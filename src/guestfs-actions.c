/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   src/generator.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2010 Red Hat Inc.
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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"
#include "guestfs_protocol.h"

#define error guestfs_error
//#define perrorf guestfs_perrorf
#define safe_malloc guestfs_safe_malloc
#define safe_realloc guestfs_safe_realloc
//#define safe_strdup guestfs_safe_strdup
#define safe_memdup guestfs_safe_memdup

/* Check the return message from a call for validity. */
static int
check_reply_header (guestfs_h *g,
                    const struct guestfs_message_header *hdr,
                    unsigned int proc_nr, unsigned int serial)
{
  if (hdr->prog != GUESTFS_PROGRAM) {
    error (g, "wrong program (%d/%d)", hdr->prog, GUESTFS_PROGRAM);
    return -1;
  }
  if (hdr->vers != GUESTFS_PROTOCOL_VERSION) {
    error (g, "wrong protocol version (%d/%d)",
           hdr->vers, GUESTFS_PROTOCOL_VERSION);
    return -1;
  }
  if (hdr->direction != GUESTFS_DIRECTION_REPLY) {
    error (g, "unexpected message direction (%d/%d)",
           hdr->direction, GUESTFS_DIRECTION_REPLY);
    return -1;
  }
  if (hdr->proc != proc_nr) {
    error (g, "unexpected procedure number (%d/%d)", hdr->proc, proc_nr);
    return -1;
  }
  if (hdr->serial != serial) {
    error (g, "unexpected serial (%d/%d)", hdr->serial, serial);
    return -1;
  }

  return 0;
}

/* Check we are in the right state to run a high-level action. */
static int
check_state (guestfs_h *g, const char *caller)
{
  if (!guestfs__is_ready (g)) {
    if (guestfs__is_config (g) || guestfs__is_launching (g))
      error (g, "%s: call launch before using this function\n(in guestfish, don't forget to use the 'run' command)",
        caller);
    else
      error (g, "%s called from the wrong state, %d != READY",
        caller, guestfs__get_state (g));
    return -1;
  }
  return 0;
}

int guestfs_test0 (guestfs_h *g,
		const char *str,
		const char *optstr,
		char *const *strlist,
		int b,
		int integer,
		int64_t integer64,
		const char *filein,
		const char *fileout)
{
  if (guestfs__get_trace (g)) {
    int i;

    printf ("test0");
    printf (" \"%s\"", str);
    if (optstr) printf (" \"%s\"", optstr);
    else printf (" null");
    putchar (' ');
    putchar ('"');
    for (i = 0; strlist[i]; ++i) {
      if (i > 0) putchar (' ');
      fputs (strlist[i], stdout);
    }
    putchar ('"');
    fputs (b ? " true" : " false", stdout);
    printf (" %d", integer);
    printf (" %" PRIi64, integer64);
    printf (" \"%s\"", filein);
    printf (" \"%s\"", fileout);
    putchar ('\n');
  }

  return guestfs__test0 (g, str, optstr, strlist, b, integer, integer64, filein, fileout);
}

int guestfs_test0rint (guestfs_h *g,
		const char *val)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rint");
    printf (" \"%s\"", val);
    putchar ('\n');
  }

  return guestfs__test0rint (g, val);
}

int guestfs_test0rinterr (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rinterr");
    putchar ('\n');
  }

  return guestfs__test0rinterr (g);
}

int64_t guestfs_test0rint64 (guestfs_h *g,
		const char *val)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rint64");
    printf (" \"%s\"", val);
    putchar ('\n');
  }

  return guestfs__test0rint64 (g, val);
}

int64_t guestfs_test0rint64err (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rint64err");
    putchar ('\n');
  }

  return guestfs__test0rint64err (g);
}

int guestfs_test0rbool (guestfs_h *g,
		const char *val)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rbool");
    printf (" \"%s\"", val);
    putchar ('\n');
  }

  return guestfs__test0rbool (g, val);
}

int guestfs_test0rboolerr (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rboolerr");
    putchar ('\n');
  }

  return guestfs__test0rboolerr (g);
}

const char *guestfs_test0rconststring (guestfs_h *g,
		const char *val)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rconststring");
    printf (" \"%s\"", val);
    putchar ('\n');
  }

  return guestfs__test0rconststring (g, val);
}

const char *guestfs_test0rconststringerr (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rconststringerr");
    putchar ('\n');
  }

  return guestfs__test0rconststringerr (g);
}

const char *guestfs_test0rconstoptstring (guestfs_h *g,
		const char *val)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rconstoptstring");
    printf (" \"%s\"", val);
    putchar ('\n');
  }

  return guestfs__test0rconstoptstring (g, val);
}

const char *guestfs_test0rconstoptstringerr (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rconstoptstringerr");
    putchar ('\n');
  }

  return guestfs__test0rconstoptstringerr (g);
}

char *guestfs_test0rstring (guestfs_h *g,
		const char *val)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rstring");
    printf (" \"%s\"", val);
    putchar ('\n');
  }

  return guestfs__test0rstring (g, val);
}

char *guestfs_test0rstringerr (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rstringerr");
    putchar ('\n');
  }

  return guestfs__test0rstringerr (g);
}

char **guestfs_test0rstringlist (guestfs_h *g,
		const char *val)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rstringlist");
    printf (" \"%s\"", val);
    putchar ('\n');
  }

  return guestfs__test0rstringlist (g, val);
}

char **guestfs_test0rstringlisterr (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rstringlisterr");
    putchar ('\n');
  }

  return guestfs__test0rstringlisterr (g);
}

struct guestfs_lvm_pv *guestfs_test0rstruct (guestfs_h *g,
		const char *val)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rstruct");
    printf (" \"%s\"", val);
    putchar ('\n');
  }

  return guestfs__test0rstruct (g, val);
}

struct guestfs_lvm_pv *guestfs_test0rstructerr (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rstructerr");
    putchar ('\n');
  }

  return guestfs__test0rstructerr (g);
}

struct guestfs_lvm_pv_list *guestfs_test0rstructlist (guestfs_h *g,
		const char *val)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rstructlist");
    printf (" \"%s\"", val);
    putchar ('\n');
  }

  return guestfs__test0rstructlist (g, val);
}

struct guestfs_lvm_pv_list *guestfs_test0rstructlisterr (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rstructlisterr");
    putchar ('\n');
  }

  return guestfs__test0rstructlisterr (g);
}

char **guestfs_test0rhashtable (guestfs_h *g,
		const char *val)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rhashtable");
    printf (" \"%s\"", val);
    putchar ('\n');
  }

  return guestfs__test0rhashtable (g, val);
}

char **guestfs_test0rhashtableerr (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("test0rhashtableerr");
    putchar ('\n');
  }

  return guestfs__test0rhashtableerr (g);
}

int guestfs_launch (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("launch");
    putchar ('\n');
  }

  return guestfs__launch (g);
}

int guestfs_wait_ready (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("wait_ready");
    putchar ('\n');
  }

  return guestfs__wait_ready (g);
}

int guestfs_kill_subprocess (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("kill_subprocess");
    putchar ('\n');
  }

  return guestfs__kill_subprocess (g);
}

int guestfs_add_drive (guestfs_h *g,
		const char *filename)
{
  if (guestfs__get_trace (g)) {
    printf ("add_drive");
    printf (" \"%s\"", filename);
    putchar ('\n');
  }

  return guestfs__add_drive (g, filename);
}

int guestfs_add_cdrom (guestfs_h *g,
		const char *filename)
{
  if (guestfs__get_trace (g)) {
    printf ("add_cdrom");
    printf (" \"%s\"", filename);
    putchar ('\n');
  }

  return guestfs__add_cdrom (g, filename);
}

int guestfs_add_drive_ro (guestfs_h *g,
		const char *filename)
{
  if (guestfs__get_trace (g)) {
    printf ("add_drive_ro");
    printf (" \"%s\"", filename);
    putchar ('\n');
  }

  return guestfs__add_drive_ro (g, filename);
}

int guestfs_config (guestfs_h *g,
		const char *qemuparam,
		const char *qemuvalue)
{
  if (guestfs__get_trace (g)) {
    printf ("config");
    printf (" \"%s\"", qemuparam);
    if (qemuvalue) printf (" \"%s\"", qemuvalue);
    else printf (" null");
    putchar ('\n');
  }

  return guestfs__config (g, qemuparam, qemuvalue);
}

int guestfs_set_qemu (guestfs_h *g,
		const char *qemu)
{
  if (guestfs__get_trace (g)) {
    printf ("set_qemu");
    printf (" \"%s\"", qemu);
    putchar ('\n');
  }

  return guestfs__set_qemu (g, qemu);
}

const char *guestfs_get_qemu (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("get_qemu");
    putchar ('\n');
  }

  return guestfs__get_qemu (g);
}

int guestfs_set_path (guestfs_h *g,
		const char *searchpath)
{
  if (guestfs__get_trace (g)) {
    printf ("set_path");
    printf (" \"%s\"", searchpath);
    putchar ('\n');
  }

  return guestfs__set_path (g, searchpath);
}

const char *guestfs_get_path (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("get_path");
    putchar ('\n');
  }

  return guestfs__get_path (g);
}

int guestfs_set_append (guestfs_h *g,
		const char *append)
{
  if (guestfs__get_trace (g)) {
    printf ("set_append");
    if (append) printf (" \"%s\"", append);
    else printf (" null");
    putchar ('\n');
  }

  return guestfs__set_append (g, append);
}

const char *guestfs_get_append (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("get_append");
    putchar ('\n');
  }

  return guestfs__get_append (g);
}

int guestfs_set_autosync (guestfs_h *g,
		int autosync)
{
  if (guestfs__get_trace (g)) {
    printf ("set_autosync");
    fputs (autosync ? " true" : " false", stdout);
    putchar ('\n');
  }

  return guestfs__set_autosync (g, autosync);
}

int guestfs_get_autosync (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("get_autosync");
    putchar ('\n');
  }

  return guestfs__get_autosync (g);
}

int guestfs_set_verbose (guestfs_h *g,
		int verbose)
{
  if (guestfs__get_trace (g)) {
    printf ("set_verbose");
    fputs (verbose ? " true" : " false", stdout);
    putchar ('\n');
  }

  return guestfs__set_verbose (g, verbose);
}

int guestfs_get_verbose (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("get_verbose");
    putchar ('\n');
  }

  return guestfs__get_verbose (g);
}

int guestfs_is_ready (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("is_ready");
    putchar ('\n');
  }

  return guestfs__is_ready (g);
}

int guestfs_is_config (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("is_config");
    putchar ('\n');
  }

  return guestfs__is_config (g);
}

int guestfs_is_launching (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("is_launching");
    putchar ('\n');
  }

  return guestfs__is_launching (g);
}

int guestfs_is_busy (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("is_busy");
    putchar ('\n');
  }

  return guestfs__is_busy (g);
}

int guestfs_get_state (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("get_state");
    putchar ('\n');
  }

  return guestfs__get_state (g);
}

int guestfs_set_memsize (guestfs_h *g,
		int memsize)
{
  if (guestfs__get_trace (g)) {
    printf ("set_memsize");
    printf (" %d", memsize);
    putchar ('\n');
  }

  return guestfs__set_memsize (g, memsize);
}

int guestfs_get_memsize (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("get_memsize");
    putchar ('\n');
  }

  return guestfs__get_memsize (g);
}

int guestfs_get_pid (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("get_pid");
    putchar ('\n');
  }

  return guestfs__get_pid (g);
}

struct guestfs_version *guestfs_version (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("version");
    putchar ('\n');
  }

  return guestfs__version (g);
}

int guestfs_set_selinux (guestfs_h *g,
		int selinux)
{
  if (guestfs__get_trace (g)) {
    printf ("set_selinux");
    fputs (selinux ? " true" : " false", stdout);
    putchar ('\n');
  }

  return guestfs__set_selinux (g, selinux);
}

int guestfs_get_selinux (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("get_selinux");
    putchar ('\n');
  }

  return guestfs__get_selinux (g);
}

int guestfs_set_trace (guestfs_h *g,
		int trace)
{
  if (guestfs__get_trace (g)) {
    printf ("set_trace");
    fputs (trace ? " true" : " false", stdout);
    putchar ('\n');
  }

  return guestfs__set_trace (g, trace);
}

int guestfs_get_trace (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("get_trace");
    putchar ('\n');
  }

  return guestfs__get_trace (g);
}

int guestfs_set_direct (guestfs_h *g,
		int direct)
{
  if (guestfs__get_trace (g)) {
    printf ("set_direct");
    fputs (direct ? " true" : " false", stdout);
    putchar ('\n');
  }

  return guestfs__set_direct (g, direct);
}

int guestfs_get_direct (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("get_direct");
    putchar ('\n');
  }

  return guestfs__get_direct (g);
}

int guestfs_set_recovery_proc (guestfs_h *g,
		int recoveryproc)
{
  if (guestfs__get_trace (g)) {
    printf ("set_recovery_proc");
    fputs (recoveryproc ? " true" : " false", stdout);
    putchar ('\n');
  }

  return guestfs__set_recovery_proc (g, recoveryproc);
}

int guestfs_get_recovery_proc (guestfs_h *g)
{
  if (guestfs__get_trace (g)) {
    printf ("get_recovery_proc");
    putchar ('\n');
  }

  return guestfs__get_recovery_proc (g);
}

int guestfs_add_drive_with_if (guestfs_h *g,
		const char *filename,
		const char *iface)
{
  if (guestfs__get_trace (g)) {
    printf ("add_drive_with_if");
    printf (" \"%s\"", filename);
    printf (" \"%s\"", iface);
    putchar ('\n');
  }

  return guestfs__add_drive_with_if (g, filename, iface);
}

int guestfs_add_drive_ro_with_if (guestfs_h *g,
		const char *filename,
		const char *iface)
{
  if (guestfs__get_trace (g)) {
    printf ("add_drive_ro_with_if");
    printf (" \"%s\"", filename);
    printf (" \"%s\"", iface);
    putchar ('\n');
  }

  return guestfs__add_drive_ro_with_if (g, filename, iface);
}

int guestfs_mount (guestfs_h *g,
		const char *device,
		const char *mountpoint)
{
  struct guestfs_mount_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mount");
    printf (" \"%s\"", device);
    printf (" \"%s\"", mountpoint);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mount") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT,
        (xdrproc_t) xdr_guestfs_mount_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mount", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mount", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_sync (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("sync");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_sync") == -1) return -1;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_SYNC, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "sync", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SYNC, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "sync", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_touch (guestfs_h *g,
		const char *path)
{
  struct guestfs_touch_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("touch");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_touch") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_TOUCH,
        (xdrproc_t) xdr_guestfs_touch_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "touch", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TOUCH, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "touch", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_cat (guestfs_h *g,
		const char *path)
{
  struct guestfs_cat_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_cat_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("cat");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_cat") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CAT,
        (xdrproc_t) xdr_guestfs_cat_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "cat", &hdr, &err,
        (xdrproc_t) xdr_guestfs_cat_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CAT, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "cat", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.content; /* caller will free */
}

char *guestfs_ll (guestfs_h *g,
		const char *directory)
{
  struct guestfs_ll_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_ll_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("ll");
    printf (" \"%s\"", directory);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_ll") == -1) return NULL;
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_LL,
        (xdrproc_t) xdr_guestfs_ll_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "ll", &hdr, &err,
        (xdrproc_t) xdr_guestfs_ll_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LL, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "ll", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.listing; /* caller will free */
}

char **guestfs_ls (guestfs_h *g,
		const char *directory)
{
  struct guestfs_ls_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_ls_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("ls");
    printf (" \"%s\"", directory);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_ls") == -1) return NULL;
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_LS,
        (xdrproc_t) xdr_guestfs_ls_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "ls", &hdr, &err,
        (xdrproc_t) xdr_guestfs_ls_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LS, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "ls", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.listing.listing_val =
    safe_realloc (g, ret.listing.listing_val,
                  sizeof (char *) * (ret.listing.listing_len + 1));
  ret.listing.listing_val[ret.listing.listing_len] = NULL;
  return ret.listing.listing_val;
}

char **guestfs_list_devices (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_list_devices_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("list_devices");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_list_devices") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_LIST_DEVICES, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "list_devices", &hdr, &err,
        (xdrproc_t) xdr_guestfs_list_devices_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LIST_DEVICES, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "list_devices", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.devices.devices_val =
    safe_realloc (g, ret.devices.devices_val,
                  sizeof (char *) * (ret.devices.devices_len + 1));
  ret.devices.devices_val[ret.devices.devices_len] = NULL;
  return ret.devices.devices_val;
}

char **guestfs_list_partitions (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_list_partitions_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("list_partitions");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_list_partitions") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_LIST_PARTITIONS, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "list_partitions", &hdr, &err,
        (xdrproc_t) xdr_guestfs_list_partitions_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LIST_PARTITIONS, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "list_partitions", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.partitions.partitions_val =
    safe_realloc (g, ret.partitions.partitions_val,
                  sizeof (char *) * (ret.partitions.partitions_len + 1));
  ret.partitions.partitions_val[ret.partitions.partitions_len] = NULL;
  return ret.partitions.partitions_val;
}

char **guestfs_pvs (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_pvs_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("pvs");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_pvs") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_PVS, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "pvs", &hdr, &err,
        (xdrproc_t) xdr_guestfs_pvs_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PVS, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "pvs", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.physvols.physvols_val =
    safe_realloc (g, ret.physvols.physvols_val,
                  sizeof (char *) * (ret.physvols.physvols_len + 1));
  ret.physvols.physvols_val[ret.physvols.physvols_len] = NULL;
  return ret.physvols.physvols_val;
}

char **guestfs_vgs (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_vgs_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("vgs");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_vgs") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_VGS, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "vgs", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vgs_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGS, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "vgs", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.volgroups.volgroups_val =
    safe_realloc (g, ret.volgroups.volgroups_val,
                  sizeof (char *) * (ret.volgroups.volgroups_len + 1));
  ret.volgroups.volgroups_val[ret.volgroups.volgroups_len] = NULL;
  return ret.volgroups.volgroups_val;
}

char **guestfs_lvs (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lvs_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("lvs");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lvs") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_LVS, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lvs", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lvs_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVS, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lvs", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.logvols.logvols_val =
    safe_realloc (g, ret.logvols.logvols_val,
                  sizeof (char *) * (ret.logvols.logvols_len + 1));
  ret.logvols.logvols_val[ret.logvols.logvols_len] = NULL;
  return ret.logvols.logvols_val;
}

struct guestfs_lvm_pv_list *guestfs_pvs_full (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_pvs_full_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("pvs_full");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_pvs_full") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_PVS_FULL, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "pvs_full", &hdr, &err,
        (xdrproc_t) xdr_guestfs_pvs_full_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PVS_FULL, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "pvs_full", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.physvols, sizeof (ret.physvols));
}

struct guestfs_lvm_vg_list *guestfs_vgs_full (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_vgs_full_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("vgs_full");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_vgs_full") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_VGS_FULL, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "vgs_full", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vgs_full_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGS_FULL, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "vgs_full", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.volgroups, sizeof (ret.volgroups));
}

struct guestfs_lvm_lv_list *guestfs_lvs_full (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lvs_full_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("lvs_full");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lvs_full") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_LVS_FULL, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lvs_full", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lvs_full_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVS_FULL, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lvs_full", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.logvols, sizeof (ret.logvols));
}

char **guestfs_read_lines (guestfs_h *g,
		const char *path)
{
  struct guestfs_read_lines_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_read_lines_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("read_lines");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_read_lines") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_READ_LINES,
        (xdrproc_t) xdr_guestfs_read_lines_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "read_lines", &hdr, &err,
        (xdrproc_t) xdr_guestfs_read_lines_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_READ_LINES, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "read_lines", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

int guestfs_aug_init (guestfs_h *g,
		const char *root,
		int flags)
{
  struct guestfs_aug_init_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("aug_init");
    printf (" \"%s\"", root);
    printf (" %d", flags);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_aug_init") == -1) return -1;
  guestfs___set_busy (g);

  args.root = (char *) root;
  args.flags = flags;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_INIT,
        (xdrproc_t) xdr_guestfs_aug_init_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_init", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_INIT, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "aug_init", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_aug_close (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("aug_close");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_aug_close") == -1) return -1;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_AUG_CLOSE, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_close", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_CLOSE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "aug_close", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_aug_defvar (guestfs_h *g,
		const char *name,
		const char *expr)
{
  struct guestfs_aug_defvar_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_aug_defvar_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("aug_defvar");
    printf (" \"%s\"", name);
    if (expr) printf (" \"%s\"", expr);
    else printf (" null");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_aug_defvar") == -1) return -1;
  guestfs___set_busy (g);

  args.name = (char *) name;
  args.expr = expr ? (char **) &expr : NULL;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_DEFVAR,
        (xdrproc_t) xdr_guestfs_aug_defvar_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "aug_defvar", &hdr, &err,
        (xdrproc_t) xdr_guestfs_aug_defvar_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_DEFVAR, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "aug_defvar", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.nrnodes;
}

struct guestfs_int_bool *guestfs_aug_defnode (guestfs_h *g,
		const char *name,
		const char *expr,
		const char *val)
{
  struct guestfs_aug_defnode_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_aug_defnode_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("aug_defnode");
    printf (" \"%s\"", name);
    printf (" \"%s\"", expr);
    printf (" \"%s\"", val);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_aug_defnode") == -1) return NULL;
  guestfs___set_busy (g);

  args.name = (char *) name;
  args.expr = (char *) expr;
  args.val = (char *) val;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_DEFNODE,
        (xdrproc_t) xdr_guestfs_aug_defnode_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "aug_defnode", &hdr, &err,
        (xdrproc_t) xdr_guestfs_aug_defnode_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_DEFNODE, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "aug_defnode", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.nrnodescreated, sizeof (ret.nrnodescreated));
}

char *guestfs_aug_get (guestfs_h *g,
		const char *augpath)
{
  struct guestfs_aug_get_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_aug_get_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("aug_get");
    printf (" \"%s\"", augpath);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_aug_get") == -1) return NULL;
  guestfs___set_busy (g);

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_GET,
        (xdrproc_t) xdr_guestfs_aug_get_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "aug_get", &hdr, &err,
        (xdrproc_t) xdr_guestfs_aug_get_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_GET, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "aug_get", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.val; /* caller will free */
}

int guestfs_aug_set (guestfs_h *g,
		const char *augpath,
		const char *val)
{
  struct guestfs_aug_set_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("aug_set");
    printf (" \"%s\"", augpath);
    printf (" \"%s\"", val);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_aug_set") == -1) return -1;
  guestfs___set_busy (g);

  args.augpath = (char *) augpath;
  args.val = (char *) val;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_SET,
        (xdrproc_t) xdr_guestfs_aug_set_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_set", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_SET, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "aug_set", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_aug_insert (guestfs_h *g,
		const char *augpath,
		const char *label,
		int before)
{
  struct guestfs_aug_insert_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("aug_insert");
    printf (" \"%s\"", augpath);
    printf (" \"%s\"", label);
    fputs (before ? " true" : " false", stdout);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_aug_insert") == -1) return -1;
  guestfs___set_busy (g);

  args.augpath = (char *) augpath;
  args.label = (char *) label;
  args.before = before;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_INSERT,
        (xdrproc_t) xdr_guestfs_aug_insert_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_insert", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_INSERT, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "aug_insert", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_aug_rm (guestfs_h *g,
		const char *augpath)
{
  struct guestfs_aug_rm_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_aug_rm_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("aug_rm");
    printf (" \"%s\"", augpath);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_aug_rm") == -1) return -1;
  guestfs___set_busy (g);

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_RM,
        (xdrproc_t) xdr_guestfs_aug_rm_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "aug_rm", &hdr, &err,
        (xdrproc_t) xdr_guestfs_aug_rm_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_RM, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "aug_rm", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.nrnodes;
}

int guestfs_aug_mv (guestfs_h *g,
		const char *src,
		const char *dest)
{
  struct guestfs_aug_mv_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("aug_mv");
    printf (" \"%s\"", src);
    printf (" \"%s\"", dest);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_aug_mv") == -1) return -1;
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_MV,
        (xdrproc_t) xdr_guestfs_aug_mv_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_mv", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_MV, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "aug_mv", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char **guestfs_aug_match (guestfs_h *g,
		const char *augpath)
{
  struct guestfs_aug_match_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_aug_match_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("aug_match");
    printf (" \"%s\"", augpath);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_aug_match") == -1) return NULL;
  guestfs___set_busy (g);

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_MATCH,
        (xdrproc_t) xdr_guestfs_aug_match_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "aug_match", &hdr, &err,
        (xdrproc_t) xdr_guestfs_aug_match_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_MATCH, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "aug_match", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.matches.matches_val =
    safe_realloc (g, ret.matches.matches_val,
                  sizeof (char *) * (ret.matches.matches_len + 1));
  ret.matches.matches_val[ret.matches.matches_len] = NULL;
  return ret.matches.matches_val;
}

int guestfs_aug_save (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("aug_save");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_aug_save") == -1) return -1;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_AUG_SAVE, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_save", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_SAVE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "aug_save", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_aug_load (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("aug_load");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_aug_load") == -1) return -1;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_AUG_LOAD, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_load", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_LOAD, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "aug_load", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char **guestfs_aug_ls (guestfs_h *g,
		const char *augpath)
{
  struct guestfs_aug_ls_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_aug_ls_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("aug_ls");
    printf (" \"%s\"", augpath);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_aug_ls") == -1) return NULL;
  guestfs___set_busy (g);

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_LS,
        (xdrproc_t) xdr_guestfs_aug_ls_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "aug_ls", &hdr, &err,
        (xdrproc_t) xdr_guestfs_aug_ls_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_LS, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "aug_ls", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.matches.matches_val =
    safe_realloc (g, ret.matches.matches_val,
                  sizeof (char *) * (ret.matches.matches_len + 1));
  ret.matches.matches_val[ret.matches.matches_len] = NULL;
  return ret.matches.matches_val;
}

int guestfs_rm (guestfs_h *g,
		const char *path)
{
  struct guestfs_rm_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("rm");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_rm") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_RM,
        (xdrproc_t) xdr_guestfs_rm_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "rm", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_RM, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "rm", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_rmdir (guestfs_h *g,
		const char *path)
{
  struct guestfs_rmdir_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("rmdir");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_rmdir") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_RMDIR,
        (xdrproc_t) xdr_guestfs_rmdir_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "rmdir", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_RMDIR, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "rmdir", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_rm_rf (guestfs_h *g,
		const char *path)
{
  struct guestfs_rm_rf_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("rm_rf");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_rm_rf") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_RM_RF,
        (xdrproc_t) xdr_guestfs_rm_rf_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "rm_rf", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_RM_RF, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "rm_rf", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mkdir (guestfs_h *g,
		const char *path)
{
  struct guestfs_mkdir_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mkdir");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mkdir") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKDIR,
        (xdrproc_t) xdr_guestfs_mkdir_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkdir", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKDIR, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mkdir", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mkdir_p (guestfs_h *g,
		const char *path)
{
  struct guestfs_mkdir_p_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mkdir_p");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mkdir_p") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKDIR_P,
        (xdrproc_t) xdr_guestfs_mkdir_p_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkdir_p", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKDIR_P, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mkdir_p", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_chmod (guestfs_h *g,
		int mode,
		const char *path)
{
  struct guestfs_chmod_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("chmod");
    printf (" %d", mode);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_chmod") == -1) return -1;
  guestfs___set_busy (g);

  args.mode = mode;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CHMOD,
        (xdrproc_t) xdr_guestfs_chmod_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "chmod", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CHMOD, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "chmod", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_chown (guestfs_h *g,
		int owner,
		int group,
		const char *path)
{
  struct guestfs_chown_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("chown");
    printf (" %d", owner);
    printf (" %d", group);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_chown") == -1) return -1;
  guestfs___set_busy (g);

  args.owner = owner;
  args.group = group;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CHOWN,
        (xdrproc_t) xdr_guestfs_chown_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "chown", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CHOWN, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "chown", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_exists (guestfs_h *g,
		const char *path)
{
  struct guestfs_exists_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_exists_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("exists");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_exists") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_EXISTS,
        (xdrproc_t) xdr_guestfs_exists_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "exists", &hdr, &err,
        (xdrproc_t) xdr_guestfs_exists_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_EXISTS, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "exists", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.existsflag;
}

int guestfs_is_file (guestfs_h *g,
		const char *path)
{
  struct guestfs_is_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_file_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("is_file");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_is_file") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_IS_FILE,
        (xdrproc_t) xdr_guestfs_is_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "is_file", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_file_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_IS_FILE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "is_file", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.fileflag;
}

int guestfs_is_dir (guestfs_h *g,
		const char *path)
{
  struct guestfs_is_dir_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_dir_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("is_dir");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_is_dir") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_IS_DIR,
        (xdrproc_t) xdr_guestfs_is_dir_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "is_dir", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_dir_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_IS_DIR, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "is_dir", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.dirflag;
}

int guestfs_pvcreate (guestfs_h *g,
		const char *device)
{
  struct guestfs_pvcreate_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("pvcreate");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_pvcreate") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PVCREATE,
        (xdrproc_t) xdr_guestfs_pvcreate_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "pvcreate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PVCREATE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "pvcreate", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_vgcreate (guestfs_h *g,
		const char *volgroup,
		char *const *physvols)
{
  struct guestfs_vgcreate_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    int i;

    printf ("vgcreate");
    printf (" \"%s\"", volgroup);
    putchar (' ');
    putchar ('"');
    for (i = 0; physvols[i]; ++i) {
      if (i > 0) putchar (' ');
      fputs (physvols[i], stdout);
    }
    putchar ('"');
    putchar ('\n');
  }

  if (check_state (g, "guestfs_vgcreate") == -1) return -1;
  guestfs___set_busy (g);

  args.volgroup = (char *) volgroup;
  args.physvols.physvols_val = (char **) physvols;
  for (args.physvols.physvols_len = 0; physvols[args.physvols.physvols_len]; args.physvols.physvols_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_VGCREATE,
        (xdrproc_t) xdr_guestfs_vgcreate_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "vgcreate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGCREATE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "vgcreate", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_lvcreate (guestfs_h *g,
		const char *logvol,
		const char *volgroup,
		int mbytes)
{
  struct guestfs_lvcreate_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("lvcreate");
    printf (" \"%s\"", logvol);
    printf (" \"%s\"", volgroup);
    printf (" %d", mbytes);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lvcreate") == -1) return -1;
  guestfs___set_busy (g);

  args.logvol = (char *) logvol;
  args.volgroup = (char *) volgroup;
  args.mbytes = mbytes;
  serial = guestfs___send (g, GUESTFS_PROC_LVCREATE,
        (xdrproc_t) xdr_guestfs_lvcreate_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lvcreate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVCREATE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lvcreate", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mkfs (guestfs_h *g,
		const char *fstype,
		const char *device)
{
  struct guestfs_mkfs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mkfs");
    printf (" \"%s\"", fstype);
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mkfs") == -1) return -1;
  guestfs___set_busy (g);

  args.fstype = (char *) fstype;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKFS,
        (xdrproc_t) xdr_guestfs_mkfs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkfs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKFS, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mkfs", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_sfdisk (guestfs_h *g,
		const char *device,
		int cyls,
		int heads,
		int sectors,
		char *const *lines)
{
  struct guestfs_sfdisk_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    int i;

    printf ("sfdisk");
    printf (" \"%s\"", device);
    printf (" %d", cyls);
    printf (" %d", heads);
    printf (" %d", sectors);
    putchar (' ');
    putchar ('"');
    for (i = 0; lines[i]; ++i) {
      if (i > 0) putchar (' ');
      fputs (lines[i], stdout);
    }
    putchar ('"');
    putchar ('\n');
  }

  if (check_state (g, "guestfs_sfdisk") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.cyls = cyls;
  args.heads = heads;
  args.sectors = sectors;
  args.lines.lines_val = (char **) lines;
  for (args.lines.lines_len = 0; lines[args.lines.lines_len]; args.lines.lines_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK,
        (xdrproc_t) xdr_guestfs_sfdisk_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "sfdisk", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SFDISK, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "sfdisk", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_write_file (guestfs_h *g,
		const char *path,
		const char *content,
		int size)
{
  struct guestfs_write_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("write_file");
    printf (" \"%s\"", path);
    printf (" \"%s\"", content);
    printf (" %d", size);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_write_file") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.content = (char *) content;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_WRITE_FILE,
        (xdrproc_t) xdr_guestfs_write_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "write_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_WRITE_FILE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "write_file", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_umount (guestfs_h *g,
		const char *pathordevice)
{
  struct guestfs_umount_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("umount");
    printf (" \"%s\"", pathordevice);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_umount") == -1) return -1;
  guestfs___set_busy (g);

  args.pathordevice = (char *) pathordevice;
  serial = guestfs___send (g, GUESTFS_PROC_UMOUNT,
        (xdrproc_t) xdr_guestfs_umount_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "umount", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_UMOUNT, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "umount", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char **guestfs_mounts (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_mounts_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mounts");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mounts") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_MOUNTS, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "mounts", &hdr, &err,
        (xdrproc_t) xdr_guestfs_mounts_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNTS, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mounts", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.devices.devices_val =
    safe_realloc (g, ret.devices.devices_val,
                  sizeof (char *) * (ret.devices.devices_len + 1));
  ret.devices.devices_val[ret.devices.devices_len] = NULL;
  return ret.devices.devices_val;
}

int guestfs_umount_all (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("umount_all");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_umount_all") == -1) return -1;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_UMOUNT_ALL, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "umount_all", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_UMOUNT_ALL, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "umount_all", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_lvm_remove_all (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("lvm_remove_all");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lvm_remove_all") == -1) return -1;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_LVM_REMOVE_ALL, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lvm_remove_all", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVM_REMOVE_ALL, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lvm_remove_all", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_file (guestfs_h *g,
		const char *path)
{
  struct guestfs_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_file_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("file");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_file") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_FILE,
        (xdrproc_t) xdr_guestfs_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "file", &hdr, &err,
        (xdrproc_t) xdr_guestfs_file_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FILE, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "file", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.description; /* caller will free */
}

char *guestfs_command (guestfs_h *g,
		char *const *arguments)
{
  struct guestfs_command_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_command_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    int i;

    printf ("command");
    putchar (' ');
    putchar ('"');
    for (i = 0; arguments[i]; ++i) {
      if (i > 0) putchar (' ');
      fputs (arguments[i], stdout);
    }
    putchar ('"');
    putchar ('\n');
  }

  if (check_state (g, "guestfs_command") == -1) return NULL;
  guestfs___set_busy (g);

  args.arguments.arguments_val = (char **) arguments;
  for (args.arguments.arguments_len = 0; arguments[args.arguments.arguments_len]; args.arguments.arguments_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_COMMAND,
        (xdrproc_t) xdr_guestfs_command_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "command", &hdr, &err,
        (xdrproc_t) xdr_guestfs_command_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_COMMAND, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "command", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.output; /* caller will free */
}

char **guestfs_command_lines (guestfs_h *g,
		char *const *arguments)
{
  struct guestfs_command_lines_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_command_lines_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    int i;

    printf ("command_lines");
    putchar (' ');
    putchar ('"');
    for (i = 0; arguments[i]; ++i) {
      if (i > 0) putchar (' ');
      fputs (arguments[i], stdout);
    }
    putchar ('"');
    putchar ('\n');
  }

  if (check_state (g, "guestfs_command_lines") == -1) return NULL;
  guestfs___set_busy (g);

  args.arguments.arguments_val = (char **) arguments;
  for (args.arguments.arguments_len = 0; arguments[args.arguments.arguments_len]; args.arguments.arguments_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_COMMAND_LINES,
        (xdrproc_t) xdr_guestfs_command_lines_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "command_lines", &hdr, &err,
        (xdrproc_t) xdr_guestfs_command_lines_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_COMMAND_LINES, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "command_lines", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

struct guestfs_stat *guestfs_stat (guestfs_h *g,
		const char *path)
{
  struct guestfs_stat_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_stat_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("stat");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_stat") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_STAT,
        (xdrproc_t) xdr_guestfs_stat_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "stat", &hdr, &err,
        (xdrproc_t) xdr_guestfs_stat_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_STAT, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "stat", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.statbuf, sizeof (ret.statbuf));
}

struct guestfs_stat *guestfs_lstat (guestfs_h *g,
		const char *path)
{
  struct guestfs_lstat_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lstat_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("lstat");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lstat") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LSTAT,
        (xdrproc_t) xdr_guestfs_lstat_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lstat", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lstat_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LSTAT, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lstat", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.statbuf, sizeof (ret.statbuf));
}

struct guestfs_statvfs *guestfs_statvfs (guestfs_h *g,
		const char *path)
{
  struct guestfs_statvfs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_statvfs_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("statvfs");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_statvfs") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_STATVFS,
        (xdrproc_t) xdr_guestfs_statvfs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "statvfs", &hdr, &err,
        (xdrproc_t) xdr_guestfs_statvfs_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_STATVFS, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "statvfs", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.statbuf, sizeof (ret.statbuf));
}

char **guestfs_tune2fs_l (guestfs_h *g,
		const char *device)
{
  struct guestfs_tune2fs_l_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_tune2fs_l_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("tune2fs_l");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_tune2fs_l") == -1) return NULL;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_TUNE2FS_L,
        (xdrproc_t) xdr_guestfs_tune2fs_l_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "tune2fs_l", &hdr, &err,
        (xdrproc_t) xdr_guestfs_tune2fs_l_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TUNE2FS_L, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "tune2fs_l", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.superblock.superblock_val =
    safe_realloc (g, ret.superblock.superblock_val,
                  sizeof (char *) * (ret.superblock.superblock_len + 1));
  ret.superblock.superblock_val[ret.superblock.superblock_len] = NULL;
  return ret.superblock.superblock_val;
}

int guestfs_blockdev_setro (guestfs_h *g,
		const char *device)
{
  struct guestfs_blockdev_setro_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("blockdev_setro");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_blockdev_setro") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_SETRO,
        (xdrproc_t) xdr_guestfs_blockdev_setro_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "blockdev_setro", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_SETRO, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "blockdev_setro", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_blockdev_setrw (guestfs_h *g,
		const char *device)
{
  struct guestfs_blockdev_setrw_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("blockdev_setrw");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_blockdev_setrw") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_SETRW,
        (xdrproc_t) xdr_guestfs_blockdev_setrw_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "blockdev_setrw", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_SETRW, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "blockdev_setrw", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_blockdev_getro (guestfs_h *g,
		const char *device)
{
  struct guestfs_blockdev_getro_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_blockdev_getro_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("blockdev_getro");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_blockdev_getro") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETRO,
        (xdrproc_t) xdr_guestfs_blockdev_getro_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "blockdev_getro", &hdr, &err,
        (xdrproc_t) xdr_guestfs_blockdev_getro_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_GETRO, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "blockdev_getro", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.ro;
}

int guestfs_blockdev_getss (guestfs_h *g,
		const char *device)
{
  struct guestfs_blockdev_getss_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_blockdev_getss_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("blockdev_getss");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_blockdev_getss") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETSS,
        (xdrproc_t) xdr_guestfs_blockdev_getss_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "blockdev_getss", &hdr, &err,
        (xdrproc_t) xdr_guestfs_blockdev_getss_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_GETSS, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "blockdev_getss", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.sectorsize;
}

int guestfs_blockdev_getbsz (guestfs_h *g,
		const char *device)
{
  struct guestfs_blockdev_getbsz_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_blockdev_getbsz_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("blockdev_getbsz");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_blockdev_getbsz") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETBSZ,
        (xdrproc_t) xdr_guestfs_blockdev_getbsz_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "blockdev_getbsz", &hdr, &err,
        (xdrproc_t) xdr_guestfs_blockdev_getbsz_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_GETBSZ, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "blockdev_getbsz", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.blocksize;
}

int guestfs_blockdev_setbsz (guestfs_h *g,
		const char *device,
		int blocksize)
{
  struct guestfs_blockdev_setbsz_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("blockdev_setbsz");
    printf (" \"%s\"", device);
    printf (" %d", blocksize);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_blockdev_setbsz") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.blocksize = blocksize;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_SETBSZ,
        (xdrproc_t) xdr_guestfs_blockdev_setbsz_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "blockdev_setbsz", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_SETBSZ, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "blockdev_setbsz", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int64_t guestfs_blockdev_getsz (guestfs_h *g,
		const char *device)
{
  struct guestfs_blockdev_getsz_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_blockdev_getsz_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("blockdev_getsz");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_blockdev_getsz") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETSZ,
        (xdrproc_t) xdr_guestfs_blockdev_getsz_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "blockdev_getsz", &hdr, &err,
        (xdrproc_t) xdr_guestfs_blockdev_getsz_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_GETSZ, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "blockdev_getsz", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.sizeinsectors;
}

int64_t guestfs_blockdev_getsize64 (guestfs_h *g,
		const char *device)
{
  struct guestfs_blockdev_getsize64_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_blockdev_getsize64_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("blockdev_getsize64");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_blockdev_getsize64") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETSIZE64,
        (xdrproc_t) xdr_guestfs_blockdev_getsize64_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "blockdev_getsize64", &hdr, &err,
        (xdrproc_t) xdr_guestfs_blockdev_getsize64_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_GETSIZE64, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "blockdev_getsize64", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.sizeinbytes;
}

int guestfs_blockdev_flushbufs (guestfs_h *g,
		const char *device)
{
  struct guestfs_blockdev_flushbufs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("blockdev_flushbufs");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_blockdev_flushbufs") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_FLUSHBUFS,
        (xdrproc_t) xdr_guestfs_blockdev_flushbufs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "blockdev_flushbufs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_FLUSHBUFS, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "blockdev_flushbufs", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_blockdev_rereadpt (guestfs_h *g,
		const char *device)
{
  struct guestfs_blockdev_rereadpt_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("blockdev_rereadpt");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_blockdev_rereadpt") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_REREADPT,
        (xdrproc_t) xdr_guestfs_blockdev_rereadpt_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "blockdev_rereadpt", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_REREADPT, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "blockdev_rereadpt", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_upload (guestfs_h *g,
		const char *filename,
		const char *remotefilename)
{
  struct guestfs_upload_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("upload");
    printf (" \"%s\"", filename);
    printf (" \"%s\"", remotefilename);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_upload") == -1) return -1;
  guestfs___set_busy (g);

  args.remotefilename = (char *) remotefilename;
  serial = guestfs___send (g, GUESTFS_PROC_UPLOAD,
        (xdrproc_t) xdr_guestfs_upload_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  r = guestfs___send_file (g, filename);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "upload", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_UPLOAD, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "upload", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_download (guestfs_h *g,
		const char *remotefilename,
		const char *filename)
{
  struct guestfs_download_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("download");
    printf (" \"%s\"", remotefilename);
    printf (" \"%s\"", filename);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_download") == -1) return -1;
  guestfs___set_busy (g);

  args.remotefilename = (char *) remotefilename;
  serial = guestfs___send (g, GUESTFS_PROC_DOWNLOAD,
        (xdrproc_t) xdr_guestfs_download_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "download", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DOWNLOAD, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "download", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, filename) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_checksum (guestfs_h *g,
		const char *csumtype,
		const char *path)
{
  struct guestfs_checksum_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_checksum_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("checksum");
    printf (" \"%s\"", csumtype);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_checksum") == -1) return NULL;
  guestfs___set_busy (g);

  args.csumtype = (char *) csumtype;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CHECKSUM,
        (xdrproc_t) xdr_guestfs_checksum_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "checksum", &hdr, &err,
        (xdrproc_t) xdr_guestfs_checksum_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CHECKSUM, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "checksum", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.checksum; /* caller will free */
}

int guestfs_tar_in (guestfs_h *g,
		const char *tarfile,
		const char *directory)
{
  struct guestfs_tar_in_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("tar_in");
    printf (" \"%s\"", tarfile);
    printf (" \"%s\"", directory);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_tar_in") == -1) return -1;
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_TAR_IN,
        (xdrproc_t) xdr_guestfs_tar_in_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  r = guestfs___send_file (g, tarfile);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "tar_in", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TAR_IN, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "tar_in", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_tar_out (guestfs_h *g,
		const char *directory,
		const char *tarfile)
{
  struct guestfs_tar_out_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("tar_out");
    printf (" \"%s\"", directory);
    printf (" \"%s\"", tarfile);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_tar_out") == -1) return -1;
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_TAR_OUT,
        (xdrproc_t) xdr_guestfs_tar_out_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "tar_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TAR_OUT, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "tar_out", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, tarfile) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_tgz_in (guestfs_h *g,
		const char *tarball,
		const char *directory)
{
  struct guestfs_tgz_in_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("tgz_in");
    printf (" \"%s\"", tarball);
    printf (" \"%s\"", directory);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_tgz_in") == -1) return -1;
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_TGZ_IN,
        (xdrproc_t) xdr_guestfs_tgz_in_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  r = guestfs___send_file (g, tarball);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "tgz_in", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TGZ_IN, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "tgz_in", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_tgz_out (guestfs_h *g,
		const char *directory,
		const char *tarball)
{
  struct guestfs_tgz_out_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("tgz_out");
    printf (" \"%s\"", directory);
    printf (" \"%s\"", tarball);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_tgz_out") == -1) return -1;
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_TGZ_OUT,
        (xdrproc_t) xdr_guestfs_tgz_out_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "tgz_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TGZ_OUT, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "tgz_out", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, tarball) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mount_ro (guestfs_h *g,
		const char *device,
		const char *mountpoint)
{
  struct guestfs_mount_ro_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mount_ro");
    printf (" \"%s\"", device);
    printf (" \"%s\"", mountpoint);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mount_ro") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_RO,
        (xdrproc_t) xdr_guestfs_mount_ro_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mount_ro", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT_RO, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mount_ro", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mount_options (guestfs_h *g,
		const char *options,
		const char *device,
		const char *mountpoint)
{
  struct guestfs_mount_options_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mount_options");
    printf (" \"%s\"", options);
    printf (" \"%s\"", device);
    printf (" \"%s\"", mountpoint);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mount_options") == -1) return -1;
  guestfs___set_busy (g);

  args.options = (char *) options;
  args.device = (char *) device;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_OPTIONS,
        (xdrproc_t) xdr_guestfs_mount_options_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mount_options", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT_OPTIONS, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mount_options", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mount_vfs (guestfs_h *g,
		const char *options,
		const char *vfstype,
		const char *device,
		const char *mountpoint)
{
  struct guestfs_mount_vfs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mount_vfs");
    printf (" \"%s\"", options);
    printf (" \"%s\"", vfstype);
    printf (" \"%s\"", device);
    printf (" \"%s\"", mountpoint);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mount_vfs") == -1) return -1;
  guestfs___set_busy (g);

  args.options = (char *) options;
  args.vfstype = (char *) vfstype;
  args.device = (char *) device;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_VFS,
        (xdrproc_t) xdr_guestfs_mount_vfs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mount_vfs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT_VFS, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mount_vfs", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_debug (guestfs_h *g,
		const char *subcmd,
		char *const *extraargs)
{
  struct guestfs_debug_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_debug_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    int i;

    printf ("debug");
    printf (" \"%s\"", subcmd);
    putchar (' ');
    putchar ('"');
    for (i = 0; extraargs[i]; ++i) {
      if (i > 0) putchar (' ');
      fputs (extraargs[i], stdout);
    }
    putchar ('"');
    putchar ('\n');
  }

  if (check_state (g, "guestfs_debug") == -1) return NULL;
  guestfs___set_busy (g);

  args.subcmd = (char *) subcmd;
  args.extraargs.extraargs_val = (char **) extraargs;
  for (args.extraargs.extraargs_len = 0; extraargs[args.extraargs.extraargs_len]; args.extraargs.extraargs_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_DEBUG,
        (xdrproc_t) xdr_guestfs_debug_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "debug", &hdr, &err,
        (xdrproc_t) xdr_guestfs_debug_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DEBUG, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "debug", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.result; /* caller will free */
}

int guestfs_lvremove (guestfs_h *g,
		const char *device)
{
  struct guestfs_lvremove_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("lvremove");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lvremove") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_LVREMOVE,
        (xdrproc_t) xdr_guestfs_lvremove_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lvremove", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVREMOVE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lvremove", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_vgremove (guestfs_h *g,
		const char *vgname)
{
  struct guestfs_vgremove_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("vgremove");
    printf (" \"%s\"", vgname);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_vgremove") == -1) return -1;
  guestfs___set_busy (g);

  args.vgname = (char *) vgname;
  serial = guestfs___send (g, GUESTFS_PROC_VGREMOVE,
        (xdrproc_t) xdr_guestfs_vgremove_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "vgremove", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGREMOVE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "vgremove", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_pvremove (guestfs_h *g,
		const char *device)
{
  struct guestfs_pvremove_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("pvremove");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_pvremove") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PVREMOVE,
        (xdrproc_t) xdr_guestfs_pvremove_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "pvremove", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PVREMOVE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "pvremove", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_set_e2label (guestfs_h *g,
		const char *device,
		const char *label)
{
  struct guestfs_set_e2label_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("set_e2label");
    printf (" \"%s\"", device);
    printf (" \"%s\"", label);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_set_e2label") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_SET_E2LABEL,
        (xdrproc_t) xdr_guestfs_set_e2label_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "set_e2label", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SET_E2LABEL, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "set_e2label", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_get_e2label (guestfs_h *g,
		const char *device)
{
  struct guestfs_get_e2label_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_get_e2label_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("get_e2label");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_get_e2label") == -1) return NULL;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_GET_E2LABEL,
        (xdrproc_t) xdr_guestfs_get_e2label_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "get_e2label", &hdr, &err,
        (xdrproc_t) xdr_guestfs_get_e2label_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GET_E2LABEL, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "get_e2label", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.label; /* caller will free */
}

int guestfs_set_e2uuid (guestfs_h *g,
		const char *device,
		const char *uuid)
{
  struct guestfs_set_e2uuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("set_e2uuid");
    printf (" \"%s\"", device);
    printf (" \"%s\"", uuid);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_set_e2uuid") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_SET_E2UUID,
        (xdrproc_t) xdr_guestfs_set_e2uuid_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "set_e2uuid", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SET_E2UUID, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "set_e2uuid", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_get_e2uuid (guestfs_h *g,
		const char *device)
{
  struct guestfs_get_e2uuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_get_e2uuid_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("get_e2uuid");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_get_e2uuid") == -1) return NULL;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_GET_E2UUID,
        (xdrproc_t) xdr_guestfs_get_e2uuid_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "get_e2uuid", &hdr, &err,
        (xdrproc_t) xdr_guestfs_get_e2uuid_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GET_E2UUID, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "get_e2uuid", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.uuid; /* caller will free */
}

int guestfs_fsck (guestfs_h *g,
		const char *fstype,
		const char *device)
{
  struct guestfs_fsck_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_fsck_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("fsck");
    printf (" \"%s\"", fstype);
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_fsck") == -1) return -1;
  guestfs___set_busy (g);

  args.fstype = (char *) fstype;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_FSCK,
        (xdrproc_t) xdr_guestfs_fsck_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "fsck", &hdr, &err,
        (xdrproc_t) xdr_guestfs_fsck_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FSCK, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "fsck", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.status;
}

int guestfs_zero (guestfs_h *g,
		const char *device)
{
  struct guestfs_zero_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("zero");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_zero") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_ZERO,
        (xdrproc_t) xdr_guestfs_zero_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "zero", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZERO, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "zero", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_grub_install (guestfs_h *g,
		const char *root,
		const char *device)
{
  struct guestfs_grub_install_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("grub_install");
    printf (" \"%s\"", root);
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_grub_install") == -1) return -1;
  guestfs___set_busy (g);

  args.root = (char *) root;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_GRUB_INSTALL,
        (xdrproc_t) xdr_guestfs_grub_install_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "grub_install", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GRUB_INSTALL, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "grub_install", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_cp (guestfs_h *g,
		const char *src,
		const char *dest)
{
  struct guestfs_cp_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("cp");
    printf (" \"%s\"", src);
    printf (" \"%s\"", dest);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_cp") == -1) return -1;
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_CP,
        (xdrproc_t) xdr_guestfs_cp_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "cp", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CP, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "cp", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_cp_a (guestfs_h *g,
		const char *src,
		const char *dest)
{
  struct guestfs_cp_a_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("cp_a");
    printf (" \"%s\"", src);
    printf (" \"%s\"", dest);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_cp_a") == -1) return -1;
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_CP_A,
        (xdrproc_t) xdr_guestfs_cp_a_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "cp_a", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CP_A, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "cp_a", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mv (guestfs_h *g,
		const char *src,
		const char *dest)
{
  struct guestfs_mv_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mv");
    printf (" \"%s\"", src);
    printf (" \"%s\"", dest);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mv") == -1) return -1;
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_MV,
        (xdrproc_t) xdr_guestfs_mv_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mv", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MV, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mv", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_drop_caches (guestfs_h *g,
		int whattodrop)
{
  struct guestfs_drop_caches_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("drop_caches");
    printf (" %d", whattodrop);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_drop_caches") == -1) return -1;
  guestfs___set_busy (g);

  args.whattodrop = whattodrop;
  serial = guestfs___send (g, GUESTFS_PROC_DROP_CACHES,
        (xdrproc_t) xdr_guestfs_drop_caches_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "drop_caches", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DROP_CACHES, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "drop_caches", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_dmesg (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_dmesg_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("dmesg");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_dmesg") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_DMESG, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "dmesg", &hdr, &err,
        (xdrproc_t) xdr_guestfs_dmesg_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DMESG, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "dmesg", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.kmsgs; /* caller will free */
}

int guestfs_ping_daemon (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("ping_daemon");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_ping_daemon") == -1) return -1;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_PING_DAEMON, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ping_daemon", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PING_DAEMON, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "ping_daemon", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_equal (guestfs_h *g,
		const char *file1,
		const char *file2)
{
  struct guestfs_equal_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_equal_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("equal");
    printf (" \"%s\"", file1);
    printf (" \"%s\"", file2);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_equal") == -1) return -1;
  guestfs___set_busy (g);

  args.file1 = (char *) file1;
  args.file2 = (char *) file2;
  serial = guestfs___send (g, GUESTFS_PROC_EQUAL,
        (xdrproc_t) xdr_guestfs_equal_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "equal", &hdr, &err,
        (xdrproc_t) xdr_guestfs_equal_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_EQUAL, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "equal", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.equality;
}

char **guestfs_strings (guestfs_h *g,
		const char *path)
{
  struct guestfs_strings_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_strings_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("strings");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_strings") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_STRINGS,
        (xdrproc_t) xdr_guestfs_strings_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "strings", &hdr, &err,
        (xdrproc_t) xdr_guestfs_strings_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_STRINGS, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "strings", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.stringsout.stringsout_val =
    safe_realloc (g, ret.stringsout.stringsout_val,
                  sizeof (char *) * (ret.stringsout.stringsout_len + 1));
  ret.stringsout.stringsout_val[ret.stringsout.stringsout_len] = NULL;
  return ret.stringsout.stringsout_val;
}

char **guestfs_strings_e (guestfs_h *g,
		const char *encoding,
		const char *path)
{
  struct guestfs_strings_e_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_strings_e_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("strings_e");
    printf (" \"%s\"", encoding);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_strings_e") == -1) return NULL;
  guestfs___set_busy (g);

  args.encoding = (char *) encoding;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_STRINGS_E,
        (xdrproc_t) xdr_guestfs_strings_e_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "strings_e", &hdr, &err,
        (xdrproc_t) xdr_guestfs_strings_e_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_STRINGS_E, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "strings_e", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.stringsout.stringsout_val =
    safe_realloc (g, ret.stringsout.stringsout_val,
                  sizeof (char *) * (ret.stringsout.stringsout_len + 1));
  ret.stringsout.stringsout_val[ret.stringsout.stringsout_len] = NULL;
  return ret.stringsout.stringsout_val;
}

char *guestfs_hexdump (guestfs_h *g,
		const char *path)
{
  struct guestfs_hexdump_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_hexdump_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("hexdump");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_hexdump") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_HEXDUMP,
        (xdrproc_t) xdr_guestfs_hexdump_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "hexdump", &hdr, &err,
        (xdrproc_t) xdr_guestfs_hexdump_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_HEXDUMP, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "hexdump", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.dump; /* caller will free */
}

int guestfs_zerofree (guestfs_h *g,
		const char *device)
{
  struct guestfs_zerofree_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("zerofree");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_zerofree") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_ZEROFREE,
        (xdrproc_t) xdr_guestfs_zerofree_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "zerofree", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZEROFREE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "zerofree", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_pvresize (guestfs_h *g,
		const char *device)
{
  struct guestfs_pvresize_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("pvresize");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_pvresize") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PVRESIZE,
        (xdrproc_t) xdr_guestfs_pvresize_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "pvresize", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PVRESIZE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "pvresize", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_sfdisk_N (guestfs_h *g,
		const char *device,
		int partnum,
		int cyls,
		int heads,
		int sectors,
		const char *line)
{
  struct guestfs_sfdisk_N_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("sfdisk_N");
    printf (" \"%s\"", device);
    printf (" %d", partnum);
    printf (" %d", cyls);
    printf (" %d", heads);
    printf (" %d", sectors);
    printf (" \"%s\"", line);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_sfdisk_N") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.partnum = partnum;
  args.cyls = cyls;
  args.heads = heads;
  args.sectors = sectors;
  args.line = (char *) line;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK_N,
        (xdrproc_t) xdr_guestfs_sfdisk_N_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "sfdisk_N", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SFDISK_N, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "sfdisk_N", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_sfdisk_l (guestfs_h *g,
		const char *device)
{
  struct guestfs_sfdisk_l_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_sfdisk_l_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("sfdisk_l");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_sfdisk_l") == -1) return NULL;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK_L,
        (xdrproc_t) xdr_guestfs_sfdisk_l_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "sfdisk_l", &hdr, &err,
        (xdrproc_t) xdr_guestfs_sfdisk_l_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SFDISK_L, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "sfdisk_l", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.partitions; /* caller will free */
}

char *guestfs_sfdisk_kernel_geometry (guestfs_h *g,
		const char *device)
{
  struct guestfs_sfdisk_kernel_geometry_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_sfdisk_kernel_geometry_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("sfdisk_kernel_geometry");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_sfdisk_kernel_geometry") == -1) return NULL;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK_KERNEL_GEOMETRY,
        (xdrproc_t) xdr_guestfs_sfdisk_kernel_geometry_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "sfdisk_kernel_geometry", &hdr, &err,
        (xdrproc_t) xdr_guestfs_sfdisk_kernel_geometry_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SFDISK_KERNEL_GEOMETRY, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "sfdisk_kernel_geometry", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.partitions; /* caller will free */
}

char *guestfs_sfdisk_disk_geometry (guestfs_h *g,
		const char *device)
{
  struct guestfs_sfdisk_disk_geometry_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_sfdisk_disk_geometry_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("sfdisk_disk_geometry");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_sfdisk_disk_geometry") == -1) return NULL;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK_DISK_GEOMETRY,
        (xdrproc_t) xdr_guestfs_sfdisk_disk_geometry_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "sfdisk_disk_geometry", &hdr, &err,
        (xdrproc_t) xdr_guestfs_sfdisk_disk_geometry_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SFDISK_DISK_GEOMETRY, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "sfdisk_disk_geometry", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.partitions; /* caller will free */
}

int guestfs_vg_activate_all (guestfs_h *g,
		int activate)
{
  struct guestfs_vg_activate_all_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("vg_activate_all");
    fputs (activate ? " true" : " false", stdout);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_vg_activate_all") == -1) return -1;
  guestfs___set_busy (g);

  args.activate = activate;
  serial = guestfs___send (g, GUESTFS_PROC_VG_ACTIVATE_ALL,
        (xdrproc_t) xdr_guestfs_vg_activate_all_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "vg_activate_all", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VG_ACTIVATE_ALL, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "vg_activate_all", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_vg_activate (guestfs_h *g,
		int activate,
		char *const *volgroups)
{
  struct guestfs_vg_activate_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    int i;

    printf ("vg_activate");
    fputs (activate ? " true" : " false", stdout);
    putchar (' ');
    putchar ('"');
    for (i = 0; volgroups[i]; ++i) {
      if (i > 0) putchar (' ');
      fputs (volgroups[i], stdout);
    }
    putchar ('"');
    putchar ('\n');
  }

  if (check_state (g, "guestfs_vg_activate") == -1) return -1;
  guestfs___set_busy (g);

  args.activate = activate;
  args.volgroups.volgroups_val = (char **) volgroups;
  for (args.volgroups.volgroups_len = 0; volgroups[args.volgroups.volgroups_len]; args.volgroups.volgroups_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_VG_ACTIVATE,
        (xdrproc_t) xdr_guestfs_vg_activate_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "vg_activate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VG_ACTIVATE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "vg_activate", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_lvresize (guestfs_h *g,
		const char *device,
		int mbytes)
{
  struct guestfs_lvresize_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("lvresize");
    printf (" \"%s\"", device);
    printf (" %d", mbytes);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lvresize") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.mbytes = mbytes;
  serial = guestfs___send (g, GUESTFS_PROC_LVRESIZE,
        (xdrproc_t) xdr_guestfs_lvresize_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lvresize", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVRESIZE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lvresize", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_resize2fs (guestfs_h *g,
		const char *device)
{
  struct guestfs_resize2fs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("resize2fs");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_resize2fs") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_RESIZE2FS,
        (xdrproc_t) xdr_guestfs_resize2fs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "resize2fs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_RESIZE2FS, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "resize2fs", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char **guestfs_find (guestfs_h *g,
		const char *directory)
{
  struct guestfs_find_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_find_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("find");
    printf (" \"%s\"", directory);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_find") == -1) return NULL;
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_FIND,
        (xdrproc_t) xdr_guestfs_find_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "find", &hdr, &err,
        (xdrproc_t) xdr_guestfs_find_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FIND, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "find", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.names.names_val =
    safe_realloc (g, ret.names.names_val,
                  sizeof (char *) * (ret.names.names_len + 1));
  ret.names.names_val[ret.names.names_len] = NULL;
  return ret.names.names_val;
}

int guestfs_e2fsck_f (guestfs_h *g,
		const char *device)
{
  struct guestfs_e2fsck_f_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("e2fsck_f");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_e2fsck_f") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_E2FSCK_F,
        (xdrproc_t) xdr_guestfs_e2fsck_f_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "e2fsck_f", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_E2FSCK_F, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "e2fsck_f", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_sleep (guestfs_h *g,
		int secs)
{
  struct guestfs_sleep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("sleep");
    printf (" %d", secs);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_sleep") == -1) return -1;
  guestfs___set_busy (g);

  args.secs = secs;
  serial = guestfs___send (g, GUESTFS_PROC_SLEEP,
        (xdrproc_t) xdr_guestfs_sleep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "sleep", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SLEEP, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "sleep", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_ntfs_3g_probe (guestfs_h *g,
		int rw,
		const char *device)
{
  struct guestfs_ntfs_3g_probe_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_ntfs_3g_probe_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("ntfs_3g_probe");
    fputs (rw ? " true" : " false", stdout);
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_ntfs_3g_probe") == -1) return -1;
  guestfs___set_busy (g);

  args.rw = rw;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_NTFS_3G_PROBE,
        (xdrproc_t) xdr_guestfs_ntfs_3g_probe_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "ntfs_3g_probe", &hdr, &err,
        (xdrproc_t) xdr_guestfs_ntfs_3g_probe_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_NTFS_3G_PROBE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "ntfs_3g_probe", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.status;
}

char *guestfs_sh (guestfs_h *g,
		const char *command)
{
  struct guestfs_sh_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_sh_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("sh");
    printf (" \"%s\"", command);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_sh") == -1) return NULL;
  guestfs___set_busy (g);

  args.command = (char *) command;
  serial = guestfs___send (g, GUESTFS_PROC_SH,
        (xdrproc_t) xdr_guestfs_sh_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "sh", &hdr, &err,
        (xdrproc_t) xdr_guestfs_sh_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SH, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "sh", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.output; /* caller will free */
}

char **guestfs_sh_lines (guestfs_h *g,
		const char *command)
{
  struct guestfs_sh_lines_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_sh_lines_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("sh_lines");
    printf (" \"%s\"", command);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_sh_lines") == -1) return NULL;
  guestfs___set_busy (g);

  args.command = (char *) command;
  serial = guestfs___send (g, GUESTFS_PROC_SH_LINES,
        (xdrproc_t) xdr_guestfs_sh_lines_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "sh_lines", &hdr, &err,
        (xdrproc_t) xdr_guestfs_sh_lines_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SH_LINES, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "sh_lines", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_glob_expand (guestfs_h *g,
		const char *pattern)
{
  struct guestfs_glob_expand_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_glob_expand_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("glob_expand");
    printf (" \"%s\"", pattern);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_glob_expand") == -1) return NULL;
  guestfs___set_busy (g);

  args.pattern = (char *) pattern;
  serial = guestfs___send (g, GUESTFS_PROC_GLOB_EXPAND,
        (xdrproc_t) xdr_guestfs_glob_expand_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "glob_expand", &hdr, &err,
        (xdrproc_t) xdr_guestfs_glob_expand_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GLOB_EXPAND, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "glob_expand", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.paths.paths_val =
    safe_realloc (g, ret.paths.paths_val,
                  sizeof (char *) * (ret.paths.paths_len + 1));
  ret.paths.paths_val[ret.paths.paths_len] = NULL;
  return ret.paths.paths_val;
}

int guestfs_scrub_device (guestfs_h *g,
		const char *device)
{
  struct guestfs_scrub_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("scrub_device");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_scrub_device") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SCRUB_DEVICE,
        (xdrproc_t) xdr_guestfs_scrub_device_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "scrub_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SCRUB_DEVICE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "scrub_device", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_scrub_file (guestfs_h *g,
		const char *file)
{
  struct guestfs_scrub_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("scrub_file");
    printf (" \"%s\"", file);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_scrub_file") == -1) return -1;
  guestfs___set_busy (g);

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_SCRUB_FILE,
        (xdrproc_t) xdr_guestfs_scrub_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "scrub_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SCRUB_FILE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "scrub_file", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_scrub_freespace (guestfs_h *g,
		const char *dir)
{
  struct guestfs_scrub_freespace_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("scrub_freespace");
    printf (" \"%s\"", dir);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_scrub_freespace") == -1) return -1;
  guestfs___set_busy (g);

  args.dir = (char *) dir;
  serial = guestfs___send (g, GUESTFS_PROC_SCRUB_FREESPACE,
        (xdrproc_t) xdr_guestfs_scrub_freespace_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "scrub_freespace", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SCRUB_FREESPACE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "scrub_freespace", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_mkdtemp (guestfs_h *g,
		const char *template)
{
  struct guestfs_mkdtemp_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_mkdtemp_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mkdtemp");
    printf (" \"%s\"", template);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mkdtemp") == -1) return NULL;
  guestfs___set_busy (g);

  args.template = (char *) template;
  serial = guestfs___send (g, GUESTFS_PROC_MKDTEMP,
        (xdrproc_t) xdr_guestfs_mkdtemp_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "mkdtemp", &hdr, &err,
        (xdrproc_t) xdr_guestfs_mkdtemp_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKDTEMP, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mkdtemp", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.dir; /* caller will free */
}

int guestfs_wc_l (guestfs_h *g,
		const char *path)
{
  struct guestfs_wc_l_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_wc_l_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("wc_l");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_wc_l") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_WC_L,
        (xdrproc_t) xdr_guestfs_wc_l_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "wc_l", &hdr, &err,
        (xdrproc_t) xdr_guestfs_wc_l_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_WC_L, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "wc_l", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.lines;
}

int guestfs_wc_w (guestfs_h *g,
		const char *path)
{
  struct guestfs_wc_w_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_wc_w_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("wc_w");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_wc_w") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_WC_W,
        (xdrproc_t) xdr_guestfs_wc_w_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "wc_w", &hdr, &err,
        (xdrproc_t) xdr_guestfs_wc_w_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_WC_W, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "wc_w", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.words;
}

int guestfs_wc_c (guestfs_h *g,
		const char *path)
{
  struct guestfs_wc_c_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_wc_c_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("wc_c");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_wc_c") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_WC_C,
        (xdrproc_t) xdr_guestfs_wc_c_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "wc_c", &hdr, &err,
        (xdrproc_t) xdr_guestfs_wc_c_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_WC_C, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "wc_c", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.chars;
}

char **guestfs_head (guestfs_h *g,
		const char *path)
{
  struct guestfs_head_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_head_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("head");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_head") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_HEAD,
        (xdrproc_t) xdr_guestfs_head_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "head", &hdr, &err,
        (xdrproc_t) xdr_guestfs_head_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_HEAD, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "head", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_head_n (guestfs_h *g,
		int nrlines,
		const char *path)
{
  struct guestfs_head_n_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_head_n_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("head_n");
    printf (" %d", nrlines);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_head_n") == -1) return NULL;
  guestfs___set_busy (g);

  args.nrlines = nrlines;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_HEAD_N,
        (xdrproc_t) xdr_guestfs_head_n_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "head_n", &hdr, &err,
        (xdrproc_t) xdr_guestfs_head_n_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_HEAD_N, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "head_n", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_tail (guestfs_h *g,
		const char *path)
{
  struct guestfs_tail_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_tail_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("tail");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_tail") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_TAIL,
        (xdrproc_t) xdr_guestfs_tail_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "tail", &hdr, &err,
        (xdrproc_t) xdr_guestfs_tail_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TAIL, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "tail", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_tail_n (guestfs_h *g,
		int nrlines,
		const char *path)
{
  struct guestfs_tail_n_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_tail_n_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("tail_n");
    printf (" %d", nrlines);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_tail_n") == -1) return NULL;
  guestfs___set_busy (g);

  args.nrlines = nrlines;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_TAIL_N,
        (xdrproc_t) xdr_guestfs_tail_n_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "tail_n", &hdr, &err,
        (xdrproc_t) xdr_guestfs_tail_n_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TAIL_N, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "tail_n", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char *guestfs_df (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_df_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("df");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_df") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_DF, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "df", &hdr, &err,
        (xdrproc_t) xdr_guestfs_df_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DF, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "df", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.output; /* caller will free */
}

char *guestfs_df_h (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_df_h_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("df_h");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_df_h") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_DF_H, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "df_h", &hdr, &err,
        (xdrproc_t) xdr_guestfs_df_h_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DF_H, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "df_h", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.output; /* caller will free */
}

int64_t guestfs_du (guestfs_h *g,
		const char *path)
{
  struct guestfs_du_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_du_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("du");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_du") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_DU,
        (xdrproc_t) xdr_guestfs_du_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "du", &hdr, &err,
        (xdrproc_t) xdr_guestfs_du_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DU, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "du", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.sizekb;
}

char **guestfs_initrd_list (guestfs_h *g,
		const char *path)
{
  struct guestfs_initrd_list_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_initrd_list_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("initrd_list");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_initrd_list") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_INITRD_LIST,
        (xdrproc_t) xdr_guestfs_initrd_list_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "initrd_list", &hdr, &err,
        (xdrproc_t) xdr_guestfs_initrd_list_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INITRD_LIST, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "initrd_list", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.filenames.filenames_val =
    safe_realloc (g, ret.filenames.filenames_val,
                  sizeof (char *) * (ret.filenames.filenames_len + 1));
  ret.filenames.filenames_val[ret.filenames.filenames_len] = NULL;
  return ret.filenames.filenames_val;
}

int guestfs_mount_loop (guestfs_h *g,
		const char *file,
		const char *mountpoint)
{
  struct guestfs_mount_loop_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mount_loop");
    printf (" \"%s\"", file);
    printf (" \"%s\"", mountpoint);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mount_loop") == -1) return -1;
  guestfs___set_busy (g);

  args.file = (char *) file;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_LOOP,
        (xdrproc_t) xdr_guestfs_mount_loop_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mount_loop", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT_LOOP, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mount_loop", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mkswap (guestfs_h *g,
		const char *device)
{
  struct guestfs_mkswap_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mkswap");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mkswap") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKSWAP,
        (xdrproc_t) xdr_guestfs_mkswap_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkswap", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKSWAP, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mkswap", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mkswap_L (guestfs_h *g,
		const char *label,
		const char *device)
{
  struct guestfs_mkswap_L_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mkswap_L");
    printf (" \"%s\"", label);
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mkswap_L") == -1) return -1;
  guestfs___set_busy (g);

  args.label = (char *) label;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKSWAP_L,
        (xdrproc_t) xdr_guestfs_mkswap_L_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkswap_L", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKSWAP_L, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mkswap_L", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mkswap_U (guestfs_h *g,
		const char *uuid,
		const char *device)
{
  struct guestfs_mkswap_U_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mkswap_U");
    printf (" \"%s\"", uuid);
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mkswap_U") == -1) return -1;
  guestfs___set_busy (g);

  args.uuid = (char *) uuid;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKSWAP_U,
        (xdrproc_t) xdr_guestfs_mkswap_U_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkswap_U", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKSWAP_U, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mkswap_U", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mknod (guestfs_h *g,
		int mode,
		int devmajor,
		int devminor,
		const char *path)
{
  struct guestfs_mknod_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mknod");
    printf (" %d", mode);
    printf (" %d", devmajor);
    printf (" %d", devminor);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mknod") == -1) return -1;
  guestfs___set_busy (g);

  args.mode = mode;
  args.devmajor = devmajor;
  args.devminor = devminor;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKNOD,
        (xdrproc_t) xdr_guestfs_mknod_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mknod", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKNOD, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mknod", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mkfifo (guestfs_h *g,
		int mode,
		const char *path)
{
  struct guestfs_mkfifo_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mkfifo");
    printf (" %d", mode);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mkfifo") == -1) return -1;
  guestfs___set_busy (g);

  args.mode = mode;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKFIFO,
        (xdrproc_t) xdr_guestfs_mkfifo_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkfifo", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKFIFO, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mkfifo", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mknod_b (guestfs_h *g,
		int mode,
		int devmajor,
		int devminor,
		const char *path)
{
  struct guestfs_mknod_b_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mknod_b");
    printf (" %d", mode);
    printf (" %d", devmajor);
    printf (" %d", devminor);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mknod_b") == -1) return -1;
  guestfs___set_busy (g);

  args.mode = mode;
  args.devmajor = devmajor;
  args.devminor = devminor;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKNOD_B,
        (xdrproc_t) xdr_guestfs_mknod_b_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mknod_b", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKNOD_B, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mknod_b", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mknod_c (guestfs_h *g,
		int mode,
		int devmajor,
		int devminor,
		const char *path)
{
  struct guestfs_mknod_c_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mknod_c");
    printf (" %d", mode);
    printf (" %d", devmajor);
    printf (" %d", devminor);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mknod_c") == -1) return -1;
  guestfs___set_busy (g);

  args.mode = mode;
  args.devmajor = devmajor;
  args.devminor = devminor;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKNOD_C,
        (xdrproc_t) xdr_guestfs_mknod_c_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mknod_c", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKNOD_C, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mknod_c", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_umask (guestfs_h *g,
		int mask)
{
  struct guestfs_umask_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_umask_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("umask");
    printf (" %d", mask);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_umask") == -1) return -1;
  guestfs___set_busy (g);

  args.mask = mask;
  serial = guestfs___send (g, GUESTFS_PROC_UMASK,
        (xdrproc_t) xdr_guestfs_umask_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "umask", &hdr, &err,
        (xdrproc_t) xdr_guestfs_umask_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_UMASK, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "umask", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.oldmask;
}

struct guestfs_dirent_list *guestfs_readdir (guestfs_h *g,
		const char *dir)
{
  struct guestfs_readdir_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_readdir_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("readdir");
    printf (" \"%s\"", dir);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_readdir") == -1) return NULL;
  guestfs___set_busy (g);

  args.dir = (char *) dir;
  serial = guestfs___send (g, GUESTFS_PROC_READDIR,
        (xdrproc_t) xdr_guestfs_readdir_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "readdir", &hdr, &err,
        (xdrproc_t) xdr_guestfs_readdir_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_READDIR, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "readdir", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.entries, sizeof (ret.entries));
}

int guestfs_sfdiskM (guestfs_h *g,
		const char *device,
		char *const *lines)
{
  struct guestfs_sfdiskM_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    int i;

    printf ("sfdiskM");
    printf (" \"%s\"", device);
    putchar (' ');
    putchar ('"');
    for (i = 0; lines[i]; ++i) {
      if (i > 0) putchar (' ');
      fputs (lines[i], stdout);
    }
    putchar ('"');
    putchar ('\n');
  }

  if (check_state (g, "guestfs_sfdiskM") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.lines.lines_val = (char **) lines;
  for (args.lines.lines_len = 0; lines[args.lines.lines_len]; args.lines.lines_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISKM,
        (xdrproc_t) xdr_guestfs_sfdiskM_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "sfdiskM", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SFDISKM, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "sfdiskM", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_zfile (guestfs_h *g,
		const char *meth,
		const char *path)
{
  struct guestfs_zfile_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zfile_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("zfile");
    printf (" \"%s\"", meth);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_zfile") == -1) return NULL;
  guestfs___set_busy (g);

  args.meth = (char *) meth;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZFILE,
        (xdrproc_t) xdr_guestfs_zfile_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zfile", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zfile_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZFILE, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "zfile", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.description; /* caller will free */
}

struct guestfs_xattr_list *guestfs_getxattrs (guestfs_h *g,
		const char *path)
{
  struct guestfs_getxattrs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_getxattrs_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("getxattrs");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_getxattrs") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_GETXATTRS,
        (xdrproc_t) xdr_guestfs_getxattrs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "getxattrs", &hdr, &err,
        (xdrproc_t) xdr_guestfs_getxattrs_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GETXATTRS, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "getxattrs", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.xattrs, sizeof (ret.xattrs));
}

struct guestfs_xattr_list *guestfs_lgetxattrs (guestfs_h *g,
		const char *path)
{
  struct guestfs_lgetxattrs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lgetxattrs_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("lgetxattrs");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lgetxattrs") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LGETXATTRS,
        (xdrproc_t) xdr_guestfs_lgetxattrs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lgetxattrs", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lgetxattrs_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LGETXATTRS, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lgetxattrs", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.xattrs, sizeof (ret.xattrs));
}

int guestfs_setxattr (guestfs_h *g,
		const char *xattr,
		const char *val,
		int vallen,
		const char *path)
{
  struct guestfs_setxattr_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("setxattr");
    printf (" \"%s\"", xattr);
    printf (" \"%s\"", val);
    printf (" %d", vallen);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_setxattr") == -1) return -1;
  guestfs___set_busy (g);

  args.xattr = (char *) xattr;
  args.val = (char *) val;
  args.vallen = vallen;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_SETXATTR,
        (xdrproc_t) xdr_guestfs_setxattr_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "setxattr", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SETXATTR, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "setxattr", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_lsetxattr (guestfs_h *g,
		const char *xattr,
		const char *val,
		int vallen,
		const char *path)
{
  struct guestfs_lsetxattr_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("lsetxattr");
    printf (" \"%s\"", xattr);
    printf (" \"%s\"", val);
    printf (" %d", vallen);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lsetxattr") == -1) return -1;
  guestfs___set_busy (g);

  args.xattr = (char *) xattr;
  args.val = (char *) val;
  args.vallen = vallen;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LSETXATTR,
        (xdrproc_t) xdr_guestfs_lsetxattr_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lsetxattr", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LSETXATTR, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lsetxattr", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_removexattr (guestfs_h *g,
		const char *xattr,
		const char *path)
{
  struct guestfs_removexattr_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("removexattr");
    printf (" \"%s\"", xattr);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_removexattr") == -1) return -1;
  guestfs___set_busy (g);

  args.xattr = (char *) xattr;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_REMOVEXATTR,
        (xdrproc_t) xdr_guestfs_removexattr_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "removexattr", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_REMOVEXATTR, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "removexattr", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_lremovexattr (guestfs_h *g,
		const char *xattr,
		const char *path)
{
  struct guestfs_lremovexattr_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("lremovexattr");
    printf (" \"%s\"", xattr);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lremovexattr") == -1) return -1;
  guestfs___set_busy (g);

  args.xattr = (char *) xattr;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LREMOVEXATTR,
        (xdrproc_t) xdr_guestfs_lremovexattr_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lremovexattr", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LREMOVEXATTR, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lremovexattr", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char **guestfs_mountpoints (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_mountpoints_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mountpoints");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mountpoints") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_MOUNTPOINTS, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "mountpoints", &hdr, &err,
        (xdrproc_t) xdr_guestfs_mountpoints_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNTPOINTS, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mountpoints", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.mps.mps_val =
    safe_realloc (g, ret.mps.mps_val,
                  sizeof (char *) * (ret.mps.mps_len + 1));
  ret.mps.mps_val[ret.mps.mps_len] = NULL;
  return ret.mps.mps_val;
}

int guestfs_mkmountpoint (guestfs_h *g,
		const char *exemptpath)
{
  struct guestfs_mkmountpoint_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mkmountpoint");
    printf (" \"%s\"", exemptpath);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mkmountpoint") == -1) return -1;
  guestfs___set_busy (g);

  args.exemptpath = (char *) exemptpath;
  serial = guestfs___send (g, GUESTFS_PROC_MKMOUNTPOINT,
        (xdrproc_t) xdr_guestfs_mkmountpoint_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkmountpoint", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKMOUNTPOINT, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mkmountpoint", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_rmmountpoint (guestfs_h *g,
		const char *exemptpath)
{
  struct guestfs_rmmountpoint_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("rmmountpoint");
    printf (" \"%s\"", exemptpath);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_rmmountpoint") == -1) return -1;
  guestfs___set_busy (g);

  args.exemptpath = (char *) exemptpath;
  serial = guestfs___send (g, GUESTFS_PROC_RMMOUNTPOINT,
        (xdrproc_t) xdr_guestfs_rmmountpoint_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "rmmountpoint", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_RMMOUNTPOINT, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "rmmountpoint", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_read_file (guestfs_h *g,
		const char *path,
		size_t *size_r)
{
  struct guestfs_read_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_read_file_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("read_file");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_read_file") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_READ_FILE,
        (xdrproc_t) xdr_guestfs_read_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "read_file", &hdr, &err,
        (xdrproc_t) xdr_guestfs_read_file_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_READ_FILE, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "read_file", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* RBufferOut is tricky: If the buffer is zero-length, then
   * _val might be NULL here.  To make the API saner for
   * callers, we turn this case into a unique pointer (using
   * malloc(1)).
   */
  if (ret.content.content_len > 0) {
    *size_r = ret.content.content_len;
    return ret.content.content_val; /* caller will free */
  } else {
    free (ret.content.content_val);
    char *p = safe_malloc (g, 1);
    *size_r = ret.content.content_len;
    return p;
  }
}

char **guestfs_grep (guestfs_h *g,
		const char *regex,
		const char *path)
{
  struct guestfs_grep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_grep_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("grep");
    printf (" \"%s\"", regex);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_grep") == -1) return NULL;
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_GREP,
        (xdrproc_t) xdr_guestfs_grep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "grep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_grep_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GREP, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "grep", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_egrep (guestfs_h *g,
		const char *regex,
		const char *path)
{
  struct guestfs_egrep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_egrep_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("egrep");
    printf (" \"%s\"", regex);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_egrep") == -1) return NULL;
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_EGREP,
        (xdrproc_t) xdr_guestfs_egrep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "egrep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_egrep_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_EGREP, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "egrep", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_fgrep (guestfs_h *g,
		const char *pattern,
		const char *path)
{
  struct guestfs_fgrep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_fgrep_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("fgrep");
    printf (" \"%s\"", pattern);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_fgrep") == -1) return NULL;
  guestfs___set_busy (g);

  args.pattern = (char *) pattern;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_FGREP,
        (xdrproc_t) xdr_guestfs_fgrep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "fgrep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_fgrep_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FGREP, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "fgrep", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_grepi (guestfs_h *g,
		const char *regex,
		const char *path)
{
  struct guestfs_grepi_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_grepi_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("grepi");
    printf (" \"%s\"", regex);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_grepi") == -1) return NULL;
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_GREPI,
        (xdrproc_t) xdr_guestfs_grepi_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "grepi", &hdr, &err,
        (xdrproc_t) xdr_guestfs_grepi_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GREPI, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "grepi", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_egrepi (guestfs_h *g,
		const char *regex,
		const char *path)
{
  struct guestfs_egrepi_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_egrepi_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("egrepi");
    printf (" \"%s\"", regex);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_egrepi") == -1) return NULL;
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_EGREPI,
        (xdrproc_t) xdr_guestfs_egrepi_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "egrepi", &hdr, &err,
        (xdrproc_t) xdr_guestfs_egrepi_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_EGREPI, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "egrepi", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_fgrepi (guestfs_h *g,
		const char *pattern,
		const char *path)
{
  struct guestfs_fgrepi_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_fgrepi_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("fgrepi");
    printf (" \"%s\"", pattern);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_fgrepi") == -1) return NULL;
  guestfs___set_busy (g);

  args.pattern = (char *) pattern;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_FGREPI,
        (xdrproc_t) xdr_guestfs_fgrepi_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "fgrepi", &hdr, &err,
        (xdrproc_t) xdr_guestfs_fgrepi_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FGREPI, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "fgrepi", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_zgrep (guestfs_h *g,
		const char *regex,
		const char *path)
{
  struct guestfs_zgrep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zgrep_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("zgrep");
    printf (" \"%s\"", regex);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_zgrep") == -1) return NULL;
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZGREP,
        (xdrproc_t) xdr_guestfs_zgrep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zgrep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zgrep_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZGREP, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "zgrep", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_zegrep (guestfs_h *g,
		const char *regex,
		const char *path)
{
  struct guestfs_zegrep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zegrep_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("zegrep");
    printf (" \"%s\"", regex);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_zegrep") == -1) return NULL;
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZEGREP,
        (xdrproc_t) xdr_guestfs_zegrep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zegrep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zegrep_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZEGREP, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "zegrep", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_zfgrep (guestfs_h *g,
		const char *pattern,
		const char *path)
{
  struct guestfs_zfgrep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zfgrep_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("zfgrep");
    printf (" \"%s\"", pattern);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_zfgrep") == -1) return NULL;
  guestfs___set_busy (g);

  args.pattern = (char *) pattern;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZFGREP,
        (xdrproc_t) xdr_guestfs_zfgrep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zfgrep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zfgrep_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZFGREP, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "zfgrep", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_zgrepi (guestfs_h *g,
		const char *regex,
		const char *path)
{
  struct guestfs_zgrepi_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zgrepi_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("zgrepi");
    printf (" \"%s\"", regex);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_zgrepi") == -1) return NULL;
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZGREPI,
        (xdrproc_t) xdr_guestfs_zgrepi_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zgrepi", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zgrepi_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZGREPI, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "zgrepi", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_zegrepi (guestfs_h *g,
		const char *regex,
		const char *path)
{
  struct guestfs_zegrepi_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zegrepi_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("zegrepi");
    printf (" \"%s\"", regex);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_zegrepi") == -1) return NULL;
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZEGREPI,
        (xdrproc_t) xdr_guestfs_zegrepi_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zegrepi", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zegrepi_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZEGREPI, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "zegrepi", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char **guestfs_zfgrepi (guestfs_h *g,
		const char *pattern,
		const char *path)
{
  struct guestfs_zfgrepi_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zfgrepi_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("zfgrepi");
    printf (" \"%s\"", pattern);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_zfgrepi") == -1) return NULL;
  guestfs___set_busy (g);

  args.pattern = (char *) pattern;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZFGREPI,
        (xdrproc_t) xdr_guestfs_zfgrepi_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zfgrepi", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zfgrepi_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZFGREPI, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "zfgrepi", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  return ret.lines.lines_val;
}

char *guestfs_realpath (guestfs_h *g,
		const char *path)
{
  struct guestfs_realpath_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_realpath_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("realpath");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_realpath") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_REALPATH,
        (xdrproc_t) xdr_guestfs_realpath_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "realpath", &hdr, &err,
        (xdrproc_t) xdr_guestfs_realpath_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_REALPATH, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "realpath", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.rpath; /* caller will free */
}

int guestfs_ln (guestfs_h *g,
		const char *target,
		const char *linkname)
{
  struct guestfs_ln_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("ln");
    printf (" \"%s\"", target);
    printf (" \"%s\"", linkname);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_ln") == -1) return -1;
  guestfs___set_busy (g);

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs___send (g, GUESTFS_PROC_LN,
        (xdrproc_t) xdr_guestfs_ln_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ln", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LN, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "ln", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_ln_f (guestfs_h *g,
		const char *target,
		const char *linkname)
{
  struct guestfs_ln_f_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("ln_f");
    printf (" \"%s\"", target);
    printf (" \"%s\"", linkname);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_ln_f") == -1) return -1;
  guestfs___set_busy (g);

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs___send (g, GUESTFS_PROC_LN_F,
        (xdrproc_t) xdr_guestfs_ln_f_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ln_f", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LN_F, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "ln_f", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_ln_s (guestfs_h *g,
		const char *target,
		const char *linkname)
{
  struct guestfs_ln_s_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("ln_s");
    printf (" \"%s\"", target);
    printf (" \"%s\"", linkname);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_ln_s") == -1) return -1;
  guestfs___set_busy (g);

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs___send (g, GUESTFS_PROC_LN_S,
        (xdrproc_t) xdr_guestfs_ln_s_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ln_s", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LN_S, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "ln_s", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_ln_sf (guestfs_h *g,
		const char *target,
		const char *linkname)
{
  struct guestfs_ln_sf_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("ln_sf");
    printf (" \"%s\"", target);
    printf (" \"%s\"", linkname);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_ln_sf") == -1) return -1;
  guestfs___set_busy (g);

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs___send (g, GUESTFS_PROC_LN_SF,
        (xdrproc_t) xdr_guestfs_ln_sf_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ln_sf", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LN_SF, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "ln_sf", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_readlink (guestfs_h *g,
		const char *path)
{
  struct guestfs_readlink_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_readlink_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("readlink");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_readlink") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_READLINK,
        (xdrproc_t) xdr_guestfs_readlink_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "readlink", &hdr, &err,
        (xdrproc_t) xdr_guestfs_readlink_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_READLINK, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "readlink", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.link; /* caller will free */
}

int guestfs_fallocate (guestfs_h *g,
		const char *path,
		int len)
{
  struct guestfs_fallocate_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("fallocate");
    printf (" \"%s\"", path);
    printf (" %d", len);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_fallocate") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.len = len;
  serial = guestfs___send (g, GUESTFS_PROC_FALLOCATE,
        (xdrproc_t) xdr_guestfs_fallocate_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "fallocate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FALLOCATE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "fallocate", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_swapon_device (guestfs_h *g,
		const char *device)
{
  struct guestfs_swapon_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("swapon_device");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_swapon_device") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPON_DEVICE,
        (xdrproc_t) xdr_guestfs_swapon_device_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapon_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPON_DEVICE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "swapon_device", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_swapoff_device (guestfs_h *g,
		const char *device)
{
  struct guestfs_swapoff_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("swapoff_device");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_swapoff_device") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPOFF_DEVICE,
        (xdrproc_t) xdr_guestfs_swapoff_device_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapoff_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPOFF_DEVICE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "swapoff_device", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_swapon_file (guestfs_h *g,
		const char *file)
{
  struct guestfs_swapon_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("swapon_file");
    printf (" \"%s\"", file);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_swapon_file") == -1) return -1;
  guestfs___set_busy (g);

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPON_FILE,
        (xdrproc_t) xdr_guestfs_swapon_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapon_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPON_FILE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "swapon_file", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_swapoff_file (guestfs_h *g,
		const char *file)
{
  struct guestfs_swapoff_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("swapoff_file");
    printf (" \"%s\"", file);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_swapoff_file") == -1) return -1;
  guestfs___set_busy (g);

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPOFF_FILE,
        (xdrproc_t) xdr_guestfs_swapoff_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapoff_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPOFF_FILE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "swapoff_file", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_swapon_label (guestfs_h *g,
		const char *label)
{
  struct guestfs_swapon_label_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("swapon_label");
    printf (" \"%s\"", label);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_swapon_label") == -1) return -1;
  guestfs___set_busy (g);

  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPON_LABEL,
        (xdrproc_t) xdr_guestfs_swapon_label_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapon_label", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPON_LABEL, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "swapon_label", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_swapoff_label (guestfs_h *g,
		const char *label)
{
  struct guestfs_swapoff_label_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("swapoff_label");
    printf (" \"%s\"", label);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_swapoff_label") == -1) return -1;
  guestfs___set_busy (g);

  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPOFF_LABEL,
        (xdrproc_t) xdr_guestfs_swapoff_label_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapoff_label", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPOFF_LABEL, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "swapoff_label", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_swapon_uuid (guestfs_h *g,
		const char *uuid)
{
  struct guestfs_swapon_uuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("swapon_uuid");
    printf (" \"%s\"", uuid);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_swapon_uuid") == -1) return -1;
  guestfs___set_busy (g);

  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPON_UUID,
        (xdrproc_t) xdr_guestfs_swapon_uuid_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapon_uuid", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPON_UUID, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "swapon_uuid", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_swapoff_uuid (guestfs_h *g,
		const char *uuid)
{
  struct guestfs_swapoff_uuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("swapoff_uuid");
    printf (" \"%s\"", uuid);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_swapoff_uuid") == -1) return -1;
  guestfs___set_busy (g);

  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPOFF_UUID,
        (xdrproc_t) xdr_guestfs_swapoff_uuid_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapoff_uuid", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPOFF_UUID, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "swapoff_uuid", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mkswap_file (guestfs_h *g,
		const char *path)
{
  struct guestfs_mkswap_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mkswap_file");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mkswap_file") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKSWAP_FILE,
        (xdrproc_t) xdr_guestfs_mkswap_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkswap_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKSWAP_FILE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mkswap_file", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_inotify_init (guestfs_h *g,
		int maxevents)
{
  struct guestfs_inotify_init_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("inotify_init");
    printf (" %d", maxevents);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_inotify_init") == -1) return -1;
  guestfs___set_busy (g);

  args.maxevents = maxevents;
  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_INIT,
        (xdrproc_t) xdr_guestfs_inotify_init_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "inotify_init", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_INIT, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "inotify_init", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int64_t guestfs_inotify_add_watch (guestfs_h *g,
		const char *path,
		int mask)
{
  struct guestfs_inotify_add_watch_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_inotify_add_watch_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("inotify_add_watch");
    printf (" \"%s\"", path);
    printf (" %d", mask);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_inotify_add_watch") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.mask = mask;
  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_ADD_WATCH,
        (xdrproc_t) xdr_guestfs_inotify_add_watch_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "inotify_add_watch", &hdr, &err,
        (xdrproc_t) xdr_guestfs_inotify_add_watch_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_ADD_WATCH, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "inotify_add_watch", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.wd;
}

int guestfs_inotify_rm_watch (guestfs_h *g,
		int wd)
{
  struct guestfs_inotify_rm_watch_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("inotify_rm_watch");
    printf (" %d", wd);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_inotify_rm_watch") == -1) return -1;
  guestfs___set_busy (g);

  args.wd = wd;
  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_RM_WATCH,
        (xdrproc_t) xdr_guestfs_inotify_rm_watch_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "inotify_rm_watch", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_RM_WATCH, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "inotify_rm_watch", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

struct guestfs_inotify_event_list *guestfs_inotify_read (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_inotify_read_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("inotify_read");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_inotify_read") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_READ, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "inotify_read", &hdr, &err,
        (xdrproc_t) xdr_guestfs_inotify_read_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_READ, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "inotify_read", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.events, sizeof (ret.events));
}

char **guestfs_inotify_files (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_inotify_files_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("inotify_files");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_inotify_files") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_FILES, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "inotify_files", &hdr, &err,
        (xdrproc_t) xdr_guestfs_inotify_files_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_FILES, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "inotify_files", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.paths.paths_val =
    safe_realloc (g, ret.paths.paths_val,
                  sizeof (char *) * (ret.paths.paths_len + 1));
  ret.paths.paths_val[ret.paths.paths_len] = NULL;
  return ret.paths.paths_val;
}

int guestfs_inotify_close (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("inotify_close");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_inotify_close") == -1) return -1;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_CLOSE, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "inotify_close", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_CLOSE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "inotify_close", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_setcon (guestfs_h *g,
		const char *context)
{
  struct guestfs_setcon_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("setcon");
    printf (" \"%s\"", context);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_setcon") == -1) return -1;
  guestfs___set_busy (g);

  args.context = (char *) context;
  serial = guestfs___send (g, GUESTFS_PROC_SETCON,
        (xdrproc_t) xdr_guestfs_setcon_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "setcon", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SETCON, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "setcon", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_getcon (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_getcon_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("getcon");
    putchar ('\n');
  }

  if (check_state (g, "guestfs_getcon") == -1) return NULL;
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_GETCON, NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "getcon", &hdr, &err,
        (xdrproc_t) xdr_guestfs_getcon_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GETCON, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "getcon", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.context; /* caller will free */
}

int guestfs_mkfs_b (guestfs_h *g,
		const char *fstype,
		int blocksize,
		const char *device)
{
  struct guestfs_mkfs_b_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mkfs_b");
    printf (" \"%s\"", fstype);
    printf (" %d", blocksize);
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mkfs_b") == -1) return -1;
  guestfs___set_busy (g);

  args.fstype = (char *) fstype;
  args.blocksize = blocksize;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKFS_B,
        (xdrproc_t) xdr_guestfs_mkfs_b_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkfs_b", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKFS_B, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mkfs_b", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mke2journal (guestfs_h *g,
		int blocksize,
		const char *device)
{
  struct guestfs_mke2journal_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mke2journal");
    printf (" %d", blocksize);
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mke2journal") == -1) return -1;
  guestfs___set_busy (g);

  args.blocksize = blocksize;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2JOURNAL,
        (xdrproc_t) xdr_guestfs_mke2journal_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mke2journal", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKE2JOURNAL, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mke2journal", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mke2journal_L (guestfs_h *g,
		int blocksize,
		const char *label,
		const char *device)
{
  struct guestfs_mke2journal_L_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mke2journal_L");
    printf (" %d", blocksize);
    printf (" \"%s\"", label);
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mke2journal_L") == -1) return -1;
  guestfs___set_busy (g);

  args.blocksize = blocksize;
  args.label = (char *) label;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2JOURNAL_L,
        (xdrproc_t) xdr_guestfs_mke2journal_L_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mke2journal_L", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKE2JOURNAL_L, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mke2journal_L", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mke2journal_U (guestfs_h *g,
		int blocksize,
		const char *uuid,
		const char *device)
{
  struct guestfs_mke2journal_U_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mke2journal_U");
    printf (" %d", blocksize);
    printf (" \"%s\"", uuid);
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mke2journal_U") == -1) return -1;
  guestfs___set_busy (g);

  args.blocksize = blocksize;
  args.uuid = (char *) uuid;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2JOURNAL_U,
        (xdrproc_t) xdr_guestfs_mke2journal_U_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mke2journal_U", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKE2JOURNAL_U, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mke2journal_U", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mke2fs_J (guestfs_h *g,
		const char *fstype,
		int blocksize,
		const char *device,
		const char *journal)
{
  struct guestfs_mke2fs_J_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mke2fs_J");
    printf (" \"%s\"", fstype);
    printf (" %d", blocksize);
    printf (" \"%s\"", device);
    printf (" \"%s\"", journal);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mke2fs_J") == -1) return -1;
  guestfs___set_busy (g);

  args.fstype = (char *) fstype;
  args.blocksize = blocksize;
  args.device = (char *) device;
  args.journal = (char *) journal;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2FS_J,
        (xdrproc_t) xdr_guestfs_mke2fs_J_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mke2fs_J", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKE2FS_J, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mke2fs_J", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mke2fs_JL (guestfs_h *g,
		const char *fstype,
		int blocksize,
		const char *device,
		const char *label)
{
  struct guestfs_mke2fs_JL_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mke2fs_JL");
    printf (" \"%s\"", fstype);
    printf (" %d", blocksize);
    printf (" \"%s\"", device);
    printf (" \"%s\"", label);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mke2fs_JL") == -1) return -1;
  guestfs___set_busy (g);

  args.fstype = (char *) fstype;
  args.blocksize = blocksize;
  args.device = (char *) device;
  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2FS_JL,
        (xdrproc_t) xdr_guestfs_mke2fs_JL_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mke2fs_JL", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKE2FS_JL, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mke2fs_JL", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mke2fs_JU (guestfs_h *g,
		const char *fstype,
		int blocksize,
		const char *device,
		const char *uuid)
{
  struct guestfs_mke2fs_JU_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mke2fs_JU");
    printf (" \"%s\"", fstype);
    printf (" %d", blocksize);
    printf (" \"%s\"", device);
    printf (" \"%s\"", uuid);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mke2fs_JU") == -1) return -1;
  guestfs___set_busy (g);

  args.fstype = (char *) fstype;
  args.blocksize = blocksize;
  args.device = (char *) device;
  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2FS_JU,
        (xdrproc_t) xdr_guestfs_mke2fs_JU_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mke2fs_JU", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKE2FS_JU, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mke2fs_JU", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_modprobe (guestfs_h *g,
		const char *modulename)
{
  struct guestfs_modprobe_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("modprobe");
    printf (" \"%s\"", modulename);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_modprobe") == -1) return -1;
  guestfs___set_busy (g);

  args.modulename = (char *) modulename;
  serial = guestfs___send (g, GUESTFS_PROC_MODPROBE,
        (xdrproc_t) xdr_guestfs_modprobe_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "modprobe", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MODPROBE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "modprobe", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_echo_daemon (guestfs_h *g,
		char *const *words)
{
  struct guestfs_echo_daemon_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_echo_daemon_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    int i;

    printf ("echo_daemon");
    putchar (' ');
    putchar ('"');
    for (i = 0; words[i]; ++i) {
      if (i > 0) putchar (' ');
      fputs (words[i], stdout);
    }
    putchar ('"');
    putchar ('\n');
  }

  if (check_state (g, "guestfs_echo_daemon") == -1) return NULL;
  guestfs___set_busy (g);

  args.words.words_val = (char **) words;
  for (args.words.words_len = 0; words[args.words.words_len]; args.words.words_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_ECHO_DAEMON,
        (xdrproc_t) xdr_guestfs_echo_daemon_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "echo_daemon", &hdr, &err,
        (xdrproc_t) xdr_guestfs_echo_daemon_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ECHO_DAEMON, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "echo_daemon", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.output; /* caller will free */
}

int guestfs_find0 (guestfs_h *g,
		const char *directory,
		const char *files)
{
  struct guestfs_find0_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("find0");
    printf (" \"%s\"", directory);
    printf (" \"%s\"", files);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_find0") == -1) return -1;
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_FIND0,
        (xdrproc_t) xdr_guestfs_find0_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "find0", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FIND0, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "find0", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, files) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_case_sensitive_path (guestfs_h *g,
		const char *path)
{
  struct guestfs_case_sensitive_path_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_case_sensitive_path_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("case_sensitive_path");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_case_sensitive_path") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CASE_SENSITIVE_PATH,
        (xdrproc_t) xdr_guestfs_case_sensitive_path_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "case_sensitive_path", &hdr, &err,
        (xdrproc_t) xdr_guestfs_case_sensitive_path_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CASE_SENSITIVE_PATH, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "case_sensitive_path", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.rpath; /* caller will free */
}

char *guestfs_vfs_type (guestfs_h *g,
		const char *device)
{
  struct guestfs_vfs_type_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_vfs_type_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("vfs_type");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_vfs_type") == -1) return NULL;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_VFS_TYPE,
        (xdrproc_t) xdr_guestfs_vfs_type_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "vfs_type", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vfs_type_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VFS_TYPE, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "vfs_type", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.fstype; /* caller will free */
}

int guestfs_truncate (guestfs_h *g,
		const char *path)
{
  struct guestfs_truncate_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("truncate");
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_truncate") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_TRUNCATE,
        (xdrproc_t) xdr_guestfs_truncate_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "truncate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TRUNCATE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "truncate", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_truncate_size (guestfs_h *g,
		const char *path,
		int64_t size)
{
  struct guestfs_truncate_size_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("truncate_size");
    printf (" \"%s\"", path);
    printf (" %" PRIi64, size);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_truncate_size") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_TRUNCATE_SIZE,
        (xdrproc_t) xdr_guestfs_truncate_size_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "truncate_size", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TRUNCATE_SIZE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "truncate_size", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_utimens (guestfs_h *g,
		const char *path,
		int64_t atsecs,
		int64_t atnsecs,
		int64_t mtsecs,
		int64_t mtnsecs)
{
  struct guestfs_utimens_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("utimens");
    printf (" \"%s\"", path);
    printf (" %" PRIi64, atsecs);
    printf (" %" PRIi64, atnsecs);
    printf (" %" PRIi64, mtsecs);
    printf (" %" PRIi64, mtnsecs);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_utimens") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.atsecs = atsecs;
  args.atnsecs = atnsecs;
  args.mtsecs = mtsecs;
  args.mtnsecs = mtnsecs;
  serial = guestfs___send (g, GUESTFS_PROC_UTIMENS,
        (xdrproc_t) xdr_guestfs_utimens_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "utimens", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_UTIMENS, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "utimens", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_mkdir_mode (guestfs_h *g,
		const char *path,
		int mode)
{
  struct guestfs_mkdir_mode_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("mkdir_mode");
    printf (" \"%s\"", path);
    printf (" %d", mode);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_mkdir_mode") == -1) return -1;
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.mode = mode;
  serial = guestfs___send (g, GUESTFS_PROC_MKDIR_MODE,
        (xdrproc_t) xdr_guestfs_mkdir_mode_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkdir_mode", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKDIR_MODE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "mkdir_mode", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_lchown (guestfs_h *g,
		int owner,
		int group,
		const char *path)
{
  struct guestfs_lchown_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("lchown");
    printf (" %d", owner);
    printf (" %d", group);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lchown") == -1) return -1;
  guestfs___set_busy (g);

  args.owner = owner;
  args.group = group;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LCHOWN,
        (xdrproc_t) xdr_guestfs_lchown_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lchown", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LCHOWN, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lchown", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

struct guestfs_stat_list *guestfs_lstatlist (guestfs_h *g,
		const char *path,
		char *const *names)
{
  struct guestfs_lstatlist_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lstatlist_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    int i;

    printf ("lstatlist");
    printf (" \"%s\"", path);
    putchar (' ');
    putchar ('"');
    for (i = 0; names[i]; ++i) {
      if (i > 0) putchar (' ');
      fputs (names[i], stdout);
    }
    putchar ('"');
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lstatlist") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.names.names_val = (char **) names;
  for (args.names.names_len = 0; names[args.names.names_len]; args.names.names_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_LSTATLIST,
        (xdrproc_t) xdr_guestfs_lstatlist_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lstatlist", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lstatlist_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LSTATLIST, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lstatlist", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.statbufs, sizeof (ret.statbufs));
}

struct guestfs_xattr_list *guestfs_lxattrlist (guestfs_h *g,
		const char *path,
		char *const *names)
{
  struct guestfs_lxattrlist_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lxattrlist_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    int i;

    printf ("lxattrlist");
    printf (" \"%s\"", path);
    putchar (' ');
    putchar ('"');
    for (i = 0; names[i]; ++i) {
      if (i > 0) putchar (' ');
      fputs (names[i], stdout);
    }
    putchar ('"');
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lxattrlist") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.names.names_val = (char **) names;
  for (args.names.names_len = 0; names[args.names.names_len]; args.names.names_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_LXATTRLIST,
        (xdrproc_t) xdr_guestfs_lxattrlist_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lxattrlist", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lxattrlist_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LXATTRLIST, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lxattrlist", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.xattrs, sizeof (ret.xattrs));
}

char **guestfs_readlinklist (guestfs_h *g,
		const char *path,
		char *const *names)
{
  struct guestfs_readlinklist_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_readlinklist_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    int i;

    printf ("readlinklist");
    printf (" \"%s\"", path);
    putchar (' ');
    putchar ('"');
    for (i = 0; names[i]; ++i) {
      if (i > 0) putchar (' ');
      fputs (names[i], stdout);
    }
    putchar ('"');
    putchar ('\n');
  }

  if (check_state (g, "guestfs_readlinklist") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.names.names_val = (char **) names;
  for (args.names.names_len = 0; names[args.names.names_len]; args.names.names_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_READLINKLIST,
        (xdrproc_t) xdr_guestfs_readlinklist_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "readlinklist", &hdr, &err,
        (xdrproc_t) xdr_guestfs_readlinklist_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_READLINKLIST, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "readlinklist", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.links.links_val =
    safe_realloc (g, ret.links.links_val,
                  sizeof (char *) * (ret.links.links_len + 1));
  ret.links.links_val[ret.links.links_len] = NULL;
  return ret.links.links_val;
}

char *guestfs_pread (guestfs_h *g,
		const char *path,
		int count,
		int64_t offset,
		size_t *size_r)
{
  struct guestfs_pread_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_pread_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("pread");
    printf (" \"%s\"", path);
    printf (" %d", count);
    printf (" %" PRIi64, offset);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_pread") == -1) return NULL;
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.count = count;
  args.offset = offset;
  serial = guestfs___send (g, GUESTFS_PROC_PREAD,
        (xdrproc_t) xdr_guestfs_pread_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "pread", &hdr, &err,
        (xdrproc_t) xdr_guestfs_pread_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PREAD, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "pread", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* RBufferOut is tricky: If the buffer is zero-length, then
   * _val might be NULL here.  To make the API saner for
   * callers, we turn this case into a unique pointer (using
   * malloc(1)).
   */
  if (ret.content.content_len > 0) {
    *size_r = ret.content.content_len;
    return ret.content.content_val; /* caller will free */
  } else {
    free (ret.content.content_val);
    char *p = safe_malloc (g, 1);
    *size_r = ret.content.content_len;
    return p;
  }
}

int guestfs_part_init (guestfs_h *g,
		const char *device,
		const char *parttype)
{
  struct guestfs_part_init_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("part_init");
    printf (" \"%s\"", device);
    printf (" \"%s\"", parttype);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_part_init") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.parttype = (char *) parttype;
  serial = guestfs___send (g, GUESTFS_PROC_PART_INIT,
        (xdrproc_t) xdr_guestfs_part_init_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "part_init", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_INIT, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "part_init", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_part_add (guestfs_h *g,
		const char *device,
		const char *prlogex,
		int64_t startsect,
		int64_t endsect)
{
  struct guestfs_part_add_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("part_add");
    printf (" \"%s\"", device);
    printf (" \"%s\"", prlogex);
    printf (" %" PRIi64, startsect);
    printf (" %" PRIi64, endsect);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_part_add") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.prlogex = (char *) prlogex;
  args.startsect = startsect;
  args.endsect = endsect;
  serial = guestfs___send (g, GUESTFS_PROC_PART_ADD,
        (xdrproc_t) xdr_guestfs_part_add_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "part_add", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_ADD, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "part_add", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_part_disk (guestfs_h *g,
		const char *device,
		const char *parttype)
{
  struct guestfs_part_disk_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("part_disk");
    printf (" \"%s\"", device);
    printf (" \"%s\"", parttype);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_part_disk") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.parttype = (char *) parttype;
  serial = guestfs___send (g, GUESTFS_PROC_PART_DISK,
        (xdrproc_t) xdr_guestfs_part_disk_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "part_disk", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_DISK, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "part_disk", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_part_set_bootable (guestfs_h *g,
		const char *device,
		int partnum,
		int bootable)
{
  struct guestfs_part_set_bootable_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("part_set_bootable");
    printf (" \"%s\"", device);
    printf (" %d", partnum);
    fputs (bootable ? " true" : " false", stdout);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_part_set_bootable") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.partnum = partnum;
  args.bootable = bootable;
  serial = guestfs___send (g, GUESTFS_PROC_PART_SET_BOOTABLE,
        (xdrproc_t) xdr_guestfs_part_set_bootable_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "part_set_bootable", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_SET_BOOTABLE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "part_set_bootable", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_part_set_name (guestfs_h *g,
		const char *device,
		int partnum,
		const char *name)
{
  struct guestfs_part_set_name_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("part_set_name");
    printf (" \"%s\"", device);
    printf (" %d", partnum);
    printf (" \"%s\"", name);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_part_set_name") == -1) return -1;
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.partnum = partnum;
  args.name = (char *) name;
  serial = guestfs___send (g, GUESTFS_PROC_PART_SET_NAME,
        (xdrproc_t) xdr_guestfs_part_set_name_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "part_set_name", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_SET_NAME, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "part_set_name", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

struct guestfs_partition_list *guestfs_part_list (guestfs_h *g,
		const char *device)
{
  struct guestfs_part_list_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_part_list_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("part_list");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_part_list") == -1) return NULL;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PART_LIST,
        (xdrproc_t) xdr_guestfs_part_list_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "part_list", &hdr, &err,
        (xdrproc_t) xdr_guestfs_part_list_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_LIST, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "part_list", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  return safe_memdup (g, &ret.partitions, sizeof (ret.partitions));
}

char *guestfs_part_get_parttype (guestfs_h *g,
		const char *device)
{
  struct guestfs_part_get_parttype_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_part_get_parttype_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("part_get_parttype");
    printf (" \"%s\"", device);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_part_get_parttype") == -1) return NULL;
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PART_GET_PARTTYPE,
        (xdrproc_t) xdr_guestfs_part_get_parttype_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "part_get_parttype", &hdr, &err,
        (xdrproc_t) xdr_guestfs_part_get_parttype_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_GET_PARTTYPE, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "part_get_parttype", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  return ret.parttype; /* caller will free */
}

int guestfs_fill (guestfs_h *g,
		int c,
		int len,
		const char *path)
{
  struct guestfs_fill_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("fill");
    printf (" %d", c);
    printf (" %d", len);
    printf (" \"%s\"", path);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_fill") == -1) return -1;
  guestfs___set_busy (g);

  args.c = c;
  args.len = len;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_FILL,
        (xdrproc_t) xdr_guestfs_fill_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "fill", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FILL, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "fill", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_available (guestfs_h *g,
		char *const *groups)
{
  struct guestfs_available_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    int i;

    printf ("available");
    putchar (' ');
    putchar ('"');
    for (i = 0; groups[i]; ++i) {
      if (i > 0) putchar (' ');
      fputs (groups[i], stdout);
    }
    putchar ('"');
    putchar ('\n');
  }

  if (check_state (g, "guestfs_available") == -1) return -1;
  guestfs___set_busy (g);

  args.groups.groups_val = (char **) groups;
  for (args.groups.groups_len = 0; groups[args.groups.groups_len]; args.groups.groups_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_AVAILABLE,
        (xdrproc_t) xdr_guestfs_available_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "available", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AVAILABLE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "available", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_dd (guestfs_h *g,
		const char *src,
		const char *dest)
{
  struct guestfs_dd_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("dd");
    printf (" \"%s\"", src);
    printf (" \"%s\"", dest);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_dd") == -1) return -1;
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_DD,
        (xdrproc_t) xdr_guestfs_dd_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "dd", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DD, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "dd", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int64_t guestfs_filesize (guestfs_h *g,
		const char *file)
{
  struct guestfs_filesize_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_filesize_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("filesize");
    printf (" \"%s\"", file);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_filesize") == -1) return -1;
  guestfs___set_busy (g);

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_FILESIZE,
        (xdrproc_t) xdr_guestfs_filesize_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "filesize", &hdr, &err,
        (xdrproc_t) xdr_guestfs_filesize_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FILESIZE, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "filesize", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return ret.size;
}

int guestfs_lvrename (guestfs_h *g,
		const char *logvol,
		const char *newlogvol)
{
  struct guestfs_lvrename_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("lvrename");
    printf (" \"%s\"", logvol);
    printf (" \"%s\"", newlogvol);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_lvrename") == -1) return -1;
  guestfs___set_busy (g);

  args.logvol = (char *) logvol;
  args.newlogvol = (char *) newlogvol;
  serial = guestfs___send (g, GUESTFS_PROC_LVRENAME,
        (xdrproc_t) xdr_guestfs_lvrename_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lvrename", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVRENAME, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "lvrename", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

int guestfs_vgrename (guestfs_h *g,
		const char *volgroup,
		const char *newvolgroup)
{
  struct guestfs_vgrename_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("vgrename");
    printf (" \"%s\"", volgroup);
    printf (" \"%s\"", newvolgroup);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_vgrename") == -1) return -1;
  guestfs___set_busy (g);

  args.volgroup = (char *) volgroup;
  args.newvolgroup = (char *) newvolgroup;
  serial = guestfs___send (g, GUESTFS_PROC_VGRENAME,
        (xdrproc_t) xdr_guestfs_vgrename_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "vgrename", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGRENAME, serial) == -1) {
    guestfs___end_busy (g);
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "vgrename", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  return 0;
}

char *guestfs_initrd_cat (guestfs_h *g,
		const char *initrdpath,
		const char *filename,
		size_t *size_r)
{
  struct guestfs_initrd_cat_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_initrd_cat_ret ret;
  int serial;
  int r;

  if (guestfs__get_trace (g)) {
    printf ("initrd_cat");
    printf (" \"%s\"", initrdpath);
    printf (" \"%s\"", filename);
    putchar ('\n');
  }

  if (check_state (g, "guestfs_initrd_cat") == -1) return NULL;
  guestfs___set_busy (g);

  args.initrdpath = (char *) initrdpath;
  args.filename = (char *) filename;
  serial = guestfs___send (g, GUESTFS_PROC_INITRD_CAT,
        (xdrproc_t) xdr_guestfs_initrd_cat_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "initrd_cat", &hdr, &err,
        (xdrproc_t) xdr_guestfs_initrd_cat_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INITRD_CAT, serial) == -1) {
    guestfs___end_busy (g);
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    error (g, "%s: %s", "initrd_cat", err.error_message);
    free (err.error_message);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* RBufferOut is tricky: If the buffer is zero-length, then
   * _val might be NULL here.  To make the API saner for
   * callers, we turn this case into a unique pointer (using
   * malloc(1)).
   */
  if (ret.content.content_len > 0) {
    *size_r = ret.content.content_len;
    return ret.content.content_val; /* caller will free */
  } else {
    free (ret.content.content_val);
    char *p = safe_malloc (g, 1);
    *size_r = ret.content.content_len;
    return p;
  }
}

/* Structure-freeing functions.  These rely on the fact that the
 * structure format is identical to the XDR format.  See note in
 * generator.ml.
 */

void
guestfs_free_int_bool (struct guestfs_int_bool *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_int_bool, (char *) x);
  free (x);
}

void
guestfs_free_int_bool_list (struct guestfs_int_bool_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_int_bool_list, (char *) x);
  free (x);
}

void
guestfs_free_lvm_pv (struct guestfs_lvm_pv *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_pv, (char *) x);
  free (x);
}

void
guestfs_free_lvm_pv_list (struct guestfs_lvm_pv_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_pv_list, (char *) x);
  free (x);
}

void
guestfs_free_lvm_vg (struct guestfs_lvm_vg *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_vg, (char *) x);
  free (x);
}

void
guestfs_free_lvm_vg_list (struct guestfs_lvm_vg_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_vg_list, (char *) x);
  free (x);
}

void
guestfs_free_lvm_lv (struct guestfs_lvm_lv *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_lv, (char *) x);
  free (x);
}

void
guestfs_free_lvm_lv_list (struct guestfs_lvm_lv_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_lv_list, (char *) x);
  free (x);
}

void
guestfs_free_stat (struct guestfs_stat *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_stat, (char *) x);
  free (x);
}

void
guestfs_free_stat_list (struct guestfs_stat_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_stat_list, (char *) x);
  free (x);
}

void
guestfs_free_statvfs (struct guestfs_statvfs *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_statvfs, (char *) x);
  free (x);
}

void
guestfs_free_statvfs_list (struct guestfs_statvfs_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_statvfs_list, (char *) x);
  free (x);
}

void
guestfs_free_dirent (struct guestfs_dirent *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_dirent, (char *) x);
  free (x);
}

void
guestfs_free_dirent_list (struct guestfs_dirent_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_dirent_list, (char *) x);
  free (x);
}

void
guestfs_free_version (struct guestfs_version *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_version, (char *) x);
  free (x);
}

void
guestfs_free_version_list (struct guestfs_version_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_version_list, (char *) x);
  free (x);
}

void
guestfs_free_xattr (struct guestfs_xattr *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_xattr, (char *) x);
  free (x);
}

void
guestfs_free_xattr_list (struct guestfs_xattr_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_xattr_list, (char *) x);
  free (x);
}

void
guestfs_free_inotify_event (struct guestfs_inotify_event *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_inotify_event, (char *) x);
  free (x);
}

void
guestfs_free_inotify_event_list (struct guestfs_inotify_event_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_inotify_event_list, (char *) x);
  free (x);
}

void
guestfs_free_partition (struct guestfs_partition *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_partition, (char *) x);
  free (x);
}

void
guestfs_free_partition_list (struct guestfs_partition_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_partition_list, (char *) x);
  free (x);
}

