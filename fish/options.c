/* libguestfs - guestfish and guestmount shared option parsing
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
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/**
 * This file contains common options parsing code used by guestfish
 * and many other tools which share a common options syntax.
 *
 * For example, guestfish, virt-cat, virt-ls etc all support the I<-a>
 * option, and that is handled in all of those tools using a macro
 * C<OPTION_a> defined in F<fish/options.h>.
 *
 * There are a lot of common global variables used, C<drvs>
 * accumulates the list of drives, C<verbose> for the I<-v> flag, and
 * many more.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>
#include <libintl.h>

#include "guestfs.h"
#include "options.h"
#include "uri.h"

/**
 * Handle the guestfish I<-a> option on the command line.
 */
void
option_a (const char *arg, const char *format, struct drv **drvsp)
{
  struct uri uri;
  struct drv *drv;

  drv = calloc (1, sizeof (struct drv));
  if (!drv)
    error (EXIT_FAILURE, errno, "calloc");

  if (parse_uri (arg, &uri) == -1)
    exit (EXIT_FAILURE);

  if (STREQ (uri.protocol, "file")) {
    /* Ordinary file. */
    if (access (uri.path, R_OK) != 0)
      error (EXIT_FAILURE, errno, "access: %s", uri.path);

    drv->type = drv_a;
    drv->nr_drives = -1;
    drv->a.filename = uri.path;
    drv->a.format = format;

    free (uri.protocol);
  }
  else {
    /* Remote storage. */
    drv->type = drv_uri;
    drv->nr_drives = -1;
    drv->uri.path = uri.path;
    drv->uri.protocol = uri.protocol;
    drv->uri.server = uri.server;
    drv->uri.username = uri.username;
    drv->uri.password = uri.password;
    drv->uri.format = format;
    drv->uri.orig_uri = arg;
  }

  drv->next = *drvsp;
  *drvsp = drv;
}

/**
 * Handle the I<-d> option when passed on the command line.
 */
void
option_d (const char *arg, struct drv **drvsp)
{
  struct drv *drv;

  drv = calloc (1, sizeof (struct drv));
  if (!drv)
    error (EXIT_FAILURE, errno, "calloc");

  drv->type = drv_d;
  drv->nr_drives = -1;
  drv->d.guest = optarg;

  drv->next = *drvsp;
  *drvsp = drv;
}

char
add_drives_handle (guestfs_h *g, struct drv *drv, char next_drive)
{
  int r;
  struct guestfs_add_drive_opts_argv ad_optargs;

  if (next_drive > 'z')
    error (EXIT_FAILURE, 0, _("too many drives added on the command line"));

  if (drv) {
    next_drive = add_drives (drv->next, next_drive);

    free (drv->device);
    drv->device = NULL;

    if (asprintf (&drv->device, "/dev/sd%c", next_drive) == -1)
      error (EXIT_FAILURE, errno, "asprintf");

    switch (drv->type) {
    case drv_a:
      ad_optargs.bitmask = 0;
      if (read_only) {
        ad_optargs.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
        ad_optargs.readonly = 1;
      }
      if (drv->a.format) {
        ad_optargs.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
        ad_optargs.format = drv->a.format;
      }
      if (drv->a.cachemode) {
        ad_optargs.bitmask |= GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK;
        ad_optargs.cachemode = drv->a.cachemode;
      }
      if (drv->a.discard) {
        ad_optargs.bitmask |= GUESTFS_ADD_DRIVE_OPTS_DISCARD_BITMASK;
        ad_optargs.discard = drv->a.discard;
      }

      r = guestfs_add_drive_opts_argv (g, drv->a.filename, &ad_optargs);
      if (r == -1)
        exit (EXIT_FAILURE);

      drv->nr_drives = 1;
      next_drive++;
      break;

    case drv_uri:
      ad_optargs.bitmask = 0;
      if (read_only) {
        ad_optargs.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
        ad_optargs.readonly = 1;
      }
      if (drv->uri.format) {
        ad_optargs.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
        ad_optargs.format = drv->uri.format;
      }
      ad_optargs.bitmask |= GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK;
      ad_optargs.protocol = drv->uri.protocol;
      if (drv->uri.server) {
        ad_optargs.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK;
        ad_optargs.server = drv->uri.server;
      }
      if (drv->uri.username) {
        ad_optargs.bitmask |= GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK;
        ad_optargs.username = drv->uri.username;
      }
      if (drv->uri.password) {
        ad_optargs.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK;
        ad_optargs.secret = drv->uri.password;
      }

      r = guestfs_add_drive_opts_argv (g, drv->uri.path, &ad_optargs);
      if (r == -1)
        exit (EXIT_FAILURE);

      drv->nr_drives = 1;
      next_drive++;
      break;

    case drv_d:
      r = add_libvirt_drives (g, drv->d.guest);
      if (r == -1)
        exit (EXIT_FAILURE);

      drv->nr_drives = r;
      next_drive += r;
      break;

#if COMPILING_GUESTFISH
    case drv_N:
      /* -N option is not affected by --ro */
      r = guestfs_add_drive_opts (g, drv->N.filename,
                                  GUESTFS_ADD_DRIVE_OPTS_FORMAT, "raw",
                                  -1);
      if (r == -1)
        exit (EXIT_FAILURE);

      drv->nr_drives = 1;
      next_drive++;
      break;
#endif

#if COMPILING_VIRT_RESCUE
    case drv_scratch:
      r = guestfs_add_drive_scratch (g, drv->scratch.size, -1);
      if (r == -1)
        exit (EXIT_FAILURE);

      drv->nr_drives = 1;
      next_drive++;
      break;
#endif

    default: /* keep GCC happy */
      abort ();
    }
  }

  return next_drive;
}

static void display_mountpoints_on_failure (const char *mp_device, const char *user_supplied_options);

void
mount_mps (struct mp *mp)
{
  int r;

  if (mp) {
    /* List is built in reverse order, so mount them in reverse order. */
    mount_mps (mp->next);

    const char *options;
    if (mp->options)
      options = mp->options;
    else if (read_only)
      options = "ro";
    else
      options = "";

    if (mp->fstype)
      r = guestfs_mount_vfs (g, options, mp->fstype, mp->device,
                             mp->mountpoint);
    else
      r = guestfs_mount_options (g, options, mp->device,
                                 mp->mountpoint);
    if (r == -1) {
      display_mountpoints_on_failure (mp->device, mp->options);
      exit (EXIT_FAILURE);
    }
  }
}

/**
 * If the I<-m> option fails on any command, display a useful error
 * message listing the mountpoints.
 */
static void
display_mountpoints_on_failure (const char *mp_device,
                                const char *user_supplied_options)
{
  CLEANUP_FREE_STRING_LIST char **fses = guestfs_list_filesystems (g);
  size_t i;

  if (fses == NULL || fses[0] == NULL)
    return;

  fprintf (stderr, _("%s: '%s' could not be mounted.\n"),
           guestfs_int_program_name, mp_device);

  if (user_supplied_options)
    fprintf (stderr, _("%s: Check mount(8) man page to ensure options '%s'\n"
                       "%s: are supported by the filesystem that is being mounted.\n"),
             guestfs_int_program_name, user_supplied_options, guestfs_int_program_name);

  fprintf (stderr, _("%s: Did you mean to mount one of these filesystems?\n"),
           guestfs_int_program_name);

  for (i = 0; fses[i] != NULL; i += 2) {
    CLEANUP_FREE char *p = NULL;
    CLEANUP_FREE char *device = guestfs_mountable_device (g, fses[i]);
    CLEANUP_FREE char *subvolume = NULL;

    guestfs_push_error_handler (g, NULL, NULL);

    subvolume = guestfs_mountable_subvolume (g, fses[i]);
    if (subvolume == NULL && guestfs_last_errno (g) != EINVAL)
      error (EXIT_FAILURE, 0,
             _("cannot determine the subvolume for %s: %s (%d)"),
             fses[i], guestfs_last_error (g), guestfs_last_errno (g));

    guestfs_pop_error_handler (g);

    /* Reformat the internal btrfsvol string into a valid mount option */
    if (device && subvolume) {
      if (asprintf (&p, "%s:/:subvol=%s", device, subvolume) == -1)
        error (EXIT_FAILURE, errno, "asprintf");
    } else {
      p = guestfs_canonical_device_name (g, fses[i]);
    }

    fprintf (stderr, "%s: \t%s (%s)\n", guestfs_int_program_name,
             p ? p : fses[i], fses[i+1]);
  }
}

void
free_drives (struct drv *drv)
{
  if (!drv) return;
  free_drives (drv->next);

  free (drv->device);

  switch (drv->type) {
  case drv_a:
    free (drv->a.filename);
    /* a.format is an optarg, so don't free it */
    /* a.cachemode is a static string, so don't free it */
    /* a.discard is a static string, so don't free it */
    break;
  case drv_uri:
    free (drv->uri.path);
    free (drv->uri.protocol);
    guestfs_int_free_string_list (drv->uri.server);
    free (drv->uri.username);
    free (drv->uri.password);
    break;
  case drv_d:
    /* d.filename is optarg, don't free it */
    break;
#if COMPILING_GUESTFISH
  case drv_N:
    free (drv->N.filename);
    drv->N.data_free (drv->N.data);
    break;
#endif
#if COMPILING_VIRT_RESCUE
  case drv_scratch:
    /* nothing */
    break;
#endif
  default: ;                    /* keep GCC happy */
  }
  free (drv);
}

void
free_mps (struct mp *mp)
{
  if (!mp) return;
  free_mps (mp->next);

  /* The drive and mountpoint fields are not allocated
   * from the heap, so we should not free them here.
   */

  free (mp);
}

/**
 * Implements the internal C<tool I<--short-options>> flag, which just
 * lists out the short options available.  Used by bash completion.
 */
void
display_short_options (const char *format)
{
  while (*format) {
    if (*format != ':')
      printf ("-%c\n", *format);
    ++format;
  }
  exit (EXIT_SUCCESS);
}

/**
 * Implements the internal C<tool I<--long-options>> flag, which just
 * lists out the long options available.  Used by bash completion.
 */
void
display_long_options (const struct option *long_options)
{
  while (long_options->name) {
    if (STRNEQ (long_options->name, "long-options") &&
        STRNEQ (long_options->name, "short-options"))
      printf ("--%s\n", long_options->name);
    long_options++;
  }
  exit (EXIT_SUCCESS);
}
