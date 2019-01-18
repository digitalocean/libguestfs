/* libguestfs - the guestfsd daemon
 * Copyright (C) 2009-2019 Red Hat Inc.
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

/**
 * This is the guestfs daemon which runs inside the guestfs appliance.
 * This file handles start up and connecting back to the library.
 */

#include <config.h>

#ifdef HAVE_WINDOWS_H
# include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <getopt.h>
#include <errno.h>
#include <error.h>
#include <assert.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef HAVE_PRINTF_H
# include <printf.h>
#endif

#include <caml/callback.h> /* for caml_startup */

#include "c-ctype.h"
#include "ignore-value.h"
#include "sockets.h"

#include "daemon.h"

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
  static const char options[] = "c:lnrtv?";
  static const struct option long_options[] = {
    { "help", 0, 0, '?' },
    { "channel", 1, 0, 'c' },
    { "listen", 0, 0, 'l' },
    { "network", 0, 0, 'n' },
    { "test", 0, 0, 't' },
    { "verbose", 0, 0, 'v' },
    { 0, 0, 0, 0 }
  };
  int c;
  const char *channel = NULL;
  int listen_mode = 0;

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
    case 'c':
      channel = optarg;
      break;

    case 'l':
      listen_mode = 1;
      break;

    case 'n':
      enable_network = 1;
      break;

      /* The -r flag is used when running standalone.  It changes
       * several aspects of the daemon.
       */
    case 'r':
      sysroot = "";
      sysroot_len = 0;
      autosync_umount = 0;
      break;

      /* Undocumented --test option used for testing guestfsd. */
    case 't':
      test_mode = 1;
      break;

    case 'v':
      verbose = 1;
      break;

    case '?':
      usage ();
      exit (EXIT_SUCCESS);

    default:
      error (EXIT_FAILURE, 0,
             "unexpected command line option 0x%x\n", (unsigned) c);
    }
  }

  if (optind < argc) {
    usage ();
    exit (EXIT_FAILURE);
  }

  /* Initialize the OCaml stubs.  This must be done after the
   * ‘verbose’ flag is set from the command line since the OCaml
   * initialization code depends on that.
   */
  caml_startup (argv);

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
   */
  if (!test_mode)
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

  /* Connect to virtio-serial channel. */
  if (!channel)
    channel = VIRTIO_SERIAL_CHANNEL;

  if (verbose)
    printf ("trying to open virtio-serial channel '%s'\n", channel);

  int sock;
  if (!listen_mode) {
    if (STRPREFIX (channel, "fd:")) {
      if (sscanf (channel+3, "%d", &sock) != 1)
        error (EXIT_FAILURE, 0, "cannot parse --channel %s", channel);
    }
    else {
      sock = open (channel, O_RDWR|O_CLOEXEC);
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
        error (EXIT_FAILURE, errno, "open: %s", channel);
      }
    }
  }
  else {
    struct sockaddr_un addr;

    sock = socket (AF_UNIX, SOCK_STREAM|SOCK_CLOEXEC, 0);
    if (sock == -1)
      error (EXIT_FAILURE, errno, "socket");
    addr.sun_family = AF_UNIX;
    if (strlen (channel) > UNIX_PATH_MAX-1)
      error (EXIT_FAILURE, 0, "%s: socket path is too long", channel);
    strcpy (addr.sun_path, channel);

    if (bind (sock, (struct sockaddr *) &addr, sizeof addr) == -1)
      error (EXIT_FAILURE, errno, "bind: %s", channel);

    if (listen (sock, 4) == -1)
      error (EXIT_FAILURE, errno, "listen");

    sock = accept4 (sock, NULL, NULL, SOCK_CLOEXEC);
    if (sock == -1)
      error (EXIT_FAILURE, errno, "accept");
  }

  /* If it's a serial-port like device then it probably has echoing
   * enabled.  Put it into complete raw mode.
   */
  if (STRPREFIX (channel, "/dev/ttyS"))
    makeraw (channel, sock);

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

  if (xwrite (sock, lenbuf, sizeof lenbuf) == -1)
    error (EXIT_FAILURE, errno, "xwrite");

  xdr_destroy (&xdr);

  /* Enter the main loop, reading and performing actions. */
  main_loop (sock);

  exit (EXIT_SUCCESS);
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

/**
 * printf helper function so we can use C<%Q> ("quoted") and C<%R> to
 * print shell-quoted strings.  See L<guestfs-hacking(1)> for more
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
    if (!SAFE (str[i])) {
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
