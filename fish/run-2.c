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
print_dirent_list (struct guestfs_dirent_list *dirents)
{
  size_t i;

  for (i = 0; i < dirents->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_dirent_indent (&dirents->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_partition_list (struct guestfs_partition_list *partitions)
{
  size_t i;

  for (i = 0; i < partitions->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_partition_indent (&partitions->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_lvm_pv_list (struct guestfs_lvm_pv_list *lvm_pvs)
{
  size_t i;

  for (i = 0; i < lvm_pvs->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_lvm_pv_indent (&lvm_pvs->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_yara_detection_list (struct guestfs_yara_detection_list *yara_detections)
{
  size_t i;

  for (i = 0; i < yara_detections->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_yara_detection_indent (&yara_detections->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_utsname (struct guestfs_utsname *utsname)
{
  guestfs_int_print_utsname_indent (utsname, stdout, "\n", "");
}

static void
print_statns (struct guestfs_statns *statns)
{
  guestfs_int_print_statns_indent (statns, stdout, "\n", "");
}

int
run_add_drive (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *filename;
  struct guestfs_add_drive_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 13) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  filename = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "readonly:")) {
      switch (guestfs_int_is_true (&argv[i][9])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][9]);
          goto out;
        case 0:  optargs_s.readonly = 0; break;
        default: optargs_s.readonly = 1;
      }
      this_mask = GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
      this_arg = "readonly";
    }
    else if (STRPREFIX (argv[i], "format:")) {
      optargs_s.format = &argv[i][7];
      this_mask = GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
      this_arg = "format";
    }
    else if (STRPREFIX (argv[i], "iface:")) {
      optargs_s.iface = &argv[i][6];
      this_mask = GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
      this_arg = "iface";
    }
    else if (STRPREFIX (argv[i], "name:")) {
      optargs_s.name = &argv[i][5];
      this_mask = GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
      this_arg = "name";
    }
    else if (STRPREFIX (argv[i], "label:")) {
      optargs_s.label = &argv[i][6];
      this_mask = GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK;
      this_arg = "label";
    }
    else if (STRPREFIX (argv[i], "protocol:")) {
      optargs_s.protocol = &argv[i][9];
      this_mask = GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK;
      this_arg = "protocol";
    }
    else if (STRPREFIX (argv[i], "server:")) {
      optargs_s.server = parse_string_list (&argv[i][7]);
      if (optargs_s.server == NULL) goto out;
      this_mask = GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK;
      this_arg = "server";
    }
    else if (STRPREFIX (argv[i], "username:")) {
      optargs_s.username = &argv[i][9];
      this_mask = GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK;
      this_arg = "username";
    }
    else if (STRPREFIX (argv[i], "secret:")) {
      optargs_s.secret = &argv[i][7];
      this_mask = GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK;
      this_arg = "secret";
    }
    else if (STRPREFIX (argv[i], "cachemode:")) {
      optargs_s.cachemode = &argv[i][10];
      this_mask = GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK;
      this_arg = "cachemode";
    }
    else if (STRPREFIX (argv[i], "discard:")) {
      optargs_s.discard = &argv[i][8];
      this_mask = GUESTFS_ADD_DRIVE_OPTS_DISCARD_BITMASK;
      this_arg = "discard";
    }
    else if (STRPREFIX (argv[i], "copyonread:")) {
      switch (guestfs_int_is_true (&argv[i][11])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][11]);
          goto out;
        case 0:  optargs_s.copyonread = 0; break;
        default: optargs_s.copyonread = 1;
      }
      this_mask = GUESTFS_ADD_DRIVE_OPTS_COPYONREAD_BITMASK;
      this_arg = "copyonread";
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

  r = guestfs_add_drive_opts_argv (g, filename, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK) &&
      optargs_s.server != NULL)
    guestfs_int_free_string_list ((char **) optargs_s.server);
 out_noargs:
  return ret;
}

int
run_add_drive_scratch (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int64_t size;
  struct guestfs_add_drive_scratch_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_scratch_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 3) {
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
               cmd, "size", "xstrtoll", xerr);
      goto out_size;
    }
    size = r;
  }

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "name:")) {
      optargs_s.name = &argv[i][5];
      this_mask = GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK;
      this_arg = "name";
    }
    else if (STRPREFIX (argv[i], "label:")) {
      optargs_s.label = &argv[i][6];
      this_mask = GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK;
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

  r = guestfs_add_drive_scratch_argv (g, size, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
 out_noargs:
  return ret;
}

int
run_aug_label (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *augpath;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  augpath = argv[i++];
  r = guestfs_aug_label (g, augpath);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_blkdiscardzeroes (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_blkdiscardzeroes (g, device);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_blockdev_getsize64 (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_blockdev_getsize64 (g, device);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_blockdev_getss (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_blockdev_getss (g, device);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_blockdev_rereadpt (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_blockdev_rereadpt (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_btrfs_balance_cancel (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_btrfs_balance_cancel (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_btrfs_qgroup_limit (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *subvolume;
  int64_t size;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  subvolume = win_prefix (argv[i++]); /* process "win:" prefix */
  if (subvolume == NULL) goto out_subvolume;
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
  r = guestfs_btrfs_qgroup_limit (g, subvolume, size);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
  free (subvolume);
 out_subvolume:
 out_noargs:
  return ret;
}

int
run_btrfs_quota_rescan (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_btrfs_quota_rescan (g, fs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (fs);
 out_fs:
 out_noargs:
  return ret;
}

int
run_btrfs_set_seeding (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_btrfs_set_seeding (g, device, seeding);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_seeding:
 out_noargs:
  return ret;
}

int
run_btrfs_subvolume_show (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  char *subvolume;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  subvolume = win_prefix (argv[i++]); /* process "win:" prefix */
  if (subvolume == NULL) goto out_subvolume;
  r = guestfs_btrfs_subvolume_show (g, subvolume);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  guestfs_int_free_string_list (r);
 out:
  free (subvolume);
 out_subvolume:
 out_noargs:
  return ret;
}

int
run_chown (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int owner;
  int group;
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
               cmd, "owner", "xstrtoll", xerr);
      goto out_owner;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "owner");
      goto out_owner;
    }
    /* The check above should ensure this assignment does not overflow. */
    owner = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "group", "xstrtoll", xerr);
      goto out_group;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "group");
      goto out_group;
    }
    /* The check above should ensure this assignment does not overflow. */
    group = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_chown (g, owner, group, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_group:
 out_owner:
 out_noargs:
  return ret;
}

int
run_command (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  char **arguments;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  arguments = parse_string_list (argv[i++]);
  if (arguments == NULL) goto out_arguments;
  r = guestfs_command (g, arguments);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  guestfs_int_free_string_list (arguments);
 out_arguments:
 out_noargs:
  return ret;
}

int
run_copy_device_to_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *src;
  char *dest;
  struct guestfs_copy_device_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 7) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  src = argv[i++];
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
      this_mask = GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
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
      this_mask = GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
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
      this_mask = GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
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
      this_mask = GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK;
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
      this_mask = GUESTFS_COPY_DEVICE_TO_FILE_APPEND_BITMASK;
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

  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (dest);
 out_dest:
 out_noargs:
  return ret;
}

int
run_cp_r (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_cp_r (g, src, dest);
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
run_debug (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *subcmd;
  char **extraargs;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  subcmd = argv[i++];
  extraargs = parse_string_list (argv[i++]);
  if (extraargs == NULL) goto out_extraargs;
  r = guestfs_debug (g, subcmd, extraargs);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  guestfs_int_free_string_list (extraargs);
 out_extraargs:
 out_noargs:
  return ret;
}

int
run_drop_caches (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int whattodrop;
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
               cmd, "whattodrop", "xstrtoll", xerr);
      goto out_whattodrop;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "whattodrop");
      goto out_whattodrop;
    }
    /* The check above should ensure this assignment does not overflow. */
    whattodrop = r;
  }
  r = guestfs_drop_caches (g, whattodrop);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_whattodrop:
 out_noargs:
  return ret;
}

int
run_egrep (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_egrep (g, regex, path);
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
run_file_architecture (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  char *filename;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  filename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (filename == NULL) goto out_filename;
  r = guestfs_file_architecture (g, filename);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (filename);
 out_filename:
 out_noargs:
  return ret;
}

int
run_get_backend (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_backend (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_get_e2attrs (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  char *file;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  file = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file == NULL) goto out_file;
  r = guestfs_get_e2attrs (g, file);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (file);
 out_file:
 out_noargs:
  return ret;
}

int
run_get_e2generation (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_get_e2generation (g, file);
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
run_glob_expand (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  char *pattern;
  struct guestfs_glob_expand_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_glob_expand_opts_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  pattern = win_prefix (argv[i++]); /* process "win:" prefix */
  if (pattern == NULL) goto out_pattern;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "directoryslash:")) {
      switch (guestfs_int_is_true (&argv[i][15])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][15]);
          goto out;
        case 0:  optargs_s.directoryslash = 0; break;
        default: optargs_s.directoryslash = 1;
      }
      this_mask = GUESTFS_GLOB_EXPAND_OPTS_DIRECTORYSLASH_BITMASK;
      this_arg = "directoryslash";
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

  r = guestfs_glob_expand_opts_argv (g, pattern, optargs);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
  free (pattern);
 out_pattern:
 out_noargs:
  return ret;
}

int
run_grub_install (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *root;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  root = win_prefix (argv[i++]); /* process "win:" prefix */
  if (root == NULL) goto out_root;
  device = argv[i++];
  r = guestfs_grub_install (g, root, device);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (root);
 out_root:
 out_noargs:
  return ret;
}

int
run_hivex_node_add_child (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;
  int64_t parent;
  const char *name;
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
               cmd, "parent", "xstrtoll", xerr);
      goto out_parent;
    }
    parent = r;
  }
  name = argv[i++];
  r = guestfs_hivex_node_add_child (g, parent, name);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_parent:
 out_noargs:
  return ret;
}

int
run_hivex_node_get_value (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;
  int64_t nodeh;
  const char *key;
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
               cmd, "nodeh", "xstrtoll", xerr);
      goto out_nodeh;
    }
    nodeh = r;
  }
  key = argv[i++];
  r = guestfs_hivex_node_get_value (g, nodeh, key);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_nodeh:
 out_noargs:
  return ret;
}

int
run_inspect_get_arch (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_inspect_get_arch (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_inspect_get_drive_mappings (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_inspect_get_drive_mappings (g, root);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_inspect_get_windows_current_control_set (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_inspect_get_windows_current_control_set (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_inspect_get_windows_systemroot (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_inspect_get_windows_systemroot (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_is_chardev (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  struct guestfs_is_chardev_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_chardev_opts_argv *optargs = &optargs_s;
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
      this_mask = GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
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

  r = guestfs_is_chardev_opts_argv (g, path, optargs);
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
run_is_lv (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *mountable;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  mountable = argv[i++];
  r = guestfs_is_lv (g, mountable);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_is_socket (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  struct guestfs_is_socket_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_socket_opts_argv *optargs = &optargs_s;
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
      this_mask = GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS_BITMASK;
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

  r = guestfs_is_socket_opts_argv (g, path, optargs);
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
run_journal_open (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_journal_open (g, directory);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}

int
run_kill_subprocess (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_kill_subprocess (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_ldmtool_scan_devices (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  char **devices;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  devices = parse_string_list (argv[i++]);
  if (devices == NULL) goto out_devices;
  r = guestfs_ldmtool_scan_devices (g, devices);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
  guestfs_int_free_string_list (devices);
 out_devices:
 out_noargs:
  return ret;
}

int
run_lsetxattr (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *xattr;
  const char *val;
  int vallen;
  char *path;
  size_t i = 0;

  if (argc != 4) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  xattr = argv[i++];
  val = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "vallen", "xstrtoll", xerr);
      goto out_vallen;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "vallen");
      goto out_vallen;
    }
    /* The check above should ensure this assignment does not overflow. */
    vallen = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_lsetxattr (g, xattr, val, vallen, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_vallen:
 out_noargs:
  return ret;
}

int
run_luks_kill_slot (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  char *key;
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
  r = guestfs_luks_kill_slot (g, device, key, keyslot);
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
run_lvm_scan (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int activate;
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
      goto out_activate;
    case 0:  activate = 0; break;
    default: activate = 1;
  }
  r = guestfs_lvm_scan (g, activate);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_activate:
 out_noargs:
  return ret;
}

int
run_mkdir (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_mkdir (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_mkfifo (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int mode;
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
               cmd, "mode", "xstrtoll", xerr);
      goto out_mode;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mode");
      goto out_mode;
    }
    /* The check above should ensure this assignment does not overflow. */
    mode = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_mkfifo (g, mode, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_mode:
 out_noargs:
  return ret;
}

int
run_mksquashfs (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  char *filename;
  struct guestfs_mksquashfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mksquashfs_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 4) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  filename = file_out (argv[i++]);
  if (filename == NULL) goto out_filename;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "compress:")) {
      optargs_s.compress = &argv[i][9];
      this_mask = GUESTFS_MKSQUASHFS_COMPRESS_BITMASK;
      this_arg = "compress";
    }
    else if (STRPREFIX (argv[i], "excludes:")) {
      optargs_s.excludes = parse_string_list (&argv[i][9]);
      if (optargs_s.excludes == NULL) goto out;
      this_mask = GUESTFS_MKSQUASHFS_EXCLUDES_BITMASK;
      this_arg = "excludes";
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

  r = guestfs_mksquashfs_argv (g, path, filename, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  if ((optargs_s.bitmask & GUESTFS_MKSQUASHFS_EXCLUDES_BITMASK) &&
      optargs_s.excludes != NULL)
    guestfs_int_free_string_list ((char **) optargs_s.excludes);
  free (filename);
 out_filename:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_modprobe (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *modulename;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  modulename = argv[i++];
  r = guestfs_modprobe (g, modulename);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_ntfscat_i (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int64_t inode;
  char *filename;
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
               cmd, "inode", "xstrtoll", xerr);
      goto out_inode;
    }
    inode = r;
  }
  filename = file_out (argv[i++]);
  if (filename == NULL) goto out_filename;
  r = guestfs_ntfscat_i (g, device, inode, filename);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (filename);
 out_filename:
 out_inode:
 out_noargs:
  return ret;
}

int
run_parse_environment (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_parse_environment (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_part_get_disk_guid (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_part_get_disk_guid (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_part_list (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_partition_list *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_part_list (g, device);
  if (r == NULL) goto out;
  ret = 0;
  print_partition_list (r);
  guestfs_free_partition_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_part_set_bootable (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int partnum;
  int bootable;
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
  switch (guestfs_int_is_true (argv[i++])) {
    case -1:
      fprintf (stderr,
               _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
               getprogname (), argv[i-1]);
      goto out_bootable;
    case 0:  bootable = 0; break;
    default: bootable = 1;
  }
  r = guestfs_part_set_bootable (g, device, partnum, bootable);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_bootable:
 out_partnum:
 out_noargs:
  return ret;
}

int
run_part_set_gpt_attributes (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int partnum;
  int64_t attributes;
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
               cmd, "attributes", "xstrtoll", xerr);
      goto out_attributes;
    }
    attributes = r;
  }
  r = guestfs_part_set_gpt_attributes (g, device, partnum, attributes);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_attributes:
 out_partnum:
 out_noargs:
  return ret;
}

int
run_part_set_gpt_guid (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_part_set_gpt_guid (g, device, partnum, guid);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_partnum:
 out_noargs:
  return ret;
}

int
run_part_to_dev (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *partition;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  partition = argv[i++];
  r = guestfs_part_to_dev (g, partition);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_pvresize (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_pvresize (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_pvs_full (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_lvm_pv_list *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_pvs_full (g);
  if (r == NULL) goto out;
  ret = 0;
  print_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_pwrite_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  const char *content;
  size_t content_size;
  int64_t offset;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  content = argv[i];
  content_size = strlen (argv[i]);
  i++;
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
  r = guestfs_pwrite_device (g, device, content, content_size, offset);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_offset:
 out_noargs:
  return ret;
}

int
run_readdir (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_dirent_list *r;
  char *dir;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  dir = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dir == NULL) goto out_dir;
  r = guestfs_readdir (g, dir);
  if (r == NULL) goto out;
  ret = 0;
  print_dirent_list (r);
  guestfs_free_dirent_list (r);
 out:
  free (dir);
 out_dir:
 out_noargs:
  return ret;
}

int
run_readlink (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_readlink (g, path);
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
run_resize2fs (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_resize2fs (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_rsync_in (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *remote;
  char *dest;
  struct guestfs_rsync_in_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_in_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 4) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  remote = argv[i++];
  dest = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dest == NULL) goto out_dest;

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
      this_mask = GUESTFS_RSYNC_IN_ARCHIVE_BITMASK;
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
      this_mask = GUESTFS_RSYNC_IN_DELETEDEST_BITMASK;
      this_arg = "deletedest";
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

  r = guestfs_rsync_in_argv (g, remote, dest, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (dest);
 out_dest:
 out_noargs:
  return ret;
}

int
run_set_e2uuid (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  const char *uuid;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  uuid = argv[i++];
  r = guestfs_set_e2uuid (g, device, uuid);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_set_libvirt_requested_credential (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int index;
  const char *cred;
  size_t cred_size;
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
               cmd, "index", "xstrtoll", xerr);
      goto out_index;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "index");
      goto out_index;
    }
    /* The check above should ensure this assignment does not overflow. */
    index = r;
  }
  cred = argv[i];
  cred_size = strlen (argv[i]);
  i++;
  r = guestfs_set_libvirt_requested_credential (g, index, cred, cred_size);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_index:
 out_noargs:
  return ret;
}

int
run_set_libvirt_supported_credentials (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char **creds;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  creds = parse_string_list (argv[i++]);
  if (creds == NULL) goto out_creds;
  r = guestfs_set_libvirt_supported_credentials (g, creds);
  if (r == -1) goto out;
  ret = 0;
 out:
  guestfs_int_free_string_list (creds);
 out_creds:
 out_noargs:
  return ret;
}

int
run_set_path (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *searchpath;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  searchpath = STRNEQ (argv[i], "") ? argv[i] : NULL;
  i++;
  r = guestfs_set_path (g, searchpath);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_set_pgroup (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int pgroup;
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
      goto out_pgroup;
    case 0:  pgroup = 0; break;
    default: pgroup = 1;
  }
  r = guestfs_set_pgroup (g, pgroup);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_pgroup:
 out_noargs:
  return ret;
}

int
run_sfdisk_disk_geometry (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_sfdisk_disk_geometry (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_sh (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *command;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  command = argv[i++];
  r = guestfs_sh (g, command);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_statns (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_statns *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_statns (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_statns (r);
  guestfs_free_statns (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_swapon_label (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *label;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  label = argv[i++];
  r = guestfs_swapon_label (g, label);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_txz_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *directory;
  char *tarball;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  tarball = file_out (argv[i++]);
  if (tarball == NULL) goto out_tarball;
  r = guestfs_txz_out (g, directory, tarball);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (tarball);
 out_tarball:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}

int
run_umount_all (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_umount_all (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_upload_offset (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *filename;
  char *remotefilename;
  int64_t offset;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  filename = file_in (argv[i++]);
  if (filename == NULL) goto out_filename;
  remotefilename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (remotefilename == NULL) goto out_remotefilename;
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
  r = guestfs_upload_offset (g, filename, remotefilename, offset);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_offset:
  free (remotefilename);
 out_remotefilename:
  free_file_in (filename);
 out_filename:
 out_noargs:
  return ret;
}

int
run_utsname (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_utsname *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_utsname (g);
  if (r == NULL) goto out;
  ret = 0;
  print_utsname (r);
  guestfs_free_utsname (r);
 out:
 out_noargs:
  return ret;
}

int
run_vgpvuuids (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_vgpvuuids (g, vgname);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_write_append (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  const char *content;
  size_t content_size;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  content = argv[i];
  content_size = strlen (argv[i]);
  i++;
  r = guestfs_write_append (g, path, content, content_size);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_yara_scan (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_yara_detection_list *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_yara_scan (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_yara_detection_list (r);
  guestfs_free_yara_detection_list (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_zgrep (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_zgrep (g, regex, path);
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
