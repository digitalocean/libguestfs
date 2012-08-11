/* ANSI-C code produced by gperf version 3.0.4 */
/* Command-line: gperf -t errnostring-gperf.gperf  */
/* Computed positions: -k'2-3,5-6' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 28 "errnostring-gperf.gperf"


#include <config.h>

#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "errnostring.h"

#ifndef E2BIG
#define E2BIG EINVAL
#endif
#ifndef EACCES
#define EACCES EINVAL
#endif
#ifndef EADDRINUSE
#define EADDRINUSE EINVAL
#endif
#ifndef EADDRNOTAVAIL
#define EADDRNOTAVAIL EINVAL
#endif
#ifndef EADV
#define EADV EINVAL
#endif
#ifndef EAFNOSUPPORT
#define EAFNOSUPPORT EINVAL
#endif
#ifndef EAGAIN
#define EAGAIN EINVAL
#endif
#ifndef EALREADY
#define EALREADY EINVAL
#endif
#ifndef EBADE
#define EBADE EINVAL
#endif
#ifndef EBADF
#define EBADF EINVAL
#endif
#ifndef EBADFD
#define EBADFD EINVAL
#endif
#ifndef EBADMSG
#define EBADMSG EINVAL
#endif
#ifndef EBADR
#define EBADR EINVAL
#endif
#ifndef EBADRQC
#define EBADRQC EINVAL
#endif
#ifndef EBADSLT
#define EBADSLT EINVAL
#endif
#ifndef EBFONT
#define EBFONT EINVAL
#endif
#ifndef EBUSY
#define EBUSY EINVAL
#endif
#ifndef ECANCELED
#define ECANCELED EINVAL
#endif
#ifndef ECHILD
#define ECHILD EINVAL
#endif
#ifndef ECHRNG
#define ECHRNG EINVAL
#endif
#ifndef ECOMM
#define ECOMM EINVAL
#endif
#ifndef ECONNABORTED
#define ECONNABORTED EINVAL
#endif
#ifndef ECONNREFUSED
#define ECONNREFUSED EINVAL
#endif
#ifndef ECONNRESET
#define ECONNRESET EINVAL
#endif
#ifndef EDEADLOCK
#define EDEADLOCK EINVAL
#endif
#ifndef EDESTADDRREQ
#define EDESTADDRREQ EINVAL
#endif
#ifndef EDOM
#define EDOM EINVAL
#endif
#ifndef EDOTDOT
#define EDOTDOT EINVAL
#endif
#ifndef EDQUOT
#define EDQUOT EINVAL
#endif
#ifndef EEXIST
#define EEXIST EINVAL
#endif
#ifndef EFAULT
#define EFAULT EINVAL
#endif
#ifndef EFBIG
#define EFBIG EINVAL
#endif
#ifndef EHOSTDOWN
#define EHOSTDOWN EINVAL
#endif
#ifndef EHOSTUNREACH
#define EHOSTUNREACH EINVAL
#endif
#ifndef EIDRM
#define EIDRM EINVAL
#endif
#ifndef EILSEQ
#define EILSEQ EINVAL
#endif
#ifndef EINPROGRESS
#define EINPROGRESS EINVAL
#endif
#ifndef EINTR
#define EINTR EINVAL
#endif
#ifndef EINVAL
#define EINVAL EINVAL
#endif
#ifndef EIO
#define EIO EINVAL
#endif
#ifndef EISCONN
#define EISCONN EINVAL
#endif
#ifndef EISDIR
#define EISDIR EINVAL
#endif
#ifndef EISNAM
#define EISNAM EINVAL
#endif
#ifndef EKEYEXPIRED
#define EKEYEXPIRED EINVAL
#endif
#ifndef EKEYREJECTED
#define EKEYREJECTED EINVAL
#endif
#ifndef EKEYREVOKED
#define EKEYREVOKED EINVAL
#endif
#ifndef EL2HLT
#define EL2HLT EINVAL
#endif
#ifndef EL2NSYNC
#define EL2NSYNC EINVAL
#endif
#ifndef EL3HLT
#define EL3HLT EINVAL
#endif
#ifndef EL3RST
#define EL3RST EINVAL
#endif
#ifndef ELIBACC
#define ELIBACC EINVAL
#endif
#ifndef ELIBBAD
#define ELIBBAD EINVAL
#endif
#ifndef ELIBEXEC
#define ELIBEXEC EINVAL
#endif
#ifndef ELIBMAX
#define ELIBMAX EINVAL
#endif
#ifndef ELIBSCN
#define ELIBSCN EINVAL
#endif
#ifndef ELNRNG
#define ELNRNG EINVAL
#endif
#ifndef ELOOP
#define ELOOP EINVAL
#endif
#ifndef EMEDIUMTYPE
#define EMEDIUMTYPE EINVAL
#endif
#ifndef EMFILE
#define EMFILE EINVAL
#endif
#ifndef EMLINK
#define EMLINK EINVAL
#endif
#ifndef EMSGSIZE
#define EMSGSIZE EINVAL
#endif
#ifndef EMULTIHOP
#define EMULTIHOP EINVAL
#endif
#ifndef ENAMETOOLONG
#define ENAMETOOLONG EINVAL
#endif
#ifndef ENAVAIL
#define ENAVAIL EINVAL
#endif
#ifndef ENETDOWN
#define ENETDOWN EINVAL
#endif
#ifndef ENETRESET
#define ENETRESET EINVAL
#endif
#ifndef ENETUNREACH
#define ENETUNREACH EINVAL
#endif
#ifndef ENFILE
#define ENFILE EINVAL
#endif
#ifndef ENOANO
#define ENOANO EINVAL
#endif
#ifndef ENOBUFS
#define ENOBUFS EINVAL
#endif
#ifndef ENOCSI
#define ENOCSI EINVAL
#endif
#ifndef ENODATA
#define ENODATA EINVAL
#endif
#ifndef ENODEV
#define ENODEV EINVAL
#endif
#ifndef ENOENT
#define ENOENT EINVAL
#endif
#ifndef ENOEXEC
#define ENOEXEC EINVAL
#endif
#ifndef ENOKEY
#define ENOKEY EINVAL
#endif
#ifndef ENOLCK
#define ENOLCK EINVAL
#endif
#ifndef ENOLINK
#define ENOLINK EINVAL
#endif
#ifndef ENOMEDIUM
#define ENOMEDIUM EINVAL
#endif
#ifndef ENOMEM
#define ENOMEM EINVAL
#endif
#ifndef ENOMSG
#define ENOMSG EINVAL
#endif
#ifndef ENONET
#define ENONET EINVAL
#endif
#ifndef ENOPKG
#define ENOPKG EINVAL
#endif
#ifndef ENOPROTOOPT
#define ENOPROTOOPT EINVAL
#endif
#ifndef ENOSPC
#define ENOSPC EINVAL
#endif
#ifndef ENOSR
#define ENOSR EINVAL
#endif
#ifndef ENOSTR
#define ENOSTR EINVAL
#endif
#ifndef ENOSYS
#define ENOSYS EINVAL
#endif
#ifndef ENOTBLK
#define ENOTBLK EINVAL
#endif
#ifndef ENOTCONN
#define ENOTCONN EINVAL
#endif
#ifndef ENOTDIR
#define ENOTDIR EINVAL
#endif
#ifndef ENOTEMPTY
#define ENOTEMPTY EINVAL
#endif
#ifndef ENOTNAM
#define ENOTNAM EINVAL
#endif
#ifndef ENOTRECOVERABLE
#define ENOTRECOVERABLE EINVAL
#endif
#ifndef ENOTSOCK
#define ENOTSOCK EINVAL
#endif
#ifndef ENOTSUP
#define ENOTSUP EINVAL
#endif
#ifndef ENOTTY
#define ENOTTY EINVAL
#endif
#ifndef ENOTUNIQ
#define ENOTUNIQ EINVAL
#endif
#ifndef ENXIO
#define ENXIO EINVAL
#endif
#ifndef EOVERFLOW
#define EOVERFLOW EINVAL
#endif
#ifndef EOWNERDEAD
#define EOWNERDEAD EINVAL
#endif
#ifndef EPERM
#define EPERM EINVAL
#endif
#ifndef EPFNOSUPPORT
#define EPFNOSUPPORT EINVAL
#endif
#ifndef EPIPE
#define EPIPE EINVAL
#endif
#ifndef EPROTO
#define EPROTO EINVAL
#endif
#ifndef EPROTONOSUPPORT
#define EPROTONOSUPPORT EINVAL
#endif
#ifndef EPROTOTYPE
#define EPROTOTYPE EINVAL
#endif
#ifndef ERANGE
#define ERANGE EINVAL
#endif
#ifndef EREMCHG
#define EREMCHG EINVAL
#endif
#ifndef EREMOTE
#define EREMOTE EINVAL
#endif
#ifndef EREMOTEIO
#define EREMOTEIO EINVAL
#endif
#ifndef ERESTART
#define ERESTART EINVAL
#endif
#ifndef ERFKILL
#define ERFKILL EINVAL
#endif
#ifndef EROFS
#define EROFS EINVAL
#endif
#ifndef ESHUTDOWN
#define ESHUTDOWN EINVAL
#endif
#ifndef ESOCKTNOSUPPORT
#define ESOCKTNOSUPPORT EINVAL
#endif
#ifndef ESPIPE
#define ESPIPE EINVAL
#endif
#ifndef ESRCH
#define ESRCH EINVAL
#endif
#ifndef ESRMNT
#define ESRMNT EINVAL
#endif
#ifndef ESTALE
#define ESTALE EINVAL
#endif
#ifndef ESTRPIPE
#define ESTRPIPE EINVAL
#endif
#ifndef ETIME
#define ETIME EINVAL
#endif
#ifndef ETIMEDOUT
#define ETIMEDOUT EINVAL
#endif
#ifndef ETOOMANYREFS
#define ETOOMANYREFS EINVAL
#endif
#ifndef ETXTBSY
#define ETXTBSY EINVAL
#endif
#ifndef EUCLEAN
#define EUCLEAN EINVAL
#endif
#ifndef EUNATCH
#define EUNATCH EINVAL
#endif
#ifndef EUSERS
#define EUSERS EINVAL
#endif
#ifndef EXDEV
#define EXDEV EINVAL
#endif
#ifndef EXFULL
#define EXFULL EINVAL
#endif
#ifndef EZZZ
#define EZZZ EINVAL
#endif

#line 434 "errnostring-gperf.gperf"
struct errnostring_entry;

#define TOTAL_KEYWORDS 131
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 15
#define MIN_HASH_VALUE 4
#define MAX_HASH_VALUE 360
/* maximum key range = 357, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
       15,  95, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361,  25, 105,  55,  10,  10,
       45, 205,  30,   5, 361, 135,  50,  45,   0,   0,
       75,  90,   5,  35,  20, 145,  25,   0, 160,  55,
        0, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361, 361, 361, 361, 361,
      361, 361, 361, 361, 361, 361
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[5]];
      /*FALLTHROUGH*/
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      /*FALLTHROUGH*/
      case 4:
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
        break;
    }
  return hval;
}

#ifdef __GNUC__
__inline
#if defined __GNUC_STDC_INLINE__ || defined __GNUC_GNU_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
const struct errnostring_entry *
guestfs___string_to_errno_lookup (register const char *str, register unsigned int len)
{
  static const struct errnostring_entry wordlist[] =
    {
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 567 "errnostring-gperf.gperf"
      {"EZZZ", EZZZ},
      {(char*)0},
#line 505 "errnostring-gperf.gperf"
      {"ENOANO", ENOANO},
      {(char*)0},
#line 476 "errnostring-gperf.gperf"
      {"EIO", EIO},
      {(char*)0},
#line 522 "errnostring-gperf.gperf"
      {"ENOSR", ENOSR},
      {(char*)0},
#line 514 "errnostring-gperf.gperf"
      {"ENOLINK", ENOLINK},
      {(char*)0},
#line 463 "errnostring-gperf.gperf"
      {"EDOM", EDOM},
#line 474 "errnostring-gperf.gperf"
      {"EINTR", EINTR},
#line 520 "errnostring-gperf.gperf"
      {"ENOPROTOOPT", ENOPROTOOPT},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 473 "errnostring-gperf.gperf"
      {"EINPROGRESS", EINPROGRESS},
#line 527 "errnostring-gperf.gperf"
      {"ENOTDIR", ENOTDIR},
      {(char*)0}, {(char*)0},
#line 537 "errnostring-gperf.gperf"
      {"EOWNERDEAD", EOWNERDEAD},
#line 510 "errnostring-gperf.gperf"
      {"ENOENT", ENOENT},
#line 464 "errnostring-gperf.gperf"
      {"EDOTDOT", EDOTDOT},
#line 501 "errnostring-gperf.gperf"
      {"ENETDOWN", ENETDOWN},
#line 515 "errnostring-gperf.gperf"
      {"ENOMEDIUM", ENOMEDIUM},
#line 530 "errnostring-gperf.gperf"
      {"ENOTRECOVERABLE", ENOTRECOVERABLE},
#line 523 "errnostring-gperf.gperf"
      {"ENOSTR", ENOSTR},
#line 529 "errnostring-gperf.gperf"
      {"ENOTNAM", ENOTNAM},
      {(char*)0},
#line 502 "errnostring-gperf.gperf"
      {"ENETRESET", ENETRESET},
      {(char*)0},
#line 518 "errnostring-gperf.gperf"
      {"ENONET", ENONET},
      {(char*)0}, {(char*)0},
#line 441 "errnostring-gperf.gperf"
      {"EADV", EADV},
#line 558 "errnostring-gperf.gperf"
      {"ETIME", ETIME},
#line 509 "errnostring-gperf.gperf"
      {"ENODEV", ENODEV},
#line 546 "errnostring-gperf.gperf"
      {"EREMOTE", EREMOTE},
#line 531 "errnostring-gperf.gperf"
      {"ENOTSOCK", ENOTSOCK},
#line 547 "errnostring-gperf.gperf"
      {"EREMOTEIO", EREMOTEIO},
#line 550 "errnostring-gperf.gperf"
      {"EROFS", EROFS},
#line 507 "errnostring-gperf.gperf"
      {"ENOCSI", ENOCSI},
#line 477 "errnostring-gperf.gperf"
      {"EISCONN", EISCONN},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 508 "errnostring-gperf.gperf"
      {"ENODATA", ENODATA},
#line 440 "errnostring-gperf.gperf"
      {"EADDRNOTAVAIL", EADDRNOTAVAIL},
#line 559 "errnostring-gperf.gperf"
      {"ETIMEDOUT", ETIMEDOUT},
#line 439 "errnostring-gperf.gperf"
      {"EADDRINUSE", EADDRINUSE},
#line 478 "errnostring-gperf.gperf"
      {"EISDIR", EISDIR},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 516 "errnostring-gperf.gperf"
      {"ENOMEM", ENOMEM},
#line 500 "errnostring-gperf.gperf"
      {"ENAVAIL", ENAVAIL},
#line 526 "errnostring-gperf.gperf"
      {"ENOTCONN", ENOTCONN},
#line 528 "errnostring-gperf.gperf"
      {"ENOTEMPTY", ENOTEMPTY},
#line 471 "errnostring-gperf.gperf"
      {"EIDRM", EIDRM},
#line 555 "errnostring-gperf.gperf"
      {"ESRMNT", ESRMNT},
#line 499 "errnostring-gperf.gperf"
      {"ENAMETOOLONG", ENAMETOOLONG},
#line 548 "errnostring-gperf.gperf"
      {"ERESTART", ERESTART},
#line 469 "errnostring-gperf.gperf"
      {"EHOSTDOWN", EHOSTDOWN},
#line 460 "errnostring-gperf.gperf"
      {"ECONNRESET", ECONNRESET},
#line 512 "errnostring-gperf.gperf"
      {"ENOKEY", ENOKEY},
#line 459 "errnostring-gperf.gperf"
      {"ECONNREFUSED", ECONNREFUSED},
      {(char*)0}, {(char*)0},
#line 554 "errnostring-gperf.gperf"
      {"ESRCH", ESRCH},
      {(char*)0},
#line 462 "errnostring-gperf.gperf"
      {"EDESTADDRREQ", EDESTADDRREQ},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 533 "errnostring-gperf.gperf"
      {"ENOTTY", ENOTTY},
      {(char*)0}, {(char*)0},
#line 536 "errnostring-gperf.gperf"
      {"EOVERFLOW", EOVERFLOW},
      {(char*)0},
#line 475 "errnostring-gperf.gperf"
      {"EINVAL", EINVAL},
      {(char*)0}, {(char*)0},
#line 461 "errnostring-gperf.gperf"
      {"EDEADLOCK", EDEADLOCK},
      {(char*)0}, {(char*)0},
#line 458 "errnostring-gperf.gperf"
      {"ECONNABORTED", ECONNABORTED},
      {(char*)0}, {(char*)0},
#line 540 "errnostring-gperf.gperf"
      {"EPIPE", EPIPE},
#line 524 "errnostring-gperf.gperf"
      {"ENOSYS", ENOSYS},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 560 "errnostring-gperf.gperf"
      {"ETOOMANYREFS", ETOOMANYREFS},
      {(char*)0},
#line 551 "errnostring-gperf.gperf"
      {"ESHUTDOWN", ESHUTDOWN},
#line 457 "errnostring-gperf.gperf"
      {"ECOMM", ECOMM},
#line 541 "errnostring-gperf.gperf"
      {"EPROTO", EPROTO},
#line 545 "errnostring-gperf.gperf"
      {"EREMCHG", EREMCHG},
      {(char*)0}, {(char*)0},
#line 543 "errnostring-gperf.gperf"
      {"EPROTOTYPE", EPROTOTYPE},
#line 504 "errnostring-gperf.gperf"
      {"ENFILE", ENFILE},
#line 549 "errnostring-gperf.gperf"
      {"ERFKILL", ERFKILL},
      {(char*)0}, {(char*)0},
#line 542 "errnostring-gperf.gperf"
      {"EPROTONOSUPPORT", EPROTONOSUPPORT},
#line 479 "errnostring-gperf.gperf"
      {"EISNAM", EISNAM},
#line 442 "errnostring-gperf.gperf"
      {"EAFNOSUPPORT", EAFNOSUPPORT},
#line 444 "errnostring-gperf.gperf"
      {"EALREADY", EALREADY},
      {(char*)0}, {(char*)0},
#line 556 "errnostring-gperf.gperf"
      {"ESTALE", ESTALE},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 465 "errnostring-gperf.gperf"
      {"EDQUOT", EDQUOT},
      {(char*)0},
#line 497 "errnostring-gperf.gperf"
      {"EMSGSIZE", EMSGSIZE},
      {(char*)0},
#line 493 "errnostring-gperf.gperf"
      {"ELOOP", ELOOP},
#line 438 "errnostring-gperf.gperf"
      {"EACCES", EACCES},
#line 490 "errnostring-gperf.gperf"
      {"ELIBMAX", ELIBMAX},
      {(char*)0}, {(char*)0},
#line 538 "errnostring-gperf.gperf"
      {"EPERM", EPERM},
#line 521 "errnostring-gperf.gperf"
      {"ENOSPC", ENOSPC},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 449 "errnostring-gperf.gperf"
      {"EBADR", EBADR},
#line 483 "errnostring-gperf.gperf"
      {"EL2HLT", EL2HLT},
#line 487 "errnostring-gperf.gperf"
      {"ELIBACC", ELIBACC},
#line 557 "errnostring-gperf.gperf"
      {"ESTRPIPE", ESTRPIPE},
      {(char*)0},
#line 445 "errnostring-gperf.gperf"
      {"EBADE", EBADE},
#line 467 "errnostring-gperf.gperf"
      {"EFAULT", EFAULT},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 455 "errnostring-gperf.gperf"
      {"ECHILD", ECHILD},
#line 491 "errnostring-gperf.gperf"
      {"ELIBSCN", ELIBSCN},
#line 534 "errnostring-gperf.gperf"
      {"ENOTUNIQ", ENOTUNIQ},
#line 454 "errnostring-gperf.gperf"
      {"ECANCELED", ECANCELED},
      {(char*)0},
#line 495 "errnostring-gperf.gperf"
      {"EMFILE", EMFILE},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 472 "errnostring-gperf.gperf"
      {"EILSEQ", EILSEQ},
#line 525 "errnostring-gperf.gperf"
      {"ENOTBLK", ENOTBLK},
#line 484 "errnostring-gperf.gperf"
      {"EL2NSYNC", EL2NSYNC},
      {(char*)0},
#line 535 "errnostring-gperf.gperf"
      {"ENXIO", ENXIO},
#line 503 "errnostring-gperf.gperf"
      {"ENETUNREACH", ENETUNREACH},
#line 539 "errnostring-gperf.gperf"
      {"EPFNOSUPPORT", EPFNOSUPPORT},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 482 "errnostring-gperf.gperf"
      {"EKEYREVOKED", EKEYREVOKED},
#line 481 "errnostring-gperf.gperf"
      {"EKEYREJECTED", EKEYREJECTED},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 452 "errnostring-gperf.gperf"
      {"EBFONT", EBFONT},
#line 511 "errnostring-gperf.gperf"
      {"ENOEXEC", ENOEXEC},
      {(char*)0}, {(char*)0},
#line 446 "errnostring-gperf.gperf"
      {"EBADF", EBADF},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 532 "errnostring-gperf.gperf"
      {"ENOTSUP", ENOTSUP},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 447 "errnostring-gperf.gperf"
      {"EBADFD", EBADFD},
#line 488 "errnostring-gperf.gperf"
      {"ELIBBAD", ELIBBAD},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 513 "errnostring-gperf.gperf"
      {"ENOLCK", ENOLCK},
#line 506 "errnostring-gperf.gperf"
      {"ENOBUFS", ENOBUFS},
      {(char*)0}, {(char*)0},
#line 565 "errnostring-gperf.gperf"
      {"EXDEV", EXDEV},
#line 553 "errnostring-gperf.gperf"
      {"ESPIPE", ESPIPE},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 552 "errnostring-gperf.gperf"
      {"ESOCKTNOSUPPORT", ESOCKTNOSUPPORT},
#line 486 "errnostring-gperf.gperf"
      {"EL3RST", EL3RST},
#line 470 "errnostring-gperf.gperf"
      {"EHOSTUNREACH", EHOSTUNREACH},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 494 "errnostring-gperf.gperf"
      {"EMEDIUMTYPE", EMEDIUMTYPE},
#line 448 "errnostring-gperf.gperf"
      {"EBADMSG", EBADMSG},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 485 "errnostring-gperf.gperf"
      {"EL3HLT", EL3HLT},
#line 451 "errnostring-gperf.gperf"
      {"EBADSLT", EBADSLT},
      {(char*)0},
#line 498 "errnostring-gperf.gperf"
      {"EMULTIHOP", EMULTIHOP},
      {(char*)0},
#line 564 "errnostring-gperf.gperf"
      {"EUSERS", EUSERS},
#line 563 "errnostring-gperf.gperf"
      {"EUNATCH", EUNATCH},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 466 "errnostring-gperf.gperf"
      {"EEXIST", EEXIST},
#line 450 "errnostring-gperf.gperf"
      {"EBADRQC", EBADRQC},
#line 489 "errnostring-gperf.gperf"
      {"ELIBEXEC", ELIBEXEC},
      {(char*)0}, {(char*)0},
#line 496 "errnostring-gperf.gperf"
      {"EMLINK", EMLINK},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 443 "errnostring-gperf.gperf"
      {"EAGAIN", EAGAIN},
#line 562 "errnostring-gperf.gperf"
      {"EUCLEAN", EUCLEAN},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 517 "errnostring-gperf.gperf"
      {"ENOMSG", ENOMSG},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 544 "errnostring-gperf.gperf"
      {"ERANGE", ERANGE},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 492 "errnostring-gperf.gperf"
      {"ELNRNG", ELNRNG},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 456 "errnostring-gperf.gperf"
      {"ECHRNG", ECHRNG},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 453 "errnostring-gperf.gperf"
      {"EBUSY", EBUSY},
#line 566 "errnostring-gperf.gperf"
      {"EXFULL", EXFULL},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 480 "errnostring-gperf.gperf"
      {"EKEYEXPIRED", EKEYEXPIRED},
#line 561 "errnostring-gperf.gperf"
      {"ETXTBSY", ETXTBSY},
      {(char*)0}, {(char*)0},
#line 437 "errnostring-gperf.gperf"
      {"E2BIG", E2BIG},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 519 "errnostring-gperf.gperf"
      {"ENOPKG", ENOPKG},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 468 "errnostring-gperf.gperf"
      {"EFBIG", EFBIG}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].name;

          if (s && *str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
