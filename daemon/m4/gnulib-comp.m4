# DO NOT EDIT! GENERATED AUTOMATICALLY!
# Copyright (C) 2002-2010 Free Software Foundation, Inc.
#
# This file is free software, distributed under the terms of the GNU
# General Public License.  As a special exception to the GNU General
# Public License, this file may be distributed as part of a program
# that contains a configuration script generated by Autoconf, under
# the same distribution terms as the rest of that program.
#
# Generated by gnulib-tool.
#
# This file represents the compiled summary of the specification in
# gnulib-cache.m4. It lists the computed macro invocations that need
# to be invoked from configure.ac.
# In projects using CVS, this file can be treated like other built files.


# This macro should be invoked from ./configure.ac, in the section
# "Checks for programs", right after AC_PROG_CC, and certainly before
# any checks for libraries, header files, types and library functions.
AC_DEFUN([gl_EARLY],
[
  m4_pattern_forbid([^gl_[A-Z]])dnl the gnulib macro namespace
  m4_pattern_allow([^gl_ES$])dnl a valid locale name
  m4_pattern_allow([^gl_LIBOBJS$])dnl a variable
  m4_pattern_allow([^gl_LTLIBOBJS$])dnl a variable
  AC_REQUIRE([AC_PROG_RANLIB])
  AC_REQUIRE([gl_USE_SYSTEM_EXTENSIONS])
])

# This macro should be invoked from ./configure.ac, in the section
# "Check for header files, types and library functions".
AC_DEFUN([gl_INIT],
[
  AM_CONDITIONAL([GL_COND_LIBTOOL], [false])
  gl_cond_libtool=false
  gl_libdeps=
  gl_ltlibdeps=
  m4_pushdef([AC_LIBOBJ], m4_defn([gl_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([gl_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([gl_LIBSOURCES]))
  m4_pushdef([gl_LIBSOURCES_LIST], [])
  m4_pushdef([gl_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='lib'
  gl_FUNC_ALLOCA
  gl_HEADER_ARPA_INET
  AC_PROG_MKDIR_P
  AC_REQUIRE([AC_C_INLINE])
  gl_BYTESWAP
  gl_FUNC_CHDIR_LONG
  gl_FUNC_CHOWN
  gl_UNISTD_MODULE_INDICATOR([chown])
  gl_CLOCK_TIME
  gl_FUNC_CLOSE
  gl_UNISTD_MODULE_INDICATOR([close])
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([connect])
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([connect])
  gl_CHECK_TYPE_STRUCT_DIRENT_D_INO
  gl_CHECK_TYPE_STRUCT_DIRENT_D_TYPE
  gl_DIRENT_H
  gl_FUNC_DIRFD
  gl_DIRENT_MODULE_INDICATOR([dirfd])
  gl_DIRNAME_LGPL
  gl_DOUBLE_SLASH_ROOT
  gl_FUNC_DUP2
  gl_UNISTD_MODULE_INDICATOR([dup2])
  gl_HEADER_ERRNO_H
  gl_ERROR
  m4_ifdef([AM_XGETTEXT_OPTION],
    [AM_][XGETTEXT_OPTION([--flag=error:3:c-format])
     AM_][XGETTEXT_OPTION([--flag=error_at_line:5:c-format])])
  gl_EXITFAIL
  gl_FUNC_FCHDIR
  gl_UNISTD_MODULE_INDICATOR([fchdir])
  gl_FUNC_FCLOSE
  gl_STDIO_MODULE_INDICATOR([fclose])
  gl_FUNC_FCNTL
  gl_FCNTL_MODULE_INDICATOR([fcntl])
  gl_FCNTL_H
  gl_FUNC_FDOPENDIR
  gl_DIRENT_MODULE_INDICATOR([fdopendir])
  gl_FLOAT_H
  gl_FUNC_FNMATCH_POSIX
  gl_FSUSAGE
  gl_FUNC_FUTIMENS
  gl_SYS_STAT_MODULE_INDICATOR([futimens])
  gl_GETADDRINFO
  gl_NETDB_MODULE_INDICATOR([getaddrinfo])
  gl_FUNC_GETCWD
  gl_UNISTD_MODULE_INDICATOR([getcwd])
  gl_FUNC_GETDELIM
  gl_STDIO_MODULE_INDICATOR([getdelim])
  gl_FUNC_GETLINE
  gl_STDIO_MODULE_INDICATOR([getline])
  gl_GETLOGIN_R
  gl_UNISTD_MODULE_INDICATOR([getlogin_r])
  AC_SUBST([LIBINTL])
  AC_SUBST([LTLIBINTL])
  gl_GETTIME
  gl_FUNC_GETTIMEOFDAY
  gl_GLOB
  gl_HASH
  gl_HOSTENT
  AC_REQUIRE([AC_C_INLINE])
  gl_INET_NTOP
  gl_ARPA_INET_MODULE_INDICATOR([inet_ntop])
  gl_INLINE
  gl_FUNC_LCHOWN
  gl_UNISTD_MODULE_INDICATOR([lchown])
  gl_LOCALCHARSET
  LOCALCHARSET_TESTS_ENVIRONMENT="CHARSETALIASDIR=\"\$(top_builddir)/$gl_source_base\""
  AC_SUBST([LOCALCHARSET_TESTS_ENVIRONMENT])
  gl_FUNC_LSEEK
  gl_UNISTD_MODULE_INDICATOR([lseek])
  gl_FUNC_LSTAT
  gl_SYS_STAT_MODULE_INDICATOR([lstat])
  gl_FUNC_MALLOC_POSIX
  gl_STDLIB_MODULE_INDICATOR([malloc-posix])
  gl_FUNC_MBRTOWC
  gl_WCHAR_MODULE_INDICATOR([mbrtowc])
  gl_FUNC_MBSINIT
  gl_WCHAR_MODULE_INDICATOR([mbsinit])
  gl_FUNC_MBSRTOWCS
  gl_WCHAR_MODULE_INDICATOR([mbsrtowcs])
  gl_FUNC_MEMCHR
  gl_STRING_MODULE_INDICATOR([memchr])
  gl_FUNC_MEMPCPY
  gl_STRING_MODULE_INDICATOR([mempcpy])
  gl_FUNC_MEMRCHR
  gl_STRING_MODULE_INDICATOR([memrchr])
  gl_FUNC_MKDIR
  gt_FUNC_MKDTEMP
  gl_STDLIB_MODULE_INDICATOR([mkdtemp])
  gl_MULTIARCH
  gl_HEADER_NETDB
  gl_HEADER_NETINET_IN
  AC_PROG_MKDIR_P
  gl_FUNC_OPEN
  gl_MODULE_INDICATOR([open])
  gl_FCNTL_MODULE_INDICATOR([open])
  gl_FUNC_OPENAT
  gl_FUNC_PERROR
  gl_STRING_MODULE_INDICATOR([perror])
  gl_FUNC_PREAD
  gl_UNISTD_MODULE_INDICATOR([pread])
  gl_FUNC_RAWMEMCHR
  gl_STRING_MODULE_INDICATOR([rawmemchr])
  gl_FUNC_READLINK
  gl_UNISTD_MODULE_INDICATOR([readlink])
  gl_FUNC_REALLOC_POSIX
  gl_STDLIB_MODULE_INDICATOR([realloc-posix])
  gl_FUNC_RMDIR
  gl_UNISTD_MODULE_INDICATOR([rmdir])
  gl_SAFE_READ
  gl_SAFE_WRITE
  gl_SAVE_CWD
  gl_FUNC_SELECT
  gl_SYS_SELECT_MODULE_INDICATOR([select])
  gl_SERVENT
  gl_SIZE_MAX
  gl_FUNC_SLEEP
  gl_UNISTD_MODULE_INDICATOR([sleep])
  gl_FUNC_SNPRINTF
  gl_STDIO_MODULE_INDICATOR([snprintf])
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([socket])
  fi
  # When this module is used, sockets may actually occur as file descriptors,
  # hence it is worth warning if the modules 'close' and 'ioctl' are not used.
  m4_ifdef([gl_UNISTD_H_DEFAULTS], [AC_REQUIRE([gl_UNISTD_H_DEFAULTS])])
  m4_ifdef([gl_SYS_IOCTL_H_DEFAULTS], [AC_REQUIRE([gl_SYS_IOCTL_H_DEFAULTS])])
  AC_REQUIRE([gl_PREREQ_SYS_H_WINSOCK2])
  if test "$ac_cv_header_winsock2_h" = yes; then
    UNISTD_H_HAVE_WINSOCK2_H_AND_USE_SOCKETS=1
    SYS_IOCTL_H_HAVE_WINSOCK2_H_AND_USE_SOCKETS=1
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([socket])
  gl_SOCKETS
  gl_TYPE_SOCKLEN_T
  gt_TYPE_SSIZE_T
  gl_FUNC_STAT
  gl_SYS_STAT_MODULE_INDICATOR([stat])
  gl_STAT_TIME
  gl_STAT_BIRTHTIME
  AM_STDBOOL_H
  gl_STDDEF_H
  gl_STDINT_H
  gl_STDIO_H
  gl_STDLIB_H
  gl_FUNC_STRCHRNUL
  gl_STRING_MODULE_INDICATOR([strchrnul])
  gl_FUNC_STRDUP_POSIX
  gl_STRING_MODULE_INDICATOR([strdup])
  gl_FUNC_STRERROR
  gl_STRING_MODULE_INDICATOR([strerror])
  gl_HEADER_STRING_H
  gl_FUNC_STRNDUP
  gl_STRING_MODULE_INDICATOR([strndup])
  gl_FUNC_STRNLEN
  gl_STRING_MODULE_INDICATOR([strnlen])
  gl_FUNC_SYMLINK
  gl_UNISTD_MODULE_INDICATOR([symlink])
  gl_FUNC_SYMLINKAT
  gl_UNISTD_MODULE_INDICATOR([symlinkat])
  gl_UNISTD_MODULE_INDICATOR([readlinkat])
  gl_HEADER_SYS_SELECT
  AC_PROG_MKDIR_P
  gl_HEADER_SYS_SOCKET
  AC_PROG_MKDIR_P
  gl_HEADER_SYS_STAT_H
  AC_PROG_MKDIR_P
  gl_HEADER_SYS_TIME_H
  AC_PROG_MKDIR_P
  gl_SYS_WAIT_H
  AC_PROG_MKDIR_P
  gl_FUNC_GEN_TEMPNAME
  gl_HEADER_TIME_H
  gl_TIMESPEC
  gl_UNISTD_H
  gl_UNISTD_SAFER
  gl_FUNC_UNLINK
  gl_UNISTD_MODULE_INDICATOR([unlink])
  gl_UTIMENS
  gl_FUNC_VASNPRINTF
  gl_FUNC_VASPRINTF
  gl_STDIO_MODULE_INDICATOR([vasprintf])
  m4_ifdef([AM_XGETTEXT_OPTION],
    [AM_][XGETTEXT_OPTION([--flag=asprintf:2:c-format])
     AM_][XGETTEXT_OPTION([--flag=vasprintf:2:c-format])])
  AC_SUBST([WARN_CFLAGS])
  gl_WCHAR_H
  gl_WCTYPE_H
  gl_FUNC_WRITE
  gl_UNISTD_MODULE_INDICATOR([write])
  gl_XALLOC
  gl_XGETCWD
  gl_XSIZE
  m4_ifval(gl_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([gl_LIBSOURCES_DIR])[ ||
      for gl_file in ]gl_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([gl_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([gl_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([gl_LIBSOURCES_DIR])
  m4_popdef([gl_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    gl_libobjs=
    gl_ltlibobjs=
    if test -n "$gl_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $gl_LIBOBJS; do echo "$i"; done | sed -e "$sed_drop_objext" | sort | uniq`; do
        gl_libobjs="$gl_libobjs $i.$ac_objext"
        gl_ltlibobjs="$gl_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([gl_LIBOBJS], [$gl_libobjs])
    AC_SUBST([gl_LTLIBOBJS], [$gl_ltlibobjs])
  ])
  gltests_libdeps=
  gltests_ltlibdeps=
  m4_pushdef([AC_LIBOBJ], m4_defn([gltests_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([gltests_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([gltests_LIBSOURCES]))
  m4_pushdef([gltests_LIBSOURCES_LIST], [])
  m4_pushdef([gltests_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='tests'
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([accept])
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([accept])
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([bind])
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([bind])
  AC_CHECK_FUNCS_ONCE([getegid])
  gl_CLOEXEC
  gl_MODULE_INDICATOR([cloexec])
  gl_MODULE_INDICATOR([fd-safer-flag])
  gl_FUNC_GETDTABLESIZE
  gl_UNISTD_MODULE_INDICATOR([getdtablesize])
  gl_FUNC_GETGROUPS
  gl_UNISTD_MODULE_INDICATOR([getgroups])
  gl_FUNC_GETPAGESIZE
  gl_UNISTD_MODULE_INDICATOR([getpagesize])
  gl_GETUGROUPS
  AC_C_BIGENDIAN
  gl_INET_PTON
  gl_ARPA_INET_MODULE_INDICATOR([inet_pton])
  AC_C_BIGENDIAN
  gl_INTTOSTR
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    dnl Even if the 'socket' module is not used here, another part of the
    dnl application may use it and pass file descriptors that refer to
    dnl sockets to the ioctl() function. So enable the support for sockets.
    AC_LIBOBJ([ioctl])
    gl_REPLACE_SYS_IOCTL_H
  fi
  gl_SYS_IOCTL_MODULE_INDICATOR([ioctl])
  gl_MODULE_INDICATOR([ioctl])
  AC_CHECK_FUNCS_ONCE([getegid])
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([listen])
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([listen])
  gt_LOCALE_FR
  gt_LOCALE_FR_UTF8
  gt_LOCALE_JA
  gt_LOCALE_ZH_CN
  gt_LOCALE_FR_UTF8
  gt_LOCALE_FR
  gt_LOCALE_FR_UTF8
  gt_LOCALE_JA
  gt_LOCALE_ZH_CN
  gl_FUNC_MMAP_ANON
  AC_CHECK_HEADERS_ONCE([sys/mman.h])
  AC_CHECK_FUNCS_ONCE([mprotect])
  gl_MGETGROUPS
  AC_CHECK_FUNCS_ONCE([getegid])
  gl_PATHMAX
  gl_PRIV_SET
  AC_CHECK_DECLS([program_invocation_name], [], [], [#include <errno.h>])
  AC_CHECK_DECLS([program_invocation_short_name], [], [], [#include <errno.h>])
  AC_FUNC_REALLOC
  AC_DEFINE([GNULIB_REALLOC_GNU], 1, [Define to indicate the 'realloc' module.])
  AC_CHECK_HEADERS_ONCE([unistd.h sys/wait.h])
  AC_REQUIRE([gl_HEADER_SYS_SOCKET])
  if test "$ac_cv_header_winsock2_h" = yes; then
    AC_LIBOBJ([setsockopt])
  fi
  gl_SYS_SOCKET_MODULE_INDICATOR([setsockopt])
  AC_CHECK_DECLS_ONCE([alarm])
  gt_TYPE_WCHAR_T
  gt_TYPE_WINT_T
  gl_SYS_IOCTL_H
  AC_PROG_MKDIR_P
  AC_CHECK_FUNCS_ONCE([shutdown])
  gl_UNLINKDIR
  gl_FUNC_USLEEP
  gl_UNISTD_MODULE_INDICATOR([usleep])
  gl_UTIMECMP
  gl_FUNC_WCTOB
  gl_WCHAR_MODULE_INDICATOR([wctob])
  m4_ifval(gltests_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([gltests_LIBSOURCES_DIR])[ ||
      for gl_file in ]gltests_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([gltests_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([gltests_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([gltests_LIBSOURCES_DIR])
  m4_popdef([gltests_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    gltests_libobjs=
    gltests_ltlibobjs=
    if test -n "$gltests_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $gltests_LIBOBJS; do echo "$i"; done | sed -e "$sed_drop_objext" | sort | uniq`; do
        gltests_libobjs="$gltests_libobjs $i.$ac_objext"
        gltests_ltlibobjs="$gltests_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([gltests_LIBOBJS], [$gltests_libobjs])
    AC_SUBST([gltests_LTLIBOBJS], [$gltests_ltlibobjs])
  ])
  LIBGNU_LIBDEPS="$gl_libdeps"
  AC_SUBST([LIBGNU_LIBDEPS])
  LIBGNU_LTLIBDEPS="$gl_ltlibdeps"
  AC_SUBST([LIBGNU_LTLIBDEPS])
  LIBTESTS_LIBDEPS="$gltests_libdeps"
  AC_SUBST([LIBTESTS_LIBDEPS])
])

# Like AC_LIBOBJ, except that the module name goes
# into gl_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([gl_LIBOBJ], [
  AS_LITERAL_IF([$1], [gl_LIBSOURCES([$1.c])])dnl
  gl_LIBOBJS="$gl_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into gl_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([gl_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [gl_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([gl_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([gl_LIBSOURCES_DIR], [lib])
      m4_append([gl_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# Like AC_LIBOBJ, except that the module name goes
# into gltests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([gltests_LIBOBJ], [
  AS_LITERAL_IF([$1], [gltests_LIBSOURCES([$1.c])])dnl
  gltests_LIBOBJS="$gltests_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into gltests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([gltests_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [gltests_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([gltests_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([gltests_LIBSOURCES_DIR], [tests])
      m4_append([gltests_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# This macro records the list of files which have been installed by
# gnulib-tool and may be removed by future gnulib-tool invocations.
AC_DEFUN([gl_FILE_LIST], [
  build-aux/arg-nonnull.h
  build-aux/warn-on-use.h
  lib/alignof.h
  lib/alloca.c
  lib/alloca.in.h
  lib/arpa_inet.in.h
  lib/asnprintf.c
  lib/asprintf.c
  lib/at-func.c
  lib/basename-lgpl.c
  lib/bitrotate.h
  lib/byteswap.in.h
  lib/c-ctype.c
  lib/c-ctype.h
  lib/chdir-long.c
  lib/chdir-long.h
  lib/chown.c
  lib/close-hook.c
  lib/close-hook.h
  lib/close.c
  lib/config.charset
  lib/connect.c
  lib/dirent.in.h
  lib/dirfd.c
  lib/dirname-lgpl.c
  lib/dirname.h
  lib/dup-safer.c
  lib/dup2.c
  lib/errno.in.h
  lib/error.c
  lib/error.h
  lib/exitfail.c
  lib/exitfail.h
  lib/fchdir.c
  lib/fchmodat.c
  lib/fchown-stub.c
  lib/fchownat.c
  lib/fclose.c
  lib/fcntl.c
  lib/fcntl.in.h
  lib/fd-safer.c
  lib/fdopendir.c
  lib/float+.h
  lib/float.in.h
  lib/fnmatch.c
  lib/fnmatch.in.h
  lib/fnmatch_loop.c
  lib/fstatat.c
  lib/fsusage.c
  lib/fsusage.h
  lib/full-read.c
  lib/full-read.h
  lib/full-write.c
  lib/full-write.h
  lib/futimens.c
  lib/gai_strerror.c
  lib/getaddrinfo.c
  lib/getcwd.c
  lib/getdelim.c
  lib/getline.c
  lib/getlogin_r.c
  lib/gettext.h
  lib/gettime.c
  lib/gettimeofday.c
  lib/glob-libc.h
  lib/glob.c
  lib/glob.in.h
  lib/hash.c
  lib/hash.h
  lib/ignore-value.h
  lib/inet_ntop.c
  lib/intprops.h
  lib/lchown.c
  lib/localcharset.c
  lib/localcharset.h
  lib/lseek.c
  lib/lstat.c
  lib/malloc.c
  lib/mbrtowc.c
  lib/mbsinit.c
  lib/mbsrtowcs-state.c
  lib/mbsrtowcs.c
  lib/memchr.c
  lib/memchr.valgrind
  lib/mempcpy.c
  lib/memrchr.c
  lib/mkdir.c
  lib/mkdirat.c
  lib/mkdtemp.c
  lib/netdb.in.h
  lib/netinet_in.in.h
  lib/open.c
  lib/openat-die.c
  lib/openat-priv.h
  lib/openat-proc.c
  lib/openat.c
  lib/openat.h
  lib/perror.c
  lib/pipe-safer.c
  lib/pread.c
  lib/printf-args.c
  lib/printf-args.h
  lib/printf-parse.c
  lib/printf-parse.h
  lib/rawmemchr.c
  lib/rawmemchr.valgrind
  lib/readlink.c
  lib/realloc.c
  lib/ref-add.sin
  lib/ref-del.sin
  lib/rmdir.c
  lib/safe-read.c
  lib/safe-read.h
  lib/safe-write.c
  lib/safe-write.h
  lib/same-inode.h
  lib/save-cwd.c
  lib/save-cwd.h
  lib/select.c
  lib/size_max.h
  lib/sleep.c
  lib/snprintf.c
  lib/socket.c
  lib/sockets.c
  lib/sockets.h
  lib/stat-time.h
  lib/stat.c
  lib/stdbool.in.h
  lib/stddef.in.h
  lib/stdint.in.h
  lib/stdio-write.c
  lib/stdio.in.h
  lib/stdlib.in.h
  lib/strchrnul.c
  lib/strchrnul.valgrind
  lib/strdup.c
  lib/streq.h
  lib/strerror.c
  lib/string.in.h
  lib/stripslash.c
  lib/strndup.c
  lib/strnlen.c
  lib/strnlen1.c
  lib/strnlen1.h
  lib/symlink.c
  lib/symlinkat.c
  lib/sys_select.in.h
  lib/sys_socket.in.h
  lib/sys_stat.in.h
  lib/sys_time.in.h
  lib/sys_wait.in.h
  lib/tempname.c
  lib/tempname.h
  lib/time.in.h
  lib/timespec.h
  lib/unistd--.h
  lib/unistd-safer.h
  lib/unistd.in.h
  lib/unlink.c
  lib/unlinkat.c
  lib/utimens.c
  lib/utimens.h
  lib/vasnprintf.c
  lib/vasnprintf.h
  lib/vasprintf.c
  lib/verify.h
  lib/w32sock.h
  lib/wchar.in.h
  lib/wctype.in.h
  lib/write.c
  lib/xalloc-die.c
  lib/xalloc.h
  lib/xgetcwd.c
  lib/xgetcwd.h
  lib/xmalloc.c
  lib/xsize.h
  m4/00gnulib.m4
  m4/alloca.m4
  m4/arpa_inet_h.m4
  m4/byteswap.m4
  m4/chdir-long.m4
  m4/chown.m4
  m4/clock_time.m4
  m4/cloexec.m4
  m4/close.m4
  m4/codeset.m4
  m4/d-ino.m4
  m4/d-type.m4
  m4/dirent_h.m4
  m4/dirfd.m4
  m4/dirname.m4
  m4/dos.m4
  m4/double-slash-root.m4
  m4/dup2.m4
  m4/errno_h.m4
  m4/error.m4
  m4/exitfail.m4
  m4/extensions.m4
  m4/fchdir.m4
  m4/fclose.m4
  m4/fcntl-o.m4
  m4/fcntl.m4
  m4/fcntl_h.m4
  m4/fdopendir.m4
  m4/float_h.m4
  m4/fnmatch.m4
  m4/fsusage.m4
  m4/futimens.m4
  m4/getaddrinfo.m4
  m4/getcwd-abort-bug.m4
  m4/getcwd-path-max.m4
  m4/getcwd.m4
  m4/getdelim.m4
  m4/getdtablesize.m4
  m4/getgroups.m4
  m4/getline.m4
  m4/getlogin_r.m4
  m4/getpagesize.m4
  m4/gettime.m4
  m4/gettimeofday.m4
  m4/getugroups.m4
  m4/glibc21.m4
  m4/glob.m4
  m4/gnulib-common.m4
  m4/hash.m4
  m4/hostent.m4
  m4/include_next.m4
  m4/inet_ntop.m4
  m4/inet_pton.m4
  m4/inline.m4
  m4/intmax_t.m4
  m4/inttostr.m4
  m4/inttypes_h.m4
  m4/lchown.m4
  m4/localcharset.m4
  m4/locale-fr.m4
  m4/locale-ja.m4
  m4/locale-zh.m4
  m4/longlong.m4
  m4/lseek.m4
  m4/lstat.m4
  m4/malloc.m4
  m4/manywarnings.m4
  m4/mbrtowc.m4
  m4/mbsinit.m4
  m4/mbsrtowcs.m4
  m4/mbstate_t.m4
  m4/memchr.m4
  m4/mempcpy.m4
  m4/memrchr.m4
  m4/mgetgroups.m4
  m4/mkdir.m4
  m4/mkdtemp.m4
  m4/mmap-anon.m4
  m4/mode_t.m4
  m4/multiarch.m4
  m4/netdb_h.m4
  m4/netinet_in_h.m4
  m4/onceonly.m4
  m4/open.m4
  m4/openat.m4
  m4/pathmax.m4
  m4/perror.m4
  m4/pread.m4
  m4/printf.m4
  m4/priv-set.m4
  m4/rawmemchr.m4
  m4/readlink.m4
  m4/realloc.m4
  m4/rmdir.m4
  m4/safe-read.m4
  m4/safe-write.m4
  m4/save-cwd.m4
  m4/select.m4
  m4/servent.m4
  m4/size_max.m4
  m4/sleep.m4
  m4/snprintf.m4
  m4/sockets.m4
  m4/socklen.m4
  m4/sockpfaf.m4
  m4/ssize_t.m4
  m4/stat-time.m4
  m4/stat.m4
  m4/stdbool.m4
  m4/stddef_h.m4
  m4/stdint.m4
  m4/stdint_h.m4
  m4/stdio_h.m4
  m4/stdlib_h.m4
  m4/strchrnul.m4
  m4/strdup.m4
  m4/strerror.m4
  m4/string_h.m4
  m4/strndup.m4
  m4/strnlen.m4
  m4/symlink.m4
  m4/symlinkat.m4
  m4/sys_ioctl_h.m4
  m4/sys_select_h.m4
  m4/sys_socket_h.m4
  m4/sys_stat_h.m4
  m4/sys_time_h.m4
  m4/sys_wait_h.m4
  m4/tempname.m4
  m4/time_h.m4
  m4/timespec.m4
  m4/unistd-safer.m4
  m4/unistd_h.m4
  m4/unlink.m4
  m4/unlinkdir.m4
  m4/usleep.m4
  m4/utimbuf.m4
  m4/utimecmp.m4
  m4/utimens.m4
  m4/utimes.m4
  m4/vasnprintf.m4
  m4/vasprintf.m4
  m4/warn-on-use.m4
  m4/warnings.m4
  m4/wchar.m4
  m4/wchar_t.m4
  m4/wctob.m4
  m4/wctype.m4
  m4/wint_t.m4
  m4/write.m4
  m4/xalloc.m4
  m4/xgetcwd.m4
  m4/xsize.m4
  tests/init.sh
  tests/macros.h
  tests/nap.h
  tests/signature.h
  tests/test-alignof.c
  tests/test-alloca-opt.c
  tests/test-arpa_inet.c
  tests/test-binary-io.c
  tests/test-binary-io.sh
  tests/test-bitrotate.c
  tests/test-byteswap.c
  tests/test-c-ctype.c
  tests/test-chown.c
  tests/test-chown.h
  tests/test-cloexec.c
  tests/test-dirent.c
  tests/test-dup-safer.c
  tests/test-dup2.c
  tests/test-errno.c
  tests/test-fchdir.c
  tests/test-fchownat.c
  tests/test-fcntl-h.c
  tests/test-fcntl.c
  tests/test-fdopendir.c
  tests/test-fnmatch.c
  tests/test-fstatat.c
  tests/test-futimens.c
  tests/test-futimens.h
  tests/test-getaddrinfo.c
  tests/test-getcwd.c
  tests/test-getdelim.c
  tests/test-getdtablesize.c
  tests/test-getgroups.c
  tests/test-getline.c
  tests/test-getlogin_r.c
  tests/test-gettimeofday.c
  tests/test-glob.c
  tests/test-hash.c
  tests/test-inet_ntop.c
  tests/test-inet_pton.c
  tests/test-lchown.c
  tests/test-lchown.h
  tests/test-lseek.c
  tests/test-lseek.sh
  tests/test-lstat.c
  tests/test-lstat.h
  tests/test-lutimens.h
  tests/test-mbrtowc.c
  tests/test-mbrtowc1.sh
  tests/test-mbrtowc2.sh
  tests/test-mbrtowc3.sh
  tests/test-mbrtowc4.sh
  tests/test-mbsinit.c
  tests/test-mbsinit.sh
  tests/test-mbsrtowcs.c
  tests/test-mbsrtowcs1.sh
  tests/test-mbsrtowcs2.sh
  tests/test-mbsrtowcs3.sh
  tests/test-mbsrtowcs4.sh
  tests/test-memchr.c
  tests/test-memrchr.c
  tests/test-mkdir.c
  tests/test-mkdir.h
  tests/test-mkdirat.c
  tests/test-netdb.c
  tests/test-netinet_in.c
  tests/test-open.c
  tests/test-open.h
  tests/test-openat.c
  tests/test-perror.c
  tests/test-perror.sh
  tests/test-pread.c
  tests/test-pread.sh
  tests/test-priv-set.c
  tests/test-rawmemchr.c
  tests/test-readlink.c
  tests/test-readlink.h
  tests/test-rmdir.c
  tests/test-rmdir.h
  tests/test-select-fd.c
  tests/test-select-in.sh
  tests/test-select-out.sh
  tests/test-select-stdin.c
  tests/test-select.c
  tests/test-sleep.c
  tests/test-snprintf.c
  tests/test-sockets.c
  tests/test-stat-time.c
  tests/test-stat.c
  tests/test-stat.h
  tests/test-stdbool.c
  tests/test-stddef.c
  tests/test-stdint.c
  tests/test-stdio.c
  tests/test-stdlib.c
  tests/test-strchrnul.c
  tests/test-strerror.c
  tests/test-string.c
  tests/test-symlink.c
  tests/test-symlink.h
  tests/test-symlinkat.c
  tests/test-sys_ioctl.c
  tests/test-sys_select.c
  tests/test-sys_socket.c
  tests/test-sys_stat.c
  tests/test-sys_time.c
  tests/test-sys_wait.c
  tests/test-time.c
  tests/test-unistd.c
  tests/test-unlink.c
  tests/test-unlink.h
  tests/test-unlinkat.c
  tests/test-usleep.c
  tests/test-utimens-common.h
  tests/test-utimens.c
  tests/test-utimens.h
  tests/test-vasnprintf.c
  tests/test-vasprintf.c
  tests/test-wchar.c
  tests/test-wctype.c
  tests/test-xalloc-die.c
  tests/test-xalloc-die.sh
  tests/zerosize-ptr.h
  tests=lib/accept.c
  tests=lib/binary-io.h
  tests=lib/bind.c
  tests=lib/cloexec.c
  tests=lib/cloexec.h
  tests=lib/dup-safer-flag.c
  tests=lib/fd-safer-flag.c
  tests=lib/getdtablesize.c
  tests=lib/getgroups.c
  tests=lib/getpagesize.c
  tests=lib/getugroups.c
  tests=lib/getugroups.h
  tests=lib/hash-pjw.c
  tests=lib/hash-pjw.h
  tests=lib/imaxtostr.c
  tests=lib/inet_pton.c
  tests=lib/inttostr.c
  tests=lib/inttostr.h
  tests=lib/ioctl.c
  tests=lib/listen.c
  tests=lib/mgetgroups.c
  tests=lib/mgetgroups.h
  tests=lib/offtostr.c
  tests=lib/pathmax.h
  tests=lib/priv-set.c
  tests=lib/priv-set.h
  tests=lib/progname.c
  tests=lib/progname.h
  tests=lib/realloc.c
  tests=lib/setsockopt.c
  tests=lib/sys_ioctl.in.h
  tests=lib/uinttostr.c
  tests=lib/umaxtostr.c
  tests=lib/unlinkdir.c
  tests=lib/unlinkdir.h
  tests=lib/usleep.c
  tests=lib/utimecmp.c
  tests=lib/utimecmp.h
  tests=lib/w32sock.h
  tests=lib/wctob.c
])
