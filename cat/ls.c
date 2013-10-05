/* virt-ls
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
#include <fcntl.h>
#include <errno.h>
#include <locale.h>
#include <assert.h>
#include <time.h>
#include <libintl.h>

#include "human.h"

#include "guestfs.h"
#include "options.h"

/* Currently open libguestfs handle. */
guestfs_h *g;

int read_only = 1;
int live = 0;
int verbose = 0;
int keys_from_stdin = 0;
int echo_keys = 0;
const char *libvirt_uri = NULL;
int inspector = 1;

static int csv = 0;
static int human = 0;
static int enable_uids = 0;
static int enable_times = 0;
static int time_t_output = 0;
static int time_relative = 0; /* 1 = seconds, 2 = days */
static int enable_extra_stats = 0;
static const char *checksum = NULL;

static time_t now;

static int do_ls (const char *dir);
static int do_ls_l (const char *dir);
static int do_ls_R (const char *dir);
static int do_ls_lR (const char *dir);

static void output_start_line (void);
static void output_end_line (void);
static void output_int64 (int64_t);
static void output_int64_dev (int64_t);
static void output_int64_perms (int64_t);
static void output_int64_size (int64_t);
static void output_int64_time (int64_t);
static void output_int64_uid (int64_t);
static void output_string (const char *);
static void output_string_link (const char *);

static int is_reg (int64_t mode);
static int is_dir (int64_t mode);
static int is_chr (int64_t mode);
static int is_blk (int64_t mode);
static int is_fifo (int64_t mode);
static int is_lnk (int64_t mode);
static int is_sock (int64_t mode);

static void __attribute__((noreturn))
usage (int status)
{
  if (status != EXIT_SUCCESS)
    fprintf (stderr, _("Try `%s --help' for more information.\n"),
             program_name);
  else {
    fprintf (stdout,
           _("%s: list files in a virtual machine\n"
             "Copyright (C) 2010-2012 Red Hat Inc.\n"
             "Usage:\n"
             "  %s [--options] -d domname dir [dir ...]\n"
             "  %s [--options] -a disk.img [-a disk.img ...] dir [dir ...]\n"
             "Options:\n"
             "  -a|--add image       Add image\n"
             "  --checksum[=...]     Display file checksums\n"
             "  -c|--connect uri     Specify libvirt URI for -d option\n"
             "  --csv                Comma-Separated Values output\n"
             "  -d|--domain guest    Add disks from libvirt guest\n"
             "  --echo-keys          Don't turn off echo for passphrases\n"
             "  --extra-stats        Display extra stats\n"
             "  --format[=raw|..]    Force disk format for -a option\n"
             "  --help               Display brief help\n"
             "  -h|--human-readable  Human-readable sizes in output\n"
             "  --keys-from-stdin    Read passphrases from stdin\n"
             "  -l|--long            Long listing\n"
             "  -R|--recursive       Recursive listing\n"
             "  --times              Display file times\n"
             "  --time-days          Display file times as days before now\n"
             "  --time-relative      Display file times as seconds before now\n"
             "  --time-t             Display file times as time_t's\n"
             "  --uids               Display UID, GID\n"
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
  /* Current time for --time-days, --time-relative output. */
  time (&now);

  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEBASEDIR);
  textdomain (PACKAGE);

  enum { HELP_OPTION = CHAR_MAX + 1 };

  static const char *options = "a:c:d:hlRvVx";
  static const struct option long_options[] = {
    { "add", 1, 0, 'a' },
    { "checksum", 2, 0, 0 },
    { "checksums", 2, 0, 0 },
    { "csv", 0, 0, 0 },
    { "connect", 1, 0, 'c' },
    { "domain", 1, 0, 'd' },
    { "echo-keys", 0, 0, 0 },
    { "extra-stat", 0, 0, 0 },
    { "extra-stats", 0, 0, 0 },
    { "format", 2, 0, 0 },
    { "help", 0, 0, HELP_OPTION },
    { "human-readable", 0, 0, 'h' },
    { "keys-from-stdin", 0, 0, 0 },
    { "long", 0, 0, 'l' },
    { "long-options", 0, 0, 0 },
    { "recursive", 0, 0, 'R' },
    { "time", 0, 0, 0 },
    { "times", 0, 0, 0 },
    { "time-days", 0, 0, 0 },
    { "time-relative", 0, 0, 0 },
    { "time-t", 0, 0, 0 },
    { "uid", 0, 0, 0 },
    { "uids", 0, 0, 0 },
    { "verbose", 0, 0, 'v' },
    { "version", 0, 0, 'V' },
    { 0, 0, 0, 0 }
  };
  struct drv *drvs = NULL;
  struct drv *drv;
  const char *format = NULL;
  int c;
  int option_index;
#define MODE_LS_L  1
#define MODE_LS_R  2
#define MODE_LS_LR (MODE_LS_L|MODE_LS_R)
  int mode = 0;

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
      } else if (STREQ (long_options[option_index].name, "checksum") ||
                 STREQ (long_options[option_index].name, "checksums")) {
        if (!optarg || STREQ (optarg, ""))
          checksum = "md5";
        else
          checksum = optarg;
      } else if (STREQ (long_options[option_index].name, "csv")) {
        csv = 1;
      } else if (STREQ (long_options[option_index].name, "extra-stat") ||
                 STREQ (long_options[option_index].name, "extra-stats")) {
        enable_extra_stats = 1;
      } else if (STREQ (long_options[option_index].name, "time") ||
                 STREQ (long_options[option_index].name, "times")) {
        enable_times = 1;
      } else if (STREQ (long_options[option_index].name, "time-t")) {
        enable_times = 1;
        time_t_output = 1;
      } else if (STREQ (long_options[option_index].name, "time-relative")) {
        enable_times = 1;
        time_t_output = 1;
        time_relative = 1;
      } else if (STREQ (long_options[option_index].name, "time-days")) {
        enable_times = 1;
        time_t_output = 1;
        time_relative = 2;
      } else if (STREQ (long_options[option_index].name, "uid") ||
                 STREQ (long_options[option_index].name, "uids")) {
        enable_uids = 1;
      } else {
        fprintf (stderr, _("%s: unknown long option: %s (%d)\n"),
                 program_name, long_options[option_index].name, option_index);
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

    case 'h':
      human = 1;
      break;

    case 'l':
      mode |= MODE_LS_L;
      break;

    case 'R':
      mode |= MODE_LS_R;
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
   * virt-ls which is how we detect this.
   */
  if (drvs == NULL) {
    /* argc - 1 because last parameter is the single directory name. */
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
  assert (read_only == 1);
  assert (inspector == 1);
  assert (live == 0);

  /* Many flags only apply to -lR mode. */
  if (mode != MODE_LS_LR &&
      (csv || human || enable_uids || enable_times || enable_extra_stats ||
       checksum)) {
    fprintf (stderr, _("%s: used a flag which can only be combined with -lR mode\nFor more information, read the virt-ls(1) man page.\n"),
             program_name);
    exit (EXIT_FAILURE);
  }

  /* CSV && human is unsafe because spreadsheets fail to parse these
   * fields correctly.  (RHBZ#600977).
   */
  if (human && csv) {
    fprintf (stderr, _("%s: you cannot use -h and --csv options together.\n"),
             program_name);
    exit (EXIT_FAILURE);
  }

  /* User must specify at least one directory name on the command line. */
  if (optind >= argc || argc - optind < 1)
    usage (EXIT_FAILURE);

  /* User must have specified some drives. */
  if (drvs == NULL)
    usage (EXIT_FAILURE);

  /* Add drives, inspect and mount.  Note that inspector is always true,
   * and there is no -m option.
   */
  add_drives (drvs, 'a');

  if (guestfs_launch (g) == -1)
    exit (EXIT_FAILURE);

  inspect_mount ();

  /* Free up data structures, no longer needed after this point. */
  free_drives (drvs);

  unsigned errors = 0;

  while (optind < argc) {
    const char *dir = argv[optind];

    switch (mode) {
    case 0:                     /* no -l or -R option */
      if (do_ls (dir) == -1)
        errors++;
      break;

    case MODE_LS_L:             /* virt-ls -l */
      if (do_ls_l (dir) == -1)
        errors++;
      break;

    case MODE_LS_R:             /* virt-ls -R */
      if (do_ls_R (dir) == -1)
        errors++;
      break;

    case MODE_LS_LR:            /* virt-ls -lR */
      if (do_ls_lR (dir) == -1)
        errors++;
      break;

    default:
      abort ();                 /* can't happen */
    }

    optind++;
  }

  guestfs_close (g);

  exit (errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}

static int
do_ls (const char *dir)
{
  size_t i;
  CLEANUP_FREE_STRING_LIST char **lines = guestfs_ls (g, dir);

  if (lines == NULL)
    return -1;

  for (i = 0; lines[i] != NULL; ++i)
    printf ("%s\n", lines[i]);

  return 0;
}

static int
do_ls_l (const char *dir)
{
  CLEANUP_FREE char *out = guestfs_ll (g, dir);

  if (out == NULL)
    return -1;

  printf ("%s", out);

  return 0;
}

static int
do_ls_R (const char *dir)
{
  size_t i;
  CLEANUP_FREE_STRING_LIST char **dirs = guestfs_find (g, dir);

  if (dirs == NULL)
    return -1;

  for (i = 0; dirs[i] != NULL; ++i)
    puts (dirs[i]);

  return 0;
}

/* Adapted from
https://rwmj.wordpress.com/2010/12/15/tip-audit-virtual-machine-for-setuid-files/
*/
static char *full_path (const char *dir, const char *name);
static int show_file (const char *dir, const char *name, const struct guestfs_stat *stat, const struct guestfs_xattr_list *xattrs);

typedef int (*visitor_function) (const char *dir, const char *name, const struct guestfs_stat *stat, const struct guestfs_xattr_list *xattrs);

static int
visit (int depth, const char *dir, visitor_function f)
{
  /* Call 'f' with the top directory.  Note that ordinary recursive
   * visits will not otherwise do this, so we have to have a special
   * case.
   */
  if (depth == 0) {
    CLEANUP_FREE_STAT struct guestfs_stat *stat = NULL;
    CLEANUP_FREE_XATTR_LIST struct guestfs_xattr_list *xattrs = NULL;
    int r;

    stat = guestfs_lstat (g, dir);
    if (stat == NULL)
      return -1;

    xattrs = guestfs_lgetxattrs (g, dir);
    if (xattrs == NULL)
      return -1;

    r = f (dir, NULL, stat, xattrs);

    if (r == -1)
      return -1;
  }

  size_t i, xattrp;
  CLEANUP_FREE_STRING_LIST char **names = NULL;
  CLEANUP_FREE_STAT_LIST struct guestfs_stat_list *stats = NULL;
  CLEANUP_FREE_XATTR_LIST struct guestfs_xattr_list *xattrs = NULL;

  names = guestfs_ls (g, dir);
  if (names == NULL)
    return -1;

  stats = guestfs_lstatlist (g, dir, names);
  if (stats == NULL)
    return -1;

  xattrs = guestfs_lxattrlist (g, dir, names);
  if (xattrs == NULL)
    return -1;

  /* Call function on everything in this directory. */
  for (i = 0, xattrp = 0; names[i] != NULL; ++i, ++xattrp) {
    CLEANUP_FREE char *path = NULL;
    struct guestfs_xattr_list file_xattrs;
    size_t nr_xattrs;

    assert (stats->len >= i);
    assert (xattrs->len >= xattrp);

    /* Find the list of extended attributes for this file. */
    assert (strlen (xattrs->val[xattrp].attrname) == 0);

    if (xattrs->val[xattrp].attrval_len == 0) {
      fprintf (stderr, _("%s: error getting extended attrs for %s %s\n"),
               program_name, dir, names[i]);
      return -1;
    }
    /* attrval is not \0-terminated. */
    char attrval[xattrs->val[xattrp].attrval_len+1];
    memcpy (attrval, xattrs->val[xattrp].attrval,
            xattrs->val[xattrp].attrval_len);
    attrval[xattrs->val[xattrp].attrval_len] = '\0';
    if (sscanf (attrval, "%zu", &nr_xattrs) != 1) {
      fprintf (stderr, _("%s: error: cannot parse xattr count for %s %s\n"),
               program_name, dir, names[i]);
      return -1;
    }

    file_xattrs.len = nr_xattrs;
    file_xattrs.val = &xattrs->val[xattrp];
    xattrp += nr_xattrs;

    /* Call the function. */
    if (f (dir, names[i], &stats->val[i], &file_xattrs) == -1)
      return -1;

    /* Recursively call visit, but only on directories. */
    if (is_dir (stats->val[i].mode)) {
      path = full_path (dir, names[i]);
      if (visit (depth + 1, path, f) == -1)
        return -1;
    }
  }

  return 0;
}

static char *
full_path (const char *dir, const char *name)
{
  int r;
  char *path;

  if (STREQ (dir, "/"))
    r = asprintf (&path, "/%s", name ? name : "");
  else if (name)
    r = asprintf (&path, "%s/%s", dir, name);
  else
    r = asprintf (&path, "%s", dir);

  if (r == -1) {
    perror ("asprintf");
    exit (EXIT_FAILURE);
  }

  return path;
}

static int
do_ls_lR (const char *dir)
{
  return visit (0, dir, show_file);
}

/* This is the function which is called to display all files and
 * directories, and it's where the magic happens.  We are called with
 * full stat and extended attributes for each file, so there is no
 * penalty for displaying anything in those structures.  However if we
 * need other things (eg. checksum) we may have to go back to the
 * appliance and then there can be a very large penalty.
 */
static int
show_file (const char *dir, const char *name,
           const struct guestfs_stat *stat,
           const struct guestfs_xattr_list *xattrs)
{
  const char *filetype;
  CLEANUP_FREE char *path = NULL, *csum = NULL, *link = NULL;

  /* Display the basic fields. */
  output_start_line ();

  if (is_reg (stat->mode))
    filetype = "-";
  else if (is_dir (stat->mode))
    filetype = "d";
  else if (is_chr (stat->mode))
    filetype = "c";
  else if (is_blk (stat->mode))
    filetype = "b";
  else if (is_fifo (stat->mode))
    filetype = "p";
  else if (is_lnk (stat->mode))
    filetype = "l";
  else if (is_sock (stat->mode))
    filetype = "s";
  else
    filetype = "u";
  output_string (filetype);
  output_int64_perms (stat->mode & 07777);

  output_int64_size (stat->size);

  /* Display extra fields when enabled. */
  if (enable_uids) {
    output_int64_uid (stat->uid);
    output_int64_uid (stat->gid);
  }

  if (enable_times) {
    output_int64_time (stat->atime);
    output_int64_time (stat->mtime);
    output_int64_time (stat->ctime);
  }

  if (enable_extra_stats) {
    output_int64_dev (stat->dev);
    output_int64 (stat->ino);
    output_int64 (stat->nlink);
    output_int64_dev (stat->rdev);
    output_int64 (stat->blocks);
  }

  /* Disabled for now -- user would definitely want these to be interpreted.
  if (enable_xattrs)
    output_xattrs (xattrs);
  */

  path = full_path (dir, name);

  if (checksum && is_reg (stat->mode)) {
    csum = guestfs_checksum (g, checksum, path);
    if (!csum)
      exit (EXIT_FAILURE);

    output_string (csum);
  }

  output_string (path);

  if (is_lnk (stat->mode))
    /* XXX Fix this for NTFS. */
    link = guestfs_readlink (g, path);
  if (link)
    output_string_link (link);

  output_end_line ();

  return 0;
}

/* Output functions.
 *
 * Note that we have to be careful to check return values from printf
 * in these functions, because we want to catch ENOSPC errors.
 */
static int field;
static void
next_field (void)
{
  int c = csv ? ',' : ' ';

  field++;
  if (field == 1) return;

  if (putchar (c) == EOF) {
    perror ("putchar");
    exit (EXIT_FAILURE);
  }
}

static void
output_start_line (void)
{
  field = 0;
}

static void
output_end_line (void)
{
  if (printf ("\n") < 0) {
    perror ("printf");
    exit (EXIT_FAILURE);
  }
}

static void
output_string (const char *s)
{
  next_field ();

  if (!csv) {
  print_no_quoting:
    if (printf ("%s", s) < 0) {
      perror ("printf");
      exit (EXIT_FAILURE);
    }
  }
  else {
    /* Quote CSV string without requiring an external module. */
    size_t i, len;
    int needs_quoting = 0;

    len = strlen (s);

    for (i = 0; i < len; ++i) {
      if (s[i] == ' ' || s[i] == '"' ||
          s[i] == '\n' || s[i] == ',') {
        needs_quoting = 1;
        break;
      }
    }

    if (!needs_quoting)
      goto print_no_quoting;

    /* Quoting for CSV fields. */
    if (putchar ('"') == EOF) {
      perror ("putchar");
      exit (EXIT_FAILURE);
    }
    for (i = 0; i < len; ++i) {
      if (s[i] == '"') {
        if (putchar ('"') == EOF || putchar ('"') == EOF) {
          perror ("putchar");
          exit (EXIT_FAILURE);
        }
      } else {
        if (putchar (s[i]) == EOF) {
          perror ("putchar");
          exit (EXIT_FAILURE);
        }
      }
    }
    if (putchar ('"') == EOF) {
      perror ("putchar");
      exit (EXIT_FAILURE);
    }
  }
}

static void
output_string_link (const char *link)
{
  if (csv)
    output_string (link);
  else {
    next_field ();

    if (printf ("-> %s", link) < 0) {
      perror ("printf");
      exit (EXIT_FAILURE);
    }
  }
}

static void
output_int64 (int64_t i)
{
  next_field ();
  /* csv doesn't need escaping */
  if (printf ("%" PRIi64, i) < 0) {
    perror ("printf");
    exit (EXIT_FAILURE);
  }
}

static void
output_int64_size (int64_t size)
{
  char buf[LONGEST_HUMAN_READABLE];
  int hopts = human_round_to_nearest|human_autoscale|human_base_1024|human_SI;
  int r;

  next_field ();

  if (!csv) {
    if (!human)
      r = printf ("%10" PRIi64, size);
    else
      r = printf ("%10s",
                  human_readable ((uintmax_t) size, buf, hopts, 1, 1));
  } else {
    /* CSV is the same as non-CSV but we don't need to right-align. */
    if (!human)
      r = printf ("%" PRIi64, size);
    else
      r = printf ("%s",
                  human_readable ((uintmax_t) size, buf, hopts, 1, 1));
  }

  if (r < 0) {
    perror ("printf");
    exit (EXIT_FAILURE);
  }
}

static void
output_int64_perms (int64_t i)
{
  next_field ();
  /* csv doesn't need escaping */
  if (printf ("%04" PRIo64, i) < 0) {
    perror ("printf");
    exit (EXIT_FAILURE);
  }
}

static void
output_int64_time (int64_t i)
{
  int r;

  next_field ();

  /* csv doesn't need escaping */
  if (time_t_output) {
    switch (time_relative) {
    case 0:                     /* --time-t */
      r = printf ("%10" PRIi64, i);
      break;
    case 1:                     /* --time-relative */
      r = printf ("%8" PRIi64, now - i);
      break;
    case 2:                     /* --time-days */
    default:
      r = printf ("%3" PRIi64, (now - i) / 86400);
      break;
    }
  }
  else {
    time_t t = (time_t) i;
    char buf[64];
    struct tm *tm;

    tm = localtime (&t);
    if (tm == NULL) {
      perror ("localtime");
      exit (EXIT_FAILURE);
    }

    if (strftime (buf, sizeof buf, "%F %T", tm) == 0) {
      perror ("strftime");
      exit (EXIT_FAILURE);
    }

    r = printf ("%s", buf);
  }

  if (r < 0) {
    perror ("printf");
    exit (EXIT_FAILURE);
  }
}

static void
output_int64_uid (int64_t i)
{
  next_field ();
  /* csv doesn't need escaping */
  if (printf ("%4" PRIi64, i) < 0) {
    perror ("printf");
    exit (EXIT_FAILURE);
  }
}

static void
output_int64_dev (int64_t i)
{
  dev_t dev = i;

  next_field ();

  /* csv doesn't need escaping */
  if (printf ("%d:%d", major (dev), minor (dev)) < 0) {
    perror ("printf");
    exit (EXIT_FAILURE);
  }
}

/* In the libguestfs API, modes returned by lstat and friends are
 * defined to contain Linux ABI values.  However since the "current
 * operating system" might not be Linux, we have to hard-code those
 * numbers here.
 */
static int
is_reg (int64_t mode)
{
  return (mode & 0170000) == 0100000;
}

static int
is_dir (int64_t mode)
{
  return (mode & 0170000) == 0040000;
}

static int
is_chr (int64_t mode)
{
  return (mode & 0170000) == 0020000;
}

static int
is_blk (int64_t mode)
{
  return (mode & 0170000) == 0060000;
}

static int
is_fifo (int64_t mode)
{
  return (mode & 0170000) == 0010000;
}

/* symbolic link */
static int
is_lnk (int64_t mode)
{
  return (mode & 0170000) == 0120000;
}

static int
is_sock (int64_t mode)
{
  return (mode & 0170000) == 0140000;
}
