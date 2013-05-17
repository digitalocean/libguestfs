/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2013 Red Hat Inc.
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

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "guestfs.h"
#include "guestfs-internal-frontend.h"

#include "tests.h"

void
no_test_warnings (void)
{
  size_t i;
  const char *no_tests[] = {
    "add_cdrom",
    "add_domain",
    "add_drive",
    "add_drive_ro",
    "add_drive_ro_with_if",
    "add_drive_with_if",
    "aug_clear",
    "aug_close",
    "aug_defnode",
    "aug_defvar",
    "aug_get",
    "aug_init",
    "aug_insert",
    "aug_load",
    "aug_ls",
    "aug_match",
    "aug_mv",
    "aug_rm",
    "aug_save",
    "aug_set",
    "base64_out",
    "blockdev_getbsz",
    "blockdev_setbsz",
    "btrfs_device_add",
    "btrfs_device_delete",
    "btrfs_filesystem_resize",
    "btrfs_subvolume_list",
    "btrfs_subvolume_set_default",
    "canonical_device_name",
    "checksums_out",
    "chown",
    "compress_device_out",
    "compress_out",
    "config",
    "copy_device_to_device",
    "copy_device_to_file",
    "copy_file_to_device",
    "debug",
    "debug_drives",
    "debug_upload",
    "df",
    "df_h",
    "extlinux",
    "filesystem_available",
    "fill_dir",
    "find0",
    "findfs_label",
    "findfs_uuid",
    "fstrim",
    "get_append",
    "get_cachedir",
    "get_direct",
    "get_libvirt_requested_credential_challenge",
    "get_libvirt_requested_credential_defresult",
    "get_libvirt_requested_credential_prompt",
    "get_libvirt_requested_credentials",
    "get_network",
    "get_pgroup",
    "get_pid",
    "get_recovery_proc",
    "get_selinux",
    "get_smp",
    "get_state",
    "get_tmpdir",
    "get_verbose",
    "getcon",
    "getxattr",
    "getxattrs",
    "hivex_close",
    "hivex_commit",
    "hivex_node_add_child",
    "hivex_node_children",
    "hivex_node_delete_child",
    "hivex_node_get_child",
    "hivex_node_get_value",
    "hivex_node_name",
    "hivex_node_parent",
    "hivex_node_set_value",
    "hivex_node_values",
    "hivex_open",
    "hivex_root",
    "hivex_value_key",
    "hivex_value_type",
    "hivex_value_utf8",
    "hivex_value_value",
    "inotify_close",
    "inotify_read",
    "inotify_rm_watch",
    "inspect_get_arch",
    "inspect_get_distro",
    "inspect_get_drive_mappings",
    "inspect_get_filesystems",
    "inspect_get_format",
    "inspect_get_hostname",
    "inspect_get_icon",
    "inspect_get_major_version",
    "inspect_get_minor_version",
    "inspect_get_mountpoints",
    "inspect_get_package_format",
    "inspect_get_package_management",
    "inspect_get_product_name",
    "inspect_get_product_variant",
    "inspect_get_roots",
    "inspect_get_type",
    "inspect_get_windows_current_control_set",
    "inspect_get_windows_systemroot",
    "inspect_is_live",
    "inspect_is_multipart",
    "inspect_is_netinst",
    "inspect_list_applications",
    "inspect_list_applications2",
    "inspect_os",
    "internal_autosync",
    "internal_hot_add_drive",
    "internal_hot_remove_drive",
    "internal_hot_remove_drive_precheck",
    "internal_lstatlist",
    "internal_lxattrlist",
    "internal_parse_mountable",
    "internal_readlinklist",
    "internal_rhbz914931",
    "internal_set_libvirt_selinux_label",
    "internal_set_libvirt_selinux_norelabel_disks",
    "internal_test",
    "internal_test_63_optargs",
    "internal_test_close_output",
    "internal_test_only_optargs",
    "internal_test_rbool",
    "internal_test_rboolerr",
    "internal_test_rbufferout",
    "internal_test_rbufferouterr",
    "internal_test_rconstoptstring",
    "internal_test_rconstoptstringerr",
    "internal_test_rconststring",
    "internal_test_rconststringerr",
    "internal_test_rhashtable",
    "internal_test_rhashtableerr",
    "internal_test_rint",
    "internal_test_rint64",
    "internal_test_rint64err",
    "internal_test_rinterr",
    "internal_test_rstring",
    "internal_test_rstringerr",
    "internal_test_rstringlist",
    "internal_test_rstringlisterr",
    "internal_test_rstruct",
    "internal_test_rstructerr",
    "internal_test_rstructlist",
    "internal_test_rstructlisterr",
    "internal_test_set_output",
    "isoinfo",
    "kill_subprocess",
    "launch",
    "lchown",
    "ldmtool_create_all",
    "ldmtool_diskgroup_disks",
    "ldmtool_diskgroup_name",
    "ldmtool_diskgroup_volumes",
    "ldmtool_remove_all",
    "ldmtool_scan",
    "ldmtool_scan_devices",
    "ldmtool_volume_hint",
    "ldmtool_volume_partitions",
    "ldmtool_volume_type",
    "lgetxattr",
    "lgetxattrs",
    "list_9p",
    "list_disk_labels",
    "list_dm_devices",
    "list_filesystems",
    "list_ldm_partitions",
    "list_ldm_volumes",
    "list_md_devices",
    "ll",
    "llz",
    "lremovexattr",
    "ls0",
    "lsetxattr",
    "lstatlist",
    "luks_add_key",
    "luks_close",
    "luks_format",
    "luks_format_cipher",
    "luks_kill_slot",
    "luks_open",
    "luks_open_ro",
    "lvm_clear_filter",
    "lvm_remove_all",
    "lvm_set_filter",
    "lvs_full",
    "lvuuid",
    "lxattrlist",
    "max_disks",
    "md_create",
    "md_detail",
    "md_stat",
    "md_stop",
    "mkmountpoint",
    "mount_9p",
    "mount_local",
    "mount_local_run",
    "mount_loop",
    "mount_options",
    "mount_vfs",
    "mountpoints",
    "ntfsclone_in",
    "ntfsclone_out",
    "ntfsresize",
    "ntfsresize_size",
    "parse_environment",
    "parse_environment_list",
    "part_list",
    "pvresize",
    "pvresize_size",
    "pvs_full",
    "pvuuid",
    "readdir",
    "readlinklist",
    "remove_drive",
    "removexattr",
    "resize2fs_M",
    "resize2fs_size",
    "rmmountpoint",
    "rsync",
    "rsync_in",
    "rsync_out",
    "scrub_freespace",
    "set_append",
    "set_attach_method",
    "set_autosync",
    "set_backend",
    "set_cachedir",
    "set_direct",
    "set_libvirt_requested_credential",
    "set_libvirt_supported_credentials",
    "set_memsize",
    "set_network",
    "set_path",
    "set_pgroup",
    "set_program",
    "set_qemu",
    "set_recovery_proc",
    "set_selinux",
    "set_smp",
    "set_tmpdir",
    "set_verbose",
    "setcon",
    "setxattr",
    "sfdisk",
    "sfdiskM",
    "sfdisk_N",
    "sfdisk_disk_geometry",
    "sfdisk_kernel_geometry",
    "sfdisk_l",
    "sh",
    "sh_lines",
    "shutdown",
    "syslinux",
    "tar_out",
    "tgz_out",
    "txz_out",
    "umount_local",
    "user_cancel",
    "vg_activate_all",
    "vglvuuids",
    "vgmeta",
    "vgpvuuids",
    "vgs_full",
    "vguuid",
    "wait_ready",
    "zfile",
    NULL
  };

  for (i = 0; no_tests[i] != NULL; ++i)
    fprintf (stderr, "warning: \"guestfs_%s\" has no tests\n",
             no_tests[i]);
}

static int
test_feature_available_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "feature_available") == NULL;
  str = getenv ("SKIP_TEST_FEATURE_AVAILABLE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FEATURE_AVAILABLE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_feature_available_0 (guestfs_h *g)
{
  if (test_feature_available_0_skip ()) {
    skipped ("test_feature_available_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultTrue for feature_available (0) */
  const char *const _arg1[1] = { NULL };
  int ret;
  ret = guestfs_feature_available (g, (char **) _arg1);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_feature_available_0", "feature_available");
    return -1;
  }
  return 0;
}

static int
test_is_whole_device_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_whole_device") == NULL;
  str = getenv ("SKIP_TEST_IS_WHOLE_DEVICE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_WHOLE_DEVICE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_whole_device_0 (guestfs_h *g)
{
  if (test_is_whole_device_0_skip ()) {
    skipped ("test_is_whole_device_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultTrue for is_whole_device (0) */
  const char *_arg3 = "/dev/sda";
  int ret;
  ret = guestfs_is_whole_device (g, _arg3);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_whole_device_0", "is_whole_device");
    return -1;
  }
  return 0;
}

static int
test_is_whole_device_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_whole_device") == NULL;
  str = getenv ("SKIP_TEST_IS_WHOLE_DEVICE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_WHOLE_DEVICE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_whole_device_1 (guestfs_h *g)
{
  if (test_is_whole_device_1_skip ()) {
    skipped ("test_is_whole_device_1", "environment variable set");
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestResultFalse for is_whole_device (1) */
  const char *_arg5 = "/dev/sda1";
  int ret;
  ret = guestfs_is_whole_device (g, _arg5);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_whole_device_1", "is_whole_device");
    return -1;
  }
  return 0;
}

static int
test_is_whole_device_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_whole_device") == NULL;
  str = getenv ("SKIP_TEST_IS_WHOLE_DEVICE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_WHOLE_DEVICE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_whole_device_2 (guestfs_h *g)
{
  if (test_is_whole_device_2_skip ()) {
    skipped ("test_is_whole_device_2", "environment variable set");
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResultFalse for is_whole_device (2) */
  const char *_arg7 = "/dev/VG/LV";
  int ret;
  ret = guestfs_is_whole_device (g, _arg7);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_whole_device_2", "is_whole_device");
    return -1;
  }
  return 0;
}

static int
test_rename_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "rename") == NULL;
  str = getenv ("SKIP_TEST_RENAME_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_RENAME");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_rename_0 (guestfs_h *g)
{
  if (test_rename_0_skip ()) {
    skipped ("test_rename_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultFalse for rename (0) */
  const char *_arg10 = "/rename";
  int _ret9;
  _ret9 = guestfs_mkdir (g, _arg10);
  if (_ret9 == -1)
    return -1;
  const char *_arg13 = "/rename/old";
  const char *_arg14 = "file content";
  size_t _arg14_size = 12;
  int _ret12;
  _ret12 = guestfs_write (g, _arg13, _arg14, _arg14_size);
  if (_ret12 == -1)
    return -1;
  const char *_arg17 = "/rename/old";
  const char *_arg18 = "/rename/new";
  int _ret16;
  _ret16 = guestfs_rename (g, _arg17, _arg18);
  if (_ret16 == -1)
    return -1;
  const char *_arg20 = "/rename/old";
  int ret;
  ret = guestfs_is_file (g, _arg20);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_rename_0", "is_file");
    return -1;
  }
  return 0;
}

static int
test_part_get_gpt_type_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_get_gpt_type") == NULL;
  str = getenv ("SKIP_TEST_PART_GET_GPT_TYPE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_GET_GPT_TYPE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_get_gpt_type_0 (guestfs_h *g)
{
  if (test_part_get_gpt_type_0_skip ()) {
    skipped ("test_part_get_gpt_type_0", "environment variable set");
    return 0;
  }

  const char *_features22[] = { "gdisk", NULL };
  if (!guestfs_feature_available (g, (char **) _features22)) {
    skipped ("test_part_get_gpt_type_0", "group %s not available in daemon",
             _features22[0]);
    return 0;
  }

  if (init_gpt (g) == -1)
    return -1;

  /* TestResultString for part_get_gpt_type (0) */
  const char *_arg24 = "/dev/sda";
  const char *_arg26 = "01234567-89AB-CDEF-0123-456789ABCDEF";
  int _ret23;
  _ret23 = guestfs_part_set_gpt_type (g, _arg24, 1, _arg26);
  if (_ret23 == -1)
    return -1;
  const char *_arg28 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_gpt_type (g, _arg28, 1);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "01234567-89AB-CDEF-0123-456789ABCDEF")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_part_get_gpt_type_0", "part_get_gpt_type", ret, "01234567-89AB-CDEF-0123-456789ABCDEF");
    return -1;
  }
  return 0;
}

static int
test_cap_set_file_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "cap_set_file") == NULL;
  str = getenv ("SKIP_TEST_CAP_SET_FILE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CAP_SET_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_cap_set_file_0 (guestfs_h *g)
{
  if (test_cap_set_file_0_skip ()) {
    skipped ("test_cap_set_file_0", "environment variable set");
    return 0;
  }

  const char *_features31[] = { "linuxcaps", NULL };
  if (!guestfs_feature_available (g, (char **) _features31)) {
    skipped ("test_cap_set_file_0", "group %s not available in daemon",
             _features31[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for cap_set_file (0) */
  const char *_arg33 = "/cap_set_file_0";
  int _ret32;
  _ret32 = guestfs_touch (g, _arg33);
  if (_ret32 == -1)
    return -1;
  const char *_arg36 = "/cap_set_file_0";
  const char *_arg37 = "cap_chown=p cap_chown+e";
  int _ret35;
  _ret35 = guestfs_cap_set_file (g, _arg36, _arg37);
  if (_ret35 == -1)
    return -1;
  const char *_arg39 = "/cap_set_file_0";
  CLEANUP_FREE char *ret;
  ret = guestfs_cap_get_file (g, _arg39);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "= cap_chown+ep")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_cap_set_file_0", "cap_get_file", ret, "= cap_chown+ep");
    return -1;
  }
  return 0;
}

static int
test_acl_delete_def_file_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "acl_delete_def_file") == NULL;
  str = getenv ("SKIP_TEST_ACL_DELETE_DEF_FILE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ACL_DELETE_DEF_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_acl_delete_def_file_0 (guestfs_h *g)
{
  if (test_acl_delete_def_file_0_skip ()) {
    skipped ("test_acl_delete_def_file_0", "environment variable set");
    return 0;
  }

  const char *_features41[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) _features41)) {
    skipped ("test_acl_delete_def_file_0", "group %s not available in daemon",
             _features41[0]);
    return 0;
  }

  skipped ("test_acl_delete_def_file_0", "test disabled in generator");
  return 0;
}

static int
test_acl_delete_def_file_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "acl_delete_def_file") == NULL;
  str = getenv ("SKIP_TEST_ACL_DELETE_DEF_FILE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ACL_DELETE_DEF_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_acl_delete_def_file_1 (guestfs_h *g)
{
  if (test_acl_delete_def_file_1_skip ()) {
    skipped ("test_acl_delete_def_file_1", "environment variable set");
    return 0;
  }

  const char *_features42[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) _features42)) {
    skipped ("test_acl_delete_def_file_1", "group %s not available in daemon",
             _features42[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for acl_delete_def_file (1) */
  const char *_arg44 = "/acl_delete_def_file_1";
  int _ret43;
  _ret43 = guestfs_mkdir (g, _arg44);
  if (_ret43 == -1)
    return -1;
  const char *_arg47 = "/acl_delete_def_file_1";
  const char *_arg48 = "default";
  const char *_arg49 = "user::r-x,group::r-x,other::r-x";
  int _ret46;
  _ret46 = guestfs_acl_set_file (g, _arg47, _arg48, _arg49);
  if (_ret46 == -1)
    return -1;
  const char *_arg52 = "/acl_delete_def_file_1";
  int _ret51;
  _ret51 = guestfs_acl_delete_def_file (g, _arg52);
  if (_ret51 == -1)
    return -1;
  return 0;
}

static int
test_acl_set_file_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "acl_set_file") == NULL;
  str = getenv ("SKIP_TEST_ACL_SET_FILE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ACL_SET_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_acl_set_file_0 (guestfs_h *g)
{
  if (test_acl_set_file_0_skip ()) {
    skipped ("test_acl_set_file_0", "environment variable set");
    return 0;
  }

  const char *_features54[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) _features54)) {
    skipped ("test_acl_set_file_0", "group %s not available in daemon",
             _features54[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for acl_set_file (0) */
  const char *_arg56 = "/acl_set_file_0";
  int _ret55;
  _ret55 = guestfs_touch (g, _arg56);
  if (_ret55 == -1)
    return -1;
  const char *_arg59 = "/acl_set_file_0";
  const char *_arg60 = "access";
  const char *_arg61 = "user::r-x,group::r-x,other::r-x";
  int _ret58;
  _ret58 = guestfs_acl_set_file (g, _arg59, _arg60, _arg61);
  if (_ret58 == -1)
    return -1;
  const char *_arg64 = "/acl_set_file_0";
  const char *_arg65 = "access";
  CLEANUP_FREE char *_ret63;
  _ret63 = guestfs_acl_get_file (g, _arg64, _arg65);
  if (_ret63 == NULL)
      return -1;
  return 0;
}

static int
test_mklost_and_found_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mklost_and_found") == NULL;
  str = getenv ("SKIP_TEST_MKLOST_AND_FOUND_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKLOST_AND_FOUND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mklost_and_found_0 (guestfs_h *g)
{
  if (test_mklost_and_found_0_skip ()) {
    skipped ("test_mklost_and_found_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestRun for mklost_and_found (0) */
  const char *_arg68 = "/lost+found";
  int _ret67;
  _ret67 = guestfs_rm_rf (g, _arg68);
  if (_ret67 == -1)
    return -1;
  const char *_arg71 = "/";
  int _ret70;
  _ret70 = guestfs_mklost_and_found (g, _arg71);
  if (_ret70 == -1)
    return -1;
  return 0;
}

static int
test_mktemp_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mktemp") == NULL;
  str = getenv ("SKIP_TEST_MKTEMP_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKTEMP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mktemp_0 (guestfs_h *g)
{
  if (test_mktemp_0_skip ()) {
    skipped ("test_mktemp_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for mktemp (0) */
  const char *_arg74 = "/mktemp";
  int _ret73;
  _ret73 = guestfs_mkdir (g, _arg74);
  if (_ret73 == -1)
    return -1;
  const char *_arg77 = "/mktemp/tmpXXXXXX";
  struct guestfs_mktemp_argv _optargs78;
  _optargs78.bitmask = UINT64_C(0x0);
  CLEANUP_FREE char *_ret76;
  _ret76 = guestfs_mktemp_argv (g, _arg77, &_optargs78);
  if (_ret76 == NULL)
      return -1;
  const char *_arg80 = "/mktemp/tmpXXXXXX";
  struct guestfs_mktemp_argv _optargs81;
  _optargs81.suffix = "suff";
  _optargs81.bitmask = UINT64_C(0x1);
  CLEANUP_FREE char *_ret79;
  _ret79 = guestfs_mktemp_argv (g, _arg80, &_optargs81);
  if (_ret79 == NULL)
      return -1;
  return 0;
}

static int
test_mke2fs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mke2fs") == NULL;
  str = getenv ("SKIP_TEST_MKE2FS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKE2FS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mke2fs_0 (guestfs_h *g)
{
  if (test_mke2fs_0_skip ()) {
    skipped ("test_mke2fs_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for mke2fs (0) */
  const char *_arg83 = "/dev/sda";
  const char *_arg84 = "mbr";
  int _ret82;
  _ret82 = guestfs_part_init (g, _arg83, _arg84);
  if (_ret82 == -1)
    return -1;
  const char *_arg87 = "/dev/sda";
  const char *_arg88 = "p";
  int _ret86;
  _ret86 = guestfs_part_add (g, _arg87, _arg88, 64, 204799);
  if (_ret86 == -1)
    return -1;
  const char *_arg93 = "/dev/sda";
  const char *_arg94 = "p";
  int _ret92;
  _ret92 = guestfs_part_add (g, _arg93, _arg94, 204800, -64);
  if (_ret92 == -1)
    return -1;
  const char *_arg99 = "/dev/sda1";
  struct guestfs_mke2fs_argv _optargs100;
  _optargs100.blocksize = 4096;
  _optargs100.journaldev = 1;
  _optargs100.bitmask = UINT64_C(0x100000002);
  int _ret98;
  _ret98 = guestfs_mke2fs_argv (g, _arg99, &_optargs100);
  if (_ret98 == -1)
    return -1;
  const char *_arg102 = "/dev/sda2";
  struct guestfs_mke2fs_argv _optargs103;
  _optargs103.blocksize = 4096;
  _optargs103.journaldevice = "/dev/sda1";
  _optargs103.fstype = "ext2";
  _optargs103.bitmask = UINT64_C(0x44002);
  int _ret101;
  _ret101 = guestfs_mke2fs_argv (g, _arg102, &_optargs103);
  if (_ret101 == -1)
    return -1;
  const char *_arg105 = "/dev/sda2";
  const char *_arg106 = "/";
  int _ret104;
  _ret104 = guestfs_mount (g, _arg105, _arg106);
  if (_ret104 == -1)
    return -1;
  const char *_arg109 = "/new";
  const char *_arg110 = "new file contents";
  size_t _arg110_size = 17;
  int _ret108;
  _ret108 = guestfs_write (g, _arg109, _arg110, _arg110_size);
  if (_ret108 == -1)
    return -1;
  const char *_arg112 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg112);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mke2fs_0", "cat", ret, "new file contents");
    return -1;
  }
  return 0;
}

static int
test_mke2fs_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mke2fs") == NULL;
  str = getenv ("SKIP_TEST_MKE2FS_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKE2FS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mke2fs_1 (guestfs_h *g)
{
  if (test_mke2fs_1_skip ()) {
    skipped ("test_mke2fs_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for mke2fs (1) */
  const char *_arg115 = "/dev/sda";
  const char *_arg116 = "mbr";
  int _ret114;
  _ret114 = guestfs_part_init (g, _arg115, _arg116);
  if (_ret114 == -1)
    return -1;
  const char *_arg119 = "/dev/sda";
  const char *_arg120 = "p";
  int _ret118;
  _ret118 = guestfs_part_add (g, _arg119, _arg120, 64, 204799);
  if (_ret118 == -1)
    return -1;
  const char *_arg125 = "/dev/sda";
  const char *_arg126 = "p";
  int _ret124;
  _ret124 = guestfs_part_add (g, _arg125, _arg126, 204800, -64);
  if (_ret124 == -1)
    return -1;
  const char *_arg131 = "/dev/sda1";
  struct guestfs_mke2fs_argv _optargs132;
  _optargs132.blocksize = 4096;
  _optargs132.journaldevice = "/dev/sda1";
  _optargs132.label = "JOURNAL";
  _optargs132.fstype = "ext2";
  _optargs132.journaldev = 1;
  _optargs132.bitmask = UINT64_C(0x10004c002);
  int _ret130;
  _ret130 = guestfs_mke2fs_argv (g, _arg131, &_optargs132);
  if (_ret130 == -1)
    return -1;
  const char *_arg134 = "/dev/sda2";
  struct guestfs_mke2fs_argv _optargs135;
  _optargs135.blocksize = 4096;
  _optargs135.journaldevice = "LABEL=JOURNAL";
  _optargs135.label = "JOURNAL";
  _optargs135.fstype = "ext2";
  _optargs135.bitmask = UINT64_C(0x4c002);
  int _ret133;
  _ret133 = guestfs_mke2fs_argv (g, _arg134, &_optargs135);
  if (_ret133 == -1)
    return -1;
  const char *_arg137 = "/dev/sda2";
  const char *_arg138 = "/";
  int _ret136;
  _ret136 = guestfs_mount (g, _arg137, _arg138);
  if (_ret136 == -1)
    return -1;
  const char *_arg141 = "/new";
  const char *_arg142 = "new file contents";
  size_t _arg142_size = 17;
  int _ret140;
  _ret140 = guestfs_write (g, _arg141, _arg142, _arg142_size);
  if (_ret140 == -1)
    return -1;
  const char *_arg144 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg144);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mke2fs_1", "cat", ret, "new file contents");
    return -1;
  }
  return 0;
}

static int
test_mke2fs_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mke2fs") == NULL;
  str = getenv ("SKIP_TEST_MKE2FS_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKE2FS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mke2fs_2 (guestfs_h *g)
{
  if (test_mke2fs_2_skip ()) {
    skipped ("test_mke2fs_2", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for mke2fs (2) */
  const char *_arg147 = "/dev/sda";
  const char *_arg148 = "mbr";
  int _ret146;
  _ret146 = guestfs_part_init (g, _arg147, _arg148);
  if (_ret146 == -1)
    return -1;
  const char *_arg151 = "/dev/sda";
  const char *_arg152 = "p";
  int _ret150;
  _ret150 = guestfs_part_add (g, _arg151, _arg152, 64, 204799);
  if (_ret150 == -1)
    return -1;
  const char *_arg157 = "/dev/sda";
  const char *_arg158 = "p";
  int _ret156;
  _ret156 = guestfs_part_add (g, _arg157, _arg158, 204800, -64);
  if (_ret156 == -1)
    return -1;
  const char *_arg163 = "/dev/sda1";
  struct guestfs_mke2fs_argv _optargs164;
  _optargs164.blocksize = 4096;
  _optargs164.uuid = "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b";
  _optargs164.journaldev = 1;
  _optargs164.bitmask = UINT64_C(0x100100002);
  int _ret162;
  _ret162 = guestfs_mke2fs_argv (g, _arg163, &_optargs164);
  if (_ret162 == -1)
    return -1;
  const char *_arg166 = "/dev/sda2";
  struct guestfs_mke2fs_argv _optargs167;
  _optargs167.blocksize = 4096;
  _optargs167.journaldevice = "UUID=ca27c5d7-8afb-7db4-5e5d-19221fa1e22b";
  _optargs167.label = "JOURNAL";
  _optargs167.fstype = "ext2";
  _optargs167.forcecreate = 1;
  _optargs167.bitmask = UINT64_C(0x24c002);
  int _ret165;
  _ret165 = guestfs_mke2fs_argv (g, _arg166, &_optargs167);
  if (_ret165 == -1)
    return -1;
  const char *_arg169 = "/dev/sda2";
  const char *_arg170 = "/";
  int _ret168;
  _ret168 = guestfs_mount (g, _arg169, _arg170);
  if (_ret168 == -1)
    return -1;
  const char *_arg173 = "/new";
  const char *_arg174 = "new file contents";
  size_t _arg174_size = 17;
  int _ret172;
  _ret172 = guestfs_write (g, _arg173, _arg174, _arg174_size);
  if (_ret172 == -1)
    return -1;
  const char *_arg176 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg176);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mke2fs_2", "cat", ret, "new file contents");
    return -1;
  }
  return 0;
}

static int
test_rm_f_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "rm_f") == NULL;
  str = getenv ("SKIP_TEST_RM_F_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_RM_F");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_rm_f_0 (guestfs_h *g)
{
  if (test_rm_f_0_skip ()) {
    skipped ("test_rm_f_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultFalse for rm_f (0) */
  const char *_arg179 = "/rm_f";
  int _ret178;
  _ret178 = guestfs_mkdir (g, _arg179);
  if (_ret178 == -1)
    return -1;
  const char *_arg182 = "/rm_f/foo";
  int _ret181;
  _ret181 = guestfs_touch (g, _arg182);
  if (_ret181 == -1)
    return -1;
  const char *_arg185 = "/rm_f/foo";
  int _ret184;
  _ret184 = guestfs_rm_f (g, _arg185);
  if (_ret184 == -1)
    return -1;
  const char *_arg188 = "/rm_f/not_exists";
  int _ret187;
  _ret187 = guestfs_rm_f (g, _arg188);
  if (_ret187 == -1)
    return -1;
  const char *_arg190 = "/rm_f/foo";
  int ret;
  ret = guestfs_exists (g, _arg190);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_rm_f_0", "exists");
    return -1;
  }
  return 0;
}

static int
test_rm_f_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "rm_f") == NULL;
  str = getenv ("SKIP_TEST_RM_F_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_RM_F");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_rm_f_1 (guestfs_h *g)
{
  if (test_rm_f_1_skip ()) {
    skipped ("test_rm_f_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for rm_f (1) */
  const char *_arg193 = "/rm_f2";
  int _ret192;
  _ret192 = guestfs_mkdir (g, _arg193);
  if (_ret192 == -1)
    return -1;
  const char *_arg196 = "/rm_f2/foo";
  int _ret195;
  _ret195 = guestfs_mkdir (g, _arg196);
  if (_ret195 == -1)
    return -1;
  const char *_arg199 = "/rm_f2/foo";
  int _ret198;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret198 = guestfs_rm_f (g, _arg199);
  guestfs_pop_error_handler (g);
  if (_ret198 != -1)
    return -1;
  return 0;
}

static int
test_xfs_repair_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "xfs_repair") == NULL;
  str = getenv ("SKIP_TEST_XFS_REPAIR_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_XFS_REPAIR");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_xfs_repair_0 (guestfs_h *g)
{
  if (test_xfs_repair_0_skip ()) {
    skipped ("test_xfs_repair_0", "environment variable set");
    return 0;
  }

  const char *_features201[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features201)) {
    skipped ("test_xfs_repair_0", "group %s not available in daemon",
             _features201[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for xfs_repair (0) */
  const char *_arg203 = "/dev/sda";
  const char *_arg204 = "mbr";
  int _ret202;
  _ret202 = guestfs_part_disk (g, _arg203, _arg204);
  if (_ret202 == -1)
    return -1;
  const char *_arg207 = "xfs";
  const char *_arg208 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs209;
  _optargs209.bitmask = UINT64_C(0x0);
  int _ret206;
  _ret206 = guestfs_mkfs_opts_argv (g, _arg207, _arg208, &_optargs209);
  if (_ret206 == -1)
    return -1;
  const char *_arg211 = "/dev/sda1";
  struct guestfs_xfs_repair_argv _optargs212;
  _optargs212.nomodify = 1;
  _optargs212.bitmask = UINT64_C(0x2);
  int _ret210;
  _ret210 = guestfs_xfs_repair_argv (g, _arg211, &_optargs212);
  if (_ret210 == -1)
    return -1;
  return 0;
}

static int
test_xfs_admin_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "xfs_admin") == NULL;
  str = getenv ("SKIP_TEST_XFS_ADMIN_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_XFS_ADMIN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_xfs_admin_0 (guestfs_h *g)
{
  if (test_xfs_admin_0_skip ()) {
    skipped ("test_xfs_admin_0", "environment variable set");
    return 0;
  }

  const char *_features213[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features213)) {
    skipped ("test_xfs_admin_0", "group %s not available in daemon",
             _features213[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for xfs_admin (0) */
  const char *_arg214 = "/dev/sda";
  const char *_arg215 = "mbr";
  int ret4;
  ret4 = guestfs_part_disk (g, _arg214, _arg215);
  if (ret4 == -1)
    return -1;
  const char *_arg217 = "xfs";
  const char *_arg218 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs219;
  _optargs219.bitmask = UINT64_C(0x0);
  int ret3;
  ret3 = guestfs_mkfs_opts_argv (g, _arg217, _arg218, &_optargs219);
  if (ret3 == -1)
    return -1;
  const char *_arg220 = "/dev/sda1";
  struct guestfs_xfs_admin_argv _optargs221;
  _optargs221.lazycounter = 0;
  _optargs221.bitmask = UINT64_C(0x10);
  int ret2;
  ret2 = guestfs_xfs_admin_argv (g, _arg220, &_optargs221);
  if (ret2 == -1)
    return -1;
  const char *_arg222 = "/dev/sda1";
  const char *_arg223 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg222, _arg223);
  if (ret1 == -1)
    return -1;
  const char *_arg225 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, _arg225);
  if (ret == NULL)
      return -1;
  if (! (ret->xfs_lazycount == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_xfs_admin_0", "ret->xfs_lazycount == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_xfs_growfs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "xfs_growfs") == NULL;
  str = getenv ("SKIP_TEST_XFS_GROWFS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_XFS_GROWFS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_xfs_growfs_0 (guestfs_h *g)
{
  if (test_xfs_growfs_0_skip ()) {
    skipped ("test_xfs_growfs_0", "environment variable set");
    return 0;
  }

  const char *_features227[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features227)) {
    skipped ("test_xfs_growfs_0", "group %s not available in daemon",
             _features227[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for xfs_growfs (0) */
  const char *_arg228 = "/dev/sda";
  const char *_arg229 = "mbr";
  int ret8;
  ret8 = guestfs_part_disk (g, _arg228, _arg229);
  if (ret8 == -1)
    return -1;
  const char *_arg231 = "/dev/sda1";
  int ret7;
  ret7 = guestfs_pvcreate (g, _arg231);
  if (ret7 == -1)
    return -1;
  const char *_arg233 = "VG";
  const char *_arg234_0 = "/dev/sda1";
  const char *const _arg234[] = {
    _arg234_0,
    NULL
  };
  int ret6;
  ret6 = guestfs_vgcreate (g, _arg233, (char **) _arg234);
  if (ret6 == -1)
    return -1;
  const char *_arg236 = "LV";
  const char *_arg237 = "VG";
  int ret5;
  ret5 = guestfs_lvcreate (g, _arg236, _arg237, 40);
  if (ret5 == -1)
    return -1;
  const char *_arg240 = "xfs";
  const char *_arg241 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs242;
  _optargs242.bitmask = UINT64_C(0x0);
  int ret4;
  ret4 = guestfs_mkfs_opts_argv (g, _arg240, _arg241, &_optargs242);
  if (ret4 == -1)
    return -1;
  const char *_arg243 = "/dev/VG/LV";
  int ret3;
  ret3 = guestfs_lvresize (g, _arg243, 80);
  if (ret3 == -1)
    return -1;
  const char *_arg246 = "/dev/VG/LV";
  const char *_arg247 = "/";
  int ret2;
  ret2 = guestfs_mount (g, _arg246, _arg247);
  if (ret2 == -1)
    return -1;
  const char *_arg249 = "/";
  struct guestfs_xfs_growfs_argv _optargs250;
  _optargs250.datasec = 1;
  _optargs250.logsec = 0;
  _optargs250.rtsec = 0;
  _optargs250.bitmask = UINT64_C(0x7);
  int ret1;
  ret1 = guestfs_xfs_growfs_argv (g, _arg249, &_optargs250);
  if (ret1 == -1)
    return -1;
  const char *_arg251 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, _arg251);
  if (ret == NULL)
      return -1;
  if (! (ret->xfs_blocksize == 4096)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_xfs_growfs_0", "ret->xfs_blocksize == 4096");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_utsname_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "utsname") == NULL;
  str = getenv ("SKIP_TEST_UTSNAME_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UTSNAME");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_utsname_0 (guestfs_h *g)
{
  if (test_utsname_0_skip ()) {
    skipped ("test_utsname_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for utsname (0) */
  CLEANUP_FREE_UTSNAME struct guestfs_utsname *_ret253;
  _ret253 = guestfs_utsname (g);
  if (_ret253 == NULL)
      return -1;
  return 0;
}

static int
test_vgchange_uuid_all_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vgchange_uuid_all") == NULL;
  str = getenv ("SKIP_TEST_VGCHANGE_UUID_ALL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VGCHANGE_UUID_ALL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vgchange_uuid_all_0 (guestfs_h *g)
{
  if (test_vgchange_uuid_all_0_skip ()) {
    skipped ("test_vgchange_uuid_all_0", "environment variable set");
    return 0;
  }

  const char *_features255[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features255)) {
    skipped ("test_vgchange_uuid_all_0", "group %s not available in daemon",
             _features255[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for vgchange_uuid_all (0) */
  const char *_arg257 = "/dev/sda";
  const char *_arg258 = "mbr";
  int _ret256;
  _ret256 = guestfs_part_disk (g, _arg257, _arg258);
  if (_ret256 == -1)
    return -1;
  const char *_arg261 = "/dev/sda1";
  int _ret260;
  _ret260 = guestfs_pvcreate (g, _arg261);
  if (_ret260 == -1)
    return -1;
  const char *_arg264 = "VG";
  const char *_arg265_0 = "/dev/sda1";
  const char *const _arg265[] = {
    _arg265_0,
    NULL
  };
  int _ret263;
  _ret263 = guestfs_vgcreate (g, _arg264, (char **) _arg265);
  if (_ret263 == -1)
    return -1;
  int _ret267;
  _ret267 = guestfs_vgchange_uuid_all (g);
  if (_ret267 == -1)
    return -1;
  return 0;
}

static int
test_vgchange_uuid_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vgchange_uuid") == NULL;
  str = getenv ("SKIP_TEST_VGCHANGE_UUID_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VGCHANGE_UUID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vgchange_uuid_0 (guestfs_h *g)
{
  if (test_vgchange_uuid_0_skip ()) {
    skipped ("test_vgchange_uuid_0", "environment variable set");
    return 0;
  }

  const char *_features269[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features269)) {
    skipped ("test_vgchange_uuid_0", "group %s not available in daemon",
             _features269[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for vgchange_uuid (0) */
  const char *_arg271 = "/dev/sda";
  const char *_arg272 = "mbr";
  int _ret270;
  _ret270 = guestfs_part_disk (g, _arg271, _arg272);
  if (_ret270 == -1)
    return -1;
  const char *_arg275 = "/dev/sda1";
  int _ret274;
  _ret274 = guestfs_pvcreate (g, _arg275);
  if (_ret274 == -1)
    return -1;
  const char *_arg278 = "VG";
  const char *_arg279_0 = "/dev/sda1";
  const char *const _arg279[] = {
    _arg279_0,
    NULL
  };
  int _ret277;
  _ret277 = guestfs_vgcreate (g, _arg278, (char **) _arg279);
  if (_ret277 == -1)
    return -1;
  const char *_arg282 = "/dev/VG";
  int _ret281;
  _ret281 = guestfs_vgchange_uuid (g, _arg282);
  if (_ret281 == -1)
    return -1;
  return 0;
}

static int
test_pvchange_uuid_all_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pvchange_uuid_all") == NULL;
  str = getenv ("SKIP_TEST_PVCHANGE_UUID_ALL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PVCHANGE_UUID_ALL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pvchange_uuid_all_0 (guestfs_h *g)
{
  if (test_pvchange_uuid_all_0_skip ()) {
    skipped ("test_pvchange_uuid_all_0", "environment variable set");
    return 0;
  }

  const char *_features284[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features284)) {
    skipped ("test_pvchange_uuid_all_0", "group %s not available in daemon",
             _features284[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for pvchange_uuid_all (0) */
  const char *_arg286 = "/dev/sda";
  const char *_arg287 = "mbr";
  int _ret285;
  _ret285 = guestfs_part_disk (g, _arg286, _arg287);
  if (_ret285 == -1)
    return -1;
  const char *_arg290 = "/dev/sda1";
  int _ret289;
  _ret289 = guestfs_pvcreate (g, _arg290);
  if (_ret289 == -1)
    return -1;
  int _ret292;
  _ret292 = guestfs_pvchange_uuid_all (g);
  if (_ret292 == -1)
    return -1;
  return 0;
}

static int
test_pvchange_uuid_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pvchange_uuid") == NULL;
  str = getenv ("SKIP_TEST_PVCHANGE_UUID_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PVCHANGE_UUID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pvchange_uuid_0 (guestfs_h *g)
{
  if (test_pvchange_uuid_0_skip ()) {
    skipped ("test_pvchange_uuid_0", "environment variable set");
    return 0;
  }

  const char *_features294[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features294)) {
    skipped ("test_pvchange_uuid_0", "group %s not available in daemon",
             _features294[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for pvchange_uuid (0) */
  const char *_arg296 = "/dev/sda";
  const char *_arg297 = "mbr";
  int _ret295;
  _ret295 = guestfs_part_disk (g, _arg296, _arg297);
  if (_ret295 == -1)
    return -1;
  const char *_arg300 = "/dev/sda1";
  int _ret299;
  _ret299 = guestfs_pvcreate (g, _arg300);
  if (_ret299 == -1)
    return -1;
  const char *_arg303 = "/dev/sda1";
  int _ret302;
  _ret302 = guestfs_pvchange_uuid (g, _arg303);
  if (_ret302 == -1)
    return -1;
  return 0;
}

static int
test_xfs_info_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "xfs_info") == NULL;
  str = getenv ("SKIP_TEST_XFS_INFO_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_XFS_INFO");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_xfs_info_0 (guestfs_h *g)
{
  if (test_xfs_info_0_skip ()) {
    skipped ("test_xfs_info_0", "environment variable set");
    return 0;
  }

  const char *_features305[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features305)) {
    skipped ("test_xfs_info_0", "group %s not available in daemon",
             _features305[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for xfs_info (0) */
  const char *_arg306 = "/dev/sda";
  const char *_arg307 = "mbr";
  int ret3;
  ret3 = guestfs_part_disk (g, _arg306, _arg307);
  if (ret3 == -1)
    return -1;
  const char *_arg309 = "xfs";
  const char *_arg310 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs311;
  _optargs311.bitmask = UINT64_C(0x0);
  int ret2;
  ret2 = guestfs_mkfs_opts_argv (g, _arg309, _arg310, &_optargs311);
  if (ret2 == -1)
    return -1;
  const char *_arg312 = "/dev/sda1";
  const char *_arg313 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg312, _arg313);
  if (ret1 == -1)
    return -1;
  const char *_arg315 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, _arg315);
  if (ret == NULL)
      return -1;
  if (! (ret->xfs_blocksize == 4096)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_xfs_info_0", "ret->xfs_blocksize == 4096");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_nr_devices_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "nr_devices") == NULL;
  str = getenv ("SKIP_TEST_NR_DEVICES_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_NR_DEVICES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_nr_devices_0 (guestfs_h *g)
{
  if (test_nr_devices_0_skip ()) {
    skipped ("test_nr_devices_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for nr_devices (0) */
  int ret;
  ret = guestfs_nr_devices (g);
  if (ret == -1)
    return -1;
  if (! (ret == 4)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_nr_devices_0", "ret == 4");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_device_index_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "device_index") == NULL;
  str = getenv ("SKIP_TEST_DEVICE_INDEX_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DEVICE_INDEX");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_device_index_0 (guestfs_h *g)
{
  if (test_device_index_0_skip ()) {
    skipped ("test_device_index_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for device_index (0) */
  const char *_arg318 = "/dev/sda";
  int ret;
  ret = guestfs_device_index (g, _arg318);
  if (ret == -1)
    return -1;
  if (! (ret == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_device_index_0", "ret == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_btrfs_fsck_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_fsck") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_FSCK_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_FSCK");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_fsck_0 (guestfs_h *g)
{
  if (test_btrfs_fsck_0_skip ()) {
    skipped ("test_btrfs_fsck_0", "environment variable set");
    return 0;
  }

  const char *_features320[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features320)) {
    skipped ("test_btrfs_fsck_0", "group %s not available in daemon",
             _features320[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_fsck (0) */
  const char *_arg322_0 = "/dev/sda1";
  const char *const _arg322[] = {
    _arg322_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs323;
  _optargs323.bitmask = UINT64_C(0x0);
  int _ret321;
  _ret321 = guestfs_mkfs_btrfs_argv (g, (char **) _arg322, &_optargs323);
  if (_ret321 == -1)
    return -1;
  const char *_arg325 = "/dev/sda1";
  struct guestfs_btrfs_fsck_argv _optargs326;
  _optargs326.bitmask = UINT64_C(0x0);
  int _ret324;
  _ret324 = guestfs_btrfs_fsck_argv (g, _arg325, &_optargs326);
  if (_ret324 == -1)
    return -1;
  return 0;
}

static int
test_btrfs_set_seeding_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_set_seeding") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_SET_SEEDING_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_SET_SEEDING");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_set_seeding_0 (guestfs_h *g)
{
  if (test_btrfs_set_seeding_0_skip ()) {
    skipped ("test_btrfs_set_seeding_0", "environment variable set");
    return 0;
  }

  const char *_features327[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features327)) {
    skipped ("test_btrfs_set_seeding_0", "group %s not available in daemon",
             _features327[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_set_seeding (0) */
  const char *_arg329_0 = "/dev/sda1";
  const char *const _arg329[] = {
    _arg329_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs330;
  _optargs330.bitmask = UINT64_C(0x0);
  int _ret328;
  _ret328 = guestfs_mkfs_btrfs_argv (g, (char **) _arg329, &_optargs330);
  if (_ret328 == -1)
    return -1;
  const char *_arg332 = "/dev/sda1";
  int _ret331;
  _ret331 = guestfs_btrfs_set_seeding (g, _arg332, 1);
  if (_ret331 == -1)
    return -1;
  const char *_arg336 = "/dev/sda1";
  int _ret335;
  _ret335 = guestfs_btrfs_set_seeding (g, _arg336, 0);
  if (_ret335 == -1)
    return -1;
  return 0;
}

static int
test_btrfs_filesystem_sync_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_filesystem_sync") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_FILESYSTEM_SYNC_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_FILESYSTEM_SYNC");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_filesystem_sync_0 (guestfs_h *g)
{
  if (test_btrfs_filesystem_sync_0_skip ()) {
    skipped ("test_btrfs_filesystem_sync_0", "environment variable set");
    return 0;
  }

  const char *_features339[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features339)) {
    skipped ("test_btrfs_filesystem_sync_0", "group %s not available in daemon",
             _features339[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_filesystem_sync (0) */
  const char *_arg341_0 = "/dev/sda1";
  const char *const _arg341[] = {
    _arg341_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs342;
  _optargs342.bitmask = UINT64_C(0x0);
  int _ret340;
  _ret340 = guestfs_mkfs_btrfs_argv (g, (char **) _arg341, &_optargs342);
  if (_ret340 == -1)
    return -1;
  const char *_arg344 = "/dev/sda1";
  const char *_arg345 = "/";
  int _ret343;
  _ret343 = guestfs_mount (g, _arg344, _arg345);
  if (_ret343 == -1)
    return -1;
  const char *_arg348 = "/test1";
  int _ret347;
  _ret347 = guestfs_btrfs_subvolume_create (g, _arg348);
  if (_ret347 == -1)
    return -1;
  const char *_arg351 = "/test1";
  int _ret350;
  _ret350 = guestfs_btrfs_filesystem_sync (g, _arg351);
  if (_ret350 == -1)
    return -1;
  const char *_arg354 = "/test1";
  int _ret353;
  _ret353 = guestfs_btrfs_filesystem_balance (g, _arg354);
  if (_ret353 == -1)
    return -1;
  return 0;
}

static int
test_btrfs_subvolume_delete_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_subvolume_delete") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_DELETE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_DELETE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_subvolume_delete_0 (guestfs_h *g)
{
  if (test_btrfs_subvolume_delete_0_skip ()) {
    skipped ("test_btrfs_subvolume_delete_0", "environment variable set");
    return 0;
  }

  const char *_features356[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features356)) {
    skipped ("test_btrfs_subvolume_delete_0", "group %s not available in daemon",
             _features356[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_subvolume_delete (0) */
  const char *_arg358_0 = "/dev/sda1";
  const char *const _arg358[] = {
    _arg358_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs359;
  _optargs359.bitmask = UINT64_C(0x0);
  int _ret357;
  _ret357 = guestfs_mkfs_btrfs_argv (g, (char **) _arg358, &_optargs359);
  if (_ret357 == -1)
    return -1;
  const char *_arg361 = "/dev/sda1";
  const char *_arg362 = "/";
  int _ret360;
  _ret360 = guestfs_mount (g, _arg361, _arg362);
  if (_ret360 == -1)
    return -1;
  const char *_arg365 = "/test1";
  int _ret364;
  _ret364 = guestfs_btrfs_subvolume_create (g, _arg365);
  if (_ret364 == -1)
    return -1;
  const char *_arg368 = "/test1";
  int _ret367;
  _ret367 = guestfs_btrfs_subvolume_delete (g, _arg368);
  if (_ret367 == -1)
    return -1;
  return 0;
}

static int
test_btrfs_subvolume_snapshot_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_subvolume_snapshot") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_SNAPSHOT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_SNAPSHOT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_subvolume_snapshot_0 (guestfs_h *g)
{
  if (test_btrfs_subvolume_snapshot_0_skip ()) {
    skipped ("test_btrfs_subvolume_snapshot_0", "environment variable set");
    return 0;
  }

  const char *_features370[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features370)) {
    skipped ("test_btrfs_subvolume_snapshot_0", "group %s not available in daemon",
             _features370[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_subvolume_snapshot (0) */
  const char *_arg372_0 = "/dev/sda1";
  const char *const _arg372[] = {
    _arg372_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs373;
  _optargs373.bitmask = UINT64_C(0x0);
  int _ret371;
  _ret371 = guestfs_mkfs_btrfs_argv (g, (char **) _arg372, &_optargs373);
  if (_ret371 == -1)
    return -1;
  const char *_arg375 = "/dev/sda1";
  const char *_arg376 = "/";
  int _ret374;
  _ret374 = guestfs_mount (g, _arg375, _arg376);
  if (_ret374 == -1)
    return -1;
  const char *_arg379 = "/dir";
  int _ret378;
  _ret378 = guestfs_mkdir (g, _arg379);
  if (_ret378 == -1)
    return -1;
  const char *_arg382 = "/test1";
  int _ret381;
  _ret381 = guestfs_btrfs_subvolume_create (g, _arg382);
  if (_ret381 == -1)
    return -1;
  const char *_arg385 = "/test2";
  int _ret384;
  _ret384 = guestfs_btrfs_subvolume_create (g, _arg385);
  if (_ret384 == -1)
    return -1;
  const char *_arg388 = "/dir/test3";
  int _ret387;
  _ret387 = guestfs_btrfs_subvolume_create (g, _arg388);
  if (_ret387 == -1)
    return -1;
  const char *_arg391 = "/dir/test3";
  const char *_arg392 = "/dir/test4";
  int _ret390;
  _ret390 = guestfs_btrfs_subvolume_snapshot (g, _arg391, _arg392);
  if (_ret390 == -1)
    return -1;
  return 0;
}

static int
test_get_e2generation_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_e2generation") == NULL;
  str = getenv ("SKIP_TEST_GET_E2GENERATION_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_E2GENERATION");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_e2generation_0 (guestfs_h *g)
{
  if (test_get_e2generation_0_skip ()) {
    skipped ("test_get_e2generation_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for get_e2generation (0) */
  const char *_arg394 = "/e2generation";
  int ret2;
  ret2 = guestfs_touch (g, _arg394);
  if (ret2 == -1)
    return -1;
  const char *_arg396 = "/e2generation";
  int ret1;
  ret1 = guestfs_set_e2generation (g, _arg396, 123456);
  if (ret1 == -1)
    return -1;
  const char *_arg399 = "/e2generation";
  int64_t ret;
  ret = guestfs_get_e2generation (g, _arg399);
  if (ret == -1)
    return -1;
  if (! (ret == 123456)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_get_e2generation_0", "ret == 123456");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_get_e2attrs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_e2attrs") == NULL;
  str = getenv ("SKIP_TEST_GET_E2ATTRS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_E2ATTRS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_e2attrs_0 (guestfs_h *g)
{
  if (test_get_e2attrs_0_skip ()) {
    skipped ("test_get_e2attrs_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for get_e2attrs (0) */
  const char *_arg402 = "/e2attrs1";
  int _ret401;
  _ret401 = guestfs_touch (g, _arg402);
  if (_ret401 == -1)
    return -1;
  const char *_arg404 = "/e2attrs1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg404);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_get_e2attrs_0", "get_e2attrs", ret, "");
    return -1;
  }
  return 0;
}

static int
test_get_e2attrs_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_e2attrs") == NULL;
  str = getenv ("SKIP_TEST_GET_E2ATTRS_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_E2ATTRS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_e2attrs_1 (guestfs_h *g)
{
  if (test_get_e2attrs_1_skip ()) {
    skipped ("test_get_e2attrs_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for get_e2attrs (1) */
  const char *_arg407 = "/e2attrs2";
  int _ret406;
  _ret406 = guestfs_touch (g, _arg407);
  if (_ret406 == -1)
    return -1;
  const char *_arg410 = "/e2attrs2";
  const char *_arg411 = "is";
  struct guestfs_set_e2attrs_argv _optargs412;
  _optargs412.clear = 0;
  _optargs412.bitmask = UINT64_C(0x1);
  int _ret409;
  _ret409 = guestfs_set_e2attrs_argv (g, _arg410, _arg411, &_optargs412);
  if (_ret409 == -1)
    return -1;
  const char *_arg413 = "/e2attrs2";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg413);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "is")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_get_e2attrs_1", "get_e2attrs", ret, "is");
    return -1;
  }
  return 0;
}

static int
test_get_e2attrs_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_e2attrs") == NULL;
  str = getenv ("SKIP_TEST_GET_E2ATTRS_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_E2ATTRS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_e2attrs_2 (guestfs_h *g)
{
  if (test_get_e2attrs_2_skip ()) {
    skipped ("test_get_e2attrs_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for get_e2attrs (2) */
  const char *_arg416 = "/e2attrs3";
  int _ret415;
  _ret415 = guestfs_touch (g, _arg416);
  if (_ret415 == -1)
    return -1;
  const char *_arg419 = "/e2attrs3";
  const char *_arg420 = "is";
  struct guestfs_set_e2attrs_argv _optargs421;
  _optargs421.clear = 0;
  _optargs421.bitmask = UINT64_C(0x1);
  int _ret418;
  _ret418 = guestfs_set_e2attrs_argv (g, _arg419, _arg420, &_optargs421);
  if (_ret418 == -1)
    return -1;
  const char *_arg423 = "/e2attrs3";
  const char *_arg424 = "i";
  struct guestfs_set_e2attrs_argv _optargs425;
  _optargs425.clear = 1;
  _optargs425.bitmask = UINT64_C(0x1);
  int _ret422;
  _ret422 = guestfs_set_e2attrs_argv (g, _arg423, _arg424, &_optargs425);
  if (_ret422 == -1)
    return -1;
  const char *_arg426 = "/e2attrs3";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg426);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "s")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_get_e2attrs_2", "get_e2attrs", ret, "s");
    return -1;
  }
  return 0;
}

static int
test_get_e2attrs_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_e2attrs") == NULL;
  str = getenv ("SKIP_TEST_GET_E2ATTRS_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_E2ATTRS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_e2attrs_3 (guestfs_h *g)
{
  if (test_get_e2attrs_3_skip ()) {
    skipped ("test_get_e2attrs_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for get_e2attrs (3) */
  const char *_arg429 = "/e2attrs4";
  int _ret428;
  _ret428 = guestfs_touch (g, _arg429);
  if (_ret428 == -1)
    return -1;
  const char *_arg432 = "/e2attrs4";
  const char *_arg433 = "adst";
  struct guestfs_set_e2attrs_argv _optargs434;
  _optargs434.clear = 0;
  _optargs434.bitmask = UINT64_C(0x1);
  int _ret431;
  _ret431 = guestfs_set_e2attrs_argv (g, _arg432, _arg433, &_optargs434);
  if (_ret431 == -1)
    return -1;
  const char *_arg436 = "/e2attrs4";
  const char *_arg437 = "iS";
  struct guestfs_set_e2attrs_argv _optargs438;
  _optargs438.clear = 0;
  _optargs438.bitmask = UINT64_C(0x1);
  int _ret435;
  _ret435 = guestfs_set_e2attrs_argv (g, _arg436, _arg437, &_optargs438);
  if (_ret435 == -1)
    return -1;
  const char *_arg440 = "/e2attrs4";
  const char *_arg441 = "i";
  struct guestfs_set_e2attrs_argv _optargs442;
  _optargs442.clear = 1;
  _optargs442.bitmask = UINT64_C(0x1);
  int _ret439;
  _ret439 = guestfs_set_e2attrs_argv (g, _arg440, _arg441, &_optargs442);
  if (_ret439 == -1)
    return -1;
  const char *_arg444 = "/e2attrs4";
  const char *_arg445 = "ad";
  struct guestfs_set_e2attrs_argv _optargs446;
  _optargs446.clear = 1;
  _optargs446.bitmask = UINT64_C(0x1);
  int _ret443;
  _ret443 = guestfs_set_e2attrs_argv (g, _arg444, _arg445, &_optargs446);
  if (_ret443 == -1)
    return -1;
  const char *_arg448 = "/e2attrs4";
  const char *_arg449 = "";
  struct guestfs_set_e2attrs_argv _optargs450;
  _optargs450.clear = 0;
  _optargs450.bitmask = UINT64_C(0x1);
  int _ret447;
  _ret447 = guestfs_set_e2attrs_argv (g, _arg448, _arg449, &_optargs450);
  if (_ret447 == -1)
    return -1;
  const char *_arg452 = "/e2attrs4";
  const char *_arg453 = "";
  struct guestfs_set_e2attrs_argv _optargs454;
  _optargs454.clear = 1;
  _optargs454.bitmask = UINT64_C(0x1);
  int _ret451;
  _ret451 = guestfs_set_e2attrs_argv (g, _arg452, _arg453, &_optargs454);
  if (_ret451 == -1)
    return -1;
  const char *_arg455 = "/e2attrs4";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg455);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "Sst")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_get_e2attrs_3", "get_e2attrs", ret, "Sst");
    return -1;
  }
  return 0;
}

static int
test_get_e2attrs_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_e2attrs") == NULL;
  str = getenv ("SKIP_TEST_GET_E2ATTRS_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_E2ATTRS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_e2attrs_4 (guestfs_h *g)
{
  if (test_get_e2attrs_4_skip ()) {
    skipped ("test_get_e2attrs_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for get_e2attrs (4) */
  const char *_arg458 = "/e2attrs5";
  int _ret457;
  _ret457 = guestfs_touch (g, _arg458);
  if (_ret457 == -1)
    return -1;
  const char *_arg461 = "/e2attrs5";
  const char *_arg462 = "R";
  struct guestfs_set_e2attrs_argv _optargs463;
  _optargs463.clear = 0;
  _optargs463.bitmask = UINT64_C(0x1);
  int _ret460;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret460 = guestfs_set_e2attrs_argv (g, _arg461, _arg462, &_optargs463);
  guestfs_pop_error_handler (g);
  if (_ret460 != -1)
    return -1;
  return 0;
}

static int
test_get_e2attrs_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_e2attrs") == NULL;
  str = getenv ("SKIP_TEST_GET_E2ATTRS_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_E2ATTRS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_e2attrs_5 (guestfs_h *g)
{
  if (test_get_e2attrs_5_skip ()) {
    skipped ("test_get_e2attrs_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for get_e2attrs (5) */
  const char *_arg465 = "/e2attrs6";
  int _ret464;
  _ret464 = guestfs_touch (g, _arg465);
  if (_ret464 == -1)
    return -1;
  const char *_arg468 = "/e2attrs6";
  const char *_arg469 = "v";
  struct guestfs_set_e2attrs_argv _optargs470;
  _optargs470.clear = 0;
  _optargs470.bitmask = UINT64_C(0x1);
  int _ret467;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret467 = guestfs_set_e2attrs_argv (g, _arg468, _arg469, &_optargs470);
  guestfs_pop_error_handler (g);
  if (_ret467 != -1)
    return -1;
  return 0;
}

static int
test_get_e2attrs_6_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_e2attrs") == NULL;
  str = getenv ("SKIP_TEST_GET_E2ATTRS_6");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_E2ATTRS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_e2attrs_6 (guestfs_h *g)
{
  if (test_get_e2attrs_6_skip ()) {
    skipped ("test_get_e2attrs_6", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for get_e2attrs (6) */
  const char *_arg472 = "/e2attrs7";
  int _ret471;
  _ret471 = guestfs_touch (g, _arg472);
  if (_ret471 == -1)
    return -1;
  const char *_arg475 = "/e2attrs7";
  const char *_arg476 = "aa";
  struct guestfs_set_e2attrs_argv _optargs477;
  _optargs477.clear = 0;
  _optargs477.bitmask = UINT64_C(0x1);
  int _ret474;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret474 = guestfs_set_e2attrs_argv (g, _arg475, _arg476, &_optargs477);
  guestfs_pop_error_handler (g);
  if (_ret474 != -1)
    return -1;
  return 0;
}

static int
test_get_e2attrs_7_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_e2attrs") == NULL;
  str = getenv ("SKIP_TEST_GET_E2ATTRS_7");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_E2ATTRS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_e2attrs_7 (guestfs_h *g)
{
  if (test_get_e2attrs_7_skip ()) {
    skipped ("test_get_e2attrs_7", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for get_e2attrs (7) */
  const char *_arg479 = "/e2attrs8";
  int _ret478;
  _ret478 = guestfs_touch (g, _arg479);
  if (_ret478 == -1)
    return -1;
  const char *_arg482 = "/e2attrs8";
  const char *_arg483 = "BabcdB";
  struct guestfs_set_e2attrs_argv _optargs484;
  _optargs484.clear = 0;
  _optargs484.bitmask = UINT64_C(0x1);
  int _ret481;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret481 = guestfs_set_e2attrs_argv (g, _arg482, _arg483, &_optargs484);
  guestfs_pop_error_handler (g);
  if (_ret481 != -1)
    return -1;
  return 0;
}

static int
test_mkfs_btrfs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkfs_btrfs") == NULL;
  str = getenv ("SKIP_TEST_MKFS_BTRFS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKFS_BTRFS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkfs_btrfs_0 (guestfs_h *g)
{
  if (test_mkfs_btrfs_0_skip ()) {
    skipped ("test_mkfs_btrfs_0", "environment variable set");
    return 0;
  }

  const char *_features485[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features485)) {
    skipped ("test_mkfs_btrfs_0", "group %s not available in daemon",
             _features485[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkfs_btrfs (0) */
  const char *_arg487 = "/dev/sda";
  const char *_arg488 = "mbr";
  int _ret486;
  _ret486 = guestfs_part_disk (g, _arg487, _arg488);
  if (_ret486 == -1)
    return -1;
  const char *_arg491_0 = "/dev/sda1";
  const char *const _arg491[] = {
    _arg491_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs492;
  _optargs492.allocstart = 0;
  _optargs492.bytecount = 268435456;
  _optargs492.datatype = "single";
  _optargs492.leafsize = 4096;
  _optargs492.label = "test";
  _optargs492.metadata = "single";
  _optargs492.nodesize = 4096;
  _optargs492.sectorsize = 512;
  _optargs492.bitmask = UINT64_C(0xff);
  int _ret490;
  _ret490 = guestfs_mkfs_btrfs_argv (g, (char **) _arg491, &_optargs492);
  if (_ret490 == -1)
    return -1;
  return 0;
}

static int
test_isoinfo_device_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "isoinfo_device") == NULL;
  str = getenv ("SKIP_TEST_ISOINFO_DEVICE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ISOINFO_DEVICE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_isoinfo_device_0 (guestfs_h *g)
{
  if (test_isoinfo_device_0_skip ()) {
    skipped ("test_isoinfo_device_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResult for isoinfo_device (0) */
  const char *_arg493 = "/dev/sdd";
  CLEANUP_FREE_ISOINFO struct guestfs_isoinfo *ret;
  ret = guestfs_isoinfo_device (g, _arg493);
  if (ret == NULL)
      return -1;
  if (! (STREQ (ret->iso_system_id, "LINUX") && STREQ (ret->iso_volume_id, "CDROM") && STREQ (ret->iso_volume_set_id, "") && ret->iso_volume_set_size == 1 && ret->iso_volume_sequence_number == 1 && ret->iso_logical_block_size == 2048)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_isoinfo_device_0", "STREQ (ret->iso_system_id, \"LINUX\") && STREQ (ret->iso_volume_id, \"CDROM\") && STREQ (ret->iso_volume_set_id, \"\") && ret->iso_volume_set_size == 1 && ret->iso_volume_sequence_number == 1 && ret->iso_logical_block_size == 2048");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_lvcreate_free_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lvcreate_free") == NULL;
  str = getenv ("SKIP_TEST_LVCREATE_FREE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LVCREATE_FREE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lvcreate_free_0 (guestfs_h *g)
{
  if (test_lvcreate_free_0_skip ()) {
    skipped ("test_lvcreate_free_0", "environment variable set");
    return 0;
  }

  const char *_features495[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features495)) {
    skipped ("test_lvcreate_free_0", "group %s not available in daemon",
             _features495[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvcreate_free (0) */
  const char *_arg496 = "/dev/sda";
  const char *_arg497 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg496, _arg497);
  if (ret7 == -1)
    return -1;
  const char *_arg499 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg499);
  if (ret6 == -1)
    return -1;
  const char *_arg501 = "VG";
  const char *_arg502_0 = "/dev/sda1";
  const char *const _arg502[] = {
    _arg502_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg501, (char **) _arg502);
  if (ret5 == -1)
    return -1;
  const char *_arg504 = "LV1";
  const char *_arg505 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate_free (g, _arg504, _arg505, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg508 = "LV2";
  const char *_arg509 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate_free (g, _arg508, _arg509, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg512 = "LV3";
  const char *_arg513 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate_free (g, _arg512, _arg513, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg516 = "LV4";
  const char *_arg517 = "VG";
  int ret1;
  ret1 = guestfs_lvcreate_free (g, _arg516, _arg517, 100);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_lvs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 4, "/dev/VG/LV1", "/dev/VG/LV2", "/dev/VG/LV3", "/dev/VG/LV4"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_lvcreate_free_0", "is_string_list (ret, 4, \"/dev/VG/LV1\", \"/dev/VG/LV2\", \"/dev/VG/LV3\", \"/dev/VG/LV4\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_zero_free_space_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "zero_free_space") == NULL;
  str = getenv ("SKIP_TEST_ZERO_FREE_SPACE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ZERO_FREE_SPACE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_zero_free_space_0 (guestfs_h *g)
{
  if (test_zero_free_space_0_skip ()) {
    skipped ("test_zero_free_space_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for zero_free_space (0) */
  const char *_arg522 = "/";
  int _ret521;
  _ret521 = guestfs_zero_free_space (g, _arg522);
  if (_ret521 == -1)
    return -1;
  return 0;
}

static int
test_set_label_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_label") == NULL;
  str = getenv ("SKIP_TEST_SET_LABEL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_LABEL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_set_label_0 (guestfs_h *g)
{
  if (test_set_label_0_skip ()) {
    skipped ("test_set_label_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResultString for set_label (0) */
  const char *_arg525 = "/dev/sda1";
  const char *_arg526 = "testlabel";
  int _ret524;
  _ret524 = guestfs_set_label (g, _arg525, _arg526);
  if (_ret524 == -1)
    return -1;
  const char *_arg528 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, _arg528);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "testlabel")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_label_0", "vfs_label", ret, "testlabel");
    return -1;
  }
  return 0;
}

static int
test_set_label_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_label") == NULL;
  str = getenv ("SKIP_TEST_SET_LABEL_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_LABEL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_set_label_1 (guestfs_h *g)
{
  if (test_set_label_1_skip ()) {
    skipped ("test_set_label_1", "environment variable set");
    return 0;
  }

  const char *_features530[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features530)) {
    skipped ("test_set_label_1", "group %s not available in daemon",
             _features530[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestResultString for set_label (1) */
  const char *_arg532 = "ntfs";
  const char *_arg533 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs534;
  _optargs534.bitmask = UINT64_C(0x0);
  int _ret531;
  _ret531 = guestfs_mkfs_opts_argv (g, _arg532, _arg533, &_optargs534);
  if (_ret531 == -1)
    return -1;
  const char *_arg536 = "/dev/sda1";
  const char *_arg537 = "testlabel2";
  int _ret535;
  _ret535 = guestfs_set_label (g, _arg536, _arg537);
  if (_ret535 == -1)
    return -1;
  const char *_arg539 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, _arg539);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "testlabel2")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_label_1", "vfs_label", ret, "testlabel2");
    return -1;
  }
  return 0;
}

static int
test_set_label_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_label") == NULL;
  str = getenv ("SKIP_TEST_SET_LABEL_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_LABEL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_set_label_2 (guestfs_h *g)
{
  if (test_set_label_2_skip ()) {
    skipped ("test_set_label_2", "environment variable set");
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestLastFail for set_label (2) */
  const char *_arg542 = "/dev/sda1";
  int _ret541;
  _ret541 = guestfs_zero (g, _arg542);
  if (_ret541 == -1)
    return -1;
  const char *_arg545 = "/dev/sda1";
  const char *_arg546 = "testlabel2";
  int _ret544;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret544 = guestfs_set_label (g, _arg545, _arg546);
  guestfs_pop_error_handler (g);
  if (_ret544 != -1)
    return -1;
  return 0;
}

static int
test_ntfsfix_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "ntfsfix") == NULL;
  str = getenv ("SKIP_TEST_NTFSFIX_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_NTFSFIX");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_ntfsfix_0 (guestfs_h *g)
{
  if (test_ntfsfix_0_skip ()) {
    skipped ("test_ntfsfix_0", "environment variable set");
    return 0;
  }

  const char *_features548[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features548)) {
    skipped ("test_ntfsfix_0", "group %s not available in daemon",
             _features548[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for ntfsfix (0) */
  const char *_arg550 = "ntfs";
  const char *_arg551 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs552;
  _optargs552.bitmask = UINT64_C(0x0);
  int _ret549;
  _ret549 = guestfs_mkfs_opts_argv (g, _arg550, _arg551, &_optargs552);
  if (_ret549 == -1)
    return -1;
  const char *_arg554 = "/dev/sda1";
  struct guestfs_ntfsfix_argv _optargs555;
  _optargs555.clearbadsectors = 0;
  _optargs555.bitmask = UINT64_C(0x1);
  int _ret553;
  _ret553 = guestfs_ntfsfix_argv (g, _arg554, &_optargs555);
  if (_ret553 == -1)
    return -1;
  return 0;
}

static int
test_wipefs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "wipefs") == NULL;
  str = getenv ("SKIP_TEST_WIPEFS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WIPEFS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_wipefs_0 (guestfs_h *g)
{
  if (test_wipefs_0_skip ()) {
    skipped ("test_wipefs_0", "environment variable set");
    return 0;
  }

  const char *_features556[] = { "wipefs", NULL };
  if (!guestfs_feature_available (g, (char **) _features556)) {
    skipped ("test_wipefs_0", "group %s not available in daemon",
             _features556[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestRun for wipefs (0) */
  const char *_arg558 = "/dev/VG/LV";
  struct guestfs_umount_opts_argv _optargs559;
  _optargs559.bitmask = UINT64_C(0x0);
  int _ret557;
  _ret557 = guestfs_umount_opts_argv (g, _arg558, &_optargs559);
  if (_ret557 == -1)
    return -1;
  const char *_arg561 = "/dev/VG/LV";
  int _ret560;
  _ret560 = guestfs_wipefs (g, _arg561);
  if (_ret560 == -1)
    return -1;
  return 0;
}

static int
test_blkid_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "blkid") == NULL;
  str = getenv ("SKIP_TEST_BLKID_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BLKID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_blkid_0 (guestfs_h *g)
{
  if (test_blkid_0_skip ()) {
    skipped ("test_blkid_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for blkid (0) */
  const char *_arg563 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_blkid (g, _arg563);
  if (ret == NULL)
      return -1;
  if (! (check_hash (ret, "TYPE", "ext2") == 0 && check_hash (ret, "USAGE", "filesystem") == 0 && check_hash (ret, "PART_ENTRY_NUMBER", "1") == 0 && check_hash (ret, "PART_ENTRY_TYPE", "0x83") == 0 && check_hash (ret, "PART_ENTRY_OFFSET", "128") == 0 && check_hash (ret, "PART_ENTRY_SIZE", "102145") == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_blkid_0", "check_hash (ret, \"TYPE\", \"ext2\") == 0 && check_hash (ret, \"USAGE\", \"filesystem\") == 0 && check_hash (ret, \"PART_ENTRY_NUMBER\", \"1\") == 0 && check_hash (ret, \"PART_ENTRY_TYPE\", \"0x83\") == 0 && check_hash (ret, \"PART_ENTRY_OFFSET\", \"128\") == 0 && check_hash (ret, \"PART_ENTRY_SIZE\", \"102145\") == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_tune2fs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "tune2fs") == NULL;
  str = getenv ("SKIP_TEST_TUNE2FS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TUNE2FS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_tune2fs_0 (guestfs_h *g)
{
  if (test_tune2fs_0_skip ()) {
    skipped ("test_tune2fs_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for tune2fs (0) */
  const char *_arg565 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs566;
  _optargs566.force = 0;
  _optargs566.maxmountcount = 0;
  _optargs566.intervalbetweenchecks = 0;
  _optargs566.bitmask = UINT64_C(0x23);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg565, &_optargs566);
  if (ret1 == -1)
    return -1;
  const char *_arg567 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg567);
  if (ret == NULL)
      return -1;
  if (! (check_hash (ret, "Check interval", "0 (<none>)") == 0 && check_hash (ret, "Maximum mount count", "-1") == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_tune2fs_0", "check_hash (ret, \"Check interval\", \"0 (<none>)\") == 0 && check_hash (ret, \"Maximum mount count\", \"-1\") == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_tune2fs_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "tune2fs") == NULL;
  str = getenv ("SKIP_TEST_TUNE2FS_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TUNE2FS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_tune2fs_1 (guestfs_h *g)
{
  if (test_tune2fs_1_skip ()) {
    skipped ("test_tune2fs_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for tune2fs (1) */
  const char *_arg569 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs570;
  _optargs570.force = 0;
  _optargs570.maxmountcount = 0;
  _optargs570.intervalbetweenchecks = 86400;
  _optargs570.bitmask = UINT64_C(0x23);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg569, &_optargs570);
  if (ret1 == -1)
    return -1;
  const char *_arg571 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg571);
  if (ret == NULL)
      return -1;
  if (! (check_hash (ret, "Check interval", "86400 (1 day)") == 0 && check_hash (ret, "Maximum mount count", "-1") == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_tune2fs_1", "check_hash (ret, \"Check interval\", \"86400 (1 day)\") == 0 && check_hash (ret, \"Maximum mount count\", \"-1\") == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_tune2fs_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "tune2fs") == NULL;
  str = getenv ("SKIP_TEST_TUNE2FS_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TUNE2FS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_tune2fs_2 (guestfs_h *g)
{
  if (test_tune2fs_2_skip ()) {
    skipped ("test_tune2fs_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for tune2fs (2) */
  const char *_arg573 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs574;
  _optargs574.force = 0;
  _optargs574.group = 1;
  _optargs574.user = 1;
  _optargs574.bitmask = UINT64_C(0x211);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg573, &_optargs574);
  if (ret1 == -1)
    return -1;
  const char *_arg575 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg575);
  if (ret == NULL)
      return -1;
  if (! (match_re (get_key (ret, "Reserved blocks uid"), "\\d+ \\(user \\S+\\)") && match_re (get_key (ret, "Reserved blocks gid"), "\\d+ \\(group \\S+\\)"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_tune2fs_2", "match_re (get_key (ret, \"Reserved blocks uid\"), \"\\\\d+ \\\\(user \\\\S+\\\\)\") && match_re (get_key (ret, \"Reserved blocks gid\"), \"\\\\d+ \\\\(group \\\\S+\\\\)\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_tune2fs_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "tune2fs") == NULL;
  str = getenv ("SKIP_TEST_TUNE2FS_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TUNE2FS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_tune2fs_3 (guestfs_h *g)
{
  if (test_tune2fs_3_skip ()) {
    skipped ("test_tune2fs_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for tune2fs (3) */
  const char *_arg577 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs578;
  _optargs578.force = 0;
  _optargs578.group = 0;
  _optargs578.user = 0;
  _optargs578.bitmask = UINT64_C(0x211);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg577, &_optargs578);
  if (ret1 == -1)
    return -1;
  const char *_arg579 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg579);
  if (ret == NULL)
      return -1;
  if (! (match_re (get_key (ret, "Reserved blocks uid"), "\\d+ \\(user \\S+\\)") && match_re (get_key (ret, "Reserved blocks gid"), "\\d+ \\(group \\S+\\)"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_tune2fs_3", "match_re (get_key (ret, \"Reserved blocks uid\"), \"\\\\d+ \\\\(user \\\\S+\\\\)\") && match_re (get_key (ret, \"Reserved blocks gid\"), \"\\\\d+ \\\\(group \\\\S+\\\\)\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_copy_file_to_file_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "copy_file_to_file") == NULL;
  str = getenv ("SKIP_TEST_COPY_FILE_TO_FILE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COPY_FILE_TO_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_copy_file_to_file_0 (guestfs_h *g)
{
  if (test_copy_file_to_file_0_skip ()) {
    skipped ("test_copy_file_to_file_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for copy_file_to_file (0) */
  const char *_arg581 = "/copyff";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg581);
  if (ret3 == -1)
    return -1;
  const char *_arg583 = "/copyff/src";
  const char *_arg584 = "hello, world";
  size_t _arg584_size = 12;
  int ret2;
  ret2 = guestfs_write (g, _arg583, _arg584, _arg584_size);
  if (ret2 == -1)
    return -1;
  const char *_arg586 = "/copyff/src";
  const char *_arg587 = "/copyff/dest";
  struct guestfs_copy_file_to_file_argv _optargs588;
  _optargs588.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_copy_file_to_file_argv (g, _arg586, _arg587, &_optargs588);
  if (ret1 == -1)
    return -1;
  const char *_arg589 = "/copyff/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg589, &size);
  if (ret == NULL)
      return -1;
  if (! (compare_buffers (ret, size, "hello, world", 12) == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_copy_file_to_file_0", "compare_buffers (ret, size, \"hello, world\", 12) == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_copy_file_to_file_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "copy_file_to_file") == NULL;
  str = getenv ("SKIP_TEST_COPY_FILE_TO_FILE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COPY_FILE_TO_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_copy_file_to_file_1 (guestfs_h *g)
{
  if (test_copy_file_to_file_1_skip ()) {
    skipped ("test_copy_file_to_file_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultTrue for copy_file_to_file (1) */
  const char *_arg592 = "/copyff2";
  int _ret591;
  _ret591 = guestfs_mkdir (g, _arg592);
  if (_ret591 == -1)
    return -1;
  const char *_arg597 = "/copyff2/src";
  int _ret594;
  _ret594 = guestfs_fill (g, 0, 1048576, _arg597);
  if (_ret594 == -1)
    return -1;
  const char *_arg600 = "/copyff2/dest";
  int _ret599;
  _ret599 = guestfs_touch (g, _arg600);
  if (_ret599 == -1)
    return -1;
  const char *_arg603 = "/copyff2/dest";
  int _ret602;
  _ret602 = guestfs_truncate_size (g, _arg603, 1048576);
  if (_ret602 == -1)
    return -1;
  const char *_arg607 = "/copyff2/src";
  const char *_arg608 = "/copyff2/dest";
  struct guestfs_copy_file_to_file_argv _optargs609;
  _optargs609.sparse = 1;
  _optargs609.bitmask = UINT64_C(0x8);
  int _ret606;
  _ret606 = guestfs_copy_file_to_file_argv (g, _arg607, _arg608, &_optargs609);
  if (_ret606 == -1)
    return -1;
  const char *_arg610 = "/copyff2/dest";
  int ret;
  ret = guestfs_is_zero (g, _arg610);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_copy_file_to_file_1", "is_zero");
    return -1;
  }
  return 0;
}

static int
test_part_to_partnum_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_to_partnum") == NULL;
  str = getenv ("SKIP_TEST_PART_TO_PARTNUM_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_TO_PARTNUM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_to_partnum_0 (guestfs_h *g)
{
  if (test_part_to_partnum_0_skip ()) {
    skipped ("test_part_to_partnum_0", "environment variable set");
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestResult for part_to_partnum (0) */
  const char *_arg612 = "/dev/sda1";
  int ret;
  ret = guestfs_part_to_partnum (g, _arg612);
  if (ret == -1)
    return -1;
  if (! (ret == 1)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_part_to_partnum_0", "ret == 1");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_part_to_partnum_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_to_partnum") == NULL;
  str = getenv ("SKIP_TEST_PART_TO_PARTNUM_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_TO_PARTNUM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_to_partnum_1 (guestfs_h *g)
{
  if (test_part_to_partnum_1_skip ()) {
    skipped ("test_part_to_partnum_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestLastFail for part_to_partnum (1) */
  const char *_arg615 = "/dev/sda";
  int _ret614;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret614 = guestfs_part_to_partnum (g, _arg615);
  guestfs_pop_error_handler (g);
  if (_ret614 != -1)
    return -1;
  return 0;
}

static int
test_internal_write_append_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "internal_write_append") == NULL;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE_APPEND_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE_APPEND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_internal_write_append_0 (guestfs_h *g)
{
  if (test_internal_write_append_0_skip ()) {
    skipped ("test_internal_write_append_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for internal_write_append (0) */
  const char *_arg618 = "/internal_write_append";
  const char *_arg619 = "line1\n";
  size_t _arg619_size = 6;
  int _ret617;
  _ret617 = guestfs_write (g, _arg618, _arg619, _arg619_size);
  if (_ret617 == -1)
    return -1;
  const char *_arg622 = "/internal_write_append";
  const char *_arg623 = "line2\n";
  size_t _arg623_size = 6;
  int _ret621;
  _ret621 = guestfs_internal_write_append (g, _arg622, _arg623, _arg623_size);
  if (_ret621 == -1)
    return -1;
  const char *_arg626 = "/internal_write_append";
  const char *_arg627 = "line3a";
  size_t _arg627_size = 6;
  int _ret625;
  _ret625 = guestfs_internal_write_append (g, _arg626, _arg627, _arg627_size);
  if (_ret625 == -1)
    return -1;
  const char *_arg630 = "/internal_write_append";
  const char *_arg631 = "line3b\n";
  size_t _arg631_size = 7;
  int _ret629;
  _ret629 = guestfs_internal_write_append (g, _arg630, _arg631, _arg631_size);
  if (_ret629 == -1)
    return -1;
  const char *_arg633 = "/internal_write_append";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg633);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "line1\nline2\nline3aline3b\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_append_0", "cat", ret, "line1\nline2\nline3aline3b\n");
    return -1;
  }
  return 0;
}

static int
test_is_zero_device_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_zero_device") == NULL;
  str = getenv ("SKIP_TEST_IS_ZERO_DEVICE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_ZERO_DEVICE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_zero_device_0 (guestfs_h *g)
{
  if (test_is_zero_device_0_skip ()) {
    skipped ("test_is_zero_device_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResultTrue for is_zero_device (0) */
  const char *_arg636 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs637;
  _optargs637.force = 0;
  _optargs637.lazyunmount = 0;
  _optargs637.bitmask = UINT64_C(0x3);
  int _ret635;
  _ret635 = guestfs_umount_opts_argv (g, _arg636, &_optargs637);
  if (_ret635 == -1)
    return -1;
  const char *_arg639 = "/dev/sda1";
  int _ret638;
  _ret638 = guestfs_zero_device (g, _arg639);
  if (_ret638 == -1)
    return -1;
  const char *_arg641 = "/dev/sda1";
  int ret;
  ret = guestfs_is_zero_device (g, _arg641);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_zero_device_0", "is_zero_device");
    return -1;
  }
  return 0;
}

static int
test_is_zero_device_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_zero_device") == NULL;
  str = getenv ("SKIP_TEST_IS_ZERO_DEVICE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_ZERO_DEVICE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_zero_device_1 (guestfs_h *g)
{
  if (test_is_zero_device_1_skip ()) {
    skipped ("test_is_zero_device_1", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResultFalse for is_zero_device (1) */
  const char *_arg643 = "/dev/sda1";
  int ret;
  ret = guestfs_is_zero_device (g, _arg643);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_zero_device_1", "is_zero_device");
    return -1;
  }
  return 0;
}

static int
test_is_zero_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_zero") == NULL;
  str = getenv ("SKIP_TEST_IS_ZERO_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_ZERO");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_zero_0 (guestfs_h *g)
{
  if (test_is_zero_0_skip ()) {
    skipped ("test_is_zero_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultTrue for is_zero (0) */
  const char *_arg645 = "/100kallzeroes";
  int ret;
  ret = guestfs_is_zero (g, _arg645);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_zero_0", "is_zero");
    return -1;
  }
  return 0;
}

static int
test_is_zero_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_zero") == NULL;
  str = getenv ("SKIP_TEST_IS_ZERO_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_ZERO");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_zero_1 (guestfs_h *g)
{
  if (test_is_zero_1_skip ()) {
    skipped ("test_is_zero_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultFalse for is_zero (1) */
  const char *_arg647 = "/100kallspaces";
  int ret;
  ret = guestfs_is_zero (g, _arg647);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_zero_1", "is_zero");
    return -1;
  }
  return 0;
}

static int
test_mkfs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkfs") == NULL;
  str = getenv ("SKIP_TEST_MKFS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKFS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkfs_0 (guestfs_h *g)
{
  if (test_mkfs_0_skip ()) {
    skipped ("test_mkfs_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for mkfs (0) */
  const char *_arg650 = "/dev/sda";
  const char *_arg651 = "mbr";
  int _ret649;
  _ret649 = guestfs_part_disk (g, _arg650, _arg651);
  if (_ret649 == -1)
    return -1;
  const char *_arg654 = "ext2";
  const char *_arg655 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs656;
  _optargs656.bitmask = UINT64_C(0x0);
  int _ret653;
  _ret653 = guestfs_mkfs_opts_argv (g, _arg654, _arg655, &_optargs656);
  if (_ret653 == -1)
    return -1;
  const char *_arg658 = "/dev/sda1";
  const char *_arg659 = "/";
  int _ret657;
  _ret657 = guestfs_mount (g, _arg658, _arg659);
  if (_ret657 == -1)
    return -1;
  const char *_arg662 = "/new";
  const char *_arg663 = "new file contents";
  size_t _arg663_size = 17;
  int _ret661;
  _ret661 = guestfs_write (g, _arg662, _arg663, _arg663_size);
  if (_ret661 == -1)
    return -1;
  const char *_arg665 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg665);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mkfs_0", "cat", ret, "new file contents");
    return -1;
  }
  return 0;
}

static int
test_lvm_canonical_lv_name_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lvm_canonical_lv_name") == NULL;
  str = getenv ("SKIP_TEST_LVM_CANONICAL_LV_NAME_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LVM_CANONICAL_LV_NAME");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lvm_canonical_lv_name_0 (guestfs_h *g)
{
  if (test_lvm_canonical_lv_name_0_skip ()) {
    skipped ("test_lvm_canonical_lv_name_0", "environment variable set");
    return 0;
  }

  const char *_features667[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features667)) {
    skipped ("test_lvm_canonical_lv_name_0", "group %s not available in daemon",
             _features667[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResultString for lvm_canonical_lv_name (0) */
  const char *_arg668 = "/dev/mapper/VG-LV";
  CLEANUP_FREE char *ret;
  ret = guestfs_lvm_canonical_lv_name (g, _arg668);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/dev/VG/LV")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_lvm_canonical_lv_name_0", "lvm_canonical_lv_name", ret, "/dev/VG/LV");
    return -1;
  }
  return 0;
}

static int
test_lvm_canonical_lv_name_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lvm_canonical_lv_name") == NULL;
  str = getenv ("SKIP_TEST_LVM_CANONICAL_LV_NAME_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LVM_CANONICAL_LV_NAME");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lvm_canonical_lv_name_1 (guestfs_h *g)
{
  if (test_lvm_canonical_lv_name_1_skip ()) {
    skipped ("test_lvm_canonical_lv_name_1", "environment variable set");
    return 0;
  }

  const char *_features670[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features670)) {
    skipped ("test_lvm_canonical_lv_name_1", "group %s not available in daemon",
             _features670[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResultString for lvm_canonical_lv_name (1) */
  const char *_arg671 = "/dev/VG/LV";
  CLEANUP_FREE char *ret;
  ret = guestfs_lvm_canonical_lv_name (g, _arg671);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/dev/VG/LV")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_lvm_canonical_lv_name_1", "lvm_canonical_lv_name", ret, "/dev/VG/LV");
    return -1;
  }
  return 0;
}

static int
test_pread_device_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pread_device") == NULL;
  str = getenv ("SKIP_TEST_PREAD_DEVICE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PREAD_DEVICE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pread_device_0 (guestfs_h *g)
{
  if (test_pread_device_0_skip ()) {
    skipped ("test_pread_device_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pread_device (0) */
  const char *_arg673 = "/dev/sdd";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread_device (g, _arg673, 8, 32768, &size);
  if (ret == NULL)
      return -1;
  if (! (compare_buffers (ret, size, "\1CD001\1\0", 8) == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_pread_device_0", "compare_buffers (ret, size, \"\\1CD001\\1\\0\", 8) == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_pwrite_device_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pwrite_device") == NULL;
  str = getenv ("SKIP_TEST_PWRITE_DEVICE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PWRITE_DEVICE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pwrite_device_0 (guestfs_h *g)
{
  if (test_pwrite_device_0_skip ()) {
    skipped ("test_pwrite_device_0", "environment variable set");
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestResult for pwrite_device (0) */
  const char *_arg677 = "/dev/sda";
  const char *_arg678 = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
  size_t _arg678_size = 66;
  int ret2;
  ret2 = guestfs_pwrite_device (g, _arg677, _arg678, _arg678_size, 446);
  if (ret2 == -1)
    return -1;
  const char *_arg681 = "/dev/sda";
  int ret1;
  ret1 = guestfs_blockdev_rereadpt (g, _arg681);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_list_partitions (g);
  if (ret == NULL)
      return -1;
  if (! (is_device_list (ret, 1, "/dev/sdb1"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_pwrite_device_0", "is_device_list (ret, 1, \"/dev/sdb1\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_download_offset_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "download_offset") == NULL;
  str = getenv ("SKIP_TEST_DOWNLOAD_OFFSET_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DOWNLOAD_OFFSET");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_download_offset_0 (guestfs_h *g)
{
  if (test_download_offset_0_skip ()) {
    skipped ("test_download_offset_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for download_offset (0) */
  const char *_arg685 = "/download_offset";
  int _ret684;
  _ret684 = guestfs_mkdir (g, _arg685);
  if (_ret684 == -1)
    return -1;
  CLEANUP_FREE char *_arg688 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *_arg689 = "/download_offset/COPYING.LIB";
  int _ret687;
  _ret687 = guestfs_upload (g, _arg688, _arg689);
  if (_ret687 == -1)
    return -1;
  const char *_arg692 = "/download_offset/COPYING.LIB";
  int _ret691;
  _ret691 = guestfs_download_offset (g, _arg692, "testdownload.tmp", 100, 26430);
  if (_ret691 == -1)
    return -1;
  CLEANUP_FREE char *_arg698 = substitute_srcdir ("testdownload.tmp");
  const char *_arg699 = "/download_offset/COPYING.LIB";
  int _ret697;
  _ret697 = guestfs_upload_offset (g, _arg698, _arg699, 100);
  if (_ret697 == -1)
    return -1;
  const char *_arg702 = "md5";
  const char *_arg703 = "/download_offset/COPYING.LIB";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg702, _arg703);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "4fbd65380cdd255951079008b364516c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_download_offset_0", "checksum", ret, "4fbd65380cdd255951079008b364516c");
    return -1;
  }
  return 0;
}

static int
test_upload_offset_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "upload_offset") == NULL;
  str = getenv ("SKIP_TEST_UPLOAD_OFFSET_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UPLOAD_OFFSET");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_upload_offset_0 (guestfs_h *g)
{
  if (test_upload_offset_0_skip ()) {
    skipped ("test_upload_offset_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for upload_offset (0) */
  CLEANUP_FREE char *_arg706 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *_arg707 = "/upload_offset";
  int _ret705;
  _ret705 = guestfs_upload_offset (g, _arg706, _arg707, 0);
  if (_ret705 == -1)
    return -1;
  const char *_arg710 = "md5";
  const char *_arg711 = "/upload_offset";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg710, _arg711);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "4fbd65380cdd255951079008b364516c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_upload_offset_0", "checksum", ret, "4fbd65380cdd255951079008b364516c");
    return -1;
  }
  return 0;
}

static int
test_part_to_dev_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_to_dev") == NULL;
  str = getenv ("SKIP_TEST_PART_TO_DEV_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_TO_DEV");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_to_dev_0 (guestfs_h *g)
{
  if (test_part_to_dev_0_skip ()) {
    skipped ("test_part_to_dev_0", "environment variable set");
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestResultDevice for part_to_dev (0) */
  const char *_arg713 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_to_dev (g, _arg713);
  if (ret == NULL)
      return -1;
  if (compare_devices (ret, "/dev/sda") != 0) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_part_to_dev_0", "part_to_dev", ret, "/dev/sda");
    return -1;
  }
  return 0;
}

static int
test_part_to_dev_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_to_dev") == NULL;
  str = getenv ("SKIP_TEST_PART_TO_DEV_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_TO_DEV");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_to_dev_1 (guestfs_h *g)
{
  if (test_part_to_dev_1_skip ()) {
    skipped ("test_part_to_dev_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestLastFail for part_to_dev (1) */
  const char *_arg716 = "/dev/sda";
  CLEANUP_FREE char *_ret715;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret715 = guestfs_part_to_dev (g, _arg716);
  guestfs_pop_error_handler (g);
  if (_ret715 != NULL)
    return -1;
  return 0;
}

static int
test_is_socket_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_socket") == NULL;
  str = getenv ("SKIP_TEST_IS_SOCKET_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_SOCKET");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_socket_0 (guestfs_h *g)
{
  if (test_is_socket_0_skip ()) {
    skipped ("test_is_socket_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultFalse for is_socket (0) */
  const char *_arg718 = "/directory";
  int ret;
  ret = guestfs_is_socket (g, _arg718);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_socket_0", "is_socket");
    return -1;
  }
  return 0;
}

static int
test_is_symlink_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_symlink") == NULL;
  str = getenv ("SKIP_TEST_IS_SYMLINK_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_SYMLINK");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_symlink_0 (guestfs_h *g)
{
  if (test_is_symlink_0_skip ()) {
    skipped ("test_is_symlink_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultFalse for is_symlink (0) */
  const char *_arg720 = "/directory";
  int ret;
  ret = guestfs_is_symlink (g, _arg720);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_symlink_0", "is_symlink");
    return -1;
  }
  return 0;
}

static int
test_is_symlink_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_symlink") == NULL;
  str = getenv ("SKIP_TEST_IS_SYMLINK_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_SYMLINK");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_symlink_1 (guestfs_h *g)
{
  if (test_is_symlink_1_skip ()) {
    skipped ("test_is_symlink_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultTrue for is_symlink (1) */
  const char *_arg722 = "/abssymlink";
  int ret;
  ret = guestfs_is_symlink (g, _arg722);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_symlink_1", "is_symlink");
    return -1;
  }
  return 0;
}

static int
test_is_fifo_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_fifo") == NULL;
  str = getenv ("SKIP_TEST_IS_FIFO_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_FIFO");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_fifo_0 (guestfs_h *g)
{
  if (test_is_fifo_0_skip ()) {
    skipped ("test_is_fifo_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultFalse for is_fifo (0) */
  const char *_arg724 = "/directory";
  int ret;
  ret = guestfs_is_fifo (g, _arg724);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_fifo_0", "is_fifo");
    return -1;
  }
  return 0;
}

static int
test_is_fifo_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_fifo") == NULL;
  str = getenv ("SKIP_TEST_IS_FIFO_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_FIFO");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_fifo_1 (guestfs_h *g)
{
  if (test_is_fifo_1_skip ()) {
    skipped ("test_is_fifo_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultTrue for is_fifo (1) */
  const char *_arg728 = "/is_fifo";
  int _ret726;
  _ret726 = guestfs_mkfifo (g, 511, _arg728);
  if (_ret726 == -1)
    return -1;
  const char *_arg730 = "/is_fifo";
  int ret;
  ret = guestfs_is_fifo (g, _arg730);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_fifo_1", "is_fifo");
    return -1;
  }
  return 0;
}

static int
test_is_blockdev_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_blockdev") == NULL;
  str = getenv ("SKIP_TEST_IS_BLOCKDEV_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_BLOCKDEV");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_blockdev_0 (guestfs_h *g)
{
  if (test_is_blockdev_0_skip ()) {
    skipped ("test_is_blockdev_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultFalse for is_blockdev (0) */
  const char *_arg732 = "/directory";
  int ret;
  ret = guestfs_is_blockdev (g, _arg732);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_blockdev_0", "is_blockdev");
    return -1;
  }
  return 0;
}

static int
test_is_blockdev_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_blockdev") == NULL;
  str = getenv ("SKIP_TEST_IS_BLOCKDEV_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_BLOCKDEV");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_blockdev_1 (guestfs_h *g)
{
  if (test_is_blockdev_1_skip ()) {
    skipped ("test_is_blockdev_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultTrue for is_blockdev (1) */
  const char *_arg738 = "/is_blockdev";
  int _ret734;
  _ret734 = guestfs_mknod_b (g, 511, 99, 66, _arg738);
  if (_ret734 == -1)
    return -1;
  const char *_arg740 = "/is_blockdev";
  int ret;
  ret = guestfs_is_blockdev (g, _arg740);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_blockdev_1", "is_blockdev");
    return -1;
  }
  return 0;
}

static int
test_is_chardev_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_chardev") == NULL;
  str = getenv ("SKIP_TEST_IS_CHARDEV_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_CHARDEV");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_chardev_0 (guestfs_h *g)
{
  if (test_is_chardev_0_skip ()) {
    skipped ("test_is_chardev_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultFalse for is_chardev (0) */
  const char *_arg742 = "/directory";
  int ret;
  ret = guestfs_is_chardev (g, _arg742);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_chardev_0", "is_chardev");
    return -1;
  }
  return 0;
}

static int
test_is_chardev_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_chardev") == NULL;
  str = getenv ("SKIP_TEST_IS_CHARDEV_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_CHARDEV");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_chardev_1 (guestfs_h *g)
{
  if (test_is_chardev_1_skip ()) {
    skipped ("test_is_chardev_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultTrue for is_chardev (1) */
  const char *_arg748 = "/is_chardev";
  int _ret744;
  _ret744 = guestfs_mknod_c (g, 511, 99, 66, _arg748);
  if (_ret744 == -1)
    return -1;
  const char *_arg750 = "/is_chardev";
  int ret;
  ret = guestfs_is_chardev (g, _arg750);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_chardev_1", "is_chardev");
    return -1;
  }
  return 0;
}

static int
test_is_lv_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_lv") == NULL;
  str = getenv ("SKIP_TEST_IS_LV_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_LV");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_lv_0 (guestfs_h *g)
{
  if (test_is_lv_0_skip ()) {
    skipped ("test_is_lv_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResultTrue for is_lv (0) */
  const char *_arg752 = "/dev/VG/LV";
  int ret;
  ret = guestfs_is_lv (g, _arg752);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_lv_0", "is_lv");
    return -1;
  }
  return 0;
}

static int
test_is_lv_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_lv") == NULL;
  str = getenv ("SKIP_TEST_IS_LV_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_LV");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_lv_1 (guestfs_h *g)
{
  if (test_is_lv_1_skip ()) {
    skipped ("test_is_lv_1", "environment variable set");
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResultFalse for is_lv (1) */
  const char *_arg754 = "/dev/sda1";
  int ret;
  ret = guestfs_is_lv (g, _arg754);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_lv_1", "is_lv");
    return -1;
  }
  return 0;
}

static int
test_vfs_uuid_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vfs_uuid") == NULL;
  str = getenv ("SKIP_TEST_VFS_UUID_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VFS_UUID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vfs_uuid_0 (guestfs_h *g)
{
  if (test_vfs_uuid_0_skip ()) {
    skipped ("test_vfs_uuid_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResultString for vfs_uuid (0) */
  const char *_arg757 = "/dev/sda1";
  const char *_arg758 = "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b";
  int _ret756;
  _ret756 = guestfs_set_e2uuid (g, _arg757, _arg758);
  if (_ret756 == -1)
    return -1;
  const char *_arg760 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_uuid (g, _arg760);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_vfs_uuid_0", "vfs_uuid", ret, "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b");
    return -1;
  }
  return 0;
}

static int
test_vfs_label_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vfs_label") == NULL;
  str = getenv ("SKIP_TEST_VFS_LABEL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VFS_LABEL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vfs_label_0 (guestfs_h *g)
{
  if (test_vfs_label_0_skip ()) {
    skipped ("test_vfs_label_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResultString for vfs_label (0) */
  const char *_arg763 = "/dev/sda1";
  const char *_arg764 = "LTEST";
  int _ret762;
  _ret762 = guestfs_set_label (g, _arg763, _arg764);
  if (_ret762 == -1)
    return -1;
  const char *_arg766 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, _arg766);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "LTEST")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_vfs_label_0", "vfs_label", ret, "LTEST");
    return -1;
  }
  return 0;
}

static int
test_fallocate64_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "fallocate64") == NULL;
  str = getenv ("SKIP_TEST_FALLOCATE64_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FALLOCATE64");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_fallocate64_0 (guestfs_h *g)
{
  if (test_fallocate64_0_skip ()) {
    skipped ("test_fallocate64_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for fallocate64 (0) */
  const char *_arg768 = "/fallocate64";
  int ret1;
  ret1 = guestfs_fallocate64 (g, _arg768, 1000000);
  if (ret1 == -1)
    return -1;
  const char *_arg771 = "/fallocate64";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg771);
  if (ret == NULL)
      return -1;
  if (! (ret->size == 1000000)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_fallocate64_0", "ret->size == 1000000");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_available_all_groups_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "available_all_groups") == NULL;
  str = getenv ("SKIP_TEST_AVAILABLE_ALL_GROUPS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_AVAILABLE_ALL_GROUPS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_available_all_groups_0 (guestfs_h *g)
{
  if (test_available_all_groups_0_skip ()) {
    skipped ("test_available_all_groups_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for available_all_groups (0) */
  CLEANUP_FREE_STRING_LIST char **_ret773;
  _ret773 = guestfs_available_all_groups (g);
  if (_ret773 == NULL)
      return -1;
  return 0;
}

static int
test_pwrite_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pwrite") == NULL;
  str = getenv ("SKIP_TEST_PWRITE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PWRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pwrite_0 (guestfs_h *g)
{
  if (test_pwrite_0_skip ()) {
    skipped ("test_pwrite_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for pwrite (0) */
  const char *_arg776 = "/pwrite";
  const char *_arg777 = "new file contents";
  size_t _arg777_size = 17;
  int _ret775;
  _ret775 = guestfs_write (g, _arg776, _arg777, _arg777_size);
  if (_ret775 == -1)
    return -1;
  const char *_arg780 = "/pwrite";
  const char *_arg781 = "data";
  size_t _arg781_size = 4;
  int _ret779;
  _ret779 = guestfs_pwrite (g, _arg780, _arg781, _arg781_size, 4);
  if (_ret779 == -1)
    return -1;
  const char *_arg784 = "/pwrite";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg784);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new data contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_pwrite_0", "cat", ret, "new data contents");
    return -1;
  }
  return 0;
}

static int
test_pwrite_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pwrite") == NULL;
  str = getenv ("SKIP_TEST_PWRITE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PWRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pwrite_1 (guestfs_h *g)
{
  if (test_pwrite_1_skip ()) {
    skipped ("test_pwrite_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for pwrite (1) */
  const char *_arg787 = "/pwrite2";
  const char *_arg788 = "new file contents";
  size_t _arg788_size = 17;
  int _ret786;
  _ret786 = guestfs_write (g, _arg787, _arg788, _arg788_size);
  if (_ret786 == -1)
    return -1;
  const char *_arg791 = "/pwrite2";
  const char *_arg792 = "is extended";
  size_t _arg792_size = 11;
  int _ret790;
  _ret790 = guestfs_pwrite (g, _arg791, _arg792, _arg792_size, 9);
  if (_ret790 == -1)
    return -1;
  const char *_arg795 = "/pwrite2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg795);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file is extended")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_pwrite_1", "cat", ret, "new file is extended");
    return -1;
  }
  return 0;
}

static int
test_pwrite_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pwrite") == NULL;
  str = getenv ("SKIP_TEST_PWRITE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PWRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pwrite_2 (guestfs_h *g)
{
  if (test_pwrite_2_skip ()) {
    skipped ("test_pwrite_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for pwrite (2) */
  const char *_arg798 = "/pwrite3";
  const char *_arg799 = "new file contents";
  size_t _arg799_size = 17;
  int _ret797;
  _ret797 = guestfs_write (g, _arg798, _arg799, _arg799_size);
  if (_ret797 == -1)
    return -1;
  const char *_arg802 = "/pwrite3";
  const char *_arg803 = "";
  size_t _arg803_size = 0;
  int _ret801;
  _ret801 = guestfs_pwrite (g, _arg802, _arg803, _arg803_size, 4);
  if (_ret801 == -1)
    return -1;
  const char *_arg806 = "/pwrite3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg806);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_pwrite_2", "cat", ret, "new file contents");
    return -1;
  }
  return 0;
}

static int
test_internal_write_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "internal_write") == NULL;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_internal_write_0 (guestfs_h *g)
{
  if (test_internal_write_0_skip ()) {
    skipped ("test_internal_write_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for internal_write (0) */
  const char *_arg809 = "/internal_write";
  const char *_arg810 = "new file contents";
  size_t _arg810_size = 17;
  int _ret808;
  _ret808 = guestfs_internal_write (g, _arg809, _arg810, _arg810_size);
  if (_ret808 == -1)
    return -1;
  const char *_arg812 = "/internal_write";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg812);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_0", "cat", ret, "new file contents");
    return -1;
  }
  return 0;
}

static int
test_internal_write_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "internal_write") == NULL;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_internal_write_1 (guestfs_h *g)
{
  if (test_internal_write_1_skip ()) {
    skipped ("test_internal_write_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for internal_write (1) */
  const char *_arg815 = "/internal_write2";
  const char *_arg816 = "\nnew file contents\n";
  size_t _arg816_size = 19;
  int _ret814;
  _ret814 = guestfs_internal_write (g, _arg815, _arg816, _arg816_size);
  if (_ret814 == -1)
    return -1;
  const char *_arg818 = "/internal_write2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg818);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\nnew file contents\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_1", "cat", ret, "\nnew file contents\n");
    return -1;
  }
  return 0;
}

static int
test_internal_write_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "internal_write") == NULL;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_internal_write_2 (guestfs_h *g)
{
  if (test_internal_write_2_skip ()) {
    skipped ("test_internal_write_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for internal_write (2) */
  const char *_arg821 = "/internal_write3";
  const char *_arg822 = "\n\n";
  size_t _arg822_size = 2;
  int _ret820;
  _ret820 = guestfs_internal_write (g, _arg821, _arg822, _arg822_size);
  if (_ret820 == -1)
    return -1;
  const char *_arg824 = "/internal_write3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg824);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_2", "cat", ret, "\n\n");
    return -1;
  }
  return 0;
}

static int
test_internal_write_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "internal_write") == NULL;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_internal_write_3 (guestfs_h *g)
{
  if (test_internal_write_3_skip ()) {
    skipped ("test_internal_write_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for internal_write (3) */
  const char *_arg827 = "/internal_write4";
  const char *_arg828 = "";
  size_t _arg828_size = 0;
  int _ret826;
  _ret826 = guestfs_internal_write (g, _arg827, _arg828, _arg828_size);
  if (_ret826 == -1)
    return -1;
  const char *_arg830 = "/internal_write4";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg830);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_3", "cat", ret, "");
    return -1;
  }
  return 0;
}

static int
test_internal_write_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "internal_write") == NULL;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_internal_write_4 (guestfs_h *g)
{
  if (test_internal_write_4_skip ()) {
    skipped ("test_internal_write_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for internal_write (4) */
  const char *_arg833 = "/internal_write5";
  const char *_arg834 = "\n\n\n";
  size_t _arg834_size = 3;
  int _ret832;
  _ret832 = guestfs_internal_write (g, _arg833, _arg834, _arg834_size);
  if (_ret832 == -1)
    return -1;
  const char *_arg836 = "/internal_write5";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg836);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_4", "cat", ret, "\n\n\n");
    return -1;
  }
  return 0;
}

static int
test_internal_write_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "internal_write") == NULL;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_INTERNAL_WRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_internal_write_5 (guestfs_h *g)
{
  if (test_internal_write_5_skip ()) {
    skipped ("test_internal_write_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for internal_write (5) */
  const char *_arg839 = "/internal_write6";
  const char *_arg840 = "\n";
  size_t _arg840_size = 1;
  int _ret838;
  _ret838 = guestfs_internal_write (g, _arg839, _arg840, _arg840_size);
  if (_ret838 == -1)
    return -1;
  const char *_arg842 = "/internal_write6";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg842);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_5", "cat", ret, "\n");
    return -1;
  }
  return 0;
}

static int
test_fill_pattern_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "fill_pattern") == NULL;
  str = getenv ("SKIP_TEST_FILL_PATTERN_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILL_PATTERN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_fill_pattern_0 (guestfs_h *g)
{
  if (test_fill_pattern_0_skip ()) {
    skipped ("test_fill_pattern_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for fill_pattern (0) */
  const char *_arg844 = "abcdefghijklmnopqrstuvwxyz";
  const char *_arg846 = "/fill_pattern";
  int ret1;
  ret1 = guestfs_fill_pattern (g, _arg844, 28, _arg846);
  if (ret1 == -1)
    return -1;
  const char *_arg848 = "/fill_pattern";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg848, &size);
  if (ret == NULL)
      return -1;
  if (! (compare_buffers (ret, size, "abcdefghijklmnopqrstuvwxyzab", 28) == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_fill_pattern_0", "compare_buffers (ret, size, \"abcdefghijklmnopqrstuvwxyzab\", 28) == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_base64_in_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "base64_in") == NULL;
  str = getenv ("SKIP_TEST_BASE64_IN_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BASE64_IN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_base64_in_0 (guestfs_h *g)
{
  if (test_base64_in_0_skip ()) {
    skipped ("test_base64_in_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for base64_in (0) */
  CLEANUP_FREE char *_arg851 = substitute_srcdir ("../data/hello.b64");
  const char *_arg852 = "/base64_in";
  int _ret850;
  _ret850 = guestfs_base64_in (g, _arg851, _arg852);
  if (_ret850 == -1)
    return -1;
  const char *_arg854 = "/base64_in";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg854);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "hello\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_base64_in_0", "cat", ret, "hello\n");
    return -1;
  }
  return 0;
}

static int
test_get_umask_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_umask") == NULL;
  str = getenv ("SKIP_TEST_GET_UMASK_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_UMASK");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_umask_0 (guestfs_h *g)
{
  if (test_get_umask_0_skip ()) {
    skipped ("test_get_umask_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for get_umask (0) */
  int ret;
  ret = guestfs_get_umask (g);
  if (ret == -1)
    return -1;
  if (! (ret == 022)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_get_umask_0", "ret == 022");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_lvresize_free_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lvresize_free") == NULL;
  str = getenv ("SKIP_TEST_LVRESIZE_FREE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LVRESIZE_FREE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lvresize_free_0 (guestfs_h *g)
{
  if (test_lvresize_free_0_skip ()) {
    skipped ("test_lvresize_free_0", "environment variable set");
    return 0;
  }

  const char *_features857[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features857)) {
    skipped ("test_lvresize_free_0", "group %s not available in daemon",
             _features857[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for lvresize_free (0) */
  const char *_arg859 = "/dev/sda";
  const char *_arg860 = "mbr";
  int _ret858;
  _ret858 = guestfs_part_disk (g, _arg859, _arg860);
  if (_ret858 == -1)
    return -1;
  const char *_arg863 = "/dev/sda1";
  int _ret862;
  _ret862 = guestfs_pvcreate (g, _arg863);
  if (_ret862 == -1)
    return -1;
  const char *_arg866 = "VG";
  const char *_arg867_0 = "/dev/sda1";
  const char *const _arg867[] = {
    _arg867_0,
    NULL
  };
  int _ret865;
  _ret865 = guestfs_vgcreate (g, _arg866, (char **) _arg867);
  if (_ret865 == -1)
    return -1;
  const char *_arg870 = "LV";
  const char *_arg871 = "VG";
  int _ret869;
  _ret869 = guestfs_lvcreate (g, _arg870, _arg871, 10);
  if (_ret869 == -1)
    return -1;
  const char *_arg875 = "/dev/VG/LV";
  int _ret874;
  _ret874 = guestfs_lvresize_free (g, _arg875, 100);
  if (_ret874 == -1)
    return -1;
  return 0;
}

static int
test_checksum_device_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "checksum_device") == NULL;
  str = getenv ("SKIP_TEST_CHECKSUM_DEVICE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CHECKSUM_DEVICE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_checksum_device_0 (guestfs_h *g)
{
  if (test_checksum_device_0_skip ()) {
    skipped ("test_checksum_device_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for checksum_device (0) */
  const char *_arg878 = "md5";
  const char *_arg879 = "/dev/sdd";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum_device (g, _arg878, _arg879);
  if (ret == NULL)
      return -1;
  if (! (check_file_md5 (ret, "../data/test.iso") == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_checksum_device_0", "check_file_md5 (ret, \"../data/test.iso\") == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_part_get_mbr_id_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_get_mbr_id") == NULL;
  str = getenv ("SKIP_TEST_PART_GET_MBR_ID_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_GET_MBR_ID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_get_mbr_id_0 (guestfs_h *g)
{
  if (test_part_get_mbr_id_0_skip ()) {
    skipped ("test_part_get_mbr_id_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for part_get_mbr_id (0) */
  const char *_arg881 = "/dev/sda";
  const char *_arg882 = "mbr";
  int ret3;
  ret3 = guestfs_part_init (g, _arg881, _arg882);
  if (ret3 == -1)
    return -1;
  const char *_arg884 = "/dev/sda";
  const char *_arg885 = "primary";
  int ret2;
  ret2 = guestfs_part_add (g, _arg884, _arg885, 1, -1);
  if (ret2 == -1)
    return -1;
  const char *_arg889 = "/dev/sda";
  int ret1;
  ret1 = guestfs_part_set_mbr_id (g, _arg889, 1, 127);
  if (ret1 == -1)
    return -1;
  const char *_arg893 = "/dev/sda";
  int ret;
  ret = guestfs_part_get_mbr_id (g, _arg893, 1);
  if (ret == -1)
    return -1;
  if (! (ret == 0x7f)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_part_get_mbr_id_0", "ret == 0x7f");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_part_get_bootable_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_get_bootable") == NULL;
  str = getenv ("SKIP_TEST_PART_GET_BOOTABLE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_GET_BOOTABLE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_get_bootable_0 (guestfs_h *g)
{
  if (test_part_get_bootable_0_skip ()) {
    skipped ("test_part_get_bootable_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultTrue for part_get_bootable (0) */
  const char *_arg897 = "/dev/sda";
  const char *_arg898 = "mbr";
  int _ret896;
  _ret896 = guestfs_part_init (g, _arg897, _arg898);
  if (_ret896 == -1)
    return -1;
  const char *_arg901 = "/dev/sda";
  const char *_arg902 = "primary";
  int _ret900;
  _ret900 = guestfs_part_add (g, _arg901, _arg902, 1, -1);
  if (_ret900 == -1)
    return -1;
  const char *_arg907 = "/dev/sda";
  int _ret906;
  _ret906 = guestfs_part_set_bootable (g, _arg907, 1, 1);
  if (_ret906 == -1)
    return -1;
  const char *_arg911 = "/dev/sda";
  int ret;
  ret = guestfs_part_get_bootable (g, _arg911, 1);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_part_get_bootable_0", "part_get_bootable");
    return -1;
  }
  return 0;
}

static int
test_part_del_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_del") == NULL;
  str = getenv ("SKIP_TEST_PART_DEL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_DEL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_del_0 (guestfs_h *g)
{
  if (test_part_del_0_skip ()) {
    skipped ("test_part_del_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for part_del (0) */
  const char *_arg915 = "/dev/sda";
  const char *_arg916 = "mbr";
  int _ret914;
  _ret914 = guestfs_part_init (g, _arg915, _arg916);
  if (_ret914 == -1)
    return -1;
  const char *_arg919 = "/dev/sda";
  const char *_arg920 = "primary";
  int _ret918;
  _ret918 = guestfs_part_add (g, _arg919, _arg920, 1, -1);
  if (_ret918 == -1)
    return -1;
  const char *_arg925 = "/dev/sda";
  int _ret924;
  _ret924 = guestfs_part_del (g, _arg925, 1);
  if (_ret924 == -1)
    return -1;
  return 0;
}

static int
test_vgscan_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vgscan") == NULL;
  str = getenv ("SKIP_TEST_VGSCAN_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VGSCAN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vgscan_0 (guestfs_h *g)
{
  if (test_vgscan_0_skip ()) {
    skipped ("test_vgscan_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for vgscan (0) */
  int _ret928;
  _ret928 = guestfs_vgscan (g);
  if (_ret928 == -1)
    return -1;
  return 0;
}

static int
test_txz_in_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "txz_in") == NULL;
  str = getenv ("SKIP_TEST_TXZ_IN_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TXZ_IN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_txz_in_0 (guestfs_h *g)
{
  if (test_txz_in_0_skip ()) {
    skipped ("test_txz_in_0", "environment variable set");
    return 0;
  }

  const char *_features930[] = { "xz", NULL };
  if (!guestfs_feature_available (g, (char **) _features930)) {
    skipped ("test_txz_in_0", "group %s not available in daemon",
             _features930[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for txz_in (0) */
  const char *_arg932 = "/txz_in";
  int _ret931;
  _ret931 = guestfs_mkdir (g, _arg932);
  if (_ret931 == -1)
    return -1;
  CLEANUP_FREE char *_arg935 = substitute_srcdir ("$srcdir/../data/helloworld.tar.xz");
  const char *_arg936 = "/txz_in";
  int _ret934;
  _ret934 = guestfs_txz_in (g, _arg935, _arg936);
  if (_ret934 == -1)
    return -1;
  const char *_arg938 = "/txz_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg938);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "hello\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_txz_in_0", "cat", ret, "hello\n");
    return -1;
  }
  return 0;
}

static int
test_zero_device_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "zero_device") == NULL;
  str = getenv ("SKIP_TEST_ZERO_DEVICE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ZERO_DEVICE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_zero_device_0 (guestfs_h *g)
{
  if (test_zero_device_0_skip ()) {
    skipped ("test_zero_device_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestRun for zero_device (0) */
  const char *_arg941 = "/dev/VG/LV";
  int _ret940;
  _ret940 = guestfs_zero_device (g, _arg941);
  if (_ret940 == -1)
    return -1;
  return 0;
}

static int
test_copy_size_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "copy_size") == NULL;
  str = getenv ("SKIP_TEST_COPY_SIZE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COPY_SIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_copy_size_0 (guestfs_h *g)
{
  if (test_copy_size_0_skip ()) {
    skipped ("test_copy_size_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for copy_size (0) */
  const char *_arg943 = "/copy_size";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg943);
  if (ret3 == -1)
    return -1;
  const char *_arg945 = "/copy_size/src";
  const char *_arg946 = "hello, world";
  size_t _arg946_size = 12;
  int ret2;
  ret2 = guestfs_write (g, _arg945, _arg946, _arg946_size);
  if (ret2 == -1)
    return -1;
  const char *_arg948 = "/copy_size/src";
  const char *_arg949 = "/copy_size/dest";
  int ret1;
  ret1 = guestfs_copy_size (g, _arg948, _arg949, 5);
  if (ret1 == -1)
    return -1;
  const char *_arg952 = "/copy_size/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg952, &size);
  if (ret == NULL)
      return -1;
  if (! (compare_buffers (ret, size, "hello", 5) == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_copy_size_0", "compare_buffers (ret, size, \"hello\", 5) == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_initrd_cat_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "initrd_cat") == NULL;
  str = getenv ("SKIP_TEST_INITRD_CAT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_INITRD_CAT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_initrd_cat_0 (guestfs_h *g)
{
  if (test_initrd_cat_0_skip ()) {
    skipped ("test_initrd_cat_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for initrd_cat (0) */
  const char *_arg954 = "/initrd";
  const char *_arg955 = "known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_initrd_cat (g, _arg954, _arg955, &size);
  if (ret == NULL)
      return -1;
  if (! (compare_buffers (ret, size, "abc\ndef\nghi", 11) == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_initrd_cat_0", "compare_buffers (ret, size, \"abc\\ndef\\nghi\", 11) == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_vgrename_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vgrename") == NULL;
  str = getenv ("SKIP_TEST_VGRENAME_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VGRENAME");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vgrename_0 (guestfs_h *g)
{
  if (test_vgrename_0_skip ()) {
    skipped ("test_vgrename_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResult for vgrename (0) */
  const char *_arg957 = "/";
  struct guestfs_umount_opts_argv _optargs958;
  _optargs958.force = 0;
  _optargs958.lazyunmount = 0;
  _optargs958.bitmask = UINT64_C(0x3);
  int ret5;
  ret5 = guestfs_umount_opts_argv (g, _arg957, &_optargs958);
  if (ret5 == -1)
    return -1;
  const char *_arg960_0 = "VG";
  const char *const _arg960[] = {
    _arg960_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vg_activate (g, 0, (char **) _arg960);
  if (ret4 == -1)
    return -1;
  const char *_arg962 = "VG";
  const char *_arg963 = "VG2";
  int ret3;
  ret3 = guestfs_vgrename (g, _arg962, _arg963);
  if (ret3 == -1)
    return -1;
  const char *_arg966_0 = "VG2";
  const char *const _arg966[] = {
    _arg966_0,
    NULL
  };
  int ret2;
  ret2 = guestfs_vg_activate (g, 1, (char **) _arg966);
  if (ret2 == -1)
    return -1;
  const char *_arg968 = "/dev/VG2/LV";
  const char *_arg969 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg968, _arg969);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_vgs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 1, "VG2"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_vgrename_0", "is_string_list (ret, 1, \"VG2\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_lvrename_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lvrename") == NULL;
  str = getenv ("SKIP_TEST_LVRENAME_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LVRENAME");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lvrename_0 (guestfs_h *g)
{
  if (test_lvrename_0_skip ()) {
    skipped ("test_lvrename_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResult for lvrename (0) */
  const char *_arg972 = "/dev/VG/LV";
  const char *_arg973 = "/dev/VG/LV2";
  int ret1;
  ret1 = guestfs_lvrename (g, _arg972, _arg973);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_lvs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 1, "/dev/VG/LV2"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_lvrename_0", "is_string_list (ret, 1, \"/dev/VG/LV2\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_filesize_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "filesize") == NULL;
  str = getenv ("SKIP_TEST_FILESIZE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILESIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_filesize_0 (guestfs_h *g)
{
  if (test_filesize_0_skip ()) {
    skipped ("test_filesize_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for filesize (0) */
  const char *_arg976 = "/filesize";
  const char *_arg977 = "hello, world";
  size_t _arg977_size = 12;
  int ret1;
  ret1 = guestfs_write (g, _arg976, _arg977, _arg977_size);
  if (ret1 == -1)
    return -1;
  const char *_arg979 = "/filesize";
  int64_t ret;
  ret = guestfs_filesize (g, _arg979);
  if (ret == -1)
    return -1;
  if (! (ret == 12)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_filesize_0", "ret == 12");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_dd_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "dd") == NULL;
  str = getenv ("SKIP_TEST_DD_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DD");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_dd_0 (guestfs_h *g)
{
  if (test_dd_0_skip ()) {
    skipped ("test_dd_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for dd (0) */
  const char *_arg981 = "/dd";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg981);
  if (ret3 == -1)
    return -1;
  const char *_arg983 = "/dd/src";
  const char *_arg984 = "hello, world";
  size_t _arg984_size = 12;
  int ret2;
  ret2 = guestfs_write (g, _arg983, _arg984, _arg984_size);
  if (ret2 == -1)
    return -1;
  const char *_arg986 = "/dd/src";
  const char *_arg987 = "/dd/dest";
  int ret1;
  ret1 = guestfs_dd (g, _arg986, _arg987);
  if (ret1 == -1)
    return -1;
  const char *_arg989 = "/dd/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg989, &size);
  if (ret == NULL)
      return -1;
  if (! (compare_buffers (ret, size, "hello, world", 12) == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_dd_0", "compare_buffers (ret, size, \"hello, world\", 12) == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_available_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "available") == NULL;
  str = getenv ("SKIP_TEST_AVAILABLE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_AVAILABLE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_available_0 (guestfs_h *g)
{
  if (test_available_0_skip ()) {
    skipped ("test_available_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for available (0) */
  const char *const _arg992[1] = { NULL };
  int _ret991;
  _ret991 = guestfs_available (g, (char **) _arg992);
  if (_ret991 == -1)
    return -1;
  return 0;
}

static int
test_fill_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "fill") == NULL;
  str = getenv ("SKIP_TEST_FILL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_fill_0 (guestfs_h *g)
{
  if (test_fill_0_skip ()) {
    skipped ("test_fill_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for fill (0) */
  const char *_arg996 = "/fill";
  int ret1;
  ret1 = guestfs_fill (g, 99, 10, _arg996);
  if (ret1 == -1)
    return -1;
  const char *_arg998 = "/fill";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg998, &size);
  if (ret == NULL)
      return -1;
  if (! (compare_buffers (ret, size, "cccccccccc", 10) == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_fill_0", "compare_buffers (ret, size, \"cccccccccc\", 10) == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_part_get_parttype_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_get_parttype") == NULL;
  str = getenv ("SKIP_TEST_PART_GET_PARTTYPE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_GET_PARTTYPE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_get_parttype_0 (guestfs_h *g)
{
  if (test_part_get_parttype_0_skip ()) {
    skipped ("test_part_get_parttype_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for part_get_parttype (0) */
  const char *_arg1001 = "/dev/sda";
  const char *_arg1002 = "gpt";
  int _ret1000;
  _ret1000 = guestfs_part_disk (g, _arg1001, _arg1002);
  if (_ret1000 == -1)
    return -1;
  const char *_arg1004 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_parttype (g, _arg1004);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "gpt")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_part_get_parttype_0", "part_get_parttype", ret, "gpt");
    return -1;
  }
  return 0;
}

static int
test_part_set_name_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_set_name") == NULL;
  str = getenv ("SKIP_TEST_PART_SET_NAME_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_SET_NAME");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_set_name_0 (guestfs_h *g)
{
  if (test_part_set_name_0_skip ()) {
    skipped ("test_part_set_name_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for part_set_name (0) */
  const char *_arg1007 = "/dev/sda";
  const char *_arg1008 = "gpt";
  int _ret1006;
  _ret1006 = guestfs_part_disk (g, _arg1007, _arg1008);
  if (_ret1006 == -1)
    return -1;
  const char *_arg1011 = "/dev/sda";
  const char *_arg1013 = "thepartname";
  int _ret1010;
  _ret1010 = guestfs_part_set_name (g, _arg1011, 1, _arg1013);
  if (_ret1010 == -1)
    return -1;
  return 0;
}

static int
test_part_set_bootable_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_set_bootable") == NULL;
  str = getenv ("SKIP_TEST_PART_SET_BOOTABLE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_SET_BOOTABLE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_set_bootable_0 (guestfs_h *g)
{
  if (test_part_set_bootable_0_skip ()) {
    skipped ("test_part_set_bootable_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for part_set_bootable (0) */
  const char *_arg1016 = "/dev/sda";
  const char *_arg1017 = "mbr";
  int _ret1015;
  _ret1015 = guestfs_part_disk (g, _arg1016, _arg1017);
  if (_ret1015 == -1)
    return -1;
  const char *_arg1020 = "/dev/sda";
  int _ret1019;
  _ret1019 = guestfs_part_set_bootable (g, _arg1020, 1, 1);
  if (_ret1019 == -1)
    return -1;
  return 0;
}

static int
test_part_disk_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_disk") == NULL;
  str = getenv ("SKIP_TEST_PART_DISK_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_DISK");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_disk_0 (guestfs_h *g)
{
  if (test_part_disk_0_skip ()) {
    skipped ("test_part_disk_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for part_disk (0) */
  const char *_arg1025 = "/dev/sda";
  const char *_arg1026 = "mbr";
  int _ret1024;
  _ret1024 = guestfs_part_disk (g, _arg1025, _arg1026);
  if (_ret1024 == -1)
    return -1;
  return 0;
}

static int
test_part_disk_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_disk") == NULL;
  str = getenv ("SKIP_TEST_PART_DISK_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_DISK");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_disk_1 (guestfs_h *g)
{
  if (test_part_disk_1_skip ()) {
    skipped ("test_part_disk_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for part_disk (1) */
  const char *_arg1029 = "/dev/sda";
  const char *_arg1030 = "gpt";
  int _ret1028;
  _ret1028 = guestfs_part_disk (g, _arg1029, _arg1030);
  if (_ret1028 == -1)
    return -1;
  return 0;
}

static int
test_part_add_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_add") == NULL;
  str = getenv ("SKIP_TEST_PART_ADD_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_ADD");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_add_0 (guestfs_h *g)
{
  if (test_part_add_0_skip ()) {
    skipped ("test_part_add_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for part_add (0) */
  const char *_arg1033 = "/dev/sda";
  const char *_arg1034 = "mbr";
  int _ret1032;
  _ret1032 = guestfs_part_init (g, _arg1033, _arg1034);
  if (_ret1032 == -1)
    return -1;
  const char *_arg1037 = "/dev/sda";
  const char *_arg1038 = "primary";
  int _ret1036;
  _ret1036 = guestfs_part_add (g, _arg1037, _arg1038, 1, -1);
  if (_ret1036 == -1)
    return -1;
  return 0;
}

static int
test_part_add_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_add") == NULL;
  str = getenv ("SKIP_TEST_PART_ADD_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_ADD");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_add_1 (guestfs_h *g)
{
  if (test_part_add_1_skip ()) {
    skipped ("test_part_add_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for part_add (1) */
  const char *_arg1043 = "/dev/sda";
  const char *_arg1044 = "gpt";
  int _ret1042;
  _ret1042 = guestfs_part_init (g, _arg1043, _arg1044);
  if (_ret1042 == -1)
    return -1;
  const char *_arg1047 = "/dev/sda";
  const char *_arg1048 = "primary";
  int _ret1046;
  _ret1046 = guestfs_part_add (g, _arg1047, _arg1048, 34, 127);
  if (_ret1046 == -1)
    return -1;
  const char *_arg1053 = "/dev/sda";
  const char *_arg1054 = "primary";
  int _ret1052;
  _ret1052 = guestfs_part_add (g, _arg1053, _arg1054, 128, -34);
  if (_ret1052 == -1)
    return -1;
  return 0;
}

static int
test_part_add_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_add") == NULL;
  str = getenv ("SKIP_TEST_PART_ADD_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_ADD");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_add_2 (guestfs_h *g)
{
  if (test_part_add_2_skip ()) {
    skipped ("test_part_add_2", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for part_add (2) */
  const char *_arg1059 = "/dev/sda";
  const char *_arg1060 = "mbr";
  int _ret1058;
  _ret1058 = guestfs_part_init (g, _arg1059, _arg1060);
  if (_ret1058 == -1)
    return -1;
  const char *_arg1063 = "/dev/sda";
  const char *_arg1064 = "primary";
  int _ret1062;
  _ret1062 = guestfs_part_add (g, _arg1063, _arg1064, 32, 127);
  if (_ret1062 == -1)
    return -1;
  const char *_arg1069 = "/dev/sda";
  const char *_arg1070 = "primary";
  int _ret1068;
  _ret1068 = guestfs_part_add (g, _arg1069, _arg1070, 128, 255);
  if (_ret1068 == -1)
    return -1;
  const char *_arg1075 = "/dev/sda";
  const char *_arg1076 = "primary";
  int _ret1074;
  _ret1074 = guestfs_part_add (g, _arg1075, _arg1076, 256, 511);
  if (_ret1074 == -1)
    return -1;
  const char *_arg1081 = "/dev/sda";
  const char *_arg1082 = "primary";
  int _ret1080;
  _ret1080 = guestfs_part_add (g, _arg1081, _arg1082, 512, -1);
  if (_ret1080 == -1)
    return -1;
  return 0;
}

static int
test_part_init_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_init") == NULL;
  str = getenv ("SKIP_TEST_PART_INIT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_INIT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_init_0 (guestfs_h *g)
{
  if (test_part_init_0_skip ()) {
    skipped ("test_part_init_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for part_init (0) */
  const char *_arg1087 = "/dev/sda";
  const char *_arg1088 = "gpt";
  int _ret1086;
  _ret1086 = guestfs_part_init (g, _arg1087, _arg1088);
  if (_ret1086 == -1)
    return -1;
  return 0;
}

static int
test_pread_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pread") == NULL;
  str = getenv ("SKIP_TEST_PREAD_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PREAD");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pread_0 (guestfs_h *g)
{
  if (test_pread_0_skip ()) {
    skipped ("test_pread_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for pread (0) */
  const char *_arg1090 = "/known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread (g, _arg1090, 1, 3, &size);
  if (ret == NULL)
      return -1;
  if (! (compare_buffers (ret, size, "\n", 1) == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_pread_0", "compare_buffers (ret, size, \"\\n\", 1) == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_pread_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pread") == NULL;
  str = getenv ("SKIP_TEST_PREAD_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PREAD");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pread_1 (guestfs_h *g)
{
  if (test_pread_1_skip ()) {
    skipped ("test_pread_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for pread (1) */
  const char *_arg1094 = "/empty";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread (g, _arg1094, 0, 100, &size);
  if (ret == NULL)
      return -1;
  if (! (compare_buffers (ret, size, NULL, 0) == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_pread_1", "compare_buffers (ret, size, NULL, 0) == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_mkdir_mode_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkdir_mode") == NULL;
  str = getenv ("SKIP_TEST_MKDIR_MODE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKDIR_MODE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkdir_mode_0 (guestfs_h *g)
{
  if (test_mkdir_mode_0_skip ()) {
    skipped ("test_mkdir_mode_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mkdir_mode (0) */
  const char *_arg1098 = "/mkdir_mode";
  int ret1;
  ret1 = guestfs_mkdir_mode (g, _arg1098, 73);
  if (ret1 == -1)
    return -1;
  const char *_arg1101 = "/mkdir_mode";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1101);
  if (ret == NULL)
      return -1;
  if (! (S_ISDIR (ret->mode) && (ret->mode & 0777) == 0111)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_mkdir_mode_0", "S_ISDIR (ret->mode) && (ret->mode & 0777) == 0111");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_utimens_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "utimens") == NULL;
  str = getenv ("SKIP_TEST_UTIMENS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UTIMENS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_utimens_0 (guestfs_h *g)
{
  if (test_utimens_0_skip ()) {
    skipped ("test_utimens_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for utimens (0) */
  const char *_arg1103 = "/utimens-file";
  int ret2;
  ret2 = guestfs_touch (g, _arg1103);
  if (ret2 == -1)
    return -1;
  const char *_arg1105 = "/utimens-file";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1105, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1111 = "/utimens-file";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1111);
  if (ret == NULL)
      return -1;
  if (! (ret->mtime == 9876)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_utimens_0", "ret->mtime == 9876");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_utimens_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "utimens") == NULL;
  str = getenv ("SKIP_TEST_UTIMENS_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UTIMENS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_utimens_1 (guestfs_h *g)
{
  if (test_utimens_1_skip ()) {
    skipped ("test_utimens_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for utimens (1) */
  const char *_arg1113 = "/utimens-dir";
  int ret2;
  ret2 = guestfs_mkdir (g, _arg1113);
  if (ret2 == -1)
    return -1;
  const char *_arg1115 = "/utimens-dir";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1115, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1121 = "/utimens-dir";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1121);
  if (ret == NULL)
      return -1;
  if (! (ret->mtime == 9876)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_utimens_1", "ret->mtime == 9876");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_utimens_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "utimens") == NULL;
  str = getenv ("SKIP_TEST_UTIMENS_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UTIMENS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_utimens_2 (guestfs_h *g)
{
  if (test_utimens_2_skip ()) {
    skipped ("test_utimens_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for utimens (2) */
  const char *_arg1124 = "/utimens-fifo";
  int ret2;
  ret2 = guestfs_mkfifo (g, 420, _arg1124);
  if (ret2 == -1)
    return -1;
  const char *_arg1126 = "/utimens-fifo";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1126, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1132 = "/utimens-fifo";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1132);
  if (ret == NULL)
      return -1;
  if (! (ret->mtime == 9876)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_utimens_2", "ret->mtime == 9876");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_utimens_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "utimens") == NULL;
  str = getenv ("SKIP_TEST_UTIMENS_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UTIMENS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_utimens_3 (guestfs_h *g)
{
  if (test_utimens_3_skip ()) {
    skipped ("test_utimens_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for utimens (3) */
  const char *_arg1134 = "/utimens-file";
  const char *_arg1135 = "/utimens-link";
  int ret2;
  ret2 = guestfs_ln_sf (g, _arg1134, _arg1135);
  if (ret2 == -1)
    return -1;
  const char *_arg1137 = "/utimens-link";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1137, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1143 = "/utimens-link";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1143);
  if (ret == NULL)
      return -1;
  if (! (ret->mtime == 9876)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_utimens_3", "ret->mtime == 9876");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_utimens_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "utimens") == NULL;
  str = getenv ("SKIP_TEST_UTIMENS_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UTIMENS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_utimens_4 (guestfs_h *g)
{
  if (test_utimens_4_skip ()) {
    skipped ("test_utimens_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for utimens (4) */
  const char *_arg1148 = "/utimens-block";
  int ret2;
  ret2 = guestfs_mknod_b (g, 420, 8, 0, _arg1148);
  if (ret2 == -1)
    return -1;
  const char *_arg1150 = "/utimens-block";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1150, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1156 = "/utimens-block";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1156);
  if (ret == NULL)
      return -1;
  if (! (ret->mtime == 9876)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_utimens_4", "ret->mtime == 9876");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_utimens_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "utimens") == NULL;
  str = getenv ("SKIP_TEST_UTIMENS_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UTIMENS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_utimens_5 (guestfs_h *g)
{
  if (test_utimens_5_skip ()) {
    skipped ("test_utimens_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for utimens (5) */
  const char *_arg1161 = "/utimens-char";
  int ret2;
  ret2 = guestfs_mknod_c (g, 420, 1, 3, _arg1161);
  if (ret2 == -1)
    return -1;
  const char *_arg1163 = "/utimens-char";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1163, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1169 = "/utimens-char";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1169);
  if (ret == NULL)
      return -1;
  if (! (ret->mtime == 9876)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_utimens_5", "ret->mtime == 9876");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_truncate_size_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "truncate_size") == NULL;
  str = getenv ("SKIP_TEST_TRUNCATE_SIZE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TRUNCATE_SIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_truncate_size_0 (guestfs_h *g)
{
  if (test_truncate_size_0_skip ()) {
    skipped ("test_truncate_size_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for truncate_size (0) */
  const char *_arg1171 = "/truncate_size";
  int ret2;
  ret2 = guestfs_touch (g, _arg1171);
  if (ret2 == -1)
    return -1;
  const char *_arg1173 = "/truncate_size";
  int ret1;
  ret1 = guestfs_truncate_size (g, _arg1173, 1000);
  if (ret1 == -1)
    return -1;
  const char *_arg1176 = "/truncate_size";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1176);
  if (ret == NULL)
      return -1;
  if (! (ret->size == 1000)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_truncate_size_0", "ret->size == 1000");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_truncate_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "truncate") == NULL;
  str = getenv ("SKIP_TEST_TRUNCATE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TRUNCATE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_truncate_0 (guestfs_h *g)
{
  if (test_truncate_0_skip ()) {
    skipped ("test_truncate_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for truncate (0) */
  const char *_arg1178 = "/truncate";
  const char *_arg1179 = "some stuff so size is not zero";
  size_t _arg1179_size = 30;
  int ret2;
  ret2 = guestfs_write (g, _arg1178, _arg1179, _arg1179_size);
  if (ret2 == -1)
    return -1;
  const char *_arg1181 = "/truncate";
  int ret1;
  ret1 = guestfs_truncate (g, _arg1181);
  if (ret1 == -1)
    return -1;
  const char *_arg1183 = "/truncate";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1183);
  if (ret == NULL)
      return -1;
  if (! (ret->size == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_truncate_0", "ret->size == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_vfs_type_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vfs_type") == NULL;
  str = getenv ("SKIP_TEST_VFS_TYPE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VFS_TYPE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vfs_type_0 (guestfs_h *g)
{
  if (test_vfs_type_0_skip ()) {
    skipped ("test_vfs_type_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for vfs_type (0) */
  const char *_arg1185 = "/dev/sdb1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_type (g, _arg1185);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "ext2")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_vfs_type_0", "vfs_type", ret, "ext2");
    return -1;
  }
  return 0;
}

static int
test_case_sensitive_path_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "case_sensitive_path") == NULL;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_case_sensitive_path_0 (guestfs_h *g)
{
  if (test_case_sensitive_path_0_skip ()) {
    skipped ("test_case_sensitive_path_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for case_sensitive_path (0) */
  const char *_arg1187 = "/DIRECTORY";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1187);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/directory")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_case_sensitive_path_0", "case_sensitive_path", ret, "/directory");
    return -1;
  }
  return 0;
}

static int
test_case_sensitive_path_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "case_sensitive_path") == NULL;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_case_sensitive_path_1 (guestfs_h *g)
{
  if (test_case_sensitive_path_1_skip ()) {
    skipped ("test_case_sensitive_path_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for case_sensitive_path (1) */
  const char *_arg1189 = "/DIRECTORY/";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1189);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/directory")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_case_sensitive_path_1", "case_sensitive_path", ret, "/directory");
    return -1;
  }
  return 0;
}

static int
test_case_sensitive_path_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "case_sensitive_path") == NULL;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_case_sensitive_path_2 (guestfs_h *g)
{
  if (test_case_sensitive_path_2_skip ()) {
    skipped ("test_case_sensitive_path_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for case_sensitive_path (2) */
  const char *_arg1191 = "/Known-1";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1191);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/known-1")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_case_sensitive_path_2", "case_sensitive_path", ret, "/known-1");
    return -1;
  }
  return 0;
}

static int
test_case_sensitive_path_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "case_sensitive_path") == NULL;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_case_sensitive_path_3 (guestfs_h *g)
{
  if (test_case_sensitive_path_3_skip ()) {
    skipped ("test_case_sensitive_path_3", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestLastFail for case_sensitive_path (3) */
  const char *_arg1194 = "/Known-1/";
  CLEANUP_FREE char *_ret1193;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1193 = guestfs_case_sensitive_path (g, _arg1194);
  guestfs_pop_error_handler (g);
  if (_ret1193 != NULL)
    return -1;
  return 0;
}

static int
test_case_sensitive_path_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "case_sensitive_path") == NULL;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_case_sensitive_path_4 (guestfs_h *g)
{
  if (test_case_sensitive_path_4_skip ()) {
    skipped ("test_case_sensitive_path_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for case_sensitive_path (4) */
  const char *_arg1197 = "/case_sensitive_path";
  int _ret1196;
  _ret1196 = guestfs_mkdir (g, _arg1197);
  if (_ret1196 == -1)
    return -1;
  const char *_arg1200 = "/case_sensitive_path/bbb";
  int _ret1199;
  _ret1199 = guestfs_mkdir (g, _arg1200);
  if (_ret1199 == -1)
    return -1;
  const char *_arg1203 = "/case_sensitive_path/bbb/c";
  int _ret1202;
  _ret1202 = guestfs_touch (g, _arg1203);
  if (_ret1202 == -1)
    return -1;
  const char *_arg1205 = "/CASE_SENSITIVE_path/bbB/C";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1205);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/case_sensitive_path/bbb/c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_case_sensitive_path_4", "case_sensitive_path", ret, "/case_sensitive_path/bbb/c");
    return -1;
  }
  return 0;
}

static int
test_case_sensitive_path_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "case_sensitive_path") == NULL;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_case_sensitive_path_5 (guestfs_h *g)
{
  if (test_case_sensitive_path_5_skip ()) {
    skipped ("test_case_sensitive_path_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for case_sensitive_path (5) */
  const char *_arg1208 = "/case_sensitive_path2";
  int _ret1207;
  _ret1207 = guestfs_mkdir (g, _arg1208);
  if (_ret1207 == -1)
    return -1;
  const char *_arg1211 = "/case_sensitive_path2/bbb";
  int _ret1210;
  _ret1210 = guestfs_mkdir (g, _arg1211);
  if (_ret1210 == -1)
    return -1;
  const char *_arg1214 = "/case_sensitive_path2/bbb/c";
  int _ret1213;
  _ret1213 = guestfs_touch (g, _arg1214);
  if (_ret1213 == -1)
    return -1;
  const char *_arg1216 = "/case_sensitive_PATH2////bbB/C";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1216);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/case_sensitive_path2/bbb/c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_case_sensitive_path_5", "case_sensitive_path", ret, "/case_sensitive_path2/bbb/c");
    return -1;
  }
  return 0;
}

static int
test_case_sensitive_path_6_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "case_sensitive_path") == NULL;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH_6");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_case_sensitive_path_6 (guestfs_h *g)
{
  if (test_case_sensitive_path_6_skip ()) {
    skipped ("test_case_sensitive_path_6", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for case_sensitive_path (6) */
  const char *_arg1219 = "/case_sensitive_path3";
  int _ret1218;
  _ret1218 = guestfs_mkdir (g, _arg1219);
  if (_ret1218 == -1)
    return -1;
  const char *_arg1222 = "/case_sensitive_path3/bbb";
  int _ret1221;
  _ret1221 = guestfs_mkdir (g, _arg1222);
  if (_ret1221 == -1)
    return -1;
  const char *_arg1225 = "/case_sensitive_path3/bbb/c";
  int _ret1224;
  _ret1224 = guestfs_touch (g, _arg1225);
  if (_ret1224 == -1)
    return -1;
  const char *_arg1228 = "/case_SENSITIVE_path3/bbb/../bbb/C";
  CLEANUP_FREE char *_ret1227;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1227 = guestfs_case_sensitive_path (g, _arg1228);
  guestfs_pop_error_handler (g);
  if (_ret1227 != NULL)
    return -1;
  return 0;
}

static int
test_case_sensitive_path_7_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "case_sensitive_path") == NULL;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH_7");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CASE_SENSITIVE_PATH");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_case_sensitive_path_7 (guestfs_h *g)
{
  if (test_case_sensitive_path_7_skip ()) {
    skipped ("test_case_sensitive_path_7", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for case_sensitive_path (7) */
  const char *_arg1231 = "/case_sensitive_path4";
  int _ret1230;
  _ret1230 = guestfs_mkdir (g, _arg1231);
  if (_ret1230 == -1)
    return -1;
  const char *_arg1233 = "/case_SENSITIVE_path4/new_file";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1233);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/case_sensitive_path4/new_file")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_case_sensitive_path_7", "case_sensitive_path", ret, "/case_sensitive_path4/new_file");
    return -1;
  }
  return 0;
}

static int
test_echo_daemon_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "echo_daemon") == NULL;
  str = getenv ("SKIP_TEST_ECHO_DAEMON_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ECHO_DAEMON");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_echo_daemon_0 (guestfs_h *g)
{
  if (test_echo_daemon_0_skip ()) {
    skipped ("test_echo_daemon_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultString for echo_daemon (0) */
  const char *_arg1235_0 = "This";
  const char *_arg1235_1 = "is";
  const char *_arg1235_2 = "a";
  const char *_arg1235_3 = "test";
  const char *const _arg1235[] = {
    _arg1235_0,
    _arg1235_1,
    _arg1235_2,
    _arg1235_3,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_echo_daemon (g, (char **) _arg1235);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "This is a test")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_echo_daemon_0", "echo_daemon", ret, "This is a test");
    return -1;
  }
  return 0;
}

static int
test_modprobe_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "modprobe") == NULL;
  str = getenv ("SKIP_TEST_MODPROBE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MODPROBE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_modprobe_0 (guestfs_h *g)
{
  if (test_modprobe_0_skip ()) {
    skipped ("test_modprobe_0", "environment variable set");
    return 0;
  }

  const char *_features1237[] = { "linuxmodules", NULL };
  if (!guestfs_feature_available (g, (char **) _features1237)) {
    skipped ("test_modprobe_0", "group %s not available in daemon",
             _features1237[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for modprobe (0) */
  const char *_arg1239 = "fat";
  int _ret1238;
  _ret1238 = guestfs_modprobe (g, _arg1239);
  if (_ret1238 == -1)
    return -1;
  return 0;
}

static int
test_mke2journal_U_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mke2journal_U") == NULL;
  str = getenv ("SKIP_TEST_MKE2JOURNAL_U_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKE2JOURNAL_U");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mke2journal_U_0 (guestfs_h *g)
{
  if (test_mke2journal_U_0_skip ()) {
    skipped ("test_mke2journal_U_0", "environment variable set");
    return 0;
  }

  const char *_features1241[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1241)) {
    skipped ("test_mke2journal_U_0", "group %s not available in daemon",
             _features1241[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for mke2journal_U (0) */
  const char *_arg1243 = "/dev/sda";
  const char *_arg1244 = "mbr";
  int _ret1242;
  _ret1242 = guestfs_part_init (g, _arg1243, _arg1244);
  if (_ret1242 == -1)
    return -1;
  const char *_arg1247 = "/dev/sda";
  const char *_arg1248 = "p";
  int _ret1246;
  _ret1246 = guestfs_part_add (g, _arg1247, _arg1248, 64, 204799);
  if (_ret1246 == -1)
    return -1;
  const char *_arg1253 = "/dev/sda";
  const char *_arg1254 = "p";
  int _ret1252;
  _ret1252 = guestfs_part_add (g, _arg1253, _arg1254, 204800, -64);
  if (_ret1252 == -1)
    return -1;
  const char *_arg1260 = "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b";
  const char *_arg1261 = "/dev/sda1";
  int _ret1258;
  _ret1258 = guestfs_mke2journal_U (g, 4096, _arg1260, _arg1261);
  if (_ret1258 == -1)
    return -1;
  const char *_arg1264 = "ext2";
  const char *_arg1266 = "/dev/sda2";
  const char *_arg1267 = "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b";
  int _ret1263;
  _ret1263 = guestfs_mke2fs_JU (g, _arg1264, 4096, _arg1266, _arg1267);
  if (_ret1263 == -1)
    return -1;
  const char *_arg1270 = "/dev/sda2";
  const char *_arg1271 = "/";
  int _ret1269;
  _ret1269 = guestfs_mount (g, _arg1270, _arg1271);
  if (_ret1269 == -1)
    return -1;
  const char *_arg1274 = "/new";
  const char *_arg1275 = "new file contents";
  size_t _arg1275_size = 17;
  int _ret1273;
  _ret1273 = guestfs_write (g, _arg1274, _arg1275, _arg1275_size);
  if (_ret1273 == -1)
    return -1;
  const char *_arg1277 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1277);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mke2journal_U_0", "cat", ret, "new file contents");
    return -1;
  }
  return 0;
}

static int
test_mke2journal_L_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mke2journal_L") == NULL;
  str = getenv ("SKIP_TEST_MKE2JOURNAL_L_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKE2JOURNAL_L");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mke2journal_L_0 (guestfs_h *g)
{
  if (test_mke2journal_L_0_skip ()) {
    skipped ("test_mke2journal_L_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for mke2journal_L (0) */
  const char *_arg1280 = "/dev/sda";
  const char *_arg1281 = "mbr";
  int _ret1279;
  _ret1279 = guestfs_part_init (g, _arg1280, _arg1281);
  if (_ret1279 == -1)
    return -1;
  const char *_arg1284 = "/dev/sda";
  const char *_arg1285 = "p";
  int _ret1283;
  _ret1283 = guestfs_part_add (g, _arg1284, _arg1285, 64, 204799);
  if (_ret1283 == -1)
    return -1;
  const char *_arg1290 = "/dev/sda";
  const char *_arg1291 = "p";
  int _ret1289;
  _ret1289 = guestfs_part_add (g, _arg1290, _arg1291, 204800, -64);
  if (_ret1289 == -1)
    return -1;
  const char *_arg1297 = "JOURNAL";
  const char *_arg1298 = "/dev/sda1";
  int _ret1295;
  _ret1295 = guestfs_mke2journal_L (g, 4096, _arg1297, _arg1298);
  if (_ret1295 == -1)
    return -1;
  const char *_arg1301 = "ext2";
  const char *_arg1303 = "/dev/sda2";
  const char *_arg1304 = "JOURNAL";
  int _ret1300;
  _ret1300 = guestfs_mke2fs_JL (g, _arg1301, 4096, _arg1303, _arg1304);
  if (_ret1300 == -1)
    return -1;
  const char *_arg1307 = "/dev/sda2";
  const char *_arg1308 = "/";
  int _ret1306;
  _ret1306 = guestfs_mount (g, _arg1307, _arg1308);
  if (_ret1306 == -1)
    return -1;
  const char *_arg1311 = "/new";
  const char *_arg1312 = "new file contents";
  size_t _arg1312_size = 17;
  int _ret1310;
  _ret1310 = guestfs_write (g, _arg1311, _arg1312, _arg1312_size);
  if (_ret1310 == -1)
    return -1;
  const char *_arg1314 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1314);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mke2journal_L_0", "cat", ret, "new file contents");
    return -1;
  }
  return 0;
}

static int
test_mke2journal_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mke2journal") == NULL;
  str = getenv ("SKIP_TEST_MKE2JOURNAL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKE2JOURNAL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mke2journal_0 (guestfs_h *g)
{
  if (test_mke2journal_0_skip ()) {
    skipped ("test_mke2journal_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for mke2journal (0) */
  const char *_arg1317 = "/dev/sda";
  const char *_arg1318 = "mbr";
  int _ret1316;
  _ret1316 = guestfs_part_init (g, _arg1317, _arg1318);
  if (_ret1316 == -1)
    return -1;
  const char *_arg1321 = "/dev/sda";
  const char *_arg1322 = "p";
  int _ret1320;
  _ret1320 = guestfs_part_add (g, _arg1321, _arg1322, 64, 204799);
  if (_ret1320 == -1)
    return -1;
  const char *_arg1327 = "/dev/sda";
  const char *_arg1328 = "p";
  int _ret1326;
  _ret1326 = guestfs_part_add (g, _arg1327, _arg1328, 204800, -64);
  if (_ret1326 == -1)
    return -1;
  const char *_arg1334 = "/dev/sda1";
  int _ret1332;
  _ret1332 = guestfs_mke2journal (g, 4096, _arg1334);
  if (_ret1332 == -1)
    return -1;
  const char *_arg1337 = "ext2";
  const char *_arg1339 = "/dev/sda2";
  const char *_arg1340 = "/dev/sda1";
  int _ret1336;
  _ret1336 = guestfs_mke2fs_J (g, _arg1337, 4096, _arg1339, _arg1340);
  if (_ret1336 == -1)
    return -1;
  const char *_arg1343 = "/dev/sda2";
  const char *_arg1344 = "/";
  int _ret1342;
  _ret1342 = guestfs_mount (g, _arg1343, _arg1344);
  if (_ret1342 == -1)
    return -1;
  const char *_arg1347 = "/new";
  const char *_arg1348 = "new file contents";
  size_t _arg1348_size = 17;
  int _ret1346;
  _ret1346 = guestfs_write (g, _arg1347, _arg1348, _arg1348_size);
  if (_ret1346 == -1)
    return -1;
  const char *_arg1350 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1350);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mke2journal_0", "cat", ret, "new file contents");
    return -1;
  }
  return 0;
}

static int
test_mkfs_b_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkfs_b") == NULL;
  str = getenv ("SKIP_TEST_MKFS_B_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKFS_B");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkfs_b_0 (guestfs_h *g)
{
  if (test_mkfs_b_0_skip ()) {
    skipped ("test_mkfs_b_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for mkfs_b (0) */
  const char *_arg1353 = "/dev/sda";
  const char *_arg1354 = "mbr";
  int _ret1352;
  _ret1352 = guestfs_part_disk (g, _arg1353, _arg1354);
  if (_ret1352 == -1)
    return -1;
  const char *_arg1357 = "ext2";
  const char *_arg1359 = "/dev/sda1";
  int _ret1356;
  _ret1356 = guestfs_mkfs_b (g, _arg1357, 4096, _arg1359);
  if (_ret1356 == -1)
    return -1;
  const char *_arg1362 = "/dev/sda1";
  const char *_arg1363 = "/";
  int _ret1361;
  _ret1361 = guestfs_mount (g, _arg1362, _arg1363);
  if (_ret1361 == -1)
    return -1;
  const char *_arg1366 = "/new";
  const char *_arg1367 = "new file contents";
  size_t _arg1367_size = 17;
  int _ret1365;
  _ret1365 = guestfs_write (g, _arg1366, _arg1367, _arg1367_size);
  if (_ret1365 == -1)
    return -1;
  const char *_arg1369 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1369);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mkfs_b_0", "cat", ret, "new file contents");
    return -1;
  }
  return 0;
}

static int
test_mkfs_b_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkfs_b") == NULL;
  str = getenv ("SKIP_TEST_MKFS_B_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKFS_B");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkfs_b_1 (guestfs_h *g)
{
  if (test_mkfs_b_1_skip ()) {
    skipped ("test_mkfs_b_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkfs_b (1) */
  const char *_arg1372 = "/dev/sda";
  const char *_arg1373 = "mbr";
  int _ret1371;
  _ret1371 = guestfs_part_disk (g, _arg1372, _arg1373);
  if (_ret1371 == -1)
    return -1;
  const char *_arg1376 = "vfat";
  const char *_arg1378 = "/dev/sda1";
  int _ret1375;
  _ret1375 = guestfs_mkfs_b (g, _arg1376, 32768, _arg1378);
  if (_ret1375 == -1)
    return -1;
  return 0;
}

static int
test_mkfs_b_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkfs_b") == NULL;
  str = getenv ("SKIP_TEST_MKFS_B_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKFS_B");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkfs_b_2 (guestfs_h *g)
{
  if (test_mkfs_b_2_skip ()) {
    skipped ("test_mkfs_b_2", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestLastFail for mkfs_b (2) */
  const char *_arg1381 = "/dev/sda";
  const char *_arg1382 = "mbr";
  int _ret1380;
  _ret1380 = guestfs_part_disk (g, _arg1381, _arg1382);
  if (_ret1380 == -1)
    return -1;
  const char *_arg1385 = "vfat";
  const char *_arg1387 = "/dev/sda1";
  int _ret1384;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1384 = guestfs_mkfs_b (g, _arg1385, 32769, _arg1387);
  guestfs_pop_error_handler (g);
  if (_ret1384 != -1)
    return -1;
  return 0;
}

static int
test_mkfs_b_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkfs_b") == NULL;
  str = getenv ("SKIP_TEST_MKFS_B_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKFS_B");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkfs_b_3 (guestfs_h *g)
{
  if (test_mkfs_b_3_skip ()) {
    skipped ("test_mkfs_b_3", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestLastFail for mkfs_b (3) */
  const char *_arg1390 = "/dev/sda";
  const char *_arg1391 = "mbr";
  int _ret1389;
  _ret1389 = guestfs_part_disk (g, _arg1390, _arg1391);
  if (_ret1389 == -1)
    return -1;
  const char *_arg1394 = "vfat";
  const char *_arg1396 = "/dev/sda1";
  int _ret1393;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1393 = guestfs_mkfs_b (g, _arg1394, 33280, _arg1396);
  guestfs_pop_error_handler (g);
  if (_ret1393 != -1)
    return -1;
  return 0;
}

static int
test_mkfs_b_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkfs_b") == NULL;
  str = getenv ("SKIP_TEST_MKFS_B_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKFS_B");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkfs_b_4 (guestfs_h *g)
{
  if (test_mkfs_b_4_skip ()) {
    skipped ("test_mkfs_b_4", "environment variable set");
    return 0;
  }

  const char *_features1398[] = { "ntfsprogs", NULL };
  if (!guestfs_feature_available (g, (char **) _features1398)) {
    skipped ("test_mkfs_b_4", "group %s not available in daemon",
             _features1398[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkfs_b (4) */
  const char *_arg1400 = "/dev/sda";
  const char *_arg1401 = "mbr";
  int _ret1399;
  _ret1399 = guestfs_part_disk (g, _arg1400, _arg1401);
  if (_ret1399 == -1)
    return -1;
  const char *_arg1404 = "ntfs";
  const char *_arg1406 = "/dev/sda1";
  int _ret1403;
  _ret1403 = guestfs_mkfs_b (g, _arg1404, 32768, _arg1406);
  if (_ret1403 == -1)
    return -1;
  return 0;
}

static int
test_inotify_add_watch_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "inotify_add_watch") == NULL;
  str = getenv ("SKIP_TEST_INOTIFY_ADD_WATCH_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_INOTIFY_ADD_WATCH");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_inotify_add_watch_0 (guestfs_h *g)
{
  if (test_inotify_add_watch_0_skip ()) {
    skipped ("test_inotify_add_watch_0", "environment variable set");
    return 0;
  }

  const char *_features1408[] = { "inotify", NULL };
  if (!guestfs_feature_available (g, (char **) _features1408)) {
    skipped ("test_inotify_add_watch_0", "group %s not available in daemon",
             _features1408[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for inotify_add_watch (0) */
  const char *_arg1409 = "/inotify_add_watch";
  int ret5;
  ret5 = guestfs_mkdir (g, _arg1409);
  if (ret5 == -1)
    return -1;
  int ret4;
  ret4 = guestfs_inotify_init (g, 0);
  if (ret4 == -1)
    return -1;
  const char *_arg1413 = "/inotify_add_watch";
  int64_t ret3;
  ret3 = guestfs_inotify_add_watch (g, _arg1413, 1073741823);
  if (ret3 == -1)
    return -1;
  const char *_arg1416 = "/inotify_add_watch/a";
  int ret2;
  ret2 = guestfs_touch (g, _arg1416);
  if (ret2 == -1)
    return -1;
  const char *_arg1418 = "/inotify_add_watch/b";
  int ret1;
  ret1 = guestfs_touch (g, _arg1418);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_inotify_files (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "a", "b"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_inotify_add_watch_0", "is_string_list (ret, 2, \"a\", \"b\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_inotify_init_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "inotify_init") == NULL;
  str = getenv ("SKIP_TEST_INOTIFY_INIT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_INOTIFY_INIT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_inotify_init_0 (guestfs_h *g)
{
  if (test_inotify_init_0_skip ()) {
    skipped ("test_inotify_init_0", "environment variable set");
    return 0;
  }

  const char *_features1421[] = { "inotify", NULL };
  if (!guestfs_feature_available (g, (char **) _features1421)) {
    skipped ("test_inotify_init_0", "group %s not available in daemon",
             _features1421[0]);
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestRun for inotify_init (0) */
  int _ret1422;
  _ret1422 = guestfs_inotify_init (g, 0);
  if (_ret1422 == -1)
    return -1;
  return 0;
}

static int
test_mkswap_file_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkswap_file") == NULL;
  str = getenv ("SKIP_TEST_MKSWAP_FILE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKSWAP_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkswap_file_0 (guestfs_h *g)
{
  if (test_mkswap_file_0_skip ()) {
    skipped ("test_mkswap_file_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for mkswap_file (0) */
  const char *_arg1426 = "/mkswap_file";
  int _ret1425;
  _ret1425 = guestfs_fallocate (g, _arg1426, 8388608);
  if (_ret1425 == -1)
    return -1;
  const char *_arg1430 = "/mkswap_file";
  int _ret1429;
  _ret1429 = guestfs_mkswap_file (g, _arg1430);
  if (_ret1429 == -1)
    return -1;
  const char *_arg1433 = "/mkswap_file";
  int _ret1432;
  _ret1432 = guestfs_rm (g, _arg1433);
  if (_ret1432 == -1)
    return -1;
  return 0;
}

static int
test_swapon_uuid_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "swapon_uuid") == NULL;
  str = getenv ("SKIP_TEST_SWAPON_UUID_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SWAPON_UUID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_swapon_uuid_0 (guestfs_h *g)
{
  if (test_swapon_uuid_0_skip ()) {
    skipped ("test_swapon_uuid_0", "environment variable set");
    return 0;
  }

  const char *_features1435[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1435)) {
    skipped ("test_swapon_uuid_0", "group %s not available in daemon",
             _features1435[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for swapon_uuid (0) */
  const char *_arg1437 = "/dev/sdc";
  struct guestfs_mkswap_opts_argv _optargs1438;
  _optargs1438.uuid = "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b";
  _optargs1438.bitmask = UINT64_C(0x2);
  int _ret1436;
  _ret1436 = guestfs_mkswap_opts_argv (g, _arg1437, &_optargs1438);
  if (_ret1436 == -1)
    return -1;
  const char *_arg1440 = "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b";
  int _ret1439;
  _ret1439 = guestfs_swapon_uuid (g, _arg1440);
  if (_ret1439 == -1)
    return -1;
  const char *_arg1443 = "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b";
  int _ret1442;
  _ret1442 = guestfs_swapoff_uuid (g, _arg1443);
  if (_ret1442 == -1)
    return -1;
  return 0;
}

static int
test_swapon_label_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "swapon_label") == NULL;
  str = getenv ("SKIP_TEST_SWAPON_LABEL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SWAPON_LABEL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_swapon_label_0 (guestfs_h *g)
{
  if (test_swapon_label_0_skip ()) {
    skipped ("test_swapon_label_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for swapon_label (0) */
  const char *_arg1446 = "/dev/sda";
  const char *_arg1447 = "mbr";
  int _ret1445;
  _ret1445 = guestfs_part_disk (g, _arg1446, _arg1447);
  if (_ret1445 == -1)
    return -1;
  const char *_arg1450 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1451;
  _optargs1451.label = "swapit";
  _optargs1451.bitmask = UINT64_C(0x1);
  int _ret1449;
  _ret1449 = guestfs_mkswap_opts_argv (g, _arg1450, &_optargs1451);
  if (_ret1449 == -1)
    return -1;
  const char *_arg1453 = "swapit";
  int _ret1452;
  _ret1452 = guestfs_swapon_label (g, _arg1453);
  if (_ret1452 == -1)
    return -1;
  const char *_arg1456 = "swapit";
  int _ret1455;
  _ret1455 = guestfs_swapoff_label (g, _arg1456);
  if (_ret1455 == -1)
    return -1;
  const char *_arg1459 = "/dev/sda";
  int _ret1458;
  _ret1458 = guestfs_zero (g, _arg1459);
  if (_ret1458 == -1)
    return -1;
  const char *_arg1462 = "/dev/sda";
  int _ret1461;
  _ret1461 = guestfs_blockdev_rereadpt (g, _arg1462);
  if (_ret1461 == -1)
    return -1;
  return 0;
}

static int
test_swapon_file_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "swapon_file") == NULL;
  str = getenv ("SKIP_TEST_SWAPON_FILE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SWAPON_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_swapon_file_0 (guestfs_h *g)
{
  if (test_swapon_file_0_skip ()) {
    skipped ("test_swapon_file_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for swapon_file (0) */
  const char *_arg1465 = "/swapon_file";
  int _ret1464;
  _ret1464 = guestfs_fallocate (g, _arg1465, 8388608);
  if (_ret1464 == -1)
    return -1;
  const char *_arg1469 = "/swapon_file";
  int _ret1468;
  _ret1468 = guestfs_mkswap_file (g, _arg1469);
  if (_ret1468 == -1)
    return -1;
  const char *_arg1472 = "/swapon_file";
  int _ret1471;
  _ret1471 = guestfs_swapon_file (g, _arg1472);
  if (_ret1471 == -1)
    return -1;
  const char *_arg1475 = "/swapon_file";
  int _ret1474;
  _ret1474 = guestfs_swapoff_file (g, _arg1475);
  if (_ret1474 == -1)
    return -1;
  const char *_arg1478 = "/swapon_file";
  int _ret1477;
  _ret1477 = guestfs_rm (g, _arg1478);
  if (_ret1477 == -1)
    return -1;
  return 0;
}

static int
test_swapon_device_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "swapon_device") == NULL;
  str = getenv ("SKIP_TEST_SWAPON_DEVICE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SWAPON_DEVICE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_swapon_device_0 (guestfs_h *g)
{
  if (test_swapon_device_0_skip ()) {
    skipped ("test_swapon_device_0", "environment variable set");
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for swapon_device (0) */
  const char *_arg1481 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1482;
  _optargs1482.bitmask = UINT64_C(0x0);
  int _ret1480;
  _ret1480 = guestfs_mkswap_opts_argv (g, _arg1481, &_optargs1482);
  if (_ret1480 == -1)
    return -1;
  const char *_arg1484 = "/dev/sda1";
  int _ret1483;
  _ret1483 = guestfs_swapon_device (g, _arg1484);
  if (_ret1483 == -1)
    return -1;
  const char *_arg1487 = "/dev/sda1";
  int _ret1486;
  _ret1486 = guestfs_swapoff_device (g, _arg1487);
  if (_ret1486 == -1)
    return -1;
  return 0;
}

static int
test_fallocate_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "fallocate") == NULL;
  str = getenv ("SKIP_TEST_FALLOCATE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FALLOCATE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_fallocate_0 (guestfs_h *g)
{
  if (test_fallocate_0_skip ()) {
    skipped ("test_fallocate_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for fallocate (0) */
  const char *_arg1489 = "/fallocate";
  int ret1;
  ret1 = guestfs_fallocate (g, _arg1489, 1000000);
  if (ret1 == -1)
    return -1;
  const char *_arg1492 = "/fallocate";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1492);
  if (ret == NULL)
      return -1;
  if (! (ret->size == 1000000)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_fallocate_0", "ret->size == 1000000");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_ln_sf_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "ln_sf") == NULL;
  str = getenv ("SKIP_TEST_LN_SF_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LN_SF");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_ln_sf_0 (guestfs_h *g)
{
  if (test_ln_sf_0_skip ()) {
    skipped ("test_ln_sf_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for ln_sf (0) */
  const char *_arg1495 = "/ln_sf/b";
  int _ret1494;
  _ret1494 = guestfs_mkdir_p (g, _arg1495);
  if (_ret1494 == -1)
    return -1;
  const char *_arg1498 = "/ln_sf/b/c";
  int _ret1497;
  _ret1497 = guestfs_touch (g, _arg1498);
  if (_ret1497 == -1)
    return -1;
  const char *_arg1501 = "../d";
  const char *_arg1502 = "/ln_sf/b/c";
  int _ret1500;
  _ret1500 = guestfs_ln_sf (g, _arg1501, _arg1502);
  if (_ret1500 == -1)
    return -1;
  const char *_arg1504 = "/ln_sf/b/c";
  CLEANUP_FREE char *ret;
  ret = guestfs_readlink (g, _arg1504);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "../d")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_ln_sf_0", "readlink", ret, "../d");
    return -1;
  }
  return 0;
}

static int
test_ln_s_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "ln_s") == NULL;
  str = getenv ("SKIP_TEST_LN_S_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LN_S");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_ln_s_0 (guestfs_h *g)
{
  if (test_ln_s_0_skip ()) {
    skipped ("test_ln_s_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for ln_s (0) */
  const char *_arg1506 = "/ln_s";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg1506);
  if (ret3 == -1)
    return -1;
  const char *_arg1508 = "/ln_s/a";
  int ret2;
  ret2 = guestfs_touch (g, _arg1508);
  if (ret2 == -1)
    return -1;
  const char *_arg1510 = "a";
  const char *_arg1511 = "/ln_s/b";
  int ret1;
  ret1 = guestfs_ln_s (g, _arg1510, _arg1511);
  if (ret1 == -1)
    return -1;
  const char *_arg1513 = "/ln_s/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_lstat (g, _arg1513);
  if (ret == NULL)
      return -1;
  if (! (S_ISLNK (ret->mode) && (ret->mode & 0777) == 0777)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_ln_s_0", "S_ISLNK (ret->mode) && (ret->mode & 0777) == 0777");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_ln_f_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "ln_f") == NULL;
  str = getenv ("SKIP_TEST_LN_F_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LN_F");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_ln_f_0 (guestfs_h *g)
{
  if (test_ln_f_0_skip ()) {
    skipped ("test_ln_f_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for ln_f (0) */
  const char *_arg1515 = "/ln_f";
  int ret4;
  ret4 = guestfs_mkdir (g, _arg1515);
  if (ret4 == -1)
    return -1;
  const char *_arg1517 = "/ln_f/a";
  int ret3;
  ret3 = guestfs_touch (g, _arg1517);
  if (ret3 == -1)
    return -1;
  const char *_arg1519 = "/ln_f/b";
  int ret2;
  ret2 = guestfs_touch (g, _arg1519);
  if (ret2 == -1)
    return -1;
  const char *_arg1521 = "/ln_f/a";
  const char *_arg1522 = "/ln_f/b";
  int ret1;
  ret1 = guestfs_ln_f (g, _arg1521, _arg1522);
  if (ret1 == -1)
    return -1;
  const char *_arg1524 = "/ln_f/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1524);
  if (ret == NULL)
      return -1;
  if (! (ret->nlink == 2)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_ln_f_0", "ret->nlink == 2");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_ln_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "ln") == NULL;
  str = getenv ("SKIP_TEST_LN_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_ln_0 (guestfs_h *g)
{
  if (test_ln_0_skip ()) {
    skipped ("test_ln_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for ln (0) */
  const char *_arg1526 = "/ln";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg1526);
  if (ret3 == -1)
    return -1;
  const char *_arg1528 = "/ln/a";
  int ret2;
  ret2 = guestfs_touch (g, _arg1528);
  if (ret2 == -1)
    return -1;
  const char *_arg1530 = "/ln/a";
  const char *_arg1531 = "/ln/b";
  int ret1;
  ret1 = guestfs_ln (g, _arg1530, _arg1531);
  if (ret1 == -1)
    return -1;
  const char *_arg1533 = "/ln/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1533);
  if (ret == NULL)
      return -1;
  if (! (ret->nlink == 2)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_ln_0", "ret->nlink == 2");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_realpath_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "realpath") == NULL;
  str = getenv ("SKIP_TEST_REALPATH_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_REALPATH");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_realpath_0 (guestfs_h *g)
{
  if (test_realpath_0_skip ()) {
    skipped ("test_realpath_0", "environment variable set");
    return 0;
  }

  const char *_features1535[] = { "realpath", NULL };
  if (!guestfs_feature_available (g, (char **) _features1535)) {
    skipped ("test_realpath_0", "group %s not available in daemon",
             _features1535[0]);
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for realpath (0) */
  const char *_arg1536 = "/../directory";
  CLEANUP_FREE char *ret;
  ret = guestfs_realpath (g, _arg1536);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/directory")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_realpath_0", "realpath", ret, "/directory");
    return -1;
  }
  return 0;
}

static int
test_zfgrepi_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "zfgrepi") == NULL;
  str = getenv ("SKIP_TEST_ZFGREPI_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ZFGREPI");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_zfgrepi_0 (guestfs_h *g)
{
  if (test_zfgrepi_0_skip ()) {
    skipped ("test_zfgrepi_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for zfgrepi (0) */
  const char *_arg1538 = "abc";
  const char *_arg1539 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zfgrepi (g, _arg1538, _arg1539);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "abc", "abc123", "ABC"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_zfgrepi_0", "is_string_list (ret, 3, \"abc\", \"abc123\", \"ABC\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_zegrepi_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "zegrepi") == NULL;
  str = getenv ("SKIP_TEST_ZEGREPI_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ZEGREPI");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_zegrepi_0 (guestfs_h *g)
{
  if (test_zegrepi_0_skip ()) {
    skipped ("test_zegrepi_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for zegrepi (0) */
  const char *_arg1541 = "abc";
  const char *_arg1542 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zegrepi (g, _arg1541, _arg1542);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "abc", "abc123", "ABC"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_zegrepi_0", "is_string_list (ret, 3, \"abc\", \"abc123\", \"ABC\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_zgrepi_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "zgrepi") == NULL;
  str = getenv ("SKIP_TEST_ZGREPI_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ZGREPI");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_zgrepi_0 (guestfs_h *g)
{
  if (test_zgrepi_0_skip ()) {
    skipped ("test_zgrepi_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for zgrepi (0) */
  const char *_arg1544 = "abc";
  const char *_arg1545 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zgrepi (g, _arg1544, _arg1545);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "abc", "abc123", "ABC"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_zgrepi_0", "is_string_list (ret, 3, \"abc\", \"abc123\", \"ABC\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_zfgrep_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "zfgrep") == NULL;
  str = getenv ("SKIP_TEST_ZFGREP_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ZFGREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_zfgrep_0 (guestfs_h *g)
{
  if (test_zfgrep_0_skip ()) {
    skipped ("test_zfgrep_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for zfgrep (0) */
  const char *_arg1547 = "abc";
  const char *_arg1548 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zfgrep (g, _arg1547, _arg1548);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "abc", "abc123"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_zfgrep_0", "is_string_list (ret, 2, \"abc\", \"abc123\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_zegrep_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "zegrep") == NULL;
  str = getenv ("SKIP_TEST_ZEGREP_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ZEGREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_zegrep_0 (guestfs_h *g)
{
  if (test_zegrep_0_skip ()) {
    skipped ("test_zegrep_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for zegrep (0) */
  const char *_arg1550 = "abc";
  const char *_arg1551 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zegrep (g, _arg1550, _arg1551);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "abc", "abc123"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_zegrep_0", "is_string_list (ret, 2, \"abc\", \"abc123\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_zgrep_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "zgrep") == NULL;
  str = getenv ("SKIP_TEST_ZGREP_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ZGREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_zgrep_0 (guestfs_h *g)
{
  if (test_zgrep_0_skip ()) {
    skipped ("test_zgrep_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for zgrep (0) */
  const char *_arg1553 = "abc";
  const char *_arg1554 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zgrep (g, _arg1553, _arg1554);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "abc", "abc123"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_zgrep_0", "is_string_list (ret, 2, \"abc\", \"abc123\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_fgrepi_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "fgrepi") == NULL;
  str = getenv ("SKIP_TEST_FGREPI_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FGREPI");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_fgrepi_0 (guestfs_h *g)
{
  if (test_fgrepi_0_skip ()) {
    skipped ("test_fgrepi_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for fgrepi (0) */
  const char *_arg1556 = "abc";
  const char *_arg1557 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_fgrepi (g, _arg1556, _arg1557);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "abc", "abc123", "ABC"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_fgrepi_0", "is_string_list (ret, 3, \"abc\", \"abc123\", \"ABC\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_egrepi_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "egrepi") == NULL;
  str = getenv ("SKIP_TEST_EGREPI_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_EGREPI");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_egrepi_0 (guestfs_h *g)
{
  if (test_egrepi_0_skip ()) {
    skipped ("test_egrepi_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for egrepi (0) */
  const char *_arg1559 = "abc";
  const char *_arg1560 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_egrepi (g, _arg1559, _arg1560);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "abc", "abc123", "ABC"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_egrepi_0", "is_string_list (ret, 3, \"abc\", \"abc123\", \"ABC\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grepi_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grepi") == NULL;
  str = getenv ("SKIP_TEST_GREPI_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREPI");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grepi_0 (guestfs_h *g)
{
  if (test_grepi_0_skip ()) {
    skipped ("test_grepi_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grepi (0) */
  const char *_arg1562 = "abc";
  const char *_arg1563 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grepi (g, _arg1562, _arg1563);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "abc", "abc123", "ABC"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grepi_0", "is_string_list (ret, 3, \"abc\", \"abc123\", \"ABC\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_fgrep_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "fgrep") == NULL;
  str = getenv ("SKIP_TEST_FGREP_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FGREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_fgrep_0 (guestfs_h *g)
{
  if (test_fgrep_0_skip ()) {
    skipped ("test_fgrep_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for fgrep (0) */
  const char *_arg1565 = "abc";
  const char *_arg1566 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_fgrep (g, _arg1565, _arg1566);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "abc", "abc123"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_fgrep_0", "is_string_list (ret, 2, \"abc\", \"abc123\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_egrep_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "egrep") == NULL;
  str = getenv ("SKIP_TEST_EGREP_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_EGREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_egrep_0 (guestfs_h *g)
{
  if (test_egrep_0_skip ()) {
    skipped ("test_egrep_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for egrep (0) */
  const char *_arg1568 = "abc";
  const char *_arg1569 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_egrep (g, _arg1568, _arg1569);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "abc", "abc123"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_egrep_0", "is_string_list (ret, 2, \"abc\", \"abc123\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_0 (guestfs_h *g)
{
  if (test_grep_0_skip ()) {
    skipped ("test_grep_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (0) */
  const char *_arg1571 = "abc";
  const char *_arg1572 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1573;
  _optargs1573.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1571, _arg1572, &_optargs1573);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "abc", "abc123"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_0", "is_string_list (ret, 2, \"abc\", \"abc123\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_1 (guestfs_h *g)
{
  if (test_grep_1_skip ()) {
    skipped ("test_grep_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (1) */
  const char *_arg1574 = "nomatch";
  const char *_arg1575 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1576;
  _optargs1576.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1574, _arg1575, &_optargs1576);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_1", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_2 (guestfs_h *g)
{
  if (test_grep_2_skip ()) {
    skipped ("test_grep_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (2) */
  const char *_arg1577 = "nomatch";
  const char *_arg1578 = "/abssymlink";
  struct guestfs_grep_opts_argv _optargs1579;
  _optargs1579.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1577, _arg1578, &_optargs1579);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_2", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_3 (guestfs_h *g)
{
  if (test_grep_3_skip ()) {
    skipped ("test_grep_3", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (3) */
  const char *_arg1580 = "abc";
  const char *_arg1581 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1582;
  _optargs1582.extended = 1;
  _optargs1582.bitmask = UINT64_C(0x1);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1580, _arg1581, &_optargs1582);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "abc", "abc123"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_3", "is_string_list (ret, 2, \"abc\", \"abc123\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_4 (guestfs_h *g)
{
  if (test_grep_4_skip ()) {
    skipped ("test_grep_4", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (4) */
  const char *_arg1583 = "abc";
  const char *_arg1584 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1585;
  _optargs1585.fixed = 1;
  _optargs1585.bitmask = UINT64_C(0x2);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1583, _arg1584, &_optargs1585);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "abc", "abc123"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_4", "is_string_list (ret, 2, \"abc\", \"abc123\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_5 (guestfs_h *g)
{
  if (test_grep_5_skip ()) {
    skipped ("test_grep_5", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (5) */
  const char *_arg1586 = "abc";
  const char *_arg1587 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1588;
  _optargs1588.insensitive = 1;
  _optargs1588.bitmask = UINT64_C(0x4);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1586, _arg1587, &_optargs1588);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "abc", "abc123", "ABC"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_5", "is_string_list (ret, 3, \"abc\", \"abc123\", \"ABC\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_6_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_6");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_6 (guestfs_h *g)
{
  if (test_grep_6_skip ()) {
    skipped ("test_grep_6", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (6) */
  const char *_arg1589 = "abc";
  const char *_arg1590 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1591;
  _optargs1591.extended = 1;
  _optargs1591.insensitive = 1;
  _optargs1591.bitmask = UINT64_C(0x5);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1589, _arg1590, &_optargs1591);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "abc", "abc123", "ABC"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_6", "is_string_list (ret, 3, \"abc\", \"abc123\", \"ABC\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_7_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_7");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_7 (guestfs_h *g)
{
  if (test_grep_7_skip ()) {
    skipped ("test_grep_7", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (7) */
  const char *_arg1592 = "abc";
  const char *_arg1593 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1594;
  _optargs1594.fixed = 1;
  _optargs1594.insensitive = 1;
  _optargs1594.bitmask = UINT64_C(0x6);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1592, _arg1593, &_optargs1594);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "abc", "abc123", "ABC"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_7", "is_string_list (ret, 3, \"abc\", \"abc123\", \"ABC\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_8_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_8");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_8 (guestfs_h *g)
{
  if (test_grep_8_skip ()) {
    skipped ("test_grep_8", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (8) */
  const char *_arg1595 = "abc";
  const char *_arg1596 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1597;
  _optargs1597.compressed = 1;
  _optargs1597.bitmask = UINT64_C(0x8);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1595, _arg1596, &_optargs1597);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "abc", "abc123"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_8", "is_string_list (ret, 2, \"abc\", \"abc123\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_9_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_9");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_9 (guestfs_h *g)
{
  if (test_grep_9_skip ()) {
    skipped ("test_grep_9", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (9) */
  const char *_arg1598 = "abc";
  const char *_arg1599 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1600;
  _optargs1600.extended = 1;
  _optargs1600.compressed = 1;
  _optargs1600.bitmask = UINT64_C(0x9);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1598, _arg1599, &_optargs1600);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "abc", "abc123"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_9", "is_string_list (ret, 2, \"abc\", \"abc123\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_10_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_10");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_10 (guestfs_h *g)
{
  if (test_grep_10_skip ()) {
    skipped ("test_grep_10", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (10) */
  const char *_arg1601 = "abc";
  const char *_arg1602 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1603;
  _optargs1603.fixed = 1;
  _optargs1603.compressed = 1;
  _optargs1603.bitmask = UINT64_C(0xa);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1601, _arg1602, &_optargs1603);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "abc", "abc123"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_10", "is_string_list (ret, 2, \"abc\", \"abc123\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_11_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_11");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_11 (guestfs_h *g)
{
  if (test_grep_11_skip ()) {
    skipped ("test_grep_11", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (11) */
  const char *_arg1604 = "abc";
  const char *_arg1605 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1606;
  _optargs1606.insensitive = 1;
  _optargs1606.compressed = 1;
  _optargs1606.bitmask = UINT64_C(0xc);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1604, _arg1605, &_optargs1606);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "abc", "abc123", "ABC"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_11", "is_string_list (ret, 3, \"abc\", \"abc123\", \"ABC\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_12_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_12");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_12 (guestfs_h *g)
{
  if (test_grep_12_skip ()) {
    skipped ("test_grep_12", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (12) */
  const char *_arg1607 = "abc";
  const char *_arg1608 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1609;
  _optargs1609.extended = 1;
  _optargs1609.insensitive = 1;
  _optargs1609.compressed = 1;
  _optargs1609.bitmask = UINT64_C(0xd);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1607, _arg1608, &_optargs1609);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "abc", "abc123", "ABC"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_12", "is_string_list (ret, 3, \"abc\", \"abc123\", \"ABC\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_grep_13_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grep") == NULL;
  str = getenv ("SKIP_TEST_GREP_13");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GREP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grep_13 (guestfs_h *g)
{
  if (test_grep_13_skip ()) {
    skipped ("test_grep_13", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for grep (13) */
  const char *_arg1610 = "abc";
  const char *_arg1611 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1612;
  _optargs1612.fixed = 1;
  _optargs1612.insensitive = 1;
  _optargs1612.compressed = 1;
  _optargs1612.bitmask = UINT64_C(0xe);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1610, _arg1611, &_optargs1612);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "abc", "abc123", "ABC"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_grep_13", "is_string_list (ret, 3, \"abc\", \"abc123\", \"ABC\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_umask_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "umask") == NULL;
  str = getenv ("SKIP_TEST_UMASK_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UMASK");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_umask_0 (guestfs_h *g)
{
  if (test_umask_0_skip ()) {
    skipped ("test_umask_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for umask (0) */
  int ret;
  ret = guestfs_umask (g, 18);
  if (ret == -1)
    return -1;
  if (! (ret == 022)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_umask_0", "ret == 022");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_mknod_c_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mknod_c") == NULL;
  str = getenv ("SKIP_TEST_MKNOD_C_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKNOD_C");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mknod_c_0 (guestfs_h *g)
{
  if (test_mknod_c_0_skip ()) {
    skipped ("test_mknod_c_0", "environment variable set");
    return 0;
  }

  const char *_features1615[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1615)) {
    skipped ("test_mknod_c_0", "group %s not available in daemon",
             _features1615[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mknod_c (0) */
  const char *_arg1619 = "/mknod_c";
  int ret1;
  ret1 = guestfs_mknod_c (g, 511, 99, 66, _arg1619);
  if (ret1 == -1)
    return -1;
  const char *_arg1621 = "/mknod_c";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1621);
  if (ret == NULL)
      return -1;
  if (! (S_ISCHR (ret->mode) && (ret->mode & 0777) == 0755)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_mknod_c_0", "S_ISCHR (ret->mode) && (ret->mode & 0777) == 0755");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_mknod_b_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mknod_b") == NULL;
  str = getenv ("SKIP_TEST_MKNOD_B_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKNOD_B");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mknod_b_0 (guestfs_h *g)
{
  if (test_mknod_b_0_skip ()) {
    skipped ("test_mknod_b_0", "environment variable set");
    return 0;
  }

  const char *_features1623[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1623)) {
    skipped ("test_mknod_b_0", "group %s not available in daemon",
             _features1623[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mknod_b (0) */
  const char *_arg1627 = "/mknod_b";
  int ret1;
  ret1 = guestfs_mknod_b (g, 511, 99, 66, _arg1627);
  if (ret1 == -1)
    return -1;
  const char *_arg1629 = "/mknod_b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1629);
  if (ret == NULL)
      return -1;
  if (! (S_ISBLK (ret->mode) && (ret->mode & 0777) == 0755)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_mknod_b_0", "S_ISBLK (ret->mode) && (ret->mode & 0777) == 0755");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_mkfifo_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkfifo") == NULL;
  str = getenv ("SKIP_TEST_MKFIFO_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKFIFO");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkfifo_0 (guestfs_h *g)
{
  if (test_mkfifo_0_skip ()) {
    skipped ("test_mkfifo_0", "environment variable set");
    return 0;
  }

  const char *_features1631[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1631)) {
    skipped ("test_mkfifo_0", "group %s not available in daemon",
             _features1631[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mkfifo (0) */
  const char *_arg1633 = "/mkfifo";
  int ret1;
  ret1 = guestfs_mkfifo (g, 511, _arg1633);
  if (ret1 == -1)
    return -1;
  const char *_arg1635 = "/mkfifo";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1635);
  if (ret == NULL)
      return -1;
  if (! (S_ISFIFO (ret->mode) && (ret->mode & 0777) == 0755)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_mkfifo_0", "S_ISFIFO (ret->mode) && (ret->mode & 0777) == 0755");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_mknod_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mknod") == NULL;
  str = getenv ("SKIP_TEST_MKNOD_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKNOD");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mknod_0 (guestfs_h *g)
{
  if (test_mknod_0_skip ()) {
    skipped ("test_mknod_0", "environment variable set");
    return 0;
  }

  const char *_features1637[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1637)) {
    skipped ("test_mknod_0", "group %s not available in daemon",
             _features1637[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mknod (0) */
  const char *_arg1641 = "/mknod";
  int ret1;
  ret1 = guestfs_mknod (g, 4607, 0, 0, _arg1641);
  if (ret1 == -1)
    return -1;
  const char *_arg1643 = "/mknod";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1643);
  if (ret == NULL)
      return -1;
  if (! (S_ISFIFO (ret->mode) && (ret->mode & 0777) == 0755)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_mknod_0", "S_ISFIFO (ret->mode) && (ret->mode & 0777) == 0755");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_mknod_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mknod") == NULL;
  str = getenv ("SKIP_TEST_MKNOD_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKNOD");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mknod_1 (guestfs_h *g)
{
  if (test_mknod_1_skip ()) {
    skipped ("test_mknod_1", "environment variable set");
    return 0;
  }

  const char *_features1645[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1645)) {
    skipped ("test_mknod_1", "group %s not available in daemon",
             _features1645[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mknod (1) */
  const char *_arg1649 = "/mknod2";
  int ret1;
  ret1 = guestfs_mknod (g, 25087, 66, 99, _arg1649);
  if (ret1 == -1)
    return -1;
  const char *_arg1651 = "/mknod2";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1651);
  if (ret == NULL)
      return -1;
  if (! (S_ISBLK (ret->mode) && (ret->mode & 0777) == 0755)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_mknod_1", "S_ISBLK (ret->mode) && (ret->mode & 0777) == 0755");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_mkswap_U_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkswap_U") == NULL;
  str = getenv ("SKIP_TEST_MKSWAP_U_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKSWAP_U");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkswap_U_0 (guestfs_h *g)
{
  if (test_mkswap_U_0_skip ()) {
    skipped ("test_mkswap_U_0", "environment variable set");
    return 0;
  }

  const char *_features1653[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1653)) {
    skipped ("test_mkswap_U_0", "group %s not available in daemon",
             _features1653[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkswap_U (0) */
  const char *_arg1655 = "/dev/sda";
  const char *_arg1656 = "mbr";
  int _ret1654;
  _ret1654 = guestfs_part_disk (g, _arg1655, _arg1656);
  if (_ret1654 == -1)
    return -1;
  const char *_arg1659 = "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b";
  const char *_arg1660 = "/dev/sda1";
  int _ret1658;
  _ret1658 = guestfs_mkswap_U (g, _arg1659, _arg1660);
  if (_ret1658 == -1)
    return -1;
  return 0;
}

static int
test_mkswap_L_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkswap_L") == NULL;
  str = getenv ("SKIP_TEST_MKSWAP_L_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKSWAP_L");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkswap_L_0 (guestfs_h *g)
{
  if (test_mkswap_L_0_skip ()) {
    skipped ("test_mkswap_L_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkswap_L (0) */
  const char *_arg1663 = "/dev/sda";
  const char *_arg1664 = "mbr";
  int _ret1662;
  _ret1662 = guestfs_part_disk (g, _arg1663, _arg1664);
  if (_ret1662 == -1)
    return -1;
  const char *_arg1667 = "hello";
  const char *_arg1668 = "/dev/sda1";
  int _ret1666;
  _ret1666 = guestfs_mkswap_L (g, _arg1667, _arg1668);
  if (_ret1666 == -1)
    return -1;
  return 0;
}

static int
test_mkswap_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkswap") == NULL;
  str = getenv ("SKIP_TEST_MKSWAP_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKSWAP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkswap_0 (guestfs_h *g)
{
  if (test_mkswap_0_skip ()) {
    skipped ("test_mkswap_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkswap (0) */
  const char *_arg1671 = "/dev/sda";
  const char *_arg1672 = "mbr";
  int _ret1670;
  _ret1670 = guestfs_part_disk (g, _arg1671, _arg1672);
  if (_ret1670 == -1)
    return -1;
  const char *_arg1675 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1676;
  _optargs1676.bitmask = UINT64_C(0x0);
  int _ret1674;
  _ret1674 = guestfs_mkswap_opts_argv (g, _arg1675, &_optargs1676);
  if (_ret1674 == -1)
    return -1;
  return 0;
}

static int
test_mkswap_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkswap") == NULL;
  str = getenv ("SKIP_TEST_MKSWAP_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKSWAP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkswap_1 (guestfs_h *g)
{
  if (test_mkswap_1_skip ()) {
    skipped ("test_mkswap_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkswap (1) */
  const char *_arg1678 = "/dev/sda";
  const char *_arg1679 = "mbr";
  int _ret1677;
  _ret1677 = guestfs_part_disk (g, _arg1678, _arg1679);
  if (_ret1677 == -1)
    return -1;
  const char *_arg1682 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1683;
  _optargs1683.label = "hello";
  _optargs1683.bitmask = UINT64_C(0x1);
  int _ret1681;
  _ret1681 = guestfs_mkswap_opts_argv (g, _arg1682, &_optargs1683);
  if (_ret1681 == -1)
    return -1;
  return 0;
}

static int
test_mkswap_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkswap") == NULL;
  str = getenv ("SKIP_TEST_MKSWAP_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKSWAP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkswap_2 (guestfs_h *g)
{
  if (test_mkswap_2_skip ()) {
    skipped ("test_mkswap_2", "environment variable set");
    return 0;
  }

  const char *_features1684[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1684)) {
    skipped ("test_mkswap_2", "group %s not available in daemon",
             _features1684[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkswap (2) */
  const char *_arg1686 = "/dev/sda";
  const char *_arg1687 = "mbr";
  int _ret1685;
  _ret1685 = guestfs_part_disk (g, _arg1686, _arg1687);
  if (_ret1685 == -1)
    return -1;
  const char *_arg1690 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1691;
  _optargs1691.uuid = "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b";
  _optargs1691.bitmask = UINT64_C(0x2);
  int _ret1689;
  _ret1689 = guestfs_mkswap_opts_argv (g, _arg1690, &_optargs1691);
  if (_ret1689 == -1)
    return -1;
  return 0;
}

static int
test_mkswap_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkswap") == NULL;
  str = getenv ("SKIP_TEST_MKSWAP_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKSWAP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkswap_3 (guestfs_h *g)
{
  if (test_mkswap_3_skip ()) {
    skipped ("test_mkswap_3", "environment variable set");
    return 0;
  }

  const char *_features1692[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1692)) {
    skipped ("test_mkswap_3", "group %s not available in daemon",
             _features1692[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkswap (3) */
  const char *_arg1694 = "/dev/sda";
  const char *_arg1695 = "mbr";
  int _ret1693;
  _ret1693 = guestfs_part_disk (g, _arg1694, _arg1695);
  if (_ret1693 == -1)
    return -1;
  const char *_arg1698 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1699;
  _optargs1699.label = "hello";
  _optargs1699.uuid = "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b";
  _optargs1699.bitmask = UINT64_C(0x3);
  int _ret1697;
  _ret1697 = guestfs_mkswap_opts_argv (g, _arg1698, &_optargs1699);
  if (_ret1697 == -1)
    return -1;
  return 0;
}

static int
test_initrd_list_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "initrd_list") == NULL;
  str = getenv ("SKIP_TEST_INITRD_LIST_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_INITRD_LIST");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_initrd_list_0 (guestfs_h *g)
{
  if (test_initrd_list_0_skip ()) {
    skipped ("test_initrd_list_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for initrd_list (0) */
  const char *_arg1700 = "/initrd";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_initrd_list (g, _arg1700);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 6, "empty", "known-1", "known-2", "known-3", "known-4", "known-5"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_initrd_list_0", "is_string_list (ret, 6, \"empty\", \"known-1\", \"known-2\", \"known-3\", \"known-4\", \"known-5\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_du_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "du") == NULL;
  str = getenv ("SKIP_TEST_DU_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DU");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_du_0 (guestfs_h *g)
{
  if (test_du_0_skip ()) {
    skipped ("test_du_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for du (0) */
  const char *_arg1702 = "/directory";
  int64_t ret;
  ret = guestfs_du (g, _arg1702);
  if (ret == -1)
    return -1;
  if (! (ret == 2)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_du_0", "ret == 2");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_tail_n_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "tail_n") == NULL;
  str = getenv ("SKIP_TEST_TAIL_N_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TAIL_N");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_tail_n_0 (guestfs_h *g)
{
  if (test_tail_n_0_skip ()) {
    skipped ("test_tail_n_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for tail_n (0) */
  const char *_arg1705 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, 3, _arg1705);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "9997abcdefghijklmnopqrstuvwxyz", "9998abcdefghijklmnopqrstuvwxyz", "9999abcdefghijklmnopqrstuvwxyz"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_tail_n_0", "is_string_list (ret, 3, \"9997abcdefghijklmnopqrstuvwxyz\", \"9998abcdefghijklmnopqrstuvwxyz\", \"9999abcdefghijklmnopqrstuvwxyz\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_tail_n_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "tail_n") == NULL;
  str = getenv ("SKIP_TEST_TAIL_N_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TAIL_N");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_tail_n_1 (guestfs_h *g)
{
  if (test_tail_n_1_skip ()) {
    skipped ("test_tail_n_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for tail_n (1) */
  const char *_arg1708 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, -9998, _arg1708);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "9997abcdefghijklmnopqrstuvwxyz", "9998abcdefghijklmnopqrstuvwxyz", "9999abcdefghijklmnopqrstuvwxyz"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_tail_n_1", "is_string_list (ret, 3, \"9997abcdefghijklmnopqrstuvwxyz\", \"9998abcdefghijklmnopqrstuvwxyz\", \"9999abcdefghijklmnopqrstuvwxyz\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_tail_n_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "tail_n") == NULL;
  str = getenv ("SKIP_TEST_TAIL_N_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TAIL_N");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_tail_n_2 (guestfs_h *g)
{
  if (test_tail_n_2_skip ()) {
    skipped ("test_tail_n_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for tail_n (2) */
  const char *_arg1711 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, 0, _arg1711);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_tail_n_2", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_tail_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "tail") == NULL;
  str = getenv ("SKIP_TEST_TAIL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TAIL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_tail_0 (guestfs_h *g)
{
  if (test_tail_0_skip ()) {
    skipped ("test_tail_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for tail (0) */
  const char *_arg1713 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail (g, _arg1713);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 10, "9990abcdefghijklmnopqrstuvwxyz", "9991abcdefghijklmnopqrstuvwxyz", "9992abcdefghijklmnopqrstuvwxyz", "9993abcdefghijklmnopqrstuvwxyz", "9994abcdefghijklmnopqrstuvwxyz", "9995abcdefghijklmnopqrstuvwxyz", "9996abcdefghijklmnopqrstuvwxyz", "9997abcdefghijklmnopqrstuvwxyz", "9998abcdefghijklmnopqrstuvwxyz", "9999abcdefghijklmnopqrstuvwxyz"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_tail_0", "is_string_list (ret, 10, \"9990abcdefghijklmnopqrstuvwxyz\", \"9991abcdefghijklmnopqrstuvwxyz\", \"9992abcdefghijklmnopqrstuvwxyz\", \"9993abcdefghijklmnopqrstuvwxyz\", \"9994abcdefghijklmnopqrstuvwxyz\", \"9995abcdefghijklmnopqrstuvwxyz\", \"9996abcdefghijklmnopqrstuvwxyz\", \"9997abcdefghijklmnopqrstuvwxyz\", \"9998abcdefghijklmnopqrstuvwxyz\", \"9999abcdefghijklmnopqrstuvwxyz\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_head_n_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "head_n") == NULL;
  str = getenv ("SKIP_TEST_HEAD_N_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_HEAD_N");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_head_n_0 (guestfs_h *g)
{
  if (test_head_n_0_skip ()) {
    skipped ("test_head_n_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for head_n (0) */
  const char *_arg1716 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, 3, _arg1716);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "0abcdefghijklmnopqrstuvwxyz", "1abcdefghijklmnopqrstuvwxyz", "2abcdefghijklmnopqrstuvwxyz"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_head_n_0", "is_string_list (ret, 3, \"0abcdefghijklmnopqrstuvwxyz\", \"1abcdefghijklmnopqrstuvwxyz\", \"2abcdefghijklmnopqrstuvwxyz\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_head_n_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "head_n") == NULL;
  str = getenv ("SKIP_TEST_HEAD_N_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_HEAD_N");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_head_n_1 (guestfs_h *g)
{
  if (test_head_n_1_skip ()) {
    skipped ("test_head_n_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for head_n (1) */
  const char *_arg1719 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, -9997, _arg1719);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "0abcdefghijklmnopqrstuvwxyz", "1abcdefghijklmnopqrstuvwxyz", "2abcdefghijklmnopqrstuvwxyz"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_head_n_1", "is_string_list (ret, 3, \"0abcdefghijklmnopqrstuvwxyz\", \"1abcdefghijklmnopqrstuvwxyz\", \"2abcdefghijklmnopqrstuvwxyz\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_head_n_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "head_n") == NULL;
  str = getenv ("SKIP_TEST_HEAD_N_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_HEAD_N");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_head_n_2 (guestfs_h *g)
{
  if (test_head_n_2_skip ()) {
    skipped ("test_head_n_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for head_n (2) */
  const char *_arg1722 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, 0, _arg1722);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_head_n_2", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_head_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "head") == NULL;
  str = getenv ("SKIP_TEST_HEAD_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_HEAD");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_head_0 (guestfs_h *g)
{
  if (test_head_0_skip ()) {
    skipped ("test_head_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for head (0) */
  const char *_arg1724 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head (g, _arg1724);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 10, "0abcdefghijklmnopqrstuvwxyz", "1abcdefghijklmnopqrstuvwxyz", "2abcdefghijklmnopqrstuvwxyz", "3abcdefghijklmnopqrstuvwxyz", "4abcdefghijklmnopqrstuvwxyz", "5abcdefghijklmnopqrstuvwxyz", "6abcdefghijklmnopqrstuvwxyz", "7abcdefghijklmnopqrstuvwxyz", "8abcdefghijklmnopqrstuvwxyz", "9abcdefghijklmnopqrstuvwxyz"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_head_0", "is_string_list (ret, 10, \"0abcdefghijklmnopqrstuvwxyz\", \"1abcdefghijklmnopqrstuvwxyz\", \"2abcdefghijklmnopqrstuvwxyz\", \"3abcdefghijklmnopqrstuvwxyz\", \"4abcdefghijklmnopqrstuvwxyz\", \"5abcdefghijklmnopqrstuvwxyz\", \"6abcdefghijklmnopqrstuvwxyz\", \"7abcdefghijklmnopqrstuvwxyz\", \"8abcdefghijklmnopqrstuvwxyz\", \"9abcdefghijklmnopqrstuvwxyz\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_head_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "head") == NULL;
  str = getenv ("SKIP_TEST_HEAD_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_HEAD");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_head_1 (guestfs_h *g)
{
  if (test_head_1_skip ()) {
    skipped ("test_head_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for head (1) */
  const char *_arg1726 = "/abssymlink";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head (g, _arg1726);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 10, "0abcdefghijklmnopqrstuvwxyz", "1abcdefghijklmnopqrstuvwxyz", "2abcdefghijklmnopqrstuvwxyz", "3abcdefghijklmnopqrstuvwxyz", "4abcdefghijklmnopqrstuvwxyz", "5abcdefghijklmnopqrstuvwxyz", "6abcdefghijklmnopqrstuvwxyz", "7abcdefghijklmnopqrstuvwxyz", "8abcdefghijklmnopqrstuvwxyz", "9abcdefghijklmnopqrstuvwxyz"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_head_1", "is_string_list (ret, 10, \"0abcdefghijklmnopqrstuvwxyz\", \"1abcdefghijklmnopqrstuvwxyz\", \"2abcdefghijklmnopqrstuvwxyz\", \"3abcdefghijklmnopqrstuvwxyz\", \"4abcdefghijklmnopqrstuvwxyz\", \"5abcdefghijklmnopqrstuvwxyz\", \"6abcdefghijklmnopqrstuvwxyz\", \"7abcdefghijklmnopqrstuvwxyz\", \"8abcdefghijklmnopqrstuvwxyz\", \"9abcdefghijklmnopqrstuvwxyz\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_wc_c_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "wc_c") == NULL;
  str = getenv ("SKIP_TEST_WC_C_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WC_C");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_wc_c_0 (guestfs_h *g)
{
  if (test_wc_c_0_skip ()) {
    skipped ("test_wc_c_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for wc_c (0) */
  const char *_arg1728 = "/100kallspaces";
  int ret;
  ret = guestfs_wc_c (g, _arg1728);
  if (ret == -1)
    return -1;
  if (! (ret == 102400)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_wc_c_0", "ret == 102400");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_wc_w_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "wc_w") == NULL;
  str = getenv ("SKIP_TEST_WC_W_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WC_W");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_wc_w_0 (guestfs_h *g)
{
  if (test_wc_w_0_skip ()) {
    skipped ("test_wc_w_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for wc_w (0) */
  const char *_arg1730 = "/10klines";
  int ret;
  ret = guestfs_wc_w (g, _arg1730);
  if (ret == -1)
    return -1;
  if (! (ret == 10000)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_wc_w_0", "ret == 10000");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_wc_l_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "wc_l") == NULL;
  str = getenv ("SKIP_TEST_WC_L_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WC_L");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_wc_l_0 (guestfs_h *g)
{
  if (test_wc_l_0_skip ()) {
    skipped ("test_wc_l_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for wc_l (0) */
  const char *_arg1732 = "/10klines";
  int ret;
  ret = guestfs_wc_l (g, _arg1732);
  if (ret == -1)
    return -1;
  if (! (ret == 10000)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_wc_l_0", "ret == 10000");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_wc_l_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "wc_l") == NULL;
  str = getenv ("SKIP_TEST_WC_L_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WC_L");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_wc_l_1 (guestfs_h *g)
{
  if (test_wc_l_1_skip ()) {
    skipped ("test_wc_l_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for wc_l (1) */
  const char *_arg1734 = "/abssymlink";
  int ret;
  ret = guestfs_wc_l (g, _arg1734);
  if (ret == -1)
    return -1;
  if (! (ret == 10000)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_wc_l_1", "ret == 10000");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_mkdtemp_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkdtemp") == NULL;
  str = getenv ("SKIP_TEST_MKDTEMP_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKDTEMP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkdtemp_0 (guestfs_h *g)
{
  if (test_mkdtemp_0_skip ()) {
    skipped ("test_mkdtemp_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for mkdtemp (0) */
  const char *_arg1737 = "/mkdtemp";
  int _ret1736;
  _ret1736 = guestfs_mkdir (g, _arg1737);
  if (_ret1736 == -1)
    return -1;
  const char *_arg1740 = "/mkdtemp/tmpXXXXXX";
  CLEANUP_FREE char *_ret1739;
  _ret1739 = guestfs_mkdtemp (g, _arg1740);
  if (_ret1739 == NULL)
      return -1;
  return 0;
}

static int
test_scrub_file_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "scrub_file") == NULL;
  str = getenv ("SKIP_TEST_SCRUB_FILE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SCRUB_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_scrub_file_0 (guestfs_h *g)
{
  if (test_scrub_file_0_skip ()) {
    skipped ("test_scrub_file_0", "environment variable set");
    return 0;
  }

  const char *_features1742[] = { "scrub", NULL };
  if (!guestfs_feature_available (g, (char **) _features1742)) {
    skipped ("test_scrub_file_0", "group %s not available in daemon",
             _features1742[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for scrub_file (0) */
  const char *_arg1744 = "/scrub_file";
  const char *_arg1745 = "content";
  size_t _arg1745_size = 7;
  int _ret1743;
  _ret1743 = guestfs_write (g, _arg1744, _arg1745, _arg1745_size);
  if (_ret1743 == -1)
    return -1;
  const char *_arg1748 = "/scrub_file";
  int _ret1747;
  _ret1747 = guestfs_scrub_file (g, _arg1748);
  if (_ret1747 == -1)
    return -1;
  return 0;
}

static int
test_scrub_device_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "scrub_device") == NULL;
  str = getenv ("SKIP_TEST_SCRUB_DEVICE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SCRUB_DEVICE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_scrub_device_0 (guestfs_h *g)
{
  if (test_scrub_device_0_skip ()) {
    skipped ("test_scrub_device_0", "environment variable set");
    return 0;
  }

  const char *_features1750[] = { "scrub", NULL };
  if (!guestfs_feature_available (g, (char **) _features1750)) {
    skipped ("test_scrub_device_0", "group %s not available in daemon",
             _features1750[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for scrub_device (0) */
  const char *_arg1752 = "/dev/sdc";
  int _ret1751;
  _ret1751 = guestfs_scrub_device (g, _arg1752);
  if (_ret1751 == -1)
    return -1;
  return 0;
}

static int
test_glob_expand_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "glob_expand") == NULL;
  str = getenv ("SKIP_TEST_GLOB_EXPAND_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GLOB_EXPAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_glob_expand_0 (guestfs_h *g)
{
  if (test_glob_expand_0_skip ()) {
    skipped ("test_glob_expand_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for glob_expand (0) */
  const char *_arg1754 = "/glob_expand/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, _arg1754);
  if (ret3 == -1)
    return -1;
  const char *_arg1756 = "/glob_expand/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, _arg1756);
  if (ret2 == -1)
    return -1;
  const char *_arg1758 = "/glob_expand/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, _arg1758);
  if (ret1 == -1)
    return -1;
  const char *_arg1760 = "/glob_expand/b/c/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, _arg1760);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "/glob_expand/b/c/d", "/glob_expand/b/c/e"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_glob_expand_0", "is_string_list (ret, 2, \"/glob_expand/b/c/d\", \"/glob_expand/b/c/e\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_glob_expand_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "glob_expand") == NULL;
  str = getenv ("SKIP_TEST_GLOB_EXPAND_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GLOB_EXPAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_glob_expand_1 (guestfs_h *g)
{
  if (test_glob_expand_1_skip ()) {
    skipped ("test_glob_expand_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for glob_expand (1) */
  const char *_arg1762 = "/glob_expand2/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, _arg1762);
  if (ret3 == -1)
    return -1;
  const char *_arg1764 = "/glob_expand2/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, _arg1764);
  if (ret2 == -1)
    return -1;
  const char *_arg1766 = "/glob_expand2/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, _arg1766);
  if (ret1 == -1)
    return -1;
  const char *_arg1768 = "/glob_expand2/*/c/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, _arg1768);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "/glob_expand2/b/c/d", "/glob_expand2/b/c/e"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_glob_expand_1", "is_string_list (ret, 2, \"/glob_expand2/b/c/d\", \"/glob_expand2/b/c/e\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_glob_expand_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "glob_expand") == NULL;
  str = getenv ("SKIP_TEST_GLOB_EXPAND_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GLOB_EXPAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_glob_expand_2 (guestfs_h *g)
{
  if (test_glob_expand_2_skip ()) {
    skipped ("test_glob_expand_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for glob_expand (2) */
  const char *_arg1770 = "/glob_expand3/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, _arg1770);
  if (ret3 == -1)
    return -1;
  const char *_arg1772 = "/glob_expand3/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, _arg1772);
  if (ret2 == -1)
    return -1;
  const char *_arg1774 = "/glob_expand3/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, _arg1774);
  if (ret1 == -1)
    return -1;
  const char *_arg1776 = "/glob_expand3/*/x/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, _arg1776);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_glob_expand_2", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_ntfs_3g_probe_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "ntfs_3g_probe") == NULL;
  str = getenv ("SKIP_TEST_NTFS_3G_PROBE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_NTFS_3G_PROBE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_ntfs_3g_probe_0 (guestfs_h *g)
{
  if (test_ntfs_3g_probe_0_skip ()) {
    skipped ("test_ntfs_3g_probe_0", "environment variable set");
    return 0;
  }

  const char *_features1778[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features1778)) {
    skipped ("test_ntfs_3g_probe_0", "group %s not available in daemon",
             _features1778[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResult for ntfs_3g_probe (0) */
  const char *_arg1779 = "/dev/sda";
  const char *_arg1780 = "mbr";
  int ret2;
  ret2 = guestfs_part_disk (g, _arg1779, _arg1780);
  if (ret2 == -1)
    return -1;
  const char *_arg1782 = "ntfs";
  const char *_arg1783 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1784;
  _optargs1784.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_mkfs_opts_argv (g, _arg1782, _arg1783, &_optargs1784);
  if (ret1 == -1)
    return -1;
  const char *_arg1786 = "/dev/sda1";
  int ret;
  ret = guestfs_ntfs_3g_probe (g, 1, _arg1786);
  if (ret == -1)
    return -1;
  if (! (ret == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_ntfs_3g_probe_0", "ret == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_ntfs_3g_probe_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "ntfs_3g_probe") == NULL;
  str = getenv ("SKIP_TEST_NTFS_3G_PROBE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_NTFS_3G_PROBE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_ntfs_3g_probe_1 (guestfs_h *g)
{
  if (test_ntfs_3g_probe_1_skip ()) {
    skipped ("test_ntfs_3g_probe_1", "environment variable set");
    return 0;
  }

  const char *_features1788[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features1788)) {
    skipped ("test_ntfs_3g_probe_1", "group %s not available in daemon",
             _features1788[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResult for ntfs_3g_probe (1) */
  const char *_arg1789 = "/dev/sda";
  const char *_arg1790 = "mbr";
  int ret2;
  ret2 = guestfs_part_disk (g, _arg1789, _arg1790);
  if (ret2 == -1)
    return -1;
  const char *_arg1792 = "ext2";
  const char *_arg1793 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1794;
  _optargs1794.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_mkfs_opts_argv (g, _arg1792, _arg1793, &_optargs1794);
  if (ret1 == -1)
    return -1;
  const char *_arg1796 = "/dev/sda1";
  int ret;
  ret = guestfs_ntfs_3g_probe (g, 1, _arg1796);
  if (ret == -1)
    return -1;
  if (! (ret == 12)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_ntfs_3g_probe_1", "ret == 12");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_sleep_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "sleep") == NULL;
  str = getenv ("SKIP_TEST_SLEEP_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SLEEP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_sleep_0 (guestfs_h *g)
{
  if (test_sleep_0_skip ()) {
    skipped ("test_sleep_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for sleep (0) */
  int _ret1798;
  _ret1798 = guestfs_sleep (g, 1);
  if (_ret1798 == -1)
    return -1;
  return 0;
}

static int
test_lvresize_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lvresize") == NULL;
  str = getenv ("SKIP_TEST_LVRESIZE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LVRESIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lvresize_0 (guestfs_h *g)
{
  if (test_lvresize_0_skip ()) {
    skipped ("test_lvresize_0", "environment variable set");
    return 0;
  }

  const char *_features1801[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features1801)) {
    skipped ("test_lvresize_0", "group %s not available in daemon",
             _features1801[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultString for lvresize (0) */
  const char *_arg1803 = "/dev/sda";
  const char *_arg1804 = "mbr";
  int _ret1802;
  _ret1802 = guestfs_part_disk (g, _arg1803, _arg1804);
  if (_ret1802 == -1)
    return -1;
  const char *_arg1807 = "/dev/sda1";
  int _ret1806;
  _ret1806 = guestfs_pvcreate (g, _arg1807);
  if (_ret1806 == -1)
    return -1;
  const char *_arg1810 = "VG";
  const char *_arg1811_0 = "/dev/sda1";
  const char *const _arg1811[] = {
    _arg1811_0,
    NULL
  };
  int _ret1809;
  _ret1809 = guestfs_vgcreate (g, _arg1810, (char **) _arg1811);
  if (_ret1809 == -1)
    return -1;
  const char *_arg1814 = "LV";
  const char *_arg1815 = "VG";
  int _ret1813;
  _ret1813 = guestfs_lvcreate (g, _arg1814, _arg1815, 10);
  if (_ret1813 == -1)
    return -1;
  const char *_arg1819 = "ext2";
  const char *_arg1820 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs1821;
  _optargs1821.bitmask = UINT64_C(0x0);
  int _ret1818;
  _ret1818 = guestfs_mkfs_opts_argv (g, _arg1819, _arg1820, &_optargs1821);
  if (_ret1818 == -1)
    return -1;
  const char *_arg1823 = "/dev/VG/LV";
  const char *_arg1824 = "/";
  int _ret1822;
  _ret1822 = guestfs_mount (g, _arg1823, _arg1824);
  if (_ret1822 == -1)
    return -1;
  const char *_arg1827 = "/new";
  const char *_arg1828 = "test content";
  size_t _arg1828_size = 12;
  int _ret1826;
  _ret1826 = guestfs_write (g, _arg1827, _arg1828, _arg1828_size);
  if (_ret1826 == -1)
    return -1;
  const char *_arg1831 = "/";
  struct guestfs_umount_opts_argv _optargs1832;
  _optargs1832.force = 0;
  _optargs1832.lazyunmount = 0;
  _optargs1832.bitmask = UINT64_C(0x3);
  int _ret1830;
  _ret1830 = guestfs_umount_opts_argv (g, _arg1831, &_optargs1832);
  if (_ret1830 == -1)
    return -1;
  const char *_arg1834 = "/dev/VG/LV";
  int _ret1833;
  _ret1833 = guestfs_lvresize (g, _arg1834, 20);
  if (_ret1833 == -1)
    return -1;
  const char *_arg1838 = "/dev/VG/LV";
  int _ret1837;
  _ret1837 = guestfs_e2fsck_f (g, _arg1838);
  if (_ret1837 == -1)
    return -1;
  const char *_arg1841 = "/dev/VG/LV";
  struct guestfs_e2fsck_argv _optargs1842;
  _optargs1842.correct = 1;
  _optargs1842.forceall = 0;
  _optargs1842.bitmask = UINT64_C(0x3);
  int _ret1840;
  _ret1840 = guestfs_e2fsck_argv (g, _arg1841, &_optargs1842);
  if (_ret1840 == -1)
    return -1;
  const char *_arg1844 = "/dev/VG/LV";
  struct guestfs_e2fsck_argv _optargs1845;
  _optargs1845.correct = 0;
  _optargs1845.forceall = 1;
  _optargs1845.bitmask = UINT64_C(0x3);
  int _ret1843;
  _ret1843 = guestfs_e2fsck_argv (g, _arg1844, &_optargs1845);
  if (_ret1843 == -1)
    return -1;
  const char *_arg1847 = "/dev/VG/LV";
  int _ret1846;
  _ret1846 = guestfs_resize2fs (g, _arg1847);
  if (_ret1846 == -1)
    return -1;
  const char *_arg1850 = "/dev/VG/LV";
  const char *_arg1851 = "/";
  int _ret1849;
  _ret1849 = guestfs_mount (g, _arg1850, _arg1851);
  if (_ret1849 == -1)
    return -1;
  const char *_arg1853 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1853);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "test content")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_lvresize_0", "cat", ret, "test content");
    return -1;
  }
  return 0;
}

static int
test_lvresize_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lvresize") == NULL;
  str = getenv ("SKIP_TEST_LVRESIZE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LVRESIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lvresize_1 (guestfs_h *g)
{
  if (test_lvresize_1_skip ()) {
    skipped ("test_lvresize_1", "environment variable set");
    return 0;
  }

  const char *_features1855[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features1855)) {
    skipped ("test_lvresize_1", "group %s not available in daemon",
             _features1855[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for lvresize (1) */
  const char *_arg1857 = "/dev/sda";
  const char *_arg1858 = "mbr";
  int _ret1856;
  _ret1856 = guestfs_part_disk (g, _arg1857, _arg1858);
  if (_ret1856 == -1)
    return -1;
  const char *_arg1861 = "/dev/sda1";
  int _ret1860;
  _ret1860 = guestfs_pvcreate (g, _arg1861);
  if (_ret1860 == -1)
    return -1;
  const char *_arg1864 = "VG";
  const char *_arg1865_0 = "/dev/sda1";
  const char *const _arg1865[] = {
    _arg1865_0,
    NULL
  };
  int _ret1863;
  _ret1863 = guestfs_vgcreate (g, _arg1864, (char **) _arg1865);
  if (_ret1863 == -1)
    return -1;
  const char *_arg1868 = "LV";
  const char *_arg1869 = "VG";
  int _ret1867;
  _ret1867 = guestfs_lvcreate (g, _arg1868, _arg1869, 20);
  if (_ret1867 == -1)
    return -1;
  const char *_arg1873 = "/dev/VG/LV";
  int _ret1872;
  _ret1872 = guestfs_lvresize (g, _arg1873, 10);
  if (_ret1872 == -1)
    return -1;
  return 0;
}

static int
test_zerofree_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "zerofree") == NULL;
  str = getenv ("SKIP_TEST_ZEROFREE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ZEROFREE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_zerofree_0 (guestfs_h *g)
{
  if (test_zerofree_0_skip ()) {
    skipped ("test_zerofree_0", "environment variable set");
    return 0;
  }

  const char *_features1876[] = { "zerofree", NULL };
  if (!guestfs_feature_available (g, (char **) _features1876)) {
    skipped ("test_zerofree_0", "group %s not available in daemon",
             _features1876[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultString for zerofree (0) */
  const char *_arg1878 = "/dev/sda";
  const char *_arg1879 = "mbr";
  int _ret1877;
  _ret1877 = guestfs_part_disk (g, _arg1878, _arg1879);
  if (_ret1877 == -1)
    return -1;
  const char *_arg1882 = "ext3";
  const char *_arg1883 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1884;
  _optargs1884.bitmask = UINT64_C(0x0);
  int _ret1881;
  _ret1881 = guestfs_mkfs_opts_argv (g, _arg1882, _arg1883, &_optargs1884);
  if (_ret1881 == -1)
    return -1;
  const char *_arg1886 = "/dev/sda1";
  const char *_arg1887 = "/";
  int _ret1885;
  _ret1885 = guestfs_mount (g, _arg1886, _arg1887);
  if (_ret1885 == -1)
    return -1;
  const char *_arg1890 = "/new";
  const char *_arg1891 = "test file";
  size_t _arg1891_size = 9;
  int _ret1889;
  _ret1889 = guestfs_write (g, _arg1890, _arg1891, _arg1891_size);
  if (_ret1889 == -1)
    return -1;
  const char *_arg1894 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs1895;
  _optargs1895.force = 0;
  _optargs1895.lazyunmount = 0;
  _optargs1895.bitmask = UINT64_C(0x3);
  int _ret1893;
  _ret1893 = guestfs_umount_opts_argv (g, _arg1894, &_optargs1895);
  if (_ret1893 == -1)
    return -1;
  const char *_arg1897 = "/dev/sda1";
  int _ret1896;
  _ret1896 = guestfs_zerofree (g, _arg1897);
  if (_ret1896 == -1)
    return -1;
  const char *_arg1900 = "/dev/sda1";
  const char *_arg1901 = "/";
  int _ret1899;
  _ret1899 = guestfs_mount (g, _arg1900, _arg1901);
  if (_ret1899 == -1)
    return -1;
  const char *_arg1903 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1903);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "test file")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_zerofree_0", "cat", ret, "test file");
    return -1;
  }
  return 0;
}

static int
test_hexdump_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "hexdump") == NULL;
  str = getenv ("SKIP_TEST_HEXDUMP_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_HEXDUMP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_hexdump_0 (guestfs_h *g)
{
  if (test_hexdump_0_skip ()) {
    skipped ("test_hexdump_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for hexdump (0) */
  const char *_arg1905 = "/known-4";
  CLEANUP_FREE char *ret;
  ret = guestfs_hexdump (g, _arg1905);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "00000000  61 62 63 0a 64 65 66 0a  67 68 69                 |abc.def.ghi|\n0000000b\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_hexdump_0", "hexdump", ret, "00000000  61 62 63 0a 64 65 66 0a  67 68 69                 |abc.def.ghi|\n0000000b\n");
    return -1;
  }
  return 0;
}

static int
test_hexdump_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "hexdump") == NULL;
  str = getenv ("SKIP_TEST_HEXDUMP_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_HEXDUMP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_hexdump_1 (guestfs_h *g)
{
  if (test_hexdump_1_skip ()) {
    skipped ("test_hexdump_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestRun for hexdump (1) */
  const char *_arg1908 = "/100krandom";
  CLEANUP_FREE char *_ret1907;
  _ret1907 = guestfs_hexdump (g, _arg1908);
  if (_ret1907 == NULL)
      return -1;
  return 0;
}

static int
test_hexdump_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "hexdump") == NULL;
  str = getenv ("SKIP_TEST_HEXDUMP_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_HEXDUMP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_hexdump_2 (guestfs_h *g)
{
  if (test_hexdump_2_skip ()) {
    skipped ("test_hexdump_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestRun for hexdump (2) */
  const char *_arg1911 = "/abssymlink";
  CLEANUP_FREE char *_ret1910;
  _ret1910 = guestfs_hexdump (g, _arg1911);
  if (_ret1910 == NULL)
      return -1;
  return 0;
}

static int
test_strings_e_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "strings_e") == NULL;
  str = getenv ("SKIP_TEST_STRINGS_E_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_STRINGS_E");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_strings_e_0 (guestfs_h *g)
{
  if (test_strings_e_0_skip ()) {
    skipped ("test_strings_e_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for strings_e (0) */
  const char *_arg1913 = "b";
  const char *_arg1914 = "/known-5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings_e (g, _arg1913, _arg1914);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_strings_e_0", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_strings_e_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "strings_e") == NULL;
  str = getenv ("SKIP_TEST_STRINGS_E_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_STRINGS_E");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_strings_e_1 (guestfs_h *g)
{
  if (test_strings_e_1_skip ()) {
    skipped ("test_strings_e_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for strings_e (1) */
  const char *_arg1916 = "/strings_e";
  const char *_arg1917 = "\0h\0e\0l\0l\0o\0\n\0w\0o\0r\0l\0d\0\n";
  size_t _arg1917_size = 24;
  int ret1;
  ret1 = guestfs_write (g, _arg1916, _arg1917, _arg1917_size);
  if (ret1 == -1)
    return -1;
  const char *_arg1919 = "b";
  const char *_arg1920 = "/strings_e";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings_e (g, _arg1919, _arg1920);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "hello", "world"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_strings_e_1", "is_string_list (ret, 2, \"hello\", \"world\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_strings_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "strings") == NULL;
  str = getenv ("SKIP_TEST_STRINGS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_STRINGS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_strings_0 (guestfs_h *g)
{
  if (test_strings_0_skip ()) {
    skipped ("test_strings_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for strings (0) */
  const char *_arg1922 = "/known-5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings (g, _arg1922);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "abcdefghi", "jklmnopqr"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_strings_0", "is_string_list (ret, 2, \"abcdefghi\", \"jklmnopqr\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_strings_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "strings") == NULL;
  str = getenv ("SKIP_TEST_STRINGS_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_STRINGS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_strings_1 (guestfs_h *g)
{
  if (test_strings_1_skip ()) {
    skipped ("test_strings_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for strings (1) */
  const char *_arg1924 = "/empty";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings (g, _arg1924);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_strings_1", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_strings_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "strings") == NULL;
  str = getenv ("SKIP_TEST_STRINGS_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_STRINGS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_strings_2 (guestfs_h *g)
{
  if (test_strings_2_skip ()) {
    skipped ("test_strings_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestRun for strings (2) */
  const char *_arg1927 = "/abssymlink";
  CLEANUP_FREE_STRING_LIST char **_ret1926;
  _ret1926 = guestfs_strings (g, _arg1927);
  if (_ret1926 == NULL)
      return -1;
  return 0;
}

static int
test_equal_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "equal") == NULL;
  str = getenv ("SKIP_TEST_EQUAL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_EQUAL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_equal_0 (guestfs_h *g)
{
  if (test_equal_0_skip ()) {
    skipped ("test_equal_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultTrue for equal (0) */
  const char *_arg1930 = "/equal";
  int _ret1929;
  _ret1929 = guestfs_mkdir (g, _arg1930);
  if (_ret1929 == -1)
    return -1;
  const char *_arg1933 = "/equal/file1";
  const char *_arg1934 = "contents of a file";
  size_t _arg1934_size = 18;
  int _ret1932;
  _ret1932 = guestfs_write (g, _arg1933, _arg1934, _arg1934_size);
  if (_ret1932 == -1)
    return -1;
  const char *_arg1937 = "/equal/file1";
  const char *_arg1938 = "/equal/file2";
  int _ret1936;
  _ret1936 = guestfs_cp (g, _arg1937, _arg1938);
  if (_ret1936 == -1)
    return -1;
  const char *_arg1940 = "/equal/file1";
  const char *_arg1941 = "/equal/file2";
  int ret;
  ret = guestfs_equal (g, _arg1940, _arg1941);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_equal_0", "equal");
    return -1;
  }
  return 0;
}

static int
test_equal_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "equal") == NULL;
  str = getenv ("SKIP_TEST_EQUAL_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_EQUAL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_equal_1 (guestfs_h *g)
{
  if (test_equal_1_skip ()) {
    skipped ("test_equal_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultFalse for equal (1) */
  const char *_arg1944 = "/equal2";
  int _ret1943;
  _ret1943 = guestfs_mkdir (g, _arg1944);
  if (_ret1943 == -1)
    return -1;
  const char *_arg1947 = "/equal2/file1";
  const char *_arg1948 = "contents of a file";
  size_t _arg1948_size = 18;
  int _ret1946;
  _ret1946 = guestfs_write (g, _arg1947, _arg1948, _arg1948_size);
  if (_ret1946 == -1)
    return -1;
  const char *_arg1951 = "/equal2/file2";
  const char *_arg1952 = "contents of another file";
  size_t _arg1952_size = 24;
  int _ret1950;
  _ret1950 = guestfs_write (g, _arg1951, _arg1952, _arg1952_size);
  if (_ret1950 == -1)
    return -1;
  const char *_arg1954 = "/equal2/file1";
  const char *_arg1955 = "/equal2/file2";
  int ret;
  ret = guestfs_equal (g, _arg1954, _arg1955);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_equal_1", "equal");
    return -1;
  }
  return 0;
}

static int
test_equal_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "equal") == NULL;
  str = getenv ("SKIP_TEST_EQUAL_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_EQUAL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_equal_2 (guestfs_h *g)
{
  if (test_equal_2_skip ()) {
    skipped ("test_equal_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for equal (2) */
  const char *_arg1958 = "/equal3";
  int _ret1957;
  _ret1957 = guestfs_mkdir (g, _arg1958);
  if (_ret1957 == -1)
    return -1;
  const char *_arg1961 = "/equal3/file1";
  const char *_arg1962 = "/equal3/file2";
  int _ret1960;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1960 = guestfs_equal (g, _arg1961, _arg1962);
  guestfs_pop_error_handler (g);
  if (_ret1960 != -1)
    return -1;
  return 0;
}

static int
test_ping_daemon_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "ping_daemon") == NULL;
  str = getenv ("SKIP_TEST_PING_DAEMON_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PING_DAEMON");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_ping_daemon_0 (guestfs_h *g)
{
  if (test_ping_daemon_0_skip ()) {
    skipped ("test_ping_daemon_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for ping_daemon (0) */
  int _ret1964;
  _ret1964 = guestfs_ping_daemon (g);
  if (_ret1964 == -1)
    return -1;
  return 0;
}

static int
test_dmesg_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "dmesg") == NULL;
  str = getenv ("SKIP_TEST_DMESG_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DMESG");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_dmesg_0 (guestfs_h *g)
{
  if (test_dmesg_0_skip ()) {
    skipped ("test_dmesg_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for dmesg (0) */
  CLEANUP_FREE char *_ret1966;
  _ret1966 = guestfs_dmesg (g);
  if (_ret1966 == NULL)
      return -1;
  return 0;
}

static int
test_drop_caches_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "drop_caches") == NULL;
  str = getenv ("SKIP_TEST_DROP_CACHES_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DROP_CACHES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_drop_caches_0 (guestfs_h *g)
{
  if (test_drop_caches_0_skip ()) {
    skipped ("test_drop_caches_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for drop_caches (0) */
  int _ret1968;
  _ret1968 = guestfs_drop_caches (g, 3);
  if (_ret1968 == -1)
    return -1;
  return 0;
}

static int
test_mv_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mv") == NULL;
  str = getenv ("SKIP_TEST_MV_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MV");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mv_0 (guestfs_h *g)
{
  if (test_mv_0_skip ()) {
    skipped ("test_mv_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for mv (0) */
  const char *_arg1972 = "/mv";
  int _ret1971;
  _ret1971 = guestfs_mkdir (g, _arg1972);
  if (_ret1971 == -1)
    return -1;
  const char *_arg1975 = "/mv/old";
  const char *_arg1976 = "file content";
  size_t _arg1976_size = 12;
  int _ret1974;
  _ret1974 = guestfs_write (g, _arg1975, _arg1976, _arg1976_size);
  if (_ret1974 == -1)
    return -1;
  const char *_arg1979 = "/mv/old";
  const char *_arg1980 = "/mv/new";
  int _ret1978;
  _ret1978 = guestfs_mv (g, _arg1979, _arg1980);
  if (_ret1978 == -1)
    return -1;
  const char *_arg1982 = "/mv/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1982);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "file content")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mv_0", "cat", ret, "file content");
    return -1;
  }
  return 0;
}

static int
test_mv_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mv") == NULL;
  str = getenv ("SKIP_TEST_MV_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MV");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mv_1 (guestfs_h *g)
{
  if (test_mv_1_skip ()) {
    skipped ("test_mv_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultFalse for mv (1) */
  const char *_arg1985 = "/mv2";
  int _ret1984;
  _ret1984 = guestfs_mkdir (g, _arg1985);
  if (_ret1984 == -1)
    return -1;
  const char *_arg1988 = "/mv2/old";
  const char *_arg1989 = "file content";
  size_t _arg1989_size = 12;
  int _ret1987;
  _ret1987 = guestfs_write (g, _arg1988, _arg1989, _arg1989_size);
  if (_ret1987 == -1)
    return -1;
  const char *_arg1992 = "/mv2/old";
  const char *_arg1993 = "/mv2/new";
  int _ret1991;
  _ret1991 = guestfs_mv (g, _arg1992, _arg1993);
  if (_ret1991 == -1)
    return -1;
  const char *_arg1995 = "/mv2/old";
  int ret;
  ret = guestfs_is_file (g, _arg1995);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_mv_1", "is_file");
    return -1;
  }
  return 0;
}

static int
test_cp_a_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "cp_a") == NULL;
  str = getenv ("SKIP_TEST_CP_A_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CP_A");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_cp_a_0 (guestfs_h *g)
{
  if (test_cp_a_0_skip ()) {
    skipped ("test_cp_a_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for cp_a (0) */
  const char *_arg1998 = "/cp_a1";
  int _ret1997;
  _ret1997 = guestfs_mkdir (g, _arg1998);
  if (_ret1997 == -1)
    return -1;
  const char *_arg2001 = "/cp_a2";
  int _ret2000;
  _ret2000 = guestfs_mkdir (g, _arg2001);
  if (_ret2000 == -1)
    return -1;
  const char *_arg2004 = "/cp_a1/file";
  const char *_arg2005 = "file content";
  size_t _arg2005_size = 12;
  int _ret2003;
  _ret2003 = guestfs_write (g, _arg2004, _arg2005, _arg2005_size);
  if (_ret2003 == -1)
    return -1;
  const char *_arg2008 = "/cp_a1";
  const char *_arg2009 = "/cp_a2";
  int _ret2007;
  _ret2007 = guestfs_cp_a (g, _arg2008, _arg2009);
  if (_ret2007 == -1)
    return -1;
  const char *_arg2011 = "/cp_a2/cp_a1/file";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2011);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "file content")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_cp_a_0", "cat", ret, "file content");
    return -1;
  }
  return 0;
}

static int
test_cp_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "cp") == NULL;
  str = getenv ("SKIP_TEST_CP_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_cp_0 (guestfs_h *g)
{
  if (test_cp_0_skip ()) {
    skipped ("test_cp_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for cp (0) */
  const char *_arg2014 = "/cp";
  int _ret2013;
  _ret2013 = guestfs_mkdir (g, _arg2014);
  if (_ret2013 == -1)
    return -1;
  const char *_arg2017 = "/cp/old";
  const char *_arg2018 = "file content";
  size_t _arg2018_size = 12;
  int _ret2016;
  _ret2016 = guestfs_write (g, _arg2017, _arg2018, _arg2018_size);
  if (_ret2016 == -1)
    return -1;
  const char *_arg2021 = "/cp/old";
  const char *_arg2022 = "/cp/new";
  int _ret2020;
  _ret2020 = guestfs_cp (g, _arg2021, _arg2022);
  if (_ret2020 == -1)
    return -1;
  const char *_arg2024 = "/cp/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2024);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "file content")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_cp_0", "cat", ret, "file content");
    return -1;
  }
  return 0;
}

static int
test_cp_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "cp") == NULL;
  str = getenv ("SKIP_TEST_CP_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_cp_1 (guestfs_h *g)
{
  if (test_cp_1_skip ()) {
    skipped ("test_cp_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultTrue for cp (1) */
  const char *_arg2027 = "/cp2";
  int _ret2026;
  _ret2026 = guestfs_mkdir (g, _arg2027);
  if (_ret2026 == -1)
    return -1;
  const char *_arg2030 = "/cp2/old";
  const char *_arg2031 = "file content";
  size_t _arg2031_size = 12;
  int _ret2029;
  _ret2029 = guestfs_write (g, _arg2030, _arg2031, _arg2031_size);
  if (_ret2029 == -1)
    return -1;
  const char *_arg2034 = "/cp2/old";
  const char *_arg2035 = "/cp2/new";
  int _ret2033;
  _ret2033 = guestfs_cp (g, _arg2034, _arg2035);
  if (_ret2033 == -1)
    return -1;
  const char *_arg2037 = "/cp2/old";
  int ret;
  ret = guestfs_is_file (g, _arg2037);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_cp_1", "is_file");
    return -1;
  }
  return 0;
}

static int
test_cp_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "cp") == NULL;
  str = getenv ("SKIP_TEST_CP_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CP");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_cp_2 (guestfs_h *g)
{
  if (test_cp_2_skip ()) {
    skipped ("test_cp_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for cp (2) */
  const char *_arg2040 = "/cp3";
  int _ret2039;
  _ret2039 = guestfs_mkdir (g, _arg2040);
  if (_ret2039 == -1)
    return -1;
  const char *_arg2043 = "/cp3/old";
  const char *_arg2044 = "file content";
  size_t _arg2044_size = 12;
  int _ret2042;
  _ret2042 = guestfs_write (g, _arg2043, _arg2044, _arg2044_size);
  if (_ret2042 == -1)
    return -1;
  const char *_arg2047 = "/cp3/dir";
  int _ret2046;
  _ret2046 = guestfs_mkdir (g, _arg2047);
  if (_ret2046 == -1)
    return -1;
  const char *_arg2050 = "/cp3/old";
  const char *_arg2051 = "/cp3/dir/new";
  int _ret2049;
  _ret2049 = guestfs_cp (g, _arg2050, _arg2051);
  if (_ret2049 == -1)
    return -1;
  const char *_arg2053 = "/cp3/dir/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2053);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "file content")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_cp_2", "cat", ret, "file content");
    return -1;
  }
  return 0;
}

static int
test_grub_install_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "grub_install") == NULL;
  str = getenv ("SKIP_TEST_GRUB_INSTALL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GRUB_INSTALL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_grub_install_0 (guestfs_h *g)
{
  if (test_grub_install_0_skip ()) {
    skipped ("test_grub_install_0", "environment variable set");
    return 0;
  }

  const char *_features2055[] = { "grub", NULL };
  if (!guestfs_feature_available (g, (char **) _features2055)) {
    skipped ("test_grub_install_0", "group %s not available in daemon",
             _features2055[0]);
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResultTrue for grub_install (0) */
  const char *_arg2057 = "/boot/grub";
  int _ret2056;
  _ret2056 = guestfs_mkdir_p (g, _arg2057);
  if (_ret2056 == -1)
    return -1;
  const char *_arg2060 = "/boot/grub/device.map";
  const char *_arg2061 = "(hd0) /dev/sda";
  size_t _arg2061_size = 14;
  int _ret2059;
  _ret2059 = guestfs_write (g, _arg2060, _arg2061, _arg2061_size);
  if (_ret2059 == -1)
    return -1;
  const char *_arg2064 = "/";
  const char *_arg2065 = "/dev/sda";
  int _ret2063;
  _ret2063 = guestfs_grub_install (g, _arg2064, _arg2065);
  if (_ret2063 == -1)
    return -1;
  const char *_arg2067 = "/boot";
  int ret;
  ret = guestfs_is_dir (g, _arg2067);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_grub_install_0", "is_dir");
    return -1;
  }
  return 0;
}

static int
test_zero_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "zero") == NULL;
  str = getenv ("SKIP_TEST_ZERO_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ZERO");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_zero_0 (guestfs_h *g)
{
  if (test_zero_0_skip ()) {
    skipped ("test_zero_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestRun for zero (0) */
  const char *_arg2070 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs2071;
  _optargs2071.force = 0;
  _optargs2071.lazyunmount = 0;
  _optargs2071.bitmask = UINT64_C(0x3);
  int _ret2069;
  _ret2069 = guestfs_umount_opts_argv (g, _arg2070, &_optargs2071);
  if (_ret2069 == -1)
    return -1;
  const char *_arg2073 = "/dev/sda1";
  int _ret2072;
  _ret2072 = guestfs_zero (g, _arg2073);
  if (_ret2072 == -1)
    return -1;
  return 0;
}

static int
test_fsck_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "fsck") == NULL;
  str = getenv ("SKIP_TEST_FSCK_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FSCK");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_fsck_0 (guestfs_h *g)
{
  if (test_fsck_0_skip ()) {
    skipped ("test_fsck_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResult for fsck (0) */
  const char *_arg2075 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs2076;
  _optargs2076.force = 0;
  _optargs2076.lazyunmount = 0;
  _optargs2076.bitmask = UINT64_C(0x3);
  int ret1;
  ret1 = guestfs_umount_opts_argv (g, _arg2075, &_optargs2076);
  if (ret1 == -1)
    return -1;
  const char *_arg2077 = "ext2";
  const char *_arg2078 = "/dev/sda1";
  int ret;
  ret = guestfs_fsck (g, _arg2077, _arg2078);
  if (ret == -1)
    return -1;
  if (! (ret == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_fsck_0", "ret == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_fsck_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "fsck") == NULL;
  str = getenv ("SKIP_TEST_FSCK_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FSCK");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_fsck_1 (guestfs_h *g)
{
  if (test_fsck_1_skip ()) {
    skipped ("test_fsck_1", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResult for fsck (1) */
  const char *_arg2080 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs2081;
  _optargs2081.force = 0;
  _optargs2081.lazyunmount = 0;
  _optargs2081.bitmask = UINT64_C(0x3);
  int ret2;
  ret2 = guestfs_umount_opts_argv (g, _arg2080, &_optargs2081);
  if (ret2 == -1)
    return -1;
  const char *_arg2082 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_zero (g, _arg2082);
  if (ret1 == -1)
    return -1;
  const char *_arg2084 = "ext2";
  const char *_arg2085 = "/dev/sda1";
  int ret;
  ret = guestfs_fsck (g, _arg2084, _arg2085);
  if (ret == -1)
    return -1;
  if (! (ret == 8)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_fsck_1", "ret == 8");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_get_e2uuid_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_e2uuid") == NULL;
  str = getenv ("SKIP_TEST_GET_E2UUID_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_E2UUID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_e2uuid_0 (guestfs_h *g)
{
  if (test_get_e2uuid_0_skip ()) {
    skipped ("test_get_e2uuid_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultString for get_e2uuid (0) */
  const char *_arg2089 = "/dev/sdc";
  int _ret2087;
  _ret2087 = guestfs_mke2journal (g, 1024, _arg2089);
  if (_ret2087 == -1)
    return -1;
  const char *_arg2092 = "/dev/sdc";
  const char *_arg2093 = "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b";
  int _ret2091;
  _ret2091 = guestfs_set_e2uuid (g, _arg2092, _arg2093);
  if (_ret2091 == -1)
    return -1;
  const char *_arg2095 = "/dev/sdc";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, _arg2095);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_get_e2uuid_0", "get_e2uuid", ret, "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b");
    return -1;
  }
  return 0;
}

static int
test_set_e2uuid_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_e2uuid") == NULL;
  str = getenv ("SKIP_TEST_SET_E2UUID_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_E2UUID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_set_e2uuid_0 (guestfs_h *g)
{
  if (test_set_e2uuid_0_skip ()) {
    skipped ("test_set_e2uuid_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResultString for set_e2uuid (0) */
  const char *_arg2098 = "/dev/sda1";
  const char *_arg2099 = "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b";
  int _ret2097;
  _ret2097 = guestfs_set_e2uuid (g, _arg2098, _arg2099);
  if (_ret2097 == -1)
    return -1;
  const char *_arg2101 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, _arg2101);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_e2uuid_0", "get_e2uuid", ret, "ca27c5d7-8afb-7db4-5e5d-19221fa1e22b");
    return -1;
  }
  return 0;
}

static int
test_set_e2uuid_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_e2uuid") == NULL;
  str = getenv ("SKIP_TEST_SET_E2UUID_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_E2UUID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_set_e2uuid_1 (guestfs_h *g)
{
  if (test_set_e2uuid_1_skip ()) {
    skipped ("test_set_e2uuid_1", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResultString for set_e2uuid (1) */
  const char *_arg2104 = "/dev/sda1";
  const char *_arg2105 = "clear";
  int _ret2103;
  _ret2103 = guestfs_set_e2uuid (g, _arg2104, _arg2105);
  if (_ret2103 == -1)
    return -1;
  const char *_arg2107 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, _arg2107);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_e2uuid_1", "get_e2uuid", ret, "");
    return -1;
  }
  return 0;
}

static int
test_set_e2uuid_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_e2uuid") == NULL;
  str = getenv ("SKIP_TEST_SET_E2UUID_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_E2UUID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_set_e2uuid_2 (guestfs_h *g)
{
  if (test_set_e2uuid_2_skip ()) {
    skipped ("test_set_e2uuid_2", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestRun for set_e2uuid (2) */
  const char *_arg2110 = "/dev/sda1";
  const char *_arg2111 = "random";
  int _ret2109;
  _ret2109 = guestfs_set_e2uuid (g, _arg2110, _arg2111);
  if (_ret2109 == -1)
    return -1;
  return 0;
}

static int
test_set_e2uuid_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_e2uuid") == NULL;
  str = getenv ("SKIP_TEST_SET_E2UUID_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_E2UUID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_set_e2uuid_3 (guestfs_h *g)
{
  if (test_set_e2uuid_3_skip ()) {
    skipped ("test_set_e2uuid_3", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestRun for set_e2uuid (3) */
  const char *_arg2114 = "/dev/sda1";
  const char *_arg2115 = "time";
  int _ret2113;
  _ret2113 = guestfs_set_e2uuid (g, _arg2114, _arg2115);
  if (_ret2113 == -1)
    return -1;
  return 0;
}

static int
test_set_e2label_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_e2label") == NULL;
  str = getenv ("SKIP_TEST_SET_E2LABEL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_E2LABEL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_set_e2label_0 (guestfs_h *g)
{
  if (test_set_e2label_0_skip ()) {
    skipped ("test_set_e2label_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResultString for set_e2label (0) */
  const char *_arg2118 = "/dev/sda1";
  const char *_arg2119 = "testlabel";
  int _ret2117;
  _ret2117 = guestfs_set_e2label (g, _arg2118, _arg2119);
  if (_ret2117 == -1)
    return -1;
  const char *_arg2121 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2label (g, _arg2121);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "testlabel")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_e2label_0", "get_e2label", ret, "testlabel");
    return -1;
  }
  return 0;
}

static int
test_pvremove_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pvremove") == NULL;
  str = getenv ("SKIP_TEST_PVREMOVE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PVREMOVE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pvremove_0 (guestfs_h *g)
{
  if (test_pvremove_0_skip ()) {
    skipped ("test_pvremove_0", "environment variable set");
    return 0;
  }

  const char *_features2123[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2123)) {
    skipped ("test_pvremove_0", "group %s not available in daemon",
             _features2123[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvremove (0) */
  const char *_arg2124 = "/dev/sda";
  const char *_arg2125 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg2124, _arg2125);
  if (ret7 == -1)
    return -1;
  const char *_arg2127 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg2127);
  if (ret6 == -1)
    return -1;
  const char *_arg2129 = "VG";
  const char *_arg2130_0 = "/dev/sda1";
  const char *const _arg2130[] = {
    _arg2130_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg2129, (char **) _arg2130);
  if (ret5 == -1)
    return -1;
  const char *_arg2132 = "LV1";
  const char *_arg2133 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg2132, _arg2133, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg2136 = "LV2";
  const char *_arg2137 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2136, _arg2137, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2140 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, _arg2140);
  if (ret2 == -1)
    return -1;
  const char *_arg2142 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, _arg2142);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_lvs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_pvremove_0", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_pvremove_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pvremove") == NULL;
  str = getenv ("SKIP_TEST_PVREMOVE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PVREMOVE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pvremove_1 (guestfs_h *g)
{
  if (test_pvremove_1_skip ()) {
    skipped ("test_pvremove_1", "environment variable set");
    return 0;
  }

  const char *_features2145[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2145)) {
    skipped ("test_pvremove_1", "group %s not available in daemon",
             _features2145[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvremove (1) */
  const char *_arg2146 = "/dev/sda";
  const char *_arg2147 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg2146, _arg2147);
  if (ret7 == -1)
    return -1;
  const char *_arg2149 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg2149);
  if (ret6 == -1)
    return -1;
  const char *_arg2151 = "VG";
  const char *_arg2152_0 = "/dev/sda1";
  const char *const _arg2152[] = {
    _arg2152_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg2151, (char **) _arg2152);
  if (ret5 == -1)
    return -1;
  const char *_arg2154 = "LV1";
  const char *_arg2155 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg2154, _arg2155, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg2158 = "LV2";
  const char *_arg2159 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2158, _arg2159, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2162 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, _arg2162);
  if (ret2 == -1)
    return -1;
  const char *_arg2164 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, _arg2164);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_vgs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_pvremove_1", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_pvremove_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pvremove") == NULL;
  str = getenv ("SKIP_TEST_PVREMOVE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PVREMOVE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pvremove_2 (guestfs_h *g)
{
  if (test_pvremove_2_skip ()) {
    skipped ("test_pvremove_2", "environment variable set");
    return 0;
  }

  const char *_features2167[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2167)) {
    skipped ("test_pvremove_2", "group %s not available in daemon",
             _features2167[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvremove (2) */
  const char *_arg2168 = "/dev/sda";
  const char *_arg2169 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg2168, _arg2169);
  if (ret7 == -1)
    return -1;
  const char *_arg2171 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg2171);
  if (ret6 == -1)
    return -1;
  const char *_arg2173 = "VG";
  const char *_arg2174_0 = "/dev/sda1";
  const char *const _arg2174[] = {
    _arg2174_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg2173, (char **) _arg2174);
  if (ret5 == -1)
    return -1;
  const char *_arg2176 = "LV1";
  const char *_arg2177 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg2176, _arg2177, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg2180 = "LV2";
  const char *_arg2181 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2180, _arg2181, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2184 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, _arg2184);
  if (ret2 == -1)
    return -1;
  const char *_arg2186 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, _arg2186);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_pvs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_pvremove_2", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_vgremove_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vgremove") == NULL;
  str = getenv ("SKIP_TEST_VGREMOVE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VGREMOVE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vgremove_0 (guestfs_h *g)
{
  if (test_vgremove_0_skip ()) {
    skipped ("test_vgremove_0", "environment variable set");
    return 0;
  }

  const char *_features2189[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2189)) {
    skipped ("test_vgremove_0", "group %s not available in daemon",
             _features2189[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for vgremove (0) */
  const char *_arg2190 = "/dev/sda";
  const char *_arg2191 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2190, _arg2191);
  if (ret6 == -1)
    return -1;
  const char *_arg2193 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2193);
  if (ret5 == -1)
    return -1;
  const char *_arg2195 = "VG";
  const char *_arg2196_0 = "/dev/sda1";
  const char *const _arg2196[] = {
    _arg2196_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2195, (char **) _arg2196);
  if (ret4 == -1)
    return -1;
  const char *_arg2198 = "LV1";
  const char *_arg2199 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2198, _arg2199, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2202 = "LV2";
  const char *_arg2203 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2202, _arg2203, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2206 = "VG";
  int ret1;
  ret1 = guestfs_vgremove (g, _arg2206);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_lvs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_vgremove_0", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_vgremove_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vgremove") == NULL;
  str = getenv ("SKIP_TEST_VGREMOVE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VGREMOVE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vgremove_1 (guestfs_h *g)
{
  if (test_vgremove_1_skip ()) {
    skipped ("test_vgremove_1", "environment variable set");
    return 0;
  }

  const char *_features2209[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2209)) {
    skipped ("test_vgremove_1", "group %s not available in daemon",
             _features2209[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for vgremove (1) */
  const char *_arg2210 = "/dev/sda";
  const char *_arg2211 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2210, _arg2211);
  if (ret6 == -1)
    return -1;
  const char *_arg2213 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2213);
  if (ret5 == -1)
    return -1;
  const char *_arg2215 = "VG";
  const char *_arg2216_0 = "/dev/sda1";
  const char *const _arg2216[] = {
    _arg2216_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2215, (char **) _arg2216);
  if (ret4 == -1)
    return -1;
  const char *_arg2218 = "LV1";
  const char *_arg2219 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2218, _arg2219, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2222 = "LV2";
  const char *_arg2223 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2222, _arg2223, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2226 = "VG";
  int ret1;
  ret1 = guestfs_vgremove (g, _arg2226);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_vgs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_vgremove_1", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_lvremove_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lvremove") == NULL;
  str = getenv ("SKIP_TEST_LVREMOVE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LVREMOVE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lvremove_0 (guestfs_h *g)
{
  if (test_lvremove_0_skip ()) {
    skipped ("test_lvremove_0", "environment variable set");
    return 0;
  }

  const char *_features2229[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2229)) {
    skipped ("test_lvremove_0", "group %s not available in daemon",
             _features2229[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvremove (0) */
  const char *_arg2230 = "/dev/sda";
  const char *_arg2231 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2230, _arg2231);
  if (ret6 == -1)
    return -1;
  const char *_arg2233 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2233);
  if (ret5 == -1)
    return -1;
  const char *_arg2235 = "VG";
  const char *_arg2236_0 = "/dev/sda1";
  const char *const _arg2236[] = {
    _arg2236_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2235, (char **) _arg2236);
  if (ret4 == -1)
    return -1;
  const char *_arg2238 = "LV1";
  const char *_arg2239 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2238, _arg2239, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2242 = "LV2";
  const char *_arg2243 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2242, _arg2243, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2246 = "/dev/VG/LV1";
  int ret1;
  ret1 = guestfs_lvremove (g, _arg2246);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_lvs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 1, "/dev/VG/LV2"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_lvremove_0", "is_string_list (ret, 1, \"/dev/VG/LV2\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_lvremove_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lvremove") == NULL;
  str = getenv ("SKIP_TEST_LVREMOVE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LVREMOVE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lvremove_1 (guestfs_h *g)
{
  if (test_lvremove_1_skip ()) {
    skipped ("test_lvremove_1", "environment variable set");
    return 0;
  }

  const char *_features2249[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2249)) {
    skipped ("test_lvremove_1", "group %s not available in daemon",
             _features2249[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvremove (1) */
  const char *_arg2250 = "/dev/sda";
  const char *_arg2251 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2250, _arg2251);
  if (ret6 == -1)
    return -1;
  const char *_arg2253 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2253);
  if (ret5 == -1)
    return -1;
  const char *_arg2255 = "VG";
  const char *_arg2256_0 = "/dev/sda1";
  const char *const _arg2256[] = {
    _arg2256_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2255, (char **) _arg2256);
  if (ret4 == -1)
    return -1;
  const char *_arg2258 = "LV1";
  const char *_arg2259 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2258, _arg2259, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2262 = "LV2";
  const char *_arg2263 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2262, _arg2263, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2266 = "/dev/VG";
  int ret1;
  ret1 = guestfs_lvremove (g, _arg2266);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_lvs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_lvremove_1", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_lvremove_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lvremove") == NULL;
  str = getenv ("SKIP_TEST_LVREMOVE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LVREMOVE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lvremove_2 (guestfs_h *g)
{
  if (test_lvremove_2_skip ()) {
    skipped ("test_lvremove_2", "environment variable set");
    return 0;
  }

  const char *_features2269[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2269)) {
    skipped ("test_lvremove_2", "group %s not available in daemon",
             _features2269[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvremove (2) */
  const char *_arg2270 = "/dev/sda";
  const char *_arg2271 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2270, _arg2271);
  if (ret6 == -1)
    return -1;
  const char *_arg2273 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2273);
  if (ret5 == -1)
    return -1;
  const char *_arg2275 = "VG";
  const char *_arg2276_0 = "/dev/sda1";
  const char *const _arg2276[] = {
    _arg2276_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2275, (char **) _arg2276);
  if (ret4 == -1)
    return -1;
  const char *_arg2278 = "LV1";
  const char *_arg2279 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2278, _arg2279, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2282 = "LV2";
  const char *_arg2283 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2282, _arg2283, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2286 = "/dev/VG";
  int ret1;
  ret1 = guestfs_lvremove (g, _arg2286);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_vgs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 1, "VG"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_lvremove_2", "is_string_list (ret, 1, \"VG\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_mount_ro_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mount_ro") == NULL;
  str = getenv ("SKIP_TEST_MOUNT_RO_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MOUNT_RO");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mount_ro_0 (guestfs_h *g)
{
  if (test_mount_ro_0_skip ()) {
    skipped ("test_mount_ro_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestLastFail for mount_ro (0) */
  const char *_arg2290 = "/";
  struct guestfs_umount_opts_argv _optargs2291;
  _optargs2291.force = 0;
  _optargs2291.lazyunmount = 0;
  _optargs2291.bitmask = UINT64_C(0x3);
  int _ret2289;
  _ret2289 = guestfs_umount_opts_argv (g, _arg2290, &_optargs2291);
  if (_ret2289 == -1)
    return -1;
  const char *_arg2293 = "/dev/sda1";
  const char *_arg2294 = "/";
  int _ret2292;
  _ret2292 = guestfs_mount_ro (g, _arg2293, _arg2294);
  if (_ret2292 == -1)
    return -1;
  const char *_arg2297 = "/new";
  int _ret2296;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2296 = guestfs_touch (g, _arg2297);
  guestfs_pop_error_handler (g);
  if (_ret2296 != -1)
    return -1;
  return 0;
}

static int
test_mount_ro_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mount_ro") == NULL;
  str = getenv ("SKIP_TEST_MOUNT_RO_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MOUNT_RO");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mount_ro_1 (guestfs_h *g)
{
  if (test_mount_ro_1_skip ()) {
    skipped ("test_mount_ro_1", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResultString for mount_ro (1) */
  const char *_arg2300 = "/new";
  const char *_arg2301 = "data";
  size_t _arg2301_size = 4;
  int _ret2299;
  _ret2299 = guestfs_write (g, _arg2300, _arg2301, _arg2301_size);
  if (_ret2299 == -1)
    return -1;
  const char *_arg2304 = "/";
  struct guestfs_umount_opts_argv _optargs2305;
  _optargs2305.force = 0;
  _optargs2305.lazyunmount = 0;
  _optargs2305.bitmask = UINT64_C(0x3);
  int _ret2303;
  _ret2303 = guestfs_umount_opts_argv (g, _arg2304, &_optargs2305);
  if (_ret2303 == -1)
    return -1;
  const char *_arg2307 = "/dev/sda1";
  const char *_arg2308 = "/";
  int _ret2306;
  _ret2306 = guestfs_mount_ro (g, _arg2307, _arg2308);
  if (_ret2306 == -1)
    return -1;
  const char *_arg2310 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2310);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "data")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mount_ro_1", "cat", ret, "data");
    return -1;
  }
  return 0;
}

static int
test_tgz_in_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "tgz_in") == NULL;
  str = getenv ("SKIP_TEST_TGZ_IN_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TGZ_IN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_tgz_in_0 (guestfs_h *g)
{
  if (test_tgz_in_0_skip ()) {
    skipped ("test_tgz_in_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for tgz_in (0) */
  const char *_arg2313 = "/tgz_in";
  int _ret2312;
  _ret2312 = guestfs_mkdir (g, _arg2313);
  if (_ret2312 == -1)
    return -1;
  CLEANUP_FREE char *_arg2316 = substitute_srcdir ("$srcdir/../data/helloworld.tar.gz");
  const char *_arg2317 = "/tgz_in";
  int _ret2315;
  _ret2315 = guestfs_tgz_in (g, _arg2316, _arg2317);
  if (_ret2315 == -1)
    return -1;
  const char *_arg2319 = "/tgz_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2319);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "hello\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_tgz_in_0", "cat", ret, "hello\n");
    return -1;
  }
  return 0;
}

static int
test_tar_in_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "tar_in") == NULL;
  str = getenv ("SKIP_TEST_TAR_IN_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TAR_IN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_tar_in_0 (guestfs_h *g)
{
  if (test_tar_in_0_skip ()) {
    skipped ("test_tar_in_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for tar_in (0) */
  const char *_arg2322 = "/tar_in";
  int _ret2321;
  _ret2321 = guestfs_mkdir (g, _arg2322);
  if (_ret2321 == -1)
    return -1;
  CLEANUP_FREE char *_arg2325 = substitute_srcdir ("$srcdir/../data/helloworld.tar");
  const char *_arg2326 = "/tar_in";
  struct guestfs_tar_in_opts_argv _optargs2327;
  _optargs2327.bitmask = UINT64_C(0x0);
  int _ret2324;
  _ret2324 = guestfs_tar_in_opts_argv (g, _arg2325, _arg2326, &_optargs2327);
  if (_ret2324 == -1)
    return -1;
  const char *_arg2328 = "/tar_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2328);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "hello\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_tar_in_0", "cat", ret, "hello\n");
    return -1;
  }
  return 0;
}

static int
test_tar_in_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "tar_in") == NULL;
  str = getenv ("SKIP_TEST_TAR_IN_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TAR_IN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_tar_in_1 (guestfs_h *g)
{
  if (test_tar_in_1_skip ()) {
    skipped ("test_tar_in_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for tar_in (1) */
  const char *_arg2331 = "/tar_in_gz";
  int _ret2330;
  _ret2330 = guestfs_mkdir (g, _arg2331);
  if (_ret2330 == -1)
    return -1;
  CLEANUP_FREE char *_arg2334 = substitute_srcdir ("$srcdir/../data/helloworld.tar.gz");
  const char *_arg2335 = "/tar_in_gz";
  struct guestfs_tar_in_opts_argv _optargs2336;
  _optargs2336.compress = "gzip";
  _optargs2336.bitmask = UINT64_C(0x1);
  int _ret2333;
  _ret2333 = guestfs_tar_in_opts_argv (g, _arg2334, _arg2335, &_optargs2336);
  if (_ret2333 == -1)
    return -1;
  const char *_arg2337 = "/tar_in_gz/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2337);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "hello\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_tar_in_1", "cat", ret, "hello\n");
    return -1;
  }
  return 0;
}

static int
test_tar_in_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "tar_in") == NULL;
  str = getenv ("SKIP_TEST_TAR_IN_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TAR_IN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_tar_in_2 (guestfs_h *g)
{
  if (test_tar_in_2_skip ()) {
    skipped ("test_tar_in_2", "environment variable set");
    return 0;
  }

  const char *_features2339[] = { "xz", NULL };
  if (!guestfs_feature_available (g, (char **) _features2339)) {
    skipped ("test_tar_in_2", "group %s not available in daemon",
             _features2339[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for tar_in (2) */
  const char *_arg2341 = "/tar_in_xz";
  int _ret2340;
  _ret2340 = guestfs_mkdir (g, _arg2341);
  if (_ret2340 == -1)
    return -1;
  CLEANUP_FREE char *_arg2344 = substitute_srcdir ("$srcdir/../data/helloworld.tar.xz");
  const char *_arg2345 = "/tar_in_xz";
  struct guestfs_tar_in_opts_argv _optargs2346;
  _optargs2346.compress = "xz";
  _optargs2346.bitmask = UINT64_C(0x1);
  int _ret2343;
  _ret2343 = guestfs_tar_in_opts_argv (g, _arg2344, _arg2345, &_optargs2346);
  if (_ret2343 == -1)
    return -1;
  const char *_arg2347 = "/tar_in_xz/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2347);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "hello\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_tar_in_2", "cat", ret, "hello\n");
    return -1;
  }
  return 0;
}

static int
test_checksum_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "checksum") == NULL;
  str = getenv ("SKIP_TEST_CHECKSUM_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CHECKSUM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_checksum_0 (guestfs_h *g)
{
  if (test_checksum_0_skip ()) {
    skipped ("test_checksum_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for checksum (0) */
  const char *_arg2349 = "crc";
  const char *_arg2350 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2349, _arg2350);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "2891671662")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_0", "checksum", ret, "2891671662");
    return -1;
  }
  return 0;
}

static int
test_checksum_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "checksum") == NULL;
  str = getenv ("SKIP_TEST_CHECKSUM_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CHECKSUM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_checksum_1 (guestfs_h *g)
{
  if (test_checksum_1_skip ()) {
    skipped ("test_checksum_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestLastFail for checksum (1) */
  const char *_arg2353 = "crc";
  const char *_arg2354 = "/notexists";
  CLEANUP_FREE char *_ret2352;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2352 = guestfs_checksum (g, _arg2353, _arg2354);
  guestfs_pop_error_handler (g);
  if (_ret2352 != NULL)
    return -1;
  return 0;
}

static int
test_checksum_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "checksum") == NULL;
  str = getenv ("SKIP_TEST_CHECKSUM_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CHECKSUM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_checksum_2 (guestfs_h *g)
{
  if (test_checksum_2_skip ()) {
    skipped ("test_checksum_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for checksum (2) */
  const char *_arg2356 = "md5";
  const char *_arg2357 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2356, _arg2357);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "46d6ca27ee07cdc6fa99c2e138cc522c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_2", "checksum", ret, "46d6ca27ee07cdc6fa99c2e138cc522c");
    return -1;
  }
  return 0;
}

static int
test_checksum_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "checksum") == NULL;
  str = getenv ("SKIP_TEST_CHECKSUM_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CHECKSUM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_checksum_3 (guestfs_h *g)
{
  if (test_checksum_3_skip ()) {
    skipped ("test_checksum_3", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for checksum (3) */
  const char *_arg2359 = "sha1";
  const char *_arg2360 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2359, _arg2360);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "b7ebccc3ee418311091c3eda0a45b83c0a770f15")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_3", "checksum", ret, "b7ebccc3ee418311091c3eda0a45b83c0a770f15");
    return -1;
  }
  return 0;
}

static int
test_checksum_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "checksum") == NULL;
  str = getenv ("SKIP_TEST_CHECKSUM_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CHECKSUM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_checksum_4 (guestfs_h *g)
{
  if (test_checksum_4_skip ()) {
    skipped ("test_checksum_4", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for checksum (4) */
  const char *_arg2362 = "sha224";
  const char *_arg2363 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2362, _arg2363);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "d2cd1774b28f3659c14116be0a6dc2bb5c4b350ce9cd5defac707741")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_4", "checksum", ret, "d2cd1774b28f3659c14116be0a6dc2bb5c4b350ce9cd5defac707741");
    return -1;
  }
  return 0;
}

static int
test_checksum_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "checksum") == NULL;
  str = getenv ("SKIP_TEST_CHECKSUM_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CHECKSUM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_checksum_5 (guestfs_h *g)
{
  if (test_checksum_5_skip ()) {
    skipped ("test_checksum_5", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for checksum (5) */
  const char *_arg2365 = "sha256";
  const char *_arg2366 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2365, _arg2366);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "75bb71b90cd20cb13f86d2bea8dad63ac7194e7517c3b52b8d06ff52d3487d30")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_5", "checksum", ret, "75bb71b90cd20cb13f86d2bea8dad63ac7194e7517c3b52b8d06ff52d3487d30");
    return -1;
  }
  return 0;
}

static int
test_checksum_6_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "checksum") == NULL;
  str = getenv ("SKIP_TEST_CHECKSUM_6");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CHECKSUM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_checksum_6 (guestfs_h *g)
{
  if (test_checksum_6_skip ()) {
    skipped ("test_checksum_6", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for checksum (6) */
  const char *_arg2368 = "sha384";
  const char *_arg2369 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2368, _arg2369);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "5fa7883430f357b5d7b7271d3a1d2872b51d73cba72731de6863d3dea55f30646af2799bef44d5ea776a5ec7941ac640")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_6", "checksum", ret, "5fa7883430f357b5d7b7271d3a1d2872b51d73cba72731de6863d3dea55f30646af2799bef44d5ea776a5ec7941ac640");
    return -1;
  }
  return 0;
}

static int
test_checksum_7_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "checksum") == NULL;
  str = getenv ("SKIP_TEST_CHECKSUM_7");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CHECKSUM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_checksum_7 (guestfs_h *g)
{
  if (test_checksum_7_skip ()) {
    skipped ("test_checksum_7", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for checksum (7) */
  const char *_arg2371 = "sha512";
  const char *_arg2372 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2371, _arg2372);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "2794062c328c6b216dca90443b7f7134c5f40e56bd0ed7853123275a09982a6f992e6ca682f9d2fba34a4c5e870d8fe077694ff831e3032a004ee077e00603f6")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_7", "checksum", ret, "2794062c328c6b216dca90443b7f7134c5f40e56bd0ed7853123275a09982a6f992e6ca682f9d2fba34a4c5e870d8fe077694ff831e3032a004ee077e00603f6");
    return -1;
  }
  return 0;
}

static int
test_checksum_8_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "checksum") == NULL;
  str = getenv ("SKIP_TEST_CHECKSUM_8");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CHECKSUM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_checksum_8 (guestfs_h *g)
{
  if (test_checksum_8_skip ()) {
    skipped ("test_checksum_8", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for checksum (8) */
  const char *_arg2374 = "sha512";
  const char *_arg2375 = "/abssymlink";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2374, _arg2375);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "5f57d0639bc95081c53afc63a449403883818edc64da48930ad6b1a4fb49be90404686877743fbcd7c99811f3def7df7bc22635c885c6a8cf79c806b43451c1a")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_8", "checksum", ret, "5f57d0639bc95081c53afc63a449403883818edc64da48930ad6b1a4fb49be90404686877743fbcd7c99811f3def7df7bc22635c885c6a8cf79c806b43451c1a");
    return -1;
  }
  return 0;
}

static int
test_download_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "download") == NULL;
  str = getenv ("SKIP_TEST_DOWNLOAD_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DOWNLOAD");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_download_0 (guestfs_h *g)
{
  if (test_download_0_skip ()) {
    skipped ("test_download_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for download (0) */
  const char *_arg2378 = "/download";
  int _ret2377;
  _ret2377 = guestfs_mkdir (g, _arg2378);
  if (_ret2377 == -1)
    return -1;
  CLEANUP_FREE char *_arg2381 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *_arg2382 = "/download/COPYING.LIB";
  int _ret2380;
  _ret2380 = guestfs_upload (g, _arg2381, _arg2382);
  if (_ret2380 == -1)
    return -1;
  const char *_arg2385 = "/download/COPYING.LIB";
  int _ret2384;
  _ret2384 = guestfs_download (g, _arg2385, "testdownload.tmp");
  if (_ret2384 == -1)
    return -1;
  CLEANUP_FREE char *_arg2389 = substitute_srcdir ("testdownload.tmp");
  const char *_arg2390 = "/download/upload";
  int _ret2388;
  _ret2388 = guestfs_upload (g, _arg2389, _arg2390);
  if (_ret2388 == -1)
    return -1;
  const char *_arg2392 = "md5";
  const char *_arg2393 = "/download/upload";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2392, _arg2393);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "4fbd65380cdd255951079008b364516c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_download_0", "checksum", ret, "4fbd65380cdd255951079008b364516c");
    return -1;
  }
  return 0;
}

static int
test_upload_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "upload") == NULL;
  str = getenv ("SKIP_TEST_UPLOAD_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UPLOAD");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_upload_0 (guestfs_h *g)
{
  if (test_upload_0_skip ()) {
    skipped ("test_upload_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for upload (0) */
  const char *_arg2396 = "/upload";
  int _ret2395;
  _ret2395 = guestfs_mkdir (g, _arg2396);
  if (_ret2395 == -1)
    return -1;
  CLEANUP_FREE char *_arg2399 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *_arg2400 = "/upload/COPYING.LIB";
  int _ret2398;
  _ret2398 = guestfs_upload (g, _arg2399, _arg2400);
  if (_ret2398 == -1)
    return -1;
  const char *_arg2402 = "md5";
  const char *_arg2403 = "/upload/COPYING.LIB";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2402, _arg2403);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "4fbd65380cdd255951079008b364516c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_upload_0", "checksum", ret, "4fbd65380cdd255951079008b364516c");
    return -1;
  }
  return 0;
}

static int
test_blockdev_rereadpt_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "blockdev_rereadpt") == NULL;
  str = getenv ("SKIP_TEST_BLOCKDEV_REREADPT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BLOCKDEV_REREADPT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_blockdev_rereadpt_0 (guestfs_h *g)
{
  if (test_blockdev_rereadpt_0_skip ()) {
    skipped ("test_blockdev_rereadpt_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for blockdev_rereadpt (0) */
  const char *_arg2406 = "/dev/sda";
  int _ret2405;
  _ret2405 = guestfs_blockdev_rereadpt (g, _arg2406);
  if (_ret2405 == -1)
    return -1;
  return 0;
}

static int
test_blockdev_flushbufs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "blockdev_flushbufs") == NULL;
  str = getenv ("SKIP_TEST_BLOCKDEV_FLUSHBUFS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BLOCKDEV_FLUSHBUFS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_blockdev_flushbufs_0 (guestfs_h *g)
{
  if (test_blockdev_flushbufs_0_skip ()) {
    skipped ("test_blockdev_flushbufs_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for blockdev_flushbufs (0) */
  const char *_arg2409 = "/dev/sda";
  int _ret2408;
  _ret2408 = guestfs_blockdev_flushbufs (g, _arg2409);
  if (_ret2408 == -1)
    return -1;
  return 0;
}

static int
test_blockdev_getsize64_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "blockdev_getsize64") == NULL;
  str = getenv ("SKIP_TEST_BLOCKDEV_GETSIZE64_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BLOCKDEV_GETSIZE64");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_blockdev_getsize64_0 (guestfs_h *g)
{
  if (test_blockdev_getsize64_0_skip ()) {
    skipped ("test_blockdev_getsize64_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for blockdev_getsize64 (0) */
  const char *_arg2411 = "/dev/sda";
  int64_t ret;
  ret = guestfs_blockdev_getsize64 (g, _arg2411);
  if (ret == -1)
    return -1;
  if (! (ret == UINT64_C (524288000))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_blockdev_getsize64_0", "ret == UINT64_C (524288000)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_blockdev_getsz_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "blockdev_getsz") == NULL;
  str = getenv ("SKIP_TEST_BLOCKDEV_GETSZ_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BLOCKDEV_GETSZ");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_blockdev_getsz_0 (guestfs_h *g)
{
  if (test_blockdev_getsz_0_skip ()) {
    skipped ("test_blockdev_getsz_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for blockdev_getsz (0) */
  const char *_arg2413 = "/dev/sda";
  int64_t ret;
  ret = guestfs_blockdev_getsz (g, _arg2413);
  if (ret == -1)
    return -1;
  if (! (ret == 1024000)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_blockdev_getsz_0", "ret == 1024000");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_blockdev_getss_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "blockdev_getss") == NULL;
  str = getenv ("SKIP_TEST_BLOCKDEV_GETSS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BLOCKDEV_GETSS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_blockdev_getss_0 (guestfs_h *g)
{
  if (test_blockdev_getss_0_skip ()) {
    skipped ("test_blockdev_getss_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for blockdev_getss (0) */
  const char *_arg2415 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getss (g, _arg2415);
  if (ret == -1)
    return -1;
  if (! (ret == 512)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_blockdev_getss_0", "ret == 512");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_blockdev_getro_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "blockdev_getro") == NULL;
  str = getenv ("SKIP_TEST_BLOCKDEV_GETRO_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BLOCKDEV_GETRO");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_blockdev_getro_0 (guestfs_h *g)
{
  if (test_blockdev_getro_0_skip ()) {
    skipped ("test_blockdev_getro_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultTrue for blockdev_getro (0) */
  const char *_arg2418 = "/dev/sda";
  int _ret2417;
  _ret2417 = guestfs_blockdev_setro (g, _arg2418);
  if (_ret2417 == -1)
    return -1;
  const char *_arg2420 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, _arg2420);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_blockdev_getro_0", "blockdev_getro");
    return -1;
  }
  return 0;
}

static int
test_blockdev_setrw_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "blockdev_setrw") == NULL;
  str = getenv ("SKIP_TEST_BLOCKDEV_SETRW_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BLOCKDEV_SETRW");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_blockdev_setrw_0 (guestfs_h *g)
{
  if (test_blockdev_setrw_0_skip ()) {
    skipped ("test_blockdev_setrw_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultFalse for blockdev_setrw (0) */
  const char *_arg2423 = "/dev/sda";
  int _ret2422;
  _ret2422 = guestfs_blockdev_setrw (g, _arg2423);
  if (_ret2422 == -1)
    return -1;
  const char *_arg2425 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, _arg2425);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_blockdev_setrw_0", "blockdev_getro");
    return -1;
  }
  return 0;
}

static int
test_blockdev_setro_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "blockdev_setro") == NULL;
  str = getenv ("SKIP_TEST_BLOCKDEV_SETRO_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BLOCKDEV_SETRO");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_blockdev_setro_0 (guestfs_h *g)
{
  if (test_blockdev_setro_0_skip ()) {
    skipped ("test_blockdev_setro_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultTrue for blockdev_setro (0) */
  const char *_arg2428 = "/dev/sda";
  int _ret2427;
  _ret2427 = guestfs_blockdev_setro (g, _arg2428);
  if (_ret2427 == -1)
    return -1;
  const char *_arg2430 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, _arg2430);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_blockdev_setro_0", "blockdev_getro");
    return -1;
  }
  return 0;
}

static int
test_tune2fs_l_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "tune2fs_l") == NULL;
  str = getenv ("SKIP_TEST_TUNE2FS_L_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TUNE2FS_L");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_tune2fs_l_0 (guestfs_h *g)
{
  if (test_tune2fs_l_0_skip ()) {
    skipped ("test_tune2fs_l_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for tune2fs_l (0) */
  const char *_arg2432 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg2432);
  if (ret == NULL)
      return -1;
  if (! (check_hash (ret, "Filesystem magic number", "0xEF53") == 0 && check_hash (ret, "Filesystem OS type", "Linux") == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_tune2fs_l_0", "check_hash (ret, \"Filesystem magic number\", \"0xEF53\") == 0 && check_hash (ret, \"Filesystem OS type\", \"Linux\") == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_statvfs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "statvfs") == NULL;
  str = getenv ("SKIP_TEST_STATVFS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_STATVFS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_statvfs_0 (guestfs_h *g)
{
  if (test_statvfs_0_skip ()) {
    skipped ("test_statvfs_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for statvfs (0) */
  const char *_arg2434 = "/";
  CLEANUP_FREE_STATVFS struct guestfs_statvfs *ret;
  ret = guestfs_statvfs (g, _arg2434);
  if (ret == NULL)
      return -1;
  if (! (ret->namemax == 255)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_statvfs_0", "ret->namemax == 255");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_lstat_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lstat") == NULL;
  str = getenv ("SKIP_TEST_LSTAT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LSTAT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lstat_0 (guestfs_h *g)
{
  if (test_lstat_0_skip ()) {
    skipped ("test_lstat_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for lstat (0) */
  const char *_arg2436 = "/empty";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_lstat (g, _arg2436);
  if (ret == NULL)
      return -1;
  if (! (ret->size == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_lstat_0", "ret->size == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_stat_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "stat") == NULL;
  str = getenv ("SKIP_TEST_STAT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_STAT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_stat_0 (guestfs_h *g)
{
  if (test_stat_0_skip ()) {
    skipped ("test_stat_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for stat (0) */
  const char *_arg2438 = "/empty";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg2438);
  if (ret == NULL)
      return -1;
  if (! (ret->size == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_stat_0", "ret->size == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_command_lines_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command_lines") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_LINES_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_lines_0 (guestfs_h *g)
{
  if (test_command_lines_0_skip ()) {
    skipped ("test_command_lines_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for command_lines (0) */
  const char *_arg2440 = "/command_lines";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2440);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2442 = substitute_srcdir ("test-command");
  const char *_arg2443 = "/command_lines/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2442, _arg2443);
  if (ret2 == -1)
    return -1;
  const char *_arg2446 = "/command_lines/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2446);
  if (ret1 == -1)
    return -1;
  const char *_arg2448_0 = "/command_lines/test-command";
  const char *_arg2448_1 = "1";
  const char *const _arg2448[] = {
    _arg2448_0,
    _arg2448_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2448);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 1, "Result1"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_command_lines_0", "is_string_list (ret, 1, \"Result1\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_command_lines_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command_lines") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_LINES_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_lines_1 (guestfs_h *g)
{
  if (test_command_lines_1_skip ()) {
    skipped ("test_command_lines_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for command_lines (1) */
  const char *_arg2450 = "/command_lines2";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2450);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2452 = substitute_srcdir ("test-command");
  const char *_arg2453 = "/command_lines2/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2452, _arg2453);
  if (ret2 == -1)
    return -1;
  const char *_arg2456 = "/command_lines2/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2456);
  if (ret1 == -1)
    return -1;
  const char *_arg2458_0 = "/command_lines2/test-command";
  const char *_arg2458_1 = "2";
  const char *const _arg2458[] = {
    _arg2458_0,
    _arg2458_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2458);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 1, "Result2"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_command_lines_1", "is_string_list (ret, 1, \"Result2\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_command_lines_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command_lines") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_LINES_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_lines_2 (guestfs_h *g)
{
  if (test_command_lines_2_skip ()) {
    skipped ("test_command_lines_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for command_lines (2) */
  const char *_arg2460 = "/command_lines3";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2460);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2462 = substitute_srcdir ("test-command");
  const char *_arg2463 = "/command_lines3/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2462, _arg2463);
  if (ret2 == -1)
    return -1;
  const char *_arg2466 = "/command_lines3/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2466);
  if (ret1 == -1)
    return -1;
  const char *_arg2468_0 = "/command_lines3/test-command";
  const char *_arg2468_1 = "3";
  const char *const _arg2468[] = {
    _arg2468_0,
    _arg2468_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2468);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "", "Result3"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_command_lines_2", "is_string_list (ret, 2, \"\", \"Result3\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_command_lines_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command_lines") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_LINES_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_lines_3 (guestfs_h *g)
{
  if (test_command_lines_3_skip ()) {
    skipped ("test_command_lines_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for command_lines (3) */
  const char *_arg2470 = "/command_lines4";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2470);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2472 = substitute_srcdir ("test-command");
  const char *_arg2473 = "/command_lines4/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2472, _arg2473);
  if (ret2 == -1)
    return -1;
  const char *_arg2476 = "/command_lines4/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2476);
  if (ret1 == -1)
    return -1;
  const char *_arg2478_0 = "/command_lines4/test-command";
  const char *_arg2478_1 = "4";
  const char *const _arg2478[] = {
    _arg2478_0,
    _arg2478_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2478);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "", "Result4"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_command_lines_3", "is_string_list (ret, 2, \"\", \"Result4\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_command_lines_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command_lines") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_LINES_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_lines_4 (guestfs_h *g)
{
  if (test_command_lines_4_skip ()) {
    skipped ("test_command_lines_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for command_lines (4) */
  const char *_arg2480 = "/command_lines5";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2480);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2482 = substitute_srcdir ("test-command");
  const char *_arg2483 = "/command_lines5/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2482, _arg2483);
  if (ret2 == -1)
    return -1;
  const char *_arg2486 = "/command_lines5/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2486);
  if (ret1 == -1)
    return -1;
  const char *_arg2488_0 = "/command_lines5/test-command";
  const char *_arg2488_1 = "5";
  const char *const _arg2488[] = {
    _arg2488_0,
    _arg2488_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2488);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "", "Result5", ""))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_command_lines_4", "is_string_list (ret, 3, \"\", \"Result5\", \"\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_command_lines_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command_lines") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_LINES_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_lines_5 (guestfs_h *g)
{
  if (test_command_lines_5_skip ()) {
    skipped ("test_command_lines_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for command_lines (5) */
  const char *_arg2490 = "/command_lines6";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2490);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2492 = substitute_srcdir ("test-command");
  const char *_arg2493 = "/command_lines6/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2492, _arg2493);
  if (ret2 == -1)
    return -1;
  const char *_arg2496 = "/command_lines6/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2496);
  if (ret1 == -1)
    return -1;
  const char *_arg2498_0 = "/command_lines6/test-command";
  const char *_arg2498_1 = "6";
  const char *const _arg2498[] = {
    _arg2498_0,
    _arg2498_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2498);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 4, "", "", "Result6", ""))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_command_lines_5", "is_string_list (ret, 4, \"\", \"\", \"Result6\", \"\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_command_lines_6_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command_lines") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_LINES_6");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_lines_6 (guestfs_h *g)
{
  if (test_command_lines_6_skip ()) {
    skipped ("test_command_lines_6", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for command_lines (6) */
  const char *_arg2500 = "/command_lines7";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2500);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2502 = substitute_srcdir ("test-command");
  const char *_arg2503 = "/command_lines7/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2502, _arg2503);
  if (ret2 == -1)
    return -1;
  const char *_arg2506 = "/command_lines7/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2506);
  if (ret1 == -1)
    return -1;
  const char *_arg2508_0 = "/command_lines7/test-command";
  const char *_arg2508_1 = "7";
  const char *const _arg2508[] = {
    _arg2508_0,
    _arg2508_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2508);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_command_lines_6", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_command_lines_7_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command_lines") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_LINES_7");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_lines_7 (guestfs_h *g)
{
  if (test_command_lines_7_skip ()) {
    skipped ("test_command_lines_7", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for command_lines (7) */
  const char *_arg2510 = "/command_lines8";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2510);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2512 = substitute_srcdir ("test-command");
  const char *_arg2513 = "/command_lines8/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2512, _arg2513);
  if (ret2 == -1)
    return -1;
  const char *_arg2516 = "/command_lines8/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2516);
  if (ret1 == -1)
    return -1;
  const char *_arg2518_0 = "/command_lines8/test-command";
  const char *_arg2518_1 = "8";
  const char *const _arg2518[] = {
    _arg2518_0,
    _arg2518_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2518);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 1, ""))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_command_lines_7", "is_string_list (ret, 1, \"\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_command_lines_8_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command_lines") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_LINES_8");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_lines_8 (guestfs_h *g)
{
  if (test_command_lines_8_skip ()) {
    skipped ("test_command_lines_8", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for command_lines (8) */
  const char *_arg2520 = "/command_lines9";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2520);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2522 = substitute_srcdir ("test-command");
  const char *_arg2523 = "/command_lines9/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2522, _arg2523);
  if (ret2 == -1)
    return -1;
  const char *_arg2526 = "/command_lines9/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2526);
  if (ret1 == -1)
    return -1;
  const char *_arg2528_0 = "/command_lines9/test-command";
  const char *_arg2528_1 = "9";
  const char *const _arg2528[] = {
    _arg2528_0,
    _arg2528_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2528);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "", ""))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_command_lines_8", "is_string_list (ret, 2, \"\", \"\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_command_lines_9_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command_lines") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_LINES_9");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_lines_9 (guestfs_h *g)
{
  if (test_command_lines_9_skip ()) {
    skipped ("test_command_lines_9", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for command_lines (9) */
  const char *_arg2530 = "/command_lines10";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2530);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2532 = substitute_srcdir ("test-command");
  const char *_arg2533 = "/command_lines10/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2532, _arg2533);
  if (ret2 == -1)
    return -1;
  const char *_arg2536 = "/command_lines10/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2536);
  if (ret1 == -1)
    return -1;
  const char *_arg2538_0 = "/command_lines10/test-command";
  const char *_arg2538_1 = "10";
  const char *const _arg2538[] = {
    _arg2538_0,
    _arg2538_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2538);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "Result10-1", "Result10-2"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_command_lines_9", "is_string_list (ret, 2, \"Result10-1\", \"Result10-2\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_command_lines_10_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command_lines") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_LINES_10");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_lines_10 (guestfs_h *g)
{
  if (test_command_lines_10_skip ()) {
    skipped ("test_command_lines_10", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for command_lines (10) */
  const char *_arg2540 = "/command_lines11";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2540);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2542 = substitute_srcdir ("test-command");
  const char *_arg2543 = "/command_lines11/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2542, _arg2543);
  if (ret2 == -1)
    return -1;
  const char *_arg2546 = "/command_lines11/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2546);
  if (ret1 == -1)
    return -1;
  const char *_arg2548_0 = "/command_lines11/test-command";
  const char *_arg2548_1 = "11";
  const char *const _arg2548[] = {
    _arg2548_0,
    _arg2548_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2548);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "Result11-1", "Result11-2"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_command_lines_10", "is_string_list (ret, 2, \"Result11-1\", \"Result11-2\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_command_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_0 (guestfs_h *g)
{
  if (test_command_0_skip ()) {
    skipped ("test_command_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for command (0) */
  const char *_arg2551 = "/command";
  int _ret2550;
  _ret2550 = guestfs_mkdir (g, _arg2551);
  if (_ret2550 == -1)
    return -1;
  CLEANUP_FREE char *_arg2554 = substitute_srcdir ("test-command");
  const char *_arg2555 = "/command/test-command";
  int _ret2553;
  _ret2553 = guestfs_upload (g, _arg2554, _arg2555);
  if (_ret2553 == -1)
    return -1;
  const char *_arg2559 = "/command/test-command";
  int _ret2557;
  _ret2557 = guestfs_chmod (g, 493, _arg2559);
  if (_ret2557 == -1)
    return -1;
  const char *_arg2561_0 = "/command/test-command";
  const char *_arg2561_1 = "1";
  const char *const _arg2561[] = {
    _arg2561_0,
    _arg2561_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2561);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "Result1")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_0", "command", ret, "Result1");
    return -1;
  }
  return 0;
}

static int
test_command_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_1 (guestfs_h *g)
{
  if (test_command_1_skip ()) {
    skipped ("test_command_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for command (1) */
  const char *_arg2564 = "/command2";
  int _ret2563;
  _ret2563 = guestfs_mkdir (g, _arg2564);
  if (_ret2563 == -1)
    return -1;
  CLEANUP_FREE char *_arg2567 = substitute_srcdir ("test-command");
  const char *_arg2568 = "/command2/test-command";
  int _ret2566;
  _ret2566 = guestfs_upload (g, _arg2567, _arg2568);
  if (_ret2566 == -1)
    return -1;
  const char *_arg2572 = "/command2/test-command";
  int _ret2570;
  _ret2570 = guestfs_chmod (g, 493, _arg2572);
  if (_ret2570 == -1)
    return -1;
  const char *_arg2574_0 = "/command2/test-command";
  const char *_arg2574_1 = "2";
  const char *const _arg2574[] = {
    _arg2574_0,
    _arg2574_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2574);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "Result2\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_1", "command", ret, "Result2\n");
    return -1;
  }
  return 0;
}

static int
test_command_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_2 (guestfs_h *g)
{
  if (test_command_2_skip ()) {
    skipped ("test_command_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for command (2) */
  const char *_arg2577 = "/command3";
  int _ret2576;
  _ret2576 = guestfs_mkdir (g, _arg2577);
  if (_ret2576 == -1)
    return -1;
  CLEANUP_FREE char *_arg2580 = substitute_srcdir ("test-command");
  const char *_arg2581 = "/command3/test-command";
  int _ret2579;
  _ret2579 = guestfs_upload (g, _arg2580, _arg2581);
  if (_ret2579 == -1)
    return -1;
  const char *_arg2585 = "/command3/test-command";
  int _ret2583;
  _ret2583 = guestfs_chmod (g, 493, _arg2585);
  if (_ret2583 == -1)
    return -1;
  const char *_arg2587_0 = "/command3/test-command";
  const char *_arg2587_1 = "3";
  const char *const _arg2587[] = {
    _arg2587_0,
    _arg2587_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2587);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\nResult3")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_2", "command", ret, "\nResult3");
    return -1;
  }
  return 0;
}

static int
test_command_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_3 (guestfs_h *g)
{
  if (test_command_3_skip ()) {
    skipped ("test_command_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for command (3) */
  const char *_arg2590 = "/command4";
  int _ret2589;
  _ret2589 = guestfs_mkdir (g, _arg2590);
  if (_ret2589 == -1)
    return -1;
  CLEANUP_FREE char *_arg2593 = substitute_srcdir ("test-command");
  const char *_arg2594 = "/command4/test-command";
  int _ret2592;
  _ret2592 = guestfs_upload (g, _arg2593, _arg2594);
  if (_ret2592 == -1)
    return -1;
  const char *_arg2598 = "/command4/test-command";
  int _ret2596;
  _ret2596 = guestfs_chmod (g, 493, _arg2598);
  if (_ret2596 == -1)
    return -1;
  const char *_arg2600_0 = "/command4/test-command";
  const char *_arg2600_1 = "4";
  const char *const _arg2600[] = {
    _arg2600_0,
    _arg2600_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2600);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\nResult4\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_3", "command", ret, "\nResult4\n");
    return -1;
  }
  return 0;
}

static int
test_command_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_4 (guestfs_h *g)
{
  if (test_command_4_skip ()) {
    skipped ("test_command_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for command (4) */
  const char *_arg2603 = "/command5";
  int _ret2602;
  _ret2602 = guestfs_mkdir (g, _arg2603);
  if (_ret2602 == -1)
    return -1;
  CLEANUP_FREE char *_arg2606 = substitute_srcdir ("test-command");
  const char *_arg2607 = "/command5/test-command";
  int _ret2605;
  _ret2605 = guestfs_upload (g, _arg2606, _arg2607);
  if (_ret2605 == -1)
    return -1;
  const char *_arg2611 = "/command5/test-command";
  int _ret2609;
  _ret2609 = guestfs_chmod (g, 493, _arg2611);
  if (_ret2609 == -1)
    return -1;
  const char *_arg2613_0 = "/command5/test-command";
  const char *_arg2613_1 = "5";
  const char *const _arg2613[] = {
    _arg2613_0,
    _arg2613_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2613);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\nResult5\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_4", "command", ret, "\nResult5\n\n");
    return -1;
  }
  return 0;
}

static int
test_command_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_5 (guestfs_h *g)
{
  if (test_command_5_skip ()) {
    skipped ("test_command_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for command (5) */
  const char *_arg2616 = "/command6";
  int _ret2615;
  _ret2615 = guestfs_mkdir (g, _arg2616);
  if (_ret2615 == -1)
    return -1;
  CLEANUP_FREE char *_arg2619 = substitute_srcdir ("test-command");
  const char *_arg2620 = "/command6/test-command";
  int _ret2618;
  _ret2618 = guestfs_upload (g, _arg2619, _arg2620);
  if (_ret2618 == -1)
    return -1;
  const char *_arg2624 = "/command6/test-command";
  int _ret2622;
  _ret2622 = guestfs_chmod (g, 493, _arg2624);
  if (_ret2622 == -1)
    return -1;
  const char *_arg2626_0 = "/command6/test-command";
  const char *_arg2626_1 = "6";
  const char *const _arg2626[] = {
    _arg2626_0,
    _arg2626_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2626);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n\nResult6\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_5", "command", ret, "\n\nResult6\n\n");
    return -1;
  }
  return 0;
}

static int
test_command_6_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_6");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_6 (guestfs_h *g)
{
  if (test_command_6_skip ()) {
    skipped ("test_command_6", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for command (6) */
  const char *_arg2629 = "/command7";
  int _ret2628;
  _ret2628 = guestfs_mkdir (g, _arg2629);
  if (_ret2628 == -1)
    return -1;
  CLEANUP_FREE char *_arg2632 = substitute_srcdir ("test-command");
  const char *_arg2633 = "/command7/test-command";
  int _ret2631;
  _ret2631 = guestfs_upload (g, _arg2632, _arg2633);
  if (_ret2631 == -1)
    return -1;
  const char *_arg2637 = "/command7/test-command";
  int _ret2635;
  _ret2635 = guestfs_chmod (g, 493, _arg2637);
  if (_ret2635 == -1)
    return -1;
  const char *_arg2639_0 = "/command7/test-command";
  const char *_arg2639_1 = "7";
  const char *const _arg2639[] = {
    _arg2639_0,
    _arg2639_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2639);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_6", "command", ret, "");
    return -1;
  }
  return 0;
}

static int
test_command_7_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_7");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_7 (guestfs_h *g)
{
  if (test_command_7_skip ()) {
    skipped ("test_command_7", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for command (7) */
  const char *_arg2642 = "/command8";
  int _ret2641;
  _ret2641 = guestfs_mkdir (g, _arg2642);
  if (_ret2641 == -1)
    return -1;
  CLEANUP_FREE char *_arg2645 = substitute_srcdir ("test-command");
  const char *_arg2646 = "/command8/test-command";
  int _ret2644;
  _ret2644 = guestfs_upload (g, _arg2645, _arg2646);
  if (_ret2644 == -1)
    return -1;
  const char *_arg2650 = "/command8/test-command";
  int _ret2648;
  _ret2648 = guestfs_chmod (g, 493, _arg2650);
  if (_ret2648 == -1)
    return -1;
  const char *_arg2652_0 = "/command8/test-command";
  const char *_arg2652_1 = "8";
  const char *const _arg2652[] = {
    _arg2652_0,
    _arg2652_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2652);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_7", "command", ret, "\n");
    return -1;
  }
  return 0;
}

static int
test_command_8_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_8");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_8 (guestfs_h *g)
{
  if (test_command_8_skip ()) {
    skipped ("test_command_8", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for command (8) */
  const char *_arg2655 = "/command9";
  int _ret2654;
  _ret2654 = guestfs_mkdir (g, _arg2655);
  if (_ret2654 == -1)
    return -1;
  CLEANUP_FREE char *_arg2658 = substitute_srcdir ("test-command");
  const char *_arg2659 = "/command9/test-command";
  int _ret2657;
  _ret2657 = guestfs_upload (g, _arg2658, _arg2659);
  if (_ret2657 == -1)
    return -1;
  const char *_arg2663 = "/command9/test-command";
  int _ret2661;
  _ret2661 = guestfs_chmod (g, 493, _arg2663);
  if (_ret2661 == -1)
    return -1;
  const char *_arg2665_0 = "/command9/test-command";
  const char *_arg2665_1 = "9";
  const char *const _arg2665[] = {
    _arg2665_0,
    _arg2665_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2665);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_8", "command", ret, "\n\n");
    return -1;
  }
  return 0;
}

static int
test_command_9_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_9");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_9 (guestfs_h *g)
{
  if (test_command_9_skip ()) {
    skipped ("test_command_9", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for command (9) */
  const char *_arg2668 = "/command10";
  int _ret2667;
  _ret2667 = guestfs_mkdir (g, _arg2668);
  if (_ret2667 == -1)
    return -1;
  CLEANUP_FREE char *_arg2671 = substitute_srcdir ("test-command");
  const char *_arg2672 = "/command10/test-command";
  int _ret2670;
  _ret2670 = guestfs_upload (g, _arg2671, _arg2672);
  if (_ret2670 == -1)
    return -1;
  const char *_arg2676 = "/command10/test-command";
  int _ret2674;
  _ret2674 = guestfs_chmod (g, 493, _arg2676);
  if (_ret2674 == -1)
    return -1;
  const char *_arg2678_0 = "/command10/test-command";
  const char *_arg2678_1 = "10";
  const char *const _arg2678[] = {
    _arg2678_0,
    _arg2678_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2678);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "Result10-1\nResult10-2\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_9", "command", ret, "Result10-1\nResult10-2\n");
    return -1;
  }
  return 0;
}

static int
test_command_10_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_10");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_10 (guestfs_h *g)
{
  if (test_command_10_skip ()) {
    skipped ("test_command_10", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for command (10) */
  const char *_arg2681 = "/command11";
  int _ret2680;
  _ret2680 = guestfs_mkdir (g, _arg2681);
  if (_ret2680 == -1)
    return -1;
  CLEANUP_FREE char *_arg2684 = substitute_srcdir ("test-command");
  const char *_arg2685 = "/command11/test-command";
  int _ret2683;
  _ret2683 = guestfs_upload (g, _arg2684, _arg2685);
  if (_ret2683 == -1)
    return -1;
  const char *_arg2689 = "/command11/test-command";
  int _ret2687;
  _ret2687 = guestfs_chmod (g, 493, _arg2689);
  if (_ret2687 == -1)
    return -1;
  const char *_arg2691_0 = "/command11/test-command";
  const char *_arg2691_1 = "11";
  const char *const _arg2691[] = {
    _arg2691_0,
    _arg2691_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2691);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "Result11-1\nResult11-2")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_10", "command", ret, "Result11-1\nResult11-2");
    return -1;
  }
  return 0;
}

static int
test_command_11_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_11");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_11 (guestfs_h *g)
{
  if (test_command_11_skip ()) {
    skipped ("test_command_11", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for command (11) */
  const char *_arg2694 = "/command12";
  int _ret2693;
  _ret2693 = guestfs_mkdir (g, _arg2694);
  if (_ret2693 == -1)
    return -1;
  CLEANUP_FREE char *_arg2697 = substitute_srcdir ("test-command");
  const char *_arg2698 = "/command12/test-command";
  int _ret2696;
  _ret2696 = guestfs_upload (g, _arg2697, _arg2698);
  if (_ret2696 == -1)
    return -1;
  const char *_arg2702 = "/command12/test-command";
  int _ret2700;
  _ret2700 = guestfs_chmod (g, 493, _arg2702);
  if (_ret2700 == -1)
    return -1;
  const char *_arg2705_0 = "/command12/test-command";
  const char *const _arg2705[] = {
    _arg2705_0,
    NULL
  };
  CLEANUP_FREE char *_ret2704;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2704 = guestfs_command (g, (char **) _arg2705);
  guestfs_pop_error_handler (g);
  if (_ret2704 != NULL)
    return -1;
  return 0;
}

static int
test_command_12_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "command") == NULL;
  str = getenv ("SKIP_TEST_COMMAND_12");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COMMAND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_command_12 (guestfs_h *g)
{
  if (test_command_12_skip ()) {
    skipped ("test_command_12", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for command (12) */
  const char *_arg2708 = "/pwd";
  int _ret2707;
  _ret2707 = guestfs_mkdir (g, _arg2708);
  if (_ret2707 == -1)
    return -1;
  CLEANUP_FREE char *_arg2711 = substitute_srcdir ("test-pwd");
  const char *_arg2712 = "/pwd/test-pwd";
  int _ret2710;
  _ret2710 = guestfs_upload (g, _arg2711, _arg2712);
  if (_ret2710 == -1)
    return -1;
  const char *_arg2716 = "/pwd/test-pwd";
  int _ret2714;
  _ret2714 = guestfs_chmod (g, 493, _arg2716);
  if (_ret2714 == -1)
    return -1;
  const char *_arg2718_0 = "/pwd/test-pwd";
  const char *const _arg2718[] = {
    _arg2718_0,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2718);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_12", "command", ret, "/");
    return -1;
  }
  return 0;
}

static int
test_file_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file") == NULL;
  str = getenv ("SKIP_TEST_FILE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_0 (guestfs_h *g)
{
  if (test_file_0_skip ()) {
    skipped ("test_file_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file (0) */
  const char *_arg2720 = "/empty";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg2720);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "empty")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_0", "file", ret, "empty");
    return -1;
  }
  return 0;
}

static int
test_file_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file") == NULL;
  str = getenv ("SKIP_TEST_FILE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_1 (guestfs_h *g)
{
  if (test_file_1_skip ()) {
    skipped ("test_file_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file (1) */
  const char *_arg2722 = "/known-1";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg2722);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "ASCII text")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_1", "file", ret, "ASCII text");
    return -1;
  }
  return 0;
}

static int
test_file_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file") == NULL;
  str = getenv ("SKIP_TEST_FILE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_2 (guestfs_h *g)
{
  if (test_file_2_skip ()) {
    skipped ("test_file_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestLastFail for file (2) */
  const char *_arg2725 = "/notexists";
  CLEANUP_FREE char *_ret2724;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2724 = guestfs_file (g, _arg2725);
  guestfs_pop_error_handler (g);
  if (_ret2724 != NULL)
    return -1;
  return 0;
}

static int
test_file_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file") == NULL;
  str = getenv ("SKIP_TEST_FILE_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_3 (guestfs_h *g)
{
  if (test_file_3_skip ()) {
    skipped ("test_file_3", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file (3) */
  const char *_arg2727 = "/abssymlink";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg2727);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "symbolic link")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_3", "file", ret, "symbolic link");
    return -1;
  }
  return 0;
}

static int
test_file_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file") == NULL;
  str = getenv ("SKIP_TEST_FILE_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_4 (guestfs_h *g)
{
  if (test_file_4_skip ()) {
    skipped ("test_file_4", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file (4) */
  const char *_arg2729 = "/directory";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg2729);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "directory")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_4", "file", ret, "directory");
    return -1;
  }
  return 0;
}

static int
test_umount_all_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "umount_all") == NULL;
  str = getenv ("SKIP_TEST_UMOUNT_ALL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UMOUNT_ALL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_umount_all_0 (guestfs_h *g)
{
  if (test_umount_all_0_skip ()) {
    skipped ("test_umount_all_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for umount_all (0) */
  int ret1;
  ret1 = guestfs_umount_all (g);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_mounts (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_umount_all_0", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_umount_all_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "umount_all") == NULL;
  str = getenv ("SKIP_TEST_UMOUNT_ALL_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UMOUNT_ALL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_umount_all_1 (guestfs_h *g)
{
  if (test_umount_all_1_skip ()) {
    skipped ("test_umount_all_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for umount_all (1) */
  const char *_arg2733 = "/dev/sda";
  const char *_arg2734 = "mbr";
  int ret14;
  ret14 = guestfs_part_init (g, _arg2733, _arg2734);
  if (ret14 == -1)
    return -1;
  const char *_arg2736 = "/dev/sda";
  const char *_arg2737 = "p";
  int ret13;
  ret13 = guestfs_part_add (g, _arg2736, _arg2737, 64, 204799);
  if (ret13 == -1)
    return -1;
  const char *_arg2741 = "/dev/sda";
  const char *_arg2742 = "p";
  int ret12;
  ret12 = guestfs_part_add (g, _arg2741, _arg2742, 204800, 409599);
  if (ret12 == -1)
    return -1;
  const char *_arg2746 = "/dev/sda";
  const char *_arg2747 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, _arg2746, _arg2747, 409600, -64);
  if (ret11 == -1)
    return -1;
  const char *_arg2751 = "ext2";
  const char *_arg2752 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs2753;
  _optargs2753.bitmask = UINT64_C(0x0);
  int ret10;
  ret10 = guestfs_mkfs_opts_argv (g, _arg2751, _arg2752, &_optargs2753);
  if (ret10 == -1)
    return -1;
  const char *_arg2754 = "ext2";
  const char *_arg2755 = "/dev/sda2";
  struct guestfs_mkfs_opts_argv _optargs2756;
  _optargs2756.bitmask = UINT64_C(0x0);
  int ret9;
  ret9 = guestfs_mkfs_opts_argv (g, _arg2754, _arg2755, &_optargs2756);
  if (ret9 == -1)
    return -1;
  const char *_arg2757 = "ext2";
  const char *_arg2758 = "/dev/sda3";
  struct guestfs_mkfs_opts_argv _optargs2759;
  _optargs2759.bitmask = UINT64_C(0x0);
  int ret8;
  ret8 = guestfs_mkfs_opts_argv (g, _arg2757, _arg2758, &_optargs2759);
  if (ret8 == -1)
    return -1;
  const char *_arg2760 = "/dev/sda1";
  const char *_arg2761 = "/";
  int ret7;
  ret7 = guestfs_mount (g, _arg2760, _arg2761);
  if (ret7 == -1)
    return -1;
  const char *_arg2763 = "/mp1";
  int ret6;
  ret6 = guestfs_mkdir (g, _arg2763);
  if (ret6 == -1)
    return -1;
  const char *_arg2765 = "/dev/sda2";
  const char *_arg2766 = "/mp1";
  int ret5;
  ret5 = guestfs_mount (g, _arg2765, _arg2766);
  if (ret5 == -1)
    return -1;
  const char *_arg2768 = "/mp1/mp2";
  int ret4;
  ret4 = guestfs_mkdir (g, _arg2768);
  if (ret4 == -1)
    return -1;
  const char *_arg2770 = "/dev/sda3";
  const char *_arg2771 = "/mp1/mp2";
  int ret3;
  ret3 = guestfs_mount (g, _arg2770, _arg2771);
  if (ret3 == -1)
    return -1;
  const char *_arg2773 = "/mp1/mp2/mp3";
  int ret2;
  ret2 = guestfs_mkdir (g, _arg2773);
  if (ret2 == -1)
    return -1;
  int ret1;
  ret1 = guestfs_umount_all (g);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_mounts (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_umount_all_1", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_mounts_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mounts") == NULL;
  str = getenv ("SKIP_TEST_MOUNTS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MOUNTS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mounts_0 (guestfs_h *g)
{
  if (test_mounts_0_skip ()) {
    skipped ("test_mounts_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mounts (0) */
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_mounts (g);
  if (ret == NULL)
      return -1;
  if (! (is_device_list (ret, 1, "/dev/sdb1"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_mounts_0", "is_device_list (ret, 1, \"/dev/sdb1\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_umount_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "umount") == NULL;
  str = getenv ("SKIP_TEST_UMOUNT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UMOUNT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_umount_0 (guestfs_h *g)
{
  if (test_umount_0_skip ()) {
    skipped ("test_umount_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for umount (0) */
  const char *_arg2778 = "/dev/sda";
  const char *_arg2779 = "mbr";
  int ret3;
  ret3 = guestfs_part_disk (g, _arg2778, _arg2779);
  if (ret3 == -1)
    return -1;
  const char *_arg2781 = "ext2";
  const char *_arg2782 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs2783;
  _optargs2783.bitmask = UINT64_C(0x0);
  int ret2;
  ret2 = guestfs_mkfs_opts_argv (g, _arg2781, _arg2782, &_optargs2783);
  if (ret2 == -1)
    return -1;
  const char *_arg2784 = "/dev/sda1";
  const char *_arg2785 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg2784, _arg2785);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_mounts (g);
  if (ret == NULL)
      return -1;
  if (! (is_device_list (ret, 1, "/dev/sda1"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_umount_0", "is_device_list (ret, 1, \"/dev/sda1\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_umount_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "umount") == NULL;
  str = getenv ("SKIP_TEST_UMOUNT_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_UMOUNT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_umount_1 (guestfs_h *g)
{
  if (test_umount_1_skip ()) {
    skipped ("test_umount_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for umount (1) */
  const char *_arg2788 = "/dev/sda";
  const char *_arg2789 = "mbr";
  int ret4;
  ret4 = guestfs_part_disk (g, _arg2788, _arg2789);
  if (ret4 == -1)
    return -1;
  const char *_arg2791 = "ext2";
  const char *_arg2792 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs2793;
  _optargs2793.bitmask = UINT64_C(0x0);
  int ret3;
  ret3 = guestfs_mkfs_opts_argv (g, _arg2791, _arg2792, &_optargs2793);
  if (ret3 == -1)
    return -1;
  const char *_arg2794 = "/dev/sda1";
  const char *_arg2795 = "/";
  int ret2;
  ret2 = guestfs_mount (g, _arg2794, _arg2795);
  if (ret2 == -1)
    return -1;
  const char *_arg2797 = "/";
  struct guestfs_umount_opts_argv _optargs2798;
  _optargs2798.force = 0;
  _optargs2798.lazyunmount = 0;
  _optargs2798.bitmask = UINT64_C(0x3);
  int ret1;
  ret1 = guestfs_umount_opts_argv (g, _arg2797, &_optargs2798);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_mounts (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_umount_1", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_write_file_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "write_file") == NULL;
  str = getenv ("SKIP_TEST_WRITE_FILE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WRITE_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_write_file_0 (guestfs_h *g)
{
  if (test_write_file_0_skip ()) {
    skipped ("test_write_file_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for write_file (0) */
  const char *_arg2801 = "/write_file";
  const char *_arg2802 = "abc";
  int _ret2800;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2800 = guestfs_write_file (g, _arg2801, _arg2802, 10000);
  guestfs_pop_error_handler (g);
  if (_ret2800 != -1)
    return -1;
  return 0;
}

static int
test_lvcreate_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lvcreate") == NULL;
  str = getenv ("SKIP_TEST_LVCREATE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LVCREATE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lvcreate_0 (guestfs_h *g)
{
  if (test_lvcreate_0_skip ()) {
    skipped ("test_lvcreate_0", "environment variable set");
    return 0;
  }

  const char *_features2805[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2805)) {
    skipped ("test_lvcreate_0", "group %s not available in daemon",
             _features2805[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvcreate (0) */
  const char *_arg2806 = "/dev/sda";
  const char *_arg2807 = "mbr";
  int ret14;
  ret14 = guestfs_part_init (g, _arg2806, _arg2807);
  if (ret14 == -1)
    return -1;
  const char *_arg2809 = "/dev/sda";
  const char *_arg2810 = "p";
  int ret13;
  ret13 = guestfs_part_add (g, _arg2809, _arg2810, 64, 204799);
  if (ret13 == -1)
    return -1;
  const char *_arg2814 = "/dev/sda";
  const char *_arg2815 = "p";
  int ret12;
  ret12 = guestfs_part_add (g, _arg2814, _arg2815, 204800, 409599);
  if (ret12 == -1)
    return -1;
  const char *_arg2819 = "/dev/sda";
  const char *_arg2820 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, _arg2819, _arg2820, 409600, -64);
  if (ret11 == -1)
    return -1;
  const char *_arg2824 = "/dev/sda1";
  int ret10;
  ret10 = guestfs_pvcreate (g, _arg2824);
  if (ret10 == -1)
    return -1;
  const char *_arg2826 = "/dev/sda2";
  int ret9;
  ret9 = guestfs_pvcreate (g, _arg2826);
  if (ret9 == -1)
    return -1;
  const char *_arg2828 = "/dev/sda3";
  int ret8;
  ret8 = guestfs_pvcreate (g, _arg2828);
  if (ret8 == -1)
    return -1;
  const char *_arg2830 = "VG1";
  const char *_arg2831_0 = "/dev/sda1";
  const char *_arg2831_1 = "/dev/sda2";
  const char *const _arg2831[] = {
    _arg2831_0,
    _arg2831_1,
    NULL
  };
  int ret7;
  ret7 = guestfs_vgcreate (g, _arg2830, (char **) _arg2831);
  if (ret7 == -1)
    return -1;
  const char *_arg2833 = "VG2";
  const char *_arg2834_0 = "/dev/sda3";
  const char *const _arg2834[] = {
    _arg2834_0,
    NULL
  };
  int ret6;
  ret6 = guestfs_vgcreate (g, _arg2833, (char **) _arg2834);
  if (ret6 == -1)
    return -1;
  const char *_arg2836 = "LV1";
  const char *_arg2837 = "VG1";
  int ret5;
  ret5 = guestfs_lvcreate (g, _arg2836, _arg2837, 50);
  if (ret5 == -1)
    return -1;
  const char *_arg2840 = "LV2";
  const char *_arg2841 = "VG1";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg2840, _arg2841, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg2844 = "LV3";
  const char *_arg2845 = "VG2";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2844, _arg2845, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2848 = "LV4";
  const char *_arg2849 = "VG2";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2848, _arg2849, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2852 = "LV5";
  const char *_arg2853 = "VG2";
  int ret1;
  ret1 = guestfs_lvcreate (g, _arg2852, _arg2853, 50);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_lvs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 5, "/dev/VG1/LV1", "/dev/VG1/LV2", "/dev/VG2/LV3", "/dev/VG2/LV4", "/dev/VG2/LV5"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_lvcreate_0", "is_string_list (ret, 5, \"/dev/VG1/LV1\", \"/dev/VG1/LV2\", \"/dev/VG2/LV3\", \"/dev/VG2/LV4\", \"/dev/VG2/LV5\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_vgcreate_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vgcreate") == NULL;
  str = getenv ("SKIP_TEST_VGCREATE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VGCREATE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vgcreate_0 (guestfs_h *g)
{
  if (test_vgcreate_0_skip ()) {
    skipped ("test_vgcreate_0", "environment variable set");
    return 0;
  }

  const char *_features2857[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2857)) {
    skipped ("test_vgcreate_0", "group %s not available in daemon",
             _features2857[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for vgcreate (0) */
  const char *_arg2858 = "/dev/sda";
  const char *_arg2859 = "mbr";
  int ret9;
  ret9 = guestfs_part_init (g, _arg2858, _arg2859);
  if (ret9 == -1)
    return -1;
  const char *_arg2861 = "/dev/sda";
  const char *_arg2862 = "p";
  int ret8;
  ret8 = guestfs_part_add (g, _arg2861, _arg2862, 64, 204799);
  if (ret8 == -1)
    return -1;
  const char *_arg2866 = "/dev/sda";
  const char *_arg2867 = "p";
  int ret7;
  ret7 = guestfs_part_add (g, _arg2866, _arg2867, 204800, 409599);
  if (ret7 == -1)
    return -1;
  const char *_arg2871 = "/dev/sda";
  const char *_arg2872 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg2871, _arg2872, 409600, -64);
  if (ret6 == -1)
    return -1;
  const char *_arg2876 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2876);
  if (ret5 == -1)
    return -1;
  const char *_arg2878 = "/dev/sda2";
  int ret4;
  ret4 = guestfs_pvcreate (g, _arg2878);
  if (ret4 == -1)
    return -1;
  const char *_arg2880 = "/dev/sda3";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg2880);
  if (ret3 == -1)
    return -1;
  const char *_arg2882 = "VG1";
  const char *_arg2883_0 = "/dev/sda1";
  const char *_arg2883_1 = "/dev/sda2";
  const char *const _arg2883[] = {
    _arg2883_0,
    _arg2883_1,
    NULL
  };
  int ret2;
  ret2 = guestfs_vgcreate (g, _arg2882, (char **) _arg2883);
  if (ret2 == -1)
    return -1;
  const char *_arg2885 = "VG2";
  const char *_arg2886_0 = "/dev/sda3";
  const char *const _arg2886[] = {
    _arg2886_0,
    NULL
  };
  int ret1;
  ret1 = guestfs_vgcreate (g, _arg2885, (char **) _arg2886);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_vgs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "VG1", "VG2"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_vgcreate_0", "is_string_list (ret, 2, \"VG1\", \"VG2\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_pvcreate_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pvcreate") == NULL;
  str = getenv ("SKIP_TEST_PVCREATE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PVCREATE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pvcreate_0 (guestfs_h *g)
{
  if (test_pvcreate_0_skip ()) {
    skipped ("test_pvcreate_0", "environment variable set");
    return 0;
  }

  const char *_features2889[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2889)) {
    skipped ("test_pvcreate_0", "group %s not available in daemon",
             _features2889[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvcreate (0) */
  const char *_arg2890 = "/dev/sda";
  const char *_arg2891 = "mbr";
  int ret7;
  ret7 = guestfs_part_init (g, _arg2890, _arg2891);
  if (ret7 == -1)
    return -1;
  const char *_arg2893 = "/dev/sda";
  const char *_arg2894 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg2893, _arg2894, 64, 204799);
  if (ret6 == -1)
    return -1;
  const char *_arg2898 = "/dev/sda";
  const char *_arg2899 = "p";
  int ret5;
  ret5 = guestfs_part_add (g, _arg2898, _arg2899, 204800, 409599);
  if (ret5 == -1)
    return -1;
  const char *_arg2903 = "/dev/sda";
  const char *_arg2904 = "p";
  int ret4;
  ret4 = guestfs_part_add (g, _arg2903, _arg2904, 409600, -64);
  if (ret4 == -1)
    return -1;
  const char *_arg2908 = "/dev/sda1";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg2908);
  if (ret3 == -1)
    return -1;
  const char *_arg2910 = "/dev/sda2";
  int ret2;
  ret2 = guestfs_pvcreate (g, _arg2910);
  if (ret2 == -1)
    return -1;
  const char *_arg2912 = "/dev/sda3";
  int ret1;
  ret1 = guestfs_pvcreate (g, _arg2912);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_pvs (g);
  if (ret == NULL)
      return -1;
  if (! (is_device_list (ret, 3, "/dev/sda1", "/dev/sda2", "/dev/sda3"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_pvcreate_0", "is_device_list (ret, 3, \"/dev/sda1\", \"/dev/sda2\", \"/dev/sda3\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_is_dir_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_dir") == NULL;
  str = getenv ("SKIP_TEST_IS_DIR_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_DIR");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_dir_0 (guestfs_h *g)
{
  if (test_is_dir_0_skip ()) {
    skipped ("test_is_dir_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultFalse for is_dir (0) */
  const char *_arg2915 = "/known-3";
  int ret;
  ret = guestfs_is_dir (g, _arg2915);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_dir_0", "is_dir");
    return -1;
  }
  return 0;
}

static int
test_is_dir_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_dir") == NULL;
  str = getenv ("SKIP_TEST_IS_DIR_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_DIR");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_dir_1 (guestfs_h *g)
{
  if (test_is_dir_1_skip ()) {
    skipped ("test_is_dir_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultTrue for is_dir (1) */
  const char *_arg2917 = "/directory";
  int ret;
  ret = guestfs_is_dir (g, _arg2917);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_dir_1", "is_dir");
    return -1;
  }
  return 0;
}

static int
test_is_file_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_file") == NULL;
  str = getenv ("SKIP_TEST_IS_FILE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_file_0 (guestfs_h *g)
{
  if (test_is_file_0_skip ()) {
    skipped ("test_is_file_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultTrue for is_file (0) */
  const char *_arg2919 = "/known-1";
  int ret;
  ret = guestfs_is_file (g, _arg2919);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_file_0", "is_file");
    return -1;
  }
  return 0;
}

static int
test_is_file_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_file") == NULL;
  str = getenv ("SKIP_TEST_IS_FILE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_file_1 (guestfs_h *g)
{
  if (test_is_file_1_skip ()) {
    skipped ("test_is_file_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultFalse for is_file (1) */
  const char *_arg2921 = "/directory";
  int ret;
  ret = guestfs_is_file (g, _arg2921);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_file_1", "is_file");
    return -1;
  }
  return 0;
}

static int
test_exists_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "exists") == NULL;
  str = getenv ("SKIP_TEST_EXISTS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_EXISTS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_exists_0 (guestfs_h *g)
{
  if (test_exists_0_skip ()) {
    skipped ("test_exists_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultTrue for exists (0) */
  const char *_arg2923 = "/empty";
  int ret;
  ret = guestfs_exists (g, _arg2923);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_exists_0", "exists");
    return -1;
  }
  return 0;
}

static int
test_exists_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "exists") == NULL;
  str = getenv ("SKIP_TEST_EXISTS_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_EXISTS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_exists_1 (guestfs_h *g)
{
  if (test_exists_1_skip ()) {
    skipped ("test_exists_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultTrue for exists (1) */
  const char *_arg2925 = "/directory";
  int ret;
  ret = guestfs_exists (g, _arg2925);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_exists_1", "exists");
    return -1;
  }
  return 0;
}

static int
test_mkdir_p_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkdir_p") == NULL;
  str = getenv ("SKIP_TEST_MKDIR_P_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKDIR_P");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkdir_p_0 (guestfs_h *g)
{
  if (test_mkdir_p_0_skip ()) {
    skipped ("test_mkdir_p_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultTrue for mkdir_p (0) */
  const char *_arg2928 = "/mkdir_p/foo/bar";
  int _ret2927;
  _ret2927 = guestfs_mkdir_p (g, _arg2928);
  if (_ret2927 == -1)
    return -1;
  const char *_arg2930 = "/mkdir_p/foo/bar";
  int ret;
  ret = guestfs_is_dir (g, _arg2930);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_mkdir_p_0", "is_dir");
    return -1;
  }
  return 0;
}

static int
test_mkdir_p_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkdir_p") == NULL;
  str = getenv ("SKIP_TEST_MKDIR_P_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKDIR_P");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkdir_p_1 (guestfs_h *g)
{
  if (test_mkdir_p_1_skip ()) {
    skipped ("test_mkdir_p_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultTrue for mkdir_p (1) */
  const char *_arg2933 = "/mkdir_p2/foo/bar";
  int _ret2932;
  _ret2932 = guestfs_mkdir_p (g, _arg2933);
  if (_ret2932 == -1)
    return -1;
  const char *_arg2935 = "/mkdir_p2/foo";
  int ret;
  ret = guestfs_is_dir (g, _arg2935);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_mkdir_p_1", "is_dir");
    return -1;
  }
  return 0;
}

static int
test_mkdir_p_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkdir_p") == NULL;
  str = getenv ("SKIP_TEST_MKDIR_P_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKDIR_P");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkdir_p_2 (guestfs_h *g)
{
  if (test_mkdir_p_2_skip ()) {
    skipped ("test_mkdir_p_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultTrue for mkdir_p (2) */
  const char *_arg2938 = "/mkdir_p3/foo/bar";
  int _ret2937;
  _ret2937 = guestfs_mkdir_p (g, _arg2938);
  if (_ret2937 == -1)
    return -1;
  const char *_arg2940 = "/mkdir_p3";
  int ret;
  ret = guestfs_is_dir (g, _arg2940);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_mkdir_p_2", "is_dir");
    return -1;
  }
  return 0;
}

static int
test_mkdir_p_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkdir_p") == NULL;
  str = getenv ("SKIP_TEST_MKDIR_P_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKDIR_P");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkdir_p_3 (guestfs_h *g)
{
  if (test_mkdir_p_3_skip ()) {
    skipped ("test_mkdir_p_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for mkdir_p (3) */
  const char *_arg2943 = "/mkdir_p4";
  int _ret2942;
  _ret2942 = guestfs_mkdir (g, _arg2943);
  if (_ret2942 == -1)
    return -1;
  const char *_arg2946 = "/mkdir_p4";
  int _ret2945;
  _ret2945 = guestfs_mkdir_p (g, _arg2946);
  if (_ret2945 == -1)
    return -1;
  return 0;
}

static int
test_mkdir_p_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkdir_p") == NULL;
  str = getenv ("SKIP_TEST_MKDIR_P_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKDIR_P");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkdir_p_4 (guestfs_h *g)
{
  if (test_mkdir_p_4_skip ()) {
    skipped ("test_mkdir_p_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for mkdir_p (4) */
  const char *_arg2949 = "/mkdir_p5";
  int _ret2948;
  _ret2948 = guestfs_touch (g, _arg2949);
  if (_ret2948 == -1)
    return -1;
  const char *_arg2952 = "/mkdir_p5";
  int _ret2951;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2951 = guestfs_mkdir_p (g, _arg2952);
  guestfs_pop_error_handler (g);
  if (_ret2951 != -1)
    return -1;
  return 0;
}

static int
test_mkdir_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkdir") == NULL;
  str = getenv ("SKIP_TEST_MKDIR_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKDIR");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkdir_0 (guestfs_h *g)
{
  if (test_mkdir_0_skip ()) {
    skipped ("test_mkdir_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultTrue for mkdir (0) */
  const char *_arg2955 = "/mkdir";
  int _ret2954;
  _ret2954 = guestfs_mkdir (g, _arg2955);
  if (_ret2954 == -1)
    return -1;
  const char *_arg2957 = "/mkdir";
  int ret;
  ret = guestfs_is_dir (g, _arg2957);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_mkdir_0", "is_dir");
    return -1;
  }
  return 0;
}

static int
test_mkdir_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkdir") == NULL;
  str = getenv ("SKIP_TEST_MKDIR_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKDIR");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkdir_1 (guestfs_h *g)
{
  if (test_mkdir_1_skip ()) {
    skipped ("test_mkdir_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for mkdir (1) */
  const char *_arg2960 = "/mkdir2/foo/bar";
  int _ret2959;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2959 = guestfs_mkdir (g, _arg2960);
  guestfs_pop_error_handler (g);
  if (_ret2959 != -1)
    return -1;
  return 0;
}

static int
test_rm_rf_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "rm_rf") == NULL;
  str = getenv ("SKIP_TEST_RM_RF_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_RM_RF");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_rm_rf_0 (guestfs_h *g)
{
  if (test_rm_rf_0_skip ()) {
    skipped ("test_rm_rf_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultFalse for rm_rf (0) */
  const char *_arg2963 = "/rm_rf";
  int _ret2962;
  _ret2962 = guestfs_mkdir (g, _arg2963);
  if (_ret2962 == -1)
    return -1;
  const char *_arg2966 = "/rm_rf/foo";
  int _ret2965;
  _ret2965 = guestfs_mkdir (g, _arg2966);
  if (_ret2965 == -1)
    return -1;
  const char *_arg2969 = "/rm_rf/foo/bar";
  int _ret2968;
  _ret2968 = guestfs_touch (g, _arg2969);
  if (_ret2968 == -1)
    return -1;
  const char *_arg2972 = "/rm_rf";
  int _ret2971;
  _ret2971 = guestfs_rm_rf (g, _arg2972);
  if (_ret2971 == -1)
    return -1;
  const char *_arg2974 = "/rm_rf";
  int ret;
  ret = guestfs_exists (g, _arg2974);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_rm_rf_0", "exists");
    return -1;
  }
  return 0;
}

static int
test_rmdir_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "rmdir") == NULL;
  str = getenv ("SKIP_TEST_RMDIR_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_RMDIR");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_rmdir_0 (guestfs_h *g)
{
  if (test_rmdir_0_skip ()) {
    skipped ("test_rmdir_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for rmdir (0) */
  const char *_arg2977 = "/rmdir";
  int _ret2976;
  _ret2976 = guestfs_mkdir (g, _arg2977);
  if (_ret2976 == -1)
    return -1;
  const char *_arg2980 = "/rmdir";
  int _ret2979;
  _ret2979 = guestfs_rmdir (g, _arg2980);
  if (_ret2979 == -1)
    return -1;
  return 0;
}

static int
test_rmdir_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "rmdir") == NULL;
  str = getenv ("SKIP_TEST_RMDIR_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_RMDIR");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_rmdir_1 (guestfs_h *g)
{
  if (test_rmdir_1_skip ()) {
    skipped ("test_rmdir_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for rmdir (1) */
  const char *_arg2983 = "/rmdir2";
  int _ret2982;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2982 = guestfs_rmdir (g, _arg2983);
  guestfs_pop_error_handler (g);
  if (_ret2982 != -1)
    return -1;
  return 0;
}

static int
test_rmdir_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "rmdir") == NULL;
  str = getenv ("SKIP_TEST_RMDIR_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_RMDIR");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_rmdir_2 (guestfs_h *g)
{
  if (test_rmdir_2_skip ()) {
    skipped ("test_rmdir_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for rmdir (2) */
  const char *_arg2986 = "/rmdir3";
  int _ret2985;
  _ret2985 = guestfs_mkdir (g, _arg2986);
  if (_ret2985 == -1)
    return -1;
  const char *_arg2989 = "/rmdir3/new";
  int _ret2988;
  _ret2988 = guestfs_touch (g, _arg2989);
  if (_ret2988 == -1)
    return -1;
  const char *_arg2992 = "/rmdir3/new";
  int _ret2991;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2991 = guestfs_rmdir (g, _arg2992);
  guestfs_pop_error_handler (g);
  if (_ret2991 != -1)
    return -1;
  return 0;
}

static int
test_rm_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "rm") == NULL;
  str = getenv ("SKIP_TEST_RM_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_RM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_rm_0 (guestfs_h *g)
{
  if (test_rm_0_skip ()) {
    skipped ("test_rm_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for rm (0) */
  const char *_arg2995 = "/rm";
  int _ret2994;
  _ret2994 = guestfs_mkdir (g, _arg2995);
  if (_ret2994 == -1)
    return -1;
  const char *_arg2998 = "/rm/new";
  int _ret2997;
  _ret2997 = guestfs_touch (g, _arg2998);
  if (_ret2997 == -1)
    return -1;
  const char *_arg3001 = "/rm/new";
  int _ret3000;
  _ret3000 = guestfs_rm (g, _arg3001);
  if (_ret3000 == -1)
    return -1;
  return 0;
}

static int
test_rm_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "rm") == NULL;
  str = getenv ("SKIP_TEST_RM_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_RM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_rm_1 (guestfs_h *g)
{
  if (test_rm_1_skip ()) {
    skipped ("test_rm_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for rm (1) */
  const char *_arg3004 = "/nosuchfile";
  int _ret3003;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret3003 = guestfs_rm (g, _arg3004);
  guestfs_pop_error_handler (g);
  if (_ret3003 != -1)
    return -1;
  return 0;
}

static int
test_rm_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "rm") == NULL;
  str = getenv ("SKIP_TEST_RM_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_RM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_rm_2 (guestfs_h *g)
{
  if (test_rm_2_skip ()) {
    skipped ("test_rm_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for rm (2) */
  const char *_arg3007 = "/rm2";
  int _ret3006;
  _ret3006 = guestfs_mkdir (g, _arg3007);
  if (_ret3006 == -1)
    return -1;
  const char *_arg3010 = "/rm2";
  int _ret3009;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret3009 = guestfs_rm (g, _arg3010);
  guestfs_pop_error_handler (g);
  if (_ret3009 != -1)
    return -1;
  return 0;
}

static int
test_lvs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lvs") == NULL;
  str = getenv ("SKIP_TEST_LVS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LVS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lvs_0 (guestfs_h *g)
{
  if (test_lvs_0_skip ()) {
    skipped ("test_lvs_0", "environment variable set");
    return 0;
  }

  const char *_features3012[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3012)) {
    skipped ("test_lvs_0", "group %s not available in daemon",
             _features3012[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResult for lvs (0) */
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_lvs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 1, "/dev/VG/LV"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_lvs_0", "is_string_list (ret, 1, \"/dev/VG/LV\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_lvs_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lvs") == NULL;
  str = getenv ("SKIP_TEST_LVS_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LVS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lvs_1 (guestfs_h *g)
{
  if (test_lvs_1_skip ()) {
    skipped ("test_lvs_1", "environment variable set");
    return 0;
  }

  const char *_features3014[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3014)) {
    skipped ("test_lvs_1", "group %s not available in daemon",
             _features3014[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvs (1) */
  const char *_arg3015 = "/dev/sda";
  const char *_arg3016 = "mbr";
  int ret12;
  ret12 = guestfs_part_init (g, _arg3015, _arg3016);
  if (ret12 == -1)
    return -1;
  const char *_arg3018 = "/dev/sda";
  const char *_arg3019 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, _arg3018, _arg3019, 64, 204799);
  if (ret11 == -1)
    return -1;
  const char *_arg3023 = "/dev/sda";
  const char *_arg3024 = "p";
  int ret10;
  ret10 = guestfs_part_add (g, _arg3023, _arg3024, 204800, 409599);
  if (ret10 == -1)
    return -1;
  const char *_arg3028 = "/dev/sda";
  const char *_arg3029 = "p";
  int ret9;
  ret9 = guestfs_part_add (g, _arg3028, _arg3029, 409600, -64);
  if (ret9 == -1)
    return -1;
  const char *_arg3033 = "/dev/sda1";
  int ret8;
  ret8 = guestfs_pvcreate (g, _arg3033);
  if (ret8 == -1)
    return -1;
  const char *_arg3035 = "/dev/sda2";
  int ret7;
  ret7 = guestfs_pvcreate (g, _arg3035);
  if (ret7 == -1)
    return -1;
  const char *_arg3037 = "/dev/sda3";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg3037);
  if (ret6 == -1)
    return -1;
  const char *_arg3039 = "VG1";
  const char *_arg3040_0 = "/dev/sda1";
  const char *_arg3040_1 = "/dev/sda2";
  const char *const _arg3040[] = {
    _arg3040_0,
    _arg3040_1,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg3039, (char **) _arg3040);
  if (ret5 == -1)
    return -1;
  const char *_arg3042 = "VG2";
  const char *_arg3043_0 = "/dev/sda3";
  const char *const _arg3043[] = {
    _arg3043_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg3042, (char **) _arg3043);
  if (ret4 == -1)
    return -1;
  const char *_arg3045 = "LV1";
  const char *_arg3046 = "VG1";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg3045, _arg3046, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg3049 = "LV2";
  const char *_arg3050 = "VG1";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg3049, _arg3050, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg3053 = "LV3";
  const char *_arg3054 = "VG2";
  int ret1;
  ret1 = guestfs_lvcreate (g, _arg3053, _arg3054, 50);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_lvs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "/dev/VG1/LV1", "/dev/VG1/LV2", "/dev/VG2/LV3"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_lvs_1", "is_string_list (ret, 3, \"/dev/VG1/LV1\", \"/dev/VG1/LV2\", \"/dev/VG2/LV3\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_vgs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vgs") == NULL;
  str = getenv ("SKIP_TEST_VGS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VGS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vgs_0 (guestfs_h *g)
{
  if (test_vgs_0_skip ()) {
    skipped ("test_vgs_0", "environment variable set");
    return 0;
  }

  const char *_features3058[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3058)) {
    skipped ("test_vgs_0", "group %s not available in daemon",
             _features3058[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResult for vgs (0) */
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_vgs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 1, "VG"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_vgs_0", "is_string_list (ret, 1, \"VG\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_vgs_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vgs") == NULL;
  str = getenv ("SKIP_TEST_VGS_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VGS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vgs_1 (guestfs_h *g)
{
  if (test_vgs_1_skip ()) {
    skipped ("test_vgs_1", "environment variable set");
    return 0;
  }

  const char *_features3060[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3060)) {
    skipped ("test_vgs_1", "group %s not available in daemon",
             _features3060[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for vgs (1) */
  const char *_arg3061 = "/dev/sda";
  const char *_arg3062 = "mbr";
  int ret9;
  ret9 = guestfs_part_init (g, _arg3061, _arg3062);
  if (ret9 == -1)
    return -1;
  const char *_arg3064 = "/dev/sda";
  const char *_arg3065 = "p";
  int ret8;
  ret8 = guestfs_part_add (g, _arg3064, _arg3065, 64, 204799);
  if (ret8 == -1)
    return -1;
  const char *_arg3069 = "/dev/sda";
  const char *_arg3070 = "p";
  int ret7;
  ret7 = guestfs_part_add (g, _arg3069, _arg3070, 204800, 409599);
  if (ret7 == -1)
    return -1;
  const char *_arg3074 = "/dev/sda";
  const char *_arg3075 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg3074, _arg3075, 409600, -64);
  if (ret6 == -1)
    return -1;
  const char *_arg3079 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg3079);
  if (ret5 == -1)
    return -1;
  const char *_arg3081 = "/dev/sda2";
  int ret4;
  ret4 = guestfs_pvcreate (g, _arg3081);
  if (ret4 == -1)
    return -1;
  const char *_arg3083 = "/dev/sda3";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg3083);
  if (ret3 == -1)
    return -1;
  const char *_arg3085 = "VG1";
  const char *_arg3086_0 = "/dev/sda1";
  const char *_arg3086_1 = "/dev/sda2";
  const char *const _arg3086[] = {
    _arg3086_0,
    _arg3086_1,
    NULL
  };
  int ret2;
  ret2 = guestfs_vgcreate (g, _arg3085, (char **) _arg3086);
  if (ret2 == -1)
    return -1;
  const char *_arg3088 = "VG2";
  const char *_arg3089_0 = "/dev/sda3";
  const char *const _arg3089[] = {
    _arg3089_0,
    NULL
  };
  int ret1;
  ret1 = guestfs_vgcreate (g, _arg3088, (char **) _arg3089);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_vgs (g);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "VG1", "VG2"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_vgs_1", "is_string_list (ret, 2, \"VG1\", \"VG2\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_pvs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pvs") == NULL;
  str = getenv ("SKIP_TEST_PVS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PVS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pvs_0 (guestfs_h *g)
{
  if (test_pvs_0_skip ()) {
    skipped ("test_pvs_0", "environment variable set");
    return 0;
  }

  const char *_features3092[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3092)) {
    skipped ("test_pvs_0", "group %s not available in daemon",
             _features3092[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResult for pvs (0) */
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_pvs (g);
  if (ret == NULL)
      return -1;
  if (! (is_device_list (ret, 1, "/dev/sda1"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_pvs_0", "is_device_list (ret, 1, \"/dev/sda1\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_pvs_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "pvs") == NULL;
  str = getenv ("SKIP_TEST_PVS_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PVS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_pvs_1 (guestfs_h *g)
{
  if (test_pvs_1_skip ()) {
    skipped ("test_pvs_1", "environment variable set");
    return 0;
  }

  const char *_features3094[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3094)) {
    skipped ("test_pvs_1", "group %s not available in daemon",
             _features3094[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvs (1) */
  const char *_arg3095 = "/dev/sda";
  const char *_arg3096 = "mbr";
  int ret7;
  ret7 = guestfs_part_init (g, _arg3095, _arg3096);
  if (ret7 == -1)
    return -1;
  const char *_arg3098 = "/dev/sda";
  const char *_arg3099 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg3098, _arg3099, 64, 204799);
  if (ret6 == -1)
    return -1;
  const char *_arg3103 = "/dev/sda";
  const char *_arg3104 = "p";
  int ret5;
  ret5 = guestfs_part_add (g, _arg3103, _arg3104, 204800, 409599);
  if (ret5 == -1)
    return -1;
  const char *_arg3108 = "/dev/sda";
  const char *_arg3109 = "p";
  int ret4;
  ret4 = guestfs_part_add (g, _arg3108, _arg3109, 409600, -64);
  if (ret4 == -1)
    return -1;
  const char *_arg3113 = "/dev/sda1";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg3113);
  if (ret3 == -1)
    return -1;
  const char *_arg3115 = "/dev/sda2";
  int ret2;
  ret2 = guestfs_pvcreate (g, _arg3115);
  if (ret2 == -1)
    return -1;
  const char *_arg3117 = "/dev/sda3";
  int ret1;
  ret1 = guestfs_pvcreate (g, _arg3117);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_pvs (g);
  if (ret == NULL)
      return -1;
  if (! (is_device_list (ret, 3, "/dev/sda1", "/dev/sda2", "/dev/sda3"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_pvs_1", "is_device_list (ret, 3, \"/dev/sda1\", \"/dev/sda2\", \"/dev/sda3\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_list_partitions_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "list_partitions") == NULL;
  str = getenv ("SKIP_TEST_LIST_PARTITIONS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LIST_PARTITIONS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_list_partitions_0 (guestfs_h *g)
{
  if (test_list_partitions_0_skip ()) {
    skipped ("test_list_partitions_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResult for list_partitions (0) */
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_list_partitions (g);
  if (ret == NULL)
      return -1;
  if (! (is_device_list (ret, 2, "/dev/sda1", "/dev/sdb1"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_list_partitions_0", "is_device_list (ret, 2, \"/dev/sda1\", \"/dev/sdb1\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_list_partitions_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "list_partitions") == NULL;
  str = getenv ("SKIP_TEST_LIST_PARTITIONS_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LIST_PARTITIONS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_list_partitions_1 (guestfs_h *g)
{
  if (test_list_partitions_1_skip ()) {
    skipped ("test_list_partitions_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for list_partitions (1) */
  const char *_arg3121 = "/dev/sda";
  const char *_arg3122 = "mbr";
  int ret4;
  ret4 = guestfs_part_init (g, _arg3121, _arg3122);
  if (ret4 == -1)
    return -1;
  const char *_arg3124 = "/dev/sda";
  const char *_arg3125 = "p";
  int ret3;
  ret3 = guestfs_part_add (g, _arg3124, _arg3125, 64, 204799);
  if (ret3 == -1)
    return -1;
  const char *_arg3129 = "/dev/sda";
  const char *_arg3130 = "p";
  int ret2;
  ret2 = guestfs_part_add (g, _arg3129, _arg3130, 204800, 409599);
  if (ret2 == -1)
    return -1;
  const char *_arg3134 = "/dev/sda";
  const char *_arg3135 = "p";
  int ret1;
  ret1 = guestfs_part_add (g, _arg3134, _arg3135, 409600, -64);
  if (ret1 == -1)
    return -1;
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_list_partitions (g);
  if (ret == NULL)
      return -1;
  if (! (is_device_list (ret, 4, "/dev/sda1", "/dev/sda2", "/dev/sda3", "/dev/sdb1"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_list_partitions_1", "is_device_list (ret, 4, \"/dev/sda1\", \"/dev/sda2\", \"/dev/sda3\", \"/dev/sdb1\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_list_devices_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "list_devices") == NULL;
  str = getenv ("SKIP_TEST_LIST_DEVICES_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LIST_DEVICES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_list_devices_0 (guestfs_h *g)
{
  if (test_list_devices_0_skip ()) {
    skipped ("test_list_devices_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for list_devices (0) */
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_list_devices (g);
  if (ret == NULL)
      return -1;
  if (! (is_device_list (ret, 4, "/dev/sda", "/dev/sdb", "/dev/sdc", "/dev/sdd"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_list_devices_0", "is_device_list (ret, 4, \"/dev/sda\", \"/dev/sdb\", \"/dev/sdc\", \"/dev/sdd\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_touch_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "touch") == NULL;
  str = getenv ("SKIP_TEST_TOUCH_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_TOUCH");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_touch_0 (guestfs_h *g)
{
  if (test_touch_0_skip ()) {
    skipped ("test_touch_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultTrue for touch (0) */
  const char *_arg3142 = "/touch";
  int _ret3141;
  _ret3141 = guestfs_touch (g, _arg3142);
  if (_ret3141 == -1)
    return -1;
  const char *_arg3144 = "/touch";
  int ret;
  ret = guestfs_exists (g, _arg3144);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_touch_0", "exists");
    return -1;
  }
  return 0;
}

static int
test_sync_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "sync") == NULL;
  str = getenv ("SKIP_TEST_SYNC_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SYNC");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_sync_0 (guestfs_h *g)
{
  if (test_sync_0_skip ()) {
    skipped ("test_sync_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for sync (0) */
  int _ret3146;
  _ret3146 = guestfs_sync (g);
  if (_ret3146 == -1)
    return -1;
  return 0;
}

static int
test_mount_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mount") == NULL;
  str = getenv ("SKIP_TEST_MOUNT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MOUNT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mount_0 (guestfs_h *g)
{
  if (test_mount_0_skip ()) {
    skipped ("test_mount_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for mount (0) */
  const char *_arg3149 = "/dev/sda";
  const char *_arg3150 = "mbr";
  int _ret3148;
  _ret3148 = guestfs_part_disk (g, _arg3149, _arg3150);
  if (_ret3148 == -1)
    return -1;
  const char *_arg3153 = "ext2";
  const char *_arg3154 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs3155;
  _optargs3155.bitmask = UINT64_C(0x0);
  int _ret3152;
  _ret3152 = guestfs_mkfs_opts_argv (g, _arg3153, _arg3154, &_optargs3155);
  if (_ret3152 == -1)
    return -1;
  const char *_arg3157 = "/dev/sda1";
  const char *_arg3158 = "/";
  int _ret3156;
  _ret3156 = guestfs_mount (g, _arg3157, _arg3158);
  if (_ret3156 == -1)
    return -1;
  const char *_arg3161 = "/new";
  const char *_arg3162 = "new file contents";
  size_t _arg3162_size = 17;
  int _ret3160;
  _ret3160 = guestfs_write (g, _arg3161, _arg3162, _arg3162_size);
  if (_ret3160 == -1)
    return -1;
  const char *_arg3164 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3164);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mount_0", "cat", ret, "new file contents");
    return -1;
  }
  return 0;
}

static int
test_get_program_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_program") == NULL;
  str = getenv ("SKIP_TEST_GET_PROGRAM_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_PROGRAM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_program_0 (guestfs_h *g)
{
  if (test_get_program_0_skip ()) {
    skipped ("test_get_program_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for get_program (0) */
  const char *_ret3166;
  _ret3166 = guestfs_get_program (g);
  if (_ret3166 == NULL)
      return -1;
  return 0;
}

static int
test_disk_has_backing_file_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_has_backing_file") == NULL;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_has_backing_file_0 (guestfs_h *g)
{
  if (test_disk_has_backing_file_0_skip ()) {
    skipped ("test_disk_has_backing_file_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultFalse for disk_has_backing_file (0) */
  const char *_arg3168 = guestfs_get_private (g, "test1");
  int ret;
  ret = guestfs_disk_has_backing_file (g, _arg3168);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_disk_has_backing_file_0", "disk_has_backing_file");
    return -1;
  }
  return 0;
}

static int
test_disk_has_backing_file_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_has_backing_file") == NULL;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_has_backing_file_1 (guestfs_h *g)
{
  if (test_disk_has_backing_file_1_skip ()) {
    skipped ("test_disk_has_backing_file_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultFalse for disk_has_backing_file (1) */
  const char *_arg3170 = guestfs_get_private (g, "test2");
  int ret;
  ret = guestfs_disk_has_backing_file (g, _arg3170);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_disk_has_backing_file_1", "disk_has_backing_file");
    return -1;
  }
  return 0;
}

static int
test_disk_has_backing_file_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_has_backing_file") == NULL;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_has_backing_file_2 (guestfs_h *g)
{
  if (test_disk_has_backing_file_2_skip ()) {
    skipped ("test_disk_has_backing_file_2", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultFalse for disk_has_backing_file (2) */
  const char *_arg3172 = guestfs_get_private (g, "test3");
  int ret;
  ret = guestfs_disk_has_backing_file (g, _arg3172);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_disk_has_backing_file_2", "disk_has_backing_file");
    return -1;
  }
  return 0;
}

static int
test_disk_virtual_size_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_virtual_size") == NULL;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_virtual_size_0 (guestfs_h *g)
{
  if (test_disk_virtual_size_0_skip ()) {
    skipped ("test_disk_virtual_size_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for disk_virtual_size (0) */
  const char *_arg3174 = guestfs_get_private (g, "test1");
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, _arg3174);
  if (ret == -1)
    return -1;
  if (! (ret == UINT64_C (524288000))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_disk_virtual_size_0", "ret == UINT64_C (524288000)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_disk_virtual_size_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_virtual_size") == NULL;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_virtual_size_1 (guestfs_h *g)
{
  if (test_disk_virtual_size_1_skip ()) {
    skipped ("test_disk_virtual_size_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for disk_virtual_size (1) */
  const char *_arg3176 = guestfs_get_private (g, "test2");
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, _arg3176);
  if (ret == -1)
    return -1;
  if (! (ret == UINT64_C (52428800))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_disk_virtual_size_1", "ret == UINT64_C (52428800)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_disk_virtual_size_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_virtual_size") == NULL;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_virtual_size_2 (guestfs_h *g)
{
  if (test_disk_virtual_size_2_skip ()) {
    skipped ("test_disk_virtual_size_2", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for disk_virtual_size (2) */
  const char *_arg3178 = guestfs_get_private (g, "test3");
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, _arg3178);
  if (ret == -1)
    return -1;
  if (! (ret == UINT64_C (10485760))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_disk_virtual_size_2", "ret == UINT64_C (10485760)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_disk_format_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_format") == NULL;
  str = getenv ("SKIP_TEST_DISK_FORMAT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_FORMAT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_format_0 (guestfs_h *g)
{
  if (test_disk_format_0_skip ()) {
    skipped ("test_disk_format_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for disk_format (0) */
  const char *_arg3180 = guestfs_get_private (g, "test1");
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, _arg3180);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "raw")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_disk_format_0", "disk_format", ret, "raw");
    return -1;
  }
  return 0;
}

static int
test_disk_format_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_format") == NULL;
  str = getenv ("SKIP_TEST_DISK_FORMAT_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_FORMAT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_format_1 (guestfs_h *g)
{
  if (test_disk_format_1_skip ()) {
    skipped ("test_disk_format_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for disk_format (1) */
  const char *_arg3182 = guestfs_get_private (g, "test2");
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, _arg3182);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "raw")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_disk_format_1", "disk_format", ret, "raw");
    return -1;
  }
  return 0;
}

static int
test_disk_format_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_format") == NULL;
  str = getenv ("SKIP_TEST_DISK_FORMAT_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_FORMAT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_format_2 (guestfs_h *g)
{
  if (test_disk_format_2_skip ()) {
    skipped ("test_disk_format_2", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for disk_format (2) */
  const char *_arg3184 = guestfs_get_private (g, "test3");
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, _arg3184);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "raw")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_disk_format_2", "disk_format", ret, "raw");
    return -1;
  }
  return 0;
}

static int
test_ls_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "ls") == NULL;
  str = getenv ("SKIP_TEST_LS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_ls_0 (guestfs_h *g)
{
  if (test_ls_0_skip ()) {
    skipped ("test_ls_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for ls (0) */
  const char *_arg3186 = "/ls";
  int ret4;
  ret4 = guestfs_mkdir (g, _arg3186);
  if (ret4 == -1)
    return -1;
  const char *_arg3188 = "/ls/new";
  int ret3;
  ret3 = guestfs_touch (g, _arg3188);
  if (ret3 == -1)
    return -1;
  const char *_arg3190 = "/ls/newer";
  int ret2;
  ret2 = guestfs_touch (g, _arg3190);
  if (ret2 == -1)
    return -1;
  const char *_arg3192 = "/ls/newest";
  int ret1;
  ret1 = guestfs_touch (g, _arg3192);
  if (ret1 == -1)
    return -1;
  const char *_arg3194 = "/ls";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_ls (g, _arg3194);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "new", "newer", "newest"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_ls_0", "is_string_list (ret, 3, \"new\", \"newer\", \"newest\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_write_append_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "write_append") == NULL;
  str = getenv ("SKIP_TEST_WRITE_APPEND_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WRITE_APPEND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_write_append_0 (guestfs_h *g)
{
  if (test_write_append_0_skip ()) {
    skipped ("test_write_append_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for write_append (0) */
  const char *_arg3197 = "/write_append";
  const char *_arg3198 = "line1\n";
  size_t _arg3198_size = 6;
  int _ret3196;
  _ret3196 = guestfs_write (g, _arg3197, _arg3198, _arg3198_size);
  if (_ret3196 == -1)
    return -1;
  const char *_arg3201 = "/write_append";
  const char *_arg3202 = "line2\n";
  size_t _arg3202_size = 6;
  int _ret3200;
  _ret3200 = guestfs_write_append (g, _arg3201, _arg3202, _arg3202_size);
  if (_ret3200 == -1)
    return -1;
  const char *_arg3205 = "/write_append";
  const char *_arg3206 = "line3a";
  size_t _arg3206_size = 6;
  int _ret3204;
  _ret3204 = guestfs_write_append (g, _arg3205, _arg3206, _arg3206_size);
  if (_ret3204 == -1)
    return -1;
  const char *_arg3209 = "/write_append";
  const char *_arg3210 = "line3b\n";
  size_t _arg3210_size = 7;
  int _ret3208;
  _ret3208 = guestfs_write_append (g, _arg3209, _arg3210, _arg3210_size);
  if (_ret3208 == -1)
    return -1;
  const char *_arg3212 = "/write_append";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3212);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "line1\nline2\nline3aline3b\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_append_0", "cat", ret, "line1\nline2\nline3aline3b\n");
    return -1;
  }
  return 0;
}

static int
test_write_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "write") == NULL;
  str = getenv ("SKIP_TEST_WRITE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_write_0 (guestfs_h *g)
{
  if (test_write_0_skip ()) {
    skipped ("test_write_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for write (0) */
  const char *_arg3215 = "/write";
  const char *_arg3216 = "new file contents";
  size_t _arg3216_size = 17;
  int _ret3214;
  _ret3214 = guestfs_write (g, _arg3215, _arg3216, _arg3216_size);
  if (_ret3214 == -1)
    return -1;
  const char *_arg3218 = "/write";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3218);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_0", "cat", ret, "new file contents");
    return -1;
  }
  return 0;
}

static int
test_write_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "write") == NULL;
  str = getenv ("SKIP_TEST_WRITE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_write_1 (guestfs_h *g)
{
  if (test_write_1_skip ()) {
    skipped ("test_write_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for write (1) */
  const char *_arg3221 = "/write2";
  const char *_arg3222 = "\nnew file contents\n";
  size_t _arg3222_size = 19;
  int _ret3220;
  _ret3220 = guestfs_write (g, _arg3221, _arg3222, _arg3222_size);
  if (_ret3220 == -1)
    return -1;
  const char *_arg3224 = "/write2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3224);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\nnew file contents\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_1", "cat", ret, "\nnew file contents\n");
    return -1;
  }
  return 0;
}

static int
test_write_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "write") == NULL;
  str = getenv ("SKIP_TEST_WRITE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_write_2 (guestfs_h *g)
{
  if (test_write_2_skip ()) {
    skipped ("test_write_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for write (2) */
  const char *_arg3227 = "/write3";
  const char *_arg3228 = "\n\n";
  size_t _arg3228_size = 2;
  int _ret3226;
  _ret3226 = guestfs_write (g, _arg3227, _arg3228, _arg3228_size);
  if (_ret3226 == -1)
    return -1;
  const char *_arg3230 = "/write3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3230);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_2", "cat", ret, "\n\n");
    return -1;
  }
  return 0;
}

static int
test_write_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "write") == NULL;
  str = getenv ("SKIP_TEST_WRITE_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_write_3 (guestfs_h *g)
{
  if (test_write_3_skip ()) {
    skipped ("test_write_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for write (3) */
  const char *_arg3233 = "/write4";
  const char *_arg3234 = "";
  size_t _arg3234_size = 0;
  int _ret3232;
  _ret3232 = guestfs_write (g, _arg3233, _arg3234, _arg3234_size);
  if (_ret3232 == -1)
    return -1;
  const char *_arg3236 = "/write4";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3236);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_3", "cat", ret, "");
    return -1;
  }
  return 0;
}

static int
test_write_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "write") == NULL;
  str = getenv ("SKIP_TEST_WRITE_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_write_4 (guestfs_h *g)
{
  if (test_write_4_skip ()) {
    skipped ("test_write_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for write (4) */
  const char *_arg3239 = "/write5";
  const char *_arg3240 = "\n\n\n";
  size_t _arg3240_size = 3;
  int _ret3238;
  _ret3238 = guestfs_write (g, _arg3239, _arg3240, _arg3240_size);
  if (_ret3238 == -1)
    return -1;
  const char *_arg3242 = "/write5";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3242);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_4", "cat", ret, "\n\n\n");
    return -1;
  }
  return 0;
}

static int
test_write_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "write") == NULL;
  str = getenv ("SKIP_TEST_WRITE_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WRITE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_write_5 (guestfs_h *g)
{
  if (test_write_5_skip ()) {
    skipped ("test_write_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for write (5) */
  const char *_arg3245 = "/write6";
  const char *_arg3246 = "\n";
  size_t _arg3246_size = 1;
  int _ret3244;
  _ret3244 = guestfs_write (g, _arg3245, _arg3246, _arg3246_size);
  if (_ret3244 == -1)
    return -1;
  const char *_arg3248 = "/write6";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3248);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_5", "cat", ret, "\n");
    return -1;
  }
  return 0;
}

static int
test_read_lines_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "read_lines") == NULL;
  str = getenv ("SKIP_TEST_READ_LINES_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_READ_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_read_lines_0 (guestfs_h *g)
{
  if (test_read_lines_0_skip ()) {
    skipped ("test_read_lines_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for read_lines (0) */
  const char *_arg3250 = "/known-4";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3250);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "abc", "def", "ghi"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_read_lines_0", "is_string_list (ret, 3, \"abc\", \"def\", \"ghi\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_read_lines_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "read_lines") == NULL;
  str = getenv ("SKIP_TEST_READ_LINES_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_READ_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_read_lines_1 (guestfs_h *g)
{
  if (test_read_lines_1_skip ()) {
    skipped ("test_read_lines_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for read_lines (1) */
  const char *_arg3252 = "/empty";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3252);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 0))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_read_lines_1", "is_string_list (ret, 0)");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_read_lines_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "read_lines") == NULL;
  str = getenv ("SKIP_TEST_READ_LINES_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_READ_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_read_lines_2 (guestfs_h *g)
{
  if (test_read_lines_2_skip ()) {
    skipped ("test_read_lines_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for read_lines (2) */
  const char *_arg3254 = "/read_lines1";
  const char *_arg3255 = "\n";
  size_t _arg3255_size = 1;
  int ret1;
  ret1 = guestfs_write (g, _arg3254, _arg3255, _arg3255_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3257 = "/read_lines1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3257);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 1, ""))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_read_lines_2", "is_string_list (ret, 1, \"\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_read_lines_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "read_lines") == NULL;
  str = getenv ("SKIP_TEST_READ_LINES_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_READ_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_read_lines_3 (guestfs_h *g)
{
  if (test_read_lines_3_skip ()) {
    skipped ("test_read_lines_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for read_lines (3) */
  const char *_arg3259 = "/read_lines2";
  const char *_arg3260 = "\r\n";
  size_t _arg3260_size = 2;
  int ret1;
  ret1 = guestfs_write (g, _arg3259, _arg3260, _arg3260_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3262 = "/read_lines2";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3262);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 1, ""))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_read_lines_3", "is_string_list (ret, 1, \"\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_read_lines_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "read_lines") == NULL;
  str = getenv ("SKIP_TEST_READ_LINES_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_READ_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_read_lines_4 (guestfs_h *g)
{
  if (test_read_lines_4_skip ()) {
    skipped ("test_read_lines_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for read_lines (4) */
  const char *_arg3264 = "/read_lines3";
  const char *_arg3265 = "\n\r\n";
  size_t _arg3265_size = 3;
  int ret1;
  ret1 = guestfs_write (g, _arg3264, _arg3265, _arg3265_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3267 = "/read_lines3";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3267);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "", ""))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_read_lines_4", "is_string_list (ret, 2, \"\", \"\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_read_lines_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "read_lines") == NULL;
  str = getenv ("SKIP_TEST_READ_LINES_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_READ_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_read_lines_5 (guestfs_h *g)
{
  if (test_read_lines_5_skip ()) {
    skipped ("test_read_lines_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for read_lines (5) */
  const char *_arg3269 = "/read_lines4";
  const char *_arg3270 = "a";
  size_t _arg3270_size = 1;
  int ret1;
  ret1 = guestfs_write (g, _arg3269, _arg3270, _arg3270_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3272 = "/read_lines4";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3272);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 1, "a"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_read_lines_5", "is_string_list (ret, 1, \"a\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_read_lines_6_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "read_lines") == NULL;
  str = getenv ("SKIP_TEST_READ_LINES_6");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_READ_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_read_lines_6 (guestfs_h *g)
{
  if (test_read_lines_6_skip ()) {
    skipped ("test_read_lines_6", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for read_lines (6) */
  const char *_arg3274 = "/read_lines5";
  const char *_arg3275 = "a\nb";
  size_t _arg3275_size = 3;
  int ret1;
  ret1 = guestfs_write (g, _arg3274, _arg3275, _arg3275_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3277 = "/read_lines5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3277);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "a", "b"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_read_lines_6", "is_string_list (ret, 2, \"a\", \"b\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_read_lines_7_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "read_lines") == NULL;
  str = getenv ("SKIP_TEST_READ_LINES_7");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_READ_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_read_lines_7 (guestfs_h *g)
{
  if (test_read_lines_7_skip ()) {
    skipped ("test_read_lines_7", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for read_lines (7) */
  const char *_arg3279 = "/read_lines6";
  const char *_arg3280 = "a\nb\n";
  size_t _arg3280_size = 4;
  int ret1;
  ret1 = guestfs_write (g, _arg3279, _arg3280, _arg3280_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3282 = "/read_lines6";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3282);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "a", "b"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_read_lines_7", "is_string_list (ret, 2, \"a\", \"b\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_read_lines_8_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "read_lines") == NULL;
  str = getenv ("SKIP_TEST_READ_LINES_8");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_READ_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_read_lines_8 (guestfs_h *g)
{
  if (test_read_lines_8_skip ()) {
    skipped ("test_read_lines_8", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for read_lines (8) */
  const char *_arg3284 = "/read_lines7";
  const char *_arg3285 = "a\nb\r\n";
  size_t _arg3285_size = 5;
  int ret1;
  ret1 = guestfs_write (g, _arg3284, _arg3285, _arg3285_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3287 = "/read_lines7";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3287);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "a", "b"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_read_lines_8", "is_string_list (ret, 2, \"a\", \"b\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_read_lines_9_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "read_lines") == NULL;
  str = getenv ("SKIP_TEST_READ_LINES_9");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_READ_LINES");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_read_lines_9 (guestfs_h *g)
{
  if (test_read_lines_9_skip ()) {
    skipped ("test_read_lines_9", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for read_lines (9) */
  const char *_arg3289 = "/read_lines8";
  const char *_arg3290 = "a\nb\r\n\n";
  size_t _arg3290_size = 6;
  int ret1;
  ret1 = guestfs_write (g, _arg3289, _arg3290, _arg3290_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3292 = "/read_lines8";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3292);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 3, "a", "b", ""))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_read_lines_9", "is_string_list (ret, 3, \"a\", \"b\", \"\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_read_file_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "read_file") == NULL;
  str = getenv ("SKIP_TEST_READ_FILE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_READ_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_read_file_0 (guestfs_h *g)
{
  if (test_read_file_0_skip ()) {
    skipped ("test_read_file_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResult for read_file (0) */
  const char *_arg3294 = "/known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg3294, &size);
  if (ret == NULL)
      return -1;
  if (! (compare_buffers (ret, size, "abc\ndef\nghi", 11) == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_read_file_0", "compare_buffers (ret, size, \"abc\\ndef\\nghi\", 11) == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_find_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "find") == NULL;
  str = getenv ("SKIP_TEST_FIND_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FIND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_find_0 (guestfs_h *g)
{
  if (test_find_0_skip ()) {
    skipped ("test_find_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResult for find (0) */
  const char *_arg3296 = "/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, _arg3296);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 1, "lost+found"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_find_0", "is_string_list (ret, 1, \"lost+found\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_find_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "find") == NULL;
  str = getenv ("SKIP_TEST_FIND_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FIND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_find_1 (guestfs_h *g)
{
  if (test_find_1_skip ()) {
    skipped ("test_find_1", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResult for find (1) */
  const char *_arg3298 = "/a";
  int ret3;
  ret3 = guestfs_touch (g, _arg3298);
  if (ret3 == -1)
    return -1;
  const char *_arg3300 = "/b";
  int ret2;
  ret2 = guestfs_mkdir (g, _arg3300);
  if (ret2 == -1)
    return -1;
  const char *_arg3302 = "/b/c";
  int ret1;
  ret1 = guestfs_touch (g, _arg3302);
  if (ret1 == -1)
    return -1;
  const char *_arg3304 = "/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, _arg3304);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 4, "a", "b", "b/c", "lost+found"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_find_1", "is_string_list (ret, 4, \"a\", \"b\", \"b/c\", \"lost+found\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_find_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "find") == NULL;
  str = getenv ("SKIP_TEST_FIND_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FIND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_find_2 (guestfs_h *g)
{
  if (test_find_2_skip ()) {
    skipped ("test_find_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for find (2) */
  const char *_arg3306 = "/find/b/c";
  int ret2;
  ret2 = guestfs_mkdir_p (g, _arg3306);
  if (ret2 == -1)
    return -1;
  const char *_arg3308 = "/find/b/c/d";
  int ret1;
  ret1 = guestfs_touch (g, _arg3308);
  if (ret1 == -1)
    return -1;
  const char *_arg3310 = "/find/b/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, _arg3310);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "c", "c/d"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_find_2", "is_string_list (ret, 2, \"c\", \"c/d\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_cat_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "cat") == NULL;
  str = getenv ("SKIP_TEST_CAT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CAT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_cat_0 (guestfs_h *g)
{
  if (test_cat_0_skip ()) {
    skipped ("test_cat_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for cat (0) */
  const char *_arg3312 = "/known-2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3312);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "abcdef\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_cat_0", "cat", ret, "abcdef\n");
    return -1;
  }
  return 0;
}

static int
test_get_backend_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_backend") == NULL;
  str = getenv ("SKIP_TEST_GET_BACKEND_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_BACKEND");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_backend_0 (guestfs_h *g)
{
  if (test_get_backend_0_skip ()) {
    skipped ("test_get_backend_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for get_backend (0) */
  CLEANUP_FREE char *_ret3314;
  _ret3314 = guestfs_get_backend (g);
  if (_ret3314 == NULL)
      return -1;
  return 0;
}

static int
test_get_attach_method_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_attach_method") == NULL;
  str = getenv ("SKIP_TEST_GET_ATTACH_METHOD_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_ATTACH_METHOD");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_attach_method_0 (guestfs_h *g)
{
  if (test_get_attach_method_0_skip ()) {
    skipped ("test_get_attach_method_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for get_attach_method (0) */
  CLEANUP_FREE char *_ret3316;
  _ret3316 = guestfs_get_attach_method (g);
  if (_ret3316 == NULL)
      return -1;
  return 0;
}

static int
test_file_architecture_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_0 (guestfs_h *g)
{
  if (test_file_architecture_0_skip ()) {
    skipped ("test_file_architecture_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file_architecture (0) */
  const char *_arg3318 = "/bin-i586-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3318);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "i386")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_0", "file_architecture", ret, "i386");
    return -1;
  }
  return 0;
}

static int
test_file_architecture_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_1 (guestfs_h *g)
{
  if (test_file_architecture_1_skip ()) {
    skipped ("test_file_architecture_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file_architecture (1) */
  const char *_arg3320 = "/bin-sparc-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3320);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "sparc")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_1", "file_architecture", ret, "sparc");
    return -1;
  }
  return 0;
}

static int
test_file_architecture_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_2 (guestfs_h *g)
{
  if (test_file_architecture_2_skip ()) {
    skipped ("test_file_architecture_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file_architecture (2) */
  const char *_arg3322 = "/bin-win32.exe";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3322);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "i386")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_2", "file_architecture", ret, "i386");
    return -1;
  }
  return 0;
}

static int
test_file_architecture_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_3 (guestfs_h *g)
{
  if (test_file_architecture_3_skip ()) {
    skipped ("test_file_architecture_3", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file_architecture (3) */
  const char *_arg3324 = "/bin-win64.exe";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3324);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "x86_64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_3", "file_architecture", ret, "x86_64");
    return -1;
  }
  return 0;
}

static int
test_file_architecture_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_4 (guestfs_h *g)
{
  if (test_file_architecture_4_skip ()) {
    skipped ("test_file_architecture_4", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file_architecture (4) */
  const char *_arg3326 = "/bin-x86_64-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3326);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "x86_64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_4", "file_architecture", ret, "x86_64");
    return -1;
  }
  return 0;
}

static int
test_file_architecture_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_5 (guestfs_h *g)
{
  if (test_file_architecture_5_skip ()) {
    skipped ("test_file_architecture_5", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file_architecture (5) */
  const char *_arg3328 = "/lib-i586.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3328);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "i386")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_5", "file_architecture", ret, "i386");
    return -1;
  }
  return 0;
}

static int
test_file_architecture_6_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_6");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_6 (guestfs_h *g)
{
  if (test_file_architecture_6_skip ()) {
    skipped ("test_file_architecture_6", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file_architecture (6) */
  const char *_arg3330 = "/lib-sparc.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3330);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "sparc")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_6", "file_architecture", ret, "sparc");
    return -1;
  }
  return 0;
}

static int
test_file_architecture_7_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_7");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_7 (guestfs_h *g)
{
  if (test_file_architecture_7_skip ()) {
    skipped ("test_file_architecture_7", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file_architecture (7) */
  const char *_arg3332 = "/lib-win32.dll";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3332);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "i386")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_7", "file_architecture", ret, "i386");
    return -1;
  }
  return 0;
}

static int
test_file_architecture_8_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_8");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_8 (guestfs_h *g)
{
  if (test_file_architecture_8_skip ()) {
    skipped ("test_file_architecture_8", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file_architecture (8) */
  const char *_arg3334 = "/lib-win64.dll";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3334);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "x86_64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_8", "file_architecture", ret, "x86_64");
    return -1;
  }
  return 0;
}

static int
test_file_architecture_9_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_9");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_9 (guestfs_h *g)
{
  if (test_file_architecture_9_skip ()) {
    skipped ("test_file_architecture_9", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file_architecture (9) */
  const char *_arg3336 = "/lib-x86_64.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3336);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "x86_64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_9", "file_architecture", ret, "x86_64");
    return -1;
  }
  return 0;
}

static int
test_file_architecture_10_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_10");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_10 (guestfs_h *g)
{
  if (test_file_architecture_10_skip ()) {
    skipped ("test_file_architecture_10", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file_architecture (10) */
  const char *_arg3338 = "/initrd-x86_64.img";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3338);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "x86_64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_10", "file_architecture", ret, "x86_64");
    return -1;
  }
  return 0;
}

static int
test_file_architecture_11_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_11");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_11 (guestfs_h *g)
{
  if (test_file_architecture_11_skip ()) {
    skipped ("test_file_architecture_11", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for file_architecture (11) */
  const char *_arg3340 = "/initrd-x86_64.img.gz";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3340);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "x86_64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_11", "file_architecture", ret, "x86_64");
    return -1;
  }
  return 0;
}

static int
test_set_trace_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_trace") == NULL;
  str = getenv ("SKIP_TEST_SET_TRACE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_TRACE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_set_trace_0 (guestfs_h *g)
{
  if (test_set_trace_0_skip ()) {
    skipped ("test_set_trace_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultFalse for set_trace (0) */
  int _ret3342;
  _ret3342 = guestfs_set_trace (g, 0);
  if (_ret3342 == -1)
    return -1;
  int ret;
  ret = guestfs_get_trace (g);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_set_trace_0", "get_trace");
    return -1;
  }
  return 0;
}

static int
test_version_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "version") == NULL;
  str = getenv ("SKIP_TEST_VERSION_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VERSION");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_version_0 (guestfs_h *g)
{
  if (test_version_0_skip ()) {
    skipped ("test_version_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResult for version (0) */
  CLEANUP_FREE_VERSION struct guestfs_version *ret;
  ret = guestfs_version (g);
  if (ret == NULL)
      return -1;
  if (! (ret->major == 1)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_version_0", "ret->major == 1");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_get_memsize_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_memsize") == NULL;
  str = getenv ("SKIP_TEST_GET_MEMSIZE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_MEMSIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_memsize_0 (guestfs_h *g)
{
  if (test_get_memsize_0_skip ()) {
    skipped ("test_get_memsize_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResult for get_memsize (0) */
  int ret;
  ret = guestfs_get_memsize (g);
  if (ret == -1)
    return -1;
  if (! (ret >= 256)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_get_memsize_0", "ret >= 256");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_is_busy_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_busy") == NULL;
  str = getenv ("SKIP_TEST_IS_BUSY_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_BUSY");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_busy_0 (guestfs_h *g)
{
  if (test_is_busy_0_skip ()) {
    skipped ("test_is_busy_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultFalse for is_busy (0) */
  int ret;
  ret = guestfs_is_busy (g);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_busy_0", "is_busy");
    return -1;
  }
  return 0;
}

static int
test_is_launching_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_launching") == NULL;
  str = getenv ("SKIP_TEST_IS_LAUNCHING_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_LAUNCHING");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_launching_0 (guestfs_h *g)
{
  if (test_is_launching_0_skip ()) {
    skipped ("test_is_launching_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultFalse for is_launching (0) */
  int ret;
  ret = guestfs_is_launching (g);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_launching_0", "is_launching");
    return -1;
  }
  return 0;
}

static int
test_is_config_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_config") == NULL;
  str = getenv ("SKIP_TEST_IS_CONFIG_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_CONFIG");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_config_0 (guestfs_h *g)
{
  if (test_is_config_0_skip ()) {
    skipped ("test_is_config_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultFalse for is_config (0) */
  int ret;
  ret = guestfs_is_config (g);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_config_0", "is_config");
    return -1;
  }
  return 0;
}

static int
test_is_ready_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_ready") == NULL;
  str = getenv ("SKIP_TEST_IS_READY_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_READY");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_ready_0 (guestfs_h *g)
{
  if (test_is_ready_0_skip ()) {
    skipped ("test_is_ready_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultTrue for is_ready (0) */
  int ret;
  ret = guestfs_is_ready (g);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_ready_0", "is_ready");
    return -1;
  }
  return 0;
}

static int
test_get_autosync_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_autosync") == NULL;
  str = getenv ("SKIP_TEST_GET_AUTOSYNC_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_AUTOSYNC");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_autosync_0 (guestfs_h *g)
{
  if (test_get_autosync_0_skip ()) {
    skipped ("test_get_autosync_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultTrue for get_autosync (0) */
  int ret;
  ret = guestfs_get_autosync (g);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_get_autosync_0", "get_autosync");
    return -1;
  }
  return 0;
}

static int
test_get_path_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_path") == NULL;
  str = getenv ("SKIP_TEST_GET_PATH_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_PATH");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_path_0 (guestfs_h *g)
{
  if (test_get_path_0_skip ()) {
    skipped ("test_get_path_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for get_path (0) */
  const char *_ret3353;
  _ret3353 = guestfs_get_path (g);
  if (_ret3353 == NULL)
      return -1;
  return 0;
}

static int
test_get_qemu_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_qemu") == NULL;
  str = getenv ("SKIP_TEST_GET_QEMU_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_QEMU");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_qemu_0 (guestfs_h *g)
{
  if (test_get_qemu_0_skip ()) {
    skipped ("test_get_qemu_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for get_qemu (0) */
  const char *_ret3355;
  _ret3355 = guestfs_get_qemu (g);
  if (_ret3355 == NULL)
      return -1;
  return 0;
}

size_t nr_tests = 427;

struct test tests[427] = {
  { .name = "test_feature_available_0", .test_fn = test_feature_available_0 },
  { .name = "test_is_whole_device_0", .test_fn = test_is_whole_device_0 },
  { .name = "test_is_whole_device_1", .test_fn = test_is_whole_device_1 },
  { .name = "test_is_whole_device_2", .test_fn = test_is_whole_device_2 },
  { .name = "test_rename_0", .test_fn = test_rename_0 },
  { .name = "test_part_get_gpt_type_0", .test_fn = test_part_get_gpt_type_0 },
  { .name = "test_cap_set_file_0", .test_fn = test_cap_set_file_0 },
  { .name = "test_acl_delete_def_file_0", .test_fn = test_acl_delete_def_file_0 },
  { .name = "test_acl_delete_def_file_1", .test_fn = test_acl_delete_def_file_1 },
  { .name = "test_acl_set_file_0", .test_fn = test_acl_set_file_0 },
  { .name = "test_mklost_and_found_0", .test_fn = test_mklost_and_found_0 },
  { .name = "test_mktemp_0", .test_fn = test_mktemp_0 },
  { .name = "test_mke2fs_0", .test_fn = test_mke2fs_0 },
  { .name = "test_mke2fs_1", .test_fn = test_mke2fs_1 },
  { .name = "test_mke2fs_2", .test_fn = test_mke2fs_2 },
  { .name = "test_rm_f_0", .test_fn = test_rm_f_0 },
  { .name = "test_rm_f_1", .test_fn = test_rm_f_1 },
  { .name = "test_xfs_repair_0", .test_fn = test_xfs_repair_0 },
  { .name = "test_xfs_admin_0", .test_fn = test_xfs_admin_0 },
  { .name = "test_xfs_growfs_0", .test_fn = test_xfs_growfs_0 },
  { .name = "test_utsname_0", .test_fn = test_utsname_0 },
  { .name = "test_vgchange_uuid_all_0", .test_fn = test_vgchange_uuid_all_0 },
  { .name = "test_vgchange_uuid_0", .test_fn = test_vgchange_uuid_0 },
  { .name = "test_pvchange_uuid_all_0", .test_fn = test_pvchange_uuid_all_0 },
  { .name = "test_pvchange_uuid_0", .test_fn = test_pvchange_uuid_0 },
  { .name = "test_xfs_info_0", .test_fn = test_xfs_info_0 },
  { .name = "test_nr_devices_0", .test_fn = test_nr_devices_0 },
  { .name = "test_device_index_0", .test_fn = test_device_index_0 },
  { .name = "test_btrfs_fsck_0", .test_fn = test_btrfs_fsck_0 },
  { .name = "test_btrfs_set_seeding_0", .test_fn = test_btrfs_set_seeding_0 },
  { .name = "test_btrfs_filesystem_sync_0", .test_fn = test_btrfs_filesystem_sync_0 },
  { .name = "test_btrfs_subvolume_delete_0", .test_fn = test_btrfs_subvolume_delete_0 },
  { .name = "test_btrfs_subvolume_snapshot_0", .test_fn = test_btrfs_subvolume_snapshot_0 },
  { .name = "test_get_e2generation_0", .test_fn = test_get_e2generation_0 },
  { .name = "test_get_e2attrs_0", .test_fn = test_get_e2attrs_0 },
  { .name = "test_get_e2attrs_1", .test_fn = test_get_e2attrs_1 },
  { .name = "test_get_e2attrs_2", .test_fn = test_get_e2attrs_2 },
  { .name = "test_get_e2attrs_3", .test_fn = test_get_e2attrs_3 },
  { .name = "test_get_e2attrs_4", .test_fn = test_get_e2attrs_4 },
  { .name = "test_get_e2attrs_5", .test_fn = test_get_e2attrs_5 },
  { .name = "test_get_e2attrs_6", .test_fn = test_get_e2attrs_6 },
  { .name = "test_get_e2attrs_7", .test_fn = test_get_e2attrs_7 },
  { .name = "test_mkfs_btrfs_0", .test_fn = test_mkfs_btrfs_0 },
  { .name = "test_isoinfo_device_0", .test_fn = test_isoinfo_device_0 },
  { .name = "test_lvcreate_free_0", .test_fn = test_lvcreate_free_0 },
  { .name = "test_zero_free_space_0", .test_fn = test_zero_free_space_0 },
  { .name = "test_set_label_0", .test_fn = test_set_label_0 },
  { .name = "test_set_label_1", .test_fn = test_set_label_1 },
  { .name = "test_set_label_2", .test_fn = test_set_label_2 },
  { .name = "test_ntfsfix_0", .test_fn = test_ntfsfix_0 },
  { .name = "test_wipefs_0", .test_fn = test_wipefs_0 },
  { .name = "test_blkid_0", .test_fn = test_blkid_0 },
  { .name = "test_tune2fs_0", .test_fn = test_tune2fs_0 },
  { .name = "test_tune2fs_1", .test_fn = test_tune2fs_1 },
  { .name = "test_tune2fs_2", .test_fn = test_tune2fs_2 },
  { .name = "test_tune2fs_3", .test_fn = test_tune2fs_3 },
  { .name = "test_copy_file_to_file_0", .test_fn = test_copy_file_to_file_0 },
  { .name = "test_copy_file_to_file_1", .test_fn = test_copy_file_to_file_1 },
  { .name = "test_part_to_partnum_0", .test_fn = test_part_to_partnum_0 },
  { .name = "test_part_to_partnum_1", .test_fn = test_part_to_partnum_1 },
  { .name = "test_internal_write_append_0", .test_fn = test_internal_write_append_0 },
  { .name = "test_is_zero_device_0", .test_fn = test_is_zero_device_0 },
  { .name = "test_is_zero_device_1", .test_fn = test_is_zero_device_1 },
  { .name = "test_is_zero_0", .test_fn = test_is_zero_0 },
  { .name = "test_is_zero_1", .test_fn = test_is_zero_1 },
  { .name = "test_mkfs_0", .test_fn = test_mkfs_0 },
  { .name = "test_lvm_canonical_lv_name_0", .test_fn = test_lvm_canonical_lv_name_0 },
  { .name = "test_lvm_canonical_lv_name_1", .test_fn = test_lvm_canonical_lv_name_1 },
  { .name = "test_pread_device_0", .test_fn = test_pread_device_0 },
  { .name = "test_pwrite_device_0", .test_fn = test_pwrite_device_0 },
  { .name = "test_download_offset_0", .test_fn = test_download_offset_0 },
  { .name = "test_upload_offset_0", .test_fn = test_upload_offset_0 },
  { .name = "test_part_to_dev_0", .test_fn = test_part_to_dev_0 },
  { .name = "test_part_to_dev_1", .test_fn = test_part_to_dev_1 },
  { .name = "test_is_socket_0", .test_fn = test_is_socket_0 },
  { .name = "test_is_symlink_0", .test_fn = test_is_symlink_0 },
  { .name = "test_is_symlink_1", .test_fn = test_is_symlink_1 },
  { .name = "test_is_fifo_0", .test_fn = test_is_fifo_0 },
  { .name = "test_is_fifo_1", .test_fn = test_is_fifo_1 },
  { .name = "test_is_blockdev_0", .test_fn = test_is_blockdev_0 },
  { .name = "test_is_blockdev_1", .test_fn = test_is_blockdev_1 },
  { .name = "test_is_chardev_0", .test_fn = test_is_chardev_0 },
  { .name = "test_is_chardev_1", .test_fn = test_is_chardev_1 },
  { .name = "test_is_lv_0", .test_fn = test_is_lv_0 },
  { .name = "test_is_lv_1", .test_fn = test_is_lv_1 },
  { .name = "test_vfs_uuid_0", .test_fn = test_vfs_uuid_0 },
  { .name = "test_vfs_label_0", .test_fn = test_vfs_label_0 },
  { .name = "test_fallocate64_0", .test_fn = test_fallocate64_0 },
  { .name = "test_available_all_groups_0", .test_fn = test_available_all_groups_0 },
  { .name = "test_pwrite_0", .test_fn = test_pwrite_0 },
  { .name = "test_pwrite_1", .test_fn = test_pwrite_1 },
  { .name = "test_pwrite_2", .test_fn = test_pwrite_2 },
  { .name = "test_internal_write_0", .test_fn = test_internal_write_0 },
  { .name = "test_internal_write_1", .test_fn = test_internal_write_1 },
  { .name = "test_internal_write_2", .test_fn = test_internal_write_2 },
  { .name = "test_internal_write_3", .test_fn = test_internal_write_3 },
  { .name = "test_internal_write_4", .test_fn = test_internal_write_4 },
  { .name = "test_internal_write_5", .test_fn = test_internal_write_5 },
  { .name = "test_fill_pattern_0", .test_fn = test_fill_pattern_0 },
  { .name = "test_base64_in_0", .test_fn = test_base64_in_0 },
  { .name = "test_get_umask_0", .test_fn = test_get_umask_0 },
  { .name = "test_lvresize_free_0", .test_fn = test_lvresize_free_0 },
  { .name = "test_checksum_device_0", .test_fn = test_checksum_device_0 },
  { .name = "test_part_get_mbr_id_0", .test_fn = test_part_get_mbr_id_0 },
  { .name = "test_part_get_bootable_0", .test_fn = test_part_get_bootable_0 },
  { .name = "test_part_del_0", .test_fn = test_part_del_0 },
  { .name = "test_vgscan_0", .test_fn = test_vgscan_0 },
  { .name = "test_txz_in_0", .test_fn = test_txz_in_0 },
  { .name = "test_zero_device_0", .test_fn = test_zero_device_0 },
  { .name = "test_copy_size_0", .test_fn = test_copy_size_0 },
  { .name = "test_initrd_cat_0", .test_fn = test_initrd_cat_0 },
  { .name = "test_vgrename_0", .test_fn = test_vgrename_0 },
  { .name = "test_lvrename_0", .test_fn = test_lvrename_0 },
  { .name = "test_filesize_0", .test_fn = test_filesize_0 },
  { .name = "test_dd_0", .test_fn = test_dd_0 },
  { .name = "test_available_0", .test_fn = test_available_0 },
  { .name = "test_fill_0", .test_fn = test_fill_0 },
  { .name = "test_part_get_parttype_0", .test_fn = test_part_get_parttype_0 },
  { .name = "test_part_set_name_0", .test_fn = test_part_set_name_0 },
  { .name = "test_part_set_bootable_0", .test_fn = test_part_set_bootable_0 },
  { .name = "test_part_disk_0", .test_fn = test_part_disk_0 },
  { .name = "test_part_disk_1", .test_fn = test_part_disk_1 },
  { .name = "test_part_add_0", .test_fn = test_part_add_0 },
  { .name = "test_part_add_1", .test_fn = test_part_add_1 },
  { .name = "test_part_add_2", .test_fn = test_part_add_2 },
  { .name = "test_part_init_0", .test_fn = test_part_init_0 },
  { .name = "test_pread_0", .test_fn = test_pread_0 },
  { .name = "test_pread_1", .test_fn = test_pread_1 },
  { .name = "test_mkdir_mode_0", .test_fn = test_mkdir_mode_0 },
  { .name = "test_utimens_0", .test_fn = test_utimens_0 },
  { .name = "test_utimens_1", .test_fn = test_utimens_1 },
  { .name = "test_utimens_2", .test_fn = test_utimens_2 },
  { .name = "test_utimens_3", .test_fn = test_utimens_3 },
  { .name = "test_utimens_4", .test_fn = test_utimens_4 },
  { .name = "test_utimens_5", .test_fn = test_utimens_5 },
  { .name = "test_truncate_size_0", .test_fn = test_truncate_size_0 },
  { .name = "test_truncate_0", .test_fn = test_truncate_0 },
  { .name = "test_vfs_type_0", .test_fn = test_vfs_type_0 },
  { .name = "test_case_sensitive_path_0", .test_fn = test_case_sensitive_path_0 },
  { .name = "test_case_sensitive_path_1", .test_fn = test_case_sensitive_path_1 },
  { .name = "test_case_sensitive_path_2", .test_fn = test_case_sensitive_path_2 },
  { .name = "test_case_sensitive_path_3", .test_fn = test_case_sensitive_path_3 },
  { .name = "test_case_sensitive_path_4", .test_fn = test_case_sensitive_path_4 },
  { .name = "test_case_sensitive_path_5", .test_fn = test_case_sensitive_path_5 },
  { .name = "test_case_sensitive_path_6", .test_fn = test_case_sensitive_path_6 },
  { .name = "test_case_sensitive_path_7", .test_fn = test_case_sensitive_path_7 },
  { .name = "test_echo_daemon_0", .test_fn = test_echo_daemon_0 },
  { .name = "test_modprobe_0", .test_fn = test_modprobe_0 },
  { .name = "test_mke2journal_U_0", .test_fn = test_mke2journal_U_0 },
  { .name = "test_mke2journal_L_0", .test_fn = test_mke2journal_L_0 },
  { .name = "test_mke2journal_0", .test_fn = test_mke2journal_0 },
  { .name = "test_mkfs_b_0", .test_fn = test_mkfs_b_0 },
  { .name = "test_mkfs_b_1", .test_fn = test_mkfs_b_1 },
  { .name = "test_mkfs_b_2", .test_fn = test_mkfs_b_2 },
  { .name = "test_mkfs_b_3", .test_fn = test_mkfs_b_3 },
  { .name = "test_mkfs_b_4", .test_fn = test_mkfs_b_4 },
  { .name = "test_inotify_add_watch_0", .test_fn = test_inotify_add_watch_0 },
  { .name = "test_inotify_init_0", .test_fn = test_inotify_init_0 },
  { .name = "test_mkswap_file_0", .test_fn = test_mkswap_file_0 },
  { .name = "test_swapon_uuid_0", .test_fn = test_swapon_uuid_0 },
  { .name = "test_swapon_label_0", .test_fn = test_swapon_label_0 },
  { .name = "test_swapon_file_0", .test_fn = test_swapon_file_0 },
  { .name = "test_swapon_device_0", .test_fn = test_swapon_device_0 },
  { .name = "test_fallocate_0", .test_fn = test_fallocate_0 },
  { .name = "test_ln_sf_0", .test_fn = test_ln_sf_0 },
  { .name = "test_ln_s_0", .test_fn = test_ln_s_0 },
  { .name = "test_ln_f_0", .test_fn = test_ln_f_0 },
  { .name = "test_ln_0", .test_fn = test_ln_0 },
  { .name = "test_realpath_0", .test_fn = test_realpath_0 },
  { .name = "test_zfgrepi_0", .test_fn = test_zfgrepi_0 },
  { .name = "test_zegrepi_0", .test_fn = test_zegrepi_0 },
  { .name = "test_zgrepi_0", .test_fn = test_zgrepi_0 },
  { .name = "test_zfgrep_0", .test_fn = test_zfgrep_0 },
  { .name = "test_zegrep_0", .test_fn = test_zegrep_0 },
  { .name = "test_zgrep_0", .test_fn = test_zgrep_0 },
  { .name = "test_fgrepi_0", .test_fn = test_fgrepi_0 },
  { .name = "test_egrepi_0", .test_fn = test_egrepi_0 },
  { .name = "test_grepi_0", .test_fn = test_grepi_0 },
  { .name = "test_fgrep_0", .test_fn = test_fgrep_0 },
  { .name = "test_egrep_0", .test_fn = test_egrep_0 },
  { .name = "test_grep_0", .test_fn = test_grep_0 },
  { .name = "test_grep_1", .test_fn = test_grep_1 },
  { .name = "test_grep_2", .test_fn = test_grep_2 },
  { .name = "test_grep_3", .test_fn = test_grep_3 },
  { .name = "test_grep_4", .test_fn = test_grep_4 },
  { .name = "test_grep_5", .test_fn = test_grep_5 },
  { .name = "test_grep_6", .test_fn = test_grep_6 },
  { .name = "test_grep_7", .test_fn = test_grep_7 },
  { .name = "test_grep_8", .test_fn = test_grep_8 },
  { .name = "test_grep_9", .test_fn = test_grep_9 },
  { .name = "test_grep_10", .test_fn = test_grep_10 },
  { .name = "test_grep_11", .test_fn = test_grep_11 },
  { .name = "test_grep_12", .test_fn = test_grep_12 },
  { .name = "test_grep_13", .test_fn = test_grep_13 },
  { .name = "test_umask_0", .test_fn = test_umask_0 },
  { .name = "test_mknod_c_0", .test_fn = test_mknod_c_0 },
  { .name = "test_mknod_b_0", .test_fn = test_mknod_b_0 },
  { .name = "test_mkfifo_0", .test_fn = test_mkfifo_0 },
  { .name = "test_mknod_0", .test_fn = test_mknod_0 },
  { .name = "test_mknod_1", .test_fn = test_mknod_1 },
  { .name = "test_mkswap_U_0", .test_fn = test_mkswap_U_0 },
  { .name = "test_mkswap_L_0", .test_fn = test_mkswap_L_0 },
  { .name = "test_mkswap_0", .test_fn = test_mkswap_0 },
  { .name = "test_mkswap_1", .test_fn = test_mkswap_1 },
  { .name = "test_mkswap_2", .test_fn = test_mkswap_2 },
  { .name = "test_mkswap_3", .test_fn = test_mkswap_3 },
  { .name = "test_initrd_list_0", .test_fn = test_initrd_list_0 },
  { .name = "test_du_0", .test_fn = test_du_0 },
  { .name = "test_tail_n_0", .test_fn = test_tail_n_0 },
  { .name = "test_tail_n_1", .test_fn = test_tail_n_1 },
  { .name = "test_tail_n_2", .test_fn = test_tail_n_2 },
  { .name = "test_tail_0", .test_fn = test_tail_0 },
  { .name = "test_head_n_0", .test_fn = test_head_n_0 },
  { .name = "test_head_n_1", .test_fn = test_head_n_1 },
  { .name = "test_head_n_2", .test_fn = test_head_n_2 },
  { .name = "test_head_0", .test_fn = test_head_0 },
  { .name = "test_head_1", .test_fn = test_head_1 },
  { .name = "test_wc_c_0", .test_fn = test_wc_c_0 },
  { .name = "test_wc_w_0", .test_fn = test_wc_w_0 },
  { .name = "test_wc_l_0", .test_fn = test_wc_l_0 },
  { .name = "test_wc_l_1", .test_fn = test_wc_l_1 },
  { .name = "test_mkdtemp_0", .test_fn = test_mkdtemp_0 },
  { .name = "test_scrub_file_0", .test_fn = test_scrub_file_0 },
  { .name = "test_scrub_device_0", .test_fn = test_scrub_device_0 },
  { .name = "test_glob_expand_0", .test_fn = test_glob_expand_0 },
  { .name = "test_glob_expand_1", .test_fn = test_glob_expand_1 },
  { .name = "test_glob_expand_2", .test_fn = test_glob_expand_2 },
  { .name = "test_ntfs_3g_probe_0", .test_fn = test_ntfs_3g_probe_0 },
  { .name = "test_ntfs_3g_probe_1", .test_fn = test_ntfs_3g_probe_1 },
  { .name = "test_sleep_0", .test_fn = test_sleep_0 },
  { .name = "test_lvresize_0", .test_fn = test_lvresize_0 },
  { .name = "test_lvresize_1", .test_fn = test_lvresize_1 },
  { .name = "test_zerofree_0", .test_fn = test_zerofree_0 },
  { .name = "test_hexdump_0", .test_fn = test_hexdump_0 },
  { .name = "test_hexdump_1", .test_fn = test_hexdump_1 },
  { .name = "test_hexdump_2", .test_fn = test_hexdump_2 },
  { .name = "test_strings_e_0", .test_fn = test_strings_e_0 },
  { .name = "test_strings_e_1", .test_fn = test_strings_e_1 },
  { .name = "test_strings_0", .test_fn = test_strings_0 },
  { .name = "test_strings_1", .test_fn = test_strings_1 },
  { .name = "test_strings_2", .test_fn = test_strings_2 },
  { .name = "test_equal_0", .test_fn = test_equal_0 },
  { .name = "test_equal_1", .test_fn = test_equal_1 },
  { .name = "test_equal_2", .test_fn = test_equal_2 },
  { .name = "test_ping_daemon_0", .test_fn = test_ping_daemon_0 },
  { .name = "test_dmesg_0", .test_fn = test_dmesg_0 },
  { .name = "test_drop_caches_0", .test_fn = test_drop_caches_0 },
  { .name = "test_mv_0", .test_fn = test_mv_0 },
  { .name = "test_mv_1", .test_fn = test_mv_1 },
  { .name = "test_cp_a_0", .test_fn = test_cp_a_0 },
  { .name = "test_cp_0", .test_fn = test_cp_0 },
  { .name = "test_cp_1", .test_fn = test_cp_1 },
  { .name = "test_cp_2", .test_fn = test_cp_2 },
  { .name = "test_grub_install_0", .test_fn = test_grub_install_0 },
  { .name = "test_zero_0", .test_fn = test_zero_0 },
  { .name = "test_fsck_0", .test_fn = test_fsck_0 },
  { .name = "test_fsck_1", .test_fn = test_fsck_1 },
  { .name = "test_get_e2uuid_0", .test_fn = test_get_e2uuid_0 },
  { .name = "test_set_e2uuid_0", .test_fn = test_set_e2uuid_0 },
  { .name = "test_set_e2uuid_1", .test_fn = test_set_e2uuid_1 },
  { .name = "test_set_e2uuid_2", .test_fn = test_set_e2uuid_2 },
  { .name = "test_set_e2uuid_3", .test_fn = test_set_e2uuid_3 },
  { .name = "test_set_e2label_0", .test_fn = test_set_e2label_0 },
  { .name = "test_pvremove_0", .test_fn = test_pvremove_0 },
  { .name = "test_pvremove_1", .test_fn = test_pvremove_1 },
  { .name = "test_pvremove_2", .test_fn = test_pvremove_2 },
  { .name = "test_vgremove_0", .test_fn = test_vgremove_0 },
  { .name = "test_vgremove_1", .test_fn = test_vgremove_1 },
  { .name = "test_lvremove_0", .test_fn = test_lvremove_0 },
  { .name = "test_lvremove_1", .test_fn = test_lvremove_1 },
  { .name = "test_lvremove_2", .test_fn = test_lvremove_2 },
  { .name = "test_mount_ro_0", .test_fn = test_mount_ro_0 },
  { .name = "test_mount_ro_1", .test_fn = test_mount_ro_1 },
  { .name = "test_tgz_in_0", .test_fn = test_tgz_in_0 },
  { .name = "test_tar_in_0", .test_fn = test_tar_in_0 },
  { .name = "test_tar_in_1", .test_fn = test_tar_in_1 },
  { .name = "test_tar_in_2", .test_fn = test_tar_in_2 },
  { .name = "test_checksum_0", .test_fn = test_checksum_0 },
  { .name = "test_checksum_1", .test_fn = test_checksum_1 },
  { .name = "test_checksum_2", .test_fn = test_checksum_2 },
  { .name = "test_checksum_3", .test_fn = test_checksum_3 },
  { .name = "test_checksum_4", .test_fn = test_checksum_4 },
  { .name = "test_checksum_5", .test_fn = test_checksum_5 },
  { .name = "test_checksum_6", .test_fn = test_checksum_6 },
  { .name = "test_checksum_7", .test_fn = test_checksum_7 },
  { .name = "test_checksum_8", .test_fn = test_checksum_8 },
  { .name = "test_download_0", .test_fn = test_download_0 },
  { .name = "test_upload_0", .test_fn = test_upload_0 },
  { .name = "test_blockdev_rereadpt_0", .test_fn = test_blockdev_rereadpt_0 },
  { .name = "test_blockdev_flushbufs_0", .test_fn = test_blockdev_flushbufs_0 },
  { .name = "test_blockdev_getsize64_0", .test_fn = test_blockdev_getsize64_0 },
  { .name = "test_blockdev_getsz_0", .test_fn = test_blockdev_getsz_0 },
  { .name = "test_blockdev_getss_0", .test_fn = test_blockdev_getss_0 },
  { .name = "test_blockdev_getro_0", .test_fn = test_blockdev_getro_0 },
  { .name = "test_blockdev_setrw_0", .test_fn = test_blockdev_setrw_0 },
  { .name = "test_blockdev_setro_0", .test_fn = test_blockdev_setro_0 },
  { .name = "test_tune2fs_l_0", .test_fn = test_tune2fs_l_0 },
  { .name = "test_statvfs_0", .test_fn = test_statvfs_0 },
  { .name = "test_lstat_0", .test_fn = test_lstat_0 },
  { .name = "test_stat_0", .test_fn = test_stat_0 },
  { .name = "test_command_lines_0", .test_fn = test_command_lines_0 },
  { .name = "test_command_lines_1", .test_fn = test_command_lines_1 },
  { .name = "test_command_lines_2", .test_fn = test_command_lines_2 },
  { .name = "test_command_lines_3", .test_fn = test_command_lines_3 },
  { .name = "test_command_lines_4", .test_fn = test_command_lines_4 },
  { .name = "test_command_lines_5", .test_fn = test_command_lines_5 },
  { .name = "test_command_lines_6", .test_fn = test_command_lines_6 },
  { .name = "test_command_lines_7", .test_fn = test_command_lines_7 },
  { .name = "test_command_lines_8", .test_fn = test_command_lines_8 },
  { .name = "test_command_lines_9", .test_fn = test_command_lines_9 },
  { .name = "test_command_lines_10", .test_fn = test_command_lines_10 },
  { .name = "test_command_0", .test_fn = test_command_0 },
  { .name = "test_command_1", .test_fn = test_command_1 },
  { .name = "test_command_2", .test_fn = test_command_2 },
  { .name = "test_command_3", .test_fn = test_command_3 },
  { .name = "test_command_4", .test_fn = test_command_4 },
  { .name = "test_command_5", .test_fn = test_command_5 },
  { .name = "test_command_6", .test_fn = test_command_6 },
  { .name = "test_command_7", .test_fn = test_command_7 },
  { .name = "test_command_8", .test_fn = test_command_8 },
  { .name = "test_command_9", .test_fn = test_command_9 },
  { .name = "test_command_10", .test_fn = test_command_10 },
  { .name = "test_command_11", .test_fn = test_command_11 },
  { .name = "test_command_12", .test_fn = test_command_12 },
  { .name = "test_file_0", .test_fn = test_file_0 },
  { .name = "test_file_1", .test_fn = test_file_1 },
  { .name = "test_file_2", .test_fn = test_file_2 },
  { .name = "test_file_3", .test_fn = test_file_3 },
  { .name = "test_file_4", .test_fn = test_file_4 },
  { .name = "test_umount_all_0", .test_fn = test_umount_all_0 },
  { .name = "test_umount_all_1", .test_fn = test_umount_all_1 },
  { .name = "test_mounts_0", .test_fn = test_mounts_0 },
  { .name = "test_umount_0", .test_fn = test_umount_0 },
  { .name = "test_umount_1", .test_fn = test_umount_1 },
  { .name = "test_write_file_0", .test_fn = test_write_file_0 },
  { .name = "test_lvcreate_0", .test_fn = test_lvcreate_0 },
  { .name = "test_vgcreate_0", .test_fn = test_vgcreate_0 },
  { .name = "test_pvcreate_0", .test_fn = test_pvcreate_0 },
  { .name = "test_is_dir_0", .test_fn = test_is_dir_0 },
  { .name = "test_is_dir_1", .test_fn = test_is_dir_1 },
  { .name = "test_is_file_0", .test_fn = test_is_file_0 },
  { .name = "test_is_file_1", .test_fn = test_is_file_1 },
  { .name = "test_exists_0", .test_fn = test_exists_0 },
  { .name = "test_exists_1", .test_fn = test_exists_1 },
  { .name = "test_mkdir_p_0", .test_fn = test_mkdir_p_0 },
  { .name = "test_mkdir_p_1", .test_fn = test_mkdir_p_1 },
  { .name = "test_mkdir_p_2", .test_fn = test_mkdir_p_2 },
  { .name = "test_mkdir_p_3", .test_fn = test_mkdir_p_3 },
  { .name = "test_mkdir_p_4", .test_fn = test_mkdir_p_4 },
  { .name = "test_mkdir_0", .test_fn = test_mkdir_0 },
  { .name = "test_mkdir_1", .test_fn = test_mkdir_1 },
  { .name = "test_rm_rf_0", .test_fn = test_rm_rf_0 },
  { .name = "test_rmdir_0", .test_fn = test_rmdir_0 },
  { .name = "test_rmdir_1", .test_fn = test_rmdir_1 },
  { .name = "test_rmdir_2", .test_fn = test_rmdir_2 },
  { .name = "test_rm_0", .test_fn = test_rm_0 },
  { .name = "test_rm_1", .test_fn = test_rm_1 },
  { .name = "test_rm_2", .test_fn = test_rm_2 },
  { .name = "test_lvs_0", .test_fn = test_lvs_0 },
  { .name = "test_lvs_1", .test_fn = test_lvs_1 },
  { .name = "test_vgs_0", .test_fn = test_vgs_0 },
  { .name = "test_vgs_1", .test_fn = test_vgs_1 },
  { .name = "test_pvs_0", .test_fn = test_pvs_0 },
  { .name = "test_pvs_1", .test_fn = test_pvs_1 },
  { .name = "test_list_partitions_0", .test_fn = test_list_partitions_0 },
  { .name = "test_list_partitions_1", .test_fn = test_list_partitions_1 },
  { .name = "test_list_devices_0", .test_fn = test_list_devices_0 },
  { .name = "test_touch_0", .test_fn = test_touch_0 },
  { .name = "test_sync_0", .test_fn = test_sync_0 },
  { .name = "test_mount_0", .test_fn = test_mount_0 },
  { .name = "test_get_program_0", .test_fn = test_get_program_0 },
  { .name = "test_disk_has_backing_file_0", .test_fn = test_disk_has_backing_file_0 },
  { .name = "test_disk_has_backing_file_1", .test_fn = test_disk_has_backing_file_1 },
  { .name = "test_disk_has_backing_file_2", .test_fn = test_disk_has_backing_file_2 },
  { .name = "test_disk_virtual_size_0", .test_fn = test_disk_virtual_size_0 },
  { .name = "test_disk_virtual_size_1", .test_fn = test_disk_virtual_size_1 },
  { .name = "test_disk_virtual_size_2", .test_fn = test_disk_virtual_size_2 },
  { .name = "test_disk_format_0", .test_fn = test_disk_format_0 },
  { .name = "test_disk_format_1", .test_fn = test_disk_format_1 },
  { .name = "test_disk_format_2", .test_fn = test_disk_format_2 },
  { .name = "test_ls_0", .test_fn = test_ls_0 },
  { .name = "test_write_append_0", .test_fn = test_write_append_0 },
  { .name = "test_write_0", .test_fn = test_write_0 },
  { .name = "test_write_1", .test_fn = test_write_1 },
  { .name = "test_write_2", .test_fn = test_write_2 },
  { .name = "test_write_3", .test_fn = test_write_3 },
  { .name = "test_write_4", .test_fn = test_write_4 },
  { .name = "test_write_5", .test_fn = test_write_5 },
  { .name = "test_read_lines_0", .test_fn = test_read_lines_0 },
  { .name = "test_read_lines_1", .test_fn = test_read_lines_1 },
  { .name = "test_read_lines_2", .test_fn = test_read_lines_2 },
  { .name = "test_read_lines_3", .test_fn = test_read_lines_3 },
  { .name = "test_read_lines_4", .test_fn = test_read_lines_4 },
  { .name = "test_read_lines_5", .test_fn = test_read_lines_5 },
  { .name = "test_read_lines_6", .test_fn = test_read_lines_6 },
  { .name = "test_read_lines_7", .test_fn = test_read_lines_7 },
  { .name = "test_read_lines_8", .test_fn = test_read_lines_8 },
  { .name = "test_read_lines_9", .test_fn = test_read_lines_9 },
  { .name = "test_read_file_0", .test_fn = test_read_file_0 },
  { .name = "test_find_0", .test_fn = test_find_0 },
  { .name = "test_find_1", .test_fn = test_find_1 },
  { .name = "test_find_2", .test_fn = test_find_2 },
  { .name = "test_cat_0", .test_fn = test_cat_0 },
  { .name = "test_get_backend_0", .test_fn = test_get_backend_0 },
  { .name = "test_get_attach_method_0", .test_fn = test_get_attach_method_0 },
  { .name = "test_file_architecture_0", .test_fn = test_file_architecture_0 },
  { .name = "test_file_architecture_1", .test_fn = test_file_architecture_1 },
  { .name = "test_file_architecture_2", .test_fn = test_file_architecture_2 },
  { .name = "test_file_architecture_3", .test_fn = test_file_architecture_3 },
  { .name = "test_file_architecture_4", .test_fn = test_file_architecture_4 },
  { .name = "test_file_architecture_5", .test_fn = test_file_architecture_5 },
  { .name = "test_file_architecture_6", .test_fn = test_file_architecture_6 },
  { .name = "test_file_architecture_7", .test_fn = test_file_architecture_7 },
  { .name = "test_file_architecture_8", .test_fn = test_file_architecture_8 },
  { .name = "test_file_architecture_9", .test_fn = test_file_architecture_9 },
  { .name = "test_file_architecture_10", .test_fn = test_file_architecture_10 },
  { .name = "test_file_architecture_11", .test_fn = test_file_architecture_11 },
  { .name = "test_set_trace_0", .test_fn = test_set_trace_0 },
  { .name = "test_version_0", .test_fn = test_version_0 },
  { .name = "test_get_memsize_0", .test_fn = test_get_memsize_0 },
  { .name = "test_is_busy_0", .test_fn = test_is_busy_0 },
  { .name = "test_is_launching_0", .test_fn = test_is_launching_0 },
  { .name = "test_is_config_0", .test_fn = test_is_config_0 },
  { .name = "test_is_ready_0", .test_fn = test_is_ready_0 },
  { .name = "test_get_autosync_0", .test_fn = test_get_autosync_0 },
  { .name = "test_get_path_0", .test_fn = test_get_path_0 },
  { .name = "test_get_qemu_0", .test_fn = test_get_qemu_0 },
};
