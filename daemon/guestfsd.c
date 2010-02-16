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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <config.h>

#define _BSD_SOURCE		/* for daemon(3) */

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

#ifdef HAVE_PRINTF_H
# include <printf.h>
#endif

#include "sockets.h"
#include "c-ctype.h"
#include "ignore-value.h"
#include "error.h"

#include "daemon.h"

static char *read_cmdline (void);

/* Also in guestfs.c */
#define GUESTFWD_ADDR "10.0.2.4"
#define GUESTFWD_PORT "6666"

/* This is only a hint.  If not defined, ignore it. */
#ifndef AI_ADDRCONFIG
# define AI_ADDRCONFIG 0
#endif

#ifndef MAX
# define MAX(a,b) ((a)>(b)?(a):(b))
#endif

int verbose = 0;

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
daemon (int nochdir, int noclose)
{
  fprintf (stderr,
           "On Windows the daemon does not support forking into the "
           "background.\nYou *must* run the daemon with the -f option.\n");
  exit (EXIT_FAILURE);
}
#endif /* WIN32 */

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
int sysroot_len = 8;

/* Not used explicitly, but required by the gnulib 'error' module. */
const char *program_name = "guestfsd";

static void
usage (void)
{
  fprintf (stderr,
    "guestfsd [-f|--foreground] [-c|--channel vmchannel] [-v|--verbose]\n");
}

int
main (int argc, char *argv[])
{
  static const char *options = "fc:v?";
  static const struct option long_options[] = {
    { "channel", required_argument, 0, 'c' },
    { "foreground", 0, 0, 'f' },
    { "help", 0, 0, '?' },
    { "verbose", 0, 0, 'v' },
    { 0, 0, 0, 0 }
  };
  int c;
  int dont_fork = 0;
  char *cmdline;
  char *vmchannel = NULL;

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

  for (;;) {
    c = getopt_long (argc, argv, options, long_options, NULL);
    if (c == -1) break;

    switch (c) {
    case 'c':
      vmchannel = optarg;
      break;

    case 'f':
      dont_fork = 1;
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
  setenv ("PATH", "/usr/bin:/bin", 1);
  setenv ("SHELL", "/bin/sh", 1);
  setenv ("LC_ALL", "C", 1);

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

  /* Get the vmchannel string.
   *
   * Sources:
   *   --channel/-c option on the command line
   *   guestfs_vmchannel=... from the kernel command line
   *   guestfs=... from the kernel command line
   *   built-in default
   *
   * At the moment we expect this to contain "tcp:ip:port" but in
   * future it might contain a device name, eg. "/dev/vcon4" for
   * virtio-console vmchannel.
   */
  if (vmchannel == NULL && cmdline) {
    char *p;
    size_t len;

    p = strstr (cmdline, "guestfs_vmchannel=");
    if (p) {
      len = strcspn (p + 18, " \t\n");
      vmchannel = strndup (p + 18, len);
      if (!vmchannel) {
        perror ("strndup");
        exit (EXIT_FAILURE);
      }
    }

    /* Old libraries passed guestfs=host:port.  Rewrite it as tcp:host:port. */
    if (vmchannel == NULL) {
      /* We will rewrite it part of the "guestfs=" string with
       *                       "tcp:"       hence p + 4 below.    */
      p = strstr (cmdline, "guestfs=");
      if (p) {
        len = strcspn (p + 4, " \t\n");
        vmchannel = strndup (p + 4, len);
        if (!vmchannel) {
          perror ("strndup");
          exit (EXIT_FAILURE);
        }
        memcpy (vmchannel, "tcp:", 4);
      }
    }
  }

  /* Default vmchannel. */
  if (vmchannel == NULL) {
    vmchannel = strdup ("tcp:" GUESTFWD_ADDR ":" GUESTFWD_PORT);
    if (!vmchannel) {
      perror ("strdup");
      exit (EXIT_FAILURE);
    }
  }

  if (verbose)
    printf ("vmchannel: %s\n", vmchannel);

  /* Connect to vmchannel. */
  int sock = -1;

  if (STREQLEN (vmchannel, "tcp:", 4)) {
    /* Resolve the hostname. */
    struct addrinfo *res, *rr;
    struct addrinfo hints;
    int r;
    char *host, *port;

    host = vmchannel+4;
    port = strchr (host, ':');
    if (port) {
      port[0] = '\0';
      port++;
    } else {
      fprintf (stderr, "vmchannel: expecting \"tcp:<ip>:<port>\": %s\n",
               vmchannel);
      exit (EXIT_FAILURE);
    }

    memset (&hints, 0, sizeof hints);
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_ADDRCONFIG;
    r = getaddrinfo (host, port, &hints, &res);
    if (r != 0) {
      fprintf (stderr, "%s:%s: %s\n",
               host, port, gai_strerror (r));
      exit (EXIT_FAILURE);
    }

    /* Connect to the given TCP socket. */
    for (rr = res; rr != NULL; rr = rr->ai_next) {
      sock = socket (rr->ai_family, rr->ai_socktype, rr->ai_protocol);
      if (sock != -1) {
        if (connect (sock, rr->ai_addr, rr->ai_addrlen) == 0)
          break;
        perror ("connect");

        close (sock);
        sock = -1;
      }
    }
    freeaddrinfo (res);
  } else {
    fprintf (stderr,
             "unknown vmchannel connection type: %s\n"
             "expecting \"tcp:<ip>:<port>\"\n",
             vmchannel);
    exit (EXIT_FAILURE);
  }

  if (sock == -1) {
    fprintf (stderr,
             "\n"
             "Failed to connect to any vmchannel implementation.\n"
             "vmchannel: %s\n"
             "\n"
             "This is a fatal error and the appliance will now exit.\n"
             "\n"
             "Usually this error is caused by either QEMU or the appliance\n"
             "kernel not supporting the vmchannel method that the\n"
             "libguestfs library chose to use.  Please run\n"
             "'libguestfs-test-tool' and provide the complete, unedited\n"
             "output to the libguestfs developers, either in a bug report\n"
             "or on the libguestfs redhat com mailing list.\n"
             "\n",
             vmchannel);
    exit (EXIT_FAILURE);
  }

  /* Send the magic length message which indicates that
   * userspace is up inside the guest.
   */
  char lenbuf[4];
  XDR xdr;
  uint32_t len = GUESTFS_LAUNCH_FLAG;
  xdrmem_create (&xdr, lenbuf, sizeof lenbuf, XDR_ENCODE);
  xdr_u_int (&xdr, &len);

  if (xwrite (sock, lenbuf, sizeof lenbuf) == -1)
    exit (EXIT_FAILURE);

  xdr_destroy (&xdr);

  /* Fork into the background. */
  if (!dont_fork) {
    if (daemon (0, 1) == -1) {
      perror ("daemon");
      exit (EXIT_FAILURE);
    }
  }

  /* Enter the main loop, reading and performing actions. */
  main_loop (sock);

  exit (EXIT_SUCCESS);
}

/* Read /proc/cmdline. */
static char *
read_cmdline (void)
{
  int fd = open ("/proc/cmdline", O_RDONLY);
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
  int len = strlen (path) + sysroot_len + 1;

  r = malloc (len);
  if (r == NULL)
    return NULL;

  snprintf (r, len, "%s%s", sysroot, path);
  return r;
}

int
xwrite (int sock, const void *v_buf, size_t len)
{
  int r;
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
add_string (char ***argv, int *size, int *alloc, const char *str)
{
  char **new_argv;
  char *new_str;

  if (*size >= *alloc) {
    *alloc += 64;
    new_argv = realloc (*argv, *alloc * sizeof (char *));
    if (new_argv == NULL) {
      reply_with_perror ("realloc");
      free_strings (*argv);
      return -1;
    }
    *argv = new_argv;
  }

  if (str) {
    new_str = strdup (str);
    if (new_str == NULL) {
      reply_with_perror ("strdup");
      free_strings (*argv);
    }
  } else
    new_str = NULL;

  (*argv)[*size] = new_str;

  (*size)++;
  return 0;
}

int
count_strings (char *const *argv)
{
  int argc;

  for (argc = 0; argv[argc] != NULL; ++argc)
    ;
  return argc;
}

static int
compare (const void *vp1, const void *vp2)
{
  char * const *p1 = (char * const *) vp1;
  char * const *p2 = (char * const *) vp2;
  return strcmp (*p1, *p2);
}

void
sort_strings (char **argv, int len)
{
  qsort (argv, len, sizeof (char *), compare);
}

void
free_strings (char **argv)
{
  int argc;

  for (argc = 0; argv[argc] != NULL; ++argc)
    free (argv[argc]);
  free (argv);
}

void
free_stringslen (char **argv, int len)
{
  int i;

  for (i = 0; i < len; ++i)
    free (argv[i]);
  free (argv);
}

/* Easy ways to run external commands.  For full documentation, see
 * 'commandrvf' below.
 */
int
commandf (char **stdoutput, char **stderror, int flags, const char *name, ...)
{
  va_list args;
  const char **argv;
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
      free (argv);
      va_end (args);
      return -1;
    }
    argv = p;
    argv[i-2] = s;
    argv[i-1] = NULL;
  }

  va_end (args);

  r = commandvf (stdoutput, stderror, flags, (const char * const*) argv);

  /* NB: Mustn't free the strings which are on the stack. */
  free (argv);

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
  const char **argv;
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
      free (argv);
      va_end (args);
      return -1;
    }
    argv = p;
    argv[i-2] = s;
    argv[i-1] = NULL;
  }

  va_end (args);

  r = commandrvf (stdoutput, stderror, flags, argv);

  /* NB: Mustn't free the strings which are on the stack. */
  free (argv);

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
 */
int
commandrvf (char **stdoutput, char **stderror, int flags,
            char const* const *argv)
{
  int so_size = 0, se_size = 0;
  int so_fd[2], se_fd[2];
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

  if (pipe (so_fd) == -1 || pipe (se_fd) == -1) {
    perror ("pipe");
    return -1;
  }

  pid = fork ();
  if (pid == -1) {
    perror ("fork");
    close (so_fd[0]);
    close (so_fd[1]);
    close (se_fd[0]);
    close (se_fd[1]);
    return -1;
  }

  if (pid == 0) {		/* Child process. */
    close (0);
    open ("/dev/null", O_RDONLY); /* Set stdin to /dev/null (ignore failure) */
    close (so_fd[0]);
    close (se_fd[0]);
    if (!(flags & COMMAND_FLAG_FOLD_STDOUT_ON_STDERR))
      dup2 (so_fd[1], 1);
    else
      dup2 (se_fd[1], 1);
    dup2 (se_fd[1], 2);
    close (so_fd[1]);
    close (se_fd[1]);

    execvp (argv[0], (void *) argv);
    perror (argv[0]);
    _exit (1);
  }

  /* Parent process. */
  close (so_fd[1]);
  close (se_fd[1]);

  FD_ZERO (&rset);
  FD_SET (so_fd[0], &rset);
  FD_SET (se_fd[0], &rset);

  quit = 0;
  while (quit < 2) {
    rset2 = rset;
    r = select (MAX (so_fd[0], se_fd[0]) + 1, &rset2, NULL, NULL, NULL);
    if (r == -1) {
      perror ("select");
    quit:
      if (stdoutput) free (*stdoutput);
      if (stderror) free (*stderror);
      close (so_fd[0]);
      close (se_fd[0]);
      waitpid (pid, NULL, 0);
      return -1;
    }

    if (FD_ISSET (so_fd[0], &rset2)) { /* something on stdout */
      r = read (so_fd[0], buf, sizeof buf);
      if (r == -1) {
        perror ("read");
        goto quit;
      }
      if (r == 0) { FD_CLR (so_fd[0], &rset); quit++; }

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

    if (FD_ISSET (se_fd[0], &rset2)) { /* something on stderr */
      r = read (se_fd[0], buf, sizeof buf);
      if (r == -1) {
        perror ("read");
        goto quit;
      }
      if (r == 0) { FD_CLR (se_fd[0], &rset); quit++; }

      if (r > 0) {
        if (verbose)
          ignore_value (write (2, buf, r));

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

  close (so_fd[0]);
  close (se_fd[0]);

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
      se_size--;
      while (se_size >= 0 && (*stderror)[se_size] == '\n')
        (*stderror)[se_size--] = '\0';
    }
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
  char **lines = NULL;
  int size = 0, alloc = 0;
  char *p, *pend;

  if (STREQ (str, ""))
    goto empty_list;

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

    if (add_string (&lines, &size, &alloc, p) == -1) {
      return NULL;
    }

    p = pend;
  }

 empty_list:
  if (add_string (&lines, &size, &alloc, NULL) == -1)
    return NULL;

  return lines;
}

/* printf helper function so we can use %Q ("quoted") and %R to print
 * shell-quoted strings.  See HACKING file for more details.
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

/* Perform device name translation.  Don't call this directly -
 * use the RESOLVE_DEVICE macro.
 *
 * See guestfs(3) for the algorithm.
 *
 * We have to open the device and test for ENXIO, because
 * the device nodes themselves will exist in the appliance.
 */
int
device_name_translation (char *device, const char *func)
{
  int fd;

  fd = open (device, O_RDONLY);
  if (fd >= 0) {
    close (fd);
    return 0;
  }

  if (errno != ENXIO && errno != ENOENT) {
  error:
    reply_with_perror ("%s: %s", func, device);
    return -1;
  }

  /* If the name begins with "/dev/sd" then try the alternatives. */
  if (STRNEQLEN (device, "/dev/sd", 7))
    goto error;

  device[5] = 'h';		/* /dev/hd (old IDE driver) */
  fd = open (device, O_RDONLY);
  if (fd >= 0) {
    close (fd);
    return 0;
  }

  device[5] = 'v';		/* /dev/vd (for virtio devices) */
  fd = open (device, O_RDONLY);
  if (fd >= 0) {
    close (fd);
    return 0;
  }

  device[5] = 's';		/* Restore original device name. */
  goto error;
}

/* LVM and other commands aren't synchronous, especially when udev is
 * involved.  eg. You can create or remove some device, but the /dev
 * device node won't appear until some time later.  This means that
 * you get an error if you run one command followed by another.
 *
 * Use 'udevadm settle' after certain commands, but don't be too
 * fussed if it fails.
 *
 * 'udevsettle' was the old name for this command (RHEL 5).  This was
 * deprecated in favour of 'udevadm settle'.  The old 'udevsettle'
 * command was left as a symlink.  Then in Fedora 13 the old symlink
 * remained but it stopped working (RHBZ#548121), so we have to be
 * careful not to assume that we can use 'udevsettle' if it exists.
 */
void
udev_settle (void)
{
  (void) command (NULL, NULL, "/sbin/udevadm", "settle", NULL);
  (void) command (NULL, NULL, "/sbin/udevsettle", NULL);
}
