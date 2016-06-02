/* virt-cat
 * Copyright (C) 2010-2012 Red Hat Inc.
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
#include <getopt.h>
#include <errno.h>
#include <locale.h>
#include <assert.h>
#include <libintl.h>

#include "guestfs.h"
#include "options.h"
#include "windows.h"

/* Currently open libguestfs handle. */
guestfs_h *g;

int read_only = 1;
int live = 0;
int verbose = 0;
int keys_from_stdin = 0;
int echo_keys = 0;
const char *libvirt_uri = NULL;
int inspector = 1;

static int do_cat (int argc, char *argv[]);

static void __attribute__((noreturn))
usage (int status)
{
  if (status != EXIT_SUCCESS)
    fprintf (stderr, _("Try `%s --help' for more information.\n"),
             guestfs_int_program_name);
  else {
    printf (_("%s: display files in a virtual machine\n"
              "Copyright (C) 2010 Red Hat Inc.\n"
              "Usage:\n"
              "  %s [--options] -d domname file [file ...]\n"
              "  %s [--options] -a disk.img [-a disk.img ...] file [file ...]\n"
              "Options:\n"
              "  -a|--add image       Add image\n"
              "  -c|--connect uri     Specify libvirt URI for -d option\n"
              "  -d|--domain guest    Add disks from libvirt guest\n"
              "  --echo-keys          Don't turn off echo for passphrases\n"
              "  --format[=raw|..]    Force disk format for -a option\n"
              "  --help               Display brief help\n"
              "  --keys-from-stdin    Read passphrases from stdin\n"
              "  -m|--mount dev[:mnt[:opts[:fstype]]]\n"
              "                       Mount dev on mnt (if omitted, /)\n"
              "  -v|--verbose         Verbose messages\n"
              "  -V|--version         Display version and exit\n"
              "  -x                   Trace libguestfs API calls\n"
              "For more information, see the manpage %s(1).\n"),
            guestfs_int_program_name, guestfs_int_program_name,
            guestfs_int_program_name, guestfs_int_program_name);
  }
  exit (status);
}

int
main (int argc, char *argv[])
{
  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEBASEDIR);
  textdomain (PACKAGE);

  enum { HELP_OPTION = CHAR_MAX + 1 };

  static const char *options = "a:c:d:m:vVx";
  static const struct option long_options[] = {
    { "add", 1, 0, 'a' },
    { "connect", 1, 0, 'c' },
    { "domain", 1, 0, 'd' },
    { "echo-keys", 0, 0, 0 },
    { "format", 2, 0, 0 },
    { "help", 0, 0, HELP_OPTION },
    { "keys-from-stdin", 0, 0, 0 },
    { "long-options", 0, 0, 0 },
    { "mount", 1, 0, 'm' },
    { "short-options", 0, 0, 0 },
    { "verbose", 0, 0, 'v' },
    { "version", 0, 0, 'V' },
    { 0, 0, 0, 0 }
  };
  struct drv *drvs = NULL;
  struct drv *drv;
  struct mp *mps = NULL;
  struct mp *mp;
  char *p;
  const char *format = NULL;
  bool format_consumed = true;
  int c;
  int r;
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
      else if (STREQ (long_options[option_index].name, "short-options"))
        display_short_options (options);
      else if (STREQ (long_options[option_index].name, "keys-from-stdin")) {
        keys_from_stdin = 1;
      } else if (STREQ (long_options[option_index].name, "echo-keys")) {
        echo_keys = 1;
      } else if (STREQ (long_options[option_index].name, "format")) {
        OPTION_format;
      } else {
        fprintf (stderr, _("%s: unknown long option: %s (%d)\n"),
                 guestfs_int_program_name,
                 long_options[option_index].name, option_index);
        exit (EXIT_FAILURE);
      }
      break;

    case 'a':
      OPTION_a;
      break;

    case 'c':
      OPTION_c;
      break;

    case 'd':
      OPTION_d;
      break;

    case 'm':
      OPTION_m;
      inspector = 0;
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
   * virt-cat which is how we detect this.
   */
  if (drvs == NULL) {
    /* argc - 1 because last parameter is the single filename. */
    while (optind < argc - 1) {
      if (strchr (argv[optind], '/') ||
          access (argv[optind], F_OK) == 0) { /* simulate -a option */
        drv = calloc (1, sizeof (struct drv));
        if (!drv) {
          perror ("calloc");
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
          perror ("calloc");
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
  assert (read_only == 1);
  assert (inspector == 1 || mps != NULL);
  assert (live == 0);

  /* User must specify at least one filename on the command line. */
  if (optind >= argc || argc - optind < 1)
    usage (EXIT_FAILURE);

  CHECK_OPTION_format_consumed;

  /* User must have specified some drives. */
  if (drvs == NULL) {
    fprintf (stderr, _("%s: error: you must specify at least one -a or -d option.\n"),
             guestfs_int_program_name);
    usage (EXIT_FAILURE);
  }

  /* Add drives, inspect and mount. */
  add_drives (drvs, 'a');

  if (guestfs_launch (g) == -1)
    exit (EXIT_FAILURE);

  if (mps != NULL)
    mount_mps (mps);
  else
    inspect_mount ();

  /* Free up data structures, no longer needed after this point. */
  free_drives (drvs);
  free_mps (mps);

  r = do_cat (argc - optind, &argv[optind]);

  guestfs_close (g);

  exit (r == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}

static int
do_cat (int argc, char *argv[])
{
  unsigned errors = 0;
  int windows = 0;
  int i;
  char *root;
  CLEANUP_FREE_STRING_LIST char **roots = NULL;

  if (inspector) {
    /* Get root mountpoint.  See: fish/inspect.c:inspect_mount */
    roots = guestfs_inspect_get_roots (g);

    assert (roots);
    assert (roots[0] != NULL);
    assert (roots[1] == NULL);
    root = roots[0];

    /* Windows?  Special handling is required. */
    windows = is_windows (g, root);
  }

  for (i = 0; i < argc; ++i) {
    CLEANUP_FREE char *filename_to_free = NULL;
    const char *filename = argv[i];

    if (windows) {
      filename = filename_to_free = windows_path (g, root, filename,
                                                  1 /* readonly */);
      if (filename == NULL) {
        errors++;
        continue;
      }
    }

    if (guestfs_download (g, filename, "/dev/stdout") == -1)
      errors++;
  }

  return errors == 0 ? 0 : -1;
}
