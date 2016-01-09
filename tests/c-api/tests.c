/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2016 Red Hat Inc.
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

#ifdef __linux__
#define GUESTFS_ISO_SYSTEM_ID "LINUX"
#else
#error Missing GUESTFS_ISO_SYSTEM_ID for the current OS
#endif

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
    "add_drive_scratch",
    "add_drive_with_if",
    "add_libvirt_dom",
    "aug_defnode",
    "aug_defvar",
    "aug_load",
    "aug_match",
    "aug_mv",
    "aug_rm",
    "base64_out",
    "blkdiscard",
    "blkdiscardzeroes",
    "blockdev_getbsz",
    "blockdev_setbsz",
    "btrfs_balance_cancel",
    "btrfs_balance_pause",
    "btrfs_balance_resume",
    "btrfs_balance_status",
    "btrfs_device_add",
    "btrfs_device_delete",
    "btrfs_filesystem_resize",
    "btrfs_replace",
    "btrfs_scrub_cancel",
    "btrfs_scrub_resume",
    "btrfs_subvolume_list",
    "btrfs_subvolume_set_default",
    "canonical_device_name",
    "checksums_out",
    "chown",
    "clear_backend_setting",
    "compress_device_out",
    "compress_out",
    "config",
    "copy_attributes",
    "copy_device_to_device",
    "copy_device_to_file",
    "copy_file_to_device",
    "copy_in",
    "copy_out",
    "cpio_out",
    "debug",
    "debug_drives",
    "debug_upload",
    "df",
    "df_h",
    "disk_create",
    "extlinux",
    "filesystem_available",
    "fill_dir",
    "find0",
    "findfs_label",
    "findfs_uuid",
    "fstrim",
    "get_append",
    "get_backend_setting",
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
    "hivex_node_add_child",
    "hivex_node_delete_child",
    "hivex_node_get_child",
    "hivex_node_get_value",
    "hivex_node_parent",
    "hivex_node_set_value",
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
    "internal_exit",
    "internal_feature_available",
    "internal_hot_add_drive",
    "internal_hot_remove_drive",
    "internal_hot_remove_drive_precheck",
    "internal_journal_get",
    "internal_lstatnslist",
    "internal_lxattrlist",
    "internal_parse_mountable",
    "internal_readlinklist",
    "internal_rhbz914931",
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
    "internal_upload",
    "isoinfo",
    "journal_close",
    "journal_get",
    "journal_get_data_threshold",
    "journal_get_realtime_usec",
    "journal_next",
    "journal_open",
    "journal_set_data_threshold",
    "journal_skip",
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
    "lstatnslist",
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
    "part_get_name",
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
    "set_backend_setting",
    "set_backend_settings",
    "set_cachedir",
    "set_direct",
    "set_hv",
    "set_identifier",
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

static int test_vfs_minimum_size_0_skip (void);
static int test_vfs_minimum_size_0_perform (guestfs_h *);

static int
test_vfs_minimum_size_0 (guestfs_h *g)
{
  if (test_vfs_minimum_size_0_skip ()) {
    skipped ("test_vfs_minimum_size_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_vfs_minimum_size_0_perform (g);
}

static int
test_vfs_minimum_size_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vfs_minimum_size") == NULL;
  str = getenv ("SKIP_TEST_VFS_MINIMUM_SIZE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VFS_MINIMUM_SIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vfs_minimum_size_0_perform (guestfs_h *g)
{
  /* TestRun for vfs_minimum_size (0) */
  const char *arg2 = "/dev/sda1";
  int64_t ret1;
  ret1 = guestfs_vfs_minimum_size (g, arg2);
  if (ret1 == -1)
    return -1;
  return 0;
}

static int test_vfs_minimum_size_1_skip (void);
static int test_vfs_minimum_size_1_perform (guestfs_h *);

static int
test_vfs_minimum_size_1 (guestfs_h *g)
{
  if (test_vfs_minimum_size_1_skip ()) {
    skipped ("test_vfs_minimum_size_1", "environment variable set");
    return 0;
  }

  const char *features4[] = { "ntfsprogs", NULL };
  if (!guestfs_feature_available (g, (char **) features4)) {
    skipped ("test_vfs_minimum_size_1", "group %s not available in daemon",
             features4[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_vfs_minimum_size_1_perform (g);
}

static int
test_vfs_minimum_size_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vfs_minimum_size") == NULL;
  str = getenv ("SKIP_TEST_VFS_MINIMUM_SIZE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VFS_MINIMUM_SIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vfs_minimum_size_1_perform (guestfs_h *g)
{
  /* TestRun for vfs_minimum_size (1) */
  const char *arg6 = "ntfs";
  const char *arg7 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs8;
  optargs8.bitmask = UINT64_C(0x0);
  int ret5;
  ret5 = guestfs_mkfs_opts_argv (g, arg6, arg7, &optargs8);
  if (ret5 == -1)
    return -1;
  const char *arg10 = "/dev/sda1";
  int64_t ret9;
  ret9 = guestfs_vfs_minimum_size (g, arg10);
  if (ret9 == -1)
    return -1;
  return 0;
}

static int test_vfs_minimum_size_2_skip (void);
static int test_vfs_minimum_size_2_perform (guestfs_h *);

static int
test_vfs_minimum_size_2 (guestfs_h *g)
{
  if (test_vfs_minimum_size_2_skip ()) {
    skipped ("test_vfs_minimum_size_2", "environment variable set");
    return 0;
  }

  const char *features12[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features12)) {
    skipped ("test_vfs_minimum_size_2", "group %s not available in daemon",
             features12[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_vfs_minimum_size_2_perform (g);
}

static int
test_vfs_minimum_size_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vfs_minimum_size") == NULL;
  str = getenv ("SKIP_TEST_VFS_MINIMUM_SIZE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VFS_MINIMUM_SIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vfs_minimum_size_2_perform (guestfs_h *g)
{
  /* TestRun for vfs_minimum_size (2) */
  const char *arg14 = "btrfs";
  const char *arg15 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs16;
  optargs16.bitmask = UINT64_C(0x0);
  int ret13;
  ret13 = guestfs_mkfs_opts_argv (g, arg14, arg15, &optargs16);
  if (ret13 == -1)
    return -1;
  const char *arg18 = "/dev/sda1";
  const char *arg19 = "/";
  int ret17;
  ret17 = guestfs_mount (g, arg18, arg19);
  if (ret17 == -1)
    return -1;
  const char *arg22 = "/dev/sda1";
  int64_t ret21;
  ret21 = guestfs_vfs_minimum_size (g, arg22);
  if (ret21 == -1)
    return -1;
  return 0;
}

static int test_vfs_minimum_size_3_skip (void);
static int test_vfs_minimum_size_3_perform (guestfs_h *);

static int
test_vfs_minimum_size_3 (guestfs_h *g)
{
  if (test_vfs_minimum_size_3_skip ()) {
    skipped ("test_vfs_minimum_size_3", "environment variable set");
    return 0;
  }

  const char *features24[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) features24)) {
    skipped ("test_vfs_minimum_size_3", "group %s not available in daemon",
             features24[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_vfs_minimum_size_3_perform (g);
}

static int
test_vfs_minimum_size_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vfs_minimum_size") == NULL;
  str = getenv ("SKIP_TEST_VFS_MINIMUM_SIZE_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VFS_MINIMUM_SIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vfs_minimum_size_3_perform (guestfs_h *g)
{
  /* TestRun for vfs_minimum_size (3) */
  const char *arg26 = "xfs";
  const char *arg27 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs28;
  optargs28.bitmask = UINT64_C(0x0);
  int ret25;
  ret25 = guestfs_mkfs_opts_argv (g, arg26, arg27, &optargs28);
  if (ret25 == -1)
    return -1;
  const char *arg30 = "/dev/sda1";
  const char *arg31 = "/";
  int ret29;
  ret29 = guestfs_mount (g, arg30, arg31);
  if (ret29 == -1)
    return -1;
  const char *arg34 = "/dev/sda1";
  int64_t ret33;
  ret33 = guestfs_vfs_minimum_size (g, arg34);
  if (ret33 == -1)
    return -1;
  return 0;
}

static int test_set_uuid_random_0_skip (void);
static int test_set_uuid_random_0_perform (guestfs_h *);

static int
test_set_uuid_random_0 (guestfs_h *g)
{
  if (test_set_uuid_random_0_skip ()) {
    skipped ("test_set_uuid_random_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_set_uuid_random_0_perform (g);
}

static int
test_set_uuid_random_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_uuid_random") == NULL;
  str = getenv ("SKIP_TEST_SET_UUID_RANDOM_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_UUID_RANDOM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_set_uuid_random_0_perform (guestfs_h *g)
{
  /* TestRun for set_uuid_random (0) */
  const char *arg37 = "/dev/sda1";
  int ret36;
  ret36 = guestfs_set_uuid_random (g, arg37);
  if (ret36 == -1)
    return -1;
  return 0;
}

static int test_part_get_mbr_part_type_0_skip (void);
static int test_part_get_mbr_part_type_0_perform (guestfs_h *);

static int
test_part_get_mbr_part_type_0 (guestfs_h *g)
{
  if (test_part_get_mbr_part_type_0_skip ()) {
    skipped ("test_part_get_mbr_part_type_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_get_mbr_part_type_0_perform (g);
}

static int
test_part_get_mbr_part_type_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_get_mbr_part_type") == NULL;
  str = getenv ("SKIP_TEST_PART_GET_MBR_PART_TYPE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_GET_MBR_PART_TYPE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_get_mbr_part_type_0_perform (guestfs_h *g)
{
  /* TestResultString for part_get_mbr_part_type (0) */
  const char *arg40 = "/dev/sda";
  const char *arg41 = "mbr";
  int ret39;
  ret39 = guestfs_part_init (g, arg40, arg41);
  if (ret39 == -1)
    return -1;
  const char *arg44 = "/dev/sda";
  const char *arg45 = "p";
  int ret43;
  ret43 = guestfs_part_add (g, arg44, arg45, 64, 204799);
  if (ret43 == -1)
    return -1;
  const char *arg50 = "/dev/sda";
  const char *arg51 = "e";
  int ret49;
  ret49 = guestfs_part_add (g, arg50, arg51, 204800, 614400);
  if (ret49 == -1)
    return -1;
  const char *arg56 = "/dev/sda";
  const char *arg57 = "l";
  int ret55;
  ret55 = guestfs_part_add (g, arg56, arg57, 204864, 205988);
  if (ret55 == -1)
    return -1;
  const char *arg61 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_mbr_part_type (g, arg61, 5);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "logical")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_part_get_mbr_part_type_0", "part_get_mbr_part_type", "logical", ret);
    return -1;
  }
  return 0;
}

static int test_part_get_mbr_part_type_1_skip (void);
static int test_part_get_mbr_part_type_1_perform (guestfs_h *);

static int
test_part_get_mbr_part_type_1 (guestfs_h *g)
{
  if (test_part_get_mbr_part_type_1_skip ()) {
    skipped ("test_part_get_mbr_part_type_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_get_mbr_part_type_1_perform (g);
}

static int
test_part_get_mbr_part_type_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_get_mbr_part_type") == NULL;
  str = getenv ("SKIP_TEST_PART_GET_MBR_PART_TYPE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_GET_MBR_PART_TYPE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_get_mbr_part_type_1_perform (guestfs_h *g)
{
  /* TestResultString for part_get_mbr_part_type (1) */
  const char *arg65 = "/dev/sda";
  const char *arg66 = "mbr";
  int ret64;
  ret64 = guestfs_part_init (g, arg65, arg66);
  if (ret64 == -1)
    return -1;
  const char *arg69 = "/dev/sda";
  const char *arg70 = "p";
  int ret68;
  ret68 = guestfs_part_add (g, arg69, arg70, 64, 204799);
  if (ret68 == -1)
    return -1;
  const char *arg75 = "/dev/sda";
  const char *arg76 = "e";
  int ret74;
  ret74 = guestfs_part_add (g, arg75, arg76, 204800, 614400);
  if (ret74 == -1)
    return -1;
  const char *arg81 = "/dev/sda";
  const char *arg82 = "l";
  int ret80;
  ret80 = guestfs_part_add (g, arg81, arg82, 204864, 205988);
  if (ret80 == -1)
    return -1;
  const char *arg86 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_mbr_part_type (g, arg86, 2);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "extended")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_part_get_mbr_part_type_1", "part_get_mbr_part_type", "extended", ret);
    return -1;
  }
  return 0;
}

static int test_btrfs_image_0_skip (void);
static int test_btrfs_image_0_perform (guestfs_h *);

static int
test_btrfs_image_0 (guestfs_h *g)
{
  if (test_btrfs_image_0_skip ()) {
    skipped ("test_btrfs_image_0", "environment variable set");
    return 0;
  }

  const char *features89[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features89)) {
    skipped ("test_btrfs_image_0", "group %s not available in daemon",
             features89[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_btrfs_image_0_perform (g);
}

static int
test_btrfs_image_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_image") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_IMAGE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_IMAGE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_image_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_image (0) */
  const char *arg91 = "/dev/sda";
  const char *arg92 = "mbr";
  int ret90;
  ret90 = guestfs_part_init (g, arg91, arg92);
  if (ret90 == -1)
    return -1;
  const char *arg95 = "/dev/sda";
  const char *arg96 = "p";
  int ret94;
  ret94 = guestfs_part_add (g, arg95, arg96, 64, 204799);
  if (ret94 == -1)
    return -1;
  const char *arg101 = "/dev/sda";
  const char *arg102 = "p";
  int ret100;
  ret100 = guestfs_part_add (g, arg101, arg102, 204800, 409599);
  if (ret100 == -1)
    return -1;
  const char *arg107_0 = "/dev/sda1";
  const char *const arg107[] = {
    arg107_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs108;
  optargs108.bitmask = UINT64_C(0x0);
  int ret106;
  ret106 = guestfs_mkfs_btrfs_argv (g, (char **) arg107, &optargs108);
  if (ret106 == -1)
    return -1;
  const char *arg110_0 = "/dev/sda2";
  const char *const arg110[] = {
    arg110_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs111;
  optargs111.bitmask = UINT64_C(0x0);
  int ret109;
  ret109 = guestfs_mkfs_btrfs_argv (g, (char **) arg110, &optargs111);
  if (ret109 == -1)
    return -1;
  const char *arg113 = "/dev/sda1";
  const char *arg114 = "/";
  int ret112;
  ret112 = guestfs_mount (g, arg113, arg114);
  if (ret112 == -1)
    return -1;
  const char *arg117_0 = "/dev/sda2";
  const char *const arg117[] = {
    arg117_0,
    NULL
  };
  const char *arg118 = "/1.img";
  struct guestfs_btrfs_image_argv optargs119;
  optargs119.bitmask = UINT64_C(0x0);
  int ret116;
  ret116 = guestfs_btrfs_image_argv (g, (char **) arg117, arg118, &optargs119);
  if (ret116 == -1)
    return -1;
  const char *arg121_0 = "/dev/sda2";
  const char *const arg121[] = {
    arg121_0,
    NULL
  };
  const char *arg122 = "/2.img";
  struct guestfs_btrfs_image_argv optargs123;
  optargs123.compresslevel = 2;
  optargs123.bitmask = UINT64_C(0x1);
  int ret120;
  ret120 = guestfs_btrfs_image_argv (g, (char **) arg121, arg122, &optargs123);
  if (ret120 == -1)
    return -1;
  return 0;
}

static int test_btrfstune_enable_skinny_metadata_extent_refs_0_skip (void);
static int test_btrfstune_enable_skinny_metadata_extent_refs_0_perform (guestfs_h *);

static int
test_btrfstune_enable_skinny_metadata_extent_refs_0 (guestfs_h *g)
{
  if (test_btrfstune_enable_skinny_metadata_extent_refs_0_skip ()) {
    skipped ("test_btrfstune_enable_skinny_metadata_extent_refs_0", "environment variable set");
    return 0;
  }

  const char *features124[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features124)) {
    skipped ("test_btrfstune_enable_skinny_metadata_extent_refs_0", "group %s not available in daemon",
             features124[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfstune_enable_skinny_metadata_extent_refs_0_perform (g);
}

static int
test_btrfstune_enable_skinny_metadata_extent_refs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfstune_enable_skinny_metadata_extent_refs") == NULL;
  str = getenv ("SKIP_TEST_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfstune_enable_skinny_metadata_extent_refs_0_perform (guestfs_h *g)
{
  /* TestRun for btrfstune_enable_skinny_metadata_extent_refs (0) */
  const char *arg126_0 = "/dev/sda1";
  const char *const arg126[] = {
    arg126_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs127;
  optargs127.bitmask = UINT64_C(0x0);
  int ret125;
  ret125 = guestfs_mkfs_btrfs_argv (g, (char **) arg126, &optargs127);
  if (ret125 == -1)
    return -1;
  const char *arg129 = "/dev/sda1";
  int ret128;
  ret128 = guestfs_btrfstune_enable_skinny_metadata_extent_refs (g, arg129);
  if (ret128 == -1)
    return -1;
  return 0;
}

static int test_btrfstune_enable_extended_inode_refs_0_skip (void);
static int test_btrfstune_enable_extended_inode_refs_0_perform (guestfs_h *);

static int
test_btrfstune_enable_extended_inode_refs_0 (guestfs_h *g)
{
  if (test_btrfstune_enable_extended_inode_refs_0_skip ()) {
    skipped ("test_btrfstune_enable_extended_inode_refs_0", "environment variable set");
    return 0;
  }

  const char *features131[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features131)) {
    skipped ("test_btrfstune_enable_extended_inode_refs_0", "group %s not available in daemon",
             features131[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfstune_enable_extended_inode_refs_0_perform (g);
}

static int
test_btrfstune_enable_extended_inode_refs_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfstune_enable_extended_inode_refs") == NULL;
  str = getenv ("SKIP_TEST_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfstune_enable_extended_inode_refs_0_perform (guestfs_h *g)
{
  /* TestRun for btrfstune_enable_extended_inode_refs (0) */
  const char *arg133_0 = "/dev/sda1";
  const char *const arg133[] = {
    arg133_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs134;
  optargs134.bitmask = UINT64_C(0x0);
  int ret132;
  ret132 = guestfs_mkfs_btrfs_argv (g, (char **) arg133, &optargs134);
  if (ret132 == -1)
    return -1;
  const char *arg136 = "/dev/sda1";
  int ret135;
  ret135 = guestfs_btrfstune_enable_extended_inode_refs (g, arg136);
  if (ret135 == -1)
    return -1;
  return 0;
}

static int test_btrfstune_seeding_0_skip (void);
static int test_btrfstune_seeding_0_perform (guestfs_h *);

static int
test_btrfstune_seeding_0 (guestfs_h *g)
{
  if (test_btrfstune_seeding_0_skip ()) {
    skipped ("test_btrfstune_seeding_0", "environment variable set");
    return 0;
  }

  const char *features138[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features138)) {
    skipped ("test_btrfstune_seeding_0", "group %s not available in daemon",
             features138[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfstune_seeding_0_perform (g);
}

static int
test_btrfstune_seeding_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfstune_seeding") == NULL;
  str = getenv ("SKIP_TEST_BTRFSTUNE_SEEDING_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFSTUNE_SEEDING");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfstune_seeding_0_perform (guestfs_h *g)
{
  /* TestRun for btrfstune_seeding (0) */
  const char *arg140_0 = "/dev/sda1";
  const char *const arg140[] = {
    arg140_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs141;
  optargs141.bitmask = UINT64_C(0x0);
  int ret139;
  ret139 = guestfs_mkfs_btrfs_argv (g, (char **) arg140, &optargs141);
  if (ret139 == -1)
    return -1;
  const char *arg143 = "/dev/sda1";
  int ret142;
  ret142 = guestfs_btrfstune_seeding (g, arg143, 1);
  if (ret142 == -1)
    return -1;
  const char *arg147 = "/dev/sda1";
  int ret146;
  ret146 = guestfs_btrfstune_seeding (g, arg147, 0);
  if (ret146 == -1)
    return -1;
  return 0;
}

static int test_btrfs_scrub_status_0_skip (void);
static int test_btrfs_scrub_status_0_perform (guestfs_h *);

static int
test_btrfs_scrub_status_0 (guestfs_h *g)
{
  if (test_btrfs_scrub_status_0_skip ()) {
    skipped ("test_btrfs_scrub_status_0", "environment variable set");
    return 0;
  }

  const char *features150[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features150)) {
    skipped ("test_btrfs_scrub_status_0", "group %s not available in daemon",
             features150[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_scrub_status_0_perform (g);
}

static int
test_btrfs_scrub_status_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_scrub_status") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_SCRUB_STATUS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_SCRUB_STATUS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_scrub_status_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_scrub_status (0) */
  const char *arg152_0 = "/dev/sda1";
  const char *const arg152[] = {
    arg152_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs153;
  optargs153.bitmask = UINT64_C(0x0);
  int ret151;
  ret151 = guestfs_mkfs_btrfs_argv (g, (char **) arg152, &optargs153);
  if (ret151 == -1)
    return -1;
  const char *arg155 = "/dev/sda1";
  const char *arg156 = "/";
  int ret154;
  ret154 = guestfs_mount (g, arg155, arg156);
  if (ret154 == -1)
    return -1;
  const char *arg159 = "/";
  int ret158;
  ret158 = guestfs_btrfs_scrub_start (g, arg159);
  if (ret158 == -1)
    return -1;
  const char *arg162 = "/";
  CLEANUP_FREE_BTRFSSCRUB struct guestfs_btrfsscrub *ret161;
  ret161 = guestfs_btrfs_scrub_status (g, arg162);
  if (ret161 == NULL)
      return -1;
  return 0;
}

static int test_part_get_gpt_guid_0_skip (void);
static int test_part_get_gpt_guid_0_perform (guestfs_h *);

static int
test_part_get_gpt_guid_0 (guestfs_h *g)
{
  if (test_part_get_gpt_guid_0_skip ()) {
    skipped ("test_part_get_gpt_guid_0", "environment variable set");
    return 0;
  }

  const char *features164[] = { "gdisk", NULL };
  if (!guestfs_feature_available (g, (char **) features164)) {
    skipped ("test_part_get_gpt_guid_0", "group %s not available in daemon",
             features164[0]);
    return 0;
  }

  if (init_gpt (g) == -1)
    return -1;

  return test_part_get_gpt_guid_0_perform (g);
}

static int
test_part_get_gpt_guid_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_get_gpt_guid") == NULL;
  str = getenv ("SKIP_TEST_PART_GET_GPT_GUID_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_GET_GPT_GUID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_get_gpt_guid_0_perform (guestfs_h *g)
{
  /* TestResultString for part_get_gpt_guid (0) */
  const char *arg166 = "/dev/sda";
  const char *arg168 = "01234567-89AB-CDEF-0123-456789ABCDEF";
  int ret165;
  ret165 = guestfs_part_set_gpt_guid (g, arg166, 1, arg168);
  if (ret165 == -1)
    return -1;
  const char *arg170 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_gpt_guid (g, arg170, 1);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "01234567-89AB-CDEF-0123-456789ABCDEF")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_part_get_gpt_guid_0", "part_get_gpt_guid", "01234567-89AB-CDEF-0123-456789ABCDEF", ret);
    return -1;
  }
  return 0;
}

static int test_part_set_gpt_guid_0_skip (void);
static int test_part_set_gpt_guid_0_perform (guestfs_h *);

static int
test_part_set_gpt_guid_0 (guestfs_h *g)
{
  if (test_part_set_gpt_guid_0_skip ()) {
    skipped ("test_part_set_gpt_guid_0", "environment variable set");
    return 0;
  }

  const char *features173[] = { "gdisk", NULL };
  if (!guestfs_feature_available (g, (char **) features173)) {
    skipped ("test_part_set_gpt_guid_0", "group %s not available in daemon",
             features173[0]);
    return 0;
  }

  if (init_gpt (g) == -1)
    return -1;

  return test_part_set_gpt_guid_0_perform (g);
}

static int
test_part_set_gpt_guid_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_set_gpt_guid") == NULL;
  str = getenv ("SKIP_TEST_PART_SET_GPT_GUID_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_SET_GPT_GUID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_set_gpt_guid_0_perform (guestfs_h *g)
{
  /* TestLastFail for part_set_gpt_guid (0) */
  const char *arg175 = "/dev/sda";
  const char *arg177 = "f";
  int ret174;
  guestfs_push_error_handler (g, NULL, NULL);
  ret174 = guestfs_part_set_gpt_guid (g, arg175, 1, arg177);
  guestfs_pop_error_handler (g);
  if (ret174 != -1)
    return -1;
  return 0;
}

static int test_part_set_gpt_guid_1_skip (void);
static int test_part_set_gpt_guid_1_perform (guestfs_h *);

static int
test_part_set_gpt_guid_1 (guestfs_h *g)
{
  if (test_part_set_gpt_guid_1_skip ()) {
    skipped ("test_part_set_gpt_guid_1", "environment variable set");
    return 0;
  }

  const char *features179[] = { "gdisk", NULL };
  if (!guestfs_feature_available (g, (char **) features179)) {
    skipped ("test_part_set_gpt_guid_1", "group %s not available in daemon",
             features179[0]);
    return 0;
  }

  if (init_gpt (g) == -1)
    return -1;

  return test_part_set_gpt_guid_1_perform (g);
}

static int
test_part_set_gpt_guid_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_set_gpt_guid") == NULL;
  str = getenv ("SKIP_TEST_PART_SET_GPT_GUID_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_SET_GPT_GUID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_set_gpt_guid_1_perform (guestfs_h *g)
{
  /* TestResultString for part_set_gpt_guid (1) */
  const char *arg181 = "/dev/sda";
  const char *arg183 = "01234567-89AB-CDEF-0123-456789ABCDEF";
  int ret180;
  ret180 = guestfs_part_set_gpt_guid (g, arg181, 1, arg183);
  if (ret180 == -1)
    return -1;
  const char *arg185 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_gpt_guid (g, arg185, 1);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "01234567-89AB-CDEF-0123-456789ABCDEF")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_part_set_gpt_guid_1", "part_get_gpt_guid", "01234567-89AB-CDEF-0123-456789ABCDEF", ret);
    return -1;
  }
  return 0;
}

static int test_btrfs_rescue_super_recover_0_skip (void);
static int test_btrfs_rescue_super_recover_0_perform (guestfs_h *);

static int
test_btrfs_rescue_super_recover_0 (guestfs_h *g)
{
  if (test_btrfs_rescue_super_recover_0_skip ()) {
    skipped ("test_btrfs_rescue_super_recover_0", "environment variable set");
    return 0;
  }

  const char *features188[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features188)) {
    skipped ("test_btrfs_rescue_super_recover_0", "group %s not available in daemon",
             features188[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_rescue_super_recover_0_perform (g);
}

static int
test_btrfs_rescue_super_recover_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_rescue_super_recover") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_RESCUE_SUPER_RECOVER_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_RESCUE_SUPER_RECOVER");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_rescue_super_recover_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_rescue_super_recover (0) */
  const char *arg190_0 = "/dev/sda1";
  const char *const arg190[] = {
    arg190_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs191;
  optargs191.bitmask = UINT64_C(0x0);
  int ret189;
  ret189 = guestfs_mkfs_btrfs_argv (g, (char **) arg190, &optargs191);
  if (ret189 == -1)
    return -1;
  const char *arg193 = "/dev/sda1";
  int ret192;
  ret192 = guestfs_btrfs_rescue_super_recover (g, arg193);
  if (ret192 == -1)
    return -1;
  return 0;
}

static int test_btrfs_rescue_chunk_recover_0_skip (void);
static int test_btrfs_rescue_chunk_recover_0_perform (guestfs_h *);

static int
test_btrfs_rescue_chunk_recover_0 (guestfs_h *g)
{
  if (test_btrfs_rescue_chunk_recover_0_skip ()) {
    skipped ("test_btrfs_rescue_chunk_recover_0", "environment variable set");
    return 0;
  }

  const char *features195[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features195)) {
    skipped ("test_btrfs_rescue_chunk_recover_0", "group %s not available in daemon",
             features195[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_rescue_chunk_recover_0_perform (g);
}

static int
test_btrfs_rescue_chunk_recover_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_rescue_chunk_recover") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_RESCUE_CHUNK_RECOVER_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_RESCUE_CHUNK_RECOVER");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_rescue_chunk_recover_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_rescue_chunk_recover (0) */
  const char *arg197_0 = "/dev/sda1";
  const char *const arg197[] = {
    arg197_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs198;
  optargs198.bitmask = UINT64_C(0x0);
  int ret196;
  ret196 = guestfs_mkfs_btrfs_argv (g, (char **) arg197, &optargs198);
  if (ret196 == -1)
    return -1;
  const char *arg200 = "/dev/sda1";
  int ret199;
  ret199 = guestfs_btrfs_rescue_chunk_recover (g, arg200);
  if (ret199 == -1)
    return -1;
  return 0;
}

static int test_btrfs_filesystem_defragment_0_skip (void);
static int test_btrfs_filesystem_defragment_0_perform (guestfs_h *);

static int
test_btrfs_filesystem_defragment_0 (guestfs_h *g)
{
  if (test_btrfs_filesystem_defragment_0_skip ()) {
    skipped ("test_btrfs_filesystem_defragment_0", "environment variable set");
    return 0;
  }

  const char *features202[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features202)) {
    skipped ("test_btrfs_filesystem_defragment_0", "group %s not available in daemon",
             features202[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_filesystem_defragment_0_perform (g);
}

static int
test_btrfs_filesystem_defragment_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_filesystem_defragment") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_FILESYSTEM_DEFRAGMENT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_FILESYSTEM_DEFRAGMENT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_filesystem_defragment_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_filesystem_defragment (0) */
  const char *arg204_0 = "/dev/sda1";
  const char *const arg204[] = {
    arg204_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs205;
  optargs205.bitmask = UINT64_C(0x0);
  int ret203;
  ret203 = guestfs_mkfs_btrfs_argv (g, (char **) arg204, &optargs205);
  if (ret203 == -1)
    return -1;
  const char *arg207 = "/dev/sda1";
  const char *arg208 = "/";
  int ret206;
  ret206 = guestfs_mount (g, arg207, arg208);
  if (ret206 == -1)
    return -1;
  const char *arg211 = "/";
  struct guestfs_btrfs_filesystem_defragment_argv optargs212;
  optargs212.flush = 1;
  optargs212.compress = "lzo";
  optargs212.bitmask = UINT64_C(0x3);
  int ret210;
  ret210 = guestfs_btrfs_filesystem_defragment_argv (g, arg211, &optargs212);
  if (ret210 == -1)
    return -1;
  return 0;
}

static int test_btrfs_filesystem_defragment_1_skip (void);
static int test_btrfs_filesystem_defragment_1_perform (guestfs_h *);

static int
test_btrfs_filesystem_defragment_1 (guestfs_h *g)
{
  if (test_btrfs_filesystem_defragment_1_skip ()) {
    skipped ("test_btrfs_filesystem_defragment_1", "environment variable set");
    return 0;
  }

  const char *features213[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features213)) {
    skipped ("test_btrfs_filesystem_defragment_1", "group %s not available in daemon",
             features213[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_filesystem_defragment_1_perform (g);
}

static int
test_btrfs_filesystem_defragment_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_filesystem_defragment") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_FILESYSTEM_DEFRAGMENT_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_FILESYSTEM_DEFRAGMENT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_filesystem_defragment_1_perform (guestfs_h *g)
{
  /* TestRun for btrfs_filesystem_defragment (1) */
  const char *arg215_0 = "/dev/sda1";
  const char *const arg215[] = {
    arg215_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs216;
  optargs216.bitmask = UINT64_C(0x0);
  int ret214;
  ret214 = guestfs_mkfs_btrfs_argv (g, (char **) arg215, &optargs216);
  if (ret214 == -1)
    return -1;
  const char *arg218 = "/dev/sda1";
  const char *arg219 = "/";
  int ret217;
  ret217 = guestfs_mount (g, arg218, arg219);
  if (ret217 == -1)
    return -1;
  const char *arg222 = "/hello";
  int ret221;
  ret221 = guestfs_touch (g, arg222);
  if (ret221 == -1)
    return -1;
  const char *arg225 = "/hello";
  struct guestfs_btrfs_filesystem_defragment_argv optargs226;
  optargs226.compress = "zlib";
  optargs226.bitmask = UINT64_C(0x2);
  int ret224;
  ret224 = guestfs_btrfs_filesystem_defragment_argv (g, arg225, &optargs226);
  if (ret224 == -1)
    return -1;
  return 0;
}

static int test_btrfs_scrub_start_0_skip (void);
static int test_btrfs_scrub_start_0_perform (guestfs_h *);

static int
test_btrfs_scrub_start_0 (guestfs_h *g)
{
  if (test_btrfs_scrub_start_0_skip ()) {
    skipped ("test_btrfs_scrub_start_0", "environment variable set");
    return 0;
  }

  const char *features227[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features227)) {
    skipped ("test_btrfs_scrub_start_0", "group %s not available in daemon",
             features227[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_scrub_start_0_perform (g);
}

static int
test_btrfs_scrub_start_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_scrub_start") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_SCRUB_START_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_SCRUB_START");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_scrub_start_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_scrub_start (0) */
  const char *arg229_0 = "/dev/sda1";
  const char *const arg229[] = {
    arg229_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs230;
  optargs230.bitmask = UINT64_C(0x0);
  int ret228;
  ret228 = guestfs_mkfs_btrfs_argv (g, (char **) arg229, &optargs230);
  if (ret228 == -1)
    return -1;
  const char *arg232 = "/dev/sda1";
  const char *arg233 = "/";
  int ret231;
  ret231 = guestfs_mount (g, arg232, arg233);
  if (ret231 == -1)
    return -1;
  const char *arg236 = "/";
  int ret235;
  ret235 = guestfs_btrfs_scrub_start (g, arg236);
  if (ret235 == -1)
    return -1;
  return 0;
}

static int test_btrfs_qgroup_remove_0_skip (void);
static int test_btrfs_qgroup_remove_0_perform (guestfs_h *);

static int
test_btrfs_qgroup_remove_0 (guestfs_h *g)
{
  if (test_btrfs_qgroup_remove_0_skip ()) {
    skipped ("test_btrfs_qgroup_remove_0", "environment variable set");
    return 0;
  }

  const char *features238[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features238)) {
    skipped ("test_btrfs_qgroup_remove_0", "group %s not available in daemon",
             features238[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_qgroup_remove_0_perform (g);
}

static int
test_btrfs_qgroup_remove_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_qgroup_remove") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_REMOVE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_REMOVE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_qgroup_remove_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_qgroup_remove (0) */
  const char *arg240_0 = "/dev/sda1";
  const char *const arg240[] = {
    arg240_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs241;
  optargs241.bitmask = UINT64_C(0x0);
  int ret239;
  ret239 = guestfs_mkfs_btrfs_argv (g, (char **) arg240, &optargs241);
  if (ret239 == -1)
    return -1;
  const char *arg243 = "/dev/sda1";
  const char *arg244 = "/";
  int ret242;
  ret242 = guestfs_mount (g, arg243, arg244);
  if (ret242 == -1)
    return -1;
  const char *arg247 = "/";
  int ret246;
  ret246 = guestfs_btrfs_quota_enable (g, arg247, 1);
  if (ret246 == -1)
    return -1;
  const char *arg251 = "0/1000";
  const char *arg252 = "/";
  int ret250;
  ret250 = guestfs_btrfs_qgroup_create (g, arg251, arg252);
  if (ret250 == -1)
    return -1;
  const char *arg255 = "1/1000";
  const char *arg256 = "/";
  int ret254;
  ret254 = guestfs_btrfs_qgroup_create (g, arg255, arg256);
  if (ret254 == -1)
    return -1;
  const char *arg259 = "0/1000";
  const char *arg260 = "1/1000";
  const char *arg261 = "/";
  int ret258;
  ret258 = guestfs_btrfs_qgroup_assign (g, arg259, arg260, arg261);
  if (ret258 == -1)
    return -1;
  const char *arg264 = "0/1000";
  const char *arg265 = "1/1000";
  const char *arg266 = "/";
  int ret263;
  ret263 = guestfs_btrfs_qgroup_remove (g, arg264, arg265, arg266);
  if (ret263 == -1)
    return -1;
  return 0;
}

static int test_btrfs_qgroup_assign_0_skip (void);
static int test_btrfs_qgroup_assign_0_perform (guestfs_h *);

static int
test_btrfs_qgroup_assign_0 (guestfs_h *g)
{
  if (test_btrfs_qgroup_assign_0_skip ()) {
    skipped ("test_btrfs_qgroup_assign_0", "environment variable set");
    return 0;
  }

  const char *features268[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features268)) {
    skipped ("test_btrfs_qgroup_assign_0", "group %s not available in daemon",
             features268[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_qgroup_assign_0_perform (g);
}

static int
test_btrfs_qgroup_assign_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_qgroup_assign") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_ASSIGN_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_ASSIGN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_qgroup_assign_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_qgroup_assign (0) */
  const char *arg270_0 = "/dev/sda1";
  const char *const arg270[] = {
    arg270_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs271;
  optargs271.bitmask = UINT64_C(0x0);
  int ret269;
  ret269 = guestfs_mkfs_btrfs_argv (g, (char **) arg270, &optargs271);
  if (ret269 == -1)
    return -1;
  const char *arg273 = "/dev/sda1";
  const char *arg274 = "/";
  int ret272;
  ret272 = guestfs_mount (g, arg273, arg274);
  if (ret272 == -1)
    return -1;
  const char *arg277 = "/";
  int ret276;
  ret276 = guestfs_btrfs_quota_enable (g, arg277, 1);
  if (ret276 == -1)
    return -1;
  const char *arg281 = "0/1000";
  const char *arg282 = "/";
  int ret280;
  ret280 = guestfs_btrfs_qgroup_create (g, arg281, arg282);
  if (ret280 == -1)
    return -1;
  const char *arg285 = "1/1000";
  const char *arg286 = "/";
  int ret284;
  ret284 = guestfs_btrfs_qgroup_create (g, arg285, arg286);
  if (ret284 == -1)
    return -1;
  const char *arg289 = "0/1000";
  const char *arg290 = "1/1000";
  const char *arg291 = "/";
  int ret288;
  ret288 = guestfs_btrfs_qgroup_assign (g, arg289, arg290, arg291);
  if (ret288 == -1)
    return -1;
  return 0;
}

static int test_btrfs_qgroup_show_0_skip (void);
static int test_btrfs_qgroup_show_0_perform (guestfs_h *);

static int
test_btrfs_qgroup_show_0 (guestfs_h *g)
{
  if (test_btrfs_qgroup_show_0_skip ()) {
    skipped ("test_btrfs_qgroup_show_0", "environment variable set");
    return 0;
  }

  const char *features293[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features293)) {
    skipped ("test_btrfs_qgroup_show_0", "group %s not available in daemon",
             features293[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_qgroup_show_0_perform (g);
}

static int
test_btrfs_qgroup_show_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_qgroup_show") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_SHOW_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_SHOW");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_qgroup_show_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_qgroup_show (0) */
  const char *arg295_0 = "/dev/sda1";
  const char *const arg295[] = {
    arg295_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs296;
  optargs296.bitmask = UINT64_C(0x0);
  int ret294;
  ret294 = guestfs_mkfs_btrfs_argv (g, (char **) arg295, &optargs296);
  if (ret294 == -1)
    return -1;
  const char *arg298 = "/dev/sda1";
  const char *arg299 = "/";
  int ret297;
  ret297 = guestfs_mount (g, arg298, arg299);
  if (ret297 == -1)
    return -1;
  const char *arg302 = "/";
  int ret301;
  ret301 = guestfs_btrfs_quota_enable (g, arg302, 1);
  if (ret301 == -1)
    return -1;
  const char *arg306 = "/sub1";
  struct guestfs_btrfs_subvolume_create_opts_argv optargs307;
  optargs307.bitmask = UINT64_C(0x0);
  int ret305;
  ret305 = guestfs_btrfs_subvolume_create_opts_argv (g, arg306, &optargs307);
  if (ret305 == -1)
    return -1;
  const char *arg309 = "0/1000";
  const char *arg310 = "/sub1";
  int ret308;
  ret308 = guestfs_btrfs_qgroup_create (g, arg309, arg310);
  if (ret308 == -1)
    return -1;
  const char *arg313 = "/";
  CLEANUP_FREE_BTRFSQGROUP_LIST struct guestfs_btrfsqgroup_list *ret312;
  ret312 = guestfs_btrfs_qgroup_show (g, arg313);
  if (ret312 == NULL)
      return -1;
  return 0;
}

static int test_btrfs_qgroup_destroy_0_skip (void);
static int test_btrfs_qgroup_destroy_0_perform (guestfs_h *);

static int
test_btrfs_qgroup_destroy_0 (guestfs_h *g)
{
  if (test_btrfs_qgroup_destroy_0_skip ()) {
    skipped ("test_btrfs_qgroup_destroy_0", "environment variable set");
    return 0;
  }

  const char *features315[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features315)) {
    skipped ("test_btrfs_qgroup_destroy_0", "group %s not available in daemon",
             features315[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_qgroup_destroy_0_perform (g);
}

static int
test_btrfs_qgroup_destroy_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_qgroup_destroy") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_DESTROY_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_DESTROY");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_qgroup_destroy_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_qgroup_destroy (0) */
  const char *arg317_0 = "/dev/sda1";
  const char *const arg317[] = {
    arg317_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs318;
  optargs318.bitmask = UINT64_C(0x0);
  int ret316;
  ret316 = guestfs_mkfs_btrfs_argv (g, (char **) arg317, &optargs318);
  if (ret316 == -1)
    return -1;
  const char *arg320 = "/dev/sda1";
  const char *arg321 = "/";
  int ret319;
  ret319 = guestfs_mount (g, arg320, arg321);
  if (ret319 == -1)
    return -1;
  const char *arg324 = "/";
  int ret323;
  ret323 = guestfs_btrfs_quota_enable (g, arg324, 1);
  if (ret323 == -1)
    return -1;
  const char *arg328 = "/sub1";
  struct guestfs_btrfs_subvolume_create_opts_argv optargs329;
  optargs329.bitmask = UINT64_C(0x0);
  int ret327;
  ret327 = guestfs_btrfs_subvolume_create_opts_argv (g, arg328, &optargs329);
  if (ret327 == -1)
    return -1;
  const char *arg331 = "0/1000";
  const char *arg332 = "/sub1";
  int ret330;
  ret330 = guestfs_btrfs_qgroup_create (g, arg331, arg332);
  if (ret330 == -1)
    return -1;
  const char *arg335 = "0/1000";
  const char *arg336 = "/sub1";
  int ret334;
  ret334 = guestfs_btrfs_qgroup_destroy (g, arg335, arg336);
  if (ret334 == -1)
    return -1;
  return 0;
}

static int test_btrfs_qgroup_create_0_skip (void);
static int test_btrfs_qgroup_create_0_perform (guestfs_h *);

static int
test_btrfs_qgroup_create_0 (guestfs_h *g)
{
  if (test_btrfs_qgroup_create_0_skip ()) {
    skipped ("test_btrfs_qgroup_create_0", "environment variable set");
    return 0;
  }

  const char *features338[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features338)) {
    skipped ("test_btrfs_qgroup_create_0", "group %s not available in daemon",
             features338[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_qgroup_create_0_perform (g);
}

static int
test_btrfs_qgroup_create_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_qgroup_create") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_CREATE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_CREATE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_qgroup_create_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_qgroup_create (0) */
  const char *arg340_0 = "/dev/sda1";
  const char *const arg340[] = {
    arg340_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs341;
  optargs341.bitmask = UINT64_C(0x0);
  int ret339;
  ret339 = guestfs_mkfs_btrfs_argv (g, (char **) arg340, &optargs341);
  if (ret339 == -1)
    return -1;
  const char *arg343 = "/dev/sda1";
  const char *arg344 = "/";
  int ret342;
  ret342 = guestfs_mount (g, arg343, arg344);
  if (ret342 == -1)
    return -1;
  const char *arg347 = "/";
  int ret346;
  ret346 = guestfs_btrfs_quota_enable (g, arg347, 1);
  if (ret346 == -1)
    return -1;
  const char *arg351 = "/sub1";
  struct guestfs_btrfs_subvolume_create_opts_argv optargs352;
  optargs352.bitmask = UINT64_C(0x0);
  int ret350;
  ret350 = guestfs_btrfs_subvolume_create_opts_argv (g, arg351, &optargs352);
  if (ret350 == -1)
    return -1;
  const char *arg354 = "0/1000";
  const char *arg355 = "/sub1";
  int ret353;
  ret353 = guestfs_btrfs_qgroup_create (g, arg354, arg355);
  if (ret353 == -1)
    return -1;
  return 0;
}

static int test_btrfs_qgroup_limit_0_skip (void);
static int test_btrfs_qgroup_limit_0_perform (guestfs_h *);

static int
test_btrfs_qgroup_limit_0 (guestfs_h *g)
{
  if (test_btrfs_qgroup_limit_0_skip ()) {
    skipped ("test_btrfs_qgroup_limit_0", "environment variable set");
    return 0;
  }

  const char *features357[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features357)) {
    skipped ("test_btrfs_qgroup_limit_0", "group %s not available in daemon",
             features357[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_qgroup_limit_0_perform (g);
}

static int
test_btrfs_qgroup_limit_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_qgroup_limit") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_LIMIT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_LIMIT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_qgroup_limit_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_qgroup_limit (0) */
  const char *arg359_0 = "/dev/sda1";
  const char *const arg359[] = {
    arg359_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs360;
  optargs360.bitmask = UINT64_C(0x0);
  int ret358;
  ret358 = guestfs_mkfs_btrfs_argv (g, (char **) arg359, &optargs360);
  if (ret358 == -1)
    return -1;
  const char *arg362 = "/dev/sda1";
  const char *arg363 = "/";
  int ret361;
  ret361 = guestfs_mount (g, arg362, arg363);
  if (ret361 == -1)
    return -1;
  const char *arg366 = "/";
  int ret365;
  ret365 = guestfs_btrfs_quota_enable (g, arg366, 1);
  if (ret365 == -1)
    return -1;
  const char *arg370 = "/";
  int ret369;
  ret369 = guestfs_btrfs_qgroup_limit (g, arg370, 10737418240);
  if (ret369 == -1)
    return -1;
  return 0;
}

static int test_btrfs_qgroup_limit_1_skip (void);
static int test_btrfs_qgroup_limit_1_perform (guestfs_h *);

static int
test_btrfs_qgroup_limit_1 (guestfs_h *g)
{
  if (test_btrfs_qgroup_limit_1_skip ()) {
    skipped ("test_btrfs_qgroup_limit_1", "environment variable set");
    return 0;
  }

  const char *features373[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features373)) {
    skipped ("test_btrfs_qgroup_limit_1", "group %s not available in daemon",
             features373[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_qgroup_limit_1_perform (g);
}

static int
test_btrfs_qgroup_limit_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_qgroup_limit") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_LIMIT_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_QGROUP_LIMIT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_qgroup_limit_1_perform (guestfs_h *g)
{
  /* TestLastFail for btrfs_qgroup_limit (1) */
  const char *arg375_0 = "/dev/sda1";
  const char *const arg375[] = {
    arg375_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs376;
  optargs376.bitmask = UINT64_C(0x0);
  int ret374;
  ret374 = guestfs_mkfs_btrfs_argv (g, (char **) arg375, &optargs376);
  if (ret374 == -1)
    return -1;
  const char *arg378 = "/dev/sda1";
  const char *arg379 = "/";
  int ret377;
  ret377 = guestfs_mount (g, arg378, arg379);
  if (ret377 == -1)
    return -1;
  const char *arg382 = "/";
  int ret381;
  ret381 = guestfs_btrfs_quota_enable (g, arg382, 0);
  if (ret381 == -1)
    return -1;
  const char *arg386 = "/";
  int ret385;
  guestfs_push_error_handler (g, NULL, NULL);
  ret385 = guestfs_btrfs_qgroup_limit (g, arg386, 10737418240);
  guestfs_pop_error_handler (g);
  if (ret385 != -1)
    return -1;
  return 0;
}

static int test_btrfs_quota_rescan_0_skip (void);
static int test_btrfs_quota_rescan_0_perform (guestfs_h *);

static int
test_btrfs_quota_rescan_0 (guestfs_h *g)
{
  if (test_btrfs_quota_rescan_0_skip ()) {
    skipped ("test_btrfs_quota_rescan_0", "environment variable set");
    return 0;
  }

  const char *features389[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features389)) {
    skipped ("test_btrfs_quota_rescan_0", "group %s not available in daemon",
             features389[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_quota_rescan_0_perform (g);
}

static int
test_btrfs_quota_rescan_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_quota_rescan") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_QUOTA_RESCAN_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_QUOTA_RESCAN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_quota_rescan_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_quota_rescan (0) */
  const char *arg391_0 = "/dev/sda1";
  const char *const arg391[] = {
    arg391_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs392;
  optargs392.bitmask = UINT64_C(0x0);
  int ret390;
  ret390 = guestfs_mkfs_btrfs_argv (g, (char **) arg391, &optargs392);
  if (ret390 == -1)
    return -1;
  const char *arg394 = "/dev/sda1";
  int ret393;
  ret393 = guestfs_btrfs_quota_enable (g, arg394, 1);
  if (ret393 == -1)
    return -1;
  const char *arg398 = "/dev/sda1";
  int ret397;
  ret397 = guestfs_btrfs_quota_rescan (g, arg398);
  if (ret397 == -1)
    return -1;
  return 0;
}

static int test_btrfs_quota_rescan_1_skip (void);
static int test_btrfs_quota_rescan_1_perform (guestfs_h *);

static int
test_btrfs_quota_rescan_1 (guestfs_h *g)
{
  if (test_btrfs_quota_rescan_1_skip ()) {
    skipped ("test_btrfs_quota_rescan_1", "environment variable set");
    return 0;
  }

  const char *features400[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features400)) {
    skipped ("test_btrfs_quota_rescan_1", "group %s not available in daemon",
             features400[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_quota_rescan_1_perform (g);
}

static int
test_btrfs_quota_rescan_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_quota_rescan") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_QUOTA_RESCAN_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_QUOTA_RESCAN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_quota_rescan_1_perform (guestfs_h *g)
{
  /* TestRun for btrfs_quota_rescan (1) */
  const char *arg402_0 = "/dev/sda1";
  const char *const arg402[] = {
    arg402_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs403;
  optargs403.bitmask = UINT64_C(0x0);
  int ret401;
  ret401 = guestfs_mkfs_btrfs_argv (g, (char **) arg402, &optargs403);
  if (ret401 == -1)
    return -1;
  const char *arg405 = "/dev/sda1";
  const char *arg406 = "/";
  int ret404;
  ret404 = guestfs_mount (g, arg405, arg406);
  if (ret404 == -1)
    return -1;
  const char *arg409 = "/";
  int ret408;
  ret408 = guestfs_btrfs_quota_enable (g, arg409, 1);
  if (ret408 == -1)
    return -1;
  const char *arg413 = "/";
  int ret412;
  ret412 = guestfs_btrfs_quota_rescan (g, arg413);
  if (ret412 == -1)
    return -1;
  return 0;
}

static int test_btrfs_quota_enable_0_skip (void);
static int test_btrfs_quota_enable_0_perform (guestfs_h *);

static int
test_btrfs_quota_enable_0 (guestfs_h *g)
{
  if (test_btrfs_quota_enable_0_skip ()) {
    skipped ("test_btrfs_quota_enable_0", "environment variable set");
    return 0;
  }

  const char *features415[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features415)) {
    skipped ("test_btrfs_quota_enable_0", "group %s not available in daemon",
             features415[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_quota_enable_0_perform (g);
}

static int
test_btrfs_quota_enable_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_quota_enable") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_QUOTA_ENABLE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_QUOTA_ENABLE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_quota_enable_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_quota_enable (0) */
  const char *arg417_0 = "/dev/sda1";
  const char *const arg417[] = {
    arg417_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs418;
  optargs418.bitmask = UINT64_C(0x0);
  int ret416;
  ret416 = guestfs_mkfs_btrfs_argv (g, (char **) arg417, &optargs418);
  if (ret416 == -1)
    return -1;
  const char *arg420 = "/dev/sda1";
  int ret419;
  ret419 = guestfs_btrfs_quota_enable (g, arg420, 1);
  if (ret419 == -1)
    return -1;
  return 0;
}

static int test_btrfs_quota_enable_1_skip (void);
static int test_btrfs_quota_enable_1_perform (guestfs_h *);

static int
test_btrfs_quota_enable_1 (guestfs_h *g)
{
  if (test_btrfs_quota_enable_1_skip ()) {
    skipped ("test_btrfs_quota_enable_1", "environment variable set");
    return 0;
  }

  const char *features423[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features423)) {
    skipped ("test_btrfs_quota_enable_1", "group %s not available in daemon",
             features423[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_quota_enable_1_perform (g);
}

static int
test_btrfs_quota_enable_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_quota_enable") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_QUOTA_ENABLE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_QUOTA_ENABLE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_quota_enable_1_perform (guestfs_h *g)
{
  /* TestRun for btrfs_quota_enable (1) */
  const char *arg425_0 = "/dev/sda1";
  const char *const arg425[] = {
    arg425_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs426;
  optargs426.bitmask = UINT64_C(0x0);
  int ret424;
  ret424 = guestfs_mkfs_btrfs_argv (g, (char **) arg425, &optargs426);
  if (ret424 == -1)
    return -1;
  const char *arg428 = "/dev/sda1";
  const char *arg429 = "/";
  int ret427;
  ret427 = guestfs_mount (g, arg428, arg429);
  if (ret427 == -1)
    return -1;
  const char *arg432 = "/";
  int ret431;
  ret431 = guestfs_btrfs_quota_enable (g, arg432, 1);
  if (ret431 == -1)
    return -1;
  return 0;
}

static int test_btrfs_quota_enable_2_skip (void);
static int test_btrfs_quota_enable_2_perform (guestfs_h *);

static int
test_btrfs_quota_enable_2 (guestfs_h *g)
{
  if (test_btrfs_quota_enable_2_skip ()) {
    skipped ("test_btrfs_quota_enable_2", "environment variable set");
    return 0;
  }

  const char *features435[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features435)) {
    skipped ("test_btrfs_quota_enable_2", "group %s not available in daemon",
             features435[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_quota_enable_2_perform (g);
}

static int
test_btrfs_quota_enable_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_quota_enable") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_QUOTA_ENABLE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_QUOTA_ENABLE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_quota_enable_2_perform (guestfs_h *g)
{
  /* TestRun for btrfs_quota_enable (2) */
  const char *arg437_0 = "/dev/sda1";
  const char *const arg437[] = {
    arg437_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs438;
  optargs438.bitmask = UINT64_C(0x0);
  int ret436;
  ret436 = guestfs_mkfs_btrfs_argv (g, (char **) arg437, &optargs438);
  if (ret436 == -1)
    return -1;
  const char *arg440 = "/dev/sda1";
  int ret439;
  ret439 = guestfs_btrfs_quota_enable (g, arg440, 0);
  if (ret439 == -1)
    return -1;
  return 0;
}

static int test_btrfs_quota_enable_3_skip (void);
static int test_btrfs_quota_enable_3_perform (guestfs_h *);

static int
test_btrfs_quota_enable_3 (guestfs_h *g)
{
  if (test_btrfs_quota_enable_3_skip ()) {
    skipped ("test_btrfs_quota_enable_3", "environment variable set");
    return 0;
  }

  const char *features443[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features443)) {
    skipped ("test_btrfs_quota_enable_3", "group %s not available in daemon",
             features443[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_quota_enable_3_perform (g);
}

static int
test_btrfs_quota_enable_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_quota_enable") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_QUOTA_ENABLE_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_QUOTA_ENABLE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_quota_enable_3_perform (guestfs_h *g)
{
  /* TestRun for btrfs_quota_enable (3) */
  const char *arg445_0 = "/dev/sda1";
  const char *const arg445[] = {
    arg445_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs446;
  optargs446.bitmask = UINT64_C(0x0);
  int ret444;
  ret444 = guestfs_mkfs_btrfs_argv (g, (char **) arg445, &optargs446);
  if (ret444 == -1)
    return -1;
  const char *arg448 = "/dev/sda1";
  const char *arg449 = "/";
  int ret447;
  ret447 = guestfs_mount (g, arg448, arg449);
  if (ret447 == -1)
    return -1;
  const char *arg452 = "/";
  int ret451;
  ret451 = guestfs_btrfs_quota_enable (g, arg452, 0);
  if (ret451 == -1)
    return -1;
  return 0;
}

static int test_btrfs_subvolume_show_0_skip (void);
static int test_btrfs_subvolume_show_0_perform (guestfs_h *);

static int
test_btrfs_subvolume_show_0 (guestfs_h *g)
{
  if (test_btrfs_subvolume_show_0_skip ()) {
    skipped ("test_btrfs_subvolume_show_0", "environment variable set");
    return 0;
  }

  const char *features455[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features455)) {
    skipped ("test_btrfs_subvolume_show_0", "group %s not available in daemon",
             features455[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_subvolume_show_0_perform (g);
}

static int
test_btrfs_subvolume_show_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_subvolume_show") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_SHOW_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_SHOW");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_subvolume_show_0_perform (guestfs_h *g)
{
  /* TestLastFail for btrfs_subvolume_show (0) */
  const char *arg457_0 = "/dev/sda1";
  const char *const arg457[] = {
    arg457_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs458;
  optargs458.bitmask = UINT64_C(0x0);
  int ret456;
  ret456 = guestfs_mkfs_btrfs_argv (g, (char **) arg457, &optargs458);
  if (ret456 == -1)
    return -1;
  const char *arg460 = "/dev/sda1";
  const char *arg461 = "/";
  int ret459;
  ret459 = guestfs_mount (g, arg460, arg461);
  if (ret459 == -1)
    return -1;
  const char *arg464 = "/";
  CLEANUP_FREE_STRING_LIST char **ret463;
  guestfs_push_error_handler (g, NULL, NULL);
  ret463 = guestfs_btrfs_subvolume_show (g, arg464);
  guestfs_pop_error_handler (g);
  if (ret463 != NULL)
    return -1;
  return 0;
}

static int test_btrfs_subvolume_show_1_skip (void);
static int test_btrfs_subvolume_show_1_perform (guestfs_h *);

static int
test_btrfs_subvolume_show_1 (guestfs_h *g)
{
  if (test_btrfs_subvolume_show_1_skip ()) {
    skipped ("test_btrfs_subvolume_show_1", "environment variable set");
    return 0;
  }

  const char *features466[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features466)) {
    skipped ("test_btrfs_subvolume_show_1", "group %s not available in daemon",
             features466[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_subvolume_show_1_perform (g);
}

static int
test_btrfs_subvolume_show_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_subvolume_show") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_SHOW_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_SHOW");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_subvolume_show_1_perform (guestfs_h *g)
{
  /* TestRun for btrfs_subvolume_show (1) */
  const char *arg468_0 = "/dev/sda1";
  const char *const arg468[] = {
    arg468_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs469;
  optargs469.bitmask = UINT64_C(0x0);
  int ret467;
  ret467 = guestfs_mkfs_btrfs_argv (g, (char **) arg468, &optargs469);
  if (ret467 == -1)
    return -1;
  const char *arg471 = "/dev/sda1";
  const char *arg472 = "/";
  int ret470;
  ret470 = guestfs_mount (g, arg471, arg472);
  if (ret470 == -1)
    return -1;
  const char *arg475 = "/sub1";
  struct guestfs_btrfs_subvolume_create_opts_argv optargs476;
  optargs476.bitmask = UINT64_C(0x0);
  int ret474;
  ret474 = guestfs_btrfs_subvolume_create_opts_argv (g, arg475, &optargs476);
  if (ret474 == -1)
    return -1;
  const char *arg478 = "/sub1";
  CLEANUP_FREE_STRING_LIST char **ret477;
  ret477 = guestfs_btrfs_subvolume_show (g, arg478);
  if (ret477 == NULL)
      return -1;
  return 0;
}

static int test_btrfs_subvolume_show_2_skip (void);
static int test_btrfs_subvolume_show_2_perform (guestfs_h *);

static int
test_btrfs_subvolume_show_2 (guestfs_h *g)
{
  if (test_btrfs_subvolume_show_2_skip ()) {
    skipped ("test_btrfs_subvolume_show_2", "environment variable set");
    return 0;
  }

  const char *features480[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features480)) {
    skipped ("test_btrfs_subvolume_show_2", "group %s not available in daemon",
             features480[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_subvolume_show_2_perform (g);
}

static int
test_btrfs_subvolume_show_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_subvolume_show") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_SHOW_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_SHOW");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_subvolume_show_2_perform (guestfs_h *g)
{
  /* TestLastFail for btrfs_subvolume_show (2) */
  const char *arg482_0 = "/dev/sda1";
  const char *const arg482[] = {
    arg482_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs483;
  optargs483.bitmask = UINT64_C(0x0);
  int ret481;
  ret481 = guestfs_mkfs_btrfs_argv (g, (char **) arg482, &optargs483);
  if (ret481 == -1)
    return -1;
  const char *arg485 = "/dev/sda1";
  const char *arg486 = "/";
  int ret484;
  ret484 = guestfs_mount (g, arg485, arg486);
  if (ret484 == -1)
    return -1;
  const char *arg489 = "/dir1";
  int ret488;
  ret488 = guestfs_mkdir (g, arg489);
  if (ret488 == -1)
    return -1;
  const char *arg492 = "/dir1";
  CLEANUP_FREE_STRING_LIST char **ret491;
  guestfs_push_error_handler (g, NULL, NULL);
  ret491 = guestfs_btrfs_subvolume_show (g, arg492);
  guestfs_pop_error_handler (g);
  if (ret491 != NULL)
    return -1;
  return 0;
}

static int test_btrfs_subvolume_get_default_0_skip (void);
static int test_btrfs_subvolume_get_default_0_perform (guestfs_h *);

static int
test_btrfs_subvolume_get_default_0 (guestfs_h *g)
{
  if (test_btrfs_subvolume_get_default_0_skip ()) {
    skipped ("test_btrfs_subvolume_get_default_0", "environment variable set");
    return 0;
  }

  const char *features494[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features494)) {
    skipped ("test_btrfs_subvolume_get_default_0", "group %s not available in daemon",
             features494[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_subvolume_get_default_0_perform (g);
}

static int
test_btrfs_subvolume_get_default_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_subvolume_get_default") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_GET_DEFAULT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_GET_DEFAULT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_subvolume_get_default_0_perform (guestfs_h *g)
{
  /* TestResult for btrfs_subvolume_get_default (0) */
  const char *arg495_0 = "/dev/sda1";
  const char *const arg495[] = {
    arg495_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs496;
  optargs496.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_mkfs_btrfs_argv (g, (char **) arg495, &optargs496);
  if (ret1 == -1)
    return -1;
  const char *arg497 = "/dev/sda1";
  int64_t ret;
  ret = guestfs_btrfs_subvolume_get_default (g, arg497);
  if (ret == -1)
    return -1;
  if (! (ret > 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_btrfs_subvolume_get_default_0", "ret > 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_btrfs_subvolume_get_default_1_skip (void);
static int test_btrfs_subvolume_get_default_1_perform (guestfs_h *);

static int
test_btrfs_subvolume_get_default_1 (guestfs_h *g)
{
  if (test_btrfs_subvolume_get_default_1_skip ()) {
    skipped ("test_btrfs_subvolume_get_default_1", "environment variable set");
    return 0;
  }

  const char *features499[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features499)) {
    skipped ("test_btrfs_subvolume_get_default_1", "group %s not available in daemon",
             features499[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_subvolume_get_default_1_perform (g);
}

static int
test_btrfs_subvolume_get_default_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "btrfs_subvolume_get_default") == NULL;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_GET_DEFAULT_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BTRFS_SUBVOLUME_GET_DEFAULT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_btrfs_subvolume_get_default_1_perform (guestfs_h *g)
{
  /* TestResult for btrfs_subvolume_get_default (1) */
  const char *arg500_0 = "/dev/sda1";
  const char *const arg500[] = {
    arg500_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs501;
  optargs501.bitmask = UINT64_C(0x0);
  int ret2;
  ret2 = guestfs_mkfs_btrfs_argv (g, (char **) arg500, &optargs501);
  if (ret2 == -1)
    return -1;
  const char *arg502 = "/dev/sda1";
  const char *arg503 = "/";
  int ret1;
  ret1 = guestfs_mount (g, arg502, arg503);
  if (ret1 == -1)
    return -1;
  const char *arg505 = "/";
  int64_t ret;
  ret = guestfs_btrfs_subvolume_get_default (g, arg505);
  if (ret == -1)
    return -1;
  if (! (ret > 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_btrfs_subvolume_get_default_1", "ret > 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_blockdev_setra_0_skip (void);
static int test_blockdev_setra_0_perform (guestfs_h *);

static int
test_blockdev_setra_0 (guestfs_h *g)
{
  if (test_blockdev_setra_0_skip ()) {
    skipped ("test_blockdev_setra_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_blockdev_setra_0_perform (g);
}

static int
test_blockdev_setra_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "blockdev_setra") == NULL;
  str = getenv ("SKIP_TEST_BLOCKDEV_SETRA_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BLOCKDEV_SETRA");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_blockdev_setra_0_perform (guestfs_h *g)
{
  /* TestRun for blockdev_setra (0) */
  const char *arg508 = "/dev/sda";
  int ret507;
  ret507 = guestfs_blockdev_setra (g, arg508, 1024);
  if (ret507 == -1)
    return -1;
  return 0;
}

static int test_lstatns_0_skip (void);
static int test_lstatns_0_perform (guestfs_h *);

static int
test_lstatns_0 (guestfs_h *g)
{
  if (test_lstatns_0_skip ()) {
    skipped ("test_lstatns_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_lstatns_0_perform (g);
}

static int
test_lstatns_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "lstatns") == NULL;
  str = getenv ("SKIP_TEST_LSTATNS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_LSTATNS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_lstatns_0_perform (guestfs_h *g)
{
  /* TestResult for lstatns (0) */
  const char *arg511 = "/empty";
  CLEANUP_FREE_STATNS struct guestfs_statns *ret;
  ret = guestfs_lstatns (g, arg511);
  if (ret == NULL)
      return -1;
  if (! (ret->st_size == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_lstatns_0", "ret->st_size == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_statns_0_skip (void);
static int test_statns_0_perform (guestfs_h *);

static int
test_statns_0 (guestfs_h *g)
{
  if (test_statns_0_skip ()) {
    skipped ("test_statns_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_statns_0_perform (g);
}

static int
test_statns_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "statns") == NULL;
  str = getenv ("SKIP_TEST_STATNS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_STATNS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_statns_0_perform (guestfs_h *g)
{
  /* TestResult for statns (0) */
  const char *arg513 = "/empty";
  CLEANUP_FREE_STATNS struct guestfs_statns *ret;
  ret = guestfs_statns (g, arg513);
  if (ret == NULL)
      return -1;
  if (! (ret->st_size == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_statns_0", "ret->st_size == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_aug_label_0_skip (void);
static int test_aug_label_0_perform (guestfs_h *);
static int test_aug_label_0_cleanup (guestfs_h *);

static int
test_aug_label_0 (guestfs_h *g)
{
  if (test_aug_label_0_skip ()) {
    skipped ("test_aug_label_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  int ret = test_aug_label_0_perform (g);
  if (test_aug_label_0_cleanup (g) == -1) {
    fprintf (stderr, "%s (%d): unexpected error during test cleanups\n",
             "aug_label", 0);
    return -1;
  }
  return ret;
}

static int
test_aug_label_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "aug_label") == NULL;
  str = getenv ("SKIP_TEST_AUG_LABEL_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_AUG_LABEL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_aug_label_0_perform (guestfs_h *g)
{
  /* TestResultString for aug_label (0) */
  const char *arg516 = "/etc";
  int ret515;
  ret515 = guestfs_mkdir (g, arg516);
  if (ret515 == -1)
    return -1;
  const char *arg519 = "/etc/passwd";
  const char *arg520 = "root:x:0:0:root:/root:/bin/bash\nbin:x:1:1:bin:/bin:/sbin/nologin\ndaemon:x:2:2:daemon:/sbin:/bin/csh\n";
  size_t arg520_size = 100;
  int ret518;
  ret518 = guestfs_write (g, arg519, arg520, arg520_size);
  if (ret518 == -1)
    return -1;
  const char *arg523 = "/";
  int ret522;
  ret522 = guestfs_aug_init (g, arg523, 0);
  if (ret522 == -1)
    return -1;
  const char *arg526 = "/files/etc/passwd/*[last()]";
  CLEANUP_FREE char *ret;
  ret = guestfs_aug_label (g, arg526);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "daemon")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_aug_label_0", "aug_label", "daemon", ret);
    return -1;
  }
  return 0;
}

static int
test_aug_label_0_cleanup (guestfs_h *g)
{
  int ret528;
  ret528 = guestfs_aug_close (g);
  if (ret528 == -1)
    return -1;
  return 0;
}

static int test_aug_setm_0_skip (void);
static int test_aug_setm_0_perform (guestfs_h *);
static int test_aug_setm_0_cleanup (guestfs_h *);

static int
test_aug_setm_0 (guestfs_h *g)
{
  if (test_aug_setm_0_skip ()) {
    skipped ("test_aug_setm_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  int ret = test_aug_setm_0_perform (g);
  if (test_aug_setm_0_cleanup (g) == -1) {
    fprintf (stderr, "%s (%d): unexpected error during test cleanups\n",
             "aug_setm", 0);
    return -1;
  }
  return ret;
}

static int
test_aug_setm_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "aug_setm") == NULL;
  str = getenv ("SKIP_TEST_AUG_SETM_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_AUG_SETM");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_aug_setm_0_perform (guestfs_h *g)
{
  /* TestResultString for aug_setm (0) */
  const char *arg531 = "/etc";
  int ret530;
  ret530 = guestfs_mkdir (g, arg531);
  if (ret530 == -1)
    return -1;
  const char *arg534 = "/etc/passwd";
  const char *arg535 = "root:x:0:0:root:/root:/bin/bash\nbin:x:1:1:bin:/bin:/sbin/nologin\ndaemon:x:2:2:daemon:/sbin:/bin/csh\n";
  size_t arg535_size = 100;
  int ret533;
  ret533 = guestfs_write (g, arg534, arg535, arg535_size);
  if (ret533 == -1)
    return -1;
  const char *arg538 = "/";
  int ret537;
  ret537 = guestfs_aug_init (g, arg538, 0);
  if (ret537 == -1)
    return -1;
  const char *arg542 = "/files/etc/passwd/*";
  const char *arg543 = "shell";
  const char *arg544 = "/sbin/nologin";
  int ret541;
  ret541 = guestfs_aug_setm (g, arg542, arg543, arg544);
  if (ret541 == -1)
    return -1;
  int ret546;
  ret546 = guestfs_aug_save (g);
  if (ret546 == -1)
    return -1;
  const char *arg548 = "/etc/passwd";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg548);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "root:x:0:0:root:/root:/sbin/nologin\nbin:x:1:1:bin:/bin:/sbin/nologin\ndaemon:x:2:2:daemon:/sbin:/sbin/nologin\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_aug_setm_0", "cat", "root:x:0:0:root:/root:/sbin/nologin\nbin:x:1:1:bin:/bin:/sbin/nologin\ndaemon:x:2:2:daemon:/sbin:/sbin/nologin\n", ret);
    return -1;
  }
  return 0;
}

static int
test_aug_setm_0_cleanup (guestfs_h *g)
{
  int ret550;
  ret550 = guestfs_aug_close (g);
  if (ret550 == -1)
    return -1;
  return 0;
}

static int test_set_uuid_0_skip (void);
static int test_set_uuid_0_perform (guestfs_h *);

static int
test_set_uuid_0 (guestfs_h *g)
{
  if (test_set_uuid_0_skip ()) {
    skipped ("test_set_uuid_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_set_uuid_0_perform (g);
}

static int
test_set_uuid_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_uuid") == NULL;
  str = getenv ("SKIP_TEST_SET_UUID_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_UUID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_set_uuid_0_perform (guestfs_h *g)
{
  /* TestResultString for set_uuid (0) */
  const char *arg553 = "/dev/sda1";
  const char *arg554 = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  int ret552;
  ret552 = guestfs_set_uuid (g, arg553, arg554);
  if (ret552 == -1)
    return -1;
  const char *arg556 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_uuid (g, arg556);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_uuid_0", "vfs_uuid", "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc", ret);
    return -1;
  }
  return 0;
}

static int test_remount_0_skip (void);
static int test_remount_0_perform (guestfs_h *);

static int
test_remount_0 (guestfs_h *g)
{
  if (test_remount_0_skip ()) {
    skipped ("test_remount_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_remount_0_perform (g);
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
test_remount_0_perform (guestfs_h *g)
{
  /* TestLastFail for remount (0) */
  const char *arg559 = "/";
  struct guestfs_remount_argv optargs560;
  optargs560.rw = 0;
  optargs560.bitmask = UINT64_C(0x1);
  int ret558;
  ret558 = guestfs_remount_argv (g, arg559, &optargs560);
  if (ret558 == -1)
    return -1;
  const char *arg562 = "/remount1";
  const char *arg563 = "data";
  size_t arg563_size = 4;
  int ret561;
  guestfs_push_error_handler (g, NULL, NULL);
  ret561 = guestfs_write (g, arg562, arg563, arg563_size);
  guestfs_pop_error_handler (g);
  if (ret561 != -1)
    return -1;
  return 0;
}

static int test_remount_1_skip (void);
static int test_remount_1_perform (guestfs_h *);

static int
test_remount_1 (guestfs_h *g)
{
  if (test_remount_1_skip ()) {
    skipped ("test_remount_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_remount_1_perform (g);
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
test_remount_1_perform (guestfs_h *g)
{
  /* TestRun for remount (1) */
  const char *arg566 = "/";
  struct guestfs_remount_argv optargs567;
  optargs567.rw = 0;
  optargs567.bitmask = UINT64_C(0x1);
  int ret565;
  ret565 = guestfs_remount_argv (g, arg566, &optargs567);
  if (ret565 == -1)
    return -1;
  const char *arg569 = "/";
  struct guestfs_remount_argv optargs570;
  optargs570.rw = 1;
  optargs570.bitmask = UINT64_C(0x1);
  int ret568;
  ret568 = guestfs_remount_argv (g, arg569, &optargs570);
  if (ret568 == -1)
    return -1;
  const char *arg572 = "/remount2";
  const char *arg573 = "data";
  size_t arg573_size = 4;
  int ret571;
  ret571 = guestfs_write (g, arg572, arg573, arg573_size);
  if (ret571 == -1)
    return -1;
  return 0;
}

static int test_cp_r_0_skip (void);
static int test_cp_r_0_perform (guestfs_h *);

static int
test_cp_r_0 (guestfs_h *g)
{
  if (test_cp_r_0_skip ()) {
    skipped ("test_cp_r_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_cp_r_0_perform (g);
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
test_cp_r_0_perform (guestfs_h *g)
{
  /* TestResultString for cp_r (0) */
  const char *arg576 = "/cp_r1";
  int ret575;
  ret575 = guestfs_mkdir (g, arg576);
  if (ret575 == -1)
    return -1;
  const char *arg579 = "/cp_r2";
  int ret578;
  ret578 = guestfs_mkdir (g, arg579);
  if (ret578 == -1)
    return -1;
  const char *arg582 = "/cp_r1/file";
  const char *arg583 = "file content";
  size_t arg583_size = 12;
  int ret581;
  ret581 = guestfs_write (g, arg582, arg583, arg583_size);
  if (ret581 == -1)
    return -1;
  const char *arg586 = "/cp_r1";
  const char *arg587 = "/cp_r2";
  int ret585;
  ret585 = guestfs_cp_r (g, arg586, arg587);
  if (ret585 == -1)
    return -1;
  const char *arg589 = "/cp_r2/cp_r1/file";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg589);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "file content")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_cp_r_0", "cat", "file content", ret);
    return -1;
  }
  return 0;
}

static int test_is_whole_device_0_skip (void);
static int test_is_whole_device_0_perform (guestfs_h *);

static int
test_is_whole_device_0 (guestfs_h *g)
{
  if (test_is_whole_device_0_skip ()) {
    skipped ("test_is_whole_device_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_is_whole_device_0_perform (g);
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
test_is_whole_device_0_perform (guestfs_h *g)
{
  /* TestResultTrue for is_whole_device (0) */
  const char *arg591 = "/dev/sda";
  int ret;
  ret = guestfs_is_whole_device (g, arg591);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_whole_device_0", "is_whole_device");
    return -1;
  }
  return 0;
}

static int test_is_whole_device_1_skip (void);
static int test_is_whole_device_1_perform (guestfs_h *);

static int
test_is_whole_device_1 (guestfs_h *g)
{
  if (test_is_whole_device_1_skip ()) {
    skipped ("test_is_whole_device_1", "environment variable set");
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_is_whole_device_1_perform (g);
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
test_is_whole_device_1_perform (guestfs_h *g)
{
  /* TestResultFalse for is_whole_device (1) */
  const char *arg593 = "/dev/sda1";
  int ret;
  ret = guestfs_is_whole_device (g, arg593);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_whole_device_1", "is_whole_device");
    return -1;
  }
  return 0;
}

static int test_is_whole_device_2_skip (void);
static int test_is_whole_device_2_perform (guestfs_h *);

static int
test_is_whole_device_2 (guestfs_h *g)
{
  if (test_is_whole_device_2_skip ()) {
    skipped ("test_is_whole_device_2", "environment variable set");
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  return test_is_whole_device_2_perform (g);
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
test_is_whole_device_2_perform (guestfs_h *g)
{
  /* TestResultFalse for is_whole_device (2) */
  const char *arg595 = "/dev/VG/LV";
  int ret;
  ret = guestfs_is_whole_device (g, arg595);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_whole_device_2", "is_whole_device");
    return -1;
  }
  return 0;
}

static int test_rename_0_skip (void);
static int test_rename_0_perform (guestfs_h *);

static int
test_rename_0 (guestfs_h *g)
{
  if (test_rename_0_skip ()) {
    skipped ("test_rename_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_rename_0_perform (g);
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
test_rename_0_perform (guestfs_h *g)
{
  /* TestResultFalse for rename (0) */
  const char *arg598 = "/rename";
  int ret597;
  ret597 = guestfs_mkdir (g, arg598);
  if (ret597 == -1)
    return -1;
  const char *arg601 = "/rename/old";
  const char *arg602 = "file content";
  size_t arg602_size = 12;
  int ret600;
  ret600 = guestfs_write (g, arg601, arg602, arg602_size);
  if (ret600 == -1)
    return -1;
  const char *arg605 = "/rename/old";
  const char *arg606 = "/rename/new";
  int ret604;
  ret604 = guestfs_rename (g, arg605, arg606);
  if (ret604 == -1)
    return -1;
  const char *arg608 = "/rename/old";
  struct guestfs_is_file_opts_argv optargs609;
  optargs609.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, arg608, &optargs609);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_rename_0", "is_file");
    return -1;
  }
  return 0;
}

static int test_part_get_gpt_type_0_skip (void);
static int test_part_get_gpt_type_0_perform (guestfs_h *);

static int
test_part_get_gpt_type_0 (guestfs_h *g)
{
  if (test_part_get_gpt_type_0_skip ()) {
    skipped ("test_part_get_gpt_type_0", "environment variable set");
    return 0;
  }

  const char *features610[] = { "gdisk", NULL };
  if (!guestfs_feature_available (g, (char **) features610)) {
    skipped ("test_part_get_gpt_type_0", "group %s not available in daemon",
             features610[0]);
    return 0;
  }

  if (init_gpt (g) == -1)
    return -1;

  return test_part_get_gpt_type_0_perform (g);
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
test_part_get_gpt_type_0_perform (guestfs_h *g)
{
  /* TestResultString for part_get_gpt_type (0) */
  const char *arg612 = "/dev/sda";
  const char *arg614 = "01234567-89AB-CDEF-0123-456789ABCDEF";
  int ret611;
  ret611 = guestfs_part_set_gpt_type (g, arg612, 1, arg614);
  if (ret611 == -1)
    return -1;
  const char *arg616 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_gpt_type (g, arg616, 1);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "01234567-89AB-CDEF-0123-456789ABCDEF")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_part_get_gpt_type_0", "part_get_gpt_type", "01234567-89AB-CDEF-0123-456789ABCDEF", ret);
    return -1;
  }
  return 0;
}

static int test_part_set_gpt_type_0_skip (void);
static int test_part_set_gpt_type_0_perform (guestfs_h *);

static int
test_part_set_gpt_type_0 (guestfs_h *g)
{
  if (test_part_set_gpt_type_0_skip ()) {
    skipped ("test_part_set_gpt_type_0", "environment variable set");
    return 0;
  }

  const char *features619[] = { "gdisk", NULL };
  if (!guestfs_feature_available (g, (char **) features619)) {
    skipped ("test_part_set_gpt_type_0", "group %s not available in daemon",
             features619[0]);
    return 0;
  }

  if (init_gpt (g) == -1)
    return -1;

  return test_part_set_gpt_type_0_perform (g);
}

static int
test_part_set_gpt_type_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_set_gpt_type") == NULL;
  str = getenv ("SKIP_TEST_PART_SET_GPT_TYPE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_SET_GPT_TYPE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_set_gpt_type_0_perform (guestfs_h *g)
{
  /* TestLastFail for part_set_gpt_type (0) */
  const char *arg621 = "/dev/sda";
  const char *arg623 = "f";
  int ret620;
  guestfs_push_error_handler (g, NULL, NULL);
  ret620 = guestfs_part_set_gpt_type (g, arg621, 1, arg623);
  guestfs_pop_error_handler (g);
  if (ret620 != -1)
    return -1;
  return 0;
}

static int test_part_set_gpt_type_1_skip (void);
static int test_part_set_gpt_type_1_perform (guestfs_h *);

static int
test_part_set_gpt_type_1 (guestfs_h *g)
{
  if (test_part_set_gpt_type_1_skip ()) {
    skipped ("test_part_set_gpt_type_1", "environment variable set");
    return 0;
  }

  const char *features625[] = { "gdisk", NULL };
  if (!guestfs_feature_available (g, (char **) features625)) {
    skipped ("test_part_set_gpt_type_1", "group %s not available in daemon",
             features625[0]);
    return 0;
  }

  if (init_gpt (g) == -1)
    return -1;

  return test_part_set_gpt_type_1_perform (g);
}

static int
test_part_set_gpt_type_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "part_set_gpt_type") == NULL;
  str = getenv ("SKIP_TEST_PART_SET_GPT_TYPE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_PART_SET_GPT_TYPE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_part_set_gpt_type_1_perform (guestfs_h *g)
{
  /* TestResultString for part_set_gpt_type (1) */
  const char *arg627 = "/dev/sda";
  const char *arg629 = "01234567-89AB-CDEF-0123-456789ABCDEF";
  int ret626;
  ret626 = guestfs_part_set_gpt_type (g, arg627, 1, arg629);
  if (ret626 == -1)
    return -1;
  const char *arg631 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_gpt_type (g, arg631, 1);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "01234567-89AB-CDEF-0123-456789ABCDEF")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_part_set_gpt_type_1", "part_get_gpt_type", "01234567-89AB-CDEF-0123-456789ABCDEF", ret);
    return -1;
  }
  return 0;
}

static int test_cap_set_file_0_skip (void);
static int test_cap_set_file_0_perform (guestfs_h *);

static int
test_cap_set_file_0 (guestfs_h *g)
{
  if (test_cap_set_file_0_skip ()) {
    skipped ("test_cap_set_file_0", "environment variable set");
    return 0;
  }

  const char *features634[] = { "linuxcaps", NULL };
  if (!guestfs_feature_available (g, (char **) features634)) {
    skipped ("test_cap_set_file_0", "group %s not available in daemon",
             features634[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_cap_set_file_0_perform (g);
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
test_cap_set_file_0_perform (guestfs_h *g)
{
  /* TestResultString for cap_set_file (0) */
  const char *arg636 = "/cap_set_file_0";
  int ret635;
  ret635 = guestfs_touch (g, arg636);
  if (ret635 == -1)
    return -1;
  const char *arg639 = "/cap_set_file_0";
  const char *arg640 = "cap_chown=p cap_chown+e";
  int ret638;
  ret638 = guestfs_cap_set_file (g, arg639, arg640);
  if (ret638 == -1)
    return -1;
  const char *arg642 = "/cap_set_file_0";
  CLEANUP_FREE char *ret;
  ret = guestfs_cap_get_file (g, arg642);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "= cap_chown+ep")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_cap_set_file_0", "cap_get_file", "= cap_chown+ep", ret);
    return -1;
  }
  return 0;
}

static int test_acl_delete_def_file_0_skip (void);

static int
test_acl_delete_def_file_0 (guestfs_h *g)
{
  if (test_acl_delete_def_file_0_skip ()) {
    skipped ("test_acl_delete_def_file_0", "environment variable set");
    return 0;
  }

  const char *features644[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) features644)) {
    skipped ("test_acl_delete_def_file_0", "group %s not available in daemon",
             features644[0]);
    return 0;
  }

  skipped ("test_acl_delete_def_file_0", "test disabled in generator");
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

static int test_acl_delete_def_file_1_skip (void);
static int test_acl_delete_def_file_1_perform (guestfs_h *);

static int
test_acl_delete_def_file_1 (guestfs_h *g)
{
  if (test_acl_delete_def_file_1_skip ()) {
    skipped ("test_acl_delete_def_file_1", "environment variable set");
    return 0;
  }

  const char *features645[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) features645)) {
    skipped ("test_acl_delete_def_file_1", "group %s not available in daemon",
             features645[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_acl_delete_def_file_1_perform (g);
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
test_acl_delete_def_file_1_perform (guestfs_h *g)
{
  /* TestRun for acl_delete_def_file (1) */
  const char *arg647 = "/acl_delete_def_file_1";
  int ret646;
  ret646 = guestfs_mkdir (g, arg647);
  if (ret646 == -1)
    return -1;
  const char *arg650 = "/acl_delete_def_file_1";
  const char *arg651 = "default";
  const char *arg652 = "user::r-x,group::r-x,other::r-x";
  int ret649;
  ret649 = guestfs_acl_set_file (g, arg650, arg651, arg652);
  if (ret649 == -1)
    return -1;
  const char *arg655 = "/acl_delete_def_file_1";
  int ret654;
  ret654 = guestfs_acl_delete_def_file (g, arg655);
  if (ret654 == -1)
    return -1;
  return 0;
}

static int test_acl_set_file_0_skip (void);
static int test_acl_set_file_0_perform (guestfs_h *);

static int
test_acl_set_file_0 (guestfs_h *g)
{
  if (test_acl_set_file_0_skip ()) {
    skipped ("test_acl_set_file_0", "environment variable set");
    return 0;
  }

  const char *features657[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) features657)) {
    skipped ("test_acl_set_file_0", "group %s not available in daemon",
             features657[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_acl_set_file_0_perform (g);
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
test_acl_set_file_0_perform (guestfs_h *g)
{
  /* TestRun for acl_set_file (0) */
  const char *arg659 = "/acl_set_file_0";
  int ret658;
  ret658 = guestfs_touch (g, arg659);
  if (ret658 == -1)
    return -1;
  const char *arg662 = "/acl_set_file_0";
  const char *arg663 = "access";
  const char *arg664 = "u::r-x,g::r-x,o::r-x";
  int ret661;
  ret661 = guestfs_acl_set_file (g, arg662, arg663, arg664);
  if (ret661 == -1)
    return -1;
  const char *arg667 = "/acl_set_file_0";
  const char *arg668 = "access";
  CLEANUP_FREE char *ret666;
  ret666 = guestfs_acl_get_file (g, arg667, arg668);
  if (ret666 == NULL)
      return -1;
  return 0;
}

static int test_acl_set_file_1_skip (void);
static int test_acl_set_file_1_perform (guestfs_h *);

static int
test_acl_set_file_1 (guestfs_h *g)
{
  if (test_acl_set_file_1_skip ()) {
    skipped ("test_acl_set_file_1", "environment variable set");
    return 0;
  }

  const char *features670[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) features670)) {
    skipped ("test_acl_set_file_1", "group %s not available in daemon",
             features670[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_acl_set_file_1_perform (g);
}

static int
test_acl_set_file_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "acl_set_file") == NULL;
  str = getenv ("SKIP_TEST_ACL_SET_FILE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ACL_SET_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_acl_set_file_1_perform (guestfs_h *g)
{
  /* TestRun for acl_set_file (1) */
  const char *arg672 = "/acl_set_file_1";
  int ret671;
  ret671 = guestfs_touch (g, arg672);
  if (ret671 == -1)
    return -1;
  const char *arg675 = "/acl_set_file_1";
  const char *arg676 = "access";
  const char *arg677 = "u::r-x,g::r-x,o::r-x,m::rwx,u:500:rw,g:600:x";
  int ret674;
  ret674 = guestfs_acl_set_file (g, arg675, arg676, arg677);
  if (ret674 == -1)
    return -1;
  return 0;
}

static int test_acl_set_file_2_skip (void);
static int test_acl_set_file_2_perform (guestfs_h *);

static int
test_acl_set_file_2 (guestfs_h *g)
{
  if (test_acl_set_file_2_skip ()) {
    skipped ("test_acl_set_file_2", "environment variable set");
    return 0;
  }

  const char *features679[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) features679)) {
    skipped ("test_acl_set_file_2", "group %s not available in daemon",
             features679[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_acl_set_file_2_perform (g);
}

static int
test_acl_set_file_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "acl_set_file") == NULL;
  str = getenv ("SKIP_TEST_ACL_SET_FILE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ACL_SET_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_acl_set_file_2_perform (guestfs_h *g)
{
  /* TestLastFail for acl_set_file (2) */
  const char *arg681 = "/acl_set_file_2";
  int ret680;
  ret680 = guestfs_touch (g, arg681);
  if (ret680 == -1)
    return -1;
  const char *arg684 = "/acl_set_file_2";
  const char *arg685 = "access";
  const char *arg686 = "u::r-x,g::r-x,o::r-x,u:500:rw,g:600:x";
  int ret683;
  guestfs_push_error_handler (g, NULL, NULL);
  ret683 = guestfs_acl_set_file (g, arg684, arg685, arg686);
  guestfs_pop_error_handler (g);
  if (ret683 != -1)
    return -1;
  return 0;
}

static int test_acl_set_file_3_skip (void);
static int test_acl_set_file_3_perform (guestfs_h *);

static int
test_acl_set_file_3 (guestfs_h *g)
{
  if (test_acl_set_file_3_skip ()) {
    skipped ("test_acl_set_file_3", "environment variable set");
    return 0;
  }

  const char *features688[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) features688)) {
    skipped ("test_acl_set_file_3", "group %s not available in daemon",
             features688[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_acl_set_file_3_perform (g);
}

static int
test_acl_set_file_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "acl_set_file") == NULL;
  str = getenv ("SKIP_TEST_ACL_SET_FILE_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ACL_SET_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_acl_set_file_3_perform (guestfs_h *g)
{
  /* TestLastFail for acl_set_file (3) */
  const char *arg690 = "/acl_set_file_3";
  int ret689;
  ret689 = guestfs_touch (g, arg690);
  if (ret689 == -1)
    return -1;
  const char *arg693 = "/acl_set_file_3";
  const char *arg694 = "access";
  const char *arg695 = "u::r-x,g::r-x,o::r-x,m::rwx,u:notauser:rw";
  int ret692;
  guestfs_push_error_handler (g, NULL, NULL);
  ret692 = guestfs_acl_set_file (g, arg693, arg694, arg695);
  guestfs_pop_error_handler (g);
  if (ret692 != -1)
    return -1;
  return 0;
}

static int test_acl_set_file_4_skip (void);
static int test_acl_set_file_4_perform (guestfs_h *);

static int
test_acl_set_file_4 (guestfs_h *g)
{
  if (test_acl_set_file_4_skip ()) {
    skipped ("test_acl_set_file_4", "environment variable set");
    return 0;
  }

  const char *features697[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) features697)) {
    skipped ("test_acl_set_file_4", "group %s not available in daemon",
             features697[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_acl_set_file_4_perform (g);
}

static int
test_acl_set_file_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "acl_set_file") == NULL;
  str = getenv ("SKIP_TEST_ACL_SET_FILE_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ACL_SET_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_acl_set_file_4_perform (guestfs_h *g)
{
  /* TestLastFail for acl_set_file (4) */
  const char *arg699 = "/acl_set_file_4";
  int ret698;
  ret698 = guestfs_touch (g, arg699);
  if (ret698 == -1)
    return -1;
  const char *arg702 = "/acl_set_file_4";
  const char *arg703 = "default";
  const char *arg704 = "u::r-x,g::r-x,o::r-x";
  int ret701;
  guestfs_push_error_handler (g, NULL, NULL);
  ret701 = guestfs_acl_set_file (g, arg702, arg703, arg704);
  guestfs_pop_error_handler (g);
  if (ret701 != -1)
    return -1;
  return 0;
}

static int test_acl_set_file_5_skip (void);
static int test_acl_set_file_5_perform (guestfs_h *);

static int
test_acl_set_file_5 (guestfs_h *g)
{
  if (test_acl_set_file_5_skip ()) {
    skipped ("test_acl_set_file_5", "environment variable set");
    return 0;
  }

  const char *features706[] = { "acl", NULL };
  if (!guestfs_feature_available (g, (char **) features706)) {
    skipped ("test_acl_set_file_5", "group %s not available in daemon",
             features706[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_acl_set_file_5_perform (g);
}

static int
test_acl_set_file_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "acl_set_file") == NULL;
  str = getenv ("SKIP_TEST_ACL_SET_FILE_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ACL_SET_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_acl_set_file_5_perform (guestfs_h *g)
{
  /* TestRun for acl_set_file (5) */
  const char *arg708 = "/acl_set_file_5";
  int ret707;
  ret707 = guestfs_mkdir (g, arg708);
  if (ret707 == -1)
    return -1;
  const char *arg711 = "/acl_set_file_5";
  const char *arg712 = "default";
  const char *arg713 = "u::r-x,g::r-x,o::r-x";
  int ret710;
  ret710 = guestfs_acl_set_file (g, arg711, arg712, arg713);
  if (ret710 == -1)
    return -1;
  return 0;
}

static int test_mklost_and_found_0_skip (void);
static int test_mklost_and_found_0_perform (guestfs_h *);

static int
test_mklost_and_found_0 (guestfs_h *g)
{
  if (test_mklost_and_found_0_skip ()) {
    skipped ("test_mklost_and_found_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_mklost_and_found_0_perform (g);
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
test_mklost_and_found_0_perform (guestfs_h *g)
{
  /* TestRun for mklost_and_found (0) */
  const char *arg716 = "/lost+found";
  int ret715;
  ret715 = guestfs_rm_rf (g, arg716);
  if (ret715 == -1)
    return -1;
  const char *arg719 = "/";
  int ret718;
  ret718 = guestfs_mklost_and_found (g, arg719);
  if (ret718 == -1)
    return -1;
  return 0;
}

static int test_mktemp_0_skip (void);
static int test_mktemp_0_perform (guestfs_h *);

static int
test_mktemp_0 (guestfs_h *g)
{
  if (test_mktemp_0_skip ()) {
    skipped ("test_mktemp_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mktemp_0_perform (g);
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
test_mktemp_0_perform (guestfs_h *g)
{
  /* TestRun for mktemp (0) */
  const char *arg722 = "/mktemp";
  int ret721;
  ret721 = guestfs_mkdir (g, arg722);
  if (ret721 == -1)
    return -1;
  const char *arg725 = "/mktemp/tmpXXXXXX";
  struct guestfs_mktemp_argv optargs726;
  optargs726.bitmask = UINT64_C(0x0);
  CLEANUP_FREE char *ret724;
  ret724 = guestfs_mktemp_argv (g, arg725, &optargs726);
  if (ret724 == NULL)
      return -1;
  const char *arg728 = "/mktemp/tmpXXXXXX";
  struct guestfs_mktemp_argv optargs729;
  optargs729.suffix = "suff";
  optargs729.bitmask = UINT64_C(0x1);
  CLEANUP_FREE char *ret727;
  ret727 = guestfs_mktemp_argv (g, arg728, &optargs729);
  if (ret727 == NULL)
      return -1;
  return 0;
}

static int test_mke2fs_0_skip (void);
static int test_mke2fs_0_perform (guestfs_h *);

static int
test_mke2fs_0 (guestfs_h *g)
{
  if (test_mke2fs_0_skip ()) {
    skipped ("test_mke2fs_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mke2fs_0_perform (g);
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
test_mke2fs_0_perform (guestfs_h *g)
{
  /* TestResultString for mke2fs (0) */
  const char *arg731 = "/dev/sda";
  const char *arg732 = "mbr";
  int ret730;
  ret730 = guestfs_part_init (g, arg731, arg732);
  if (ret730 == -1)
    return -1;
  const char *arg735 = "/dev/sda";
  const char *arg736 = "p";
  int ret734;
  ret734 = guestfs_part_add (g, arg735, arg736, 64, 204799);
  if (ret734 == -1)
    return -1;
  const char *arg741 = "/dev/sda";
  const char *arg742 = "p";
  int ret740;
  ret740 = guestfs_part_add (g, arg741, arg742, 204800, -64);
  if (ret740 == -1)
    return -1;
  const char *arg747 = "/dev/sda1";
  struct guestfs_mke2fs_argv optargs748;
  optargs748.blocksize = 4096;
  optargs748.journaldev = 1;
  optargs748.bitmask = UINT64_C(0x100000002);
  int ret746;
  ret746 = guestfs_mke2fs_argv (g, arg747, &optargs748);
  if (ret746 == -1)
    return -1;
  const char *arg750 = "/dev/sda2";
  struct guestfs_mke2fs_argv optargs751;
  optargs751.blocksize = 4096;
  optargs751.journaldevice = "/dev/sda1";
  optargs751.fstype = "ext2";
  optargs751.bitmask = UINT64_C(0x44002);
  int ret749;
  ret749 = guestfs_mke2fs_argv (g, arg750, &optargs751);
  if (ret749 == -1)
    return -1;
  const char *arg753 = "/dev/sda2";
  const char *arg754 = "/";
  int ret752;
  ret752 = guestfs_mount (g, arg753, arg754);
  if (ret752 == -1)
    return -1;
  const char *arg757 = "/new";
  const char *arg758 = "new file contents";
  size_t arg758_size = 17;
  int ret756;
  ret756 = guestfs_write (g, arg757, arg758, arg758_size);
  if (ret756 == -1)
    return -1;
  const char *arg760 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg760);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mke2fs_0", "cat", "new file contents", ret);
    return -1;
  }
  return 0;
}

static int test_mke2fs_1_skip (void);
static int test_mke2fs_1_perform (guestfs_h *);

static int
test_mke2fs_1 (guestfs_h *g)
{
  if (test_mke2fs_1_skip ()) {
    skipped ("test_mke2fs_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mke2fs_1_perform (g);
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
test_mke2fs_1_perform (guestfs_h *g)
{
  /* TestResultString for mke2fs (1) */
  const char *arg763 = "/dev/sda";
  const char *arg764 = "mbr";
  int ret762;
  ret762 = guestfs_part_init (g, arg763, arg764);
  if (ret762 == -1)
    return -1;
  const char *arg767 = "/dev/sda";
  const char *arg768 = "p";
  int ret766;
  ret766 = guestfs_part_add (g, arg767, arg768, 64, 204799);
  if (ret766 == -1)
    return -1;
  const char *arg773 = "/dev/sda";
  const char *arg774 = "p";
  int ret772;
  ret772 = guestfs_part_add (g, arg773, arg774, 204800, -64);
  if (ret772 == -1)
    return -1;
  const char *arg779 = "/dev/sda1";
  struct guestfs_mke2fs_argv optargs780;
  optargs780.blocksize = 4096;
  optargs780.journaldevice = "/dev/sda1";
  optargs780.label = "JOURNAL";
  optargs780.fstype = "ext2";
  optargs780.journaldev = 1;
  optargs780.bitmask = UINT64_C(0x10004c002);
  int ret778;
  ret778 = guestfs_mke2fs_argv (g, arg779, &optargs780);
  if (ret778 == -1)
    return -1;
  const char *arg782 = "/dev/sda2";
  struct guestfs_mke2fs_argv optargs783;
  optargs783.blocksize = 4096;
  optargs783.journaldevice = "LABEL=JOURNAL";
  optargs783.label = "JOURNAL";
  optargs783.fstype = "ext2";
  optargs783.bitmask = UINT64_C(0x4c002);
  int ret781;
  ret781 = guestfs_mke2fs_argv (g, arg782, &optargs783);
  if (ret781 == -1)
    return -1;
  const char *arg785 = "/dev/sda2";
  const char *arg786 = "/";
  int ret784;
  ret784 = guestfs_mount (g, arg785, arg786);
  if (ret784 == -1)
    return -1;
  const char *arg789 = "/new";
  const char *arg790 = "new file contents";
  size_t arg790_size = 17;
  int ret788;
  ret788 = guestfs_write (g, arg789, arg790, arg790_size);
  if (ret788 == -1)
    return -1;
  const char *arg792 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg792);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mke2fs_1", "cat", "new file contents", ret);
    return -1;
  }
  return 0;
}

static int test_mke2fs_2_skip (void);
static int test_mke2fs_2_perform (guestfs_h *);

static int
test_mke2fs_2 (guestfs_h *g)
{
  if (test_mke2fs_2_skip ()) {
    skipped ("test_mke2fs_2", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mke2fs_2_perform (g);
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
test_mke2fs_2_perform (guestfs_h *g)
{
  /* TestResultString for mke2fs (2) */
  const char *arg795 = "/dev/sda";
  const char *arg796 = "mbr";
  int ret794;
  ret794 = guestfs_part_init (g, arg795, arg796);
  if (ret794 == -1)
    return -1;
  const char *arg799 = "/dev/sda";
  const char *arg800 = "p";
  int ret798;
  ret798 = guestfs_part_add (g, arg799, arg800, 64, 204799);
  if (ret798 == -1)
    return -1;
  const char *arg805 = "/dev/sda";
  const char *arg806 = "p";
  int ret804;
  ret804 = guestfs_part_add (g, arg805, arg806, 204800, -64);
  if (ret804 == -1)
    return -1;
  const char *arg811 = "/dev/sda1";
  struct guestfs_mke2fs_argv optargs812;
  optargs812.blocksize = 4096;
  optargs812.uuid = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  optargs812.journaldev = 1;
  optargs812.bitmask = UINT64_C(0x100100002);
  int ret810;
  ret810 = guestfs_mke2fs_argv (g, arg811, &optargs812);
  if (ret810 == -1)
    return -1;
  const char *arg814 = "/dev/sda2";
  struct guestfs_mke2fs_argv optargs815;
  optargs815.blocksize = 4096;
  optargs815.journaldevice = "UUID=01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  optargs815.label = "JOURNAL";
  optargs815.fstype = "ext2";
  optargs815.forcecreate = 1;
  optargs815.bitmask = UINT64_C(0x24c002);
  int ret813;
  ret813 = guestfs_mke2fs_argv (g, arg814, &optargs815);
  if (ret813 == -1)
    return -1;
  const char *arg817 = "/dev/sda2";
  const char *arg818 = "/";
  int ret816;
  ret816 = guestfs_mount (g, arg817, arg818);
  if (ret816 == -1)
    return -1;
  const char *arg821 = "/new";
  const char *arg822 = "new file contents";
  size_t arg822_size = 17;
  int ret820;
  ret820 = guestfs_write (g, arg821, arg822, arg822_size);
  if (ret820 == -1)
    return -1;
  const char *arg824 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg824);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mke2fs_2", "cat", "new file contents", ret);
    return -1;
  }
  return 0;
}

static int test_rm_f_0_skip (void);
static int test_rm_f_0_perform (guestfs_h *);

static int
test_rm_f_0 (guestfs_h *g)
{
  if (test_rm_f_0_skip ()) {
    skipped ("test_rm_f_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_rm_f_0_perform (g);
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
test_rm_f_0_perform (guestfs_h *g)
{
  /* TestResultFalse for rm_f (0) */
  const char *arg827 = "/rm_f";
  int ret826;
  ret826 = guestfs_mkdir (g, arg827);
  if (ret826 == -1)
    return -1;
  const char *arg830 = "/rm_f/foo";
  int ret829;
  ret829 = guestfs_touch (g, arg830);
  if (ret829 == -1)
    return -1;
  const char *arg833 = "/rm_f/foo";
  int ret832;
  ret832 = guestfs_rm_f (g, arg833);
  if (ret832 == -1)
    return -1;
  const char *arg836 = "/rm_f/not_exists";
  int ret835;
  ret835 = guestfs_rm_f (g, arg836);
  if (ret835 == -1)
    return -1;
  const char *arg838 = "/rm_f/foo";
  int ret;
  ret = guestfs_exists (g, arg838);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_rm_f_0", "exists");
    return -1;
  }
  return 0;
}

static int test_rm_f_1_skip (void);
static int test_rm_f_1_perform (guestfs_h *);

static int
test_rm_f_1 (guestfs_h *g)
{
  if (test_rm_f_1_skip ()) {
    skipped ("test_rm_f_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_rm_f_1_perform (g);
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
test_rm_f_1_perform (guestfs_h *g)
{
  /* TestLastFail for rm_f (1) */
  const char *arg841 = "/rm_f2";
  int ret840;
  ret840 = guestfs_mkdir (g, arg841);
  if (ret840 == -1)
    return -1;
  const char *arg844 = "/rm_f2/foo";
  int ret843;
  ret843 = guestfs_mkdir (g, arg844);
  if (ret843 == -1)
    return -1;
  const char *arg847 = "/rm_f2/foo";
  int ret846;
  guestfs_push_error_handler (g, NULL, NULL);
  ret846 = guestfs_rm_f (g, arg847);
  guestfs_pop_error_handler (g);
  if (ret846 != -1)
    return -1;
  return 0;
}

static int test_xfs_repair_0_skip (void);
static int test_xfs_repair_0_perform (guestfs_h *);

static int
test_xfs_repair_0 (guestfs_h *g)
{
  if (test_xfs_repair_0_skip ()) {
    skipped ("test_xfs_repair_0", "environment variable set");
    return 0;
  }

  const char *features849[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) features849)) {
    skipped ("test_xfs_repair_0", "group %s not available in daemon",
             features849[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_xfs_repair_0_perform (g);
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
test_xfs_repair_0_perform (guestfs_h *g)
{
  /* TestRun for xfs_repair (0) */
  const char *arg851 = "/dev/sda";
  const char *arg852 = "mbr";
  int ret850;
  ret850 = guestfs_part_disk (g, arg851, arg852);
  if (ret850 == -1)
    return -1;
  const char *arg855 = "xfs";
  const char *arg856 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs857;
  optargs857.bitmask = UINT64_C(0x0);
  int ret854;
  ret854 = guestfs_mkfs_opts_argv (g, arg855, arg856, &optargs857);
  if (ret854 == -1)
    return -1;
  const char *arg859 = "/dev/sda1";
  struct guestfs_xfs_repair_argv optargs860;
  optargs860.nomodify = 1;
  optargs860.bitmask = UINT64_C(0x2);
  int ret858;
  ret858 = guestfs_xfs_repair_argv (g, arg859, &optargs860);
  if (ret858 == -1)
    return -1;
  return 0;
}

static int test_hivex_commit_0_skip (void);
static int test_hivex_commit_0_perform (guestfs_h *);
static int test_hivex_commit_0_cleanup (guestfs_h *);

static int
test_hivex_commit_0 (guestfs_h *g)
{
  if (test_hivex_commit_0_skip ()) {
    skipped ("test_hivex_commit_0", "environment variable set");
    return 0;
  }

  const char *features861[] = { "hivex", NULL };
  if (!guestfs_feature_available (g, (char **) features861)) {
    skipped ("test_hivex_commit_0", "group %s not available in daemon",
             features861[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  int ret = test_hivex_commit_0_perform (g);
  if (test_hivex_commit_0_cleanup (g) == -1) {
    fprintf (stderr, "%s (%d): unexpected error during test cleanups\n",
             "hivex_commit", 0);
    return -1;
  }
  return ret;
}

static int
test_hivex_commit_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "hivex_commit") == NULL;
  str = getenv ("SKIP_TEST_HIVEX_COMMIT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_HIVEX_COMMIT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_hivex_commit_0_perform (guestfs_h *g)
{
  /* TestRun for hivex_commit (0) */
  CLEANUP_FREE char *arg863 = substitute_srcdir ("$srcdir/../../test-data/files/minimal");
  const char *arg864 = "/hivex_commit1";
  int ret862;
  ret862 = guestfs_upload (g, arg863, arg864);
  if (ret862 == -1)
    return -1;
  const char *arg867 = "/hivex_commit1";
  struct guestfs_hivex_open_argv optargs868;
  optargs868.write = 1;
  optargs868.bitmask = UINT64_C(0x4);
  int ret866;
  ret866 = guestfs_hivex_open_argv (g, arg867, &optargs868);
  if (ret866 == -1)
    return -1;
  int ret869;
  ret869 = guestfs_hivex_commit (g, NULL);
  if (ret869 == -1)
    return -1;
  return 0;
}

static int
test_hivex_commit_0_cleanup (guestfs_h *g)
{
  int ret872;
  ret872 = guestfs_hivex_close (g);
  if (ret872 == -1)
    return -1;
  return 0;
}

static int test_hivex_commit_1_skip (void);
static int test_hivex_commit_1_perform (guestfs_h *);
static int test_hivex_commit_1_cleanup (guestfs_h *);

static int
test_hivex_commit_1 (guestfs_h *g)
{
  if (test_hivex_commit_1_skip ()) {
    skipped ("test_hivex_commit_1", "environment variable set");
    return 0;
  }

  const char *features874[] = { "hivex", NULL };
  if (!guestfs_feature_available (g, (char **) features874)) {
    skipped ("test_hivex_commit_1", "group %s not available in daemon",
             features874[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  int ret = test_hivex_commit_1_perform (g);
  if (test_hivex_commit_1_cleanup (g) == -1) {
    fprintf (stderr, "%s (%d): unexpected error during test cleanups\n",
             "hivex_commit", 1);
    return -1;
  }
  return ret;
}

static int
test_hivex_commit_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "hivex_commit") == NULL;
  str = getenv ("SKIP_TEST_HIVEX_COMMIT_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_HIVEX_COMMIT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_hivex_commit_1_perform (guestfs_h *g)
{
  /* TestResultTrue for hivex_commit (1) */
  CLEANUP_FREE char *arg876 = substitute_srcdir ("$srcdir/../../test-data/files/minimal");
  const char *arg877 = "/hivex_commit2";
  int ret875;
  ret875 = guestfs_upload (g, arg876, arg877);
  if (ret875 == -1)
    return -1;
  const char *arg880 = "/hivex_commit2";
  struct guestfs_hivex_open_argv optargs881;
  optargs881.write = 1;
  optargs881.bitmask = UINT64_C(0x4);
  int ret879;
  ret879 = guestfs_hivex_open_argv (g, arg880, &optargs881);
  if (ret879 == -1)
    return -1;
  const char *arg883 = "/hivex_commit2_copy";
  int ret882;
  ret882 = guestfs_hivex_commit (g, arg883);
  if (ret882 == -1)
    return -1;
  const char *arg885 = "/hivex_commit2_copy";
  struct guestfs_is_file_opts_argv optargs886;
  optargs886.followsymlinks = 0;
  optargs886.bitmask = UINT64_C(0x1);
  int ret;
  ret = guestfs_is_file_opts_argv (g, arg885, &optargs886);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_hivex_commit_1", "is_file");
    return -1;
  }
  return 0;
}

static int
test_hivex_commit_1_cleanup (guestfs_h *g)
{
  int ret887;
  ret887 = guestfs_hivex_close (g);
  if (ret887 == -1)
    return -1;
  return 0;
}

static int test_hivex_open_0_skip (void);
static int test_hivex_open_0_perform (guestfs_h *);
static int test_hivex_open_0_cleanup (guestfs_h *);

static int
test_hivex_open_0 (guestfs_h *g)
{
  if (test_hivex_open_0_skip ()) {
    skipped ("test_hivex_open_0", "environment variable set");
    return 0;
  }

  const char *features889[] = { "hivex", NULL };
  if (!guestfs_feature_available (g, (char **) features889)) {
    skipped ("test_hivex_open_0", "group %s not available in daemon",
             features889[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  int ret = test_hivex_open_0_perform (g);
  if (test_hivex_open_0_cleanup (g) == -1) {
    fprintf (stderr, "%s (%d): unexpected error during test cleanups\n",
             "hivex_open", 0);
    return -1;
  }
  return ret;
}

static int
test_hivex_open_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "hivex_open") == NULL;
  str = getenv ("SKIP_TEST_HIVEX_OPEN_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_HIVEX_OPEN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_hivex_open_0_perform (guestfs_h *g)
{
  /* TestRun for hivex_open (0) */
  CLEANUP_FREE char *arg891 = substitute_srcdir ("$srcdir/../../test-data/files/minimal");
  const char *arg892 = "/hivex_open";
  int ret890;
  ret890 = guestfs_upload (g, arg891, arg892);
  if (ret890 == -1)
    return -1;
  const char *arg895 = "/hivex_open";
  struct guestfs_hivex_open_argv optargs896;
  optargs896.write = 0;
  optargs896.bitmask = UINT64_C(0x4);
  int ret894;
  ret894 = guestfs_hivex_open_argv (g, arg895, &optargs896);
  if (ret894 == -1)
    return -1;
  int64_t ret897;
  ret897 = guestfs_hivex_root (g);
  if (ret897 == -1)
    return -1;
  CLEANUP_FREE char *ret899;
  ret899 = guestfs_hivex_node_name (g, 4128);
  if (ret899 == NULL)
      return -1;
  CLEANUP_FREE_HIVEX_NODE_LIST struct guestfs_hivex_node_list *ret902;
  ret902 = guestfs_hivex_node_children (g, 4128);
  if (ret902 == NULL)
      return -1;
  CLEANUP_FREE_HIVEX_VALUE_LIST struct guestfs_hivex_value_list *ret905;
  ret905 = guestfs_hivex_node_values (g, 4128);
  if (ret905 == NULL)
      return -1;
  return 0;
}

static int
test_hivex_open_0_cleanup (guestfs_h *g)
{
  int ret908;
  ret908 = guestfs_hivex_close (g);
  if (ret908 == -1)
    return -1;
  return 0;
}

static int test_xfs_admin_0_skip (void);
static int test_xfs_admin_0_perform (guestfs_h *);

static int
test_xfs_admin_0 (guestfs_h *g)
{
  if (test_xfs_admin_0_skip ()) {
    skipped ("test_xfs_admin_0", "environment variable set");
    return 0;
  }

  const char *features910[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) features910)) {
    skipped ("test_xfs_admin_0", "group %s not available in daemon",
             features910[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_xfs_admin_0_perform (g);
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
test_xfs_admin_0_perform (guestfs_h *g)
{
  /* TestResult for xfs_admin (0) */
  const char *arg911 = "/dev/sda";
  const char *arg912 = "mbr";
  int ret4;
  ret4 = guestfs_part_disk (g, arg911, arg912);
  if (ret4 == -1)
    return -1;
  const char *arg914 = "xfs";
  const char *arg915 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs916;
  optargs916.bitmask = UINT64_C(0x0);
  int ret3;
  ret3 = guestfs_mkfs_opts_argv (g, arg914, arg915, &optargs916);
  if (ret3 == -1)
    return -1;
  const char *arg917 = "/dev/sda1";
  struct guestfs_xfs_admin_argv optargs918;
  optargs918.lazycounter = 0;
  optargs918.bitmask = UINT64_C(0x10);
  int ret2;
  ret2 = guestfs_xfs_admin_argv (g, arg917, &optargs918);
  if (ret2 == -1)
    return -1;
  const char *arg919 = "/dev/sda1";
  const char *arg920 = "/";
  int ret1;
  ret1 = guestfs_mount (g, arg919, arg920);
  if (ret1 == -1)
    return -1;
  const char *arg922 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, arg922);
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

static int test_xfs_admin_1_skip (void);
static int test_xfs_admin_1_perform (guestfs_h *);

static int
test_xfs_admin_1 (guestfs_h *g)
{
  if (test_xfs_admin_1_skip ()) {
    skipped ("test_xfs_admin_1", "environment variable set");
    return 0;
  }

  const char *features924[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) features924)) {
    skipped ("test_xfs_admin_1", "group %s not available in daemon",
             features924[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_xfs_admin_1_perform (g);
}

static int
test_xfs_admin_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "xfs_admin") == NULL;
  str = getenv ("SKIP_TEST_XFS_ADMIN_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_XFS_ADMIN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_xfs_admin_1_perform (guestfs_h *g)
{
  /* TestResultString for xfs_admin (1) */
  const char *arg926 = "/dev/sda";
  const char *arg927 = "mbr";
  int ret925;
  ret925 = guestfs_part_disk (g, arg926, arg927);
  if (ret925 == -1)
    return -1;
  const char *arg930 = "xfs";
  const char *arg931 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs932;
  optargs932.bitmask = UINT64_C(0x0);
  int ret929;
  ret929 = guestfs_mkfs_opts_argv (g, arg930, arg931, &optargs932);
  if (ret929 == -1)
    return -1;
  const char *arg934 = "/dev/sda1";
  struct guestfs_xfs_admin_argv optargs935;
  optargs935.lazycounter = 0;
  optargs935.uuid = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  optargs935.bitmask = UINT64_C(0x50);
  int ret933;
  ret933 = guestfs_xfs_admin_argv (g, arg934, &optargs935);
  if (ret933 == -1)
    return -1;
  const char *arg936 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_uuid (g, arg936);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_xfs_admin_1", "vfs_uuid", "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc", ret);
    return -1;
  }
  return 0;
}

static int test_xfs_admin_2_skip (void);
static int test_xfs_admin_2_perform (guestfs_h *);

static int
test_xfs_admin_2 (guestfs_h *g)
{
  if (test_xfs_admin_2_skip ()) {
    skipped ("test_xfs_admin_2", "environment variable set");
    return 0;
  }

  const char *features938[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) features938)) {
    skipped ("test_xfs_admin_2", "group %s not available in daemon",
             features938[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_xfs_admin_2_perform (g);
}

static int
test_xfs_admin_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "xfs_admin") == NULL;
  str = getenv ("SKIP_TEST_XFS_ADMIN_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_XFS_ADMIN");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_xfs_admin_2_perform (guestfs_h *g)
{
  /* TestResultString for xfs_admin (2) */
  const char *arg940 = "/dev/sda";
  const char *arg941 = "mbr";
  int ret939;
  ret939 = guestfs_part_disk (g, arg940, arg941);
  if (ret939 == -1)
    return -1;
  const char *arg944 = "xfs";
  const char *arg945 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs946;
  optargs946.bitmask = UINT64_C(0x0);
  int ret943;
  ret943 = guestfs_mkfs_opts_argv (g, arg944, arg945, &optargs946);
  if (ret943 == -1)
    return -1;
  const char *arg948 = "/dev/sda1";
  struct guestfs_xfs_admin_argv optargs949;
  optargs949.lazycounter = 0;
  optargs949.label = "LBL-TEST";
  optargs949.bitmask = UINT64_C(0x30);
  int ret947;
  ret947 = guestfs_xfs_admin_argv (g, arg948, &optargs949);
  if (ret947 == -1)
    return -1;
  const char *arg950 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, arg950);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "LBL-TEST")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_xfs_admin_2", "vfs_label", "LBL-TEST", ret);
    return -1;
  }
  return 0;
}

static int test_xfs_growfs_0_skip (void);
static int test_xfs_growfs_0_perform (guestfs_h *);

static int
test_xfs_growfs_0 (guestfs_h *g)
{
  if (test_xfs_growfs_0_skip ()) {
    skipped ("test_xfs_growfs_0", "environment variable set");
    return 0;
  }

  const char *features952[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) features952)) {
    skipped ("test_xfs_growfs_0", "group %s not available in daemon",
             features952[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_xfs_growfs_0_perform (g);
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
test_xfs_growfs_0_perform (guestfs_h *g)
{
  /* TestResult for xfs_growfs (0) */
  const char *arg953 = "/dev/sda";
  const char *arg954 = "mbr";
  int ret8;
  ret8 = guestfs_part_disk (g, arg953, arg954);
  if (ret8 == -1)
    return -1;
  const char *arg956 = "/dev/sda1";
  int ret7;
  ret7 = guestfs_pvcreate (g, arg956);
  if (ret7 == -1)
    return -1;
  const char *arg958 = "VG";
  const char *arg959_0 = "/dev/sda1";
  const char *const arg959[] = {
    arg959_0,
    NULL
  };
  int ret6;
  ret6 = guestfs_vgcreate (g, arg958, (char **) arg959);
  if (ret6 == -1)
    return -1;
  const char *arg961 = "LV";
  const char *arg962 = "VG";
  int ret5;
  ret5 = guestfs_lvcreate (g, arg961, arg962, 40);
  if (ret5 == -1)
    return -1;
  const char *arg965 = "xfs";
  const char *arg966 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv optargs967;
  optargs967.bitmask = UINT64_C(0x0);
  int ret4;
  ret4 = guestfs_mkfs_opts_argv (g, arg965, arg966, &optargs967);
  if (ret4 == -1)
    return -1;
  const char *arg968 = "/dev/VG/LV";
  int ret3;
  ret3 = guestfs_lvresize (g, arg968, 80);
  if (ret3 == -1)
    return -1;
  const char *arg971 = "/dev/VG/LV";
  const char *arg972 = "/";
  int ret2;
  ret2 = guestfs_mount (g, arg971, arg972);
  if (ret2 == -1)
    return -1;
  const char *arg974 = "/";
  struct guestfs_xfs_growfs_argv optargs975;
  optargs975.datasec = 1;
  optargs975.logsec = 0;
  optargs975.rtsec = 0;
  optargs975.bitmask = UINT64_C(0x7);
  int ret1;
  ret1 = guestfs_xfs_growfs_argv (g, arg974, &optargs975);
  if (ret1 == -1)
    return -1;
  const char *arg976 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, arg976);
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

static int test_utsname_0_skip (void);
static int test_utsname_0_perform (guestfs_h *);

static int
test_utsname_0 (guestfs_h *g)
{
  if (test_utsname_0_skip ()) {
    skipped ("test_utsname_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_utsname_0_perform (g);
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
test_utsname_0_perform (guestfs_h *g)
{
  /* TestRun for utsname (0) */
  CLEANUP_FREE_UTSNAME struct guestfs_utsname *ret978;
  ret978 = guestfs_utsname (g);
  if (ret978 == NULL)
      return -1;
  return 0;
}

static int test_vgchange_uuid_all_0_skip (void);
static int test_vgchange_uuid_all_0_perform (guestfs_h *);

static int
test_vgchange_uuid_all_0 (guestfs_h *g)
{
  if (test_vgchange_uuid_all_0_skip ()) {
    skipped ("test_vgchange_uuid_all_0", "environment variable set");
    return 0;
  }

  const char *features980[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features980)) {
    skipped ("test_vgchange_uuid_all_0", "group %s not available in daemon",
             features980[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_vgchange_uuid_all_0_perform (g);
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
test_vgchange_uuid_all_0_perform (guestfs_h *g)
{
  /* TestRun for vgchange_uuid_all (0) */
  const char *arg982 = "/dev/sda";
  const char *arg983 = "mbr";
  int ret981;
  ret981 = guestfs_part_disk (g, arg982, arg983);
  if (ret981 == -1)
    return -1;
  const char *arg986 = "/dev/sda1";
  int ret985;
  ret985 = guestfs_pvcreate (g, arg986);
  if (ret985 == -1)
    return -1;
  const char *arg989 = "VG";
  const char *arg990_0 = "/dev/sda1";
  const char *const arg990[] = {
    arg990_0,
    NULL
  };
  int ret988;
  ret988 = guestfs_vgcreate (g, arg989, (char **) arg990);
  if (ret988 == -1)
    return -1;
  int ret992;
  ret992 = guestfs_vgchange_uuid_all (g);
  if (ret992 == -1)
    return -1;
  return 0;
}

static int test_vgchange_uuid_0_skip (void);
static int test_vgchange_uuid_0_perform (guestfs_h *);

static int
test_vgchange_uuid_0 (guestfs_h *g)
{
  if (test_vgchange_uuid_0_skip ()) {
    skipped ("test_vgchange_uuid_0", "environment variable set");
    return 0;
  }

  const char *features994[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features994)) {
    skipped ("test_vgchange_uuid_0", "group %s not available in daemon",
             features994[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_vgchange_uuid_0_perform (g);
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
test_vgchange_uuid_0_perform (guestfs_h *g)
{
  /* TestRun for vgchange_uuid (0) */
  const char *arg996 = "/dev/sda";
  const char *arg997 = "mbr";
  int ret995;
  ret995 = guestfs_part_disk (g, arg996, arg997);
  if (ret995 == -1)
    return -1;
  const char *arg1000 = "/dev/sda1";
  int ret999;
  ret999 = guestfs_pvcreate (g, arg1000);
  if (ret999 == -1)
    return -1;
  const char *arg1003 = "VG";
  const char *arg1004_0 = "/dev/sda1";
  const char *const arg1004[] = {
    arg1004_0,
    NULL
  };
  int ret1002;
  ret1002 = guestfs_vgcreate (g, arg1003, (char **) arg1004);
  if (ret1002 == -1)
    return -1;
  const char *arg1007 = "/dev/VG";
  int ret1006;
  ret1006 = guestfs_vgchange_uuid (g, arg1007);
  if (ret1006 == -1)
    return -1;
  return 0;
}

static int test_pvchange_uuid_all_0_skip (void);
static int test_pvchange_uuid_all_0_perform (guestfs_h *);

static int
test_pvchange_uuid_all_0 (guestfs_h *g)
{
  if (test_pvchange_uuid_all_0_skip ()) {
    skipped ("test_pvchange_uuid_all_0", "environment variable set");
    return 0;
  }

  const char *features1009[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features1009)) {
    skipped ("test_pvchange_uuid_all_0", "group %s not available in daemon",
             features1009[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_pvchange_uuid_all_0_perform (g);
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
test_pvchange_uuid_all_0_perform (guestfs_h *g)
{
  /* TestRun for pvchange_uuid_all (0) */
  const char *arg1011 = "/dev/sda";
  const char *arg1012 = "mbr";
  int ret1010;
  ret1010 = guestfs_part_disk (g, arg1011, arg1012);
  if (ret1010 == -1)
    return -1;
  const char *arg1015 = "/dev/sda1";
  int ret1014;
  ret1014 = guestfs_pvcreate (g, arg1015);
  if (ret1014 == -1)
    return -1;
  int ret1017;
  ret1017 = guestfs_pvchange_uuid_all (g);
  if (ret1017 == -1)
    return -1;
  return 0;
}

static int test_pvchange_uuid_0_skip (void);
static int test_pvchange_uuid_0_perform (guestfs_h *);

static int
test_pvchange_uuid_0 (guestfs_h *g)
{
  if (test_pvchange_uuid_0_skip ()) {
    skipped ("test_pvchange_uuid_0", "environment variable set");
    return 0;
  }

  const char *features1019[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features1019)) {
    skipped ("test_pvchange_uuid_0", "group %s not available in daemon",
             features1019[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_pvchange_uuid_0_perform (g);
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
test_pvchange_uuid_0_perform (guestfs_h *g)
{
  /* TestRun for pvchange_uuid (0) */
  const char *arg1021 = "/dev/sda";
  const char *arg1022 = "mbr";
  int ret1020;
  ret1020 = guestfs_part_disk (g, arg1021, arg1022);
  if (ret1020 == -1)
    return -1;
  const char *arg1025 = "/dev/sda1";
  int ret1024;
  ret1024 = guestfs_pvcreate (g, arg1025);
  if (ret1024 == -1)
    return -1;
  const char *arg1028 = "/dev/sda1";
  int ret1027;
  ret1027 = guestfs_pvchange_uuid (g, arg1028);
  if (ret1027 == -1)
    return -1;
  return 0;
}

static int test_xfs_info_0_skip (void);
static int test_xfs_info_0_perform (guestfs_h *);

static int
test_xfs_info_0 (guestfs_h *g)
{
  if (test_xfs_info_0_skip ()) {
    skipped ("test_xfs_info_0", "environment variable set");
    return 0;
  }

  const char *features1030[] = { "xfs", NULL };
  if (!guestfs_feature_available (g, (char **) features1030)) {
    skipped ("test_xfs_info_0", "group %s not available in daemon",
             features1030[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_xfs_info_0_perform (g);
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
test_xfs_info_0_perform (guestfs_h *g)
{
  /* TestResult for xfs_info (0) */
  const char *arg1031 = "/dev/sda";
  const char *arg1032 = "mbr";
  int ret3;
  ret3 = guestfs_part_disk (g, arg1031, arg1032);
  if (ret3 == -1)
    return -1;
  const char *arg1034 = "xfs";
  const char *arg1035 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs1036;
  optargs1036.bitmask = UINT64_C(0x0);
  int ret2;
  ret2 = guestfs_mkfs_opts_argv (g, arg1034, arg1035, &optargs1036);
  if (ret2 == -1)
    return -1;
  const char *arg1037 = "/dev/sda1";
  const char *arg1038 = "/";
  int ret1;
  ret1 = guestfs_mount (g, arg1037, arg1038);
  if (ret1 == -1)
    return -1;
  const char *arg1040 = "/";
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *ret;
  ret = guestfs_xfs_info (g, arg1040);
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

static int test_nr_devices_0_skip (void);
static int test_nr_devices_0_perform (guestfs_h *);

static int
test_nr_devices_0 (guestfs_h *g)
{
  if (test_nr_devices_0_skip ()) {
    skipped ("test_nr_devices_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_nr_devices_0_perform (g);
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
test_nr_devices_0_perform (guestfs_h *g)
{
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

static int test_device_index_0_skip (void);
static int test_device_index_0_perform (guestfs_h *);

static int
test_device_index_0 (guestfs_h *g)
{
  if (test_device_index_0_skip ()) {
    skipped ("test_device_index_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_device_index_0_perform (g);
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
test_device_index_0_perform (guestfs_h *g)
{
  /* TestResult for device_index (0) */
  const char *arg1043 = "/dev/sda";
  int ret;
  ret = guestfs_device_index (g, arg1043);
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

static int test_btrfs_fsck_0_skip (void);
static int test_btrfs_fsck_0_perform (guestfs_h *);

static int
test_btrfs_fsck_0 (guestfs_h *g)
{
  if (test_btrfs_fsck_0_skip ()) {
    skipped ("test_btrfs_fsck_0", "environment variable set");
    return 0;
  }

  const char *features1045[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features1045)) {
    skipped ("test_btrfs_fsck_0", "group %s not available in daemon",
             features1045[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_fsck_0_perform (g);
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
test_btrfs_fsck_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_fsck (0) */
  const char *arg1047_0 = "/dev/sda1";
  const char *const arg1047[] = {
    arg1047_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs1048;
  optargs1048.bitmask = UINT64_C(0x0);
  int ret1046;
  ret1046 = guestfs_mkfs_btrfs_argv (g, (char **) arg1047, &optargs1048);
  if (ret1046 == -1)
    return -1;
  const char *arg1050 = "/dev/sda1";
  struct guestfs_btrfs_fsck_argv optargs1051;
  optargs1051.bitmask = UINT64_C(0x0);
  int ret1049;
  ret1049 = guestfs_btrfs_fsck_argv (g, arg1050, &optargs1051);
  if (ret1049 == -1)
    return -1;
  return 0;
}

static int test_btrfs_set_seeding_0_skip (void);
static int test_btrfs_set_seeding_0_perform (guestfs_h *);

static int
test_btrfs_set_seeding_0 (guestfs_h *g)
{
  if (test_btrfs_set_seeding_0_skip ()) {
    skipped ("test_btrfs_set_seeding_0", "environment variable set");
    return 0;
  }

  const char *features1052[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features1052)) {
    skipped ("test_btrfs_set_seeding_0", "group %s not available in daemon",
             features1052[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_set_seeding_0_perform (g);
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
test_btrfs_set_seeding_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_set_seeding (0) */
  const char *arg1054_0 = "/dev/sda1";
  const char *const arg1054[] = {
    arg1054_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs1055;
  optargs1055.bitmask = UINT64_C(0x0);
  int ret1053;
  ret1053 = guestfs_mkfs_btrfs_argv (g, (char **) arg1054, &optargs1055);
  if (ret1053 == -1)
    return -1;
  const char *arg1057 = "/dev/sda1";
  int ret1056;
  ret1056 = guestfs_btrfs_set_seeding (g, arg1057, 1);
  if (ret1056 == -1)
    return -1;
  const char *arg1061 = "/dev/sda1";
  int ret1060;
  ret1060 = guestfs_btrfs_set_seeding (g, arg1061, 0);
  if (ret1060 == -1)
    return -1;
  return 0;
}

static int test_btrfs_filesystem_sync_0_skip (void);
static int test_btrfs_filesystem_sync_0_perform (guestfs_h *);

static int
test_btrfs_filesystem_sync_0 (guestfs_h *g)
{
  if (test_btrfs_filesystem_sync_0_skip ()) {
    skipped ("test_btrfs_filesystem_sync_0", "environment variable set");
    return 0;
  }

  const char *features1064[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features1064)) {
    skipped ("test_btrfs_filesystem_sync_0", "group %s not available in daemon",
             features1064[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_filesystem_sync_0_perform (g);
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
test_btrfs_filesystem_sync_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_filesystem_sync (0) */
  const char *arg1066_0 = "/dev/sda1";
  const char *const arg1066[] = {
    arg1066_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs1067;
  optargs1067.bitmask = UINT64_C(0x0);
  int ret1065;
  ret1065 = guestfs_mkfs_btrfs_argv (g, (char **) arg1066, &optargs1067);
  if (ret1065 == -1)
    return -1;
  const char *arg1069 = "/dev/sda1";
  const char *arg1070 = "/";
  int ret1068;
  ret1068 = guestfs_mount (g, arg1069, arg1070);
  if (ret1068 == -1)
    return -1;
  const char *arg1073 = "/test1";
  struct guestfs_btrfs_subvolume_create_opts_argv optargs1074;
  optargs1074.bitmask = UINT64_C(0x0);
  int ret1072;
  ret1072 = guestfs_btrfs_subvolume_create_opts_argv (g, arg1073, &optargs1074);
  if (ret1072 == -1)
    return -1;
  const char *arg1076 = "/test1";
  int ret1075;
  ret1075 = guestfs_btrfs_filesystem_sync (g, arg1076);
  if (ret1075 == -1)
    return -1;
  const char *arg1079 = "/test1";
  int ret1078;
  ret1078 = guestfs_btrfs_filesystem_balance (g, arg1079);
  if (ret1078 == -1)
    return -1;
  return 0;
}

static int test_btrfs_subvolume_delete_0_skip (void);
static int test_btrfs_subvolume_delete_0_perform (guestfs_h *);

static int
test_btrfs_subvolume_delete_0 (guestfs_h *g)
{
  if (test_btrfs_subvolume_delete_0_skip ()) {
    skipped ("test_btrfs_subvolume_delete_0", "environment variable set");
    return 0;
  }

  const char *features1081[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features1081)) {
    skipped ("test_btrfs_subvolume_delete_0", "group %s not available in daemon",
             features1081[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_subvolume_delete_0_perform (g);
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
test_btrfs_subvolume_delete_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_subvolume_delete (0) */
  const char *arg1083_0 = "/dev/sda1";
  const char *const arg1083[] = {
    arg1083_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs1084;
  optargs1084.bitmask = UINT64_C(0x0);
  int ret1082;
  ret1082 = guestfs_mkfs_btrfs_argv (g, (char **) arg1083, &optargs1084);
  if (ret1082 == -1)
    return -1;
  const char *arg1086 = "/dev/sda1";
  const char *arg1087 = "/";
  int ret1085;
  ret1085 = guestfs_mount (g, arg1086, arg1087);
  if (ret1085 == -1)
    return -1;
  const char *arg1090 = "/test1";
  struct guestfs_btrfs_subvolume_create_opts_argv optargs1091;
  optargs1091.bitmask = UINT64_C(0x0);
  int ret1089;
  ret1089 = guestfs_btrfs_subvolume_create_opts_argv (g, arg1090, &optargs1091);
  if (ret1089 == -1)
    return -1;
  const char *arg1093 = "/test1";
  int ret1092;
  ret1092 = guestfs_btrfs_subvolume_delete (g, arg1093);
  if (ret1092 == -1)
    return -1;
  return 0;
}

static int test_btrfs_subvolume_snapshot_0_skip (void);
static int test_btrfs_subvolume_snapshot_0_perform (guestfs_h *);

static int
test_btrfs_subvolume_snapshot_0 (guestfs_h *g)
{
  if (test_btrfs_subvolume_snapshot_0_skip ()) {
    skipped ("test_btrfs_subvolume_snapshot_0", "environment variable set");
    return 0;
  }

  const char *features1095[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features1095)) {
    skipped ("test_btrfs_subvolume_snapshot_0", "group %s not available in daemon",
             features1095[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_btrfs_subvolume_snapshot_0_perform (g);
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
test_btrfs_subvolume_snapshot_0_perform (guestfs_h *g)
{
  /* TestRun for btrfs_subvolume_snapshot (0) */
  const char *arg1097_0 = "/dev/sda1";
  const char *const arg1097[] = {
    arg1097_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs1098;
  optargs1098.bitmask = UINT64_C(0x0);
  int ret1096;
  ret1096 = guestfs_mkfs_btrfs_argv (g, (char **) arg1097, &optargs1098);
  if (ret1096 == -1)
    return -1;
  const char *arg1100 = "/dev/sda1";
  const char *arg1101 = "/";
  int ret1099;
  ret1099 = guestfs_mount (g, arg1100, arg1101);
  if (ret1099 == -1)
    return -1;
  const char *arg1104 = "/dir";
  int ret1103;
  ret1103 = guestfs_mkdir (g, arg1104);
  if (ret1103 == -1)
    return -1;
  const char *arg1107 = "/test1";
  struct guestfs_btrfs_subvolume_create_opts_argv optargs1108;
  optargs1108.bitmask = UINT64_C(0x0);
  int ret1106;
  ret1106 = guestfs_btrfs_subvolume_create_opts_argv (g, arg1107, &optargs1108);
  if (ret1106 == -1)
    return -1;
  const char *arg1110 = "/test2";
  struct guestfs_btrfs_subvolume_create_opts_argv optargs1111;
  optargs1111.bitmask = UINT64_C(0x0);
  int ret1109;
  ret1109 = guestfs_btrfs_subvolume_create_opts_argv (g, arg1110, &optargs1111);
  if (ret1109 == -1)
    return -1;
  const char *arg1113 = "/dir/test3";
  struct guestfs_btrfs_subvolume_create_opts_argv optargs1114;
  optargs1114.bitmask = UINT64_C(0x0);
  int ret1112;
  ret1112 = guestfs_btrfs_subvolume_create_opts_argv (g, arg1113, &optargs1114);
  if (ret1112 == -1)
    return -1;
  const char *arg1116 = "/dir/test3";
  const char *arg1117 = "/dir/test5";
  struct guestfs_btrfs_subvolume_snapshot_opts_argv optargs1118;
  optargs1118.ro = 1;
  optargs1118.bitmask = UINT64_C(0x1);
  int ret1115;
  ret1115 = guestfs_btrfs_subvolume_snapshot_opts_argv (g, arg1116, arg1117, &optargs1118);
  if (ret1115 == -1)
    return -1;
  const char *arg1120 = "/dir/test3";
  const char *arg1121 = "/dir/test6";
  struct guestfs_btrfs_subvolume_snapshot_opts_argv optargs1122;
  optargs1122.qgroupid = "0/1000";
  optargs1122.bitmask = UINT64_C(0x2);
  int ret1119;
  ret1119 = guestfs_btrfs_subvolume_snapshot_opts_argv (g, arg1120, arg1121, &optargs1122);
  if (ret1119 == -1)
    return -1;
  return 0;
}

static int test_get_e2generation_0_skip (void);
static int test_get_e2generation_0_perform (guestfs_h *);

static int
test_get_e2generation_0 (guestfs_h *g)
{
  if (test_get_e2generation_0_skip ()) {
    skipped ("test_get_e2generation_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_get_e2generation_0_perform (g);
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
test_get_e2generation_0_perform (guestfs_h *g)
{
  /* TestResult for get_e2generation (0) */
  const char *arg1123 = "/e2generation";
  int ret2;
  ret2 = guestfs_touch (g, arg1123);
  if (ret2 == -1)
    return -1;
  const char *arg1125 = "/e2generation";
  int ret1;
  ret1 = guestfs_set_e2generation (g, arg1125, 123456);
  if (ret1 == -1)
    return -1;
  const char *arg1128 = "/e2generation";
  int64_t ret;
  ret = guestfs_get_e2generation (g, arg1128);
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

static int test_get_e2attrs_0_skip (void);
static int test_get_e2attrs_0_perform (guestfs_h *);

static int
test_get_e2attrs_0 (guestfs_h *g)
{
  if (test_get_e2attrs_0_skip ()) {
    skipped ("test_get_e2attrs_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_get_e2attrs_0_perform (g);
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
test_get_e2attrs_0_perform (guestfs_h *g)
{
  /* TestResultString for get_e2attrs (0) */
  const char *arg1131 = "/e2attrs1";
  int ret1130;
  ret1130 = guestfs_touch (g, arg1131);
  if (ret1130 == -1)
    return -1;
  const char *arg1133 = "/e2attrs1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, arg1133);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_get_e2attrs_0", "get_e2attrs", "", ret);
    return -1;
  }
  return 0;
}

static int test_get_e2attrs_1_skip (void);
static int test_get_e2attrs_1_perform (guestfs_h *);

static int
test_get_e2attrs_1 (guestfs_h *g)
{
  if (test_get_e2attrs_1_skip ()) {
    skipped ("test_get_e2attrs_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_get_e2attrs_1_perform (g);
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
test_get_e2attrs_1_perform (guestfs_h *g)
{
  /* TestResultString for get_e2attrs (1) */
  const char *arg1136 = "/e2attrs2";
  int ret1135;
  ret1135 = guestfs_touch (g, arg1136);
  if (ret1135 == -1)
    return -1;
  const char *arg1139 = "/e2attrs2";
  const char *arg1140 = "is";
  struct guestfs_set_e2attrs_argv optargs1141;
  optargs1141.clear = 0;
  optargs1141.bitmask = UINT64_C(0x1);
  int ret1138;
  ret1138 = guestfs_set_e2attrs_argv (g, arg1139, arg1140, &optargs1141);
  if (ret1138 == -1)
    return -1;
  const char *arg1142 = "/e2attrs2";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, arg1142);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "is")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_get_e2attrs_1", "get_e2attrs", "is", ret);
    return -1;
  }
  return 0;
}

static int test_get_e2attrs_2_skip (void);
static int test_get_e2attrs_2_perform (guestfs_h *);

static int
test_get_e2attrs_2 (guestfs_h *g)
{
  if (test_get_e2attrs_2_skip ()) {
    skipped ("test_get_e2attrs_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_get_e2attrs_2_perform (g);
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
test_get_e2attrs_2_perform (guestfs_h *g)
{
  /* TestResultString for get_e2attrs (2) */
  const char *arg1145 = "/e2attrs3";
  int ret1144;
  ret1144 = guestfs_touch (g, arg1145);
  if (ret1144 == -1)
    return -1;
  const char *arg1148 = "/e2attrs3";
  const char *arg1149 = "is";
  struct guestfs_set_e2attrs_argv optargs1150;
  optargs1150.clear = 0;
  optargs1150.bitmask = UINT64_C(0x1);
  int ret1147;
  ret1147 = guestfs_set_e2attrs_argv (g, arg1148, arg1149, &optargs1150);
  if (ret1147 == -1)
    return -1;
  const char *arg1152 = "/e2attrs3";
  const char *arg1153 = "i";
  struct guestfs_set_e2attrs_argv optargs1154;
  optargs1154.clear = 1;
  optargs1154.bitmask = UINT64_C(0x1);
  int ret1151;
  ret1151 = guestfs_set_e2attrs_argv (g, arg1152, arg1153, &optargs1154);
  if (ret1151 == -1)
    return -1;
  const char *arg1155 = "/e2attrs3";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, arg1155);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "s")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_get_e2attrs_2", "get_e2attrs", "s", ret);
    return -1;
  }
  return 0;
}

static int test_get_e2attrs_3_skip (void);
static int test_get_e2attrs_3_perform (guestfs_h *);

static int
test_get_e2attrs_3 (guestfs_h *g)
{
  if (test_get_e2attrs_3_skip ()) {
    skipped ("test_get_e2attrs_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_get_e2attrs_3_perform (g);
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
test_get_e2attrs_3_perform (guestfs_h *g)
{
  /* TestResultString for get_e2attrs (3) */
  const char *arg1158 = "/e2attrs4";
  int ret1157;
  ret1157 = guestfs_touch (g, arg1158);
  if (ret1157 == -1)
    return -1;
  const char *arg1161 = "/e2attrs4";
  const char *arg1162 = "adst";
  struct guestfs_set_e2attrs_argv optargs1163;
  optargs1163.clear = 0;
  optargs1163.bitmask = UINT64_C(0x1);
  int ret1160;
  ret1160 = guestfs_set_e2attrs_argv (g, arg1161, arg1162, &optargs1163);
  if (ret1160 == -1)
    return -1;
  const char *arg1165 = "/e2attrs4";
  const char *arg1166 = "iS";
  struct guestfs_set_e2attrs_argv optargs1167;
  optargs1167.clear = 0;
  optargs1167.bitmask = UINT64_C(0x1);
  int ret1164;
  ret1164 = guestfs_set_e2attrs_argv (g, arg1165, arg1166, &optargs1167);
  if (ret1164 == -1)
    return -1;
  const char *arg1169 = "/e2attrs4";
  const char *arg1170 = "i";
  struct guestfs_set_e2attrs_argv optargs1171;
  optargs1171.clear = 1;
  optargs1171.bitmask = UINT64_C(0x1);
  int ret1168;
  ret1168 = guestfs_set_e2attrs_argv (g, arg1169, arg1170, &optargs1171);
  if (ret1168 == -1)
    return -1;
  const char *arg1173 = "/e2attrs4";
  const char *arg1174 = "ad";
  struct guestfs_set_e2attrs_argv optargs1175;
  optargs1175.clear = 1;
  optargs1175.bitmask = UINT64_C(0x1);
  int ret1172;
  ret1172 = guestfs_set_e2attrs_argv (g, arg1173, arg1174, &optargs1175);
  if (ret1172 == -1)
    return -1;
  const char *arg1177 = "/e2attrs4";
  const char *arg1178 = "";
  struct guestfs_set_e2attrs_argv optargs1179;
  optargs1179.clear = 0;
  optargs1179.bitmask = UINT64_C(0x1);
  int ret1176;
  ret1176 = guestfs_set_e2attrs_argv (g, arg1177, arg1178, &optargs1179);
  if (ret1176 == -1)
    return -1;
  const char *arg1181 = "/e2attrs4";
  const char *arg1182 = "";
  struct guestfs_set_e2attrs_argv optargs1183;
  optargs1183.clear = 1;
  optargs1183.bitmask = UINT64_C(0x1);
  int ret1180;
  ret1180 = guestfs_set_e2attrs_argv (g, arg1181, arg1182, &optargs1183);
  if (ret1180 == -1)
    return -1;
  const char *arg1184 = "/e2attrs4";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2attrs (g, arg1184);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "Sst")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_get_e2attrs_3", "get_e2attrs", "Sst", ret);
    return -1;
  }
  return 0;
}

static int test_get_e2attrs_4_skip (void);
static int test_get_e2attrs_4_perform (guestfs_h *);

static int
test_get_e2attrs_4 (guestfs_h *g)
{
  if (test_get_e2attrs_4_skip ()) {
    skipped ("test_get_e2attrs_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_get_e2attrs_4_perform (g);
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
test_get_e2attrs_4_perform (guestfs_h *g)
{
  /* TestLastFail for get_e2attrs (4) */
  const char *arg1187 = "/e2attrs5";
  int ret1186;
  ret1186 = guestfs_touch (g, arg1187);
  if (ret1186 == -1)
    return -1;
  const char *arg1190 = "/e2attrs5";
  const char *arg1191 = "R";
  struct guestfs_set_e2attrs_argv optargs1192;
  optargs1192.clear = 0;
  optargs1192.bitmask = UINT64_C(0x1);
  int ret1189;
  guestfs_push_error_handler (g, NULL, NULL);
  ret1189 = guestfs_set_e2attrs_argv (g, arg1190, arg1191, &optargs1192);
  guestfs_pop_error_handler (g);
  if (ret1189 != -1)
    return -1;
  return 0;
}

static int test_get_e2attrs_5_skip (void);
static int test_get_e2attrs_5_perform (guestfs_h *);

static int
test_get_e2attrs_5 (guestfs_h *g)
{
  if (test_get_e2attrs_5_skip ()) {
    skipped ("test_get_e2attrs_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_get_e2attrs_5_perform (g);
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
test_get_e2attrs_5_perform (guestfs_h *g)
{
  /* TestLastFail for get_e2attrs (5) */
  const char *arg1194 = "/e2attrs6";
  int ret1193;
  ret1193 = guestfs_touch (g, arg1194);
  if (ret1193 == -1)
    return -1;
  const char *arg1197 = "/e2attrs6";
  const char *arg1198 = "v";
  struct guestfs_set_e2attrs_argv optargs1199;
  optargs1199.clear = 0;
  optargs1199.bitmask = UINT64_C(0x1);
  int ret1196;
  guestfs_push_error_handler (g, NULL, NULL);
  ret1196 = guestfs_set_e2attrs_argv (g, arg1197, arg1198, &optargs1199);
  guestfs_pop_error_handler (g);
  if (ret1196 != -1)
    return -1;
  return 0;
}

static int test_get_e2attrs_6_skip (void);
static int test_get_e2attrs_6_perform (guestfs_h *);

static int
test_get_e2attrs_6 (guestfs_h *g)
{
  if (test_get_e2attrs_6_skip ()) {
    skipped ("test_get_e2attrs_6", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_get_e2attrs_6_perform (g);
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
test_get_e2attrs_6_perform (guestfs_h *g)
{
  /* TestLastFail for get_e2attrs (6) */
  const char *arg1201 = "/e2attrs7";
  int ret1200;
  ret1200 = guestfs_touch (g, arg1201);
  if (ret1200 == -1)
    return -1;
  const char *arg1204 = "/e2attrs7";
  const char *arg1205 = "aa";
  struct guestfs_set_e2attrs_argv optargs1206;
  optargs1206.clear = 0;
  optargs1206.bitmask = UINT64_C(0x1);
  int ret1203;
  guestfs_push_error_handler (g, NULL, NULL);
  ret1203 = guestfs_set_e2attrs_argv (g, arg1204, arg1205, &optargs1206);
  guestfs_pop_error_handler (g);
  if (ret1203 != -1)
    return -1;
  return 0;
}

static int test_get_e2attrs_7_skip (void);
static int test_get_e2attrs_7_perform (guestfs_h *);

static int
test_get_e2attrs_7 (guestfs_h *g)
{
  if (test_get_e2attrs_7_skip ()) {
    skipped ("test_get_e2attrs_7", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_get_e2attrs_7_perform (g);
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
test_get_e2attrs_7_perform (guestfs_h *g)
{
  /* TestLastFail for get_e2attrs (7) */
  const char *arg1208 = "/e2attrs8";
  int ret1207;
  ret1207 = guestfs_touch (g, arg1208);
  if (ret1207 == -1)
    return -1;
  const char *arg1211 = "/e2attrs8";
  const char *arg1212 = "BabcdB";
  struct guestfs_set_e2attrs_argv optargs1213;
  optargs1213.clear = 0;
  optargs1213.bitmask = UINT64_C(0x1);
  int ret1210;
  guestfs_push_error_handler (g, NULL, NULL);
  ret1210 = guestfs_set_e2attrs_argv (g, arg1211, arg1212, &optargs1213);
  guestfs_pop_error_handler (g);
  if (ret1210 != -1)
    return -1;
  return 0;
}

static int test_mkfs_btrfs_0_skip (void);
static int test_mkfs_btrfs_0_perform (guestfs_h *);

static int
test_mkfs_btrfs_0 (guestfs_h *g)
{
  if (test_mkfs_btrfs_0_skip ()) {
    skipped ("test_mkfs_btrfs_0", "environment variable set");
    return 0;
  }

  const char *features1214[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features1214)) {
    skipped ("test_mkfs_btrfs_0", "group %s not available in daemon",
             features1214[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mkfs_btrfs_0_perform (g);
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
test_mkfs_btrfs_0_perform (guestfs_h *g)
{
  /* TestRun for mkfs_btrfs (0) */
  const char *arg1216 = "/dev/sda";
  const char *arg1217 = "mbr";
  int ret1215;
  ret1215 = guestfs_part_disk (g, arg1216, arg1217);
  if (ret1215 == -1)
    return -1;
  const char *arg1220_0 = "/dev/sda1";
  const char *const arg1220[] = {
    arg1220_0,
    NULL
  };
  struct guestfs_mkfs_btrfs_argv optargs1221;
  optargs1221.allocstart = 0;
  optargs1221.bytecount = 268435456;
  optargs1221.datatype = "single";
  optargs1221.leafsize = 4096;
  optargs1221.label = "test";
  optargs1221.metadata = "single";
  optargs1221.nodesize = 4096;
  optargs1221.sectorsize = 512;
  optargs1221.bitmask = UINT64_C(0xff);
  int ret1219;
  ret1219 = guestfs_mkfs_btrfs_argv (g, (char **) arg1220, &optargs1221);
  if (ret1219 == -1)
    return -1;
  return 0;
}

static int test_isoinfo_device_0_skip (void);
static int test_isoinfo_device_0_perform (guestfs_h *);

static int
test_isoinfo_device_0 (guestfs_h *g)
{
  if (test_isoinfo_device_0_skip ()) {
    skipped ("test_isoinfo_device_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_isoinfo_device_0_perform (g);
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
test_isoinfo_device_0_perform (guestfs_h *g)
{
  /* TestResult for isoinfo_device (0) */
  const char *arg1222 = "/dev/sdd";
  CLEANUP_FREE_ISOINFO struct guestfs_isoinfo *ret;
  ret = guestfs_isoinfo_device (g, arg1222);
  if (ret == NULL)
      return -1;
  if (! (STREQ (ret->iso_system_id, GUESTFS_ISO_SYSTEM_ID) && STREQ (ret->iso_volume_id, "CDROM") && STREQ (ret->iso_volume_set_id, "") && ret->iso_volume_set_size == 1 && ret->iso_volume_sequence_number == 1 && ret->iso_logical_block_size == 2048)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_isoinfo_device_0", "STREQ (ret->iso_system_id, GUESTFS_ISO_SYSTEM_ID) && STREQ (ret->iso_volume_id, \"CDROM\") && STREQ (ret->iso_volume_set_id, \"\") && ret->iso_volume_set_size == 1 && ret->iso_volume_sequence_number == 1 && ret->iso_logical_block_size == 2048");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_lvcreate_free_0_skip (void);
static int test_lvcreate_free_0_perform (guestfs_h *);

static int
test_lvcreate_free_0 (guestfs_h *g)
{
  if (test_lvcreate_free_0_skip ()) {
    skipped ("test_lvcreate_free_0", "environment variable set");
    return 0;
  }

  const char *features1224[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features1224)) {
    skipped ("test_lvcreate_free_0", "group %s not available in daemon",
             features1224[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_lvcreate_free_0_perform (g);
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
test_lvcreate_free_0_perform (guestfs_h *g)
{
  /* TestResult for lvcreate_free (0) */
  const char *arg1225 = "/dev/sda";
  const char *arg1226 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, arg1225, arg1226);
  if (ret7 == -1)
    return -1;
  const char *arg1228 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, arg1228);
  if (ret6 == -1)
    return -1;
  const char *arg1230 = "VG";
  const char *arg1231_0 = "/dev/sda1";
  const char *const arg1231[] = {
    arg1231_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, arg1230, (char **) arg1231);
  if (ret5 == -1)
    return -1;
  const char *arg1233 = "LV1";
  const char *arg1234 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate_free (g, arg1233, arg1234, 50);
  if (ret4 == -1)
    return -1;
  const char *arg1237 = "LV2";
  const char *arg1238 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate_free (g, arg1237, arg1238, 50);
  if (ret3 == -1)
    return -1;
  const char *arg1241 = "LV3";
  const char *arg1242 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate_free (g, arg1241, arg1242, 50);
  if (ret2 == -1)
    return -1;
  const char *arg1245 = "LV4";
  const char *arg1246 = "VG";
  int ret1;
  ret1 = guestfs_lvcreate_free (g, arg1245, arg1246, 100);
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

static int test_zero_free_space_0_skip (void);
static int test_zero_free_space_0_perform (guestfs_h *);

static int
test_zero_free_space_0 (guestfs_h *g)
{
  if (test_zero_free_space_0_skip ()) {
    skipped ("test_zero_free_space_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_zero_free_space_0_perform (g);
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
test_zero_free_space_0_perform (guestfs_h *g)
{
  /* TestRun for zero_free_space (0) */
  const char *arg1251 = "/";
  int ret1250;
  ret1250 = guestfs_zero_free_space (g, arg1251);
  if (ret1250 == -1)
    return -1;
  return 0;
}

static int test_set_label_0_skip (void);
static int test_set_label_0_perform (guestfs_h *);

static int
test_set_label_0 (guestfs_h *g)
{
  if (test_set_label_0_skip ()) {
    skipped ("test_set_label_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_set_label_0_perform (g);
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
test_set_label_0_perform (guestfs_h *g)
{
  /* TestResultString for set_label (0) */
  const char *arg1254 = "/dev/sda1";
  const char *arg1255 = "testlabel";
  int ret1253;
  ret1253 = guestfs_set_label (g, arg1254, arg1255);
  if (ret1253 == -1)
    return -1;
  const char *arg1257 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, arg1257);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "testlabel")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_label_0", "vfs_label", "testlabel", ret);
    return -1;
  }
  return 0;
}

static int test_set_label_1_skip (void);
static int test_set_label_1_perform (guestfs_h *);

static int
test_set_label_1 (guestfs_h *g)
{
  if (test_set_label_1_skip ()) {
    skipped ("test_set_label_1", "environment variable set");
    return 0;
  }

  const char *features1259[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) features1259)) {
    skipped ("test_set_label_1", "group %s not available in daemon",
             features1259[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_set_label_1_perform (g);
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
test_set_label_1_perform (guestfs_h *g)
{
  /* TestResultString for set_label (1) */
  const char *arg1261 = "ntfs";
  const char *arg1262 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs1263;
  optargs1263.bitmask = UINT64_C(0x0);
  int ret1260;
  ret1260 = guestfs_mkfs_opts_argv (g, arg1261, arg1262, &optargs1263);
  if (ret1260 == -1)
    return -1;
  const char *arg1265 = "/dev/sda1";
  const char *arg1266 = "testlabel2";
  int ret1264;
  ret1264 = guestfs_set_label (g, arg1265, arg1266);
  if (ret1264 == -1)
    return -1;
  const char *arg1268 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, arg1268);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "testlabel2")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_label_1", "vfs_label", "testlabel2", ret);
    return -1;
  }
  return 0;
}

static int test_set_label_2_skip (void);
static int test_set_label_2_perform (guestfs_h *);

static int
test_set_label_2 (guestfs_h *g)
{
  if (test_set_label_2_skip ()) {
    skipped ("test_set_label_2", "environment variable set");
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_set_label_2_perform (g);
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
test_set_label_2_perform (guestfs_h *g)
{
  /* TestLastFail for set_label (2) */
  const char *arg1271 = "/dev/sda1";
  int ret1270;
  ret1270 = guestfs_zero (g, arg1271);
  if (ret1270 == -1)
    return -1;
  const char *arg1274 = "/dev/sda1";
  const char *arg1275 = "testlabel2";
  int ret1273;
  guestfs_push_error_handler (g, NULL, NULL);
  ret1273 = guestfs_set_label (g, arg1274, arg1275);
  guestfs_pop_error_handler (g);
  if (ret1273 != -1)
    return -1;
  return 0;
}

static int test_ntfsfix_0_skip (void);
static int test_ntfsfix_0_perform (guestfs_h *);

static int
test_ntfsfix_0 (guestfs_h *g)
{
  if (test_ntfsfix_0_skip ()) {
    skipped ("test_ntfsfix_0", "environment variable set");
    return 0;
  }

  const char *features1277[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) features1277)) {
    skipped ("test_ntfsfix_0", "group %s not available in daemon",
             features1277[0]);
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_ntfsfix_0_perform (g);
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
test_ntfsfix_0_perform (guestfs_h *g)
{
  /* TestRun for ntfsfix (0) */
  const char *arg1279 = "ntfs";
  const char *arg1280 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs1281;
  optargs1281.bitmask = UINT64_C(0x0);
  int ret1278;
  ret1278 = guestfs_mkfs_opts_argv (g, arg1279, arg1280, &optargs1281);
  if (ret1278 == -1)
    return -1;
  const char *arg1283 = "/dev/sda1";
  struct guestfs_ntfsfix_argv optargs1284;
  optargs1284.clearbadsectors = 0;
  optargs1284.bitmask = UINT64_C(0x1);
  int ret1282;
  ret1282 = guestfs_ntfsfix_argv (g, arg1283, &optargs1284);
  if (ret1282 == -1)
    return -1;
  return 0;
}

static int test_wipefs_0_skip (void);
static int test_wipefs_0_perform (guestfs_h *);

static int
test_wipefs_0 (guestfs_h *g)
{
  if (test_wipefs_0_skip ()) {
    skipped ("test_wipefs_0", "environment variable set");
    return 0;
  }

  const char *features1285[] = { "wipefs", NULL };
  if (!guestfs_feature_available (g, (char **) features1285)) {
    skipped ("test_wipefs_0", "group %s not available in daemon",
             features1285[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  return test_wipefs_0_perform (g);
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
test_wipefs_0_perform (guestfs_h *g)
{
  /* TestRun for wipefs (0) */
  const char *arg1287 = "/dev/VG/LV";
  struct guestfs_umount_opts_argv optargs1288;
  optargs1288.bitmask = UINT64_C(0x0);
  int ret1286;
  ret1286 = guestfs_umount_opts_argv (g, arg1287, &optargs1288);
  if (ret1286 == -1)
    return -1;
  const char *arg1290 = "/dev/VG/LV";
  int ret1289;
  ret1289 = guestfs_wipefs (g, arg1290);
  if (ret1289 == -1)
    return -1;
  return 0;
}

static int test_blkid_0_skip (void);
static int test_blkid_0_perform (guestfs_h *);

static int
test_blkid_0 (guestfs_h *g)
{
  if (test_blkid_0_skip ()) {
    skipped ("test_blkid_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_blkid_0_perform (g);
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
test_blkid_0_perform (guestfs_h *g)
{
  /* TestResult for blkid (0) */
  const char *arg1292 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_blkid (g, arg1292);
  if (ret == NULL)
      return -1;
  if (! (check_hash (ret, "TYPE", "ext2") == 0 && check_hash (ret, "USAGE", "filesystem") == 0 && check_hash (ret, "PART_ENTRY_NUMBER", "1") == 0 && check_hash (ret, "PART_ENTRY_TYPE", "0x83") == 0 && check_hash (ret, "PART_ENTRY_OFFSET", "128") == 0 && check_hash (ret, "PART_ENTRY_SIZE", "1023745") == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_blkid_0", "check_hash (ret, \"TYPE\", \"ext2\") == 0 && check_hash (ret, \"USAGE\", \"filesystem\") == 0 && check_hash (ret, \"PART_ENTRY_NUMBER\", \"1\") == 0 && check_hash (ret, \"PART_ENTRY_TYPE\", \"0x83\") == 0 && check_hash (ret, \"PART_ENTRY_OFFSET\", \"128\") == 0 && check_hash (ret, \"PART_ENTRY_SIZE\", \"1023745\") == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_tune2fs_0_skip (void);
static int test_tune2fs_0_perform (guestfs_h *);

static int
test_tune2fs_0 (guestfs_h *g)
{
  if (test_tune2fs_0_skip ()) {
    skipped ("test_tune2fs_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_tune2fs_0_perform (g);
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
test_tune2fs_0_perform (guestfs_h *g)
{
  /* TestResult for tune2fs (0) */
  const char *arg1294 = "/dev/sdb1";
  struct guestfs_tune2fs_argv optargs1295;
  optargs1295.force = 0;
  optargs1295.maxmountcount = 0;
  optargs1295.intervalbetweenchecks = 0;
  optargs1295.bitmask = UINT64_C(0x23);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, arg1294, &optargs1295);
  if (ret1 == -1)
    return -1;
  const char *arg1296 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, arg1296);
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

static int test_tune2fs_1_skip (void);
static int test_tune2fs_1_perform (guestfs_h *);

static int
test_tune2fs_1 (guestfs_h *g)
{
  if (test_tune2fs_1_skip ()) {
    skipped ("test_tune2fs_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_tune2fs_1_perform (g);
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
test_tune2fs_1_perform (guestfs_h *g)
{
  /* TestResult for tune2fs (1) */
  const char *arg1298 = "/dev/sdb1";
  struct guestfs_tune2fs_argv optargs1299;
  optargs1299.force = 0;
  optargs1299.maxmountcount = 0;
  optargs1299.intervalbetweenchecks = 86400;
  optargs1299.bitmask = UINT64_C(0x23);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, arg1298, &optargs1299);
  if (ret1 == -1)
    return -1;
  const char *arg1300 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, arg1300);
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

static int test_tune2fs_2_skip (void);
static int test_tune2fs_2_perform (guestfs_h *);

static int
test_tune2fs_2 (guestfs_h *g)
{
  if (test_tune2fs_2_skip ()) {
    skipped ("test_tune2fs_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_tune2fs_2_perform (g);
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
test_tune2fs_2_perform (guestfs_h *g)
{
  /* TestResult for tune2fs (2) */
  const char *arg1302 = "/dev/sdb1";
  struct guestfs_tune2fs_argv optargs1303;
  optargs1303.force = 0;
  optargs1303.group = 1;
  optargs1303.user = 1;
  optargs1303.bitmask = UINT64_C(0x211);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, arg1302, &optargs1303);
  if (ret1 == -1)
    return -1;
  const char *arg1304 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, arg1304);
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

static int test_tune2fs_3_skip (void);
static int test_tune2fs_3_perform (guestfs_h *);

static int
test_tune2fs_3 (guestfs_h *g)
{
  if (test_tune2fs_3_skip ()) {
    skipped ("test_tune2fs_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_tune2fs_3_perform (g);
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
test_tune2fs_3_perform (guestfs_h *g)
{
  /* TestResult for tune2fs (3) */
  const char *arg1306 = "/dev/sdb1";
  struct guestfs_tune2fs_argv optargs1307;
  optargs1307.force = 0;
  optargs1307.group = 0;
  optargs1307.user = 0;
  optargs1307.bitmask = UINT64_C(0x211);
  int ret1;
  ret1 = guestfs_tune2fs_argv (g, arg1306, &optargs1307);
  if (ret1 == -1)
    return -1;
  const char *arg1308 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, arg1308);
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

static int test_copy_file_to_file_0_skip (void);
static int test_copy_file_to_file_0_perform (guestfs_h *);

static int
test_copy_file_to_file_0 (guestfs_h *g)
{
  if (test_copy_file_to_file_0_skip ()) {
    skipped ("test_copy_file_to_file_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_copy_file_to_file_0_perform (g);
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
test_copy_file_to_file_0_perform (guestfs_h *g)
{
  /* TestResult for copy_file_to_file (0) */
  const char *arg1310 = "/copyff";
  int ret3;
  ret3 = guestfs_mkdir (g, arg1310);
  if (ret3 == -1)
    return -1;
  const char *arg1312 = "/copyff/src";
  const char *arg1313 = "hello, world";
  size_t arg1313_size = 12;
  int ret2;
  ret2 = guestfs_write (g, arg1312, arg1313, arg1313_size);
  if (ret2 == -1)
    return -1;
  const char *arg1315 = "/copyff/src";
  const char *arg1316 = "/copyff/dest";
  struct guestfs_copy_file_to_file_argv optargs1317;
  optargs1317.append = 0;
  optargs1317.bitmask = UINT64_C(0x10);
  int ret1;
  ret1 = guestfs_copy_file_to_file_argv (g, arg1315, arg1316, &optargs1317);
  if (ret1 == -1)
    return -1;
  const char *arg1318 = "/copyff/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, arg1318, &size);
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

static int test_copy_file_to_file_1_skip (void);
static int test_copy_file_to_file_1_perform (guestfs_h *);

static int
test_copy_file_to_file_1 (guestfs_h *g)
{
  if (test_copy_file_to_file_1_skip ()) {
    skipped ("test_copy_file_to_file_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_copy_file_to_file_1_perform (g);
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
test_copy_file_to_file_1_perform (guestfs_h *g)
{
  /* TestResultTrue for copy_file_to_file (1) */
  const char *arg1321 = "/copyff2";
  int ret1320;
  ret1320 = guestfs_mkdir (g, arg1321);
  if (ret1320 == -1)
    return -1;
  const char *arg1326 = "/copyff2/src";
  int ret1323;
  ret1323 = guestfs_fill (g, 0, 1048576, arg1326);
  if (ret1323 == -1)
    return -1;
  const char *arg1329 = "/copyff2/dest";
  int ret1328;
  ret1328 = guestfs_touch (g, arg1329);
  if (ret1328 == -1)
    return -1;
  const char *arg1332 = "/copyff2/dest";
  int ret1331;
  ret1331 = guestfs_truncate_size (g, arg1332, 1048576);
  if (ret1331 == -1)
    return -1;
  const char *arg1336 = "/copyff2/src";
  const char *arg1337 = "/copyff2/dest";
  struct guestfs_copy_file_to_file_argv optargs1338;
  optargs1338.sparse = 1;
  optargs1338.append = 0;
  optargs1338.bitmask = UINT64_C(0x18);
  int ret1335;
  ret1335 = guestfs_copy_file_to_file_argv (g, arg1336, arg1337, &optargs1338);
  if (ret1335 == -1)
    return -1;
  const char *arg1339 = "/copyff2/dest";
  int ret;
  ret = guestfs_is_zero (g, arg1339);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_copy_file_to_file_1", "is_zero");
    return -1;
  }
  return 0;
}

static int test_copy_file_to_file_2_skip (void);
static int test_copy_file_to_file_2_perform (guestfs_h *);

static int
test_copy_file_to_file_2 (guestfs_h *g)
{
  if (test_copy_file_to_file_2_skip ()) {
    skipped ("test_copy_file_to_file_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_copy_file_to_file_2_perform (g);
}

static int
test_copy_file_to_file_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "copy_file_to_file") == NULL;
  str = getenv ("SKIP_TEST_COPY_FILE_TO_FILE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_COPY_FILE_TO_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_copy_file_to_file_2_perform (guestfs_h *g)
{
  /* TestResult for copy_file_to_file (2) */
  const char *arg1341 = "/copyff3";
  int ret5;
  ret5 = guestfs_mkdir (g, arg1341);
  if (ret5 == -1)
    return -1;
  const char *arg1343 = "/copyff3/src";
  const char *arg1344 = "hello, world";
  size_t arg1344_size = 12;
  int ret4;
  ret4 = guestfs_write (g, arg1343, arg1344, arg1344_size);
  if (ret4 == -1)
    return -1;
  const char *arg1346 = "/copyff3/src";
  const char *arg1347 = "/copyff3/dest";
  struct guestfs_copy_file_to_file_argv optargs1348;
  optargs1348.append = 1;
  optargs1348.bitmask = UINT64_C(0x10);
  int ret3;
  ret3 = guestfs_copy_file_to_file_argv (g, arg1346, arg1347, &optargs1348);
  if (ret3 == -1)
    return -1;
  const char *arg1349 = "/copyff3/src";
  const char *arg1350 = "/copyff3/dest";
  struct guestfs_copy_file_to_file_argv optargs1351;
  optargs1351.append = 1;
  optargs1351.bitmask = UINT64_C(0x10);
  int ret2;
  ret2 = guestfs_copy_file_to_file_argv (g, arg1349, arg1350, &optargs1351);
  if (ret2 == -1)
    return -1;
  const char *arg1352 = "/copyff3/src";
  const char *arg1353 = "/copyff3/dest";
  struct guestfs_copy_file_to_file_argv optargs1354;
  optargs1354.append = 1;
  optargs1354.bitmask = UINT64_C(0x10);
  int ret1;
  ret1 = guestfs_copy_file_to_file_argv (g, arg1352, arg1353, &optargs1354);
  if (ret1 == -1)
    return -1;
  const char *arg1355 = "/copyff3/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, arg1355, &size);
  if (ret == NULL)
      return -1;
  if (! (compare_buffers (ret, size, "hello, worldhello, worldhello, world", 12*3) == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_copy_file_to_file_2", "compare_buffers (ret, size, \"hello, worldhello, worldhello, world\", 12*3) == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_part_to_partnum_0_skip (void);
static int test_part_to_partnum_0_perform (guestfs_h *);

static int
test_part_to_partnum_0 (guestfs_h *g)
{
  if (test_part_to_partnum_0_skip ()) {
    skipped ("test_part_to_partnum_0", "environment variable set");
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_part_to_partnum_0_perform (g);
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
test_part_to_partnum_0_perform (guestfs_h *g)
{
  /* TestResult for part_to_partnum (0) */
  const char *arg1357 = "/dev/sda1";
  int ret;
  ret = guestfs_part_to_partnum (g, arg1357);
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

static int test_part_to_partnum_1_skip (void);
static int test_part_to_partnum_1_perform (guestfs_h *);

static int
test_part_to_partnum_1 (guestfs_h *g)
{
  if (test_part_to_partnum_1_skip ()) {
    skipped ("test_part_to_partnum_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_to_partnum_1_perform (g);
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
test_part_to_partnum_1_perform (guestfs_h *g)
{
  /* TestLastFail for part_to_partnum (1) */
  const char *arg1360 = "/dev/sda";
  int ret1359;
  guestfs_push_error_handler (g, NULL, NULL);
  ret1359 = guestfs_part_to_partnum (g, arg1360);
  guestfs_pop_error_handler (g);
  if (ret1359 != -1)
    return -1;
  return 0;
}

static int test_internal_write_append_0_skip (void);
static int test_internal_write_append_0_perform (guestfs_h *);

static int
test_internal_write_append_0 (guestfs_h *g)
{
  if (test_internal_write_append_0_skip ()) {
    skipped ("test_internal_write_append_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_internal_write_append_0_perform (g);
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
test_internal_write_append_0_perform (guestfs_h *g)
{
  /* TestResultString for internal_write_append (0) */
  const char *arg1363 = "/internal_write_append";
  const char *arg1364 = "line1\n";
  size_t arg1364_size = 6;
  int ret1362;
  ret1362 = guestfs_write (g, arg1363, arg1364, arg1364_size);
  if (ret1362 == -1)
    return -1;
  const char *arg1367 = "/internal_write_append";
  const char *arg1368 = "line2\n";
  size_t arg1368_size = 6;
  int ret1366;
  ret1366 = guestfs_internal_write_append (g, arg1367, arg1368, arg1368_size);
  if (ret1366 == -1)
    return -1;
  const char *arg1371 = "/internal_write_append";
  const char *arg1372 = "line3a";
  size_t arg1372_size = 6;
  int ret1370;
  ret1370 = guestfs_internal_write_append (g, arg1371, arg1372, arg1372_size);
  if (ret1370 == -1)
    return -1;
  const char *arg1375 = "/internal_write_append";
  const char *arg1376 = "line3b\n";
  size_t arg1376_size = 7;
  int ret1374;
  ret1374 = guestfs_internal_write_append (g, arg1375, arg1376, arg1376_size);
  if (ret1374 == -1)
    return -1;
  const char *arg1378 = "/internal_write_append";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg1378);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "line1\nline2\nline3aline3b\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_append_0", "cat", "line1\nline2\nline3aline3b\n", ret);
    return -1;
  }
  return 0;
}

static int test_is_zero_device_0_skip (void);
static int test_is_zero_device_0_perform (guestfs_h *);

static int
test_is_zero_device_0 (guestfs_h *g)
{
  if (test_is_zero_device_0_skip ()) {
    skipped ("test_is_zero_device_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_is_zero_device_0_perform (g);
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
test_is_zero_device_0_perform (guestfs_h *g)
{
  /* TestResultTrue for is_zero_device (0) */
  const char *arg1381 = "/dev/sda1";
  struct guestfs_umount_opts_argv optargs1382;
  optargs1382.force = 0;
  optargs1382.lazyunmount = 0;
  optargs1382.bitmask = UINT64_C(0x3);
  int ret1380;
  ret1380 = guestfs_umount_opts_argv (g, arg1381, &optargs1382);
  if (ret1380 == -1)
    return -1;
  const char *arg1384 = "/dev/sda1";
  int ret1383;
  ret1383 = guestfs_zero_device (g, arg1384);
  if (ret1383 == -1)
    return -1;
  const char *arg1386 = "/dev/sda1";
  int ret;
  ret = guestfs_is_zero_device (g, arg1386);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_zero_device_0", "is_zero_device");
    return -1;
  }
  return 0;
}

static int test_is_zero_device_1_skip (void);
static int test_is_zero_device_1_perform (guestfs_h *);

static int
test_is_zero_device_1 (guestfs_h *g)
{
  if (test_is_zero_device_1_skip ()) {
    skipped ("test_is_zero_device_1", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_is_zero_device_1_perform (g);
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
test_is_zero_device_1_perform (guestfs_h *g)
{
  /* TestResultFalse for is_zero_device (1) */
  const char *arg1388 = "/dev/sda1";
  int ret;
  ret = guestfs_is_zero_device (g, arg1388);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_zero_device_1", "is_zero_device");
    return -1;
  }
  return 0;
}

static int test_is_zero_0_skip (void);
static int test_is_zero_0_perform (guestfs_h *);

static int
test_is_zero_0 (guestfs_h *g)
{
  if (test_is_zero_0_skip ()) {
    skipped ("test_is_zero_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_is_zero_0_perform (g);
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
test_is_zero_0_perform (guestfs_h *g)
{
  /* TestResultTrue for is_zero (0) */
  const char *arg1390 = "/100kallzeroes";
  int ret;
  ret = guestfs_is_zero (g, arg1390);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_zero_0", "is_zero");
    return -1;
  }
  return 0;
}

static int test_is_zero_1_skip (void);
static int test_is_zero_1_perform (guestfs_h *);

static int
test_is_zero_1 (guestfs_h *g)
{
  if (test_is_zero_1_skip ()) {
    skipped ("test_is_zero_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_is_zero_1_perform (g);
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
test_is_zero_1_perform (guestfs_h *g)
{
  /* TestResultFalse for is_zero (1) */
  const char *arg1392 = "/100kallspaces";
  int ret;
  ret = guestfs_is_zero (g, arg1392);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_zero_1", "is_zero");
    return -1;
  }
  return 0;
}

static int test_mkfs_0_skip (void);
static int test_mkfs_0_perform (guestfs_h *);

static int
test_mkfs_0 (guestfs_h *g)
{
  if (test_mkfs_0_skip ()) {
    skipped ("test_mkfs_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mkfs_0_perform (g);
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
test_mkfs_0_perform (guestfs_h *g)
{
  /* TestResultString for mkfs (0) */
  const char *arg1395 = "/dev/sda";
  const char *arg1396 = "mbr";
  int ret1394;
  ret1394 = guestfs_part_disk (g, arg1395, arg1396);
  if (ret1394 == -1)
    return -1;
  const char *arg1399 = "ext2";
  const char *arg1400 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs1401;
  optargs1401.bitmask = UINT64_C(0x0);
  int ret1398;
  ret1398 = guestfs_mkfs_opts_argv (g, arg1399, arg1400, &optargs1401);
  if (ret1398 == -1)
    return -1;
  const char *arg1403 = "/dev/sda1";
  const char *arg1404 = "/";
  int ret1402;
  ret1402 = guestfs_mount (g, arg1403, arg1404);
  if (ret1402 == -1)
    return -1;
  const char *arg1407 = "/new";
  const char *arg1408 = "new file contents";
  size_t arg1408_size = 17;
  int ret1406;
  ret1406 = guestfs_write (g, arg1407, arg1408, arg1408_size);
  if (ret1406 == -1)
    return -1;
  const char *arg1410 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg1410);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mkfs_0", "cat", "new file contents", ret);
    return -1;
  }
  return 0;
}

static int test_lvm_canonical_lv_name_0_skip (void);
static int test_lvm_canonical_lv_name_0_perform (guestfs_h *);

static int
test_lvm_canonical_lv_name_0 (guestfs_h *g)
{
  if (test_lvm_canonical_lv_name_0_skip ()) {
    skipped ("test_lvm_canonical_lv_name_0", "environment variable set");
    return 0;
  }

  const char *features1412[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features1412)) {
    skipped ("test_lvm_canonical_lv_name_0", "group %s not available in daemon",
             features1412[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  return test_lvm_canonical_lv_name_0_perform (g);
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
test_lvm_canonical_lv_name_0_perform (guestfs_h *g)
{
  /* TestResultString for lvm_canonical_lv_name (0) */
  const char *arg1413 = "/dev/mapper/VG-LV";
  CLEANUP_FREE char *ret;
  ret = guestfs_lvm_canonical_lv_name (g, arg1413);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/dev/VG/LV")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_lvm_canonical_lv_name_0", "lvm_canonical_lv_name", "/dev/VG/LV", ret);
    return -1;
  }
  return 0;
}

static int test_lvm_canonical_lv_name_1_skip (void);
static int test_lvm_canonical_lv_name_1_perform (guestfs_h *);

static int
test_lvm_canonical_lv_name_1 (guestfs_h *g)
{
  if (test_lvm_canonical_lv_name_1_skip ()) {
    skipped ("test_lvm_canonical_lv_name_1", "environment variable set");
    return 0;
  }

  const char *features1415[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features1415)) {
    skipped ("test_lvm_canonical_lv_name_1", "group %s not available in daemon",
             features1415[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  return test_lvm_canonical_lv_name_1_perform (g);
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
test_lvm_canonical_lv_name_1_perform (guestfs_h *g)
{
  /* TestResultString for lvm_canonical_lv_name (1) */
  const char *arg1416 = "/dev/VG/LV";
  CLEANUP_FREE char *ret;
  ret = guestfs_lvm_canonical_lv_name (g, arg1416);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/dev/VG/LV")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_lvm_canonical_lv_name_1", "lvm_canonical_lv_name", "/dev/VG/LV", ret);
    return -1;
  }
  return 0;
}

static int test_pread_device_0_skip (void);
static int test_pread_device_0_perform (guestfs_h *);

static int
test_pread_device_0 (guestfs_h *g)
{
  if (test_pread_device_0_skip ()) {
    skipped ("test_pread_device_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_pread_device_0_perform (g);
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
test_pread_device_0_perform (guestfs_h *g)
{
  /* TestResult for pread_device (0) */
  const char *arg1418 = "/dev/sdd";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread_device (g, arg1418, 8, 32768, &size);
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

static int test_pwrite_device_0_skip (void);
static int test_pwrite_device_0_perform (guestfs_h *);

static int
test_pwrite_device_0 (guestfs_h *g)
{
  if (test_pwrite_device_0_skip ()) {
    skipped ("test_pwrite_device_0", "environment variable set");
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_pwrite_device_0_perform (g);
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
test_pwrite_device_0_perform (guestfs_h *g)
{
  /* TestResult for pwrite_device (0) */
  const char *arg1422 = "/dev/sda";
  const char *arg1423 = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
  size_t arg1423_size = 66;
  int ret2;
  ret2 = guestfs_pwrite_device (g, arg1422, arg1423, arg1423_size, 446);
  if (ret2 == -1)
    return -1;
  const char *arg1426 = "/dev/sda";
  int ret1;
  ret1 = guestfs_blockdev_rereadpt (g, arg1426);
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

static int test_download_offset_0_skip (void);
static int test_download_offset_0_perform (guestfs_h *);

static int
test_download_offset_0 (guestfs_h *g)
{
  if (test_download_offset_0_skip ()) {
    skipped ("test_download_offset_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_download_offset_0_perform (g);
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
test_download_offset_0_perform (guestfs_h *g)
{
  /* TestResultString for download_offset (0) */
  const char *arg1430 = "/download_offset";
  int ret1429;
  ret1429 = guestfs_mkdir (g, arg1430);
  if (ret1429 == -1)
    return -1;
  CLEANUP_FREE char *arg1433 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *arg1434 = "/download_offset/COPYING.LIB";
  int ret1432;
  ret1432 = guestfs_upload (g, arg1433, arg1434);
  if (ret1432 == -1)
    return -1;
  const char *arg1437 = "/download_offset/COPYING.LIB";
  int ret1436;
  ret1436 = guestfs_download_offset (g, arg1437, "testdownload.tmp", 100, 26430);
  if (ret1436 == -1)
    return -1;
  CLEANUP_FREE char *arg1443 = substitute_srcdir ("testdownload.tmp");
  const char *arg1444 = "/download_offset/COPYING.LIB";
  int ret1442;
  ret1442 = guestfs_upload_offset (g, arg1443, arg1444, 100);
  if (ret1442 == -1)
    return -1;
  const char *arg1447 = "md5";
  const char *arg1448 = "/download_offset/COPYING.LIB";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, arg1447, arg1448);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "4fbd65380cdd255951079008b364516c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_download_offset_0", "checksum", "4fbd65380cdd255951079008b364516c", ret);
    return -1;
  }
  return 0;
}

static int test_upload_offset_0_skip (void);
static int test_upload_offset_0_perform (guestfs_h *);

static int
test_upload_offset_0 (guestfs_h *g)
{
  if (test_upload_offset_0_skip ()) {
    skipped ("test_upload_offset_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_upload_offset_0_perform (g);
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
test_upload_offset_0_perform (guestfs_h *g)
{
  /* TestResultString for upload_offset (0) */
  CLEANUP_FREE char *arg1451 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *arg1452 = "/upload_offset";
  int ret1450;
  ret1450 = guestfs_upload_offset (g, arg1451, arg1452, 0);
  if (ret1450 == -1)
    return -1;
  const char *arg1455 = "md5";
  const char *arg1456 = "/upload_offset";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, arg1455, arg1456);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "4fbd65380cdd255951079008b364516c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_upload_offset_0", "checksum", "4fbd65380cdd255951079008b364516c", ret);
    return -1;
  }
  return 0;
}

static int test_part_to_dev_0_skip (void);
static int test_part_to_dev_0_perform (guestfs_h *);

static int
test_part_to_dev_0 (guestfs_h *g)
{
  if (test_part_to_dev_0_skip ()) {
    skipped ("test_part_to_dev_0", "environment variable set");
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_part_to_dev_0_perform (g);
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
test_part_to_dev_0_perform (guestfs_h *g)
{
  /* TestResultDevice for part_to_dev (0) */
  const char *arg1458 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_to_dev (g, arg1458);
  if (ret == NULL)
      return -1;
  if (compare_devices (ret, "/dev/sda") != 0) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_part_to_dev_0", "part_to_dev", "/dev/sda", ret);
    return -1;
  }
  return 0;
}

static int test_part_to_dev_1_skip (void);
static int test_part_to_dev_1_perform (guestfs_h *);

static int
test_part_to_dev_1 (guestfs_h *g)
{
  if (test_part_to_dev_1_skip ()) {
    skipped ("test_part_to_dev_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_to_dev_1_perform (g);
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
test_part_to_dev_1_perform (guestfs_h *g)
{
  /* TestLastFail for part_to_dev (1) */
  const char *arg1461 = "/dev/sda";
  CLEANUP_FREE char *ret1460;
  guestfs_push_error_handler (g, NULL, NULL);
  ret1460 = guestfs_part_to_dev (g, arg1461);
  guestfs_pop_error_handler (g);
  if (ret1460 != NULL)
    return -1;
  return 0;
}

static int test_is_socket_0_skip (void);
static int test_is_socket_0_perform (guestfs_h *);

static int
test_is_socket_0 (guestfs_h *g)
{
  if (test_is_socket_0_skip ()) {
    skipped ("test_is_socket_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_is_socket_0_perform (g);
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
test_is_socket_0_perform (guestfs_h *g)
{
  /* TestResultFalse for is_socket (0) */
  const char *arg1463 = "/directory";
  struct guestfs_is_socket_opts_argv optargs1464;
  optargs1464.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_socket_opts_argv (g, arg1463, &optargs1464);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_socket_0", "is_socket");
    return -1;
  }
  return 0;
}

static int test_is_symlink_0_skip (void);
static int test_is_symlink_0_perform (guestfs_h *);

static int
test_is_symlink_0 (guestfs_h *g)
{
  if (test_is_symlink_0_skip ()) {
    skipped ("test_is_symlink_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_is_symlink_0_perform (g);
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
test_is_symlink_0_perform (guestfs_h *g)
{
  /* TestResultFalse for is_symlink (0) */
  const char *arg1465 = "/directory";
  int ret;
  ret = guestfs_is_symlink (g, arg1465);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_symlink_0", "is_symlink");
    return -1;
  }
  return 0;
}

static int test_is_symlink_1_skip (void);
static int test_is_symlink_1_perform (guestfs_h *);

static int
test_is_symlink_1 (guestfs_h *g)
{
  if (test_is_symlink_1_skip ()) {
    skipped ("test_is_symlink_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_is_symlink_1_perform (g);
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
test_is_symlink_1_perform (guestfs_h *g)
{
  /* TestResultTrue for is_symlink (1) */
  const char *arg1467 = "/abssymlink";
  int ret;
  ret = guestfs_is_symlink (g, arg1467);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_symlink_1", "is_symlink");
    return -1;
  }
  return 0;
}

static int test_is_fifo_0_skip (void);
static int test_is_fifo_0_perform (guestfs_h *);

static int
test_is_fifo_0 (guestfs_h *g)
{
  if (test_is_fifo_0_skip ()) {
    skipped ("test_is_fifo_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_is_fifo_0_perform (g);
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
test_is_fifo_0_perform (guestfs_h *g)
{
  /* TestResultFalse for is_fifo (0) */
  const char *arg1469 = "/directory";
  struct guestfs_is_fifo_opts_argv optargs1470;
  optargs1470.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_fifo_opts_argv (g, arg1469, &optargs1470);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_fifo_0", "is_fifo");
    return -1;
  }
  return 0;
}

static int test_is_fifo_1_skip (void);
static int test_is_fifo_1_perform (guestfs_h *);

static int
test_is_fifo_1 (guestfs_h *g)
{
  if (test_is_fifo_1_skip ()) {
    skipped ("test_is_fifo_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_is_fifo_1_perform (g);
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
test_is_fifo_1_perform (guestfs_h *g)
{
  /* TestResultTrue for is_fifo (1) */
  const char *arg1473 = "/is_fifo";
  int ret1471;
  ret1471 = guestfs_mkfifo (g, 511, arg1473);
  if (ret1471 == -1)
    return -1;
  const char *arg1475 = "/is_fifo";
  struct guestfs_is_fifo_opts_argv optargs1476;
  optargs1476.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_fifo_opts_argv (g, arg1475, &optargs1476);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_fifo_1", "is_fifo");
    return -1;
  }
  return 0;
}

static int test_is_blockdev_0_skip (void);
static int test_is_blockdev_0_perform (guestfs_h *);

static int
test_is_blockdev_0 (guestfs_h *g)
{
  if (test_is_blockdev_0_skip ()) {
    skipped ("test_is_blockdev_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_is_blockdev_0_perform (g);
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
test_is_blockdev_0_perform (guestfs_h *g)
{
  /* TestResultFalse for is_blockdev (0) */
  const char *arg1477 = "/directory";
  struct guestfs_is_blockdev_opts_argv optargs1478;
  optargs1478.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_blockdev_opts_argv (g, arg1477, &optargs1478);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_blockdev_0", "is_blockdev");
    return -1;
  }
  return 0;
}

static int test_is_blockdev_1_skip (void);
static int test_is_blockdev_1_perform (guestfs_h *);

static int
test_is_blockdev_1 (guestfs_h *g)
{
  if (test_is_blockdev_1_skip ()) {
    skipped ("test_is_blockdev_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_is_blockdev_1_perform (g);
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
test_is_blockdev_1_perform (guestfs_h *g)
{
  /* TestResultTrue for is_blockdev (1) */
  const char *arg1483 = "/is_blockdev";
  int ret1479;
  ret1479 = guestfs_mknod_b (g, 511, 99, 66, arg1483);
  if (ret1479 == -1)
    return -1;
  const char *arg1485 = "/is_blockdev";
  struct guestfs_is_blockdev_opts_argv optargs1486;
  optargs1486.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_blockdev_opts_argv (g, arg1485, &optargs1486);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_blockdev_1", "is_blockdev");
    return -1;
  }
  return 0;
}

static int test_is_chardev_0_skip (void);
static int test_is_chardev_0_perform (guestfs_h *);

static int
test_is_chardev_0 (guestfs_h *g)
{
  if (test_is_chardev_0_skip ()) {
    skipped ("test_is_chardev_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_is_chardev_0_perform (g);
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
test_is_chardev_0_perform (guestfs_h *g)
{
  /* TestResultFalse for is_chardev (0) */
  const char *arg1487 = "/directory";
  struct guestfs_is_chardev_opts_argv optargs1488;
  optargs1488.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_chardev_opts_argv (g, arg1487, &optargs1488);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_chardev_0", "is_chardev");
    return -1;
  }
  return 0;
}

static int test_is_chardev_1_skip (void);
static int test_is_chardev_1_perform (guestfs_h *);

static int
test_is_chardev_1 (guestfs_h *g)
{
  if (test_is_chardev_1_skip ()) {
    skipped ("test_is_chardev_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_is_chardev_1_perform (g);
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
test_is_chardev_1_perform (guestfs_h *g)
{
  /* TestResultTrue for is_chardev (1) */
  const char *arg1493 = "/is_chardev";
  int ret1489;
  ret1489 = guestfs_mknod_c (g, 511, 99, 66, arg1493);
  if (ret1489 == -1)
    return -1;
  const char *arg1495 = "/is_chardev";
  struct guestfs_is_chardev_opts_argv optargs1496;
  optargs1496.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_chardev_opts_argv (g, arg1495, &optargs1496);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_chardev_1", "is_chardev");
    return -1;
  }
  return 0;
}

static int test_is_lv_0_skip (void);
static int test_is_lv_0_perform (guestfs_h *);

static int
test_is_lv_0 (guestfs_h *g)
{
  if (test_is_lv_0_skip ()) {
    skipped ("test_is_lv_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  return test_is_lv_0_perform (g);
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
test_is_lv_0_perform (guestfs_h *g)
{
  /* TestResultTrue for is_lv (0) */
  const char *arg1497 = "/dev/VG/LV";
  int ret;
  ret = guestfs_is_lv (g, arg1497);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_lv_0", "is_lv");
    return -1;
  }
  return 0;
}

static int test_is_lv_1_skip (void);
static int test_is_lv_1_perform (guestfs_h *);

static int
test_is_lv_1 (guestfs_h *g)
{
  if (test_is_lv_1_skip ()) {
    skipped ("test_is_lv_1", "environment variable set");
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  return test_is_lv_1_perform (g);
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
test_is_lv_1_perform (guestfs_h *g)
{
  /* TestResultFalse for is_lv (1) */
  const char *arg1499 = "/dev/sda1";
  int ret;
  ret = guestfs_is_lv (g, arg1499);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_lv_1", "is_lv");
    return -1;
  }
  return 0;
}

static int test_vfs_uuid_0_skip (void);
static int test_vfs_uuid_0_perform (guestfs_h *);

static int
test_vfs_uuid_0 (guestfs_h *g)
{
  if (test_vfs_uuid_0_skip ()) {
    skipped ("test_vfs_uuid_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_vfs_uuid_0_perform (g);
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
test_vfs_uuid_0_perform (guestfs_h *g)
{
  /* TestResultString for vfs_uuid (0) */
  const char *arg1502 = "/dev/sda1";
  const char *arg1503 = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  int ret1501;
  ret1501 = guestfs_set_e2uuid (g, arg1502, arg1503);
  if (ret1501 == -1)
    return -1;
  const char *arg1505 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_uuid (g, arg1505);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_vfs_uuid_0", "vfs_uuid", "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc", ret);
    return -1;
  }
  return 0;
}

static int test_vfs_label_0_skip (void);
static int test_vfs_label_0_perform (guestfs_h *);

static int
test_vfs_label_0 (guestfs_h *g)
{
  if (test_vfs_label_0_skip ()) {
    skipped ("test_vfs_label_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_vfs_label_0_perform (g);
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
test_vfs_label_0_perform (guestfs_h *g)
{
  /* TestResultString for vfs_label (0) */
  const char *arg1508 = "/dev/sda1";
  const char *arg1509 = "LTEST";
  int ret1507;
  ret1507 = guestfs_set_label (g, arg1508, arg1509);
  if (ret1507 == -1)
    return -1;
  const char *arg1511 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, arg1511);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "LTEST")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_vfs_label_0", "vfs_label", "LTEST", ret);
    return -1;
  }
  return 0;
}

static int test_vfs_label_1_skip (void);
static int test_vfs_label_1_perform (guestfs_h *);

static int
test_vfs_label_1 (guestfs_h *g)
{
  if (test_vfs_label_1_skip ()) {
    skipped ("test_vfs_label_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_vfs_label_1_perform (g);
}

static int
test_vfs_label_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vfs_label") == NULL;
  str = getenv ("SKIP_TEST_VFS_LABEL_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VFS_LABEL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vfs_label_1_perform (guestfs_h *g)
{
  /* TestResultString for vfs_label (1) */
  const char *arg1514 = "/dev/sda";
  const char *arg1515 = "mbr";
  int ret1513;
  ret1513 = guestfs_part_disk (g, arg1514, arg1515);
  if (ret1513 == -1)
    return -1;
  const char *arg1518 = "ext2";
  const char *arg1519 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs1520;
  optargs1520.label = "test-label";
  optargs1520.bitmask = UINT64_C(0x10);
  int ret1517;
  ret1517 = guestfs_mkfs_opts_argv (g, arg1518, arg1519, &optargs1520);
  if (ret1517 == -1)
    return -1;
  const char *arg1521 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, arg1521);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "test-label")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_vfs_label_1", "vfs_label", "test-label", ret);
    return -1;
  }
  return 0;
}

static int test_vfs_label_2_skip (void);
static int test_vfs_label_2_perform (guestfs_h *);

static int
test_vfs_label_2 (guestfs_h *g)
{
  if (test_vfs_label_2_skip ()) {
    skipped ("test_vfs_label_2", "environment variable set");
    return 0;
  }

  const char *features1523[] = { "btrfs", NULL };
  if (!guestfs_feature_available (g, (char **) features1523)) {
    skipped ("test_vfs_label_2", "group %s not available in daemon",
             features1523[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_vfs_label_2_perform (g);
}

static int
test_vfs_label_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vfs_label") == NULL;
  str = getenv ("SKIP_TEST_VFS_LABEL_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VFS_LABEL");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vfs_label_2_perform (guestfs_h *g)
{
  /* TestResultString for vfs_label (2) */
  const char *arg1525 = "/dev/sda";
  const char *arg1526 = "mbr";
  int ret1524;
  ret1524 = guestfs_part_disk (g, arg1525, arg1526);
  if (ret1524 == -1)
    return -1;
  const char *arg1529 = "btrfs";
  const char *arg1530 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs1531;
  optargs1531.label = "";
  optargs1531.bitmask = UINT64_C(0x10);
  int ret1528;
  ret1528 = guestfs_mkfs_opts_argv (g, arg1529, arg1530, &optargs1531);
  if (ret1528 == -1)
    return -1;
  const char *arg1533 = "/dev/sda1";
  const char *arg1534 = "test-label-btrfs";
  int ret1532;
  ret1532 = guestfs_set_label (g, arg1533, arg1534);
  if (ret1532 == -1)
    return -1;
  const char *arg1536 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, arg1536);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "test-label-btrfs")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_vfs_label_2", "vfs_label", "test-label-btrfs", ret);
    return -1;
  }
  return 0;
}

static int test_fallocate64_0_skip (void);
static int test_fallocate64_0_perform (guestfs_h *);

static int
test_fallocate64_0 (guestfs_h *g)
{
  if (test_fallocate64_0_skip ()) {
    skipped ("test_fallocate64_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_fallocate64_0_perform (g);
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
test_fallocate64_0_perform (guestfs_h *g)
{
  /* TestResult for fallocate64 (0) */
  const char *arg1538 = "/fallocate64";
  int ret1;
  ret1 = guestfs_fallocate64 (g, arg1538, 1000000);
  if (ret1 == -1)
    return -1;
  const char *arg1541 = "/fallocate64";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg1541);
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

static int test_available_all_groups_0_skip (void);
static int test_available_all_groups_0_perform (guestfs_h *);

static int
test_available_all_groups_0 (guestfs_h *g)
{
  if (test_available_all_groups_0_skip ()) {
    skipped ("test_available_all_groups_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_available_all_groups_0_perform (g);
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
test_available_all_groups_0_perform (guestfs_h *g)
{
  /* TestRun for available_all_groups (0) */
  CLEANUP_FREE_STRING_LIST char **ret1543;
  ret1543 = guestfs_available_all_groups (g);
  if (ret1543 == NULL)
      return -1;
  return 0;
}

static int test_pwrite_0_skip (void);
static int test_pwrite_0_perform (guestfs_h *);

static int
test_pwrite_0 (guestfs_h *g)
{
  if (test_pwrite_0_skip ()) {
    skipped ("test_pwrite_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_pwrite_0_perform (g);
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
test_pwrite_0_perform (guestfs_h *g)
{
  /* TestResultString for pwrite (0) */
  const char *arg1546 = "/pwrite";
  const char *arg1547 = "new file contents";
  size_t arg1547_size = 17;
  int ret1545;
  ret1545 = guestfs_write (g, arg1546, arg1547, arg1547_size);
  if (ret1545 == -1)
    return -1;
  const char *arg1550 = "/pwrite";
  const char *arg1551 = "data";
  size_t arg1551_size = 4;
  int ret1549;
  ret1549 = guestfs_pwrite (g, arg1550, arg1551, arg1551_size, 4);
  if (ret1549 == -1)
    return -1;
  const char *arg1554 = "/pwrite";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg1554);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new data contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_pwrite_0", "cat", "new data contents", ret);
    return -1;
  }
  return 0;
}

static int test_pwrite_1_skip (void);
static int test_pwrite_1_perform (guestfs_h *);

static int
test_pwrite_1 (guestfs_h *g)
{
  if (test_pwrite_1_skip ()) {
    skipped ("test_pwrite_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_pwrite_1_perform (g);
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
test_pwrite_1_perform (guestfs_h *g)
{
  /* TestResultString for pwrite (1) */
  const char *arg1557 = "/pwrite2";
  const char *arg1558 = "new file contents";
  size_t arg1558_size = 17;
  int ret1556;
  ret1556 = guestfs_write (g, arg1557, arg1558, arg1558_size);
  if (ret1556 == -1)
    return -1;
  const char *arg1561 = "/pwrite2";
  const char *arg1562 = "is extended";
  size_t arg1562_size = 11;
  int ret1560;
  ret1560 = guestfs_pwrite (g, arg1561, arg1562, arg1562_size, 9);
  if (ret1560 == -1)
    return -1;
  const char *arg1565 = "/pwrite2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg1565);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file is extended")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_pwrite_1", "cat", "new file is extended", ret);
    return -1;
  }
  return 0;
}

static int test_pwrite_2_skip (void);
static int test_pwrite_2_perform (guestfs_h *);

static int
test_pwrite_2 (guestfs_h *g)
{
  if (test_pwrite_2_skip ()) {
    skipped ("test_pwrite_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_pwrite_2_perform (g);
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
test_pwrite_2_perform (guestfs_h *g)
{
  /* TestResultString for pwrite (2) */
  const char *arg1568 = "/pwrite3";
  const char *arg1569 = "new file contents";
  size_t arg1569_size = 17;
  int ret1567;
  ret1567 = guestfs_write (g, arg1568, arg1569, arg1569_size);
  if (ret1567 == -1)
    return -1;
  const char *arg1572 = "/pwrite3";
  const char *arg1573 = "";
  size_t arg1573_size = 0;
  int ret1571;
  ret1571 = guestfs_pwrite (g, arg1572, arg1573, arg1573_size, 4);
  if (ret1571 == -1)
    return -1;
  const char *arg1576 = "/pwrite3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg1576);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_pwrite_2", "cat", "new file contents", ret);
    return -1;
  }
  return 0;
}

static int test_internal_write_0_skip (void);
static int test_internal_write_0_perform (guestfs_h *);

static int
test_internal_write_0 (guestfs_h *g)
{
  if (test_internal_write_0_skip ()) {
    skipped ("test_internal_write_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_internal_write_0_perform (g);
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
test_internal_write_0_perform (guestfs_h *g)
{
  /* TestResultString for internal_write (0) */
  const char *arg1579 = "/internal_write";
  const char *arg1580 = "new file contents";
  size_t arg1580_size = 17;
  int ret1578;
  ret1578 = guestfs_internal_write (g, arg1579, arg1580, arg1580_size);
  if (ret1578 == -1)
    return -1;
  const char *arg1582 = "/internal_write";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg1582);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_0", "cat", "new file contents", ret);
    return -1;
  }
  return 0;
}

static int test_internal_write_1_skip (void);
static int test_internal_write_1_perform (guestfs_h *);

static int
test_internal_write_1 (guestfs_h *g)
{
  if (test_internal_write_1_skip ()) {
    skipped ("test_internal_write_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_internal_write_1_perform (g);
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
test_internal_write_1_perform (guestfs_h *g)
{
  /* TestResultString for internal_write (1) */
  const char *arg1585 = "/internal_write2";
  const char *arg1586 = "\nnew file contents\n";
  size_t arg1586_size = 19;
  int ret1584;
  ret1584 = guestfs_internal_write (g, arg1585, arg1586, arg1586_size);
  if (ret1584 == -1)
    return -1;
  const char *arg1588 = "/internal_write2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg1588);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\nnew file contents\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_1", "cat", "\nnew file contents\n", ret);
    return -1;
  }
  return 0;
}

static int test_internal_write_2_skip (void);
static int test_internal_write_2_perform (guestfs_h *);

static int
test_internal_write_2 (guestfs_h *g)
{
  if (test_internal_write_2_skip ()) {
    skipped ("test_internal_write_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_internal_write_2_perform (g);
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
test_internal_write_2_perform (guestfs_h *g)
{
  /* TestResultString for internal_write (2) */
  const char *arg1591 = "/internal_write3";
  const char *arg1592 = "\n\n";
  size_t arg1592_size = 2;
  int ret1590;
  ret1590 = guestfs_internal_write (g, arg1591, arg1592, arg1592_size);
  if (ret1590 == -1)
    return -1;
  const char *arg1594 = "/internal_write3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg1594);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_2", "cat", "\n\n", ret);
    return -1;
  }
  return 0;
}

static int test_internal_write_3_skip (void);
static int test_internal_write_3_perform (guestfs_h *);

static int
test_internal_write_3 (guestfs_h *g)
{
  if (test_internal_write_3_skip ()) {
    skipped ("test_internal_write_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_internal_write_3_perform (g);
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
test_internal_write_3_perform (guestfs_h *g)
{
  /* TestResultString for internal_write (3) */
  const char *arg1597 = "/internal_write4";
  const char *arg1598 = "";
  size_t arg1598_size = 0;
  int ret1596;
  ret1596 = guestfs_internal_write (g, arg1597, arg1598, arg1598_size);
  if (ret1596 == -1)
    return -1;
  const char *arg1600 = "/internal_write4";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg1600);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_3", "cat", "", ret);
    return -1;
  }
  return 0;
}

static int test_internal_write_4_skip (void);
static int test_internal_write_4_perform (guestfs_h *);

static int
test_internal_write_4 (guestfs_h *g)
{
  if (test_internal_write_4_skip ()) {
    skipped ("test_internal_write_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_internal_write_4_perform (g);
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
test_internal_write_4_perform (guestfs_h *g)
{
  /* TestResultString for internal_write (4) */
  const char *arg1603 = "/internal_write5";
  const char *arg1604 = "\n\n\n";
  size_t arg1604_size = 3;
  int ret1602;
  ret1602 = guestfs_internal_write (g, arg1603, arg1604, arg1604_size);
  if (ret1602 == -1)
    return -1;
  const char *arg1606 = "/internal_write5";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg1606);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_4", "cat", "\n\n\n", ret);
    return -1;
  }
  return 0;
}

static int test_internal_write_5_skip (void);
static int test_internal_write_5_perform (guestfs_h *);

static int
test_internal_write_5 (guestfs_h *g)
{
  if (test_internal_write_5_skip ()) {
    skipped ("test_internal_write_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_internal_write_5_perform (g);
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
test_internal_write_5_perform (guestfs_h *g)
{
  /* TestResultString for internal_write (5) */
  const char *arg1609 = "/internal_write6";
  const char *arg1610 = "\n";
  size_t arg1610_size = 1;
  int ret1608;
  ret1608 = guestfs_internal_write (g, arg1609, arg1610, arg1610_size);
  if (ret1608 == -1)
    return -1;
  const char *arg1612 = "/internal_write6";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg1612);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_internal_write_5", "cat", "\n", ret);
    return -1;
  }
  return 0;
}

static int test_fill_pattern_0_skip (void);
static int test_fill_pattern_0_perform (guestfs_h *);

static int
test_fill_pattern_0 (guestfs_h *g)
{
  if (test_fill_pattern_0_skip ()) {
    skipped ("test_fill_pattern_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_fill_pattern_0_perform (g);
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
test_fill_pattern_0_perform (guestfs_h *g)
{
  /* TestResult for fill_pattern (0) */
  const char *arg1614 = "abcdefghijklmnopqrstuvwxyz";
  const char *arg1616 = "/fill_pattern";
  int ret1;
  ret1 = guestfs_fill_pattern (g, arg1614, 28, arg1616);
  if (ret1 == -1)
    return -1;
  const char *arg1618 = "/fill_pattern";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, arg1618, &size);
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

static int test_base64_in_0_skip (void);
static int test_base64_in_0_perform (guestfs_h *);

static int
test_base64_in_0 (guestfs_h *g)
{
  if (test_base64_in_0_skip ()) {
    skipped ("test_base64_in_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_base64_in_0_perform (g);
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
test_base64_in_0_perform (guestfs_h *g)
{
  /* TestResultString for base64_in (0) */
  CLEANUP_FREE char *arg1621 = substitute_srcdir ("../../test-data/files/hello.b64");
  const char *arg1622 = "/base64_in";
  int ret1620;
  ret1620 = guestfs_base64_in (g, arg1621, arg1622);
  if (ret1620 == -1)
    return -1;
  const char *arg1624 = "/base64_in";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg1624);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "hello\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_base64_in_0", "cat", "hello\n", ret);
    return -1;
  }
  return 0;
}

static int test_get_umask_0_skip (void);
static int test_get_umask_0_perform (guestfs_h *);

static int
test_get_umask_0 (guestfs_h *g)
{
  if (test_get_umask_0_skip ()) {
    skipped ("test_get_umask_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_get_umask_0_perform (g);
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
test_get_umask_0_perform (guestfs_h *g)
{
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

static int test_lvresize_free_0_skip (void);
static int test_lvresize_free_0_perform (guestfs_h *);

static int
test_lvresize_free_0 (guestfs_h *g)
{
  if (test_lvresize_free_0_skip ()) {
    skipped ("test_lvresize_free_0", "environment variable set");
    return 0;
  }

  const char *features1627[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features1627)) {
    skipped ("test_lvresize_free_0", "group %s not available in daemon",
             features1627[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_lvresize_free_0_perform (g);
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
test_lvresize_free_0_perform (guestfs_h *g)
{
  /* TestRun for lvresize_free (0) */
  const char *arg1629 = "/dev/sda";
  const char *arg1630 = "mbr";
  int ret1628;
  ret1628 = guestfs_part_disk (g, arg1629, arg1630);
  if (ret1628 == -1)
    return -1;
  const char *arg1633 = "/dev/sda1";
  int ret1632;
  ret1632 = guestfs_pvcreate (g, arg1633);
  if (ret1632 == -1)
    return -1;
  const char *arg1636 = "VG";
  const char *arg1637_0 = "/dev/sda1";
  const char *const arg1637[] = {
    arg1637_0,
    NULL
  };
  int ret1635;
  ret1635 = guestfs_vgcreate (g, arg1636, (char **) arg1637);
  if (ret1635 == -1)
    return -1;
  const char *arg1640 = "LV";
  const char *arg1641 = "VG";
  int ret1639;
  ret1639 = guestfs_lvcreate (g, arg1640, arg1641, 10);
  if (ret1639 == -1)
    return -1;
  const char *arg1645 = "/dev/VG/LV";
  int ret1644;
  ret1644 = guestfs_lvresize_free (g, arg1645, 100);
  if (ret1644 == -1)
    return -1;
  return 0;
}

static int test_checksum_device_0_skip (void);
static int test_checksum_device_0_perform (guestfs_h *);

static int
test_checksum_device_0 (guestfs_h *g)
{
  if (test_checksum_device_0_skip ()) {
    skipped ("test_checksum_device_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_checksum_device_0_perform (g);
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
test_checksum_device_0_perform (guestfs_h *g)
{
  /* TestResult for checksum_device (0) */
  const char *arg1648 = "md5";
  const char *arg1649 = "/dev/sdd";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum_device (g, arg1648, arg1649);
  if (ret == NULL)
      return -1;
  if (! (check_file_md5 (ret, "../../test-data/test.iso") == 0)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_checksum_device_0", "check_file_md5 (ret, \"../../test-data/test.iso\") == 0");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_part_get_mbr_id_0_skip (void);
static int test_part_get_mbr_id_0_perform (guestfs_h *);

static int
test_part_get_mbr_id_0 (guestfs_h *g)
{
  if (test_part_get_mbr_id_0_skip ()) {
    skipped ("test_part_get_mbr_id_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_get_mbr_id_0_perform (g);
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
test_part_get_mbr_id_0_perform (guestfs_h *g)
{
  /* TestResult for part_get_mbr_id (0) */
  const char *arg1651 = "/dev/sda";
  const char *arg1652 = "mbr";
  int ret3;
  ret3 = guestfs_part_init (g, arg1651, arg1652);
  if (ret3 == -1)
    return -1;
  const char *arg1654 = "/dev/sda";
  const char *arg1655 = "primary";
  int ret2;
  ret2 = guestfs_part_add (g, arg1654, arg1655, 1, -1);
  if (ret2 == -1)
    return -1;
  const char *arg1659 = "/dev/sda";
  int ret1;
  ret1 = guestfs_part_set_mbr_id (g, arg1659, 1, 127);
  if (ret1 == -1)
    return -1;
  const char *arg1663 = "/dev/sda";
  int ret;
  ret = guestfs_part_get_mbr_id (g, arg1663, 1);
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

static int test_part_get_bootable_0_skip (void);
static int test_part_get_bootable_0_perform (guestfs_h *);

static int
test_part_get_bootable_0 (guestfs_h *g)
{
  if (test_part_get_bootable_0_skip ()) {
    skipped ("test_part_get_bootable_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_get_bootable_0_perform (g);
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
test_part_get_bootable_0_perform (guestfs_h *g)
{
  /* TestResultTrue for part_get_bootable (0) */
  const char *arg1667 = "/dev/sda";
  const char *arg1668 = "mbr";
  int ret1666;
  ret1666 = guestfs_part_init (g, arg1667, arg1668);
  if (ret1666 == -1)
    return -1;
  const char *arg1671 = "/dev/sda";
  const char *arg1672 = "primary";
  int ret1670;
  ret1670 = guestfs_part_add (g, arg1671, arg1672, 1, -1);
  if (ret1670 == -1)
    return -1;
  const char *arg1677 = "/dev/sda";
  int ret1676;
  ret1676 = guestfs_part_set_bootable (g, arg1677, 1, 1);
  if (ret1676 == -1)
    return -1;
  const char *arg1681 = "/dev/sda";
  int ret;
  ret = guestfs_part_get_bootable (g, arg1681, 1);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_part_get_bootable_0", "part_get_bootable");
    return -1;
  }
  return 0;
}

static int test_part_del_0_skip (void);
static int test_part_del_0_perform (guestfs_h *);

static int
test_part_del_0 (guestfs_h *g)
{
  if (test_part_del_0_skip ()) {
    skipped ("test_part_del_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_del_0_perform (g);
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
test_part_del_0_perform (guestfs_h *g)
{
  /* TestRun for part_del (0) */
  const char *arg1685 = "/dev/sda";
  const char *arg1686 = "mbr";
  int ret1684;
  ret1684 = guestfs_part_init (g, arg1685, arg1686);
  if (ret1684 == -1)
    return -1;
  const char *arg1689 = "/dev/sda";
  const char *arg1690 = "primary";
  int ret1688;
  ret1688 = guestfs_part_add (g, arg1689, arg1690, 1, -1);
  if (ret1688 == -1)
    return -1;
  const char *arg1695 = "/dev/sda";
  int ret1694;
  ret1694 = guestfs_part_del (g, arg1695, 1);
  if (ret1694 == -1)
    return -1;
  return 0;
}

static int test_vgscan_0_skip (void);
static int test_vgscan_0_perform (guestfs_h *);

static int
test_vgscan_0 (guestfs_h *g)
{
  if (test_vgscan_0_skip ()) {
    skipped ("test_vgscan_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_vgscan_0_perform (g);
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
test_vgscan_0_perform (guestfs_h *g)
{
  /* TestRun for vgscan (0) */
  int ret1698;
  ret1698 = guestfs_vgscan (g);
  if (ret1698 == -1)
    return -1;
  return 0;
}

static int test_txz_in_0_skip (void);
static int test_txz_in_0_perform (guestfs_h *);

static int
test_txz_in_0 (guestfs_h *g)
{
  if (test_txz_in_0_skip ()) {
    skipped ("test_txz_in_0", "environment variable set");
    return 0;
  }

  const char *features1700[] = { "xz", NULL };
  if (!guestfs_feature_available (g, (char **) features1700)) {
    skipped ("test_txz_in_0", "group %s not available in daemon",
             features1700[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_txz_in_0_perform (g);
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
test_txz_in_0_perform (guestfs_h *g)
{
  /* TestResultString for txz_in (0) */
  const char *arg1702 = "/txz_in";
  int ret1701;
  ret1701 = guestfs_mkdir (g, arg1702);
  if (ret1701 == -1)
    return -1;
  CLEANUP_FREE char *arg1705 = substitute_srcdir ("$srcdir/../../test-data/files/helloworld.tar.xz");
  const char *arg1706 = "/txz_in";
  int ret1704;
  ret1704 = guestfs_txz_in (g, arg1705, arg1706);
  if (ret1704 == -1)
    return -1;
  const char *arg1708 = "/txz_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg1708);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "hello\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_txz_in_0", "cat", "hello\n", ret);
    return -1;
  }
  return 0;
}

static int test_zero_device_0_skip (void);
static int test_zero_device_0_perform (guestfs_h *);

static int
test_zero_device_0 (guestfs_h *g)
{
  if (test_zero_device_0_skip ()) {
    skipped ("test_zero_device_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  return test_zero_device_0_perform (g);
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
test_zero_device_0_perform (guestfs_h *g)
{
  /* TestRun for zero_device (0) */
  const char *arg1711 = "/dev/VG/LV";
  int ret1710;
  ret1710 = guestfs_zero_device (g, arg1711);
  if (ret1710 == -1)
    return -1;
  return 0;
}

static int test_copy_size_0_skip (void);
static int test_copy_size_0_perform (guestfs_h *);

static int
test_copy_size_0 (guestfs_h *g)
{
  if (test_copy_size_0_skip ()) {
    skipped ("test_copy_size_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_copy_size_0_perform (g);
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
test_copy_size_0_perform (guestfs_h *g)
{
  /* TestResult for copy_size (0) */
  const char *arg1713 = "/copy_size";
  int ret3;
  ret3 = guestfs_mkdir (g, arg1713);
  if (ret3 == -1)
    return -1;
  const char *arg1715 = "/copy_size/src";
  const char *arg1716 = "hello, world";
  size_t arg1716_size = 12;
  int ret2;
  ret2 = guestfs_write (g, arg1715, arg1716, arg1716_size);
  if (ret2 == -1)
    return -1;
  const char *arg1718 = "/copy_size/src";
  const char *arg1719 = "/copy_size/dest";
  int ret1;
  ret1 = guestfs_copy_size (g, arg1718, arg1719, 5);
  if (ret1 == -1)
    return -1;
  const char *arg1722 = "/copy_size/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, arg1722, &size);
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

static int test_initrd_cat_0_skip (void);
static int test_initrd_cat_0_perform (guestfs_h *);

static int
test_initrd_cat_0 (guestfs_h *g)
{
  if (test_initrd_cat_0_skip ()) {
    skipped ("test_initrd_cat_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_initrd_cat_0_perform (g);
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
test_initrd_cat_0_perform (guestfs_h *g)
{
  /* TestResult for initrd_cat (0) */
  const char *arg1724 = "/initrd";
  const char *arg1725 = "known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_initrd_cat (g, arg1724, arg1725, &size);
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

static int test_vgrename_0_skip (void);
static int test_vgrename_0_perform (guestfs_h *);

static int
test_vgrename_0 (guestfs_h *g)
{
  if (test_vgrename_0_skip ()) {
    skipped ("test_vgrename_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  return test_vgrename_0_perform (g);
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
test_vgrename_0_perform (guestfs_h *g)
{
  /* TestResult for vgrename (0) */
  const char *arg1727 = "/";
  struct guestfs_umount_opts_argv optargs1728;
  optargs1728.force = 0;
  optargs1728.lazyunmount = 0;
  optargs1728.bitmask = UINT64_C(0x3);
  int ret5;
  ret5 = guestfs_umount_opts_argv (g, arg1727, &optargs1728);
  if (ret5 == -1)
    return -1;
  const char *arg1730_0 = "VG";
  const char *const arg1730[] = {
    arg1730_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vg_activate (g, 0, (char **) arg1730);
  if (ret4 == -1)
    return -1;
  const char *arg1732 = "VG";
  const char *arg1733 = "VG2";
  int ret3;
  ret3 = guestfs_vgrename (g, arg1732, arg1733);
  if (ret3 == -1)
    return -1;
  const char *arg1736_0 = "VG2";
  const char *const arg1736[] = {
    arg1736_0,
    NULL
  };
  int ret2;
  ret2 = guestfs_vg_activate (g, 1, (char **) arg1736);
  if (ret2 == -1)
    return -1;
  const char *arg1738 = "/dev/VG2/LV";
  const char *arg1739 = "/";
  int ret1;
  ret1 = guestfs_mount (g, arg1738, arg1739);
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

static int test_lvrename_0_skip (void);
static int test_lvrename_0_perform (guestfs_h *);

static int
test_lvrename_0 (guestfs_h *g)
{
  if (test_lvrename_0_skip ()) {
    skipped ("test_lvrename_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  return test_lvrename_0_perform (g);
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
test_lvrename_0_perform (guestfs_h *g)
{
  /* TestResult for lvrename (0) */
  const char *arg1742 = "/dev/VG/LV";
  const char *arg1743 = "/dev/VG/LV2";
  int ret1;
  ret1 = guestfs_lvrename (g, arg1742, arg1743);
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

static int test_filesize_0_skip (void);
static int test_filesize_0_perform (guestfs_h *);

static int
test_filesize_0 (guestfs_h *g)
{
  if (test_filesize_0_skip ()) {
    skipped ("test_filesize_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_filesize_0_perform (g);
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
test_filesize_0_perform (guestfs_h *g)
{
  /* TestResult for filesize (0) */
  const char *arg1746 = "/filesize";
  const char *arg1747 = "hello, world";
  size_t arg1747_size = 12;
  int ret1;
  ret1 = guestfs_write (g, arg1746, arg1747, arg1747_size);
  if (ret1 == -1)
    return -1;
  const char *arg1749 = "/filesize";
  int64_t ret;
  ret = guestfs_filesize (g, arg1749);
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

static int test_dd_0_skip (void);
static int test_dd_0_perform (guestfs_h *);

static int
test_dd_0 (guestfs_h *g)
{
  if (test_dd_0_skip ()) {
    skipped ("test_dd_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_dd_0_perform (g);
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
test_dd_0_perform (guestfs_h *g)
{
  /* TestResult for dd (0) */
  const char *arg1751 = "/dd";
  int ret3;
  ret3 = guestfs_mkdir (g, arg1751);
  if (ret3 == -1)
    return -1;
  const char *arg1753 = "/dd/src";
  const char *arg1754 = "hello, world";
  size_t arg1754_size = 12;
  int ret2;
  ret2 = guestfs_write (g, arg1753, arg1754, arg1754_size);
  if (ret2 == -1)
    return -1;
  const char *arg1756 = "/dd/src";
  const char *arg1757 = "/dd/dest";
  int ret1;
  ret1 = guestfs_dd (g, arg1756, arg1757);
  if (ret1 == -1)
    return -1;
  const char *arg1759 = "/dd/dest";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, arg1759, &size);
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

static int test_fill_0_skip (void);
static int test_fill_0_perform (guestfs_h *);

static int
test_fill_0 (guestfs_h *g)
{
  if (test_fill_0_skip ()) {
    skipped ("test_fill_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_fill_0_perform (g);
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
test_fill_0_perform (guestfs_h *g)
{
  /* TestResult for fill (0) */
  const char *arg1763 = "/fill";
  int ret1;
  ret1 = guestfs_fill (g, 99, 10, arg1763);
  if (ret1 == -1)
    return -1;
  const char *arg1765 = "/fill";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, arg1765, &size);
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

static int test_part_get_parttype_0_skip (void);
static int test_part_get_parttype_0_perform (guestfs_h *);

static int
test_part_get_parttype_0 (guestfs_h *g)
{
  if (test_part_get_parttype_0_skip ()) {
    skipped ("test_part_get_parttype_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_get_parttype_0_perform (g);
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
test_part_get_parttype_0_perform (guestfs_h *g)
{
  /* TestResultString for part_get_parttype (0) */
  const char *arg1768 = "/dev/sda";
  const char *arg1769 = "gpt";
  int ret1767;
  ret1767 = guestfs_part_disk (g, arg1768, arg1769);
  if (ret1767 == -1)
    return -1;
  const char *arg1771 = "/dev/sda";
  CLEANUP_FREE char *ret;
  ret = guestfs_part_get_parttype (g, arg1771);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "gpt")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_part_get_parttype_0", "part_get_parttype", "gpt", ret);
    return -1;
  }
  return 0;
}

static int test_part_set_name_0_skip (void);
static int test_part_set_name_0_perform (guestfs_h *);

static int
test_part_set_name_0 (guestfs_h *g)
{
  if (test_part_set_name_0_skip ()) {
    skipped ("test_part_set_name_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_set_name_0_perform (g);
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
test_part_set_name_0_perform (guestfs_h *g)
{
  /* TestRun for part_set_name (0) */
  const char *arg1774 = "/dev/sda";
  const char *arg1775 = "gpt";
  int ret1773;
  ret1773 = guestfs_part_disk (g, arg1774, arg1775);
  if (ret1773 == -1)
    return -1;
  const char *arg1778 = "/dev/sda";
  const char *arg1780 = "thepartname";
  int ret1777;
  ret1777 = guestfs_part_set_name (g, arg1778, 1, arg1780);
  if (ret1777 == -1)
    return -1;
  return 0;
}

static int test_part_set_bootable_0_skip (void);
static int test_part_set_bootable_0_perform (guestfs_h *);

static int
test_part_set_bootable_0 (guestfs_h *g)
{
  if (test_part_set_bootable_0_skip ()) {
    skipped ("test_part_set_bootable_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_set_bootable_0_perform (g);
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
test_part_set_bootable_0_perform (guestfs_h *g)
{
  /* TestRun for part_set_bootable (0) */
  const char *arg1783 = "/dev/sda";
  const char *arg1784 = "mbr";
  int ret1782;
  ret1782 = guestfs_part_disk (g, arg1783, arg1784);
  if (ret1782 == -1)
    return -1;
  const char *arg1787 = "/dev/sda";
  int ret1786;
  ret1786 = guestfs_part_set_bootable (g, arg1787, 1, 1);
  if (ret1786 == -1)
    return -1;
  return 0;
}

static int test_part_disk_0_skip (void);
static int test_part_disk_0_perform (guestfs_h *);

static int
test_part_disk_0 (guestfs_h *g)
{
  if (test_part_disk_0_skip ()) {
    skipped ("test_part_disk_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_disk_0_perform (g);
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
test_part_disk_0_perform (guestfs_h *g)
{
  /* TestRun for part_disk (0) */
  const char *arg1792 = "/dev/sda";
  const char *arg1793 = "mbr";
  int ret1791;
  ret1791 = guestfs_part_disk (g, arg1792, arg1793);
  if (ret1791 == -1)
    return -1;
  return 0;
}

static int test_part_disk_1_skip (void);
static int test_part_disk_1_perform (guestfs_h *);

static int
test_part_disk_1 (guestfs_h *g)
{
  if (test_part_disk_1_skip ()) {
    skipped ("test_part_disk_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_disk_1_perform (g);
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
test_part_disk_1_perform (guestfs_h *g)
{
  /* TestRun for part_disk (1) */
  const char *arg1796 = "/dev/sda";
  const char *arg1797 = "gpt";
  int ret1795;
  ret1795 = guestfs_part_disk (g, arg1796, arg1797);
  if (ret1795 == -1)
    return -1;
  return 0;
}

static int test_part_add_0_skip (void);
static int test_part_add_0_perform (guestfs_h *);

static int
test_part_add_0 (guestfs_h *g)
{
  if (test_part_add_0_skip ()) {
    skipped ("test_part_add_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_add_0_perform (g);
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
test_part_add_0_perform (guestfs_h *g)
{
  /* TestRun for part_add (0) */
  const char *arg1800 = "/dev/sda";
  const char *arg1801 = "mbr";
  int ret1799;
  ret1799 = guestfs_part_init (g, arg1800, arg1801);
  if (ret1799 == -1)
    return -1;
  const char *arg1804 = "/dev/sda";
  const char *arg1805 = "primary";
  int ret1803;
  ret1803 = guestfs_part_add (g, arg1804, arg1805, 1, -1);
  if (ret1803 == -1)
    return -1;
  return 0;
}

static int test_part_add_1_skip (void);
static int test_part_add_1_perform (guestfs_h *);

static int
test_part_add_1 (guestfs_h *g)
{
  if (test_part_add_1_skip ()) {
    skipped ("test_part_add_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_add_1_perform (g);
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
test_part_add_1_perform (guestfs_h *g)
{
  /* TestRun for part_add (1) */
  const char *arg1810 = "/dev/sda";
  const char *arg1811 = "gpt";
  int ret1809;
  ret1809 = guestfs_part_init (g, arg1810, arg1811);
  if (ret1809 == -1)
    return -1;
  const char *arg1814 = "/dev/sda";
  const char *arg1815 = "primary";
  int ret1813;
  ret1813 = guestfs_part_add (g, arg1814, arg1815, 34, 127);
  if (ret1813 == -1)
    return -1;
  const char *arg1820 = "/dev/sda";
  const char *arg1821 = "primary";
  int ret1819;
  ret1819 = guestfs_part_add (g, arg1820, arg1821, 128, -34);
  if (ret1819 == -1)
    return -1;
  return 0;
}

static int test_part_add_2_skip (void);
static int test_part_add_2_perform (guestfs_h *);

static int
test_part_add_2 (guestfs_h *g)
{
  if (test_part_add_2_skip ()) {
    skipped ("test_part_add_2", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_add_2_perform (g);
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
test_part_add_2_perform (guestfs_h *g)
{
  /* TestRun for part_add (2) */
  const char *arg1826 = "/dev/sda";
  const char *arg1827 = "mbr";
  int ret1825;
  ret1825 = guestfs_part_init (g, arg1826, arg1827);
  if (ret1825 == -1)
    return -1;
  const char *arg1830 = "/dev/sda";
  const char *arg1831 = "primary";
  int ret1829;
  ret1829 = guestfs_part_add (g, arg1830, arg1831, 32, 127);
  if (ret1829 == -1)
    return -1;
  const char *arg1836 = "/dev/sda";
  const char *arg1837 = "primary";
  int ret1835;
  ret1835 = guestfs_part_add (g, arg1836, arg1837, 128, 255);
  if (ret1835 == -1)
    return -1;
  const char *arg1842 = "/dev/sda";
  const char *arg1843 = "primary";
  int ret1841;
  ret1841 = guestfs_part_add (g, arg1842, arg1843, 256, 511);
  if (ret1841 == -1)
    return -1;
  const char *arg1848 = "/dev/sda";
  const char *arg1849 = "primary";
  int ret1847;
  ret1847 = guestfs_part_add (g, arg1848, arg1849, 512, -1);
  if (ret1847 == -1)
    return -1;
  return 0;
}

static int test_part_init_0_skip (void);
static int test_part_init_0_perform (guestfs_h *);

static int
test_part_init_0 (guestfs_h *g)
{
  if (test_part_init_0_skip ()) {
    skipped ("test_part_init_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_part_init_0_perform (g);
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
test_part_init_0_perform (guestfs_h *g)
{
  /* TestRun for part_init (0) */
  const char *arg1854 = "/dev/sda";
  const char *arg1855 = "gpt";
  int ret1853;
  ret1853 = guestfs_part_init (g, arg1854, arg1855);
  if (ret1853 == -1)
    return -1;
  return 0;
}

static int test_pread_0_skip (void);
static int test_pread_0_perform (guestfs_h *);

static int
test_pread_0 (guestfs_h *g)
{
  if (test_pread_0_skip ()) {
    skipped ("test_pread_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_pread_0_perform (g);
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
test_pread_0_perform (guestfs_h *g)
{
  /* TestResult for pread (0) */
  const char *arg1857 = "/known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread (g, arg1857, 1, 3, &size);
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

static int test_pread_1_skip (void);
static int test_pread_1_perform (guestfs_h *);

static int
test_pread_1 (guestfs_h *g)
{
  if (test_pread_1_skip ()) {
    skipped ("test_pread_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_pread_1_perform (g);
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
test_pread_1_perform (guestfs_h *g)
{
  /* TestResult for pread (1) */
  const char *arg1861 = "/empty";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_pread (g, arg1861, 0, 100, &size);
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

static int test_mkdir_mode_0_skip (void);
static int test_mkdir_mode_0_perform (guestfs_h *);

static int
test_mkdir_mode_0 (guestfs_h *g)
{
  if (test_mkdir_mode_0_skip ()) {
    skipped ("test_mkdir_mode_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mkdir_mode_0_perform (g);
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
test_mkdir_mode_0_perform (guestfs_h *g)
{
  /* TestResult for mkdir_mode (0) */
  const char *arg1865 = "/mkdir_mode";
  int ret1;
  ret1 = guestfs_mkdir_mode (g, arg1865, 73);
  if (ret1 == -1)
    return -1;
  const char *arg1868 = "/mkdir_mode";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg1868);
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

static int test_utimens_0_skip (void);
static int test_utimens_0_perform (guestfs_h *);

static int
test_utimens_0 (guestfs_h *g)
{
  if (test_utimens_0_skip ()) {
    skipped ("test_utimens_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_utimens_0_perform (g);
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
test_utimens_0_perform (guestfs_h *g)
{
  /* TestResult for utimens (0) */
  const char *arg1870 = "/utimens-file";
  int ret2;
  ret2 = guestfs_touch (g, arg1870);
  if (ret2 == -1)
    return -1;
  const char *arg1872 = "/utimens-file";
  int ret1;
  ret1 = guestfs_utimens (g, arg1872, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *arg1878 = "/utimens-file";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg1878);
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

static int test_utimens_1_skip (void);
static int test_utimens_1_perform (guestfs_h *);

static int
test_utimens_1 (guestfs_h *g)
{
  if (test_utimens_1_skip ()) {
    skipped ("test_utimens_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_utimens_1_perform (g);
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
test_utimens_1_perform (guestfs_h *g)
{
  /* TestResult for utimens (1) */
  const char *arg1880 = "/utimens-dir";
  int ret2;
  ret2 = guestfs_mkdir (g, arg1880);
  if (ret2 == -1)
    return -1;
  const char *arg1882 = "/utimens-dir";
  int ret1;
  ret1 = guestfs_utimens (g, arg1882, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *arg1888 = "/utimens-dir";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg1888);
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

static int test_utimens_2_skip (void);
static int test_utimens_2_perform (guestfs_h *);

static int
test_utimens_2 (guestfs_h *g)
{
  if (test_utimens_2_skip ()) {
    skipped ("test_utimens_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_utimens_2_perform (g);
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
test_utimens_2_perform (guestfs_h *g)
{
  /* TestResult for utimens (2) */
  const char *arg1891 = "/utimens-fifo";
  int ret2;
  ret2 = guestfs_mkfifo (g, 420, arg1891);
  if (ret2 == -1)
    return -1;
  const char *arg1893 = "/utimens-fifo";
  int ret1;
  ret1 = guestfs_utimens (g, arg1893, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *arg1899 = "/utimens-fifo";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg1899);
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

static int test_utimens_3_skip (void);
static int test_utimens_3_perform (guestfs_h *);

static int
test_utimens_3 (guestfs_h *g)
{
  if (test_utimens_3_skip ()) {
    skipped ("test_utimens_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_utimens_3_perform (g);
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
test_utimens_3_perform (guestfs_h *g)
{
  /* TestResult for utimens (3) */
  const char *arg1901 = "/utimens-file";
  const char *arg1902 = "/utimens-link";
  int ret2;
  ret2 = guestfs_ln_sf (g, arg1901, arg1902);
  if (ret2 == -1)
    return -1;
  const char *arg1904 = "/utimens-link";
  int ret1;
  ret1 = guestfs_utimens (g, arg1904, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *arg1910 = "/utimens-link";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg1910);
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

static int test_utimens_4_skip (void);
static int test_utimens_4_perform (guestfs_h *);

static int
test_utimens_4 (guestfs_h *g)
{
  if (test_utimens_4_skip ()) {
    skipped ("test_utimens_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_utimens_4_perform (g);
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
test_utimens_4_perform (guestfs_h *g)
{
  /* TestResult for utimens (4) */
  const char *arg1915 = "/utimens-block";
  int ret2;
  ret2 = guestfs_mknod_b (g, 420, 8, 0, arg1915);
  if (ret2 == -1)
    return -1;
  const char *arg1917 = "/utimens-block";
  int ret1;
  ret1 = guestfs_utimens (g, arg1917, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *arg1923 = "/utimens-block";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg1923);
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

static int test_utimens_5_skip (void);
static int test_utimens_5_perform (guestfs_h *);

static int
test_utimens_5 (guestfs_h *g)
{
  if (test_utimens_5_skip ()) {
    skipped ("test_utimens_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_utimens_5_perform (g);
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
test_utimens_5_perform (guestfs_h *g)
{
  /* TestResult for utimens (5) */
  const char *arg1928 = "/utimens-char";
  int ret2;
  ret2 = guestfs_mknod_c (g, 420, 1, 3, arg1928);
  if (ret2 == -1)
    return -1;
  const char *arg1930 = "/utimens-char";
  int ret1;
  ret1 = guestfs_utimens (g, arg1930, 12345, 67890, 9876, 5432);
  if (ret1 == -1)
    return -1;
  const char *arg1936 = "/utimens-char";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg1936);
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

static int test_truncate_size_0_skip (void);
static int test_truncate_size_0_perform (guestfs_h *);

static int
test_truncate_size_0 (guestfs_h *g)
{
  if (test_truncate_size_0_skip ()) {
    skipped ("test_truncate_size_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_truncate_size_0_perform (g);
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
test_truncate_size_0_perform (guestfs_h *g)
{
  /* TestResult for truncate_size (0) */
  const char *arg1938 = "/truncate_size";
  int ret2;
  ret2 = guestfs_touch (g, arg1938);
  if (ret2 == -1)
    return -1;
  const char *arg1940 = "/truncate_size";
  int ret1;
  ret1 = guestfs_truncate_size (g, arg1940, 1000);
  if (ret1 == -1)
    return -1;
  const char *arg1943 = "/truncate_size";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg1943);
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

static int test_truncate_0_skip (void);
static int test_truncate_0_perform (guestfs_h *);

static int
test_truncate_0 (guestfs_h *g)
{
  if (test_truncate_0_skip ()) {
    skipped ("test_truncate_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_truncate_0_perform (g);
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
test_truncate_0_perform (guestfs_h *g)
{
  /* TestResult for truncate (0) */
  const char *arg1945 = "/truncate";
  const char *arg1946 = "some stuff so size is not zero";
  size_t arg1946_size = 30;
  int ret2;
  ret2 = guestfs_write (g, arg1945, arg1946, arg1946_size);
  if (ret2 == -1)
    return -1;
  const char *arg1948 = "/truncate";
  int ret1;
  ret1 = guestfs_truncate (g, arg1948);
  if (ret1 == -1)
    return -1;
  const char *arg1950 = "/truncate";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg1950);
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

static int test_vfs_type_0_skip (void);
static int test_vfs_type_0_perform (guestfs_h *);

static int
test_vfs_type_0 (guestfs_h *g)
{
  if (test_vfs_type_0_skip ()) {
    skipped ("test_vfs_type_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_vfs_type_0_perform (g);
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
test_vfs_type_0_perform (guestfs_h *g)
{
  /* TestResultString for vfs_type (0) */
  const char *arg1952 = "/dev/sdb1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_type (g, arg1952);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "ext2")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_vfs_type_0", "vfs_type", "ext2", ret);
    return -1;
  }
  return 0;
}

static int test_case_sensitive_path_0_skip (void);
static int test_case_sensitive_path_0_perform (guestfs_h *);

static int
test_case_sensitive_path_0 (guestfs_h *g)
{
  if (test_case_sensitive_path_0_skip ()) {
    skipped ("test_case_sensitive_path_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_case_sensitive_path_0_perform (g);
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
test_case_sensitive_path_0_perform (guestfs_h *g)
{
  /* TestResultString for case_sensitive_path (0) */
  const char *arg1954 = "/DIRECTORY";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, arg1954);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/directory")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_case_sensitive_path_0", "case_sensitive_path", "/directory", ret);
    return -1;
  }
  return 0;
}

static int test_case_sensitive_path_1_skip (void);
static int test_case_sensitive_path_1_perform (guestfs_h *);

static int
test_case_sensitive_path_1 (guestfs_h *g)
{
  if (test_case_sensitive_path_1_skip ()) {
    skipped ("test_case_sensitive_path_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_case_sensitive_path_1_perform (g);
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
test_case_sensitive_path_1_perform (guestfs_h *g)
{
  /* TestResultString for case_sensitive_path (1) */
  const char *arg1956 = "/DIRECTORY/";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, arg1956);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/directory")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_case_sensitive_path_1", "case_sensitive_path", "/directory", ret);
    return -1;
  }
  return 0;
}

static int test_case_sensitive_path_2_skip (void);
static int test_case_sensitive_path_2_perform (guestfs_h *);

static int
test_case_sensitive_path_2 (guestfs_h *g)
{
  if (test_case_sensitive_path_2_skip ()) {
    skipped ("test_case_sensitive_path_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_case_sensitive_path_2_perform (g);
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
test_case_sensitive_path_2_perform (guestfs_h *g)
{
  /* TestResultString for case_sensitive_path (2) */
  const char *arg1958 = "/Known-1";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, arg1958);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/known-1")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_case_sensitive_path_2", "case_sensitive_path", "/known-1", ret);
    return -1;
  }
  return 0;
}

static int test_case_sensitive_path_3_skip (void);
static int test_case_sensitive_path_3_perform (guestfs_h *);

static int
test_case_sensitive_path_3 (guestfs_h *g)
{
  if (test_case_sensitive_path_3_skip ()) {
    skipped ("test_case_sensitive_path_3", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_case_sensitive_path_3_perform (g);
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
test_case_sensitive_path_3_perform (guestfs_h *g)
{
  /* TestLastFail for case_sensitive_path (3) */
  const char *arg1961 = "/Known-1/";
  CLEANUP_FREE char *ret1960;
  guestfs_push_error_handler (g, NULL, NULL);
  ret1960 = guestfs_case_sensitive_path (g, arg1961);
  guestfs_pop_error_handler (g);
  if (ret1960 != NULL)
    return -1;
  return 0;
}

static int test_case_sensitive_path_4_skip (void);
static int test_case_sensitive_path_4_perform (guestfs_h *);

static int
test_case_sensitive_path_4 (guestfs_h *g)
{
  if (test_case_sensitive_path_4_skip ()) {
    skipped ("test_case_sensitive_path_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_case_sensitive_path_4_perform (g);
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
test_case_sensitive_path_4_perform (guestfs_h *g)
{
  /* TestResultString for case_sensitive_path (4) */
  const char *arg1964 = "/case_sensitive_path";
  int ret1963;
  ret1963 = guestfs_mkdir (g, arg1964);
  if (ret1963 == -1)
    return -1;
  const char *arg1967 = "/case_sensitive_path/bbb";
  int ret1966;
  ret1966 = guestfs_mkdir (g, arg1967);
  if (ret1966 == -1)
    return -1;
  const char *arg1970 = "/case_sensitive_path/bbb/c";
  int ret1969;
  ret1969 = guestfs_touch (g, arg1970);
  if (ret1969 == -1)
    return -1;
  const char *arg1972 = "/CASE_SENSITIVE_path/bbB/C";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, arg1972);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/case_sensitive_path/bbb/c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_case_sensitive_path_4", "case_sensitive_path", "/case_sensitive_path/bbb/c", ret);
    return -1;
  }
  return 0;
}

static int test_case_sensitive_path_5_skip (void);
static int test_case_sensitive_path_5_perform (guestfs_h *);

static int
test_case_sensitive_path_5 (guestfs_h *g)
{
  if (test_case_sensitive_path_5_skip ()) {
    skipped ("test_case_sensitive_path_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_case_sensitive_path_5_perform (g);
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
test_case_sensitive_path_5_perform (guestfs_h *g)
{
  /* TestResultString for case_sensitive_path (5) */
  const char *arg1975 = "/case_sensitive_path2";
  int ret1974;
  ret1974 = guestfs_mkdir (g, arg1975);
  if (ret1974 == -1)
    return -1;
  const char *arg1978 = "/case_sensitive_path2/bbb";
  int ret1977;
  ret1977 = guestfs_mkdir (g, arg1978);
  if (ret1977 == -1)
    return -1;
  const char *arg1981 = "/case_sensitive_path2/bbb/c";
  int ret1980;
  ret1980 = guestfs_touch (g, arg1981);
  if (ret1980 == -1)
    return -1;
  const char *arg1983 = "/case_sensitive_PATH2////bbB/C";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, arg1983);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/case_sensitive_path2/bbb/c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_case_sensitive_path_5", "case_sensitive_path", "/case_sensitive_path2/bbb/c", ret);
    return -1;
  }
  return 0;
}

static int test_case_sensitive_path_6_skip (void);
static int test_case_sensitive_path_6_perform (guestfs_h *);

static int
test_case_sensitive_path_6 (guestfs_h *g)
{
  if (test_case_sensitive_path_6_skip ()) {
    skipped ("test_case_sensitive_path_6", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_case_sensitive_path_6_perform (g);
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
test_case_sensitive_path_6_perform (guestfs_h *g)
{
  /* TestLastFail for case_sensitive_path (6) */
  const char *arg1986 = "/case_sensitive_path3";
  int ret1985;
  ret1985 = guestfs_mkdir (g, arg1986);
  if (ret1985 == -1)
    return -1;
  const char *arg1989 = "/case_sensitive_path3/bbb";
  int ret1988;
  ret1988 = guestfs_mkdir (g, arg1989);
  if (ret1988 == -1)
    return -1;
  const char *arg1992 = "/case_sensitive_path3/bbb/c";
  int ret1991;
  ret1991 = guestfs_touch (g, arg1992);
  if (ret1991 == -1)
    return -1;
  const char *arg1995 = "/case_SENSITIVE_path3/bbb/../bbb/C";
  CLEANUP_FREE char *ret1994;
  guestfs_push_error_handler (g, NULL, NULL);
  ret1994 = guestfs_case_sensitive_path (g, arg1995);
  guestfs_pop_error_handler (g);
  if (ret1994 != NULL)
    return -1;
  return 0;
}

static int test_case_sensitive_path_7_skip (void);
static int test_case_sensitive_path_7_perform (guestfs_h *);

static int
test_case_sensitive_path_7 (guestfs_h *g)
{
  if (test_case_sensitive_path_7_skip ()) {
    skipped ("test_case_sensitive_path_7", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_case_sensitive_path_7_perform (g);
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
test_case_sensitive_path_7_perform (guestfs_h *g)
{
  /* TestResultString for case_sensitive_path (7) */
  const char *arg1998 = "/case_sensitive_path4";
  int ret1997;
  ret1997 = guestfs_mkdir (g, arg1998);
  if (ret1997 == -1)
    return -1;
  const char *arg2000 = "/case_SENSITIVE_path4/new_file";
  CLEANUP_FREE char *ret;
  ret = guestfs_case_sensitive_path (g, arg2000);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/case_sensitive_path4/new_file")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_case_sensitive_path_7", "case_sensitive_path", "/case_sensitive_path4/new_file", ret);
    return -1;
  }
  return 0;
}

static int test_echo_daemon_0_skip (void);
static int test_echo_daemon_0_perform (guestfs_h *);

static int
test_echo_daemon_0 (guestfs_h *g)
{
  if (test_echo_daemon_0_skip ()) {
    skipped ("test_echo_daemon_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_echo_daemon_0_perform (g);
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
test_echo_daemon_0_perform (guestfs_h *g)
{
  /* TestResultString for echo_daemon (0) */
  const char *arg2002_0 = "This";
  const char *arg2002_1 = "is";
  const char *arg2002_2 = "a";
  const char *arg2002_3 = "test";
  const char *const arg2002[] = {
    arg2002_0,
    arg2002_1,
    arg2002_2,
    arg2002_3,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_echo_daemon (g, (char **) arg2002);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "This is a test")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_echo_daemon_0", "echo_daemon", "This is a test", ret);
    return -1;
  }
  return 0;
}

static int test_echo_daemon_1_skip (void);
static int test_echo_daemon_1_perform (guestfs_h *);

static int
test_echo_daemon_1 (guestfs_h *g)
{
  if (test_echo_daemon_1_skip ()) {
    skipped ("test_echo_daemon_1", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_echo_daemon_1_perform (g);
}

static int
test_echo_daemon_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "echo_daemon") == NULL;
  str = getenv ("SKIP_TEST_ECHO_DAEMON_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_ECHO_DAEMON");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_echo_daemon_1_perform (guestfs_h *g)
{
  /* TestResultString for echo_daemon (1) */
  const char *const arg2004[1] = { NULL };
  CLEANUP_FREE char *ret;
  ret = guestfs_echo_daemon (g, (char **) arg2004);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_echo_daemon_1", "echo_daemon", "", ret);
    return -1;
  }
  return 0;
}

static int test_modprobe_0_skip (void);
static int test_modprobe_0_perform (guestfs_h *);

static int
test_modprobe_0 (guestfs_h *g)
{
  if (test_modprobe_0_skip ()) {
    skipped ("test_modprobe_0", "environment variable set");
    return 0;
  }

  const char *features2006[] = { "linuxmodules", NULL };
  if (!guestfs_feature_available (g, (char **) features2006)) {
    skipped ("test_modprobe_0", "group %s not available in daemon",
             features2006[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_modprobe_0_perform (g);
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
test_modprobe_0_perform (guestfs_h *g)
{
  /* TestRun for modprobe (0) */
  const char *arg2008 = "fat";
  int ret2007;
  ret2007 = guestfs_modprobe (g, arg2008);
  if (ret2007 == -1)
    return -1;
  return 0;
}

static int test_mke2journal_U_0_skip (void);
static int test_mke2journal_U_0_perform (guestfs_h *);

static int
test_mke2journal_U_0 (guestfs_h *g)
{
  if (test_mke2journal_U_0_skip ()) {
    skipped ("test_mke2journal_U_0", "environment variable set");
    return 0;
  }

  const char *features2010[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) features2010)) {
    skipped ("test_mke2journal_U_0", "group %s not available in daemon",
             features2010[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mke2journal_U_0_perform (g);
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
test_mke2journal_U_0_perform (guestfs_h *g)
{
  /* TestResultString for mke2journal_U (0) */
  const char *arg2012 = "/dev/sda";
  const char *arg2013 = "mbr";
  int ret2011;
  ret2011 = guestfs_part_init (g, arg2012, arg2013);
  if (ret2011 == -1)
    return -1;
  const char *arg2016 = "/dev/sda";
  const char *arg2017 = "p";
  int ret2015;
  ret2015 = guestfs_part_add (g, arg2016, arg2017, 64, 204799);
  if (ret2015 == -1)
    return -1;
  const char *arg2022 = "/dev/sda";
  const char *arg2023 = "p";
  int ret2021;
  ret2021 = guestfs_part_add (g, arg2022, arg2023, 204800, -64);
  if (ret2021 == -1)
    return -1;
  const char *arg2029 = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  const char *arg2030 = "/dev/sda1";
  int ret2027;
  ret2027 = guestfs_mke2journal_U (g, 4096, arg2029, arg2030);
  if (ret2027 == -1)
    return -1;
  const char *arg2033 = "ext2";
  const char *arg2035 = "/dev/sda2";
  const char *arg2036 = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  int ret2032;
  ret2032 = guestfs_mke2fs_JU (g, arg2033, 4096, arg2035, arg2036);
  if (ret2032 == -1)
    return -1;
  const char *arg2039 = "/dev/sda2";
  const char *arg2040 = "/";
  int ret2038;
  ret2038 = guestfs_mount (g, arg2039, arg2040);
  if (ret2038 == -1)
    return -1;
  const char *arg2043 = "/new";
  const char *arg2044 = "new file contents";
  size_t arg2044_size = 17;
  int ret2042;
  ret2042 = guestfs_write (g, arg2043, arg2044, arg2044_size);
  if (ret2042 == -1)
    return -1;
  const char *arg2046 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg2046);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mke2journal_U_0", "cat", "new file contents", ret);
    return -1;
  }
  return 0;
}

static int test_mke2journal_L_0_skip (void);
static int test_mke2journal_L_0_perform (guestfs_h *);

static int
test_mke2journal_L_0 (guestfs_h *g)
{
  if (test_mke2journal_L_0_skip ()) {
    skipped ("test_mke2journal_L_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mke2journal_L_0_perform (g);
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
test_mke2journal_L_0_perform (guestfs_h *g)
{
  /* TestResultString for mke2journal_L (0) */
  const char *arg2049 = "/dev/sda";
  const char *arg2050 = "mbr";
  int ret2048;
  ret2048 = guestfs_part_init (g, arg2049, arg2050);
  if (ret2048 == -1)
    return -1;
  const char *arg2053 = "/dev/sda";
  const char *arg2054 = "p";
  int ret2052;
  ret2052 = guestfs_part_add (g, arg2053, arg2054, 64, 204799);
  if (ret2052 == -1)
    return -1;
  const char *arg2059 = "/dev/sda";
  const char *arg2060 = "p";
  int ret2058;
  ret2058 = guestfs_part_add (g, arg2059, arg2060, 204800, -64);
  if (ret2058 == -1)
    return -1;
  const char *arg2066 = "JOURNAL";
  const char *arg2067 = "/dev/sda1";
  int ret2064;
  ret2064 = guestfs_mke2journal_L (g, 4096, arg2066, arg2067);
  if (ret2064 == -1)
    return -1;
  const char *arg2070 = "ext2";
  const char *arg2072 = "/dev/sda2";
  const char *arg2073 = "JOURNAL";
  int ret2069;
  ret2069 = guestfs_mke2fs_JL (g, arg2070, 4096, arg2072, arg2073);
  if (ret2069 == -1)
    return -1;
  const char *arg2076 = "/dev/sda2";
  const char *arg2077 = "/";
  int ret2075;
  ret2075 = guestfs_mount (g, arg2076, arg2077);
  if (ret2075 == -1)
    return -1;
  const char *arg2080 = "/new";
  const char *arg2081 = "new file contents";
  size_t arg2081_size = 17;
  int ret2079;
  ret2079 = guestfs_write (g, arg2080, arg2081, arg2081_size);
  if (ret2079 == -1)
    return -1;
  const char *arg2083 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg2083);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mke2journal_L_0", "cat", "new file contents", ret);
    return -1;
  }
  return 0;
}

static int test_mke2journal_0_skip (void);
static int test_mke2journal_0_perform (guestfs_h *);

static int
test_mke2journal_0 (guestfs_h *g)
{
  if (test_mke2journal_0_skip ()) {
    skipped ("test_mke2journal_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mke2journal_0_perform (g);
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
test_mke2journal_0_perform (guestfs_h *g)
{
  /* TestResultString for mke2journal (0) */
  const char *arg2086 = "/dev/sda";
  const char *arg2087 = "mbr";
  int ret2085;
  ret2085 = guestfs_part_init (g, arg2086, arg2087);
  if (ret2085 == -1)
    return -1;
  const char *arg2090 = "/dev/sda";
  const char *arg2091 = "p";
  int ret2089;
  ret2089 = guestfs_part_add (g, arg2090, arg2091, 64, 204799);
  if (ret2089 == -1)
    return -1;
  const char *arg2096 = "/dev/sda";
  const char *arg2097 = "p";
  int ret2095;
  ret2095 = guestfs_part_add (g, arg2096, arg2097, 204800, -64);
  if (ret2095 == -1)
    return -1;
  const char *arg2103 = "/dev/sda1";
  int ret2101;
  ret2101 = guestfs_mke2journal (g, 4096, arg2103);
  if (ret2101 == -1)
    return -1;
  const char *arg2106 = "ext2";
  const char *arg2108 = "/dev/sda2";
  const char *arg2109 = "/dev/sda1";
  int ret2105;
  ret2105 = guestfs_mke2fs_J (g, arg2106, 4096, arg2108, arg2109);
  if (ret2105 == -1)
    return -1;
  const char *arg2112 = "/dev/sda2";
  const char *arg2113 = "/";
  int ret2111;
  ret2111 = guestfs_mount (g, arg2112, arg2113);
  if (ret2111 == -1)
    return -1;
  const char *arg2116 = "/new";
  const char *arg2117 = "new file contents";
  size_t arg2117_size = 17;
  int ret2115;
  ret2115 = guestfs_write (g, arg2116, arg2117, arg2117_size);
  if (ret2115 == -1)
    return -1;
  const char *arg2119 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg2119);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mke2journal_0", "cat", "new file contents", ret);
    return -1;
  }
  return 0;
}

static int test_mkfs_b_0_skip (void);
static int test_mkfs_b_0_perform (guestfs_h *);

static int
test_mkfs_b_0 (guestfs_h *g)
{
  if (test_mkfs_b_0_skip ()) {
    skipped ("test_mkfs_b_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mkfs_b_0_perform (g);
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
test_mkfs_b_0_perform (guestfs_h *g)
{
  /* TestResultString for mkfs_b (0) */
  const char *arg2122 = "/dev/sda";
  const char *arg2123 = "mbr";
  int ret2121;
  ret2121 = guestfs_part_disk (g, arg2122, arg2123);
  if (ret2121 == -1)
    return -1;
  const char *arg2126 = "ext2";
  const char *arg2128 = "/dev/sda1";
  int ret2125;
  ret2125 = guestfs_mkfs_b (g, arg2126, 4096, arg2128);
  if (ret2125 == -1)
    return -1;
  const char *arg2131 = "/dev/sda1";
  const char *arg2132 = "/";
  int ret2130;
  ret2130 = guestfs_mount (g, arg2131, arg2132);
  if (ret2130 == -1)
    return -1;
  const char *arg2135 = "/new";
  const char *arg2136 = "new file contents";
  size_t arg2136_size = 17;
  int ret2134;
  ret2134 = guestfs_write (g, arg2135, arg2136, arg2136_size);
  if (ret2134 == -1)
    return -1;
  const char *arg2138 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg2138);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mkfs_b_0", "cat", "new file contents", ret);
    return -1;
  }
  return 0;
}

static int test_mkfs_b_1_skip (void);
static int test_mkfs_b_1_perform (guestfs_h *);

static int
test_mkfs_b_1 (guestfs_h *g)
{
  if (test_mkfs_b_1_skip ()) {
    skipped ("test_mkfs_b_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mkfs_b_1_perform (g);
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
test_mkfs_b_1_perform (guestfs_h *g)
{
  /* TestRun for mkfs_b (1) */
  const char *arg2141 = "/dev/sda";
  const char *arg2142 = "mbr";
  int ret2140;
  ret2140 = guestfs_part_disk (g, arg2141, arg2142);
  if (ret2140 == -1)
    return -1;
  const char *arg2145 = "vfat";
  const char *arg2147 = "/dev/sda1";
  int ret2144;
  ret2144 = guestfs_mkfs_b (g, arg2145, 32768, arg2147);
  if (ret2144 == -1)
    return -1;
  return 0;
}

static int test_mkfs_b_2_skip (void);
static int test_mkfs_b_2_perform (guestfs_h *);

static int
test_mkfs_b_2 (guestfs_h *g)
{
  if (test_mkfs_b_2_skip ()) {
    skipped ("test_mkfs_b_2", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mkfs_b_2_perform (g);
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
test_mkfs_b_2_perform (guestfs_h *g)
{
  /* TestLastFail for mkfs_b (2) */
  const char *arg2150 = "/dev/sda";
  const char *arg2151 = "mbr";
  int ret2149;
  ret2149 = guestfs_part_disk (g, arg2150, arg2151);
  if (ret2149 == -1)
    return -1;
  const char *arg2154 = "vfat";
  const char *arg2156 = "/dev/sda1";
  int ret2153;
  guestfs_push_error_handler (g, NULL, NULL);
  ret2153 = guestfs_mkfs_b (g, arg2154, 32769, arg2156);
  guestfs_pop_error_handler (g);
  if (ret2153 != -1)
    return -1;
  return 0;
}

static int test_mkfs_b_3_skip (void);
static int test_mkfs_b_3_perform (guestfs_h *);

static int
test_mkfs_b_3 (guestfs_h *g)
{
  if (test_mkfs_b_3_skip ()) {
    skipped ("test_mkfs_b_3", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mkfs_b_3_perform (g);
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
test_mkfs_b_3_perform (guestfs_h *g)
{
  /* TestLastFail for mkfs_b (3) */
  const char *arg2159 = "/dev/sda";
  const char *arg2160 = "mbr";
  int ret2158;
  ret2158 = guestfs_part_disk (g, arg2159, arg2160);
  if (ret2158 == -1)
    return -1;
  const char *arg2163 = "vfat";
  const char *arg2165 = "/dev/sda1";
  int ret2162;
  guestfs_push_error_handler (g, NULL, NULL);
  ret2162 = guestfs_mkfs_b (g, arg2163, 33280, arg2165);
  guestfs_pop_error_handler (g);
  if (ret2162 != -1)
    return -1;
  return 0;
}

static int test_mkfs_b_4_skip (void);
static int test_mkfs_b_4_perform (guestfs_h *);

static int
test_mkfs_b_4 (guestfs_h *g)
{
  if (test_mkfs_b_4_skip ()) {
    skipped ("test_mkfs_b_4", "environment variable set");
    return 0;
  }

  const char *features2167[] = { "ntfsprogs", NULL };
  if (!guestfs_feature_available (g, (char **) features2167)) {
    skipped ("test_mkfs_b_4", "group %s not available in daemon",
             features2167[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mkfs_b_4_perform (g);
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
test_mkfs_b_4_perform (guestfs_h *g)
{
  /* TestRun for mkfs_b (4) */
  const char *arg2169 = "/dev/sda";
  const char *arg2170 = "mbr";
  int ret2168;
  ret2168 = guestfs_part_disk (g, arg2169, arg2170);
  if (ret2168 == -1)
    return -1;
  const char *arg2173 = "ntfs";
  const char *arg2175 = "/dev/sda1";
  int ret2172;
  ret2172 = guestfs_mkfs_b (g, arg2173, 32768, arg2175);
  if (ret2172 == -1)
    return -1;
  return 0;
}

static int test_inotify_add_watch_0_skip (void);
static int test_inotify_add_watch_0_perform (guestfs_h *);

static int
test_inotify_add_watch_0 (guestfs_h *g)
{
  if (test_inotify_add_watch_0_skip ()) {
    skipped ("test_inotify_add_watch_0", "environment variable set");
    return 0;
  }

  const char *features2177[] = { "inotify", NULL };
  if (!guestfs_feature_available (g, (char **) features2177)) {
    skipped ("test_inotify_add_watch_0", "group %s not available in daemon",
             features2177[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_inotify_add_watch_0_perform (g);
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
test_inotify_add_watch_0_perform (guestfs_h *g)
{
  /* TestResult for inotify_add_watch (0) */
  const char *arg2178 = "/inotify_add_watch";
  int ret5;
  ret5 = guestfs_mkdir (g, arg2178);
  if (ret5 == -1)
    return -1;
  int ret4;
  ret4 = guestfs_inotify_init (g, 0);
  if (ret4 == -1)
    return -1;
  const char *arg2182 = "/inotify_add_watch";
  int64_t ret3;
  ret3 = guestfs_inotify_add_watch (g, arg2182, 1073741823);
  if (ret3 == -1)
    return -1;
  const char *arg2185 = "/inotify_add_watch/a";
  int ret2;
  ret2 = guestfs_touch (g, arg2185);
  if (ret2 == -1)
    return -1;
  const char *arg2187 = "/inotify_add_watch/b";
  int ret1;
  ret1 = guestfs_touch (g, arg2187);
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

static int test_inotify_init_0_skip (void);
static int test_inotify_init_0_perform (guestfs_h *);

static int
test_inotify_init_0 (guestfs_h *g)
{
  if (test_inotify_init_0_skip ()) {
    skipped ("test_inotify_init_0", "environment variable set");
    return 0;
  }

  const char *features2190[] = { "inotify", NULL };
  if (!guestfs_feature_available (g, (char **) features2190)) {
    skipped ("test_inotify_init_0", "group %s not available in daemon",
             features2190[0]);
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_inotify_init_0_perform (g);
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
test_inotify_init_0_perform (guestfs_h *g)
{
  /* TestRun for inotify_init (0) */
  int ret2191;
  ret2191 = guestfs_inotify_init (g, 0);
  if (ret2191 == -1)
    return -1;
  return 0;
}

static int test_mkswap_file_0_skip (void);
static int test_mkswap_file_0_perform (guestfs_h *);

static int
test_mkswap_file_0 (guestfs_h *g)
{
  if (test_mkswap_file_0_skip ()) {
    skipped ("test_mkswap_file_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mkswap_file_0_perform (g);
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
test_mkswap_file_0_perform (guestfs_h *g)
{
  /* TestRun for mkswap_file (0) */
  const char *arg2195 = "/mkswap_file";
  int ret2194;
  ret2194 = guestfs_fallocate (g, arg2195, 8388608);
  if (ret2194 == -1)
    return -1;
  const char *arg2199 = "/mkswap_file";
  int ret2198;
  ret2198 = guestfs_mkswap_file (g, arg2199);
  if (ret2198 == -1)
    return -1;
  const char *arg2202 = "/mkswap_file";
  int ret2201;
  ret2201 = guestfs_rm (g, arg2202);
  if (ret2201 == -1)
    return -1;
  return 0;
}

static int test_swapon_uuid_0_skip (void);
static int test_swapon_uuid_0_perform (guestfs_h *);

static int
test_swapon_uuid_0 (guestfs_h *g)
{
  if (test_swapon_uuid_0_skip ()) {
    skipped ("test_swapon_uuid_0", "environment variable set");
    return 0;
  }

  const char *features2204[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) features2204)) {
    skipped ("test_swapon_uuid_0", "group %s not available in daemon",
             features2204[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_swapon_uuid_0_perform (g);
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
test_swapon_uuid_0_perform (guestfs_h *g)
{
  /* TestRun for swapon_uuid (0) */
  const char *arg2206 = "/dev/sdc";
  struct guestfs_mkswap_opts_argv optargs2207;
  optargs2207.uuid = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  optargs2207.bitmask = UINT64_C(0x2);
  int ret2205;
  ret2205 = guestfs_mkswap_opts_argv (g, arg2206, &optargs2207);
  if (ret2205 == -1)
    return -1;
  const char *arg2209 = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  int ret2208;
  ret2208 = guestfs_swapon_uuid (g, arg2209);
  if (ret2208 == -1)
    return -1;
  const char *arg2212 = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  int ret2211;
  ret2211 = guestfs_swapoff_uuid (g, arg2212);
  if (ret2211 == -1)
    return -1;
  return 0;
}

static int test_swapon_label_0_skip (void);
static int test_swapon_label_0_perform (guestfs_h *);

static int
test_swapon_label_0 (guestfs_h *g)
{
  if (test_swapon_label_0_skip ()) {
    skipped ("test_swapon_label_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_swapon_label_0_perform (g);
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
test_swapon_label_0_perform (guestfs_h *g)
{
  /* TestRun for swapon_label (0) */
  const char *arg2215 = "/dev/sda";
  const char *arg2216 = "mbr";
  int ret2214;
  ret2214 = guestfs_part_disk (g, arg2215, arg2216);
  if (ret2214 == -1)
    return -1;
  const char *arg2219 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv optargs2220;
  optargs2220.label = "swapit";
  optargs2220.bitmask = UINT64_C(0x1);
  int ret2218;
  ret2218 = guestfs_mkswap_opts_argv (g, arg2219, &optargs2220);
  if (ret2218 == -1)
    return -1;
  const char *arg2222 = "swapit";
  int ret2221;
  ret2221 = guestfs_swapon_label (g, arg2222);
  if (ret2221 == -1)
    return -1;
  const char *arg2225 = "swapit";
  int ret2224;
  ret2224 = guestfs_swapoff_label (g, arg2225);
  if (ret2224 == -1)
    return -1;
  const char *arg2228 = "/dev/sda";
  int ret2227;
  ret2227 = guestfs_zero (g, arg2228);
  if (ret2227 == -1)
    return -1;
  const char *arg2231 = "/dev/sda";
  int ret2230;
  ret2230 = guestfs_blockdev_rereadpt (g, arg2231);
  if (ret2230 == -1)
    return -1;
  return 0;
}

static int test_swapon_file_0_skip (void);
static int test_swapon_file_0_perform (guestfs_h *);

static int
test_swapon_file_0 (guestfs_h *g)
{
  if (test_swapon_file_0_skip ()) {
    skipped ("test_swapon_file_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_swapon_file_0_perform (g);
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
test_swapon_file_0_perform (guestfs_h *g)
{
  /* TestRun for swapon_file (0) */
  const char *arg2234 = "/swapon_file";
  int ret2233;
  ret2233 = guestfs_fallocate (g, arg2234, 8388608);
  if (ret2233 == -1)
    return -1;
  const char *arg2238 = "/swapon_file";
  int ret2237;
  ret2237 = guestfs_mkswap_file (g, arg2238);
  if (ret2237 == -1)
    return -1;
  const char *arg2241 = "/swapon_file";
  int ret2240;
  ret2240 = guestfs_swapon_file (g, arg2241);
  if (ret2240 == -1)
    return -1;
  const char *arg2244 = "/swapon_file";
  int ret2243;
  ret2243 = guestfs_swapoff_file (g, arg2244);
  if (ret2243 == -1)
    return -1;
  const char *arg2247 = "/swapon_file";
  int ret2246;
  ret2246 = guestfs_rm (g, arg2247);
  if (ret2246 == -1)
    return -1;
  return 0;
}

static int test_swapon_device_0_skip (void);
static int test_swapon_device_0_perform (guestfs_h *);

static int
test_swapon_device_0 (guestfs_h *g)
{
  if (test_swapon_device_0_skip ()) {
    skipped ("test_swapon_device_0", "environment variable set");
    return 0;
  }

  if (init_partition (g) == -1)
    return -1;

  return test_swapon_device_0_perform (g);
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
test_swapon_device_0_perform (guestfs_h *g)
{
  /* TestRun for swapon_device (0) */
  const char *arg2250 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv optargs2251;
  optargs2251.bitmask = UINT64_C(0x0);
  int ret2249;
  ret2249 = guestfs_mkswap_opts_argv (g, arg2250, &optargs2251);
  if (ret2249 == -1)
    return -1;
  const char *arg2253 = "/dev/sda1";
  int ret2252;
  ret2252 = guestfs_swapon_device (g, arg2253);
  if (ret2252 == -1)
    return -1;
  const char *arg2256 = "/dev/sda1";
  int ret2255;
  ret2255 = guestfs_swapoff_device (g, arg2256);
  if (ret2255 == -1)
    return -1;
  return 0;
}

static int test_fallocate_0_skip (void);
static int test_fallocate_0_perform (guestfs_h *);

static int
test_fallocate_0 (guestfs_h *g)
{
  if (test_fallocate_0_skip ()) {
    skipped ("test_fallocate_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_fallocate_0_perform (g);
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
test_fallocate_0_perform (guestfs_h *g)
{
  /* TestResult for fallocate (0) */
  const char *arg2258 = "/fallocate";
  int ret1;
  ret1 = guestfs_fallocate (g, arg2258, 1000000);
  if (ret1 == -1)
    return -1;
  const char *arg2261 = "/fallocate";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg2261);
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

static int test_ln_sf_0_skip (void);
static int test_ln_sf_0_perform (guestfs_h *);

static int
test_ln_sf_0 (guestfs_h *g)
{
  if (test_ln_sf_0_skip ()) {
    skipped ("test_ln_sf_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_ln_sf_0_perform (g);
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
test_ln_sf_0_perform (guestfs_h *g)
{
  /* TestResultString for ln_sf (0) */
  const char *arg2264 = "/ln_sf/b";
  int ret2263;
  ret2263 = guestfs_mkdir_p (g, arg2264);
  if (ret2263 == -1)
    return -1;
  const char *arg2267 = "/ln_sf/b/c";
  int ret2266;
  ret2266 = guestfs_touch (g, arg2267);
  if (ret2266 == -1)
    return -1;
  const char *arg2270 = "../d";
  const char *arg2271 = "/ln_sf/b/c";
  int ret2269;
  ret2269 = guestfs_ln_sf (g, arg2270, arg2271);
  if (ret2269 == -1)
    return -1;
  const char *arg2273 = "/ln_sf/b/c";
  CLEANUP_FREE char *ret;
  ret = guestfs_readlink (g, arg2273);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "../d")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_ln_sf_0", "readlink", "../d", ret);
    return -1;
  }
  return 0;
}

static int test_ln_s_0_skip (void);
static int test_ln_s_0_perform (guestfs_h *);

static int
test_ln_s_0 (guestfs_h *g)
{
  if (test_ln_s_0_skip ()) {
    skipped ("test_ln_s_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_ln_s_0_perform (g);
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
test_ln_s_0_perform (guestfs_h *g)
{
  /* TestResult for ln_s (0) */
  const char *arg2275 = "/ln_s";
  int ret3;
  ret3 = guestfs_mkdir (g, arg2275);
  if (ret3 == -1)
    return -1;
  const char *arg2277 = "/ln_s/a";
  int ret2;
  ret2 = guestfs_touch (g, arg2277);
  if (ret2 == -1)
    return -1;
  const char *arg2279 = "a";
  const char *arg2280 = "/ln_s/b";
  int ret1;
  ret1 = guestfs_ln_s (g, arg2279, arg2280);
  if (ret1 == -1)
    return -1;
  const char *arg2282 = "/ln_s/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_lstat (g, arg2282);
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

static int test_ln_f_0_skip (void);
static int test_ln_f_0_perform (guestfs_h *);

static int
test_ln_f_0 (guestfs_h *g)
{
  if (test_ln_f_0_skip ()) {
    skipped ("test_ln_f_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_ln_f_0_perform (g);
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
test_ln_f_0_perform (guestfs_h *g)
{
  /* TestResult for ln_f (0) */
  const char *arg2284 = "/ln_f";
  int ret4;
  ret4 = guestfs_mkdir (g, arg2284);
  if (ret4 == -1)
    return -1;
  const char *arg2286 = "/ln_f/a";
  int ret3;
  ret3 = guestfs_touch (g, arg2286);
  if (ret3 == -1)
    return -1;
  const char *arg2288 = "/ln_f/b";
  int ret2;
  ret2 = guestfs_touch (g, arg2288);
  if (ret2 == -1)
    return -1;
  const char *arg2290 = "/ln_f/a";
  const char *arg2291 = "/ln_f/b";
  int ret1;
  ret1 = guestfs_ln_f (g, arg2290, arg2291);
  if (ret1 == -1)
    return -1;
  const char *arg2293 = "/ln_f/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg2293);
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

static int test_ln_0_skip (void);
static int test_ln_0_perform (guestfs_h *);

static int
test_ln_0 (guestfs_h *g)
{
  if (test_ln_0_skip ()) {
    skipped ("test_ln_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_ln_0_perform (g);
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
test_ln_0_perform (guestfs_h *g)
{
  /* TestResult for ln (0) */
  const char *arg2295 = "/ln";
  int ret3;
  ret3 = guestfs_mkdir (g, arg2295);
  if (ret3 == -1)
    return -1;
  const char *arg2297 = "/ln/a";
  int ret2;
  ret2 = guestfs_touch (g, arg2297);
  if (ret2 == -1)
    return -1;
  const char *arg2299 = "/ln/a";
  const char *arg2300 = "/ln/b";
  int ret1;
  ret1 = guestfs_ln (g, arg2299, arg2300);
  if (ret1 == -1)
    return -1;
  const char *arg2302 = "/ln/b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg2302);
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

static int test_realpath_0_skip (void);
static int test_realpath_0_perform (guestfs_h *);

static int
test_realpath_0 (guestfs_h *g)
{
  if (test_realpath_0_skip ()) {
    skipped ("test_realpath_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_realpath_0_perform (g);
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
test_realpath_0_perform (guestfs_h *g)
{
  /* TestResultString for realpath (0) */
  const char *arg2304 = "/../directory";
  CLEANUP_FREE char *ret;
  ret = guestfs_realpath (g, arg2304);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/directory")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_realpath_0", "realpath", "/directory", ret);
    return -1;
  }
  return 0;
}

static int test_zfgrepi_0_skip (void);
static int test_zfgrepi_0_perform (guestfs_h *);

static int
test_zfgrepi_0 (guestfs_h *g)
{
  if (test_zfgrepi_0_skip ()) {
    skipped ("test_zfgrepi_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_zfgrepi_0_perform (g);
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
test_zfgrepi_0_perform (guestfs_h *g)
{
  /* TestResult for zfgrepi (0) */
  const char *arg2306 = "abc";
  const char *arg2307 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zfgrepi (g, arg2306, arg2307);
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

static int test_zegrepi_0_skip (void);
static int test_zegrepi_0_perform (guestfs_h *);

static int
test_zegrepi_0 (guestfs_h *g)
{
  if (test_zegrepi_0_skip ()) {
    skipped ("test_zegrepi_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_zegrepi_0_perform (g);
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
test_zegrepi_0_perform (guestfs_h *g)
{
  /* TestResult for zegrepi (0) */
  const char *arg2309 = "abc";
  const char *arg2310 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zegrepi (g, arg2309, arg2310);
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

static int test_zgrepi_0_skip (void);
static int test_zgrepi_0_perform (guestfs_h *);

static int
test_zgrepi_0 (guestfs_h *g)
{
  if (test_zgrepi_0_skip ()) {
    skipped ("test_zgrepi_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_zgrepi_0_perform (g);
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
test_zgrepi_0_perform (guestfs_h *g)
{
  /* TestResult for zgrepi (0) */
  const char *arg2312 = "abc";
  const char *arg2313 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zgrepi (g, arg2312, arg2313);
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

static int test_zfgrep_0_skip (void);
static int test_zfgrep_0_perform (guestfs_h *);

static int
test_zfgrep_0 (guestfs_h *g)
{
  if (test_zfgrep_0_skip ()) {
    skipped ("test_zfgrep_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_zfgrep_0_perform (g);
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
test_zfgrep_0_perform (guestfs_h *g)
{
  /* TestResult for zfgrep (0) */
  const char *arg2315 = "abc";
  const char *arg2316 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zfgrep (g, arg2315, arg2316);
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

static int test_zegrep_0_skip (void);
static int test_zegrep_0_perform (guestfs_h *);

static int
test_zegrep_0 (guestfs_h *g)
{
  if (test_zegrep_0_skip ()) {
    skipped ("test_zegrep_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_zegrep_0_perform (g);
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
test_zegrep_0_perform (guestfs_h *g)
{
  /* TestResult for zegrep (0) */
  const char *arg2318 = "abc";
  const char *arg2319 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zegrep (g, arg2318, arg2319);
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

static int test_zgrep_0_skip (void);
static int test_zgrep_0_perform (guestfs_h *);

static int
test_zgrep_0 (guestfs_h *g)
{
  if (test_zgrep_0_skip ()) {
    skipped ("test_zgrep_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_zgrep_0_perform (g);
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
test_zgrep_0_perform (guestfs_h *g)
{
  /* TestResult for zgrep (0) */
  const char *arg2321 = "abc";
  const char *arg2322 = "/test-grep.txt.gz";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_zgrep (g, arg2321, arg2322);
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

static int test_fgrepi_0_skip (void);
static int test_fgrepi_0_perform (guestfs_h *);

static int
test_fgrepi_0 (guestfs_h *g)
{
  if (test_fgrepi_0_skip ()) {
    skipped ("test_fgrepi_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_fgrepi_0_perform (g);
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
test_fgrepi_0_perform (guestfs_h *g)
{
  /* TestResult for fgrepi (0) */
  const char *arg2324 = "abc";
  const char *arg2325 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_fgrepi (g, arg2324, arg2325);
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

static int test_egrepi_0_skip (void);
static int test_egrepi_0_perform (guestfs_h *);

static int
test_egrepi_0 (guestfs_h *g)
{
  if (test_egrepi_0_skip ()) {
    skipped ("test_egrepi_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_egrepi_0_perform (g);
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
test_egrepi_0_perform (guestfs_h *g)
{
  /* TestResult for egrepi (0) */
  const char *arg2327 = "abc";
  const char *arg2328 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_egrepi (g, arg2327, arg2328);
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

static int test_grepi_0_skip (void);
static int test_grepi_0_perform (guestfs_h *);

static int
test_grepi_0 (guestfs_h *g)
{
  if (test_grepi_0_skip ()) {
    skipped ("test_grepi_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grepi_0_perform (g);
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
test_grepi_0_perform (guestfs_h *g)
{
  /* TestResult for grepi (0) */
  const char *arg2330 = "abc";
  const char *arg2331 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grepi (g, arg2330, arg2331);
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

static int test_fgrep_0_skip (void);
static int test_fgrep_0_perform (guestfs_h *);

static int
test_fgrep_0 (guestfs_h *g)
{
  if (test_fgrep_0_skip ()) {
    skipped ("test_fgrep_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_fgrep_0_perform (g);
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
test_fgrep_0_perform (guestfs_h *g)
{
  /* TestResult for fgrep (0) */
  const char *arg2333 = "abc";
  const char *arg2334 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_fgrep (g, arg2333, arg2334);
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

static int test_egrep_0_skip (void);
static int test_egrep_0_perform (guestfs_h *);

static int
test_egrep_0 (guestfs_h *g)
{
  if (test_egrep_0_skip ()) {
    skipped ("test_egrep_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_egrep_0_perform (g);
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
test_egrep_0_perform (guestfs_h *g)
{
  /* TestResult for egrep (0) */
  const char *arg2336 = "abc";
  const char *arg2337 = "/test-grep.txt";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_egrep (g, arg2336, arg2337);
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

static int test_grep_0_skip (void);
static int test_grep_0_perform (guestfs_h *);

static int
test_grep_0 (guestfs_h *g)
{
  if (test_grep_0_skip ()) {
    skipped ("test_grep_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_0_perform (g);
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
test_grep_0_perform (guestfs_h *g)
{
  /* TestResult for grep (0) */
  const char *arg2339 = "abc";
  const char *arg2340 = "/test-grep.txt";
  struct guestfs_grep_opts_argv optargs2341;
  optargs2341.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2339, arg2340, &optargs2341);
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

static int test_grep_1_skip (void);
static int test_grep_1_perform (guestfs_h *);

static int
test_grep_1 (guestfs_h *g)
{
  if (test_grep_1_skip ()) {
    skipped ("test_grep_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_1_perform (g);
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
test_grep_1_perform (guestfs_h *g)
{
  /* TestResult for grep (1) */
  const char *arg2342 = "nomatch";
  const char *arg2343 = "/test-grep.txt";
  struct guestfs_grep_opts_argv optargs2344;
  optargs2344.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2342, arg2343, &optargs2344);
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

static int test_grep_2_skip (void);
static int test_grep_2_perform (guestfs_h *);

static int
test_grep_2 (guestfs_h *g)
{
  if (test_grep_2_skip ()) {
    skipped ("test_grep_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_2_perform (g);
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
test_grep_2_perform (guestfs_h *g)
{
  /* TestResult for grep (2) */
  const char *arg2345 = "nomatch";
  const char *arg2346 = "/abssymlink";
  struct guestfs_grep_opts_argv optargs2347;
  optargs2347.bitmask = UINT64_C(0x0);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2345, arg2346, &optargs2347);
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

static int test_grep_3_skip (void);
static int test_grep_3_perform (guestfs_h *);

static int
test_grep_3 (guestfs_h *g)
{
  if (test_grep_3_skip ()) {
    skipped ("test_grep_3", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_3_perform (g);
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
test_grep_3_perform (guestfs_h *g)
{
  /* TestResult for grep (3) */
  const char *arg2348 = "abc";
  const char *arg2349 = "/test-grep.txt";
  struct guestfs_grep_opts_argv optargs2350;
  optargs2350.extended = 1;
  optargs2350.bitmask = UINT64_C(0x1);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2348, arg2349, &optargs2350);
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

static int test_grep_4_skip (void);
static int test_grep_4_perform (guestfs_h *);

static int
test_grep_4 (guestfs_h *g)
{
  if (test_grep_4_skip ()) {
    skipped ("test_grep_4", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_4_perform (g);
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
test_grep_4_perform (guestfs_h *g)
{
  /* TestResult for grep (4) */
  const char *arg2351 = "abc";
  const char *arg2352 = "/test-grep.txt";
  struct guestfs_grep_opts_argv optargs2353;
  optargs2353.fixed = 1;
  optargs2353.bitmask = UINT64_C(0x2);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2351, arg2352, &optargs2353);
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

static int test_grep_5_skip (void);
static int test_grep_5_perform (guestfs_h *);

static int
test_grep_5 (guestfs_h *g)
{
  if (test_grep_5_skip ()) {
    skipped ("test_grep_5", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_5_perform (g);
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
test_grep_5_perform (guestfs_h *g)
{
  /* TestResult for grep (5) */
  const char *arg2354 = "abc";
  const char *arg2355 = "/test-grep.txt";
  struct guestfs_grep_opts_argv optargs2356;
  optargs2356.insensitive = 1;
  optargs2356.bitmask = UINT64_C(0x4);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2354, arg2355, &optargs2356);
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

static int test_grep_6_skip (void);
static int test_grep_6_perform (guestfs_h *);

static int
test_grep_6 (guestfs_h *g)
{
  if (test_grep_6_skip ()) {
    skipped ("test_grep_6", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_6_perform (g);
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
test_grep_6_perform (guestfs_h *g)
{
  /* TestResult for grep (6) */
  const char *arg2357 = "abc";
  const char *arg2358 = "/test-grep.txt";
  struct guestfs_grep_opts_argv optargs2359;
  optargs2359.extended = 1;
  optargs2359.insensitive = 1;
  optargs2359.bitmask = UINT64_C(0x5);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2357, arg2358, &optargs2359);
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

static int test_grep_7_skip (void);
static int test_grep_7_perform (guestfs_h *);

static int
test_grep_7 (guestfs_h *g)
{
  if (test_grep_7_skip ()) {
    skipped ("test_grep_7", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_7_perform (g);
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
test_grep_7_perform (guestfs_h *g)
{
  /* TestResult for grep (7) */
  const char *arg2360 = "abc";
  const char *arg2361 = "/test-grep.txt";
  struct guestfs_grep_opts_argv optargs2362;
  optargs2362.fixed = 1;
  optargs2362.insensitive = 1;
  optargs2362.bitmask = UINT64_C(0x6);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2360, arg2361, &optargs2362);
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

static int test_grep_8_skip (void);
static int test_grep_8_perform (guestfs_h *);

static int
test_grep_8 (guestfs_h *g)
{
  if (test_grep_8_skip ()) {
    skipped ("test_grep_8", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_8_perform (g);
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
test_grep_8_perform (guestfs_h *g)
{
  /* TestResult for grep (8) */
  const char *arg2363 = "abc";
  const char *arg2364 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv optargs2365;
  optargs2365.compressed = 1;
  optargs2365.bitmask = UINT64_C(0x8);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2363, arg2364, &optargs2365);
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

static int test_grep_9_skip (void);
static int test_grep_9_perform (guestfs_h *);

static int
test_grep_9 (guestfs_h *g)
{
  if (test_grep_9_skip ()) {
    skipped ("test_grep_9", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_9_perform (g);
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
test_grep_9_perform (guestfs_h *g)
{
  /* TestResult for grep (9) */
  const char *arg2366 = "abc";
  const char *arg2367 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv optargs2368;
  optargs2368.extended = 1;
  optargs2368.compressed = 1;
  optargs2368.bitmask = UINT64_C(0x9);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2366, arg2367, &optargs2368);
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

static int test_grep_10_skip (void);
static int test_grep_10_perform (guestfs_h *);

static int
test_grep_10 (guestfs_h *g)
{
  if (test_grep_10_skip ()) {
    skipped ("test_grep_10", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_10_perform (g);
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
test_grep_10_perform (guestfs_h *g)
{
  /* TestResult for grep (10) */
  const char *arg2369 = "abc";
  const char *arg2370 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv optargs2371;
  optargs2371.fixed = 1;
  optargs2371.compressed = 1;
  optargs2371.bitmask = UINT64_C(0xa);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2369, arg2370, &optargs2371);
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

static int test_grep_11_skip (void);
static int test_grep_11_perform (guestfs_h *);

static int
test_grep_11 (guestfs_h *g)
{
  if (test_grep_11_skip ()) {
    skipped ("test_grep_11", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_11_perform (g);
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
test_grep_11_perform (guestfs_h *g)
{
  /* TestResult for grep (11) */
  const char *arg2372 = "abc";
  const char *arg2373 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv optargs2374;
  optargs2374.insensitive = 1;
  optargs2374.compressed = 1;
  optargs2374.bitmask = UINT64_C(0xc);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2372, arg2373, &optargs2374);
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

static int test_grep_12_skip (void);
static int test_grep_12_perform (guestfs_h *);

static int
test_grep_12 (guestfs_h *g)
{
  if (test_grep_12_skip ()) {
    skipped ("test_grep_12", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_12_perform (g);
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
test_grep_12_perform (guestfs_h *g)
{
  /* TestResult for grep (12) */
  const char *arg2375 = "abc";
  const char *arg2376 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv optargs2377;
  optargs2377.extended = 1;
  optargs2377.insensitive = 1;
  optargs2377.compressed = 1;
  optargs2377.bitmask = UINT64_C(0xd);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2375, arg2376, &optargs2377);
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

static int test_grep_13_skip (void);
static int test_grep_13_perform (guestfs_h *);

static int
test_grep_13 (guestfs_h *g)
{
  if (test_grep_13_skip ()) {
    skipped ("test_grep_13", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_grep_13_perform (g);
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
test_grep_13_perform (guestfs_h *g)
{
  /* TestResult for grep (13) */
  const char *arg2378 = "abc";
  const char *arg2379 = "/test-grep.txt.gz";
  struct guestfs_grep_opts_argv optargs2380;
  optargs2380.fixed = 1;
  optargs2380.insensitive = 1;
  optargs2380.compressed = 1;
  optargs2380.bitmask = UINT64_C(0xe);
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_grep_opts_argv (g, arg2378, arg2379, &optargs2380);
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

static int test_umask_0_skip (void);
static int test_umask_0_perform (guestfs_h *);

static int
test_umask_0 (guestfs_h *g)
{
  if (test_umask_0_skip ()) {
    skipped ("test_umask_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_umask_0_perform (g);
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
test_umask_0_perform (guestfs_h *g)
{
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

static int test_mknod_c_0_skip (void);
static int test_mknod_c_0_perform (guestfs_h *);

static int
test_mknod_c_0 (guestfs_h *g)
{
  if (test_mknod_c_0_skip ()) {
    skipped ("test_mknod_c_0", "environment variable set");
    return 0;
  }

  const char *features2383[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) features2383)) {
    skipped ("test_mknod_c_0", "group %s not available in daemon",
             features2383[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mknod_c_0_perform (g);
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
test_mknod_c_0_perform (guestfs_h *g)
{
  /* TestResult for mknod_c (0) */
  const char *arg2387 = "/mknod_c";
  int ret1;
  ret1 = guestfs_mknod_c (g, 511, 99, 66, arg2387);
  if (ret1 == -1)
    return -1;
  const char *arg2389 = "/mknod_c";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg2389);
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

static int test_mknod_c_1_skip (void);
static int test_mknod_c_1_perform (guestfs_h *);

static int
test_mknod_c_1 (guestfs_h *g)
{
  if (test_mknod_c_1_skip ()) {
    skipped ("test_mknod_c_1", "environment variable set");
    return 0;
  }

  const char *features2391[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) features2391)) {
    skipped ("test_mknod_c_1", "group %s not available in daemon",
             features2391[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mknod_c_1_perform (g);
}

static int
test_mknod_c_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mknod_c") == NULL;
  str = getenv ("SKIP_TEST_MKNOD_C_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKNOD_C");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mknod_c_1_perform (guestfs_h *g)
{
  /* TestLastFail for mknod_c (1) */
  const char *arg2396 = "/mknod_c-2";
  int ret2392;
  guestfs_push_error_handler (g, NULL, NULL);
  ret2392 = guestfs_mknod_c (g, 8703, 99, 66, arg2396);
  guestfs_pop_error_handler (g);
  if (ret2392 != -1)
    return -1;
  return 0;
}

static int test_mknod_b_0_skip (void);
static int test_mknod_b_0_perform (guestfs_h *);

static int
test_mknod_b_0 (guestfs_h *g)
{
  if (test_mknod_b_0_skip ()) {
    skipped ("test_mknod_b_0", "environment variable set");
    return 0;
  }

  const char *features2398[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) features2398)) {
    skipped ("test_mknod_b_0", "group %s not available in daemon",
             features2398[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mknod_b_0_perform (g);
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
test_mknod_b_0_perform (guestfs_h *g)
{
  /* TestResult for mknod_b (0) */
  const char *arg2402 = "/mknod_b";
  int ret1;
  ret1 = guestfs_mknod_b (g, 511, 99, 66, arg2402);
  if (ret1 == -1)
    return -1;
  const char *arg2404 = "/mknod_b";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg2404);
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

static int test_mknod_b_1_skip (void);
static int test_mknod_b_1_perform (guestfs_h *);

static int
test_mknod_b_1 (guestfs_h *g)
{
  if (test_mknod_b_1_skip ()) {
    skipped ("test_mknod_b_1", "environment variable set");
    return 0;
  }

  const char *features2406[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) features2406)) {
    skipped ("test_mknod_b_1", "group %s not available in daemon",
             features2406[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mknod_b_1_perform (g);
}

static int
test_mknod_b_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mknod_b") == NULL;
  str = getenv ("SKIP_TEST_MKNOD_B_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKNOD_B");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mknod_b_1_perform (guestfs_h *g)
{
  /* TestLastFail for mknod_b (1) */
  const char *arg2411 = "/mknod_b-2";
  int ret2407;
  guestfs_push_error_handler (g, NULL, NULL);
  ret2407 = guestfs_mknod_b (g, 4607, 99, 66, arg2411);
  guestfs_pop_error_handler (g);
  if (ret2407 != -1)
    return -1;
  return 0;
}

static int test_mkfifo_0_skip (void);
static int test_mkfifo_0_perform (guestfs_h *);

static int
test_mkfifo_0 (guestfs_h *g)
{
  if (test_mkfifo_0_skip ()) {
    skipped ("test_mkfifo_0", "environment variable set");
    return 0;
  }

  const char *features2413[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) features2413)) {
    skipped ("test_mkfifo_0", "group %s not available in daemon",
             features2413[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mkfifo_0_perform (g);
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
test_mkfifo_0_perform (guestfs_h *g)
{
  /* TestResult for mkfifo (0) */
  const char *arg2415 = "/mkfifo";
  int ret1;
  ret1 = guestfs_mkfifo (g, 511, arg2415);
  if (ret1 == -1)
    return -1;
  const char *arg2417 = "/mkfifo";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg2417);
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

static int test_mkfifo_1_skip (void);
static int test_mkfifo_1_perform (guestfs_h *);

static int
test_mkfifo_1 (guestfs_h *g)
{
  if (test_mkfifo_1_skip ()) {
    skipped ("test_mkfifo_1", "environment variable set");
    return 0;
  }

  const char *features2419[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) features2419)) {
    skipped ("test_mkfifo_1", "group %s not available in daemon",
             features2419[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mkfifo_1_perform (g);
}

static int
test_mkfifo_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "mkfifo") == NULL;
  str = getenv ("SKIP_TEST_MKFIFO_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_MKFIFO");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_mkfifo_1_perform (guestfs_h *g)
{
  /* TestLastFail for mkfifo (1) */
  const char *arg2422 = "/mkfifo-2";
  int ret2420;
  guestfs_push_error_handler (g, NULL, NULL);
  ret2420 = guestfs_mkfifo (g, 8703, arg2422);
  guestfs_pop_error_handler (g);
  if (ret2420 != -1)
    return -1;
  return 0;
}

static int test_mknod_0_skip (void);
static int test_mknod_0_perform (guestfs_h *);

static int
test_mknod_0 (guestfs_h *g)
{
  if (test_mknod_0_skip ()) {
    skipped ("test_mknod_0", "environment variable set");
    return 0;
  }

  const char *features2424[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) features2424)) {
    skipped ("test_mknod_0", "group %s not available in daemon",
             features2424[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mknod_0_perform (g);
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
test_mknod_0_perform (guestfs_h *g)
{
  /* TestResult for mknod (0) */
  const char *arg2428 = "/mknod";
  int ret1;
  ret1 = guestfs_mknod (g, 4607, 0, 0, arg2428);
  if (ret1 == -1)
    return -1;
  const char *arg2430 = "/mknod";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg2430);
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

static int test_mknod_1_skip (void);
static int test_mknod_1_perform (guestfs_h *);

static int
test_mknod_1 (guestfs_h *g)
{
  if (test_mknod_1_skip ()) {
    skipped ("test_mknod_1", "environment variable set");
    return 0;
  }

  const char *features2432[] = { "mknod", NULL };
  if (!guestfs_feature_available (g, (char **) features2432)) {
    skipped ("test_mknod_1", "group %s not available in daemon",
             features2432[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mknod_1_perform (g);
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
test_mknod_1_perform (guestfs_h *g)
{
  /* TestResult for mknod (1) */
  const char *arg2436 = "/mknod2";
  int ret1;
  ret1 = guestfs_mknod (g, 25087, 66, 99, arg2436);
  if (ret1 == -1)
    return -1;
  const char *arg2438 = "/mknod2";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg2438);
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

static int test_mkswap_U_0_skip (void);
static int test_mkswap_U_0_perform (guestfs_h *);

static int
test_mkswap_U_0 (guestfs_h *g)
{
  if (test_mkswap_U_0_skip ()) {
    skipped ("test_mkswap_U_0", "environment variable set");
    return 0;
  }

  const char *features2440[] = { "linuxfsuuid", NULL };
  if (!guestfs_feature_available (g, (char **) features2440)) {
    skipped ("test_mkswap_U_0", "group %s not available in daemon",
             features2440[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mkswap_U_0_perform (g);
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
test_mkswap_U_0_perform (guestfs_h *g)
{
  /* TestRun for mkswap_U (0) */
  const char *arg2442 = "/dev/sda";
  const char *arg2443 = "mbr";
  int ret2441;
  ret2441 = guestfs_part_disk (g, arg2442, arg2443);
  if (ret2441 == -1)
    return -1;
  const char *arg2446 = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  const char *arg2447 = "/dev/sda1";
  int ret2445;
  ret2445 = guestfs_mkswap_U (g, arg2446, arg2447);
  if (ret2445 == -1)
    return -1;
  return 0;
}

static int test_mkswap_L_0_skip (void);
static int test_mkswap_L_0_perform (guestfs_h *);

static int
test_mkswap_L_0 (guestfs_h *g)
{
  if (test_mkswap_L_0_skip ()) {
    skipped ("test_mkswap_L_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mkswap_L_0_perform (g);
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
test_mkswap_L_0_perform (guestfs_h *g)
{
  /* TestRun for mkswap_L (0) */
  const char *arg2450 = "/dev/sda";
  const char *arg2451 = "mbr";
  int ret2449;
  ret2449 = guestfs_part_disk (g, arg2450, arg2451);
  if (ret2449 == -1)
    return -1;
  const char *arg2454 = "hello";
  const char *arg2455 = "/dev/sda1";
  int ret2453;
  ret2453 = guestfs_mkswap_L (g, arg2454, arg2455);
  if (ret2453 == -1)
    return -1;
  return 0;
}

static int test_mkswap_0_skip (void);
static int test_mkswap_0_perform (guestfs_h *);

static int
test_mkswap_0 (guestfs_h *g)
{
  if (test_mkswap_0_skip ()) {
    skipped ("test_mkswap_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mkswap_0_perform (g);
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
test_mkswap_0_perform (guestfs_h *g)
{
  /* TestRun for mkswap (0) */
  const char *arg2458 = "/dev/sda";
  const char *arg2459 = "mbr";
  int ret2457;
  ret2457 = guestfs_part_disk (g, arg2458, arg2459);
  if (ret2457 == -1)
    return -1;
  const char *arg2462 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv optargs2463;
  optargs2463.bitmask = UINT64_C(0x0);
  int ret2461;
  ret2461 = guestfs_mkswap_opts_argv (g, arg2462, &optargs2463);
  if (ret2461 == -1)
    return -1;
  return 0;
}

static int test_mkswap_1_skip (void);
static int test_mkswap_1_perform (guestfs_h *);

static int
test_mkswap_1 (guestfs_h *g)
{
  if (test_mkswap_1_skip ()) {
    skipped ("test_mkswap_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mkswap_1_perform (g);
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
test_mkswap_1_perform (guestfs_h *g)
{
  /* TestRun for mkswap (1) */
  const char *arg2465 = "/dev/sda";
  const char *arg2466 = "mbr";
  int ret2464;
  ret2464 = guestfs_part_disk (g, arg2465, arg2466);
  if (ret2464 == -1)
    return -1;
  const char *arg2469 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv optargs2470;
  optargs2470.label = "hello";
  optargs2470.bitmask = UINT64_C(0x1);
  int ret2468;
  ret2468 = guestfs_mkswap_opts_argv (g, arg2469, &optargs2470);
  if (ret2468 == -1)
    return -1;
  return 0;
}

static int test_mkswap_2_skip (void);
static int test_mkswap_2_perform (guestfs_h *);

static int
test_mkswap_2 (guestfs_h *g)
{
  if (test_mkswap_2_skip ()) {
    skipped ("test_mkswap_2", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mkswap_2_perform (g);
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
test_mkswap_2_perform (guestfs_h *g)
{
  /* TestResultString for mkswap (2) */
  const char *arg2472 = "/dev/sda";
  const char *arg2473 = "mbr";
  int ret2471;
  ret2471 = guestfs_part_disk (g, arg2472, arg2473);
  if (ret2471 == -1)
    return -1;
  const char *arg2476 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv optargs2477;
  optargs2477.uuid = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  optargs2477.bitmask = UINT64_C(0x2);
  int ret2475;
  ret2475 = guestfs_mkswap_opts_argv (g, arg2476, &optargs2477);
  if (ret2475 == -1)
    return -1;
  const char *arg2478 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_uuid (g, arg2478);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mkswap_2", "vfs_uuid", "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc", ret);
    return -1;
  }
  return 0;
}

static int test_mkswap_3_skip (void);
static int test_mkswap_3_perform (guestfs_h *);

static int
test_mkswap_3 (guestfs_h *g)
{
  if (test_mkswap_3_skip ()) {
    skipped ("test_mkswap_3", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mkswap_3_perform (g);
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
test_mkswap_3_perform (guestfs_h *g)
{
  /* TestResultString for mkswap (3) */
  const char *arg2481 = "/dev/sda";
  const char *arg2482 = "mbr";
  int ret2480;
  ret2480 = guestfs_part_disk (g, arg2481, arg2482);
  if (ret2480 == -1)
    return -1;
  const char *arg2485 = "/dev/sda1";
  struct guestfs_mkswap_opts_argv optargs2486;
  optargs2486.label = "hello";
  optargs2486.uuid = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  optargs2486.bitmask = UINT64_C(0x3);
  int ret2484;
  ret2484 = guestfs_mkswap_opts_argv (g, arg2485, &optargs2486);
  if (ret2484 == -1)
    return -1;
  const char *arg2487 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_vfs_label (g, arg2487);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "hello")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mkswap_3", "vfs_label", "hello", ret);
    return -1;
  }
  return 0;
}

static int test_initrd_list_0_skip (void);
static int test_initrd_list_0_perform (guestfs_h *);

static int
test_initrd_list_0 (guestfs_h *g)
{
  if (test_initrd_list_0_skip ()) {
    skipped ("test_initrd_list_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_initrd_list_0_perform (g);
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
test_initrd_list_0_perform (guestfs_h *g)
{
  /* TestResult for initrd_list (0) */
  const char *arg2489 = "/initrd";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_initrd_list (g, arg2489);
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

static int test_du_0_skip (void);
static int test_du_0_perform (guestfs_h *);

static int
test_du_0 (guestfs_h *g)
{
  if (test_du_0_skip ()) {
    skipped ("test_du_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_du_0_perform (g);
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
test_du_0_perform (guestfs_h *g)
{
  /* TestResult for du (0) */
  const char *arg2491 = "/directory";
  int64_t ret;
  ret = guestfs_du (g, arg2491);
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

static int test_tail_n_0_skip (void);
static int test_tail_n_0_perform (guestfs_h *);

static int
test_tail_n_0 (guestfs_h *g)
{
  if (test_tail_n_0_skip ()) {
    skipped ("test_tail_n_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_tail_n_0_perform (g);
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
test_tail_n_0_perform (guestfs_h *g)
{
  /* TestResult for tail_n (0) */
  const char *arg2494 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, 3, arg2494);
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

static int test_tail_n_1_skip (void);
static int test_tail_n_1_perform (guestfs_h *);

static int
test_tail_n_1 (guestfs_h *g)
{
  if (test_tail_n_1_skip ()) {
    skipped ("test_tail_n_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_tail_n_1_perform (g);
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
test_tail_n_1_perform (guestfs_h *g)
{
  /* TestResult for tail_n (1) */
  const char *arg2497 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, -9998, arg2497);
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

static int test_tail_n_2_skip (void);
static int test_tail_n_2_perform (guestfs_h *);

static int
test_tail_n_2 (guestfs_h *g)
{
  if (test_tail_n_2_skip ()) {
    skipped ("test_tail_n_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_tail_n_2_perform (g);
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
test_tail_n_2_perform (guestfs_h *g)
{
  /* TestResult for tail_n (2) */
  const char *arg2500 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail_n (g, 0, arg2500);
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

static int test_tail_0_skip (void);
static int test_tail_0_perform (guestfs_h *);

static int
test_tail_0 (guestfs_h *g)
{
  if (test_tail_0_skip ()) {
    skipped ("test_tail_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_tail_0_perform (g);
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
test_tail_0_perform (guestfs_h *g)
{
  /* TestResult for tail (0) */
  const char *arg2502 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tail (g, arg2502);
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

static int test_head_n_0_skip (void);
static int test_head_n_0_perform (guestfs_h *);

static int
test_head_n_0 (guestfs_h *g)
{
  if (test_head_n_0_skip ()) {
    skipped ("test_head_n_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_head_n_0_perform (g);
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
test_head_n_0_perform (guestfs_h *g)
{
  /* TestResult for head_n (0) */
  const char *arg2505 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, 3, arg2505);
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

static int test_head_n_1_skip (void);
static int test_head_n_1_perform (guestfs_h *);

static int
test_head_n_1 (guestfs_h *g)
{
  if (test_head_n_1_skip ()) {
    skipped ("test_head_n_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_head_n_1_perform (g);
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
test_head_n_1_perform (guestfs_h *g)
{
  /* TestResult for head_n (1) */
  const char *arg2508 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, -9997, arg2508);
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

static int test_head_n_2_skip (void);
static int test_head_n_2_perform (guestfs_h *);

static int
test_head_n_2 (guestfs_h *g)
{
  if (test_head_n_2_skip ()) {
    skipped ("test_head_n_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_head_n_2_perform (g);
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
test_head_n_2_perform (guestfs_h *g)
{
  /* TestResult for head_n (2) */
  const char *arg2511 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head_n (g, 0, arg2511);
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

static int test_head_0_skip (void);
static int test_head_0_perform (guestfs_h *);

static int
test_head_0 (guestfs_h *g)
{
  if (test_head_0_skip ()) {
    skipped ("test_head_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_head_0_perform (g);
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
test_head_0_perform (guestfs_h *g)
{
  /* TestResult for head (0) */
  const char *arg2513 = "/10klines";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head (g, arg2513);
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

static int test_head_1_skip (void);
static int test_head_1_perform (guestfs_h *);

static int
test_head_1 (guestfs_h *g)
{
  if (test_head_1_skip ()) {
    skipped ("test_head_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_head_1_perform (g);
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
test_head_1_perform (guestfs_h *g)
{
  /* TestResult for head (1) */
  const char *arg2515 = "/abssymlink";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_head (g, arg2515);
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

static int test_wc_c_0_skip (void);
static int test_wc_c_0_perform (guestfs_h *);

static int
test_wc_c_0 (guestfs_h *g)
{
  if (test_wc_c_0_skip ()) {
    skipped ("test_wc_c_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_wc_c_0_perform (g);
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
test_wc_c_0_perform (guestfs_h *g)
{
  /* TestResult for wc_c (0) */
  const char *arg2517 = "/100kallspaces";
  int ret;
  ret = guestfs_wc_c (g, arg2517);
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

static int test_wc_w_0_skip (void);
static int test_wc_w_0_perform (guestfs_h *);

static int
test_wc_w_0 (guestfs_h *g)
{
  if (test_wc_w_0_skip ()) {
    skipped ("test_wc_w_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_wc_w_0_perform (g);
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
test_wc_w_0_perform (guestfs_h *g)
{
  /* TestResult for wc_w (0) */
  const char *arg2519 = "/10klines";
  int ret;
  ret = guestfs_wc_w (g, arg2519);
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

static int test_wc_l_0_skip (void);
static int test_wc_l_0_perform (guestfs_h *);

static int
test_wc_l_0 (guestfs_h *g)
{
  if (test_wc_l_0_skip ()) {
    skipped ("test_wc_l_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_wc_l_0_perform (g);
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
test_wc_l_0_perform (guestfs_h *g)
{
  /* TestResult for wc_l (0) */
  const char *arg2521 = "/10klines";
  int ret;
  ret = guestfs_wc_l (g, arg2521);
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

static int test_wc_l_1_skip (void);
static int test_wc_l_1_perform (guestfs_h *);

static int
test_wc_l_1 (guestfs_h *g)
{
  if (test_wc_l_1_skip ()) {
    skipped ("test_wc_l_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_wc_l_1_perform (g);
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
test_wc_l_1_perform (guestfs_h *g)
{
  /* TestResult for wc_l (1) */
  const char *arg2523 = "/abssymlink";
  int ret;
  ret = guestfs_wc_l (g, arg2523);
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

static int test_mkdtemp_0_skip (void);
static int test_mkdtemp_0_perform (guestfs_h *);

static int
test_mkdtemp_0 (guestfs_h *g)
{
  if (test_mkdtemp_0_skip ()) {
    skipped ("test_mkdtemp_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mkdtemp_0_perform (g);
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
test_mkdtemp_0_perform (guestfs_h *g)
{
  /* TestRun for mkdtemp (0) */
  const char *arg2526 = "/mkdtemp";
  int ret2525;
  ret2525 = guestfs_mkdir (g, arg2526);
  if (ret2525 == -1)
    return -1;
  const char *arg2529 = "/mkdtemp/tmpXXXXXX";
  CLEANUP_FREE char *ret2528;
  ret2528 = guestfs_mkdtemp (g, arg2529);
  if (ret2528 == NULL)
      return -1;
  return 0;
}

static int test_scrub_file_0_skip (void);
static int test_scrub_file_0_perform (guestfs_h *);

static int
test_scrub_file_0 (guestfs_h *g)
{
  if (test_scrub_file_0_skip ()) {
    skipped ("test_scrub_file_0", "environment variable set");
    return 0;
  }

  const char *features2531[] = { "scrub", NULL };
  if (!guestfs_feature_available (g, (char **) features2531)) {
    skipped ("test_scrub_file_0", "group %s not available in daemon",
             features2531[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_scrub_file_0_perform (g);
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
test_scrub_file_0_perform (guestfs_h *g)
{
  /* TestRun for scrub_file (0) */
  const char *arg2533 = "/scrub_file";
  const char *arg2534 = "content";
  size_t arg2534_size = 7;
  int ret2532;
  ret2532 = guestfs_write (g, arg2533, arg2534, arg2534_size);
  if (ret2532 == -1)
    return -1;
  const char *arg2537 = "/scrub_file";
  int ret2536;
  ret2536 = guestfs_scrub_file (g, arg2537);
  if (ret2536 == -1)
    return -1;
  return 0;
}

static int test_scrub_file_1_skip (void);
static int test_scrub_file_1_perform (guestfs_h *);

static int
test_scrub_file_1 (guestfs_h *g)
{
  if (test_scrub_file_1_skip ()) {
    skipped ("test_scrub_file_1", "environment variable set");
    return 0;
  }

  const char *features2539[] = { "scrub", NULL };
  if (!guestfs_feature_available (g, (char **) features2539)) {
    skipped ("test_scrub_file_1", "group %s not available in daemon",
             features2539[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_scrub_file_1_perform (g);
}

static int
test_scrub_file_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "scrub_file") == NULL;
  str = getenv ("SKIP_TEST_SCRUB_FILE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SCRUB_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_scrub_file_1_perform (guestfs_h *g)
{
  /* TestRun for scrub_file (1) */
  const char *arg2541 = "/scrub_file_2";
  const char *arg2542 = "content";
  size_t arg2542_size = 7;
  int ret2540;
  ret2540 = guestfs_write (g, arg2541, arg2542, arg2542_size);
  if (ret2540 == -1)
    return -1;
  const char *arg2545 = "/scrub_file_2";
  const char *arg2546 = "/scrub_file_2_link";
  int ret2544;
  ret2544 = guestfs_ln_s (g, arg2545, arg2546);
  if (ret2544 == -1)
    return -1;
  const char *arg2549 = "/scrub_file_2_link";
  int ret2548;
  ret2548 = guestfs_scrub_file (g, arg2549);
  if (ret2548 == -1)
    return -1;
  return 0;
}

static int test_scrub_file_2_skip (void);
static int test_scrub_file_2_perform (guestfs_h *);

static int
test_scrub_file_2 (guestfs_h *g)
{
  if (test_scrub_file_2_skip ()) {
    skipped ("test_scrub_file_2", "environment variable set");
    return 0;
  }

  const char *features2551[] = { "scrub", NULL };
  if (!guestfs_feature_available (g, (char **) features2551)) {
    skipped ("test_scrub_file_2", "group %s not available in daemon",
             features2551[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_scrub_file_2_perform (g);
}

static int
test_scrub_file_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "scrub_file") == NULL;
  str = getenv ("SKIP_TEST_SCRUB_FILE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SCRUB_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_scrub_file_2_perform (guestfs_h *g)
{
  /* TestLastFail for scrub_file (2) */
  const char *arg2553 = "/scrub_file_3_notexisting";
  const char *arg2554 = "/scrub_file_3_link";
  int ret2552;
  ret2552 = guestfs_ln_s (g, arg2553, arg2554);
  if (ret2552 == -1)
    return -1;
  const char *arg2557 = "/scrub_file_3_link";
  int ret2556;
  guestfs_push_error_handler (g, NULL, NULL);
  ret2556 = guestfs_scrub_file (g, arg2557);
  guestfs_pop_error_handler (g);
  if (ret2556 != -1)
    return -1;
  return 0;
}

static int test_scrub_file_3_skip (void);
static int test_scrub_file_3_perform (guestfs_h *);

static int
test_scrub_file_3 (guestfs_h *g)
{
  if (test_scrub_file_3_skip ()) {
    skipped ("test_scrub_file_3", "environment variable set");
    return 0;
  }

  const char *features2559[] = { "scrub", NULL };
  if (!guestfs_feature_available (g, (char **) features2559)) {
    skipped ("test_scrub_file_3", "group %s not available in daemon",
             features2559[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_scrub_file_3_perform (g);
}

static int
test_scrub_file_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "scrub_file") == NULL;
  str = getenv ("SKIP_TEST_SCRUB_FILE_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SCRUB_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_scrub_file_3_perform (guestfs_h *g)
{
  /* TestLastFail for scrub_file (3) */
  const char *arg2561 = "/scrub_file_4";
  const char *arg2562 = "content";
  size_t arg2562_size = 7;
  int ret2560;
  ret2560 = guestfs_write (g, arg2561, arg2562, arg2562_size);
  if (ret2560 == -1)
    return -1;
  const char *arg2565 = "../sysroot/scrub_file_4";
  const char *arg2566 = "/scrub_file_4_link";
  int ret2564;
  ret2564 = guestfs_ln_s (g, arg2565, arg2566);
  if (ret2564 == -1)
    return -1;
  const char *arg2569 = "/scrub_file_4_link";
  int ret2568;
  guestfs_push_error_handler (g, NULL, NULL);
  ret2568 = guestfs_scrub_file (g, arg2569);
  guestfs_pop_error_handler (g);
  if (ret2568 != -1)
    return -1;
  return 0;
}

static int test_scrub_device_0_skip (void);
static int test_scrub_device_0_perform (guestfs_h *);

static int
test_scrub_device_0 (guestfs_h *g)
{
  if (test_scrub_device_0_skip ()) {
    skipped ("test_scrub_device_0", "environment variable set");
    return 0;
  }

  const char *features2571[] = { "scrub", NULL };
  if (!guestfs_feature_available (g, (char **) features2571)) {
    skipped ("test_scrub_device_0", "group %s not available in daemon",
             features2571[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_scrub_device_0_perform (g);
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
test_scrub_device_0_perform (guestfs_h *g)
{
  /* TestRun for scrub_device (0) */
  const char *arg2573 = "/dev/sdc";
  int ret2572;
  ret2572 = guestfs_scrub_device (g, arg2573);
  if (ret2572 == -1)
    return -1;
  return 0;
}

static int test_glob_expand_0_skip (void);
static int test_glob_expand_0_perform (guestfs_h *);

static int
test_glob_expand_0 (guestfs_h *g)
{
  if (test_glob_expand_0_skip ()) {
    skipped ("test_glob_expand_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_glob_expand_0_perform (g);
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
test_glob_expand_0_perform (guestfs_h *g)
{
  /* TestResult for glob_expand (0) */
  const char *arg2575 = "/glob_expand/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, arg2575);
  if (ret3 == -1)
    return -1;
  const char *arg2577 = "/glob_expand/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, arg2577);
  if (ret2 == -1)
    return -1;
  const char *arg2579 = "/glob_expand/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, arg2579);
  if (ret1 == -1)
    return -1;
  const char *arg2581 = "/glob_expand/b/c/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, arg2581);
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

static int test_glob_expand_1_skip (void);
static int test_glob_expand_1_perform (guestfs_h *);

static int
test_glob_expand_1 (guestfs_h *g)
{
  if (test_glob_expand_1_skip ()) {
    skipped ("test_glob_expand_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_glob_expand_1_perform (g);
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
test_glob_expand_1_perform (guestfs_h *g)
{
  /* TestResult for glob_expand (1) */
  const char *arg2583 = "/glob_expand2/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, arg2583);
  if (ret3 == -1)
    return -1;
  const char *arg2585 = "/glob_expand2/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, arg2585);
  if (ret2 == -1)
    return -1;
  const char *arg2587 = "/glob_expand2/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, arg2587);
  if (ret1 == -1)
    return -1;
  const char *arg2589 = "/glob_expand2/*/c/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, arg2589);
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

static int test_glob_expand_2_skip (void);
static int test_glob_expand_2_perform (guestfs_h *);

static int
test_glob_expand_2 (guestfs_h *g)
{
  if (test_glob_expand_2_skip ()) {
    skipped ("test_glob_expand_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_glob_expand_2_perform (g);
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
test_glob_expand_2_perform (guestfs_h *g)
{
  /* TestResult for glob_expand (2) */
  const char *arg2591 = "/glob_expand3/b/c";
  int ret3;
  ret3 = guestfs_mkdir_p (g, arg2591);
  if (ret3 == -1)
    return -1;
  const char *arg2593 = "/glob_expand3/b/c/d";
  int ret2;
  ret2 = guestfs_touch (g, arg2593);
  if (ret2 == -1)
    return -1;
  const char *arg2595 = "/glob_expand3/b/c/e";
  int ret1;
  ret1 = guestfs_touch (g, arg2595);
  if (ret1 == -1)
    return -1;
  const char *arg2597 = "/glob_expand3/*/x/*";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_glob_expand (g, arg2597);
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

static int test_ntfs_3g_probe_0_skip (void);
static int test_ntfs_3g_probe_0_perform (guestfs_h *);

static int
test_ntfs_3g_probe_0 (guestfs_h *g)
{
  if (test_ntfs_3g_probe_0_skip ()) {
    skipped ("test_ntfs_3g_probe_0", "environment variable set");
    return 0;
  }

  const char *features2599[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) features2599)) {
    skipped ("test_ntfs_3g_probe_0", "group %s not available in daemon",
             features2599[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_ntfs_3g_probe_0_perform (g);
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
test_ntfs_3g_probe_0_perform (guestfs_h *g)
{
  /* TestResult for ntfs_3g_probe (0) */
  const char *arg2600 = "/dev/sda";
  const char *arg2601 = "mbr";
  int ret2;
  ret2 = guestfs_part_disk (g, arg2600, arg2601);
  if (ret2 == -1)
    return -1;
  const char *arg2603 = "ntfs";
  const char *arg2604 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs2605;
  optargs2605.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_mkfs_opts_argv (g, arg2603, arg2604, &optargs2605);
  if (ret1 == -1)
    return -1;
  const char *arg2607 = "/dev/sda1";
  int ret;
  ret = guestfs_ntfs_3g_probe (g, 1, arg2607);
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

static int test_ntfs_3g_probe_1_skip (void);
static int test_ntfs_3g_probe_1_perform (guestfs_h *);

static int
test_ntfs_3g_probe_1 (guestfs_h *g)
{
  if (test_ntfs_3g_probe_1_skip ()) {
    skipped ("test_ntfs_3g_probe_1", "environment variable set");
    return 0;
  }

  const char *features2609[] = { "ntfs3g", NULL };
  if (!guestfs_feature_available (g, (char **) features2609)) {
    skipped ("test_ntfs_3g_probe_1", "group %s not available in daemon",
             features2609[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_ntfs_3g_probe_1_perform (g);
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
test_ntfs_3g_probe_1_perform (guestfs_h *g)
{
  /* TestResult for ntfs_3g_probe (1) */
  const char *arg2610 = "/dev/sda";
  const char *arg2611 = "mbr";
  int ret2;
  ret2 = guestfs_part_disk (g, arg2610, arg2611);
  if (ret2 == -1)
    return -1;
  const char *arg2613 = "ext2";
  const char *arg2614 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs2615;
  optargs2615.bitmask = UINT64_C(0x0);
  int ret1;
  ret1 = guestfs_mkfs_opts_argv (g, arg2613, arg2614, &optargs2615);
  if (ret1 == -1)
    return -1;
  const char *arg2617 = "/dev/sda1";
  int ret;
  ret = guestfs_ntfs_3g_probe (g, 1, arg2617);
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

static int test_sleep_0_skip (void);
static int test_sleep_0_perform (guestfs_h *);

static int
test_sleep_0 (guestfs_h *g)
{
  if (test_sleep_0_skip ()) {
    skipped ("test_sleep_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_sleep_0_perform (g);
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
test_sleep_0_perform (guestfs_h *g)
{
  /* TestRun for sleep (0) */
  int ret2619;
  ret2619 = guestfs_sleep (g, 1);
  if (ret2619 == -1)
    return -1;
  return 0;
}

static int test_lvresize_0_skip (void);
static int test_lvresize_0_perform (guestfs_h *);

static int
test_lvresize_0 (guestfs_h *g)
{
  if (test_lvresize_0_skip ()) {
    skipped ("test_lvresize_0", "environment variable set");
    return 0;
  }

  const char *features2622[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features2622)) {
    skipped ("test_lvresize_0", "group %s not available in daemon",
             features2622[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_lvresize_0_perform (g);
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
test_lvresize_0_perform (guestfs_h *g)
{
  /* TestResultString for lvresize (0) */
  const char *arg2624 = "/dev/sda";
  const char *arg2625 = "mbr";
  int ret2623;
  ret2623 = guestfs_part_disk (g, arg2624, arg2625);
  if (ret2623 == -1)
    return -1;
  const char *arg2628 = "/dev/sda1";
  int ret2627;
  ret2627 = guestfs_pvcreate (g, arg2628);
  if (ret2627 == -1)
    return -1;
  const char *arg2631 = "VG";
  const char *arg2632_0 = "/dev/sda1";
  const char *const arg2632[] = {
    arg2632_0,
    NULL
  };
  int ret2630;
  ret2630 = guestfs_vgcreate (g, arg2631, (char **) arg2632);
  if (ret2630 == -1)
    return -1;
  const char *arg2635 = "LV";
  const char *arg2636 = "VG";
  int ret2634;
  ret2634 = guestfs_lvcreate (g, arg2635, arg2636, 10);
  if (ret2634 == -1)
    return -1;
  const char *arg2640 = "ext2";
  const char *arg2641 = "/dev/VG/LV";
  struct guestfs_mkfs_opts_argv optargs2642;
  optargs2642.bitmask = UINT64_C(0x0);
  int ret2639;
  ret2639 = guestfs_mkfs_opts_argv (g, arg2640, arg2641, &optargs2642);
  if (ret2639 == -1)
    return -1;
  const char *arg2644 = "/dev/VG/LV";
  const char *arg2645 = "/";
  int ret2643;
  ret2643 = guestfs_mount (g, arg2644, arg2645);
  if (ret2643 == -1)
    return -1;
  const char *arg2648 = "/new";
  const char *arg2649 = "test content";
  size_t arg2649_size = 12;
  int ret2647;
  ret2647 = guestfs_write (g, arg2648, arg2649, arg2649_size);
  if (ret2647 == -1)
    return -1;
  const char *arg2652 = "/";
  struct guestfs_umount_opts_argv optargs2653;
  optargs2653.force = 0;
  optargs2653.lazyunmount = 0;
  optargs2653.bitmask = UINT64_C(0x3);
  int ret2651;
  ret2651 = guestfs_umount_opts_argv (g, arg2652, &optargs2653);
  if (ret2651 == -1)
    return -1;
  const char *arg2655 = "/dev/VG/LV";
  int ret2654;
  ret2654 = guestfs_lvresize (g, arg2655, 20);
  if (ret2654 == -1)
    return -1;
  const char *arg2659 = "/dev/VG/LV";
  int ret2658;
  ret2658 = guestfs_e2fsck_f (g, arg2659);
  if (ret2658 == -1)
    return -1;
  const char *arg2662 = "/dev/VG/LV";
  struct guestfs_e2fsck_argv optargs2663;
  optargs2663.correct = 1;
  optargs2663.forceall = 0;
  optargs2663.bitmask = UINT64_C(0x3);
  int ret2661;
  ret2661 = guestfs_e2fsck_argv (g, arg2662, &optargs2663);
  if (ret2661 == -1)
    return -1;
  const char *arg2665 = "/dev/VG/LV";
  struct guestfs_e2fsck_argv optargs2666;
  optargs2666.correct = 0;
  optargs2666.forceall = 1;
  optargs2666.bitmask = UINT64_C(0x3);
  int ret2664;
  ret2664 = guestfs_e2fsck_argv (g, arg2665, &optargs2666);
  if (ret2664 == -1)
    return -1;
  const char *arg2668 = "/dev/VG/LV";
  int ret2667;
  ret2667 = guestfs_resize2fs (g, arg2668);
  if (ret2667 == -1)
    return -1;
  const char *arg2671 = "/dev/VG/LV";
  const char *arg2672 = "/";
  int ret2670;
  ret2670 = guestfs_mount (g, arg2671, arg2672);
  if (ret2670 == -1)
    return -1;
  const char *arg2674 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg2674);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "test content")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_lvresize_0", "cat", "test content", ret);
    return -1;
  }
  return 0;
}

static int test_lvresize_1_skip (void);
static int test_lvresize_1_perform (guestfs_h *);

static int
test_lvresize_1 (guestfs_h *g)
{
  if (test_lvresize_1_skip ()) {
    skipped ("test_lvresize_1", "environment variable set");
    return 0;
  }

  const char *features2676[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features2676)) {
    skipped ("test_lvresize_1", "group %s not available in daemon",
             features2676[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_lvresize_1_perform (g);
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
test_lvresize_1_perform (guestfs_h *g)
{
  /* TestRun for lvresize (1) */
  const char *arg2678 = "/dev/sda";
  const char *arg2679 = "mbr";
  int ret2677;
  ret2677 = guestfs_part_disk (g, arg2678, arg2679);
  if (ret2677 == -1)
    return -1;
  const char *arg2682 = "/dev/sda1";
  int ret2681;
  ret2681 = guestfs_pvcreate (g, arg2682);
  if (ret2681 == -1)
    return -1;
  const char *arg2685 = "VG";
  const char *arg2686_0 = "/dev/sda1";
  const char *const arg2686[] = {
    arg2686_0,
    NULL
  };
  int ret2684;
  ret2684 = guestfs_vgcreate (g, arg2685, (char **) arg2686);
  if (ret2684 == -1)
    return -1;
  const char *arg2689 = "LV";
  const char *arg2690 = "VG";
  int ret2688;
  ret2688 = guestfs_lvcreate (g, arg2689, arg2690, 20);
  if (ret2688 == -1)
    return -1;
  const char *arg2694 = "/dev/VG/LV";
  int ret2693;
  ret2693 = guestfs_lvresize (g, arg2694, 10);
  if (ret2693 == -1)
    return -1;
  return 0;
}

static int test_zerofree_0_skip (void);
static int test_zerofree_0_perform (guestfs_h *);

static int
test_zerofree_0 (guestfs_h *g)
{
  if (test_zerofree_0_skip ()) {
    skipped ("test_zerofree_0", "environment variable set");
    return 0;
  }

  const char *features2697[] = { "zerofree", NULL };
  if (!guestfs_feature_available (g, (char **) features2697)) {
    skipped ("test_zerofree_0", "group %s not available in daemon",
             features2697[0]);
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_zerofree_0_perform (g);
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
test_zerofree_0_perform (guestfs_h *g)
{
  /* TestResultString for zerofree (0) */
  const char *arg2699 = "/dev/sda";
  const char *arg2700 = "mbr";
  int ret2698;
  ret2698 = guestfs_part_disk (g, arg2699, arg2700);
  if (ret2698 == -1)
    return -1;
  const char *arg2703 = "ext3";
  const char *arg2704 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs2705;
  optargs2705.bitmask = UINT64_C(0x0);
  int ret2702;
  ret2702 = guestfs_mkfs_opts_argv (g, arg2703, arg2704, &optargs2705);
  if (ret2702 == -1)
    return -1;
  const char *arg2707 = "/dev/sda1";
  const char *arg2708 = "/";
  int ret2706;
  ret2706 = guestfs_mount (g, arg2707, arg2708);
  if (ret2706 == -1)
    return -1;
  const char *arg2711 = "/new";
  const char *arg2712 = "test file";
  size_t arg2712_size = 9;
  int ret2710;
  ret2710 = guestfs_write (g, arg2711, arg2712, arg2712_size);
  if (ret2710 == -1)
    return -1;
  const char *arg2715 = "/dev/sda1";
  struct guestfs_umount_opts_argv optargs2716;
  optargs2716.force = 0;
  optargs2716.lazyunmount = 0;
  optargs2716.bitmask = UINT64_C(0x3);
  int ret2714;
  ret2714 = guestfs_umount_opts_argv (g, arg2715, &optargs2716);
  if (ret2714 == -1)
    return -1;
  const char *arg2718 = "/dev/sda1";
  int ret2717;
  ret2717 = guestfs_zerofree (g, arg2718);
  if (ret2717 == -1)
    return -1;
  const char *arg2721 = "/dev/sda1";
  const char *arg2722 = "/";
  int ret2720;
  ret2720 = guestfs_mount (g, arg2721, arg2722);
  if (ret2720 == -1)
    return -1;
  const char *arg2724 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg2724);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "test file")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_zerofree_0", "cat", "test file", ret);
    return -1;
  }
  return 0;
}

static int test_hexdump_0_skip (void);
static int test_hexdump_0_perform (guestfs_h *);

static int
test_hexdump_0 (guestfs_h *g)
{
  if (test_hexdump_0_skip ()) {
    skipped ("test_hexdump_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_hexdump_0_perform (g);
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
test_hexdump_0_perform (guestfs_h *g)
{
  /* TestResultString for hexdump (0) */
  const char *arg2726 = "/known-4";
  CLEANUP_FREE char *ret;
  ret = guestfs_hexdump (g, arg2726);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "00000000  61 62 63 0a 64 65 66 0a  67 68 69                 |abc.def.ghi|\n0000000b\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_hexdump_0", "hexdump", "00000000  61 62 63 0a 64 65 66 0a  67 68 69                 |abc.def.ghi|\n0000000b\n", ret);
    return -1;
  }
  return 0;
}

static int test_hexdump_1_skip (void);
static int test_hexdump_1_perform (guestfs_h *);

static int
test_hexdump_1 (guestfs_h *g)
{
  if (test_hexdump_1_skip ()) {
    skipped ("test_hexdump_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_hexdump_1_perform (g);
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
test_hexdump_1_perform (guestfs_h *g)
{
  /* TestRun for hexdump (1) */
  const char *arg2729 = "/100krandom";
  CLEANUP_FREE char *ret2728;
  ret2728 = guestfs_hexdump (g, arg2729);
  if (ret2728 == NULL)
      return -1;
  return 0;
}

static int test_hexdump_2_skip (void);
static int test_hexdump_2_perform (guestfs_h *);

static int
test_hexdump_2 (guestfs_h *g)
{
  if (test_hexdump_2_skip ()) {
    skipped ("test_hexdump_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_hexdump_2_perform (g);
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
test_hexdump_2_perform (guestfs_h *g)
{
  /* TestRun for hexdump (2) */
  const char *arg2732 = "/abssymlink";
  CLEANUP_FREE char *ret2731;
  ret2731 = guestfs_hexdump (g, arg2732);
  if (ret2731 == NULL)
      return -1;
  return 0;
}

static int test_strings_e_0_skip (void);
static int test_strings_e_0_perform (guestfs_h *);

static int
test_strings_e_0 (guestfs_h *g)
{
  if (test_strings_e_0_skip ()) {
    skipped ("test_strings_e_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_strings_e_0_perform (g);
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
test_strings_e_0_perform (guestfs_h *g)
{
  /* TestResult for strings_e (0) */
  const char *arg2734 = "b";
  const char *arg2735 = "/known-5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings_e (g, arg2734, arg2735);
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

static int test_strings_e_1_skip (void);
static int test_strings_e_1_perform (guestfs_h *);

static int
test_strings_e_1 (guestfs_h *g)
{
  if (test_strings_e_1_skip ()) {
    skipped ("test_strings_e_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_strings_e_1_perform (g);
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
test_strings_e_1_perform (guestfs_h *g)
{
  /* TestResult for strings_e (1) */
  const char *arg2737 = "/strings_e";
  const char *arg2738 = "\0h\0e\0l\0l\0o\0\n\0w\0o\0r\0l\0d\0\n";
  size_t arg2738_size = 24;
  int ret1;
  ret1 = guestfs_write (g, arg2737, arg2738, arg2738_size);
  if (ret1 == -1)
    return -1;
  const char *arg2740 = "b";
  const char *arg2741 = "/strings_e";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings_e (g, arg2740, arg2741);
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

static int test_strings_0_skip (void);
static int test_strings_0_perform (guestfs_h *);

static int
test_strings_0 (guestfs_h *g)
{
  if (test_strings_0_skip ()) {
    skipped ("test_strings_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_strings_0_perform (g);
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
test_strings_0_perform (guestfs_h *g)
{
  /* TestResult for strings (0) */
  const char *arg2743 = "/known-5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings (g, arg2743);
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

static int test_strings_1_skip (void);
static int test_strings_1_perform (guestfs_h *);

static int
test_strings_1 (guestfs_h *g)
{
  if (test_strings_1_skip ()) {
    skipped ("test_strings_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_strings_1_perform (g);
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
test_strings_1_perform (guestfs_h *g)
{
  /* TestResult for strings (1) */
  const char *arg2745 = "/empty";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_strings (g, arg2745);
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

static int test_strings_2_skip (void);
static int test_strings_2_perform (guestfs_h *);

static int
test_strings_2 (guestfs_h *g)
{
  if (test_strings_2_skip ()) {
    skipped ("test_strings_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_strings_2_perform (g);
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
test_strings_2_perform (guestfs_h *g)
{
  /* TestRun for strings (2) */
  const char *arg2748 = "/abssymlink";
  CLEANUP_FREE_STRING_LIST char **ret2747;
  ret2747 = guestfs_strings (g, arg2748);
  if (ret2747 == NULL)
      return -1;
  return 0;
}

static int test_equal_0_skip (void);
static int test_equal_0_perform (guestfs_h *);

static int
test_equal_0 (guestfs_h *g)
{
  if (test_equal_0_skip ()) {
    skipped ("test_equal_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_equal_0_perform (g);
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
test_equal_0_perform (guestfs_h *g)
{
  /* TestResultTrue for equal (0) */
  const char *arg2751 = "/equal";
  int ret2750;
  ret2750 = guestfs_mkdir (g, arg2751);
  if (ret2750 == -1)
    return -1;
  const char *arg2754 = "/equal/file1";
  const char *arg2755 = "contents of a file";
  size_t arg2755_size = 18;
  int ret2753;
  ret2753 = guestfs_write (g, arg2754, arg2755, arg2755_size);
  if (ret2753 == -1)
    return -1;
  const char *arg2758 = "/equal/file1";
  const char *arg2759 = "/equal/file2";
  int ret2757;
  ret2757 = guestfs_cp (g, arg2758, arg2759);
  if (ret2757 == -1)
    return -1;
  const char *arg2761 = "/equal/file1";
  const char *arg2762 = "/equal/file2";
  int ret;
  ret = guestfs_equal (g, arg2761, arg2762);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_equal_0", "equal");
    return -1;
  }
  return 0;
}

static int test_equal_1_skip (void);
static int test_equal_1_perform (guestfs_h *);

static int
test_equal_1 (guestfs_h *g)
{
  if (test_equal_1_skip ()) {
    skipped ("test_equal_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_equal_1_perform (g);
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
test_equal_1_perform (guestfs_h *g)
{
  /* TestResultFalse for equal (1) */
  const char *arg2765 = "/equal2";
  int ret2764;
  ret2764 = guestfs_mkdir (g, arg2765);
  if (ret2764 == -1)
    return -1;
  const char *arg2768 = "/equal2/file1";
  const char *arg2769 = "contents of a file";
  size_t arg2769_size = 18;
  int ret2767;
  ret2767 = guestfs_write (g, arg2768, arg2769, arg2769_size);
  if (ret2767 == -1)
    return -1;
  const char *arg2772 = "/equal2/file2";
  const char *arg2773 = "contents of another file";
  size_t arg2773_size = 24;
  int ret2771;
  ret2771 = guestfs_write (g, arg2772, arg2773, arg2773_size);
  if (ret2771 == -1)
    return -1;
  const char *arg2775 = "/equal2/file1";
  const char *arg2776 = "/equal2/file2";
  int ret;
  ret = guestfs_equal (g, arg2775, arg2776);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_equal_1", "equal");
    return -1;
  }
  return 0;
}

static int test_equal_2_skip (void);
static int test_equal_2_perform (guestfs_h *);

static int
test_equal_2 (guestfs_h *g)
{
  if (test_equal_2_skip ()) {
    skipped ("test_equal_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_equal_2_perform (g);
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
test_equal_2_perform (guestfs_h *g)
{
  /* TestLastFail for equal (2) */
  const char *arg2779 = "/equal3";
  int ret2778;
  ret2778 = guestfs_mkdir (g, arg2779);
  if (ret2778 == -1)
    return -1;
  const char *arg2782 = "/equal3/file1";
  const char *arg2783 = "/equal3/file2";
  int ret2781;
  guestfs_push_error_handler (g, NULL, NULL);
  ret2781 = guestfs_equal (g, arg2782, arg2783);
  guestfs_pop_error_handler (g);
  if (ret2781 != -1)
    return -1;
  return 0;
}

static int test_ping_daemon_0_skip (void);
static int test_ping_daemon_0_perform (guestfs_h *);

static int
test_ping_daemon_0 (guestfs_h *g)
{
  if (test_ping_daemon_0_skip ()) {
    skipped ("test_ping_daemon_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_ping_daemon_0_perform (g);
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
test_ping_daemon_0_perform (guestfs_h *g)
{
  /* TestRun for ping_daemon (0) */
  int ret2785;
  ret2785 = guestfs_ping_daemon (g);
  if (ret2785 == -1)
    return -1;
  return 0;
}

static int test_dmesg_0_skip (void);
static int test_dmesg_0_perform (guestfs_h *);

static int
test_dmesg_0 (guestfs_h *g)
{
  if (test_dmesg_0_skip ()) {
    skipped ("test_dmesg_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_dmesg_0_perform (g);
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
test_dmesg_0_perform (guestfs_h *g)
{
  /* TestRun for dmesg (0) */
  CLEANUP_FREE char *ret2787;
  ret2787 = guestfs_dmesg (g);
  if (ret2787 == NULL)
      return -1;
  return 0;
}

static int test_drop_caches_0_skip (void);
static int test_drop_caches_0_perform (guestfs_h *);

static int
test_drop_caches_0 (guestfs_h *g)
{
  if (test_drop_caches_0_skip ()) {
    skipped ("test_drop_caches_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_drop_caches_0_perform (g);
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
test_drop_caches_0_perform (guestfs_h *g)
{
  /* TestRun for drop_caches (0) */
  int ret2789;
  ret2789 = guestfs_drop_caches (g, 3);
  if (ret2789 == -1)
    return -1;
  return 0;
}

static int test_mv_0_skip (void);
static int test_mv_0_perform (guestfs_h *);

static int
test_mv_0 (guestfs_h *g)
{
  if (test_mv_0_skip ()) {
    skipped ("test_mv_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mv_0_perform (g);
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
test_mv_0_perform (guestfs_h *g)
{
  /* TestResultString for mv (0) */
  const char *arg2793 = "/mv";
  int ret2792;
  ret2792 = guestfs_mkdir (g, arg2793);
  if (ret2792 == -1)
    return -1;
  const char *arg2796 = "/mv/old";
  const char *arg2797 = "file content";
  size_t arg2797_size = 12;
  int ret2795;
  ret2795 = guestfs_write (g, arg2796, arg2797, arg2797_size);
  if (ret2795 == -1)
    return -1;
  const char *arg2800 = "/mv/old";
  const char *arg2801 = "/mv/new";
  int ret2799;
  ret2799 = guestfs_mv (g, arg2800, arg2801);
  if (ret2799 == -1)
    return -1;
  const char *arg2803 = "/mv/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg2803);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "file content")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mv_0", "cat", "file content", ret);
    return -1;
  }
  return 0;
}

static int test_mv_1_skip (void);
static int test_mv_1_perform (guestfs_h *);

static int
test_mv_1 (guestfs_h *g)
{
  if (test_mv_1_skip ()) {
    skipped ("test_mv_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mv_1_perform (g);
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
test_mv_1_perform (guestfs_h *g)
{
  /* TestResultFalse for mv (1) */
  const char *arg2806 = "/mv2";
  int ret2805;
  ret2805 = guestfs_mkdir (g, arg2806);
  if (ret2805 == -1)
    return -1;
  const char *arg2809 = "/mv2/old";
  const char *arg2810 = "file content";
  size_t arg2810_size = 12;
  int ret2808;
  ret2808 = guestfs_write (g, arg2809, arg2810, arg2810_size);
  if (ret2808 == -1)
    return -1;
  const char *arg2813 = "/mv2/old";
  const char *arg2814 = "/mv2/new";
  int ret2812;
  ret2812 = guestfs_mv (g, arg2813, arg2814);
  if (ret2812 == -1)
    return -1;
  const char *arg2816 = "/mv2/old";
  struct guestfs_is_file_opts_argv optargs2817;
  optargs2817.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, arg2816, &optargs2817);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_mv_1", "is_file");
    return -1;
  }
  return 0;
}

static int test_cp_a_0_skip (void);
static int test_cp_a_0_perform (guestfs_h *);

static int
test_cp_a_0 (guestfs_h *g)
{
  if (test_cp_a_0_skip ()) {
    skipped ("test_cp_a_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_cp_a_0_perform (g);
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
test_cp_a_0_perform (guestfs_h *g)
{
  /* TestResultString for cp_a (0) */
  const char *arg2819 = "/cp_a1";
  int ret2818;
  ret2818 = guestfs_mkdir (g, arg2819);
  if (ret2818 == -1)
    return -1;
  const char *arg2822 = "/cp_a2";
  int ret2821;
  ret2821 = guestfs_mkdir (g, arg2822);
  if (ret2821 == -1)
    return -1;
  const char *arg2825 = "/cp_a1/file";
  const char *arg2826 = "file content";
  size_t arg2826_size = 12;
  int ret2824;
  ret2824 = guestfs_write (g, arg2825, arg2826, arg2826_size);
  if (ret2824 == -1)
    return -1;
  const char *arg2829 = "/cp_a1";
  const char *arg2830 = "/cp_a2";
  int ret2828;
  ret2828 = guestfs_cp_a (g, arg2829, arg2830);
  if (ret2828 == -1)
    return -1;
  const char *arg2832 = "/cp_a2/cp_a1/file";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg2832);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "file content")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_cp_a_0", "cat", "file content", ret);
    return -1;
  }
  return 0;
}

static int test_cp_0_skip (void);
static int test_cp_0_perform (guestfs_h *);

static int
test_cp_0 (guestfs_h *g)
{
  if (test_cp_0_skip ()) {
    skipped ("test_cp_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_cp_0_perform (g);
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
test_cp_0_perform (guestfs_h *g)
{
  /* TestResultString for cp (0) */
  const char *arg2835 = "/cp";
  int ret2834;
  ret2834 = guestfs_mkdir (g, arg2835);
  if (ret2834 == -1)
    return -1;
  const char *arg2838 = "/cp/old";
  const char *arg2839 = "file content";
  size_t arg2839_size = 12;
  int ret2837;
  ret2837 = guestfs_write (g, arg2838, arg2839, arg2839_size);
  if (ret2837 == -1)
    return -1;
  const char *arg2842 = "/cp/old";
  const char *arg2843 = "/cp/new";
  int ret2841;
  ret2841 = guestfs_cp (g, arg2842, arg2843);
  if (ret2841 == -1)
    return -1;
  const char *arg2845 = "/cp/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg2845);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "file content")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_cp_0", "cat", "file content", ret);
    return -1;
  }
  return 0;
}

static int test_cp_1_skip (void);
static int test_cp_1_perform (guestfs_h *);

static int
test_cp_1 (guestfs_h *g)
{
  if (test_cp_1_skip ()) {
    skipped ("test_cp_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_cp_1_perform (g);
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
test_cp_1_perform (guestfs_h *g)
{
  /* TestResultTrue for cp (1) */
  const char *arg2848 = "/cp2";
  int ret2847;
  ret2847 = guestfs_mkdir (g, arg2848);
  if (ret2847 == -1)
    return -1;
  const char *arg2851 = "/cp2/old";
  const char *arg2852 = "file content";
  size_t arg2852_size = 12;
  int ret2850;
  ret2850 = guestfs_write (g, arg2851, arg2852, arg2852_size);
  if (ret2850 == -1)
    return -1;
  const char *arg2855 = "/cp2/old";
  const char *arg2856 = "/cp2/new";
  int ret2854;
  ret2854 = guestfs_cp (g, arg2855, arg2856);
  if (ret2854 == -1)
    return -1;
  const char *arg2858 = "/cp2/old";
  struct guestfs_is_file_opts_argv optargs2859;
  optargs2859.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, arg2858, &optargs2859);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_cp_1", "is_file");
    return -1;
  }
  return 0;
}

static int test_cp_2_skip (void);
static int test_cp_2_perform (guestfs_h *);

static int
test_cp_2 (guestfs_h *g)
{
  if (test_cp_2_skip ()) {
    skipped ("test_cp_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_cp_2_perform (g);
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
test_cp_2_perform (guestfs_h *g)
{
  /* TestResultString for cp (2) */
  const char *arg2861 = "/cp3";
  int ret2860;
  ret2860 = guestfs_mkdir (g, arg2861);
  if (ret2860 == -1)
    return -1;
  const char *arg2864 = "/cp3/old";
  const char *arg2865 = "file content";
  size_t arg2865_size = 12;
  int ret2863;
  ret2863 = guestfs_write (g, arg2864, arg2865, arg2865_size);
  if (ret2863 == -1)
    return -1;
  const char *arg2868 = "/cp3/dir";
  int ret2867;
  ret2867 = guestfs_mkdir (g, arg2868);
  if (ret2867 == -1)
    return -1;
  const char *arg2871 = "/cp3/old";
  const char *arg2872 = "/cp3/dir/new";
  int ret2870;
  ret2870 = guestfs_cp (g, arg2871, arg2872);
  if (ret2870 == -1)
    return -1;
  const char *arg2874 = "/cp3/dir/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg2874);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "file content")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_cp_2", "cat", "file content", ret);
    return -1;
  }
  return 0;
}

static int test_grub_install_0_skip (void);
static int test_grub_install_0_perform (guestfs_h *);

static int
test_grub_install_0 (guestfs_h *g)
{
  if (test_grub_install_0_skip ()) {
    skipped ("test_grub_install_0", "environment variable set");
    return 0;
  }

  const char *features2876[] = { "grub", NULL };
  if (!guestfs_feature_available (g, (char **) features2876)) {
    skipped ("test_grub_install_0", "group %s not available in daemon",
             features2876[0]);
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_grub_install_0_perform (g);
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
test_grub_install_0_perform (guestfs_h *g)
{
  /* TestResultTrue for grub_install (0) */
  const char *arg2878 = "/boot/grub";
  int ret2877;
  ret2877 = guestfs_mkdir_p (g, arg2878);
  if (ret2877 == -1)
    return -1;
  const char *arg2881 = "/boot/grub/device.map";
  const char *arg2882 = "(hd0) /dev/sda";
  size_t arg2882_size = 14;
  int ret2880;
  ret2880 = guestfs_write (g, arg2881, arg2882, arg2882_size);
  if (ret2880 == -1)
    return -1;
  const char *arg2885 = "/";
  const char *arg2886 = "/dev/sda";
  int ret2884;
  ret2884 = guestfs_grub_install (g, arg2885, arg2886);
  if (ret2884 == -1)
    return -1;
  const char *arg2888 = "/boot";
  struct guestfs_is_dir_opts_argv optargs2889;
  optargs2889.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, arg2888, &optargs2889);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_grub_install_0", "is_dir");
    return -1;
  }
  return 0;
}

static int test_zero_0_skip (void);
static int test_zero_0_perform (guestfs_h *);

static int
test_zero_0 (guestfs_h *g)
{
  if (test_zero_0_skip ()) {
    skipped ("test_zero_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_zero_0_perform (g);
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
test_zero_0_perform (guestfs_h *g)
{
  /* TestRun for zero (0) */
  const char *arg2891 = "/dev/sda1";
  struct guestfs_umount_opts_argv optargs2892;
  optargs2892.force = 0;
  optargs2892.lazyunmount = 0;
  optargs2892.bitmask = UINT64_C(0x3);
  int ret2890;
  ret2890 = guestfs_umount_opts_argv (g, arg2891, &optargs2892);
  if (ret2890 == -1)
    return -1;
  const char *arg2894 = "/dev/sda1";
  int ret2893;
  ret2893 = guestfs_zero (g, arg2894);
  if (ret2893 == -1)
    return -1;
  return 0;
}

static int test_fsck_0_skip (void);
static int test_fsck_0_perform (guestfs_h *);

static int
test_fsck_0 (guestfs_h *g)
{
  if (test_fsck_0_skip ()) {
    skipped ("test_fsck_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_fsck_0_perform (g);
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
test_fsck_0_perform (guestfs_h *g)
{
  /* TestResult for fsck (0) */
  const char *arg2896 = "/dev/sda1";
  struct guestfs_umount_opts_argv optargs2897;
  optargs2897.force = 0;
  optargs2897.lazyunmount = 0;
  optargs2897.bitmask = UINT64_C(0x3);
  int ret1;
  ret1 = guestfs_umount_opts_argv (g, arg2896, &optargs2897);
  if (ret1 == -1)
    return -1;
  const char *arg2898 = "ext2";
  const char *arg2899 = "/dev/sda1";
  int ret;
  ret = guestfs_fsck (g, arg2898, arg2899);
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

static int test_fsck_1_skip (void);
static int test_fsck_1_perform (guestfs_h *);

static int
test_fsck_1 (guestfs_h *g)
{
  if (test_fsck_1_skip ()) {
    skipped ("test_fsck_1", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_fsck_1_perform (g);
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
test_fsck_1_perform (guestfs_h *g)
{
  /* TestResult for fsck (1) */
  const char *arg2901 = "/dev/sda1";
  struct guestfs_umount_opts_argv optargs2902;
  optargs2902.force = 0;
  optargs2902.lazyunmount = 0;
  optargs2902.bitmask = UINT64_C(0x3);
  int ret2;
  ret2 = guestfs_umount_opts_argv (g, arg2901, &optargs2902);
  if (ret2 == -1)
    return -1;
  const char *arg2903 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_zero (g, arg2903);
  if (ret1 == -1)
    return -1;
  const char *arg2905 = "ext2";
  const char *arg2906 = "/dev/sda1";
  int ret;
  ret = guestfs_fsck (g, arg2905, arg2906);
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

static int test_get_e2uuid_0_skip (void);
static int test_get_e2uuid_0_perform (guestfs_h *);

static int
test_get_e2uuid_0 (guestfs_h *g)
{
  if (test_get_e2uuid_0_skip ()) {
    skipped ("test_get_e2uuid_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_get_e2uuid_0_perform (g);
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
test_get_e2uuid_0_perform (guestfs_h *g)
{
  /* TestResultString for get_e2uuid (0) */
  const char *arg2910 = "/dev/sdc";
  int ret2908;
  ret2908 = guestfs_mke2journal (g, 1024, arg2910);
  if (ret2908 == -1)
    return -1;
  const char *arg2913 = "/dev/sdc";
  const char *arg2914 = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  int ret2912;
  ret2912 = guestfs_set_e2uuid (g, arg2913, arg2914);
  if (ret2912 == -1)
    return -1;
  const char *arg2916 = "/dev/sdc";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, arg2916);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_get_e2uuid_0", "get_e2uuid", "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc", ret);
    return -1;
  }
  return 0;
}

static int test_set_e2uuid_0_skip (void);
static int test_set_e2uuid_0_perform (guestfs_h *);

static int
test_set_e2uuid_0 (guestfs_h *g)
{
  if (test_set_e2uuid_0_skip ()) {
    skipped ("test_set_e2uuid_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_set_e2uuid_0_perform (g);
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
test_set_e2uuid_0_perform (guestfs_h *g)
{
  /* TestResultString for set_e2uuid (0) */
  const char *arg2919 = "/dev/sda1";
  const char *arg2920 = "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc";
  int ret2918;
  ret2918 = guestfs_set_e2uuid (g, arg2919, arg2920);
  if (ret2918 == -1)
    return -1;
  const char *arg2922 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, arg2922);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_e2uuid_0", "get_e2uuid", "01a644cb-af8c-c3b7-9f9b-db8bf094f8dc", ret);
    return -1;
  }
  return 0;
}

static int test_set_e2uuid_1_skip (void);
static int test_set_e2uuid_1_perform (guestfs_h *);

static int
test_set_e2uuid_1 (guestfs_h *g)
{
  if (test_set_e2uuid_1_skip ()) {
    skipped ("test_set_e2uuid_1", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_set_e2uuid_1_perform (g);
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
test_set_e2uuid_1_perform (guestfs_h *g)
{
  /* TestResultString for set_e2uuid (1) */
  const char *arg2925 = "/dev/sda1";
  const char *arg2926 = "clear";
  int ret2924;
  ret2924 = guestfs_set_e2uuid (g, arg2925, arg2926);
  if (ret2924 == -1)
    return -1;
  const char *arg2928 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2uuid (g, arg2928);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_e2uuid_1", "get_e2uuid", "", ret);
    return -1;
  }
  return 0;
}

static int test_set_e2uuid_2_skip (void);
static int test_set_e2uuid_2_perform (guestfs_h *);

static int
test_set_e2uuid_2 (guestfs_h *g)
{
  if (test_set_e2uuid_2_skip ()) {
    skipped ("test_set_e2uuid_2", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_set_e2uuid_2_perform (g);
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
test_set_e2uuid_2_perform (guestfs_h *g)
{
  /* TestRun for set_e2uuid (2) */
  const char *arg2931 = "/dev/sda1";
  const char *arg2932 = "random";
  int ret2930;
  ret2930 = guestfs_set_e2uuid (g, arg2931, arg2932);
  if (ret2930 == -1)
    return -1;
  return 0;
}

static int test_set_e2uuid_3_skip (void);
static int test_set_e2uuid_3_perform (guestfs_h *);

static int
test_set_e2uuid_3 (guestfs_h *g)
{
  if (test_set_e2uuid_3_skip ()) {
    skipped ("test_set_e2uuid_3", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_set_e2uuid_3_perform (g);
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
test_set_e2uuid_3_perform (guestfs_h *g)
{
  /* TestRun for set_e2uuid (3) */
  const char *arg2935 = "/dev/sda1";
  const char *arg2936 = "time";
  int ret2934;
  ret2934 = guestfs_set_e2uuid (g, arg2935, arg2936);
  if (ret2934 == -1)
    return -1;
  return 0;
}

static int test_set_e2label_0_skip (void);
static int test_set_e2label_0_perform (guestfs_h *);

static int
test_set_e2label_0 (guestfs_h *g)
{
  if (test_set_e2label_0_skip ()) {
    skipped ("test_set_e2label_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_set_e2label_0_perform (g);
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
test_set_e2label_0_perform (guestfs_h *g)
{
  /* TestResultString for set_e2label (0) */
  const char *arg2939 = "/dev/sda1";
  const char *arg2940 = "testlabel";
  int ret2938;
  ret2938 = guestfs_set_e2label (g, arg2939, arg2940);
  if (ret2938 == -1)
    return -1;
  const char *arg2942 = "/dev/sda1";
  CLEANUP_FREE char *ret;
  ret = guestfs_get_e2label (g, arg2942);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "testlabel")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_set_e2label_0", "get_e2label", "testlabel", ret);
    return -1;
  }
  return 0;
}

static int test_pvremove_0_skip (void);
static int test_pvremove_0_perform (guestfs_h *);

static int
test_pvremove_0 (guestfs_h *g)
{
  if (test_pvremove_0_skip ()) {
    skipped ("test_pvremove_0", "environment variable set");
    return 0;
  }

  const char *features2944[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features2944)) {
    skipped ("test_pvremove_0", "group %s not available in daemon",
             features2944[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_pvremove_0_perform (g);
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
test_pvremove_0_perform (guestfs_h *g)
{
  /* TestResult for pvremove (0) */
  const char *arg2945 = "/dev/sda";
  const char *arg2946 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, arg2945, arg2946);
  if (ret7 == -1)
    return -1;
  const char *arg2948 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, arg2948);
  if (ret6 == -1)
    return -1;
  const char *arg2950 = "VG";
  const char *arg2951_0 = "/dev/sda1";
  const char *const arg2951[] = {
    arg2951_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, arg2950, (char **) arg2951);
  if (ret5 == -1)
    return -1;
  const char *arg2953 = "LV1";
  const char *arg2954 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, arg2953, arg2954, 50);
  if (ret4 == -1)
    return -1;
  const char *arg2957 = "LV2";
  const char *arg2958 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, arg2957, arg2958, 50);
  if (ret3 == -1)
    return -1;
  const char *arg2961 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, arg2961);
  if (ret2 == -1)
    return -1;
  const char *arg2963 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, arg2963);
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

static int test_pvremove_1_skip (void);
static int test_pvremove_1_perform (guestfs_h *);

static int
test_pvremove_1 (guestfs_h *g)
{
  if (test_pvremove_1_skip ()) {
    skipped ("test_pvremove_1", "environment variable set");
    return 0;
  }

  const char *features2966[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features2966)) {
    skipped ("test_pvremove_1", "group %s not available in daemon",
             features2966[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_pvremove_1_perform (g);
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
test_pvremove_1_perform (guestfs_h *g)
{
  /* TestResult for pvremove (1) */
  const char *arg2967 = "/dev/sda";
  const char *arg2968 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, arg2967, arg2968);
  if (ret7 == -1)
    return -1;
  const char *arg2970 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, arg2970);
  if (ret6 == -1)
    return -1;
  const char *arg2972 = "VG";
  const char *arg2973_0 = "/dev/sda1";
  const char *const arg2973[] = {
    arg2973_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, arg2972, (char **) arg2973);
  if (ret5 == -1)
    return -1;
  const char *arg2975 = "LV1";
  const char *arg2976 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, arg2975, arg2976, 50);
  if (ret4 == -1)
    return -1;
  const char *arg2979 = "LV2";
  const char *arg2980 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, arg2979, arg2980, 50);
  if (ret3 == -1)
    return -1;
  const char *arg2983 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, arg2983);
  if (ret2 == -1)
    return -1;
  const char *arg2985 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, arg2985);
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

static int test_pvremove_2_skip (void);
static int test_pvremove_2_perform (guestfs_h *);

static int
test_pvremove_2 (guestfs_h *g)
{
  if (test_pvremove_2_skip ()) {
    skipped ("test_pvremove_2", "environment variable set");
    return 0;
  }

  const char *features2988[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features2988)) {
    skipped ("test_pvremove_2", "group %s not available in daemon",
             features2988[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_pvremove_2_perform (g);
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
test_pvremove_2_perform (guestfs_h *g)
{
  /* TestResult for pvremove (2) */
  const char *arg2989 = "/dev/sda";
  const char *arg2990 = "mbr";
  int ret7;
  ret7 = guestfs_part_disk (g, arg2989, arg2990);
  if (ret7 == -1)
    return -1;
  const char *arg2992 = "/dev/sda1";
  int ret6;
  ret6 = guestfs_pvcreate (g, arg2992);
  if (ret6 == -1)
    return -1;
  const char *arg2994 = "VG";
  const char *arg2995_0 = "/dev/sda1";
  const char *const arg2995[] = {
    arg2995_0,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, arg2994, (char **) arg2995);
  if (ret5 == -1)
    return -1;
  const char *arg2997 = "LV1";
  const char *arg2998 = "VG";
  int ret4;
  ret4 = guestfs_lvcreate (g, arg2997, arg2998, 50);
  if (ret4 == -1)
    return -1;
  const char *arg3001 = "LV2";
  const char *arg3002 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, arg3001, arg3002, 50);
  if (ret3 == -1)
    return -1;
  const char *arg3005 = "VG";
  int ret2;
  ret2 = guestfs_vgremove (g, arg3005);
  if (ret2 == -1)
    return -1;
  const char *arg3007 = "/dev/sda1";
  int ret1;
  ret1 = guestfs_pvremove (g, arg3007);
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

static int test_vgremove_0_skip (void);
static int test_vgremove_0_perform (guestfs_h *);

static int
test_vgremove_0 (guestfs_h *g)
{
  if (test_vgremove_0_skip ()) {
    skipped ("test_vgremove_0", "environment variable set");
    return 0;
  }

  const char *features3010[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features3010)) {
    skipped ("test_vgremove_0", "group %s not available in daemon",
             features3010[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_vgremove_0_perform (g);
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
test_vgremove_0_perform (guestfs_h *g)
{
  /* TestResult for vgremove (0) */
  const char *arg3011 = "/dev/sda";
  const char *arg3012 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, arg3011, arg3012);
  if (ret6 == -1)
    return -1;
  const char *arg3014 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, arg3014);
  if (ret5 == -1)
    return -1;
  const char *arg3016 = "VG";
  const char *arg3017_0 = "/dev/sda1";
  const char *const arg3017[] = {
    arg3017_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, arg3016, (char **) arg3017);
  if (ret4 == -1)
    return -1;
  const char *arg3019 = "LV1";
  const char *arg3020 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, arg3019, arg3020, 50);
  if (ret3 == -1)
    return -1;
  const char *arg3023 = "LV2";
  const char *arg3024 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, arg3023, arg3024, 50);
  if (ret2 == -1)
    return -1;
  const char *arg3027 = "VG";
  int ret1;
  ret1 = guestfs_vgremove (g, arg3027);
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

static int test_vgremove_1_skip (void);
static int test_vgremove_1_perform (guestfs_h *);

static int
test_vgremove_1 (guestfs_h *g)
{
  if (test_vgremove_1_skip ()) {
    skipped ("test_vgremove_1", "environment variable set");
    return 0;
  }

  const char *features3030[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features3030)) {
    skipped ("test_vgremove_1", "group %s not available in daemon",
             features3030[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_vgremove_1_perform (g);
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
test_vgremove_1_perform (guestfs_h *g)
{
  /* TestResult for vgremove (1) */
  const char *arg3031 = "/dev/sda";
  const char *arg3032 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, arg3031, arg3032);
  if (ret6 == -1)
    return -1;
  const char *arg3034 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, arg3034);
  if (ret5 == -1)
    return -1;
  const char *arg3036 = "VG";
  const char *arg3037_0 = "/dev/sda1";
  const char *const arg3037[] = {
    arg3037_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, arg3036, (char **) arg3037);
  if (ret4 == -1)
    return -1;
  const char *arg3039 = "LV1";
  const char *arg3040 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, arg3039, arg3040, 50);
  if (ret3 == -1)
    return -1;
  const char *arg3043 = "LV2";
  const char *arg3044 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, arg3043, arg3044, 50);
  if (ret2 == -1)
    return -1;
  const char *arg3047 = "VG";
  int ret1;
  ret1 = guestfs_vgremove (g, arg3047);
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

static int test_lvremove_0_skip (void);
static int test_lvremove_0_perform (guestfs_h *);

static int
test_lvremove_0 (guestfs_h *g)
{
  if (test_lvremove_0_skip ()) {
    skipped ("test_lvremove_0", "environment variable set");
    return 0;
  }

  const char *features3050[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features3050)) {
    skipped ("test_lvremove_0", "group %s not available in daemon",
             features3050[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_lvremove_0_perform (g);
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
test_lvremove_0_perform (guestfs_h *g)
{
  /* TestResult for lvremove (0) */
  const char *arg3051 = "/dev/sda";
  const char *arg3052 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, arg3051, arg3052);
  if (ret6 == -1)
    return -1;
  const char *arg3054 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, arg3054);
  if (ret5 == -1)
    return -1;
  const char *arg3056 = "VG";
  const char *arg3057_0 = "/dev/sda1";
  const char *const arg3057[] = {
    arg3057_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, arg3056, (char **) arg3057);
  if (ret4 == -1)
    return -1;
  const char *arg3059 = "LV1";
  const char *arg3060 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, arg3059, arg3060, 50);
  if (ret3 == -1)
    return -1;
  const char *arg3063 = "LV2";
  const char *arg3064 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, arg3063, arg3064, 50);
  if (ret2 == -1)
    return -1;
  const char *arg3067 = "/dev/VG/LV1";
  int ret1;
  ret1 = guestfs_lvremove (g, arg3067);
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

static int test_lvremove_1_skip (void);
static int test_lvremove_1_perform (guestfs_h *);

static int
test_lvremove_1 (guestfs_h *g)
{
  if (test_lvremove_1_skip ()) {
    skipped ("test_lvremove_1", "environment variable set");
    return 0;
  }

  const char *features3070[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features3070)) {
    skipped ("test_lvremove_1", "group %s not available in daemon",
             features3070[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_lvremove_1_perform (g);
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
test_lvremove_1_perform (guestfs_h *g)
{
  /* TestResult for lvremove (1) */
  const char *arg3071 = "/dev/sda";
  const char *arg3072 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, arg3071, arg3072);
  if (ret6 == -1)
    return -1;
  const char *arg3074 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, arg3074);
  if (ret5 == -1)
    return -1;
  const char *arg3076 = "VG";
  const char *arg3077_0 = "/dev/sda1";
  const char *const arg3077[] = {
    arg3077_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, arg3076, (char **) arg3077);
  if (ret4 == -1)
    return -1;
  const char *arg3079 = "LV1";
  const char *arg3080 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, arg3079, arg3080, 50);
  if (ret3 == -1)
    return -1;
  const char *arg3083 = "LV2";
  const char *arg3084 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, arg3083, arg3084, 50);
  if (ret2 == -1)
    return -1;
  const char *arg3087 = "/dev/VG";
  int ret1;
  ret1 = guestfs_lvremove (g, arg3087);
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

static int test_lvremove_2_skip (void);
static int test_lvremove_2_perform (guestfs_h *);

static int
test_lvremove_2 (guestfs_h *g)
{
  if (test_lvremove_2_skip ()) {
    skipped ("test_lvremove_2", "environment variable set");
    return 0;
  }

  const char *features3090[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features3090)) {
    skipped ("test_lvremove_2", "group %s not available in daemon",
             features3090[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_lvremove_2_perform (g);
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
test_lvremove_2_perform (guestfs_h *g)
{
  /* TestResult for lvremove (2) */
  const char *arg3091 = "/dev/sda";
  const char *arg3092 = "mbr";
  int ret6;
  ret6 = guestfs_part_disk (g, arg3091, arg3092);
  if (ret6 == -1)
    return -1;
  const char *arg3094 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, arg3094);
  if (ret5 == -1)
    return -1;
  const char *arg3096 = "VG";
  const char *arg3097_0 = "/dev/sda1";
  const char *const arg3097[] = {
    arg3097_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, arg3096, (char **) arg3097);
  if (ret4 == -1)
    return -1;
  const char *arg3099 = "LV1";
  const char *arg3100 = "VG";
  int ret3;
  ret3 = guestfs_lvcreate (g, arg3099, arg3100, 50);
  if (ret3 == -1)
    return -1;
  const char *arg3103 = "LV2";
  const char *arg3104 = "VG";
  int ret2;
  ret2 = guestfs_lvcreate (g, arg3103, arg3104, 50);
  if (ret2 == -1)
    return -1;
  const char *arg3107 = "/dev/VG";
  int ret1;
  ret1 = guestfs_lvremove (g, arg3107);
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

static int test_mount_ro_0_skip (void);
static int test_mount_ro_0_perform (guestfs_h *);

static int
test_mount_ro_0 (guestfs_h *g)
{
  if (test_mount_ro_0_skip ()) {
    skipped ("test_mount_ro_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_mount_ro_0_perform (g);
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
test_mount_ro_0_perform (guestfs_h *g)
{
  /* TestLastFail for mount_ro (0) */
  const char *arg3111 = "/";
  struct guestfs_umount_opts_argv optargs3112;
  optargs3112.force = 0;
  optargs3112.lazyunmount = 0;
  optargs3112.bitmask = UINT64_C(0x3);
  int ret3110;
  ret3110 = guestfs_umount_opts_argv (g, arg3111, &optargs3112);
  if (ret3110 == -1)
    return -1;
  const char *arg3114 = "/dev/sda1";
  const char *arg3115 = "/";
  int ret3113;
  ret3113 = guestfs_mount_ro (g, arg3114, arg3115);
  if (ret3113 == -1)
    return -1;
  const char *arg3118 = "/new";
  int ret3117;
  guestfs_push_error_handler (g, NULL, NULL);
  ret3117 = guestfs_touch (g, arg3118);
  guestfs_pop_error_handler (g);
  if (ret3117 != -1)
    return -1;
  return 0;
}

static int test_mount_ro_1_skip (void);
static int test_mount_ro_1_perform (guestfs_h *);

static int
test_mount_ro_1 (guestfs_h *g)
{
  if (test_mount_ro_1_skip ()) {
    skipped ("test_mount_ro_1", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_mount_ro_1_perform (g);
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
test_mount_ro_1_perform (guestfs_h *g)
{
  /* TestResultString for mount_ro (1) */
  const char *arg3121 = "/new";
  const char *arg3122 = "data";
  size_t arg3122_size = 4;
  int ret3120;
  ret3120 = guestfs_write (g, arg3121, arg3122, arg3122_size);
  if (ret3120 == -1)
    return -1;
  const char *arg3125 = "/";
  struct guestfs_umount_opts_argv optargs3126;
  optargs3126.force = 0;
  optargs3126.lazyunmount = 0;
  optargs3126.bitmask = UINT64_C(0x3);
  int ret3124;
  ret3124 = guestfs_umount_opts_argv (g, arg3125, &optargs3126);
  if (ret3124 == -1)
    return -1;
  const char *arg3128 = "/dev/sda1";
  const char *arg3129 = "/";
  int ret3127;
  ret3127 = guestfs_mount_ro (g, arg3128, arg3129);
  if (ret3127 == -1)
    return -1;
  const char *arg3131 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg3131);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "data")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mount_ro_1", "cat", "data", ret);
    return -1;
  }
  return 0;
}

static int test_tgz_in_0_skip (void);
static int test_tgz_in_0_perform (guestfs_h *);

static int
test_tgz_in_0 (guestfs_h *g)
{
  if (test_tgz_in_0_skip ()) {
    skipped ("test_tgz_in_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_tgz_in_0_perform (g);
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
test_tgz_in_0_perform (guestfs_h *g)
{
  /* TestResultString for tgz_in (0) */
  const char *arg3134 = "/tgz_in";
  int ret3133;
  ret3133 = guestfs_mkdir (g, arg3134);
  if (ret3133 == -1)
    return -1;
  CLEANUP_FREE char *arg3137 = substitute_srcdir ("$srcdir/../../test-data/files/helloworld.tar.gz");
  const char *arg3138 = "/tgz_in";
  int ret3136;
  ret3136 = guestfs_tgz_in (g, arg3137, arg3138);
  if (ret3136 == -1)
    return -1;
  const char *arg3140 = "/tgz_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg3140);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "hello\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_tgz_in_0", "cat", "hello\n", ret);
    return -1;
  }
  return 0;
}

static int test_tar_in_0_skip (void);
static int test_tar_in_0_perform (guestfs_h *);

static int
test_tar_in_0 (guestfs_h *g)
{
  if (test_tar_in_0_skip ()) {
    skipped ("test_tar_in_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_tar_in_0_perform (g);
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
test_tar_in_0_perform (guestfs_h *g)
{
  /* TestResultString for tar_in (0) */
  const char *arg3143 = "/tar_in";
  int ret3142;
  ret3142 = guestfs_mkdir (g, arg3143);
  if (ret3142 == -1)
    return -1;
  CLEANUP_FREE char *arg3146 = substitute_srcdir ("$srcdir/../../test-data/files/helloworld.tar");
  const char *arg3147 = "/tar_in";
  struct guestfs_tar_in_opts_argv optargs3148;
  optargs3148.bitmask = UINT64_C(0x0);
  int ret3145;
  ret3145 = guestfs_tar_in_opts_argv (g, arg3146, arg3147, &optargs3148);
  if (ret3145 == -1)
    return -1;
  const char *arg3149 = "/tar_in/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg3149);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "hello\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_tar_in_0", "cat", "hello\n", ret);
    return -1;
  }
  return 0;
}

static int test_tar_in_1_skip (void);
static int test_tar_in_1_perform (guestfs_h *);

static int
test_tar_in_1 (guestfs_h *g)
{
  if (test_tar_in_1_skip ()) {
    skipped ("test_tar_in_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_tar_in_1_perform (g);
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
test_tar_in_1_perform (guestfs_h *g)
{
  /* TestResultString for tar_in (1) */
  const char *arg3152 = "/tar_in_gz";
  int ret3151;
  ret3151 = guestfs_mkdir (g, arg3152);
  if (ret3151 == -1)
    return -1;
  CLEANUP_FREE char *arg3155 = substitute_srcdir ("$srcdir/../../test-data/files/helloworld.tar.gz");
  const char *arg3156 = "/tar_in_gz";
  struct guestfs_tar_in_opts_argv optargs3157;
  optargs3157.compress = "gzip";
  optargs3157.bitmask = UINT64_C(0x1);
  int ret3154;
  ret3154 = guestfs_tar_in_opts_argv (g, arg3155, arg3156, &optargs3157);
  if (ret3154 == -1)
    return -1;
  const char *arg3158 = "/tar_in_gz/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg3158);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "hello\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_tar_in_1", "cat", "hello\n", ret);
    return -1;
  }
  return 0;
}

static int test_tar_in_2_skip (void);
static int test_tar_in_2_perform (guestfs_h *);

static int
test_tar_in_2 (guestfs_h *g)
{
  if (test_tar_in_2_skip ()) {
    skipped ("test_tar_in_2", "environment variable set");
    return 0;
  }

  const char *features3160[] = { "xz", NULL };
  if (!guestfs_feature_available (g, (char **) features3160)) {
    skipped ("test_tar_in_2", "group %s not available in daemon",
             features3160[0]);
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_tar_in_2_perform (g);
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
test_tar_in_2_perform (guestfs_h *g)
{
  /* TestResultString for tar_in (2) */
  const char *arg3162 = "/tar_in_xz";
  int ret3161;
  ret3161 = guestfs_mkdir (g, arg3162);
  if (ret3161 == -1)
    return -1;
  CLEANUP_FREE char *arg3165 = substitute_srcdir ("$srcdir/../../test-data/files/helloworld.tar.xz");
  const char *arg3166 = "/tar_in_xz";
  struct guestfs_tar_in_opts_argv optargs3167;
  optargs3167.compress = "xz";
  optargs3167.bitmask = UINT64_C(0x1);
  int ret3164;
  ret3164 = guestfs_tar_in_opts_argv (g, arg3165, arg3166, &optargs3167);
  if (ret3164 == -1)
    return -1;
  const char *arg3168 = "/tar_in_xz/hello";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg3168);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "hello\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_tar_in_2", "cat", "hello\n", ret);
    return -1;
  }
  return 0;
}

static int test_checksum_0_skip (void);
static int test_checksum_0_perform (guestfs_h *);

static int
test_checksum_0 (guestfs_h *g)
{
  if (test_checksum_0_skip ()) {
    skipped ("test_checksum_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_checksum_0_perform (g);
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
test_checksum_0_perform (guestfs_h *g)
{
  /* TestResultString for checksum (0) */
  const char *arg3170 = "crc";
  const char *arg3171 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, arg3170, arg3171);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "2891671662")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_0", "checksum", "2891671662", ret);
    return -1;
  }
  return 0;
}

static int test_checksum_1_skip (void);
static int test_checksum_1_perform (guestfs_h *);

static int
test_checksum_1 (guestfs_h *g)
{
  if (test_checksum_1_skip ()) {
    skipped ("test_checksum_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_checksum_1_perform (g);
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
test_checksum_1_perform (guestfs_h *g)
{
  /* TestLastFail for checksum (1) */
  const char *arg3174 = "crc";
  const char *arg3175 = "/notexists";
  CLEANUP_FREE char *ret3173;
  guestfs_push_error_handler (g, NULL, NULL);
  ret3173 = guestfs_checksum (g, arg3174, arg3175);
  guestfs_pop_error_handler (g);
  if (ret3173 != NULL)
    return -1;
  return 0;
}

static int test_checksum_2_skip (void);
static int test_checksum_2_perform (guestfs_h *);

static int
test_checksum_2 (guestfs_h *g)
{
  if (test_checksum_2_skip ()) {
    skipped ("test_checksum_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_checksum_2_perform (g);
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
test_checksum_2_perform (guestfs_h *g)
{
  /* TestResultString for checksum (2) */
  const char *arg3177 = "md5";
  const char *arg3178 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, arg3177, arg3178);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "46d6ca27ee07cdc6fa99c2e138cc522c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_2", "checksum", "46d6ca27ee07cdc6fa99c2e138cc522c", ret);
    return -1;
  }
  return 0;
}

static int test_checksum_3_skip (void);
static int test_checksum_3_perform (guestfs_h *);

static int
test_checksum_3 (guestfs_h *g)
{
  if (test_checksum_3_skip ()) {
    skipped ("test_checksum_3", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_checksum_3_perform (g);
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
test_checksum_3_perform (guestfs_h *g)
{
  /* TestResultString for checksum (3) */
  const char *arg3180 = "sha1";
  const char *arg3181 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, arg3180, arg3181);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "b7ebccc3ee418311091c3eda0a45b83c0a770f15")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_3", "checksum", "b7ebccc3ee418311091c3eda0a45b83c0a770f15", ret);
    return -1;
  }
  return 0;
}

static int test_checksum_4_skip (void);
static int test_checksum_4_perform (guestfs_h *);

static int
test_checksum_4 (guestfs_h *g)
{
  if (test_checksum_4_skip ()) {
    skipped ("test_checksum_4", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_checksum_4_perform (g);
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
test_checksum_4_perform (guestfs_h *g)
{
  /* TestResultString for checksum (4) */
  const char *arg3183 = "sha224";
  const char *arg3184 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, arg3183, arg3184);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "d2cd1774b28f3659c14116be0a6dc2bb5c4b350ce9cd5defac707741")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_4", "checksum", "d2cd1774b28f3659c14116be0a6dc2bb5c4b350ce9cd5defac707741", ret);
    return -1;
  }
  return 0;
}

static int test_checksum_5_skip (void);
static int test_checksum_5_perform (guestfs_h *);

static int
test_checksum_5 (guestfs_h *g)
{
  if (test_checksum_5_skip ()) {
    skipped ("test_checksum_5", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_checksum_5_perform (g);
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
test_checksum_5_perform (guestfs_h *g)
{
  /* TestResultString for checksum (5) */
  const char *arg3186 = "sha256";
  const char *arg3187 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, arg3186, arg3187);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "75bb71b90cd20cb13f86d2bea8dad63ac7194e7517c3b52b8d06ff52d3487d30")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_5", "checksum", "75bb71b90cd20cb13f86d2bea8dad63ac7194e7517c3b52b8d06ff52d3487d30", ret);
    return -1;
  }
  return 0;
}

static int test_checksum_6_skip (void);
static int test_checksum_6_perform (guestfs_h *);

static int
test_checksum_6 (guestfs_h *g)
{
  if (test_checksum_6_skip ()) {
    skipped ("test_checksum_6", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_checksum_6_perform (g);
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
test_checksum_6_perform (guestfs_h *g)
{
  /* TestResultString for checksum (6) */
  const char *arg3189 = "sha384";
  const char *arg3190 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, arg3189, arg3190);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "5fa7883430f357b5d7b7271d3a1d2872b51d73cba72731de6863d3dea55f30646af2799bef44d5ea776a5ec7941ac640")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_6", "checksum", "5fa7883430f357b5d7b7271d3a1d2872b51d73cba72731de6863d3dea55f30646af2799bef44d5ea776a5ec7941ac640", ret);
    return -1;
  }
  return 0;
}

static int test_checksum_7_skip (void);
static int test_checksum_7_perform (guestfs_h *);

static int
test_checksum_7 (guestfs_h *g)
{
  if (test_checksum_7_skip ()) {
    skipped ("test_checksum_7", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_checksum_7_perform (g);
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
test_checksum_7_perform (guestfs_h *g)
{
  /* TestResultString for checksum (7) */
  const char *arg3192 = "sha512";
  const char *arg3193 = "/known-3";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, arg3192, arg3193);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "2794062c328c6b216dca90443b7f7134c5f40e56bd0ed7853123275a09982a6f992e6ca682f9d2fba34a4c5e870d8fe077694ff831e3032a004ee077e00603f6")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_7", "checksum", "2794062c328c6b216dca90443b7f7134c5f40e56bd0ed7853123275a09982a6f992e6ca682f9d2fba34a4c5e870d8fe077694ff831e3032a004ee077e00603f6", ret);
    return -1;
  }
  return 0;
}

static int test_checksum_8_skip (void);
static int test_checksum_8_perform (guestfs_h *);

static int
test_checksum_8 (guestfs_h *g)
{
  if (test_checksum_8_skip ()) {
    skipped ("test_checksum_8", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_checksum_8_perform (g);
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
test_checksum_8_perform (guestfs_h *g)
{
  /* TestResultString for checksum (8) */
  const char *arg3195 = "sha512";
  const char *arg3196 = "/abssymlink";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, arg3195, arg3196);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "5f57d0639bc95081c53afc63a449403883818edc64da48930ad6b1a4fb49be90404686877743fbcd7c99811f3def7df7bc22635c885c6a8cf79c806b43451c1a")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_checksum_8", "checksum", "5f57d0639bc95081c53afc63a449403883818edc64da48930ad6b1a4fb49be90404686877743fbcd7c99811f3def7df7bc22635c885c6a8cf79c806b43451c1a", ret);
    return -1;
  }
  return 0;
}

static int test_download_0_skip (void);
static int test_download_0_perform (guestfs_h *);

static int
test_download_0 (guestfs_h *g)
{
  if (test_download_0_skip ()) {
    skipped ("test_download_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_download_0_perform (g);
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
test_download_0_perform (guestfs_h *g)
{
  /* TestResultString for download (0) */
  const char *arg3199 = "/download";
  int ret3198;
  ret3198 = guestfs_mkdir (g, arg3199);
  if (ret3198 == -1)
    return -1;
  CLEANUP_FREE char *arg3202 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *arg3203 = "/download/COPYING.LIB";
  int ret3201;
  ret3201 = guestfs_upload (g, arg3202, arg3203);
  if (ret3201 == -1)
    return -1;
  const char *arg3206 = "/download/COPYING.LIB";
  int ret3205;
  ret3205 = guestfs_download (g, arg3206, "testdownload.tmp");
  if (ret3205 == -1)
    return -1;
  CLEANUP_FREE char *arg3210 = substitute_srcdir ("testdownload.tmp");
  const char *arg3211 = "/download/upload";
  int ret3209;
  ret3209 = guestfs_upload (g, arg3210, arg3211);
  if (ret3209 == -1)
    return -1;
  const char *arg3213 = "md5";
  const char *arg3214 = "/download/upload";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, arg3213, arg3214);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "4fbd65380cdd255951079008b364516c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_download_0", "checksum", "4fbd65380cdd255951079008b364516c", ret);
    return -1;
  }
  return 0;
}

static int test_upload_0_skip (void);
static int test_upload_0_perform (guestfs_h *);

static int
test_upload_0 (guestfs_h *g)
{
  if (test_upload_0_skip ()) {
    skipped ("test_upload_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_upload_0_perform (g);
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
test_upload_0_perform (guestfs_h *g)
{
  /* TestResultString for upload (0) */
  const char *arg3217 = "/upload";
  int ret3216;
  ret3216 = guestfs_mkdir (g, arg3217);
  if (ret3216 == -1)
    return -1;
  CLEANUP_FREE char *arg3220 = substitute_srcdir ("$srcdir/../../COPYING.LIB");
  const char *arg3221 = "/upload/COPYING.LIB";
  int ret3219;
  ret3219 = guestfs_upload (g, arg3220, arg3221);
  if (ret3219 == -1)
    return -1;
  const char *arg3223 = "md5";
  const char *arg3224 = "/upload/COPYING.LIB";
  CLEANUP_FREE char *ret;
  ret = guestfs_checksum (g, arg3223, arg3224);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "4fbd65380cdd255951079008b364516c")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_upload_0", "checksum", "4fbd65380cdd255951079008b364516c", ret);
    return -1;
  }
  return 0;
}

static int test_blockdev_rereadpt_0_skip (void);
static int test_blockdev_rereadpt_0_perform (guestfs_h *);

static int
test_blockdev_rereadpt_0 (guestfs_h *g)
{
  if (test_blockdev_rereadpt_0_skip ()) {
    skipped ("test_blockdev_rereadpt_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_blockdev_rereadpt_0_perform (g);
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
test_blockdev_rereadpt_0_perform (guestfs_h *g)
{
  /* TestRun for blockdev_rereadpt (0) */
  const char *arg3227 = "/dev/sda";
  int ret3226;
  ret3226 = guestfs_blockdev_rereadpt (g, arg3227);
  if (ret3226 == -1)
    return -1;
  return 0;
}

static int test_blockdev_flushbufs_0_skip (void);
static int test_blockdev_flushbufs_0_perform (guestfs_h *);

static int
test_blockdev_flushbufs_0 (guestfs_h *g)
{
  if (test_blockdev_flushbufs_0_skip ()) {
    skipped ("test_blockdev_flushbufs_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_blockdev_flushbufs_0_perform (g);
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
test_blockdev_flushbufs_0_perform (guestfs_h *g)
{
  /* TestRun for blockdev_flushbufs (0) */
  const char *arg3230 = "/dev/sda";
  int ret3229;
  ret3229 = guestfs_blockdev_flushbufs (g, arg3230);
  if (ret3229 == -1)
    return -1;
  return 0;
}

static int test_blockdev_getsize64_0_skip (void);
static int test_blockdev_getsize64_0_perform (guestfs_h *);

static int
test_blockdev_getsize64_0 (guestfs_h *g)
{
  if (test_blockdev_getsize64_0_skip ()) {
    skipped ("test_blockdev_getsize64_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_blockdev_getsize64_0_perform (g);
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
test_blockdev_getsize64_0_perform (guestfs_h *g)
{
  /* TestResult for blockdev_getsize64 (0) */
  const char *arg3232 = "/dev/sda";
  int64_t ret;
  ret = guestfs_blockdev_getsize64 (g, arg3232);
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

static int test_blockdev_getsz_0_skip (void);
static int test_blockdev_getsz_0_perform (guestfs_h *);

static int
test_blockdev_getsz_0 (guestfs_h *g)
{
  if (test_blockdev_getsz_0_skip ()) {
    skipped ("test_blockdev_getsz_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_blockdev_getsz_0_perform (g);
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
test_blockdev_getsz_0_perform (guestfs_h *g)
{
  /* TestResult for blockdev_getsz (0) */
  const char *arg3234 = "/dev/sda";
  int64_t ret;
  ret = guestfs_blockdev_getsz (g, arg3234);
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

static int test_blockdev_getss_0_skip (void);
static int test_blockdev_getss_0_perform (guestfs_h *);

static int
test_blockdev_getss_0 (guestfs_h *g)
{
  if (test_blockdev_getss_0_skip ()) {
    skipped ("test_blockdev_getss_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_blockdev_getss_0_perform (g);
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
test_blockdev_getss_0_perform (guestfs_h *g)
{
  /* TestResult for blockdev_getss (0) */
  const char *arg3236 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getss (g, arg3236);
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

static int test_blockdev_getro_0_skip (void);
static int test_blockdev_getro_0_perform (guestfs_h *);

static int
test_blockdev_getro_0 (guestfs_h *g)
{
  if (test_blockdev_getro_0_skip ()) {
    skipped ("test_blockdev_getro_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_blockdev_getro_0_perform (g);
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
test_blockdev_getro_0_perform (guestfs_h *g)
{
  /* TestResultTrue for blockdev_getro (0) */
  const char *arg3239 = "/dev/sda";
  int ret3238;
  ret3238 = guestfs_blockdev_setro (g, arg3239);
  if (ret3238 == -1)
    return -1;
  const char *arg3241 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, arg3241);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_blockdev_getro_0", "blockdev_getro");
    return -1;
  }
  return 0;
}

static int test_blockdev_setrw_0_skip (void);
static int test_blockdev_setrw_0_perform (guestfs_h *);

static int
test_blockdev_setrw_0 (guestfs_h *g)
{
  if (test_blockdev_setrw_0_skip ()) {
    skipped ("test_blockdev_setrw_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_blockdev_setrw_0_perform (g);
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
test_blockdev_setrw_0_perform (guestfs_h *g)
{
  /* TestResultFalse for blockdev_setrw (0) */
  const char *arg3244 = "/dev/sda";
  int ret3243;
  ret3243 = guestfs_blockdev_setrw (g, arg3244);
  if (ret3243 == -1)
    return -1;
  const char *arg3246 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, arg3246);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_blockdev_setrw_0", "blockdev_getro");
    return -1;
  }
  return 0;
}

static int test_blockdev_setro_0_skip (void);
static int test_blockdev_setro_0_perform (guestfs_h *);

static int
test_blockdev_setro_0 (guestfs_h *g)
{
  if (test_blockdev_setro_0_skip ()) {
    skipped ("test_blockdev_setro_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_blockdev_setro_0_perform (g);
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
test_blockdev_setro_0_perform (guestfs_h *g)
{
  /* TestResultTrue for blockdev_setro (0) */
  const char *arg3249 = "/dev/sda";
  int ret3248;
  ret3248 = guestfs_blockdev_setro (g, arg3249);
  if (ret3248 == -1)
    return -1;
  const char *arg3251 = "/dev/sda";
  int ret;
  ret = guestfs_blockdev_getro (g, arg3251);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_blockdev_setro_0", "blockdev_getro");
    return -1;
  }
  return 0;
}

static int test_tune2fs_l_0_skip (void);
static int test_tune2fs_l_0_perform (guestfs_h *);

static int
test_tune2fs_l_0 (guestfs_h *g)
{
  if (test_tune2fs_l_0_skip ()) {
    skipped ("test_tune2fs_l_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_tune2fs_l_0_perform (g);
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
test_tune2fs_l_0_perform (guestfs_h *g)
{
  /* TestResult for tune2fs_l (0) */
  const char *arg3253 = "/dev/sdb1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_tune2fs_l (g, arg3253);
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

static int test_statvfs_0_skip (void);
static int test_statvfs_0_perform (guestfs_h *);

static int
test_statvfs_0 (guestfs_h *g)
{
  if (test_statvfs_0_skip ()) {
    skipped ("test_statvfs_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_statvfs_0_perform (g);
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
test_statvfs_0_perform (guestfs_h *g)
{
  /* TestResult for statvfs (0) */
  const char *arg3255 = "/";
  CLEANUP_FREE_STATVFS struct guestfs_statvfs *ret;
  ret = guestfs_statvfs (g, arg3255);
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

static int test_command_lines_0_skip (void);
static int test_command_lines_0_perform (guestfs_h *);

static int
test_command_lines_0 (guestfs_h *g)
{
  if (test_command_lines_0_skip ()) {
    skipped ("test_command_lines_0", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_lines_0", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_lines_0_perform (g);
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
test_command_lines_0_perform (guestfs_h *g)
{
  /* TestResult for command_lines (0) */
  const char *arg3257 = "/command_lines";
  int ret3;
  ret3 = guestfs_mkdir (g, arg3257);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *arg3259 = substitute_srcdir ("test-command");
  const char *arg3260 = "/command_lines/test-command";
  int ret2;
  ret2 = guestfs_upload (g, arg3259, arg3260);
  if (ret2 == -1)
    return -1;
  const char *arg3263 = "/command_lines/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, arg3263);
  if (ret1 == -1)
    return -1;
  const char *arg3265_0 = "/command_lines/test-command";
  const char *arg3265_1 = "1";
  const char *const arg3265[] = {
    arg3265_0,
    arg3265_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) arg3265);
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

static int test_command_lines_1_skip (void);
static int test_command_lines_1_perform (guestfs_h *);

static int
test_command_lines_1 (guestfs_h *g)
{
  if (test_command_lines_1_skip ()) {
    skipped ("test_command_lines_1", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_lines_1", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_lines_1_perform (g);
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
test_command_lines_1_perform (guestfs_h *g)
{
  /* TestResult for command_lines (1) */
  const char *arg3267 = "/command_lines2";
  int ret3;
  ret3 = guestfs_mkdir (g, arg3267);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *arg3269 = substitute_srcdir ("test-command");
  const char *arg3270 = "/command_lines2/test-command";
  int ret2;
  ret2 = guestfs_upload (g, arg3269, arg3270);
  if (ret2 == -1)
    return -1;
  const char *arg3273 = "/command_lines2/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, arg3273);
  if (ret1 == -1)
    return -1;
  const char *arg3275_0 = "/command_lines2/test-command";
  const char *arg3275_1 = "2";
  const char *const arg3275[] = {
    arg3275_0,
    arg3275_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) arg3275);
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

static int test_command_lines_2_skip (void);
static int test_command_lines_2_perform (guestfs_h *);

static int
test_command_lines_2 (guestfs_h *g)
{
  if (test_command_lines_2_skip ()) {
    skipped ("test_command_lines_2", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_lines_2", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_lines_2_perform (g);
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
test_command_lines_2_perform (guestfs_h *g)
{
  /* TestResult for command_lines (2) */
  const char *arg3277 = "/command_lines3";
  int ret3;
  ret3 = guestfs_mkdir (g, arg3277);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *arg3279 = substitute_srcdir ("test-command");
  const char *arg3280 = "/command_lines3/test-command";
  int ret2;
  ret2 = guestfs_upload (g, arg3279, arg3280);
  if (ret2 == -1)
    return -1;
  const char *arg3283 = "/command_lines3/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, arg3283);
  if (ret1 == -1)
    return -1;
  const char *arg3285_0 = "/command_lines3/test-command";
  const char *arg3285_1 = "3";
  const char *const arg3285[] = {
    arg3285_0,
    arg3285_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) arg3285);
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

static int test_command_lines_3_skip (void);
static int test_command_lines_3_perform (guestfs_h *);

static int
test_command_lines_3 (guestfs_h *g)
{
  if (test_command_lines_3_skip ()) {
    skipped ("test_command_lines_3", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_lines_3", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_lines_3_perform (g);
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
test_command_lines_3_perform (guestfs_h *g)
{
  /* TestResult for command_lines (3) */
  const char *arg3287 = "/command_lines4";
  int ret3;
  ret3 = guestfs_mkdir (g, arg3287);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *arg3289 = substitute_srcdir ("test-command");
  const char *arg3290 = "/command_lines4/test-command";
  int ret2;
  ret2 = guestfs_upload (g, arg3289, arg3290);
  if (ret2 == -1)
    return -1;
  const char *arg3293 = "/command_lines4/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, arg3293);
  if (ret1 == -1)
    return -1;
  const char *arg3295_0 = "/command_lines4/test-command";
  const char *arg3295_1 = "4";
  const char *const arg3295[] = {
    arg3295_0,
    arg3295_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) arg3295);
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

static int test_command_lines_4_skip (void);
static int test_command_lines_4_perform (guestfs_h *);

static int
test_command_lines_4 (guestfs_h *g)
{
  if (test_command_lines_4_skip ()) {
    skipped ("test_command_lines_4", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_lines_4", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_lines_4_perform (g);
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
test_command_lines_4_perform (guestfs_h *g)
{
  /* TestResult for command_lines (4) */
  const char *arg3297 = "/command_lines5";
  int ret3;
  ret3 = guestfs_mkdir (g, arg3297);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *arg3299 = substitute_srcdir ("test-command");
  const char *arg3300 = "/command_lines5/test-command";
  int ret2;
  ret2 = guestfs_upload (g, arg3299, arg3300);
  if (ret2 == -1)
    return -1;
  const char *arg3303 = "/command_lines5/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, arg3303);
  if (ret1 == -1)
    return -1;
  const char *arg3305_0 = "/command_lines5/test-command";
  const char *arg3305_1 = "5";
  const char *const arg3305[] = {
    arg3305_0,
    arg3305_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) arg3305);
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

static int test_command_lines_5_skip (void);
static int test_command_lines_5_perform (guestfs_h *);

static int
test_command_lines_5 (guestfs_h *g)
{
  if (test_command_lines_5_skip ()) {
    skipped ("test_command_lines_5", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_lines_5", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_lines_5_perform (g);
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
test_command_lines_5_perform (guestfs_h *g)
{
  /* TestResult for command_lines (5) */
  const char *arg3307 = "/command_lines6";
  int ret3;
  ret3 = guestfs_mkdir (g, arg3307);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *arg3309 = substitute_srcdir ("test-command");
  const char *arg3310 = "/command_lines6/test-command";
  int ret2;
  ret2 = guestfs_upload (g, arg3309, arg3310);
  if (ret2 == -1)
    return -1;
  const char *arg3313 = "/command_lines6/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, arg3313);
  if (ret1 == -1)
    return -1;
  const char *arg3315_0 = "/command_lines6/test-command";
  const char *arg3315_1 = "6";
  const char *const arg3315[] = {
    arg3315_0,
    arg3315_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) arg3315);
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

static int test_command_lines_6_skip (void);
static int test_command_lines_6_perform (guestfs_h *);

static int
test_command_lines_6 (guestfs_h *g)
{
  if (test_command_lines_6_skip ()) {
    skipped ("test_command_lines_6", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_lines_6", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_lines_6_perform (g);
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
test_command_lines_6_perform (guestfs_h *g)
{
  /* TestResult for command_lines (6) */
  const char *arg3317 = "/command_lines7";
  int ret3;
  ret3 = guestfs_mkdir (g, arg3317);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *arg3319 = substitute_srcdir ("test-command");
  const char *arg3320 = "/command_lines7/test-command";
  int ret2;
  ret2 = guestfs_upload (g, arg3319, arg3320);
  if (ret2 == -1)
    return -1;
  const char *arg3323 = "/command_lines7/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, arg3323);
  if (ret1 == -1)
    return -1;
  const char *arg3325_0 = "/command_lines7/test-command";
  const char *arg3325_1 = "7";
  const char *const arg3325[] = {
    arg3325_0,
    arg3325_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) arg3325);
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

static int test_command_lines_7_skip (void);
static int test_command_lines_7_perform (guestfs_h *);

static int
test_command_lines_7 (guestfs_h *g)
{
  if (test_command_lines_7_skip ()) {
    skipped ("test_command_lines_7", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_lines_7", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_lines_7_perform (g);
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
test_command_lines_7_perform (guestfs_h *g)
{
  /* TestResult for command_lines (7) */
  const char *arg3327 = "/command_lines8";
  int ret3;
  ret3 = guestfs_mkdir (g, arg3327);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *arg3329 = substitute_srcdir ("test-command");
  const char *arg3330 = "/command_lines8/test-command";
  int ret2;
  ret2 = guestfs_upload (g, arg3329, arg3330);
  if (ret2 == -1)
    return -1;
  const char *arg3333 = "/command_lines8/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, arg3333);
  if (ret1 == -1)
    return -1;
  const char *arg3335_0 = "/command_lines8/test-command";
  const char *arg3335_1 = "8";
  const char *const arg3335[] = {
    arg3335_0,
    arg3335_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) arg3335);
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

static int test_command_lines_8_skip (void);
static int test_command_lines_8_perform (guestfs_h *);

static int
test_command_lines_8 (guestfs_h *g)
{
  if (test_command_lines_8_skip ()) {
    skipped ("test_command_lines_8", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_lines_8", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_lines_8_perform (g);
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
test_command_lines_8_perform (guestfs_h *g)
{
  /* TestResult for command_lines (8) */
  const char *arg3337 = "/command_lines9";
  int ret3;
  ret3 = guestfs_mkdir (g, arg3337);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *arg3339 = substitute_srcdir ("test-command");
  const char *arg3340 = "/command_lines9/test-command";
  int ret2;
  ret2 = guestfs_upload (g, arg3339, arg3340);
  if (ret2 == -1)
    return -1;
  const char *arg3343 = "/command_lines9/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, arg3343);
  if (ret1 == -1)
    return -1;
  const char *arg3345_0 = "/command_lines9/test-command";
  const char *arg3345_1 = "9";
  const char *const arg3345[] = {
    arg3345_0,
    arg3345_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) arg3345);
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

static int test_command_lines_9_skip (void);
static int test_command_lines_9_perform (guestfs_h *);

static int
test_command_lines_9 (guestfs_h *g)
{
  if (test_command_lines_9_skip ()) {
    skipped ("test_command_lines_9", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_lines_9", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_lines_9_perform (g);
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
test_command_lines_9_perform (guestfs_h *g)
{
  /* TestResult for command_lines (9) */
  const char *arg3347 = "/command_lines10";
  int ret3;
  ret3 = guestfs_mkdir (g, arg3347);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *arg3349 = substitute_srcdir ("test-command");
  const char *arg3350 = "/command_lines10/test-command";
  int ret2;
  ret2 = guestfs_upload (g, arg3349, arg3350);
  if (ret2 == -1)
    return -1;
  const char *arg3353 = "/command_lines10/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, arg3353);
  if (ret1 == -1)
    return -1;
  const char *arg3355_0 = "/command_lines10/test-command";
  const char *arg3355_1 = "10";
  const char *const arg3355[] = {
    arg3355_0,
    arg3355_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) arg3355);
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

static int test_command_lines_10_skip (void);
static int test_command_lines_10_perform (guestfs_h *);

static int
test_command_lines_10 (guestfs_h *g)
{
  if (test_command_lines_10_skip ()) {
    skipped ("test_command_lines_10", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_lines_10", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_lines_10_perform (g);
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
test_command_lines_10_perform (guestfs_h *g)
{
  /* TestResult for command_lines (10) */
  const char *arg3357 = "/command_lines11";
  int ret3;
  ret3 = guestfs_mkdir (g, arg3357);
  if (ret3 == -1)
    return -1;
  CLEANUP_FREE char *arg3359 = substitute_srcdir ("test-command");
  const char *arg3360 = "/command_lines11/test-command";
  int ret2;
  ret2 = guestfs_upload (g, arg3359, arg3360);
  if (ret2 == -1)
    return -1;
  const char *arg3363 = "/command_lines11/test-command";
  int ret1;
  ret1 = guestfs_chmod (g, 493, arg3363);
  if (ret1 == -1)
    return -1;
  const char *arg3365_0 = "/command_lines11/test-command";
  const char *arg3365_1 = "11";
  const char *const arg3365[] = {
    arg3365_0,
    arg3365_1,
    NULL
  };
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_command_lines (g, (char **) arg3365);
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

static int test_command_0_skip (void);
static int test_command_0_perform (guestfs_h *);

static int
test_command_0 (guestfs_h *g)
{
  if (test_command_0_skip ()) {
    skipped ("test_command_0", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_0", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_0_perform (g);
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
test_command_0_perform (guestfs_h *g)
{
  /* TestResultString for command (0) */
  const char *arg3368 = "/command";
  int ret3367;
  ret3367 = guestfs_mkdir (g, arg3368);
  if (ret3367 == -1)
    return -1;
  CLEANUP_FREE char *arg3371 = substitute_srcdir ("test-command");
  const char *arg3372 = "/command/test-command";
  int ret3370;
  ret3370 = guestfs_upload (g, arg3371, arg3372);
  if (ret3370 == -1)
    return -1;
  const char *arg3376 = "/command/test-command";
  int ret3374;
  ret3374 = guestfs_chmod (g, 493, arg3376);
  if (ret3374 == -1)
    return -1;
  const char *arg3378_0 = "/command/test-command";
  const char *arg3378_1 = "1";
  const char *const arg3378[] = {
    arg3378_0,
    arg3378_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) arg3378);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "Result1")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_0", "command", "Result1", ret);
    return -1;
  }
  return 0;
}

static int test_command_1_skip (void);
static int test_command_1_perform (guestfs_h *);

static int
test_command_1 (guestfs_h *g)
{
  if (test_command_1_skip ()) {
    skipped ("test_command_1", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_1", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_1_perform (g);
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
test_command_1_perform (guestfs_h *g)
{
  /* TestResultString for command (1) */
  const char *arg3381 = "/command2";
  int ret3380;
  ret3380 = guestfs_mkdir (g, arg3381);
  if (ret3380 == -1)
    return -1;
  CLEANUP_FREE char *arg3384 = substitute_srcdir ("test-command");
  const char *arg3385 = "/command2/test-command";
  int ret3383;
  ret3383 = guestfs_upload (g, arg3384, arg3385);
  if (ret3383 == -1)
    return -1;
  const char *arg3389 = "/command2/test-command";
  int ret3387;
  ret3387 = guestfs_chmod (g, 493, arg3389);
  if (ret3387 == -1)
    return -1;
  const char *arg3391_0 = "/command2/test-command";
  const char *arg3391_1 = "2";
  const char *const arg3391[] = {
    arg3391_0,
    arg3391_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) arg3391);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "Result2\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_1", "command", "Result2\n", ret);
    return -1;
  }
  return 0;
}

static int test_command_2_skip (void);
static int test_command_2_perform (guestfs_h *);

static int
test_command_2 (guestfs_h *g)
{
  if (test_command_2_skip ()) {
    skipped ("test_command_2", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_2", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_2_perform (g);
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
test_command_2_perform (guestfs_h *g)
{
  /* TestResultString for command (2) */
  const char *arg3394 = "/command3";
  int ret3393;
  ret3393 = guestfs_mkdir (g, arg3394);
  if (ret3393 == -1)
    return -1;
  CLEANUP_FREE char *arg3397 = substitute_srcdir ("test-command");
  const char *arg3398 = "/command3/test-command";
  int ret3396;
  ret3396 = guestfs_upload (g, arg3397, arg3398);
  if (ret3396 == -1)
    return -1;
  const char *arg3402 = "/command3/test-command";
  int ret3400;
  ret3400 = guestfs_chmod (g, 493, arg3402);
  if (ret3400 == -1)
    return -1;
  const char *arg3404_0 = "/command3/test-command";
  const char *arg3404_1 = "3";
  const char *const arg3404[] = {
    arg3404_0,
    arg3404_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) arg3404);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\nResult3")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_2", "command", "\nResult3", ret);
    return -1;
  }
  return 0;
}

static int test_command_3_skip (void);
static int test_command_3_perform (guestfs_h *);

static int
test_command_3 (guestfs_h *g)
{
  if (test_command_3_skip ()) {
    skipped ("test_command_3", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_3", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_3_perform (g);
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
test_command_3_perform (guestfs_h *g)
{
  /* TestResultString for command (3) */
  const char *arg3407 = "/command4";
  int ret3406;
  ret3406 = guestfs_mkdir (g, arg3407);
  if (ret3406 == -1)
    return -1;
  CLEANUP_FREE char *arg3410 = substitute_srcdir ("test-command");
  const char *arg3411 = "/command4/test-command";
  int ret3409;
  ret3409 = guestfs_upload (g, arg3410, arg3411);
  if (ret3409 == -1)
    return -1;
  const char *arg3415 = "/command4/test-command";
  int ret3413;
  ret3413 = guestfs_chmod (g, 493, arg3415);
  if (ret3413 == -1)
    return -1;
  const char *arg3417_0 = "/command4/test-command";
  const char *arg3417_1 = "4";
  const char *const arg3417[] = {
    arg3417_0,
    arg3417_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) arg3417);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\nResult4\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_3", "command", "\nResult4\n", ret);
    return -1;
  }
  return 0;
}

static int test_command_4_skip (void);
static int test_command_4_perform (guestfs_h *);

static int
test_command_4 (guestfs_h *g)
{
  if (test_command_4_skip ()) {
    skipped ("test_command_4", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_4", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_4_perform (g);
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
test_command_4_perform (guestfs_h *g)
{
  /* TestResultString for command (4) */
  const char *arg3420 = "/command5";
  int ret3419;
  ret3419 = guestfs_mkdir (g, arg3420);
  if (ret3419 == -1)
    return -1;
  CLEANUP_FREE char *arg3423 = substitute_srcdir ("test-command");
  const char *arg3424 = "/command5/test-command";
  int ret3422;
  ret3422 = guestfs_upload (g, arg3423, arg3424);
  if (ret3422 == -1)
    return -1;
  const char *arg3428 = "/command5/test-command";
  int ret3426;
  ret3426 = guestfs_chmod (g, 493, arg3428);
  if (ret3426 == -1)
    return -1;
  const char *arg3430_0 = "/command5/test-command";
  const char *arg3430_1 = "5";
  const char *const arg3430[] = {
    arg3430_0,
    arg3430_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) arg3430);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\nResult5\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_4", "command", "\nResult5\n\n", ret);
    return -1;
  }
  return 0;
}

static int test_command_5_skip (void);
static int test_command_5_perform (guestfs_h *);

static int
test_command_5 (guestfs_h *g)
{
  if (test_command_5_skip ()) {
    skipped ("test_command_5", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_5", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_5_perform (g);
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
test_command_5_perform (guestfs_h *g)
{
  /* TestResultString for command (5) */
  const char *arg3433 = "/command6";
  int ret3432;
  ret3432 = guestfs_mkdir (g, arg3433);
  if (ret3432 == -1)
    return -1;
  CLEANUP_FREE char *arg3436 = substitute_srcdir ("test-command");
  const char *arg3437 = "/command6/test-command";
  int ret3435;
  ret3435 = guestfs_upload (g, arg3436, arg3437);
  if (ret3435 == -1)
    return -1;
  const char *arg3441 = "/command6/test-command";
  int ret3439;
  ret3439 = guestfs_chmod (g, 493, arg3441);
  if (ret3439 == -1)
    return -1;
  const char *arg3443_0 = "/command6/test-command";
  const char *arg3443_1 = "6";
  const char *const arg3443[] = {
    arg3443_0,
    arg3443_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) arg3443);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n\nResult6\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_5", "command", "\n\nResult6\n\n", ret);
    return -1;
  }
  return 0;
}

static int test_command_6_skip (void);
static int test_command_6_perform (guestfs_h *);

static int
test_command_6 (guestfs_h *g)
{
  if (test_command_6_skip ()) {
    skipped ("test_command_6", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_6", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_6_perform (g);
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
test_command_6_perform (guestfs_h *g)
{
  /* TestResultString for command (6) */
  const char *arg3446 = "/command7";
  int ret3445;
  ret3445 = guestfs_mkdir (g, arg3446);
  if (ret3445 == -1)
    return -1;
  CLEANUP_FREE char *arg3449 = substitute_srcdir ("test-command");
  const char *arg3450 = "/command7/test-command";
  int ret3448;
  ret3448 = guestfs_upload (g, arg3449, arg3450);
  if (ret3448 == -1)
    return -1;
  const char *arg3454 = "/command7/test-command";
  int ret3452;
  ret3452 = guestfs_chmod (g, 493, arg3454);
  if (ret3452 == -1)
    return -1;
  const char *arg3456_0 = "/command7/test-command";
  const char *arg3456_1 = "7";
  const char *const arg3456[] = {
    arg3456_0,
    arg3456_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) arg3456);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_6", "command", "", ret);
    return -1;
  }
  return 0;
}

static int test_command_7_skip (void);
static int test_command_7_perform (guestfs_h *);

static int
test_command_7 (guestfs_h *g)
{
  if (test_command_7_skip ()) {
    skipped ("test_command_7", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_7", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_7_perform (g);
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
test_command_7_perform (guestfs_h *g)
{
  /* TestResultString for command (7) */
  const char *arg3459 = "/command8";
  int ret3458;
  ret3458 = guestfs_mkdir (g, arg3459);
  if (ret3458 == -1)
    return -1;
  CLEANUP_FREE char *arg3462 = substitute_srcdir ("test-command");
  const char *arg3463 = "/command8/test-command";
  int ret3461;
  ret3461 = guestfs_upload (g, arg3462, arg3463);
  if (ret3461 == -1)
    return -1;
  const char *arg3467 = "/command8/test-command";
  int ret3465;
  ret3465 = guestfs_chmod (g, 493, arg3467);
  if (ret3465 == -1)
    return -1;
  const char *arg3469_0 = "/command8/test-command";
  const char *arg3469_1 = "8";
  const char *const arg3469[] = {
    arg3469_0,
    arg3469_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) arg3469);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_7", "command", "\n", ret);
    return -1;
  }
  return 0;
}

static int test_command_8_skip (void);
static int test_command_8_perform (guestfs_h *);

static int
test_command_8 (guestfs_h *g)
{
  if (test_command_8_skip ()) {
    skipped ("test_command_8", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_8", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_8_perform (g);
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
test_command_8_perform (guestfs_h *g)
{
  /* TestResultString for command (8) */
  const char *arg3472 = "/command9";
  int ret3471;
  ret3471 = guestfs_mkdir (g, arg3472);
  if (ret3471 == -1)
    return -1;
  CLEANUP_FREE char *arg3475 = substitute_srcdir ("test-command");
  const char *arg3476 = "/command9/test-command";
  int ret3474;
  ret3474 = guestfs_upload (g, arg3475, arg3476);
  if (ret3474 == -1)
    return -1;
  const char *arg3480 = "/command9/test-command";
  int ret3478;
  ret3478 = guestfs_chmod (g, 493, arg3480);
  if (ret3478 == -1)
    return -1;
  const char *arg3482_0 = "/command9/test-command";
  const char *arg3482_1 = "9";
  const char *const arg3482[] = {
    arg3482_0,
    arg3482_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) arg3482);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_8", "command", "\n\n", ret);
    return -1;
  }
  return 0;
}

static int test_command_9_skip (void);
static int test_command_9_perform (guestfs_h *);

static int
test_command_9 (guestfs_h *g)
{
  if (test_command_9_skip ()) {
    skipped ("test_command_9", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_9", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_9_perform (g);
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
test_command_9_perform (guestfs_h *g)
{
  /* TestResultString for command (9) */
  const char *arg3485 = "/command10";
  int ret3484;
  ret3484 = guestfs_mkdir (g, arg3485);
  if (ret3484 == -1)
    return -1;
  CLEANUP_FREE char *arg3488 = substitute_srcdir ("test-command");
  const char *arg3489 = "/command10/test-command";
  int ret3487;
  ret3487 = guestfs_upload (g, arg3488, arg3489);
  if (ret3487 == -1)
    return -1;
  const char *arg3493 = "/command10/test-command";
  int ret3491;
  ret3491 = guestfs_chmod (g, 493, arg3493);
  if (ret3491 == -1)
    return -1;
  const char *arg3495_0 = "/command10/test-command";
  const char *arg3495_1 = "10";
  const char *const arg3495[] = {
    arg3495_0,
    arg3495_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) arg3495);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "Result10-1\nResult10-2\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_9", "command", "Result10-1\nResult10-2\n", ret);
    return -1;
  }
  return 0;
}

static int test_command_10_skip (void);
static int test_command_10_perform (guestfs_h *);

static int
test_command_10 (guestfs_h *g)
{
  if (test_command_10_skip ()) {
    skipped ("test_command_10", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_10", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_10_perform (g);
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
test_command_10_perform (guestfs_h *g)
{
  /* TestResultString for command (10) */
  const char *arg3498 = "/command11";
  int ret3497;
  ret3497 = guestfs_mkdir (g, arg3498);
  if (ret3497 == -1)
    return -1;
  CLEANUP_FREE char *arg3501 = substitute_srcdir ("test-command");
  const char *arg3502 = "/command11/test-command";
  int ret3500;
  ret3500 = guestfs_upload (g, arg3501, arg3502);
  if (ret3500 == -1)
    return -1;
  const char *arg3506 = "/command11/test-command";
  int ret3504;
  ret3504 = guestfs_chmod (g, 493, arg3506);
  if (ret3504 == -1)
    return -1;
  const char *arg3508_0 = "/command11/test-command";
  const char *arg3508_1 = "11";
  const char *const arg3508[] = {
    arg3508_0,
    arg3508_1,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) arg3508);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "Result11-1\nResult11-2")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_10", "command", "Result11-1\nResult11-2", ret);
    return -1;
  }
  return 0;
}

static int test_command_11_skip (void);
static int test_command_11_perform (guestfs_h *);

static int
test_command_11 (guestfs_h *g)
{
  if (test_command_11_skip ()) {
    skipped ("test_command_11", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_11", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_11_perform (g);
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
test_command_11_perform (guestfs_h *g)
{
  /* TestLastFail for command (11) */
  const char *arg3511 = "/command12";
  int ret3510;
  ret3510 = guestfs_mkdir (g, arg3511);
  if (ret3510 == -1)
    return -1;
  CLEANUP_FREE char *arg3514 = substitute_srcdir ("test-command");
  const char *arg3515 = "/command12/test-command";
  int ret3513;
  ret3513 = guestfs_upload (g, arg3514, arg3515);
  if (ret3513 == -1)
    return -1;
  const char *arg3519 = "/command12/test-command";
  int ret3517;
  ret3517 = guestfs_chmod (g, 493, arg3519);
  if (ret3517 == -1)
    return -1;
  const char *arg3522_0 = "/command12/test-command";
  const char *const arg3522[] = {
    arg3522_0,
    NULL
  };
  CLEANUP_FREE char *ret3521;
  guestfs_push_error_handler (g, NULL, NULL);
  ret3521 = guestfs_command (g, (char **) arg3522);
  guestfs_pop_error_handler (g);
  if (ret3521 != NULL)
    return -1;
  return 0;
}

static int test_command_12_skip (void);
static int test_command_12_perform (guestfs_h *);

static int
test_command_12 (guestfs_h *g)
{
  if (test_command_12_skip ()) {
    skipped ("test_command_12", "environment variable set");
    return 0;
  }

  if (using_cross_appliance ()) {
    skipped ("test_command_12", "cannot run when appliance and host are different");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_command_12_perform (g);
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
test_command_12_perform (guestfs_h *g)
{
  /* TestResultString for command (12) */
  const char *arg3525 = "/pwd";
  int ret3524;
  ret3524 = guestfs_mkdir (g, arg3525);
  if (ret3524 == -1)
    return -1;
  CLEANUP_FREE char *arg3528 = substitute_srcdir ("test-pwd");
  const char *arg3529 = "/pwd/test-pwd";
  int ret3527;
  ret3527 = guestfs_upload (g, arg3528, arg3529);
  if (ret3527 == -1)
    return -1;
  const char *arg3533 = "/pwd/test-pwd";
  int ret3531;
  ret3531 = guestfs_chmod (g, 493, arg3533);
  if (ret3531 == -1)
    return -1;
  const char *arg3535_0 = "/pwd/test-pwd";
  const char *const arg3535[] = {
    arg3535_0,
    NULL
  };
  CLEANUP_FREE char *ret;
  ret = guestfs_command (g, (char **) arg3535);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "/")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_command_12", "command", "/", ret);
    return -1;
  }
  return 0;
}

static int test_file_0_skip (void);
static int test_file_0_perform (guestfs_h *);

static int
test_file_0 (guestfs_h *g)
{
  if (test_file_0_skip ()) {
    skipped ("test_file_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_0_perform (g);
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
test_file_0_perform (guestfs_h *g)
{
  /* TestResultString for file (0) */
  const char *arg3537 = "/empty";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, arg3537);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "empty")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_0", "file", "empty", ret);
    return -1;
  }
  return 0;
}

static int test_file_1_skip (void);
static int test_file_1_perform (guestfs_h *);

static int
test_file_1 (guestfs_h *g)
{
  if (test_file_1_skip ()) {
    skipped ("test_file_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_1_perform (g);
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
test_file_1_perform (guestfs_h *g)
{
  /* TestResultString for file (1) */
  const char *arg3539 = "/known-1";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, arg3539);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "ASCII text")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_1", "file", "ASCII text", ret);
    return -1;
  }
  return 0;
}

static int test_file_2_skip (void);
static int test_file_2_perform (guestfs_h *);

static int
test_file_2 (guestfs_h *g)
{
  if (test_file_2_skip ()) {
    skipped ("test_file_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_2_perform (g);
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
test_file_2_perform (guestfs_h *g)
{
  /* TestLastFail for file (2) */
  const char *arg3542 = "/notexists";
  CLEANUP_FREE char *ret3541;
  guestfs_push_error_handler (g, NULL, NULL);
  ret3541 = guestfs_file (g, arg3542);
  guestfs_pop_error_handler (g);
  if (ret3541 != NULL)
    return -1;
  return 0;
}

static int test_file_3_skip (void);
static int test_file_3_perform (guestfs_h *);

static int
test_file_3 (guestfs_h *g)
{
  if (test_file_3_skip ()) {
    skipped ("test_file_3", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_3_perform (g);
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
test_file_3_perform (guestfs_h *g)
{
  /* TestResultString for file (3) */
  const char *arg3544 = "/abssymlink";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, arg3544);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "symbolic link")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_3", "file", "symbolic link", ret);
    return -1;
  }
  return 0;
}

static int test_file_4_skip (void);
static int test_file_4_perform (guestfs_h *);

static int
test_file_4 (guestfs_h *g)
{
  if (test_file_4_skip ()) {
    skipped ("test_file_4", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_4_perform (g);
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
test_file_4_perform (guestfs_h *g)
{
  /* TestResultString for file (4) */
  const char *arg3546 = "/directory";
  CLEANUP_FREE char *ret;
  ret = guestfs_file (g, arg3546);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "directory")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_4", "file", "directory", ret);
    return -1;
  }
  return 0;
}

static int test_umount_all_0_skip (void);
static int test_umount_all_0_perform (guestfs_h *);

static int
test_umount_all_0 (guestfs_h *g)
{
  if (test_umount_all_0_skip ()) {
    skipped ("test_umount_all_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_umount_all_0_perform (g);
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
test_umount_all_0_perform (guestfs_h *g)
{
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

static int test_umount_all_1_skip (void);
static int test_umount_all_1_perform (guestfs_h *);

static int
test_umount_all_1 (guestfs_h *g)
{
  if (test_umount_all_1_skip ()) {
    skipped ("test_umount_all_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_umount_all_1_perform (g);
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
test_umount_all_1_perform (guestfs_h *g)
{
  /* TestResult for umount_all (1) */
  const char *arg3550 = "/dev/sda";
  const char *arg3551 = "mbr";
  int ret14;
  ret14 = guestfs_part_init (g, arg3550, arg3551);
  if (ret14 == -1)
    return -1;
  const char *arg3553 = "/dev/sda";
  const char *arg3554 = "p";
  int ret13;
  ret13 = guestfs_part_add (g, arg3553, arg3554, 64, 204799);
  if (ret13 == -1)
    return -1;
  const char *arg3558 = "/dev/sda";
  const char *arg3559 = "p";
  int ret12;
  ret12 = guestfs_part_add (g, arg3558, arg3559, 204800, 409599);
  if (ret12 == -1)
    return -1;
  const char *arg3563 = "/dev/sda";
  const char *arg3564 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, arg3563, arg3564, 409600, -64);
  if (ret11 == -1)
    return -1;
  const char *arg3568 = "ext2";
  const char *arg3569 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs3570;
  optargs3570.bitmask = UINT64_C(0x0);
  int ret10;
  ret10 = guestfs_mkfs_opts_argv (g, arg3568, arg3569, &optargs3570);
  if (ret10 == -1)
    return -1;
  const char *arg3571 = "ext2";
  const char *arg3572 = "/dev/sda2";
  struct guestfs_mkfs_opts_argv optargs3573;
  optargs3573.bitmask = UINT64_C(0x0);
  int ret9;
  ret9 = guestfs_mkfs_opts_argv (g, arg3571, arg3572, &optargs3573);
  if (ret9 == -1)
    return -1;
  const char *arg3574 = "ext2";
  const char *arg3575 = "/dev/sda3";
  struct guestfs_mkfs_opts_argv optargs3576;
  optargs3576.bitmask = UINT64_C(0x0);
  int ret8;
  ret8 = guestfs_mkfs_opts_argv (g, arg3574, arg3575, &optargs3576);
  if (ret8 == -1)
    return -1;
  const char *arg3577 = "/dev/sda1";
  const char *arg3578 = "/";
  int ret7;
  ret7 = guestfs_mount (g, arg3577, arg3578);
  if (ret7 == -1)
    return -1;
  const char *arg3580 = "/mp1";
  int ret6;
  ret6 = guestfs_mkdir (g, arg3580);
  if (ret6 == -1)
    return -1;
  const char *arg3582 = "/dev/sda2";
  const char *arg3583 = "/mp1";
  int ret5;
  ret5 = guestfs_mount (g, arg3582, arg3583);
  if (ret5 == -1)
    return -1;
  const char *arg3585 = "/mp1/mp2";
  int ret4;
  ret4 = guestfs_mkdir (g, arg3585);
  if (ret4 == -1)
    return -1;
  const char *arg3587 = "/dev/sda3";
  const char *arg3588 = "/mp1/mp2";
  int ret3;
  ret3 = guestfs_mount (g, arg3587, arg3588);
  if (ret3 == -1)
    return -1;
  const char *arg3590 = "/mp1/mp2/mp3";
  int ret2;
  ret2 = guestfs_mkdir (g, arg3590);
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

static int test_mounts_0_skip (void);
static int test_mounts_0_perform (guestfs_h *);

static int
test_mounts_0 (guestfs_h *g)
{
  if (test_mounts_0_skip ()) {
    skipped ("test_mounts_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mounts_0_perform (g);
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
test_mounts_0_perform (guestfs_h *g)
{
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

static int test_umount_0_skip (void);
static int test_umount_0_perform (guestfs_h *);

static int
test_umount_0 (guestfs_h *g)
{
  if (test_umount_0_skip ()) {
    skipped ("test_umount_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_umount_0_perform (g);
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
test_umount_0_perform (guestfs_h *g)
{
  /* TestResult for umount (0) */
  const char *arg3595 = "/dev/sda";
  const char *arg3596 = "mbr";
  int ret3;
  ret3 = guestfs_part_disk (g, arg3595, arg3596);
  if (ret3 == -1)
    return -1;
  const char *arg3598 = "ext2";
  const char *arg3599 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs3600;
  optargs3600.bitmask = UINT64_C(0x0);
  int ret2;
  ret2 = guestfs_mkfs_opts_argv (g, arg3598, arg3599, &optargs3600);
  if (ret2 == -1)
    return -1;
  const char *arg3601 = "/dev/sda1";
  const char *arg3602 = "/";
  int ret1;
  ret1 = guestfs_mount (g, arg3601, arg3602);
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

static int test_umount_1_skip (void);
static int test_umount_1_perform (guestfs_h *);

static int
test_umount_1 (guestfs_h *g)
{
  if (test_umount_1_skip ()) {
    skipped ("test_umount_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_umount_1_perform (g);
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
test_umount_1_perform (guestfs_h *g)
{
  /* TestResult for umount (1) */
  const char *arg3605 = "/dev/sda";
  const char *arg3606 = "mbr";
  int ret4;
  ret4 = guestfs_part_disk (g, arg3605, arg3606);
  if (ret4 == -1)
    return -1;
  const char *arg3608 = "ext2";
  const char *arg3609 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs3610;
  optargs3610.bitmask = UINT64_C(0x0);
  int ret3;
  ret3 = guestfs_mkfs_opts_argv (g, arg3608, arg3609, &optargs3610);
  if (ret3 == -1)
    return -1;
  const char *arg3611 = "/dev/sda1";
  const char *arg3612 = "/";
  int ret2;
  ret2 = guestfs_mount (g, arg3611, arg3612);
  if (ret2 == -1)
    return -1;
  const char *arg3614 = "/";
  struct guestfs_umount_opts_argv optargs3615;
  optargs3615.force = 0;
  optargs3615.lazyunmount = 0;
  optargs3615.bitmask = UINT64_C(0x3);
  int ret1;
  ret1 = guestfs_umount_opts_argv (g, arg3614, &optargs3615);
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

static int test_write_file_0_skip (void);
static int test_write_file_0_perform (guestfs_h *);

static int
test_write_file_0 (guestfs_h *g)
{
  if (test_write_file_0_skip ()) {
    skipped ("test_write_file_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_write_file_0_perform (g);
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
test_write_file_0_perform (guestfs_h *g)
{
  /* TestLastFail for write_file (0) */
  const char *arg3618 = "/write_file";
  const char *arg3619 = "abc";
  int ret3617;
  guestfs_push_error_handler (g, NULL, NULL);
  ret3617 = guestfs_write_file (g, arg3618, arg3619, 10000);
  guestfs_pop_error_handler (g);
  if (ret3617 != -1)
    return -1;
  return 0;
}

static int test_lvcreate_0_skip (void);
static int test_lvcreate_0_perform (guestfs_h *);

static int
test_lvcreate_0 (guestfs_h *g)
{
  if (test_lvcreate_0_skip ()) {
    skipped ("test_lvcreate_0", "environment variable set");
    return 0;
  }

  const char *features3622[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features3622)) {
    skipped ("test_lvcreate_0", "group %s not available in daemon",
             features3622[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_lvcreate_0_perform (g);
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
test_lvcreate_0_perform (guestfs_h *g)
{
  /* TestResult for lvcreate (0) */
  const char *arg3623 = "/dev/sda";
  const char *arg3624 = "mbr";
  int ret14;
  ret14 = guestfs_part_init (g, arg3623, arg3624);
  if (ret14 == -1)
    return -1;
  const char *arg3626 = "/dev/sda";
  const char *arg3627 = "p";
  int ret13;
  ret13 = guestfs_part_add (g, arg3626, arg3627, 64, 204799);
  if (ret13 == -1)
    return -1;
  const char *arg3631 = "/dev/sda";
  const char *arg3632 = "p";
  int ret12;
  ret12 = guestfs_part_add (g, arg3631, arg3632, 204800, 409599);
  if (ret12 == -1)
    return -1;
  const char *arg3636 = "/dev/sda";
  const char *arg3637 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, arg3636, arg3637, 409600, -64);
  if (ret11 == -1)
    return -1;
  const char *arg3641 = "/dev/sda1";
  int ret10;
  ret10 = guestfs_pvcreate (g, arg3641);
  if (ret10 == -1)
    return -1;
  const char *arg3643 = "/dev/sda2";
  int ret9;
  ret9 = guestfs_pvcreate (g, arg3643);
  if (ret9 == -1)
    return -1;
  const char *arg3645 = "/dev/sda3";
  int ret8;
  ret8 = guestfs_pvcreate (g, arg3645);
  if (ret8 == -1)
    return -1;
  const char *arg3647 = "VG1";
  const char *arg3648_0 = "/dev/sda1";
  const char *arg3648_1 = "/dev/sda2";
  const char *const arg3648[] = {
    arg3648_0,
    arg3648_1,
    NULL
  };
  int ret7;
  ret7 = guestfs_vgcreate (g, arg3647, (char **) arg3648);
  if (ret7 == -1)
    return -1;
  const char *arg3650 = "VG2";
  const char *arg3651_0 = "/dev/sda3";
  const char *const arg3651[] = {
    arg3651_0,
    NULL
  };
  int ret6;
  ret6 = guestfs_vgcreate (g, arg3650, (char **) arg3651);
  if (ret6 == -1)
    return -1;
  const char *arg3653 = "LV1";
  const char *arg3654 = "VG1";
  int ret5;
  ret5 = guestfs_lvcreate (g, arg3653, arg3654, 50);
  if (ret5 == -1)
    return -1;
  const char *arg3657 = "LV2";
  const char *arg3658 = "VG1";
  int ret4;
  ret4 = guestfs_lvcreate (g, arg3657, arg3658, 50);
  if (ret4 == -1)
    return -1;
  const char *arg3661 = "LV3";
  const char *arg3662 = "VG2";
  int ret3;
  ret3 = guestfs_lvcreate (g, arg3661, arg3662, 50);
  if (ret3 == -1)
    return -1;
  const char *arg3665 = "LV4";
  const char *arg3666 = "VG2";
  int ret2;
  ret2 = guestfs_lvcreate (g, arg3665, arg3666, 50);
  if (ret2 == -1)
    return -1;
  const char *arg3669 = "LV5";
  const char *arg3670 = "VG2";
  int ret1;
  ret1 = guestfs_lvcreate (g, arg3669, arg3670, 50);
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

static int test_vgcreate_0_skip (void);
static int test_vgcreate_0_perform (guestfs_h *);

static int
test_vgcreate_0 (guestfs_h *g)
{
  if (test_vgcreate_0_skip ()) {
    skipped ("test_vgcreate_0", "environment variable set");
    return 0;
  }

  const char *features3674[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features3674)) {
    skipped ("test_vgcreate_0", "group %s not available in daemon",
             features3674[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_vgcreate_0_perform (g);
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
test_vgcreate_0_perform (guestfs_h *g)
{
  /* TestResult for vgcreate (0) */
  const char *arg3675 = "/dev/sda";
  const char *arg3676 = "mbr";
  int ret9;
  ret9 = guestfs_part_init (g, arg3675, arg3676);
  if (ret9 == -1)
    return -1;
  const char *arg3678 = "/dev/sda";
  const char *arg3679 = "p";
  int ret8;
  ret8 = guestfs_part_add (g, arg3678, arg3679, 64, 204799);
  if (ret8 == -1)
    return -1;
  const char *arg3683 = "/dev/sda";
  const char *arg3684 = "p";
  int ret7;
  ret7 = guestfs_part_add (g, arg3683, arg3684, 204800, 409599);
  if (ret7 == -1)
    return -1;
  const char *arg3688 = "/dev/sda";
  const char *arg3689 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, arg3688, arg3689, 409600, -64);
  if (ret6 == -1)
    return -1;
  const char *arg3693 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, arg3693);
  if (ret5 == -1)
    return -1;
  const char *arg3695 = "/dev/sda2";
  int ret4;
  ret4 = guestfs_pvcreate (g, arg3695);
  if (ret4 == -1)
    return -1;
  const char *arg3697 = "/dev/sda3";
  int ret3;
  ret3 = guestfs_pvcreate (g, arg3697);
  if (ret3 == -1)
    return -1;
  const char *arg3699 = "VG1";
  const char *arg3700_0 = "/dev/sda1";
  const char *arg3700_1 = "/dev/sda2";
  const char *const arg3700[] = {
    arg3700_0,
    arg3700_1,
    NULL
  };
  int ret2;
  ret2 = guestfs_vgcreate (g, arg3699, (char **) arg3700);
  if (ret2 == -1)
    return -1;
  const char *arg3702 = "VG2";
  const char *arg3703_0 = "/dev/sda3";
  const char *const arg3703[] = {
    arg3703_0,
    NULL
  };
  int ret1;
  ret1 = guestfs_vgcreate (g, arg3702, (char **) arg3703);
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

static int test_vgcreate_1_skip (void);
static int test_vgcreate_1_perform (guestfs_h *);

static int
test_vgcreate_1 (guestfs_h *g)
{
  if (test_vgcreate_1_skip ()) {
    skipped ("test_vgcreate_1", "environment variable set");
    return 0;
  }

  const char *features3706[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features3706)) {
    skipped ("test_vgcreate_1", "group %s not available in daemon",
             features3706[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_vgcreate_1_perform (g);
}

static int
test_vgcreate_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "vgcreate") == NULL;
  str = getenv ("SKIP_TEST_VGCREATE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_VGCREATE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_vgcreate_1_perform (guestfs_h *g)
{
  /* TestLastFail for vgcreate (1) */
  const char *arg3708 = "/dev/sda";
  const char *arg3709 = "mbr";
  int ret3707;
  ret3707 = guestfs_part_init (g, arg3708, arg3709);
  if (ret3707 == -1)
    return -1;
  const char *arg3712 = "/dev/sda";
  const char *arg3713 = "p";
  int ret3711;
  ret3711 = guestfs_part_add (g, arg3712, arg3713, 64, 204799);
  if (ret3711 == -1)
    return -1;
  const char *arg3718 = "/dev/sda";
  const char *arg3719 = "p";
  int ret3717;
  ret3717 = guestfs_part_add (g, arg3718, arg3719, 204800, 409599);
  if (ret3717 == -1)
    return -1;
  const char *arg3724 = "/dev/sda";
  const char *arg3725 = "p";
  int ret3723;
  ret3723 = guestfs_part_add (g, arg3724, arg3725, 409600, -64);
  if (ret3723 == -1)
    return -1;
  const char *arg3730 = "/dev/sda1";
  int ret3729;
  ret3729 = guestfs_pvcreate (g, arg3730);
  if (ret3729 == -1)
    return -1;
  const char *arg3733 = "/dev/sda2";
  int ret3732;
  ret3732 = guestfs_pvcreate (g, arg3733);
  if (ret3732 == -1)
    return -1;
  const char *arg3736 = "/dev/sda3";
  int ret3735;
  ret3735 = guestfs_pvcreate (g, arg3736);
  if (ret3735 == -1)
    return -1;
  const char *arg3739 = "VG1";
  const char *arg3740_0 = "/foo/bar";
  const char *arg3740_1 = "/dev/sda2";
  const char *const arg3740[] = {
    arg3740_0,
    arg3740_1,
    NULL
  };
  int ret3738;
  guestfs_push_error_handler (g, NULL, NULL);
  ret3738 = guestfs_vgcreate (g, arg3739, (char **) arg3740);
  guestfs_pop_error_handler (g);
  if (ret3738 != -1)
    return -1;
  return 0;
}

static int test_pvcreate_0_skip (void);
static int test_pvcreate_0_perform (guestfs_h *);

static int
test_pvcreate_0 (guestfs_h *g)
{
  if (test_pvcreate_0_skip ()) {
    skipped ("test_pvcreate_0", "environment variable set");
    return 0;
  }

  const char *features3742[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features3742)) {
    skipped ("test_pvcreate_0", "group %s not available in daemon",
             features3742[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_pvcreate_0_perform (g);
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
test_pvcreate_0_perform (guestfs_h *g)
{
  /* TestResult for pvcreate (0) */
  const char *arg3743 = "/dev/sda";
  const char *arg3744 = "mbr";
  int ret7;
  ret7 = guestfs_part_init (g, arg3743, arg3744);
  if (ret7 == -1)
    return -1;
  const char *arg3746 = "/dev/sda";
  const char *arg3747 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, arg3746, arg3747, 64, 204799);
  if (ret6 == -1)
    return -1;
  const char *arg3751 = "/dev/sda";
  const char *arg3752 = "p";
  int ret5;
  ret5 = guestfs_part_add (g, arg3751, arg3752, 204800, 409599);
  if (ret5 == -1)
    return -1;
  const char *arg3756 = "/dev/sda";
  const char *arg3757 = "p";
  int ret4;
  ret4 = guestfs_part_add (g, arg3756, arg3757, 409600, -64);
  if (ret4 == -1)
    return -1;
  const char *arg3761 = "/dev/sda1";
  int ret3;
  ret3 = guestfs_pvcreate (g, arg3761);
  if (ret3 == -1)
    return -1;
  const char *arg3763 = "/dev/sda2";
  int ret2;
  ret2 = guestfs_pvcreate (g, arg3763);
  if (ret2 == -1)
    return -1;
  const char *arg3765 = "/dev/sda3";
  int ret1;
  ret1 = guestfs_pvcreate (g, arg3765);
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

static int test_is_dir_0_skip (void);
static int test_is_dir_0_perform (guestfs_h *);

static int
test_is_dir_0 (guestfs_h *g)
{
  if (test_is_dir_0_skip ()) {
    skipped ("test_is_dir_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_is_dir_0_perform (g);
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
test_is_dir_0_perform (guestfs_h *g)
{
  /* TestResultFalse for is_dir (0) */
  const char *arg3768 = "/known-3";
  struct guestfs_is_dir_opts_argv optargs3769;
  optargs3769.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, arg3768, &optargs3769);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_dir_0", "is_dir");
    return -1;
  }
  return 0;
}

static int test_is_dir_1_skip (void);
static int test_is_dir_1_perform (guestfs_h *);

static int
test_is_dir_1 (guestfs_h *g)
{
  if (test_is_dir_1_skip ()) {
    skipped ("test_is_dir_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_is_dir_1_perform (g);
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
test_is_dir_1_perform (guestfs_h *g)
{
  /* TestResultTrue for is_dir (1) */
  const char *arg3770 = "/directory";
  struct guestfs_is_dir_opts_argv optargs3771;
  optargs3771.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, arg3770, &optargs3771);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_dir_1", "is_dir");
    return -1;
  }
  return 0;
}

static int test_is_file_0_skip (void);
static int test_is_file_0_perform (guestfs_h *);

static int
test_is_file_0 (guestfs_h *g)
{
  if (test_is_file_0_skip ()) {
    skipped ("test_is_file_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_is_file_0_perform (g);
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
test_is_file_0_perform (guestfs_h *g)
{
  /* TestResultTrue for is_file (0) */
  const char *arg3772 = "/known-1";
  struct guestfs_is_file_opts_argv optargs3773;
  optargs3773.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, arg3772, &optargs3773);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_file_0", "is_file");
    return -1;
  }
  return 0;
}

static int test_is_file_1_skip (void);
static int test_is_file_1_perform (guestfs_h *);

static int
test_is_file_1 (guestfs_h *g)
{
  if (test_is_file_1_skip ()) {
    skipped ("test_is_file_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_is_file_1_perform (g);
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
test_is_file_1_perform (guestfs_h *g)
{
  /* TestResultFalse for is_file (1) */
  const char *arg3774 = "/directory";
  struct guestfs_is_file_opts_argv optargs3775;
  optargs3775.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_file_opts_argv (g, arg3774, &optargs3775);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_is_file_1", "is_file");
    return -1;
  }
  return 0;
}

static int test_is_file_2_skip (void);
static int test_is_file_2_perform (guestfs_h *);

static int
test_is_file_2 (guestfs_h *g)
{
  if (test_is_file_2_skip ()) {
    skipped ("test_is_file_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_is_file_2_perform (g);
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
test_is_file_2_perform (guestfs_h *g)
{
  /* TestResultTrue for is_file (2) */
  const char *arg3776 = "/abssymlink";
  struct guestfs_is_file_opts_argv optargs3777;
  optargs3777.followsymlinks = 1;
  optargs3777.bitmask = UINT64_C(0x1);
  int ret;
  ret = guestfs_is_file_opts_argv (g, arg3776, &optargs3777);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_is_file_2", "is_file");
    return -1;
  }
  return 0;
}

static int test_exists_0_skip (void);
static int test_exists_0_perform (guestfs_h *);

static int
test_exists_0 (guestfs_h *g)
{
  if (test_exists_0_skip ()) {
    skipped ("test_exists_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_exists_0_perform (g);
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
test_exists_0_perform (guestfs_h *g)
{
  /* TestResultTrue for exists (0) */
  const char *arg3778 = "/empty";
  int ret;
  ret = guestfs_exists (g, arg3778);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_exists_0", "exists");
    return -1;
  }
  return 0;
}

static int test_exists_1_skip (void);
static int test_exists_1_perform (guestfs_h *);

static int
test_exists_1 (guestfs_h *g)
{
  if (test_exists_1_skip ()) {
    skipped ("test_exists_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_exists_1_perform (g);
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
test_exists_1_perform (guestfs_h *g)
{
  /* TestResultTrue for exists (1) */
  const char *arg3780 = "/directory";
  int ret;
  ret = guestfs_exists (g, arg3780);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_exists_1", "exists");
    return -1;
  }
  return 0;
}

static int test_mkdir_p_0_skip (void);
static int test_mkdir_p_0_perform (guestfs_h *);

static int
test_mkdir_p_0 (guestfs_h *g)
{
  if (test_mkdir_p_0_skip ()) {
    skipped ("test_mkdir_p_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mkdir_p_0_perform (g);
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
test_mkdir_p_0_perform (guestfs_h *g)
{
  /* TestResultTrue for mkdir_p (0) */
  const char *arg3783 = "/mkdir_p/foo/bar";
  int ret3782;
  ret3782 = guestfs_mkdir_p (g, arg3783);
  if (ret3782 == -1)
    return -1;
  const char *arg3785 = "/mkdir_p/foo/bar";
  struct guestfs_is_dir_opts_argv optargs3786;
  optargs3786.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, arg3785, &optargs3786);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_mkdir_p_0", "is_dir");
    return -1;
  }
  return 0;
}

static int test_mkdir_p_1_skip (void);
static int test_mkdir_p_1_perform (guestfs_h *);

static int
test_mkdir_p_1 (guestfs_h *g)
{
  if (test_mkdir_p_1_skip ()) {
    skipped ("test_mkdir_p_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mkdir_p_1_perform (g);
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
test_mkdir_p_1_perform (guestfs_h *g)
{
  /* TestResultTrue for mkdir_p (1) */
  const char *arg3788 = "/mkdir_p2/foo/bar";
  int ret3787;
  ret3787 = guestfs_mkdir_p (g, arg3788);
  if (ret3787 == -1)
    return -1;
  const char *arg3790 = "/mkdir_p2/foo";
  struct guestfs_is_dir_opts_argv optargs3791;
  optargs3791.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, arg3790, &optargs3791);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_mkdir_p_1", "is_dir");
    return -1;
  }
  return 0;
}

static int test_mkdir_p_2_skip (void);
static int test_mkdir_p_2_perform (guestfs_h *);

static int
test_mkdir_p_2 (guestfs_h *g)
{
  if (test_mkdir_p_2_skip ()) {
    skipped ("test_mkdir_p_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mkdir_p_2_perform (g);
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
test_mkdir_p_2_perform (guestfs_h *g)
{
  /* TestResultTrue for mkdir_p (2) */
  const char *arg3793 = "/mkdir_p3/foo/bar";
  int ret3792;
  ret3792 = guestfs_mkdir_p (g, arg3793);
  if (ret3792 == -1)
    return -1;
  const char *arg3795 = "/mkdir_p3";
  struct guestfs_is_dir_opts_argv optargs3796;
  optargs3796.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, arg3795, &optargs3796);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_mkdir_p_2", "is_dir");
    return -1;
  }
  return 0;
}

static int test_mkdir_p_3_skip (void);
static int test_mkdir_p_3_perform (guestfs_h *);

static int
test_mkdir_p_3 (guestfs_h *g)
{
  if (test_mkdir_p_3_skip ()) {
    skipped ("test_mkdir_p_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mkdir_p_3_perform (g);
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
test_mkdir_p_3_perform (guestfs_h *g)
{
  /* TestRun for mkdir_p (3) */
  const char *arg3798 = "/mkdir_p4";
  int ret3797;
  ret3797 = guestfs_mkdir (g, arg3798);
  if (ret3797 == -1)
    return -1;
  const char *arg3801 = "/mkdir_p4";
  int ret3800;
  ret3800 = guestfs_mkdir_p (g, arg3801);
  if (ret3800 == -1)
    return -1;
  return 0;
}

static int test_mkdir_p_4_skip (void);
static int test_mkdir_p_4_perform (guestfs_h *);

static int
test_mkdir_p_4 (guestfs_h *g)
{
  if (test_mkdir_p_4_skip ()) {
    skipped ("test_mkdir_p_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mkdir_p_4_perform (g);
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
test_mkdir_p_4_perform (guestfs_h *g)
{
  /* TestLastFail for mkdir_p (4) */
  const char *arg3804 = "/mkdir_p5";
  int ret3803;
  ret3803 = guestfs_touch (g, arg3804);
  if (ret3803 == -1)
    return -1;
  const char *arg3807 = "/mkdir_p5";
  int ret3806;
  guestfs_push_error_handler (g, NULL, NULL);
  ret3806 = guestfs_mkdir_p (g, arg3807);
  guestfs_pop_error_handler (g);
  if (ret3806 != -1)
    return -1;
  return 0;
}

static int test_mkdir_0_skip (void);
static int test_mkdir_0_perform (guestfs_h *);

static int
test_mkdir_0 (guestfs_h *g)
{
  if (test_mkdir_0_skip ()) {
    skipped ("test_mkdir_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mkdir_0_perform (g);
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
test_mkdir_0_perform (guestfs_h *g)
{
  /* TestResultTrue for mkdir (0) */
  const char *arg3810 = "/mkdir";
  int ret3809;
  ret3809 = guestfs_mkdir (g, arg3810);
  if (ret3809 == -1)
    return -1;
  const char *arg3812 = "/mkdir";
  struct guestfs_is_dir_opts_argv optargs3813;
  optargs3813.bitmask = UINT64_C(0x0);
  int ret;
  ret = guestfs_is_dir_opts_argv (g, arg3812, &optargs3813);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_mkdir_0", "is_dir");
    return -1;
  }
  return 0;
}

static int test_mkdir_1_skip (void);
static int test_mkdir_1_perform (guestfs_h *);

static int
test_mkdir_1 (guestfs_h *g)
{
  if (test_mkdir_1_skip ()) {
    skipped ("test_mkdir_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_mkdir_1_perform (g);
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
test_mkdir_1_perform (guestfs_h *g)
{
  /* TestLastFail for mkdir (1) */
  const char *arg3815 = "/mkdir2/foo/bar";
  int ret3814;
  guestfs_push_error_handler (g, NULL, NULL);
  ret3814 = guestfs_mkdir (g, arg3815);
  guestfs_pop_error_handler (g);
  if (ret3814 != -1)
    return -1;
  return 0;
}

static int test_rm_rf_0_skip (void);
static int test_rm_rf_0_perform (guestfs_h *);

static int
test_rm_rf_0 (guestfs_h *g)
{
  if (test_rm_rf_0_skip ()) {
    skipped ("test_rm_rf_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_rm_rf_0_perform (g);
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
test_rm_rf_0_perform (guestfs_h *g)
{
  /* TestResultFalse for rm_rf (0) */
  const char *arg3818 = "/rm_rf";
  int ret3817;
  ret3817 = guestfs_mkdir (g, arg3818);
  if (ret3817 == -1)
    return -1;
  const char *arg3821 = "/rm_rf/foo";
  int ret3820;
  ret3820 = guestfs_mkdir (g, arg3821);
  if (ret3820 == -1)
    return -1;
  const char *arg3824 = "/rm_rf/foo/bar";
  int ret3823;
  ret3823 = guestfs_touch (g, arg3824);
  if (ret3823 == -1)
    return -1;
  const char *arg3827 = "/rm_rf";
  int ret3826;
  ret3826 = guestfs_rm_rf (g, arg3827);
  if (ret3826 == -1)
    return -1;
  const char *arg3829 = "/rm_rf";
  int ret;
  ret = guestfs_exists (g, arg3829);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_rm_rf_0", "exists");
    return -1;
  }
  return 0;
}

static int test_rmdir_0_skip (void);
static int test_rmdir_0_perform (guestfs_h *);

static int
test_rmdir_0 (guestfs_h *g)
{
  if (test_rmdir_0_skip ()) {
    skipped ("test_rmdir_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_rmdir_0_perform (g);
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
test_rmdir_0_perform (guestfs_h *g)
{
  /* TestRun for rmdir (0) */
  const char *arg3832 = "/rmdir";
  int ret3831;
  ret3831 = guestfs_mkdir (g, arg3832);
  if (ret3831 == -1)
    return -1;
  const char *arg3835 = "/rmdir";
  int ret3834;
  ret3834 = guestfs_rmdir (g, arg3835);
  if (ret3834 == -1)
    return -1;
  return 0;
}

static int test_rmdir_1_skip (void);
static int test_rmdir_1_perform (guestfs_h *);

static int
test_rmdir_1 (guestfs_h *g)
{
  if (test_rmdir_1_skip ()) {
    skipped ("test_rmdir_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_rmdir_1_perform (g);
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
test_rmdir_1_perform (guestfs_h *g)
{
  /* TestLastFail for rmdir (1) */
  const char *arg3838 = "/rmdir2";
  int ret3837;
  guestfs_push_error_handler (g, NULL, NULL);
  ret3837 = guestfs_rmdir (g, arg3838);
  guestfs_pop_error_handler (g);
  if (ret3837 != -1)
    return -1;
  return 0;
}

static int test_rmdir_2_skip (void);
static int test_rmdir_2_perform (guestfs_h *);

static int
test_rmdir_2 (guestfs_h *g)
{
  if (test_rmdir_2_skip ()) {
    skipped ("test_rmdir_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_rmdir_2_perform (g);
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
test_rmdir_2_perform (guestfs_h *g)
{
  /* TestLastFail for rmdir (2) */
  const char *arg3841 = "/rmdir3";
  int ret3840;
  ret3840 = guestfs_mkdir (g, arg3841);
  if (ret3840 == -1)
    return -1;
  const char *arg3844 = "/rmdir3/new";
  int ret3843;
  ret3843 = guestfs_touch (g, arg3844);
  if (ret3843 == -1)
    return -1;
  const char *arg3847 = "/rmdir3/new";
  int ret3846;
  guestfs_push_error_handler (g, NULL, NULL);
  ret3846 = guestfs_rmdir (g, arg3847);
  guestfs_pop_error_handler (g);
  if (ret3846 != -1)
    return -1;
  return 0;
}

static int test_rm_0_skip (void);
static int test_rm_0_perform (guestfs_h *);

static int
test_rm_0 (guestfs_h *g)
{
  if (test_rm_0_skip ()) {
    skipped ("test_rm_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_rm_0_perform (g);
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
test_rm_0_perform (guestfs_h *g)
{
  /* TestRun for rm (0) */
  const char *arg3850 = "/rm";
  int ret3849;
  ret3849 = guestfs_mkdir (g, arg3850);
  if (ret3849 == -1)
    return -1;
  const char *arg3853 = "/rm/new";
  int ret3852;
  ret3852 = guestfs_touch (g, arg3853);
  if (ret3852 == -1)
    return -1;
  const char *arg3856 = "/rm/new";
  int ret3855;
  ret3855 = guestfs_rm (g, arg3856);
  if (ret3855 == -1)
    return -1;
  return 0;
}

static int test_rm_1_skip (void);
static int test_rm_1_perform (guestfs_h *);

static int
test_rm_1 (guestfs_h *g)
{
  if (test_rm_1_skip ()) {
    skipped ("test_rm_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_rm_1_perform (g);
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
test_rm_1_perform (guestfs_h *g)
{
  /* TestLastFail for rm (1) */
  const char *arg3859 = "/nosuchfile";
  int ret3858;
  guestfs_push_error_handler (g, NULL, NULL);
  ret3858 = guestfs_rm (g, arg3859);
  guestfs_pop_error_handler (g);
  if (ret3858 != -1)
    return -1;
  return 0;
}

static int test_rm_2_skip (void);
static int test_rm_2_perform (guestfs_h *);

static int
test_rm_2 (guestfs_h *g)
{
  if (test_rm_2_skip ()) {
    skipped ("test_rm_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_rm_2_perform (g);
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
test_rm_2_perform (guestfs_h *g)
{
  /* TestLastFail for rm (2) */
  const char *arg3862 = "/rm2";
  int ret3861;
  ret3861 = guestfs_mkdir (g, arg3862);
  if (ret3861 == -1)
    return -1;
  const char *arg3865 = "/rm2";
  int ret3864;
  guestfs_push_error_handler (g, NULL, NULL);
  ret3864 = guestfs_rm (g, arg3865);
  guestfs_pop_error_handler (g);
  if (ret3864 != -1)
    return -1;
  return 0;
}

static int test_aug_ls_0_skip (void);
static int test_aug_ls_0_perform (guestfs_h *);
static int test_aug_ls_0_cleanup (guestfs_h *);

static int
test_aug_ls_0 (guestfs_h *g)
{
  if (test_aug_ls_0_skip ()) {
    skipped ("test_aug_ls_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  int ret = test_aug_ls_0_perform (g);
  if (test_aug_ls_0_cleanup (g) == -1) {
    fprintf (stderr, "%s (%d): unexpected error during test cleanups\n",
             "aug_ls", 0);
    return -1;
  }
  return ret;
}

static int
test_aug_ls_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "aug_ls") == NULL;
  str = getenv ("SKIP_TEST_AUG_LS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_AUG_LS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_aug_ls_0_perform (guestfs_h *g)
{
  /* TestResult for aug_ls (0) */
  const char *arg3867 = "/etc";
  int ret3;
  ret3 = guestfs_mkdir (g, arg3867);
  if (ret3 == -1)
    return -1;
  const char *arg3869 = "/etc/hosts";
  const char *arg3870 = "127.0.0.1 localhost";
  size_t arg3870_size = 19;
  int ret2;
  ret2 = guestfs_write (g, arg3869, arg3870, arg3870_size);
  if (ret2 == -1)
    return -1;
  const char *arg3872 = "/";
  int ret1;
  ret1 = guestfs_aug_init (g, arg3872, 0);
  if (ret1 == -1)
    return -1;
  const char *arg3875 = "/files/etc/hosts/1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_aug_ls (g, arg3875);
  if (ret == NULL)
      return -1;
  if (! (is_string_list (ret, 2, "/files/etc/hosts/1/canonical", "/files/etc/hosts/1/ipaddr"))) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_aug_ls_0", "is_string_list (ret, 2, \"/files/etc/hosts/1/canonical\", \"/files/etc/hosts/1/ipaddr\")");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int
test_aug_ls_0_cleanup (guestfs_h *g)
{
  int ret3877;
  ret3877 = guestfs_aug_close (g);
  if (ret3877 == -1)
    return -1;
  return 0;
}

static int test_aug_insert_0_skip (void);
static int test_aug_insert_0_perform (guestfs_h *);
static int test_aug_insert_0_cleanup (guestfs_h *);

static int
test_aug_insert_0 (guestfs_h *g)
{
  if (test_aug_insert_0_skip ()) {
    skipped ("test_aug_insert_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  int ret = test_aug_insert_0_perform (g);
  if (test_aug_insert_0_cleanup (g) == -1) {
    fprintf (stderr, "%s (%d): unexpected error during test cleanups\n",
             "aug_insert", 0);
    return -1;
  }
  return ret;
}

static int
test_aug_insert_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "aug_insert") == NULL;
  str = getenv ("SKIP_TEST_AUG_INSERT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_AUG_INSERT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_aug_insert_0_perform (guestfs_h *g)
{
  /* TestResultString for aug_insert (0) */
  const char *arg3880 = "/etc";
  int ret3879;
  ret3879 = guestfs_mkdir (g, arg3880);
  if (ret3879 == -1)
    return -1;
  const char *arg3883 = "/etc/hosts";
  const char *arg3884 = "";
  size_t arg3884_size = 0;
  int ret3882;
  ret3882 = guestfs_write (g, arg3883, arg3884, arg3884_size);
  if (ret3882 == -1)
    return -1;
  const char *arg3887 = "/";
  int ret3886;
  ret3886 = guestfs_aug_init (g, arg3887, 0);
  if (ret3886 == -1)
    return -1;
  const char *arg3891 = "/files/etc/hosts";
  const char *arg3892 = "1";
  int ret3890;
  ret3890 = guestfs_aug_insert (g, arg3891, arg3892, 0);
  if (ret3890 == -1)
    return -1;
  const char *arg3896 = "/files/etc/hosts/1/ipaddr";
  const char *arg3897 = "127.0.0.1";
  int ret3895;
  ret3895 = guestfs_aug_set (g, arg3896, arg3897);
  if (ret3895 == -1)
    return -1;
  const char *arg3900 = "/files/etc/hosts/1/canonical";
  const char *arg3901 = "foobar";
  int ret3899;
  ret3899 = guestfs_aug_set (g, arg3900, arg3901);
  if (ret3899 == -1)
    return -1;
  const char *arg3904 = "/files/etc/hosts/1/canonical";
  int ret3903;
  ret3903 = guestfs_aug_clear (g, arg3904);
  if (ret3903 == -1)
    return -1;
  const char *arg3907 = "/files/etc/hosts/1/canonical";
  const char *arg3908 = "localhost";
  int ret3906;
  ret3906 = guestfs_aug_set (g, arg3907, arg3908);
  if (ret3906 == -1)
    return -1;
  int ret3910;
  ret3910 = guestfs_aug_save (g);
  if (ret3910 == -1)
    return -1;
  const char *arg3912 = "/etc/hosts";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg3912);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n127.0.0.1\tlocalhost\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_aug_insert_0", "cat", "\n127.0.0.1\tlocalhost\n", ret);
    return -1;
  }
  return 0;
}

static int
test_aug_insert_0_cleanup (guestfs_h *g)
{
  int ret3914;
  ret3914 = guestfs_aug_close (g);
  if (ret3914 == -1)
    return -1;
  return 0;
}

static int test_aug_set_0_skip (void);
static int test_aug_set_0_perform (guestfs_h *);
static int test_aug_set_0_cleanup (guestfs_h *);

static int
test_aug_set_0 (guestfs_h *g)
{
  if (test_aug_set_0_skip ()) {
    skipped ("test_aug_set_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  int ret = test_aug_set_0_perform (g);
  if (test_aug_set_0_cleanup (g) == -1) {
    fprintf (stderr, "%s (%d): unexpected error during test cleanups\n",
             "aug_set", 0);
    return -1;
  }
  return ret;
}

static int
test_aug_set_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "aug_set") == NULL;
  str = getenv ("SKIP_TEST_AUG_SET_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_AUG_SET");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_aug_set_0_perform (guestfs_h *g)
{
  /* TestResultString for aug_set (0) */
  const char *arg3917 = "/etc";
  int ret3916;
  ret3916 = guestfs_mkdir (g, arg3917);
  if (ret3916 == -1)
    return -1;
  const char *arg3920 = "/etc/hostname";
  const char *arg3921 = "test.example.org";
  size_t arg3921_size = 16;
  int ret3919;
  ret3919 = guestfs_write (g, arg3920, arg3921, arg3921_size);
  if (ret3919 == -1)
    return -1;
  const char *arg3924 = "/";
  int ret3923;
  ret3923 = guestfs_aug_init (g, arg3924, 0);
  if (ret3923 == -1)
    return -1;
  const char *arg3928 = "/files/etc/hostname/hostname";
  const char *arg3929 = "replace.example.com";
  int ret3927;
  ret3927 = guestfs_aug_set (g, arg3928, arg3929);
  if (ret3927 == -1)
    return -1;
  const char *arg3931 = "/files/etc/hostname/hostname";
  CLEANUP_FREE char *ret;
  ret = guestfs_aug_get (g, arg3931);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "replace.example.com")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_aug_set_0", "aug_get", "replace.example.com", ret);
    return -1;
  }
  return 0;
}

static int
test_aug_set_0_cleanup (guestfs_h *g)
{
  int ret3933;
  ret3933 = guestfs_aug_close (g);
  if (ret3933 == -1)
    return -1;
  return 0;
}

static int test_aug_init_0_skip (void);
static int test_aug_init_0_perform (guestfs_h *);
static int test_aug_init_0_cleanup (guestfs_h *);

static int
test_aug_init_0 (guestfs_h *g)
{
  if (test_aug_init_0_skip ()) {
    skipped ("test_aug_init_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  int ret = test_aug_init_0_perform (g);
  if (test_aug_init_0_cleanup (g) == -1) {
    fprintf (stderr, "%s (%d): unexpected error during test cleanups\n",
             "aug_init", 0);
    return -1;
  }
  return ret;
}

static int
test_aug_init_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "aug_init") == NULL;
  str = getenv ("SKIP_TEST_AUG_INIT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_AUG_INIT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_aug_init_0_perform (guestfs_h *g)
{
  /* TestResultString for aug_init (0) */
  const char *arg3936 = "/etc";
  int ret3935;
  ret3935 = guestfs_mkdir (g, arg3936);
  if (ret3935 == -1)
    return -1;
  const char *arg3939 = "/etc/hostname";
  const char *arg3940 = "test.example.org";
  size_t arg3940_size = 16;
  int ret3938;
  ret3938 = guestfs_write (g, arg3939, arg3940, arg3940_size);
  if (ret3938 == -1)
    return -1;
  const char *arg3943 = "/";
  int ret3942;
  ret3942 = guestfs_aug_init (g, arg3943, 0);
  if (ret3942 == -1)
    return -1;
  const char *arg3946 = "/files/etc/hostname/hostname";
  CLEANUP_FREE char *ret;
  ret = guestfs_aug_get (g, arg3946);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "test.example.org")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_aug_init_0", "aug_get", "test.example.org", ret);
    return -1;
  }
  return 0;
}

static int
test_aug_init_0_cleanup (guestfs_h *g)
{
  int ret3948;
  ret3948 = guestfs_aug_close (g);
  if (ret3948 == -1)
    return -1;
  return 0;
}

static int test_lvs_0_skip (void);
static int test_lvs_0_perform (guestfs_h *);

static int
test_lvs_0 (guestfs_h *g)
{
  if (test_lvs_0_skip ()) {
    skipped ("test_lvs_0", "environment variable set");
    return 0;
  }

  const char *features3950[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features3950)) {
    skipped ("test_lvs_0", "group %s not available in daemon",
             features3950[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  return test_lvs_0_perform (g);
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
test_lvs_0_perform (guestfs_h *g)
{
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

static int test_lvs_1_skip (void);
static int test_lvs_1_perform (guestfs_h *);

static int
test_lvs_1 (guestfs_h *g)
{
  if (test_lvs_1_skip ()) {
    skipped ("test_lvs_1", "environment variable set");
    return 0;
  }

  const char *features3952[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features3952)) {
    skipped ("test_lvs_1", "group %s not available in daemon",
             features3952[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_lvs_1_perform (g);
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
test_lvs_1_perform (guestfs_h *g)
{
  /* TestResult for lvs (1) */
  const char *arg3953 = "/dev/sda";
  const char *arg3954 = "mbr";
  int ret12;
  ret12 = guestfs_part_init (g, arg3953, arg3954);
  if (ret12 == -1)
    return -1;
  const char *arg3956 = "/dev/sda";
  const char *arg3957 = "p";
  int ret11;
  ret11 = guestfs_part_add (g, arg3956, arg3957, 64, 204799);
  if (ret11 == -1)
    return -1;
  const char *arg3961 = "/dev/sda";
  const char *arg3962 = "p";
  int ret10;
  ret10 = guestfs_part_add (g, arg3961, arg3962, 204800, 409599);
  if (ret10 == -1)
    return -1;
  const char *arg3966 = "/dev/sda";
  const char *arg3967 = "p";
  int ret9;
  ret9 = guestfs_part_add (g, arg3966, arg3967, 409600, -64);
  if (ret9 == -1)
    return -1;
  const char *arg3971 = "/dev/sda1";
  int ret8;
  ret8 = guestfs_pvcreate (g, arg3971);
  if (ret8 == -1)
    return -1;
  const char *arg3973 = "/dev/sda2";
  int ret7;
  ret7 = guestfs_pvcreate (g, arg3973);
  if (ret7 == -1)
    return -1;
  const char *arg3975 = "/dev/sda3";
  int ret6;
  ret6 = guestfs_pvcreate (g, arg3975);
  if (ret6 == -1)
    return -1;
  const char *arg3977 = "VG1";
  const char *arg3978_0 = "/dev/sda1";
  const char *arg3978_1 = "/dev/sda2";
  const char *const arg3978[] = {
    arg3978_0,
    arg3978_1,
    NULL
  };
  int ret5;
  ret5 = guestfs_vgcreate (g, arg3977, (char **) arg3978);
  if (ret5 == -1)
    return -1;
  const char *arg3980 = "VG2";
  const char *arg3981_0 = "/dev/sda3";
  const char *const arg3981[] = {
    arg3981_0,
    NULL
  };
  int ret4;
  ret4 = guestfs_vgcreate (g, arg3980, (char **) arg3981);
  if (ret4 == -1)
    return -1;
  const char *arg3983 = "LV1";
  const char *arg3984 = "VG1";
  int ret3;
  ret3 = guestfs_lvcreate (g, arg3983, arg3984, 50);
  if (ret3 == -1)
    return -1;
  const char *arg3987 = "LV2";
  const char *arg3988 = "VG1";
  int ret2;
  ret2 = guestfs_lvcreate (g, arg3987, arg3988, 50);
  if (ret2 == -1)
    return -1;
  const char *arg3991 = "LV3";
  const char *arg3992 = "VG2";
  int ret1;
  ret1 = guestfs_lvcreate (g, arg3991, arg3992, 50);
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

static int test_vgs_0_skip (void);
static int test_vgs_0_perform (guestfs_h *);

static int
test_vgs_0 (guestfs_h *g)
{
  if (test_vgs_0_skip ()) {
    skipped ("test_vgs_0", "environment variable set");
    return 0;
  }

  const char *features3996[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features3996)) {
    skipped ("test_vgs_0", "group %s not available in daemon",
             features3996[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  return test_vgs_0_perform (g);
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
test_vgs_0_perform (guestfs_h *g)
{
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

static int test_vgs_1_skip (void);
static int test_vgs_1_perform (guestfs_h *);

static int
test_vgs_1 (guestfs_h *g)
{
  if (test_vgs_1_skip ()) {
    skipped ("test_vgs_1", "environment variable set");
    return 0;
  }

  const char *features3998[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features3998)) {
    skipped ("test_vgs_1", "group %s not available in daemon",
             features3998[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_vgs_1_perform (g);
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
test_vgs_1_perform (guestfs_h *g)
{
  /* TestResult for vgs (1) */
  const char *arg3999 = "/dev/sda";
  const char *arg4000 = "mbr";
  int ret9;
  ret9 = guestfs_part_init (g, arg3999, arg4000);
  if (ret9 == -1)
    return -1;
  const char *arg4002 = "/dev/sda";
  const char *arg4003 = "p";
  int ret8;
  ret8 = guestfs_part_add (g, arg4002, arg4003, 64, 204799);
  if (ret8 == -1)
    return -1;
  const char *arg4007 = "/dev/sda";
  const char *arg4008 = "p";
  int ret7;
  ret7 = guestfs_part_add (g, arg4007, arg4008, 204800, 409599);
  if (ret7 == -1)
    return -1;
  const char *arg4012 = "/dev/sda";
  const char *arg4013 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, arg4012, arg4013, 409600, -64);
  if (ret6 == -1)
    return -1;
  const char *arg4017 = "/dev/sda1";
  int ret5;
  ret5 = guestfs_pvcreate (g, arg4017);
  if (ret5 == -1)
    return -1;
  const char *arg4019 = "/dev/sda2";
  int ret4;
  ret4 = guestfs_pvcreate (g, arg4019);
  if (ret4 == -1)
    return -1;
  const char *arg4021 = "/dev/sda3";
  int ret3;
  ret3 = guestfs_pvcreate (g, arg4021);
  if (ret3 == -1)
    return -1;
  const char *arg4023 = "VG1";
  const char *arg4024_0 = "/dev/sda1";
  const char *arg4024_1 = "/dev/sda2";
  const char *const arg4024[] = {
    arg4024_0,
    arg4024_1,
    NULL
  };
  int ret2;
  ret2 = guestfs_vgcreate (g, arg4023, (char **) arg4024);
  if (ret2 == -1)
    return -1;
  const char *arg4026 = "VG2";
  const char *arg4027_0 = "/dev/sda3";
  const char *const arg4027[] = {
    arg4027_0,
    NULL
  };
  int ret1;
  ret1 = guestfs_vgcreate (g, arg4026, (char **) arg4027);
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

static int test_pvs_0_skip (void);
static int test_pvs_0_perform (guestfs_h *);

static int
test_pvs_0 (guestfs_h *g)
{
  if (test_pvs_0_skip ()) {
    skipped ("test_pvs_0", "environment variable set");
    return 0;
  }

  const char *features4030[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features4030)) {
    skipped ("test_pvs_0", "group %s not available in daemon",
             features4030[0]);
    return 0;
  }

  if (init_basic_fs_on_lvm (g) == -1)
    return -1;

  return test_pvs_0_perform (g);
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
test_pvs_0_perform (guestfs_h *g)
{
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

static int test_pvs_1_skip (void);
static int test_pvs_1_perform (guestfs_h *);

static int
test_pvs_1 (guestfs_h *g)
{
  if (test_pvs_1_skip ()) {
    skipped ("test_pvs_1", "environment variable set");
    return 0;
  }

  const char *features4032[] = { "lvm2", NULL };
  if (!guestfs_feature_available (g, (char **) features4032)) {
    skipped ("test_pvs_1", "group %s not available in daemon",
             features4032[0]);
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_pvs_1_perform (g);
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
test_pvs_1_perform (guestfs_h *g)
{
  /* TestResult for pvs (1) */
  const char *arg4033 = "/dev/sda";
  const char *arg4034 = "mbr";
  int ret7;
  ret7 = guestfs_part_init (g, arg4033, arg4034);
  if (ret7 == -1)
    return -1;
  const char *arg4036 = "/dev/sda";
  const char *arg4037 = "p";
  int ret6;
  ret6 = guestfs_part_add (g, arg4036, arg4037, 64, 204799);
  if (ret6 == -1)
    return -1;
  const char *arg4041 = "/dev/sda";
  const char *arg4042 = "p";
  int ret5;
  ret5 = guestfs_part_add (g, arg4041, arg4042, 204800, 409599);
  if (ret5 == -1)
    return -1;
  const char *arg4046 = "/dev/sda";
  const char *arg4047 = "p";
  int ret4;
  ret4 = guestfs_part_add (g, arg4046, arg4047, 409600, -64);
  if (ret4 == -1)
    return -1;
  const char *arg4051 = "/dev/sda1";
  int ret3;
  ret3 = guestfs_pvcreate (g, arg4051);
  if (ret3 == -1)
    return -1;
  const char *arg4053 = "/dev/sda2";
  int ret2;
  ret2 = guestfs_pvcreate (g, arg4053);
  if (ret2 == -1)
    return -1;
  const char *arg4055 = "/dev/sda3";
  int ret1;
  ret1 = guestfs_pvcreate (g, arg4055);
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

static int test_list_partitions_0_skip (void);
static int test_list_partitions_0_perform (guestfs_h *);

static int
test_list_partitions_0 (guestfs_h *g)
{
  if (test_list_partitions_0_skip ()) {
    skipped ("test_list_partitions_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_list_partitions_0_perform (g);
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
test_list_partitions_0_perform (guestfs_h *g)
{
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

static int test_list_partitions_1_skip (void);
static int test_list_partitions_1_perform (guestfs_h *);

static int
test_list_partitions_1 (guestfs_h *g)
{
  if (test_list_partitions_1_skip ()) {
    skipped ("test_list_partitions_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_list_partitions_1_perform (g);
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
test_list_partitions_1_perform (guestfs_h *g)
{
  /* TestResult for list_partitions (1) */
  const char *arg4059 = "/dev/sda";
  const char *arg4060 = "mbr";
  int ret4;
  ret4 = guestfs_part_init (g, arg4059, arg4060);
  if (ret4 == -1)
    return -1;
  const char *arg4062 = "/dev/sda";
  const char *arg4063 = "p";
  int ret3;
  ret3 = guestfs_part_add (g, arg4062, arg4063, 64, 204799);
  if (ret3 == -1)
    return -1;
  const char *arg4067 = "/dev/sda";
  const char *arg4068 = "p";
  int ret2;
  ret2 = guestfs_part_add (g, arg4067, arg4068, 204800, 409599);
  if (ret2 == -1)
    return -1;
  const char *arg4072 = "/dev/sda";
  const char *arg4073 = "p";
  int ret1;
  ret1 = guestfs_part_add (g, arg4072, arg4073, 409600, -64);
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

static int test_list_devices_0_skip (void);
static int test_list_devices_0_perform (guestfs_h *);

static int
test_list_devices_0 (guestfs_h *g)
{
  if (test_list_devices_0_skip ()) {
    skipped ("test_list_devices_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_list_devices_0_perform (g);
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
test_list_devices_0_perform (guestfs_h *g)
{
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

static int test_touch_0_skip (void);
static int test_touch_0_perform (guestfs_h *);

static int
test_touch_0 (guestfs_h *g)
{
  if (test_touch_0_skip ()) {
    skipped ("test_touch_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_touch_0_perform (g);
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
test_touch_0_perform (guestfs_h *g)
{
  /* TestResultTrue for touch (0) */
  const char *arg4080 = "/touch";
  int ret4079;
  ret4079 = guestfs_touch (g, arg4080);
  if (ret4079 == -1)
    return -1;
  const char *arg4082 = "/touch";
  int ret;
  ret = guestfs_exists (g, arg4082);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_touch_0", "exists");
    return -1;
  }
  return 0;
}

static int test_sync_0_skip (void);
static int test_sync_0_perform (guestfs_h *);

static int
test_sync_0 (guestfs_h *g)
{
  if (test_sync_0_skip ()) {
    skipped ("test_sync_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_sync_0_perform (g);
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
test_sync_0_perform (guestfs_h *g)
{
  /* TestRun for sync (0) */
  int ret4084;
  ret4084 = guestfs_sync (g);
  if (ret4084 == -1)
    return -1;
  return 0;
}

static int test_mount_0_skip (void);
static int test_mount_0_perform (guestfs_h *);

static int
test_mount_0 (guestfs_h *g)
{
  if (test_mount_0_skip ()) {
    skipped ("test_mount_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_mount_0_perform (g);
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
test_mount_0_perform (guestfs_h *g)
{
  /* TestResultString for mount (0) */
  const char *arg4087 = "/dev/sda";
  const char *arg4088 = "mbr";
  int ret4086;
  ret4086 = guestfs_part_disk (g, arg4087, arg4088);
  if (ret4086 == -1)
    return -1;
  const char *arg4091 = "ext2";
  const char *arg4092 = "/dev/sda1";
  struct guestfs_mkfs_opts_argv optargs4093;
  optargs4093.bitmask = UINT64_C(0x0);
  int ret4090;
  ret4090 = guestfs_mkfs_opts_argv (g, arg4091, arg4092, &optargs4093);
  if (ret4090 == -1)
    return -1;
  const char *arg4095 = "/dev/sda1";
  const char *arg4096 = "/";
  int ret4094;
  ret4094 = guestfs_mount (g, arg4095, arg4096);
  if (ret4094 == -1)
    return -1;
  const char *arg4099 = "/new";
  const char *arg4100 = "new file contents";
  size_t arg4100_size = 17;
  int ret4098;
  ret4098 = guestfs_write (g, arg4099, arg4100, arg4100_size);
  if (ret4098 == -1)
    return -1;
  const char *arg4102 = "/new";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg4102);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_mount_0", "cat", "new file contents", ret);
    return -1;
  }
  return 0;
}

static int test_feature_available_0_skip (void);
static int test_feature_available_0_perform (guestfs_h *);

static int
test_feature_available_0 (guestfs_h *g)
{
  if (test_feature_available_0_skip ()) {
    skipped ("test_feature_available_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_feature_available_0_perform (g);
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
test_feature_available_0_perform (guestfs_h *g)
{
  /* TestResultTrue for feature_available (0) */
  const char *const arg4104[1] = { NULL };
  int ret;
  ret = guestfs_feature_available (g, (char **) arg4104);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_feature_available_0", "feature_available");
    return -1;
  }
  return 0;
}

static int test_available_0_skip (void);
static int test_available_0_perform (guestfs_h *);

static int
test_available_0 (guestfs_h *g)
{
  if (test_available_0_skip ()) {
    skipped ("test_available_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_available_0_perform (g);
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
test_available_0_perform (guestfs_h *g)
{
  /* TestRun for available (0) */
  const char *const arg4107[1] = { NULL };
  int ret4106;
  ret4106 = guestfs_available (g, (char **) arg4107);
  if (ret4106 == -1)
    return -1;
  return 0;
}

static int test_get_identifier_0_skip (void);
static int test_get_identifier_0_perform (guestfs_h *);

static int
test_get_identifier_0 (guestfs_h *g)
{
  if (test_get_identifier_0_skip ()) {
    skipped ("test_get_identifier_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_get_identifier_0_perform (g);
}

static int
test_get_identifier_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_identifier") == NULL;
  str = getenv ("SKIP_TEST_GET_IDENTIFIER_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_IDENTIFIER");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_identifier_0_perform (guestfs_h *g)
{
  /* TestRun for get_identifier (0) */
  const char *ret4109;
  ret4109 = guestfs_get_identifier (g);
  if (ret4109 == NULL)
      return -1;
  return 0;
}

static int test_c_pointer_0_skip (void);
static int test_c_pointer_0_perform (guestfs_h *);

static int
test_c_pointer_0 (guestfs_h *g)
{
  if (test_c_pointer_0_skip ()) {
    skipped ("test_c_pointer_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_c_pointer_0_perform (g);
}

static int
test_c_pointer_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "c_pointer") == NULL;
  str = getenv ("SKIP_TEST_C_POINTER_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_C_POINTER");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_c_pointer_0_perform (guestfs_h *g)
{
  /* TestRun for c_pointer (0) */
  int64_t ret4111;
  ret4111 = guestfs_c_pointer (g);
  if (ret4111 == -1)
    return -1;
  return 0;
}

static int test_lstat_0_skip (void);
static int test_lstat_0_perform (guestfs_h *);

static int
test_lstat_0 (guestfs_h *g)
{
  if (test_lstat_0_skip ()) {
    skipped ("test_lstat_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_lstat_0_perform (g);
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
test_lstat_0_perform (guestfs_h *g)
{
  /* TestResult for lstat (0) */
  const char *arg4113 = "/empty";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_lstat (g, arg4113);
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

static int test_stat_0_skip (void);
static int test_stat_0_perform (guestfs_h *);

static int
test_stat_0 (guestfs_h *g)
{
  if (test_stat_0_skip ()) {
    skipped ("test_stat_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_stat_0_perform (g);
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
test_stat_0_perform (guestfs_h *g)
{
  /* TestResult for stat (0) */
  const char *arg4115 = "/empty";
  CLEANUP_FREE_STAT struct guestfs_stat *ret;
  ret = guestfs_stat (g, arg4115);
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

static int test_get_backend_settings_0_skip (void);
static int test_get_backend_settings_0_perform (guestfs_h *);

static int
test_get_backend_settings_0 (guestfs_h *g)
{
  if (test_get_backend_settings_0_skip ()) {
    skipped ("test_get_backend_settings_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_get_backend_settings_0_perform (g);
}

static int
test_get_backend_settings_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_backend_settings") == NULL;
  str = getenv ("SKIP_TEST_GET_BACKEND_SETTINGS_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_BACKEND_SETTINGS");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_backend_settings_0_perform (guestfs_h *g)
{
  /* TestRun for get_backend_settings (0) */
  CLEANUP_FREE_STRING_LIST char **ret4117;
  ret4117 = guestfs_get_backend_settings (g);
  if (ret4117 == NULL)
      return -1;
  return 0;
}

static int test_get_program_0_skip (void);
static int test_get_program_0_perform (guestfs_h *);

static int
test_get_program_0 (guestfs_h *g)
{
  if (test_get_program_0_skip ()) {
    skipped ("test_get_program_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_get_program_0_perform (g);
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
test_get_program_0_perform (guestfs_h *g)
{
  /* TestRun for get_program (0) */
  const char *ret4119;
  ret4119 = guestfs_get_program (g);
  if (ret4119 == NULL)
      return -1;
  return 0;
}

static int test_disk_has_backing_file_0_skip (void);
static int test_disk_has_backing_file_0_perform (guestfs_h *);

static int
test_disk_has_backing_file_0 (guestfs_h *g)
{
  if (test_disk_has_backing_file_0_skip ()) {
    skipped ("test_disk_has_backing_file_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_has_backing_file_0_perform (g);
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
test_disk_has_backing_file_0_perform (guestfs_h *g)
{
  /* TestResultFalse for disk_has_backing_file (0) */
  const char *arg4121 = "../../test-data/blank-disks/blank-disk-1s.raw";
  int ret;
  ret = guestfs_disk_has_backing_file (g, arg4121);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_disk_has_backing_file_0", "disk_has_backing_file");
    return -1;
  }
  return 0;
}

static int test_disk_has_backing_file_1_skip (void);
static int test_disk_has_backing_file_1_perform (guestfs_h *);

static int
test_disk_has_backing_file_1 (guestfs_h *g)
{
  if (test_disk_has_backing_file_1_skip ()) {
    skipped ("test_disk_has_backing_file_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_has_backing_file_1_perform (g);
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
test_disk_has_backing_file_1_perform (guestfs_h *g)
{
  /* TestResultFalse for disk_has_backing_file (1) */
  const char *arg4123 = "../../test-data/blank-disks/blank-disk-1s.qcow2";
  int ret;
  ret = guestfs_disk_has_backing_file (g, arg4123);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_disk_has_backing_file_1", "disk_has_backing_file");
    return -1;
  }
  return 0;
}

static int test_disk_has_backing_file_2_skip (void);
static int test_disk_has_backing_file_2_perform (guestfs_h *);

static int
test_disk_has_backing_file_2 (guestfs_h *g)
{
  if (test_disk_has_backing_file_2_skip ()) {
    skipped ("test_disk_has_backing_file_2", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_has_backing_file_2_perform (g);
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
test_disk_has_backing_file_2_perform (guestfs_h *g)
{
  /* TestResultFalse for disk_has_backing_file (2) */
  const char *arg4125 = "../../test-data/blank-disks/blank-disk-1K.raw";
  int ret;
  ret = guestfs_disk_has_backing_file (g, arg4125);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_disk_has_backing_file_2", "disk_has_backing_file");
    return -1;
  }
  return 0;
}

static int test_disk_has_backing_file_3_skip (void);
static int test_disk_has_backing_file_3_perform (guestfs_h *);

static int
test_disk_has_backing_file_3 (guestfs_h *g)
{
  if (test_disk_has_backing_file_3_skip ()) {
    skipped ("test_disk_has_backing_file_3", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_has_backing_file_3_perform (g);
}

static int
test_disk_has_backing_file_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_has_backing_file") == NULL;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_has_backing_file_3_perform (guestfs_h *g)
{
  /* TestResultFalse for disk_has_backing_file (3) */
  const char *arg4127 = "../../test-data/blank-disks/blank-disk-1K.qcow2";
  int ret;
  ret = guestfs_disk_has_backing_file (g, arg4127);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_disk_has_backing_file_3", "disk_has_backing_file");
    return -1;
  }
  return 0;
}

static int test_disk_has_backing_file_4_skip (void);
static int test_disk_has_backing_file_4_perform (guestfs_h *);

static int
test_disk_has_backing_file_4 (guestfs_h *g)
{
  if (test_disk_has_backing_file_4_skip ()) {
    skipped ("test_disk_has_backing_file_4", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_has_backing_file_4_perform (g);
}

static int
test_disk_has_backing_file_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_has_backing_file") == NULL;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_has_backing_file_4_perform (guestfs_h *g)
{
  /* TestResultFalse for disk_has_backing_file (4) */
  const char *arg4129 = "../../test-data/blank-disks/blank-disk-1M.raw";
  int ret;
  ret = guestfs_disk_has_backing_file (g, arg4129);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_disk_has_backing_file_4", "disk_has_backing_file");
    return -1;
  }
  return 0;
}

static int test_disk_has_backing_file_5_skip (void);
static int test_disk_has_backing_file_5_perform (guestfs_h *);

static int
test_disk_has_backing_file_5 (guestfs_h *g)
{
  if (test_disk_has_backing_file_5_skip ()) {
    skipped ("test_disk_has_backing_file_5", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_has_backing_file_5_perform (g);
}

static int
test_disk_has_backing_file_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_has_backing_file") == NULL;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_has_backing_file_5_perform (guestfs_h *g)
{
  /* TestResultFalse for disk_has_backing_file (5) */
  const char *arg4131 = "../../test-data/blank-disks/blank-disk-1M.qcow2";
  int ret;
  ret = guestfs_disk_has_backing_file (g, arg4131);
  if (ret == -1)
    return -1;
  if (ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'false' but it returned 'true'\n",
             "test_disk_has_backing_file_5", "disk_has_backing_file");
    return -1;
  }
  return 0;
}

static int test_disk_has_backing_file_6_skip (void);
static int test_disk_has_backing_file_6_perform (guestfs_h *);

static int
test_disk_has_backing_file_6 (guestfs_h *g)
{
  if (test_disk_has_backing_file_6_skip ()) {
    skipped ("test_disk_has_backing_file_6", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_has_backing_file_6_perform (g);
}

static int
test_disk_has_backing_file_6_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_has_backing_file") == NULL;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE_6");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_HAS_BACKING_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_has_backing_file_6_perform (guestfs_h *g)
{
  /* TestResultTrue for disk_has_backing_file (6) */
  const char *arg4133 = "../../test-data/blank-disks/blank-disk-with-backing.qcow2";
  int ret;
  ret = guestfs_disk_has_backing_file (g, arg4133);
  if (ret == -1)
    return -1;
  if (!ret) {
    fprintf (stderr, "%s: test failed: expected last command %s to return 'true' but it returned 'false'\n",
             "test_disk_has_backing_file_6", "disk_has_backing_file");
    return -1;
  }
  return 0;
}

static int test_disk_virtual_size_0_skip (void);
static int test_disk_virtual_size_0_perform (guestfs_h *);

static int
test_disk_virtual_size_0 (guestfs_h *g)
{
  if (test_disk_virtual_size_0_skip ()) {
    skipped ("test_disk_virtual_size_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_virtual_size_0_perform (g);
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
test_disk_virtual_size_0_perform (guestfs_h *g)
{
  /* TestResult for disk_virtual_size (0) */
  const char *arg4135 = "../../test-data/blank-disks/blank-disk-1s.raw";
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, arg4135);
  if (ret == -1)
    return -1;
  if (! (ret == 512)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_disk_virtual_size_0", "ret == 512");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_disk_virtual_size_1_skip (void);
static int test_disk_virtual_size_1_perform (guestfs_h *);

static int
test_disk_virtual_size_1 (guestfs_h *g)
{
  if (test_disk_virtual_size_1_skip ()) {
    skipped ("test_disk_virtual_size_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_virtual_size_1_perform (g);
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
test_disk_virtual_size_1_perform (guestfs_h *g)
{
  /* TestResult for disk_virtual_size (1) */
  const char *arg4137 = "../../test-data/blank-disks/blank-disk-1s.qcow2";
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, arg4137);
  if (ret == -1)
    return -1;
  if (! (ret == 512)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_disk_virtual_size_1", "ret == 512");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_disk_virtual_size_2_skip (void);
static int test_disk_virtual_size_2_perform (guestfs_h *);

static int
test_disk_virtual_size_2 (guestfs_h *g)
{
  if (test_disk_virtual_size_2_skip ()) {
    skipped ("test_disk_virtual_size_2", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_virtual_size_2_perform (g);
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
test_disk_virtual_size_2_perform (guestfs_h *g)
{
  /* TestResult for disk_virtual_size (2) */
  const char *arg4139 = "../../test-data/blank-disks/blank-disk-1K.raw";
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, arg4139);
  if (ret == -1)
    return -1;
  if (! (ret == 1024)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_disk_virtual_size_2", "ret == 1024");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_disk_virtual_size_3_skip (void);
static int test_disk_virtual_size_3_perform (guestfs_h *);

static int
test_disk_virtual_size_3 (guestfs_h *g)
{
  if (test_disk_virtual_size_3_skip ()) {
    skipped ("test_disk_virtual_size_3", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_virtual_size_3_perform (g);
}

static int
test_disk_virtual_size_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_virtual_size") == NULL;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_virtual_size_3_perform (guestfs_h *g)
{
  /* TestResult for disk_virtual_size (3) */
  const char *arg4141 = "../../test-data/blank-disks/blank-disk-1K.qcow2";
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, arg4141);
  if (ret == -1)
    return -1;
  if (! (ret == 1024)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_disk_virtual_size_3", "ret == 1024");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_disk_virtual_size_4_skip (void);
static int test_disk_virtual_size_4_perform (guestfs_h *);

static int
test_disk_virtual_size_4 (guestfs_h *g)
{
  if (test_disk_virtual_size_4_skip ()) {
    skipped ("test_disk_virtual_size_4", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_virtual_size_4_perform (g);
}

static int
test_disk_virtual_size_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_virtual_size") == NULL;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_virtual_size_4_perform (guestfs_h *g)
{
  /* TestResult for disk_virtual_size (4) */
  const char *arg4143 = "../../test-data/blank-disks/blank-disk-1M.raw";
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, arg4143);
  if (ret == -1)
    return -1;
  if (! (ret == 1024*1024)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_disk_virtual_size_4", "ret == 1024*1024");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_disk_virtual_size_5_skip (void);
static int test_disk_virtual_size_5_perform (guestfs_h *);

static int
test_disk_virtual_size_5 (guestfs_h *g)
{
  if (test_disk_virtual_size_5_skip ()) {
    skipped ("test_disk_virtual_size_5", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_virtual_size_5_perform (g);
}

static int
test_disk_virtual_size_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_virtual_size") == NULL;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_virtual_size_5_perform (guestfs_h *g)
{
  /* TestResult for disk_virtual_size (5) */
  const char *arg4145 = "../../test-data/blank-disks/blank-disk-1M.qcow2";
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, arg4145);
  if (ret == -1)
    return -1;
  if (! (ret == 1024*1024)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_disk_virtual_size_5", "ret == 1024*1024");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_disk_virtual_size_6_skip (void);
static int test_disk_virtual_size_6_perform (guestfs_h *);

static int
test_disk_virtual_size_6 (guestfs_h *g)
{
  if (test_disk_virtual_size_6_skip ()) {
    skipped ("test_disk_virtual_size_6", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_virtual_size_6_perform (g);
}

static int
test_disk_virtual_size_6_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_virtual_size") == NULL;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE_6");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_VIRTUAL_SIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_virtual_size_6_perform (guestfs_h *g)
{
  /* TestResult for disk_virtual_size (6) */
  const char *arg4147 = "../../test-data/blank-disks/blank-disk-with-backing.qcow2";
  int64_t ret;
  ret = guestfs_disk_virtual_size (g, arg4147);
  if (ret == -1)
    return -1;
  if (! (ret == 1024*1024)) {
    fprintf (stderr, "%s: test failed: expression false: %s\n",
             "test_disk_virtual_size_6", "ret == 1024*1024");
    if (!guestfs_get_trace (g))
      fprintf (stderr, "Set LIBGUESTFS_TRACE=1 to see values returned from API calls.\n");
    return -1;
  }
  return 0;
}

static int test_disk_format_0_skip (void);
static int test_disk_format_0_perform (guestfs_h *);

static int
test_disk_format_0 (guestfs_h *g)
{
  if (test_disk_format_0_skip ()) {
    skipped ("test_disk_format_0", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_format_0_perform (g);
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
test_disk_format_0_perform (guestfs_h *g)
{
  /* TestResultString for disk_format (0) */
  const char *arg4149 = "../../test-data/blank-disks/blank-disk-1s.raw";
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, arg4149);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "raw")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_disk_format_0", "disk_format", "raw", ret);
    return -1;
  }
  return 0;
}

static int test_disk_format_1_skip (void);
static int test_disk_format_1_perform (guestfs_h *);

static int
test_disk_format_1 (guestfs_h *g)
{
  if (test_disk_format_1_skip ()) {
    skipped ("test_disk_format_1", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_format_1_perform (g);
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
test_disk_format_1_perform (guestfs_h *g)
{
  /* TestResultString for disk_format (1) */
  const char *arg4151 = "../../test-data/blank-disks/blank-disk-1s.qcow2";
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, arg4151);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "qcow2")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_disk_format_1", "disk_format", "qcow2", ret);
    return -1;
  }
  return 0;
}

static int test_disk_format_2_skip (void);
static int test_disk_format_2_perform (guestfs_h *);

static int
test_disk_format_2 (guestfs_h *g)
{
  if (test_disk_format_2_skip ()) {
    skipped ("test_disk_format_2", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_format_2_perform (g);
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
test_disk_format_2_perform (guestfs_h *g)
{
  /* TestResultString for disk_format (2) */
  const char *arg4153 = "../../test-data/blank-disks/blank-disk-1K.raw";
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, arg4153);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "raw")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_disk_format_2", "disk_format", "raw", ret);
    return -1;
  }
  return 0;
}

static int test_disk_format_3_skip (void);
static int test_disk_format_3_perform (guestfs_h *);

static int
test_disk_format_3 (guestfs_h *g)
{
  if (test_disk_format_3_skip ()) {
    skipped ("test_disk_format_3", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_format_3_perform (g);
}

static int
test_disk_format_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_format") == NULL;
  str = getenv ("SKIP_TEST_DISK_FORMAT_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_FORMAT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_format_3_perform (guestfs_h *g)
{
  /* TestResultString for disk_format (3) */
  const char *arg4155 = "../../test-data/blank-disks/blank-disk-1K.qcow2";
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, arg4155);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "qcow2")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_disk_format_3", "disk_format", "qcow2", ret);
    return -1;
  }
  return 0;
}

static int test_disk_format_4_skip (void);
static int test_disk_format_4_perform (guestfs_h *);

static int
test_disk_format_4 (guestfs_h *g)
{
  if (test_disk_format_4_skip ()) {
    skipped ("test_disk_format_4", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_format_4_perform (g);
}

static int
test_disk_format_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_format") == NULL;
  str = getenv ("SKIP_TEST_DISK_FORMAT_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_FORMAT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_format_4_perform (guestfs_h *g)
{
  /* TestResultString for disk_format (4) */
  const char *arg4157 = "../../test-data/blank-disks/blank-disk-1M.raw";
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, arg4157);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "raw")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_disk_format_4", "disk_format", "raw", ret);
    return -1;
  }
  return 0;
}

static int test_disk_format_5_skip (void);
static int test_disk_format_5_perform (guestfs_h *);

static int
test_disk_format_5 (guestfs_h *g)
{
  if (test_disk_format_5_skip ()) {
    skipped ("test_disk_format_5", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_format_5_perform (g);
}

static int
test_disk_format_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_format") == NULL;
  str = getenv ("SKIP_TEST_DISK_FORMAT_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_FORMAT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_format_5_perform (guestfs_h *g)
{
  /* TestResultString for disk_format (5) */
  const char *arg4159 = "../../test-data/blank-disks/blank-disk-1M.qcow2";
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, arg4159);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "qcow2")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_disk_format_5", "disk_format", "qcow2", ret);
    return -1;
  }
  return 0;
}

static int test_disk_format_6_skip (void);
static int test_disk_format_6_perform (guestfs_h *);

static int
test_disk_format_6 (guestfs_h *g)
{
  if (test_disk_format_6_skip ()) {
    skipped ("test_disk_format_6", "environment variable set");
    return 0;
  }

  if (init_empty (g) == -1)
    return -1;

  return test_disk_format_6_perform (g);
}

static int
test_disk_format_6_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "disk_format") == NULL;
  str = getenv ("SKIP_TEST_DISK_FORMAT_6");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_DISK_FORMAT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_disk_format_6_perform (guestfs_h *g)
{
  /* TestResultString for disk_format (6) */
  const char *arg4161 = "../../test-data/blank-disks/blank-disk-with-backing.qcow2";
  CLEANUP_FREE char *ret;
  ret = guestfs_disk_format (g, arg4161);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "qcow2")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_disk_format_6", "disk_format", "qcow2", ret);
    return -1;
  }
  return 0;
}

static int test_ls_0_skip (void);
static int test_ls_0_perform (guestfs_h *);

static int
test_ls_0 (guestfs_h *g)
{
  if (test_ls_0_skip ()) {
    skipped ("test_ls_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_ls_0_perform (g);
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
test_ls_0_perform (guestfs_h *g)
{
  /* TestResult for ls (0) */
  const char *arg4163 = "/ls";
  int ret4;
  ret4 = guestfs_mkdir (g, arg4163);
  if (ret4 == -1)
    return -1;
  const char *arg4165 = "/ls/new";
  int ret3;
  ret3 = guestfs_touch (g, arg4165);
  if (ret3 == -1)
    return -1;
  const char *arg4167 = "/ls/newer";
  int ret2;
  ret2 = guestfs_touch (g, arg4167);
  if (ret2 == -1)
    return -1;
  const char *arg4169 = "/ls/newest";
  int ret1;
  ret1 = guestfs_touch (g, arg4169);
  if (ret1 == -1)
    return -1;
  const char *arg4171 = "/ls";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_ls (g, arg4171);
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

static int test_write_append_0_skip (void);
static int test_write_append_0_perform (guestfs_h *);

static int
test_write_append_0 (guestfs_h *g)
{
  if (test_write_append_0_skip ()) {
    skipped ("test_write_append_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_write_append_0_perform (g);
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
test_write_append_0_perform (guestfs_h *g)
{
  /* TestResultString for write_append (0) */
  const char *arg4174 = "/write_append";
  const char *arg4175 = "line1\n";
  size_t arg4175_size = 6;
  int ret4173;
  ret4173 = guestfs_write (g, arg4174, arg4175, arg4175_size);
  if (ret4173 == -1)
    return -1;
  const char *arg4178 = "/write_append";
  const char *arg4179 = "line2\n";
  size_t arg4179_size = 6;
  int ret4177;
  ret4177 = guestfs_write_append (g, arg4178, arg4179, arg4179_size);
  if (ret4177 == -1)
    return -1;
  const char *arg4182 = "/write_append";
  const char *arg4183 = "line3a";
  size_t arg4183_size = 6;
  int ret4181;
  ret4181 = guestfs_write_append (g, arg4182, arg4183, arg4183_size);
  if (ret4181 == -1)
    return -1;
  const char *arg4186 = "/write_append";
  const char *arg4187 = "line3b\n";
  size_t arg4187_size = 7;
  int ret4185;
  ret4185 = guestfs_write_append (g, arg4186, arg4187, arg4187_size);
  if (ret4185 == -1)
    return -1;
  const char *arg4189 = "/write_append";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg4189);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "line1\nline2\nline3aline3b\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_append_0", "cat", "line1\nline2\nline3aline3b\n", ret);
    return -1;
  }
  return 0;
}

static int test_write_0_skip (void);
static int test_write_0_perform (guestfs_h *);

static int
test_write_0 (guestfs_h *g)
{
  if (test_write_0_skip ()) {
    skipped ("test_write_0", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_write_0_perform (g);
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
test_write_0_perform (guestfs_h *g)
{
  /* TestResultString for write (0) */
  const char *arg4192 = "/write";
  const char *arg4193 = "new file contents";
  size_t arg4193_size = 17;
  int ret4191;
  ret4191 = guestfs_write (g, arg4192, arg4193, arg4193_size);
  if (ret4191 == -1)
    return -1;
  const char *arg4195 = "/write";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg4195);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "new file contents")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_0", "cat", "new file contents", ret);
    return -1;
  }
  return 0;
}

static int test_write_1_skip (void);
static int test_write_1_perform (guestfs_h *);

static int
test_write_1 (guestfs_h *g)
{
  if (test_write_1_skip ()) {
    skipped ("test_write_1", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_write_1_perform (g);
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
test_write_1_perform (guestfs_h *g)
{
  /* TestResultString for write (1) */
  const char *arg4198 = "/write2";
  const char *arg4199 = "\nnew file contents\n";
  size_t arg4199_size = 19;
  int ret4197;
  ret4197 = guestfs_write (g, arg4198, arg4199, arg4199_size);
  if (ret4197 == -1)
    return -1;
  const char *arg4201 = "/write2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg4201);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\nnew file contents\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_1", "cat", "\nnew file contents\n", ret);
    return -1;
  }
  return 0;
}

static int test_write_2_skip (void);
static int test_write_2_perform (guestfs_h *);

static int
test_write_2 (guestfs_h *g)
{
  if (test_write_2_skip ()) {
    skipped ("test_write_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_write_2_perform (g);
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
test_write_2_perform (guestfs_h *g)
{
  /* TestResultString for write (2) */
  const char *arg4204 = "/write3";
  const char *arg4205 = "\n\n";
  size_t arg4205_size = 2;
  int ret4203;
  ret4203 = guestfs_write (g, arg4204, arg4205, arg4205_size);
  if (ret4203 == -1)
    return -1;
  const char *arg4207 = "/write3";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg4207);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_2", "cat", "\n\n", ret);
    return -1;
  }
  return 0;
}

static int test_write_3_skip (void);
static int test_write_3_perform (guestfs_h *);

static int
test_write_3 (guestfs_h *g)
{
  if (test_write_3_skip ()) {
    skipped ("test_write_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_write_3_perform (g);
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
test_write_3_perform (guestfs_h *g)
{
  /* TestResultString for write (3) */
  const char *arg4210 = "/write4";
  const char *arg4211 = "";
  size_t arg4211_size = 0;
  int ret4209;
  ret4209 = guestfs_write (g, arg4210, arg4211, arg4211_size);
  if (ret4209 == -1)
    return -1;
  const char *arg4213 = "/write4";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg4213);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_3", "cat", "", ret);
    return -1;
  }
  return 0;
}

static int test_write_4_skip (void);
static int test_write_4_perform (guestfs_h *);

static int
test_write_4 (guestfs_h *g)
{
  if (test_write_4_skip ()) {
    skipped ("test_write_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_write_4_perform (g);
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
test_write_4_perform (guestfs_h *g)
{
  /* TestResultString for write (4) */
  const char *arg4216 = "/write5";
  const char *arg4217 = "\n\n\n";
  size_t arg4217_size = 3;
  int ret4215;
  ret4215 = guestfs_write (g, arg4216, arg4217, arg4217_size);
  if (ret4215 == -1)
    return -1;
  const char *arg4219 = "/write5";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg4219);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n\n\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_4", "cat", "\n\n\n", ret);
    return -1;
  }
  return 0;
}

static int test_write_5_skip (void);
static int test_write_5_perform (guestfs_h *);

static int
test_write_5 (guestfs_h *g)
{
  if (test_write_5_skip ()) {
    skipped ("test_write_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_write_5_perform (g);
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
test_write_5_perform (guestfs_h *g)
{
  /* TestResultString for write (5) */
  const char *arg4222 = "/write6";
  const char *arg4223 = "\n";
  size_t arg4223_size = 1;
  int ret4221;
  ret4221 = guestfs_write (g, arg4222, arg4223, arg4223_size);
  if (ret4221 == -1)
    return -1;
  const char *arg4225 = "/write6";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg4225);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_write_5", "cat", "\n", ret);
    return -1;
  }
  return 0;
}

static int test_read_lines_0_skip (void);
static int test_read_lines_0_perform (guestfs_h *);

static int
test_read_lines_0 (guestfs_h *g)
{
  if (test_read_lines_0_skip ()) {
    skipped ("test_read_lines_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_read_lines_0_perform (g);
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
test_read_lines_0_perform (guestfs_h *g)
{
  /* TestResult for read_lines (0) */
  const char *arg4227 = "/known-4";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, arg4227);
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

static int test_read_lines_1_skip (void);
static int test_read_lines_1_perform (guestfs_h *);

static int
test_read_lines_1 (guestfs_h *g)
{
  if (test_read_lines_1_skip ()) {
    skipped ("test_read_lines_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_read_lines_1_perform (g);
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
test_read_lines_1_perform (guestfs_h *g)
{
  /* TestResult for read_lines (1) */
  const char *arg4229 = "/empty";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, arg4229);
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

static int test_read_lines_2_skip (void);
static int test_read_lines_2_perform (guestfs_h *);

static int
test_read_lines_2 (guestfs_h *g)
{
  if (test_read_lines_2_skip ()) {
    skipped ("test_read_lines_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_read_lines_2_perform (g);
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
test_read_lines_2_perform (guestfs_h *g)
{
  /* TestResult for read_lines (2) */
  const char *arg4231 = "/read_lines1";
  const char *arg4232 = "\n";
  size_t arg4232_size = 1;
  int ret1;
  ret1 = guestfs_write (g, arg4231, arg4232, arg4232_size);
  if (ret1 == -1)
    return -1;
  const char *arg4234 = "/read_lines1";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, arg4234);
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

static int test_read_lines_3_skip (void);
static int test_read_lines_3_perform (guestfs_h *);

static int
test_read_lines_3 (guestfs_h *g)
{
  if (test_read_lines_3_skip ()) {
    skipped ("test_read_lines_3", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_read_lines_3_perform (g);
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
test_read_lines_3_perform (guestfs_h *g)
{
  /* TestResult for read_lines (3) */
  const char *arg4236 = "/read_lines2";
  const char *arg4237 = "\r\n";
  size_t arg4237_size = 2;
  int ret1;
  ret1 = guestfs_write (g, arg4236, arg4237, arg4237_size);
  if (ret1 == -1)
    return -1;
  const char *arg4239 = "/read_lines2";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, arg4239);
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

static int test_read_lines_4_skip (void);
static int test_read_lines_4_perform (guestfs_h *);

static int
test_read_lines_4 (guestfs_h *g)
{
  if (test_read_lines_4_skip ()) {
    skipped ("test_read_lines_4", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_read_lines_4_perform (g);
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
test_read_lines_4_perform (guestfs_h *g)
{
  /* TestResult for read_lines (4) */
  const char *arg4241 = "/read_lines3";
  const char *arg4242 = "\n\r\n";
  size_t arg4242_size = 3;
  int ret1;
  ret1 = guestfs_write (g, arg4241, arg4242, arg4242_size);
  if (ret1 == -1)
    return -1;
  const char *arg4244 = "/read_lines3";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, arg4244);
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

static int test_read_lines_5_skip (void);
static int test_read_lines_5_perform (guestfs_h *);

static int
test_read_lines_5 (guestfs_h *g)
{
  if (test_read_lines_5_skip ()) {
    skipped ("test_read_lines_5", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_read_lines_5_perform (g);
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
test_read_lines_5_perform (guestfs_h *g)
{
  /* TestResult for read_lines (5) */
  const char *arg4246 = "/read_lines4";
  const char *arg4247 = "a";
  size_t arg4247_size = 1;
  int ret1;
  ret1 = guestfs_write (g, arg4246, arg4247, arg4247_size);
  if (ret1 == -1)
    return -1;
  const char *arg4249 = "/read_lines4";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, arg4249);
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

static int test_read_lines_6_skip (void);
static int test_read_lines_6_perform (guestfs_h *);

static int
test_read_lines_6 (guestfs_h *g)
{
  if (test_read_lines_6_skip ()) {
    skipped ("test_read_lines_6", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_read_lines_6_perform (g);
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
test_read_lines_6_perform (guestfs_h *g)
{
  /* TestResult for read_lines (6) */
  const char *arg4251 = "/read_lines5";
  const char *arg4252 = "a\nb";
  size_t arg4252_size = 3;
  int ret1;
  ret1 = guestfs_write (g, arg4251, arg4252, arg4252_size);
  if (ret1 == -1)
    return -1;
  const char *arg4254 = "/read_lines5";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, arg4254);
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

static int test_read_lines_7_skip (void);
static int test_read_lines_7_perform (guestfs_h *);

static int
test_read_lines_7 (guestfs_h *g)
{
  if (test_read_lines_7_skip ()) {
    skipped ("test_read_lines_7", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_read_lines_7_perform (g);
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
test_read_lines_7_perform (guestfs_h *g)
{
  /* TestResult for read_lines (7) */
  const char *arg4256 = "/read_lines6";
  const char *arg4257 = "a\nb\n";
  size_t arg4257_size = 4;
  int ret1;
  ret1 = guestfs_write (g, arg4256, arg4257, arg4257_size);
  if (ret1 == -1)
    return -1;
  const char *arg4259 = "/read_lines6";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, arg4259);
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

static int test_read_lines_8_skip (void);
static int test_read_lines_8_perform (guestfs_h *);

static int
test_read_lines_8 (guestfs_h *g)
{
  if (test_read_lines_8_skip ()) {
    skipped ("test_read_lines_8", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_read_lines_8_perform (g);
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
test_read_lines_8_perform (guestfs_h *g)
{
  /* TestResult for read_lines (8) */
  const char *arg4261 = "/read_lines7";
  const char *arg4262 = "a\nb\r\n";
  size_t arg4262_size = 5;
  int ret1;
  ret1 = guestfs_write (g, arg4261, arg4262, arg4262_size);
  if (ret1 == -1)
    return -1;
  const char *arg4264 = "/read_lines7";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, arg4264);
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

static int test_read_lines_9_skip (void);
static int test_read_lines_9_perform (guestfs_h *);

static int
test_read_lines_9 (guestfs_h *g)
{
  if (test_read_lines_9_skip ()) {
    skipped ("test_read_lines_9", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_read_lines_9_perform (g);
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
test_read_lines_9_perform (guestfs_h *g)
{
  /* TestResult for read_lines (9) */
  const char *arg4266 = "/read_lines8";
  const char *arg4267 = "a\nb\r\n\n";
  size_t arg4267_size = 6;
  int ret1;
  ret1 = guestfs_write (g, arg4266, arg4267, arg4267_size);
  if (ret1 == -1)
    return -1;
  const char *arg4269 = "/read_lines8";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_read_lines (g, arg4269);
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

static int test_read_file_0_skip (void);
static int test_read_file_0_perform (guestfs_h *);

static int
test_read_file_0 (guestfs_h *g)
{
  if (test_read_file_0_skip ()) {
    skipped ("test_read_file_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_read_file_0_perform (g);
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
test_read_file_0_perform (guestfs_h *g)
{
  /* TestResult for read_file (0) */
  const char *arg4271 = "/known-4";
  CLEANUP_FREE char *ret;
  size_t size;
  ret = guestfs_read_file (g, arg4271, &size);
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

static int test_find_0_skip (void);
static int test_find_0_perform (guestfs_h *);

static int
test_find_0 (guestfs_h *g)
{
  if (test_find_0_skip ()) {
    skipped ("test_find_0", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_find_0_perform (g);
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
test_find_0_perform (guestfs_h *g)
{
  /* TestResult for find (0) */
  const char *arg4273 = "/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, arg4273);
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

static int test_find_1_skip (void);
static int test_find_1_perform (guestfs_h *);

static int
test_find_1 (guestfs_h *g)
{
  if (test_find_1_skip ()) {
    skipped ("test_find_1", "environment variable set");
    return 0;
  }

  if (init_basic_fs (g) == -1)
    return -1;

  return test_find_1_perform (g);
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
test_find_1_perform (guestfs_h *g)
{
  /* TestResult for find (1) */
  const char *arg4275 = "/a";
  int ret3;
  ret3 = guestfs_touch (g, arg4275);
  if (ret3 == -1)
    return -1;
  const char *arg4277 = "/b";
  int ret2;
  ret2 = guestfs_mkdir (g, arg4277);
  if (ret2 == -1)
    return -1;
  const char *arg4279 = "/b/c";
  int ret1;
  ret1 = guestfs_touch (g, arg4279);
  if (ret1 == -1)
    return -1;
  const char *arg4281 = "/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, arg4281);
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

static int test_find_2_skip (void);
static int test_find_2_perform (guestfs_h *);

static int
test_find_2 (guestfs_h *g)
{
  if (test_find_2_skip ()) {
    skipped ("test_find_2", "environment variable set");
    return 0;
  }

  if (init_scratch_fs (g) == -1)
    return -1;

  return test_find_2_perform (g);
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
test_find_2_perform (guestfs_h *g)
{
  /* TestResult for find (2) */
  const char *arg4283 = "/find/b/c";
  int ret2;
  ret2 = guestfs_mkdir_p (g, arg4283);
  if (ret2 == -1)
    return -1;
  const char *arg4285 = "/find/b/c/d";
  int ret1;
  ret1 = guestfs_touch (g, arg4285);
  if (ret1 == -1)
    return -1;
  const char *arg4287 = "/find/b/";
  CLEANUP_FREE_STRING_LIST char **ret;
  ret = guestfs_find (g, arg4287);
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

static int test_cat_0_skip (void);
static int test_cat_0_perform (guestfs_h *);

static int
test_cat_0 (guestfs_h *g)
{
  if (test_cat_0_skip ()) {
    skipped ("test_cat_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_cat_0_perform (g);
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
test_cat_0_perform (guestfs_h *g)
{
  /* TestResultString for cat (0) */
  const char *arg4289 = "/known-2";
  CLEANUP_FREE char *ret;
  ret = guestfs_cat (g, arg4289);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "abcdef\n")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_cat_0", "cat", "abcdef\n", ret);
    return -1;
  }
  return 0;
}

static int test_get_backend_0_skip (void);
static int test_get_backend_0_perform (guestfs_h *);

static int
test_get_backend_0 (guestfs_h *g)
{
  if (test_get_backend_0_skip ()) {
    skipped ("test_get_backend_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_get_backend_0_perform (g);
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
test_get_backend_0_perform (guestfs_h *g)
{
  /* TestRun for get_backend (0) */
  CLEANUP_FREE char *ret4291;
  ret4291 = guestfs_get_backend (g);
  if (ret4291 == NULL)
      return -1;
  return 0;
}

static int test_get_attach_method_0_skip (void);
static int test_get_attach_method_0_perform (guestfs_h *);

static int
test_get_attach_method_0 (guestfs_h *g)
{
  if (test_get_attach_method_0_skip ()) {
    skipped ("test_get_attach_method_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_get_attach_method_0_perform (g);
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
test_get_attach_method_0_perform (guestfs_h *g)
{
  /* TestRun for get_attach_method (0) */
  CLEANUP_FREE char *ret4293;
  ret4293 = guestfs_get_attach_method (g);
  if (ret4293 == NULL)
      return -1;
  return 0;
}

static int test_file_architecture_0_skip (void);
static int test_file_architecture_0_perform (guestfs_h *);

static int
test_file_architecture_0 (guestfs_h *g)
{
  if (test_file_architecture_0_skip ()) {
    skipped ("test_file_architecture_0", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_0_perform (g);
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
test_file_architecture_0_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (0) */
  const char *arg4295 = "/bin-aarch64-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4295);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "aarch64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_0", "file_architecture", "aarch64", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_1_skip (void);
static int test_file_architecture_1_perform (guestfs_h *);

static int
test_file_architecture_1 (guestfs_h *g)
{
  if (test_file_architecture_1_skip ()) {
    skipped ("test_file_architecture_1", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_1_perform (g);
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
test_file_architecture_1_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (1) */
  const char *arg4297 = "/bin-armv7-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4297);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "arm")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_1", "file_architecture", "arm", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_2_skip (void);
static int test_file_architecture_2_perform (guestfs_h *);

static int
test_file_architecture_2 (guestfs_h *g)
{
  if (test_file_architecture_2_skip ()) {
    skipped ("test_file_architecture_2", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_2_perform (g);
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
test_file_architecture_2_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (2) */
  const char *arg4299 = "/bin-i586-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4299);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "i386")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_2", "file_architecture", "i386", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_3_skip (void);
static int test_file_architecture_3_perform (guestfs_h *);

static int
test_file_architecture_3 (guestfs_h *g)
{
  if (test_file_architecture_3_skip ()) {
    skipped ("test_file_architecture_3", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_3_perform (g);
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
test_file_architecture_3_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (3) */
  const char *arg4301 = "/bin-ppc64-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4301);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "ppc64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_3", "file_architecture", "ppc64", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_4_skip (void);
static int test_file_architecture_4_perform (guestfs_h *);

static int
test_file_architecture_4 (guestfs_h *g)
{
  if (test_file_architecture_4_skip ()) {
    skipped ("test_file_architecture_4", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_4_perform (g);
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
test_file_architecture_4_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (4) */
  const char *arg4303 = "/bin-ppc64le-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4303);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "ppc64le")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_4", "file_architecture", "ppc64le", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_5_skip (void);
static int test_file_architecture_5_perform (guestfs_h *);

static int
test_file_architecture_5 (guestfs_h *g)
{
  if (test_file_architecture_5_skip ()) {
    skipped ("test_file_architecture_5", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_5_perform (g);
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
test_file_architecture_5_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (5) */
  const char *arg4305 = "/bin-sparc-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4305);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "sparc")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_5", "file_architecture", "sparc", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_6_skip (void);
static int test_file_architecture_6_perform (guestfs_h *);

static int
test_file_architecture_6 (guestfs_h *g)
{
  if (test_file_architecture_6_skip ()) {
    skipped ("test_file_architecture_6", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_6_perform (g);
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
test_file_architecture_6_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (6) */
  const char *arg4307 = "/bin-win32.exe";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4307);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "i386")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_6", "file_architecture", "i386", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_7_skip (void);
static int test_file_architecture_7_perform (guestfs_h *);

static int
test_file_architecture_7 (guestfs_h *g)
{
  if (test_file_architecture_7_skip ()) {
    skipped ("test_file_architecture_7", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_7_perform (g);
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
test_file_architecture_7_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (7) */
  const char *arg4309 = "/bin-win64.exe";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4309);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "x86_64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_7", "file_architecture", "x86_64", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_8_skip (void);
static int test_file_architecture_8_perform (guestfs_h *);

static int
test_file_architecture_8 (guestfs_h *g)
{
  if (test_file_architecture_8_skip ()) {
    skipped ("test_file_architecture_8", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_8_perform (g);
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
test_file_architecture_8_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (8) */
  const char *arg4311 = "/bin-x86_64-dynamic";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4311);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "x86_64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_8", "file_architecture", "x86_64", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_9_skip (void);
static int test_file_architecture_9_perform (guestfs_h *);

static int
test_file_architecture_9 (guestfs_h *g)
{
  if (test_file_architecture_9_skip ()) {
    skipped ("test_file_architecture_9", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_9_perform (g);
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
test_file_architecture_9_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (9) */
  const char *arg4313 = "/lib-aarch64.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4313);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "aarch64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_9", "file_architecture", "aarch64", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_10_skip (void);
static int test_file_architecture_10_perform (guestfs_h *);

static int
test_file_architecture_10 (guestfs_h *g)
{
  if (test_file_architecture_10_skip ()) {
    skipped ("test_file_architecture_10", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_10_perform (g);
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
test_file_architecture_10_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (10) */
  const char *arg4315 = "/lib-armv7.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4315);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "arm")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_10", "file_architecture", "arm", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_11_skip (void);
static int test_file_architecture_11_perform (guestfs_h *);

static int
test_file_architecture_11 (guestfs_h *g)
{
  if (test_file_architecture_11_skip ()) {
    skipped ("test_file_architecture_11", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_11_perform (g);
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
test_file_architecture_11_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (11) */
  const char *arg4317 = "/lib-i586.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4317);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "i386")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_11", "file_architecture", "i386", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_12_skip (void);
static int test_file_architecture_12_perform (guestfs_h *);

static int
test_file_architecture_12 (guestfs_h *g)
{
  if (test_file_architecture_12_skip ()) {
    skipped ("test_file_architecture_12", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_12_perform (g);
}

static int
test_file_architecture_12_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_12");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_12_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (12) */
  const char *arg4319 = "/lib-ppc64.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4319);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "ppc64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_12", "file_architecture", "ppc64", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_13_skip (void);
static int test_file_architecture_13_perform (guestfs_h *);

static int
test_file_architecture_13 (guestfs_h *g)
{
  if (test_file_architecture_13_skip ()) {
    skipped ("test_file_architecture_13", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_13_perform (g);
}

static int
test_file_architecture_13_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_13");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_13_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (13) */
  const char *arg4321 = "/lib-ppc64le.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4321);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "ppc64le")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_13", "file_architecture", "ppc64le", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_14_skip (void);
static int test_file_architecture_14_perform (guestfs_h *);

static int
test_file_architecture_14 (guestfs_h *g)
{
  if (test_file_architecture_14_skip ()) {
    skipped ("test_file_architecture_14", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_14_perform (g);
}

static int
test_file_architecture_14_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_14");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_14_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (14) */
  const char *arg4323 = "/lib-sparc.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4323);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "sparc")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_14", "file_architecture", "sparc", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_15_skip (void);
static int test_file_architecture_15_perform (guestfs_h *);

static int
test_file_architecture_15 (guestfs_h *g)
{
  if (test_file_architecture_15_skip ()) {
    skipped ("test_file_architecture_15", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_15_perform (g);
}

static int
test_file_architecture_15_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_15");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_15_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (15) */
  const char *arg4325 = "/lib-win32.dll";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4325);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "i386")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_15", "file_architecture", "i386", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_16_skip (void);
static int test_file_architecture_16_perform (guestfs_h *);

static int
test_file_architecture_16 (guestfs_h *g)
{
  if (test_file_architecture_16_skip ()) {
    skipped ("test_file_architecture_16", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_16_perform (g);
}

static int
test_file_architecture_16_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_16");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_16_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (16) */
  const char *arg4327 = "/lib-win64.dll";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4327);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "x86_64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_16", "file_architecture", "x86_64", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_17_skip (void);
static int test_file_architecture_17_perform (guestfs_h *);

static int
test_file_architecture_17 (guestfs_h *g)
{
  if (test_file_architecture_17_skip ()) {
    skipped ("test_file_architecture_17", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_17_perform (g);
}

static int
test_file_architecture_17_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_17");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_17_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (17) */
  const char *arg4329 = "/lib-x86_64.so";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4329);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "x86_64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_17", "file_architecture", "x86_64", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_18_skip (void);
static int test_file_architecture_18_perform (guestfs_h *);

static int
test_file_architecture_18 (guestfs_h *g)
{
  if (test_file_architecture_18_skip ()) {
    skipped ("test_file_architecture_18", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_18_perform (g);
}

static int
test_file_architecture_18_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_18");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_18_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (18) */
  const char *arg4331 = "/initrd-x86_64.img";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4331);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "x86_64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_18", "file_architecture", "x86_64", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_19_skip (void);
static int test_file_architecture_19_perform (guestfs_h *);

static int
test_file_architecture_19 (guestfs_h *g)
{
  if (test_file_architecture_19_skip ()) {
    skipped ("test_file_architecture_19", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_19_perform (g);
}

static int
test_file_architecture_19_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_19");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_19_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (19) */
  const char *arg4333 = "/initrd-x86_64.img.gz";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4333);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "x86_64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_19", "file_architecture", "x86_64", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_20_skip (void);
static int test_file_architecture_20_perform (guestfs_h *);

static int
test_file_architecture_20 (guestfs_h *g)
{
  if (test_file_architecture_20_skip ()) {
    skipped ("test_file_architecture_20", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_20_perform (g);
}

static int
test_file_architecture_20_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_20");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_20_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (20) */
  const char *arg4335 = "/bin-x86_64-dynamic.gz";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4335);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "x86_64")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_20", "file_architecture", "x86_64", ret);
    return -1;
  }
  return 0;
}

static int test_file_architecture_21_skip (void);
static int test_file_architecture_21_perform (guestfs_h *);

static int
test_file_architecture_21 (guestfs_h *g)
{
  if (test_file_architecture_21_skip ()) {
    skipped ("test_file_architecture_21", "environment variable set");
    return 0;
  }

  if (init_iso_fs (g) == -1)
    return -1;

  return test_file_architecture_21_perform (g);
}

static int
test_file_architecture_21_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "file_architecture") == NULL;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE_21");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_FILE_ARCHITECTURE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_file_architecture_21_perform (guestfs_h *g)
{
  /* TestResultString for file_architecture (21) */
  const char *arg4337 = "/lib-i586.so.xz";
  CLEANUP_FREE char *ret;
  ret = guestfs_file_architecture (g, arg4337);
  if (ret == NULL)
      return -1;
  if (! STREQ (ret, "i386")) {
    fprintf (stderr, "%s: test failed: expected last command %s to return \"%s\" but it returned \"%s\"\n",
             "test_file_architecture_21", "file_architecture", "i386", ret);
    return -1;
  }
  return 0;
}

static int test_set_trace_0_skip (void);
static int test_set_trace_0_perform (guestfs_h *);

static int
test_set_trace_0 (guestfs_h *g)
{
  if (test_set_trace_0_skip ()) {
    skipped ("test_set_trace_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_set_trace_0_perform (g);
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
test_set_trace_0_perform (guestfs_h *g)
{
  /* TestResultFalse for set_trace (0) */
  int ret4339;
  ret4339 = guestfs_set_trace (g, 0);
  if (ret4339 == -1)
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

static int test_version_0_skip (void);
static int test_version_0_perform (guestfs_h *);

static int
test_version_0 (guestfs_h *g)
{
  if (test_version_0_skip ()) {
    skipped ("test_version_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_version_0_perform (g);
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
test_version_0_perform (guestfs_h *g)
{
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

static int test_get_memsize_0_skip (void);
static int test_get_memsize_0_perform (guestfs_h *);

static int
test_get_memsize_0 (guestfs_h *g)
{
  if (test_get_memsize_0_skip ()) {
    skipped ("test_get_memsize_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_get_memsize_0_perform (g);
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
test_get_memsize_0_perform (guestfs_h *g)
{
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

static int test_is_busy_0_skip (void);
static int test_is_busy_0_perform (guestfs_h *);

static int
test_is_busy_0 (guestfs_h *g)
{
  if (test_is_busy_0_skip ()) {
    skipped ("test_is_busy_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_is_busy_0_perform (g);
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
test_is_busy_0_perform (guestfs_h *g)
{
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

static int test_is_launching_0_skip (void);
static int test_is_launching_0_perform (guestfs_h *);

static int
test_is_launching_0 (guestfs_h *g)
{
  if (test_is_launching_0_skip ()) {
    skipped ("test_is_launching_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_is_launching_0_perform (g);
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
test_is_launching_0_perform (guestfs_h *g)
{
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

static int test_is_config_0_skip (void);
static int test_is_config_0_perform (guestfs_h *);

static int
test_is_config_0 (guestfs_h *g)
{
  if (test_is_config_0_skip ()) {
    skipped ("test_is_config_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_is_config_0_perform (g);
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
test_is_config_0_perform (guestfs_h *g)
{
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

static int test_is_ready_0_skip (void);
static int test_is_ready_0_perform (guestfs_h *);

static int
test_is_ready_0 (guestfs_h *g)
{
  if (test_is_ready_0_skip ()) {
    skipped ("test_is_ready_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_is_ready_0_perform (g);
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
test_is_ready_0_perform (guestfs_h *g)
{
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

static int test_get_autosync_0_skip (void);
static int test_get_autosync_0_perform (guestfs_h *);

static int
test_get_autosync_0 (guestfs_h *g)
{
  if (test_get_autosync_0_skip ()) {
    skipped ("test_get_autosync_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_get_autosync_0_perform (g);
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
test_get_autosync_0_perform (guestfs_h *g)
{
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

static int test_get_path_0_skip (void);
static int test_get_path_0_perform (guestfs_h *);

static int
test_get_path_0 (guestfs_h *g)
{
  if (test_get_path_0_skip ()) {
    skipped ("test_get_path_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_get_path_0_perform (g);
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
test_get_path_0_perform (guestfs_h *g)
{
  /* TestRun for get_path (0) */
  const char *ret4350;
  ret4350 = guestfs_get_path (g);
  if (ret4350 == NULL)
      return -1;
  return 0;
}

static int test_get_hv_0_skip (void);
static int test_get_hv_0_perform (guestfs_h *);

static int
test_get_hv_0 (guestfs_h *g)
{
  if (test_get_hv_0_skip ()) {
    skipped ("test_get_hv_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_get_hv_0_perform (g);
}

static int
test_get_hv_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_hv") == NULL;
  str = getenv ("SKIP_TEST_GET_HV_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_HV");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int
test_get_hv_0_perform (guestfs_h *g)
{
  /* TestRun for get_hv (0) */
  CLEANUP_FREE char *ret4352;
  ret4352 = guestfs_get_hv (g);
  if (ret4352 == NULL)
      return -1;
  return 0;
}

static int test_get_qemu_0_skip (void);
static int test_get_qemu_0_perform (guestfs_h *);

static int
test_get_qemu_0 (guestfs_h *g)
{
  if (test_get_qemu_0_skip ()) {
    skipped ("test_get_qemu_0", "environment variable set");
    return 0;
  }

  if (init_none (g) == -1)
    return -1;

  return test_get_qemu_0_perform (g);
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
test_get_qemu_0_perform (guestfs_h *g)
{
  /* TestRun for get_qemu (0) */
  const char *ret4354;
  ret4354 = guestfs_get_qemu (g);
  if (ret4354 == NULL)
      return -1;
  return 0;
}

size_t nr_tests = 528;

struct test tests[528] = {
  { .name = "test_vfs_minimum_size_0", .test_fn = test_vfs_minimum_size_0 },
  { .name = "test_vfs_minimum_size_1", .test_fn = test_vfs_minimum_size_1 },
  { .name = "test_vfs_minimum_size_2", .test_fn = test_vfs_minimum_size_2 },
  { .name = "test_vfs_minimum_size_3", .test_fn = test_vfs_minimum_size_3 },
  { .name = "test_set_uuid_random_0", .test_fn = test_set_uuid_random_0 },
  { .name = "test_part_get_mbr_part_type_0", .test_fn = test_part_get_mbr_part_type_0 },
  { .name = "test_part_get_mbr_part_type_1", .test_fn = test_part_get_mbr_part_type_1 },
  { .name = "test_btrfs_image_0", .test_fn = test_btrfs_image_0 },
  { .name = "test_btrfstune_enable_skinny_metadata_extent_refs_0", .test_fn = test_btrfstune_enable_skinny_metadata_extent_refs_0 },
  { .name = "test_btrfstune_enable_extended_inode_refs_0", .test_fn = test_btrfstune_enable_extended_inode_refs_0 },
  { .name = "test_btrfstune_seeding_0", .test_fn = test_btrfstune_seeding_0 },
  { .name = "test_btrfs_scrub_status_0", .test_fn = test_btrfs_scrub_status_0 },
  { .name = "test_part_get_gpt_guid_0", .test_fn = test_part_get_gpt_guid_0 },
  { .name = "test_part_set_gpt_guid_0", .test_fn = test_part_set_gpt_guid_0 },
  { .name = "test_part_set_gpt_guid_1", .test_fn = test_part_set_gpt_guid_1 },
  { .name = "test_btrfs_rescue_super_recover_0", .test_fn = test_btrfs_rescue_super_recover_0 },
  { .name = "test_btrfs_rescue_chunk_recover_0", .test_fn = test_btrfs_rescue_chunk_recover_0 },
  { .name = "test_btrfs_filesystem_defragment_0", .test_fn = test_btrfs_filesystem_defragment_0 },
  { .name = "test_btrfs_filesystem_defragment_1", .test_fn = test_btrfs_filesystem_defragment_1 },
  { .name = "test_btrfs_scrub_start_0", .test_fn = test_btrfs_scrub_start_0 },
  { .name = "test_btrfs_qgroup_remove_0", .test_fn = test_btrfs_qgroup_remove_0 },
  { .name = "test_btrfs_qgroup_assign_0", .test_fn = test_btrfs_qgroup_assign_0 },
  { .name = "test_btrfs_qgroup_show_0", .test_fn = test_btrfs_qgroup_show_0 },
  { .name = "test_btrfs_qgroup_destroy_0", .test_fn = test_btrfs_qgroup_destroy_0 },
  { .name = "test_btrfs_qgroup_create_0", .test_fn = test_btrfs_qgroup_create_0 },
  { .name = "test_btrfs_qgroup_limit_0", .test_fn = test_btrfs_qgroup_limit_0 },
  { .name = "test_btrfs_qgroup_limit_1", .test_fn = test_btrfs_qgroup_limit_1 },
  { .name = "test_btrfs_quota_rescan_0", .test_fn = test_btrfs_quota_rescan_0 },
  { .name = "test_btrfs_quota_rescan_1", .test_fn = test_btrfs_quota_rescan_1 },
  { .name = "test_btrfs_quota_enable_0", .test_fn = test_btrfs_quota_enable_0 },
  { .name = "test_btrfs_quota_enable_1", .test_fn = test_btrfs_quota_enable_1 },
  { .name = "test_btrfs_quota_enable_2", .test_fn = test_btrfs_quota_enable_2 },
  { .name = "test_btrfs_quota_enable_3", .test_fn = test_btrfs_quota_enable_3 },
  { .name = "test_btrfs_subvolume_show_0", .test_fn = test_btrfs_subvolume_show_0 },
  { .name = "test_btrfs_subvolume_show_1", .test_fn = test_btrfs_subvolume_show_1 },
  { .name = "test_btrfs_subvolume_show_2", .test_fn = test_btrfs_subvolume_show_2 },
  { .name = "test_btrfs_subvolume_get_default_0", .test_fn = test_btrfs_subvolume_get_default_0 },
  { .name = "test_btrfs_subvolume_get_default_1", .test_fn = test_btrfs_subvolume_get_default_1 },
  { .name = "test_blockdev_setra_0", .test_fn = test_blockdev_setra_0 },
  { .name = "test_lstatns_0", .test_fn = test_lstatns_0 },
  { .name = "test_statns_0", .test_fn = test_statns_0 },
  { .name = "test_aug_label_0", .test_fn = test_aug_label_0 },
  { .name = "test_aug_setm_0", .test_fn = test_aug_setm_0 },
  { .name = "test_set_uuid_0", .test_fn = test_set_uuid_0 },
  { .name = "test_remount_0", .test_fn = test_remount_0 },
  { .name = "test_remount_1", .test_fn = test_remount_1 },
  { .name = "test_cp_r_0", .test_fn = test_cp_r_0 },
  { .name = "test_is_whole_device_0", .test_fn = test_is_whole_device_0 },
  { .name = "test_is_whole_device_1", .test_fn = test_is_whole_device_1 },
  { .name = "test_is_whole_device_2", .test_fn = test_is_whole_device_2 },
  { .name = "test_rename_0", .test_fn = test_rename_0 },
  { .name = "test_part_get_gpt_type_0", .test_fn = test_part_get_gpt_type_0 },
  { .name = "test_part_set_gpt_type_0", .test_fn = test_part_set_gpt_type_0 },
  { .name = "test_part_set_gpt_type_1", .test_fn = test_part_set_gpt_type_1 },
  { .name = "test_cap_set_file_0", .test_fn = test_cap_set_file_0 },
  { .name = "test_acl_delete_def_file_0", .test_fn = test_acl_delete_def_file_0 },
  { .name = "test_acl_delete_def_file_1", .test_fn = test_acl_delete_def_file_1 },
  { .name = "test_acl_set_file_0", .test_fn = test_acl_set_file_0 },
  { .name = "test_acl_set_file_1", .test_fn = test_acl_set_file_1 },
  { .name = "test_acl_set_file_2", .test_fn = test_acl_set_file_2 },
  { .name = "test_acl_set_file_3", .test_fn = test_acl_set_file_3 },
  { .name = "test_acl_set_file_4", .test_fn = test_acl_set_file_4 },
  { .name = "test_acl_set_file_5", .test_fn = test_acl_set_file_5 },
  { .name = "test_mklost_and_found_0", .test_fn = test_mklost_and_found_0 },
  { .name = "test_mktemp_0", .test_fn = test_mktemp_0 },
  { .name = "test_mke2fs_0", .test_fn = test_mke2fs_0 },
  { .name = "test_mke2fs_1", .test_fn = test_mke2fs_1 },
  { .name = "test_mke2fs_2", .test_fn = test_mke2fs_2 },
  { .name = "test_rm_f_0", .test_fn = test_rm_f_0 },
  { .name = "test_rm_f_1", .test_fn = test_rm_f_1 },
  { .name = "test_xfs_repair_0", .test_fn = test_xfs_repair_0 },
  { .name = "test_hivex_commit_0", .test_fn = test_hivex_commit_0 },
  { .name = "test_hivex_commit_1", .test_fn = test_hivex_commit_1 },
  { .name = "test_hivex_open_0", .test_fn = test_hivex_open_0 },
  { .name = "test_xfs_admin_0", .test_fn = test_xfs_admin_0 },
  { .name = "test_xfs_admin_1", .test_fn = test_xfs_admin_1 },
  { .name = "test_xfs_admin_2", .test_fn = test_xfs_admin_2 },
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
  { .name = "test_copy_file_to_file_2", .test_fn = test_copy_file_to_file_2 },
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
  { .name = "test_vfs_label_1", .test_fn = test_vfs_label_1 },
  { .name = "test_vfs_label_2", .test_fn = test_vfs_label_2 },
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
  { .name = "test_echo_daemon_1", .test_fn = test_echo_daemon_1 },
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
  { .name = "test_mknod_c_1", .test_fn = test_mknod_c_1 },
  { .name = "test_mknod_b_0", .test_fn = test_mknod_b_0 },
  { .name = "test_mknod_b_1", .test_fn = test_mknod_b_1 },
  { .name = "test_mkfifo_0", .test_fn = test_mkfifo_0 },
  { .name = "test_mkfifo_1", .test_fn = test_mkfifo_1 },
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
  { .name = "test_scrub_file_1", .test_fn = test_scrub_file_1 },
  { .name = "test_scrub_file_2", .test_fn = test_scrub_file_2 },
  { .name = "test_scrub_file_3", .test_fn = test_scrub_file_3 },
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
  { .name = "test_vgcreate_1", .test_fn = test_vgcreate_1 },
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
  { .name = "test_aug_ls_0", .test_fn = test_aug_ls_0 },
  { .name = "test_aug_insert_0", .test_fn = test_aug_insert_0 },
  { .name = "test_aug_set_0", .test_fn = test_aug_set_0 },
  { .name = "test_aug_init_0", .test_fn = test_aug_init_0 },
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
  { .name = "test_feature_available_0", .test_fn = test_feature_available_0 },
  { .name = "test_available_0", .test_fn = test_available_0 },
  { .name = "test_get_identifier_0", .test_fn = test_get_identifier_0 },
  { .name = "test_c_pointer_0", .test_fn = test_c_pointer_0 },
  { .name = "test_lstat_0", .test_fn = test_lstat_0 },
  { .name = "test_stat_0", .test_fn = test_stat_0 },
  { .name = "test_get_backend_settings_0", .test_fn = test_get_backend_settings_0 },
  { .name = "test_get_program_0", .test_fn = test_get_program_0 },
  { .name = "test_disk_has_backing_file_0", .test_fn = test_disk_has_backing_file_0 },
  { .name = "test_disk_has_backing_file_1", .test_fn = test_disk_has_backing_file_1 },
  { .name = "test_disk_has_backing_file_2", .test_fn = test_disk_has_backing_file_2 },
  { .name = "test_disk_has_backing_file_3", .test_fn = test_disk_has_backing_file_3 },
  { .name = "test_disk_has_backing_file_4", .test_fn = test_disk_has_backing_file_4 },
  { .name = "test_disk_has_backing_file_5", .test_fn = test_disk_has_backing_file_5 },
  { .name = "test_disk_has_backing_file_6", .test_fn = test_disk_has_backing_file_6 },
  { .name = "test_disk_virtual_size_0", .test_fn = test_disk_virtual_size_0 },
  { .name = "test_disk_virtual_size_1", .test_fn = test_disk_virtual_size_1 },
  { .name = "test_disk_virtual_size_2", .test_fn = test_disk_virtual_size_2 },
  { .name = "test_disk_virtual_size_3", .test_fn = test_disk_virtual_size_3 },
  { .name = "test_disk_virtual_size_4", .test_fn = test_disk_virtual_size_4 },
  { .name = "test_disk_virtual_size_5", .test_fn = test_disk_virtual_size_5 },
  { .name = "test_disk_virtual_size_6", .test_fn = test_disk_virtual_size_6 },
  { .name = "test_disk_format_0", .test_fn = test_disk_format_0 },
  { .name = "test_disk_format_1", .test_fn = test_disk_format_1 },
  { .name = "test_disk_format_2", .test_fn = test_disk_format_2 },
  { .name = "test_disk_format_3", .test_fn = test_disk_format_3 },
  { .name = "test_disk_format_4", .test_fn = test_disk_format_4 },
  { .name = "test_disk_format_5", .test_fn = test_disk_format_5 },
  { .name = "test_disk_format_6", .test_fn = test_disk_format_6 },
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
  { .name = "test_file_architecture_12", .test_fn = test_file_architecture_12 },
  { .name = "test_file_architecture_13", .test_fn = test_file_architecture_13 },
  { .name = "test_file_architecture_14", .test_fn = test_file_architecture_14 },
  { .name = "test_file_architecture_15", .test_fn = test_file_architecture_15 },
  { .name = "test_file_architecture_16", .test_fn = test_file_architecture_16 },
  { .name = "test_file_architecture_17", .test_fn = test_file_architecture_17 },
  { .name = "test_file_architecture_18", .test_fn = test_file_architecture_18 },
  { .name = "test_file_architecture_19", .test_fn = test_file_architecture_19 },
  { .name = "test_file_architecture_20", .test_fn = test_file_architecture_20 },
  { .name = "test_file_architecture_21", .test_fn = test_file_architecture_21 },
  { .name = "test_set_trace_0", .test_fn = test_set_trace_0 },
  { .name = "test_version_0", .test_fn = test_version_0 },
  { .name = "test_get_memsize_0", .test_fn = test_get_memsize_0 },
  { .name = "test_is_busy_0", .test_fn = test_is_busy_0 },
  { .name = "test_is_launching_0", .test_fn = test_is_launching_0 },
  { .name = "test_is_config_0", .test_fn = test_is_config_0 },
  { .name = "test_is_ready_0", .test_fn = test_is_ready_0 },
  { .name = "test_get_autosync_0", .test_fn = test_get_autosync_0 },
  { .name = "test_get_path_0", .test_fn = test_get_path_0 },
  { .name = "test_get_hv_0", .test_fn = test_get_hv_0 },
  { .name = "test_get_qemu_0", .test_fn = test_get_qemu_0 },
};
