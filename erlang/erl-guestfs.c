/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <erl_interface.h>
#include <ei.h>

#include "guestfs.h"

extern guestfs_h *g;

extern ETERM *dispatch (ETERM *message);
extern int atom_equals (ETERM *atom, const char *name);
extern ETERM *make_error (const char *funname);
extern ETERM *unknown_optarg (const char *funname, ETERM *optargname);
extern ETERM *unknown_function (ETERM *fun);
extern ETERM *make_string_list (char **r);
extern ETERM *make_table (char **r);
extern ETERM *make_bool (int r);
extern char **get_string_list (ETERM *term);
extern int get_bool (ETERM *term);
extern void free_strings (char **r);

#define ARG(i) (ERL_TUPLE_ELEMENT(message,(i)+1))

static ETERM *
make_int_bool (const struct guestfs_int_bool *int_bool)
{
  ETERM *t[2];

  t[0] = erl_mk_int (int_bool->i);
  t[1] = erl_mk_int (int_bool->b);

  return erl_mk_list (t, 2);
}

static ETERM *
make_lvm_pv (const struct guestfs_lvm_pv *lvm_pv)
{
  ETERM *t[14];

  t[0] = erl_mk_string (lvm_pv->pv_name);
  t[1] = erl_mk_estring (lvm_pv->pv_uuid, 32);
  t[2] = erl_mk_string (lvm_pv->pv_fmt);
  t[3] = erl_mk_longlong (lvm_pv->pv_size);
  t[4] = erl_mk_longlong (lvm_pv->dev_size);
  t[5] = erl_mk_longlong (lvm_pv->pv_free);
  t[6] = erl_mk_longlong (lvm_pv->pv_used);
  t[7] = erl_mk_string (lvm_pv->pv_attr);
  t[8] = erl_mk_longlong (lvm_pv->pv_pe_count);
  t[9] = erl_mk_longlong (lvm_pv->pv_pe_alloc_count);
  t[10] = erl_mk_string (lvm_pv->pv_tags);
  t[11] = erl_mk_longlong (lvm_pv->pe_start);
  t[12] = erl_mk_longlong (lvm_pv->pv_mda_count);
  t[13] = erl_mk_longlong (lvm_pv->pv_mda_free);

  return erl_mk_list (t, 14);
}

static ETERM *
make_lvm_vg (const struct guestfs_lvm_vg *lvm_vg)
{
  ETERM *t[19];

  t[0] = erl_mk_string (lvm_vg->vg_name);
  t[1] = erl_mk_estring (lvm_vg->vg_uuid, 32);
  t[2] = erl_mk_string (lvm_vg->vg_fmt);
  t[3] = erl_mk_string (lvm_vg->vg_attr);
  t[4] = erl_mk_longlong (lvm_vg->vg_size);
  t[5] = erl_mk_longlong (lvm_vg->vg_free);
  t[6] = erl_mk_string (lvm_vg->vg_sysid);
  t[7] = erl_mk_longlong (lvm_vg->vg_extent_size);
  t[8] = erl_mk_longlong (lvm_vg->vg_extent_count);
  t[9] = erl_mk_longlong (lvm_vg->vg_free_count);
  t[10] = erl_mk_longlong (lvm_vg->max_lv);
  t[11] = erl_mk_longlong (lvm_vg->max_pv);
  t[12] = erl_mk_longlong (lvm_vg->pv_count);
  t[13] = erl_mk_longlong (lvm_vg->lv_count);
  t[14] = erl_mk_longlong (lvm_vg->snap_count);
  t[15] = erl_mk_longlong (lvm_vg->vg_seqno);
  t[16] = erl_mk_string (lvm_vg->vg_tags);
  t[17] = erl_mk_longlong (lvm_vg->vg_mda_count);
  t[18] = erl_mk_longlong (lvm_vg->vg_mda_free);

  return erl_mk_list (t, 19);
}

static ETERM *
make_lvm_lv (const struct guestfs_lvm_lv *lvm_lv)
{
  ETERM *t[16];

  t[0] = erl_mk_string (lvm_lv->lv_name);
  t[1] = erl_mk_estring (lvm_lv->lv_uuid, 32);
  t[2] = erl_mk_string (lvm_lv->lv_attr);
  t[3] = erl_mk_longlong (lvm_lv->lv_major);
  t[4] = erl_mk_longlong (lvm_lv->lv_minor);
  t[5] = erl_mk_longlong (lvm_lv->lv_kernel_major);
  t[6] = erl_mk_longlong (lvm_lv->lv_kernel_minor);
  t[7] = erl_mk_longlong (lvm_lv->lv_size);
  t[8] = erl_mk_longlong (lvm_lv->seg_count);
  t[9] = erl_mk_string (lvm_lv->origin);
  if (lvm_lv->snap_percent >= 0)
    t[10] = erl_mk_float (lvm_lv->snap_percent);
  else
    t[10] = erl_mk_atom ("undefined");
  if (lvm_lv->copy_percent >= 0)
    t[11] = erl_mk_float (lvm_lv->copy_percent);
  else
    t[11] = erl_mk_atom ("undefined");
  t[12] = erl_mk_string (lvm_lv->move_pv);
  t[13] = erl_mk_string (lvm_lv->lv_tags);
  t[14] = erl_mk_string (lvm_lv->mirror_log);
  t[15] = erl_mk_string (lvm_lv->modules);

  return erl_mk_list (t, 16);
}

static ETERM *
make_stat (const struct guestfs_stat *stat)
{
  ETERM *t[13];

  t[0] = erl_mk_longlong (stat->dev);
  t[1] = erl_mk_longlong (stat->ino);
  t[2] = erl_mk_longlong (stat->mode);
  t[3] = erl_mk_longlong (stat->nlink);
  t[4] = erl_mk_longlong (stat->uid);
  t[5] = erl_mk_longlong (stat->gid);
  t[6] = erl_mk_longlong (stat->rdev);
  t[7] = erl_mk_longlong (stat->size);
  t[8] = erl_mk_longlong (stat->blksize);
  t[9] = erl_mk_longlong (stat->blocks);
  t[10] = erl_mk_longlong (stat->atime);
  t[11] = erl_mk_longlong (stat->mtime);
  t[12] = erl_mk_longlong (stat->ctime);

  return erl_mk_list (t, 13);
}

static ETERM *
make_statvfs (const struct guestfs_statvfs *statvfs)
{
  ETERM *t[11];

  t[0] = erl_mk_longlong (statvfs->bsize);
  t[1] = erl_mk_longlong (statvfs->frsize);
  t[2] = erl_mk_longlong (statvfs->blocks);
  t[3] = erl_mk_longlong (statvfs->bfree);
  t[4] = erl_mk_longlong (statvfs->bavail);
  t[5] = erl_mk_longlong (statvfs->files);
  t[6] = erl_mk_longlong (statvfs->ffree);
  t[7] = erl_mk_longlong (statvfs->favail);
  t[8] = erl_mk_longlong (statvfs->fsid);
  t[9] = erl_mk_longlong (statvfs->flag);
  t[10] = erl_mk_longlong (statvfs->namemax);

  return erl_mk_list (t, 11);
}

static ETERM *
make_dirent (const struct guestfs_dirent *dirent)
{
  ETERM *t[3];

  t[0] = erl_mk_longlong (dirent->ino);
  t[1] = erl_mk_int (dirent->ftyp);
  t[2] = erl_mk_string (dirent->name);

  return erl_mk_list (t, 3);
}

static ETERM *
make_version (const struct guestfs_version *version)
{
  ETERM *t[4];

  t[0] = erl_mk_longlong (version->major);
  t[1] = erl_mk_longlong (version->minor);
  t[2] = erl_mk_longlong (version->release);
  t[3] = erl_mk_string (version->extra);

  return erl_mk_list (t, 4);
}

static ETERM *
make_xattr (const struct guestfs_xattr *xattr)
{
  ETERM *t[2];

  t[0] = erl_mk_string (xattr->attrname);
  t[1] = erl_mk_estring (xattr->attrval, xattr->attrval_len);

  return erl_mk_list (t, 2);
}

static ETERM *
make_inotify_event (const struct guestfs_inotify_event *inotify_event)
{
  ETERM *t[4];

  t[0] = erl_mk_longlong (inotify_event->in_wd);
  t[1] = erl_mk_int (inotify_event->in_mask);
  t[2] = erl_mk_int (inotify_event->in_cookie);
  t[3] = erl_mk_string (inotify_event->in_name);

  return erl_mk_list (t, 4);
}

static ETERM *
make_partition (const struct guestfs_partition *partition)
{
  ETERM *t[4];

  t[0] = erl_mk_int (partition->part_num);
  t[1] = erl_mk_longlong (partition->part_start);
  t[2] = erl_mk_longlong (partition->part_end);
  t[3] = erl_mk_longlong (partition->part_size);

  return erl_mk_list (t, 4);
}

static ETERM *
make_application (const struct guestfs_application *application)
{
  ETERM *t[12];

  t[0] = erl_mk_string (application->app_name);
  t[1] = erl_mk_string (application->app_display_name);
  t[2] = erl_mk_int (application->app_epoch);
  t[3] = erl_mk_string (application->app_version);
  t[4] = erl_mk_string (application->app_release);
  t[5] = erl_mk_string (application->app_install_path);
  t[6] = erl_mk_string (application->app_trans_path);
  t[7] = erl_mk_string (application->app_publisher);
  t[8] = erl_mk_string (application->app_url);
  t[9] = erl_mk_string (application->app_source_package);
  t[10] = erl_mk_string (application->app_summary);
  t[11] = erl_mk_string (application->app_description);

  return erl_mk_list (t, 12);
}

static ETERM *
make_lvm_vg_list (const struct guestfs_lvm_vg_list *lvm_vgs)
{
  ETERM *t[lvm_vgs->len];
  size_t i;

  for (i = 0; i < lvm_vgs->len; ++i)
    t[i] = make_lvm_vg (&lvm_vgs->val[i]);

  return erl_mk_list (t, lvm_vgs->len);
}

static ETERM *
make_stat_list (const struct guestfs_stat_list *stats)
{
  ETERM *t[stats->len];
  size_t i;

  for (i = 0; i < stats->len; ++i)
    t[i] = make_stat (&stats->val[i]);

  return erl_mk_list (t, stats->len);
}

static ETERM *
make_dirent_list (const struct guestfs_dirent_list *dirents)
{
  ETERM *t[dirents->len];
  size_t i;

  for (i = 0; i < dirents->len; ++i)
    t[i] = make_dirent (&dirents->val[i]);

  return erl_mk_list (t, dirents->len);
}

static ETERM *
make_partition_list (const struct guestfs_partition_list *partitions)
{
  ETERM *t[partitions->len];
  size_t i;

  for (i = 0; i < partitions->len; ++i)
    t[i] = make_partition (&partitions->val[i]);

  return erl_mk_list (t, partitions->len);
}

static ETERM *
make_lvm_lv_list (const struct guestfs_lvm_lv_list *lvm_lvs)
{
  ETERM *t[lvm_lvs->len];
  size_t i;

  for (i = 0; i < lvm_lvs->len; ++i)
    t[i] = make_lvm_lv (&lvm_lvs->val[i]);

  return erl_mk_list (t, lvm_lvs->len);
}

static ETERM *
make_xattr_list (const struct guestfs_xattr_list *xattrs)
{
  ETERM *t[xattrs->len];
  size_t i;

  for (i = 0; i < xattrs->len; ++i)
    t[i] = make_xattr (&xattrs->val[i]);

  return erl_mk_list (t, xattrs->len);
}

static ETERM *
make_lvm_pv_list (const struct guestfs_lvm_pv_list *lvm_pvs)
{
  ETERM *t[lvm_pvs->len];
  size_t i;

  for (i = 0; i < lvm_pvs->len; ++i)
    t[i] = make_lvm_pv (&lvm_pvs->val[i]);

  return erl_mk_list (t, lvm_pvs->len);
}

static ETERM *
make_application_list (const struct guestfs_application_list *applications)
{
  ETERM *t[applications->len];
  size_t i;

  for (i = 0; i < applications->len; ++i)
    t[i] = make_application (&applications->val[i]);

  return erl_mk_list (t, applications->len);
}

static ETERM *
make_inotify_event_list (const struct guestfs_inotify_event_list *inotify_events)
{
  ETERM *t[inotify_events->len];
  size_t i;

  for (i = 0; i < inotify_events->len; ++i)
    t[i] = make_inotify_event (&inotify_events->val[i]);

  return erl_mk_list (t, inotify_events->len);
}

static ETERM *
run_add_cdrom (ETERM *message)
{
  char *filename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_add_cdrom (g, filename);
  free (filename);
  if (r == -1)
    return make_error ("add_cdrom");

  return erl_mk_atom ("ok");
}

static ETERM *
run_add_domain (ETERM *message)
{
  char *dom = erl_iolist_to_string (ARG (0));

  struct guestfs_add_domain_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_domain_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "libvirturi")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
      optargs_s.libvirturi = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "readonly")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
      optargs_s.readonly = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "iface")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
      optargs_s.iface = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "live")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
      optargs_s.live = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "allowuuid")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
      optargs_s.allowuuid = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "readonlydisk")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK;
      optargs_s.readonlydisk = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("add_domain", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_add_domain_argv (g, dom, optargs);
  free (dom);
  if ((optargs_s.bitmask & GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK))
    free ((char *) optargs_s.libvirturi);
  if ((optargs_s.bitmask & GUESTFS_ADD_DOMAIN_IFACE_BITMASK))
    free ((char *) optargs_s.iface);
  if ((optargs_s.bitmask & GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK))
    free ((char *) optargs_s.readonlydisk);
  if (r == -1)
    return make_error ("add_domain");

  return erl_mk_int (r);
}

static ETERM *
run_add_drive (ETERM *message)
{
  char *filename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_add_drive (g, filename);
  free (filename);
  if (r == -1)
    return make_error ("add_drive");

  return erl_mk_atom ("ok");
}

static ETERM *
run_add_drive_opts (ETERM *message)
{
  char *filename = erl_iolist_to_string (ARG (0));

  struct guestfs_add_drive_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "readonly")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
      optargs_s.readonly = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "format")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
      optargs_s.format = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "iface")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
      optargs_s.iface = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "name")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
      optargs_s.name = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("add_drive_opts", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_add_drive_opts_argv (g, filename, optargs);
  free (filename);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK))
    free ((char *) optargs_s.format);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK))
    free ((char *) optargs_s.iface);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK))
    free ((char *) optargs_s.name);
  if (r == -1)
    return make_error ("add_drive_opts");

  return erl_mk_atom ("ok");
}

static ETERM *
run_add_drive_ro (ETERM *message)
{
  char *filename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_add_drive_ro (g, filename);
  free (filename);
  if (r == -1)
    return make_error ("add_drive_ro");

  return erl_mk_atom ("ok");
}

static ETERM *
run_add_drive_ro_with_if (ETERM *message)
{
  char *filename = erl_iolist_to_string (ARG (0));
  char *iface = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_add_drive_ro_with_if (g, filename, iface);
  free (filename);
  free (iface);
  if (r == -1)
    return make_error ("add_drive_ro_with_if");

  return erl_mk_atom ("ok");
}

static ETERM *
run_add_drive_with_if (ETERM *message)
{
  char *filename = erl_iolist_to_string (ARG (0));
  char *iface = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_add_drive_with_if (g, filename, iface);
  free (filename);
  free (iface);
  if (r == -1)
    return make_error ("add_drive_with_if");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_clear (ETERM *message)
{
  char *augpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_aug_clear (g, augpath);
  free (augpath);
  if (r == -1)
    return make_error ("aug_clear");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_close (ETERM *message)
{
  int r;

  r = guestfs_aug_close (g);
  if (r == -1)
    return make_error ("aug_close");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_defnode (ETERM *message)
{
  char *name = erl_iolist_to_string (ARG (0));
  char *expr = erl_iolist_to_string (ARG (1));
  char *val = erl_iolist_to_string (ARG (2));
  struct guestfs_int_bool *r;

  r = guestfs_aug_defnode (g, name, expr, val);
  free (name);
  free (expr);
  free (val);
  if (r == NULL)
    return make_error ("aug_defnode");

  ETERM *rt = make_int_bool (r);
  guestfs_free_int_bool (r);
  return rt;
}

static ETERM *
run_aug_defvar (ETERM *message)
{
  char *name = erl_iolist_to_string (ARG (0));
  char *expr;
  if (atom_equals (ARG (1), "undefined"))
    expr = NULL;
  else
    expr = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_aug_defvar (g, name, expr);
  free (name);
  free (expr);
  if (r == -1)
    return make_error ("aug_defvar");

  return erl_mk_int (r);
}

static ETERM *
run_aug_get (ETERM *message)
{
  char *augpath = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_aug_get (g, augpath);
  free (augpath);
  if (r == NULL)
    return make_error ("aug_get");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_aug_init (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  int flags = ERL_INT_VALUE (ARG (1));
  int r;

  r = guestfs_aug_init (g, root, flags);
  free (root);
  if (r == -1)
    return make_error ("aug_init");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_insert (ETERM *message)
{
  char *augpath = erl_iolist_to_string (ARG (0));
  char *label = erl_iolist_to_string (ARG (1));
  int before = get_bool (ARG (2));
  int r;

  r = guestfs_aug_insert (g, augpath, label, before);
  free (augpath);
  free (label);
  if (r == -1)
    return make_error ("aug_insert");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_load (ETERM *message)
{
  int r;

  r = guestfs_aug_load (g);
  if (r == -1)
    return make_error ("aug_load");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_ls (ETERM *message)
{
  char *augpath = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_aug_ls (g, augpath);
  free (augpath);
  if (r == NULL)
    return make_error ("aug_ls");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_aug_match (ETERM *message)
{
  char *augpath = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_aug_match (g, augpath);
  free (augpath);
  if (r == NULL)
    return make_error ("aug_match");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_aug_mv (ETERM *message)
{
  char *src = erl_iolist_to_string (ARG (0));
  char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_aug_mv (g, src, dest);
  free (src);
  free (dest);
  if (r == -1)
    return make_error ("aug_mv");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_rm (ETERM *message)
{
  char *augpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_aug_rm (g, augpath);
  free (augpath);
  if (r == -1)
    return make_error ("aug_rm");

  return erl_mk_int (r);
}

static ETERM *
run_aug_save (ETERM *message)
{
  int r;

  r = guestfs_aug_save (g);
  if (r == -1)
    return make_error ("aug_save");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_set (ETERM *message)
{
  char *augpath = erl_iolist_to_string (ARG (0));
  char *val = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_aug_set (g, augpath, val);
  free (augpath);
  free (val);
  if (r == -1)
    return make_error ("aug_set");

  return erl_mk_atom ("ok");
}

static ETERM *
run_available (ETERM *message)
{
  char **groups = get_string_list (ARG (0));
  int r;

  r = guestfs_available (g, groups);
  free_strings (groups);
  if (r == -1)
    return make_error ("available");

  return erl_mk_atom ("ok");
}

static ETERM *
run_available_all_groups (ETERM *message)
{
  char **r;

  r = guestfs_available_all_groups (g);
  if (r == NULL)
    return make_error ("available_all_groups");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_base64_in (ETERM *message)
{
  char *base64file = erl_iolist_to_string (ARG (0));
  char *filename = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_base64_in (g, base64file, filename);
  free (base64file);
  free (filename);
  if (r == -1)
    return make_error ("base64_in");

  return erl_mk_atom ("ok");
}

static ETERM *
run_base64_out (ETERM *message)
{
  char *filename = erl_iolist_to_string (ARG (0));
  char *base64file = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_base64_out (g, filename, base64file);
  free (filename);
  free (base64file);
  if (r == -1)
    return make_error ("base64_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_blkid (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_blkid (g, device);
  free (device);
  if (r == NULL)
    return make_error ("blkid");

  ETERM *rt = make_table (r);
  free_strings (r);
  return rt;
}

static ETERM *
run_blockdev_flushbufs (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_flushbufs (g, device);
  free (device);
  if (r == -1)
    return make_error ("blockdev_flushbufs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_blockdev_getbsz (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_getbsz (g, device);
  free (device);
  if (r == -1)
    return make_error ("blockdev_getbsz");

  return erl_mk_int (r);
}

static ETERM *
run_blockdev_getro (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_getro (g, device);
  free (device);
  if (r == -1)
    return make_error ("blockdev_getro");

  return make_bool (r);
}

static ETERM *
run_blockdev_getsize64 (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_blockdev_getsize64 (g, device);
  free (device);
  if (r == -1)
    return make_error ("blockdev_getsize64");

  return erl_mk_longlong (r);
}

static ETERM *
run_blockdev_getss (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_getss (g, device);
  free (device);
  if (r == -1)
    return make_error ("blockdev_getss");

  return erl_mk_int (r);
}

static ETERM *
run_blockdev_getsz (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_blockdev_getsz (g, device);
  free (device);
  if (r == -1)
    return make_error ("blockdev_getsz");

  return erl_mk_longlong (r);
}

static ETERM *
run_blockdev_rereadpt (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_rereadpt (g, device);
  free (device);
  if (r == -1)
    return make_error ("blockdev_rereadpt");

  return erl_mk_atom ("ok");
}

static ETERM *
run_blockdev_setbsz (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int blocksize = ERL_INT_VALUE (ARG (1));
  int r;

  r = guestfs_blockdev_setbsz (g, device, blocksize);
  free (device);
  if (r == -1)
    return make_error ("blockdev_setbsz");

  return erl_mk_atom ("ok");
}

static ETERM *
run_blockdev_setro (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_setro (g, device);
  free (device);
  if (r == -1)
    return make_error ("blockdev_setro");

  return erl_mk_atom ("ok");
}

static ETERM *
run_blockdev_setrw (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_setrw (g, device);
  free (device);
  if (r == -1)
    return make_error ("blockdev_setrw");

  return erl_mk_atom ("ok");
}

static ETERM *
run_btrfs_filesystem_resize (ETERM *message)
{
  char *mountpoint = erl_iolist_to_string (ARG (0));

  struct guestfs_btrfs_filesystem_resize_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
      optargs_s.size = ERL_LL_VALUE (hd_value);
    }
    else
      return unknown_optarg ("btrfs_filesystem_resize", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);
  free (mountpoint);
  if (r == -1)
    return make_error ("btrfs_filesystem_resize");

  return erl_mk_atom ("ok");
}

static ETERM *
run_case_sensitive_path (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_case_sensitive_path (g, path);
  free (path);
  if (r == NULL)
    return make_error ("case_sensitive_path");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_cat (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_cat (g, path);
  free (path);
  if (r == NULL)
    return make_error ("cat");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_checksum (ETERM *message)
{
  char *csumtype = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_checksum (g, csumtype, path);
  free (csumtype);
  free (path);
  if (r == NULL)
    return make_error ("checksum");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_checksum_device (ETERM *message)
{
  char *csumtype = erl_iolist_to_string (ARG (0));
  char *device = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_checksum_device (g, csumtype, device);
  free (csumtype);
  free (device);
  if (r == NULL)
    return make_error ("checksum_device");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_checksums_out (ETERM *message)
{
  char *csumtype = erl_iolist_to_string (ARG (0));
  char *directory = erl_iolist_to_string (ARG (1));
  char *sumsfile = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_checksums_out (g, csumtype, directory, sumsfile);
  free (csumtype);
  free (directory);
  free (sumsfile);
  if (r == -1)
    return make_error ("checksums_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_chmod (ETERM *message)
{
  int mode = ERL_INT_VALUE (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_chmod (g, mode, path);
  free (path);
  if (r == -1)
    return make_error ("chmod");

  return erl_mk_atom ("ok");
}

static ETERM *
run_chown (ETERM *message)
{
  int owner = ERL_INT_VALUE (ARG (0));
  int group = ERL_INT_VALUE (ARG (1));
  char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_chown (g, owner, group, path);
  free (path);
  if (r == -1)
    return make_error ("chown");

  return erl_mk_atom ("ok");
}

static ETERM *
run_command (ETERM *message)
{
  char **arguments = get_string_list (ARG (0));
  char *r;

  r = guestfs_command (g, arguments);
  free_strings (arguments);
  if (r == NULL)
    return make_error ("command");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_command_lines (ETERM *message)
{
  char **arguments = get_string_list (ARG (0));
  char **r;

  r = guestfs_command_lines (g, arguments);
  free_strings (arguments);
  if (r == NULL)
    return make_error ("command_lines");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_compress_device_out (ETERM *message)
{
  char *ctype = erl_iolist_to_string (ARG (0));
  char *device = erl_iolist_to_string (ARG (1));
  char *zdevice = erl_iolist_to_string (ARG (2));

  struct guestfs_compress_device_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_device_out_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (3);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "level")) {
      optargs_s.bitmask |= GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
      optargs_s.level = ERL_INT_VALUE (hd_value);
    }
    else
      return unknown_optarg ("compress_device_out", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);
  free (ctype);
  free (device);
  free (zdevice);
  if (r == -1)
    return make_error ("compress_device_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_compress_out (ETERM *message)
{
  char *ctype = erl_iolist_to_string (ARG (0));
  char *file = erl_iolist_to_string (ARG (1));
  char *zfile = erl_iolist_to_string (ARG (2));

  struct guestfs_compress_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_out_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (3);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "level")) {
      optargs_s.bitmask |= GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
      optargs_s.level = ERL_INT_VALUE (hd_value);
    }
    else
      return unknown_optarg ("compress_out", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_compress_out_argv (g, ctype, file, zfile, optargs);
  free (ctype);
  free (file);
  free (zfile);
  if (r == -1)
    return make_error ("compress_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_config (ETERM *message)
{
  char *qemuparam = erl_iolist_to_string (ARG (0));
  char *qemuvalue;
  if (atom_equals (ARG (1), "undefined"))
    qemuvalue = NULL;
  else
    qemuvalue = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_config (g, qemuparam, qemuvalue);
  free (qemuparam);
  free (qemuvalue);
  if (r == -1)
    return make_error ("config");

  return erl_mk_atom ("ok");
}

static ETERM *
run_copy_device_to_device (ETERM *message)
{
  char *src = erl_iolist_to_string (ARG (0));
  char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_device_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "srcoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "destoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
      optargs_s.size = ERL_LL_VALUE (hd_value);
    }
    else
      return unknown_optarg ("copy_device_to_device", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);
  free (src);
  free (dest);
  if (r == -1)
    return make_error ("copy_device_to_device");

  return erl_mk_atom ("ok");
}

static ETERM *
run_copy_device_to_file (ETERM *message)
{
  char *src = erl_iolist_to_string (ARG (0));
  char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_device_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "srcoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "destoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
      optargs_s.size = ERL_LL_VALUE (hd_value);
    }
    else
      return unknown_optarg ("copy_device_to_file", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);
  free (src);
  free (dest);
  if (r == -1)
    return make_error ("copy_device_to_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_copy_file_to_device (ETERM *message)
{
  char *src = erl_iolist_to_string (ARG (0));
  char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_file_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "srcoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "destoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
      optargs_s.size = ERL_LL_VALUE (hd_value);
    }
    else
      return unknown_optarg ("copy_file_to_device", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);
  free (src);
  free (dest);
  if (r == -1)
    return make_error ("copy_file_to_device");

  return erl_mk_atom ("ok");
}

static ETERM *
run_copy_file_to_file (ETERM *message)
{
  char *src = erl_iolist_to_string (ARG (0));
  char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_file_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "srcoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "destoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
      optargs_s.size = ERL_LL_VALUE (hd_value);
    }
    else
      return unknown_optarg ("copy_file_to_file", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);
  free (src);
  free (dest);
  if (r == -1)
    return make_error ("copy_file_to_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_copy_size (ETERM *message)
{
  char *src = erl_iolist_to_string (ARG (0));
  char *dest = erl_iolist_to_string (ARG (1));
  int64_t size = ERL_LL_VALUE (ARG (2));
  int r;

  r = guestfs_copy_size (g, src, dest, size);
  free (src);
  free (dest);
  if (r == -1)
    return make_error ("copy_size");

  return erl_mk_atom ("ok");
}

static ETERM *
run_cp (ETERM *message)
{
  char *src = erl_iolist_to_string (ARG (0));
  char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_cp (g, src, dest);
  free (src);
  free (dest);
  if (r == -1)
    return make_error ("cp");

  return erl_mk_atom ("ok");
}

static ETERM *
run_cp_a (ETERM *message)
{
  char *src = erl_iolist_to_string (ARG (0));
  char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_cp_a (g, src, dest);
  free (src);
  free (dest);
  if (r == -1)
    return make_error ("cp_a");

  return erl_mk_atom ("ok");
}

static ETERM *
run_dd (ETERM *message)
{
  char *src = erl_iolist_to_string (ARG (0));
  char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_dd (g, src, dest);
  free (src);
  free (dest);
  if (r == -1)
    return make_error ("dd");

  return erl_mk_atom ("ok");
}

static ETERM *
run_debug (ETERM *message)
{
  char *subcmd = erl_iolist_to_string (ARG (0));
  char **extraargs = get_string_list (ARG (1));
  char *r;

  r = guestfs_debug (g, subcmd, extraargs);
  free (subcmd);
  free_strings (extraargs);
  if (r == NULL)
    return make_error ("debug");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_debug_cmdline (ETERM *message)
{
  char **r;

  r = guestfs_debug_cmdline (g);
  if (r == NULL)
    return make_error ("debug_cmdline");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_debug_drives (ETERM *message)
{
  char **r;

  r = guestfs_debug_drives (g);
  if (r == NULL)
    return make_error ("debug_drives");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_debug_upload (ETERM *message)
{
  char *filename = erl_iolist_to_string (ARG (0));
  char *tmpname = erl_iolist_to_string (ARG (1));
  int mode = ERL_INT_VALUE (ARG (2));
  int r;

  r = guestfs_debug_upload (g, filename, tmpname, mode);
  free (filename);
  free (tmpname);
  if (r == -1)
    return make_error ("debug_upload");

  return erl_mk_atom ("ok");
}

static ETERM *
run_df (ETERM *message)
{
  char *r;

  r = guestfs_df (g);
  if (r == NULL)
    return make_error ("df");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_df_h (ETERM *message)
{
  char *r;

  r = guestfs_df_h (g);
  if (r == NULL)
    return make_error ("df_h");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_dmesg (ETERM *message)
{
  char *r;

  r = guestfs_dmesg (g);
  if (r == NULL)
    return make_error ("dmesg");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_download (ETERM *message)
{
  char *remotefilename = erl_iolist_to_string (ARG (0));
  char *filename = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_download (g, remotefilename, filename);
  free (remotefilename);
  free (filename);
  if (r == -1)
    return make_error ("download");

  return erl_mk_atom ("ok");
}

static ETERM *
run_download_offset (ETERM *message)
{
  char *remotefilename = erl_iolist_to_string (ARG (0));
  char *filename = erl_iolist_to_string (ARG (1));
  int64_t offset = ERL_LL_VALUE (ARG (2));
  int64_t size = ERL_LL_VALUE (ARG (3));
  int r;

  r = guestfs_download_offset (g, remotefilename, filename, offset, size);
  free (remotefilename);
  free (filename);
  if (r == -1)
    return make_error ("download_offset");

  return erl_mk_atom ("ok");
}

static ETERM *
run_drop_caches (ETERM *message)
{
  int whattodrop = ERL_INT_VALUE (ARG (0));
  int r;

  r = guestfs_drop_caches (g, whattodrop);
  if (r == -1)
    return make_error ("drop_caches");

  return erl_mk_atom ("ok");
}

static ETERM *
run_du (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_du (g, path);
  free (path);
  if (r == -1)
    return make_error ("du");

  return erl_mk_longlong (r);
}

static ETERM *
run_e2fsck (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_e2fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_e2fsck_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "correct")) {
      optargs_s.bitmask |= GUESTFS_E2FSCK_CORRECT_BITMASK;
      optargs_s.correct = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "forceall")) {
      optargs_s.bitmask |= GUESTFS_E2FSCK_FORCEALL_BITMASK;
      optargs_s.forceall = get_bool (hd_value);
    }
    else
      return unknown_optarg ("e2fsck", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_e2fsck_argv (g, device, optargs);
  free (device);
  if (r == -1)
    return make_error ("e2fsck");

  return erl_mk_atom ("ok");
}

static ETERM *
run_e2fsck_f (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_e2fsck_f (g, device);
  free (device);
  if (r == -1)
    return make_error ("e2fsck_f");

  return erl_mk_atom ("ok");
}

static ETERM *
run_echo_daemon (ETERM *message)
{
  char **words = get_string_list (ARG (0));
  char *r;

  r = guestfs_echo_daemon (g, words);
  free_strings (words);
  if (r == NULL)
    return make_error ("echo_daemon");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_egrep (ETERM *message)
{
  char *regex = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_egrep (g, regex, path);
  free (regex);
  free (path);
  if (r == NULL)
    return make_error ("egrep");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_egrepi (ETERM *message)
{
  char *regex = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_egrepi (g, regex, path);
  free (regex);
  free (path);
  if (r == NULL)
    return make_error ("egrepi");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_equal (ETERM *message)
{
  char *file1 = erl_iolist_to_string (ARG (0));
  char *file2 = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_equal (g, file1, file2);
  free (file1);
  free (file2);
  if (r == -1)
    return make_error ("equal");

  return make_bool (r);
}

static ETERM *
run_exists (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_exists (g, path);
  free (path);
  if (r == -1)
    return make_error ("exists");

  return make_bool (r);
}

static ETERM *
run_fallocate (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int len = ERL_INT_VALUE (ARG (1));
  int r;

  r = guestfs_fallocate (g, path, len);
  free (path);
  if (r == -1)
    return make_error ("fallocate");

  return erl_mk_atom ("ok");
}

static ETERM *
run_fallocate64 (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int64_t len = ERL_LL_VALUE (ARG (1));
  int r;

  r = guestfs_fallocate64 (g, path, len);
  free (path);
  if (r == -1)
    return make_error ("fallocate64");

  return erl_mk_atom ("ok");
}

static ETERM *
run_fgrep (ETERM *message)
{
  char *pattern = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_fgrep (g, pattern, path);
  free (pattern);
  free (path);
  if (r == NULL)
    return make_error ("fgrep");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_fgrepi (ETERM *message)
{
  char *pattern = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_fgrepi (g, pattern, path);
  free (pattern);
  free (path);
  if (r == NULL)
    return make_error ("fgrepi");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_file (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_file (g, path);
  free (path);
  if (r == NULL)
    return make_error ("file");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_file_architecture (ETERM *message)
{
  char *filename = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_file_architecture (g, filename);
  free (filename);
  if (r == NULL)
    return make_error ("file_architecture");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_filesize (ETERM *message)
{
  char *file = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_filesize (g, file);
  free (file);
  if (r == -1)
    return make_error ("filesize");

  return erl_mk_longlong (r);
}

static ETERM *
run_fill (ETERM *message)
{
  int c = ERL_INT_VALUE (ARG (0));
  int len = ERL_INT_VALUE (ARG (1));
  char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_fill (g, c, len, path);
  free (path);
  if (r == -1)
    return make_error ("fill");

  return erl_mk_atom ("ok");
}

static ETERM *
run_fill_pattern (ETERM *message)
{
  char *pattern = erl_iolist_to_string (ARG (0));
  int len = ERL_INT_VALUE (ARG (1));
  char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_fill_pattern (g, pattern, len, path);
  free (pattern);
  free (path);
  if (r == -1)
    return make_error ("fill_pattern");

  return erl_mk_atom ("ok");
}

static ETERM *
run_find (ETERM *message)
{
  char *directory = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_find (g, directory);
  free (directory);
  if (r == NULL)
    return make_error ("find");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_find0 (ETERM *message)
{
  char *directory = erl_iolist_to_string (ARG (0));
  char *files = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_find0 (g, directory, files);
  free (directory);
  free (files);
  if (r == -1)
    return make_error ("find0");

  return erl_mk_atom ("ok");
}

static ETERM *
run_findfs_label (ETERM *message)
{
  char *label = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_findfs_label (g, label);
  free (label);
  if (r == NULL)
    return make_error ("findfs_label");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_findfs_uuid (ETERM *message)
{
  char *uuid = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_findfs_uuid (g, uuid);
  free (uuid);
  if (r == NULL)
    return make_error ("findfs_uuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_fsck (ETERM *message)
{
  char *fstype = erl_iolist_to_string (ARG (0));
  char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_fsck (g, fstype, device);
  free (fstype);
  free (device);
  if (r == -1)
    return make_error ("fsck");

  return erl_mk_int (r);
}

static ETERM *
run_get_append (ETERM *message)
{
  const char *r;

  r = guestfs_get_append (g);

  ETERM *rt;
  if (r)
    rt = erl_mk_string (r);
  else
    rt = erl_mk_atom ("undefined");
  return rt;
}

static ETERM *
run_get_attach_method (ETERM *message)
{
  char *r;

  r = guestfs_get_attach_method (g);
  if (r == NULL)
    return make_error ("get_attach_method");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_autosync (ETERM *message)
{
  int r;

  r = guestfs_get_autosync (g);
  if (r == -1)
    return make_error ("get_autosync");

  return make_bool (r);
}

static ETERM *
run_get_direct (ETERM *message)
{
  int r;

  r = guestfs_get_direct (g);
  if (r == -1)
    return make_error ("get_direct");

  return make_bool (r);
}

static ETERM *
run_get_e2label (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_get_e2label (g, device);
  free (device);
  if (r == NULL)
    return make_error ("get_e2label");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_e2uuid (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_get_e2uuid (g, device);
  free (device);
  if (r == NULL)
    return make_error ("get_e2uuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_memsize (ETERM *message)
{
  int r;

  r = guestfs_get_memsize (g);
  if (r == -1)
    return make_error ("get_memsize");

  return erl_mk_int (r);
}

static ETERM *
run_get_network (ETERM *message)
{
  int r;

  r = guestfs_get_network (g);
  if (r == -1)
    return make_error ("get_network");

  return make_bool (r);
}

static ETERM *
run_get_path (ETERM *message)
{
  const char *r;

  r = guestfs_get_path (g);
  if (r == NULL)
    return make_error ("get_path");

  return erl_mk_string (r);
}

static ETERM *
run_get_pgroup (ETERM *message)
{
  int r;

  r = guestfs_get_pgroup (g);
  if (r == -1)
    return make_error ("get_pgroup");

  return make_bool (r);
}

static ETERM *
run_get_pid (ETERM *message)
{
  int r;

  r = guestfs_get_pid (g);
  if (r == -1)
    return make_error ("get_pid");

  return erl_mk_int (r);
}

static ETERM *
run_get_qemu (ETERM *message)
{
  const char *r;

  r = guestfs_get_qemu (g);
  if (r == NULL)
    return make_error ("get_qemu");

  return erl_mk_string (r);
}

static ETERM *
run_get_recovery_proc (ETERM *message)
{
  int r;

  r = guestfs_get_recovery_proc (g);
  if (r == -1)
    return make_error ("get_recovery_proc");

  return make_bool (r);
}

static ETERM *
run_get_selinux (ETERM *message)
{
  int r;

  r = guestfs_get_selinux (g);
  if (r == -1)
    return make_error ("get_selinux");

  return make_bool (r);
}

static ETERM *
run_get_smp (ETERM *message)
{
  int r;

  r = guestfs_get_smp (g);
  if (r == -1)
    return make_error ("get_smp");

  return erl_mk_int (r);
}

static ETERM *
run_get_state (ETERM *message)
{
  int r;

  r = guestfs_get_state (g);
  if (r == -1)
    return make_error ("get_state");

  return erl_mk_int (r);
}

static ETERM *
run_get_trace (ETERM *message)
{
  int r;

  r = guestfs_get_trace (g);
  if (r == -1)
    return make_error ("get_trace");

  return make_bool (r);
}

static ETERM *
run_get_umask (ETERM *message)
{
  int r;

  r = guestfs_get_umask (g);
  if (r == -1)
    return make_error ("get_umask");

  return erl_mk_int (r);
}

static ETERM *
run_get_verbose (ETERM *message)
{
  int r;

  r = guestfs_get_verbose (g);
  if (r == -1)
    return make_error ("get_verbose");

  return make_bool (r);
}

static ETERM *
run_getcon (ETERM *message)
{
  char *r;

  r = guestfs_getcon (g);
  if (r == NULL)
    return make_error ("getcon");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_getxattr (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char *name = erl_iolist_to_string (ARG (1));
  char *r;
  size_t size;

  r = guestfs_getxattr (g, path, name, &size);
  free (path);
  free (name);
  if (r == NULL)
    return make_error ("getxattr");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_getxattrs (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_xattr_list *r;

  r = guestfs_getxattrs (g, path);
  free (path);
  if (r == NULL)
    return make_error ("getxattrs");

  ETERM *rt = make_xattr_list (r);
  guestfs_free_xattr_list (r);
  return rt;
}

static ETERM *
run_glob_expand (ETERM *message)
{
  char *pattern = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_glob_expand (g, pattern);
  free (pattern);
  if (r == NULL)
    return make_error ("glob_expand");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_grep (ETERM *message)
{
  char *regex = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_grep (g, regex, path);
  free (regex);
  free (path);
  if (r == NULL)
    return make_error ("grep");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_grepi (ETERM *message)
{
  char *regex = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_grepi (g, regex, path);
  free (regex);
  free (path);
  if (r == NULL)
    return make_error ("grepi");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_grub_install (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_grub_install (g, root, device);
  free (root);
  free (device);
  if (r == -1)
    return make_error ("grub_install");

  return erl_mk_atom ("ok");
}

static ETERM *
run_head (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_head (g, path);
  free (path);
  if (r == NULL)
    return make_error ("head");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_head_n (ETERM *message)
{
  int nrlines = ERL_INT_VALUE (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_head_n (g, nrlines, path);
  free (path);
  if (r == NULL)
    return make_error ("head_n");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_hexdump (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_hexdump (g, path);
  free (path);
  if (r == NULL)
    return make_error ("hexdump");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_initrd_cat (ETERM *message)
{
  char *initrdpath = erl_iolist_to_string (ARG (0));
  char *filename = erl_iolist_to_string (ARG (1));
  char *r;
  size_t size;

  r = guestfs_initrd_cat (g, initrdpath, filename, &size);
  free (initrdpath);
  free (filename);
  if (r == NULL)
    return make_error ("initrd_cat");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_initrd_list (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_initrd_list (g, path);
  free (path);
  if (r == NULL)
    return make_error ("initrd_list");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_inotify_add_watch (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int mask = ERL_INT_VALUE (ARG (1));
  int64_t r;

  r = guestfs_inotify_add_watch (g, path, mask);
  free (path);
  if (r == -1)
    return make_error ("inotify_add_watch");

  return erl_mk_longlong (r);
}

static ETERM *
run_inotify_close (ETERM *message)
{
  int r;

  r = guestfs_inotify_close (g);
  if (r == -1)
    return make_error ("inotify_close");

  return erl_mk_atom ("ok");
}

static ETERM *
run_inotify_files (ETERM *message)
{
  char **r;

  r = guestfs_inotify_files (g);
  if (r == NULL)
    return make_error ("inotify_files");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_inotify_init (ETERM *message)
{
  int maxevents = ERL_INT_VALUE (ARG (0));
  int r;

  r = guestfs_inotify_init (g, maxevents);
  if (r == -1)
    return make_error ("inotify_init");

  return erl_mk_atom ("ok");
}

static ETERM *
run_inotify_read (ETERM *message)
{
  struct guestfs_inotify_event_list *r;

  r = guestfs_inotify_read (g);
  if (r == NULL)
    return make_error ("inotify_read");

  ETERM *rt = make_inotify_event_list (r);
  guestfs_free_inotify_event_list (r);
  return rt;
}

static ETERM *
run_inotify_rm_watch (ETERM *message)
{
  int wd = ERL_INT_VALUE (ARG (0));
  int r;

  r = guestfs_inotify_rm_watch (g, wd);
  if (r == -1)
    return make_error ("inotify_rm_watch");

  return erl_mk_atom ("ok");
}

static ETERM *
run_inspect_get_arch (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_arch (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_arch");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_distro (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_distro (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_distro");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_drive_mappings (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_inspect_get_drive_mappings (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_drive_mappings");

  ETERM *rt = make_table (r);
  free_strings (r);
  return rt;
}

static ETERM *
run_inspect_get_filesystems (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_inspect_get_filesystems (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_filesystems");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_inspect_get_format (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_format (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_format");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_hostname (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_hostname (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_hostname");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_icon (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));

  struct guestfs_inspect_get_icon_argv optargs_s = { .bitmask = 0 };
  struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "favicon")) {
      optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
      optargs_s.favicon = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "highquality")) {
      optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
      optargs_s.highquality = get_bool (hd_value);
    }
    else
      return unknown_optarg ("inspect_get_icon", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  char *r;
  size_t size;

  r = guestfs_inspect_get_icon_argv (g, root, &size, optargs);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_icon");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_major_version (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_get_major_version (g, root);
  free (root);
  if (r == -1)
    return make_error ("inspect_get_major_version");

  return erl_mk_int (r);
}

static ETERM *
run_inspect_get_minor_version (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_get_minor_version (g, root);
  free (root);
  if (r == -1)
    return make_error ("inspect_get_minor_version");

  return erl_mk_int (r);
}

static ETERM *
run_inspect_get_mountpoints (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_inspect_get_mountpoints (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_mountpoints");

  ETERM *rt = make_table (r);
  free_strings (r);
  return rt;
}

static ETERM *
run_inspect_get_package_format (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_package_format (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_package_format");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_package_management (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_package_management (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_package_management");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_product_name (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_product_name (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_product_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_product_variant (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_product_variant (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_product_variant");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_roots (ETERM *message)
{
  char **r;

  r = guestfs_inspect_get_roots (g);
  if (r == NULL)
    return make_error ("inspect_get_roots");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_inspect_get_type (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_type (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_type");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_windows_current_control_set (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_windows_current_control_set (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_windows_current_control_set");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_windows_systemroot (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_windows_systemroot (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_get_windows_systemroot");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_is_live (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_is_live (g, root);
  free (root);
  if (r == -1)
    return make_error ("inspect_is_live");

  return make_bool (r);
}

static ETERM *
run_inspect_is_multipart (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_is_multipart (g, root);
  free (root);
  if (r == -1)
    return make_error ("inspect_is_multipart");

  return make_bool (r);
}

static ETERM *
run_inspect_is_netinst (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_is_netinst (g, root);
  free (root);
  if (r == -1)
    return make_error ("inspect_is_netinst");

  return make_bool (r);
}

static ETERM *
run_inspect_list_applications (ETERM *message)
{
  char *root = erl_iolist_to_string (ARG (0));
  struct guestfs_application_list *r;

  r = guestfs_inspect_list_applications (g, root);
  free (root);
  if (r == NULL)
    return make_error ("inspect_list_applications");

  ETERM *rt = make_application_list (r);
  guestfs_free_application_list (r);
  return rt;
}

static ETERM *
run_inspect_os (ETERM *message)
{
  char **r;

  r = guestfs_inspect_os (g);
  if (r == NULL)
    return make_error ("inspect_os");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_internal_autosync (ETERM *message)
{
  int r;

  r = guestfs_internal_autosync (g);
  if (r == -1)
    return make_error ("internal_autosync");

  return erl_mk_atom ("ok");
}

static ETERM *
run_is_blockdev (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_blockdev (g, path);
  free (path);
  if (r == -1)
    return make_error ("is_blockdev");

  return make_bool (r);
}

static ETERM *
run_is_busy (ETERM *message)
{
  int r;

  r = guestfs_is_busy (g);
  if (r == -1)
    return make_error ("is_busy");

  return make_bool (r);
}

static ETERM *
run_is_chardev (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_chardev (g, path);
  free (path);
  if (r == -1)
    return make_error ("is_chardev");

  return make_bool (r);
}

static ETERM *
run_is_config (ETERM *message)
{
  int r;

  r = guestfs_is_config (g);
  if (r == -1)
    return make_error ("is_config");

  return make_bool (r);
}

static ETERM *
run_is_dir (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_dir (g, path);
  free (path);
  if (r == -1)
    return make_error ("is_dir");

  return make_bool (r);
}

static ETERM *
run_is_fifo (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_fifo (g, path);
  free (path);
  if (r == -1)
    return make_error ("is_fifo");

  return make_bool (r);
}

static ETERM *
run_is_file (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_file (g, path);
  free (path);
  if (r == -1)
    return make_error ("is_file");

  return make_bool (r);
}

static ETERM *
run_is_launching (ETERM *message)
{
  int r;

  r = guestfs_is_launching (g);
  if (r == -1)
    return make_error ("is_launching");

  return make_bool (r);
}

static ETERM *
run_is_lv (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_lv (g, device);
  free (device);
  if (r == -1)
    return make_error ("is_lv");

  return make_bool (r);
}

static ETERM *
run_is_ready (ETERM *message)
{
  int r;

  r = guestfs_is_ready (g);
  if (r == -1)
    return make_error ("is_ready");

  return make_bool (r);
}

static ETERM *
run_is_socket (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_socket (g, path);
  free (path);
  if (r == -1)
    return make_error ("is_socket");

  return make_bool (r);
}

static ETERM *
run_is_symlink (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_symlink (g, path);
  free (path);
  if (r == -1)
    return make_error ("is_symlink");

  return make_bool (r);
}

static ETERM *
run_is_zero (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_zero (g, path);
  free (path);
  if (r == -1)
    return make_error ("is_zero");

  return make_bool (r);
}

static ETERM *
run_is_zero_device (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_zero_device (g, device);
  free (device);
  if (r == -1)
    return make_error ("is_zero_device");

  return make_bool (r);
}

static ETERM *
run_kill_subprocess (ETERM *message)
{
  int r;

  r = guestfs_kill_subprocess (g);
  if (r == -1)
    return make_error ("kill_subprocess");

  return erl_mk_atom ("ok");
}

static ETERM *
run_launch (ETERM *message)
{
  int r;

  r = guestfs_launch (g);
  if (r == -1)
    return make_error ("launch");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lchown (ETERM *message)
{
  int owner = ERL_INT_VALUE (ARG (0));
  int group = ERL_INT_VALUE (ARG (1));
  char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_lchown (g, owner, group, path);
  free (path);
  if (r == -1)
    return make_error ("lchown");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lgetxattr (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char *name = erl_iolist_to_string (ARG (1));
  char *r;
  size_t size;

  r = guestfs_lgetxattr (g, path, name, &size);
  free (path);
  free (name);
  if (r == NULL)
    return make_error ("lgetxattr");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_lgetxattrs (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_xattr_list *r;

  r = guestfs_lgetxattrs (g, path);
  free (path);
  if (r == NULL)
    return make_error ("lgetxattrs");

  ETERM *rt = make_xattr_list (r);
  guestfs_free_xattr_list (r);
  return rt;
}

static ETERM *
run_list_9p (ETERM *message)
{
  char **r;

  r = guestfs_list_9p (g);
  if (r == NULL)
    return make_error ("list_9p");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_list_devices (ETERM *message)
{
  char **r;

  r = guestfs_list_devices (g);
  if (r == NULL)
    return make_error ("list_devices");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_list_dm_devices (ETERM *message)
{
  char **r;

  r = guestfs_list_dm_devices (g);
  if (r == NULL)
    return make_error ("list_dm_devices");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_list_filesystems (ETERM *message)
{
  char **r;

  r = guestfs_list_filesystems (g);
  if (r == NULL)
    return make_error ("list_filesystems");

  ETERM *rt = make_table (r);
  free_strings (r);
  return rt;
}

static ETERM *
run_list_md_devices (ETERM *message)
{
  char **r;

  r = guestfs_list_md_devices (g);
  if (r == NULL)
    return make_error ("list_md_devices");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_list_partitions (ETERM *message)
{
  char **r;

  r = guestfs_list_partitions (g);
  if (r == NULL)
    return make_error ("list_partitions");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_ll (ETERM *message)
{
  char *directory = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_ll (g, directory);
  free (directory);
  if (r == NULL)
    return make_error ("ll");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_ln (ETERM *message)
{
  char *target = erl_iolist_to_string (ARG (0));
  char *linkname = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ln (g, target, linkname);
  free (target);
  free (linkname);
  if (r == -1)
    return make_error ("ln");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ln_f (ETERM *message)
{
  char *target = erl_iolist_to_string (ARG (0));
  char *linkname = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ln_f (g, target, linkname);
  free (target);
  free (linkname);
  if (r == -1)
    return make_error ("ln_f");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ln_s (ETERM *message)
{
  char *target = erl_iolist_to_string (ARG (0));
  char *linkname = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ln_s (g, target, linkname);
  free (target);
  free (linkname);
  if (r == -1)
    return make_error ("ln_s");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ln_sf (ETERM *message)
{
  char *target = erl_iolist_to_string (ARG (0));
  char *linkname = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ln_sf (g, target, linkname);
  free (target);
  free (linkname);
  if (r == -1)
    return make_error ("ln_sf");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lremovexattr (ETERM *message)
{
  char *xattr = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_lremovexattr (g, xattr, path);
  free (xattr);
  free (path);
  if (r == -1)
    return make_error ("lremovexattr");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ls (ETERM *message)
{
  char *directory = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_ls (g, directory);
  free (directory);
  if (r == NULL)
    return make_error ("ls");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_lsetxattr (ETERM *message)
{
  char *xattr = erl_iolist_to_string (ARG (0));
  char *val = erl_iolist_to_string (ARG (1));
  int vallen = ERL_INT_VALUE (ARG (2));
  char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_lsetxattr (g, xattr, val, vallen, path);
  free (xattr);
  free (val);
  free (path);
  if (r == -1)
    return make_error ("lsetxattr");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lstat (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_stat *r;

  r = guestfs_lstat (g, path);
  free (path);
  if (r == NULL)
    return make_error ("lstat");

  ETERM *rt = make_stat (r);
  guestfs_free_stat (r);
  return rt;
}

static ETERM *
run_lstatlist (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char **names = get_string_list (ARG (1));
  struct guestfs_stat_list *r;

  r = guestfs_lstatlist (g, path, names);
  free (path);
  free_strings (names);
  if (r == NULL)
    return make_error ("lstatlist");

  ETERM *rt = make_stat_list (r);
  guestfs_free_stat_list (r);
  return rt;
}

static ETERM *
run_luks_add_key (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *key = erl_iolist_to_string (ARG (1));
  char *newkey = erl_iolist_to_string (ARG (2));
  int keyslot = ERL_INT_VALUE (ARG (3));
  int r;

  r = guestfs_luks_add_key (g, device, key, newkey, keyslot);
  free (device);
  free (key);
  free (newkey);
  if (r == -1)
    return make_error ("luks_add_key");

  return erl_mk_atom ("ok");
}

static ETERM *
run_luks_close (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_luks_close (g, device);
  free (device);
  if (r == -1)
    return make_error ("luks_close");

  return erl_mk_atom ("ok");
}

static ETERM *
run_luks_format (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *key = erl_iolist_to_string (ARG (1));
  int keyslot = ERL_INT_VALUE (ARG (2));
  int r;

  r = guestfs_luks_format (g, device, key, keyslot);
  free (device);
  free (key);
  if (r == -1)
    return make_error ("luks_format");

  return erl_mk_atom ("ok");
}

static ETERM *
run_luks_format_cipher (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *key = erl_iolist_to_string (ARG (1));
  int keyslot = ERL_INT_VALUE (ARG (2));
  char *cipher = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);
  free (device);
  free (key);
  free (cipher);
  if (r == -1)
    return make_error ("luks_format_cipher");

  return erl_mk_atom ("ok");
}

static ETERM *
run_luks_kill_slot (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *key = erl_iolist_to_string (ARG (1));
  int keyslot = ERL_INT_VALUE (ARG (2));
  int r;

  r = guestfs_luks_kill_slot (g, device, key, keyslot);
  free (device);
  free (key);
  if (r == -1)
    return make_error ("luks_kill_slot");

  return erl_mk_atom ("ok");
}

static ETERM *
run_luks_open (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *key = erl_iolist_to_string (ARG (1));
  char *mapname = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_luks_open (g, device, key, mapname);
  free (device);
  free (key);
  free (mapname);
  if (r == -1)
    return make_error ("luks_open");

  return erl_mk_atom ("ok");
}

static ETERM *
run_luks_open_ro (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *key = erl_iolist_to_string (ARG (1));
  char *mapname = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_luks_open_ro (g, device, key, mapname);
  free (device);
  free (key);
  free (mapname);
  if (r == -1)
    return make_error ("luks_open_ro");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvcreate (ETERM *message)
{
  char *logvol = erl_iolist_to_string (ARG (0));
  char *volgroup = erl_iolist_to_string (ARG (1));
  int mbytes = ERL_INT_VALUE (ARG (2));
  int r;

  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);
  free (logvol);
  free (volgroup);
  if (r == -1)
    return make_error ("lvcreate");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvm_canonical_lv_name (ETERM *message)
{
  char *lvname = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_lvm_canonical_lv_name (g, lvname);
  free (lvname);
  if (r == NULL)
    return make_error ("lvm_canonical_lv_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_lvm_clear_filter (ETERM *message)
{
  int r;

  r = guestfs_lvm_clear_filter (g);
  if (r == -1)
    return make_error ("lvm_clear_filter");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvm_remove_all (ETERM *message)
{
  int r;

  r = guestfs_lvm_remove_all (g);
  if (r == -1)
    return make_error ("lvm_remove_all");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvm_set_filter (ETERM *message)
{
  char **devices = get_string_list (ARG (0));
  int r;

  r = guestfs_lvm_set_filter (g, devices);
  free_strings (devices);
  if (r == -1)
    return make_error ("lvm_set_filter");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvremove (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_lvremove (g, device);
  free (device);
  if (r == -1)
    return make_error ("lvremove");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvrename (ETERM *message)
{
  char *logvol = erl_iolist_to_string (ARG (0));
  char *newlogvol = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_lvrename (g, logvol, newlogvol);
  free (logvol);
  free (newlogvol);
  if (r == -1)
    return make_error ("lvrename");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvresize (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int mbytes = ERL_INT_VALUE (ARG (1));
  int r;

  r = guestfs_lvresize (g, device, mbytes);
  free (device);
  if (r == -1)
    return make_error ("lvresize");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvresize_free (ETERM *message)
{
  char *lv = erl_iolist_to_string (ARG (0));
  int percent = ERL_INT_VALUE (ARG (1));
  int r;

  r = guestfs_lvresize_free (g, lv, percent);
  free (lv);
  if (r == -1)
    return make_error ("lvresize_free");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvs (ETERM *message)
{
  char **r;

  r = guestfs_lvs (g);
  if (r == NULL)
    return make_error ("lvs");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_lvs_full (ETERM *message)
{
  struct guestfs_lvm_lv_list *r;

  r = guestfs_lvs_full (g);
  if (r == NULL)
    return make_error ("lvs_full");

  ETERM *rt = make_lvm_lv_list (r);
  guestfs_free_lvm_lv_list (r);
  return rt;
}

static ETERM *
run_lvuuid (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_lvuuid (g, device);
  free (device);
  if (r == NULL)
    return make_error ("lvuuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_lxattrlist (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char **names = get_string_list (ARG (1));
  struct guestfs_xattr_list *r;

  r = guestfs_lxattrlist (g, path, names);
  free (path);
  free_strings (names);
  if (r == NULL)
    return make_error ("lxattrlist");

  ETERM *rt = make_xattr_list (r);
  guestfs_free_xattr_list (r);
  return rt;
}

static ETERM *
run_md_create (ETERM *message)
{
  char *name = erl_iolist_to_string (ARG (0));
  char **devices = get_string_list (ARG (1));

  struct guestfs_md_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_md_create_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "missingbitmap")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
      optargs_s.missingbitmap = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "nrdevices")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
      optargs_s.nrdevices = ERL_INT_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "spare")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_SPARE_BITMASK;
      optargs_s.spare = ERL_INT_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "chunk")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_CHUNK_BITMASK;
      optargs_s.chunk = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "level")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_LEVEL_BITMASK;
      optargs_s.level = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("md_create", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_md_create_argv (g, name, devices, optargs);
  free (name);
  free_strings (devices);
  if ((optargs_s.bitmask & GUESTFS_MD_CREATE_LEVEL_BITMASK))
    free ((char *) optargs_s.level);
  if (r == -1)
    return make_error ("md_create");

  return erl_mk_atom ("ok");
}

static ETERM *
run_md_detail (ETERM *message)
{
  char *md = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_md_detail (g, md);
  free (md);
  if (r == NULL)
    return make_error ("md_detail");

  ETERM *rt = make_table (r);
  free_strings (r);
  return rt;
}

static ETERM *
run_md_stop (ETERM *message)
{
  char *md = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_md_stop (g, md);
  free (md);
  if (r == -1)
    return make_error ("md_stop");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkdir (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mkdir (g, path);
  free (path);
  if (r == -1)
    return make_error ("mkdir");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkdir_mode (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int mode = ERL_INT_VALUE (ARG (1));
  int r;

  r = guestfs_mkdir_mode (g, path, mode);
  free (path);
  if (r == -1)
    return make_error ("mkdir_mode");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkdir_p (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mkdir_p (g, path);
  free (path);
  if (r == -1)
    return make_error ("mkdir_p");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkdtemp (ETERM *message)
{
  char *tmpl = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_mkdtemp (g, tmpl);
  free (tmpl);
  if (r == NULL)
    return make_error ("mkdtemp");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_mke2fs_J (ETERM *message)
{
  char *fstype = erl_iolist_to_string (ARG (0));
  int blocksize = ERL_INT_VALUE (ARG (1));
  char *device = erl_iolist_to_string (ARG (2));
  char *journal = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);
  free (fstype);
  free (device);
  free (journal);
  if (r == -1)
    return make_error ("mke2fs_J");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mke2fs_JL (ETERM *message)
{
  char *fstype = erl_iolist_to_string (ARG (0));
  int blocksize = ERL_INT_VALUE (ARG (1));
  char *device = erl_iolist_to_string (ARG (2));
  char *label = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);
  free (fstype);
  free (device);
  free (label);
  if (r == -1)
    return make_error ("mke2fs_JL");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mke2fs_JU (ETERM *message)
{
  char *fstype = erl_iolist_to_string (ARG (0));
  int blocksize = ERL_INT_VALUE (ARG (1));
  char *device = erl_iolist_to_string (ARG (2));
  char *uuid = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);
  free (fstype);
  free (device);
  free (uuid);
  if (r == -1)
    return make_error ("mke2fs_JU");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mke2journal (ETERM *message)
{
  int blocksize = ERL_INT_VALUE (ARG (0));
  char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mke2journal (g, blocksize, device);
  free (device);
  if (r == -1)
    return make_error ("mke2journal");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mke2journal_L (ETERM *message)
{
  int blocksize = ERL_INT_VALUE (ARG (0));
  char *label = erl_iolist_to_string (ARG (1));
  char *device = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_mke2journal_L (g, blocksize, label, device);
  free (label);
  free (device);
  if (r == -1)
    return make_error ("mke2journal_L");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mke2journal_U (ETERM *message)
{
  int blocksize = ERL_INT_VALUE (ARG (0));
  char *uuid = erl_iolist_to_string (ARG (1));
  char *device = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_mke2journal_U (g, blocksize, uuid, device);
  free (uuid);
  free (device);
  if (r == -1)
    return make_error ("mke2journal_U");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkfifo (ETERM *message)
{
  int mode = ERL_INT_VALUE (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mkfifo (g, mode, path);
  free (path);
  if (r == -1)
    return make_error ("mkfifo");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkfs (ETERM *message)
{
  char *fstype = erl_iolist_to_string (ARG (0));
  char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mkfs (g, fstype, device);
  free (fstype);
  free (device);
  if (r == -1)
    return make_error ("mkfs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkfs_b (ETERM *message)
{
  char *fstype = erl_iolist_to_string (ARG (0));
  int blocksize = ERL_INT_VALUE (ARG (1));
  char *device = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_mkfs_b (g, fstype, blocksize, device);
  free (fstype);
  free (device);
  if (r == -1)
    return make_error ("mkfs_b");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkfs_opts (ETERM *message)
{
  char *fstype = erl_iolist_to_string (ARG (0));
  char *device = erl_iolist_to_string (ARG (1));

  struct guestfs_mkfs_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "blocksize")) {
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
      optargs_s.blocksize = ERL_INT_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "features")) {
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
      optargs_s.features = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "inode")) {
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_INODE_BITMASK;
      optargs_s.inode = ERL_INT_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "sectorsize")) {
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
      optargs_s.sectorsize = ERL_INT_VALUE (hd_value);
    }
    else
      return unknown_optarg ("mkfs_opts", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);
  free (fstype);
  free (device);
  if ((optargs_s.bitmask & GUESTFS_MKFS_OPTS_FEATURES_BITMASK))
    free ((char *) optargs_s.features);
  if (r == -1)
    return make_error ("mkfs_opts");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkmountpoint (ETERM *message)
{
  char *exemptpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mkmountpoint (g, exemptpath);
  free (exemptpath);
  if (r == -1)
    return make_error ("mkmountpoint");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mknod (ETERM *message)
{
  int mode = ERL_INT_VALUE (ARG (0));
  int devmajor = ERL_INT_VALUE (ARG (1));
  int devminor = ERL_INT_VALUE (ARG (2));
  char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mknod (g, mode, devmajor, devminor, path);
  free (path);
  if (r == -1)
    return make_error ("mknod");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mknod_b (ETERM *message)
{
  int mode = ERL_INT_VALUE (ARG (0));
  int devmajor = ERL_INT_VALUE (ARG (1));
  int devminor = ERL_INT_VALUE (ARG (2));
  char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);
  free (path);
  if (r == -1)
    return make_error ("mknod_b");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mknod_c (ETERM *message)
{
  int mode = ERL_INT_VALUE (ARG (0));
  int devmajor = ERL_INT_VALUE (ARG (1));
  int devminor = ERL_INT_VALUE (ARG (2));
  char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mknod_c (g, mode, devmajor, devminor, path);
  free (path);
  if (r == -1)
    return make_error ("mknod_c");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkswap (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mkswap (g, device);
  free (device);
  if (r == -1)
    return make_error ("mkswap");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkswap_L (ETERM *message)
{
  char *label = erl_iolist_to_string (ARG (0));
  char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mkswap_L (g, label, device);
  free (label);
  free (device);
  if (r == -1)
    return make_error ("mkswap_L");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkswap_U (ETERM *message)
{
  char *uuid = erl_iolist_to_string (ARG (0));
  char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mkswap_U (g, uuid, device);
  free (uuid);
  free (device);
  if (r == -1)
    return make_error ("mkswap_U");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkswap_file (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mkswap_file (g, path);
  free (path);
  if (r == -1)
    return make_error ("mkswap_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_modprobe (ETERM *message)
{
  char *modulename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_modprobe (g, modulename);
  free (modulename);
  if (r == -1)
    return make_error ("modprobe");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *mountpoint = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mount (g, device, mountpoint);
  free (device);
  free (mountpoint);
  if (r == -1)
    return make_error ("mount");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount_9p (ETERM *message)
{
  char *mounttag = erl_iolist_to_string (ARG (0));
  char *mountpoint = erl_iolist_to_string (ARG (1));

  struct guestfs_mount_9p_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_9p_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "options")) {
      optargs_s.bitmask |= GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
      optargs_s.options = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("mount_9p", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);
  free (mounttag);
  free (mountpoint);
  if ((optargs_s.bitmask & GUESTFS_MOUNT_9P_OPTIONS_BITMASK))
    free ((char *) optargs_s.options);
  if (r == -1)
    return make_error ("mount_9p");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount_loop (ETERM *message)
{
  char *file = erl_iolist_to_string (ARG (0));
  char *mountpoint = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mount_loop (g, file, mountpoint);
  free (file);
  free (mountpoint);
  if (r == -1)
    return make_error ("mount_loop");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount_options (ETERM *message)
{
  char *options = erl_iolist_to_string (ARG (0));
  char *device = erl_iolist_to_string (ARG (1));
  char *mountpoint = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_mount_options (g, options, device, mountpoint);
  free (options);
  free (device);
  free (mountpoint);
  if (r == -1)
    return make_error ("mount_options");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount_ro (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *mountpoint = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mount_ro (g, device, mountpoint);
  free (device);
  free (mountpoint);
  if (r == -1)
    return make_error ("mount_ro");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount_vfs (ETERM *message)
{
  char *options = erl_iolist_to_string (ARG (0));
  char *vfstype = erl_iolist_to_string (ARG (1));
  char *device = erl_iolist_to_string (ARG (2));
  char *mountpoint = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mount_vfs (g, options, vfstype, device, mountpoint);
  free (options);
  free (vfstype);
  free (device);
  free (mountpoint);
  if (r == -1)
    return make_error ("mount_vfs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mountpoints (ETERM *message)
{
  char **r;

  r = guestfs_mountpoints (g);
  if (r == NULL)
    return make_error ("mountpoints");

  ETERM *rt = make_table (r);
  free_strings (r);
  return rt;
}

static ETERM *
run_mounts (ETERM *message)
{
  char **r;

  r = guestfs_mounts (g);
  if (r == NULL)
    return make_error ("mounts");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_mv (ETERM *message)
{
  char *src = erl_iolist_to_string (ARG (0));
  char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mv (g, src, dest);
  free (src);
  free (dest);
  if (r == -1)
    return make_error ("mv");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ntfs_3g_probe (ETERM *message)
{
  int rw = get_bool (ARG (0));
  char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ntfs_3g_probe (g, rw, device);
  free (device);
  if (r == -1)
    return make_error ("ntfs_3g_probe");

  return erl_mk_int (r);
}

static ETERM *
run_ntfsresize (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_ntfsresize (g, device);
  free (device);
  if (r == -1)
    return make_error ("ntfsresize");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ntfsresize_opts (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_ntfsresize_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
      optargs_s.size = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "force")) {
      optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
      optargs_s.force = get_bool (hd_value);
    }
    else
      return unknown_optarg ("ntfsresize_opts", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_ntfsresize_opts_argv (g, device, optargs);
  free (device);
  if (r == -1)
    return make_error ("ntfsresize_opts");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ntfsresize_size (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int64_t size = ERL_LL_VALUE (ARG (1));
  int r;

  r = guestfs_ntfsresize_size (g, device, size);
  free (device);
  if (r == -1)
    return make_error ("ntfsresize_size");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_add (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *prlogex = erl_iolist_to_string (ARG (1));
  int64_t startsect = ERL_LL_VALUE (ARG (2));
  int64_t endsect = ERL_LL_VALUE (ARG (3));
  int r;

  r = guestfs_part_add (g, device, prlogex, startsect, endsect);
  free (device);
  free (prlogex);
  if (r == -1)
    return make_error ("part_add");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_del (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int partnum = ERL_INT_VALUE (ARG (1));
  int r;

  r = guestfs_part_del (g, device, partnum);
  free (device);
  if (r == -1)
    return make_error ("part_del");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_disk (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *parttype = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_part_disk (g, device, parttype);
  free (device);
  free (parttype);
  if (r == -1)
    return make_error ("part_disk");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_get_bootable (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int partnum = ERL_INT_VALUE (ARG (1));
  int r;

  r = guestfs_part_get_bootable (g, device, partnum);
  free (device);
  if (r == -1)
    return make_error ("part_get_bootable");

  return make_bool (r);
}

static ETERM *
run_part_get_mbr_id (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int partnum = ERL_INT_VALUE (ARG (1));
  int r;

  r = guestfs_part_get_mbr_id (g, device, partnum);
  free (device);
  if (r == -1)
    return make_error ("part_get_mbr_id");

  return erl_mk_int (r);
}

static ETERM *
run_part_get_parttype (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_part_get_parttype (g, device);
  free (device);
  if (r == NULL)
    return make_error ("part_get_parttype");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_part_init (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *parttype = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_part_init (g, device, parttype);
  free (device);
  free (parttype);
  if (r == -1)
    return make_error ("part_init");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_list (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  struct guestfs_partition_list *r;

  r = guestfs_part_list (g, device);
  free (device);
  if (r == NULL)
    return make_error ("part_list");

  ETERM *rt = make_partition_list (r);
  guestfs_free_partition_list (r);
  return rt;
}

static ETERM *
run_part_set_bootable (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int partnum = ERL_INT_VALUE (ARG (1));
  int bootable = get_bool (ARG (2));
  int r;

  r = guestfs_part_set_bootable (g, device, partnum, bootable);
  free (device);
  if (r == -1)
    return make_error ("part_set_bootable");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_set_mbr_id (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int partnum = ERL_INT_VALUE (ARG (1));
  int idbyte = ERL_INT_VALUE (ARG (2));
  int r;

  r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);
  free (device);
  if (r == -1)
    return make_error ("part_set_mbr_id");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_set_name (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int partnum = ERL_INT_VALUE (ARG (1));
  char *name = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_part_set_name (g, device, partnum, name);
  free (device);
  free (name);
  if (r == -1)
    return make_error ("part_set_name");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_to_dev (ETERM *message)
{
  char *partition = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_part_to_dev (g, partition);
  free (partition);
  if (r == NULL)
    return make_error ("part_to_dev");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_part_to_partnum (ETERM *message)
{
  char *partition = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_part_to_partnum (g, partition);
  free (partition);
  if (r == -1)
    return make_error ("part_to_partnum");

  return erl_mk_int (r);
}

static ETERM *
run_ping_daemon (ETERM *message)
{
  int r;

  r = guestfs_ping_daemon (g);
  if (r == -1)
    return make_error ("ping_daemon");

  return erl_mk_atom ("ok");
}

static ETERM *
run_pread (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int count = ERL_INT_VALUE (ARG (1));
  int64_t offset = ERL_LL_VALUE (ARG (2));
  char *r;
  size_t size;

  r = guestfs_pread (g, path, count, offset, &size);
  free (path);
  if (r == NULL)
    return make_error ("pread");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_pread_device (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int count = ERL_INT_VALUE (ARG (1));
  int64_t offset = ERL_LL_VALUE (ARG (2));
  char *r;
  size_t size;

  r = guestfs_pread_device (g, device, count, offset, &size);
  free (device);
  if (r == NULL)
    return make_error ("pread_device");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_pvcreate (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_pvcreate (g, device);
  free (device);
  if (r == -1)
    return make_error ("pvcreate");

  return erl_mk_atom ("ok");
}

static ETERM *
run_pvremove (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_pvremove (g, device);
  free (device);
  if (r == -1)
    return make_error ("pvremove");

  return erl_mk_atom ("ok");
}

static ETERM *
run_pvresize (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_pvresize (g, device);
  free (device);
  if (r == -1)
    return make_error ("pvresize");

  return erl_mk_atom ("ok");
}

static ETERM *
run_pvresize_size (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int64_t size = ERL_LL_VALUE (ARG (1));
  int r;

  r = guestfs_pvresize_size (g, device, size);
  free (device);
  if (r == -1)
    return make_error ("pvresize_size");

  return erl_mk_atom ("ok");
}

static ETERM *
run_pvs (ETERM *message)
{
  char **r;

  r = guestfs_pvs (g);
  if (r == NULL)
    return make_error ("pvs");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_pvs_full (ETERM *message)
{
  struct guestfs_lvm_pv_list *r;

  r = guestfs_pvs_full (g);
  if (r == NULL)
    return make_error ("pvs_full");

  ETERM *rt = make_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  return rt;
}

static ETERM *
run_pvuuid (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_pvuuid (g, device);
  free (device);
  if (r == NULL)
    return make_error ("pvuuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_pwrite (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  size_t content_size = erl_iolist_length (ARG (1));
  char *content = erl_iolist_to_string (ARG (1));
  int64_t offset = ERL_LL_VALUE (ARG (2));
  int r;

  r = guestfs_pwrite (g, path, content, content_size, offset);
  free (path);
  free (content);
  if (r == -1)
    return make_error ("pwrite");

  return erl_mk_int (r);
}

static ETERM *
run_pwrite_device (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  size_t content_size = erl_iolist_length (ARG (1));
  char *content = erl_iolist_to_string (ARG (1));
  int64_t offset = ERL_LL_VALUE (ARG (2));
  int r;

  r = guestfs_pwrite_device (g, device, content, content_size, offset);
  free (device);
  free (content);
  if (r == -1)
    return make_error ("pwrite_device");

  return erl_mk_int (r);
}

static ETERM *
run_read_file (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char *r;
  size_t size;

  r = guestfs_read_file (g, path, &size);
  free (path);
  if (r == NULL)
    return make_error ("read_file");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_read_lines (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_read_lines (g, path);
  free (path);
  if (r == NULL)
    return make_error ("read_lines");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_readdir (ETERM *message)
{
  char *dir = erl_iolist_to_string (ARG (0));
  struct guestfs_dirent_list *r;

  r = guestfs_readdir (g, dir);
  free (dir);
  if (r == NULL)
    return make_error ("readdir");

  ETERM *rt = make_dirent_list (r);
  guestfs_free_dirent_list (r);
  return rt;
}

static ETERM *
run_readlink (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_readlink (g, path);
  free (path);
  if (r == NULL)
    return make_error ("readlink");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_readlinklist (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char **names = get_string_list (ARG (1));
  char **r;

  r = guestfs_readlinklist (g, path, names);
  free (path);
  free_strings (names);
  if (r == NULL)
    return make_error ("readlinklist");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_realpath (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_realpath (g, path);
  free (path);
  if (r == NULL)
    return make_error ("realpath");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_removexattr (ETERM *message)
{
  char *xattr = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_removexattr (g, xattr, path);
  free (xattr);
  free (path);
  if (r == -1)
    return make_error ("removexattr");

  return erl_mk_atom ("ok");
}

static ETERM *
run_resize2fs (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_resize2fs (g, device);
  free (device);
  if (r == -1)
    return make_error ("resize2fs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_resize2fs_M (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_resize2fs_M (g, device);
  free (device);
  if (r == -1)
    return make_error ("resize2fs_M");

  return erl_mk_atom ("ok");
}

static ETERM *
run_resize2fs_size (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int64_t size = ERL_LL_VALUE (ARG (1));
  int r;

  r = guestfs_resize2fs_size (g, device, size);
  free (device);
  if (r == -1)
    return make_error ("resize2fs_size");

  return erl_mk_atom ("ok");
}

static ETERM *
run_rm (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rm (g, path);
  free (path);
  if (r == -1)
    return make_error ("rm");

  return erl_mk_atom ("ok");
}

static ETERM *
run_rm_rf (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rm_rf (g, path);
  free (path);
  if (r == -1)
    return make_error ("rm_rf");

  return erl_mk_atom ("ok");
}

static ETERM *
run_rmdir (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rmdir (g, path);
  free (path);
  if (r == -1)
    return make_error ("rmdir");

  return erl_mk_atom ("ok");
}

static ETERM *
run_rmmountpoint (ETERM *message)
{
  char *exemptpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rmmountpoint (g, exemptpath);
  free (exemptpath);
  if (r == -1)
    return make_error ("rmmountpoint");

  return erl_mk_atom ("ok");
}

static ETERM *
run_scrub_device (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_scrub_device (g, device);
  free (device);
  if (r == -1)
    return make_error ("scrub_device");

  return erl_mk_atom ("ok");
}

static ETERM *
run_scrub_file (ETERM *message)
{
  char *file = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_scrub_file (g, file);
  free (file);
  if (r == -1)
    return make_error ("scrub_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_scrub_freespace (ETERM *message)
{
  char *dir = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_scrub_freespace (g, dir);
  free (dir);
  if (r == -1)
    return make_error ("scrub_freespace");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_append (ETERM *message)
{
  char *append;
  if (atom_equals (ARG (0), "undefined"))
    append = NULL;
  else
    append = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_append (g, append);
  free (append);
  if (r == -1)
    return make_error ("set_append");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_attach_method (ETERM *message)
{
  char *attachmethod = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_attach_method (g, attachmethod);
  free (attachmethod);
  if (r == -1)
    return make_error ("set_attach_method");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_autosync (ETERM *message)
{
  int autosync = get_bool (ARG (0));
  int r;

  r = guestfs_set_autosync (g, autosync);
  if (r == -1)
    return make_error ("set_autosync");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_direct (ETERM *message)
{
  int direct = get_bool (ARG (0));
  int r;

  r = guestfs_set_direct (g, direct);
  if (r == -1)
    return make_error ("set_direct");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_e2label (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *label = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_set_e2label (g, device, label);
  free (device);
  free (label);
  if (r == -1)
    return make_error ("set_e2label");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_e2uuid (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *uuid = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_set_e2uuid (g, device, uuid);
  free (device);
  free (uuid);
  if (r == -1)
    return make_error ("set_e2uuid");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_memsize (ETERM *message)
{
  int memsize = ERL_INT_VALUE (ARG (0));
  int r;

  r = guestfs_set_memsize (g, memsize);
  if (r == -1)
    return make_error ("set_memsize");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_network (ETERM *message)
{
  int network = get_bool (ARG (0));
  int r;

  r = guestfs_set_network (g, network);
  if (r == -1)
    return make_error ("set_network");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_path (ETERM *message)
{
  char *searchpath;
  if (atom_equals (ARG (0), "undefined"))
    searchpath = NULL;
  else
    searchpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_path (g, searchpath);
  free (searchpath);
  if (r == -1)
    return make_error ("set_path");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_pgroup (ETERM *message)
{
  int pgroup = get_bool (ARG (0));
  int r;

  r = guestfs_set_pgroup (g, pgroup);
  if (r == -1)
    return make_error ("set_pgroup");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_qemu (ETERM *message)
{
  char *qemu;
  if (atom_equals (ARG (0), "undefined"))
    qemu = NULL;
  else
    qemu = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_qemu (g, qemu);
  free (qemu);
  if (r == -1)
    return make_error ("set_qemu");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_recovery_proc (ETERM *message)
{
  int recoveryproc = get_bool (ARG (0));
  int r;

  r = guestfs_set_recovery_proc (g, recoveryproc);
  if (r == -1)
    return make_error ("set_recovery_proc");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_selinux (ETERM *message)
{
  int selinux = get_bool (ARG (0));
  int r;

  r = guestfs_set_selinux (g, selinux);
  if (r == -1)
    return make_error ("set_selinux");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_smp (ETERM *message)
{
  int smp = ERL_INT_VALUE (ARG (0));
  int r;

  r = guestfs_set_smp (g, smp);
  if (r == -1)
    return make_error ("set_smp");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_trace (ETERM *message)
{
  int trace = get_bool (ARG (0));
  int r;

  r = guestfs_set_trace (g, trace);
  if (r == -1)
    return make_error ("set_trace");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_verbose (ETERM *message)
{
  int verbose = get_bool (ARG (0));
  int r;

  r = guestfs_set_verbose (g, verbose);
  if (r == -1)
    return make_error ("set_verbose");

  return erl_mk_atom ("ok");
}

static ETERM *
run_setcon (ETERM *message)
{
  char *context = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_setcon (g, context);
  free (context);
  if (r == -1)
    return make_error ("setcon");

  return erl_mk_atom ("ok");
}

static ETERM *
run_setxattr (ETERM *message)
{
  char *xattr = erl_iolist_to_string (ARG (0));
  char *val = erl_iolist_to_string (ARG (1));
  int vallen = ERL_INT_VALUE (ARG (2));
  char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_setxattr (g, xattr, val, vallen, path);
  free (xattr);
  free (val);
  free (path);
  if (r == -1)
    return make_error ("setxattr");

  return erl_mk_atom ("ok");
}

static ETERM *
run_sfdisk (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int cyls = ERL_INT_VALUE (ARG (1));
  int heads = ERL_INT_VALUE (ARG (2));
  int sectors = ERL_INT_VALUE (ARG (3));
  char **lines = get_string_list (ARG (4));
  int r;

  r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);
  free (device);
  free_strings (lines);
  if (r == -1)
    return make_error ("sfdisk");

  return erl_mk_atom ("ok");
}

static ETERM *
run_sfdiskM (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char **lines = get_string_list (ARG (1));
  int r;

  r = guestfs_sfdiskM (g, device, lines);
  free (device);
  free_strings (lines);
  if (r == -1)
    return make_error ("sfdiskM");

  return erl_mk_atom ("ok");
}

static ETERM *
run_sfdisk_N (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int partnum = ERL_INT_VALUE (ARG (1));
  int cyls = ERL_INT_VALUE (ARG (2));
  int heads = ERL_INT_VALUE (ARG (3));
  int sectors = ERL_INT_VALUE (ARG (4));
  char *line = erl_iolist_to_string (ARG (5));
  int r;

  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  free (device);
  free (line);
  if (r == -1)
    return make_error ("sfdisk_N");

  return erl_mk_atom ("ok");
}

static ETERM *
run_sfdisk_disk_geometry (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_sfdisk_disk_geometry (g, device);
  free (device);
  if (r == NULL)
    return make_error ("sfdisk_disk_geometry");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_sfdisk_kernel_geometry (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_sfdisk_kernel_geometry (g, device);
  free (device);
  if (r == NULL)
    return make_error ("sfdisk_kernel_geometry");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_sfdisk_l (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_sfdisk_l (g, device);
  free (device);
  if (r == NULL)
    return make_error ("sfdisk_l");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_sh (ETERM *message)
{
  char *command = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_sh (g, command);
  free (command);
  if (r == NULL)
    return make_error ("sh");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_sh_lines (ETERM *message)
{
  char *command = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_sh_lines (g, command);
  free (command);
  if (r == NULL)
    return make_error ("sh_lines");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_sleep (ETERM *message)
{
  int secs = ERL_INT_VALUE (ARG (0));
  int r;

  r = guestfs_sleep (g, secs);
  if (r == -1)
    return make_error ("sleep");

  return erl_mk_atom ("ok");
}

static ETERM *
run_stat (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_stat *r;

  r = guestfs_stat (g, path);
  free (path);
  if (r == NULL)
    return make_error ("stat");

  ETERM *rt = make_stat (r);
  guestfs_free_stat (r);
  return rt;
}

static ETERM *
run_statvfs (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_statvfs *r;

  r = guestfs_statvfs (g, path);
  free (path);
  if (r == NULL)
    return make_error ("statvfs");

  ETERM *rt = make_statvfs (r);
  guestfs_free_statvfs (r);
  return rt;
}

static ETERM *
run_strings (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_strings (g, path);
  free (path);
  if (r == NULL)
    return make_error ("strings");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_strings_e (ETERM *message)
{
  char *encoding = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_strings_e (g, encoding, path);
  free (encoding);
  free (path);
  if (r == NULL)
    return make_error ("strings_e");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_swapoff_device (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapoff_device (g, device);
  free (device);
  if (r == -1)
    return make_error ("swapoff_device");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapoff_file (ETERM *message)
{
  char *file = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapoff_file (g, file);
  free (file);
  if (r == -1)
    return make_error ("swapoff_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapoff_label (ETERM *message)
{
  char *label = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapoff_label (g, label);
  free (label);
  if (r == -1)
    return make_error ("swapoff_label");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapoff_uuid (ETERM *message)
{
  char *uuid = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapoff_uuid (g, uuid);
  free (uuid);
  if (r == -1)
    return make_error ("swapoff_uuid");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapon_device (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapon_device (g, device);
  free (device);
  if (r == -1)
    return make_error ("swapon_device");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapon_file (ETERM *message)
{
  char *file = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapon_file (g, file);
  free (file);
  if (r == -1)
    return make_error ("swapon_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapon_label (ETERM *message)
{
  char *label = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapon_label (g, label);
  free (label);
  if (r == -1)
    return make_error ("swapon_label");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapon_uuid (ETERM *message)
{
  char *uuid = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapon_uuid (g, uuid);
  free (uuid);
  if (r == -1)
    return make_error ("swapon_uuid");

  return erl_mk_atom ("ok");
}

static ETERM *
run_sync (ETERM *message)
{
  int r;

  r = guestfs_sync (g);
  if (r == -1)
    return make_error ("sync");

  return erl_mk_atom ("ok");
}

static ETERM *
run_tail (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_tail (g, path);
  free (path);
  if (r == NULL)
    return make_error ("tail");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_tail_n (ETERM *message)
{
  int nrlines = ERL_INT_VALUE (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_tail_n (g, nrlines, path);
  free (path);
  if (r == NULL)
    return make_error ("tail_n");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_tar_in (ETERM *message)
{
  char *tarfile = erl_iolist_to_string (ARG (0));
  char *directory = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_tar_in (g, tarfile, directory);
  free (tarfile);
  free (directory);
  if (r == -1)
    return make_error ("tar_in");

  return erl_mk_atom ("ok");
}

static ETERM *
run_tar_out (ETERM *message)
{
  char *directory = erl_iolist_to_string (ARG (0));
  char *tarfile = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_tar_out (g, directory, tarfile);
  free (directory);
  free (tarfile);
  if (r == -1)
    return make_error ("tar_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_test0 (ETERM *message)
{
  char *str = erl_iolist_to_string (ARG (0));
  char *optstr;
  if (atom_equals (ARG (1), "undefined"))
    optstr = NULL;
  else
    optstr = erl_iolist_to_string (ARG (1));
  char **strlist = get_string_list (ARG (2));
  int b = get_bool (ARG (3));
  int integer = ERL_INT_VALUE (ARG (4));
  int64_t integer64 = ERL_LL_VALUE (ARG (5));
  char *filein = erl_iolist_to_string (ARG (6));
  char *fileout = erl_iolist_to_string (ARG (7));
  size_t bufferin_size = erl_iolist_length (ARG (8));
  char *bufferin = erl_iolist_to_string (ARG (8));

  struct guestfs_test0_argv optargs_s = { .bitmask = 0 };
  struct guestfs_test0_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (9);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "obool")) {
      optargs_s.bitmask |= GUESTFS_TEST0_OBOOL_BITMASK;
      optargs_s.obool = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "oint")) {
      optargs_s.bitmask |= GUESTFS_TEST0_OINT_BITMASK;
      optargs_s.oint = ERL_INT_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "oint64")) {
      optargs_s.bitmask |= GUESTFS_TEST0_OINT64_BITMASK;
      optargs_s.oint64 = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "ostring")) {
      optargs_s.bitmask |= GUESTFS_TEST0_OSTRING_BITMASK;
      optargs_s.ostring = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("test0", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_test0_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);
  free (str);
  free (optstr);
  free_strings (strlist);
  free (filein);
  free (fileout);
  free (bufferin);
  if ((optargs_s.bitmask & GUESTFS_TEST0_OSTRING_BITMASK))
    free ((char *) optargs_s.ostring);
  if (r == -1)
    return make_error ("test0");

  return erl_mk_atom ("ok");
}

static ETERM *
run_test0rbool (ETERM *message)
{
  char *val = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_test0rbool (g, val);
  free (val);
  if (r == -1)
    return make_error ("test0rbool");

  return make_bool (r);
}

static ETERM *
run_test0rboolerr (ETERM *message)
{
  int r;

  r = guestfs_test0rboolerr (g);
  if (r == -1)
    return make_error ("test0rboolerr");

  return make_bool (r);
}

static ETERM *
run_test0rbufferout (ETERM *message)
{
  char *val = erl_iolist_to_string (ARG (0));
  char *r;
  size_t size;

  r = guestfs_test0rbufferout (g, val, &size);
  free (val);
  if (r == NULL)
    return make_error ("test0rbufferout");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_test0rbufferouterr (ETERM *message)
{
  char *r;
  size_t size;

  r = guestfs_test0rbufferouterr (g, &size);
  if (r == NULL)
    return make_error ("test0rbufferouterr");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_test0rconstoptstring (ETERM *message)
{
  char *val = erl_iolist_to_string (ARG (0));
  const char *r;

  r = guestfs_test0rconstoptstring (g, val);
  free (val);

  ETERM *rt;
  if (r)
    rt = erl_mk_string (r);
  else
    rt = erl_mk_atom ("undefined");
  return rt;
}

static ETERM *
run_test0rconstoptstringerr (ETERM *message)
{
  const char *r;

  r = guestfs_test0rconstoptstringerr (g);

  ETERM *rt;
  if (r)
    rt = erl_mk_string (r);
  else
    rt = erl_mk_atom ("undefined");
  return rt;
}

static ETERM *
run_test0rconststring (ETERM *message)
{
  char *val = erl_iolist_to_string (ARG (0));
  const char *r;

  r = guestfs_test0rconststring (g, val);
  free (val);
  if (r == NULL)
    return make_error ("test0rconststring");

  return erl_mk_string (r);
}

static ETERM *
run_test0rconststringerr (ETERM *message)
{
  const char *r;

  r = guestfs_test0rconststringerr (g);
  if (r == NULL)
    return make_error ("test0rconststringerr");

  return erl_mk_string (r);
}

static ETERM *
run_test0rhashtable (ETERM *message)
{
  char *val = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_test0rhashtable (g, val);
  free (val);
  if (r == NULL)
    return make_error ("test0rhashtable");

  ETERM *rt = make_table (r);
  free_strings (r);
  return rt;
}

static ETERM *
run_test0rhashtableerr (ETERM *message)
{
  char **r;

  r = guestfs_test0rhashtableerr (g);
  if (r == NULL)
    return make_error ("test0rhashtableerr");

  ETERM *rt = make_table (r);
  free_strings (r);
  return rt;
}

static ETERM *
run_test0rint (ETERM *message)
{
  char *val = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_test0rint (g, val);
  free (val);
  if (r == -1)
    return make_error ("test0rint");

  return erl_mk_int (r);
}

static ETERM *
run_test0rint64 (ETERM *message)
{
  char *val = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_test0rint64 (g, val);
  free (val);
  if (r == -1)
    return make_error ("test0rint64");

  return erl_mk_longlong (r);
}

static ETERM *
run_test0rint64err (ETERM *message)
{
  int64_t r;

  r = guestfs_test0rint64err (g);
  if (r == -1)
    return make_error ("test0rint64err");

  return erl_mk_longlong (r);
}

static ETERM *
run_test0rinterr (ETERM *message)
{
  int r;

  r = guestfs_test0rinterr (g);
  if (r == -1)
    return make_error ("test0rinterr");

  return erl_mk_int (r);
}

static ETERM *
run_test0rstring (ETERM *message)
{
  char *val = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_test0rstring (g, val);
  free (val);
  if (r == NULL)
    return make_error ("test0rstring");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_test0rstringerr (ETERM *message)
{
  char *r;

  r = guestfs_test0rstringerr (g);
  if (r == NULL)
    return make_error ("test0rstringerr");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_test0rstringlist (ETERM *message)
{
  char *val = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_test0rstringlist (g, val);
  free (val);
  if (r == NULL)
    return make_error ("test0rstringlist");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_test0rstringlisterr (ETERM *message)
{
  char **r;

  r = guestfs_test0rstringlisterr (g);
  if (r == NULL)
    return make_error ("test0rstringlisterr");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_test0rstruct (ETERM *message)
{
  char *val = erl_iolist_to_string (ARG (0));
  struct guestfs_lvm_pv *r;

  r = guestfs_test0rstruct (g, val);
  free (val);
  if (r == NULL)
    return make_error ("test0rstruct");

  ETERM *rt = make_lvm_pv (r);
  guestfs_free_lvm_pv (r);
  return rt;
}

static ETERM *
run_test0rstructerr (ETERM *message)
{
  struct guestfs_lvm_pv *r;

  r = guestfs_test0rstructerr (g);
  if (r == NULL)
    return make_error ("test0rstructerr");

  ETERM *rt = make_lvm_pv (r);
  guestfs_free_lvm_pv (r);
  return rt;
}

static ETERM *
run_test0rstructlist (ETERM *message)
{
  char *val = erl_iolist_to_string (ARG (0));
  struct guestfs_lvm_pv_list *r;

  r = guestfs_test0rstructlist (g, val);
  free (val);
  if (r == NULL)
    return make_error ("test0rstructlist");

  ETERM *rt = make_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  return rt;
}

static ETERM *
run_test0rstructlisterr (ETERM *message)
{
  struct guestfs_lvm_pv_list *r;

  r = guestfs_test0rstructlisterr (g);
  if (r == NULL)
    return make_error ("test0rstructlisterr");

  ETERM *rt = make_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  return rt;
}

static ETERM *
run_tgz_in (ETERM *message)
{
  char *tarball = erl_iolist_to_string (ARG (0));
  char *directory = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_tgz_in (g, tarball, directory);
  free (tarball);
  free (directory);
  if (r == -1)
    return make_error ("tgz_in");

  return erl_mk_atom ("ok");
}

static ETERM *
run_tgz_out (ETERM *message)
{
  char *directory = erl_iolist_to_string (ARG (0));
  char *tarball = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_tgz_out (g, directory, tarball);
  free (directory);
  free (tarball);
  if (r == -1)
    return make_error ("tgz_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_touch (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_touch (g, path);
  free (path);
  if (r == -1)
    return make_error ("touch");

  return erl_mk_atom ("ok");
}

static ETERM *
run_truncate (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_truncate (g, path);
  free (path);
  if (r == -1)
    return make_error ("truncate");

  return erl_mk_atom ("ok");
}

static ETERM *
run_truncate_size (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int64_t size = ERL_LL_VALUE (ARG (1));
  int r;

  r = guestfs_truncate_size (g, path, size);
  free (path);
  if (r == -1)
    return make_error ("truncate_size");

  return erl_mk_atom ("ok");
}

static ETERM *
run_tune2fs (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_tune2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tune2fs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "force")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_FORCE_BITMASK;
      optargs_s.force = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "maxmountcount")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
      optargs_s.maxmountcount = ERL_INT_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "mountcount")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
      optargs_s.mountcount = ERL_INT_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "errorbehavior")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK;
      optargs_s.errorbehavior = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "group")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_GROUP_BITMASK;
      optargs_s.group = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "intervalbetweenchecks")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
      optargs_s.intervalbetweenchecks = ERL_INT_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "reservedblockspercentage")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
      optargs_s.reservedblockspercentage = ERL_INT_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "lastmounteddirectory")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK;
      optargs_s.lastmounteddirectory = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "reservedblockscount")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
      optargs_s.reservedblockscount = ERL_LL_VALUE (hd_value);
    }
    else
    if (atom_equals (hd_name, "user")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_USER_BITMASK;
      optargs_s.user = ERL_LL_VALUE (hd_value);
    }
    else
      return unknown_optarg ("tune2fs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_tune2fs_argv (g, device, optargs);
  free (device);
  if ((optargs_s.bitmask & GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK))
    free ((char *) optargs_s.errorbehavior);
  if ((optargs_s.bitmask & GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK))
    free ((char *) optargs_s.lastmounteddirectory);
  if (r == -1)
    return make_error ("tune2fs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_tune2fs_l (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_tune2fs_l (g, device);
  free (device);
  if (r == NULL)
    return make_error ("tune2fs_l");

  ETERM *rt = make_table (r);
  free_strings (r);
  return rt;
}

static ETERM *
run_txz_in (ETERM *message)
{
  char *tarball = erl_iolist_to_string (ARG (0));
  char *directory = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_txz_in (g, tarball, directory);
  free (tarball);
  free (directory);
  if (r == -1)
    return make_error ("txz_in");

  return erl_mk_atom ("ok");
}

static ETERM *
run_txz_out (ETERM *message)
{
  char *directory = erl_iolist_to_string (ARG (0));
  char *tarball = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_txz_out (g, directory, tarball);
  free (directory);
  free (tarball);
  if (r == -1)
    return make_error ("txz_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_umask (ETERM *message)
{
  int mask = ERL_INT_VALUE (ARG (0));
  int r;

  r = guestfs_umask (g, mask);
  if (r == -1)
    return make_error ("umask");

  return erl_mk_int (r);
}

static ETERM *
run_umount (ETERM *message)
{
  char *pathordevice = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_umount (g, pathordevice);
  free (pathordevice);
  if (r == -1)
    return make_error ("umount");

  return erl_mk_atom ("ok");
}

static ETERM *
run_umount_all (ETERM *message)
{
  int r;

  r = guestfs_umount_all (g);
  if (r == -1)
    return make_error ("umount_all");

  return erl_mk_atom ("ok");
}

static ETERM *
run_upload (ETERM *message)
{
  char *filename = erl_iolist_to_string (ARG (0));
  char *remotefilename = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_upload (g, filename, remotefilename);
  free (filename);
  free (remotefilename);
  if (r == -1)
    return make_error ("upload");

  return erl_mk_atom ("ok");
}

static ETERM *
run_upload_offset (ETERM *message)
{
  char *filename = erl_iolist_to_string (ARG (0));
  char *remotefilename = erl_iolist_to_string (ARG (1));
  int64_t offset = ERL_LL_VALUE (ARG (2));
  int r;

  r = guestfs_upload_offset (g, filename, remotefilename, offset);
  free (filename);
  free (remotefilename);
  if (r == -1)
    return make_error ("upload_offset");

  return erl_mk_atom ("ok");
}

static ETERM *
run_utimens (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int64_t atsecs = ERL_LL_VALUE (ARG (1));
  int64_t atnsecs = ERL_LL_VALUE (ARG (2));
  int64_t mtsecs = ERL_LL_VALUE (ARG (3));
  int64_t mtnsecs = ERL_LL_VALUE (ARG (4));
  int r;

  r = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);
  free (path);
  if (r == -1)
    return make_error ("utimens");

  return erl_mk_atom ("ok");
}

static ETERM *
run_version (ETERM *message)
{
  struct guestfs_version *r;

  r = guestfs_version (g);
  if (r == NULL)
    return make_error ("version");

  ETERM *rt = make_version (r);
  guestfs_free_version (r);
  return rt;
}

static ETERM *
run_vfs_label (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_vfs_label (g, device);
  free (device);
  if (r == NULL)
    return make_error ("vfs_label");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_vfs_type (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_vfs_type (g, device);
  free (device);
  if (r == NULL)
    return make_error ("vfs_type");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_vfs_uuid (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_vfs_uuid (g, device);
  free (device);
  if (r == NULL)
    return make_error ("vfs_uuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_vg_activate (ETERM *message)
{
  int activate = get_bool (ARG (0));
  char **volgroups = get_string_list (ARG (1));
  int r;

  r = guestfs_vg_activate (g, activate, volgroups);
  free_strings (volgroups);
  if (r == -1)
    return make_error ("vg_activate");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vg_activate_all (ETERM *message)
{
  int activate = get_bool (ARG (0));
  int r;

  r = guestfs_vg_activate_all (g, activate);
  if (r == -1)
    return make_error ("vg_activate_all");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vgcreate (ETERM *message)
{
  char *volgroup = erl_iolist_to_string (ARG (0));
  char **physvols = get_string_list (ARG (1));
  int r;

  r = guestfs_vgcreate (g, volgroup, physvols);
  free (volgroup);
  free_strings (physvols);
  if (r == -1)
    return make_error ("vgcreate");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vglvuuids (ETERM *message)
{
  char *vgname = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_vglvuuids (g, vgname);
  free (vgname);
  if (r == NULL)
    return make_error ("vglvuuids");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_vgpvuuids (ETERM *message)
{
  char *vgname = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_vgpvuuids (g, vgname);
  free (vgname);
  if (r == NULL)
    return make_error ("vgpvuuids");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_vgremove (ETERM *message)
{
  char *vgname = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_vgremove (g, vgname);
  free (vgname);
  if (r == -1)
    return make_error ("vgremove");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vgrename (ETERM *message)
{
  char *volgroup = erl_iolist_to_string (ARG (0));
  char *newvolgroup = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_vgrename (g, volgroup, newvolgroup);
  free (volgroup);
  free (newvolgroup);
  if (r == -1)
    return make_error ("vgrename");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vgs (ETERM *message)
{
  char **r;

  r = guestfs_vgs (g);
  if (r == NULL)
    return make_error ("vgs");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_vgs_full (ETERM *message)
{
  struct guestfs_lvm_vg_list *r;

  r = guestfs_vgs_full (g);
  if (r == NULL)
    return make_error ("vgs_full");

  ETERM *rt = make_lvm_vg_list (r);
  guestfs_free_lvm_vg_list (r);
  return rt;
}

static ETERM *
run_vgscan (ETERM *message)
{
  int r;

  r = guestfs_vgscan (g);
  if (r == -1)
    return make_error ("vgscan");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vguuid (ETERM *message)
{
  char *vgname = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_vguuid (g, vgname);
  free (vgname);
  if (r == NULL)
    return make_error ("vguuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_wait_ready (ETERM *message)
{
  int r;

  r = guestfs_wait_ready (g);
  if (r == -1)
    return make_error ("wait_ready");

  return erl_mk_atom ("ok");
}

static ETERM *
run_wc_c (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_wc_c (g, path);
  free (path);
  if (r == -1)
    return make_error ("wc_c");

  return erl_mk_int (r);
}

static ETERM *
run_wc_l (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_wc_l (g, path);
  free (path);
  if (r == -1)
    return make_error ("wc_l");

  return erl_mk_int (r);
}

static ETERM *
run_wc_w (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_wc_w (g, path);
  free (path);
  if (r == -1)
    return make_error ("wc_w");

  return erl_mk_int (r);
}

static ETERM *
run_write (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  size_t content_size = erl_iolist_length (ARG (1));
  char *content = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_write (g, path, content, content_size);
  free (path);
  free (content);
  if (r == -1)
    return make_error ("write");

  return erl_mk_atom ("ok");
}

static ETERM *
run_write_append (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  size_t content_size = erl_iolist_length (ARG (1));
  char *content = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_write_append (g, path, content, content_size);
  free (path);
  free (content);
  if (r == -1)
    return make_error ("write_append");

  return erl_mk_atom ("ok");
}

static ETERM *
run_write_file (ETERM *message)
{
  char *path = erl_iolist_to_string (ARG (0));
  char *content = erl_iolist_to_string (ARG (1));
  int size = ERL_INT_VALUE (ARG (2));
  int r;

  r = guestfs_write_file (g, path, content, size);
  free (path);
  free (content);
  if (r == -1)
    return make_error ("write_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_zegrep (ETERM *message)
{
  char *regex = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zegrep (g, regex, path);
  free (regex);
  free (path);
  if (r == NULL)
    return make_error ("zegrep");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_zegrepi (ETERM *message)
{
  char *regex = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zegrepi (g, regex, path);
  free (regex);
  free (path);
  if (r == NULL)
    return make_error ("zegrepi");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_zero (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_zero (g, device);
  free (device);
  if (r == -1)
    return make_error ("zero");

  return erl_mk_atom ("ok");
}

static ETERM *
run_zero_device (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_zero_device (g, device);
  free (device);
  if (r == -1)
    return make_error ("zero_device");

  return erl_mk_atom ("ok");
}

static ETERM *
run_zerofree (ETERM *message)
{
  char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_zerofree (g, device);
  free (device);
  if (r == -1)
    return make_error ("zerofree");

  return erl_mk_atom ("ok");
}

static ETERM *
run_zfgrep (ETERM *message)
{
  char *pattern = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zfgrep (g, pattern, path);
  free (pattern);
  free (path);
  if (r == NULL)
    return make_error ("zfgrep");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_zfgrepi (ETERM *message)
{
  char *pattern = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zfgrepi (g, pattern, path);
  free (pattern);
  free (path);
  if (r == NULL)
    return make_error ("zfgrepi");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_zfile (ETERM *message)
{
  char *meth = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_zfile (g, meth, path);
  free (meth);
  free (path);
  if (r == NULL)
    return make_error ("zfile");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_zgrep (ETERM *message)
{
  char *regex = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zgrep (g, regex, path);
  free (regex);
  free (path);
  if (r == NULL)
    return make_error ("zgrep");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}

static ETERM *
run_zgrepi (ETERM *message)
{
  char *regex = erl_iolist_to_string (ARG (0));
  char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zgrepi (g, regex, path);
  free (regex);
  free (path);
  if (r == NULL)
    return make_error ("zgrepi");

  ETERM *rt = make_string_list (r);
  free_strings (r);

  return rt;
}


ETERM *
dispatch (ETERM *message)
{
  ETERM *fun;

  fun = ERL_TUPLE_ELEMENT (message, 0);

  /* XXX We should use gperf here. */
  if (atom_equals (fun, "add_cdrom"))
    return run_add_cdrom (message);
  else if (atom_equals (fun, "add_domain"))
    return run_add_domain (message);
  else if (atom_equals (fun, "add_drive"))
    return run_add_drive (message);
  else if (atom_equals (fun, "add_drive_opts"))
    return run_add_drive_opts (message);
  else if (atom_equals (fun, "add_drive_ro"))
    return run_add_drive_ro (message);
  else if (atom_equals (fun, "add_drive_ro_with_if"))
    return run_add_drive_ro_with_if (message);
  else if (atom_equals (fun, "add_drive_with_if"))
    return run_add_drive_with_if (message);
  else if (atom_equals (fun, "aug_clear"))
    return run_aug_clear (message);
  else if (atom_equals (fun, "aug_close"))
    return run_aug_close (message);
  else if (atom_equals (fun, "aug_defnode"))
    return run_aug_defnode (message);
  else if (atom_equals (fun, "aug_defvar"))
    return run_aug_defvar (message);
  else if (atom_equals (fun, "aug_get"))
    return run_aug_get (message);
  else if (atom_equals (fun, "aug_init"))
    return run_aug_init (message);
  else if (atom_equals (fun, "aug_insert"))
    return run_aug_insert (message);
  else if (atom_equals (fun, "aug_load"))
    return run_aug_load (message);
  else if (atom_equals (fun, "aug_ls"))
    return run_aug_ls (message);
  else if (atom_equals (fun, "aug_match"))
    return run_aug_match (message);
  else if (atom_equals (fun, "aug_mv"))
    return run_aug_mv (message);
  else if (atom_equals (fun, "aug_rm"))
    return run_aug_rm (message);
  else if (atom_equals (fun, "aug_save"))
    return run_aug_save (message);
  else if (atom_equals (fun, "aug_set"))
    return run_aug_set (message);
  else if (atom_equals (fun, "available"))
    return run_available (message);
  else if (atom_equals (fun, "available_all_groups"))
    return run_available_all_groups (message);
  else if (atom_equals (fun, "base64_in"))
    return run_base64_in (message);
  else if (atom_equals (fun, "base64_out"))
    return run_base64_out (message);
  else if (atom_equals (fun, "blkid"))
    return run_blkid (message);
  else if (atom_equals (fun, "blockdev_flushbufs"))
    return run_blockdev_flushbufs (message);
  else if (atom_equals (fun, "blockdev_getbsz"))
    return run_blockdev_getbsz (message);
  else if (atom_equals (fun, "blockdev_getro"))
    return run_blockdev_getro (message);
  else if (atom_equals (fun, "blockdev_getsize64"))
    return run_blockdev_getsize64 (message);
  else if (atom_equals (fun, "blockdev_getss"))
    return run_blockdev_getss (message);
  else if (atom_equals (fun, "blockdev_getsz"))
    return run_blockdev_getsz (message);
  else if (atom_equals (fun, "blockdev_rereadpt"))
    return run_blockdev_rereadpt (message);
  else if (atom_equals (fun, "blockdev_setbsz"))
    return run_blockdev_setbsz (message);
  else if (atom_equals (fun, "blockdev_setro"))
    return run_blockdev_setro (message);
  else if (atom_equals (fun, "blockdev_setrw"))
    return run_blockdev_setrw (message);
  else if (atom_equals (fun, "btrfs_filesystem_resize"))
    return run_btrfs_filesystem_resize (message);
  else if (atom_equals (fun, "case_sensitive_path"))
    return run_case_sensitive_path (message);
  else if (atom_equals (fun, "cat"))
    return run_cat (message);
  else if (atom_equals (fun, "checksum"))
    return run_checksum (message);
  else if (atom_equals (fun, "checksum_device"))
    return run_checksum_device (message);
  else if (atom_equals (fun, "checksums_out"))
    return run_checksums_out (message);
  else if (atom_equals (fun, "chmod"))
    return run_chmod (message);
  else if (atom_equals (fun, "chown"))
    return run_chown (message);
  else if (atom_equals (fun, "command"))
    return run_command (message);
  else if (atom_equals (fun, "command_lines"))
    return run_command_lines (message);
  else if (atom_equals (fun, "compress_device_out"))
    return run_compress_device_out (message);
  else if (atom_equals (fun, "compress_out"))
    return run_compress_out (message);
  else if (atom_equals (fun, "config"))
    return run_config (message);
  else if (atom_equals (fun, "copy_device_to_device"))
    return run_copy_device_to_device (message);
  else if (atom_equals (fun, "copy_device_to_file"))
    return run_copy_device_to_file (message);
  else if (atom_equals (fun, "copy_file_to_device"))
    return run_copy_file_to_device (message);
  else if (atom_equals (fun, "copy_file_to_file"))
    return run_copy_file_to_file (message);
  else if (atom_equals (fun, "copy_size"))
    return run_copy_size (message);
  else if (atom_equals (fun, "cp"))
    return run_cp (message);
  else if (atom_equals (fun, "cp_a"))
    return run_cp_a (message);
  else if (atom_equals (fun, "dd"))
    return run_dd (message);
  else if (atom_equals (fun, "debug"))
    return run_debug (message);
  else if (atom_equals (fun, "debug_cmdline"))
    return run_debug_cmdline (message);
  else if (atom_equals (fun, "debug_drives"))
    return run_debug_drives (message);
  else if (atom_equals (fun, "debug_upload"))
    return run_debug_upload (message);
  else if (atom_equals (fun, "df"))
    return run_df (message);
  else if (atom_equals (fun, "df_h"))
    return run_df_h (message);
  else if (atom_equals (fun, "dmesg"))
    return run_dmesg (message);
  else if (atom_equals (fun, "download"))
    return run_download (message);
  else if (atom_equals (fun, "download_offset"))
    return run_download_offset (message);
  else if (atom_equals (fun, "drop_caches"))
    return run_drop_caches (message);
  else if (atom_equals (fun, "du"))
    return run_du (message);
  else if (atom_equals (fun, "e2fsck"))
    return run_e2fsck (message);
  else if (atom_equals (fun, "e2fsck_f"))
    return run_e2fsck_f (message);
  else if (atom_equals (fun, "echo_daemon"))
    return run_echo_daemon (message);
  else if (atom_equals (fun, "egrep"))
    return run_egrep (message);
  else if (atom_equals (fun, "egrepi"))
    return run_egrepi (message);
  else if (atom_equals (fun, "equal"))
    return run_equal (message);
  else if (atom_equals (fun, "exists"))
    return run_exists (message);
  else if (atom_equals (fun, "fallocate"))
    return run_fallocate (message);
  else if (atom_equals (fun, "fallocate64"))
    return run_fallocate64 (message);
  else if (atom_equals (fun, "fgrep"))
    return run_fgrep (message);
  else if (atom_equals (fun, "fgrepi"))
    return run_fgrepi (message);
  else if (atom_equals (fun, "file"))
    return run_file (message);
  else if (atom_equals (fun, "file_architecture"))
    return run_file_architecture (message);
  else if (atom_equals (fun, "filesize"))
    return run_filesize (message);
  else if (atom_equals (fun, "fill"))
    return run_fill (message);
  else if (atom_equals (fun, "fill_pattern"))
    return run_fill_pattern (message);
  else if (atom_equals (fun, "find"))
    return run_find (message);
  else if (atom_equals (fun, "find0"))
    return run_find0 (message);
  else if (atom_equals (fun, "findfs_label"))
    return run_findfs_label (message);
  else if (atom_equals (fun, "findfs_uuid"))
    return run_findfs_uuid (message);
  else if (atom_equals (fun, "fsck"))
    return run_fsck (message);
  else if (atom_equals (fun, "get_append"))
    return run_get_append (message);
  else if (atom_equals (fun, "get_attach_method"))
    return run_get_attach_method (message);
  else if (atom_equals (fun, "get_autosync"))
    return run_get_autosync (message);
  else if (atom_equals (fun, "get_direct"))
    return run_get_direct (message);
  else if (atom_equals (fun, "get_e2label"))
    return run_get_e2label (message);
  else if (atom_equals (fun, "get_e2uuid"))
    return run_get_e2uuid (message);
  else if (atom_equals (fun, "get_memsize"))
    return run_get_memsize (message);
  else if (atom_equals (fun, "get_network"))
    return run_get_network (message);
  else if (atom_equals (fun, "get_path"))
    return run_get_path (message);
  else if (atom_equals (fun, "get_pgroup"))
    return run_get_pgroup (message);
  else if (atom_equals (fun, "get_pid"))
    return run_get_pid (message);
  else if (atom_equals (fun, "get_qemu"))
    return run_get_qemu (message);
  else if (atom_equals (fun, "get_recovery_proc"))
    return run_get_recovery_proc (message);
  else if (atom_equals (fun, "get_selinux"))
    return run_get_selinux (message);
  else if (atom_equals (fun, "get_smp"))
    return run_get_smp (message);
  else if (atom_equals (fun, "get_state"))
    return run_get_state (message);
  else if (atom_equals (fun, "get_trace"))
    return run_get_trace (message);
  else if (atom_equals (fun, "get_umask"))
    return run_get_umask (message);
  else if (atom_equals (fun, "get_verbose"))
    return run_get_verbose (message);
  else if (atom_equals (fun, "getcon"))
    return run_getcon (message);
  else if (atom_equals (fun, "getxattr"))
    return run_getxattr (message);
  else if (atom_equals (fun, "getxattrs"))
    return run_getxattrs (message);
  else if (atom_equals (fun, "glob_expand"))
    return run_glob_expand (message);
  else if (atom_equals (fun, "grep"))
    return run_grep (message);
  else if (atom_equals (fun, "grepi"))
    return run_grepi (message);
  else if (atom_equals (fun, "grub_install"))
    return run_grub_install (message);
  else if (atom_equals (fun, "head"))
    return run_head (message);
  else if (atom_equals (fun, "head_n"))
    return run_head_n (message);
  else if (atom_equals (fun, "hexdump"))
    return run_hexdump (message);
  else if (atom_equals (fun, "initrd_cat"))
    return run_initrd_cat (message);
  else if (atom_equals (fun, "initrd_list"))
    return run_initrd_list (message);
  else if (atom_equals (fun, "inotify_add_watch"))
    return run_inotify_add_watch (message);
  else if (atom_equals (fun, "inotify_close"))
    return run_inotify_close (message);
  else if (atom_equals (fun, "inotify_files"))
    return run_inotify_files (message);
  else if (atom_equals (fun, "inotify_init"))
    return run_inotify_init (message);
  else if (atom_equals (fun, "inotify_read"))
    return run_inotify_read (message);
  else if (atom_equals (fun, "inotify_rm_watch"))
    return run_inotify_rm_watch (message);
  else if (atom_equals (fun, "inspect_get_arch"))
    return run_inspect_get_arch (message);
  else if (atom_equals (fun, "inspect_get_distro"))
    return run_inspect_get_distro (message);
  else if (atom_equals (fun, "inspect_get_drive_mappings"))
    return run_inspect_get_drive_mappings (message);
  else if (atom_equals (fun, "inspect_get_filesystems"))
    return run_inspect_get_filesystems (message);
  else if (atom_equals (fun, "inspect_get_format"))
    return run_inspect_get_format (message);
  else if (atom_equals (fun, "inspect_get_hostname"))
    return run_inspect_get_hostname (message);
  else if (atom_equals (fun, "inspect_get_icon"))
    return run_inspect_get_icon (message);
  else if (atom_equals (fun, "inspect_get_major_version"))
    return run_inspect_get_major_version (message);
  else if (atom_equals (fun, "inspect_get_minor_version"))
    return run_inspect_get_minor_version (message);
  else if (atom_equals (fun, "inspect_get_mountpoints"))
    return run_inspect_get_mountpoints (message);
  else if (atom_equals (fun, "inspect_get_package_format"))
    return run_inspect_get_package_format (message);
  else if (atom_equals (fun, "inspect_get_package_management"))
    return run_inspect_get_package_management (message);
  else if (atom_equals (fun, "inspect_get_product_name"))
    return run_inspect_get_product_name (message);
  else if (atom_equals (fun, "inspect_get_product_variant"))
    return run_inspect_get_product_variant (message);
  else if (atom_equals (fun, "inspect_get_roots"))
    return run_inspect_get_roots (message);
  else if (atom_equals (fun, "inspect_get_type"))
    return run_inspect_get_type (message);
  else if (atom_equals (fun, "inspect_get_windows_current_control_set"))
    return run_inspect_get_windows_current_control_set (message);
  else if (atom_equals (fun, "inspect_get_windows_systemroot"))
    return run_inspect_get_windows_systemroot (message);
  else if (atom_equals (fun, "inspect_is_live"))
    return run_inspect_is_live (message);
  else if (atom_equals (fun, "inspect_is_multipart"))
    return run_inspect_is_multipart (message);
  else if (atom_equals (fun, "inspect_is_netinst"))
    return run_inspect_is_netinst (message);
  else if (atom_equals (fun, "inspect_list_applications"))
    return run_inspect_list_applications (message);
  else if (atom_equals (fun, "inspect_os"))
    return run_inspect_os (message);
  else if (atom_equals (fun, "internal_autosync"))
    return run_internal_autosync (message);
  else if (atom_equals (fun, "is_blockdev"))
    return run_is_blockdev (message);
  else if (atom_equals (fun, "is_busy"))
    return run_is_busy (message);
  else if (atom_equals (fun, "is_chardev"))
    return run_is_chardev (message);
  else if (atom_equals (fun, "is_config"))
    return run_is_config (message);
  else if (atom_equals (fun, "is_dir"))
    return run_is_dir (message);
  else if (atom_equals (fun, "is_fifo"))
    return run_is_fifo (message);
  else if (atom_equals (fun, "is_file"))
    return run_is_file (message);
  else if (atom_equals (fun, "is_launching"))
    return run_is_launching (message);
  else if (atom_equals (fun, "is_lv"))
    return run_is_lv (message);
  else if (atom_equals (fun, "is_ready"))
    return run_is_ready (message);
  else if (atom_equals (fun, "is_socket"))
    return run_is_socket (message);
  else if (atom_equals (fun, "is_symlink"))
    return run_is_symlink (message);
  else if (atom_equals (fun, "is_zero"))
    return run_is_zero (message);
  else if (atom_equals (fun, "is_zero_device"))
    return run_is_zero_device (message);
  else if (atom_equals (fun, "kill_subprocess"))
    return run_kill_subprocess (message);
  else if (atom_equals (fun, "launch"))
    return run_launch (message);
  else if (atom_equals (fun, "lchown"))
    return run_lchown (message);
  else if (atom_equals (fun, "lgetxattr"))
    return run_lgetxattr (message);
  else if (atom_equals (fun, "lgetxattrs"))
    return run_lgetxattrs (message);
  else if (atom_equals (fun, "list_9p"))
    return run_list_9p (message);
  else if (atom_equals (fun, "list_devices"))
    return run_list_devices (message);
  else if (atom_equals (fun, "list_dm_devices"))
    return run_list_dm_devices (message);
  else if (atom_equals (fun, "list_filesystems"))
    return run_list_filesystems (message);
  else if (atom_equals (fun, "list_md_devices"))
    return run_list_md_devices (message);
  else if (atom_equals (fun, "list_partitions"))
    return run_list_partitions (message);
  else if (atom_equals (fun, "ll"))
    return run_ll (message);
  else if (atom_equals (fun, "ln"))
    return run_ln (message);
  else if (atom_equals (fun, "ln_f"))
    return run_ln_f (message);
  else if (atom_equals (fun, "ln_s"))
    return run_ln_s (message);
  else if (atom_equals (fun, "ln_sf"))
    return run_ln_sf (message);
  else if (atom_equals (fun, "lremovexattr"))
    return run_lremovexattr (message);
  else if (atom_equals (fun, "ls"))
    return run_ls (message);
  else if (atom_equals (fun, "lsetxattr"))
    return run_lsetxattr (message);
  else if (atom_equals (fun, "lstat"))
    return run_lstat (message);
  else if (atom_equals (fun, "lstatlist"))
    return run_lstatlist (message);
  else if (atom_equals (fun, "luks_add_key"))
    return run_luks_add_key (message);
  else if (atom_equals (fun, "luks_close"))
    return run_luks_close (message);
  else if (atom_equals (fun, "luks_format"))
    return run_luks_format (message);
  else if (atom_equals (fun, "luks_format_cipher"))
    return run_luks_format_cipher (message);
  else if (atom_equals (fun, "luks_kill_slot"))
    return run_luks_kill_slot (message);
  else if (atom_equals (fun, "luks_open"))
    return run_luks_open (message);
  else if (atom_equals (fun, "luks_open_ro"))
    return run_luks_open_ro (message);
  else if (atom_equals (fun, "lvcreate"))
    return run_lvcreate (message);
  else if (atom_equals (fun, "lvm_canonical_lv_name"))
    return run_lvm_canonical_lv_name (message);
  else if (atom_equals (fun, "lvm_clear_filter"))
    return run_lvm_clear_filter (message);
  else if (atom_equals (fun, "lvm_remove_all"))
    return run_lvm_remove_all (message);
  else if (atom_equals (fun, "lvm_set_filter"))
    return run_lvm_set_filter (message);
  else if (atom_equals (fun, "lvremove"))
    return run_lvremove (message);
  else if (atom_equals (fun, "lvrename"))
    return run_lvrename (message);
  else if (atom_equals (fun, "lvresize"))
    return run_lvresize (message);
  else if (atom_equals (fun, "lvresize_free"))
    return run_lvresize_free (message);
  else if (atom_equals (fun, "lvs"))
    return run_lvs (message);
  else if (atom_equals (fun, "lvs_full"))
    return run_lvs_full (message);
  else if (atom_equals (fun, "lvuuid"))
    return run_lvuuid (message);
  else if (atom_equals (fun, "lxattrlist"))
    return run_lxattrlist (message);
  else if (atom_equals (fun, "md_create"))
    return run_md_create (message);
  else if (atom_equals (fun, "md_detail"))
    return run_md_detail (message);
  else if (atom_equals (fun, "md_stop"))
    return run_md_stop (message);
  else if (atom_equals (fun, "mkdir"))
    return run_mkdir (message);
  else if (atom_equals (fun, "mkdir_mode"))
    return run_mkdir_mode (message);
  else if (atom_equals (fun, "mkdir_p"))
    return run_mkdir_p (message);
  else if (atom_equals (fun, "mkdtemp"))
    return run_mkdtemp (message);
  else if (atom_equals (fun, "mke2fs_J"))
    return run_mke2fs_J (message);
  else if (atom_equals (fun, "mke2fs_JL"))
    return run_mke2fs_JL (message);
  else if (atom_equals (fun, "mke2fs_JU"))
    return run_mke2fs_JU (message);
  else if (atom_equals (fun, "mke2journal"))
    return run_mke2journal (message);
  else if (atom_equals (fun, "mke2journal_L"))
    return run_mke2journal_L (message);
  else if (atom_equals (fun, "mke2journal_U"))
    return run_mke2journal_U (message);
  else if (atom_equals (fun, "mkfifo"))
    return run_mkfifo (message);
  else if (atom_equals (fun, "mkfs"))
    return run_mkfs (message);
  else if (atom_equals (fun, "mkfs_b"))
    return run_mkfs_b (message);
  else if (atom_equals (fun, "mkfs_opts"))
    return run_mkfs_opts (message);
  else if (atom_equals (fun, "mkmountpoint"))
    return run_mkmountpoint (message);
  else if (atom_equals (fun, "mknod"))
    return run_mknod (message);
  else if (atom_equals (fun, "mknod_b"))
    return run_mknod_b (message);
  else if (atom_equals (fun, "mknod_c"))
    return run_mknod_c (message);
  else if (atom_equals (fun, "mkswap"))
    return run_mkswap (message);
  else if (atom_equals (fun, "mkswap_L"))
    return run_mkswap_L (message);
  else if (atom_equals (fun, "mkswap_U"))
    return run_mkswap_U (message);
  else if (atom_equals (fun, "mkswap_file"))
    return run_mkswap_file (message);
  else if (atom_equals (fun, "modprobe"))
    return run_modprobe (message);
  else if (atom_equals (fun, "mount"))
    return run_mount (message);
  else if (atom_equals (fun, "mount_9p"))
    return run_mount_9p (message);
  else if (atom_equals (fun, "mount_loop"))
    return run_mount_loop (message);
  else if (atom_equals (fun, "mount_options"))
    return run_mount_options (message);
  else if (atom_equals (fun, "mount_ro"))
    return run_mount_ro (message);
  else if (atom_equals (fun, "mount_vfs"))
    return run_mount_vfs (message);
  else if (atom_equals (fun, "mountpoints"))
    return run_mountpoints (message);
  else if (atom_equals (fun, "mounts"))
    return run_mounts (message);
  else if (atom_equals (fun, "mv"))
    return run_mv (message);
  else if (atom_equals (fun, "ntfs_3g_probe"))
    return run_ntfs_3g_probe (message);
  else if (atom_equals (fun, "ntfsresize"))
    return run_ntfsresize (message);
  else if (atom_equals (fun, "ntfsresize_opts"))
    return run_ntfsresize_opts (message);
  else if (atom_equals (fun, "ntfsresize_size"))
    return run_ntfsresize_size (message);
  else if (atom_equals (fun, "part_add"))
    return run_part_add (message);
  else if (atom_equals (fun, "part_del"))
    return run_part_del (message);
  else if (atom_equals (fun, "part_disk"))
    return run_part_disk (message);
  else if (atom_equals (fun, "part_get_bootable"))
    return run_part_get_bootable (message);
  else if (atom_equals (fun, "part_get_mbr_id"))
    return run_part_get_mbr_id (message);
  else if (atom_equals (fun, "part_get_parttype"))
    return run_part_get_parttype (message);
  else if (atom_equals (fun, "part_init"))
    return run_part_init (message);
  else if (atom_equals (fun, "part_list"))
    return run_part_list (message);
  else if (atom_equals (fun, "part_set_bootable"))
    return run_part_set_bootable (message);
  else if (atom_equals (fun, "part_set_mbr_id"))
    return run_part_set_mbr_id (message);
  else if (atom_equals (fun, "part_set_name"))
    return run_part_set_name (message);
  else if (atom_equals (fun, "part_to_dev"))
    return run_part_to_dev (message);
  else if (atom_equals (fun, "part_to_partnum"))
    return run_part_to_partnum (message);
  else if (atom_equals (fun, "ping_daemon"))
    return run_ping_daemon (message);
  else if (atom_equals (fun, "pread"))
    return run_pread (message);
  else if (atom_equals (fun, "pread_device"))
    return run_pread_device (message);
  else if (atom_equals (fun, "pvcreate"))
    return run_pvcreate (message);
  else if (atom_equals (fun, "pvremove"))
    return run_pvremove (message);
  else if (atom_equals (fun, "pvresize"))
    return run_pvresize (message);
  else if (atom_equals (fun, "pvresize_size"))
    return run_pvresize_size (message);
  else if (atom_equals (fun, "pvs"))
    return run_pvs (message);
  else if (atom_equals (fun, "pvs_full"))
    return run_pvs_full (message);
  else if (atom_equals (fun, "pvuuid"))
    return run_pvuuid (message);
  else if (atom_equals (fun, "pwrite"))
    return run_pwrite (message);
  else if (atom_equals (fun, "pwrite_device"))
    return run_pwrite_device (message);
  else if (atom_equals (fun, "read_file"))
    return run_read_file (message);
  else if (atom_equals (fun, "read_lines"))
    return run_read_lines (message);
  else if (atom_equals (fun, "readdir"))
    return run_readdir (message);
  else if (atom_equals (fun, "readlink"))
    return run_readlink (message);
  else if (atom_equals (fun, "readlinklist"))
    return run_readlinklist (message);
  else if (atom_equals (fun, "realpath"))
    return run_realpath (message);
  else if (atom_equals (fun, "removexattr"))
    return run_removexattr (message);
  else if (atom_equals (fun, "resize2fs"))
    return run_resize2fs (message);
  else if (atom_equals (fun, "resize2fs_M"))
    return run_resize2fs_M (message);
  else if (atom_equals (fun, "resize2fs_size"))
    return run_resize2fs_size (message);
  else if (atom_equals (fun, "rm"))
    return run_rm (message);
  else if (atom_equals (fun, "rm_rf"))
    return run_rm_rf (message);
  else if (atom_equals (fun, "rmdir"))
    return run_rmdir (message);
  else if (atom_equals (fun, "rmmountpoint"))
    return run_rmmountpoint (message);
  else if (atom_equals (fun, "scrub_device"))
    return run_scrub_device (message);
  else if (atom_equals (fun, "scrub_file"))
    return run_scrub_file (message);
  else if (atom_equals (fun, "scrub_freespace"))
    return run_scrub_freespace (message);
  else if (atom_equals (fun, "set_append"))
    return run_set_append (message);
  else if (atom_equals (fun, "set_attach_method"))
    return run_set_attach_method (message);
  else if (atom_equals (fun, "set_autosync"))
    return run_set_autosync (message);
  else if (atom_equals (fun, "set_direct"))
    return run_set_direct (message);
  else if (atom_equals (fun, "set_e2label"))
    return run_set_e2label (message);
  else if (atom_equals (fun, "set_e2uuid"))
    return run_set_e2uuid (message);
  else if (atom_equals (fun, "set_memsize"))
    return run_set_memsize (message);
  else if (atom_equals (fun, "set_network"))
    return run_set_network (message);
  else if (atom_equals (fun, "set_path"))
    return run_set_path (message);
  else if (atom_equals (fun, "set_pgroup"))
    return run_set_pgroup (message);
  else if (atom_equals (fun, "set_qemu"))
    return run_set_qemu (message);
  else if (atom_equals (fun, "set_recovery_proc"))
    return run_set_recovery_proc (message);
  else if (atom_equals (fun, "set_selinux"))
    return run_set_selinux (message);
  else if (atom_equals (fun, "set_smp"))
    return run_set_smp (message);
  else if (atom_equals (fun, "set_trace"))
    return run_set_trace (message);
  else if (atom_equals (fun, "set_verbose"))
    return run_set_verbose (message);
  else if (atom_equals (fun, "setcon"))
    return run_setcon (message);
  else if (atom_equals (fun, "setxattr"))
    return run_setxattr (message);
  else if (atom_equals (fun, "sfdisk"))
    return run_sfdisk (message);
  else if (atom_equals (fun, "sfdiskM"))
    return run_sfdiskM (message);
  else if (atom_equals (fun, "sfdisk_N"))
    return run_sfdisk_N (message);
  else if (atom_equals (fun, "sfdisk_disk_geometry"))
    return run_sfdisk_disk_geometry (message);
  else if (atom_equals (fun, "sfdisk_kernel_geometry"))
    return run_sfdisk_kernel_geometry (message);
  else if (atom_equals (fun, "sfdisk_l"))
    return run_sfdisk_l (message);
  else if (atom_equals (fun, "sh"))
    return run_sh (message);
  else if (atom_equals (fun, "sh_lines"))
    return run_sh_lines (message);
  else if (atom_equals (fun, "sleep"))
    return run_sleep (message);
  else if (atom_equals (fun, "stat"))
    return run_stat (message);
  else if (atom_equals (fun, "statvfs"))
    return run_statvfs (message);
  else if (atom_equals (fun, "strings"))
    return run_strings (message);
  else if (atom_equals (fun, "strings_e"))
    return run_strings_e (message);
  else if (atom_equals (fun, "swapoff_device"))
    return run_swapoff_device (message);
  else if (atom_equals (fun, "swapoff_file"))
    return run_swapoff_file (message);
  else if (atom_equals (fun, "swapoff_label"))
    return run_swapoff_label (message);
  else if (atom_equals (fun, "swapoff_uuid"))
    return run_swapoff_uuid (message);
  else if (atom_equals (fun, "swapon_device"))
    return run_swapon_device (message);
  else if (atom_equals (fun, "swapon_file"))
    return run_swapon_file (message);
  else if (atom_equals (fun, "swapon_label"))
    return run_swapon_label (message);
  else if (atom_equals (fun, "swapon_uuid"))
    return run_swapon_uuid (message);
  else if (atom_equals (fun, "sync"))
    return run_sync (message);
  else if (atom_equals (fun, "tail"))
    return run_tail (message);
  else if (atom_equals (fun, "tail_n"))
    return run_tail_n (message);
  else if (atom_equals (fun, "tar_in"))
    return run_tar_in (message);
  else if (atom_equals (fun, "tar_out"))
    return run_tar_out (message);
  else if (atom_equals (fun, "test0"))
    return run_test0 (message);
  else if (atom_equals (fun, "test0rbool"))
    return run_test0rbool (message);
  else if (atom_equals (fun, "test0rboolerr"))
    return run_test0rboolerr (message);
  else if (atom_equals (fun, "test0rbufferout"))
    return run_test0rbufferout (message);
  else if (atom_equals (fun, "test0rbufferouterr"))
    return run_test0rbufferouterr (message);
  else if (atom_equals (fun, "test0rconstoptstring"))
    return run_test0rconstoptstring (message);
  else if (atom_equals (fun, "test0rconstoptstringerr"))
    return run_test0rconstoptstringerr (message);
  else if (atom_equals (fun, "test0rconststring"))
    return run_test0rconststring (message);
  else if (atom_equals (fun, "test0rconststringerr"))
    return run_test0rconststringerr (message);
  else if (atom_equals (fun, "test0rhashtable"))
    return run_test0rhashtable (message);
  else if (atom_equals (fun, "test0rhashtableerr"))
    return run_test0rhashtableerr (message);
  else if (atom_equals (fun, "test0rint"))
    return run_test0rint (message);
  else if (atom_equals (fun, "test0rint64"))
    return run_test0rint64 (message);
  else if (atom_equals (fun, "test0rint64err"))
    return run_test0rint64err (message);
  else if (atom_equals (fun, "test0rinterr"))
    return run_test0rinterr (message);
  else if (atom_equals (fun, "test0rstring"))
    return run_test0rstring (message);
  else if (atom_equals (fun, "test0rstringerr"))
    return run_test0rstringerr (message);
  else if (atom_equals (fun, "test0rstringlist"))
    return run_test0rstringlist (message);
  else if (atom_equals (fun, "test0rstringlisterr"))
    return run_test0rstringlisterr (message);
  else if (atom_equals (fun, "test0rstruct"))
    return run_test0rstruct (message);
  else if (atom_equals (fun, "test0rstructerr"))
    return run_test0rstructerr (message);
  else if (atom_equals (fun, "test0rstructlist"))
    return run_test0rstructlist (message);
  else if (atom_equals (fun, "test0rstructlisterr"))
    return run_test0rstructlisterr (message);
  else if (atom_equals (fun, "tgz_in"))
    return run_tgz_in (message);
  else if (atom_equals (fun, "tgz_out"))
    return run_tgz_out (message);
  else if (atom_equals (fun, "touch"))
    return run_touch (message);
  else if (atom_equals (fun, "truncate"))
    return run_truncate (message);
  else if (atom_equals (fun, "truncate_size"))
    return run_truncate_size (message);
  else if (atom_equals (fun, "tune2fs"))
    return run_tune2fs (message);
  else if (atom_equals (fun, "tune2fs_l"))
    return run_tune2fs_l (message);
  else if (atom_equals (fun, "txz_in"))
    return run_txz_in (message);
  else if (atom_equals (fun, "txz_out"))
    return run_txz_out (message);
  else if (atom_equals (fun, "umask"))
    return run_umask (message);
  else if (atom_equals (fun, "umount"))
    return run_umount (message);
  else if (atom_equals (fun, "umount_all"))
    return run_umount_all (message);
  else if (atom_equals (fun, "upload"))
    return run_upload (message);
  else if (atom_equals (fun, "upload_offset"))
    return run_upload_offset (message);
  else if (atom_equals (fun, "utimens"))
    return run_utimens (message);
  else if (atom_equals (fun, "version"))
    return run_version (message);
  else if (atom_equals (fun, "vfs_label"))
    return run_vfs_label (message);
  else if (atom_equals (fun, "vfs_type"))
    return run_vfs_type (message);
  else if (atom_equals (fun, "vfs_uuid"))
    return run_vfs_uuid (message);
  else if (atom_equals (fun, "vg_activate"))
    return run_vg_activate (message);
  else if (atom_equals (fun, "vg_activate_all"))
    return run_vg_activate_all (message);
  else if (atom_equals (fun, "vgcreate"))
    return run_vgcreate (message);
  else if (atom_equals (fun, "vglvuuids"))
    return run_vglvuuids (message);
  else if (atom_equals (fun, "vgpvuuids"))
    return run_vgpvuuids (message);
  else if (atom_equals (fun, "vgremove"))
    return run_vgremove (message);
  else if (atom_equals (fun, "vgrename"))
    return run_vgrename (message);
  else if (atom_equals (fun, "vgs"))
    return run_vgs (message);
  else if (atom_equals (fun, "vgs_full"))
    return run_vgs_full (message);
  else if (atom_equals (fun, "vgscan"))
    return run_vgscan (message);
  else if (atom_equals (fun, "vguuid"))
    return run_vguuid (message);
  else if (atom_equals (fun, "wait_ready"))
    return run_wait_ready (message);
  else if (atom_equals (fun, "wc_c"))
    return run_wc_c (message);
  else if (atom_equals (fun, "wc_l"))
    return run_wc_l (message);
  else if (atom_equals (fun, "wc_w"))
    return run_wc_w (message);
  else if (atom_equals (fun, "write"))
    return run_write (message);
  else if (atom_equals (fun, "write_append"))
    return run_write_append (message);
  else if (atom_equals (fun, "write_file"))
    return run_write_file (message);
  else if (atom_equals (fun, "zegrep"))
    return run_zegrep (message);
  else if (atom_equals (fun, "zegrepi"))
    return run_zegrepi (message);
  else if (atom_equals (fun, "zero"))
    return run_zero (message);
  else if (atom_equals (fun, "zero_device"))
    return run_zero_device (message);
  else if (atom_equals (fun, "zerofree"))
    return run_zerofree (message);
  else if (atom_equals (fun, "zfgrep"))
    return run_zfgrep (message);
  else if (atom_equals (fun, "zfgrepi"))
    return run_zfgrepi (message);
  else if (atom_equals (fun, "zfile"))
    return run_zfile (message);
  else if (atom_equals (fun, "zgrep"))
    return run_zgrep (message);
  else if (atom_equals (fun, "zgrepi"))
    return run_zgrepi (message);
  else return unknown_function (fun);
}
