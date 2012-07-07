/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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

extern int guestfs__test0 (guestfs_h *g, const char *str, const char *optstr, char *const *strlist, int b, int integer, int64_t integer64, const char *filein, const char *fileout, const char *bufferin, size_t bufferin_size, const struct guestfs_test0_argv *optargs);
extern int guestfs__test0rint (guestfs_h *g, const char *val);
extern int guestfs__test0rinterr (guestfs_h *g);
extern int64_t guestfs__test0rint64 (guestfs_h *g, const char *val);
extern int64_t guestfs__test0rint64err (guestfs_h *g);
extern int guestfs__test0rbool (guestfs_h *g, const char *val);
extern int guestfs__test0rboolerr (guestfs_h *g);
extern const char *guestfs__test0rconststring (guestfs_h *g, const char *val);
extern const char *guestfs__test0rconststringerr (guestfs_h *g);
extern const char *guestfs__test0rconstoptstring (guestfs_h *g, const char *val);
extern const char *guestfs__test0rconstoptstringerr (guestfs_h *g);
extern char *guestfs__test0rstring (guestfs_h *g, const char *val);
extern char *guestfs__test0rstringerr (guestfs_h *g);
extern char **guestfs__test0rstringlist (guestfs_h *g, const char *val);
extern char **guestfs__test0rstringlisterr (guestfs_h *g);
extern struct guestfs_lvm_pv *guestfs__test0rstruct (guestfs_h *g, const char *val);
extern struct guestfs_lvm_pv *guestfs__test0rstructerr (guestfs_h *g);
extern struct guestfs_lvm_pv_list *guestfs__test0rstructlist (guestfs_h *g, const char *val);
extern struct guestfs_lvm_pv_list *guestfs__test0rstructlisterr (guestfs_h *g);
extern char **guestfs__test0rhashtable (guestfs_h *g, const char *val);
extern char **guestfs__test0rhashtableerr (guestfs_h *g);
extern char *guestfs__test0rbufferout (guestfs_h *g, const char *val, size_t *size_r);
extern char *guestfs__test0rbufferouterr (guestfs_h *g, size_t *size_r);
extern int guestfs__launch (guestfs_h *g);
extern int guestfs__wait_ready (guestfs_h *g);
extern int guestfs__kill_subprocess (guestfs_h *g);
extern int guestfs__add_drive (guestfs_h *g, const char *filename);
extern int guestfs__add_cdrom (guestfs_h *g, const char *filename);
extern int guestfs__add_drive_ro (guestfs_h *g, const char *filename);
extern int guestfs__config (guestfs_h *g, const char *qemuparam, const char *qemuvalue);
extern int guestfs__set_qemu (guestfs_h *g, const char *qemu);
extern const char *guestfs__get_qemu (guestfs_h *g);
extern int guestfs__set_path (guestfs_h *g, const char *searchpath);
extern const char *guestfs__get_path (guestfs_h *g);
extern int guestfs__set_append (guestfs_h *g, const char *append);
extern const char *guestfs__get_append (guestfs_h *g);
extern int guestfs__set_autosync (guestfs_h *g, int autosync);
extern int guestfs__get_autosync (guestfs_h *g);
extern int guestfs__set_verbose (guestfs_h *g, int verbose);
extern int guestfs__get_verbose (guestfs_h *g);
extern int guestfs__is_ready (guestfs_h *g);
extern int guestfs__is_config (guestfs_h *g);
extern int guestfs__is_launching (guestfs_h *g);
extern int guestfs__is_busy (guestfs_h *g);
extern int guestfs__get_state (guestfs_h *g);
extern int guestfs__set_memsize (guestfs_h *g, int memsize);
extern int guestfs__get_memsize (guestfs_h *g);
extern int guestfs__get_pid (guestfs_h *g);
extern struct guestfs_version *guestfs__version (guestfs_h *g);
extern int guestfs__set_selinux (guestfs_h *g, int selinux);
extern int guestfs__get_selinux (guestfs_h *g);
extern int guestfs__set_trace (guestfs_h *g, int trace);
extern int guestfs__get_trace (guestfs_h *g);
extern int guestfs__set_direct (guestfs_h *g, int direct);
extern int guestfs__get_direct (guestfs_h *g);
extern int guestfs__set_recovery_proc (guestfs_h *g, int recoveryproc);
extern int guestfs__get_recovery_proc (guestfs_h *g);
extern int guestfs__add_drive_with_if (guestfs_h *g, const char *filename, const char *iface);
extern int guestfs__add_drive_ro_with_if (guestfs_h *g, const char *filename, const char *iface);
extern char *guestfs__file_architecture (guestfs_h *g, const char *filename);
extern char **guestfs__inspect_os (guestfs_h *g);
extern char *guestfs__inspect_get_type (guestfs_h *g, const char *root);
extern char *guestfs__inspect_get_arch (guestfs_h *g, const char *root);
extern char *guestfs__inspect_get_distro (guestfs_h *g, const char *root);
extern int guestfs__inspect_get_major_version (guestfs_h *g, const char *root);
extern int guestfs__inspect_get_minor_version (guestfs_h *g, const char *root);
extern char *guestfs__inspect_get_product_name (guestfs_h *g, const char *root);
extern char **guestfs__inspect_get_mountpoints (guestfs_h *g, const char *root);
extern char **guestfs__inspect_get_filesystems (guestfs_h *g, const char *root);
extern int guestfs__set_network (guestfs_h *g, int network);
extern int guestfs__get_network (guestfs_h *g);
extern char **guestfs__list_filesystems (guestfs_h *g);
extern int guestfs__add_drive_opts (guestfs_h *g, const char *filename, const struct guestfs_add_drive_opts_argv *optargs);
extern char *guestfs__inspect_get_windows_systemroot (guestfs_h *g, const char *root);
extern char **guestfs__inspect_get_roots (guestfs_h *g);
extern char **guestfs__debug_cmdline (guestfs_h *g);
extern char **guestfs__debug_drives (guestfs_h *g);
extern int guestfs__add_domain (guestfs_h *g, const char *dom, const struct guestfs_add_domain_argv *optargs);
extern char *guestfs__inspect_get_package_format (guestfs_h *g, const char *root);
extern char *guestfs__inspect_get_package_management (guestfs_h *g, const char *root);
extern struct guestfs_application_list *guestfs__inspect_list_applications (guestfs_h *g, const char *root);
extern char *guestfs__inspect_get_hostname (guestfs_h *g, const char *root);
extern char *guestfs__inspect_get_format (guestfs_h *g, const char *root);
extern int guestfs__inspect_is_live (guestfs_h *g, const char *root);
extern int guestfs__inspect_is_netinst (guestfs_h *g, const char *root);
extern int guestfs__inspect_is_multipart (guestfs_h *g, const char *root);
extern int guestfs__set_attach_method (guestfs_h *g, const char *attachmethod);
extern char *guestfs__get_attach_method (guestfs_h *g);
extern char *guestfs__inspect_get_product_variant (guestfs_h *g, const char *root);
extern char *guestfs__inspect_get_windows_current_control_set (guestfs_h *g, const char *root);
extern char **guestfs__inspect_get_drive_mappings (guestfs_h *g, const char *root);
extern char *guestfs__inspect_get_icon (guestfs_h *g, const char *root, size_t *size_r, const struct guestfs_inspect_get_icon_argv *optargs);
extern int guestfs__set_pgroup (guestfs_h *g, int pgroup);
extern int guestfs__get_pgroup (guestfs_h *g);
extern int guestfs__set_smp (guestfs_h *g, int smp);
extern int guestfs__get_smp (guestfs_h *g);
extern int guestfs__mount_local (guestfs_h *g, const char *localmountpoint, const struct guestfs_mount_local_argv *optargs);
extern int guestfs__mount_local_run (guestfs_h *g);
extern int guestfs__umount_local (guestfs_h *g, const struct guestfs_umount_local_argv *optargs);
extern int guestfs__shutdown (guestfs_h *g);
