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

extern int guestfs__test0 (guestfs_h *handle, const char *str, const char *optstr, char *const *strlist, int b, int integer, int64_t integer64, const char *filein, const char *fileout);
extern int guestfs__test0rint (guestfs_h *handle, const char *val);
extern int guestfs__test0rinterr (guestfs_h *handle);
extern int64_t guestfs__test0rint64 (guestfs_h *handle, const char *val);
extern int64_t guestfs__test0rint64err (guestfs_h *handle);
extern int guestfs__test0rbool (guestfs_h *handle, const char *val);
extern int guestfs__test0rboolerr (guestfs_h *handle);
extern const char *guestfs__test0rconststring (guestfs_h *handle, const char *val);
extern const char *guestfs__test0rconststringerr (guestfs_h *handle);
extern const char *guestfs__test0rconstoptstring (guestfs_h *handle, const char *val);
extern const char *guestfs__test0rconstoptstringerr (guestfs_h *handle);
extern char *guestfs__test0rstring (guestfs_h *handle, const char *val);
extern char *guestfs__test0rstringerr (guestfs_h *handle);
extern char **guestfs__test0rstringlist (guestfs_h *handle, const char *val);
extern char **guestfs__test0rstringlisterr (guestfs_h *handle);
extern struct guestfs_lvm_pv *guestfs__test0rstruct (guestfs_h *handle, const char *val);
extern struct guestfs_lvm_pv *guestfs__test0rstructerr (guestfs_h *handle);
extern struct guestfs_lvm_pv_list *guestfs__test0rstructlist (guestfs_h *handle, const char *val);
extern struct guestfs_lvm_pv_list *guestfs__test0rstructlisterr (guestfs_h *handle);
extern char **guestfs__test0rhashtable (guestfs_h *handle, const char *val);
extern char **guestfs__test0rhashtableerr (guestfs_h *handle);
extern int guestfs__launch (guestfs_h *handle);
extern int guestfs__wait_ready (guestfs_h *handle);
extern int guestfs__kill_subprocess (guestfs_h *handle);
extern int guestfs__add_drive (guestfs_h *handle, const char *filename);
extern int guestfs__add_cdrom (guestfs_h *handle, const char *filename);
extern int guestfs__add_drive_ro (guestfs_h *handle, const char *filename);
extern int guestfs__config (guestfs_h *handle, const char *qemuparam, const char *qemuvalue);
extern int guestfs__set_qemu (guestfs_h *handle, const char *qemu);
extern const char *guestfs__get_qemu (guestfs_h *handle);
extern int guestfs__set_path (guestfs_h *handle, const char *searchpath);
extern const char *guestfs__get_path (guestfs_h *handle);
extern int guestfs__set_append (guestfs_h *handle, const char *append);
extern const char *guestfs__get_append (guestfs_h *handle);
extern int guestfs__set_autosync (guestfs_h *handle, int autosync);
extern int guestfs__get_autosync (guestfs_h *handle);
extern int guestfs__set_verbose (guestfs_h *handle, int verbose);
extern int guestfs__get_verbose (guestfs_h *handle);
extern int guestfs__is_ready (guestfs_h *handle);
extern int guestfs__is_config (guestfs_h *handle);
extern int guestfs__is_launching (guestfs_h *handle);
extern int guestfs__is_busy (guestfs_h *handle);
extern int guestfs__get_state (guestfs_h *handle);
extern int guestfs__set_memsize (guestfs_h *handle, int memsize);
extern int guestfs__get_memsize (guestfs_h *handle);
extern int guestfs__get_pid (guestfs_h *handle);
extern struct guestfs_version *guestfs__version (guestfs_h *handle);
extern int guestfs__set_selinux (guestfs_h *handle, int selinux);
extern int guestfs__get_selinux (guestfs_h *handle);
extern int guestfs__set_trace (guestfs_h *handle, int trace);
extern int guestfs__get_trace (guestfs_h *handle);
extern int guestfs__set_direct (guestfs_h *handle, int direct);
extern int guestfs__get_direct (guestfs_h *handle);
extern int guestfs__set_recovery_proc (guestfs_h *handle, int recoveryproc);
extern int guestfs__get_recovery_proc (guestfs_h *handle);
extern int guestfs__add_drive_with_if (guestfs_h *handle, const char *filename, const char *iface);
extern int guestfs__add_drive_ro_with_if (guestfs_h *handle, const char *filename, const char *iface);
