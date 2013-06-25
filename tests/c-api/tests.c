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
test_cp_r_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "cp_r") == NULL;
  str = getenv ("SKIP_TEST_CP_R_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_CP_R");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_cp_r_0 (guestfs_h *g)
{
  if (test_cp_r_0_skip ()) {
    skipped ("test_cp_r_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for cp_r (0) */
  const char *_arg2 = "/cp_r1";
  int _ret1;
  _ret1 = guestfs_mkdir (g, _arg2);
  if (_ret1 == -1)
    return -1;
  const char *_arg5 = "/cp_r2";
  int _ret4;
  _ret4 = guestfs_mkdir (g, _arg5);
  if (_ret4 == -1)
    return -1;
  const char *_arg8 = "/cp_r1/file";
  const char *_arg9 = "file content";
  size_t _arg9_size = 12;
  int _ret7;
  _ret7 = guestfs_write (g, _arg8, _arg9, _arg9_size);
  if (_ret7 == -1)
    return -1;
  const char *_arg12 = "/cp_r1";
  const char *_arg13 = "/cp_r2";
  int _ret11;
  _ret11 = guestfs_cp_r (g, _arg12, _arg13);
  if (_ret11 == -1)
    return -1;
  const char *_arg15 = "/cp_r2/cp_r1/file";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg15);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "file content")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_cp_r_0", "cat", ret, "file content");
    return -1;
  }
  return 0;
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
  const char *const _arg17[1] = { NULL };
  int ret;
  ret = guestfs_feature_available (g, (char **) _arg17);
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
  const char *_arg19 = "/dev/sda";
  int ret;
  ret = guestfs_is_whole_device (g, _arg19);
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
  const char *_arg21 = "/dev/sda1";
  int ret;
  ret = guestfs_is_whole_device (g, _arg21);
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
  const char *_arg23 = "/dev/VG/LV";
  int ret;
  ret = guestfs_is_whole_device (g, _arg23);
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
  const char *_arg26 = "/rename";
  int _ret25;
  _ret25 = guestfs_mkdir (g, _arg26);
  if (_ret25 == -1)
    return -1;
  const char *_arg29 = "/rename/old";
  const char *_arg30 = "file content";
  size_t _arg30_size = 12;
  int _ret28;
  _ret28 = guestfs_write (g, _arg29, _arg30, _arg30_size);
  if (_ret28 == -1)
    return -1;
  const char *_arg33 = "/rename/old";
  const char *_arg34 = "/rename/new";
  int _ret32;
  _ret32 = guestfs_rename (g, _arg33, _arg34);
  if (_ret32 == -1)
    return -1;
  const char *_arg36 = "/rename/old";
  struct guestfs_is_file_opts_argv _optargs37;
  _optargs37.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, _arg36, &_optargs37);
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

  const char *_features38[] = { "gdisk", NULL };
  if (!guestfs_feature_available (g, (char **) _features38)) {
    skipped ("test_part_get_gpt_type_0", "group %s not available in daemon",
             _features38[0]);
    return 0;
  }

  if (init_gpt (g) == -1)
    return -1;

  /* TestResultString for part_get_gpt_type (0) */
  const char *_arg40 = "/dev/sda";
  const char *_arg42 = "01234567-89AB-CDEF-0123-456789ABCDEF";
  int _ret39;
  _ret39 = guestfs_part_set_gpt_type (g, _arg40, 1, _arg42);
  if (_ret39 == -1)
    return -1;
  const char *_arg44 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_gpt_type (g, _arg44, 1);
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

  const char *_features47[] = { "linuxcaps", NULL };
  if (!guestfs_feature_available (g, (char **) _features47)) {
    skipped ("test_cap_set_file_0", "group %s not available in daemon",
             _features47[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for cap_set_file (0) */
  const char *_arg49 = "/cap_set_file_0";
  int _ret48;
  _ret48 = guestfs_touch (g, _arg49);
  if (_ret48 == -1)
    return -1;
  const char *_arg52 = "/cap_set_file_0";
  const char *_arg53 = "cap_chown=p cap_chown+e";
  int _ret51;
  _ret51 = guestfs_cap_set_file (g, _arg52, _arg53);
  if (_ret51 == -1)
    return -1;
  const char *_arg55 = "/cap_set_file_0";
  CLEANUP_FREE char *ret;
  ret = guestfs_cap_get_file (g, _arg55);
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

  const char *_features57[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) _features57)) {
    skipped ("test_acl_delete_def_file_0", "group %s not available in daemon",
             _features57[0]);
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

  const char *_features58[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) _features58)) {
    skipped ("test_acl_delete_def_file_1", "group %s not available in daemon",
             _features58[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for acl_delete_def_file (1) */
  const char *_arg60 = "/acl_delete_def_file_1";
  int _ret59;
  _ret59 = guestfs_mkdir (g, _arg60);
  if (_ret59 == -1)
    return -1;
  const char *_arg63 = "/acl_delete_def_file_1";
  const char *_arg64 = "default";
  const char *_arg65 = "user::r-x,group::r-x,other::r-x";
  int _ret62;
  _ret62 = guestfs_acl_set_file (g, _arg63, _arg64, _arg65);
  if (_ret62 == -1)
    return -1;
  const char *_arg68 = "/acl_delete_def_file_1";
  int _ret67;
  _ret67 = guestfs_acl_delete_def_file (g, _arg68);
  if (_ret67 == -1)
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

  const char *_features70[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) _features70)) {
    skipped ("test_acl_set_file_0", "group %s not available in daemon",
             _features70[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for acl_set_file (0) */
  const char *_arg72 = "/acl_set_file_0";
  int _ret71;
  _ret71 = guestfs_touch (g, _arg72);
  if (_ret71 == -1)
    return -1;
  const char *_arg75 = "/acl_set_file_0";
  const char *_arg76 = "access";
  const char *_arg77 = "user::r-x,group::r-x,other::r-x";
  int _ret74;
  _ret74 = guestfs_acl_set_file (g, _arg75, _arg76, _arg77);
  if (_ret74 == -1)
    return -1;
  const char *_arg80 = "/acl_set_file_0";
  const char *_arg81 = "access";
  CLEANUP_FREE char *_ret79;
  _ret79 = guestfs_acl_get_file (g, _arg80, _arg81);
  if (_ret79 == NULL)
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
  const char *_arg84 = "/lost+found";
  int _ret83;
  _ret83 = guestfs_rm_rf (g, _arg84);
  if (_ret83 == -1)
    return -1;
  const char *_arg87 = "/";
  int _ret86;
  _ret86 = guestfs_mklost_and_found (g, _arg87);
  if (_ret86 == -1)
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
  const char *_arg90 = "/mktemp";
  int _ret89;
  _ret89 = guestfs_mkdir (g, _arg90);
  if (_ret89 == -1)
    return -1;
  const char *_arg93 = "/mktemp/tmpXXXXXX";
  struct guestfs_mktemp_argv _optargs94;
  _optargs94.bitmask = UINT64_C(0x0);
  CLEANUP_FREE char *_ret92;
  _ret92 = guestfs_mktemp_argv (g, _arg93, &_optargs94);
  if (_ret92 == NULL)
      return -1;
  const char *_arg96 = "/mktemp/tmpXXXXXX";
  struct guestfs_mktemp_argv _optargs97;
  _optargs97.suffix = "suff";
  _optargs97.bitmask = UINT64_C(0x1);
  CLEANUP_FREE char *_ret95;
  _ret95 = guestfs_mktemp_argv (g, _arg96, &_optargs97);
  if (_ret95 == NULL)
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
  const char *_arg99 = "/dev/sda";
  const char *_arg100 = "mbr";
  int _ret98;
  _ret98 = guestfs_part_init (g, _arg99, _arg100);
  if (_ret98 == -1)
    return -1;
  const char *_arg103 = "/dev/sda";
  const char *_arg104 = "p";
  int _ret102;
  _ret102 = guestfs_part_add (g, _arg103, _arg104, 64, 204799);
  if (_ret102 == -1)
    return -1;
  const char *_arg109 = "/dev/sda";
  const char *_arg110 = "p";
  int _ret108;
  _ret108 = guestfs_part_add (g, _arg109, _arg110, 204800, -64);
  if (_ret108 == -1)
    return -1;
  const char *_arg115 = "/dev/sda1";
  struct guestfs_mke2fs_argv _optargs116;
  _optargs116.blocksize = 4096;
  _optargs116.journaldev = 1;
  _optargs116.bitmask = UINT64_C(0x100000002);
  int _ret114;
  _ret114 = guestfs_mke2fs_argv (g, _arg115, &_optargs116);
  if (_ret114 == -1)
    return -1;
  const char *_arg118 = "/dev/sda2";
  struct guestfs_mke2fs_argv _optargs119;
  _optargs119.blocksize = 4096;
  _optargs119.journaldevice = "/dev/sda1";
  _optargs119.fstype = "ext2";
  _optargs119.bitmask = UINT64_C(0x44002);
  int _ret117;
  _ret117 = guestfs_mke2fs_argv (g, _arg118, &_optargs119);
  if (_ret117 == -1)
    return -1;
  const char *_arg121 = "/dev/sda2";
  const char *_arg122 = "/";
  int _ret120;
  _ret120 = guestfs_mount (g, _arg121, _arg122);
  if (_ret120 == -1)
    return -1;
  const char *_arg125 = "/new";
  const char *_arg126 = "new file contents";
  size_t _arg126_size = 17;
  int _ret124;
  _ret124 = guestfs_write (g, _arg125, _arg126, _arg126_size);
  if (_ret124 == -1)
    return -1;
  const char *_arg128 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg128);
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
  const char *_arg131 = "/dev/sda";
  const char *_arg132 = "mbr";
  int _ret130;
  _ret130 = guestfs_part_init (g, _arg131, _arg132);
  if (_ret130 == -1)
    return -1;
  const char *_arg135 = "/dev/sda";
  const char *_arg136 = "p";
  int _ret134;
  _ret134 = guestfs_part_add (g, _arg135, _arg136, 64, 204799);
  if (_ret134 == -1)
    return -1;
  const char *_arg141 = "/dev/sda";
  const char *_arg142 = "p";
  int _ret140;
  _ret140 = guestfs_part_add (g, _arg141, _arg142, 204800, -64);
  if (_ret140 == -1)
    return -1;
  const char *_arg147 = "/dev/sda1";
  struct guestfs_mke2fs_argv _optargs148;
  _optargs148.blocksize = 4096;
  _optargs148.journaldevice = "/dev/sda1";
  _optargs148.label = "JOURNAL";
  _optargs148.fstype = "ext2";
  _optargs148.journaldev = 1;
  _optargs148.bitmask = UINT64_C(0x10004c002);
  int _ret146;
  _ret146 = guestfs_mke2fs_argv (g, _arg147, &_optargs148);
  if (_ret146 == -1)
    return -1;
  const char *_arg150 = "/dev/sda2";
  struct guestfs_mke2fs_argv _optargs151;
  _optargs151.blocksize = 4096;
  _optargs151.journaldevice = "LABEL=JOURNAL";
  _optargs151.label = "JOURNAL";
  _optargs151.fstype = "ext2";
  _optargs151.bitmask = UINT64_C(0x4c002);
  int _ret149;
  _ret149 = guestfs_mke2fs_argv (g, _arg150, &_optargs151);
  if (_ret149 == -1)
    return -1;
  const char *_arg153 = "/dev/sda2";
  const char *_arg154 = "/";
  int _ret152;
  _ret152 = guestfs_mount (g, _arg153, _arg154);
  if (_ret152 == -1)
    return -1;
  const char *_arg157 = "/new";
  const char *_arg158 = "new file contents";
  size_t _arg158_size = 17;
  int _ret156;
  _ret156 = guestfs_write (g, _arg157, _arg158, _arg158_size);
  if (_ret156 == -1)
    return -1;
  const char *_arg160 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg160);
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
  const char *_arg163 = "/dev/sda";
  const char *_arg164 = "mbr";
  int _ret162;
  _ret162 = guestfs_part_init (g, _arg163, _arg164);
  if (_ret162 == -1)
    return -1;
  const char *_arg167 = "/dev/sda";
  const char *_arg168 = "p";
  int _ret166;
  _ret166 = guestfs_part_add (g, _arg167, _arg168, 64, 204799);
  if (_ret166 == -1)
    return -1;
  const char *_arg173 = "/dev/sda";
  const char *_arg174 = "p";
  int _ret172;
  _ret172 = guestfs_part_add (g, _arg173, _arg174, 204800, -64);
  if (_ret172 == -1)
    return -1;
  const char *_arg179 = "/dev/sda1";
  struct guestfs_mke2fs_argv _optargs180;
  _optargs180.blocksize = 4096;
  _optargs180.uuid = "6ea9252b-0589-a149-2961-67ad38fa3d4c";
  _optargs180.journaldev = 1;
  _optargs180.bitmask = UINT64_C(0x100100002);
  int _ret178;
  _ret178 = guestfs_mke2fs_argv (g, _arg179, &_optargs180);
  if (_ret178 == -1)
    return -1;
  const char *_arg182 = "/dev/sda2";
  struct guestfs_mke2fs_argv _optargs183;
  _optargs183.blocksize = 4096;
  _optargs183.journaldevice = "UUID=6ea9252b-0589-a149-2961-67ad38fa3d4c";
  _optargs183.label = "JOURNAL";
  _optargs183.fstype = "ext2";
  _optargs183.forcecreate = 1;
  _optargs183.bitmask = UINT64_C(0x24c002);
  int _ret181;
  _ret181 = guestfs_mke2fs_argv (g, _arg182, &_optargs183);
  if (_ret181 == -1)
    return -1;
  const char *_arg185 = "/dev/sda2";
  const char *_arg186 = "/";
  int _ret184;
  _ret184 = guestfs_mount (g, _arg185, _arg186);
  if (_ret184 == -1)
    return -1;
  const char *_arg189 = "/new";
  const char *_arg190 = "new file contents";
  size_t _arg190_size = 17;
  int _ret188;
  _ret188 = guestfs_write (g, _arg189, _arg190, _arg190_size);
  if (_ret188 == -1)
    return -1;
  const char *_arg192 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg192);
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
  const char *_arg195 = "/rm_f";
  int _ret194;
  _ret194 = guestfs_mkdir (g, _arg195);
  if (_ret194 == -1)
    return -1;
  const char *_arg198 = "/rm_f/foo";
  int _ret197;
  _ret197 = guestfs_touch (g, _arg198);
  if (_ret197 == -1)
    return -1;
  const char *_arg201 = "/rm_f/foo";
  int _ret200;
  _ret200 = guestfs_rm_f (g, _arg201);
  if (_ret200 == -1)
    return -1;
  const char *_arg204 = "/rm_f/not_exists";
  int _ret203;
  _ret203 = guestfs_rm_f (g, _arg204);
  if (_ret203 == -1)
    return -1;
  const char *_arg206 = "/rm_f/foo";
  int ret;
  ret = guestfs_exists (g, _arg206);
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
  const char *_arg209 = "/rm_f2";
  int _ret208;
  _ret208 = guestfs_mkdir (g, _arg209);
  if (_ret208 == -1)
    return -1;
  const char *_arg212 = "/rm_f2/foo";
  int _ret211;
  _ret211 = guestfs_mkdir (g, _arg212);
  if (_ret211 == -1)
    return -1;
  const char *_arg215 = "/rm_f2/foo";
  int _ret214;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret214 = guestfs_rm_f (g, _arg215);
  guestfs_pop_error_handler (g);
  if (_ret214 != -1)
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

  const char *_features217[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features217)) {
    skipped ("test_xfs_repair_0", "group %s not available in daemon",
             _features217[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for xfs_repair (0) */
  const char *_arg219 = "/dev/sda";
  const char *_arg220 = "mbr";
  int _ret218;
  _ret218 = guestfs_part_disk (g, _arg219, _arg220);
  if (_ret218 == -1)
    return -1;
  const char *_arg223 = "xfs";
  const char *_arg224 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs225;
  _optargs225.bitmask = UINT64_C(0x0);
  int _ret222;
  _ret222 = guestfs_mkfs_opts_argv (g, _arg223, _arg224, &_optargs225);
  if (_ret222 == -1)
    return -1;
  const char *_arg227 = "/dev/sda1";
  struct guestfs_xfs_repair_argv _optargs228;
  _optargs228.nomodify = 1;
  _optargs228.bitmask = UINT64_C(0x2);
  int _ret226;
  _ret226 = guestfs_xfs_repair_argv (g, _arg227, &_optargs228);
  if (_ret226 == -1)
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

  const char *_features229[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features229)) {
    skipped ("test_xfs_admin_0", "group %s not available in daemon",
             _features229[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for xfs_admin (0) */
  const char *_arg230 = "/dev/sda";
  const char *_arg231 = "mbr";
  int ret4;
  ret4 = guestfs_part_disk (g, _arg230, _arg231);
  if (ret4 == -1)
    return -1;
  const char *_arg233 = "xfs";
  const char *_arg234 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs235;
  _optargs235.bitmask = UINT64_C(0x0);
  int ret3;
  ret3 = guestfs_mkfs_opts_argv (g, _arg233, _arg234, &_optargs235);
  if (ret3 == -1)
    return -1;
  const char *_arg236 = "/dev/sda1";
  struct guestfs_xfs_admin_argv _optargs237;
  _optargs237.lazycounter = 0;
  _optargs237.bitmask = UINT64_C(0x10);
  int ret2;
  ret2 = guestfs_xfs_admin_argv (g, _arg236, &_optargs237);
  if (ret2 == -1)
    return -1;
  const char *_arg238 = "/dev/sda1";
  const char *_arg239 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg238, _arg239);
  if (ret1 == -1)
    return -1;
  const char *_arg241 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, _arg241);
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

  const char *_features243[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features243)) {
    skipped ("test_xfs_growfs_0", "group %s not available in daemon",
             _features243[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for xfs_growfs (0) */
  const char *_arg244 = "/dev/sda";
  const char *_arg245 = "mbr";
  int ret8;
  ret8 = guestfs_part_disk (g, _arg244, _arg245);
  if (ret8 == -1)
    return -1;
  const char *_arg247 = "/dev/sda1";
  int ret7;
  ret7 = guestfs_pvcreate (g, _arg247);
  if (ret7 == -1)
    return -1;
  const char *_arg249 = "VG";
  const char *_arg250_0 = "/dev/sda1";
  const char *const _arg250[] = {
    _arg250_0,
    NULL
  };
  int ret6;
  ret6 = guestfs_vgcreate (g, _arg249, (char **) _arg250);
  if (ret6 == -1)
    return -1;
  const char *_arg252 = "LV";
  const char *_arg253 = "VG";
  int ret5;
  ret5 = guestfs_lvcreate (g, _arg252, _arg253, 40);
  if (ret5 == -1)
    return -1;
  const char *_arg256 = "xfs";
  const char *_arg257 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs258;
  _optargs258.bitmask = UINT64_C(0x0);
  int ret4;
  ret4 = guestfs_mkfs_opts_argv (g, _arg256, _arg257, &_optargs258);
  if (ret4 == -1)
    return -1;
  const char *_arg259 = "/dev/VG/LV";
  int ret3;
  ret3 = guestfs_lvresize (g, _arg259, 80);
  if (ret3 == -1)
    return -1;
  const char *_arg262 = "/dev/VG/LV";
  const char *_arg263 = "/";
  int ret2;
  ret2 = guestfs_mount (g, _arg262, _arg263);
  if (ret2 == -1)
    return -1;
  const char *_arg265 = "/";
  struct guestfs_xfs_growfs_argv _optargs266;
  _optargs266.datasec = 1;
  _optargs266.logsec = 0;
  _optargs266.rtsec = 0;
  _optargs266.bitmask = UINT64_C(0x7);
  int ret1;
  ret1 = guestfs_xfs_growfs_argv (g, _arg265, &_optargs266);
  if (ret1 == -1)
    return -1;
  const char *_arg267 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, _arg267);
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
  CLEANUP_FREE_UTSNAME struct guestfs_utsname *_ret269;
  _ret269 = guestfs_utsname (g);
  if (_ret269 == NULL)
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

  const char *_features271[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features271)) {
    skipped ("test_vgchange_uuid_all_0", "group %s not available in daemon",
             _features271[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for vgchange_uuid_all (0) */
  const char *_arg273 = "/dev/sda";
  const char *_arg274 = "mbr";
  int _ret272;
  _ret272 = guestfs_part_disk (g, _arg273, _arg274);
  if (_ret272 == -1)
    return -1;
  const char *_arg277 = "/dev/sda1";
  int _ret276;
  _ret276 = guestfs_pvcreate (g, _arg277);
  if (_ret276 == -1)
    return -1;
  const char *_arg280 = "VG";
  const char *_arg281_0 = "/dev/sda1";
  const char *const _arg281[] = {
    _arg281_0,
    NULL
  };
  int _ret279;
  _ret279 = guestfs_vgcreate (g, _arg280, (char **) _arg281);
  if (_ret279 == -1)
    return -1;
  int _ret283;
  _ret283 = guestfs_vgchange_uuid_all (g);
  if (_ret283 == -1)
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

  const char *_features285[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features285)) {
    skipped ("test_vgchange_uuid_0", "group %s not available in daemon",
             _features285[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for vgchange_uuid (0) */
  const char *_arg287 = "/dev/sda";
  const char *_arg288 = "mbr";
  int _ret286;
  _ret286 = guestfs_part_disk (g, _arg287, _arg288);
  if (_ret286 == -1)
    return -1;
  const char *_arg291 = "/dev/sda1";
  int _ret290;
  _ret290 = guestfs_pvcreate (g, _arg291);
  if (_ret290 == -1)
    return -1;
  const char *_arg294 = "VG";
  const char *_arg295_0 = "/dev/sda1";
  const char *const _arg295[] = {
    _arg295_0,
    NULL
  };
  int _ret293;
  _ret293 = guestfs_vgcreate (g, _arg294, (char **) _arg295);
  if (_ret293 == -1)
    return -1;
  const char *_arg298 = "/dev/VG";
  int _ret297;
  _ret297 = guestfs_vgchange_uuid (g, _arg298);
  if (_ret297 == -1)
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

  const char *_features300[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features300)) {
    skipped ("test_pvchange_uuid_all_0", "group %s not available in daemon",
             _features300[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for pvchange_uuid_all (0) */
  const char *_arg302 = "/dev/sda";
  const char *_arg303 = "mbr";
  int _ret301;
  _ret301 = guestfs_part_disk (g, _arg302, _arg303);
  if (_ret301 == -1)
    return -1;
  const char *_arg306 = "/dev/sda1";
  int _ret305;
  _ret305 = guestfs_pvcreate (g, _arg306);
  if (_ret305 == -1)
    return -1;
  int _ret308;
  _ret308 = guestfs_pvchange_uuid_all (g);
  if (_ret308 == -1)
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

  const char *_features310[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features310)) {
    skipped ("test_pvchange_uuid_0", "group %s not available in daemon",
             _features310[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for pvchange_uuid (0) */
  const char *_arg312 = "/dev/sda";
  const char *_arg313 = "mbr";
  int _ret311;
  _ret311 = guestfs_part_disk (g, _arg312, _arg313);
  if (_ret311 == -1)
    return -1;
  const char *_arg316 = "/dev/sda1";
  int _ret315;
  _ret315 = guestfs_pvcreate (g, _arg316);
  if (_ret315 == -1)
    return -1;
  const char *_arg319 = "/dev/sda1";
  int _ret318;
  _ret318 = guestfs_pvchange_uuid (g, _arg319);
  if (_ret318 == -1)
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

  const char *_features321[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features321)) {
    skipped ("test_xfs_info_0", "group %s not available in daemon",
             _features321[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for xfs_info (0) */
  const char *_arg322 = "/dev/sda";
  const char *_arg323 = "mbr";
  int ret3;
  ret3 = guestfs_part_disk (g, _arg322, _arg323);
  if (ret3 == -1)
    return -1;
  const char *_arg325 = "xfs";
  const char *_arg326 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs327;
  _optargs327.bitmask = UINT64_C(0x0);
  int ret2;
  ret2 = guestfs_mkfs_opts_argv (g, _arg325, _arg326, &_optargs327);
  if (ret2 == -1)
    return -1;
  const char *_arg328 = "/dev/sda1";
  const char *_arg329 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg328, _arg329);
  if (ret1 == -1)
    return -1;
  const char *_arg331 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, _arg331);
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
  const char *_arg334 = "/dev/sda";
  int ret;
  ret = guestfs_device_index (g, _arg334);
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

  const char *_features336[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features336)) {
    skipped ("test_btrfs_fsck_0", "group %s not available in daemon",
             _features336[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_fsck (0) */
  const char *_arg338_0 = "/dev/sda1";
  const char *const _arg338[] = {
    _arg338_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs339;
  _optargs339.bitmask = UINT64_C(0x0);
  int _ret337;
  _ret337 = guestfs_mkfs_btrfs_argv (g, (char **) _arg338, &_optargs339);
  if (_ret337 == -1)
    return -1;
  const char *_arg341 = "/dev/sda1";
  struct guestfs_btrfs_fsck_argv _optargs342;
  _optargs342.bitmask = UINT64_C(0x0);
  int _ret340;
  _ret340 = guestfs_btrfs_fsck_argv (g, _arg341, &_optargs342);
  if (_ret340 == -1)
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

  const char *_features343[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features343)) {
    skipped ("test_btrfs_set_seeding_0", "group %s not available in daemon",
             _features343[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_set_seeding (0) */
  const char *_arg345_0 = "/dev/sda1";
  const char *const _arg345[] = {
    _arg345_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs346;
  _optargs346.bitmask = UINT64_C(0x0);
  int _ret344;
  _ret344 = guestfs_mkfs_btrfs_argv (g, (char **) _arg345, &_optargs346);
  if (_ret344 == -1)
    return -1;
  const char *_arg348 = "/dev/sda1";
  int _ret347;
  _ret347 = guestfs_btrfs_set_seeding (g, _arg348, 1);
  if (_ret347 == -1)
    return -1;
  const char *_arg352 = "/dev/sda1";
  int _ret351;
  _ret351 = guestfs_btrfs_set_seeding (g, _arg352, 0);
  if (_ret351 == -1)
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

  const char *_features355[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features355)) {
    skipped ("test_btrfs_filesystem_sync_0", "group %s not available in daemon",
             _features355[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_filesystem_sync (0) */
  const char *_arg357_0 = "/dev/sda1";
  const char *const _arg357[] = {
    _arg357_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs358;
  _optargs358.bitmask = UINT64_C(0x0);
  int _ret356;
  _ret356 = guestfs_mkfs_btrfs_argv (g, (char **) _arg357, &_optargs358);
  if (_ret356 == -1)
    return -1;
  const char *_arg360 = "/dev/sda1";
  const char *_arg361 = "/";
  int _ret359;
  _ret359 = guestfs_mount (g, _arg360, _arg361);
  if (_ret359 == -1)
    return -1;
  const char *_arg364 = "/test1";
  int _ret363;
  _ret363 = guestfs_btrfs_subvolume_create (g, _arg364);
  if (_ret363 == -1)
    return -1;
  const char *_arg367 = "/test1";
  int _ret366;
  _ret366 = guestfs_btrfs_filesystem_sync (g, _arg367);
  if (_ret366 == -1)
    return -1;
  const char *_arg370 = "/test1";
  int _ret369;
  _ret369 = guestfs_btrfs_filesystem_balance (g, _arg370);
  if (_ret369 == -1)
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

  const char *_features372[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features372)) {
    skipped ("test_btrfs_subvolume_delete_0", "group %s not available in daemon",
             _features372[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_subvolume_delete (0) */
  const char *_arg374_0 = "/dev/sda1";
  const char *const _arg374[] = {
    _arg374_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs375;
  _optargs375.bitmask = UINT64_C(0x0);
  int _ret373;
  _ret373 = guestfs_mkfs_btrfs_argv (g, (char **) _arg374, &_optargs375);
  if (_ret373 == -1)
    return -1;
  const char *_arg377 = "/dev/sda1";
  const char *_arg378 = "/";
  int _ret376;
  _ret376 = guestfs_mount (g, _arg377, _arg378);
  if (_ret376 == -1)
    return -1;
  const char *_arg381 = "/test1";
  int _ret380;
  _ret380 = guestfs_btrfs_subvolume_create (g, _arg381);
  if (_ret380 == -1)
    return -1;
  const char *_arg384 = "/test1";
  int _ret383;
  _ret383 = guestfs_btrfs_subvolume_delete (g, _arg384);
  if (_ret383 == -1)
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

  const char *_features386[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features386)) {
    skipped ("test_btrfs_subvolume_snapshot_0", "group %s not available in daemon",
             _features386[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_subvolume_snapshot (0) */
  const char *_arg388_0 = "/dev/sda1";
  const char *const _arg388[] = {
    _arg388_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs389;
  _optargs389.bitmask = UINT64_C(0x0);
  int _ret387;
  _ret387 = guestfs_mkfs_btrfs_argv (g, (char **) _arg388, &_optargs389);
  if (_ret387 == -1)
    return -1;
  const char *_arg391 = "/dev/sda1";
  const char *_arg392 = "/";
  int _ret390;
  _ret390 = guestfs_mount (g, _arg391, _arg392);
  if (_ret390 == -1)
    return -1;
  const char *_arg395 = "/dir";
  int _ret394;
  _ret394 = guestfs_mkdir (g, _arg395);
  if (_ret394 == -1)
    return -1;
  const char *_arg398 = "/test1";
  int _ret397;
  _ret397 = guestfs_btrfs_subvolume_create (g, _arg398);
  if (_ret397 == -1)
    return -1;
  const char *_arg401 = "/test2";
  int _ret400;
  _ret400 = guestfs_btrfs_subvolume_create (g, _arg401);
  if (_ret400 == -1)
    return -1;
  const char *_arg404 = "/dir/test3";
  int _ret403;
  _ret403 = guestfs_btrfs_subvolume_create (g, _arg404);
  if (_ret403 == -1)
    return -1;
  const char *_arg407 = "/dir/test3";
  const char *_arg408 = "/dir/test4";
  int _ret406;
  _ret406 = guestfs_btrfs_subvolume_snapshot (g, _arg407, _arg408);
  if (_ret406 == -1)
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
  const char *_arg410 = "/e2generation";
  int ret2;
  ret2 = guestfs_touch (g, _arg410);
  if (ret2 == -1)
    return -1;
  const char *_arg412 = "/e2generation";
  int ret1;
  ret1 = guestfs_set_e2generation (g, _arg412, 123456);
  if (ret1 == -1)
    return -1;
  const char *_arg415 = "/e2generation";
  int64_t ret;
  ret = guestfs_get_e2generation (g, _arg415);
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
  const char *_arg418 = "/e2attrs1";
  int _ret417;
  _ret417 = guestfs_touch (g, _arg418);
  if (_ret417 == -1)
    return -1;
  const char *_arg420 = "/e2attrs1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg420);
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
  const char *_arg423 = "/e2attrs2";
  int _ret422;
  _ret422 = guestfs_touch (g, _arg423);
  if (_ret422 == -1)
    return -1;
  const char *_arg426 = "/e2attrs2";
  const char *_arg427 = "is";
  struct guestfs_set_e2attrs_argv _optargs428;
  _optargs428.clear = 0;
  _optargs428.bitmask = UINT64_C(0x1);
  int _ret425;
  _ret425 = guestfs_set_e2attrs_argv (g, _arg426, _arg427, &_optargs428);
  if (_ret425 == -1)
    return -1;
  const char *_arg429 = "/e2attrs2";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg429);
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
  const char *_arg432 = "/e2attrs3";
  int _ret431;
  _ret431 = guestfs_touch (g, _arg432);
  if (_ret431 == -1)
    return -1;
  const char *_arg435 = "/e2attrs3";
  const char *_arg436 = "is";
  struct guestfs_set_e2attrs_argv _optargs437;
  _optargs437.clear = 0;
  _optargs437.bitmask = UINT64_C(0x1);
  int _ret434;
  _ret434 = guestfs_set_e2attrs_argv (g, _arg435, _arg436, &_optargs437);
  if (_ret434 == -1)
    return -1;
  const char *_arg439 = "/e2attrs3";
  const char *_arg440 = "i";
  struct guestfs_set_e2attrs_argv _optargs441;
  _optargs441.clear = 1;
  _optargs441.bitmask = UINT64_C(0x1);
  int _ret438;
  _ret438 = guestfs_set_e2attrs_argv (g, _arg439, _arg440, &_optargs441);
  if (_ret438 == -1)
    return -1;
  const char *_arg442 = "/e2attrs3";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg442);
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
  const char *_arg445 = "/e2attrs4";
  int _ret444;
  _ret444 = guestfs_touch (g, _arg445);
  if (_ret444 == -1)
    return -1;
  const char *_arg448 = "/e2attrs4";
  const char *_arg449 = "adst";
  struct guestfs_set_e2attrs_argv _optargs450;
  _optargs450.clear = 0;
  _optargs450.bitmask = UINT64_C(0x1);
  int _ret447;
  _ret447 = guestfs_set_e2attrs_argv (g, _arg448, _arg449, &_optargs450);
  if (_ret447 == -1)
    return -1;
  const char *_arg452 = "/e2attrs4";
  const char *_arg453 = "iS";
  struct guestfs_set_e2attrs_argv _optargs454;
  _optargs454.clear = 0;
  _optargs454.bitmask = UINT64_C(0x1);
  int _ret451;
  _ret451 = guestfs_set_e2attrs_argv (g, _arg452, _arg453, &_optargs454);
  if (_ret451 == -1)
    return -1;
  const char *_arg456 = "/e2attrs4";
  const char *_arg457 = "i";
  struct guestfs_set_e2attrs_argv _optargs458;
  _optargs458.clear = 1;
  _optargs458.bitmask = UINT64_C(0x1);
  int _ret455;
  _ret455 = guestfs_set_e2attrs_argv (g, _arg456, _arg457, &_optargs458);
  if (_ret455 == -1)
    return -1;
  const char *_arg460 = "/e2attrs4";
  const char *_arg461 = "ad";
  struct guestfs_set_e2attrs_argv _optargs462;
  _optargs462.clear = 1;
  _optargs462.bitmask = UINT64_C(0x1);
  int _ret459;
  _ret459 = guestfs_set_e2attrs_argv (g, _arg460, _arg461, &_optargs462);
  if (_ret459 == -1)
    return -1;
  const char *_arg464 = "/e2attrs4";
  const char *_arg465 = "";
  struct guestfs_set_e2attrs_argv _optargs466;
  _optargs466.clear = 0;
  _optargs466.bitmask = UINT64_C(0x1);
  int _ret463;
  _ret463 = guestfs_set_e2attrs_argv (g, _arg464, _arg465, &_optargs466);
  if (_ret463 == -1)
    return -1;
  const char *_arg468 = "/e2attrs4";
  const char *_arg469 = "";
  struct guestfs_set_e2attrs_argv _optargs470;
  _optargs470.clear = 1;
  _optargs470.bitmask = UINT64_C(0x1);
  int _ret467;
  _ret467 = guestfs_set_e2attrs_argv (g, _arg468, _arg469, &_optargs470);
  if (_ret467 == -1)
    return -1;
  const char *_arg471 = "/e2attrs4";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg471);
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
  const char *_arg474 = "/e2attrs5";
  int _ret473;
  _ret473 = guestfs_touch (g, _arg474);
  if (_ret473 == -1)
    return -1;
  const char *_arg477 = "/e2attrs5";
  const char *_arg478 = "R";
  struct guestfs_set_e2attrs_argv _optargs479;
  _optargs479.clear = 0;
  _optargs479.bitmask = UINT64_C(0x1);
  int _ret476;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret476 = guestfs_set_e2attrs_argv (g, _arg477, _arg478, &_optargs479);
  guestfs_pop_error_handler (g);
  if (_ret476 != -1)
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
  const char *_arg481 = "/e2attrs6";
  int _ret480;
  _ret480 = guestfs_touch (g, _arg481);
  if (_ret480 == -1)
    return -1;
  const char *_arg484 = "/e2attrs6";
  const char *_arg485 = "v";
  struct guestfs_set_e2attrs_argv _optargs486;
  _optargs486.clear = 0;
  _optargs486.bitmask = UINT64_C(0x1);
  int _ret483;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret483 = guestfs_set_e2attrs_argv (g, _arg484, _arg485, &_optargs486);
  guestfs_pop_error_handler (g);
  if (_ret483 != -1)
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
  const char *_arg488 = "/e2attrs7";
  int _ret487;
  _ret487 = guestfs_touch (g, _arg488);
  if (_ret487 == -1)
    return -1;
  const char *_arg491 = "/e2attrs7";
  const char *_arg492 = "aa";
  struct guestfs_set_e2attrs_argv _optargs493;
  _optargs493.clear = 0;
  _optargs493.bitmask = UINT64_C(0x1);
  int _ret490;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret490 = guestfs_set_e2attrs_argv (g, _arg491, _arg492, &_optargs493);
  guestfs_pop_error_handler (g);
  if (_ret490 != -1)
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
  const char *_arg495 = "/e2attrs8";
  int _ret494;
  _ret494 = guestfs_touch (g, _arg495);
  if (_ret494 == -1)
    return -1;
  const char *_arg498 = "/e2attrs8";
  const char *_arg499 = "BabcdB";
  struct guestfs_set_e2attrs_argv _optargs500;
  _optargs500.clear = 0;
  _optargs500.bitmask = UINT64_C(0x1);
  int _ret497;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret497 = guestfs_set_e2attrs_argv (g, _arg498, _arg499, &_optargs500);
  guestfs_pop_error_handler (g);
  if (_ret497 != -1)
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

  const char *_features501[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features501)) {
    skipped ("test_mkfs_btrfs_0", "group %s not available in daemon",
             _features501[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkfs_btrfs (0) */
  const char *_arg503 = "/dev/sda";
  const char *_arg504 = "mbr";
  int _ret502;
  _ret502 = guestfs_part_disk (g, _arg503, _arg504);
  if (_ret502 == -1)
    return -1;
  const char *_arg507_0 = "/dev/sda1";
  const char *const _arg507[] = {
    _arg507_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs508;
  _optargs508.allocstart = 0;
  _optargs508.bytecount = 268435456;
  _optargs508.datatype = "single";
  _optargs508.leafsize = 4096;
  _optargs508.label = "test";
  _optargs508.metadata = "single";
  _optargs508.nodesize = 4096;
  _optargs508.sectorsize = 512;
  _optargs508.bitmask = UINT64_C(0xff);
  int _ret506;
  _ret506 = guestfs_mkfs_btrfs_argv (g, (char **) _arg507, &_optargs508);
  if (_ret506 == -1)
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
  const char *_arg509 = "/dev/sdd";
  CLEANUP_FREE_ISOINFO struct guestfs_isoinfo *ret;
  ret = guestfs_isoinfo_device (g, _arg509);
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

  const char *_features511[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features511)) {
    skipped ("test_lvcreate_free_0", "group %s not available in daemon",
             _features511[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvcreate_free (0) */
  const char *_arg512 = "/dev/sda";
  const char *_arg513 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg512, _arg513);
  if (ret7 == -1)
    return -1;
  const char *_arg515 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg515);
  if (ret6 == -1)
    return -1;
  const char *_arg517 = "VG";
  const char *_arg518_0 = "/dev/sda1";
  const char *const _arg518[] = {
    _arg518_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg517, (char **) _arg518);
  if (ret5 == -1)
    return -1;
  const char *_arg520 = "LV1";
  const char *_arg521 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate_free (g, _arg520, _arg521, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg524 = "LV2";
  const char *_arg525 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate_free (g, _arg524, _arg525, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg528 = "LV3";
  const char *_arg529 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate_free (g, _arg528, _arg529, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg532 = "LV4";
  const char *_arg533 = "VG";
  int ret1;
  ret1 = guestfs_lvcreate_free (g, _arg532, _arg533, 100);
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
  const char *_arg538 = "/";
  int _ret537;
  _ret537 = guestfs_zero_free_space (g, _arg538);
  if (_ret537 == -1)
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
  const char *_arg541 = "/dev/sda1";
  const char *_arg542 = "testlabel";
  int _ret540;
  _ret540 = guestfs_set_label (g, _arg541, _arg542);
  if (_ret540 == -1)
    return -1;
  const char *_arg544 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, _arg544);
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

  const char *_features546[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features546)) {
    skipped ("test_set_label_1", "group %s not available in daemon",
             _features546[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestResultString for set_label (1) */
  const char *_arg548 = "ntfs";
  const char *_arg549 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs550;
  _optargs550.bitmask = UINT64_C(0x0);
  int _ret547;
  _ret547 = guestfs_mkfs_opts_argv (g, _arg548, _arg549, &_optargs550);
  if (_ret547 == -1)
    return -1;
  const char *_arg552 = "/dev/sda1";
  const char *_arg553 = "testlabel2";
  int _ret551;
  _ret551 = guestfs_set_label (g, _arg552, _arg553);
  if (_ret551 == -1)
    return -1;
  const char *_arg555 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, _arg555);
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
  const char *_arg558 = "/dev/sda1";
  int _ret557;
  _ret557 = guestfs_zero (g, _arg558);
  if (_ret557 == -1)
    return -1;
  const char *_arg561 = "/dev/sda1";
  const char *_arg562 = "testlabel2";
  int _ret560;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret560 = guestfs_set_label (g, _arg561, _arg562);
  guestfs_pop_error_handler (g);
  if (_ret560 != -1)
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

  const char *_features564[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features564)) {
    skipped ("test_ntfsfix_0", "group %s not available in daemon",
             _features564[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for ntfsfix (0) */
  const char *_arg566 = "ntfs";
  const char *_arg567 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs568;
  _optargs568.bitmask = UINT64_C(0x0);
  int _ret565;
  _ret565 = guestfs_mkfs_opts_argv (g, _arg566, _arg567, &_optargs568);
  if (_ret565 == -1)
    return -1;
  const char *_arg570 = "/dev/sda1";
  struct guestfs_ntfsfix_argv _optargs571;
  _optargs571.clearbadsectors = 0;
  _optargs571.bitmask = UINT64_C(0x1);
  int _ret569;
  _ret569 = guestfs_ntfsfix_argv (g, _arg570, &_optargs571);
  if (_ret569 == -1)
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

  const char *_features572[] = { "wipefs", NULL };
  if (!guestfs_feature_available (g, (char **) _features572)) {
    skipped ("test_wipefs_0", "group %s not available in daemon",
             _features572[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestRun for wipefs (0) */
  const char *_arg574 = "/dev/VG/LV";
  struct guestfs_umount_opts_argv _optargs575;
  _optargs575.bitmask = UINT64_C(0x0);
  int _ret573;
  _ret573 = guestfs_umount_opts_argv (g, _arg574, &_optargs575);
  if (_ret573 == -1)
    return -1;
  const char *_arg577 = "/dev/VG/LV";
  int _ret576;
  _ret576 = guestfs_wipefs (g, _arg577);
  if (_ret576 == -1)
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
  const char *_arg579 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_blkid (g, _arg579);
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
  const char *_arg581 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs582;
  _optargs582.force = 0;
  _optargs582.maxmountcount = 0;
  _optargs582.intervalbetweenchecks = 0;
  _optargs582.bitmask = UINT64_C(0x23);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg581, &_optargs582);
  if (ret1 == -1)
    return -1;
  const char *_arg583 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg583);
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
  const char *_arg585 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs586;
  _optargs586.force = 0;
  _optargs586.maxmountcount = 0;
  _optargs586.intervalbetweenchecks = 86400;
  _optargs586.bitmask = UINT64_C(0x23);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg585, &_optargs586);
  if (ret1 == -1)
    return -1;
  const char *_arg587 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg587);
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
  const char *_arg589 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs590;
  _optargs590.force = 0;
  _optargs590.group = 1;
  _optargs590.user = 1;
  _optargs590.bitmask = UINT64_C(0x211);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg589, &_optargs590);
  if (ret1 == -1)
    return -1;
  const char *_arg591 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg591);
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
  const char *_arg593 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs594;
  _optargs594.force = 0;
  _optargs594.group = 0;
  _optargs594.user = 0;
  _optargs594.bitmask = UINT64_C(0x211);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg593, &_optargs594);
  if (ret1 == -1)
    return -1;
  const char *_arg595 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg595);
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
  const char *_arg597 = "/copyff";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg597);
  if (ret3 == -1)
    return -1;
  const char *_arg599 = "/copyff/src";
  const char *_arg600 = "hello, world";
  size_t _arg600_size = 12;
  int ret2;
  ret2 = guestfs_write (g, _arg599, _arg600, _arg600_size);
  if (ret2 == -1)
    return -1;
  const char *_arg602 = "/copyff/src";
  const char *_arg603 = "/copyff/dest";
  struct guestfs_copy_file_to_file_argv _optargs604;
  _optargs604.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_copy_file_to_file_argv (g, _arg602, _arg603, &_optargs604);
  if (ret1 == -1)
    return -1;
  const char *_arg605 = "/copyff/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg605, &size);
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
  const char *_arg608 = "/copyff2";
  int _ret607;
  _ret607 = guestfs_mkdir (g, _arg608);
  if (_ret607 == -1)
    return -1;
  const char *_arg613 = "/copyff2/src";
  int _ret610;
  _ret610 = guestfs_fill (g, 0, 1048576, _arg613);
  if (_ret610 == -1)
    return -1;
  const char *_arg616 = "/copyff2/dest";
  int _ret615;
  _ret615 = guestfs_touch (g, _arg616);
  if (_ret615 == -1)
    return -1;
  const char *_arg619 = "/copyff2/dest";
  int _ret618;
  _ret618 = guestfs_truncate_size (g, _arg619, 1048576);
  if (_ret618 == -1)
    return -1;
  const char *_arg623 = "/copyff2/src";
  const char *_arg624 = "/copyff2/dest";
  struct guestfs_copy_file_to_file_argv _optargs625;
  _optargs625.sparse = 1;
  _optargs625.bitmask = UINT64_C(0x8);
  int _ret622;
  _ret622 = guestfs_copy_file_to_file_argv (g, _arg623, _arg624, &_optargs625);
  if (_ret622 == -1)
    return -1;
  const char *_arg626 = "/copyff2/dest";
  int ret;
  ret = guestfs_is_zero (g, _arg626);
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
  const char *_arg628 = "/dev/sda1";
  int ret;
  ret = guestfs_part_to_partnum (g, _arg628);
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
  const char *_arg631 = "/dev/sda";
  int _ret630;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret630 = guestfs_part_to_partnum (g, _arg631);
  guestfs_pop_error_handler (g);
  if (_ret630 != -1)
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
  const char *_arg634 = "/internal_write_append";
  const char *_arg635 = "line1\n";
  size_t _arg635_size = 6;
  int _ret633;
  _ret633 = guestfs_write (g, _arg634, _arg635, _arg635_size);
  if (_ret633 == -1)
    return -1;
  const char *_arg638 = "/internal_write_append";
  const char *_arg639 = "line2\n";
  size_t _arg639_size = 6;
  int _ret637;
  _ret637 = guestfs_internal_write_append (g, _arg638, _arg639, _arg639_size);
  if (_ret637 == -1)
    return -1;
  const char *_arg642 = "/internal_write_append";
  const char *_arg643 = "line3a";
  size_t _arg643_size = 6;
  int _ret641;
  _ret641 = guestfs_internal_write_append (g, _arg642, _arg643, _arg643_size);
  if (_ret641 == -1)
    return -1;
  const char *_arg646 = "/internal_write_append";
  const char *_arg647 = "line3b\n";
  size_t _arg647_size = 7;
  int _ret645;
  _ret645 = guestfs_internal_write_append (g, _arg646, _arg647, _arg647_size);
  if (_ret645 == -1)
    return -1;
  const char *_arg649 = "/internal_write_append";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg649);
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
  const char *_arg652 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs653;
  _optargs653.force = 0;
  _optargs653.lazyunmount = 0;
  _optargs653.bitmask = UINT64_C(0x3);
  int _ret651;
  _ret651 = guestfs_umount_opts_argv (g, _arg652, &_optargs653);
  if (_ret651 == -1)
    return -1;
  const char *_arg655 = "/dev/sda1";
  int _ret654;
  _ret654 = guestfs_zero_device (g, _arg655);
  if (_ret654 == -1)
    return -1;
  const char *_arg657 = "/dev/sda1";
  int ret;
  ret = guestfs_is_zero_device (g, _arg657);
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
  const char *_arg659 = "/dev/sda1";
  int ret;
  ret = guestfs_is_zero_device (g, _arg659);
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
  const char *_arg661 = "/100kallzeroes";
  int ret;
  ret = guestfs_is_zero (g, _arg661);
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
  const char *_arg663 = "/100kallspaces";
  int ret;
  ret = guestfs_is_zero (g, _arg663);
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
  const char *_arg666 = "/dev/sda";
  const char *_arg667 = "mbr";
  int _ret665;
  _ret665 = guestfs_part_disk (g, _arg666, _arg667);
  if (_ret665 == -1)
    return -1;
  const char *_arg670 = "ext2";
  const char *_arg671 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs672;
  _optargs672.bitmask = UINT64_C(0x0);
  int _ret669;
  _ret669 = guestfs_mkfs_opts_argv (g, _arg670, _arg671, &_optargs672);
  if (_ret669 == -1)
    return -1;
  const char *_arg674 = "/dev/sda1";
  const char *_arg675 = "/";
  int _ret673;
  _ret673 = guestfs_mount (g, _arg674, _arg675);
  if (_ret673 == -1)
    return -1;
  const char *_arg678 = "/new";
  const char *_arg679 = "new file contents";
  size_t _arg679_size = 17;
  int _ret677;
  _ret677 = guestfs_write (g, _arg678, _arg679, _arg679_size);
  if (_ret677 == -1)
    return -1;
  const char *_arg681 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg681);
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

  const char *_features683[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features683)) {
    skipped ("test_lvm_canonical_lv_name_0", "group %s not available in daemon",
             _features683[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResultString for lvm_canonical_lv_name (0) */
  const char *_arg684 = "/dev/mapper/VG-LV";
  CLEANUP_FREE char *ret;
  ret = guestfs_lvm_canonical_lv_name (g, _arg684);
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

  const char *_features686[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features686)) {
    skipped ("test_lvm_canonical_lv_name_1", "group %s not available in daemon",
             _features686[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResultString for lvm_canonical_lv_name (1) */
  const char *_arg687 = "/dev/VG/LV";
  CLEANUP_FREE char *ret;
  ret = guestfs_lvm_canonical_lv_name (g, _arg687);
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
  const char *_arg689 = "/dev/sdd";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread_device (g, _arg689, 8, 32768, &size);
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
  const char *_arg693 = "/dev/sda";
  const char *_arg694 = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
  size_t _arg694_size = 66;
  int ret2;
  ret2 = guestfs_pwrite_device (g, _arg693, _arg694, _arg694_size, 446);
  if (ret2 == -1)
    return -1;
  const char *_arg697 = "/dev/sda";
  int ret1;
  ret1 = guestfs_blockdev_rereadpt (g, _arg697);
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
  const char *_arg701 = "/download_offset";
  int _ret700;
  _ret700 = guestfs_mkdir (g, _arg701);
  if (_ret700 == -1)
    return -1;
  CLEANUP_FREE char *_arg704 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *_arg705 = "/download_offset/COPYING.LIB";
  int _ret703;
  _ret703 = guestfs_upload (g, _arg704, _arg705);
  if (_ret703 == -1)
    return -1;
  const char *_arg708 = "/download_offset/COPYING.LIB";
  int _ret707;
  _ret707 = guestfs_download_offset (g, _arg708, "testdownload.tmp", 100, 26430);
  if (_ret707 == -1)
    return -1;
  CLEANUP_FREE char *_arg714 = substitute_srcdir ("testdownload.tmp");
  const char *_arg715 = "/download_offset/COPYING.LIB";
  int _ret713;
  _ret713 = guestfs_upload_offset (g, _arg714, _arg715, 100);
  if (_ret713 == -1)
    return -1;
  const char *_arg718 = "md5";
  const char *_arg719 = "/download_offset/COPYING.LIB";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg718, _arg719);
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
  CLEANUP_FREE char *_arg722 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *_arg723 = "/upload_offset";
  int _ret721;
  _ret721 = guestfs_upload_offset (g, _arg722, _arg723, 0);
  if (_ret721 == -1)
    return -1;
  const char *_arg726 = "md5";
  const char *_arg727 = "/upload_offset";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg726, _arg727);
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
  const char *_arg729 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_to_dev (g, _arg729);
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
  const char *_arg732 = "/dev/sda";
  CLEANUP_FREE char *_ret731;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret731 = guestfs_part_to_dev (g, _arg732);
  guestfs_pop_error_handler (g);
  if (_ret731 != NULL)
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
  const char *_arg734 = "/directory";
  struct guestfs_is_socket_opts_argv _optargs735;
  _optargs735.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_socket_opts_argv (g, _arg734, &_optargs735);
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
  const char *_arg736 = "/directory";
  int ret;
  ret = guestfs_is_symlink (g, _arg736);
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
  const char *_arg738 = "/abssymlink";
  int ret;
  ret = guestfs_is_symlink (g, _arg738);
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
  const char *_arg740 = "/directory";
  struct guestfs_is_fifo_opts_argv _optargs741;
  _optargs741.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_fifo_opts_argv (g, _arg740, &_optargs741);
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
  const char *_arg744 = "/is_fifo";
  int _ret742;
  _ret742 = guestfs_mkfifo (g, 511, _arg744);
  if (_ret742 == -1)
    return -1;
  const char *_arg746 = "/is_fifo";
  struct guestfs_is_fifo_opts_argv _optargs747;
  _optargs747.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_fifo_opts_argv (g, _arg746, &_optargs747);
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
  const char *_arg748 = "/directory";
  struct guestfs_is_blockdev_opts_argv _optargs749;
  _optargs749.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_blockdev_opts_argv (g, _arg748, &_optargs749);
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
  const char *_arg754 = "/is_blockdev";
  int _ret750;
  _ret750 = guestfs_mknod_b (g, 511, 99, 66, _arg754);
  if (_ret750 == -1)
    return -1;
  const char *_arg756 = "/is_blockdev";
  struct guestfs_is_blockdev_opts_argv _optargs757;
  _optargs757.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_blockdev_opts_argv (g, _arg756, &_optargs757);
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
  const char *_arg758 = "/directory";
  struct guestfs_is_chardev_opts_argv _optargs759;
  _optargs759.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_chardev_opts_argv (g, _arg758, &_optargs759);
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
  const char *_arg764 = "/is_chardev";
  int _ret760;
  _ret760 = guestfs_mknod_c (g, 511, 99, 66, _arg764);
  if (_ret760 == -1)
    return -1;
  const char *_arg766 = "/is_chardev";
  struct guestfs_is_chardev_opts_argv _optargs767;
  _optargs767.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_chardev_opts_argv (g, _arg766, &_optargs767);
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
  const char *_arg768 = "/dev/VG/LV";
  int ret;
  ret = guestfs_is_lv (g, _arg768);
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
  const char *_arg770 = "/dev/sda1";
  int ret;
  ret = guestfs_is_lv (g, _arg770);
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
  const char *_arg773 = "/dev/sda1";
  const char *_arg774 = "6ea9252b-0589-a149-2961-67ad38fa3d4c";
  int _ret772;
  _ret772 = guestfs_set_e2uuid (g, _arg773, _arg774);
  if (_ret772 == -1)
    return -1;
  const char *_arg776 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_uuid (g, _arg776);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "6ea9252b-0589-a149-2961-67ad38fa3d4c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_vfs_uuid_0", "vfs_uuid", ret, "6ea9252b-0589-a149-2961-67ad38fa3d4c");
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
  const char *_arg779 = "/dev/sda1";
  const char *_arg780 = "LTEST";
  int _ret778;
  _ret778 = guestfs_set_label (g, _arg779, _arg780);
  if (_ret778 == -1)
    return -1;
  const char *_arg782 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, _arg782);
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
  const char *_arg784 = "/fallocate64";
  int ret1;
  ret1 = guestfs_fallocate64 (g, _arg784, 1000000);
  if (ret1 == -1)
    return -1;
  const char *_arg787 = "/fallocate64";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg787);
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
  CLEANUP_FREE_STRING_LIST char **_ret789;
  _ret789 = guestfs_available_all_groups (g);
  if (_ret789 == NULL)
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
  const char *_arg792 = "/pwrite";
  const char *_arg793 = "new file contents";
  size_t _arg793_size = 17;
  int _ret791;
  _ret791 = guestfs_write (g, _arg792, _arg793, _arg793_size);
  if (_ret791 == -1)
    return -1;
  const char *_arg796 = "/pwrite";
  const char *_arg797 = "data";
  size_t _arg797_size = 4;
  int _ret795;
  _ret795 = guestfs_pwrite (g, _arg796, _arg797, _arg797_size, 4);
  if (_ret795 == -1)
    return -1;
  const char *_arg800 = "/pwrite";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg800);
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
  const char *_arg803 = "/pwrite2";
  const char *_arg804 = "new file contents";
  size_t _arg804_size = 17;
  int _ret802;
  _ret802 = guestfs_write (g, _arg803, _arg804, _arg804_size);
  if (_ret802 == -1)
    return -1;
  const char *_arg807 = "/pwrite2";
  const char *_arg808 = "is extended";
  size_t _arg808_size = 11;
  int _ret806;
  _ret806 = guestfs_pwrite (g, _arg807, _arg808, _arg808_size, 9);
  if (_ret806 == -1)
    return -1;
  const char *_arg811 = "/pwrite2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg811);
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
  const char *_arg814 = "/pwrite3";
  const char *_arg815 = "new file contents";
  size_t _arg815_size = 17;
  int _ret813;
  _ret813 = guestfs_write (g, _arg814, _arg815, _arg815_size);
  if (_ret813 == -1)
    return -1;
  const char *_arg818 = "/pwrite3";
  const char *_arg819 = "";
  size_t _arg819_size = 0;
  int _ret817;
  _ret817 = guestfs_pwrite (g, _arg818, _arg819, _arg819_size, 4);
  if (_ret817 == -1)
    return -1;
  const char *_arg822 = "/pwrite3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg822);
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
  const char *_arg825 = "/internal_write";
  const char *_arg826 = "new file contents";
  size_t _arg826_size = 17;
  int _ret824;
  _ret824 = guestfs_internal_write (g, _arg825, _arg826, _arg826_size);
  if (_ret824 == -1)
    return -1;
  const char *_arg828 = "/internal_write";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg828);
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
  const char *_arg831 = "/internal_write2";
  const char *_arg832 = "\nnew file contents\n";
  size_t _arg832_size = 19;
  int _ret830;
  _ret830 = guestfs_internal_write (g, _arg831, _arg832, _arg832_size);
  if (_ret830 == -1)
    return -1;
  const char *_arg834 = "/internal_write2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg834);
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
  const char *_arg837 = "/internal_write3";
  const char *_arg838 = "\n\n";
  size_t _arg838_size = 2;
  int _ret836;
  _ret836 = guestfs_internal_write (g, _arg837, _arg838, _arg838_size);
  if (_ret836 == -1)
    return -1;
  const char *_arg840 = "/internal_write3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg840);
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
  const char *_arg843 = "/internal_write4";
  const char *_arg844 = "";
  size_t _arg844_size = 0;
  int _ret842;
  _ret842 = guestfs_internal_write (g, _arg843, _arg844, _arg844_size);
  if (_ret842 == -1)
    return -1;
  const char *_arg846 = "/internal_write4";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg846);
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
  const char *_arg849 = "/internal_write5";
  const char *_arg850 = "\n\n\n";
  size_t _arg850_size = 3;
  int _ret848;
  _ret848 = guestfs_internal_write (g, _arg849, _arg850, _arg850_size);
  if (_ret848 == -1)
    return -1;
  const char *_arg852 = "/internal_write5";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg852);
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
  const char *_arg855 = "/internal_write6";
  const char *_arg856 = "\n";
  size_t _arg856_size = 1;
  int _ret854;
  _ret854 = guestfs_internal_write (g, _arg855, _arg856, _arg856_size);
  if (_ret854 == -1)
    return -1;
  const char *_arg858 = "/internal_write6";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg858);
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
  const char *_arg860 = "abcdefghijklmnopqrstuvwxyz";
  const char *_arg862 = "/fill_pattern";
  int ret1;
  ret1 = guestfs_fill_pattern (g, _arg860, 28, _arg862);
  if (ret1 == -1)
    return -1;
  const char *_arg864 = "/fill_pattern";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg864, &size);
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
  CLEANUP_FREE char *_arg867 = substitute_srcdir ("../data/hello.b64");
  const char *_arg868 = "/base64_in";
  int _ret866;
  _ret866 = guestfs_base64_in (g, _arg867, _arg868);
  if (_ret866 == -1)
    return -1;
  const char *_arg870 = "/base64_in";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg870);
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

  const char *_features873[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features873)) {
    skipped ("test_lvresize_free_0", "group %s not available in daemon",
             _features873[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for lvresize_free (0) */
  const char *_arg875 = "/dev/sda";
  const char *_arg876 = "mbr";
  int _ret874;
  _ret874 = guestfs_part_disk (g, _arg875, _arg876);
  if (_ret874 == -1)
    return -1;
  const char *_arg879 = "/dev/sda1";
  int _ret878;
  _ret878 = guestfs_pvcreate (g, _arg879);
  if (_ret878 == -1)
    return -1;
  const char *_arg882 = "VG";
  const char *_arg883_0 = "/dev/sda1";
  const char *const _arg883[] = {
    _arg883_0,
    NULL
  };
  int _ret881;
  _ret881 = guestfs_vgcreate (g, _arg882, (char **) _arg883);
  if (_ret881 == -1)
    return -1;
  const char *_arg886 = "LV";
  const char *_arg887 = "VG";
  int _ret885;
  _ret885 = guestfs_lvcreate (g, _arg886, _arg887, 10);
  if (_ret885 == -1)
    return -1;
  const char *_arg891 = "/dev/VG/LV";
  int _ret890;
  _ret890 = guestfs_lvresize_free (g, _arg891, 100);
  if (_ret890 == -1)
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
  const char *_arg894 = "md5";
  const char *_arg895 = "/dev/sdd";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum_device (g, _arg894, _arg895);
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
  const char *_arg897 = "/dev/sda";
  const char *_arg898 = "mbr";
  int ret3;
  ret3 = guestfs_part_init (g, _arg897, _arg898);
  if (ret3 == -1)
    return -1;
  const char *_arg900 = "/dev/sda";
  const char *_arg901 = "primary";
  int ret2;
  ret2 = guestfs_part_add (g, _arg900, _arg901, 1, -1);
  if (ret2 == -1)
    return -1;
  const char *_arg905 = "/dev/sda";
  int ret1;
  ret1 = guestfs_part_set_mbr_id (g, _arg905, 1, 127);
  if (ret1 == -1)
    return -1;
  const char *_arg909 = "/dev/sda";
  int ret;
  ret = guestfs_part_get_mbr_id (g, _arg909, 1);
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
  const char *_arg913 = "/dev/sda";
  const char *_arg914 = "mbr";
  int _ret912;
  _ret912 = guestfs_part_init (g, _arg913, _arg914);
  if (_ret912 == -1)
    return -1;
  const char *_arg917 = "/dev/sda";
  const char *_arg918 = "primary";
  int _ret916;
  _ret916 = guestfs_part_add (g, _arg917, _arg918, 1, -1);
  if (_ret916 == -1)
    return -1;
  const char *_arg923 = "/dev/sda";
  int _ret922;
  _ret922 = guestfs_part_set_bootable (g, _arg923, 1, 1);
  if (_ret922 == -1)
    return -1;
  const char *_arg927 = "/dev/sda";
  int ret;
  ret = guestfs_part_get_bootable (g, _arg927, 1);
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
  const char *_arg931 = "/dev/sda";
  const char *_arg932 = "mbr";
  int _ret930;
  _ret930 = guestfs_part_init (g, _arg931, _arg932);
  if (_ret930 == -1)
    return -1;
  const char *_arg935 = "/dev/sda";
  const char *_arg936 = "primary";
  int _ret934;
  _ret934 = guestfs_part_add (g, _arg935, _arg936, 1, -1);
  if (_ret934 == -1)
    return -1;
  const char *_arg941 = "/dev/sda";
  int _ret940;
  _ret940 = guestfs_part_del (g, _arg941, 1);
  if (_ret940 == -1)
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
  int _ret944;
  _ret944 = guestfs_vgscan (g);
  if (_ret944 == -1)
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

  const char *_features946[] = { "xz", NULL };
  if (!guestfs_feature_available (g, (char **) _features946)) {
    skipped ("test_txz_in_0", "group %s not available in daemon",
             _features946[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for txz_in (0) */
  const char *_arg948 = "/txz_in";
  int _ret947;
  _ret947 = guestfs_mkdir (g, _arg948);
  if (_ret947 == -1)
    return -1;
  CLEANUP_FREE char *_arg951 = substitute_srcdir ("$srcdir/../data/helloworld.tar.xz");
  const char *_arg952 = "/txz_in";
  int _ret950;
  _ret950 = guestfs_txz_in (g, _arg951, _arg952);
  if (_ret950 == -1)
    return -1;
  const char *_arg954 = "/txz_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg954);
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
  const char *_arg957 = "/dev/VG/LV";
  int _ret956;
  _ret956 = guestfs_zero_device (g, _arg957);
  if (_ret956 == -1)
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
  const char *_arg959 = "/copy_size";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg959);
  if (ret3 == -1)
    return -1;
  const char *_arg961 = "/copy_size/src";
  const char *_arg962 = "hello, world";
  size_t _arg962_size = 12;
  int ret2;
  ret2 = guestfs_write (g, _arg961, _arg962, _arg962_size);
  if (ret2 == -1)
    return -1;
  const char *_arg964 = "/copy_size/src";
  const char *_arg965 = "/copy_size/dest";
  int ret1;
  ret1 = guestfs_copy_size (g, _arg964, _arg965, 5);
  if (ret1 == -1)
    return -1;
  const char *_arg968 = "/copy_size/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg968, &size);
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
  const char *_arg970 = "/initrd";
  const char *_arg971 = "known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_initrd_cat (g, _arg970, _arg971, &size);
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
  const char *_arg973 = "/";
  struct guestfs_umount_opts_argv _optargs974;
  _optargs974.force = 0;
  _optargs974.lazyunmount = 0;
  _optargs974.bitmask = UINT64_C(0x3);
  int ret5;
  ret5 = guestfs_umount_opts_argv (g, _arg973, &_optargs974);
  if (ret5 == -1)
    return -1;
  const char *_arg976_0 = "VG";
  const char *const _arg976[] = {
    _arg976_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vg_activate (g, 0, (char **) _arg976);
  if (ret4 == -1)
    return -1;
  const char *_arg978 = "VG";
  const char *_arg979 = "VG2";
  int ret3;
  ret3 = guestfs_vgrename (g, _arg978, _arg979);
  if (ret3 == -1)
    return -1;
  const char *_arg982_0 = "VG2";
  const char *const _arg982[] = {
    _arg982_0,
    NULL
  };
  int ret2;
  ret2 = guestfs_vg_activate (g, 1, (char **) _arg982);
  if (ret2 == -1)
    return -1;
  const char *_arg984 = "/dev/VG2/LV";
  const char *_arg985 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg984, _arg985);
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
  const char *_arg988 = "/dev/VG/LV";
  const char *_arg989 = "/dev/VG/LV2";
  int ret1;
  ret1 = guestfs_lvrename (g, _arg988, _arg989);
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
  const char *_arg992 = "/filesize";
  const char *_arg993 = "hello, world";
  size_t _arg993_size = 12;
  int ret1;
  ret1 = guestfs_write (g, _arg992, _arg993, _arg993_size);
  if (ret1 == -1)
    return -1;
  const char *_arg995 = "/filesize";
  int64_t ret;
  ret = guestfs_filesize (g, _arg995);
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
  const char *_arg997 = "/dd";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg997);
  if (ret3 == -1)
    return -1;
  const char *_arg999 = "/dd/src";
  const char *_arg1000 = "hello, world";
  size_t _arg1000_size = 12;
  int ret2;
  ret2 = guestfs_write (g, _arg999, _arg1000, _arg1000_size);
  if (ret2 == -1)
    return -1;
  const char *_arg1002 = "/dd/src";
  const char *_arg1003 = "/dd/dest";
  int ret1;
  ret1 = guestfs_dd (g, _arg1002, _arg1003);
  if (ret1 == -1)
    return -1;
  const char *_arg1005 = "/dd/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg1005, &size);
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
  const char *const _arg1008[1] = { NULL };
  int _ret1007;
  _ret1007 = guestfs_available (g, (char **) _arg1008);
  if (_ret1007 == -1)
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
  const char *_arg1012 = "/fill";
  int ret1;
  ret1 = guestfs_fill (g, 99, 10, _arg1012);
  if (ret1 == -1)
    return -1;
  const char *_arg1014 = "/fill";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg1014, &size);
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
  const char *_arg1017 = "/dev/sda";
  const char *_arg1018 = "gpt";
  int _ret1016;
  _ret1016 = guestfs_part_disk (g, _arg1017, _arg1018);
  if (_ret1016 == -1)
    return -1;
  const char *_arg1020 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_parttype (g, _arg1020);
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
  const char *_arg1023 = "/dev/sda";
  const char *_arg1024 = "gpt";
  int _ret1022;
  _ret1022 = guestfs_part_disk (g, _arg1023, _arg1024);
  if (_ret1022 == -1)
    return -1;
  const char *_arg1027 = "/dev/sda";
  const char *_arg1029 = "thepartname";
  int _ret1026;
  _ret1026 = guestfs_part_set_name (g, _arg1027, 1, _arg1029);
  if (_ret1026 == -1)
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
  const char *_arg1032 = "/dev/sda";
  const char *_arg1033 = "mbr";
  int _ret1031;
  _ret1031 = guestfs_part_disk (g, _arg1032, _arg1033);
  if (_ret1031 == -1)
    return -1;
  const char *_arg1036 = "/dev/sda";
  int _ret1035;
  _ret1035 = guestfs_part_set_bootable (g, _arg1036, 1, 1);
  if (_ret1035 == -1)
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
  const char *_arg1041 = "/dev/sda";
  const char *_arg1042 = "mbr";
  int _ret1040;
  _ret1040 = guestfs_part_disk (g, _arg1041, _arg1042);
  if (_ret1040 == -1)
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
  const char *_arg1045 = "/dev/sda";
  const char *_arg1046 = "gpt";
  int _ret1044;
  _ret1044 = guestfs_part_disk (g, _arg1045, _arg1046);
  if (_ret1044 == -1)
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
  const char *_arg1049 = "/dev/sda";
  const char *_arg1050 = "mbr";
  int _ret1048;
  _ret1048 = guestfs_part_init (g, _arg1049, _arg1050);
  if (_ret1048 == -1)
    return -1;
  const char *_arg1053 = "/dev/sda";
  const char *_arg1054 = "primary";
  int _ret1052;
  _ret1052 = guestfs_part_add (g, _arg1053, _arg1054, 1, -1);
  if (_ret1052 == -1)
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
  const char *_arg1059 = "/dev/sda";
  const char *_arg1060 = "gpt";
  int _ret1058;
  _ret1058 = guestfs_part_init (g, _arg1059, _arg1060);
  if (_ret1058 == -1)
    return -1;
  const char *_arg1063 = "/dev/sda";
  const char *_arg1064 = "primary";
  int _ret1062;
  _ret1062 = guestfs_part_add (g, _arg1063, _arg1064, 34, 127);
  if (_ret1062 == -1)
    return -1;
  const char *_arg1069 = "/dev/sda";
  const char *_arg1070 = "primary";
  int _ret1068;
  _ret1068 = guestfs_part_add (g, _arg1069, _arg1070, 128, -34);
  if (_ret1068 == -1)
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
  const char *_arg1075 = "/dev/sda";
  const char *_arg1076 = "mbr";
  int _ret1074;
  _ret1074 = guestfs_part_init (g, _arg1075, _arg1076);
  if (_ret1074 == -1)
    return -1;
  const char *_arg1079 = "/dev/sda";
  const char *_arg1080 = "primary";
  int _ret1078;
  _ret1078 = guestfs_part_add (g, _arg1079, _arg1080, 32, 127);
  if (_ret1078 == -1)
    return -1;
  const char *_arg1085 = "/dev/sda";
  const char *_arg1086 = "primary";
  int _ret1084;
  _ret1084 = guestfs_part_add (g, _arg1085, _arg1086, 128, 255);
  if (_ret1084 == -1)
    return -1;
  const char *_arg1091 = "/dev/sda";
  const char *_arg1092 = "primary";
  int _ret1090;
  _ret1090 = guestfs_part_add (g, _arg1091, _arg1092, 256, 511);
  if (_ret1090 == -1)
    return -1;
  const char *_arg1097 = "/dev/sda";
  const char *_arg1098 = "primary";
  int _ret1096;
  _ret1096 = guestfs_part_add (g, _arg1097, _arg1098, 512, -1);
  if (_ret1096 == -1)
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
  const char *_arg1103 = "/dev/sda";
  const char *_arg1104 = "gpt";
  int _ret1102;
  _ret1102 = guestfs_part_init (g, _arg1103, _arg1104);
  if (_ret1102 == -1)
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
  const char *_arg1106 = "/known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread (g, _arg1106, 1, 3, &size);
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
  const char *_arg1110 = "/empty";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread (g, _arg1110, 0, 100, &size);
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
  const char *_arg1114 = "/mkdir_mode";
  int ret1;
  ret1 = guestfs_mkdir_mode (g, _arg1114, 73);
  if (ret1 == -1)
    return -1;
  const char *_arg1117 = "/mkdir_mode";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1117);
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
  const char *_arg1119 = "/utimens-file";
  int ret2;
  ret2 = guestfs_touch (g, _arg1119);
  if (ret2 == -1)
    return -1;
  const char *_arg1121 = "/utimens-file";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1121, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1127 = "/utimens-file";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1127);
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
  const char *_arg1129 = "/utimens-dir";
  int ret2;
  ret2 = guestfs_mkdir (g, _arg1129);
  if (ret2 == -1)
    return -1;
  const char *_arg1131 = "/utimens-dir";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1131, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1137 = "/utimens-dir";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1137);
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
  const char *_arg1140 = "/utimens-fifo";
  int ret2;
  ret2 = guestfs_mkfifo (g, 420, _arg1140);
  if (ret2 == -1)
    return -1;
  const char *_arg1142 = "/utimens-fifo";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1142, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1148 = "/utimens-fifo";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1148);
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
  const char *_arg1150 = "/utimens-file";
  const char *_arg1151 = "/utimens-link";
  int ret2;
  ret2 = guestfs_ln_sf (g, _arg1150, _arg1151);
  if (ret2 == -1)
    return -1;
  const char *_arg1153 = "/utimens-link";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1153, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1159 = "/utimens-link";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1159);
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
  const char *_arg1164 = "/utimens-block";
  int ret2;
  ret2 = guestfs_mknod_b (g, 420, 8, 0, _arg1164);
  if (ret2 == -1)
    return -1;
  const char *_arg1166 = "/utimens-block";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1166, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1172 = "/utimens-block";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1172);
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
  const char *_arg1177 = "/utimens-char";
  int ret2;
  ret2 = guestfs_mknod_c (g, 420, 1, 3, _arg1177);
  if (ret2 == -1)
    return -1;
  const char *_arg1179 = "/utimens-char";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1179, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1185 = "/utimens-char";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1185);
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
  const char *_arg1187 = "/truncate_size";
  int ret2;
  ret2 = guestfs_touch (g, _arg1187);
  if (ret2 == -1)
    return -1;
  const char *_arg1189 = "/truncate_size";
  int ret1;
  ret1 = guestfs_truncate_size (g, _arg1189, 1000);
  if (ret1 == -1)
    return -1;
  const char *_arg1192 = "/truncate_size";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1192);
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
  const char *_arg1194 = "/truncate";
  const char *_arg1195 = "some stuff so size is not zero";
  size_t _arg1195_size = 30;
  int ret2;
  ret2 = guestfs_write (g, _arg1194, _arg1195, _arg1195_size);
  if (ret2 == -1)
    return -1;
  const char *_arg1197 = "/truncate";
  int ret1;
  ret1 = guestfs_truncate (g, _arg1197);
  if (ret1 == -1)
    return -1;
  const char *_arg1199 = "/truncate";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1199);
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
  const char *_arg1201 = "/dev/sdb1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_type (g, _arg1201);
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
  const char *_arg1203 = "/DIRECTORY";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1203);
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
  const char *_arg1205 = "/DIRECTORY/";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1205);
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
  const char *_arg1207 = "/Known-1";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1207);
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
  const char *_arg1210 = "/Known-1/";
  CLEANUP_FREE char *_ret1209;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1209 = guestfs_case_sensitive_path (g, _arg1210);
  guestfs_pop_error_handler (g);
  if (_ret1209 != NULL)
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
  const char *_arg1213 = "/case_sensitive_path";
  int _ret1212;
  _ret1212 = guestfs_mkdir (g, _arg1213);
  if (_ret1212 == -1)
    return -1;
  const char *_arg1216 = "/case_sensitive_path/bbb";
  int _ret1215;
  _ret1215 = guestfs_mkdir (g, _arg1216);
  if (_ret1215 == -1)
    return -1;
  const char *_arg1219 = "/case_sensitive_path/bbb/c";
  int _ret1218;
  _ret1218 = guestfs_touch (g, _arg1219);
  if (_ret1218 == -1)
    return -1;
  const char *_arg1221 = "/CASE_SENSITIVE_path/bbB/C";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1221);
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
  const char *_arg1224 = "/case_sensitive_path2";
  int _ret1223;
  _ret1223 = guestfs_mkdir (g, _arg1224);
  if (_ret1223 == -1)
    return -1;
  const char *_arg1227 = "/case_sensitive_path2/bbb";
  int _ret1226;
  _ret1226 = guestfs_mkdir (g, _arg1227);
  if (_ret1226 == -1)
    return -1;
  const char *_arg1230 = "/case_sensitive_path2/bbb/c";
  int _ret1229;
  _ret1229 = guestfs_touch (g, _arg1230);
  if (_ret1229 == -1)
    return -1;
  const char *_arg1232 = "/case_sensitive_PATH2////bbB/C";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1232);
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
  const char *_arg1235 = "/case_sensitive_path3";
  int _ret1234;
  _ret1234 = guestfs_mkdir (g, _arg1235);
  if (_ret1234 == -1)
    return -1;
  const char *_arg1238 = "/case_sensitive_path3/bbb";
  int _ret1237;
  _ret1237 = guestfs_mkdir (g, _arg1238);
  if (_ret1237 == -1)
    return -1;
  const char *_arg1241 = "/case_sensitive_path3/bbb/c";
  int _ret1240;
  _ret1240 = guestfs_touch (g, _arg1241);
  if (_ret1240 == -1)
    return -1;
  const char *_arg1244 = "/case_SENSITIVE_path3/bbb/../bbb/C";
  CLEANUP_FREE char *_ret1243;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1243 = guestfs_case_sensitive_path (g, _arg1244);
  guestfs_pop_error_handler (g);
  if (_ret1243 != NULL)
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
  const char *_arg1247 = "/case_sensitive_path4";
  int _ret1246;
  _ret1246 = guestfs_mkdir (g, _arg1247);
  if (_ret1246 == -1)
    return -1;
  const char *_arg1249 = "/case_SENSITIVE_path4/new_file";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1249);
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
  const char *_arg1251_0 = "This";
  const char *_arg1251_1 = "is";
  const char *_arg1251_2 = "a";
  const char *_arg1251_3 = "test";
  const char *const _arg1251[] = {
    _arg1251_0,
    _arg1251_1,
    _arg1251_2,
    _arg1251_3,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_echo_daemon (g, (char **) _arg1251);
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

  const char *_features1253[] = { "linuxmodules", NULL };
  if (!guestfs_feature_available (g, (char **) _features1253)) {
    skipped ("test_modprobe_0", "group %s not available in daemon",
             _features1253[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for modprobe (0) */
  const char *_arg1255 = "fat";
  int _ret1254;
  _ret1254 = guestfs_modprobe (g, _arg1255);
  if (_ret1254 == -1)
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

  const char *_features1257[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1257)) {
    skipped ("test_mke2journal_U_0", "group %s not available in daemon",
             _features1257[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for mke2journal_U (0) */
  const char *_arg1259 = "/dev/sda";
  const char *_arg1260 = "mbr";
  int _ret1258;
  _ret1258 = guestfs_part_init (g, _arg1259, _arg1260);
  if (_ret1258 == -1)
    return -1;
  const char *_arg1263 = "/dev/sda";
  const char *_arg1264 = "p";
  int _ret1262;
  _ret1262 = guestfs_part_add (g, _arg1263, _arg1264, 64, 204799);
  if (_ret1262 == -1)
    return -1;
  const char *_arg1269 = "/dev/sda";
  const char *_arg1270 = "p";
  int _ret1268;
  _ret1268 = guestfs_part_add (g, _arg1269, _arg1270, 204800, -64);
  if (_ret1268 == -1)
    return -1;
  const char *_arg1276 = "6ea9252b-0589-a149-2961-67ad38fa3d4c";
  const char *_arg1277 = "/dev/sda1";
  int _ret1274;
  _ret1274 = guestfs_mke2journal_U (g, 4096, _arg1276, _arg1277);
  if (_ret1274 == -1)
    return -1;
  const char *_arg1280 = "ext2";
  const char *_arg1282 = "/dev/sda2";
  const char *_arg1283 = "6ea9252b-0589-a149-2961-67ad38fa3d4c";
  int _ret1279;
  _ret1279 = guestfs_mke2fs_JU (g, _arg1280, 4096, _arg1282, _arg1283);
  if (_ret1279 == -1)
    return -1;
  const char *_arg1286 = "/dev/sda2";
  const char *_arg1287 = "/";
  int _ret1285;
  _ret1285 = guestfs_mount (g, _arg1286, _arg1287);
  if (_ret1285 == -1)
    return -1;
  const char *_arg1290 = "/new";
  const char *_arg1291 = "new file contents";
  size_t _arg1291_size = 17;
  int _ret1289;
  _ret1289 = guestfs_write (g, _arg1290, _arg1291, _arg1291_size);
  if (_ret1289 == -1)
    return -1;
  const char *_arg1293 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1293);
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
  const char *_arg1296 = "/dev/sda";
  const char *_arg1297 = "mbr";
  int _ret1295;
  _ret1295 = guestfs_part_init (g, _arg1296, _arg1297);
  if (_ret1295 == -1)
    return -1;
  const char *_arg1300 = "/dev/sda";
  const char *_arg1301 = "p";
  int _ret1299;
  _ret1299 = guestfs_part_add (g, _arg1300, _arg1301, 64, 204799);
  if (_ret1299 == -1)
    return -1;
  const char *_arg1306 = "/dev/sda";
  const char *_arg1307 = "p";
  int _ret1305;
  _ret1305 = guestfs_part_add (g, _arg1306, _arg1307, 204800, -64);
  if (_ret1305 == -1)
    return -1;
  const char *_arg1313 = "JOURNAL";
  const char *_arg1314 = "/dev/sda1";
  int _ret1311;
  _ret1311 = guestfs_mke2journal_L (g, 4096, _arg1313, _arg1314);
  if (_ret1311 == -1)
    return -1;
  const char *_arg1317 = "ext2";
  const char *_arg1319 = "/dev/sda2";
  const char *_arg1320 = "JOURNAL";
  int _ret1316;
  _ret1316 = guestfs_mke2fs_JL (g, _arg1317, 4096, _arg1319, _arg1320);
  if (_ret1316 == -1)
    return -1;
  const char *_arg1323 = "/dev/sda2";
  const char *_arg1324 = "/";
  int _ret1322;
  _ret1322 = guestfs_mount (g, _arg1323, _arg1324);
  if (_ret1322 == -1)
    return -1;
  const char *_arg1327 = "/new";
  const char *_arg1328 = "new file contents";
  size_t _arg1328_size = 17;
  int _ret1326;
  _ret1326 = guestfs_write (g, _arg1327, _arg1328, _arg1328_size);
  if (_ret1326 == -1)
    return -1;
  const char *_arg1330 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1330);
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
  const char *_arg1333 = "/dev/sda";
  const char *_arg1334 = "mbr";
  int _ret1332;
  _ret1332 = guestfs_part_init (g, _arg1333, _arg1334);
  if (_ret1332 == -1)
    return -1;
  const char *_arg1337 = "/dev/sda";
  const char *_arg1338 = "p";
  int _ret1336;
  _ret1336 = guestfs_part_add (g, _arg1337, _arg1338, 64, 204799);
  if (_ret1336 == -1)
    return -1;
  const char *_arg1343 = "/dev/sda";
  const char *_arg1344 = "p";
  int _ret1342;
  _ret1342 = guestfs_part_add (g, _arg1343, _arg1344, 204800, -64);
  if (_ret1342 == -1)
    return -1;
  const char *_arg1350 = "/dev/sda1";
  int _ret1348;
  _ret1348 = guestfs_mke2journal (g, 4096, _arg1350);
  if (_ret1348 == -1)
    return -1;
  const char *_arg1353 = "ext2";
  const char *_arg1355 = "/dev/sda2";
  const char *_arg1356 = "/dev/sda1";
  int _ret1352;
  _ret1352 = guestfs_mke2fs_J (g, _arg1353, 4096, _arg1355, _arg1356);
  if (_ret1352 == -1)
    return -1;
  const char *_arg1359 = "/dev/sda2";
  const char *_arg1360 = "/";
  int _ret1358;
  _ret1358 = guestfs_mount (g, _arg1359, _arg1360);
  if (_ret1358 == -1)
    return -1;
  const char *_arg1363 = "/new";
  const char *_arg1364 = "new file contents";
  size_t _arg1364_size = 17;
  int _ret1362;
  _ret1362 = guestfs_write (g, _arg1363, _arg1364, _arg1364_size);
  if (_ret1362 == -1)
    return -1;
  const char *_arg1366 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1366);
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
  const char *_arg1369 = "/dev/sda";
  const char *_arg1370 = "mbr";
  int _ret1368;
  _ret1368 = guestfs_part_disk (g, _arg1369, _arg1370);
  if (_ret1368 == -1)
    return -1;
  const char *_arg1373 = "ext2";
  const char *_arg1375 = "/dev/sda1";
  int _ret1372;
  _ret1372 = guestfs_mkfs_b (g, _arg1373, 4096, _arg1375);
  if (_ret1372 == -1)
    return -1;
  const char *_arg1378 = "/dev/sda1";
  const char *_arg1379 = "/";
  int _ret1377;
  _ret1377 = guestfs_mount (g, _arg1378, _arg1379);
  if (_ret1377 == -1)
    return -1;
  const char *_arg1382 = "/new";
  const char *_arg1383 = "new file contents";
  size_t _arg1383_size = 17;
  int _ret1381;
  _ret1381 = guestfs_write (g, _arg1382, _arg1383, _arg1383_size);
  if (_ret1381 == -1)
    return -1;
  const char *_arg1385 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1385);
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
  const char *_arg1388 = "/dev/sda";
  const char *_arg1389 = "mbr";
  int _ret1387;
  _ret1387 = guestfs_part_disk (g, _arg1388, _arg1389);
  if (_ret1387 == -1)
    return -1;
  const char *_arg1392 = "vfat";
  const char *_arg1394 = "/dev/sda1";
  int _ret1391;
  _ret1391 = guestfs_mkfs_b (g, _arg1392, 32768, _arg1394);
  if (_ret1391 == -1)
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
  const char *_arg1397 = "/dev/sda";
  const char *_arg1398 = "mbr";
  int _ret1396;
  _ret1396 = guestfs_part_disk (g, _arg1397, _arg1398);
  if (_ret1396 == -1)
    return -1;
  const char *_arg1401 = "vfat";
  const char *_arg1403 = "/dev/sda1";
  int _ret1400;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1400 = guestfs_mkfs_b (g, _arg1401, 32769, _arg1403);
  guestfs_pop_error_handler (g);
  if (_ret1400 != -1)
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
  const char *_arg1406 = "/dev/sda";
  const char *_arg1407 = "mbr";
  int _ret1405;
  _ret1405 = guestfs_part_disk (g, _arg1406, _arg1407);
  if (_ret1405 == -1)
    return -1;
  const char *_arg1410 = "vfat";
  const char *_arg1412 = "/dev/sda1";
  int _ret1409;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1409 = guestfs_mkfs_b (g, _arg1410, 33280, _arg1412);
  guestfs_pop_error_handler (g);
  if (_ret1409 != -1)
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

  const char *_features1414[] = { "ntfsprogs", NULL };
  if (!guestfs_feature_available (g, (char **) _features1414)) {
    skipped ("test_mkfs_b_4", "group %s not available in daemon",
             _features1414[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkfs_b (4) */
  const char *_arg1416 = "/dev/sda";
  const char *_arg1417 = "mbr";
  int _ret1415;
  _ret1415 = guestfs_part_disk (g, _arg1416, _arg1417);
  if (_ret1415 == -1)
    return -1;
  const char *_arg1420 = "ntfs";
  const char *_arg1422 = "/dev/sda1";
  int _ret1419;
  _ret1419 = guestfs_mkfs_b (g, _arg1420, 32768, _arg1422);
  if (_ret1419 == -1)
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

  const char *_features1424[] = { "inotify", NULL };
  if (!guestfs_feature_available (g, (char **) _features1424)) {
    skipped ("test_inotify_add_watch_0", "group %s not available in daemon",
             _features1424[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for inotify_add_watch (0) */
  const char *_arg1425 = "/inotify_add_watch";
  int ret5;
  ret5 = guestfs_mkdir (g, _arg1425);
  if (ret5 == -1)
    return -1;
  int ret4;
  ret4 = guestfs_inotify_init (g, 0);
  if (ret4 == -1)
    return -1;
  const char *_arg1429 = "/inotify_add_watch";
  int64_t ret3;
  ret3 = guestfs_inotify_add_watch (g, _arg1429, 1073741823);
  if (ret3 == -1)
    return -1;
  const char *_arg1432 = "/inotify_add_watch/a";
  int ret2;
  ret2 = guestfs_touch (g, _arg1432);
  if (ret2 == -1)
    return -1;
  const char *_arg1434 = "/inotify_add_watch/b";
  int ret1;
  ret1 = guestfs_touch (g, _arg1434);
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

  const char *_features1437[] = { "inotify", NULL };
  if (!guestfs_feature_available (g, (char **) _features1437)) {
    skipped ("test_inotify_init_0", "group %s not available in daemon",
             _features1437[0]);
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestRun for inotify_init (0) */
  int _ret1438;
  _ret1438 = guestfs_inotify_init (g, 0);
  if (_ret1438 == -1)
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
  const char *_arg1442 = "/mkswap_file";
  int _ret1441;
  _ret1441 = guestfs_fallocate (g, _arg1442, 8388608);
  if (_ret1441 == -1)
    return -1;
  const char *_arg1446 = "/mkswap_file";
  int _ret1445;
  _ret1445 = guestfs_mkswap_file (g, _arg1446);
  if (_ret1445 == -1)
    return -1;
  const char *_arg1449 = "/mkswap_file";
  int _ret1448;
  _ret1448 = guestfs_rm (g, _arg1449);
  if (_ret1448 == -1)
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

  const char *_features1451[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1451)) {
    skipped ("test_swapon_uuid_0", "group %s not available in daemon",
             _features1451[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for swapon_uuid (0) */
  const char *_arg1453 = "/dev/sdc";
  struct guestfs_mkswap_opts_argv _optargs1454;
  _optargs1454.uuid = "6ea9252b-0589-a149-2961-67ad38fa3d4c";
  _optargs1454.bitmask = UINT64_C(0x2);
  int _ret1452;
  _ret1452 = guestfs_mkswap_opts_argv (g, _arg1453, &_optargs1454);
  if (_ret1452 == -1)
    return -1;
  const char *_arg1456 = "6ea9252b-0589-a149-2961-67ad38fa3d4c";
  int _ret1455;
  _ret1455 = guestfs_swapon_uuid (g, _arg1456);
  if (_ret1455 == -1)
    return -1;
  const char *_arg1459 = "6ea9252b-0589-a149-2961-67ad38fa3d4c";
  int _ret1458;
  _ret1458 = guestfs_swapoff_uuid (g, _arg1459);
  if (_ret1458 == -1)
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
  const char *_arg1462 = "/dev/sda";
  const char *_arg1463 = "mbr";
  int _ret1461;
  _ret1461 = guestfs_part_disk (g, _arg1462, _arg1463);
  if (_ret1461 == -1)
    return -1;
  const char *_arg1466 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1467;
  _optargs1467.label = "swapit";
  _optargs1467.bitmask = UINT64_C(0x1);
  int _ret1465;
  _ret1465 = guestfs_mkswap_opts_argv (g, _arg1466, &_optargs1467);
  if (_ret1465 == -1)
    return -1;
  const char *_arg1469 = "swapit";
  int _ret1468;
  _ret1468 = guestfs_swapon_label (g, _arg1469);
  if (_ret1468 == -1)
    return -1;
  const char *_arg1472 = "swapit";
  int _ret1471;
  _ret1471 = guestfs_swapoff_label (g, _arg1472);
  if (_ret1471 == -1)
    return -1;
  const char *_arg1475 = "/dev/sda";
  int _ret1474;
  _ret1474 = guestfs_zero (g, _arg1475);
  if (_ret1474 == -1)
    return -1;
  const char *_arg1478 = "/dev/sda";
  int _ret1477;
  _ret1477 = guestfs_blockdev_rereadpt (g, _arg1478);
  if (_ret1477 == -1)
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
  const char *_arg1481 = "/swapon_file";
  int _ret1480;
  _ret1480 = guestfs_fallocate (g, _arg1481, 8388608);
  if (_ret1480 == -1)
    return -1;
  const char *_arg1485 = "/swapon_file";
  int _ret1484;
  _ret1484 = guestfs_mkswap_file (g, _arg1485);
  if (_ret1484 == -1)
    return -1;
  const char *_arg1488 = "/swapon_file";
  int _ret1487;
  _ret1487 = guestfs_swapon_file (g, _arg1488);
  if (_ret1487 == -1)
    return -1;
  const char *_arg1491 = "/swapon_file";
  int _ret1490;
  _ret1490 = guestfs_swapoff_file (g, _arg1491);
  if (_ret1490 == -1)
    return -1;
  const char *_arg1494 = "/swapon_file";
  int _ret1493;
  _ret1493 = guestfs_rm (g, _arg1494);
  if (_ret1493 == -1)
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
  const char *_arg1497 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1498;
  _optargs1498.bitmask = UINT64_C(0x0);
  int _ret1496;
  _ret1496 = guestfs_mkswap_opts_argv (g, _arg1497, &_optargs1498);
  if (_ret1496 == -1)
    return -1;
  const char *_arg1500 = "/dev/sda1";
  int _ret1499;
  _ret1499 = guestfs_swapon_device (g, _arg1500);
  if (_ret1499 == -1)
    return -1;
  const char *_arg1503 = "/dev/sda1";
  int _ret1502;
  _ret1502 = guestfs_swapoff_device (g, _arg1503);
  if (_ret1502 == -1)
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
  const char *_arg1505 = "/fallocate";
  int ret1;
  ret1 = guestfs_fallocate (g, _arg1505, 1000000);
  if (ret1 == -1)
    return -1;
  const char *_arg1508 = "/fallocate";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1508);
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
  const char *_arg1511 = "/ln_sf/b";
  int _ret1510;
  _ret1510 = guestfs_mkdir_p (g, _arg1511);
  if (_ret1510 == -1)
    return -1;
  const char *_arg1514 = "/ln_sf/b/c";
  int _ret1513;
  _ret1513 = guestfs_touch (g, _arg1514);
  if (_ret1513 == -1)
    return -1;
  const char *_arg1517 = "../d";
  const char *_arg1518 = "/ln_sf/b/c";
  int _ret1516;
  _ret1516 = guestfs_ln_sf (g, _arg1517, _arg1518);
  if (_ret1516 == -1)
    return -1;
  const char *_arg1520 = "/ln_sf/b/c";
  CLEANUP_FREE char *ret;
  ret = guestfs_readlink (g, _arg1520);
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
  const char *_arg1522 = "/ln_s";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg1522);
  if (ret3 == -1)
    return -1;
  const char *_arg1524 = "/ln_s/a";
  int ret2;
  ret2 = guestfs_touch (g, _arg1524);
  if (ret2 == -1)
    return -1;
  const char *_arg1526 = "a";
  const char *_arg1527 = "/ln_s/b";
  int ret1;
  ret1 = guestfs_ln_s (g, _arg1526, _arg1527);
  if (ret1 == -1)
    return -1;
  const char *_arg1529 = "/ln_s/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_lstat (g, _arg1529);
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
  const char *_arg1531 = "/ln_f";
  int ret4;
  ret4 = guestfs_mkdir (g, _arg1531);
  if (ret4 == -1)
    return -1;
  const char *_arg1533 = "/ln_f/a";
  int ret3;
  ret3 = guestfs_touch (g, _arg1533);
  if (ret3 == -1)
    return -1;
  const char *_arg1535 = "/ln_f/b";
  int ret2;
  ret2 = guestfs_touch (g, _arg1535);
  if (ret2 == -1)
    return -1;
  const char *_arg1537 = "/ln_f/a";
  const char *_arg1538 = "/ln_f/b";
  int ret1;
  ret1 = guestfs_ln_f (g, _arg1537, _arg1538);
  if (ret1 == -1)
    return -1;
  const char *_arg1540 = "/ln_f/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1540);
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
  const char *_arg1542 = "/ln";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg1542);
  if (ret3 == -1)
    return -1;
  const char *_arg1544 = "/ln/a";
  int ret2;
  ret2 = guestfs_touch (g, _arg1544);
  if (ret2 == -1)
    return -1;
  const char *_arg1546 = "/ln/a";
  const char *_arg1547 = "/ln/b";
  int ret1;
  ret1 = guestfs_ln (g, _arg1546, _arg1547);
  if (ret1 == -1)
    return -1;
  const char *_arg1549 = "/ln/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1549);
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

  const char *_features1551[] = { "realpath", NULL };
  if (!guestfs_feature_available (g, (char **) _features1551)) {
    skipped ("test_realpath_0", "group %s not available in daemon",
             _features1551[0]);
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for realpath (0) */
  const char *_arg1552 = "/../directory";
  CLEANUP_FREE char *ret;
  ret = guestfs_realpath (g, _arg1552);
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
  const char *_arg1554 = "abc";
  const char *_arg1555 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zfgrepi (g, _arg1554, _arg1555);
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
  const char *_arg1557 = "abc";
  const char *_arg1558 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zegrepi (g, _arg1557, _arg1558);
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
  const char *_arg1560 = "abc";
  const char *_arg1561 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zgrepi (g, _arg1560, _arg1561);
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
  const char *_arg1563 = "abc";
  const char *_arg1564 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zfgrep (g, _arg1563, _arg1564);
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
  const char *_arg1566 = "abc";
  const char *_arg1567 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zegrep (g, _arg1566, _arg1567);
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
  const char *_arg1569 = "abc";
  const char *_arg1570 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zgrep (g, _arg1569, _arg1570);
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
  const char *_arg1572 = "abc";
  const char *_arg1573 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_fgrepi (g, _arg1572, _arg1573);
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
  const char *_arg1575 = "abc";
  const char *_arg1576 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_egrepi (g, _arg1575, _arg1576);
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
  const char *_arg1578 = "abc";
  const char *_arg1579 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grepi (g, _arg1578, _arg1579);
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
  const char *_arg1581 = "abc";
  const char *_arg1582 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_fgrep (g, _arg1581, _arg1582);
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
  const char *_arg1584 = "abc";
  const char *_arg1585 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_egrep (g, _arg1584, _arg1585);
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
  const char *_arg1587 = "abc";
  const char *_arg1588 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1589;
  _optargs1589.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1587, _arg1588, &_optargs1589);
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
  const char *_arg1590 = "nomatch";
  const char *_arg1591 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1592;
  _optargs1592.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1590, _arg1591, &_optargs1592);
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
  const char *_arg1593 = "nomatch";
  const char *_arg1594 = "/abssymlink";
  struct guestfs_grep_opts_argv _optargs1595;
  _optargs1595.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1593, _arg1594, &_optargs1595);
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
  const char *_arg1596 = "abc";
  const char *_arg1597 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1598;
  _optargs1598.extended = 1;
  _optargs1598.bitmask = UINT64_C(0x1);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1596, _arg1597, &_optargs1598);
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
  const char *_arg1599 = "abc";
  const char *_arg1600 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1601;
  _optargs1601.fixed = 1;
  _optargs1601.bitmask = UINT64_C(0x2);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1599, _arg1600, &_optargs1601);
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
  const char *_arg1602 = "abc";
  const char *_arg1603 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1604;
  _optargs1604.insensitive = 1;
  _optargs1604.bitmask = UINT64_C(0x4);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1602, _arg1603, &_optargs1604);
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
  const char *_arg1605 = "abc";
  const char *_arg1606 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1607;
  _optargs1607.extended = 1;
  _optargs1607.insensitive = 1;
  _optargs1607.bitmask = UINT64_C(0x5);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1605, _arg1606, &_optargs1607);
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
  const char *_arg1608 = "abc";
  const char *_arg1609 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1610;
  _optargs1610.fixed = 1;
  _optargs1610.insensitive = 1;
  _optargs1610.bitmask = UINT64_C(0x6);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1608, _arg1609, &_optargs1610);
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
  const char *_arg1611 = "abc";
  const char *_arg1612 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1613;
  _optargs1613.compressed = 1;
  _optargs1613.bitmask = UINT64_C(0x8);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1611, _arg1612, &_optargs1613);
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
  const char *_arg1614 = "abc";
  const char *_arg1615 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1616;
  _optargs1616.extended = 1;
  _optargs1616.compressed = 1;
  _optargs1616.bitmask = UINT64_C(0x9);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1614, _arg1615, &_optargs1616);
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
  const char *_arg1617 = "abc";
  const char *_arg1618 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1619;
  _optargs1619.fixed = 1;
  _optargs1619.compressed = 1;
  _optargs1619.bitmask = UINT64_C(0xa);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1617, _arg1618, &_optargs1619);
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
  const char *_arg1620 = "abc";
  const char *_arg1621 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1622;
  _optargs1622.insensitive = 1;
  _optargs1622.compressed = 1;
  _optargs1622.bitmask = UINT64_C(0xc);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1620, _arg1621, &_optargs1622);
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
  const char *_arg1623 = "abc";
  const char *_arg1624 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1625;
  _optargs1625.extended = 1;
  _optargs1625.insensitive = 1;
  _optargs1625.compressed = 1;
  _optargs1625.bitmask = UINT64_C(0xd);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1623, _arg1624, &_optargs1625);
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
  const char *_arg1626 = "abc";
  const char *_arg1627 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1628;
  _optargs1628.fixed = 1;
  _optargs1628.insensitive = 1;
  _optargs1628.compressed = 1;
  _optargs1628.bitmask = UINT64_C(0xe);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1626, _arg1627, &_optargs1628);
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

  const char *_features1631[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1631)) {
    skipped ("test_mknod_c_0", "group %s not available in daemon",
             _features1631[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mknod_c (0) */
  const char *_arg1635 = "/mknod_c";
  int ret1;
  ret1 = guestfs_mknod_c (g, 511, 99, 66, _arg1635);
  if (ret1 == -1)
    return -1;
  const char *_arg1637 = "/mknod_c";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1637);
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

  const char *_features1639[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1639)) {
    skipped ("test_mknod_b_0", "group %s not available in daemon",
             _features1639[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mknod_b (0) */
  const char *_arg1643 = "/mknod_b";
  int ret1;
  ret1 = guestfs_mknod_b (g, 511, 99, 66, _arg1643);
  if (ret1 == -1)
    return -1;
  const char *_arg1645 = "/mknod_b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1645);
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

  const char *_features1647[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1647)) {
    skipped ("test_mkfifo_0", "group %s not available in daemon",
             _features1647[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mkfifo (0) */
  const char *_arg1649 = "/mkfifo";
  int ret1;
  ret1 = guestfs_mkfifo (g, 511, _arg1649);
  if (ret1 == -1)
    return -1;
  const char *_arg1651 = "/mkfifo";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1651);
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

  const char *_features1653[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1653)) {
    skipped ("test_mknod_0", "group %s not available in daemon",
             _features1653[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mknod (0) */
  const char *_arg1657 = "/mknod";
  int ret1;
  ret1 = guestfs_mknod (g, 4607, 0, 0, _arg1657);
  if (ret1 == -1)
    return -1;
  const char *_arg1659 = "/mknod";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1659);
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

  const char *_features1661[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1661)) {
    skipped ("test_mknod_1", "group %s not available in daemon",
             _features1661[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mknod (1) */
  const char *_arg1665 = "/mknod2";
  int ret1;
  ret1 = guestfs_mknod (g, 25087, 66, 99, _arg1665);
  if (ret1 == -1)
    return -1;
  const char *_arg1667 = "/mknod2";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1667);
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

  const char *_features1669[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1669)) {
    skipped ("test_mkswap_U_0", "group %s not available in daemon",
             _features1669[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkswap_U (0) */
  const char *_arg1671 = "/dev/sda";
  const char *_arg1672 = "mbr";
  int _ret1670;
  _ret1670 = guestfs_part_disk (g, _arg1671, _arg1672);
  if (_ret1670 == -1)
    return -1;
  const char *_arg1675 = "6ea9252b-0589-a149-2961-67ad38fa3d4c";
  const char *_arg1676 = "/dev/sda1";
  int _ret1674;
  _ret1674 = guestfs_mkswap_U (g, _arg1675, _arg1676);
  if (_ret1674 == -1)
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
  const char *_arg1679 = "/dev/sda";
  const char *_arg1680 = "mbr";
  int _ret1678;
  _ret1678 = guestfs_part_disk (g, _arg1679, _arg1680);
  if (_ret1678 == -1)
    return -1;
  const char *_arg1683 = "hello";
  const char *_arg1684 = "/dev/sda1";
  int _ret1682;
  _ret1682 = guestfs_mkswap_L (g, _arg1683, _arg1684);
  if (_ret1682 == -1)
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
  const char *_arg1687 = "/dev/sda";
  const char *_arg1688 = "mbr";
  int _ret1686;
  _ret1686 = guestfs_part_disk (g, _arg1687, _arg1688);
  if (_ret1686 == -1)
    return -1;
  const char *_arg1691 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1692;
  _optargs1692.bitmask = UINT64_C(0x0);
  int _ret1690;
  _ret1690 = guestfs_mkswap_opts_argv (g, _arg1691, &_optargs1692);
  if (_ret1690 == -1)
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
  const char *_arg1694 = "/dev/sda";
  const char *_arg1695 = "mbr";
  int _ret1693;
  _ret1693 = guestfs_part_disk (g, _arg1694, _arg1695);
  if (_ret1693 == -1)
    return -1;
  const char *_arg1698 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1699;
  _optargs1699.label = "hello";
  _optargs1699.bitmask = UINT64_C(0x1);
  int _ret1697;
  _ret1697 = guestfs_mkswap_opts_argv (g, _arg1698, &_optargs1699);
  if (_ret1697 == -1)
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

  const char *_features1700[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1700)) {
    skipped ("test_mkswap_2", "group %s not available in daemon",
             _features1700[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkswap (2) */
  const char *_arg1702 = "/dev/sda";
  const char *_arg1703 = "mbr";
  int _ret1701;
  _ret1701 = guestfs_part_disk (g, _arg1702, _arg1703);
  if (_ret1701 == -1)
    return -1;
  const char *_arg1706 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1707;
  _optargs1707.uuid = "6ea9252b-0589-a149-2961-67ad38fa3d4c";
  _optargs1707.bitmask = UINT64_C(0x2);
  int _ret1705;
  _ret1705 = guestfs_mkswap_opts_argv (g, _arg1706, &_optargs1707);
  if (_ret1705 == -1)
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

  const char *_features1708[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1708)) {
    skipped ("test_mkswap_3", "group %s not available in daemon",
             _features1708[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkswap (3) */
  const char *_arg1710 = "/dev/sda";
  const char *_arg1711 = "mbr";
  int _ret1709;
  _ret1709 = guestfs_part_disk (g, _arg1710, _arg1711);
  if (_ret1709 == -1)
    return -1;
  const char *_arg1714 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1715;
  _optargs1715.label = "hello";
  _optargs1715.uuid = "6ea9252b-0589-a149-2961-67ad38fa3d4c";
  _optargs1715.bitmask = UINT64_C(0x3);
  int _ret1713;
  _ret1713 = guestfs_mkswap_opts_argv (g, _arg1714, &_optargs1715);
  if (_ret1713 == -1)
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
  const char *_arg1716 = "/initrd";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_initrd_list (g, _arg1716);
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
  const char *_arg1718 = "/directory";
  int64_t ret;
  ret = guestfs_du (g, _arg1718);
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
  const char *_arg1721 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, 3, _arg1721);
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
  const char *_arg1724 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, -9998, _arg1724);
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
  const char *_arg1727 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, 0, _arg1727);
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
  const char *_arg1729 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail (g, _arg1729);
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
  const char *_arg1732 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, 3, _arg1732);
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
  const char *_arg1735 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, -9997, _arg1735);
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
  const char *_arg1738 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, 0, _arg1738);
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
  const char *_arg1740 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head (g, _arg1740);
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
  const char *_arg1742 = "/abssymlink";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head (g, _arg1742);
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
  const char *_arg1744 = "/100kallspaces";
  int ret;
  ret = guestfs_wc_c (g, _arg1744);
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
  const char *_arg1746 = "/10klines";
  int ret;
  ret = guestfs_wc_w (g, _arg1746);
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
  const char *_arg1748 = "/10klines";
  int ret;
  ret = guestfs_wc_l (g, _arg1748);
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
  const char *_arg1750 = "/abssymlink";
  int ret;
  ret = guestfs_wc_l (g, _arg1750);
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
  const char *_arg1753 = "/mkdtemp";
  int _ret1752;
  _ret1752 = guestfs_mkdir (g, _arg1753);
  if (_ret1752 == -1)
    return -1;
  const char *_arg1756 = "/mkdtemp/tmpXXXXXX";
  CLEANUP_FREE char *_ret1755;
  _ret1755 = guestfs_mkdtemp (g, _arg1756);
  if (_ret1755 == NULL)
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

  const char *_features1758[] = { "scrub", NULL };
  if (!guestfs_feature_available (g, (char **) _features1758)) {
    skipped ("test_scrub_file_0", "group %s not available in daemon",
             _features1758[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for scrub_file (0) */
  const char *_arg1760 = "/scrub_file";
  const char *_arg1761 = "content";
  size_t _arg1761_size = 7;
  int _ret1759;
  _ret1759 = guestfs_write (g, _arg1760, _arg1761, _arg1761_size);
  if (_ret1759 == -1)
    return -1;
  const char *_arg1764 = "/scrub_file";
  int _ret1763;
  _ret1763 = guestfs_scrub_file (g, _arg1764);
  if (_ret1763 == -1)
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

  const char *_features1766[] = { "scrub", NULL };
  if (!guestfs_feature_available (g, (char **) _features1766)) {
    skipped ("test_scrub_device_0", "group %s not available in daemon",
             _features1766[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for scrub_device (0) */
  const char *_arg1768 = "/dev/sdc";
  int _ret1767;
  _ret1767 = guestfs_scrub_device (g, _arg1768);
  if (_ret1767 == -1)
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
  const char *_arg1770 = "/glob_expand/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, _arg1770);
  if (ret3 == -1)
    return -1;
  const char *_arg1772 = "/glob_expand/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, _arg1772);
  if (ret2 == -1)
    return -1;
  const char *_arg1774 = "/glob_expand/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, _arg1774);
  if (ret1 == -1)
    return -1;
  const char *_arg1776 = "/glob_expand/b/c/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, _arg1776);
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
  const char *_arg1778 = "/glob_expand2/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, _arg1778);
  if (ret3 == -1)
    return -1;
  const char *_arg1780 = "/glob_expand2/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, _arg1780);
  if (ret2 == -1)
    return -1;
  const char *_arg1782 = "/glob_expand2/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, _arg1782);
  if (ret1 == -1)
    return -1;
  const char *_arg1784 = "/glob_expand2/*/c/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, _arg1784);
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
  const char *_arg1786 = "/glob_expand3/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, _arg1786);
  if (ret3 == -1)
    return -1;
  const char *_arg1788 = "/glob_expand3/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, _arg1788);
  if (ret2 == -1)
    return -1;
  const char *_arg1790 = "/glob_expand3/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, _arg1790);
  if (ret1 == -1)
    return -1;
  const char *_arg1792 = "/glob_expand3/*/x/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, _arg1792);
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

  const char *_features1794[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features1794)) {
    skipped ("test_ntfs_3g_probe_0", "group %s not available in daemon",
             _features1794[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResult for ntfs_3g_probe (0) */
  const char *_arg1795 = "/dev/sda";
  const char *_arg1796 = "mbr";
  int ret2;
  ret2 = guestfs_part_disk (g, _arg1795, _arg1796);
  if (ret2 == -1)
    return -1;
  const char *_arg1798 = "ntfs";
  const char *_arg1799 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1800;
  _optargs1800.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_mkfs_opts_argv (g, _arg1798, _arg1799, &_optargs1800);
  if (ret1 == -1)
    return -1;
  const char *_arg1802 = "/dev/sda1";
  int ret;
  ret = guestfs_ntfs_3g_probe (g, 1, _arg1802);
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

  const char *_features1804[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features1804)) {
    skipped ("test_ntfs_3g_probe_1", "group %s not available in daemon",
             _features1804[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResult for ntfs_3g_probe (1) */
  const char *_arg1805 = "/dev/sda";
  const char *_arg1806 = "mbr";
  int ret2;
  ret2 = guestfs_part_disk (g, _arg1805, _arg1806);
  if (ret2 == -1)
    return -1;
  const char *_arg1808 = "ext2";
  const char *_arg1809 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1810;
  _optargs1810.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_mkfs_opts_argv (g, _arg1808, _arg1809, &_optargs1810);
  if (ret1 == -1)
    return -1;
  const char *_arg1812 = "/dev/sda1";
  int ret;
  ret = guestfs_ntfs_3g_probe (g, 1, _arg1812);
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
  int _ret1814;
  _ret1814 = guestfs_sleep (g, 1);
  if (_ret1814 == -1)
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

  const char *_features1817[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features1817)) {
    skipped ("test_lvresize_0", "group %s not available in daemon",
             _features1817[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultString for lvresize (0) */
  const char *_arg1819 = "/dev/sda";
  const char *_arg1820 = "mbr";
  int _ret1818;
  _ret1818 = guestfs_part_disk (g, _arg1819, _arg1820);
  if (_ret1818 == -1)
    return -1;
  const char *_arg1823 = "/dev/sda1";
  int _ret1822;
  _ret1822 = guestfs_pvcreate (g, _arg1823);
  if (_ret1822 == -1)
    return -1;
  const char *_arg1826 = "VG";
  const char *_arg1827_0 = "/dev/sda1";
  const char *const _arg1827[] = {
    _arg1827_0,
    NULL
  };
  int _ret1825;
  _ret1825 = guestfs_vgcreate (g, _arg1826, (char **) _arg1827);
  if (_ret1825 == -1)
    return -1;
  const char *_arg1830 = "LV";
  const char *_arg1831 = "VG";
  int _ret1829;
  _ret1829 = guestfs_lvcreate (g, _arg1830, _arg1831, 10);
  if (_ret1829 == -1)
    return -1;
  const char *_arg1835 = "ext2";
  const char *_arg1836 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs1837;
  _optargs1837.bitmask = UINT64_C(0x0);
  int _ret1834;
  _ret1834 = guestfs_mkfs_opts_argv (g, _arg1835, _arg1836, &_optargs1837);
  if (_ret1834 == -1)
    return -1;
  const char *_arg1839 = "/dev/VG/LV";
  const char *_arg1840 = "/";
  int _ret1838;
  _ret1838 = guestfs_mount (g, _arg1839, _arg1840);
  if (_ret1838 == -1)
    return -1;
  const char *_arg1843 = "/new";
  const char *_arg1844 = "test content";
  size_t _arg1844_size = 12;
  int _ret1842;
  _ret1842 = guestfs_write (g, _arg1843, _arg1844, _arg1844_size);
  if (_ret1842 == -1)
    return -1;
  const char *_arg1847 = "/";
  struct guestfs_umount_opts_argv _optargs1848;
  _optargs1848.force = 0;
  _optargs1848.lazyunmount = 0;
  _optargs1848.bitmask = UINT64_C(0x3);
  int _ret1846;
  _ret1846 = guestfs_umount_opts_argv (g, _arg1847, &_optargs1848);
  if (_ret1846 == -1)
    return -1;
  const char *_arg1850 = "/dev/VG/LV";
  int _ret1849;
  _ret1849 = guestfs_lvresize (g, _arg1850, 20);
  if (_ret1849 == -1)
    return -1;
  const char *_arg1854 = "/dev/VG/LV";
  int _ret1853;
  _ret1853 = guestfs_e2fsck_f (g, _arg1854);
  if (_ret1853 == -1)
    return -1;
  const char *_arg1857 = "/dev/VG/LV";
  struct guestfs_e2fsck_argv _optargs1858;
  _optargs1858.correct = 1;
  _optargs1858.forceall = 0;
  _optargs1858.bitmask = UINT64_C(0x3);
  int _ret1856;
  _ret1856 = guestfs_e2fsck_argv (g, _arg1857, &_optargs1858);
  if (_ret1856 == -1)
    return -1;
  const char *_arg1860 = "/dev/VG/LV";
  struct guestfs_e2fsck_argv _optargs1861;
  _optargs1861.correct = 0;
  _optargs1861.forceall = 1;
  _optargs1861.bitmask = UINT64_C(0x3);
  int _ret1859;
  _ret1859 = guestfs_e2fsck_argv (g, _arg1860, &_optargs1861);
  if (_ret1859 == -1)
    return -1;
  const char *_arg1863 = "/dev/VG/LV";
  int _ret1862;
  _ret1862 = guestfs_resize2fs (g, _arg1863);
  if (_ret1862 == -1)
    return -1;
  const char *_arg1866 = "/dev/VG/LV";
  const char *_arg1867 = "/";
  int _ret1865;
  _ret1865 = guestfs_mount (g, _arg1866, _arg1867);
  if (_ret1865 == -1)
    return -1;
  const char *_arg1869 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1869);
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

  const char *_features1871[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features1871)) {
    skipped ("test_lvresize_1", "group %s not available in daemon",
             _features1871[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for lvresize (1) */
  const char *_arg1873 = "/dev/sda";
  const char *_arg1874 = "mbr";
  int _ret1872;
  _ret1872 = guestfs_part_disk (g, _arg1873, _arg1874);
  if (_ret1872 == -1)
    return -1;
  const char *_arg1877 = "/dev/sda1";
  int _ret1876;
  _ret1876 = guestfs_pvcreate (g, _arg1877);
  if (_ret1876 == -1)
    return -1;
  const char *_arg1880 = "VG";
  const char *_arg1881_0 = "/dev/sda1";
  const char *const _arg1881[] = {
    _arg1881_0,
    NULL
  };
  int _ret1879;
  _ret1879 = guestfs_vgcreate (g, _arg1880, (char **) _arg1881);
  if (_ret1879 == -1)
    return -1;
  const char *_arg1884 = "LV";
  const char *_arg1885 = "VG";
  int _ret1883;
  _ret1883 = guestfs_lvcreate (g, _arg1884, _arg1885, 20);
  if (_ret1883 == -1)
    return -1;
  const char *_arg1889 = "/dev/VG/LV";
  int _ret1888;
  _ret1888 = guestfs_lvresize (g, _arg1889, 10);
  if (_ret1888 == -1)
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

  const char *_features1892[] = { "zerofree", NULL };
  if (!guestfs_feature_available (g, (char **) _features1892)) {
    skipped ("test_zerofree_0", "group %s not available in daemon",
             _features1892[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultString for zerofree (0) */
  const char *_arg1894 = "/dev/sda";
  const char *_arg1895 = "mbr";
  int _ret1893;
  _ret1893 = guestfs_part_disk (g, _arg1894, _arg1895);
  if (_ret1893 == -1)
    return -1;
  const char *_arg1898 = "ext3";
  const char *_arg1899 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1900;
  _optargs1900.bitmask = UINT64_C(0x0);
  int _ret1897;
  _ret1897 = guestfs_mkfs_opts_argv (g, _arg1898, _arg1899, &_optargs1900);
  if (_ret1897 == -1)
    return -1;
  const char *_arg1902 = "/dev/sda1";
  const char *_arg1903 = "/";
  int _ret1901;
  _ret1901 = guestfs_mount (g, _arg1902, _arg1903);
  if (_ret1901 == -1)
    return -1;
  const char *_arg1906 = "/new";
  const char *_arg1907 = "test file";
  size_t _arg1907_size = 9;
  int _ret1905;
  _ret1905 = guestfs_write (g, _arg1906, _arg1907, _arg1907_size);
  if (_ret1905 == -1)
    return -1;
  const char *_arg1910 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs1911;
  _optargs1911.force = 0;
  _optargs1911.lazyunmount = 0;
  _optargs1911.bitmask = UINT64_C(0x3);
  int _ret1909;
  _ret1909 = guestfs_umount_opts_argv (g, _arg1910, &_optargs1911);
  if (_ret1909 == -1)
    return -1;
  const char *_arg1913 = "/dev/sda1";
  int _ret1912;
  _ret1912 = guestfs_zerofree (g, _arg1913);
  if (_ret1912 == -1)
    return -1;
  const char *_arg1916 = "/dev/sda1";
  const char *_arg1917 = "/";
  int _ret1915;
  _ret1915 = guestfs_mount (g, _arg1916, _arg1917);
  if (_ret1915 == -1)
    return -1;
  const char *_arg1919 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1919);
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
  const char *_arg1921 = "/known-4";
  CLEANUP_FREE char *ret;
  ret = guestfs_hexdump (g, _arg1921);
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
  const char *_arg1924 = "/100krandom";
  CLEANUP_FREE char *_ret1923;
  _ret1923 = guestfs_hexdump (g, _arg1924);
  if (_ret1923 == NULL)
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
  const char *_arg1927 = "/abssymlink";
  CLEANUP_FREE char *_ret1926;
  _ret1926 = guestfs_hexdump (g, _arg1927);
  if (_ret1926 == NULL)
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
  const char *_arg1929 = "b";
  const char *_arg1930 = "/known-5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings_e (g, _arg1929, _arg1930);
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
  const char *_arg1932 = "/strings_e";
  const char *_arg1933 = "\0h\0e\0l\0l\0o\0\n\0w\0o\0r\0l\0d\0\n";
  size_t _arg1933_size = 24;
  int ret1;
  ret1 = guestfs_write (g, _arg1932, _arg1933, _arg1933_size);
  if (ret1 == -1)
    return -1;
  const char *_arg1935 = "b";
  const char *_arg1936 = "/strings_e";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings_e (g, _arg1935, _arg1936);
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
  const char *_arg1938 = "/known-5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings (g, _arg1938);
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
  const char *_arg1940 = "/empty";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings (g, _arg1940);
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
  const char *_arg1943 = "/abssymlink";
  CLEANUP_FREE_STRING_LIST char **_ret1942;
  _ret1942 = guestfs_strings (g, _arg1943);
  if (_ret1942 == NULL)
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
  const char *_arg1946 = "/equal";
  int _ret1945;
  _ret1945 = guestfs_mkdir (g, _arg1946);
  if (_ret1945 == -1)
    return -1;
  const char *_arg1949 = "/equal/file1";
  const char *_arg1950 = "contents of a file";
  size_t _arg1950_size = 18;
  int _ret1948;
  _ret1948 = guestfs_write (g, _arg1949, _arg1950, _arg1950_size);
  if (_ret1948 == -1)
    return -1;
  const char *_arg1953 = "/equal/file1";
  const char *_arg1954 = "/equal/file2";
  int _ret1952;
  _ret1952 = guestfs_cp (g, _arg1953, _arg1954);
  if (_ret1952 == -1)
    return -1;
  const char *_arg1956 = "/equal/file1";
  const char *_arg1957 = "/equal/file2";
  int ret;
  ret = guestfs_equal (g, _arg1956, _arg1957);
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
  const char *_arg1960 = "/equal2";
  int _ret1959;
  _ret1959 = guestfs_mkdir (g, _arg1960);
  if (_ret1959 == -1)
    return -1;
  const char *_arg1963 = "/equal2/file1";
  const char *_arg1964 = "contents of a file";
  size_t _arg1964_size = 18;
  int _ret1962;
  _ret1962 = guestfs_write (g, _arg1963, _arg1964, _arg1964_size);
  if (_ret1962 == -1)
    return -1;
  const char *_arg1967 = "/equal2/file2";
  const char *_arg1968 = "contents of another file";
  size_t _arg1968_size = 24;
  int _ret1966;
  _ret1966 = guestfs_write (g, _arg1967, _arg1968, _arg1968_size);
  if (_ret1966 == -1)
    return -1;
  const char *_arg1970 = "/equal2/file1";
  const char *_arg1971 = "/equal2/file2";
  int ret;
  ret = guestfs_equal (g, _arg1970, _arg1971);
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
  const char *_arg1974 = "/equal3";
  int _ret1973;
  _ret1973 = guestfs_mkdir (g, _arg1974);
  if (_ret1973 == -1)
    return -1;
  const char *_arg1977 = "/equal3/file1";
  const char *_arg1978 = "/equal3/file2";
  int _ret1976;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1976 = guestfs_equal (g, _arg1977, _arg1978);
  guestfs_pop_error_handler (g);
  if (_ret1976 != -1)
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
  int _ret1980;
  _ret1980 = guestfs_ping_daemon (g);
  if (_ret1980 == -1)
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
  CLEANUP_FREE char *_ret1982;
  _ret1982 = guestfs_dmesg (g);
  if (_ret1982 == NULL)
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
  int _ret1984;
  _ret1984 = guestfs_drop_caches (g, 3);
  if (_ret1984 == -1)
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
  const char *_arg1988 = "/mv";
  int _ret1987;
  _ret1987 = guestfs_mkdir (g, _arg1988);
  if (_ret1987 == -1)
    return -1;
  const char *_arg1991 = "/mv/old";
  const char *_arg1992 = "file content";
  size_t _arg1992_size = 12;
  int _ret1990;
  _ret1990 = guestfs_write (g, _arg1991, _arg1992, _arg1992_size);
  if (_ret1990 == -1)
    return -1;
  const char *_arg1995 = "/mv/old";
  const char *_arg1996 = "/mv/new";
  int _ret1994;
  _ret1994 = guestfs_mv (g, _arg1995, _arg1996);
  if (_ret1994 == -1)
    return -1;
  const char *_arg1998 = "/mv/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1998);
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
  const char *_arg2001 = "/mv2";
  int _ret2000;
  _ret2000 = guestfs_mkdir (g, _arg2001);
  if (_ret2000 == -1)
    return -1;
  const char *_arg2004 = "/mv2/old";
  const char *_arg2005 = "file content";
  size_t _arg2005_size = 12;
  int _ret2003;
  _ret2003 = guestfs_write (g, _arg2004, _arg2005, _arg2005_size);
  if (_ret2003 == -1)
    return -1;
  const char *_arg2008 = "/mv2/old";
  const char *_arg2009 = "/mv2/new";
  int _ret2007;
  _ret2007 = guestfs_mv (g, _arg2008, _arg2009);
  if (_ret2007 == -1)
    return -1;
  const char *_arg2011 = "/mv2/old";
  struct guestfs_is_file_opts_argv _optargs2012;
  _optargs2012.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, _arg2011, &_optargs2012);
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
  const char *_arg2014 = "/cp_a1";
  int _ret2013;
  _ret2013 = guestfs_mkdir (g, _arg2014);
  if (_ret2013 == -1)
    return -1;
  const char *_arg2017 = "/cp_a2";
  int _ret2016;
  _ret2016 = guestfs_mkdir (g, _arg2017);
  if (_ret2016 == -1)
    return -1;
  const char *_arg2020 = "/cp_a1/file";
  const char *_arg2021 = "file content";
  size_t _arg2021_size = 12;
  int _ret2019;
  _ret2019 = guestfs_write (g, _arg2020, _arg2021, _arg2021_size);
  if (_ret2019 == -1)
    return -1;
  const char *_arg2024 = "/cp_a1";
  const char *_arg2025 = "/cp_a2";
  int _ret2023;
  _ret2023 = guestfs_cp_a (g, _arg2024, _arg2025);
  if (_ret2023 == -1)
    return -1;
  const char *_arg2027 = "/cp_a2/cp_a1/file";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2027);
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
  const char *_arg2030 = "/cp";
  int _ret2029;
  _ret2029 = guestfs_mkdir (g, _arg2030);
  if (_ret2029 == -1)
    return -1;
  const char *_arg2033 = "/cp/old";
  const char *_arg2034 = "file content";
  size_t _arg2034_size = 12;
  int _ret2032;
  _ret2032 = guestfs_write (g, _arg2033, _arg2034, _arg2034_size);
  if (_ret2032 == -1)
    return -1;
  const char *_arg2037 = "/cp/old";
  const char *_arg2038 = "/cp/new";
  int _ret2036;
  _ret2036 = guestfs_cp (g, _arg2037, _arg2038);
  if (_ret2036 == -1)
    return -1;
  const char *_arg2040 = "/cp/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2040);
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
  const char *_arg2043 = "/cp2";
  int _ret2042;
  _ret2042 = guestfs_mkdir (g, _arg2043);
  if (_ret2042 == -1)
    return -1;
  const char *_arg2046 = "/cp2/old";
  const char *_arg2047 = "file content";
  size_t _arg2047_size = 12;
  int _ret2045;
  _ret2045 = guestfs_write (g, _arg2046, _arg2047, _arg2047_size);
  if (_ret2045 == -1)
    return -1;
  const char *_arg2050 = "/cp2/old";
  const char *_arg2051 = "/cp2/new";
  int _ret2049;
  _ret2049 = guestfs_cp (g, _arg2050, _arg2051);
  if (_ret2049 == -1)
    return -1;
  const char *_arg2053 = "/cp2/old";
  struct guestfs_is_file_opts_argv _optargs2054;
  _optargs2054.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, _arg2053, &_optargs2054);
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
  const char *_arg2056 = "/cp3";
  int _ret2055;
  _ret2055 = guestfs_mkdir (g, _arg2056);
  if (_ret2055 == -1)
    return -1;
  const char *_arg2059 = "/cp3/old";
  const char *_arg2060 = "file content";
  size_t _arg2060_size = 12;
  int _ret2058;
  _ret2058 = guestfs_write (g, _arg2059, _arg2060, _arg2060_size);
  if (_ret2058 == -1)
    return -1;
  const char *_arg2063 = "/cp3/dir";
  int _ret2062;
  _ret2062 = guestfs_mkdir (g, _arg2063);
  if (_ret2062 == -1)
    return -1;
  const char *_arg2066 = "/cp3/old";
  const char *_arg2067 = "/cp3/dir/new";
  int _ret2065;
  _ret2065 = guestfs_cp (g, _arg2066, _arg2067);
  if (_ret2065 == -1)
    return -1;
  const char *_arg2069 = "/cp3/dir/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2069);
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

  const char *_features2071[] = { "grub", NULL };
  if (!guestfs_feature_available (g, (char **) _features2071)) {
    skipped ("test_grub_install_0", "group %s not available in daemon",
             _features2071[0]);
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResultTrue for grub_install (0) */
  const char *_arg2073 = "/boot/grub";
  int _ret2072;
  _ret2072 = guestfs_mkdir_p (g, _arg2073);
  if (_ret2072 == -1)
    return -1;
  const char *_arg2076 = "/boot/grub/device.map";
  const char *_arg2077 = "(hd0) /dev/sda";
  size_t _arg2077_size = 14;
  int _ret2075;
  _ret2075 = guestfs_write (g, _arg2076, _arg2077, _arg2077_size);
  if (_ret2075 == -1)
    return -1;
  const char *_arg2080 = "/";
  const char *_arg2081 = "/dev/sda";
  int _ret2079;
  _ret2079 = guestfs_grub_install (g, _arg2080, _arg2081);
  if (_ret2079 == -1)
    return -1;
  const char *_arg2083 = "/boot";
  struct guestfs_is_dir_opts_argv _optargs2084;
  _optargs2084.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2083, &_optargs2084);
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
  const char *_arg2086 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs2087;
  _optargs2087.force = 0;
  _optargs2087.lazyunmount = 0;
  _optargs2087.bitmask = UINT64_C(0x3);
  int _ret2085;
  _ret2085 = guestfs_umount_opts_argv (g, _arg2086, &_optargs2087);
  if (_ret2085 == -1)
    return -1;
  const char *_arg2089 = "/dev/sda1";
  int _ret2088;
  _ret2088 = guestfs_zero (g, _arg2089);
  if (_ret2088 == -1)
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
  const char *_arg2091 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs2092;
  _optargs2092.force = 0;
  _optargs2092.lazyunmount = 0;
  _optargs2092.bitmask = UINT64_C(0x3);
  int ret1;
  ret1 = guestfs_umount_opts_argv (g, _arg2091, &_optargs2092);
  if (ret1 == -1)
    return -1;
  const char *_arg2093 = "ext2";
  const char *_arg2094 = "/dev/sda1";
  int ret;
  ret = guestfs_fsck (g, _arg2093, _arg2094);
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
  const char *_arg2096 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs2097;
  _optargs2097.force = 0;
  _optargs2097.lazyunmount = 0;
  _optargs2097.bitmask = UINT64_C(0x3);
  int ret2;
  ret2 = guestfs_umount_opts_argv (g, _arg2096, &_optargs2097);
  if (ret2 == -1)
    return -1;
  const char *_arg2098 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_zero (g, _arg2098);
  if (ret1 == -1)
    return -1;
  const char *_arg2100 = "ext2";
  const char *_arg2101 = "/dev/sda1";
  int ret;
  ret = guestfs_fsck (g, _arg2100, _arg2101);
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
  const char *_arg2105 = "/dev/sdc";
  int _ret2103;
  _ret2103 = guestfs_mke2journal (g, 1024, _arg2105);
  if (_ret2103 == -1)
    return -1;
  const char *_arg2108 = "/dev/sdc";
  const char *_arg2109 = "6ea9252b-0589-a149-2961-67ad38fa3d4c";
  int _ret2107;
  _ret2107 = guestfs_set_e2uuid (g, _arg2108, _arg2109);
  if (_ret2107 == -1)
    return -1;
  const char *_arg2111 = "/dev/sdc";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, _arg2111);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "6ea9252b-0589-a149-2961-67ad38fa3d4c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_get_e2uuid_0", "get_e2uuid", ret, "6ea9252b-0589-a149-2961-67ad38fa3d4c");
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
  const char *_arg2114 = "/dev/sda1";
  const char *_arg2115 = "6ea9252b-0589-a149-2961-67ad38fa3d4c";
  int _ret2113;
  _ret2113 = guestfs_set_e2uuid (g, _arg2114, _arg2115);
  if (_ret2113 == -1)
    return -1;
  const char *_arg2117 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, _arg2117);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "6ea9252b-0589-a149-2961-67ad38fa3d4c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_e2uuid_0", "get_e2uuid", ret, "6ea9252b-0589-a149-2961-67ad38fa3d4c");
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
  const char *_arg2120 = "/dev/sda1";
  const char *_arg2121 = "clear";
  int _ret2119;
  _ret2119 = guestfs_set_e2uuid (g, _arg2120, _arg2121);
  if (_ret2119 == -1)
    return -1;
  const char *_arg2123 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, _arg2123);
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
  const char *_arg2126 = "/dev/sda1";
  const char *_arg2127 = "random";
  int _ret2125;
  _ret2125 = guestfs_set_e2uuid (g, _arg2126, _arg2127);
  if (_ret2125 == -1)
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
  const char *_arg2130 = "/dev/sda1";
  const char *_arg2131 = "time";
  int _ret2129;
  _ret2129 = guestfs_set_e2uuid (g, _arg2130, _arg2131);
  if (_ret2129 == -1)
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
  const char *_arg2134 = "/dev/sda1";
  const char *_arg2135 = "testlabel";
  int _ret2133;
  _ret2133 = guestfs_set_e2label (g, _arg2134, _arg2135);
  if (_ret2133 == -1)
    return -1;
  const char *_arg2137 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2label (g, _arg2137);
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

  const char *_features2139[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2139)) {
    skipped ("test_pvremove_0", "group %s not available in daemon",
             _features2139[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvremove (0) */
  const char *_arg2140 = "/dev/sda";
  const char *_arg2141 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg2140, _arg2141);
  if (ret7 == -1)
    return -1;
  const char *_arg2143 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg2143);
  if (ret6 == -1)
    return -1;
  const char *_arg2145 = "VG";
  const char *_arg2146_0 = "/dev/sda1";
  const char *const _arg2146[] = {
    _arg2146_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg2145, (char **) _arg2146);
  if (ret5 == -1)
    return -1;
  const char *_arg2148 = "LV1";
  const char *_arg2149 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg2148, _arg2149, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg2152 = "LV2";
  const char *_arg2153 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2152, _arg2153, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2156 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, _arg2156);
  if (ret2 == -1)
    return -1;
  const char *_arg2158 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, _arg2158);
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

  const char *_features2161[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2161)) {
    skipped ("test_pvremove_1", "group %s not available in daemon",
             _features2161[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvremove (1) */
  const char *_arg2162 = "/dev/sda";
  const char *_arg2163 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg2162, _arg2163);
  if (ret7 == -1)
    return -1;
  const char *_arg2165 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg2165);
  if (ret6 == -1)
    return -1;
  const char *_arg2167 = "VG";
  const char *_arg2168_0 = "/dev/sda1";
  const char *const _arg2168[] = {
    _arg2168_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg2167, (char **) _arg2168);
  if (ret5 == -1)
    return -1;
  const char *_arg2170 = "LV1";
  const char *_arg2171 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg2170, _arg2171, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg2174 = "LV2";
  const char *_arg2175 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2174, _arg2175, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2178 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, _arg2178);
  if (ret2 == -1)
    return -1;
  const char *_arg2180 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, _arg2180);
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

  const char *_features2183[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2183)) {
    skipped ("test_pvremove_2", "group %s not available in daemon",
             _features2183[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvremove (2) */
  const char *_arg2184 = "/dev/sda";
  const char *_arg2185 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg2184, _arg2185);
  if (ret7 == -1)
    return -1;
  const char *_arg2187 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg2187);
  if (ret6 == -1)
    return -1;
  const char *_arg2189 = "VG";
  const char *_arg2190_0 = "/dev/sda1";
  const char *const _arg2190[] = {
    _arg2190_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg2189, (char **) _arg2190);
  if (ret5 == -1)
    return -1;
  const char *_arg2192 = "LV1";
  const char *_arg2193 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg2192, _arg2193, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg2196 = "LV2";
  const char *_arg2197 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2196, _arg2197, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2200 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, _arg2200);
  if (ret2 == -1)
    return -1;
  const char *_arg2202 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, _arg2202);
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

  const char *_features2205[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2205)) {
    skipped ("test_vgremove_0", "group %s not available in daemon",
             _features2205[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for vgremove (0) */
  const char *_arg2206 = "/dev/sda";
  const char *_arg2207 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2206, _arg2207);
  if (ret6 == -1)
    return -1;
  const char *_arg2209 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2209);
  if (ret5 == -1)
    return -1;
  const char *_arg2211 = "VG";
  const char *_arg2212_0 = "/dev/sda1";
  const char *const _arg2212[] = {
    _arg2212_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2211, (char **) _arg2212);
  if (ret4 == -1)
    return -1;
  const char *_arg2214 = "LV1";
  const char *_arg2215 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2214, _arg2215, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2218 = "LV2";
  const char *_arg2219 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2218, _arg2219, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2222 = "VG";
  int ret1;
  ret1 = guestfs_vgremove (g, _arg2222);
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

  const char *_features2225[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2225)) {
    skipped ("test_vgremove_1", "group %s not available in daemon",
             _features2225[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for vgremove (1) */
  const char *_arg2226 = "/dev/sda";
  const char *_arg2227 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2226, _arg2227);
  if (ret6 == -1)
    return -1;
  const char *_arg2229 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2229);
  if (ret5 == -1)
    return -1;
  const char *_arg2231 = "VG";
  const char *_arg2232_0 = "/dev/sda1";
  const char *const _arg2232[] = {
    _arg2232_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2231, (char **) _arg2232);
  if (ret4 == -1)
    return -1;
  const char *_arg2234 = "LV1";
  const char *_arg2235 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2234, _arg2235, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2238 = "LV2";
  const char *_arg2239 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2238, _arg2239, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2242 = "VG";
  int ret1;
  ret1 = guestfs_vgremove (g, _arg2242);
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

  const char *_features2245[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2245)) {
    skipped ("test_lvremove_0", "group %s not available in daemon",
             _features2245[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvremove (0) */
  const char *_arg2246 = "/dev/sda";
  const char *_arg2247 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2246, _arg2247);
  if (ret6 == -1)
    return -1;
  const char *_arg2249 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2249);
  if (ret5 == -1)
    return -1;
  const char *_arg2251 = "VG";
  const char *_arg2252_0 = "/dev/sda1";
  const char *const _arg2252[] = {
    _arg2252_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2251, (char **) _arg2252);
  if (ret4 == -1)
    return -1;
  const char *_arg2254 = "LV1";
  const char *_arg2255 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2254, _arg2255, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2258 = "LV2";
  const char *_arg2259 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2258, _arg2259, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2262 = "/dev/VG/LV1";
  int ret1;
  ret1 = guestfs_lvremove (g, _arg2262);
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

  const char *_features2265[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2265)) {
    skipped ("test_lvremove_1", "group %s not available in daemon",
             _features2265[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvremove (1) */
  const char *_arg2266 = "/dev/sda";
  const char *_arg2267 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2266, _arg2267);
  if (ret6 == -1)
    return -1;
  const char *_arg2269 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2269);
  if (ret5 == -1)
    return -1;
  const char *_arg2271 = "VG";
  const char *_arg2272_0 = "/dev/sda1";
  const char *const _arg2272[] = {
    _arg2272_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2271, (char **) _arg2272);
  if (ret4 == -1)
    return -1;
  const char *_arg2274 = "LV1";
  const char *_arg2275 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2274, _arg2275, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2278 = "LV2";
  const char *_arg2279 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2278, _arg2279, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2282 = "/dev/VG";
  int ret1;
  ret1 = guestfs_lvremove (g, _arg2282);
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

  const char *_features2285[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2285)) {
    skipped ("test_lvremove_2", "group %s not available in daemon",
             _features2285[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvremove (2) */
  const char *_arg2286 = "/dev/sda";
  const char *_arg2287 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2286, _arg2287);
  if (ret6 == -1)
    return -1;
  const char *_arg2289 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2289);
  if (ret5 == -1)
    return -1;
  const char *_arg2291 = "VG";
  const char *_arg2292_0 = "/dev/sda1";
  const char *const _arg2292[] = {
    _arg2292_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2291, (char **) _arg2292);
  if (ret4 == -1)
    return -1;
  const char *_arg2294 = "LV1";
  const char *_arg2295 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2294, _arg2295, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2298 = "LV2";
  const char *_arg2299 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2298, _arg2299, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2302 = "/dev/VG";
  int ret1;
  ret1 = guestfs_lvremove (g, _arg2302);
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
  const char *_arg2306 = "/";
  struct guestfs_umount_opts_argv _optargs2307;
  _optargs2307.force = 0;
  _optargs2307.lazyunmount = 0;
  _optargs2307.bitmask = UINT64_C(0x3);
  int _ret2305;
  _ret2305 = guestfs_umount_opts_argv (g, _arg2306, &_optargs2307);
  if (_ret2305 == -1)
    return -1;
  const char *_arg2309 = "/dev/sda1";
  const char *_arg2310 = "/";
  int _ret2308;
  _ret2308 = guestfs_mount_ro (g, _arg2309, _arg2310);
  if (_ret2308 == -1)
    return -1;
  const char *_arg2313 = "/new";
  int _ret2312;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2312 = guestfs_touch (g, _arg2313);
  guestfs_pop_error_handler (g);
  if (_ret2312 != -1)
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
  const char *_arg2316 = "/new";
  const char *_arg2317 = "data";
  size_t _arg2317_size = 4;
  int _ret2315;
  _ret2315 = guestfs_write (g, _arg2316, _arg2317, _arg2317_size);
  if (_ret2315 == -1)
    return -1;
  const char *_arg2320 = "/";
  struct guestfs_umount_opts_argv _optargs2321;
  _optargs2321.force = 0;
  _optargs2321.lazyunmount = 0;
  _optargs2321.bitmask = UINT64_C(0x3);
  int _ret2319;
  _ret2319 = guestfs_umount_opts_argv (g, _arg2320, &_optargs2321);
  if (_ret2319 == -1)
    return -1;
  const char *_arg2323 = "/dev/sda1";
  const char *_arg2324 = "/";
  int _ret2322;
  _ret2322 = guestfs_mount_ro (g, _arg2323, _arg2324);
  if (_ret2322 == -1)
    return -1;
  const char *_arg2326 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2326);
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
  const char *_arg2329 = "/tgz_in";
  int _ret2328;
  _ret2328 = guestfs_mkdir (g, _arg2329);
  if (_ret2328 == -1)
    return -1;
  CLEANUP_FREE char *_arg2332 = substitute_srcdir ("$srcdir/../data/helloworld.tar.gz");
  const char *_arg2333 = "/tgz_in";
  int _ret2331;
  _ret2331 = guestfs_tgz_in (g, _arg2332, _arg2333);
  if (_ret2331 == -1)
    return -1;
  const char *_arg2335 = "/tgz_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2335);
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
  const char *_arg2338 = "/tar_in";
  int _ret2337;
  _ret2337 = guestfs_mkdir (g, _arg2338);
  if (_ret2337 == -1)
    return -1;
  CLEANUP_FREE char *_arg2341 = substitute_srcdir ("$srcdir/../data/helloworld.tar");
  const char *_arg2342 = "/tar_in";
  struct guestfs_tar_in_opts_argv _optargs2343;
  _optargs2343.bitmask = UINT64_C(0x0);
  int _ret2340;
  _ret2340 = guestfs_tar_in_opts_argv (g, _arg2341, _arg2342, &_optargs2343);
  if (_ret2340 == -1)
    return -1;
  const char *_arg2344 = "/tar_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2344);
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
  const char *_arg2347 = "/tar_in_gz";
  int _ret2346;
  _ret2346 = guestfs_mkdir (g, _arg2347);
  if (_ret2346 == -1)
    return -1;
  CLEANUP_FREE char *_arg2350 = substitute_srcdir ("$srcdir/../data/helloworld.tar.gz");
  const char *_arg2351 = "/tar_in_gz";
  struct guestfs_tar_in_opts_argv _optargs2352;
  _optargs2352.compress = "gzip";
  _optargs2352.bitmask = UINT64_C(0x1);
  int _ret2349;
  _ret2349 = guestfs_tar_in_opts_argv (g, _arg2350, _arg2351, &_optargs2352);
  if (_ret2349 == -1)
    return -1;
  const char *_arg2353 = "/tar_in_gz/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2353);
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

  const char *_features2355[] = { "xz", NULL };
  if (!guestfs_feature_available (g, (char **) _features2355)) {
    skipped ("test_tar_in_2", "group %s not available in daemon",
             _features2355[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for tar_in (2) */
  const char *_arg2357 = "/tar_in_xz";
  int _ret2356;
  _ret2356 = guestfs_mkdir (g, _arg2357);
  if (_ret2356 == -1)
    return -1;
  CLEANUP_FREE char *_arg2360 = substitute_srcdir ("$srcdir/../data/helloworld.tar.xz");
  const char *_arg2361 = "/tar_in_xz";
  struct guestfs_tar_in_opts_argv _optargs2362;
  _optargs2362.compress = "xz";
  _optargs2362.bitmask = UINT64_C(0x1);
  int _ret2359;
  _ret2359 = guestfs_tar_in_opts_argv (g, _arg2360, _arg2361, &_optargs2362);
  if (_ret2359 == -1)
    return -1;
  const char *_arg2363 = "/tar_in_xz/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2363);
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
  const char *_arg2365 = "crc";
  const char *_arg2366 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2365, _arg2366);
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
  const char *_arg2369 = "crc";
  const char *_arg2370 = "/notexists";
  CLEANUP_FREE char *_ret2368;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2368 = guestfs_checksum (g, _arg2369, _arg2370);
  guestfs_pop_error_handler (g);
  if (_ret2368 != NULL)
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
  const char *_arg2372 = "md5";
  const char *_arg2373 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2372, _arg2373);
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
  const char *_arg2375 = "sha1";
  const char *_arg2376 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2375, _arg2376);
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
  const char *_arg2378 = "sha224";
  const char *_arg2379 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2378, _arg2379);
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
  const char *_arg2381 = "sha256";
  const char *_arg2382 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2381, _arg2382);
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
  const char *_arg2384 = "sha384";
  const char *_arg2385 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2384, _arg2385);
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
  const char *_arg2387 = "sha512";
  const char *_arg2388 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2387, _arg2388);
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
  const char *_arg2390 = "sha512";
  const char *_arg2391 = "/abssymlink";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2390, _arg2391);
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
  const char *_arg2394 = "/download";
  int _ret2393;
  _ret2393 = guestfs_mkdir (g, _arg2394);
  if (_ret2393 == -1)
    return -1;
  CLEANUP_FREE char *_arg2397 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *_arg2398 = "/download/COPYING.LIB";
  int _ret2396;
  _ret2396 = guestfs_upload (g, _arg2397, _arg2398);
  if (_ret2396 == -1)
    return -1;
  const char *_arg2401 = "/download/COPYING.LIB";
  int _ret2400;
  _ret2400 = guestfs_download (g, _arg2401, "testdownload.tmp");
  if (_ret2400 == -1)
    return -1;
  CLEANUP_FREE char *_arg2405 = substitute_srcdir ("testdownload.tmp");
  const char *_arg2406 = "/download/upload";
  int _ret2404;
  _ret2404 = guestfs_upload (g, _arg2405, _arg2406);
  if (_ret2404 == -1)
    return -1;
  const char *_arg2408 = "md5";
  const char *_arg2409 = "/download/upload";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2408, _arg2409);
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
  const char *_arg2412 = "/upload";
  int _ret2411;
  _ret2411 = guestfs_mkdir (g, _arg2412);
  if (_ret2411 == -1)
    return -1;
  CLEANUP_FREE char *_arg2415 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *_arg2416 = "/upload/COPYING.LIB";
  int _ret2414;
  _ret2414 = guestfs_upload (g, _arg2415, _arg2416);
  if (_ret2414 == -1)
    return -1;
  const char *_arg2418 = "md5";
  const char *_arg2419 = "/upload/COPYING.LIB";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2418, _arg2419);
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
  const char *_arg2422 = "/dev/sda";
  int _ret2421;
  _ret2421 = guestfs_blockdev_rereadpt (g, _arg2422);
  if (_ret2421 == -1)
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
  const char *_arg2425 = "/dev/sda";
  int _ret2424;
  _ret2424 = guestfs_blockdev_flushbufs (g, _arg2425);
  if (_ret2424 == -1)
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
  const char *_arg2427 = "/dev/sda";
  int64_t ret;
  ret = guestfs_blockdev_getsize64 (g, _arg2427);
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
  const char *_arg2429 = "/dev/sda";
  int64_t ret;
  ret = guestfs_blockdev_getsz (g, _arg2429);
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
  const char *_arg2431 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getss (g, _arg2431);
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
  const char *_arg2434 = "/dev/sda";
  int _ret2433;
  _ret2433 = guestfs_blockdev_setro (g, _arg2434);
  if (_ret2433 == -1)
    return -1;
  const char *_arg2436 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, _arg2436);
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
  const char *_arg2439 = "/dev/sda";
  int _ret2438;
  _ret2438 = guestfs_blockdev_setrw (g, _arg2439);
  if (_ret2438 == -1)
    return -1;
  const char *_arg2441 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, _arg2441);
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
  const char *_arg2444 = "/dev/sda";
  int _ret2443;
  _ret2443 = guestfs_blockdev_setro (g, _arg2444);
  if (_ret2443 == -1)
    return -1;
  const char *_arg2446 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, _arg2446);
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
  const char *_arg2448 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg2448);
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
  const char *_arg2450 = "/";
  CLEANUP_FREE_STATVFS struct guestfs_statvfs *ret;
  ret = guestfs_statvfs (g, _arg2450);
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
  const char *_arg2452 = "/empty";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_lstat (g, _arg2452);
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
  const char *_arg2454 = "/empty";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg2454);
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
  const char *_arg2456 = "/command_lines";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2456);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2458 = substitute_srcdir ("test-command");
  const char *_arg2459 = "/command_lines/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2458, _arg2459);
  if (ret2 == -1)
    return -1;
  const char *_arg2462 = "/command_lines/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2462);
  if (ret1 == -1)
    return -1;
  const char *_arg2464_0 = "/command_lines/test-command";
  const char *_arg2464_1 = "1";
  const char *const _arg2464[] = {
    _arg2464_0,
    _arg2464_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2464);
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
  const char *_arg2466 = "/command_lines2";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2466);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2468 = substitute_srcdir ("test-command");
  const char *_arg2469 = "/command_lines2/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2468, _arg2469);
  if (ret2 == -1)
    return -1;
  const char *_arg2472 = "/command_lines2/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2472);
  if (ret1 == -1)
    return -1;
  const char *_arg2474_0 = "/command_lines2/test-command";
  const char *_arg2474_1 = "2";
  const char *const _arg2474[] = {
    _arg2474_0,
    _arg2474_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2474);
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
  const char *_arg2476 = "/command_lines3";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2476);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2478 = substitute_srcdir ("test-command");
  const char *_arg2479 = "/command_lines3/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2478, _arg2479);
  if (ret2 == -1)
    return -1;
  const char *_arg2482 = "/command_lines3/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2482);
  if (ret1 == -1)
    return -1;
  const char *_arg2484_0 = "/command_lines3/test-command";
  const char *_arg2484_1 = "3";
  const char *const _arg2484[] = {
    _arg2484_0,
    _arg2484_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2484);
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
  const char *_arg2486 = "/command_lines4";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2486);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2488 = substitute_srcdir ("test-command");
  const char *_arg2489 = "/command_lines4/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2488, _arg2489);
  if (ret2 == -1)
    return -1;
  const char *_arg2492 = "/command_lines4/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2492);
  if (ret1 == -1)
    return -1;
  const char *_arg2494_0 = "/command_lines4/test-command";
  const char *_arg2494_1 = "4";
  const char *const _arg2494[] = {
    _arg2494_0,
    _arg2494_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2494);
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
  const char *_arg2496 = "/command_lines5";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2496);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2498 = substitute_srcdir ("test-command");
  const char *_arg2499 = "/command_lines5/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2498, _arg2499);
  if (ret2 == -1)
    return -1;
  const char *_arg2502 = "/command_lines5/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2502);
  if (ret1 == -1)
    return -1;
  const char *_arg2504_0 = "/command_lines5/test-command";
  const char *_arg2504_1 = "5";
  const char *const _arg2504[] = {
    _arg2504_0,
    _arg2504_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2504);
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
  const char *_arg2506 = "/command_lines6";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2506);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2508 = substitute_srcdir ("test-command");
  const char *_arg2509 = "/command_lines6/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2508, _arg2509);
  if (ret2 == -1)
    return -1;
  const char *_arg2512 = "/command_lines6/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2512);
  if (ret1 == -1)
    return -1;
  const char *_arg2514_0 = "/command_lines6/test-command";
  const char *_arg2514_1 = "6";
  const char *const _arg2514[] = {
    _arg2514_0,
    _arg2514_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2514);
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
  const char *_arg2516 = "/command_lines7";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2516);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2518 = substitute_srcdir ("test-command");
  const char *_arg2519 = "/command_lines7/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2518, _arg2519);
  if (ret2 == -1)
    return -1;
  const char *_arg2522 = "/command_lines7/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2522);
  if (ret1 == -1)
    return -1;
  const char *_arg2524_0 = "/command_lines7/test-command";
  const char *_arg2524_1 = "7";
  const char *const _arg2524[] = {
    _arg2524_0,
    _arg2524_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2524);
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
  const char *_arg2526 = "/command_lines8";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2526);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2528 = substitute_srcdir ("test-command");
  const char *_arg2529 = "/command_lines8/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2528, _arg2529);
  if (ret2 == -1)
    return -1;
  const char *_arg2532 = "/command_lines8/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2532);
  if (ret1 == -1)
    return -1;
  const char *_arg2534_0 = "/command_lines8/test-command";
  const char *_arg2534_1 = "8";
  const char *const _arg2534[] = {
    _arg2534_0,
    _arg2534_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2534);
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
  const char *_arg2536 = "/command_lines9";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2536);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2538 = substitute_srcdir ("test-command");
  const char *_arg2539 = "/command_lines9/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2538, _arg2539);
  if (ret2 == -1)
    return -1;
  const char *_arg2542 = "/command_lines9/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2542);
  if (ret1 == -1)
    return -1;
  const char *_arg2544_0 = "/command_lines9/test-command";
  const char *_arg2544_1 = "9";
  const char *const _arg2544[] = {
    _arg2544_0,
    _arg2544_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2544);
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
  const char *_arg2546 = "/command_lines10";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2546);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2548 = substitute_srcdir ("test-command");
  const char *_arg2549 = "/command_lines10/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2548, _arg2549);
  if (ret2 == -1)
    return -1;
  const char *_arg2552 = "/command_lines10/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2552);
  if (ret1 == -1)
    return -1;
  const char *_arg2554_0 = "/command_lines10/test-command";
  const char *_arg2554_1 = "10";
  const char *const _arg2554[] = {
    _arg2554_0,
    _arg2554_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2554);
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
  const char *_arg2556 = "/command_lines11";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2556);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2558 = substitute_srcdir ("test-command");
  const char *_arg2559 = "/command_lines11/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2558, _arg2559);
  if (ret2 == -1)
    return -1;
  const char *_arg2562 = "/command_lines11/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2562);
  if (ret1 == -1)
    return -1;
  const char *_arg2564_0 = "/command_lines11/test-command";
  const char *_arg2564_1 = "11";
  const char *const _arg2564[] = {
    _arg2564_0,
    _arg2564_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2564);
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
  const char *_arg2567 = "/command";
  int _ret2566;
  _ret2566 = guestfs_mkdir (g, _arg2567);
  if (_ret2566 == -1)
    return -1;
  CLEANUP_FREE char *_arg2570 = substitute_srcdir ("test-command");
  const char *_arg2571 = "/command/test-command";
  int _ret2569;
  _ret2569 = guestfs_upload (g, _arg2570, _arg2571);
  if (_ret2569 == -1)
    return -1;
  const char *_arg2575 = "/command/test-command";
  int _ret2573;
  _ret2573 = guestfs_chmod (g, 493, _arg2575);
  if (_ret2573 == -1)
    return -1;
  const char *_arg2577_0 = "/command/test-command";
  const char *_arg2577_1 = "1";
  const char *const _arg2577[] = {
    _arg2577_0,
    _arg2577_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2577);
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
  const char *_arg2580 = "/command2";
  int _ret2579;
  _ret2579 = guestfs_mkdir (g, _arg2580);
  if (_ret2579 == -1)
    return -1;
  CLEANUP_FREE char *_arg2583 = substitute_srcdir ("test-command");
  const char *_arg2584 = "/command2/test-command";
  int _ret2582;
  _ret2582 = guestfs_upload (g, _arg2583, _arg2584);
  if (_ret2582 == -1)
    return -1;
  const char *_arg2588 = "/command2/test-command";
  int _ret2586;
  _ret2586 = guestfs_chmod (g, 493, _arg2588);
  if (_ret2586 == -1)
    return -1;
  const char *_arg2590_0 = "/command2/test-command";
  const char *_arg2590_1 = "2";
  const char *const _arg2590[] = {
    _arg2590_0,
    _arg2590_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2590);
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
  const char *_arg2593 = "/command3";
  int _ret2592;
  _ret2592 = guestfs_mkdir (g, _arg2593);
  if (_ret2592 == -1)
    return -1;
  CLEANUP_FREE char *_arg2596 = substitute_srcdir ("test-command");
  const char *_arg2597 = "/command3/test-command";
  int _ret2595;
  _ret2595 = guestfs_upload (g, _arg2596, _arg2597);
  if (_ret2595 == -1)
    return -1;
  const char *_arg2601 = "/command3/test-command";
  int _ret2599;
  _ret2599 = guestfs_chmod (g, 493, _arg2601);
  if (_ret2599 == -1)
    return -1;
  const char *_arg2603_0 = "/command3/test-command";
  const char *_arg2603_1 = "3";
  const char *const _arg2603[] = {
    _arg2603_0,
    _arg2603_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2603);
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
  const char *_arg2606 = "/command4";
  int _ret2605;
  _ret2605 = guestfs_mkdir (g, _arg2606);
  if (_ret2605 == -1)
    return -1;
  CLEANUP_FREE char *_arg2609 = substitute_srcdir ("test-command");
  const char *_arg2610 = "/command4/test-command";
  int _ret2608;
  _ret2608 = guestfs_upload (g, _arg2609, _arg2610);
  if (_ret2608 == -1)
    return -1;
  const char *_arg2614 = "/command4/test-command";
  int _ret2612;
  _ret2612 = guestfs_chmod (g, 493, _arg2614);
  if (_ret2612 == -1)
    return -1;
  const char *_arg2616_0 = "/command4/test-command";
  const char *_arg2616_1 = "4";
  const char *const _arg2616[] = {
    _arg2616_0,
    _arg2616_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2616);
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
  const char *_arg2619 = "/command5";
  int _ret2618;
  _ret2618 = guestfs_mkdir (g, _arg2619);
  if (_ret2618 == -1)
    return -1;
  CLEANUP_FREE char *_arg2622 = substitute_srcdir ("test-command");
  const char *_arg2623 = "/command5/test-command";
  int _ret2621;
  _ret2621 = guestfs_upload (g, _arg2622, _arg2623);
  if (_ret2621 == -1)
    return -1;
  const char *_arg2627 = "/command5/test-command";
  int _ret2625;
  _ret2625 = guestfs_chmod (g, 493, _arg2627);
  if (_ret2625 == -1)
    return -1;
  const char *_arg2629_0 = "/command5/test-command";
  const char *_arg2629_1 = "5";
  const char *const _arg2629[] = {
    _arg2629_0,
    _arg2629_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2629);
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
  const char *_arg2632 = "/command6";
  int _ret2631;
  _ret2631 = guestfs_mkdir (g, _arg2632);
  if (_ret2631 == -1)
    return -1;
  CLEANUP_FREE char *_arg2635 = substitute_srcdir ("test-command");
  const char *_arg2636 = "/command6/test-command";
  int _ret2634;
  _ret2634 = guestfs_upload (g, _arg2635, _arg2636);
  if (_ret2634 == -1)
    return -1;
  const char *_arg2640 = "/command6/test-command";
  int _ret2638;
  _ret2638 = guestfs_chmod (g, 493, _arg2640);
  if (_ret2638 == -1)
    return -1;
  const char *_arg2642_0 = "/command6/test-command";
  const char *_arg2642_1 = "6";
  const char *const _arg2642[] = {
    _arg2642_0,
    _arg2642_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2642);
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
  const char *_arg2645 = "/command7";
  int _ret2644;
  _ret2644 = guestfs_mkdir (g, _arg2645);
  if (_ret2644 == -1)
    return -1;
  CLEANUP_FREE char *_arg2648 = substitute_srcdir ("test-command");
  const char *_arg2649 = "/command7/test-command";
  int _ret2647;
  _ret2647 = guestfs_upload (g, _arg2648, _arg2649);
  if (_ret2647 == -1)
    return -1;
  const char *_arg2653 = "/command7/test-command";
  int _ret2651;
  _ret2651 = guestfs_chmod (g, 493, _arg2653);
  if (_ret2651 == -1)
    return -1;
  const char *_arg2655_0 = "/command7/test-command";
  const char *_arg2655_1 = "7";
  const char *const _arg2655[] = {
    _arg2655_0,
    _arg2655_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2655);
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
  const char *_arg2658 = "/command8";
  int _ret2657;
  _ret2657 = guestfs_mkdir (g, _arg2658);
  if (_ret2657 == -1)
    return -1;
  CLEANUP_FREE char *_arg2661 = substitute_srcdir ("test-command");
  const char *_arg2662 = "/command8/test-command";
  int _ret2660;
  _ret2660 = guestfs_upload (g, _arg2661, _arg2662);
  if (_ret2660 == -1)
    return -1;
  const char *_arg2666 = "/command8/test-command";
  int _ret2664;
  _ret2664 = guestfs_chmod (g, 493, _arg2666);
  if (_ret2664 == -1)
    return -1;
  const char *_arg2668_0 = "/command8/test-command";
  const char *_arg2668_1 = "8";
  const char *const _arg2668[] = {
    _arg2668_0,
    _arg2668_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2668);
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
  const char *_arg2671 = "/command9";
  int _ret2670;
  _ret2670 = guestfs_mkdir (g, _arg2671);
  if (_ret2670 == -1)
    return -1;
  CLEANUP_FREE char *_arg2674 = substitute_srcdir ("test-command");
  const char *_arg2675 = "/command9/test-command";
  int _ret2673;
  _ret2673 = guestfs_upload (g, _arg2674, _arg2675);
  if (_ret2673 == -1)
    return -1;
  const char *_arg2679 = "/command9/test-command";
  int _ret2677;
  _ret2677 = guestfs_chmod (g, 493, _arg2679);
  if (_ret2677 == -1)
    return -1;
  const char *_arg2681_0 = "/command9/test-command";
  const char *_arg2681_1 = "9";
  const char *const _arg2681[] = {
    _arg2681_0,
    _arg2681_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2681);
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
  const char *_arg2684 = "/command10";
  int _ret2683;
  _ret2683 = guestfs_mkdir (g, _arg2684);
  if (_ret2683 == -1)
    return -1;
  CLEANUP_FREE char *_arg2687 = substitute_srcdir ("test-command");
  const char *_arg2688 = "/command10/test-command";
  int _ret2686;
  _ret2686 = guestfs_upload (g, _arg2687, _arg2688);
  if (_ret2686 == -1)
    return -1;
  const char *_arg2692 = "/command10/test-command";
  int _ret2690;
  _ret2690 = guestfs_chmod (g, 493, _arg2692);
  if (_ret2690 == -1)
    return -1;
  const char *_arg2694_0 = "/command10/test-command";
  const char *_arg2694_1 = "10";
  const char *const _arg2694[] = {
    _arg2694_0,
    _arg2694_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2694);
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
  const char *_arg2697 = "/command11";
  int _ret2696;
  _ret2696 = guestfs_mkdir (g, _arg2697);
  if (_ret2696 == -1)
    return -1;
  CLEANUP_FREE char *_arg2700 = substitute_srcdir ("test-command");
  const char *_arg2701 = "/command11/test-command";
  int _ret2699;
  _ret2699 = guestfs_upload (g, _arg2700, _arg2701);
  if (_ret2699 == -1)
    return -1;
  const char *_arg2705 = "/command11/test-command";
  int _ret2703;
  _ret2703 = guestfs_chmod (g, 493, _arg2705);
  if (_ret2703 == -1)
    return -1;
  const char *_arg2707_0 = "/command11/test-command";
  const char *_arg2707_1 = "11";
  const char *const _arg2707[] = {
    _arg2707_0,
    _arg2707_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2707);
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
  const char *_arg2710 = "/command12";
  int _ret2709;
  _ret2709 = guestfs_mkdir (g, _arg2710);
  if (_ret2709 == -1)
    return -1;
  CLEANUP_FREE char *_arg2713 = substitute_srcdir ("test-command");
  const char *_arg2714 = "/command12/test-command";
  int _ret2712;
  _ret2712 = guestfs_upload (g, _arg2713, _arg2714);
  if (_ret2712 == -1)
    return -1;
  const char *_arg2718 = "/command12/test-command";
  int _ret2716;
  _ret2716 = guestfs_chmod (g, 493, _arg2718);
  if (_ret2716 == -1)
    return -1;
  const char *_arg2721_0 = "/command12/test-command";
  const char *const _arg2721[] = {
    _arg2721_0,
    NULL
  };
  CLEANUP_FREE char *_ret2720;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2720 = guestfs_command (g, (char **) _arg2721);
  guestfs_pop_error_handler (g);
  if (_ret2720 != NULL)
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
  const char *_arg2724 = "/pwd";
  int _ret2723;
  _ret2723 = guestfs_mkdir (g, _arg2724);
  if (_ret2723 == -1)
    return -1;
  CLEANUP_FREE char *_arg2727 = substitute_srcdir ("test-pwd");
  const char *_arg2728 = "/pwd/test-pwd";
  int _ret2726;
  _ret2726 = guestfs_upload (g, _arg2727, _arg2728);
  if (_ret2726 == -1)
    return -1;
  const char *_arg2732 = "/pwd/test-pwd";
  int _ret2730;
  _ret2730 = guestfs_chmod (g, 493, _arg2732);
  if (_ret2730 == -1)
    return -1;
  const char *_arg2734_0 = "/pwd/test-pwd";
  const char *const _arg2734[] = {
    _arg2734_0,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2734);
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
  const char *_arg2736 = "/empty";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg2736);
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
  const char *_arg2738 = "/known-1";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg2738);
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
  const char *_arg2741 = "/notexists";
  CLEANUP_FREE char *_ret2740;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2740 = guestfs_file (g, _arg2741);
  guestfs_pop_error_handler (g);
  if (_ret2740 != NULL)
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
  const char *_arg2743 = "/abssymlink";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg2743);
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
  const char *_arg2745 = "/directory";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg2745);
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
  const char *_arg2749 = "/dev/sda";
  const char *_arg2750 = "mbr";
  int ret14;
  ret14 = guestfs_part_init (g, _arg2749, _arg2750);
  if (ret14 == -1)
    return -1;
  const char *_arg2752 = "/dev/sda";
  const char *_arg2753 = "p";
  int ret13;
  ret13 = guestfs_part_add (g, _arg2752, _arg2753, 64, 204799);
  if (ret13 == -1)
    return -1;
  const char *_arg2757 = "/dev/sda";
  const char *_arg2758 = "p";
  int ret12;
  ret12 = guestfs_part_add (g, _arg2757, _arg2758, 204800, 409599);
  if (ret12 == -1)
    return -1;
  const char *_arg2762 = "/dev/sda";
  const char *_arg2763 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, _arg2762, _arg2763, 409600, -64);
  if (ret11 == -1)
    return -1;
  const char *_arg2767 = "ext2";
  const char *_arg2768 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs2769;
  _optargs2769.bitmask = UINT64_C(0x0);
  int ret10;
  ret10 = guestfs_mkfs_opts_argv (g, _arg2767, _arg2768, &_optargs2769);
  if (ret10 == -1)
    return -1;
  const char *_arg2770 = "ext2";
  const char *_arg2771 = "/dev/sda2";
  struct guestfs_mkfs_opts_argv _optargs2772;
  _optargs2772.bitmask = UINT64_C(0x0);
  int ret9;
  ret9 = guestfs_mkfs_opts_argv (g, _arg2770, _arg2771, &_optargs2772);
  if (ret9 == -1)
    return -1;
  const char *_arg2773 = "ext2";
  const char *_arg2774 = "/dev/sda3";
  struct guestfs_mkfs_opts_argv _optargs2775;
  _optargs2775.bitmask = UINT64_C(0x0);
  int ret8;
  ret8 = guestfs_mkfs_opts_argv (g, _arg2773, _arg2774, &_optargs2775);
  if (ret8 == -1)
    return -1;
  const char *_arg2776 = "/dev/sda1";
  const char *_arg2777 = "/";
  int ret7;
  ret7 = guestfs_mount (g, _arg2776, _arg2777);
  if (ret7 == -1)
    return -1;
  const char *_arg2779 = "/mp1";
  int ret6;
  ret6 = guestfs_mkdir (g, _arg2779);
  if (ret6 == -1)
    return -1;
  const char *_arg2781 = "/dev/sda2";
  const char *_arg2782 = "/mp1";
  int ret5;
  ret5 = guestfs_mount (g, _arg2781, _arg2782);
  if (ret5 == -1)
    return -1;
  const char *_arg2784 = "/mp1/mp2";
  int ret4;
  ret4 = guestfs_mkdir (g, _arg2784);
  if (ret4 == -1)
    return -1;
  const char *_arg2786 = "/dev/sda3";
  const char *_arg2787 = "/mp1/mp2";
  int ret3;
  ret3 = guestfs_mount (g, _arg2786, _arg2787);
  if (ret3 == -1)
    return -1;
  const char *_arg2789 = "/mp1/mp2/mp3";
  int ret2;
  ret2 = guestfs_mkdir (g, _arg2789);
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
  const char *_arg2794 = "/dev/sda";
  const char *_arg2795 = "mbr";
  int ret3;
  ret3 = guestfs_part_disk (g, _arg2794, _arg2795);
  if (ret3 == -1)
    return -1;
  const char *_arg2797 = "ext2";
  const char *_arg2798 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs2799;
  _optargs2799.bitmask = UINT64_C(0x0);
  int ret2;
  ret2 = guestfs_mkfs_opts_argv (g, _arg2797, _arg2798, &_optargs2799);
  if (ret2 == -1)
    return -1;
  const char *_arg2800 = "/dev/sda1";
  const char *_arg2801 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg2800, _arg2801);
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
  const char *_arg2804 = "/dev/sda";
  const char *_arg2805 = "mbr";
  int ret4;
  ret4 = guestfs_part_disk (g, _arg2804, _arg2805);
  if (ret4 == -1)
    return -1;
  const char *_arg2807 = "ext2";
  const char *_arg2808 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs2809;
  _optargs2809.bitmask = UINT64_C(0x0);
  int ret3;
  ret3 = guestfs_mkfs_opts_argv (g, _arg2807, _arg2808, &_optargs2809);
  if (ret3 == -1)
    return -1;
  const char *_arg2810 = "/dev/sda1";
  const char *_arg2811 = "/";
  int ret2;
  ret2 = guestfs_mount (g, _arg2810, _arg2811);
  if (ret2 == -1)
    return -1;
  const char *_arg2813 = "/";
  struct guestfs_umount_opts_argv _optargs2814;
  _optargs2814.force = 0;
  _optargs2814.lazyunmount = 0;
  _optargs2814.bitmask = UINT64_C(0x3);
  int ret1;
  ret1 = guestfs_umount_opts_argv (g, _arg2813, &_optargs2814);
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
  const char *_arg2817 = "/write_file";
  const char *_arg2818 = "abc";
  int _ret2816;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2816 = guestfs_write_file (g, _arg2817, _arg2818, 10000);
  guestfs_pop_error_handler (g);
  if (_ret2816 != -1)
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

  const char *_features2821[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2821)) {
    skipped ("test_lvcreate_0", "group %s not available in daemon",
             _features2821[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvcreate (0) */
  const char *_arg2822 = "/dev/sda";
  const char *_arg2823 = "mbr";
  int ret14;
  ret14 = guestfs_part_init (g, _arg2822, _arg2823);
  if (ret14 == -1)
    return -1;
  const char *_arg2825 = "/dev/sda";
  const char *_arg2826 = "p";
  int ret13;
  ret13 = guestfs_part_add (g, _arg2825, _arg2826, 64, 204799);
  if (ret13 == -1)
    return -1;
  const char *_arg2830 = "/dev/sda";
  const char *_arg2831 = "p";
  int ret12;
  ret12 = guestfs_part_add (g, _arg2830, _arg2831, 204800, 409599);
  if (ret12 == -1)
    return -1;
  const char *_arg2835 = "/dev/sda";
  const char *_arg2836 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, _arg2835, _arg2836, 409600, -64);
  if (ret11 == -1)
    return -1;
  const char *_arg2840 = "/dev/sda1";
  int ret10;
  ret10 = guestfs_pvcreate (g, _arg2840);
  if (ret10 == -1)
    return -1;
  const char *_arg2842 = "/dev/sda2";
  int ret9;
  ret9 = guestfs_pvcreate (g, _arg2842);
  if (ret9 == -1)
    return -1;
  const char *_arg2844 = "/dev/sda3";
  int ret8;
  ret8 = guestfs_pvcreate (g, _arg2844);
  if (ret8 == -1)
    return -1;
  const char *_arg2846 = "VG1";
  const char *_arg2847_0 = "/dev/sda1";
  const char *_arg2847_1 = "/dev/sda2";
  const char *const _arg2847[] = {
    _arg2847_0,
    _arg2847_1,
    NULL
  };
  int ret7;
  ret7 = guestfs_vgcreate (g, _arg2846, (char **) _arg2847);
  if (ret7 == -1)
    return -1;
  const char *_arg2849 = "VG2";
  const char *_arg2850_0 = "/dev/sda3";
  const char *const _arg2850[] = {
    _arg2850_0,
    NULL
  };
  int ret6;
  ret6 = guestfs_vgcreate (g, _arg2849, (char **) _arg2850);
  if (ret6 == -1)
    return -1;
  const char *_arg2852 = "LV1";
  const char *_arg2853 = "VG1";
  int ret5;
  ret5 = guestfs_lvcreate (g, _arg2852, _arg2853, 50);
  if (ret5 == -1)
    return -1;
  const char *_arg2856 = "LV2";
  const char *_arg2857 = "VG1";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg2856, _arg2857, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg2860 = "LV3";
  const char *_arg2861 = "VG2";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2860, _arg2861, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2864 = "LV4";
  const char *_arg2865 = "VG2";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2864, _arg2865, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2868 = "LV5";
  const char *_arg2869 = "VG2";
  int ret1;
  ret1 = guestfs_lvcreate (g, _arg2868, _arg2869, 50);
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

  const char *_features2873[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2873)) {
    skipped ("test_vgcreate_0", "group %s not available in daemon",
             _features2873[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for vgcreate (0) */
  const char *_arg2874 = "/dev/sda";
  const char *_arg2875 = "mbr";
  int ret9;
  ret9 = guestfs_part_init (g, _arg2874, _arg2875);
  if (ret9 == -1)
    return -1;
  const char *_arg2877 = "/dev/sda";
  const char *_arg2878 = "p";
  int ret8;
  ret8 = guestfs_part_add (g, _arg2877, _arg2878, 64, 204799);
  if (ret8 == -1)
    return -1;
  const char *_arg2882 = "/dev/sda";
  const char *_arg2883 = "p";
  int ret7;
  ret7 = guestfs_part_add (g, _arg2882, _arg2883, 204800, 409599);
  if (ret7 == -1)
    return -1;
  const char *_arg2887 = "/dev/sda";
  const char *_arg2888 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg2887, _arg2888, 409600, -64);
  if (ret6 == -1)
    return -1;
  const char *_arg2892 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2892);
  if (ret5 == -1)
    return -1;
  const char *_arg2894 = "/dev/sda2";
  int ret4;
  ret4 = guestfs_pvcreate (g, _arg2894);
  if (ret4 == -1)
    return -1;
  const char *_arg2896 = "/dev/sda3";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg2896);
  if (ret3 == -1)
    return -1;
  const char *_arg2898 = "VG1";
  const char *_arg2899_0 = "/dev/sda1";
  const char *_arg2899_1 = "/dev/sda2";
  const char *const _arg2899[] = {
    _arg2899_0,
    _arg2899_1,
    NULL
  };
  int ret2;
  ret2 = guestfs_vgcreate (g, _arg2898, (char **) _arg2899);
  if (ret2 == -1)
    return -1;
  const char *_arg2901 = "VG2";
  const char *_arg2902_0 = "/dev/sda3";
  const char *const _arg2902[] = {
    _arg2902_0,
    NULL
  };
  int ret1;
  ret1 = guestfs_vgcreate (g, _arg2901, (char **) _arg2902);
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

  const char *_features2905[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2905)) {
    skipped ("test_pvcreate_0", "group %s not available in daemon",
             _features2905[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvcreate (0) */
  const char *_arg2906 = "/dev/sda";
  const char *_arg2907 = "mbr";
  int ret7;
  ret7 = guestfs_part_init (g, _arg2906, _arg2907);
  if (ret7 == -1)
    return -1;
  const char *_arg2909 = "/dev/sda";
  const char *_arg2910 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg2909, _arg2910, 64, 204799);
  if (ret6 == -1)
    return -1;
  const char *_arg2914 = "/dev/sda";
  const char *_arg2915 = "p";
  int ret5;
  ret5 = guestfs_part_add (g, _arg2914, _arg2915, 204800, 409599);
  if (ret5 == -1)
    return -1;
  const char *_arg2919 = "/dev/sda";
  const char *_arg2920 = "p";
  int ret4;
  ret4 = guestfs_part_add (g, _arg2919, _arg2920, 409600, -64);
  if (ret4 == -1)
    return -1;
  const char *_arg2924 = "/dev/sda1";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg2924);
  if (ret3 == -1)
    return -1;
  const char *_arg2926 = "/dev/sda2";
  int ret2;
  ret2 = guestfs_pvcreate (g, _arg2926);
  if (ret2 == -1)
    return -1;
  const char *_arg2928 = "/dev/sda3";
  int ret1;
  ret1 = guestfs_pvcreate (g, _arg2928);
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
  const char *_arg2931 = "/known-3";
  struct guestfs_is_dir_opts_argv _optargs2932;
  _optargs2932.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2931, &_optargs2932);
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
  const char *_arg2933 = "/directory";
  struct guestfs_is_dir_opts_argv _optargs2934;
  _optargs2934.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2933, &_optargs2934);
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
  const char *_arg2935 = "/known-1";
  struct guestfs_is_file_opts_argv _optargs2936;
  _optargs2936.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, _arg2935, &_optargs2936);
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
  const char *_arg2937 = "/directory";
  struct guestfs_is_file_opts_argv _optargs2938;
  _optargs2938.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, _arg2937, &_optargs2938);
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
test_is_file_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "is_file") == NULL;
  str = getenv ("SKIP_TEST_IS_FILE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_IS_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_is_file_2 (guestfs_h *g)
{
  if (test_is_file_2_skip ()) {
    skipped ("test_is_file_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultTrue for is_file (2) */
  const char *_arg2939 = "/abssymlink";
  struct guestfs_is_file_opts_argv _optargs2940;
  _optargs2940.followsymlinks = 1;
  _optargs2940.bitmask = UINT64_C(0x1);
  int ret;
  ret = guestfs_is_file_opts_argv (g, _arg2939, &_optargs2940);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_file_2", "is_file");
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
  const char *_arg2941 = "/empty";
  int ret;
  ret = guestfs_exists (g, _arg2941);
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
  const char *_arg2943 = "/directory";
  int ret;
  ret = guestfs_exists (g, _arg2943);
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
  const char *_arg2946 = "/mkdir_p/foo/bar";
  int _ret2945;
  _ret2945 = guestfs_mkdir_p (g, _arg2946);
  if (_ret2945 == -1)
    return -1;
  const char *_arg2948 = "/mkdir_p/foo/bar";
  struct guestfs_is_dir_opts_argv _optargs2949;
  _optargs2949.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2948, &_optargs2949);
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
  const char *_arg2951 = "/mkdir_p2/foo/bar";
  int _ret2950;
  _ret2950 = guestfs_mkdir_p (g, _arg2951);
  if (_ret2950 == -1)
    return -1;
  const char *_arg2953 = "/mkdir_p2/foo";
  struct guestfs_is_dir_opts_argv _optargs2954;
  _optargs2954.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2953, &_optargs2954);
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
  const char *_arg2956 = "/mkdir_p3/foo/bar";
  int _ret2955;
  _ret2955 = guestfs_mkdir_p (g, _arg2956);
  if (_ret2955 == -1)
    return -1;
  const char *_arg2958 = "/mkdir_p3";
  struct guestfs_is_dir_opts_argv _optargs2959;
  _optargs2959.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2958, &_optargs2959);
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
  const char *_arg2961 = "/mkdir_p4";
  int _ret2960;
  _ret2960 = guestfs_mkdir (g, _arg2961);
  if (_ret2960 == -1)
    return -1;
  const char *_arg2964 = "/mkdir_p4";
  int _ret2963;
  _ret2963 = guestfs_mkdir_p (g, _arg2964);
  if (_ret2963 == -1)
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
  const char *_arg2967 = "/mkdir_p5";
  int _ret2966;
  _ret2966 = guestfs_touch (g, _arg2967);
  if (_ret2966 == -1)
    return -1;
  const char *_arg2970 = "/mkdir_p5";
  int _ret2969;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2969 = guestfs_mkdir_p (g, _arg2970);
  guestfs_pop_error_handler (g);
  if (_ret2969 != -1)
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
  const char *_arg2973 = "/mkdir";
  int _ret2972;
  _ret2972 = guestfs_mkdir (g, _arg2973);
  if (_ret2972 == -1)
    return -1;
  const char *_arg2975 = "/mkdir";
  struct guestfs_is_dir_opts_argv _optargs2976;
  _optargs2976.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2975, &_optargs2976);
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
  const char *_arg2978 = "/mkdir2/foo/bar";
  int _ret2977;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2977 = guestfs_mkdir (g, _arg2978);
  guestfs_pop_error_handler (g);
  if (_ret2977 != -1)
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
  const char *_arg2981 = "/rm_rf";
  int _ret2980;
  _ret2980 = guestfs_mkdir (g, _arg2981);
  if (_ret2980 == -1)
    return -1;
  const char *_arg2984 = "/rm_rf/foo";
  int _ret2983;
  _ret2983 = guestfs_mkdir (g, _arg2984);
  if (_ret2983 == -1)
    return -1;
  const char *_arg2987 = "/rm_rf/foo/bar";
  int _ret2986;
  _ret2986 = guestfs_touch (g, _arg2987);
  if (_ret2986 == -1)
    return -1;
  const char *_arg2990 = "/rm_rf";
  int _ret2989;
  _ret2989 = guestfs_rm_rf (g, _arg2990);
  if (_ret2989 == -1)
    return -1;
  const char *_arg2992 = "/rm_rf";
  int ret;
  ret = guestfs_exists (g, _arg2992);
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
  const char *_arg2995 = "/rmdir";
  int _ret2994;
  _ret2994 = guestfs_mkdir (g, _arg2995);
  if (_ret2994 == -1)
    return -1;
  const char *_arg2998 = "/rmdir";
  int _ret2997;
  _ret2997 = guestfs_rmdir (g, _arg2998);
  if (_ret2997 == -1)
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
  const char *_arg3001 = "/rmdir2";
  int _ret3000;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret3000 = guestfs_rmdir (g, _arg3001);
  guestfs_pop_error_handler (g);
  if (_ret3000 != -1)
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
  const char *_arg3004 = "/rmdir3";
  int _ret3003;
  _ret3003 = guestfs_mkdir (g, _arg3004);
  if (_ret3003 == -1)
    return -1;
  const char *_arg3007 = "/rmdir3/new";
  int _ret3006;
  _ret3006 = guestfs_touch (g, _arg3007);
  if (_ret3006 == -1)
    return -1;
  const char *_arg3010 = "/rmdir3/new";
  int _ret3009;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret3009 = guestfs_rmdir (g, _arg3010);
  guestfs_pop_error_handler (g);
  if (_ret3009 != -1)
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
  const char *_arg3013 = "/rm";
  int _ret3012;
  _ret3012 = guestfs_mkdir (g, _arg3013);
  if (_ret3012 == -1)
    return -1;
  const char *_arg3016 = "/rm/new";
  int _ret3015;
  _ret3015 = guestfs_touch (g, _arg3016);
  if (_ret3015 == -1)
    return -1;
  const char *_arg3019 = "/rm/new";
  int _ret3018;
  _ret3018 = guestfs_rm (g, _arg3019);
  if (_ret3018 == -1)
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
  const char *_arg3022 = "/nosuchfile";
  int _ret3021;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret3021 = guestfs_rm (g, _arg3022);
  guestfs_pop_error_handler (g);
  if (_ret3021 != -1)
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
  const char *_arg3025 = "/rm2";
  int _ret3024;
  _ret3024 = guestfs_mkdir (g, _arg3025);
  if (_ret3024 == -1)
    return -1;
  const char *_arg3028 = "/rm2";
  int _ret3027;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret3027 = guestfs_rm (g, _arg3028);
  guestfs_pop_error_handler (g);
  if (_ret3027 != -1)
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

  const char *_features3030[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3030)) {
    skipped ("test_lvs_0", "group %s not available in daemon",
             _features3030[0]);
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

  const char *_features3032[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3032)) {
    skipped ("test_lvs_1", "group %s not available in daemon",
             _features3032[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvs (1) */
  const char *_arg3033 = "/dev/sda";
  const char *_arg3034 = "mbr";
  int ret12;
  ret12 = guestfs_part_init (g, _arg3033, _arg3034);
  if (ret12 == -1)
    return -1;
  const char *_arg3036 = "/dev/sda";
  const char *_arg3037 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, _arg3036, _arg3037, 64, 204799);
  if (ret11 == -1)
    return -1;
  const char *_arg3041 = "/dev/sda";
  const char *_arg3042 = "p";
  int ret10;
  ret10 = guestfs_part_add (g, _arg3041, _arg3042, 204800, 409599);
  if (ret10 == -1)
    return -1;
  const char *_arg3046 = "/dev/sda";
  const char *_arg3047 = "p";
  int ret9;
  ret9 = guestfs_part_add (g, _arg3046, _arg3047, 409600, -64);
  if (ret9 == -1)
    return -1;
  const char *_arg3051 = "/dev/sda1";
  int ret8;
  ret8 = guestfs_pvcreate (g, _arg3051);
  if (ret8 == -1)
    return -1;
  const char *_arg3053 = "/dev/sda2";
  int ret7;
  ret7 = guestfs_pvcreate (g, _arg3053);
  if (ret7 == -1)
    return -1;
  const char *_arg3055 = "/dev/sda3";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg3055);
  if (ret6 == -1)
    return -1;
  const char *_arg3057 = "VG1";
  const char *_arg3058_0 = "/dev/sda1";
  const char *_arg3058_1 = "/dev/sda2";
  const char *const _arg3058[] = {
    _arg3058_0,
    _arg3058_1,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg3057, (char **) _arg3058);
  if (ret5 == -1)
    return -1;
  const char *_arg3060 = "VG2";
  const char *_arg3061_0 = "/dev/sda3";
  const char *const _arg3061[] = {
    _arg3061_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg3060, (char **) _arg3061);
  if (ret4 == -1)
    return -1;
  const char *_arg3063 = "LV1";
  const char *_arg3064 = "VG1";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg3063, _arg3064, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg3067 = "LV2";
  const char *_arg3068 = "VG1";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg3067, _arg3068, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg3071 = "LV3";
  const char *_arg3072 = "VG2";
  int ret1;
  ret1 = guestfs_lvcreate (g, _arg3071, _arg3072, 50);
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

  const char *_features3076[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3076)) {
    skipped ("test_vgs_0", "group %s not available in daemon",
             _features3076[0]);
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

  const char *_features3078[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3078)) {
    skipped ("test_vgs_1", "group %s not available in daemon",
             _features3078[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for vgs (1) */
  const char *_arg3079 = "/dev/sda";
  const char *_arg3080 = "mbr";
  int ret9;
  ret9 = guestfs_part_init (g, _arg3079, _arg3080);
  if (ret9 == -1)
    return -1;
  const char *_arg3082 = "/dev/sda";
  const char *_arg3083 = "p";
  int ret8;
  ret8 = guestfs_part_add (g, _arg3082, _arg3083, 64, 204799);
  if (ret8 == -1)
    return -1;
  const char *_arg3087 = "/dev/sda";
  const char *_arg3088 = "p";
  int ret7;
  ret7 = guestfs_part_add (g, _arg3087, _arg3088, 204800, 409599);
  if (ret7 == -1)
    return -1;
  const char *_arg3092 = "/dev/sda";
  const char *_arg3093 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg3092, _arg3093, 409600, -64);
  if (ret6 == -1)
    return -1;
  const char *_arg3097 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg3097);
  if (ret5 == -1)
    return -1;
  const char *_arg3099 = "/dev/sda2";
  int ret4;
  ret4 = guestfs_pvcreate (g, _arg3099);
  if (ret4 == -1)
    return -1;
  const char *_arg3101 = "/dev/sda3";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg3101);
  if (ret3 == -1)
    return -1;
  const char *_arg3103 = "VG1";
  const char *_arg3104_0 = "/dev/sda1";
  const char *_arg3104_1 = "/dev/sda2";
  const char *const _arg3104[] = {
    _arg3104_0,
    _arg3104_1,
    NULL
  };
  int ret2;
  ret2 = guestfs_vgcreate (g, _arg3103, (char **) _arg3104);
  if (ret2 == -1)
    return -1;
  const char *_arg3106 = "VG2";
  const char *_arg3107_0 = "/dev/sda3";
  const char *const _arg3107[] = {
    _arg3107_0,
    NULL
  };
  int ret1;
  ret1 = guestfs_vgcreate (g, _arg3106, (char **) _arg3107);
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

  const char *_features3110[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3110)) {
    skipped ("test_pvs_0", "group %s not available in daemon",
             _features3110[0]);
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

  const char *_features3112[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3112)) {
    skipped ("test_pvs_1", "group %s not available in daemon",
             _features3112[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvs (1) */
  const char *_arg3113 = "/dev/sda";
  const char *_arg3114 = "mbr";
  int ret7;
  ret7 = guestfs_part_init (g, _arg3113, _arg3114);
  if (ret7 == -1)
    return -1;
  const char *_arg3116 = "/dev/sda";
  const char *_arg3117 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg3116, _arg3117, 64, 204799);
  if (ret6 == -1)
    return -1;
  const char *_arg3121 = "/dev/sda";
  const char *_arg3122 = "p";
  int ret5;
  ret5 = guestfs_part_add (g, _arg3121, _arg3122, 204800, 409599);
  if (ret5 == -1)
    return -1;
  const char *_arg3126 = "/dev/sda";
  const char *_arg3127 = "p";
  int ret4;
  ret4 = guestfs_part_add (g, _arg3126, _arg3127, 409600, -64);
  if (ret4 == -1)
    return -1;
  const char *_arg3131 = "/dev/sda1";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg3131);
  if (ret3 == -1)
    return -1;
  const char *_arg3133 = "/dev/sda2";
  int ret2;
  ret2 = guestfs_pvcreate (g, _arg3133);
  if (ret2 == -1)
    return -1;
  const char *_arg3135 = "/dev/sda3";
  int ret1;
  ret1 = guestfs_pvcreate (g, _arg3135);
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
  const char *_arg3139 = "/dev/sda";
  const char *_arg3140 = "mbr";
  int ret4;
  ret4 = guestfs_part_init (g, _arg3139, _arg3140);
  if (ret4 == -1)
    return -1;
  const char *_arg3142 = "/dev/sda";
  const char *_arg3143 = "p";
  int ret3;
  ret3 = guestfs_part_add (g, _arg3142, _arg3143, 64, 204799);
  if (ret3 == -1)
    return -1;
  const char *_arg3147 = "/dev/sda";
  const char *_arg3148 = "p";
  int ret2;
  ret2 = guestfs_part_add (g, _arg3147, _arg3148, 204800, 409599);
  if (ret2 == -1)
    return -1;
  const char *_arg3152 = "/dev/sda";
  const char *_arg3153 = "p";
  int ret1;
  ret1 = guestfs_part_add (g, _arg3152, _arg3153, 409600, -64);
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
  const char *_arg3160 = "/touch";
  int _ret3159;
  _ret3159 = guestfs_touch (g, _arg3160);
  if (_ret3159 == -1)
    return -1;
  const char *_arg3162 = "/touch";
  int ret;
  ret = guestfs_exists (g, _arg3162);
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
  int _ret3164;
  _ret3164 = guestfs_sync (g);
  if (_ret3164 == -1)
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
  const char *_arg3167 = "/dev/sda";
  const char *_arg3168 = "mbr";
  int _ret3166;
  _ret3166 = guestfs_part_disk (g, _arg3167, _arg3168);
  if (_ret3166 == -1)
    return -1;
  const char *_arg3171 = "ext2";
  const char *_arg3172 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs3173;
  _optargs3173.bitmask = UINT64_C(0x0);
  int _ret3170;
  _ret3170 = guestfs_mkfs_opts_argv (g, _arg3171, _arg3172, &_optargs3173);
  if (_ret3170 == -1)
    return -1;
  const char *_arg3175 = "/dev/sda1";
  const char *_arg3176 = "/";
  int _ret3174;
  _ret3174 = guestfs_mount (g, _arg3175, _arg3176);
  if (_ret3174 == -1)
    return -1;
  const char *_arg3179 = "/new";
  const char *_arg3180 = "new file contents";
  size_t _arg3180_size = 17;
  int _ret3178;
  _ret3178 = guestfs_write (g, _arg3179, _arg3180, _arg3180_size);
  if (_ret3178 == -1)
    return -1;
  const char *_arg3182 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3182);
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
  const char *_ret3184;
  _ret3184 = guestfs_get_program (g);
  if (_ret3184 == NULL)
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
  const char *_arg3186 = guestfs_get_private (g, "test1");
  int ret;
  ret = guestfs_disk_has_backing_file (g, _arg3186);
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
  const char *_arg3188 = guestfs_get_private (g, "test2");
  int ret;
  ret = guestfs_disk_has_backing_file (g, _arg3188);
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
  const char *_arg3190 = guestfs_get_private (g, "test3");
  int ret;
  ret = guestfs_disk_has_backing_file (g, _arg3190);
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
  const char *_arg3192 = guestfs_get_private (g, "test1");
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, _arg3192);
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
  const char *_arg3194 = guestfs_get_private (g, "test2");
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, _arg3194);
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
  const char *_arg3196 = guestfs_get_private (g, "test3");
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, _arg3196);
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
  const char *_arg3198 = guestfs_get_private (g, "test1");
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, _arg3198);
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
  const char *_arg3200 = guestfs_get_private (g, "test2");
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, _arg3200);
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
  const char *_arg3202 = guestfs_get_private (g, "test3");
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, _arg3202);
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
  const char *_arg3204 = "/ls";
  int ret4;
  ret4 = guestfs_mkdir (g, _arg3204);
  if (ret4 == -1)
    return -1;
  const char *_arg3206 = "/ls/new";
  int ret3;
  ret3 = guestfs_touch (g, _arg3206);
  if (ret3 == -1)
    return -1;
  const char *_arg3208 = "/ls/newer";
  int ret2;
  ret2 = guestfs_touch (g, _arg3208);
  if (ret2 == -1)
    return -1;
  const char *_arg3210 = "/ls/newest";
  int ret1;
  ret1 = guestfs_touch (g, _arg3210);
  if (ret1 == -1)
    return -1;
  const char *_arg3212 = "/ls";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_ls (g, _arg3212);
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
  const char *_arg3215 = "/write_append";
  const char *_arg3216 = "line1\n";
  size_t _arg3216_size = 6;
  int _ret3214;
  _ret3214 = guestfs_write (g, _arg3215, _arg3216, _arg3216_size);
  if (_ret3214 == -1)
    return -1;
  const char *_arg3219 = "/write_append";
  const char *_arg3220 = "line2\n";
  size_t _arg3220_size = 6;
  int _ret3218;
  _ret3218 = guestfs_write_append (g, _arg3219, _arg3220, _arg3220_size);
  if (_ret3218 == -1)
    return -1;
  const char *_arg3223 = "/write_append";
  const char *_arg3224 = "line3a";
  size_t _arg3224_size = 6;
  int _ret3222;
  _ret3222 = guestfs_write_append (g, _arg3223, _arg3224, _arg3224_size);
  if (_ret3222 == -1)
    return -1;
  const char *_arg3227 = "/write_append";
  const char *_arg3228 = "line3b\n";
  size_t _arg3228_size = 7;
  int _ret3226;
  _ret3226 = guestfs_write_append (g, _arg3227, _arg3228, _arg3228_size);
  if (_ret3226 == -1)
    return -1;
  const char *_arg3230 = "/write_append";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3230);
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
  const char *_arg3233 = "/write";
  const char *_arg3234 = "new file contents";
  size_t _arg3234_size = 17;
  int _ret3232;
  _ret3232 = guestfs_write (g, _arg3233, _arg3234, _arg3234_size);
  if (_ret3232 == -1)
    return -1;
  const char *_arg3236 = "/write";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3236);
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
  const char *_arg3239 = "/write2";
  const char *_arg3240 = "\nnew file contents\n";
  size_t _arg3240_size = 19;
  int _ret3238;
  _ret3238 = guestfs_write (g, _arg3239, _arg3240, _arg3240_size);
  if (_ret3238 == -1)
    return -1;
  const char *_arg3242 = "/write2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3242);
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
  const char *_arg3245 = "/write3";
  const char *_arg3246 = "\n\n";
  size_t _arg3246_size = 2;
  int _ret3244;
  _ret3244 = guestfs_write (g, _arg3245, _arg3246, _arg3246_size);
  if (_ret3244 == -1)
    return -1;
  const char *_arg3248 = "/write3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3248);
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
  const char *_arg3251 = "/write4";
  const char *_arg3252 = "";
  size_t _arg3252_size = 0;
  int _ret3250;
  _ret3250 = guestfs_write (g, _arg3251, _arg3252, _arg3252_size);
  if (_ret3250 == -1)
    return -1;
  const char *_arg3254 = "/write4";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3254);
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
  const char *_arg3257 = "/write5";
  const char *_arg3258 = "\n\n\n";
  size_t _arg3258_size = 3;
  int _ret3256;
  _ret3256 = guestfs_write (g, _arg3257, _arg3258, _arg3258_size);
  if (_ret3256 == -1)
    return -1;
  const char *_arg3260 = "/write5";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3260);
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
  const char *_arg3263 = "/write6";
  const char *_arg3264 = "\n";
  size_t _arg3264_size = 1;
  int _ret3262;
  _ret3262 = guestfs_write (g, _arg3263, _arg3264, _arg3264_size);
  if (_ret3262 == -1)
    return -1;
  const char *_arg3266 = "/write6";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3266);
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
  const char *_arg3268 = "/known-4";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3268);
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
  const char *_arg3270 = "/empty";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3270);
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
  const char *_arg3272 = "/read_lines1";
  const char *_arg3273 = "\n";
  size_t _arg3273_size = 1;
  int ret1;
  ret1 = guestfs_write (g, _arg3272, _arg3273, _arg3273_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3275 = "/read_lines1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3275);
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
  const char *_arg3277 = "/read_lines2";
  const char *_arg3278 = "\r\n";
  size_t _arg3278_size = 2;
  int ret1;
  ret1 = guestfs_write (g, _arg3277, _arg3278, _arg3278_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3280 = "/read_lines2";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3280);
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
  const char *_arg3282 = "/read_lines3";
  const char *_arg3283 = "\n\r\n";
  size_t _arg3283_size = 3;
  int ret1;
  ret1 = guestfs_write (g, _arg3282, _arg3283, _arg3283_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3285 = "/read_lines3";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3285);
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
  const char *_arg3287 = "/read_lines4";
  const char *_arg3288 = "a";
  size_t _arg3288_size = 1;
  int ret1;
  ret1 = guestfs_write (g, _arg3287, _arg3288, _arg3288_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3290 = "/read_lines4";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3290);
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
  const char *_arg3292 = "/read_lines5";
  const char *_arg3293 = "a\nb";
  size_t _arg3293_size = 3;
  int ret1;
  ret1 = guestfs_write (g, _arg3292, _arg3293, _arg3293_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3295 = "/read_lines5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3295);
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
  const char *_arg3297 = "/read_lines6";
  const char *_arg3298 = "a\nb\n";
  size_t _arg3298_size = 4;
  int ret1;
  ret1 = guestfs_write (g, _arg3297, _arg3298, _arg3298_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3300 = "/read_lines6";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3300);
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
  const char *_arg3302 = "/read_lines7";
  const char *_arg3303 = "a\nb\r\n";
  size_t _arg3303_size = 5;
  int ret1;
  ret1 = guestfs_write (g, _arg3302, _arg3303, _arg3303_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3305 = "/read_lines7";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3305);
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
  const char *_arg3307 = "/read_lines8";
  const char *_arg3308 = "a\nb\r\n\n";
  size_t _arg3308_size = 6;
  int ret1;
  ret1 = guestfs_write (g, _arg3307, _arg3308, _arg3308_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3310 = "/read_lines8";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3310);
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
  const char *_arg3312 = "/known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg3312, &size);
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
  const char *_arg3314 = "/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, _arg3314);
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
  const char *_arg3316 = "/a";
  int ret3;
  ret3 = guestfs_touch (g, _arg3316);
  if (ret3 == -1)
    return -1;
  const char *_arg3318 = "/b";
  int ret2;
  ret2 = guestfs_mkdir (g, _arg3318);
  if (ret2 == -1)
    return -1;
  const char *_arg3320 = "/b/c";
  int ret1;
  ret1 = guestfs_touch (g, _arg3320);
  if (ret1 == -1)
    return -1;
  const char *_arg3322 = "/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, _arg3322);
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
  const char *_arg3324 = "/find/b/c";
  int ret2;
  ret2 = guestfs_mkdir_p (g, _arg3324);
  if (ret2 == -1)
    return -1;
  const char *_arg3326 = "/find/b/c/d";
  int ret1;
  ret1 = guestfs_touch (g, _arg3326);
  if (ret1 == -1)
    return -1;
  const char *_arg3328 = "/find/b/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, _arg3328);
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
  const char *_arg3330 = "/known-2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3330);
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
  CLEANUP_FREE char *_ret3332;
  _ret3332 = guestfs_get_backend (g);
  if (_ret3332 == NULL)
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
  CLEANUP_FREE char *_ret3334;
  _ret3334 = guestfs_get_attach_method (g);
  if (_ret3334 == NULL)
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
  const char *_arg3336 = "/bin-i586-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3336);
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
  const char *_arg3338 = "/bin-sparc-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3338);
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
  const char *_arg3340 = "/bin-win32.exe";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3340);
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
  const char *_arg3342 = "/bin-win64.exe";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3342);
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
  const char *_arg3344 = "/bin-x86_64-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3344);
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
  const char *_arg3346 = "/lib-i586.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3346);
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
  const char *_arg3348 = "/lib-sparc.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3348);
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
  const char *_arg3350 = "/lib-win32.dll";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3350);
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
  const char *_arg3352 = "/lib-win64.dll";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3352);
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
  const char *_arg3354 = "/lib-x86_64.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3354);
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
  const char *_arg3356 = "/initrd-x86_64.img";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3356);
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
  const char *_arg3358 = "/initrd-x86_64.img.gz";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3358);
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
  int _ret3360;
  _ret3360 = guestfs_set_trace (g, 0);
  if (_ret3360 == -1)
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
  const char *_ret3371;
  _ret3371 = guestfs_get_path (g);
  if (_ret3371 == NULL)
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
  const char *_ret3373;
  _ret3373 = guestfs_get_qemu (g);
  if (_ret3373 == NULL)
      return -1;
  return 0;
}

size_t nr_tests = 429;

struct test tests[429] = {
  { .name = "test_cp_r_0", .test_fn = test_cp_r_0 },
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
  { .name = "test_is_file_2", .test_fn = test_is_file_2 },
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
