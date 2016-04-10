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

dnl Any C libraries required by the libguestfs C library (not the daemon).

dnl Check if dirent (readdir) supports d_type member.
AC_STRUCT_DIRENT_D_TYPE

dnl Check if stat has the required fields.
AC_STRUCT_ST_BLOCKS
AC_CHECK_MEMBER([struct stat.st_blksize],[
    AC_DEFINE([HAVE_STRUCT_STAT_ST_BLKSIZE],[1],[Define to 1 if 'st_blksize' is a member of 'struct stat'.])])
AC_CHECK_MEMBER([struct stat.st_atim.tv_nsec],[
    AC_DEFINE([HAVE_STRUCT_STAT_ST_ATIM_TV_NSEC],[1],[Define to 1 if 'st_mtim.tv_nsec' is a member of 'struct stat'.])])
AC_CHECK_MEMBER([struct stat.st_mtim.tv_nsec],[
    AC_DEFINE([HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC],[1],[Define to 1 if 'st_mtim.tv_nsec' is a member of 'struct stat'.])])
AC_CHECK_MEMBER([struct stat.st_ctim.tv_nsec],[
    AC_DEFINE([HAVE_STRUCT_STAT_ST_CTIM_TV_NSEC],[1],[Define to 1 if 'st_mtim.tv_nsec' is a member of 'struct stat'.])])

dnl Define a C symbol for the host CPU architecture.
AC_DEFINE_UNQUOTED([host_cpu],["$host_cpu"],[Host architecture.])

dnl Check if libc has program_invocation_short_name.
AC_CHECK_DECLS([program_invocation_short_name], [], [], [#include <errno.h>])

dnl Headers.
AC_CHECK_HEADERS([\
    attr/xattr.h \
    byteswap.h \
    endian.h \
    sys/endian.h \
    errno.h \
    linux/fs.h \
    linux/raid/md_u.h \
    printf.h \
    sys/inotify.h \
    sys/resource.h \
    sys/socket.h \
    sys/statvfs.h \
    sys/time.h \
    sys/types.h \
    sys/un.h \
    sys/wait.h \
    windows.h \
    sys/xattr.h])

dnl Functions.
AC_CHECK_FUNCS([\
    be32toh \
    fsync \
    futimens \
    getprogname \
    getxattr \
    htonl \
    htons \
    inotify_init1 \
    lgetxattr \
    listxattr \
    llistxattr \
    lsetxattr \
    lremovexattr \
    mknod \
    ntohl \
    ntohs \
    posix_fallocate \
    posix_fadvise \
    removexattr \
    setitimer \
    setrlimit \
    setxattr \
    sigaction \
    statvfs \
    sync])

dnl Check for UNIX_PATH_MAX, creating a custom one if not available.
AC_MSG_CHECKING([for UNIX_PATH_MAX])
AC_COMPILE_IFELSE([
  AC_LANG_PROGRAM([[
#include <sys/un.h>
  ]], [[
#ifndef UNIX_PATH_MAX
#error UNIX_PATH_MAX not defined
#endif
  ]])], [
    AC_MSG_RESULT([yes])
  ], [
    AC_MSG_RESULT([no])
    AC_MSG_CHECKING([for size of sockaddr_un.sun_path])
    AC_COMPUTE_INT(unix_path_max, [sizeof (myaddr.sun_path)], [
#include <sys/un.h>
struct sockaddr_un myaddr;
      ], [
        AC_MSG_ERROR([cannot get it])
      ])
    AC_MSG_RESULT([$unix_path_max])
    AC_DEFINE_UNQUOTED([UNIX_PATH_MAX], $unix_path_max, [Custom value for UNIX_PATH_MAX])
  ])

dnl tgetent, tputs and UP [sic] are all required.  They come from the lower
dnl tinfo library, but might be part of ncurses directly.
PKG_CHECK_MODULES([LIBTINFO], [tinfo], [], [
    PKG_CHECK_MODULES([LIBTINFO], [ncurses], [], [
        AC_CHECK_PROGS([NCURSES_CONFIG], [ncurses6-config ncurses5-config], [no])
        AS_IF([test "x$NCURSES_CONFIG" = "xno"], [
            AC_MSG_ERROR([ncurses development package is not installed])
        ])
        LIBTINFO_CFLAGS=`$NCURSES_CONFIG --cflags`
        LIBTINFO_LIBS=`$NCURSES_CONFIG --libs`
    ])
])
AC_SUBST([LIBTINFO_CFLAGS])
AC_SUBST([LIBTINFO_LIBS])

dnl GNU gettext tools (optional).
AC_CHECK_PROG([XGETTEXT],[xgettext],[xgettext],[no])
AC_CHECK_PROG([MSGCAT],[msgcat],[msgcat],[no])
AC_CHECK_PROG([MSGFMT],[msgfmt],[msgfmt],[no])
AC_CHECK_PROG([MSGMERGE],[msgmerge],[msgmerge],[no])

dnl Check they are the GNU gettext tools.
AC_MSG_CHECKING([msgfmt is GNU tool])
if $MSGFMT --version >/dev/null 2>&1 && $MSGFMT --version | grep -q 'GNU gettext'; then
    msgfmt_is_gnu=yes
else
    msgfmt_is_gnu=no
fi
AC_MSG_RESULT([$msgfmt_is_gnu])
AM_CONDITIONAL([HAVE_GNU_GETTEXT],
    [test "x$XGETTEXT" != "xno" && test "x$MSGCAT" != "xno" && test "x$MSGFMT" != "xno" && test "x$MSGMERGE" != "xno" && test "x$msgfmt_is_gnu" != "xno"])

dnl Check for gettext.
AM_GNU_GETTEXT([external])

dnl Default backend.
AC_MSG_CHECKING([if the user specified a default backend])
AC_ARG_WITH([default-backend],
    [AS_HELP_STRING([--with-default-backend="direct|libvirt|..."],
        [set default backend @<:@default=direct@:>@])],
    [DEFAULT_BACKEND="$withval"],
    [DEFAULT_BACKEND=direct])
AC_MSG_RESULT([$DEFAULT_BACKEND])
AC_DEFINE_UNQUOTED([DEFAULT_BACKEND],["$DEFAULT_BACKEND"],
                   [Default backend.])

dnl Fail with error if user does --with-default-attach-method.
AC_ARG_WITH([default-attach-method],
    [AS_HELP_STRING([--with-default-attach-method="..."],
        [use --with-default-backend instead])],
    [AC_MSG_FAILURE([--with-default-attach-method no longer works in
this version of libguestfs, use
  ./configure --with-default-backend=$withval
instead.])])

dnl Check for libdl/dlopen (optional - only used to test if the library
dnl can be used with libdl).
AC_CHECK_LIB([dl],[dlopen],[have_libdl=yes],[have_libdl=no])
AC_CHECK_HEADERS([dlfcn.h],[have_dlfcn=yes],[have_dlfcn=no])
AM_CONDITIONAL([HAVE_LIBDL],
               [test "x$have_libdl" = "xyes" && test "x$have_dlfcn" = "xyes"])

dnl Check for rpcgen and XDR library.  rpcgen is optional.
AC_CHECK_PROG([RPCGEN],[rpcgen],[rpcgen],[no])
AM_CONDITIONAL([HAVE_RPCGEN],[test "x$RPCGEN" != "xno"])
AC_CHECK_LIB([portablexdr],[xdrmem_create],[],[
    AC_SEARCH_LIBS([xdrmem_create],[rpc xdr nsl])
])
AC_SEARCH_LIBS([xdr_u_int64_t],[portablexdr rpc xdr nsl],[
    AC_DEFINE([HAVE_XDR_U_INT64_T],[1],[Define to 1 if xdr_u_int64_t() exists.])
])
AC_SEARCH_LIBS([xdr_uint64_t],[portablexdr rpc xdr nsl],[
    AC_DEFINE([HAVE_XDR_UINT64_T],[1],[Define to 1 if xdr_uint64_t() exists.])
])
AM_CONDITIONAL([HAVE_XDR_U_INT64_T],
               [test "x$ac_cv_search_xdr_u_int64_t" != "xno"])
AM_CONDITIONAL([HAVE_XDR_UINT64_T],
               [test "x$ac_cv_search_xdr_uint64_t" != "xno"])

dnl Check for libselinux (optional).
AC_CHECK_HEADERS([selinux/selinux.h])
AC_CHECK_LIB([selinux],[setexeccon],[
    have_libselinux="$ac_cv_header_selinux_selinux_h"
    SELINUX_LIBS="-lselinux"

    old_LIBS="$LIBS"
    LIBS="$LIBS $SELINUX_LIBS"
    AC_CHECK_FUNCS([setcon getcon])
    LIBS="$old_LIBS"
],[have_libselinux=no])
if test "x$have_libselinux" = "xyes"; then
    AC_DEFINE([HAVE_LIBSELINUX],[1],[Define to 1 if you have libselinux.])
fi
AC_SUBST([SELINUX_LIBS])

dnl Check for systemtap/DTrace userspace probes (optional).
dnl Since the probe points break under clang, allow this to be disabled.
AC_ARG_ENABLE([probes],
    AS_HELP_STRING([--disable-probes], [disable systemtap/DTrace userspace probes]),
    [],
    [enable_probes=yes])
AS_IF([test "x$enable_probes" != "xno"],[
    dnl http://sourceware.org/systemtap/wiki/AddingUserSpaceProbingToApps
    AC_CHECK_HEADERS([sys/sdt.h])
    dnl AC_CHECK_PROG([DTRACE],[dtrace],[dtrace],[no])
    AS_IF([test "x$ac_cv_header_sys_sdt_h" = "xyes"],[
        AC_DEFINE([ENABLE_PROBES],[1],[Enable systemtap/DTrace userspace probes.])
    ])
])

dnl Enable packet dumps when in verbose mode.  This generates lots
dnl of debug info, only useful for people debugging the RPC mechanism.
AC_ARG_ENABLE([packet-dump],[
    AS_HELP_STRING([--enable-packet-dump],
        [enable packet dumps in verbose mode @<:@default=no@:>@])],
    [AC_DEFINE([ENABLE_PACKET_DUMP],[1],[Enable packet dumps in verbose mode.])],
    [])

dnl Check for PCRE (required)
PKG_CHECK_MODULES([PCRE], [libpcre])

dnl Check for Augeas >= 1.0.0 (required).
PKG_CHECK_MODULES([AUGEAS],[augeas >= 1.0.0])

dnl libmagic (highly recommended)
AC_CHECK_LIB([magic],[magic_file],[
    AC_CHECK_HEADER([magic.h],[
        AC_SUBST([MAGIC_LIBS], ["-lmagic"])
        AC_DEFINE([HAVE_LIBMAGIC],[1],[libmagic found at compile time.])
    ], [])
],[AC_MSG_WARN([libmagic not found, some core features will be disabled])])

dnl libvirt (highly recommended)
AC_ARG_WITH([libvirt],[
    AS_HELP_STRING([--without-libvirt],
                   [disable libvirt support @<:@default=check@:>@])],
    [],
    [with_libvirt=check])
AS_IF([test "$with_libvirt" != "no"],[
    PKG_CHECK_MODULES([LIBVIRT], [libvirt],[
        AC_SUBST([LIBVIRT_CFLAGS])
        AC_SUBST([LIBVIRT_LIBS])
        AC_DEFINE([HAVE_LIBVIRT],[1],[libvirt found at compile time.])
    ],
    [AC_MSG_WARN([libvirt not found, some core features will be disabled])])
])
AM_CONDITIONAL([HAVE_LIBVIRT],[test "x$LIBVIRT_LIBS" != "x"])

libvirt_ro_uri='qemu+unix:///system?socket=/var/run/libvirt/libvirt-sock-ro'
AC_SUBST([libvirt_ro_uri])

dnl libxml2 (required)
PKG_CHECK_MODULES([LIBXML2], [libxml-2.0])
old_LIBS="$LIBS"
LIBS="$LIBS $LIBXML2_LIBS"
AC_CHECK_FUNCS([xmlBufferDetach])
LIBS="$old_LIBS"

dnl Check for yajl JSON library (optional).
PKG_CHECK_MODULES([YAJL], [yajl >= 2.0.4], [
    AC_SUBST([YAJL_CFLAGS])
    AC_SUBST([YAJL_LIBS])
    AC_DEFINE([HAVE_YAJL],[1],[Define to 1 if you have yajl.])
],[AC_MSG_WARN([yajl not found, some features will be disabled])])
AM_CONDITIONAL([HAVE_YAJL],[test "x$YAJL_LIBS" != "x"])

dnl Check for C++ (optional, we just use this to test the header works).
AC_PROG_CXX

dnl The C++ compiler test is pretty useless because even if it fails
dnl it sets CXX=g++.  So test the compiler actually works.
AC_MSG_CHECKING([if the C++ compiler really really works])
AS_IF([$CXX --version >&AS_MESSAGE_LOG_FD 2>&1],[have_cxx=yes],[have_cxx=no])
AC_MSG_RESULT([$have_cxx])
AM_CONDITIONAL([HAVE_CXX], [test "$have_cxx" = "yes"])

dnl For search paths.
AC_DEFINE_UNQUOTED([PATH_SEPARATOR],["$PATH_SEPARATOR"],
                   [Character that separates path elements in search paths])

dnl Library versioning.
MAX_PROC_NR=`cat $srcdir/src/MAX_PROC_NR`
AC_SUBST(MAX_PROC_NR)
