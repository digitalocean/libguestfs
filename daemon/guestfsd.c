/* libguestfs - the guestfsd daemon
 * Copyright (C) 2009-2014 Red Hat Inc.
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#ifdef HAVE_WINDOWS_H
# include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <rpc/types.h>
#include <rpc/xdr.h>
#include <getopt.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <netdb.h>
#include <sys/select.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <assert.h>
#include <termios.h>

#ifdef HAVE_PRINTF_H
# include <printf.h>
#endif

#include <augeas.h>

#include "sockets.h"
#include "c-ctype.h"
#include "ignore-value.h"
#include "error.h"

#include "daemon.h"

GUESTFSD_EXT_CMD(str_udevadm, udevadm);

static char *read_cmdline (void);

#ifndef MAX
# define MAX(a,b) ((a)>(b)?(a):(b))
#endif

/* Not the end of the world if this open flag is not defined. */
#ifndef O_CLOEXEC
# define O_CLOEXEC 0
#endif

/* For improved readability dealing with pipe arrays */
#define PIPE_READ 0
#define PIPE_WRITE 1

/* If root device is an ext2 filesystem, this is the major and minor.
 * This is so we can ignore this device from the point of view of the
 * user, eg. in guestfs_list_devices and many other places.
 */
static dev_t root_device = 0;

int verbose = 0;
int enable_network = 0;

static void makeraw (const char *channel, int fd);
static int print_shell_quote (FILE *stream, const struct printf_info *info, const void *const *args);
static int print_sysroot_shell_quote (FILE *stream, const struct printf_info *info, const void *const *args);
#ifdef HAVE_REGISTER_PRINTF_SPECIFIER
static int print_arginfo (const struct printf_info *info, size_t n, int *argtypes, int *size);
#else
#ifdef HAVE_REGISTER_PRINTF_FUNCTION
static int print_arginfo (const struct printf_info *info, size_t n, int *argtypes);
#else
#error "HAVE_REGISTER_PRINTF_{SPECIFIER|FUNCTION} not defined"
#endif
#endif

#ifdef WIN32
static int
winsock_init (void)
{
  int r;

  /* http://msdn2.microsoft.com/en-us/library/ms742213.aspx */
  r = gl_sockets_startup (SOCKETS_2_2);
  return r == 0 ? 0 : -1;
}
#else /* !WIN32 */
static int
winsock_init (void)
{
  return 0;
}
#endif /* !WIN32 */

/* Location to mount root device. */
const char *sysroot = "/sysroot"; /* No trailing slash. */
size_t sysroot_len = 8;

/* If set (the default), do 'umount-all' when performing autosync. */
int autosync_umount = 1;

/* Not used explicitly, but required by the gnulib 'error' module. */
const char *program_name = "guestfsd";

/* Name of the virtio-serial channel. */
#define VIRTIO_SERIAL_CHANNEL "/dev/virtio-ports/org.libguestfs.channel.0"

static void
usage (void)
{
  fprintf (stderr,
    "guestfsd [-r] [-v|--verbose]\n");
}

int
main (int argc, char *argv[])
{
  static const char *options = "rv?";
  static const struct option long_options[] = {
    { "help", 0, 0, '?' },
    { "verbose", 0, 0, 'v' },
    { 0, 0, 0, 0 }
  };
  int c;
  char *cmdline;

  ignore_value (chdir ("/"));

  if (winsock_init () == -1)
    error (EXIT_FAILURE, 0, "winsock initialization failed");

#ifdef HAVE_REGISTER_PRINTF_SPECIFIER
  /* http://udrepper.livejournal.com/20948.html */
  register_printf_specifier ('Q', print_shell_quote, print_arginfo);
  register_printf_specifier ('R', print_sysroot_shell_quote, print_arginfo);
#else
#ifdef HAVE_REGISTER_PRINTF_FUNCTION
  register_printf_function ('Q', print_shell_quote, print_arginfo);
  register_printf_function ('R', print_sysroot_shell_quote, print_arginfo);
#else
#error "HAVE_REGISTER_PRINTF_{SPECIFIER|FUNCTION} not defined"
#endif
#endif

  /* XXX The appliance /init script sets LD_PRELOAD=../libSegFault.so.
   * However if we CHROOT_IN to the sysroot that file might not exist,
   * resulting in all commands failing.  What we'd really like to do
   * is to have LD_PRELOAD only set while outside the chroot.  I
   * suspect the proper way to solve this is to remove the
   * CHROOT_IN/_OUT hack and replace it properly (fork), but that is
   * for another day.
   */
  unsetenv ("LD_PRELOAD");

  struct stat statbuf;
  if (stat ("/", &statbuf) == 0)
    root_device = statbuf.st_dev;

  for (;;) {
    c = getopt_long (argc, argv, options, long_options, NULL);
    if (c == -1) break;

    switch (c) {
      /* The -r flag is used when running standalone.  It changes
       * several aspects of the daemon.
       */
    case 'r':
      sysroot = "";
      sysroot_len = 0;
      autosync_umount = 0;
      break;

    case 'v':
      verbose = 1;
      break;

    case '?':
      usage ();
      exit (EXIT_SUCCESS);

    default:
      fprintf (stderr, "guestfsd: unexpected command line option 0x%x\n", c);
      exit (EXIT_FAILURE);
    }
  }

  if (optind < argc) {
    usage ();
    exit (EXIT_FAILURE);
  }

  cmdline = read_cmdline ();

  /* Set the verbose flag. */
  verbose = verbose ||
    (cmdline && strstr (cmdline, "guestfs_verbose=1") != NULL);
  if (verbose)
    printf ("verbose daemon enabled\n");

  if (verbose) {
    if (cmdline)
      printf ("linux commmand line: %s\n", cmdline);
    else
      printf ("could not read linux command line\n");
  }

  enable_network = cmdline && strstr (cmdline, "guestfs_network=1") != NULL;

#ifndef WIN32
  /* Make sure SIGPIPE doesn't kill us. */
  struct sigaction sa;
  memset (&sa, 0, sizeof sa);
  sa.sa_handler = SIG_IGN;
  sa.sa_flags = 0;
  if (sigaction (SIGPIPE, &sa, NULL) == -1)
    perror ("sigaction SIGPIPE"); /* but try to continue anyway ... */
#endif

#ifdef WIN32
# define setenv(n,v,f) _putenv(n "=" v)
#endif
  /* Set up a basic environment.  After we are called by /init the
   * environment is essentially empty.
   * https://bugzilla.redhat.com/show_bug.cgi?id=502074#c5
   *
   * NOTE: if you change $PATH, you must also change 'prog_exists'
   * function below.
   */
  setenv ("PATH", "/sbin:/usr/sbin:/bin:/usr/bin", 1);
  setenv ("SHELL", "/bin/sh", 1);
  setenv ("LC_ALL", "C", 1);
  setenv ("TERM", "dumb", 1);

#ifndef WIN32
  /* We document that umask defaults to 022 (it should be this anyway). */
  umask (022);
#else
  /* This is the default for Windows anyway.  It's not even clear if
   * Windows ever uses this -- the MSDN documentation for the function
   * contains obvious errors.
   */
  _umask (0);
#endif

  /* Make a private copy of /etc/lvm so we can change the config (see
   * daemon/lvm-filter.c).
   */
  copy_lvm ();

  /* Connect to virtio-serial channel. */
  char *channel, *p;
  if (cmdline && (p = strstr (cmdline, "guestfs_channel=")) != NULL) {
    p += 16;
    channel = strndup (p, strcspn (p, " \n"));
  }
  else
    channel = strdup (VIRTIO_SERIAL_CHANNEL);
  if (!channel) {
    perror ("strdup");
    exit (EXIT_FAILURE);
  }

  if (verbose)
    printf ("trying to open virtio-serial channel '%s'\n", channel);

  int sock = open (channel, O_RDWR|O_CLOEXEC);
  if (sock == -1) {
    fprintf (stderr,
             "\n"
             "Failed to connect to virtio-serial channel.\n"
             "\n"
             "This is a fatal error and the appliance will now exit.\n"
             "\n"
             "Usually this error is caused by either QEMU or the appliance\n"
             "kernel not supporting the vmchannel method that the\n"
             "libguestfs library chose to use.  Please run\n"
             "'libguestfs-test-tool' and provide the complete, unedited\n"
             "output to the libguestfs developers, either in a bug report\n"
             "or on the libguestfs redhat com mailing list.\n"
             "\n");
    perror (channel);
    exit (EXIT_FAILURE);
  }

  /* If it's a serial-port like device then it probably has echoing
   * enabled.  Put it into complete raw mode.
   */
  if (STRPREFIX (channel, "/dev/ttyS"))
    makeraw (channel, sock);

  /* cmdline, channel not used after this point */
  free (cmdline);
  free (channel);

  /* Wait for udev devices to be created.  If you start libguestfs,
   * especially with disks that contain complex (eg. mdadm) data
   * already, then it is possible for the 'mdadm' and LVM commands
   * that the init script runs to have not completed by the time the
   * daemon starts executing library commands.  (This is very rare and
   * hard to test however, but we have seen it in 'brew').  Run
   * udev_settle, but do it as late as possible to minimize the chance
   * that we'll have to do any waiting here.
   */
  udev_settle ();

  /* Send the magic length message which indicates that
   * userspace is up inside the guest.
   */
  char lenbuf[4];
  XDR xdr;
  uint32_t len = GUESTFS_LAUNCH_FLAG;
  xdrmem_create (&xdr, lenbuf, sizeof lenbuf, XDR_ENCODE);
  xdr_u_int (&xdr, &len);

  if (xwrite (sock, lenbuf, sizeof lenbuf) == -1) {
    perror ("xwrite");
    exit (EXIT_FAILURE);
  }

  xdr_destroy (&xdr);

  /* Enter the main loop, reading and performing actions. */
  main_loop (sock);

  exit (EXIT_SUCCESS);
}

/* Read /proc/cmdline. */
static char *
read_cmdline (void)
{
  int fd = open ("/proc/cmdline", O_RDONLY|O_CLOEXEC);
  if (fd == -1) {
    perror ("/proc/cmdline");
    return NULL;
  }

  size_t len = 0;
  ssize_t n;
  char buf[256];
  char *r = NULL;

  for (;;) {
    n = read (fd, buf, sizeof buf);
    if (n == -1) {
      perror ("read");
      free (r);
      close (fd);
      return NULL;
    }
    if (n == 0)
      break;
    char *newr = realloc (r, len + n + 1); /* + 1 is for terminating NUL */
    if (newr == NULL) {
      perror ("realloc");
      free (r);
      close (fd);
      return NULL;
    }
    r = newr;
    memcpy (&r[len], buf, n);
    len += n;
  }

  if (r)
    r[len] = '\0';

  if (close (fd) == -1) {
    perror ("close");
    free (r);
    return NULL;
  }

  return r;
}

/* Try to make the socket raw, but don't fail if it's not possible. */
static void
makeraw (const char *channel, int fd)
{
  struct termios tt;

  if (tcgetattr (fd, &tt) == -1) {
    fprintf (stderr, "tcgetattr: ");
    perror (channel);
    return;
  }

  cfmakeraw (&tt);
  if (tcsetattr (fd, TCSANOW, &tt) == -1) {
    fprintf (stderr, "tcsetattr: ");
    perror (channel);
  }
}

/* Return true iff device is the root device (and therefore should be
 * ignored from the point of view of user calls).
 */
static int
is_root_device_stat (struct stat *statbuf)
{
  if (statbuf->st_rdev == root_device) return 1;
  return 0;
}

int
is_root_device (const char *device)
{
  struct stat statbuf;
  if (stat (device, &statbuf) == -1) {
    perror (device);
    return 0;
  }

  return is_root_device_stat (&statbuf);
}

/* Turn "/path" into "/sysroot/path".
 *
 * Caller must check for NULL and call reply_with_perror ("malloc")
 * if it is.  Caller must also free the string.
 *
 * See also the custom %R printf formatter which does shell quoting too.
 */
char *
sysroot_path (const char *path)
{
  char *r;
  size_t len = strlen (path) + sysroot_len + 1;

  r = malloc (len);
  if (r == NULL)
    return NULL;

  snprintf (r, len, "%s%s", sysroot, path);
  return r;
}

/* Resolve path within sysroot, calling sysroot_path on the resolved path.
 *
 * Caller must check for NULL and call reply_with_perror ("malloc/realpath")
 * if it is.  Caller must also free the string.
 *
 * See also the custom %R printf formatter which does shell quoting too.
 */
char *
sysroot_realpath (const char *path)
{
  CLEANUP_FREE char *rp = NULL;

  CHROOT_IN;
  rp = realpath (path, NULL);
  CHROOT_OUT;
  if (rp == NULL)
    return NULL;

  return sysroot_path (rp);
}

int
xwrite (int sock, const void *v_buf, size_t len)
{
  ssize_t r;
  const char *buf = v_buf;

  while (len > 0) {
    r = write (sock, buf, len);
    if (r == -1) {
      perror ("write");
      return -1;
    }
    buf += r;
    len -= r;
  }

  return 0;
}

int
xread (int sock, void *v_buf, size_t len)
{
  int r;
  char *buf = v_buf;

  while (len > 0) {
    r = read (sock, buf, len);
    if (r == -1) {
      perror ("read");
      return -1;
    }
    if (r == 0) {
      fprintf (stderr, "read: unexpected end of file on fd %d\n", sock);
      return -1;
    }
    buf += r;
    len -= r;
  }

  return 0;
}

int
add_string_nodup (struct stringsbuf *sb, char *str)
{
  char **new_argv;

  if (sb->size >= sb->alloc) {
    sb->alloc += 64;
    new_argv = realloc (sb->argv, sb->alloc * sizeof (char *));
    if (new_argv == NULL) {
      reply_with_perror ("realloc");
      free_stringslen (sb->argv, sb->size);
      sb->argv = NULL;
      return -1;
    }
    sb->argv = new_argv;
  }

  sb->argv[sb->size] = str;
  sb->size++;

  return 0;
}

int
add_string (struct stringsbuf *sb, const char *str)
{
  char *new_str = NULL;

  if (str) {
    new_str = strdup (str);
    if (new_str == NULL) {
      reply_with_perror ("strdup");
      free_stringslen (sb->argv, sb->size);
      sb->argv = NULL;
      return -1;
    }
  }

  return add_string_nodup (sb, new_str);
}

int
add_sprintf (struct stringsbuf *sb, const char *fs, ...)
{
  va_list args;
  char *str;
  int r;

  va_start (args, fs);
  r = vasprintf (&str, fs, args);
  va_end (args);
  if (r == -1) {
    reply_with_perror ("vasprintf");
    free_stringslen (sb->argv, sb->size);
    sb->argv = NULL;
    return -1;
  }

  return add_string_nodup (sb, str);
}

int
end_stringsbuf (struct stringsbuf *sb)
{
  return add_string_nodup (sb, NULL);
}

size_t
count_strings (char *const *argv)
{
  size_t argc;

  for (argc = 0; argv[argc] != NULL; ++argc)
    ;
  return argc;
}

/* http://graphics.stanford.edu/~seander/bithacks.html#DetermineIfPowerOf2 */
int
is_power_of_2 (unsigned long v)
{
  return v && ((v & (v - 1)) == 0);
}

static int
compare (const void *vp1, const void *vp2)
{
  char * const *p1 = (char * const *) vp1;
  char * const *p2 = (char * const *) vp2;
  return strcmp (*p1, *p2);
}

void
sort_strings (char **argv, size_t len)
{
  qsort (argv, len, sizeof (char *), compare);
}

void
free_strings (char **argv)
{
  size_t argc;

  if (!argv)
    return;

  for (argc = 0; argv[argc] != NULL; ++argc)
    free (argv[argc]);
  free (argv);
}

void
free_stringslen (char **argv, size_t len)
{
  size_t i;

  if (!argv)
    return;

  for (i = 0; i < len; ++i)
    free (argv[i]);
  free (argv);
}

/* Compare device names (including partition numbers if present).
 * https://rwmj.wordpress.com/2011/01/09/how-are-linux-drives-named-beyond-drive-26-devsdz/
 */
int
compare_device_names (const char *a, const char *b)
{
  size_t alen, blen;
  int r;
  int a_partnum, b_partnum;

  /* Skip /dev/ prefix if present. */
  if (STRPREFIX (a, "/dev/"))
    a += 5;
  if (STRPREFIX (b, "/dev/"))
    b += 5;

  /* Skip sd/hd/ubd/vd. */
  alen = strcspn (a, "d");
  blen = strcspn (b, "d");
  assert (alen > 0 && alen <= 2);
  assert (blen > 0 && blen <= 2);
  a += alen + 1;
  b += blen + 1;

  /* Get device name part, that is, just 'a', 'ab' etc. */
  alen = strcspn (a, "0123456789");
  blen = strcspn (b, "0123456789");

  /* If device name part is longer, it is always greater, eg.
   * "/dev/sdz" < "/dev/sdaa".
   */
  if (alen != blen)
    return alen - blen;

  /* Device name parts are the same length, so do a regular compare. */
  r = strncmp (a, b, alen);
  if (r != 0)
    return r;

  /* Compare partitions numbers. */
  a += alen;
  b += alen;

  /* If no partition numbers, bail -- the devices are the same.  This
   * can happen in one peculiar case: where you have a mix of devices
   * with different interfaces (eg. /dev/sda and /dev/vda).
   * (RHBZ#858128).
   */
  if (!*a && !*b)
    return 0;

  r = sscanf (a, "%d", &a_partnum);
  assert (r == 1);
  r = sscanf (b, "%d", &b_partnum);
  assert (r == 1);

  return a_partnum - b_partnum;
}

static int
compare_device_names_vp (const void *vp1, const void *vp2)
{
  char * const *p1 = (char * const *) vp1;
  char * const *p2 = (char * const *) vp2;
  return compare_device_names (*p1, *p2);
}

void
sort_device_names (char **argv, size_t len)
{
  qsort (argv, len, sizeof (char *), compare_device_names_vp);
}

char *
concat_strings (char *const *argv)
{
  return join_strings ("", argv);
}

char *
join_strings (const char *separator, char *const *argv)
{
  size_t i, len, seplen, rlen;
  char *r;

  seplen = strlen (separator);

  len = 0;
  for (i = 0; argv[i] != NULL; ++i) {
    if (i > 0)
      len += seplen;
    len += strlen (argv[i]);
  }
  len++; /* for final \0 */

  r = malloc (len);
  if (r == NULL)
    return NULL;

  rlen = 0;
  for (i = 0; argv[i] != NULL; ++i) {
    if (i > 0) {
      memcpy (&r[rlen], separator, seplen);
      rlen += seplen;
    }
    len = strlen (argv[i]);
    memcpy (&r[rlen], argv[i], len);
    rlen += len;
  }
  r[rlen] = '\0';

  return r;
}

/* Easy ways to run external commands.  For full documentation, see
 * 'commandrvf' below.
 */
int
commandf (char **stdoutput, char **stderror, int flags, const char *name, ...)
{
  va_list args;
  /* NB: Mustn't free the strings which are on the stack. */
  CLEANUP_FREE const char **argv = NULL;
  char *s;
  size_t i;
  int r;

  /* Collect the command line arguments into an array. */
  i = 2;
  argv = malloc (sizeof (char *) * i);
  if (argv == NULL) {
    perror ("malloc");
    return -1;
  }
  argv[0] = (char *) name;
  argv[1] = NULL;

  va_start (args, name);

  while ((s = va_arg (args, char *)) != NULL) {
    const char **p = realloc (argv, sizeof (char *) * (++i));
    if (p == NULL) {
      perror ("realloc");
      va_end (args);
      return -1;
    }
    argv = p;
    argv[i-2] = s;
    argv[i-1] = NULL;
  }

  va_end (args);

  r = commandvf (stdoutput, stderror, flags, (const char * const*) argv);

  return r;
}

/* Same as 'command', but we allow the status code from the
 * subcommand to be non-zero, and return that status code.
 * We still return -1 if there was some other error.
 */
int
commandrf (char **stdoutput, char **stderror, int flags, const char *name, ...)
{
  va_list args;
  CLEANUP_FREE const char **argv = NULL;
  char *s;
  int i, r;

  /* Collect the command line arguments into an array. */
  i = 2;
  argv = malloc (sizeof (char *) * i);
  if (argv == NULL) {
    perror ("malloc");
    return -1;
  }
  argv[0] = (char *) name;
  argv[1] = NULL;

  va_start (args, name);

  while ((s = va_arg (args, char *)) != NULL) {
    const char **p = realloc (argv, sizeof (char *) * (++i));
    if (p == NULL) {
      perror ("realloc");
      va_end (args);
      return -1;
    }
    argv = p;
    argv[i-2] = s;
    argv[i-1] = NULL;
  }

  va_end (args);

  r = commandrvf (stdoutput, stderror, flags, argv);

  return r;
}

/* Same as 'command', but passing an argv. */
int
commandvf (char **stdoutput, char **stderror, int flags,
           char const *const *argv)
{
  int r;

  r = commandrvf (stdoutput, stderror, flags, (void *) argv);
  if (r == 0)
    return 0;
  else
    return -1;
}

/* This is a more sane version of 'system(3)' for running external
 * commands.  It uses fork/execvp, so we don't need to worry about
 * quoting of parameters, and it allows us to capture any error
 * messages in a buffer.
 *
 * If stdoutput is not NULL, then *stdoutput will return the stdout
 * of the command.
 *
 * If stderror is not NULL, then *stderror will return the stderr
 * of the command.  If there is a final \n character, it is removed
 * so you can use the error string directly in a call to
 * reply_with_error.
 *
 * Flags:
 *
 * COMMAND_FLAG_FOLD_STDOUT_ON_STDERR: For broken external commands
 * that send error messages to stdout (hello, parted) but that don't
 * have any useful stdout information, use this flag to capture the
 * error messages in the *stderror buffer.  If using this flag,
 * you should pass stdoutput as NULL because nothing could ever be
 * captured in that buffer.
 *
 * COMMAND_FLAG_CHROOT_COPY_FILE_TO_STDIN: For running external
 * commands on chrooted files correctly (see RHBZ#579608) specifying
 * this flag causes another process to be forked which chroots into
 * sysroot and just copies the input file to stdin of the specified
 * command.  The file descriptor is ORed with the flags, and that file
 * descriptor is always closed by this function.  See hexdump.c for an
 * example of usage.
 */
int
commandrvf (char **stdoutput, char **stderror, int flags,
            char const* const *argv)
{
  size_t so_size = 0, se_size = 0;
  int so_fd[2], se_fd[2];
  int flag_copy_stdin = flags & COMMAND_FLAG_CHROOT_COPY_FILE_TO_STDIN;
  int flag_copy_fd = flags & COMMAND_FLAG_FD_MASK;
  pid_t pid;
  int r, quit, i;
  fd_set rset, rset2;
  char buf[256];
  char *p;

  if (stdoutput) *stdoutput = NULL;
  if (stderror) *stderror = NULL;

  if (verbose) {
    printf ("%s", argv[0]);
    for (i = 1; argv[i] != NULL; ++i)
      printf (" %s", argv[i]);
    printf ("\n");
  }

  /* Note: abort is used in a few places along the error paths early
   * in this function.  This is because (a) cleaning up correctly is
   * very complex at these places and (b) abort is used when a
   * resource problems is indicated which would be due to much more
   * serious issues - eg. memory or file descriptor leaks.  We
   * wouldn't expect fork(2) or pipe(2) to fail in normal
   * circumstances.
   */

  if (pipe (so_fd) == -1 || pipe (se_fd) == -1) {
    error (0, errno, "pipe");
    abort ();
  }

  pid = fork ();
  if (pid == -1) {
    error (0, errno, "fork");
    abort ();
  }

  if (pid == 0) {		/* Child process running the command. */
    signal (SIGALRM, SIG_DFL);
    signal (SIGPIPE, SIG_DFL);
    close (0);
    if (flag_copy_stdin) {
      dup2 (flag_copy_fd, STDIN_FILENO);
    } else {
      /* Set stdin to /dev/null (ignore failure) */
      ignore_value (open ("/dev/null", O_RDONLY|O_CLOEXEC));
    }
    close (so_fd[PIPE_READ]);
    close (se_fd[PIPE_READ]);
    if (!(flags & COMMAND_FLAG_FOLD_STDOUT_ON_STDERR))
      dup2 (so_fd[PIPE_WRITE], STDOUT_FILENO);
    else
      dup2 (se_fd[PIPE_WRITE], STDOUT_FILENO);
    dup2 (se_fd[PIPE_WRITE], STDERR_FILENO);
    close (so_fd[PIPE_WRITE]);
    close (se_fd[PIPE_WRITE]);

    ignore_value (chdir ("/"));

    execvp (argv[0], (void *) argv);
    perror (argv[0]);
    _exit (EXIT_FAILURE);
  }

  /* Parent process. */
  close (so_fd[PIPE_WRITE]);
  close (se_fd[PIPE_WRITE]);

  FD_ZERO (&rset);
  FD_SET (so_fd[PIPE_READ], &rset);
  FD_SET (se_fd[PIPE_READ], &rset);

  quit = 0;
  while (quit < 2) {
  again:
    rset2 = rset;
    r = select (MAX (so_fd[PIPE_READ], se_fd[PIPE_READ]) + 1, &rset2,
                NULL, NULL, NULL);
    if (r == -1) {
      if (errno == EINTR)
        goto again;

      perror ("select");
    quit:
      if (stdoutput) {
        free (*stdoutput);
        *stdoutput = NULL;
      }
      if (stderror) {
        free (*stderror);
        /* Need to return non-NULL *stderror here since most callers
         * will try to print and then free the err string.
         * Unfortunately recovery from strdup failure here is not
         * possible.
         */
        *stderror = strdup ("error running external command, "
                            "see debug output for details");
      }
      close (so_fd[PIPE_READ]);
      close (se_fd[PIPE_READ]);
      if (flag_copy_stdin) close (flag_copy_fd);
      waitpid (pid, NULL, 0);
      return -1;
    }

    if (FD_ISSET (so_fd[PIPE_READ], &rset2)) { /* something on stdout */
      r = read (so_fd[PIPE_READ], buf, sizeof buf);
      if (r == -1) {
        perror ("read");
        goto quit;
      }
      if (r == 0) { FD_CLR (so_fd[PIPE_READ], &rset); quit++; }

      if (r > 0 && stdoutput) {
        so_size += r;
        p = realloc (*stdoutput, so_size);
        if (p == NULL) {
          perror ("realloc");
          goto quit;
        }
        *stdoutput = p;
        memcpy (*stdoutput + so_size - r, buf, r);
      }
    }

    if (FD_ISSET (se_fd[PIPE_READ], &rset2)) { /* something on stderr */
      r = read (se_fd[PIPE_READ], buf, sizeof buf);
      if (r == -1) {
        perror ("read");
        goto quit;
      }
      if (r == 0) { FD_CLR (se_fd[PIPE_READ], &rset); quit++; }

      if (r > 0) {
        if (verbose)
          ignore_value (write (STDERR_FILENO, buf, r));

        if (stderror) {
          se_size += r;
          p = realloc (*stderror, se_size);
          if (p == NULL) {
            perror ("realloc");
            goto quit;
          }
          *stderror = p;
          memcpy (*stderror + se_size - r, buf, r);
        }
      }
    }
  }

  close (so_fd[PIPE_READ]);
  close (se_fd[PIPE_READ]);

  /* Make sure the output buffers are \0-terminated.  Also remove any
   * trailing \n characters from the error buffer (not from stdout).
   */
  if (stdoutput) {
    void *q = realloc (*stdoutput, so_size+1);
    if (q == NULL) {
      perror ("realloc");
      free (*stdoutput);
    }
    *stdoutput = q;
    if (*stdoutput)
      (*stdoutput)[so_size] = '\0';
  }
  if (stderror) {
    void *q = realloc (*stderror, se_size+1);
    if (q == NULL) {
      perror ("realloc");
      free (*stderror);
    }
    *stderror = q;
    if (*stderror) {
      (*stderror)[se_size] = '\0';
      while (se_size > 0 && (*stderror)[se_size-1] == '\n') {
        se_size--;
        (*stderror)[se_size] = '\0';
      }
    }
  }

  if (flag_copy_stdin && close (flag_copy_fd) == -1) {
    perror ("close");
    return -1;
  }

  /* Get the exit status of the command. */
  if (waitpid (pid, &r, 0) != pid) {
    perror ("waitpid");
    return -1;
  }

  if (WIFEXITED (r)) {
    return WEXITSTATUS (r);
  } else
    return -1;
}

/* Split an output string into a NULL-terminated list of lines.
 * Typically this is used where we have run an external command
 * which has printed out a list of things, and we want to return
 * an actual list.
 *
 * The corner cases here are quite tricky.  Note in particular:
 *
 *   "" -> []
 *   "\n" -> [""]
 *   "a\nb" -> ["a"; "b"]
 *   "a\nb\n" -> ["a"; "b"]
 *   "a\nb\n\n" -> ["a"; "b"; ""]
 *
 * The original string is written over and destroyed by this
 * function (which is usually OK because it's the 'out' string
 * from command()).  You can free the original string, because
 * add_string() strdups the strings.
 */
char **
split_lines (char *str)
{
  DECLARE_STRINGSBUF (lines);
  char *p, *pend;

  if (STREQ (str, ""))
    return empty_list ();

  p = str;
  while (p) {
    /* Empty last line? */
    if (p[0] == '\0')
      break;

    pend = strchr (p, '\n');
    if (pend) {
      *pend = '\0';
      pend++;
    }

    if (add_string (&lines, p) == -1) {
      return NULL;
    }

    p = pend;
  }

  if (end_stringsbuf (&lines) == -1)
    return NULL;

  return lines.argv;
}

char **
empty_list (void)
{
  DECLARE_STRINGSBUF (ret);

  if (end_stringsbuf (&ret) == -1)
    return NULL;

  return ret.argv;
}

/* Skip leading and trailing whitespace, updating the original string
 * in-place.
 */
void
trim (char *str)
{
  size_t len = strlen (str);

  while (len > 0 && c_isspace (str[len-1])) {
    str[len-1] = '\0';
    len--;
  }

  const char *p = str;
  while (*p && c_isspace (*p)) {
    p++;
    len--;
  }

  memmove (str, p, len+1);
}

/* printf helper function so we can use %Q ("quoted") and %R to print
 * shell-quoted strings.  See guestfs(3)/EXTENDING LIBGUESTFS for more
 * details.
 */
static int
print_shell_quote (FILE *stream,
                   const struct printf_info *info ATTRIBUTE_UNUSED,
                   const void *const *args)
{
#define SAFE(c) (c_isalnum((c)) ||					\
                 (c) == '/' || (c) == '-' || (c) == '_' || (c) == '.')
  int i, len;
  const char *str = *((const char **) (args[0]));

  for (i = len = 0; str[i]; ++i) {
    if (!SAFE(str[i])) {
      putc ('\\', stream);
      len ++;
    }
    putc (str[i], stream);
    len ++;
  }

  return len;
}

static int
print_sysroot_shell_quote (FILE *stream,
                           const struct printf_info *info,
                           const void *const *args)
{
  fputs (sysroot, stream);
  return sysroot_len + print_shell_quote (stream, info, args);
}

#ifdef HAVE_REGISTER_PRINTF_SPECIFIER
static int
print_arginfo (const struct printf_info *info ATTRIBUTE_UNUSED,
               size_t n, int *argtypes, int *size)
{
  if (n > 0) {
    argtypes[0] = PA_STRING;
    size[0] = sizeof (const char *);
  }
  return 1;
}
#else
#ifdef HAVE_REGISTER_PRINTF_FUNCTION
static int
print_arginfo (const struct printf_info *info, size_t n, int *argtypes)
{
  if (n > 0)
    argtypes[0] = PA_STRING;
  return 1;
}
#else
#error "HAVE_REGISTER_PRINTF_{SPECIFIER|FUNCTION} not defined"
#endif
#endif

/* Perform device name translation.  See guestfs(3) for the algorithm.
 * Usually you should not call this directly.
 *
 * It returns a newly allocated string which the caller must free.
 *
 * It returns NULL on error.  *Note* it does *NOT* call reply_with_*.
 *
 * We have to open the device and test for ENXIO, because the device
 * nodes may exist in the appliance.
 */
char *
device_name_translation (const char *device)
{
  int fd;
  char *ret;

  fd = open (device, O_RDONLY|O_CLOEXEC);
  if (fd >= 0) {
    close (fd);
    return strdup (device);
  }

  if (errno != ENXIO && errno != ENOENT)
    return NULL;

  /* If the name begins with "/dev/sd" then try the alternatives. */
  if (!STRPREFIX (device, "/dev/sd"))
    return NULL;
  device += 7;                  /* device == "a1" etc. */

  /* /dev/vd (virtio-blk) */
  if (asprintf (&ret, "/dev/vd%s", device) == -1)
    return NULL;
  fd = open (ret, O_RDONLY|O_CLOEXEC);
  if (fd >= 0) {
    close (fd);
    return ret;
  }
  free (ret);

  /* /dev/hd (old IDE driver) */
  if (asprintf (&ret, "/dev/hd%s", device) == -1)
    return NULL;
  fd = open (ret, O_RDONLY|O_CLOEXEC);
  if (fd >= 0) {
    close (fd);
    return ret;
  }
  free (ret);

  /* User-Mode Linux */
  if (asprintf (&ret, "/dev/ubd%s", device) == -1)
    return NULL;
  fd = open (ret, O_RDONLY|O_CLOEXEC);
  if (fd >= 0) {
    close (fd);
    return ret;
  }
  free (ret);

  return NULL;
}

/* Parse the mountable descriptor for a btrfs subvolume.  Don't call
 * this directly; it is only used from the stubs.
 *
 * A btrfs subvolume is given as:
 *
 * btrfsvol:/dev/sda3/root
 *
 * where /dev/sda3 is a block device containing a btrfs filesystem,
 * and root is the name of a subvolume on it. This function is passed
 * the string following 'btrfsvol:'.
 *
 * On success, mountable->device & mountable->volume must be freed by
 * the caller.
 */
int
parse_btrfsvol (const char *desc_orig, mountable_t *mountable)
{
  size_t len = strlen (desc_orig);
  char desc[len+1];
  CLEANUP_FREE char *device = NULL;
  const char *volume = NULL;
  char *slash;
  struct stat statbuf;

  mountable->type = MOUNTABLE_BTRFSVOL;

  memcpy (desc, desc_orig, len+1);

  if (! STRPREFIX (desc, "/dev/"))
    return -1;

  slash = desc + strlen ("/dev/") - 1;
  while ((slash = strchr (slash + 1, '/'))) {
    *slash = '\0';

    free (device);
    device = device_name_translation (desc);
    if (!device) {
      perror (desc);
      continue;
    }

    if (stat (device, &statbuf) == -1) {
      perror (device);
      return -1;
    }

    if (!S_ISDIR (statbuf.st_mode) &&
        !is_root_device_stat (&statbuf)) {
      volume = slash + 1;
      break;
    }

    *slash = '/';
  }

  if (!device) return -1;

  if (!volume) return -1;

  mountable->volume = strdup (volume);
  if (!mountable->volume) {
    perror ("strdup");
    return -1;
  }

  mountable->device = device;
  device = NULL; /* to stop CLEANUP_FREE from freeing it */

  return 0;
}

/* Convert a mountable_t back to its string representation
 *
 * This function can be used in an error path, and must not call
 * reply_with_error().
 */
char *
mountable_to_string (const mountable_t *mountable)
{
  char *desc;

  switch (mountable->type) {
    case MOUNTABLE_DEVICE:
    case MOUNTABLE_PATH:
      return strdup (mountable->device);

    case MOUNTABLE_BTRFSVOL:
      if (asprintf(&desc, "btrfsvol:%s/%s",
                   mountable->device, mountable->volume) == -1)
        return NULL;
      return desc;

    default:
      return NULL;
  }
}

/* Check program exists and is executable on $PATH.  Actually, we
 * just assume PATH contains the default entries (see main() above).
 */
int
prog_exists (const char *prog)
{
  static const char * const dirs[] =
    { "/sbin", "/usr/sbin", "/bin", "/usr/bin" };
  size_t i;
  char buf[1024];

  for (i = 0; i < sizeof dirs / sizeof dirs[0]; ++i) {
    snprintf (buf, sizeof buf, "%s/%s", dirs[i], prog);
    if (access (buf, X_OK) == 0)
      return 1;
  }
  return 0;
}

/* Pass a template such as "/sysroot/XXXXXXXX.XXX".  This updates the
 * template to contain a randomly named file.  Any 'X' characters
 * after the final '/' are replaced with random characters.
 *
 * Notes: You should probably use an 8.3 path, so it's compatible with
 * all filesystems including basic FAT.  Also this only substitutes
 * lowercase ASCII letters and numbers, again for compatibility with
 * lowest common denominator filesystems.
 *
 * This doesn't create a file or check whether or not the file exists
 * (it would be extremely unlikely to exist as long as the RNG is
 * working).
 *
 * If there is an error, -1 is returned.
 */
int
random_name (char *template)
{
  int fd;
  unsigned char c;
  char *p;

  fd = open ("/dev/urandom", O_RDONLY|O_CLOEXEC);
  if (fd == -1)
    return -1;

  p = strrchr (template, '/');
  if (p == NULL)
    abort ();                   /* internal error - bad template */

  while (*p) {
    if (*p == 'X') {
      if (read (fd, &c, 1) != 1) {
        close (fd);
        return -1;
      }
      *p = "0123456789abcdefghijklmnopqrstuvwxyz"[c % 36];
    }

    p++;
  }

  close (fd);
  return 0;
}

/* LVM and other commands aren't synchronous, especially when udev is
 * involved.  eg. You can create or remove some device, but the /dev
 * device node won't appear until some time later.  This means that
 * you get an error if you run one command followed by another.
 *
 * Use 'udevadm settle' after certain commands, but don't be too
 * fussed if it fails.
 */
void
udev_settle (void)
{
  char cmd[80];
  int r;

  snprintf (cmd, sizeof cmd, "udevadm%s settle", verbose ? " --debug" : "");
  if (verbose)
    printf ("%s\n", cmd);
  r = system (cmd);
  if (r == -1)
    perror ("system");
  else if (!WIFEXITED (r) || WEXITSTATUS (r) != 0)
    fprintf (stderr, "warning: udevadm command failed\n");
}

/* Use by the CLEANUP_* macros.  Do not call these directly. */
void
cleanup_free (void *ptr)
{
  free (* (void **) ptr);
}

void
cleanup_free_string_list (void *ptr)
{
  free_strings (* (char ***) ptr);
}

void
cleanup_unlink_free (void *ptr)
{
  char *filename = * (char **) ptr;

  if (filename) {
    unlink (filename);
    free (filename);
  }
}

void
cleanup_close (void *ptr)
{
  int fd = * (int *) ptr;

  if (fd >= 0)
    close (fd);
}

void
cleanup_aug_close (void *ptr)
{
  augeas *aug = * (augeas **) ptr;

  if (aug != NULL)
    aug_close (aug);
}
