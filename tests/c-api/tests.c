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
test_feature_available_0 (void)
{
  if (test_feature_available_0_skip ()) {
    skipped ("test_feature_available_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_feature_available_0 */
  const char *_arg2 = "/dev/sda";
  int _ret1;
  _ret1 = guestfs_blockdev_setrw (g, _arg2);
  if (_ret1 == -1)
    return -1;
  int _ret4;
  _ret4 = guestfs_umount_all (g);
  if (_ret4 == -1)
    return -1;
  int _ret6;
  _ret6 = guestfs_lvm_remove_all (g);
  if (_ret6 == -1)
    return -1;

  /* TestResultTrue for feature_available (0) */
  const char *const _arg8[1] = { NULL };
  int ret;
  ret = guestfs_feature_available (g, (char **) _arg8);
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
test_is_whole_device_0 (void)
{
  if (test_is_whole_device_0_skip ()) {
    skipped ("test_is_whole_device_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_is_whole_device_0 */
  const char *_arg11 = "/dev/sda";
  int _ret10;
  _ret10 = guestfs_blockdev_setrw (g, _arg11);
  if (_ret10 == -1)
    return -1;
  int _ret13;
  _ret13 = guestfs_umount_all (g);
  if (_ret13 == -1)
    return -1;
  int _ret15;
  _ret15 = guestfs_lvm_remove_all (g);
  if (_ret15 == -1)
    return -1;

  /* TestResultTrue for is_whole_device (0) */
  const char *_arg17 = "/dev/sda";
  int ret;
  ret = guestfs_is_whole_device (g, _arg17);
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
test_is_whole_device_1 (void)
{
  if (test_is_whole_device_1_skip ()) {
    skipped ("test_is_whole_device_1", "environment variable set");
    return 0;
  }

  /* InitPartition for test_is_whole_device_1: create /dev/sda1 */
  const char *_arg20 = "/dev/sda";
  int _ret19;
  _ret19 = guestfs_blockdev_setrw (g, _arg20);
  if (_ret19 == -1)
    return -1;
  int _ret22;
  _ret22 = guestfs_umount_all (g);
  if (_ret22 == -1)
    return -1;
  int _ret24;
  _ret24 = guestfs_lvm_remove_all (g);
  if (_ret24 == -1)
    return -1;
  const char *_arg27 = "/dev/sda";
  const char *_arg28 = "mbr";
  int _ret26;
  _ret26 = guestfs_part_disk (g, _arg27, _arg28);
  if (_ret26 == -1)
    return -1;

  /* TestResultFalse for is_whole_device (1) */
  const char *_arg30 = "/dev/sda1";
  int ret;
  ret = guestfs_is_whole_device (g, _arg30);
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
test_is_whole_device_2 (void)
{
  if (test_is_whole_device_2_skip ()) {
    skipped ("test_is_whole_device_2", "environment variable set");
    return 0;
  }

  /* InitBasicFSonLVM for test_is_whole_device_2: create ext2 on /dev/VG/LV */
  const char *_arg33 = "/dev/sda";
  int _ret32;
  _ret32 = guestfs_blockdev_setrw (g, _arg33);
  if (_ret32 == -1)
    return -1;
  int _ret35;
  _ret35 = guestfs_umount_all (g);
  if (_ret35 == -1)
    return -1;
  int _ret37;
  _ret37 = guestfs_lvm_remove_all (g);
  if (_ret37 == -1)
    return -1;
  const char *_arg40 = "/dev/sda";
  const char *_arg41 = "mbr";
  int _ret39;
  _ret39 = guestfs_part_disk (g, _arg40, _arg41);
  if (_ret39 == -1)
    return -1;
  const char *_arg44 = "/dev/sda1";
  int _ret43;
  _ret43 = guestfs_pvcreate (g, _arg44);
  if (_ret43 == -1)
    return -1;
  const char *_arg47 = "VG";
  const char *_arg48_0 = "/dev/sda1";
  const char *const _arg48[] = {
    _arg48_0,
    NULL
  };
  int _ret46;
  _ret46 = guestfs_vgcreate (g, _arg47, (char **) _arg48);
  if (_ret46 == -1)
    return -1;
  const char *_arg51 = "LV";
  const char *_arg52 = "VG";
  int _ret50;
  _ret50 = guestfs_lvcreate (g, _arg51, _arg52, 8);
  if (_ret50 == -1)
    return -1;
  const char *_arg56 = "ext2";
  const char *_arg57 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs58;
  _optargs58.bitmask = UINT64_C(0x0);
  int _ret55;
  _ret55 = guestfs_mkfs_opts_argv (g, _arg56, _arg57, &_optargs58);
  if (_ret55 == -1)
    return -1;
  const char *_arg60 = "/dev/VG/LV";
  const char *_arg61 = "/";
  int _ret59;
  _ret59 = guestfs_mount (g, _arg60, _arg61);
  if (_ret59 == -1)
    return -1;

  /* TestResultFalse for is_whole_device (2) */
  const char *_arg63 = "/dev/VG/LV";
  int ret;
  ret = guestfs_is_whole_device (g, _arg63);
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
test_rename_0 (void)
{
  if (test_rename_0_skip ()) {
    skipped ("test_rename_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_rename_0 */
  const char *_arg66 = "/dev/sda";
  int _ret65;
  _ret65 = guestfs_blockdev_setrw (g, _arg66);
  if (_ret65 == -1)
    return -1;
  int _ret68;
  _ret68 = guestfs_umount_all (g);
  if (_ret68 == -1)
    return -1;
  int _ret70;
  _ret70 = guestfs_lvm_remove_all (g);
  if (_ret70 == -1)
    return -1;
  const char *_arg73 = "/dev/sdb1";
  const char *_arg74 = "/";
  int _ret72;
  _ret72 = guestfs_mount (g, _arg73, _arg74);
  if (_ret72 == -1)
    return -1;

  /* TestResultFalse for rename (0) */
  const char *_arg77 = "/rename";
  int _ret76;
  _ret76 = guestfs_mkdir (g, _arg77);
  if (_ret76 == -1)
    return -1;
  const char *_arg80 = "/rename/old";
  const char *_arg81 = "file content";
  size_t _arg81_size = 12;
  int _ret79;
  _ret79 = guestfs_write (g, _arg80, _arg81, _arg81_size);
  if (_ret79 == -1)
    return -1;
  const char *_arg84 = "/rename/old";
  const char *_arg85 = "/rename/new";
  int _ret83;
  _ret83 = guestfs_rename (g, _arg84, _arg85);
  if (_ret83 == -1)
    return -1;
  const char *_arg87 = "/rename/old";
  int ret;
  ret = guestfs_is_file (g, _arg87);
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
test_part_get_gpt_type_0 (void)
{
  if (test_part_get_gpt_type_0_skip ()) {
    skipped ("test_part_get_gpt_type_0", "environment variable set");
    return 0;
  }

  const char *_features89[] = { "gdisk", NULL };
  if (!guestfs_feature_available (g, (char **) _features89)) {
    skipped ("test_part_get_gpt_type_0", "group %s not available in daemon",
             _features89[0]);
    return 0;
  }

  /* InitGPT for test_part_get_gpt_type_0: create /dev/sda1 */
  const char *_arg91 = "/dev/sda";
  int _ret90;
  _ret90 = guestfs_blockdev_setrw (g, _arg91);
  if (_ret90 == -1)
    return -1;
  int _ret93;
  _ret93 = guestfs_umount_all (g);
  if (_ret93 == -1)
    return -1;
  int _ret95;
  _ret95 = guestfs_lvm_remove_all (g);
  if (_ret95 == -1)
    return -1;
  const char *_arg98 = "/dev/sda";
  const char *_arg99 = "gpt";
  int _ret97;
  _ret97 = guestfs_part_disk (g, _arg98, _arg99);
  if (_ret97 == -1)
    return -1;

  /* TestResultString for part_get_gpt_type (0) */
  const char *_arg102 = "/dev/sda";
  const char *_arg104 = "01234567-89AB-CDEF-0123-456789ABCDEF";
  int _ret101;
  _ret101 = guestfs_part_set_gpt_type (g, _arg102, 1, _arg104);
  if (_ret101 == -1)
    return -1;
  const char *_arg106 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_gpt_type (g, _arg106, 1);
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
test_cap_set_file_0 (void)
{
  if (test_cap_set_file_0_skip ()) {
    skipped ("test_cap_set_file_0", "environment variable set");
    return 0;
  }

  const char *_features109[] = { "linuxcaps", NULL };
  if (!guestfs_feature_available (g, (char **) _features109)) {
    skipped ("test_cap_set_file_0", "group %s not available in daemon",
             _features109[0]);
    return 0;
  }

  /* InitScratchFS for test_cap_set_file_0 */
  const char *_arg111 = "/dev/sda";
  int _ret110;
  _ret110 = guestfs_blockdev_setrw (g, _arg111);
  if (_ret110 == -1)
    return -1;
  int _ret113;
  _ret113 = guestfs_umount_all (g);
  if (_ret113 == -1)
    return -1;
  int _ret115;
  _ret115 = guestfs_lvm_remove_all (g);
  if (_ret115 == -1)
    return -1;
  const char *_arg118 = "/dev/sdb1";
  const char *_arg119 = "/";
  int _ret117;
  _ret117 = guestfs_mount (g, _arg118, _arg119);
  if (_ret117 == -1)
    return -1;

  /* TestResultString for cap_set_file (0) */
  const char *_arg122 = "/cap_set_file_0";
  int _ret121;
  _ret121 = guestfs_touch (g, _arg122);
  if (_ret121 == -1)
    return -1;
  const char *_arg125 = "/cap_set_file_0";
  const char *_arg126 = "cap_chown=p cap_chown+e";
  int _ret124;
  _ret124 = guestfs_cap_set_file (g, _arg125, _arg126);
  if (_ret124 == -1)
    return -1;
  const char *_arg128 = "/cap_set_file_0";
  CLEANUP_FREE char *ret;
  ret = guestfs_cap_get_file (g, _arg128);
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
test_acl_delete_def_file_0 (void)
{
  if (test_acl_delete_def_file_0_skip ()) {
    skipped ("test_acl_delete_def_file_0", "environment variable set");
    return 0;
  }

  const char *_features130[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) _features130)) {
    skipped ("test_acl_delete_def_file_0", "group %s not available in daemon",
             _features130[0]);
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
test_acl_delete_def_file_1 (void)
{
  if (test_acl_delete_def_file_1_skip ()) {
    skipped ("test_acl_delete_def_file_1", "environment variable set");
    return 0;
  }

  const char *_features131[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) _features131)) {
    skipped ("test_acl_delete_def_file_1", "group %s not available in daemon",
             _features131[0]);
    return 0;
  }

  /* InitScratchFS for test_acl_delete_def_file_1 */
  const char *_arg133 = "/dev/sda";
  int _ret132;
  _ret132 = guestfs_blockdev_setrw (g, _arg133);
  if (_ret132 == -1)
    return -1;
  int _ret135;
  _ret135 = guestfs_umount_all (g);
  if (_ret135 == -1)
    return -1;
  int _ret137;
  _ret137 = guestfs_lvm_remove_all (g);
  if (_ret137 == -1)
    return -1;
  const char *_arg140 = "/dev/sdb1";
  const char *_arg141 = "/";
  int _ret139;
  _ret139 = guestfs_mount (g, _arg140, _arg141);
  if (_ret139 == -1)
    return -1;

  /* TestRun for acl_delete_def_file (1) */
  const char *_arg144 = "/acl_delete_def_file_1";
  int _ret143;
  _ret143 = guestfs_mkdir (g, _arg144);
  if (_ret143 == -1)
    return -1;
  const char *_arg147 = "/acl_delete_def_file_1";
  const char *_arg148 = "default";
  const char *_arg149 = "user::r-x,group::r-x,other::r-x";
  int _ret146;
  _ret146 = guestfs_acl_set_file (g, _arg147, _arg148, _arg149);
  if (_ret146 == -1)
    return -1;
  const char *_arg152 = "/acl_delete_def_file_1";
  int _ret151;
  _ret151 = guestfs_acl_delete_def_file (g, _arg152);
  if (_ret151 == -1)
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
test_acl_set_file_0 (void)
{
  if (test_acl_set_file_0_skip ()) {
    skipped ("test_acl_set_file_0", "environment variable set");
    return 0;
  }

  const char *_features154[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) _features154)) {
    skipped ("test_acl_set_file_0", "group %s not available in daemon",
             _features154[0]);
    return 0;
  }

  /* InitScratchFS for test_acl_set_file_0 */
  const char *_arg156 = "/dev/sda";
  int _ret155;
  _ret155 = guestfs_blockdev_setrw (g, _arg156);
  if (_ret155 == -1)
    return -1;
  int _ret158;
  _ret158 = guestfs_umount_all (g);
  if (_ret158 == -1)
    return -1;
  int _ret160;
  _ret160 = guestfs_lvm_remove_all (g);
  if (_ret160 == -1)
    return -1;
  const char *_arg163 = "/dev/sdb1";
  const char *_arg164 = "/";
  int _ret162;
  _ret162 = guestfs_mount (g, _arg163, _arg164);
  if (_ret162 == -1)
    return -1;

  /* TestRun for acl_set_file (0) */
  const char *_arg167 = "/acl_set_file_0";
  int _ret166;
  _ret166 = guestfs_touch (g, _arg167);
  if (_ret166 == -1)
    return -1;
  const char *_arg170 = "/acl_set_file_0";
  const char *_arg171 = "access";
  const char *_arg172 = "user::r-x,group::r-x,other::r-x";
  int _ret169;
  _ret169 = guestfs_acl_set_file (g, _arg170, _arg171, _arg172);
  if (_ret169 == -1)
    return -1;
  const char *_arg175 = "/acl_set_file_0";
  const char *_arg176 = "access";
  CLEANUP_FREE char *_ret174;
  _ret174 = guestfs_acl_get_file (g, _arg175, _arg176);
  if (_ret174 == NULL)
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
test_mklost_and_found_0 (void)
{
  if (test_mklost_and_found_0_skip ()) {
    skipped ("test_mklost_and_found_0", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_mklost_and_found_0: create ext2 on /dev/sda1 */
  const char *_arg179 = "/dev/sda";
  int _ret178;
  _ret178 = guestfs_blockdev_setrw (g, _arg179);
  if (_ret178 == -1)
    return -1;
  int _ret181;
  _ret181 = guestfs_umount_all (g);
  if (_ret181 == -1)
    return -1;
  int _ret183;
  _ret183 = guestfs_lvm_remove_all (g);
  if (_ret183 == -1)
    return -1;
  const char *_arg186 = "/dev/sda";
  const char *_arg187 = "mbr";
  int _ret185;
  _ret185 = guestfs_part_disk (g, _arg186, _arg187);
  if (_ret185 == -1)
    return -1;
  const char *_arg190 = "ext2";
  const char *_arg191 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs192;
  _optargs192.bitmask = UINT64_C(0x0);
  int _ret189;
  _ret189 = guestfs_mkfs_opts_argv (g, _arg190, _arg191, &_optargs192);
  if (_ret189 == -1)
    return -1;
  const char *_arg194 = "/dev/sda1";
  const char *_arg195 = "/";
  int _ret193;
  _ret193 = guestfs_mount (g, _arg194, _arg195);
  if (_ret193 == -1)
    return -1;

  /* TestRun for mklost_and_found (0) */
  const char *_arg198 = "/lost+found";
  int _ret197;
  _ret197 = guestfs_rm_rf (g, _arg198);
  if (_ret197 == -1)
    return -1;
  const char *_arg201 = "/";
  int _ret200;
  _ret200 = guestfs_mklost_and_found (g, _arg201);
  if (_ret200 == -1)
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
test_mktemp_0 (void)
{
  if (test_mktemp_0_skip ()) {
    skipped ("test_mktemp_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mktemp_0 */
  const char *_arg204 = "/dev/sda";
  int _ret203;
  _ret203 = guestfs_blockdev_setrw (g, _arg204);
  if (_ret203 == -1)
    return -1;
  int _ret206;
  _ret206 = guestfs_umount_all (g);
  if (_ret206 == -1)
    return -1;
  int _ret208;
  _ret208 = guestfs_lvm_remove_all (g);
  if (_ret208 == -1)
    return -1;
  const char *_arg211 = "/dev/sdb1";
  const char *_arg212 = "/";
  int _ret210;
  _ret210 = guestfs_mount (g, _arg211, _arg212);
  if (_ret210 == -1)
    return -1;

  /* TestRun for mktemp (0) */
  const char *_arg215 = "/mktemp";
  int _ret214;
  _ret214 = guestfs_mkdir (g, _arg215);
  if (_ret214 == -1)
    return -1;
  const char *_arg218 = "/mktemp/tmpXXXXXX";
  struct guestfs_mktemp_argv _optargs219;
  _optargs219.bitmask = UINT64_C(0x0);
  CLEANUP_FREE char *_ret217;
  _ret217 = guestfs_mktemp_argv (g, _arg218, &_optargs219);
  if (_ret217 == NULL)
      return -1;
  const char *_arg221 = "/mktemp/tmpXXXXXX";
  struct guestfs_mktemp_argv _optargs222;
  _optargs222.suffix = "suff";
  _optargs222.bitmask = UINT64_C(0x1);
  CLEANUP_FREE char *_ret220;
  _ret220 = guestfs_mktemp_argv (g, _arg221, &_optargs222);
  if (_ret220 == NULL)
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
test_mke2fs_0 (void)
{
  if (test_mke2fs_0_skip ()) {
    skipped ("test_mke2fs_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mke2fs_0 */
  const char *_arg224 = "/dev/sda";
  int _ret223;
  _ret223 = guestfs_blockdev_setrw (g, _arg224);
  if (_ret223 == -1)
    return -1;
  int _ret226;
  _ret226 = guestfs_umount_all (g);
  if (_ret226 == -1)
    return -1;
  int _ret228;
  _ret228 = guestfs_lvm_remove_all (g);
  if (_ret228 == -1)
    return -1;

  /* TestResultString for mke2fs (0) */
  const char *_arg231 = "/dev/sda";
  const char *_arg232 = "mbr";
  int _ret230;
  _ret230 = guestfs_part_init (g, _arg231, _arg232);
  if (_ret230 == -1)
    return -1;
  const char *_arg235 = "/dev/sda";
  const char *_arg236 = "p";
  int _ret234;
  _ret234 = guestfs_part_add (g, _arg235, _arg236, 64, 204799);
  if (_ret234 == -1)
    return -1;
  const char *_arg241 = "/dev/sda";
  const char *_arg242 = "p";
  int _ret240;
  _ret240 = guestfs_part_add (g, _arg241, _arg242, 204800, -64);
  if (_ret240 == -1)
    return -1;
  const char *_arg247 = "/dev/sda1";
  struct guestfs_mke2fs_argv _optargs248;
  _optargs248.blocksize = 4096;
  _optargs248.journaldev = 1;
  _optargs248.bitmask = UINT64_C(0x100000002);
  int _ret246;
  _ret246 = guestfs_mke2fs_argv (g, _arg247, &_optargs248);
  if (_ret246 == -1)
    return -1;
  const char *_arg250 = "/dev/sda2";
  struct guestfs_mke2fs_argv _optargs251;
  _optargs251.blocksize = 4096;
  _optargs251.journaldevice = "/dev/sda1";
  _optargs251.fstype = "ext2";
  _optargs251.bitmask = UINT64_C(0x44002);
  int _ret249;
  _ret249 = guestfs_mke2fs_argv (g, _arg250, &_optargs251);
  if (_ret249 == -1)
    return -1;
  const char *_arg253 = "/dev/sda2";
  const char *_arg254 = "/";
  int _ret252;
  _ret252 = guestfs_mount (g, _arg253, _arg254);
  if (_ret252 == -1)
    return -1;
  const char *_arg257 = "/new";
  const char *_arg258 = "new file contents";
  size_t _arg258_size = 17;
  int _ret256;
  _ret256 = guestfs_write (g, _arg257, _arg258, _arg258_size);
  if (_ret256 == -1)
    return -1;
  const char *_arg260 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg260);
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
test_mke2fs_1 (void)
{
  if (test_mke2fs_1_skip ()) {
    skipped ("test_mke2fs_1", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mke2fs_1 */
  const char *_arg263 = "/dev/sda";
  int _ret262;
  _ret262 = guestfs_blockdev_setrw (g, _arg263);
  if (_ret262 == -1)
    return -1;
  int _ret265;
  _ret265 = guestfs_umount_all (g);
  if (_ret265 == -1)
    return -1;
  int _ret267;
  _ret267 = guestfs_lvm_remove_all (g);
  if (_ret267 == -1)
    return -1;

  /* TestResultString for mke2fs (1) */
  const char *_arg270 = "/dev/sda";
  const char *_arg271 = "mbr";
  int _ret269;
  _ret269 = guestfs_part_init (g, _arg270, _arg271);
  if (_ret269 == -1)
    return -1;
  const char *_arg274 = "/dev/sda";
  const char *_arg275 = "p";
  int _ret273;
  _ret273 = guestfs_part_add (g, _arg274, _arg275, 64, 204799);
  if (_ret273 == -1)
    return -1;
  const char *_arg280 = "/dev/sda";
  const char *_arg281 = "p";
  int _ret279;
  _ret279 = guestfs_part_add (g, _arg280, _arg281, 204800, -64);
  if (_ret279 == -1)
    return -1;
  const char *_arg286 = "/dev/sda1";
  struct guestfs_mke2fs_argv _optargs287;
  _optargs287.blocksize = 4096;
  _optargs287.journaldevice = "/dev/sda1";
  _optargs287.label = "JOURNAL";
  _optargs287.fstype = "ext2";
  _optargs287.journaldev = 1;
  _optargs287.bitmask = UINT64_C(0x10004c002);
  int _ret285;
  _ret285 = guestfs_mke2fs_argv (g, _arg286, &_optargs287);
  if (_ret285 == -1)
    return -1;
  const char *_arg289 = "/dev/sda2";
  struct guestfs_mke2fs_argv _optargs290;
  _optargs290.blocksize = 4096;
  _optargs290.journaldevice = "LABEL=JOURNAL";
  _optargs290.label = "JOURNAL";
  _optargs290.fstype = "ext2";
  _optargs290.bitmask = UINT64_C(0x4c002);
  int _ret288;
  _ret288 = guestfs_mke2fs_argv (g, _arg289, &_optargs290);
  if (_ret288 == -1)
    return -1;
  const char *_arg292 = "/dev/sda2";
  const char *_arg293 = "/";
  int _ret291;
  _ret291 = guestfs_mount (g, _arg292, _arg293);
  if (_ret291 == -1)
    return -1;
  const char *_arg296 = "/new";
  const char *_arg297 = "new file contents";
  size_t _arg297_size = 17;
  int _ret295;
  _ret295 = guestfs_write (g, _arg296, _arg297, _arg297_size);
  if (_ret295 == -1)
    return -1;
  const char *_arg299 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg299);
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
test_mke2fs_2 (void)
{
  if (test_mke2fs_2_skip ()) {
    skipped ("test_mke2fs_2", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mke2fs_2 */
  const char *_arg302 = "/dev/sda";
  int _ret301;
  _ret301 = guestfs_blockdev_setrw (g, _arg302);
  if (_ret301 == -1)
    return -1;
  int _ret304;
  _ret304 = guestfs_umount_all (g);
  if (_ret304 == -1)
    return -1;
  int _ret306;
  _ret306 = guestfs_lvm_remove_all (g);
  if (_ret306 == -1)
    return -1;

  /* TestResultString for mke2fs (2) */
  const char *_arg309 = "/dev/sda";
  const char *_arg310 = "mbr";
  int _ret308;
  _ret308 = guestfs_part_init (g, _arg309, _arg310);
  if (_ret308 == -1)
    return -1;
  const char *_arg313 = "/dev/sda";
  const char *_arg314 = "p";
  int _ret312;
  _ret312 = guestfs_part_add (g, _arg313, _arg314, 64, 204799);
  if (_ret312 == -1)
    return -1;
  const char *_arg319 = "/dev/sda";
  const char *_arg320 = "p";
  int _ret318;
  _ret318 = guestfs_part_add (g, _arg319, _arg320, 204800, -64);
  if (_ret318 == -1)
    return -1;
  const char *_arg325 = "/dev/sda1";
  struct guestfs_mke2fs_argv _optargs326;
  _optargs326.blocksize = 4096;
  _optargs326.uuid = "fd5f5bd4-9254-0e03-76b4-43f62553291c";
  _optargs326.journaldev = 1;
  _optargs326.bitmask = UINT64_C(0x100100002);
  int _ret324;
  _ret324 = guestfs_mke2fs_argv (g, _arg325, &_optargs326);
  if (_ret324 == -1)
    return -1;
  const char *_arg328 = "/dev/sda2";
  struct guestfs_mke2fs_argv _optargs329;
  _optargs329.blocksize = 4096;
  _optargs329.journaldevice = "UUID=fd5f5bd4-9254-0e03-76b4-43f62553291c";
  _optargs329.label = "JOURNAL";
  _optargs329.fstype = "ext2";
  _optargs329.forcecreate = 1;
  _optargs329.bitmask = UINT64_C(0x24c002);
  int _ret327;
  _ret327 = guestfs_mke2fs_argv (g, _arg328, &_optargs329);
  if (_ret327 == -1)
    return -1;
  const char *_arg331 = "/dev/sda2";
  const char *_arg332 = "/";
  int _ret330;
  _ret330 = guestfs_mount (g, _arg331, _arg332);
  if (_ret330 == -1)
    return -1;
  const char *_arg335 = "/new";
  const char *_arg336 = "new file contents";
  size_t _arg336_size = 17;
  int _ret334;
  _ret334 = guestfs_write (g, _arg335, _arg336, _arg336_size);
  if (_ret334 == -1)
    return -1;
  const char *_arg338 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg338);
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
test_rm_f_0 (void)
{
  if (test_rm_f_0_skip ()) {
    skipped ("test_rm_f_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_rm_f_0 */
  const char *_arg341 = "/dev/sda";
  int _ret340;
  _ret340 = guestfs_blockdev_setrw (g, _arg341);
  if (_ret340 == -1)
    return -1;
  int _ret343;
  _ret343 = guestfs_umount_all (g);
  if (_ret343 == -1)
    return -1;
  int _ret345;
  _ret345 = guestfs_lvm_remove_all (g);
  if (_ret345 == -1)
    return -1;
  const char *_arg348 = "/dev/sdb1";
  const char *_arg349 = "/";
  int _ret347;
  _ret347 = guestfs_mount (g, _arg348, _arg349);
  if (_ret347 == -1)
    return -1;

  /* TestResultFalse for rm_f (0) */
  const char *_arg352 = "/rm_f";
  int _ret351;
  _ret351 = guestfs_mkdir (g, _arg352);
  if (_ret351 == -1)
    return -1;
  const char *_arg355 = "/rm_f/foo";
  int _ret354;
  _ret354 = guestfs_touch (g, _arg355);
  if (_ret354 == -1)
    return -1;
  const char *_arg358 = "/rm_f/foo";
  int _ret357;
  _ret357 = guestfs_rm_f (g, _arg358);
  if (_ret357 == -1)
    return -1;
  const char *_arg361 = "/rm_f/not_exists";
  int _ret360;
  _ret360 = guestfs_rm_f (g, _arg361);
  if (_ret360 == -1)
    return -1;
  const char *_arg363 = "/rm_f/foo";
  int ret;
  ret = guestfs_exists (g, _arg363);
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
test_rm_f_1 (void)
{
  if (test_rm_f_1_skip ()) {
    skipped ("test_rm_f_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_rm_f_1 */
  const char *_arg366 = "/dev/sda";
  int _ret365;
  _ret365 = guestfs_blockdev_setrw (g, _arg366);
  if (_ret365 == -1)
    return -1;
  int _ret368;
  _ret368 = guestfs_umount_all (g);
  if (_ret368 == -1)
    return -1;
  int _ret370;
  _ret370 = guestfs_lvm_remove_all (g);
  if (_ret370 == -1)
    return -1;
  const char *_arg373 = "/dev/sdb1";
  const char *_arg374 = "/";
  int _ret372;
  _ret372 = guestfs_mount (g, _arg373, _arg374);
  if (_ret372 == -1)
    return -1;

  /* TestLastFail for rm_f (1) */
  const char *_arg377 = "/rm_f2";
  int _ret376;
  _ret376 = guestfs_mkdir (g, _arg377);
  if (_ret376 == -1)
    return -1;
  const char *_arg380 = "/rm_f2/foo";
  int _ret379;
  _ret379 = guestfs_mkdir (g, _arg380);
  if (_ret379 == -1)
    return -1;
  const char *_arg383 = "/rm_f2/foo";
  int _ret382;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret382 = guestfs_rm_f (g, _arg383);
  guestfs_pop_error_handler (g);
  if (_ret382 != -1)
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
test_xfs_repair_0 (void)
{
  if (test_xfs_repair_0_skip ()) {
    skipped ("test_xfs_repair_0", "environment variable set");
    return 0;
  }

  const char *_features385[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features385)) {
    skipped ("test_xfs_repair_0", "group %s not available in daemon",
             _features385[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_xfs_repair_0 */
  const char *_arg387 = "/dev/sda";
  int _ret386;
  _ret386 = guestfs_blockdev_setrw (g, _arg387);
  if (_ret386 == -1)
    return -1;
  int _ret389;
  _ret389 = guestfs_umount_all (g);
  if (_ret389 == -1)
    return -1;
  int _ret391;
  _ret391 = guestfs_lvm_remove_all (g);
  if (_ret391 == -1)
    return -1;

  /* TestRun for xfs_repair (0) */
  const char *_arg394 = "/dev/sda";
  const char *_arg395 = "mbr";
  int _ret393;
  _ret393 = guestfs_part_disk (g, _arg394, _arg395);
  if (_ret393 == -1)
    return -1;
  const char *_arg398 = "xfs";
  const char *_arg399 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs400;
  _optargs400.bitmask = UINT64_C(0x0);
  int _ret397;
  _ret397 = guestfs_mkfs_opts_argv (g, _arg398, _arg399, &_optargs400);
  if (_ret397 == -1)
    return -1;
  const char *_arg402 = "/dev/sda1";
  struct guestfs_xfs_repair_argv _optargs403;
  _optargs403.nomodify = 1;
  _optargs403.bitmask = UINT64_C(0x2);
  int _ret401;
  _ret401 = guestfs_xfs_repair_argv (g, _arg402, &_optargs403);
  if (_ret401 == -1)
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
test_xfs_admin_0 (void)
{
  if (test_xfs_admin_0_skip ()) {
    skipped ("test_xfs_admin_0", "environment variable set");
    return 0;
  }

  const char *_features404[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features404)) {
    skipped ("test_xfs_admin_0", "group %s not available in daemon",
             _features404[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_xfs_admin_0 */
  const char *_arg406 = "/dev/sda";
  int _ret405;
  _ret405 = guestfs_blockdev_setrw (g, _arg406);
  if (_ret405 == -1)
    return -1;
  int _ret408;
  _ret408 = guestfs_umount_all (g);
  if (_ret408 == -1)
    return -1;
  int _ret410;
  _ret410 = guestfs_lvm_remove_all (g);
  if (_ret410 == -1)
    return -1;

  /* TestResult for xfs_admin (0) */
  const char *_arg412 = "/dev/sda";
  const char *_arg413 = "mbr";
  int ret4;
  ret4 = guestfs_part_disk (g, _arg412, _arg413);
  if (ret4 == -1)
    return -1;
  const char *_arg415 = "xfs";
  const char *_arg416 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs417;
  _optargs417.bitmask = UINT64_C(0x0);
  int ret3;
  ret3 = guestfs_mkfs_opts_argv (g, _arg415, _arg416, &_optargs417);
  if (ret3 == -1)
    return -1;
  const char *_arg418 = "/dev/sda1";
  struct guestfs_xfs_admin_argv _optargs419;
  _optargs419.lazycounter = 0;
  _optargs419.bitmask = UINT64_C(0x10);
  int ret2;
  ret2 = guestfs_xfs_admin_argv (g, _arg418, &_optargs419);
  if (ret2 == -1)
    return -1;
  const char *_arg420 = "/dev/sda1";
  const char *_arg421 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg420, _arg421);
  if (ret1 == -1)
    return -1;
  const char *_arg423 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, _arg423);
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
test_xfs_growfs_0 (void)
{
  if (test_xfs_growfs_0_skip ()) {
    skipped ("test_xfs_growfs_0", "environment variable set");
    return 0;
  }

  const char *_features425[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features425)) {
    skipped ("test_xfs_growfs_0", "group %s not available in daemon",
             _features425[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_xfs_growfs_0 */
  const char *_arg427 = "/dev/sda";
  int _ret426;
  _ret426 = guestfs_blockdev_setrw (g, _arg427);
  if (_ret426 == -1)
    return -1;
  int _ret429;
  _ret429 = guestfs_umount_all (g);
  if (_ret429 == -1)
    return -1;
  int _ret431;
  _ret431 = guestfs_lvm_remove_all (g);
  if (_ret431 == -1)
    return -1;

  /* TestResult for xfs_growfs (0) */
  const char *_arg433 = "/dev/sda";
  const char *_arg434 = "mbr";
  int ret8;
  ret8 = guestfs_part_disk (g, _arg433, _arg434);
  if (ret8 == -1)
    return -1;
  const char *_arg436 = "/dev/sda1";
  int ret7;
  ret7 = guestfs_pvcreate (g, _arg436);
  if (ret7 == -1)
    return -1;
  const char *_arg438 = "VG";
  const char *_arg439_0 = "/dev/sda1";
  const char *const _arg439[] = {
    _arg439_0,
    NULL
  };
  int ret6;
  ret6 = guestfs_vgcreate (g, _arg438, (char **) _arg439);
  if (ret6 == -1)
    return -1;
  const char *_arg441 = "LV";
  const char *_arg442 = "VG";
  int ret5;
  ret5 = guestfs_lvcreate (g, _arg441, _arg442, 40);
  if (ret5 == -1)
    return -1;
  const char *_arg445 = "xfs";
  const char *_arg446 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs447;
  _optargs447.bitmask = UINT64_C(0x0);
  int ret4;
  ret4 = guestfs_mkfs_opts_argv (g, _arg445, _arg446, &_optargs447);
  if (ret4 == -1)
    return -1;
  const char *_arg448 = "/dev/VG/LV";
  int ret3;
  ret3 = guestfs_lvresize (g, _arg448, 80);
  if (ret3 == -1)
    return -1;
  const char *_arg451 = "/dev/VG/LV";
  const char *_arg452 = "/";
  int ret2;
  ret2 = guestfs_mount (g, _arg451, _arg452);
  if (ret2 == -1)
    return -1;
  const char *_arg454 = "/";
  struct guestfs_xfs_growfs_argv _optargs455;
  _optargs455.datasec = 1;
  _optargs455.logsec = 0;
  _optargs455.rtsec = 0;
  _optargs455.bitmask = UINT64_C(0x7);
  int ret1;
  ret1 = guestfs_xfs_growfs_argv (g, _arg454, &_optargs455);
  if (ret1 == -1)
    return -1;
  const char *_arg456 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, _arg456);
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
test_utsname_0 (void)
{
  if (test_utsname_0_skip ()) {
    skipped ("test_utsname_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_utsname_0 */
  const char *_arg459 = "/dev/sda";
  int _ret458;
  _ret458 = guestfs_blockdev_setrw (g, _arg459);
  if (_ret458 == -1)
    return -1;
  int _ret461;
  _ret461 = guestfs_umount_all (g);
  if (_ret461 == -1)
    return -1;
  int _ret463;
  _ret463 = guestfs_lvm_remove_all (g);
  if (_ret463 == -1)
    return -1;

  /* TestRun for utsname (0) */
  CLEANUP_FREE_UTSNAME struct guestfs_utsname *_ret465;
  _ret465 = guestfs_utsname (g);
  if (_ret465 == NULL)
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
test_vgchange_uuid_all_0 (void)
{
  if (test_vgchange_uuid_all_0_skip ()) {
    skipped ("test_vgchange_uuid_all_0", "environment variable set");
    return 0;
  }

  const char *_features467[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features467)) {
    skipped ("test_vgchange_uuid_all_0", "group %s not available in daemon",
             _features467[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_vgchange_uuid_all_0 */
  const char *_arg469 = "/dev/sda";
  int _ret468;
  _ret468 = guestfs_blockdev_setrw (g, _arg469);
  if (_ret468 == -1)
    return -1;
  int _ret471;
  _ret471 = guestfs_umount_all (g);
  if (_ret471 == -1)
    return -1;
  int _ret473;
  _ret473 = guestfs_lvm_remove_all (g);
  if (_ret473 == -1)
    return -1;

  /* TestRun for vgchange_uuid_all (0) */
  const char *_arg476 = "/dev/sda";
  const char *_arg477 = "mbr";
  int _ret475;
  _ret475 = guestfs_part_disk (g, _arg476, _arg477);
  if (_ret475 == -1)
    return -1;
  const char *_arg480 = "/dev/sda1";
  int _ret479;
  _ret479 = guestfs_pvcreate (g, _arg480);
  if (_ret479 == -1)
    return -1;
  const char *_arg483 = "VG";
  const char *_arg484_0 = "/dev/sda1";
  const char *const _arg484[] = {
    _arg484_0,
    NULL
  };
  int _ret482;
  _ret482 = guestfs_vgcreate (g, _arg483, (char **) _arg484);
  if (_ret482 == -1)
    return -1;
  int _ret486;
  _ret486 = guestfs_vgchange_uuid_all (g);
  if (_ret486 == -1)
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
test_vgchange_uuid_0 (void)
{
  if (test_vgchange_uuid_0_skip ()) {
    skipped ("test_vgchange_uuid_0", "environment variable set");
    return 0;
  }

  const char *_features488[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features488)) {
    skipped ("test_vgchange_uuid_0", "group %s not available in daemon",
             _features488[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_vgchange_uuid_0 */
  const char *_arg490 = "/dev/sda";
  int _ret489;
  _ret489 = guestfs_blockdev_setrw (g, _arg490);
  if (_ret489 == -1)
    return -1;
  int _ret492;
  _ret492 = guestfs_umount_all (g);
  if (_ret492 == -1)
    return -1;
  int _ret494;
  _ret494 = guestfs_lvm_remove_all (g);
  if (_ret494 == -1)
    return -1;

  /* TestRun for vgchange_uuid (0) */
  const char *_arg497 = "/dev/sda";
  const char *_arg498 = "mbr";
  int _ret496;
  _ret496 = guestfs_part_disk (g, _arg497, _arg498);
  if (_ret496 == -1)
    return -1;
  const char *_arg501 = "/dev/sda1";
  int _ret500;
  _ret500 = guestfs_pvcreate (g, _arg501);
  if (_ret500 == -1)
    return -1;
  const char *_arg504 = "VG";
  const char *_arg505_0 = "/dev/sda1";
  const char *const _arg505[] = {
    _arg505_0,
    NULL
  };
  int _ret503;
  _ret503 = guestfs_vgcreate (g, _arg504, (char **) _arg505);
  if (_ret503 == -1)
    return -1;
  const char *_arg508 = "/dev/VG";
  int _ret507;
  _ret507 = guestfs_vgchange_uuid (g, _arg508);
  if (_ret507 == -1)
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
test_pvchange_uuid_all_0 (void)
{
  if (test_pvchange_uuid_all_0_skip ()) {
    skipped ("test_pvchange_uuid_all_0", "environment variable set");
    return 0;
  }

  const char *_features510[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features510)) {
    skipped ("test_pvchange_uuid_all_0", "group %s not available in daemon",
             _features510[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_pvchange_uuid_all_0 */
  const char *_arg512 = "/dev/sda";
  int _ret511;
  _ret511 = guestfs_blockdev_setrw (g, _arg512);
  if (_ret511 == -1)
    return -1;
  int _ret514;
  _ret514 = guestfs_umount_all (g);
  if (_ret514 == -1)
    return -1;
  int _ret516;
  _ret516 = guestfs_lvm_remove_all (g);
  if (_ret516 == -1)
    return -1;

  /* TestRun for pvchange_uuid_all (0) */
  const char *_arg519 = "/dev/sda";
  const char *_arg520 = "mbr";
  int _ret518;
  _ret518 = guestfs_part_disk (g, _arg519, _arg520);
  if (_ret518 == -1)
    return -1;
  const char *_arg523 = "/dev/sda1";
  int _ret522;
  _ret522 = guestfs_pvcreate (g, _arg523);
  if (_ret522 == -1)
    return -1;
  int _ret525;
  _ret525 = guestfs_pvchange_uuid_all (g);
  if (_ret525 == -1)
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
test_pvchange_uuid_0 (void)
{
  if (test_pvchange_uuid_0_skip ()) {
    skipped ("test_pvchange_uuid_0", "environment variable set");
    return 0;
  }

  const char *_features527[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features527)) {
    skipped ("test_pvchange_uuid_0", "group %s not available in daemon",
             _features527[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_pvchange_uuid_0 */
  const char *_arg529 = "/dev/sda";
  int _ret528;
  _ret528 = guestfs_blockdev_setrw (g, _arg529);
  if (_ret528 == -1)
    return -1;
  int _ret531;
  _ret531 = guestfs_umount_all (g);
  if (_ret531 == -1)
    return -1;
  int _ret533;
  _ret533 = guestfs_lvm_remove_all (g);
  if (_ret533 == -1)
    return -1;

  /* TestRun for pvchange_uuid (0) */
  const char *_arg536 = "/dev/sda";
  const char *_arg537 = "mbr";
  int _ret535;
  _ret535 = guestfs_part_disk (g, _arg536, _arg537);
  if (_ret535 == -1)
    return -1;
  const char *_arg540 = "/dev/sda1";
  int _ret539;
  _ret539 = guestfs_pvcreate (g, _arg540);
  if (_ret539 == -1)
    return -1;
  const char *_arg543 = "/dev/sda1";
  int _ret542;
  _ret542 = guestfs_pvchange_uuid (g, _arg543);
  if (_ret542 == -1)
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
test_xfs_info_0 (void)
{
  if (test_xfs_info_0_skip ()) {
    skipped ("test_xfs_info_0", "environment variable set");
    return 0;
  }

  const char *_features545[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features545)) {
    skipped ("test_xfs_info_0", "group %s not available in daemon",
             _features545[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_xfs_info_0 */
  const char *_arg547 = "/dev/sda";
  int _ret546;
  _ret546 = guestfs_blockdev_setrw (g, _arg547);
  if (_ret546 == -1)
    return -1;
  int _ret549;
  _ret549 = guestfs_umount_all (g);
  if (_ret549 == -1)
    return -1;
  int _ret551;
  _ret551 = guestfs_lvm_remove_all (g);
  if (_ret551 == -1)
    return -1;

  /* TestResult for xfs_info (0) */
  const char *_arg553 = "/dev/sda";
  const char *_arg554 = "mbr";
  int ret3;
  ret3 = guestfs_part_disk (g, _arg553, _arg554);
  if (ret3 == -1)
    return -1;
  const char *_arg556 = "xfs";
  const char *_arg557 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs558;
  _optargs558.bitmask = UINT64_C(0x0);
  int ret2;
  ret2 = guestfs_mkfs_opts_argv (g, _arg556, _arg557, &_optargs558);
  if (ret2 == -1)
    return -1;
  const char *_arg559 = "/dev/sda1";
  const char *_arg560 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg559, _arg560);
  if (ret1 == -1)
    return -1;
  const char *_arg562 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, _arg562);
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
test_nr_devices_0 (void)
{
  if (test_nr_devices_0_skip ()) {
    skipped ("test_nr_devices_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_nr_devices_0 */
  const char *_arg565 = "/dev/sda";
  int _ret564;
  _ret564 = guestfs_blockdev_setrw (g, _arg565);
  if (_ret564 == -1)
    return -1;
  int _ret567;
  _ret567 = guestfs_umount_all (g);
  if (_ret567 == -1)
    return -1;
  int _ret569;
  _ret569 = guestfs_lvm_remove_all (g);
  if (_ret569 == -1)
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
test_device_index_0 (void)
{
  if (test_device_index_0_skip ()) {
    skipped ("test_device_index_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_device_index_0 */
  const char *_arg573 = "/dev/sda";
  int _ret572;
  _ret572 = guestfs_blockdev_setrw (g, _arg573);
  if (_ret572 == -1)
    return -1;
  int _ret575;
  _ret575 = guestfs_umount_all (g);
  if (_ret575 == -1)
    return -1;
  int _ret577;
  _ret577 = guestfs_lvm_remove_all (g);
  if (_ret577 == -1)
    return -1;

  /* TestResult for device_index (0) */
  const char *_arg579 = "/dev/sda";
  int ret;
  ret = guestfs_device_index (g, _arg579);
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
test_btrfs_fsck_0 (void)
{
  if (test_btrfs_fsck_0_skip ()) {
    skipped ("test_btrfs_fsck_0", "environment variable set");
    return 0;
  }

  const char *_features581[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features581)) {
    skipped ("test_btrfs_fsck_0", "group %s not available in daemon",
             _features581[0]);
    return 0;
  }

  /* InitPartition for test_btrfs_fsck_0: create /dev/sda1 */
  const char *_arg583 = "/dev/sda";
  int _ret582;
  _ret582 = guestfs_blockdev_setrw (g, _arg583);
  if (_ret582 == -1)
    return -1;
  int _ret585;
  _ret585 = guestfs_umount_all (g);
  if (_ret585 == -1)
    return -1;
  int _ret587;
  _ret587 = guestfs_lvm_remove_all (g);
  if (_ret587 == -1)
    return -1;
  const char *_arg590 = "/dev/sda";
  const char *_arg591 = "mbr";
  int _ret589;
  _ret589 = guestfs_part_disk (g, _arg590, _arg591);
  if (_ret589 == -1)
    return -1;

  /* TestRun for btrfs_fsck (0) */
  const char *_arg594_0 = "/dev/sda1";
  const char *const _arg594[] = {
    _arg594_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs595;
  _optargs595.bitmask = UINT64_C(0x0);
  int _ret593;
  _ret593 = guestfs_mkfs_btrfs_argv (g, (char **) _arg594, &_optargs595);
  if (_ret593 == -1)
    return -1;
  const char *_arg597 = "/dev/sda1";
  struct guestfs_btrfs_fsck_argv _optargs598;
  _optargs598.bitmask = UINT64_C(0x0);
  int _ret596;
  _ret596 = guestfs_btrfs_fsck_argv (g, _arg597, &_optargs598);
  if (_ret596 == -1)
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
test_btrfs_set_seeding_0 (void)
{
  if (test_btrfs_set_seeding_0_skip ()) {
    skipped ("test_btrfs_set_seeding_0", "environment variable set");
    return 0;
  }

  const char *_features599[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features599)) {
    skipped ("test_btrfs_set_seeding_0", "group %s not available in daemon",
             _features599[0]);
    return 0;
  }

  /* InitPartition for test_btrfs_set_seeding_0: create /dev/sda1 */
  const char *_arg601 = "/dev/sda";
  int _ret600;
  _ret600 = guestfs_blockdev_setrw (g, _arg601);
  if (_ret600 == -1)
    return -1;
  int _ret603;
  _ret603 = guestfs_umount_all (g);
  if (_ret603 == -1)
    return -1;
  int _ret605;
  _ret605 = guestfs_lvm_remove_all (g);
  if (_ret605 == -1)
    return -1;
  const char *_arg608 = "/dev/sda";
  const char *_arg609 = "mbr";
  int _ret607;
  _ret607 = guestfs_part_disk (g, _arg608, _arg609);
  if (_ret607 == -1)
    return -1;

  /* TestRun for btrfs_set_seeding (0) */
  const char *_arg612_0 = "/dev/sda1";
  const char *const _arg612[] = {
    _arg612_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs613;
  _optargs613.bitmask = UINT64_C(0x0);
  int _ret611;
  _ret611 = guestfs_mkfs_btrfs_argv (g, (char **) _arg612, &_optargs613);
  if (_ret611 == -1)
    return -1;
  const char *_arg615 = "/dev/sda1";
  int _ret614;
  _ret614 = guestfs_btrfs_set_seeding (g, _arg615, 1);
  if (_ret614 == -1)
    return -1;
  const char *_arg619 = "/dev/sda1";
  int _ret618;
  _ret618 = guestfs_btrfs_set_seeding (g, _arg619, 0);
  if (_ret618 == -1)
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
test_btrfs_filesystem_sync_0 (void)
{
  if (test_btrfs_filesystem_sync_0_skip ()) {
    skipped ("test_btrfs_filesystem_sync_0", "environment variable set");
    return 0;
  }

  const char *_features622[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features622)) {
    skipped ("test_btrfs_filesystem_sync_0", "group %s not available in daemon",
             _features622[0]);
    return 0;
  }

  /* InitPartition for test_btrfs_filesystem_sync_0: create /dev/sda1 */
  const char *_arg624 = "/dev/sda";
  int _ret623;
  _ret623 = guestfs_blockdev_setrw (g, _arg624);
  if (_ret623 == -1)
    return -1;
  int _ret626;
  _ret626 = guestfs_umount_all (g);
  if (_ret626 == -1)
    return -1;
  int _ret628;
  _ret628 = guestfs_lvm_remove_all (g);
  if (_ret628 == -1)
    return -1;
  const char *_arg631 = "/dev/sda";
  const char *_arg632 = "mbr";
  int _ret630;
  _ret630 = guestfs_part_disk (g, _arg631, _arg632);
  if (_ret630 == -1)
    return -1;

  /* TestRun for btrfs_filesystem_sync (0) */
  const char *_arg635_0 = "/dev/sda1";
  const char *const _arg635[] = {
    _arg635_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs636;
  _optargs636.bitmask = UINT64_C(0x0);
  int _ret634;
  _ret634 = guestfs_mkfs_btrfs_argv (g, (char **) _arg635, &_optargs636);
  if (_ret634 == -1)
    return -1;
  const char *_arg638 = "/dev/sda1";
  const char *_arg639 = "/";
  int _ret637;
  _ret637 = guestfs_mount (g, _arg638, _arg639);
  if (_ret637 == -1)
    return -1;
  const char *_arg642 = "/test1";
  int _ret641;
  _ret641 = guestfs_btrfs_subvolume_create (g, _arg642);
  if (_ret641 == -1)
    return -1;
  const char *_arg645 = "/test1";
  int _ret644;
  _ret644 = guestfs_btrfs_filesystem_sync (g, _arg645);
  if (_ret644 == -1)
    return -1;
  const char *_arg648 = "/test1";
  int _ret647;
  _ret647 = guestfs_btrfs_filesystem_balance (g, _arg648);
  if (_ret647 == -1)
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
test_btrfs_subvolume_delete_0 (void)
{
  if (test_btrfs_subvolume_delete_0_skip ()) {
    skipped ("test_btrfs_subvolume_delete_0", "environment variable set");
    return 0;
  }

  const char *_features650[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features650)) {
    skipped ("test_btrfs_subvolume_delete_0", "group %s not available in daemon",
             _features650[0]);
    return 0;
  }

  /* InitPartition for test_btrfs_subvolume_delete_0: create /dev/sda1 */
  const char *_arg652 = "/dev/sda";
  int _ret651;
  _ret651 = guestfs_blockdev_setrw (g, _arg652);
  if (_ret651 == -1)
    return -1;
  int _ret654;
  _ret654 = guestfs_umount_all (g);
  if (_ret654 == -1)
    return -1;
  int _ret656;
  _ret656 = guestfs_lvm_remove_all (g);
  if (_ret656 == -1)
    return -1;
  const char *_arg659 = "/dev/sda";
  const char *_arg660 = "mbr";
  int _ret658;
  _ret658 = guestfs_part_disk (g, _arg659, _arg660);
  if (_ret658 == -1)
    return -1;

  /* TestRun for btrfs_subvolume_delete (0) */
  const char *_arg663_0 = "/dev/sda1";
  const char *const _arg663[] = {
    _arg663_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs664;
  _optargs664.bitmask = UINT64_C(0x0);
  int _ret662;
  _ret662 = guestfs_mkfs_btrfs_argv (g, (char **) _arg663, &_optargs664);
  if (_ret662 == -1)
    return -1;
  const char *_arg666 = "/dev/sda1";
  const char *_arg667 = "/";
  int _ret665;
  _ret665 = guestfs_mount (g, _arg666, _arg667);
  if (_ret665 == -1)
    return -1;
  const char *_arg670 = "/test1";
  int _ret669;
  _ret669 = guestfs_btrfs_subvolume_create (g, _arg670);
  if (_ret669 == -1)
    return -1;
  const char *_arg673 = "/test1";
  int _ret672;
  _ret672 = guestfs_btrfs_subvolume_delete (g, _arg673);
  if (_ret672 == -1)
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
test_btrfs_subvolume_snapshot_0 (void)
{
  if (test_btrfs_subvolume_snapshot_0_skip ()) {
    skipped ("test_btrfs_subvolume_snapshot_0", "environment variable set");
    return 0;
  }

  const char *_features675[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features675)) {
    skipped ("test_btrfs_subvolume_snapshot_0", "group %s not available in daemon",
             _features675[0]);
    return 0;
  }

  /* InitPartition for test_btrfs_subvolume_snapshot_0: create /dev/sda1 */
  const char *_arg677 = "/dev/sda";
  int _ret676;
  _ret676 = guestfs_blockdev_setrw (g, _arg677);
  if (_ret676 == -1)
    return -1;
  int _ret679;
  _ret679 = guestfs_umount_all (g);
  if (_ret679 == -1)
    return -1;
  int _ret681;
  _ret681 = guestfs_lvm_remove_all (g);
  if (_ret681 == -1)
    return -1;
  const char *_arg684 = "/dev/sda";
  const char *_arg685 = "mbr";
  int _ret683;
  _ret683 = guestfs_part_disk (g, _arg684, _arg685);
  if (_ret683 == -1)
    return -1;

  /* TestRun for btrfs_subvolume_snapshot (0) */
  const char *_arg688_0 = "/dev/sda1";
  const char *const _arg688[] = {
    _arg688_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs689;
  _optargs689.bitmask = UINT64_C(0x0);
  int _ret687;
  _ret687 = guestfs_mkfs_btrfs_argv (g, (char **) _arg688, &_optargs689);
  if (_ret687 == -1)
    return -1;
  const char *_arg691 = "/dev/sda1";
  const char *_arg692 = "/";
  int _ret690;
  _ret690 = guestfs_mount (g, _arg691, _arg692);
  if (_ret690 == -1)
    return -1;
  const char *_arg695 = "/dir";
  int _ret694;
  _ret694 = guestfs_mkdir (g, _arg695);
  if (_ret694 == -1)
    return -1;
  const char *_arg698 = "/test1";
  int _ret697;
  _ret697 = guestfs_btrfs_subvolume_create (g, _arg698);
  if (_ret697 == -1)
    return -1;
  const char *_arg701 = "/test2";
  int _ret700;
  _ret700 = guestfs_btrfs_subvolume_create (g, _arg701);
  if (_ret700 == -1)
    return -1;
  const char *_arg704 = "/dir/test3";
  int _ret703;
  _ret703 = guestfs_btrfs_subvolume_create (g, _arg704);
  if (_ret703 == -1)
    return -1;
  const char *_arg707 = "/dir/test3";
  const char *_arg708 = "/dir/test4";
  int _ret706;
  _ret706 = guestfs_btrfs_subvolume_snapshot (g, _arg707, _arg708);
  if (_ret706 == -1)
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
test_get_e2generation_0 (void)
{
  if (test_get_e2generation_0_skip ()) {
    skipped ("test_get_e2generation_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_get_e2generation_0 */
  const char *_arg711 = "/dev/sda";
  int _ret710;
  _ret710 = guestfs_blockdev_setrw (g, _arg711);
  if (_ret710 == -1)
    return -1;
  int _ret713;
  _ret713 = guestfs_umount_all (g);
  if (_ret713 == -1)
    return -1;
  int _ret715;
  _ret715 = guestfs_lvm_remove_all (g);
  if (_ret715 == -1)
    return -1;
  const char *_arg718 = "/dev/sdb1";
  const char *_arg719 = "/";
  int _ret717;
  _ret717 = guestfs_mount (g, _arg718, _arg719);
  if (_ret717 == -1)
    return -1;

  /* TestResult for get_e2generation (0) */
  const char *_arg721 = "/e2generation";
  int ret2;
  ret2 = guestfs_touch (g, _arg721);
  if (ret2 == -1)
    return -1;
  const char *_arg723 = "/e2generation";
  int ret1;
  ret1 = guestfs_set_e2generation (g, _arg723, 123456);
  if (ret1 == -1)
    return -1;
  const char *_arg726 = "/e2generation";
  int64_t ret;
  ret = guestfs_get_e2generation (g, _arg726);
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
test_get_e2attrs_0 (void)
{
  if (test_get_e2attrs_0_skip ()) {
    skipped ("test_get_e2attrs_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_0 */
  const char *_arg729 = "/dev/sda";
  int _ret728;
  _ret728 = guestfs_blockdev_setrw (g, _arg729);
  if (_ret728 == -1)
    return -1;
  int _ret731;
  _ret731 = guestfs_umount_all (g);
  if (_ret731 == -1)
    return -1;
  int _ret733;
  _ret733 = guestfs_lvm_remove_all (g);
  if (_ret733 == -1)
    return -1;
  const char *_arg736 = "/dev/sdb1";
  const char *_arg737 = "/";
  int _ret735;
  _ret735 = guestfs_mount (g, _arg736, _arg737);
  if (_ret735 == -1)
    return -1;

  /* TestResultString for get_e2attrs (0) */
  const char *_arg740 = "/e2attrs1";
  int _ret739;
  _ret739 = guestfs_touch (g, _arg740);
  if (_ret739 == -1)
    return -1;
  const char *_arg742 = "/e2attrs1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg742);
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
test_get_e2attrs_1 (void)
{
  if (test_get_e2attrs_1_skip ()) {
    skipped ("test_get_e2attrs_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_1 */
  const char *_arg745 = "/dev/sda";
  int _ret744;
  _ret744 = guestfs_blockdev_setrw (g, _arg745);
  if (_ret744 == -1)
    return -1;
  int _ret747;
  _ret747 = guestfs_umount_all (g);
  if (_ret747 == -1)
    return -1;
  int _ret749;
  _ret749 = guestfs_lvm_remove_all (g);
  if (_ret749 == -1)
    return -1;
  const char *_arg752 = "/dev/sdb1";
  const char *_arg753 = "/";
  int _ret751;
  _ret751 = guestfs_mount (g, _arg752, _arg753);
  if (_ret751 == -1)
    return -1;

  /* TestResultString for get_e2attrs (1) */
  const char *_arg756 = "/e2attrs2";
  int _ret755;
  _ret755 = guestfs_touch (g, _arg756);
  if (_ret755 == -1)
    return -1;
  const char *_arg759 = "/e2attrs2";
  const char *_arg760 = "is";
  struct guestfs_set_e2attrs_argv _optargs761;
  _optargs761.clear = 0;
  _optargs761.bitmask = UINT64_C(0x1);
  int _ret758;
  _ret758 = guestfs_set_e2attrs_argv (g, _arg759, _arg760, &_optargs761);
  if (_ret758 == -1)
    return -1;
  const char *_arg762 = "/e2attrs2";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg762);
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
test_get_e2attrs_2 (void)
{
  if (test_get_e2attrs_2_skip ()) {
    skipped ("test_get_e2attrs_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_2 */
  const char *_arg765 = "/dev/sda";
  int _ret764;
  _ret764 = guestfs_blockdev_setrw (g, _arg765);
  if (_ret764 == -1)
    return -1;
  int _ret767;
  _ret767 = guestfs_umount_all (g);
  if (_ret767 == -1)
    return -1;
  int _ret769;
  _ret769 = guestfs_lvm_remove_all (g);
  if (_ret769 == -1)
    return -1;
  const char *_arg772 = "/dev/sdb1";
  const char *_arg773 = "/";
  int _ret771;
  _ret771 = guestfs_mount (g, _arg772, _arg773);
  if (_ret771 == -1)
    return -1;

  /* TestResultString for get_e2attrs (2) */
  const char *_arg776 = "/e2attrs3";
  int _ret775;
  _ret775 = guestfs_touch (g, _arg776);
  if (_ret775 == -1)
    return -1;
  const char *_arg779 = "/e2attrs3";
  const char *_arg780 = "is";
  struct guestfs_set_e2attrs_argv _optargs781;
  _optargs781.clear = 0;
  _optargs781.bitmask = UINT64_C(0x1);
  int _ret778;
  _ret778 = guestfs_set_e2attrs_argv (g, _arg779, _arg780, &_optargs781);
  if (_ret778 == -1)
    return -1;
  const char *_arg783 = "/e2attrs3";
  const char *_arg784 = "i";
  struct guestfs_set_e2attrs_argv _optargs785;
  _optargs785.clear = 1;
  _optargs785.bitmask = UINT64_C(0x1);
  int _ret782;
  _ret782 = guestfs_set_e2attrs_argv (g, _arg783, _arg784, &_optargs785);
  if (_ret782 == -1)
    return -1;
  const char *_arg786 = "/e2attrs3";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg786);
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
test_get_e2attrs_3 (void)
{
  if (test_get_e2attrs_3_skip ()) {
    skipped ("test_get_e2attrs_3", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_3 */
  const char *_arg789 = "/dev/sda";
  int _ret788;
  _ret788 = guestfs_blockdev_setrw (g, _arg789);
  if (_ret788 == -1)
    return -1;
  int _ret791;
  _ret791 = guestfs_umount_all (g);
  if (_ret791 == -1)
    return -1;
  int _ret793;
  _ret793 = guestfs_lvm_remove_all (g);
  if (_ret793 == -1)
    return -1;
  const char *_arg796 = "/dev/sdb1";
  const char *_arg797 = "/";
  int _ret795;
  _ret795 = guestfs_mount (g, _arg796, _arg797);
  if (_ret795 == -1)
    return -1;

  /* TestResultString for get_e2attrs (3) */
  const char *_arg800 = "/e2attrs4";
  int _ret799;
  _ret799 = guestfs_touch (g, _arg800);
  if (_ret799 == -1)
    return -1;
  const char *_arg803 = "/e2attrs4";
  const char *_arg804 = "adst";
  struct guestfs_set_e2attrs_argv _optargs805;
  _optargs805.clear = 0;
  _optargs805.bitmask = UINT64_C(0x1);
  int _ret802;
  _ret802 = guestfs_set_e2attrs_argv (g, _arg803, _arg804, &_optargs805);
  if (_ret802 == -1)
    return -1;
  const char *_arg807 = "/e2attrs4";
  const char *_arg808 = "iS";
  struct guestfs_set_e2attrs_argv _optargs809;
  _optargs809.clear = 0;
  _optargs809.bitmask = UINT64_C(0x1);
  int _ret806;
  _ret806 = guestfs_set_e2attrs_argv (g, _arg807, _arg808, &_optargs809);
  if (_ret806 == -1)
    return -1;
  const char *_arg811 = "/e2attrs4";
  const char *_arg812 = "i";
  struct guestfs_set_e2attrs_argv _optargs813;
  _optargs813.clear = 1;
  _optargs813.bitmask = UINT64_C(0x1);
  int _ret810;
  _ret810 = guestfs_set_e2attrs_argv (g, _arg811, _arg812, &_optargs813);
  if (_ret810 == -1)
    return -1;
  const char *_arg815 = "/e2attrs4";
  const char *_arg816 = "ad";
  struct guestfs_set_e2attrs_argv _optargs817;
  _optargs817.clear = 1;
  _optargs817.bitmask = UINT64_C(0x1);
  int _ret814;
  _ret814 = guestfs_set_e2attrs_argv (g, _arg815, _arg816, &_optargs817);
  if (_ret814 == -1)
    return -1;
  const char *_arg819 = "/e2attrs4";
  const char *_arg820 = "";
  struct guestfs_set_e2attrs_argv _optargs821;
  _optargs821.clear = 0;
  _optargs821.bitmask = UINT64_C(0x1);
  int _ret818;
  _ret818 = guestfs_set_e2attrs_argv (g, _arg819, _arg820, &_optargs821);
  if (_ret818 == -1)
    return -1;
  const char *_arg823 = "/e2attrs4";
  const char *_arg824 = "";
  struct guestfs_set_e2attrs_argv _optargs825;
  _optargs825.clear = 1;
  _optargs825.bitmask = UINT64_C(0x1);
  int _ret822;
  _ret822 = guestfs_set_e2attrs_argv (g, _arg823, _arg824, &_optargs825);
  if (_ret822 == -1)
    return -1;
  const char *_arg826 = "/e2attrs4";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, _arg826);
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
test_get_e2attrs_4 (void)
{
  if (test_get_e2attrs_4_skip ()) {
    skipped ("test_get_e2attrs_4", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_4 */
  const char *_arg829 = "/dev/sda";
  int _ret828;
  _ret828 = guestfs_blockdev_setrw (g, _arg829);
  if (_ret828 == -1)
    return -1;
  int _ret831;
  _ret831 = guestfs_umount_all (g);
  if (_ret831 == -1)
    return -1;
  int _ret833;
  _ret833 = guestfs_lvm_remove_all (g);
  if (_ret833 == -1)
    return -1;
  const char *_arg836 = "/dev/sdb1";
  const char *_arg837 = "/";
  int _ret835;
  _ret835 = guestfs_mount (g, _arg836, _arg837);
  if (_ret835 == -1)
    return -1;

  /* TestLastFail for get_e2attrs (4) */
  const char *_arg840 = "/e2attrs5";
  int _ret839;
  _ret839 = guestfs_touch (g, _arg840);
  if (_ret839 == -1)
    return -1;
  const char *_arg843 = "/e2attrs5";
  const char *_arg844 = "R";
  struct guestfs_set_e2attrs_argv _optargs845;
  _optargs845.clear = 0;
  _optargs845.bitmask = UINT64_C(0x1);
  int _ret842;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret842 = guestfs_set_e2attrs_argv (g, _arg843, _arg844, &_optargs845);
  guestfs_pop_error_handler (g);
  if (_ret842 != -1)
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
test_get_e2attrs_5 (void)
{
  if (test_get_e2attrs_5_skip ()) {
    skipped ("test_get_e2attrs_5", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_5 */
  const char *_arg847 = "/dev/sda";
  int _ret846;
  _ret846 = guestfs_blockdev_setrw (g, _arg847);
  if (_ret846 == -1)
    return -1;
  int _ret849;
  _ret849 = guestfs_umount_all (g);
  if (_ret849 == -1)
    return -1;
  int _ret851;
  _ret851 = guestfs_lvm_remove_all (g);
  if (_ret851 == -1)
    return -1;
  const char *_arg854 = "/dev/sdb1";
  const char *_arg855 = "/";
  int _ret853;
  _ret853 = guestfs_mount (g, _arg854, _arg855);
  if (_ret853 == -1)
    return -1;

  /* TestLastFail for get_e2attrs (5) */
  const char *_arg858 = "/e2attrs6";
  int _ret857;
  _ret857 = guestfs_touch (g, _arg858);
  if (_ret857 == -1)
    return -1;
  const char *_arg861 = "/e2attrs6";
  const char *_arg862 = "v";
  struct guestfs_set_e2attrs_argv _optargs863;
  _optargs863.clear = 0;
  _optargs863.bitmask = UINT64_C(0x1);
  int _ret860;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret860 = guestfs_set_e2attrs_argv (g, _arg861, _arg862, &_optargs863);
  guestfs_pop_error_handler (g);
  if (_ret860 != -1)
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
test_get_e2attrs_6 (void)
{
  if (test_get_e2attrs_6_skip ()) {
    skipped ("test_get_e2attrs_6", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_6 */
  const char *_arg865 = "/dev/sda";
  int _ret864;
  _ret864 = guestfs_blockdev_setrw (g, _arg865);
  if (_ret864 == -1)
    return -1;
  int _ret867;
  _ret867 = guestfs_umount_all (g);
  if (_ret867 == -1)
    return -1;
  int _ret869;
  _ret869 = guestfs_lvm_remove_all (g);
  if (_ret869 == -1)
    return -1;
  const char *_arg872 = "/dev/sdb1";
  const char *_arg873 = "/";
  int _ret871;
  _ret871 = guestfs_mount (g, _arg872, _arg873);
  if (_ret871 == -1)
    return -1;

  /* TestLastFail for get_e2attrs (6) */
  const char *_arg876 = "/e2attrs7";
  int _ret875;
  _ret875 = guestfs_touch (g, _arg876);
  if (_ret875 == -1)
    return -1;
  const char *_arg879 = "/e2attrs7";
  const char *_arg880 = "aa";
  struct guestfs_set_e2attrs_argv _optargs881;
  _optargs881.clear = 0;
  _optargs881.bitmask = UINT64_C(0x1);
  int _ret878;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret878 = guestfs_set_e2attrs_argv (g, _arg879, _arg880, &_optargs881);
  guestfs_pop_error_handler (g);
  if (_ret878 != -1)
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
test_get_e2attrs_7 (void)
{
  if (test_get_e2attrs_7_skip ()) {
    skipped ("test_get_e2attrs_7", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_7 */
  const char *_arg883 = "/dev/sda";
  int _ret882;
  _ret882 = guestfs_blockdev_setrw (g, _arg883);
  if (_ret882 == -1)
    return -1;
  int _ret885;
  _ret885 = guestfs_umount_all (g);
  if (_ret885 == -1)
    return -1;
  int _ret887;
  _ret887 = guestfs_lvm_remove_all (g);
  if (_ret887 == -1)
    return -1;
  const char *_arg890 = "/dev/sdb1";
  const char *_arg891 = "/";
  int _ret889;
  _ret889 = guestfs_mount (g, _arg890, _arg891);
  if (_ret889 == -1)
    return -1;

  /* TestLastFail for get_e2attrs (7) */
  const char *_arg894 = "/e2attrs8";
  int _ret893;
  _ret893 = guestfs_touch (g, _arg894);
  if (_ret893 == -1)
    return -1;
  const char *_arg897 = "/e2attrs8";
  const char *_arg898 = "BabcdB";
  struct guestfs_set_e2attrs_argv _optargs899;
  _optargs899.clear = 0;
  _optargs899.bitmask = UINT64_C(0x1);
  int _ret896;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret896 = guestfs_set_e2attrs_argv (g, _arg897, _arg898, &_optargs899);
  guestfs_pop_error_handler (g);
  if (_ret896 != -1)
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
test_mkfs_btrfs_0 (void)
{
  if (test_mkfs_btrfs_0_skip ()) {
    skipped ("test_mkfs_btrfs_0", "environment variable set");
    return 0;
  }

  const char *_features900[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) _features900)) {
    skipped ("test_mkfs_btrfs_0", "group %s not available in daemon",
             _features900[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_btrfs_0 */
  const char *_arg902 = "/dev/sda";
  int _ret901;
  _ret901 = guestfs_blockdev_setrw (g, _arg902);
  if (_ret901 == -1)
    return -1;
  int _ret904;
  _ret904 = guestfs_umount_all (g);
  if (_ret904 == -1)
    return -1;
  int _ret906;
  _ret906 = guestfs_lvm_remove_all (g);
  if (_ret906 == -1)
    return -1;

  /* TestRun for mkfs_btrfs (0) */
  const char *_arg909 = "/dev/sda";
  const char *_arg910 = "mbr";
  int _ret908;
  _ret908 = guestfs_part_disk (g, _arg909, _arg910);
  if (_ret908 == -1)
    return -1;
  const char *_arg913_0 = "/dev/sda1";
  const char *const _arg913[] = {
    _arg913_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv _optargs914;
  _optargs914.allocstart = 0;
  _optargs914.bytecount = 268435456;
  _optargs914.datatype = "single";
  _optargs914.leafsize = 4096;
  _optargs914.label = "test";
  _optargs914.metadata = "single";
  _optargs914.nodesize = 4096;
  _optargs914.sectorsize = 512;
  _optargs914.bitmask = UINT64_C(0xff);
  int _ret912;
  _ret912 = guestfs_mkfs_btrfs_argv (g, (char **) _arg913, &_optargs914);
  if (_ret912 == -1)
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
test_isoinfo_device_0 (void)
{
  if (test_isoinfo_device_0_skip ()) {
    skipped ("test_isoinfo_device_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_isoinfo_device_0 */
  const char *_arg916 = "/dev/sda";
  int _ret915;
  _ret915 = guestfs_blockdev_setrw (g, _arg916);
  if (_ret915 == -1)
    return -1;
  int _ret918;
  _ret918 = guestfs_umount_all (g);
  if (_ret918 == -1)
    return -1;
  int _ret920;
  _ret920 = guestfs_lvm_remove_all (g);
  if (_ret920 == -1)
    return -1;

  /* TestResult for isoinfo_device (0) */
  const char *_arg922 = "/dev/sdd";
  CLEANUP_FREE_ISOINFO struct guestfs_isoinfo *ret;
  ret = guestfs_isoinfo_device (g, _arg922);
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
test_lvcreate_free_0 (void)
{
  if (test_lvcreate_free_0_skip ()) {
    skipped ("test_lvcreate_free_0", "environment variable set");
    return 0;
  }

  const char *_features924[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features924)) {
    skipped ("test_lvcreate_free_0", "group %s not available in daemon",
             _features924[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_lvcreate_free_0 */
  const char *_arg926 = "/dev/sda";
  int _ret925;
  _ret925 = guestfs_blockdev_setrw (g, _arg926);
  if (_ret925 == -1)
    return -1;
  int _ret928;
  _ret928 = guestfs_umount_all (g);
  if (_ret928 == -1)
    return -1;
  int _ret930;
  _ret930 = guestfs_lvm_remove_all (g);
  if (_ret930 == -1)
    return -1;

  /* TestResult for lvcreate_free (0) */
  const char *_arg932 = "/dev/sda";
  const char *_arg933 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg932, _arg933);
  if (ret7 == -1)
    return -1;
  const char *_arg935 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg935);
  if (ret6 == -1)
    return -1;
  const char *_arg937 = "VG";
  const char *_arg938_0 = "/dev/sda1";
  const char *const _arg938[] = {
    _arg938_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg937, (char **) _arg938);
  if (ret5 == -1)
    return -1;
  const char *_arg940 = "LV1";
  const char *_arg941 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate_free (g, _arg940, _arg941, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg944 = "LV2";
  const char *_arg945 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate_free (g, _arg944, _arg945, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg948 = "LV3";
  const char *_arg949 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate_free (g, _arg948, _arg949, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg952 = "LV4";
  const char *_arg953 = "VG";
  int ret1;
  ret1 = guestfs_lvcreate_free (g, _arg952, _arg953, 100);
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
test_zero_free_space_0 (void)
{
  if (test_zero_free_space_0_skip ()) {
    skipped ("test_zero_free_space_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_zero_free_space_0 */
  const char *_arg958 = "/dev/sda";
  int _ret957;
  _ret957 = guestfs_blockdev_setrw (g, _arg958);
  if (_ret957 == -1)
    return -1;
  int _ret960;
  _ret960 = guestfs_umount_all (g);
  if (_ret960 == -1)
    return -1;
  int _ret962;
  _ret962 = guestfs_lvm_remove_all (g);
  if (_ret962 == -1)
    return -1;
  const char *_arg965 = "/dev/sdb1";
  const char *_arg966 = "/";
  int _ret964;
  _ret964 = guestfs_mount (g, _arg965, _arg966);
  if (_ret964 == -1)
    return -1;

  /* TestRun for zero_free_space (0) */
  const char *_arg969 = "/";
  int _ret968;
  _ret968 = guestfs_zero_free_space (g, _arg969);
  if (_ret968 == -1)
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
test_set_label_0 (void)
{
  if (test_set_label_0_skip ()) {
    skipped ("test_set_label_0", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_set_label_0: create ext2 on /dev/sda1 */
  const char *_arg972 = "/dev/sda";
  int _ret971;
  _ret971 = guestfs_blockdev_setrw (g, _arg972);
  if (_ret971 == -1)
    return -1;
  int _ret974;
  _ret974 = guestfs_umount_all (g);
  if (_ret974 == -1)
    return -1;
  int _ret976;
  _ret976 = guestfs_lvm_remove_all (g);
  if (_ret976 == -1)
    return -1;
  const char *_arg979 = "/dev/sda";
  const char *_arg980 = "mbr";
  int _ret978;
  _ret978 = guestfs_part_disk (g, _arg979, _arg980);
  if (_ret978 == -1)
    return -1;
  const char *_arg983 = "ext2";
  const char *_arg984 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs985;
  _optargs985.bitmask = UINT64_C(0x0);
  int _ret982;
  _ret982 = guestfs_mkfs_opts_argv (g, _arg983, _arg984, &_optargs985);
  if (_ret982 == -1)
    return -1;
  const char *_arg987 = "/dev/sda1";
  const char *_arg988 = "/";
  int _ret986;
  _ret986 = guestfs_mount (g, _arg987, _arg988);
  if (_ret986 == -1)
    return -1;

  /* TestResultString for set_label (0) */
  const char *_arg991 = "/dev/sda1";
  const char *_arg992 = "testlabel";
  int _ret990;
  _ret990 = guestfs_set_label (g, _arg991, _arg992);
  if (_ret990 == -1)
    return -1;
  const char *_arg994 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, _arg994);
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
test_set_label_1 (void)
{
  if (test_set_label_1_skip ()) {
    skipped ("test_set_label_1", "environment variable set");
    return 0;
  }

  const char *_features996[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features996)) {
    skipped ("test_set_label_1", "group %s not available in daemon",
             _features996[0]);
    return 0;
  }

  /* InitPartition for test_set_label_1: create /dev/sda1 */
  const char *_arg998 = "/dev/sda";
  int _ret997;
  _ret997 = guestfs_blockdev_setrw (g, _arg998);
  if (_ret997 == -1)
    return -1;
  int _ret1000;
  _ret1000 = guestfs_umount_all (g);
  if (_ret1000 == -1)
    return -1;
  int _ret1002;
  _ret1002 = guestfs_lvm_remove_all (g);
  if (_ret1002 == -1)
    return -1;
  const char *_arg1005 = "/dev/sda";
  const char *_arg1006 = "mbr";
  int _ret1004;
  _ret1004 = guestfs_part_disk (g, _arg1005, _arg1006);
  if (_ret1004 == -1)
    return -1;

  /* TestResultString for set_label (1) */
  const char *_arg1009 = "ntfs";
  const char *_arg1010 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1011;
  _optargs1011.bitmask = UINT64_C(0x0);
  int _ret1008;
  _ret1008 = guestfs_mkfs_opts_argv (g, _arg1009, _arg1010, &_optargs1011);
  if (_ret1008 == -1)
    return -1;
  const char *_arg1013 = "/dev/sda1";
  const char *_arg1014 = "testlabel2";
  int _ret1012;
  _ret1012 = guestfs_set_label (g, _arg1013, _arg1014);
  if (_ret1012 == -1)
    return -1;
  const char *_arg1016 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, _arg1016);
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
test_set_label_2 (void)
{
  if (test_set_label_2_skip ()) {
    skipped ("test_set_label_2", "environment variable set");
    return 0;
  }

  /* InitPartition for test_set_label_2: create /dev/sda1 */
  const char *_arg1019 = "/dev/sda";
  int _ret1018;
  _ret1018 = guestfs_blockdev_setrw (g, _arg1019);
  if (_ret1018 == -1)
    return -1;
  int _ret1021;
  _ret1021 = guestfs_umount_all (g);
  if (_ret1021 == -1)
    return -1;
  int _ret1023;
  _ret1023 = guestfs_lvm_remove_all (g);
  if (_ret1023 == -1)
    return -1;
  const char *_arg1026 = "/dev/sda";
  const char *_arg1027 = "mbr";
  int _ret1025;
  _ret1025 = guestfs_part_disk (g, _arg1026, _arg1027);
  if (_ret1025 == -1)
    return -1;

  /* TestLastFail for set_label (2) */
  const char *_arg1030 = "/dev/sda1";
  int _ret1029;
  _ret1029 = guestfs_zero (g, _arg1030);
  if (_ret1029 == -1)
    return -1;
  const char *_arg1033 = "/dev/sda1";
  const char *_arg1034 = "testlabel2";
  int _ret1032;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1032 = guestfs_set_label (g, _arg1033, _arg1034);
  guestfs_pop_error_handler (g);
  if (_ret1032 != -1)
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
test_ntfsfix_0 (void)
{
  if (test_ntfsfix_0_skip ()) {
    skipped ("test_ntfsfix_0", "environment variable set");
    return 0;
  }

  const char *_features1036[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features1036)) {
    skipped ("test_ntfsfix_0", "group %s not available in daemon",
             _features1036[0]);
    return 0;
  }

  /* InitPartition for test_ntfsfix_0: create /dev/sda1 */
  const char *_arg1038 = "/dev/sda";
  int _ret1037;
  _ret1037 = guestfs_blockdev_setrw (g, _arg1038);
  if (_ret1037 == -1)
    return -1;
  int _ret1040;
  _ret1040 = guestfs_umount_all (g);
  if (_ret1040 == -1)
    return -1;
  int _ret1042;
  _ret1042 = guestfs_lvm_remove_all (g);
  if (_ret1042 == -1)
    return -1;
  const char *_arg1045 = "/dev/sda";
  const char *_arg1046 = "mbr";
  int _ret1044;
  _ret1044 = guestfs_part_disk (g, _arg1045, _arg1046);
  if (_ret1044 == -1)
    return -1;

  /* TestRun for ntfsfix (0) */
  const char *_arg1049 = "ntfs";
  const char *_arg1050 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1051;
  _optargs1051.bitmask = UINT64_C(0x0);
  int _ret1048;
  _ret1048 = guestfs_mkfs_opts_argv (g, _arg1049, _arg1050, &_optargs1051);
  if (_ret1048 == -1)
    return -1;
  const char *_arg1053 = "/dev/sda1";
  struct guestfs_ntfsfix_argv _optargs1054;
  _optargs1054.clearbadsectors = 0;
  _optargs1054.bitmask = UINT64_C(0x1);
  int _ret1052;
  _ret1052 = guestfs_ntfsfix_argv (g, _arg1053, &_optargs1054);
  if (_ret1052 == -1)
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
test_wipefs_0 (void)
{
  if (test_wipefs_0_skip ()) {
    skipped ("test_wipefs_0", "environment variable set");
    return 0;
  }

  const char *_features1055[] = { "wipefs", NULL };
  if (!guestfs_feature_available (g, (char **) _features1055)) {
    skipped ("test_wipefs_0", "group %s not available in daemon",
             _features1055[0]);
    return 0;
  }

  /* InitBasicFSonLVM for test_wipefs_0: create ext2 on /dev/VG/LV */
  const char *_arg1057 = "/dev/sda";
  int _ret1056;
  _ret1056 = guestfs_blockdev_setrw (g, _arg1057);
  if (_ret1056 == -1)
    return -1;
  int _ret1059;
  _ret1059 = guestfs_umount_all (g);
  if (_ret1059 == -1)
    return -1;
  int _ret1061;
  _ret1061 = guestfs_lvm_remove_all (g);
  if (_ret1061 == -1)
    return -1;
  const char *_arg1064 = "/dev/sda";
  const char *_arg1065 = "mbr";
  int _ret1063;
  _ret1063 = guestfs_part_disk (g, _arg1064, _arg1065);
  if (_ret1063 == -1)
    return -1;
  const char *_arg1068 = "/dev/sda1";
  int _ret1067;
  _ret1067 = guestfs_pvcreate (g, _arg1068);
  if (_ret1067 == -1)
    return -1;
  const char *_arg1071 = "VG";
  const char *_arg1072_0 = "/dev/sda1";
  const char *const _arg1072[] = {
    _arg1072_0,
    NULL
  };
  int _ret1070;
  _ret1070 = guestfs_vgcreate (g, _arg1071, (char **) _arg1072);
  if (_ret1070 == -1)
    return -1;
  const char *_arg1075 = "LV";
  const char *_arg1076 = "VG";
  int _ret1074;
  _ret1074 = guestfs_lvcreate (g, _arg1075, _arg1076, 8);
  if (_ret1074 == -1)
    return -1;
  const char *_arg1080 = "ext2";
  const char *_arg1081 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs1082;
  _optargs1082.bitmask = UINT64_C(0x0);
  int _ret1079;
  _ret1079 = guestfs_mkfs_opts_argv (g, _arg1080, _arg1081, &_optargs1082);
  if (_ret1079 == -1)
    return -1;
  const char *_arg1084 = "/dev/VG/LV";
  const char *_arg1085 = "/";
  int _ret1083;
  _ret1083 = guestfs_mount (g, _arg1084, _arg1085);
  if (_ret1083 == -1)
    return -1;

  /* TestRun for wipefs (0) */
  const char *_arg1088 = "/dev/VG/LV";
  struct guestfs_umount_opts_argv _optargs1089;
  _optargs1089.bitmask = UINT64_C(0x0);
  int _ret1087;
  _ret1087 = guestfs_umount_opts_argv (g, _arg1088, &_optargs1089);
  if (_ret1087 == -1)
    return -1;
  const char *_arg1091 = "/dev/VG/LV";
  int _ret1090;
  _ret1090 = guestfs_wipefs (g, _arg1091);
  if (_ret1090 == -1)
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
test_blkid_0 (void)
{
  if (test_blkid_0_skip ()) {
    skipped ("test_blkid_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_blkid_0 */
  const char *_arg1094 = "/dev/sda";
  int _ret1093;
  _ret1093 = guestfs_blockdev_setrw (g, _arg1094);
  if (_ret1093 == -1)
    return -1;
  int _ret1096;
  _ret1096 = guestfs_umount_all (g);
  if (_ret1096 == -1)
    return -1;
  int _ret1098;
  _ret1098 = guestfs_lvm_remove_all (g);
  if (_ret1098 == -1)
    return -1;
  const char *_arg1101 = "/dev/sdb1";
  const char *_arg1102 = "/";
  int _ret1100;
  _ret1100 = guestfs_mount (g, _arg1101, _arg1102);
  if (_ret1100 == -1)
    return -1;

  /* TestResult for blkid (0) */
  const char *_arg1104 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_blkid (g, _arg1104);
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
test_tune2fs_0 (void)
{
  if (test_tune2fs_0_skip ()) {
    skipped ("test_tune2fs_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_tune2fs_0 */
  const char *_arg1107 = "/dev/sda";
  int _ret1106;
  _ret1106 = guestfs_blockdev_setrw (g, _arg1107);
  if (_ret1106 == -1)
    return -1;
  int _ret1109;
  _ret1109 = guestfs_umount_all (g);
  if (_ret1109 == -1)
    return -1;
  int _ret1111;
  _ret1111 = guestfs_lvm_remove_all (g);
  if (_ret1111 == -1)
    return -1;
  const char *_arg1114 = "/dev/sdb1";
  const char *_arg1115 = "/";
  int _ret1113;
  _ret1113 = guestfs_mount (g, _arg1114, _arg1115);
  if (_ret1113 == -1)
    return -1;

  /* TestResult for tune2fs (0) */
  const char *_arg1117 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs1118;
  _optargs1118.force = 0;
  _optargs1118.maxmountcount = 0;
  _optargs1118.intervalbetweenchecks = 0;
  _optargs1118.bitmask = UINT64_C(0x23);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg1117, &_optargs1118);
  if (ret1 == -1)
    return -1;
  const char *_arg1119 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg1119);
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
test_tune2fs_1 (void)
{
  if (test_tune2fs_1_skip ()) {
    skipped ("test_tune2fs_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_tune2fs_1 */
  const char *_arg1122 = "/dev/sda";
  int _ret1121;
  _ret1121 = guestfs_blockdev_setrw (g, _arg1122);
  if (_ret1121 == -1)
    return -1;
  int _ret1124;
  _ret1124 = guestfs_umount_all (g);
  if (_ret1124 == -1)
    return -1;
  int _ret1126;
  _ret1126 = guestfs_lvm_remove_all (g);
  if (_ret1126 == -1)
    return -1;
  const char *_arg1129 = "/dev/sdb1";
  const char *_arg1130 = "/";
  int _ret1128;
  _ret1128 = guestfs_mount (g, _arg1129, _arg1130);
  if (_ret1128 == -1)
    return -1;

  /* TestResult for tune2fs (1) */
  const char *_arg1132 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs1133;
  _optargs1133.force = 0;
  _optargs1133.maxmountcount = 0;
  _optargs1133.intervalbetweenchecks = 86400;
  _optargs1133.bitmask = UINT64_C(0x23);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg1132, &_optargs1133);
  if (ret1 == -1)
    return -1;
  const char *_arg1134 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg1134);
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
test_tune2fs_2 (void)
{
  if (test_tune2fs_2_skip ()) {
    skipped ("test_tune2fs_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_tune2fs_2 */
  const char *_arg1137 = "/dev/sda";
  int _ret1136;
  _ret1136 = guestfs_blockdev_setrw (g, _arg1137);
  if (_ret1136 == -1)
    return -1;
  int _ret1139;
  _ret1139 = guestfs_umount_all (g);
  if (_ret1139 == -1)
    return -1;
  int _ret1141;
  _ret1141 = guestfs_lvm_remove_all (g);
  if (_ret1141 == -1)
    return -1;
  const char *_arg1144 = "/dev/sdb1";
  const char *_arg1145 = "/";
  int _ret1143;
  _ret1143 = guestfs_mount (g, _arg1144, _arg1145);
  if (_ret1143 == -1)
    return -1;

  /* TestResult for tune2fs (2) */
  const char *_arg1147 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs1148;
  _optargs1148.force = 0;
  _optargs1148.group = 1;
  _optargs1148.user = 1;
  _optargs1148.bitmask = UINT64_C(0x211);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg1147, &_optargs1148);
  if (ret1 == -1)
    return -1;
  const char *_arg1149 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg1149);
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
test_tune2fs_3 (void)
{
  if (test_tune2fs_3_skip ()) {
    skipped ("test_tune2fs_3", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_tune2fs_3 */
  const char *_arg1152 = "/dev/sda";
  int _ret1151;
  _ret1151 = guestfs_blockdev_setrw (g, _arg1152);
  if (_ret1151 == -1)
    return -1;
  int _ret1154;
  _ret1154 = guestfs_umount_all (g);
  if (_ret1154 == -1)
    return -1;
  int _ret1156;
  _ret1156 = guestfs_lvm_remove_all (g);
  if (_ret1156 == -1)
    return -1;
  const char *_arg1159 = "/dev/sdb1";
  const char *_arg1160 = "/";
  int _ret1158;
  _ret1158 = guestfs_mount (g, _arg1159, _arg1160);
  if (_ret1158 == -1)
    return -1;

  /* TestResult for tune2fs (3) */
  const char *_arg1162 = "/dev/sdb1";
  struct guestfs_tune2fs_argv _optargs1163;
  _optargs1163.force = 0;
  _optargs1163.group = 0;
  _optargs1163.user = 0;
  _optargs1163.bitmask = UINT64_C(0x211);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, _arg1162, &_optargs1163);
  if (ret1 == -1)
    return -1;
  const char *_arg1164 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg1164);
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
test_copy_file_to_file_0 (void)
{
  if (test_copy_file_to_file_0_skip ()) {
    skipped ("test_copy_file_to_file_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_copy_file_to_file_0 */
  const char *_arg1167 = "/dev/sda";
  int _ret1166;
  _ret1166 = guestfs_blockdev_setrw (g, _arg1167);
  if (_ret1166 == -1)
    return -1;
  int _ret1169;
  _ret1169 = guestfs_umount_all (g);
  if (_ret1169 == -1)
    return -1;
  int _ret1171;
  _ret1171 = guestfs_lvm_remove_all (g);
  if (_ret1171 == -1)
    return -1;
  const char *_arg1174 = "/dev/sdb1";
  const char *_arg1175 = "/";
  int _ret1173;
  _ret1173 = guestfs_mount (g, _arg1174, _arg1175);
  if (_ret1173 == -1)
    return -1;

  /* TestResult for copy_file_to_file (0) */
  const char *_arg1177 = "/copyff";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg1177);
  if (ret3 == -1)
    return -1;
  const char *_arg1179 = "/copyff/src";
  const char *_arg1180 = "hello, world";
  size_t _arg1180_size = 12;
  int ret2;
  ret2 = guestfs_write (g, _arg1179, _arg1180, _arg1180_size);
  if (ret2 == -1)
    return -1;
  const char *_arg1182 = "/copyff/src";
  const char *_arg1183 = "/copyff/dest";
  struct guestfs_copy_file_to_file_argv _optargs1184;
  _optargs1184.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_copy_file_to_file_argv (g, _arg1182, _arg1183, &_optargs1184);
  if (ret1 == -1)
    return -1;
  const char *_arg1185 = "/copyff/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg1185, &size);
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
test_copy_file_to_file_1 (void)
{
  if (test_copy_file_to_file_1_skip ()) {
    skipped ("test_copy_file_to_file_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_copy_file_to_file_1 */
  const char *_arg1188 = "/dev/sda";
  int _ret1187;
  _ret1187 = guestfs_blockdev_setrw (g, _arg1188);
  if (_ret1187 == -1)
    return -1;
  int _ret1190;
  _ret1190 = guestfs_umount_all (g);
  if (_ret1190 == -1)
    return -1;
  int _ret1192;
  _ret1192 = guestfs_lvm_remove_all (g);
  if (_ret1192 == -1)
    return -1;
  const char *_arg1195 = "/dev/sdb1";
  const char *_arg1196 = "/";
  int _ret1194;
  _ret1194 = guestfs_mount (g, _arg1195, _arg1196);
  if (_ret1194 == -1)
    return -1;

  /* TestResultTrue for copy_file_to_file (1) */
  const char *_arg1199 = "/copyff2";
  int _ret1198;
  _ret1198 = guestfs_mkdir (g, _arg1199);
  if (_ret1198 == -1)
    return -1;
  const char *_arg1204 = "/copyff2/src";
  int _ret1201;
  _ret1201 = guestfs_fill (g, 0, 1048576, _arg1204);
  if (_ret1201 == -1)
    return -1;
  const char *_arg1207 = "/copyff2/dest";
  int _ret1206;
  _ret1206 = guestfs_touch (g, _arg1207);
  if (_ret1206 == -1)
    return -1;
  const char *_arg1210 = "/copyff2/dest";
  int _ret1209;
  _ret1209 = guestfs_truncate_size (g, _arg1210, 1048576);
  if (_ret1209 == -1)
    return -1;
  const char *_arg1214 = "/copyff2/src";
  const char *_arg1215 = "/copyff2/dest";
  struct guestfs_copy_file_to_file_argv _optargs1216;
  _optargs1216.sparse = 1;
  _optargs1216.bitmask = UINT64_C(0x8);
  int _ret1213;
  _ret1213 = guestfs_copy_file_to_file_argv (g, _arg1214, _arg1215, &_optargs1216);
  if (_ret1213 == -1)
    return -1;
  const char *_arg1217 = "/copyff2/dest";
  int ret;
  ret = guestfs_is_zero (g, _arg1217);
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
test_part_to_partnum_0 (void)
{
  if (test_part_to_partnum_0_skip ()) {
    skipped ("test_part_to_partnum_0", "environment variable set");
    return 0;
  }

  /* InitPartition for test_part_to_partnum_0: create /dev/sda1 */
  const char *_arg1220 = "/dev/sda";
  int _ret1219;
  _ret1219 = guestfs_blockdev_setrw (g, _arg1220);
  if (_ret1219 == -1)
    return -1;
  int _ret1222;
  _ret1222 = guestfs_umount_all (g);
  if (_ret1222 == -1)
    return -1;
  int _ret1224;
  _ret1224 = guestfs_lvm_remove_all (g);
  if (_ret1224 == -1)
    return -1;
  const char *_arg1227 = "/dev/sda";
  const char *_arg1228 = "mbr";
  int _ret1226;
  _ret1226 = guestfs_part_disk (g, _arg1227, _arg1228);
  if (_ret1226 == -1)
    return -1;

  /* TestResult for part_to_partnum (0) */
  const char *_arg1230 = "/dev/sda1";
  int ret;
  ret = guestfs_part_to_partnum (g, _arg1230);
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
test_part_to_partnum_1 (void)
{
  if (test_part_to_partnum_1_skip ()) {
    skipped ("test_part_to_partnum_1", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_to_partnum_1 */
  const char *_arg1233 = "/dev/sda";
  int _ret1232;
  _ret1232 = guestfs_blockdev_setrw (g, _arg1233);
  if (_ret1232 == -1)
    return -1;
  int _ret1235;
  _ret1235 = guestfs_umount_all (g);
  if (_ret1235 == -1)
    return -1;
  int _ret1237;
  _ret1237 = guestfs_lvm_remove_all (g);
  if (_ret1237 == -1)
    return -1;

  /* TestLastFail for part_to_partnum (1) */
  const char *_arg1240 = "/dev/sda";
  int _ret1239;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1239 = guestfs_part_to_partnum (g, _arg1240);
  guestfs_pop_error_handler (g);
  if (_ret1239 != -1)
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
test_internal_write_append_0 (void)
{
  if (test_internal_write_append_0_skip ()) {
    skipped ("test_internal_write_append_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_internal_write_append_0 */
  const char *_arg1243 = "/dev/sda";
  int _ret1242;
  _ret1242 = guestfs_blockdev_setrw (g, _arg1243);
  if (_ret1242 == -1)
    return -1;
  int _ret1245;
  _ret1245 = guestfs_umount_all (g);
  if (_ret1245 == -1)
    return -1;
  int _ret1247;
  _ret1247 = guestfs_lvm_remove_all (g);
  if (_ret1247 == -1)
    return -1;
  const char *_arg1250 = "/dev/sdb1";
  const char *_arg1251 = "/";
  int _ret1249;
  _ret1249 = guestfs_mount (g, _arg1250, _arg1251);
  if (_ret1249 == -1)
    return -1;

  /* TestResultString for internal_write_append (0) */
  const char *_arg1254 = "/internal_write_append";
  const char *_arg1255 = "line1\n";
  size_t _arg1255_size = 6;
  int _ret1253;
  _ret1253 = guestfs_write (g, _arg1254, _arg1255, _arg1255_size);
  if (_ret1253 == -1)
    return -1;
  const char *_arg1258 = "/internal_write_append";
  const char *_arg1259 = "line2\n";
  size_t _arg1259_size = 6;
  int _ret1257;
  _ret1257 = guestfs_internal_write_append (g, _arg1258, _arg1259, _arg1259_size);
  if (_ret1257 == -1)
    return -1;
  const char *_arg1262 = "/internal_write_append";
  const char *_arg1263 = "line3a";
  size_t _arg1263_size = 6;
  int _ret1261;
  _ret1261 = guestfs_internal_write_append (g, _arg1262, _arg1263, _arg1263_size);
  if (_ret1261 == -1)
    return -1;
  const char *_arg1266 = "/internal_write_append";
  const char *_arg1267 = "line3b\n";
  size_t _arg1267_size = 7;
  int _ret1265;
  _ret1265 = guestfs_internal_write_append (g, _arg1266, _arg1267, _arg1267_size);
  if (_ret1265 == -1)
    return -1;
  const char *_arg1269 = "/internal_write_append";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1269);
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
test_is_zero_device_0 (void)
{
  if (test_is_zero_device_0_skip ()) {
    skipped ("test_is_zero_device_0", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_is_zero_device_0: create ext2 on /dev/sda1 */
  const char *_arg1272 = "/dev/sda";
  int _ret1271;
  _ret1271 = guestfs_blockdev_setrw (g, _arg1272);
  if (_ret1271 == -1)
    return -1;
  int _ret1274;
  _ret1274 = guestfs_umount_all (g);
  if (_ret1274 == -1)
    return -1;
  int _ret1276;
  _ret1276 = guestfs_lvm_remove_all (g);
  if (_ret1276 == -1)
    return -1;
  const char *_arg1279 = "/dev/sda";
  const char *_arg1280 = "mbr";
  int _ret1278;
  _ret1278 = guestfs_part_disk (g, _arg1279, _arg1280);
  if (_ret1278 == -1)
    return -1;
  const char *_arg1283 = "ext2";
  const char *_arg1284 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1285;
  _optargs1285.bitmask = UINT64_C(0x0);
  int _ret1282;
  _ret1282 = guestfs_mkfs_opts_argv (g, _arg1283, _arg1284, &_optargs1285);
  if (_ret1282 == -1)
    return -1;
  const char *_arg1287 = "/dev/sda1";
  const char *_arg1288 = "/";
  int _ret1286;
  _ret1286 = guestfs_mount (g, _arg1287, _arg1288);
  if (_ret1286 == -1)
    return -1;

  /* TestResultTrue for is_zero_device (0) */
  const char *_arg1291 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs1292;
  _optargs1292.force = 0;
  _optargs1292.lazyunmount = 0;
  _optargs1292.bitmask = UINT64_C(0x3);
  int _ret1290;
  _ret1290 = guestfs_umount_opts_argv (g, _arg1291, &_optargs1292);
  if (_ret1290 == -1)
    return -1;
  const char *_arg1294 = "/dev/sda1";
  int _ret1293;
  _ret1293 = guestfs_zero_device (g, _arg1294);
  if (_ret1293 == -1)
    return -1;
  const char *_arg1296 = "/dev/sda1";
  int ret;
  ret = guestfs_is_zero_device (g, _arg1296);
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
test_is_zero_device_1 (void)
{
  if (test_is_zero_device_1_skip ()) {
    skipped ("test_is_zero_device_1", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_is_zero_device_1: create ext2 on /dev/sda1 */
  const char *_arg1299 = "/dev/sda";
  int _ret1298;
  _ret1298 = guestfs_blockdev_setrw (g, _arg1299);
  if (_ret1298 == -1)
    return -1;
  int _ret1301;
  _ret1301 = guestfs_umount_all (g);
  if (_ret1301 == -1)
    return -1;
  int _ret1303;
  _ret1303 = guestfs_lvm_remove_all (g);
  if (_ret1303 == -1)
    return -1;
  const char *_arg1306 = "/dev/sda";
  const char *_arg1307 = "mbr";
  int _ret1305;
  _ret1305 = guestfs_part_disk (g, _arg1306, _arg1307);
  if (_ret1305 == -1)
    return -1;
  const char *_arg1310 = "ext2";
  const char *_arg1311 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1312;
  _optargs1312.bitmask = UINT64_C(0x0);
  int _ret1309;
  _ret1309 = guestfs_mkfs_opts_argv (g, _arg1310, _arg1311, &_optargs1312);
  if (_ret1309 == -1)
    return -1;
  const char *_arg1314 = "/dev/sda1";
  const char *_arg1315 = "/";
  int _ret1313;
  _ret1313 = guestfs_mount (g, _arg1314, _arg1315);
  if (_ret1313 == -1)
    return -1;

  /* TestResultFalse for is_zero_device (1) */
  const char *_arg1317 = "/dev/sda1";
  int ret;
  ret = guestfs_is_zero_device (g, _arg1317);
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
test_is_zero_0 (void)
{
  if (test_is_zero_0_skip ()) {
    skipped ("test_is_zero_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_is_zero_0 */
  const char *_arg1320 = "/dev/sda";
  int _ret1319;
  _ret1319 = guestfs_blockdev_setrw (g, _arg1320);
  if (_ret1319 == -1)
    return -1;
  int _ret1322;
  _ret1322 = guestfs_umount_all (g);
  if (_ret1322 == -1)
    return -1;
  int _ret1324;
  _ret1324 = guestfs_lvm_remove_all (g);
  if (_ret1324 == -1)
    return -1;
  const char *_arg1327 = "/dev/sdd";
  const char *_arg1328 = "/";
  int _ret1326;
  _ret1326 = guestfs_mount_ro (g, _arg1327, _arg1328);
  if (_ret1326 == -1)
    return -1;

  /* TestResultTrue for is_zero (0) */
  const char *_arg1330 = "/100kallzeroes";
  int ret;
  ret = guestfs_is_zero (g, _arg1330);
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
test_is_zero_1 (void)
{
  if (test_is_zero_1_skip ()) {
    skipped ("test_is_zero_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_is_zero_1 */
  const char *_arg1333 = "/dev/sda";
  int _ret1332;
  _ret1332 = guestfs_blockdev_setrw (g, _arg1333);
  if (_ret1332 == -1)
    return -1;
  int _ret1335;
  _ret1335 = guestfs_umount_all (g);
  if (_ret1335 == -1)
    return -1;
  int _ret1337;
  _ret1337 = guestfs_lvm_remove_all (g);
  if (_ret1337 == -1)
    return -1;
  const char *_arg1340 = "/dev/sdd";
  const char *_arg1341 = "/";
  int _ret1339;
  _ret1339 = guestfs_mount_ro (g, _arg1340, _arg1341);
  if (_ret1339 == -1)
    return -1;

  /* TestResultFalse for is_zero (1) */
  const char *_arg1343 = "/100kallspaces";
  int ret;
  ret = guestfs_is_zero (g, _arg1343);
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
test_mkfs_0 (void)
{
  if (test_mkfs_0_skip ()) {
    skipped ("test_mkfs_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_0 */
  const char *_arg1346 = "/dev/sda";
  int _ret1345;
  _ret1345 = guestfs_blockdev_setrw (g, _arg1346);
  if (_ret1345 == -1)
    return -1;
  int _ret1348;
  _ret1348 = guestfs_umount_all (g);
  if (_ret1348 == -1)
    return -1;
  int _ret1350;
  _ret1350 = guestfs_lvm_remove_all (g);
  if (_ret1350 == -1)
    return -1;

  /* TestResultString for mkfs (0) */
  const char *_arg1353 = "/dev/sda";
  const char *_arg1354 = "mbr";
  int _ret1352;
  _ret1352 = guestfs_part_disk (g, _arg1353, _arg1354);
  if (_ret1352 == -1)
    return -1;
  const char *_arg1357 = "ext2";
  const char *_arg1358 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1359;
  _optargs1359.bitmask = UINT64_C(0x0);
  int _ret1356;
  _ret1356 = guestfs_mkfs_opts_argv (g, _arg1357, _arg1358, &_optargs1359);
  if (_ret1356 == -1)
    return -1;
  const char *_arg1361 = "/dev/sda1";
  const char *_arg1362 = "/";
  int _ret1360;
  _ret1360 = guestfs_mount (g, _arg1361, _arg1362);
  if (_ret1360 == -1)
    return -1;
  const char *_arg1365 = "/new";
  const char *_arg1366 = "new file contents";
  size_t _arg1366_size = 17;
  int _ret1364;
  _ret1364 = guestfs_write (g, _arg1365, _arg1366, _arg1366_size);
  if (_ret1364 == -1)
    return -1;
  const char *_arg1368 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1368);
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
test_lvm_canonical_lv_name_0 (void)
{
  if (test_lvm_canonical_lv_name_0_skip ()) {
    skipped ("test_lvm_canonical_lv_name_0", "environment variable set");
    return 0;
  }

  const char *_features1370[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features1370)) {
    skipped ("test_lvm_canonical_lv_name_0", "group %s not available in daemon",
             _features1370[0]);
    return 0;
  }

  /* InitBasicFSonLVM for test_lvm_canonical_lv_name_0: create ext2 on /dev/VG/LV */
  const char *_arg1372 = "/dev/sda";
  int _ret1371;
  _ret1371 = guestfs_blockdev_setrw (g, _arg1372);
  if (_ret1371 == -1)
    return -1;
  int _ret1374;
  _ret1374 = guestfs_umount_all (g);
  if (_ret1374 == -1)
    return -1;
  int _ret1376;
  _ret1376 = guestfs_lvm_remove_all (g);
  if (_ret1376 == -1)
    return -1;
  const char *_arg1379 = "/dev/sda";
  const char *_arg1380 = "mbr";
  int _ret1378;
  _ret1378 = guestfs_part_disk (g, _arg1379, _arg1380);
  if (_ret1378 == -1)
    return -1;
  const char *_arg1383 = "/dev/sda1";
  int _ret1382;
  _ret1382 = guestfs_pvcreate (g, _arg1383);
  if (_ret1382 == -1)
    return -1;
  const char *_arg1386 = "VG";
  const char *_arg1387_0 = "/dev/sda1";
  const char *const _arg1387[] = {
    _arg1387_0,
    NULL
  };
  int _ret1385;
  _ret1385 = guestfs_vgcreate (g, _arg1386, (char **) _arg1387);
  if (_ret1385 == -1)
    return -1;
  const char *_arg1390 = "LV";
  const char *_arg1391 = "VG";
  int _ret1389;
  _ret1389 = guestfs_lvcreate (g, _arg1390, _arg1391, 8);
  if (_ret1389 == -1)
    return -1;
  const char *_arg1395 = "ext2";
  const char *_arg1396 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs1397;
  _optargs1397.bitmask = UINT64_C(0x0);
  int _ret1394;
  _ret1394 = guestfs_mkfs_opts_argv (g, _arg1395, _arg1396, &_optargs1397);
  if (_ret1394 == -1)
    return -1;
  const char *_arg1399 = "/dev/VG/LV";
  const char *_arg1400 = "/";
  int _ret1398;
  _ret1398 = guestfs_mount (g, _arg1399, _arg1400);
  if (_ret1398 == -1)
    return -1;

  /* TestResultString for lvm_canonical_lv_name (0) */
  const char *_arg1402 = "/dev/mapper/VG-LV";
  CLEANUP_FREE char *ret;
  ret = guestfs_lvm_canonical_lv_name (g, _arg1402);
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
test_lvm_canonical_lv_name_1 (void)
{
  if (test_lvm_canonical_lv_name_1_skip ()) {
    skipped ("test_lvm_canonical_lv_name_1", "environment variable set");
    return 0;
  }

  const char *_features1404[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features1404)) {
    skipped ("test_lvm_canonical_lv_name_1", "group %s not available in daemon",
             _features1404[0]);
    return 0;
  }

  /* InitBasicFSonLVM for test_lvm_canonical_lv_name_1: create ext2 on /dev/VG/LV */
  const char *_arg1406 = "/dev/sda";
  int _ret1405;
  _ret1405 = guestfs_blockdev_setrw (g, _arg1406);
  if (_ret1405 == -1)
    return -1;
  int _ret1408;
  _ret1408 = guestfs_umount_all (g);
  if (_ret1408 == -1)
    return -1;
  int _ret1410;
  _ret1410 = guestfs_lvm_remove_all (g);
  if (_ret1410 == -1)
    return -1;
  const char *_arg1413 = "/dev/sda";
  const char *_arg1414 = "mbr";
  int _ret1412;
  _ret1412 = guestfs_part_disk (g, _arg1413, _arg1414);
  if (_ret1412 == -1)
    return -1;
  const char *_arg1417 = "/dev/sda1";
  int _ret1416;
  _ret1416 = guestfs_pvcreate (g, _arg1417);
  if (_ret1416 == -1)
    return -1;
  const char *_arg1420 = "VG";
  const char *_arg1421_0 = "/dev/sda1";
  const char *const _arg1421[] = {
    _arg1421_0,
    NULL
  };
  int _ret1419;
  _ret1419 = guestfs_vgcreate (g, _arg1420, (char **) _arg1421);
  if (_ret1419 == -1)
    return -1;
  const char *_arg1424 = "LV";
  const char *_arg1425 = "VG";
  int _ret1423;
  _ret1423 = guestfs_lvcreate (g, _arg1424, _arg1425, 8);
  if (_ret1423 == -1)
    return -1;
  const char *_arg1429 = "ext2";
  const char *_arg1430 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs1431;
  _optargs1431.bitmask = UINT64_C(0x0);
  int _ret1428;
  _ret1428 = guestfs_mkfs_opts_argv (g, _arg1429, _arg1430, &_optargs1431);
  if (_ret1428 == -1)
    return -1;
  const char *_arg1433 = "/dev/VG/LV";
  const char *_arg1434 = "/";
  int _ret1432;
  _ret1432 = guestfs_mount (g, _arg1433, _arg1434);
  if (_ret1432 == -1)
    return -1;

  /* TestResultString for lvm_canonical_lv_name (1) */
  const char *_arg1436 = "/dev/VG/LV";
  CLEANUP_FREE char *ret;
  ret = guestfs_lvm_canonical_lv_name (g, _arg1436);
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
test_pread_device_0 (void)
{
  if (test_pread_device_0_skip ()) {
    skipped ("test_pread_device_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_pread_device_0 */
  const char *_arg1439 = "/dev/sda";
  int _ret1438;
  _ret1438 = guestfs_blockdev_setrw (g, _arg1439);
  if (_ret1438 == -1)
    return -1;
  int _ret1441;
  _ret1441 = guestfs_umount_all (g);
  if (_ret1441 == -1)
    return -1;
  int _ret1443;
  _ret1443 = guestfs_lvm_remove_all (g);
  if (_ret1443 == -1)
    return -1;

  /* TestResult for pread_device (0) */
  const char *_arg1445 = "/dev/sdd";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread_device (g, _arg1445, 8, 32768, &size);
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
test_pwrite_device_0 (void)
{
  if (test_pwrite_device_0_skip ()) {
    skipped ("test_pwrite_device_0", "environment variable set");
    return 0;
  }

  /* InitPartition for test_pwrite_device_0: create /dev/sda1 */
  const char *_arg1450 = "/dev/sda";
  int _ret1449;
  _ret1449 = guestfs_blockdev_setrw (g, _arg1450);
  if (_ret1449 == -1)
    return -1;
  int _ret1452;
  _ret1452 = guestfs_umount_all (g);
  if (_ret1452 == -1)
    return -1;
  int _ret1454;
  _ret1454 = guestfs_lvm_remove_all (g);
  if (_ret1454 == -1)
    return -1;
  const char *_arg1457 = "/dev/sda";
  const char *_arg1458 = "mbr";
  int _ret1456;
  _ret1456 = guestfs_part_disk (g, _arg1457, _arg1458);
  if (_ret1456 == -1)
    return -1;

  /* TestResult for pwrite_device (0) */
  const char *_arg1460 = "/dev/sda";
  const char *_arg1461 = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
  size_t _arg1461_size = 66;
  int ret2;
  ret2 = guestfs_pwrite_device (g, _arg1460, _arg1461, _arg1461_size, 446);
  if (ret2 == -1)
    return -1;
  const char *_arg1464 = "/dev/sda";
  int ret1;
  ret1 = guestfs_blockdev_rereadpt (g, _arg1464);
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
test_download_offset_0 (void)
{
  if (test_download_offset_0_skip ()) {
    skipped ("test_download_offset_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_download_offset_0 */
  const char *_arg1468 = "/dev/sda";
  int _ret1467;
  _ret1467 = guestfs_blockdev_setrw (g, _arg1468);
  if (_ret1467 == -1)
    return -1;
  int _ret1470;
  _ret1470 = guestfs_umount_all (g);
  if (_ret1470 == -1)
    return -1;
  int _ret1472;
  _ret1472 = guestfs_lvm_remove_all (g);
  if (_ret1472 == -1)
    return -1;
  const char *_arg1475 = "/dev/sdb1";
  const char *_arg1476 = "/";
  int _ret1474;
  _ret1474 = guestfs_mount (g, _arg1475, _arg1476);
  if (_ret1474 == -1)
    return -1;

  /* TestResultString for download_offset (0) */
  const char *_arg1479 = "/download_offset";
  int _ret1478;
  _ret1478 = guestfs_mkdir (g, _arg1479);
  if (_ret1478 == -1)
    return -1;
  const char *_arg1483 = "/download_offset/COPYING.LIB";
  int _ret1481;
  _ret1481 = guestfs_upload (g, "../../COPYING.LIB", _arg1483);
  if (_ret1481 == -1)
    return -1;
  const char *_arg1486 = "/download_offset/COPYING.LIB";
  int _ret1485;
  _ret1485 = guestfs_download_offset (g, _arg1486, "testdownload.tmp", 100, 26430);
  if (_ret1485 == -1)
    return -1;
  const char *_arg1493 = "/download_offset/COPYING.LIB";
  int _ret1491;
  _ret1491 = guestfs_upload_offset (g, "testdownload.tmp", _arg1493, 100);
  if (_ret1491 == -1)
    return -1;
  const char *_arg1496 = "md5";
  const char *_arg1497 = "/download_offset/COPYING.LIB";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg1496, _arg1497);
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
test_upload_offset_0 (void)
{
  if (test_upload_offset_0_skip ()) {
    skipped ("test_upload_offset_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_upload_offset_0 */
  const char *_arg1500 = "/dev/sda";
  int _ret1499;
  _ret1499 = guestfs_blockdev_setrw (g, _arg1500);
  if (_ret1499 == -1)
    return -1;
  int _ret1502;
  _ret1502 = guestfs_umount_all (g);
  if (_ret1502 == -1)
    return -1;
  int _ret1504;
  _ret1504 = guestfs_lvm_remove_all (g);
  if (_ret1504 == -1)
    return -1;
  const char *_arg1507 = "/dev/sdb1";
  const char *_arg1508 = "/";
  int _ret1506;
  _ret1506 = guestfs_mount (g, _arg1507, _arg1508);
  if (_ret1506 == -1)
    return -1;

  /* TestResultString for upload_offset (0) */
  const char *_arg1512 = "/upload_offset";
  int _ret1510;
  _ret1510 = guestfs_upload_offset (g, "../../COPYING.LIB", _arg1512, 0);
  if (_ret1510 == -1)
    return -1;
  const char *_arg1515 = "md5";
  const char *_arg1516 = "/upload_offset";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg1515, _arg1516);
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
test_part_to_dev_0 (void)
{
  if (test_part_to_dev_0_skip ()) {
    skipped ("test_part_to_dev_0", "environment variable set");
    return 0;
  }

  /* InitPartition for test_part_to_dev_0: create /dev/sda1 */
  const char *_arg1519 = "/dev/sda";
  int _ret1518;
  _ret1518 = guestfs_blockdev_setrw (g, _arg1519);
  if (_ret1518 == -1)
    return -1;
  int _ret1521;
  _ret1521 = guestfs_umount_all (g);
  if (_ret1521 == -1)
    return -1;
  int _ret1523;
  _ret1523 = guestfs_lvm_remove_all (g);
  if (_ret1523 == -1)
    return -1;
  const char *_arg1526 = "/dev/sda";
  const char *_arg1527 = "mbr";
  int _ret1525;
  _ret1525 = guestfs_part_disk (g, _arg1526, _arg1527);
  if (_ret1525 == -1)
    return -1;

  /* TestResultDevice for part_to_dev (0) */
  const char *_arg1529 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_to_dev (g, _arg1529);
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
test_part_to_dev_1 (void)
{
  if (test_part_to_dev_1_skip ()) {
    skipped ("test_part_to_dev_1", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_to_dev_1 */
  const char *_arg1532 = "/dev/sda";
  int _ret1531;
  _ret1531 = guestfs_blockdev_setrw (g, _arg1532);
  if (_ret1531 == -1)
    return -1;
  int _ret1534;
  _ret1534 = guestfs_umount_all (g);
  if (_ret1534 == -1)
    return -1;
  int _ret1536;
  _ret1536 = guestfs_lvm_remove_all (g);
  if (_ret1536 == -1)
    return -1;

  /* TestLastFail for part_to_dev (1) */
  const char *_arg1539 = "/dev/sda";
  CLEANUP_FREE char *_ret1538;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret1538 = guestfs_part_to_dev (g, _arg1539);
  guestfs_pop_error_handler (g);
  if (_ret1538 != NULL)
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
test_is_socket_0 (void)
{
  if (test_is_socket_0_skip ()) {
    skipped ("test_is_socket_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_is_socket_0 */
  const char *_arg1542 = "/dev/sda";
  int _ret1541;
  _ret1541 = guestfs_blockdev_setrw (g, _arg1542);
  if (_ret1541 == -1)
    return -1;
  int _ret1544;
  _ret1544 = guestfs_umount_all (g);
  if (_ret1544 == -1)
    return -1;
  int _ret1546;
  _ret1546 = guestfs_lvm_remove_all (g);
  if (_ret1546 == -1)
    return -1;
  const char *_arg1549 = "/dev/sdd";
  const char *_arg1550 = "/";
  int _ret1548;
  _ret1548 = guestfs_mount_ro (g, _arg1549, _arg1550);
  if (_ret1548 == -1)
    return -1;

  /* TestResultFalse for is_socket (0) */
  const char *_arg1552 = "/directory";
  int ret;
  ret = guestfs_is_socket (g, _arg1552);
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
test_is_symlink_0 (void)
{
  if (test_is_symlink_0_skip ()) {
    skipped ("test_is_symlink_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_is_symlink_0 */
  const char *_arg1555 = "/dev/sda";
  int _ret1554;
  _ret1554 = guestfs_blockdev_setrw (g, _arg1555);
  if (_ret1554 == -1)
    return -1;
  int _ret1557;
  _ret1557 = guestfs_umount_all (g);
  if (_ret1557 == -1)
    return -1;
  int _ret1559;
  _ret1559 = guestfs_lvm_remove_all (g);
  if (_ret1559 == -1)
    return -1;
  const char *_arg1562 = "/dev/sdd";
  const char *_arg1563 = "/";
  int _ret1561;
  _ret1561 = guestfs_mount_ro (g, _arg1562, _arg1563);
  if (_ret1561 == -1)
    return -1;

  /* TestResultFalse for is_symlink (0) */
  const char *_arg1565 = "/directory";
  int ret;
  ret = guestfs_is_symlink (g, _arg1565);
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
test_is_symlink_1 (void)
{
  if (test_is_symlink_1_skip ()) {
    skipped ("test_is_symlink_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_is_symlink_1 */
  const char *_arg1568 = "/dev/sda";
  int _ret1567;
  _ret1567 = guestfs_blockdev_setrw (g, _arg1568);
  if (_ret1567 == -1)
    return -1;
  int _ret1570;
  _ret1570 = guestfs_umount_all (g);
  if (_ret1570 == -1)
    return -1;
  int _ret1572;
  _ret1572 = guestfs_lvm_remove_all (g);
  if (_ret1572 == -1)
    return -1;
  const char *_arg1575 = "/dev/sdd";
  const char *_arg1576 = "/";
  int _ret1574;
  _ret1574 = guestfs_mount_ro (g, _arg1575, _arg1576);
  if (_ret1574 == -1)
    return -1;

  /* TestResultTrue for is_symlink (1) */
  const char *_arg1578 = "/abssymlink";
  int ret;
  ret = guestfs_is_symlink (g, _arg1578);
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
test_is_fifo_0 (void)
{
  if (test_is_fifo_0_skip ()) {
    skipped ("test_is_fifo_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_is_fifo_0 */
  const char *_arg1581 = "/dev/sda";
  int _ret1580;
  _ret1580 = guestfs_blockdev_setrw (g, _arg1581);
  if (_ret1580 == -1)
    return -1;
  int _ret1583;
  _ret1583 = guestfs_umount_all (g);
  if (_ret1583 == -1)
    return -1;
  int _ret1585;
  _ret1585 = guestfs_lvm_remove_all (g);
  if (_ret1585 == -1)
    return -1;
  const char *_arg1588 = "/dev/sdd";
  const char *_arg1589 = "/";
  int _ret1587;
  _ret1587 = guestfs_mount_ro (g, _arg1588, _arg1589);
  if (_ret1587 == -1)
    return -1;

  /* TestResultFalse for is_fifo (0) */
  const char *_arg1591 = "/directory";
  int ret;
  ret = guestfs_is_fifo (g, _arg1591);
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
test_is_fifo_1 (void)
{
  if (test_is_fifo_1_skip ()) {
    skipped ("test_is_fifo_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_is_fifo_1 */
  const char *_arg1594 = "/dev/sda";
  int _ret1593;
  _ret1593 = guestfs_blockdev_setrw (g, _arg1594);
  if (_ret1593 == -1)
    return -1;
  int _ret1596;
  _ret1596 = guestfs_umount_all (g);
  if (_ret1596 == -1)
    return -1;
  int _ret1598;
  _ret1598 = guestfs_lvm_remove_all (g);
  if (_ret1598 == -1)
    return -1;
  const char *_arg1601 = "/dev/sdb1";
  const char *_arg1602 = "/";
  int _ret1600;
  _ret1600 = guestfs_mount (g, _arg1601, _arg1602);
  if (_ret1600 == -1)
    return -1;

  /* TestResultTrue for is_fifo (1) */
  const char *_arg1606 = "/is_fifo";
  int _ret1604;
  _ret1604 = guestfs_mkfifo (g, 511, _arg1606);
  if (_ret1604 == -1)
    return -1;
  const char *_arg1608 = "/is_fifo";
  int ret;
  ret = guestfs_is_fifo (g, _arg1608);
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
test_is_blockdev_0 (void)
{
  if (test_is_blockdev_0_skip ()) {
    skipped ("test_is_blockdev_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_is_blockdev_0 */
  const char *_arg1611 = "/dev/sda";
  int _ret1610;
  _ret1610 = guestfs_blockdev_setrw (g, _arg1611);
  if (_ret1610 == -1)
    return -1;
  int _ret1613;
  _ret1613 = guestfs_umount_all (g);
  if (_ret1613 == -1)
    return -1;
  int _ret1615;
  _ret1615 = guestfs_lvm_remove_all (g);
  if (_ret1615 == -1)
    return -1;
  const char *_arg1618 = "/dev/sdd";
  const char *_arg1619 = "/";
  int _ret1617;
  _ret1617 = guestfs_mount_ro (g, _arg1618, _arg1619);
  if (_ret1617 == -1)
    return -1;

  /* TestResultFalse for is_blockdev (0) */
  const char *_arg1621 = "/directory";
  int ret;
  ret = guestfs_is_blockdev (g, _arg1621);
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
test_is_blockdev_1 (void)
{
  if (test_is_blockdev_1_skip ()) {
    skipped ("test_is_blockdev_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_is_blockdev_1 */
  const char *_arg1624 = "/dev/sda";
  int _ret1623;
  _ret1623 = guestfs_blockdev_setrw (g, _arg1624);
  if (_ret1623 == -1)
    return -1;
  int _ret1626;
  _ret1626 = guestfs_umount_all (g);
  if (_ret1626 == -1)
    return -1;
  int _ret1628;
  _ret1628 = guestfs_lvm_remove_all (g);
  if (_ret1628 == -1)
    return -1;
  const char *_arg1631 = "/dev/sdb1";
  const char *_arg1632 = "/";
  int _ret1630;
  _ret1630 = guestfs_mount (g, _arg1631, _arg1632);
  if (_ret1630 == -1)
    return -1;

  /* TestResultTrue for is_blockdev (1) */
  const char *_arg1638 = "/is_blockdev";
  int _ret1634;
  _ret1634 = guestfs_mknod_b (g, 511, 99, 66, _arg1638);
  if (_ret1634 == -1)
    return -1;
  const char *_arg1640 = "/is_blockdev";
  int ret;
  ret = guestfs_is_blockdev (g, _arg1640);
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
test_is_chardev_0 (void)
{
  if (test_is_chardev_0_skip ()) {
    skipped ("test_is_chardev_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_is_chardev_0 */
  const char *_arg1643 = "/dev/sda";
  int _ret1642;
  _ret1642 = guestfs_blockdev_setrw (g, _arg1643);
  if (_ret1642 == -1)
    return -1;
  int _ret1645;
  _ret1645 = guestfs_umount_all (g);
  if (_ret1645 == -1)
    return -1;
  int _ret1647;
  _ret1647 = guestfs_lvm_remove_all (g);
  if (_ret1647 == -1)
    return -1;
  const char *_arg1650 = "/dev/sdd";
  const char *_arg1651 = "/";
  int _ret1649;
  _ret1649 = guestfs_mount_ro (g, _arg1650, _arg1651);
  if (_ret1649 == -1)
    return -1;

  /* TestResultFalse for is_chardev (0) */
  const char *_arg1653 = "/directory";
  int ret;
  ret = guestfs_is_chardev (g, _arg1653);
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
test_is_chardev_1 (void)
{
  if (test_is_chardev_1_skip ()) {
    skipped ("test_is_chardev_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_is_chardev_1 */
  const char *_arg1656 = "/dev/sda";
  int _ret1655;
  _ret1655 = guestfs_blockdev_setrw (g, _arg1656);
  if (_ret1655 == -1)
    return -1;
  int _ret1658;
  _ret1658 = guestfs_umount_all (g);
  if (_ret1658 == -1)
    return -1;
  int _ret1660;
  _ret1660 = guestfs_lvm_remove_all (g);
  if (_ret1660 == -1)
    return -1;
  const char *_arg1663 = "/dev/sdb1";
  const char *_arg1664 = "/";
  int _ret1662;
  _ret1662 = guestfs_mount (g, _arg1663, _arg1664);
  if (_ret1662 == -1)
    return -1;

  /* TestResultTrue for is_chardev (1) */
  const char *_arg1670 = "/is_chardev";
  int _ret1666;
  _ret1666 = guestfs_mknod_c (g, 511, 99, 66, _arg1670);
  if (_ret1666 == -1)
    return -1;
  const char *_arg1672 = "/is_chardev";
  int ret;
  ret = guestfs_is_chardev (g, _arg1672);
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
test_is_lv_0 (void)
{
  if (test_is_lv_0_skip ()) {
    skipped ("test_is_lv_0", "environment variable set");
    return 0;
  }

  /* InitBasicFSonLVM for test_is_lv_0: create ext2 on /dev/VG/LV */
  const char *_arg1675 = "/dev/sda";
  int _ret1674;
  _ret1674 = guestfs_blockdev_setrw (g, _arg1675);
  if (_ret1674 == -1)
    return -1;
  int _ret1677;
  _ret1677 = guestfs_umount_all (g);
  if (_ret1677 == -1)
    return -1;
  int _ret1679;
  _ret1679 = guestfs_lvm_remove_all (g);
  if (_ret1679 == -1)
    return -1;
  const char *_arg1682 = "/dev/sda";
  const char *_arg1683 = "mbr";
  int _ret1681;
  _ret1681 = guestfs_part_disk (g, _arg1682, _arg1683);
  if (_ret1681 == -1)
    return -1;
  const char *_arg1686 = "/dev/sda1";
  int _ret1685;
  _ret1685 = guestfs_pvcreate (g, _arg1686);
  if (_ret1685 == -1)
    return -1;
  const char *_arg1689 = "VG";
  const char *_arg1690_0 = "/dev/sda1";
  const char *const _arg1690[] = {
    _arg1690_0,
    NULL
  };
  int _ret1688;
  _ret1688 = guestfs_vgcreate (g, _arg1689, (char **) _arg1690);
  if (_ret1688 == -1)
    return -1;
  const char *_arg1693 = "LV";
  const char *_arg1694 = "VG";
  int _ret1692;
  _ret1692 = guestfs_lvcreate (g, _arg1693, _arg1694, 8);
  if (_ret1692 == -1)
    return -1;
  const char *_arg1698 = "ext2";
  const char *_arg1699 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs1700;
  _optargs1700.bitmask = UINT64_C(0x0);
  int _ret1697;
  _ret1697 = guestfs_mkfs_opts_argv (g, _arg1698, _arg1699, &_optargs1700);
  if (_ret1697 == -1)
    return -1;
  const char *_arg1702 = "/dev/VG/LV";
  const char *_arg1703 = "/";
  int _ret1701;
  _ret1701 = guestfs_mount (g, _arg1702, _arg1703);
  if (_ret1701 == -1)
    return -1;

  /* TestResultTrue for is_lv (0) */
  const char *_arg1705 = "/dev/VG/LV";
  int ret;
  ret = guestfs_is_lv (g, _arg1705);
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
test_is_lv_1 (void)
{
  if (test_is_lv_1_skip ()) {
    skipped ("test_is_lv_1", "environment variable set");
    return 0;
  }

  /* InitBasicFSonLVM for test_is_lv_1: create ext2 on /dev/VG/LV */
  const char *_arg1708 = "/dev/sda";
  int _ret1707;
  _ret1707 = guestfs_blockdev_setrw (g, _arg1708);
  if (_ret1707 == -1)
    return -1;
  int _ret1710;
  _ret1710 = guestfs_umount_all (g);
  if (_ret1710 == -1)
    return -1;
  int _ret1712;
  _ret1712 = guestfs_lvm_remove_all (g);
  if (_ret1712 == -1)
    return -1;
  const char *_arg1715 = "/dev/sda";
  const char *_arg1716 = "mbr";
  int _ret1714;
  _ret1714 = guestfs_part_disk (g, _arg1715, _arg1716);
  if (_ret1714 == -1)
    return -1;
  const char *_arg1719 = "/dev/sda1";
  int _ret1718;
  _ret1718 = guestfs_pvcreate (g, _arg1719);
  if (_ret1718 == -1)
    return -1;
  const char *_arg1722 = "VG";
  const char *_arg1723_0 = "/dev/sda1";
  const char *const _arg1723[] = {
    _arg1723_0,
    NULL
  };
  int _ret1721;
  _ret1721 = guestfs_vgcreate (g, _arg1722, (char **) _arg1723);
  if (_ret1721 == -1)
    return -1;
  const char *_arg1726 = "LV";
  const char *_arg1727 = "VG";
  int _ret1725;
  _ret1725 = guestfs_lvcreate (g, _arg1726, _arg1727, 8);
  if (_ret1725 == -1)
    return -1;
  const char *_arg1731 = "ext2";
  const char *_arg1732 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs1733;
  _optargs1733.bitmask = UINT64_C(0x0);
  int _ret1730;
  _ret1730 = guestfs_mkfs_opts_argv (g, _arg1731, _arg1732, &_optargs1733);
  if (_ret1730 == -1)
    return -1;
  const char *_arg1735 = "/dev/VG/LV";
  const char *_arg1736 = "/";
  int _ret1734;
  _ret1734 = guestfs_mount (g, _arg1735, _arg1736);
  if (_ret1734 == -1)
    return -1;

  /* TestResultFalse for is_lv (1) */
  const char *_arg1738 = "/dev/sda1";
  int ret;
  ret = guestfs_is_lv (g, _arg1738);
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
test_vfs_uuid_0 (void)
{
  if (test_vfs_uuid_0_skip ()) {
    skipped ("test_vfs_uuid_0", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_vfs_uuid_0: create ext2 on /dev/sda1 */
  const char *_arg1741 = "/dev/sda";
  int _ret1740;
  _ret1740 = guestfs_blockdev_setrw (g, _arg1741);
  if (_ret1740 == -1)
    return -1;
  int _ret1743;
  _ret1743 = guestfs_umount_all (g);
  if (_ret1743 == -1)
    return -1;
  int _ret1745;
  _ret1745 = guestfs_lvm_remove_all (g);
  if (_ret1745 == -1)
    return -1;
  const char *_arg1748 = "/dev/sda";
  const char *_arg1749 = "mbr";
  int _ret1747;
  _ret1747 = guestfs_part_disk (g, _arg1748, _arg1749);
  if (_ret1747 == -1)
    return -1;
  const char *_arg1752 = "ext2";
  const char *_arg1753 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1754;
  _optargs1754.bitmask = UINT64_C(0x0);
  int _ret1751;
  _ret1751 = guestfs_mkfs_opts_argv (g, _arg1752, _arg1753, &_optargs1754);
  if (_ret1751 == -1)
    return -1;
  const char *_arg1756 = "/dev/sda1";
  const char *_arg1757 = "/";
  int _ret1755;
  _ret1755 = guestfs_mount (g, _arg1756, _arg1757);
  if (_ret1755 == -1)
    return -1;

  /* TestResultString for vfs_uuid (0) */
  const char *_arg1760 = "/dev/sda1";
  const char *_arg1761 = "fd5f5bd4-9254-0e03-76b4-43f62553291c";
  int _ret1759;
  _ret1759 = guestfs_set_e2uuid (g, _arg1760, _arg1761);
  if (_ret1759 == -1)
    return -1;
  const char *_arg1763 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_uuid (g, _arg1763);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "fd5f5bd4-9254-0e03-76b4-43f62553291c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_vfs_uuid_0", "vfs_uuid", ret, "fd5f5bd4-9254-0e03-76b4-43f62553291c");
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
test_vfs_label_0 (void)
{
  if (test_vfs_label_0_skip ()) {
    skipped ("test_vfs_label_0", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_vfs_label_0: create ext2 on /dev/sda1 */
  const char *_arg1766 = "/dev/sda";
  int _ret1765;
  _ret1765 = guestfs_blockdev_setrw (g, _arg1766);
  if (_ret1765 == -1)
    return -1;
  int _ret1768;
  _ret1768 = guestfs_umount_all (g);
  if (_ret1768 == -1)
    return -1;
  int _ret1770;
  _ret1770 = guestfs_lvm_remove_all (g);
  if (_ret1770 == -1)
    return -1;
  const char *_arg1773 = "/dev/sda";
  const char *_arg1774 = "mbr";
  int _ret1772;
  _ret1772 = guestfs_part_disk (g, _arg1773, _arg1774);
  if (_ret1772 == -1)
    return -1;
  const char *_arg1777 = "ext2";
  const char *_arg1778 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs1779;
  _optargs1779.bitmask = UINT64_C(0x0);
  int _ret1776;
  _ret1776 = guestfs_mkfs_opts_argv (g, _arg1777, _arg1778, &_optargs1779);
  if (_ret1776 == -1)
    return -1;
  const char *_arg1781 = "/dev/sda1";
  const char *_arg1782 = "/";
  int _ret1780;
  _ret1780 = guestfs_mount (g, _arg1781, _arg1782);
  if (_ret1780 == -1)
    return -1;

  /* TestResultString for vfs_label (0) */
  const char *_arg1785 = "/dev/sda1";
  const char *_arg1786 = "LTEST";
  int _ret1784;
  _ret1784 = guestfs_set_label (g, _arg1785, _arg1786);
  if (_ret1784 == -1)
    return -1;
  const char *_arg1788 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, _arg1788);
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
test_fallocate64_0 (void)
{
  if (test_fallocate64_0_skip ()) {
    skipped ("test_fallocate64_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_fallocate64_0 */
  const char *_arg1791 = "/dev/sda";
  int _ret1790;
  _ret1790 = guestfs_blockdev_setrw (g, _arg1791);
  if (_ret1790 == -1)
    return -1;
  int _ret1793;
  _ret1793 = guestfs_umount_all (g);
  if (_ret1793 == -1)
    return -1;
  int _ret1795;
  _ret1795 = guestfs_lvm_remove_all (g);
  if (_ret1795 == -1)
    return -1;
  const char *_arg1798 = "/dev/sdb1";
  const char *_arg1799 = "/";
  int _ret1797;
  _ret1797 = guestfs_mount (g, _arg1798, _arg1799);
  if (_ret1797 == -1)
    return -1;

  /* TestResult for fallocate64 (0) */
  const char *_arg1801 = "/fallocate64";
  int ret1;
  ret1 = guestfs_fallocate64 (g, _arg1801, 1000000);
  if (ret1 == -1)
    return -1;
  const char *_arg1804 = "/fallocate64";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg1804);
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
test_available_all_groups_0 (void)
{
  if (test_available_all_groups_0_skip ()) {
    skipped ("test_available_all_groups_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_available_all_groups_0 */
  const char *_arg1807 = "/dev/sda";
  int _ret1806;
  _ret1806 = guestfs_blockdev_setrw (g, _arg1807);
  if (_ret1806 == -1)
    return -1;
  int _ret1809;
  _ret1809 = guestfs_umount_all (g);
  if (_ret1809 == -1)
    return -1;
  int _ret1811;
  _ret1811 = guestfs_lvm_remove_all (g);
  if (_ret1811 == -1)
    return -1;

  /* TestRun for available_all_groups (0) */
  CLEANUP_FREE_STRING_LIST char **_ret1813;
  _ret1813 = guestfs_available_all_groups (g);
  if (_ret1813 == NULL)
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
test_pwrite_0 (void)
{
  if (test_pwrite_0_skip ()) {
    skipped ("test_pwrite_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_pwrite_0 */
  const char *_arg1816 = "/dev/sda";
  int _ret1815;
  _ret1815 = guestfs_blockdev_setrw (g, _arg1816);
  if (_ret1815 == -1)
    return -1;
  int _ret1818;
  _ret1818 = guestfs_umount_all (g);
  if (_ret1818 == -1)
    return -1;
  int _ret1820;
  _ret1820 = guestfs_lvm_remove_all (g);
  if (_ret1820 == -1)
    return -1;
  const char *_arg1823 = "/dev/sdb1";
  const char *_arg1824 = "/";
  int _ret1822;
  _ret1822 = guestfs_mount (g, _arg1823, _arg1824);
  if (_ret1822 == -1)
    return -1;

  /* TestResultString for pwrite (0) */
  const char *_arg1827 = "/pwrite";
  const char *_arg1828 = "new file contents";
  size_t _arg1828_size = 17;
  int _ret1826;
  _ret1826 = guestfs_write (g, _arg1827, _arg1828, _arg1828_size);
  if (_ret1826 == -1)
    return -1;
  const char *_arg1831 = "/pwrite";
  const char *_arg1832 = "data";
  size_t _arg1832_size = 4;
  int _ret1830;
  _ret1830 = guestfs_pwrite (g, _arg1831, _arg1832, _arg1832_size, 4);
  if (_ret1830 == -1)
    return -1;
  const char *_arg1835 = "/pwrite";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1835);
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
test_pwrite_1 (void)
{
  if (test_pwrite_1_skip ()) {
    skipped ("test_pwrite_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_pwrite_1 */
  const char *_arg1838 = "/dev/sda";
  int _ret1837;
  _ret1837 = guestfs_blockdev_setrw (g, _arg1838);
  if (_ret1837 == -1)
    return -1;
  int _ret1840;
  _ret1840 = guestfs_umount_all (g);
  if (_ret1840 == -1)
    return -1;
  int _ret1842;
  _ret1842 = guestfs_lvm_remove_all (g);
  if (_ret1842 == -1)
    return -1;
  const char *_arg1845 = "/dev/sdb1";
  const char *_arg1846 = "/";
  int _ret1844;
  _ret1844 = guestfs_mount (g, _arg1845, _arg1846);
  if (_ret1844 == -1)
    return -1;

  /* TestResultString for pwrite (1) */
  const char *_arg1849 = "/pwrite2";
  const char *_arg1850 = "new file contents";
  size_t _arg1850_size = 17;
  int _ret1848;
  _ret1848 = guestfs_write (g, _arg1849, _arg1850, _arg1850_size);
  if (_ret1848 == -1)
    return -1;
  const char *_arg1853 = "/pwrite2";
  const char *_arg1854 = "is extended";
  size_t _arg1854_size = 11;
  int _ret1852;
  _ret1852 = guestfs_pwrite (g, _arg1853, _arg1854, _arg1854_size, 9);
  if (_ret1852 == -1)
    return -1;
  const char *_arg1857 = "/pwrite2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1857);
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
test_pwrite_2 (void)
{
  if (test_pwrite_2_skip ()) {
    skipped ("test_pwrite_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_pwrite_2 */
  const char *_arg1860 = "/dev/sda";
  int _ret1859;
  _ret1859 = guestfs_blockdev_setrw (g, _arg1860);
  if (_ret1859 == -1)
    return -1;
  int _ret1862;
  _ret1862 = guestfs_umount_all (g);
  if (_ret1862 == -1)
    return -1;
  int _ret1864;
  _ret1864 = guestfs_lvm_remove_all (g);
  if (_ret1864 == -1)
    return -1;
  const char *_arg1867 = "/dev/sdb1";
  const char *_arg1868 = "/";
  int _ret1866;
  _ret1866 = guestfs_mount (g, _arg1867, _arg1868);
  if (_ret1866 == -1)
    return -1;

  /* TestResultString for pwrite (2) */
  const char *_arg1871 = "/pwrite3";
  const char *_arg1872 = "new file contents";
  size_t _arg1872_size = 17;
  int _ret1870;
  _ret1870 = guestfs_write (g, _arg1871, _arg1872, _arg1872_size);
  if (_ret1870 == -1)
    return -1;
  const char *_arg1875 = "/pwrite3";
  const char *_arg1876 = "";
  size_t _arg1876_size = 0;
  int _ret1874;
  _ret1874 = guestfs_pwrite (g, _arg1875, _arg1876, _arg1876_size, 4);
  if (_ret1874 == -1)
    return -1;
  const char *_arg1879 = "/pwrite3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1879);
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
test_internal_write_0 (void)
{
  if (test_internal_write_0_skip ()) {
    skipped ("test_internal_write_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_internal_write_0 */
  const char *_arg1882 = "/dev/sda";
  int _ret1881;
  _ret1881 = guestfs_blockdev_setrw (g, _arg1882);
  if (_ret1881 == -1)
    return -1;
  int _ret1884;
  _ret1884 = guestfs_umount_all (g);
  if (_ret1884 == -1)
    return -1;
  int _ret1886;
  _ret1886 = guestfs_lvm_remove_all (g);
  if (_ret1886 == -1)
    return -1;
  const char *_arg1889 = "/dev/sdb1";
  const char *_arg1890 = "/";
  int _ret1888;
  _ret1888 = guestfs_mount (g, _arg1889, _arg1890);
  if (_ret1888 == -1)
    return -1;

  /* TestResultString for internal_write (0) */
  const char *_arg1893 = "/internal_write";
  const char *_arg1894 = "new file contents";
  size_t _arg1894_size = 17;
  int _ret1892;
  _ret1892 = guestfs_internal_write (g, _arg1893, _arg1894, _arg1894_size);
  if (_ret1892 == -1)
    return -1;
  const char *_arg1896 = "/internal_write";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1896);
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
test_internal_write_1 (void)
{
  if (test_internal_write_1_skip ()) {
    skipped ("test_internal_write_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_internal_write_1 */
  const char *_arg1899 = "/dev/sda";
  int _ret1898;
  _ret1898 = guestfs_blockdev_setrw (g, _arg1899);
  if (_ret1898 == -1)
    return -1;
  int _ret1901;
  _ret1901 = guestfs_umount_all (g);
  if (_ret1901 == -1)
    return -1;
  int _ret1903;
  _ret1903 = guestfs_lvm_remove_all (g);
  if (_ret1903 == -1)
    return -1;
  const char *_arg1906 = "/dev/sdb1";
  const char *_arg1907 = "/";
  int _ret1905;
  _ret1905 = guestfs_mount (g, _arg1906, _arg1907);
  if (_ret1905 == -1)
    return -1;

  /* TestResultString for internal_write (1) */
  const char *_arg1910 = "/internal_write2";
  const char *_arg1911 = "\nnew file contents\n";
  size_t _arg1911_size = 19;
  int _ret1909;
  _ret1909 = guestfs_internal_write (g, _arg1910, _arg1911, _arg1911_size);
  if (_ret1909 == -1)
    return -1;
  const char *_arg1913 = "/internal_write2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1913);
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
test_internal_write_2 (void)
{
  if (test_internal_write_2_skip ()) {
    skipped ("test_internal_write_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_internal_write_2 */
  const char *_arg1916 = "/dev/sda";
  int _ret1915;
  _ret1915 = guestfs_blockdev_setrw (g, _arg1916);
  if (_ret1915 == -1)
    return -1;
  int _ret1918;
  _ret1918 = guestfs_umount_all (g);
  if (_ret1918 == -1)
    return -1;
  int _ret1920;
  _ret1920 = guestfs_lvm_remove_all (g);
  if (_ret1920 == -1)
    return -1;
  const char *_arg1923 = "/dev/sdb1";
  const char *_arg1924 = "/";
  int _ret1922;
  _ret1922 = guestfs_mount (g, _arg1923, _arg1924);
  if (_ret1922 == -1)
    return -1;

  /* TestResultString for internal_write (2) */
  const char *_arg1927 = "/internal_write3";
  const char *_arg1928 = "\n\n";
  size_t _arg1928_size = 2;
  int _ret1926;
  _ret1926 = guestfs_internal_write (g, _arg1927, _arg1928, _arg1928_size);
  if (_ret1926 == -1)
    return -1;
  const char *_arg1930 = "/internal_write3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1930);
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
test_internal_write_3 (void)
{
  if (test_internal_write_3_skip ()) {
    skipped ("test_internal_write_3", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_internal_write_3 */
  const char *_arg1933 = "/dev/sda";
  int _ret1932;
  _ret1932 = guestfs_blockdev_setrw (g, _arg1933);
  if (_ret1932 == -1)
    return -1;
  int _ret1935;
  _ret1935 = guestfs_umount_all (g);
  if (_ret1935 == -1)
    return -1;
  int _ret1937;
  _ret1937 = guestfs_lvm_remove_all (g);
  if (_ret1937 == -1)
    return -1;
  const char *_arg1940 = "/dev/sdb1";
  const char *_arg1941 = "/";
  int _ret1939;
  _ret1939 = guestfs_mount (g, _arg1940, _arg1941);
  if (_ret1939 == -1)
    return -1;

  /* TestResultString for internal_write (3) */
  const char *_arg1944 = "/internal_write4";
  const char *_arg1945 = "";
  size_t _arg1945_size = 0;
  int _ret1943;
  _ret1943 = guestfs_internal_write (g, _arg1944, _arg1945, _arg1945_size);
  if (_ret1943 == -1)
    return -1;
  const char *_arg1947 = "/internal_write4";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1947);
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
test_internal_write_4 (void)
{
  if (test_internal_write_4_skip ()) {
    skipped ("test_internal_write_4", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_internal_write_4 */
  const char *_arg1950 = "/dev/sda";
  int _ret1949;
  _ret1949 = guestfs_blockdev_setrw (g, _arg1950);
  if (_ret1949 == -1)
    return -1;
  int _ret1952;
  _ret1952 = guestfs_umount_all (g);
  if (_ret1952 == -1)
    return -1;
  int _ret1954;
  _ret1954 = guestfs_lvm_remove_all (g);
  if (_ret1954 == -1)
    return -1;
  const char *_arg1957 = "/dev/sdb1";
  const char *_arg1958 = "/";
  int _ret1956;
  _ret1956 = guestfs_mount (g, _arg1957, _arg1958);
  if (_ret1956 == -1)
    return -1;

  /* TestResultString for internal_write (4) */
  const char *_arg1961 = "/internal_write5";
  const char *_arg1962 = "\n\n\n";
  size_t _arg1962_size = 3;
  int _ret1960;
  _ret1960 = guestfs_internal_write (g, _arg1961, _arg1962, _arg1962_size);
  if (_ret1960 == -1)
    return -1;
  const char *_arg1964 = "/internal_write5";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1964);
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
test_internal_write_5 (void)
{
  if (test_internal_write_5_skip ()) {
    skipped ("test_internal_write_5", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_internal_write_5 */
  const char *_arg1967 = "/dev/sda";
  int _ret1966;
  _ret1966 = guestfs_blockdev_setrw (g, _arg1967);
  if (_ret1966 == -1)
    return -1;
  int _ret1969;
  _ret1969 = guestfs_umount_all (g);
  if (_ret1969 == -1)
    return -1;
  int _ret1971;
  _ret1971 = guestfs_lvm_remove_all (g);
  if (_ret1971 == -1)
    return -1;
  const char *_arg1974 = "/dev/sdb1";
  const char *_arg1975 = "/";
  int _ret1973;
  _ret1973 = guestfs_mount (g, _arg1974, _arg1975);
  if (_ret1973 == -1)
    return -1;

  /* TestResultString for internal_write (5) */
  const char *_arg1978 = "/internal_write6";
  const char *_arg1979 = "\n";
  size_t _arg1979_size = 1;
  int _ret1977;
  _ret1977 = guestfs_internal_write (g, _arg1978, _arg1979, _arg1979_size);
  if (_ret1977 == -1)
    return -1;
  const char *_arg1981 = "/internal_write6";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg1981);
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
test_fill_pattern_0 (void)
{
  if (test_fill_pattern_0_skip ()) {
    skipped ("test_fill_pattern_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_fill_pattern_0 */
  const char *_arg1984 = "/dev/sda";
  int _ret1983;
  _ret1983 = guestfs_blockdev_setrw (g, _arg1984);
  if (_ret1983 == -1)
    return -1;
  int _ret1986;
  _ret1986 = guestfs_umount_all (g);
  if (_ret1986 == -1)
    return -1;
  int _ret1988;
  _ret1988 = guestfs_lvm_remove_all (g);
  if (_ret1988 == -1)
    return -1;
  const char *_arg1991 = "/dev/sdb1";
  const char *_arg1992 = "/";
  int _ret1990;
  _ret1990 = guestfs_mount (g, _arg1991, _arg1992);
  if (_ret1990 == -1)
    return -1;

  /* TestResult for fill_pattern (0) */
  const char *_arg1994 = "abcdefghijklmnopqrstuvwxyz";
  const char *_arg1996 = "/fill_pattern";
  int ret1;
  ret1 = guestfs_fill_pattern (g, _arg1994, 28, _arg1996);
  if (ret1 == -1)
    return -1;
  const char *_arg1998 = "/fill_pattern";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg1998, &size);
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
test_base64_in_0 (void)
{
  if (test_base64_in_0_skip ()) {
    skipped ("test_base64_in_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_base64_in_0 */
  const char *_arg2001 = "/dev/sda";
  int _ret2000;
  _ret2000 = guestfs_blockdev_setrw (g, _arg2001);
  if (_ret2000 == -1)
    return -1;
  int _ret2003;
  _ret2003 = guestfs_umount_all (g);
  if (_ret2003 == -1)
    return -1;
  int _ret2005;
  _ret2005 = guestfs_lvm_remove_all (g);
  if (_ret2005 == -1)
    return -1;
  const char *_arg2008 = "/dev/sdb1";
  const char *_arg2009 = "/";
  int _ret2007;
  _ret2007 = guestfs_mount (g, _arg2008, _arg2009);
  if (_ret2007 == -1)
    return -1;

  /* TestResultString for base64_in (0) */
  const char *_arg2013 = "/base64_in";
  int _ret2011;
  _ret2011 = guestfs_base64_in (g, "../data/hello.b64", _arg2013);
  if (_ret2011 == -1)
    return -1;
  const char *_arg2015 = "/base64_in";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2015);
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
test_get_umask_0 (void)
{
  if (test_get_umask_0_skip ()) {
    skipped ("test_get_umask_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_umask_0 */
  const char *_arg2018 = "/dev/sda";
  int _ret2017;
  _ret2017 = guestfs_blockdev_setrw (g, _arg2018);
  if (_ret2017 == -1)
    return -1;
  int _ret2020;
  _ret2020 = guestfs_umount_all (g);
  if (_ret2020 == -1)
    return -1;
  int _ret2022;
  _ret2022 = guestfs_lvm_remove_all (g);
  if (_ret2022 == -1)
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
test_lvresize_free_0 (void)
{
  if (test_lvresize_free_0_skip ()) {
    skipped ("test_lvresize_free_0", "environment variable set");
    return 0;
  }

  const char *_features2025[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features2025)) {
    skipped ("test_lvresize_free_0", "group %s not available in daemon",
             _features2025[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_lvresize_free_0 */
  const char *_arg2027 = "/dev/sda";
  int _ret2026;
  _ret2026 = guestfs_blockdev_setrw (g, _arg2027);
  if (_ret2026 == -1)
    return -1;
  int _ret2029;
  _ret2029 = guestfs_umount_all (g);
  if (_ret2029 == -1)
    return -1;
  int _ret2031;
  _ret2031 = guestfs_lvm_remove_all (g);
  if (_ret2031 == -1)
    return -1;

  /* TestRun for lvresize_free (0) */
  const char *_arg2034 = "/dev/sda";
  const char *_arg2035 = "mbr";
  int _ret2033;
  _ret2033 = guestfs_part_disk (g, _arg2034, _arg2035);
  if (_ret2033 == -1)
    return -1;
  const char *_arg2038 = "/dev/sda1";
  int _ret2037;
  _ret2037 = guestfs_pvcreate (g, _arg2038);
  if (_ret2037 == -1)
    return -1;
  const char *_arg2041 = "VG";
  const char *_arg2042_0 = "/dev/sda1";
  const char *const _arg2042[] = {
    _arg2042_0,
    NULL
  };
  int _ret2040;
  _ret2040 = guestfs_vgcreate (g, _arg2041, (char **) _arg2042);
  if (_ret2040 == -1)
    return -1;
  const char *_arg2045 = "LV";
  const char *_arg2046 = "VG";
  int _ret2044;
  _ret2044 = guestfs_lvcreate (g, _arg2045, _arg2046, 10);
  if (_ret2044 == -1)
    return -1;
  const char *_arg2050 = "/dev/VG/LV";
  int _ret2049;
  _ret2049 = guestfs_lvresize_free (g, _arg2050, 100);
  if (_ret2049 == -1)
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
test_checksum_device_0 (void)
{
  if (test_checksum_device_0_skip ()) {
    skipped ("test_checksum_device_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_checksum_device_0 */
  const char *_arg2054 = "/dev/sda";
  int _ret2053;
  _ret2053 = guestfs_blockdev_setrw (g, _arg2054);
  if (_ret2053 == -1)
    return -1;
  int _ret2056;
  _ret2056 = guestfs_umount_all (g);
  if (_ret2056 == -1)
    return -1;
  int _ret2058;
  _ret2058 = guestfs_lvm_remove_all (g);
  if (_ret2058 == -1)
    return -1;
  const char *_arg2061 = "/dev/sdd";
  const char *_arg2062 = "/";
  int _ret2060;
  _ret2060 = guestfs_mount_ro (g, _arg2061, _arg2062);
  if (_ret2060 == -1)
    return -1;

  /* TestResult for checksum_device (0) */
  const char *_arg2064 = "md5";
  const char *_arg2065 = "/dev/sdd";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum_device (g, _arg2064, _arg2065);
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
test_part_get_mbr_id_0 (void)
{
  if (test_part_get_mbr_id_0_skip ()) {
    skipped ("test_part_get_mbr_id_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_get_mbr_id_0 */
  const char *_arg2068 = "/dev/sda";
  int _ret2067;
  _ret2067 = guestfs_blockdev_setrw (g, _arg2068);
  if (_ret2067 == -1)
    return -1;
  int _ret2070;
  _ret2070 = guestfs_umount_all (g);
  if (_ret2070 == -1)
    return -1;
  int _ret2072;
  _ret2072 = guestfs_lvm_remove_all (g);
  if (_ret2072 == -1)
    return -1;

  /* TestResult for part_get_mbr_id (0) */
  const char *_arg2074 = "/dev/sda";
  const char *_arg2075 = "mbr";
  int ret3;
  ret3 = guestfs_part_init (g, _arg2074, _arg2075);
  if (ret3 == -1)
    return -1;
  const char *_arg2077 = "/dev/sda";
  const char *_arg2078 = "primary";
  int ret2;
  ret2 = guestfs_part_add (g, _arg2077, _arg2078, 1, -1);
  if (ret2 == -1)
    return -1;
  const char *_arg2082 = "/dev/sda";
  int ret1;
  ret1 = guestfs_part_set_mbr_id (g, _arg2082, 1, 127);
  if (ret1 == -1)
    return -1;
  const char *_arg2086 = "/dev/sda";
  int ret;
  ret = guestfs_part_get_mbr_id (g, _arg2086, 1);
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
test_part_get_bootable_0 (void)
{
  if (test_part_get_bootable_0_skip ()) {
    skipped ("test_part_get_bootable_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_get_bootable_0 */
  const char *_arg2090 = "/dev/sda";
  int _ret2089;
  _ret2089 = guestfs_blockdev_setrw (g, _arg2090);
  if (_ret2089 == -1)
    return -1;
  int _ret2092;
  _ret2092 = guestfs_umount_all (g);
  if (_ret2092 == -1)
    return -1;
  int _ret2094;
  _ret2094 = guestfs_lvm_remove_all (g);
  if (_ret2094 == -1)
    return -1;

  /* TestResultTrue for part_get_bootable (0) */
  const char *_arg2097 = "/dev/sda";
  const char *_arg2098 = "mbr";
  int _ret2096;
  _ret2096 = guestfs_part_init (g, _arg2097, _arg2098);
  if (_ret2096 == -1)
    return -1;
  const char *_arg2101 = "/dev/sda";
  const char *_arg2102 = "primary";
  int _ret2100;
  _ret2100 = guestfs_part_add (g, _arg2101, _arg2102, 1, -1);
  if (_ret2100 == -1)
    return -1;
  const char *_arg2107 = "/dev/sda";
  int _ret2106;
  _ret2106 = guestfs_part_set_bootable (g, _arg2107, 1, 1);
  if (_ret2106 == -1)
    return -1;
  const char *_arg2111 = "/dev/sda";
  int ret;
  ret = guestfs_part_get_bootable (g, _arg2111, 1);
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
test_part_del_0 (void)
{
  if (test_part_del_0_skip ()) {
    skipped ("test_part_del_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_del_0 */
  const char *_arg2115 = "/dev/sda";
  int _ret2114;
  _ret2114 = guestfs_blockdev_setrw (g, _arg2115);
  if (_ret2114 == -1)
    return -1;
  int _ret2117;
  _ret2117 = guestfs_umount_all (g);
  if (_ret2117 == -1)
    return -1;
  int _ret2119;
  _ret2119 = guestfs_lvm_remove_all (g);
  if (_ret2119 == -1)
    return -1;

  /* TestRun for part_del (0) */
  const char *_arg2122 = "/dev/sda";
  const char *_arg2123 = "mbr";
  int _ret2121;
  _ret2121 = guestfs_part_init (g, _arg2122, _arg2123);
  if (_ret2121 == -1)
    return -1;
  const char *_arg2126 = "/dev/sda";
  const char *_arg2127 = "primary";
  int _ret2125;
  _ret2125 = guestfs_part_add (g, _arg2126, _arg2127, 1, -1);
  if (_ret2125 == -1)
    return -1;
  const char *_arg2132 = "/dev/sda";
  int _ret2131;
  _ret2131 = guestfs_part_del (g, _arg2132, 1);
  if (_ret2131 == -1)
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
test_vgscan_0 (void)
{
  if (test_vgscan_0_skip ()) {
    skipped ("test_vgscan_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_vgscan_0 */
  const char *_arg2136 = "/dev/sda";
  int _ret2135;
  _ret2135 = guestfs_blockdev_setrw (g, _arg2136);
  if (_ret2135 == -1)
    return -1;
  int _ret2138;
  _ret2138 = guestfs_umount_all (g);
  if (_ret2138 == -1)
    return -1;
  int _ret2140;
  _ret2140 = guestfs_lvm_remove_all (g);
  if (_ret2140 == -1)
    return -1;

  /* TestRun for vgscan (0) */
  int _ret2142;
  _ret2142 = guestfs_vgscan (g);
  if (_ret2142 == -1)
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
test_txz_in_0 (void)
{
  if (test_txz_in_0_skip ()) {
    skipped ("test_txz_in_0", "environment variable set");
    return 0;
  }

  const char *_features2144[] = { "xz", NULL };
  if (!guestfs_feature_available (g, (char **) _features2144)) {
    skipped ("test_txz_in_0", "group %s not available in daemon",
             _features2144[0]);
    return 0;
  }

  /* InitScratchFS for test_txz_in_0 */
  const char *_arg2146 = "/dev/sda";
  int _ret2145;
  _ret2145 = guestfs_blockdev_setrw (g, _arg2146);
  if (_ret2145 == -1)
    return -1;
  int _ret2148;
  _ret2148 = guestfs_umount_all (g);
  if (_ret2148 == -1)
    return -1;
  int _ret2150;
  _ret2150 = guestfs_lvm_remove_all (g);
  if (_ret2150 == -1)
    return -1;
  const char *_arg2153 = "/dev/sdb1";
  const char *_arg2154 = "/";
  int _ret2152;
  _ret2152 = guestfs_mount (g, _arg2153, _arg2154);
  if (_ret2152 == -1)
    return -1;

  /* TestResultString for txz_in (0) */
  const char *_arg2157 = "/txz_in";
  int _ret2156;
  _ret2156 = guestfs_mkdir (g, _arg2157);
  if (_ret2156 == -1)
    return -1;
  const char *_arg2161 = "/txz_in";
  int _ret2159;
  _ret2159 = guestfs_txz_in (g, "../data/helloworld.tar.xz", _arg2161);
  if (_ret2159 == -1)
    return -1;
  const char *_arg2163 = "/txz_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2163);
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
test_zero_device_0 (void)
{
  if (test_zero_device_0_skip ()) {
    skipped ("test_zero_device_0", "environment variable set");
    return 0;
  }

  /* InitBasicFSonLVM for test_zero_device_0: create ext2 on /dev/VG/LV */
  const char *_arg2166 = "/dev/sda";
  int _ret2165;
  _ret2165 = guestfs_blockdev_setrw (g, _arg2166);
  if (_ret2165 == -1)
    return -1;
  int _ret2168;
  _ret2168 = guestfs_umount_all (g);
  if (_ret2168 == -1)
    return -1;
  int _ret2170;
  _ret2170 = guestfs_lvm_remove_all (g);
  if (_ret2170 == -1)
    return -1;
  const char *_arg2173 = "/dev/sda";
  const char *_arg2174 = "mbr";
  int _ret2172;
  _ret2172 = guestfs_part_disk (g, _arg2173, _arg2174);
  if (_ret2172 == -1)
    return -1;
  const char *_arg2177 = "/dev/sda1";
  int _ret2176;
  _ret2176 = guestfs_pvcreate (g, _arg2177);
  if (_ret2176 == -1)
    return -1;
  const char *_arg2180 = "VG";
  const char *_arg2181_0 = "/dev/sda1";
  const char *const _arg2181[] = {
    _arg2181_0,
    NULL
  };
  int _ret2179;
  _ret2179 = guestfs_vgcreate (g, _arg2180, (char **) _arg2181);
  if (_ret2179 == -1)
    return -1;
  const char *_arg2184 = "LV";
  const char *_arg2185 = "VG";
  int _ret2183;
  _ret2183 = guestfs_lvcreate (g, _arg2184, _arg2185, 8);
  if (_ret2183 == -1)
    return -1;
  const char *_arg2189 = "ext2";
  const char *_arg2190 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs2191;
  _optargs2191.bitmask = UINT64_C(0x0);
  int _ret2188;
  _ret2188 = guestfs_mkfs_opts_argv (g, _arg2189, _arg2190, &_optargs2191);
  if (_ret2188 == -1)
    return -1;
  const char *_arg2193 = "/dev/VG/LV";
  const char *_arg2194 = "/";
  int _ret2192;
  _ret2192 = guestfs_mount (g, _arg2193, _arg2194);
  if (_ret2192 == -1)
    return -1;

  /* TestRun for zero_device (0) */
  const char *_arg2197 = "/dev/VG/LV";
  int _ret2196;
  _ret2196 = guestfs_zero_device (g, _arg2197);
  if (_ret2196 == -1)
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
test_copy_size_0 (void)
{
  if (test_copy_size_0_skip ()) {
    skipped ("test_copy_size_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_copy_size_0 */
  const char *_arg2200 = "/dev/sda";
  int _ret2199;
  _ret2199 = guestfs_blockdev_setrw (g, _arg2200);
  if (_ret2199 == -1)
    return -1;
  int _ret2202;
  _ret2202 = guestfs_umount_all (g);
  if (_ret2202 == -1)
    return -1;
  int _ret2204;
  _ret2204 = guestfs_lvm_remove_all (g);
  if (_ret2204 == -1)
    return -1;
  const char *_arg2207 = "/dev/sdb1";
  const char *_arg2208 = "/";
  int _ret2206;
  _ret2206 = guestfs_mount (g, _arg2207, _arg2208);
  if (_ret2206 == -1)
    return -1;

  /* TestResult for copy_size (0) */
  const char *_arg2210 = "/copy_size";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2210);
  if (ret3 == -1)
    return -1;
  const char *_arg2212 = "/copy_size/src";
  const char *_arg2213 = "hello, world";
  size_t _arg2213_size = 12;
  int ret2;
  ret2 = guestfs_write (g, _arg2212, _arg2213, _arg2213_size);
  if (ret2 == -1)
    return -1;
  const char *_arg2215 = "/copy_size/src";
  const char *_arg2216 = "/copy_size/dest";
  int ret1;
  ret1 = guestfs_copy_size (g, _arg2215, _arg2216, 5);
  if (ret1 == -1)
    return -1;
  const char *_arg2219 = "/copy_size/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg2219, &size);
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
test_initrd_cat_0 (void)
{
  if (test_initrd_cat_0_skip ()) {
    skipped ("test_initrd_cat_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_initrd_cat_0 */
  const char *_arg2222 = "/dev/sda";
  int _ret2221;
  _ret2221 = guestfs_blockdev_setrw (g, _arg2222);
  if (_ret2221 == -1)
    return -1;
  int _ret2224;
  _ret2224 = guestfs_umount_all (g);
  if (_ret2224 == -1)
    return -1;
  int _ret2226;
  _ret2226 = guestfs_lvm_remove_all (g);
  if (_ret2226 == -1)
    return -1;
  const char *_arg2229 = "/dev/sdd";
  const char *_arg2230 = "/";
  int _ret2228;
  _ret2228 = guestfs_mount_ro (g, _arg2229, _arg2230);
  if (_ret2228 == -1)
    return -1;

  /* TestResult for initrd_cat (0) */
  const char *_arg2232 = "/initrd";
  const char *_arg2233 = "known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_initrd_cat (g, _arg2232, _arg2233, &size);
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
test_vgrename_0 (void)
{
  if (test_vgrename_0_skip ()) {
    skipped ("test_vgrename_0", "environment variable set");
    return 0;
  }

  /* InitBasicFSonLVM for test_vgrename_0: create ext2 on /dev/VG/LV */
  const char *_arg2236 = "/dev/sda";
  int _ret2235;
  _ret2235 = guestfs_blockdev_setrw (g, _arg2236);
  if (_ret2235 == -1)
    return -1;
  int _ret2238;
  _ret2238 = guestfs_umount_all (g);
  if (_ret2238 == -1)
    return -1;
  int _ret2240;
  _ret2240 = guestfs_lvm_remove_all (g);
  if (_ret2240 == -1)
    return -1;
  const char *_arg2243 = "/dev/sda";
  const char *_arg2244 = "mbr";
  int _ret2242;
  _ret2242 = guestfs_part_disk (g, _arg2243, _arg2244);
  if (_ret2242 == -1)
    return -1;
  const char *_arg2247 = "/dev/sda1";
  int _ret2246;
  _ret2246 = guestfs_pvcreate (g, _arg2247);
  if (_ret2246 == -1)
    return -1;
  const char *_arg2250 = "VG";
  const char *_arg2251_0 = "/dev/sda1";
  const char *const _arg2251[] = {
    _arg2251_0,
    NULL
  };
  int _ret2249;
  _ret2249 = guestfs_vgcreate (g, _arg2250, (char **) _arg2251);
  if (_ret2249 == -1)
    return -1;
  const char *_arg2254 = "LV";
  const char *_arg2255 = "VG";
  int _ret2253;
  _ret2253 = guestfs_lvcreate (g, _arg2254, _arg2255, 8);
  if (_ret2253 == -1)
    return -1;
  const char *_arg2259 = "ext2";
  const char *_arg2260 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs2261;
  _optargs2261.bitmask = UINT64_C(0x0);
  int _ret2258;
  _ret2258 = guestfs_mkfs_opts_argv (g, _arg2259, _arg2260, &_optargs2261);
  if (_ret2258 == -1)
    return -1;
  const char *_arg2263 = "/dev/VG/LV";
  const char *_arg2264 = "/";
  int _ret2262;
  _ret2262 = guestfs_mount (g, _arg2263, _arg2264);
  if (_ret2262 == -1)
    return -1;

  /* TestResult for vgrename (0) */
  const char *_arg2266 = "/";
  struct guestfs_umount_opts_argv _optargs2267;
  _optargs2267.force = 0;
  _optargs2267.lazyunmount = 0;
  _optargs2267.bitmask = UINT64_C(0x3);
  int ret5;
  ret5 = guestfs_umount_opts_argv (g, _arg2266, &_optargs2267);
  if (ret5 == -1)
    return -1;
  const char *_arg2269_0 = "VG";
  const char *const _arg2269[] = {
    _arg2269_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vg_activate (g, 0, (char **) _arg2269);
  if (ret4 == -1)
    return -1;
  const char *_arg2271 = "VG";
  const char *_arg2272 = "VG2";
  int ret3;
  ret3 = guestfs_vgrename (g, _arg2271, _arg2272);
  if (ret3 == -1)
    return -1;
  const char *_arg2275_0 = "VG2";
  const char *const _arg2275[] = {
    _arg2275_0,
    NULL
  };
  int ret2;
  ret2 = guestfs_vg_activate (g, 1, (char **) _arg2275);
  if (ret2 == -1)
    return -1;
  const char *_arg2277 = "/dev/VG2/LV";
  const char *_arg2278 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg2277, _arg2278);
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
test_lvrename_0 (void)
{
  if (test_lvrename_0_skip ()) {
    skipped ("test_lvrename_0", "environment variable set");
    return 0;
  }

  /* InitBasicFSonLVM for test_lvrename_0: create ext2 on /dev/VG/LV */
  const char *_arg2282 = "/dev/sda";
  int _ret2281;
  _ret2281 = guestfs_blockdev_setrw (g, _arg2282);
  if (_ret2281 == -1)
    return -1;
  int _ret2284;
  _ret2284 = guestfs_umount_all (g);
  if (_ret2284 == -1)
    return -1;
  int _ret2286;
  _ret2286 = guestfs_lvm_remove_all (g);
  if (_ret2286 == -1)
    return -1;
  const char *_arg2289 = "/dev/sda";
  const char *_arg2290 = "mbr";
  int _ret2288;
  _ret2288 = guestfs_part_disk (g, _arg2289, _arg2290);
  if (_ret2288 == -1)
    return -1;
  const char *_arg2293 = "/dev/sda1";
  int _ret2292;
  _ret2292 = guestfs_pvcreate (g, _arg2293);
  if (_ret2292 == -1)
    return -1;
  const char *_arg2296 = "VG";
  const char *_arg2297_0 = "/dev/sda1";
  const char *const _arg2297[] = {
    _arg2297_0,
    NULL
  };
  int _ret2295;
  _ret2295 = guestfs_vgcreate (g, _arg2296, (char **) _arg2297);
  if (_ret2295 == -1)
    return -1;
  const char *_arg2300 = "LV";
  const char *_arg2301 = "VG";
  int _ret2299;
  _ret2299 = guestfs_lvcreate (g, _arg2300, _arg2301, 8);
  if (_ret2299 == -1)
    return -1;
  const char *_arg2305 = "ext2";
  const char *_arg2306 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs2307;
  _optargs2307.bitmask = UINT64_C(0x0);
  int _ret2304;
  _ret2304 = guestfs_mkfs_opts_argv (g, _arg2305, _arg2306, &_optargs2307);
  if (_ret2304 == -1)
    return -1;
  const char *_arg2309 = "/dev/VG/LV";
  const char *_arg2310 = "/";
  int _ret2308;
  _ret2308 = guestfs_mount (g, _arg2309, _arg2310);
  if (_ret2308 == -1)
    return -1;

  /* TestResult for lvrename (0) */
  const char *_arg2312 = "/dev/VG/LV";
  const char *_arg2313 = "/dev/VG/LV2";
  int ret1;
  ret1 = guestfs_lvrename (g, _arg2312, _arg2313);
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
test_filesize_0 (void)
{
  if (test_filesize_0_skip ()) {
    skipped ("test_filesize_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_filesize_0 */
  const char *_arg2317 = "/dev/sda";
  int _ret2316;
  _ret2316 = guestfs_blockdev_setrw (g, _arg2317);
  if (_ret2316 == -1)
    return -1;
  int _ret2319;
  _ret2319 = guestfs_umount_all (g);
  if (_ret2319 == -1)
    return -1;
  int _ret2321;
  _ret2321 = guestfs_lvm_remove_all (g);
  if (_ret2321 == -1)
    return -1;
  const char *_arg2324 = "/dev/sdb1";
  const char *_arg2325 = "/";
  int _ret2323;
  _ret2323 = guestfs_mount (g, _arg2324, _arg2325);
  if (_ret2323 == -1)
    return -1;

  /* TestResult for filesize (0) */
  const char *_arg2327 = "/filesize";
  const char *_arg2328 = "hello, world";
  size_t _arg2328_size = 12;
  int ret1;
  ret1 = guestfs_write (g, _arg2327, _arg2328, _arg2328_size);
  if (ret1 == -1)
    return -1;
  const char *_arg2330 = "/filesize";
  int64_t ret;
  ret = guestfs_filesize (g, _arg2330);
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
test_dd_0 (void)
{
  if (test_dd_0_skip ()) {
    skipped ("test_dd_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_dd_0 */
  const char *_arg2333 = "/dev/sda";
  int _ret2332;
  _ret2332 = guestfs_blockdev_setrw (g, _arg2333);
  if (_ret2332 == -1)
    return -1;
  int _ret2335;
  _ret2335 = guestfs_umount_all (g);
  if (_ret2335 == -1)
    return -1;
  int _ret2337;
  _ret2337 = guestfs_lvm_remove_all (g);
  if (_ret2337 == -1)
    return -1;
  const char *_arg2340 = "/dev/sdb1";
  const char *_arg2341 = "/";
  int _ret2339;
  _ret2339 = guestfs_mount (g, _arg2340, _arg2341);
  if (_ret2339 == -1)
    return -1;

  /* TestResult for dd (0) */
  const char *_arg2343 = "/dd";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg2343);
  if (ret3 == -1)
    return -1;
  const char *_arg2345 = "/dd/src";
  const char *_arg2346 = "hello, world";
  size_t _arg2346_size = 12;
  int ret2;
  ret2 = guestfs_write (g, _arg2345, _arg2346, _arg2346_size);
  if (ret2 == -1)
    return -1;
  const char *_arg2348 = "/dd/src";
  const char *_arg2349 = "/dd/dest";
  int ret1;
  ret1 = guestfs_dd (g, _arg2348, _arg2349);
  if (ret1 == -1)
    return -1;
  const char *_arg2351 = "/dd/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg2351, &size);
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
test_available_0 (void)
{
  if (test_available_0_skip ()) {
    skipped ("test_available_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_available_0 */
  const char *_arg2354 = "/dev/sda";
  int _ret2353;
  _ret2353 = guestfs_blockdev_setrw (g, _arg2354);
  if (_ret2353 == -1)
    return -1;
  int _ret2356;
  _ret2356 = guestfs_umount_all (g);
  if (_ret2356 == -1)
    return -1;
  int _ret2358;
  _ret2358 = guestfs_lvm_remove_all (g);
  if (_ret2358 == -1)
    return -1;

  /* TestRun for available (0) */
  const char *const _arg2361[1] = { NULL };
  int _ret2360;
  _ret2360 = guestfs_available (g, (char **) _arg2361);
  if (_ret2360 == -1)
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
test_fill_0 (void)
{
  if (test_fill_0_skip ()) {
    skipped ("test_fill_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_fill_0 */
  const char *_arg2364 = "/dev/sda";
  int _ret2363;
  _ret2363 = guestfs_blockdev_setrw (g, _arg2364);
  if (_ret2363 == -1)
    return -1;
  int _ret2366;
  _ret2366 = guestfs_umount_all (g);
  if (_ret2366 == -1)
    return -1;
  int _ret2368;
  _ret2368 = guestfs_lvm_remove_all (g);
  if (_ret2368 == -1)
    return -1;
  const char *_arg2371 = "/dev/sdb1";
  const char *_arg2372 = "/";
  int _ret2370;
  _ret2370 = guestfs_mount (g, _arg2371, _arg2372);
  if (_ret2370 == -1)
    return -1;

  /* TestResult for fill (0) */
  const char *_arg2376 = "/fill";
  int ret1;
  ret1 = guestfs_fill (g, 99, 10, _arg2376);
  if (ret1 == -1)
    return -1;
  const char *_arg2378 = "/fill";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg2378, &size);
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
test_part_get_parttype_0 (void)
{
  if (test_part_get_parttype_0_skip ()) {
    skipped ("test_part_get_parttype_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_get_parttype_0 */
  const char *_arg2381 = "/dev/sda";
  int _ret2380;
  _ret2380 = guestfs_blockdev_setrw (g, _arg2381);
  if (_ret2380 == -1)
    return -1;
  int _ret2383;
  _ret2383 = guestfs_umount_all (g);
  if (_ret2383 == -1)
    return -1;
  int _ret2385;
  _ret2385 = guestfs_lvm_remove_all (g);
  if (_ret2385 == -1)
    return -1;

  /* TestResultString for part_get_parttype (0) */
  const char *_arg2388 = "/dev/sda";
  const char *_arg2389 = "gpt";
  int _ret2387;
  _ret2387 = guestfs_part_disk (g, _arg2388, _arg2389);
  if (_ret2387 == -1)
    return -1;
  const char *_arg2391 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_parttype (g, _arg2391);
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
test_part_set_name_0 (void)
{
  if (test_part_set_name_0_skip ()) {
    skipped ("test_part_set_name_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_set_name_0 */
  const char *_arg2394 = "/dev/sda";
  int _ret2393;
  _ret2393 = guestfs_blockdev_setrw (g, _arg2394);
  if (_ret2393 == -1)
    return -1;
  int _ret2396;
  _ret2396 = guestfs_umount_all (g);
  if (_ret2396 == -1)
    return -1;
  int _ret2398;
  _ret2398 = guestfs_lvm_remove_all (g);
  if (_ret2398 == -1)
    return -1;

  /* TestRun for part_set_name (0) */
  const char *_arg2401 = "/dev/sda";
  const char *_arg2402 = "gpt";
  int _ret2400;
  _ret2400 = guestfs_part_disk (g, _arg2401, _arg2402);
  if (_ret2400 == -1)
    return -1;
  const char *_arg2405 = "/dev/sda";
  const char *_arg2407 = "thepartname";
  int _ret2404;
  _ret2404 = guestfs_part_set_name (g, _arg2405, 1, _arg2407);
  if (_ret2404 == -1)
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
test_part_set_bootable_0 (void)
{
  if (test_part_set_bootable_0_skip ()) {
    skipped ("test_part_set_bootable_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_set_bootable_0 */
  const char *_arg2410 = "/dev/sda";
  int _ret2409;
  _ret2409 = guestfs_blockdev_setrw (g, _arg2410);
  if (_ret2409 == -1)
    return -1;
  int _ret2412;
  _ret2412 = guestfs_umount_all (g);
  if (_ret2412 == -1)
    return -1;
  int _ret2414;
  _ret2414 = guestfs_lvm_remove_all (g);
  if (_ret2414 == -1)
    return -1;

  /* TestRun for part_set_bootable (0) */
  const char *_arg2417 = "/dev/sda";
  const char *_arg2418 = "mbr";
  int _ret2416;
  _ret2416 = guestfs_part_disk (g, _arg2417, _arg2418);
  if (_ret2416 == -1)
    return -1;
  const char *_arg2421 = "/dev/sda";
  int _ret2420;
  _ret2420 = guestfs_part_set_bootable (g, _arg2421, 1, 1);
  if (_ret2420 == -1)
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
test_part_disk_0 (void)
{
  if (test_part_disk_0_skip ()) {
    skipped ("test_part_disk_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_disk_0 */
  const char *_arg2426 = "/dev/sda";
  int _ret2425;
  _ret2425 = guestfs_blockdev_setrw (g, _arg2426);
  if (_ret2425 == -1)
    return -1;
  int _ret2428;
  _ret2428 = guestfs_umount_all (g);
  if (_ret2428 == -1)
    return -1;
  int _ret2430;
  _ret2430 = guestfs_lvm_remove_all (g);
  if (_ret2430 == -1)
    return -1;

  /* TestRun for part_disk (0) */
  const char *_arg2433 = "/dev/sda";
  const char *_arg2434 = "mbr";
  int _ret2432;
  _ret2432 = guestfs_part_disk (g, _arg2433, _arg2434);
  if (_ret2432 == -1)
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
test_part_disk_1 (void)
{
  if (test_part_disk_1_skip ()) {
    skipped ("test_part_disk_1", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_disk_1 */
  const char *_arg2437 = "/dev/sda";
  int _ret2436;
  _ret2436 = guestfs_blockdev_setrw (g, _arg2437);
  if (_ret2436 == -1)
    return -1;
  int _ret2439;
  _ret2439 = guestfs_umount_all (g);
  if (_ret2439 == -1)
    return -1;
  int _ret2441;
  _ret2441 = guestfs_lvm_remove_all (g);
  if (_ret2441 == -1)
    return -1;

  /* TestRun for part_disk (1) */
  const char *_arg2444 = "/dev/sda";
  const char *_arg2445 = "gpt";
  int _ret2443;
  _ret2443 = guestfs_part_disk (g, _arg2444, _arg2445);
  if (_ret2443 == -1)
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
test_part_add_0 (void)
{
  if (test_part_add_0_skip ()) {
    skipped ("test_part_add_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_add_0 */
  const char *_arg2448 = "/dev/sda";
  int _ret2447;
  _ret2447 = guestfs_blockdev_setrw (g, _arg2448);
  if (_ret2447 == -1)
    return -1;
  int _ret2450;
  _ret2450 = guestfs_umount_all (g);
  if (_ret2450 == -1)
    return -1;
  int _ret2452;
  _ret2452 = guestfs_lvm_remove_all (g);
  if (_ret2452 == -1)
    return -1;

  /* TestRun for part_add (0) */
  const char *_arg2455 = "/dev/sda";
  const char *_arg2456 = "mbr";
  int _ret2454;
  _ret2454 = guestfs_part_init (g, _arg2455, _arg2456);
  if (_ret2454 == -1)
    return -1;
  const char *_arg2459 = "/dev/sda";
  const char *_arg2460 = "primary";
  int _ret2458;
  _ret2458 = guestfs_part_add (g, _arg2459, _arg2460, 1, -1);
  if (_ret2458 == -1)
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
test_part_add_1 (void)
{
  if (test_part_add_1_skip ()) {
    skipped ("test_part_add_1", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_add_1 */
  const char *_arg2465 = "/dev/sda";
  int _ret2464;
  _ret2464 = guestfs_blockdev_setrw (g, _arg2465);
  if (_ret2464 == -1)
    return -1;
  int _ret2467;
  _ret2467 = guestfs_umount_all (g);
  if (_ret2467 == -1)
    return -1;
  int _ret2469;
  _ret2469 = guestfs_lvm_remove_all (g);
  if (_ret2469 == -1)
    return -1;

  /* TestRun for part_add (1) */
  const char *_arg2472 = "/dev/sda";
  const char *_arg2473 = "gpt";
  int _ret2471;
  _ret2471 = guestfs_part_init (g, _arg2472, _arg2473);
  if (_ret2471 == -1)
    return -1;
  const char *_arg2476 = "/dev/sda";
  const char *_arg2477 = "primary";
  int _ret2475;
  _ret2475 = guestfs_part_add (g, _arg2476, _arg2477, 34, 127);
  if (_ret2475 == -1)
    return -1;
  const char *_arg2482 = "/dev/sda";
  const char *_arg2483 = "primary";
  int _ret2481;
  _ret2481 = guestfs_part_add (g, _arg2482, _arg2483, 128, -34);
  if (_ret2481 == -1)
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
test_part_add_2 (void)
{
  if (test_part_add_2_skip ()) {
    skipped ("test_part_add_2", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_add_2 */
  const char *_arg2488 = "/dev/sda";
  int _ret2487;
  _ret2487 = guestfs_blockdev_setrw (g, _arg2488);
  if (_ret2487 == -1)
    return -1;
  int _ret2490;
  _ret2490 = guestfs_umount_all (g);
  if (_ret2490 == -1)
    return -1;
  int _ret2492;
  _ret2492 = guestfs_lvm_remove_all (g);
  if (_ret2492 == -1)
    return -1;

  /* TestRun for part_add (2) */
  const char *_arg2495 = "/dev/sda";
  const char *_arg2496 = "mbr";
  int _ret2494;
  _ret2494 = guestfs_part_init (g, _arg2495, _arg2496);
  if (_ret2494 == -1)
    return -1;
  const char *_arg2499 = "/dev/sda";
  const char *_arg2500 = "primary";
  int _ret2498;
  _ret2498 = guestfs_part_add (g, _arg2499, _arg2500, 32, 127);
  if (_ret2498 == -1)
    return -1;
  const char *_arg2505 = "/dev/sda";
  const char *_arg2506 = "primary";
  int _ret2504;
  _ret2504 = guestfs_part_add (g, _arg2505, _arg2506, 128, 255);
  if (_ret2504 == -1)
    return -1;
  const char *_arg2511 = "/dev/sda";
  const char *_arg2512 = "primary";
  int _ret2510;
  _ret2510 = guestfs_part_add (g, _arg2511, _arg2512, 256, 511);
  if (_ret2510 == -1)
    return -1;
  const char *_arg2517 = "/dev/sda";
  const char *_arg2518 = "primary";
  int _ret2516;
  _ret2516 = guestfs_part_add (g, _arg2517, _arg2518, 512, -1);
  if (_ret2516 == -1)
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
test_part_init_0 (void)
{
  if (test_part_init_0_skip ()) {
    skipped ("test_part_init_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_init_0 */
  const char *_arg2523 = "/dev/sda";
  int _ret2522;
  _ret2522 = guestfs_blockdev_setrw (g, _arg2523);
  if (_ret2522 == -1)
    return -1;
  int _ret2525;
  _ret2525 = guestfs_umount_all (g);
  if (_ret2525 == -1)
    return -1;
  int _ret2527;
  _ret2527 = guestfs_lvm_remove_all (g);
  if (_ret2527 == -1)
    return -1;

  /* TestRun for part_init (0) */
  const char *_arg2530 = "/dev/sda";
  const char *_arg2531 = "gpt";
  int _ret2529;
  _ret2529 = guestfs_part_init (g, _arg2530, _arg2531);
  if (_ret2529 == -1)
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
test_pread_0 (void)
{
  if (test_pread_0_skip ()) {
    skipped ("test_pread_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_pread_0 */
  const char *_arg2534 = "/dev/sda";
  int _ret2533;
  _ret2533 = guestfs_blockdev_setrw (g, _arg2534);
  if (_ret2533 == -1)
    return -1;
  int _ret2536;
  _ret2536 = guestfs_umount_all (g);
  if (_ret2536 == -1)
    return -1;
  int _ret2538;
  _ret2538 = guestfs_lvm_remove_all (g);
  if (_ret2538 == -1)
    return -1;
  const char *_arg2541 = "/dev/sdd";
  const char *_arg2542 = "/";
  int _ret2540;
  _ret2540 = guestfs_mount_ro (g, _arg2541, _arg2542);
  if (_ret2540 == -1)
    return -1;

  /* TestResult for pread (0) */
  const char *_arg2544 = "/known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread (g, _arg2544, 1, 3, &size);
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
test_pread_1 (void)
{
  if (test_pread_1_skip ()) {
    skipped ("test_pread_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_pread_1 */
  const char *_arg2549 = "/dev/sda";
  int _ret2548;
  _ret2548 = guestfs_blockdev_setrw (g, _arg2549);
  if (_ret2548 == -1)
    return -1;
  int _ret2551;
  _ret2551 = guestfs_umount_all (g);
  if (_ret2551 == -1)
    return -1;
  int _ret2553;
  _ret2553 = guestfs_lvm_remove_all (g);
  if (_ret2553 == -1)
    return -1;
  const char *_arg2556 = "/dev/sdd";
  const char *_arg2557 = "/";
  int _ret2555;
  _ret2555 = guestfs_mount_ro (g, _arg2556, _arg2557);
  if (_ret2555 == -1)
    return -1;

  /* TestResult for pread (1) */
  const char *_arg2559 = "/empty";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread (g, _arg2559, 0, 100, &size);
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
test_mkdir_mode_0 (void)
{
  if (test_mkdir_mode_0_skip ()) {
    skipped ("test_mkdir_mode_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mkdir_mode_0 */
  const char *_arg2564 = "/dev/sda";
  int _ret2563;
  _ret2563 = guestfs_blockdev_setrw (g, _arg2564);
  if (_ret2563 == -1)
    return -1;
  int _ret2566;
  _ret2566 = guestfs_umount_all (g);
  if (_ret2566 == -1)
    return -1;
  int _ret2568;
  _ret2568 = guestfs_lvm_remove_all (g);
  if (_ret2568 == -1)
    return -1;
  const char *_arg2571 = "/dev/sdb1";
  const char *_arg2572 = "/";
  int _ret2570;
  _ret2570 = guestfs_mount (g, _arg2571, _arg2572);
  if (_ret2570 == -1)
    return -1;

  /* TestResult for mkdir_mode (0) */
  const char *_arg2574 = "/mkdir_mode";
  int ret1;
  ret1 = guestfs_mkdir_mode (g, _arg2574, 73);
  if (ret1 == -1)
    return -1;
  const char *_arg2577 = "/mkdir_mode";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg2577);
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
test_utimens_0 (void)
{
  if (test_utimens_0_skip ()) {
    skipped ("test_utimens_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_utimens_0 */
  const char *_arg2580 = "/dev/sda";
  int _ret2579;
  _ret2579 = guestfs_blockdev_setrw (g, _arg2580);
  if (_ret2579 == -1)
    return -1;
  int _ret2582;
  _ret2582 = guestfs_umount_all (g);
  if (_ret2582 == -1)
    return -1;
  int _ret2584;
  _ret2584 = guestfs_lvm_remove_all (g);
  if (_ret2584 == -1)
    return -1;
  const char *_arg2587 = "/dev/sdb1";
  const char *_arg2588 = "/";
  int _ret2586;
  _ret2586 = guestfs_mount (g, _arg2587, _arg2588);
  if (_ret2586 == -1)
    return -1;

  /* TestResult for utimens (0) */
  const char *_arg2590 = "/utimens-file";
  int ret2;
  ret2 = guestfs_touch (g, _arg2590);
  if (ret2 == -1)
    return -1;
  const char *_arg2592 = "/utimens-file";
  int ret1;
  ret1 = guestfs_utimens (g, _arg2592, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg2598 = "/utimens-file";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg2598);
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
test_utimens_1 (void)
{
  if (test_utimens_1_skip ()) {
    skipped ("test_utimens_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_utimens_1 */
  const char *_arg2601 = "/dev/sda";
  int _ret2600;
  _ret2600 = guestfs_blockdev_setrw (g, _arg2601);
  if (_ret2600 == -1)
    return -1;
  int _ret2603;
  _ret2603 = guestfs_umount_all (g);
  if (_ret2603 == -1)
    return -1;
  int _ret2605;
  _ret2605 = guestfs_lvm_remove_all (g);
  if (_ret2605 == -1)
    return -1;
  const char *_arg2608 = "/dev/sdb1";
  const char *_arg2609 = "/";
  int _ret2607;
  _ret2607 = guestfs_mount (g, _arg2608, _arg2609);
  if (_ret2607 == -1)
    return -1;

  /* TestResult for utimens (1) */
  const char *_arg2611 = "/utimens-dir";
  int ret2;
  ret2 = guestfs_mkdir (g, _arg2611);
  if (ret2 == -1)
    return -1;
  const char *_arg2613 = "/utimens-dir";
  int ret1;
  ret1 = guestfs_utimens (g, _arg2613, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg2619 = "/utimens-dir";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg2619);
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
test_utimens_2 (void)
{
  if (test_utimens_2_skip ()) {
    skipped ("test_utimens_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_utimens_2 */
  const char *_arg2622 = "/dev/sda";
  int _ret2621;
  _ret2621 = guestfs_blockdev_setrw (g, _arg2622);
  if (_ret2621 == -1)
    return -1;
  int _ret2624;
  _ret2624 = guestfs_umount_all (g);
  if (_ret2624 == -1)
    return -1;
  int _ret2626;
  _ret2626 = guestfs_lvm_remove_all (g);
  if (_ret2626 == -1)
    return -1;
  const char *_arg2629 = "/dev/sdb1";
  const char *_arg2630 = "/";
  int _ret2628;
  _ret2628 = guestfs_mount (g, _arg2629, _arg2630);
  if (_ret2628 == -1)
    return -1;

  /* TestResult for utimens (2) */
  const char *_arg2633 = "/utimens-fifo";
  int ret2;
  ret2 = guestfs_mkfifo (g, 420, _arg2633);
  if (ret2 == -1)
    return -1;
  const char *_arg2635 = "/utimens-fifo";
  int ret1;
  ret1 = guestfs_utimens (g, _arg2635, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg2641 = "/utimens-fifo";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg2641);
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
test_utimens_3 (void)
{
  if (test_utimens_3_skip ()) {
    skipped ("test_utimens_3", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_utimens_3 */
  const char *_arg2644 = "/dev/sda";
  int _ret2643;
  _ret2643 = guestfs_blockdev_setrw (g, _arg2644);
  if (_ret2643 == -1)
    return -1;
  int _ret2646;
  _ret2646 = guestfs_umount_all (g);
  if (_ret2646 == -1)
    return -1;
  int _ret2648;
  _ret2648 = guestfs_lvm_remove_all (g);
  if (_ret2648 == -1)
    return -1;
  const char *_arg2651 = "/dev/sdb1";
  const char *_arg2652 = "/";
  int _ret2650;
  _ret2650 = guestfs_mount (g, _arg2651, _arg2652);
  if (_ret2650 == -1)
    return -1;

  /* TestResult for utimens (3) */
  const char *_arg2654 = "/utimens-file";
  const char *_arg2655 = "/utimens-link";
  int ret2;
  ret2 = guestfs_ln_sf (g, _arg2654, _arg2655);
  if (ret2 == -1)
    return -1;
  const char *_arg2657 = "/utimens-link";
  int ret1;
  ret1 = guestfs_utimens (g, _arg2657, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg2663 = "/utimens-link";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg2663);
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
test_utimens_4 (void)
{
  if (test_utimens_4_skip ()) {
    skipped ("test_utimens_4", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_utimens_4 */
  const char *_arg2666 = "/dev/sda";
  int _ret2665;
  _ret2665 = guestfs_blockdev_setrw (g, _arg2666);
  if (_ret2665 == -1)
    return -1;
  int _ret2668;
  _ret2668 = guestfs_umount_all (g);
  if (_ret2668 == -1)
    return -1;
  int _ret2670;
  _ret2670 = guestfs_lvm_remove_all (g);
  if (_ret2670 == -1)
    return -1;
  const char *_arg2673 = "/dev/sdb1";
  const char *_arg2674 = "/";
  int _ret2672;
  _ret2672 = guestfs_mount (g, _arg2673, _arg2674);
  if (_ret2672 == -1)
    return -1;

  /* TestResult for utimens (4) */
  const char *_arg2679 = "/utimens-block";
  int ret2;
  ret2 = guestfs_mknod_b (g, 420, 8, 0, _arg2679);
  if (ret2 == -1)
    return -1;
  const char *_arg2681 = "/utimens-block";
  int ret1;
  ret1 = guestfs_utimens (g, _arg2681, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg2687 = "/utimens-block";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg2687);
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
test_utimens_5 (void)
{
  if (test_utimens_5_skip ()) {
    skipped ("test_utimens_5", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_utimens_5 */
  const char *_arg2690 = "/dev/sda";
  int _ret2689;
  _ret2689 = guestfs_blockdev_setrw (g, _arg2690);
  if (_ret2689 == -1)
    return -1;
  int _ret2692;
  _ret2692 = guestfs_umount_all (g);
  if (_ret2692 == -1)
    return -1;
  int _ret2694;
  _ret2694 = guestfs_lvm_remove_all (g);
  if (_ret2694 == -1)
    return -1;
  const char *_arg2697 = "/dev/sdb1";
  const char *_arg2698 = "/";
  int _ret2696;
  _ret2696 = guestfs_mount (g, _arg2697, _arg2698);
  if (_ret2696 == -1)
    return -1;

  /* TestResult for utimens (5) */
  const char *_arg2703 = "/utimens-char";
  int ret2;
  ret2 = guestfs_mknod_c (g, 420, 1, 3, _arg2703);
  if (ret2 == -1)
    return -1;
  const char *_arg2705 = "/utimens-char";
  int ret1;
  ret1 = guestfs_utimens (g, _arg2705, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *_arg2711 = "/utimens-char";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg2711);
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
test_truncate_size_0 (void)
{
  if (test_truncate_size_0_skip ()) {
    skipped ("test_truncate_size_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_truncate_size_0 */
  const char *_arg2714 = "/dev/sda";
  int _ret2713;
  _ret2713 = guestfs_blockdev_setrw (g, _arg2714);
  if (_ret2713 == -1)
    return -1;
  int _ret2716;
  _ret2716 = guestfs_umount_all (g);
  if (_ret2716 == -1)
    return -1;
  int _ret2718;
  _ret2718 = guestfs_lvm_remove_all (g);
  if (_ret2718 == -1)
    return -1;
  const char *_arg2721 = "/dev/sdb1";
  const char *_arg2722 = "/";
  int _ret2720;
  _ret2720 = guestfs_mount (g, _arg2721, _arg2722);
  if (_ret2720 == -1)
    return -1;

  /* TestResult for truncate_size (0) */
  const char *_arg2724 = "/truncate_size";
  int ret2;
  ret2 = guestfs_touch (g, _arg2724);
  if (ret2 == -1)
    return -1;
  const char *_arg2726 = "/truncate_size";
  int ret1;
  ret1 = guestfs_truncate_size (g, _arg2726, 1000);
  if (ret1 == -1)
    return -1;
  const char *_arg2729 = "/truncate_size";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg2729);
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
test_truncate_0 (void)
{
  if (test_truncate_0_skip ()) {
    skipped ("test_truncate_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_truncate_0 */
  const char *_arg2732 = "/dev/sda";
  int _ret2731;
  _ret2731 = guestfs_blockdev_setrw (g, _arg2732);
  if (_ret2731 == -1)
    return -1;
  int _ret2734;
  _ret2734 = guestfs_umount_all (g);
  if (_ret2734 == -1)
    return -1;
  int _ret2736;
  _ret2736 = guestfs_lvm_remove_all (g);
  if (_ret2736 == -1)
    return -1;
  const char *_arg2739 = "/dev/sdb1";
  const char *_arg2740 = "/";
  int _ret2738;
  _ret2738 = guestfs_mount (g, _arg2739, _arg2740);
  if (_ret2738 == -1)
    return -1;

  /* TestResult for truncate (0) */
  const char *_arg2742 = "/truncate";
  const char *_arg2743 = "some stuff so size is not zero";
  size_t _arg2743_size = 30;
  int ret2;
  ret2 = guestfs_write (g, _arg2742, _arg2743, _arg2743_size);
  if (ret2 == -1)
    return -1;
  const char *_arg2745 = "/truncate";
  int ret1;
  ret1 = guestfs_truncate (g, _arg2745);
  if (ret1 == -1)
    return -1;
  const char *_arg2747 = "/truncate";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg2747);
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
test_vfs_type_0 (void)
{
  if (test_vfs_type_0_skip ()) {
    skipped ("test_vfs_type_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_vfs_type_0 */
  const char *_arg2750 = "/dev/sda";
  int _ret2749;
  _ret2749 = guestfs_blockdev_setrw (g, _arg2750);
  if (_ret2749 == -1)
    return -1;
  int _ret2752;
  _ret2752 = guestfs_umount_all (g);
  if (_ret2752 == -1)
    return -1;
  int _ret2754;
  _ret2754 = guestfs_lvm_remove_all (g);
  if (_ret2754 == -1)
    return -1;
  const char *_arg2757 = "/dev/sdb1";
  const char *_arg2758 = "/";
  int _ret2756;
  _ret2756 = guestfs_mount (g, _arg2757, _arg2758);
  if (_ret2756 == -1)
    return -1;

  /* TestResultString for vfs_type (0) */
  const char *_arg2760 = "/dev/sdb1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_type (g, _arg2760);
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
test_case_sensitive_path_0 (void)
{
  if (test_case_sensitive_path_0_skip ()) {
    skipped ("test_case_sensitive_path_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_case_sensitive_path_0 */
  const char *_arg2763 = "/dev/sda";
  int _ret2762;
  _ret2762 = guestfs_blockdev_setrw (g, _arg2763);
  if (_ret2762 == -1)
    return -1;
  int _ret2765;
  _ret2765 = guestfs_umount_all (g);
  if (_ret2765 == -1)
    return -1;
  int _ret2767;
  _ret2767 = guestfs_lvm_remove_all (g);
  if (_ret2767 == -1)
    return -1;
  const char *_arg2770 = "/dev/sdd";
  const char *_arg2771 = "/";
  int _ret2769;
  _ret2769 = guestfs_mount_ro (g, _arg2770, _arg2771);
  if (_ret2769 == -1)
    return -1;

  /* TestResultString for case_sensitive_path (0) */
  const char *_arg2773 = "/DIRECTORY";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg2773);
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
test_case_sensitive_path_1 (void)
{
  if (test_case_sensitive_path_1_skip ()) {
    skipped ("test_case_sensitive_path_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_case_sensitive_path_1 */
  const char *_arg2776 = "/dev/sda";
  int _ret2775;
  _ret2775 = guestfs_blockdev_setrw (g, _arg2776);
  if (_ret2775 == -1)
    return -1;
  int _ret2778;
  _ret2778 = guestfs_umount_all (g);
  if (_ret2778 == -1)
    return -1;
  int _ret2780;
  _ret2780 = guestfs_lvm_remove_all (g);
  if (_ret2780 == -1)
    return -1;
  const char *_arg2783 = "/dev/sdd";
  const char *_arg2784 = "/";
  int _ret2782;
  _ret2782 = guestfs_mount_ro (g, _arg2783, _arg2784);
  if (_ret2782 == -1)
    return -1;

  /* TestResultString for case_sensitive_path (1) */
  const char *_arg2786 = "/DIRECTORY/";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg2786);
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
test_case_sensitive_path_2 (void)
{
  if (test_case_sensitive_path_2_skip ()) {
    skipped ("test_case_sensitive_path_2", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_case_sensitive_path_2 */
  const char *_arg2789 = "/dev/sda";
  int _ret2788;
  _ret2788 = guestfs_blockdev_setrw (g, _arg2789);
  if (_ret2788 == -1)
    return -1;
  int _ret2791;
  _ret2791 = guestfs_umount_all (g);
  if (_ret2791 == -1)
    return -1;
  int _ret2793;
  _ret2793 = guestfs_lvm_remove_all (g);
  if (_ret2793 == -1)
    return -1;
  const char *_arg2796 = "/dev/sdd";
  const char *_arg2797 = "/";
  int _ret2795;
  _ret2795 = guestfs_mount_ro (g, _arg2796, _arg2797);
  if (_ret2795 == -1)
    return -1;

  /* TestResultString for case_sensitive_path (2) */
  const char *_arg2799 = "/Known-1";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg2799);
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
test_case_sensitive_path_3 (void)
{
  if (test_case_sensitive_path_3_skip ()) {
    skipped ("test_case_sensitive_path_3", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_case_sensitive_path_3 */
  const char *_arg2802 = "/dev/sda";
  int _ret2801;
  _ret2801 = guestfs_blockdev_setrw (g, _arg2802);
  if (_ret2801 == -1)
    return -1;
  int _ret2804;
  _ret2804 = guestfs_umount_all (g);
  if (_ret2804 == -1)
    return -1;
  int _ret2806;
  _ret2806 = guestfs_lvm_remove_all (g);
  if (_ret2806 == -1)
    return -1;
  const char *_arg2809 = "/dev/sdd";
  const char *_arg2810 = "/";
  int _ret2808;
  _ret2808 = guestfs_mount_ro (g, _arg2809, _arg2810);
  if (_ret2808 == -1)
    return -1;

  /* TestLastFail for case_sensitive_path (3) */
  const char *_arg2813 = "/Known-1/";
  CLEANUP_FREE char *_ret2812;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2812 = guestfs_case_sensitive_path (g, _arg2813);
  guestfs_pop_error_handler (g);
  if (_ret2812 != NULL)
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
test_case_sensitive_path_4 (void)
{
  if (test_case_sensitive_path_4_skip ()) {
    skipped ("test_case_sensitive_path_4", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_case_sensitive_path_4 */
  const char *_arg2816 = "/dev/sda";
  int _ret2815;
  _ret2815 = guestfs_blockdev_setrw (g, _arg2816);
  if (_ret2815 == -1)
    return -1;
  int _ret2818;
  _ret2818 = guestfs_umount_all (g);
  if (_ret2818 == -1)
    return -1;
  int _ret2820;
  _ret2820 = guestfs_lvm_remove_all (g);
  if (_ret2820 == -1)
    return -1;
  const char *_arg2823 = "/dev/sdb1";
  const char *_arg2824 = "/";
  int _ret2822;
  _ret2822 = guestfs_mount (g, _arg2823, _arg2824);
  if (_ret2822 == -1)
    return -1;

  /* TestResultString for case_sensitive_path (4) */
  const char *_arg2827 = "/case_sensitive_path";
  int _ret2826;
  _ret2826 = guestfs_mkdir (g, _arg2827);
  if (_ret2826 == -1)
    return -1;
  const char *_arg2830 = "/case_sensitive_path/bbb";
  int _ret2829;
  _ret2829 = guestfs_mkdir (g, _arg2830);
  if (_ret2829 == -1)
    return -1;
  const char *_arg2833 = "/case_sensitive_path/bbb/c";
  int _ret2832;
  _ret2832 = guestfs_touch (g, _arg2833);
  if (_ret2832 == -1)
    return -1;
  const char *_arg2835 = "/CASE_SENSITIVE_path/bbB/C";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg2835);
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
test_case_sensitive_path_5 (void)
{
  if (test_case_sensitive_path_5_skip ()) {
    skipped ("test_case_sensitive_path_5", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_case_sensitive_path_5 */
  const char *_arg2838 = "/dev/sda";
  int _ret2837;
  _ret2837 = guestfs_blockdev_setrw (g, _arg2838);
  if (_ret2837 == -1)
    return -1;
  int _ret2840;
  _ret2840 = guestfs_umount_all (g);
  if (_ret2840 == -1)
    return -1;
  int _ret2842;
  _ret2842 = guestfs_lvm_remove_all (g);
  if (_ret2842 == -1)
    return -1;
  const char *_arg2845 = "/dev/sdb1";
  const char *_arg2846 = "/";
  int _ret2844;
  _ret2844 = guestfs_mount (g, _arg2845, _arg2846);
  if (_ret2844 == -1)
    return -1;

  /* TestResultString for case_sensitive_path (5) */
  const char *_arg2849 = "/case_sensitive_path2";
  int _ret2848;
  _ret2848 = guestfs_mkdir (g, _arg2849);
  if (_ret2848 == -1)
    return -1;
  const char *_arg2852 = "/case_sensitive_path2/bbb";
  int _ret2851;
  _ret2851 = guestfs_mkdir (g, _arg2852);
  if (_ret2851 == -1)
    return -1;
  const char *_arg2855 = "/case_sensitive_path2/bbb/c";
  int _ret2854;
  _ret2854 = guestfs_touch (g, _arg2855);
  if (_ret2854 == -1)
    return -1;
  const char *_arg2857 = "/case_sensitive_PATH2////bbB/C";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg2857);
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
test_case_sensitive_path_6 (void)
{
  if (test_case_sensitive_path_6_skip ()) {
    skipped ("test_case_sensitive_path_6", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_case_sensitive_path_6 */
  const char *_arg2860 = "/dev/sda";
  int _ret2859;
  _ret2859 = guestfs_blockdev_setrw (g, _arg2860);
  if (_ret2859 == -1)
    return -1;
  int _ret2862;
  _ret2862 = guestfs_umount_all (g);
  if (_ret2862 == -1)
    return -1;
  int _ret2864;
  _ret2864 = guestfs_lvm_remove_all (g);
  if (_ret2864 == -1)
    return -1;
  const char *_arg2867 = "/dev/sdb1";
  const char *_arg2868 = "/";
  int _ret2866;
  _ret2866 = guestfs_mount (g, _arg2867, _arg2868);
  if (_ret2866 == -1)
    return -1;

  /* TestLastFail for case_sensitive_path (6) */
  const char *_arg2871 = "/case_sensitive_path3";
  int _ret2870;
  _ret2870 = guestfs_mkdir (g, _arg2871);
  if (_ret2870 == -1)
    return -1;
  const char *_arg2874 = "/case_sensitive_path3/bbb";
  int _ret2873;
  _ret2873 = guestfs_mkdir (g, _arg2874);
  if (_ret2873 == -1)
    return -1;
  const char *_arg2877 = "/case_sensitive_path3/bbb/c";
  int _ret2876;
  _ret2876 = guestfs_touch (g, _arg2877);
  if (_ret2876 == -1)
    return -1;
  const char *_arg2880 = "/case_SENSITIVE_path3/bbb/../bbb/C";
  CLEANUP_FREE char *_ret2879;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret2879 = guestfs_case_sensitive_path (g, _arg2880);
  guestfs_pop_error_handler (g);
  if (_ret2879 != NULL)
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
test_case_sensitive_path_7 (void)
{
  if (test_case_sensitive_path_7_skip ()) {
    skipped ("test_case_sensitive_path_7", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_case_sensitive_path_7 */
  const char *_arg2883 = "/dev/sda";
  int _ret2882;
  _ret2882 = guestfs_blockdev_setrw (g, _arg2883);
  if (_ret2882 == -1)
    return -1;
  int _ret2885;
  _ret2885 = guestfs_umount_all (g);
  if (_ret2885 == -1)
    return -1;
  int _ret2887;
  _ret2887 = guestfs_lvm_remove_all (g);
  if (_ret2887 == -1)
    return -1;
  const char *_arg2890 = "/dev/sdb1";
  const char *_arg2891 = "/";
  int _ret2889;
  _ret2889 = guestfs_mount (g, _arg2890, _arg2891);
  if (_ret2889 == -1)
    return -1;

  /* TestResultString for case_sensitive_path (7) */
  const char *_arg2894 = "/case_sensitive_path4";
  int _ret2893;
  _ret2893 = guestfs_mkdir (g, _arg2894);
  if (_ret2893 == -1)
    return -1;
  const char *_arg2896 = "/case_SENSITIVE_path4/new_file";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, _arg2896);
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
test_echo_daemon_0 (void)
{
  if (test_echo_daemon_0_skip ()) {
    skipped ("test_echo_daemon_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_echo_daemon_0 */
  const char *_arg2899 = "/dev/sda";
  int _ret2898;
  _ret2898 = guestfs_blockdev_setrw (g, _arg2899);
  if (_ret2898 == -1)
    return -1;
  int _ret2901;
  _ret2901 = guestfs_umount_all (g);
  if (_ret2901 == -1)
    return -1;
  int _ret2903;
  _ret2903 = guestfs_lvm_remove_all (g);
  if (_ret2903 == -1)
    return -1;

  /* TestResultString for echo_daemon (0) */
  const char *_arg2905_0 = "This";
  const char *_arg2905_1 = "is";
  const char *_arg2905_2 = "a";
  const char *_arg2905_3 = "test";
  const char *const _arg2905[] = {
    _arg2905_0,
    _arg2905_1,
    _arg2905_2,
    _arg2905_3,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_echo_daemon (g, (char **) _arg2905);
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
test_modprobe_0 (void)
{
  if (test_modprobe_0_skip ()) {
    skipped ("test_modprobe_0", "environment variable set");
    return 0;
  }

  const char *_features2907[] = { "linuxmodules", NULL };
  if (!guestfs_feature_available (g, (char **) _features2907)) {
    skipped ("test_modprobe_0", "group %s not available in daemon",
             _features2907[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_modprobe_0 */
  const char *_arg2909 = "/dev/sda";
  int _ret2908;
  _ret2908 = guestfs_blockdev_setrw (g, _arg2909);
  if (_ret2908 == -1)
    return -1;
  int _ret2911;
  _ret2911 = guestfs_umount_all (g);
  if (_ret2911 == -1)
    return -1;
  int _ret2913;
  _ret2913 = guestfs_lvm_remove_all (g);
  if (_ret2913 == -1)
    return -1;

  /* TestRun for modprobe (0) */
  const char *_arg2916 = "fat";
  int _ret2915;
  _ret2915 = guestfs_modprobe (g, _arg2916);
  if (_ret2915 == -1)
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
test_mke2journal_U_0 (void)
{
  if (test_mke2journal_U_0_skip ()) {
    skipped ("test_mke2journal_U_0", "environment variable set");
    return 0;
  }

  const char *_features2918[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features2918)) {
    skipped ("test_mke2journal_U_0", "group %s not available in daemon",
             _features2918[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_mke2journal_U_0 */
  const char *_arg2920 = "/dev/sda";
  int _ret2919;
  _ret2919 = guestfs_blockdev_setrw (g, _arg2920);
  if (_ret2919 == -1)
    return -1;
  int _ret2922;
  _ret2922 = guestfs_umount_all (g);
  if (_ret2922 == -1)
    return -1;
  int _ret2924;
  _ret2924 = guestfs_lvm_remove_all (g);
  if (_ret2924 == -1)
    return -1;

  /* TestResultString for mke2journal_U (0) */
  const char *_arg2927 = "/dev/sda";
  const char *_arg2928 = "mbr";
  int _ret2926;
  _ret2926 = guestfs_part_init (g, _arg2927, _arg2928);
  if (_ret2926 == -1)
    return -1;
  const char *_arg2931 = "/dev/sda";
  const char *_arg2932 = "p";
  int _ret2930;
  _ret2930 = guestfs_part_add (g, _arg2931, _arg2932, 64, 204799);
  if (_ret2930 == -1)
    return -1;
  const char *_arg2937 = "/dev/sda";
  const char *_arg2938 = "p";
  int _ret2936;
  _ret2936 = guestfs_part_add (g, _arg2937, _arg2938, 204800, -64);
  if (_ret2936 == -1)
    return -1;
  const char *_arg2944 = "fd5f5bd4-9254-0e03-76b4-43f62553291c";
  const char *_arg2945 = "/dev/sda1";
  int _ret2942;
  _ret2942 = guestfs_mke2journal_U (g, 4096, _arg2944, _arg2945);
  if (_ret2942 == -1)
    return -1;
  const char *_arg2948 = "ext2";
  const char *_arg2950 = "/dev/sda2";
  const char *_arg2951 = "fd5f5bd4-9254-0e03-76b4-43f62553291c";
  int _ret2947;
  _ret2947 = guestfs_mke2fs_JU (g, _arg2948, 4096, _arg2950, _arg2951);
  if (_ret2947 == -1)
    return -1;
  const char *_arg2954 = "/dev/sda2";
  const char *_arg2955 = "/";
  int _ret2953;
  _ret2953 = guestfs_mount (g, _arg2954, _arg2955);
  if (_ret2953 == -1)
    return -1;
  const char *_arg2958 = "/new";
  const char *_arg2959 = "new file contents";
  size_t _arg2959_size = 17;
  int _ret2957;
  _ret2957 = guestfs_write (g, _arg2958, _arg2959, _arg2959_size);
  if (_ret2957 == -1)
    return -1;
  const char *_arg2961 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg2961);
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
test_mke2journal_L_0 (void)
{
  if (test_mke2journal_L_0_skip ()) {
    skipped ("test_mke2journal_L_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mke2journal_L_0 */
  const char *_arg2964 = "/dev/sda";
  int _ret2963;
  _ret2963 = guestfs_blockdev_setrw (g, _arg2964);
  if (_ret2963 == -1)
    return -1;
  int _ret2966;
  _ret2966 = guestfs_umount_all (g);
  if (_ret2966 == -1)
    return -1;
  int _ret2968;
  _ret2968 = guestfs_lvm_remove_all (g);
  if (_ret2968 == -1)
    return -1;

  /* TestResultString for mke2journal_L (0) */
  const char *_arg2971 = "/dev/sda";
  const char *_arg2972 = "mbr";
  int _ret2970;
  _ret2970 = guestfs_part_init (g, _arg2971, _arg2972);
  if (_ret2970 == -1)
    return -1;
  const char *_arg2975 = "/dev/sda";
  const char *_arg2976 = "p";
  int _ret2974;
  _ret2974 = guestfs_part_add (g, _arg2975, _arg2976, 64, 204799);
  if (_ret2974 == -1)
    return -1;
  const char *_arg2981 = "/dev/sda";
  const char *_arg2982 = "p";
  int _ret2980;
  _ret2980 = guestfs_part_add (g, _arg2981, _arg2982, 204800, -64);
  if (_ret2980 == -1)
    return -1;
  const char *_arg2988 = "JOURNAL";
  const char *_arg2989 = "/dev/sda1";
  int _ret2986;
  _ret2986 = guestfs_mke2journal_L (g, 4096, _arg2988, _arg2989);
  if (_ret2986 == -1)
    return -1;
  const char *_arg2992 = "ext2";
  const char *_arg2994 = "/dev/sda2";
  const char *_arg2995 = "JOURNAL";
  int _ret2991;
  _ret2991 = guestfs_mke2fs_JL (g, _arg2992, 4096, _arg2994, _arg2995);
  if (_ret2991 == -1)
    return -1;
  const char *_arg2998 = "/dev/sda2";
  const char *_arg2999 = "/";
  int _ret2997;
  _ret2997 = guestfs_mount (g, _arg2998, _arg2999);
  if (_ret2997 == -1)
    return -1;
  const char *_arg3002 = "/new";
  const char *_arg3003 = "new file contents";
  size_t _arg3003_size = 17;
  int _ret3001;
  _ret3001 = guestfs_write (g, _arg3002, _arg3003, _arg3003_size);
  if (_ret3001 == -1)
    return -1;
  const char *_arg3005 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3005);
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
test_mke2journal_0 (void)
{
  if (test_mke2journal_0_skip ()) {
    skipped ("test_mke2journal_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mke2journal_0 */
  const char *_arg3008 = "/dev/sda";
  int _ret3007;
  _ret3007 = guestfs_blockdev_setrw (g, _arg3008);
  if (_ret3007 == -1)
    return -1;
  int _ret3010;
  _ret3010 = guestfs_umount_all (g);
  if (_ret3010 == -1)
    return -1;
  int _ret3012;
  _ret3012 = guestfs_lvm_remove_all (g);
  if (_ret3012 == -1)
    return -1;

  /* TestResultString for mke2journal (0) */
  const char *_arg3015 = "/dev/sda";
  const char *_arg3016 = "mbr";
  int _ret3014;
  _ret3014 = guestfs_part_init (g, _arg3015, _arg3016);
  if (_ret3014 == -1)
    return -1;
  const char *_arg3019 = "/dev/sda";
  const char *_arg3020 = "p";
  int _ret3018;
  _ret3018 = guestfs_part_add (g, _arg3019, _arg3020, 64, 204799);
  if (_ret3018 == -1)
    return -1;
  const char *_arg3025 = "/dev/sda";
  const char *_arg3026 = "p";
  int _ret3024;
  _ret3024 = guestfs_part_add (g, _arg3025, _arg3026, 204800, -64);
  if (_ret3024 == -1)
    return -1;
  const char *_arg3032 = "/dev/sda1";
  int _ret3030;
  _ret3030 = guestfs_mke2journal (g, 4096, _arg3032);
  if (_ret3030 == -1)
    return -1;
  const char *_arg3035 = "ext2";
  const char *_arg3037 = "/dev/sda2";
  const char *_arg3038 = "/dev/sda1";
  int _ret3034;
  _ret3034 = guestfs_mke2fs_J (g, _arg3035, 4096, _arg3037, _arg3038);
  if (_ret3034 == -1)
    return -1;
  const char *_arg3041 = "/dev/sda2";
  const char *_arg3042 = "/";
  int _ret3040;
  _ret3040 = guestfs_mount (g, _arg3041, _arg3042);
  if (_ret3040 == -1)
    return -1;
  const char *_arg3045 = "/new";
  const char *_arg3046 = "new file contents";
  size_t _arg3046_size = 17;
  int _ret3044;
  _ret3044 = guestfs_write (g, _arg3045, _arg3046, _arg3046_size);
  if (_ret3044 == -1)
    return -1;
  const char *_arg3048 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3048);
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
test_mkfs_b_0 (void)
{
  if (test_mkfs_b_0_skip ()) {
    skipped ("test_mkfs_b_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_b_0 */
  const char *_arg3051 = "/dev/sda";
  int _ret3050;
  _ret3050 = guestfs_blockdev_setrw (g, _arg3051);
  if (_ret3050 == -1)
    return -1;
  int _ret3053;
  _ret3053 = guestfs_umount_all (g);
  if (_ret3053 == -1)
    return -1;
  int _ret3055;
  _ret3055 = guestfs_lvm_remove_all (g);
  if (_ret3055 == -1)
    return -1;

  /* TestResultString for mkfs_b (0) */
  const char *_arg3058 = "/dev/sda";
  const char *_arg3059 = "mbr";
  int _ret3057;
  _ret3057 = guestfs_part_disk (g, _arg3058, _arg3059);
  if (_ret3057 == -1)
    return -1;
  const char *_arg3062 = "ext2";
  const char *_arg3064 = "/dev/sda1";
  int _ret3061;
  _ret3061 = guestfs_mkfs_b (g, _arg3062, 4096, _arg3064);
  if (_ret3061 == -1)
    return -1;
  const char *_arg3067 = "/dev/sda1";
  const char *_arg3068 = "/";
  int _ret3066;
  _ret3066 = guestfs_mount (g, _arg3067, _arg3068);
  if (_ret3066 == -1)
    return -1;
  const char *_arg3071 = "/new";
  const char *_arg3072 = "new file contents";
  size_t _arg3072_size = 17;
  int _ret3070;
  _ret3070 = guestfs_write (g, _arg3071, _arg3072, _arg3072_size);
  if (_ret3070 == -1)
    return -1;
  const char *_arg3074 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg3074);
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
test_mkfs_b_1 (void)
{
  if (test_mkfs_b_1_skip ()) {
    skipped ("test_mkfs_b_1", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_b_1 */
  const char *_arg3077 = "/dev/sda";
  int _ret3076;
  _ret3076 = guestfs_blockdev_setrw (g, _arg3077);
  if (_ret3076 == -1)
    return -1;
  int _ret3079;
  _ret3079 = guestfs_umount_all (g);
  if (_ret3079 == -1)
    return -1;
  int _ret3081;
  _ret3081 = guestfs_lvm_remove_all (g);
  if (_ret3081 == -1)
    return -1;

  /* TestRun for mkfs_b (1) */
  const char *_arg3084 = "/dev/sda";
  const char *_arg3085 = "mbr";
  int _ret3083;
  _ret3083 = guestfs_part_disk (g, _arg3084, _arg3085);
  if (_ret3083 == -1)
    return -1;
  const char *_arg3088 = "vfat";
  const char *_arg3090 = "/dev/sda1";
  int _ret3087;
  _ret3087 = guestfs_mkfs_b (g, _arg3088, 32768, _arg3090);
  if (_ret3087 == -1)
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
test_mkfs_b_2 (void)
{
  if (test_mkfs_b_2_skip ()) {
    skipped ("test_mkfs_b_2", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_b_2 */
  const char *_arg3093 = "/dev/sda";
  int _ret3092;
  _ret3092 = guestfs_blockdev_setrw (g, _arg3093);
  if (_ret3092 == -1)
    return -1;
  int _ret3095;
  _ret3095 = guestfs_umount_all (g);
  if (_ret3095 == -1)
    return -1;
  int _ret3097;
  _ret3097 = guestfs_lvm_remove_all (g);
  if (_ret3097 == -1)
    return -1;

  /* TestLastFail for mkfs_b (2) */
  const char *_arg3100 = "/dev/sda";
  const char *_arg3101 = "mbr";
  int _ret3099;
  _ret3099 = guestfs_part_disk (g, _arg3100, _arg3101);
  if (_ret3099 == -1)
    return -1;
  const char *_arg3104 = "vfat";
  const char *_arg3106 = "/dev/sda1";
  int _ret3103;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret3103 = guestfs_mkfs_b (g, _arg3104, 32769, _arg3106);
  guestfs_pop_error_handler (g);
  if (_ret3103 != -1)
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
test_mkfs_b_3 (void)
{
  if (test_mkfs_b_3_skip ()) {
    skipped ("test_mkfs_b_3", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_b_3 */
  const char *_arg3109 = "/dev/sda";
  int _ret3108;
  _ret3108 = guestfs_blockdev_setrw (g, _arg3109);
  if (_ret3108 == -1)
    return -1;
  int _ret3111;
  _ret3111 = guestfs_umount_all (g);
  if (_ret3111 == -1)
    return -1;
  int _ret3113;
  _ret3113 = guestfs_lvm_remove_all (g);
  if (_ret3113 == -1)
    return -1;

  /* TestLastFail for mkfs_b (3) */
  const char *_arg3116 = "/dev/sda";
  const char *_arg3117 = "mbr";
  int _ret3115;
  _ret3115 = guestfs_part_disk (g, _arg3116, _arg3117);
  if (_ret3115 == -1)
    return -1;
  const char *_arg3120 = "vfat";
  const char *_arg3122 = "/dev/sda1";
  int _ret3119;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret3119 = guestfs_mkfs_b (g, _arg3120, 33280, _arg3122);
  guestfs_pop_error_handler (g);
  if (_ret3119 != -1)
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
test_mkfs_b_4 (void)
{
  if (test_mkfs_b_4_skip ()) {
    skipped ("test_mkfs_b_4", "environment variable set");
    return 0;
  }

  const char *_features3124[] = { "ntfsprogs", NULL };
  if (!guestfs_feature_available (g, (char **) _features3124)) {
    skipped ("test_mkfs_b_4", "group %s not available in daemon",
             _features3124[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_b_4 */
  const char *_arg3126 = "/dev/sda";
  int _ret3125;
  _ret3125 = guestfs_blockdev_setrw (g, _arg3126);
  if (_ret3125 == -1)
    return -1;
  int _ret3128;
  _ret3128 = guestfs_umount_all (g);
  if (_ret3128 == -1)
    return -1;
  int _ret3130;
  _ret3130 = guestfs_lvm_remove_all (g);
  if (_ret3130 == -1)
    return -1;

  /* TestRun for mkfs_b (4) */
  const char *_arg3133 = "/dev/sda";
  const char *_arg3134 = "mbr";
  int _ret3132;
  _ret3132 = guestfs_part_disk (g, _arg3133, _arg3134);
  if (_ret3132 == -1)
    return -1;
  const char *_arg3137 = "ntfs";
  const char *_arg3139 = "/dev/sda1";
  int _ret3136;
  _ret3136 = guestfs_mkfs_b (g, _arg3137, 32768, _arg3139);
  if (_ret3136 == -1)
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
test_inotify_add_watch_0 (void)
{
  if (test_inotify_add_watch_0_skip ()) {
    skipped ("test_inotify_add_watch_0", "environment variable set");
    return 0;
  }

  const char *_features3141[] = { "inotify", NULL };
  if (!guestfs_feature_available (g, (char **) _features3141)) {
    skipped ("test_inotify_add_watch_0", "group %s not available in daemon",
             _features3141[0]);
    return 0;
  }

  /* InitScratchFS for test_inotify_add_watch_0 */
  const char *_arg3143 = "/dev/sda";
  int _ret3142;
  _ret3142 = guestfs_blockdev_setrw (g, _arg3143);
  if (_ret3142 == -1)
    return -1;
  int _ret3145;
  _ret3145 = guestfs_umount_all (g);
  if (_ret3145 == -1)
    return -1;
  int _ret3147;
  _ret3147 = guestfs_lvm_remove_all (g);
  if (_ret3147 == -1)
    return -1;
  const char *_arg3150 = "/dev/sdb1";
  const char *_arg3151 = "/";
  int _ret3149;
  _ret3149 = guestfs_mount (g, _arg3150, _arg3151);
  if (_ret3149 == -1)
    return -1;

  /* TestResult for inotify_add_watch (0) */
  const char *_arg3153 = "/inotify_add_watch";
  int ret5;
  ret5 = guestfs_mkdir (g, _arg3153);
  if (ret5 == -1)
    return -1;
  int ret4;
  ret4 = guestfs_inotify_init (g, 0);
  if (ret4 == -1)
    return -1;
  const char *_arg3157 = "/inotify_add_watch";
  int64_t ret3;
  ret3 = guestfs_inotify_add_watch (g, _arg3157, 1073741823);
  if (ret3 == -1)
    return -1;
  const char *_arg3160 = "/inotify_add_watch/a";
  int ret2;
  ret2 = guestfs_touch (g, _arg3160);
  if (ret2 == -1)
    return -1;
  const char *_arg3162 = "/inotify_add_watch/b";
  int ret1;
  ret1 = guestfs_touch (g, _arg3162);
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
test_inotify_init_0 (void)
{
  if (test_inotify_init_0_skip ()) {
    skipped ("test_inotify_init_0", "environment variable set");
    return 0;
  }

  const char *_features3165[] = { "inotify", NULL };
  if (!guestfs_feature_available (g, (char **) _features3165)) {
    skipped ("test_inotify_init_0", "group %s not available in daemon",
             _features3165[0]);
    return 0;
  }

  /* InitISOFS for test_inotify_init_0 */
  const char *_arg3167 = "/dev/sda";
  int _ret3166;
  _ret3166 = guestfs_blockdev_setrw (g, _arg3167);
  if (_ret3166 == -1)
    return -1;
  int _ret3169;
  _ret3169 = guestfs_umount_all (g);
  if (_ret3169 == -1)
    return -1;
  int _ret3171;
  _ret3171 = guestfs_lvm_remove_all (g);
  if (_ret3171 == -1)
    return -1;
  const char *_arg3174 = "/dev/sdd";
  const char *_arg3175 = "/";
  int _ret3173;
  _ret3173 = guestfs_mount_ro (g, _arg3174, _arg3175);
  if (_ret3173 == -1)
    return -1;

  /* TestRun for inotify_init (0) */
  int _ret3177;
  _ret3177 = guestfs_inotify_init (g, 0);
  if (_ret3177 == -1)
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
test_mkswap_file_0 (void)
{
  if (test_mkswap_file_0_skip ()) {
    skipped ("test_mkswap_file_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mkswap_file_0 */
  const char *_arg3181 = "/dev/sda";
  int _ret3180;
  _ret3180 = guestfs_blockdev_setrw (g, _arg3181);
  if (_ret3180 == -1)
    return -1;
  int _ret3183;
  _ret3183 = guestfs_umount_all (g);
  if (_ret3183 == -1)
    return -1;
  int _ret3185;
  _ret3185 = guestfs_lvm_remove_all (g);
  if (_ret3185 == -1)
    return -1;
  const char *_arg3188 = "/dev/sdb1";
  const char *_arg3189 = "/";
  int _ret3187;
  _ret3187 = guestfs_mount (g, _arg3188, _arg3189);
  if (_ret3187 == -1)
    return -1;

  /* TestRun for mkswap_file (0) */
  const char *_arg3192 = "/mkswap_file";
  int _ret3191;
  _ret3191 = guestfs_fallocate (g, _arg3192, 8388608);
  if (_ret3191 == -1)
    return -1;
  const char *_arg3196 = "/mkswap_file";
  int _ret3195;
  _ret3195 = guestfs_mkswap_file (g, _arg3196);
  if (_ret3195 == -1)
    return -1;
  const char *_arg3199 = "/mkswap_file";
  int _ret3198;
  _ret3198 = guestfs_rm (g, _arg3199);
  if (_ret3198 == -1)
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
test_swapon_uuid_0 (void)
{
  if (test_swapon_uuid_0_skip ()) {
    skipped ("test_swapon_uuid_0", "environment variable set");
    return 0;
  }

  const char *_features3201[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features3201)) {
    skipped ("test_swapon_uuid_0", "group %s not available in daemon",
             _features3201[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_swapon_uuid_0 */
  const char *_arg3203 = "/dev/sda";
  int _ret3202;
  _ret3202 = guestfs_blockdev_setrw (g, _arg3203);
  if (_ret3202 == -1)
    return -1;
  int _ret3205;
  _ret3205 = guestfs_umount_all (g);
  if (_ret3205 == -1)
    return -1;
  int _ret3207;
  _ret3207 = guestfs_lvm_remove_all (g);
  if (_ret3207 == -1)
    return -1;

  /* TestRun for swapon_uuid (0) */
  const char *_arg3210 = "/dev/sdc";
  struct guestfs_mkswap_opts_argv _optargs3211;
  _optargs3211.uuid = "fd5f5bd4-9254-0e03-76b4-43f62553291c";
  _optargs3211.bitmask = UINT64_C(0x2);
  int _ret3209;
  _ret3209 = guestfs_mkswap_opts_argv (g, _arg3210, &_optargs3211);
  if (_ret3209 == -1)
    return -1;
  const char *_arg3213 = "fd5f5bd4-9254-0e03-76b4-43f62553291c";
  int _ret3212;
  _ret3212 = guestfs_swapon_uuid (g, _arg3213);
  if (_ret3212 == -1)
    return -1;
  const char *_arg3216 = "fd5f5bd4-9254-0e03-76b4-43f62553291c";
  int _ret3215;
  _ret3215 = guestfs_swapoff_uuid (g, _arg3216);
  if (_ret3215 == -1)
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
test_swapon_label_0 (void)
{
  if (test_swapon_label_0_skip ()) {
    skipped ("test_swapon_label_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_swapon_label_0 */
  const char *_arg3219 = "/dev/sda";
  int _ret3218;
  _ret3218 = guestfs_blockdev_setrw (g, _arg3219);
  if (_ret3218 == -1)
    return -1;
  int _ret3221;
  _ret3221 = guestfs_umount_all (g);
  if (_ret3221 == -1)
    return -1;
  int _ret3223;
  _ret3223 = guestfs_lvm_remove_all (g);
  if (_ret3223 == -1)
    return -1;

  /* TestRun for swapon_label (0) */
  const char *_arg3226 = "/dev/sda";
  const char *_arg3227 = "mbr";
  int _ret3225;
  _ret3225 = guestfs_part_disk (g, _arg3226, _arg3227);
  if (_ret3225 == -1)
    return -1;
  const char *_arg3230 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs3231;
  _optargs3231.label = "swapit";
  _optargs3231.bitmask = UINT64_C(0x1);
  int _ret3229;
  _ret3229 = guestfs_mkswap_opts_argv (g, _arg3230, &_optargs3231);
  if (_ret3229 == -1)
    return -1;
  const char *_arg3233 = "swapit";
  int _ret3232;
  _ret3232 = guestfs_swapon_label (g, _arg3233);
  if (_ret3232 == -1)
    return -1;
  const char *_arg3236 = "swapit";
  int _ret3235;
  _ret3235 = guestfs_swapoff_label (g, _arg3236);
  if (_ret3235 == -1)
    return -1;
  const char *_arg3239 = "/dev/sda";
  int _ret3238;
  _ret3238 = guestfs_zero (g, _arg3239);
  if (_ret3238 == -1)
    return -1;
  const char *_arg3242 = "/dev/sda";
  int _ret3241;
  _ret3241 = guestfs_blockdev_rereadpt (g, _arg3242);
  if (_ret3241 == -1)
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
test_swapon_file_0 (void)
{
  if (test_swapon_file_0_skip ()) {
    skipped ("test_swapon_file_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_swapon_file_0 */
  const char *_arg3245 = "/dev/sda";
  int _ret3244;
  _ret3244 = guestfs_blockdev_setrw (g, _arg3245);
  if (_ret3244 == -1)
    return -1;
  int _ret3247;
  _ret3247 = guestfs_umount_all (g);
  if (_ret3247 == -1)
    return -1;
  int _ret3249;
  _ret3249 = guestfs_lvm_remove_all (g);
  if (_ret3249 == -1)
    return -1;
  const char *_arg3252 = "/dev/sdb1";
  const char *_arg3253 = "/";
  int _ret3251;
  _ret3251 = guestfs_mount (g, _arg3252, _arg3253);
  if (_ret3251 == -1)
    return -1;

  /* TestRun for swapon_file (0) */
  const char *_arg3256 = "/swapon_file";
  int _ret3255;
  _ret3255 = guestfs_fallocate (g, _arg3256, 8388608);
  if (_ret3255 == -1)
    return -1;
  const char *_arg3260 = "/swapon_file";
  int _ret3259;
  _ret3259 = guestfs_mkswap_file (g, _arg3260);
  if (_ret3259 == -1)
    return -1;
  const char *_arg3263 = "/swapon_file";
  int _ret3262;
  _ret3262 = guestfs_swapon_file (g, _arg3263);
  if (_ret3262 == -1)
    return -1;
  const char *_arg3266 = "/swapon_file";
  int _ret3265;
  _ret3265 = guestfs_swapoff_file (g, _arg3266);
  if (_ret3265 == -1)
    return -1;
  const char *_arg3269 = "/swapon_file";
  int _ret3268;
  _ret3268 = guestfs_rm (g, _arg3269);
  if (_ret3268 == -1)
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
test_swapon_device_0 (void)
{
  if (test_swapon_device_0_skip ()) {
    skipped ("test_swapon_device_0", "environment variable set");
    return 0;
  }

  /* InitPartition for test_swapon_device_0: create /dev/sda1 */
  const char *_arg3272 = "/dev/sda";
  int _ret3271;
  _ret3271 = guestfs_blockdev_setrw (g, _arg3272);
  if (_ret3271 == -1)
    return -1;
  int _ret3274;
  _ret3274 = guestfs_umount_all (g);
  if (_ret3274 == -1)
    return -1;
  int _ret3276;
  _ret3276 = guestfs_lvm_remove_all (g);
  if (_ret3276 == -1)
    return -1;
  const char *_arg3279 = "/dev/sda";
  const char *_arg3280 = "mbr";
  int _ret3278;
  _ret3278 = guestfs_part_disk (g, _arg3279, _arg3280);
  if (_ret3278 == -1)
    return -1;

  /* TestRun for swapon_device (0) */
  const char *_arg3283 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs3284;
  _optargs3284.bitmask = UINT64_C(0x0);
  int _ret3282;
  _ret3282 = guestfs_mkswap_opts_argv (g, _arg3283, &_optargs3284);
  if (_ret3282 == -1)
    return -1;
  const char *_arg3286 = "/dev/sda1";
  int _ret3285;
  _ret3285 = guestfs_swapon_device (g, _arg3286);
  if (_ret3285 == -1)
    return -1;
  const char *_arg3289 = "/dev/sda1";
  int _ret3288;
  _ret3288 = guestfs_swapoff_device (g, _arg3289);
  if (_ret3288 == -1)
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
test_fallocate_0 (void)
{
  if (test_fallocate_0_skip ()) {
    skipped ("test_fallocate_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_fallocate_0 */
  const char *_arg3292 = "/dev/sda";
  int _ret3291;
  _ret3291 = guestfs_blockdev_setrw (g, _arg3292);
  if (_ret3291 == -1)
    return -1;
  int _ret3294;
  _ret3294 = guestfs_umount_all (g);
  if (_ret3294 == -1)
    return -1;
  int _ret3296;
  _ret3296 = guestfs_lvm_remove_all (g);
  if (_ret3296 == -1)
    return -1;
  const char *_arg3299 = "/dev/sdb1";
  const char *_arg3300 = "/";
  int _ret3298;
  _ret3298 = guestfs_mount (g, _arg3299, _arg3300);
  if (_ret3298 == -1)
    return -1;

  /* TestResult for fallocate (0) */
  const char *_arg3302 = "/fallocate";
  int ret1;
  ret1 = guestfs_fallocate (g, _arg3302, 1000000);
  if (ret1 == -1)
    return -1;
  const char *_arg3305 = "/fallocate";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg3305);
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
test_ln_sf_0 (void)
{
  if (test_ln_sf_0_skip ()) {
    skipped ("test_ln_sf_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_ln_sf_0 */
  const char *_arg3308 = "/dev/sda";
  int _ret3307;
  _ret3307 = guestfs_blockdev_setrw (g, _arg3308);
  if (_ret3307 == -1)
    return -1;
  int _ret3310;
  _ret3310 = guestfs_umount_all (g);
  if (_ret3310 == -1)
    return -1;
  int _ret3312;
  _ret3312 = guestfs_lvm_remove_all (g);
  if (_ret3312 == -1)
    return -1;
  const char *_arg3315 = "/dev/sdb1";
  const char *_arg3316 = "/";
  int _ret3314;
  _ret3314 = guestfs_mount (g, _arg3315, _arg3316);
  if (_ret3314 == -1)
    return -1;

  /* TestResultString for ln_sf (0) */
  const char *_arg3319 = "/ln_sf/b";
  int _ret3318;
  _ret3318 = guestfs_mkdir_p (g, _arg3319);
  if (_ret3318 == -1)
    return -1;
  const char *_arg3322 = "/ln_sf/b/c";
  int _ret3321;
  _ret3321 = guestfs_touch (g, _arg3322);
  if (_ret3321 == -1)
    return -1;
  const char *_arg3325 = "../d";
  const char *_arg3326 = "/ln_sf/b/c";
  int _ret3324;
  _ret3324 = guestfs_ln_sf (g, _arg3325, _arg3326);
  if (_ret3324 == -1)
    return -1;
  const char *_arg3328 = "/ln_sf/b/c";
  CLEANUP_FREE char *ret;
  ret = guestfs_readlink (g, _arg3328);
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
test_ln_s_0 (void)
{
  if (test_ln_s_0_skip ()) {
    skipped ("test_ln_s_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_ln_s_0 */
  const char *_arg3331 = "/dev/sda";
  int _ret3330;
  _ret3330 = guestfs_blockdev_setrw (g, _arg3331);
  if (_ret3330 == -1)
    return -1;
  int _ret3333;
  _ret3333 = guestfs_umount_all (g);
  if (_ret3333 == -1)
    return -1;
  int _ret3335;
  _ret3335 = guestfs_lvm_remove_all (g);
  if (_ret3335 == -1)
    return -1;
  const char *_arg3338 = "/dev/sdb1";
  const char *_arg3339 = "/";
  int _ret3337;
  _ret3337 = guestfs_mount (g, _arg3338, _arg3339);
  if (_ret3337 == -1)
    return -1;

  /* TestResult for ln_s (0) */
  const char *_arg3341 = "/ln_s";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg3341);
  if (ret3 == -1)
    return -1;
  const char *_arg3343 = "/ln_s/a";
  int ret2;
  ret2 = guestfs_touch (g, _arg3343);
  if (ret2 == -1)
    return -1;
  const char *_arg3345 = "a";
  const char *_arg3346 = "/ln_s/b";
  int ret1;
  ret1 = guestfs_ln_s (g, _arg3345, _arg3346);
  if (ret1 == -1)
    return -1;
  const char *_arg3348 = "/ln_s/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_lstat (g, _arg3348);
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
test_ln_f_0 (void)
{
  if (test_ln_f_0_skip ()) {
    skipped ("test_ln_f_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_ln_f_0 */
  const char *_arg3351 = "/dev/sda";
  int _ret3350;
  _ret3350 = guestfs_blockdev_setrw (g, _arg3351);
  if (_ret3350 == -1)
    return -1;
  int _ret3353;
  _ret3353 = guestfs_umount_all (g);
  if (_ret3353 == -1)
    return -1;
  int _ret3355;
  _ret3355 = guestfs_lvm_remove_all (g);
  if (_ret3355 == -1)
    return -1;
  const char *_arg3358 = "/dev/sdb1";
  const char *_arg3359 = "/";
  int _ret3357;
  _ret3357 = guestfs_mount (g, _arg3358, _arg3359);
  if (_ret3357 == -1)
    return -1;

  /* TestResult for ln_f (0) */
  const char *_arg3361 = "/ln_f";
  int ret4;
  ret4 = guestfs_mkdir (g, _arg3361);
  if (ret4 == -1)
    return -1;
  const char *_arg3363 = "/ln_f/a";
  int ret3;
  ret3 = guestfs_touch (g, _arg3363);
  if (ret3 == -1)
    return -1;
  const char *_arg3365 = "/ln_f/b";
  int ret2;
  ret2 = guestfs_touch (g, _arg3365);
  if (ret2 == -1)
    return -1;
  const char *_arg3367 = "/ln_f/a";
  const char *_arg3368 = "/ln_f/b";
  int ret1;
  ret1 = guestfs_ln_f (g, _arg3367, _arg3368);
  if (ret1 == -1)
    return -1;
  const char *_arg3370 = "/ln_f/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg3370);
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
test_ln_0 (void)
{
  if (test_ln_0_skip ()) {
    skipped ("test_ln_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_ln_0 */
  const char *_arg3373 = "/dev/sda";
  int _ret3372;
  _ret3372 = guestfs_blockdev_setrw (g, _arg3373);
  if (_ret3372 == -1)
    return -1;
  int _ret3375;
  _ret3375 = guestfs_umount_all (g);
  if (_ret3375 == -1)
    return -1;
  int _ret3377;
  _ret3377 = guestfs_lvm_remove_all (g);
  if (_ret3377 == -1)
    return -1;
  const char *_arg3380 = "/dev/sdb1";
  const char *_arg3381 = "/";
  int _ret3379;
  _ret3379 = guestfs_mount (g, _arg3380, _arg3381);
  if (_ret3379 == -1)
    return -1;

  /* TestResult for ln (0) */
  const char *_arg3383 = "/ln";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg3383);
  if (ret3 == -1)
    return -1;
  const char *_arg3385 = "/ln/a";
  int ret2;
  ret2 = guestfs_touch (g, _arg3385);
  if (ret2 == -1)
    return -1;
  const char *_arg3387 = "/ln/a";
  const char *_arg3388 = "/ln/b";
  int ret1;
  ret1 = guestfs_ln (g, _arg3387, _arg3388);
  if (ret1 == -1)
    return -1;
  const char *_arg3390 = "/ln/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg3390);
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
test_realpath_0 (void)
{
  if (test_realpath_0_skip ()) {
    skipped ("test_realpath_0", "environment variable set");
    return 0;
  }

  const char *_features3392[] = { "realpath", NULL };
  if (!guestfs_feature_available (g, (char **) _features3392)) {
    skipped ("test_realpath_0", "group %s not available in daemon",
             _features3392[0]);
    return 0;
  }

  /* InitISOFS for test_realpath_0 */
  const char *_arg3394 = "/dev/sda";
  int _ret3393;
  _ret3393 = guestfs_blockdev_setrw (g, _arg3394);
  if (_ret3393 == -1)
    return -1;
  int _ret3396;
  _ret3396 = guestfs_umount_all (g);
  if (_ret3396 == -1)
    return -1;
  int _ret3398;
  _ret3398 = guestfs_lvm_remove_all (g);
  if (_ret3398 == -1)
    return -1;
  const char *_arg3401 = "/dev/sdd";
  const char *_arg3402 = "/";
  int _ret3400;
  _ret3400 = guestfs_mount_ro (g, _arg3401, _arg3402);
  if (_ret3400 == -1)
    return -1;

  /* TestResultString for realpath (0) */
  const char *_arg3404 = "/../directory";
  CLEANUP_FREE char *ret;
  ret = guestfs_realpath (g, _arg3404);
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
test_zfgrepi_0 (void)
{
  if (test_zfgrepi_0_skip ()) {
    skipped ("test_zfgrepi_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_zfgrepi_0 */
  const char *_arg3407 = "/dev/sda";
  int _ret3406;
  _ret3406 = guestfs_blockdev_setrw (g, _arg3407);
  if (_ret3406 == -1)
    return -1;
  int _ret3409;
  _ret3409 = guestfs_umount_all (g);
  if (_ret3409 == -1)
    return -1;
  int _ret3411;
  _ret3411 = guestfs_lvm_remove_all (g);
  if (_ret3411 == -1)
    return -1;
  const char *_arg3414 = "/dev/sdd";
  const char *_arg3415 = "/";
  int _ret3413;
  _ret3413 = guestfs_mount_ro (g, _arg3414, _arg3415);
  if (_ret3413 == -1)
    return -1;

  /* TestResult for zfgrepi (0) */
  const char *_arg3417 = "abc";
  const char *_arg3418 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zfgrepi (g, _arg3417, _arg3418);
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
test_zegrepi_0 (void)
{
  if (test_zegrepi_0_skip ()) {
    skipped ("test_zegrepi_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_zegrepi_0 */
  const char *_arg3421 = "/dev/sda";
  int _ret3420;
  _ret3420 = guestfs_blockdev_setrw (g, _arg3421);
  if (_ret3420 == -1)
    return -1;
  int _ret3423;
  _ret3423 = guestfs_umount_all (g);
  if (_ret3423 == -1)
    return -1;
  int _ret3425;
  _ret3425 = guestfs_lvm_remove_all (g);
  if (_ret3425 == -1)
    return -1;
  const char *_arg3428 = "/dev/sdd";
  const char *_arg3429 = "/";
  int _ret3427;
  _ret3427 = guestfs_mount_ro (g, _arg3428, _arg3429);
  if (_ret3427 == -1)
    return -1;

  /* TestResult for zegrepi (0) */
  const char *_arg3431 = "abc";
  const char *_arg3432 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zegrepi (g, _arg3431, _arg3432);
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
test_zgrepi_0 (void)
{
  if (test_zgrepi_0_skip ()) {
    skipped ("test_zgrepi_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_zgrepi_0 */
  const char *_arg3435 = "/dev/sda";
  int _ret3434;
  _ret3434 = guestfs_blockdev_setrw (g, _arg3435);
  if (_ret3434 == -1)
    return -1;
  int _ret3437;
  _ret3437 = guestfs_umount_all (g);
  if (_ret3437 == -1)
    return -1;
  int _ret3439;
  _ret3439 = guestfs_lvm_remove_all (g);
  if (_ret3439 == -1)
    return -1;
  const char *_arg3442 = "/dev/sdd";
  const char *_arg3443 = "/";
  int _ret3441;
  _ret3441 = guestfs_mount_ro (g, _arg3442, _arg3443);
  if (_ret3441 == -1)
    return -1;

  /* TestResult for zgrepi (0) */
  const char *_arg3445 = "abc";
  const char *_arg3446 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zgrepi (g, _arg3445, _arg3446);
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
test_zfgrep_0 (void)
{
  if (test_zfgrep_0_skip ()) {
    skipped ("test_zfgrep_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_zfgrep_0 */
  const char *_arg3449 = "/dev/sda";
  int _ret3448;
  _ret3448 = guestfs_blockdev_setrw (g, _arg3449);
  if (_ret3448 == -1)
    return -1;
  int _ret3451;
  _ret3451 = guestfs_umount_all (g);
  if (_ret3451 == -1)
    return -1;
  int _ret3453;
  _ret3453 = guestfs_lvm_remove_all (g);
  if (_ret3453 == -1)
    return -1;
  const char *_arg3456 = "/dev/sdd";
  const char *_arg3457 = "/";
  int _ret3455;
  _ret3455 = guestfs_mount_ro (g, _arg3456, _arg3457);
  if (_ret3455 == -1)
    return -1;

  /* TestResult for zfgrep (0) */
  const char *_arg3459 = "abc";
  const char *_arg3460 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zfgrep (g, _arg3459, _arg3460);
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
test_zegrep_0 (void)
{
  if (test_zegrep_0_skip ()) {
    skipped ("test_zegrep_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_zegrep_0 */
  const char *_arg3463 = "/dev/sda";
  int _ret3462;
  _ret3462 = guestfs_blockdev_setrw (g, _arg3463);
  if (_ret3462 == -1)
    return -1;
  int _ret3465;
  _ret3465 = guestfs_umount_all (g);
  if (_ret3465 == -1)
    return -1;
  int _ret3467;
  _ret3467 = guestfs_lvm_remove_all (g);
  if (_ret3467 == -1)
    return -1;
  const char *_arg3470 = "/dev/sdd";
  const char *_arg3471 = "/";
  int _ret3469;
  _ret3469 = guestfs_mount_ro (g, _arg3470, _arg3471);
  if (_ret3469 == -1)
    return -1;

  /* TestResult for zegrep (0) */
  const char *_arg3473 = "abc";
  const char *_arg3474 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zegrep (g, _arg3473, _arg3474);
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
test_zgrep_0 (void)
{
  if (test_zgrep_0_skip ()) {
    skipped ("test_zgrep_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_zgrep_0 */
  const char *_arg3477 = "/dev/sda";
  int _ret3476;
  _ret3476 = guestfs_blockdev_setrw (g, _arg3477);
  if (_ret3476 == -1)
    return -1;
  int _ret3479;
  _ret3479 = guestfs_umount_all (g);
  if (_ret3479 == -1)
    return -1;
  int _ret3481;
  _ret3481 = guestfs_lvm_remove_all (g);
  if (_ret3481 == -1)
    return -1;
  const char *_arg3484 = "/dev/sdd";
  const char *_arg3485 = "/";
  int _ret3483;
  _ret3483 = guestfs_mount_ro (g, _arg3484, _arg3485);
  if (_ret3483 == -1)
    return -1;

  /* TestResult for zgrep (0) */
  const char *_arg3487 = "abc";
  const char *_arg3488 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zgrep (g, _arg3487, _arg3488);
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
test_fgrepi_0 (void)
{
  if (test_fgrepi_0_skip ()) {
    skipped ("test_fgrepi_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_fgrepi_0 */
  const char *_arg3491 = "/dev/sda";
  int _ret3490;
  _ret3490 = guestfs_blockdev_setrw (g, _arg3491);
  if (_ret3490 == -1)
    return -1;
  int _ret3493;
  _ret3493 = guestfs_umount_all (g);
  if (_ret3493 == -1)
    return -1;
  int _ret3495;
  _ret3495 = guestfs_lvm_remove_all (g);
  if (_ret3495 == -1)
    return -1;
  const char *_arg3498 = "/dev/sdd";
  const char *_arg3499 = "/";
  int _ret3497;
  _ret3497 = guestfs_mount_ro (g, _arg3498, _arg3499);
  if (_ret3497 == -1)
    return -1;

  /* TestResult for fgrepi (0) */
  const char *_arg3501 = "abc";
  const char *_arg3502 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_fgrepi (g, _arg3501, _arg3502);
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
test_egrepi_0 (void)
{
  if (test_egrepi_0_skip ()) {
    skipped ("test_egrepi_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_egrepi_0 */
  const char *_arg3505 = "/dev/sda";
  int _ret3504;
  _ret3504 = guestfs_blockdev_setrw (g, _arg3505);
  if (_ret3504 == -1)
    return -1;
  int _ret3507;
  _ret3507 = guestfs_umount_all (g);
  if (_ret3507 == -1)
    return -1;
  int _ret3509;
  _ret3509 = guestfs_lvm_remove_all (g);
  if (_ret3509 == -1)
    return -1;
  const char *_arg3512 = "/dev/sdd";
  const char *_arg3513 = "/";
  int _ret3511;
  _ret3511 = guestfs_mount_ro (g, _arg3512, _arg3513);
  if (_ret3511 == -1)
    return -1;

  /* TestResult for egrepi (0) */
  const char *_arg3515 = "abc";
  const char *_arg3516 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_egrepi (g, _arg3515, _arg3516);
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
test_grepi_0 (void)
{
  if (test_grepi_0_skip ()) {
    skipped ("test_grepi_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grepi_0 */
  const char *_arg3519 = "/dev/sda";
  int _ret3518;
  _ret3518 = guestfs_blockdev_setrw (g, _arg3519);
  if (_ret3518 == -1)
    return -1;
  int _ret3521;
  _ret3521 = guestfs_umount_all (g);
  if (_ret3521 == -1)
    return -1;
  int _ret3523;
  _ret3523 = guestfs_lvm_remove_all (g);
  if (_ret3523 == -1)
    return -1;
  const char *_arg3526 = "/dev/sdd";
  const char *_arg3527 = "/";
  int _ret3525;
  _ret3525 = guestfs_mount_ro (g, _arg3526, _arg3527);
  if (_ret3525 == -1)
    return -1;

  /* TestResult for grepi (0) */
  const char *_arg3529 = "abc";
  const char *_arg3530 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grepi (g, _arg3529, _arg3530);
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
test_fgrep_0 (void)
{
  if (test_fgrep_0_skip ()) {
    skipped ("test_fgrep_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_fgrep_0 */
  const char *_arg3533 = "/dev/sda";
  int _ret3532;
  _ret3532 = guestfs_blockdev_setrw (g, _arg3533);
  if (_ret3532 == -1)
    return -1;
  int _ret3535;
  _ret3535 = guestfs_umount_all (g);
  if (_ret3535 == -1)
    return -1;
  int _ret3537;
  _ret3537 = guestfs_lvm_remove_all (g);
  if (_ret3537 == -1)
    return -1;
  const char *_arg3540 = "/dev/sdd";
  const char *_arg3541 = "/";
  int _ret3539;
  _ret3539 = guestfs_mount_ro (g, _arg3540, _arg3541);
  if (_ret3539 == -1)
    return -1;

  /* TestResult for fgrep (0) */
  const char *_arg3543 = "abc";
  const char *_arg3544 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_fgrep (g, _arg3543, _arg3544);
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
test_egrep_0 (void)
{
  if (test_egrep_0_skip ()) {
    skipped ("test_egrep_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_egrep_0 */
  const char *_arg3547 = "/dev/sda";
  int _ret3546;
  _ret3546 = guestfs_blockdev_setrw (g, _arg3547);
  if (_ret3546 == -1)
    return -1;
  int _ret3549;
  _ret3549 = guestfs_umount_all (g);
  if (_ret3549 == -1)
    return -1;
  int _ret3551;
  _ret3551 = guestfs_lvm_remove_all (g);
  if (_ret3551 == -1)
    return -1;
  const char *_arg3554 = "/dev/sdd";
  const char *_arg3555 = "/";
  int _ret3553;
  _ret3553 = guestfs_mount_ro (g, _arg3554, _arg3555);
  if (_ret3553 == -1)
    return -1;

  /* TestResult for egrep (0) */
  const char *_arg3557 = "abc";
  const char *_arg3558 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_egrep (g, _arg3557, _arg3558);
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
test_grep_0 (void)
{
  if (test_grep_0_skip ()) {
    skipped ("test_grep_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_0 */
  const char *_arg3561 = "/dev/sda";
  int _ret3560;
  _ret3560 = guestfs_blockdev_setrw (g, _arg3561);
  if (_ret3560 == -1)
    return -1;
  int _ret3563;
  _ret3563 = guestfs_umount_all (g);
  if (_ret3563 == -1)
    return -1;
  int _ret3565;
  _ret3565 = guestfs_lvm_remove_all (g);
  if (_ret3565 == -1)
    return -1;
  const char *_arg3568 = "/dev/sdd";
  const char *_arg3569 = "/";
  int _ret3567;
  _ret3567 = guestfs_mount_ro (g, _arg3568, _arg3569);
  if (_ret3567 == -1)
    return -1;

  /* TestResult for grep (0) */
  const char *_arg3571 = "abc";
  const char *_arg3572 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs3573;
  _optargs3573.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3571, _arg3572, &_optargs3573);
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
test_grep_1 (void)
{
  if (test_grep_1_skip ()) {
    skipped ("test_grep_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_1 */
  const char *_arg3575 = "/dev/sda";
  int _ret3574;
  _ret3574 = guestfs_blockdev_setrw (g, _arg3575);
  if (_ret3574 == -1)
    return -1;
  int _ret3577;
  _ret3577 = guestfs_umount_all (g);
  if (_ret3577 == -1)
    return -1;
  int _ret3579;
  _ret3579 = guestfs_lvm_remove_all (g);
  if (_ret3579 == -1)
    return -1;
  const char *_arg3582 = "/dev/sdd";
  const char *_arg3583 = "/";
  int _ret3581;
  _ret3581 = guestfs_mount_ro (g, _arg3582, _arg3583);
  if (_ret3581 == -1)
    return -1;

  /* TestResult for grep (1) */
  const char *_arg3585 = "nomatch";
  const char *_arg3586 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs3587;
  _optargs3587.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3585, _arg3586, &_optargs3587);
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
test_grep_2 (void)
{
  if (test_grep_2_skip ()) {
    skipped ("test_grep_2", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_2 */
  const char *_arg3589 = "/dev/sda";
  int _ret3588;
  _ret3588 = guestfs_blockdev_setrw (g, _arg3589);
  if (_ret3588 == -1)
    return -1;
  int _ret3591;
  _ret3591 = guestfs_umount_all (g);
  if (_ret3591 == -1)
    return -1;
  int _ret3593;
  _ret3593 = guestfs_lvm_remove_all (g);
  if (_ret3593 == -1)
    return -1;
  const char *_arg3596 = "/dev/sdd";
  const char *_arg3597 = "/";
  int _ret3595;
  _ret3595 = guestfs_mount_ro (g, _arg3596, _arg3597);
  if (_ret3595 == -1)
    return -1;

  /* TestResult for grep (2) */
  const char *_arg3599 = "nomatch";
  const char *_arg3600 = "/abssymlink";
  struct guestfs_grep_opts_argv _optargs3601;
  _optargs3601.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3599, _arg3600, &_optargs3601);
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
test_grep_3 (void)
{
  if (test_grep_3_skip ()) {
    skipped ("test_grep_3", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_3 */
  const char *_arg3603 = "/dev/sda";
  int _ret3602;
  _ret3602 = guestfs_blockdev_setrw (g, _arg3603);
  if (_ret3602 == -1)
    return -1;
  int _ret3605;
  _ret3605 = guestfs_umount_all (g);
  if (_ret3605 == -1)
    return -1;
  int _ret3607;
  _ret3607 = guestfs_lvm_remove_all (g);
  if (_ret3607 == -1)
    return -1;
  const char *_arg3610 = "/dev/sdd";
  const char *_arg3611 = "/";
  int _ret3609;
  _ret3609 = guestfs_mount_ro (g, _arg3610, _arg3611);
  if (_ret3609 == -1)
    return -1;

  /* TestResult for grep (3) */
  const char *_arg3613 = "abc";
  const char *_arg3614 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs3615;
  _optargs3615.extended = 1;
  _optargs3615.bitmask = UINT64_C(0x1);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3613, _arg3614, &_optargs3615);
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
test_grep_4 (void)
{
  if (test_grep_4_skip ()) {
    skipped ("test_grep_4", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_4 */
  const char *_arg3617 = "/dev/sda";
  int _ret3616;
  _ret3616 = guestfs_blockdev_setrw (g, _arg3617);
  if (_ret3616 == -1)
    return -1;
  int _ret3619;
  _ret3619 = guestfs_umount_all (g);
  if (_ret3619 == -1)
    return -1;
  int _ret3621;
  _ret3621 = guestfs_lvm_remove_all (g);
  if (_ret3621 == -1)
    return -1;
  const char *_arg3624 = "/dev/sdd";
  const char *_arg3625 = "/";
  int _ret3623;
  _ret3623 = guestfs_mount_ro (g, _arg3624, _arg3625);
  if (_ret3623 == -1)
    return -1;

  /* TestResult for grep (4) */
  const char *_arg3627 = "abc";
  const char *_arg3628 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs3629;
  _optargs3629.fixed = 1;
  _optargs3629.bitmask = UINT64_C(0x2);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3627, _arg3628, &_optargs3629);
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
test_grep_5 (void)
{
  if (test_grep_5_skip ()) {
    skipped ("test_grep_5", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_5 */
  const char *_arg3631 = "/dev/sda";
  int _ret3630;
  _ret3630 = guestfs_blockdev_setrw (g, _arg3631);
  if (_ret3630 == -1)
    return -1;
  int _ret3633;
  _ret3633 = guestfs_umount_all (g);
  if (_ret3633 == -1)
    return -1;
  int _ret3635;
  _ret3635 = guestfs_lvm_remove_all (g);
  if (_ret3635 == -1)
    return -1;
  const char *_arg3638 = "/dev/sdd";
  const char *_arg3639 = "/";
  int _ret3637;
  _ret3637 = guestfs_mount_ro (g, _arg3638, _arg3639);
  if (_ret3637 == -1)
    return -1;

  /* TestResult for grep (5) */
  const char *_arg3641 = "abc";
  const char *_arg3642 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs3643;
  _optargs3643.insensitive = 1;
  _optargs3643.bitmask = UINT64_C(0x4);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3641, _arg3642, &_optargs3643);
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
test_grep_6 (void)
{
  if (test_grep_6_skip ()) {
    skipped ("test_grep_6", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_6 */
  const char *_arg3645 = "/dev/sda";
  int _ret3644;
  _ret3644 = guestfs_blockdev_setrw (g, _arg3645);
  if (_ret3644 == -1)
    return -1;
  int _ret3647;
  _ret3647 = guestfs_umount_all (g);
  if (_ret3647 == -1)
    return -1;
  int _ret3649;
  _ret3649 = guestfs_lvm_remove_all (g);
  if (_ret3649 == -1)
    return -1;
  const char *_arg3652 = "/dev/sdd";
  const char *_arg3653 = "/";
  int _ret3651;
  _ret3651 = guestfs_mount_ro (g, _arg3652, _arg3653);
  if (_ret3651 == -1)
    return -1;

  /* TestResult for grep (6) */
  const char *_arg3655 = "abc";
  const char *_arg3656 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs3657;
  _optargs3657.extended = 1;
  _optargs3657.insensitive = 1;
  _optargs3657.bitmask = UINT64_C(0x5);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3655, _arg3656, &_optargs3657);
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
test_grep_7 (void)
{
  if (test_grep_7_skip ()) {
    skipped ("test_grep_7", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_7 */
  const char *_arg3659 = "/dev/sda";
  int _ret3658;
  _ret3658 = guestfs_blockdev_setrw (g, _arg3659);
  if (_ret3658 == -1)
    return -1;
  int _ret3661;
  _ret3661 = guestfs_umount_all (g);
  if (_ret3661 == -1)
    return -1;
  int _ret3663;
  _ret3663 = guestfs_lvm_remove_all (g);
  if (_ret3663 == -1)
    return -1;
  const char *_arg3666 = "/dev/sdd";
  const char *_arg3667 = "/";
  int _ret3665;
  _ret3665 = guestfs_mount_ro (g, _arg3666, _arg3667);
  if (_ret3665 == -1)
    return -1;

  /* TestResult for grep (7) */
  const char *_arg3669 = "abc";
  const char *_arg3670 = "/test-grep.txt";
  struct guestfs_grep_opts_argv _optargs3671;
  _optargs3671.fixed = 1;
  _optargs3671.insensitive = 1;
  _optargs3671.bitmask = UINT64_C(0x6);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3669, _arg3670, &_optargs3671);
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
test_grep_8 (void)
{
  if (test_grep_8_skip ()) {
    skipped ("test_grep_8", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_8 */
  const char *_arg3673 = "/dev/sda";
  int _ret3672;
  _ret3672 = guestfs_blockdev_setrw (g, _arg3673);
  if (_ret3672 == -1)
    return -1;
  int _ret3675;
  _ret3675 = guestfs_umount_all (g);
  if (_ret3675 == -1)
    return -1;
  int _ret3677;
  _ret3677 = guestfs_lvm_remove_all (g);
  if (_ret3677 == -1)
    return -1;
  const char *_arg3680 = "/dev/sdd";
  const char *_arg3681 = "/";
  int _ret3679;
  _ret3679 = guestfs_mount_ro (g, _arg3680, _arg3681);
  if (_ret3679 == -1)
    return -1;

  /* TestResult for grep (8) */
  const char *_arg3683 = "abc";
  const char *_arg3684 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs3685;
  _optargs3685.compressed = 1;
  _optargs3685.bitmask = UINT64_C(0x8);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3683, _arg3684, &_optargs3685);
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
test_grep_9 (void)
{
  if (test_grep_9_skip ()) {
    skipped ("test_grep_9", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_9 */
  const char *_arg3687 = "/dev/sda";
  int _ret3686;
  _ret3686 = guestfs_blockdev_setrw (g, _arg3687);
  if (_ret3686 == -1)
    return -1;
  int _ret3689;
  _ret3689 = guestfs_umount_all (g);
  if (_ret3689 == -1)
    return -1;
  int _ret3691;
  _ret3691 = guestfs_lvm_remove_all (g);
  if (_ret3691 == -1)
    return -1;
  const char *_arg3694 = "/dev/sdd";
  const char *_arg3695 = "/";
  int _ret3693;
  _ret3693 = guestfs_mount_ro (g, _arg3694, _arg3695);
  if (_ret3693 == -1)
    return -1;

  /* TestResult for grep (9) */
  const char *_arg3697 = "abc";
  const char *_arg3698 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs3699;
  _optargs3699.extended = 1;
  _optargs3699.compressed = 1;
  _optargs3699.bitmask = UINT64_C(0x9);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3697, _arg3698, &_optargs3699);
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
test_grep_10 (void)
{
  if (test_grep_10_skip ()) {
    skipped ("test_grep_10", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_10 */
  const char *_arg3701 = "/dev/sda";
  int _ret3700;
  _ret3700 = guestfs_blockdev_setrw (g, _arg3701);
  if (_ret3700 == -1)
    return -1;
  int _ret3703;
  _ret3703 = guestfs_umount_all (g);
  if (_ret3703 == -1)
    return -1;
  int _ret3705;
  _ret3705 = guestfs_lvm_remove_all (g);
  if (_ret3705 == -1)
    return -1;
  const char *_arg3708 = "/dev/sdd";
  const char *_arg3709 = "/";
  int _ret3707;
  _ret3707 = guestfs_mount_ro (g, _arg3708, _arg3709);
  if (_ret3707 == -1)
    return -1;

  /* TestResult for grep (10) */
  const char *_arg3711 = "abc";
  const char *_arg3712 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs3713;
  _optargs3713.fixed = 1;
  _optargs3713.compressed = 1;
  _optargs3713.bitmask = UINT64_C(0xa);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3711, _arg3712, &_optargs3713);
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
test_grep_11 (void)
{
  if (test_grep_11_skip ()) {
    skipped ("test_grep_11", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_11 */
  const char *_arg3715 = "/dev/sda";
  int _ret3714;
  _ret3714 = guestfs_blockdev_setrw (g, _arg3715);
  if (_ret3714 == -1)
    return -1;
  int _ret3717;
  _ret3717 = guestfs_umount_all (g);
  if (_ret3717 == -1)
    return -1;
  int _ret3719;
  _ret3719 = guestfs_lvm_remove_all (g);
  if (_ret3719 == -1)
    return -1;
  const char *_arg3722 = "/dev/sdd";
  const char *_arg3723 = "/";
  int _ret3721;
  _ret3721 = guestfs_mount_ro (g, _arg3722, _arg3723);
  if (_ret3721 == -1)
    return -1;

  /* TestResult for grep (11) */
  const char *_arg3725 = "abc";
  const char *_arg3726 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs3727;
  _optargs3727.insensitive = 1;
  _optargs3727.compressed = 1;
  _optargs3727.bitmask = UINT64_C(0xc);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3725, _arg3726, &_optargs3727);
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
test_grep_12 (void)
{
  if (test_grep_12_skip ()) {
    skipped ("test_grep_12", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_12 */
  const char *_arg3729 = "/dev/sda";
  int _ret3728;
  _ret3728 = guestfs_blockdev_setrw (g, _arg3729);
  if (_ret3728 == -1)
    return -1;
  int _ret3731;
  _ret3731 = guestfs_umount_all (g);
  if (_ret3731 == -1)
    return -1;
  int _ret3733;
  _ret3733 = guestfs_lvm_remove_all (g);
  if (_ret3733 == -1)
    return -1;
  const char *_arg3736 = "/dev/sdd";
  const char *_arg3737 = "/";
  int _ret3735;
  _ret3735 = guestfs_mount_ro (g, _arg3736, _arg3737);
  if (_ret3735 == -1)
    return -1;

  /* TestResult for grep (12) */
  const char *_arg3739 = "abc";
  const char *_arg3740 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs3741;
  _optargs3741.extended = 1;
  _optargs3741.insensitive = 1;
  _optargs3741.compressed = 1;
  _optargs3741.bitmask = UINT64_C(0xd);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3739, _arg3740, &_optargs3741);
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
test_grep_13 (void)
{
  if (test_grep_13_skip ()) {
    skipped ("test_grep_13", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_grep_13 */
  const char *_arg3743 = "/dev/sda";
  int _ret3742;
  _ret3742 = guestfs_blockdev_setrw (g, _arg3743);
  if (_ret3742 == -1)
    return -1;
  int _ret3745;
  _ret3745 = guestfs_umount_all (g);
  if (_ret3745 == -1)
    return -1;
  int _ret3747;
  _ret3747 = guestfs_lvm_remove_all (g);
  if (_ret3747 == -1)
    return -1;
  const char *_arg3750 = "/dev/sdd";
  const char *_arg3751 = "/";
  int _ret3749;
  _ret3749 = guestfs_mount_ro (g, _arg3750, _arg3751);
  if (_ret3749 == -1)
    return -1;

  /* TestResult for grep (13) */
  const char *_arg3753 = "abc";
  const char *_arg3754 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv _optargs3755;
  _optargs3755.fixed = 1;
  _optargs3755.insensitive = 1;
  _optargs3755.compressed = 1;
  _optargs3755.bitmask = UINT64_C(0xe);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, _arg3753, _arg3754, &_optargs3755);
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
test_umask_0 (void)
{
  if (test_umask_0_skip ()) {
    skipped ("test_umask_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_umask_0 */
  const char *_arg3757 = "/dev/sda";
  int _ret3756;
  _ret3756 = guestfs_blockdev_setrw (g, _arg3757);
  if (_ret3756 == -1)
    return -1;
  int _ret3759;
  _ret3759 = guestfs_umount_all (g);
  if (_ret3759 == -1)
    return -1;
  int _ret3761;
  _ret3761 = guestfs_lvm_remove_all (g);
  if (_ret3761 == -1)
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
test_mknod_c_0 (void)
{
  if (test_mknod_c_0_skip ()) {
    skipped ("test_mknod_c_0", "environment variable set");
    return 0;
  }

  const char *_features3765[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features3765)) {
    skipped ("test_mknod_c_0", "group %s not available in daemon",
             _features3765[0]);
    return 0;
  }

  /* InitScratchFS for test_mknod_c_0 */
  const char *_arg3767 = "/dev/sda";
  int _ret3766;
  _ret3766 = guestfs_blockdev_setrw (g, _arg3767);
  if (_ret3766 == -1)
    return -1;
  int _ret3769;
  _ret3769 = guestfs_umount_all (g);
  if (_ret3769 == -1)
    return -1;
  int _ret3771;
  _ret3771 = guestfs_lvm_remove_all (g);
  if (_ret3771 == -1)
    return -1;
  const char *_arg3774 = "/dev/sdb1";
  const char *_arg3775 = "/";
  int _ret3773;
  _ret3773 = guestfs_mount (g, _arg3774, _arg3775);
  if (_ret3773 == -1)
    return -1;

  /* TestResult for mknod_c (0) */
  const char *_arg3780 = "/mknod_c";
  int ret1;
  ret1 = guestfs_mknod_c (g, 511, 99, 66, _arg3780);
  if (ret1 == -1)
    return -1;
  const char *_arg3782 = "/mknod_c";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg3782);
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
test_mknod_b_0 (void)
{
  if (test_mknod_b_0_skip ()) {
    skipped ("test_mknod_b_0", "environment variable set");
    return 0;
  }

  const char *_features3784[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features3784)) {
    skipped ("test_mknod_b_0", "group %s not available in daemon",
             _features3784[0]);
    return 0;
  }

  /* InitScratchFS for test_mknod_b_0 */
  const char *_arg3786 = "/dev/sda";
  int _ret3785;
  _ret3785 = guestfs_blockdev_setrw (g, _arg3786);
  if (_ret3785 == -1)
    return -1;
  int _ret3788;
  _ret3788 = guestfs_umount_all (g);
  if (_ret3788 == -1)
    return -1;
  int _ret3790;
  _ret3790 = guestfs_lvm_remove_all (g);
  if (_ret3790 == -1)
    return -1;
  const char *_arg3793 = "/dev/sdb1";
  const char *_arg3794 = "/";
  int _ret3792;
  _ret3792 = guestfs_mount (g, _arg3793, _arg3794);
  if (_ret3792 == -1)
    return -1;

  /* TestResult for mknod_b (0) */
  const char *_arg3799 = "/mknod_b";
  int ret1;
  ret1 = guestfs_mknod_b (g, 511, 99, 66, _arg3799);
  if (ret1 == -1)
    return -1;
  const char *_arg3801 = "/mknod_b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg3801);
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
test_mkfifo_0 (void)
{
  if (test_mkfifo_0_skip ()) {
    skipped ("test_mkfifo_0", "environment variable set");
    return 0;
  }

  const char *_features3803[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features3803)) {
    skipped ("test_mkfifo_0", "group %s not available in daemon",
             _features3803[0]);
    return 0;
  }

  /* InitScratchFS for test_mkfifo_0 */
  const char *_arg3805 = "/dev/sda";
  int _ret3804;
  _ret3804 = guestfs_blockdev_setrw (g, _arg3805);
  if (_ret3804 == -1)
    return -1;
  int _ret3807;
  _ret3807 = guestfs_umount_all (g);
  if (_ret3807 == -1)
    return -1;
  int _ret3809;
  _ret3809 = guestfs_lvm_remove_all (g);
  if (_ret3809 == -1)
    return -1;
  const char *_arg3812 = "/dev/sdb1";
  const char *_arg3813 = "/";
  int _ret3811;
  _ret3811 = guestfs_mount (g, _arg3812, _arg3813);
  if (_ret3811 == -1)
    return -1;

  /* TestResult for mkfifo (0) */
  const char *_arg3816 = "/mkfifo";
  int ret1;
  ret1 = guestfs_mkfifo (g, 511, _arg3816);
  if (ret1 == -1)
    return -1;
  const char *_arg3818 = "/mkfifo";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg3818);
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
test_mknod_0 (void)
{
  if (test_mknod_0_skip ()) {
    skipped ("test_mknod_0", "environment variable set");
    return 0;
  }

  const char *_features3820[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features3820)) {
    skipped ("test_mknod_0", "group %s not available in daemon",
             _features3820[0]);
    return 0;
  }

  /* InitScratchFS for test_mknod_0 */
  const char *_arg3822 = "/dev/sda";
  int _ret3821;
  _ret3821 = guestfs_blockdev_setrw (g, _arg3822);
  if (_ret3821 == -1)
    return -1;
  int _ret3824;
  _ret3824 = guestfs_umount_all (g);
  if (_ret3824 == -1)
    return -1;
  int _ret3826;
  _ret3826 = guestfs_lvm_remove_all (g);
  if (_ret3826 == -1)
    return -1;
  const char *_arg3829 = "/dev/sdb1";
  const char *_arg3830 = "/";
  int _ret3828;
  _ret3828 = guestfs_mount (g, _arg3829, _arg3830);
  if (_ret3828 == -1)
    return -1;

  /* TestResult for mknod (0) */
  const char *_arg3835 = "/mknod";
  int ret1;
  ret1 = guestfs_mknod (g, 4607, 0, 0, _arg3835);
  if (ret1 == -1)
    return -1;
  const char *_arg3837 = "/mknod";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg3837);
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
test_mknod_1 (void)
{
  if (test_mknod_1_skip ()) {
    skipped ("test_mknod_1", "environment variable set");
    return 0;
  }

  const char *_features3839[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) _features3839)) {
    skipped ("test_mknod_1", "group %s not available in daemon",
             _features3839[0]);
    return 0;
  }

  /* InitScratchFS for test_mknod_1 */
  const char *_arg3841 = "/dev/sda";
  int _ret3840;
  _ret3840 = guestfs_blockdev_setrw (g, _arg3841);
  if (_ret3840 == -1)
    return -1;
  int _ret3843;
  _ret3843 = guestfs_umount_all (g);
  if (_ret3843 == -1)
    return -1;
  int _ret3845;
  _ret3845 = guestfs_lvm_remove_all (g);
  if (_ret3845 == -1)
    return -1;
  const char *_arg3848 = "/dev/sdb1";
  const char *_arg3849 = "/";
  int _ret3847;
  _ret3847 = guestfs_mount (g, _arg3848, _arg3849);
  if (_ret3847 == -1)
    return -1;

  /* TestResult for mknod (1) */
  const char *_arg3854 = "/mknod2";
  int ret1;
  ret1 = guestfs_mknod (g, 25087, 66, 99, _arg3854);
  if (ret1 == -1)
    return -1;
  const char *_arg3856 = "/mknod2";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg3856);
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
test_mkswap_U_0 (void)
{
  if (test_mkswap_U_0_skip ()) {
    skipped ("test_mkswap_U_0", "environment variable set");
    return 0;
  }

  const char *_features3858[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features3858)) {
    skipped ("test_mkswap_U_0", "group %s not available in daemon",
             _features3858[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_mkswap_U_0 */
  const char *_arg3860 = "/dev/sda";
  int _ret3859;
  _ret3859 = guestfs_blockdev_setrw (g, _arg3860);
  if (_ret3859 == -1)
    return -1;
  int _ret3862;
  _ret3862 = guestfs_umount_all (g);
  if (_ret3862 == -1)
    return -1;
  int _ret3864;
  _ret3864 = guestfs_lvm_remove_all (g);
  if (_ret3864 == -1)
    return -1;

  /* TestRun for mkswap_U (0) */
  const char *_arg3867 = "/dev/sda";
  const char *_arg3868 = "mbr";
  int _ret3866;
  _ret3866 = guestfs_part_disk (g, _arg3867, _arg3868);
  if (_ret3866 == -1)
    return -1;
  const char *_arg3871 = "fd5f5bd4-9254-0e03-76b4-43f62553291c";
  const char *_arg3872 = "/dev/sda1";
  int _ret3870;
  _ret3870 = guestfs_mkswap_U (g, _arg3871, _arg3872);
  if (_ret3870 == -1)
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
test_mkswap_L_0 (void)
{
  if (test_mkswap_L_0_skip ()) {
    skipped ("test_mkswap_L_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkswap_L_0 */
  const char *_arg3875 = "/dev/sda";
  int _ret3874;
  _ret3874 = guestfs_blockdev_setrw (g, _arg3875);
  if (_ret3874 == -1)
    return -1;
  int _ret3877;
  _ret3877 = guestfs_umount_all (g);
  if (_ret3877 == -1)
    return -1;
  int _ret3879;
  _ret3879 = guestfs_lvm_remove_all (g);
  if (_ret3879 == -1)
    return -1;

  /* TestRun for mkswap_L (0) */
  const char *_arg3882 = "/dev/sda";
  const char *_arg3883 = "mbr";
  int _ret3881;
  _ret3881 = guestfs_part_disk (g, _arg3882, _arg3883);
  if (_ret3881 == -1)
    return -1;
  const char *_arg3886 = "hello";
  const char *_arg3887 = "/dev/sda1";
  int _ret3885;
  _ret3885 = guestfs_mkswap_L (g, _arg3886, _arg3887);
  if (_ret3885 == -1)
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
test_mkswap_0 (void)
{
  if (test_mkswap_0_skip ()) {
    skipped ("test_mkswap_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkswap_0 */
  const char *_arg3890 = "/dev/sda";
  int _ret3889;
  _ret3889 = guestfs_blockdev_setrw (g, _arg3890);
  if (_ret3889 == -1)
    return -1;
  int _ret3892;
  _ret3892 = guestfs_umount_all (g);
  if (_ret3892 == -1)
    return -1;
  int _ret3894;
  _ret3894 = guestfs_lvm_remove_all (g);
  if (_ret3894 == -1)
    return -1;

  /* TestRun for mkswap (0) */
  const char *_arg3897 = "/dev/sda";
  const char *_arg3898 = "mbr";
  int _ret3896;
  _ret3896 = guestfs_part_disk (g, _arg3897, _arg3898);
  if (_ret3896 == -1)
    return -1;
  const char *_arg3901 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs3902;
  _optargs3902.bitmask = UINT64_C(0x0);
  int _ret3900;
  _ret3900 = guestfs_mkswap_opts_argv (g, _arg3901, &_optargs3902);
  if (_ret3900 == -1)
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
test_mkswap_1 (void)
{
  if (test_mkswap_1_skip ()) {
    skipped ("test_mkswap_1", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkswap_1 */
  const char *_arg3904 = "/dev/sda";
  int _ret3903;
  _ret3903 = guestfs_blockdev_setrw (g, _arg3904);
  if (_ret3903 == -1)
    return -1;
  int _ret3906;
  _ret3906 = guestfs_umount_all (g);
  if (_ret3906 == -1)
    return -1;
  int _ret3908;
  _ret3908 = guestfs_lvm_remove_all (g);
  if (_ret3908 == -1)
    return -1;

  /* TestRun for mkswap (1) */
  const char *_arg3911 = "/dev/sda";
  const char *_arg3912 = "mbr";
  int _ret3910;
  _ret3910 = guestfs_part_disk (g, _arg3911, _arg3912);
  if (_ret3910 == -1)
    return -1;
  const char *_arg3915 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs3916;
  _optargs3916.label = "hello";
  _optargs3916.bitmask = UINT64_C(0x1);
  int _ret3914;
  _ret3914 = guestfs_mkswap_opts_argv (g, _arg3915, &_optargs3916);
  if (_ret3914 == -1)
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
test_mkswap_2 (void)
{
  if (test_mkswap_2_skip ()) {
    skipped ("test_mkswap_2", "environment variable set");
    return 0;
  }

  const char *_features3917[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features3917)) {
    skipped ("test_mkswap_2", "group %s not available in daemon",
             _features3917[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_mkswap_2 */
  const char *_arg3919 = "/dev/sda";
  int _ret3918;
  _ret3918 = guestfs_blockdev_setrw (g, _arg3919);
  if (_ret3918 == -1)
    return -1;
  int _ret3921;
  _ret3921 = guestfs_umount_all (g);
  if (_ret3921 == -1)
    return -1;
  int _ret3923;
  _ret3923 = guestfs_lvm_remove_all (g);
  if (_ret3923 == -1)
    return -1;

  /* TestRun for mkswap (2) */
  const char *_arg3926 = "/dev/sda";
  const char *_arg3927 = "mbr";
  int _ret3925;
  _ret3925 = guestfs_part_disk (g, _arg3926, _arg3927);
  if (_ret3925 == -1)
    return -1;
  const char *_arg3930 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs3931;
  _optargs3931.uuid = "fd5f5bd4-9254-0e03-76b4-43f62553291c";
  _optargs3931.bitmask = UINT64_C(0x2);
  int _ret3929;
  _ret3929 = guestfs_mkswap_opts_argv (g, _arg3930, &_optargs3931);
  if (_ret3929 == -1)
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
test_mkswap_3 (void)
{
  if (test_mkswap_3_skip ()) {
    skipped ("test_mkswap_3", "environment variable set");
    return 0;
  }

  const char *_features3932[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) _features3932)) {
    skipped ("test_mkswap_3", "group %s not available in daemon",
             _features3932[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_mkswap_3 */
  const char *_arg3934 = "/dev/sda";
  int _ret3933;
  _ret3933 = guestfs_blockdev_setrw (g, _arg3934);
  if (_ret3933 == -1)
    return -1;
  int _ret3936;
  _ret3936 = guestfs_umount_all (g);
  if (_ret3936 == -1)
    return -1;
  int _ret3938;
  _ret3938 = guestfs_lvm_remove_all (g);
  if (_ret3938 == -1)
    return -1;

  /* TestRun for mkswap (3) */
  const char *_arg3941 = "/dev/sda";
  const char *_arg3942 = "mbr";
  int _ret3940;
  _ret3940 = guestfs_part_disk (g, _arg3941, _arg3942);
  if (_ret3940 == -1)
    return -1;
  const char *_arg3945 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv _optargs3946;
  _optargs3946.label = "hello";
  _optargs3946.uuid = "fd5f5bd4-9254-0e03-76b4-43f62553291c";
  _optargs3946.bitmask = UINT64_C(0x3);
  int _ret3944;
  _ret3944 = guestfs_mkswap_opts_argv (g, _arg3945, &_optargs3946);
  if (_ret3944 == -1)
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
test_initrd_list_0 (void)
{
  if (test_initrd_list_0_skip ()) {
    skipped ("test_initrd_list_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_initrd_list_0 */
  const char *_arg3948 = "/dev/sda";
  int _ret3947;
  _ret3947 = guestfs_blockdev_setrw (g, _arg3948);
  if (_ret3947 == -1)
    return -1;
  int _ret3950;
  _ret3950 = guestfs_umount_all (g);
  if (_ret3950 == -1)
    return -1;
  int _ret3952;
  _ret3952 = guestfs_lvm_remove_all (g);
  if (_ret3952 == -1)
    return -1;
  const char *_arg3955 = "/dev/sdd";
  const char *_arg3956 = "/";
  int _ret3954;
  _ret3954 = guestfs_mount_ro (g, _arg3955, _arg3956);
  if (_ret3954 == -1)
    return -1;

  /* TestResult for initrd_list (0) */
  const char *_arg3958 = "/initrd";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_initrd_list (g, _arg3958);
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
test_du_0 (void)
{
  if (test_du_0_skip ()) {
    skipped ("test_du_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_du_0 */
  const char *_arg3961 = "/dev/sda";
  int _ret3960;
  _ret3960 = guestfs_blockdev_setrw (g, _arg3961);
  if (_ret3960 == -1)
    return -1;
  int _ret3963;
  _ret3963 = guestfs_umount_all (g);
  if (_ret3963 == -1)
    return -1;
  int _ret3965;
  _ret3965 = guestfs_lvm_remove_all (g);
  if (_ret3965 == -1)
    return -1;
  const char *_arg3968 = "/dev/sdd";
  const char *_arg3969 = "/";
  int _ret3967;
  _ret3967 = guestfs_mount_ro (g, _arg3968, _arg3969);
  if (_ret3967 == -1)
    return -1;

  /* TestResult for du (0) */
  const char *_arg3971 = "/directory";
  int64_t ret;
  ret = guestfs_du (g, _arg3971);
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
test_tail_n_0 (void)
{
  if (test_tail_n_0_skip ()) {
    skipped ("test_tail_n_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_tail_n_0 */
  const char *_arg3974 = "/dev/sda";
  int _ret3973;
  _ret3973 = guestfs_blockdev_setrw (g, _arg3974);
  if (_ret3973 == -1)
    return -1;
  int _ret3976;
  _ret3976 = guestfs_umount_all (g);
  if (_ret3976 == -1)
    return -1;
  int _ret3978;
  _ret3978 = guestfs_lvm_remove_all (g);
  if (_ret3978 == -1)
    return -1;
  const char *_arg3981 = "/dev/sdd";
  const char *_arg3982 = "/";
  int _ret3980;
  _ret3980 = guestfs_mount_ro (g, _arg3981, _arg3982);
  if (_ret3980 == -1)
    return -1;

  /* TestResult for tail_n (0) */
  const char *_arg3985 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, 3, _arg3985);
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
test_tail_n_1 (void)
{
  if (test_tail_n_1_skip ()) {
    skipped ("test_tail_n_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_tail_n_1 */
  const char *_arg3988 = "/dev/sda";
  int _ret3987;
  _ret3987 = guestfs_blockdev_setrw (g, _arg3988);
  if (_ret3987 == -1)
    return -1;
  int _ret3990;
  _ret3990 = guestfs_umount_all (g);
  if (_ret3990 == -1)
    return -1;
  int _ret3992;
  _ret3992 = guestfs_lvm_remove_all (g);
  if (_ret3992 == -1)
    return -1;
  const char *_arg3995 = "/dev/sdd";
  const char *_arg3996 = "/";
  int _ret3994;
  _ret3994 = guestfs_mount_ro (g, _arg3995, _arg3996);
  if (_ret3994 == -1)
    return -1;

  /* TestResult for tail_n (1) */
  const char *_arg3999 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, -9998, _arg3999);
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
test_tail_n_2 (void)
{
  if (test_tail_n_2_skip ()) {
    skipped ("test_tail_n_2", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_tail_n_2 */
  const char *_arg4002 = "/dev/sda";
  int _ret4001;
  _ret4001 = guestfs_blockdev_setrw (g, _arg4002);
  if (_ret4001 == -1)
    return -1;
  int _ret4004;
  _ret4004 = guestfs_umount_all (g);
  if (_ret4004 == -1)
    return -1;
  int _ret4006;
  _ret4006 = guestfs_lvm_remove_all (g);
  if (_ret4006 == -1)
    return -1;
  const char *_arg4009 = "/dev/sdd";
  const char *_arg4010 = "/";
  int _ret4008;
  _ret4008 = guestfs_mount_ro (g, _arg4009, _arg4010);
  if (_ret4008 == -1)
    return -1;

  /* TestResult for tail_n (2) */
  const char *_arg4013 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, 0, _arg4013);
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
test_tail_0 (void)
{
  if (test_tail_0_skip ()) {
    skipped ("test_tail_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_tail_0 */
  const char *_arg4016 = "/dev/sda";
  int _ret4015;
  _ret4015 = guestfs_blockdev_setrw (g, _arg4016);
  if (_ret4015 == -1)
    return -1;
  int _ret4018;
  _ret4018 = guestfs_umount_all (g);
  if (_ret4018 == -1)
    return -1;
  int _ret4020;
  _ret4020 = guestfs_lvm_remove_all (g);
  if (_ret4020 == -1)
    return -1;
  const char *_arg4023 = "/dev/sdd";
  const char *_arg4024 = "/";
  int _ret4022;
  _ret4022 = guestfs_mount_ro (g, _arg4023, _arg4024);
  if (_ret4022 == -1)
    return -1;

  /* TestResult for tail (0) */
  const char *_arg4026 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail (g, _arg4026);
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
test_head_n_0 (void)
{
  if (test_head_n_0_skip ()) {
    skipped ("test_head_n_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_head_n_0 */
  const char *_arg4029 = "/dev/sda";
  int _ret4028;
  _ret4028 = guestfs_blockdev_setrw (g, _arg4029);
  if (_ret4028 == -1)
    return -1;
  int _ret4031;
  _ret4031 = guestfs_umount_all (g);
  if (_ret4031 == -1)
    return -1;
  int _ret4033;
  _ret4033 = guestfs_lvm_remove_all (g);
  if (_ret4033 == -1)
    return -1;
  const char *_arg4036 = "/dev/sdd";
  const char *_arg4037 = "/";
  int _ret4035;
  _ret4035 = guestfs_mount_ro (g, _arg4036, _arg4037);
  if (_ret4035 == -1)
    return -1;

  /* TestResult for head_n (0) */
  const char *_arg4040 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, 3, _arg4040);
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
test_head_n_1 (void)
{
  if (test_head_n_1_skip ()) {
    skipped ("test_head_n_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_head_n_1 */
  const char *_arg4043 = "/dev/sda";
  int _ret4042;
  _ret4042 = guestfs_blockdev_setrw (g, _arg4043);
  if (_ret4042 == -1)
    return -1;
  int _ret4045;
  _ret4045 = guestfs_umount_all (g);
  if (_ret4045 == -1)
    return -1;
  int _ret4047;
  _ret4047 = guestfs_lvm_remove_all (g);
  if (_ret4047 == -1)
    return -1;
  const char *_arg4050 = "/dev/sdd";
  const char *_arg4051 = "/";
  int _ret4049;
  _ret4049 = guestfs_mount_ro (g, _arg4050, _arg4051);
  if (_ret4049 == -1)
    return -1;

  /* TestResult for head_n (1) */
  const char *_arg4054 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, -9997, _arg4054);
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
test_head_n_2 (void)
{
  if (test_head_n_2_skip ()) {
    skipped ("test_head_n_2", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_head_n_2 */
  const char *_arg4057 = "/dev/sda";
  int _ret4056;
  _ret4056 = guestfs_blockdev_setrw (g, _arg4057);
  if (_ret4056 == -1)
    return -1;
  int _ret4059;
  _ret4059 = guestfs_umount_all (g);
  if (_ret4059 == -1)
    return -1;
  int _ret4061;
  _ret4061 = guestfs_lvm_remove_all (g);
  if (_ret4061 == -1)
    return -1;
  const char *_arg4064 = "/dev/sdd";
  const char *_arg4065 = "/";
  int _ret4063;
  _ret4063 = guestfs_mount_ro (g, _arg4064, _arg4065);
  if (_ret4063 == -1)
    return -1;

  /* TestResult for head_n (2) */
  const char *_arg4068 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, 0, _arg4068);
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
test_head_0 (void)
{
  if (test_head_0_skip ()) {
    skipped ("test_head_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_head_0 */
  const char *_arg4071 = "/dev/sda";
  int _ret4070;
  _ret4070 = guestfs_blockdev_setrw (g, _arg4071);
  if (_ret4070 == -1)
    return -1;
  int _ret4073;
  _ret4073 = guestfs_umount_all (g);
  if (_ret4073 == -1)
    return -1;
  int _ret4075;
  _ret4075 = guestfs_lvm_remove_all (g);
  if (_ret4075 == -1)
    return -1;
  const char *_arg4078 = "/dev/sdd";
  const char *_arg4079 = "/";
  int _ret4077;
  _ret4077 = guestfs_mount_ro (g, _arg4078, _arg4079);
  if (_ret4077 == -1)
    return -1;

  /* TestResult for head (0) */
  const char *_arg4081 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head (g, _arg4081);
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
test_head_1 (void)
{
  if (test_head_1_skip ()) {
    skipped ("test_head_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_head_1 */
  const char *_arg4084 = "/dev/sda";
  int _ret4083;
  _ret4083 = guestfs_blockdev_setrw (g, _arg4084);
  if (_ret4083 == -1)
    return -1;
  int _ret4086;
  _ret4086 = guestfs_umount_all (g);
  if (_ret4086 == -1)
    return -1;
  int _ret4088;
  _ret4088 = guestfs_lvm_remove_all (g);
  if (_ret4088 == -1)
    return -1;
  const char *_arg4091 = "/dev/sdd";
  const char *_arg4092 = "/";
  int _ret4090;
  _ret4090 = guestfs_mount_ro (g, _arg4091, _arg4092);
  if (_ret4090 == -1)
    return -1;

  /* TestResult for head (1) */
  const char *_arg4094 = "/abssymlink";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head (g, _arg4094);
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
test_wc_c_0 (void)
{
  if (test_wc_c_0_skip ()) {
    skipped ("test_wc_c_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_wc_c_0 */
  const char *_arg4097 = "/dev/sda";
  int _ret4096;
  _ret4096 = guestfs_blockdev_setrw (g, _arg4097);
  if (_ret4096 == -1)
    return -1;
  int _ret4099;
  _ret4099 = guestfs_umount_all (g);
  if (_ret4099 == -1)
    return -1;
  int _ret4101;
  _ret4101 = guestfs_lvm_remove_all (g);
  if (_ret4101 == -1)
    return -1;
  const char *_arg4104 = "/dev/sdd";
  const char *_arg4105 = "/";
  int _ret4103;
  _ret4103 = guestfs_mount_ro (g, _arg4104, _arg4105);
  if (_ret4103 == -1)
    return -1;

  /* TestResult for wc_c (0) */
  const char *_arg4107 = "/100kallspaces";
  int ret;
  ret = guestfs_wc_c (g, _arg4107);
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
test_wc_w_0 (void)
{
  if (test_wc_w_0_skip ()) {
    skipped ("test_wc_w_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_wc_w_0 */
  const char *_arg4110 = "/dev/sda";
  int _ret4109;
  _ret4109 = guestfs_blockdev_setrw (g, _arg4110);
  if (_ret4109 == -1)
    return -1;
  int _ret4112;
  _ret4112 = guestfs_umount_all (g);
  if (_ret4112 == -1)
    return -1;
  int _ret4114;
  _ret4114 = guestfs_lvm_remove_all (g);
  if (_ret4114 == -1)
    return -1;
  const char *_arg4117 = "/dev/sdd";
  const char *_arg4118 = "/";
  int _ret4116;
  _ret4116 = guestfs_mount_ro (g, _arg4117, _arg4118);
  if (_ret4116 == -1)
    return -1;

  /* TestResult for wc_w (0) */
  const char *_arg4120 = "/10klines";
  int ret;
  ret = guestfs_wc_w (g, _arg4120);
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
test_wc_l_0 (void)
{
  if (test_wc_l_0_skip ()) {
    skipped ("test_wc_l_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_wc_l_0 */
  const char *_arg4123 = "/dev/sda";
  int _ret4122;
  _ret4122 = guestfs_blockdev_setrw (g, _arg4123);
  if (_ret4122 == -1)
    return -1;
  int _ret4125;
  _ret4125 = guestfs_umount_all (g);
  if (_ret4125 == -1)
    return -1;
  int _ret4127;
  _ret4127 = guestfs_lvm_remove_all (g);
  if (_ret4127 == -1)
    return -1;
  const char *_arg4130 = "/dev/sdd";
  const char *_arg4131 = "/";
  int _ret4129;
  _ret4129 = guestfs_mount_ro (g, _arg4130, _arg4131);
  if (_ret4129 == -1)
    return -1;

  /* TestResult for wc_l (0) */
  const char *_arg4133 = "/10klines";
  int ret;
  ret = guestfs_wc_l (g, _arg4133);
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
test_wc_l_1 (void)
{
  if (test_wc_l_1_skip ()) {
    skipped ("test_wc_l_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_wc_l_1 */
  const char *_arg4136 = "/dev/sda";
  int _ret4135;
  _ret4135 = guestfs_blockdev_setrw (g, _arg4136);
  if (_ret4135 == -1)
    return -1;
  int _ret4138;
  _ret4138 = guestfs_umount_all (g);
  if (_ret4138 == -1)
    return -1;
  int _ret4140;
  _ret4140 = guestfs_lvm_remove_all (g);
  if (_ret4140 == -1)
    return -1;
  const char *_arg4143 = "/dev/sdd";
  const char *_arg4144 = "/";
  int _ret4142;
  _ret4142 = guestfs_mount_ro (g, _arg4143, _arg4144);
  if (_ret4142 == -1)
    return -1;

  /* TestResult for wc_l (1) */
  const char *_arg4146 = "/abssymlink";
  int ret;
  ret = guestfs_wc_l (g, _arg4146);
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
test_mkdtemp_0 (void)
{
  if (test_mkdtemp_0_skip ()) {
    skipped ("test_mkdtemp_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mkdtemp_0 */
  const char *_arg4149 = "/dev/sda";
  int _ret4148;
  _ret4148 = guestfs_blockdev_setrw (g, _arg4149);
  if (_ret4148 == -1)
    return -1;
  int _ret4151;
  _ret4151 = guestfs_umount_all (g);
  if (_ret4151 == -1)
    return -1;
  int _ret4153;
  _ret4153 = guestfs_lvm_remove_all (g);
  if (_ret4153 == -1)
    return -1;
  const char *_arg4156 = "/dev/sdb1";
  const char *_arg4157 = "/";
  int _ret4155;
  _ret4155 = guestfs_mount (g, _arg4156, _arg4157);
  if (_ret4155 == -1)
    return -1;

  /* TestRun for mkdtemp (0) */
  const char *_arg4160 = "/mkdtemp";
  int _ret4159;
  _ret4159 = guestfs_mkdir (g, _arg4160);
  if (_ret4159 == -1)
    return -1;
  const char *_arg4163 = "/mkdtemp/tmpXXXXXX";
  CLEANUP_FREE char *_ret4162;
  _ret4162 = guestfs_mkdtemp (g, _arg4163);
  if (_ret4162 == NULL)
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
test_scrub_file_0 (void)
{
  if (test_scrub_file_0_skip ()) {
    skipped ("test_scrub_file_0", "environment variable set");
    return 0;
  }

  const char *_features4165[] = { "scrub", NULL };
  if (!guestfs_feature_available (g, (char **) _features4165)) {
    skipped ("test_scrub_file_0", "group %s not available in daemon",
             _features4165[0]);
    return 0;
  }

  /* InitScratchFS for test_scrub_file_0 */
  const char *_arg4167 = "/dev/sda";
  int _ret4166;
  _ret4166 = guestfs_blockdev_setrw (g, _arg4167);
  if (_ret4166 == -1)
    return -1;
  int _ret4169;
  _ret4169 = guestfs_umount_all (g);
  if (_ret4169 == -1)
    return -1;
  int _ret4171;
  _ret4171 = guestfs_lvm_remove_all (g);
  if (_ret4171 == -1)
    return -1;
  const char *_arg4174 = "/dev/sdb1";
  const char *_arg4175 = "/";
  int _ret4173;
  _ret4173 = guestfs_mount (g, _arg4174, _arg4175);
  if (_ret4173 == -1)
    return -1;

  /* TestRun for scrub_file (0) */
  const char *_arg4178 = "/scrub_file";
  const char *_arg4179 = "content";
  size_t _arg4179_size = 7;
  int _ret4177;
  _ret4177 = guestfs_write (g, _arg4178, _arg4179, _arg4179_size);
  if (_ret4177 == -1)
    return -1;
  const char *_arg4182 = "/scrub_file";
  int _ret4181;
  _ret4181 = guestfs_scrub_file (g, _arg4182);
  if (_ret4181 == -1)
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
test_scrub_device_0 (void)
{
  if (test_scrub_device_0_skip ()) {
    skipped ("test_scrub_device_0", "environment variable set");
    return 0;
  }

  const char *_features4184[] = { "scrub", NULL };
  if (!guestfs_feature_available (g, (char **) _features4184)) {
    skipped ("test_scrub_device_0", "group %s not available in daemon",
             _features4184[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_scrub_device_0 */
  const char *_arg4186 = "/dev/sda";
  int _ret4185;
  _ret4185 = guestfs_blockdev_setrw (g, _arg4186);
  if (_ret4185 == -1)
    return -1;
  int _ret4188;
  _ret4188 = guestfs_umount_all (g);
  if (_ret4188 == -1)
    return -1;
  int _ret4190;
  _ret4190 = guestfs_lvm_remove_all (g);
  if (_ret4190 == -1)
    return -1;

  /* TestRun for scrub_device (0) */
  const char *_arg4193 = "/dev/sdc";
  int _ret4192;
  _ret4192 = guestfs_scrub_device (g, _arg4193);
  if (_ret4192 == -1)
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
test_glob_expand_0 (void)
{
  if (test_glob_expand_0_skip ()) {
    skipped ("test_glob_expand_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_glob_expand_0 */
  const char *_arg4196 = "/dev/sda";
  int _ret4195;
  _ret4195 = guestfs_blockdev_setrw (g, _arg4196);
  if (_ret4195 == -1)
    return -1;
  int _ret4198;
  _ret4198 = guestfs_umount_all (g);
  if (_ret4198 == -1)
    return -1;
  int _ret4200;
  _ret4200 = guestfs_lvm_remove_all (g);
  if (_ret4200 == -1)
    return -1;
  const char *_arg4203 = "/dev/sdb1";
  const char *_arg4204 = "/";
  int _ret4202;
  _ret4202 = guestfs_mount (g, _arg4203, _arg4204);
  if (_ret4202 == -1)
    return -1;

  /* TestResult for glob_expand (0) */
  const char *_arg4206 = "/glob_expand/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, _arg4206);
  if (ret3 == -1)
    return -1;
  const char *_arg4208 = "/glob_expand/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, _arg4208);
  if (ret2 == -1)
    return -1;
  const char *_arg4210 = "/glob_expand/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, _arg4210);
  if (ret1 == -1)
    return -1;
  const char *_arg4212 = "/glob_expand/b/c/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, _arg4212);
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
test_glob_expand_1 (void)
{
  if (test_glob_expand_1_skip ()) {
    skipped ("test_glob_expand_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_glob_expand_1 */
  const char *_arg4215 = "/dev/sda";
  int _ret4214;
  _ret4214 = guestfs_blockdev_setrw (g, _arg4215);
  if (_ret4214 == -1)
    return -1;
  int _ret4217;
  _ret4217 = guestfs_umount_all (g);
  if (_ret4217 == -1)
    return -1;
  int _ret4219;
  _ret4219 = guestfs_lvm_remove_all (g);
  if (_ret4219 == -1)
    return -1;
  const char *_arg4222 = "/dev/sdb1";
  const char *_arg4223 = "/";
  int _ret4221;
  _ret4221 = guestfs_mount (g, _arg4222, _arg4223);
  if (_ret4221 == -1)
    return -1;

  /* TestResult for glob_expand (1) */
  const char *_arg4225 = "/glob_expand2/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, _arg4225);
  if (ret3 == -1)
    return -1;
  const char *_arg4227 = "/glob_expand2/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, _arg4227);
  if (ret2 == -1)
    return -1;
  const char *_arg4229 = "/glob_expand2/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, _arg4229);
  if (ret1 == -1)
    return -1;
  const char *_arg4231 = "/glob_expand2/*/c/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, _arg4231);
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
test_glob_expand_2 (void)
{
  if (test_glob_expand_2_skip ()) {
    skipped ("test_glob_expand_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_glob_expand_2 */
  const char *_arg4234 = "/dev/sda";
  int _ret4233;
  _ret4233 = guestfs_blockdev_setrw (g, _arg4234);
  if (_ret4233 == -1)
    return -1;
  int _ret4236;
  _ret4236 = guestfs_umount_all (g);
  if (_ret4236 == -1)
    return -1;
  int _ret4238;
  _ret4238 = guestfs_lvm_remove_all (g);
  if (_ret4238 == -1)
    return -1;
  const char *_arg4241 = "/dev/sdb1";
  const char *_arg4242 = "/";
  int _ret4240;
  _ret4240 = guestfs_mount (g, _arg4241, _arg4242);
  if (_ret4240 == -1)
    return -1;

  /* TestResult for glob_expand (2) */
  const char *_arg4244 = "/glob_expand3/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, _arg4244);
  if (ret3 == -1)
    return -1;
  const char *_arg4246 = "/glob_expand3/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, _arg4246);
  if (ret2 == -1)
    return -1;
  const char *_arg4248 = "/glob_expand3/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, _arg4248);
  if (ret1 == -1)
    return -1;
  const char *_arg4250 = "/glob_expand3/*/x/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, _arg4250);
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
test_ntfs_3g_probe_0 (void)
{
  if (test_ntfs_3g_probe_0_skip ()) {
    skipped ("test_ntfs_3g_probe_0", "environment variable set");
    return 0;
  }

  const char *_features4252[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features4252)) {
    skipped ("test_ntfs_3g_probe_0", "group %s not available in daemon",
             _features4252[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_ntfs_3g_probe_0 */
  const char *_arg4254 = "/dev/sda";
  int _ret4253;
  _ret4253 = guestfs_blockdev_setrw (g, _arg4254);
  if (_ret4253 == -1)
    return -1;
  int _ret4256;
  _ret4256 = guestfs_umount_all (g);
  if (_ret4256 == -1)
    return -1;
  int _ret4258;
  _ret4258 = guestfs_lvm_remove_all (g);
  if (_ret4258 == -1)
    return -1;

  /* TestResult for ntfs_3g_probe (0) */
  const char *_arg4260 = "/dev/sda";
  const char *_arg4261 = "mbr";
  int ret2;
  ret2 = guestfs_part_disk (g, _arg4260, _arg4261);
  if (ret2 == -1)
    return -1;
  const char *_arg4263 = "ntfs";
  const char *_arg4264 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs4265;
  _optargs4265.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_mkfs_opts_argv (g, _arg4263, _arg4264, &_optargs4265);
  if (ret1 == -1)
    return -1;
  const char *_arg4267 = "/dev/sda1";
  int ret;
  ret = guestfs_ntfs_3g_probe (g, 1, _arg4267);
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
test_ntfs_3g_probe_1 (void)
{
  if (test_ntfs_3g_probe_1_skip ()) {
    skipped ("test_ntfs_3g_probe_1", "environment variable set");
    return 0;
  }

  const char *_features4269[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) _features4269)) {
    skipped ("test_ntfs_3g_probe_1", "group %s not available in daemon",
             _features4269[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_ntfs_3g_probe_1 */
  const char *_arg4271 = "/dev/sda";
  int _ret4270;
  _ret4270 = guestfs_blockdev_setrw (g, _arg4271);
  if (_ret4270 == -1)
    return -1;
  int _ret4273;
  _ret4273 = guestfs_umount_all (g);
  if (_ret4273 == -1)
    return -1;
  int _ret4275;
  _ret4275 = guestfs_lvm_remove_all (g);
  if (_ret4275 == -1)
    return -1;

  /* TestResult for ntfs_3g_probe (1) */
  const char *_arg4277 = "/dev/sda";
  const char *_arg4278 = "mbr";
  int ret2;
  ret2 = guestfs_part_disk (g, _arg4277, _arg4278);
  if (ret2 == -1)
    return -1;
  const char *_arg4280 = "ext2";
  const char *_arg4281 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs4282;
  _optargs4282.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_mkfs_opts_argv (g, _arg4280, _arg4281, &_optargs4282);
  if (ret1 == -1)
    return -1;
  const char *_arg4284 = "/dev/sda1";
  int ret;
  ret = guestfs_ntfs_3g_probe (g, 1, _arg4284);
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
test_sleep_0 (void)
{
  if (test_sleep_0_skip ()) {
    skipped ("test_sleep_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_sleep_0 */
  const char *_arg4287 = "/dev/sda";
  int _ret4286;
  _ret4286 = guestfs_blockdev_setrw (g, _arg4287);
  if (_ret4286 == -1)
    return -1;
  int _ret4289;
  _ret4289 = guestfs_umount_all (g);
  if (_ret4289 == -1)
    return -1;
  int _ret4291;
  _ret4291 = guestfs_lvm_remove_all (g);
  if (_ret4291 == -1)
    return -1;

  /* TestRun for sleep (0) */
  int _ret4293;
  _ret4293 = guestfs_sleep (g, 1);
  if (_ret4293 == -1)
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
test_lvresize_0 (void)
{
  if (test_lvresize_0_skip ()) {
    skipped ("test_lvresize_0", "environment variable set");
    return 0;
  }

  const char *_features4296[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features4296)) {
    skipped ("test_lvresize_0", "group %s not available in daemon",
             _features4296[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_lvresize_0 */
  const char *_arg4298 = "/dev/sda";
  int _ret4297;
  _ret4297 = guestfs_blockdev_setrw (g, _arg4298);
  if (_ret4297 == -1)
    return -1;
  int _ret4300;
  _ret4300 = guestfs_umount_all (g);
  if (_ret4300 == -1)
    return -1;
  int _ret4302;
  _ret4302 = guestfs_lvm_remove_all (g);
  if (_ret4302 == -1)
    return -1;

  /* TestResultString for lvresize (0) */
  const char *_arg4305 = "/dev/sda";
  const char *_arg4306 = "mbr";
  int _ret4304;
  _ret4304 = guestfs_part_disk (g, _arg4305, _arg4306);
  if (_ret4304 == -1)
    return -1;
  const char *_arg4309 = "/dev/sda1";
  int _ret4308;
  _ret4308 = guestfs_pvcreate (g, _arg4309);
  if (_ret4308 == -1)
    return -1;
  const char *_arg4312 = "VG";
  const char *_arg4313_0 = "/dev/sda1";
  const char *const _arg4313[] = {
    _arg4313_0,
    NULL
  };
  int _ret4311;
  _ret4311 = guestfs_vgcreate (g, _arg4312, (char **) _arg4313);
  if (_ret4311 == -1)
    return -1;
  const char *_arg4316 = "LV";
  const char *_arg4317 = "VG";
  int _ret4315;
  _ret4315 = guestfs_lvcreate (g, _arg4316, _arg4317, 10);
  if (_ret4315 == -1)
    return -1;
  const char *_arg4321 = "ext2";
  const char *_arg4322 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs4323;
  _optargs4323.bitmask = UINT64_C(0x0);
  int _ret4320;
  _ret4320 = guestfs_mkfs_opts_argv (g, _arg4321, _arg4322, &_optargs4323);
  if (_ret4320 == -1)
    return -1;
  const char *_arg4325 = "/dev/VG/LV";
  const char *_arg4326 = "/";
  int _ret4324;
  _ret4324 = guestfs_mount (g, _arg4325, _arg4326);
  if (_ret4324 == -1)
    return -1;
  const char *_arg4329 = "/new";
  const char *_arg4330 = "test content";
  size_t _arg4330_size = 12;
  int _ret4328;
  _ret4328 = guestfs_write (g, _arg4329, _arg4330, _arg4330_size);
  if (_ret4328 == -1)
    return -1;
  const char *_arg4333 = "/";
  struct guestfs_umount_opts_argv _optargs4334;
  _optargs4334.force = 0;
  _optargs4334.lazyunmount = 0;
  _optargs4334.bitmask = UINT64_C(0x3);
  int _ret4332;
  _ret4332 = guestfs_umount_opts_argv (g, _arg4333, &_optargs4334);
  if (_ret4332 == -1)
    return -1;
  const char *_arg4336 = "/dev/VG/LV";
  int _ret4335;
  _ret4335 = guestfs_lvresize (g, _arg4336, 20);
  if (_ret4335 == -1)
    return -1;
  const char *_arg4340 = "/dev/VG/LV";
  int _ret4339;
  _ret4339 = guestfs_e2fsck_f (g, _arg4340);
  if (_ret4339 == -1)
    return -1;
  const char *_arg4343 = "/dev/VG/LV";
  struct guestfs_e2fsck_argv _optargs4344;
  _optargs4344.correct = 1;
  _optargs4344.forceall = 0;
  _optargs4344.bitmask = UINT64_C(0x3);
  int _ret4342;
  _ret4342 = guestfs_e2fsck_argv (g, _arg4343, &_optargs4344);
  if (_ret4342 == -1)
    return -1;
  const char *_arg4346 = "/dev/VG/LV";
  struct guestfs_e2fsck_argv _optargs4347;
  _optargs4347.correct = 0;
  _optargs4347.forceall = 1;
  _optargs4347.bitmask = UINT64_C(0x3);
  int _ret4345;
  _ret4345 = guestfs_e2fsck_argv (g, _arg4346, &_optargs4347);
  if (_ret4345 == -1)
    return -1;
  const char *_arg4349 = "/dev/VG/LV";
  int _ret4348;
  _ret4348 = guestfs_resize2fs (g, _arg4349);
  if (_ret4348 == -1)
    return -1;
  const char *_arg4352 = "/dev/VG/LV";
  const char *_arg4353 = "/";
  int _ret4351;
  _ret4351 = guestfs_mount (g, _arg4352, _arg4353);
  if (_ret4351 == -1)
    return -1;
  const char *_arg4355 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg4355);
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
test_lvresize_1 (void)
{
  if (test_lvresize_1_skip ()) {
    skipped ("test_lvresize_1", "environment variable set");
    return 0;
  }

  const char *_features4357[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features4357)) {
    skipped ("test_lvresize_1", "group %s not available in daemon",
             _features4357[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_lvresize_1 */
  const char *_arg4359 = "/dev/sda";
  int _ret4358;
  _ret4358 = guestfs_blockdev_setrw (g, _arg4359);
  if (_ret4358 == -1)
    return -1;
  int _ret4361;
  _ret4361 = guestfs_umount_all (g);
  if (_ret4361 == -1)
    return -1;
  int _ret4363;
  _ret4363 = guestfs_lvm_remove_all (g);
  if (_ret4363 == -1)
    return -1;

  /* TestRun for lvresize (1) */
  const char *_arg4366 = "/dev/sda";
  const char *_arg4367 = "mbr";
  int _ret4365;
  _ret4365 = guestfs_part_disk (g, _arg4366, _arg4367);
  if (_ret4365 == -1)
    return -1;
  const char *_arg4370 = "/dev/sda1";
  int _ret4369;
  _ret4369 = guestfs_pvcreate (g, _arg4370);
  if (_ret4369 == -1)
    return -1;
  const char *_arg4373 = "VG";
  const char *_arg4374_0 = "/dev/sda1";
  const char *const _arg4374[] = {
    _arg4374_0,
    NULL
  };
  int _ret4372;
  _ret4372 = guestfs_vgcreate (g, _arg4373, (char **) _arg4374);
  if (_ret4372 == -1)
    return -1;
  const char *_arg4377 = "LV";
  const char *_arg4378 = "VG";
  int _ret4376;
  _ret4376 = guestfs_lvcreate (g, _arg4377, _arg4378, 20);
  if (_ret4376 == -1)
    return -1;
  const char *_arg4382 = "/dev/VG/LV";
  int _ret4381;
  _ret4381 = guestfs_lvresize (g, _arg4382, 10);
  if (_ret4381 == -1)
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
test_zerofree_0 (void)
{
  if (test_zerofree_0_skip ()) {
    skipped ("test_zerofree_0", "environment variable set");
    return 0;
  }

  const char *_features4385[] = { "zerofree", NULL };
  if (!guestfs_feature_available (g, (char **) _features4385)) {
    skipped ("test_zerofree_0", "group %s not available in daemon",
             _features4385[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_zerofree_0 */
  const char *_arg4387 = "/dev/sda";
  int _ret4386;
  _ret4386 = guestfs_blockdev_setrw (g, _arg4387);
  if (_ret4386 == -1)
    return -1;
  int _ret4389;
  _ret4389 = guestfs_umount_all (g);
  if (_ret4389 == -1)
    return -1;
  int _ret4391;
  _ret4391 = guestfs_lvm_remove_all (g);
  if (_ret4391 == -1)
    return -1;

  /* TestResultString for zerofree (0) */
  const char *_arg4394 = "/dev/sda";
  const char *_arg4395 = "mbr";
  int _ret4393;
  _ret4393 = guestfs_part_disk (g, _arg4394, _arg4395);
  if (_ret4393 == -1)
    return -1;
  const char *_arg4398 = "ext3";
  const char *_arg4399 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs4400;
  _optargs4400.bitmask = UINT64_C(0x0);
  int _ret4397;
  _ret4397 = guestfs_mkfs_opts_argv (g, _arg4398, _arg4399, &_optargs4400);
  if (_ret4397 == -1)
    return -1;
  const char *_arg4402 = "/dev/sda1";
  const char *_arg4403 = "/";
  int _ret4401;
  _ret4401 = guestfs_mount (g, _arg4402, _arg4403);
  if (_ret4401 == -1)
    return -1;
  const char *_arg4406 = "/new";
  const char *_arg4407 = "test file";
  size_t _arg4407_size = 9;
  int _ret4405;
  _ret4405 = guestfs_write (g, _arg4406, _arg4407, _arg4407_size);
  if (_ret4405 == -1)
    return -1;
  const char *_arg4410 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs4411;
  _optargs4411.force = 0;
  _optargs4411.lazyunmount = 0;
  _optargs4411.bitmask = UINT64_C(0x3);
  int _ret4409;
  _ret4409 = guestfs_umount_opts_argv (g, _arg4410, &_optargs4411);
  if (_ret4409 == -1)
    return -1;
  const char *_arg4413 = "/dev/sda1";
  int _ret4412;
  _ret4412 = guestfs_zerofree (g, _arg4413);
  if (_ret4412 == -1)
    return -1;
  const char *_arg4416 = "/dev/sda1";
  const char *_arg4417 = "/";
  int _ret4415;
  _ret4415 = guestfs_mount (g, _arg4416, _arg4417);
  if (_ret4415 == -1)
    return -1;
  const char *_arg4419 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg4419);
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
test_hexdump_0 (void)
{
  if (test_hexdump_0_skip ()) {
    skipped ("test_hexdump_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_hexdump_0 */
  const char *_arg4422 = "/dev/sda";
  int _ret4421;
  _ret4421 = guestfs_blockdev_setrw (g, _arg4422);
  if (_ret4421 == -1)
    return -1;
  int _ret4424;
  _ret4424 = guestfs_umount_all (g);
  if (_ret4424 == -1)
    return -1;
  int _ret4426;
  _ret4426 = guestfs_lvm_remove_all (g);
  if (_ret4426 == -1)
    return -1;
  const char *_arg4429 = "/dev/sdd";
  const char *_arg4430 = "/";
  int _ret4428;
  _ret4428 = guestfs_mount_ro (g, _arg4429, _arg4430);
  if (_ret4428 == -1)
    return -1;

  /* TestResultString for hexdump (0) */
  const char *_arg4432 = "/known-4";
  CLEANUP_FREE char *ret;
  ret = guestfs_hexdump (g, _arg4432);
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
test_hexdump_1 (void)
{
  if (test_hexdump_1_skip ()) {
    skipped ("test_hexdump_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_hexdump_1 */
  const char *_arg4435 = "/dev/sda";
  int _ret4434;
  _ret4434 = guestfs_blockdev_setrw (g, _arg4435);
  if (_ret4434 == -1)
    return -1;
  int _ret4437;
  _ret4437 = guestfs_umount_all (g);
  if (_ret4437 == -1)
    return -1;
  int _ret4439;
  _ret4439 = guestfs_lvm_remove_all (g);
  if (_ret4439 == -1)
    return -1;
  const char *_arg4442 = "/dev/sdd";
  const char *_arg4443 = "/";
  int _ret4441;
  _ret4441 = guestfs_mount_ro (g, _arg4442, _arg4443);
  if (_ret4441 == -1)
    return -1;

  /* TestRun for hexdump (1) */
  const char *_arg4446 = "/100krandom";
  CLEANUP_FREE char *_ret4445;
  _ret4445 = guestfs_hexdump (g, _arg4446);
  if (_ret4445 == NULL)
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
test_hexdump_2 (void)
{
  if (test_hexdump_2_skip ()) {
    skipped ("test_hexdump_2", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_hexdump_2 */
  const char *_arg4449 = "/dev/sda";
  int _ret4448;
  _ret4448 = guestfs_blockdev_setrw (g, _arg4449);
  if (_ret4448 == -1)
    return -1;
  int _ret4451;
  _ret4451 = guestfs_umount_all (g);
  if (_ret4451 == -1)
    return -1;
  int _ret4453;
  _ret4453 = guestfs_lvm_remove_all (g);
  if (_ret4453 == -1)
    return -1;
  const char *_arg4456 = "/dev/sdd";
  const char *_arg4457 = "/";
  int _ret4455;
  _ret4455 = guestfs_mount_ro (g, _arg4456, _arg4457);
  if (_ret4455 == -1)
    return -1;

  /* TestRun for hexdump (2) */
  const char *_arg4460 = "/abssymlink";
  CLEANUP_FREE char *_ret4459;
  _ret4459 = guestfs_hexdump (g, _arg4460);
  if (_ret4459 == NULL)
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
test_strings_e_0 (void)
{
  if (test_strings_e_0_skip ()) {
    skipped ("test_strings_e_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_strings_e_0 */
  const char *_arg4463 = "/dev/sda";
  int _ret4462;
  _ret4462 = guestfs_blockdev_setrw (g, _arg4463);
  if (_ret4462 == -1)
    return -1;
  int _ret4465;
  _ret4465 = guestfs_umount_all (g);
  if (_ret4465 == -1)
    return -1;
  int _ret4467;
  _ret4467 = guestfs_lvm_remove_all (g);
  if (_ret4467 == -1)
    return -1;
  const char *_arg4470 = "/dev/sdd";
  const char *_arg4471 = "/";
  int _ret4469;
  _ret4469 = guestfs_mount_ro (g, _arg4470, _arg4471);
  if (_ret4469 == -1)
    return -1;

  /* TestResult for strings_e (0) */
  const char *_arg4473 = "b";
  const char *_arg4474 = "/known-5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings_e (g, _arg4473, _arg4474);
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
test_strings_e_1 (void)
{
  if (test_strings_e_1_skip ()) {
    skipped ("test_strings_e_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_strings_e_1 */
  const char *_arg4477 = "/dev/sda";
  int _ret4476;
  _ret4476 = guestfs_blockdev_setrw (g, _arg4477);
  if (_ret4476 == -1)
    return -1;
  int _ret4479;
  _ret4479 = guestfs_umount_all (g);
  if (_ret4479 == -1)
    return -1;
  int _ret4481;
  _ret4481 = guestfs_lvm_remove_all (g);
  if (_ret4481 == -1)
    return -1;
  const char *_arg4484 = "/dev/sdb1";
  const char *_arg4485 = "/";
  int _ret4483;
  _ret4483 = guestfs_mount (g, _arg4484, _arg4485);
  if (_ret4483 == -1)
    return -1;

  /* TestResult for strings_e (1) */
  const char *_arg4487 = "/strings_e";
  const char *_arg4488 = "\0h\0e\0l\0l\0o\0\n\0w\0o\0r\0l\0d\0\n";
  size_t _arg4488_size = 24;
  int ret1;
  ret1 = guestfs_write (g, _arg4487, _arg4488, _arg4488_size);
  if (ret1 == -1)
    return -1;
  const char *_arg4490 = "b";
  const char *_arg4491 = "/strings_e";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings_e (g, _arg4490, _arg4491);
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
test_strings_0 (void)
{
  if (test_strings_0_skip ()) {
    skipped ("test_strings_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_strings_0 */
  const char *_arg4494 = "/dev/sda";
  int _ret4493;
  _ret4493 = guestfs_blockdev_setrw (g, _arg4494);
  if (_ret4493 == -1)
    return -1;
  int _ret4496;
  _ret4496 = guestfs_umount_all (g);
  if (_ret4496 == -1)
    return -1;
  int _ret4498;
  _ret4498 = guestfs_lvm_remove_all (g);
  if (_ret4498 == -1)
    return -1;
  const char *_arg4501 = "/dev/sdd";
  const char *_arg4502 = "/";
  int _ret4500;
  _ret4500 = guestfs_mount_ro (g, _arg4501, _arg4502);
  if (_ret4500 == -1)
    return -1;

  /* TestResult for strings (0) */
  const char *_arg4504 = "/known-5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings (g, _arg4504);
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
test_strings_1 (void)
{
  if (test_strings_1_skip ()) {
    skipped ("test_strings_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_strings_1 */
  const char *_arg4507 = "/dev/sda";
  int _ret4506;
  _ret4506 = guestfs_blockdev_setrw (g, _arg4507);
  if (_ret4506 == -1)
    return -1;
  int _ret4509;
  _ret4509 = guestfs_umount_all (g);
  if (_ret4509 == -1)
    return -1;
  int _ret4511;
  _ret4511 = guestfs_lvm_remove_all (g);
  if (_ret4511 == -1)
    return -1;
  const char *_arg4514 = "/dev/sdd";
  const char *_arg4515 = "/";
  int _ret4513;
  _ret4513 = guestfs_mount_ro (g, _arg4514, _arg4515);
  if (_ret4513 == -1)
    return -1;

  /* TestResult for strings (1) */
  const char *_arg4517 = "/empty";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings (g, _arg4517);
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
test_strings_2 (void)
{
  if (test_strings_2_skip ()) {
    skipped ("test_strings_2", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_strings_2 */
  const char *_arg4520 = "/dev/sda";
  int _ret4519;
  _ret4519 = guestfs_blockdev_setrw (g, _arg4520);
  if (_ret4519 == -1)
    return -1;
  int _ret4522;
  _ret4522 = guestfs_umount_all (g);
  if (_ret4522 == -1)
    return -1;
  int _ret4524;
  _ret4524 = guestfs_lvm_remove_all (g);
  if (_ret4524 == -1)
    return -1;
  const char *_arg4527 = "/dev/sdd";
  const char *_arg4528 = "/";
  int _ret4526;
  _ret4526 = guestfs_mount_ro (g, _arg4527, _arg4528);
  if (_ret4526 == -1)
    return -1;

  /* TestRun for strings (2) */
  const char *_arg4531 = "/abssymlink";
  CLEANUP_FREE_STRING_LIST char **_ret4530;
  _ret4530 = guestfs_strings (g, _arg4531);
  if (_ret4530 == NULL)
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
test_equal_0 (void)
{
  if (test_equal_0_skip ()) {
    skipped ("test_equal_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_equal_0 */
  const char *_arg4534 = "/dev/sda";
  int _ret4533;
  _ret4533 = guestfs_blockdev_setrw (g, _arg4534);
  if (_ret4533 == -1)
    return -1;
  int _ret4536;
  _ret4536 = guestfs_umount_all (g);
  if (_ret4536 == -1)
    return -1;
  int _ret4538;
  _ret4538 = guestfs_lvm_remove_all (g);
  if (_ret4538 == -1)
    return -1;
  const char *_arg4541 = "/dev/sdb1";
  const char *_arg4542 = "/";
  int _ret4540;
  _ret4540 = guestfs_mount (g, _arg4541, _arg4542);
  if (_ret4540 == -1)
    return -1;

  /* TestResultTrue for equal (0) */
  const char *_arg4545 = "/equal";
  int _ret4544;
  _ret4544 = guestfs_mkdir (g, _arg4545);
  if (_ret4544 == -1)
    return -1;
  const char *_arg4548 = "/equal/file1";
  const char *_arg4549 = "contents of a file";
  size_t _arg4549_size = 18;
  int _ret4547;
  _ret4547 = guestfs_write (g, _arg4548, _arg4549, _arg4549_size);
  if (_ret4547 == -1)
    return -1;
  const char *_arg4552 = "/equal/file1";
  const char *_arg4553 = "/equal/file2";
  int _ret4551;
  _ret4551 = guestfs_cp (g, _arg4552, _arg4553);
  if (_ret4551 == -1)
    return -1;
  const char *_arg4555 = "/equal/file1";
  const char *_arg4556 = "/equal/file2";
  int ret;
  ret = guestfs_equal (g, _arg4555, _arg4556);
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
test_equal_1 (void)
{
  if (test_equal_1_skip ()) {
    skipped ("test_equal_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_equal_1 */
  const char *_arg4559 = "/dev/sda";
  int _ret4558;
  _ret4558 = guestfs_blockdev_setrw (g, _arg4559);
  if (_ret4558 == -1)
    return -1;
  int _ret4561;
  _ret4561 = guestfs_umount_all (g);
  if (_ret4561 == -1)
    return -1;
  int _ret4563;
  _ret4563 = guestfs_lvm_remove_all (g);
  if (_ret4563 == -1)
    return -1;
  const char *_arg4566 = "/dev/sdb1";
  const char *_arg4567 = "/";
  int _ret4565;
  _ret4565 = guestfs_mount (g, _arg4566, _arg4567);
  if (_ret4565 == -1)
    return -1;

  /* TestResultFalse for equal (1) */
  const char *_arg4570 = "/equal2";
  int _ret4569;
  _ret4569 = guestfs_mkdir (g, _arg4570);
  if (_ret4569 == -1)
    return -1;
  const char *_arg4573 = "/equal2/file1";
  const char *_arg4574 = "contents of a file";
  size_t _arg4574_size = 18;
  int _ret4572;
  _ret4572 = guestfs_write (g, _arg4573, _arg4574, _arg4574_size);
  if (_ret4572 == -1)
    return -1;
  const char *_arg4577 = "/equal2/file2";
  const char *_arg4578 = "contents of another file";
  size_t _arg4578_size = 24;
  int _ret4576;
  _ret4576 = guestfs_write (g, _arg4577, _arg4578, _arg4578_size);
  if (_ret4576 == -1)
    return -1;
  const char *_arg4580 = "/equal2/file1";
  const char *_arg4581 = "/equal2/file2";
  int ret;
  ret = guestfs_equal (g, _arg4580, _arg4581);
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
test_equal_2 (void)
{
  if (test_equal_2_skip ()) {
    skipped ("test_equal_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_equal_2 */
  const char *_arg4584 = "/dev/sda";
  int _ret4583;
  _ret4583 = guestfs_blockdev_setrw (g, _arg4584);
  if (_ret4583 == -1)
    return -1;
  int _ret4586;
  _ret4586 = guestfs_umount_all (g);
  if (_ret4586 == -1)
    return -1;
  int _ret4588;
  _ret4588 = guestfs_lvm_remove_all (g);
  if (_ret4588 == -1)
    return -1;
  const char *_arg4591 = "/dev/sdb1";
  const char *_arg4592 = "/";
  int _ret4590;
  _ret4590 = guestfs_mount (g, _arg4591, _arg4592);
  if (_ret4590 == -1)
    return -1;

  /* TestLastFail for equal (2) */
  const char *_arg4595 = "/equal3";
  int _ret4594;
  _ret4594 = guestfs_mkdir (g, _arg4595);
  if (_ret4594 == -1)
    return -1;
  const char *_arg4598 = "/equal3/file1";
  const char *_arg4599 = "/equal3/file2";
  int _ret4597;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret4597 = guestfs_equal (g, _arg4598, _arg4599);
  guestfs_pop_error_handler (g);
  if (_ret4597 != -1)
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
test_ping_daemon_0 (void)
{
  if (test_ping_daemon_0_skip ()) {
    skipped ("test_ping_daemon_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_ping_daemon_0 */
  const char *_arg4602 = "/dev/sda";
  int _ret4601;
  _ret4601 = guestfs_blockdev_setrw (g, _arg4602);
  if (_ret4601 == -1)
    return -1;
  int _ret4604;
  _ret4604 = guestfs_umount_all (g);
  if (_ret4604 == -1)
    return -1;
  int _ret4606;
  _ret4606 = guestfs_lvm_remove_all (g);
  if (_ret4606 == -1)
    return -1;

  /* TestRun for ping_daemon (0) */
  int _ret4608;
  _ret4608 = guestfs_ping_daemon (g);
  if (_ret4608 == -1)
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
test_dmesg_0 (void)
{
  if (test_dmesg_0_skip ()) {
    skipped ("test_dmesg_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_dmesg_0 */
  const char *_arg4611 = "/dev/sda";
  int _ret4610;
  _ret4610 = guestfs_blockdev_setrw (g, _arg4611);
  if (_ret4610 == -1)
    return -1;
  int _ret4613;
  _ret4613 = guestfs_umount_all (g);
  if (_ret4613 == -1)
    return -1;
  int _ret4615;
  _ret4615 = guestfs_lvm_remove_all (g);
  if (_ret4615 == -1)
    return -1;

  /* TestRun for dmesg (0) */
  CLEANUP_FREE char *_ret4617;
  _ret4617 = guestfs_dmesg (g);
  if (_ret4617 == NULL)
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
test_drop_caches_0 (void)
{
  if (test_drop_caches_0_skip ()) {
    skipped ("test_drop_caches_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_drop_caches_0 */
  const char *_arg4620 = "/dev/sda";
  int _ret4619;
  _ret4619 = guestfs_blockdev_setrw (g, _arg4620);
  if (_ret4619 == -1)
    return -1;
  int _ret4622;
  _ret4622 = guestfs_umount_all (g);
  if (_ret4622 == -1)
    return -1;
  int _ret4624;
  _ret4624 = guestfs_lvm_remove_all (g);
  if (_ret4624 == -1)
    return -1;

  /* TestRun for drop_caches (0) */
  int _ret4626;
  _ret4626 = guestfs_drop_caches (g, 3);
  if (_ret4626 == -1)
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
test_mv_0 (void)
{
  if (test_mv_0_skip ()) {
    skipped ("test_mv_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mv_0 */
  const char *_arg4630 = "/dev/sda";
  int _ret4629;
  _ret4629 = guestfs_blockdev_setrw (g, _arg4630);
  if (_ret4629 == -1)
    return -1;
  int _ret4632;
  _ret4632 = guestfs_umount_all (g);
  if (_ret4632 == -1)
    return -1;
  int _ret4634;
  _ret4634 = guestfs_lvm_remove_all (g);
  if (_ret4634 == -1)
    return -1;
  const char *_arg4637 = "/dev/sdb1";
  const char *_arg4638 = "/";
  int _ret4636;
  _ret4636 = guestfs_mount (g, _arg4637, _arg4638);
  if (_ret4636 == -1)
    return -1;

  /* TestResultString for mv (0) */
  const char *_arg4641 = "/mv";
  int _ret4640;
  _ret4640 = guestfs_mkdir (g, _arg4641);
  if (_ret4640 == -1)
    return -1;
  const char *_arg4644 = "/mv/old";
  const char *_arg4645 = "file content";
  size_t _arg4645_size = 12;
  int _ret4643;
  _ret4643 = guestfs_write (g, _arg4644, _arg4645, _arg4645_size);
  if (_ret4643 == -1)
    return -1;
  const char *_arg4648 = "/mv/old";
  const char *_arg4649 = "/mv/new";
  int _ret4647;
  _ret4647 = guestfs_mv (g, _arg4648, _arg4649);
  if (_ret4647 == -1)
    return -1;
  const char *_arg4651 = "/mv/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg4651);
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
test_mv_1 (void)
{
  if (test_mv_1_skip ()) {
    skipped ("test_mv_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mv_1 */
  const char *_arg4654 = "/dev/sda";
  int _ret4653;
  _ret4653 = guestfs_blockdev_setrw (g, _arg4654);
  if (_ret4653 == -1)
    return -1;
  int _ret4656;
  _ret4656 = guestfs_umount_all (g);
  if (_ret4656 == -1)
    return -1;
  int _ret4658;
  _ret4658 = guestfs_lvm_remove_all (g);
  if (_ret4658 == -1)
    return -1;
  const char *_arg4661 = "/dev/sdb1";
  const char *_arg4662 = "/";
  int _ret4660;
  _ret4660 = guestfs_mount (g, _arg4661, _arg4662);
  if (_ret4660 == -1)
    return -1;

  /* TestResultFalse for mv (1) */
  const char *_arg4665 = "/mv2";
  int _ret4664;
  _ret4664 = guestfs_mkdir (g, _arg4665);
  if (_ret4664 == -1)
    return -1;
  const char *_arg4668 = "/mv2/old";
  const char *_arg4669 = "file content";
  size_t _arg4669_size = 12;
  int _ret4667;
  _ret4667 = guestfs_write (g, _arg4668, _arg4669, _arg4669_size);
  if (_ret4667 == -1)
    return -1;
  const char *_arg4672 = "/mv2/old";
  const char *_arg4673 = "/mv2/new";
  int _ret4671;
  _ret4671 = guestfs_mv (g, _arg4672, _arg4673);
  if (_ret4671 == -1)
    return -1;
  const char *_arg4675 = "/mv2/old";
  int ret;
  ret = guestfs_is_file (g, _arg4675);
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
test_cp_a_0 (void)
{
  if (test_cp_a_0_skip ()) {
    skipped ("test_cp_a_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_cp_a_0 */
  const char *_arg4678 = "/dev/sda";
  int _ret4677;
  _ret4677 = guestfs_blockdev_setrw (g, _arg4678);
  if (_ret4677 == -1)
    return -1;
  int _ret4680;
  _ret4680 = guestfs_umount_all (g);
  if (_ret4680 == -1)
    return -1;
  int _ret4682;
  _ret4682 = guestfs_lvm_remove_all (g);
  if (_ret4682 == -1)
    return -1;
  const char *_arg4685 = "/dev/sdb1";
  const char *_arg4686 = "/";
  int _ret4684;
  _ret4684 = guestfs_mount (g, _arg4685, _arg4686);
  if (_ret4684 == -1)
    return -1;

  /* TestResultString for cp_a (0) */
  const char *_arg4689 = "/cp_a1";
  int _ret4688;
  _ret4688 = guestfs_mkdir (g, _arg4689);
  if (_ret4688 == -1)
    return -1;
  const char *_arg4692 = "/cp_a2";
  int _ret4691;
  _ret4691 = guestfs_mkdir (g, _arg4692);
  if (_ret4691 == -1)
    return -1;
  const char *_arg4695 = "/cp_a1/file";
  const char *_arg4696 = "file content";
  size_t _arg4696_size = 12;
  int _ret4694;
  _ret4694 = guestfs_write (g, _arg4695, _arg4696, _arg4696_size);
  if (_ret4694 == -1)
    return -1;
  const char *_arg4699 = "/cp_a1";
  const char *_arg4700 = "/cp_a2";
  int _ret4698;
  _ret4698 = guestfs_cp_a (g, _arg4699, _arg4700);
  if (_ret4698 == -1)
    return -1;
  const char *_arg4702 = "/cp_a2/cp_a1/file";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg4702);
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
test_cp_0 (void)
{
  if (test_cp_0_skip ()) {
    skipped ("test_cp_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_cp_0 */
  const char *_arg4705 = "/dev/sda";
  int _ret4704;
  _ret4704 = guestfs_blockdev_setrw (g, _arg4705);
  if (_ret4704 == -1)
    return -1;
  int _ret4707;
  _ret4707 = guestfs_umount_all (g);
  if (_ret4707 == -1)
    return -1;
  int _ret4709;
  _ret4709 = guestfs_lvm_remove_all (g);
  if (_ret4709 == -1)
    return -1;
  const char *_arg4712 = "/dev/sdb1";
  const char *_arg4713 = "/";
  int _ret4711;
  _ret4711 = guestfs_mount (g, _arg4712, _arg4713);
  if (_ret4711 == -1)
    return -1;

  /* TestResultString for cp (0) */
  const char *_arg4716 = "/cp";
  int _ret4715;
  _ret4715 = guestfs_mkdir (g, _arg4716);
  if (_ret4715 == -1)
    return -1;
  const char *_arg4719 = "/cp/old";
  const char *_arg4720 = "file content";
  size_t _arg4720_size = 12;
  int _ret4718;
  _ret4718 = guestfs_write (g, _arg4719, _arg4720, _arg4720_size);
  if (_ret4718 == -1)
    return -1;
  const char *_arg4723 = "/cp/old";
  const char *_arg4724 = "/cp/new";
  int _ret4722;
  _ret4722 = guestfs_cp (g, _arg4723, _arg4724);
  if (_ret4722 == -1)
    return -1;
  const char *_arg4726 = "/cp/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg4726);
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
test_cp_1 (void)
{
  if (test_cp_1_skip ()) {
    skipped ("test_cp_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_cp_1 */
  const char *_arg4729 = "/dev/sda";
  int _ret4728;
  _ret4728 = guestfs_blockdev_setrw (g, _arg4729);
  if (_ret4728 == -1)
    return -1;
  int _ret4731;
  _ret4731 = guestfs_umount_all (g);
  if (_ret4731 == -1)
    return -1;
  int _ret4733;
  _ret4733 = guestfs_lvm_remove_all (g);
  if (_ret4733 == -1)
    return -1;
  const char *_arg4736 = "/dev/sdb1";
  const char *_arg4737 = "/";
  int _ret4735;
  _ret4735 = guestfs_mount (g, _arg4736, _arg4737);
  if (_ret4735 == -1)
    return -1;

  /* TestResultTrue for cp (1) */
  const char *_arg4740 = "/cp2";
  int _ret4739;
  _ret4739 = guestfs_mkdir (g, _arg4740);
  if (_ret4739 == -1)
    return -1;
  const char *_arg4743 = "/cp2/old";
  const char *_arg4744 = "file content";
  size_t _arg4744_size = 12;
  int _ret4742;
  _ret4742 = guestfs_write (g, _arg4743, _arg4744, _arg4744_size);
  if (_ret4742 == -1)
    return -1;
  const char *_arg4747 = "/cp2/old";
  const char *_arg4748 = "/cp2/new";
  int _ret4746;
  _ret4746 = guestfs_cp (g, _arg4747, _arg4748);
  if (_ret4746 == -1)
    return -1;
  const char *_arg4750 = "/cp2/old";
  int ret;
  ret = guestfs_is_file (g, _arg4750);
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
test_cp_2 (void)
{
  if (test_cp_2_skip ()) {
    skipped ("test_cp_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_cp_2 */
  const char *_arg4753 = "/dev/sda";
  int _ret4752;
  _ret4752 = guestfs_blockdev_setrw (g, _arg4753);
  if (_ret4752 == -1)
    return -1;
  int _ret4755;
  _ret4755 = guestfs_umount_all (g);
  if (_ret4755 == -1)
    return -1;
  int _ret4757;
  _ret4757 = guestfs_lvm_remove_all (g);
  if (_ret4757 == -1)
    return -1;
  const char *_arg4760 = "/dev/sdb1";
  const char *_arg4761 = "/";
  int _ret4759;
  _ret4759 = guestfs_mount (g, _arg4760, _arg4761);
  if (_ret4759 == -1)
    return -1;

  /* TestResultString for cp (2) */
  const char *_arg4764 = "/cp3";
  int _ret4763;
  _ret4763 = guestfs_mkdir (g, _arg4764);
  if (_ret4763 == -1)
    return -1;
  const char *_arg4767 = "/cp3/old";
  const char *_arg4768 = "file content";
  size_t _arg4768_size = 12;
  int _ret4766;
  _ret4766 = guestfs_write (g, _arg4767, _arg4768, _arg4768_size);
  if (_ret4766 == -1)
    return -1;
  const char *_arg4771 = "/cp3/dir";
  int _ret4770;
  _ret4770 = guestfs_mkdir (g, _arg4771);
  if (_ret4770 == -1)
    return -1;
  const char *_arg4774 = "/cp3/old";
  const char *_arg4775 = "/cp3/dir/new";
  int _ret4773;
  _ret4773 = guestfs_cp (g, _arg4774, _arg4775);
  if (_ret4773 == -1)
    return -1;
  const char *_arg4777 = "/cp3/dir/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg4777);
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
test_grub_install_0 (void)
{
  if (test_grub_install_0_skip ()) {
    skipped ("test_grub_install_0", "environment variable set");
    return 0;
  }

  const char *_features4779[] = { "grub", NULL };
  if (!guestfs_feature_available (g, (char **) _features4779)) {
    skipped ("test_grub_install_0", "group %s not available in daemon",
             _features4779[0]);
    return 0;
  }

  /* InitBasicFS for test_grub_install_0: create ext2 on /dev/sda1 */
  const char *_arg4781 = "/dev/sda";
  int _ret4780;
  _ret4780 = guestfs_blockdev_setrw (g, _arg4781);
  if (_ret4780 == -1)
    return -1;
  int _ret4783;
  _ret4783 = guestfs_umount_all (g);
  if (_ret4783 == -1)
    return -1;
  int _ret4785;
  _ret4785 = guestfs_lvm_remove_all (g);
  if (_ret4785 == -1)
    return -1;
  const char *_arg4788 = "/dev/sda";
  const char *_arg4789 = "mbr";
  int _ret4787;
  _ret4787 = guestfs_part_disk (g, _arg4788, _arg4789);
  if (_ret4787 == -1)
    return -1;
  const char *_arg4792 = "ext2";
  const char *_arg4793 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs4794;
  _optargs4794.bitmask = UINT64_C(0x0);
  int _ret4791;
  _ret4791 = guestfs_mkfs_opts_argv (g, _arg4792, _arg4793, &_optargs4794);
  if (_ret4791 == -1)
    return -1;
  const char *_arg4796 = "/dev/sda1";
  const char *_arg4797 = "/";
  int _ret4795;
  _ret4795 = guestfs_mount (g, _arg4796, _arg4797);
  if (_ret4795 == -1)
    return -1;

  /* TestResultTrue for grub_install (0) */
  const char *_arg4800 = "/boot/grub";
  int _ret4799;
  _ret4799 = guestfs_mkdir_p (g, _arg4800);
  if (_ret4799 == -1)
    return -1;
  const char *_arg4803 = "/boot/grub/device.map";
  const char *_arg4804 = "(hd0) /dev/vda";
  size_t _arg4804_size = 14;
  int _ret4802;
  _ret4802 = guestfs_write (g, _arg4803, _arg4804, _arg4804_size);
  if (_ret4802 == -1)
    return -1;
  const char *_arg4807 = "/";
  const char *_arg4808 = "/dev/vda";
  int _ret4806;
  _ret4806 = guestfs_grub_install (g, _arg4807, _arg4808);
  if (_ret4806 == -1)
    return -1;
  const char *_arg4810 = "/boot";
  int ret;
  ret = guestfs_is_dir (g, _arg4810);
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
test_zero_0 (void)
{
  if (test_zero_0_skip ()) {
    skipped ("test_zero_0", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_zero_0: create ext2 on /dev/sda1 */
  const char *_arg4813 = "/dev/sda";
  int _ret4812;
  _ret4812 = guestfs_blockdev_setrw (g, _arg4813);
  if (_ret4812 == -1)
    return -1;
  int _ret4815;
  _ret4815 = guestfs_umount_all (g);
  if (_ret4815 == -1)
    return -1;
  int _ret4817;
  _ret4817 = guestfs_lvm_remove_all (g);
  if (_ret4817 == -1)
    return -1;
  const char *_arg4820 = "/dev/sda";
  const char *_arg4821 = "mbr";
  int _ret4819;
  _ret4819 = guestfs_part_disk (g, _arg4820, _arg4821);
  if (_ret4819 == -1)
    return -1;
  const char *_arg4824 = "ext2";
  const char *_arg4825 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs4826;
  _optargs4826.bitmask = UINT64_C(0x0);
  int _ret4823;
  _ret4823 = guestfs_mkfs_opts_argv (g, _arg4824, _arg4825, &_optargs4826);
  if (_ret4823 == -1)
    return -1;
  const char *_arg4828 = "/dev/sda1";
  const char *_arg4829 = "/";
  int _ret4827;
  _ret4827 = guestfs_mount (g, _arg4828, _arg4829);
  if (_ret4827 == -1)
    return -1;

  /* TestRun for zero (0) */
  const char *_arg4832 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs4833;
  _optargs4833.force = 0;
  _optargs4833.lazyunmount = 0;
  _optargs4833.bitmask = UINT64_C(0x3);
  int _ret4831;
  _ret4831 = guestfs_umount_opts_argv (g, _arg4832, &_optargs4833);
  if (_ret4831 == -1)
    return -1;
  const char *_arg4835 = "/dev/sda1";
  int _ret4834;
  _ret4834 = guestfs_zero (g, _arg4835);
  if (_ret4834 == -1)
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
test_fsck_0 (void)
{
  if (test_fsck_0_skip ()) {
    skipped ("test_fsck_0", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_fsck_0: create ext2 on /dev/sda1 */
  const char *_arg4838 = "/dev/sda";
  int _ret4837;
  _ret4837 = guestfs_blockdev_setrw (g, _arg4838);
  if (_ret4837 == -1)
    return -1;
  int _ret4840;
  _ret4840 = guestfs_umount_all (g);
  if (_ret4840 == -1)
    return -1;
  int _ret4842;
  _ret4842 = guestfs_lvm_remove_all (g);
  if (_ret4842 == -1)
    return -1;
  const char *_arg4845 = "/dev/sda";
  const char *_arg4846 = "mbr";
  int _ret4844;
  _ret4844 = guestfs_part_disk (g, _arg4845, _arg4846);
  if (_ret4844 == -1)
    return -1;
  const char *_arg4849 = "ext2";
  const char *_arg4850 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs4851;
  _optargs4851.bitmask = UINT64_C(0x0);
  int _ret4848;
  _ret4848 = guestfs_mkfs_opts_argv (g, _arg4849, _arg4850, &_optargs4851);
  if (_ret4848 == -1)
    return -1;
  const char *_arg4853 = "/dev/sda1";
  const char *_arg4854 = "/";
  int _ret4852;
  _ret4852 = guestfs_mount (g, _arg4853, _arg4854);
  if (_ret4852 == -1)
    return -1;

  /* TestResult for fsck (0) */
  const char *_arg4856 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs4857;
  _optargs4857.force = 0;
  _optargs4857.lazyunmount = 0;
  _optargs4857.bitmask = UINT64_C(0x3);
  int ret1;
  ret1 = guestfs_umount_opts_argv (g, _arg4856, &_optargs4857);
  if (ret1 == -1)
    return -1;
  const char *_arg4858 = "ext2";
  const char *_arg4859 = "/dev/sda1";
  int ret;
  ret = guestfs_fsck (g, _arg4858, _arg4859);
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
test_fsck_1 (void)
{
  if (test_fsck_1_skip ()) {
    skipped ("test_fsck_1", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_fsck_1: create ext2 on /dev/sda1 */
  const char *_arg4862 = "/dev/sda";
  int _ret4861;
  _ret4861 = guestfs_blockdev_setrw (g, _arg4862);
  if (_ret4861 == -1)
    return -1;
  int _ret4864;
  _ret4864 = guestfs_umount_all (g);
  if (_ret4864 == -1)
    return -1;
  int _ret4866;
  _ret4866 = guestfs_lvm_remove_all (g);
  if (_ret4866 == -1)
    return -1;
  const char *_arg4869 = "/dev/sda";
  const char *_arg4870 = "mbr";
  int _ret4868;
  _ret4868 = guestfs_part_disk (g, _arg4869, _arg4870);
  if (_ret4868 == -1)
    return -1;
  const char *_arg4873 = "ext2";
  const char *_arg4874 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs4875;
  _optargs4875.bitmask = UINT64_C(0x0);
  int _ret4872;
  _ret4872 = guestfs_mkfs_opts_argv (g, _arg4873, _arg4874, &_optargs4875);
  if (_ret4872 == -1)
    return -1;
  const char *_arg4877 = "/dev/sda1";
  const char *_arg4878 = "/";
  int _ret4876;
  _ret4876 = guestfs_mount (g, _arg4877, _arg4878);
  if (_ret4876 == -1)
    return -1;

  /* TestResult for fsck (1) */
  const char *_arg4880 = "/dev/sda1";
  struct guestfs_umount_opts_argv _optargs4881;
  _optargs4881.force = 0;
  _optargs4881.lazyunmount = 0;
  _optargs4881.bitmask = UINT64_C(0x3);
  int ret2;
  ret2 = guestfs_umount_opts_argv (g, _arg4880, &_optargs4881);
  if (ret2 == -1)
    return -1;
  const char *_arg4882 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_zero (g, _arg4882);
  if (ret1 == -1)
    return -1;
  const char *_arg4884 = "ext2";
  const char *_arg4885 = "/dev/sda1";
  int ret;
  ret = guestfs_fsck (g, _arg4884, _arg4885);
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
test_get_e2uuid_0 (void)
{
  if (test_get_e2uuid_0_skip ()) {
    skipped ("test_get_e2uuid_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_e2uuid_0 */
  const char *_arg4888 = "/dev/sda";
  int _ret4887;
  _ret4887 = guestfs_blockdev_setrw (g, _arg4888);
  if (_ret4887 == -1)
    return -1;
  int _ret4890;
  _ret4890 = guestfs_umount_all (g);
  if (_ret4890 == -1)
    return -1;
  int _ret4892;
  _ret4892 = guestfs_lvm_remove_all (g);
  if (_ret4892 == -1)
    return -1;

  /* TestResultString for get_e2uuid (0) */
  const char *_arg4896 = "/dev/sdc";
  int _ret4894;
  _ret4894 = guestfs_mke2journal (g, 1024, _arg4896);
  if (_ret4894 == -1)
    return -1;
  const char *_arg4899 = "/dev/sdc";
  const char *_arg4900 = "fd5f5bd4-9254-0e03-76b4-43f62553291c";
  int _ret4898;
  _ret4898 = guestfs_set_e2uuid (g, _arg4899, _arg4900);
  if (_ret4898 == -1)
    return -1;
  const char *_arg4902 = "/dev/sdc";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, _arg4902);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "fd5f5bd4-9254-0e03-76b4-43f62553291c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_get_e2uuid_0", "get_e2uuid", ret, "fd5f5bd4-9254-0e03-76b4-43f62553291c");
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
test_set_e2uuid_0 (void)
{
  if (test_set_e2uuid_0_skip ()) {
    skipped ("test_set_e2uuid_0", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_set_e2uuid_0: create ext2 on /dev/sda1 */
  const char *_arg4905 = "/dev/sda";
  int _ret4904;
  _ret4904 = guestfs_blockdev_setrw (g, _arg4905);
  if (_ret4904 == -1)
    return -1;
  int _ret4907;
  _ret4907 = guestfs_umount_all (g);
  if (_ret4907 == -1)
    return -1;
  int _ret4909;
  _ret4909 = guestfs_lvm_remove_all (g);
  if (_ret4909 == -1)
    return -1;
  const char *_arg4912 = "/dev/sda";
  const char *_arg4913 = "mbr";
  int _ret4911;
  _ret4911 = guestfs_part_disk (g, _arg4912, _arg4913);
  if (_ret4911 == -1)
    return -1;
  const char *_arg4916 = "ext2";
  const char *_arg4917 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs4918;
  _optargs4918.bitmask = UINT64_C(0x0);
  int _ret4915;
  _ret4915 = guestfs_mkfs_opts_argv (g, _arg4916, _arg4917, &_optargs4918);
  if (_ret4915 == -1)
    return -1;
  const char *_arg4920 = "/dev/sda1";
  const char *_arg4921 = "/";
  int _ret4919;
  _ret4919 = guestfs_mount (g, _arg4920, _arg4921);
  if (_ret4919 == -1)
    return -1;

  /* TestResultString for set_e2uuid (0) */
  const char *_arg4924 = "/dev/sda1";
  const char *_arg4925 = "fd5f5bd4-9254-0e03-76b4-43f62553291c";
  int _ret4923;
  _ret4923 = guestfs_set_e2uuid (g, _arg4924, _arg4925);
  if (_ret4923 == -1)
    return -1;
  const char *_arg4927 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, _arg4927);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "fd5f5bd4-9254-0e03-76b4-43f62553291c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_e2uuid_0", "get_e2uuid", ret, "fd5f5bd4-9254-0e03-76b4-43f62553291c");
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
test_set_e2uuid_1 (void)
{
  if (test_set_e2uuid_1_skip ()) {
    skipped ("test_set_e2uuid_1", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_set_e2uuid_1: create ext2 on /dev/sda1 */
  const char *_arg4930 = "/dev/sda";
  int _ret4929;
  _ret4929 = guestfs_blockdev_setrw (g, _arg4930);
  if (_ret4929 == -1)
    return -1;
  int _ret4932;
  _ret4932 = guestfs_umount_all (g);
  if (_ret4932 == -1)
    return -1;
  int _ret4934;
  _ret4934 = guestfs_lvm_remove_all (g);
  if (_ret4934 == -1)
    return -1;
  const char *_arg4937 = "/dev/sda";
  const char *_arg4938 = "mbr";
  int _ret4936;
  _ret4936 = guestfs_part_disk (g, _arg4937, _arg4938);
  if (_ret4936 == -1)
    return -1;
  const char *_arg4941 = "ext2";
  const char *_arg4942 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs4943;
  _optargs4943.bitmask = UINT64_C(0x0);
  int _ret4940;
  _ret4940 = guestfs_mkfs_opts_argv (g, _arg4941, _arg4942, &_optargs4943);
  if (_ret4940 == -1)
    return -1;
  const char *_arg4945 = "/dev/sda1";
  const char *_arg4946 = "/";
  int _ret4944;
  _ret4944 = guestfs_mount (g, _arg4945, _arg4946);
  if (_ret4944 == -1)
    return -1;

  /* TestResultString for set_e2uuid (1) */
  const char *_arg4949 = "/dev/sda1";
  const char *_arg4950 = "clear";
  int _ret4948;
  _ret4948 = guestfs_set_e2uuid (g, _arg4949, _arg4950);
  if (_ret4948 == -1)
    return -1;
  const char *_arg4952 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, _arg4952);
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
test_set_e2uuid_2 (void)
{
  if (test_set_e2uuid_2_skip ()) {
    skipped ("test_set_e2uuid_2", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_set_e2uuid_2: create ext2 on /dev/sda1 */
  const char *_arg4955 = "/dev/sda";
  int _ret4954;
  _ret4954 = guestfs_blockdev_setrw (g, _arg4955);
  if (_ret4954 == -1)
    return -1;
  int _ret4957;
  _ret4957 = guestfs_umount_all (g);
  if (_ret4957 == -1)
    return -1;
  int _ret4959;
  _ret4959 = guestfs_lvm_remove_all (g);
  if (_ret4959 == -1)
    return -1;
  const char *_arg4962 = "/dev/sda";
  const char *_arg4963 = "mbr";
  int _ret4961;
  _ret4961 = guestfs_part_disk (g, _arg4962, _arg4963);
  if (_ret4961 == -1)
    return -1;
  const char *_arg4966 = "ext2";
  const char *_arg4967 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs4968;
  _optargs4968.bitmask = UINT64_C(0x0);
  int _ret4965;
  _ret4965 = guestfs_mkfs_opts_argv (g, _arg4966, _arg4967, &_optargs4968);
  if (_ret4965 == -1)
    return -1;
  const char *_arg4970 = "/dev/sda1";
  const char *_arg4971 = "/";
  int _ret4969;
  _ret4969 = guestfs_mount (g, _arg4970, _arg4971);
  if (_ret4969 == -1)
    return -1;

  /* TestRun for set_e2uuid (2) */
  const char *_arg4974 = "/dev/sda1";
  const char *_arg4975 = "random";
  int _ret4973;
  _ret4973 = guestfs_set_e2uuid (g, _arg4974, _arg4975);
  if (_ret4973 == -1)
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
test_set_e2uuid_3 (void)
{
  if (test_set_e2uuid_3_skip ()) {
    skipped ("test_set_e2uuid_3", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_set_e2uuid_3: create ext2 on /dev/sda1 */
  const char *_arg4978 = "/dev/sda";
  int _ret4977;
  _ret4977 = guestfs_blockdev_setrw (g, _arg4978);
  if (_ret4977 == -1)
    return -1;
  int _ret4980;
  _ret4980 = guestfs_umount_all (g);
  if (_ret4980 == -1)
    return -1;
  int _ret4982;
  _ret4982 = guestfs_lvm_remove_all (g);
  if (_ret4982 == -1)
    return -1;
  const char *_arg4985 = "/dev/sda";
  const char *_arg4986 = "mbr";
  int _ret4984;
  _ret4984 = guestfs_part_disk (g, _arg4985, _arg4986);
  if (_ret4984 == -1)
    return -1;
  const char *_arg4989 = "ext2";
  const char *_arg4990 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs4991;
  _optargs4991.bitmask = UINT64_C(0x0);
  int _ret4988;
  _ret4988 = guestfs_mkfs_opts_argv (g, _arg4989, _arg4990, &_optargs4991);
  if (_ret4988 == -1)
    return -1;
  const char *_arg4993 = "/dev/sda1";
  const char *_arg4994 = "/";
  int _ret4992;
  _ret4992 = guestfs_mount (g, _arg4993, _arg4994);
  if (_ret4992 == -1)
    return -1;

  /* TestRun for set_e2uuid (3) */
  const char *_arg4997 = "/dev/sda1";
  const char *_arg4998 = "time";
  int _ret4996;
  _ret4996 = guestfs_set_e2uuid (g, _arg4997, _arg4998);
  if (_ret4996 == -1)
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
test_set_e2label_0 (void)
{
  if (test_set_e2label_0_skip ()) {
    skipped ("test_set_e2label_0", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_set_e2label_0: create ext2 on /dev/sda1 */
  const char *_arg5001 = "/dev/sda";
  int _ret5000;
  _ret5000 = guestfs_blockdev_setrw (g, _arg5001);
  if (_ret5000 == -1)
    return -1;
  int _ret5003;
  _ret5003 = guestfs_umount_all (g);
  if (_ret5003 == -1)
    return -1;
  int _ret5005;
  _ret5005 = guestfs_lvm_remove_all (g);
  if (_ret5005 == -1)
    return -1;
  const char *_arg5008 = "/dev/sda";
  const char *_arg5009 = "mbr";
  int _ret5007;
  _ret5007 = guestfs_part_disk (g, _arg5008, _arg5009);
  if (_ret5007 == -1)
    return -1;
  const char *_arg5012 = "ext2";
  const char *_arg5013 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs5014;
  _optargs5014.bitmask = UINT64_C(0x0);
  int _ret5011;
  _ret5011 = guestfs_mkfs_opts_argv (g, _arg5012, _arg5013, &_optargs5014);
  if (_ret5011 == -1)
    return -1;
  const char *_arg5016 = "/dev/sda1";
  const char *_arg5017 = "/";
  int _ret5015;
  _ret5015 = guestfs_mount (g, _arg5016, _arg5017);
  if (_ret5015 == -1)
    return -1;

  /* TestResultString for set_e2label (0) */
  const char *_arg5020 = "/dev/sda1";
  const char *_arg5021 = "testlabel";
  int _ret5019;
  _ret5019 = guestfs_set_e2label (g, _arg5020, _arg5021);
  if (_ret5019 == -1)
    return -1;
  const char *_arg5023 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2label (g, _arg5023);
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
test_pvremove_0 (void)
{
  if (test_pvremove_0_skip ()) {
    skipped ("test_pvremove_0", "environment variable set");
    return 0;
  }

  const char *_features5025[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features5025)) {
    skipped ("test_pvremove_0", "group %s not available in daemon",
             _features5025[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_pvremove_0 */
  const char *_arg5027 = "/dev/sda";
  int _ret5026;
  _ret5026 = guestfs_blockdev_setrw (g, _arg5027);
  if (_ret5026 == -1)
    return -1;
  int _ret5029;
  _ret5029 = guestfs_umount_all (g);
  if (_ret5029 == -1)
    return -1;
  int _ret5031;
  _ret5031 = guestfs_lvm_remove_all (g);
  if (_ret5031 == -1)
    return -1;

  /* TestResult for pvremove (0) */
  const char *_arg5033 = "/dev/sda";
  const char *_arg5034 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg5033, _arg5034);
  if (ret7 == -1)
    return -1;
  const char *_arg5036 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg5036);
  if (ret6 == -1)
    return -1;
  const char *_arg5038 = "VG";
  const char *_arg5039_0 = "/dev/sda1";
  const char *const _arg5039[] = {
    _arg5039_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg5038, (char **) _arg5039);
  if (ret5 == -1)
    return -1;
  const char *_arg5041 = "LV1";
  const char *_arg5042 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg5041, _arg5042, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg5045 = "LV2";
  const char *_arg5046 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg5045, _arg5046, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg5049 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, _arg5049);
  if (ret2 == -1)
    return -1;
  const char *_arg5051 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, _arg5051);
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
test_pvremove_1 (void)
{
  if (test_pvremove_1_skip ()) {
    skipped ("test_pvremove_1", "environment variable set");
    return 0;
  }

  const char *_features5054[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features5054)) {
    skipped ("test_pvremove_1", "group %s not available in daemon",
             _features5054[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_pvremove_1 */
  const char *_arg5056 = "/dev/sda";
  int _ret5055;
  _ret5055 = guestfs_blockdev_setrw (g, _arg5056);
  if (_ret5055 == -1)
    return -1;
  int _ret5058;
  _ret5058 = guestfs_umount_all (g);
  if (_ret5058 == -1)
    return -1;
  int _ret5060;
  _ret5060 = guestfs_lvm_remove_all (g);
  if (_ret5060 == -1)
    return -1;

  /* TestResult for pvremove (1) */
  const char *_arg5062 = "/dev/sda";
  const char *_arg5063 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg5062, _arg5063);
  if (ret7 == -1)
    return -1;
  const char *_arg5065 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg5065);
  if (ret6 == -1)
    return -1;
  const char *_arg5067 = "VG";
  const char *_arg5068_0 = "/dev/sda1";
  const char *const _arg5068[] = {
    _arg5068_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg5067, (char **) _arg5068);
  if (ret5 == -1)
    return -1;
  const char *_arg5070 = "LV1";
  const char *_arg5071 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg5070, _arg5071, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg5074 = "LV2";
  const char *_arg5075 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg5074, _arg5075, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg5078 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, _arg5078);
  if (ret2 == -1)
    return -1;
  const char *_arg5080 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, _arg5080);
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
test_pvremove_2 (void)
{
  if (test_pvremove_2_skip ()) {
    skipped ("test_pvremove_2", "environment variable set");
    return 0;
  }

  const char *_features5083[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features5083)) {
    skipped ("test_pvremove_2", "group %s not available in daemon",
             _features5083[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_pvremove_2 */
  const char *_arg5085 = "/dev/sda";
  int _ret5084;
  _ret5084 = guestfs_blockdev_setrw (g, _arg5085);
  if (_ret5084 == -1)
    return -1;
  int _ret5087;
  _ret5087 = guestfs_umount_all (g);
  if (_ret5087 == -1)
    return -1;
  int _ret5089;
  _ret5089 = guestfs_lvm_remove_all (g);
  if (_ret5089 == -1)
    return -1;

  /* TestResult for pvremove (2) */
  const char *_arg5091 = "/dev/sda";
  const char *_arg5092 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, _arg5091, _arg5092);
  if (ret7 == -1)
    return -1;
  const char *_arg5094 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg5094);
  if (ret6 == -1)
    return -1;
  const char *_arg5096 = "VG";
  const char *_arg5097_0 = "/dev/sda1";
  const char *const _arg5097[] = {
    _arg5097_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg5096, (char **) _arg5097);
  if (ret5 == -1)
    return -1;
  const char *_arg5099 = "LV1";
  const char *_arg5100 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg5099, _arg5100, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg5103 = "LV2";
  const char *_arg5104 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg5103, _arg5104, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg5107 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, _arg5107);
  if (ret2 == -1)
    return -1;
  const char *_arg5109 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, _arg5109);
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
test_vgremove_0 (void)
{
  if (test_vgremove_0_skip ()) {
    skipped ("test_vgremove_0", "environment variable set");
    return 0;
  }

  const char *_features5112[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features5112)) {
    skipped ("test_vgremove_0", "group %s not available in daemon",
             _features5112[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_vgremove_0 */
  const char *_arg5114 = "/dev/sda";
  int _ret5113;
  _ret5113 = guestfs_blockdev_setrw (g, _arg5114);
  if (_ret5113 == -1)
    return -1;
  int _ret5116;
  _ret5116 = guestfs_umount_all (g);
  if (_ret5116 == -1)
    return -1;
  int _ret5118;
  _ret5118 = guestfs_lvm_remove_all (g);
  if (_ret5118 == -1)
    return -1;

  /* TestResult for vgremove (0) */
  const char *_arg5120 = "/dev/sda";
  const char *_arg5121 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg5120, _arg5121);
  if (ret6 == -1)
    return -1;
  const char *_arg5123 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg5123);
  if (ret5 == -1)
    return -1;
  const char *_arg5125 = "VG";
  const char *_arg5126_0 = "/dev/sda1";
  const char *const _arg5126[] = {
    _arg5126_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg5125, (char **) _arg5126);
  if (ret4 == -1)
    return -1;
  const char *_arg5128 = "LV1";
  const char *_arg5129 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg5128, _arg5129, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg5132 = "LV2";
  const char *_arg5133 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg5132, _arg5133, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg5136 = "VG";
  int ret1;
  ret1 = guestfs_vgremove (g, _arg5136);
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
test_vgremove_1 (void)
{
  if (test_vgremove_1_skip ()) {
    skipped ("test_vgremove_1", "environment variable set");
    return 0;
  }

  const char *_features5139[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features5139)) {
    skipped ("test_vgremove_1", "group %s not available in daemon",
             _features5139[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_vgremove_1 */
  const char *_arg5141 = "/dev/sda";
  int _ret5140;
  _ret5140 = guestfs_blockdev_setrw (g, _arg5141);
  if (_ret5140 == -1)
    return -1;
  int _ret5143;
  _ret5143 = guestfs_umount_all (g);
  if (_ret5143 == -1)
    return -1;
  int _ret5145;
  _ret5145 = guestfs_lvm_remove_all (g);
  if (_ret5145 == -1)
    return -1;

  /* TestResult for vgremove (1) */
  const char *_arg5147 = "/dev/sda";
  const char *_arg5148 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg5147, _arg5148);
  if (ret6 == -1)
    return -1;
  const char *_arg5150 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg5150);
  if (ret5 == -1)
    return -1;
  const char *_arg5152 = "VG";
  const char *_arg5153_0 = "/dev/sda1";
  const char *const _arg5153[] = {
    _arg5153_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg5152, (char **) _arg5153);
  if (ret4 == -1)
    return -1;
  const char *_arg5155 = "LV1";
  const char *_arg5156 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg5155, _arg5156, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg5159 = "LV2";
  const char *_arg5160 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg5159, _arg5160, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg5163 = "VG";
  int ret1;
  ret1 = guestfs_vgremove (g, _arg5163);
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
test_lvremove_0 (void)
{
  if (test_lvremove_0_skip ()) {
    skipped ("test_lvremove_0", "environment variable set");
    return 0;
  }

  const char *_features5166[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features5166)) {
    skipped ("test_lvremove_0", "group %s not available in daemon",
             _features5166[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_lvremove_0 */
  const char *_arg5168 = "/dev/sda";
  int _ret5167;
  _ret5167 = guestfs_blockdev_setrw (g, _arg5168);
  if (_ret5167 == -1)
    return -1;
  int _ret5170;
  _ret5170 = guestfs_umount_all (g);
  if (_ret5170 == -1)
    return -1;
  int _ret5172;
  _ret5172 = guestfs_lvm_remove_all (g);
  if (_ret5172 == -1)
    return -1;

  /* TestResult for lvremove (0) */
  const char *_arg5174 = "/dev/sda";
  const char *_arg5175 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg5174, _arg5175);
  if (ret6 == -1)
    return -1;
  const char *_arg5177 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg5177);
  if (ret5 == -1)
    return -1;
  const char *_arg5179 = "VG";
  const char *_arg5180_0 = "/dev/sda1";
  const char *const _arg5180[] = {
    _arg5180_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg5179, (char **) _arg5180);
  if (ret4 == -1)
    return -1;
  const char *_arg5182 = "LV1";
  const char *_arg5183 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg5182, _arg5183, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg5186 = "LV2";
  const char *_arg5187 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg5186, _arg5187, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg5190 = "/dev/VG/LV1";
  int ret1;
  ret1 = guestfs_lvremove (g, _arg5190);
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
test_lvremove_1 (void)
{
  if (test_lvremove_1_skip ()) {
    skipped ("test_lvremove_1", "environment variable set");
    return 0;
  }

  const char *_features5193[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features5193)) {
    skipped ("test_lvremove_1", "group %s not available in daemon",
             _features5193[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_lvremove_1 */
  const char *_arg5195 = "/dev/sda";
  int _ret5194;
  _ret5194 = guestfs_blockdev_setrw (g, _arg5195);
  if (_ret5194 == -1)
    return -1;
  int _ret5197;
  _ret5197 = guestfs_umount_all (g);
  if (_ret5197 == -1)
    return -1;
  int _ret5199;
  _ret5199 = guestfs_lvm_remove_all (g);
  if (_ret5199 == -1)
    return -1;

  /* TestResult for lvremove (1) */
  const char *_arg5201 = "/dev/sda";
  const char *_arg5202 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg5201, _arg5202);
  if (ret6 == -1)
    return -1;
  const char *_arg5204 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg5204);
  if (ret5 == -1)
    return -1;
  const char *_arg5206 = "VG";
  const char *_arg5207_0 = "/dev/sda1";
  const char *const _arg5207[] = {
    _arg5207_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg5206, (char **) _arg5207);
  if (ret4 == -1)
    return -1;
  const char *_arg5209 = "LV1";
  const char *_arg5210 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg5209, _arg5210, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg5213 = "LV2";
  const char *_arg5214 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg5213, _arg5214, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg5217 = "/dev/VG";
  int ret1;
  ret1 = guestfs_lvremove (g, _arg5217);
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
test_lvremove_2 (void)
{
  if (test_lvremove_2_skip ()) {
    skipped ("test_lvremove_2", "environment variable set");
    return 0;
  }

  const char *_features5220[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features5220)) {
    skipped ("test_lvremove_2", "group %s not available in daemon",
             _features5220[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_lvremove_2 */
  const char *_arg5222 = "/dev/sda";
  int _ret5221;
  _ret5221 = guestfs_blockdev_setrw (g, _arg5222);
  if (_ret5221 == -1)
    return -1;
  int _ret5224;
  _ret5224 = guestfs_umount_all (g);
  if (_ret5224 == -1)
    return -1;
  int _ret5226;
  _ret5226 = guestfs_lvm_remove_all (g);
  if (_ret5226 == -1)
    return -1;

  /* TestResult for lvremove (2) */
  const char *_arg5228 = "/dev/sda";
  const char *_arg5229 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, _arg5228, _arg5229);
  if (ret6 == -1)
    return -1;
  const char *_arg5231 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg5231);
  if (ret5 == -1)
    return -1;
  const char *_arg5233 = "VG";
  const char *_arg5234_0 = "/dev/sda1";
  const char *const _arg5234[] = {
    _arg5234_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg5233, (char **) _arg5234);
  if (ret4 == -1)
    return -1;
  const char *_arg5236 = "LV1";
  const char *_arg5237 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg5236, _arg5237, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg5240 = "LV2";
  const char *_arg5241 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg5240, _arg5241, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg5244 = "/dev/VG";
  int ret1;
  ret1 = guestfs_lvremove (g, _arg5244);
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
test_mount_ro_0 (void)
{
  if (test_mount_ro_0_skip ()) {
    skipped ("test_mount_ro_0", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_mount_ro_0: create ext2 on /dev/sda1 */
  const char *_arg5248 = "/dev/sda";
  int _ret5247;
  _ret5247 = guestfs_blockdev_setrw (g, _arg5248);
  if (_ret5247 == -1)
    return -1;
  int _ret5250;
  _ret5250 = guestfs_umount_all (g);
  if (_ret5250 == -1)
    return -1;
  int _ret5252;
  _ret5252 = guestfs_lvm_remove_all (g);
  if (_ret5252 == -1)
    return -1;
  const char *_arg5255 = "/dev/sda";
  const char *_arg5256 = "mbr";
  int _ret5254;
  _ret5254 = guestfs_part_disk (g, _arg5255, _arg5256);
  if (_ret5254 == -1)
    return -1;
  const char *_arg5259 = "ext2";
  const char *_arg5260 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs5261;
  _optargs5261.bitmask = UINT64_C(0x0);
  int _ret5258;
  _ret5258 = guestfs_mkfs_opts_argv (g, _arg5259, _arg5260, &_optargs5261);
  if (_ret5258 == -1)
    return -1;
  const char *_arg5263 = "/dev/sda1";
  const char *_arg5264 = "/";
  int _ret5262;
  _ret5262 = guestfs_mount (g, _arg5263, _arg5264);
  if (_ret5262 == -1)
    return -1;

  /* TestLastFail for mount_ro (0) */
  const char *_arg5267 = "/";
  struct guestfs_umount_opts_argv _optargs5268;
  _optargs5268.force = 0;
  _optargs5268.lazyunmount = 0;
  _optargs5268.bitmask = UINT64_C(0x3);
  int _ret5266;
  _ret5266 = guestfs_umount_opts_argv (g, _arg5267, &_optargs5268);
  if (_ret5266 == -1)
    return -1;
  const char *_arg5270 = "/dev/sda1";
  const char *_arg5271 = "/";
  int _ret5269;
  _ret5269 = guestfs_mount_ro (g, _arg5270, _arg5271);
  if (_ret5269 == -1)
    return -1;
  const char *_arg5274 = "/new";
  int _ret5273;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret5273 = guestfs_touch (g, _arg5274);
  guestfs_pop_error_handler (g);
  if (_ret5273 != -1)
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
test_mount_ro_1 (void)
{
  if (test_mount_ro_1_skip ()) {
    skipped ("test_mount_ro_1", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_mount_ro_1: create ext2 on /dev/sda1 */
  const char *_arg5277 = "/dev/sda";
  int _ret5276;
  _ret5276 = guestfs_blockdev_setrw (g, _arg5277);
  if (_ret5276 == -1)
    return -1;
  int _ret5279;
  _ret5279 = guestfs_umount_all (g);
  if (_ret5279 == -1)
    return -1;
  int _ret5281;
  _ret5281 = guestfs_lvm_remove_all (g);
  if (_ret5281 == -1)
    return -1;
  const char *_arg5284 = "/dev/sda";
  const char *_arg5285 = "mbr";
  int _ret5283;
  _ret5283 = guestfs_part_disk (g, _arg5284, _arg5285);
  if (_ret5283 == -1)
    return -1;
  const char *_arg5288 = "ext2";
  const char *_arg5289 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs5290;
  _optargs5290.bitmask = UINT64_C(0x0);
  int _ret5287;
  _ret5287 = guestfs_mkfs_opts_argv (g, _arg5288, _arg5289, &_optargs5290);
  if (_ret5287 == -1)
    return -1;
  const char *_arg5292 = "/dev/sda1";
  const char *_arg5293 = "/";
  int _ret5291;
  _ret5291 = guestfs_mount (g, _arg5292, _arg5293);
  if (_ret5291 == -1)
    return -1;

  /* TestResultString for mount_ro (1) */
  const char *_arg5296 = "/new";
  const char *_arg5297 = "data";
  size_t _arg5297_size = 4;
  int _ret5295;
  _ret5295 = guestfs_write (g, _arg5296, _arg5297, _arg5297_size);
  if (_ret5295 == -1)
    return -1;
  const char *_arg5300 = "/";
  struct guestfs_umount_opts_argv _optargs5301;
  _optargs5301.force = 0;
  _optargs5301.lazyunmount = 0;
  _optargs5301.bitmask = UINT64_C(0x3);
  int _ret5299;
  _ret5299 = guestfs_umount_opts_argv (g, _arg5300, &_optargs5301);
  if (_ret5299 == -1)
    return -1;
  const char *_arg5303 = "/dev/sda1";
  const char *_arg5304 = "/";
  int _ret5302;
  _ret5302 = guestfs_mount_ro (g, _arg5303, _arg5304);
  if (_ret5302 == -1)
    return -1;
  const char *_arg5306 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg5306);
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
test_tgz_in_0 (void)
{
  if (test_tgz_in_0_skip ()) {
    skipped ("test_tgz_in_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_tgz_in_0 */
  const char *_arg5309 = "/dev/sda";
  int _ret5308;
  _ret5308 = guestfs_blockdev_setrw (g, _arg5309);
  if (_ret5308 == -1)
    return -1;
  int _ret5311;
  _ret5311 = guestfs_umount_all (g);
  if (_ret5311 == -1)
    return -1;
  int _ret5313;
  _ret5313 = guestfs_lvm_remove_all (g);
  if (_ret5313 == -1)
    return -1;
  const char *_arg5316 = "/dev/sdb1";
  const char *_arg5317 = "/";
  int _ret5315;
  _ret5315 = guestfs_mount (g, _arg5316, _arg5317);
  if (_ret5315 == -1)
    return -1;

  /* TestResultString for tgz_in (0) */
  const char *_arg5320 = "/tgz_in";
  int _ret5319;
  _ret5319 = guestfs_mkdir (g, _arg5320);
  if (_ret5319 == -1)
    return -1;
  const char *_arg5324 = "/tgz_in";
  int _ret5322;
  _ret5322 = guestfs_tgz_in (g, "../data/helloworld.tar.gz", _arg5324);
  if (_ret5322 == -1)
    return -1;
  const char *_arg5326 = "/tgz_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg5326);
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
test_tar_in_0 (void)
{
  if (test_tar_in_0_skip ()) {
    skipped ("test_tar_in_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_tar_in_0 */
  const char *_arg5329 = "/dev/sda";
  int _ret5328;
  _ret5328 = guestfs_blockdev_setrw (g, _arg5329);
  if (_ret5328 == -1)
    return -1;
  int _ret5331;
  _ret5331 = guestfs_umount_all (g);
  if (_ret5331 == -1)
    return -1;
  int _ret5333;
  _ret5333 = guestfs_lvm_remove_all (g);
  if (_ret5333 == -1)
    return -1;
  const char *_arg5336 = "/dev/sdb1";
  const char *_arg5337 = "/";
  int _ret5335;
  _ret5335 = guestfs_mount (g, _arg5336, _arg5337);
  if (_ret5335 == -1)
    return -1;

  /* TestResultString for tar_in (0) */
  const char *_arg5340 = "/tar_in";
  int _ret5339;
  _ret5339 = guestfs_mkdir (g, _arg5340);
  if (_ret5339 == -1)
    return -1;
  const char *_arg5344 = "/tar_in";
  struct guestfs_tar_in_opts_argv _optargs5345;
  _optargs5345.bitmask = UINT64_C(0x0);
  int _ret5342;
  _ret5342 = guestfs_tar_in_opts_argv (g, "../data/helloworld.tar", _arg5344, &_optargs5345);
  if (_ret5342 == -1)
    return -1;
  const char *_arg5346 = "/tar_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg5346);
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
test_tar_in_1 (void)
{
  if (test_tar_in_1_skip ()) {
    skipped ("test_tar_in_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_tar_in_1 */
  const char *_arg5349 = "/dev/sda";
  int _ret5348;
  _ret5348 = guestfs_blockdev_setrw (g, _arg5349);
  if (_ret5348 == -1)
    return -1;
  int _ret5351;
  _ret5351 = guestfs_umount_all (g);
  if (_ret5351 == -1)
    return -1;
  int _ret5353;
  _ret5353 = guestfs_lvm_remove_all (g);
  if (_ret5353 == -1)
    return -1;
  const char *_arg5356 = "/dev/sdb1";
  const char *_arg5357 = "/";
  int _ret5355;
  _ret5355 = guestfs_mount (g, _arg5356, _arg5357);
  if (_ret5355 == -1)
    return -1;

  /* TestResultString for tar_in (1) */
  const char *_arg5360 = "/tar_in_gz";
  int _ret5359;
  _ret5359 = guestfs_mkdir (g, _arg5360);
  if (_ret5359 == -1)
    return -1;
  const char *_arg5364 = "/tar_in_gz";
  struct guestfs_tar_in_opts_argv _optargs5365;
  _optargs5365.compress = "gzip";
  _optargs5365.bitmask = UINT64_C(0x1);
  int _ret5362;
  _ret5362 = guestfs_tar_in_opts_argv (g, "../data/helloworld.tar.gz", _arg5364, &_optargs5365);
  if (_ret5362 == -1)
    return -1;
  const char *_arg5366 = "/tar_in_gz/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg5366);
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
test_tar_in_2 (void)
{
  if (test_tar_in_2_skip ()) {
    skipped ("test_tar_in_2", "environment variable set");
    return 0;
  }

  const char *_features5368[] = { "xz", NULL };
  if (!guestfs_feature_available (g, (char **) _features5368)) {
    skipped ("test_tar_in_2", "group %s not available in daemon",
             _features5368[0]);
    return 0;
  }

  /* InitScratchFS for test_tar_in_2 */
  const char *_arg5370 = "/dev/sda";
  int _ret5369;
  _ret5369 = guestfs_blockdev_setrw (g, _arg5370);
  if (_ret5369 == -1)
    return -1;
  int _ret5372;
  _ret5372 = guestfs_umount_all (g);
  if (_ret5372 == -1)
    return -1;
  int _ret5374;
  _ret5374 = guestfs_lvm_remove_all (g);
  if (_ret5374 == -1)
    return -1;
  const char *_arg5377 = "/dev/sdb1";
  const char *_arg5378 = "/";
  int _ret5376;
  _ret5376 = guestfs_mount (g, _arg5377, _arg5378);
  if (_ret5376 == -1)
    return -1;

  /* TestResultString for tar_in (2) */
  const char *_arg5381 = "/tar_in_xz";
  int _ret5380;
  _ret5380 = guestfs_mkdir (g, _arg5381);
  if (_ret5380 == -1)
    return -1;
  const char *_arg5385 = "/tar_in_xz";
  struct guestfs_tar_in_opts_argv _optargs5386;
  _optargs5386.compress = "xz";
  _optargs5386.bitmask = UINT64_C(0x1);
  int _ret5383;
  _ret5383 = guestfs_tar_in_opts_argv (g, "../data/helloworld.tar.xz", _arg5385, &_optargs5386);
  if (_ret5383 == -1)
    return -1;
  const char *_arg5387 = "/tar_in_xz/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg5387);
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
test_checksum_0 (void)
{
  if (test_checksum_0_skip ()) {
    skipped ("test_checksum_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_checksum_0 */
  const char *_arg5390 = "/dev/sda";
  int _ret5389;
  _ret5389 = guestfs_blockdev_setrw (g, _arg5390);
  if (_ret5389 == -1)
    return -1;
  int _ret5392;
  _ret5392 = guestfs_umount_all (g);
  if (_ret5392 == -1)
    return -1;
  int _ret5394;
  _ret5394 = guestfs_lvm_remove_all (g);
  if (_ret5394 == -1)
    return -1;
  const char *_arg5397 = "/dev/sdd";
  const char *_arg5398 = "/";
  int _ret5396;
  _ret5396 = guestfs_mount_ro (g, _arg5397, _arg5398);
  if (_ret5396 == -1)
    return -1;

  /* TestResultString for checksum (0) */
  const char *_arg5400 = "crc";
  const char *_arg5401 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg5400, _arg5401);
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
test_checksum_1 (void)
{
  if (test_checksum_1_skip ()) {
    skipped ("test_checksum_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_checksum_1 */
  const char *_arg5404 = "/dev/sda";
  int _ret5403;
  _ret5403 = guestfs_blockdev_setrw (g, _arg5404);
  if (_ret5403 == -1)
    return -1;
  int _ret5406;
  _ret5406 = guestfs_umount_all (g);
  if (_ret5406 == -1)
    return -1;
  int _ret5408;
  _ret5408 = guestfs_lvm_remove_all (g);
  if (_ret5408 == -1)
    return -1;
  const char *_arg5411 = "/dev/sdd";
  const char *_arg5412 = "/";
  int _ret5410;
  _ret5410 = guestfs_mount_ro (g, _arg5411, _arg5412);
  if (_ret5410 == -1)
    return -1;

  /* TestLastFail for checksum (1) */
  const char *_arg5415 = "crc";
  const char *_arg5416 = "/notexists";
  CLEANUP_FREE char *_ret5414;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret5414 = guestfs_checksum (g, _arg5415, _arg5416);
  guestfs_pop_error_handler (g);
  if (_ret5414 != NULL)
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
test_checksum_2 (void)
{
  if (test_checksum_2_skip ()) {
    skipped ("test_checksum_2", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_checksum_2 */
  const char *_arg5419 = "/dev/sda";
  int _ret5418;
  _ret5418 = guestfs_blockdev_setrw (g, _arg5419);
  if (_ret5418 == -1)
    return -1;
  int _ret5421;
  _ret5421 = guestfs_umount_all (g);
  if (_ret5421 == -1)
    return -1;
  int _ret5423;
  _ret5423 = guestfs_lvm_remove_all (g);
  if (_ret5423 == -1)
    return -1;
  const char *_arg5426 = "/dev/sdd";
  const char *_arg5427 = "/";
  int _ret5425;
  _ret5425 = guestfs_mount_ro (g, _arg5426, _arg5427);
  if (_ret5425 == -1)
    return -1;

  /* TestResultString for checksum (2) */
  const char *_arg5429 = "md5";
  const char *_arg5430 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg5429, _arg5430);
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
test_checksum_3 (void)
{
  if (test_checksum_3_skip ()) {
    skipped ("test_checksum_3", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_checksum_3 */
  const char *_arg5433 = "/dev/sda";
  int _ret5432;
  _ret5432 = guestfs_blockdev_setrw (g, _arg5433);
  if (_ret5432 == -1)
    return -1;
  int _ret5435;
  _ret5435 = guestfs_umount_all (g);
  if (_ret5435 == -1)
    return -1;
  int _ret5437;
  _ret5437 = guestfs_lvm_remove_all (g);
  if (_ret5437 == -1)
    return -1;
  const char *_arg5440 = "/dev/sdd";
  const char *_arg5441 = "/";
  int _ret5439;
  _ret5439 = guestfs_mount_ro (g, _arg5440, _arg5441);
  if (_ret5439 == -1)
    return -1;

  /* TestResultString for checksum (3) */
  const char *_arg5443 = "sha1";
  const char *_arg5444 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg5443, _arg5444);
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
test_checksum_4 (void)
{
  if (test_checksum_4_skip ()) {
    skipped ("test_checksum_4", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_checksum_4 */
  const char *_arg5447 = "/dev/sda";
  int _ret5446;
  _ret5446 = guestfs_blockdev_setrw (g, _arg5447);
  if (_ret5446 == -1)
    return -1;
  int _ret5449;
  _ret5449 = guestfs_umount_all (g);
  if (_ret5449 == -1)
    return -1;
  int _ret5451;
  _ret5451 = guestfs_lvm_remove_all (g);
  if (_ret5451 == -1)
    return -1;
  const char *_arg5454 = "/dev/sdd";
  const char *_arg5455 = "/";
  int _ret5453;
  _ret5453 = guestfs_mount_ro (g, _arg5454, _arg5455);
  if (_ret5453 == -1)
    return -1;

  /* TestResultString for checksum (4) */
  const char *_arg5457 = "sha224";
  const char *_arg5458 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg5457, _arg5458);
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
test_checksum_5 (void)
{
  if (test_checksum_5_skip ()) {
    skipped ("test_checksum_5", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_checksum_5 */
  const char *_arg5461 = "/dev/sda";
  int _ret5460;
  _ret5460 = guestfs_blockdev_setrw (g, _arg5461);
  if (_ret5460 == -1)
    return -1;
  int _ret5463;
  _ret5463 = guestfs_umount_all (g);
  if (_ret5463 == -1)
    return -1;
  int _ret5465;
  _ret5465 = guestfs_lvm_remove_all (g);
  if (_ret5465 == -1)
    return -1;
  const char *_arg5468 = "/dev/sdd";
  const char *_arg5469 = "/";
  int _ret5467;
  _ret5467 = guestfs_mount_ro (g, _arg5468, _arg5469);
  if (_ret5467 == -1)
    return -1;

  /* TestResultString for checksum (5) */
  const char *_arg5471 = "sha256";
  const char *_arg5472 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg5471, _arg5472);
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
test_checksum_6 (void)
{
  if (test_checksum_6_skip ()) {
    skipped ("test_checksum_6", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_checksum_6 */
  const char *_arg5475 = "/dev/sda";
  int _ret5474;
  _ret5474 = guestfs_blockdev_setrw (g, _arg5475);
  if (_ret5474 == -1)
    return -1;
  int _ret5477;
  _ret5477 = guestfs_umount_all (g);
  if (_ret5477 == -1)
    return -1;
  int _ret5479;
  _ret5479 = guestfs_lvm_remove_all (g);
  if (_ret5479 == -1)
    return -1;
  const char *_arg5482 = "/dev/sdd";
  const char *_arg5483 = "/";
  int _ret5481;
  _ret5481 = guestfs_mount_ro (g, _arg5482, _arg5483);
  if (_ret5481 == -1)
    return -1;

  /* TestResultString for checksum (6) */
  const char *_arg5485 = "sha384";
  const char *_arg5486 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg5485, _arg5486);
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
test_checksum_7 (void)
{
  if (test_checksum_7_skip ()) {
    skipped ("test_checksum_7", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_checksum_7 */
  const char *_arg5489 = "/dev/sda";
  int _ret5488;
  _ret5488 = guestfs_blockdev_setrw (g, _arg5489);
  if (_ret5488 == -1)
    return -1;
  int _ret5491;
  _ret5491 = guestfs_umount_all (g);
  if (_ret5491 == -1)
    return -1;
  int _ret5493;
  _ret5493 = guestfs_lvm_remove_all (g);
  if (_ret5493 == -1)
    return -1;
  const char *_arg5496 = "/dev/sdd";
  const char *_arg5497 = "/";
  int _ret5495;
  _ret5495 = guestfs_mount_ro (g, _arg5496, _arg5497);
  if (_ret5495 == -1)
    return -1;

  /* TestResultString for checksum (7) */
  const char *_arg5499 = "sha512";
  const char *_arg5500 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg5499, _arg5500);
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
test_checksum_8 (void)
{
  if (test_checksum_8_skip ()) {
    skipped ("test_checksum_8", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_checksum_8 */
  const char *_arg5503 = "/dev/sda";
  int _ret5502;
  _ret5502 = guestfs_blockdev_setrw (g, _arg5503);
  if (_ret5502 == -1)
    return -1;
  int _ret5505;
  _ret5505 = guestfs_umount_all (g);
  if (_ret5505 == -1)
    return -1;
  int _ret5507;
  _ret5507 = guestfs_lvm_remove_all (g);
  if (_ret5507 == -1)
    return -1;
  const char *_arg5510 = "/dev/sdd";
  const char *_arg5511 = "/";
  int _ret5509;
  _ret5509 = guestfs_mount_ro (g, _arg5510, _arg5511);
  if (_ret5509 == -1)
    return -1;

  /* TestResultString for checksum (8) */
  const char *_arg5513 = "sha512";
  const char *_arg5514 = "/abssymlink";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg5513, _arg5514);
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
test_download_0 (void)
{
  if (test_download_0_skip ()) {
    skipped ("test_download_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_download_0 */
  const char *_arg5517 = "/dev/sda";
  int _ret5516;
  _ret5516 = guestfs_blockdev_setrw (g, _arg5517);
  if (_ret5516 == -1)
    return -1;
  int _ret5519;
  _ret5519 = guestfs_umount_all (g);
  if (_ret5519 == -1)
    return -1;
  int _ret5521;
  _ret5521 = guestfs_lvm_remove_all (g);
  if (_ret5521 == -1)
    return -1;
  const char *_arg5524 = "/dev/sdb1";
  const char *_arg5525 = "/";
  int _ret5523;
  _ret5523 = guestfs_mount (g, _arg5524, _arg5525);
  if (_ret5523 == -1)
    return -1;

  /* TestResultString for download (0) */
  const char *_arg5528 = "/download";
  int _ret5527;
  _ret5527 = guestfs_mkdir (g, _arg5528);
  if (_ret5527 == -1)
    return -1;
  const char *_arg5532 = "/download/COPYING.LIB";
  int _ret5530;
  _ret5530 = guestfs_upload (g, "../../COPYING.LIB", _arg5532);
  if (_ret5530 == -1)
    return -1;
  const char *_arg5535 = "/download/COPYING.LIB";
  int _ret5534;
  _ret5534 = guestfs_download (g, _arg5535, "testdownload.tmp");
  if (_ret5534 == -1)
    return -1;
  const char *_arg5540 = "/download/upload";
  int _ret5538;
  _ret5538 = guestfs_upload (g, "testdownload.tmp", _arg5540);
  if (_ret5538 == -1)
    return -1;
  const char *_arg5542 = "md5";
  const char *_arg5543 = "/download/upload";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg5542, _arg5543);
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
test_upload_0 (void)
{
  if (test_upload_0_skip ()) {
    skipped ("test_upload_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_upload_0 */
  const char *_arg5546 = "/dev/sda";
  int _ret5545;
  _ret5545 = guestfs_blockdev_setrw (g, _arg5546);
  if (_ret5545 == -1)
    return -1;
  int _ret5548;
  _ret5548 = guestfs_umount_all (g);
  if (_ret5548 == -1)
    return -1;
  int _ret5550;
  _ret5550 = guestfs_lvm_remove_all (g);
  if (_ret5550 == -1)
    return -1;
  const char *_arg5553 = "/dev/sdb1";
  const char *_arg5554 = "/";
  int _ret5552;
  _ret5552 = guestfs_mount (g, _arg5553, _arg5554);
  if (_ret5552 == -1)
    return -1;

  /* TestResultString for upload (0) */
  const char *_arg5557 = "/upload";
  int _ret5556;
  _ret5556 = guestfs_mkdir (g, _arg5557);
  if (_ret5556 == -1)
    return -1;
  const char *_arg5561 = "/upload/COPYING.LIB";
  int _ret5559;
  _ret5559 = guestfs_upload (g, "../../COPYING.LIB", _arg5561);
  if (_ret5559 == -1)
    return -1;
  const char *_arg5563 = "md5";
  const char *_arg5564 = "/upload/COPYING.LIB";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, _arg5563, _arg5564);
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
test_blockdev_rereadpt_0 (void)
{
  if (test_blockdev_rereadpt_0_skip ()) {
    skipped ("test_blockdev_rereadpt_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_rereadpt_0 */
  const char *_arg5567 = "/dev/sda";
  int _ret5566;
  _ret5566 = guestfs_blockdev_setrw (g, _arg5567);
  if (_ret5566 == -1)
    return -1;
  int _ret5569;
  _ret5569 = guestfs_umount_all (g);
  if (_ret5569 == -1)
    return -1;
  int _ret5571;
  _ret5571 = guestfs_lvm_remove_all (g);
  if (_ret5571 == -1)
    return -1;

  /* TestRun for blockdev_rereadpt (0) */
  const char *_arg5574 = "/dev/sda";
  int _ret5573;
  _ret5573 = guestfs_blockdev_rereadpt (g, _arg5574);
  if (_ret5573 == -1)
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
test_blockdev_flushbufs_0 (void)
{
  if (test_blockdev_flushbufs_0_skip ()) {
    skipped ("test_blockdev_flushbufs_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_flushbufs_0 */
  const char *_arg5577 = "/dev/sda";
  int _ret5576;
  _ret5576 = guestfs_blockdev_setrw (g, _arg5577);
  if (_ret5576 == -1)
    return -1;
  int _ret5579;
  _ret5579 = guestfs_umount_all (g);
  if (_ret5579 == -1)
    return -1;
  int _ret5581;
  _ret5581 = guestfs_lvm_remove_all (g);
  if (_ret5581 == -1)
    return -1;

  /* TestRun for blockdev_flushbufs (0) */
  const char *_arg5584 = "/dev/sda";
  int _ret5583;
  _ret5583 = guestfs_blockdev_flushbufs (g, _arg5584);
  if (_ret5583 == -1)
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
test_blockdev_getsize64_0 (void)
{
  if (test_blockdev_getsize64_0_skip ()) {
    skipped ("test_blockdev_getsize64_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_getsize64_0 */
  const char *_arg5587 = "/dev/sda";
  int _ret5586;
  _ret5586 = guestfs_blockdev_setrw (g, _arg5587);
  if (_ret5586 == -1)
    return -1;
  int _ret5589;
  _ret5589 = guestfs_umount_all (g);
  if (_ret5589 == -1)
    return -1;
  int _ret5591;
  _ret5591 = guestfs_lvm_remove_all (g);
  if (_ret5591 == -1)
    return -1;

  /* TestResult for blockdev_getsize64 (0) */
  const char *_arg5593 = "/dev/sda";
  int64_t ret;
  ret = guestfs_blockdev_getsize64 (g, _arg5593);
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
test_blockdev_getsz_0 (void)
{
  if (test_blockdev_getsz_0_skip ()) {
    skipped ("test_blockdev_getsz_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_getsz_0 */
  const char *_arg5596 = "/dev/sda";
  int _ret5595;
  _ret5595 = guestfs_blockdev_setrw (g, _arg5596);
  if (_ret5595 == -1)
    return -1;
  int _ret5598;
  _ret5598 = guestfs_umount_all (g);
  if (_ret5598 == -1)
    return -1;
  int _ret5600;
  _ret5600 = guestfs_lvm_remove_all (g);
  if (_ret5600 == -1)
    return -1;

  /* TestResult for blockdev_getsz (0) */
  const char *_arg5602 = "/dev/sda";
  int64_t ret;
  ret = guestfs_blockdev_getsz (g, _arg5602);
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
test_blockdev_getss_0 (void)
{
  if (test_blockdev_getss_0_skip ()) {
    skipped ("test_blockdev_getss_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_getss_0 */
  const char *_arg5605 = "/dev/sda";
  int _ret5604;
  _ret5604 = guestfs_blockdev_setrw (g, _arg5605);
  if (_ret5604 == -1)
    return -1;
  int _ret5607;
  _ret5607 = guestfs_umount_all (g);
  if (_ret5607 == -1)
    return -1;
  int _ret5609;
  _ret5609 = guestfs_lvm_remove_all (g);
  if (_ret5609 == -1)
    return -1;

  /* TestResult for blockdev_getss (0) */
  const char *_arg5611 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getss (g, _arg5611);
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
test_blockdev_getro_0 (void)
{
  if (test_blockdev_getro_0_skip ()) {
    skipped ("test_blockdev_getro_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_getro_0 */
  const char *_arg5614 = "/dev/sda";
  int _ret5613;
  _ret5613 = guestfs_blockdev_setrw (g, _arg5614);
  if (_ret5613 == -1)
    return -1;
  int _ret5616;
  _ret5616 = guestfs_umount_all (g);
  if (_ret5616 == -1)
    return -1;
  int _ret5618;
  _ret5618 = guestfs_lvm_remove_all (g);
  if (_ret5618 == -1)
    return -1;

  /* TestResultTrue for blockdev_getro (0) */
  const char *_arg5621 = "/dev/sda";
  int _ret5620;
  _ret5620 = guestfs_blockdev_setro (g, _arg5621);
  if (_ret5620 == -1)
    return -1;
  const char *_arg5623 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, _arg5623);
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
test_blockdev_setrw_0 (void)
{
  if (test_blockdev_setrw_0_skip ()) {
    skipped ("test_blockdev_setrw_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_setrw_0 */
  const char *_arg5626 = "/dev/sda";
  int _ret5625;
  _ret5625 = guestfs_blockdev_setrw (g, _arg5626);
  if (_ret5625 == -1)
    return -1;
  int _ret5628;
  _ret5628 = guestfs_umount_all (g);
  if (_ret5628 == -1)
    return -1;
  int _ret5630;
  _ret5630 = guestfs_lvm_remove_all (g);
  if (_ret5630 == -1)
    return -1;

  /* TestResultFalse for blockdev_setrw (0) */
  const char *_arg5633 = "/dev/sda";
  int _ret5632;
  _ret5632 = guestfs_blockdev_setrw (g, _arg5633);
  if (_ret5632 == -1)
    return -1;
  const char *_arg5635 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, _arg5635);
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
test_blockdev_setro_0 (void)
{
  if (test_blockdev_setro_0_skip ()) {
    skipped ("test_blockdev_setro_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_setro_0 */
  const char *_arg5638 = "/dev/sda";
  int _ret5637;
  _ret5637 = guestfs_blockdev_setrw (g, _arg5638);
  if (_ret5637 == -1)
    return -1;
  int _ret5640;
  _ret5640 = guestfs_umount_all (g);
  if (_ret5640 == -1)
    return -1;
  int _ret5642;
  _ret5642 = guestfs_lvm_remove_all (g);
  if (_ret5642 == -1)
    return -1;

  /* TestResultTrue for blockdev_setro (0) */
  const char *_arg5645 = "/dev/sda";
  int _ret5644;
  _ret5644 = guestfs_blockdev_setro (g, _arg5645);
  if (_ret5644 == -1)
    return -1;
  const char *_arg5647 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, _arg5647);
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
test_tune2fs_l_0 (void)
{
  if (test_tune2fs_l_0_skip ()) {
    skipped ("test_tune2fs_l_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_tune2fs_l_0 */
  const char *_arg5650 = "/dev/sda";
  int _ret5649;
  _ret5649 = guestfs_blockdev_setrw (g, _arg5650);
  if (_ret5649 == -1)
    return -1;
  int _ret5652;
  _ret5652 = guestfs_umount_all (g);
  if (_ret5652 == -1)
    return -1;
  int _ret5654;
  _ret5654 = guestfs_lvm_remove_all (g);
  if (_ret5654 == -1)
    return -1;
  const char *_arg5657 = "/dev/sdb1";
  const char *_arg5658 = "/";
  int _ret5656;
  _ret5656 = guestfs_mount (g, _arg5657, _arg5658);
  if (_ret5656 == -1)
    return -1;

  /* TestResult for tune2fs_l (0) */
  const char *_arg5660 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, _arg5660);
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
test_statvfs_0 (void)
{
  if (test_statvfs_0_skip ()) {
    skipped ("test_statvfs_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_statvfs_0 */
  const char *_arg5663 = "/dev/sda";
  int _ret5662;
  _ret5662 = guestfs_blockdev_setrw (g, _arg5663);
  if (_ret5662 == -1)
    return -1;
  int _ret5665;
  _ret5665 = guestfs_umount_all (g);
  if (_ret5665 == -1)
    return -1;
  int _ret5667;
  _ret5667 = guestfs_lvm_remove_all (g);
  if (_ret5667 == -1)
    return -1;
  const char *_arg5670 = "/dev/sdd";
  const char *_arg5671 = "/";
  int _ret5669;
  _ret5669 = guestfs_mount_ro (g, _arg5670, _arg5671);
  if (_ret5669 == -1)
    return -1;

  /* TestResult for statvfs (0) */
  const char *_arg5673 = "/";
  CLEANUP_FREE_STATVFS struct guestfs_statvfs *ret;
  ret = guestfs_statvfs (g, _arg5673);
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
test_lstat_0 (void)
{
  if (test_lstat_0_skip ()) {
    skipped ("test_lstat_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_lstat_0 */
  const char *_arg5676 = "/dev/sda";
  int _ret5675;
  _ret5675 = guestfs_blockdev_setrw (g, _arg5676);
  if (_ret5675 == -1)
    return -1;
  int _ret5678;
  _ret5678 = guestfs_umount_all (g);
  if (_ret5678 == -1)
    return -1;
  int _ret5680;
  _ret5680 = guestfs_lvm_remove_all (g);
  if (_ret5680 == -1)
    return -1;
  const char *_arg5683 = "/dev/sdd";
  const char *_arg5684 = "/";
  int _ret5682;
  _ret5682 = guestfs_mount_ro (g, _arg5683, _arg5684);
  if (_ret5682 == -1)
    return -1;

  /* TestResult for lstat (0) */
  const char *_arg5686 = "/empty";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_lstat (g, _arg5686);
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
test_stat_0 (void)
{
  if (test_stat_0_skip ()) {
    skipped ("test_stat_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_stat_0 */
  const char *_arg5689 = "/dev/sda";
  int _ret5688;
  _ret5688 = guestfs_blockdev_setrw (g, _arg5689);
  if (_ret5688 == -1)
    return -1;
  int _ret5691;
  _ret5691 = guestfs_umount_all (g);
  if (_ret5691 == -1)
    return -1;
  int _ret5693;
  _ret5693 = guestfs_lvm_remove_all (g);
  if (_ret5693 == -1)
    return -1;
  const char *_arg5696 = "/dev/sdd";
  const char *_arg5697 = "/";
  int _ret5695;
  _ret5695 = guestfs_mount_ro (g, _arg5696, _arg5697);
  if (_ret5695 == -1)
    return -1;

  /* TestResult for stat (0) */
  const char *_arg5699 = "/empty";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, _arg5699);
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
test_command_lines_0 (void)
{
  if (test_command_lines_0_skip ()) {
    skipped ("test_command_lines_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_lines_0 */
  const char *_arg5702 = "/dev/sda";
  int _ret5701;
  _ret5701 = guestfs_blockdev_setrw (g, _arg5702);
  if (_ret5701 == -1)
    return -1;
  int _ret5704;
  _ret5704 = guestfs_umount_all (g);
  if (_ret5704 == -1)
    return -1;
  int _ret5706;
  _ret5706 = guestfs_lvm_remove_all (g);
  if (_ret5706 == -1)
    return -1;
  const char *_arg5709 = "/dev/sdb1";
  const char *_arg5710 = "/";
  int _ret5708;
  _ret5708 = guestfs_mount (g, _arg5709, _arg5710);
  if (_ret5708 == -1)
    return -1;

  /* TestResult for command_lines (0) */
  const char *_arg5712 = "/command_lines";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg5712);
  if (ret3 == -1)
    return -1;
  const char *_arg5715 = "/command_lines/test-command";
  int ret2;
  ret2 = guestfs_upload (g, "test-command", _arg5715);
  if (ret2 == -1)
    return -1;
  const char *_arg5718 = "/command_lines/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg5718);
  if (ret1 == -1)
    return -1;
  const char *_arg5720_0 = "/command_lines/test-command";
  const char *_arg5720_1 = "1";
  const char *const _arg5720[] = {
    _arg5720_0,
    _arg5720_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg5720);
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
test_command_lines_1 (void)
{
  if (test_command_lines_1_skip ()) {
    skipped ("test_command_lines_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_lines_1 */
  const char *_arg5723 = "/dev/sda";
  int _ret5722;
  _ret5722 = guestfs_blockdev_setrw (g, _arg5723);
  if (_ret5722 == -1)
    return -1;
  int _ret5725;
  _ret5725 = guestfs_umount_all (g);
  if (_ret5725 == -1)
    return -1;
  int _ret5727;
  _ret5727 = guestfs_lvm_remove_all (g);
  if (_ret5727 == -1)
    return -1;
  const char *_arg5730 = "/dev/sdb1";
  const char *_arg5731 = "/";
  int _ret5729;
  _ret5729 = guestfs_mount (g, _arg5730, _arg5731);
  if (_ret5729 == -1)
    return -1;

  /* TestResult for command_lines (1) */
  const char *_arg5733 = "/command_lines2";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg5733);
  if (ret3 == -1)
    return -1;
  const char *_arg5736 = "/command_lines2/test-command";
  int ret2;
  ret2 = guestfs_upload (g, "test-command", _arg5736);
  if (ret2 == -1)
    return -1;
  const char *_arg5739 = "/command_lines2/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg5739);
  if (ret1 == -1)
    return -1;
  const char *_arg5741_0 = "/command_lines2/test-command";
  const char *_arg5741_1 = "2";
  const char *const _arg5741[] = {
    _arg5741_0,
    _arg5741_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg5741);
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
test_command_lines_2 (void)
{
  if (test_command_lines_2_skip ()) {
    skipped ("test_command_lines_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_lines_2 */
  const char *_arg5744 = "/dev/sda";
  int _ret5743;
  _ret5743 = guestfs_blockdev_setrw (g, _arg5744);
  if (_ret5743 == -1)
    return -1;
  int _ret5746;
  _ret5746 = guestfs_umount_all (g);
  if (_ret5746 == -1)
    return -1;
  int _ret5748;
  _ret5748 = guestfs_lvm_remove_all (g);
  if (_ret5748 == -1)
    return -1;
  const char *_arg5751 = "/dev/sdb1";
  const char *_arg5752 = "/";
  int _ret5750;
  _ret5750 = guestfs_mount (g, _arg5751, _arg5752);
  if (_ret5750 == -1)
    return -1;

  /* TestResult for command_lines (2) */
  const char *_arg5754 = "/command_lines3";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg5754);
  if (ret3 == -1)
    return -1;
  const char *_arg5757 = "/command_lines3/test-command";
  int ret2;
  ret2 = guestfs_upload (g, "test-command", _arg5757);
  if (ret2 == -1)
    return -1;
  const char *_arg5760 = "/command_lines3/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg5760);
  if (ret1 == -1)
    return -1;
  const char *_arg5762_0 = "/command_lines3/test-command";
  const char *_arg5762_1 = "3";
  const char *const _arg5762[] = {
    _arg5762_0,
    _arg5762_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg5762);
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
test_command_lines_3 (void)
{
  if (test_command_lines_3_skip ()) {
    skipped ("test_command_lines_3", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_lines_3 */
  const char *_arg5765 = "/dev/sda";
  int _ret5764;
  _ret5764 = guestfs_blockdev_setrw (g, _arg5765);
  if (_ret5764 == -1)
    return -1;
  int _ret5767;
  _ret5767 = guestfs_umount_all (g);
  if (_ret5767 == -1)
    return -1;
  int _ret5769;
  _ret5769 = guestfs_lvm_remove_all (g);
  if (_ret5769 == -1)
    return -1;
  const char *_arg5772 = "/dev/sdb1";
  const char *_arg5773 = "/";
  int _ret5771;
  _ret5771 = guestfs_mount (g, _arg5772, _arg5773);
  if (_ret5771 == -1)
    return -1;

  /* TestResult for command_lines (3) */
  const char *_arg5775 = "/command_lines4";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg5775);
  if (ret3 == -1)
    return -1;
  const char *_arg5778 = "/command_lines4/test-command";
  int ret2;
  ret2 = guestfs_upload (g, "test-command", _arg5778);
  if (ret2 == -1)
    return -1;
  const char *_arg5781 = "/command_lines4/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg5781);
  if (ret1 == -1)
    return -1;
  const char *_arg5783_0 = "/command_lines4/test-command";
  const char *_arg5783_1 = "4";
  const char *const _arg5783[] = {
    _arg5783_0,
    _arg5783_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg5783);
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
test_command_lines_4 (void)
{
  if (test_command_lines_4_skip ()) {
    skipped ("test_command_lines_4", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_lines_4 */
  const char *_arg5786 = "/dev/sda";
  int _ret5785;
  _ret5785 = guestfs_blockdev_setrw (g, _arg5786);
  if (_ret5785 == -1)
    return -1;
  int _ret5788;
  _ret5788 = guestfs_umount_all (g);
  if (_ret5788 == -1)
    return -1;
  int _ret5790;
  _ret5790 = guestfs_lvm_remove_all (g);
  if (_ret5790 == -1)
    return -1;
  const char *_arg5793 = "/dev/sdb1";
  const char *_arg5794 = "/";
  int _ret5792;
  _ret5792 = guestfs_mount (g, _arg5793, _arg5794);
  if (_ret5792 == -1)
    return -1;

  /* TestResult for command_lines (4) */
  const char *_arg5796 = "/command_lines5";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg5796);
  if (ret3 == -1)
    return -1;
  const char *_arg5799 = "/command_lines5/test-command";
  int ret2;
  ret2 = guestfs_upload (g, "test-command", _arg5799);
  if (ret2 == -1)
    return -1;
  const char *_arg5802 = "/command_lines5/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg5802);
  if (ret1 == -1)
    return -1;
  const char *_arg5804_0 = "/command_lines5/test-command";
  const char *_arg5804_1 = "5";
  const char *const _arg5804[] = {
    _arg5804_0,
    _arg5804_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg5804);
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
test_command_lines_5 (void)
{
  if (test_command_lines_5_skip ()) {
    skipped ("test_command_lines_5", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_lines_5 */
  const char *_arg5807 = "/dev/sda";
  int _ret5806;
  _ret5806 = guestfs_blockdev_setrw (g, _arg5807);
  if (_ret5806 == -1)
    return -1;
  int _ret5809;
  _ret5809 = guestfs_umount_all (g);
  if (_ret5809 == -1)
    return -1;
  int _ret5811;
  _ret5811 = guestfs_lvm_remove_all (g);
  if (_ret5811 == -1)
    return -1;
  const char *_arg5814 = "/dev/sdb1";
  const char *_arg5815 = "/";
  int _ret5813;
  _ret5813 = guestfs_mount (g, _arg5814, _arg5815);
  if (_ret5813 == -1)
    return -1;

  /* TestResult for command_lines (5) */
  const char *_arg5817 = "/command_lines6";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg5817);
  if (ret3 == -1)
    return -1;
  const char *_arg5820 = "/command_lines6/test-command";
  int ret2;
  ret2 = guestfs_upload (g, "test-command", _arg5820);
  if (ret2 == -1)
    return -1;
  const char *_arg5823 = "/command_lines6/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg5823);
  if (ret1 == -1)
    return -1;
  const char *_arg5825_0 = "/command_lines6/test-command";
  const char *_arg5825_1 = "6";
  const char *const _arg5825[] = {
    _arg5825_0,
    _arg5825_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg5825);
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
test_command_lines_6 (void)
{
  if (test_command_lines_6_skip ()) {
    skipped ("test_command_lines_6", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_lines_6 */
  const char *_arg5828 = "/dev/sda";
  int _ret5827;
  _ret5827 = guestfs_blockdev_setrw (g, _arg5828);
  if (_ret5827 == -1)
    return -1;
  int _ret5830;
  _ret5830 = guestfs_umount_all (g);
  if (_ret5830 == -1)
    return -1;
  int _ret5832;
  _ret5832 = guestfs_lvm_remove_all (g);
  if (_ret5832 == -1)
    return -1;
  const char *_arg5835 = "/dev/sdb1";
  const char *_arg5836 = "/";
  int _ret5834;
  _ret5834 = guestfs_mount (g, _arg5835, _arg5836);
  if (_ret5834 == -1)
    return -1;

  /* TestResult for command_lines (6) */
  const char *_arg5838 = "/command_lines7";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg5838);
  if (ret3 == -1)
    return -1;
  const char *_arg5841 = "/command_lines7/test-command";
  int ret2;
  ret2 = guestfs_upload (g, "test-command", _arg5841);
  if (ret2 == -1)
    return -1;
  const char *_arg5844 = "/command_lines7/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg5844);
  if (ret1 == -1)
    return -1;
  const char *_arg5846_0 = "/command_lines7/test-command";
  const char *_arg5846_1 = "7";
  const char *const _arg5846[] = {
    _arg5846_0,
    _arg5846_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg5846);
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
test_command_lines_7 (void)
{
  if (test_command_lines_7_skip ()) {
    skipped ("test_command_lines_7", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_lines_7 */
  const char *_arg5849 = "/dev/sda";
  int _ret5848;
  _ret5848 = guestfs_blockdev_setrw (g, _arg5849);
  if (_ret5848 == -1)
    return -1;
  int _ret5851;
  _ret5851 = guestfs_umount_all (g);
  if (_ret5851 == -1)
    return -1;
  int _ret5853;
  _ret5853 = guestfs_lvm_remove_all (g);
  if (_ret5853 == -1)
    return -1;
  const char *_arg5856 = "/dev/sdb1";
  const char *_arg5857 = "/";
  int _ret5855;
  _ret5855 = guestfs_mount (g, _arg5856, _arg5857);
  if (_ret5855 == -1)
    return -1;

  /* TestResult for command_lines (7) */
  const char *_arg5859 = "/command_lines8";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg5859);
  if (ret3 == -1)
    return -1;
  const char *_arg5862 = "/command_lines8/test-command";
  int ret2;
  ret2 = guestfs_upload (g, "test-command", _arg5862);
  if (ret2 == -1)
    return -1;
  const char *_arg5865 = "/command_lines8/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg5865);
  if (ret1 == -1)
    return -1;
  const char *_arg5867_0 = "/command_lines8/test-command";
  const char *_arg5867_1 = "8";
  const char *const _arg5867[] = {
    _arg5867_0,
    _arg5867_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg5867);
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
test_command_lines_8 (void)
{
  if (test_command_lines_8_skip ()) {
    skipped ("test_command_lines_8", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_lines_8 */
  const char *_arg5870 = "/dev/sda";
  int _ret5869;
  _ret5869 = guestfs_blockdev_setrw (g, _arg5870);
  if (_ret5869 == -1)
    return -1;
  int _ret5872;
  _ret5872 = guestfs_umount_all (g);
  if (_ret5872 == -1)
    return -1;
  int _ret5874;
  _ret5874 = guestfs_lvm_remove_all (g);
  if (_ret5874 == -1)
    return -1;
  const char *_arg5877 = "/dev/sdb1";
  const char *_arg5878 = "/";
  int _ret5876;
  _ret5876 = guestfs_mount (g, _arg5877, _arg5878);
  if (_ret5876 == -1)
    return -1;

  /* TestResult for command_lines (8) */
  const char *_arg5880 = "/command_lines9";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg5880);
  if (ret3 == -1)
    return -1;
  const char *_arg5883 = "/command_lines9/test-command";
  int ret2;
  ret2 = guestfs_upload (g, "test-command", _arg5883);
  if (ret2 == -1)
    return -1;
  const char *_arg5886 = "/command_lines9/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg5886);
  if (ret1 == -1)
    return -1;
  const char *_arg5888_0 = "/command_lines9/test-command";
  const char *_arg5888_1 = "9";
  const char *const _arg5888[] = {
    _arg5888_0,
    _arg5888_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg5888);
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
test_command_lines_9 (void)
{
  if (test_command_lines_9_skip ()) {
    skipped ("test_command_lines_9", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_lines_9 */
  const char *_arg5891 = "/dev/sda";
  int _ret5890;
  _ret5890 = guestfs_blockdev_setrw (g, _arg5891);
  if (_ret5890 == -1)
    return -1;
  int _ret5893;
  _ret5893 = guestfs_umount_all (g);
  if (_ret5893 == -1)
    return -1;
  int _ret5895;
  _ret5895 = guestfs_lvm_remove_all (g);
  if (_ret5895 == -1)
    return -1;
  const char *_arg5898 = "/dev/sdb1";
  const char *_arg5899 = "/";
  int _ret5897;
  _ret5897 = guestfs_mount (g, _arg5898, _arg5899);
  if (_ret5897 == -1)
    return -1;

  /* TestResult for command_lines (9) */
  const char *_arg5901 = "/command_lines10";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg5901);
  if (ret3 == -1)
    return -1;
  const char *_arg5904 = "/command_lines10/test-command";
  int ret2;
  ret2 = guestfs_upload (g, "test-command", _arg5904);
  if (ret2 == -1)
    return -1;
  const char *_arg5907 = "/command_lines10/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg5907);
  if (ret1 == -1)
    return -1;
  const char *_arg5909_0 = "/command_lines10/test-command";
  const char *_arg5909_1 = "10";
  const char *const _arg5909[] = {
    _arg5909_0,
    _arg5909_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg5909);
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
test_command_lines_10 (void)
{
  if (test_command_lines_10_skip ()) {
    skipped ("test_command_lines_10", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_lines_10 */
  const char *_arg5912 = "/dev/sda";
  int _ret5911;
  _ret5911 = guestfs_blockdev_setrw (g, _arg5912);
  if (_ret5911 == -1)
    return -1;
  int _ret5914;
  _ret5914 = guestfs_umount_all (g);
  if (_ret5914 == -1)
    return -1;
  int _ret5916;
  _ret5916 = guestfs_lvm_remove_all (g);
  if (_ret5916 == -1)
    return -1;
  const char *_arg5919 = "/dev/sdb1";
  const char *_arg5920 = "/";
  int _ret5918;
  _ret5918 = guestfs_mount (g, _arg5919, _arg5920);
  if (_ret5918 == -1)
    return -1;

  /* TestResult for command_lines (10) */
  const char *_arg5922 = "/command_lines11";
  int ret3;
  ret3 = guestfs_mkdir (g, _arg5922);
  if (ret3 == -1)
    return -1;
  const char *_arg5925 = "/command_lines11/test-command";
  int ret2;
  ret2 = guestfs_upload (g, "test-command", _arg5925);
  if (ret2 == -1)
    return -1;
  const char *_arg5928 = "/command_lines11/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, _arg5928);
  if (ret1 == -1)
    return -1;
  const char *_arg5930_0 = "/command_lines11/test-command";
  const char *_arg5930_1 = "11";
  const char *const _arg5930[] = {
    _arg5930_0,
    _arg5930_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) _arg5930);
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
test_command_0 (void)
{
  if (test_command_0_skip ()) {
    skipped ("test_command_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_0 */
  const char *_arg5933 = "/dev/sda";
  int _ret5932;
  _ret5932 = guestfs_blockdev_setrw (g, _arg5933);
  if (_ret5932 == -1)
    return -1;
  int _ret5935;
  _ret5935 = guestfs_umount_all (g);
  if (_ret5935 == -1)
    return -1;
  int _ret5937;
  _ret5937 = guestfs_lvm_remove_all (g);
  if (_ret5937 == -1)
    return -1;
  const char *_arg5940 = "/dev/sdb1";
  const char *_arg5941 = "/";
  int _ret5939;
  _ret5939 = guestfs_mount (g, _arg5940, _arg5941);
  if (_ret5939 == -1)
    return -1;

  /* TestResultString for command (0) */
  const char *_arg5944 = "/command";
  int _ret5943;
  _ret5943 = guestfs_mkdir (g, _arg5944);
  if (_ret5943 == -1)
    return -1;
  const char *_arg5948 = "/command/test-command";
  int _ret5946;
  _ret5946 = guestfs_upload (g, "test-command", _arg5948);
  if (_ret5946 == -1)
    return -1;
  const char *_arg5952 = "/command/test-command";
  int _ret5950;
  _ret5950 = guestfs_chmod (g, 493, _arg5952);
  if (_ret5950 == -1)
    return -1;
  const char *_arg5954_0 = "/command/test-command";
  const char *_arg5954_1 = "1";
  const char *const _arg5954[] = {
    _arg5954_0,
    _arg5954_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg5954);
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
test_command_1 (void)
{
  if (test_command_1_skip ()) {
    skipped ("test_command_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_1 */
  const char *_arg5957 = "/dev/sda";
  int _ret5956;
  _ret5956 = guestfs_blockdev_setrw (g, _arg5957);
  if (_ret5956 == -1)
    return -1;
  int _ret5959;
  _ret5959 = guestfs_umount_all (g);
  if (_ret5959 == -1)
    return -1;
  int _ret5961;
  _ret5961 = guestfs_lvm_remove_all (g);
  if (_ret5961 == -1)
    return -1;
  const char *_arg5964 = "/dev/sdb1";
  const char *_arg5965 = "/";
  int _ret5963;
  _ret5963 = guestfs_mount (g, _arg5964, _arg5965);
  if (_ret5963 == -1)
    return -1;

  /* TestResultString for command (1) */
  const char *_arg5968 = "/command2";
  int _ret5967;
  _ret5967 = guestfs_mkdir (g, _arg5968);
  if (_ret5967 == -1)
    return -1;
  const char *_arg5972 = "/command2/test-command";
  int _ret5970;
  _ret5970 = guestfs_upload (g, "test-command", _arg5972);
  if (_ret5970 == -1)
    return -1;
  const char *_arg5976 = "/command2/test-command";
  int _ret5974;
  _ret5974 = guestfs_chmod (g, 493, _arg5976);
  if (_ret5974 == -1)
    return -1;
  const char *_arg5978_0 = "/command2/test-command";
  const char *_arg5978_1 = "2";
  const char *const _arg5978[] = {
    _arg5978_0,
    _arg5978_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg5978);
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
test_command_2 (void)
{
  if (test_command_2_skip ()) {
    skipped ("test_command_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_2 */
  const char *_arg5981 = "/dev/sda";
  int _ret5980;
  _ret5980 = guestfs_blockdev_setrw (g, _arg5981);
  if (_ret5980 == -1)
    return -1;
  int _ret5983;
  _ret5983 = guestfs_umount_all (g);
  if (_ret5983 == -1)
    return -1;
  int _ret5985;
  _ret5985 = guestfs_lvm_remove_all (g);
  if (_ret5985 == -1)
    return -1;
  const char *_arg5988 = "/dev/sdb1";
  const char *_arg5989 = "/";
  int _ret5987;
  _ret5987 = guestfs_mount (g, _arg5988, _arg5989);
  if (_ret5987 == -1)
    return -1;

  /* TestResultString for command (2) */
  const char *_arg5992 = "/command3";
  int _ret5991;
  _ret5991 = guestfs_mkdir (g, _arg5992);
  if (_ret5991 == -1)
    return -1;
  const char *_arg5996 = "/command3/test-command";
  int _ret5994;
  _ret5994 = guestfs_upload (g, "test-command", _arg5996);
  if (_ret5994 == -1)
    return -1;
  const char *_arg6000 = "/command3/test-command";
  int _ret5998;
  _ret5998 = guestfs_chmod (g, 493, _arg6000);
  if (_ret5998 == -1)
    return -1;
  const char *_arg6002_0 = "/command3/test-command";
  const char *_arg6002_1 = "3";
  const char *const _arg6002[] = {
    _arg6002_0,
    _arg6002_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg6002);
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
test_command_3 (void)
{
  if (test_command_3_skip ()) {
    skipped ("test_command_3", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_3 */
  const char *_arg6005 = "/dev/sda";
  int _ret6004;
  _ret6004 = guestfs_blockdev_setrw (g, _arg6005);
  if (_ret6004 == -1)
    return -1;
  int _ret6007;
  _ret6007 = guestfs_umount_all (g);
  if (_ret6007 == -1)
    return -1;
  int _ret6009;
  _ret6009 = guestfs_lvm_remove_all (g);
  if (_ret6009 == -1)
    return -1;
  const char *_arg6012 = "/dev/sdb1";
  const char *_arg6013 = "/";
  int _ret6011;
  _ret6011 = guestfs_mount (g, _arg6012, _arg6013);
  if (_ret6011 == -1)
    return -1;

  /* TestResultString for command (3) */
  const char *_arg6016 = "/command4";
  int _ret6015;
  _ret6015 = guestfs_mkdir (g, _arg6016);
  if (_ret6015 == -1)
    return -1;
  const char *_arg6020 = "/command4/test-command";
  int _ret6018;
  _ret6018 = guestfs_upload (g, "test-command", _arg6020);
  if (_ret6018 == -1)
    return -1;
  const char *_arg6024 = "/command4/test-command";
  int _ret6022;
  _ret6022 = guestfs_chmod (g, 493, _arg6024);
  if (_ret6022 == -1)
    return -1;
  const char *_arg6026_0 = "/command4/test-command";
  const char *_arg6026_1 = "4";
  const char *const _arg6026[] = {
    _arg6026_0,
    _arg6026_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg6026);
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
test_command_4 (void)
{
  if (test_command_4_skip ()) {
    skipped ("test_command_4", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_4 */
  const char *_arg6029 = "/dev/sda";
  int _ret6028;
  _ret6028 = guestfs_blockdev_setrw (g, _arg6029);
  if (_ret6028 == -1)
    return -1;
  int _ret6031;
  _ret6031 = guestfs_umount_all (g);
  if (_ret6031 == -1)
    return -1;
  int _ret6033;
  _ret6033 = guestfs_lvm_remove_all (g);
  if (_ret6033 == -1)
    return -1;
  const char *_arg6036 = "/dev/sdb1";
  const char *_arg6037 = "/";
  int _ret6035;
  _ret6035 = guestfs_mount (g, _arg6036, _arg6037);
  if (_ret6035 == -1)
    return -1;

  /* TestResultString for command (4) */
  const char *_arg6040 = "/command5";
  int _ret6039;
  _ret6039 = guestfs_mkdir (g, _arg6040);
  if (_ret6039 == -1)
    return -1;
  const char *_arg6044 = "/command5/test-command";
  int _ret6042;
  _ret6042 = guestfs_upload (g, "test-command", _arg6044);
  if (_ret6042 == -1)
    return -1;
  const char *_arg6048 = "/command5/test-command";
  int _ret6046;
  _ret6046 = guestfs_chmod (g, 493, _arg6048);
  if (_ret6046 == -1)
    return -1;
  const char *_arg6050_0 = "/command5/test-command";
  const char *_arg6050_1 = "5";
  const char *const _arg6050[] = {
    _arg6050_0,
    _arg6050_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg6050);
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
test_command_5 (void)
{
  if (test_command_5_skip ()) {
    skipped ("test_command_5", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_5 */
  const char *_arg6053 = "/dev/sda";
  int _ret6052;
  _ret6052 = guestfs_blockdev_setrw (g, _arg6053);
  if (_ret6052 == -1)
    return -1;
  int _ret6055;
  _ret6055 = guestfs_umount_all (g);
  if (_ret6055 == -1)
    return -1;
  int _ret6057;
  _ret6057 = guestfs_lvm_remove_all (g);
  if (_ret6057 == -1)
    return -1;
  const char *_arg6060 = "/dev/sdb1";
  const char *_arg6061 = "/";
  int _ret6059;
  _ret6059 = guestfs_mount (g, _arg6060, _arg6061);
  if (_ret6059 == -1)
    return -1;

  /* TestResultString for command (5) */
  const char *_arg6064 = "/command6";
  int _ret6063;
  _ret6063 = guestfs_mkdir (g, _arg6064);
  if (_ret6063 == -1)
    return -1;
  const char *_arg6068 = "/command6/test-command";
  int _ret6066;
  _ret6066 = guestfs_upload (g, "test-command", _arg6068);
  if (_ret6066 == -1)
    return -1;
  const char *_arg6072 = "/command6/test-command";
  int _ret6070;
  _ret6070 = guestfs_chmod (g, 493, _arg6072);
  if (_ret6070 == -1)
    return -1;
  const char *_arg6074_0 = "/command6/test-command";
  const char *_arg6074_1 = "6";
  const char *const _arg6074[] = {
    _arg6074_0,
    _arg6074_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg6074);
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
test_command_6 (void)
{
  if (test_command_6_skip ()) {
    skipped ("test_command_6", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_6 */
  const char *_arg6077 = "/dev/sda";
  int _ret6076;
  _ret6076 = guestfs_blockdev_setrw (g, _arg6077);
  if (_ret6076 == -1)
    return -1;
  int _ret6079;
  _ret6079 = guestfs_umount_all (g);
  if (_ret6079 == -1)
    return -1;
  int _ret6081;
  _ret6081 = guestfs_lvm_remove_all (g);
  if (_ret6081 == -1)
    return -1;
  const char *_arg6084 = "/dev/sdb1";
  const char *_arg6085 = "/";
  int _ret6083;
  _ret6083 = guestfs_mount (g, _arg6084, _arg6085);
  if (_ret6083 == -1)
    return -1;

  /* TestResultString for command (6) */
  const char *_arg6088 = "/command7";
  int _ret6087;
  _ret6087 = guestfs_mkdir (g, _arg6088);
  if (_ret6087 == -1)
    return -1;
  const char *_arg6092 = "/command7/test-command";
  int _ret6090;
  _ret6090 = guestfs_upload (g, "test-command", _arg6092);
  if (_ret6090 == -1)
    return -1;
  const char *_arg6096 = "/command7/test-command";
  int _ret6094;
  _ret6094 = guestfs_chmod (g, 493, _arg6096);
  if (_ret6094 == -1)
    return -1;
  const char *_arg6098_0 = "/command7/test-command";
  const char *_arg6098_1 = "7";
  const char *const _arg6098[] = {
    _arg6098_0,
    _arg6098_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg6098);
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
test_command_7 (void)
{
  if (test_command_7_skip ()) {
    skipped ("test_command_7", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_7 */
  const char *_arg6101 = "/dev/sda";
  int _ret6100;
  _ret6100 = guestfs_blockdev_setrw (g, _arg6101);
  if (_ret6100 == -1)
    return -1;
  int _ret6103;
  _ret6103 = guestfs_umount_all (g);
  if (_ret6103 == -1)
    return -1;
  int _ret6105;
  _ret6105 = guestfs_lvm_remove_all (g);
  if (_ret6105 == -1)
    return -1;
  const char *_arg6108 = "/dev/sdb1";
  const char *_arg6109 = "/";
  int _ret6107;
  _ret6107 = guestfs_mount (g, _arg6108, _arg6109);
  if (_ret6107 == -1)
    return -1;

  /* TestResultString for command (7) */
  const char *_arg6112 = "/command8";
  int _ret6111;
  _ret6111 = guestfs_mkdir (g, _arg6112);
  if (_ret6111 == -1)
    return -1;
  const char *_arg6116 = "/command8/test-command";
  int _ret6114;
  _ret6114 = guestfs_upload (g, "test-command", _arg6116);
  if (_ret6114 == -1)
    return -1;
  const char *_arg6120 = "/command8/test-command";
  int _ret6118;
  _ret6118 = guestfs_chmod (g, 493, _arg6120);
  if (_ret6118 == -1)
    return -1;
  const char *_arg6122_0 = "/command8/test-command";
  const char *_arg6122_1 = "8";
  const char *const _arg6122[] = {
    _arg6122_0,
    _arg6122_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg6122);
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
test_command_8 (void)
{
  if (test_command_8_skip ()) {
    skipped ("test_command_8", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_8 */
  const char *_arg6125 = "/dev/sda";
  int _ret6124;
  _ret6124 = guestfs_blockdev_setrw (g, _arg6125);
  if (_ret6124 == -1)
    return -1;
  int _ret6127;
  _ret6127 = guestfs_umount_all (g);
  if (_ret6127 == -1)
    return -1;
  int _ret6129;
  _ret6129 = guestfs_lvm_remove_all (g);
  if (_ret6129 == -1)
    return -1;
  const char *_arg6132 = "/dev/sdb1";
  const char *_arg6133 = "/";
  int _ret6131;
  _ret6131 = guestfs_mount (g, _arg6132, _arg6133);
  if (_ret6131 == -1)
    return -1;

  /* TestResultString for command (8) */
  const char *_arg6136 = "/command9";
  int _ret6135;
  _ret6135 = guestfs_mkdir (g, _arg6136);
  if (_ret6135 == -1)
    return -1;
  const char *_arg6140 = "/command9/test-command";
  int _ret6138;
  _ret6138 = guestfs_upload (g, "test-command", _arg6140);
  if (_ret6138 == -1)
    return -1;
  const char *_arg6144 = "/command9/test-command";
  int _ret6142;
  _ret6142 = guestfs_chmod (g, 493, _arg6144);
  if (_ret6142 == -1)
    return -1;
  const char *_arg6146_0 = "/command9/test-command";
  const char *_arg6146_1 = "9";
  const char *const _arg6146[] = {
    _arg6146_0,
    _arg6146_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg6146);
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
test_command_9 (void)
{
  if (test_command_9_skip ()) {
    skipped ("test_command_9", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_9 */
  const char *_arg6149 = "/dev/sda";
  int _ret6148;
  _ret6148 = guestfs_blockdev_setrw (g, _arg6149);
  if (_ret6148 == -1)
    return -1;
  int _ret6151;
  _ret6151 = guestfs_umount_all (g);
  if (_ret6151 == -1)
    return -1;
  int _ret6153;
  _ret6153 = guestfs_lvm_remove_all (g);
  if (_ret6153 == -1)
    return -1;
  const char *_arg6156 = "/dev/sdb1";
  const char *_arg6157 = "/";
  int _ret6155;
  _ret6155 = guestfs_mount (g, _arg6156, _arg6157);
  if (_ret6155 == -1)
    return -1;

  /* TestResultString for command (9) */
  const char *_arg6160 = "/command10";
  int _ret6159;
  _ret6159 = guestfs_mkdir (g, _arg6160);
  if (_ret6159 == -1)
    return -1;
  const char *_arg6164 = "/command10/test-command";
  int _ret6162;
  _ret6162 = guestfs_upload (g, "test-command", _arg6164);
  if (_ret6162 == -1)
    return -1;
  const char *_arg6168 = "/command10/test-command";
  int _ret6166;
  _ret6166 = guestfs_chmod (g, 493, _arg6168);
  if (_ret6166 == -1)
    return -1;
  const char *_arg6170_0 = "/command10/test-command";
  const char *_arg6170_1 = "10";
  const char *const _arg6170[] = {
    _arg6170_0,
    _arg6170_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg6170);
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
test_command_10 (void)
{
  if (test_command_10_skip ()) {
    skipped ("test_command_10", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_10 */
  const char *_arg6173 = "/dev/sda";
  int _ret6172;
  _ret6172 = guestfs_blockdev_setrw (g, _arg6173);
  if (_ret6172 == -1)
    return -1;
  int _ret6175;
  _ret6175 = guestfs_umount_all (g);
  if (_ret6175 == -1)
    return -1;
  int _ret6177;
  _ret6177 = guestfs_lvm_remove_all (g);
  if (_ret6177 == -1)
    return -1;
  const char *_arg6180 = "/dev/sdb1";
  const char *_arg6181 = "/";
  int _ret6179;
  _ret6179 = guestfs_mount (g, _arg6180, _arg6181);
  if (_ret6179 == -1)
    return -1;

  /* TestResultString for command (10) */
  const char *_arg6184 = "/command11";
  int _ret6183;
  _ret6183 = guestfs_mkdir (g, _arg6184);
  if (_ret6183 == -1)
    return -1;
  const char *_arg6188 = "/command11/test-command";
  int _ret6186;
  _ret6186 = guestfs_upload (g, "test-command", _arg6188);
  if (_ret6186 == -1)
    return -1;
  const char *_arg6192 = "/command11/test-command";
  int _ret6190;
  _ret6190 = guestfs_chmod (g, 493, _arg6192);
  if (_ret6190 == -1)
    return -1;
  const char *_arg6194_0 = "/command11/test-command";
  const char *_arg6194_1 = "11";
  const char *const _arg6194[] = {
    _arg6194_0,
    _arg6194_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg6194);
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
test_command_11 (void)
{
  if (test_command_11_skip ()) {
    skipped ("test_command_11", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_11 */
  const char *_arg6197 = "/dev/sda";
  int _ret6196;
  _ret6196 = guestfs_blockdev_setrw (g, _arg6197);
  if (_ret6196 == -1)
    return -1;
  int _ret6199;
  _ret6199 = guestfs_umount_all (g);
  if (_ret6199 == -1)
    return -1;
  int _ret6201;
  _ret6201 = guestfs_lvm_remove_all (g);
  if (_ret6201 == -1)
    return -1;
  const char *_arg6204 = "/dev/sdb1";
  const char *_arg6205 = "/";
  int _ret6203;
  _ret6203 = guestfs_mount (g, _arg6204, _arg6205);
  if (_ret6203 == -1)
    return -1;

  /* TestLastFail for command (11) */
  const char *_arg6208 = "/command12";
  int _ret6207;
  _ret6207 = guestfs_mkdir (g, _arg6208);
  if (_ret6207 == -1)
    return -1;
  const char *_arg6212 = "/command12/test-command";
  int _ret6210;
  _ret6210 = guestfs_upload (g, "test-command", _arg6212);
  if (_ret6210 == -1)
    return -1;
  const char *_arg6216 = "/command12/test-command";
  int _ret6214;
  _ret6214 = guestfs_chmod (g, 493, _arg6216);
  if (_ret6214 == -1)
    return -1;
  const char *_arg6219_0 = "/command12/test-command";
  const char *const _arg6219[] = {
    _arg6219_0,
    NULL
  };
  CLEANUP_FREE char *_ret6218;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret6218 = guestfs_command (g, (char **) _arg6219);
  guestfs_pop_error_handler (g);
  if (_ret6218 != NULL)
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
test_command_12 (void)
{
  if (test_command_12_skip ()) {
    skipped ("test_command_12", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_command_12 */
  const char *_arg6222 = "/dev/sda";
  int _ret6221;
  _ret6221 = guestfs_blockdev_setrw (g, _arg6222);
  if (_ret6221 == -1)
    return -1;
  int _ret6224;
  _ret6224 = guestfs_umount_all (g);
  if (_ret6224 == -1)
    return -1;
  int _ret6226;
  _ret6226 = guestfs_lvm_remove_all (g);
  if (_ret6226 == -1)
    return -1;
  const char *_arg6229 = "/dev/sdb1";
  const char *_arg6230 = "/";
  int _ret6228;
  _ret6228 = guestfs_mount (g, _arg6229, _arg6230);
  if (_ret6228 == -1)
    return -1;

  /* TestResultString for command (12) */
  const char *_arg6233 = "/pwd";
  int _ret6232;
  _ret6232 = guestfs_mkdir (g, _arg6233);
  if (_ret6232 == -1)
    return -1;
  const char *_arg6237 = "/pwd/test-pwd";
  int _ret6235;
  _ret6235 = guestfs_upload (g, "test-pwd", _arg6237);
  if (_ret6235 == -1)
    return -1;
  const char *_arg6241 = "/pwd/test-pwd";
  int _ret6239;
  _ret6239 = guestfs_chmod (g, 493, _arg6241);
  if (_ret6239 == -1)
    return -1;
  const char *_arg6243_0 = "/pwd/test-pwd";
  const char *const _arg6243[] = {
    _arg6243_0,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) _arg6243);
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
test_file_0 (void)
{
  if (test_file_0_skip ()) {
    skipped ("test_file_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_0 */
  const char *_arg6246 = "/dev/sda";
  int _ret6245;
  _ret6245 = guestfs_blockdev_setrw (g, _arg6246);
  if (_ret6245 == -1)
    return -1;
  int _ret6248;
  _ret6248 = guestfs_umount_all (g);
  if (_ret6248 == -1)
    return -1;
  int _ret6250;
  _ret6250 = guestfs_lvm_remove_all (g);
  if (_ret6250 == -1)
    return -1;
  const char *_arg6253 = "/dev/sdd";
  const char *_arg6254 = "/";
  int _ret6252;
  _ret6252 = guestfs_mount_ro (g, _arg6253, _arg6254);
  if (_ret6252 == -1)
    return -1;

  /* TestResultString for file (0) */
  const char *_arg6256 = "/empty";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg6256);
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
test_file_1 (void)
{
  if (test_file_1_skip ()) {
    skipped ("test_file_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_1 */
  const char *_arg6259 = "/dev/sda";
  int _ret6258;
  _ret6258 = guestfs_blockdev_setrw (g, _arg6259);
  if (_ret6258 == -1)
    return -1;
  int _ret6261;
  _ret6261 = guestfs_umount_all (g);
  if (_ret6261 == -1)
    return -1;
  int _ret6263;
  _ret6263 = guestfs_lvm_remove_all (g);
  if (_ret6263 == -1)
    return -1;
  const char *_arg6266 = "/dev/sdd";
  const char *_arg6267 = "/";
  int _ret6265;
  _ret6265 = guestfs_mount_ro (g, _arg6266, _arg6267);
  if (_ret6265 == -1)
    return -1;

  /* TestResultString for file (1) */
  const char *_arg6269 = "/known-1";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg6269);
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
test_file_2 (void)
{
  if (test_file_2_skip ()) {
    skipped ("test_file_2", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_2 */
  const char *_arg6272 = "/dev/sda";
  int _ret6271;
  _ret6271 = guestfs_blockdev_setrw (g, _arg6272);
  if (_ret6271 == -1)
    return -1;
  int _ret6274;
  _ret6274 = guestfs_umount_all (g);
  if (_ret6274 == -1)
    return -1;
  int _ret6276;
  _ret6276 = guestfs_lvm_remove_all (g);
  if (_ret6276 == -1)
    return -1;
  const char *_arg6279 = "/dev/sdd";
  const char *_arg6280 = "/";
  int _ret6278;
  _ret6278 = guestfs_mount_ro (g, _arg6279, _arg6280);
  if (_ret6278 == -1)
    return -1;

  /* TestLastFail for file (2) */
  const char *_arg6283 = "/notexists";
  CLEANUP_FREE char *_ret6282;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret6282 = guestfs_file (g, _arg6283);
  guestfs_pop_error_handler (g);
  if (_ret6282 != NULL)
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
test_file_3 (void)
{
  if (test_file_3_skip ()) {
    skipped ("test_file_3", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_3 */
  const char *_arg6286 = "/dev/sda";
  int _ret6285;
  _ret6285 = guestfs_blockdev_setrw (g, _arg6286);
  if (_ret6285 == -1)
    return -1;
  int _ret6288;
  _ret6288 = guestfs_umount_all (g);
  if (_ret6288 == -1)
    return -1;
  int _ret6290;
  _ret6290 = guestfs_lvm_remove_all (g);
  if (_ret6290 == -1)
    return -1;
  const char *_arg6293 = "/dev/sdd";
  const char *_arg6294 = "/";
  int _ret6292;
  _ret6292 = guestfs_mount_ro (g, _arg6293, _arg6294);
  if (_ret6292 == -1)
    return -1;

  /* TestResultString for file (3) */
  const char *_arg6296 = "/abssymlink";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg6296);
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
test_file_4 (void)
{
  if (test_file_4_skip ()) {
    skipped ("test_file_4", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_4 */
  const char *_arg6299 = "/dev/sda";
  int _ret6298;
  _ret6298 = guestfs_blockdev_setrw (g, _arg6299);
  if (_ret6298 == -1)
    return -1;
  int _ret6301;
  _ret6301 = guestfs_umount_all (g);
  if (_ret6301 == -1)
    return -1;
  int _ret6303;
  _ret6303 = guestfs_lvm_remove_all (g);
  if (_ret6303 == -1)
    return -1;
  const char *_arg6306 = "/dev/sdd";
  const char *_arg6307 = "/";
  int _ret6305;
  _ret6305 = guestfs_mount_ro (g, _arg6306, _arg6307);
  if (_ret6305 == -1)
    return -1;

  /* TestResultString for file (4) */
  const char *_arg6309 = "/directory";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, _arg6309);
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
test_umount_all_0 (void)
{
  if (test_umount_all_0_skip ()) {
    skipped ("test_umount_all_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_umount_all_0 */
  const char *_arg6312 = "/dev/sda";
  int _ret6311;
  _ret6311 = guestfs_blockdev_setrw (g, _arg6312);
  if (_ret6311 == -1)
    return -1;
  int _ret6314;
  _ret6314 = guestfs_umount_all (g);
  if (_ret6314 == -1)
    return -1;
  int _ret6316;
  _ret6316 = guestfs_lvm_remove_all (g);
  if (_ret6316 == -1)
    return -1;
  const char *_arg6319 = "/dev/sdb1";
  const char *_arg6320 = "/";
  int _ret6318;
  _ret6318 = guestfs_mount (g, _arg6319, _arg6320);
  if (_ret6318 == -1)
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
test_umount_all_1 (void)
{
  if (test_umount_all_1_skip ()) {
    skipped ("test_umount_all_1", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_umount_all_1 */
  const char *_arg6325 = "/dev/sda";
  int _ret6324;
  _ret6324 = guestfs_blockdev_setrw (g, _arg6325);
  if (_ret6324 == -1)
    return -1;
  int _ret6327;
  _ret6327 = guestfs_umount_all (g);
  if (_ret6327 == -1)
    return -1;
  int _ret6329;
  _ret6329 = guestfs_lvm_remove_all (g);
  if (_ret6329 == -1)
    return -1;

  /* TestResult for umount_all (1) */
  const char *_arg6331 = "/dev/sda";
  const char *_arg6332 = "mbr";
  int ret14;
  ret14 = guestfs_part_init (g, _arg6331, _arg6332);
  if (ret14 == -1)
    return -1;
  const char *_arg6334 = "/dev/sda";
  const char *_arg6335 = "p";
  int ret13;
  ret13 = guestfs_part_add (g, _arg6334, _arg6335, 64, 204799);
  if (ret13 == -1)
    return -1;
  const char *_arg6339 = "/dev/sda";
  const char *_arg6340 = "p";
  int ret12;
  ret12 = guestfs_part_add (g, _arg6339, _arg6340, 204800, 409599);
  if (ret12 == -1)
    return -1;
  const char *_arg6344 = "/dev/sda";
  const char *_arg6345 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, _arg6344, _arg6345, 409600, -64);
  if (ret11 == -1)
    return -1;
  const char *_arg6349 = "ext2";
  const char *_arg6350 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs6351;
  _optargs6351.bitmask = UINT64_C(0x0);
  int ret10;
  ret10 = guestfs_mkfs_opts_argv (g, _arg6349, _arg6350, &_optargs6351);
  if (ret10 == -1)
    return -1;
  const char *_arg6352 = "ext2";
  const char *_arg6353 = "/dev/sda2";
  struct guestfs_mkfs_opts_argv _optargs6354;
  _optargs6354.bitmask = UINT64_C(0x0);
  int ret9;
  ret9 = guestfs_mkfs_opts_argv (g, _arg6352, _arg6353, &_optargs6354);
  if (ret9 == -1)
    return -1;
  const char *_arg6355 = "ext2";
  const char *_arg6356 = "/dev/sda3";
  struct guestfs_mkfs_opts_argv _optargs6357;
  _optargs6357.bitmask = UINT64_C(0x0);
  int ret8;
  ret8 = guestfs_mkfs_opts_argv (g, _arg6355, _arg6356, &_optargs6357);
  if (ret8 == -1)
    return -1;
  const char *_arg6358 = "/dev/sda1";
  const char *_arg6359 = "/";
  int ret7;
  ret7 = guestfs_mount (g, _arg6358, _arg6359);
  if (ret7 == -1)
    return -1;
  const char *_arg6361 = "/mp1";
  int ret6;
  ret6 = guestfs_mkdir (g, _arg6361);
  if (ret6 == -1)
    return -1;
  const char *_arg6363 = "/dev/sda2";
  const char *_arg6364 = "/mp1";
  int ret5;
  ret5 = guestfs_mount (g, _arg6363, _arg6364);
  if (ret5 == -1)
    return -1;
  const char *_arg6366 = "/mp1/mp2";
  int ret4;
  ret4 = guestfs_mkdir (g, _arg6366);
  if (ret4 == -1)
    return -1;
  const char *_arg6368 = "/dev/sda3";
  const char *_arg6369 = "/mp1/mp2";
  int ret3;
  ret3 = guestfs_mount (g, _arg6368, _arg6369);
  if (ret3 == -1)
    return -1;
  const char *_arg6371 = "/mp1/mp2/mp3";
  int ret2;
  ret2 = guestfs_mkdir (g, _arg6371);
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
test_mounts_0 (void)
{
  if (test_mounts_0_skip ()) {
    skipped ("test_mounts_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mounts_0 */
  const char *_arg6376 = "/dev/sda";
  int _ret6375;
  _ret6375 = guestfs_blockdev_setrw (g, _arg6376);
  if (_ret6375 == -1)
    return -1;
  int _ret6378;
  _ret6378 = guestfs_umount_all (g);
  if (_ret6378 == -1)
    return -1;
  int _ret6380;
  _ret6380 = guestfs_lvm_remove_all (g);
  if (_ret6380 == -1)
    return -1;
  const char *_arg6383 = "/dev/sdb1";
  const char *_arg6384 = "/";
  int _ret6382;
  _ret6382 = guestfs_mount (g, _arg6383, _arg6384);
  if (_ret6382 == -1)
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
test_umount_0 (void)
{
  if (test_umount_0_skip ()) {
    skipped ("test_umount_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_umount_0 */
  const char *_arg6388 = "/dev/sda";
  int _ret6387;
  _ret6387 = guestfs_blockdev_setrw (g, _arg6388);
  if (_ret6387 == -1)
    return -1;
  int _ret6390;
  _ret6390 = guestfs_umount_all (g);
  if (_ret6390 == -1)
    return -1;
  int _ret6392;
  _ret6392 = guestfs_lvm_remove_all (g);
  if (_ret6392 == -1)
    return -1;

  /* TestResult for umount (0) */
  const char *_arg6394 = "/dev/sda";
  const char *_arg6395 = "mbr";
  int ret3;
  ret3 = guestfs_part_disk (g, _arg6394, _arg6395);
  if (ret3 == -1)
    return -1;
  const char *_arg6397 = "ext2";
  const char *_arg6398 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs6399;
  _optargs6399.bitmask = UINT64_C(0x0);
  int ret2;
  ret2 = guestfs_mkfs_opts_argv (g, _arg6397, _arg6398, &_optargs6399);
  if (ret2 == -1)
    return -1;
  const char *_arg6400 = "/dev/sda1";
  const char *_arg6401 = "/";
  int ret1;
  ret1 = guestfs_mount (g, _arg6400, _arg6401);
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
test_umount_1 (void)
{
  if (test_umount_1_skip ()) {
    skipped ("test_umount_1", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_umount_1 */
  const char *_arg6405 = "/dev/sda";
  int _ret6404;
  _ret6404 = guestfs_blockdev_setrw (g, _arg6405);
  if (_ret6404 == -1)
    return -1;
  int _ret6407;
  _ret6407 = guestfs_umount_all (g);
  if (_ret6407 == -1)
    return -1;
  int _ret6409;
  _ret6409 = guestfs_lvm_remove_all (g);
  if (_ret6409 == -1)
    return -1;

  /* TestResult for umount (1) */
  const char *_arg6411 = "/dev/sda";
  const char *_arg6412 = "mbr";
  int ret4;
  ret4 = guestfs_part_disk (g, _arg6411, _arg6412);
  if (ret4 == -1)
    return -1;
  const char *_arg6414 = "ext2";
  const char *_arg6415 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs6416;
  _optargs6416.bitmask = UINT64_C(0x0);
  int ret3;
  ret3 = guestfs_mkfs_opts_argv (g, _arg6414, _arg6415, &_optargs6416);
  if (ret3 == -1)
    return -1;
  const char *_arg6417 = "/dev/sda1";
  const char *_arg6418 = "/";
  int ret2;
  ret2 = guestfs_mount (g, _arg6417, _arg6418);
  if (ret2 == -1)
    return -1;
  const char *_arg6420 = "/";
  struct guestfs_umount_opts_argv _optargs6421;
  _optargs6421.force = 0;
  _optargs6421.lazyunmount = 0;
  _optargs6421.bitmask = UINT64_C(0x3);
  int ret1;
  ret1 = guestfs_umount_opts_argv (g, _arg6420, &_optargs6421);
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
test_write_file_0 (void)
{
  if (test_write_file_0_skip ()) {
    skipped ("test_write_file_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_write_file_0 */
  const char *_arg6424 = "/dev/sda";
  int _ret6423;
  _ret6423 = guestfs_blockdev_setrw (g, _arg6424);
  if (_ret6423 == -1)
    return -1;
  int _ret6426;
  _ret6426 = guestfs_umount_all (g);
  if (_ret6426 == -1)
    return -1;
  int _ret6428;
  _ret6428 = guestfs_lvm_remove_all (g);
  if (_ret6428 == -1)
    return -1;
  const char *_arg6431 = "/dev/sdb1";
  const char *_arg6432 = "/";
  int _ret6430;
  _ret6430 = guestfs_mount (g, _arg6431, _arg6432);
  if (_ret6430 == -1)
    return -1;

  /* TestLastFail for write_file (0) */
  const char *_arg6435 = "/write_file";
  const char *_arg6436 = "abc";
  int _ret6434;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret6434 = guestfs_write_file (g, _arg6435, _arg6436, 10000);
  guestfs_pop_error_handler (g);
  if (_ret6434 != -1)
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
test_lvcreate_0 (void)
{
  if (test_lvcreate_0_skip ()) {
    skipped ("test_lvcreate_0", "environment variable set");
    return 0;
  }

  const char *_features6439[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features6439)) {
    skipped ("test_lvcreate_0", "group %s not available in daemon",
             _features6439[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_lvcreate_0 */
  const char *_arg6441 = "/dev/sda";
  int _ret6440;
  _ret6440 = guestfs_blockdev_setrw (g, _arg6441);
  if (_ret6440 == -1)
    return -1;
  int _ret6443;
  _ret6443 = guestfs_umount_all (g);
  if (_ret6443 == -1)
    return -1;
  int _ret6445;
  _ret6445 = guestfs_lvm_remove_all (g);
  if (_ret6445 == -1)
    return -1;

  /* TestResult for lvcreate (0) */
  const char *_arg6447 = "/dev/sda";
  const char *_arg6448 = "mbr";
  int ret14;
  ret14 = guestfs_part_init (g, _arg6447, _arg6448);
  if (ret14 == -1)
    return -1;
  const char *_arg6450 = "/dev/sda";
  const char *_arg6451 = "p";
  int ret13;
  ret13 = guestfs_part_add (g, _arg6450, _arg6451, 64, 204799);
  if (ret13 == -1)
    return -1;
  const char *_arg6455 = "/dev/sda";
  const char *_arg6456 = "p";
  int ret12;
  ret12 = guestfs_part_add (g, _arg6455, _arg6456, 204800, 409599);
  if (ret12 == -1)
    return -1;
  const char *_arg6460 = "/dev/sda";
  const char *_arg6461 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, _arg6460, _arg6461, 409600, -64);
  if (ret11 == -1)
    return -1;
  const char *_arg6465 = "/dev/sda1";
  int ret10;
  ret10 = guestfs_pvcreate (g, _arg6465);
  if (ret10 == -1)
    return -1;
  const char *_arg6467 = "/dev/sda2";
  int ret9;
  ret9 = guestfs_pvcreate (g, _arg6467);
  if (ret9 == -1)
    return -1;
  const char *_arg6469 = "/dev/sda3";
  int ret8;
  ret8 = guestfs_pvcreate (g, _arg6469);
  if (ret8 == -1)
    return -1;
  const char *_arg6471 = "VG1";
  const char *_arg6472_0 = "/dev/sda1";
  const char *_arg6472_1 = "/dev/sda2";
  const char *const _arg6472[] = {
    _arg6472_0,
    _arg6472_1,
    NULL
  };
  int ret7;
  ret7 = guestfs_vgcreate (g, _arg6471, (char **) _arg6472);
  if (ret7 == -1)
    return -1;
  const char *_arg6474 = "VG2";
  const char *_arg6475_0 = "/dev/sda3";
  const char *const _arg6475[] = {
    _arg6475_0,
    NULL
  };
  int ret6;
  ret6 = guestfs_vgcreate (g, _arg6474, (char **) _arg6475);
  if (ret6 == -1)
    return -1;
  const char *_arg6477 = "LV1";
  const char *_arg6478 = "VG1";
  int ret5;
  ret5 = guestfs_lvcreate (g, _arg6477, _arg6478, 50);
  if (ret5 == -1)
    return -1;
  const char *_arg6481 = "LV2";
  const char *_arg6482 = "VG1";
  int ret4;
  ret4 = guestfs_lvcreate (g, _arg6481, _arg6482, 50);
  if (ret4 == -1)
    return -1;
  const char *_arg6485 = "LV3";
  const char *_arg6486 = "VG2";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg6485, _arg6486, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg6489 = "LV4";
  const char *_arg6490 = "VG2";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg6489, _arg6490, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg6493 = "LV5";
  const char *_arg6494 = "VG2";
  int ret1;
  ret1 = guestfs_lvcreate (g, _arg6493, _arg6494, 50);
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
test_vgcreate_0 (void)
{
  if (test_vgcreate_0_skip ()) {
    skipped ("test_vgcreate_0", "environment variable set");
    return 0;
  }

  const char *_features6498[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features6498)) {
    skipped ("test_vgcreate_0", "group %s not available in daemon",
             _features6498[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_vgcreate_0 */
  const char *_arg6500 = "/dev/sda";
  int _ret6499;
  _ret6499 = guestfs_blockdev_setrw (g, _arg6500);
  if (_ret6499 == -1)
    return -1;
  int _ret6502;
  _ret6502 = guestfs_umount_all (g);
  if (_ret6502 == -1)
    return -1;
  int _ret6504;
  _ret6504 = guestfs_lvm_remove_all (g);
  if (_ret6504 == -1)
    return -1;

  /* TestResult for vgcreate (0) */
  const char *_arg6506 = "/dev/sda";
  const char *_arg6507 = "mbr";
  int ret9;
  ret9 = guestfs_part_init (g, _arg6506, _arg6507);
  if (ret9 == -1)
    return -1;
  const char *_arg6509 = "/dev/sda";
  const char *_arg6510 = "p";
  int ret8;
  ret8 = guestfs_part_add (g, _arg6509, _arg6510, 64, 204799);
  if (ret8 == -1)
    return -1;
  const char *_arg6514 = "/dev/sda";
  const char *_arg6515 = "p";
  int ret7;
  ret7 = guestfs_part_add (g, _arg6514, _arg6515, 204800, 409599);
  if (ret7 == -1)
    return -1;
  const char *_arg6519 = "/dev/sda";
  const char *_arg6520 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg6519, _arg6520, 409600, -64);
  if (ret6 == -1)
    return -1;
  const char *_arg6524 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg6524);
  if (ret5 == -1)
    return -1;
  const char *_arg6526 = "/dev/sda2";
  int ret4;
  ret4 = guestfs_pvcreate (g, _arg6526);
  if (ret4 == -1)
    return -1;
  const char *_arg6528 = "/dev/sda3";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg6528);
  if (ret3 == -1)
    return -1;
  const char *_arg6530 = "VG1";
  const char *_arg6531_0 = "/dev/sda1";
  const char *_arg6531_1 = "/dev/sda2";
  const char *const _arg6531[] = {
    _arg6531_0,
    _arg6531_1,
    NULL
  };
  int ret2;
  ret2 = guestfs_vgcreate (g, _arg6530, (char **) _arg6531);
  if (ret2 == -1)
    return -1;
  const char *_arg6533 = "VG2";
  const char *_arg6534_0 = "/dev/sda3";
  const char *const _arg6534[] = {
    _arg6534_0,
    NULL
  };
  int ret1;
  ret1 = guestfs_vgcreate (g, _arg6533, (char **) _arg6534);
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
test_pvcreate_0 (void)
{
  if (test_pvcreate_0_skip ()) {
    skipped ("test_pvcreate_0", "environment variable set");
    return 0;
  }

  const char *_features6537[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features6537)) {
    skipped ("test_pvcreate_0", "group %s not available in daemon",
             _features6537[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_pvcreate_0 */
  const char *_arg6539 = "/dev/sda";
  int _ret6538;
  _ret6538 = guestfs_blockdev_setrw (g, _arg6539);
  if (_ret6538 == -1)
    return -1;
  int _ret6541;
  _ret6541 = guestfs_umount_all (g);
  if (_ret6541 == -1)
    return -1;
  int _ret6543;
  _ret6543 = guestfs_lvm_remove_all (g);
  if (_ret6543 == -1)
    return -1;

  /* TestResult for pvcreate (0) */
  const char *_arg6545 = "/dev/sda";
  const char *_arg6546 = "mbr";
  int ret7;
  ret7 = guestfs_part_init (g, _arg6545, _arg6546);
  if (ret7 == -1)
    return -1;
  const char *_arg6548 = "/dev/sda";
  const char *_arg6549 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg6548, _arg6549, 64, 204799);
  if (ret6 == -1)
    return -1;
  const char *_arg6553 = "/dev/sda";
  const char *_arg6554 = "p";
  int ret5;
  ret5 = guestfs_part_add (g, _arg6553, _arg6554, 204800, 409599);
  if (ret5 == -1)
    return -1;
  const char *_arg6558 = "/dev/sda";
  const char *_arg6559 = "p";
  int ret4;
  ret4 = guestfs_part_add (g, _arg6558, _arg6559, 409600, -64);
  if (ret4 == -1)
    return -1;
  const char *_arg6563 = "/dev/sda1";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg6563);
  if (ret3 == -1)
    return -1;
  const char *_arg6565 = "/dev/sda2";
  int ret2;
  ret2 = guestfs_pvcreate (g, _arg6565);
  if (ret2 == -1)
    return -1;
  const char *_arg6567 = "/dev/sda3";
  int ret1;
  ret1 = guestfs_pvcreate (g, _arg6567);
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
test_is_dir_0 (void)
{
  if (test_is_dir_0_skip ()) {
    skipped ("test_is_dir_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_is_dir_0 */
  const char *_arg6571 = "/dev/sda";
  int _ret6570;
  _ret6570 = guestfs_blockdev_setrw (g, _arg6571);
  if (_ret6570 == -1)
    return -1;
  int _ret6573;
  _ret6573 = guestfs_umount_all (g);
  if (_ret6573 == -1)
    return -1;
  int _ret6575;
  _ret6575 = guestfs_lvm_remove_all (g);
  if (_ret6575 == -1)
    return -1;
  const char *_arg6578 = "/dev/sdd";
  const char *_arg6579 = "/";
  int _ret6577;
  _ret6577 = guestfs_mount_ro (g, _arg6578, _arg6579);
  if (_ret6577 == -1)
    return -1;

  /* TestResultFalse for is_dir (0) */
  const char *_arg6581 = "/known-3";
  int ret;
  ret = guestfs_is_dir (g, _arg6581);
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
test_is_dir_1 (void)
{
  if (test_is_dir_1_skip ()) {
    skipped ("test_is_dir_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_is_dir_1 */
  const char *_arg6584 = "/dev/sda";
  int _ret6583;
  _ret6583 = guestfs_blockdev_setrw (g, _arg6584);
  if (_ret6583 == -1)
    return -1;
  int _ret6586;
  _ret6586 = guestfs_umount_all (g);
  if (_ret6586 == -1)
    return -1;
  int _ret6588;
  _ret6588 = guestfs_lvm_remove_all (g);
  if (_ret6588 == -1)
    return -1;
  const char *_arg6591 = "/dev/sdd";
  const char *_arg6592 = "/";
  int _ret6590;
  _ret6590 = guestfs_mount_ro (g, _arg6591, _arg6592);
  if (_ret6590 == -1)
    return -1;

  /* TestResultTrue for is_dir (1) */
  const char *_arg6594 = "/directory";
  int ret;
  ret = guestfs_is_dir (g, _arg6594);
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
test_is_file_0 (void)
{
  if (test_is_file_0_skip ()) {
    skipped ("test_is_file_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_is_file_0 */
  const char *_arg6597 = "/dev/sda";
  int _ret6596;
  _ret6596 = guestfs_blockdev_setrw (g, _arg6597);
  if (_ret6596 == -1)
    return -1;
  int _ret6599;
  _ret6599 = guestfs_umount_all (g);
  if (_ret6599 == -1)
    return -1;
  int _ret6601;
  _ret6601 = guestfs_lvm_remove_all (g);
  if (_ret6601 == -1)
    return -1;
  const char *_arg6604 = "/dev/sdd";
  const char *_arg6605 = "/";
  int _ret6603;
  _ret6603 = guestfs_mount_ro (g, _arg6604, _arg6605);
  if (_ret6603 == -1)
    return -1;

  /* TestResultTrue for is_file (0) */
  const char *_arg6607 = "/known-1";
  int ret;
  ret = guestfs_is_file (g, _arg6607);
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
test_is_file_1 (void)
{
  if (test_is_file_1_skip ()) {
    skipped ("test_is_file_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_is_file_1 */
  const char *_arg6610 = "/dev/sda";
  int _ret6609;
  _ret6609 = guestfs_blockdev_setrw (g, _arg6610);
  if (_ret6609 == -1)
    return -1;
  int _ret6612;
  _ret6612 = guestfs_umount_all (g);
  if (_ret6612 == -1)
    return -1;
  int _ret6614;
  _ret6614 = guestfs_lvm_remove_all (g);
  if (_ret6614 == -1)
    return -1;
  const char *_arg6617 = "/dev/sdd";
  const char *_arg6618 = "/";
  int _ret6616;
  _ret6616 = guestfs_mount_ro (g, _arg6617, _arg6618);
  if (_ret6616 == -1)
    return -1;

  /* TestResultFalse for is_file (1) */
  const char *_arg6620 = "/directory";
  int ret;
  ret = guestfs_is_file (g, _arg6620);
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
test_exists_0 (void)
{
  if (test_exists_0_skip ()) {
    skipped ("test_exists_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_exists_0 */
  const char *_arg6623 = "/dev/sda";
  int _ret6622;
  _ret6622 = guestfs_blockdev_setrw (g, _arg6623);
  if (_ret6622 == -1)
    return -1;
  int _ret6625;
  _ret6625 = guestfs_umount_all (g);
  if (_ret6625 == -1)
    return -1;
  int _ret6627;
  _ret6627 = guestfs_lvm_remove_all (g);
  if (_ret6627 == -1)
    return -1;
  const char *_arg6630 = "/dev/sdd";
  const char *_arg6631 = "/";
  int _ret6629;
  _ret6629 = guestfs_mount_ro (g, _arg6630, _arg6631);
  if (_ret6629 == -1)
    return -1;

  /* TestResultTrue for exists (0) */
  const char *_arg6633 = "/empty";
  int ret;
  ret = guestfs_exists (g, _arg6633);
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
test_exists_1 (void)
{
  if (test_exists_1_skip ()) {
    skipped ("test_exists_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_exists_1 */
  const char *_arg6636 = "/dev/sda";
  int _ret6635;
  _ret6635 = guestfs_blockdev_setrw (g, _arg6636);
  if (_ret6635 == -1)
    return -1;
  int _ret6638;
  _ret6638 = guestfs_umount_all (g);
  if (_ret6638 == -1)
    return -1;
  int _ret6640;
  _ret6640 = guestfs_lvm_remove_all (g);
  if (_ret6640 == -1)
    return -1;
  const char *_arg6643 = "/dev/sdd";
  const char *_arg6644 = "/";
  int _ret6642;
  _ret6642 = guestfs_mount_ro (g, _arg6643, _arg6644);
  if (_ret6642 == -1)
    return -1;

  /* TestResultTrue for exists (1) */
  const char *_arg6646 = "/directory";
  int ret;
  ret = guestfs_exists (g, _arg6646);
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
test_mkdir_p_0 (void)
{
  if (test_mkdir_p_0_skip ()) {
    skipped ("test_mkdir_p_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mkdir_p_0 */
  const char *_arg6649 = "/dev/sda";
  int _ret6648;
  _ret6648 = guestfs_blockdev_setrw (g, _arg6649);
  if (_ret6648 == -1)
    return -1;
  int _ret6651;
  _ret6651 = guestfs_umount_all (g);
  if (_ret6651 == -1)
    return -1;
  int _ret6653;
  _ret6653 = guestfs_lvm_remove_all (g);
  if (_ret6653 == -1)
    return -1;
  const char *_arg6656 = "/dev/sdb1";
  const char *_arg6657 = "/";
  int _ret6655;
  _ret6655 = guestfs_mount (g, _arg6656, _arg6657);
  if (_ret6655 == -1)
    return -1;

  /* TestResultTrue for mkdir_p (0) */
  const char *_arg6660 = "/mkdir_p/foo/bar";
  int _ret6659;
  _ret6659 = guestfs_mkdir_p (g, _arg6660);
  if (_ret6659 == -1)
    return -1;
  const char *_arg6662 = "/mkdir_p/foo/bar";
  int ret;
  ret = guestfs_is_dir (g, _arg6662);
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
test_mkdir_p_1 (void)
{
  if (test_mkdir_p_1_skip ()) {
    skipped ("test_mkdir_p_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mkdir_p_1 */
  const char *_arg6665 = "/dev/sda";
  int _ret6664;
  _ret6664 = guestfs_blockdev_setrw (g, _arg6665);
  if (_ret6664 == -1)
    return -1;
  int _ret6667;
  _ret6667 = guestfs_umount_all (g);
  if (_ret6667 == -1)
    return -1;
  int _ret6669;
  _ret6669 = guestfs_lvm_remove_all (g);
  if (_ret6669 == -1)
    return -1;
  const char *_arg6672 = "/dev/sdb1";
  const char *_arg6673 = "/";
  int _ret6671;
  _ret6671 = guestfs_mount (g, _arg6672, _arg6673);
  if (_ret6671 == -1)
    return -1;

  /* TestResultTrue for mkdir_p (1) */
  const char *_arg6676 = "/mkdir_p2/foo/bar";
  int _ret6675;
  _ret6675 = guestfs_mkdir_p (g, _arg6676);
  if (_ret6675 == -1)
    return -1;
  const char *_arg6678 = "/mkdir_p2/foo";
  int ret;
  ret = guestfs_is_dir (g, _arg6678);
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
test_mkdir_p_2 (void)
{
  if (test_mkdir_p_2_skip ()) {
    skipped ("test_mkdir_p_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mkdir_p_2 */
  const char *_arg6681 = "/dev/sda";
  int _ret6680;
  _ret6680 = guestfs_blockdev_setrw (g, _arg6681);
  if (_ret6680 == -1)
    return -1;
  int _ret6683;
  _ret6683 = guestfs_umount_all (g);
  if (_ret6683 == -1)
    return -1;
  int _ret6685;
  _ret6685 = guestfs_lvm_remove_all (g);
  if (_ret6685 == -1)
    return -1;
  const char *_arg6688 = "/dev/sdb1";
  const char *_arg6689 = "/";
  int _ret6687;
  _ret6687 = guestfs_mount (g, _arg6688, _arg6689);
  if (_ret6687 == -1)
    return -1;

  /* TestResultTrue for mkdir_p (2) */
  const char *_arg6692 = "/mkdir_p3/foo/bar";
  int _ret6691;
  _ret6691 = guestfs_mkdir_p (g, _arg6692);
  if (_ret6691 == -1)
    return -1;
  const char *_arg6694 = "/mkdir_p3";
  int ret;
  ret = guestfs_is_dir (g, _arg6694);
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
test_mkdir_p_3 (void)
{
  if (test_mkdir_p_3_skip ()) {
    skipped ("test_mkdir_p_3", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mkdir_p_3 */
  const char *_arg6697 = "/dev/sda";
  int _ret6696;
  _ret6696 = guestfs_blockdev_setrw (g, _arg6697);
  if (_ret6696 == -1)
    return -1;
  int _ret6699;
  _ret6699 = guestfs_umount_all (g);
  if (_ret6699 == -1)
    return -1;
  int _ret6701;
  _ret6701 = guestfs_lvm_remove_all (g);
  if (_ret6701 == -1)
    return -1;
  const char *_arg6704 = "/dev/sdb1";
  const char *_arg6705 = "/";
  int _ret6703;
  _ret6703 = guestfs_mount (g, _arg6704, _arg6705);
  if (_ret6703 == -1)
    return -1;

  /* TestRun for mkdir_p (3) */
  const char *_arg6708 = "/mkdir_p4";
  int _ret6707;
  _ret6707 = guestfs_mkdir (g, _arg6708);
  if (_ret6707 == -1)
    return -1;
  const char *_arg6711 = "/mkdir_p4";
  int _ret6710;
  _ret6710 = guestfs_mkdir_p (g, _arg6711);
  if (_ret6710 == -1)
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
test_mkdir_p_4 (void)
{
  if (test_mkdir_p_4_skip ()) {
    skipped ("test_mkdir_p_4", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mkdir_p_4 */
  const char *_arg6714 = "/dev/sda";
  int _ret6713;
  _ret6713 = guestfs_blockdev_setrw (g, _arg6714);
  if (_ret6713 == -1)
    return -1;
  int _ret6716;
  _ret6716 = guestfs_umount_all (g);
  if (_ret6716 == -1)
    return -1;
  int _ret6718;
  _ret6718 = guestfs_lvm_remove_all (g);
  if (_ret6718 == -1)
    return -1;
  const char *_arg6721 = "/dev/sdb1";
  const char *_arg6722 = "/";
  int _ret6720;
  _ret6720 = guestfs_mount (g, _arg6721, _arg6722);
  if (_ret6720 == -1)
    return -1;

  /* TestLastFail for mkdir_p (4) */
  const char *_arg6725 = "/mkdir_p5";
  int _ret6724;
  _ret6724 = guestfs_touch (g, _arg6725);
  if (_ret6724 == -1)
    return -1;
  const char *_arg6728 = "/mkdir_p5";
  int _ret6727;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret6727 = guestfs_mkdir_p (g, _arg6728);
  guestfs_pop_error_handler (g);
  if (_ret6727 != -1)
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
test_mkdir_0 (void)
{
  if (test_mkdir_0_skip ()) {
    skipped ("test_mkdir_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mkdir_0 */
  const char *_arg6731 = "/dev/sda";
  int _ret6730;
  _ret6730 = guestfs_blockdev_setrw (g, _arg6731);
  if (_ret6730 == -1)
    return -1;
  int _ret6733;
  _ret6733 = guestfs_umount_all (g);
  if (_ret6733 == -1)
    return -1;
  int _ret6735;
  _ret6735 = guestfs_lvm_remove_all (g);
  if (_ret6735 == -1)
    return -1;
  const char *_arg6738 = "/dev/sdb1";
  const char *_arg6739 = "/";
  int _ret6737;
  _ret6737 = guestfs_mount (g, _arg6738, _arg6739);
  if (_ret6737 == -1)
    return -1;

  /* TestResultTrue for mkdir (0) */
  const char *_arg6742 = "/mkdir";
  int _ret6741;
  _ret6741 = guestfs_mkdir (g, _arg6742);
  if (_ret6741 == -1)
    return -1;
  const char *_arg6744 = "/mkdir";
  int ret;
  ret = guestfs_is_dir (g, _arg6744);
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
test_mkdir_1 (void)
{
  if (test_mkdir_1_skip ()) {
    skipped ("test_mkdir_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_mkdir_1 */
  const char *_arg6747 = "/dev/sda";
  int _ret6746;
  _ret6746 = guestfs_blockdev_setrw (g, _arg6747);
  if (_ret6746 == -1)
    return -1;
  int _ret6749;
  _ret6749 = guestfs_umount_all (g);
  if (_ret6749 == -1)
    return -1;
  int _ret6751;
  _ret6751 = guestfs_lvm_remove_all (g);
  if (_ret6751 == -1)
    return -1;
  const char *_arg6754 = "/dev/sdb1";
  const char *_arg6755 = "/";
  int _ret6753;
  _ret6753 = guestfs_mount (g, _arg6754, _arg6755);
  if (_ret6753 == -1)
    return -1;

  /* TestLastFail for mkdir (1) */
  const char *_arg6758 = "/mkdir2/foo/bar";
  int _ret6757;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret6757 = guestfs_mkdir (g, _arg6758);
  guestfs_pop_error_handler (g);
  if (_ret6757 != -1)
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
test_rm_rf_0 (void)
{
  if (test_rm_rf_0_skip ()) {
    skipped ("test_rm_rf_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_rm_rf_0 */
  const char *_arg6761 = "/dev/sda";
  int _ret6760;
  _ret6760 = guestfs_blockdev_setrw (g, _arg6761);
  if (_ret6760 == -1)
    return -1;
  int _ret6763;
  _ret6763 = guestfs_umount_all (g);
  if (_ret6763 == -1)
    return -1;
  int _ret6765;
  _ret6765 = guestfs_lvm_remove_all (g);
  if (_ret6765 == -1)
    return -1;
  const char *_arg6768 = "/dev/sdb1";
  const char *_arg6769 = "/";
  int _ret6767;
  _ret6767 = guestfs_mount (g, _arg6768, _arg6769);
  if (_ret6767 == -1)
    return -1;

  /* TestResultFalse for rm_rf (0) */
  const char *_arg6772 = "/rm_rf";
  int _ret6771;
  _ret6771 = guestfs_mkdir (g, _arg6772);
  if (_ret6771 == -1)
    return -1;
  const char *_arg6775 = "/rm_rf/foo";
  int _ret6774;
  _ret6774 = guestfs_mkdir (g, _arg6775);
  if (_ret6774 == -1)
    return -1;
  const char *_arg6778 = "/rm_rf/foo/bar";
  int _ret6777;
  _ret6777 = guestfs_touch (g, _arg6778);
  if (_ret6777 == -1)
    return -1;
  const char *_arg6781 = "/rm_rf";
  int _ret6780;
  _ret6780 = guestfs_rm_rf (g, _arg6781);
  if (_ret6780 == -1)
    return -1;
  const char *_arg6783 = "/rm_rf";
  int ret;
  ret = guestfs_exists (g, _arg6783);
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
test_rmdir_0 (void)
{
  if (test_rmdir_0_skip ()) {
    skipped ("test_rmdir_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_rmdir_0 */
  const char *_arg6786 = "/dev/sda";
  int _ret6785;
  _ret6785 = guestfs_blockdev_setrw (g, _arg6786);
  if (_ret6785 == -1)
    return -1;
  int _ret6788;
  _ret6788 = guestfs_umount_all (g);
  if (_ret6788 == -1)
    return -1;
  int _ret6790;
  _ret6790 = guestfs_lvm_remove_all (g);
  if (_ret6790 == -1)
    return -1;
  const char *_arg6793 = "/dev/sdb1";
  const char *_arg6794 = "/";
  int _ret6792;
  _ret6792 = guestfs_mount (g, _arg6793, _arg6794);
  if (_ret6792 == -1)
    return -1;

  /* TestRun for rmdir (0) */
  const char *_arg6797 = "/rmdir";
  int _ret6796;
  _ret6796 = guestfs_mkdir (g, _arg6797);
  if (_ret6796 == -1)
    return -1;
  const char *_arg6800 = "/rmdir";
  int _ret6799;
  _ret6799 = guestfs_rmdir (g, _arg6800);
  if (_ret6799 == -1)
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
test_rmdir_1 (void)
{
  if (test_rmdir_1_skip ()) {
    skipped ("test_rmdir_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_rmdir_1 */
  const char *_arg6803 = "/dev/sda";
  int _ret6802;
  _ret6802 = guestfs_blockdev_setrw (g, _arg6803);
  if (_ret6802 == -1)
    return -1;
  int _ret6805;
  _ret6805 = guestfs_umount_all (g);
  if (_ret6805 == -1)
    return -1;
  int _ret6807;
  _ret6807 = guestfs_lvm_remove_all (g);
  if (_ret6807 == -1)
    return -1;
  const char *_arg6810 = "/dev/sdb1";
  const char *_arg6811 = "/";
  int _ret6809;
  _ret6809 = guestfs_mount (g, _arg6810, _arg6811);
  if (_ret6809 == -1)
    return -1;

  /* TestLastFail for rmdir (1) */
  const char *_arg6814 = "/rmdir2";
  int _ret6813;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret6813 = guestfs_rmdir (g, _arg6814);
  guestfs_pop_error_handler (g);
  if (_ret6813 != -1)
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
test_rmdir_2 (void)
{
  if (test_rmdir_2_skip ()) {
    skipped ("test_rmdir_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_rmdir_2 */
  const char *_arg6817 = "/dev/sda";
  int _ret6816;
  _ret6816 = guestfs_blockdev_setrw (g, _arg6817);
  if (_ret6816 == -1)
    return -1;
  int _ret6819;
  _ret6819 = guestfs_umount_all (g);
  if (_ret6819 == -1)
    return -1;
  int _ret6821;
  _ret6821 = guestfs_lvm_remove_all (g);
  if (_ret6821 == -1)
    return -1;
  const char *_arg6824 = "/dev/sdb1";
  const char *_arg6825 = "/";
  int _ret6823;
  _ret6823 = guestfs_mount (g, _arg6824, _arg6825);
  if (_ret6823 == -1)
    return -1;

  /* TestLastFail for rmdir (2) */
  const char *_arg6828 = "/rmdir3";
  int _ret6827;
  _ret6827 = guestfs_mkdir (g, _arg6828);
  if (_ret6827 == -1)
    return -1;
  const char *_arg6831 = "/rmdir3/new";
  int _ret6830;
  _ret6830 = guestfs_touch (g, _arg6831);
  if (_ret6830 == -1)
    return -1;
  const char *_arg6834 = "/rmdir3/new";
  int _ret6833;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret6833 = guestfs_rmdir (g, _arg6834);
  guestfs_pop_error_handler (g);
  if (_ret6833 != -1)
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
test_rm_0 (void)
{
  if (test_rm_0_skip ()) {
    skipped ("test_rm_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_rm_0 */
  const char *_arg6837 = "/dev/sda";
  int _ret6836;
  _ret6836 = guestfs_blockdev_setrw (g, _arg6837);
  if (_ret6836 == -1)
    return -1;
  int _ret6839;
  _ret6839 = guestfs_umount_all (g);
  if (_ret6839 == -1)
    return -1;
  int _ret6841;
  _ret6841 = guestfs_lvm_remove_all (g);
  if (_ret6841 == -1)
    return -1;
  const char *_arg6844 = "/dev/sdb1";
  const char *_arg6845 = "/";
  int _ret6843;
  _ret6843 = guestfs_mount (g, _arg6844, _arg6845);
  if (_ret6843 == -1)
    return -1;

  /* TestRun for rm (0) */
  const char *_arg6848 = "/rm";
  int _ret6847;
  _ret6847 = guestfs_mkdir (g, _arg6848);
  if (_ret6847 == -1)
    return -1;
  const char *_arg6851 = "/rm/new";
  int _ret6850;
  _ret6850 = guestfs_touch (g, _arg6851);
  if (_ret6850 == -1)
    return -1;
  const char *_arg6854 = "/rm/new";
  int _ret6853;
  _ret6853 = guestfs_rm (g, _arg6854);
  if (_ret6853 == -1)
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
test_rm_1 (void)
{
  if (test_rm_1_skip ()) {
    skipped ("test_rm_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_rm_1 */
  const char *_arg6857 = "/dev/sda";
  int _ret6856;
  _ret6856 = guestfs_blockdev_setrw (g, _arg6857);
  if (_ret6856 == -1)
    return -1;
  int _ret6859;
  _ret6859 = guestfs_umount_all (g);
  if (_ret6859 == -1)
    return -1;
  int _ret6861;
  _ret6861 = guestfs_lvm_remove_all (g);
  if (_ret6861 == -1)
    return -1;
  const char *_arg6864 = "/dev/sdb1";
  const char *_arg6865 = "/";
  int _ret6863;
  _ret6863 = guestfs_mount (g, _arg6864, _arg6865);
  if (_ret6863 == -1)
    return -1;

  /* TestLastFail for rm (1) */
  const char *_arg6868 = "/nosuchfile";
  int _ret6867;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret6867 = guestfs_rm (g, _arg6868);
  guestfs_pop_error_handler (g);
  if (_ret6867 != -1)
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
test_rm_2 (void)
{
  if (test_rm_2_skip ()) {
    skipped ("test_rm_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_rm_2 */
  const char *_arg6871 = "/dev/sda";
  int _ret6870;
  _ret6870 = guestfs_blockdev_setrw (g, _arg6871);
  if (_ret6870 == -1)
    return -1;
  int _ret6873;
  _ret6873 = guestfs_umount_all (g);
  if (_ret6873 == -1)
    return -1;
  int _ret6875;
  _ret6875 = guestfs_lvm_remove_all (g);
  if (_ret6875 == -1)
    return -1;
  const char *_arg6878 = "/dev/sdb1";
  const char *_arg6879 = "/";
  int _ret6877;
  _ret6877 = guestfs_mount (g, _arg6878, _arg6879);
  if (_ret6877 == -1)
    return -1;

  /* TestLastFail for rm (2) */
  const char *_arg6882 = "/rm2";
  int _ret6881;
  _ret6881 = guestfs_mkdir (g, _arg6882);
  if (_ret6881 == -1)
    return -1;
  const char *_arg6885 = "/rm2";
  int _ret6884;
  guestfs_push_error_handler (g, NULL, NULL);
  _ret6884 = guestfs_rm (g, _arg6885);
  guestfs_pop_error_handler (g);
  if (_ret6884 != -1)
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
test_lvs_0 (void)
{
  if (test_lvs_0_skip ()) {
    skipped ("test_lvs_0", "environment variable set");
    return 0;
  }

  const char *_features6887[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features6887)) {
    skipped ("test_lvs_0", "group %s not available in daemon",
             _features6887[0]);
    return 0;
  }

  /* InitBasicFSonLVM for test_lvs_0: create ext2 on /dev/VG/LV */
  const char *_arg6889 = "/dev/sda";
  int _ret6888;
  _ret6888 = guestfs_blockdev_setrw (g, _arg6889);
  if (_ret6888 == -1)
    return -1;
  int _ret6891;
  _ret6891 = guestfs_umount_all (g);
  if (_ret6891 == -1)
    return -1;
  int _ret6893;
  _ret6893 = guestfs_lvm_remove_all (g);
  if (_ret6893 == -1)
    return -1;
  const char *_arg6896 = "/dev/sda";
  const char *_arg6897 = "mbr";
  int _ret6895;
  _ret6895 = guestfs_part_disk (g, _arg6896, _arg6897);
  if (_ret6895 == -1)
    return -1;
  const char *_arg6900 = "/dev/sda1";
  int _ret6899;
  _ret6899 = guestfs_pvcreate (g, _arg6900);
  if (_ret6899 == -1)
    return -1;
  const char *_arg6903 = "VG";
  const char *_arg6904_0 = "/dev/sda1";
  const char *const _arg6904[] = {
    _arg6904_0,
    NULL
  };
  int _ret6902;
  _ret6902 = guestfs_vgcreate (g, _arg6903, (char **) _arg6904);
  if (_ret6902 == -1)
    return -1;
  const char *_arg6907 = "LV";
  const char *_arg6908 = "VG";
  int _ret6906;
  _ret6906 = guestfs_lvcreate (g, _arg6907, _arg6908, 8);
  if (_ret6906 == -1)
    return -1;
  const char *_arg6912 = "ext2";
  const char *_arg6913 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs6914;
  _optargs6914.bitmask = UINT64_C(0x0);
  int _ret6911;
  _ret6911 = guestfs_mkfs_opts_argv (g, _arg6912, _arg6913, &_optargs6914);
  if (_ret6911 == -1)
    return -1;
  const char *_arg6916 = "/dev/VG/LV";
  const char *_arg6917 = "/";
  int _ret6915;
  _ret6915 = guestfs_mount (g, _arg6916, _arg6917);
  if (_ret6915 == -1)
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
test_lvs_1 (void)
{
  if (test_lvs_1_skip ()) {
    skipped ("test_lvs_1", "environment variable set");
    return 0;
  }

  const char *_features6920[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features6920)) {
    skipped ("test_lvs_1", "group %s not available in daemon",
             _features6920[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_lvs_1 */
  const char *_arg6922 = "/dev/sda";
  int _ret6921;
  _ret6921 = guestfs_blockdev_setrw (g, _arg6922);
  if (_ret6921 == -1)
    return -1;
  int _ret6924;
  _ret6924 = guestfs_umount_all (g);
  if (_ret6924 == -1)
    return -1;
  int _ret6926;
  _ret6926 = guestfs_lvm_remove_all (g);
  if (_ret6926 == -1)
    return -1;

  /* TestResult for lvs (1) */
  const char *_arg6928 = "/dev/sda";
  const char *_arg6929 = "mbr";
  int ret12;
  ret12 = guestfs_part_init (g, _arg6928, _arg6929);
  if (ret12 == -1)
    return -1;
  const char *_arg6931 = "/dev/sda";
  const char *_arg6932 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, _arg6931, _arg6932, 64, 204799);
  if (ret11 == -1)
    return -1;
  const char *_arg6936 = "/dev/sda";
  const char *_arg6937 = "p";
  int ret10;
  ret10 = guestfs_part_add (g, _arg6936, _arg6937, 204800, 409599);
  if (ret10 == -1)
    return -1;
  const char *_arg6941 = "/dev/sda";
  const char *_arg6942 = "p";
  int ret9;
  ret9 = guestfs_part_add (g, _arg6941, _arg6942, 409600, -64);
  if (ret9 == -1)
    return -1;
  const char *_arg6946 = "/dev/sda1";
  int ret8;
  ret8 = guestfs_pvcreate (g, _arg6946);
  if (ret8 == -1)
    return -1;
  const char *_arg6948 = "/dev/sda2";
  int ret7;
  ret7 = guestfs_pvcreate (g, _arg6948);
  if (ret7 == -1)
    return -1;
  const char *_arg6950 = "/dev/sda3";
  int ret6;
  ret6 = guestfs_pvcreate (g, _arg6950);
  if (ret6 == -1)
    return -1;
  const char *_arg6952 = "VG1";
  const char *_arg6953_0 = "/dev/sda1";
  const char *_arg6953_1 = "/dev/sda2";
  const char *const _arg6953[] = {
    _arg6953_0,
    _arg6953_1,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, _arg6952, (char **) _arg6953);
  if (ret5 == -1)
    return -1;
  const char *_arg6955 = "VG2";
  const char *_arg6956_0 = "/dev/sda3";
  const char *const _arg6956[] = {
    _arg6956_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, _arg6955, (char **) _arg6956);
  if (ret4 == -1)
    return -1;
  const char *_arg6958 = "LV1";
  const char *_arg6959 = "VG1";
  int ret3;
  ret3 = guestfs_lvcreate (g, _arg6958, _arg6959, 50);
  if (ret3 == -1)
    return -1;
  const char *_arg6962 = "LV2";
  const char *_arg6963 = "VG1";
  int ret2;
  ret2 = guestfs_lvcreate (g, _arg6962, _arg6963, 50);
  if (ret2 == -1)
    return -1;
  const char *_arg6966 = "LV3";
  const char *_arg6967 = "VG2";
  int ret1;
  ret1 = guestfs_lvcreate (g, _arg6966, _arg6967, 50);
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
test_vgs_0 (void)
{
  if (test_vgs_0_skip ()) {
    skipped ("test_vgs_0", "environment variable set");
    return 0;
  }

  const char *_features6971[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features6971)) {
    skipped ("test_vgs_0", "group %s not available in daemon",
             _features6971[0]);
    return 0;
  }

  /* InitBasicFSonLVM for test_vgs_0: create ext2 on /dev/VG/LV */
  const char *_arg6973 = "/dev/sda";
  int _ret6972;
  _ret6972 = guestfs_blockdev_setrw (g, _arg6973);
  if (_ret6972 == -1)
    return -1;
  int _ret6975;
  _ret6975 = guestfs_umount_all (g);
  if (_ret6975 == -1)
    return -1;
  int _ret6977;
  _ret6977 = guestfs_lvm_remove_all (g);
  if (_ret6977 == -1)
    return -1;
  const char *_arg6980 = "/dev/sda";
  const char *_arg6981 = "mbr";
  int _ret6979;
  _ret6979 = guestfs_part_disk (g, _arg6980, _arg6981);
  if (_ret6979 == -1)
    return -1;
  const char *_arg6984 = "/dev/sda1";
  int _ret6983;
  _ret6983 = guestfs_pvcreate (g, _arg6984);
  if (_ret6983 == -1)
    return -1;
  const char *_arg6987 = "VG";
  const char *_arg6988_0 = "/dev/sda1";
  const char *const _arg6988[] = {
    _arg6988_0,
    NULL
  };
  int _ret6986;
  _ret6986 = guestfs_vgcreate (g, _arg6987, (char **) _arg6988);
  if (_ret6986 == -1)
    return -1;
  const char *_arg6991 = "LV";
  const char *_arg6992 = "VG";
  int _ret6990;
  _ret6990 = guestfs_lvcreate (g, _arg6991, _arg6992, 8);
  if (_ret6990 == -1)
    return -1;
  const char *_arg6996 = "ext2";
  const char *_arg6997 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs6998;
  _optargs6998.bitmask = UINT64_C(0x0);
  int _ret6995;
  _ret6995 = guestfs_mkfs_opts_argv (g, _arg6996, _arg6997, &_optargs6998);
  if (_ret6995 == -1)
    return -1;
  const char *_arg7000 = "/dev/VG/LV";
  const char *_arg7001 = "/";
  int _ret6999;
  _ret6999 = guestfs_mount (g, _arg7000, _arg7001);
  if (_ret6999 == -1)
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
test_vgs_1 (void)
{
  if (test_vgs_1_skip ()) {
    skipped ("test_vgs_1", "environment variable set");
    return 0;
  }

  const char *_features7004[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features7004)) {
    skipped ("test_vgs_1", "group %s not available in daemon",
             _features7004[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_vgs_1 */
  const char *_arg7006 = "/dev/sda";
  int _ret7005;
  _ret7005 = guestfs_blockdev_setrw (g, _arg7006);
  if (_ret7005 == -1)
    return -1;
  int _ret7008;
  _ret7008 = guestfs_umount_all (g);
  if (_ret7008 == -1)
    return -1;
  int _ret7010;
  _ret7010 = guestfs_lvm_remove_all (g);
  if (_ret7010 == -1)
    return -1;

  /* TestResult for vgs (1) */
  const char *_arg7012 = "/dev/sda";
  const char *_arg7013 = "mbr";
  int ret9;
  ret9 = guestfs_part_init (g, _arg7012, _arg7013);
  if (ret9 == -1)
    return -1;
  const char *_arg7015 = "/dev/sda";
  const char *_arg7016 = "p";
  int ret8;
  ret8 = guestfs_part_add (g, _arg7015, _arg7016, 64, 204799);
  if (ret8 == -1)
    return -1;
  const char *_arg7020 = "/dev/sda";
  const char *_arg7021 = "p";
  int ret7;
  ret7 = guestfs_part_add (g, _arg7020, _arg7021, 204800, 409599);
  if (ret7 == -1)
    return -1;
  const char *_arg7025 = "/dev/sda";
  const char *_arg7026 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg7025, _arg7026, 409600, -64);
  if (ret6 == -1)
    return -1;
  const char *_arg7030 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, _arg7030);
  if (ret5 == -1)
    return -1;
  const char *_arg7032 = "/dev/sda2";
  int ret4;
  ret4 = guestfs_pvcreate (g, _arg7032);
  if (ret4 == -1)
    return -1;
  const char *_arg7034 = "/dev/sda3";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg7034);
  if (ret3 == -1)
    return -1;
  const char *_arg7036 = "VG1";
  const char *_arg7037_0 = "/dev/sda1";
  const char *_arg7037_1 = "/dev/sda2";
  const char *const _arg7037[] = {
    _arg7037_0,
    _arg7037_1,
    NULL
  };
  int ret2;
  ret2 = guestfs_vgcreate (g, _arg7036, (char **) _arg7037);
  if (ret2 == -1)
    return -1;
  const char *_arg7039 = "VG2";
  const char *_arg7040_0 = "/dev/sda3";
  const char *const _arg7040[] = {
    _arg7040_0,
    NULL
  };
  int ret1;
  ret1 = guestfs_vgcreate (g, _arg7039, (char **) _arg7040);
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
test_pvs_0 (void)
{
  if (test_pvs_0_skip ()) {
    skipped ("test_pvs_0", "environment variable set");
    return 0;
  }

  const char *_features7043[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features7043)) {
    skipped ("test_pvs_0", "group %s not available in daemon",
             _features7043[0]);
    return 0;
  }

  /* InitBasicFSonLVM for test_pvs_0: create ext2 on /dev/VG/LV */
  const char *_arg7045 = "/dev/sda";
  int _ret7044;
  _ret7044 = guestfs_blockdev_setrw (g, _arg7045);
  if (_ret7044 == -1)
    return -1;
  int _ret7047;
  _ret7047 = guestfs_umount_all (g);
  if (_ret7047 == -1)
    return -1;
  int _ret7049;
  _ret7049 = guestfs_lvm_remove_all (g);
  if (_ret7049 == -1)
    return -1;
  const char *_arg7052 = "/dev/sda";
  const char *_arg7053 = "mbr";
  int _ret7051;
  _ret7051 = guestfs_part_disk (g, _arg7052, _arg7053);
  if (_ret7051 == -1)
    return -1;
  const char *_arg7056 = "/dev/sda1";
  int _ret7055;
  _ret7055 = guestfs_pvcreate (g, _arg7056);
  if (_ret7055 == -1)
    return -1;
  const char *_arg7059 = "VG";
  const char *_arg7060_0 = "/dev/sda1";
  const char *const _arg7060[] = {
    _arg7060_0,
    NULL
  };
  int _ret7058;
  _ret7058 = guestfs_vgcreate (g, _arg7059, (char **) _arg7060);
  if (_ret7058 == -1)
    return -1;
  const char *_arg7063 = "LV";
  const char *_arg7064 = "VG";
  int _ret7062;
  _ret7062 = guestfs_lvcreate (g, _arg7063, _arg7064, 8);
  if (_ret7062 == -1)
    return -1;
  const char *_arg7068 = "ext2";
  const char *_arg7069 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv _optargs7070;
  _optargs7070.bitmask = UINT64_C(0x0);
  int _ret7067;
  _ret7067 = guestfs_mkfs_opts_argv (g, _arg7068, _arg7069, &_optargs7070);
  if (_ret7067 == -1)
    return -1;
  const char *_arg7072 = "/dev/VG/LV";
  const char *_arg7073 = "/";
  int _ret7071;
  _ret7071 = guestfs_mount (g, _arg7072, _arg7073);
  if (_ret7071 == -1)
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
test_pvs_1 (void)
{
  if (test_pvs_1_skip ()) {
    skipped ("test_pvs_1", "environment variable set");
    return 0;
  }

  const char *_features7076[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) _features7076)) {
    skipped ("test_pvs_1", "group %s not available in daemon",
             _features7076[0]);
    return 0;
  }

  /* InitNone|InitEmpty for test_pvs_1 */
  const char *_arg7078 = "/dev/sda";
  int _ret7077;
  _ret7077 = guestfs_blockdev_setrw (g, _arg7078);
  if (_ret7077 == -1)
    return -1;
  int _ret7080;
  _ret7080 = guestfs_umount_all (g);
  if (_ret7080 == -1)
    return -1;
  int _ret7082;
  _ret7082 = guestfs_lvm_remove_all (g);
  if (_ret7082 == -1)
    return -1;

  /* TestResult for pvs (1) */
  const char *_arg7084 = "/dev/sda";
  const char *_arg7085 = "mbr";
  int ret7;
  ret7 = guestfs_part_init (g, _arg7084, _arg7085);
  if (ret7 == -1)
    return -1;
  const char *_arg7087 = "/dev/sda";
  const char *_arg7088 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, _arg7087, _arg7088, 64, 204799);
  if (ret6 == -1)
    return -1;
  const char *_arg7092 = "/dev/sda";
  const char *_arg7093 = "p";
  int ret5;
  ret5 = guestfs_part_add (g, _arg7092, _arg7093, 204800, 409599);
  if (ret5 == -1)
    return -1;
  const char *_arg7097 = "/dev/sda";
  const char *_arg7098 = "p";
  int ret4;
  ret4 = guestfs_part_add (g, _arg7097, _arg7098, 409600, -64);
  if (ret4 == -1)
    return -1;
  const char *_arg7102 = "/dev/sda1";
  int ret3;
  ret3 = guestfs_pvcreate (g, _arg7102);
  if (ret3 == -1)
    return -1;
  const char *_arg7104 = "/dev/sda2";
  int ret2;
  ret2 = guestfs_pvcreate (g, _arg7104);
  if (ret2 == -1)
    return -1;
  const char *_arg7106 = "/dev/sda3";
  int ret1;
  ret1 = guestfs_pvcreate (g, _arg7106);
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
test_list_partitions_0 (void)
{
  if (test_list_partitions_0_skip ()) {
    skipped ("test_list_partitions_0", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_list_partitions_0: create ext2 on /dev/sda1 */
  const char *_arg7110 = "/dev/sda";
  int _ret7109;
  _ret7109 = guestfs_blockdev_setrw (g, _arg7110);
  if (_ret7109 == -1)
    return -1;
  int _ret7112;
  _ret7112 = guestfs_umount_all (g);
  if (_ret7112 == -1)
    return -1;
  int _ret7114;
  _ret7114 = guestfs_lvm_remove_all (g);
  if (_ret7114 == -1)
    return -1;
  const char *_arg7117 = "/dev/sda";
  const char *_arg7118 = "mbr";
  int _ret7116;
  _ret7116 = guestfs_part_disk (g, _arg7117, _arg7118);
  if (_ret7116 == -1)
    return -1;
  const char *_arg7121 = "ext2";
  const char *_arg7122 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs7123;
  _optargs7123.bitmask = UINT64_C(0x0);
  int _ret7120;
  _ret7120 = guestfs_mkfs_opts_argv (g, _arg7121, _arg7122, &_optargs7123);
  if (_ret7120 == -1)
    return -1;
  const char *_arg7125 = "/dev/sda1";
  const char *_arg7126 = "/";
  int _ret7124;
  _ret7124 = guestfs_mount (g, _arg7125, _arg7126);
  if (_ret7124 == -1)
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
test_list_partitions_1 (void)
{
  if (test_list_partitions_1_skip ()) {
    skipped ("test_list_partitions_1", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_list_partitions_1 */
  const char *_arg7130 = "/dev/sda";
  int _ret7129;
  _ret7129 = guestfs_blockdev_setrw (g, _arg7130);
  if (_ret7129 == -1)
    return -1;
  int _ret7132;
  _ret7132 = guestfs_umount_all (g);
  if (_ret7132 == -1)
    return -1;
  int _ret7134;
  _ret7134 = guestfs_lvm_remove_all (g);
  if (_ret7134 == -1)
    return -1;

  /* TestResult for list_partitions (1) */
  const char *_arg7136 = "/dev/sda";
  const char *_arg7137 = "mbr";
  int ret4;
  ret4 = guestfs_part_init (g, _arg7136, _arg7137);
  if (ret4 == -1)
    return -1;
  const char *_arg7139 = "/dev/sda";
  const char *_arg7140 = "p";
  int ret3;
  ret3 = guestfs_part_add (g, _arg7139, _arg7140, 64, 204799);
  if (ret3 == -1)
    return -1;
  const char *_arg7144 = "/dev/sda";
  const char *_arg7145 = "p";
  int ret2;
  ret2 = guestfs_part_add (g, _arg7144, _arg7145, 204800, 409599);
  if (ret2 == -1)
    return -1;
  const char *_arg7149 = "/dev/sda";
  const char *_arg7150 = "p";
  int ret1;
  ret1 = guestfs_part_add (g, _arg7149, _arg7150, 409600, -64);
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
test_list_devices_0 (void)
{
  if (test_list_devices_0_skip ()) {
    skipped ("test_list_devices_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_list_devices_0 */
  const char *_arg7156 = "/dev/sda";
  int _ret7155;
  _ret7155 = guestfs_blockdev_setrw (g, _arg7156);
  if (_ret7155 == -1)
    return -1;
  int _ret7158;
  _ret7158 = guestfs_umount_all (g);
  if (_ret7158 == -1)
    return -1;
  int _ret7160;
  _ret7160 = guestfs_lvm_remove_all (g);
  if (_ret7160 == -1)
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
test_touch_0 (void)
{
  if (test_touch_0_skip ()) {
    skipped ("test_touch_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_touch_0 */
  const char *_arg7164 = "/dev/sda";
  int _ret7163;
  _ret7163 = guestfs_blockdev_setrw (g, _arg7164);
  if (_ret7163 == -1)
    return -1;
  int _ret7166;
  _ret7166 = guestfs_umount_all (g);
  if (_ret7166 == -1)
    return -1;
  int _ret7168;
  _ret7168 = guestfs_lvm_remove_all (g);
  if (_ret7168 == -1)
    return -1;
  const char *_arg7171 = "/dev/sdb1";
  const char *_arg7172 = "/";
  int _ret7170;
  _ret7170 = guestfs_mount (g, _arg7171, _arg7172);
  if (_ret7170 == -1)
    return -1;

  /* TestResultTrue for touch (0) */
  const char *_arg7175 = "/touch";
  int _ret7174;
  _ret7174 = guestfs_touch (g, _arg7175);
  if (_ret7174 == -1)
    return -1;
  const char *_arg7177 = "/touch";
  int ret;
  ret = guestfs_exists (g, _arg7177);
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
test_sync_0 (void)
{
  if (test_sync_0_skip ()) {
    skipped ("test_sync_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_sync_0 */
  const char *_arg7180 = "/dev/sda";
  int _ret7179;
  _ret7179 = guestfs_blockdev_setrw (g, _arg7180);
  if (_ret7179 == -1)
    return -1;
  int _ret7182;
  _ret7182 = guestfs_umount_all (g);
  if (_ret7182 == -1)
    return -1;
  int _ret7184;
  _ret7184 = guestfs_lvm_remove_all (g);
  if (_ret7184 == -1)
    return -1;

  /* TestRun for sync (0) */
  int _ret7186;
  _ret7186 = guestfs_sync (g);
  if (_ret7186 == -1)
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
test_mount_0 (void)
{
  if (test_mount_0_skip ()) {
    skipped ("test_mount_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_mount_0 */
  const char *_arg7189 = "/dev/sda";
  int _ret7188;
  _ret7188 = guestfs_blockdev_setrw (g, _arg7189);
  if (_ret7188 == -1)
    return -1;
  int _ret7191;
  _ret7191 = guestfs_umount_all (g);
  if (_ret7191 == -1)
    return -1;
  int _ret7193;
  _ret7193 = guestfs_lvm_remove_all (g);
  if (_ret7193 == -1)
    return -1;

  /* TestResultString for mount (0) */
  const char *_arg7196 = "/dev/sda";
  const char *_arg7197 = "mbr";
  int _ret7195;
  _ret7195 = guestfs_part_disk (g, _arg7196, _arg7197);
  if (_ret7195 == -1)
    return -1;
  const char *_arg7200 = "ext2";
  const char *_arg7201 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs7202;
  _optargs7202.bitmask = UINT64_C(0x0);
  int _ret7199;
  _ret7199 = guestfs_mkfs_opts_argv (g, _arg7200, _arg7201, &_optargs7202);
  if (_ret7199 == -1)
    return -1;
  const char *_arg7204 = "/dev/sda1";
  const char *_arg7205 = "/";
  int _ret7203;
  _ret7203 = guestfs_mount (g, _arg7204, _arg7205);
  if (_ret7203 == -1)
    return -1;
  const char *_arg7208 = "/new";
  const char *_arg7209 = "new file contents";
  size_t _arg7209_size = 17;
  int _ret7207;
  _ret7207 = guestfs_write (g, _arg7208, _arg7209, _arg7209_size);
  if (_ret7207 == -1)
    return -1;
  const char *_arg7211 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg7211);
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
test_get_program_0 (void)
{
  if (test_get_program_0_skip ()) {
    skipped ("test_get_program_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_program_0 */
  const char *_arg7214 = "/dev/sda";
  int _ret7213;
  _ret7213 = guestfs_blockdev_setrw (g, _arg7214);
  if (_ret7213 == -1)
    return -1;
  int _ret7216;
  _ret7216 = guestfs_umount_all (g);
  if (_ret7216 == -1)
    return -1;
  int _ret7218;
  _ret7218 = guestfs_lvm_remove_all (g);
  if (_ret7218 == -1)
    return -1;

  /* TestRun for get_program (0) */
  const char *_ret7220;
  _ret7220 = guestfs_get_program (g);
  if (_ret7220 == NULL)
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
test_disk_has_backing_file_0 (void)
{
  if (test_disk_has_backing_file_0_skip ()) {
    skipped ("test_disk_has_backing_file_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_has_backing_file_0 */
  const char *_arg7223 = "/dev/sda";
  int _ret7222;
  _ret7222 = guestfs_blockdev_setrw (g, _arg7223);
  if (_ret7222 == -1)
    return -1;
  int _ret7225;
  _ret7225 = guestfs_umount_all (g);
  if (_ret7225 == -1)
    return -1;
  int _ret7227;
  _ret7227 = guestfs_lvm_remove_all (g);
  if (_ret7227 == -1)
    return -1;

  /* TestResultFalse for disk_has_backing_file (0) */
  const char *_arg7229 = "test1.img";
  int ret;
  ret = guestfs_disk_has_backing_file (g, _arg7229);
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
test_disk_has_backing_file_1 (void)
{
  if (test_disk_has_backing_file_1_skip ()) {
    skipped ("test_disk_has_backing_file_1", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_has_backing_file_1 */
  const char *_arg7232 = "/dev/sda";
  int _ret7231;
  _ret7231 = guestfs_blockdev_setrw (g, _arg7232);
  if (_ret7231 == -1)
    return -1;
  int _ret7234;
  _ret7234 = guestfs_umount_all (g);
  if (_ret7234 == -1)
    return -1;
  int _ret7236;
  _ret7236 = guestfs_lvm_remove_all (g);
  if (_ret7236 == -1)
    return -1;

  /* TestResultFalse for disk_has_backing_file (1) */
  const char *_arg7238 = "test2.img";
  int ret;
  ret = guestfs_disk_has_backing_file (g, _arg7238);
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
test_disk_has_backing_file_2 (void)
{
  if (test_disk_has_backing_file_2_skip ()) {
    skipped ("test_disk_has_backing_file_2", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_has_backing_file_2 */
  const char *_arg7241 = "/dev/sda";
  int _ret7240;
  _ret7240 = guestfs_blockdev_setrw (g, _arg7241);
  if (_ret7240 == -1)
    return -1;
  int _ret7243;
  _ret7243 = guestfs_umount_all (g);
  if (_ret7243 == -1)
    return -1;
  int _ret7245;
  _ret7245 = guestfs_lvm_remove_all (g);
  if (_ret7245 == -1)
    return -1;

  /* TestResultFalse for disk_has_backing_file (2) */
  const char *_arg7247 = "test3.img";
  int ret;
  ret = guestfs_disk_has_backing_file (g, _arg7247);
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
test_disk_virtual_size_0 (void)
{
  if (test_disk_virtual_size_0_skip ()) {
    skipped ("test_disk_virtual_size_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_virtual_size_0 */
  const char *_arg7250 = "/dev/sda";
  int _ret7249;
  _ret7249 = guestfs_blockdev_setrw (g, _arg7250);
  if (_ret7249 == -1)
    return -1;
  int _ret7252;
  _ret7252 = guestfs_umount_all (g);
  if (_ret7252 == -1)
    return -1;
  int _ret7254;
  _ret7254 = guestfs_lvm_remove_all (g);
  if (_ret7254 == -1)
    return -1;

  /* TestResult for disk_virtual_size (0) */
  const char *_arg7256 = "test1.img";
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, _arg7256);
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
test_disk_virtual_size_1 (void)
{
  if (test_disk_virtual_size_1_skip ()) {
    skipped ("test_disk_virtual_size_1", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_virtual_size_1 */
  const char *_arg7259 = "/dev/sda";
  int _ret7258;
  _ret7258 = guestfs_blockdev_setrw (g, _arg7259);
  if (_ret7258 == -1)
    return -1;
  int _ret7261;
  _ret7261 = guestfs_umount_all (g);
  if (_ret7261 == -1)
    return -1;
  int _ret7263;
  _ret7263 = guestfs_lvm_remove_all (g);
  if (_ret7263 == -1)
    return -1;

  /* TestResult for disk_virtual_size (1) */
  const char *_arg7265 = "test2.img";
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, _arg7265);
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
test_disk_virtual_size_2 (void)
{
  if (test_disk_virtual_size_2_skip ()) {
    skipped ("test_disk_virtual_size_2", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_virtual_size_2 */
  const char *_arg7268 = "/dev/sda";
  int _ret7267;
  _ret7267 = guestfs_blockdev_setrw (g, _arg7268);
  if (_ret7267 == -1)
    return -1;
  int _ret7270;
  _ret7270 = guestfs_umount_all (g);
  if (_ret7270 == -1)
    return -1;
  int _ret7272;
  _ret7272 = guestfs_lvm_remove_all (g);
  if (_ret7272 == -1)
    return -1;

  /* TestResult for disk_virtual_size (2) */
  const char *_arg7274 = "test3.img";
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, _arg7274);
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
test_disk_format_0 (void)
{
  if (test_disk_format_0_skip ()) {
    skipped ("test_disk_format_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_format_0 */
  const char *_arg7277 = "/dev/sda";
  int _ret7276;
  _ret7276 = guestfs_blockdev_setrw (g, _arg7277);
  if (_ret7276 == -1)
    return -1;
  int _ret7279;
  _ret7279 = guestfs_umount_all (g);
  if (_ret7279 == -1)
    return -1;
  int _ret7281;
  _ret7281 = guestfs_lvm_remove_all (g);
  if (_ret7281 == -1)
    return -1;

  /* TestResultString for disk_format (0) */
  const char *_arg7283 = "test1.img";
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, _arg7283);
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
test_disk_format_1 (void)
{
  if (test_disk_format_1_skip ()) {
    skipped ("test_disk_format_1", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_format_1 */
  const char *_arg7286 = "/dev/sda";
  int _ret7285;
  _ret7285 = guestfs_blockdev_setrw (g, _arg7286);
  if (_ret7285 == -1)
    return -1;
  int _ret7288;
  _ret7288 = guestfs_umount_all (g);
  if (_ret7288 == -1)
    return -1;
  int _ret7290;
  _ret7290 = guestfs_lvm_remove_all (g);
  if (_ret7290 == -1)
    return -1;

  /* TestResultString for disk_format (1) */
  const char *_arg7292 = "test2.img";
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, _arg7292);
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
test_disk_format_2 (void)
{
  if (test_disk_format_2_skip ()) {
    skipped ("test_disk_format_2", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_format_2 */
  const char *_arg7295 = "/dev/sda";
  int _ret7294;
  _ret7294 = guestfs_blockdev_setrw (g, _arg7295);
  if (_ret7294 == -1)
    return -1;
  int _ret7297;
  _ret7297 = guestfs_umount_all (g);
  if (_ret7297 == -1)
    return -1;
  int _ret7299;
  _ret7299 = guestfs_lvm_remove_all (g);
  if (_ret7299 == -1)
    return -1;

  /* TestResultString for disk_format (2) */
  const char *_arg7301 = "test3.img";
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, _arg7301);
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
test_ls_0 (void)
{
  if (test_ls_0_skip ()) {
    skipped ("test_ls_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_ls_0 */
  const char *_arg7304 = "/dev/sda";
  int _ret7303;
  _ret7303 = guestfs_blockdev_setrw (g, _arg7304);
  if (_ret7303 == -1)
    return -1;
  int _ret7306;
  _ret7306 = guestfs_umount_all (g);
  if (_ret7306 == -1)
    return -1;
  int _ret7308;
  _ret7308 = guestfs_lvm_remove_all (g);
  if (_ret7308 == -1)
    return -1;
  const char *_arg7311 = "/dev/sdb1";
  const char *_arg7312 = "/";
  int _ret7310;
  _ret7310 = guestfs_mount (g, _arg7311, _arg7312);
  if (_ret7310 == -1)
    return -1;

  /* TestResult for ls (0) */
  const char *_arg7314 = "/ls";
  int ret4;
  ret4 = guestfs_mkdir (g, _arg7314);
  if (ret4 == -1)
    return -1;
  const char *_arg7316 = "/ls/new";
  int ret3;
  ret3 = guestfs_touch (g, _arg7316);
  if (ret3 == -1)
    return -1;
  const char *_arg7318 = "/ls/newer";
  int ret2;
  ret2 = guestfs_touch (g, _arg7318);
  if (ret2 == -1)
    return -1;
  const char *_arg7320 = "/ls/newest";
  int ret1;
  ret1 = guestfs_touch (g, _arg7320);
  if (ret1 == -1)
    return -1;
  const char *_arg7322 = "/ls";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_ls (g, _arg7322);
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
test_write_append_0 (void)
{
  if (test_write_append_0_skip ()) {
    skipped ("test_write_append_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_write_append_0 */
  const char *_arg7325 = "/dev/sda";
  int _ret7324;
  _ret7324 = guestfs_blockdev_setrw (g, _arg7325);
  if (_ret7324 == -1)
    return -1;
  int _ret7327;
  _ret7327 = guestfs_umount_all (g);
  if (_ret7327 == -1)
    return -1;
  int _ret7329;
  _ret7329 = guestfs_lvm_remove_all (g);
  if (_ret7329 == -1)
    return -1;
  const char *_arg7332 = "/dev/sdb1";
  const char *_arg7333 = "/";
  int _ret7331;
  _ret7331 = guestfs_mount (g, _arg7332, _arg7333);
  if (_ret7331 == -1)
    return -1;

  /* TestResultString for write_append (0) */
  const char *_arg7336 = "/write_append";
  const char *_arg7337 = "line1\n";
  size_t _arg7337_size = 6;
  int _ret7335;
  _ret7335 = guestfs_write (g, _arg7336, _arg7337, _arg7337_size);
  if (_ret7335 == -1)
    return -1;
  const char *_arg7340 = "/write_append";
  const char *_arg7341 = "line2\n";
  size_t _arg7341_size = 6;
  int _ret7339;
  _ret7339 = guestfs_write_append (g, _arg7340, _arg7341, _arg7341_size);
  if (_ret7339 == -1)
    return -1;
  const char *_arg7344 = "/write_append";
  const char *_arg7345 = "line3a";
  size_t _arg7345_size = 6;
  int _ret7343;
  _ret7343 = guestfs_write_append (g, _arg7344, _arg7345, _arg7345_size);
  if (_ret7343 == -1)
    return -1;
  const char *_arg7348 = "/write_append";
  const char *_arg7349 = "line3b\n";
  size_t _arg7349_size = 7;
  int _ret7347;
  _ret7347 = guestfs_write_append (g, _arg7348, _arg7349, _arg7349_size);
  if (_ret7347 == -1)
    return -1;
  const char *_arg7351 = "/write_append";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg7351);
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
test_write_0 (void)
{
  if (test_write_0_skip ()) {
    skipped ("test_write_0", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_write_0 */
  const char *_arg7354 = "/dev/sda";
  int _ret7353;
  _ret7353 = guestfs_blockdev_setrw (g, _arg7354);
  if (_ret7353 == -1)
    return -1;
  int _ret7356;
  _ret7356 = guestfs_umount_all (g);
  if (_ret7356 == -1)
    return -1;
  int _ret7358;
  _ret7358 = guestfs_lvm_remove_all (g);
  if (_ret7358 == -1)
    return -1;
  const char *_arg7361 = "/dev/sdb1";
  const char *_arg7362 = "/";
  int _ret7360;
  _ret7360 = guestfs_mount (g, _arg7361, _arg7362);
  if (_ret7360 == -1)
    return -1;

  /* TestResultString for write (0) */
  const char *_arg7365 = "/write";
  const char *_arg7366 = "new file contents";
  size_t _arg7366_size = 17;
  int _ret7364;
  _ret7364 = guestfs_write (g, _arg7365, _arg7366, _arg7366_size);
  if (_ret7364 == -1)
    return -1;
  const char *_arg7368 = "/write";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg7368);
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
test_write_1 (void)
{
  if (test_write_1_skip ()) {
    skipped ("test_write_1", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_write_1 */
  const char *_arg7371 = "/dev/sda";
  int _ret7370;
  _ret7370 = guestfs_blockdev_setrw (g, _arg7371);
  if (_ret7370 == -1)
    return -1;
  int _ret7373;
  _ret7373 = guestfs_umount_all (g);
  if (_ret7373 == -1)
    return -1;
  int _ret7375;
  _ret7375 = guestfs_lvm_remove_all (g);
  if (_ret7375 == -1)
    return -1;
  const char *_arg7378 = "/dev/sdb1";
  const char *_arg7379 = "/";
  int _ret7377;
  _ret7377 = guestfs_mount (g, _arg7378, _arg7379);
  if (_ret7377 == -1)
    return -1;

  /* TestResultString for write (1) */
  const char *_arg7382 = "/write2";
  const char *_arg7383 = "\nnew file contents\n";
  size_t _arg7383_size = 19;
  int _ret7381;
  _ret7381 = guestfs_write (g, _arg7382, _arg7383, _arg7383_size);
  if (_ret7381 == -1)
    return -1;
  const char *_arg7385 = "/write2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg7385);
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
test_write_2 (void)
{
  if (test_write_2_skip ()) {
    skipped ("test_write_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_write_2 */
  const char *_arg7388 = "/dev/sda";
  int _ret7387;
  _ret7387 = guestfs_blockdev_setrw (g, _arg7388);
  if (_ret7387 == -1)
    return -1;
  int _ret7390;
  _ret7390 = guestfs_umount_all (g);
  if (_ret7390 == -1)
    return -1;
  int _ret7392;
  _ret7392 = guestfs_lvm_remove_all (g);
  if (_ret7392 == -1)
    return -1;
  const char *_arg7395 = "/dev/sdb1";
  const char *_arg7396 = "/";
  int _ret7394;
  _ret7394 = guestfs_mount (g, _arg7395, _arg7396);
  if (_ret7394 == -1)
    return -1;

  /* TestResultString for write (2) */
  const char *_arg7399 = "/write3";
  const char *_arg7400 = "\n\n";
  size_t _arg7400_size = 2;
  int _ret7398;
  _ret7398 = guestfs_write (g, _arg7399, _arg7400, _arg7400_size);
  if (_ret7398 == -1)
    return -1;
  const char *_arg7402 = "/write3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg7402);
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
test_write_3 (void)
{
  if (test_write_3_skip ()) {
    skipped ("test_write_3", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_write_3 */
  const char *_arg7405 = "/dev/sda";
  int _ret7404;
  _ret7404 = guestfs_blockdev_setrw (g, _arg7405);
  if (_ret7404 == -1)
    return -1;
  int _ret7407;
  _ret7407 = guestfs_umount_all (g);
  if (_ret7407 == -1)
    return -1;
  int _ret7409;
  _ret7409 = guestfs_lvm_remove_all (g);
  if (_ret7409 == -1)
    return -1;
  const char *_arg7412 = "/dev/sdb1";
  const char *_arg7413 = "/";
  int _ret7411;
  _ret7411 = guestfs_mount (g, _arg7412, _arg7413);
  if (_ret7411 == -1)
    return -1;

  /* TestResultString for write (3) */
  const char *_arg7416 = "/write4";
  const char *_arg7417 = "";
  size_t _arg7417_size = 0;
  int _ret7415;
  _ret7415 = guestfs_write (g, _arg7416, _arg7417, _arg7417_size);
  if (_ret7415 == -1)
    return -1;
  const char *_arg7419 = "/write4";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg7419);
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
test_write_4 (void)
{
  if (test_write_4_skip ()) {
    skipped ("test_write_4", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_write_4 */
  const char *_arg7422 = "/dev/sda";
  int _ret7421;
  _ret7421 = guestfs_blockdev_setrw (g, _arg7422);
  if (_ret7421 == -1)
    return -1;
  int _ret7424;
  _ret7424 = guestfs_umount_all (g);
  if (_ret7424 == -1)
    return -1;
  int _ret7426;
  _ret7426 = guestfs_lvm_remove_all (g);
  if (_ret7426 == -1)
    return -1;
  const char *_arg7429 = "/dev/sdb1";
  const char *_arg7430 = "/";
  int _ret7428;
  _ret7428 = guestfs_mount (g, _arg7429, _arg7430);
  if (_ret7428 == -1)
    return -1;

  /* TestResultString for write (4) */
  const char *_arg7433 = "/write5";
  const char *_arg7434 = "\n\n\n";
  size_t _arg7434_size = 3;
  int _ret7432;
  _ret7432 = guestfs_write (g, _arg7433, _arg7434, _arg7434_size);
  if (_ret7432 == -1)
    return -1;
  const char *_arg7436 = "/write5";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg7436);
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
test_write_5 (void)
{
  if (test_write_5_skip ()) {
    skipped ("test_write_5", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_write_5 */
  const char *_arg7439 = "/dev/sda";
  int _ret7438;
  _ret7438 = guestfs_blockdev_setrw (g, _arg7439);
  if (_ret7438 == -1)
    return -1;
  int _ret7441;
  _ret7441 = guestfs_umount_all (g);
  if (_ret7441 == -1)
    return -1;
  int _ret7443;
  _ret7443 = guestfs_lvm_remove_all (g);
  if (_ret7443 == -1)
    return -1;
  const char *_arg7446 = "/dev/sdb1";
  const char *_arg7447 = "/";
  int _ret7445;
  _ret7445 = guestfs_mount (g, _arg7446, _arg7447);
  if (_ret7445 == -1)
    return -1;

  /* TestResultString for write (5) */
  const char *_arg7450 = "/write6";
  const char *_arg7451 = "\n";
  size_t _arg7451_size = 1;
  int _ret7449;
  _ret7449 = guestfs_write (g, _arg7450, _arg7451, _arg7451_size);
  if (_ret7449 == -1)
    return -1;
  const char *_arg7453 = "/write6";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg7453);
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
test_read_lines_0 (void)
{
  if (test_read_lines_0_skip ()) {
    skipped ("test_read_lines_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_read_lines_0 */
  const char *_arg7456 = "/dev/sda";
  int _ret7455;
  _ret7455 = guestfs_blockdev_setrw (g, _arg7456);
  if (_ret7455 == -1)
    return -1;
  int _ret7458;
  _ret7458 = guestfs_umount_all (g);
  if (_ret7458 == -1)
    return -1;
  int _ret7460;
  _ret7460 = guestfs_lvm_remove_all (g);
  if (_ret7460 == -1)
    return -1;
  const char *_arg7463 = "/dev/sdd";
  const char *_arg7464 = "/";
  int _ret7462;
  _ret7462 = guestfs_mount_ro (g, _arg7463, _arg7464);
  if (_ret7462 == -1)
    return -1;

  /* TestResult for read_lines (0) */
  const char *_arg7466 = "/known-4";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg7466);
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
test_read_lines_1 (void)
{
  if (test_read_lines_1_skip ()) {
    skipped ("test_read_lines_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_read_lines_1 */
  const char *_arg7469 = "/dev/sda";
  int _ret7468;
  _ret7468 = guestfs_blockdev_setrw (g, _arg7469);
  if (_ret7468 == -1)
    return -1;
  int _ret7471;
  _ret7471 = guestfs_umount_all (g);
  if (_ret7471 == -1)
    return -1;
  int _ret7473;
  _ret7473 = guestfs_lvm_remove_all (g);
  if (_ret7473 == -1)
    return -1;
  const char *_arg7476 = "/dev/sdd";
  const char *_arg7477 = "/";
  int _ret7475;
  _ret7475 = guestfs_mount_ro (g, _arg7476, _arg7477);
  if (_ret7475 == -1)
    return -1;

  /* TestResult for read_lines (1) */
  const char *_arg7479 = "/empty";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg7479);
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
test_read_lines_2 (void)
{
  if (test_read_lines_2_skip ()) {
    skipped ("test_read_lines_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_read_lines_2 */
  const char *_arg7482 = "/dev/sda";
  int _ret7481;
  _ret7481 = guestfs_blockdev_setrw (g, _arg7482);
  if (_ret7481 == -1)
    return -1;
  int _ret7484;
  _ret7484 = guestfs_umount_all (g);
  if (_ret7484 == -1)
    return -1;
  int _ret7486;
  _ret7486 = guestfs_lvm_remove_all (g);
  if (_ret7486 == -1)
    return -1;
  const char *_arg7489 = "/dev/sdb1";
  const char *_arg7490 = "/";
  int _ret7488;
  _ret7488 = guestfs_mount (g, _arg7489, _arg7490);
  if (_ret7488 == -1)
    return -1;

  /* TestResult for read_lines (2) */
  const char *_arg7492 = "/read_lines1";
  const char *_arg7493 = "\n";
  size_t _arg7493_size = 1;
  int ret1;
  ret1 = guestfs_write (g, _arg7492, _arg7493, _arg7493_size);
  if (ret1 == -1)
    return -1;
  const char *_arg7495 = "/read_lines1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg7495);
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
test_read_lines_3 (void)
{
  if (test_read_lines_3_skip ()) {
    skipped ("test_read_lines_3", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_read_lines_3 */
  const char *_arg7498 = "/dev/sda";
  int _ret7497;
  _ret7497 = guestfs_blockdev_setrw (g, _arg7498);
  if (_ret7497 == -1)
    return -1;
  int _ret7500;
  _ret7500 = guestfs_umount_all (g);
  if (_ret7500 == -1)
    return -1;
  int _ret7502;
  _ret7502 = guestfs_lvm_remove_all (g);
  if (_ret7502 == -1)
    return -1;
  const char *_arg7505 = "/dev/sdb1";
  const char *_arg7506 = "/";
  int _ret7504;
  _ret7504 = guestfs_mount (g, _arg7505, _arg7506);
  if (_ret7504 == -1)
    return -1;

  /* TestResult for read_lines (3) */
  const char *_arg7508 = "/read_lines2";
  const char *_arg7509 = "\r\n";
  size_t _arg7509_size = 2;
  int ret1;
  ret1 = guestfs_write (g, _arg7508, _arg7509, _arg7509_size);
  if (ret1 == -1)
    return -1;
  const char *_arg7511 = "/read_lines2";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg7511);
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
test_read_lines_4 (void)
{
  if (test_read_lines_4_skip ()) {
    skipped ("test_read_lines_4", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_read_lines_4 */
  const char *_arg7514 = "/dev/sda";
  int _ret7513;
  _ret7513 = guestfs_blockdev_setrw (g, _arg7514);
  if (_ret7513 == -1)
    return -1;
  int _ret7516;
  _ret7516 = guestfs_umount_all (g);
  if (_ret7516 == -1)
    return -1;
  int _ret7518;
  _ret7518 = guestfs_lvm_remove_all (g);
  if (_ret7518 == -1)
    return -1;
  const char *_arg7521 = "/dev/sdb1";
  const char *_arg7522 = "/";
  int _ret7520;
  _ret7520 = guestfs_mount (g, _arg7521, _arg7522);
  if (_ret7520 == -1)
    return -1;

  /* TestResult for read_lines (4) */
  const char *_arg7524 = "/read_lines3";
  const char *_arg7525 = "\n\r\n";
  size_t _arg7525_size = 3;
  int ret1;
  ret1 = guestfs_write (g, _arg7524, _arg7525, _arg7525_size);
  if (ret1 == -1)
    return -1;
  const char *_arg7527 = "/read_lines3";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg7527);
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
test_read_lines_5 (void)
{
  if (test_read_lines_5_skip ()) {
    skipped ("test_read_lines_5", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_read_lines_5 */
  const char *_arg7530 = "/dev/sda";
  int _ret7529;
  _ret7529 = guestfs_blockdev_setrw (g, _arg7530);
  if (_ret7529 == -1)
    return -1;
  int _ret7532;
  _ret7532 = guestfs_umount_all (g);
  if (_ret7532 == -1)
    return -1;
  int _ret7534;
  _ret7534 = guestfs_lvm_remove_all (g);
  if (_ret7534 == -1)
    return -1;
  const char *_arg7537 = "/dev/sdb1";
  const char *_arg7538 = "/";
  int _ret7536;
  _ret7536 = guestfs_mount (g, _arg7537, _arg7538);
  if (_ret7536 == -1)
    return -1;

  /* TestResult for read_lines (5) */
  const char *_arg7540 = "/read_lines4";
  const char *_arg7541 = "a";
  size_t _arg7541_size = 1;
  int ret1;
  ret1 = guestfs_write (g, _arg7540, _arg7541, _arg7541_size);
  if (ret1 == -1)
    return -1;
  const char *_arg7543 = "/read_lines4";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg7543);
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
test_read_lines_6 (void)
{
  if (test_read_lines_6_skip ()) {
    skipped ("test_read_lines_6", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_read_lines_6 */
  const char *_arg7546 = "/dev/sda";
  int _ret7545;
  _ret7545 = guestfs_blockdev_setrw (g, _arg7546);
  if (_ret7545 == -1)
    return -1;
  int _ret7548;
  _ret7548 = guestfs_umount_all (g);
  if (_ret7548 == -1)
    return -1;
  int _ret7550;
  _ret7550 = guestfs_lvm_remove_all (g);
  if (_ret7550 == -1)
    return -1;
  const char *_arg7553 = "/dev/sdb1";
  const char *_arg7554 = "/";
  int _ret7552;
  _ret7552 = guestfs_mount (g, _arg7553, _arg7554);
  if (_ret7552 == -1)
    return -1;

  /* TestResult for read_lines (6) */
  const char *_arg7556 = "/read_lines5";
  const char *_arg7557 = "a\nb";
  size_t _arg7557_size = 3;
  int ret1;
  ret1 = guestfs_write (g, _arg7556, _arg7557, _arg7557_size);
  if (ret1 == -1)
    return -1;
  const char *_arg7559 = "/read_lines5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg7559);
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
test_read_lines_7 (void)
{
  if (test_read_lines_7_skip ()) {
    skipped ("test_read_lines_7", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_read_lines_7 */
  const char *_arg7562 = "/dev/sda";
  int _ret7561;
  _ret7561 = guestfs_blockdev_setrw (g, _arg7562);
  if (_ret7561 == -1)
    return -1;
  int _ret7564;
  _ret7564 = guestfs_umount_all (g);
  if (_ret7564 == -1)
    return -1;
  int _ret7566;
  _ret7566 = guestfs_lvm_remove_all (g);
  if (_ret7566 == -1)
    return -1;
  const char *_arg7569 = "/dev/sdb1";
  const char *_arg7570 = "/";
  int _ret7568;
  _ret7568 = guestfs_mount (g, _arg7569, _arg7570);
  if (_ret7568 == -1)
    return -1;

  /* TestResult for read_lines (7) */
  const char *_arg7572 = "/read_lines6";
  const char *_arg7573 = "a\nb\n";
  size_t _arg7573_size = 4;
  int ret1;
  ret1 = guestfs_write (g, _arg7572, _arg7573, _arg7573_size);
  if (ret1 == -1)
    return -1;
  const char *_arg7575 = "/read_lines6";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg7575);
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
test_read_lines_8 (void)
{
  if (test_read_lines_8_skip ()) {
    skipped ("test_read_lines_8", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_read_lines_8 */
  const char *_arg7578 = "/dev/sda";
  int _ret7577;
  _ret7577 = guestfs_blockdev_setrw (g, _arg7578);
  if (_ret7577 == -1)
    return -1;
  int _ret7580;
  _ret7580 = guestfs_umount_all (g);
  if (_ret7580 == -1)
    return -1;
  int _ret7582;
  _ret7582 = guestfs_lvm_remove_all (g);
  if (_ret7582 == -1)
    return -1;
  const char *_arg7585 = "/dev/sdb1";
  const char *_arg7586 = "/";
  int _ret7584;
  _ret7584 = guestfs_mount (g, _arg7585, _arg7586);
  if (_ret7584 == -1)
    return -1;

  /* TestResult for read_lines (8) */
  const char *_arg7588 = "/read_lines7";
  const char *_arg7589 = "a\nb\r\n";
  size_t _arg7589_size = 5;
  int ret1;
  ret1 = guestfs_write (g, _arg7588, _arg7589, _arg7589_size);
  if (ret1 == -1)
    return -1;
  const char *_arg7591 = "/read_lines7";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg7591);
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
test_read_lines_9 (void)
{
  if (test_read_lines_9_skip ()) {
    skipped ("test_read_lines_9", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_read_lines_9 */
  const char *_arg7594 = "/dev/sda";
  int _ret7593;
  _ret7593 = guestfs_blockdev_setrw (g, _arg7594);
  if (_ret7593 == -1)
    return -1;
  int _ret7596;
  _ret7596 = guestfs_umount_all (g);
  if (_ret7596 == -1)
    return -1;
  int _ret7598;
  _ret7598 = guestfs_lvm_remove_all (g);
  if (_ret7598 == -1)
    return -1;
  const char *_arg7601 = "/dev/sdb1";
  const char *_arg7602 = "/";
  int _ret7600;
  _ret7600 = guestfs_mount (g, _arg7601, _arg7602);
  if (_ret7600 == -1)
    return -1;

  /* TestResult for read_lines (9) */
  const char *_arg7604 = "/read_lines8";
  const char *_arg7605 = "a\nb\r\n\n";
  size_t _arg7605_size = 6;
  int ret1;
  ret1 = guestfs_write (g, _arg7604, _arg7605, _arg7605_size);
  if (ret1 == -1)
    return -1;
  const char *_arg7607 = "/read_lines8";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, _arg7607);
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
test_read_file_0 (void)
{
  if (test_read_file_0_skip ()) {
    skipped ("test_read_file_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_read_file_0 */
  const char *_arg7610 = "/dev/sda";
  int _ret7609;
  _ret7609 = guestfs_blockdev_setrw (g, _arg7610);
  if (_ret7609 == -1)
    return -1;
  int _ret7612;
  _ret7612 = guestfs_umount_all (g);
  if (_ret7612 == -1)
    return -1;
  int _ret7614;
  _ret7614 = guestfs_lvm_remove_all (g);
  if (_ret7614 == -1)
    return -1;
  const char *_arg7617 = "/dev/sdd";
  const char *_arg7618 = "/";
  int _ret7616;
  _ret7616 = guestfs_mount_ro (g, _arg7617, _arg7618);
  if (_ret7616 == -1)
    return -1;

  /* TestResult for read_file (0) */
  const char *_arg7620 = "/known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, _arg7620, &size);
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
test_find_0 (void)
{
  if (test_find_0_skip ()) {
    skipped ("test_find_0", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_find_0: create ext2 on /dev/sda1 */
  const char *_arg7623 = "/dev/sda";
  int _ret7622;
  _ret7622 = guestfs_blockdev_setrw (g, _arg7623);
  if (_ret7622 == -1)
    return -1;
  int _ret7625;
  _ret7625 = guestfs_umount_all (g);
  if (_ret7625 == -1)
    return -1;
  int _ret7627;
  _ret7627 = guestfs_lvm_remove_all (g);
  if (_ret7627 == -1)
    return -1;
  const char *_arg7630 = "/dev/sda";
  const char *_arg7631 = "mbr";
  int _ret7629;
  _ret7629 = guestfs_part_disk (g, _arg7630, _arg7631);
  if (_ret7629 == -1)
    return -1;
  const char *_arg7634 = "ext2";
  const char *_arg7635 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs7636;
  _optargs7636.bitmask = UINT64_C(0x0);
  int _ret7633;
  _ret7633 = guestfs_mkfs_opts_argv (g, _arg7634, _arg7635, &_optargs7636);
  if (_ret7633 == -1)
    return -1;
  const char *_arg7638 = "/dev/sda1";
  const char *_arg7639 = "/";
  int _ret7637;
  _ret7637 = guestfs_mount (g, _arg7638, _arg7639);
  if (_ret7637 == -1)
    return -1;

  /* TestResult for find (0) */
  const char *_arg7641 = "/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, _arg7641);
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
test_find_1 (void)
{
  if (test_find_1_skip ()) {
    skipped ("test_find_1", "environment variable set");
    return 0;
  }

  /* InitBasicFS for test_find_1: create ext2 on /dev/sda1 */
  const char *_arg7644 = "/dev/sda";
  int _ret7643;
  _ret7643 = guestfs_blockdev_setrw (g, _arg7644);
  if (_ret7643 == -1)
    return -1;
  int _ret7646;
  _ret7646 = guestfs_umount_all (g);
  if (_ret7646 == -1)
    return -1;
  int _ret7648;
  _ret7648 = guestfs_lvm_remove_all (g);
  if (_ret7648 == -1)
    return -1;
  const char *_arg7651 = "/dev/sda";
  const char *_arg7652 = "mbr";
  int _ret7650;
  _ret7650 = guestfs_part_disk (g, _arg7651, _arg7652);
  if (_ret7650 == -1)
    return -1;
  const char *_arg7655 = "ext2";
  const char *_arg7656 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv _optargs7657;
  _optargs7657.bitmask = UINT64_C(0x0);
  int _ret7654;
  _ret7654 = guestfs_mkfs_opts_argv (g, _arg7655, _arg7656, &_optargs7657);
  if (_ret7654 == -1)
    return -1;
  const char *_arg7659 = "/dev/sda1";
  const char *_arg7660 = "/";
  int _ret7658;
  _ret7658 = guestfs_mount (g, _arg7659, _arg7660);
  if (_ret7658 == -1)
    return -1;

  /* TestResult for find (1) */
  const char *_arg7662 = "/a";
  int ret3;
  ret3 = guestfs_touch (g, _arg7662);
  if (ret3 == -1)
    return -1;
  const char *_arg7664 = "/b";
  int ret2;
  ret2 = guestfs_mkdir (g, _arg7664);
  if (ret2 == -1)
    return -1;
  const char *_arg7666 = "/b/c";
  int ret1;
  ret1 = guestfs_touch (g, _arg7666);
  if (ret1 == -1)
    return -1;
  const char *_arg7668 = "/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, _arg7668);
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
test_find_2 (void)
{
  if (test_find_2_skip ()) {
    skipped ("test_find_2", "environment variable set");
    return 0;
  }

  /* InitScratchFS for test_find_2 */
  const char *_arg7671 = "/dev/sda";
  int _ret7670;
  _ret7670 = guestfs_blockdev_setrw (g, _arg7671);
  if (_ret7670 == -1)
    return -1;
  int _ret7673;
  _ret7673 = guestfs_umount_all (g);
  if (_ret7673 == -1)
    return -1;
  int _ret7675;
  _ret7675 = guestfs_lvm_remove_all (g);
  if (_ret7675 == -1)
    return -1;
  const char *_arg7678 = "/dev/sdb1";
  const char *_arg7679 = "/";
  int _ret7677;
  _ret7677 = guestfs_mount (g, _arg7678, _arg7679);
  if (_ret7677 == -1)
    return -1;

  /* TestResult for find (2) */
  const char *_arg7681 = "/find/b/c";
  int ret2;
  ret2 = guestfs_mkdir_p (g, _arg7681);
  if (ret2 == -1)
    return -1;
  const char *_arg7683 = "/find/b/c/d";
  int ret1;
  ret1 = guestfs_touch (g, _arg7683);
  if (ret1 == -1)
    return -1;
  const char *_arg7685 = "/find/b/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, _arg7685);
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
test_cat_0 (void)
{
  if (test_cat_0_skip ()) {
    skipped ("test_cat_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_cat_0 */
  const char *_arg7688 = "/dev/sda";
  int _ret7687;
  _ret7687 = guestfs_blockdev_setrw (g, _arg7688);
  if (_ret7687 == -1)
    return -1;
  int _ret7690;
  _ret7690 = guestfs_umount_all (g);
  if (_ret7690 == -1)
    return -1;
  int _ret7692;
  _ret7692 = guestfs_lvm_remove_all (g);
  if (_ret7692 == -1)
    return -1;
  const char *_arg7695 = "/dev/sdd";
  const char *_arg7696 = "/";
  int _ret7694;
  _ret7694 = guestfs_mount_ro (g, _arg7695, _arg7696);
  if (_ret7694 == -1)
    return -1;

  /* TestResultString for cat (0) */
  const char *_arg7698 = "/known-2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, _arg7698);
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
test_get_backend_0 (void)
{
  if (test_get_backend_0_skip ()) {
    skipped ("test_get_backend_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_backend_0 */
  const char *_arg7701 = "/dev/sda";
  int _ret7700;
  _ret7700 = guestfs_blockdev_setrw (g, _arg7701);
  if (_ret7700 == -1)
    return -1;
  int _ret7703;
  _ret7703 = guestfs_umount_all (g);
  if (_ret7703 == -1)
    return -1;
  int _ret7705;
  _ret7705 = guestfs_lvm_remove_all (g);
  if (_ret7705 == -1)
    return -1;

  /* TestRun for get_backend (0) */
  CLEANUP_FREE char *_ret7707;
  _ret7707 = guestfs_get_backend (g);
  if (_ret7707 == NULL)
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
test_get_attach_method_0 (void)
{
  if (test_get_attach_method_0_skip ()) {
    skipped ("test_get_attach_method_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_attach_method_0 */
  const char *_arg7710 = "/dev/sda";
  int _ret7709;
  _ret7709 = guestfs_blockdev_setrw (g, _arg7710);
  if (_ret7709 == -1)
    return -1;
  int _ret7712;
  _ret7712 = guestfs_umount_all (g);
  if (_ret7712 == -1)
    return -1;
  int _ret7714;
  _ret7714 = guestfs_lvm_remove_all (g);
  if (_ret7714 == -1)
    return -1;

  /* TestRun for get_attach_method (0) */
  CLEANUP_FREE char *_ret7716;
  _ret7716 = guestfs_get_attach_method (g);
  if (_ret7716 == NULL)
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
test_file_architecture_0 (void)
{
  if (test_file_architecture_0_skip ()) {
    skipped ("test_file_architecture_0", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_architecture_0 */
  const char *_arg7719 = "/dev/sda";
  int _ret7718;
  _ret7718 = guestfs_blockdev_setrw (g, _arg7719);
  if (_ret7718 == -1)
    return -1;
  int _ret7721;
  _ret7721 = guestfs_umount_all (g);
  if (_ret7721 == -1)
    return -1;
  int _ret7723;
  _ret7723 = guestfs_lvm_remove_all (g);
  if (_ret7723 == -1)
    return -1;
  const char *_arg7726 = "/dev/sdd";
  const char *_arg7727 = "/";
  int _ret7725;
  _ret7725 = guestfs_mount_ro (g, _arg7726, _arg7727);
  if (_ret7725 == -1)
    return -1;

  /* TestResultString for file_architecture (0) */
  const char *_arg7729 = "/bin-i586-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg7729);
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
test_file_architecture_1 (void)
{
  if (test_file_architecture_1_skip ()) {
    skipped ("test_file_architecture_1", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_architecture_1 */
  const char *_arg7732 = "/dev/sda";
  int _ret7731;
  _ret7731 = guestfs_blockdev_setrw (g, _arg7732);
  if (_ret7731 == -1)
    return -1;
  int _ret7734;
  _ret7734 = guestfs_umount_all (g);
  if (_ret7734 == -1)
    return -1;
  int _ret7736;
  _ret7736 = guestfs_lvm_remove_all (g);
  if (_ret7736 == -1)
    return -1;
  const char *_arg7739 = "/dev/sdd";
  const char *_arg7740 = "/";
  int _ret7738;
  _ret7738 = guestfs_mount_ro (g, _arg7739, _arg7740);
  if (_ret7738 == -1)
    return -1;

  /* TestResultString for file_architecture (1) */
  const char *_arg7742 = "/bin-sparc-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg7742);
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
test_file_architecture_2 (void)
{
  if (test_file_architecture_2_skip ()) {
    skipped ("test_file_architecture_2", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_architecture_2 */
  const char *_arg7745 = "/dev/sda";
  int _ret7744;
  _ret7744 = guestfs_blockdev_setrw (g, _arg7745);
  if (_ret7744 == -1)
    return -1;
  int _ret7747;
  _ret7747 = guestfs_umount_all (g);
  if (_ret7747 == -1)
    return -1;
  int _ret7749;
  _ret7749 = guestfs_lvm_remove_all (g);
  if (_ret7749 == -1)
    return -1;
  const char *_arg7752 = "/dev/sdd";
  const char *_arg7753 = "/";
  int _ret7751;
  _ret7751 = guestfs_mount_ro (g, _arg7752, _arg7753);
  if (_ret7751 == -1)
    return -1;

  /* TestResultString for file_architecture (2) */
  const char *_arg7755 = "/bin-win32.exe";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg7755);
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
test_file_architecture_3 (void)
{
  if (test_file_architecture_3_skip ()) {
    skipped ("test_file_architecture_3", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_architecture_3 */
  const char *_arg7758 = "/dev/sda";
  int _ret7757;
  _ret7757 = guestfs_blockdev_setrw (g, _arg7758);
  if (_ret7757 == -1)
    return -1;
  int _ret7760;
  _ret7760 = guestfs_umount_all (g);
  if (_ret7760 == -1)
    return -1;
  int _ret7762;
  _ret7762 = guestfs_lvm_remove_all (g);
  if (_ret7762 == -1)
    return -1;
  const char *_arg7765 = "/dev/sdd";
  const char *_arg7766 = "/";
  int _ret7764;
  _ret7764 = guestfs_mount_ro (g, _arg7765, _arg7766);
  if (_ret7764 == -1)
    return -1;

  /* TestResultString for file_architecture (3) */
  const char *_arg7768 = "/bin-win64.exe";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg7768);
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
test_file_architecture_4 (void)
{
  if (test_file_architecture_4_skip ()) {
    skipped ("test_file_architecture_4", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_architecture_4 */
  const char *_arg7771 = "/dev/sda";
  int _ret7770;
  _ret7770 = guestfs_blockdev_setrw (g, _arg7771);
  if (_ret7770 == -1)
    return -1;
  int _ret7773;
  _ret7773 = guestfs_umount_all (g);
  if (_ret7773 == -1)
    return -1;
  int _ret7775;
  _ret7775 = guestfs_lvm_remove_all (g);
  if (_ret7775 == -1)
    return -1;
  const char *_arg7778 = "/dev/sdd";
  const char *_arg7779 = "/";
  int _ret7777;
  _ret7777 = guestfs_mount_ro (g, _arg7778, _arg7779);
  if (_ret7777 == -1)
    return -1;

  /* TestResultString for file_architecture (4) */
  const char *_arg7781 = "/bin-x86_64-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg7781);
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
test_file_architecture_5 (void)
{
  if (test_file_architecture_5_skip ()) {
    skipped ("test_file_architecture_5", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_architecture_5 */
  const char *_arg7784 = "/dev/sda";
  int _ret7783;
  _ret7783 = guestfs_blockdev_setrw (g, _arg7784);
  if (_ret7783 == -1)
    return -1;
  int _ret7786;
  _ret7786 = guestfs_umount_all (g);
  if (_ret7786 == -1)
    return -1;
  int _ret7788;
  _ret7788 = guestfs_lvm_remove_all (g);
  if (_ret7788 == -1)
    return -1;
  const char *_arg7791 = "/dev/sdd";
  const char *_arg7792 = "/";
  int _ret7790;
  _ret7790 = guestfs_mount_ro (g, _arg7791, _arg7792);
  if (_ret7790 == -1)
    return -1;

  /* TestResultString for file_architecture (5) */
  const char *_arg7794 = "/lib-i586.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg7794);
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
test_file_architecture_6 (void)
{
  if (test_file_architecture_6_skip ()) {
    skipped ("test_file_architecture_6", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_architecture_6 */
  const char *_arg7797 = "/dev/sda";
  int _ret7796;
  _ret7796 = guestfs_blockdev_setrw (g, _arg7797);
  if (_ret7796 == -1)
    return -1;
  int _ret7799;
  _ret7799 = guestfs_umount_all (g);
  if (_ret7799 == -1)
    return -1;
  int _ret7801;
  _ret7801 = guestfs_lvm_remove_all (g);
  if (_ret7801 == -1)
    return -1;
  const char *_arg7804 = "/dev/sdd";
  const char *_arg7805 = "/";
  int _ret7803;
  _ret7803 = guestfs_mount_ro (g, _arg7804, _arg7805);
  if (_ret7803 == -1)
    return -1;

  /* TestResultString for file_architecture (6) */
  const char *_arg7807 = "/lib-sparc.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg7807);
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
test_file_architecture_7 (void)
{
  if (test_file_architecture_7_skip ()) {
    skipped ("test_file_architecture_7", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_architecture_7 */
  const char *_arg7810 = "/dev/sda";
  int _ret7809;
  _ret7809 = guestfs_blockdev_setrw (g, _arg7810);
  if (_ret7809 == -1)
    return -1;
  int _ret7812;
  _ret7812 = guestfs_umount_all (g);
  if (_ret7812 == -1)
    return -1;
  int _ret7814;
  _ret7814 = guestfs_lvm_remove_all (g);
  if (_ret7814 == -1)
    return -1;
  const char *_arg7817 = "/dev/sdd";
  const char *_arg7818 = "/";
  int _ret7816;
  _ret7816 = guestfs_mount_ro (g, _arg7817, _arg7818);
  if (_ret7816 == -1)
    return -1;

  /* TestResultString for file_architecture (7) */
  const char *_arg7820 = "/lib-win32.dll";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg7820);
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
test_file_architecture_8 (void)
{
  if (test_file_architecture_8_skip ()) {
    skipped ("test_file_architecture_8", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_architecture_8 */
  const char *_arg7823 = "/dev/sda";
  int _ret7822;
  _ret7822 = guestfs_blockdev_setrw (g, _arg7823);
  if (_ret7822 == -1)
    return -1;
  int _ret7825;
  _ret7825 = guestfs_umount_all (g);
  if (_ret7825 == -1)
    return -1;
  int _ret7827;
  _ret7827 = guestfs_lvm_remove_all (g);
  if (_ret7827 == -1)
    return -1;
  const char *_arg7830 = "/dev/sdd";
  const char *_arg7831 = "/";
  int _ret7829;
  _ret7829 = guestfs_mount_ro (g, _arg7830, _arg7831);
  if (_ret7829 == -1)
    return -1;

  /* TestResultString for file_architecture (8) */
  const char *_arg7833 = "/lib-win64.dll";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg7833);
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
test_file_architecture_9 (void)
{
  if (test_file_architecture_9_skip ()) {
    skipped ("test_file_architecture_9", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_architecture_9 */
  const char *_arg7836 = "/dev/sda";
  int _ret7835;
  _ret7835 = guestfs_blockdev_setrw (g, _arg7836);
  if (_ret7835 == -1)
    return -1;
  int _ret7838;
  _ret7838 = guestfs_umount_all (g);
  if (_ret7838 == -1)
    return -1;
  int _ret7840;
  _ret7840 = guestfs_lvm_remove_all (g);
  if (_ret7840 == -1)
    return -1;
  const char *_arg7843 = "/dev/sdd";
  const char *_arg7844 = "/";
  int _ret7842;
  _ret7842 = guestfs_mount_ro (g, _arg7843, _arg7844);
  if (_ret7842 == -1)
    return -1;

  /* TestResultString for file_architecture (9) */
  const char *_arg7846 = "/lib-x86_64.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg7846);
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
test_file_architecture_10 (void)
{
  if (test_file_architecture_10_skip ()) {
    skipped ("test_file_architecture_10", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_architecture_10 */
  const char *_arg7849 = "/dev/sda";
  int _ret7848;
  _ret7848 = guestfs_blockdev_setrw (g, _arg7849);
  if (_ret7848 == -1)
    return -1;
  int _ret7851;
  _ret7851 = guestfs_umount_all (g);
  if (_ret7851 == -1)
    return -1;
  int _ret7853;
  _ret7853 = guestfs_lvm_remove_all (g);
  if (_ret7853 == -1)
    return -1;
  const char *_arg7856 = "/dev/sdd";
  const char *_arg7857 = "/";
  int _ret7855;
  _ret7855 = guestfs_mount_ro (g, _arg7856, _arg7857);
  if (_ret7855 == -1)
    return -1;

  /* TestResultString for file_architecture (10) */
  const char *_arg7859 = "/initrd-x86_64.img";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg7859);
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
test_file_architecture_11 (void)
{
  if (test_file_architecture_11_skip ()) {
    skipped ("test_file_architecture_11", "environment variable set");
    return 0;
  }

  /* InitISOFS for test_file_architecture_11 */
  const char *_arg7862 = "/dev/sda";
  int _ret7861;
  _ret7861 = guestfs_blockdev_setrw (g, _arg7862);
  if (_ret7861 == -1)
    return -1;
  int _ret7864;
  _ret7864 = guestfs_umount_all (g);
  if (_ret7864 == -1)
    return -1;
  int _ret7866;
  _ret7866 = guestfs_lvm_remove_all (g);
  if (_ret7866 == -1)
    return -1;
  const char *_arg7869 = "/dev/sdd";
  const char *_arg7870 = "/";
  int _ret7868;
  _ret7868 = guestfs_mount_ro (g, _arg7869, _arg7870);
  if (_ret7868 == -1)
    return -1;

  /* TestResultString for file_architecture (11) */
  const char *_arg7872 = "/initrd-x86_64.img.gz";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, _arg7872);
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
test_set_trace_0 (void)
{
  if (test_set_trace_0_skip ()) {
    skipped ("test_set_trace_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_set_trace_0 */
  const char *_arg7875 = "/dev/sda";
  int _ret7874;
  _ret7874 = guestfs_blockdev_setrw (g, _arg7875);
  if (_ret7874 == -1)
    return -1;
  int _ret7877;
  _ret7877 = guestfs_umount_all (g);
  if (_ret7877 == -1)
    return -1;
  int _ret7879;
  _ret7879 = guestfs_lvm_remove_all (g);
  if (_ret7879 == -1)
    return -1;

  /* TestResultFalse for set_trace (0) */
  int _ret7881;
  _ret7881 = guestfs_set_trace (g, 0);
  if (_ret7881 == -1)
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
test_version_0 (void)
{
  if (test_version_0_skip ()) {
    skipped ("test_version_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_version_0 */
  const char *_arg7886 = "/dev/sda";
  int _ret7885;
  _ret7885 = guestfs_blockdev_setrw (g, _arg7886);
  if (_ret7885 == -1)
    return -1;
  int _ret7888;
  _ret7888 = guestfs_umount_all (g);
  if (_ret7888 == -1)
    return -1;
  int _ret7890;
  _ret7890 = guestfs_lvm_remove_all (g);
  if (_ret7890 == -1)
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
test_get_memsize_0 (void)
{
  if (test_get_memsize_0_skip ()) {
    skipped ("test_get_memsize_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_memsize_0 */
  const char *_arg7894 = "/dev/sda";
  int _ret7893;
  _ret7893 = guestfs_blockdev_setrw (g, _arg7894);
  if (_ret7893 == -1)
    return -1;
  int _ret7896;
  _ret7896 = guestfs_umount_all (g);
  if (_ret7896 == -1)
    return -1;
  int _ret7898;
  _ret7898 = guestfs_lvm_remove_all (g);
  if (_ret7898 == -1)
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
test_is_busy_0 (void)
{
  if (test_is_busy_0_skip ()) {
    skipped ("test_is_busy_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_is_busy_0 */
  const char *_arg7902 = "/dev/sda";
  int _ret7901;
  _ret7901 = guestfs_blockdev_setrw (g, _arg7902);
  if (_ret7901 == -1)
    return -1;
  int _ret7904;
  _ret7904 = guestfs_umount_all (g);
  if (_ret7904 == -1)
    return -1;
  int _ret7906;
  _ret7906 = guestfs_lvm_remove_all (g);
  if (_ret7906 == -1)
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
test_is_launching_0 (void)
{
  if (test_is_launching_0_skip ()) {
    skipped ("test_is_launching_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_is_launching_0 */
  const char *_arg7910 = "/dev/sda";
  int _ret7909;
  _ret7909 = guestfs_blockdev_setrw (g, _arg7910);
  if (_ret7909 == -1)
    return -1;
  int _ret7912;
  _ret7912 = guestfs_umount_all (g);
  if (_ret7912 == -1)
    return -1;
  int _ret7914;
  _ret7914 = guestfs_lvm_remove_all (g);
  if (_ret7914 == -1)
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
test_is_config_0 (void)
{
  if (test_is_config_0_skip ()) {
    skipped ("test_is_config_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_is_config_0 */
  const char *_arg7918 = "/dev/sda";
  int _ret7917;
  _ret7917 = guestfs_blockdev_setrw (g, _arg7918);
  if (_ret7917 == -1)
    return -1;
  int _ret7920;
  _ret7920 = guestfs_umount_all (g);
  if (_ret7920 == -1)
    return -1;
  int _ret7922;
  _ret7922 = guestfs_lvm_remove_all (g);
  if (_ret7922 == -1)
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
test_is_ready_0 (void)
{
  if (test_is_ready_0_skip ()) {
    skipped ("test_is_ready_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_is_ready_0 */
  const char *_arg7926 = "/dev/sda";
  int _ret7925;
  _ret7925 = guestfs_blockdev_setrw (g, _arg7926);
  if (_ret7925 == -1)
    return -1;
  int _ret7928;
  _ret7928 = guestfs_umount_all (g);
  if (_ret7928 == -1)
    return -1;
  int _ret7930;
  _ret7930 = guestfs_lvm_remove_all (g);
  if (_ret7930 == -1)
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
test_get_autosync_0 (void)
{
  if (test_get_autosync_0_skip ()) {
    skipped ("test_get_autosync_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_autosync_0 */
  const char *_arg7934 = "/dev/sda";
  int _ret7933;
  _ret7933 = guestfs_blockdev_setrw (g, _arg7934);
  if (_ret7933 == -1)
    return -1;
  int _ret7936;
  _ret7936 = guestfs_umount_all (g);
  if (_ret7936 == -1)
    return -1;
  int _ret7938;
  _ret7938 = guestfs_lvm_remove_all (g);
  if (_ret7938 == -1)
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
test_get_path_0 (void)
{
  if (test_get_path_0_skip ()) {
    skipped ("test_get_path_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_path_0 */
  const char *_arg7942 = "/dev/sda";
  int _ret7941;
  _ret7941 = guestfs_blockdev_setrw (g, _arg7942);
  if (_ret7941 == -1)
    return -1;
  int _ret7944;
  _ret7944 = guestfs_umount_all (g);
  if (_ret7944 == -1)
    return -1;
  int _ret7946;
  _ret7946 = guestfs_lvm_remove_all (g);
  if (_ret7946 == -1)
    return -1;

  /* TestRun for get_path (0) */
  const char *_ret7948;
  _ret7948 = guestfs_get_path (g);
  if (_ret7948 == NULL)
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
test_get_qemu_0 (void)
{
  if (test_get_qemu_0_skip ()) {
    skipped ("test_get_qemu_0", "environment variable set");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_qemu_0 */
  const char *_arg7951 = "/dev/sda";
  int _ret7950;
  _ret7950 = guestfs_blockdev_setrw (g, _arg7951);
  if (_ret7950 == -1)
    return -1;
  int _ret7953;
  _ret7953 = guestfs_umount_all (g);
  if (_ret7953 == -1)
    return -1;
  int _ret7955;
  _ret7955 = guestfs_lvm_remove_all (g);
  if (_ret7955 == -1)
    return -1;

  /* TestRun for get_qemu (0) */
  const char *_ret7957;
  _ret7957 = guestfs_get_qemu (g);
  if (_ret7957 == NULL)
      return -1;
  return 0;
}

size_t nr_tests = 427;

size_t
perform_tests (void)
{
  size_t test_num = 0;
  size_t nr_failed = 0;

  test_num++;
  next_test (g, test_num, nr_tests, "test_feature_available_0");
  if (test_feature_available_0 () == -1) {
    printf ("FAIL: %s\n", "test_feature_available_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_whole_device_0");
  if (test_is_whole_device_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_whole_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_whole_device_1");
  if (test_is_whole_device_1 () == -1) {
    printf ("FAIL: %s\n", "test_is_whole_device_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_whole_device_2");
  if (test_is_whole_device_2 () == -1) {
    printf ("FAIL: %s\n", "test_is_whole_device_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rename_0");
  if (test_rename_0 () == -1) {
    printf ("FAIL: %s\n", "test_rename_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_get_gpt_type_0");
  if (test_part_get_gpt_type_0 () == -1) {
    printf ("FAIL: %s\n", "test_part_get_gpt_type_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_cap_set_file_0");
  if (test_cap_set_file_0 () == -1) {
    printf ("FAIL: %s\n", "test_cap_set_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_acl_delete_def_file_0");
  if (test_acl_delete_def_file_0 () == -1) {
    printf ("FAIL: %s\n", "test_acl_delete_def_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_acl_delete_def_file_1");
  if (test_acl_delete_def_file_1 () == -1) {
    printf ("FAIL: %s\n", "test_acl_delete_def_file_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_acl_set_file_0");
  if (test_acl_set_file_0 () == -1) {
    printf ("FAIL: %s\n", "test_acl_set_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mklost_and_found_0");
  if (test_mklost_and_found_0 () == -1) {
    printf ("FAIL: %s\n", "test_mklost_and_found_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mktemp_0");
  if (test_mktemp_0 () == -1) {
    printf ("FAIL: %s\n", "test_mktemp_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mke2fs_0");
  if (test_mke2fs_0 () == -1) {
    printf ("FAIL: %s\n", "test_mke2fs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mke2fs_1");
  if (test_mke2fs_1 () == -1) {
    printf ("FAIL: %s\n", "test_mke2fs_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mke2fs_2");
  if (test_mke2fs_2 () == -1) {
    printf ("FAIL: %s\n", "test_mke2fs_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rm_f_0");
  if (test_rm_f_0 () == -1) {
    printf ("FAIL: %s\n", "test_rm_f_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rm_f_1");
  if (test_rm_f_1 () == -1) {
    printf ("FAIL: %s\n", "test_rm_f_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_xfs_repair_0");
  if (test_xfs_repair_0 () == -1) {
    printf ("FAIL: %s\n", "test_xfs_repair_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_xfs_admin_0");
  if (test_xfs_admin_0 () == -1) {
    printf ("FAIL: %s\n", "test_xfs_admin_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_xfs_growfs_0");
  if (test_xfs_growfs_0 () == -1) {
    printf ("FAIL: %s\n", "test_xfs_growfs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utsname_0");
  if (test_utsname_0 () == -1) {
    printf ("FAIL: %s\n", "test_utsname_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgchange_uuid_all_0");
  if (test_vgchange_uuid_all_0 () == -1) {
    printf ("FAIL: %s\n", "test_vgchange_uuid_all_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgchange_uuid_0");
  if (test_vgchange_uuid_0 () == -1) {
    printf ("FAIL: %s\n", "test_vgchange_uuid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvchange_uuid_all_0");
  if (test_pvchange_uuid_all_0 () == -1) {
    printf ("FAIL: %s\n", "test_pvchange_uuid_all_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvchange_uuid_0");
  if (test_pvchange_uuid_0 () == -1) {
    printf ("FAIL: %s\n", "test_pvchange_uuid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_xfs_info_0");
  if (test_xfs_info_0 () == -1) {
    printf ("FAIL: %s\n", "test_xfs_info_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_nr_devices_0");
  if (test_nr_devices_0 () == -1) {
    printf ("FAIL: %s\n", "test_nr_devices_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_device_index_0");
  if (test_device_index_0 () == -1) {
    printf ("FAIL: %s\n", "test_device_index_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_btrfs_fsck_0");
  if (test_btrfs_fsck_0 () == -1) {
    printf ("FAIL: %s\n", "test_btrfs_fsck_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_btrfs_set_seeding_0");
  if (test_btrfs_set_seeding_0 () == -1) {
    printf ("FAIL: %s\n", "test_btrfs_set_seeding_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_btrfs_filesystem_sync_0");
  if (test_btrfs_filesystem_sync_0 () == -1) {
    printf ("FAIL: %s\n", "test_btrfs_filesystem_sync_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_btrfs_subvolume_delete_0");
  if (test_btrfs_subvolume_delete_0 () == -1) {
    printf ("FAIL: %s\n", "test_btrfs_subvolume_delete_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_btrfs_subvolume_snapshot_0");
  if (test_btrfs_subvolume_snapshot_0 () == -1) {
    printf ("FAIL: %s\n", "test_btrfs_subvolume_snapshot_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2generation_0");
  if (test_get_e2generation_0 () == -1) {
    printf ("FAIL: %s\n", "test_get_e2generation_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_0");
  if (test_get_e2attrs_0 () == -1) {
    printf ("FAIL: %s\n", "test_get_e2attrs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_1");
  if (test_get_e2attrs_1 () == -1) {
    printf ("FAIL: %s\n", "test_get_e2attrs_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_2");
  if (test_get_e2attrs_2 () == -1) {
    printf ("FAIL: %s\n", "test_get_e2attrs_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_3");
  if (test_get_e2attrs_3 () == -1) {
    printf ("FAIL: %s\n", "test_get_e2attrs_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_4");
  if (test_get_e2attrs_4 () == -1) {
    printf ("FAIL: %s\n", "test_get_e2attrs_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_5");
  if (test_get_e2attrs_5 () == -1) {
    printf ("FAIL: %s\n", "test_get_e2attrs_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_6");
  if (test_get_e2attrs_6 () == -1) {
    printf ("FAIL: %s\n", "test_get_e2attrs_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_7");
  if (test_get_e2attrs_7 () == -1) {
    printf ("FAIL: %s\n", "test_get_e2attrs_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_btrfs_0");
  if (test_mkfs_btrfs_0 () == -1) {
    printf ("FAIL: %s\n", "test_mkfs_btrfs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_isoinfo_device_0");
  if (test_isoinfo_device_0 () == -1) {
    printf ("FAIL: %s\n", "test_isoinfo_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvcreate_free_0");
  if (test_lvcreate_free_0 () == -1) {
    printf ("FAIL: %s\n", "test_lvcreate_free_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zero_free_space_0");
  if (test_zero_free_space_0 () == -1) {
    printf ("FAIL: %s\n", "test_zero_free_space_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_label_0");
  if (test_set_label_0 () == -1) {
    printf ("FAIL: %s\n", "test_set_label_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_label_1");
  if (test_set_label_1 () == -1) {
    printf ("FAIL: %s\n", "test_set_label_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_label_2");
  if (test_set_label_2 () == -1) {
    printf ("FAIL: %s\n", "test_set_label_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ntfsfix_0");
  if (test_ntfsfix_0 () == -1) {
    printf ("FAIL: %s\n", "test_ntfsfix_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_wipefs_0");
  if (test_wipefs_0 () == -1) {
    printf ("FAIL: %s\n", "test_wipefs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blkid_0");
  if (test_blkid_0 () == -1) {
    printf ("FAIL: %s\n", "test_blkid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tune2fs_0");
  if (test_tune2fs_0 () == -1) {
    printf ("FAIL: %s\n", "test_tune2fs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tune2fs_1");
  if (test_tune2fs_1 () == -1) {
    printf ("FAIL: %s\n", "test_tune2fs_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tune2fs_2");
  if (test_tune2fs_2 () == -1) {
    printf ("FAIL: %s\n", "test_tune2fs_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tune2fs_3");
  if (test_tune2fs_3 () == -1) {
    printf ("FAIL: %s\n", "test_tune2fs_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_copy_file_to_file_0");
  if (test_copy_file_to_file_0 () == -1) {
    printf ("FAIL: %s\n", "test_copy_file_to_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_copy_file_to_file_1");
  if (test_copy_file_to_file_1 () == -1) {
    printf ("FAIL: %s\n", "test_copy_file_to_file_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_to_partnum_0");
  if (test_part_to_partnum_0 () == -1) {
    printf ("FAIL: %s\n", "test_part_to_partnum_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_to_partnum_1");
  if (test_part_to_partnum_1 () == -1) {
    printf ("FAIL: %s\n", "test_part_to_partnum_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_append_0");
  if (test_internal_write_append_0 () == -1) {
    printf ("FAIL: %s\n", "test_internal_write_append_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_zero_device_0");
  if (test_is_zero_device_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_zero_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_zero_device_1");
  if (test_is_zero_device_1 () == -1) {
    printf ("FAIL: %s\n", "test_is_zero_device_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_zero_0");
  if (test_is_zero_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_zero_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_zero_1");
  if (test_is_zero_1 () == -1) {
    printf ("FAIL: %s\n", "test_is_zero_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_0");
  if (test_mkfs_0 () == -1) {
    printf ("FAIL: %s\n", "test_mkfs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvm_canonical_lv_name_0");
  if (test_lvm_canonical_lv_name_0 () == -1) {
    printf ("FAIL: %s\n", "test_lvm_canonical_lv_name_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvm_canonical_lv_name_1");
  if (test_lvm_canonical_lv_name_1 () == -1) {
    printf ("FAIL: %s\n", "test_lvm_canonical_lv_name_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pread_device_0");
  if (test_pread_device_0 () == -1) {
    printf ("FAIL: %s\n", "test_pread_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pwrite_device_0");
  if (test_pwrite_device_0 () == -1) {
    printf ("FAIL: %s\n", "test_pwrite_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_download_offset_0");
  if (test_download_offset_0 () == -1) {
    printf ("FAIL: %s\n", "test_download_offset_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_upload_offset_0");
  if (test_upload_offset_0 () == -1) {
    printf ("FAIL: %s\n", "test_upload_offset_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_to_dev_0");
  if (test_part_to_dev_0 () == -1) {
    printf ("FAIL: %s\n", "test_part_to_dev_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_to_dev_1");
  if (test_part_to_dev_1 () == -1) {
    printf ("FAIL: %s\n", "test_part_to_dev_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_socket_0");
  if (test_is_socket_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_socket_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_symlink_0");
  if (test_is_symlink_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_symlink_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_symlink_1");
  if (test_is_symlink_1 () == -1) {
    printf ("FAIL: %s\n", "test_is_symlink_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_fifo_0");
  if (test_is_fifo_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_fifo_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_fifo_1");
  if (test_is_fifo_1 () == -1) {
    printf ("FAIL: %s\n", "test_is_fifo_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_blockdev_0");
  if (test_is_blockdev_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_blockdev_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_blockdev_1");
  if (test_is_blockdev_1 () == -1) {
    printf ("FAIL: %s\n", "test_is_blockdev_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_chardev_0");
  if (test_is_chardev_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_chardev_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_chardev_1");
  if (test_is_chardev_1 () == -1) {
    printf ("FAIL: %s\n", "test_is_chardev_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_lv_0");
  if (test_is_lv_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_lv_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_lv_1");
  if (test_is_lv_1 () == -1) {
    printf ("FAIL: %s\n", "test_is_lv_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vfs_uuid_0");
  if (test_vfs_uuid_0 () == -1) {
    printf ("FAIL: %s\n", "test_vfs_uuid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vfs_label_0");
  if (test_vfs_label_0 () == -1) {
    printf ("FAIL: %s\n", "test_vfs_label_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fallocate64_0");
  if (test_fallocate64_0 () == -1) {
    printf ("FAIL: %s\n", "test_fallocate64_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_available_all_groups_0");
  if (test_available_all_groups_0 () == -1) {
    printf ("FAIL: %s\n", "test_available_all_groups_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pwrite_0");
  if (test_pwrite_0 () == -1) {
    printf ("FAIL: %s\n", "test_pwrite_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pwrite_1");
  if (test_pwrite_1 () == -1) {
    printf ("FAIL: %s\n", "test_pwrite_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pwrite_2");
  if (test_pwrite_2 () == -1) {
    printf ("FAIL: %s\n", "test_pwrite_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_0");
  if (test_internal_write_0 () == -1) {
    printf ("FAIL: %s\n", "test_internal_write_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_1");
  if (test_internal_write_1 () == -1) {
    printf ("FAIL: %s\n", "test_internal_write_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_2");
  if (test_internal_write_2 () == -1) {
    printf ("FAIL: %s\n", "test_internal_write_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_3");
  if (test_internal_write_3 () == -1) {
    printf ("FAIL: %s\n", "test_internal_write_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_4");
  if (test_internal_write_4 () == -1) {
    printf ("FAIL: %s\n", "test_internal_write_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_5");
  if (test_internal_write_5 () == -1) {
    printf ("FAIL: %s\n", "test_internal_write_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fill_pattern_0");
  if (test_fill_pattern_0 () == -1) {
    printf ("FAIL: %s\n", "test_fill_pattern_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_base64_in_0");
  if (test_base64_in_0 () == -1) {
    printf ("FAIL: %s\n", "test_base64_in_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_umask_0");
  if (test_get_umask_0 () == -1) {
    printf ("FAIL: %s\n", "test_get_umask_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvresize_free_0");
  if (test_lvresize_free_0 () == -1) {
    printf ("FAIL: %s\n", "test_lvresize_free_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_device_0");
  if (test_checksum_device_0 () == -1) {
    printf ("FAIL: %s\n", "test_checksum_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_get_mbr_id_0");
  if (test_part_get_mbr_id_0 () == -1) {
    printf ("FAIL: %s\n", "test_part_get_mbr_id_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_get_bootable_0");
  if (test_part_get_bootable_0 () == -1) {
    printf ("FAIL: %s\n", "test_part_get_bootable_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_del_0");
  if (test_part_del_0 () == -1) {
    printf ("FAIL: %s\n", "test_part_del_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgscan_0");
  if (test_vgscan_0 () == -1) {
    printf ("FAIL: %s\n", "test_vgscan_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_txz_in_0");
  if (test_txz_in_0 () == -1) {
    printf ("FAIL: %s\n", "test_txz_in_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zero_device_0");
  if (test_zero_device_0 () == -1) {
    printf ("FAIL: %s\n", "test_zero_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_copy_size_0");
  if (test_copy_size_0 () == -1) {
    printf ("FAIL: %s\n", "test_copy_size_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_initrd_cat_0");
  if (test_initrd_cat_0 () == -1) {
    printf ("FAIL: %s\n", "test_initrd_cat_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgrename_0");
  if (test_vgrename_0 () == -1) {
    printf ("FAIL: %s\n", "test_vgrename_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvrename_0");
  if (test_lvrename_0 () == -1) {
    printf ("FAIL: %s\n", "test_lvrename_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_filesize_0");
  if (test_filesize_0 () == -1) {
    printf ("FAIL: %s\n", "test_filesize_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_dd_0");
  if (test_dd_0 () == -1) {
    printf ("FAIL: %s\n", "test_dd_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_available_0");
  if (test_available_0 () == -1) {
    printf ("FAIL: %s\n", "test_available_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fill_0");
  if (test_fill_0 () == -1) {
    printf ("FAIL: %s\n", "test_fill_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_get_parttype_0");
  if (test_part_get_parttype_0 () == -1) {
    printf ("FAIL: %s\n", "test_part_get_parttype_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_set_name_0");
  if (test_part_set_name_0 () == -1) {
    printf ("FAIL: %s\n", "test_part_set_name_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_set_bootable_0");
  if (test_part_set_bootable_0 () == -1) {
    printf ("FAIL: %s\n", "test_part_set_bootable_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_disk_0");
  if (test_part_disk_0 () == -1) {
    printf ("FAIL: %s\n", "test_part_disk_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_disk_1");
  if (test_part_disk_1 () == -1) {
    printf ("FAIL: %s\n", "test_part_disk_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_add_0");
  if (test_part_add_0 () == -1) {
    printf ("FAIL: %s\n", "test_part_add_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_add_1");
  if (test_part_add_1 () == -1) {
    printf ("FAIL: %s\n", "test_part_add_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_add_2");
  if (test_part_add_2 () == -1) {
    printf ("FAIL: %s\n", "test_part_add_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_init_0");
  if (test_part_init_0 () == -1) {
    printf ("FAIL: %s\n", "test_part_init_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pread_0");
  if (test_pread_0 () == -1) {
    printf ("FAIL: %s\n", "test_pread_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pread_1");
  if (test_pread_1 () == -1) {
    printf ("FAIL: %s\n", "test_pread_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_mode_0");
  if (test_mkdir_mode_0 () == -1) {
    printf ("FAIL: %s\n", "test_mkdir_mode_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utimens_0");
  if (test_utimens_0 () == -1) {
    printf ("FAIL: %s\n", "test_utimens_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utimens_1");
  if (test_utimens_1 () == -1) {
    printf ("FAIL: %s\n", "test_utimens_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utimens_2");
  if (test_utimens_2 () == -1) {
    printf ("FAIL: %s\n", "test_utimens_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utimens_3");
  if (test_utimens_3 () == -1) {
    printf ("FAIL: %s\n", "test_utimens_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utimens_4");
  if (test_utimens_4 () == -1) {
    printf ("FAIL: %s\n", "test_utimens_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utimens_5");
  if (test_utimens_5 () == -1) {
    printf ("FAIL: %s\n", "test_utimens_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_truncate_size_0");
  if (test_truncate_size_0 () == -1) {
    printf ("FAIL: %s\n", "test_truncate_size_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_truncate_0");
  if (test_truncate_0 () == -1) {
    printf ("FAIL: %s\n", "test_truncate_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vfs_type_0");
  if (test_vfs_type_0 () == -1) {
    printf ("FAIL: %s\n", "test_vfs_type_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_0");
  if (test_case_sensitive_path_0 () == -1) {
    printf ("FAIL: %s\n", "test_case_sensitive_path_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_1");
  if (test_case_sensitive_path_1 () == -1) {
    printf ("FAIL: %s\n", "test_case_sensitive_path_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_2");
  if (test_case_sensitive_path_2 () == -1) {
    printf ("FAIL: %s\n", "test_case_sensitive_path_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_3");
  if (test_case_sensitive_path_3 () == -1) {
    printf ("FAIL: %s\n", "test_case_sensitive_path_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_4");
  if (test_case_sensitive_path_4 () == -1) {
    printf ("FAIL: %s\n", "test_case_sensitive_path_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_5");
  if (test_case_sensitive_path_5 () == -1) {
    printf ("FAIL: %s\n", "test_case_sensitive_path_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_6");
  if (test_case_sensitive_path_6 () == -1) {
    printf ("FAIL: %s\n", "test_case_sensitive_path_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_7");
  if (test_case_sensitive_path_7 () == -1) {
    printf ("FAIL: %s\n", "test_case_sensitive_path_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_echo_daemon_0");
  if (test_echo_daemon_0 () == -1) {
    printf ("FAIL: %s\n", "test_echo_daemon_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_modprobe_0");
  if (test_modprobe_0 () == -1) {
    printf ("FAIL: %s\n", "test_modprobe_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mke2journal_U_0");
  if (test_mke2journal_U_0 () == -1) {
    printf ("FAIL: %s\n", "test_mke2journal_U_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mke2journal_L_0");
  if (test_mke2journal_L_0 () == -1) {
    printf ("FAIL: %s\n", "test_mke2journal_L_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mke2journal_0");
  if (test_mke2journal_0 () == -1) {
    printf ("FAIL: %s\n", "test_mke2journal_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_b_0");
  if (test_mkfs_b_0 () == -1) {
    printf ("FAIL: %s\n", "test_mkfs_b_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_b_1");
  if (test_mkfs_b_1 () == -1) {
    printf ("FAIL: %s\n", "test_mkfs_b_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_b_2");
  if (test_mkfs_b_2 () == -1) {
    printf ("FAIL: %s\n", "test_mkfs_b_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_b_3");
  if (test_mkfs_b_3 () == -1) {
    printf ("FAIL: %s\n", "test_mkfs_b_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_b_4");
  if (test_mkfs_b_4 () == -1) {
    printf ("FAIL: %s\n", "test_mkfs_b_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_inotify_add_watch_0");
  if (test_inotify_add_watch_0 () == -1) {
    printf ("FAIL: %s\n", "test_inotify_add_watch_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_inotify_init_0");
  if (test_inotify_init_0 () == -1) {
    printf ("FAIL: %s\n", "test_inotify_init_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_file_0");
  if (test_mkswap_file_0 () == -1) {
    printf ("FAIL: %s\n", "test_mkswap_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_swapon_uuid_0");
  if (test_swapon_uuid_0 () == -1) {
    printf ("FAIL: %s\n", "test_swapon_uuid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_swapon_label_0");
  if (test_swapon_label_0 () == -1) {
    printf ("FAIL: %s\n", "test_swapon_label_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_swapon_file_0");
  if (test_swapon_file_0 () == -1) {
    printf ("FAIL: %s\n", "test_swapon_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_swapon_device_0");
  if (test_swapon_device_0 () == -1) {
    printf ("FAIL: %s\n", "test_swapon_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fallocate_0");
  if (test_fallocate_0 () == -1) {
    printf ("FAIL: %s\n", "test_fallocate_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ln_sf_0");
  if (test_ln_sf_0 () == -1) {
    printf ("FAIL: %s\n", "test_ln_sf_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ln_s_0");
  if (test_ln_s_0 () == -1) {
    printf ("FAIL: %s\n", "test_ln_s_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ln_f_0");
  if (test_ln_f_0 () == -1) {
    printf ("FAIL: %s\n", "test_ln_f_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ln_0");
  if (test_ln_0 () == -1) {
    printf ("FAIL: %s\n", "test_ln_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_realpath_0");
  if (test_realpath_0 () == -1) {
    printf ("FAIL: %s\n", "test_realpath_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zfgrepi_0");
  if (test_zfgrepi_0 () == -1) {
    printf ("FAIL: %s\n", "test_zfgrepi_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zegrepi_0");
  if (test_zegrepi_0 () == -1) {
    printf ("FAIL: %s\n", "test_zegrepi_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zgrepi_0");
  if (test_zgrepi_0 () == -1) {
    printf ("FAIL: %s\n", "test_zgrepi_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zfgrep_0");
  if (test_zfgrep_0 () == -1) {
    printf ("FAIL: %s\n", "test_zfgrep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zegrep_0");
  if (test_zegrep_0 () == -1) {
    printf ("FAIL: %s\n", "test_zegrep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zgrep_0");
  if (test_zgrep_0 () == -1) {
    printf ("FAIL: %s\n", "test_zgrep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fgrepi_0");
  if (test_fgrepi_0 () == -1) {
    printf ("FAIL: %s\n", "test_fgrepi_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_egrepi_0");
  if (test_egrepi_0 () == -1) {
    printf ("FAIL: %s\n", "test_egrepi_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grepi_0");
  if (test_grepi_0 () == -1) {
    printf ("FAIL: %s\n", "test_grepi_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fgrep_0");
  if (test_fgrep_0 () == -1) {
    printf ("FAIL: %s\n", "test_fgrep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_egrep_0");
  if (test_egrep_0 () == -1) {
    printf ("FAIL: %s\n", "test_egrep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_0");
  if (test_grep_0 () == -1) {
    printf ("FAIL: %s\n", "test_grep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_1");
  if (test_grep_1 () == -1) {
    printf ("FAIL: %s\n", "test_grep_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_2");
  if (test_grep_2 () == -1) {
    printf ("FAIL: %s\n", "test_grep_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_3");
  if (test_grep_3 () == -1) {
    printf ("FAIL: %s\n", "test_grep_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_4");
  if (test_grep_4 () == -1) {
    printf ("FAIL: %s\n", "test_grep_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_5");
  if (test_grep_5 () == -1) {
    printf ("FAIL: %s\n", "test_grep_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_6");
  if (test_grep_6 () == -1) {
    printf ("FAIL: %s\n", "test_grep_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_7");
  if (test_grep_7 () == -1) {
    printf ("FAIL: %s\n", "test_grep_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_8");
  if (test_grep_8 () == -1) {
    printf ("FAIL: %s\n", "test_grep_8");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_9");
  if (test_grep_9 () == -1) {
    printf ("FAIL: %s\n", "test_grep_9");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_10");
  if (test_grep_10 () == -1) {
    printf ("FAIL: %s\n", "test_grep_10");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_11");
  if (test_grep_11 () == -1) {
    printf ("FAIL: %s\n", "test_grep_11");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_12");
  if (test_grep_12 () == -1) {
    printf ("FAIL: %s\n", "test_grep_12");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_13");
  if (test_grep_13 () == -1) {
    printf ("FAIL: %s\n", "test_grep_13");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_umask_0");
  if (test_umask_0 () == -1) {
    printf ("FAIL: %s\n", "test_umask_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mknod_c_0");
  if (test_mknod_c_0 () == -1) {
    printf ("FAIL: %s\n", "test_mknod_c_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mknod_b_0");
  if (test_mknod_b_0 () == -1) {
    printf ("FAIL: %s\n", "test_mknod_b_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfifo_0");
  if (test_mkfifo_0 () == -1) {
    printf ("FAIL: %s\n", "test_mkfifo_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mknod_0");
  if (test_mknod_0 () == -1) {
    printf ("FAIL: %s\n", "test_mknod_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mknod_1");
  if (test_mknod_1 () == -1) {
    printf ("FAIL: %s\n", "test_mknod_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_U_0");
  if (test_mkswap_U_0 () == -1) {
    printf ("FAIL: %s\n", "test_mkswap_U_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_L_0");
  if (test_mkswap_L_0 () == -1) {
    printf ("FAIL: %s\n", "test_mkswap_L_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_0");
  if (test_mkswap_0 () == -1) {
    printf ("FAIL: %s\n", "test_mkswap_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_1");
  if (test_mkswap_1 () == -1) {
    printf ("FAIL: %s\n", "test_mkswap_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_2");
  if (test_mkswap_2 () == -1) {
    printf ("FAIL: %s\n", "test_mkswap_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_3");
  if (test_mkswap_3 () == -1) {
    printf ("FAIL: %s\n", "test_mkswap_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_initrd_list_0");
  if (test_initrd_list_0 () == -1) {
    printf ("FAIL: %s\n", "test_initrd_list_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_du_0");
  if (test_du_0 () == -1) {
    printf ("FAIL: %s\n", "test_du_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tail_n_0");
  if (test_tail_n_0 () == -1) {
    printf ("FAIL: %s\n", "test_tail_n_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tail_n_1");
  if (test_tail_n_1 () == -1) {
    printf ("FAIL: %s\n", "test_tail_n_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tail_n_2");
  if (test_tail_n_2 () == -1) {
    printf ("FAIL: %s\n", "test_tail_n_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tail_0");
  if (test_tail_0 () == -1) {
    printf ("FAIL: %s\n", "test_tail_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_head_n_0");
  if (test_head_n_0 () == -1) {
    printf ("FAIL: %s\n", "test_head_n_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_head_n_1");
  if (test_head_n_1 () == -1) {
    printf ("FAIL: %s\n", "test_head_n_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_head_n_2");
  if (test_head_n_2 () == -1) {
    printf ("FAIL: %s\n", "test_head_n_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_head_0");
  if (test_head_0 () == -1) {
    printf ("FAIL: %s\n", "test_head_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_head_1");
  if (test_head_1 () == -1) {
    printf ("FAIL: %s\n", "test_head_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_wc_c_0");
  if (test_wc_c_0 () == -1) {
    printf ("FAIL: %s\n", "test_wc_c_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_wc_w_0");
  if (test_wc_w_0 () == -1) {
    printf ("FAIL: %s\n", "test_wc_w_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_wc_l_0");
  if (test_wc_l_0 () == -1) {
    printf ("FAIL: %s\n", "test_wc_l_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_wc_l_1");
  if (test_wc_l_1 () == -1) {
    printf ("FAIL: %s\n", "test_wc_l_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdtemp_0");
  if (test_mkdtemp_0 () == -1) {
    printf ("FAIL: %s\n", "test_mkdtemp_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_scrub_file_0");
  if (test_scrub_file_0 () == -1) {
    printf ("FAIL: %s\n", "test_scrub_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_scrub_device_0");
  if (test_scrub_device_0 () == -1) {
    printf ("FAIL: %s\n", "test_scrub_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_glob_expand_0");
  if (test_glob_expand_0 () == -1) {
    printf ("FAIL: %s\n", "test_glob_expand_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_glob_expand_1");
  if (test_glob_expand_1 () == -1) {
    printf ("FAIL: %s\n", "test_glob_expand_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_glob_expand_2");
  if (test_glob_expand_2 () == -1) {
    printf ("FAIL: %s\n", "test_glob_expand_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ntfs_3g_probe_0");
  if (test_ntfs_3g_probe_0 () == -1) {
    printf ("FAIL: %s\n", "test_ntfs_3g_probe_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ntfs_3g_probe_1");
  if (test_ntfs_3g_probe_1 () == -1) {
    printf ("FAIL: %s\n", "test_ntfs_3g_probe_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_sleep_0");
  if (test_sleep_0 () == -1) {
    printf ("FAIL: %s\n", "test_sleep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvresize_0");
  if (test_lvresize_0 () == -1) {
    printf ("FAIL: %s\n", "test_lvresize_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvresize_1");
  if (test_lvresize_1 () == -1) {
    printf ("FAIL: %s\n", "test_lvresize_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zerofree_0");
  if (test_zerofree_0 () == -1) {
    printf ("FAIL: %s\n", "test_zerofree_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_hexdump_0");
  if (test_hexdump_0 () == -1) {
    printf ("FAIL: %s\n", "test_hexdump_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_hexdump_1");
  if (test_hexdump_1 () == -1) {
    printf ("FAIL: %s\n", "test_hexdump_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_hexdump_2");
  if (test_hexdump_2 () == -1) {
    printf ("FAIL: %s\n", "test_hexdump_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_strings_e_0");
  if (test_strings_e_0 () == -1) {
    printf ("FAIL: %s\n", "test_strings_e_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_strings_e_1");
  if (test_strings_e_1 () == -1) {
    printf ("FAIL: %s\n", "test_strings_e_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_strings_0");
  if (test_strings_0 () == -1) {
    printf ("FAIL: %s\n", "test_strings_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_strings_1");
  if (test_strings_1 () == -1) {
    printf ("FAIL: %s\n", "test_strings_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_strings_2");
  if (test_strings_2 () == -1) {
    printf ("FAIL: %s\n", "test_strings_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_equal_0");
  if (test_equal_0 () == -1) {
    printf ("FAIL: %s\n", "test_equal_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_equal_1");
  if (test_equal_1 () == -1) {
    printf ("FAIL: %s\n", "test_equal_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_equal_2");
  if (test_equal_2 () == -1) {
    printf ("FAIL: %s\n", "test_equal_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ping_daemon_0");
  if (test_ping_daemon_0 () == -1) {
    printf ("FAIL: %s\n", "test_ping_daemon_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_dmesg_0");
  if (test_dmesg_0 () == -1) {
    printf ("FAIL: %s\n", "test_dmesg_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_drop_caches_0");
  if (test_drop_caches_0 () == -1) {
    printf ("FAIL: %s\n", "test_drop_caches_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mv_0");
  if (test_mv_0 () == -1) {
    printf ("FAIL: %s\n", "test_mv_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mv_1");
  if (test_mv_1 () == -1) {
    printf ("FAIL: %s\n", "test_mv_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_cp_a_0");
  if (test_cp_a_0 () == -1) {
    printf ("FAIL: %s\n", "test_cp_a_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_cp_0");
  if (test_cp_0 () == -1) {
    printf ("FAIL: %s\n", "test_cp_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_cp_1");
  if (test_cp_1 () == -1) {
    printf ("FAIL: %s\n", "test_cp_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_cp_2");
  if (test_cp_2 () == -1) {
    printf ("FAIL: %s\n", "test_cp_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grub_install_0");
  if (test_grub_install_0 () == -1) {
    printf ("FAIL: %s\n", "test_grub_install_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zero_0");
  if (test_zero_0 () == -1) {
    printf ("FAIL: %s\n", "test_zero_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fsck_0");
  if (test_fsck_0 () == -1) {
    printf ("FAIL: %s\n", "test_fsck_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fsck_1");
  if (test_fsck_1 () == -1) {
    printf ("FAIL: %s\n", "test_fsck_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2uuid_0");
  if (test_get_e2uuid_0 () == -1) {
    printf ("FAIL: %s\n", "test_get_e2uuid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_e2uuid_0");
  if (test_set_e2uuid_0 () == -1) {
    printf ("FAIL: %s\n", "test_set_e2uuid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_e2uuid_1");
  if (test_set_e2uuid_1 () == -1) {
    printf ("FAIL: %s\n", "test_set_e2uuid_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_e2uuid_2");
  if (test_set_e2uuid_2 () == -1) {
    printf ("FAIL: %s\n", "test_set_e2uuid_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_e2uuid_3");
  if (test_set_e2uuid_3 () == -1) {
    printf ("FAIL: %s\n", "test_set_e2uuid_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_e2label_0");
  if (test_set_e2label_0 () == -1) {
    printf ("FAIL: %s\n", "test_set_e2label_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvremove_0");
  if (test_pvremove_0 () == -1) {
    printf ("FAIL: %s\n", "test_pvremove_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvremove_1");
  if (test_pvremove_1 () == -1) {
    printf ("FAIL: %s\n", "test_pvremove_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvremove_2");
  if (test_pvremove_2 () == -1) {
    printf ("FAIL: %s\n", "test_pvremove_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgremove_0");
  if (test_vgremove_0 () == -1) {
    printf ("FAIL: %s\n", "test_vgremove_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgremove_1");
  if (test_vgremove_1 () == -1) {
    printf ("FAIL: %s\n", "test_vgremove_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvremove_0");
  if (test_lvremove_0 () == -1) {
    printf ("FAIL: %s\n", "test_lvremove_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvremove_1");
  if (test_lvremove_1 () == -1) {
    printf ("FAIL: %s\n", "test_lvremove_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvremove_2");
  if (test_lvremove_2 () == -1) {
    printf ("FAIL: %s\n", "test_lvremove_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mount_ro_0");
  if (test_mount_ro_0 () == -1) {
    printf ("FAIL: %s\n", "test_mount_ro_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mount_ro_1");
  if (test_mount_ro_1 () == -1) {
    printf ("FAIL: %s\n", "test_mount_ro_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tgz_in_0");
  if (test_tgz_in_0 () == -1) {
    printf ("FAIL: %s\n", "test_tgz_in_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tar_in_0");
  if (test_tar_in_0 () == -1) {
    printf ("FAIL: %s\n", "test_tar_in_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tar_in_1");
  if (test_tar_in_1 () == -1) {
    printf ("FAIL: %s\n", "test_tar_in_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tar_in_2");
  if (test_tar_in_2 () == -1) {
    printf ("FAIL: %s\n", "test_tar_in_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_0");
  if (test_checksum_0 () == -1) {
    printf ("FAIL: %s\n", "test_checksum_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_1");
  if (test_checksum_1 () == -1) {
    printf ("FAIL: %s\n", "test_checksum_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_2");
  if (test_checksum_2 () == -1) {
    printf ("FAIL: %s\n", "test_checksum_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_3");
  if (test_checksum_3 () == -1) {
    printf ("FAIL: %s\n", "test_checksum_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_4");
  if (test_checksum_4 () == -1) {
    printf ("FAIL: %s\n", "test_checksum_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_5");
  if (test_checksum_5 () == -1) {
    printf ("FAIL: %s\n", "test_checksum_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_6");
  if (test_checksum_6 () == -1) {
    printf ("FAIL: %s\n", "test_checksum_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_7");
  if (test_checksum_7 () == -1) {
    printf ("FAIL: %s\n", "test_checksum_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_8");
  if (test_checksum_8 () == -1) {
    printf ("FAIL: %s\n", "test_checksum_8");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_download_0");
  if (test_download_0 () == -1) {
    printf ("FAIL: %s\n", "test_download_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_upload_0");
  if (test_upload_0 () == -1) {
    printf ("FAIL: %s\n", "test_upload_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_rereadpt_0");
  if (test_blockdev_rereadpt_0 () == -1) {
    printf ("FAIL: %s\n", "test_blockdev_rereadpt_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_flushbufs_0");
  if (test_blockdev_flushbufs_0 () == -1) {
    printf ("FAIL: %s\n", "test_blockdev_flushbufs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_getsize64_0");
  if (test_blockdev_getsize64_0 () == -1) {
    printf ("FAIL: %s\n", "test_blockdev_getsize64_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_getsz_0");
  if (test_blockdev_getsz_0 () == -1) {
    printf ("FAIL: %s\n", "test_blockdev_getsz_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_getss_0");
  if (test_blockdev_getss_0 () == -1) {
    printf ("FAIL: %s\n", "test_blockdev_getss_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_getro_0");
  if (test_blockdev_getro_0 () == -1) {
    printf ("FAIL: %s\n", "test_blockdev_getro_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_setrw_0");
  if (test_blockdev_setrw_0 () == -1) {
    printf ("FAIL: %s\n", "test_blockdev_setrw_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_setro_0");
  if (test_blockdev_setro_0 () == -1) {
    printf ("FAIL: %s\n", "test_blockdev_setro_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tune2fs_l_0");
  if (test_tune2fs_l_0 () == -1) {
    printf ("FAIL: %s\n", "test_tune2fs_l_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_statvfs_0");
  if (test_statvfs_0 () == -1) {
    printf ("FAIL: %s\n", "test_statvfs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lstat_0");
  if (test_lstat_0 () == -1) {
    printf ("FAIL: %s\n", "test_lstat_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_stat_0");
  if (test_stat_0 () == -1) {
    printf ("FAIL: %s\n", "test_stat_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_0");
  if (test_command_lines_0 () == -1) {
    printf ("FAIL: %s\n", "test_command_lines_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_1");
  if (test_command_lines_1 () == -1) {
    printf ("FAIL: %s\n", "test_command_lines_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_2");
  if (test_command_lines_2 () == -1) {
    printf ("FAIL: %s\n", "test_command_lines_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_3");
  if (test_command_lines_3 () == -1) {
    printf ("FAIL: %s\n", "test_command_lines_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_4");
  if (test_command_lines_4 () == -1) {
    printf ("FAIL: %s\n", "test_command_lines_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_5");
  if (test_command_lines_5 () == -1) {
    printf ("FAIL: %s\n", "test_command_lines_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_6");
  if (test_command_lines_6 () == -1) {
    printf ("FAIL: %s\n", "test_command_lines_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_7");
  if (test_command_lines_7 () == -1) {
    printf ("FAIL: %s\n", "test_command_lines_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_8");
  if (test_command_lines_8 () == -1) {
    printf ("FAIL: %s\n", "test_command_lines_8");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_9");
  if (test_command_lines_9 () == -1) {
    printf ("FAIL: %s\n", "test_command_lines_9");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_10");
  if (test_command_lines_10 () == -1) {
    printf ("FAIL: %s\n", "test_command_lines_10");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_0");
  if (test_command_0 () == -1) {
    printf ("FAIL: %s\n", "test_command_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_1");
  if (test_command_1 () == -1) {
    printf ("FAIL: %s\n", "test_command_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_2");
  if (test_command_2 () == -1) {
    printf ("FAIL: %s\n", "test_command_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_3");
  if (test_command_3 () == -1) {
    printf ("FAIL: %s\n", "test_command_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_4");
  if (test_command_4 () == -1) {
    printf ("FAIL: %s\n", "test_command_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_5");
  if (test_command_5 () == -1) {
    printf ("FAIL: %s\n", "test_command_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_6");
  if (test_command_6 () == -1) {
    printf ("FAIL: %s\n", "test_command_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_7");
  if (test_command_7 () == -1) {
    printf ("FAIL: %s\n", "test_command_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_8");
  if (test_command_8 () == -1) {
    printf ("FAIL: %s\n", "test_command_8");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_9");
  if (test_command_9 () == -1) {
    printf ("FAIL: %s\n", "test_command_9");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_10");
  if (test_command_10 () == -1) {
    printf ("FAIL: %s\n", "test_command_10");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_11");
  if (test_command_11 () == -1) {
    printf ("FAIL: %s\n", "test_command_11");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_12");
  if (test_command_12 () == -1) {
    printf ("FAIL: %s\n", "test_command_12");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_0");
  if (test_file_0 () == -1) {
    printf ("FAIL: %s\n", "test_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_1");
  if (test_file_1 () == -1) {
    printf ("FAIL: %s\n", "test_file_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_2");
  if (test_file_2 () == -1) {
    printf ("FAIL: %s\n", "test_file_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_3");
  if (test_file_3 () == -1) {
    printf ("FAIL: %s\n", "test_file_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_4");
  if (test_file_4 () == -1) {
    printf ("FAIL: %s\n", "test_file_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_umount_all_0");
  if (test_umount_all_0 () == -1) {
    printf ("FAIL: %s\n", "test_umount_all_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_umount_all_1");
  if (test_umount_all_1 () == -1) {
    printf ("FAIL: %s\n", "test_umount_all_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mounts_0");
  if (test_mounts_0 () == -1) {
    printf ("FAIL: %s\n", "test_mounts_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_umount_0");
  if (test_umount_0 () == -1) {
    printf ("FAIL: %s\n", "test_umount_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_umount_1");
  if (test_umount_1 () == -1) {
    printf ("FAIL: %s\n", "test_umount_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_file_0");
  if (test_write_file_0 () == -1) {
    printf ("FAIL: %s\n", "test_write_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvcreate_0");
  if (test_lvcreate_0 () == -1) {
    printf ("FAIL: %s\n", "test_lvcreate_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgcreate_0");
  if (test_vgcreate_0 () == -1) {
    printf ("FAIL: %s\n", "test_vgcreate_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvcreate_0");
  if (test_pvcreate_0 () == -1) {
    printf ("FAIL: %s\n", "test_pvcreate_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_dir_0");
  if (test_is_dir_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_dir_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_dir_1");
  if (test_is_dir_1 () == -1) {
    printf ("FAIL: %s\n", "test_is_dir_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_file_0");
  if (test_is_file_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_file_1");
  if (test_is_file_1 () == -1) {
    printf ("FAIL: %s\n", "test_is_file_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_exists_0");
  if (test_exists_0 () == -1) {
    printf ("FAIL: %s\n", "test_exists_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_exists_1");
  if (test_exists_1 () == -1) {
    printf ("FAIL: %s\n", "test_exists_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_p_0");
  if (test_mkdir_p_0 () == -1) {
    printf ("FAIL: %s\n", "test_mkdir_p_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_p_1");
  if (test_mkdir_p_1 () == -1) {
    printf ("FAIL: %s\n", "test_mkdir_p_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_p_2");
  if (test_mkdir_p_2 () == -1) {
    printf ("FAIL: %s\n", "test_mkdir_p_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_p_3");
  if (test_mkdir_p_3 () == -1) {
    printf ("FAIL: %s\n", "test_mkdir_p_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_p_4");
  if (test_mkdir_p_4 () == -1) {
    printf ("FAIL: %s\n", "test_mkdir_p_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_0");
  if (test_mkdir_0 () == -1) {
    printf ("FAIL: %s\n", "test_mkdir_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_1");
  if (test_mkdir_1 () == -1) {
    printf ("FAIL: %s\n", "test_mkdir_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rm_rf_0");
  if (test_rm_rf_0 () == -1) {
    printf ("FAIL: %s\n", "test_rm_rf_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rmdir_0");
  if (test_rmdir_0 () == -1) {
    printf ("FAIL: %s\n", "test_rmdir_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rmdir_1");
  if (test_rmdir_1 () == -1) {
    printf ("FAIL: %s\n", "test_rmdir_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rmdir_2");
  if (test_rmdir_2 () == -1) {
    printf ("FAIL: %s\n", "test_rmdir_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rm_0");
  if (test_rm_0 () == -1) {
    printf ("FAIL: %s\n", "test_rm_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rm_1");
  if (test_rm_1 () == -1) {
    printf ("FAIL: %s\n", "test_rm_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rm_2");
  if (test_rm_2 () == -1) {
    printf ("FAIL: %s\n", "test_rm_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvs_0");
  if (test_lvs_0 () == -1) {
    printf ("FAIL: %s\n", "test_lvs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvs_1");
  if (test_lvs_1 () == -1) {
    printf ("FAIL: %s\n", "test_lvs_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgs_0");
  if (test_vgs_0 () == -1) {
    printf ("FAIL: %s\n", "test_vgs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgs_1");
  if (test_vgs_1 () == -1) {
    printf ("FAIL: %s\n", "test_vgs_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvs_0");
  if (test_pvs_0 () == -1) {
    printf ("FAIL: %s\n", "test_pvs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvs_1");
  if (test_pvs_1 () == -1) {
    printf ("FAIL: %s\n", "test_pvs_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_list_partitions_0");
  if (test_list_partitions_0 () == -1) {
    printf ("FAIL: %s\n", "test_list_partitions_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_list_partitions_1");
  if (test_list_partitions_1 () == -1) {
    printf ("FAIL: %s\n", "test_list_partitions_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_list_devices_0");
  if (test_list_devices_0 () == -1) {
    printf ("FAIL: %s\n", "test_list_devices_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_touch_0");
  if (test_touch_0 () == -1) {
    printf ("FAIL: %s\n", "test_touch_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_sync_0");
  if (test_sync_0 () == -1) {
    printf ("FAIL: %s\n", "test_sync_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mount_0");
  if (test_mount_0 () == -1) {
    printf ("FAIL: %s\n", "test_mount_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_program_0");
  if (test_get_program_0 () == -1) {
    printf ("FAIL: %s\n", "test_get_program_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_has_backing_file_0");
  if (test_disk_has_backing_file_0 () == -1) {
    printf ("FAIL: %s\n", "test_disk_has_backing_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_has_backing_file_1");
  if (test_disk_has_backing_file_1 () == -1) {
    printf ("FAIL: %s\n", "test_disk_has_backing_file_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_has_backing_file_2");
  if (test_disk_has_backing_file_2 () == -1) {
    printf ("FAIL: %s\n", "test_disk_has_backing_file_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_virtual_size_0");
  if (test_disk_virtual_size_0 () == -1) {
    printf ("FAIL: %s\n", "test_disk_virtual_size_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_virtual_size_1");
  if (test_disk_virtual_size_1 () == -1) {
    printf ("FAIL: %s\n", "test_disk_virtual_size_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_virtual_size_2");
  if (test_disk_virtual_size_2 () == -1) {
    printf ("FAIL: %s\n", "test_disk_virtual_size_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_format_0");
  if (test_disk_format_0 () == -1) {
    printf ("FAIL: %s\n", "test_disk_format_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_format_1");
  if (test_disk_format_1 () == -1) {
    printf ("FAIL: %s\n", "test_disk_format_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_format_2");
  if (test_disk_format_2 () == -1) {
    printf ("FAIL: %s\n", "test_disk_format_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ls_0");
  if (test_ls_0 () == -1) {
    printf ("FAIL: %s\n", "test_ls_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_append_0");
  if (test_write_append_0 () == -1) {
    printf ("FAIL: %s\n", "test_write_append_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_0");
  if (test_write_0 () == -1) {
    printf ("FAIL: %s\n", "test_write_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_1");
  if (test_write_1 () == -1) {
    printf ("FAIL: %s\n", "test_write_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_2");
  if (test_write_2 () == -1) {
    printf ("FAIL: %s\n", "test_write_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_3");
  if (test_write_3 () == -1) {
    printf ("FAIL: %s\n", "test_write_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_4");
  if (test_write_4 () == -1) {
    printf ("FAIL: %s\n", "test_write_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_5");
  if (test_write_5 () == -1) {
    printf ("FAIL: %s\n", "test_write_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_0");
  if (test_read_lines_0 () == -1) {
    printf ("FAIL: %s\n", "test_read_lines_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_1");
  if (test_read_lines_1 () == -1) {
    printf ("FAIL: %s\n", "test_read_lines_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_2");
  if (test_read_lines_2 () == -1) {
    printf ("FAIL: %s\n", "test_read_lines_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_3");
  if (test_read_lines_3 () == -1) {
    printf ("FAIL: %s\n", "test_read_lines_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_4");
  if (test_read_lines_4 () == -1) {
    printf ("FAIL: %s\n", "test_read_lines_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_5");
  if (test_read_lines_5 () == -1) {
    printf ("FAIL: %s\n", "test_read_lines_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_6");
  if (test_read_lines_6 () == -1) {
    printf ("FAIL: %s\n", "test_read_lines_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_7");
  if (test_read_lines_7 () == -1) {
    printf ("FAIL: %s\n", "test_read_lines_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_8");
  if (test_read_lines_8 () == -1) {
    printf ("FAIL: %s\n", "test_read_lines_8");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_9");
  if (test_read_lines_9 () == -1) {
    printf ("FAIL: %s\n", "test_read_lines_9");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_file_0");
  if (test_read_file_0 () == -1) {
    printf ("FAIL: %s\n", "test_read_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_find_0");
  if (test_find_0 () == -1) {
    printf ("FAIL: %s\n", "test_find_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_find_1");
  if (test_find_1 () == -1) {
    printf ("FAIL: %s\n", "test_find_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_find_2");
  if (test_find_2 () == -1) {
    printf ("FAIL: %s\n", "test_find_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_cat_0");
  if (test_cat_0 () == -1) {
    printf ("FAIL: %s\n", "test_cat_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_backend_0");
  if (test_get_backend_0 () == -1) {
    printf ("FAIL: %s\n", "test_get_backend_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_attach_method_0");
  if (test_get_attach_method_0 () == -1) {
    printf ("FAIL: %s\n", "test_get_attach_method_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_0");
  if (test_file_architecture_0 () == -1) {
    printf ("FAIL: %s\n", "test_file_architecture_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_1");
  if (test_file_architecture_1 () == -1) {
    printf ("FAIL: %s\n", "test_file_architecture_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_2");
  if (test_file_architecture_2 () == -1) {
    printf ("FAIL: %s\n", "test_file_architecture_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_3");
  if (test_file_architecture_3 () == -1) {
    printf ("FAIL: %s\n", "test_file_architecture_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_4");
  if (test_file_architecture_4 () == -1) {
    printf ("FAIL: %s\n", "test_file_architecture_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_5");
  if (test_file_architecture_5 () == -1) {
    printf ("FAIL: %s\n", "test_file_architecture_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_6");
  if (test_file_architecture_6 () == -1) {
    printf ("FAIL: %s\n", "test_file_architecture_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_7");
  if (test_file_architecture_7 () == -1) {
    printf ("FAIL: %s\n", "test_file_architecture_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_8");
  if (test_file_architecture_8 () == -1) {
    printf ("FAIL: %s\n", "test_file_architecture_8");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_9");
  if (test_file_architecture_9 () == -1) {
    printf ("FAIL: %s\n", "test_file_architecture_9");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_10");
  if (test_file_architecture_10 () == -1) {
    printf ("FAIL: %s\n", "test_file_architecture_10");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_11");
  if (test_file_architecture_11 () == -1) {
    printf ("FAIL: %s\n", "test_file_architecture_11");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_trace_0");
  if (test_set_trace_0 () == -1) {
    printf ("FAIL: %s\n", "test_set_trace_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_version_0");
  if (test_version_0 () == -1) {
    printf ("FAIL: %s\n", "test_version_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_memsize_0");
  if (test_get_memsize_0 () == -1) {
    printf ("FAIL: %s\n", "test_get_memsize_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_busy_0");
  if (test_is_busy_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_busy_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_launching_0");
  if (test_is_launching_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_launching_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_config_0");
  if (test_is_config_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_config_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_ready_0");
  if (test_is_ready_0 () == -1) {
    printf ("FAIL: %s\n", "test_is_ready_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_autosync_0");
  if (test_get_autosync_0 () == -1) {
    printf ("FAIL: %s\n", "test_get_autosync_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_path_0");
  if (test_get_path_0 () == -1) {
    printf ("FAIL: %s\n", "test_get_path_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_qemu_0");
  if (test_get_qemu_0 () == -1) {
    printf ("FAIL: %s\n", "test_get_qemu_0");
    nr_failed++;
  }

  return nr_failed;
}
