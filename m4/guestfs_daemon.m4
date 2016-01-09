# libguestfs
# Copyright (C) 2009-2016 Red Hat Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

dnl The daemon and any dependencies.

dnl Build the daemon?
AC_MSG_CHECKING([if we should build the daemon])
AC_ARG_ENABLE([daemon],
    [AS_HELP_STRING([--enable-daemon],
        [enable building the daemon @<:@default=yes@:>@])],
    [],
    [enable_daemon=yes])
AM_CONDITIONAL([ENABLE_DAEMON],[test "x$enable_daemon" = "xyes"])
AC_MSG_RESULT([$enable_daemon])

if test "x$enable_daemon" = "xyes"; then
    dnl Install the daemon (for libguestfs live service)
    AC_MSG_CHECKING([if we should install the daemon])
    AC_ARG_ENABLE([install-daemon],
        [AS_HELP_STRING([--enable-install-daemon],
            [enable installing the daemon under $sbindir @<:@default=no@:>@])],
            [],
            [enable_install_daemon=no])
    AC_MSG_RESULT([$enable_install_daemon])

    dnl Which directory should we put the daemon in?  NOTE: This
    dnl is the "virtual" directory inside the appliance, not the
    dnl install directory for libguestfs live.  Since Fedora 17
    dnl /sbin is a symlink to /usr/sbin.  We have to put the
    dnl daemon into a real (non-symlink) directory.
    dirs="/sbin /usr/sbin /bin /usr/bin"
    AC_MSG_CHECKING([which of $dirs is a real directory])
    for dir in $dirs; do
        parent=`dirname $dir`
        if test ! -L $parent && test -d $parent \
            && test ! -L $dir && test -d $dir
        then
            DAEMON_SUPERMIN_DIR=$dir
            break
        fi
    done
    if test "x$DAEMON_SUPERMIN_DIR" = "x"; then
        AC_MSG_ERROR([non-symlink binary directory not found])
    fi
    AC_MSG_RESULT([$DAEMON_SUPERMIN_DIR])
    AC_SUBST([DAEMON_SUPERMIN_DIR])

    dnl For modified printf in the daemon, we need glibc either (old-style)
    dnl register_printf_function or (new-style) register_printf_specifier.
    AC_CHECK_FUNC([register_printf_specifier],[
        AC_DEFINE([HAVE_REGISTER_PRINTF_SPECIFIER],[1],
                  [Define to 1 if you have new-style register_printf_specifier.])
    ],[
        AC_CHECK_FUNC([register_printf_function],[
            AC_DEFINE([HAVE_REGISTER_PRINTF_FUNCTION],[1],
                      [Define to 1 if you have old-style register_printf_function.])
        ],[
            AC_MSG_FAILURE(
[No support for glibc-style extended printf formatters.

This means you either have a very old glibc (pre-2.0) or you
are using some other libc where this is not supported.])])])
fi
AM_CONDITIONAL([INSTALL_DAEMON],[test "x$enable_install_daemon" = "xyes"])

dnl POSIX acl library (highly recommended)
AC_CHECK_LIB([acl],[acl_from_text],[
    AC_CHECK_HEADER([sys/acl.h],[
        AC_SUBST([ACL_LIBS], [-lacl])
        AC_DEFINE([HAVE_ACL], [1], [Define to 1 if the POSIX acl library is available.])
    ], [])
],[AC_MSG_WARN([POSIX acl library not found])])

dnl Linux capabilities library (libcap) (highly recommended)
AC_CHECK_LIB([cap],[cap_from_text],[
    AC_CHECK_HEADER([sys/capability.h],[
        AC_SUBST([CAP_LIBS], [-lcap])
        AC_DEFINE([HAVE_CAP], [1], [Define to 1 if the Linux capabilities library (libcap) is available.])
    ], [])
],[AC_MSG_WARN([Linux capabilities library (libcap) not found])])

dnl hivex library (highly recommended)
dnl This used to be a part of libguestfs, but was spun off into its
dnl own separate upstream project in libguestfs 1.0.85.
PKG_CHECK_MODULES([HIVEX], [hivex],[
    AC_SUBST([HIVEX_CFLAGS])
    AC_SUBST([HIVEX_LIBS])
    AC_DEFINE([HAVE_HIVEX],[1],[hivex library found at compile time.])
],
    [AC_MSG_WARN([hivex not found, some core features will be disabled])])
AM_CONDITIONAL([HAVE_HIVEX],[test "x$HIVEX_LIBS" != "x"])

dnl systemd journal library (optional)
PKG_CHECK_MODULES([SD_JOURNAL], [libsystemd],[
    AC_SUBST([SD_JOURNAL_CFLAGS])
    AC_SUBST([SD_JOURNAL_LIBS])
    AC_DEFINE([HAVE_SD_JOURNAL],[1],[systemd journal library found at compile time.])
],[
    PKG_CHECK_MODULES([SD_JOURNAL], [libsystemd-journal >= 196],[
        AC_SUBST([SD_JOURNAL_CFLAGS])
        AC_SUBST([SD_JOURNAL_LIBS])
        AC_DEFINE([HAVE_SD_JOURNAL],[1],[systemd journal library found at compile time.])
    ],[
        AC_MSG_WARN([systemd journal library not found, some features will be disabled])
    ])
])
