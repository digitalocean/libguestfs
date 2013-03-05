/* libguestfs-test-tool
 * Copyright (C) 2009-2013 Red Hat Inc.
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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <locale.h>
#include <limits.h>
#include <libintl.h>

#include <guestfs.h>
#include "guestfs-internal-frontend.h"

#include "ignore-value.h"

#ifndef P_tmpdir
#define P_tmpdir "/tmp"
#endif

#define DEFAULT_TIMEOUT 600

static int timeout = DEFAULT_TIMEOUT;
static char tmpf[] = P_tmpdir "/libguestfs-test-tool-sda-XXXXXX";

static void make_files (void);
static void set_qemu (guestfs_h *g, const char *path, int use_wrapper);

static void
usage (void)
{
  printf (_("libguestfs-test-tool: interactive test tool\n"
            "Copyright (C) 2009-2013 Red Hat Inc.\n"
            "Usage:\n"
            "  libguestfs-test-tool [--options]\n"
            "Options:\n"
            "  --help         Display usage\n"
            "  --qemudir dir  Specify QEMU source directory\n"
            "  --qemu qemu    Specify QEMU binary\n"
            "  --timeout n\n"
            "  -t n           Set launch timeout (default: %d seconds)\n"
            "  --version\n"
            "  -V             Display libguestfs version and exit\n"
            ),
          DEFAULT_TIMEOUT);
}

extern char **environ;

int
main (int argc, char *argv[])
{
  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEBASEDIR);
  textdomain (PACKAGE);

  static const char *options = "t:V?";
  static const struct option long_options[] = {
    { "help", 0, 0, '?' },
    { "qemu", 1, 0, 0 },
    { "qemudir", 1, 0, 0 },
    { "timeout", 1, 0, 't' },
    { "version", 0, 0, 'V' },
    { 0, 0, 0, 0 }
  };
  int c;
  int option_index;
  int i;
  struct guestfs_version *vers;
  char *p;
  guestfs_h *g;
  char *qemu = NULL;
  int qemu_use_wrapper;

  for (;;) {
    c = getopt_long (argc, argv, options, long_options, &option_index);
    if (c == -1) break;

    switch (c) {
    case 0:			/* options which are long only */
      if (STREQ (long_options[option_index].name, "qemu")) {
        qemu = optarg;
        qemu_use_wrapper = 0;
      }
      else if (STREQ (long_options[option_index].name, "qemudir")) {
        qemu = optarg;
        qemu_use_wrapper = 1;
      }
      else {
        fprintf (stderr,
                 _("libguestfs-test-tool: unknown long option: %s (%d)\n"),
                 long_options[option_index].name, option_index);
        exit (EXIT_FAILURE);
      }
      break;

    case 't':
      if (sscanf (optarg, "%d", &timeout) != 1 || timeout < 0) {
        fprintf (stderr,
                 _("libguestfs-test-tool: invalid timeout: %s\n"),
                 optarg);
        exit (EXIT_FAILURE);
      }
      break;

    case 'V':
      g = guestfs_create ();
      if (g == NULL) {
        fprintf (stderr,
                 _("libguestfs-test-tool: failed to create libguestfs handle\n"));
        exit (EXIT_FAILURE);
      }
      vers = guestfs_version (g);
      if (vers == NULL) {
        fprintf (stderr, _("libguestfs-test-tool: guestfs_version failed\n"));
        exit (EXIT_FAILURE);
      }
      printf ("%s %"PRIi64".%"PRIi64".%"PRIi64"%s\n",
              "libguestfs-test-tool",
              vers->major, vers->minor, vers->release, vers->extra);
      guestfs_free_version (vers);
      guestfs_close (g);
      exit (EXIT_SUCCESS);

    case '?':
      usage ();
      exit (EXIT_SUCCESS);

    default:
      fprintf (stderr,
               _("libguestfs-test-tool: unexpected command line option 0x%x\n"),
               c);
      exit (EXIT_FAILURE);
    }
  }

  if (optind < argc) {
    fprintf (stderr, _("libguestfs-test-tool: extra arguments on the command line\n"));
    exit (EXIT_FAILURE);
  }

  /* Everyone ignores the documentation, so ... */
  printf ("     ************************************************************\n"
          "     *                    IMPORTANT NOTICE\n"
          "     *\n"
          "     * When reporting bugs, include the COMPLETE, UNEDITED\n"
          "     * output below in your bug report.\n"
          "     *\n"
          "     ************************************************************\n"
          );
  sleep (3);

  /* Create the handle. */
  g = guestfs_create_flags (GUESTFS_CREATE_NO_ENVIRONMENT);
  if (g == NULL) {
    fprintf (stderr,
             _("libguestfs-test-tool: failed to create libguestfs handle\n"));
    exit (EXIT_FAILURE);
  }
  if (guestfs_parse_environment (g) == -1) {
    fprintf (stderr,
             _("libguestfs-test-tool: failed parsing environment variables.\n"
               "Check earlier messages, and the output of the 'printenv' command.\n"));
    exit (EXIT_FAILURE);
  }
  guestfs_set_verbose (g, 1);

  if (qemu)
    set_qemu (g, qemu, qemu_use_wrapper);

  make_files ();

  /* Print out any environment variables which may relate to this test. */
  for (i = 0; environ[i] != NULL; ++i) {
    if (STRPREFIX (environ[i], "LIBGUESTFS_"))
      printf ("%s\n", environ[i]);
    if (STRPREFIX (environ[i], "FEBOOTSTRAP_"))
      printf ("%s\n", environ[i]);
    if (STRPREFIX (environ[i], "SUPERMIN_"))
      printf ("%s\n", environ[i]);
    if (STRPREFIX (environ[i], "LIBVIRT_"))
      printf ("%s\n", environ[i]);
    if (STRPREFIX (environ[i], "LIBVIRTD_"))
      printf ("%s\n", environ[i]);
    if (STRPREFIX (environ[i], "LD_"))
      printf ("%s\n", environ[i]);
  }
  p = getenv ("TMPDIR");
  if (p)
    printf ("TMPDIR=%s\n", p);
  p = getenv ("PATH");
  if (p)
    printf ("PATH=%s\n", p);

  /* Print SELinux mode (don't worry if this fails, or if the command
   * doesn't even exist).
   */
  printf ("SELinux: ");
  fflush (stdout); /* because getenforce prints output on stderr :-( */
  ignore_value (system ("getenforce"));

  /* Configure the handle. */
  if (guestfs_add_drive_opts (g, tmpf,
                              GUESTFS_ADD_DRIVE_OPTS_FORMAT, "raw",
                              -1) == -1) {
    fprintf (stderr,
             _("libguestfs-test-tool: failed to add drive '%s'\n"),
             tmpf);
    exit (EXIT_FAILURE);
  }

  /* Print any version info etc. */
  vers = guestfs_version (g);
  if (vers == NULL) {
    fprintf (stderr, _("libguestfs-test-tool: guestfs_version failed\n"));
    exit (EXIT_FAILURE);
  }
  printf ("library version: %"PRIi64".%"PRIi64".%"PRIi64"%s\n",
          vers->major, vers->minor, vers->release, vers->extra);
  guestfs_free_version (vers);

  printf ("guestfs_get_append: %s\n", guestfs_get_append (g) ? : "(null)");
  p = guestfs_get_attach_method (g);
  printf ("guestfs_get_attach_method: %s\n", p ? : "(null)");
  free (p);
  printf ("guestfs_get_autosync: %d\n", guestfs_get_autosync (g));
  p = guestfs_get_cachedir (g);
  printf ("guestfs_get_cachedir: %s\n", p ? : "(null)");
  free (p);
  printf ("guestfs_get_direct: %d\n", guestfs_get_direct (g));
  printf ("guestfs_get_memsize: %d\n", guestfs_get_memsize (g));
  printf ("guestfs_get_network: %d\n", guestfs_get_network (g));
  printf ("guestfs_get_path: %s\n", guestfs_get_path (g) ? : "(null)");
  printf ("guestfs_get_pgroup: %d\n", guestfs_get_pgroup (g));
  printf ("guestfs_get_qemu: %s\n", guestfs_get_qemu (g));
  printf ("guestfs_get_recovery_proc: %d\n", guestfs_get_recovery_proc (g));
  printf ("guestfs_get_selinux: %d\n", guestfs_get_selinux (g));
  printf ("guestfs_get_smp: %d\n", guestfs_get_smp (g));
  p = guestfs_get_tmpdir (g);
  printf ("guestfs_get_tmpdir: %s\n", p ? : "(null)");
  free (p);
  printf ("guestfs_get_trace: %d\n", guestfs_get_trace (g));
  printf ("guestfs_get_verbose: %d\n", guestfs_get_verbose (g));

  printf ("host_cpu: %s\n", host_cpu);

  /* Launch the guest handle. */
  printf ("Launching appliance, timeout set to %d seconds.\n", timeout);
  fflush (stdout);

  alarm (timeout);

  if (guestfs_launch (g) == -1) {
    fprintf (stderr,
             _("libguestfs-test-tool: failed to launch appliance\n"));
    exit (EXIT_FAILURE);
  }

  alarm (0);

  printf ("Guest launched OK.\n");
  fflush (stdout);

  /* Create the filesystem and mount everything. */
  if (guestfs_part_disk (g, "/dev/sda", "mbr") == -1) {
    fprintf (stderr,
             _("libguestfs-test-tool: failed to run part-disk\n"));
    exit (EXIT_FAILURE);
  }

  if (guestfs_mkfs (g, "ext2", "/dev/sda1") == -1) {
    fprintf (stderr,
             _("libguestfs-test-tool: failed to mkfs.ext2\n"));
    exit (EXIT_FAILURE);
  }

  if (guestfs_mount (g, "/dev/sda1", "/") == -1) {
    fprintf (stderr,
             _("libguestfs-test-tool: failed to mount /dev/sda1 on /\n"));
    exit (EXIT_FAILURE);
  }

  /* Touch a file. */
  if (guestfs_touch (g, "/hello") == -1) {
    fprintf (stderr,
             _("libguestfs-test-tool: failed to touch file\n"));
    exit (EXIT_FAILURE);
  }

  /* Close the handle. */
  if (guestfs_shutdown (g) == -1) {
    fprintf (stderr, _("libguestfs-test-tool: shutdown failed\n"));
    exit (EXIT_FAILURE);
  }

  guestfs_close (g);

  /* Booted and performed some simple operations -- success! */
  printf ("===== TEST FINISHED OK =====\n");
  exit (EXIT_SUCCESS);
}

static char qemuwrapper[] = P_tmpdir "/libguestfs-test-tool-wrapper-XXXXXX";

static void
cleanup_wrapper (void)
{
  unlink (qemuwrapper);
}

/* Handle the --qemu and --qemudir parameters.  use_wrapper is true
 * in the --qemudir (source directory) case, where we have to create
 * a wrapper shell script.
 */
static void
set_qemu (guestfs_h *g, const char *path, int use_wrapper)
{
  char *buffer;
  struct stat statbuf;
  int fd;
  FILE *fp;

  if (getenv ("LIBGUESTFS_QEMU")) {
    fprintf (stderr,
    _("LIBGUESTFS_QEMU environment variable is already set, so\n"
      "--qemu/--qemudir options cannot be used.\n"));
    exit (EXIT_FAILURE);
  }

  if (!use_wrapper) {
    if (access (path, X_OK) == -1) {
      fprintf (stderr,
               _("Binary '%s' does not exist or is not executable\n"),
               path);
      exit (EXIT_FAILURE);
    }

    guestfs_set_qemu (g, path);
    return;
  }

  /* This should be a source directory, so check it. */
  if (asprintf (&buffer, "%s/pc-bios", path) == -1) {
    perror ("asprintf");
    exit (EXIT_FAILURE);
  }
  if (stat (buffer, &statbuf) == -1 ||
      !S_ISDIR (statbuf.st_mode)) {
    fprintf (stderr,
             _("%s: does not look like a qemu source directory\n"),
             path);
    free (buffer);
    exit (EXIT_FAILURE);
  }
  free (buffer);

  /* Make a wrapper script. */
  fd = mkstemp (qemuwrapper);
  if (fd == -1) {
    perror (qemuwrapper);
    exit (EXIT_FAILURE);
  }

  fchmod (fd, 0700);

  fp = fdopen (fd, "w");
  fprintf (fp,
           "#!/bin/sh -\n"
           "host_cpu=%s\n"
           "qemudir='%s'\n"
           "qemu=\"$qemudir/$host_cpu-softmmu/qemu-system-$host_cpu\"\n"
           "exec \"$qemu\" -L \"$qemudir/pc-bios\" \"$@\"\n",
           host_cpu, path);
  fclose (fp);

  guestfs_set_qemu (g, qemuwrapper);
  atexit (cleanup_wrapper);
}

static void
cleanup_tmpfiles (void)
{
  unlink (tmpf);
}

static void
make_files (void)
{
  int fd;

  /* Allocate the sparse file for /dev/sda. */
  fd = mkstemp (tmpf);
  if (fd == -1) {
    perror (tmpf);
    exit (EXIT_FAILURE);
  }

  if (lseek (fd, 100 * 1024 * 1024 - 1, SEEK_SET) == -1) {
    perror ("lseek");
    close (fd);
    unlink (tmpf);
    exit (EXIT_FAILURE);
  }

  if (write (fd, "\0", 1) == -1) {
    perror ("write");
    close (fd);
    unlink (tmpf);
    exit (EXIT_FAILURE);
  }

  close (fd);

  atexit (cleanup_tmpfiles);	/* Removes tmpf. */
}
