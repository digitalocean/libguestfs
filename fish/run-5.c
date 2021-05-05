/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/fish.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
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
#include "guestfs-utils.h"
#include "structs-print.h"

#include "fish.h"
#include "options.h"
#include "fish-cmds.h"
#include "run.h"

/* Valid suffixes allowed for numbers.  See Gnulib xstrtol function. */
static const char xstrtol_suffixes[] = "0kKMGTPEZY";


static void
print_lvm_lv_list (struct guestfs_lvm_lv_list *lvm_lvs)
{
  size_t i;

  for (i = 0; i < lvm_lvs->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_lvm_lv_indent (&lvm_lvs->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_mdstat_list (struct guestfs_mdstat_list *mdstats)
{
  size_t i;

  for (i = 0; i < mdstats->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_mdstat_indent (&mdstats->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_xfsinfo (struct guestfs_xfsinfo *xfsinfo)
{
  guestfs_int_print_xfsinfo_indent (xfsinfo, stdout, "\n", "");
}

static void
print_isoinfo (struct guestfs_isoinfo *isoinfo)
{
  guestfs_int_print_isoinfo_indent (isoinfo, stdout, "\n", "");
}

static void
print_stat (struct guestfs_stat *stat)
{
  guestfs_int_print_stat_indent (stat, stdout, "\n", "");
}

int
run_acl_set_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  const char *acltype;
  const char *acl;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  acltype = argv[i++];
  acl = argv[i++];
  r = guestfs_acl_set_file (g, path, acltype, acl);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_add_drive_with_if (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *filename;
  const char *iface;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  filename = argv[i++];
  iface = argv[i++];
  r = guestfs_add_drive_with_if (g, filename, iface);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_blockdev_flushbufs (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_blockdev_flushbufs (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_blockdev_setrw (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_blockdev_setrw (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_btrfs_balance_pause (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_btrfs_balance_pause (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_btrfs_device_add (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char **devices;
  char *fs;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  devices = parse_string_list (argv[i++]);
  if (devices == NULL) goto out_devices;
  fs = win_prefix (argv[i++]); /* process "win:" prefix */
  if (fs == NULL) goto out_fs;
  r = guestfs_btrfs_device_add (g, devices, fs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (fs);
 out_fs:
  guestfs_int_free_string_list (devices);
 out_devices:
 out_noargs:
  return ret;
}

int
run_btrfs_filesystem_balance (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *fs;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  fs = win_prefix (argv[i++]); /* process "win:" prefix */
  if (fs == NULL) goto out_fs;
  r = guestfs_btrfs_filesystem_balance (g, fs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (fs);
 out_fs:
 out_noargs:
  return ret;
}

int
run_btrfs_filesystem_show (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_btrfs_filesystem_show (g, device);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_btrfs_qgroup_assign (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_btrfs_qgroup_assign (g, src, dst, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_btrfs_replace (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *srcdev;
  const char *targetdev;
  char *mntpoint;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  srcdev = argv[i++];
  targetdev = argv[i++];
  mntpoint = win_prefix (argv[i++]); /* process "win:" prefix */
  if (mntpoint == NULL) goto out_mntpoint;
  r = guestfs_btrfs_replace (g, srcdev, targetdev, mntpoint);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (mntpoint);
 out_mntpoint:
 out_noargs:
  return ret;
}

int
run_btrfs_scrub_cancel (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_btrfs_scrub_cancel (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_btrfs_subvolume_get_default (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;
  char *fs;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  fs = win_prefix (argv[i++]); /* process "win:" prefix */
  if (fs == NULL) goto out_fs;
  r = guestfs_btrfs_subvolume_get_default (g, fs);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
  free (fs);
 out_fs:
 out_noargs:
  return ret;
}

int
run_btrfstune_seeding (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int seeding;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  switch (guestfs_int_is_true (argv[i++])) {
    case -1:
      fprintf (stderr,
               _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
               getprogname (), argv[i-1]);
      goto out_seeding;
    case 0:  seeding = 0; break;
    default: seeding = 1;
  }
  r = guestfs_btrfstune_seeding (g, device, seeding);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_seeding:
 out_noargs:
  return ret;
}

int
run_c_pointer (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_c_pointer (g);
  if (r == -1) goto out;
  ret = 0;
  printf ("%s%" PRIx64 "\n", r != 0 ? "0x" : "", (uint64_t) r);
 out:
 out_noargs:
  return ret;
}

int
run_cap_set_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  const char *cap;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  cap = argv[i++];
  r = guestfs_cap_set_file (g, path, cap);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_copy_file_to_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *src;
  const char *dest;
  struct guestfs_copy_file_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 7) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  src = win_prefix (argv[i++]); /* process "win:" prefix */
  if (src == NULL) goto out_src;
  dest = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "srcoffset:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.srcoffset", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.srcoffset = r;
      }
      this_mask = GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
      this_arg = "srcoffset";
    }
    else if (STRPREFIX (argv[i], "destoffset:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][11], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.destoffset", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.destoffset = r;
      }
      this_mask = GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
      this_arg = "destoffset";
    }
    else if (STRPREFIX (argv[i], "size:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][5], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.size", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.size = r;
      }
      this_mask = GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
      this_arg = "size";
    }
    else if (STRPREFIX (argv[i], "sparse:")) {
      switch (guestfs_int_is_true (&argv[i][7])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][7]);
          goto out;
        case 0:  optargs_s.sparse = 0; break;
        default: optargs_s.sparse = 1;
      }
      this_mask = GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK;
      this_arg = "sparse";
    }
    else if (STRPREFIX (argv[i], "append:")) {
      switch (guestfs_int_is_true (&argv[i][7])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][7]);
          goto out;
        case 0:  optargs_s.append = 0; break;
        default: optargs_s.append = 1;
      }
      this_mask = GUESTFS_COPY_FILE_TO_DEVICE_APPEND_BITMASK;
      this_arg = "append";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given more than once\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (src);
 out_src:
 out_noargs:
  return ret;
}

int
run_copy_file_to_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *src;
  char *dest;
  struct guestfs_copy_file_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 7) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  src = win_prefix (argv[i++]); /* process "win:" prefix */
  if (src == NULL) goto out_src;
  dest = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dest == NULL) goto out_dest;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "srcoffset:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.srcoffset", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.srcoffset = r;
      }
      this_mask = GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
      this_arg = "srcoffset";
    }
    else if (STRPREFIX (argv[i], "destoffset:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][11], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.destoffset", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.destoffset = r;
      }
      this_mask = GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
      this_arg = "destoffset";
    }
    else if (STRPREFIX (argv[i], "size:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][5], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.size", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.size = r;
      }
      this_mask = GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
      this_arg = "size";
    }
    else if (STRPREFIX (argv[i], "sparse:")) {
      switch (guestfs_int_is_true (&argv[i][7])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][7]);
          goto out;
        case 0:  optargs_s.sparse = 0; break;
        default: optargs_s.sparse = 1;
      }
      this_mask = GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK;
      this_arg = "sparse";
    }
    else if (STRPREFIX (argv[i], "append:")) {
      switch (guestfs_int_is_true (&argv[i][7])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][7]);
          goto out;
        case 0:  optargs_s.append = 0; break;
        default: optargs_s.append = 1;
      }
      this_mask = GUESTFS_COPY_FILE_TO_FILE_APPEND_BITMASK;
      this_arg = "append";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given more than once\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);
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
run_cpio_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *directory;
  char *cpiofile;
  struct guestfs_cpio_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_cpio_out_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  directory = argv[i++];
  cpiofile = file_out (argv[i++]);
  if (cpiofile == NULL) goto out_cpiofile;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "format:")) {
      optargs_s.format = &argv[i][7];
      this_mask = GUESTFS_CPIO_OUT_FORMAT_BITMASK;
      this_arg = "format";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given more than once\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_cpio_out_argv (g, directory, cpiofile, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (cpiofile);
 out_cpiofile:
 out_noargs:
  return ret;
}

int
run_disk_virtual_size (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;
  const char *filename;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  filename = argv[i++];
  r = guestfs_disk_virtual_size (g, filename);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_download (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *remotefilename;
  char *filename;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  remotefilename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (remotefilename == NULL) goto out_remotefilename;
  filename = file_out (argv[i++]);
  if (filename == NULL) goto out_filename;
  r = guestfs_download (g, remotefilename, filename);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (filename);
 out_filename:
  free (remotefilename);
 out_remotefilename:
 out_noargs:
  return ret;
}

int
run_feature_available (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char **groups;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  groups = parse_string_list (argv[i++]);
  if (groups == NULL) goto out_groups;
  r = guestfs_feature_available (g, groups);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  guestfs_int_free_string_list (groups);
 out_groups:
 out_noargs:
  return ret;
}

int
run_fill_pattern (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *pattern;
  int len;
  char *path;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  pattern = argv[i++];
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
  r = guestfs_fill_pattern (g, pattern, len, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_len:
 out_noargs:
  return ret;
}

int
run_find0 (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *directory;
  char *files;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  files = file_out (argv[i++]);
  if (files == NULL) goto out_files;
  r = guestfs_find0 (g, directory, files);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (files);
 out_files:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}

int
run_get_append (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  const char *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_append (g);
  ret = 0;
  printf ("%s\n", r ? : "(null)");
 out_noargs:
  return ret;
}

int
run_get_memsize (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_memsize (g);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_get_program (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  const char *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_program (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_head_n (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_head_n (g, nrlines, path);
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
run_hivex_commit (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *filename;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  filename = STRNEQ (argv[i], "") ? argv[i] : NULL;
  i++;
  r = guestfs_hivex_commit (g, filename);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_hivex_node_delete_child (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
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
  r = guestfs_hivex_node_delete_child (g, nodeh);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_nodeh:
 out_noargs:
  return ret;
}

int
run_initrd_cat (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  size_t size;
  char *initrdpath;
  const char *filename;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  initrdpath = win_prefix (argv[i++]); /* process "win:" prefix */
  if (initrdpath == NULL) goto out_initrdpath;
  filename = argv[i++];
  r = guestfs_initrd_cat (g, initrdpath, filename, &size);
  if (r == NULL) goto out;
  if (full_write (1, r, size) != size) {
    perror ("write");
    free (r);
    goto out;
  }
  ret = 0;
  free (r);
 out:
  free (initrdpath);
 out_initrdpath:
 out_noargs:
  return ret;
}

int
run_inotify_close (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_inotify_close (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_inspect_get_major_version (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_major_version (g, root);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_inspect_get_osinfo (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_inspect_get_osinfo (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_inspect_get_roots (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_inspect_get_roots (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_is_blockdev (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  struct guestfs_is_blockdev_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_blockdev_opts_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "followsymlinks:")) {
      switch (guestfs_int_is_true (&argv[i][15])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][15]);
          goto out;
        case 0:  optargs_s.followsymlinks = 0; break;
        default: optargs_s.followsymlinks = 1;
      }
      this_mask = GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
      this_arg = "followsymlinks";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given more than once\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_is_blockdev_opts_argv (g, path, optargs);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_is_config (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_is_config (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_is_fifo (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  struct guestfs_is_fifo_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_fifo_opts_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "followsymlinks:")) {
      switch (guestfs_int_is_true (&argv[i][15])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][15]);
          goto out;
        case 0:  optargs_s.followsymlinks = 0; break;
        default: optargs_s.followsymlinks = 1;
      }
      this_mask = GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS_BITMASK;
      this_arg = "followsymlinks";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given more than once\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_is_fifo_opts_argv (g, path, optargs);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_isoinfo_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_isoinfo *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_isoinfo_device (g, device);
  if (r == NULL) goto out;
  ret = 0;
  print_isoinfo (r);
  guestfs_free_isoinfo (r);
 out:
 out_noargs:
  return ret;
}

int
run_journal_next (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_journal_next (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_journal_skip (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;
  int64_t skip;
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
               cmd, "skip", "xstrtoll", xerr);
      goto out_skip;
    }
    skip = r;
  }
  r = guestfs_journal_skip (g, skip);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_skip:
 out_noargs:
  return ret;
}

int
run_ldmtool_volume_partitions (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  const char *diskgroup;
  const char *volume;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  diskgroup = argv[i++];
  volume = argv[i++];
  r = guestfs_ldmtool_volume_partitions (g, diskgroup, volume);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_list_disk_labels (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_list_disk_labels (g);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_list_md_devices (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_list_md_devices (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_ln (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *target;
  char *linkname;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  target = argv[i++];
  linkname = win_prefix (argv[i++]); /* process "win:" prefix */
  if (linkname == NULL) goto out_linkname;
  r = guestfs_ln (g, target, linkname);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (linkname);
 out_linkname:
 out_noargs:
  return ret;
}

int
run_ln_sf (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *target;
  char *linkname;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  target = argv[i++];
  linkname = win_prefix (argv[i++]); /* process "win:" prefix */
  if (linkname == NULL) goto out_linkname;
  r = guestfs_ln_sf (g, target, linkname);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (linkname);
 out_linkname:
 out_noargs:
  return ret;
}

int
run_luks_add_key (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  char *key;
  char *newkey;
  int keyslot;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  key = read_key ("key");
  if (keys_from_stdin)
    input_lineno++;
  if (key == NULL) goto out_key;
  newkey = read_key ("newkey");
  if (keys_from_stdin)
    input_lineno++;
  if (newkey == NULL) goto out_newkey;
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
  r = guestfs_luks_add_key (g, device, key, newkey, keyslot);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_keyslot:
  free (newkey);
 out_newkey:
  free (key);
 out_key:
 out_noargs:
  return ret;
}

int
run_lvcreate (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *logvol;
  const char *volgroup;
  int mbytes;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  logvol = argv[i++];
  volgroup = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "mbytes", "xstrtoll", xerr);
      goto out_mbytes;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mbytes");
      goto out_mbytes;
    }
    /* The check above should ensure this assignment does not overflow. */
    mbytes = r;
  }
  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_mbytes:
 out_noargs:
  return ret;
}

int
run_lvcreate_free (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *logvol;
  const char *volgroup;
  int percent;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  logvol = argv[i++];
  volgroup = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "percent", "xstrtoll", xerr);
      goto out_percent;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "percent");
      goto out_percent;
    }
    /* The check above should ensure this assignment does not overflow. */
    percent = r;
  }
  r = guestfs_lvcreate_free (g, logvol, volgroup, percent);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_percent:
 out_noargs:
  return ret;
}

int
run_lvm_set_filter (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char **devices;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  devices = parse_string_list (argv[i++]);
  if (devices == NULL) goto out_devices;
  r = guestfs_lvm_set_filter (g, devices);
  if (r == -1) goto out;
  ret = 0;
 out:
  guestfs_int_free_string_list (devices);
 out_devices:
 out_noargs:
  return ret;
}

int
run_lvs_full (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_lvm_lv_list *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_lvs_full (g);
  if (r == NULL) goto out;
  ret = 0;
  print_lvm_lv_list (r);
  guestfs_free_lvm_lv_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_md_stat (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_mdstat_list *r;
  const char *md;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  md = argv[i++];
  r = guestfs_md_stat (g, md);
  if (r == NULL) goto out;
  ret = 0;
  print_mdstat_list (r);
  guestfs_free_mdstat_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_mkfs (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *fstype;
  const char *device;
  struct guestfs_mkfs_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 7) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  fstype = argv[i++];
  device = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "blocksize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.blocksize", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.blocksize");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.blocksize = r;
      }
      this_mask = GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
      this_arg = "blocksize";
    }
    else if (STRPREFIX (argv[i], "features:")) {
      optargs_s.features = &argv[i][9];
      this_mask = GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
      this_arg = "features";
    }
    else if (STRPREFIX (argv[i], "inode:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][6], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.inode", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.inode");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.inode = r;
      }
      this_mask = GUESTFS_MKFS_OPTS_INODE_BITMASK;
      this_arg = "inode";
    }
    else if (STRPREFIX (argv[i], "sectorsize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][11], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.sectorsize", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.sectorsize");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.sectorsize = r;
      }
      this_mask = GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
      this_arg = "sectorsize";
    }
    else if (STRPREFIX (argv[i], "label:")) {
      optargs_s.label = &argv[i][6];
      this_mask = GUESTFS_MKFS_OPTS_LABEL_BITMASK;
      this_arg = "label";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given more than once\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_mkfs_b (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  fstype = argv[i++];
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
  device = argv[i++];
  r = guestfs_mkfs_b (g, fstype, blocksize, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

int
run_mkswap_U (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *uuid;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  uuid = argv[i++];
  device = argv[i++];
  r = guestfs_mkswap_U (g, uuid, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_mountpoints (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_mountpoints (g);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_nr_devices (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_nr_devices (g);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_ntfsclone_in (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *backupfile;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  backupfile = file_in (argv[i++]);
  if (backupfile == NULL) goto out_backupfile;
  device = argv[i++];
  r = guestfs_ntfsclone_in (g, backupfile, device);
  if (r == -1) goto out;
  ret = 0;
 out:
  free_file_in (backupfile);
 out_backupfile:
 out_noargs:
  return ret;
}

int
run_parse_environment_list (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char **environment;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  environment = parse_string_list (argv[i++]);
  if (environment == NULL) goto out_environment;
  r = guestfs_parse_environment_list (g, environment);
  if (r == -1) goto out;
  ret = 0;
 out:
  guestfs_int_free_string_list (environment);
 out_environment:
 out_noargs:
  return ret;
}

int
run_part_get_bootable (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int partnum;
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
  r = guestfs_part_get_bootable (g, device, partnum);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_partnum:
 out_noargs:
  return ret;
}

int
run_part_get_gpt_attributes (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;
  const char *device;
  int partnum;
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
  r = guestfs_part_get_gpt_attributes (g, device, partnum);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_partnum:
 out_noargs:
  return ret;
}

int
run_part_set_gpt_type (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int partnum;
  const char *guid;
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
  guid = argv[i++];
  r = guestfs_part_set_gpt_type (g, device, partnum, guid);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_partnum:
 out_noargs:
  return ret;
}

int
run_part_set_name (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int partnum;
  const char *name;
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
  name = argv[i++];
  r = guestfs_part_set_name (g, device, partnum, name);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_partnum:
 out_noargs:
  return ret;
}

int
run_pvremove (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_pvremove (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_scrub_freespace (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *dir;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  dir = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dir == NULL) goto out_dir;
  r = guestfs_scrub_freespace (g, dir);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (dir);
 out_dir:
 out_noargs:
  return ret;
}

int
run_set_attach_method (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *backend;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  backend = argv[i++];
  r = guestfs_set_attach_method (g, backend);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_set_network (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int network;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  switch (guestfs_int_is_true (argv[i++])) {
    case -1:
      fprintf (stderr,
               _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
               getprogname (), argv[i-1]);
      goto out_network;
    case 0:  network = 0; break;
    default: network = 1;
  }
  r = guestfs_set_network (g, network);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_network:
 out_noargs:
  return ret;
}

int
run_set_smp (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int smp;
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
               cmd, "smp", "xstrtoll", xerr);
      goto out_smp;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "smp");
      goto out_smp;
    }
    /* The check above should ensure this assignment does not overflow. */
    smp = r;
  }
  r = guestfs_set_smp (g, smp);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_smp:
 out_noargs:
  return ret;
}

int
run_set_tmpdir (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *tmpdir;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  tmpdir = STRNEQ (argv[i], "") ? argv[i] : NULL;
  i++;
  r = guestfs_set_tmpdir (g, tmpdir);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_set_trace (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int trace;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  switch (guestfs_int_is_true (argv[i++])) {
    case -1:
      fprintf (stderr,
               _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
               getprogname (), argv[i-1]);
      goto out_trace;
    case 0:  trace = 0; break;
    default: trace = 1;
  }
  r = guestfs_set_trace (g, trace);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_trace:
 out_noargs:
  return ret;
}

int
run_set_uuid_random (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_set_uuid_random (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_sfdisk (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int cyls;
  int heads;
  int sectors;
  char **lines;
  size_t i = 0;

  if (argc != 5) {
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
               cmd, "cyls", "xstrtoll", xerr);
      goto out_cyls;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "cyls");
      goto out_cyls;
    }
    /* The check above should ensure this assignment does not overflow. */
    cyls = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "heads", "xstrtoll", xerr);
      goto out_heads;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "heads");
      goto out_heads;
    }
    /* The check above should ensure this assignment does not overflow. */
    heads = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "sectors", "xstrtoll", xerr);
      goto out_sectors;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "sectors");
      goto out_sectors;
    }
    /* The check above should ensure this assignment does not overflow. */
    sectors = r;
  }
  lines = parse_string_list (argv[i++]);
  if (lines == NULL) goto out_lines;
  r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);
  if (r == -1) goto out;
  ret = 0;
 out:
  guestfs_int_free_string_list (lines);
 out_lines:
 out_sectors:
 out_heads:
 out_cyls:
 out_noargs:
  return ret;
}

int
run_sfdiskM (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  char **lines;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  lines = parse_string_list (argv[i++]);
  if (lines == NULL) goto out_lines;
  r = guestfs_sfdiskM (g, device, lines);
  if (r == -1) goto out;
  ret = 0;
 out:
  guestfs_int_free_string_list (lines);
 out_lines:
 out_noargs:
  return ret;
}

int
run_sfdisk_N (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int partnum;
  int cyls;
  int heads;
  int sectors;
  const char *line;
  size_t i = 0;

  if (argc != 6) {
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
               cmd, "cyls", "xstrtoll", xerr);
      goto out_cyls;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "cyls");
      goto out_cyls;
    }
    /* The check above should ensure this assignment does not overflow. */
    cyls = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "heads", "xstrtoll", xerr);
      goto out_heads;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "heads");
      goto out_heads;
    }
    /* The check above should ensure this assignment does not overflow. */
    heads = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "sectors", "xstrtoll", xerr);
      goto out_sectors;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "sectors");
      goto out_sectors;
    }
    /* The check above should ensure this assignment does not overflow. */
    sectors = r;
  }
  line = argv[i++];
  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_sectors:
 out_heads:
 out_cyls:
 out_partnum:
 out_noargs:
  return ret;
}

int
run_stat (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_stat *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_stat (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_stat (r);
  guestfs_free_stat (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_swapoff_device (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_swapoff_device (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_swapon_device (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_swapon_device (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_swapon_uuid (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *uuid;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  uuid = argv[i++];
  r = guestfs_swapon_uuid (g, uuid);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_tgz_in (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *tarball;
  char *directory;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  tarball = file_in (argv[i++]);
  if (tarball == NULL) goto out_tarball;
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  r = guestfs_tgz_in (g, tarball, directory);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (directory);
 out_directory:
  free_file_in (tarball);
 out_tarball:
 out_noargs:
  return ret;
}

int
run_truncate_size (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  int64_t size;
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
               cmd, "size", "xstrtoll", xerr);
      goto out_size;
    }
    size = r;
  }
  r = guestfs_truncate_size (g, path, size);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_txz_in (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *tarball;
  char *directory;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  tarball = file_in (argv[i++]);
  if (tarball == NULL) goto out_tarball;
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  r = guestfs_txz_in (g, tarball, directory);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (directory);
 out_directory:
  free_file_in (tarball);
 out_tarball:
 out_noargs:
  return ret;
}

int
run_user_cancel (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_user_cancel (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_vgchange_uuid (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *vg;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  vg = argv[i++];
  r = guestfs_vgchange_uuid (g, vg);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_vglvuuids (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  const char *vgname;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  vgname = argv[i++];
  r = guestfs_vglvuuids (g, vgname);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_vgremove (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *vgname;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  vgname = argv[i++];
  r = guestfs_vgremove (g, vgname);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_wc_l (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_wc_l (g, path);
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
run_xfs_growfs (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  struct guestfs_xfs_growfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_growfs_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 9) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "datasec:")) {
      switch (guestfs_int_is_true (&argv[i][8])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][8]);
          goto out;
        case 0:  optargs_s.datasec = 0; break;
        default: optargs_s.datasec = 1;
      }
      this_mask = GUESTFS_XFS_GROWFS_DATASEC_BITMASK;
      this_arg = "datasec";
    }
    else if (STRPREFIX (argv[i], "logsec:")) {
      switch (guestfs_int_is_true (&argv[i][7])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][7]);
          goto out;
        case 0:  optargs_s.logsec = 0; break;
        default: optargs_s.logsec = 1;
      }
      this_mask = GUESTFS_XFS_GROWFS_LOGSEC_BITMASK;
      this_arg = "logsec";
    }
    else if (STRPREFIX (argv[i], "rtsec:")) {
      switch (guestfs_int_is_true (&argv[i][6])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][6]);
          goto out;
        case 0:  optargs_s.rtsec = 0; break;
        default: optargs_s.rtsec = 1;
      }
      this_mask = GUESTFS_XFS_GROWFS_RTSEC_BITMASK;
      this_arg = "rtsec";
    }
    else if (STRPREFIX (argv[i], "datasize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][9], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.datasize", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.datasize = r;
      }
      this_mask = GUESTFS_XFS_GROWFS_DATASIZE_BITMASK;
      this_arg = "datasize";
    }
    else if (STRPREFIX (argv[i], "logsize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][8], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.logsize", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.logsize = r;
      }
      this_mask = GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK;
      this_arg = "logsize";
    }
    else if (STRPREFIX (argv[i], "rtsize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][7], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.rtsize", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.rtsize = r;
      }
      this_mask = GUESTFS_XFS_GROWFS_RTSIZE_BITMASK;
      this_arg = "rtsize";
    }
    else if (STRPREFIX (argv[i], "rtextsize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.rtextsize", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.rtextsize = r;
      }
      this_mask = GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK;
      this_arg = "rtextsize";
    }
    else if (STRPREFIX (argv[i], "maxpct:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][7], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.maxpct", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.maxpct");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.maxpct = r;
      }
      this_mask = GUESTFS_XFS_GROWFS_MAXPCT_BITMASK;
      this_arg = "maxpct";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given more than once\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_xfs_growfs_argv (g, path, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_xfs_info (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_xfsinfo *r;
  char *pathordevice;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  pathordevice = win_prefix (argv[i++]); /* process "win:" prefix */
  if (pathordevice == NULL) goto out_pathordevice;
  r = guestfs_xfs_info (g, pathordevice);
  if (r == NULL) goto out;
  ret = 0;
  print_xfsinfo (r);
  guestfs_free_xfsinfo (r);
 out:
  free (pathordevice);
 out_pathordevice:
 out_noargs:
  return ret;
}

int
run_xfs_repair (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *device;
  struct guestfs_xfs_repair_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_repair_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 11) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = win_prefix (argv[i++]); /* process "win:" prefix */
  if (device == NULL) goto out_device;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "forcelogzero:")) {
      switch (guestfs_int_is_true (&argv[i][13])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][13]);
          goto out;
        case 0:  optargs_s.forcelogzero = 0; break;
        default: optargs_s.forcelogzero = 1;
      }
      this_mask = GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK;
      this_arg = "forcelogzero";
    }
    else if (STRPREFIX (argv[i], "nomodify:")) {
      switch (guestfs_int_is_true (&argv[i][9])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][9]);
          goto out;
        case 0:  optargs_s.nomodify = 0; break;
        default: optargs_s.nomodify = 1;
      }
      this_mask = GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK;
      this_arg = "nomodify";
    }
    else if (STRPREFIX (argv[i], "noprefetch:")) {
      switch (guestfs_int_is_true (&argv[i][11])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][11]);
          goto out;
        case 0:  optargs_s.noprefetch = 0; break;
        default: optargs_s.noprefetch = 1;
      }
      this_mask = GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK;
      this_arg = "noprefetch";
    }
    else if (STRPREFIX (argv[i], "forcegeometry:")) {
      switch (guestfs_int_is_true (&argv[i][14])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][14]);
          goto out;
        case 0:  optargs_s.forcegeometry = 0; break;
        default: optargs_s.forcegeometry = 1;
      }
      this_mask = GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK;
      this_arg = "forcegeometry";
    }
    else if (STRPREFIX (argv[i], "maxmem:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][7], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.maxmem", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.maxmem = r;
      }
      this_mask = GUESTFS_XFS_REPAIR_MAXMEM_BITMASK;
      this_arg = "maxmem";
    }
    else if (STRPREFIX (argv[i], "ihashsize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.ihashsize", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.ihashsize = r;
      }
      this_mask = GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK;
      this_arg = "ihashsize";
    }
    else if (STRPREFIX (argv[i], "bhashsize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.bhashsize", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.bhashsize = r;
      }
      this_mask = GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK;
      this_arg = "bhashsize";
    }
    else if (STRPREFIX (argv[i], "agstride:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][9], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.agstride", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.agstride = r;
      }
      this_mask = GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK;
      this_arg = "agstride";
    }
    else if (STRPREFIX (argv[i], "logdev:")) {
      optargs_s.logdev = &argv[i][7];
      this_mask = GUESTFS_XFS_REPAIR_LOGDEV_BITMASK;
      this_arg = "logdev";
    }
    else if (STRPREFIX (argv[i], "rtdev:")) {
      optargs_s.rtdev = &argv[i][6];
      this_mask = GUESTFS_XFS_REPAIR_RTDEV_BITMASK;
      this_arg = "rtdev";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given more than once\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_xfs_repair_argv (g, device, optargs);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
  free (device);
 out_device:
 out_noargs:
  return ret;
}

int
run_zero_device (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_zero_device (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_zero_free_space (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *directory;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  r = guestfs_zero_free_space (g, directory);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}
