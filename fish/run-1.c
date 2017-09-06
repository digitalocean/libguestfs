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
print_btrfsqgroup_list (struct guestfs_btrfsqgroup_list *btrfsqgroups)
{
  size_t i;

  for (i = 0; i < btrfsqgroups->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_btrfsqgroup_indent (&btrfsqgroups->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_tsk_dirent_list (struct guestfs_tsk_dirent_list *tsk_dirents)
{
  size_t i;

  for (i = 0; i < tsk_dirents->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_tsk_dirent_indent (&tsk_dirents->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_application2_list (struct guestfs_application2_list *application2s)
{
  size_t i;

  for (i = 0; i < application2s->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_application2_indent (&application2s->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

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
print_lvm_vg_list (struct guestfs_lvm_vg_list *lvm_vgs)
{
  size_t i;

  for (i = 0; i < lvm_vgs->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_lvm_vg_indent (&lvm_vgs->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_stat_list (struct guestfs_stat_list *stats)
{
  size_t i;

  for (i = 0; i < stats->len; ++i) {
    printf ("[%zu] = {\n", i);
    guestfs_int_print_stat_indent (&stats->val[i], stdout, "\n", "  ");
    printf ("}\n");
  }
}

static void
print_stat (struct guestfs_stat *stat)
{
  guestfs_int_print_stat_indent (stat, stdout, "\n", "");
}

int
run_aug_clear (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *augpath;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  augpath = argv[i++];
  r = guestfs_aug_clear (g, augpath);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_aug_defvar (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *name;
  const char *expr;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  name = argv[i++];
  expr = STRNEQ (argv[i], "") ? argv[i] : NULL;
  i++;
  r = guestfs_aug_defvar (g, name, expr);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_base64_in (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *base64file;
  char *filename;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  base64file = file_in (argv[i++]);
  if (base64file == NULL) goto out_base64file;
  filename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (filename == NULL) goto out_filename;
  r = guestfs_base64_in (g, base64file, filename);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (filename);
 out_filename:
  free_file_in (base64file);
 out_base64file:
 out_noargs:
  return ret;
}

int
run_base64_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *filename;
  char *base64file;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  filename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (filename == NULL) goto out_filename;
  base64file = file_out (argv[i++]);
  if (base64file == NULL) goto out_base64file;
  r = guestfs_base64_out (g, filename, base64file);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (base64file);
 out_base64file:
  free (filename);
 out_filename:
 out_noargs:
  return ret;
}

int
run_btrfs_balance_resume (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_btrfs_balance_resume (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_btrfs_fsck (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  struct guestfs_btrfs_fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_fsck_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "superblock:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][11], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.superblock", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.superblock = r;
      }
      this_mask = GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK;
      this_arg = "superblock";
    }
    else if (STRPREFIX (argv[i], "repair:")) {
      switch (guestfs_int_is_true (&argv[i][7])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][7]);
          goto out;
        case 0:  optargs_s.repair = 0; break;
        default: optargs_s.repair = 1;
      }
      this_mask = GUESTFS_BTRFS_FSCK_REPAIR_BITMASK;
      this_arg = "repair";
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

  r = guestfs_btrfs_fsck_argv (g, device, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_btrfs_qgroup_show (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_btrfsqgroup_list *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_btrfs_qgroup_show (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_btrfsqgroup_list (r);
  guestfs_free_btrfsqgroup_list (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_btrfs_rescue_chunk_recover (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_btrfs_rescue_chunk_recover (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_btrfs_scrub_resume (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_btrfs_scrub_resume (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_cat (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_cat (g, path);
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
run_checksum_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *csumtype;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  csumtype = argv[i++];
  device = argv[i++];
  r = guestfs_checksum_device (g, csumtype, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_clear_backend_setting (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *name;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  name = argv[i++];
  r = guestfs_clear_backend_setting (g, name);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_config (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *hvparam;
  const char *hvvalue;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  hvparam = argv[i++];
  hvvalue = STRNEQ (argv[i], "") ? argv[i] : NULL;
  i++;
  r = guestfs_config (g, hvparam, hvvalue);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_copy_attributes (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *src;
  char *dest;
  struct guestfs_copy_attributes_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_attributes_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 6) {
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

    if (STRPREFIX (argv[i], "all:")) {
      switch (guestfs_int_is_true (&argv[i][4])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][4]);
          goto out;
        case 0:  optargs_s.all = 0; break;
        default: optargs_s.all = 1;
      }
      this_mask = GUESTFS_COPY_ATTRIBUTES_ALL_BITMASK;
      this_arg = "all";
    }
    else if (STRPREFIX (argv[i], "mode:")) {
      switch (guestfs_int_is_true (&argv[i][5])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][5]);
          goto out;
        case 0:  optargs_s.mode = 0; break;
        default: optargs_s.mode = 1;
      }
      this_mask = GUESTFS_COPY_ATTRIBUTES_MODE_BITMASK;
      this_arg = "mode";
    }
    else if (STRPREFIX (argv[i], "xattributes:")) {
      switch (guestfs_int_is_true (&argv[i][12])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][12]);
          goto out;
        case 0:  optargs_s.xattributes = 0; break;
        default: optargs_s.xattributes = 1;
      }
      this_mask = GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES_BITMASK;
      this_arg = "xattributes";
    }
    else if (STRPREFIX (argv[i], "ownership:")) {
      switch (guestfs_int_is_true (&argv[i][10])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][10]);
          goto out;
        case 0:  optargs_s.ownership = 0; break;
        default: optargs_s.ownership = 1;
      }
      this_mask = GUESTFS_COPY_ATTRIBUTES_OWNERSHIP_BITMASK;
      this_arg = "ownership";
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

  r = guestfs_copy_attributes_argv (g, src, dest, optargs);
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
run_copy_device_to_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *src;
  const char *dest;
  struct guestfs_copy_device_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 7) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  src = argv[i++];
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
      this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
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
      this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
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
      this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
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
      this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK;
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
      this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_APPEND_BITMASK;
      this_arg = "append";
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

  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_dd (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_dd (g, src, dest);
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
run_debug_drives (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_debug_drives (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_device_index (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_device_index (g, device);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_download_inode (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_download_inode (g, device, inode, filename);
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
run_exists (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_exists (g, path);
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
run_filesystem_walk (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_tsk_dirent_list *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_filesystem_walk (g, device);
  if (r == NULL) goto out;
  ret = 0;
  print_tsk_dirent_list (r);
  guestfs_free_tsk_dirent_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_fill_dir (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *dir;
  int nr;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  dir = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dir == NULL) goto out_dir;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %u)\n"),
               cmd, "nr", "xstrtoll", xerr);
      goto out_nr;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "nr");
      goto out_nr;
    }
    /* The check above should ensure this assignment does not overflow. */
    nr = r;
  }
  r = guestfs_fill_dir (g, dir, nr);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_nr:
  free (dir);
 out_dir:
 out_noargs:
  return ret;
}

int
run_findfs_label (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *label;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  label = argv[i++];
  r = guestfs_findfs_label (g, label);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_get_identifier (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  const char *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_identifier (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_get_libvirt_requested_credential_prompt (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  int index;
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
  r = guestfs_get_libvirt_requested_credential_prompt (g, index);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_index:
 out_noargs:
  return ret;
}

int
run_get_network (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_network (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_get_qemu (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  const char *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_qemu (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_get_umask (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_umask (g);
  if (r == -1) goto out;
  ret = 0;
  printf ("%s%o\n", r != 0 ? "0" : "", (unsigned) r);
 out:
 out_noargs:
  return ret;
}

int
run_get_verbose (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_get_verbose (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_getxattrs (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_xattr_list *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_getxattrs (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_xattr_list (r);
  guestfs_free_xattr_list (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_grep (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  const char *regex;
  char *path;
  struct guestfs_grep_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_grep_opts_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 6) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  regex = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "extended:")) {
      switch (guestfs_int_is_true (&argv[i][9])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][9]);
          goto out;
        case 0:  optargs_s.extended = 0; break;
        default: optargs_s.extended = 1;
      }
      this_mask = GUESTFS_GREP_OPTS_EXTENDED_BITMASK;
      this_arg = "extended";
    }
    else if (STRPREFIX (argv[i], "fixed:")) {
      switch (guestfs_int_is_true (&argv[i][6])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][6]);
          goto out;
        case 0:  optargs_s.fixed = 0; break;
        default: optargs_s.fixed = 1;
      }
      this_mask = GUESTFS_GREP_OPTS_FIXED_BITMASK;
      this_arg = "fixed";
    }
    else if (STRPREFIX (argv[i], "insensitive:")) {
      switch (guestfs_int_is_true (&argv[i][12])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][12]);
          goto out;
        case 0:  optargs_s.insensitive = 0; break;
        default: optargs_s.insensitive = 1;
      }
      this_mask = GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK;
      this_arg = "insensitive";
    }
    else if (STRPREFIX (argv[i], "compressed:")) {
      switch (guestfs_int_is_true (&argv[i][11])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][11]);
          goto out;
        case 0:  optargs_s.compressed = 0; break;
        default: optargs_s.compressed = 1;
      }
      this_mask = GUESTFS_GREP_OPTS_COMPRESSED_BITMASK;
      this_arg = "compressed";
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

  r = guestfs_grep_opts_argv (g, regex, path, optargs);
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
run_hivex_node_parent (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;
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
  r = guestfs_hivex_node_parent (g, nodeh);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_nodeh:
 out_noargs:
  return ret;
}

int
run_hivex_root (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int64_t r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_hivex_root (g);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_noargs:
  return ret;
}

int
run_hivex_value_value (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  size_t size;
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
  r = guestfs_hivex_value_value (g, valueh, &size);
  if (r == NULL) goto out;
  if (full_write (1, r, size) != size) {
    perror ("write");
    free (r);
    goto out;
  }
  ret = 0;
  free (r);
 out:
 out_valueh:
 out_noargs:
  return ret;
}

int
run_initrd_list (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_initrd_list (g, path);
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
run_inotify_files (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_inotify_files (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_inotify_rm_watch (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int wd;
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
               cmd, "wd", "xstrtoll", xerr);
      goto out_wd;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "wd");
      goto out_wd;
    }
    /* The check above should ensure this assignment does not overflow. */
    wd = r;
  }
  r = guestfs_inotify_rm_watch (g, wd);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_wd:
 out_noargs:
  return ret;
}

int
run_inspect_get_icon (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  size_t size;
  const char *root;
  struct guestfs_inspect_get_icon_argv optargs_s = { .bitmask = 0 };
  struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  root = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "favicon:")) {
      switch (guestfs_int_is_true (&argv[i][8])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][8]);
          goto out;
        case 0:  optargs_s.favicon = 0; break;
        default: optargs_s.favicon = 1;
      }
      this_mask = GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
      this_arg = "favicon";
    }
    else if (STRPREFIX (argv[i], "highquality:")) {
      switch (guestfs_int_is_true (&argv[i][12])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][12]);
          goto out;
        case 0:  optargs_s.highquality = 0; break;
        default: optargs_s.highquality = 1;
      }
      this_mask = GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
      this_arg = "highquality";
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

  r = guestfs_inspect_get_icon_argv (g, root, &size, optargs);
  if (r == NULL) goto out;
  if (full_write (1, r, size) != size) {
    perror ("write");
    free (r);
    goto out;
  }
  ret = 0;
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_inspect_get_windows_system_hive (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_inspect_get_windows_system_hive (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_inspect_is_netinst (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_inspect_is_netinst (g, root);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

int
run_inspect_list_applications2 (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_application2_list *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_list_applications2 (g, root);
  if (r == NULL) goto out;
  ret = 0;
  print_application2_list (r);
  guestfs_free_application2_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_is_symlink (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_is_symlink (g, path);
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
run_is_zero (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_is_zero (g, path);
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
run_lchown (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_lchown (g, owner, group, path);
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
run_ldmtool_create_all (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_ldmtool_create_all (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_ldmtool_diskgroup_disks (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;
  const char *diskgroup;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  diskgroup = argv[i++];
  r = guestfs_ldmtool_diskgroup_disks (g, diskgroup);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_list_partitions (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_list_partitions (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_llz (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  char *directory;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  r = guestfs_llz (g, directory);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}

int
run_lstat (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_lstat (g, path);
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
run_lstatlist (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_stat_list *r;
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
  r = guestfs_lstatlist (g, path, names);
  if (r == NULL) goto out;
  ret = 0;
  print_stat_list (r);
  guestfs_free_stat_list (r);
 out:
  guestfs_int_free_string_list (names);
 out_names:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_luks_open (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  char *key;
  const char *mapname;
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
  mapname = argv[i++];
  r = guestfs_luks_open (g, device, key, mapname);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (key);
 out_key:
 out_noargs:
  return ret;
}

int
run_luks_open_ro (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  char *key;
  const char *mapname;
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
  mapname = argv[i++];
  r = guestfs_luks_open_ro (g, device, key, mapname);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (key);
 out_key:
 out_noargs:
  return ret;
}

int
run_lvm_remove_all (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_lvm_remove_all (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_lvresize_free (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *lv;
  int percent;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  lv = argv[i++];
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
  r = guestfs_lvresize_free (g, lv, percent);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_percent:
 out_noargs:
  return ret;
}

int
run_md_create (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *name;
  char **devices;
  struct guestfs_md_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_md_create_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 7) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  name = argv[i++];
  devices = parse_string_list (argv[i++]);
  if (devices == NULL) goto out_devices;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "missingbitmap:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][14], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.missingbitmap", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.missingbitmap = r;
      }
      this_mask = GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
      this_arg = "missingbitmap";
    }
    else if (STRPREFIX (argv[i], "nrdevices:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.nrdevices", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.nrdevices");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.nrdevices = r;
      }
      this_mask = GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
      this_arg = "nrdevices";
    }
    else if (STRPREFIX (argv[i], "spare:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][6], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.spare", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.spare");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.spare = r;
      }
      this_mask = GUESTFS_MD_CREATE_SPARE_BITMASK;
      this_arg = "spare";
    }
    else if (STRPREFIX (argv[i], "chunk:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][6], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %u)\n"),
                   cmd, "optargs_s.chunk", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.chunk = r;
      }
      this_mask = GUESTFS_MD_CREATE_CHUNK_BITMASK;
      this_arg = "chunk";
    }
    else if (STRPREFIX (argv[i], "level:")) {
      optargs_s.level = &argv[i][6];
      this_mask = GUESTFS_MD_CREATE_LEVEL_BITMASK;
      this_arg = "level";
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

  r = guestfs_md_create_argv (g, name, devices, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  guestfs_int_free_string_list (devices);
 out_devices:
 out_noargs:
  return ret;
}

int
run_mkdtemp (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  char *tmpl;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  tmpl = win_prefix (argv[i++]); /* process "win:" prefix */
  if (tmpl == NULL) goto out_tmpl;
  r = guestfs_mkdtemp (g, tmpl);
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
run_mknod (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_mknod (g, mode, devmajor, devminor, path);
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
run_mount (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *mountable;
  const char *mountpoint;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  mountable = argv[i++];
  mountpoint = argv[i++];
  r = guestfs_mount (g, mountable, mountpoint);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_mount_local_run (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_mount_local_run (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_mount_ro (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *mountable;
  const char *mountpoint;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  mountable = argv[i++];
  mountpoint = argv[i++];
  r = guestfs_mount_ro (g, mountable, mountpoint);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_mountable_subvolume (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_mountable_subvolume (g, mountable);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

int
run_mounts (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char **r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_mounts (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_ntfs_3g_probe (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int rw;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  switch (guestfs_int_is_true (argv[i++])) {
    case -1:
      fprintf (stderr,
               _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
               getprogname (), argv[i-1]);
      goto out_rw;
    case 0:  rw = 0; break;
    default: rw = 1;
  }
  device = argv[i++];
  r = guestfs_ntfs_3g_probe (g, rw, device);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_rw:
 out_noargs:
  return ret;
}

int
run_ntfsclone_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  char *backupfile;
  struct guestfs_ntfsclone_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsclone_out_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 7) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  backupfile = file_out (argv[i++]);
  if (backupfile == NULL) goto out_backupfile;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "metadataonly:")) {
      switch (guestfs_int_is_true (&argv[i][13])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][13]);
          goto out;
        case 0:  optargs_s.metadataonly = 0; break;
        default: optargs_s.metadataonly = 1;
      }
      this_mask = GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK;
      this_arg = "metadataonly";
    }
    else if (STRPREFIX (argv[i], "rescue:")) {
      switch (guestfs_int_is_true (&argv[i][7])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][7]);
          goto out;
        case 0:  optargs_s.rescue = 0; break;
        default: optargs_s.rescue = 1;
      }
      this_mask = GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK;
      this_arg = "rescue";
    }
    else if (STRPREFIX (argv[i], "ignorefscheck:")) {
      switch (guestfs_int_is_true (&argv[i][14])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][14]);
          goto out;
        case 0:  optargs_s.ignorefscheck = 0; break;
        default: optargs_s.ignorefscheck = 1;
      }
      this_mask = GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK;
      this_arg = "ignorefscheck";
    }
    else if (STRPREFIX (argv[i], "preservetimestamps:")) {
      switch (guestfs_int_is_true (&argv[i][19])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][19]);
          goto out;
        case 0:  optargs_s.preservetimestamps = 0; break;
        default: optargs_s.preservetimestamps = 1;
      }
      this_mask = GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK;
      this_arg = "preservetimestamps";
    }
    else if (STRPREFIX (argv[i], "force:")) {
      switch (guestfs_int_is_true (&argv[i][6])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][6]);
          goto out;
        case 0:  optargs_s.force = 0; break;
        default: optargs_s.force = 1;
      }
      this_mask = GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK;
      this_arg = "force";
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

  r = guestfs_ntfsclone_out_argv (g, device, backupfile, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (backupfile);
 out_backupfile:
 out_noargs:
  return ret;
}

int
run_part_set_disk_guid (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  const char *guid;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];
  guid = argv[i++];
  r = guestfs_part_set_disk_guid (g, device, guid);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_part_set_disk_guid_random (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_part_set_disk_guid_random (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_pread (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  size_t size;
  char *path;
  int count;
  int64_t offset;
  size_t i = 0;

  if (argc != 3) {
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
  r = guestfs_pread (g, path, count, offset, &size);
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
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_realpath (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_realpath (g, path);
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
run_selinux_relabel (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *specfile;
  char *path;
  struct guestfs_selinux_relabel_argv optargs_s = { .bitmask = 0 };
  struct guestfs_selinux_relabel_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  specfile = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;

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
      this_mask = GUESTFS_SELINUX_RELABEL_FORCE_BITMASK;
      this_arg = "force";
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

  r = guestfs_selinux_relabel_argv (g, specfile, path, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_set_autosync (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int autosync;
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
      goto out_autosync;
    case 0:  autosync = 0; break;
    default: autosync = 1;
  }
  r = guestfs_set_autosync (g, autosync);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_autosync:
 out_noargs:
  return ret;
}

int
run_set_backend_setting (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *name;
  const char *val;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  name = argv[i++];
  val = argv[i++];
  r = guestfs_set_backend_setting (g, name, val);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_set_identifier (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *identifier;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  identifier = argv[i++];
  r = guestfs_set_identifier (g, identifier);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_set_verbose (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int verbose;
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
      goto out_verbose;
    case 0:  verbose = 0; break;
    default: verbose = 1;
  }
  r = guestfs_set_verbose (g, verbose);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_verbose:
 out_noargs:
  return ret;
}

int
run_swapoff_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *file;
  size_t i = 0;

  if (argc != 1) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  file = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file == NULL) goto out_file;
  r = guestfs_swapoff_file (g, file);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (file);
 out_file:
 out_noargs:
  return ret;
}

int
run_syslinux (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  struct guestfs_syslinux_argv optargs_s = { .bitmask = 0 };
  struct guestfs_syslinux_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "directory:")) {
      optargs_s.directory = &argv[i][10];
      this_mask = GUESTFS_SYSLINUX_DIRECTORY_BITMASK;
      this_arg = "directory";
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

  r = guestfs_syslinux_argv (g, device, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_tail (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_tail (g, path);
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
run_touch (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_touch (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

int
run_tune2fs_l (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_tune2fs_l (g, device);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  guestfs_int_free_string_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_umount (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  char *pathordevice;
  struct guestfs_umount_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_umount_opts_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 3) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  pathordevice = win_prefix (argv[i++]); /* process "win:" prefix */
  if (pathordevice == NULL) goto out_pathordevice;

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
      this_mask = GUESTFS_UMOUNT_OPTS_FORCE_BITMASK;
      this_arg = "force";
    }
    else if (STRPREFIX (argv[i], "lazyunmount:")) {
      switch (guestfs_int_is_true (&argv[i][12])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][12]);
          goto out;
        case 0:  optargs_s.lazyunmount = 0; break;
        default: optargs_s.lazyunmount = 1;
      }
      this_mask = GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK;
      this_arg = "lazyunmount";
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

  r = guestfs_umount_opts_argv (g, pathordevice, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (pathordevice);
 out_pathordevice:
 out_noargs:
  return ret;
}

int
run_vg_activate (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  int activate;
  char **volgroups;
  size_t i = 0;

  if (argc != 2) {
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
  volgroups = parse_string_list (argv[i++]);
  if (volgroups == NULL) goto out_volgroups;
  r = guestfs_vg_activate (g, activate, volgroups);
  if (r == -1) goto out;
  ret = 0;
 out:
  guestfs_int_free_string_list (volgroups);
 out_volgroups:
 out_activate:
 out_noargs:
  return ret;
}

int
run_vgs_full (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  struct guestfs_lvm_vg_list *r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_vgs_full (g);
  if (r == NULL) goto out;
  ret = 0;
  print_lvm_vg_list (r);
  guestfs_free_lvm_vg_list (r);
 out:
 out_noargs:
  return ret;
}

int
run_vgscan (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;

  if (argc != 0) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  r = guestfs_vgscan (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_xfs_admin (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  int r;
  const char *device;
  struct guestfs_xfs_admin_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_admin_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 8) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  device = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "extunwritten:")) {
      switch (guestfs_int_is_true (&argv[i][13])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][13]);
          goto out;
        case 0:  optargs_s.extunwritten = 0; break;
        default: optargs_s.extunwritten = 1;
      }
      this_mask = GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK;
      this_arg = "extunwritten";
    }
    else if (STRPREFIX (argv[i], "imgfile:")) {
      switch (guestfs_int_is_true (&argv[i][8])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][8]);
          goto out;
        case 0:  optargs_s.imgfile = 0; break;
        default: optargs_s.imgfile = 1;
      }
      this_mask = GUESTFS_XFS_ADMIN_IMGFILE_BITMASK;
      this_arg = "imgfile";
    }
    else if (STRPREFIX (argv[i], "v2log:")) {
      switch (guestfs_int_is_true (&argv[i][6])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][6]);
          goto out;
        case 0:  optargs_s.v2log = 0; break;
        default: optargs_s.v2log = 1;
      }
      this_mask = GUESTFS_XFS_ADMIN_V2LOG_BITMASK;
      this_arg = "v2log";
    }
    else if (STRPREFIX (argv[i], "projid32bit:")) {
      switch (guestfs_int_is_true (&argv[i][12])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][12]);
          goto out;
        case 0:  optargs_s.projid32bit = 0; break;
        default: optargs_s.projid32bit = 1;
      }
      this_mask = GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK;
      this_arg = "projid32bit";
    }
    else if (STRPREFIX (argv[i], "lazycounter:")) {
      switch (guestfs_int_is_true (&argv[i][12])) {
        case -1:
          fprintf (stderr,
                   _("%s: '%s': invalid boolean value, use 'true' or 'false'\n"),
                   getprogname (), &argv[i][12]);
          goto out;
        case 0:  optargs_s.lazycounter = 0; break;
        default: optargs_s.lazycounter = 1;
      }
      this_mask = GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK;
      this_arg = "lazycounter";
    }
    else if (STRPREFIX (argv[i], "label:")) {
      optargs_s.label = &argv[i][6];
      this_mask = GUESTFS_XFS_ADMIN_LABEL_BITMASK;
      this_arg = "label";
    }
    else if (STRPREFIX (argv[i], "uuid:")) {
      optargs_s.uuid = &argv[i][5];
      this_mask = GUESTFS_XFS_ADMIN_UUID_BITMASK;
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

  r = guestfs_xfs_admin_argv (g, device, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_zegrepi (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_zegrepi (g, regex, path);
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
run_zfgrep (const char *cmd, size_t argc, char *argv[])
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
  r = guestfs_zfgrep (g, pattern, path);
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
run_zfile (const char *cmd, size_t argc, char *argv[])
{
  int ret = RUN_ERROR;
  char *r;
  const char *meth;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    ret = RUN_WRONG_ARGS;
    goto out_noargs;
  }
  meth = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_zfile (g, meth, path);
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
