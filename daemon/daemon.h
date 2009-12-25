/* libguestfs - the guestfsd daemon
 * Copyright (C) 2009 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef GUESTFSD_DAEMON_H
#define GUESTFSD_DAEMON_H

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>

#include <rpc/types.h>
#include <rpc/xdr.h>

#include "../src/guestfs_protocol.h"

/*-- in guestfsd.c --*/
extern int verbose;

extern const char *sysroot;
extern int sysroot_len;

extern char *sysroot_path (const char *path);

extern int xwrite (int sock, const void *buf, size_t len)
  __attribute__((__warn_unused_result__));
extern int xread (int sock, void *buf, size_t len)
  __attribute__((__warn_unused_result__));

extern int add_string (char ***argv, int *size, int *alloc, const char *str);
extern int count_strings (char *const *argv);
extern void sort_strings (char **argv, int len);
extern void free_strings (char **argv);
extern void free_stringslen (char **argv, int len);

#define command(out,err,name,...) commandf((out),(err),0,(name),__VA_ARGS__)
#define commandr(out,err,name,...) commandrf((out),(err),0,(name),__VA_ARGS__)
#define commandv(out,err,argv) commandvf((out),(err),0,(argv))
#define commandrv(out,err,argv) commandrvf((out),(err),0,(argv))

#define COMMAND_FLAG_FOLD_STDOUT_ON_STDERR 1

extern int commandf (char **stdoutput, char **stderror, int flags,
                     const char *name, ...);
extern int commandrf (char **stdoutput, char **stderror, int flags,
                      const char *name, ...);
extern int commandvf (char **stdoutput, char **stderror, int flags,
                      char const *const *argv);
extern int commandrvf (char **stdoutput, char **stderror, int flags,
                       char const* const *argv);

extern char **split_lines (char *str);

extern int device_name_translation (char *device, const char *func);

extern void udev_settle (void);

/* This just stops gcc from giving a warning about our custom
 * printf formatters %Q and %R.  See HACKING file for more
 * info about these.
 */
static inline int
asprintf_nowarn (char **strp, const char *fmt, ...)
{
  int r;
  va_list args;

  va_start (args, fmt);
  r = vasprintf (strp, fmt, args);
  va_end (args);
  return r;
}

/*-- in names.c (auto-generated) --*/
extern const char *function_names[];

/*-- in proto.c --*/
extern int proc_nr;
extern int serial;

/*-- in mount.c --*/
extern int root_mounted;

/*-- in stubs.c (auto-generated) --*/
extern void dispatch_incoming_message (XDR *);
extern guestfs_int_lvm_pv_list *parse_command_line_pvs (void);
extern guestfs_int_lvm_vg_list *parse_command_line_vgs (void);
extern guestfs_int_lvm_lv_list *parse_command_line_lvs (void);

/*-- in optgroups.c (auto-generated) --*/
struct optgroup {
  const char *group;            /* Name of the optional group. */
  int (*available) (void);      /* Function to test availability. */
};
extern struct optgroup optgroups[];

/*-- in sync.c --*/
/* Use this as a replacement for sync(2). */
extern int sync_disks (void);

/*-- in proto.c --*/
extern void main_loop (int sock) __attribute__((noreturn));

/* ordinary daemon functions use these to indicate errors */
extern void reply_with_error (const char *fs, ...)
  __attribute__((format (printf,1,2)));
extern void reply_with_perror_errno (int err, const char *fs, ...)
  __attribute__((format (printf,2,3)));
#define reply_with_perror(...) reply_with_perror_errno(errno, __VA_ARGS__)

/* daemon functions that receive files (FileIn) should call
 * receive_file for each FileIn parameter.
 */
typedef int (*receive_cb) (void *opaque, const void *buf, int len);
extern int receive_file (receive_cb cb, void *opaque);

/* daemon functions that receive files (FileIn) can call this
 * to cancel incoming transfers (eg. if there is a local error),
 * but they MUST then call reply_with_*.
 */
extern void cancel_receive (void);

/* daemon functions that return files (FileOut) should call
 * reply, then send_file_* for each FileOut parameter.
 * Note max write size if GUESTFS_MAX_CHUNK_SIZE.
 */
extern int send_file_write (const void *buf, int len);
extern int send_file_end (int cancel);

/* only call this if there is a FileOut parameter */
extern void reply (xdrproc_t xdrp, char *ret);

/* Helper for functions that need a root filesystem mounted.
 * NB. Cannot be used for FileIn functions.
 */
#define NEED_ROOT(fail_stmt)						\
  do {									\
    if (!root_mounted) {						\
      reply_with_error ("%s: you must call 'mount' first to mount the root filesystem", __func__); \
      fail_stmt;							\
    }									\
  }									\
  while (0)

/* Helper for functions that need an argument ("path") that is absolute.
 * NB. Cannot be used for FileIn functions.
 */
#define ABS_PATH(path,fail_stmt)					\
  do {									\
    if ((path)[0] != '/') {						\
      reply_with_error ("%s: path must start with a / character", __func__); \
      fail_stmt;							\
    }									\
  } while (0)

/* All functions that need an argument that is a device or partition name
 * must call this macro.  It checks that the device exists and does
 * device name translation (described in the guestfs(3) manpage).
 * Note that the "path" argument may be modified.
 *
 * NB. Cannot be used for FileIn functions.
 */
#define RESOLVE_DEVICE(path,fail_stmt)					\
  do {									\
    if (STRNEQLEN ((path), "/dev/", 5)) {				\
      reply_with_error ("%s: %s: expecting a device name", __func__, (path)); \
      fail_stmt;							\
    }									\
    if (device_name_translation ((path), __func__) == -1)		\
      fail_stmt;							\
  } while (0)

/* Helper for functions which need either an absolute path in the
 * mounted filesystem, OR a /dev/ device which exists.
 *
 * NB. Cannot be used for FileIn functions.
 *
 * NB #2: Functions which mix filenames and device paths should be
 * avoided, and existing functions should be deprecated.  This is
 * because we intend in future to make device parameters a distinct
 * type from filenames.
 */
#define REQUIRE_ROOT_OR_RESOLVE_DEVICE(path,fail_stmt)			\
  do {									\
    if (STREQLEN ((path), "/dev/", 5))                                  \
      RESOLVE_DEVICE ((path), fail_stmt);				\
    else {								\
      NEED_ROOT (fail_stmt);						\
      ABS_PATH ((path),fail_stmt);					\
    }									\
  } while (0)

/* NB:
 * (1) You must match CHROOT_IN and CHROOT_OUT even along error paths.
 * (2) You must not change directory!  cwd must always be "/", otherwise
 *     we can't escape our own chroot.
 * (3) All paths specified must be absolute.
 * (4) Neither macro affects errno.
 */
#define CHROOT_IN				\
  do {						\
    int __old_errno = errno;			\
    if (chroot (sysroot) == -1)			\
      perror ("CHROOT_IN: sysroot");		\
    errno = __old_errno;			\
  } while (0)
#define CHROOT_OUT				\
  do {						\
    int __old_errno = errno;			\
    if (chroot (".") == -1)			\
      perror ("CHROOT_OUT: .");			\
    errno = __old_errno;			\
  } while (0)

/* Marks functions which are not implemented.
 * NB. Cannot be used for FileIn functions.
 */
#define XXX_NOT_IMPL(errcode)						\
  do {									\
    reply_with_error ("%s: function not implemented", __func__);	\
    return (errcode);							\
  }									\
  while (0)

/* Marks functions which are not available.
 * NB. Cannot be used for FileIn functions.
 */
#define NOT_AVAILABLE(errcode)                                          \
  do {									\
    reply_with_error ("%s: function not available", __func__);          \
    return (errcode);							\
  }									\
  while (0)

#ifndef __attribute__
# if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 8)
#  define __attribute__(x) /* empty */
# endif
#endif

#ifndef ATTRIBUTE_UNUSED
# define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
#endif

#define STREQ(a,b) (strcmp((a),(b)) == 0)
#define STRCASEEQ(a,b) (strcasecmp((a),(b)) == 0)
#define STRNEQ(a,b) (strcmp((a),(b)) != 0)
#define STRCASENEQ(a,b) (strcasecmp((a),(b)) != 0)
#define STREQLEN(a,b,n) (strncmp((a),(b),(n)) == 0)
#define STRCASEEQLEN(a,b,n) (strncasecmp((a),(b),(n)) == 0)
#define STRNEQLEN(a,b,n) (strncmp((a),(b),(n)) != 0)
#define STRCASENEQLEN(a,b,n) (strncasecmp((a),(b),(n)) != 0)
#define STRPREFIX(a,b) (strncmp((a),(b),strlen((b))) == 0)

#endif /* GUESTFSD_DAEMON_H */
