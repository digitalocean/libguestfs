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

#ifndef GUESTFS_INTERNAL_ACTIONS_H_
#define GUESTFS_INTERNAL_ACTIONS_H_

extern int guestfs_impl_add_cdrom (guestfs_h *g, const char *filename);
extern int guestfs_impl_add_domain (guestfs_h *g, const char *dom, const struct guestfs_add_domain_argv *optargs);
extern int guestfs_impl_add_drive_opts (guestfs_h *g, const char *filename, const struct guestfs_add_drive_opts_argv *optargs);
extern int guestfs_impl_add_drive_ro (guestfs_h *g, const char *filename);
extern int guestfs_impl_add_drive_ro_with_if (guestfs_h *g, const char *filename, const char *iface);
extern int guestfs_impl_add_drive_scratch (guestfs_h *g, int64_t size, const struct guestfs_add_drive_scratch_argv *optargs);
extern int guestfs_impl_add_drive_with_if (guestfs_h *g, const char *filename, const char *iface);
extern int guestfs_impl_add_libvirt_dom (guestfs_h *g, void * /* really virDomainPtr */ dom, const struct guestfs_add_libvirt_dom_argv *optargs);
extern int guestfs_impl_available (guestfs_h *g, char *const *groups);
extern int64_t guestfs_impl_c_pointer (guestfs_h *g);
extern char *guestfs_impl_canonical_device_name (guestfs_h *g, const char *device);
extern char *guestfs_impl_cat (guestfs_h *g, const char *path);
extern int guestfs_impl_clear_backend_setting (guestfs_h *g, const char *name);
extern int guestfs_impl_config (guestfs_h *g, const char *hvparam, const char *hvvalue);
extern int guestfs_impl_copy_in (guestfs_h *g, const char *localpath, const char *remotedir);
extern int guestfs_impl_copy_out (guestfs_h *g, const char *remotepath, const char *localdir);
extern char **guestfs_impl_debug_drives (guestfs_h *g);
extern int guestfs_impl_disk_create (guestfs_h *g, const char *filename, const char *format, int64_t size, const struct guestfs_disk_create_argv *optargs);
extern char *guestfs_impl_disk_format (guestfs_h *g, const char *filename);
extern int guestfs_impl_disk_has_backing_file (guestfs_h *g, const char *filename);
extern int64_t guestfs_impl_disk_virtual_size (guestfs_h *g, const char *filename);
extern int guestfs_impl_feature_available (guestfs_h *g, char *const *groups);
extern char *guestfs_impl_file_architecture (guestfs_h *g, const char *filename);
extern struct guestfs_tsk_dirent_list *guestfs_impl_filesystem_walk (guestfs_h *g, const char *device);
extern char **guestfs_impl_find (guestfs_h *g, const char *directory);
extern struct guestfs_tsk_dirent_list *guestfs_impl_find_inode (guestfs_h *g, const char *device, int64_t inode);
extern const char *guestfs_impl_get_append (guestfs_h *g);
extern char *guestfs_impl_get_attach_method (guestfs_h *g);
extern int guestfs_impl_get_autosync (guestfs_h *g);
extern char *guestfs_impl_get_backend (guestfs_h *g);
extern char *guestfs_impl_get_backend_setting (guestfs_h *g, const char *name);
extern char **guestfs_impl_get_backend_settings (guestfs_h *g);
extern char *guestfs_impl_get_cachedir (guestfs_h *g);
extern int guestfs_impl_get_direct (guestfs_h *g);
extern char *guestfs_impl_get_hv (guestfs_h *g);
extern const char *guestfs_impl_get_identifier (guestfs_h *g);
extern char *guestfs_impl_get_libvirt_requested_credential_challenge (guestfs_h *g, int index);
extern char *guestfs_impl_get_libvirt_requested_credential_defresult (guestfs_h *g, int index);
extern char *guestfs_impl_get_libvirt_requested_credential_prompt (guestfs_h *g, int index);
extern char **guestfs_impl_get_libvirt_requested_credentials (guestfs_h *g);
extern int guestfs_impl_get_memsize (guestfs_h *g);
extern int guestfs_impl_get_network (guestfs_h *g);
extern const char *guestfs_impl_get_path (guestfs_h *g);
extern int guestfs_impl_get_pgroup (guestfs_h *g);
extern int guestfs_impl_get_pid (guestfs_h *g);
extern const char *guestfs_impl_get_program (guestfs_h *g);
extern const char *guestfs_impl_get_qemu (guestfs_h *g);
extern int guestfs_impl_get_recovery_proc (guestfs_h *g);
extern int guestfs_impl_get_selinux (guestfs_h *g);
extern int guestfs_impl_get_smp (guestfs_h *g);
extern char *guestfs_impl_get_sockdir (guestfs_h *g);
extern int guestfs_impl_get_state (guestfs_h *g);
extern char *guestfs_impl_get_tmpdir (guestfs_h *g);
extern int guestfs_impl_get_trace (guestfs_h *g);
extern int guestfs_impl_get_verbose (guestfs_h *g);
extern char *guestfs_impl_hivex_value_utf8 (guestfs_h *g, int64_t valueh);
extern char *guestfs_impl_inspect_get_arch (guestfs_h *g, const char *root);
extern char *guestfs_impl_inspect_get_distro (guestfs_h *g, const char *root);
extern char **guestfs_impl_inspect_get_drive_mappings (guestfs_h *g, const char *root);
extern char **guestfs_impl_inspect_get_filesystems (guestfs_h *g, const char *root);
extern char *guestfs_impl_inspect_get_format (guestfs_h *g, const char *root);
extern char *guestfs_impl_inspect_get_hostname (guestfs_h *g, const char *root);
extern char *guestfs_impl_inspect_get_icon (guestfs_h *g, const char *root, size_t *size_r, const struct guestfs_inspect_get_icon_argv *optargs);
extern int guestfs_impl_inspect_get_major_version (guestfs_h *g, const char *root);
extern int guestfs_impl_inspect_get_minor_version (guestfs_h *g, const char *root);
extern char **guestfs_impl_inspect_get_mountpoints (guestfs_h *g, const char *root);
extern char *guestfs_impl_inspect_get_package_format (guestfs_h *g, const char *root);
extern char *guestfs_impl_inspect_get_package_management (guestfs_h *g, const char *root);
extern char *guestfs_impl_inspect_get_product_name (guestfs_h *g, const char *root);
extern char *guestfs_impl_inspect_get_product_variant (guestfs_h *g, const char *root);
extern char **guestfs_impl_inspect_get_roots (guestfs_h *g);
extern char *guestfs_impl_inspect_get_type (guestfs_h *g, const char *root);
extern char *guestfs_impl_inspect_get_windows_current_control_set (guestfs_h *g, const char *root);
extern char *guestfs_impl_inspect_get_windows_software_hive (guestfs_h *g, const char *root);
extern char *guestfs_impl_inspect_get_windows_system_hive (guestfs_h *g, const char *root);
extern char *guestfs_impl_inspect_get_windows_systemroot (guestfs_h *g, const char *root);
extern int guestfs_impl_inspect_is_live (guestfs_h *g, const char *root);
extern int guestfs_impl_inspect_is_multipart (guestfs_h *g, const char *root);
extern int guestfs_impl_inspect_is_netinst (guestfs_h *g, const char *root);
extern struct guestfs_application_list *guestfs_impl_inspect_list_applications (guestfs_h *g, const char *root);
extern struct guestfs_application2_list *guestfs_impl_inspect_list_applications2 (guestfs_h *g, const char *root);
extern char **guestfs_impl_inspect_os (guestfs_h *g);
extern int guestfs_impl_internal_test (guestfs_h *g, const char *str, const char *optstr, char *const *strlist, int b, int integer, int64_t integer64, const char *filein, const char *fileout, const char *bufferin, size_t bufferin_size, const struct guestfs_internal_test_argv *optargs);
extern int guestfs_impl_internal_test_63_optargs (guestfs_h *g, const struct guestfs_internal_test_63_optargs_argv *optargs);
extern int guestfs_impl_internal_test_close_output (guestfs_h *g);
extern int guestfs_impl_internal_test_only_optargs (guestfs_h *g, const struct guestfs_internal_test_only_optargs_argv *optargs);
extern int guestfs_impl_internal_test_rbool (guestfs_h *g, const char *val);
extern int guestfs_impl_internal_test_rboolerr (guestfs_h *g);
extern char *guestfs_impl_internal_test_rbufferout (guestfs_h *g, const char *val, size_t *size_r);
extern char *guestfs_impl_internal_test_rbufferouterr (guestfs_h *g, size_t *size_r);
extern const char *guestfs_impl_internal_test_rconstoptstring (guestfs_h *g, const char *val);
extern const char *guestfs_impl_internal_test_rconstoptstringerr (guestfs_h *g);
extern const char *guestfs_impl_internal_test_rconststring (guestfs_h *g, const char *val);
extern const char *guestfs_impl_internal_test_rconststringerr (guestfs_h *g);
extern char **guestfs_impl_internal_test_rhashtable (guestfs_h *g, const char *val);
extern char **guestfs_impl_internal_test_rhashtableerr (guestfs_h *g);
extern int guestfs_impl_internal_test_rint (guestfs_h *g, const char *val);
extern int64_t guestfs_impl_internal_test_rint64 (guestfs_h *g, const char *val);
extern int64_t guestfs_impl_internal_test_rint64err (guestfs_h *g);
extern int guestfs_impl_internal_test_rinterr (guestfs_h *g);
extern char *guestfs_impl_internal_test_rstring (guestfs_h *g, const char *val);
extern char *guestfs_impl_internal_test_rstringerr (guestfs_h *g);
extern char **guestfs_impl_internal_test_rstringlist (guestfs_h *g, const char *val);
extern char **guestfs_impl_internal_test_rstringlisterr (guestfs_h *g);
extern struct guestfs_lvm_pv *guestfs_impl_internal_test_rstruct (guestfs_h *g, const char *val);
extern struct guestfs_lvm_pv *guestfs_impl_internal_test_rstructerr (guestfs_h *g);
extern struct guestfs_lvm_pv_list *guestfs_impl_internal_test_rstructlist (guestfs_h *g, const char *val);
extern struct guestfs_lvm_pv_list *guestfs_impl_internal_test_rstructlisterr (guestfs_h *g);
extern int guestfs_impl_internal_test_set_output (guestfs_h *g, const char *filename);
extern int guestfs_impl_is_busy (guestfs_h *g);
extern int guestfs_impl_is_config (guestfs_h *g);
extern int guestfs_impl_is_launching (guestfs_h *g);
extern int guestfs_impl_is_ready (guestfs_h *g);
extern struct guestfs_xattr_list *guestfs_impl_journal_get (guestfs_h *g);
extern int guestfs_impl_kill_subprocess (guestfs_h *g);
extern int guestfs_impl_launch (guestfs_h *g);
extern char **guestfs_impl_list_filesystems (guestfs_h *g);
extern char **guestfs_impl_ls (guestfs_h *g, const char *directory);
extern struct guestfs_stat *guestfs_impl_lstat (guestfs_h *g, const char *path);
extern struct guestfs_stat_list *guestfs_impl_lstatlist (guestfs_h *g, const char *path, char *const *names);
extern struct guestfs_statns_list *guestfs_impl_lstatnslist (guestfs_h *g, const char *path, char *const *names);
extern struct guestfs_xattr_list *guestfs_impl_lxattrlist (guestfs_h *g, const char *path, char *const *names);
extern int guestfs_impl_max_disks (guestfs_h *g);
extern int guestfs_impl_mount_local (guestfs_h *g, const char *localmountpoint, const struct guestfs_mount_local_argv *optargs);
extern int guestfs_impl_mount_local_run (guestfs_h *g);
extern char *guestfs_impl_mountable_device (guestfs_h *g, const char *mountable);
extern char *guestfs_impl_mountable_subvolume (guestfs_h *g, const char *mountable);
extern int guestfs_impl_parse_environment (guestfs_h *g);
extern int guestfs_impl_parse_environment_list (guestfs_h *g, char *const *environment);
extern char *guestfs_impl_read_file (guestfs_h *g, const char *path, size_t *size_r);
extern char **guestfs_impl_read_lines (guestfs_h *g, const char *path);
extern char **guestfs_impl_readlinklist (guestfs_h *g, const char *path, char *const *names);
extern int guestfs_impl_remove_drive (guestfs_h *g, const char *label);
extern int guestfs_impl_set_append (guestfs_h *g, const char *append);
extern int guestfs_impl_set_attach_method (guestfs_h *g, const char *backend);
extern int guestfs_impl_set_autosync (guestfs_h *g, int autosync);
extern int guestfs_impl_set_backend (guestfs_h *g, const char *backend);
extern int guestfs_impl_set_backend_setting (guestfs_h *g, const char *name, const char *val);
extern int guestfs_impl_set_backend_settings (guestfs_h *g, char *const *settings);
extern int guestfs_impl_set_cachedir (guestfs_h *g, const char *cachedir);
extern int guestfs_impl_set_direct (guestfs_h *g, int direct);
extern int guestfs_impl_set_hv (guestfs_h *g, const char *hv);
extern int guestfs_impl_set_identifier (guestfs_h *g, const char *identifier);
extern int guestfs_impl_set_libvirt_requested_credential (guestfs_h *g, int index, const char *cred, size_t cred_size);
extern int guestfs_impl_set_libvirt_supported_credentials (guestfs_h *g, char *const *creds);
extern int guestfs_impl_set_memsize (guestfs_h *g, int memsize);
extern int guestfs_impl_set_network (guestfs_h *g, int network);
extern int guestfs_impl_set_path (guestfs_h *g, const char *searchpath);
extern int guestfs_impl_set_pgroup (guestfs_h *g, int pgroup);
extern int guestfs_impl_set_program (guestfs_h *g, const char *program);
extern int guestfs_impl_set_qemu (guestfs_h *g, const char *hv);
extern int guestfs_impl_set_recovery_proc (guestfs_h *g, int recoveryproc);
extern int guestfs_impl_set_selinux (guestfs_h *g, int selinux);
extern int guestfs_impl_set_smp (guestfs_h *g, int smp);
extern int guestfs_impl_set_tmpdir (guestfs_h *g, const char *tmpdir);
extern int guestfs_impl_set_trace (guestfs_h *g, int trace);
extern int guestfs_impl_set_verbose (guestfs_h *g, int verbose);
extern int guestfs_impl_shutdown (guestfs_h *g);
extern struct guestfs_stat *guestfs_impl_stat (guestfs_h *g, const char *path);
extern int guestfs_impl_umount_local (guestfs_h *g, const struct guestfs_umount_local_argv *optargs);
extern int guestfs_impl_user_cancel (guestfs_h *g);
extern struct guestfs_version *guestfs_impl_version (guestfs_h *g);
extern int guestfs_impl_wait_ready (guestfs_h *g);
extern int guestfs_impl_write (guestfs_h *g, const char *path, const char *content, size_t content_size);
extern int guestfs_impl_write_append (guestfs_h *g, const char *path, const char *content, size_t content_size);

#endif /* GUESTFS_INTERNAL_ACTIONS_H_ */
