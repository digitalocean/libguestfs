/* libguestfs
 * Copyright (C) 2009-2011 Red Hat Inc.
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

#ifndef GUESTFS_INTERNAL_H_
#define GUESTFS_INTERNAL_H_

#include <rpc/types.h>
#include <rpc/xdr.h>

#include <pcre.h>

#define STREQ(a,b) (strcmp((a),(b)) == 0)
#define STRCASEEQ(a,b) (strcasecmp((a),(b)) == 0)
#define STRNEQ(a,b) (strcmp((a),(b)) != 0)
#define STRCASENEQ(a,b) (strcasecmp((a),(b)) != 0)
#define STREQLEN(a,b,n) (strncmp((a),(b),(n)) == 0)
#define STRCASEEQLEN(a,b,n) (strncasecmp((a),(b),(n)) == 0)
#define STRNEQLEN(a,b,n) (strncmp((a),(b),(n)) != 0)
#define STRCASENEQLEN(a,b,n) (strncasecmp((a),(b),(n)) != 0)
#define STRPREFIX(a,b) (strncmp((a),(b),strlen((b))) == 0)

#ifdef HAVE_GETTEXT
#include "gettext.h"
#define _(str) dgettext(PACKAGE, (str))
#define N_(str) dgettext(PACKAGE, (str))
#else
#define _(str) str
#define N_(str) str
#endif

#define TMP_TEMPLATE_ON_STACK(var)                        \
  const char *ttos_tmpdir = guestfs_tmpdir ();            \
  char var[strlen (ttos_tmpdir) + 32];                    \
  sprintf (var, "%s/libguestfsXXXXXX", ttos_tmpdir)       \

#define UNIX_PATH_MAX 108

#ifndef MAX
#define MAX(a,b) ((a)>(b)?(a):(b))
#endif

#ifdef __APPLE__
#define xdr_uint32_t xdr_u_int32_t
#endif

/* Some limits on what the inspection code will read, for safety. */

/* Small text configuration files.
 *
 * The upper limit is for general files that we grep or download.  The
 * largest such file is probably "txtsetup.sif" from Windows CDs
 * (~500K).  This number has to be larger than any legitimate file and
 * smaller than the protocol message size.
 *
 * The lower limit is for files parsed by Augeas on the daemon side,
 * where Augeas is running in reduced memory and can potentially
 * create a lot of metadata so we really need to be careful about
 * those.
 */
#define MAX_SMALL_FILE_SIZE    (2 * 1000 * 1000)
#define MAX_AUGEAS_FILE_SIZE        (100 * 1000)

/* Maximum Windows Registry hive that we will download to /tmp.  Some
 * registries can be legitimately very large.
 */
#define MAX_REGISTRY_SIZE    (100 * 1000 * 1000)

/* Maximum RPM or dpkg database we will download to /tmp.  RPM
 * 'Packages' database can get very large: 70 MB is roughly the
 * standard size for a new Fedora install, and after lots of package
 * installation/removal I have seen well over 100 MB databases.
 */
#define MAX_PKG_DB_SIZE       (300 * 1000 * 1000)

/* Maximum size of Windows explorer.exe.  2.6MB on Windows 7. */
#define MAX_WINDOWS_EXPLORER_SIZE (4 * 1000 * 1000)

/* Network configuration of the appliance.  Note these addresses are
 * only meaningful within the context of the running appliance.  QEMU
 * translates network connections to these magic addresses into
 * userspace calls on the host (eg. connect(2)).  qemu-doc has a nice
 * diagram which is also useful to refer to.
 *
 * NETWORK: The network.
 *
 * ROUTER: The address of the "host", ie. this library.
 *
 * [Note: If you change NETWORK and ROUTER then you also have to
 * change the network configuration in appliance/init].
 *
 * GUESTFWD_ADDR, GUESTFWD_PORT: The guestfwd feature of qemu
 * magically connects this pseudo-address to the guestfwd channel.  In
 * typical Linux configurations of libguestfs, guestfwd is not
 * actually used any more.
 */
#define NETWORK "169.254.0.0/16"
#define ROUTER "169.254.2.2"

/* GuestFS handle and connection. */
enum state { CONFIG, LAUNCHING, READY, BUSY, NO_HANDLE };

/* Attach method. */
enum attach_method { ATTACH_METHOD_APPLIANCE = 0, ATTACH_METHOD_UNIX };

/* Event. */
struct event {
  uint64_t event_bitmask;
  guestfs_event_callback cb;
  void *opaque;

  /* opaque2 is not exposed through the API, but is used internally to
   * emulate the old-style callback API.
   */
  void *opaque2;
};

struct guestfs_h
{
  struct guestfs_h *next;	/* Linked list of open handles. */

  /* State: see the state machine diagram in the man page guestfs(3). */
  enum state state;

  int fd[2];			/* Stdin/stdout of qemu. */
  int sock;			/* Daemon communications socket. */
  pid_t pid;			/* Qemu PID. */
  pid_t recoverypid;		/* Recovery process PID. */

  struct timeval launch_t;      /* The time that we called guestfs_launch. */

  char *tmpdir;			/* Temporary directory containing socket. */

  char *qemu_help, *qemu_version; /* Output of qemu -help, qemu -version. */

  char **cmdline;		/* Qemu command line. */
  size_t cmdline_size;

  int verbose;
  int trace;
  int autosync;
  int direct;
  int recovery_proc;
  int enable_network;

  char *path;			/* Path to kernel, initrd. */
  char *qemu;			/* Qemu binary. */
  char *append;			/* Append to kernel command line. */

  enum attach_method attach_method;
  char *attach_method_arg;

  int memsize;			/* Size of RAM (megabytes). */

  int selinux;                  /* selinux enabled? */

  int pgroup;                   /* Create process group for children? */

  char *last_error;
  int last_errnum;              /* errno, or 0 if there was no errno */

  /* Callbacks. */
  guestfs_abort_cb           abort_cb;
  guestfs_error_handler_cb   error_cb;
  void *                     error_cb_data;

  /* Events. */
  struct event *events;
  size_t nr_events;

  int msg_next_serial;

  /* Information gathered by inspect_os.  Must be freed by calling
   * guestfs___free_inspect_info.
   */
  struct inspect_fs *fses;
  size_t nr_fses;

  /* Private data area. */
  struct hash_table *pda;
  struct pda_entry *pda_next;

  /* Used by src/actions.c:trace_* functions. */
  FILE *trace_fp;
  char *trace_buf;
  size_t trace_len;

  /* User cancelled transfer.  Not signal-atomic, but it doesn't
   * matter for this case because we only care if it is != 0.
   */
  int user_cancel;
};

/* Per-filesystem data stored for inspect_os. */
enum inspect_fs_content {
  FS_CONTENT_UNKNOWN = 0,
  FS_CONTENT_LINUX_ROOT,
  FS_CONTENT_WINDOWS_ROOT,
  FS_CONTENT_WINDOWS_VOLUME_WITH_APPS,
  FS_CONTENT_WINDOWS_VOLUME,
  FS_CONTENT_LINUX_BOOT,
  FS_CONTENT_LINUX_USR,
  FS_CONTENT_LINUX_USR_LOCAL,
  FS_CONTENT_LINUX_VAR,
  FS_CONTENT_FREEBSD_ROOT,
  FS_CONTENT_INSTALLER,
};

enum inspect_os_format {
  OS_FORMAT_UNKNOWN = 0,
  OS_FORMAT_INSTALLED,
  OS_FORMAT_INSTALLER,
  /* in future: supplemental disks */
};

enum inspect_os_type {
  OS_TYPE_UNKNOWN = 0,
  OS_TYPE_LINUX,
  OS_TYPE_WINDOWS,
  OS_TYPE_FREEBSD,
};

enum inspect_os_distro {
  OS_DISTRO_UNKNOWN = 0,
  OS_DISTRO_DEBIAN,
  OS_DISTRO_FEDORA,
  OS_DISTRO_REDHAT_BASED,
  OS_DISTRO_RHEL,
  OS_DISTRO_WINDOWS,
  OS_DISTRO_PARDUS,
  OS_DISTRO_ARCHLINUX,
  OS_DISTRO_GENTOO,
  OS_DISTRO_UBUNTU,
  OS_DISTRO_MEEGO,
  OS_DISTRO_LINUX_MINT,
  OS_DISTRO_MANDRIVA,
  OS_DISTRO_SLACKWARE,
  OS_DISTRO_CENTOS,
  OS_DISTRO_SCIENTIFIC_LINUX,
};

enum inspect_os_package_format {
  OS_PACKAGE_FORMAT_UNKNOWN = 0,
  OS_PACKAGE_FORMAT_RPM,
  OS_PACKAGE_FORMAT_DEB,
  OS_PACKAGE_FORMAT_PACMAN,
  OS_PACKAGE_FORMAT_EBUILD,
  OS_PACKAGE_FORMAT_PISI
};

enum inspect_os_package_management {
  OS_PACKAGE_MANAGEMENT_UNKNOWN = 0,
  OS_PACKAGE_MANAGEMENT_YUM,
  OS_PACKAGE_MANAGEMENT_UP2DATE,
  OS_PACKAGE_MANAGEMENT_APT,
  OS_PACKAGE_MANAGEMENT_PACMAN,
  OS_PACKAGE_MANAGEMENT_PORTAGE,
  OS_PACKAGE_MANAGEMENT_PISI,
  OS_PACKAGE_MANAGEMENT_URPMI,
};

struct inspect_fs {
  int is_root;
  char *device;
  int is_mountable;
  int is_swap;
  enum inspect_fs_content content;
  enum inspect_os_type type;
  enum inspect_os_distro distro;
  enum inspect_os_package_format package_format;
  enum inspect_os_package_management package_management;
  char *product_name;
  char *product_variant;
  int major_version;
  int minor_version;
  char *arch;
  char *hostname;
  char *windows_systemroot;
  char *windows_current_control_set;
  char **drive_mappings;
  enum inspect_os_format format;
  int is_live_disk;
  int is_netinst_disk;
  int is_multipart_disk;
  struct inspect_fstab_entry *fstab;
  size_t nr_fstab;
};

struct inspect_fstab_entry {
  char *device;
  char *mountpoint;
};

struct guestfs_message_header;
struct guestfs_message_error;
struct guestfs_progress;

extern void guestfs_error (guestfs_h *g, const char *fs, ...)
  __attribute__((format (printf,2,3)));
extern void guestfs_error_errno (guestfs_h *g, int errnum, const char *fs, ...)
  __attribute__((format (printf,3,4)));
extern void guestfs_perrorf (guestfs_h *g, const char *fs, ...)
  __attribute__((format (printf,2,3)));
extern void *guestfs_safe_realloc (guestfs_h *g, void *ptr, int nbytes);
extern char *guestfs_safe_strdup (guestfs_h *g, const char *str);
extern char *guestfs_safe_strndup (guestfs_h *g, const char *str, size_t n);
extern void *guestfs_safe_memdup (guestfs_h *g, void *ptr, size_t size);
extern char *guestfs_safe_asprintf (guestfs_h *g, const char *fs, ...)
  __attribute__((format (printf,2,3)));
extern void guestfs___warning (guestfs_h *g, const char *fs, ...)
  __attribute__((format (printf,2,3)));
extern void guestfs___debug (guestfs_h *g, const char *fs, ...)
  __attribute__((format (printf,2,3)));
extern void guestfs___trace (guestfs_h *g, const char *fs, ...)
  __attribute__((format (printf,2,3)));
extern const char *guestfs___persistent_tmpdir (void);
extern void guestfs___print_timestamped_argv (guestfs_h *g, const char *argv[]);
extern void guestfs___print_timestamped_message (guestfs_h *g, const char *fs, ...);
extern void guestfs___free_inspect_info (guestfs_h *g);
extern int guestfs___set_busy (guestfs_h *g);
extern int guestfs___end_busy (guestfs_h *g);
extern int guestfs___send (guestfs_h *g, int proc_nr, uint64_t progress_hint, uint64_t optargs_bitmask, xdrproc_t xdrp, char *args);
extern int guestfs___recv (guestfs_h *g, const char *fn, struct guestfs_message_header *hdr, struct guestfs_message_error *err, xdrproc_t xdrp, char *ret);
extern int guestfs___recv_discard (guestfs_h *g, const char *fn);
extern int guestfs___send_file (guestfs_h *g, const char *filename);
extern int guestfs___recv_file (guestfs_h *g, const char *filename);
extern int guestfs___send_to_daemon (guestfs_h *g, const void *v_buf, size_t n);
extern int guestfs___recv_from_daemon (guestfs_h *g, uint32_t *size_rtn, void **buf_rtn);
extern int guestfs___accept_from_daemon (guestfs_h *g);
extern void guestfs___progress_message_callback (guestfs_h *g, const struct guestfs_progress *message);
extern int guestfs___build_appliance (guestfs_h *g, char **kernel, char **initrd, char **appliance);
extern void guestfs___launch_send_progress (guestfs_h *g, int perdozen);
extern void guestfs___print_BufferIn (FILE *out, const char *buf, size_t buf_size);
extern void guestfs___print_BufferOut (FILE *out, const char *buf, size_t buf_size);
extern int guestfs___match (guestfs_h *g, const char *str, const pcre *re);
extern char *guestfs___match1 (guestfs_h *g, const char *str, const pcre *re);
extern int guestfs___match2 (guestfs_h *g, const char *str, const pcre *re, char **ret1, char **ret2);
extern int guestfs___match3 (guestfs_h *g, const char *str, const pcre *re, char **ret1, char **ret2, char **ret3);
extern int guestfs___feature_available (guestfs_h *g, const char *feature);
extern void guestfs___free_string_list (char **);
extern size_t guestfs___checkpoint_cmdline (guestfs_h *g);
extern void guestfs___rollback_cmdline (guestfs_h *g, size_t pos);
extern void guestfs___call_callbacks_void (guestfs_h *g, uint64_t event);
extern void guestfs___call_callbacks_message (guestfs_h *g, uint64_t event, const char *buf, size_t buf_len);
extern void guestfs___call_callbacks_array (guestfs_h *g, uint64_t event, const uint64_t *array, size_t array_len);
extern int guestfs___is_file_nocase (guestfs_h *g, const char *);
extern int guestfs___is_dir_nocase (guestfs_h *g, const char *);
#if defined(HAVE_HIVEX)
extern int guestfs___check_for_filesystem_on (guestfs_h *g, const char *device, int is_block, int is_partnum);
extern char *guestfs___download_to_tmp (guestfs_h *g, struct inspect_fs *fs, const char *filename, const char *basename, int64_t max_size);
extern char *guestfs___case_sensitive_path_silently (guestfs_h *g, const char *);
extern struct inspect_fs *guestfs___search_for_root (guestfs_h *g, const char *root);
extern int guestfs___parse_unsigned_int (guestfs_h *g, const char *str);
extern int guestfs___parse_unsigned_int_ignore_trailing (guestfs_h *g, const char *str);
extern int guestfs___parse_major_minor (guestfs_h *g, struct inspect_fs *fs);
extern char *guestfs___first_line_of_file (guestfs_h *g, const char *filename);
extern int guestfs___first_egrep_of_file (guestfs_h *g, const char *filename, const char *eregex, int iflag, char **ret);
typedef int (*guestfs___db_dump_callback) (guestfs_h *g, const unsigned char *key, size_t keylen, const unsigned char *value, size_t valuelen, void *opaque);
extern int guestfs___read_db_dump (guestfs_h *g, const char *dumpfile, void *opaque, guestfs___db_dump_callback callback);
extern int guestfs___check_installer_root (guestfs_h *g, struct inspect_fs *fs);
extern int guestfs___check_linux_root (guestfs_h *g, struct inspect_fs *fs);
extern int guestfs___check_freebsd_root (guestfs_h *g, struct inspect_fs *fs);
extern int guestfs___has_windows_systemroot (guestfs_h *g);
extern int guestfs___check_windows_root (guestfs_h *g, struct inspect_fs *fs);
#endif

#define error(g,...) guestfs_error_errno((g),0,__VA_ARGS__)
#define perrorf guestfs_perrorf
#define warning(g,...) guestfs___warning((g),__VA_ARGS__)
#define debug(g,...) \
  do { if ((g)->verbose) guestfs___debug ((g),__VA_ARGS__); } while (0)
#define safe_calloc guestfs_safe_calloc
#define safe_malloc guestfs_safe_malloc
#define safe_realloc guestfs_safe_realloc
#define safe_strdup guestfs_safe_strdup
#define safe_strndup guestfs_safe_strndup
#define safe_memdup guestfs_safe_memdup
#define safe_asprintf guestfs_safe_asprintf
#define match guestfs___match
#define match1 guestfs___match1
#define match2 guestfs___match2
#define match3 guestfs___match3

#endif /* GUESTFS_INTERNAL_H_ */
