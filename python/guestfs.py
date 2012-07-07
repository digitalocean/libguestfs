# libguestfs generated file
# WARNING: THIS FILE IS GENERATED FROM:
#   generator/generator_*.ml
# ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
#
# Copyright (C) 2009-2012 Red Hat Inc.
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

"""Python bindings for libguestfs

import guestfs
g = guestfs.GuestFS ()
g.add_drive_opts ("guest.img", format="raw")
g.launch ()
parts = g.list_partitions ()

The guestfs module provides a Python binding to the libguestfs API
for examining and modifying virtual machine disk images.

Amongst the things this is good for: making batch configuration
changes to guests, getting disk used/free statistics (see also:
virt-df), migrating between virtualization systems (see also:
virt-p2v), performing partial backups, performing partial guest
clones, cloning guests and changing registry/UUID/hostname info, and
much else besides.

Libguestfs uses Linux kernel and qemu code, and can access any type of
guest filesystem that Linux and qemu can, including but not limited
to: ext2/3/4, btrfs, FAT and NTFS, LVM, many different disk partition
schemes, qcow, qcow2, vmdk.

Libguestfs provides ways to enumerate guest storage (eg. partitions,
LVs, what filesystem is in each LV, etc.).  It can also run commands
in the context of the guest.  Also you can access filesystems over
FUSE.

Errors which happen while using the API are turned into Python
RuntimeError exceptions.

To create a guestfs handle you usually have to perform the following
sequence of calls:

# Create the handle, call add_drive* at least once, and possibly
# several times if the guest has multiple block devices:
g = guestfs.GuestFS ()
g.add_drive_opts ("guest.img", format="raw")

# Launch the qemu subprocess and wait for it to become ready:
g.launch ()

# Now you can issue commands, for example:
logvols = g.lvs ()

"""

import libguestfsmod

EVENT_CLOSE = 0x1
EVENT_SUBPROCESS_QUIT = 0x2
EVENT_LAUNCH_DONE = 0x4
EVENT_PROGRESS = 0x8
EVENT_APPLIANCE = 0x10
EVENT_LIBRARY = 0x20
EVENT_TRACE = 0x40
EVENT_ENTER = 0x80

class ClosedHandle(ValueError):
    pass

class GuestFS:
    """Instances of this class are libguestfs API handles."""

    def __init__ (self):
        """Create a new libguestfs handle."""
        self._o = libguestfsmod.create ()

    def __del__ (self):
        if self._o:
            libguestfsmod.close (self._o)

    def _check_not_closed (self):
        if not self._o:
            raise ClosedHandle ("GuestFS: method called on closed handle")

    def close (self):
        """Explicitly close the guestfs handle.

        The handle is closed implicitly when its reference count goes
        to zero (eg. when it goes out of scope or the program ends).

        This call is only needed if you want to force the handle to
        close now.  After calling this, the program must not call
        any method on the handle (except the implicit call to
        __del__ which happens when the final reference is cleaned up).
        """
        self._check_not_closed ()
        libguestfsmod.close (self._o)
        self._o = None

    def set_event_callback (self, cb, event_bitmask):
        """Register an event callback.

        Register "cb" as a callback function for all of the
        events in "event_bitmask".  "event_bitmask" should be
        one or more "guestfs.EVENT_*" flags logically or'd together.

        This function returns an event handle which can be used
        to delete the callback (see "delete_event_callback").

        The callback function receives 4 parameters:

        cb (event, event_handle, buf, array)

        "event" is one of the "EVENT_*" flags.  "buf" is a
        message buffer (only for some types of events).  "array"
        is an array of integers (only for some types of events).

        You should read the documentation for
        "guestfs_set_event_callback" in guestfs(3) before using
        this function.
        """
        self._check_not_closed ()
        return libguestfsmod.set_event_callback (self._o, cb, event_bitmask)

    def delete_event_callback (self, event_handle):
        """Delete an event callback."""
        self._check_not_closed ()
        libguestfsmod.delete_event_callback (self._o, event_handle)

    def test0 (self, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, obool=-1, oint=-1, oint64=-1, ostring=None):
        strlist = list (strlist)
        self._check_not_closed ()
        return libguestfsmod.test0 (self._o, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, obool, oint, oint64, ostring)

    def test0rint (self, val):
        self._check_not_closed ()
        return libguestfsmod.test0rint (self._o, val)

    def test0rinterr (self):
        self._check_not_closed ()
        return libguestfsmod.test0rinterr (self._o)

    def test0rint64 (self, val):
        self._check_not_closed ()
        return libguestfsmod.test0rint64 (self._o, val)

    def test0rint64err (self):
        self._check_not_closed ()
        return libguestfsmod.test0rint64err (self._o)

    def test0rbool (self, val):
        self._check_not_closed ()
        return libguestfsmod.test0rbool (self._o, val)

    def test0rboolerr (self):
        self._check_not_closed ()
        return libguestfsmod.test0rboolerr (self._o)

    def test0rconststring (self, val):
        self._check_not_closed ()
        return libguestfsmod.test0rconststring (self._o, val)

    def test0rconststringerr (self):
        self._check_not_closed ()
        return libguestfsmod.test0rconststringerr (self._o)

    def test0rconstoptstring (self, val):
        self._check_not_closed ()
        return libguestfsmod.test0rconstoptstring (self._o, val)

    def test0rconstoptstringerr (self):
        self._check_not_closed ()
        return libguestfsmod.test0rconstoptstringerr (self._o)

    def test0rstring (self, val):
        self._check_not_closed ()
        return libguestfsmod.test0rstring (self._o, val)

    def test0rstringerr (self):
        self._check_not_closed ()
        return libguestfsmod.test0rstringerr (self._o)

    def test0rstringlist (self, val):
        self._check_not_closed ()
        return libguestfsmod.test0rstringlist (self._o, val)

    def test0rstringlisterr (self):
        self._check_not_closed ()
        return libguestfsmod.test0rstringlisterr (self._o)

    def test0rstruct (self, val):
        self._check_not_closed ()
        return libguestfsmod.test0rstruct (self._o, val)

    def test0rstructerr (self):
        self._check_not_closed ()
        return libguestfsmod.test0rstructerr (self._o)

    def test0rstructlist (self, val):
        self._check_not_closed ()
        return libguestfsmod.test0rstructlist (self._o, val)

    def test0rstructlisterr (self):
        self._check_not_closed ()
        return libguestfsmod.test0rstructlisterr (self._o)

    def test0rhashtable (self, val):
        self._check_not_closed ()
        return libguestfsmod.test0rhashtable (self._o, val)

    def test0rhashtableerr (self):
        self._check_not_closed ()
        return libguestfsmod.test0rhashtableerr (self._o)

    def test0rbufferout (self, val):
        self._check_not_closed ()
        return libguestfsmod.test0rbufferout (self._o, val)

    def test0rbufferouterr (self):
        self._check_not_closed ()
        return libguestfsmod.test0rbufferouterr (self._o)

    def launch (self):
        """Internally libguestfs is implemented by running a
        virtual machine using qemu(1).
        
        You should call this after configuring the handle (eg.
        adding drives) but before performing any actions.
        """
        self._check_not_closed ()
        return libguestfsmod.launch (self._o)

    def wait_ready (self):
        """This function is a no op.
        
        In versions of the API < 1.0.71 you had to call this
        function just after calling "g.launch" to wait for the
        launch to complete. However this is no longer necessary
        because "g.launch" now does the waiting.
        
        If you see any calls to this function in code then you
        can just remove them, unless you want to retain
        compatibility with older versions of the API.
        
        *This function is deprecated.* In new code, use the
        "launch" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.wait_ready (self._o)

    def kill_subprocess (self):
        """This kills the qemu subprocess.
        
        Do not call this. See: "g.shutdown" instead.
        
        *This function is deprecated.* In new code, use the
        "shutdown" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.kill_subprocess (self._o)

    def add_drive (self, filename):
        """This function is the equivalent of calling
        "g.add_drive_opts" with no optional parameters, so the
        disk is added writable, with the format being detected
        automatically.
        
        Automatic detection of the format opens you up to a
        potential security hole when dealing with untrusted
        raw-format images. See CVE-2010-3851 and RHBZ#642934.
        Specifying the format closes this security hole.
        Therefore you should think about replacing calls to this
        function with calls to "g.add_drive_opts", and
        specifying the format.
        """
        self._check_not_closed ()
        return libguestfsmod.add_drive (self._o, filename)

    def add_cdrom (self, filename):
        """This function adds a virtual CD-ROM disk image to the
        guest.
        
        This is equivalent to the qemu parameter *-cdrom
        filename*.
        
        Notes:
        
        *   This call checks for the existence of "filename".
        This stops you from specifying other types of drive
        which are supported by qemu such as "nbd:" and
        "http:" URLs. To specify those, use the general
        "g.config" call instead.
        
        *   If you just want to add an ISO file (often you use
        this as an efficient way to transfer large files
        into the guest), then you should probably use
        "g.add_drive_ro" instead.
        
        *This function is deprecated.* In new code, use the
        "add_drive_opts" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.add_cdrom (self._o, filename)

    def add_drive_ro (self, filename):
        """This function is the equivalent of calling
        "g.add_drive_opts" with the optional parameter
        "GUESTFS_ADD_DRIVE_OPTS_READONLY" set to 1, so the disk
        is added read-only, with the format being detected
        automatically.
        """
        self._check_not_closed ()
        return libguestfsmod.add_drive_ro (self._o, filename)

    def config (self, qemuparam, qemuvalue):
        """This can be used to add arbitrary qemu command line
        parameters of the form *-param value*. Actually it's not
        quite arbitrary - we prevent you from setting some
        parameters which would interfere with parameters that we
        use.
        
        The first character of "param" string must be a "-"
        (dash).
        
        "value" can be NULL.
        """
        self._check_not_closed ()
        return libguestfsmod.config (self._o, qemuparam, qemuvalue)

    def set_qemu (self, qemu):
        """Set the qemu binary that we will use.
        
        The default is chosen when the library was compiled by
        the configure script.
        
        You can also override this by setting the
        "LIBGUESTFS_QEMU" environment variable.
        
        Setting "qemu" to "NULL" restores the default qemu
        binary.
        
        Note that you should call this function as early as
        possible after creating the handle. This is because some
        pre-launch operations depend on testing qemu features
        (by running "qemu -help"). If the qemu binary changes,
        we don't retest features, and so you might see
        inconsistent results. Using the environment variable
        "LIBGUESTFS_QEMU" is safest of all since that picks the
        qemu binary at the same time as the handle is created.
        """
        self._check_not_closed ()
        return libguestfsmod.set_qemu (self._o, qemu)

    def get_qemu (self):
        """Return the current qemu binary.
        
        This is always non-NULL. If it wasn't set already, then
        this will return the default qemu binary name.
        """
        self._check_not_closed ()
        return libguestfsmod.get_qemu (self._o)

    def set_path (self, searchpath):
        """Set the path that libguestfs searches for kernel and
        initrd.img.
        
        The default is "$libdir/guestfs" unless overridden by
        setting "LIBGUESTFS_PATH" environment variable.
        
        Setting "path" to "NULL" restores the default path.
        """
        self._check_not_closed ()
        return libguestfsmod.set_path (self._o, searchpath)

    def get_path (self):
        """Return the current search path.
        
        This is always non-NULL. If it wasn't set already, then
        this will return the default path.
        """
        self._check_not_closed ()
        return libguestfsmod.get_path (self._o)

    def set_append (self, append):
        """This function is used to add additional options to the
        guest kernel command line.
        
        The default is "NULL" unless overridden by setting
        "LIBGUESTFS_APPEND" environment variable.
        
        Setting "append" to "NULL" means *no* additional options
        are passed (libguestfs always adds a few of its own).
        """
        self._check_not_closed ()
        return libguestfsmod.set_append (self._o, append)

    def get_append (self):
        """Return the additional kernel options which are added to
        the guest kernel command line.
        
        If "NULL" then no options are added.
        """
        self._check_not_closed ()
        return libguestfsmod.get_append (self._o)

    def set_autosync (self, autosync):
        """If "autosync" is true, this enables autosync. Libguestfs
        will make a best effort attempt to make filesystems
        consistent and synchronized when the handle is closed
        (also if the program exits without closing handles).
        
        This is enabled by default (since libguestfs 1.5.24,
        previously it was disabled by default).
        """
        self._check_not_closed ()
        return libguestfsmod.set_autosync (self._o, autosync)

    def get_autosync (self):
        """Get the autosync flag.
        """
        self._check_not_closed ()
        return libguestfsmod.get_autosync (self._o)

    def set_verbose (self, verbose):
        """If "verbose" is true, this turns on verbose messages.
        
        Verbose messages are disabled unless the environment
        variable "LIBGUESTFS_DEBUG" is defined and set to 1.
        
        Verbose messages are normally sent to "stderr", unless
        you register a callback to send them somewhere else (see
        "g.set_event_callback").
        """
        self._check_not_closed ()
        return libguestfsmod.set_verbose (self._o, verbose)

    def get_verbose (self):
        """This returns the verbose messages flag.
        """
        self._check_not_closed ()
        return libguestfsmod.get_verbose (self._o)

    def is_ready (self):
        """This returns true iff this handle is ready to accept
        commands (in the "READY" state).
        
        For more information on states, see guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.is_ready (self._o)

    def is_config (self):
        """This returns true iff this handle is being configured
        (in the "CONFIG" state).
        
        For more information on states, see guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.is_config (self._o)

    def is_launching (self):
        """This returns true iff this handle is launching the
        subprocess (in the "LAUNCHING" state).
        
        For more information on states, see guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.is_launching (self._o)

    def is_busy (self):
        self._check_not_closed ()
        return libguestfsmod.is_busy (self._o)

    def get_state (self):
        """This returns the current state as an opaque integer.
        This is only useful for printing debug and internal
        error messages.
        
        For more information on states, see guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.get_state (self._o)

    def set_memsize (self, memsize):
        """This sets the memory size in megabytes allocated to the
        qemu subprocess. This only has any effect if called
        before "g.launch".
        
        You can also change this by setting the environment
        variable "LIBGUESTFS_MEMSIZE" before the handle is
        created.
        
        For more information on the architecture of libguestfs,
        see guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.set_memsize (self._o, memsize)

    def get_memsize (self):
        """This gets the memory size in megabytes allocated to the
        qemu subprocess.
        
        If "g.set_memsize" was not called on this handle, and if
        "LIBGUESTFS_MEMSIZE" was not set, then this returns the
        compiled-in default value for memsize.
        
        For more information on the architecture of libguestfs,
        see guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.get_memsize (self._o)

    def get_pid (self):
        """Return the process ID of the qemu subprocess. If there
        is no qemu subprocess, then this will return an error.
        
        This is an internal call used for debugging and testing.
        """
        self._check_not_closed ()
        return libguestfsmod.get_pid (self._o)

    def version (self):
        """Return the libguestfs version number that the program is
        linked against.
        
        Note that because of dynamic linking this is not
        necessarily the version of libguestfs that you compiled
        against. You can compile the program, and then at
        runtime dynamically link against a completely different
        "libguestfs.so" library.
        
        This call was added in version 1.0.58. In previous
        versions of libguestfs there was no way to get the
        version number. From C code you can use dynamic linker
        functions to find out if this symbol exists (if it
        doesn't, then it's an earlier version).
        
        The call returns a structure with four elements. The
        first three ("major", "minor" and "release") are numbers
        and correspond to the usual version triplet. The fourth
        element ("extra") is a string and is normally empty, but
        may be used for distro-specific information.
        
        To construct the original version string:
        "$major.$minor.$release$extra"
        
        See also: "LIBGUESTFS VERSION NUMBERS" in guestfs(3).
        
        *Note:* Don't use this call to test for availability of
        features. In enterprise distributions we backport
        features from later versions into earlier versions,
        making this an unreliable way to test for features. Use
        "g.available" instead.
        
        This function returns a dictionary, with keys matching
        the various fields in the guestfs_version structure.
        """
        self._check_not_closed ()
        return libguestfsmod.version (self._o)

    def set_selinux (self, selinux):
        """This sets the selinux flag that is passed to the
        appliance at boot time. The default is "selinux=0"
        (disabled).
        
        Note that if SELinux is enabled, it is always in
        Permissive mode ("enforcing=0").
        
        For more information on the architecture of libguestfs,
        see guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.set_selinux (self._o, selinux)

    def get_selinux (self):
        """This returns the current setting of the selinux flag
        which is passed to the appliance at boot time. See
        "g.set_selinux".
        
        For more information on the architecture of libguestfs,
        see guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.get_selinux (self._o)

    def set_trace (self, trace):
        """If the command trace flag is set to 1, then libguestfs
        calls, parameters and return values are traced.
        
        If you want to trace C API calls into libguestfs (and
        other libraries) then possibly a better way is to use
        the external ltrace(1) command.
        
        Command traces are disabled unless the environment
        variable "LIBGUESTFS_TRACE" is defined and set to 1.
        
        Trace messages are normally sent to "stderr", unless you
        register a callback to send them somewhere else (see
        "g.set_event_callback").
        """
        self._check_not_closed ()
        return libguestfsmod.set_trace (self._o, trace)

    def get_trace (self):
        """Return the command trace flag.
        """
        self._check_not_closed ()
        return libguestfsmod.get_trace (self._o)

    def set_direct (self, direct):
        """If the direct appliance mode flag is enabled, then stdin
        and stdout are passed directly through to the appliance
        once it is launched.
        
        One consequence of this is that log messages aren't
        caught by the library and handled by
        "g.set_log_message_callback", but go straight to stdout.
        
        You probably don't want to use this unless you know what
        you are doing.
        
        The default is disabled.
        """
        self._check_not_closed ()
        return libguestfsmod.set_direct (self._o, direct)

    def get_direct (self):
        """Return the direct appliance mode flag.
        """
        self._check_not_closed ()
        return libguestfsmod.get_direct (self._o)

    def set_recovery_proc (self, recoveryproc):
        """If this is called with the parameter "false" then
        "g.launch" does not create a recovery process. The
        purpose of the recovery process is to stop runaway qemu
        processes in the case where the main program aborts
        abruptly.
        
        This only has any effect if called before "g.launch",
        and the default is true.
        
        About the only time when you would want to disable this
        is if the main process will fork itself into the
        background ("daemonize" itself). In this case the
        recovery process thinks that the main program has
        disappeared and so kills qemu, which is not very
        helpful.
        """
        self._check_not_closed ()
        return libguestfsmod.set_recovery_proc (self._o, recoveryproc)

    def get_recovery_proc (self):
        """Return the recovery process enabled flag.
        """
        self._check_not_closed ()
        return libguestfsmod.get_recovery_proc (self._o)

    def add_drive_with_if (self, filename, iface):
        """This is the same as "g.add_drive" but it allows you to
        specify the QEMU interface emulation to use at run time.
        
        *This function is deprecated.* In new code, use the
        "add_drive_opts" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.add_drive_with_if (self._o, filename, iface)

    def add_drive_ro_with_if (self, filename, iface):
        """This is the same as "g.add_drive_ro" but it allows you
        to specify the QEMU interface emulation to use at run
        time.
        
        *This function is deprecated.* In new code, use the
        "add_drive_opts" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.add_drive_ro_with_if (self._o, filename, iface)

    def file_architecture (self, filename):
        """This detects the architecture of the binary "filename",
        and returns it if known.
        
        Currently defined architectures are:
        
        "i386"
        This string is returned for all 32 bit i386, i486,
        i586, i686 binaries irrespective of the precise
        processor requirements of the binary.
        
        "x86_64"
        64 bit x86-64.
        
        "sparc"
        32 bit SPARC.
        
        "sparc64"
        64 bit SPARC V9 and above.
        
        "ia64"
        Intel Itanium.
        
        "ppc"
        32 bit Power PC.
        
        "ppc64"
        64 bit Power PC.
        
        Libguestfs may return other architecture strings in
        future.
        
        The function works on at least the following types of
        files:
        
        *   many types of Un*x and Linux binary
        
        *   many types of Un*x and Linux shared library
        
        *   Windows Win32 and Win64 binaries
        
        *   Windows Win32 and Win64 DLLs
        
        Win32 binaries and DLLs return "i386".
        
        Win64 binaries and DLLs return "x86_64".
        
        *   Linux kernel modules
        
        *   Linux new-style initrd images
        
        *   some non-x86 Linux vmlinuz kernels
        
        What it can't do currently:
        
        *   static libraries (libfoo.a)
        
        *   Linux old-style initrd as compressed ext2 filesystem
        (RHEL 3)
        
        *   x86 Linux vmlinuz kernels
        
        x86 vmlinuz images (bzImage format) consist of a mix
        of 16-, 32- and compressed code, and are horribly
        hard to unpack. If you want to find the architecture
        of a kernel, use the architecture of the associated
        initrd or kernel module(s) instead.
        """
        self._check_not_closed ()
        return libguestfsmod.file_architecture (self._o, filename)

    def inspect_os (self):
        """This function uses other libguestfs functions and
        certain heuristics to inspect the disk(s) (usually disks
        belonging to a virtual machine), looking for operating
        systems.
        
        The list returned is empty if no operating systems were
        found.
        
        If one operating system was found, then this returns a
        list with a single element, which is the name of the
        root filesystem of this operating system. It is also
        possible for this function to return a list containing
        more than one element, indicating a dual-boot or
        multi-boot virtual machine, with each element being the
        root filesystem of one of the operating systems.
        
        You can pass the root string(s) returned to other
        "g.inspect_get_*" functions in order to query further
        information about each operating system, such as the
        name and version.
        
        This function uses other libguestfs features such as
        "g.mount_ro" and "g.umount_all" in order to mount and
        unmount filesystems and look at the contents. This
        should be called with no disks currently mounted. The
        function may also use Augeas, so any existing Augeas
        handle will be closed.
        
        This function cannot decrypt encrypted disks. The caller
        must do that first (supplying the necessary keys) if the
        disk is encrypted.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        
        See also "g.list_filesystems".
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_os (self._o)

    def inspect_get_type (self, root):
        """This returns the type of the inspected operating system.
        Currently defined types are:
        
        "linux"
        Any Linux-based operating system.
        
        "windows"
        Any Microsoft Windows operating system.
        
        "freebsd"
        FreeBSD.
        
        "netbsd"
        NetBSD.
        
        "hurd"
        GNU/Hurd.
        
        "dos"
        MS-DOS, FreeDOS and others.
        
        "unknown"
        The operating system type could not be determined.
        
        Future versions of libguestfs may return other strings
        here. The caller should be prepared to handle any
        string.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_type (self._o, root)

    def inspect_get_arch (self, root):
        """This returns the architecture of the inspected operating
        system. The possible return values are listed under
        "g.file_architecture".
        
        If the architecture could not be determined, then the
        string "unknown" is returned.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_arch (self._o, root)

    def inspect_get_distro (self, root):
        """This returns the distro (distribution) of the inspected
        operating system.
        
        Currently defined distros are:
        
        "archlinux"
        Arch Linux.
        
        "buildroot"
        Buildroot-derived distro, but not one we
        specifically recognize.
        
        "centos"
        CentOS.
        
        "cirros"
        Cirros.
        
        "debian"
        Debian.
        
        "fedora"
        Fedora.
        
        "freedos"
        FreeDOS.
        
        "gentoo"
        Gentoo.
        
        "linuxmint"
        Linux Mint.
        
        "mageia"
        Mageia.
        
        "mandriva"
        Mandriva.
        
        "meego"
        MeeGo.
        
        "opensuse"
        OpenSUSE.
        
        "pardus"
        Pardus.
        
        "redhat-based"
        Some Red Hat-derived distro.
        
        "rhel"
        Red Hat Enterprise Linux.
        
        "scientificlinux"
        Scientific Linux.
        
        "slackware"
        Slackware.
        
        "ttylinux"
        ttylinux.
        
        "ubuntu"
        Ubuntu.
        
        "unknown"
        The distro could not be determined.
        
        "windows"
        Windows does not have distributions. This string is
        returned if the OS type is Windows.
        
        Future versions of libguestfs may return other strings
        here. The caller should be prepared to handle any
        string.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_distro (self._o, root)

    def inspect_get_major_version (self, root):
        """This returns the major version number of the inspected
        operating system.
        
        Windows uses a consistent versioning scheme which is
        *not* reflected in the popular public names used by the
        operating system. Notably the operating system known as
        "Windows 7" is really version 6.1 (ie. major = 6, minor
        = 1). You can find out the real versions corresponding
        to releases of Windows by consulting Wikipedia or MSDN.
        
        If the version could not be determined, then 0 is
        returned.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_major_version (self._o, root)

    def inspect_get_minor_version (self, root):
        """This returns the minor version number of the inspected
        operating system.
        
        If the version could not be determined, then 0 is
        returned.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        See also "g.inspect_get_major_version".
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_minor_version (self._o, root)

    def inspect_get_product_name (self, root):
        """This returns the product name of the inspected operating
        system. The product name is generally some freeform
        string which can be displayed to the user, but should
        not be parsed by programs.
        
        If the product name could not be determined, then the
        string "unknown" is returned.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_product_name (self._o, root)

    def inspect_get_mountpoints (self, root):
        """This returns a hash of where we think the filesystems
        associated with this operating system should be mounted.
        Callers should note that this is at best an educated
        guess made by reading configuration files such as
        "/etc/fstab". *In particular note* that this may return
        filesystems which are non-existent or not mountable and
        callers should be prepared to handle or ignore failures
        if they try to mount them.
        
        Each element in the returned hashtable has a key which
        is the path of the mountpoint (eg. "/boot") and a value
        which is the filesystem that would be mounted there (eg.
        "/dev/sda1").
        
        Non-mounted devices such as swap devices are *not*
        returned in this list.
        
        For operating systems like Windows which still use drive
        letters, this call will only return an entry for the
        first drive "mounted on" "/". For information about the
        mapping of drive letters to partitions, see
        "g.inspect_get_drive_mappings".
        
        Please read "INSPECTION" in guestfs(3) for more details.
        See also "g.inspect_get_filesystems".
        
        This function returns a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_mountpoints (self._o, root)

    def inspect_get_filesystems (self, root):
        """This returns a list of all the filesystems that we think
        are associated with this operating system. This includes
        the root filesystem, other ordinary filesystems, and
        non-mounted devices like swap partitions.
        
        In the case of a multi-boot virtual machine, it is
        possible for a filesystem to be shared between operating
        systems.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        See also "g.inspect_get_mountpoints".
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_filesystems (self._o, root)

    def set_network (self, network):
        """If "network" is true, then the network is enabled in the
        libguestfs appliance. The default is false.
        
        This affects whether commands are able to access the
        network (see "RUNNING COMMANDS" in guestfs(3)).
        
        You must call this before calling "g.launch", otherwise
        it has no effect.
        """
        self._check_not_closed ()
        return libguestfsmod.set_network (self._o, network)

    def get_network (self):
        """This returns the enable network flag.
        """
        self._check_not_closed ()
        return libguestfsmod.get_network (self._o)

    def list_filesystems (self):
        """This inspection command looks for filesystems on
        partitions, block devices and logical volumes, returning
        a list of devices containing filesystems and their type.
        
        The return value is a hash, where the keys are the
        devices containing filesystems, and the values are the
        filesystem types. For example:
        
        "/dev/sda1" => "ntfs"
        "/dev/sda2" => "ext2"
        "/dev/vg_guest/lv_root" => "ext4"
        "/dev/vg_guest/lv_swap" => "swap"
        
        The value can have the special value "unknown", meaning
        the content of the device is undetermined or empty.
        "swap" means a Linux swap partition.
        
        This command runs other libguestfs commands, which might
        include "g.mount" and "g.umount", and therefore you
        should use this soon after launch and only when nothing
        is mounted.
        
        Not all of the filesystems returned will be mountable.
        In particular, swap partitions are returned in the list.
        Also this command does not check that each filesystem
        found is valid and mountable, and some filesystems might
        be mountable but require special options. Filesystems
        may not all belong to a single logical operating system
        (use "g.inspect_os" to look for OSes).
        
        This function returns a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.list_filesystems (self._o)

    def add_drive_opts (self, filename, readonly=-1, format=None, iface=None, name=None):
        """This function adds a virtual machine disk image
        "filename" to libguestfs. The first time you call this
        function, the disk appears as "/dev/sda", the second
        time as "/dev/sdb", and so on.
        
        You don't necessarily need to be root when using
        libguestfs. However you obviously do need sufficient
        permissions to access the filename for whatever
        operations you want to perform (ie. read access if you
        just want to read the image or write access if you want
        to modify the image).
        
        This call checks that "filename" exists.
        
        The optional arguments are:
        
        "readonly"
        If true then the image is treated as read-only.
        Writes are still allowed, but they are stored in a
        temporary snapshot overlay which is discarded at the
        end. The disk that you add is not modified.
        
        "format"
        This forces the image format. If you omit this (or
        use "g.add_drive" or "g.add_drive_ro") then the
        format is automatically detected. Possible formats
        include "raw" and "qcow2".
        
        Automatic detection of the format opens you up to a
        potential security hole when dealing with untrusted
        raw-format images. See CVE-2010-3851 and
        RHBZ#642934. Specifying the format closes this
        security hole.
        
        "iface"
        This rarely-used option lets you emulate the
        behaviour of the deprecated "g.add_drive_with_if"
        call (q.v.)
        
        "name"
        The name the drive had in the original guest, e.g.
        /dev/sdb. This is used as a hint to the guest
        inspection process if it is available.
        """
        self._check_not_closed ()
        return libguestfsmod.add_drive_opts (self._o, filename, readonly, format, iface, name)

    def inspect_get_windows_systemroot (self, root):
        """This returns the Windows systemroot of the inspected
        guest. The systemroot is a directory path such as
        "/WINDOWS".
        
        This call assumes that the guest is Windows and that the
        systemroot could be determined by inspection. If this is
        not the case then an error is returned.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_windows_systemroot (self._o, root)

    def inspect_get_roots (self):
        """This function is a convenient way to get the list of
        root devices, as returned from a previous call to
        "g.inspect_os", but without redoing the whole inspection
        process.
        
        This returns an empty list if either no root devices
        were found or the caller has not called "g.inspect_os".
        
        Please read "INSPECTION" in guestfs(3) for more details.
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_roots (self._o)

    def debug_cmdline (self):
        self._check_not_closed ()
        return libguestfsmod.debug_cmdline (self._o)

    def debug_drives (self):
        self._check_not_closed ()
        return libguestfsmod.debug_drives (self._o)

    def add_domain (self, dom, libvirturi=None, readonly=-1, iface=None, live=-1, allowuuid=-1, readonlydisk=None):
        """This function adds the disk(s) attached to the named
        libvirt domain "dom". It works by connecting to libvirt,
        requesting the domain and domain XML from libvirt,
        parsing it for disks, and calling "g.add_drive_opts" on
        each one.
        
        The number of disks added is returned. This operation is
        atomic: if an error is returned, then no disks are
        added.
        
        This function does some minimal checks to make sure the
        libvirt domain is not running (unless "readonly" is
        true). In a future version we will try to acquire the
        libvirt lock on each disk.
        
        Disks must be accessible locally. This often means that
        adding disks from a remote libvirt connection (see
        <http://libvirt.org/remote.html>) will fail unless those
        disks are accessible via the same device path locally
        too.
        
        The optional "libvirturi" parameter sets the libvirt URI
        (see <http://libvirt.org/uri.html>). If this is not set
        then we connect to the default libvirt URI (or one set
        through an environment variable, see the libvirt
        documentation for full details).
        
        The optional "live" flag controls whether this call will
        try to connect to a running virtual machine "guestfsd"
        process if it sees a suitable <channel> element in the
        libvirt XML definition. The default (if the flag is
        omitted) is never to try. See "ATTACHING TO RUNNING
        DAEMONS" in guestfs(3) for more information.
        
        If the "allowuuid" flag is true (default is false) then
        a UUID *may* be passed instead of the domain name. The
        "dom" string is treated as a UUID first and looked up,
        and if that lookup fails then we treat "dom" as a name
        as usual.
        
        The optional "readonlydisk" parameter controls what we
        do for disks which are marked <readonly/> in the libvirt
        XML. Possible values are:
        
        readonlydisk = "error"
        If "readonly" is false:
        
        The whole call is aborted with an error if any disk
        with the <readonly/> flag is found.
        
        If "readonly" is true:
        
        Disks with the <readonly/> flag are added read-only.
        
        readonlydisk = "read"
        If "readonly" is false:
        
        Disks with the <readonly/> flag are added read-only.
        Other disks are added read/write.
        
        If "readonly" is true:
        
        Disks with the <readonly/> flag are added read-only.
        
        readonlydisk = "write" (default)
        If "readonly" is false:
        
        Disks with the <readonly/> flag are added
        read/write.
        
        If "readonly" is true:
        
        Disks with the <readonly/> flag are added read-only.
        
        readonlydisk = "ignore"
        If "readonly" is true or false:
        
        Disks with the <readonly/> flag are skipped.
        
        The other optional parameters are passed directly
        through to "g.add_drive_opts".
        """
        self._check_not_closed ()
        return libguestfsmod.add_domain (self._o, dom, libvirturi, readonly, iface, live, allowuuid, readonlydisk)

    def inspect_get_package_format (self, root):
        """This function and "g.inspect_get_package_management"
        return the package format and package management tool
        used by the inspected operating system. For example for
        Fedora these functions would return "rpm" (package
        format) and "yum" (package management).
        
        This returns the string "unknown" if we could not
        determine the package format *or* if the operating
        system does not have a real packaging system (eg.
        Windows).
        
        Possible strings include: "rpm", "deb", "ebuild",
        "pisi", "pacman", "pkgsrc". Future versions of
        libguestfs may return other strings.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_package_format (self._o, root)

    def inspect_get_package_management (self, root):
        """"g.inspect_get_package_format" and this function return
        the package format and package management tool used by
        the inspected operating system. For example for Fedora
        these functions would return "rpm" (package format) and
        "yum" (package management).
        
        This returns the string "unknown" if we could not
        determine the package management tool *or* if the
        operating system does not have a real packaging system
        (eg. Windows).
        
        Possible strings include: "yum", "up2date", "apt" (for
        all Debian derivatives), "portage", "pisi", "pacman",
        "urpmi", "zypper". Future versions of libguestfs may
        return other strings.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_package_management (self._o, root)

    def inspect_list_applications (self, root):
        """Return the list of applications installed in the
        operating system.
        
        *Note:* This call works differently from other parts of
        the inspection API. You have to call "g.inspect_os",
        then "g.inspect_get_mountpoints", then mount up the
        disks, before calling this. Listing applications is a
        significantly more difficult operation which requires
        access to the full filesystem. Also note that unlike the
        other "g.inspect_get_*" calls which are just returning
        data cached in the libguestfs handle, this call actually
        reads parts of the mounted filesystems during the call.
        
        This returns an empty list if the inspection code was
        not able to determine the list of applications.
        
        The application structure contains the following fields:
        
        "app_name"
        The name of the application. For Red Hat-derived and
        Debian-derived Linux guests, this is the package
        name.
        
        "app_display_name"
        The display name of the application, sometimes
        localized to the install language of the guest
        operating system.
        
        If unavailable this is returned as an empty string
        "". Callers needing to display something can use
        "app_name" instead.
        
        "app_epoch"
        For package managers which use epochs, this contains
        the epoch of the package (an integer). If
        unavailable, this is returned as 0.
        
        "app_version"
        The version string of the application or package. If
        unavailable this is returned as an empty string "".
        
        "app_release"
        The release string of the application or package,
        for package managers that use this. If unavailable
        this is returned as an empty string "".
        
        "app_install_path"
        The installation path of the application (on
        operating systems such as Windows which use
        installation paths). This path is in the format used
        by the guest operating system, it is not a
        libguestfs path.
        
        If unavailable this is returned as an empty string
        "".
        
        "app_trans_path"
        The install path translated into a libguestfs path.
        If unavailable this is returned as an empty string
        "".
        
        "app_publisher"
        The name of the publisher of the application, for
        package managers that use this. If unavailable this
        is returned as an empty string "".
        
        "app_url"
        The URL (eg. upstream URL) of the application. If
        unavailable this is returned as an empty string "".
        
        "app_source_package"
        For packaging systems which support this, the name
        of the source package. If unavailable this is
        returned as an empty string "".
        
        "app_summary"
        A short (usually one line) description of the
        application or package. If unavailable this is
        returned as an empty string "".
        
        "app_description"
        A longer description of the application or package.
        If unavailable this is returned as an empty string
        "".
        
        Please read "INSPECTION" in guestfs(3) for more details.
        
        This function returns a list of applications. Each
        application is represented as a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_list_applications (self._o, root)

    def inspect_get_hostname (self, root):
        """This function returns the hostname of the operating
        system as found by inspection of the guest's
        configuration files.
        
        If the hostname could not be determined, then the string
        "unknown" is returned.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_hostname (self._o, root)

    def inspect_get_format (self, root):
        """This returns the format of the inspected operating
        system. You can use it to detect install images, live
        CDs and similar.
        
        Currently defined formats are:
        
        "installed"
        This is an installed operating system.
        
        "installer"
        The disk image being inspected is not an installed
        operating system, but a *bootable* install disk,
        live CD, or similar.
        
        "unknown"
        The format of this disk image is not known.
        
        Future versions of libguestfs may return other strings
        here. The caller should be prepared to handle any
        string.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_format (self._o, root)

    def inspect_is_live (self, root):
        """If "g.inspect_get_format" returns "installer" (this is
        an install disk), then this returns true if a live image
        was detected on the disk.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_is_live (self._o, root)

    def inspect_is_netinst (self, root):
        """If "g.inspect_get_format" returns "installer" (this is
        an install disk), then this returns true if the disk is
        a network installer, ie. not a self-contained install CD
        but one which is likely to require network access to
        complete the install.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_is_netinst (self._o, root)

    def inspect_is_multipart (self, root):
        """If "g.inspect_get_format" returns "installer" (this is
        an install disk), then this returns true if the disk is
        part of a set.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_is_multipart (self._o, root)

    def set_attach_method (self, attachmethod):
        """Set the method that libguestfs uses to connect to the
        back end guestfsd daemon. Possible methods are:
        
        "appliance"
        Launch an appliance and connect to it. This is the
        ordinary method and the default.
        
        "unix:*path*"
        Connect to the Unix domain socket *path*.
        
        This method lets you connect to an existing daemon
        or (using virtio-serial) to a live guest. For more
        information, see "ATTACHING TO RUNNING DAEMONS" in
        guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.set_attach_method (self._o, attachmethod)

    def get_attach_method (self):
        """Return the current attach method. See
        "g.set_attach_method".
        """
        self._check_not_closed ()
        return libguestfsmod.get_attach_method (self._o)

    def inspect_get_product_variant (self, root):
        """This returns the product variant of the inspected
        operating system.
        
        For Windows guests, this returns the contents of the
        Registry key "HKLM\\Software\\Microsoft\\Windows
        NT\\CurrentVersion" "InstallationType" which is usually a
        string such as "Client" or "Server" (other values are
        possible). This can be used to distinguish consumer and
        enterprise versions of Windows that have the same
        version number (for example, Windows 7 and Windows 2008
        Server are both version 6.1, but the former is "Client"
        and the latter is "Server").
        
        For enterprise Linux guests, in future we intend this to
        return the product variant such as "Desktop", "Server"
        and so on. But this is not implemented at present.
        
        If the product variant could not be determined, then the
        string "unknown" is returned.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        See also "g.inspect_get_product_name",
        "g.inspect_get_major_version".
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_product_variant (self._o, root)

    def inspect_get_windows_current_control_set (self, root):
        """This returns the Windows CurrentControlSet of the
        inspected guest. The CurrentControlSet is a registry key
        name such as "ControlSet001".
        
        This call assumes that the guest is Windows and that the
        Registry could be examined by inspection. If this is not
        the case then an error is returned.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_windows_current_control_set (self._o, root)

    def inspect_get_drive_mappings (self, root):
        """This call is useful for Windows which uses a primitive
        system of assigning drive letters (like "C:") to
        partitions. This inspection API examines the Windows
        Registry to find out how disks/partitions are mapped to
        drive letters, and returns a hash table as in the
        example below:
        
        C      =>     /dev/vda2
        E      =>     /dev/vdb1
        F      =>     /dev/vdc1
        
        Note that keys are drive letters. For Windows, the key
        is case insensitive and just contains the drive letter,
        without the customary colon separator character.
        
        In future we may support other operating systems that
        also used drive letters, but the keys for those might
        not be case insensitive and might be longer than 1
        character. For example in OS-9, hard drives were named
        "h0", "h1" etc.
        
        For Windows guests, currently only hard drive mappings
        are returned. Removable disks (eg. DVD-ROMs) are
        ignored.
        
        For guests that do not use drive mappings, or if the
        drive mappings could not be determined, this returns an
        empty hash table.
        
        Please read "INSPECTION" in guestfs(3) for more details.
        See also "g.inspect_get_mountpoints",
        "g.inspect_get_filesystems".
        
        This function returns a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_drive_mappings (self._o, root)

    def inspect_get_icon (self, root, favicon=-1, highquality=-1):
        """This function returns an icon corresponding to the
        inspected operating system. The icon is returned as a
        buffer containing a PNG image (re-encoded to PNG if
        necessary).
        
        If it was not possible to get an icon this function
        returns a zero-length (non-NULL) buffer. *Callers must
        check for this case*.
        
        Libguestfs will start by looking for a file called
        "/etc/favicon.png" or "C:\\etc\\favicon.png" and if it has
        the correct format, the contents of this file will be
        returned. You can disable favicons by passing the
        optional "favicon" boolean as false (default is true).
        
        If finding the favicon fails, then we look in other
        places in the guest for a suitable icon.
        
        If the optional "highquality" boolean is true then only
        high quality icons are returned, which means only icons
        of high resolution with an alpha channel. The default
        (false) is to return any icon we can, even if it is of
        substandard quality.
        
        Notes:
        
        *   Unlike most other inspection API calls, the guest's
        disks must be mounted up before you call this, since
        it needs to read information from the guest
        filesystem during the call.
        
        *   Security: The icon data comes from the untrusted
        guest, and should be treated with caution. PNG files
        have been known to contain exploits. Ensure that
        libpng (or other relevant libraries) are fully up to
        date before trying to process or display the icon.
        
        *   The PNG image returned can be any size. It might not
        be square. Libguestfs tries to return the largest,
        highest quality icon available. The application must
        scale the icon to the required size.
        
        *   Extracting icons from Windows guests requires the
        external "wrestool" program from the "icoutils"
        package, and several programs ("bmptopnm",
        "pnmtopng", "pamcut") from the "netpbm" package.
        These must be installed separately.
        
        *   Operating system icons are usually trademarks. Seek
        legal advice before using trademarks in
        applications.
        """
        self._check_not_closed ()
        return libguestfsmod.inspect_get_icon (self._o, root, favicon, highquality)

    def set_pgroup (self, pgroup):
        """If "pgroup" is true, child processes are placed into
        their own process group.
        
        The practical upshot of this is that signals like
        "SIGINT" (from users pressing "^C") won't be received by
        the child process.
        
        The default for this flag is false, because usually you
        want "^C" to kill the subprocess. Guestfish sets this
        flag to true when used interactively, so that "^C" can
        cancel long-running commands gracefully (see
        "g.user_cancel").
        """
        self._check_not_closed ()
        return libguestfsmod.set_pgroup (self._o, pgroup)

    def get_pgroup (self):
        """This returns the process group flag.
        """
        self._check_not_closed ()
        return libguestfsmod.get_pgroup (self._o)

    def set_smp (self, smp):
        """Change the number of virtual CPUs assigned to the
        appliance. The default is 1. Increasing this may improve
        performance, though often it has no effect.
        
        This function must be called before "g.launch".
        """
        self._check_not_closed ()
        return libguestfsmod.set_smp (self._o, smp)

    def get_smp (self):
        """This returns the number of virtual CPUs assigned to the
        appliance.
        """
        self._check_not_closed ()
        return libguestfsmod.get_smp (self._o)

    def mount_local (self, localmountpoint, readonly=-1, options=None, cachetimeout=-1, debugcalls=-1):
        """This call exports the libguestfs-accessible filesystem
        to a local mountpoint (directory) called
        "localmountpoint". Ordinary reads and writes to files
        and directories under "localmountpoint" are redirected
        through libguestfs.
        
        If the optional "readonly" flag is set to true, then
        writes to the filesystem return error "EROFS".
        
        "options" is a comma-separated list of mount options.
        See guestmount(1) for some useful options.
        
        "cachetimeout" sets the timeout (in seconds) for cached
        directory entries. The default is 60 seconds. See
        guestmount(1) for further information.
        
        If "debugcalls" is set to true, then additional
        debugging information is generated for every FUSE call.
        
        When "g.mount_local" returns, the filesystem is ready,
        but is not processing requests (access to it will
        block). You have to call "g.mount_local_run" to run the
        main loop.
        
        See "MOUNT LOCAL" in guestfs(3) for full documentation.
        """
        self._check_not_closed ()
        return libguestfsmod.mount_local (self._o, localmountpoint, readonly, options, cachetimeout, debugcalls)

    def mount_local_run (self):
        """Run the main loop which translates kernel calls to
        libguestfs calls.
        
        This should only be called after "g.mount_local" returns
        successfully. The call will not return until the
        filesystem is unmounted.
        
        Note you must *not* make concurrent libguestfs calls on
        the same handle from another thread, with the exception
        of "g.umount_local".
        
        You may call this from a different thread than the one
        which called "g.mount_local", subject to the usual rules
        for threads and libguestfs (see "MULTIPLE HANDLES AND
        MULTIPLE THREADS" in guestfs(3)).
        
        See "MOUNT LOCAL" in guestfs(3) for full documentation.
        """
        self._check_not_closed ()
        return libguestfsmod.mount_local_run (self._o)

    def umount_local (self, retry=-1):
        """If libguestfs is exporting the filesystem on a local
        mountpoint, then this unmounts it.
        
        See "MOUNT LOCAL" in guestfs(3) for full documentation.
        """
        self._check_not_closed ()
        return libguestfsmod.umount_local (self._o, retry)

    def shutdown (self):
        """This is the opposite of "g.launch". It performs an
        orderly shutdown of the backend process(es). If the
        autosync flag is set (which is the default) then the
        disk image is synchronized.
        
        If the subprocess exits with an error then this function
        will return an error, which should *not* be ignored (it
        may indicate that the disk image could not be written
        out properly).
        
        It is safe to call this multiple times. Extra calls are
        ignored.
        
        This call does *not* close or free up the handle. You
        still need to call "g.close" afterwards.
        
        "g.close" will call this if you don't do it explicitly,
        but note that any errors are ignored in that case.
        """
        self._check_not_closed ()
        return libguestfsmod.shutdown (self._o)

    def mount (self, device, mountpoint):
        """Mount a guest disk at a position in the filesystem.
        Block devices are named "/dev/sda", "/dev/sdb" and so
        on, as they were added to the guest. If those block
        devices contain partitions, they will have the usual
        names (eg. "/dev/sda1"). Also LVM "/dev/VG/LV"-style
        names can be used.
        
        The rules are the same as for mount(2): A filesystem
        must first be mounted on "/" before others can be
        mounted. Other filesystems can only be mounted on
        directories which already exist.
        
        The mounted filesystem is writable, if we have
        sufficient permissions on the underlying device.
        
        Before libguestfs 1.13.16, this call implicitly added
        the options "sync" and "noatime". The "sync" option
        greatly slowed writes and caused many problems for
        users. If your program might need to work with older
        versions of libguestfs, use "g.mount_options" instead
        (using an empty string for the first parameter if you
        don't want any options).
        """
        self._check_not_closed ()
        return libguestfsmod.mount (self._o, device, mountpoint)

    def sync (self):
        """This syncs the disk, so that any writes are flushed
        through to the underlying disk image.
        
        You should always call this if you have modified a disk
        image, before closing the handle.
        """
        self._check_not_closed ()
        return libguestfsmod.sync (self._o)

    def touch (self, path):
        """Touch acts like the touch(1) command. It can be used to
        update the timestamps on a file, or, if the file does
        not exist, to create a new zero-length file.
        
        This command only works on regular files, and will fail
        on other file types such as directories, symbolic links,
        block special etc.
        """
        self._check_not_closed ()
        return libguestfsmod.touch (self._o, path)

    def cat (self, path):
        """Return the contents of the file named "path".
        
        Note that this function cannot correctly handle binary
        files (specifically, files containing "\\0" character
        which is treated as end of string). For those you need
        to use the "g.read_file" or "g.download" functions which
        have a more complex interface.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.cat (self._o, path)

    def ll (self, directory):
        """List the files in "directory" (relative to the root
        directory, there is no cwd) in the format of 'ls -la'.
        
        This command is mostly useful for interactive sessions.
        It is *not* intended that you try to parse the output
        string.
        """
        self._check_not_closed ()
        return libguestfsmod.ll (self._o, directory)

    def ls (self, directory):
        """List the files in "directory" (relative to the root
        directory, there is no cwd). The '.' and '..' entries
        are not returned, but hidden files are shown.
        
        This command is mostly useful for interactive sessions.
        Programs should probably use "g.readdir" instead.
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.ls (self._o, directory)

    def list_devices (self):
        """List all the block devices.
        
        The full block device names are returned, eg.
        "/dev/sda".
        
        See also "g.list_filesystems".
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.list_devices (self._o)

    def list_partitions (self):
        """List all the partitions detected on all block devices.
        
        The full partition device names are returned, eg.
        "/dev/sda1"
        
        This does not return logical volumes. For that you will
        need to call "g.lvs".
        
        See also "g.list_filesystems".
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.list_partitions (self._o)

    def pvs (self):
        """List all the physical volumes detected. This is the
        equivalent of the pvs(8) command.
        
        This returns a list of just the device names that
        contain PVs (eg. "/dev/sda2").
        
        See also "g.pvs_full".
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.pvs (self._o)

    def vgs (self):
        """List all the volumes groups detected. This is the
        equivalent of the vgs(8) command.
        
        This returns a list of just the volume group names that
        were detected (eg. "VolGroup00").
        
        See also "g.vgs_full".
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.vgs (self._o)

    def lvs (self):
        """List all the logical volumes detected. This is the
        equivalent of the lvs(8) command.
        
        This returns a list of the logical volume device names
        (eg. "/dev/VolGroup00/LogVol00").
        
        See also "g.lvs_full", "g.list_filesystems".
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.lvs (self._o)

    def pvs_full (self):
        """List all the physical volumes detected. This is the
        equivalent of the pvs(8) command. The "full" version
        includes all fields.
        
        This function returns a list of lvm_pvs. Each lvm_pv is
        represented as a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.pvs_full (self._o)

    def vgs_full (self):
        """List all the volumes groups detected. This is the
        equivalent of the vgs(8) command. The "full" version
        includes all fields.
        
        This function returns a list of lvm_vgs. Each lvm_vg is
        represented as a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.vgs_full (self._o)

    def lvs_full (self):
        """List all the logical volumes detected. This is the
        equivalent of the lvs(8) command. The "full" version
        includes all fields.
        
        This function returns a list of lvm_lvs. Each lvm_lv is
        represented as a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.lvs_full (self._o)

    def read_lines (self, path):
        """Return the contents of the file named "path".
        
        The file contents are returned as a list of lines.
        Trailing "LF" and "CRLF" character sequences are *not*
        returned.
        
        Note that this function cannot correctly handle binary
        files (specifically, files containing "\\0" character
        which is treated as end of line). For those you need to
        use the "g.read_file" function which has a more complex
        interface.
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.read_lines (self._o, path)

    def aug_init (self, root, flags):
        """Create a new Augeas handle for editing configuration
        files. If there was any previous Augeas handle
        associated with this guestfs session, then it is closed.
        
        You must call this before using any other "g.aug_*"
        commands.
        
        "root" is the filesystem root. "root" must not be NULL,
        use "/" instead.
        
        The flags are the same as the flags defined in
        <augeas.h>, the logical *or* of the following integers:
        
        "AUG_SAVE_BACKUP" = 1
        Keep the original file with a ".augsave" extension.
        
        "AUG_SAVE_NEWFILE" = 2
        Save changes into a file with extension ".augnew",
        and do not overwrite original. Overrides
        "AUG_SAVE_BACKUP".
        
        "AUG_TYPE_CHECK" = 4
        Typecheck lenses.
        
        This option is only useful when debugging Augeas
        lenses. Use of this option may require additional
        memory for the libguestfs appliance. You may need to
        set the "LIBGUESTFS_MEMSIZE" environment variable or
        call "g.set_memsize".
        
        "AUG_NO_STDINC" = 8
        Do not use standard load path for modules.
        
        "AUG_SAVE_NOOP" = 16
        Make save a no-op, just record what would have been
        changed.
        
        "AUG_NO_LOAD" = 32
        Do not load the tree in "g.aug_init".
        
        To close the handle, you can call "g.aug_close".
        
        To find out more about Augeas, see <http://augeas.net/>.
        """
        self._check_not_closed ()
        return libguestfsmod.aug_init (self._o, root, flags)

    def aug_close (self):
        """Close the current Augeas handle and free up any
        resources used by it. After calling this, you have to
        call "g.aug_init" again before you can use any other
        Augeas functions.
        """
        self._check_not_closed ()
        return libguestfsmod.aug_close (self._o)

    def aug_defvar (self, name, expr):
        """Defines an Augeas variable "name" whose value is the
        result of evaluating "expr". If "expr" is NULL, then
        "name" is undefined.
        
        On success this returns the number of nodes in "expr",
        or 0 if "expr" evaluates to something which is not a
        nodeset.
        """
        self._check_not_closed ()
        return libguestfsmod.aug_defvar (self._o, name, expr)

    def aug_defnode (self, name, expr, val):
        """Defines a variable "name" whose value is the result of
        evaluating "expr".
        
        If "expr" evaluates to an empty nodeset, a node is
        created, equivalent to calling "g.aug_set" "expr",
        "value". "name" will be the nodeset containing that
        single node.
        
        On success this returns a pair containing the number of
        nodes in the nodeset, and a boolean flag if a node was
        created.
        
        This function returns a dictionary, with keys matching
        the various fields in the guestfs_int_bool structure.
        """
        self._check_not_closed ()
        return libguestfsmod.aug_defnode (self._o, name, expr, val)

    def aug_get (self, augpath):
        """Look up the value associated with "path". If "path"
        matches exactly one node, the "value" is returned.
        """
        self._check_not_closed ()
        return libguestfsmod.aug_get (self._o, augpath)

    def aug_set (self, augpath, val):
        """Set the value associated with "path" to "val".
        
        In the Augeas API, it is possible to clear a node by
        setting the value to NULL. Due to an oversight in the
        libguestfs API you cannot do that with this call.
        Instead you must use the "g.aug_clear" call.
        """
        self._check_not_closed ()
        return libguestfsmod.aug_set (self._o, augpath, val)

    def aug_insert (self, augpath, label, before):
        """Create a new sibling "label" for "path", inserting it
        into the tree before or after "path" (depending on the
        boolean flag "before").
        
        "path" must match exactly one existing node in the tree,
        and "label" must be a label, ie. not contain "/", "*" or
        end with a bracketed index "[N]".
        """
        self._check_not_closed ()
        return libguestfsmod.aug_insert (self._o, augpath, label, before)

    def aug_rm (self, augpath):
        """Remove "path" and all of its children.
        
        On success this returns the number of entries which were
        removed.
        """
        self._check_not_closed ()
        return libguestfsmod.aug_rm (self._o, augpath)

    def aug_mv (self, src, dest):
        """Move the node "src" to "dest". "src" must match exactly
        one node. "dest" is overwritten if it exists.
        """
        self._check_not_closed ()
        return libguestfsmod.aug_mv (self._o, src, dest)

    def aug_match (self, augpath):
        """Returns a list of paths which match the path expression
        "path". The returned paths are sufficiently qualified so
        that they match exactly one node in the current tree.
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.aug_match (self._o, augpath)

    def aug_save (self):
        """This writes all pending changes to disk.
        
        The flags which were passed to "g.aug_init" affect
        exactly how files are saved.
        """
        self._check_not_closed ()
        return libguestfsmod.aug_save (self._o)

    def aug_load (self):
        """Load files into the tree.
        
        See "aug_load" in the Augeas documentation for the full
        gory details.
        """
        self._check_not_closed ()
        return libguestfsmod.aug_load (self._o)

    def aug_ls (self, augpath):
        """This is just a shortcut for listing "g.aug_match"
        "path/*" and sorting the resulting nodes into
        alphabetical order.
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.aug_ls (self._o, augpath)

    def rm (self, path):
        """Remove the single file "path".
        """
        self._check_not_closed ()
        return libguestfsmod.rm (self._o, path)

    def rmdir (self, path):
        """Remove the single directory "path".
        """
        self._check_not_closed ()
        return libguestfsmod.rmdir (self._o, path)

    def rm_rf (self, path):
        """Remove the file or directory "path", recursively
        removing the contents if its a directory. This is like
        the "rm -rf" shell command.
        """
        self._check_not_closed ()
        return libguestfsmod.rm_rf (self._o, path)

    def mkdir (self, path):
        """Create a directory named "path".
        """
        self._check_not_closed ()
        return libguestfsmod.mkdir (self._o, path)

    def mkdir_p (self, path):
        """Create a directory named "path", creating any parent
        directories as necessary. This is like the "mkdir -p"
        shell command.
        """
        self._check_not_closed ()
        return libguestfsmod.mkdir_p (self._o, path)

    def chmod (self, mode, path):
        """Change the mode (permissions) of "path" to "mode". Only
        numeric modes are supported.
        
        *Note*: When using this command from guestfish, "mode"
        by default would be decimal, unless you prefix it with 0
        to get octal, ie. use 0700 not 700.
        
        The mode actually set is affected by the umask.
        """
        self._check_not_closed ()
        return libguestfsmod.chmod (self._o, mode, path)

    def chown (self, owner, group, path):
        """Change the file owner to "owner" and group to "group".
        
        Only numeric uid and gid are supported. If you want to
        use names, you will need to locate and parse the
        password file yourself (Augeas support makes this
        relatively easy).
        """
        self._check_not_closed ()
        return libguestfsmod.chown (self._o, owner, group, path)

    def exists (self, path):
        """This returns "true" if and only if there is a file,
        directory (or anything) with the given "path" name.
        
        See also "g.is_file", "g.is_dir", "g.stat".
        """
        self._check_not_closed ()
        return libguestfsmod.exists (self._o, path)

    def is_file (self, path):
        """This returns "true" if and only if there is a regular
        file with the given "path" name. Note that it returns
        false for other objects like directories.
        
        See also "g.stat".
        """
        self._check_not_closed ()
        return libguestfsmod.is_file (self._o, path)

    def is_dir (self, path):
        """This returns "true" if and only if there is a directory
        with the given "path" name. Note that it returns false
        for other objects like files.
        
        See also "g.stat".
        """
        self._check_not_closed ()
        return libguestfsmod.is_dir (self._o, path)

    def pvcreate (self, device):
        """This creates an LVM physical volume on the named
        "device", where "device" should usually be a partition
        name such as "/dev/sda1".
        """
        self._check_not_closed ()
        return libguestfsmod.pvcreate (self._o, device)

    def vgcreate (self, volgroup, physvols):
        """This creates an LVM volume group called "volgroup" from
        the non-empty list of physical volumes "physvols".
        """
        physvols = list (physvols)
        self._check_not_closed ()
        return libguestfsmod.vgcreate (self._o, volgroup, physvols)

    def lvcreate (self, logvol, volgroup, mbytes):
        """This creates an LVM logical volume called "logvol" on
        the volume group "volgroup", with "size" megabytes.
        """
        self._check_not_closed ()
        return libguestfsmod.lvcreate (self._o, logvol, volgroup, mbytes)

    def mkfs (self, fstype, device):
        """This creates a filesystem on "device" (usually a
        partition or LVM logical volume). The filesystem type is
        "fstype", for example "ext3".
        """
        self._check_not_closed ()
        return libguestfsmod.mkfs (self._o, fstype, device)

    def sfdisk (self, device, cyls, heads, sectors, lines):
        """This is a direct interface to the sfdisk(8) program for
        creating partitions on block devices.
        
        "device" should be a block device, for example
        "/dev/sda".
        
        "cyls", "heads" and "sectors" are the number of
        cylinders, heads and sectors on the device, which are
        passed directly to sfdisk as the *-C*, *-H* and *-S*
        parameters. If you pass 0 for any of these, then the
        corresponding parameter is omitted. Usually for 'large'
        disks, you can just pass 0 for these, but for small
        (floppy-sized) disks, sfdisk (or rather, the kernel)
        cannot work out the right geometry and you will need to
        tell it.
        
        "lines" is a list of lines that we feed to "sfdisk". For
        more information refer to the sfdisk(8) manpage.
        
        To create a single partition occupying the whole disk,
        you would pass "lines" as a single element list, when
        the single element being the string "," (comma).
        
        See also: "g.sfdisk_l", "g.sfdisk_N", "g.part_init"
        
        *This function is deprecated.* In new code, use the
        "part_add" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        lines = list (lines)
        self._check_not_closed ()
        return libguestfsmod.sfdisk (self._o, device, cyls, heads, sectors, lines)

    def write_file (self, path, content, size):
        """This call creates a file called "path". The contents of
        the file is the string "content" (which can contain any
        8 bit data), with length "size".
        
        As a special case, if "size" is 0 then the length is
        calculated using "strlen" (so in this case the content
        cannot contain embedded ASCII NULs).
        
        *NB.* Owing to a bug, writing content containing ASCII
        NUL characters does *not* work, even if the length is
        specified.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        
        *This function is deprecated.* In new code, use the
        "write" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.write_file (self._o, path, content, size)

    def umount (self, pathordevice):
        """This unmounts the given filesystem. The filesystem may
        be specified either by its mountpoint (path) or the
        device which contains the filesystem.
        """
        self._check_not_closed ()
        return libguestfsmod.umount (self._o, pathordevice)

    def mounts (self):
        """This returns the list of currently mounted filesystems.
        It returns the list of devices (eg. "/dev/sda1",
        "/dev/VG/LV").
        
        Some internal mounts are not shown.
        
        See also: "g.mountpoints"
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.mounts (self._o)

    def umount_all (self):
        """This unmounts all mounted filesystems.
        
        Some internal mounts are not unmounted by this call.
        """
        self._check_not_closed ()
        return libguestfsmod.umount_all (self._o)

    def lvm_remove_all (self):
        """This command removes all LVM logical volumes, volume
        groups and physical volumes.
        """
        self._check_not_closed ()
        return libguestfsmod.lvm_remove_all (self._o)

    def file (self, path):
        """This call uses the standard file(1) command to determine
        the type or contents of the file.
        
        This call will also transparently look inside various
        types of compressed file.
        
        The exact command which runs is "file -zb path". Note in
        particular that the filename is not prepended to the
        output (the *-b* option).
        
        The output depends on the output of the underlying
        file(1) command and it can change in future in ways
        beyond our control. In other words, the output is not
        guaranteed by the ABI.
        
        See also: file(1), "g.vfs_type", "g.lstat", "g.is_file",
        "g.is_blockdev" (etc), "g.is_zero".
        """
        self._check_not_closed ()
        return libguestfsmod.file (self._o, path)

    def command (self, arguments):
        """This call runs a command from the guest filesystem. The
        filesystem must be mounted, and must contain a
        compatible operating system (ie. something Linux, with
        the same or compatible processor architecture).
        
        The single parameter is an argv-style list of arguments.
        The first element is the name of the program to run.
        Subsequent elements are parameters. The list must be
        non-empty (ie. must contain a program name). Note that
        the command runs directly, and is *not* invoked via the
        shell (see "g.sh").
        
        The return value is anything printed to *stdout* by the
        command.
        
        If the command returns a non-zero exit status, then this
        function returns an error message. The error message
        string is the content of *stderr* from the command.
        
        The $PATH environment variable will contain at least
        "/usr/bin" and "/bin". If you require a program from
        another location, you should provide the full path in
        the first parameter.
        
        Shared libraries and data files required by the program
        must be available on filesystems which are mounted in
        the correct places. It is the caller's responsibility to
        ensure all filesystems that are needed are mounted at
        the right locations.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        arguments = list (arguments)
        self._check_not_closed ()
        return libguestfsmod.command (self._o, arguments)

    def command_lines (self, arguments):
        """This is the same as "g.command", but splits the result
        into a list of lines.
        
        See also: "g.sh_lines"
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        arguments = list (arguments)
        self._check_not_closed ()
        return libguestfsmod.command_lines (self._o, arguments)

    def stat (self, path):
        """Returns file information for the given "path".
        
        This is the same as the stat(2) system call.
        
        This function returns a dictionary, with keys matching
        the various fields in the guestfs_stat structure.
        """
        self._check_not_closed ()
        return libguestfsmod.stat (self._o, path)

    def lstat (self, path):
        """Returns file information for the given "path".
        
        This is the same as "g.stat" except that if "path" is a
        symbolic link, then the link is stat-ed, not the file it
        refers to.
        
        This is the same as the lstat(2) system call.
        
        This function returns a dictionary, with keys matching
        the various fields in the guestfs_stat structure.
        """
        self._check_not_closed ()
        return libguestfsmod.lstat (self._o, path)

    def statvfs (self, path):
        """Returns file system statistics for any mounted file
        system. "path" should be a file or directory in the
        mounted file system (typically it is the mount point
        itself, but it doesn't need to be).
        
        This is the same as the statvfs(2) system call.
        
        This function returns a dictionary, with keys matching
        the various fields in the guestfs_statvfs structure.
        """
        self._check_not_closed ()
        return libguestfsmod.statvfs (self._o, path)

    def tune2fs_l (self, device):
        """This returns the contents of the ext2, ext3 or ext4
        filesystem superblock on "device".
        
        It is the same as running "tune2fs -l device". See
        tune2fs(8) manpage for more details. The list of fields
        returned isn't clearly defined, and depends on both the
        version of "tune2fs" that libguestfs was built against,
        and the filesystem itself.
        
        This function returns a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.tune2fs_l (self._o, device)

    def blockdev_setro (self, device):
        """Sets the block device named "device" to read-only.
        
        This uses the blockdev(8) command.
        """
        self._check_not_closed ()
        return libguestfsmod.blockdev_setro (self._o, device)

    def blockdev_setrw (self, device):
        """Sets the block device named "device" to read-write.
        
        This uses the blockdev(8) command.
        """
        self._check_not_closed ()
        return libguestfsmod.blockdev_setrw (self._o, device)

    def blockdev_getro (self, device):
        """Returns a boolean indicating if the block device is
        read-only (true if read-only, false if not).
        
        This uses the blockdev(8) command.
        """
        self._check_not_closed ()
        return libguestfsmod.blockdev_getro (self._o, device)

    def blockdev_getss (self, device):
        """This returns the size of sectors on a block device.
        Usually 512, but can be larger for modern devices.
        
        (Note, this is not the size in sectors, use
        "g.blockdev_getsz" for that).
        
        This uses the blockdev(8) command.
        """
        self._check_not_closed ()
        return libguestfsmod.blockdev_getss (self._o, device)

    def blockdev_getbsz (self, device):
        """This returns the block size of a device.
        
        (Note this is different from both *size in blocks* and
        *filesystem block size*).
        
        This uses the blockdev(8) command.
        """
        self._check_not_closed ()
        return libguestfsmod.blockdev_getbsz (self._o, device)

    def blockdev_setbsz (self, device, blocksize):
        """This sets the block size of a device.
        
        (Note this is different from both *size in blocks* and
        *filesystem block size*).
        
        This uses the blockdev(8) command.
        """
        self._check_not_closed ()
        return libguestfsmod.blockdev_setbsz (self._o, device, blocksize)

    def blockdev_getsz (self, device):
        """This returns the size of the device in units of 512-byte
        sectors (even if the sectorsize isn't 512 bytes ...
        weird).
        
        See also "g.blockdev_getss" for the real sector size of
        the device, and "g.blockdev_getsize64" for the more
        useful *size in bytes*.
        
        This uses the blockdev(8) command.
        """
        self._check_not_closed ()
        return libguestfsmod.blockdev_getsz (self._o, device)

    def blockdev_getsize64 (self, device):
        """This returns the size of the device in bytes.
        
        See also "g.blockdev_getsz".
        
        This uses the blockdev(8) command.
        """
        self._check_not_closed ()
        return libguestfsmod.blockdev_getsize64 (self._o, device)

    def blockdev_flushbufs (self, device):
        """This tells the kernel to flush internal buffers
        associated with "device".
        
        This uses the blockdev(8) command.
        """
        self._check_not_closed ()
        return libguestfsmod.blockdev_flushbufs (self._o, device)

    def blockdev_rereadpt (self, device):
        """Reread the partition table on "device".
        
        This uses the blockdev(8) command.
        """
        self._check_not_closed ()
        return libguestfsmod.blockdev_rereadpt (self._o, device)

    def upload (self, filename, remotefilename):
        """Upload local file "filename" to "remotefilename" on the
        filesystem.
        
        "filename" can also be a named pipe.
        
        See also "g.download".
        """
        self._check_not_closed ()
        return libguestfsmod.upload (self._o, filename, remotefilename)

    def download (self, remotefilename, filename):
        """Download file "remotefilename" and save it as "filename"
        on the local machine.
        
        "filename" can also be a named pipe.
        
        See also "g.upload", "g.cat".
        """
        self._check_not_closed ()
        return libguestfsmod.download (self._o, remotefilename, filename)

    def checksum (self, csumtype, path):
        """This call computes the MD5, SHAx or CRC checksum of the
        file named "path".
        
        The type of checksum to compute is given by the
        "csumtype" parameter which must have one of the
        following values:
        
        "crc"
        Compute the cyclic redundancy check (CRC) specified
        by POSIX for the "cksum" command.
        
        "md5"
        Compute the MD5 hash (using the "md5sum" program).
        
        "sha1"
        Compute the SHA1 hash (using the "sha1sum" program).
        
        "sha224"
        Compute the SHA224 hash (using the "sha224sum"
        program).
        
        "sha256"
        Compute the SHA256 hash (using the "sha256sum"
        program).
        
        "sha384"
        Compute the SHA384 hash (using the "sha384sum"
        program).
        
        "sha512"
        Compute the SHA512 hash (using the "sha512sum"
        program).
        
        The checksum is returned as a printable string.
        
        To get the checksum for a device, use
        "g.checksum_device".
        
        To get the checksums for many files, use
        "g.checksums_out".
        """
        self._check_not_closed ()
        return libguestfsmod.checksum (self._o, csumtype, path)

    def tar_in (self, tarfile, directory):
        """This command uploads and unpacks local file "tarfile"
        (an *uncompressed* tar file) into "directory".
        
        To upload a compressed tarball, use "g.tgz_in" or
        "g.txz_in".
        """
        self._check_not_closed ()
        return libguestfsmod.tar_in (self._o, tarfile, directory)

    def tar_out (self, directory, tarfile):
        """This command packs the contents of "directory" and
        downloads it to local file "tarfile".
        
        To download a compressed tarball, use "g.tgz_out" or
        "g.txz_out".
        """
        self._check_not_closed ()
        return libguestfsmod.tar_out (self._o, directory, tarfile)

    def tgz_in (self, tarball, directory):
        """This command uploads and unpacks local file "tarball" (a
        *gzip compressed* tar file) into "directory".
        
        To upload an uncompressed tarball, use "g.tar_in".
        """
        self._check_not_closed ()
        return libguestfsmod.tgz_in (self._o, tarball, directory)

    def tgz_out (self, directory, tarball):
        """This command packs the contents of "directory" and
        downloads it to local file "tarball".
        
        To download an uncompressed tarball, use "g.tar_out".
        """
        self._check_not_closed ()
        return libguestfsmod.tgz_out (self._o, directory, tarball)

    def mount_ro (self, device, mountpoint):
        """This is the same as the "g.mount" command, but it mounts
        the filesystem with the read-only (*-o ro*) flag.
        """
        self._check_not_closed ()
        return libguestfsmod.mount_ro (self._o, device, mountpoint)

    def mount_options (self, options, device, mountpoint):
        """This is the same as the "g.mount" command, but it allows
        you to set the mount options as for the mount(8) *-o*
        flag.
        
        If the "options" parameter is an empty string, then no
        options are passed (all options default to whatever the
        filesystem uses).
        """
        self._check_not_closed ()
        return libguestfsmod.mount_options (self._o, options, device, mountpoint)

    def mount_vfs (self, options, vfstype, device, mountpoint):
        """This is the same as the "g.mount" command, but it allows
        you to set both the mount options and the vfstype as for
        the mount(8) *-o* and *-t* flags.
        """
        self._check_not_closed ()
        return libguestfsmod.mount_vfs (self._o, options, vfstype, device, mountpoint)

    def debug (self, subcmd, extraargs):
        extraargs = list (extraargs)
        self._check_not_closed ()
        return libguestfsmod.debug (self._o, subcmd, extraargs)

    def lvremove (self, device):
        """Remove an LVM logical volume "device", where "device" is
        the path to the LV, such as "/dev/VG/LV".
        
        You can also remove all LVs in a volume group by
        specifying the VG name, "/dev/VG".
        """
        self._check_not_closed ()
        return libguestfsmod.lvremove (self._o, device)

    def vgremove (self, vgname):
        """Remove an LVM volume group "vgname", (for example "VG").
        
        This also forcibly removes all logical volumes in the
        volume group (if any).
        """
        self._check_not_closed ()
        return libguestfsmod.vgremove (self._o, vgname)

    def pvremove (self, device):
        """This wipes a physical volume "device" so that LVM will
        no longer recognise it.
        
        The implementation uses the "pvremove" command which
        refuses to wipe physical volumes that contain any volume
        groups, so you have to remove those first.
        """
        self._check_not_closed ()
        return libguestfsmod.pvremove (self._o, device)

    def set_e2label (self, device, label):
        """This sets the ext2/3/4 filesystem label of the
        filesystem on "device" to "label". Filesystem labels are
        limited to 16 characters.
        
        You can use either "g.tune2fs_l" or "g.get_e2label" to
        return the existing label on a filesystem.
        
        *This function is deprecated.* In new code, use the
        "set_label" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.set_e2label (self._o, device, label)

    def get_e2label (self, device):
        """This returns the ext2/3/4 filesystem label of the
        filesystem on "device".
        
        *This function is deprecated.* In new code, use the
        "vfs_label" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.get_e2label (self._o, device)

    def set_e2uuid (self, device, uuid):
        """This sets the ext2/3/4 filesystem UUID of the filesystem
        on "device" to "uuid". The format of the UUID and
        alternatives such as "clear", "random" and "time" are
        described in the tune2fs(8) manpage.
        
        You can use either "g.tune2fs_l" or "g.get_e2uuid" to
        return the existing UUID of a filesystem.
        """
        self._check_not_closed ()
        return libguestfsmod.set_e2uuid (self._o, device, uuid)

    def get_e2uuid (self, device):
        """This returns the ext2/3/4 filesystem UUID of the
        filesystem on "device".
        
        *This function is deprecated.* In new code, use the
        "vfs_uuid" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.get_e2uuid (self._o, device)

    def fsck (self, fstype, device):
        """This runs the filesystem checker (fsck) on "device"
        which should have filesystem type "fstype".
        
        The returned integer is the status. See fsck(8) for the
        list of status codes from "fsck".
        
        Notes:
        
        *   Multiple status codes can be summed together.
        
        *   A non-zero return code can mean "success", for
        example if errors have been corrected on the
        filesystem.
        
        *   Checking or repairing NTFS volumes is not supported
        (by linux-ntfs).
        
        This command is entirely equivalent to running "fsck -a
        -t fstype device".
        """
        self._check_not_closed ()
        return libguestfsmod.fsck (self._o, fstype, device)

    def zero (self, device):
        """This command writes zeroes over the first few blocks of
        "device".
        
        How many blocks are zeroed isn't specified (but it's
        *not* enough to securely wipe the device). It should be
        sufficient to remove any partition tables, filesystem
        superblocks and so on.
        
        If blocks are already zero, then this command avoids
        writing zeroes. This prevents the underlying device from
        becoming non-sparse or growing unnecessarily.
        
        See also: "g.zero_device", "g.scrub_device",
        "g.is_zero_device"
        """
        self._check_not_closed ()
        return libguestfsmod.zero (self._o, device)

    def grub_install (self, root, device):
        """This command installs GRUB 1 (the Grand Unified
        Bootloader) on "device", with the root directory being
        "root".
        
        Notes:
        
        *   There is currently no way in the API to install
        grub2, which is used by most modern Linux guests. It
        is possible to run the grub2 command from the guest,
        although see the caveats in "RUNNING COMMANDS" in
        guestfs(3).
        
        *   This uses "grub-install" from the host.
        Unfortunately grub is not always compatible with
        itself, so this only works in rather narrow
        circumstances. Careful testing with each guest
        version is advisable.
        
        *   If grub-install reports the error "No suitable drive
        was found in the generated device map." it may be
        that you need to create a "/boot/grub/device.map"
        file first that contains the mapping between grub
        device names and Linux device names. It is usually
        sufficient to create a file containing:
        
        (hd0) /dev/vda
        
        replacing "/dev/vda" with the name of the
        installation device.
        """
        self._check_not_closed ()
        return libguestfsmod.grub_install (self._o, root, device)

    def cp (self, src, dest):
        """This copies a file from "src" to "dest" where "dest" is
        either a destination filename or destination directory.
        """
        self._check_not_closed ()
        return libguestfsmod.cp (self._o, src, dest)

    def cp_a (self, src, dest):
        """This copies a file or directory from "src" to "dest"
        recursively using the "cp -a" command.
        """
        self._check_not_closed ()
        return libguestfsmod.cp_a (self._o, src, dest)

    def mv (self, src, dest):
        """This moves a file from "src" to "dest" where "dest" is
        either a destination filename or destination directory.
        """
        self._check_not_closed ()
        return libguestfsmod.mv (self._o, src, dest)

    def drop_caches (self, whattodrop):
        """This instructs the guest kernel to drop its page cache,
        and/or dentries and inode caches. The parameter
        "whattodrop" tells the kernel what precisely to drop,
        see <http://linux-mm.org/Drop_Caches>
        
        Setting "whattodrop" to 3 should drop everything.
        
        This automatically calls sync(2) before the operation,
        so that the maximum guest memory is freed.
        """
        self._check_not_closed ()
        return libguestfsmod.drop_caches (self._o, whattodrop)

    def dmesg (self):
        """This returns the kernel messages ("dmesg" output) from
        the guest kernel. This is sometimes useful for extended
        debugging of problems.
        
        Another way to get the same information is to enable
        verbose messages with "g.set_verbose" or by setting the
        environment variable "LIBGUESTFS_DEBUG=1" before running
        the program.
        """
        self._check_not_closed ()
        return libguestfsmod.dmesg (self._o)

    def ping_daemon (self):
        """This is a test probe into the guestfs daemon running
        inside the qemu subprocess. Calling this function checks
        that the daemon responds to the ping message, without
        affecting the daemon or attached block device(s) in any
        other way.
        """
        self._check_not_closed ()
        return libguestfsmod.ping_daemon (self._o)

    def equal (self, file1, file2):
        """This compares the two files "file1" and "file2" and
        returns true if their content is exactly equal, or false
        otherwise.
        
        The external cmp(1) program is used for the comparison.
        """
        self._check_not_closed ()
        return libguestfsmod.equal (self._o, file1, file2)

    def strings (self, path):
        """This runs the strings(1) command on a file and returns
        the list of printable strings found.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.strings (self._o, path)

    def strings_e (self, encoding, path):
        """This is like the "g.strings" command, but allows you to
        specify the encoding of strings that are looked for in
        the source file "path".
        
        Allowed encodings are:
        
        s   Single 7-bit-byte characters like ASCII and the
        ASCII-compatible parts of ISO-8859-X (this is what
        "g.strings" uses).
        
        S   Single 8-bit-byte characters.
        
        b   16-bit big endian strings such as those encoded in
        UTF-16BE or UCS-2BE.
        
        l (lower case letter L)
        16-bit little endian such as UTF-16LE and UCS-2LE.
        This is useful for examining binaries in Windows
        guests.
        
        B   32-bit big endian such as UCS-4BE.
        
        L   32-bit little endian such as UCS-4LE.
        
        The returned strings are transcoded to UTF-8.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.strings_e (self._o, encoding, path)

    def hexdump (self, path):
        """This runs "hexdump -C" on the given "path". The result
        is the human-readable, canonical hex dump of the file.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.hexdump (self._o, path)

    def zerofree (self, device):
        """This runs the *zerofree* program on "device". This
        program claims to zero unused inodes and disk blocks on
        an ext2/3 filesystem, thus making it possible to
        compress the filesystem more effectively.
        
        You should not run this program if the filesystem is
        mounted.
        
        It is possible that using this program can damage the
        filesystem or data on the filesystem.
        """
        self._check_not_closed ()
        return libguestfsmod.zerofree (self._o, device)

    def pvresize (self, device):
        """This resizes (expands or shrinks) an existing LVM
        physical volume to match the new size of the underlying
        device.
        """
        self._check_not_closed ()
        return libguestfsmod.pvresize (self._o, device)

    def sfdisk_N (self, device, partnum, cyls, heads, sectors, line):
        """This runs sfdisk(8) option to modify just the single
        partition "n" (note: "n" counts from 1).
        
        For other parameters, see "g.sfdisk". You should usually
        pass 0 for the cyls/heads/sectors parameters.
        
        See also: "g.part_add"
        
        *This function is deprecated.* In new code, use the
        "part_add" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.sfdisk_N (self._o, device, partnum, cyls, heads, sectors, line)

    def sfdisk_l (self, device):
        """This displays the partition table on "device", in the
        human-readable output of the sfdisk(8) command. It is
        not intended to be parsed.
        
        See also: "g.part_list"
        
        *This function is deprecated.* In new code, use the
        "part_list" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.sfdisk_l (self._o, device)

    def sfdisk_kernel_geometry (self, device):
        """This displays the kernel's idea of the geometry of
        "device".
        
        The result is in human-readable format, and not designed
        to be parsed.
        """
        self._check_not_closed ()
        return libguestfsmod.sfdisk_kernel_geometry (self._o, device)

    def sfdisk_disk_geometry (self, device):
        """This displays the disk geometry of "device" read from
        the partition table. Especially in the case where the
        underlying block device has been resized, this can be
        different from the kernel's idea of the geometry (see
        "g.sfdisk_kernel_geometry").
        
        The result is in human-readable format, and not designed
        to be parsed.
        """
        self._check_not_closed ()
        return libguestfsmod.sfdisk_disk_geometry (self._o, device)

    def vg_activate_all (self, activate):
        """This command activates or (if "activate" is false)
        deactivates all logical volumes in all volume groups.
        
        This command is the same as running "vgchange -a y|n"
        """
        self._check_not_closed ()
        return libguestfsmod.vg_activate_all (self._o, activate)

    def vg_activate (self, activate, volgroups):
        """This command activates or (if "activate" is false)
        deactivates all logical volumes in the listed volume
        groups "volgroups".
        
        This command is the same as running "vgchange -a y|n
        volgroups..."
        
        Note that if "volgroups" is an empty list then all
        volume groups are activated or deactivated.
        """
        volgroups = list (volgroups)
        self._check_not_closed ()
        return libguestfsmod.vg_activate (self._o, activate, volgroups)

    def lvresize (self, device, mbytes):
        """This resizes (expands or shrinks) an existing LVM
        logical volume to "mbytes". When reducing, data in the
        reduced part is lost.
        """
        self._check_not_closed ()
        return libguestfsmod.lvresize (self._o, device, mbytes)

    def resize2fs (self, device):
        """This resizes an ext2, ext3 or ext4 filesystem to match
        the size of the underlying device.
        
        See also "RESIZE2FS ERRORS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.resize2fs (self._o, device)

    def find (self, directory):
        """This command lists out all files and directories,
        recursively, starting at "directory". It is essentially
        equivalent to running the shell command "find directory
        -print" but some post-processing happens on the output,
        described below.
        
        This returns a list of strings *without any prefix*.
        Thus if the directory structure was:
        
        /tmp/a
        /tmp/b
        /tmp/c/d
        
        then the returned list from "g.find" "/tmp" would be 4
        elements:
        
        a
        b
        c
        c/d
        
        If "directory" is not a directory, then this command
        returns an error.
        
        The returned list is sorted.
        
        See also "g.find0".
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.find (self._o, directory)

    def e2fsck_f (self, device):
        """This runs "e2fsck -p -f device", ie. runs the ext2/ext3
        filesystem checker on "device", noninteractively (*-p*),
        even if the filesystem appears to be clean (*-f*).
        
        *This function is deprecated.* In new code, use the
        "e2fsck" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.e2fsck_f (self._o, device)

    def sleep (self, secs):
        """Sleep for "secs" seconds.
        """
        self._check_not_closed ()
        return libguestfsmod.sleep (self._o, secs)

    def ntfs_3g_probe (self, rw, device):
        """This command runs the ntfs-3g.probe(8) command which
        probes an NTFS "device" for mountability. (Not all NTFS
        volumes can be mounted read-write, and some cannot be
        mounted at all).
        
        "rw" is a boolean flag. Set it to true if you want to
        test if the volume can be mounted read-write. Set it to
        false if you want to test if the volume can be mounted
        read-only.
        
        The return value is an integer which 0 if the operation
        would succeed, or some non-zero value documented in the
        ntfs-3g.probe(8) manual page.
        """
        self._check_not_closed ()
        return libguestfsmod.ntfs_3g_probe (self._o, rw, device)

    def sh (self, command):
        """This call runs a command from the guest filesystem via
        the guest's "/bin/sh".
        
        This is like "g.command", but passes the command to:
        
        /bin/sh -c "command"
        
        Depending on the guest's shell, this usually results in
        wildcards being expanded, shell expressions being
        interpolated and so on.
        
        All the provisos about "g.command" apply to this call.
        """
        self._check_not_closed ()
        return libguestfsmod.sh (self._o, command)

    def sh_lines (self, command):
        """This is the same as "g.sh", but splits the result into a
        list of lines.
        
        See also: "g.command_lines"
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.sh_lines (self._o, command)

    def glob_expand (self, pattern):
        """This command searches for all the pathnames matching
        "pattern" according to the wildcard expansion rules used
        by the shell.
        
        If no paths match, then this returns an empty list
        (note: not an error).
        
        It is just a wrapper around the C glob(3) function with
        flags "GLOB_MARK|GLOB_BRACE". See that manual page for
        more details.
        
        Notice that there is no equivalent command for expanding
        a device name (eg. "/dev/sd*"). Use "g.list_devices",
        "g.list_partitions" etc functions instead.
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.glob_expand (self._o, pattern)

    def scrub_device (self, device):
        """This command writes patterns over "device" to make data
        retrieval more difficult.
        
        It is an interface to the scrub(1) program. See that
        manual page for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.scrub_device (self._o, device)

    def scrub_file (self, file):
        """This command writes patterns over a file to make data
        retrieval more difficult.
        
        The file is *removed* after scrubbing.
        
        It is an interface to the scrub(1) program. See that
        manual page for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.scrub_file (self._o, file)

    def scrub_freespace (self, dir):
        """This command creates the directory "dir" and then fills
        it with files until the filesystem is full, and scrubs
        the files as for "g.scrub_file", and deletes them. The
        intention is to scrub any free space on the partition
        containing "dir".
        
        It is an interface to the scrub(1) program. See that
        manual page for more details.
        """
        self._check_not_closed ()
        return libguestfsmod.scrub_freespace (self._o, dir)

    def mkdtemp (self, tmpl):
        """This command creates a temporary directory. The "tmpl"
        parameter should be a full pathname for the temporary
        directory name with the final six characters being
        "XXXXXX".
        
        For example: "/tmp/myprogXXXXXX" or
        "/Temp/myprogXXXXXX", the second one being suitable for
        Windows filesystems.
        
        The name of the temporary directory that was created is
        returned.
        
        The temporary directory is created with mode 0700 and is
        owned by root.
        
        The caller is responsible for deleting the temporary
        directory and its contents after use.
        
        See also: mkdtemp(3)
        """
        self._check_not_closed ()
        return libguestfsmod.mkdtemp (self._o, tmpl)

    def wc_l (self, path):
        """This command counts the lines in a file, using the "wc
        -l" external command.
        """
        self._check_not_closed ()
        return libguestfsmod.wc_l (self._o, path)

    def wc_w (self, path):
        """This command counts the words in a file, using the "wc
        -w" external command.
        """
        self._check_not_closed ()
        return libguestfsmod.wc_w (self._o, path)

    def wc_c (self, path):
        """This command counts the characters in a file, using the
        "wc -c" external command.
        """
        self._check_not_closed ()
        return libguestfsmod.wc_c (self._o, path)

    def head (self, path):
        """This command returns up to the first 10 lines of a file
        as a list of strings.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.head (self._o, path)

    def head_n (self, nrlines, path):
        """If the parameter "nrlines" is a positive number, this
        returns the first "nrlines" lines of the file "path".
        
        If the parameter "nrlines" is a negative number, this
        returns lines from the file "path", excluding the last
        "nrlines" lines.
        
        If the parameter "nrlines" is zero, this returns an
        empty list.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.head_n (self._o, nrlines, path)

    def tail (self, path):
        """This command returns up to the last 10 lines of a file
        as a list of strings.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.tail (self._o, path)

    def tail_n (self, nrlines, path):
        """If the parameter "nrlines" is a positive number, this
        returns the last "nrlines" lines of the file "path".
        
        If the parameter "nrlines" is a negative number, this
        returns lines from the file "path", starting with the
        "-nrlines"th line.
        
        If the parameter "nrlines" is zero, this returns an
        empty list.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.tail_n (self._o, nrlines, path)

    def df (self):
        """This command runs the "df" command to report disk space
        used.
        
        This command is mostly useful for interactive sessions.
        It is *not* intended that you try to parse the output
        string. Use "g.statvfs" from programs.
        """
        self._check_not_closed ()
        return libguestfsmod.df (self._o)

    def df_h (self):
        """This command runs the "df -h" command to report disk
        space used in human-readable format.
        
        This command is mostly useful for interactive sessions.
        It is *not* intended that you try to parse the output
        string. Use "g.statvfs" from programs.
        """
        self._check_not_closed ()
        return libguestfsmod.df_h (self._o)

    def du (self, path):
        """This command runs the "du -s" command to estimate file
        space usage for "path".
        
        "path" can be a file or a directory. If "path" is a
        directory then the estimate includes the contents of the
        directory and all subdirectories (recursively).
        
        The result is the estimated size in *kilobytes* (ie.
        units of 1024 bytes).
        """
        self._check_not_closed ()
        return libguestfsmod.du (self._o, path)

    def initrd_list (self, path):
        """This command lists out files contained in an initrd.
        
        The files are listed without any initial "/" character.
        The files are listed in the order they appear (not
        necessarily alphabetical). Directory names are listed as
        separate items.
        
        Old Linux kernels (2.4 and earlier) used a compressed
        ext2 filesystem as initrd. We *only* support the newer
        initramfs format (compressed cpio files).
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.initrd_list (self._o, path)

    def mount_loop (self, file, mountpoint):
        """This command lets you mount "file" (a filesystem image
        in a file) on a mount point. It is entirely equivalent
        to the command "mount -o loop file mountpoint".
        """
        self._check_not_closed ()
        return libguestfsmod.mount_loop (self._o, file, mountpoint)

    def mkswap (self, device):
        """Create a swap partition on "device".
        """
        self._check_not_closed ()
        return libguestfsmod.mkswap (self._o, device)

    def mkswap_L (self, label, device):
        """Create a swap partition on "device" with label "label".
        
        Note that you cannot attach a swap label to a block
        device (eg. "/dev/sda"), just to a partition. This
        appears to be a limitation of the kernel or swap tools.
        """
        self._check_not_closed ()
        return libguestfsmod.mkswap_L (self._o, label, device)

    def mkswap_U (self, uuid, device):
        """Create a swap partition on "device" with UUID "uuid".
        """
        self._check_not_closed ()
        return libguestfsmod.mkswap_U (self._o, uuid, device)

    def mknod (self, mode, devmajor, devminor, path):
        """This call creates block or character special devices, or
        named pipes (FIFOs).
        
        The "mode" parameter should be the mode, using the
        standard constants. "devmajor" and "devminor" are the
        device major and minor numbers, only used when creating
        block and character special devices.
        
        Note that, just like mknod(2), the mode must be bitwise
        OR'd with S_IFBLK, S_IFCHR, S_IFIFO or S_IFSOCK
        (otherwise this call just creates a regular file). These
        constants are available in the standard Linux header
        files, or you can use "g.mknod_b", "g.mknod_c" or
        "g.mkfifo" which are wrappers around this command which
        bitwise OR in the appropriate constant for you.
        
        The mode actually set is affected by the umask.
        """
        self._check_not_closed ()
        return libguestfsmod.mknod (self._o, mode, devmajor, devminor, path)

    def mkfifo (self, mode, path):
        """This call creates a FIFO (named pipe) called "path" with
        mode "mode". It is just a convenient wrapper around
        "g.mknod".
        
        The mode actually set is affected by the umask.
        """
        self._check_not_closed ()
        return libguestfsmod.mkfifo (self._o, mode, path)

    def mknod_b (self, mode, devmajor, devminor, path):
        """This call creates a block device node called "path" with
        mode "mode" and device major/minor "devmajor" and
        "devminor". It is just a convenient wrapper around
        "g.mknod".
        
        The mode actually set is affected by the umask.
        """
        self._check_not_closed ()
        return libguestfsmod.mknod_b (self._o, mode, devmajor, devminor, path)

    def mknod_c (self, mode, devmajor, devminor, path):
        """This call creates a char device node called "path" with
        mode "mode" and device major/minor "devmajor" and
        "devminor". It is just a convenient wrapper around
        "g.mknod".
        
        The mode actually set is affected by the umask.
        """
        self._check_not_closed ()
        return libguestfsmod.mknod_c (self._o, mode, devmajor, devminor, path)

    def umask (self, mask):
        """This function sets the mask used for creating new files
        and device nodes to "mask & 0777".
        
        Typical umask values would be 022 which creates new
        files with permissions like "-rw-r--r--" or
        "-rwxr-xr-x", and 002 which creates new files with
        permissions like "-rw-rw-r--" or "-rwxrwxr-x".
        
        The default umask is 022. This is important because it
        means that directories and device nodes will be created
        with 0644 or 0755 mode even if you specify 0777.
        
        See also "g.get_umask", umask(2), "g.mknod", "g.mkdir".
        
        This call returns the previous umask.
        """
        self._check_not_closed ()
        return libguestfsmod.umask (self._o, mask)

    def readdir (self, dir):
        """This returns the list of directory entries in directory
        "dir".
        
        All entries in the directory are returned, including "."
        and "..". The entries are *not* sorted, but returned in
        the same order as the underlying filesystem.
        
        Also this call returns basic file type information about
        each file. The "ftyp" field will contain one of the
        following characters:
        
        'b' Block special
        
        'c' Char special
        
        'd' Directory
        
        'f' FIFO (named pipe)
        
        'l' Symbolic link
        
        'r' Regular file
        
        's' Socket
        
        'u' Unknown file type
        
        '?' The readdir(3) call returned a "d_type" field with
        an unexpected value
        
        This function is primarily intended for use by programs.
        To get a simple list of names, use "g.ls". To get a
        printable directory for human consumption, use "g.ll".
        
        This function returns a list of dirents. Each dirent is
        represented as a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.readdir (self._o, dir)

    def sfdiskM (self, device, lines):
        """This is a simplified interface to the "g.sfdisk"
        command, where partition sizes are specified in
        megabytes only (rounded to the nearest cylinder) and you
        don't need to specify the cyls, heads and sectors
        parameters which were rarely if ever used anyway.
        
        See also: "g.sfdisk", the sfdisk(8) manpage and
        "g.part_disk"
        
        *This function is deprecated.* In new code, use the
        "part_add" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        lines = list (lines)
        self._check_not_closed ()
        return libguestfsmod.sfdiskM (self._o, device, lines)

    def zfile (self, meth, path):
        """This command runs "file" after first decompressing
        "path" using "method".
        
        "method" must be one of "gzip", "compress" or "bzip2".
        
        Since 1.0.63, use "g.file" instead which can now process
        compressed files.
        
        *This function is deprecated.* In new code, use the
        "file" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.zfile (self._o, meth, path)

    def getxattrs (self, path):
        """This call lists the extended attributes of the file or
        directory "path".
        
        At the system call level, this is a combination of the
        listxattr(2) and getxattr(2) calls.
        
        See also: "g.lgetxattrs", attr(5).
        
        This function returns a list of xattrs. Each xattr is
        represented as a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.getxattrs (self._o, path)

    def lgetxattrs (self, path):
        """This is the same as "g.getxattrs", but if "path" is a
        symbolic link, then it returns the extended attributes
        of the link itself.
        
        This function returns a list of xattrs. Each xattr is
        represented as a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.lgetxattrs (self._o, path)

    def setxattr (self, xattr, val, vallen, path):
        """This call sets the extended attribute named "xattr" of
        the file "path" to the value "val" (of length "vallen").
        The value is arbitrary 8 bit data.
        
        See also: "g.lsetxattr", attr(5).
        """
        self._check_not_closed ()
        return libguestfsmod.setxattr (self._o, xattr, val, vallen, path)

    def lsetxattr (self, xattr, val, vallen, path):
        """This is the same as "g.setxattr", but if "path" is a
        symbolic link, then it sets an extended attribute of the
        link itself.
        """
        self._check_not_closed ()
        return libguestfsmod.lsetxattr (self._o, xattr, val, vallen, path)

    def removexattr (self, xattr, path):
        """This call removes the extended attribute named "xattr"
        of the file "path".
        
        See also: "g.lremovexattr", attr(5).
        """
        self._check_not_closed ()
        return libguestfsmod.removexattr (self._o, xattr, path)

    def lremovexattr (self, xattr, path):
        """This is the same as "g.removexattr", but if "path" is a
        symbolic link, then it removes an extended attribute of
        the link itself.
        """
        self._check_not_closed ()
        return libguestfsmod.lremovexattr (self._o, xattr, path)

    def mountpoints (self):
        """This call is similar to "g.mounts". That call returns a
        list of devices. This one returns a hash table (map) of
        device name to directory where the device is mounted.
        
        This function returns a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.mountpoints (self._o)

    def mkmountpoint (self, exemptpath):
        """"g.mkmountpoint" and "g.rmmountpoint" are specialized
        calls that can be used to create extra mountpoints
        before mounting the first filesystem.
        
        These calls are *only* necessary in some very limited
        circumstances, mainly the case where you want to mount a
        mix of unrelated and/or read-only filesystems together.
        
        For example, live CDs often contain a "Russian doll"
        nest of filesystems, an ISO outer layer, with a squashfs
        image inside, with an ext2/3 image inside that. You can
        unpack this as follows in guestfish:
        
        add-ro Fedora-11-i686-Live.iso
        run
        mkmountpoint /cd
        mkmountpoint /sqsh
        mkmountpoint /ext3fs
        mount /dev/sda /cd
        mount-loop /cd/LiveOS/squashfs.img /sqsh
        mount-loop /sqsh/LiveOS/ext3fs.img /ext3fs
        
        The inner filesystem is now unpacked under the /ext3fs
        mountpoint.
        
        "g.mkmountpoint" is not compatible with "g.umount_all".
        You may get unexpected errors if you try to mix these
        calls. It is safest to manually unmount filesystems and
        remove mountpoints after use.
        
        "g.umount_all" unmounts filesystems by sorting the paths
        longest first, so for this to work for manual
        mountpoints, you must ensure that the innermost
        mountpoints have the longest pathnames, as in the
        example code above.
        
        For more details see
        <https://bugzilla.redhat.com/show_bug.cgi?id=599503>
        
        Autosync [see "g.set_autosync", this is set by default
        on handles] can cause "g.umount_all" to be called when
        the handle is closed which can also trigger these
        issues.
        """
        self._check_not_closed ()
        return libguestfsmod.mkmountpoint (self._o, exemptpath)

    def rmmountpoint (self, exemptpath):
        """This calls removes a mountpoint that was previously
        created with "g.mkmountpoint". See "g.mkmountpoint" for
        full details.
        """
        self._check_not_closed ()
        return libguestfsmod.rmmountpoint (self._o, exemptpath)

    def read_file (self, path):
        """This calls returns the contents of the file "path" as a
        buffer.
        
        Unlike "g.cat", this function can correctly handle files
        that contain embedded ASCII NUL characters. However
        unlike "g.download", this function is limited in the
        total size of file that can be handled.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.read_file (self._o, path)

    def grep (self, regex, path):
        """This calls the external "grep" program and returns the
        matching lines.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.grep (self._o, regex, path)

    def egrep (self, regex, path):
        """This calls the external "egrep" program and returns the
        matching lines.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.egrep (self._o, regex, path)

    def fgrep (self, pattern, path):
        """This calls the external "fgrep" program and returns the
        matching lines.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.fgrep (self._o, pattern, path)

    def grepi (self, regex, path):
        """This calls the external "grep -i" program and returns
        the matching lines.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.grepi (self._o, regex, path)

    def egrepi (self, regex, path):
        """This calls the external "egrep -i" program and returns
        the matching lines.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.egrepi (self._o, regex, path)

    def fgrepi (self, pattern, path):
        """This calls the external "fgrep -i" program and returns
        the matching lines.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.fgrepi (self._o, pattern, path)

    def zgrep (self, regex, path):
        """This calls the external "zgrep" program and returns the
        matching lines.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.zgrep (self._o, regex, path)

    def zegrep (self, regex, path):
        """This calls the external "zegrep" program and returns the
        matching lines.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.zegrep (self._o, regex, path)

    def zfgrep (self, pattern, path):
        """This calls the external "zfgrep" program and returns the
        matching lines.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.zfgrep (self._o, pattern, path)

    def zgrepi (self, regex, path):
        """This calls the external "zgrep -i" program and returns
        the matching lines.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.zgrepi (self._o, regex, path)

    def zegrepi (self, regex, path):
        """This calls the external "zegrep -i" program and returns
        the matching lines.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.zegrepi (self._o, regex, path)

    def zfgrepi (self, pattern, path):
        """This calls the external "zfgrep -i" program and returns
        the matching lines.
        
        This function returns a list of strings.
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.zfgrepi (self._o, pattern, path)

    def realpath (self, path):
        """Return the canonicalized absolute pathname of "path".
        The returned path has no ".", ".." or symbolic link path
        elements.
        """
        self._check_not_closed ()
        return libguestfsmod.realpath (self._o, path)

    def ln (self, target, linkname):
        """This command creates a hard link using the "ln" command.
        """
        self._check_not_closed ()
        return libguestfsmod.ln (self._o, target, linkname)

    def ln_f (self, target, linkname):
        """This command creates a hard link using the "ln -f"
        command. The *-f* option removes the link ("linkname")
        if it exists already.
        """
        self._check_not_closed ()
        return libguestfsmod.ln_f (self._o, target, linkname)

    def ln_s (self, target, linkname):
        """This command creates a symbolic link using the "ln -s"
        command.
        """
        self._check_not_closed ()
        return libguestfsmod.ln_s (self._o, target, linkname)

    def ln_sf (self, target, linkname):
        """This command creates a symbolic link using the "ln -sf"
        command, The *-f* option removes the link ("linkname")
        if it exists already.
        """
        self._check_not_closed ()
        return libguestfsmod.ln_sf (self._o, target, linkname)

    def readlink (self, path):
        """This command reads the target of a symbolic link.
        """
        self._check_not_closed ()
        return libguestfsmod.readlink (self._o, path)

    def fallocate (self, path, len):
        """This command preallocates a file (containing zero bytes)
        named "path" of size "len" bytes. If the file exists
        already, it is overwritten.
        
        Do not confuse this with the guestfish-specific "alloc"
        command which allocates a file in the host and attaches
        it as a device.
        
        *This function is deprecated.* In new code, use the
        "fallocate64" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.fallocate (self._o, path, len)

    def swapon_device (self, device):
        """This command enables the libguestfs appliance to use the
        swap device or partition named "device". The increased
        memory is made available for all commands, for example
        those run using "g.command" or "g.sh".
        
        Note that you should not swap to existing guest swap
        partitions unless you know what you are doing. They may
        contain hibernation information, or other information
        that the guest doesn't want you to trash. You also risk
        leaking information about the host to the guest this
        way. Instead, attach a new host device to the guest and
        swap on that.
        """
        self._check_not_closed ()
        return libguestfsmod.swapon_device (self._o, device)

    def swapoff_device (self, device):
        """This command disables the libguestfs appliance swap
        device or partition named "device". See
        "g.swapon_device".
        """
        self._check_not_closed ()
        return libguestfsmod.swapoff_device (self._o, device)

    def swapon_file (self, file):
        """This command enables swap to a file. See
        "g.swapon_device" for other notes.
        """
        self._check_not_closed ()
        return libguestfsmod.swapon_file (self._o, file)

    def swapoff_file (self, file):
        """This command disables the libguestfs appliance swap on
        file.
        """
        self._check_not_closed ()
        return libguestfsmod.swapoff_file (self._o, file)

    def swapon_label (self, label):
        """This command enables swap to a labeled swap partition.
        See "g.swapon_device" for other notes.
        """
        self._check_not_closed ()
        return libguestfsmod.swapon_label (self._o, label)

    def swapoff_label (self, label):
        """This command disables the libguestfs appliance swap on
        labeled swap partition.
        """
        self._check_not_closed ()
        return libguestfsmod.swapoff_label (self._o, label)

    def swapon_uuid (self, uuid):
        """This command enables swap to a swap partition with the
        given UUID. See "g.swapon_device" for other notes.
        """
        self._check_not_closed ()
        return libguestfsmod.swapon_uuid (self._o, uuid)

    def swapoff_uuid (self, uuid):
        """This command disables the libguestfs appliance swap
        partition with the given UUID.
        """
        self._check_not_closed ()
        return libguestfsmod.swapoff_uuid (self._o, uuid)

    def mkswap_file (self, path):
        """Create a swap file.
        
        This command just writes a swap file signature to an
        existing file. To create the file itself, use something
        like "g.fallocate".
        """
        self._check_not_closed ()
        return libguestfsmod.mkswap_file (self._o, path)

    def inotify_init (self, maxevents):
        """This command creates a new inotify handle. The inotify
        subsystem can be used to notify events which happen to
        objects in the guest filesystem.
        
        "maxevents" is the maximum number of events which will
        be queued up between calls to "g.inotify_read" or
        "g.inotify_files". If this is passed as 0, then the
        kernel (or previously set) default is used. For Linux
        2.6.29 the default was 16384 events. Beyond this limit,
        the kernel throws away events, but records the fact that
        it threw them away by setting a flag "IN_Q_OVERFLOW" in
        the returned structure list (see "g.inotify_read").
        
        Before any events are generated, you have to add some
        watches to the internal watch list. See:
        "g.inotify_add_watch" and "g.inotify_rm_watch".
        
        Queued up events should be read periodically by calling
        "g.inotify_read" (or "g.inotify_files" which is just a
        helpful wrapper around "g.inotify_read"). If you don't
        read the events out often enough then you risk the
        internal queue overflowing.
        
        The handle should be closed after use by calling
        "g.inotify_close". This also removes any watches
        automatically.
        
        See also inotify(7) for an overview of the inotify
        interface as exposed by the Linux kernel, which is
        roughly what we expose via libguestfs. Note that there
        is one global inotify handle per libguestfs instance.
        """
        self._check_not_closed ()
        return libguestfsmod.inotify_init (self._o, maxevents)

    def inotify_add_watch (self, path, mask):
        """Watch "path" for the events listed in "mask".
        
        Note that if "path" is a directory then events within
        that directory are watched, but this does *not* happen
        recursively (in subdirectories).
        
        Note for non-C or non-Linux callers: the inotify events
        are defined by the Linux kernel ABI and are listed in
        "/usr/include/sys/inotify.h".
        """
        self._check_not_closed ()
        return libguestfsmod.inotify_add_watch (self._o, path, mask)

    def inotify_rm_watch (self, wd):
        """Remove a previously defined inotify watch. See
        "g.inotify_add_watch".
        """
        self._check_not_closed ()
        return libguestfsmod.inotify_rm_watch (self._o, wd)

    def inotify_read (self):
        """Return the complete queue of events that have happened
        since the previous read call.
        
        If no events have happened, this returns an empty list.
        
        *Note*: In order to make sure that all events have been
        read, you must call this function repeatedly until it
        returns an empty list. The reason is that the call will
        read events up to the maximum appliance-to-host message
        size and leave remaining events in the queue.
        
        This function returns a list of inotify_events. Each
        inotify_event is represented as a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.inotify_read (self._o)

    def inotify_files (self):
        """This function is a helpful wrapper around
        "g.inotify_read" which just returns a list of pathnames
        of objects that were touched. The returned pathnames are
        sorted and deduplicated.
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.inotify_files (self._o)

    def inotify_close (self):
        """This closes the inotify handle which was previously
        opened by inotify_init. It removes all watches, throws
        away any pending events, and deallocates all resources.
        """
        self._check_not_closed ()
        return libguestfsmod.inotify_close (self._o)

    def setcon (self, context):
        """This sets the SELinux security context of the daemon to
        the string "context".
        
        See the documentation about SELINUX in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.setcon (self._o, context)

    def getcon (self):
        """This gets the SELinux security context of the daemon.
        
        See the documentation about SELINUX in guestfs(3), and
        "g.setcon"
        """
        self._check_not_closed ()
        return libguestfsmod.getcon (self._o)

    def mkfs_b (self, fstype, blocksize, device):
        """This call is similar to "g.mkfs", but it allows you to
        control the block size of the resulting filesystem.
        Supported block sizes depend on the filesystem type, but
        typically they are 1024, 2048 or 4096 only.
        
        For VFAT and NTFS the "blocksize" parameter is treated
        as the requested cluster size.
        
        *This function is deprecated.* In new code, use the
        "mkfs_opts" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.mkfs_b (self._o, fstype, blocksize, device)

    def mke2journal (self, blocksize, device):
        """This creates an ext2 external journal on "device". It is
        equivalent to the command:
        
        mke2fs -O journal_dev -b blocksize device
        """
        self._check_not_closed ()
        return libguestfsmod.mke2journal (self._o, blocksize, device)

    def mke2journal_L (self, blocksize, label, device):
        """This creates an ext2 external journal on "device" with
        label "label".
        """
        self._check_not_closed ()
        return libguestfsmod.mke2journal_L (self._o, blocksize, label, device)

    def mke2journal_U (self, blocksize, uuid, device):
        """This creates an ext2 external journal on "device" with
        UUID "uuid".
        """
        self._check_not_closed ()
        return libguestfsmod.mke2journal_U (self._o, blocksize, uuid, device)

    def mke2fs_J (self, fstype, blocksize, device, journal):
        """This creates an ext2/3/4 filesystem on "device" with an
        external journal on "journal". It is equivalent to the
        command:
        
        mke2fs -t fstype -b blocksize -J device=<journal> <device>
        
        See also "g.mke2journal".
        """
        self._check_not_closed ()
        return libguestfsmod.mke2fs_J (self._o, fstype, blocksize, device, journal)

    def mke2fs_JL (self, fstype, blocksize, device, label):
        """This creates an ext2/3/4 filesystem on "device" with an
        external journal on the journal labeled "label".
        
        See also "g.mke2journal_L".
        """
        self._check_not_closed ()
        return libguestfsmod.mke2fs_JL (self._o, fstype, blocksize, device, label)

    def mke2fs_JU (self, fstype, blocksize, device, uuid):
        """This creates an ext2/3/4 filesystem on "device" with an
        external journal on the journal with UUID "uuid".
        
        See also "g.mke2journal_U".
        """
        self._check_not_closed ()
        return libguestfsmod.mke2fs_JU (self._o, fstype, blocksize, device, uuid)

    def modprobe (self, modulename):
        """This loads a kernel module in the appliance.
        
        The kernel module must have been whitelisted when
        libguestfs was built (see "appliance/kmod.whitelist.in"
        in the source).
        """
        self._check_not_closed ()
        return libguestfsmod.modprobe (self._o, modulename)

    def echo_daemon (self, words):
        """This command concatenates the list of "words" passed
        with single spaces between them and returns the
        resulting string.
        
        You can use this command to test the connection through
        to the daemon.
        
        See also "g.ping_daemon".
        """
        words = list (words)
        self._check_not_closed ()
        return libguestfsmod.echo_daemon (self._o, words)

    def find0 (self, directory, files):
        """This command lists out all files and directories,
        recursively, starting at "directory", placing the
        resulting list in the external file called "files".
        
        This command works the same way as "g.find" with the
        following exceptions:
        
        *   The resulting list is written to an external file.
        
        *   Items (filenames) in the result are separated by
        "\\0" characters. See find(1) option *-print0*.
        
        *   This command is not limited in the number of names
        that it can return.
        
        *   The result list is not sorted.
        """
        self._check_not_closed ()
        return libguestfsmod.find0 (self._o, directory, files)

    def case_sensitive_path (self, path):
        """This can be used to resolve case insensitive paths on a
        filesystem which is case sensitive. The use case is to
        resolve paths which you have read from Windows
        configuration files or the Windows Registry, to the true
        path.
        
        The command handles a peculiarity of the Linux ntfs-3g
        filesystem driver (and probably others), which is that
        although the underlying filesystem is case-insensitive,
        the driver exports the filesystem to Linux as
        case-sensitive.
        
        One consequence of this is that special directories such
        as "c:\\windows" may appear as "/WINDOWS" or "/windows"
        (or other things) depending on the precise details of
        how they were created. In Windows itself this would not
        be a problem.
        
        Bug or feature? You decide:
        <http://www.tuxera.com/community/ntfs-3g-faq/#posixfilen
        ames1>
        
        This function resolves the true case of each element in
        the path and returns the case-sensitive path.
        
        Thus "g.case_sensitive_path" ("/Windows/System32") might
        return "/WINDOWS/system32" (the exact return value would
        depend on details of how the directories were originally
        created under Windows).
        
        *Note*: This function does not handle drive names,
        backslashes etc.
        
        See also "g.realpath".
        """
        self._check_not_closed ()
        return libguestfsmod.case_sensitive_path (self._o, path)

    def vfs_type (self, device):
        """This command gets the filesystem type corresponding to
        the filesystem on "device".
        
        For most filesystems, the result is the name of the
        Linux VFS module which would be used to mount this
        filesystem if you mounted it without specifying the
        filesystem type. For example a string such as "ext3" or
        "ntfs".
        """
        self._check_not_closed ()
        return libguestfsmod.vfs_type (self._o, device)

    def truncate (self, path):
        """This command truncates "path" to a zero-length file. The
        file must exist already.
        """
        self._check_not_closed ()
        return libguestfsmod.truncate (self._o, path)

    def truncate_size (self, path, size):
        """This command truncates "path" to size "size" bytes. The
        file must exist already.
        
        If the current file size is less than "size" then the
        file is extended to the required size with zero bytes.
        This creates a sparse file (ie. disk blocks are not
        allocated for the file until you write to it). To create
        a non-sparse file of zeroes, use "g.fallocate64"
        instead.
        """
        self._check_not_closed ()
        return libguestfsmod.truncate_size (self._o, path, size)

    def utimens (self, path, atsecs, atnsecs, mtsecs, mtnsecs):
        """This command sets the timestamps of a file with
        nanosecond precision.
        
        "atsecs, atnsecs" are the last access time (atime) in
        secs and nanoseconds from the epoch.
        
        "mtsecs, mtnsecs" are the last modification time (mtime)
        in secs and nanoseconds from the epoch.
        
        If the *nsecs field contains the special value -1 then
        the corresponding timestamp is set to the current time.
        (The *secs field is ignored in this case).
        
        If the *nsecs field contains the special value -2 then
        the corresponding timestamp is left unchanged. (The
        *secs field is ignored in this case).
        """
        self._check_not_closed ()
        return libguestfsmod.utimens (self._o, path, atsecs, atnsecs, mtsecs, mtnsecs)

    def mkdir_mode (self, path, mode):
        """This command creates a directory, setting the initial
        permissions of the directory to "mode".
        
        For common Linux filesystems, the actual mode which is
        set will be "mode & ~umask & 01777". Non-native-Linux
        filesystems may interpret the mode in other ways.
        
        See also "g.mkdir", "g.umask"
        """
        self._check_not_closed ()
        return libguestfsmod.mkdir_mode (self._o, path, mode)

    def lchown (self, owner, group, path):
        """Change the file owner to "owner" and group to "group".
        This is like "g.chown" but if "path" is a symlink then
        the link itself is changed, not the target.
        
        Only numeric uid and gid are supported. If you want to
        use names, you will need to locate and parse the
        password file yourself (Augeas support makes this
        relatively easy).
        """
        self._check_not_closed ()
        return libguestfsmod.lchown (self._o, owner, group, path)

    def lstatlist (self, path, names):
        """This call allows you to perform the "g.lstat" operation
        on multiple files, where all files are in the directory
        "path". "names" is the list of files from this
        directory.
        
        On return you get a list of stat structs, with a
        one-to-one correspondence to the "names" list. If any
        name did not exist or could not be lstat'd, then the
        "ino" field of that structure is set to -1.
        
        This call is intended for programs that want to
        efficiently list a directory contents without making
        many round-trips. See also "g.lxattrlist" for a
        similarly efficient call for getting extended
        attributes. Very long directory listings might cause the
        protocol message size to be exceeded, causing this call
        to fail. The caller must split up such requests into
        smaller groups of names.
        
        This function returns a list of stats. Each stat is
        represented as a dictionary.
        """
        names = list (names)
        self._check_not_closed ()
        return libguestfsmod.lstatlist (self._o, path, names)

    def lxattrlist (self, path, names):
        """This call allows you to get the extended attributes of
        multiple files, where all files are in the directory
        "path". "names" is the list of files from this
        directory.
        
        On return you get a flat list of xattr structs which
        must be interpreted sequentially. The first xattr struct
        always has a zero-length "attrname". "attrval" in this
        struct is zero-length to indicate there was an error
        doing "lgetxattr" for this file, *or* is a C string
        which is a decimal number (the number of following
        attributes for this file, which could be "0"). Then
        after the first xattr struct are the zero or more
        attributes for the first named file. This repeats for
        the second and subsequent files.
        
        This call is intended for programs that want to
        efficiently list a directory contents without making
        many round-trips. See also "g.lstatlist" for a similarly
        efficient call for getting standard stats. Very long
        directory listings might cause the protocol message size
        to be exceeded, causing this call to fail. The caller
        must split up such requests into smaller groups of
        names.
        
        This function returns a list of xattrs. Each xattr is
        represented as a dictionary.
        """
        names = list (names)
        self._check_not_closed ()
        return libguestfsmod.lxattrlist (self._o, path, names)

    def readlinklist (self, path, names):
        """This call allows you to do a "readlink" operation on
        multiple files, where all files are in the directory
        "path". "names" is the list of files from this
        directory.
        
        On return you get a list of strings, with a one-to-one
        correspondence to the "names" list. Each string is the
        value of the symbolic link.
        
        If the readlink(2) operation fails on any name, then the
        corresponding result string is the empty string "".
        However the whole operation is completed even if there
        were readlink(2) errors, and so you can call this
        function with names where you don't know if they are
        symbolic links already (albeit slightly less efficient).
        
        This call is intended for programs that want to
        efficiently list a directory contents without making
        many round-trips. Very long directory listings might
        cause the protocol message size to be exceeded, causing
        this call to fail. The caller must split up such
        requests into smaller groups of names.
        
        This function returns a list of strings.
        """
        names = list (names)
        self._check_not_closed ()
        return libguestfsmod.readlinklist (self._o, path, names)

    def pread (self, path, count, offset):
        """This command lets you read part of a file. It reads
        "count" bytes of the file, starting at "offset", from
        file "path".
        
        This may read fewer bytes than requested. For further
        details see the pread(2) system call.
        
        See also "g.pwrite", "g.pread_device".
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.pread (self._o, path, count, offset)

    def part_init (self, device, parttype):
        """This creates an empty partition table on "device" of one
        of the partition types listed below. Usually "parttype"
        should be either "msdos" or "gpt" (for large disks).
        
        Initially there are no partitions. Following this, you
        should call "g.part_add" for each partition required.
        
        Possible values for "parttype" are:
        
        efi
        gpt Intel EFI / GPT partition table.
        
        This is recommended for >= 2 TB partitions that will
        be accessed from Linux and Intel-based Mac OS X. It
        also has limited backwards compatibility with the
        "mbr" format.
        
        mbr
        msdos
        The standard PC "Master Boot Record" (MBR) format
        used by MS-DOS and Windows. This partition type will
        only work for device sizes up to 2 TB. For large
        disks we recommend using "gpt".
        
        Other partition table types that may work but are not
        supported include:
        
        aix AIX disk labels.
        
        amiga
        rdb Amiga "Rigid Disk Block" format.
        
        bsd BSD disk labels.
        
        dasd
        DASD, used on IBM mainframes.
        
        dvh MIPS/SGI volumes.
        
        mac Old Mac partition format. Modern Macs use "gpt".
        
        pc98
        NEC PC-98 format, common in Japan apparently.
        
        sun Sun disk labels.
        """
        self._check_not_closed ()
        return libguestfsmod.part_init (self._o, device, parttype)

    def part_add (self, device, prlogex, startsect, endsect):
        """This command adds a partition to "device". If there is
        no partition table on the device, call "g.part_init"
        first.
        
        The "prlogex" parameter is the type of partition.
        Normally you should pass "p" or "primary" here, but MBR
        partition tables also support "l" (or "logical") and "e"
        (or "extended") partition types.
        
        "startsect" and "endsect" are the start and end of the
        partition in *sectors*. "endsect" may be negative, which
        means it counts backwards from the end of the disk (-1
        is the last sector).
        
        Creating a partition which covers the whole disk is not
        so easy. Use "g.part_disk" to do that.
        """
        self._check_not_closed ()
        return libguestfsmod.part_add (self._o, device, prlogex, startsect, endsect)

    def part_disk (self, device, parttype):
        """This command is simply a combination of "g.part_init"
        followed by "g.part_add" to create a single primary
        partition covering the whole disk.
        
        "parttype" is the partition table type, usually "mbr" or
        "gpt", but other possible values are described in
        "g.part_init".
        """
        self._check_not_closed ()
        return libguestfsmod.part_disk (self._o, device, parttype)

    def part_set_bootable (self, device, partnum, bootable):
        """This sets the bootable flag on partition numbered
        "partnum" on device "device". Note that partitions are
        numbered from 1.
        
        The bootable flag is used by some operating systems
        (notably Windows) to determine which partition to boot
        from. It is by no means universally recognized.
        """
        self._check_not_closed ()
        return libguestfsmod.part_set_bootable (self._o, device, partnum, bootable)

    def part_set_name (self, device, partnum, name):
        """This sets the partition name on partition numbered
        "partnum" on device "device". Note that partitions are
        numbered from 1.
        
        The partition name can only be set on certain types of
        partition table. This works on "gpt" but not on "mbr"
        partitions.
        """
        self._check_not_closed ()
        return libguestfsmod.part_set_name (self._o, device, partnum, name)

    def part_list (self, device):
        """This command parses the partition table on "device" and
        returns the list of partitions found.
        
        The fields in the returned structure are:
        
        part_num
        Partition number, counting from 1.
        
        part_start
        Start of the partition *in bytes*. To get sectors
        you have to divide by the device's sector size, see
        "g.blockdev_getss".
        
        part_end
        End of the partition in bytes.
        
        part_size
        Size of the partition in bytes.
        
        This function returns a list of partitions. Each
        partition is represented as a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.part_list (self._o, device)

    def part_get_parttype (self, device):
        """This command examines the partition table on "device"
        and returns the partition table type (format) being
        used.
        
        Common return values include: "msdos" (a DOS/Windows
        style MBR partition table), "gpt" (a GPT/EFI-style
        partition table). Other values are possible, although
        unusual. See "g.part_init" for a full list.
        """
        self._check_not_closed ()
        return libguestfsmod.part_get_parttype (self._o, device)

    def fill (self, c, len, path):
        """This command creates a new file called "path". The
        initial content of the file is "len" octets of "c",
        where "c" must be a number in the range "[0..255]".
        
        To fill a file with zero bytes (sparsely), it is much
        more efficient to use "g.truncate_size". To create a
        file with a pattern of repeating bytes use
        "g.fill_pattern".
        """
        self._check_not_closed ()
        return libguestfsmod.fill (self._o, c, len, path)

    def available (self, groups):
        """This command is used to check the availability of some
        groups of functionality in the appliance, which not all
        builds of the libguestfs appliance will be able to
        provide.
        
        The libguestfs groups, and the functions that those
        groups correspond to, are listed in "AVAILABILITY" in
        guestfs(3). You can also fetch this list at runtime by
        calling "g.available_all_groups".
        
        The argument "groups" is a list of group names, eg:
        "["inotify", "augeas"]" would check for the availability
        of the Linux inotify functions and Augeas (configuration
        file editing) functions.
        
        The command returns no error if *all* requested groups
        are available.
        
        It fails with an error if one or more of the requested
        groups is unavailable in the appliance.
        
        If an unknown group name is included in the list of
        groups then an error is always returned.
        
        *Notes:*
        
        *   You must call "g.launch" before calling this
        function.
        
        The reason is because we don't know what groups are
        supported by the appliance/daemon until it is
        running and can be queried.
        
        *   If a group of functions is available, this does not
        necessarily mean that they will work. You still have
        to check for errors when calling individual API
        functions even if they are available.
        
        *   It is usually the job of distro packagers to build
        complete functionality into the libguestfs
        appliance. Upstream libguestfs, if built from source
        with all requirements satisfied, will support
        everything.
        
        *   This call was added in version 1.0.80. In previous
        versions of libguestfs all you could do would be to
        speculatively execute a command to find out if the
        daemon implemented it. See also "g.version".
        """
        groups = list (groups)
        self._check_not_closed ()
        return libguestfsmod.available (self._o, groups)

    def dd (self, src, dest):
        """This command copies from one source device or file "src"
        to another destination device or file "dest". Normally
        you would use this to copy to or from a device or
        partition, for example to duplicate a filesystem.
        
        If the destination is a device, it must be as large or
        larger than the source file or device, otherwise the
        copy will fail. This command cannot do partial copies
        (see "g.copy_device_to_device").
        
        *This function is deprecated.* In new code, use the
        "copy_device_to_device" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.dd (self._o, src, dest)

    def filesize (self, file):
        """This command returns the size of "file" in bytes.
        
        To get other stats about a file, use "g.stat",
        "g.lstat", "g.is_dir", "g.is_file" etc. To get the size
        of block devices, use "g.blockdev_getsize64".
        """
        self._check_not_closed ()
        return libguestfsmod.filesize (self._o, file)

    def lvrename (self, logvol, newlogvol):
        """Rename a logical volume "logvol" with the new name
        "newlogvol".
        """
        self._check_not_closed ()
        return libguestfsmod.lvrename (self._o, logvol, newlogvol)

    def vgrename (self, volgroup, newvolgroup):
        """Rename a volume group "volgroup" with the new name
        "newvolgroup".
        """
        self._check_not_closed ()
        return libguestfsmod.vgrename (self._o, volgroup, newvolgroup)

    def initrd_cat (self, initrdpath, filename):
        """This command unpacks the file "filename" from the initrd
        file called "initrdpath". The filename must be given
        *without* the initial "/" character.
        
        For example, in guestfish you could use the following
        command to examine the boot script (usually called
        "/init") contained in a Linux initrd or initramfs image:
        
        initrd-cat /boot/initrd-<version>.img init
        
        See also "g.initrd_list".
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.initrd_cat (self._o, initrdpath, filename)

    def pvuuid (self, device):
        """This command returns the UUID of the LVM PV "device".
        """
        self._check_not_closed ()
        return libguestfsmod.pvuuid (self._o, device)

    def vguuid (self, vgname):
        """This command returns the UUID of the LVM VG named
        "vgname".
        """
        self._check_not_closed ()
        return libguestfsmod.vguuid (self._o, vgname)

    def lvuuid (self, device):
        """This command returns the UUID of the LVM LV "device".
        """
        self._check_not_closed ()
        return libguestfsmod.lvuuid (self._o, device)

    def vgpvuuids (self, vgname):
        """Given a VG called "vgname", this returns the UUIDs of
        all the physical volumes that this volume group resides
        on.
        
        You can use this along with "g.pvs" and "g.pvuuid" calls
        to associate physical volumes and volume groups.
        
        See also "g.vglvuuids".
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.vgpvuuids (self._o, vgname)

    def vglvuuids (self, vgname):
        """Given a VG called "vgname", this returns the UUIDs of
        all the logical volumes created in this volume group.
        
        You can use this along with "g.lvs" and "g.lvuuid" calls
        to associate logical volumes and volume groups.
        
        See also "g.vgpvuuids".
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.vglvuuids (self._o, vgname)

    def copy_size (self, src, dest, size):
        """This command copies exactly "size" bytes from one source
        device or file "src" to another destination device or
        file "dest".
        
        Note this will fail if the source is too short or if the
        destination is not large enough.
        
        *This function is deprecated.* In new code, use the
        "copy_device_to_device" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.copy_size (self._o, src, dest, size)

    def zero_device (self, device):
        """This command writes zeroes over the entire "device".
        Compare with "g.zero" which just zeroes the first few
        blocks of a device.
        
        If blocks are already zero, then this command avoids
        writing zeroes. This prevents the underlying device from
        becoming non-sparse or growing unnecessarily.
        """
        self._check_not_closed ()
        return libguestfsmod.zero_device (self._o, device)

    def txz_in (self, tarball, directory):
        """This command uploads and unpacks local file "tarball"
        (an *xz compressed* tar file) into "directory".
        """
        self._check_not_closed ()
        return libguestfsmod.txz_in (self._o, tarball, directory)

    def txz_out (self, directory, tarball):
        """This command packs the contents of "directory" and
        downloads it to local file "tarball" (as an xz
        compressed tar archive).
        """
        self._check_not_closed ()
        return libguestfsmod.txz_out (self._o, directory, tarball)

    def ntfsresize (self, device):
        """This command resizes an NTFS filesystem, expanding or
        shrinking it to the size of the underlying device.
        
        *Note:* After the resize operation, the filesystem is
        marked as requiring a consistency check (for safety).
        You have to boot into Windows to perform this check and
        clear this condition. Furthermore, ntfsresize refuses to
        resize filesystems which have been marked in this way.
        So in effect it is not possible to call ntfsresize
        multiple times on a single filesystem without booting
        into Windows between each resize.
        
        See also ntfsresize(8).
        
        *This function is deprecated.* In new code, use the
        "ntfsresize_opts" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.ntfsresize (self._o, device)

    def vgscan (self):
        """This rescans all block devices and rebuilds the list of
        LVM physical volumes, volume groups and logical volumes.
        """
        self._check_not_closed ()
        return libguestfsmod.vgscan (self._o)

    def part_del (self, device, partnum):
        """This command deletes the partition numbered "partnum" on
        "device".
        
        Note that in the case of MBR partitioning, deleting an
        extended partition also deletes any logical partitions
        it contains.
        """
        self._check_not_closed ()
        return libguestfsmod.part_del (self._o, device, partnum)

    def part_get_bootable (self, device, partnum):
        """This command returns true if the partition "partnum" on
        "device" has the bootable flag set.
        
        See also "g.part_set_bootable".
        """
        self._check_not_closed ()
        return libguestfsmod.part_get_bootable (self._o, device, partnum)

    def part_get_mbr_id (self, device, partnum):
        """Returns the MBR type byte (also known as the ID byte)
        from the numbered partition "partnum".
        
        Note that only MBR (old DOS-style) partitions have type
        bytes. You will get undefined results for other
        partition table types (see "g.part_get_parttype").
        """
        self._check_not_closed ()
        return libguestfsmod.part_get_mbr_id (self._o, device, partnum)

    def part_set_mbr_id (self, device, partnum, idbyte):
        """Sets the MBR type byte (also known as the ID byte) of
        the numbered partition "partnum" to "idbyte". Note that
        the type bytes quoted in most documentation are in fact
        hexadecimal numbers, but usually documented without any
        leading "0x" which might be confusing.
        
        Note that only MBR (old DOS-style) partitions have type
        bytes. You will get undefined results for other
        partition table types (see "g.part_get_parttype").
        """
        self._check_not_closed ()
        return libguestfsmod.part_set_mbr_id (self._o, device, partnum, idbyte)

    def checksum_device (self, csumtype, device):
        """This call computes the MD5, SHAx or CRC checksum of the
        contents of the device named "device". For the types of
        checksums supported see the "g.checksum" command.
        """
        self._check_not_closed ()
        return libguestfsmod.checksum_device (self._o, csumtype, device)

    def lvresize_free (self, lv, percent):
        """This expands an existing logical volume "lv" so that it
        fills "pc"% of the remaining free space in the volume
        group. Commonly you would call this with pc = 100 which
        expands the logical volume as much as possible, using
        all remaining free space in the volume group.
        """
        self._check_not_closed ()
        return libguestfsmod.lvresize_free (self._o, lv, percent)

    def aug_clear (self, augpath):
        """Set the value associated with "path" to "NULL". This is
        the same as the augtool(1) "clear" command.
        """
        self._check_not_closed ()
        return libguestfsmod.aug_clear (self._o, augpath)

    def get_umask (self):
        """Return the current umask. By default the umask is 022
        unless it has been set by calling "g.umask".
        """
        self._check_not_closed ()
        return libguestfsmod.get_umask (self._o)

    def debug_upload (self, filename, tmpname, mode):
        self._check_not_closed ()
        return libguestfsmod.debug_upload (self._o, filename, tmpname, mode)

    def base64_in (self, base64file, filename):
        """This command uploads base64-encoded data from
        "base64file" to "filename".
        """
        self._check_not_closed ()
        return libguestfsmod.base64_in (self._o, base64file, filename)

    def base64_out (self, filename, base64file):
        """This command downloads the contents of "filename",
        writing it out to local file "base64file" encoded as
        base64.
        """
        self._check_not_closed ()
        return libguestfsmod.base64_out (self._o, filename, base64file)

    def checksums_out (self, csumtype, directory, sumsfile):
        """This command computes the checksums of all regular files
        in "directory" and then emits a list of those checksums
        to the local output file "sumsfile".
        
        This can be used for verifying the integrity of a
        virtual machine. However to be properly secure you
        should pay attention to the output of the checksum
        command (it uses the ones from GNU coreutils). In
        particular when the filename is not printable, coreutils
        uses a special backslash syntax. For more information,
        see the GNU coreutils info file.
        """
        self._check_not_closed ()
        return libguestfsmod.checksums_out (self._o, csumtype, directory, sumsfile)

    def fill_pattern (self, pattern, len, path):
        """This function is like "g.fill" except that it creates a
        new file of length "len" containing the repeating
        pattern of bytes in "pattern". The pattern is truncated
        if necessary to ensure the length of the file is exactly
        "len" bytes.
        """
        self._check_not_closed ()
        return libguestfsmod.fill_pattern (self._o, pattern, len, path)

    def write (self, path, content):
        """This call creates a file called "path". The content of
        the file is the string "content" (which can contain any
        8 bit data).
        
        See also "g.write_append".
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.write (self._o, path, content)

    def pwrite (self, path, content, offset):
        """This command writes to part of a file. It writes the
        data buffer "content" to the file "path" starting at
        offset "offset".
        
        This command implements the pwrite(2) system call, and
        like that system call it may not write the full data
        requested. The return value is the number of bytes that
        were actually written to the file. This could even be 0,
        although short writes are unlikely for regular files in
        ordinary circumstances.
        
        See also "g.pread", "g.pwrite_device".
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.pwrite (self._o, path, content, offset)

    def resize2fs_size (self, device, size):
        """This command is the same as "g.resize2fs" except that it
        allows you to specify the new size (in bytes)
        explicitly.
        
        See also "RESIZE2FS ERRORS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.resize2fs_size (self._o, device, size)

    def pvresize_size (self, device, size):
        """This command is the same as "g.pvresize" except that it
        allows you to specify the new size (in bytes)
        explicitly.
        """
        self._check_not_closed ()
        return libguestfsmod.pvresize_size (self._o, device, size)

    def ntfsresize_size (self, device, size):
        """This command is the same as "g.ntfsresize" except that
        it allows you to specify the new size (in bytes)
        explicitly.
        
        *This function is deprecated.* In new code, use the
        "ntfsresize_opts" call instead.
        
        Deprecated functions will not be removed from the API,
        but the fact that they are deprecated indicates that
        there are problems with correct use of these functions.
        """
        self._check_not_closed ()
        return libguestfsmod.ntfsresize_size (self._o, device, size)

    def available_all_groups (self):
        """This command returns a list of all optional groups that
        this daemon knows about. Note this returns both
        supported and unsupported groups. To find out which ones
        the daemon can actually support you have to call
        "g.available" on each member of the returned list.
        
        See also "g.available" and "AVAILABILITY" in guestfs(3).
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.available_all_groups (self._o)

    def fallocate64 (self, path, len):
        """This command preallocates a file (containing zero bytes)
        named "path" of size "len" bytes. If the file exists
        already, it is overwritten.
        
        Note that this call allocates disk blocks for the file.
        To create a sparse file use "g.truncate_size" instead.
        
        The deprecated call "g.fallocate" does the same, but
        owing to an oversight it only allowed 30 bit lengths to
        be specified, effectively limiting the maximum size of
        files created through that call to 1GB.
        
        Do not confuse this with the guestfish-specific "alloc"
        and "sparse" commands which create a file in the host
        and attach it as a device.
        """
        self._check_not_closed ()
        return libguestfsmod.fallocate64 (self._o, path, len)

    def vfs_label (self, device):
        """This returns the filesystem label of the filesystem on
        "device".
        
        If the filesystem is unlabeled, this returns the empty
        string.
        
        To find a filesystem from the label, use
        "g.findfs_label".
        """
        self._check_not_closed ()
        return libguestfsmod.vfs_label (self._o, device)

    def vfs_uuid (self, device):
        """This returns the filesystem UUID of the filesystem on
        "device".
        
        If the filesystem does not have a UUID, this returns the
        empty string.
        
        To find a filesystem from the UUID, use "g.findfs_uuid".
        """
        self._check_not_closed ()
        return libguestfsmod.vfs_uuid (self._o, device)

    def lvm_set_filter (self, devices):
        """This sets the LVM device filter so that LVM will only be
        able to "see" the block devices in the list "devices",
        and will ignore all other attached block devices.
        
        Where disk image(s) contain duplicate PVs or VGs, this
        command is useful to get LVM to ignore the duplicates,
        otherwise LVM can get confused. Note also there are two
        types of duplication possible: either cloned PVs/VGs
        which have identical UUIDs; or VGs that are not cloned
        but just happen to have the same name. In normal
        operation you cannot create this situation, but you can
        do it outside LVM, eg. by cloning disk images or by bit
        twiddling inside the LVM metadata.
        
        This command also clears the LVM cache and performs a
        volume group scan.
        
        You can filter whole block devices or individual
        partitions.
        
        You cannot use this if any VG is currently in use (eg.
        contains a mounted filesystem), even if you are not
        filtering out that VG.
        """
        devices = list (devices)
        self._check_not_closed ()
        return libguestfsmod.lvm_set_filter (self._o, devices)

    def lvm_clear_filter (self):
        """This undoes the effect of "g.lvm_set_filter". LVM will
        be able to see every block device.
        
        This command also clears the LVM cache and performs a
        volume group scan.
        """
        self._check_not_closed ()
        return libguestfsmod.lvm_clear_filter (self._o)

    def luks_open (self, device, key, mapname):
        """This command opens a block device which has been
        encrypted according to the Linux Unified Key Setup
        (LUKS) standard.
        
        "device" is the encrypted block device or partition.
        
        The caller must supply one of the keys associated with
        the LUKS block device, in the "key" parameter.
        
        This creates a new block device called
        "/dev/mapper/mapname". Reads and writes to this block
        device are decrypted from and encrypted to the
        underlying "device" respectively.
        
        If this block device contains LVM volume groups, then
        calling "g.vgscan" followed by "g.vg_activate_all" will
        make them visible.
        
        Use "g.list_dm_devices" to list all device mapper
        devices.
        """
        self._check_not_closed ()
        return libguestfsmod.luks_open (self._o, device, key, mapname)

    def luks_open_ro (self, device, key, mapname):
        """This is the same as "g.luks_open" except that a
        read-only mapping is created.
        """
        self._check_not_closed ()
        return libguestfsmod.luks_open_ro (self._o, device, key, mapname)

    def luks_close (self, device):
        """This closes a LUKS device that was created earlier by
        "g.luks_open" or "g.luks_open_ro". The "device"
        parameter must be the name of the LUKS mapping device
        (ie. "/dev/mapper/mapname") and *not* the name of the
        underlying block device.
        """
        self._check_not_closed ()
        return libguestfsmod.luks_close (self._o, device)

    def luks_format (self, device, key, keyslot):
        """This command erases existing data on "device" and
        formats the device as a LUKS encrypted device. "key" is
        the initial key, which is added to key slot "slot".
        (LUKS supports 8 key slots, numbered 0-7).
        """
        self._check_not_closed ()
        return libguestfsmod.luks_format (self._o, device, key, keyslot)

    def luks_format_cipher (self, device, key, keyslot, cipher):
        """This command is the same as "g.luks_format" but it also
        allows you to set the "cipher" used.
        """
        self._check_not_closed ()
        return libguestfsmod.luks_format_cipher (self._o, device, key, keyslot, cipher)

    def luks_add_key (self, device, key, newkey, keyslot):
        """This command adds a new key on LUKS device "device".
        "key" is any existing key, and is used to access the
        device. "newkey" is the new key to add. "keyslot" is the
        key slot that will be replaced.
        
        Note that if "keyslot" already contains a key, then this
        command will fail. You have to use "g.luks_kill_slot"
        first to remove that key.
        """
        self._check_not_closed ()
        return libguestfsmod.luks_add_key (self._o, device, key, newkey, keyslot)

    def luks_kill_slot (self, device, key, keyslot):
        """This command deletes the key in key slot "keyslot" from
        the encrypted LUKS device "device". "key" must be one of
        the *other* keys.
        """
        self._check_not_closed ()
        return libguestfsmod.luks_kill_slot (self._o, device, key, keyslot)

    def is_lv (self, device):
        """This command tests whether "device" is a logical volume,
        and returns true iff this is the case.
        """
        self._check_not_closed ()
        return libguestfsmod.is_lv (self._o, device)

    def findfs_uuid (self, uuid):
        """This command searches the filesystems and returns the
        one which has the given UUID. An error is returned if no
        such filesystem can be found.
        
        To find the UUID of a filesystem, use "g.vfs_uuid".
        """
        self._check_not_closed ()
        return libguestfsmod.findfs_uuid (self._o, uuid)

    def findfs_label (self, label):
        """This command searches the filesystems and returns the
        one which has the given label. An error is returned if
        no such filesystem can be found.
        
        To find the label of a filesystem, use "g.vfs_label".
        """
        self._check_not_closed ()
        return libguestfsmod.findfs_label (self._o, label)

    def is_chardev (self, path):
        """This returns "true" if and only if there is a character
        device with the given "path" name.
        
        See also "g.stat".
        """
        self._check_not_closed ()
        return libguestfsmod.is_chardev (self._o, path)

    def is_blockdev (self, path):
        """This returns "true" if and only if there is a block
        device with the given "path" name.
        
        See also "g.stat".
        """
        self._check_not_closed ()
        return libguestfsmod.is_blockdev (self._o, path)

    def is_fifo (self, path):
        """This returns "true" if and only if there is a FIFO
        (named pipe) with the given "path" name.
        
        See also "g.stat".
        """
        self._check_not_closed ()
        return libguestfsmod.is_fifo (self._o, path)

    def is_symlink (self, path):
        """This returns "true" if and only if there is a symbolic
        link with the given "path" name.
        
        See also "g.stat".
        """
        self._check_not_closed ()
        return libguestfsmod.is_symlink (self._o, path)

    def is_socket (self, path):
        """This returns "true" if and only if there is a Unix
        domain socket with the given "path" name.
        
        See also "g.stat".
        """
        self._check_not_closed ()
        return libguestfsmod.is_socket (self._o, path)

    def part_to_dev (self, partition):
        """This function takes a partition name (eg. "/dev/sdb1")
        and removes the partition number, returning the device
        name (eg. "/dev/sdb").
        
        The named partition must exist, for example as a string
        returned from "g.list_partitions".
        
        See also "g.part_to_partnum", "g.device_index".
        """
        self._check_not_closed ()
        return libguestfsmod.part_to_dev (self._o, partition)

    def upload_offset (self, filename, remotefilename, offset):
        """Upload local file "filename" to "remotefilename" on the
        filesystem.
        
        "remotefilename" is overwritten starting at the byte
        "offset" specified. The intention is to overwrite parts
        of existing files or devices, although if a non-existant
        file is specified then it is created with a "hole"
        before "offset". The size of the data written is
        implicit in the size of the source "filename".
        
        Note that there is no limit on the amount of data that
        can be uploaded with this call, unlike with "g.pwrite",
        and this call always writes the full amount unless an
        error occurs.
        
        See also "g.upload", "g.pwrite".
        """
        self._check_not_closed ()
        return libguestfsmod.upload_offset (self._o, filename, remotefilename, offset)

    def download_offset (self, remotefilename, filename, offset, size):
        """Download file "remotefilename" and save it as "filename"
        on the local machine.
        
        "remotefilename" is read for "size" bytes starting at
        "offset" (this region must be within the file or
        device).
        
        Note that there is no limit on the amount of data that
        can be downloaded with this call, unlike with "g.pread",
        and this call always reads the full amount unless an
        error occurs.
        
        See also "g.download", "g.pread".
        """
        self._check_not_closed ()
        return libguestfsmod.download_offset (self._o, remotefilename, filename, offset, size)

    def pwrite_device (self, device, content, offset):
        """This command writes to part of a device. It writes the
        data buffer "content" to "device" starting at offset
        "offset".
        
        This command implements the pwrite(2) system call, and
        like that system call it may not write the full data
        requested (although short writes to disk devices and
        partitions are probably impossible with standard Linux
        kernels).
        
        See also "g.pwrite".
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.pwrite_device (self._o, device, content, offset)

    def pread_device (self, device, count, offset):
        """This command lets you read part of a file. It reads
        "count" bytes of "device", starting at "offset".
        
        This may read fewer bytes than requested. For further
        details see the pread(2) system call.
        
        See also "g.pread".
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.pread_device (self._o, device, count, offset)

    def lvm_canonical_lv_name (self, lvname):
        """This converts alternative naming schemes for LVs that
        you might find to the canonical name. For example,
        "/dev/mapper/VG-LV" is converted to "/dev/VG/LV".
        
        This command returns an error if the "lvname" parameter
        does not refer to a logical volume.
        
        See also "g.is_lv".
        """
        self._check_not_closed ()
        return libguestfsmod.lvm_canonical_lv_name (self._o, lvname)

    def mkfs_opts (self, fstype, device, blocksize=-1, features=None, inode=-1, sectorsize=-1):
        """This function creates a filesystem on "device". The
        filesystem type is "fstype", for example "ext3".
        
        The optional arguments are:
        
        "blocksize"
        The filesystem block size. Supported block sizes
        depend on the filesystem type, but typically they
        are 1024, 2048 or 4096 for Linux ext2/3 filesystems.
        
        For VFAT and NTFS the "blocksize" parameter is
        treated as the requested cluster size.
        
        For UFS block sizes, please see mkfs.ufs(8).
        
        "features"
        This passes the *-O* parameter to the external mkfs
        program.
        
        For certain filesystem types, this allows extra
        filesystem features to be selected. See mke2fs(8)
        and mkfs.ufs(8) for more details.
        
        You cannot use this optional parameter with the
        "gfs" or "gfs2" filesystem type.
        
        "inode"
        This passes the *-I* parameter to the external
        mke2fs(8) program which sets the inode size (only
        for ext2/3/4 filesystems at present).
        
        "sectorsize"
        This passes the *-S* parameter to external
        mkfs.ufs(8) program, which sets sector size for ufs
        filesystem.
        """
        self._check_not_closed ()
        return libguestfsmod.mkfs_opts (self._o, fstype, device, blocksize, features, inode, sectorsize)

    def getxattr (self, path, name):
        """Get a single extended attribute from file "path" named
        "name". This call follows symlinks. If you want to
        lookup an extended attribute for the symlink itself, use
        "g.lgetxattr".
        
        Normally it is better to get all extended attributes
        from a file in one go by calling "g.getxattrs". However
        some Linux filesystem implementations are buggy and do
        not provide a way to list out attributes. For these
        filesystems (notably ntfs-3g) you have to know the names
        of the extended attributes you want in advance and call
        this function.
        
        Extended attribute values are blobs of binary data. If
        there is no extended attribute named "name", this
        returns an error.
        
        See also: "g.getxattrs", "g.lgetxattr", attr(5).
        """
        self._check_not_closed ()
        return libguestfsmod.getxattr (self._o, path, name)

    def lgetxattr (self, path, name):
        """Get a single extended attribute from file "path" named
        "name". If "path" is a symlink, then this call returns
        an extended attribute from the symlink.
        
        Normally it is better to get all extended attributes
        from a file in one go by calling "g.getxattrs". However
        some Linux filesystem implementations are buggy and do
        not provide a way to list out attributes. For these
        filesystems (notably ntfs-3g) you have to know the names
        of the extended attributes you want in advance and call
        this function.
        
        Extended attribute values are blobs of binary data. If
        there is no extended attribute named "name", this
        returns an error.
        
        See also: "g.lgetxattrs", "g.getxattr", attr(5).
        """
        self._check_not_closed ()
        return libguestfsmod.lgetxattr (self._o, path, name)

    def resize2fs_M (self, device):
        """This command is the same as "g.resize2fs", but the
        filesystem is resized to its minimum size. This works
        like the *-M* option to the "resize2fs" command.
        
        To get the resulting size of the filesystem you should
        call "g.tune2fs_l" and read the "Block size" and "Block
        count" values. These two numbers, multiplied together,
        give the resulting size of the minimal filesystem in
        bytes.
        
        See also "RESIZE2FS ERRORS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.resize2fs_M (self._o, device)

    def internal_autosync (self):
        self._check_not_closed ()
        return libguestfsmod.internal_autosync (self._o)

    def is_zero (self, path):
        """This returns true iff the file exists and the file is
        empty or it contains all zero bytes.
        """
        self._check_not_closed ()
        return libguestfsmod.is_zero (self._o, path)

    def is_zero_device (self, device):
        """This returns true iff the device exists and contains all
        zero bytes.
        
        Note that for large devices this can take a long time to
        run.
        """
        self._check_not_closed ()
        return libguestfsmod.is_zero_device (self._o, device)

    def list_9p (self):
        """List all 9p filesystems attached to the guest. A list of
        mount tags is returned.
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.list_9p (self._o)

    def mount_9p (self, mounttag, mountpoint, options=None):
        """Mount the virtio-9p filesystem with the tag "mounttag"
        on the directory "mountpoint".
        
        If required, "trans=virtio" will be automatically added
        to the options. Any other options required can be passed
        in the optional "options" parameter.
        """
        self._check_not_closed ()
        return libguestfsmod.mount_9p (self._o, mounttag, mountpoint, options)

    def list_dm_devices (self):
        """List all device mapper devices.
        
        The returned list contains "/dev/mapper/*" devices, eg.
        ones created by a previous call to "g.luks_open".
        
        Device mapper devices which correspond to logical
        volumes are *not* returned in this list. Call "g.lvs" if
        you want to list logical volumes.
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.list_dm_devices (self._o)

    def ntfsresize_opts (self, device, size=-1, force=-1):
        """This command resizes an NTFS filesystem, expanding or
        shrinking it to the size of the underlying device.
        
        The optional parameters are:
        
        "size"
        The new size (in bytes) of the filesystem. If
        omitted, the filesystem is resized to fit the
        container (eg. partition).
        
        "force"
        If this option is true, then force the resize of the
        filesystem even if the filesystem is marked as
        requiring a consistency check.
        
        After the resize operation, the filesystem is always
        marked as requiring a consistency check (for
        safety). You have to boot into Windows to perform
        this check and clear this condition. If you *don't*
        set the "force" option then it is not possible to
        call "g.ntfsresize_opts" multiple times on a single
        filesystem without booting into Windows between each
        resize.
        
        See also ntfsresize(8).
        """
        self._check_not_closed ()
        return libguestfsmod.ntfsresize_opts (self._o, device, size, force)

    def btrfs_filesystem_resize (self, mountpoint, size=-1):
        """This command resizes a btrfs filesystem.
        
        Note that unlike other resize calls, the filesystem has
        to be mounted and the parameter is the mountpoint not
        the device (this is a requirement of btrfs itself).
        
        The optional parameters are:
        
        "size"
        The new size (in bytes) of the filesystem. If
        omitted, the filesystem is resized to the maximum
        size.
        
        See also btrfs(8).
        """
        self._check_not_closed ()
        return libguestfsmod.btrfs_filesystem_resize (self._o, mountpoint, size)

    def write_append (self, path, content):
        """This call appends "content" to the end of file "path".
        If "path" does not exist, then a new file is created.
        
        See also "g.write".
        
        Because of the message protocol, there is a transfer
        limit of somewhere between 2MB and 4MB. See "PROTOCOL
        LIMITS" in guestfs(3).
        """
        self._check_not_closed ()
        return libguestfsmod.write_append (self._o, path, content)

    def compress_out (self, ctype, file, zfile, level=-1):
        """This command compresses "file" and writes it out to the
        local file "zfile".
        
        The compression program used is controlled by the
        "ctype" parameter. Currently this includes: "compress",
        "gzip", "bzip2", "xz" or "lzop". Some compression types
        may not be supported by particular builds of libguestfs,
        in which case you will get an error containing the
        substring "not supported".
        
        The optional "level" parameter controls compression
        level. The meaning and default for this parameter
        depends on the compression program being used.
        """
        self._check_not_closed ()
        return libguestfsmod.compress_out (self._o, ctype, file, zfile, level)

    def compress_device_out (self, ctype, device, zdevice, level=-1):
        """This command compresses "device" and writes it out to
        the local file "zdevice".
        
        The "ctype" and optional "level" parameters have the
        same meaning as in "g.compress_out".
        """
        self._check_not_closed ()
        return libguestfsmod.compress_device_out (self._o, ctype, device, zdevice, level)

    def part_to_partnum (self, partition):
        """This function takes a partition name (eg. "/dev/sdb1")
        and returns the partition number (eg. 1).
        
        The named partition must exist, for example as a string
        returned from "g.list_partitions".
        
        See also "g.part_to_dev".
        """
        self._check_not_closed ()
        return libguestfsmod.part_to_partnum (self._o, partition)

    def copy_device_to_device (self, src, dest, srcoffset=-1, destoffset=-1, size=-1):
        """The four calls "g.copy_device_to_device",
        "g.copy_device_to_file", "g.copy_file_to_device", and
        "g.copy_file_to_file" let you copy from a source
        (device|file) to a destination (device|file).
        
        Partial copies can be made since you can specify
        optionally the source offset, destination offset and
        size to copy. These values are all specified in bytes.
        If not given, the offsets both default to zero, and the
        size defaults to copying as much as possible until we
        hit the end of the source.
        
        The source and destination may be the same object.
        However overlapping regions may not be copied correctly.
        
        If the destination is a file, it is created if required.
        If the destination file is not large enough, it is
        extended.
        """
        self._check_not_closed ()
        return libguestfsmod.copy_device_to_device (self._o, src, dest, srcoffset, destoffset, size)

    def copy_device_to_file (self, src, dest, srcoffset=-1, destoffset=-1, size=-1):
        """See "g.copy_device_to_device" for a general overview of
        this call.
        """
        self._check_not_closed ()
        return libguestfsmod.copy_device_to_file (self._o, src, dest, srcoffset, destoffset, size)

    def copy_file_to_device (self, src, dest, srcoffset=-1, destoffset=-1, size=-1):
        """See "g.copy_device_to_device" for a general overview of
        this call.
        """
        self._check_not_closed ()
        return libguestfsmod.copy_file_to_device (self._o, src, dest, srcoffset, destoffset, size)

    def copy_file_to_file (self, src, dest, srcoffset=-1, destoffset=-1, size=-1):
        """See "g.copy_device_to_device" for a general overview of
        this call.
        
        This is not the function you want for copying files.
        This is for copying blocks within existing files. See
        "g.cp", "g.cp_a" and "g.mv" for general file copying and
        moving functions.
        """
        self._check_not_closed ()
        return libguestfsmod.copy_file_to_file (self._o, src, dest, srcoffset, destoffset, size)

    def tune2fs (self, device, force=-1, maxmountcount=-1, mountcount=-1, errorbehavior=None, group=-1, intervalbetweenchecks=-1, reservedblockspercentage=-1, lastmounteddirectory=None, reservedblockscount=-1, user=-1):
        """This call allows you to adjust various filesystem
        parameters of an ext2/ext3/ext4 filesystem called
        "device".
        
        The optional parameters are:
        
        "force"
        Force tune2fs to complete the operation even in the
        face of errors. This is the same as the tune2fs "-f"
        option.
        
        "maxmountcount"
        Set the number of mounts after which the filesystem
        is checked by e2fsck(8). If this is 0 then the
        number of mounts is disregarded. This is the same as
        the tune2fs "-c" option.
        
        "mountcount"
        Set the number of times the filesystem has been
        mounted. This is the same as the tune2fs "-C"
        option.
        
        "errorbehavior"
        Change the behavior of the kernel code when errors
        are detected. Possible values currently are:
        "continue", "remount-ro", "panic". In practice these
        options don't really make any difference,
        particularly for write errors.
        
        This is the same as the tune2fs "-e" option.
        
        "group"
        Set the group which can use reserved filesystem
        blocks. This is the same as the tune2fs "-g" option
        except that it can only be specified as a number.
        
        "intervalbetweenchecks"
        Adjust the maximal time between two filesystem
        checks (in seconds). If the option is passed as 0
        then time-dependent checking is disabled.
        
        This is the same as the tune2fs "-i" option.
        
        "reservedblockspercentage"
        Set the percentage of the filesystem which may only
        be allocated by privileged processes. This is the
        same as the tune2fs "-m" option.
        
        "lastmounteddirectory"
        Set the last mounted directory. This is the same as
        the tune2fs "-M" option.
        
        "reservedblockscount" Set the number of reserved
        filesystem blocks. This is the same as the tune2fs "-r"
        option.
        "user"
        Set the user who can use the reserved filesystem
        blocks. This is the same as the tune2fs "-u" option
        except that it can only be specified as a number.
        
        To get the current values of filesystem parameters, see
        "g.tune2fs_l". For precise details of how tune2fs works,
        see the tune2fs(8) man page.
        """
        self._check_not_closed ()
        return libguestfsmod.tune2fs (self._o, device, force, maxmountcount, mountcount, errorbehavior, group, intervalbetweenchecks, reservedblockspercentage, lastmounteddirectory, reservedblockscount, user)

    def md_create (self, name, devices, missingbitmap=-1, nrdevices=-1, spare=-1, chunk=-1, level=None):
        """Create a Linux md (RAID) device named "name" on the
        devices in the list "devices".
        
        The optional parameters are:
        
        "missingbitmap"
        A bitmap of missing devices. If a bit is set it
        means that a missing device is added to the array.
        The least significant bit corresponds to the first
        device in the array.
        
        As examples:
        
        If "devices = ["/dev/sda"]" and "missingbitmap =
        0x1" then the resulting array would be "[<missing>,
        "/dev/sda"]".
        
        If "devices = ["/dev/sda"]" and "missingbitmap =
        0x2" then the resulting array would be "["/dev/sda",
        <missing>]".
        
        This defaults to 0 (no missing devices).
        
        The length of "devices" + the number of bits set in
        "missingbitmap" must equal "nrdevices" + "spare".
        
        "nrdevices"
        The number of active RAID devices.
        
        If not set, this defaults to the length of "devices"
        plus the number of bits set in "missingbitmap".
        
        "spare"
        The number of spare devices.
        
        If not set, this defaults to 0.
        
        "chunk"
        The chunk size in bytes.
        
        "level"
        The RAID level, which can be one of: *linear*,
        *raid0*, *0*, *stripe*, *raid1*, *1*, *mirror*,
        *raid4*, *4*, *raid5*, *5*, *raid6*, *6*, *raid10*,
        *10*. Some of these are synonymous, and more levels
        may be added in future.
        
        If not set, this defaults to "raid1".
        """
        devices = list (devices)
        self._check_not_closed ()
        return libguestfsmod.md_create (self._o, name, devices, missingbitmap, nrdevices, spare, chunk, level)

    def list_md_devices (self):
        """List all Linux md devices.
        
        This function returns a list of strings.
        """
        self._check_not_closed ()
        return libguestfsmod.list_md_devices (self._o)

    def md_detail (self, md):
        """This command exposes the output of 'mdadm -DY <md>'. The
        following fields are usually present in the returned
        hash. Other fields may also be present.
        
        "level"
        The raid level of the MD device.
        
        "devices"
        The number of underlying devices in the MD device.
        
        "metadata"
        The metadata version used.
        
        "uuid"
        The UUID of the MD device.
        
        "name"
        The name of the MD device.
        
        This function returns a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.md_detail (self._o, md)

    def md_stop (self, md):
        """This command deactivates the MD array named "md". The
        device is stopped, but it is not destroyed or zeroed.
        """
        self._check_not_closed ()
        return libguestfsmod.md_stop (self._o, md)

    def blkid (self, device):
        """This command returns block device attributes for
        "device". The following fields are usually present in
        the returned hash. Other fields may also be present.
        
        "UUID"
        The uuid of this device.
        
        "LABEL"
        The label of this device.
        
        "VERSION"
        The version of blkid command.
        
        "TYPE"
        The filesystem type or RAID of this device.
        
        "USAGE"
        The usage of this device, for example "filesystem"
        or "raid".
        
        This function returns a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.blkid (self._o, device)

    def e2fsck (self, device, correct=-1, forceall=-1):
        """This runs the ext2/ext3 filesystem checker on "device".
        It can take the following optional arguments:
        
        "correct"
        Automatically repair the file system. This option
        will cause e2fsck to automatically fix any
        filesystem problems that can be safely fixed without
        human intervention.
        
        This option may not be specified at the same time as
        the "forceall" option.
        
        "forceall"
        Assume an answer of 'yes' to all questions; allows
        e2fsck to be used non-interactively.
        
        This option may not be specified at the same time as
        the "correct" option.
        """
        self._check_not_closed ()
        return libguestfsmod.e2fsck (self._o, device, correct, forceall)

    def llz (self, directory):
        """List the files in "directory" in the format of 'ls
        -laZ'.
        
        This command is mostly useful for interactive sessions.
        It is *not* intended that you try to parse the output
        string.
        """
        self._check_not_closed ()
        return libguestfsmod.llz (self._o, directory)

    def wipefs (self, device):
        """This command erases filesystem or RAID signatures from
        the specified "device" to make the filesystem invisible
        to libblkid.
        
        This does not erase the filesystem itself nor any other
        data from the "device".
        
        Compare with "g.zero" which zeroes the first few blocks
        of a device.
        """
        self._check_not_closed ()
        return libguestfsmod.wipefs (self._o, device)

    def ntfsfix (self, device, clearbadsectors=-1):
        """This command repairs some fundamental NTFS
        inconsistencies, resets the NTFS journal file, and
        schedules an NTFS consistency check for the first boot
        into Windows.
        
        This is *not* an equivalent of Windows "chkdsk". It does
        *not* scan the filesystem for inconsistencies.
        
        The optional "clearbadsectors" flag clears the list of
        bad sectors. This is useful after cloning a disk with
        bad sectors to a new disk.
        """
        self._check_not_closed ()
        return libguestfsmod.ntfsfix (self._o, device, clearbadsectors)

    def ntfsclone_out (self, device, backupfile, metadataonly=-1, rescue=-1, ignorefscheck=-1, preservetimestamps=-1, force=-1):
        """Stream the NTFS filesystem "device" to the local file
        "backupfile". The format used for the backup file is a
        special format used by the ntfsclone(8) tool.
        
        If the optional "metadataonly" flag is true, then *only*
        the metadata is saved, losing all the user data (this is
        useful for diagnosing some filesystem problems).
        
        The optional "rescue", "ignorefscheck",
        "preservetimestamps" and "force" flags have precise
        meanings detailed in the ntfsclone(8) man page.
        
        Use "g.ntfsclone_in" to restore the file back to a
        libguestfs device.
        """
        self._check_not_closed ()
        return libguestfsmod.ntfsclone_out (self._o, device, backupfile, metadataonly, rescue, ignorefscheck, preservetimestamps, force)

    def ntfsclone_in (self, backupfile, device):
        """Restore the "backupfile" (from a previous call to
        "g.ntfsclone_out") to "device", overwriting any existing
        contents of this device.
        """
        self._check_not_closed ()
        return libguestfsmod.ntfsclone_in (self._o, backupfile, device)

    def set_label (self, device, label):
        """Set the filesystem label on "device" to "label".
        
        Only some filesystem types support labels, and
        libguestfs supports setting labels on only a subset of
        these.
        
        On ext2/3/4 filesystems, labels are limited to 16 bytes.
        
        On NTFS filesystems, labels are limited to 128 unicode
        characters.
        
        To read the label on a filesystem, call "g.vfs_label".
        """
        self._check_not_closed ()
        return libguestfsmod.set_label (self._o, device, label)

    def zero_free_space (self, directory):
        """Zero the free space in the filesystem mounted on
        "directory". The filesystem must be mounted read-write.
        
        The filesystem contents are not affected, but any free
        space in the filesystem is freed.
        
        In future (but not currently) these zeroed blocks will
        be "sparsified" - that is, given back to the host.
        """
        self._check_not_closed ()
        return libguestfsmod.zero_free_space (self._o, directory)

    def lvcreate_free (self, logvol, volgroup, percent):
        """Create an LVM logical volume called
        "/dev/volgroup/logvol", using approximately "percent" %
        of the free space remaining in the volume group. Most
        usefully, when "percent" is 100 this will create the
        largest possible LV.
        """
        self._check_not_closed ()
        return libguestfsmod.lvcreate_free (self._o, logvol, volgroup, percent)

    def isoinfo_device (self, device):
        """"device" is an ISO device. This returns a struct of
        information read from the primary volume descriptor (the
        ISO equivalent of the superblock) of the device.
        
        Usually it is more efficient to use the isoinfo(1)
        command with the *-d* option on the host to analyze ISO
        files, instead of going through libguestfs.
        
        For information on the primary volume descriptor fields,
        see
        <http://wiki.osdev.org/ISO_9660#The_Primary_Volume_Descr
        iptor>
        
        This function returns a dictionary, with keys matching
        the various fields in the guestfs_isoinfo structure.
        """
        self._check_not_closed ()
        return libguestfsmod.isoinfo_device (self._o, device)

    def isoinfo (self, isofile):
        """This is the same as "g.isoinfo_device" except that it
        works for an ISO file located inside some other mounted
        filesystem. Note that in the common case where you have
        added an ISO file as a libguestfs device, you would
        *not* call this. Instead you would call
        "g.isoinfo_device".
        
        This function returns a dictionary, with keys matching
        the various fields in the guestfs_isoinfo structure.
        """
        self._check_not_closed ()
        return libguestfsmod.isoinfo (self._o, isofile)

    def vgmeta (self, vgname):
        """"vgname" is an LVM volume group. This command examines
        the volume group and returns its metadata.
        
        Note that the metadata is an internal structure used by
        LVM, subject to change at any time, and is provided for
        information only.
        """
        self._check_not_closed ()
        return libguestfsmod.vgmeta (self._o, vgname)

    def md_stat (self, md):
        """This call returns a list of the underlying devices which
        make up the single software RAID array device "md".
        
        To get a list of software RAID devices, call
        "g.list_md_devices".
        
        Each structure returned corresponds to one device along
        with additional status information:
        
        "mdstat_device"
        The name of the underlying device.
        
        "mdstat_index"
        The index of this device within the array.
        
        "mdstat_flags"
        Flags associated with this device. This is a string
        containing (in no specific order) zero or more of
        the following flags:
        
        "W" write-mostly
        
        "F" device is faulty
        
        "S" device is a RAID spare
        
        "R" replacement
        
        This function returns a list of mdstats. Each mdstat is
        represented as a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.md_stat (self._o, md)

    def mkfs_btrfs (self, devices, allocstart=-1, bytecount=-1, datatype=None, leafsize=-1, label=None, metadata=None, nodesize=-1, sectorsize=-1):
        """Create a btrfs filesystem, allowing all configurables to
        be set. For more information on the optional arguments,
        see mkfs.btrfs(8).
        
        Since btrfs filesystems can span multiple devices, this
        takes a non-empty list of devices.
        
        To create general filesystems, use "g.mkfs_opts".
        """
        devices = list (devices)
        self._check_not_closed ()
        return libguestfsmod.mkfs_btrfs (self._o, devices, allocstart, bytecount, datatype, leafsize, label, metadata, nodesize, sectorsize)

    def get_e2attrs (self, file):
        """This returns the file attributes associated with "file".
        
        The attributes are a set of bits associated with each
        inode which affect the behaviour of the file. The
        attributes are returned as a string of letters
        (described below). The string may be empty, indicating
        that no file attributes are set for this file.
        
        These attributes are only present when the file is
        located on an ext2/3/4 filesystem. Using this call on
        other filesystem types will result in an error.
        
        The characters (file attributes) in the returned string
        are currently:
        
        'A' When the file is accessed, its atime is not
        modified.
        
        'a' The file is append-only.
        
        'c' The file is compressed on-disk.
        
        'D' (Directories only.) Changes to this directory are
        written synchronously to disk.
        
        'd' The file is not a candidate for backup (see
        dump(8)).
        
        'E' The file has compression errors.
        
        'e' The file is using extents.
        
        'h' The file is storing its blocks in units of the
        filesystem blocksize instead of sectors.
        
        'I' (Directories only.) The directory is using hashed
        trees.
        
        'i' The file is immutable. It cannot be modified,
        deleted or renamed. No link can be created to this
        file.
        
        'j' The file is data-journaled.
        
        's' When the file is deleted, all its blocks will be
        zeroed.
        
        'S' Changes to this file are written synchronously to
        disk.
        
        'T' (Directories only.) This is a hint to the block
        allocator that subdirectories contained in this
        directory should be spread across blocks. If not
        present, the block allocator will try to group
        subdirectories together.
        
        't' For a file, this disables tail-merging. (Not used by
        upstream implementations of ext2.)
        
        'u' When the file is deleted, its blocks will be saved,
        allowing the file to be undeleted.
        
        'X' The raw contents of the compressed file may be
        accessed.
        
        'Z' The compressed file is dirty.
        
        More file attributes may be added to this list later.
        Not all file attributes may be set for all kinds of
        files. For detailed information, consult the chattr(1)
        man page.
        
        See also "g.set_e2attrs".
        
        Don't confuse these attributes with extended attributes
        (see "g.getxattr").
        """
        self._check_not_closed ()
        return libguestfsmod.get_e2attrs (self._o, file)

    def set_e2attrs (self, file, attrs, clear=-1):
        """This sets or clears the file attributes "attrs"
        associated with the inode "file".
        
        "attrs" is a string of characters representing file
        attributes. See "g.get_e2attrs" for a list of possible
        attributes. Not all attributes can be changed.
        
        If optional boolean "clear" is not present or false,
        then the "attrs" listed are set in the inode.
        
        If "clear" is true, then the "attrs" listed are cleared
        in the inode.
        
        In both cases, other attributes not present in the
        "attrs" string are left unchanged.
        
        These attributes are only present when the file is
        located on an ext2/3/4 filesystem. Using this call on
        other filesystem types will result in an error.
        """
        self._check_not_closed ()
        return libguestfsmod.set_e2attrs (self._o, file, attrs, clear)

    def get_e2generation (self, file):
        """This returns the ext2 file generation of a file. The
        generation (which used to be called the "version") is a
        number associated with an inode. This is most commonly
        used by NFS servers.
        
        The generation is only present when the file is located
        on an ext2/3/4 filesystem. Using this call on other
        filesystem types will result in an error.
        
        See "g.set_e2generation".
        """
        self._check_not_closed ()
        return libguestfsmod.get_e2generation (self._o, file)

    def set_e2generation (self, file, generation):
        """This sets the ext2 file generation of a file.
        
        See "g.get_e2generation".
        """
        self._check_not_closed ()
        return libguestfsmod.set_e2generation (self._o, file, generation)

    def btrfs_subvolume_snapshot (self, source, dest):
        """Create a writable snapshot of the btrfs subvolume
        "source". The "dest" argument is the destination
        directory and the name of the snapshot, in the form
        "/path/to/dest/name".
        """
        self._check_not_closed ()
        return libguestfsmod.btrfs_subvolume_snapshot (self._o, source, dest)

    def btrfs_subvolume_delete (self, subvolume):
        """Delete the named btrfs subvolume.
        """
        self._check_not_closed ()
        return libguestfsmod.btrfs_subvolume_delete (self._o, subvolume)

    def btrfs_subvolume_create (self, dest):
        """Create a btrfs subvolume. The "dest" argument is the
        destination directory and the name of the snapshot, in
        the form "/path/to/dest/name".
        """
        self._check_not_closed ()
        return libguestfsmod.btrfs_subvolume_create (self._o, dest)

    def btrfs_subvolume_list (self, fs):
        """List the btrfs snapshots and subvolumes of the btrfs
        filesystem which is mounted at "fs".
        
        This function returns a list of btrfssubvolumes. Each
        btrfssubvolume is represented as a dictionary.
        """
        self._check_not_closed ()
        return libguestfsmod.btrfs_subvolume_list (self._o, fs)

    def btrfs_subvolume_set_default (self, id, fs):
        """Set the subvolume of the btrfs filesystem "fs" which
        will be mounted by default. See "g.btrfs_subvolume_list"
        to get a list of subvolumes.
        """
        self._check_not_closed ()
        return libguestfsmod.btrfs_subvolume_set_default (self._o, id, fs)

    def btrfs_filesystem_sync (self, fs):
        """Force sync on the btrfs filesystem mounted at "fs".
        """
        self._check_not_closed ()
        return libguestfsmod.btrfs_filesystem_sync (self._o, fs)

    def btrfs_filesystem_balance (self, fs):
        """Balance the chunks in the btrfs filesystem mounted at
        "fs" across the underlying devices.
        """
        self._check_not_closed ()
        return libguestfsmod.btrfs_filesystem_balance (self._o, fs)

    def btrfs_device_add (self, devices, fs):
        """Add the list of device(s) in "devices" to the btrfs
        filesystem mounted at "fs". If "devices" is an empty
        list, this does nothing.
        """
        devices = list (devices)
        self._check_not_closed ()
        return libguestfsmod.btrfs_device_add (self._o, devices, fs)

    def btrfs_device_delete (self, devices, fs):
        """Remove the "devices" from the btrfs filesystem mounted
        at "fs". If "devices" is an empty list, this does
        nothing.
        """
        devices = list (devices)
        self._check_not_closed ()
        return libguestfsmod.btrfs_device_delete (self._o, devices, fs)

    def btrfs_set_seeding (self, device, seeding):
        """Enable or disable the seeding feature of a device that
        contains a btrfs filesystem.
        """
        self._check_not_closed ()
        return libguestfsmod.btrfs_set_seeding (self._o, device, seeding)

    def btrfs_fsck (self, device, superblock=-1, repair=-1):
        """Used to check a btrfs filesystem, "device" is the device
        file where the filesystem is stored.
        """
        self._check_not_closed ()
        return libguestfsmod.btrfs_fsck (self._o, device, superblock, repair)

    def device_index (self, device):
        """This function takes a device name (eg. "/dev/sdb") and
        returns the index of the device in the list of devices.
        
        Index numbers start from 0. The named device must exist,
        for example as a string returned from "g.list_devices".
        
        See also "g.list_devices", "g.part_to_dev".
        """
        self._check_not_closed ()
        return libguestfsmod.device_index (self._o, device)

    def nr_devices (self):
        """This returns the number of whole block devices that were
        added. This is the same as the number of devices that
        would be returned if you called "g.list_devices".
        
        To find out the maximum number of devices that could be
        added, call "g.max_disks".
        """
        self._check_not_closed ()
        return libguestfsmod.nr_devices (self._o)

