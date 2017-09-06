/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/c.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"

int
guestfs_add_domain (guestfs_h *g,
                    const char *dom,
                    ...)
{
  va_list optargs;

  int r;

  va_start (optargs, dom);
  r = guestfs_add_domain_va (g, dom, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_add_domain_va (guestfs_h *g,
                       const char *dom,
                       va_list args)
{
  struct guestfs_add_domain_argv optargs_s;
  struct guestfs_add_domain_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_ADD_DOMAIN_LIBVIRTURI:
      optargs_s.libvirturi = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DOMAIN_READONLY:
      optargs_s.readonly = va_arg (args, int);
      break;
    case GUESTFS_ADD_DOMAIN_IFACE:
      optargs_s.iface = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DOMAIN_LIVE:
      optargs_s.live = va_arg (args, int);
      break;
    case GUESTFS_ADD_DOMAIN_ALLOWUUID:
      optargs_s.allowuuid = va_arg (args, int);
      break;
    case GUESTFS_ADD_DOMAIN_READONLYDISK:
      optargs_s.readonlydisk = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DOMAIN_CACHEMODE:
      optargs_s.cachemode = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DOMAIN_DISCARD:
      optargs_s.discard = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DOMAIN_COPYONREAD:
      optargs_s.copyonread = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "add_domain", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "add_domain");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_add_domain_argv (g, dom, optargs);
}

int
guestfs_add_drive_opts (guestfs_h *g,
                        const char *filename,
                        ...)
{
  va_list optargs;

  int r;

  va_start (optargs, filename);
  r = guestfs_add_drive_opts_va (g, filename, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_add_drive_opts_va (guestfs_h *g,
                           const char *filename,
                           va_list args)
{
  struct guestfs_add_drive_opts_argv optargs_s;
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_ADD_DRIVE_OPTS_READONLY:
      optargs_s.readonly = va_arg (args, int);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_FORMAT:
      optargs_s.format = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_IFACE:
      optargs_s.iface = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_NAME:
      optargs_s.name = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_LABEL:
      optargs_s.label = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_PROTOCOL:
      optargs_s.protocol = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_SERVER:
      optargs_s.server = va_arg (args, char *const *);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_USERNAME:
      optargs_s.username = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_SECRET:
      optargs_s.secret = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_CACHEMODE:
      optargs_s.cachemode = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_DISCARD:
      optargs_s.discard = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_COPYONREAD:
      optargs_s.copyonread = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "add_drive", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "add_drive");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_add_drive_opts_argv (g, filename, optargs);
}

int
guestfs_add_drive (guestfs_h *g,
                   const char *filename)
{
  struct guestfs_add_drive_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;

  return guestfs_add_drive_opts_argv (g, filename, optargs);
}

int
guestfs_add_drive_scratch (guestfs_h *g,
                           int64_t size,
                           ...)
{
  va_list optargs;

  int r;

  va_start (optargs, size);
  r = guestfs_add_drive_scratch_va (g, size, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_add_drive_scratch_va (guestfs_h *g,
                              int64_t size,
                              va_list args)
{
  struct guestfs_add_drive_scratch_argv optargs_s;
  struct guestfs_add_drive_scratch_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_ADD_DRIVE_SCRATCH_NAME:
      optargs_s.name = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DRIVE_SCRATCH_LABEL:
      optargs_s.label = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "add_drive_scratch", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "add_drive_scratch");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_add_drive_scratch_argv (g, size, optargs);
}

int
guestfs_add_libvirt_dom (guestfs_h *g,
                         void * /* really virDomainPtr */ dom,
                         ...)
{
  va_list optargs;

  int r;

  va_start (optargs, dom);
  r = guestfs_add_libvirt_dom_va (g, dom, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_add_libvirt_dom_va (guestfs_h *g,
                            void * /* really virDomainPtr */ dom,
                            va_list args)
{
  struct guestfs_add_libvirt_dom_argv optargs_s;
  struct guestfs_add_libvirt_dom_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_ADD_LIBVIRT_DOM_READONLY:
      optargs_s.readonly = va_arg (args, int);
      break;
    case GUESTFS_ADD_LIBVIRT_DOM_IFACE:
      optargs_s.iface = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_LIBVIRT_DOM_LIVE:
      optargs_s.live = va_arg (args, int);
      break;
    case GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK:
      optargs_s.readonlydisk = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE:
      optargs_s.cachemode = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_LIBVIRT_DOM_DISCARD:
      optargs_s.discard = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_LIBVIRT_DOM_COPYONREAD:
      optargs_s.copyonread = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "add_libvirt_dom", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "add_libvirt_dom");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_add_libvirt_dom_argv (g, dom, optargs);
}

int
guestfs_aug_transform (guestfs_h *g,
                       const char *lens,
                       const char *file,
                       ...)
{
  va_list optargs;

  int r;

  va_start (optargs, file);
  r = guestfs_aug_transform_va (g, lens, file, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_aug_transform_va (guestfs_h *g,
                          const char *lens,
                          const char *file,
                          va_list args)
{
  struct guestfs_aug_transform_argv optargs_s;
  struct guestfs_aug_transform_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_AUG_TRANSFORM_REMOVE:
      optargs_s.remove = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "aug_transform", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "aug_transform");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_aug_transform_argv (g, lens, file, optargs);
}

int
guestfs_btrfs_filesystem_defragment (guestfs_h *g,
                                     const char *path,
                                     ...)
{
  va_list optargs;

  int r;

  va_start (optargs, path);
  r = guestfs_btrfs_filesystem_defragment_va (g, path, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_btrfs_filesystem_defragment_va (guestfs_h *g,
                                        const char *path,
                                        va_list args)
{
  struct guestfs_btrfs_filesystem_defragment_argv optargs_s;
  struct guestfs_btrfs_filesystem_defragment_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH:
      optargs_s.flush = va_arg (args, int);
      break;
    case GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS:
      optargs_s.compress = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "btrfs_filesystem_defragment", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "btrfs_filesystem_defragment");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_btrfs_filesystem_defragment_argv (g, path, optargs);
}

int
guestfs_btrfs_filesystem_resize (guestfs_h *g,
                                 const char *mountpoint,
                                 ...)
{
  va_list optargs;

  int r;

  va_start (optargs, mountpoint);
  r = guestfs_btrfs_filesystem_resize_va (g, mountpoint, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_btrfs_filesystem_resize_va (guestfs_h *g,
                                    const char *mountpoint,
                                    va_list args)
{
  struct guestfs_btrfs_filesystem_resize_argv optargs_s;
  struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE:
      optargs_s.size = va_arg (args, int64_t);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "btrfs_filesystem_resize", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "btrfs_filesystem_resize");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);
}

int
guestfs_btrfs_fsck (guestfs_h *g,
                    const char *device,
                    ...)
{
  va_list optargs;

  int r;

  va_start (optargs, device);
  r = guestfs_btrfs_fsck_va (g, device, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_btrfs_fsck_va (guestfs_h *g,
                       const char *device,
                       va_list args)
{
  struct guestfs_btrfs_fsck_argv optargs_s;
  struct guestfs_btrfs_fsck_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_BTRFS_FSCK_SUPERBLOCK:
      optargs_s.superblock = va_arg (args, int64_t);
      break;
    case GUESTFS_BTRFS_FSCK_REPAIR:
      optargs_s.repair = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "btrfs_fsck", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "btrfs_fsck");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_btrfs_fsck_argv (g, device, optargs);
}

int
guestfs_btrfs_image (guestfs_h *g,
                     char *const *source,
                     const char *image,
                     ...)
{
  va_list optargs;

  int r;

  va_start (optargs, image);
  r = guestfs_btrfs_image_va (g, source, image, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_btrfs_image_va (guestfs_h *g,
                        char *const *source,
                        const char *image,
                        va_list args)
{
  struct guestfs_btrfs_image_argv optargs_s;
  struct guestfs_btrfs_image_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL:
      optargs_s.compresslevel = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "btrfs_image", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "btrfs_image");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_btrfs_image_argv (g, source, image, optargs);
}

int
guestfs_btrfs_subvolume_create_opts (guestfs_h *g,
                                     const char *dest,
                                     ...)
{
  va_list optargs;

  int r;

  va_start (optargs, dest);
  r = guestfs_btrfs_subvolume_create_opts_va (g, dest, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_btrfs_subvolume_create_opts_va (guestfs_h *g,
                                        const char *dest,
                                        va_list args)
{
  struct guestfs_btrfs_subvolume_create_opts_argv optargs_s;
  struct guestfs_btrfs_subvolume_create_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_BTRFS_SUBVOLUME_CREATE_OPTS_QGROUPID:
      optargs_s.qgroupid = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "btrfs_subvolume_create", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "btrfs_subvolume_create");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_btrfs_subvolume_create_opts_argv (g, dest, optargs);
}

int
guestfs_btrfs_subvolume_create (guestfs_h *g,
                                const char *dest)
{
  struct guestfs_btrfs_subvolume_create_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_subvolume_create_opts_argv *optargs = &optargs_s;

  return guestfs_btrfs_subvolume_create_opts_argv (g, dest, optargs);
}

int
guestfs_btrfs_subvolume_snapshot_opts (guestfs_h *g,
                                       const char *source,
                                       const char *dest,
                                       ...)
{
  va_list optargs;

  int r;

  va_start (optargs, dest);
  r = guestfs_btrfs_subvolume_snapshot_opts_va (g, source, dest, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_btrfs_subvolume_snapshot_opts_va (guestfs_h *g,
                                          const char *source,
                                          const char *dest,
                                          va_list args)
{
  struct guestfs_btrfs_subvolume_snapshot_opts_argv optargs_s;
  struct guestfs_btrfs_subvolume_snapshot_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_RO:
      optargs_s.ro = va_arg (args, int);
      break;
    case GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_QGROUPID:
      optargs_s.qgroupid = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "btrfs_subvolume_snapshot", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "btrfs_subvolume_snapshot");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_btrfs_subvolume_snapshot_opts_argv (g, source, dest, optargs);
}

int
guestfs_btrfs_subvolume_snapshot (guestfs_h *g,
                                  const char *source,
                                  const char *dest)
{
  struct guestfs_btrfs_subvolume_snapshot_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_subvolume_snapshot_opts_argv *optargs = &optargs_s;

  return guestfs_btrfs_subvolume_snapshot_opts_argv (g, source, dest, optargs);
}

int
guestfs_compress_device_out (guestfs_h *g,
                             const char *ctype,
                             const char *device,
                             const char *zdevice,
                             ...)
{
  va_list optargs;

  int r;

  va_start (optargs, zdevice);
  r = guestfs_compress_device_out_va (g, ctype, device, zdevice, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_compress_device_out_va (guestfs_h *g,
                                const char *ctype,
                                const char *device,
                                const char *zdevice,
                                va_list args)
{
  struct guestfs_compress_device_out_argv optargs_s;
  struct guestfs_compress_device_out_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_COMPRESS_DEVICE_OUT_LEVEL:
      optargs_s.level = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "compress_device_out", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "compress_device_out");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);
}

int
guestfs_compress_out (guestfs_h *g,
                      const char *ctype,
                      const char *file,
                      const char *zfile,
                      ...)
{
  va_list optargs;

  int r;

  va_start (optargs, zfile);
  r = guestfs_compress_out_va (g, ctype, file, zfile, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_compress_out_va (guestfs_h *g,
                         const char *ctype,
                         const char *file,
                         const char *zfile,
                         va_list args)
{
  struct guestfs_compress_out_argv optargs_s;
  struct guestfs_compress_out_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_COMPRESS_OUT_LEVEL:
      optargs_s.level = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "compress_out", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "compress_out");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_compress_out_argv (g, ctype, file, zfile, optargs);
}

int
guestfs_copy_attributes (guestfs_h *g,
                         const char *src,
                         const char *dest,
                         ...)
{
  va_list optargs;

  int r;

  va_start (optargs, dest);
  r = guestfs_copy_attributes_va (g, src, dest, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_copy_attributes_va (guestfs_h *g,
                            const char *src,
                            const char *dest,
                            va_list args)
{
  struct guestfs_copy_attributes_argv optargs_s;
  struct guestfs_copy_attributes_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_COPY_ATTRIBUTES_ALL:
      optargs_s.all = va_arg (args, int);
      break;
    case GUESTFS_COPY_ATTRIBUTES_MODE:
      optargs_s.mode = va_arg (args, int);
      break;
    case GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES:
      optargs_s.xattributes = va_arg (args, int);
      break;
    case GUESTFS_COPY_ATTRIBUTES_OWNERSHIP:
      optargs_s.ownership = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "copy_attributes", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "copy_attributes");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_copy_attributes_argv (g, src, dest, optargs);
}

int
guestfs_copy_device_to_device (guestfs_h *g,
                               const char *src,
                               const char *dest,
                               ...)
{
  va_list optargs;

  int r;

  va_start (optargs, dest);
  r = guestfs_copy_device_to_device_va (g, src, dest, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_copy_device_to_device_va (guestfs_h *g,
                                  const char *src,
                                  const char *dest,
                                  va_list args)
{
  struct guestfs_copy_device_to_device_argv optargs_s;
  struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET:
      optargs_s.srcoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET:
      optargs_s.destoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE:
      optargs_s.size = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE:
      optargs_s.sparse = va_arg (args, int);
      break;
    case GUESTFS_COPY_DEVICE_TO_DEVICE_APPEND:
      optargs_s.append = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "copy_device_to_device", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "copy_device_to_device");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_copy_device_to_device_argv (g, src, dest, optargs);
}

int
guestfs_copy_device_to_file (guestfs_h *g,
                             const char *src,
                             const char *dest,
                             ...)
{
  va_list optargs;

  int r;

  va_start (optargs, dest);
  r = guestfs_copy_device_to_file_va (g, src, dest, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_copy_device_to_file_va (guestfs_h *g,
                                const char *src,
                                const char *dest,
                                va_list args)
{
  struct guestfs_copy_device_to_file_argv optargs_s;
  struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET:
      optargs_s.srcoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET:
      optargs_s.destoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_DEVICE_TO_FILE_SIZE:
      optargs_s.size = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_DEVICE_TO_FILE_SPARSE:
      optargs_s.sparse = va_arg (args, int);
      break;
    case GUESTFS_COPY_DEVICE_TO_FILE_APPEND:
      optargs_s.append = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "copy_device_to_file", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "copy_device_to_file");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_copy_device_to_file_argv (g, src, dest, optargs);
}

int
guestfs_copy_file_to_device (guestfs_h *g,
                             const char *src,
                             const char *dest,
                             ...)
{
  va_list optargs;

  int r;

  va_start (optargs, dest);
  r = guestfs_copy_file_to_device_va (g, src, dest, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_copy_file_to_device_va (guestfs_h *g,
                                const char *src,
                                const char *dest,
                                va_list args)
{
  struct guestfs_copy_file_to_device_argv optargs_s;
  struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET:
      optargs_s.srcoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET:
      optargs_s.destoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_FILE_TO_DEVICE_SIZE:
      optargs_s.size = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_FILE_TO_DEVICE_SPARSE:
      optargs_s.sparse = va_arg (args, int);
      break;
    case GUESTFS_COPY_FILE_TO_DEVICE_APPEND:
      optargs_s.append = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "copy_file_to_device", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "copy_file_to_device");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_copy_file_to_device_argv (g, src, dest, optargs);
}

int
guestfs_copy_file_to_file (guestfs_h *g,
                           const char *src,
                           const char *dest,
                           ...)
{
  va_list optargs;

  int r;

  va_start (optargs, dest);
  r = guestfs_copy_file_to_file_va (g, src, dest, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_copy_file_to_file_va (guestfs_h *g,
                              const char *src,
                              const char *dest,
                              va_list args)
{
  struct guestfs_copy_file_to_file_argv optargs_s;
  struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET:
      optargs_s.srcoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET:
      optargs_s.destoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_FILE_TO_FILE_SIZE:
      optargs_s.size = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_FILE_TO_FILE_SPARSE:
      optargs_s.sparse = va_arg (args, int);
      break;
    case GUESTFS_COPY_FILE_TO_FILE_APPEND:
      optargs_s.append = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "copy_file_to_file", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "copy_file_to_file");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_copy_file_to_file_argv (g, src, dest, optargs);
}

int
guestfs_cpio_out (guestfs_h *g,
                  const char *directory,
                  const char *cpiofile,
                  ...)
{
  va_list optargs;

  int r;

  va_start (optargs, cpiofile);
  r = guestfs_cpio_out_va (g, directory, cpiofile, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_cpio_out_va (guestfs_h *g,
                     const char *directory,
                     const char *cpiofile,
                     va_list args)
{
  struct guestfs_cpio_out_argv optargs_s;
  struct guestfs_cpio_out_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_CPIO_OUT_FORMAT:
      optargs_s.format = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "cpio_out", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "cpio_out");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_cpio_out_argv (g, directory, cpiofile, optargs);
}

int
guestfs_disk_create (guestfs_h *g,
                     const char *filename,
                     const char *format,
                     int64_t size,
                     ...)
{
  va_list optargs;

  int r;

  va_start (optargs, size);
  r = guestfs_disk_create_va (g, filename, format, size, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_disk_create_va (guestfs_h *g,
                        const char *filename,
                        const char *format,
                        int64_t size,
                        va_list args)
{
  struct guestfs_disk_create_argv optargs_s;
  struct guestfs_disk_create_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_DISK_CREATE_BACKINGFILE:
      optargs_s.backingfile = va_arg (args, const char *);
      break;
    case GUESTFS_DISK_CREATE_BACKINGFORMAT:
      optargs_s.backingformat = va_arg (args, const char *);
      break;
    case GUESTFS_DISK_CREATE_PREALLOCATION:
      optargs_s.preallocation = va_arg (args, const char *);
      break;
    case GUESTFS_DISK_CREATE_COMPAT:
      optargs_s.compat = va_arg (args, const char *);
      break;
    case GUESTFS_DISK_CREATE_CLUSTERSIZE:
      optargs_s.clustersize = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "disk_create", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "disk_create");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_disk_create_argv (g, filename, format, size, optargs);
}

int
guestfs_download_blocks (guestfs_h *g,
                         const char *device,
                         int64_t start,
                         int64_t stop,
                         const char *filename,
                         ...)
{
  va_list optargs;

  int r;

  va_start (optargs, filename);
  r = guestfs_download_blocks_va (g, device, start, stop, filename, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_download_blocks_va (guestfs_h *g,
                            const char *device,
                            int64_t start,
                            int64_t stop,
                            const char *filename,
                            va_list args)
{
  struct guestfs_download_blocks_argv optargs_s;
  struct guestfs_download_blocks_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_DOWNLOAD_BLOCKS_UNALLOCATED:
      optargs_s.unallocated = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "download_blocks", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "download_blocks");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_download_blocks_argv (g, device, start, stop, filename, optargs);
}

int
guestfs_e2fsck (guestfs_h *g,
                const char *device,
                ...)
{
  va_list optargs;

  int r;

  va_start (optargs, device);
  r = guestfs_e2fsck_va (g, device, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_e2fsck_va (guestfs_h *g,
                   const char *device,
                   va_list args)
{
  struct guestfs_e2fsck_argv optargs_s;
  struct guestfs_e2fsck_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_E2FSCK_CORRECT:
      optargs_s.correct = va_arg (args, int);
      break;
    case GUESTFS_E2FSCK_FORCEALL:
      optargs_s.forceall = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "e2fsck", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "e2fsck");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_e2fsck_argv (g, device, optargs);
}

int
guestfs_fstrim (guestfs_h *g,
                const char *mountpoint,
                ...)
{
  va_list optargs;

  int r;

  va_start (optargs, mountpoint);
  r = guestfs_fstrim_va (g, mountpoint, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_fstrim_va (guestfs_h *g,
                   const char *mountpoint,
                   va_list args)
{
  struct guestfs_fstrim_argv optargs_s;
  struct guestfs_fstrim_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_FSTRIM_OFFSET:
      optargs_s.offset = va_arg (args, int64_t);
      break;
    case GUESTFS_FSTRIM_LENGTH:
      optargs_s.length = va_arg (args, int64_t);
      break;
    case GUESTFS_FSTRIM_MINIMUMFREEEXTENT:
      optargs_s.minimumfreeextent = va_arg (args, int64_t);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "fstrim", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "fstrim");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_fstrim_argv (g, mountpoint, optargs);
}

char **
guestfs_glob_expand_opts (guestfs_h *g,
                          const char *pattern,
                          ...)
{
  va_list optargs;

  char **r;

  va_start (optargs, pattern);
  r = guestfs_glob_expand_opts_va (g, pattern, optargs);
  va_end (optargs);

  return r;
}

char **
guestfs_glob_expand_opts_va (guestfs_h *g,
                             const char *pattern,
                             va_list args)
{
  struct guestfs_glob_expand_opts_argv optargs_s;
  struct guestfs_glob_expand_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_GLOB_EXPAND_OPTS_DIRECTORYSLASH:
      optargs_s.directoryslash = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "glob_expand", i);
      return NULL;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "glob_expand");
      return NULL;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_glob_expand_opts_argv (g, pattern, optargs);
}

char **
guestfs_glob_expand (guestfs_h *g,
                     const char *pattern)
{
  struct guestfs_glob_expand_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_glob_expand_opts_argv *optargs = &optargs_s;

  return guestfs_glob_expand_opts_argv (g, pattern, optargs);
}

char **
guestfs_grep_opts (guestfs_h *g,
                   const char *regex,
                   const char *path,
                   ...)
{
  va_list optargs;

  char **r;

  va_start (optargs, path);
  r = guestfs_grep_opts_va (g, regex, path, optargs);
  va_end (optargs);

  return r;
}

char **
guestfs_grep_opts_va (guestfs_h *g,
                      const char *regex,
                      const char *path,
                      va_list args)
{
  struct guestfs_grep_opts_argv optargs_s;
  struct guestfs_grep_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_GREP_OPTS_EXTENDED:
      optargs_s.extended = va_arg (args, int);
      break;
    case GUESTFS_GREP_OPTS_FIXED:
      optargs_s.fixed = va_arg (args, int);
      break;
    case GUESTFS_GREP_OPTS_INSENSITIVE:
      optargs_s.insensitive = va_arg (args, int);
      break;
    case GUESTFS_GREP_OPTS_COMPRESSED:
      optargs_s.compressed = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "grep", i);
      return NULL;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "grep");
      return NULL;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_grep_opts_argv (g, regex, path, optargs);
}

char **
guestfs_grep (guestfs_h *g,
              const char *regex,
              const char *path)
{
  struct guestfs_grep_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_grep_opts_argv *optargs = &optargs_s;

  return guestfs_grep_opts_argv (g, regex, path, optargs);
}

int
guestfs_hivex_open (guestfs_h *g,
                    const char *filename,
                    ...)
{
  va_list optargs;

  int r;

  va_start (optargs, filename);
  r = guestfs_hivex_open_va (g, filename, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_hivex_open_va (guestfs_h *g,
                       const char *filename,
                       va_list args)
{
  struct guestfs_hivex_open_argv optargs_s;
  struct guestfs_hivex_open_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_HIVEX_OPEN_VERBOSE:
      optargs_s.verbose = va_arg (args, int);
      break;
    case GUESTFS_HIVEX_OPEN_DEBUG:
      optargs_s.debug = va_arg (args, int);
      break;
    case GUESTFS_HIVEX_OPEN_WRITE:
      optargs_s.write = va_arg (args, int);
      break;
    case GUESTFS_HIVEX_OPEN_UNSAFE:
      optargs_s.unsafe = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "hivex_open", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "hivex_open");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_hivex_open_argv (g, filename, optargs);
}

char *
guestfs_inspect_get_icon (guestfs_h *g,
                          const char *root,
                          size_t *size_r,
                          ...)
{
  va_list optargs;

  char *r;

  va_start (optargs, size_r);
  r = guestfs_inspect_get_icon_va (g, root, size_r, optargs);
  va_end (optargs);

  return r;
}

char *
guestfs_inspect_get_icon_va (guestfs_h *g,
                             const char *root,
                             size_t *size_r,
                             va_list args)
{
  struct guestfs_inspect_get_icon_argv optargs_s;
  struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_INSPECT_GET_ICON_FAVICON:
      optargs_s.favicon = va_arg (args, int);
      break;
    case GUESTFS_INSPECT_GET_ICON_HIGHQUALITY:
      optargs_s.highquality = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "inspect_get_icon", i);
      return NULL;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "inspect_get_icon");
      return NULL;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_inspect_get_icon_argv (g, root, size_r, optargs);
}

int
guestfs_internal_test (guestfs_h *g,
                       const char *str,
                       const char *optstr,
                       char *const *strlist,
                       int b,
                       int integer,
                       int64_t integer64,
                       const char *filein,
                       const char *fileout,
                       const char *bufferin,
                       size_t bufferin_size,
                       ...)
{
  va_list optargs;

  int r;

  va_start (optargs, bufferin_size);
  r = guestfs_internal_test_va (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_internal_test_va (guestfs_h *g,
                          const char *str,
                          const char *optstr,
                          char *const *strlist,
                          int b,
                          int integer,
                          int64_t integer64,
                          const char *filein,
                          const char *fileout,
                          const char *bufferin,
                          size_t bufferin_size,
                          va_list args)
{
  struct guestfs_internal_test_argv optargs_s;
  struct guestfs_internal_test_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_INTERNAL_TEST_OBOOL:
      optargs_s.obool = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_OINT:
      optargs_s.oint = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_OINT64:
      optargs_s.oint64 = va_arg (args, int64_t);
      break;
    case GUESTFS_INTERNAL_TEST_OSTRING:
      optargs_s.ostring = va_arg (args, const char *);
      break;
    case GUESTFS_INTERNAL_TEST_OSTRINGLIST:
      optargs_s.ostringlist = va_arg (args, char *const *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "internal_test", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "internal_test");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_internal_test_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);
}

int
guestfs_internal_test_63_optargs (guestfs_h *g,
                                  ...)
{
  va_list optargs;

  int r;

  va_start (optargs, g);
  r = guestfs_internal_test_63_optargs_va (g, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_internal_test_63_optargs_va (guestfs_h *g,
                                     va_list args)
{
  struct guestfs_internal_test_63_optargs_argv optargs_s;
  struct guestfs_internal_test_63_optargs_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1:
      optargs_s.opt1 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2:
      optargs_s.opt2 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3:
      optargs_s.opt3 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4:
      optargs_s.opt4 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5:
      optargs_s.opt5 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6:
      optargs_s.opt6 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7:
      optargs_s.opt7 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8:
      optargs_s.opt8 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9:
      optargs_s.opt9 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10:
      optargs_s.opt10 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11:
      optargs_s.opt11 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12:
      optargs_s.opt12 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13:
      optargs_s.opt13 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14:
      optargs_s.opt14 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15:
      optargs_s.opt15 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16:
      optargs_s.opt16 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17:
      optargs_s.opt17 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18:
      optargs_s.opt18 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19:
      optargs_s.opt19 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20:
      optargs_s.opt20 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21:
      optargs_s.opt21 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22:
      optargs_s.opt22 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23:
      optargs_s.opt23 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24:
      optargs_s.opt24 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25:
      optargs_s.opt25 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26:
      optargs_s.opt26 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27:
      optargs_s.opt27 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28:
      optargs_s.opt28 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29:
      optargs_s.opt29 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30:
      optargs_s.opt30 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31:
      optargs_s.opt31 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32:
      optargs_s.opt32 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33:
      optargs_s.opt33 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34:
      optargs_s.opt34 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35:
      optargs_s.opt35 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36:
      optargs_s.opt36 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37:
      optargs_s.opt37 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38:
      optargs_s.opt38 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39:
      optargs_s.opt39 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40:
      optargs_s.opt40 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41:
      optargs_s.opt41 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42:
      optargs_s.opt42 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43:
      optargs_s.opt43 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44:
      optargs_s.opt44 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45:
      optargs_s.opt45 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46:
      optargs_s.opt46 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47:
      optargs_s.opt47 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48:
      optargs_s.opt48 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49:
      optargs_s.opt49 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50:
      optargs_s.opt50 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51:
      optargs_s.opt51 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52:
      optargs_s.opt52 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53:
      optargs_s.opt53 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54:
      optargs_s.opt54 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55:
      optargs_s.opt55 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56:
      optargs_s.opt56 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57:
      optargs_s.opt57 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58:
      optargs_s.opt58 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59:
      optargs_s.opt59 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60:
      optargs_s.opt60 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61:
      optargs_s.opt61 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62:
      optargs_s.opt62 = va_arg (args, int);
      break;
    case GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63:
      optargs_s.opt63 = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "internal_test_63_optargs", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "internal_test_63_optargs");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_internal_test_63_optargs_argv (g, optargs);
}

int
guestfs_internal_test_only_optargs (guestfs_h *g,
                                    ...)
{
  va_list optargs;

  int r;

  va_start (optargs, g);
  r = guestfs_internal_test_only_optargs_va (g, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_internal_test_only_optargs_va (guestfs_h *g,
                                       va_list args)
{
  struct guestfs_internal_test_only_optargs_argv optargs_s;
  struct guestfs_internal_test_only_optargs_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST:
      optargs_s.test = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "internal_test_only_optargs", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "internal_test_only_optargs");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_internal_test_only_optargs_argv (g, optargs);
}

int
guestfs_is_blockdev_opts (guestfs_h *g,
                          const char *path,
                          ...)
{
  va_list optargs;

  int r;

  va_start (optargs, path);
  r = guestfs_is_blockdev_opts_va (g, path, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_is_blockdev_opts_va (guestfs_h *g,
                             const char *path,
                             va_list args)
{
  struct guestfs_is_blockdev_opts_argv optargs_s;
  struct guestfs_is_blockdev_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS:
      optargs_s.followsymlinks = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "is_blockdev", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "is_blockdev");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_is_blockdev_opts_argv (g, path, optargs);
}

int
guestfs_is_blockdev (guestfs_h *g,
                     const char *path)
{
  struct guestfs_is_blockdev_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_blockdev_opts_argv *optargs = &optargs_s;

  return guestfs_is_blockdev_opts_argv (g, path, optargs);
}

int
guestfs_is_chardev_opts (guestfs_h *g,
                         const char *path,
                         ...)
{
  va_list optargs;

  int r;

  va_start (optargs, path);
  r = guestfs_is_chardev_opts_va (g, path, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_is_chardev_opts_va (guestfs_h *g,
                            const char *path,
                            va_list args)
{
  struct guestfs_is_chardev_opts_argv optargs_s;
  struct guestfs_is_chardev_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS:
      optargs_s.followsymlinks = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "is_chardev", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "is_chardev");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_is_chardev_opts_argv (g, path, optargs);
}

int
guestfs_is_chardev (guestfs_h *g,
                    const char *path)
{
  struct guestfs_is_chardev_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_chardev_opts_argv *optargs = &optargs_s;

  return guestfs_is_chardev_opts_argv (g, path, optargs);
}

int
guestfs_is_dir_opts (guestfs_h *g,
                     const char *path,
                     ...)
{
  va_list optargs;

  int r;

  va_start (optargs, path);
  r = guestfs_is_dir_opts_va (g, path, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_is_dir_opts_va (guestfs_h *g,
                        const char *path,
                        va_list args)
{
  struct guestfs_is_dir_opts_argv optargs_s;
  struct guestfs_is_dir_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS:
      optargs_s.followsymlinks = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "is_dir", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "is_dir");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_is_dir_opts_argv (g, path, optargs);
}

int
guestfs_is_dir (guestfs_h *g,
                const char *path)
{
  struct guestfs_is_dir_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_dir_opts_argv *optargs = &optargs_s;

  return guestfs_is_dir_opts_argv (g, path, optargs);
}

int
guestfs_is_fifo_opts (guestfs_h *g,
                      const char *path,
                      ...)
{
  va_list optargs;

  int r;

  va_start (optargs, path);
  r = guestfs_is_fifo_opts_va (g, path, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_is_fifo_opts_va (guestfs_h *g,
                         const char *path,
                         va_list args)
{
  struct guestfs_is_fifo_opts_argv optargs_s;
  struct guestfs_is_fifo_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS:
      optargs_s.followsymlinks = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "is_fifo", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "is_fifo");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_is_fifo_opts_argv (g, path, optargs);
}

int
guestfs_is_fifo (guestfs_h *g,
                 const char *path)
{
  struct guestfs_is_fifo_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_fifo_opts_argv *optargs = &optargs_s;

  return guestfs_is_fifo_opts_argv (g, path, optargs);
}

int
guestfs_is_file_opts (guestfs_h *g,
                      const char *path,
                      ...)
{
  va_list optargs;

  int r;

  va_start (optargs, path);
  r = guestfs_is_file_opts_va (g, path, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_is_file_opts_va (guestfs_h *g,
                         const char *path,
                         va_list args)
{
  struct guestfs_is_file_opts_argv optargs_s;
  struct guestfs_is_file_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS:
      optargs_s.followsymlinks = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "is_file", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "is_file");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_is_file_opts_argv (g, path, optargs);
}

int
guestfs_is_file (guestfs_h *g,
                 const char *path)
{
  struct guestfs_is_file_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_file_opts_argv *optargs = &optargs_s;

  return guestfs_is_file_opts_argv (g, path, optargs);
}

int
guestfs_is_socket_opts (guestfs_h *g,
                        const char *path,
                        ...)
{
  va_list optargs;

  int r;

  va_start (optargs, path);
  r = guestfs_is_socket_opts_va (g, path, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_is_socket_opts_va (guestfs_h *g,
                           const char *path,
                           va_list args)
{
  struct guestfs_is_socket_opts_argv optargs_s;
  struct guestfs_is_socket_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS:
      optargs_s.followsymlinks = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "is_socket", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "is_socket");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_is_socket_opts_argv (g, path, optargs);
}

int
guestfs_is_socket (guestfs_h *g,
                   const char *path)
{
  struct guestfs_is_socket_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_socket_opts_argv *optargs = &optargs_s;

  return guestfs_is_socket_opts_argv (g, path, optargs);
}

int
guestfs_md_create (guestfs_h *g,
                   const char *name,
                   char *const *devices,
                   ...)
{
  va_list optargs;

  int r;

  va_start (optargs, devices);
  r = guestfs_md_create_va (g, name, devices, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_md_create_va (guestfs_h *g,
                      const char *name,
                      char *const *devices,
                      va_list args)
{
  struct guestfs_md_create_argv optargs_s;
  struct guestfs_md_create_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_MD_CREATE_MISSINGBITMAP:
      optargs_s.missingbitmap = va_arg (args, int64_t);
      break;
    case GUESTFS_MD_CREATE_NRDEVICES:
      optargs_s.nrdevices = va_arg (args, int);
      break;
    case GUESTFS_MD_CREATE_SPARE:
      optargs_s.spare = va_arg (args, int);
      break;
    case GUESTFS_MD_CREATE_CHUNK:
      optargs_s.chunk = va_arg (args, int64_t);
      break;
    case GUESTFS_MD_CREATE_LEVEL:
      optargs_s.level = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "md_create", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "md_create");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_md_create_argv (g, name, devices, optargs);
}

int
guestfs_mke2fs (guestfs_h *g,
                const char *device,
                ...)
{
  va_list optargs;

  int r;

  va_start (optargs, device);
  r = guestfs_mke2fs_va (g, device, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_mke2fs_va (guestfs_h *g,
                   const char *device,
                   va_list args)
{
  struct guestfs_mke2fs_argv optargs_s;
  struct guestfs_mke2fs_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_MKE2FS_BLOCKSCOUNT:
      optargs_s.blockscount = va_arg (args, int64_t);
      break;
    case GUESTFS_MKE2FS_BLOCKSIZE:
      optargs_s.blocksize = va_arg (args, int64_t);
      break;
    case GUESTFS_MKE2FS_FRAGSIZE:
      optargs_s.fragsize = va_arg (args, int64_t);
      break;
    case GUESTFS_MKE2FS_BLOCKSPERGROUP:
      optargs_s.blockspergroup = va_arg (args, int64_t);
      break;
    case GUESTFS_MKE2FS_NUMBEROFGROUPS:
      optargs_s.numberofgroups = va_arg (args, int64_t);
      break;
    case GUESTFS_MKE2FS_BYTESPERINODE:
      optargs_s.bytesperinode = va_arg (args, int64_t);
      break;
    case GUESTFS_MKE2FS_INODESIZE:
      optargs_s.inodesize = va_arg (args, int64_t);
      break;
    case GUESTFS_MKE2FS_JOURNALSIZE:
      optargs_s.journalsize = va_arg (args, int64_t);
      break;
    case GUESTFS_MKE2FS_NUMBEROFINODES:
      optargs_s.numberofinodes = va_arg (args, int64_t);
      break;
    case GUESTFS_MKE2FS_STRIDESIZE:
      optargs_s.stridesize = va_arg (args, int64_t);
      break;
    case GUESTFS_MKE2FS_STRIPEWIDTH:
      optargs_s.stripewidth = va_arg (args, int64_t);
      break;
    case GUESTFS_MKE2FS_MAXONLINERESIZE:
      optargs_s.maxonlineresize = va_arg (args, int64_t);
      break;
    case GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE:
      optargs_s.reservedblockspercentage = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_MMPUPDATEINTERVAL:
      optargs_s.mmpupdateinterval = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_JOURNALDEVICE:
      optargs_s.journaldevice = va_arg (args, const char *);
      break;
    case GUESTFS_MKE2FS_LABEL:
      optargs_s.label = va_arg (args, const char *);
      break;
    case GUESTFS_MKE2FS_LASTMOUNTEDDIR:
      optargs_s.lastmounteddir = va_arg (args, const char *);
      break;
    case GUESTFS_MKE2FS_CREATOROS:
      optargs_s.creatoros = va_arg (args, const char *);
      break;
    case GUESTFS_MKE2FS_FSTYPE:
      optargs_s.fstype = va_arg (args, const char *);
      break;
    case GUESTFS_MKE2FS_USAGETYPE:
      optargs_s.usagetype = va_arg (args, const char *);
      break;
    case GUESTFS_MKE2FS_UUID:
      optargs_s.uuid = va_arg (args, const char *);
      break;
    case GUESTFS_MKE2FS_FORCECREATE:
      optargs_s.forcecreate = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_WRITESBANDGROUPONLY:
      optargs_s.writesbandgrouponly = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_LAZYITABLEINIT:
      optargs_s.lazyitableinit = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_LAZYJOURNALINIT:
      optargs_s.lazyjournalinit = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_TESTFS:
      optargs_s.testfs = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_DISCARD:
      optargs_s.discard = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_QUOTATYPE:
      optargs_s.quotatype = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_EXTENT:
      optargs_s.extent = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_FILETYPE:
      optargs_s.filetype = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_FLEXBG:
      optargs_s.flexbg = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_HASJOURNAL:
      optargs_s.hasjournal = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_JOURNALDEV:
      optargs_s.journaldev = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_LARGEFILE:
      optargs_s.largefile = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_QUOTA:
      optargs_s.quota = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_RESIZEINODE:
      optargs_s.resizeinode = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_SPARSESUPER:
      optargs_s.sparsesuper = va_arg (args, int);
      break;
    case GUESTFS_MKE2FS_UNINITBG:
      optargs_s.uninitbg = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "mke2fs", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "mke2fs");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_mke2fs_argv (g, device, optargs);
}

int
guestfs_mkfs_opts (guestfs_h *g,
                   const char *fstype,
                   const char *device,
                   ...)
{
  va_list optargs;

  int r;

  va_start (optargs, device);
  r = guestfs_mkfs_opts_va (g, fstype, device, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_mkfs_opts_va (guestfs_h *g,
                      const char *fstype,
                      const char *device,
                      va_list args)
{
  struct guestfs_mkfs_opts_argv optargs_s;
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_MKFS_OPTS_BLOCKSIZE:
      optargs_s.blocksize = va_arg (args, int);
      break;
    case GUESTFS_MKFS_OPTS_FEATURES:
      optargs_s.features = va_arg (args, const char *);
      break;
    case GUESTFS_MKFS_OPTS_INODE:
      optargs_s.inode = va_arg (args, int);
      break;
    case GUESTFS_MKFS_OPTS_SECTORSIZE:
      optargs_s.sectorsize = va_arg (args, int);
      break;
    case GUESTFS_MKFS_OPTS_LABEL:
      optargs_s.label = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "mkfs", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "mkfs");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_mkfs_opts_argv (g, fstype, device, optargs);
}

int
guestfs_mkfs (guestfs_h *g,
              const char *fstype,
              const char *device)
{
  struct guestfs_mkfs_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;

  return guestfs_mkfs_opts_argv (g, fstype, device, optargs);
}

int
guestfs_mkfs_btrfs (guestfs_h *g,
                    char *const *devices,
                    ...)
{
  va_list optargs;

  int r;

  va_start (optargs, devices);
  r = guestfs_mkfs_btrfs_va (g, devices, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_mkfs_btrfs_va (guestfs_h *g,
                       char *const *devices,
                       va_list args)
{
  struct guestfs_mkfs_btrfs_argv optargs_s;
  struct guestfs_mkfs_btrfs_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_MKFS_BTRFS_ALLOCSTART:
      optargs_s.allocstart = va_arg (args, int64_t);
      break;
    case GUESTFS_MKFS_BTRFS_BYTECOUNT:
      optargs_s.bytecount = va_arg (args, int64_t);
      break;
    case GUESTFS_MKFS_BTRFS_DATATYPE:
      optargs_s.datatype = va_arg (args, const char *);
      break;
    case GUESTFS_MKFS_BTRFS_LEAFSIZE:
      optargs_s.leafsize = va_arg (args, int);
      break;
    case GUESTFS_MKFS_BTRFS_LABEL:
      optargs_s.label = va_arg (args, const char *);
      break;
    case GUESTFS_MKFS_BTRFS_METADATA:
      optargs_s.metadata = va_arg (args, const char *);
      break;
    case GUESTFS_MKFS_BTRFS_NODESIZE:
      optargs_s.nodesize = va_arg (args, int);
      break;
    case GUESTFS_MKFS_BTRFS_SECTORSIZE:
      optargs_s.sectorsize = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "mkfs_btrfs", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "mkfs_btrfs");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_mkfs_btrfs_argv (g, devices, optargs);
}

int
guestfs_mksquashfs (guestfs_h *g,
                    const char *path,
                    const char *filename,
                    ...)
{
  va_list optargs;

  int r;

  va_start (optargs, filename);
  r = guestfs_mksquashfs_va (g, path, filename, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_mksquashfs_va (guestfs_h *g,
                       const char *path,
                       const char *filename,
                       va_list args)
{
  struct guestfs_mksquashfs_argv optargs_s;
  struct guestfs_mksquashfs_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_MKSQUASHFS_COMPRESS:
      optargs_s.compress = va_arg (args, const char *);
      break;
    case GUESTFS_MKSQUASHFS_EXCLUDES:
      optargs_s.excludes = va_arg (args, char *const *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "mksquashfs", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "mksquashfs");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_mksquashfs_argv (g, path, filename, optargs);
}

int
guestfs_mkswap_opts (guestfs_h *g,
                     const char *device,
                     ...)
{
  va_list optargs;

  int r;

  va_start (optargs, device);
  r = guestfs_mkswap_opts_va (g, device, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_mkswap_opts_va (guestfs_h *g,
                        const char *device,
                        va_list args)
{
  struct guestfs_mkswap_opts_argv optargs_s;
  struct guestfs_mkswap_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_MKSWAP_OPTS_LABEL:
      optargs_s.label = va_arg (args, const char *);
      break;
    case GUESTFS_MKSWAP_OPTS_UUID:
      optargs_s.uuid = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "mkswap", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "mkswap");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_mkswap_opts_argv (g, device, optargs);
}

int
guestfs_mkswap (guestfs_h *g,
                const char *device)
{
  struct guestfs_mkswap_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkswap_opts_argv *optargs = &optargs_s;

  return guestfs_mkswap_opts_argv (g, device, optargs);
}

char *
guestfs_mktemp (guestfs_h *g,
                const char *tmpl,
                ...)
{
  va_list optargs;

  char *r;

  va_start (optargs, tmpl);
  r = guestfs_mktemp_va (g, tmpl, optargs);
  va_end (optargs);

  return r;
}

char *
guestfs_mktemp_va (guestfs_h *g,
                   const char *tmpl,
                   va_list args)
{
  struct guestfs_mktemp_argv optargs_s;
  struct guestfs_mktemp_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_MKTEMP_SUFFIX:
      optargs_s.suffix = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "mktemp", i);
      return NULL;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "mktemp");
      return NULL;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_mktemp_argv (g, tmpl, optargs);
}

int
guestfs_mount_9p (guestfs_h *g,
                  const char *mounttag,
                  const char *mountpoint,
                  ...)
{
  va_list optargs;

  int r;

  va_start (optargs, mountpoint);
  r = guestfs_mount_9p_va (g, mounttag, mountpoint, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_mount_9p_va (guestfs_h *g,
                     const char *mounttag,
                     const char *mountpoint,
                     va_list args)
{
  struct guestfs_mount_9p_argv optargs_s;
  struct guestfs_mount_9p_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_MOUNT_9P_OPTIONS:
      optargs_s.options = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "mount_9p", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "mount_9p");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);
}

int
guestfs_mount_local (guestfs_h *g,
                     const char *localmountpoint,
                     ...)
{
  va_list optargs;

  int r;

  va_start (optargs, localmountpoint);
  r = guestfs_mount_local_va (g, localmountpoint, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_mount_local_va (guestfs_h *g,
                        const char *localmountpoint,
                        va_list args)
{
  struct guestfs_mount_local_argv optargs_s;
  struct guestfs_mount_local_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_MOUNT_LOCAL_READONLY:
      optargs_s.readonly = va_arg (args, int);
      break;
    case GUESTFS_MOUNT_LOCAL_OPTIONS:
      optargs_s.options = va_arg (args, const char *);
      break;
    case GUESTFS_MOUNT_LOCAL_CACHETIMEOUT:
      optargs_s.cachetimeout = va_arg (args, int);
      break;
    case GUESTFS_MOUNT_LOCAL_DEBUGCALLS:
      optargs_s.debugcalls = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "mount_local", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "mount_local");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_mount_local_argv (g, localmountpoint, optargs);
}

int
guestfs_ntfsclone_out (guestfs_h *g,
                       const char *device,
                       const char *backupfile,
                       ...)
{
  va_list optargs;

  int r;

  va_start (optargs, backupfile);
  r = guestfs_ntfsclone_out_va (g, device, backupfile, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_ntfsclone_out_va (guestfs_h *g,
                          const char *device,
                          const char *backupfile,
                          va_list args)
{
  struct guestfs_ntfsclone_out_argv optargs_s;
  struct guestfs_ntfsclone_out_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_NTFSCLONE_OUT_METADATAONLY:
      optargs_s.metadataonly = va_arg (args, int);
      break;
    case GUESTFS_NTFSCLONE_OUT_RESCUE:
      optargs_s.rescue = va_arg (args, int);
      break;
    case GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK:
      optargs_s.ignorefscheck = va_arg (args, int);
      break;
    case GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS:
      optargs_s.preservetimestamps = va_arg (args, int);
      break;
    case GUESTFS_NTFSCLONE_OUT_FORCE:
      optargs_s.force = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "ntfsclone_out", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "ntfsclone_out");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_ntfsclone_out_argv (g, device, backupfile, optargs);
}

int
guestfs_ntfsfix (guestfs_h *g,
                 const char *device,
                 ...)
{
  va_list optargs;

  int r;

  va_start (optargs, device);
  r = guestfs_ntfsfix_va (g, device, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_ntfsfix_va (guestfs_h *g,
                    const char *device,
                    va_list args)
{
  struct guestfs_ntfsfix_argv optargs_s;
  struct guestfs_ntfsfix_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_NTFSFIX_CLEARBADSECTORS:
      optargs_s.clearbadsectors = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "ntfsfix", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "ntfsfix");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_ntfsfix_argv (g, device, optargs);
}

int
guestfs_ntfsresize_opts (guestfs_h *g,
                         const char *device,
                         ...)
{
  va_list optargs;

  int r;

  va_start (optargs, device);
  r = guestfs_ntfsresize_opts_va (g, device, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_ntfsresize_opts_va (guestfs_h *g,
                            const char *device,
                            va_list args)
{
  struct guestfs_ntfsresize_opts_argv optargs_s;
  struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_NTFSRESIZE_OPTS_SIZE:
      optargs_s.size = va_arg (args, int64_t);
      break;
    case GUESTFS_NTFSRESIZE_OPTS_FORCE:
      optargs_s.force = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "ntfsresize", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "ntfsresize");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_ntfsresize_opts_argv (g, device, optargs);
}

int
guestfs_ntfsresize (guestfs_h *g,
                    const char *device)
{
  struct guestfs_ntfsresize_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;

  return guestfs_ntfsresize_opts_argv (g, device, optargs);
}

int
guestfs_remount (guestfs_h *g,
                 const char *mountpoint,
                 ...)
{
  va_list optargs;

  int r;

  va_start (optargs, mountpoint);
  r = guestfs_remount_va (g, mountpoint, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_remount_va (guestfs_h *g,
                    const char *mountpoint,
                    va_list args)
{
  struct guestfs_remount_argv optargs_s;
  struct guestfs_remount_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_REMOUNT_RW:
      optargs_s.rw = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "remount", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "remount");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_remount_argv (g, mountpoint, optargs);
}

int
guestfs_rsync (guestfs_h *g,
               const char *src,
               const char *dest,
               ...)
{
  va_list optargs;

  int r;

  va_start (optargs, dest);
  r = guestfs_rsync_va (g, src, dest, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_rsync_va (guestfs_h *g,
                  const char *src,
                  const char *dest,
                  va_list args)
{
  struct guestfs_rsync_argv optargs_s;
  struct guestfs_rsync_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_RSYNC_ARCHIVE:
      optargs_s.archive = va_arg (args, int);
      break;
    case GUESTFS_RSYNC_DELETEDEST:
      optargs_s.deletedest = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "rsync", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "rsync");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_rsync_argv (g, src, dest, optargs);
}

int
guestfs_rsync_in (guestfs_h *g,
                  const char *remote,
                  const char *dest,
                  ...)
{
  va_list optargs;

  int r;

  va_start (optargs, dest);
  r = guestfs_rsync_in_va (g, remote, dest, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_rsync_in_va (guestfs_h *g,
                     const char *remote,
                     const char *dest,
                     va_list args)
{
  struct guestfs_rsync_in_argv optargs_s;
  struct guestfs_rsync_in_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_RSYNC_IN_ARCHIVE:
      optargs_s.archive = va_arg (args, int);
      break;
    case GUESTFS_RSYNC_IN_DELETEDEST:
      optargs_s.deletedest = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "rsync_in", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "rsync_in");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_rsync_in_argv (g, remote, dest, optargs);
}

int
guestfs_rsync_out (guestfs_h *g,
                   const char *src,
                   const char *remote,
                   ...)
{
  va_list optargs;

  int r;

  va_start (optargs, remote);
  r = guestfs_rsync_out_va (g, src, remote, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_rsync_out_va (guestfs_h *g,
                      const char *src,
                      const char *remote,
                      va_list args)
{
  struct guestfs_rsync_out_argv optargs_s;
  struct guestfs_rsync_out_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_RSYNC_OUT_ARCHIVE:
      optargs_s.archive = va_arg (args, int);
      break;
    case GUESTFS_RSYNC_OUT_DELETEDEST:
      optargs_s.deletedest = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "rsync_out", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "rsync_out");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_rsync_out_argv (g, src, remote, optargs);
}

int
guestfs_selinux_relabel (guestfs_h *g,
                         const char *specfile,
                         const char *path,
                         ...)
{
  va_list optargs;

  int r;

  va_start (optargs, path);
  r = guestfs_selinux_relabel_va (g, specfile, path, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_selinux_relabel_va (guestfs_h *g,
                            const char *specfile,
                            const char *path,
                            va_list args)
{
  struct guestfs_selinux_relabel_argv optargs_s;
  struct guestfs_selinux_relabel_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_SELINUX_RELABEL_FORCE:
      optargs_s.force = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "selinux_relabel", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "selinux_relabel");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_selinux_relabel_argv (g, specfile, path, optargs);
}

int
guestfs_set_e2attrs (guestfs_h *g,
                     const char *file,
                     const char *attrs,
                     ...)
{
  va_list optargs;

  int r;

  va_start (optargs, attrs);
  r = guestfs_set_e2attrs_va (g, file, attrs, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_set_e2attrs_va (guestfs_h *g,
                        const char *file,
                        const char *attrs,
                        va_list args)
{
  struct guestfs_set_e2attrs_argv optargs_s;
  struct guestfs_set_e2attrs_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_SET_E2ATTRS_CLEAR:
      optargs_s.clear = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "set_e2attrs", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "set_e2attrs");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_set_e2attrs_argv (g, file, attrs, optargs);
}

int
guestfs_syslinux (guestfs_h *g,
                  const char *device,
                  ...)
{
  va_list optargs;

  int r;

  va_start (optargs, device);
  r = guestfs_syslinux_va (g, device, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_syslinux_va (guestfs_h *g,
                     const char *device,
                     va_list args)
{
  struct guestfs_syslinux_argv optargs_s;
  struct guestfs_syslinux_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_SYSLINUX_DIRECTORY:
      optargs_s.directory = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "syslinux", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "syslinux");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_syslinux_argv (g, device, optargs);
}

int
guestfs_tar_in_opts (guestfs_h *g,
                     const char *tarfile,
                     const char *directory,
                     ...)
{
  va_list optargs;

  int r;

  va_start (optargs, directory);
  r = guestfs_tar_in_opts_va (g, tarfile, directory, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_tar_in_opts_va (guestfs_h *g,
                        const char *tarfile,
                        const char *directory,
                        va_list args)
{
  struct guestfs_tar_in_opts_argv optargs_s;
  struct guestfs_tar_in_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_TAR_IN_OPTS_COMPRESS:
      optargs_s.compress = va_arg (args, const char *);
      break;
    case GUESTFS_TAR_IN_OPTS_XATTRS:
      optargs_s.xattrs = va_arg (args, int);
      break;
    case GUESTFS_TAR_IN_OPTS_SELINUX:
      optargs_s.selinux = va_arg (args, int);
      break;
    case GUESTFS_TAR_IN_OPTS_ACLS:
      optargs_s.acls = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "tar_in", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "tar_in");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_tar_in_opts_argv (g, tarfile, directory, optargs);
}

int
guestfs_tar_in (guestfs_h *g,
                const char *tarfile,
                const char *directory)
{
  struct guestfs_tar_in_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_in_opts_argv *optargs = &optargs_s;

  return guestfs_tar_in_opts_argv (g, tarfile, directory, optargs);
}

int
guestfs_tar_out_opts (guestfs_h *g,
                      const char *directory,
                      const char *tarfile,
                      ...)
{
  va_list optargs;

  int r;

  va_start (optargs, tarfile);
  r = guestfs_tar_out_opts_va (g, directory, tarfile, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_tar_out_opts_va (guestfs_h *g,
                         const char *directory,
                         const char *tarfile,
                         va_list args)
{
  struct guestfs_tar_out_opts_argv optargs_s;
  struct guestfs_tar_out_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_TAR_OUT_OPTS_COMPRESS:
      optargs_s.compress = va_arg (args, const char *);
      break;
    case GUESTFS_TAR_OUT_OPTS_NUMERICOWNER:
      optargs_s.numericowner = va_arg (args, int);
      break;
    case GUESTFS_TAR_OUT_OPTS_EXCLUDES:
      optargs_s.excludes = va_arg (args, char *const *);
      break;
    case GUESTFS_TAR_OUT_OPTS_XATTRS:
      optargs_s.xattrs = va_arg (args, int);
      break;
    case GUESTFS_TAR_OUT_OPTS_SELINUX:
      optargs_s.selinux = va_arg (args, int);
      break;
    case GUESTFS_TAR_OUT_OPTS_ACLS:
      optargs_s.acls = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "tar_out", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "tar_out");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_tar_out_opts_argv (g, directory, tarfile, optargs);
}

int
guestfs_tar_out (guestfs_h *g,
                 const char *directory,
                 const char *tarfile)
{
  struct guestfs_tar_out_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_out_opts_argv *optargs = &optargs_s;

  return guestfs_tar_out_opts_argv (g, directory, tarfile, optargs);
}

int
guestfs_tune2fs (guestfs_h *g,
                 const char *device,
                 ...)
{
  va_list optargs;

  int r;

  va_start (optargs, device);
  r = guestfs_tune2fs_va (g, device, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_tune2fs_va (guestfs_h *g,
                    const char *device,
                    va_list args)
{
  struct guestfs_tune2fs_argv optargs_s;
  struct guestfs_tune2fs_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_TUNE2FS_FORCE:
      optargs_s.force = va_arg (args, int);
      break;
    case GUESTFS_TUNE2FS_MAXMOUNTCOUNT:
      optargs_s.maxmountcount = va_arg (args, int);
      break;
    case GUESTFS_TUNE2FS_MOUNTCOUNT:
      optargs_s.mountcount = va_arg (args, int);
      break;
    case GUESTFS_TUNE2FS_ERRORBEHAVIOR:
      optargs_s.errorbehavior = va_arg (args, const char *);
      break;
    case GUESTFS_TUNE2FS_GROUP:
      optargs_s.group = va_arg (args, int64_t);
      break;
    case GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS:
      optargs_s.intervalbetweenchecks = va_arg (args, int);
      break;
    case GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE:
      optargs_s.reservedblockspercentage = va_arg (args, int);
      break;
    case GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY:
      optargs_s.lastmounteddirectory = va_arg (args, const char *);
      break;
    case GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT:
      optargs_s.reservedblockscount = va_arg (args, int64_t);
      break;
    case GUESTFS_TUNE2FS_USER:
      optargs_s.user = va_arg (args, int64_t);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "tune2fs", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "tune2fs");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_tune2fs_argv (g, device, optargs);
}

int
guestfs_umount_opts (guestfs_h *g,
                     const char *pathordevice,
                     ...)
{
  va_list optargs;

  int r;

  va_start (optargs, pathordevice);
  r = guestfs_umount_opts_va (g, pathordevice, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_umount_opts_va (guestfs_h *g,
                        const char *pathordevice,
                        va_list args)
{
  struct guestfs_umount_opts_argv optargs_s;
  struct guestfs_umount_opts_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_UMOUNT_OPTS_FORCE:
      optargs_s.force = va_arg (args, int);
      break;
    case GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT:
      optargs_s.lazyunmount = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "umount", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "umount");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_umount_opts_argv (g, pathordevice, optargs);
}

int
guestfs_umount (guestfs_h *g,
                const char *pathordevice)
{
  struct guestfs_umount_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_umount_opts_argv *optargs = &optargs_s;

  return guestfs_umount_opts_argv (g, pathordevice, optargs);
}

int
guestfs_umount_local (guestfs_h *g,
                      ...)
{
  va_list optargs;

  int r;

  va_start (optargs, g);
  r = guestfs_umount_local_va (g, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_umount_local_va (guestfs_h *g,
                         va_list args)
{
  struct guestfs_umount_local_argv optargs_s;
  struct guestfs_umount_local_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_UMOUNT_LOCAL_RETRY:
      optargs_s.retry = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "umount_local", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "umount_local");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_umount_local_argv (g, optargs);
}

int
guestfs_xfs_admin (guestfs_h *g,
                   const char *device,
                   ...)
{
  va_list optargs;

  int r;

  va_start (optargs, device);
  r = guestfs_xfs_admin_va (g, device, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_xfs_admin_va (guestfs_h *g,
                      const char *device,
                      va_list args)
{
  struct guestfs_xfs_admin_argv optargs_s;
  struct guestfs_xfs_admin_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_XFS_ADMIN_EXTUNWRITTEN:
      optargs_s.extunwritten = va_arg (args, int);
      break;
    case GUESTFS_XFS_ADMIN_IMGFILE:
      optargs_s.imgfile = va_arg (args, int);
      break;
    case GUESTFS_XFS_ADMIN_V2LOG:
      optargs_s.v2log = va_arg (args, int);
      break;
    case GUESTFS_XFS_ADMIN_PROJID32BIT:
      optargs_s.projid32bit = va_arg (args, int);
      break;
    case GUESTFS_XFS_ADMIN_LAZYCOUNTER:
      optargs_s.lazycounter = va_arg (args, int);
      break;
    case GUESTFS_XFS_ADMIN_LABEL:
      optargs_s.label = va_arg (args, const char *);
      break;
    case GUESTFS_XFS_ADMIN_UUID:
      optargs_s.uuid = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "xfs_admin", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "xfs_admin");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_xfs_admin_argv (g, device, optargs);
}

int
guestfs_xfs_growfs (guestfs_h *g,
                    const char *path,
                    ...)
{
  va_list optargs;

  int r;

  va_start (optargs, path);
  r = guestfs_xfs_growfs_va (g, path, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_xfs_growfs_va (guestfs_h *g,
                       const char *path,
                       va_list args)
{
  struct guestfs_xfs_growfs_argv optargs_s;
  struct guestfs_xfs_growfs_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_XFS_GROWFS_DATASEC:
      optargs_s.datasec = va_arg (args, int);
      break;
    case GUESTFS_XFS_GROWFS_LOGSEC:
      optargs_s.logsec = va_arg (args, int);
      break;
    case GUESTFS_XFS_GROWFS_RTSEC:
      optargs_s.rtsec = va_arg (args, int);
      break;
    case GUESTFS_XFS_GROWFS_DATASIZE:
      optargs_s.datasize = va_arg (args, int64_t);
      break;
    case GUESTFS_XFS_GROWFS_LOGSIZE:
      optargs_s.logsize = va_arg (args, int64_t);
      break;
    case GUESTFS_XFS_GROWFS_RTSIZE:
      optargs_s.rtsize = va_arg (args, int64_t);
      break;
    case GUESTFS_XFS_GROWFS_RTEXTSIZE:
      optargs_s.rtextsize = va_arg (args, int64_t);
      break;
    case GUESTFS_XFS_GROWFS_MAXPCT:
      optargs_s.maxpct = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "xfs_growfs", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "xfs_growfs");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_xfs_growfs_argv (g, path, optargs);
}

int
guestfs_xfs_repair (guestfs_h *g,
                    const char *device,
                    ...)
{
  va_list optargs;

  int r;

  va_start (optargs, device);
  r = guestfs_xfs_repair_va (g, device, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_xfs_repair_va (guestfs_h *g,
                       const char *device,
                       va_list args)
{
  struct guestfs_xfs_repair_argv optargs_s;
  struct guestfs_xfs_repair_argv *optargs = &optargs_s;
  int i;
  uint64_t i_mask;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_XFS_REPAIR_FORCELOGZERO:
      optargs_s.forcelogzero = va_arg (args, int);
      break;
    case GUESTFS_XFS_REPAIR_NOMODIFY:
      optargs_s.nomodify = va_arg (args, int);
      break;
    case GUESTFS_XFS_REPAIR_NOPREFETCH:
      optargs_s.noprefetch = va_arg (args, int);
      break;
    case GUESTFS_XFS_REPAIR_FORCEGEOMETRY:
      optargs_s.forcegeometry = va_arg (args, int);
      break;
    case GUESTFS_XFS_REPAIR_MAXMEM:
      optargs_s.maxmem = va_arg (args, int64_t);
      break;
    case GUESTFS_XFS_REPAIR_IHASHSIZE:
      optargs_s.ihashsize = va_arg (args, int64_t);
      break;
    case GUESTFS_XFS_REPAIR_BHASHSIZE:
      optargs_s.bhashsize = va_arg (args, int64_t);
      break;
    case GUESTFS_XFS_REPAIR_AGSTRIDE:
      optargs_s.agstride = va_arg (args, int64_t);
      break;
    case GUESTFS_XFS_REPAIR_LOGDEV:
      optargs_s.logdev = va_arg (args, const char *);
      break;
    case GUESTFS_XFS_REPAIR_RTDEV:
      optargs_s.rtdev = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "xfs_repair", i);
      return -1;
    }

    i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "xfs_repair");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_xfs_repair_argv (g, device, optargs);
}

