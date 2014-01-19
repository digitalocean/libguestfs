/* virt-edit
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h>
#include <locale.h>
#include <getopt.h>
#include <errno.h>
#include <assert.h>
#include <libintl.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <utime.h>

#include "xvasprintf.h"
#include "c-ctype.h"

#include "guestfs.h"
#include "options.h"

/* Currently open libguestfs handle. */
guestfs_h *g;

int read_only = 0;
int live = 0;
int verbose = 0;
int keys_from_stdin = 0;
int echo_keys = 0;
const char *libvirt_uri = NULL;
int inspector = 1;

static const char *backup_extension = NULL;
static const char *perl_expr = NULL;

static void edit_files (int argc, char *argv[]);
static void edit (const char *filename, const char *root);
static char *edit_interactively (const char *tmpfile);
static char *edit_non_interactively (const char *tmpfile);
static int is_windows (guestfs_h *g, const char *root);
static char *windows_path (guestfs_h *g, const char *root, const char *filename);
static char *generate_random_name (const char *filename);
static char *generate_backup_name (const char *filename);

static void __attribute__((noreturn))
usage (int status)
{
  if (status != EXIT_SUCCESS)
    fprintf (stderr, _("Try `%s --help' for more information.\n"),
             program_name);
  else {
    fprintf (stdout,
           _("%s: Edit a file in a virtual machine\n"
             "Copyright (C) 2009-2014 Red Hat Inc.\n"
             "Usage:\n"
             "  %s [--options] -d domname file [file ...]\n"
             "  %s [--options] -a disk.img [-a disk.img ...] file [file ...]\n"
             "Options:\n"
             "  -a|--add image       Add image\n"
             "  -b|--backup .ext     Backup original as original.ext\n"
             "  -c|--connect uri     Specify libvirt URI for -d option\n"
             "  -d|--domain guest    Add disks from libvirt guest\n"
             "  --echo-keys          Don't turn off echo for passphrases\n"
             "  -e|--expr expr       Non-interactive editing using Perl expr\n"
             "  --format[=raw|..]    Force disk format for -a option\n"
             "  --help               Display brief help\n"
             "  --keys-from-stdin    Read passphrases from stdin\n"
             "  -v|--verbose         Verbose messages\n"
             "  -V|--version         Display version and exit\n"
             "  -x                   Trace libguestfs API calls\n"
             "For more information, see the manpage %s(1).\n"),
             program_name, program_name, program_name,
             program_name);
  }
  exit (status);
}

int
main (int argc, char *argv[])
{
  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEBASEDIR);
  textdomain (PACKAGE);

  /* We use random(3) below. */
  srandom (time (NULL));

  enum { HELP_OPTION = CHAR_MAX + 1 };

  static const char *options = "a:b:c:d:e:vVx";
  static const struct option long_options[] = {
    { "add", 1, 0, 'a' },
    { "backup", 1, 0, 'b' },
    { "connect", 1, 0, 'c' },
    { "domain", 1, 0, 'd' },
    { "echo-keys", 0, 0, 0 },
    { "edit", 1, 0, 'e' },
    { "expr", 1, 0, 'e' },
    { "format", 2, 0, 0 },
    { "help", 0, 0, HELP_OPTION },
    { "keys-from-stdin", 0, 0, 0 },
    { "long-options", 0, 0, 0 },
    { "verbose", 0, 0, 'v' },
    { "version", 0, 0, 'V' },
    { 0, 0, 0, 0 }
  };
  struct drv *drvs = NULL;
  struct drv *drv;
  const char *format = NULL;
  int c;
  int option_index;

  g = guestfs_create ();
  if (g == NULL) {
    fprintf (stderr, _("guestfs_create: failed to create handle\n"));
    exit (EXIT_FAILURE);
  }

  for (;;) {
    c = getopt_long (argc, argv, options, long_options, &option_index);
    if (c == -1) break;

    switch (c) {
    case 0:			/* options which are long only */
      if (STREQ (long_options[option_index].name, "long-options"))
        display_long_options (long_options);
      else if (STREQ (long_options[option_index].name, "keys-from-stdin")) {
        keys_from_stdin = 1;
      } else if (STREQ (long_options[option_index].name, "echo-keys")) {
        echo_keys = 1;
      } else if (STREQ (long_options[option_index].name, "format")) {
        if (!optarg || STREQ (optarg, ""))
          format = NULL;
        else
          format = optarg;
      } else {
        fprintf (stderr, _("%s: unknown long option: %s (%d)\n"),
                 program_name, long_options[option_index].name, option_index);
        exit (EXIT_FAILURE);
      }
      break;

    case 'a':
      OPTION_a;
      break;

    case 'b':
      if (backup_extension) {
        fprintf (stderr, _("%s: -b option given multiple times\n"),
                 program_name);
        exit (EXIT_FAILURE);
      }
      backup_extension = optarg;
      break;

    case 'c':
      OPTION_c;
      break;

    case 'd':
      OPTION_d;
      break;

    case 'e':
      if (perl_expr) {
        fprintf (stderr, _("%s: -e option given multiple times\n"),
                 program_name);
        exit (EXIT_FAILURE);
      }
      perl_expr = optarg;
      break;

    case 'v':
      OPTION_v;
      break;

    case 'V':
      OPTION_V;
      break;

    case 'x':
      OPTION_x;
      break;

    case HELP_OPTION:
      usage (EXIT_SUCCESS);

    default:
      usage (EXIT_FAILURE);
    }
  }

  /* Old-style syntax?  There were no -a or -d options in the old
   * virt-edit which is how we detect this.
   */
  if (drvs == NULL) {
    /* argc - 1 because last parameter is the single filename. */
    while (optind < argc - 1) {
      if (strchr (argv[optind], '/') ||
          access (argv[optind], F_OK) == 0) { /* simulate -a option */
        drv = calloc (1, sizeof (struct drv));
        if (!drv) {
          perror ("malloc");
          exit (EXIT_FAILURE);
        }
        drv->type = drv_a;
        drv->a.filename = strdup (argv[optind]);
        if (!drv->a.filename) {
          perror ("strdup");
          exit (EXIT_FAILURE);
        }
        drv->next = drvs;
        drvs = drv;
      } else {                  /* simulate -d option */
        drv = calloc (1, sizeof (struct drv));
        if (!drv) {
          perror ("malloc");
          exit (EXIT_FAILURE);
        }
        drv->type = drv_d;
        drv->d.guest = argv[optind];
        drv->next = drvs;
        drvs = drv;
      }

      optind++;
    }
  }

  /* These are really constants, but they have to be variables for the
   * options parsing code.  Assert here that they have known-good
   * values.
   */
  assert (read_only == 0);
  assert (inspector == 1);
  assert (live == 0);

  /* User must specify at least one filename on the command line. */
  if (optind >= argc || argc - optind < 1)
    usage (EXIT_FAILURE);

  /* User must have specified some drives. */
  if (drvs == NULL)
    usage (EXIT_FAILURE);

  /* Add drives. */
  add_drives (drvs, 'a');

  if (guestfs_launch (g) == -1)
    exit (EXIT_FAILURE);

  inspect_mount ();

  /* Free up data structures, no longer needed after this point. */
  free_drives (drvs);

  edit_files (argc - optind, &argv[optind]);

  /* Cleanly unmount the disks after editing. */
  if (guestfs_shutdown (g) == -1)
    exit (EXIT_FAILURE);

  guestfs_close (g);

  exit (EXIT_SUCCESS);
}

static void
edit_files (int argc, char *argv[])
{
  int i;
  char *root;
  CLEANUP_FREE_STRING_LIST char **roots = guestfs_inspect_get_roots (g);

  if (!roots)
    exit (EXIT_FAILURE);

  /* Get root mountpoint. */
  /* see fish/inspect.c:inspect_mount */
  assert (roots[0] != NULL && roots[1] == NULL);
  root = roots[0];

  for (i = 0; i < argc; ++i)
    edit (argv[i], root);
}

static void
edit (const char *filename, const char *root)
{
  CLEANUP_FREE char *filename_to_free = NULL;
  CLEANUP_FREE char *tmpdir = guestfs_get_tmpdir (g);
  char tmpfile[strlen (tmpdir) + 32];
  sprintf (tmpfile, "%s/virteditXXXXXX", tmpdir);

  int fd;
  char fdbuf[32];
  CLEANUP_FREE char *upload_from = NULL;
  CLEANUP_FREE char *newname = NULL;
  CLEANUP_FREE char *backupname = NULL;

  /* Windows?  Special handling is required. */
  if (is_windows (g, root))
    filename = filename_to_free = windows_path (g, root, filename);

  /* Download the file to a temporary. */
  fd = mkstemp (tmpfile);
  if (fd == -1) {
    perror ("mkstemp");
    exit (EXIT_FAILURE);
  }

  snprintf (fdbuf, sizeof fdbuf, "/dev/fd/%d", fd);

  if (guestfs_download (g, filename, fdbuf) == -1)
    goto error;

  if (close (fd) == -1) {
    perror (tmpfile);
    goto error;
  }

  if (!perl_expr)
    upload_from = edit_interactively (tmpfile);
  else
    upload_from = edit_non_interactively (tmpfile);

  /* We don't always need to upload: upload_from could be NULL because
   * the user closed the editor without changing the file.
   */
  if (upload_from) {
    /* Upload to a new file in the same directory, so if it fails we
     * don't end up with a partially written file.  Give the new file
     * a completely random name so we have only a tiny chance of
     * overwriting some existing file.
     */
    newname = generate_random_name (filename);

    if (guestfs_upload (g, upload_from, newname) == -1)
      goto error;

    /* Set the permissions, UID, GID and SELinux context of the new
     * file to match the old file (RHBZ#788641).
     */
    if (guestfs_copy_attributes (g, filename, newname,
        GUESTFS_COPY_ATTRIBUTES_ALL, 1, -1) == -1)
      goto error;

    /* Backup or overwrite the file. */
    if (backup_extension) {
      backupname = generate_backup_name (filename);
      if (guestfs_mv (g, filename, backupname) == -1)
        goto error;
    }
    if (guestfs_mv (g, newname, filename) == -1)
      goto error;
  }

  unlink (tmpfile);
  return;

 error:
  unlink (tmpfile);
  exit (EXIT_FAILURE);
}

static char *
edit_interactively (const char *tmpfile)
{
  struct utimbuf times;
  struct stat oldstat, newstat;
  const char *editor;
  CLEANUP_FREE char *cmd = NULL;
  int r;
  char *ret;

  /* Set the time back a few seconds on the original file.  This is so
   * that if the user is very fast at editing, or if EDITOR is an
   * automatic editor, then the edit might happen within the 1 second
   * granularity of mtime, and we would think the file hasn't changed.
   */
  if (stat (tmpfile, &oldstat) == -1) {
    perror (tmpfile);
    exit (EXIT_FAILURE);
  }

  times.actime = oldstat.st_atime - 5;
  times.modtime = oldstat.st_mtime - 5;
  if (utime (tmpfile, &times) == -1) {
    perror ("utimes");
    exit (EXIT_FAILURE);
  }

  if (stat (tmpfile, &oldstat) == -1) {
    perror (tmpfile);
    exit (EXIT_FAILURE);
  }

  editor = getenv ("EDITOR");
  if (editor == NULL)
    editor = "vi";

  if (asprintf (&cmd, "%s %s", editor, tmpfile) == -1) {
    perror ("asprintf");
    exit (EXIT_FAILURE);
  }

  if (verbose)
    fprintf (stderr, "%s\n", cmd);

  r = system (cmd);
  if (r == -1 || WEXITSTATUS (r) != 0)
    exit (EXIT_FAILURE);

  if (stat (tmpfile, &newstat) == -1) {
    perror (tmpfile);
    exit (EXIT_FAILURE);
  }

  if (oldstat.st_ctime == newstat.st_ctime &&
      oldstat.st_mtime == newstat.st_mtime) {
    printf ("File not changed.\n");
    return NULL;
  }

  ret = strdup (tmpfile);
  if (!ret) {
    perror ("strdup");
    exit (EXIT_FAILURE);
  }

  return ret;
}

/* Note that virt-builder uses exactly the same code .. in OCaml. */
static char *
edit_non_interactively (const char *tmpfile)
{
  CLEANUP_FREE char *cmd = NULL, *outfile = NULL;
  char *ret;
  int r;

  assert (perl_expr != NULL);

  /* Pass the expression to Perl via the environment.  This sidesteps
   * any quoting problems with the already complex Perl command line.
   */
  setenv ("virt_edit_expr", perl_expr, 1);

  /* Call out to a canned Perl script. */
  if (asprintf (&cmd,
                "perl -e '"
                "$lineno = 0; "
                "$expr = $ENV{virt_edit_expr}; "
                "while (<STDIN>) { "
                "  $lineno++; "
                "  eval $expr; "
                "  die if $@; "
                "  print STDOUT $_ or die \"print: $!\"; "
                "} "
                "close STDOUT or die \"close: $!\"; "
                "' < %s > %s.out",
                tmpfile, tmpfile) == -1) {
    perror ("asprintf");
    exit (EXIT_FAILURE);
  }

  if (verbose)
    fprintf (stderr, "%s\n", cmd);

  r = system (cmd);
  if (r == -1 || WEXITSTATUS (r) != 0)
    exit (EXIT_FAILURE);

  if (asprintf (&outfile, "%s.out", tmpfile) == -1) {
    perror ("asprintf");
    exit (EXIT_FAILURE);
  }

  if (rename (outfile, tmpfile) == -1) {
    perror ("rename");
    exit (EXIT_FAILURE);
  }

  ret = strdup (tmpfile);
  if (!ret) {
    perror ("strdup");
    exit (EXIT_FAILURE);
  }

  return ret; /* caller will free */
}

static int
is_windows (guestfs_h *g, const char *root)
{
  int w;
  CLEANUP_FREE char *type = guestfs_inspect_get_type (g, root);
  if (!type)
    return 0;

  w = STREQ (type, "windows");
  return w;
}

static void mount_drive_letter (char drive_letter, const char *root);

static char *
windows_path (guestfs_h *g, const char *root, const char *path)
{
  char *ret;
  size_t i;

  /* If there is a drive letter, rewrite the path. */
  if (c_isalpha (path[0]) && path[1] == ':') {
    char drive_letter = c_tolower (path[0]);
    /* This returns the newly allocated string. */
    mount_drive_letter (drive_letter, root);
    ret = strdup (path + 2);
    if (ret == NULL) {
      perror ("strdup");
      exit (EXIT_FAILURE);
    }
  }
  else if (!*path) {
    ret = strdup ("/");
    if (ret == NULL) {
      perror ("strdup");
      exit (EXIT_FAILURE);
    }
  }
  else {
    ret = strdup (path);
    if (ret == NULL) {
      perror ("strdup");
      exit (EXIT_FAILURE);
    }
  }

  /* Blindly convert any backslashes into forward slashes.  Is this good? */
  for (i = 0; i < strlen (ret); ++i)
    if (ret[i] == '\\')
      ret[i] = '/';

  char *t = guestfs_case_sensitive_path (g, ret);
  free (ret);
  ret = t;
  if (ret == NULL)
    exit (EXIT_FAILURE);

  return ret;
}

static void
mount_drive_letter (char drive_letter, const char *root)
{
  char *device;
  size_t i;

  /* Resolve the drive letter using the drive mappings table. */
  CLEANUP_FREE_STRING_LIST char **drives =
    guestfs_inspect_get_drive_mappings (g, root);
  if (drives == NULL || drives[0] == NULL) {
    fprintf (stderr, _("%s: to use Windows drive letters, this must be a Windows guest\n"),
             program_name);
    exit (EXIT_FAILURE);
  }

  device = NULL;
  for (i = 0; drives[i] != NULL; i += 2) {
    if (c_tolower (drives[i][0]) == drive_letter && drives[i][1] == '\0') {
      device = drives[i+1];
      break;
    }
  }

  if (device == NULL) {
    fprintf (stderr, _("%s: drive '%c:' not found.\n"),
             program_name, drive_letter);
    exit (EXIT_FAILURE);
  }

  /* Unmount current disk and remount device. */
  if (guestfs_umount_all (g) == -1)
    exit (EXIT_FAILURE);

  if (guestfs_mount (g, device, "/") == -1)
    exit (EXIT_FAILURE);

  /* Don't need to free (device) because that string was in the
   * drives array.
   */
}

static char
random_char (void)
{
  char c[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  return c[random () % (sizeof c - 1)];
}

static char *
generate_random_name (const char *filename)
{
  char *ret, *p;
  size_t i;

  ret = malloc (strlen (filename) + 16);
  if (!ret) {
    perror ("malloc");
    exit (EXIT_FAILURE);
  }
  strcpy (ret, filename);

  p = strrchr (ret, '/');
  assert (p);
  p++;

  /* Because of "+ 16" above, there should be enough space in the
   * output buffer to write 8 random characters here.
   */
  for (i = 0; i < 8; ++i)
    *p++ = random_char ();
  *p++ = '\0';

  return ret; /* caller will free */
}

static char *
generate_backup_name (const char *filename)
{
  char *ret;

  assert (backup_extension != NULL);

  if (asprintf (&ret, "%s%s", filename, backup_extension) == -1) {
    perror ("asprintf");
    exit (EXIT_FAILURE);
  }

  return ret; /* caller will free */
}
