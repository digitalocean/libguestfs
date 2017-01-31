/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/fish.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
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

#include <config.h>

/* It is safe to call deprecated functions from this file. */
#undef GUESTFS_WARN_DEPRECATED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <libintl.h>
#include <errno.h>

#include "full-write.h"
#include "xstrtol.h"
#include "getprogname.h"

#include "guestfs.h"
#include "guestfs-internal-frontend.h"
#include "structs-print.h"

#include "fish.h"
#include "options.h"
#include "fish-cmds.h"
#include "run.h"

/* Valid suffixes allowed for numbers.  See Gnulib xstrtol function. */
static const char xstrtol_suffixes[] = "0kKMGTPEZY";


static void
print_inotify_event_list (struct guestfs_inotify_event_list *inotify_events)
{
  size_t i;

  for (i = 0; i < inotify_events->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_inotify_event_indent (&inotify_events->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_hivex_value_list (struct guestfs_hivex_value_list *hivex_values)
{
  size_t i;

  for (i = 0; i < hivex_values->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_hivex_value_indent (&hivex_values->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_isoinfo (struct guestfs_isoinfo *isoinfo)
{
  guestfs_int_print_isoinfo_indent (isoinfo, stdout, "\n", "");
}

int
run_aug_mv (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *src;
  const char *dest;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  src = argv[i++];
  dest = argv[i++];
  r = guestfs_aug_mv (g, src, dest);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_available_all_groups (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_available_all_groups (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_blockdev_getbsz (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_blockdev_getbsz (g, device);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_blockdev_getro (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_blockdev_getro (g, device);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_blockdev_setbsz (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int blocksize;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "blocksize", "xstrtoll", xerr);
      goto out_blocksize;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "blocksize");
      goto out_blocksize;
    }
    /* The check above should ensure this assignment does not overflow. */
    blocksize = r;
  }
  r = guestfs_blockdev_setbsz (g, device, blocksize);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

int
run_btrfs_qgroup_remove (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *src;
  const char *dst;
  char *path;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  src = argv[i++];
  dst = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_btrfs_qgroup_remove (g, src, dst, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_btrfs_quota_enable (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *fs;
  int enable;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  fs = win_prefix (argv[i++]); /* process "win:" prefix */
  if (fs == NULL) goto out_fs;
  switch (guestfs_int_is_true (argv[i++])) {
    case -1:
      fprintf (stderr,
               _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
               getprogname (), argv[i-1]);
      goto out_enable;
    case 0:  enable = 0; break;
    default: enable = 1;
  }
  r = guestfs_btrfs_quota_enable (g, fs, enable);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_enable:
  free (fs);
 out_fs:
 out_noargs:
  return ret;
}

int
run_checksums_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *csumtype;
  char *directory;
  char *sumsfile;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  csumtype = argv[i++];
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  sumsfile = file_out (argv[i++]);
  if (sumsfile == NULL) goto out_sumsfile;
  r = guestfs_checksums_out (g, csumtype, directory, sumsfile);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (sumsfile);
 out_sumsfile:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}

int
run_cp_a (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *src;
  char *dest;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  src = win_prefix (argv[i++]); /* process "win:" prefix */
  if (src == NULL) goto out_src;
  dest = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dest == NULL) goto out_dest;
  r = guestfs_cp_a (g, src, dest);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (dest);
 out_dest:
  free (src);
 out_src:
 out_noargs:
  return ret;
}

int
run_df (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_df (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_disk_format (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *filename;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  filename = argv[i++];
  r = guestfs_disk_format (g, filename);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_egrepi (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  const char *regex;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  regex = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_egrepi (g, regex, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_fallocate (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  int len;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "len", "xstrtoll", xerr);
      goto out_len;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "len");
      goto out_len;
    }
    /* The check above should ensure this assignment does not overflow. */
    len = r;
  }
  r = guestfs_fallocate (g, path, len);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_len:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_fallocate64 (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  int64_t len;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "len", "xstrtoll", xerr);
      goto out_len;
    }
    len = r;
  }
  r = guestfs_fallocate64 (g, path, len);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_len:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_fgrep (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  const char *pattern;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  pattern = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_fgrep (g, pattern, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_file (g, path);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_filesize (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;
  char *file;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  file = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file == NULL) goto out_file;
  r = guestfs_filesize (g, file);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
  free (file);
 out_file:
 out_noargs:
  return ret;
}

int
run_filesystem_available (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *filesystem;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  filesystem = argv[i++];
  r = guestfs_filesystem_available (g, filesystem);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_fill (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int c;
  int len;
  char *path;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "c", "xstrtoll", xerr);
      goto out_c;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "c");
      goto out_c;
    }
    /* The check above should ensure this assignment does not overflow. */
    c = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "len", "xstrtoll", xerr);
      goto out_len;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "len");
      goto out_len;
    }
    /* The check above should ensure this assignment does not overflow. */
    len = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_fill (g, c, len, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_len:
 out_c:
 out_noargs:
  return ret;
}

int
run_find (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  char *directory;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  r = guestfs_find (g, directory);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}

int
run_get_direct (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_direct (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_get_hv (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_hv (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_get_libvirt_requested_credentials (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_libvirt_requested_credentials (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_head (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_head (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_hivex_node_name (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  int64_t nodeh;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "nodeh", "xstrtoll", xerr);
      goto out_nodeh;
    }
    nodeh = r;
  }
  r = guestfs_hivex_node_name (g, nodeh);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_nodeh:
 out_noargs:
  return ret;
}

int
run_hivex_node_values (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_hivex_value_list *r;
  int64_t nodeh;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "nodeh", "xstrtoll", xerr);
      goto out_nodeh;
    }
    nodeh = r;
  }
  r = guestfs_hivex_node_values (g, nodeh);
  if (r == NULL) goto out;
  ret = 0;
  print_hivex_value_list (r);
  guestfs_free_hivex_value_list (r);
 out:
 out_nodeh:
 out_noargs:
  return ret;
}

int
run_inotify_read (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_inotify_event_list *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_inotify_read (g);
  if (r == NULL) goto out;
  ret = 0;
  print_inotify_event_list (r);
  guestfs_free_inotify_event_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_inspect_get_mountpoints (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_mountpoints (g, root);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_inspect_get_package_management (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_package_management (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_inspect_get_product_name (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_product_name (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_isoinfo (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_isoinfo *r;
  char *isofile;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  isofile = win_prefix (argv[i++]); /* process "win:" prefix */
  if (isofile == NULL) goto out_isofile;
  r = guestfs_isoinfo (g, isofile);
  if (r == NULL) goto out;
  ret = 0;
  print_isoinfo (r);
  guestfs_free_isoinfo (r);
 out:
  free (isofile);
 out_isofile:
 out_noargs:
  return ret;
}

int
run_journal_close (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_journal_close (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_lgetxattr (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  size_t size;
  char *path;
  const char *name;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  name = argv[i++];
  r = guestfs_lgetxattr (g, path, name, &size);
  if (r == NULL) goto out;
  if (full_write (1, r, size) != size) {
    perror ("write");
    free (r);
    goto out;
  }
  ret = 0;
  free (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_list_9p (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_list_9p (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_list_ldm_partitions (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_list_ldm_partitions (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_luks_format_cipher (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  char *key;
  int keyslot;
  const char *cipher;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  key = read_key ("key");
  if (keys_from_stdin)
    input_lineno++;
  if (key == NULL) goto out_key;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "keyslot", "xstrtoll", xerr);
      goto out_keyslot;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "keyslot");
      goto out_keyslot;
    }
    /* The check above should ensure this assignment does not overflow. */
    keyslot = r;
  }
  cipher = argv[i++];
  r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_keyslot:
  free (key);
 out_key:
 out_noargs:
  return ret;
}

int
run_lvm_clear_filter (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_lvm_clear_filter (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_lvs (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_lvs (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_max_disks (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_max_disks (g);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_md_detail (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  const char *md;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  md = argv[i++];
  r = guestfs_md_detail (g, md);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_mke2journal_L (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int blocksize;
  const char *label;
  const char *device;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "blocksize", "xstrtoll", xerr);
      goto out_blocksize;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "blocksize");
      goto out_blocksize;
    }
    /* The check above should ensure this assignment does not overflow. */
    blocksize = r;
  }
  label = argv[i++];
  device = argv[i++];
  r = guestfs_mke2journal_L (g, blocksize, label, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

int
run_mkswap (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  struct guestfs_mkswap_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkswap_opts_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "label:")) {
      optargs_s.label = &argv[i][6];
      this_mask = GUESTFS_MKSWAP_OPTS_LABEL_BITMASK;
      this_arg = "label";
    }
    else if (STRPREFIX (argv[i], "uuid:")) {
      optargs_s.uuid = &argv[i][5];
      this_mask = GUESTFS_MKSWAP_OPTS_UUID_BITMASK;
      this_arg = "uuid";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_mkswap_opts_argv (g, device, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_mkswap_L (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *label;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  label = argv[i++];
  device = argv[i++];
  r = guestfs_mkswap_L (g, label, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_mktemp (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  char *tmpl;
  struct guestfs_mktemp_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mktemp_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  tmpl = win_prefix (argv[i++]); /* process "win:" prefix */
  if (tmpl == NULL) goto out_tmpl;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "suffix:")) {
      optargs_s.suffix = &argv[i][7];
      this_mask = GUESTFS_MKTEMP_SUFFIX_BITMASK;
      this_arg = "suffix";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_mktemp_argv (g, tmpl, optargs);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (tmpl);
 out_tmpl:
 out_noargs:
  return ret;
}

int
run_mount_loop (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *file;
  char *mountpoint;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  file = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file == NULL) goto out_file;
  mountpoint = win_prefix (argv[i++]); /* process "win:" prefix */
  if (mountpoint == NULL) goto out_mountpoint;
  r = guestfs_mount_loop (g, file, mountpoint);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (mountpoint);
 out_mountpoint:
  free (file);
 out_file:
 out_noargs:
  return ret;
}

int
run_mount_vfs (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *options;
  const char *vfstype;
  const char *mountable;
  const char *mountpoint;
  size_t i = 0;

  if (argc != 4) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  options = argv[i++];
  vfstype = argv[i++];
  mountable = argv[i++];
  mountpoint = argv[i++];
  r = guestfs_mount_vfs (g, options, vfstype, mountable, mountpoint);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_part_set_mbr_id (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int partnum;
  int idbyte;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "partnum", "xstrtoll", xerr);
      goto out_partnum;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "partnum");
      goto out_partnum;
    }
    /* The check above should ensure this assignment does not overflow. */
    partnum = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "idbyte", "xstrtoll", xerr);
      goto out_idbyte;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "idbyte");
      goto out_idbyte;
    }
    /* The check above should ensure this assignment does not overflow. */
    idbyte = r;
  }
  r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_idbyte:
 out_partnum:
 out_noargs:
  return ret;
}

int
run_pread_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  size_t size;
  const char *device;
  int count;
  int64_t offset;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "count", "xstrtoll", xerr);
      goto out_count;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "count");
      goto out_count;
    }
    /* The check above should ensure this assignment does not overflow. */
    count = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "offset", "xstrtoll", xerr);
      goto out_offset;
    }
    offset = r;
  }
  r = guestfs_pread_device (g, device, count, offset, &size);
  if (r == NULL) goto out;
  if (full_write (1, r, size) != size) {
    perror ("write");
    free (r);
    goto out;
  }
  ret = 0;
  free (r);
 out:
 out_offset:
 out_count:
 out_noargs:
  return ret;
}

int
run_pvchange_uuid (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_pvchange_uuid (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_pvchange_uuid_all (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_pvchange_uuid_all (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_pvresize_size (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int64_t size;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "size", "xstrtoll", xerr);
      goto out_size;
    }
    size = r;
  }
  r = guestfs_pvresize_size (g, device, size);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
 out_noargs:
  return ret;
}

int
run_read_lines (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_read_lines (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_remount (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *mountpoint;
  struct guestfs_remount_argv optargs_s = { .bitmask = 0 };
  struct guestfs_remount_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  mountpoint = win_prefix (argv[i++]); /* process "win:" prefix */
  if (mountpoint == NULL) goto out_mountpoint;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "rw:")) {
      switch (guestfs_int_is_true (&argv[i][3])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][3]);
          goto out;
        case 0:  optargs_s.rw = 0; break;
        default: optargs_s.rw = 1;
      }
      this_mask = GUESTFS_REMOUNT_RW_BITMASK;
      this_arg = "rw";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_remount_argv (g, mountpoint, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (mountpoint);
 out_mountpoint:
 out_noargs:
  return ret;
}

int
run_removexattr (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *xattr;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  xattr = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_removexattr (g, xattr, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_resize2fs_size (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int64_t size;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "size", "xstrtoll", xerr);
      goto out_size;
    }
    size = r;
  }
  r = guestfs_resize2fs_size (g, device, size);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
 out_noargs:
  return ret;
}

int
run_rm_f (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_rm_f (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_rsync_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *src;
  const char *remote;
  struct guestfs_rsync_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_out_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 4) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  src = win_prefix (argv[i++]); /* process "win:" prefix */
  if (src == NULL) goto out_src;
  remote = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "archive:")) {
      switch (guestfs_int_is_true (&argv[i][8])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][8]);
          goto out;
        case 0:  optargs_s.archive = 0; break;
        default: optargs_s.archive = 1;
      }
      this_mask = GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK;
      this_arg = "archive";
    }
    else if (STRPREFIX (argv[i], "deletedest:")) {
      switch (guestfs_int_is_true (&argv[i][11])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][11]);
          goto out;
        case 0:  optargs_s.deletedest = 0; break;
        default: optargs_s.deletedest = 1;
      }
      this_mask = GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK;
      this_arg = "deletedest";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_rsync_out_argv (g, src, remote, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (src);
 out_src:
 out_noargs:
  return ret;
}

int
run_set_e2generation (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *file;
  int64_t generation;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  file = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file == NULL) goto out_file;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "generation", "xstrtoll", xerr);
      goto out_generation;
    }
    generation = r;
  }
  r = guestfs_set_e2generation (g, file, generation);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_generation:
  free (file);
 out_file:
 out_noargs:
  return ret;
}

int
run_set_label (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *mountable;
  const char *label;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  mountable = argv[i++];
  label = argv[i++];
  r = guestfs_set_label (g, mountable, label);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_sfdisk_kernel_geometry (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_sfdisk_kernel_geometry (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_sleep (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int secs;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "secs", "xstrtoll", xerr);
      goto out_secs;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "secs");
      goto out_secs;
    }
    /* The check above should ensure this assignment does not overflow. */
    secs = r;
  }
  r = guestfs_sleep (g, secs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_secs:
 out_noargs:
  return ret;
}

int
run_strings_e (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  const char *encoding;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  encoding = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_strings_e (g, encoding, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_sync (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_sync (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_tail_n (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  int nrlines;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "nrlines", "xstrtoll", xerr);
      goto out_nrlines;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "nrlines");
      goto out_nrlines;
    }
    /* The check above should ensure this assignment does not overflow. */
    nrlines = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_tail_n (g, nrlines, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
  free (path);
 out_path:
 out_nrlines:
 out_noargs:
  return ret;
}

int
run_tar_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *directory;
  char *tarfile;
  struct guestfs_tar_out_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_out_opts_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 8) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  directory = argv[i++];
  tarfile = file_out (argv[i++]);
  if (tarfile == NULL) goto out_tarfile;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "compress:")) {
      optargs_s.compress = &argv[i][9];
      this_mask = GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK;
      this_arg = "compress";
    }
    else if (STRPREFIX (argv[i], "numericowner:")) {
      switch (guestfs_int_is_true (&argv[i][13])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][13]);
          goto out;
        case 0:  optargs_s.numericowner = 0; break;
        default: optargs_s.numericowner = 1;
      }
      this_mask = GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK;
      this_arg = "numericowner";
    }
    else if (STRPREFIX (argv[i], "excludes:")) {
      optargs_s.excludes = parse_string_list (&argv[i][9]);
      if (optargs_s.excludes == NULL) goto out;
      this_mask = GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK;
      this_arg = "excludes";
    }
    else if (STRPREFIX (argv[i], "xattrs:")) {
      switch (guestfs_int_is_true (&argv[i][7])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][7]);
          goto out;
        case 0:  optargs_s.xattrs = 0; break;
        default: optargs_s.xattrs = 1;
      }
      this_mask = GUESTFS_TAR_OUT_OPTS_XATTRS_BITMASK;
      this_arg = "xattrs";
    }
    else if (STRPREFIX (argv[i], "selinux:")) {
      switch (guestfs_int_is_true (&argv[i][8])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][8]);
          goto out;
        case 0:  optargs_s.selinux = 0; break;
        default: optargs_s.selinux = 1;
      }
      this_mask = GUESTFS_TAR_OUT_OPTS_SELINUX_BITMASK;
      this_arg = "selinux";
    }
    else if (STRPREFIX (argv[i], "acls:")) {
      switch (guestfs_int_is_true (&argv[i][5])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][5]);
          goto out;
        case 0:  optargs_s.acls = 0; break;
        default: optargs_s.acls = 1;
      }
      this_mask = GUESTFS_TAR_OUT_OPTS_ACLS_BITMASK;
      this_arg = "acls";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_tar_out_opts_argv (g, directory, tarfile, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  if ((optargs_s.bitmask & GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK) &&
      optargs_s.excludes != NULL)
    guestfs_int_free_string_list ((char **) optargs_s.excludes);
  free (tarfile);
 out_tarfile:
 out_noargs:
  return ret;
}

int
run_vfs_type (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *mountable;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  mountable = argv[i++];
  r = guestfs_vfs_type (g, mountable);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_vgcreate (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *volgroup;
  char **physvols;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  volgroup = argv[i++];
  physvols = parse_string_list (argv[i++]);
  if (physvols == NULL) goto out_physvols;
  r = guestfs_vgcreate (g, volgroup, physvols);
  if (r == -1) goto out;
  ret = 0;
 out:
  guestfs_int_free_string_list (physvols);
 out_physvols:
 out_noargs:
  return ret;
}

int
run_wc_c (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_wc_c (g, path);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_zegrep (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  const char *regex;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  regex = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_zegrep (g, regex, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}
