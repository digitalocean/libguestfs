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
test_remount_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "remount") == NULL;
  str = getenv ("SKIP_TEST_REMOUNT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_REMOUNT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_remount_0 (guestfs_h *g)
{
  if (test_remount_0_skip ()) {
    skipped ("test_remount_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestLastFail for remount (0) */
  const char *_arg2 = "/";
  struct guestfs_remount_argv _optargs3;
  _optargs3.rw = 0;
  _optargs3.bitmask = UINT64_C(0x1);
  int _ret1;
  _ret1 = guestfs_remount_argv (g, _arg2, &_optargs3);
  if (_ret1 == -1)
    return -1;
  const char *_arg5 = "/remount1";
  const char *_arg6 = "data";
  size_t _arg6_size = 4;
  int _ret4;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret4 = guestfs_write (g, _arg5, _arg6, _arg6_size);
  guestfs_pop_error_handler (g);
  if (_ret4 != -1)
    return -1;
  return 0;
}

static int
test_remount_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "remount") == NULL;
  str = getenv ("SKIP_TEST_REMOUNT_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_REMOUNT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_remount_1 (guestfs_h *g)
{
  if (test_remount_1_skip ()) {
    skipped ("test_remount_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for remount (1) */
  const char *_arg9 = "/";
  struct guestfs_remount_argv _optargs10;
  _optargs10.rw = 0;
  _optargs10.bitmask = UINT64_C(0x1);
  int _ret8;
  _ret8 = guestfs_remount_argv (g, _arg9, &_optargs10);
  if (_ret8 == -1)
    return -1;
  const char *_arg12 = "/";
  struct guestfs_remount_argv _optargs13;
  _optargs13.rw = 1;
  _optargs13.bitmask = UINT64_C(0x1);
  int _ret11;
  _ret11 = guestfs_remount_argv (g, _arg12, &_optargs13);
  if (_ret11 == -1)
    return -1;
  const char *_arg15 = "/remount2";
  const char *_arg16 = "data";
  size_t _arg16_size = 4;
  int _ret14;
  _ret14 = guestfs_write (g, _arg15, _arg16, _arg16_size);
  if (_ret14 == -1)
    return -1;
  return 0;
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
  const char *_arg19 = "/cp_r1";
  int _ret18;
  _ret18 = guestfs_mkdir (g, _arg19);
  if (_ret18 == -1)
    return -1;
  const char *_arg22 = "/cp_r2";
  int _ret21;
  _ret21 = guestfs_mkdir (g, _arg22);
  if (_ret21 == -1)
    return -1;
  const char *_arg25 = "/cp_r1/file";
  const char *_arg26 = "file content";
  size_t _arg26_size = 12;
  int _ret24;
  _ret24 = guestfs_write (g, _arg25, _arg26, _arg26_size);
  if (_ret24 == -1)
    return -1;
  const char *_arg29 = "/cp_r1";
  const char *_arg30 = "/cp_r2";
  int _ret28;
  _ret28 = guestfs_cp_r (g, _arg29, _arg30);
  if (_ret28 == -1)
    return -1;
  const char *_arg32 = "/cp_r2/cp_r1/file";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg32);
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
  const char *const _arg34[1] = { NULL };
  int ret;
  ret = guestfs_feature_available (g, (char **) _arg34);
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
  const char *_arg36 = "/dev/sda";
  int ret;
  ret = guestfs_is_whole_device (g, _arg36);
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
  const char *_arg38 = "/dev/sda1";
  int ret;
  ret = guestfs_is_whole_device (g, _arg38);
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
  const char *_arg40 = "/dev/VG/LV";
  int ret;
  ret = guestfs_is_whole_device (g, _arg40);
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
  const char *_arg43 = "/rename";
  int _ret42;
  _ret42 = guestfs_mkdir (g, _arg43);
  if (_ret42 == -1)
    return -1;
  const char *_arg46 = "/rename/old";
  const char *_arg47 = "file content";
  size_t _arg47_size = 12;
  int _ret45;
  _ret45 = guestfs_write (g, _arg46, _arg47, _arg47_size);
  if (_ret45 == -1)
    return -1;
  const char *_arg50 = "/rename/old";
  const char *_arg51 = "/rename/new";
  int _ret49;
  _ret49 = guestfs_rename (g, _arg50, _arg51);
  if (_ret49 == -1)
    return -1;
  const char *_arg53 = "/rename/old";
  struct guestfs_is_file_opts_argv _optargs54;
  _optargs54.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, _arg53, &_optargs54);
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

  const char *_features55[] = { "gdisk", NULL };
  if (!guestfs_feature_available (g, (char **) _features55)) {
    skipped ("test_part_get_gpt_type_0", "group %s not available in daemon",
             _features55[0]);
    return 0;
  }

  if (init_gpt (g) == -1)
    return -1;

  /* TestResultString for part_get_gpt_type (0) */
  const char *_arg57 = "/dev/sda";
  const char *_arg59 = "01234567-89AB-CDEF-0123-456789ABCDEF";
  int _ret56;
  _ret56 = guestfs_part_set_gpt_type (g, _arg57, 1, _arg59);
  if (_ret56 == -1)
    return -1;
  const char *_arg61 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_gpt_type (g, _arg61, 1);
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

  const char *_features64[] = { "linuxcaps", NULL };
  if (!guestfs_feature_available (g, (char **) _features64)) {
    skipped ("test_cap_set_file_0", "group %s not available in daemon",
             _features64[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for cap_set_file (0) */
  const char *_arg66 = "/cap_set_file_0";
  int _ret65;
  _ret65 = guestfs_touch (g, _arg66);
  if (_ret65 == -1)
    return -1;
  const char *_arg69 = "/cap_set_file_0";
  const char *_arg70 = "cap_chown=p cap_chown+e";
  int _ret68;
  _ret68 = guestfs_cap_set_file (g, _arg69, _arg70);
  if (_ret68 == -1)
    return -1;
  const char *_arg72 = "/cap_set_file_0";
  CLEANUP_FREE char *ret;
  ret = guestfs_cap_get_file (g, _arg72);
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

  const char *_features74[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) _features74)) {
    skipped ("test_acl_delete_def_file_0", "group %s not available in daemon",
             _features74[0]);
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

  const char *_features75[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) _features75)) {
    skipped ("test_acl_delete_def_file_1", "group %s not available in daemon",
             _features75[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for acl_delete_def_file (1) */
  const char *_arg77 = "/acl_delete_def_file_1";
  int _ret76;
  _ret76 = guestfs_mkdir (g, _arg77);
  if (_ret76 == -1)
    return -1;
  const char *_arg80 = "/acl_delete_def_file_1";
  const char *_arg81 = "default";
  const char *_arg82 = "user::r-x,group::r-x,other::r-x";
  int _ret79;
  _ret79 = guestfs_acl_set_file (g, _arg80, _arg81, _arg82);
  if (_ret79 == -1)
    return -1;
  const char *_arg85 = "/acl_delete_def_file_1";
  int _ret84;
  _ret84 = guestfs_acl_delete_def_file (g, _arg85);
  if (_ret84 == -1)
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

  const char *_features87[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) _features87)) {
    skipped ("test_acl_set_file_0", "group %s not available in daemon",
             _features87[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for acl_set_file (0) */
  const char *_arg89 = "/acl_set_file_0";
  int _ret88;
  _ret88 = guestfs_touch (g, _arg89);
  if (_ret88 == -1)
    return -1;
  const char *_arg92 = "/acl_set_file_0";
  const char *_arg93 = "access";
  const char *_arg94 = "user::r-x,group::r-x,other::r-x";
  int _ret91;
  _ret91 = guestfs_acl_set_file (g, _arg92, _arg93, _arg94);
  if (_ret91 == -1)
    return -1;
  const char *_arg97 = "/acl_set_file_0";
  const char *_arg98 = "access";
  CLEANUP_FREE char *_ret96;
  _ret96 = guestfs_acl_get_file (g, _arg97, _arg98);
  if (_ret96 == NULL)
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
  const char *_arg101 = "/lost+found";
  int _ret100;
  _ret100 = guestfs_rm_rf (g, _arg101);
  if (_ret100 == -1)
    return -1;
  const char *_arg104 = "/";
  int _ret103;
  _ret103 = guestfs_mklost_and_found (g, _arg104);
  if (_ret103 == -1)
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
  const char *_arg107 = "/mktemp";
  int _ret106;
  _ret106 = guestfs_mkdir (g, _arg107);
  if (_ret106 == -1)
    return -1;
  const char *_arg110 = "/mktemp/tmpXXXXXX";
  struct guestfs_mktemp_argv _optargs111;
  _optargs111.bitmask = UINT64_C(0x0);
  CLEANUP_FREE char *_ret109;
  _ret109 = guestfs_mktemp_argv (g, _arg110, &_optargs111);
  if (_ret109 == NULL)
      return -1;
  const char *_arg113 = "/mktemp/tmpXXXXXX";
  struct guestfs_mktemp_argv _optargs114;
  _optargs114.suffix = "suff";
  _optargs114.bitmask = UINT64_C(0x1);
  CLEANUP_FREE char *_ret112;
  _ret112 = guestfs_mktemp_argv (g, _arg113, &_optargs114);
  if (_ret112 == NULL)
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
  const char *_arg116 = "/dev/sda";
  const char *_arg117 = "mbr";
  int _ret115;
  _ret115 = guestfs_part_init (g, _arg116, _arg117);
  if (_ret115 == -1)
    return -1;
  const char *_arg120 = "/dev/sda";
  const char *_arg121 = "p";
  int _ret119;
  _ret119 = guestfs_part_add (g, _arg120, _arg121, 64, 204799);
  if (_ret119 == -1)
    return -1;
  const char *_arg126 = "/dev/sda";
  const char *_arg127 = "p";
  int _ret125;
  _ret125 = guestfs_part_add (g, _arg126, _arg127, 204800, -64);
  if (_ret125 == -1)
    return -1;
  const char *_arg132 = "/dev/sda1";
  struct guestfs_mke2fs_argv _optargs133;
  _optargs133.blocksize = 4096;
  _optargs133.journaldev = 1;
  _optargs133.bitmask = UINT64_C(0x100000002);
  int _ret131;
  _ret131 = guestfs_mke2fs_argv (g, _arg132, &_optargs133);
  if (_ret131 == -1)
    return -1;
  const char *_arg135 = "/dev/sda2";
  struct guestfs_mke2fs_argv _optargs136;
  _optargs136.blocksize = 4096;
  _optargs136.journaldevice = "/dev/sda1";
  _optargs136.fstype = "ext2";
  _optargs136.bitmask = UINT64_C(0x44002);
  int _ret134;
  _ret134 = guestfs_mke2fs_argv (g, _arg135, &_optargs136);
  if (_ret134 == -1)
    return -1;
  const char *_arg138 = "/dev/sda2";
  const char *_arg139 = "/";
  int _ret137;
  _ret137 = guestfs_mount (g, _arg138, _arg139);
  if (_ret137 == -1)
    return -1;
  const char *_arg142 = "/new";
  const char *_arg143 = "new file contents";
  size_t _arg143_size = 17;
  int _ret141;
  _ret141 = guestfs_write (g, _arg142, _arg143, _arg143_size);
  if (_ret141 == -1)
    return -1;
  const char *_arg145 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg145);
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
  const char *_arg148 = "/dev/sda";
  const char *_arg149 = "mbr";
  int _ret147;
  _ret147 = guestfs_part_init (g, _arg148, _arg149);
  if (_ret147 == -1)
    return -1;
  const char *_arg152 = "/dev/sda";
  const char *_arg153 = "p";
  int _ret151;
  _ret151 = guestfs_part_add (g, _arg152, _arg153, 64, 204799);
  if (_ret151 == -1)
    return -1;
  const char *_arg158 = "/dev/sda";
  const char *_arg159 = "p";
  int _ret157;
  _ret157 = guestfs_part_add (g, _arg158, _arg159, 204800, -64);
  if (_ret157 == -1)
    return -1;
  const char *_arg164 = "/dev/sda1";
  struct guestfs_mke2fs_argv _optargs165;
  _optargs165.blocksize = 4096;
  _optargs165.journaldevice = "/dev/sda1";
  _optargs165.label = "JOURNAL";
  _optargs165.fstype = "ext2";
  _optargs165.journaldev = 1;
  _optargs165.bitmask = UINT64_C(0x10004c002);
  int _ret163;
  _ret163 = guestfs_mke2fs_argv (g, _arg164, &_optargs165);
  if (_ret163 == -1)
    return -1;
  const char *_arg167 = "/dev/sda2";
  struct guestfs_mke2fs_argv _optargs168;
  _optargs168.blocksize = 4096;
  _optargs168.journaldevice = "LABEL=JOURNAL";
  _optargs168.label = "JOURNAL";
  _optargs168.fstype = "ext2";
  _optargs168.bitmask = UINT64_C(0x4c002);
  int _ret166;
  _ret166 = guestfs_mke2fs_argv (g, _arg167, &_optargs168);
  if (_ret166 == -1)
    return -1;
  const char *_arg170 = "/dev/sda2";
  const char *_arg171 = "/";
  int _ret169;
  _ret169 = guestfs_mount (g, _arg170, _arg171);
  if (_ret169 == -1)
    return -1;
  const char *_arg174 = "/new";
  const char *_arg175 = "new file contents";
  size_t _arg175_size = 17;
  int _ret173;
  _ret173 = guestfs_write (g, _arg174, _arg175, _arg175_size);
  if (_ret173 == -1)
    return -1;
  const char *_arg177 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg177);
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
  const char *_arg180 = "/dev/sda";
  const char *_arg181 = "mbr";
  int _ret179;
  _ret179 = guestfs_part_init (g, _arg180, _arg181);
  if (_ret179 == -1)
    return -1;
  const char *_arg184 = "/dev/sda";
  const char *_arg185 = "p";
  int _ret183;
  _ret183 = guestfs_part_add (g, _arg184, _arg185, 64, 204799);
  if (_ret183 == -1)
    return -1;
  const char *_arg190 = "/dev/sda";
  const char *_arg191 = "p";
  int _ret189;
  _ret189 = guestfs_part_add (g, _arg190, _arg191, 204800, -64);
  if (_ret189 == -1)
    return -1;
  const char *_arg196 = "/dev/sda1";
  struct guestfs_mke2fs_argv _optargs197;
  _optargs197.blocksize = 4096;
  _optargs197.uuid = "c70c615b-388c-4537-5d08-73fd30081170";
  _optargs197.journaldev = 1;
  _optargs197.bitmask = UINT64_C(0x100100002);
  int _ret195;
  _ret195 = guestfs_mke2fs_argv (g, _arg196, &_optargs197);
  if (_ret195 == -1)
    return -1;
  const char *_arg199 = "/dev/sda2";
  struct guestfs_mke2fs_argv _optargs200;
  _optargs200.blocksize = 4096;
  _optargs200.journaldevice = "UUID=c70c615b-388c-4537-5d08-73fd30081170";
  _optargs200.label = "JOURNAL";
  _optargs200.fstype = "ext2";
  _optargs200.forcecreate = 1;
  _optargs200.bitmask = UINT64_C(0x24c002);
  int _ret198;
  _ret198 = guestfs_mke2fs_argv (g, _arg199, &_optargs200);
  if (_ret198 == -1)
    return -1;
  const char *_arg202 = "/dev/sda2";
  const char *_arg203 = "/";
  int _ret201;
  _ret201 = guestfs_mount (g, _arg202, _arg203);
  if (_ret201 == -1)
    return -1;
  const char *_arg206 = "/new";
  const char *_arg207 = "new file contents";
  size_t _arg207_size = 17;
  int _ret205;
  _ret205 = guestfs_write (g, _arg206, _arg207, _arg207_size);
  if (_ret205 == -1)
    return -1;
  const char *_arg209 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg209);
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
  const char *_arg212 = "/rm_f";
  int _ret211;
  _ret211 = guestfs_mkdir (g, _arg212);
  if (_ret211 == -1)
    return -1;
  const char *_arg215 = "/rm_f/foo";
  int _ret214;
  _ret214 = guestfs_touch (g, _arg215);
  if (_ret214 == -1)
    return -1;
  const char *_arg218 = "/rm_f/foo";
  int _ret217;
  _ret217 = guestfs_rm_f (g, _arg218);
  if (_ret217 == -1)
    return -1;
  const char *_arg221 = "/rm_f/not_exists";
  int _ret220;
  _ret220 = guestfs_rm_f (g, _arg221);
  if (_ret220 == -1)
    return -1;
  const char *_arg223 = "/rm_f/foo";
  int ret;
  ret = guestfs_exists (g, _arg223);
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
  const char *_arg226 = "/rm_f2";
  int _ret225;
  _ret225 = guestfs_mkdir (g, _arg226);
  if (_ret225 == -1)
    return -1;
  const char *_arg229 = "/rm_f2/foo";
  int _ret228;
  _ret228 = guestfs_mkdir (g, _arg229);
  if (_ret228 == -1)
    return -1;
  const char *_arg232 = "/rm_f2/foo";
  int _ret231;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret231 = guestfs_rm_f (g, _arg232);
  guestfs_pop_error_handler (g);
  if (_ret231 != -1)
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

  const char *_features234[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features234)) {
    skipped ("test_xfs_repair_0", "group %s not available in daemon",
             _features234[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for xfs_repair (0) */
  const char *_arg236 = "/dev/sda";
  const char *_arg237 = "mbr";
  int _ret235;
  _ret235 = guestfs_part_disk (g, _arg236, _arg237);
  if (_ret235 == -1)
    return -1;
  const char *_arg240 = "xfs";
  const char *_arg241 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs242;
  _optargs242.bitmask = UINT64_C(0x0);
  int _ret239;
  _ret239 = guestfs_mkfs_opts_argv (g, _arg240, _arg241, &_optargs242);
  if (_ret239 == -1)
    return -1;
  const char *_arg244 = "/dev/sda1";
  struct guestfs_xfs_repair_argv _optargs245;
  _optargs245.nomodify = 1;
  _optargs245.bitmask = UINT64_C(0x2);
  int _ret243;
  _ret243 = guestfs_xfs_repair_argv (g, _arg244, &_optargs245);
  if (_ret243 == -1)
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

  const char *_features246[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features246)) {
    skipped ("test_xfs_admin_0", "group %s not available in daemon",
             _features246[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for xfs_admin (0) */
  const char *_arg247 = "/dev/sda";
  const char *_arg248 = "mbr";
  int ret4;
  ret4 = guestfs_part_disk (g, _arg247, _arg248);
  if (ret4 == -1)
    return -1;
  const char *_arg250 = "xfs";
  const char *_arg251 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs252;
  _optargs252.bitmask = UINT64_C(0x0);
  int ret3;
  ret3 = guestfs_mkfs_opts_argv (g, _arg250, _arg251, &_optargs252);
  if (ret3 == -1)
    return -1;
  const char *_arg253 = "/dev/sda1";
  struct guestfs_xfs_admin_argv _optargs254;
  _optargs254.lazycounter = 0;
  _optargs254.bitmask = UINT64_C(0x10);
  int ret2;
  ret2 = guestfs_xfs_admin_argv (g, _arg253, &_optargs254);
  if (ret2 == -1)
    return -1;
  const char *_arg255 = "/dev/sda1";
  const char *_arg256 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg255, _arg256);
  if (ret1 == -1)
    return -1;
  const char *_arg258 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, _arg258);
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

  const char *_features260[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features260)) {
    skipped ("test_xfs_growfs_0", "group %s not available in daemon",
             _features260[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for xfs_growfs (0) */
  const char *_arg261 = "/dev/sda";
  const char *_arg262 = "mbr";
  int ret8;
  ret8 = guestfs_part_disk (g, _arg261, _arg262);
  if (ret8 == -1)
    return -1;
  const char *_arg264 = "/dev/sda1";
  int ret7;
  ret7 = guestfs_pvcreate (g, _arg264);
  if (ret7 == -1)
    return -1;
  const char *_arg266 = "VG";
  const char *_arg267_0 = "/dev/sda1";
  const char *const _arg267[] = {
    _arg267_0,
    NULL
  };
  int ret6;
  ret6 = guestfs_vgcreate (g, _arg266, (char **) _arg267);
  if (ret6 == -1)
    return -1;
  const char *_arg269 = "LV";
  const char *_arg270 = "VG";
  int ret5;
  ret5 = guestfs_lvcreate (g, _arg269, _arg270, 40);
  if (ret5 == -1)
    return -1;
  const char *_arg273 = "xfs";
  const char *_arg274 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs275;
  _optargs275.bitmask = UINT64_C(0x0);
  int ret4;
  ret4 = guestfs_mkfs_opts_argv (g, _arg273, _arg274, &_optargs275);
  if (ret4 == -1)
    return -1;
  const char *_arg276 = "/dev/VG/LV";
  int ret3;
  ret3 = guestfs_lvresize (g, _arg276, 80);
  if (ret3 == -1)
    return -1;
  const char *_arg279 = "/dev/VG/LV";
  const char *_arg280 = "/";
  int ret2;
  ret2 = guestfs_mount (g, _arg279, _arg280);
  if (ret2 == -1)
    return -1;
  const char *_arg282 = "/";
  struct guestfs_xfs_growfs_argv _optargs283;
  _optargs283.datasec = 1;
  _optargs283.logsec = 0;
  _optargs283.rtsec = 0;
  _optargs283.bitmask = UINT64_C(0x7);
  int ret1;
  ret1 = guestfs_xfs_growfs_argv (g, _arg282, &_optargs283);
  if (ret1 == -1)
    return -1;
  const char *_arg284 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, _arg284);
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
  CLEANUP_FREE_UTSNAME struct guestfs_utsname *_ret286;
  _ret286 = guestfs_utsname (g);
  if (_ret286 == NULL)
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

  const char *_features288[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features288)) {
    skipped ("test_vgchange_uuid_all_0", "group %s not available in daemon",
             _features288[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for vgchange_uuid_all (0) */
  const char *_arg290 = "/dev/sda";
  const char *_arg291 = "mbr";
  int _ret289;
  _ret289 = guestfs_part_disk (g, _arg290, _arg291);
  if (_ret289 == -1)
    return -1;
  const char *_arg294 = "/dev/sda1";
  int _ret293;
  _ret293 = guestfs_pvcreate (g, _arg294);
  if (_ret293 == -1)
    return -1;
  const char *_arg297 = "VG";
  const char *_arg298_0 = "/dev/sda1";
  const char *const _arg298[] = {
    _arg298_0,
    NULL
  };
  int _ret296;
  _ret296 = guestfs_vgcreate (g, _arg297, (char **) _arg298);
  if (_ret296 == -1)
    return -1;
  int _ret300;
  _ret300 = guestfs_vgchange_uuid_all (g);
  if (_ret300 == -1)
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

  const char *_features302[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features302)) {
    skipped ("test_vgchange_uuid_0", "group %s not available in daemon",
             _features302[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for vgchange_uuid (0) */
  const char *_arg304 = "/dev/sda";
  const char *_arg305 = "mbr";
  int _ret303;
  _ret303 = guestfs_part_disk (g, _arg304, _arg305);
  if (_ret303 == -1)
    return -1;
  const char *_arg308 = "/dev/sda1";
  int _ret307;
  _ret307 = guestfs_pvcreate (g, _arg308);
  if (_ret307 == -1)
    return -1;
  const char *_arg311 = "VG";
  const char *_arg312_0 = "/dev/sda1";
  const char *const _arg312[] = {
    _arg312_0,
    NULL
  };
  int _ret310;
  _ret310 = guestfs_vgcreate (g, _arg311, (char **) _arg312);
  if (_ret310 == -1)
    return -1;
  const char *_arg315 = "/dev/VG";
  int _ret314;
  _ret314 = guestfs_vgchange_uuid (g, _arg315);
  if (_ret314 == -1)
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

  const char *_features317[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features317)) {
    skipped ("test_pvchange_uuid_all_0", "group %s not available in daemon",
             _features317[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for pvchange_uuid_all (0) */
  const char *_arg319 = "/dev/sda";
  const char *_arg320 = "mbr";
  int _ret318;
  _ret318 = guestfs_part_disk (g, _arg319, _arg320);
  if (_ret318 == -1)
    return -1;
  const char *_arg323 = "/dev/sda1";
  int _ret322;
  _ret322 = guestfs_pvcreate (g, _arg323);
  if (_ret322 == -1)
    return -1;
  int _ret325;
  _ret325 = guestfs_pvchange_uuid_all (g);
  if (_ret325 == -1)
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

  const char *_features327[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features327)) {
    skipped ("test_pvchange_uuid_0", "group %s not available in daemon",
             _features327[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for pvchange_uuid (0) */
  const char *_arg329 = "/dev/sda";
  const char *_arg330 = "mbr";
  int _ret328;
  _ret328 = guestfs_part_disk (g, _arg329, _arg330);
  if (_ret328 == -1)
    return -1;
  const char *_arg333 = "/dev/sda1";
  int _ret332;
  _ret332 = guestfs_pvcreate (g, _arg333);
  if (_ret332 == -1)
    return -1;
  const char *_arg336 = "/dev/sda1";
  int _ret335;
  _ret335 = guestfs_pvchange_uuid (g, _arg336);
  if (_ret335 == -1)
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

  const char *_features338[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features338)) {
    skipped ("test_xfs_info_0", "group %s not available in daemon",
             _features338[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for xfs_info (0) */
  const char *_arg339 = "/dev/sda";
  const char *_arg340 = "mbr";
  int ret3;
  ret3 = guestfs_part_disk (g, _arg339, _arg340);
  if (ret3 == -1)
    return -1;
  const char *_arg342 = "xfs";
  const char *_arg343 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs344;
  _optargs344.bitmask = UINT64_C(0x0);
  int ret2;
  ret2 = guestfs_mkfs_opts_argv (g, _arg342, _arg343, &_optargs344);
  if (ret2 == -1)
    return -1;
  const char *_arg345 = "/dev/sda1";
  const char *_arg346 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg345, _arg346);
  if (ret1 == -1)
    return -1;
  const char *_arg348 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, _arg348);
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
  const char *_arg351 = "/dev/sda";
  int ret;
  ret = guestfs_device_index (g, _arg351);
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

  const char *_features353[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features353)) {
    skipped ("test_btrfs_fsck_0", "group %s not available in daemon",
             _features353[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_fsck (0) */
  const char *_arg355_0 = "/dev/sda1";
  const char *const _arg355[] = {
    _arg355_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs356;
  _optargs356.bitmask = UINT64_C(0x0);
  int _ret354;
  _ret354 = guestfs_mkfs_btrfs_argv (g, (char **) _arg355, &_optargs356);
  if (_ret354 == -1)
    return -1;
  const char *_arg358 = "/dev/sda1";
  struct guestfs_btrfs_fsck_argv _optargs359;
  _optargs359.bitmask = UINT64_C(0x0);
  int _ret357;
  _ret357 = guestfs_btrfs_fsck_argv (g, _arg358, &_optargs359);
  if (_ret357 == -1)
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

  const char *_features360[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features360)) {
    skipped ("test_btrfs_set_seeding_0", "group %s not available in daemon",
             _features360[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_set_seeding (0) */
  const char *_arg362_0 = "/dev/sda1";
  const char *const _arg362[] = {
    _arg362_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs363;
  _optargs363.bitmask = UINT64_C(0x0);
  int _ret361;
  _ret361 = guestfs_mkfs_btrfs_argv (g, (char **) _arg362, &_optargs363);
  if (_ret361 == -1)
    return -1;
  const char *_arg365 = "/dev/sda1";
  int _ret364;
  _ret364 = guestfs_btrfs_set_seeding (g, _arg365, 1);
  if (_ret364 == -1)
    return -1;
  const char *_arg369 = "/dev/sda1";
  int _ret368;
  _ret368 = guestfs_btrfs_set_seeding (g, _arg369, 0);
  if (_ret368 == -1)
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

  const char *_features372[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features372)) {
    skipped ("test_btrfs_filesystem_sync_0", "group %s not available in daemon",
             _features372[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_filesystem_sync (0) */
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
  _ret383 = guestfs_btrfs_filesystem_sync (g, _arg384);
  if (_ret383 == -1)
    return -1;
  const char *_arg387 = "/test1";
  int _ret386;
  _ret386 = guestfs_btrfs_filesystem_balance (g, _arg387);
  if (_ret386 == -1)
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

  const char *_features389[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features389)) {
    skipped ("test_btrfs_subvolume_delete_0", "group %s not available in daemon",
             _features389[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_subvolume_delete (0) */
  const char *_arg391_0 = "/dev/sda1";
  const char *const _arg391[] = {
    _arg391_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs392;
  _optargs392.bitmask = UINT64_C(0x0);
  int _ret390;
  _ret390 = guestfs_mkfs_btrfs_argv (g, (char **) _arg391, &_optargs392);
  if (_ret390 == -1)
    return -1;
  const char *_arg394 = "/dev/sda1";
  const char *_arg395 = "/";
  int _ret393;
  _ret393 = guestfs_mount (g, _arg394, _arg395);
  if (_ret393 == -1)
    return -1;
  const char *_arg398 = "/test1";
  int _ret397;
  _ret397 = guestfs_btrfs_subvolume_create (g, _arg398);
  if (_ret397 == -1)
    return -1;
  const char *_arg401 = "/test1";
  int _ret400;
  _ret400 = guestfs_btrfs_subvolume_delete (g, _arg401);
  if (_ret400 == -1)
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

  const char *_features403[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features403)) {
    skipped ("test_btrfs_subvolume_snapshot_0", "group %s not available in daemon",
             _features403[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for btrfs_subvolume_snapshot (0) */
  const char *_arg405_0 = "/dev/sda1";
  const char *const _arg405[] = {
    _arg405_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs406;
  _optargs406.bitmask = UINT64_C(0x0);
  int _ret404;
  _ret404 = guestfs_mkfs_btrfs_argv (g, (char **) _arg405, &_optargs406);
  if (_ret404 == -1)
    return -1;
  const char *_arg408 = "/dev/sda1";
  const char *_arg409 = "/";
  int _ret407;
  _ret407 = guestfs_mount (g, _arg408, _arg409);
  if (_ret407 == -1)
    return -1;
  const char *_arg412 = "/dir";
  int _ret411;
  _ret411 = guestfs_mkdir (g, _arg412);
  if (_ret411 == -1)
    return -1;
  const char *_arg415 = "/test1";
  int _ret414;
  _ret414 = guestfs_btrfs_subvolume_create (g, _arg415);
  if (_ret414 == -1)
    return -1;
  const char *_arg418 = "/test2";
  int _ret417;
  _ret417 = guestfs_btrfs_subvolume_create (g, _arg418);
  if (_ret417 == -1)
    return -1;
  const char *_arg421 = "/dir/test3";
  int _ret420;
  _ret420 = guestfs_btrfs_subvolume_create (g, _arg421);
  if (_ret420 == -1)
    return -1;
  const char *_arg424 = "/dir/test3";
  const char *_arg425 = "/dir/test4";
  int _ret423;
  _ret423 = guestfs_btrfs_subvolume_snapshot (g, _arg424, _arg425);
  if (_ret423 == -1)
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
  const char *_arg427 = "/e2generation";
  int ret2;
  ret2 = guestfs_touch (g, _arg427);
  if (ret2 == -1)
    return -1;
  const char *_arg429 = "/e2generation";
  int ret1;
  ret1 = guestfs_set_e2generation (g, _arg429, 123456);
  if (ret1 == -1)
    return -1;
  const char *_arg432 = "/e2generation";
  int64_t ret;
  ret = guestfs_get_e2generation (g, _arg432);
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
  const char *_arg435 = "/e2attrs1";
  int _ret434;
  _ret434 = guestfs_touch (g, _arg435);
  if (_ret434 == -1)
    return -1;
  const char *_arg437 = "/e2attrs1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg437);
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
  const char *_arg440 = "/e2attrs2";
  int _ret439;
  _ret439 = guestfs_touch (g, _arg440);
  if (_ret439 == -1)
    return -1;
  const char *_arg443 = "/e2attrs2";
  const char *_arg444 = "is";
  struct guestfs_set_e2attrs_argv _optargs445;
  _optargs445.clear = 0;
  _optargs445.bitmask = UINT64_C(0x1);
  int _ret442;
  _ret442 = guestfs_set_e2attrs_argv (g, _arg443, _arg444, &_optargs445);
  if (_ret442 == -1)
    return -1;
  const char *_arg446 = "/e2attrs2";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg446);
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
  const char *_arg449 = "/e2attrs3";
  int _ret448;
  _ret448 = guestfs_touch (g, _arg449);
  if (_ret448 == -1)
    return -1;
  const char *_arg452 = "/e2attrs3";
  const char *_arg453 = "is";
  struct guestfs_set_e2attrs_argv _optargs454;
  _optargs454.clear = 0;
  _optargs454.bitmask = UINT64_C(0x1);
  int _ret451;
  _ret451 = guestfs_set_e2attrs_argv (g, _arg452, _arg453, &_optargs454);
  if (_ret451 == -1)
    return -1;
  const char *_arg456 = "/e2attrs3";
  const char *_arg457 = "i";
  struct guestfs_set_e2attrs_argv _optargs458;
  _optargs458.clear = 1;
  _optargs458.bitmask = UINT64_C(0x1);
  int _ret455;
  _ret455 = guestfs_set_e2attrs_argv (g, _arg456, _arg457, &_optargs458);
  if (_ret455 == -1)
    return -1;
  const char *_arg459 = "/e2attrs3";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg459);
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
  const char *_arg462 = "/e2attrs4";
  int _ret461;
  _ret461 = guestfs_touch (g, _arg462);
  if (_ret461 == -1)
    return -1;
  const char *_arg465 = "/e2attrs4";
  const char *_arg466 = "adst";
  struct guestfs_set_e2attrs_argv _optargs467;
  _optargs467.clear = 0;
  _optargs467.bitmask = UINT64_C(0x1);
  int _ret464;
  _ret464 = guestfs_set_e2attrs_argv (g, _arg465, _arg466, &_optargs467);
  if (_ret464 == -1)
    return -1;
  const char *_arg469 = "/e2attrs4";
  const char *_arg470 = "iS";
  struct guestfs_set_e2attrs_argv _optargs471;
  _optargs471.clear = 0;
  _optargs471.bitmask = UINT64_C(0x1);
  int _ret468;
  _ret468 = guestfs_set_e2attrs_argv (g, _arg469, _arg470, &_optargs471);
  if (_ret468 == -1)
    return -1;
  const char *_arg473 = "/e2attrs4";
  const char *_arg474 = "i";
  struct guestfs_set_e2attrs_argv _optargs475;
  _optargs475.clear = 1;
  _optargs475.bitmask = UINT64_C(0x1);
  int _ret472;
  _ret472 = guestfs_set_e2attrs_argv (g, _arg473, _arg474, &_optargs475);
  if (_ret472 == -1)
    return -1;
  const char *_arg477 = "/e2attrs4";
  const char *_arg478 = "ad";
  struct guestfs_set_e2attrs_argv _optargs479;
  _optargs479.clear = 1;
  _optargs479.bitmask = UINT64_C(0x1);
  int _ret476;
  _ret476 = guestfs_set_e2attrs_argv (g, _arg477, _arg478, &_optargs479);
  if (_ret476 == -1)
    return -1;
  const char *_arg481 = "/e2attrs4";
  const char *_arg482 = "";
  struct guestfs_set_e2attrs_argv _optargs483;
  _optargs483.clear = 0;
  _optargs483.bitmask = UINT64_C(0x1);
  int _ret480;
  _ret480 = guestfs_set_e2attrs_argv (g, _arg481, _arg482, &_optargs483);
  if (_ret480 == -1)
    return -1;
  const char *_arg485 = "/e2attrs4";
  const char *_arg486 = "";
  struct guestfs_set_e2attrs_argv _optargs487;
  _optargs487.clear = 1;
  _optargs487.bitmask = UINT64_C(0x1);
  int _ret484;
  _ret484 = guestfs_set_e2attrs_argv (g, _arg485, _arg486, &_optargs487);
  if (_ret484 == -1)
    return -1;
  const char *_arg488 = "/e2attrs4";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg488);
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
  const char *_arg491 = "/e2attrs5";
  int _ret490;
  _ret490 = guestfs_touch (g, _arg491);
  if (_ret490 == -1)
    return -1;
  const char *_arg494 = "/e2attrs5";
  const char *_arg495 = "R";
  struct guestfs_set_e2attrs_argv _optargs496;
  _optargs496.clear = 0;
  _optargs496.bitmask = UINT64_C(0x1);
  int _ret493;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret493 = guestfs_set_e2attrs_argv (g, _arg494, _arg495, &_optargs496);
  guestfs_pop_error_handler (g);
  if (_ret493 != -1)
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
  const char *_arg498 = "/e2attrs6";
  int _ret497;
  _ret497 = guestfs_touch (g, _arg498);
  if (_ret497 == -1)
    return -1;
  const char *_arg501 = "/e2attrs6";
  const char *_arg502 = "v";
  struct guestfs_set_e2attrs_argv _optargs503;
  _optargs503.clear = 0;
  _optargs503.bitmask = UINT64_C(0x1);
  int _ret500;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret500 = guestfs_set_e2attrs_argv (g, _arg501, _arg502, &_optargs503);
  guestfs_pop_error_handler (g);
  if (_ret500 != -1)
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
  const char *_arg505 = "/e2attrs7";
  int _ret504;
  _ret504 = guestfs_touch (g, _arg505);
  if (_ret504 == -1)
    return -1;
  const char *_arg508 = "/e2attrs7";
  const char *_arg509 = "aa";
  struct guestfs_set_e2attrs_argv _optargs510;
  _optargs510.clear = 0;
  _optargs510.bitmask = UINT64_C(0x1);
  int _ret507;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret507 = guestfs_set_e2attrs_argv (g, _arg508, _arg509, &_optargs510);
  guestfs_pop_error_handler (g);
  if (_ret507 != -1)
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
  const char *_arg512 = "/e2attrs8";
  int _ret511;
  _ret511 = guestfs_touch (g, _arg512);
  if (_ret511 == -1)
    return -1;
  const char *_arg515 = "/e2attrs8";
  const char *_arg516 = "BabcdB";
  struct guestfs_set_e2attrs_argv _optargs517;
  _optargs517.clear = 0;
  _optargs517.bitmask = UINT64_C(0x1);
  int _ret514;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret514 = guestfs_set_e2attrs_argv (g, _arg515, _arg516, &_optargs517);
  guestfs_pop_error_handler (g);
  if (_ret514 != -1)
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

  const char *_features518[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features518)) {
    skipped ("test_mkfs_btrfs_0", "group %s not available in daemon",
             _features518[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkfs_btrfs (0) */
  const char *_arg520 = "/dev/sda";
  const char *_arg521 = "mbr";
  int _ret519;
  _ret519 = guestfs_part_disk (g, _arg520, _arg521);
  if (_ret519 == -1)
    return -1;
  const char *_arg524_0 = "/dev/sda1";
  const char *const _arg524[] = {
    _arg524_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs525;
  _optargs525.allocstart = 0;
  _optargs525.bytecount = 268435456;
  _optargs525.datatype = "single";
  _optargs525.leafsize = 4096;
  _optargs525.label = "test";
  _optargs525.metadata = "single";
  _optargs525.nodesize = 4096;
  _optargs525.sectorsize = 512;
  _optargs525.bitmask = UINT64_C(0xff);
  int _ret523;
  _ret523 = guestfs_mkfs_btrfs_argv (g, (char **) _arg524, &_optargs525);
  if (_ret523 == -1)
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
  const char *_arg526 = "/dev/sdd";
  CLEANUP_FREE_ISOINFO struct guestfs_isoinfo *ret;
  ret = guestfs_isoinfo_device (g, _arg526);
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

  const char *_features528[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features528)) {
    skipped ("test_lvcreate_free_0", "group %s not available in daemon",
             _features528[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvcreate_free (0) */
  const char *_arg529 = "/dev/sda";
  const char *_arg530 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg529, _arg530);
  if (ret7 == -1)
    return -1;
  const char *_arg532 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg532);
  if (ret6 == -1)
    return -1;
  const char *_arg534 = "VG";
  const char *_arg535_0 = "/dev/sda1";
  const char *const _arg535[] = {
    _arg535_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg534, (char **) _arg535);
  if (ret5 == -1)
    return -1;
  const char *_arg537 = "LV1";
  const char *_arg538 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate_free (g, _arg537, _arg538, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg541 = "LV2";
  const char *_arg542 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate_free (g, _arg541, _arg542, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg545 = "LV3";
  const char *_arg546 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate_free (g, _arg545, _arg546, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg549 = "LV4";
  const char *_arg550 = "VG";
  int ret1;
  ret1 = guestfs_lvcreate_free (g, _arg549, _arg550, 100);
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
  const char *_arg555 = "/";
  int _ret554;
  _ret554 = guestfs_zero_free_space (g, _arg555);
  if (_ret554 == -1)
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
  const char *_arg558 = "/dev/sda1";
  const char *_arg559 = "testlabel";
  int _ret557;
  _ret557 = guestfs_set_label (g, _arg558, _arg559);
  if (_ret557 == -1)
    return -1;
  const char *_arg561 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, _arg561);
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

  const char *_features563[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features563)) {
    skipped ("test_set_label_1", "group %s not available in daemon",
             _features563[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestResultString for set_label (1) */
  const char *_arg565 = "ntfs";
  const char *_arg566 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs567;
  _optargs567.bitmask = UINT64_C(0x0);
  int _ret564;
  _ret564 = guestfs_mkfs_opts_argv (g, _arg565, _arg566, &_optargs567);
  if (_ret564 == -1)
    return -1;
  const char *_arg569 = "/dev/sda1";
  const char *_arg570 = "testlabel2";
  int _ret568;
  _ret568 = guestfs_set_label (g, _arg569, _arg570);
  if (_ret568 == -1)
    return -1;
  const char *_arg572 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, _arg572);
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
  const char *_arg575 = "/dev/sda1";
  int _ret574;
  _ret574 = guestfs_zero (g, _arg575);
  if (_ret574 == -1)
    return -1;
  const char *_arg578 = "/dev/sda1";
  const char *_arg579 = "testlabel2";
  int _ret577;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret577 = guestfs_set_label (g, _arg578, _arg579);
  guestfs_pop_error_handler (g);
  if (_ret577 != -1)
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

  const char *_features581[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features581)) {
    skipped ("test_ntfsfix_0", "group %s not available in daemon",
             _features581[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  /* TestRun for ntfsfix (0) */
  const char *_arg583 = "ntfs";
  const char *_arg584 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs585;
  _optargs585.bitmask = UINT64_C(0x0);
  int _ret582;
  _ret582 = guestfs_mkfs_opts_argv (g, _arg583, _arg584, &_optargs585);
  if (_ret582 == -1)
    return -1;
  const char *_arg587 = "/dev/sda1";
  struct guestfs_ntfsfix_argv _optargs588;
  _optargs588.clearbadsectors = 0;
  _optargs588.bitmask = UINT64_C(0x1);
  int _ret586;
  _ret586 = guestfs_ntfsfix_argv (g, _arg587, &_optargs588);
  if (_ret586 == -1)
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

  const char *_features589[] = { "wipefs", NULL };
  if (!guestfs_feature_available (g, (char **) _features589)) {
    skipped ("test_wipefs_0", "group %s not available in daemon",
             _features589[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestRun for wipefs (0) */
  const char *_arg591 = "/dev/VG/LV";
  struct guestfs_umount_opts_argv _optargs592;
  _optargs592.bitmask = UINT64_C(0x0);
  int _ret590;
  _ret590 = guestfs_umount_opts_argv (g, _arg591, &_optargs592);
  if (_ret590 == -1)
    return -1;
  const char *_arg594 = "/dev/VG/LV";
  int _ret593;
  _ret593 = guestfs_wipefs (g, _arg594);
  if (_ret593 == -1)
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
  const char *_arg596 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_blkid (g, _arg596);
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
  const char *_arg598 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs599;
  _optargs599.force = 0;
  _optargs599.maxmountcount = 0;
  _optargs599.intervalbetweenchecks = 0;
  _optargs599.bitmask = UINT64_C(0x23);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg598, &_optargs599);
  if (ret1 == -1)
    return -1;
  const char *_arg600 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg600);
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
  const char *_arg602 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs603;
  _optargs603.force = 0;
  _optargs603.maxmountcount = 0;
  _optargs603.intervalbetweenchecks = 86400;
  _optargs603.bitmask = UINT64_C(0x23);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg602, &_optargs603);
  if (ret1 == -1)
    return -1;
  const char *_arg604 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg604);
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
  const char *_arg606 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs607;
  _optargs607.force = 0;
  _optargs607.group = 1;
  _optargs607.user = 1;
  _optargs607.bitmask = UINT64_C(0x211);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg606, &_optargs607);
  if (ret1 == -1)
    return -1;
  const char *_arg608 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg608);
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
  const char *_arg610 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs611;
  _optargs611.force = 0;
  _optargs611.group = 0;
  _optargs611.user = 0;
  _optargs611.bitmask = UINT64_C(0x211);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg610, &_optargs611);
  if (ret1 == -1)
    return -1;
  const char *_arg612 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg612);
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
  const char *_arg614 = "/copyff";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg614);
  if (ret3 == -1)
    return -1;
  const char *_arg616 = "/copyff/src";
  const char *_arg617 = "hello, world";
  size_t _arg617_size = 12;
  int ret2;
  ret2 = guestfs_write (g, _arg616, _arg617, _arg617_size);
  if (ret2 == -1)
    return -1;
  const char *_arg619 = "/copyff/src";
  const char *_arg620 = "/copyff/dest";
  struct guestfs_copy_file_to_file_argv _optargs621;
  _optargs621.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_copy_file_to_file_argv (g, _arg619, _arg620, &_optargs621);
  if (ret1 == -1)
    return -1;
  const char *_arg622 = "/copyff/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg622, &size);
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
  const char *_arg625 = "/copyff2";
  int _ret624;
  _ret624 = guestfs_mkdir (g, _arg625);
  if (_ret624 == -1)
    return -1;
  const char *_arg630 = "/copyff2/src";
  int _ret627;
  _ret627 = guestfs_fill (g, 0, 1048576, _arg630);
  if (_ret627 == -1)
    return -1;
  const char *_arg633 = "/copyff2/dest";
  int _ret632;
  _ret632 = guestfs_touch (g, _arg633);
  if (_ret632 == -1)
    return -1;
  const char *_arg636 = "/copyff2/dest";
  int _ret635;
  _ret635 = guestfs_truncate_size (g, _arg636, 1048576);
  if (_ret635 == -1)
    return -1;
  const char *_arg640 = "/copyff2/src";
  const char *_arg641 = "/copyff2/dest";
  struct guestfs_copy_file_to_file_argv _optargs642;
  _optargs642.sparse = 1;
  _optargs642.bitmask = UINT64_C(0x8);
  int _ret639;
  _ret639 = guestfs_copy_file_to_file_argv (g, _arg640, _arg641, &_optargs642);
  if (_ret639 == -1)
    return -1;
  const char *_arg643 = "/copyff2/dest";
  int ret;
  ret = guestfs_is_zero (g, _arg643);
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
  const char *_arg645 = "/dev/sda1";
  int ret;
  ret = guestfs_part_to_partnum (g, _arg645);
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
  const char *_arg648 = "/dev/sda";
  int _ret647;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret647 = guestfs_part_to_partnum (g, _arg648);
  guestfs_pop_error_handler (g);
  if (_ret647 != -1)
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
  const char *_arg651 = "/internal_write_append";
  const char *_arg652 = "line1\n";
  size_t _arg652_size = 6;
  int _ret650;
  _ret650 = guestfs_write (g, _arg651, _arg652, _arg652_size);
  if (_ret650 == -1)
    return -1;
  const char *_arg655 = "/internal_write_append";
  const char *_arg656 = "line2\n";
  size_t _arg656_size = 6;
  int _ret654;
  _ret654 = guestfs_internal_write_append (g, _arg655, _arg656, _arg656_size);
  if (_ret654 == -1)
    return -1;
  const char *_arg659 = "/internal_write_append";
  const char *_arg660 = "line3a";
  size_t _arg660_size = 6;
  int _ret658;
  _ret658 = guestfs_internal_write_append (g, _arg659, _arg660, _arg660_size);
  if (_ret658 == -1)
    return -1;
  const char *_arg663 = "/internal_write_append";
  const char *_arg664 = "line3b\n";
  size_t _arg664_size = 7;
  int _ret662;
  _ret662 = guestfs_internal_write_append (g, _arg663, _arg664, _arg664_size);
  if (_ret662 == -1)
    return -1;
  const char *_arg666 = "/internal_write_append";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg666);
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
  const char *_arg669 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs670;
  _optargs670.force = 0;
  _optargs670.lazyunmount = 0;
  _optargs670.bitmask = UINT64_C(0x3);
  int _ret668;
  _ret668 = guestfs_umount_opts_argv (g, _arg669, &_optargs670);
  if (_ret668 == -1)
    return -1;
  const char *_arg672 = "/dev/sda1";
  int _ret671;
  _ret671 = guestfs_zero_device (g, _arg672);
  if (_ret671 == -1)
    return -1;
  const char *_arg674 = "/dev/sda1";
  int ret;
  ret = guestfs_is_zero_device (g, _arg674);
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
  const char *_arg676 = "/dev/sda1";
  int ret;
  ret = guestfs_is_zero_device (g, _arg676);
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
  const char *_arg678 = "/100kallzeroes";
  int ret;
  ret = guestfs_is_zero (g, _arg678);
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
  const char *_arg680 = "/100kallspaces";
  int ret;
  ret = guestfs_is_zero (g, _arg680);
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
  const char *_arg683 = "/dev/sda";
  const char *_arg684 = "mbr";
  int _ret682;
  _ret682 = guestfs_part_disk (g, _arg683, _arg684);
  if (_ret682 == -1)
    return -1;
  const char *_arg687 = "ext2";
  const char *_arg688 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs689;
  _optargs689.bitmask = UINT64_C(0x0);
  int _ret686;
  _ret686 = guestfs_mkfs_opts_argv (g, _arg687, _arg688, &_optargs689);
  if (_ret686 == -1)
    return -1;
  const char *_arg691 = "/dev/sda1";
  const char *_arg692 = "/";
  int _ret690;
  _ret690 = guestfs_mount (g, _arg691, _arg692);
  if (_ret690 == -1)
    return -1;
  const char *_arg695 = "/new";
  const char *_arg696 = "new file contents";
  size_t _arg696_size = 17;
  int _ret694;
  _ret694 = guestfs_write (g, _arg695, _arg696, _arg696_size);
  if (_ret694 == -1)
    return -1;
  const char *_arg698 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg698);
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

  const char *_features700[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features700)) {
    skipped ("test_lvm_canonical_lv_name_0", "group %s not available in daemon",
             _features700[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResultString for lvm_canonical_lv_name (0) */
  const char *_arg701 = "/dev/mapper/VG-LV";
  CLEANUP_FREE char *ret;
  ret = guestfs_lvm_canonical_lv_name (g, _arg701);
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

  const char *_features703[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features703)) {
    skipped ("test_lvm_canonical_lv_name_1", "group %s not available in daemon",
             _features703[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  /* TestResultString for lvm_canonical_lv_name (1) */
  const char *_arg704 = "/dev/VG/LV";
  CLEANUP_FREE char *ret;
  ret = guestfs_lvm_canonical_lv_name (g, _arg704);
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
  const char *_arg706 = "/dev/sdd";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread_device (g, _arg706, 8, 32768, &size);
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
  const char *_arg710 = "/dev/sda";
  const char *_arg711 = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
  size_t _arg711_size = 66;
  int ret2;
  ret2 = guestfs_pwrite_device (g, _arg710, _arg711, _arg711_size, 446);
  if (ret2 == -1)
    return -1;
  const char *_arg714 = "/dev/sda";
  int ret1;
  ret1 = guestfs_blockdev_rereadpt (g, _arg714);
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
  const char *_arg718 = "/download_offset";
  int _ret717;
  _ret717 = guestfs_mkdir (g, _arg718);
  if (_ret717 == -1)
    return -1;
  CLEANUP_FREE char *_arg721 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *_arg722 = "/download_offset/COPYING.LIB";
  int _ret720;
  _ret720 = guestfs_upload (g, _arg721, _arg722);
  if (_ret720 == -1)
    return -1;
  const char *_arg725 = "/download_offset/COPYING.LIB";
  int _ret724;
  _ret724 = guestfs_download_offset (g, _arg725, "testdownload.tmp", 100, 26430);
  if (_ret724 == -1)
    return -1;
  CLEANUP_FREE char *_arg731 = substitute_srcdir ("testdownload.tmp");
  const char *_arg732 = "/download_offset/COPYING.LIB";
  int _ret730;
  _ret730 = guestfs_upload_offset (g, _arg731, _arg732, 100);
  if (_ret730 == -1)
    return -1;
  const char *_arg735 = "md5";
  const char *_arg736 = "/download_offset/COPYING.LIB";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg735, _arg736);
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
  CLEANUP_FREE char *_arg739 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *_arg740 = "/upload_offset";
  int _ret738;
  _ret738 = guestfs_upload_offset (g, _arg739, _arg740, 0);
  if (_ret738 == -1)
    return -1;
  const char *_arg743 = "md5";
  const char *_arg744 = "/upload_offset";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg743, _arg744);
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
  const char *_arg746 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_to_dev (g, _arg746);
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
  const char *_arg749 = "/dev/sda";
  CLEANUP_FREE char *_ret748;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret748 = guestfs_part_to_dev (g, _arg749);
  guestfs_pop_error_handler (g);
  if (_ret748 != NULL)
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
  const char *_arg751 = "/directory";
  struct guestfs_is_socket_opts_argv _optargs752;
  _optargs752.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_socket_opts_argv (g, _arg751, &_optargs752);
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
  const char *_arg753 = "/directory";
  int ret;
  ret = guestfs_is_symlink (g, _arg753);
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
  const char *_arg755 = "/abssymlink";
  int ret;
  ret = guestfs_is_symlink (g, _arg755);
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
  const char *_arg757 = "/directory";
  struct guestfs_is_fifo_opts_argv _optargs758;
  _optargs758.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_fifo_opts_argv (g, _arg757, &_optargs758);
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
  const char *_arg761 = "/is_fifo";
  int _ret759;
  _ret759 = guestfs_mkfifo (g, 511, _arg761);
  if (_ret759 == -1)
    return -1;
  const char *_arg763 = "/is_fifo";
  struct guestfs_is_fifo_opts_argv _optargs764;
  _optargs764.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_fifo_opts_argv (g, _arg763, &_optargs764);
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
  const char *_arg765 = "/directory";
  struct guestfs_is_blockdev_opts_argv _optargs766;
  _optargs766.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_blockdev_opts_argv (g, _arg765, &_optargs766);
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
  const char *_arg771 = "/is_blockdev";
  int _ret767;
  _ret767 = guestfs_mknod_b (g, 511, 99, 66, _arg771);
  if (_ret767 == -1)
    return -1;
  const char *_arg773 = "/is_blockdev";
  struct guestfs_is_blockdev_opts_argv _optargs774;
  _optargs774.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_blockdev_opts_argv (g, _arg773, &_optargs774);
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
  const char *_arg775 = "/directory";
  struct guestfs_is_chardev_opts_argv _optargs776;
  _optargs776.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_chardev_opts_argv (g, _arg775, &_optargs776);
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
  const char *_arg781 = "/is_chardev";
  int _ret777;
  _ret777 = guestfs_mknod_c (g, 511, 99, 66, _arg781);
  if (_ret777 == -1)
    return -1;
  const char *_arg783 = "/is_chardev";
  struct guestfs_is_chardev_opts_argv _optargs784;
  _optargs784.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_chardev_opts_argv (g, _arg783, &_optargs784);
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
  const char *_arg785 = "/dev/VG/LV";
  int ret;
  ret = guestfs_is_lv (g, _arg785);
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
  const char *_arg787 = "/dev/sda1";
  int ret;
  ret = guestfs_is_lv (g, _arg787);
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
  const char *_arg790 = "/dev/sda1";
  const char *_arg791 = "c70c615b-388c-4537-5d08-73fd30081170";
  int _ret789;
  _ret789 = guestfs_set_e2uuid (g, _arg790, _arg791);
  if (_ret789 == -1)
    return -1;
  const char *_arg793 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_uuid (g, _arg793);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "c70c615b-388c-4537-5d08-73fd30081170")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_vfs_uuid_0", "vfs_uuid", ret, "c70c615b-388c-4537-5d08-73fd30081170");
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
  const char *_arg796 = "/dev/sda1";
  const char *_arg797 = "LTEST";
  int _ret795;
  _ret795 = guestfs_set_label (g, _arg796, _arg797);
  if (_ret795 == -1)
    return -1;
  const char *_arg799 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, _arg799);
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
  const char *_arg801 = "/fallocate64";
  int ret1;
  ret1 = guestfs_fallocate64 (g, _arg801, 1000000);
  if (ret1 == -1)
    return -1;
  const char *_arg804 = "/fallocate64";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg804);
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
  CLEANUP_FREE_STRING_LIST char **_ret806;
  _ret806 = guestfs_available_all_groups (g);
  if (_ret806 == NULL)
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
  const char *_arg809 = "/pwrite";
  const char *_arg810 = "new file contents";
  size_t _arg810_size = 17;
  int _ret808;
  _ret808 = guestfs_write (g, _arg809, _arg810, _arg810_size);
  if (_ret808 == -1)
    return -1;
  const char *_arg813 = "/pwrite";
  const char *_arg814 = "data";
  size_t _arg814_size = 4;
  int _ret812;
  _ret812 = guestfs_pwrite (g, _arg813, _arg814, _arg814_size, 4);
  if (_ret812 == -1)
    return -1;
  const char *_arg817 = "/pwrite";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg817);
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
  const char *_arg820 = "/pwrite2";
  const char *_arg821 = "new file contents";
  size_t _arg821_size = 17;
  int _ret819;
  _ret819 = guestfs_write (g, _arg820, _arg821, _arg821_size);
  if (_ret819 == -1)
    return -1;
  const char *_arg824 = "/pwrite2";
  const char *_arg825 = "is extended";
  size_t _arg825_size = 11;
  int _ret823;
  _ret823 = guestfs_pwrite (g, _arg824, _arg825, _arg825_size, 9);
  if (_ret823 == -1)
    return -1;
  const char *_arg828 = "/pwrite2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg828);
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
  const char *_arg831 = "/pwrite3";
  const char *_arg832 = "new file contents";
  size_t _arg832_size = 17;
  int _ret830;
  _ret830 = guestfs_write (g, _arg831, _arg832, _arg832_size);
  if (_ret830 == -1)
    return -1;
  const char *_arg835 = "/pwrite3";
  const char *_arg836 = "";
  size_t _arg836_size = 0;
  int _ret834;
  _ret834 = guestfs_pwrite (g, _arg835, _arg836, _arg836_size, 4);
  if (_ret834 == -1)
    return -1;
  const char *_arg839 = "/pwrite3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg839);
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
  const char *_arg842 = "/internal_write";
  const char *_arg843 = "new file contents";
  size_t _arg843_size = 17;
  int _ret841;
  _ret841 = guestfs_internal_write (g, _arg842, _arg843, _arg843_size);
  if (_ret841 == -1)
    return -1;
  const char *_arg845 = "/internal_write";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg845);
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
  const char *_arg848 = "/internal_write2";
  const char *_arg849 = "\nnew file contents\n";
  size_t _arg849_size = 19;
  int _ret847;
  _ret847 = guestfs_internal_write (g, _arg848, _arg849, _arg849_size);
  if (_ret847 == -1)
    return -1;
  const char *_arg851 = "/internal_write2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg851);
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
  const char *_arg854 = "/internal_write3";
  const char *_arg855 = "\n\n";
  size_t _arg855_size = 2;
  int _ret853;
  _ret853 = guestfs_internal_write (g, _arg854, _arg855, _arg855_size);
  if (_ret853 == -1)
    return -1;
  const char *_arg857 = "/internal_write3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg857);
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
  const char *_arg860 = "/internal_write4";
  const char *_arg861 = "";
  size_t _arg861_size = 0;
  int _ret859;
  _ret859 = guestfs_internal_write (g, _arg860, _arg861, _arg861_size);
  if (_ret859 == -1)
    return -1;
  const char *_arg863 = "/internal_write4";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg863);
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
  const char *_arg866 = "/internal_write5";
  const char *_arg867 = "\n\n\n";
  size_t _arg867_size = 3;
  int _ret865;
  _ret865 = guestfs_internal_write (g, _arg866, _arg867, _arg867_size);
  if (_ret865 == -1)
    return -1;
  const char *_arg869 = "/internal_write5";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg869);
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
  const char *_arg872 = "/internal_write6";
  const char *_arg873 = "\n";
  size_t _arg873_size = 1;
  int _ret871;
  _ret871 = guestfs_internal_write (g, _arg872, _arg873, _arg873_size);
  if (_ret871 == -1)
    return -1;
  const char *_arg875 = "/internal_write6";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg875);
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
  const char *_arg877 = "abcdefghijklmnopqrstuvwxyz";
  const char *_arg879 = "/fill_pattern";
  int ret1;
  ret1 = guestfs_fill_pattern (g, _arg877, 28, _arg879);
  if (ret1 == -1)
    return -1;
  const char *_arg881 = "/fill_pattern";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg881, &size);
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
  CLEANUP_FREE char *_arg884 = substitute_srcdir ("../data/hello.b64");
  const char *_arg885 = "/base64_in";
  int _ret883;
  _ret883 = guestfs_base64_in (g, _arg884, _arg885);
  if (_ret883 == -1)
    return -1;
  const char *_arg887 = "/base64_in";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg887);
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

  const char *_features890[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features890)) {
    skipped ("test_lvresize_free_0", "group %s not available in daemon",
             _features890[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for lvresize_free (0) */
  const char *_arg892 = "/dev/sda";
  const char *_arg893 = "mbr";
  int _ret891;
  _ret891 = guestfs_part_disk (g, _arg892, _arg893);
  if (_ret891 == -1)
    return -1;
  const char *_arg896 = "/dev/sda1";
  int _ret895;
  _ret895 = guestfs_pvcreate (g, _arg896);
  if (_ret895 == -1)
    return -1;
  const char *_arg899 = "VG";
  const char *_arg900_0 = "/dev/sda1";
  const char *const _arg900[] = {
    _arg900_0,
    NULL
  };
  int _ret898;
  _ret898 = guestfs_vgcreate (g, _arg899, (char **) _arg900);
  if (_ret898 == -1)
    return -1;
  const char *_arg903 = "LV";
  const char *_arg904 = "VG";
  int _ret902;
  _ret902 = guestfs_lvcreate (g, _arg903, _arg904, 10);
  if (_ret902 == -1)
    return -1;
  const char *_arg908 = "/dev/VG/LV";
  int _ret907;
  _ret907 = guestfs_lvresize_free (g, _arg908, 100);
  if (_ret907 == -1)
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
  const char *_arg911 = "md5";
  const char *_arg912 = "/dev/sdd";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum_device (g, _arg911, _arg912);
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
  const char *_arg914 = "/dev/sda";
  const char *_arg915 = "mbr";
  int ret3;
  ret3 = guestfs_part_init (g, _arg914, _arg915);
  if (ret3 == -1)
    return -1;
  const char *_arg917 = "/dev/sda";
  const char *_arg918 = "primary";
  int ret2;
  ret2 = guestfs_part_add (g, _arg917, _arg918, 1, -1);
  if (ret2 == -1)
    return -1;
  const char *_arg922 = "/dev/sda";
  int ret1;
  ret1 = guestfs_part_set_mbr_id (g, _arg922, 1, 127);
  if (ret1 == -1)
    return -1;
  const char *_arg926 = "/dev/sda";
  int ret;
  ret = guestfs_part_get_mbr_id (g, _arg926, 1);
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
  const char *_arg930 = "/dev/sda";
  const char *_arg931 = "mbr";
  int _ret929;
  _ret929 = guestfs_part_init (g, _arg930, _arg931);
  if (_ret929 == -1)
    return -1;
  const char *_arg934 = "/dev/sda";
  const char *_arg935 = "primary";
  int _ret933;
  _ret933 = guestfs_part_add (g, _arg934, _arg935, 1, -1);
  if (_ret933 == -1)
    return -1;
  const char *_arg940 = "/dev/sda";
  int _ret939;
  _ret939 = guestfs_part_set_bootable (g, _arg940, 1, 1);
  if (_ret939 == -1)
    return -1;
  const char *_arg944 = "/dev/sda";
  int ret;
  ret = guestfs_part_get_bootable (g, _arg944, 1);
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
  const char *_arg948 = "/dev/sda";
  const char *_arg949 = "mbr";
  int _ret947;
  _ret947 = guestfs_part_init (g, _arg948, _arg949);
  if (_ret947 == -1)
    return -1;
  const char *_arg952 = "/dev/sda";
  const char *_arg953 = "primary";
  int _ret951;
  _ret951 = guestfs_part_add (g, _arg952, _arg953, 1, -1);
  if (_ret951 == -1)
    return -1;
  const char *_arg958 = "/dev/sda";
  int _ret957;
  _ret957 = guestfs_part_del (g, _arg958, 1);
  if (_ret957 == -1)
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
  int _ret961;
  _ret961 = guestfs_vgscan (g);
  if (_ret961 == -1)
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

  const char *_features963[] = { "xz", NULL };
  if (!guestfs_feature_available (g, (char **) _features963)) {
    skipped ("test_txz_in_0", "group %s not available in daemon",
             _features963[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for txz_in (0) */
  const char *_arg965 = "/txz_in";
  int _ret964;
  _ret964 = guestfs_mkdir (g, _arg965);
  if (_ret964 == -1)
    return -1;
  CLEANUP_FREE char *_arg968 = substitute_srcdir ("$srcdir/../data/helloworld.tar.xz");
  const char *_arg969 = "/txz_in";
  int _ret967;
  _ret967 = guestfs_txz_in (g, _arg968, _arg969);
  if (_ret967 == -1)
    return -1;
  const char *_arg971 = "/txz_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg971);
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
  const char *_arg974 = "/dev/VG/LV";
  int _ret973;
  _ret973 = guestfs_zero_device (g, _arg974);
  if (_ret973 == -1)
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
  const char *_arg976 = "/copy_size";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg976);
  if (ret3 == -1)
    return -1;
  const char *_arg978 = "/copy_size/src";
  const char *_arg979 = "hello, world";
  size_t _arg979_size = 12;
  int ret2;
  ret2 = guestfs_write (g, _arg978, _arg979, _arg979_size);
  if (ret2 == -1)
    return -1;
  const char *_arg981 = "/copy_size/src";
  const char *_arg982 = "/copy_size/dest";
  int ret1;
  ret1 = guestfs_copy_size (g, _arg981, _arg982, 5);
  if (ret1 == -1)
    return -1;
  const char *_arg985 = "/copy_size/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg985, &size);
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
  const char *_arg987 = "/initrd";
  const char *_arg988 = "known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_initrd_cat (g, _arg987, _arg988, &size);
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
  const char *_arg990 = "/";
  struct guestfs_umount_opts_argv _optargs991;
  _optargs991.force = 0;
  _optargs991.lazyunmount = 0;
  _optargs991.bitmask = UINT64_C(0x3);
  int ret5;
  ret5 = guestfs_umount_opts_argv (g, _arg990, &_optargs991);
  if (ret5 == -1)
    return -1;
  const char *_arg993_0 = "VG";
  const char *const _arg993[] = {
    _arg993_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vg_activate (g, 0, (char **) _arg993);
  if (ret4 == -1)
    return -1;
  const char *_arg995 = "VG";
  const char *_arg996 = "VG2";
  int ret3;
  ret3 = guestfs_vgrename (g, _arg995, _arg996);
  if (ret3 == -1)
    return -1;
  const char *_arg999_0 = "VG2";
  const char *const _arg999[] = {
    _arg999_0,
    NULL
  };
  int ret2;
  ret2 = guestfs_vg_activate (g, 1, (char **) _arg999);
  if (ret2 == -1)
    return -1;
  const char *_arg1001 = "/dev/VG2/LV";
  const char *_arg1002 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg1001, _arg1002);
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
  const char *_arg1005 = "/dev/VG/LV";
  const char *_arg1006 = "/dev/VG/LV2";
  int ret1;
  ret1 = guestfs_lvrename (g, _arg1005, _arg1006);
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
  const char *_arg1009 = "/filesize";
  const char *_arg1010 = "hello, world";
  size_t _arg1010_size = 12;
  int ret1;
  ret1 = guestfs_write (g, _arg1009, _arg1010, _arg1010_size);
  if (ret1 == -1)
    return -1;
  const char *_arg1012 = "/filesize";
  int64_t ret;
  ret = guestfs_filesize (g, _arg1012);
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
  const char *_arg1014 = "/dd";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg1014);
  if (ret3 == -1)
    return -1;
  const char *_arg1016 = "/dd/src";
  const char *_arg1017 = "hello, world";
  size_t _arg1017_size = 12;
  int ret2;
  ret2 = guestfs_write (g, _arg1016, _arg1017, _arg1017_size);
  if (ret2 == -1)
    return -1;
  const char *_arg1019 = "/dd/src";
  const char *_arg1020 = "/dd/dest";
  int ret1;
  ret1 = guestfs_dd (g, _arg1019, _arg1020);
  if (ret1 == -1)
    return -1;
  const char *_arg1022 = "/dd/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg1022, &size);
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
  const char *const _arg1025[1] = { NULL };
  int _ret1024;
  _ret1024 = guestfs_available (g, (char **) _arg1025);
  if (_ret1024 == -1)
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
  const char *_arg1029 = "/fill";
  int ret1;
  ret1 = guestfs_fill (g, 99, 10, _arg1029);
  if (ret1 == -1)
    return -1;
  const char *_arg1031 = "/fill";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg1031, &size);
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
  const char *_arg1034 = "/dev/sda";
  const char *_arg1035 = "gpt";
  int _ret1033;
  _ret1033 = guestfs_part_disk (g, _arg1034, _arg1035);
  if (_ret1033 == -1)
    return -1;
  const char *_arg1037 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_parttype (g, _arg1037);
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
  const char *_arg1040 = "/dev/sda";
  const char *_arg1041 = "gpt";
  int _ret1039;
  _ret1039 = guestfs_part_disk (g, _arg1040, _arg1041);
  if (_ret1039 == -1)
    return -1;
  const char *_arg1044 = "/dev/sda";
  const char *_arg1046 = "thepartname";
  int _ret1043;
  _ret1043 = guestfs_part_set_name (g, _arg1044, 1, _arg1046);
  if (_ret1043 == -1)
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
  const char *_arg1049 = "/dev/sda";
  const char *_arg1050 = "mbr";
  int _ret1048;
  _ret1048 = guestfs_part_disk (g, _arg1049, _arg1050);
  if (_ret1048 == -1)
    return -1;
  const char *_arg1053 = "/dev/sda";
  int _ret1052;
  _ret1052 = guestfs_part_set_bootable (g, _arg1053, 1, 1);
  if (_ret1052 == -1)
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
  const char *_arg1058 = "/dev/sda";
  const char *_arg1059 = "mbr";
  int _ret1057;
  _ret1057 = guestfs_part_disk (g, _arg1058, _arg1059);
  if (_ret1057 == -1)
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
  const char *_arg1062 = "/dev/sda";
  const char *_arg1063 = "gpt";
  int _ret1061;
  _ret1061 = guestfs_part_disk (g, _arg1062, _arg1063);
  if (_ret1061 == -1)
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
  const char *_arg1066 = "/dev/sda";
  const char *_arg1067 = "mbr";
  int _ret1065;
  _ret1065 = guestfs_part_init (g, _arg1066, _arg1067);
  if (_ret1065 == -1)
    return -1;
  const char *_arg1070 = "/dev/sda";
  const char *_arg1071 = "primary";
  int _ret1069;
  _ret1069 = guestfs_part_add (g, _arg1070, _arg1071, 1, -1);
  if (_ret1069 == -1)
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
  const char *_arg1076 = "/dev/sda";
  const char *_arg1077 = "gpt";
  int _ret1075;
  _ret1075 = guestfs_part_init (g, _arg1076, _arg1077);
  if (_ret1075 == -1)
    return -1;
  const char *_arg1080 = "/dev/sda";
  const char *_arg1081 = "primary";
  int _ret1079;
  _ret1079 = guestfs_part_add (g, _arg1080, _arg1081, 34, 127);
  if (_ret1079 == -1)
    return -1;
  const char *_arg1086 = "/dev/sda";
  const char *_arg1087 = "primary";
  int _ret1085;
  _ret1085 = guestfs_part_add (g, _arg1086, _arg1087, 128, -34);
  if (_ret1085 == -1)
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
  const char *_arg1092 = "/dev/sda";
  const char *_arg1093 = "mbr";
  int _ret1091;
  _ret1091 = guestfs_part_init (g, _arg1092, _arg1093);
  if (_ret1091 == -1)
    return -1;
  const char *_arg1096 = "/dev/sda";
  const char *_arg1097 = "primary";
  int _ret1095;
  _ret1095 = guestfs_part_add (g, _arg1096, _arg1097, 32, 127);
  if (_ret1095 == -1)
    return -1;
  const char *_arg1102 = "/dev/sda";
  const char *_arg1103 = "primary";
  int _ret1101;
  _ret1101 = guestfs_part_add (g, _arg1102, _arg1103, 128, 255);
  if (_ret1101 == -1)
    return -1;
  const char *_arg1108 = "/dev/sda";
  const char *_arg1109 = "primary";
  int _ret1107;
  _ret1107 = guestfs_part_add (g, _arg1108, _arg1109, 256, 511);
  if (_ret1107 == -1)
    return -1;
  const char *_arg1114 = "/dev/sda";
  const char *_arg1115 = "primary";
  int _ret1113;
  _ret1113 = guestfs_part_add (g, _arg1114, _arg1115, 512, -1);
  if (_ret1113 == -1)
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
  const char *_arg1120 = "/dev/sda";
  const char *_arg1121 = "gpt";
  int _ret1119;
  _ret1119 = guestfs_part_init (g, _arg1120, _arg1121);
  if (_ret1119 == -1)
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
  const char *_arg1123 = "/known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread (g, _arg1123, 1, 3, &size);
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
  const char *_arg1127 = "/empty";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread (g, _arg1127, 0, 100, &size);
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
  const char *_arg1131 = "/mkdir_mode";
  int ret1;
  ret1 = guestfs_mkdir_mode (g, _arg1131, 73);
  if (ret1 == -1)
    return -1;
  const char *_arg1134 = "/mkdir_mode";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1134);
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
  const char *_arg1136 = "/utimens-file";
  int ret2;
  ret2 = guestfs_touch (g, _arg1136);
  if (ret2 == -1)
    return -1;
  const char *_arg1138 = "/utimens-file";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1138, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1144 = "/utimens-file";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1144);
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
  const char *_arg1146 = "/utimens-dir";
  int ret2;
  ret2 = guestfs_mkdir (g, _arg1146);
  if (ret2 == -1)
    return -1;
  const char *_arg1148 = "/utimens-dir";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1148, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1154 = "/utimens-dir";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1154);
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
  const char *_arg1157 = "/utimens-fifo";
  int ret2;
  ret2 = guestfs_mkfifo (g, 420, _arg1157);
  if (ret2 == -1)
    return -1;
  const char *_arg1159 = "/utimens-fifo";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1159, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1165 = "/utimens-fifo";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1165);
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
  const char *_arg1167 = "/utimens-file";
  const char *_arg1168 = "/utimens-link";
  int ret2;
  ret2 = guestfs_ln_sf (g, _arg1167, _arg1168);
  if (ret2 == -1)
    return -1;
  const char *_arg1170 = "/utimens-link";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1170, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1176 = "/utimens-link";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1176);
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
  const char *_arg1181 = "/utimens-block";
  int ret2;
  ret2 = guestfs_mknod_b (g, 420, 8, 0, _arg1181);
  if (ret2 == -1)
    return -1;
  const char *_arg1183 = "/utimens-block";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1183, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1189 = "/utimens-block";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1189);
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
  const char *_arg1194 = "/utimens-char";
  int ret2;
  ret2 = guestfs_mknod_c (g, 420, 1, 3, _arg1194);
  if (ret2 == -1)
    return -1;
  const char *_arg1196 = "/utimens-char";
  int ret1;
  ret1 = guestfs_utimens (g, _arg1196, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg1202 = "/utimens-char";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1202);
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
  const char *_arg1204 = "/truncate_size";
  int ret2;
  ret2 = guestfs_touch (g, _arg1204);
  if (ret2 == -1)
    return -1;
  const char *_arg1206 = "/truncate_size";
  int ret1;
  ret1 = guestfs_truncate_size (g, _arg1206, 1000);
  if (ret1 == -1)
    return -1;
  const char *_arg1209 = "/truncate_size";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1209);
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
  const char *_arg1211 = "/truncate";
  const char *_arg1212 = "some stuff so size is not zero";
  size_t _arg1212_size = 30;
  int ret2;
  ret2 = guestfs_write (g, _arg1211, _arg1212, _arg1212_size);
  if (ret2 == -1)
    return -1;
  const char *_arg1214 = "/truncate";
  int ret1;
  ret1 = guestfs_truncate (g, _arg1214);
  if (ret1 == -1)
    return -1;
  const char *_arg1216 = "/truncate";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1216);
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
  const char *_arg1218 = "/dev/sdb1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_type (g, _arg1218);
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
  const char *_arg1220 = "/DIRECTORY";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1220);
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
  const char *_arg1222 = "/DIRECTORY/";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1222);
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
  const char *_arg1224 = "/Known-1";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1224);
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
  const char *_arg1227 = "/Known-1/";
  CLEANUP_FREE char *_ret1226;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1226 = guestfs_case_sensitive_path (g, _arg1227);
  guestfs_pop_error_handler (g);
  if (_ret1226 != NULL)
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
  const char *_arg1230 = "/case_sensitive_path";
  int _ret1229;
  _ret1229 = guestfs_mkdir (g, _arg1230);
  if (_ret1229 == -1)
    return -1;
  const char *_arg1233 = "/case_sensitive_path/bbb";
  int _ret1232;
  _ret1232 = guestfs_mkdir (g, _arg1233);
  if (_ret1232 == -1)
    return -1;
  const char *_arg1236 = "/case_sensitive_path/bbb/c";
  int _ret1235;
  _ret1235 = guestfs_touch (g, _arg1236);
  if (_ret1235 == -1)
    return -1;
  const char *_arg1238 = "/CASE_SENSITIVE_path/bbB/C";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1238);
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
  const char *_arg1241 = "/case_sensitive_path2";
  int _ret1240;
  _ret1240 = guestfs_mkdir (g, _arg1241);
  if (_ret1240 == -1)
    return -1;
  const char *_arg1244 = "/case_sensitive_path2/bbb";
  int _ret1243;
  _ret1243 = guestfs_mkdir (g, _arg1244);
  if (_ret1243 == -1)
    return -1;
  const char *_arg1247 = "/case_sensitive_path2/bbb/c";
  int _ret1246;
  _ret1246 = guestfs_touch (g, _arg1247);
  if (_ret1246 == -1)
    return -1;
  const char *_arg1249 = "/case_sensitive_PATH2////bbB/C";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1249);
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
  const char *_arg1252 = "/case_sensitive_path3";
  int _ret1251;
  _ret1251 = guestfs_mkdir (g, _arg1252);
  if (_ret1251 == -1)
    return -1;
  const char *_arg1255 = "/case_sensitive_path3/bbb";
  int _ret1254;
  _ret1254 = guestfs_mkdir (g, _arg1255);
  if (_ret1254 == -1)
    return -1;
  const char *_arg1258 = "/case_sensitive_path3/bbb/c";
  int _ret1257;
  _ret1257 = guestfs_touch (g, _arg1258);
  if (_ret1257 == -1)
    return -1;
  const char *_arg1261 = "/case_SENSITIVE_path3/bbb/../bbb/C";
  CLEANUP_FREE char *_ret1260;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1260 = guestfs_case_sensitive_path (g, _arg1261);
  guestfs_pop_error_handler (g);
  if (_ret1260 != NULL)
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
  const char *_arg1264 = "/case_sensitive_path4";
  int _ret1263;
  _ret1263 = guestfs_mkdir (g, _arg1264);
  if (_ret1263 == -1)
    return -1;
  const char *_arg1266 = "/case_SENSITIVE_path4/new_file";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg1266);
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
  const char *_arg1268_0 = "This";
  const char *_arg1268_1 = "is";
  const char *_arg1268_2 = "a";
  const char *_arg1268_3 = "test";
  const char *const _arg1268[] = {
    _arg1268_0,
    _arg1268_1,
    _arg1268_2,
    _arg1268_3,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_echo_daemon (g, (char **) _arg1268);
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

  const char *_features1270[] = { "linuxmodules", NULL };
  if (!guestfs_feature_available (g, (char **) _features1270)) {
    skipped ("test_modprobe_0", "group %s not available in daemon",
             _features1270[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for modprobe (0) */
  const char *_arg1272 = "fat";
  int _ret1271;
  _ret1271 = guestfs_modprobe (g, _arg1272);
  if (_ret1271 == -1)
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

  const char *_features1274[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1274)) {
    skipped ("test_mke2journal_U_0", "group %s not available in daemon",
             _features1274[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResultString for mke2journal_U (0) */
  const char *_arg1276 = "/dev/sda";
  const char *_arg1277 = "mbr";
  int _ret1275;
  _ret1275 = guestfs_part_init (g, _arg1276, _arg1277);
  if (_ret1275 == -1)
    return -1;
  const char *_arg1280 = "/dev/sda";
  const char *_arg1281 = "p";
  int _ret1279;
  _ret1279 = guestfs_part_add (g, _arg1280, _arg1281, 64, 204799);
  if (_ret1279 == -1)
    return -1;
  const char *_arg1286 = "/dev/sda";
  const char *_arg1287 = "p";
  int _ret1285;
  _ret1285 = guestfs_part_add (g, _arg1286, _arg1287, 204800, -64);
  if (_ret1285 == -1)
    return -1;
  const char *_arg1293 = "c70c615b-388c-4537-5d08-73fd30081170";
  const char *_arg1294 = "/dev/sda1";
  int _ret1291;
  _ret1291 = guestfs_mke2journal_U (g, 4096, _arg1293, _arg1294);
  if (_ret1291 == -1)
    return -1;
  const char *_arg1297 = "ext2";
  const char *_arg1299 = "/dev/sda2";
  const char *_arg1300 = "c70c615b-388c-4537-5d08-73fd30081170";
  int _ret1296;
  _ret1296 = guestfs_mke2fs_JU (g, _arg1297, 4096, _arg1299, _arg1300);
  if (_ret1296 == -1)
    return -1;
  const char *_arg1303 = "/dev/sda2";
  const char *_arg1304 = "/";
  int _ret1302;
  _ret1302 = guestfs_mount (g, _arg1303, _arg1304);
  if (_ret1302 == -1)
    return -1;
  const char *_arg1307 = "/new";
  const char *_arg1308 = "new file contents";
  size_t _arg1308_size = 17;
  int _ret1306;
  _ret1306 = guestfs_write (g, _arg1307, _arg1308, _arg1308_size);
  if (_ret1306 == -1)
    return -1;
  const char *_arg1310 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1310);
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
  const char *_arg1313 = "/dev/sda";
  const char *_arg1314 = "mbr";
  int _ret1312;
  _ret1312 = guestfs_part_init (g, _arg1313, _arg1314);
  if (_ret1312 == -1)
    return -1;
  const char *_arg1317 = "/dev/sda";
  const char *_arg1318 = "p";
  int _ret1316;
  _ret1316 = guestfs_part_add (g, _arg1317, _arg1318, 64, 204799);
  if (_ret1316 == -1)
    return -1;
  const char *_arg1323 = "/dev/sda";
  const char *_arg1324 = "p";
  int _ret1322;
  _ret1322 = guestfs_part_add (g, _arg1323, _arg1324, 204800, -64);
  if (_ret1322 == -1)
    return -1;
  const char *_arg1330 = "JOURNAL";
  const char *_arg1331 = "/dev/sda1";
  int _ret1328;
  _ret1328 = guestfs_mke2journal_L (g, 4096, _arg1330, _arg1331);
  if (_ret1328 == -1)
    return -1;
  const char *_arg1334 = "ext2";
  const char *_arg1336 = "/dev/sda2";
  const char *_arg1337 = "JOURNAL";
  int _ret1333;
  _ret1333 = guestfs_mke2fs_JL (g, _arg1334, 4096, _arg1336, _arg1337);
  if (_ret1333 == -1)
    return -1;
  const char *_arg1340 = "/dev/sda2";
  const char *_arg1341 = "/";
  int _ret1339;
  _ret1339 = guestfs_mount (g, _arg1340, _arg1341);
  if (_ret1339 == -1)
    return -1;
  const char *_arg1344 = "/new";
  const char *_arg1345 = "new file contents";
  size_t _arg1345_size = 17;
  int _ret1343;
  _ret1343 = guestfs_write (g, _arg1344, _arg1345, _arg1345_size);
  if (_ret1343 == -1)
    return -1;
  const char *_arg1347 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1347);
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
  const char *_arg1350 = "/dev/sda";
  const char *_arg1351 = "mbr";
  int _ret1349;
  _ret1349 = guestfs_part_init (g, _arg1350, _arg1351);
  if (_ret1349 == -1)
    return -1;
  const char *_arg1354 = "/dev/sda";
  const char *_arg1355 = "p";
  int _ret1353;
  _ret1353 = guestfs_part_add (g, _arg1354, _arg1355, 64, 204799);
  if (_ret1353 == -1)
    return -1;
  const char *_arg1360 = "/dev/sda";
  const char *_arg1361 = "p";
  int _ret1359;
  _ret1359 = guestfs_part_add (g, _arg1360, _arg1361, 204800, -64);
  if (_ret1359 == -1)
    return -1;
  const char *_arg1367 = "/dev/sda1";
  int _ret1365;
  _ret1365 = guestfs_mke2journal (g, 4096, _arg1367);
  if (_ret1365 == -1)
    return -1;
  const char *_arg1370 = "ext2";
  const char *_arg1372 = "/dev/sda2";
  const char *_arg1373 = "/dev/sda1";
  int _ret1369;
  _ret1369 = guestfs_mke2fs_J (g, _arg1370, 4096, _arg1372, _arg1373);
  if (_ret1369 == -1)
    return -1;
  const char *_arg1376 = "/dev/sda2";
  const char *_arg1377 = "/";
  int _ret1375;
  _ret1375 = guestfs_mount (g, _arg1376, _arg1377);
  if (_ret1375 == -1)
    return -1;
  const char *_arg1380 = "/new";
  const char *_arg1381 = "new file contents";
  size_t _arg1381_size = 17;
  int _ret1379;
  _ret1379 = guestfs_write (g, _arg1380, _arg1381, _arg1381_size);
  if (_ret1379 == -1)
    return -1;
  const char *_arg1383 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1383);
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
  const char *_arg1386 = "/dev/sda";
  const char *_arg1387 = "mbr";
  int _ret1385;
  _ret1385 = guestfs_part_disk (g, _arg1386, _arg1387);
  if (_ret1385 == -1)
    return -1;
  const char *_arg1390 = "ext2";
  const char *_arg1392 = "/dev/sda1";
  int _ret1389;
  _ret1389 = guestfs_mkfs_b (g, _arg1390, 4096, _arg1392);
  if (_ret1389 == -1)
    return -1;
  const char *_arg1395 = "/dev/sda1";
  const char *_arg1396 = "/";
  int _ret1394;
  _ret1394 = guestfs_mount (g, _arg1395, _arg1396);
  if (_ret1394 == -1)
    return -1;
  const char *_arg1399 = "/new";
  const char *_arg1400 = "new file contents";
  size_t _arg1400_size = 17;
  int _ret1398;
  _ret1398 = guestfs_write (g, _arg1399, _arg1400, _arg1400_size);
  if (_ret1398 == -1)
    return -1;
  const char *_arg1402 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1402);
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
  const char *_arg1405 = "/dev/sda";
  const char *_arg1406 = "mbr";
  int _ret1404;
  _ret1404 = guestfs_part_disk (g, _arg1405, _arg1406);
  if (_ret1404 == -1)
    return -1;
  const char *_arg1409 = "vfat";
  const char *_arg1411 = "/dev/sda1";
  int _ret1408;
  _ret1408 = guestfs_mkfs_b (g, _arg1409, 32768, _arg1411);
  if (_ret1408 == -1)
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
  const char *_arg1414 = "/dev/sda";
  const char *_arg1415 = "mbr";
  int _ret1413;
  _ret1413 = guestfs_part_disk (g, _arg1414, _arg1415);
  if (_ret1413 == -1)
    return -1;
  const char *_arg1418 = "vfat";
  const char *_arg1420 = "/dev/sda1";
  int _ret1417;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1417 = guestfs_mkfs_b (g, _arg1418, 32769, _arg1420);
  guestfs_pop_error_handler (g);
  if (_ret1417 != -1)
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
  const char *_arg1423 = "/dev/sda";
  const char *_arg1424 = "mbr";
  int _ret1422;
  _ret1422 = guestfs_part_disk (g, _arg1423, _arg1424);
  if (_ret1422 == -1)
    return -1;
  const char *_arg1427 = "vfat";
  const char *_arg1429 = "/dev/sda1";
  int _ret1426;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1426 = guestfs_mkfs_b (g, _arg1427, 33280, _arg1429);
  guestfs_pop_error_handler (g);
  if (_ret1426 != -1)
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

  const char *_features1431[] = { "ntfsprogs", NULL };
  if (!guestfs_feature_available (g, (char **) _features1431)) {
    skipped ("test_mkfs_b_4", "group %s not available in daemon",
             _features1431[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkfs_b (4) */
  const char *_arg1433 = "/dev/sda";
  const char *_arg1434 = "mbr";
  int _ret1432;
  _ret1432 = guestfs_part_disk (g, _arg1433, _arg1434);
  if (_ret1432 == -1)
    return -1;
  const char *_arg1437 = "ntfs";
  const char *_arg1439 = "/dev/sda1";
  int _ret1436;
  _ret1436 = guestfs_mkfs_b (g, _arg1437, 32768, _arg1439);
  if (_ret1436 == -1)
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

  const char *_features1441[] = { "inotify", NULL };
  if (!guestfs_feature_available (g, (char **) _features1441)) {
    skipped ("test_inotify_add_watch_0", "group %s not available in daemon",
             _features1441[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for inotify_add_watch (0) */
  const char *_arg1442 = "/inotify_add_watch";
  int ret5;
  ret5 = guestfs_mkdir (g, _arg1442);
  if (ret5 == -1)
    return -1;
  int ret4;
  ret4 = guestfs_inotify_init (g, 0);
  if (ret4 == -1)
    return -1;
  const char *_arg1446 = "/inotify_add_watch";
  int64_t ret3;
  ret3 = guestfs_inotify_add_watch (g, _arg1446, 1073741823);
  if (ret3 == -1)
    return -1;
  const char *_arg1449 = "/inotify_add_watch/a";
  int ret2;
  ret2 = guestfs_touch (g, _arg1449);
  if (ret2 == -1)
    return -1;
  const char *_arg1451 = "/inotify_add_watch/b";
  int ret1;
  ret1 = guestfs_touch (g, _arg1451);
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

  const char *_features1454[] = { "inotify", NULL };
  if (!guestfs_feature_available (g, (char **) _features1454)) {
    skipped ("test_inotify_init_0", "group %s not available in daemon",
             _features1454[0]);
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestRun for inotify_init (0) */
  int _ret1455;
  _ret1455 = guestfs_inotify_init (g, 0);
  if (_ret1455 == -1)
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
  const char *_arg1459 = "/mkswap_file";
  int _ret1458;
  _ret1458 = guestfs_fallocate (g, _arg1459, 8388608);
  if (_ret1458 == -1)
    return -1;
  const char *_arg1463 = "/mkswap_file";
  int _ret1462;
  _ret1462 = guestfs_mkswap_file (g, _arg1463);
  if (_ret1462 == -1)
    return -1;
  const char *_arg1466 = "/mkswap_file";
  int _ret1465;
  _ret1465 = guestfs_rm (g, _arg1466);
  if (_ret1465 == -1)
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

  const char *_features1468[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1468)) {
    skipped ("test_swapon_uuid_0", "group %s not available in daemon",
             _features1468[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for swapon_uuid (0) */
  const char *_arg1470 = "/dev/sdc";
  struct guestfs_mkswap_opts_argv _optargs1471;
  _optargs1471.uuid = "c70c615b-388c-4537-5d08-73fd30081170";
  _optargs1471.bitmask = UINT64_C(0x2);
  int _ret1469;
  _ret1469 = guestfs_mkswap_opts_argv (g, _arg1470, &_optargs1471);
  if (_ret1469 == -1)
    return -1;
  const char *_arg1473 = "c70c615b-388c-4537-5d08-73fd30081170";
  int _ret1472;
  _ret1472 = guestfs_swapon_uuid (g, _arg1473);
  if (_ret1472 == -1)
    return -1;
  const char *_arg1476 = "c70c615b-388c-4537-5d08-73fd30081170";
  int _ret1475;
  _ret1475 = guestfs_swapoff_uuid (g, _arg1476);
  if (_ret1475 == -1)
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
  const char *_arg1479 = "/dev/sda";
  const char *_arg1480 = "mbr";
  int _ret1478;
  _ret1478 = guestfs_part_disk (g, _arg1479, _arg1480);
  if (_ret1478 == -1)
    return -1;
  const char *_arg1483 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1484;
  _optargs1484.label = "swapit";
  _optargs1484.bitmask = UINT64_C(0x1);
  int _ret1482;
  _ret1482 = guestfs_mkswap_opts_argv (g, _arg1483, &_optargs1484);
  if (_ret1482 == -1)
    return -1;
  const char *_arg1486 = "swapit";
  int _ret1485;
  _ret1485 = guestfs_swapon_label (g, _arg1486);
  if (_ret1485 == -1)
    return -1;
  const char *_arg1489 = "swapit";
  int _ret1488;
  _ret1488 = guestfs_swapoff_label (g, _arg1489);
  if (_ret1488 == -1)
    return -1;
  const char *_arg1492 = "/dev/sda";
  int _ret1491;
  _ret1491 = guestfs_zero (g, _arg1492);
  if (_ret1491 == -1)
    return -1;
  const char *_arg1495 = "/dev/sda";
  int _ret1494;
  _ret1494 = guestfs_blockdev_rereadpt (g, _arg1495);
  if (_ret1494 == -1)
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
  const char *_arg1498 = "/swapon_file";
  int _ret1497;
  _ret1497 = guestfs_fallocate (g, _arg1498, 8388608);
  if (_ret1497 == -1)
    return -1;
  const char *_arg1502 = "/swapon_file";
  int _ret1501;
  _ret1501 = guestfs_mkswap_file (g, _arg1502);
  if (_ret1501 == -1)
    return -1;
  const char *_arg1505 = "/swapon_file";
  int _ret1504;
  _ret1504 = guestfs_swapon_file (g, _arg1505);
  if (_ret1504 == -1)
    return -1;
  const char *_arg1508 = "/swapon_file";
  int _ret1507;
  _ret1507 = guestfs_swapoff_file (g, _arg1508);
  if (_ret1507 == -1)
    return -1;
  const char *_arg1511 = "/swapon_file";
  int _ret1510;
  _ret1510 = guestfs_rm (g, _arg1511);
  if (_ret1510 == -1)
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
  const char *_arg1514 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1515;
  _optargs1515.bitmask = UINT64_C(0x0);
  int _ret1513;
  _ret1513 = guestfs_mkswap_opts_argv (g, _arg1514, &_optargs1515);
  if (_ret1513 == -1)
    return -1;
  const char *_arg1517 = "/dev/sda1";
  int _ret1516;
  _ret1516 = guestfs_swapon_device (g, _arg1517);
  if (_ret1516 == -1)
    return -1;
  const char *_arg1520 = "/dev/sda1";
  int _ret1519;
  _ret1519 = guestfs_swapoff_device (g, _arg1520);
  if (_ret1519 == -1)
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
  const char *_arg1522 = "/fallocate";
  int ret1;
  ret1 = guestfs_fallocate (g, _arg1522, 1000000);
  if (ret1 == -1)
    return -1;
  const char *_arg1525 = "/fallocate";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1525);
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
  const char *_arg1528 = "/ln_sf/b";
  int _ret1527;
  _ret1527 = guestfs_mkdir_p (g, _arg1528);
  if (_ret1527 == -1)
    return -1;
  const char *_arg1531 = "/ln_sf/b/c";
  int _ret1530;
  _ret1530 = guestfs_touch (g, _arg1531);
  if (_ret1530 == -1)
    return -1;
  const char *_arg1534 = "../d";
  const char *_arg1535 = "/ln_sf/b/c";
  int _ret1533;
  _ret1533 = guestfs_ln_sf (g, _arg1534, _arg1535);
  if (_ret1533 == -1)
    return -1;
  const char *_arg1537 = "/ln_sf/b/c";
  CLEANUP_FREE char *ret;
  ret = guestfs_readlink (g, _arg1537);
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
  const char *_arg1539 = "/ln_s";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg1539);
  if (ret3 == -1)
    return -1;
  const char *_arg1541 = "/ln_s/a";
  int ret2;
  ret2 = guestfs_touch (g, _arg1541);
  if (ret2 == -1)
    return -1;
  const char *_arg1543 = "a";
  const char *_arg1544 = "/ln_s/b";
  int ret1;
  ret1 = guestfs_ln_s (g, _arg1543, _arg1544);
  if (ret1 == -1)
    return -1;
  const char *_arg1546 = "/ln_s/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_lstat (g, _arg1546);
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
  const char *_arg1548 = "/ln_f";
  int ret4;
  ret4 = guestfs_mkdir (g, _arg1548);
  if (ret4 == -1)
    return -1;
  const char *_arg1550 = "/ln_f/a";
  int ret3;
  ret3 = guestfs_touch (g, _arg1550);
  if (ret3 == -1)
    return -1;
  const char *_arg1552 = "/ln_f/b";
  int ret2;
  ret2 = guestfs_touch (g, _arg1552);
  if (ret2 == -1)
    return -1;
  const char *_arg1554 = "/ln_f/a";
  const char *_arg1555 = "/ln_f/b";
  int ret1;
  ret1 = guestfs_ln_f (g, _arg1554, _arg1555);
  if (ret1 == -1)
    return -1;
  const char *_arg1557 = "/ln_f/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1557);
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
  const char *_arg1559 = "/ln";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg1559);
  if (ret3 == -1)
    return -1;
  const char *_arg1561 = "/ln/a";
  int ret2;
  ret2 = guestfs_touch (g, _arg1561);
  if (ret2 == -1)
    return -1;
  const char *_arg1563 = "/ln/a";
  const char *_arg1564 = "/ln/b";
  int ret1;
  ret1 = guestfs_ln (g, _arg1563, _arg1564);
  if (ret1 == -1)
    return -1;
  const char *_arg1566 = "/ln/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1566);
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

  const char *_features1568[] = { "realpath", NULL };
  if (!guestfs_feature_available (g, (char **) _features1568)) {
    skipped ("test_realpath_0", "group %s not available in daemon",
             _features1568[0]);
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  /* TestResultString for realpath (0) */
  const char *_arg1569 = "/../directory";
  CLEANUP_FREE char *ret;
  ret = guestfs_realpath (g, _arg1569);
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
  const char *_arg1571 = "abc";
  const char *_arg1572 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zfgrepi (g, _arg1571, _arg1572);
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
  const char *_arg1574 = "abc";
  const char *_arg1575 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zegrepi (g, _arg1574, _arg1575);
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
  const char *_arg1577 = "abc";
  const char *_arg1578 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zgrepi (g, _arg1577, _arg1578);
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
  const char *_arg1580 = "abc";
  const char *_arg1581 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zfgrep (g, _arg1580, _arg1581);
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
  const char *_arg1583 = "abc";
  const char *_arg1584 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zegrep (g, _arg1583, _arg1584);
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
  const char *_arg1586 = "abc";
  const char *_arg1587 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zgrep (g, _arg1586, _arg1587);
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
  const char *_arg1589 = "abc";
  const char *_arg1590 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_fgrepi (g, _arg1589, _arg1590);
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
  const char *_arg1592 = "abc";
  const char *_arg1593 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_egrepi (g, _arg1592, _arg1593);
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
  const char *_arg1595 = "abc";
  const char *_arg1596 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grepi (g, _arg1595, _arg1596);
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
  const char *_arg1598 = "abc";
  const char *_arg1599 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_fgrep (g, _arg1598, _arg1599);
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
  const char *_arg1601 = "abc";
  const char *_arg1602 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_egrep (g, _arg1601, _arg1602);
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
  const char *_arg1604 = "abc";
  const char *_arg1605 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1606;
  _optargs1606.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1604, _arg1605, &_optargs1606);
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
  const char *_arg1607 = "nomatch";
  const char *_arg1608 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1609;
  _optargs1609.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1607, _arg1608, &_optargs1609);
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
  const char *_arg1610 = "nomatch";
  const char *_arg1611 = "/abssymlink";
  struct guestfs_grep_opts_argv _optargs1612;
  _optargs1612.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1610, _arg1611, &_optargs1612);
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
  const char *_arg1613 = "abc";
  const char *_arg1614 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1615;
  _optargs1615.extended = 1;
  _optargs1615.bitmask = UINT64_C(0x1);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1613, _arg1614, &_optargs1615);
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
  const char *_arg1616 = "abc";
  const char *_arg1617 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1618;
  _optargs1618.fixed = 1;
  _optargs1618.bitmask = UINT64_C(0x2);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1616, _arg1617, &_optargs1618);
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
  const char *_arg1619 = "abc";
  const char *_arg1620 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1621;
  _optargs1621.insensitive = 1;
  _optargs1621.bitmask = UINT64_C(0x4);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1619, _arg1620, &_optargs1621);
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
  const char *_arg1622 = "abc";
  const char *_arg1623 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1624;
  _optargs1624.extended = 1;
  _optargs1624.insensitive = 1;
  _optargs1624.bitmask = UINT64_C(0x5);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1622, _arg1623, &_optargs1624);
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
  const char *_arg1625 = "abc";
  const char *_arg1626 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs1627;
  _optargs1627.fixed = 1;
  _optargs1627.insensitive = 1;
  _optargs1627.bitmask = UINT64_C(0x6);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1625, _arg1626, &_optargs1627);
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
  const char *_arg1628 = "abc";
  const char *_arg1629 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1630;
  _optargs1630.compressed = 1;
  _optargs1630.bitmask = UINT64_C(0x8);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1628, _arg1629, &_optargs1630);
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
  const char *_arg1631 = "abc";
  const char *_arg1632 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1633;
  _optargs1633.extended = 1;
  _optargs1633.compressed = 1;
  _optargs1633.bitmask = UINT64_C(0x9);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1631, _arg1632, &_optargs1633);
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
  const char *_arg1634 = "abc";
  const char *_arg1635 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1636;
  _optargs1636.fixed = 1;
  _optargs1636.compressed = 1;
  _optargs1636.bitmask = UINT64_C(0xa);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1634, _arg1635, &_optargs1636);
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
  const char *_arg1637 = "abc";
  const char *_arg1638 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1639;
  _optargs1639.insensitive = 1;
  _optargs1639.compressed = 1;
  _optargs1639.bitmask = UINT64_C(0xc);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1637, _arg1638, &_optargs1639);
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
  const char *_arg1640 = "abc";
  const char *_arg1641 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1642;
  _optargs1642.extended = 1;
  _optargs1642.insensitive = 1;
  _optargs1642.compressed = 1;
  _optargs1642.bitmask = UINT64_C(0xd);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1640, _arg1641, &_optargs1642);
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
  const char *_arg1643 = "abc";
  const char *_arg1644 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs1645;
  _optargs1645.fixed = 1;
  _optargs1645.insensitive = 1;
  _optargs1645.compressed = 1;
  _optargs1645.bitmask = UINT64_C(0xe);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg1643, _arg1644, &_optargs1645);
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

  const char *_features1648[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1648)) {
    skipped ("test_mknod_c_0", "group %s not available in daemon",
             _features1648[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mknod_c (0) */
  const char *_arg1652 = "/mknod_c";
  int ret1;
  ret1 = guestfs_mknod_c (g, 511, 99, 66, _arg1652);
  if (ret1 == -1)
    return -1;
  const char *_arg1654 = "/mknod_c";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1654);
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

  const char *_features1656[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1656)) {
    skipped ("test_mknod_b_0", "group %s not available in daemon",
             _features1656[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mknod_b (0) */
  const char *_arg1660 = "/mknod_b";
  int ret1;
  ret1 = guestfs_mknod_b (g, 511, 99, 66, _arg1660);
  if (ret1 == -1)
    return -1;
  const char *_arg1662 = "/mknod_b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1662);
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

  const char *_features1664[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1664)) {
    skipped ("test_mkfifo_0", "group %s not available in daemon",
             _features1664[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mkfifo (0) */
  const char *_arg1666 = "/mkfifo";
  int ret1;
  ret1 = guestfs_mkfifo (g, 511, _arg1666);
  if (ret1 == -1)
    return -1;
  const char *_arg1668 = "/mkfifo";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1668);
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

  const char *_features1670[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1670)) {
    skipped ("test_mknod_0", "group %s not available in daemon",
             _features1670[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mknod (0) */
  const char *_arg1674 = "/mknod";
  int ret1;
  ret1 = guestfs_mknod (g, 4607, 0, 0, _arg1674);
  if (ret1 == -1)
    return -1;
  const char *_arg1676 = "/mknod";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1676);
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

  const char *_features1678[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features1678)) {
    skipped ("test_mknod_1", "group %s not available in daemon",
             _features1678[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResult for mknod (1) */
  const char *_arg1682 = "/mknod2";
  int ret1;
  ret1 = guestfs_mknod (g, 25087, 66, 99, _arg1682);
  if (ret1 == -1)
    return -1;
  const char *_arg1684 = "/mknod2";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1684);
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

  const char *_features1686[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1686)) {
    skipped ("test_mkswap_U_0", "group %s not available in daemon",
             _features1686[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkswap_U (0) */
  const char *_arg1688 = "/dev/sda";
  const char *_arg1689 = "mbr";
  int _ret1687;
  _ret1687 = guestfs_part_disk (g, _arg1688, _arg1689);
  if (_ret1687 == -1)
    return -1;
  const char *_arg1692 = "c70c615b-388c-4537-5d08-73fd30081170";
  const char *_arg1693 = "/dev/sda1";
  int _ret1691;
  _ret1691 = guestfs_mkswap_U (g, _arg1692, _arg1693);
  if (_ret1691 == -1)
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
  const char *_arg1696 = "/dev/sda";
  const char *_arg1697 = "mbr";
  int _ret1695;
  _ret1695 = guestfs_part_disk (g, _arg1696, _arg1697);
  if (_ret1695 == -1)
    return -1;
  const char *_arg1700 = "hello";
  const char *_arg1701 = "/dev/sda1";
  int _ret1699;
  _ret1699 = guestfs_mkswap_L (g, _arg1700, _arg1701);
  if (_ret1699 == -1)
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
  const char *_arg1704 = "/dev/sda";
  const char *_arg1705 = "mbr";
  int _ret1703;
  _ret1703 = guestfs_part_disk (g, _arg1704, _arg1705);
  if (_ret1703 == -1)
    return -1;
  const char *_arg1708 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1709;
  _optargs1709.bitmask = UINT64_C(0x0);
  int _ret1707;
  _ret1707 = guestfs_mkswap_opts_argv (g, _arg1708, &_optargs1709);
  if (_ret1707 == -1)
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
  const char *_arg1711 = "/dev/sda";
  const char *_arg1712 = "mbr";
  int _ret1710;
  _ret1710 = guestfs_part_disk (g, _arg1711, _arg1712);
  if (_ret1710 == -1)
    return -1;
  const char *_arg1715 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1716;
  _optargs1716.label = "hello";
  _optargs1716.bitmask = UINT64_C(0x1);
  int _ret1714;
  _ret1714 = guestfs_mkswap_opts_argv (g, _arg1715, &_optargs1716);
  if (_ret1714 == -1)
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

  const char *_features1717[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1717)) {
    skipped ("test_mkswap_2", "group %s not available in daemon",
             _features1717[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkswap (2) */
  const char *_arg1719 = "/dev/sda";
  const char *_arg1720 = "mbr";
  int _ret1718;
  _ret1718 = guestfs_part_disk (g, _arg1719, _arg1720);
  if (_ret1718 == -1)
    return -1;
  const char *_arg1723 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1724;
  _optargs1724.uuid = "c70c615b-388c-4537-5d08-73fd30081170";
  _optargs1724.bitmask = UINT64_C(0x2);
  int _ret1722;
  _ret1722 = guestfs_mkswap_opts_argv (g, _arg1723, &_optargs1724);
  if (_ret1722 == -1)
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

  const char *_features1725[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features1725)) {
    skipped ("test_mkswap_3", "group %s not available in daemon",
             _features1725[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestRun for mkswap (3) */
  const char *_arg1727 = "/dev/sda";
  const char *_arg1728 = "mbr";
  int _ret1726;
  _ret1726 = guestfs_part_disk (g, _arg1727, _arg1728);
  if (_ret1726 == -1)
    return -1;
  const char *_arg1731 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs1732;
  _optargs1732.label = "hello";
  _optargs1732.uuid = "c70c615b-388c-4537-5d08-73fd30081170";
  _optargs1732.bitmask = UINT64_C(0x3);
  int _ret1730;
  _ret1730 = guestfs_mkswap_opts_argv (g, _arg1731, &_optargs1732);
  if (_ret1730 == -1)
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
  const char *_arg1733 = "/initrd";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_initrd_list (g, _arg1733);
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
  const char *_arg1735 = "/directory";
  int64_t ret;
  ret = guestfs_du (g, _arg1735);
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
  const char *_arg1738 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, 3, _arg1738);
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
  const char *_arg1741 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, -9998, _arg1741);
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
  const char *_arg1744 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, 0, _arg1744);
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
  const char *_arg1746 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail (g, _arg1746);
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
  const char *_arg1749 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, 3, _arg1749);
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
  const char *_arg1752 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, -9997, _arg1752);
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
  const char *_arg1755 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, 0, _arg1755);
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
  const char *_arg1757 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head (g, _arg1757);
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
  const char *_arg1759 = "/abssymlink";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head (g, _arg1759);
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
  const char *_arg1761 = "/100kallspaces";
  int ret;
  ret = guestfs_wc_c (g, _arg1761);
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
  const char *_arg1763 = "/10klines";
  int ret;
  ret = guestfs_wc_w (g, _arg1763);
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
  const char *_arg1765 = "/10klines";
  int ret;
  ret = guestfs_wc_l (g, _arg1765);
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
  const char *_arg1767 = "/abssymlink";
  int ret;
  ret = guestfs_wc_l (g, _arg1767);
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
  const char *_arg1770 = "/mkdtemp";
  int _ret1769;
  _ret1769 = guestfs_mkdir (g, _arg1770);
  if (_ret1769 == -1)
    return -1;
  const char *_arg1773 = "/mkdtemp/tmpXXXXXX";
  CLEANUP_FREE char *_ret1772;
  _ret1772 = guestfs_mkdtemp (g, _arg1773);
  if (_ret1772 == NULL)
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

  const char *_features1775[] = { "scrub", NULL };
  if (!guestfs_feature_available (g, (char **) _features1775)) {
    skipped ("test_scrub_file_0", "group %s not available in daemon",
             _features1775[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestRun for scrub_file (0) */
  const char *_arg1777 = "/scrub_file";
  const char *_arg1778 = "content";
  size_t _arg1778_size = 7;
  int _ret1776;
  _ret1776 = guestfs_write (g, _arg1777, _arg1778, _arg1778_size);
  if (_ret1776 == -1)
    return -1;
  const char *_arg1781 = "/scrub_file";
  int _ret1780;
  _ret1780 = guestfs_scrub_file (g, _arg1781);
  if (_ret1780 == -1)
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

  const char *_features1783[] = { "scrub", NULL };
  if (!guestfs_feature_available (g, (char **) _features1783)) {
    skipped ("test_scrub_device_0", "group %s not available in daemon",
             _features1783[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for scrub_device (0) */
  const char *_arg1785 = "/dev/sdc";
  int _ret1784;
  _ret1784 = guestfs_scrub_device (g, _arg1785);
  if (_ret1784 == -1)
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
  const char *_arg1787 = "/glob_expand/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, _arg1787);
  if (ret3 == -1)
    return -1;
  const char *_arg1789 = "/glob_expand/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, _arg1789);
  if (ret2 == -1)
    return -1;
  const char *_arg1791 = "/glob_expand/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, _arg1791);
  if (ret1 == -1)
    return -1;
  const char *_arg1793 = "/glob_expand/b/c/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, _arg1793);
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
  const char *_arg1795 = "/glob_expand2/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, _arg1795);
  if (ret3 == -1)
    return -1;
  const char *_arg1797 = "/glob_expand2/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, _arg1797);
  if (ret2 == -1)
    return -1;
  const char *_arg1799 = "/glob_expand2/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, _arg1799);
  if (ret1 == -1)
    return -1;
  const char *_arg1801 = "/glob_expand2/*/c/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, _arg1801);
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
  const char *_arg1803 = "/glob_expand3/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, _arg1803);
  if (ret3 == -1)
    return -1;
  const char *_arg1805 = "/glob_expand3/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, _arg1805);
  if (ret2 == -1)
    return -1;
  const char *_arg1807 = "/glob_expand3/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, _arg1807);
  if (ret1 == -1)
    return -1;
  const char *_arg1809 = "/glob_expand3/*/x/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, _arg1809);
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

  const char *_features1811[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features1811)) {
    skipped ("test_ntfs_3g_probe_0", "group %s not available in daemon",
             _features1811[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResult for ntfs_3g_probe (0) */
  const char *_arg1812 = "/dev/sda";
  const char *_arg1813 = "mbr";
  int ret2;
  ret2 = guestfs_part_disk (g, _arg1812, _arg1813);
  if (ret2 == -1)
    return -1;
  const char *_arg1815 = "ntfs";
  const char *_arg1816 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1817;
  _optargs1817.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_mkfs_opts_argv (g, _arg1815, _arg1816, &_optargs1817);
  if (ret1 == -1)
    return -1;
  const char *_arg1819 = "/dev/sda1";
  int ret;
  ret = guestfs_ntfs_3g_probe (g, 1, _arg1819);
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

  const char *_features1821[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features1821)) {
    skipped ("test_ntfs_3g_probe_1", "group %s not available in daemon",
             _features1821[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResult for ntfs_3g_probe (1) */
  const char *_arg1822 = "/dev/sda";
  const char *_arg1823 = "mbr";
  int ret2;
  ret2 = guestfs_part_disk (g, _arg1822, _arg1823);
  if (ret2 == -1)
    return -1;
  const char *_arg1825 = "ext2";
  const char *_arg1826 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1827;
  _optargs1827.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_mkfs_opts_argv (g, _arg1825, _arg1826, &_optargs1827);
  if (ret1 == -1)
    return -1;
  const char *_arg1829 = "/dev/sda1";
  int ret;
  ret = guestfs_ntfs_3g_probe (g, 1, _arg1829);
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
  int _ret1831;
  _ret1831 = guestfs_sleep (g, 1);
  if (_ret1831 == -1)
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

  const char *_features1834[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features1834)) {
    skipped ("test_lvresize_0", "group %s not available in daemon",
             _features1834[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultString for lvresize (0) */
  const char *_arg1836 = "/dev/sda";
  const char *_arg1837 = "mbr";
  int _ret1835;
  _ret1835 = guestfs_part_disk (g, _arg1836, _arg1837);
  if (_ret1835 == -1)
    return -1;
  const char *_arg1840 = "/dev/sda1";
  int _ret1839;
  _ret1839 = guestfs_pvcreate (g, _arg1840);
  if (_ret1839 == -1)
    return -1;
  const char *_arg1843 = "VG";
  const char *_arg1844_0 = "/dev/sda1";
  const char *const _arg1844[] = {
    _arg1844_0,
    NULL
  };
  int _ret1842;
  _ret1842 = guestfs_vgcreate (g, _arg1843, (char **) _arg1844);
  if (_ret1842 == -1)
    return -1;
  const char *_arg1847 = "LV";
  const char *_arg1848 = "VG";
  int _ret1846;
  _ret1846 = guestfs_lvcreate (g, _arg1847, _arg1848, 10);
  if (_ret1846 == -1)
    return -1;
  const char *_arg1852 = "ext2";
  const char *_arg1853 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs1854;
  _optargs1854.bitmask = UINT64_C(0x0);
  int _ret1851;
  _ret1851 = guestfs_mkfs_opts_argv (g, _arg1852, _arg1853, &_optargs1854);
  if (_ret1851 == -1)
    return -1;
  const char *_arg1856 = "/dev/VG/LV";
  const char *_arg1857 = "/";
  int _ret1855;
  _ret1855 = guestfs_mount (g, _arg1856, _arg1857);
  if (_ret1855 == -1)
    return -1;
  const char *_arg1860 = "/new";
  const char *_arg1861 = "test content";
  size_t _arg1861_size = 12;
  int _ret1859;
  _ret1859 = guestfs_write (g, _arg1860, _arg1861, _arg1861_size);
  if (_ret1859 == -1)
    return -1;
  const char *_arg1864 = "/";
  struct guestfs_umount_opts_argv _optargs1865;
  _optargs1865.force = 0;
  _optargs1865.lazyunmount = 0;
  _optargs1865.bitmask = UINT64_C(0x3);
  int _ret1863;
  _ret1863 = guestfs_umount_opts_argv (g, _arg1864, &_optargs1865);
  if (_ret1863 == -1)
    return -1;
  const char *_arg1867 = "/dev/VG/LV";
  int _ret1866;
  _ret1866 = guestfs_lvresize (g, _arg1867, 20);
  if (_ret1866 == -1)
    return -1;
  const char *_arg1871 = "/dev/VG/LV";
  int _ret1870;
  _ret1870 = guestfs_e2fsck_f (g, _arg1871);
  if (_ret1870 == -1)
    return -1;
  const char *_arg1874 = "/dev/VG/LV";
  struct guestfs_e2fsck_argv _optargs1875;
  _optargs1875.correct = 1;
  _optargs1875.forceall = 0;
  _optargs1875.bitmask = UINT64_C(0x3);
  int _ret1873;
  _ret1873 = guestfs_e2fsck_argv (g, _arg1874, &_optargs1875);
  if (_ret1873 == -1)
    return -1;
  const char *_arg1877 = "/dev/VG/LV";
  struct guestfs_e2fsck_argv _optargs1878;
  _optargs1878.correct = 0;
  _optargs1878.forceall = 1;
  _optargs1878.bitmask = UINT64_C(0x3);
  int _ret1876;
  _ret1876 = guestfs_e2fsck_argv (g, _arg1877, &_optargs1878);
  if (_ret1876 == -1)
    return -1;
  const char *_arg1880 = "/dev/VG/LV";
  int _ret1879;
  _ret1879 = guestfs_resize2fs (g, _arg1880);
  if (_ret1879 == -1)
    return -1;
  const char *_arg1883 = "/dev/VG/LV";
  const char *_arg1884 = "/";
  int _ret1882;
  _ret1882 = guestfs_mount (g, _arg1883, _arg1884);
  if (_ret1882 == -1)
    return -1;
  const char *_arg1886 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1886);
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

  const char *_features1888[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features1888)) {
    skipped ("test_lvresize_1", "group %s not available in daemon",
             _features1888[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestRun for lvresize (1) */
  const char *_arg1890 = "/dev/sda";
  const char *_arg1891 = "mbr";
  int _ret1889;
  _ret1889 = guestfs_part_disk (g, _arg1890, _arg1891);
  if (_ret1889 == -1)
    return -1;
  const char *_arg1894 = "/dev/sda1";
  int _ret1893;
  _ret1893 = guestfs_pvcreate (g, _arg1894);
  if (_ret1893 == -1)
    return -1;
  const char *_arg1897 = "VG";
  const char *_arg1898_0 = "/dev/sda1";
  const char *const _arg1898[] = {
    _arg1898_0,
    NULL
  };
  int _ret1896;
  _ret1896 = guestfs_vgcreate (g, _arg1897, (char **) _arg1898);
  if (_ret1896 == -1)
    return -1;
  const char *_arg1901 = "LV";
  const char *_arg1902 = "VG";
  int _ret1900;
  _ret1900 = guestfs_lvcreate (g, _arg1901, _arg1902, 20);
  if (_ret1900 == -1)
    return -1;
  const char *_arg1906 = "/dev/VG/LV";
  int _ret1905;
  _ret1905 = guestfs_lvresize (g, _arg1906, 10);
  if (_ret1905 == -1)
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

  const char *_features1909[] = { "zerofree", NULL };
  if (!guestfs_feature_available (g, (char **) _features1909)) {
    skipped ("test_zerofree_0", "group %s not available in daemon",
             _features1909[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  /* TestResultString for zerofree (0) */
  const char *_arg1911 = "/dev/sda";
  const char *_arg1912 = "mbr";
  int _ret1910;
  _ret1910 = guestfs_part_disk (g, _arg1911, _arg1912);
  if (_ret1910 == -1)
    return -1;
  const char *_arg1915 = "ext3";
  const char *_arg1916 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1917;
  _optargs1917.bitmask = UINT64_C(0x0);
  int _ret1914;
  _ret1914 = guestfs_mkfs_opts_argv (g, _arg1915, _arg1916, &_optargs1917);
  if (_ret1914 == -1)
    return -1;
  const char *_arg1919 = "/dev/sda1";
  const char *_arg1920 = "/";
  int _ret1918;
  _ret1918 = guestfs_mount (g, _arg1919, _arg1920);
  if (_ret1918 == -1)
    return -1;
  const char *_arg1923 = "/new";
  const char *_arg1924 = "test file";
  size_t _arg1924_size = 9;
  int _ret1922;
  _ret1922 = guestfs_write (g, _arg1923, _arg1924, _arg1924_size);
  if (_ret1922 == -1)
    return -1;
  const char *_arg1927 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs1928;
  _optargs1928.force = 0;
  _optargs1928.lazyunmount = 0;
  _optargs1928.bitmask = UINT64_C(0x3);
  int _ret1926;
  _ret1926 = guestfs_umount_opts_argv (g, _arg1927, &_optargs1928);
  if (_ret1926 == -1)
    return -1;
  const char *_arg1930 = "/dev/sda1";
  int _ret1929;
  _ret1929 = guestfs_zerofree (g, _arg1930);
  if (_ret1929 == -1)
    return -1;
  const char *_arg1933 = "/dev/sda1";
  const char *_arg1934 = "/";
  int _ret1932;
  _ret1932 = guestfs_mount (g, _arg1933, _arg1934);
  if (_ret1932 == -1)
    return -1;
  const char *_arg1936 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1936);
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
  const char *_arg1938 = "/known-4";
  CLEANUP_FREE char *ret;
  ret = guestfs_hexdump (g, _arg1938);
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
  const char *_arg1941 = "/100krandom";
  CLEANUP_FREE char *_ret1940;
  _ret1940 = guestfs_hexdump (g, _arg1941);
  if (_ret1940 == NULL)
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
  const char *_arg1944 = "/abssymlink";
  CLEANUP_FREE char *_ret1943;
  _ret1943 = guestfs_hexdump (g, _arg1944);
  if (_ret1943 == NULL)
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
  const char *_arg1946 = "b";
  const char *_arg1947 = "/known-5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings_e (g, _arg1946, _arg1947);
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
  const char *_arg1949 = "/strings_e";
  const char *_arg1950 = "\0h\0e\0l\0l\0o\0\n\0w\0o\0r\0l\0d\0\n";
  size_t _arg1950_size = 24;
  int ret1;
  ret1 = guestfs_write (g, _arg1949, _arg1950, _arg1950_size);
  if (ret1 == -1)
    return -1;
  const char *_arg1952 = "b";
  const char *_arg1953 = "/strings_e";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings_e (g, _arg1952, _arg1953);
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
  const char *_arg1955 = "/known-5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings (g, _arg1955);
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
  const char *_arg1957 = "/empty";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings (g, _arg1957);
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
  const char *_arg1960 = "/abssymlink";
  CLEANUP_FREE_STRING_LIST char **_ret1959;
  _ret1959 = guestfs_strings (g, _arg1960);
  if (_ret1959 == NULL)
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
  const char *_arg1963 = "/equal";
  int _ret1962;
  _ret1962 = guestfs_mkdir (g, _arg1963);
  if (_ret1962 == -1)
    return -1;
  const char *_arg1966 = "/equal/file1";
  const char *_arg1967 = "contents of a file";
  size_t _arg1967_size = 18;
  int _ret1965;
  _ret1965 = guestfs_write (g, _arg1966, _arg1967, _arg1967_size);
  if (_ret1965 == -1)
    return -1;
  const char *_arg1970 = "/equal/file1";
  const char *_arg1971 = "/equal/file2";
  int _ret1969;
  _ret1969 = guestfs_cp (g, _arg1970, _arg1971);
  if (_ret1969 == -1)
    return -1;
  const char *_arg1973 = "/equal/file1";
  const char *_arg1974 = "/equal/file2";
  int ret;
  ret = guestfs_equal (g, _arg1973, _arg1974);
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
  const char *_arg1977 = "/equal2";
  int _ret1976;
  _ret1976 = guestfs_mkdir (g, _arg1977);
  if (_ret1976 == -1)
    return -1;
  const char *_arg1980 = "/equal2/file1";
  const char *_arg1981 = "contents of a file";
  size_t _arg1981_size = 18;
  int _ret1979;
  _ret1979 = guestfs_write (g, _arg1980, _arg1981, _arg1981_size);
  if (_ret1979 == -1)
    return -1;
  const char *_arg1984 = "/equal2/file2";
  const char *_arg1985 = "contents of another file";
  size_t _arg1985_size = 24;
  int _ret1983;
  _ret1983 = guestfs_write (g, _arg1984, _arg1985, _arg1985_size);
  if (_ret1983 == -1)
    return -1;
  const char *_arg1987 = "/equal2/file1";
  const char *_arg1988 = "/equal2/file2";
  int ret;
  ret = guestfs_equal (g, _arg1987, _arg1988);
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
  const char *_arg1991 = "/equal3";
  int _ret1990;
  _ret1990 = guestfs_mkdir (g, _arg1991);
  if (_ret1990 == -1)
    return -1;
  const char *_arg1994 = "/equal3/file1";
  const char *_arg1995 = "/equal3/file2";
  int _ret1993;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1993 = guestfs_equal (g, _arg1994, _arg1995);
  guestfs_pop_error_handler (g);
  if (_ret1993 != -1)
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
  int _ret1997;
  _ret1997 = guestfs_ping_daemon (g);
  if (_ret1997 == -1)
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
  CLEANUP_FREE char *_ret1999;
  _ret1999 = guestfs_dmesg (g);
  if (_ret1999 == NULL)
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
  int _ret2001;
  _ret2001 = guestfs_drop_caches (g, 3);
  if (_ret2001 == -1)
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
  const char *_arg2005 = "/mv";
  int _ret2004;
  _ret2004 = guestfs_mkdir (g, _arg2005);
  if (_ret2004 == -1)
    return -1;
  const char *_arg2008 = "/mv/old";
  const char *_arg2009 = "file content";
  size_t _arg2009_size = 12;
  int _ret2007;
  _ret2007 = guestfs_write (g, _arg2008, _arg2009, _arg2009_size);
  if (_ret2007 == -1)
    return -1;
  const char *_arg2012 = "/mv/old";
  const char *_arg2013 = "/mv/new";
  int _ret2011;
  _ret2011 = guestfs_mv (g, _arg2012, _arg2013);
  if (_ret2011 == -1)
    return -1;
  const char *_arg2015 = "/mv/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2015);
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
  const char *_arg2018 = "/mv2";
  int _ret2017;
  _ret2017 = guestfs_mkdir (g, _arg2018);
  if (_ret2017 == -1)
    return -1;
  const char *_arg2021 = "/mv2/old";
  const char *_arg2022 = "file content";
  size_t _arg2022_size = 12;
  int _ret2020;
  _ret2020 = guestfs_write (g, _arg2021, _arg2022, _arg2022_size);
  if (_ret2020 == -1)
    return -1;
  const char *_arg2025 = "/mv2/old";
  const char *_arg2026 = "/mv2/new";
  int _ret2024;
  _ret2024 = guestfs_mv (g, _arg2025, _arg2026);
  if (_ret2024 == -1)
    return -1;
  const char *_arg2028 = "/mv2/old";
  struct guestfs_is_file_opts_argv _optargs2029;
  _optargs2029.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, _arg2028, &_optargs2029);
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
  const char *_arg2031 = "/cp_a1";
  int _ret2030;
  _ret2030 = guestfs_mkdir (g, _arg2031);
  if (_ret2030 == -1)
    return -1;
  const char *_arg2034 = "/cp_a2";
  int _ret2033;
  _ret2033 = guestfs_mkdir (g, _arg2034);
  if (_ret2033 == -1)
    return -1;
  const char *_arg2037 = "/cp_a1/file";
  const char *_arg2038 = "file content";
  size_t _arg2038_size = 12;
  int _ret2036;
  _ret2036 = guestfs_write (g, _arg2037, _arg2038, _arg2038_size);
  if (_ret2036 == -1)
    return -1;
  const char *_arg2041 = "/cp_a1";
  const char *_arg2042 = "/cp_a2";
  int _ret2040;
  _ret2040 = guestfs_cp_a (g, _arg2041, _arg2042);
  if (_ret2040 == -1)
    return -1;
  const char *_arg2044 = "/cp_a2/cp_a1/file";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2044);
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
  const char *_arg2047 = "/cp";
  int _ret2046;
  _ret2046 = guestfs_mkdir (g, _arg2047);
  if (_ret2046 == -1)
    return -1;
  const char *_arg2050 = "/cp/old";
  const char *_arg2051 = "file content";
  size_t _arg2051_size = 12;
  int _ret2049;
  _ret2049 = guestfs_write (g, _arg2050, _arg2051, _arg2051_size);
  if (_ret2049 == -1)
    return -1;
  const char *_arg2054 = "/cp/old";
  const char *_arg2055 = "/cp/new";
  int _ret2053;
  _ret2053 = guestfs_cp (g, _arg2054, _arg2055);
  if (_ret2053 == -1)
    return -1;
  const char *_arg2057 = "/cp/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2057);
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
  const char *_arg2060 = "/cp2";
  int _ret2059;
  _ret2059 = guestfs_mkdir (g, _arg2060);
  if (_ret2059 == -1)
    return -1;
  const char *_arg2063 = "/cp2/old";
  const char *_arg2064 = "file content";
  size_t _arg2064_size = 12;
  int _ret2062;
  _ret2062 = guestfs_write (g, _arg2063, _arg2064, _arg2064_size);
  if (_ret2062 == -1)
    return -1;
  const char *_arg2067 = "/cp2/old";
  const char *_arg2068 = "/cp2/new";
  int _ret2066;
  _ret2066 = guestfs_cp (g, _arg2067, _arg2068);
  if (_ret2066 == -1)
    return -1;
  const char *_arg2070 = "/cp2/old";
  struct guestfs_is_file_opts_argv _optargs2071;
  _optargs2071.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, _arg2070, &_optargs2071);
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
  const char *_arg2073 = "/cp3";
  int _ret2072;
  _ret2072 = guestfs_mkdir (g, _arg2073);
  if (_ret2072 == -1)
    return -1;
  const char *_arg2076 = "/cp3/old";
  const char *_arg2077 = "file content";
  size_t _arg2077_size = 12;
  int _ret2075;
  _ret2075 = guestfs_write (g, _arg2076, _arg2077, _arg2077_size);
  if (_ret2075 == -1)
    return -1;
  const char *_arg2080 = "/cp3/dir";
  int _ret2079;
  _ret2079 = guestfs_mkdir (g, _arg2080);
  if (_ret2079 == -1)
    return -1;
  const char *_arg2083 = "/cp3/old";
  const char *_arg2084 = "/cp3/dir/new";
  int _ret2082;
  _ret2082 = guestfs_cp (g, _arg2083, _arg2084);
  if (_ret2082 == -1)
    return -1;
  const char *_arg2086 = "/cp3/dir/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2086);
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

  const char *_features2088[] = { "grub", NULL };
  if (!guestfs_feature_available (g, (char **) _features2088)) {
    skipped ("test_grub_install_0", "group %s not available in daemon",
             _features2088[0]);
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  /* TestResultTrue for grub_install (0) */
  const char *_arg2090 = "/boot/grub";
  int _ret2089;
  _ret2089 = guestfs_mkdir_p (g, _arg2090);
  if (_ret2089 == -1)
    return -1;
  const char *_arg2093 = "/boot/grub/device.map";
  const char *_arg2094 = "(hd0) /dev/sda";
  size_t _arg2094_size = 14;
  int _ret2092;
  _ret2092 = guestfs_write (g, _arg2093, _arg2094, _arg2094_size);
  if (_ret2092 == -1)
    return -1;
  const char *_arg2097 = "/";
  const char *_arg2098 = "/dev/sda";
  int _ret2096;
  _ret2096 = guestfs_grub_install (g, _arg2097, _arg2098);
  if (_ret2096 == -1)
    return -1;
  const char *_arg2100 = "/boot";
  struct guestfs_is_dir_opts_argv _optargs2101;
  _optargs2101.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2100, &_optargs2101);
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
  const char *_arg2103 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs2104;
  _optargs2104.force = 0;
  _optargs2104.lazyunmount = 0;
  _optargs2104.bitmask = UINT64_C(0x3);
  int _ret2102;
  _ret2102 = guestfs_umount_opts_argv (g, _arg2103, &_optargs2104);
  if (_ret2102 == -1)
    return -1;
  const char *_arg2106 = "/dev/sda1";
  int _ret2105;
  _ret2105 = guestfs_zero (g, _arg2106);
  if (_ret2105 == -1)
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
  const char *_arg2108 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs2109;
  _optargs2109.force = 0;
  _optargs2109.lazyunmount = 0;
  _optargs2109.bitmask = UINT64_C(0x3);
  int ret1;
  ret1 = guestfs_umount_opts_argv (g, _arg2108, &_optargs2109);
  if (ret1 == -1)
    return -1;
  const char *_arg2110 = "ext2";
  const char *_arg2111 = "/dev/sda1";
  int ret;
  ret = guestfs_fsck (g, _arg2110, _arg2111);
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
  const char *_arg2113 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs2114;
  _optargs2114.force = 0;
  _optargs2114.lazyunmount = 0;
  _optargs2114.bitmask = UINT64_C(0x3);
  int ret2;
  ret2 = guestfs_umount_opts_argv (g, _arg2113, &_optargs2114);
  if (ret2 == -1)
    return -1;
  const char *_arg2115 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_zero (g, _arg2115);
  if (ret1 == -1)
    return -1;
  const char *_arg2117 = "ext2";
  const char *_arg2118 = "/dev/sda1";
  int ret;
  ret = guestfs_fsck (g, _arg2117, _arg2118);
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
  const char *_arg2122 = "/dev/sdc";
  int _ret2120;
  _ret2120 = guestfs_mke2journal (g, 1024, _arg2122);
  if (_ret2120 == -1)
    return -1;
  const char *_arg2125 = "/dev/sdc";
  const char *_arg2126 = "c70c615b-388c-4537-5d08-73fd30081170";
  int _ret2124;
  _ret2124 = guestfs_set_e2uuid (g, _arg2125, _arg2126);
  if (_ret2124 == -1)
    return -1;
  const char *_arg2128 = "/dev/sdc";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, _arg2128);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "c70c615b-388c-4537-5d08-73fd30081170")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_get_e2uuid_0", "get_e2uuid", ret, "c70c615b-388c-4537-5d08-73fd30081170");
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
  const char *_arg2131 = "/dev/sda1";
  const char *_arg2132 = "c70c615b-388c-4537-5d08-73fd30081170";
  int _ret2130;
  _ret2130 = guestfs_set_e2uuid (g, _arg2131, _arg2132);
  if (_ret2130 == -1)
    return -1;
  const char *_arg2134 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, _arg2134);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "c70c615b-388c-4537-5d08-73fd30081170")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_e2uuid_0", "get_e2uuid", ret, "c70c615b-388c-4537-5d08-73fd30081170");
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
  const char *_arg2137 = "/dev/sda1";
  const char *_arg2138 = "clear";
  int _ret2136;
  _ret2136 = guestfs_set_e2uuid (g, _arg2137, _arg2138);
  if (_ret2136 == -1)
    return -1;
  const char *_arg2140 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, _arg2140);
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
  const char *_arg2143 = "/dev/sda1";
  const char *_arg2144 = "random";
  int _ret2142;
  _ret2142 = guestfs_set_e2uuid (g, _arg2143, _arg2144);
  if (_ret2142 == -1)
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
  const char *_arg2147 = "/dev/sda1";
  const char *_arg2148 = "time";
  int _ret2146;
  _ret2146 = guestfs_set_e2uuid (g, _arg2147, _arg2148);
  if (_ret2146 == -1)
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
  const char *_arg2151 = "/dev/sda1";
  const char *_arg2152 = "testlabel";
  int _ret2150;
  _ret2150 = guestfs_set_e2label (g, _arg2151, _arg2152);
  if (_ret2150 == -1)
    return -1;
  const char *_arg2154 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2label (g, _arg2154);
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

  const char *_features2156[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2156)) {
    skipped ("test_pvremove_0", "group %s not available in daemon",
             _features2156[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvremove (0) */
  const char *_arg2157 = "/dev/sda";
  const char *_arg2158 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg2157, _arg2158);
  if (ret7 == -1)
    return -1;
  const char *_arg2160 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg2160);
  if (ret6 == -1)
    return -1;
  const char *_arg2162 = "VG";
  const char *_arg2163_0 = "/dev/sda1";
  const char *const _arg2163[] = {
    _arg2163_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg2162, (char **) _arg2163);
  if (ret5 == -1)
    return -1;
  const char *_arg2165 = "LV1";
  const char *_arg2166 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg2165, _arg2166, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg2169 = "LV2";
  const char *_arg2170 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2169, _arg2170, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2173 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, _arg2173);
  if (ret2 == -1)
    return -1;
  const char *_arg2175 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, _arg2175);
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

  const char *_features2178[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2178)) {
    skipped ("test_pvremove_1", "group %s not available in daemon",
             _features2178[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvremove (1) */
  const char *_arg2179 = "/dev/sda";
  const char *_arg2180 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg2179, _arg2180);
  if (ret7 == -1)
    return -1;
  const char *_arg2182 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg2182);
  if (ret6 == -1)
    return -1;
  const char *_arg2184 = "VG";
  const char *_arg2185_0 = "/dev/sda1";
  const char *const _arg2185[] = {
    _arg2185_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg2184, (char **) _arg2185);
  if (ret5 == -1)
    return -1;
  const char *_arg2187 = "LV1";
  const char *_arg2188 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg2187, _arg2188, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg2191 = "LV2";
  const char *_arg2192 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2191, _arg2192, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2195 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, _arg2195);
  if (ret2 == -1)
    return -1;
  const char *_arg2197 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, _arg2197);
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

  const char *_features2200[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2200)) {
    skipped ("test_pvremove_2", "group %s not available in daemon",
             _features2200[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvremove (2) */
  const char *_arg2201 = "/dev/sda";
  const char *_arg2202 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg2201, _arg2202);
  if (ret7 == -1)
    return -1;
  const char *_arg2204 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg2204);
  if (ret6 == -1)
    return -1;
  const char *_arg2206 = "VG";
  const char *_arg2207_0 = "/dev/sda1";
  const char *const _arg2207[] = {
    _arg2207_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg2206, (char **) _arg2207);
  if (ret5 == -1)
    return -1;
  const char *_arg2209 = "LV1";
  const char *_arg2210 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg2209, _arg2210, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg2213 = "LV2";
  const char *_arg2214 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2213, _arg2214, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2217 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, _arg2217);
  if (ret2 == -1)
    return -1;
  const char *_arg2219 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, _arg2219);
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

  const char *_features2222[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2222)) {
    skipped ("test_vgremove_0", "group %s not available in daemon",
             _features2222[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for vgremove (0) */
  const char *_arg2223 = "/dev/sda";
  const char *_arg2224 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2223, _arg2224);
  if (ret6 == -1)
    return -1;
  const char *_arg2226 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2226);
  if (ret5 == -1)
    return -1;
  const char *_arg2228 = "VG";
  const char *_arg2229_0 = "/dev/sda1";
  const char *const _arg2229[] = {
    _arg2229_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2228, (char **) _arg2229);
  if (ret4 == -1)
    return -1;
  const char *_arg2231 = "LV1";
  const char *_arg2232 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2231, _arg2232, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2235 = "LV2";
  const char *_arg2236 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2235, _arg2236, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2239 = "VG";
  int ret1;
  ret1 = guestfs_vgremove (g, _arg2239);
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

  const char *_features2242[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2242)) {
    skipped ("test_vgremove_1", "group %s not available in daemon",
             _features2242[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for vgremove (1) */
  const char *_arg2243 = "/dev/sda";
  const char *_arg2244 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2243, _arg2244);
  if (ret6 == -1)
    return -1;
  const char *_arg2246 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2246);
  if (ret5 == -1)
    return -1;
  const char *_arg2248 = "VG";
  const char *_arg2249_0 = "/dev/sda1";
  const char *const _arg2249[] = {
    _arg2249_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2248, (char **) _arg2249);
  if (ret4 == -1)
    return -1;
  const char *_arg2251 = "LV1";
  const char *_arg2252 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2251, _arg2252, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2255 = "LV2";
  const char *_arg2256 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2255, _arg2256, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2259 = "VG";
  int ret1;
  ret1 = guestfs_vgremove (g, _arg2259);
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

  const char *_features2262[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2262)) {
    skipped ("test_lvremove_0", "group %s not available in daemon",
             _features2262[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvremove (0) */
  const char *_arg2263 = "/dev/sda";
  const char *_arg2264 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2263, _arg2264);
  if (ret6 == -1)
    return -1;
  const char *_arg2266 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2266);
  if (ret5 == -1)
    return -1;
  const char *_arg2268 = "VG";
  const char *_arg2269_0 = "/dev/sda1";
  const char *const _arg2269[] = {
    _arg2269_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2268, (char **) _arg2269);
  if (ret4 == -1)
    return -1;
  const char *_arg2271 = "LV1";
  const char *_arg2272 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2271, _arg2272, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2275 = "LV2";
  const char *_arg2276 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2275, _arg2276, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2279 = "/dev/VG/LV1";
  int ret1;
  ret1 = guestfs_lvremove (g, _arg2279);
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

  const char *_features2282[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2282)) {
    skipped ("test_lvremove_1", "group %s not available in daemon",
             _features2282[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvremove (1) */
  const char *_arg2283 = "/dev/sda";
  const char *_arg2284 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2283, _arg2284);
  if (ret6 == -1)
    return -1;
  const char *_arg2286 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2286);
  if (ret5 == -1)
    return -1;
  const char *_arg2288 = "VG";
  const char *_arg2289_0 = "/dev/sda1";
  const char *const _arg2289[] = {
    _arg2289_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2288, (char **) _arg2289);
  if (ret4 == -1)
    return -1;
  const char *_arg2291 = "LV1";
  const char *_arg2292 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2291, _arg2292, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2295 = "LV2";
  const char *_arg2296 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2295, _arg2296, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2299 = "/dev/VG";
  int ret1;
  ret1 = guestfs_lvremove (g, _arg2299);
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

  const char *_features2302[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2302)) {
    skipped ("test_lvremove_2", "group %s not available in daemon",
             _features2302[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvremove (2) */
  const char *_arg2303 = "/dev/sda";
  const char *_arg2304 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg2303, _arg2304);
  if (ret6 == -1)
    return -1;
  const char *_arg2306 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2306);
  if (ret5 == -1)
    return -1;
  const char *_arg2308 = "VG";
  const char *_arg2309_0 = "/dev/sda1";
  const char *const _arg2309[] = {
    _arg2309_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg2308, (char **) _arg2309);
  if (ret4 == -1)
    return -1;
  const char *_arg2311 = "LV1";
  const char *_arg2312 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2311, _arg2312, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2315 = "LV2";
  const char *_arg2316 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2315, _arg2316, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2319 = "/dev/VG";
  int ret1;
  ret1 = guestfs_lvremove (g, _arg2319);
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
  const char *_arg2323 = "/";
  struct guestfs_umount_opts_argv _optargs2324;
  _optargs2324.force = 0;
  _optargs2324.lazyunmount = 0;
  _optargs2324.bitmask = UINT64_C(0x3);
  int _ret2322;
  _ret2322 = guestfs_umount_opts_argv (g, _arg2323, &_optargs2324);
  if (_ret2322 == -1)
    return -1;
  const char *_arg2326 = "/dev/sda1";
  const char *_arg2327 = "/";
  int _ret2325;
  _ret2325 = guestfs_mount_ro (g, _arg2326, _arg2327);
  if (_ret2325 == -1)
    return -1;
  const char *_arg2330 = "/new";
  int _ret2329;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2329 = guestfs_touch (g, _arg2330);
  guestfs_pop_error_handler (g);
  if (_ret2329 != -1)
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
  const char *_arg2333 = "/new";
  const char *_arg2334 = "data";
  size_t _arg2334_size = 4;
  int _ret2332;
  _ret2332 = guestfs_write (g, _arg2333, _arg2334, _arg2334_size);
  if (_ret2332 == -1)
    return -1;
  const char *_arg2337 = "/";
  struct guestfs_umount_opts_argv _optargs2338;
  _optargs2338.force = 0;
  _optargs2338.lazyunmount = 0;
  _optargs2338.bitmask = UINT64_C(0x3);
  int _ret2336;
  _ret2336 = guestfs_umount_opts_argv (g, _arg2337, &_optargs2338);
  if (_ret2336 == -1)
    return -1;
  const char *_arg2340 = "/dev/sda1";
  const char *_arg2341 = "/";
  int _ret2339;
  _ret2339 = guestfs_mount_ro (g, _arg2340, _arg2341);
  if (_ret2339 == -1)
    return -1;
  const char *_arg2343 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2343);
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
  const char *_arg2346 = "/tgz_in";
  int _ret2345;
  _ret2345 = guestfs_mkdir (g, _arg2346);
  if (_ret2345 == -1)
    return -1;
  CLEANUP_FREE char *_arg2349 = substitute_srcdir ("$srcdir/../data/helloworld.tar.gz");
  const char *_arg2350 = "/tgz_in";
  int _ret2348;
  _ret2348 = guestfs_tgz_in (g, _arg2349, _arg2350);
  if (_ret2348 == -1)
    return -1;
  const char *_arg2352 = "/tgz_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2352);
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
  const char *_arg2355 = "/tar_in";
  int _ret2354;
  _ret2354 = guestfs_mkdir (g, _arg2355);
  if (_ret2354 == -1)
    return -1;
  CLEANUP_FREE char *_arg2358 = substitute_srcdir ("$srcdir/../data/helloworld.tar");
  const char *_arg2359 = "/tar_in";
  struct guestfs_tar_in_opts_argv _optargs2360;
  _optargs2360.bitmask = UINT64_C(0x0);
  int _ret2357;
  _ret2357 = guestfs_tar_in_opts_argv (g, _arg2358, _arg2359, &_optargs2360);
  if (_ret2357 == -1)
    return -1;
  const char *_arg2361 = "/tar_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2361);
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
  const char *_arg2364 = "/tar_in_gz";
  int _ret2363;
  _ret2363 = guestfs_mkdir (g, _arg2364);
  if (_ret2363 == -1)
    return -1;
  CLEANUP_FREE char *_arg2367 = substitute_srcdir ("$srcdir/../data/helloworld.tar.gz");
  const char *_arg2368 = "/tar_in_gz";
  struct guestfs_tar_in_opts_argv _optargs2369;
  _optargs2369.compress = "gzip";
  _optargs2369.bitmask = UINT64_C(0x1);
  int _ret2366;
  _ret2366 = guestfs_tar_in_opts_argv (g, _arg2367, _arg2368, &_optargs2369);
  if (_ret2366 == -1)
    return -1;
  const char *_arg2370 = "/tar_in_gz/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2370);
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

  const char *_features2372[] = { "xz", NULL };
  if (!guestfs_feature_available (g, (char **) _features2372)) {
    skipped ("test_tar_in_2", "group %s not available in daemon",
             _features2372[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  /* TestResultString for tar_in (2) */
  const char *_arg2374 = "/tar_in_xz";
  int _ret2373;
  _ret2373 = guestfs_mkdir (g, _arg2374);
  if (_ret2373 == -1)
    return -1;
  CLEANUP_FREE char *_arg2377 = substitute_srcdir ("$srcdir/../data/helloworld.tar.xz");
  const char *_arg2378 = "/tar_in_xz";
  struct guestfs_tar_in_opts_argv _optargs2379;
  _optargs2379.compress = "xz";
  _optargs2379.bitmask = UINT64_C(0x1);
  int _ret2376;
  _ret2376 = guestfs_tar_in_opts_argv (g, _arg2377, _arg2378, &_optargs2379);
  if (_ret2376 == -1)
    return -1;
  const char *_arg2380 = "/tar_in_xz/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2380);
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
  const char *_arg2382 = "crc";
  const char *_arg2383 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2382, _arg2383);
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
  const char *_arg2386 = "crc";
  const char *_arg2387 = "/notexists";
  CLEANUP_FREE char *_ret2385;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2385 = guestfs_checksum (g, _arg2386, _arg2387);
  guestfs_pop_error_handler (g);
  if (_ret2385 != NULL)
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
  const char *_arg2389 = "md5";
  const char *_arg2390 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2389, _arg2390);
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
  const char *_arg2392 = "sha1";
  const char *_arg2393 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2392, _arg2393);
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
  const char *_arg2395 = "sha224";
  const char *_arg2396 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2395, _arg2396);
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
  const char *_arg2398 = "sha256";
  const char *_arg2399 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2398, _arg2399);
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
  const char *_arg2401 = "sha384";
  const char *_arg2402 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2401, _arg2402);
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
  const char *_arg2404 = "sha512";
  const char *_arg2405 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2404, _arg2405);
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
  const char *_arg2407 = "sha512";
  const char *_arg2408 = "/abssymlink";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2407, _arg2408);
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
  const char *_arg2411 = "/download";
  int _ret2410;
  _ret2410 = guestfs_mkdir (g, _arg2411);
  if (_ret2410 == -1)
    return -1;
  CLEANUP_FREE char *_arg2414 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *_arg2415 = "/download/COPYING.LIB";
  int _ret2413;
  _ret2413 = guestfs_upload (g, _arg2414, _arg2415);
  if (_ret2413 == -1)
    return -1;
  const char *_arg2418 = "/download/COPYING.LIB";
  int _ret2417;
  _ret2417 = guestfs_download (g, _arg2418, "testdownload.tmp");
  if (_ret2417 == -1)
    return -1;
  CLEANUP_FREE char *_arg2422 = substitute_srcdir ("testdownload.tmp");
  const char *_arg2423 = "/download/upload";
  int _ret2421;
  _ret2421 = guestfs_upload (g, _arg2422, _arg2423);
  if (_ret2421 == -1)
    return -1;
  const char *_arg2425 = "md5";
  const char *_arg2426 = "/download/upload";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2425, _arg2426);
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
  const char *_arg2429 = "/upload";
  int _ret2428;
  _ret2428 = guestfs_mkdir (g, _arg2429);
  if (_ret2428 == -1)
    return -1;
  CLEANUP_FREE char *_arg2432 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *_arg2433 = "/upload/COPYING.LIB";
  int _ret2431;
  _ret2431 = guestfs_upload (g, _arg2432, _arg2433);
  if (_ret2431 == -1)
    return -1;
  const char *_arg2435 = "md5";
  const char *_arg2436 = "/upload/COPYING.LIB";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg2435, _arg2436);
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
  const char *_arg2439 = "/dev/sda";
  int _ret2438;
  _ret2438 = guestfs_blockdev_rereadpt (g, _arg2439);
  if (_ret2438 == -1)
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
  const char *_arg2442 = "/dev/sda";
  int _ret2441;
  _ret2441 = guestfs_blockdev_flushbufs (g, _arg2442);
  if (_ret2441 == -1)
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
  const char *_arg2444 = "/dev/sda";
  int64_t ret;
  ret = guestfs_blockdev_getsize64 (g, _arg2444);
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
  const char *_arg2446 = "/dev/sda";
  int64_t ret;
  ret = guestfs_blockdev_getsz (g, _arg2446);
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
  const char *_arg2448 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getss (g, _arg2448);
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
  const char *_arg2451 = "/dev/sda";
  int _ret2450;
  _ret2450 = guestfs_blockdev_setro (g, _arg2451);
  if (_ret2450 == -1)
    return -1;
  const char *_arg2453 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, _arg2453);
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
  const char *_arg2456 = "/dev/sda";
  int _ret2455;
  _ret2455 = guestfs_blockdev_setrw (g, _arg2456);
  if (_ret2455 == -1)
    return -1;
  const char *_arg2458 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, _arg2458);
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
  const char *_arg2461 = "/dev/sda";
  int _ret2460;
  _ret2460 = guestfs_blockdev_setro (g, _arg2461);
  if (_ret2460 == -1)
    return -1;
  const char *_arg2463 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, _arg2463);
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
  const char *_arg2465 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg2465);
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
  const char *_arg2467 = "/";
  CLEANUP_FREE_STATVFS struct guestfs_statvfs *ret;
  ret = guestfs_statvfs (g, _arg2467);
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
  const char *_arg2469 = "/empty";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_lstat (g, _arg2469);
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
  const char *_arg2471 = "/empty";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg2471);
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
  const char *_arg2473 = "/command_lines";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2473);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2475 = substitute_srcdir ("test-command");
  const char *_arg2476 = "/command_lines/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2475, _arg2476);
  if (ret2 == -1)
    return -1;
  const char *_arg2479 = "/command_lines/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2479);
  if (ret1 == -1)
    return -1;
  const char *_arg2481_0 = "/command_lines/test-command";
  const char *_arg2481_1 = "1";
  const char *const _arg2481[] = {
    _arg2481_0,
    _arg2481_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2481);
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
  const char *_arg2483 = "/command_lines2";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2483);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2485 = substitute_srcdir ("test-command");
  const char *_arg2486 = "/command_lines2/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2485, _arg2486);
  if (ret2 == -1)
    return -1;
  const char *_arg2489 = "/command_lines2/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2489);
  if (ret1 == -1)
    return -1;
  const char *_arg2491_0 = "/command_lines2/test-command";
  const char *_arg2491_1 = "2";
  const char *const _arg2491[] = {
    _arg2491_0,
    _arg2491_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2491);
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
  const char *_arg2493 = "/command_lines3";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2493);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2495 = substitute_srcdir ("test-command");
  const char *_arg2496 = "/command_lines3/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2495, _arg2496);
  if (ret2 == -1)
    return -1;
  const char *_arg2499 = "/command_lines3/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2499);
  if (ret1 == -1)
    return -1;
  const char *_arg2501_0 = "/command_lines3/test-command";
  const char *_arg2501_1 = "3";
  const char *const _arg2501[] = {
    _arg2501_0,
    _arg2501_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2501);
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
  const char *_arg2503 = "/command_lines4";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2503);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2505 = substitute_srcdir ("test-command");
  const char *_arg2506 = "/command_lines4/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2505, _arg2506);
  if (ret2 == -1)
    return -1;
  const char *_arg2509 = "/command_lines4/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2509);
  if (ret1 == -1)
    return -1;
  const char *_arg2511_0 = "/command_lines4/test-command";
  const char *_arg2511_1 = "4";
  const char *const _arg2511[] = {
    _arg2511_0,
    _arg2511_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2511);
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
  const char *_arg2513 = "/command_lines5";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2513);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2515 = substitute_srcdir ("test-command");
  const char *_arg2516 = "/command_lines5/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2515, _arg2516);
  if (ret2 == -1)
    return -1;
  const char *_arg2519 = "/command_lines5/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2519);
  if (ret1 == -1)
    return -1;
  const char *_arg2521_0 = "/command_lines5/test-command";
  const char *_arg2521_1 = "5";
  const char *const _arg2521[] = {
    _arg2521_0,
    _arg2521_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2521);
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
  const char *_arg2523 = "/command_lines6";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2523);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2525 = substitute_srcdir ("test-command");
  const char *_arg2526 = "/command_lines6/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2525, _arg2526);
  if (ret2 == -1)
    return -1;
  const char *_arg2529 = "/command_lines6/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2529);
  if (ret1 == -1)
    return -1;
  const char *_arg2531_0 = "/command_lines6/test-command";
  const char *_arg2531_1 = "6";
  const char *const _arg2531[] = {
    _arg2531_0,
    _arg2531_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2531);
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
  const char *_arg2533 = "/command_lines7";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2533);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2535 = substitute_srcdir ("test-command");
  const char *_arg2536 = "/command_lines7/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2535, _arg2536);
  if (ret2 == -1)
    return -1;
  const char *_arg2539 = "/command_lines7/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2539);
  if (ret1 == -1)
    return -1;
  const char *_arg2541_0 = "/command_lines7/test-command";
  const char *_arg2541_1 = "7";
  const char *const _arg2541[] = {
    _arg2541_0,
    _arg2541_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2541);
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
  const char *_arg2543 = "/command_lines8";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2543);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2545 = substitute_srcdir ("test-command");
  const char *_arg2546 = "/command_lines8/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2545, _arg2546);
  if (ret2 == -1)
    return -1;
  const char *_arg2549 = "/command_lines8/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2549);
  if (ret1 == -1)
    return -1;
  const char *_arg2551_0 = "/command_lines8/test-command";
  const char *_arg2551_1 = "8";
  const char *const _arg2551[] = {
    _arg2551_0,
    _arg2551_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2551);
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
  const char *_arg2553 = "/command_lines9";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2553);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2555 = substitute_srcdir ("test-command");
  const char *_arg2556 = "/command_lines9/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2555, _arg2556);
  if (ret2 == -1)
    return -1;
  const char *_arg2559 = "/command_lines9/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2559);
  if (ret1 == -1)
    return -1;
  const char *_arg2561_0 = "/command_lines9/test-command";
  const char *_arg2561_1 = "9";
  const char *const _arg2561[] = {
    _arg2561_0,
    _arg2561_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2561);
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
  const char *_arg2563 = "/command_lines10";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2563);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2565 = substitute_srcdir ("test-command");
  const char *_arg2566 = "/command_lines10/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2565, _arg2566);
  if (ret2 == -1)
    return -1;
  const char *_arg2569 = "/command_lines10/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2569);
  if (ret1 == -1)
    return -1;
  const char *_arg2571_0 = "/command_lines10/test-command";
  const char *_arg2571_1 = "10";
  const char *const _arg2571[] = {
    _arg2571_0,
    _arg2571_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2571);
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
  const char *_arg2573 = "/command_lines11";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2573);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *_arg2575 = substitute_srcdir ("test-command");
  const char *_arg2576 = "/command_lines11/test-command";
  int ret2;
  ret2 = guestfs_upload (g, _arg2575, _arg2576);
  if (ret2 == -1)
    return -1;
  const char *_arg2579 = "/command_lines11/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg2579);
  if (ret1 == -1)
    return -1;
  const char *_arg2581_0 = "/command_lines11/test-command";
  const char *_arg2581_1 = "11";
  const char *const _arg2581[] = {
    _arg2581_0,
    _arg2581_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg2581);
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
  const char *_arg2584 = "/command";
  int _ret2583;
  _ret2583 = guestfs_mkdir (g, _arg2584);
  if (_ret2583 == -1)
    return -1;
  CLEANUP_FREE char *_arg2587 = substitute_srcdir ("test-command");
  const char *_arg2588 = "/command/test-command";
  int _ret2586;
  _ret2586 = guestfs_upload (g, _arg2587, _arg2588);
  if (_ret2586 == -1)
    return -1;
  const char *_arg2592 = "/command/test-command";
  int _ret2590;
  _ret2590 = guestfs_chmod (g, 493, _arg2592);
  if (_ret2590 == -1)
    return -1;
  const char *_arg2594_0 = "/command/test-command";
  const char *_arg2594_1 = "1";
  const char *const _arg2594[] = {
    _arg2594_0,
    _arg2594_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2594);
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
  const char *_arg2597 = "/command2";
  int _ret2596;
  _ret2596 = guestfs_mkdir (g, _arg2597);
  if (_ret2596 == -1)
    return -1;
  CLEANUP_FREE char *_arg2600 = substitute_srcdir ("test-command");
  const char *_arg2601 = "/command2/test-command";
  int _ret2599;
  _ret2599 = guestfs_upload (g, _arg2600, _arg2601);
  if (_ret2599 == -1)
    return -1;
  const char *_arg2605 = "/command2/test-command";
  int _ret2603;
  _ret2603 = guestfs_chmod (g, 493, _arg2605);
  if (_ret2603 == -1)
    return -1;
  const char *_arg2607_0 = "/command2/test-command";
  const char *_arg2607_1 = "2";
  const char *const _arg2607[] = {
    _arg2607_0,
    _arg2607_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2607);
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
  const char *_arg2610 = "/command3";
  int _ret2609;
  _ret2609 = guestfs_mkdir (g, _arg2610);
  if (_ret2609 == -1)
    return -1;
  CLEANUP_FREE char *_arg2613 = substitute_srcdir ("test-command");
  const char *_arg2614 = "/command3/test-command";
  int _ret2612;
  _ret2612 = guestfs_upload (g, _arg2613, _arg2614);
  if (_ret2612 == -1)
    return -1;
  const char *_arg2618 = "/command3/test-command";
  int _ret2616;
  _ret2616 = guestfs_chmod (g, 493, _arg2618);
  if (_ret2616 == -1)
    return -1;
  const char *_arg2620_0 = "/command3/test-command";
  const char *_arg2620_1 = "3";
  const char *const _arg2620[] = {
    _arg2620_0,
    _arg2620_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2620);
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
  const char *_arg2623 = "/command4";
  int _ret2622;
  _ret2622 = guestfs_mkdir (g, _arg2623);
  if (_ret2622 == -1)
    return -1;
  CLEANUP_FREE char *_arg2626 = substitute_srcdir ("test-command");
  const char *_arg2627 = "/command4/test-command";
  int _ret2625;
  _ret2625 = guestfs_upload (g, _arg2626, _arg2627);
  if (_ret2625 == -1)
    return -1;
  const char *_arg2631 = "/command4/test-command";
  int _ret2629;
  _ret2629 = guestfs_chmod (g, 493, _arg2631);
  if (_ret2629 == -1)
    return -1;
  const char *_arg2633_0 = "/command4/test-command";
  const char *_arg2633_1 = "4";
  const char *const _arg2633[] = {
    _arg2633_0,
    _arg2633_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2633);
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
  const char *_arg2636 = "/command5";
  int _ret2635;
  _ret2635 = guestfs_mkdir (g, _arg2636);
  if (_ret2635 == -1)
    return -1;
  CLEANUP_FREE char *_arg2639 = substitute_srcdir ("test-command");
  const char *_arg2640 = "/command5/test-command";
  int _ret2638;
  _ret2638 = guestfs_upload (g, _arg2639, _arg2640);
  if (_ret2638 == -1)
    return -1;
  const char *_arg2644 = "/command5/test-command";
  int _ret2642;
  _ret2642 = guestfs_chmod (g, 493, _arg2644);
  if (_ret2642 == -1)
    return -1;
  const char *_arg2646_0 = "/command5/test-command";
  const char *_arg2646_1 = "5";
  const char *const _arg2646[] = {
    _arg2646_0,
    _arg2646_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2646);
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
  const char *_arg2649 = "/command6";
  int _ret2648;
  _ret2648 = guestfs_mkdir (g, _arg2649);
  if (_ret2648 == -1)
    return -1;
  CLEANUP_FREE char *_arg2652 = substitute_srcdir ("test-command");
  const char *_arg2653 = "/command6/test-command";
  int _ret2651;
  _ret2651 = guestfs_upload (g, _arg2652, _arg2653);
  if (_ret2651 == -1)
    return -1;
  const char *_arg2657 = "/command6/test-command";
  int _ret2655;
  _ret2655 = guestfs_chmod (g, 493, _arg2657);
  if (_ret2655 == -1)
    return -1;
  const char *_arg2659_0 = "/command6/test-command";
  const char *_arg2659_1 = "6";
  const char *const _arg2659[] = {
    _arg2659_0,
    _arg2659_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2659);
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
  const char *_arg2662 = "/command7";
  int _ret2661;
  _ret2661 = guestfs_mkdir (g, _arg2662);
  if (_ret2661 == -1)
    return -1;
  CLEANUP_FREE char *_arg2665 = substitute_srcdir ("test-command");
  const char *_arg2666 = "/command7/test-command";
  int _ret2664;
  _ret2664 = guestfs_upload (g, _arg2665, _arg2666);
  if (_ret2664 == -1)
    return -1;
  const char *_arg2670 = "/command7/test-command";
  int _ret2668;
  _ret2668 = guestfs_chmod (g, 493, _arg2670);
  if (_ret2668 == -1)
    return -1;
  const char *_arg2672_0 = "/command7/test-command";
  const char *_arg2672_1 = "7";
  const char *const _arg2672[] = {
    _arg2672_0,
    _arg2672_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2672);
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
  const char *_arg2675 = "/command8";
  int _ret2674;
  _ret2674 = guestfs_mkdir (g, _arg2675);
  if (_ret2674 == -1)
    return -1;
  CLEANUP_FREE char *_arg2678 = substitute_srcdir ("test-command");
  const char *_arg2679 = "/command8/test-command";
  int _ret2677;
  _ret2677 = guestfs_upload (g, _arg2678, _arg2679);
  if (_ret2677 == -1)
    return -1;
  const char *_arg2683 = "/command8/test-command";
  int _ret2681;
  _ret2681 = guestfs_chmod (g, 493, _arg2683);
  if (_ret2681 == -1)
    return -1;
  const char *_arg2685_0 = "/command8/test-command";
  const char *_arg2685_1 = "8";
  const char *const _arg2685[] = {
    _arg2685_0,
    _arg2685_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2685);
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
  const char *_arg2688 = "/command9";
  int _ret2687;
  _ret2687 = guestfs_mkdir (g, _arg2688);
  if (_ret2687 == -1)
    return -1;
  CLEANUP_FREE char *_arg2691 = substitute_srcdir ("test-command");
  const char *_arg2692 = "/command9/test-command";
  int _ret2690;
  _ret2690 = guestfs_upload (g, _arg2691, _arg2692);
  if (_ret2690 == -1)
    return -1;
  const char *_arg2696 = "/command9/test-command";
  int _ret2694;
  _ret2694 = guestfs_chmod (g, 493, _arg2696);
  if (_ret2694 == -1)
    return -1;
  const char *_arg2698_0 = "/command9/test-command";
  const char *_arg2698_1 = "9";
  const char *const _arg2698[] = {
    _arg2698_0,
    _arg2698_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2698);
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
  const char *_arg2701 = "/command10";
  int _ret2700;
  _ret2700 = guestfs_mkdir (g, _arg2701);
  if (_ret2700 == -1)
    return -1;
  CLEANUP_FREE char *_arg2704 = substitute_srcdir ("test-command");
  const char *_arg2705 = "/command10/test-command";
  int _ret2703;
  _ret2703 = guestfs_upload (g, _arg2704, _arg2705);
  if (_ret2703 == -1)
    return -1;
  const char *_arg2709 = "/command10/test-command";
  int _ret2707;
  _ret2707 = guestfs_chmod (g, 493, _arg2709);
  if (_ret2707 == -1)
    return -1;
  const char *_arg2711_0 = "/command10/test-command";
  const char *_arg2711_1 = "10";
  const char *const _arg2711[] = {
    _arg2711_0,
    _arg2711_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2711);
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
  const char *_arg2714 = "/command11";
  int _ret2713;
  _ret2713 = guestfs_mkdir (g, _arg2714);
  if (_ret2713 == -1)
    return -1;
  CLEANUP_FREE char *_arg2717 = substitute_srcdir ("test-command");
  const char *_arg2718 = "/command11/test-command";
  int _ret2716;
  _ret2716 = guestfs_upload (g, _arg2717, _arg2718);
  if (_ret2716 == -1)
    return -1;
  const char *_arg2722 = "/command11/test-command";
  int _ret2720;
  _ret2720 = guestfs_chmod (g, 493, _arg2722);
  if (_ret2720 == -1)
    return -1;
  const char *_arg2724_0 = "/command11/test-command";
  const char *_arg2724_1 = "11";
  const char *const _arg2724[] = {
    _arg2724_0,
    _arg2724_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2724);
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
  const char *_arg2727 = "/command12";
  int _ret2726;
  _ret2726 = guestfs_mkdir (g, _arg2727);
  if (_ret2726 == -1)
    return -1;
  CLEANUP_FREE char *_arg2730 = substitute_srcdir ("test-command");
  const char *_arg2731 = "/command12/test-command";
  int _ret2729;
  _ret2729 = guestfs_upload (g, _arg2730, _arg2731);
  if (_ret2729 == -1)
    return -1;
  const char *_arg2735 = "/command12/test-command";
  int _ret2733;
  _ret2733 = guestfs_chmod (g, 493, _arg2735);
  if (_ret2733 == -1)
    return -1;
  const char *_arg2738_0 = "/command12/test-command";
  const char *const _arg2738[] = {
    _arg2738_0,
    NULL
  };
  CLEANUP_FREE char *_ret2737;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2737 = guestfs_command (g, (char **) _arg2738);
  guestfs_pop_error_handler (g);
  if (_ret2737 != NULL)
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
  const char *_arg2741 = "/pwd";
  int _ret2740;
  _ret2740 = guestfs_mkdir (g, _arg2741);
  if (_ret2740 == -1)
    return -1;
  CLEANUP_FREE char *_arg2744 = substitute_srcdir ("test-pwd");
  const char *_arg2745 = "/pwd/test-pwd";
  int _ret2743;
  _ret2743 = guestfs_upload (g, _arg2744, _arg2745);
  if (_ret2743 == -1)
    return -1;
  const char *_arg2749 = "/pwd/test-pwd";
  int _ret2747;
  _ret2747 = guestfs_chmod (g, 493, _arg2749);
  if (_ret2747 == -1)
    return -1;
  const char *_arg2751_0 = "/pwd/test-pwd";
  const char *const _arg2751[] = {
    _arg2751_0,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg2751);
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
  const char *_arg2753 = "/empty";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg2753);
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
  const char *_arg2755 = "/known-1";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg2755);
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
  const char *_arg2758 = "/notexists";
  CLEANUP_FREE char *_ret2757;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2757 = guestfs_file (g, _arg2758);
  guestfs_pop_error_handler (g);
  if (_ret2757 != NULL)
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
  const char *_arg2760 = "/abssymlink";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg2760);
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
  const char *_arg2762 = "/directory";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg2762);
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
  const char *_arg2766 = "/dev/sda";
  const char *_arg2767 = "mbr";
  int ret14;
  ret14 = guestfs_part_init (g, _arg2766, _arg2767);
  if (ret14 == -1)
    return -1;
  const char *_arg2769 = "/dev/sda";
  const char *_arg2770 = "p";
  int ret13;
  ret13 = guestfs_part_add (g, _arg2769, _arg2770, 64, 204799);
  if (ret13 == -1)
    return -1;
  const char *_arg2774 = "/dev/sda";
  const char *_arg2775 = "p";
  int ret12;
  ret12 = guestfs_part_add (g, _arg2774, _arg2775, 204800, 409599);
  if (ret12 == -1)
    return -1;
  const char *_arg2779 = "/dev/sda";
  const char *_arg2780 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, _arg2779, _arg2780, 409600, -64);
  if (ret11 == -1)
    return -1;
  const char *_arg2784 = "ext2";
  const char *_arg2785 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs2786;
  _optargs2786.bitmask = UINT64_C(0x0);
  int ret10;
  ret10 = guestfs_mkfs_opts_argv (g, _arg2784, _arg2785, &_optargs2786);
  if (ret10 == -1)
    return -1;
  const char *_arg2787 = "ext2";
  const char *_arg2788 = "/dev/sda2";
  struct guestfs_mkfs_opts_argv _optargs2789;
  _optargs2789.bitmask = UINT64_C(0x0);
  int ret9;
  ret9 = guestfs_mkfs_opts_argv (g, _arg2787, _arg2788, &_optargs2789);
  if (ret9 == -1)
    return -1;
  const char *_arg2790 = "ext2";
  const char *_arg2791 = "/dev/sda3";
  struct guestfs_mkfs_opts_argv _optargs2792;
  _optargs2792.bitmask = UINT64_C(0x0);
  int ret8;
  ret8 = guestfs_mkfs_opts_argv (g, _arg2790, _arg2791, &_optargs2792);
  if (ret8 == -1)
    return -1;
  const char *_arg2793 = "/dev/sda1";
  const char *_arg2794 = "/";
  int ret7;
  ret7 = guestfs_mount (g, _arg2793, _arg2794);
  if (ret7 == -1)
    return -1;
  const char *_arg2796 = "/mp1";
  int ret6;
  ret6 = guestfs_mkdir (g, _arg2796);
  if (ret6 == -1)
    return -1;
  const char *_arg2798 = "/dev/sda2";
  const char *_arg2799 = "/mp1";
  int ret5;
  ret5 = guestfs_mount (g, _arg2798, _arg2799);
  if (ret5 == -1)
    return -1;
  const char *_arg2801 = "/mp1/mp2";
  int ret4;
  ret4 = guestfs_mkdir (g, _arg2801);
  if (ret4 == -1)
    return -1;
  const char *_arg2803 = "/dev/sda3";
  const char *_arg2804 = "/mp1/mp2";
  int ret3;
  ret3 = guestfs_mount (g, _arg2803, _arg2804);
  if (ret3 == -1)
    return -1;
  const char *_arg2806 = "/mp1/mp2/mp3";
  int ret2;
  ret2 = guestfs_mkdir (g, _arg2806);
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
  const char *_arg2811 = "/dev/sda";
  const char *_arg2812 = "mbr";
  int ret3;
  ret3 = guestfs_part_disk (g, _arg2811, _arg2812);
  if (ret3 == -1)
    return -1;
  const char *_arg2814 = "ext2";
  const char *_arg2815 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs2816;
  _optargs2816.bitmask = UINT64_C(0x0);
  int ret2;
  ret2 = guestfs_mkfs_opts_argv (g, _arg2814, _arg2815, &_optargs2816);
  if (ret2 == -1)
    return -1;
  const char *_arg2817 = "/dev/sda1";
  const char *_arg2818 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg2817, _arg2818);
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
  const char *_arg2821 = "/dev/sda";
  const char *_arg2822 = "mbr";
  int ret4;
  ret4 = guestfs_part_disk (g, _arg2821, _arg2822);
  if (ret4 == -1)
    return -1;
  const char *_arg2824 = "ext2";
  const char *_arg2825 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs2826;
  _optargs2826.bitmask = UINT64_C(0x0);
  int ret3;
  ret3 = guestfs_mkfs_opts_argv (g, _arg2824, _arg2825, &_optargs2826);
  if (ret3 == -1)
    return -1;
  const char *_arg2827 = "/dev/sda1";
  const char *_arg2828 = "/";
  int ret2;
  ret2 = guestfs_mount (g, _arg2827, _arg2828);
  if (ret2 == -1)
    return -1;
  const char *_arg2830 = "/";
  struct guestfs_umount_opts_argv _optargs2831;
  _optargs2831.force = 0;
  _optargs2831.lazyunmount = 0;
  _optargs2831.bitmask = UINT64_C(0x3);
  int ret1;
  ret1 = guestfs_umount_opts_argv (g, _arg2830, &_optargs2831);
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
  const char *_arg2834 = "/write_file";
  const char *_arg2835 = "abc";
  int _ret2833;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2833 = guestfs_write_file (g, _arg2834, _arg2835, 10000);
  guestfs_pop_error_handler (g);
  if (_ret2833 != -1)
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

  const char *_features2838[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2838)) {
    skipped ("test_lvcreate_0", "group %s not available in daemon",
             _features2838[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvcreate (0) */
  const char *_arg2839 = "/dev/sda";
  const char *_arg2840 = "mbr";
  int ret14;
  ret14 = guestfs_part_init (g, _arg2839, _arg2840);
  if (ret14 == -1)
    return -1;
  const char *_arg2842 = "/dev/sda";
  const char *_arg2843 = "p";
  int ret13;
  ret13 = guestfs_part_add (g, _arg2842, _arg2843, 64, 204799);
  if (ret13 == -1)
    return -1;
  const char *_arg2847 = "/dev/sda";
  const char *_arg2848 = "p";
  int ret12;
  ret12 = guestfs_part_add (g, _arg2847, _arg2848, 204800, 409599);
  if (ret12 == -1)
    return -1;
  const char *_arg2852 = "/dev/sda";
  const char *_arg2853 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, _arg2852, _arg2853, 409600, -64);
  if (ret11 == -1)
    return -1;
  const char *_arg2857 = "/dev/sda1";
  int ret10;
  ret10 = guestfs_pvcreate (g, _arg2857);
  if (ret10 == -1)
    return -1;
  const char *_arg2859 = "/dev/sda2";
  int ret9;
  ret9 = guestfs_pvcreate (g, _arg2859);
  if (ret9 == -1)
    return -1;
  const char *_arg2861 = "/dev/sda3";
  int ret8;
  ret8 = guestfs_pvcreate (g, _arg2861);
  if (ret8 == -1)
    return -1;
  const char *_arg2863 = "VG1";
  const char *_arg2864_0 = "/dev/sda1";
  const char *_arg2864_1 = "/dev/sda2";
  const char *const _arg2864[] = {
    _arg2864_0,
    _arg2864_1,
    NULL
  };
  int ret7;
  ret7 = guestfs_vgcreate (g, _arg2863, (char **) _arg2864);
  if (ret7 == -1)
    return -1;
  const char *_arg2866 = "VG2";
  const char *_arg2867_0 = "/dev/sda3";
  const char *const _arg2867[] = {
    _arg2867_0,
    NULL
  };
  int ret6;
  ret6 = guestfs_vgcreate (g, _arg2866, (char **) _arg2867);
  if (ret6 == -1)
    return -1;
  const char *_arg2869 = "LV1";
  const char *_arg2870 = "VG1";
  int ret5;
  ret5 = guestfs_lvcreate (g, _arg2869, _arg2870, 50);
  if (ret5 == -1)
    return -1;
  const char *_arg2873 = "LV2";
  const char *_arg2874 = "VG1";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg2873, _arg2874, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg2877 = "LV3";
  const char *_arg2878 = "VG2";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg2877, _arg2878, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg2881 = "LV4";
  const char *_arg2882 = "VG2";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg2881, _arg2882, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg2885 = "LV5";
  const char *_arg2886 = "VG2";
  int ret1;
  ret1 = guestfs_lvcreate (g, _arg2885, _arg2886, 50);
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

  const char *_features2890[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2890)) {
    skipped ("test_vgcreate_0", "group %s not available in daemon",
             _features2890[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for vgcreate (0) */
  const char *_arg2891 = "/dev/sda";
  const char *_arg2892 = "mbr";
  int ret9;
  ret9 = guestfs_part_init (g, _arg2891, _arg2892);
  if (ret9 == -1)
    return -1;
  const char *_arg2894 = "/dev/sda";
  const char *_arg2895 = "p";
  int ret8;
  ret8 = guestfs_part_add (g, _arg2894, _arg2895, 64, 204799);
  if (ret8 == -1)
    return -1;
  const char *_arg2899 = "/dev/sda";
  const char *_arg2900 = "p";
  int ret7;
  ret7 = guestfs_part_add (g, _arg2899, _arg2900, 204800, 409599);
  if (ret7 == -1)
    return -1;
  const char *_arg2904 = "/dev/sda";
  const char *_arg2905 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg2904, _arg2905, 409600, -64);
  if (ret6 == -1)
    return -1;
  const char *_arg2909 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg2909);
  if (ret5 == -1)
    return -1;
  const char *_arg2911 = "/dev/sda2";
  int ret4;
  ret4 = guestfs_pvcreate (g, _arg2911);
  if (ret4 == -1)
    return -1;
  const char *_arg2913 = "/dev/sda3";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg2913);
  if (ret3 == -1)
    return -1;
  const char *_arg2915 = "VG1";
  const char *_arg2916_0 = "/dev/sda1";
  const char *_arg2916_1 = "/dev/sda2";
  const char *const _arg2916[] = {
    _arg2916_0,
    _arg2916_1,
    NULL
  };
  int ret2;
  ret2 = guestfs_vgcreate (g, _arg2915, (char **) _arg2916);
  if (ret2 == -1)
    return -1;
  const char *_arg2918 = "VG2";
  const char *_arg2919_0 = "/dev/sda3";
  const char *const _arg2919[] = {
    _arg2919_0,
    NULL
  };
  int ret1;
  ret1 = guestfs_vgcreate (g, _arg2918, (char **) _arg2919);
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

  const char *_features2922[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2922)) {
    skipped ("test_pvcreate_0", "group %s not available in daemon",
             _features2922[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvcreate (0) */
  const char *_arg2923 = "/dev/sda";
  const char *_arg2924 = "mbr";
  int ret7;
  ret7 = guestfs_part_init (g, _arg2923, _arg2924);
  if (ret7 == -1)
    return -1;
  const char *_arg2926 = "/dev/sda";
  const char *_arg2927 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg2926, _arg2927, 64, 204799);
  if (ret6 == -1)
    return -1;
  const char *_arg2931 = "/dev/sda";
  const char *_arg2932 = "p";
  int ret5;
  ret5 = guestfs_part_add (g, _arg2931, _arg2932, 204800, 409599);
  if (ret5 == -1)
    return -1;
  const char *_arg2936 = "/dev/sda";
  const char *_arg2937 = "p";
  int ret4;
  ret4 = guestfs_part_add (g, _arg2936, _arg2937, 409600, -64);
  if (ret4 == -1)
    return -1;
  const char *_arg2941 = "/dev/sda1";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg2941);
  if (ret3 == -1)
    return -1;
  const char *_arg2943 = "/dev/sda2";
  int ret2;
  ret2 = guestfs_pvcreate (g, _arg2943);
  if (ret2 == -1)
    return -1;
  const char *_arg2945 = "/dev/sda3";
  int ret1;
  ret1 = guestfs_pvcreate (g, _arg2945);
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
  const char *_arg2948 = "/known-3";
  struct guestfs_is_dir_opts_argv _optargs2949;
  _optargs2949.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2948, &_optargs2949);
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
  const char *_arg2950 = "/directory";
  struct guestfs_is_dir_opts_argv _optargs2951;
  _optargs2951.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2950, &_optargs2951);
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
  const char *_arg2952 = "/known-1";
  struct guestfs_is_file_opts_argv _optargs2953;
  _optargs2953.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, _arg2952, &_optargs2953);
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
  const char *_arg2954 = "/directory";
  struct guestfs_is_file_opts_argv _optargs2955;
  _optargs2955.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, _arg2954, &_optargs2955);
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
  const char *_arg2956 = "/abssymlink";
  struct guestfs_is_file_opts_argv _optargs2957;
  _optargs2957.followsymlinks = 1;
  _optargs2957.bitmask = UINT64_C(0x1);
  int ret;
  ret = guestfs_is_file_opts_argv (g, _arg2956, &_optargs2957);
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
  const char *_arg2958 = "/empty";
  int ret;
  ret = guestfs_exists (g, _arg2958);
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
  const char *_arg2960 = "/directory";
  int ret;
  ret = guestfs_exists (g, _arg2960);
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
  const char *_arg2963 = "/mkdir_p/foo/bar";
  int _ret2962;
  _ret2962 = guestfs_mkdir_p (g, _arg2963);
  if (_ret2962 == -1)
    return -1;
  const char *_arg2965 = "/mkdir_p/foo/bar";
  struct guestfs_is_dir_opts_argv _optargs2966;
  _optargs2966.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2965, &_optargs2966);
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
  const char *_arg2968 = "/mkdir_p2/foo/bar";
  int _ret2967;
  _ret2967 = guestfs_mkdir_p (g, _arg2968);
  if (_ret2967 == -1)
    return -1;
  const char *_arg2970 = "/mkdir_p2/foo";
  struct guestfs_is_dir_opts_argv _optargs2971;
  _optargs2971.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2970, &_optargs2971);
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
  const char *_arg2973 = "/mkdir_p3/foo/bar";
  int _ret2972;
  _ret2972 = guestfs_mkdir_p (g, _arg2973);
  if (_ret2972 == -1)
    return -1;
  const char *_arg2975 = "/mkdir_p3";
  struct guestfs_is_dir_opts_argv _optargs2976;
  _optargs2976.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2975, &_optargs2976);
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
  const char *_arg2978 = "/mkdir_p4";
  int _ret2977;
  _ret2977 = guestfs_mkdir (g, _arg2978);
  if (_ret2977 == -1)
    return -1;
  const char *_arg2981 = "/mkdir_p4";
  int _ret2980;
  _ret2980 = guestfs_mkdir_p (g, _arg2981);
  if (_ret2980 == -1)
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
  const char *_arg2984 = "/mkdir_p5";
  int _ret2983;
  _ret2983 = guestfs_touch (g, _arg2984);
  if (_ret2983 == -1)
    return -1;
  const char *_arg2987 = "/mkdir_p5";
  int _ret2986;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2986 = guestfs_mkdir_p (g, _arg2987);
  guestfs_pop_error_handler (g);
  if (_ret2986 != -1)
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
  const char *_arg2990 = "/mkdir";
  int _ret2989;
  _ret2989 = guestfs_mkdir (g, _arg2990);
  if (_ret2989 == -1)
    return -1;
  const char *_arg2992 = "/mkdir";
  struct guestfs_is_dir_opts_argv _optargs2993;
  _optargs2993.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, _arg2992, &_optargs2993);
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
  const char *_arg2995 = "/mkdir2/foo/bar";
  int _ret2994;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2994 = guestfs_mkdir (g, _arg2995);
  guestfs_pop_error_handler (g);
  if (_ret2994 != -1)
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
  const char *_arg2998 = "/rm_rf";
  int _ret2997;
  _ret2997 = guestfs_mkdir (g, _arg2998);
  if (_ret2997 == -1)
    return -1;
  const char *_arg3001 = "/rm_rf/foo";
  int _ret3000;
  _ret3000 = guestfs_mkdir (g, _arg3001);
  if (_ret3000 == -1)
    return -1;
  const char *_arg3004 = "/rm_rf/foo/bar";
  int _ret3003;
  _ret3003 = guestfs_touch (g, _arg3004);
  if (_ret3003 == -1)
    return -1;
  const char *_arg3007 = "/rm_rf";
  int _ret3006;
  _ret3006 = guestfs_rm_rf (g, _arg3007);
  if (_ret3006 == -1)
    return -1;
  const char *_arg3009 = "/rm_rf";
  int ret;
  ret = guestfs_exists (g, _arg3009);
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
  const char *_arg3012 = "/rmdir";
  int _ret3011;
  _ret3011 = guestfs_mkdir (g, _arg3012);
  if (_ret3011 == -1)
    return -1;
  const char *_arg3015 = "/rmdir";
  int _ret3014;
  _ret3014 = guestfs_rmdir (g, _arg3015);
  if (_ret3014 == -1)
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
  const char *_arg3018 = "/rmdir2";
  int _ret3017;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret3017 = guestfs_rmdir (g, _arg3018);
  guestfs_pop_error_handler (g);
  if (_ret3017 != -1)
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
  const char *_arg3021 = "/rmdir3";
  int _ret3020;
  _ret3020 = guestfs_mkdir (g, _arg3021);
  if (_ret3020 == -1)
    return -1;
  const char *_arg3024 = "/rmdir3/new";
  int _ret3023;
  _ret3023 = guestfs_touch (g, _arg3024);
  if (_ret3023 == -1)
    return -1;
  const char *_arg3027 = "/rmdir3/new";
  int _ret3026;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret3026 = guestfs_rmdir (g, _arg3027);
  guestfs_pop_error_handler (g);
  if (_ret3026 != -1)
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
  const char *_arg3030 = "/rm";
  int _ret3029;
  _ret3029 = guestfs_mkdir (g, _arg3030);
  if (_ret3029 == -1)
    return -1;
  const char *_arg3033 = "/rm/new";
  int _ret3032;
  _ret3032 = guestfs_touch (g, _arg3033);
  if (_ret3032 == -1)
    return -1;
  const char *_arg3036 = "/rm/new";
  int _ret3035;
  _ret3035 = guestfs_rm (g, _arg3036);
  if (_ret3035 == -1)
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
  const char *_arg3039 = "/nosuchfile";
  int _ret3038;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret3038 = guestfs_rm (g, _arg3039);
  guestfs_pop_error_handler (g);
  if (_ret3038 != -1)
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
  const char *_arg3042 = "/rm2";
  int _ret3041;
  _ret3041 = guestfs_mkdir (g, _arg3042);
  if (_ret3041 == -1)
    return -1;
  const char *_arg3045 = "/rm2";
  int _ret3044;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret3044 = guestfs_rm (g, _arg3045);
  guestfs_pop_error_handler (g);
  if (_ret3044 != -1)
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

  const char *_features3047[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3047)) {
    skipped ("test_lvs_0", "group %s not available in daemon",
             _features3047[0]);
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

  const char *_features3049[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3049)) {
    skipped ("test_lvs_1", "group %s not available in daemon",
             _features3049[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for lvs (1) */
  const char *_arg3050 = "/dev/sda";
  const char *_arg3051 = "mbr";
  int ret12;
  ret12 = guestfs_part_init (g, _arg3050, _arg3051);
  if (ret12 == -1)
    return -1;
  const char *_arg3053 = "/dev/sda";
  const char *_arg3054 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, _arg3053, _arg3054, 64, 204799);
  if (ret11 == -1)
    return -1;
  const char *_arg3058 = "/dev/sda";
  const char *_arg3059 = "p";
  int ret10;
  ret10 = guestfs_part_add (g, _arg3058, _arg3059, 204800, 409599);
  if (ret10 == -1)
    return -1;
  const char *_arg3063 = "/dev/sda";
  const char *_arg3064 = "p";
  int ret9;
  ret9 = guestfs_part_add (g, _arg3063, _arg3064, 409600, -64);
  if (ret9 == -1)
    return -1;
  const char *_arg3068 = "/dev/sda1";
  int ret8;
  ret8 = guestfs_pvcreate (g, _arg3068);
  if (ret8 == -1)
    return -1;
  const char *_arg3070 = "/dev/sda2";
  int ret7;
  ret7 = guestfs_pvcreate (g, _arg3070);
  if (ret7 == -1)
    return -1;
  const char *_arg3072 = "/dev/sda3";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg3072);
  if (ret6 == -1)
    return -1;
  const char *_arg3074 = "VG1";
  const char *_arg3075_0 = "/dev/sda1";
  const char *_arg3075_1 = "/dev/sda2";
  const char *const _arg3075[] = {
    _arg3075_0,
    _arg3075_1,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg3074, (char **) _arg3075);
  if (ret5 == -1)
    return -1;
  const char *_arg3077 = "VG2";
  const char *_arg3078_0 = "/dev/sda3";
  const char *const _arg3078[] = {
    _arg3078_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg3077, (char **) _arg3078);
  if (ret4 == -1)
    return -1;
  const char *_arg3080 = "LV1";
  const char *_arg3081 = "VG1";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg3080, _arg3081, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg3084 = "LV2";
  const char *_arg3085 = "VG1";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg3084, _arg3085, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg3088 = "LV3";
  const char *_arg3089 = "VG2";
  int ret1;
  ret1 = guestfs_lvcreate (g, _arg3088, _arg3089, 50);
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

  const char *_features3093[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3093)) {
    skipped ("test_vgs_0", "group %s not available in daemon",
             _features3093[0]);
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

  const char *_features3095[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3095)) {
    skipped ("test_vgs_1", "group %s not available in daemon",
             _features3095[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for vgs (1) */
  const char *_arg3096 = "/dev/sda";
  const char *_arg3097 = "mbr";
  int ret9;
  ret9 = guestfs_part_init (g, _arg3096, _arg3097);
  if (ret9 == -1)
    return -1;
  const char *_arg3099 = "/dev/sda";
  const char *_arg3100 = "p";
  int ret8;
  ret8 = guestfs_part_add (g, _arg3099, _arg3100, 64, 204799);
  if (ret8 == -1)
    return -1;
  const char *_arg3104 = "/dev/sda";
  const char *_arg3105 = "p";
  int ret7;
  ret7 = guestfs_part_add (g, _arg3104, _arg3105, 204800, 409599);
  if (ret7 == -1)
    return -1;
  const char *_arg3109 = "/dev/sda";
  const char *_arg3110 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg3109, _arg3110, 409600, -64);
  if (ret6 == -1)
    return -1;
  const char *_arg3114 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg3114);
  if (ret5 == -1)
    return -1;
  const char *_arg3116 = "/dev/sda2";
  int ret4;
  ret4 = guestfs_pvcreate (g, _arg3116);
  if (ret4 == -1)
    return -1;
  const char *_arg3118 = "/dev/sda3";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg3118);
  if (ret3 == -1)
    return -1;
  const char *_arg3120 = "VG1";
  const char *_arg3121_0 = "/dev/sda1";
  const char *_arg3121_1 = "/dev/sda2";
  const char *const _arg3121[] = {
    _arg3121_0,
    _arg3121_1,
    NULL
  };
  int ret2;
  ret2 = guestfs_vgcreate (g, _arg3120, (char **) _arg3121);
  if (ret2 == -1)
    return -1;
  const char *_arg3123 = "VG2";
  const char *_arg3124_0 = "/dev/sda3";
  const char *const _arg3124[] = {
    _arg3124_0,
    NULL
  };
  int ret1;
  ret1 = guestfs_vgcreate (g, _arg3123, (char **) _arg3124);
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

  const char *_features3127[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3127)) {
    skipped ("test_pvs_0", "group %s not available in daemon",
             _features3127[0]);
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

  const char *_features3129[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features3129)) {
    skipped ("test_pvs_1", "group %s not available in daemon",
             _features3129[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  /* TestResult for pvs (1) */
  const char *_arg3130 = "/dev/sda";
  const char *_arg3131 = "mbr";
  int ret7;
  ret7 = guestfs_part_init (g, _arg3130, _arg3131);
  if (ret7 == -1)
    return -1;
  const char *_arg3133 = "/dev/sda";
  const char *_arg3134 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg3133, _arg3134, 64, 204799);
  if (ret6 == -1)
    return -1;
  const char *_arg3138 = "/dev/sda";
  const char *_arg3139 = "p";
  int ret5;
  ret5 = guestfs_part_add (g, _arg3138, _arg3139, 204800, 409599);
  if (ret5 == -1)
    return -1;
  const char *_arg3143 = "/dev/sda";
  const char *_arg3144 = "p";
  int ret4;
  ret4 = guestfs_part_add (g, _arg3143, _arg3144, 409600, -64);
  if (ret4 == -1)
    return -1;
  const char *_arg3148 = "/dev/sda1";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg3148);
  if (ret3 == -1)
    return -1;
  const char *_arg3150 = "/dev/sda2";
  int ret2;
  ret2 = guestfs_pvcreate (g, _arg3150);
  if (ret2 == -1)
    return -1;
  const char *_arg3152 = "/dev/sda3";
  int ret1;
  ret1 = guestfs_pvcreate (g, _arg3152);
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
  const char *_arg3156 = "/dev/sda";
  const char *_arg3157 = "mbr";
  int ret4;
  ret4 = guestfs_part_init (g, _arg3156, _arg3157);
  if (ret4 == -1)
    return -1;
  const char *_arg3159 = "/dev/sda";
  const char *_arg3160 = "p";
  int ret3;
  ret3 = guestfs_part_add (g, _arg3159, _arg3160, 64, 204799);
  if (ret3 == -1)
    return -1;
  const char *_arg3164 = "/dev/sda";
  const char *_arg3165 = "p";
  int ret2;
  ret2 = guestfs_part_add (g, _arg3164, _arg3165, 204800, 409599);
  if (ret2 == -1)
    return -1;
  const char *_arg3169 = "/dev/sda";
  const char *_arg3170 = "p";
  int ret1;
  ret1 = guestfs_part_add (g, _arg3169, _arg3170, 409600, -64);
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
  const char *_arg3177 = "/touch";
  int _ret3176;
  _ret3176 = guestfs_touch (g, _arg3177);
  if (_ret3176 == -1)
    return -1;
  const char *_arg3179 = "/touch";
  int ret;
  ret = guestfs_exists (g, _arg3179);
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
  int _ret3181;
  _ret3181 = guestfs_sync (g);
  if (_ret3181 == -1)
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
  const char *_arg3184 = "/dev/sda";
  const char *_arg3185 = "mbr";
  int _ret3183;
  _ret3183 = guestfs_part_disk (g, _arg3184, _arg3185);
  if (_ret3183 == -1)
    return -1;
  const char *_arg3188 = "ext2";
  const char *_arg3189 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs3190;
  _optargs3190.bitmask = UINT64_C(0x0);
  int _ret3187;
  _ret3187 = guestfs_mkfs_opts_argv (g, _arg3188, _arg3189, &_optargs3190);
  if (_ret3187 == -1)
    return -1;
  const char *_arg3192 = "/dev/sda1";
  const char *_arg3193 = "/";
  int _ret3191;
  _ret3191 = guestfs_mount (g, _arg3192, _arg3193);
  if (_ret3191 == -1)
    return -1;
  const char *_arg3196 = "/new";
  const char *_arg3197 = "new file contents";
  size_t _arg3197_size = 17;
  int _ret3195;
  _ret3195 = guestfs_write (g, _arg3196, _arg3197, _arg3197_size);
  if (_ret3195 == -1)
    return -1;
  const char *_arg3199 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3199);
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
  const char *_ret3201;
  _ret3201 = guestfs_get_program (g);
  if (_ret3201 == NULL)
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
  const char *_arg3203 = guestfs_get_private (g, "test1");
  int ret;
  ret = guestfs_disk_has_backing_file (g, _arg3203);
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
  const char *_arg3205 = guestfs_get_private (g, "test2");
  int ret;
  ret = guestfs_disk_has_backing_file (g, _arg3205);
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
  const char *_arg3207 = guestfs_get_private (g, "test3");
  int ret;
  ret = guestfs_disk_has_backing_file (g, _arg3207);
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
  const char *_arg3209 = guestfs_get_private (g, "test1");
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, _arg3209);
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
  const char *_arg3211 = guestfs_get_private (g, "test2");
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, _arg3211);
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
  const char *_arg3213 = guestfs_get_private (g, "test3");
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, _arg3213);
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
  const char *_arg3215 = guestfs_get_private (g, "test1");
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, _arg3215);
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
  const char *_arg3217 = guestfs_get_private (g, "test2");
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, _arg3217);
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
  const char *_arg3219 = guestfs_get_private (g, "test3");
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, _arg3219);
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
  const char *_arg3221 = "/ls";
  int ret4;
  ret4 = guestfs_mkdir (g, _arg3221);
  if (ret4 == -1)
    return -1;
  const char *_arg3223 = "/ls/new";
  int ret3;
  ret3 = guestfs_touch (g, _arg3223);
  if (ret3 == -1)
    return -1;
  const char *_arg3225 = "/ls/newer";
  int ret2;
  ret2 = guestfs_touch (g, _arg3225);
  if (ret2 == -1)
    return -1;
  const char *_arg3227 = "/ls/newest";
  int ret1;
  ret1 = guestfs_touch (g, _arg3227);
  if (ret1 == -1)
    return -1;
  const char *_arg3229 = "/ls";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_ls (g, _arg3229);
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
  const char *_arg3232 = "/write_append";
  const char *_arg3233 = "line1\n";
  size_t _arg3233_size = 6;
  int _ret3231;
  _ret3231 = guestfs_write (g, _arg3232, _arg3233, _arg3233_size);
  if (_ret3231 == -1)
    return -1;
  const char *_arg3236 = "/write_append";
  const char *_arg3237 = "line2\n";
  size_t _arg3237_size = 6;
  int _ret3235;
  _ret3235 = guestfs_write_append (g, _arg3236, _arg3237, _arg3237_size);
  if (_ret3235 == -1)
    return -1;
  const char *_arg3240 = "/write_append";
  const char *_arg3241 = "line3a";
  size_t _arg3241_size = 6;
  int _ret3239;
  _ret3239 = guestfs_write_append (g, _arg3240, _arg3241, _arg3241_size);
  if (_ret3239 == -1)
    return -1;
  const char *_arg3244 = "/write_append";
  const char *_arg3245 = "line3b\n";
  size_t _arg3245_size = 7;
  int _ret3243;
  _ret3243 = guestfs_write_append (g, _arg3244, _arg3245, _arg3245_size);
  if (_ret3243 == -1)
    return -1;
  const char *_arg3247 = "/write_append";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3247);
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
  const char *_arg3250 = "/write";
  const char *_arg3251 = "new file contents";
  size_t _arg3251_size = 17;
  int _ret3249;
  _ret3249 = guestfs_write (g, _arg3250, _arg3251, _arg3251_size);
  if (_ret3249 == -1)
    return -1;
  const char *_arg3253 = "/write";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3253);
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
  const char *_arg3256 = "/write2";
  const char *_arg3257 = "\nnew file contents\n";
  size_t _arg3257_size = 19;
  int _ret3255;
  _ret3255 = guestfs_write (g, _arg3256, _arg3257, _arg3257_size);
  if (_ret3255 == -1)
    return -1;
  const char *_arg3259 = "/write2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3259);
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
  const char *_arg3262 = "/write3";
  const char *_arg3263 = "\n\n";
  size_t _arg3263_size = 2;
  int _ret3261;
  _ret3261 = guestfs_write (g, _arg3262, _arg3263, _arg3263_size);
  if (_ret3261 == -1)
    return -1;
  const char *_arg3265 = "/write3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3265);
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
  const char *_arg3268 = "/write4";
  const char *_arg3269 = "";
  size_t _arg3269_size = 0;
  int _ret3267;
  _ret3267 = guestfs_write (g, _arg3268, _arg3269, _arg3269_size);
  if (_ret3267 == -1)
    return -1;
  const char *_arg3271 = "/write4";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3271);
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
  const char *_arg3274 = "/write5";
  const char *_arg3275 = "\n\n\n";
  size_t _arg3275_size = 3;
  int _ret3273;
  _ret3273 = guestfs_write (g, _arg3274, _arg3275, _arg3275_size);
  if (_ret3273 == -1)
    return -1;
  const char *_arg3277 = "/write5";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3277);
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
  const char *_arg3280 = "/write6";
  const char *_arg3281 = "\n";
  size_t _arg3281_size = 1;
  int _ret3279;
  _ret3279 = guestfs_write (g, _arg3280, _arg3281, _arg3281_size);
  if (_ret3279 == -1)
    return -1;
  const char *_arg3283 = "/write6";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3283);
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
  const char *_arg3285 = "/known-4";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3285);
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
  const char *_arg3287 = "/empty";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3287);
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
  const char *_arg3289 = "/read_lines1";
  const char *_arg3290 = "\n";
  size_t _arg3290_size = 1;
  int ret1;
  ret1 = guestfs_write (g, _arg3289, _arg3290, _arg3290_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3292 = "/read_lines1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3292);
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
  const char *_arg3294 = "/read_lines2";
  const char *_arg3295 = "\r\n";
  size_t _arg3295_size = 2;
  int ret1;
  ret1 = guestfs_write (g, _arg3294, _arg3295, _arg3295_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3297 = "/read_lines2";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3297);
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
  const char *_arg3299 = "/read_lines3";
  const char *_arg3300 = "\n\r\n";
  size_t _arg3300_size = 3;
  int ret1;
  ret1 = guestfs_write (g, _arg3299, _arg3300, _arg3300_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3302 = "/read_lines3";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3302);
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
  const char *_arg3304 = "/read_lines4";
  const char *_arg3305 = "a";
  size_t _arg3305_size = 1;
  int ret1;
  ret1 = guestfs_write (g, _arg3304, _arg3305, _arg3305_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3307 = "/read_lines4";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3307);
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
  const char *_arg3309 = "/read_lines5";
  const char *_arg3310 = "a\nb";
  size_t _arg3310_size = 3;
  int ret1;
  ret1 = guestfs_write (g, _arg3309, _arg3310, _arg3310_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3312 = "/read_lines5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3312);
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
  const char *_arg3314 = "/read_lines6";
  const char *_arg3315 = "a\nb\n";
  size_t _arg3315_size = 4;
  int ret1;
  ret1 = guestfs_write (g, _arg3314, _arg3315, _arg3315_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3317 = "/read_lines6";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3317);
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
  const char *_arg3319 = "/read_lines7";
  const char *_arg3320 = "a\nb\r\n";
  size_t _arg3320_size = 5;
  int ret1;
  ret1 = guestfs_write (g, _arg3319, _arg3320, _arg3320_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3322 = "/read_lines7";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3322);
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
  const char *_arg3324 = "/read_lines8";
  const char *_arg3325 = "a\nb\r\n\n";
  size_t _arg3325_size = 6;
  int ret1;
  ret1 = guestfs_write (g, _arg3324, _arg3325, _arg3325_size);
  if (ret1 == -1)
    return -1;
  const char *_arg3327 = "/read_lines8";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg3327);
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
  const char *_arg3329 = "/known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg3329, &size);
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
  const char *_arg3331 = "/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, _arg3331);
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
  const char *_arg3333 = "/a";
  int ret3;
  ret3 = guestfs_touch (g, _arg3333);
  if (ret3 == -1)
    return -1;
  const char *_arg3335 = "/b";
  int ret2;
  ret2 = guestfs_mkdir (g, _arg3335);
  if (ret2 == -1)
    return -1;
  const char *_arg3337 = "/b/c";
  int ret1;
  ret1 = guestfs_touch (g, _arg3337);
  if (ret1 == -1)
    return -1;
  const char *_arg3339 = "/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, _arg3339);
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
  const char *_arg3341 = "/find/b/c";
  int ret2;
  ret2 = guestfs_mkdir_p (g, _arg3341);
  if (ret2 == -1)
    return -1;
  const char *_arg3343 = "/find/b/c/d";
  int ret1;
  ret1 = guestfs_touch (g, _arg3343);
  if (ret1 == -1)
    return -1;
  const char *_arg3345 = "/find/b/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, _arg3345);
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
  const char *_arg3347 = "/known-2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3347);
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
  CLEANUP_FREE char *_ret3349;
  _ret3349 = guestfs_get_backend (g);
  if (_ret3349 == NULL)
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
  CLEANUP_FREE char *_ret3351;
  _ret3351 = guestfs_get_attach_method (g);
  if (_ret3351 == NULL)
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
  const char *_arg3353 = "/bin-i586-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3353);
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
  const char *_arg3355 = "/bin-sparc-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3355);
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
  const char *_arg3357 = "/bin-win32.exe";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3357);
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
  const char *_arg3359 = "/bin-win64.exe";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3359);
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
  const char *_arg3361 = "/bin-x86_64-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3361);
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
  const char *_arg3363 = "/lib-i586.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3363);
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
  const char *_arg3365 = "/lib-sparc.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3365);
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
  const char *_arg3367 = "/lib-win32.dll";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3367);
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
  const char *_arg3369 = "/lib-win64.dll";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3369);
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
  const char *_arg3371 = "/lib-x86_64.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3371);
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
  const char *_arg3373 = "/initrd-x86_64.img";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3373);
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
  const char *_arg3375 = "/initrd-x86_64.img.gz";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg3375);
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
  int _ret3377;
  _ret3377 = guestfs_set_trace (g, 0);
  if (_ret3377 == -1)
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
  const char *_ret3388;
  _ret3388 = guestfs_get_path (g);
  if (_ret3388 == NULL)
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
  const char *_ret3390;
  _ret3390 = guestfs_get_qemu (g);
  if (_ret3390 == NULL)
      return -1;
  return 0;
}

size_t nr_tests = 431;

struct test tests[431] = {
  { .name = "test_remount_0", .test_fn = test_remount_0 },
  { .name = "test_remount_1", .test_fn = test_remount_1 },
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
