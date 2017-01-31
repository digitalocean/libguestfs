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
print_xattr_list (struct guestfs_xattr_list *xattrs)
{
  size_t i;

  for (i = 0; i < xattrs->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_xattr_indent (&xattrs->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_btrfssubvolume_list (struct guestfs_btrfssubvolume_list *btrfssubvolumes)
{
  size_t i;

  for (i = 0; i < btrfssubvolumes->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_btrfssubvolume_indent (&btrfssubvolumes->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_version (struct guestfs_version *version)
{
  guestfs_int_print_version_indent (version, stdout, "\n", "");
}

static void
print_int_bool (struct guestfs_int_bool *int_bool)
{
  guestfs_int_print_int_bool_indent (int_bool, stdout, "\n", "");
}

static void
print_statns (struct guestfs_statns *statns)
{
  guestfs_int_print_statns_indent (statns, stdout, "\n", "");
}

static void
print_btrfsbalance (struct guestfs_btrfsbalance *btrfsbalance)
{
  guestfs_int_print_btrfsbalance_indent (btrfsbalance, stdout, "\n", "");
}

static void
print_statvfs (struct guestfs_statvfs *statvfs)
{
  guestfs_int_print_statvfs_indent (statvfs, stdout, "\n", "");
}

int
run_acl_get_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  char *path;
  const char *acltype;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  acltype = argv[i++];
  r = guestfs_acl_get_file (g, path, acltype);
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
run_aug_close (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_aug_close (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_aug_defnode (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_int_bool *r;
  const char *name;
  const char *expr;
  const char *val;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  name = argv[i++];
  expr = argv[i++];
  val = argv[i++];
  r = guestfs_aug_defnode (g, name, expr, val);
  if (r == NULL) goto out;
  ret = 0;
  print_int_bool (r);
  guestfs_free_int_bool (r);
 out:
 out_noargs:
  return ret;
}

int
run_aug_get (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_aug_get (g, augpath);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_aug_save (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_aug_save (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_aug_setm (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *base;
  const char *sub;
  const char *val;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  base = argv[i++];
  sub = STRNEQ (argv[i], "") ? argv[i] : NULL;
  i++;
  val = argv[i++];
  r = guestfs_aug_setm (g, base, sub, val);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_available (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_available (g, groups);
  if (r == -1) goto out;
  ret = 0;
 out:
  guestfs_int_free_string_list (groups);
 out_groups:
 out_noargs:
  return ret;
}

int
run_blkdiscard (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_blkdiscard (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_blockdev_getsz (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_blockdev_getsz (g, device);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_blockdev_setro (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_blockdev_setro (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_btrfs_balance_status (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_btrfsbalance *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_btrfs_balance_status (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_btrfsbalance (r);
  guestfs_free_btrfsbalance (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_btrfs_device_delete (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_btrfs_device_delete (g, devices, fs);
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
run_btrfs_filesystem_defragment (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  struct guestfs_btrfs_filesystem_defragment_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_defragment_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "flush:")) {
      switch (guestfs_int_is_true (&argv[i][6])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][6]);
          goto out;
        case 0:  optargs_s.flush = 0; break;
        default: optargs_s.flush = 1;
      }
      this_mask = GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH_BITMASK;
      this_arg = "flush";
    }
    else if (STRPREFIX (argv[i], "compress:")) {
      optargs_s.compress = &argv[i][9];
      this_mask = GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS_BITMASK;
      this_arg = "compress";
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

  r = guestfs_btrfs_filesystem_defragment_argv (g, path, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_btrfs_filesystem_resize (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *mountpoint;
  struct guestfs_btrfs_filesystem_resize_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;
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

    if (STRPREFIX (argv[i], "size:")) {
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
      this_mask = GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
      this_arg = "size";
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

  r = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (mountpoint);
 out_mountpoint:
 out_noargs:
  return ret;
}

int
run_btrfs_filesystem_sync (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_btrfs_filesystem_sync (g, fs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (fs);
 out_fs:
 out_noargs:
  return ret;
}

int
run_btrfs_image (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char **source;
  char *image;
  struct guestfs_btrfs_image_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_image_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  source = parse_string_list (argv[i++]);
  if (source == NULL) goto out_source;
  image = win_prefix (argv[i++]); /* process "win:" prefix */
  if (image == NULL) goto out_image;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "compresslevel:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][14], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.compresslevel", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.compresslevel");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.compresslevel = r;
      }
      this_mask = GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL_BITMASK;
      this_arg = "compresslevel";
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

  r = guestfs_btrfs_image_argv (g, source, image, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (image);
 out_image:
  guestfs_int_free_string_list (source);
 out_source:
 out_noargs:
  return ret;
}

int
run_btrfs_qgroup_destroy (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *qgroupid;
  char *subvolume;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  qgroupid = argv[i++];
  subvolume = win_prefix (argv[i++]); /* process "win:" prefix */
  if (subvolume == NULL) goto out_subvolume;
  r = guestfs_btrfs_qgroup_destroy (g, qgroupid, subvolume);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (subvolume);
 out_subvolume:
 out_noargs:
  return ret;
}

int
run_btrfs_subvolume_delete (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *subvolume;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  subvolume = win_prefix (argv[i++]); /* process "win:" prefix */
  if (subvolume == NULL) goto out_subvolume;
  r = guestfs_btrfs_subvolume_delete (g, subvolume);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (subvolume);
 out_subvolume:
 out_noargs:
  return ret;
}

int
run_btrfs_subvolume_list (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_btrfssubvolume_list *r;
  char *fs;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  fs = win_prefix (argv[i++]); /* process "win:" prefix */
  if (fs == NULL) goto out_fs;
  r = guestfs_btrfs_subvolume_list (g, fs);
  if (r == NULL) goto out;
  ret = 0;
  print_btrfssubvolume_list (r);
  guestfs_free_btrfssubvolume_list (r);
 out:
  free (fs);
 out_fs:
 out_noargs:
  return ret;
}

int
run_btrfstune_enable_skinny_metadata_extent_refs (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_btrfstune_enable_skinny_metadata_extent_refs (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_cap_get_file (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_cap_get_file (g, path);
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
run_checksum (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *csumtype;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  csumtype = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_checksum (g, csumtype, path);
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
run_chmod (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_chmod (g, mode, path);
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
run_disk_create (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *filename;
  const char *format;
  int64_t size;
  struct guestfs_disk_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_disk_create_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 3 || argc > 8) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  filename = argv[i++];
  format = argv[i++];
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

    if (STRPREFIX (argv[i], "backingfile:")) {
      optargs_s.backingfile = &argv[i][12];
      this_mask = GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK;
      this_arg = "backingfile";
    }
    else if (STRPREFIX (argv[i], "backingformat:")) {
      optargs_s.backingformat = &argv[i][14];
      this_mask = GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK;
      this_arg = "backingformat";
    }
    else if (STRPREFIX (argv[i], "preallocation:")) {
      optargs_s.preallocation = &argv[i][14];
      this_mask = GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK;
      this_arg = "preallocation";
    }
    else if (STRPREFIX (argv[i], "compat:")) {
      optargs_s.compat = &argv[i][7];
      this_mask = GUESTFS_DISK_CREATE_COMPAT_BITMASK;
      this_arg = "compat";
    }
    else if (STRPREFIX (argv[i], "clustersize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][12], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.clustersize", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.clustersize");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.clustersize = r;
      }
      this_mask = GUESTFS_DISK_CREATE_CLUSTERSIZE_BITMASK;
      this_arg = "clustersize";
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

  r = guestfs_disk_create_argv (g, filename, format, size, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
 out_noargs:
  return ret;
}

int
run_dmesg (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_dmesg (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_download_blocks (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  int64_t start;
  int64_t stop;
  char *filename;
  struct guestfs_download_blocks_argv optargs_s = { .bitmask = 0 };
  struct guestfs_download_blocks_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 4 || argc > 5) {
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
               cmd, "start", "xstrtoll", xerr);
      goto out_start;
    }
    start = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "stop", "xstrtoll", xerr);
      goto out_stop;
    }
    stop = r;
  }
  filename = file_out (argv[i++]);
  if (filename == NULL) goto out_filename;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "unallocated:")) {
      switch (guestfs_int_is_true (&argv[i][12])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][12]);
          goto out;
        case 0:  optargs_s.unallocated = 0; break;
        default: optargs_s.unallocated = 1;
      }
      this_mask = GUESTFS_DOWNLOAD_BLOCKS_UNALLOCATED_BITMASK;
      this_arg = "unallocated";
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

  r = guestfs_download_blocks_argv (g, device, start, stop, filename, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (filename);
 out_filename:
 out_stop:
 out_start:
 out_noargs:
  return ret;
}

int
run_du (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_du (g, path);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_e2fsck_f (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_e2fsck_f (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_echo_daemon (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  char **words;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  words = parse_string_list (argv[i++]);
  if (words == NULL) goto out_words;
  r = guestfs_echo_daemon (g, words);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  guestfs_int_free_string_list (words);
 out_words:
 out_noargs:
  return ret;
}

int
run_equal (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *file1;
  char *file2;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  file1 = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file1 == NULL) goto out_file1;
  file2 = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file2 == NULL) goto out_file2;
  r = guestfs_equal (g, file1, file2);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  free (file2);
 out_file2:
  free (file1);
 out_file1:
 out_noargs:
  return ret;
}

int
run_fgrepi (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_fgrepi (g, pattern, path);
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
run_get_backend_setting (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *name;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  name = argv[i++];
  r = guestfs_get_backend_setting (g, name);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_get_backend_settings (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_backend_settings (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_get_e2label (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_get_e2label (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_get_recovery_proc (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_recovery_proc (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_get_tmpdir (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_tmpdir (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_getcon (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_getcon (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_getxattr (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_getxattr (g, path, name, &size);
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
run_hivex_close (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_hivex_close (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_hivex_open (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *filename;
  struct guestfs_hivex_open_argv optargs_s = { .bitmask = 0 };
  struct guestfs_hivex_open_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 4) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  filename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (filename == NULL) goto out_filename;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "verbose:")) {
      switch (guestfs_int_is_true (&argv[i][8])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][8]);
          goto out;
        case 0:  optargs_s.verbose = 0; break;
        default: optargs_s.verbose = 1;
      }
      this_mask = GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK;
      this_arg = "verbose";
    }
    else if (STRPREFIX (argv[i], "debug:")) {
      switch (guestfs_int_is_true (&argv[i][6])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][6]);
          goto out;
        case 0:  optargs_s.debug = 0; break;
        default: optargs_s.debug = 1;
      }
      this_mask = GUESTFS_HIVEX_OPEN_DEBUG_BITMASK;
      this_arg = "debug";
    }
    else if (STRPREFIX (argv[i], "write:")) {
      switch (guestfs_int_is_true (&argv[i][6])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][6]);
          goto out;
        case 0:  optargs_s.write = 0; break;
        default: optargs_s.write = 1;
      }
      this_mask = GUESTFS_HIVEX_OPEN_WRITE_BITMASK;
      this_arg = "write";
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

  r = guestfs_hivex_open_argv (g, filename, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (filename);
 out_filename:
 out_noargs:
  return ret;
}

int
run_hivex_value_utf8 (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  int64_t valueh;
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
               cmd, "valueh", "xstrtoll", xerr);
      goto out_valueh;
    }
    valueh = r;
  }
  r = guestfs_hivex_value_utf8 (g, valueh);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_valueh:
 out_noargs:
  return ret;
}

int
run_inotify_add_watch (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;
  char *path;
  int mask;
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
               cmd, "mask", "xstrtoll", xerr);
      goto out_mask;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mask");
      goto out_mask;
    }
    /* The check above should ensure this assignment does not overflow. */
    mask = r;
  }
  r = guestfs_inotify_add_watch (g, path, mask);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_mask:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_inotify_init (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int maxevents;
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
               cmd, "maxevents", "xstrtoll", xerr);
      goto out_maxevents;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "maxevents");
      goto out_maxevents;
    }
    /* The check above should ensure this assignment does not overflow. */
    maxevents = r;
  }
  r = guestfs_inotify_init (g, maxevents);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_maxevents:
 out_noargs:
  return ret;
}

int
run_inspect_get_type (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_inspect_get_type (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_inspect_is_live (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_inspect_is_live (g, root);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_internal_exit (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_internal_exit (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_is_dir (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  struct guestfs_is_dir_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_dir_opts_argv *optargs = &optargs_s;
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
      this_mask = GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS_BITMASK;
      this_arg = "followsymlinks";
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

  r = guestfs_is_dir_opts_argv (g, path, optargs);
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
run_is_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  struct guestfs_is_file_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_file_opts_argv *optargs = &optargs_s;
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
      this_mask = GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS_BITMASK;
      this_arg = "followsymlinks";
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

  r = guestfs_is_file_opts_argv (g, path, optargs);
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
run_is_whole_device (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_is_whole_device (g, device);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_is_zero_device (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_is_zero_device (g, device);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_journal_get_realtime_usec (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_journal_get_realtime_usec (g);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_journal_set_data_threshold (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int64_t threshold;
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
               cmd, "threshold", "xstrtoll", xerr);
      goto out_threshold;
    }
    threshold = r;
  }
  r = guestfs_journal_set_data_threshold (g, threshold);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_threshold:
 out_noargs:
  return ret;
}

int
run_launch (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_launch (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_ldmtool_remove_all (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_ldmtool_remove_all (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_ldmtool_volume_hint (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *diskgroup;
  const char *volume;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  diskgroup = argv[i++];
  volume = argv[i++];
  r = guestfs_ldmtool_volume_hint (g, diskgroup, volume);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_ldmtool_volume_type (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *diskgroup;
  const char *volume;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  diskgroup = argv[i++];
  volume = argv[i++];
  r = guestfs_ldmtool_volume_type (g, diskgroup, volume);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_list_devices (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_list_devices (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_list_filesystems (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_list_filesystems (g);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_ls (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_ls (g, directory);
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
run_ls0 (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *dir;
  char *filenames;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  dir = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dir == NULL) goto out_dir;
  filenames = file_out (argv[i++]);
  if (filenames == NULL) goto out_filenames;
  r = guestfs_ls0 (g, dir, filenames);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (filenames);
 out_filenames:
  free (dir);
 out_dir:
 out_noargs:
  return ret;
}

int
run_lstatns (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_lstatns (g, path);
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
run_lxattrlist (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_xattr_list *r;
  char *path;
  char **names;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  names = parse_string_list (argv[i++]);
  if (names == NULL) goto out_names;
  r = guestfs_lxattrlist (g, path, names);
  if (r == NULL) goto out;
  ret = 0;
  print_xattr_list (r);
  guestfs_free_xattr_list (r);
 out:
  guestfs_int_free_string_list (names);
 out_names:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_mkdir_mode (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  int mode;
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
  r = guestfs_mkdir_mode (g, path, mode);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_mode:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_mkdir_p (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_mkdir_p (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_mke2fs (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  struct guestfs_mke2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mke2fs_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 39) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "blockscount:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][12], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.blockscount", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.blockscount = r;
      }
      this_mask = GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK;
      this_arg = "blockscount";
    }
    else if (STRPREFIX (argv[i], "blocksize:")) {
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
        optargs_s.blocksize = r;
      }
      this_mask = GUESTFS_MKE2FS_BLOCKSIZE_BITMASK;
      this_arg = "blocksize";
    }
    else if (STRPREFIX (argv[i], "fragsize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][9], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.fragsize", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.fragsize = r;
      }
      this_mask = GUESTFS_MKE2FS_FRAGSIZE_BITMASK;
      this_arg = "fragsize";
    }
    else if (STRPREFIX (argv[i], "blockspergroup:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][15], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.blockspergroup", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.blockspergroup = r;
      }
      this_mask = GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK;
      this_arg = "blockspergroup";
    }
    else if (STRPREFIX (argv[i], "numberofgroups:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][15], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.numberofgroups", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.numberofgroups = r;
      }
      this_mask = GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK;
      this_arg = "numberofgroups";
    }
    else if (STRPREFIX (argv[i], "bytesperinode:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][14], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.bytesperinode", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.bytesperinode = r;
      }
      this_mask = GUESTFS_MKE2FS_BYTESPERINODE_BITMASK;
      this_arg = "bytesperinode";
    }
    else if (STRPREFIX (argv[i], "inodesize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.inodesize", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.inodesize = r;
      }
      this_mask = GUESTFS_MKE2FS_INODESIZE_BITMASK;
      this_arg = "inodesize";
    }
    else if (STRPREFIX (argv[i], "journalsize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][12], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.journalsize", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.journalsize = r;
      }
      this_mask = GUESTFS_MKE2FS_JOURNALSIZE_BITMASK;
      this_arg = "journalsize";
    }
    else if (STRPREFIX (argv[i], "numberofinodes:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][15], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.numberofinodes", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.numberofinodes = r;
      }
      this_mask = GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK;
      this_arg = "numberofinodes";
    }
    else if (STRPREFIX (argv[i], "stridesize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][11], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.stridesize", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.stridesize = r;
      }
      this_mask = GUESTFS_MKE2FS_STRIDESIZE_BITMASK;
      this_arg = "stridesize";
    }
    else if (STRPREFIX (argv[i], "stripewidth:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][12], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.stripewidth", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.stripewidth = r;
      }
      this_mask = GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK;
      this_arg = "stripewidth";
    }
    else if (STRPREFIX (argv[i], "maxonlineresize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][16], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.maxonlineresize", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.maxonlineresize = r;
      }
      this_mask = GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK;
      this_arg = "maxonlineresize";
    }
    else if (STRPREFIX (argv[i], "reservedblockspercentage:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][25], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.reservedblockspercentage", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.reservedblockspercentage");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.reservedblockspercentage = r;
      }
      this_mask = GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
      this_arg = "reservedblockspercentage";
    }
    else if (STRPREFIX (argv[i], "mmpupdateinterval:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][18], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.mmpupdateinterval", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.mmpupdateinterval");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.mmpupdateinterval = r;
      }
      this_mask = GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK;
      this_arg = "mmpupdateinterval";
    }
    else if (STRPREFIX (argv[i], "journaldevice:")) {
      optargs_s.journaldevice = &argv[i][14];
      this_mask = GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK;
      this_arg = "journaldevice";
    }
    else if (STRPREFIX (argv[i], "label:")) {
      optargs_s.label = &argv[i][6];
      this_mask = GUESTFS_MKE2FS_LABEL_BITMASK;
      this_arg = "label";
    }
    else if (STRPREFIX (argv[i], "lastmounteddir:")) {
      optargs_s.lastmounteddir = &argv[i][15];
      this_mask = GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK;
      this_arg = "lastmounteddir";
    }
    else if (STRPREFIX (argv[i], "creatoros:")) {
      optargs_s.creatoros = &argv[i][10];
      this_mask = GUESTFS_MKE2FS_CREATOROS_BITMASK;
      this_arg = "creatoros";
    }
    else if (STRPREFIX (argv[i], "fstype:")) {
      optargs_s.fstype = &argv[i][7];
      this_mask = GUESTFS_MKE2FS_FSTYPE_BITMASK;
      this_arg = "fstype";
    }
    else if (STRPREFIX (argv[i], "usagetype:")) {
      optargs_s.usagetype = &argv[i][10];
      this_mask = GUESTFS_MKE2FS_USAGETYPE_BITMASK;
      this_arg = "usagetype";
    }
    else if (STRPREFIX (argv[i], "uuid:")) {
      optargs_s.uuid = &argv[i][5];
      this_mask = GUESTFS_MKE2FS_UUID_BITMASK;
      this_arg = "uuid";
    }
    else if (STRPREFIX (argv[i], "forcecreate:")) {
      switch (guestfs_int_is_true (&argv[i][12])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][12]);
          goto out;
        case 0:  optargs_s.forcecreate = 0; break;
        default: optargs_s.forcecreate = 1;
      }
      this_mask = GUESTFS_MKE2FS_FORCECREATE_BITMASK;
      this_arg = "forcecreate";
    }
    else if (STRPREFIX (argv[i], "writesbandgrouponly:")) {
      switch (guestfs_int_is_true (&argv[i][20])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][20]);
          goto out;
        case 0:  optargs_s.writesbandgrouponly = 0; break;
        default: optargs_s.writesbandgrouponly = 1;
      }
      this_mask = GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK;
      this_arg = "writesbandgrouponly";
    }
    else if (STRPREFIX (argv[i], "lazyitableinit:")) {
      switch (guestfs_int_is_true (&argv[i][15])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][15]);
          goto out;
        case 0:  optargs_s.lazyitableinit = 0; break;
        default: optargs_s.lazyitableinit = 1;
      }
      this_mask = GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK;
      this_arg = "lazyitableinit";
    }
    else if (STRPREFIX (argv[i], "lazyjournalinit:")) {
      switch (guestfs_int_is_true (&argv[i][16])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][16]);
          goto out;
        case 0:  optargs_s.lazyjournalinit = 0; break;
        default: optargs_s.lazyjournalinit = 1;
      }
      this_mask = GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK;
      this_arg = "lazyjournalinit";
    }
    else if (STRPREFIX (argv[i], "testfs:")) {
      switch (guestfs_int_is_true (&argv[i][7])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][7]);
          goto out;
        case 0:  optargs_s.testfs = 0; break;
        default: optargs_s.testfs = 1;
      }
      this_mask = GUESTFS_MKE2FS_TESTFS_BITMASK;
      this_arg = "testfs";
    }
    else if (STRPREFIX (argv[i], "discard:")) {
      switch (guestfs_int_is_true (&argv[i][8])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][8]);
          goto out;
        case 0:  optargs_s.discard = 0; break;
        default: optargs_s.discard = 1;
      }
      this_mask = GUESTFS_MKE2FS_DISCARD_BITMASK;
      this_arg = "discard";
    }
    else if (STRPREFIX (argv[i], "quotatype:")) {
      switch (guestfs_int_is_true (&argv[i][10])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][10]);
          goto out;
        case 0:  optargs_s.quotatype = 0; break;
        default: optargs_s.quotatype = 1;
      }
      this_mask = GUESTFS_MKE2FS_QUOTATYPE_BITMASK;
      this_arg = "quotatype";
    }
    else if (STRPREFIX (argv[i], "extent:")) {
      switch (guestfs_int_is_true (&argv[i][7])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][7]);
          goto out;
        case 0:  optargs_s.extent = 0; break;
        default: optargs_s.extent = 1;
      }
      this_mask = GUESTFS_MKE2FS_EXTENT_BITMASK;
      this_arg = "extent";
    }
    else if (STRPREFIX (argv[i], "filetype:")) {
      switch (guestfs_int_is_true (&argv[i][9])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][9]);
          goto out;
        case 0:  optargs_s.filetype = 0; break;
        default: optargs_s.filetype = 1;
      }
      this_mask = GUESTFS_MKE2FS_FILETYPE_BITMASK;
      this_arg = "filetype";
    }
    else if (STRPREFIX (argv[i], "flexbg:")) {
      switch (guestfs_int_is_true (&argv[i][7])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][7]);
          goto out;
        case 0:  optargs_s.flexbg = 0; break;
        default: optargs_s.flexbg = 1;
      }
      this_mask = GUESTFS_MKE2FS_FLEXBG_BITMASK;
      this_arg = "flexbg";
    }
    else if (STRPREFIX (argv[i], "hasjournal:")) {
      switch (guestfs_int_is_true (&argv[i][11])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][11]);
          goto out;
        case 0:  optargs_s.hasjournal = 0; break;
        default: optargs_s.hasjournal = 1;
      }
      this_mask = GUESTFS_MKE2FS_HASJOURNAL_BITMASK;
      this_arg = "hasjournal";
    }
    else if (STRPREFIX (argv[i], "journaldev:")) {
      switch (guestfs_int_is_true (&argv[i][11])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][11]);
          goto out;
        case 0:  optargs_s.journaldev = 0; break;
        default: optargs_s.journaldev = 1;
      }
      this_mask = GUESTFS_MKE2FS_JOURNALDEV_BITMASK;
      this_arg = "journaldev";
    }
    else if (STRPREFIX (argv[i], "largefile:")) {
      switch (guestfs_int_is_true (&argv[i][10])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][10]);
          goto out;
        case 0:  optargs_s.largefile = 0; break;
        default: optargs_s.largefile = 1;
      }
      this_mask = GUESTFS_MKE2FS_LARGEFILE_BITMASK;
      this_arg = "largefile";
    }
    else if (STRPREFIX (argv[i], "quota:")) {
      switch (guestfs_int_is_true (&argv[i][6])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][6]);
          goto out;
        case 0:  optargs_s.quota = 0; break;
        default: optargs_s.quota = 1;
      }
      this_mask = GUESTFS_MKE2FS_QUOTA_BITMASK;
      this_arg = "quota";
    }
    else if (STRPREFIX (argv[i], "resizeinode:")) {
      switch (guestfs_int_is_true (&argv[i][12])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][12]);
          goto out;
        case 0:  optargs_s.resizeinode = 0; break;
        default: optargs_s.resizeinode = 1;
      }
      this_mask = GUESTFS_MKE2FS_RESIZEINODE_BITMASK;
      this_arg = "resizeinode";
    }
    else if (STRPREFIX (argv[i], "sparsesuper:")) {
      switch (guestfs_int_is_true (&argv[i][12])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][12]);
          goto out;
        case 0:  optargs_s.sparsesuper = 0; break;
        default: optargs_s.sparsesuper = 1;
      }
      this_mask = GUESTFS_MKE2FS_SPARSESUPER_BITMASK;
      this_arg = "sparsesuper";
    }
    else if (STRPREFIX (argv[i], "uninitbg:")) {
      switch (guestfs_int_is_true (&argv[i][9])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][9]);
          goto out;
        case 0:  optargs_s.uninitbg = 0; break;
        default: optargs_s.uninitbg = 1;
      }
      this_mask = GUESTFS_MKE2FS_UNINITBG_BITMASK;
      this_arg = "uninitbg";
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

  r = guestfs_mke2fs_argv (g, device, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_mke2fs_JL (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *label;
  size_t i = 0;

  if (argc != 4) {
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
  label = argv[i++];
  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

int
run_mke2fs_JU (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *uuid;
  size_t i = 0;

  if (argc != 4) {
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
  uuid = argv[i++];
  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

int
run_mke2journal (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int blocksize;
  const char *device;
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
  r = guestfs_mke2journal (g, blocksize, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

int
run_mknod_b (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int mode;
  int devmajor;
  int devminor;
  char *path;
  size_t i = 0;

  if (argc != 4) {
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
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "devmajor", "xstrtoll", xerr);
      goto out_devmajor;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "devmajor");
      goto out_devmajor;
    }
    /* The check above should ensure this assignment does not overflow. */
    devmajor = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "devminor", "xstrtoll", xerr);
      goto out_devminor;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "devminor");
      goto out_devminor;
    }
    /* The check above should ensure this assignment does not overflow. */
    devminor = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_devminor:
 out_devmajor:
 out_mode:
 out_noargs:
  return ret;
}

int
run_mount_local (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *localmountpoint;
  struct guestfs_mount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_local_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 5) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  localmountpoint = argv[i++];

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
      this_mask = GUESTFS_MOUNT_LOCAL_READONLY_BITMASK;
      this_arg = "readonly";
    }
    else if (STRPREFIX (argv[i], "options:")) {
      optargs_s.options = &argv[i][8];
      this_mask = GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK;
      this_arg = "options";
    }
    else if (STRPREFIX (argv[i], "cachetimeout:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][13], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.cachetimeout", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.cachetimeout");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.cachetimeout = r;
      }
      this_mask = GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK;
      this_arg = "cachetimeout";
    }
    else if (STRPREFIX (argv[i], "debugcalls:")) {
      switch (guestfs_int_is_true (&argv[i][11])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][11]);
          goto out;
        case 0:  optargs_s.debugcalls = 0; break;
        default: optargs_s.debugcalls = 1;
      }
      this_mask = GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK;
      this_arg = "debugcalls";
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

  r = guestfs_mount_local_argv (g, localmountpoint, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_ntfsresize_size (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_ntfsresize_size (g, device, size);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
 out_noargs:
  return ret;
}

int
run_part_del (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_part_del (g, device, partnum);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_partnum:
 out_noargs:
  return ret;
}

int
run_part_get_gpt_type (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
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
  r = guestfs_part_get_gpt_type (g, device, partnum);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_partnum:
 out_noargs:
  return ret;
}

int
run_ping_daemon (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_ping_daemon (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_remove_drive (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_remove_drive (g, label);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_rm (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_rm (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_rmdir (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_rmdir (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_rsync (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *src;
  char *dest;
  struct guestfs_rsync_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 4) {
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
      this_mask = GUESTFS_RSYNC_ARCHIVE_BITMASK;
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
      this_mask = GUESTFS_RSYNC_DELETEDEST_BITMASK;
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

  r = guestfs_rsync_argv (g, src, dest, optargs);
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
run_set_backend_settings (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char **settings;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  settings = parse_string_list (argv[i++]);
  if (settings == NULL) goto out_settings;
  r = guestfs_set_backend_settings (g, settings);
  if (r == -1) goto out;
  ret = 0;
 out:
  guestfs_int_free_string_list (settings);
 out_settings:
 out_noargs:
  return ret;
}

int
run_set_hv (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *hv;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  hv = argv[i++];
  r = guestfs_set_hv (g, hv);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_set_qemu (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *hv;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  hv = STRNEQ (argv[i], "") ? argv[i] : NULL;
  i++;
  r = guestfs_set_qemu (g, hv);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_set_recovery_proc (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int recoveryproc;
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
      goto out_recoveryproc;
    case 0:  recoveryproc = 0; break;
    default: recoveryproc = 1;
  }
  r = guestfs_set_recovery_proc (g, recoveryproc);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_recoveryproc:
 out_noargs:
  return ret;
}

int
run_set_uuid (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_set_uuid (g, device, uuid);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_setcon (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *context;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  context = argv[i++];
  r = guestfs_setcon (g, context);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_statvfs (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_statvfs *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_statvfs (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_statvfs (r);
  guestfs_free_statvfs (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_strings (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_strings (g, path);
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
run_swapoff_label (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_swapoff_label (g, label);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_swapoff_uuid (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_swapoff_uuid (g, uuid);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_tar_in (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *tarfile;
  char *directory;
  struct guestfs_tar_in_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_in_opts_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 6) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  tarfile = file_in (argv[i++]);
  if (tarfile == NULL) goto out_tarfile;
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "compress:")) {
      optargs_s.compress = &argv[i][9];
      this_mask = GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK;
      this_arg = "compress";
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
      this_mask = GUESTFS_TAR_IN_OPTS_XATTRS_BITMASK;
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
      this_mask = GUESTFS_TAR_IN_OPTS_SELINUX_BITMASK;
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
      this_mask = GUESTFS_TAR_IN_OPTS_ACLS_BITMASK;
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

  r = guestfs_tar_in_opts_argv (g, tarfile, directory, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (directory);
 out_directory:
  free_file_in (tarfile);
 out_tarfile:
 out_noargs:
  return ret;
}

int
run_truncate (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_truncate (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_tune2fs (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  struct guestfs_tune2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tune2fs_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 11) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "force:")) {
      switch (guestfs_int_is_true (&argv[i][6])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][6]);
          goto out;
        case 0:  optargs_s.force = 0; break;
        default: optargs_s.force = 1;
      }
      this_mask = GUESTFS_TUNE2FS_FORCE_BITMASK;
      this_arg = "force";
    }
    else if (STRPREFIX (argv[i], "maxmountcount:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][14], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.maxmountcount", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.maxmountcount");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.maxmountcount = r;
      }
      this_mask = GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
      this_arg = "maxmountcount";
    }
    else if (STRPREFIX (argv[i], "mountcount:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][11], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.mountcount", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.mountcount");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.mountcount = r;
      }
      this_mask = GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
      this_arg = "mountcount";
    }
    else if (STRPREFIX (argv[i], "errorbehavior:")) {
      optargs_s.errorbehavior = &argv[i][14];
      this_mask = GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK;
      this_arg = "errorbehavior";
    }
    else if (STRPREFIX (argv[i], "group:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][6], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.group", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.group = r;
      }
      this_mask = GUESTFS_TUNE2FS_GROUP_BITMASK;
      this_arg = "group";
    }
    else if (STRPREFIX (argv[i], "intervalbetweenchecks:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][22], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.intervalbetweenchecks", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.intervalbetweenchecks");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.intervalbetweenchecks = r;
      }
      this_mask = GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
      this_arg = "intervalbetweenchecks";
    }
    else if (STRPREFIX (argv[i], "reservedblockspercentage:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][25], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.reservedblockspercentage", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.reservedblockspercentage");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.reservedblockspercentage = r;
      }
      this_mask = GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
      this_arg = "reservedblockspercentage";
    }
    else if (STRPREFIX (argv[i], "lastmounteddirectory:")) {
      optargs_s.lastmounteddirectory = &argv[i][21];
      this_mask = GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK;
      this_arg = "lastmounteddirectory";
    }
    else if (STRPREFIX (argv[i], "reservedblockscount:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][20], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.reservedblockscount", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.reservedblockscount = r;
      }
      this_mask = GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
      this_arg = "reservedblockscount";
    }
    else if (STRPREFIX (argv[i], "user:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][5], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.user", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.user = r;
      }
      this_mask = GUESTFS_TUNE2FS_USER_BITMASK;
      this_arg = "user";
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

  r = guestfs_tune2fs_argv (g, device, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_upload (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *filename;
  char *remotefilename;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  filename = file_in (argv[i++]);
  if (filename == NULL) goto out_filename;
  remotefilename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (remotefilename == NULL) goto out_remotefilename;
  r = guestfs_upload (g, filename, remotefilename);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (remotefilename);
 out_remotefilename:
  free_file_in (filename);
 out_filename:
 out_noargs:
  return ret;
}

int
run_utimens (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  int64_t atsecs;
  int64_t atnsecs;
  int64_t mtsecs;
  int64_t mtnsecs;
  size_t i = 0;

  if (argc != 5) {
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
               cmd, "atsecs", "xstrtoll", xerr);
      goto out_atsecs;
    }
    atsecs = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "atnsecs", "xstrtoll", xerr);
      goto out_atnsecs;
    }
    atnsecs = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "mtsecs", "xstrtoll", xerr);
      goto out_mtsecs;
    }
    mtsecs = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "mtnsecs", "xstrtoll", xerr);
      goto out_mtnsecs;
    }
    mtnsecs = r;
  }
  r = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_mtnsecs:
 out_mtsecs:
 out_atnsecs:
 out_atsecs:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_version (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_version *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_version (g);
  if (r == NULL) goto out;
  ret = 0;
  print_version (r);
  guestfs_free_version (r);
 out:
 out_noargs:
  return ret;
}

int
run_vfs_minimum_size (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;
  const char *mountable;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  mountable = argv[i++];
  r = guestfs_vfs_minimum_size (g, mountable);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_vfs_uuid (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_vfs_uuid (g, mountable);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_vgs (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_vgs (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_write_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *path;
  const char *content;
  int size;
  size_t i = 0;

  if (argc != 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  content = argv[i++];
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
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "size");
      goto out_size;
    }
    /* The check above should ensure this assignment does not overflow. */
    size = r;
  }
  r = guestfs_write_file (g, path, content, size);
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
run_zero (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_zero (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_zerofree (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_zerofree (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_zgrepi (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_zgrepi (g, regex, path);
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
