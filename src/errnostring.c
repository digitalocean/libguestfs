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

#include <config.h>

#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "errnostring.h"

static const char *errno_to_string[] = {
#ifdef E2BIG
  [E2BIG] = "E2BIG",
#endif
#ifdef EACCES
  [EACCES] = "EACCES",
#endif
#ifdef EADDRINUSE
  [EADDRINUSE] = "EADDRINUSE",
#endif
#ifdef EADDRNOTAVAIL
  [EADDRNOTAVAIL] = "EADDRNOTAVAIL",
#endif
#ifdef EADV
  [EADV] = "EADV",
#endif
#ifdef EAFNOSUPPORT
  [EAFNOSUPPORT] = "EAFNOSUPPORT",
#endif
#ifdef EAGAIN
  [EAGAIN] = "EAGAIN",
#endif
#ifdef EALREADY
  [EALREADY] = "EALREADY",
#endif
#ifdef EBADE
  [EBADE] = "EBADE",
#endif
#ifdef EBADF
  [EBADF] = "EBADF",
#endif
#ifdef EBADFD
  [EBADFD] = "EBADFD",
#endif
#ifdef EBADMSG
  [EBADMSG] = "EBADMSG",
#endif
#ifdef EBADR
  [EBADR] = "EBADR",
#endif
#ifdef EBADRQC
  [EBADRQC] = "EBADRQC",
#endif
#ifdef EBADSLT
  [EBADSLT] = "EBADSLT",
#endif
#ifdef EBFONT
  [EBFONT] = "EBFONT",
#endif
#ifdef EBUSY
  [EBUSY] = "EBUSY",
#endif
#ifdef ECANCELED
  [ECANCELED] = "ECANCELED",
#endif
#ifdef ECHILD
  [ECHILD] = "ECHILD",
#endif
#ifdef ECHRNG
  [ECHRNG] = "ECHRNG",
#endif
#ifdef ECOMM
  [ECOMM] = "ECOMM",
#endif
#ifdef ECONNABORTED
  [ECONNABORTED] = "ECONNABORTED",
#endif
#ifdef ECONNREFUSED
  [ECONNREFUSED] = "ECONNREFUSED",
#endif
#ifdef ECONNRESET
  [ECONNRESET] = "ECONNRESET",
#endif
#ifdef EDEADLOCK
  [EDEADLOCK] = "EDEADLOCK",
#endif
#ifdef EDESTADDRREQ
  [EDESTADDRREQ] = "EDESTADDRREQ",
#endif
#ifdef EDOM
  [EDOM] = "EDOM",
#endif
#ifdef EDOTDOT
  [EDOTDOT] = "EDOTDOT",
#endif
#ifdef EDQUOT
  [EDQUOT] = "EDQUOT",
#endif
#ifdef EEXIST
  [EEXIST] = "EEXIST",
#endif
#ifdef EFAULT
  [EFAULT] = "EFAULT",
#endif
#ifdef EFBIG
  [EFBIG] = "EFBIG",
#endif
#ifdef EHOSTDOWN
  [EHOSTDOWN] = "EHOSTDOWN",
#endif
#ifdef EHOSTUNREACH
  [EHOSTUNREACH] = "EHOSTUNREACH",
#endif
#ifdef EIDRM
  [EIDRM] = "EIDRM",
#endif
#ifdef EILSEQ
  [EILSEQ] = "EILSEQ",
#endif
#ifdef EINPROGRESS
  [EINPROGRESS] = "EINPROGRESS",
#endif
#ifdef EINTR
  [EINTR] = "EINTR",
#endif
#ifdef EINVAL
  [EINVAL] = "EINVAL",
#endif
#ifdef EIO
  [EIO] = "EIO",
#endif
#ifdef EISCONN
  [EISCONN] = "EISCONN",
#endif
#ifdef EISDIR
  [EISDIR] = "EISDIR",
#endif
#ifdef EISNAM
  [EISNAM] = "EISNAM",
#endif
#ifdef EKEYEXPIRED
  [EKEYEXPIRED] = "EKEYEXPIRED",
#endif
#ifdef EKEYREJECTED
  [EKEYREJECTED] = "EKEYREJECTED",
#endif
#ifdef EKEYREVOKED
  [EKEYREVOKED] = "EKEYREVOKED",
#endif
#ifdef EL2HLT
  [EL2HLT] = "EL2HLT",
#endif
#ifdef EL2NSYNC
  [EL2NSYNC] = "EL2NSYNC",
#endif
#ifdef EL3HLT
  [EL3HLT] = "EL3HLT",
#endif
#ifdef EL3RST
  [EL3RST] = "EL3RST",
#endif
#ifdef ELIBACC
  [ELIBACC] = "ELIBACC",
#endif
#ifdef ELIBBAD
  [ELIBBAD] = "ELIBBAD",
#endif
#ifdef ELIBEXEC
  [ELIBEXEC] = "ELIBEXEC",
#endif
#ifdef ELIBMAX
  [ELIBMAX] = "ELIBMAX",
#endif
#ifdef ELIBSCN
  [ELIBSCN] = "ELIBSCN",
#endif
#ifdef ELNRNG
  [ELNRNG] = "ELNRNG",
#endif
#ifdef ELOOP
  [ELOOP] = "ELOOP",
#endif
#ifdef EMEDIUMTYPE
  [EMEDIUMTYPE] = "EMEDIUMTYPE",
#endif
#ifdef EMFILE
  [EMFILE] = "EMFILE",
#endif
#ifdef EMLINK
  [EMLINK] = "EMLINK",
#endif
#ifdef EMSGSIZE
  [EMSGSIZE] = "EMSGSIZE",
#endif
#ifdef EMULTIHOP
  [EMULTIHOP] = "EMULTIHOP",
#endif
#ifdef ENAMETOOLONG
  [ENAMETOOLONG] = "ENAMETOOLONG",
#endif
#ifdef ENAVAIL
  [ENAVAIL] = "ENAVAIL",
#endif
#ifdef ENETDOWN
  [ENETDOWN] = "ENETDOWN",
#endif
#ifdef ENETRESET
  [ENETRESET] = "ENETRESET",
#endif
#ifdef ENETUNREACH
  [ENETUNREACH] = "ENETUNREACH",
#endif
#ifdef ENFILE
  [ENFILE] = "ENFILE",
#endif
#ifdef ENOANO
  [ENOANO] = "ENOANO",
#endif
#ifdef ENOBUFS
  [ENOBUFS] = "ENOBUFS",
#endif
#ifdef ENOCSI
  [ENOCSI] = "ENOCSI",
#endif
#ifdef ENODATA
  [ENODATA] = "ENODATA",
#endif
#ifdef ENODEV
  [ENODEV] = "ENODEV",
#endif
#ifdef ENOENT
  [ENOENT] = "ENOENT",
#endif
#ifdef ENOEXEC
  [ENOEXEC] = "ENOEXEC",
#endif
#ifdef ENOKEY
  [ENOKEY] = "ENOKEY",
#endif
#ifdef ENOLCK
  [ENOLCK] = "ENOLCK",
#endif
#ifdef ENOLINK
  [ENOLINK] = "ENOLINK",
#endif
#ifdef ENOMEDIUM
  [ENOMEDIUM] = "ENOMEDIUM",
#endif
#ifdef ENOMEM
  [ENOMEM] = "ENOMEM",
#endif
#ifdef ENOMSG
  [ENOMSG] = "ENOMSG",
#endif
#ifdef ENONET
  [ENONET] = "ENONET",
#endif
#ifdef ENOPKG
  [ENOPKG] = "ENOPKG",
#endif
#ifdef ENOPROTOOPT
  [ENOPROTOOPT] = "ENOPROTOOPT",
#endif
#ifdef ENOSPC
  [ENOSPC] = "ENOSPC",
#endif
#ifdef ENOSR
  [ENOSR] = "ENOSR",
#endif
#ifdef ENOSTR
  [ENOSTR] = "ENOSTR",
#endif
#ifdef ENOSYS
  [ENOSYS] = "ENOSYS",
#endif
#ifdef ENOTBLK
  [ENOTBLK] = "ENOTBLK",
#endif
#ifdef ENOTCONN
  [ENOTCONN] = "ENOTCONN",
#endif
#ifdef ENOTDIR
  [ENOTDIR] = "ENOTDIR",
#endif
#ifdef ENOTEMPTY
  [ENOTEMPTY] = "ENOTEMPTY",
#endif
#ifdef ENOTNAM
  [ENOTNAM] = "ENOTNAM",
#endif
#ifdef ENOTRECOVERABLE
  [ENOTRECOVERABLE] = "ENOTRECOVERABLE",
#endif
#ifdef ENOTSOCK
  [ENOTSOCK] = "ENOTSOCK",
#endif
#ifdef ENOTSUP
  [ENOTSUP] = "ENOTSUP",
#endif
#ifdef ENOTTY
  [ENOTTY] = "ENOTTY",
#endif
#ifdef ENOTUNIQ
  [ENOTUNIQ] = "ENOTUNIQ",
#endif
#ifdef ENXIO
  [ENXIO] = "ENXIO",
#endif
#ifdef EOVERFLOW
  [EOVERFLOW] = "EOVERFLOW",
#endif
#ifdef EOWNERDEAD
  [EOWNERDEAD] = "EOWNERDEAD",
#endif
#ifdef EPERM
  [EPERM] = "EPERM",
#endif
#ifdef EPFNOSUPPORT
  [EPFNOSUPPORT] = "EPFNOSUPPORT",
#endif
#ifdef EPIPE
  [EPIPE] = "EPIPE",
#endif
#ifdef EPROTO
  [EPROTO] = "EPROTO",
#endif
#ifdef EPROTONOSUPPORT
  [EPROTONOSUPPORT] = "EPROTONOSUPPORT",
#endif
#ifdef EPROTOTYPE
  [EPROTOTYPE] = "EPROTOTYPE",
#endif
#ifdef ERANGE
  [ERANGE] = "ERANGE",
#endif
#ifdef EREMCHG
  [EREMCHG] = "EREMCHG",
#endif
#ifdef EREMOTE
  [EREMOTE] = "EREMOTE",
#endif
#ifdef EREMOTEIO
  [EREMOTEIO] = "EREMOTEIO",
#endif
#ifdef ERESTART
  [ERESTART] = "ERESTART",
#endif
#ifdef ERFKILL
  [ERFKILL] = "ERFKILL",
#endif
#ifdef EROFS
  [EROFS] = "EROFS",
#endif
#ifdef ESHUTDOWN
  [ESHUTDOWN] = "ESHUTDOWN",
#endif
#ifdef ESOCKTNOSUPPORT
  [ESOCKTNOSUPPORT] = "ESOCKTNOSUPPORT",
#endif
#ifdef ESPIPE
  [ESPIPE] = "ESPIPE",
#endif
#ifdef ESRCH
  [ESRCH] = "ESRCH",
#endif
#ifdef ESRMNT
  [ESRMNT] = "ESRMNT",
#endif
#ifdef ESTALE
  [ESTALE] = "ESTALE",
#endif
#ifdef ESTRPIPE
  [ESTRPIPE] = "ESTRPIPE",
#endif
#ifdef ETIME
  [ETIME] = "ETIME",
#endif
#ifdef ETIMEDOUT
  [ETIMEDOUT] = "ETIMEDOUT",
#endif
#ifdef ETOOMANYREFS
  [ETOOMANYREFS] = "ETOOMANYREFS",
#endif
#ifdef ETXTBSY
  [ETXTBSY] = "ETXTBSY",
#endif
#ifdef EUCLEAN
  [EUCLEAN] = "EUCLEAN",
#endif
#ifdef EUNATCH
  [EUNATCH] = "EUNATCH",
#endif
#ifdef EUSERS
  [EUSERS] = "EUSERS",
#endif
#ifdef EXDEV
  [EXDEV] = "EXDEV",
#endif
#ifdef EXFULL
  [EXFULL] = "EXFULL",
#endif
#ifdef EZZZ
  [EZZZ] = "EZZZ",
#endif
};

#define ERRNO_TO_STRING_SIZE \
  (sizeof errno_to_string / sizeof errno_to_string[0])

const char *
guestfs___errno_to_string (int errnum)
{
  /* See function documentation. */
  if (errnum == 0)
    abort ();

  if (errnum < 0 || (size_t) errnum >= ERRNO_TO_STRING_SIZE ||
      errno_to_string[errnum] == NULL)
    return "EINVAL";
  else
    return errno_to_string[errnum];
}

int
guestfs___string_to_errno (const char *errnostr)
{
  const struct errnostring_entry *v =
    guestfs___string_to_errno_lookup (errnostr, strlen (errnostr));
  if (v /* not necessary to check v->name != NULL here */)
    return v->errnum;
  else
    return EINVAL;
}
