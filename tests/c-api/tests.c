/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
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

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include "guestfs.h"

#define STREQ(a,b) (strcmp((a),(b)) == 0)
//#define STRCASEEQ(a,b) (strcasecmp((a),(b)) == 0)
#define STRNEQ(a,b) (strcmp((a),(b)) != 0)
//#define STRCASENEQ(a,b) (strcasecmp((a),(b)) != 0)
//#define STREQLEN(a,b,n) (strncmp((a),(b),(n)) == 0)
//#define STRCASEEQLEN(a,b,n) (strncasecmp((a),(b),(n)) == 0)
#define STRNEQLEN(a,b,n) (strncmp((a),(b),(n)) != 0)
//#define STRCASENEQLEN(a,b,n) (strncasecmp((a),(b),(n)) != 0)
//#define STRPREFIX(a,b) (strncmp((a),(b),strlen((b))) == 0)

static guestfs_h *g;

/* FIXME: nearly identical code appears in fish.c */
static void
print_strings (char *const *argv)
{
  size_t argc;

  for (argc = 0; argv[argc] != NULL; ++argc)
    printf ("\t%s\n", argv[argc]);
}

static int
is_available (const char *group)
{
  const char *groups[] = { group, NULL };
  int r;

  guestfs_push_error_handler (g, NULL, NULL);
  r = guestfs_available (g, (char **) groups);
  guestfs_pop_error_handler (g);

  return r == 0;
}

static void
incr (guestfs_h *g, void *iv)
{
  int *i = (int *) iv;
  (*i)++;
}

/* Get md5sum of the named file. */
static void
md5sum (const char *filename, char *result)
{
  char cmd[256];
  snprintf (cmd, sizeof cmd, "md5sum %s", filename);
  FILE *pp = popen (cmd, "r");
  if (pp == NULL) {
    perror (cmd);
    exit (EXIT_FAILURE);
  }
  if (fread (result, 1, 32, pp) != 32) {
    perror ("md5sum: fread");
    exit (EXIT_FAILURE);
  }
  if (pclose (pp) != 0) {
    perror ("pclose");
    exit (EXIT_FAILURE);
  }
  result[32] = '\0';
}

/* Return the value for a key in a hashtable.
 * Note: the return value is part of the hash and should not be freed.
 */
static const char *
get_key (char **hash, const char *key)
{
  size_t i;

  for (i = 0; hash[i] != NULL; i += 2) {
    if (STREQ (hash[i], key))
      return hash[i+1];
  }

  return NULL; /* key not found */
}

static void
next_test (guestfs_h *g, size_t test_num, size_t nr_tests,
           const char *test_name)
{
  if (guestfs_get_verbose (g))
    printf ("-------------------------------------------------------------------------------\n");
  printf ("%3zu/%3zu %s\n", test_num, nr_tests, test_name);
}

static void
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
    "internal_readlinklist",
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
    "set_cachedir",
    "set_direct",
    "set_libvirt_requested_credential",
    "set_libvirt_supported_credentials",
    "set_memsize",
    "set_network",
    "set_path",
    "set_pgroup",
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
    "tar_out",
    "tgz_out",
    "txz_out",
    "umount_local",
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_get_gpt_type_0");
    return 0;
  }

  if (!is_available ("gdisk")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_part_get_gpt_type_0", "gdisk");
    return 0;
  }
  /* InitGPT for test_part_get_gpt_type_0: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "gpt";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestOutput for part_get_gpt_type (0) */
  const char *expected = "01234567-89AB-CDEF-0123-456789ABCDEF";
  {
    const char *device = "/dev/sda";
    const char *guid = "01234567-89AB-CDEF-0123-456789ABCDEF";
    int r;
    r = guestfs_part_set_gpt_type (g, device, 1, guid);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    char *r;
    r = guestfs_part_get_gpt_type (g, device, 1);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_part_get_gpt_type_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_cap_set_file_0");
    return 0;
  }

  if (!is_available ("linuxcaps")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_cap_set_file_0", "linuxcaps");
    return 0;
  }
  /* InitScratchFS for test_cap_set_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for cap_set_file (0) */
  const char *expected = "= cap_chown+ep";
  {
    const char *path = "/cap_set_file_0";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/cap_set_file_0";
    const char *cap = "cap_chown=p cap_chown+e";
    int r;
    r = guestfs_cap_set_file (g, path, cap);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/cap_set_file_0";
    char *r;
    r = guestfs_cap_get_file (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_cap_set_file_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_acl_delete_def_file_0");
    return 0;
  }

  if (!is_available ("acl")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_acl_delete_def_file_0", "acl");
    return 0;
  }
  printf ("        %s skipped (reason: test disabled in generator)\n", "test_acl_delete_def_file_0");
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_acl_delete_def_file_1");
    return 0;
  }

  if (!is_available ("acl")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_acl_delete_def_file_1", "acl");
    return 0;
  }
  /* InitScratchFS for test_acl_delete_def_file_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for acl_delete_def_file (1) */
  {
    const char *path = "/acl_delete_def_file_1";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/acl_delete_def_file_1";
    const char *acltype = "default";
    const char *acl = "user::r-x,group::r-x,other::r-x";
    int r;
    r = guestfs_acl_set_file (g, path, acltype, acl);
    if (r == -1)
      return -1;
  }
  {
    const char *dir = "/acl_delete_def_file_1";
    int r;
    r = guestfs_acl_delete_def_file (g, dir);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_acl_set_file_0");
    return 0;
  }

  if (!is_available ("acl")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_acl_set_file_0", "acl");
    return 0;
  }
  /* InitScratchFS for test_acl_set_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for acl_set_file (0) */
  {
    const char *path = "/acl_set_file_0";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/acl_set_file_0";
    const char *acltype = "access";
    const char *acl = "user::r-x,group::r-x,other::r-x";
    int r;
    r = guestfs_acl_set_file (g, path, acltype, acl);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/acl_set_file_0";
    const char *acltype = "access";
    char *r;
    r = guestfs_acl_get_file (g, path, acltype);
    if (r == NULL)
      return -1;
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mklost_and_found_0");
    return 0;
  }

  /* InitBasicFS for test_mklost_and_found_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for mklost_and_found (0) */
  {
    const char *path = "/lost+found";
    int r;
    r = guestfs_rm_rf (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *mountpoint = "/";
    int r;
    r = guestfs_mklost_and_found (g, mountpoint);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mktemp_0");
    return 0;
  }

  /* InitScratchFS for test_mktemp_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for mktemp (0) */
  {
    const char *path = "/mktemp";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *tmpl = "/mktemp/tmpXXXXXX";
    struct guestfs_mktemp_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    char *r;
    r = guestfs_mktemp_argv (g, tmpl, &optargs);
    if (r == NULL)
      return -1;
    free (r);
  }
  {
    const char *tmpl = "/mktemp/tmpXXXXXX";
    struct guestfs_mktemp_argv optargs;
    optargs.suffix = "suff";
    optargs.bitmask = UINT64_C(0x1);
    char *r;
    r = guestfs_mktemp_argv (g, tmpl, &optargs);
    if (r == NULL)
      return -1;
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mke2fs_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mke2fs_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mke2fs (0) */
  const char *expected = "new file contents";
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, -64);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    struct guestfs_mke2fs_argv optargs;
    optargs.blocksize = 4096;
    optargs.journaldev = 1;
    optargs.bitmask = UINT64_C(0x100000002);
    int r;
    r = guestfs_mke2fs_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    struct guestfs_mke2fs_argv optargs;
    optargs.blocksize = 4096;
    optargs.journaldevice = "/dev/sda1";
    optargs.fstype = "ext2";
    optargs.bitmask = UINT64_C(0x44002);
    int r;
    r = guestfs_mke2fs_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_mke2fs_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mke2fs_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_mke2fs_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mke2fs (1) */
  const char *expected = "new file contents";
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, -64);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    struct guestfs_mke2fs_argv optargs;
    optargs.blocksize = 4096;
    optargs.journaldevice = "/dev/sda1";
    optargs.label = "JOURNAL";
    optargs.fstype = "ext2";
    optargs.journaldev = 1;
    optargs.bitmask = UINT64_C(0x10004c002);
    int r;
    r = guestfs_mke2fs_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    struct guestfs_mke2fs_argv optargs;
    optargs.blocksize = 4096;
    optargs.journaldevice = "LABEL=JOURNAL";
    optargs.label = "JOURNAL";
    optargs.fstype = "ext2";
    optargs.bitmask = UINT64_C(0x4c002);
    int r;
    r = guestfs_mke2fs_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_mke2fs_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mke2fs_2");
    return 0;
  }

  /* InitNone|InitEmpty for test_mke2fs_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mke2fs (2) */
  const char *expected = "new file contents";
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, -64);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    struct guestfs_mke2fs_argv optargs;
    optargs.blocksize = 4096;
    optargs.uuid = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
    optargs.journaldev = 1;
    optargs.bitmask = UINT64_C(0x100100002);
    int r;
    r = guestfs_mke2fs_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    struct guestfs_mke2fs_argv optargs;
    optargs.blocksize = 4096;
    optargs.journaldevice = "UUID=d113cb80-b755-cd40-f87b-46eed23b2f0f";
    optargs.label = "JOURNAL";
    optargs.fstype = "ext2";
    optargs.forcecreate = 1;
    optargs.bitmask = UINT64_C(0x24c002);
    int r;
    r = guestfs_mke2fs_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_mke2fs_2", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_rm_f_0");
    return 0;
  }

  /* InitScratchFS for test_rm_f_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for rm_f (0) */
  {
    const char *path = "/rm_f";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rm_f/foo";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rm_f/foo";
    int r;
    r = guestfs_rm_f (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rm_f/not_exists";
    int r;
    r = guestfs_rm_f (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rm_f/foo";
    int r;
    r = guestfs_exists (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_rm_f_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_rm_f_1");
    return 0;
  }

  /* InitScratchFS for test_rm_f_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for rm_f (1) */
  {
    const char *path = "/rm_f2";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rm_f2/foo";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rm_f2/foo";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_rm_f (g, path);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_xfs_repair_0");
    return 0;
  }

  if (!is_available ("xfs")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_xfs_repair_0", "xfs");
    return 0;
  }
  /* InitNone|InitEmpty for test_xfs_repair_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for xfs_repair (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "xfs";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    struct guestfs_xfs_repair_argv optargs;
    optargs.nomodify = 1;
    optargs.bitmask = UINT64_C(0x2);
    int r;
    r = guestfs_xfs_repair_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_xfs_admin_0");
    return 0;
  }

  if (!is_available ("xfs")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_xfs_admin_0", "xfs");
    return 0;
  }
  /* InitNone|InitEmpty for test_xfs_admin_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for xfs_admin (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "xfs";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    struct guestfs_xfs_admin_argv optargs;
    optargs.lazycounter = 0;
    optargs.bitmask = UINT64_C(0x10);
    int r;
    r = guestfs_xfs_admin_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *pathordevice = "/";
    struct guestfs_xfsinfo *r;
    r = guestfs_xfs_info (g, pathordevice);
    if (r == NULL)
      return -1;
    if (r->xfs_lazycount != 0) {
      fprintf (stderr, "%s: xfs_lazycount was %d, expected 0\n",
               "test_xfs_admin_0", (int) r->xfs_lazycount);
      return -1;
    }
    guestfs_free_xfsinfo (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_xfs_growfs_0");
    return 0;
  }

  if (!is_available ("xfs")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_xfs_growfs_0", "xfs");
    return 0;
  }
  /* InitNone|InitEmpty for test_xfs_growfs_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for xfs_growfs (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 40);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "xfs";
    const char *device = "/dev/VG/LV";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    int r;
    r = guestfs_lvresize (g, device, 80);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/";
    struct guestfs_xfs_growfs_argv optargs;
    optargs.datasec = 1;
    optargs.logsec = 0;
    optargs.rtsec = 0;
    optargs.bitmask = UINT64_C(0x7);
    int r;
    r = guestfs_xfs_growfs_argv (g, path, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *pathordevice = "/";
    struct guestfs_xfsinfo *r;
    r = guestfs_xfs_info (g, pathordevice);
    if (r == NULL)
      return -1;
    if (r->xfs_blocksize != 4096) {
      fprintf (stderr, "%s: xfs_blocksize was %d, expected 4096\n",
               "test_xfs_growfs_0", (int) r->xfs_blocksize);
      return -1;
    }
    guestfs_free_xfsinfo (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_utsname_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_utsname_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for utsname (0) */
  {
    struct guestfs_utsname *r;
    r = guestfs_utsname (g);
    if (r == NULL)
      return -1;
    guestfs_free_utsname (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgchange_uuid_all_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_vgchange_uuid_all_0", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_vgchange_uuid_all_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for vgchange_uuid_all (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_vgchange_uuid_all (g);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgchange_uuid_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_vgchange_uuid_0", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_vgchange_uuid_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for vgchange_uuid (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *vg = "/dev/VG";
    int r;
    r = guestfs_vgchange_uuid (g, vg);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvchange_uuid_all_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvchange_uuid_all_0", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_pvchange_uuid_all_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for pvchange_uuid_all (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_pvchange_uuid_all (g);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvchange_uuid_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvchange_uuid_0", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_pvchange_uuid_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for pvchange_uuid (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvchange_uuid (g, device);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_xfs_info_0");
    return 0;
  }

  if (!is_available ("xfs")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_xfs_info_0", "xfs");
    return 0;
  }
  /* InitNone|InitEmpty for test_xfs_info_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for xfs_info (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "xfs";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *pathordevice = "/";
    struct guestfs_xfsinfo *r;
    r = guestfs_xfs_info (g, pathordevice);
    if (r == NULL)
      return -1;
    if (r->xfs_blocksize != 4096) {
      fprintf (stderr, "%s: xfs_blocksize was %d, expected 4096\n",
               "test_xfs_info_0", (int) r->xfs_blocksize);
      return -1;
    }
    guestfs_free_xfsinfo (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_nr_devices_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_nr_devices_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for nr_devices (0) */
  {
    int r;
    r = guestfs_nr_devices (g);
    if (r == -1)
      return -1;
    if (r != 4) {
      fprintf (stderr, "%s: expected 4 but got %d\n",               "test_nr_devices_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_device_index_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_device_index_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for device_index (0) */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_device_index (g, device);
    if (r == -1)
      return -1;
    if (r != 0) {
      fprintf (stderr, "%s: expected 0 but got %d\n",               "test_device_index_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_btrfs_fsck_0");
    return 0;
  }

  if (!is_available ("btrfs")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_btrfs_fsck_0", "btrfs");
    return 0;
  }
  /* InitPartition for test_btrfs_fsck_0: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestRun for btrfs_fsck (0) */
  {
    const char *devices_0 = "/dev/sda1";
    const char *const devices[] = {
      devices_0,
      NULL
    };
    struct guestfs_mkfs_btrfs_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_btrfs_argv (g, (char **) devices, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    struct guestfs_btrfs_fsck_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_btrfs_fsck_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_btrfs_set_seeding_0");
    return 0;
  }

  if (!is_available ("btrfs")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_btrfs_set_seeding_0", "btrfs");
    return 0;
  }
  /* InitPartition for test_btrfs_set_seeding_0: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestRun for btrfs_set_seeding (0) */
  {
    const char *devices_0 = "/dev/sda1";
    const char *const devices[] = {
      devices_0,
      NULL
    };
    struct guestfs_mkfs_btrfs_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_btrfs_argv (g, (char **) devices, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_btrfs_set_seeding (g, device, 1);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_btrfs_set_seeding (g, device, 0);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_btrfs_filesystem_sync_0");
    return 0;
  }

  if (!is_available ("btrfs")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_btrfs_filesystem_sync_0", "btrfs");
    return 0;
  }
  /* InitPartition for test_btrfs_filesystem_sync_0: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestRun for btrfs_filesystem_sync (0) */
  {
    const char *devices_0 = "/dev/sda1";
    const char *const devices[] = {
      devices_0,
      NULL
    };
    struct guestfs_mkfs_btrfs_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_btrfs_argv (g, (char **) devices, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *dest = "/test1";
    int r;
    r = guestfs_btrfs_subvolume_create (g, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *fs = "/test1";
    int r;
    r = guestfs_btrfs_filesystem_sync (g, fs);
    if (r == -1)
      return -1;
  }
  {
    const char *fs = "/test1";
    int r;
    r = guestfs_btrfs_filesystem_balance (g, fs);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_btrfs_subvolume_delete_0");
    return 0;
  }

  if (!is_available ("btrfs")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_btrfs_subvolume_delete_0", "btrfs");
    return 0;
  }
  /* InitPartition for test_btrfs_subvolume_delete_0: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestRun for btrfs_subvolume_delete (0) */
  {
    const char *devices_0 = "/dev/sda1";
    const char *const devices[] = {
      devices_0,
      NULL
    };
    struct guestfs_mkfs_btrfs_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_btrfs_argv (g, (char **) devices, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *dest = "/test1";
    int r;
    r = guestfs_btrfs_subvolume_create (g, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *subvolume = "/test1";
    int r;
    r = guestfs_btrfs_subvolume_delete (g, subvolume);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_btrfs_subvolume_snapshot_0");
    return 0;
  }

  if (!is_available ("btrfs")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_btrfs_subvolume_snapshot_0", "btrfs");
    return 0;
  }
  /* InitPartition for test_btrfs_subvolume_snapshot_0: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestRun for btrfs_subvolume_snapshot (0) */
  {
    const char *devices_0 = "/dev/sda1";
    const char *const devices[] = {
      devices_0,
      NULL
    };
    struct guestfs_mkfs_btrfs_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_btrfs_argv (g, (char **) devices, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/dir";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *dest = "/test1";
    int r;
    r = guestfs_btrfs_subvolume_create (g, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *dest = "/test2";
    int r;
    r = guestfs_btrfs_subvolume_create (g, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *dest = "/dir/test3";
    int r;
    r = guestfs_btrfs_subvolume_create (g, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *source = "/dir/test3";
    const char *dest = "/dir/test4";
    int r;
    r = guestfs_btrfs_subvolume_snapshot (g, source, dest);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_e2generation_0");
    return 0;
  }

  /* InitScratchFS for test_get_e2generation_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for get_e2generation (0) */
  {
    const char *path = "/e2generation";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2generation";
    int r;
    r = guestfs_set_e2generation (g, file, 123456);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2generation";
    int64_t r;
    r = guestfs_get_e2generation (g, file);
    if (r == -1)
      return -1;
    if (r != 123456) {
      fprintf (stderr, "%s: expected 123456 but got %d\n",               "test_get_e2generation_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_e2attrs_0");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for get_e2attrs (0) */
  const char *expected = "";
  {
    const char *path = "/e2attrs1";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs1";
    char *r;
    r = guestfs_get_e2attrs (g, file);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_get_e2attrs_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_e2attrs_1");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for get_e2attrs (1) */
  const char *expected = "is";
  {
    const char *path = "/e2attrs2";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs2";
    const char *attrs = "is";
    struct guestfs_set_e2attrs_argv optargs;
    optargs.clear = 0;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_set_e2attrs_argv (g, file, attrs, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs2";
    char *r;
    r = guestfs_get_e2attrs (g, file);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_get_e2attrs_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_e2attrs_2");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for get_e2attrs (2) */
  const char *expected = "s";
  {
    const char *path = "/e2attrs3";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs3";
    const char *attrs = "is";
    struct guestfs_set_e2attrs_argv optargs;
    optargs.clear = 0;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_set_e2attrs_argv (g, file, attrs, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs3";
    const char *attrs = "i";
    struct guestfs_set_e2attrs_argv optargs;
    optargs.clear = 1;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_set_e2attrs_argv (g, file, attrs, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs3";
    char *r;
    r = guestfs_get_e2attrs (g, file);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_get_e2attrs_2", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_e2attrs_3");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for get_e2attrs (3) */
  const char *expected = "Sst";
  {
    const char *path = "/e2attrs4";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs4";
    const char *attrs = "adst";
    struct guestfs_set_e2attrs_argv optargs;
    optargs.clear = 0;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_set_e2attrs_argv (g, file, attrs, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs4";
    const char *attrs = "iS";
    struct guestfs_set_e2attrs_argv optargs;
    optargs.clear = 0;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_set_e2attrs_argv (g, file, attrs, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs4";
    const char *attrs = "i";
    struct guestfs_set_e2attrs_argv optargs;
    optargs.clear = 1;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_set_e2attrs_argv (g, file, attrs, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs4";
    const char *attrs = "ad";
    struct guestfs_set_e2attrs_argv optargs;
    optargs.clear = 1;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_set_e2attrs_argv (g, file, attrs, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs4";
    const char *attrs = "";
    struct guestfs_set_e2attrs_argv optargs;
    optargs.clear = 0;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_set_e2attrs_argv (g, file, attrs, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs4";
    const char *attrs = "";
    struct guestfs_set_e2attrs_argv optargs;
    optargs.clear = 1;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_set_e2attrs_argv (g, file, attrs, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs4";
    char *r;
    r = guestfs_get_e2attrs (g, file);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_get_e2attrs_3", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_e2attrs_4");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for get_e2attrs (4) */
  {
    const char *path = "/e2attrs5";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs5";
    const char *attrs = "R";
    struct guestfs_set_e2attrs_argv optargs;
    optargs.clear = 0;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_set_e2attrs_argv (g, file, attrs, &optargs);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_e2attrs_5");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_5 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for get_e2attrs (5) */
  {
    const char *path = "/e2attrs6";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs6";
    const char *attrs = "v";
    struct guestfs_set_e2attrs_argv optargs;
    optargs.clear = 0;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_set_e2attrs_argv (g, file, attrs, &optargs);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_e2attrs_6");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_6 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for get_e2attrs (6) */
  {
    const char *path = "/e2attrs7";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs7";
    const char *attrs = "aa";
    struct guestfs_set_e2attrs_argv optargs;
    optargs.clear = 0;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_set_e2attrs_argv (g, file, attrs, &optargs);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_e2attrs_7");
    return 0;
  }

  /* InitScratchFS for test_get_e2attrs_7 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for get_e2attrs (7) */
  {
    const char *path = "/e2attrs8";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/e2attrs8";
    const char *attrs = "BabcdB";
    struct guestfs_set_e2attrs_argv optargs;
    optargs.clear = 0;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_set_e2attrs_argv (g, file, attrs, &optargs);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkfs_btrfs_0");
    return 0;
  }

  if (!is_available ("btrfs")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mkfs_btrfs_0", "btrfs");
    return 0;
  }
  /* InitNone|InitEmpty for test_mkfs_btrfs_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkfs_btrfs (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *devices_0 = "/dev/sda1";
    const char *const devices[] = {
      devices_0,
      NULL
    };
    struct guestfs_mkfs_btrfs_argv optargs;
    optargs.allocstart = 0;
    optargs.bytecount = 268435456;
    optargs.datatype = "single";
    optargs.leafsize = 4096;
    optargs.label = "test";
    optargs.metadata = "single";
    optargs.nodesize = 4096;
    optargs.sectorsize = 512;
    optargs.bitmask = UINT64_C(0xff);
    int r;
    r = guestfs_mkfs_btrfs_argv (g, (char **) devices, &optargs);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_isoinfo_device_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_isoinfo_device_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for isoinfo_device (0) */
  {
    const char *device = "/dev/sdd";
    struct guestfs_isoinfo *r;
    r = guestfs_isoinfo_device (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r->iso_system_id, "LINUX")) {
      fprintf (stderr, "%s: iso_system_id was \"%s\", expected \"LINUX\"\n",
               "test_isoinfo_device_0", r->iso_system_id);
      return -1;
    }
    if (STRNEQ (r->iso_volume_id, "CDROM")) {
      fprintf (stderr, "%s: iso_volume_id was \"%s\", expected \"CDROM\"\n",
               "test_isoinfo_device_0", r->iso_volume_id);
      return -1;
    }
    if (STRNEQ (r->iso_volume_set_id, "")) {
      fprintf (stderr, "%s: iso_volume_set_id was \"%s\", expected \"\"\n",
               "test_isoinfo_device_0", r->iso_volume_set_id);
      return -1;
    }
    if (r->iso_volume_set_size != 1) {
      fprintf (stderr, "%s: iso_volume_set_size was %d, expected 1\n",
               "test_isoinfo_device_0", (int) r->iso_volume_set_size);
      return -1;
    }
    if (r->iso_volume_sequence_number != 1) {
      fprintf (stderr, "%s: iso_volume_sequence_number was %d, expected 1\n",
               "test_isoinfo_device_0", (int) r->iso_volume_sequence_number);
      return -1;
    }
    if (r->iso_logical_block_size != 2048) {
      fprintf (stderr, "%s: iso_logical_block_size was %d, expected 2048\n",
               "test_isoinfo_device_0", (int) r->iso_logical_block_size);
      return -1;
    }
    guestfs_free_isoinfo (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvcreate_free_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvcreate_free_0", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_lvcreate_free_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvcreate_free (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate_free (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate_free (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV3";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate_free (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV4";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate_free (g, logvol, volgroup, 100);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvcreate_free_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG/LV1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvcreate_free_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvcreate_free_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG/LV2";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvcreate_free_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvcreate_free_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG/LV3";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvcreate_free_0", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvcreate_free_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG/LV4";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvcreate_free_0", expected, r[3]);
        return -1;
      }
    }
    if (r[4] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_lvcreate_free_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_zero_free_space_0");
    return 0;
  }

  /* InitScratchFS for test_zero_free_space_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for zero_free_space (0) */
  {
    const char *directory = "/";
    int r;
    r = guestfs_zero_free_space (g, directory);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_label_0");
    return 0;
  }

  /* InitBasicFS for test_set_label_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for set_label (0) */
  const char *expected = "testlabel";
  {
    const char *device = "/dev/sda1";
    const char *label = "testlabel";
    int r;
    r = guestfs_set_label (g, device, label);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    char *r;
    r = guestfs_vfs_label (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_set_label_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_label_1");
    return 0;
  }

  if (!is_available ("ntfs3g")) {
    printf ("        %s skipped (reason: %s not available)\n", "test_set_label_1", "ntfs3g");
    return 0;
  }

  /* InitPartition for test_set_label_1: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestOutput for set_label (1) */
  const char *expected = "testlabel2";
  {
    const char *fstype = "ntfs";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *label = "testlabel2";
    int r;
    r = guestfs_set_label (g, device, label);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    char *r;
    r = guestfs_vfs_label (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_set_label_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_label_2");
    return 0;
  }

  /* InitPartition for test_set_label_2: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for set_label (2) */
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_zero (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *label = "testlabel2";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_set_label (g, device, label);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_ntfsfix_0");
    return 0;
  }

  if (!is_available ("ntfs3g")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_ntfsfix_0", "ntfs3g");
    return 0;
  }
  /* InitPartition for test_ntfsfix_0: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestRun for ntfsfix (0) */
  {
    const char *fstype = "ntfs";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    struct guestfs_ntfsfix_argv optargs;
    optargs.clearbadsectors = 0;
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_ntfsfix_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_wipefs_0");
    return 0;
  }

  if (!is_available ("wipefs")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_wipefs_0", "wipefs");
    return 0;
  }
  /* InitBasicFSonLVM for test_wipefs_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for wipefs (0) */
  {
    const char *pathordevice = "/dev/VG/LV";
    struct guestfs_umount_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_umount_opts_argv (g, pathordevice, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    int r;
    r = guestfs_wipefs (g, device);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_blkid_0");
    return 0;
  }

  /* InitScratchFS for test_blkid_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputHashtable for blkid (0) */
  const char *key, *expected, *value;
  {
    const char *device = "/dev/sdb1";
    char **r;
    size_t i;
    r = guestfs_blkid (g, device);
    if (r == NULL)
      return -1;
    key = "TYPE";
    expected = "ext2";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_blkid_0", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_blkid_0", key, expected, value);
      return -1;
    }
    key = "USAGE";
    expected = "filesystem";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_blkid_0", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_blkid_0", key, expected, value);
      return -1;
    }
    key = "PART_ENTRY_NUMBER";
    expected = "1";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_blkid_0", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_blkid_0", key, expected, value);
      return -1;
    }
    key = "PART_ENTRY_TYPE";
    expected = "0x83";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_blkid_0", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_blkid_0", key, expected, value);
      return -1;
    }
    key = "PART_ENTRY_OFFSET";
    expected = "128";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_blkid_0", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_blkid_0", key, expected, value);
      return -1;
    }
    key = "PART_ENTRY_SIZE";
    expected = "102145";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_blkid_0", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_blkid_0", key, expected, value);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_tune2fs_0");
    return 0;
  }

  /* InitScratchFS for test_tune2fs_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputHashtable for tune2fs (0) */
  const char *key, *expected, *value;
  {
    const char *device = "/dev/sdb1";
    struct guestfs_tune2fs_argv optargs;
    optargs.force = 0;
    optargs.maxmountcount = 0;
    optargs.intervalbetweenchecks = 0;
    optargs.bitmask = UINT64_C(0x23);
    int r;
    r = guestfs_tune2fs_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    char **r;
    size_t i;
    r = guestfs_tune2fs_l (g, device);
    if (r == NULL)
      return -1;
    key = "Check interval";
    expected = "0 (<none>)";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_tune2fs_0", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_tune2fs_0", key, expected, value);
      return -1;
    }
    key = "Maximum mount count";
    expected = "-1";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_tune2fs_0", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_tune2fs_0", key, expected, value);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_tune2fs_1");
    return 0;
  }

  /* InitScratchFS for test_tune2fs_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputHashtable for tune2fs (1) */
  const char *key, *expected, *value;
  {
    const char *device = "/dev/sdb1";
    struct guestfs_tune2fs_argv optargs;
    optargs.force = 0;
    optargs.maxmountcount = 0;
    optargs.intervalbetweenchecks = 86400;
    optargs.bitmask = UINT64_C(0x23);
    int r;
    r = guestfs_tune2fs_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    char **r;
    size_t i;
    r = guestfs_tune2fs_l (g, device);
    if (r == NULL)
      return -1;
    key = "Check interval";
    expected = "86400 (1 day)";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_tune2fs_1", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_tune2fs_1", key, expected, value);
      return -1;
    }
    key = "Maximum mount count";
    expected = "-1";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_tune2fs_1", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_tune2fs_1", key, expected, value);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_tune2fs_2");
    return 0;
  }

  /* InitScratchFS for test_tune2fs_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputHashtable for tune2fs (2) */
  const char *key, *expected, *value;
  {
    const char *device = "/dev/sdb1";
    struct guestfs_tune2fs_argv optargs;
    optargs.force = 0;
    optargs.group = 1;
    optargs.user = 1;
    optargs.bitmask = UINT64_C(0x211);
    int r;
    r = guestfs_tune2fs_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    char **r;
    size_t i;
    r = guestfs_tune2fs_l (g, device);
    if (r == NULL)
      return -1;
    key = "Reserved blocks uid";
    expected = "1 (user bin)";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_tune2fs_2", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_tune2fs_2", key, expected, value);
      return -1;
    }
    key = "Reserved blocks gid";
    expected = "1 (group bin)";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_tune2fs_2", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_tune2fs_2", key, expected, value);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_tune2fs_3");
    return 0;
  }

  /* InitScratchFS for test_tune2fs_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputHashtable for tune2fs (3) */
  const char *key, *expected, *value;
  {
    const char *device = "/dev/sdb1";
    struct guestfs_tune2fs_argv optargs;
    optargs.force = 0;
    optargs.group = 0;
    optargs.user = 0;
    optargs.bitmask = UINT64_C(0x211);
    int r;
    r = guestfs_tune2fs_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    char **r;
    size_t i;
    r = guestfs_tune2fs_l (g, device);
    if (r == NULL)
      return -1;
    key = "Reserved blocks uid";
    expected = "0 (user root)";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_tune2fs_3", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_tune2fs_3", key, expected, value);
      return -1;
    }
    key = "Reserved blocks gid";
    expected = "0 (group root)";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_tune2fs_3", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_tune2fs_3", key, expected, value);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_copy_file_to_file_0");
    return 0;
  }

  /* InitScratchFS for test_copy_file_to_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputBuffer for copy_file_to_file (0) */
  const char *expected = "hello, world";
  {
    const char *path = "/copyff";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/copyff/src";
    const char *content = "hello, world";
    size_t content_size = 12;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/copyff/src";
    const char *dest = "/copyff/dest";
    struct guestfs_copy_file_to_file_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_copy_file_to_file_argv (g, src, dest, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/copyff/dest";
    char *r;
    size_t size;
    r = guestfs_read_file (g, path, &size);
    if (r == NULL)
      return -1;
    if (size != 12) {
      fprintf (stderr, "%s: returned size of buffer wrong, expected 12 but got %zu\n", "test_copy_file_to_file_0", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_copy_file_to_file_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_to_partnum_0");
    return 0;
  }

  /* InitPartition for test_part_to_partnum_0: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for part_to_partnum (0) */
  {
    const char *partition = "/dev/sda1";
    int r;
    r = guestfs_part_to_partnum (g, partition);
    if (r == -1)
      return -1;
    if (r != 1) {
      fprintf (stderr, "%s: expected 1 but got %d\n",               "test_part_to_partnum_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_to_partnum_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_to_partnum_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for part_to_partnum (1) */
  {
    const char *partition = "/dev/sda";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_part_to_partnum (g, partition);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_internal_write_append_0");
    return 0;
  }

  /* InitScratchFS for test_internal_write_append_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for internal_write_append (0) */
  const char *expected = "line1\nline2\nline3aline3b\n";
  {
    const char *path = "/internal_write_append";
    const char *content = "line1\n";
    size_t content_size = 6;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/internal_write_append";
    const char *content = "line2\n";
    size_t content_size = 6;
    int r;
    r = guestfs_internal_write_append (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/internal_write_append";
    const char *content = "line3a";
    size_t content_size = 6;
    int r;
    r = guestfs_internal_write_append (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/internal_write_append";
    const char *content = "line3b\n";
    size_t content_size = 7;
    int r;
    r = guestfs_internal_write_append (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/internal_write_append";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_internal_write_append_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_zero_device_0");
    return 0;
  }

  /* InitBasicFS for test_is_zero_device_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for is_zero_device (0) */
  {
    const char *pathordevice = "/dev/sda1";
    struct guestfs_umount_opts_argv optargs;
    optargs.force = 0;
    optargs.lazyunmount = 0;
    optargs.bitmask = UINT64_C(0x3);
    int r;
    r = guestfs_umount_opts_argv (g, pathordevice, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_zero_device (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_is_zero_device (g, device);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_is_zero_device_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_zero_device_1");
    return 0;
  }

  /* InitBasicFS for test_is_zero_device_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_zero_device (1) */
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_is_zero_device (g, device);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_is_zero_device_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_zero_0");
    return 0;
  }

  /* InitISOFS for test_is_zero_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for is_zero (0) */
  {
    const char *path = "/100kallzeroes";
    int r;
    r = guestfs_is_zero (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_is_zero_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_zero_1");
    return 0;
  }

  /* InitISOFS for test_is_zero_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_zero (1) */
  {
    const char *path = "/100kallspaces";
    int r;
    r = guestfs_is_zero (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_is_zero_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkfs_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mkfs (0) */
  const char *expected = "new file contents";
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_mkfs_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvm_canonical_lv_name_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: %s not available)\n", "test_lvm_canonical_lv_name_0", "lvm2");
    return 0;
  }

  /* InitBasicFSonLVM for test_lvm_canonical_lv_name_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for lvm_canonical_lv_name (0) */
  const char *expected = "/dev/VG/LV";
  {
    const char *lvname = "/dev/mapper/VG-LV";
    char *r;
    r = guestfs_lvm_canonical_lv_name (g, lvname);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvm_canonical_lv_name_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvm_canonical_lv_name_1");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: %s not available)\n", "test_lvm_canonical_lv_name_1", "lvm2");
    return 0;
  }

  /* InitBasicFSonLVM for test_lvm_canonical_lv_name_1: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for lvm_canonical_lv_name (1) */
  const char *expected = "/dev/VG/LV";
  {
    const char *lvname = "/dev/VG/LV";
    char *r;
    r = guestfs_lvm_canonical_lv_name (g, lvname);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvm_canonical_lv_name_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pread_device_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_pread_device_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputBuffer for pread_device (0) */
  const char *expected = "CD001\0";
  {
    const char *device = "/dev/sdd";
    char *r;
    size_t size;
    r = guestfs_pread_device (g, device, 8, 32768, &size);
    if (r == NULL)
      return -1;
    if (size != 8) {
      fprintf (stderr, "%s: returned size of buffer wrong, expected 8 but got %zu\n", "test_pread_device_0", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pread_device_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pwrite_device_0");
    return 0;
  }

  /* InitPartition for test_pwrite_device_0: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for pwrite_device (0) */
  {
    const char *device = "/dev/sda";
    const char *content = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    size_t content_size = 66;
    int r;
    r = guestfs_pwrite_device (g, device, content, content_size, 446);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_rereadpt (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_list_partitions (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_pwrite_device_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sdb1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pwrite_device_0", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_pwrite_device_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_download_offset_0");
    return 0;
  }

  /* InitScratchFS for test_download_offset_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for download_offset (0) */
  const char *expected = "4fbd65380cdd255951079008b364516c";
  {
    const char *path = "/download_offset";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/download_offset/COPYING.LIB";
    int r;
    r = guestfs_upload (g, "../../COPYING.LIB", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/download_offset/COPYING.LIB";
    int r;
    r = guestfs_download_offset (g, remotefilename, "testdownload.tmp", 100, 26430);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/download_offset/COPYING.LIB";
    int r;
    r = guestfs_upload_offset (g, "testdownload.tmp", remotefilename, 100);
    if (r == -1)
      return -1;
  }
  {
    const char *csumtype = "md5";
    const char *path = "/download_offset/COPYING.LIB";
    char *r;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_download_offset_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_upload_offset_0");
    return 0;
  }

  /* InitScratchFS for test_upload_offset_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for upload_offset (0) */
  const char *expected = "4fbd65380cdd255951079008b364516c";
  {
    const char *remotefilename = "/upload_offset";
    int r;
    r = guestfs_upload_offset (g, "../../COPYING.LIB", remotefilename, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *csumtype = "md5";
    const char *path = "/upload_offset";
    char *r;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_upload_offset_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_to_dev_0");
    return 0;
  }

  /* InitPartition for test_part_to_dev_0: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestOutputDevice for part_to_dev (0) */
  const char *expected = "/dev/sda";
  {
    const char *partition = "/dev/sda1";
    char *r;
    r = guestfs_part_to_dev (g, partition);
    if (r == NULL)
      return -1;
    r[5] = 's';
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_part_to_dev_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_to_dev_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_to_dev_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for part_to_dev (1) */
  {
    const char *partition = "/dev/sda";
    char *r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_part_to_dev (g, partition);
    guestfs_pop_error_handler (g);
    if (r != NULL)
      return -1;
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_socket_0");
    return 0;
  }

  /* InitISOFS for test_is_socket_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_socket (0) */
  {
    const char *path = "/directory";
    int r;
    r = guestfs_is_socket (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_is_socket_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_symlink_0");
    return 0;
  }

  /* InitISOFS for test_is_symlink_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_symlink (0) */
  {
    const char *path = "/directory";
    int r;
    r = guestfs_is_symlink (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_is_symlink_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_symlink_1");
    return 0;
  }

  /* InitISOFS for test_is_symlink_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for is_symlink (1) */
  {
    const char *path = "/abssymlink";
    int r;
    r = guestfs_is_symlink (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_is_symlink_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_fifo_0");
    return 0;
  }

  /* InitISOFS for test_is_fifo_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_fifo (0) */
  {
    const char *path = "/directory";
    int r;
    r = guestfs_is_fifo (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_is_fifo_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_fifo_1");
    return 0;
  }

  /* InitScratchFS for test_is_fifo_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for is_fifo (1) */
  {
    const char *path = "/is_fifo";
    int r;
    r = guestfs_mkfifo (g, 511, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/is_fifo";
    int r;
    r = guestfs_is_fifo (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_is_fifo_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_blockdev_0");
    return 0;
  }

  /* InitISOFS for test_is_blockdev_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_blockdev (0) */
  {
    const char *path = "/directory";
    int r;
    r = guestfs_is_blockdev (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_is_blockdev_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_blockdev_1");
    return 0;
  }

  /* InitScratchFS for test_is_blockdev_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for is_blockdev (1) */
  {
    const char *path = "/is_blockdev";
    int r;
    r = guestfs_mknod_b (g, 511, 99, 66, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/is_blockdev";
    int r;
    r = guestfs_is_blockdev (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_is_blockdev_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_chardev_0");
    return 0;
  }

  /* InitISOFS for test_is_chardev_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_chardev (0) */
  {
    const char *path = "/directory";
    int r;
    r = guestfs_is_chardev (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_is_chardev_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_chardev_1");
    return 0;
  }

  /* InitScratchFS for test_is_chardev_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for is_chardev (1) */
  {
    const char *path = "/is_chardev";
    int r;
    r = guestfs_mknod_c (g, 511, 99, 66, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/is_chardev";
    int r;
    r = guestfs_is_chardev (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_is_chardev_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_lv_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_is_lv_0", "lvm2");
    return 0;
  }
  /* InitBasicFSonLVM for test_is_lv_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for is_lv (0) */
  {
    const char *device = "/dev/VG/LV";
    int r;
    r = guestfs_is_lv (g, device);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_is_lv_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_lv_1");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_is_lv_1", "lvm2");
    return 0;
  }
  /* InitBasicFSonLVM for test_is_lv_1: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_lv (1) */
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_is_lv (g, device);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_is_lv_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_vfs_uuid_0");
    return 0;
  }

  /* InitBasicFS for test_vfs_uuid_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for vfs_uuid (0) */
  const char *expected = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
  {
    const char *device = "/dev/sda1";
    const char *uuid = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
    int r;
    r = guestfs_set_e2uuid (g, device, uuid);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    char *r;
    r = guestfs_vfs_uuid (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_vfs_uuid_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_vfs_label_0");
    return 0;
  }

  /* InitBasicFS for test_vfs_label_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for vfs_label (0) */
  const char *expected = "LTEST";
  {
    const char *device = "/dev/sda1";
    const char *label = "LTEST";
    int r;
    r = guestfs_set_label (g, device, label);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    char *r;
    r = guestfs_vfs_label (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_vfs_label_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_fallocate64_0");
    return 0;
  }

  /* InitScratchFS for test_fallocate64_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for fallocate64 (0) */
  {
    const char *path = "/fallocate64";
    int r;
    r = guestfs_fallocate64 (g, path, 1000000);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/fallocate64";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->size != 1000000) {
      fprintf (stderr, "%s: size was %d, expected 1000000\n",
               "test_fallocate64_0", (int) r->size);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_available_all_groups_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_available_all_groups_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for available_all_groups (0) */
  {
    char **r;
    size_t i;
    r = guestfs_available_all_groups (g);
    if (r == NULL)
      return -1;
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pwrite_0");
    return 0;
  }

  /* InitScratchFS for test_pwrite_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for pwrite (0) */
  const char *expected = "new data contents";
  {
    const char *path = "/pwrite";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/pwrite";
    const char *content = "data";
    size_t content_size = 4;
    int r;
    r = guestfs_pwrite (g, path, content, content_size, 4);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/pwrite";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pwrite_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pwrite_1");
    return 0;
  }

  /* InitScratchFS for test_pwrite_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for pwrite (1) */
  const char *expected = "new file is extended";
  {
    const char *path = "/pwrite2";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/pwrite2";
    const char *content = "is extended";
    size_t content_size = 11;
    int r;
    r = guestfs_pwrite (g, path, content, content_size, 9);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/pwrite2";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pwrite_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pwrite_2");
    return 0;
  }

  /* InitScratchFS for test_pwrite_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for pwrite (2) */
  const char *expected = "new file contents";
  {
    const char *path = "/pwrite3";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/pwrite3";
    const char *content = "";
    size_t content_size = 0;
    int r;
    r = guestfs_pwrite (g, path, content, content_size, 4);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/pwrite3";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pwrite_2", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_internal_write_0");
    return 0;
  }

  /* InitScratchFS for test_internal_write_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for internal_write (0) */
  const char *expected = "new file contents";
  {
    const char *path = "/internal_write";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_internal_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/internal_write";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_internal_write_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_internal_write_1");
    return 0;
  }

  /* InitScratchFS for test_internal_write_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for internal_write (1) */
  const char *expected = "\nnew file contents\n";
  {
    const char *path = "/internal_write2";
    const char *content = "\nnew file contents\n";
    size_t content_size = 19;
    int r;
    r = guestfs_internal_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/internal_write2";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_internal_write_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_internal_write_2");
    return 0;
  }

  /* InitScratchFS for test_internal_write_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for internal_write (2) */
  const char *expected = "\n\n";
  {
    const char *path = "/internal_write3";
    const char *content = "\n\n";
    size_t content_size = 2;
    int r;
    r = guestfs_internal_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/internal_write3";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_internal_write_2", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_internal_write_3");
    return 0;
  }

  /* InitScratchFS for test_internal_write_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for internal_write (3) */
  const char *expected = "";
  {
    const char *path = "/internal_write4";
    const char *content = "";
    size_t content_size = 0;
    int r;
    r = guestfs_internal_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/internal_write4";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_internal_write_3", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_internal_write_4");
    return 0;
  }

  /* InitScratchFS for test_internal_write_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for internal_write (4) */
  const char *expected = "\n\n\n";
  {
    const char *path = "/internal_write5";
    const char *content = "\n\n\n";
    size_t content_size = 3;
    int r;
    r = guestfs_internal_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/internal_write5";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_internal_write_4", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_internal_write_5");
    return 0;
  }

  /* InitScratchFS for test_internal_write_5 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for internal_write (5) */
  const char *expected = "\n";
  {
    const char *path = "/internal_write6";
    const char *content = "\n";
    size_t content_size = 1;
    int r;
    r = guestfs_internal_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/internal_write6";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_internal_write_5", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_fill_pattern_0");
    return 0;
  }

  /* InitScratchFS for test_fill_pattern_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputBuffer for fill_pattern (0) */
  const char *expected = "abcdefghijklmnopqrstuvwxyzab";
  {
    const char *pattern = "abcdefghijklmnopqrstuvwxyz";
    const char *path = "/fill_pattern";
    int r;
    r = guestfs_fill_pattern (g, pattern, 28, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/fill_pattern";
    char *r;
    size_t size;
    r = guestfs_read_file (g, path, &size);
    if (r == NULL)
      return -1;
    if (size != 28) {
      fprintf (stderr, "%s: returned size of buffer wrong, expected 28 but got %zu\n", "test_fill_pattern_0", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_fill_pattern_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_base64_in_0");
    return 0;
  }

  /* InitScratchFS for test_base64_in_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for base64_in (0) */
  const char *expected = "hello\n";
  {
    const char *filename = "/base64_in";
    int r;
    r = guestfs_base64_in (g, "../data/hello.b64", filename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/base64_in";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_base64_in_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_umask_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_umask_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for get_umask (0) */
  {
    int r;
    r = guestfs_get_umask (g);
    if (r == -1)
      return -1;
    if (r != 18) {
      fprintf (stderr, "%s: expected 18 but got %d\n",               "test_get_umask_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvresize_free_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvresize_free_0", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_lvresize_free_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for lvresize_free (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 10);
    if (r == -1)
      return -1;
  }
  {
    const char *lv = "/dev/VG/LV";
    int r;
    r = guestfs_lvresize_free (g, lv, 100);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_device_0");
    return 0;
  }

  /* InitISOFS for test_checksum_device_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFileMD5 for checksum_device (0) */
  char expected[33];
  md5sum ("../data/test.iso", expected);
  {
    const char *csumtype = "md5";
    const char *device = "/dev/sdd";
    char *r;
    r = guestfs_checksum_device (g, csumtype, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_checksum_device_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_get_mbr_id_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_get_mbr_id_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for part_get_mbr_id (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    r = guestfs_part_add (g, device, prlogex, 1, -1);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_part_set_mbr_id (g, device, 1, 127);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_part_get_mbr_id (g, device, 1);
    if (r == -1)
      return -1;
    if (r != 127) {
      fprintf (stderr, "%s: expected 127 but got %d\n",               "test_part_get_mbr_id_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_get_bootable_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_get_bootable_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for part_get_bootable (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    r = guestfs_part_add (g, device, prlogex, 1, -1);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_part_set_bootable (g, device, 1, 1);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_part_get_bootable (g, device, 1);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_part_get_bootable_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_del_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_del_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_del (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    r = guestfs_part_add (g, device, prlogex, 1, -1);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_part_del (g, device, 1);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgscan_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_vgscan_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for vgscan (0) */
  {
    int r;
    r = guestfs_vgscan (g);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_txz_in_0");
    return 0;
  }

  if (!is_available ("xz")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_txz_in_0", "xz");
    return 0;
  }
  /* InitScratchFS for test_txz_in_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for txz_in (0) */
  const char *expected = "hello\n";
  {
    const char *path = "/txz_in";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *directory = "/txz_in";
    int r;
    r = guestfs_txz_in (g, "../data/helloworld.tar.xz", directory);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/txz_in/hello";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_txz_in_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_zero_device_0");
    return 0;
  }

  /* InitBasicFSonLVM for test_zero_device_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for zero_device (0) */
  {
    const char *device = "/dev/VG/LV";
    int r;
    r = guestfs_zero_device (g, device);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_copy_size_0");
    return 0;
  }

  /* InitScratchFS for test_copy_size_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputBuffer for copy_size (0) */
  const char *expected = "hello";
  {
    const char *path = "/copy_size";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/copy_size/src";
    const char *content = "hello, world";
    size_t content_size = 12;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/copy_size/src";
    const char *dest = "/copy_size/dest";
    int r;
    r = guestfs_copy_size (g, src, dest, 5);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/copy_size/dest";
    char *r;
    size_t size;
    r = guestfs_read_file (g, path, &size);
    if (r == NULL)
      return -1;
    if (size != 5) {
      fprintf (stderr, "%s: returned size of buffer wrong, expected 5 but got %zu\n", "test_copy_size_0", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_copy_size_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_initrd_cat_0");
    return 0;
  }

  /* InitISOFS for test_initrd_cat_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputBuffer for initrd_cat (0) */
  const char *expected = "abc\ndef\nghi";
  {
    const char *initrdpath = "/initrd";
    const char *filename = "known-4";
    char *r;
    size_t size;
    r = guestfs_initrd_cat (g, initrdpath, filename, &size);
    if (r == NULL)
      return -1;
    if (size != 11) {
      fprintf (stderr, "%s: returned size of buffer wrong, expected 11 but got %zu\n", "test_initrd_cat_0", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_initrd_cat_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgrename_0");
    return 0;
  }

  /* InitBasicFSonLVM for test_vgrename_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for vgrename (0) */
  {
    const char *pathordevice = "/";
    struct guestfs_umount_opts_argv optargs;
    optargs.force = 0;
    optargs.lazyunmount = 0;
    optargs.bitmask = UINT64_C(0x3);
    int r;
    r = guestfs_umount_opts_argv (g, pathordevice, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroups_0 = "VG";
    const char *const volgroups[] = {
      volgroups_0,
      NULL
    };
    int r;
    r = guestfs_vg_activate (g, 0, (char **) volgroups);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *newvolgroup = "VG2";
    int r;
    r = guestfs_vgrename (g, volgroup, newvolgroup);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroups_0 = "VG2";
    const char *const volgroups[] = {
      volgroups_0,
      NULL
    };
    int r;
    r = guestfs_vg_activate (g, 1, (char **) volgroups);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG2/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_vgrename_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG2";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_vgrename_0", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_vgrename_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvrename_0");
    return 0;
  }

  /* InitBasicFSonLVM for test_lvrename_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvrename (0) */
  {
    const char *logvol = "/dev/VG/LV";
    const char *newlogvol = "/dev/VG/LV2";
    int r;
    r = guestfs_lvrename (g, logvol, newlogvol);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvrename_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG/LV2";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvrename_0", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_lvrename_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_filesize_0");
    return 0;
  }

  /* InitScratchFS for test_filesize_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for filesize (0) */
  {
    const char *path = "/filesize";
    const char *content = "hello, world";
    size_t content_size = 12;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/filesize";
    int64_t r;
    r = guestfs_filesize (g, file);
    if (r == -1)
      return -1;
    if (r != 12) {
      fprintf (stderr, "%s: expected 12 but got %d\n",               "test_filesize_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_dd_0");
    return 0;
  }

  /* InitScratchFS for test_dd_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputBuffer for dd (0) */
  const char *expected = "hello, world";
  {
    const char *path = "/dd";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/dd/src";
    const char *content = "hello, world";
    size_t content_size = 12;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/dd/src";
    const char *dest = "/dd/dest";
    int r;
    r = guestfs_dd (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/dd/dest";
    char *r;
    size_t size;
    r = guestfs_read_file (g, path, &size);
    if (r == NULL)
      return -1;
    if (size != 12) {
      fprintf (stderr, "%s: returned size of buffer wrong, expected 12 but got %zu\n", "test_dd_0", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_dd_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_available_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_available_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for available (0) */
  {
    const char *const groups[1] = { NULL };
    int r;
    r = guestfs_available (g, (char **) groups);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_fill_0");
    return 0;
  }

  /* InitScratchFS for test_fill_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputBuffer for fill (0) */
  const char *expected = "cccccccccc";
  {
    const char *path = "/fill";
    int r;
    r = guestfs_fill (g, 99, 10, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/fill";
    char *r;
    size_t size;
    r = guestfs_read_file (g, path, &size);
    if (r == NULL)
      return -1;
    if (size != 10) {
      fprintf (stderr, "%s: returned size of buffer wrong, expected 10 but got %zu\n", "test_fill_0", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_fill_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_get_parttype_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_get_parttype_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for part_get_parttype (0) */
  const char *expected = "gpt";
  {
    const char *device = "/dev/sda";
    const char *parttype = "gpt";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    char *r;
    r = guestfs_part_get_parttype (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_part_get_parttype_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_set_name_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_set_name_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_set_name (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "gpt";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *name = "thepartname";
    int r;
    r = guestfs_part_set_name (g, device, 1, name);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_set_bootable_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_set_bootable_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_set_bootable (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_part_set_bootable (g, device, 1, 1);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_disk_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_disk_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_disk (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_disk_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_disk_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_disk (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "gpt";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_add_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_add_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_add (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    r = guestfs_part_add (g, device, prlogex, 1, -1);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_add_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_add_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_add (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "gpt";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    r = guestfs_part_add (g, device, prlogex, 34, 127);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    r = guestfs_part_add (g, device, prlogex, 128, -34);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_add_2");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_add_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_add (2) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    r = guestfs_part_add (g, device, prlogex, 32, 127);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    r = guestfs_part_add (g, device, prlogex, 128, 255);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    r = guestfs_part_add (g, device, prlogex, 256, 511);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    r = guestfs_part_add (g, device, prlogex, 512, -1);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_init_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_init_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_init (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "gpt";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pread_0");
    return 0;
  }

  /* InitISOFS for test_pread_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputBuffer for pread (0) */
  const char *expected = "\n";
  {
    const char *path = "/known-4";
    char *r;
    size_t size;
    r = guestfs_pread (g, path, 1, 3, &size);
    if (r == NULL)
      return -1;
    if (size != 1) {
      fprintf (stderr, "%s: returned size of buffer wrong, expected 1 but got %zu\n", "test_pread_0", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pread_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pread_1");
    return 0;
  }

  /* InitISOFS for test_pread_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputBuffer for pread (1) */
  const char *expected = "";
  {
    const char *path = "/empty";
    char *r;
    size_t size;
    r = guestfs_pread (g, path, 0, 100, &size);
    if (r == NULL)
      return -1;
    if (size != 0) {
      fprintf (stderr, "%s: returned size of buffer wrong, expected 0 but got %zu\n", "test_pread_1", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pread_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_mode_0");
    return 0;
  }

  /* InitScratchFS for test_mkdir_mode_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for mkdir_mode (0) */
  {
    const char *path = "/mkdir_mode";
    int r;
    r = guestfs_mkdir_mode (g, path, 73);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mkdir_mode";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 16457) {
      fprintf (stderr, "%s: mode was %d, expected 16457\n",
               "test_mkdir_mode_0", (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_utimens_0");
    return 0;
  }

  /* InitScratchFS for test_utimens_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for utimens (0) */
  {
    const char *path = "/utimens-file";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/utimens-file";
    int r;
    r = guestfs_utimens (g, path, 12345, 67890, 9876, 5432);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/utimens-file";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mtime != 9876) {
      fprintf (stderr, "%s: mtime was %d, expected 9876\n",
               "test_utimens_0", (int) r->mtime);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_utimens_1");
    return 0;
  }

  /* InitScratchFS for test_utimens_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for utimens (1) */
  {
    const char *path = "/utimens-dir";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/utimens-dir";
    int r;
    r = guestfs_utimens (g, path, 12345, 67890, 9876, 5432);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/utimens-dir";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mtime != 9876) {
      fprintf (stderr, "%s: mtime was %d, expected 9876\n",
               "test_utimens_1", (int) r->mtime);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_utimens_2");
    return 0;
  }

  /* InitScratchFS for test_utimens_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for utimens (2) */
  {
    const char *path = "/utimens-fifo";
    int r;
    r = guestfs_mkfifo (g, 420, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/utimens-fifo";
    int r;
    r = guestfs_utimens (g, path, 12345, 67890, 9876, 5432);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/utimens-fifo";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mtime != 9876) {
      fprintf (stderr, "%s: mtime was %d, expected 9876\n",
               "test_utimens_2", (int) r->mtime);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_utimens_3");
    return 0;
  }

  /* InitScratchFS for test_utimens_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for utimens (3) */
  {
    const char *target = "/utimens-file";
    const char *linkname = "/utimens-link";
    int r;
    r = guestfs_ln_sf (g, target, linkname);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/utimens-link";
    int r;
    r = guestfs_utimens (g, path, 12345, 67890, 9876, 5432);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/utimens-link";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mtime != 9876) {
      fprintf (stderr, "%s: mtime was %d, expected 9876\n",
               "test_utimens_3", (int) r->mtime);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_utimens_4");
    return 0;
  }

  /* InitScratchFS for test_utimens_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for utimens (4) */
  {
    const char *path = "/utimens-block";
    int r;
    r = guestfs_mknod_b (g, 420, 8, 0, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/utimens-block";
    int r;
    r = guestfs_utimens (g, path, 12345, 67890, 9876, 5432);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/utimens-block";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mtime != 9876) {
      fprintf (stderr, "%s: mtime was %d, expected 9876\n",
               "test_utimens_4", (int) r->mtime);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_utimens_5");
    return 0;
  }

  /* InitScratchFS for test_utimens_5 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for utimens (5) */
  {
    const char *path = "/utimens-char";
    int r;
    r = guestfs_mknod_c (g, 420, 1, 3, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/utimens-char";
    int r;
    r = guestfs_utimens (g, path, 12345, 67890, 9876, 5432);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/utimens-char";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mtime != 9876) {
      fprintf (stderr, "%s: mtime was %d, expected 9876\n",
               "test_utimens_5", (int) r->mtime);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_truncate_size_0");
    return 0;
  }

  /* InitScratchFS for test_truncate_size_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for truncate_size (0) */
  {
    const char *path = "/truncate_size";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/truncate_size";
    int r;
    r = guestfs_truncate_size (g, path, 1000);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/truncate_size";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->size != 1000) {
      fprintf (stderr, "%s: size was %d, expected 1000\n",
               "test_truncate_size_0", (int) r->size);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_truncate_0");
    return 0;
  }

  /* InitScratchFS for test_truncate_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for truncate (0) */
  {
    const char *path = "/truncate";
    const char *content = "some stuff so size is not zero";
    size_t content_size = 30;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/truncate";
    int r;
    r = guestfs_truncate (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/truncate";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->size != 0) {
      fprintf (stderr, "%s: size was %d, expected 0\n",
               "test_truncate_0", (int) r->size);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_vfs_type_0");
    return 0;
  }

  /* InitScratchFS for test_vfs_type_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for vfs_type (0) */
  const char *expected = "ext2";
  {
    const char *device = "/dev/sdb1";
    char *r;
    r = guestfs_vfs_type (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_vfs_type_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_0");
    return 0;
  }

  /* InitISOFS for test_case_sensitive_path_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for case_sensitive_path (0) */
  const char *expected = "/directory";
  {
    const char *path = "/DIRECTORY";
    char *r;
    r = guestfs_case_sensitive_path (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_case_sensitive_path_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_1");
    return 0;
  }

  /* InitISOFS for test_case_sensitive_path_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for case_sensitive_path (1) */
  const char *expected = "/directory";
  {
    const char *path = "/DIRECTORY/";
    char *r;
    r = guestfs_case_sensitive_path (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_case_sensitive_path_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_2");
    return 0;
  }

  /* InitISOFS for test_case_sensitive_path_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for case_sensitive_path (2) */
  const char *expected = "/known-1";
  {
    const char *path = "/Known-1";
    char *r;
    r = guestfs_case_sensitive_path (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_case_sensitive_path_2", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_3");
    return 0;
  }

  /* InitISOFS for test_case_sensitive_path_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for case_sensitive_path (3) */
  {
    const char *path = "/Known-1/";
    char *r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_case_sensitive_path (g, path);
    guestfs_pop_error_handler (g);
    if (r != NULL)
      return -1;
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_4");
    return 0;
  }

  /* InitScratchFS for test_case_sensitive_path_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for case_sensitive_path (4) */
  const char *expected = "/case_sensitive_path/bbb/c";
  {
    const char *path = "/case_sensitive_path";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/case_sensitive_path/bbb";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/case_sensitive_path/bbb/c";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/CASE_SENSITIVE_path/bbB/C";
    char *r;
    r = guestfs_case_sensitive_path (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_case_sensitive_path_4", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_5");
    return 0;
  }

  /* InitScratchFS for test_case_sensitive_path_5 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for case_sensitive_path (5) */
  const char *expected = "/case_sensitive_path2/bbb/c";
  {
    const char *path = "/case_sensitive_path2";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/case_sensitive_path2/bbb";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/case_sensitive_path2/bbb/c";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/case_sensitive_PATH2////bbB/C";
    char *r;
    r = guestfs_case_sensitive_path (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_case_sensitive_path_5", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_6");
    return 0;
  }

  /* InitScratchFS for test_case_sensitive_path_6 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for case_sensitive_path (6) */
  {
    const char *path = "/case_sensitive_path3";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/case_sensitive_path3/bbb";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/case_sensitive_path3/bbb/c";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/case_SENSITIVE_path3/bbb/../bbb/C";
    char *r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_case_sensitive_path (g, path);
    guestfs_pop_error_handler (g);
    if (r != NULL)
      return -1;
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_7");
    return 0;
  }

  /* InitScratchFS for test_case_sensitive_path_7 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for case_sensitive_path (7) */
  const char *expected = "/case_sensitive_path4/new_file";
  {
    const char *path = "/case_sensitive_path4";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/case_SENSITIVE_path4/new_file";
    char *r;
    r = guestfs_case_sensitive_path (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_case_sensitive_path_7", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_echo_daemon_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_echo_daemon_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for echo_daemon (0) */
  const char *expected = "This is a test";
  {
    const char *words_0 = "This";
    const char *words_1 = "is";
    const char *words_2 = "a";
    const char *words_3 = "test";
    const char *const words[] = {
      words_0,
      words_1,
      words_2,
      words_3,
      NULL
    };
    char *r;
    r = guestfs_echo_daemon (g, (char **) words);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_echo_daemon_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_modprobe_0");
    return 0;
  }

  if (!is_available ("linuxmodules")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_modprobe_0", "linuxmodules");
    return 0;
  }
  /* InitNone|InitEmpty for test_modprobe_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for modprobe (0) */
  {
    const char *modulename = "fat";
    int r;
    r = guestfs_modprobe (g, modulename);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mke2journal_U_0");
    return 0;
  }

  if (!is_available ("linuxfsuuid")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mke2journal_U_0", "linuxfsuuid");
    return 0;
  }
  /* InitNone|InitEmpty for test_mke2journal_U_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mke2journal_U (0) */
  const char *expected = "new file contents";
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, -64);
    if (r == -1)
      return -1;
  }
  {
    const char *uuid = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_mke2journal_U (g, 4096, uuid, device);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda2";
    const char *uuid = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
    int r;
    r = guestfs_mke2fs_JU (g, fstype, 4096, device, uuid);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_mke2journal_U_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mke2journal_L_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mke2journal_L_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mke2journal_L (0) */
  const char *expected = "new file contents";
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, -64);
    if (r == -1)
      return -1;
  }
  {
    const char *label = "JOURNAL";
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_mke2journal_L (g, 4096, label, device);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda2";
    const char *label = "JOURNAL";
    int r;
    r = guestfs_mke2fs_JL (g, fstype, 4096, device, label);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_mke2journal_L_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mke2journal_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mke2journal_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mke2journal (0) */
  const char *expected = "new file contents";
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, -64);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_mke2journal (g, 4096, device);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda2";
    const char *journal = "/dev/sda1";
    int r;
    r = guestfs_mke2fs_J (g, fstype, 4096, device, journal);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_mke2journal_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkfs_b_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_b_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mkfs_b (0) */
  const char *expected = "new file contents";
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_mkfs_b (g, fstype, 4096, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_mkfs_b_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkfs_b_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_b_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkfs_b (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "vfat";
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_mkfs_b (g, fstype, 32768, device);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkfs_b_2");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_b_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for mkfs_b (2) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "vfat";
    const char *device = "/dev/sda1";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_mkfs_b (g, fstype, 32769, device);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkfs_b_3");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_b_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for mkfs_b (3) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "vfat";
    const char *device = "/dev/sda1";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_mkfs_b (g, fstype, 33280, device);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkfs_b_4");
    return 0;
  }

  if (!is_available ("ntfsprogs")) {
    printf ("        %s skipped (reason: %s not available)\n", "test_mkfs_b_4", "ntfsprogs");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_b_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkfs_b (4) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ntfs";
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_mkfs_b (g, fstype, 32768, device);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_inotify_add_watch_0");
    return 0;
  }

  if (!is_available ("inotify")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_inotify_add_watch_0", "inotify");
    return 0;
  }
  /* InitScratchFS for test_inotify_add_watch_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for inotify_add_watch (0) */
  {
    const char *path = "/inotify_add_watch";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_inotify_init (g, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/inotify_add_watch";
    int64_t r;
    r = guestfs_inotify_add_watch (g, path, 1073741823);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/inotify_add_watch/a";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/inotify_add_watch/b";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_inotify_files (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_inotify_add_watch_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "a";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_inotify_add_watch_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_inotify_add_watch_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "b";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_inotify_add_watch_0", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_inotify_add_watch_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_inotify_init_0");
    return 0;
  }

  if (!is_available ("inotify")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_inotify_init_0", "inotify");
    return 0;
  }
  /* InitISOFS for test_inotify_init_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for inotify_init (0) */
  {
    int r;
    r = guestfs_inotify_init (g, 0);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkswap_file_0");
    return 0;
  }

  /* InitScratchFS for test_mkswap_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkswap_file (0) */
  {
    const char *path = "/mkswap_file";
    int r;
    r = guestfs_fallocate (g, path, 8388608);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mkswap_file";
    int r;
    r = guestfs_mkswap_file (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mkswap_file";
    int r;
    r = guestfs_rm (g, path);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_swapon_uuid_0");
    return 0;
  }

  if (!is_available ("linuxfsuuid")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_swapon_uuid_0", "linuxfsuuid");
    return 0;
  }
  /* InitNone|InitEmpty for test_swapon_uuid_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for swapon_uuid (0) */
  {
    const char *device = "/dev/sdc";
    struct guestfs_mkswap_opts_argv optargs;
    optargs.uuid = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
    optargs.bitmask = UINT64_C(0x2);
    int r;
    r = guestfs_mkswap_opts_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *uuid = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
    int r;
    r = guestfs_swapon_uuid (g, uuid);
    if (r == -1)
      return -1;
  }
  {
    const char *uuid = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
    int r;
    r = guestfs_swapoff_uuid (g, uuid);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_swapon_label_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_swapon_label_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for swapon_label (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    struct guestfs_mkswap_opts_argv optargs;
    optargs.label = "swapit";
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_mkswap_opts_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *label = "swapit";
    int r;
    r = guestfs_swapon_label (g, label);
    if (r == -1)
      return -1;
  }
  {
    const char *label = "swapit";
    int r;
    r = guestfs_swapoff_label (g, label);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_zero (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_rereadpt (g, device);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_swapon_file_0");
    return 0;
  }

  /* InitScratchFS for test_swapon_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for swapon_file (0) */
  {
    const char *path = "/swapon_file";
    int r;
    r = guestfs_fallocate (g, path, 8388608);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/swapon_file";
    int r;
    r = guestfs_mkswap_file (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/swapon_file";
    int r;
    r = guestfs_swapon_file (g, file);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/swapon_file";
    int r;
    r = guestfs_swapoff_file (g, file);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/swapon_file";
    int r;
    r = guestfs_rm (g, path);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_swapon_device_0");
    return 0;
  }

  /* InitPartition for test_swapon_device_0: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestRun for swapon_device (0) */
  {
    const char *device = "/dev/sda1";
    struct guestfs_mkswap_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkswap_opts_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_swapon_device (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_swapoff_device (g, device);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_fallocate_0");
    return 0;
  }

  /* InitScratchFS for test_fallocate_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for fallocate (0) */
  {
    const char *path = "/fallocate";
    int r;
    r = guestfs_fallocate (g, path, 1000000);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/fallocate";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->size != 1000000) {
      fprintf (stderr, "%s: size was %d, expected 1000000\n",
               "test_fallocate_0", (int) r->size);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_ln_sf_0");
    return 0;
  }

  /* InitScratchFS for test_ln_sf_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for ln_sf (0) */
  const char *expected = "../d";
  {
    const char *path = "/ln_sf/b";
    int r;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/ln_sf/b/c";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *target = "../d";
    const char *linkname = "/ln_sf/b/c";
    int r;
    r = guestfs_ln_sf (g, target, linkname);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/ln_sf/b/c";
    char *r;
    r = guestfs_readlink (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_ln_sf_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_ln_s_0");
    return 0;
  }

  /* InitScratchFS for test_ln_s_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for ln_s (0) */
  {
    const char *path = "/ln_s";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/ln_s/a";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *target = "a";
    const char *linkname = "/ln_s/b";
    int r;
    r = guestfs_ln_s (g, target, linkname);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/ln_s/b";
    struct guestfs_stat *r;
    r = guestfs_lstat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 41471) {
      fprintf (stderr, "%s: mode was %d, expected 41471\n",
               "test_ln_s_0", (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_ln_f_0");
    return 0;
  }

  /* InitScratchFS for test_ln_f_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for ln_f (0) */
  {
    const char *path = "/ln_f";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/ln_f/a";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/ln_f/b";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *target = "/ln_f/a";
    const char *linkname = "/ln_f/b";
    int r;
    r = guestfs_ln_f (g, target, linkname);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/ln_f/b";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->nlink != 2) {
      fprintf (stderr, "%s: nlink was %d, expected 2\n",
               "test_ln_f_0", (int) r->nlink);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_ln_0");
    return 0;
  }

  /* InitScratchFS for test_ln_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for ln (0) */
  {
    const char *path = "/ln";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/ln/a";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *target = "/ln/a";
    const char *linkname = "/ln/b";
    int r;
    r = guestfs_ln (g, target, linkname);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/ln/b";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->nlink != 2) {
      fprintf (stderr, "%s: nlink was %d, expected 2\n",
               "test_ln_0", (int) r->nlink);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_realpath_0");
    return 0;
  }

  if (!is_available ("realpath")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_realpath_0", "realpath");
    return 0;
  }
  /* InitISOFS for test_realpath_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for realpath (0) */
  const char *expected = "/directory";
  {
    const char *path = "/../directory";
    char *r;
    r = guestfs_realpath (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_realpath_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_zfgrepi_0");
    return 0;
  }

  /* InitISOFS for test_zfgrepi_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for zfgrepi (0) */
  {
    const char *pattern = "abc";
    const char *path = "/test-grep.txt.gz";
    char **r;
    size_t i;
    r = guestfs_zfgrepi (g, pattern, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zfgrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zfgrepi_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zfgrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zfgrepi_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zfgrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zfgrepi_0", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_zfgrepi_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_zegrepi_0");
    return 0;
  }

  /* InitISOFS for test_zegrepi_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for zegrepi (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    char **r;
    size_t i;
    r = guestfs_zegrepi (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zegrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zegrepi_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zegrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zegrepi_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zegrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zegrepi_0", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_zegrepi_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_zgrepi_0");
    return 0;
  }

  /* InitISOFS for test_zgrepi_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for zgrepi (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    char **r;
    size_t i;
    r = guestfs_zgrepi (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zgrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zgrepi_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zgrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zgrepi_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zgrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zgrepi_0", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_zgrepi_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_zfgrep_0");
    return 0;
  }

  /* InitISOFS for test_zfgrep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for zfgrep (0) */
  {
    const char *pattern = "abc";
    const char *path = "/test-grep.txt.gz";
    char **r;
    size_t i;
    r = guestfs_zfgrep (g, pattern, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zfgrep_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zfgrep_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zfgrep_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zfgrep_0", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_zfgrep_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_zegrep_0");
    return 0;
  }

  /* InitISOFS for test_zegrep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for zegrep (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    char **r;
    size_t i;
    r = guestfs_zegrep (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zegrep_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zegrep_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zegrep_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zegrep_0", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_zegrep_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_zgrep_0");
    return 0;
  }

  /* InitISOFS for test_zgrep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for zgrep (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    char **r;
    size_t i;
    r = guestfs_zgrep (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zgrep_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zgrep_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_zgrep_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zgrep_0", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_zgrep_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_fgrepi_0");
    return 0;
  }

  /* InitISOFS for test_fgrepi_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for fgrepi (0) */
  {
    const char *pattern = "abc";
    const char *path = "/test-grep.txt";
    char **r;
    size_t i;
    r = guestfs_fgrepi (g, pattern, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_fgrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_fgrepi_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_fgrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_fgrepi_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_fgrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_fgrepi_0", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_fgrepi_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_egrepi_0");
    return 0;
  }

  /* InitISOFS for test_egrepi_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for egrepi (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt";
    char **r;
    size_t i;
    r = guestfs_egrepi (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_egrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_egrepi_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_egrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_egrepi_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_egrepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_egrepi_0", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_egrepi_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grepi_0");
    return 0;
  }

  /* InitISOFS for test_grepi_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grepi (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt";
    char **r;
    size_t i;
    r = guestfs_grepi (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grepi_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grepi_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grepi_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grepi_0", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grepi_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_fgrep_0");
    return 0;
  }

  /* InitISOFS for test_fgrep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for fgrep (0) */
  {
    const char *pattern = "abc";
    const char *path = "/test-grep.txt";
    char **r;
    size_t i;
    r = guestfs_fgrep (g, pattern, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_fgrep_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_fgrep_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_fgrep_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_fgrep_0", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_fgrep_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_egrep_0");
    return 0;
  }

  /* InitISOFS for test_egrep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for egrep (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt";
    char **r;
    size_t i;
    r = guestfs_egrep (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_egrep_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_egrep_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_egrep_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_egrep_0", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_egrep_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_0");
    return 0;
  }

  /* InitISOFS for test_grep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt";
    struct guestfs_grep_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_0", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_1");
    return 0;
  }

  /* InitISOFS for test_grep_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (1) */
  {
    const char *regex = "nomatch";
    const char *path = "/test-grep.txt";
    struct guestfs_grep_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_2");
    return 0;
  }

  /* InitISOFS for test_grep_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (2) */
  {
    const char *regex = "nomatch";
    const char *path = "/abssymlink";
    struct guestfs_grep_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_2");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_3");
    return 0;
  }

  /* InitISOFS for test_grep_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (3) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt";
    struct guestfs_grep_opts_argv optargs;
    optargs.extended = 1;
    optargs.bitmask = UINT64_C(0x1);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_3");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_3", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_3");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_3", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_3");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_4");
    return 0;
  }

  /* InitISOFS for test_grep_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (4) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt";
    struct guestfs_grep_opts_argv optargs;
    optargs.fixed = 1;
    optargs.bitmask = UINT64_C(0x2);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_4");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_4", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_4");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_4", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_4");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_5");
    return 0;
  }

  /* InitISOFS for test_grep_5 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (5) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt";
    struct guestfs_grep_opts_argv optargs;
    optargs.insensitive = 1;
    optargs.bitmask = UINT64_C(0x4);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_5");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_5", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_5");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_5", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_5");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_5", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_5");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_6");
    return 0;
  }

  /* InitISOFS for test_grep_6 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (6) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt";
    struct guestfs_grep_opts_argv optargs;
    optargs.extended = 1;
    optargs.insensitive = 1;
    optargs.bitmask = UINT64_C(0x5);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_6");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_6", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_6");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_6", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_6");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_6", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_6");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_7");
    return 0;
  }

  /* InitISOFS for test_grep_7 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (7) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt";
    struct guestfs_grep_opts_argv optargs;
    optargs.fixed = 1;
    optargs.insensitive = 1;
    optargs.bitmask = UINT64_C(0x6);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_7");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_7", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_7");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_7", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_7");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_7", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_7");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_8");
    return 0;
  }

  /* InitISOFS for test_grep_8 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (8) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    struct guestfs_grep_opts_argv optargs;
    optargs.compressed = 1;
    optargs.bitmask = UINT64_C(0x8);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_8");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_8", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_8");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_8", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_8");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_9");
    return 0;
  }

  /* InitISOFS for test_grep_9 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (9) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    struct guestfs_grep_opts_argv optargs;
    optargs.extended = 1;
    optargs.compressed = 1;
    optargs.bitmask = UINT64_C(0x9);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_9");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_9", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_9");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_9", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_9");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_10");
    return 0;
  }

  /* InitISOFS for test_grep_10 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (10) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    struct guestfs_grep_opts_argv optargs;
    optargs.fixed = 1;
    optargs.compressed = 1;
    optargs.bitmask = UINT64_C(0xa);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_10");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_10", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_10");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_10", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_10");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_11");
    return 0;
  }

  /* InitISOFS for test_grep_11 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (11) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    struct guestfs_grep_opts_argv optargs;
    optargs.insensitive = 1;
    optargs.compressed = 1;
    optargs.bitmask = UINT64_C(0xc);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_11");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_11", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_11");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_11", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_11");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_11", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_11");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_12");
    return 0;
  }

  /* InitISOFS for test_grep_12 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (12) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    struct guestfs_grep_opts_argv optargs;
    optargs.extended = 1;
    optargs.insensitive = 1;
    optargs.compressed = 1;
    optargs.bitmask = UINT64_C(0xd);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_12");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_12", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_12");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_12", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_12");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_12", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_12");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_13");
    return 0;
  }

  /* InitISOFS for test_grep_13 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (13) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    struct guestfs_grep_opts_argv optargs;
    optargs.fixed = 1;
    optargs.insensitive = 1;
    optargs.compressed = 1;
    optargs.bitmask = UINT64_C(0xe);
    char **r;
    size_t i;
    r = guestfs_grep_opts_argv (g, regex, path, &optargs);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_13");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_13", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_13");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_13", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_grep_13");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_grep_13", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_grep_13");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_umask_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_umask_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for umask (0) */
  {
    int r;
    r = guestfs_umask (g, 18);
    if (r == -1)
      return -1;
    if (r != 18) {
      fprintf (stderr, "%s: expected 18 but got %d\n",               "test_umask_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mknod_c_0");
    return 0;
  }

  if (!is_available ("mknod")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mknod_c_0", "mknod");
    return 0;
  }
  /* InitScratchFS for test_mknod_c_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for mknod_c (0) */
  {
    const char *path = "/mknod_c";
    int r;
    r = guestfs_mknod_c (g, 511, 99, 66, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mknod_c";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 8685) {
      fprintf (stderr, "%s: mode was %d, expected 8685\n",
               "test_mknod_c_0", (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mknod_b_0");
    return 0;
  }

  if (!is_available ("mknod")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mknod_b_0", "mknod");
    return 0;
  }
  /* InitScratchFS for test_mknod_b_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for mknod_b (0) */
  {
    const char *path = "/mknod_b";
    int r;
    r = guestfs_mknod_b (g, 511, 99, 66, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mknod_b";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 25069) {
      fprintf (stderr, "%s: mode was %d, expected 25069\n",
               "test_mknod_b_0", (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkfifo_0");
    return 0;
  }

  if (!is_available ("mknod")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mkfifo_0", "mknod");
    return 0;
  }
  /* InitScratchFS for test_mkfifo_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for mkfifo (0) */
  {
    const char *path = "/mkfifo";
    int r;
    r = guestfs_mkfifo (g, 511, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mkfifo";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 4589) {
      fprintf (stderr, "%s: mode was %d, expected 4589\n",
               "test_mkfifo_0", (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mknod_0");
    return 0;
  }

  if (!is_available ("mknod")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mknod_0", "mknod");
    return 0;
  }
  /* InitScratchFS for test_mknod_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for mknod (0) */
  {
    const char *path = "/mknod";
    int r;
    r = guestfs_mknod (g, 4607, 0, 0, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mknod";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 4589) {
      fprintf (stderr, "%s: mode was %d, expected 4589\n",
               "test_mknod_0", (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mknod_1");
    return 0;
  }

  if (!is_available ("mknod")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mknod_1", "mknod");
    return 0;
  }
  /* InitScratchFS for test_mknod_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for mknod (1) */
  {
    const char *path = "/mknod2";
    int r;
    r = guestfs_mknod (g, 25087, 66, 99, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mknod2";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 25069) {
      fprintf (stderr, "%s: mode was %d, expected 25069\n",
               "test_mknod_1", (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkswap_U_0");
    return 0;
  }

  if (!is_available ("linuxfsuuid")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mkswap_U_0", "linuxfsuuid");
    return 0;
  }
  /* InitNone|InitEmpty for test_mkswap_U_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkswap_U (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *uuid = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_mkswap_U (g, uuid, device);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkswap_L_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkswap_L_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkswap_L (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *label = "hello";
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_mkswap_L (g, label, device);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkswap_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkswap_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkswap (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    struct guestfs_mkswap_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkswap_opts_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkswap_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkswap_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkswap (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    struct guestfs_mkswap_opts_argv optargs;
    optargs.label = "hello";
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_mkswap_opts_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkswap_2");
    return 0;
  }

  if (!is_available ("linuxfsuuid")) {
    printf ("        %s skipped (reason: %s not available)\n", "test_mkswap_2", "linuxfsuuid");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkswap_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkswap (2) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    struct guestfs_mkswap_opts_argv optargs;
    optargs.uuid = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
    optargs.bitmask = UINT64_C(0x2);
    int r;
    r = guestfs_mkswap_opts_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkswap_3");
    return 0;
  }

  if (!is_available ("linuxfsuuid")) {
    printf ("        %s skipped (reason: %s not available)\n", "test_mkswap_3", "linuxfsuuid");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkswap_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkswap (3) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    struct guestfs_mkswap_opts_argv optargs;
    optargs.label = "hello";
    optargs.uuid = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
    optargs.bitmask = UINT64_C(0x3);
    int r;
    r = guestfs_mkswap_opts_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_initrd_list_0");
    return 0;
  }

  /* InitISOFS for test_initrd_list_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for initrd_list (0) */
  {
    const char *path = "/initrd";
    char **r;
    size_t i;
    r = guestfs_initrd_list (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_initrd_list_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "empty";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_initrd_list_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_initrd_list_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "known-1";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_initrd_list_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_initrd_list_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "known-2";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_initrd_list_0", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_initrd_list_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "known-3";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_initrd_list_0", expected, r[3]);
        return -1;
      }
    }
    if (!r[4]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_initrd_list_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "known-4";
      if (STRNEQ (r[4], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_initrd_list_0", expected, r[4]);
        return -1;
      }
    }
    if (!r[5]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_initrd_list_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "known-5";
      if (STRNEQ (r[5], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_initrd_list_0", expected, r[5]);
        return -1;
      }
    }
    if (r[6] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_initrd_list_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_du_0");
    return 0;
  }

  /* InitISOFS for test_du_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for du (0) */
  {
    const char *path = "/directory";
    int64_t r;
    r = guestfs_du (g, path);
    if (r == -1)
      return -1;
    if (r != 2) {
      fprintf (stderr, "%s: expected 2 but got %d\n",               "test_du_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_tail_n_0");
    return 0;
  }

  /* InitISOFS for test_tail_n_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for tail_n (0) */
  {
    const char *path = "/10klines";
    char **r;
    size_t i;
    r = guestfs_tail_n (g, 3, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_n_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9997abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_n_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_n_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9998abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_n_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_n_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9999abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_n_0", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_tail_n_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_tail_n_1");
    return 0;
  }

  /* InitISOFS for test_tail_n_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for tail_n (1) */
  {
    const char *path = "/10klines";
    char **r;
    size_t i;
    r = guestfs_tail_n (g, -9998, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_n_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9997abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_n_1", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_n_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9998abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_n_1", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_n_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9999abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_n_1", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_tail_n_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_tail_n_2");
    return 0;
  }

  /* InitISOFS for test_tail_n_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for tail_n (2) */
  {
    const char *path = "/10klines";
    char **r;
    size_t i;
    r = guestfs_tail_n (g, 0, path);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_tail_n_2");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_tail_0");
    return 0;
  }

  /* InitISOFS for test_tail_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for tail (0) */
  {
    const char *path = "/10klines";
    char **r;
    size_t i;
    r = guestfs_tail (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9990abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9991abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9992abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_0", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9993abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_0", expected, r[3]);
        return -1;
      }
    }
    if (!r[4]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9994abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[4], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_0", expected, r[4]);
        return -1;
      }
    }
    if (!r[5]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9995abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[5], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_0", expected, r[5]);
        return -1;
      }
    }
    if (!r[6]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9996abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[6], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_0", expected, r[6]);
        return -1;
      }
    }
    if (!r[7]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9997abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[7], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_0", expected, r[7]);
        return -1;
      }
    }
    if (!r[8]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9998abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[8], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_0", expected, r[8]);
        return -1;
      }
    }
    if (!r[9]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_tail_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9999abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[9], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tail_0", expected, r[9]);
        return -1;
      }
    }
    if (r[10] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_tail_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_head_n_0");
    return 0;
  }

  /* InitISOFS for test_head_n_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for head_n (0) */
  {
    const char *path = "/10klines";
    char **r;
    size_t i;
    r = guestfs_head_n (g, 3, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_n_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "0abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_n_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_n_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "1abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_n_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_n_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "2abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_n_0", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_head_n_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_head_n_1");
    return 0;
  }

  /* InitISOFS for test_head_n_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for head_n (1) */
  {
    const char *path = "/10klines";
    char **r;
    size_t i;
    r = guestfs_head_n (g, -9997, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_n_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "0abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_n_1", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_n_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "1abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_n_1", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_n_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "2abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_n_1", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_head_n_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_head_n_2");
    return 0;
  }

  /* InitISOFS for test_head_n_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for head_n (2) */
  {
    const char *path = "/10klines";
    char **r;
    size_t i;
    r = guestfs_head_n (g, 0, path);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_head_n_2");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_head_0");
    return 0;
  }

  /* InitISOFS for test_head_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for head (0) */
  {
    const char *path = "/10klines";
    char **r;
    size_t i;
    r = guestfs_head (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "0abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "1abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "2abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_0", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "3abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_0", expected, r[3]);
        return -1;
      }
    }
    if (!r[4]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "4abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[4], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_0", expected, r[4]);
        return -1;
      }
    }
    if (!r[5]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "5abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[5], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_0", expected, r[5]);
        return -1;
      }
    }
    if (!r[6]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "6abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[6], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_0", expected, r[6]);
        return -1;
      }
    }
    if (!r[7]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "7abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[7], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_0", expected, r[7]);
        return -1;
      }
    }
    if (!r[8]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "8abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[8], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_0", expected, r[8]);
        return -1;
      }
    }
    if (!r[9]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[9], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_0", expected, r[9]);
        return -1;
      }
    }
    if (r[10] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_head_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_head_1");
    return 0;
  }

  /* InitISOFS for test_head_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for head (1) */
  {
    const char *path = "/abssymlink";
    char **r;
    size_t i;
    r = guestfs_head (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "0abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_1", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "1abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_1", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "2abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_1", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "3abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_1", expected, r[3]);
        return -1;
      }
    }
    if (!r[4]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "4abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[4], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_1", expected, r[4]);
        return -1;
      }
    }
    if (!r[5]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "5abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[5], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_1", expected, r[5]);
        return -1;
      }
    }
    if (!r[6]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "6abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[6], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_1", expected, r[6]);
        return -1;
      }
    }
    if (!r[7]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "7abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[7], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_1", expected, r[7]);
        return -1;
      }
    }
    if (!r[8]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "8abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[8], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_1", expected, r[8]);
        return -1;
      }
    }
    if (!r[9]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_head_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[9], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_head_1", expected, r[9]);
        return -1;
      }
    }
    if (r[10] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_head_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_wc_c_0");
    return 0;
  }

  /* InitISOFS for test_wc_c_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for wc_c (0) */
  {
    const char *path = "/100kallspaces";
    int r;
    r = guestfs_wc_c (g, path);
    if (r == -1)
      return -1;
    if (r != 102400) {
      fprintf (stderr, "%s: expected 102400 but got %d\n",               "test_wc_c_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_wc_w_0");
    return 0;
  }

  /* InitISOFS for test_wc_w_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for wc_w (0) */
  {
    const char *path = "/10klines";
    int r;
    r = guestfs_wc_w (g, path);
    if (r == -1)
      return -1;
    if (r != 10000) {
      fprintf (stderr, "%s: expected 10000 but got %d\n",               "test_wc_w_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_wc_l_0");
    return 0;
  }

  /* InitISOFS for test_wc_l_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for wc_l (0) */
  {
    const char *path = "/10klines";
    int r;
    r = guestfs_wc_l (g, path);
    if (r == -1)
      return -1;
    if (r != 10000) {
      fprintf (stderr, "%s: expected 10000 but got %d\n",               "test_wc_l_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_wc_l_1");
    return 0;
  }

  /* InitISOFS for test_wc_l_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for wc_l (1) */
  {
    const char *path = "/abssymlink";
    int r;
    r = guestfs_wc_l (g, path);
    if (r == -1)
      return -1;
    if (r != 10000) {
      fprintf (stderr, "%s: expected 10000 but got %d\n",               "test_wc_l_1", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdtemp_0");
    return 0;
  }

  /* InitScratchFS for test_mkdtemp_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkdtemp (0) */
  {
    const char *path = "/mkdtemp";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *tmpl = "/mkdtemp/tmpXXXXXX";
    char *r;
    r = guestfs_mkdtemp (g, tmpl);
    if (r == NULL)
      return -1;
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_scrub_file_0");
    return 0;
  }

  if (!is_available ("scrub")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_scrub_file_0", "scrub");
    return 0;
  }
  /* InitScratchFS for test_scrub_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for scrub_file (0) */
  {
    const char *path = "/scrub_file";
    const char *content = "content";
    size_t content_size = 7;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/scrub_file";
    int r;
    r = guestfs_scrub_file (g, file);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_scrub_device_0");
    return 0;
  }

  if (!is_available ("scrub")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_scrub_device_0", "scrub");
    return 0;
  }
  /* InitNone|InitEmpty for test_scrub_device_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for scrub_device (0) */
  {
    const char *device = "/dev/sdc";
    int r;
    r = guestfs_scrub_device (g, device);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_glob_expand_0");
    return 0;
  }

  /* InitScratchFS for test_glob_expand_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for glob_expand (0) */
  {
    const char *path = "/glob_expand/b/c";
    int r;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/glob_expand/b/c/d";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/glob_expand/b/c/e";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *pattern = "/glob_expand/b/c/*";
    char **r;
    size_t i;
    r = guestfs_glob_expand (g, pattern);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_glob_expand_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/glob_expand/b/c/d";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_glob_expand_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_glob_expand_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/glob_expand/b/c/e";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_glob_expand_0", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_glob_expand_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_glob_expand_1");
    return 0;
  }

  /* InitScratchFS for test_glob_expand_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for glob_expand (1) */
  {
    const char *path = "/glob_expand2/b/c";
    int r;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/glob_expand2/b/c/d";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/glob_expand2/b/c/e";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *pattern = "/glob_expand2/*/c/*";
    char **r;
    size_t i;
    r = guestfs_glob_expand (g, pattern);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_glob_expand_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/glob_expand2/b/c/d";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_glob_expand_1", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_glob_expand_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/glob_expand2/b/c/e";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_glob_expand_1", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_glob_expand_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_glob_expand_2");
    return 0;
  }

  /* InitScratchFS for test_glob_expand_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for glob_expand (2) */
  {
    const char *path = "/glob_expand3/b/c";
    int r;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/glob_expand3/b/c/d";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/glob_expand3/b/c/e";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *pattern = "/glob_expand3/*/x/*";
    char **r;
    size_t i;
    r = guestfs_glob_expand (g, pattern);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_glob_expand_2");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_ntfs_3g_probe_0");
    return 0;
  }

  if (!is_available ("ntfs3g")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_ntfs_3g_probe_0", "ntfs3g");
    return 0;
  }
  /* InitNone|InitEmpty for test_ntfs_3g_probe_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for ntfs_3g_probe (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ntfs";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_ntfs_3g_probe (g, 1, device);
    if (r == -1)
      return -1;
    if (r != 0) {
      fprintf (stderr, "%s: expected 0 but got %d\n",               "test_ntfs_3g_probe_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_ntfs_3g_probe_1");
    return 0;
  }

  if (!is_available ("ntfs3g")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_ntfs_3g_probe_1", "ntfs3g");
    return 0;
  }
  /* InitNone|InitEmpty for test_ntfs_3g_probe_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for ntfs_3g_probe (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_ntfs_3g_probe (g, 1, device);
    if (r == -1)
      return -1;
    if (r != 12) {
      fprintf (stderr, "%s: expected 12 but got %d\n",               "test_ntfs_3g_probe_1", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_sleep_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_sleep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for sleep (0) */
  {
    int r;
    r = guestfs_sleep (g, 1);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvresize_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvresize_0", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_lvresize_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for lvresize (0) */
  const char *expected = "test content";
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 10);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "test content";
    size_t content_size = 12;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *pathordevice = "/";
    struct guestfs_umount_opts_argv optargs;
    optargs.force = 0;
    optargs.lazyunmount = 0;
    optargs.bitmask = UINT64_C(0x3);
    int r;
    r = guestfs_umount_opts_argv (g, pathordevice, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    int r;
    r = guestfs_lvresize (g, device, 20);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    int r;
    r = guestfs_e2fsck_f (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    struct guestfs_e2fsck_argv optargs;
    optargs.correct = 1;
    optargs.forceall = 0;
    optargs.bitmask = UINT64_C(0x3);
    int r;
    r = guestfs_e2fsck_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    struct guestfs_e2fsck_argv optargs;
    optargs.correct = 0;
    optargs.forceall = 1;
    optargs.bitmask = UINT64_C(0x3);
    int r;
    r = guestfs_e2fsck_argv (g, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    int r;
    r = guestfs_resize2fs (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvresize_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvresize_1");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvresize_1", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_lvresize_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for lvresize (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 20);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    int r;
    r = guestfs_lvresize (g, device, 10);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_zerofree_0");
    return 0;
  }

  if (!is_available ("zerofree")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_zerofree_0", "zerofree");
    return 0;
  }
  /* InitNone|InitEmpty for test_zerofree_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for zerofree (0) */
  const char *expected = "test file";
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext3";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "test file";
    size_t content_size = 9;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *pathordevice = "/dev/sda1";
    struct guestfs_umount_opts_argv optargs;
    optargs.force = 0;
    optargs.lazyunmount = 0;
    optargs.bitmask = UINT64_C(0x3);
    int r;
    r = guestfs_umount_opts_argv (g, pathordevice, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_zerofree (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_zerofree_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_hexdump_0");
    return 0;
  }

  /* InitISOFS for test_hexdump_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for hexdump (0) */
  const char *expected = "00000000  61 62 63 0a 64 65 66 0a  67 68 69                 |abc.def.ghi|\n0000000b\n";
  {
    const char *path = "/known-4";
    char *r;
    r = guestfs_hexdump (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_hexdump_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_hexdump_1");
    return 0;
  }

  /* InitISOFS for test_hexdump_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for hexdump (1) */
  {
    const char *path = "/100krandom";
    char *r;
    r = guestfs_hexdump (g, path);
    if (r == NULL)
      return -1;
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_hexdump_2");
    return 0;
  }

  /* InitISOFS for test_hexdump_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for hexdump (2) */
  {
    const char *path = "/abssymlink";
    char *r;
    r = guestfs_hexdump (g, path);
    if (r == NULL)
      return -1;
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_strings_e_0");
    return 0;
  }

  /* InitISOFS for test_strings_e_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for strings_e (0) */
  {
    const char *encoding = "b";
    const char *path = "/known-5";
    char **r;
    size_t i;
    r = guestfs_strings_e (g, encoding, path);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_strings_e_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_strings_e_1");
    return 0;
  }

  /* InitScratchFS for test_strings_e_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for strings_e (1) */
  {
    const char *path = "/strings_e";
    const char *content = "\0h\0e\0l\0l\0o\0\n\0w\0o\0r\0l\0d\0\n";
    size_t content_size = 24;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *encoding = "b";
    const char *path = "/strings_e";
    char **r;
    size_t i;
    r = guestfs_strings_e (g, encoding, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_strings_e_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "hello";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_strings_e_1", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_strings_e_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "world";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_strings_e_1", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_strings_e_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_strings_0");
    return 0;
  }

  /* InitISOFS for test_strings_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for strings (0) */
  {
    const char *path = "/known-5";
    char **r;
    size_t i;
    r = guestfs_strings (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_strings_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abcdefghi";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_strings_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_strings_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "jklmnopqr";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_strings_0", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_strings_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_strings_1");
    return 0;
  }

  /* InitISOFS for test_strings_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for strings (1) */
  {
    const char *path = "/empty";
    char **r;
    size_t i;
    r = guestfs_strings (g, path);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_strings_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_strings_2");
    return 0;
  }

  /* InitISOFS for test_strings_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for strings (2) */
  {
    const char *path = "/abssymlink";
    char **r;
    size_t i;
    r = guestfs_strings (g, path);
    if (r == NULL)
      return -1;
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_equal_0");
    return 0;
  }

  /* InitScratchFS for test_equal_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for equal (0) */
  {
    const char *path = "/equal";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/equal/file1";
    const char *content = "contents of a file";
    size_t content_size = 18;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/equal/file1";
    const char *dest = "/equal/file2";
    int r;
    r = guestfs_cp (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *file1 = "/equal/file1";
    const char *file2 = "/equal/file2";
    int r;
    r = guestfs_equal (g, file1, file2);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_equal_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_equal_1");
    return 0;
  }

  /* InitScratchFS for test_equal_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for equal (1) */
  {
    const char *path = "/equal2";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/equal2/file1";
    const char *content = "contents of a file";
    size_t content_size = 18;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/equal2/file2";
    const char *content = "contents of another file";
    size_t content_size = 24;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *file1 = "/equal2/file1";
    const char *file2 = "/equal2/file2";
    int r;
    r = guestfs_equal (g, file1, file2);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_equal_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_equal_2");
    return 0;
  }

  /* InitScratchFS for test_equal_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for equal (2) */
  {
    const char *path = "/equal3";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *file1 = "/equal3/file1";
    const char *file2 = "/equal3/file2";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_equal (g, file1, file2);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_ping_daemon_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_ping_daemon_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for ping_daemon (0) */
  {
    int r;
    r = guestfs_ping_daemon (g);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_dmesg_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_dmesg_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for dmesg (0) */
  {
    char *r;
    r = guestfs_dmesg (g);
    if (r == NULL)
      return -1;
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_drop_caches_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_drop_caches_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for drop_caches (0) */
  {
    int r;
    r = guestfs_drop_caches (g, 3);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mv_0");
    return 0;
  }

  /* InitScratchFS for test_mv_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mv (0) */
  const char *expected = "file content";
  {
    const char *path = "/mv";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mv/old";
    const char *content = "file content";
    size_t content_size = 12;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/mv/old";
    const char *dest = "/mv/new";
    int r;
    r = guestfs_mv (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mv/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_mv_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mv_1");
    return 0;
  }

  /* InitScratchFS for test_mv_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for mv (1) */
  {
    const char *path = "/mv2";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mv2/old";
    const char *content = "file content";
    size_t content_size = 12;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/mv2/old";
    const char *dest = "/mv2/new";
    int r;
    r = guestfs_mv (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mv2/old";
    int r;
    r = guestfs_is_file (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_mv_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_cp_a_0");
    return 0;
  }

  /* InitScratchFS for test_cp_a_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for cp_a (0) */
  const char *expected = "file content";
  {
    const char *path = "/cp_a1";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/cp_a2";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/cp_a1/file";
    const char *content = "file content";
    size_t content_size = 12;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/cp_a1";
    const char *dest = "/cp_a2";
    int r;
    r = guestfs_cp_a (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/cp_a2/cp_a1/file";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_cp_a_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_cp_0");
    return 0;
  }

  /* InitScratchFS for test_cp_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for cp (0) */
  const char *expected = "file content";
  {
    const char *path = "/cp";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/cp/old";
    const char *content = "file content";
    size_t content_size = 12;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/cp/old";
    const char *dest = "/cp/new";
    int r;
    r = guestfs_cp (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/cp/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_cp_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_cp_1");
    return 0;
  }

  /* InitScratchFS for test_cp_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for cp (1) */
  {
    const char *path = "/cp2";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/cp2/old";
    const char *content = "file content";
    size_t content_size = 12;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/cp2/old";
    const char *dest = "/cp2/new";
    int r;
    r = guestfs_cp (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/cp2/old";
    int r;
    r = guestfs_is_file (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_cp_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_cp_2");
    return 0;
  }

  /* InitScratchFS for test_cp_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for cp (2) */
  const char *expected = "file content";
  {
    const char *path = "/cp3";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/cp3/old";
    const char *content = "file content";
    size_t content_size = 12;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/cp3/dir";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/cp3/old";
    const char *dest = "/cp3/dir/new";
    int r;
    r = guestfs_cp (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/cp3/dir/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_cp_2", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_grub_install_0");
    return 0;
  }

  if (!is_available ("grub")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_grub_install_0", "grub");
    return 0;
  }
  /* InitBasicFS for test_grub_install_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for grub_install (0) */
  {
    const char *path = "/boot/grub";
    int r;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/boot/grub/device.map";
    const char *content = "(hd0) /dev/vda";
    size_t content_size = 14;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *root = "/";
    const char *device = "/dev/vda";
    int r;
    r = guestfs_grub_install (g, root, device);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/boot";
    int r;
    r = guestfs_is_dir (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_grub_install_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_zero_0");
    return 0;
  }

  /* InitBasicFS for test_zero_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for zero (0) */
  {
    const char *pathordevice = "/dev/sda1";
    struct guestfs_umount_opts_argv optargs;
    optargs.force = 0;
    optargs.lazyunmount = 0;
    optargs.bitmask = UINT64_C(0x3);
    int r;
    r = guestfs_umount_opts_argv (g, pathordevice, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_zero (g, device);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_fsck_0");
    return 0;
  }

  /* InitBasicFS for test_fsck_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for fsck (0) */
  {
    const char *pathordevice = "/dev/sda1";
    struct guestfs_umount_opts_argv optargs;
    optargs.force = 0;
    optargs.lazyunmount = 0;
    optargs.bitmask = UINT64_C(0x3);
    int r;
    r = guestfs_umount_opts_argv (g, pathordevice, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_fsck (g, fstype, device);
    if (r == -1)
      return -1;
    if (r != 0) {
      fprintf (stderr, "%s: expected 0 but got %d\n",               "test_fsck_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_fsck_1");
    return 0;
  }

  /* InitBasicFS for test_fsck_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for fsck (1) */
  {
    const char *pathordevice = "/dev/sda1";
    struct guestfs_umount_opts_argv optargs;
    optargs.force = 0;
    optargs.lazyunmount = 0;
    optargs.bitmask = UINT64_C(0x3);
    int r;
    r = guestfs_umount_opts_argv (g, pathordevice, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_zero (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_fsck (g, fstype, device);
    if (r == -1)
      return -1;
    if (r != 8) {
      fprintf (stderr, "%s: expected 8 but got %d\n",               "test_fsck_1", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_e2uuid_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_e2uuid_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for get_e2uuid (0) */
  const char *expected = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
  {
    const char *device = "/dev/sdc";
    int r;
    r = guestfs_mke2journal (g, 1024, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdc";
    const char *uuid = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
    int r;
    r = guestfs_set_e2uuid (g, device, uuid);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdc";
    char *r;
    r = guestfs_get_e2uuid (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_get_e2uuid_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_e2uuid_0");
    return 0;
  }

  /* InitBasicFS for test_set_e2uuid_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for set_e2uuid (0) */
  const char *expected = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
  {
    const char *device = "/dev/sda1";
    const char *uuid = "d113cb80-b755-cd40-f87b-46eed23b2f0f";
    int r;
    r = guestfs_set_e2uuid (g, device, uuid);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    char *r;
    r = guestfs_get_e2uuid (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_set_e2uuid_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_e2uuid_1");
    return 0;
  }

  /* InitBasicFS for test_set_e2uuid_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for set_e2uuid (1) */
  const char *expected = "";
  {
    const char *device = "/dev/sda1";
    const char *uuid = "clear";
    int r;
    r = guestfs_set_e2uuid (g, device, uuid);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    char *r;
    r = guestfs_get_e2uuid (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_set_e2uuid_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_e2uuid_2");
    return 0;
  }

  /* InitBasicFS for test_set_e2uuid_2: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for set_e2uuid (2) */
  {
    const char *device = "/dev/sda1";
    const char *uuid = "random";
    int r;
    r = guestfs_set_e2uuid (g, device, uuid);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_e2uuid_3");
    return 0;
  }

  /* InitBasicFS for test_set_e2uuid_3: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for set_e2uuid (3) */
  {
    const char *device = "/dev/sda1";
    const char *uuid = "time";
    int r;
    r = guestfs_set_e2uuid (g, device, uuid);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_e2label_0");
    return 0;
  }

  /* InitBasicFS for test_set_e2label_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for set_e2label (0) */
  const char *expected = "testlabel";
  {
    const char *device = "/dev/sda1";
    const char *label = "testlabel";
    int r;
    r = guestfs_set_e2label (g, device, label);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    char *r;
    r = guestfs_get_e2label (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_set_e2label_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvremove_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvremove_0", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_pvremove_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for pvremove (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *vgname = "VG";
    int r;
    r = guestfs_vgremove (g, vgname);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvremove (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_pvremove_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvremove_1");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvremove_1", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_pvremove_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for pvremove (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *vgname = "VG";
    int r;
    r = guestfs_vgremove (g, vgname);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvremove (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_pvremove_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvremove_2");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvremove_2", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_pvremove_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for pvremove (2) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *vgname = "VG";
    int r;
    r = guestfs_vgremove (g, vgname);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvremove (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_pvs (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_pvremove_2");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgremove_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_vgremove_0", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_vgremove_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for vgremove (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *vgname = "VG";
    int r;
    r = guestfs_vgremove (g, vgname);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_vgremove_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgremove_1");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_vgremove_1", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_vgremove_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for vgremove (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *vgname = "VG";
    int r;
    r = guestfs_vgremove (g, vgname);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_vgremove_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvremove_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvremove_0", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_lvremove_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvremove (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV1";
    int r;
    r = guestfs_lvremove (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvremove_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG/LV2";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvremove_0", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_lvremove_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvremove_1");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvremove_1", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_lvremove_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvremove (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG";
    int r;
    r = guestfs_lvremove (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_lvremove_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvremove_2");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvremove_2", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_lvremove_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvremove (2) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG";
    int r;
    r = guestfs_lvremove (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvremove_2");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvremove_2", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_lvremove_2");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mount_ro_0");
    return 0;
  }

  /* InitBasicFS for test_mount_ro_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for mount_ro (0) */
  {
    const char *pathordevice = "/";
    struct guestfs_umount_opts_argv optargs;
    optargs.force = 0;
    optargs.lazyunmount = 0;
    optargs.bitmask = UINT64_C(0x3);
    int r;
    r = guestfs_umount_opts_argv (g, pathordevice, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_touch (g, path);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mount_ro_1");
    return 0;
  }

  /* InitBasicFS for test_mount_ro_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mount_ro (1) */
  const char *expected = "data";
  {
    const char *path = "/new";
    const char *content = "data";
    size_t content_size = 4;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *pathordevice = "/";
    struct guestfs_umount_opts_argv optargs;
    optargs.force = 0;
    optargs.lazyunmount = 0;
    optargs.bitmask = UINT64_C(0x3);
    int r;
    r = guestfs_umount_opts_argv (g, pathordevice, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_mount_ro_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_tgz_in_0");
    return 0;
  }

  /* InitScratchFS for test_tgz_in_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for tgz_in (0) */
  const char *expected = "hello\n";
  {
    const char *path = "/tgz_in";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *directory = "/tgz_in";
    int r;
    r = guestfs_tgz_in (g, "../data/helloworld.tar.gz", directory);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/tgz_in/hello";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tgz_in_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_tar_in_0");
    return 0;
  }

  /* InitScratchFS for test_tar_in_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for tar_in (0) */
  const char *expected = "hello\n";
  {
    const char *path = "/tar_in";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *directory = "/tar_in";
    struct guestfs_tar_in_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_tar_in_opts_argv (g, "../data/helloworld.tar", directory, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/tar_in/hello";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tar_in_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_tar_in_1");
    return 0;
  }

  /* InitScratchFS for test_tar_in_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for tar_in (1) */
  const char *expected = "hello\n";
  {
    const char *path = "/tar_in_gz";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *directory = "/tar_in_gz";
    struct guestfs_tar_in_opts_argv optargs;
    optargs.compress = "gzip";
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_tar_in_opts_argv (g, "../data/helloworld.tar.gz", directory, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/tar_in_gz/hello";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tar_in_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_tar_in_2");
    return 0;
  }

  if (!is_available ("xz")) {
    printf ("        %s skipped (reason: %s not available)\n", "test_tar_in_2", "xz");
    return 0;
  }

  /* InitScratchFS for test_tar_in_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for tar_in (2) */
  const char *expected = "hello\n";
  {
    const char *path = "/tar_in_xz";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *directory = "/tar_in_xz";
    struct guestfs_tar_in_opts_argv optargs;
    optargs.compress = "xz";
    optargs.bitmask = UINT64_C(0x1);
    int r;
    r = guestfs_tar_in_opts_argv (g, "../data/helloworld.tar.xz", directory, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/tar_in_xz/hello";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_tar_in_2", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_0");
    return 0;
  }

  /* InitISOFS for test_checksum_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for checksum (0) */
  const char *expected = "2891671662";
  {
    const char *csumtype = "crc";
    const char *path = "/known-3";
    char *r;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_checksum_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_1");
    return 0;
  }

  /* InitISOFS for test_checksum_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for checksum (1) */
  {
    const char *csumtype = "crc";
    const char *path = "/notexists";
    char *r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_checksum (g, csumtype, path);
    guestfs_pop_error_handler (g);
    if (r != NULL)
      return -1;
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_2");
    return 0;
  }

  /* InitISOFS for test_checksum_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for checksum (2) */
  const char *expected = "46d6ca27ee07cdc6fa99c2e138cc522c";
  {
    const char *csumtype = "md5";
    const char *path = "/known-3";
    char *r;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_checksum_2", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_3");
    return 0;
  }

  /* InitISOFS for test_checksum_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for checksum (3) */
  const char *expected = "b7ebccc3ee418311091c3eda0a45b83c0a770f15";
  {
    const char *csumtype = "sha1";
    const char *path = "/known-3";
    char *r;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_checksum_3", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_4");
    return 0;
  }

  /* InitISOFS for test_checksum_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for checksum (4) */
  const char *expected = "d2cd1774b28f3659c14116be0a6dc2bb5c4b350ce9cd5defac707741";
  {
    const char *csumtype = "sha224";
    const char *path = "/known-3";
    char *r;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_checksum_4", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_5");
    return 0;
  }

  /* InitISOFS for test_checksum_5 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for checksum (5) */
  const char *expected = "75bb71b90cd20cb13f86d2bea8dad63ac7194e7517c3b52b8d06ff52d3487d30";
  {
    const char *csumtype = "sha256";
    const char *path = "/known-3";
    char *r;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_checksum_5", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_6");
    return 0;
  }

  /* InitISOFS for test_checksum_6 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for checksum (6) */
  const char *expected = "5fa7883430f357b5d7b7271d3a1d2872b51d73cba72731de6863d3dea55f30646af2799bef44d5ea776a5ec7941ac640";
  {
    const char *csumtype = "sha384";
    const char *path = "/known-3";
    char *r;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_checksum_6", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_7");
    return 0;
  }

  /* InitISOFS for test_checksum_7 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for checksum (7) */
  const char *expected = "2794062c328c6b216dca90443b7f7134c5f40e56bd0ed7853123275a09982a6f992e6ca682f9d2fba34a4c5e870d8fe077694ff831e3032a004ee077e00603f6";
  {
    const char *csumtype = "sha512";
    const char *path = "/known-3";
    char *r;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_checksum_7", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_8");
    return 0;
  }

  /* InitISOFS for test_checksum_8 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for checksum (8) */
  const char *expected = "5f57d0639bc95081c53afc63a449403883818edc64da48930ad6b1a4fb49be90404686877743fbcd7c99811f3def7df7bc22635c885c6a8cf79c806b43451c1a";
  {
    const char *csumtype = "sha512";
    const char *path = "/abssymlink";
    char *r;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_checksum_8", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_download_0");
    return 0;
  }

  /* InitScratchFS for test_download_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for download (0) */
  const char *expected = "4fbd65380cdd255951079008b364516c";
  {
    const char *path = "/download";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/download/COPYING.LIB";
    int r;
    r = guestfs_upload (g, "../../COPYING.LIB", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/download/COPYING.LIB";
    int r;
    r = guestfs_download (g, remotefilename, "testdownload.tmp");
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/download/upload";
    int r;
    r = guestfs_upload (g, "testdownload.tmp", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *csumtype = "md5";
    const char *path = "/download/upload";
    char *r;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_download_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_upload_0");
    return 0;
  }

  /* InitScratchFS for test_upload_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for upload (0) */
  const char *expected = "4fbd65380cdd255951079008b364516c";
  {
    const char *path = "/upload";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/upload/COPYING.LIB";
    int r;
    r = guestfs_upload (g, "../../COPYING.LIB", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *csumtype = "md5";
    const char *path = "/upload/COPYING.LIB";
    char *r;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_upload_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_rereadpt_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_rereadpt_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for blockdev_rereadpt (0) */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_rereadpt (g, device);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_flushbufs_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_flushbufs_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for blockdev_flushbufs (0) */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_flushbufs (g, device);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_getsize64_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_getsize64_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for blockdev_getsize64 (0) */
  {
    const char *device = "/dev/sda";
    int64_t r;
    r = guestfs_blockdev_getsize64 (g, device);
    if (r == -1)
      return -1;
    if (r != 524288000) {
      fprintf (stderr, "%s: expected 524288000 but got %d\n",               "test_blockdev_getsize64_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_getsz_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_getsz_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for blockdev_getsz (0) */
  {
    const char *device = "/dev/sda";
    int64_t r;
    r = guestfs_blockdev_getsz (g, device);
    if (r == -1)
      return -1;
    if (r != 1024000) {
      fprintf (stderr, "%s: expected 1024000 but got %d\n",               "test_blockdev_getsz_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_getss_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_getss_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for blockdev_getss (0) */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_getss (g, device);
    if (r == -1)
      return -1;
    if (r != 512) {
      fprintf (stderr, "%s: expected 512 but got %d\n",               "test_blockdev_getss_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_getro_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_getro_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for blockdev_getro (0) */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setro (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_getro (g, device);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_blockdev_getro_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_setrw_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_setrw_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for blockdev_setrw (0) */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_getro (g, device);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_blockdev_setrw_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_setro_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_setro_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for blockdev_setro (0) */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setro (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_getro (g, device);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_blockdev_setro_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_tune2fs_l_0");
    return 0;
  }

  /* InitScratchFS for test_tune2fs_l_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputHashtable for tune2fs_l (0) */
  const char *key, *expected, *value;
  {
    const char *device = "/dev/sdb1";
    char **r;
    size_t i;
    r = guestfs_tune2fs_l (g, device);
    if (r == NULL)
      return -1;
    key = "Filesystem magic number";
    expected = "0xEF53";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_tune2fs_l_0", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_tune2fs_l_0", key, expected, value);
      return -1;
    }
    key = "Filesystem OS type";
    expected = "Linux";
    value = get_key (r, key);
    if (value == NULL) {
      fprintf (stderr, "%s: key \"%s\" not found in hash: expecting \"%s\"\n", "test_tune2fs_l_0", key, expected);
      return -1;
    }
    if (STRNEQ (value, expected)) {
      fprintf (stderr, "%s: key \"%s\": expected \"%s\" but got \"%s\"\n", "test_tune2fs_l_0", key, expected, value);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_statvfs_0");
    return 0;
  }

  /* InitISOFS for test_statvfs_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for statvfs (0) */
  {
    const char *path = "/";
    struct guestfs_statvfs *r;
    r = guestfs_statvfs (g, path);
    if (r == NULL)
      return -1;
    if (r->namemax != 255) {
      fprintf (stderr, "%s: namemax was %d, expected 255\n",
               "test_statvfs_0", (int) r->namemax);
      return -1;
    }
    guestfs_free_statvfs (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lstat_0");
    return 0;
  }

  /* InitISOFS for test_lstat_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for lstat (0) */
  {
    const char *path = "/empty";
    struct guestfs_stat *r;
    r = guestfs_lstat (g, path);
    if (r == NULL)
      return -1;
    if (r->size != 0) {
      fprintf (stderr, "%s: size was %d, expected 0\n",
               "test_lstat_0", (int) r->size);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_stat_0");
    return 0;
  }

  /* InitISOFS for test_stat_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for stat (0) */
  {
    const char *path = "/empty";
    struct guestfs_stat *r;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->size != 0) {
      fprintf (stderr, "%s: size was %d, expected 0\n",
               "test_stat_0", (int) r->size);
      return -1;
    }
    guestfs_free_stat (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_0");
    return 0;
  }

  /* InitScratchFS for test_command_lines_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (0) */
  {
    const char *path = "/command_lines";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command_lines/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command_lines/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command_lines/test-command";
    const char *arguments_1 = "1";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    size_t i;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_0", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_command_lines_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_1");
    return 0;
  }

  /* InitScratchFS for test_command_lines_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (1) */
  {
    const char *path = "/command_lines2";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command_lines2/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command_lines2/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command_lines2/test-command";
    const char *arguments_1 = "2";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    size_t i;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result2";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_1", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_command_lines_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_2");
    return 0;
  }

  /* InitScratchFS for test_command_lines_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (2) */
  {
    const char *path = "/command_lines3";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command_lines3/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command_lines3/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command_lines3/test-command";
    const char *arguments_1 = "3";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    size_t i;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_2");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_2", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_2");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result3";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_2", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_command_lines_2");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_3");
    return 0;
  }

  /* InitScratchFS for test_command_lines_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (3) */
  {
    const char *path = "/command_lines4";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command_lines4/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command_lines4/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command_lines4/test-command";
    const char *arguments_1 = "4";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    size_t i;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_3");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_3", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_3");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result4";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_3", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_command_lines_3");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_4");
    return 0;
  }

  /* InitScratchFS for test_command_lines_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (4) */
  {
    const char *path = "/command_lines5";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command_lines5/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command_lines5/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command_lines5/test-command";
    const char *arguments_1 = "5";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    size_t i;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_4");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_4", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_4");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result5";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_4", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_4");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_4", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_command_lines_4");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_5");
    return 0;
  }

  /* InitScratchFS for test_command_lines_5 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (5) */
  {
    const char *path = "/command_lines6";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command_lines6/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command_lines6/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command_lines6/test-command";
    const char *arguments_1 = "6";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    size_t i;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_5");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_5", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_5");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_5", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_5");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result6";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_5", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_5");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_5", expected, r[3]);
        return -1;
      }
    }
    if (r[4] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_command_lines_5");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_6");
    return 0;
  }

  /* InitScratchFS for test_command_lines_6 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (6) */
  {
    const char *path = "/command_lines7";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command_lines7/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command_lines7/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command_lines7/test-command";
    const char *arguments_1 = "7";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    size_t i;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_command_lines_6");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_7");
    return 0;
  }

  /* InitScratchFS for test_command_lines_7 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (7) */
  {
    const char *path = "/command_lines8";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command_lines8/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command_lines8/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command_lines8/test-command";
    const char *arguments_1 = "8";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    size_t i;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_7");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_7", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_command_lines_7");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_8");
    return 0;
  }

  /* InitScratchFS for test_command_lines_8 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (8) */
  {
    const char *path = "/command_lines9";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command_lines9/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command_lines9/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command_lines9/test-command";
    const char *arguments_1 = "9";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    size_t i;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_8");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_8", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_8");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_8", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_command_lines_8");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_9");
    return 0;
  }

  /* InitScratchFS for test_command_lines_9 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (9) */
  {
    const char *path = "/command_lines10";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command_lines10/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command_lines10/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command_lines10/test-command";
    const char *arguments_1 = "10";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    size_t i;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_9");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result10-1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_9", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_9");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result10-2";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_9", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_command_lines_9");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_10");
    return 0;
  }

  /* InitScratchFS for test_command_lines_10 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (10) */
  {
    const char *path = "/command_lines11";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command_lines11/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command_lines11/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command_lines11/test-command";
    const char *arguments_1 = "11";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    size_t i;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_10");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result11-1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_10", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_command_lines_10");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result11-2";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_lines_10", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_command_lines_10");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_0");
    return 0;
  }

  /* InitScratchFS for test_command_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (0) */
  const char *expected = "Result1";
  {
    const char *path = "/command";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command/test-command";
    const char *arguments_1 = "1";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_1");
    return 0;
  }

  /* InitScratchFS for test_command_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (1) */
  const char *expected = "Result2\n";
  {
    const char *path = "/command2";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command2/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command2/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command2/test-command";
    const char *arguments_1 = "2";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_2");
    return 0;
  }

  /* InitScratchFS for test_command_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (2) */
  const char *expected = "\nResult3";
  {
    const char *path = "/command3";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command3/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command3/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command3/test-command";
    const char *arguments_1 = "3";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_2", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_3");
    return 0;
  }

  /* InitScratchFS for test_command_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (3) */
  const char *expected = "\nResult4\n";
  {
    const char *path = "/command4";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command4/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command4/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command4/test-command";
    const char *arguments_1 = "4";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_3", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_4");
    return 0;
  }

  /* InitScratchFS for test_command_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (4) */
  const char *expected = "\nResult5\n\n";
  {
    const char *path = "/command5";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command5/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command5/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command5/test-command";
    const char *arguments_1 = "5";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_4", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_5");
    return 0;
  }

  /* InitScratchFS for test_command_5 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (5) */
  const char *expected = "\n\nResult6\n\n";
  {
    const char *path = "/command6";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command6/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command6/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command6/test-command";
    const char *arguments_1 = "6";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_5", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_6");
    return 0;
  }

  /* InitScratchFS for test_command_6 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (6) */
  const char *expected = "";
  {
    const char *path = "/command7";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command7/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command7/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command7/test-command";
    const char *arguments_1 = "7";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_6", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_7");
    return 0;
  }

  /* InitScratchFS for test_command_7 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (7) */
  const char *expected = "\n";
  {
    const char *path = "/command8";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command8/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command8/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command8/test-command";
    const char *arguments_1 = "8";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_7", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_8");
    return 0;
  }

  /* InitScratchFS for test_command_8 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (8) */
  const char *expected = "\n\n";
  {
    const char *path = "/command9";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command9/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command9/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command9/test-command";
    const char *arguments_1 = "9";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_8", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_9");
    return 0;
  }

  /* InitScratchFS for test_command_9 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (9) */
  const char *expected = "Result10-1\nResult10-2\n";
  {
    const char *path = "/command10";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command10/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command10/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command10/test-command";
    const char *arguments_1 = "10";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_9", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_10");
    return 0;
  }

  /* InitScratchFS for test_command_10 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (10) */
  const char *expected = "Result11-1\nResult11-2";
  {
    const char *path = "/command11";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command11/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command11/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command11/test-command";
    const char *arguments_1 = "11";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_10", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_11");
    return 0;
  }

  /* InitScratchFS for test_command_11 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for command (11) */
  {
    const char *path = "/command12";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/command12/test-command";
    int r;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/command12/test-command";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/command12/test-command";
    const char *const arguments[] = {
      arguments_0,
      NULL
    };
    char *r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_command (g, (char **) arguments);
    guestfs_pop_error_handler (g);
    if (r != NULL)
      return -1;
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_12");
    return 0;
  }

  /* InitScratchFS for test_command_12 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (12) */
  const char *expected = "/";
  {
    const char *path = "/pwd";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/pwd/test-pwd";
    int r;
    r = guestfs_upload (g, "test-pwd", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/pwd/test-pwd";
    int r;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/pwd/test-pwd";
    const char *const arguments[] = {
      arguments_0,
      NULL
    };
    char *r;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_command_12", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_0");
    return 0;
  }

  /* InitISOFS for test_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file (0) */
  const char *expected = "empty";
  {
    const char *path = "/empty";
    char *r;
    r = guestfs_file (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_1");
    return 0;
  }

  /* InitISOFS for test_file_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file (1) */
  const char *expected = "ASCII text";
  {
    const char *path = "/known-1";
    char *r;
    r = guestfs_file (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_2");
    return 0;
  }

  /* InitISOFS for test_file_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for file (2) */
  {
    const char *path = "/notexists";
    char *r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_file (g, path);
    guestfs_pop_error_handler (g);
    if (r != NULL)
      return -1;
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_3");
    return 0;
  }

  /* InitISOFS for test_file_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file (3) */
  const char *expected = "symbolic link";
  {
    const char *path = "/abssymlink";
    char *r;
    r = guestfs_file (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_3", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_4");
    return 0;
  }

  /* InitISOFS for test_file_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file (4) */
  const char *expected = "directory";
  {
    const char *path = "/directory";
    char *r;
    r = guestfs_file (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_4", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_umount_all_0");
    return 0;
  }

  /* InitScratchFS for test_umount_all_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for umount_all (0) */
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_mounts (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_umount_all_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_umount_all_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_umount_all_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for umount_all (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, 409599);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 409600, -64);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda2";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda3";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mp1";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    const char *mountpoint = "/mp1";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mp1/mp2";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda3";
    const char *mountpoint = "/mp1/mp2";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mp1/mp2/mp3";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_mounts (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_umount_all_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mounts_0");
    return 0;
  }

  /* InitScratchFS for test_mounts_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for mounts (0) */
  {
    char **r;
    size_t i;
    r = guestfs_mounts (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_mounts_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sdb1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_mounts_0", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_mounts_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_umount_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_umount_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for umount (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_mounts (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_umount_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_umount_0", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_umount_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_umount_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_umount_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for umount (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *pathordevice = "/";
    struct guestfs_umount_opts_argv optargs;
    optargs.force = 0;
    optargs.lazyunmount = 0;
    optargs.bitmask = UINT64_C(0x3);
    int r;
    r = guestfs_umount_opts_argv (g, pathordevice, &optargs);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_mounts (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_umount_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_file_0");
    return 0;
  }

  /* InitScratchFS for test_write_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for write_file (0) */
  {
    const char *path = "/write_file";
    const char *content = "abc";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_write_file (g, path, content, 10000);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvcreate_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvcreate_0", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_lvcreate_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvcreate (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, 409599);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 409600, -64);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda3";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG1";
    const char *physvols_0 = "/dev/sda1";
    const char *physvols_1 = "/dev/sda2";
    const char *const physvols[] = {
      physvols_0,
      physvols_1,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG2";
    const char *physvols_0 = "/dev/sda3";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG1";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG1";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV3";
    const char *volgroup = "VG2";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV4";
    const char *volgroup = "VG2";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV5";
    const char *volgroup = "VG2";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvcreate_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG1/LV1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvcreate_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvcreate_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG1/LV2";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvcreate_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvcreate_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG2/LV3";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvcreate_0", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvcreate_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG2/LV4";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvcreate_0", expected, r[3]);
        return -1;
      }
    }
    if (!r[4]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvcreate_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG2/LV5";
      if (STRNEQ (r[4], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvcreate_0", expected, r[4]);
        return -1;
      }
    }
    if (r[5] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_lvcreate_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgcreate_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_vgcreate_0", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_vgcreate_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for vgcreate (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, 409599);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 409600, -64);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda3";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG1";
    const char *physvols_0 = "/dev/sda1";
    const char *physvols_1 = "/dev/sda2";
    const char *const physvols[] = {
      physvols_0,
      physvols_1,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG2";
    const char *physvols_0 = "/dev/sda3";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_vgcreate_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_vgcreate_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_vgcreate_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG2";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_vgcreate_0", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_vgcreate_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvcreate_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvcreate_0", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_pvcreate_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for pvcreate (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, 409599);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 409600, -64);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda3";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_pvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_pvcreate_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pvcreate_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_pvcreate_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda2";
      r[1][5] = 's';
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pvcreate_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_pvcreate_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda3";
      r[2][5] = 's';
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pvcreate_0", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_pvcreate_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_dir_0");
    return 0;
  }

  /* InitISOFS for test_is_dir_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_dir (0) */
  {
    const char *path = "/known-3";
    int r;
    r = guestfs_is_dir (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_is_dir_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_dir_1");
    return 0;
  }

  /* InitISOFS for test_is_dir_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for is_dir (1) */
  {
    const char *path = "/directory";
    int r;
    r = guestfs_is_dir (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_is_dir_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_file_0");
    return 0;
  }

  /* InitISOFS for test_is_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for is_file (0) */
  {
    const char *path = "/known-1";
    int r;
    r = guestfs_is_file (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_is_file_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_file_1");
    return 0;
  }

  /* InitISOFS for test_is_file_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_file (1) */
  {
    const char *path = "/directory";
    int r;
    r = guestfs_is_file (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_is_file_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_exists_0");
    return 0;
  }

  /* InitISOFS for test_exists_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for exists (0) */
  {
    const char *path = "/empty";
    int r;
    r = guestfs_exists (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_exists_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_exists_1");
    return 0;
  }

  /* InitISOFS for test_exists_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for exists (1) */
  {
    const char *path = "/directory";
    int r;
    r = guestfs_exists (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_exists_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_p_0");
    return 0;
  }

  /* InitScratchFS for test_mkdir_p_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for mkdir_p (0) */
  {
    const char *path = "/mkdir_p/foo/bar";
    int r;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mkdir_p/foo/bar";
    int r;
    r = guestfs_is_dir (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_mkdir_p_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_p_1");
    return 0;
  }

  /* InitScratchFS for test_mkdir_p_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for mkdir_p (1) */
  {
    const char *path = "/mkdir_p2/foo/bar";
    int r;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mkdir_p2/foo";
    int r;
    r = guestfs_is_dir (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_mkdir_p_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_p_2");
    return 0;
  }

  /* InitScratchFS for test_mkdir_p_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for mkdir_p (2) */
  {
    const char *path = "/mkdir_p3/foo/bar";
    int r;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mkdir_p3";
    int r;
    r = guestfs_is_dir (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_mkdir_p_2");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_p_3");
    return 0;
  }

  /* InitScratchFS for test_mkdir_p_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkdir_p (3) */
  {
    const char *path = "/mkdir_p4";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mkdir_p4";
    int r;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_p_4");
    return 0;
  }

  /* InitScratchFS for test_mkdir_p_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for mkdir_p (4) */
  {
    const char *path = "/mkdir_p5";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mkdir_p5";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_mkdir_p (g, path);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_0");
    return 0;
  }

  /* InitScratchFS for test_mkdir_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for mkdir (0) */
  {
    const char *path = "/mkdir";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mkdir";
    int r;
    r = guestfs_is_dir (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_mkdir_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_1");
    return 0;
  }

  /* InitScratchFS for test_mkdir_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for mkdir (1) */
  {
    const char *path = "/mkdir2/foo/bar";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_mkdir (g, path);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_rm_rf_0");
    return 0;
  }

  /* InitScratchFS for test_rm_rf_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for rm_rf (0) */
  {
    const char *path = "/rm_rf";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rm_rf/foo";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rm_rf/foo/bar";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rm_rf";
    int r;
    r = guestfs_rm_rf (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rm_rf";
    int r;
    r = guestfs_exists (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_rm_rf_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_rmdir_0");
    return 0;
  }

  /* InitScratchFS for test_rmdir_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for rmdir (0) */
  {
    const char *path = "/rmdir";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rmdir";
    int r;
    r = guestfs_rmdir (g, path);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_rmdir_1");
    return 0;
  }

  /* InitScratchFS for test_rmdir_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for rmdir (1) */
  {
    const char *path = "/rmdir2";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_rmdir (g, path);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_rmdir_2");
    return 0;
  }

  /* InitScratchFS for test_rmdir_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for rmdir (2) */
  {
    const char *path = "/rmdir3";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rmdir3/new";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rmdir3/new";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_rmdir (g, path);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_rm_0");
    return 0;
  }

  /* InitScratchFS for test_rm_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for rm (0) */
  {
    const char *path = "/rm";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rm/new";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rm/new";
    int r;
    r = guestfs_rm (g, path);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_rm_1");
    return 0;
  }

  /* InitScratchFS for test_rm_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for rm (1) */
  {
    const char *path = "/nosuchfile";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_rm (g, path);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_rm_2");
    return 0;
  }

  /* InitScratchFS for test_rm_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for rm (2) */
  {
    const char *path = "/rm2";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/rm2";
    int r;
    guestfs_push_error_handler (g, NULL, NULL);
    r = guestfs_rm (g, path);
    guestfs_pop_error_handler (g);
    if (r != -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvs_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvs_0", "lvm2");
    return 0;
  }
  /* InitBasicFSonLVM for test_lvs_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvs (0) */
  {
    char **r;
    size_t i;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvs_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG/LV";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvs_0", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_lvs_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvs_1");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvs_1", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_lvs_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvs (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, 409599);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 409600, -64);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda3";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG1";
    const char *physvols_0 = "/dev/sda1";
    const char *physvols_1 = "/dev/sda2";
    const char *const physvols[] = {
      physvols_0,
      physvols_1,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG2";
    const char *physvols_0 = "/dev/sda3";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG1";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG1";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV3";
    const char *volgroup = "VG2";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvs_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG1/LV1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvs_1", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvs_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG1/LV2";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvs_1", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_lvs_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG2/LV3";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_lvs_1", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_lvs_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgs_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_vgs_0", "lvm2");
    return 0;
  }
  /* InitBasicFSonLVM for test_vgs_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for vgs (0) */
  {
    char **r;
    size_t i;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_vgs_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_vgs_0", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_vgs_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgs_1");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_vgs_1", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_vgs_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for vgs (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, 409599);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 409600, -64);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda3";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG1";
    const char *physvols_0 = "/dev/sda1";
    const char *physvols_1 = "/dev/sda2";
    const char *const physvols[] = {
      physvols_0,
      physvols_1,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG2";
    const char *physvols_0 = "/dev/sda3";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_vgs_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_vgs_1", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_vgs_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG2";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_vgs_1", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_vgs_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvs_0");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvs_0", "lvm2");
    return 0;
  }
  /* InitBasicFSonLVM for test_pvs_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *physvols_0 = "/dev/sda1";
    const char *const physvols[] = {
      physvols_0,
      NULL
    };
    int r;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for pvs (0) */
  {
    char **r;
    size_t i;
    r = guestfs_pvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_pvs_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pvs_0", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_pvs_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvs_1");
    return 0;
  }

  if (!is_available ("lvm2")) {
    printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvs_1", "lvm2");
    return 0;
  }
  /* InitNone|InitEmpty for test_pvs_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for pvs (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, 409599);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 409600, -64);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda3";
    int r;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_pvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_pvs_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pvs_1", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_pvs_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda2";
      r[1][5] = 's';
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pvs_1", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_pvs_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda3";
      r[2][5] = 's';
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_pvs_1", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_pvs_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_list_partitions_0");
    return 0;
  }

  /* InitBasicFS for test_list_partitions_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for list_partitions (0) */
  {
    char **r;
    size_t i;
    r = guestfs_list_partitions (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_list_partitions_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_list_partitions_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_list_partitions_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sdb1";
      r[1][5] = 's';
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_list_partitions_0", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_list_partitions_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_list_partitions_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_list_partitions_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for list_partitions (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 64, 204799);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 204800, 409599);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "p";
    int r;
    r = guestfs_part_add (g, device, prlogex, 409600, -64);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    size_t i;
    r = guestfs_list_partitions (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_list_partitions_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_list_partitions_1", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_list_partitions_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda2";
      r[1][5] = 's';
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_list_partitions_1", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_list_partitions_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda3";
      r[2][5] = 's';
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_list_partitions_1", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_list_partitions_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sdb1";
      r[3][5] = 's';
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_list_partitions_1", expected, r[3]);
        return -1;
      }
    }
    if (r[4] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_list_partitions_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_list_devices_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_list_devices_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for list_devices (0) */
  {
    char **r;
    size_t i;
    r = guestfs_list_devices (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_list_devices_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_list_devices_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_list_devices_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sdb";
      r[1][5] = 's';
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_list_devices_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_list_devices_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sdc";
      r[2][5] = 's';
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_list_devices_0", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_list_devices_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sdd";
      r[3][5] = 's';
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_list_devices_0", expected, r[3]);
        return -1;
      }
    }
    if (r[4] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_list_devices_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_touch_0");
    return 0;
  }

  /* InitScratchFS for test_touch_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for touch (0) */
  {
    const char *path = "/touch";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/touch";
    int r;
    r = guestfs_exists (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_touch_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_sync_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_sync_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for sync (0) */
  {
    int r;
    r = guestfs_sync (g);
    if (r == -1)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_mount_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mount_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mount (0) */
  const char *expected = "new file contents";
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_mount_0", expected, r);
      return -1;
    }
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_disk_has_backing_file_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_has_backing_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for disk_has_backing_file (0) */
  {
    const char *filename = "test1.img";
    int r;
    r = guestfs_disk_has_backing_file (g, filename);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_disk_has_backing_file_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_disk_has_backing_file_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_has_backing_file_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for disk_has_backing_file (1) */
  {
    const char *filename = "test2.img";
    int r;
    r = guestfs_disk_has_backing_file (g, filename);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_disk_has_backing_file_1");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_disk_has_backing_file_2");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_has_backing_file_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for disk_has_backing_file (2) */
  {
    const char *filename = "test3.img";
    int r;
    r = guestfs_disk_has_backing_file (g, filename);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_disk_has_backing_file_2");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_disk_virtual_size_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_virtual_size_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for disk_virtual_size (0) */
  {
    const char *filename = "test1.img";
    int64_t r;
    r = guestfs_disk_virtual_size (g, filename);
    if (r == -1)
      return -1;
    if (r != 524288000) {
      fprintf (stderr, "%s: expected 524288000 but got %d\n",               "test_disk_virtual_size_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_disk_virtual_size_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_virtual_size_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for disk_virtual_size (1) */
  {
    const char *filename = "test2.img";
    int64_t r;
    r = guestfs_disk_virtual_size (g, filename);
    if (r == -1)
      return -1;
    if (r != 52428800) {
      fprintf (stderr, "%s: expected 52428800 but got %d\n",               "test_disk_virtual_size_1", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_disk_virtual_size_2");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_virtual_size_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for disk_virtual_size (2) */
  {
    const char *filename = "test3.img";
    int64_t r;
    r = guestfs_disk_virtual_size (g, filename);
    if (r == -1)
      return -1;
    if (r != 10485760) {
      fprintf (stderr, "%s: expected 10485760 but got %d\n",               "test_disk_virtual_size_2", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_disk_format_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_format_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for disk_format (0) */
  const char *expected = "raw";
  {
    const char *filename = "test1.img";
    char *r;
    r = guestfs_disk_format (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_disk_format_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_disk_format_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_format_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for disk_format (1) */
  const char *expected = "raw";
  {
    const char *filename = "test2.img";
    char *r;
    r = guestfs_disk_format (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_disk_format_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_disk_format_2");
    return 0;
  }

  /* InitNone|InitEmpty for test_disk_format_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for disk_format (2) */
  const char *expected = "raw";
  {
    const char *filename = "test3.img";
    char *r;
    r = guestfs_disk_format (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_disk_format_2", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_ls_0");
    return 0;
  }

  /* InitScratchFS for test_ls_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for ls (0) */
  {
    const char *path = "/ls";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/ls/new";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/ls/newer";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/ls/newest";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *directory = "/ls";
    char **r;
    size_t i;
    r = guestfs_ls (g, directory);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_ls_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "new";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_ls_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_ls_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "newer";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_ls_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_ls_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "newest";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_ls_0", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_ls_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_append_0");
    return 0;
  }

  /* InitScratchFS for test_write_append_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for write_append (0) */
  const char *expected = "line1\nline2\nline3aline3b\n";
  {
    const char *path = "/write_append";
    const char *content = "line1\n";
    size_t content_size = 6;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/write_append";
    const char *content = "line2\n";
    size_t content_size = 6;
    int r;
    r = guestfs_write_append (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/write_append";
    const char *content = "line3a";
    size_t content_size = 6;
    int r;
    r = guestfs_write_append (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/write_append";
    const char *content = "line3b\n";
    size_t content_size = 7;
    int r;
    r = guestfs_write_append (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/write_append";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_write_append_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_0");
    return 0;
  }

  /* InitScratchFS for test_write_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for write (0) */
  const char *expected = "new file contents";
  {
    const char *path = "/write";
    const char *content = "new file contents";
    size_t content_size = 17;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/write";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_write_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_1");
    return 0;
  }

  /* InitScratchFS for test_write_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for write (1) */
  const char *expected = "\nnew file contents\n";
  {
    const char *path = "/write2";
    const char *content = "\nnew file contents\n";
    size_t content_size = 19;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/write2";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_write_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_2");
    return 0;
  }

  /* InitScratchFS for test_write_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for write (2) */
  const char *expected = "\n\n";
  {
    const char *path = "/write3";
    const char *content = "\n\n";
    size_t content_size = 2;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/write3";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_write_2", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_3");
    return 0;
  }

  /* InitScratchFS for test_write_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for write (3) */
  const char *expected = "";
  {
    const char *path = "/write4";
    const char *content = "";
    size_t content_size = 0;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/write4";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_write_3", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_4");
    return 0;
  }

  /* InitScratchFS for test_write_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for write (4) */
  const char *expected = "\n\n\n";
  {
    const char *path = "/write5";
    const char *content = "\n\n\n";
    size_t content_size = 3;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/write5";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_write_4", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_5");
    return 0;
  }

  /* InitScratchFS for test_write_5 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for write (5) */
  const char *expected = "\n";
  {
    const char *path = "/write6";
    const char *content = "\n";
    size_t content_size = 1;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/write6";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_write_5", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_lines_0");
    return 0;
  }

  /* InitISOFS for test_read_lines_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for read_lines (0) */
  {
    const char *path = "/known-4";
    char **r;
    size_t i;
    r = guestfs_read_lines (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_0", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "def";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_0", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ghi";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_0", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_read_lines_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_lines_1");
    return 0;
  }

  /* InitISOFS for test_read_lines_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for read_lines (1) */
  {
    const char *path = "/empty";
    char **r;
    size_t i;
    r = guestfs_read_lines (g, path);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_read_lines_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_lines_2");
    return 0;
  }

  /* InitScratchFS for test_read_lines_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for read_lines (2) */
  {
    const char *path = "/read_lines1";
    const char *content = "\n";
    size_t content_size = 1;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/read_lines1";
    char **r;
    size_t i;
    r = guestfs_read_lines (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_2");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_2", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_read_lines_2");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_lines_3");
    return 0;
  }

  /* InitScratchFS for test_read_lines_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for read_lines (3) */
  {
    const char *path = "/read_lines2";
    const char *content = "\r\n";
    size_t content_size = 2;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/read_lines2";
    char **r;
    size_t i;
    r = guestfs_read_lines (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_3");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_3", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_read_lines_3");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_lines_4");
    return 0;
  }

  /* InitScratchFS for test_read_lines_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for read_lines (4) */
  {
    const char *path = "/read_lines3";
    const char *content = "\n\r\n";
    size_t content_size = 3;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/read_lines3";
    char **r;
    size_t i;
    r = guestfs_read_lines (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_4");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_4", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_4");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_4", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_read_lines_4");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_lines_5");
    return 0;
  }

  /* InitScratchFS for test_read_lines_5 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for read_lines (5) */
  {
    const char *path = "/read_lines4";
    const char *content = "a";
    size_t content_size = 1;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/read_lines4";
    char **r;
    size_t i;
    r = guestfs_read_lines (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_5");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "a";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_5", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_read_lines_5");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_lines_6");
    return 0;
  }

  /* InitScratchFS for test_read_lines_6 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for read_lines (6) */
  {
    const char *path = "/read_lines5";
    const char *content = "a\nb";
    size_t content_size = 3;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/read_lines5";
    char **r;
    size_t i;
    r = guestfs_read_lines (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_6");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "a";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_6", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_6");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "b";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_6", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_read_lines_6");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_lines_7");
    return 0;
  }

  /* InitScratchFS for test_read_lines_7 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for read_lines (7) */
  {
    const char *path = "/read_lines6";
    const char *content = "a\nb\n";
    size_t content_size = 4;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/read_lines6";
    char **r;
    size_t i;
    r = guestfs_read_lines (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_7");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "a";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_7", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_7");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "b";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_7", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_read_lines_7");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_lines_8");
    return 0;
  }

  /* InitScratchFS for test_read_lines_8 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for read_lines (8) */
  {
    const char *path = "/read_lines7";
    const char *content = "a\nb\r\n";
    size_t content_size = 5;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/read_lines7";
    char **r;
    size_t i;
    r = guestfs_read_lines (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_8");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "a";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_8", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_8");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "b";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_8", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_read_lines_8");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_lines_9");
    return 0;
  }

  /* InitScratchFS for test_read_lines_9 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for read_lines (9) */
  {
    const char *path = "/read_lines8";
    const char *content = "a\nb\r\n\n";
    size_t content_size = 6;
    int r;
    r = guestfs_write (g, path, content, content_size);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/read_lines8";
    char **r;
    size_t i;
    r = guestfs_read_lines (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_9");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "a";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_9", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_9");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "b";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_9", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_read_lines_9");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_lines_9", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_read_lines_9");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_file_0");
    return 0;
  }

  /* InitISOFS for test_read_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputBuffer for read_file (0) */
  const char *expected = "abc\ndef\nghi";
  {
    const char *path = "/known-4";
    char *r;
    size_t size;
    r = guestfs_read_file (g, path, &size);
    if (r == NULL)
      return -1;
    if (size != 11) {
      fprintf (stderr, "%s: returned size of buffer wrong, expected 11 but got %zu\n", "test_read_file_0", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_read_file_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_find_0");
    return 0;
  }

  /* InitBasicFS for test_find_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for find (0) */
  {
    const char *directory = "/";
    char **r;
    size_t i;
    r = guestfs_find (g, directory);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_find_0");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "lost+found";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_find_0", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_find_0");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_find_1");
    return 0;
  }

  /* InitBasicFS for test_find_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    struct guestfs_mkfs_opts_argv optargs;
    optargs.bitmask = UINT64_C(0x0);
    int r;
    r = guestfs_mkfs_opts_argv (g, fstype, device, &optargs);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for find (1) */
  {
    const char *path = "/a";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/b";
    int r;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/b/c";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *directory = "/";
    char **r;
    size_t i;
    r = guestfs_find (g, directory);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_find_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "a";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_find_1", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_find_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "b";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_find_1", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_find_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "b/c";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_find_1", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_find_1");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "lost+found";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_find_1", expected, r[3]);
        return -1;
      }
    }
    if (r[4] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_find_1");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_find_2");
    return 0;
  }

  /* InitScratchFS for test_find_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb1";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for find (2) */
  {
    const char *path = "/find/b/c";
    int r;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/find/b/c/d";
    int r;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *directory = "/find/b/";
    char **r;
    size_t i;
    r = guestfs_find (g, directory);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_find_2");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "c";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_find_2", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "%s: short list returned from command\n", "test_find_2");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "c/d";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_find_2", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "%s: extra elements returned from command\n", "test_find_2");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_cat_0");
    return 0;
  }

  /* InitISOFS for test_cat_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for cat (0) */
  const char *expected = "abcdef\n";
  {
    const char *path = "/known-2";
    char *r;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_cat_0", expected, r);
      return -1;
    }
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_attach_method_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_attach_method_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for get_attach_method (0) */
  {
    char *r;
    r = guestfs_get_attach_method (g);
    if (r == NULL)
      return -1;
    free (r);
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_architecture_0");
    return 0;
  }

  /* InitISOFS for test_file_architecture_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file_architecture (0) */
  const char *expected = "i386";
  {
    const char *filename = "/bin-i586-dynamic";
    char *r;
    r = guestfs_file_architecture (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_architecture_0", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_architecture_1");
    return 0;
  }

  /* InitISOFS for test_file_architecture_1 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file_architecture (1) */
  const char *expected = "sparc";
  {
    const char *filename = "/bin-sparc-dynamic";
    char *r;
    r = guestfs_file_architecture (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_architecture_1", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_architecture_2");
    return 0;
  }

  /* InitISOFS for test_file_architecture_2 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file_architecture (2) */
  const char *expected = "i386";
  {
    const char *filename = "/bin-win32.exe";
    char *r;
    r = guestfs_file_architecture (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_architecture_2", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_architecture_3");
    return 0;
  }

  /* InitISOFS for test_file_architecture_3 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file_architecture (3) */
  const char *expected = "x86_64";
  {
    const char *filename = "/bin-win64.exe";
    char *r;
    r = guestfs_file_architecture (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_architecture_3", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_architecture_4");
    return 0;
  }

  /* InitISOFS for test_file_architecture_4 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file_architecture (4) */
  const char *expected = "x86_64";
  {
    const char *filename = "/bin-x86_64-dynamic";
    char *r;
    r = guestfs_file_architecture (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_architecture_4", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_architecture_5");
    return 0;
  }

  /* InitISOFS for test_file_architecture_5 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file_architecture (5) */
  const char *expected = "i386";
  {
    const char *filename = "/lib-i586.so";
    char *r;
    r = guestfs_file_architecture (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_architecture_5", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_architecture_6");
    return 0;
  }

  /* InitISOFS for test_file_architecture_6 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file_architecture (6) */
  const char *expected = "sparc";
  {
    const char *filename = "/lib-sparc.so";
    char *r;
    r = guestfs_file_architecture (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_architecture_6", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_architecture_7");
    return 0;
  }

  /* InitISOFS for test_file_architecture_7 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file_architecture (7) */
  const char *expected = "i386";
  {
    const char *filename = "/lib-win32.dll";
    char *r;
    r = guestfs_file_architecture (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_architecture_7", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_architecture_8");
    return 0;
  }

  /* InitISOFS for test_file_architecture_8 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file_architecture (8) */
  const char *expected = "x86_64";
  {
    const char *filename = "/lib-win64.dll";
    char *r;
    r = guestfs_file_architecture (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_architecture_8", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_architecture_9");
    return 0;
  }

  /* InitISOFS for test_file_architecture_9 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file_architecture (9) */
  const char *expected = "x86_64";
  {
    const char *filename = "/lib-x86_64.so";
    char *r;
    r = guestfs_file_architecture (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_architecture_9", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_architecture_10");
    return 0;
  }

  /* InitISOFS for test_file_architecture_10 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file_architecture (10) */
  const char *expected = "x86_64";
  {
    const char *filename = "/initrd-x86_64.img";
    char *r;
    r = guestfs_file_architecture (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_architecture_10", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_architecture_11");
    return 0;
  }

  /* InitISOFS for test_file_architecture_11 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file_architecture (11) */
  const char *expected = "x86_64";
  {
    const char *filename = "/initrd-x86_64.img.gz";
    char *r;
    r = guestfs_file_architecture (g, filename);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "%s: expected \"%s\" but got \"%s\"\n", "test_file_architecture_11", expected, r);
      return -1;
    }
    free (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_trace_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_set_trace_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for set_trace (0) */
  {
    int r;
    r = guestfs_set_trace (g, 0);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_get_trace (g);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_set_trace_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_version_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_version_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for version (0) */
  {
    struct guestfs_version *r;
    r = guestfs_version (g);
    if (r == NULL)
      return -1;
    if (r->major != 1) {
      fprintf (stderr, "%s: major was %d, expected 1\n",
               "test_version_0", (int) r->major);
      return -1;
    }
    guestfs_free_version (r);
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_memsize_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_memsize_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputIntOp for get_memsize (0) */
  {
    int r;
    r = guestfs_get_memsize (g);
    if (r == -1)
      return -1;
    if (! (r >= 256)) {
      fprintf (stderr, "%s: expected >= 256 but got %d\n",               "test_get_memsize_0", (int) r);
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_busy_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_is_busy_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_busy (0) */
  {
    int r;
    r = guestfs_is_busy (g);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_is_busy_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_launching_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_is_launching_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_launching (0) */
  {
    int r;
    r = guestfs_is_launching (g);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_is_launching_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_config_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_is_config_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_config (0) */
  {
    int r;
    r = guestfs_is_config (g);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "%s: expected false, got true\n", "test_is_config_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_ready_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_is_ready_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for is_ready (0) */
  {
    int r;
    r = guestfs_is_ready (g);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_is_ready_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_autosync_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_autosync_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for get_autosync (0) */
  {
    int r;
    r = guestfs_get_autosync (g);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "%s: expected true, got false\n", "test_get_autosync_0");
      return -1;
    }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_path_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_path_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for get_path (0) */
  {
    const char *r;
    r = guestfs_get_path (g);
    if (r == NULL)
      return -1;
  }
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
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_qemu_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_qemu_0 */
  {
    const char *device = "/dev/sda";
    int r;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for get_qemu (0) */
  {
    const char *r;
    r = guestfs_get_qemu (g);
    if (r == NULL)
      return -1;
  }
  return 0;
}

int
main (int argc, char *argv[])
{
  const char *filename;
  int fd;
  const size_t nr_tests = 419;
  size_t test_num = 0;
  size_t nr_failed = 0;

  setbuf (stdout, NULL);

  no_test_warnings ();

  g = guestfs_create ();
  if (g == NULL) {
    printf ("guestfs_create FAILED\n");
    exit (EXIT_FAILURE);
  }

  filename = "test1.img";
  fd = open (filename, O_WRONLY|O_CREAT|O_NOCTTY|O_TRUNC|O_CLOEXEC, 0666);
  if (fd == -1) {
    perror (filename);
    exit (EXIT_FAILURE);
  }
  if (ftruncate (fd, 524288000) == -1) {
    perror ("ftruncate");
    close (fd);
    unlink (filename);
    exit (EXIT_FAILURE);
  }
  if (close (fd) == -1) {
    perror (filename);
    unlink (filename);
    exit (EXIT_FAILURE);
  }
  if (guestfs_add_drive (g, filename) == -1) {
    printf ("guestfs_add_drive %s FAILED\n", filename);
    exit (EXIT_FAILURE);
  }

  filename = "test2.img";
  fd = open (filename, O_WRONLY|O_CREAT|O_NOCTTY|O_TRUNC|O_CLOEXEC, 0666);
  if (fd == -1) {
    perror (filename);
    exit (EXIT_FAILURE);
  }
  if (ftruncate (fd, 52428800) == -1) {
    perror ("ftruncate");
    close (fd);
    unlink (filename);
    exit (EXIT_FAILURE);
  }
  if (close (fd) == -1) {
    perror (filename);
    unlink (filename);
    exit (EXIT_FAILURE);
  }
  if (guestfs_add_drive (g, filename) == -1) {
    printf ("guestfs_add_drive %s FAILED\n", filename);
    exit (EXIT_FAILURE);
  }

  filename = "test3.img";
  fd = open (filename, O_WRONLY|O_CREAT|O_NOCTTY|O_TRUNC|O_CLOEXEC, 0666);
  if (fd == -1) {
    perror (filename);
    exit (EXIT_FAILURE);
  }
  if (ftruncate (fd, 10485760) == -1) {
    perror ("ftruncate");
    close (fd);
    unlink (filename);
    exit (EXIT_FAILURE);
  }
  if (close (fd) == -1) {
    perror (filename);
    unlink (filename);
    exit (EXIT_FAILURE);
  }
  if (guestfs_add_drive (g, filename) == -1) {
    printf ("guestfs_add_drive %s FAILED\n", filename);
    exit (EXIT_FAILURE);
  }

  if (guestfs_add_drive_ro (g, "../data/test.iso") == -1) {
    printf ("guestfs_add_drive_ro ../data/test.iso FAILED\n");
    exit (EXIT_FAILURE);
  }

  /* Set a timeout in case qemu hangs during launch (RHBZ#505329). */
  alarm (600);

  if (guestfs_launch (g) == -1) {
    printf ("guestfs_launch FAILED\n");
    exit (EXIT_FAILURE);
  }

  /* Cancel previous alarm. */
  alarm (0);

  /* Create ext2 filesystem on /dev/sdb1 partition. */
  if (guestfs_part_disk (g, "/dev/sdb", "mbr") == -1) {
    printf ("guestfs_part_disk FAILED\n");
    exit (EXIT_FAILURE);
  }
  if (guestfs_mkfs (g, "ext2", "/dev/sdb1") == -1) {
    printf ("guestfs_mkfs (/dev/sdb1) FAILED\n");
    exit (EXIT_FAILURE);
  }

  test_num++;
  next_test (g, test_num, nr_tests, "test_part_get_gpt_type_0");
  if (test_part_get_gpt_type_0 () == -1) {
    printf ("%s FAILED\n", "test_part_get_gpt_type_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_cap_set_file_0");
  if (test_cap_set_file_0 () == -1) {
    printf ("%s FAILED\n", "test_cap_set_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_acl_delete_def_file_0");
  if (test_acl_delete_def_file_0 () == -1) {
    printf ("%s FAILED\n", "test_acl_delete_def_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_acl_delete_def_file_1");
  if (test_acl_delete_def_file_1 () == -1) {
    printf ("%s FAILED\n", "test_acl_delete_def_file_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_acl_set_file_0");
  if (test_acl_set_file_0 () == -1) {
    printf ("%s FAILED\n", "test_acl_set_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mklost_and_found_0");
  if (test_mklost_and_found_0 () == -1) {
    printf ("%s FAILED\n", "test_mklost_and_found_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mktemp_0");
  if (test_mktemp_0 () == -1) {
    printf ("%s FAILED\n", "test_mktemp_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mke2fs_0");
  if (test_mke2fs_0 () == -1) {
    printf ("%s FAILED\n", "test_mke2fs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mke2fs_1");
  if (test_mke2fs_1 () == -1) {
    printf ("%s FAILED\n", "test_mke2fs_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mke2fs_2");
  if (test_mke2fs_2 () == -1) {
    printf ("%s FAILED\n", "test_mke2fs_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rm_f_0");
  if (test_rm_f_0 () == -1) {
    printf ("%s FAILED\n", "test_rm_f_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rm_f_1");
  if (test_rm_f_1 () == -1) {
    printf ("%s FAILED\n", "test_rm_f_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_xfs_repair_0");
  if (test_xfs_repair_0 () == -1) {
    printf ("%s FAILED\n", "test_xfs_repair_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_xfs_admin_0");
  if (test_xfs_admin_0 () == -1) {
    printf ("%s FAILED\n", "test_xfs_admin_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_xfs_growfs_0");
  if (test_xfs_growfs_0 () == -1) {
    printf ("%s FAILED\n", "test_xfs_growfs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utsname_0");
  if (test_utsname_0 () == -1) {
    printf ("%s FAILED\n", "test_utsname_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgchange_uuid_all_0");
  if (test_vgchange_uuid_all_0 () == -1) {
    printf ("%s FAILED\n", "test_vgchange_uuid_all_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgchange_uuid_0");
  if (test_vgchange_uuid_0 () == -1) {
    printf ("%s FAILED\n", "test_vgchange_uuid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvchange_uuid_all_0");
  if (test_pvchange_uuid_all_0 () == -1) {
    printf ("%s FAILED\n", "test_pvchange_uuid_all_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvchange_uuid_0");
  if (test_pvchange_uuid_0 () == -1) {
    printf ("%s FAILED\n", "test_pvchange_uuid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_xfs_info_0");
  if (test_xfs_info_0 () == -1) {
    printf ("%s FAILED\n", "test_xfs_info_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_nr_devices_0");
  if (test_nr_devices_0 () == -1) {
    printf ("%s FAILED\n", "test_nr_devices_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_device_index_0");
  if (test_device_index_0 () == -1) {
    printf ("%s FAILED\n", "test_device_index_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_btrfs_fsck_0");
  if (test_btrfs_fsck_0 () == -1) {
    printf ("%s FAILED\n", "test_btrfs_fsck_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_btrfs_set_seeding_0");
  if (test_btrfs_set_seeding_0 () == -1) {
    printf ("%s FAILED\n", "test_btrfs_set_seeding_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_btrfs_filesystem_sync_0");
  if (test_btrfs_filesystem_sync_0 () == -1) {
    printf ("%s FAILED\n", "test_btrfs_filesystem_sync_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_btrfs_subvolume_delete_0");
  if (test_btrfs_subvolume_delete_0 () == -1) {
    printf ("%s FAILED\n", "test_btrfs_subvolume_delete_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_btrfs_subvolume_snapshot_0");
  if (test_btrfs_subvolume_snapshot_0 () == -1) {
    printf ("%s FAILED\n", "test_btrfs_subvolume_snapshot_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2generation_0");
  if (test_get_e2generation_0 () == -1) {
    printf ("%s FAILED\n", "test_get_e2generation_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_0");
  if (test_get_e2attrs_0 () == -1) {
    printf ("%s FAILED\n", "test_get_e2attrs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_1");
  if (test_get_e2attrs_1 () == -1) {
    printf ("%s FAILED\n", "test_get_e2attrs_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_2");
  if (test_get_e2attrs_2 () == -1) {
    printf ("%s FAILED\n", "test_get_e2attrs_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_3");
  if (test_get_e2attrs_3 () == -1) {
    printf ("%s FAILED\n", "test_get_e2attrs_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_4");
  if (test_get_e2attrs_4 () == -1) {
    printf ("%s FAILED\n", "test_get_e2attrs_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_5");
  if (test_get_e2attrs_5 () == -1) {
    printf ("%s FAILED\n", "test_get_e2attrs_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_6");
  if (test_get_e2attrs_6 () == -1) {
    printf ("%s FAILED\n", "test_get_e2attrs_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2attrs_7");
  if (test_get_e2attrs_7 () == -1) {
    printf ("%s FAILED\n", "test_get_e2attrs_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_btrfs_0");
  if (test_mkfs_btrfs_0 () == -1) {
    printf ("%s FAILED\n", "test_mkfs_btrfs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_isoinfo_device_0");
  if (test_isoinfo_device_0 () == -1) {
    printf ("%s FAILED\n", "test_isoinfo_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvcreate_free_0");
  if (test_lvcreate_free_0 () == -1) {
    printf ("%s FAILED\n", "test_lvcreate_free_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zero_free_space_0");
  if (test_zero_free_space_0 () == -1) {
    printf ("%s FAILED\n", "test_zero_free_space_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_label_0");
  if (test_set_label_0 () == -1) {
    printf ("%s FAILED\n", "test_set_label_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_label_1");
  if (test_set_label_1 () == -1) {
    printf ("%s FAILED\n", "test_set_label_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_label_2");
  if (test_set_label_2 () == -1) {
    printf ("%s FAILED\n", "test_set_label_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ntfsfix_0");
  if (test_ntfsfix_0 () == -1) {
    printf ("%s FAILED\n", "test_ntfsfix_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_wipefs_0");
  if (test_wipefs_0 () == -1) {
    printf ("%s FAILED\n", "test_wipefs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blkid_0");
  if (test_blkid_0 () == -1) {
    printf ("%s FAILED\n", "test_blkid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tune2fs_0");
  if (test_tune2fs_0 () == -1) {
    printf ("%s FAILED\n", "test_tune2fs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tune2fs_1");
  if (test_tune2fs_1 () == -1) {
    printf ("%s FAILED\n", "test_tune2fs_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tune2fs_2");
  if (test_tune2fs_2 () == -1) {
    printf ("%s FAILED\n", "test_tune2fs_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tune2fs_3");
  if (test_tune2fs_3 () == -1) {
    printf ("%s FAILED\n", "test_tune2fs_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_copy_file_to_file_0");
  if (test_copy_file_to_file_0 () == -1) {
    printf ("%s FAILED\n", "test_copy_file_to_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_to_partnum_0");
  if (test_part_to_partnum_0 () == -1) {
    printf ("%s FAILED\n", "test_part_to_partnum_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_to_partnum_1");
  if (test_part_to_partnum_1 () == -1) {
    printf ("%s FAILED\n", "test_part_to_partnum_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_append_0");
  if (test_internal_write_append_0 () == -1) {
    printf ("%s FAILED\n", "test_internal_write_append_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_zero_device_0");
  if (test_is_zero_device_0 () == -1) {
    printf ("%s FAILED\n", "test_is_zero_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_zero_device_1");
  if (test_is_zero_device_1 () == -1) {
    printf ("%s FAILED\n", "test_is_zero_device_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_zero_0");
  if (test_is_zero_0 () == -1) {
    printf ("%s FAILED\n", "test_is_zero_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_zero_1");
  if (test_is_zero_1 () == -1) {
    printf ("%s FAILED\n", "test_is_zero_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_0");
  if (test_mkfs_0 () == -1) {
    printf ("%s FAILED\n", "test_mkfs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvm_canonical_lv_name_0");
  if (test_lvm_canonical_lv_name_0 () == -1) {
    printf ("%s FAILED\n", "test_lvm_canonical_lv_name_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvm_canonical_lv_name_1");
  if (test_lvm_canonical_lv_name_1 () == -1) {
    printf ("%s FAILED\n", "test_lvm_canonical_lv_name_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pread_device_0");
  if (test_pread_device_0 () == -1) {
    printf ("%s FAILED\n", "test_pread_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pwrite_device_0");
  if (test_pwrite_device_0 () == -1) {
    printf ("%s FAILED\n", "test_pwrite_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_download_offset_0");
  if (test_download_offset_0 () == -1) {
    printf ("%s FAILED\n", "test_download_offset_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_upload_offset_0");
  if (test_upload_offset_0 () == -1) {
    printf ("%s FAILED\n", "test_upload_offset_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_to_dev_0");
  if (test_part_to_dev_0 () == -1) {
    printf ("%s FAILED\n", "test_part_to_dev_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_to_dev_1");
  if (test_part_to_dev_1 () == -1) {
    printf ("%s FAILED\n", "test_part_to_dev_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_socket_0");
  if (test_is_socket_0 () == -1) {
    printf ("%s FAILED\n", "test_is_socket_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_symlink_0");
  if (test_is_symlink_0 () == -1) {
    printf ("%s FAILED\n", "test_is_symlink_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_symlink_1");
  if (test_is_symlink_1 () == -1) {
    printf ("%s FAILED\n", "test_is_symlink_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_fifo_0");
  if (test_is_fifo_0 () == -1) {
    printf ("%s FAILED\n", "test_is_fifo_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_fifo_1");
  if (test_is_fifo_1 () == -1) {
    printf ("%s FAILED\n", "test_is_fifo_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_blockdev_0");
  if (test_is_blockdev_0 () == -1) {
    printf ("%s FAILED\n", "test_is_blockdev_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_blockdev_1");
  if (test_is_blockdev_1 () == -1) {
    printf ("%s FAILED\n", "test_is_blockdev_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_chardev_0");
  if (test_is_chardev_0 () == -1) {
    printf ("%s FAILED\n", "test_is_chardev_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_chardev_1");
  if (test_is_chardev_1 () == -1) {
    printf ("%s FAILED\n", "test_is_chardev_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_lv_0");
  if (test_is_lv_0 () == -1) {
    printf ("%s FAILED\n", "test_is_lv_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_lv_1");
  if (test_is_lv_1 () == -1) {
    printf ("%s FAILED\n", "test_is_lv_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vfs_uuid_0");
  if (test_vfs_uuid_0 () == -1) {
    printf ("%s FAILED\n", "test_vfs_uuid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vfs_label_0");
  if (test_vfs_label_0 () == -1) {
    printf ("%s FAILED\n", "test_vfs_label_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fallocate64_0");
  if (test_fallocate64_0 () == -1) {
    printf ("%s FAILED\n", "test_fallocate64_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_available_all_groups_0");
  if (test_available_all_groups_0 () == -1) {
    printf ("%s FAILED\n", "test_available_all_groups_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pwrite_0");
  if (test_pwrite_0 () == -1) {
    printf ("%s FAILED\n", "test_pwrite_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pwrite_1");
  if (test_pwrite_1 () == -1) {
    printf ("%s FAILED\n", "test_pwrite_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pwrite_2");
  if (test_pwrite_2 () == -1) {
    printf ("%s FAILED\n", "test_pwrite_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_0");
  if (test_internal_write_0 () == -1) {
    printf ("%s FAILED\n", "test_internal_write_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_1");
  if (test_internal_write_1 () == -1) {
    printf ("%s FAILED\n", "test_internal_write_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_2");
  if (test_internal_write_2 () == -1) {
    printf ("%s FAILED\n", "test_internal_write_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_3");
  if (test_internal_write_3 () == -1) {
    printf ("%s FAILED\n", "test_internal_write_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_4");
  if (test_internal_write_4 () == -1) {
    printf ("%s FAILED\n", "test_internal_write_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_internal_write_5");
  if (test_internal_write_5 () == -1) {
    printf ("%s FAILED\n", "test_internal_write_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fill_pattern_0");
  if (test_fill_pattern_0 () == -1) {
    printf ("%s FAILED\n", "test_fill_pattern_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_base64_in_0");
  if (test_base64_in_0 () == -1) {
    printf ("%s FAILED\n", "test_base64_in_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_umask_0");
  if (test_get_umask_0 () == -1) {
    printf ("%s FAILED\n", "test_get_umask_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvresize_free_0");
  if (test_lvresize_free_0 () == -1) {
    printf ("%s FAILED\n", "test_lvresize_free_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_device_0");
  if (test_checksum_device_0 () == -1) {
    printf ("%s FAILED\n", "test_checksum_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_get_mbr_id_0");
  if (test_part_get_mbr_id_0 () == -1) {
    printf ("%s FAILED\n", "test_part_get_mbr_id_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_get_bootable_0");
  if (test_part_get_bootable_0 () == -1) {
    printf ("%s FAILED\n", "test_part_get_bootable_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_del_0");
  if (test_part_del_0 () == -1) {
    printf ("%s FAILED\n", "test_part_del_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgscan_0");
  if (test_vgscan_0 () == -1) {
    printf ("%s FAILED\n", "test_vgscan_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_txz_in_0");
  if (test_txz_in_0 () == -1) {
    printf ("%s FAILED\n", "test_txz_in_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zero_device_0");
  if (test_zero_device_0 () == -1) {
    printf ("%s FAILED\n", "test_zero_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_copy_size_0");
  if (test_copy_size_0 () == -1) {
    printf ("%s FAILED\n", "test_copy_size_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_initrd_cat_0");
  if (test_initrd_cat_0 () == -1) {
    printf ("%s FAILED\n", "test_initrd_cat_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgrename_0");
  if (test_vgrename_0 () == -1) {
    printf ("%s FAILED\n", "test_vgrename_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvrename_0");
  if (test_lvrename_0 () == -1) {
    printf ("%s FAILED\n", "test_lvrename_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_filesize_0");
  if (test_filesize_0 () == -1) {
    printf ("%s FAILED\n", "test_filesize_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_dd_0");
  if (test_dd_0 () == -1) {
    printf ("%s FAILED\n", "test_dd_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_available_0");
  if (test_available_0 () == -1) {
    printf ("%s FAILED\n", "test_available_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fill_0");
  if (test_fill_0 () == -1) {
    printf ("%s FAILED\n", "test_fill_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_get_parttype_0");
  if (test_part_get_parttype_0 () == -1) {
    printf ("%s FAILED\n", "test_part_get_parttype_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_set_name_0");
  if (test_part_set_name_0 () == -1) {
    printf ("%s FAILED\n", "test_part_set_name_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_set_bootable_0");
  if (test_part_set_bootable_0 () == -1) {
    printf ("%s FAILED\n", "test_part_set_bootable_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_disk_0");
  if (test_part_disk_0 () == -1) {
    printf ("%s FAILED\n", "test_part_disk_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_disk_1");
  if (test_part_disk_1 () == -1) {
    printf ("%s FAILED\n", "test_part_disk_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_add_0");
  if (test_part_add_0 () == -1) {
    printf ("%s FAILED\n", "test_part_add_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_add_1");
  if (test_part_add_1 () == -1) {
    printf ("%s FAILED\n", "test_part_add_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_add_2");
  if (test_part_add_2 () == -1) {
    printf ("%s FAILED\n", "test_part_add_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_part_init_0");
  if (test_part_init_0 () == -1) {
    printf ("%s FAILED\n", "test_part_init_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pread_0");
  if (test_pread_0 () == -1) {
    printf ("%s FAILED\n", "test_pread_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pread_1");
  if (test_pread_1 () == -1) {
    printf ("%s FAILED\n", "test_pread_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_mode_0");
  if (test_mkdir_mode_0 () == -1) {
    printf ("%s FAILED\n", "test_mkdir_mode_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utimens_0");
  if (test_utimens_0 () == -1) {
    printf ("%s FAILED\n", "test_utimens_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utimens_1");
  if (test_utimens_1 () == -1) {
    printf ("%s FAILED\n", "test_utimens_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utimens_2");
  if (test_utimens_2 () == -1) {
    printf ("%s FAILED\n", "test_utimens_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utimens_3");
  if (test_utimens_3 () == -1) {
    printf ("%s FAILED\n", "test_utimens_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utimens_4");
  if (test_utimens_4 () == -1) {
    printf ("%s FAILED\n", "test_utimens_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_utimens_5");
  if (test_utimens_5 () == -1) {
    printf ("%s FAILED\n", "test_utimens_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_truncate_size_0");
  if (test_truncate_size_0 () == -1) {
    printf ("%s FAILED\n", "test_truncate_size_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_truncate_0");
  if (test_truncate_0 () == -1) {
    printf ("%s FAILED\n", "test_truncate_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vfs_type_0");
  if (test_vfs_type_0 () == -1) {
    printf ("%s FAILED\n", "test_vfs_type_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_0");
  if (test_case_sensitive_path_0 () == -1) {
    printf ("%s FAILED\n", "test_case_sensitive_path_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_1");
  if (test_case_sensitive_path_1 () == -1) {
    printf ("%s FAILED\n", "test_case_sensitive_path_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_2");
  if (test_case_sensitive_path_2 () == -1) {
    printf ("%s FAILED\n", "test_case_sensitive_path_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_3");
  if (test_case_sensitive_path_3 () == -1) {
    printf ("%s FAILED\n", "test_case_sensitive_path_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_4");
  if (test_case_sensitive_path_4 () == -1) {
    printf ("%s FAILED\n", "test_case_sensitive_path_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_5");
  if (test_case_sensitive_path_5 () == -1) {
    printf ("%s FAILED\n", "test_case_sensitive_path_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_6");
  if (test_case_sensitive_path_6 () == -1) {
    printf ("%s FAILED\n", "test_case_sensitive_path_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_case_sensitive_path_7");
  if (test_case_sensitive_path_7 () == -1) {
    printf ("%s FAILED\n", "test_case_sensitive_path_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_echo_daemon_0");
  if (test_echo_daemon_0 () == -1) {
    printf ("%s FAILED\n", "test_echo_daemon_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_modprobe_0");
  if (test_modprobe_0 () == -1) {
    printf ("%s FAILED\n", "test_modprobe_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mke2journal_U_0");
  if (test_mke2journal_U_0 () == -1) {
    printf ("%s FAILED\n", "test_mke2journal_U_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mke2journal_L_0");
  if (test_mke2journal_L_0 () == -1) {
    printf ("%s FAILED\n", "test_mke2journal_L_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mke2journal_0");
  if (test_mke2journal_0 () == -1) {
    printf ("%s FAILED\n", "test_mke2journal_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_b_0");
  if (test_mkfs_b_0 () == -1) {
    printf ("%s FAILED\n", "test_mkfs_b_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_b_1");
  if (test_mkfs_b_1 () == -1) {
    printf ("%s FAILED\n", "test_mkfs_b_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_b_2");
  if (test_mkfs_b_2 () == -1) {
    printf ("%s FAILED\n", "test_mkfs_b_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_b_3");
  if (test_mkfs_b_3 () == -1) {
    printf ("%s FAILED\n", "test_mkfs_b_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfs_b_4");
  if (test_mkfs_b_4 () == -1) {
    printf ("%s FAILED\n", "test_mkfs_b_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_inotify_add_watch_0");
  if (test_inotify_add_watch_0 () == -1) {
    printf ("%s FAILED\n", "test_inotify_add_watch_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_inotify_init_0");
  if (test_inotify_init_0 () == -1) {
    printf ("%s FAILED\n", "test_inotify_init_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_file_0");
  if (test_mkswap_file_0 () == -1) {
    printf ("%s FAILED\n", "test_mkswap_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_swapon_uuid_0");
  if (test_swapon_uuid_0 () == -1) {
    printf ("%s FAILED\n", "test_swapon_uuid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_swapon_label_0");
  if (test_swapon_label_0 () == -1) {
    printf ("%s FAILED\n", "test_swapon_label_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_swapon_file_0");
  if (test_swapon_file_0 () == -1) {
    printf ("%s FAILED\n", "test_swapon_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_swapon_device_0");
  if (test_swapon_device_0 () == -1) {
    printf ("%s FAILED\n", "test_swapon_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fallocate_0");
  if (test_fallocate_0 () == -1) {
    printf ("%s FAILED\n", "test_fallocate_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ln_sf_0");
  if (test_ln_sf_0 () == -1) {
    printf ("%s FAILED\n", "test_ln_sf_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ln_s_0");
  if (test_ln_s_0 () == -1) {
    printf ("%s FAILED\n", "test_ln_s_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ln_f_0");
  if (test_ln_f_0 () == -1) {
    printf ("%s FAILED\n", "test_ln_f_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ln_0");
  if (test_ln_0 () == -1) {
    printf ("%s FAILED\n", "test_ln_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_realpath_0");
  if (test_realpath_0 () == -1) {
    printf ("%s FAILED\n", "test_realpath_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zfgrepi_0");
  if (test_zfgrepi_0 () == -1) {
    printf ("%s FAILED\n", "test_zfgrepi_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zegrepi_0");
  if (test_zegrepi_0 () == -1) {
    printf ("%s FAILED\n", "test_zegrepi_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zgrepi_0");
  if (test_zgrepi_0 () == -1) {
    printf ("%s FAILED\n", "test_zgrepi_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zfgrep_0");
  if (test_zfgrep_0 () == -1) {
    printf ("%s FAILED\n", "test_zfgrep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zegrep_0");
  if (test_zegrep_0 () == -1) {
    printf ("%s FAILED\n", "test_zegrep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zgrep_0");
  if (test_zgrep_0 () == -1) {
    printf ("%s FAILED\n", "test_zgrep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fgrepi_0");
  if (test_fgrepi_0 () == -1) {
    printf ("%s FAILED\n", "test_fgrepi_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_egrepi_0");
  if (test_egrepi_0 () == -1) {
    printf ("%s FAILED\n", "test_egrepi_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grepi_0");
  if (test_grepi_0 () == -1) {
    printf ("%s FAILED\n", "test_grepi_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fgrep_0");
  if (test_fgrep_0 () == -1) {
    printf ("%s FAILED\n", "test_fgrep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_egrep_0");
  if (test_egrep_0 () == -1) {
    printf ("%s FAILED\n", "test_egrep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_0");
  if (test_grep_0 () == -1) {
    printf ("%s FAILED\n", "test_grep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_1");
  if (test_grep_1 () == -1) {
    printf ("%s FAILED\n", "test_grep_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_2");
  if (test_grep_2 () == -1) {
    printf ("%s FAILED\n", "test_grep_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_3");
  if (test_grep_3 () == -1) {
    printf ("%s FAILED\n", "test_grep_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_4");
  if (test_grep_4 () == -1) {
    printf ("%s FAILED\n", "test_grep_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_5");
  if (test_grep_5 () == -1) {
    printf ("%s FAILED\n", "test_grep_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_6");
  if (test_grep_6 () == -1) {
    printf ("%s FAILED\n", "test_grep_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_7");
  if (test_grep_7 () == -1) {
    printf ("%s FAILED\n", "test_grep_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_8");
  if (test_grep_8 () == -1) {
    printf ("%s FAILED\n", "test_grep_8");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_9");
  if (test_grep_9 () == -1) {
    printf ("%s FAILED\n", "test_grep_9");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_10");
  if (test_grep_10 () == -1) {
    printf ("%s FAILED\n", "test_grep_10");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_11");
  if (test_grep_11 () == -1) {
    printf ("%s FAILED\n", "test_grep_11");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_12");
  if (test_grep_12 () == -1) {
    printf ("%s FAILED\n", "test_grep_12");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grep_13");
  if (test_grep_13 () == -1) {
    printf ("%s FAILED\n", "test_grep_13");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_umask_0");
  if (test_umask_0 () == -1) {
    printf ("%s FAILED\n", "test_umask_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mknod_c_0");
  if (test_mknod_c_0 () == -1) {
    printf ("%s FAILED\n", "test_mknod_c_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mknod_b_0");
  if (test_mknod_b_0 () == -1) {
    printf ("%s FAILED\n", "test_mknod_b_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkfifo_0");
  if (test_mkfifo_0 () == -1) {
    printf ("%s FAILED\n", "test_mkfifo_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mknod_0");
  if (test_mknod_0 () == -1) {
    printf ("%s FAILED\n", "test_mknod_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mknod_1");
  if (test_mknod_1 () == -1) {
    printf ("%s FAILED\n", "test_mknod_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_U_0");
  if (test_mkswap_U_0 () == -1) {
    printf ("%s FAILED\n", "test_mkswap_U_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_L_0");
  if (test_mkswap_L_0 () == -1) {
    printf ("%s FAILED\n", "test_mkswap_L_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_0");
  if (test_mkswap_0 () == -1) {
    printf ("%s FAILED\n", "test_mkswap_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_1");
  if (test_mkswap_1 () == -1) {
    printf ("%s FAILED\n", "test_mkswap_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_2");
  if (test_mkswap_2 () == -1) {
    printf ("%s FAILED\n", "test_mkswap_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkswap_3");
  if (test_mkswap_3 () == -1) {
    printf ("%s FAILED\n", "test_mkswap_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_initrd_list_0");
  if (test_initrd_list_0 () == -1) {
    printf ("%s FAILED\n", "test_initrd_list_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_du_0");
  if (test_du_0 () == -1) {
    printf ("%s FAILED\n", "test_du_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tail_n_0");
  if (test_tail_n_0 () == -1) {
    printf ("%s FAILED\n", "test_tail_n_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tail_n_1");
  if (test_tail_n_1 () == -1) {
    printf ("%s FAILED\n", "test_tail_n_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tail_n_2");
  if (test_tail_n_2 () == -1) {
    printf ("%s FAILED\n", "test_tail_n_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tail_0");
  if (test_tail_0 () == -1) {
    printf ("%s FAILED\n", "test_tail_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_head_n_0");
  if (test_head_n_0 () == -1) {
    printf ("%s FAILED\n", "test_head_n_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_head_n_1");
  if (test_head_n_1 () == -1) {
    printf ("%s FAILED\n", "test_head_n_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_head_n_2");
  if (test_head_n_2 () == -1) {
    printf ("%s FAILED\n", "test_head_n_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_head_0");
  if (test_head_0 () == -1) {
    printf ("%s FAILED\n", "test_head_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_head_1");
  if (test_head_1 () == -1) {
    printf ("%s FAILED\n", "test_head_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_wc_c_0");
  if (test_wc_c_0 () == -1) {
    printf ("%s FAILED\n", "test_wc_c_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_wc_w_0");
  if (test_wc_w_0 () == -1) {
    printf ("%s FAILED\n", "test_wc_w_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_wc_l_0");
  if (test_wc_l_0 () == -1) {
    printf ("%s FAILED\n", "test_wc_l_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_wc_l_1");
  if (test_wc_l_1 () == -1) {
    printf ("%s FAILED\n", "test_wc_l_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdtemp_0");
  if (test_mkdtemp_0 () == -1) {
    printf ("%s FAILED\n", "test_mkdtemp_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_scrub_file_0");
  if (test_scrub_file_0 () == -1) {
    printf ("%s FAILED\n", "test_scrub_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_scrub_device_0");
  if (test_scrub_device_0 () == -1) {
    printf ("%s FAILED\n", "test_scrub_device_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_glob_expand_0");
  if (test_glob_expand_0 () == -1) {
    printf ("%s FAILED\n", "test_glob_expand_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_glob_expand_1");
  if (test_glob_expand_1 () == -1) {
    printf ("%s FAILED\n", "test_glob_expand_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_glob_expand_2");
  if (test_glob_expand_2 () == -1) {
    printf ("%s FAILED\n", "test_glob_expand_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ntfs_3g_probe_0");
  if (test_ntfs_3g_probe_0 () == -1) {
    printf ("%s FAILED\n", "test_ntfs_3g_probe_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ntfs_3g_probe_1");
  if (test_ntfs_3g_probe_1 () == -1) {
    printf ("%s FAILED\n", "test_ntfs_3g_probe_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_sleep_0");
  if (test_sleep_0 () == -1) {
    printf ("%s FAILED\n", "test_sleep_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvresize_0");
  if (test_lvresize_0 () == -1) {
    printf ("%s FAILED\n", "test_lvresize_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvresize_1");
  if (test_lvresize_1 () == -1) {
    printf ("%s FAILED\n", "test_lvresize_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zerofree_0");
  if (test_zerofree_0 () == -1) {
    printf ("%s FAILED\n", "test_zerofree_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_hexdump_0");
  if (test_hexdump_0 () == -1) {
    printf ("%s FAILED\n", "test_hexdump_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_hexdump_1");
  if (test_hexdump_1 () == -1) {
    printf ("%s FAILED\n", "test_hexdump_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_hexdump_2");
  if (test_hexdump_2 () == -1) {
    printf ("%s FAILED\n", "test_hexdump_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_strings_e_0");
  if (test_strings_e_0 () == -1) {
    printf ("%s FAILED\n", "test_strings_e_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_strings_e_1");
  if (test_strings_e_1 () == -1) {
    printf ("%s FAILED\n", "test_strings_e_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_strings_0");
  if (test_strings_0 () == -1) {
    printf ("%s FAILED\n", "test_strings_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_strings_1");
  if (test_strings_1 () == -1) {
    printf ("%s FAILED\n", "test_strings_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_strings_2");
  if (test_strings_2 () == -1) {
    printf ("%s FAILED\n", "test_strings_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_equal_0");
  if (test_equal_0 () == -1) {
    printf ("%s FAILED\n", "test_equal_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_equal_1");
  if (test_equal_1 () == -1) {
    printf ("%s FAILED\n", "test_equal_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_equal_2");
  if (test_equal_2 () == -1) {
    printf ("%s FAILED\n", "test_equal_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ping_daemon_0");
  if (test_ping_daemon_0 () == -1) {
    printf ("%s FAILED\n", "test_ping_daemon_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_dmesg_0");
  if (test_dmesg_0 () == -1) {
    printf ("%s FAILED\n", "test_dmesg_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_drop_caches_0");
  if (test_drop_caches_0 () == -1) {
    printf ("%s FAILED\n", "test_drop_caches_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mv_0");
  if (test_mv_0 () == -1) {
    printf ("%s FAILED\n", "test_mv_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mv_1");
  if (test_mv_1 () == -1) {
    printf ("%s FAILED\n", "test_mv_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_cp_a_0");
  if (test_cp_a_0 () == -1) {
    printf ("%s FAILED\n", "test_cp_a_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_cp_0");
  if (test_cp_0 () == -1) {
    printf ("%s FAILED\n", "test_cp_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_cp_1");
  if (test_cp_1 () == -1) {
    printf ("%s FAILED\n", "test_cp_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_cp_2");
  if (test_cp_2 () == -1) {
    printf ("%s FAILED\n", "test_cp_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_grub_install_0");
  if (test_grub_install_0 () == -1) {
    printf ("%s FAILED\n", "test_grub_install_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_zero_0");
  if (test_zero_0 () == -1) {
    printf ("%s FAILED\n", "test_zero_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fsck_0");
  if (test_fsck_0 () == -1) {
    printf ("%s FAILED\n", "test_fsck_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_fsck_1");
  if (test_fsck_1 () == -1) {
    printf ("%s FAILED\n", "test_fsck_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_e2uuid_0");
  if (test_get_e2uuid_0 () == -1) {
    printf ("%s FAILED\n", "test_get_e2uuid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_e2uuid_0");
  if (test_set_e2uuid_0 () == -1) {
    printf ("%s FAILED\n", "test_set_e2uuid_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_e2uuid_1");
  if (test_set_e2uuid_1 () == -1) {
    printf ("%s FAILED\n", "test_set_e2uuid_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_e2uuid_2");
  if (test_set_e2uuid_2 () == -1) {
    printf ("%s FAILED\n", "test_set_e2uuid_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_e2uuid_3");
  if (test_set_e2uuid_3 () == -1) {
    printf ("%s FAILED\n", "test_set_e2uuid_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_e2label_0");
  if (test_set_e2label_0 () == -1) {
    printf ("%s FAILED\n", "test_set_e2label_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvremove_0");
  if (test_pvremove_0 () == -1) {
    printf ("%s FAILED\n", "test_pvremove_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvremove_1");
  if (test_pvremove_1 () == -1) {
    printf ("%s FAILED\n", "test_pvremove_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvremove_2");
  if (test_pvremove_2 () == -1) {
    printf ("%s FAILED\n", "test_pvremove_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgremove_0");
  if (test_vgremove_0 () == -1) {
    printf ("%s FAILED\n", "test_vgremove_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgremove_1");
  if (test_vgremove_1 () == -1) {
    printf ("%s FAILED\n", "test_vgremove_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvremove_0");
  if (test_lvremove_0 () == -1) {
    printf ("%s FAILED\n", "test_lvremove_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvremove_1");
  if (test_lvremove_1 () == -1) {
    printf ("%s FAILED\n", "test_lvremove_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvremove_2");
  if (test_lvremove_2 () == -1) {
    printf ("%s FAILED\n", "test_lvremove_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mount_ro_0");
  if (test_mount_ro_0 () == -1) {
    printf ("%s FAILED\n", "test_mount_ro_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mount_ro_1");
  if (test_mount_ro_1 () == -1) {
    printf ("%s FAILED\n", "test_mount_ro_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tgz_in_0");
  if (test_tgz_in_0 () == -1) {
    printf ("%s FAILED\n", "test_tgz_in_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tar_in_0");
  if (test_tar_in_0 () == -1) {
    printf ("%s FAILED\n", "test_tar_in_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tar_in_1");
  if (test_tar_in_1 () == -1) {
    printf ("%s FAILED\n", "test_tar_in_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tar_in_2");
  if (test_tar_in_2 () == -1) {
    printf ("%s FAILED\n", "test_tar_in_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_0");
  if (test_checksum_0 () == -1) {
    printf ("%s FAILED\n", "test_checksum_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_1");
  if (test_checksum_1 () == -1) {
    printf ("%s FAILED\n", "test_checksum_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_2");
  if (test_checksum_2 () == -1) {
    printf ("%s FAILED\n", "test_checksum_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_3");
  if (test_checksum_3 () == -1) {
    printf ("%s FAILED\n", "test_checksum_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_4");
  if (test_checksum_4 () == -1) {
    printf ("%s FAILED\n", "test_checksum_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_5");
  if (test_checksum_5 () == -1) {
    printf ("%s FAILED\n", "test_checksum_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_6");
  if (test_checksum_6 () == -1) {
    printf ("%s FAILED\n", "test_checksum_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_7");
  if (test_checksum_7 () == -1) {
    printf ("%s FAILED\n", "test_checksum_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_checksum_8");
  if (test_checksum_8 () == -1) {
    printf ("%s FAILED\n", "test_checksum_8");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_download_0");
  if (test_download_0 () == -1) {
    printf ("%s FAILED\n", "test_download_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_upload_0");
  if (test_upload_0 () == -1) {
    printf ("%s FAILED\n", "test_upload_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_rereadpt_0");
  if (test_blockdev_rereadpt_0 () == -1) {
    printf ("%s FAILED\n", "test_blockdev_rereadpt_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_flushbufs_0");
  if (test_blockdev_flushbufs_0 () == -1) {
    printf ("%s FAILED\n", "test_blockdev_flushbufs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_getsize64_0");
  if (test_blockdev_getsize64_0 () == -1) {
    printf ("%s FAILED\n", "test_blockdev_getsize64_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_getsz_0");
  if (test_blockdev_getsz_0 () == -1) {
    printf ("%s FAILED\n", "test_blockdev_getsz_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_getss_0");
  if (test_blockdev_getss_0 () == -1) {
    printf ("%s FAILED\n", "test_blockdev_getss_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_getro_0");
  if (test_blockdev_getro_0 () == -1) {
    printf ("%s FAILED\n", "test_blockdev_getro_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_setrw_0");
  if (test_blockdev_setrw_0 () == -1) {
    printf ("%s FAILED\n", "test_blockdev_setrw_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_blockdev_setro_0");
  if (test_blockdev_setro_0 () == -1) {
    printf ("%s FAILED\n", "test_blockdev_setro_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_tune2fs_l_0");
  if (test_tune2fs_l_0 () == -1) {
    printf ("%s FAILED\n", "test_tune2fs_l_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_statvfs_0");
  if (test_statvfs_0 () == -1) {
    printf ("%s FAILED\n", "test_statvfs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lstat_0");
  if (test_lstat_0 () == -1) {
    printf ("%s FAILED\n", "test_lstat_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_stat_0");
  if (test_stat_0 () == -1) {
    printf ("%s FAILED\n", "test_stat_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_0");
  if (test_command_lines_0 () == -1) {
    printf ("%s FAILED\n", "test_command_lines_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_1");
  if (test_command_lines_1 () == -1) {
    printf ("%s FAILED\n", "test_command_lines_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_2");
  if (test_command_lines_2 () == -1) {
    printf ("%s FAILED\n", "test_command_lines_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_3");
  if (test_command_lines_3 () == -1) {
    printf ("%s FAILED\n", "test_command_lines_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_4");
  if (test_command_lines_4 () == -1) {
    printf ("%s FAILED\n", "test_command_lines_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_5");
  if (test_command_lines_5 () == -1) {
    printf ("%s FAILED\n", "test_command_lines_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_6");
  if (test_command_lines_6 () == -1) {
    printf ("%s FAILED\n", "test_command_lines_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_7");
  if (test_command_lines_7 () == -1) {
    printf ("%s FAILED\n", "test_command_lines_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_8");
  if (test_command_lines_8 () == -1) {
    printf ("%s FAILED\n", "test_command_lines_8");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_9");
  if (test_command_lines_9 () == -1) {
    printf ("%s FAILED\n", "test_command_lines_9");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_lines_10");
  if (test_command_lines_10 () == -1) {
    printf ("%s FAILED\n", "test_command_lines_10");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_0");
  if (test_command_0 () == -1) {
    printf ("%s FAILED\n", "test_command_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_1");
  if (test_command_1 () == -1) {
    printf ("%s FAILED\n", "test_command_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_2");
  if (test_command_2 () == -1) {
    printf ("%s FAILED\n", "test_command_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_3");
  if (test_command_3 () == -1) {
    printf ("%s FAILED\n", "test_command_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_4");
  if (test_command_4 () == -1) {
    printf ("%s FAILED\n", "test_command_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_5");
  if (test_command_5 () == -1) {
    printf ("%s FAILED\n", "test_command_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_6");
  if (test_command_6 () == -1) {
    printf ("%s FAILED\n", "test_command_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_7");
  if (test_command_7 () == -1) {
    printf ("%s FAILED\n", "test_command_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_8");
  if (test_command_8 () == -1) {
    printf ("%s FAILED\n", "test_command_8");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_9");
  if (test_command_9 () == -1) {
    printf ("%s FAILED\n", "test_command_9");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_10");
  if (test_command_10 () == -1) {
    printf ("%s FAILED\n", "test_command_10");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_11");
  if (test_command_11 () == -1) {
    printf ("%s FAILED\n", "test_command_11");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_command_12");
  if (test_command_12 () == -1) {
    printf ("%s FAILED\n", "test_command_12");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_0");
  if (test_file_0 () == -1) {
    printf ("%s FAILED\n", "test_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_1");
  if (test_file_1 () == -1) {
    printf ("%s FAILED\n", "test_file_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_2");
  if (test_file_2 () == -1) {
    printf ("%s FAILED\n", "test_file_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_3");
  if (test_file_3 () == -1) {
    printf ("%s FAILED\n", "test_file_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_4");
  if (test_file_4 () == -1) {
    printf ("%s FAILED\n", "test_file_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_umount_all_0");
  if (test_umount_all_0 () == -1) {
    printf ("%s FAILED\n", "test_umount_all_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_umount_all_1");
  if (test_umount_all_1 () == -1) {
    printf ("%s FAILED\n", "test_umount_all_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mounts_0");
  if (test_mounts_0 () == -1) {
    printf ("%s FAILED\n", "test_mounts_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_umount_0");
  if (test_umount_0 () == -1) {
    printf ("%s FAILED\n", "test_umount_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_umount_1");
  if (test_umount_1 () == -1) {
    printf ("%s FAILED\n", "test_umount_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_file_0");
  if (test_write_file_0 () == -1) {
    printf ("%s FAILED\n", "test_write_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvcreate_0");
  if (test_lvcreate_0 () == -1) {
    printf ("%s FAILED\n", "test_lvcreate_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgcreate_0");
  if (test_vgcreate_0 () == -1) {
    printf ("%s FAILED\n", "test_vgcreate_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvcreate_0");
  if (test_pvcreate_0 () == -1) {
    printf ("%s FAILED\n", "test_pvcreate_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_dir_0");
  if (test_is_dir_0 () == -1) {
    printf ("%s FAILED\n", "test_is_dir_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_dir_1");
  if (test_is_dir_1 () == -1) {
    printf ("%s FAILED\n", "test_is_dir_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_file_0");
  if (test_is_file_0 () == -1) {
    printf ("%s FAILED\n", "test_is_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_file_1");
  if (test_is_file_1 () == -1) {
    printf ("%s FAILED\n", "test_is_file_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_exists_0");
  if (test_exists_0 () == -1) {
    printf ("%s FAILED\n", "test_exists_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_exists_1");
  if (test_exists_1 () == -1) {
    printf ("%s FAILED\n", "test_exists_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_p_0");
  if (test_mkdir_p_0 () == -1) {
    printf ("%s FAILED\n", "test_mkdir_p_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_p_1");
  if (test_mkdir_p_1 () == -1) {
    printf ("%s FAILED\n", "test_mkdir_p_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_p_2");
  if (test_mkdir_p_2 () == -1) {
    printf ("%s FAILED\n", "test_mkdir_p_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_p_3");
  if (test_mkdir_p_3 () == -1) {
    printf ("%s FAILED\n", "test_mkdir_p_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_p_4");
  if (test_mkdir_p_4 () == -1) {
    printf ("%s FAILED\n", "test_mkdir_p_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_0");
  if (test_mkdir_0 () == -1) {
    printf ("%s FAILED\n", "test_mkdir_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mkdir_1");
  if (test_mkdir_1 () == -1) {
    printf ("%s FAILED\n", "test_mkdir_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rm_rf_0");
  if (test_rm_rf_0 () == -1) {
    printf ("%s FAILED\n", "test_rm_rf_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rmdir_0");
  if (test_rmdir_0 () == -1) {
    printf ("%s FAILED\n", "test_rmdir_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rmdir_1");
  if (test_rmdir_1 () == -1) {
    printf ("%s FAILED\n", "test_rmdir_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rmdir_2");
  if (test_rmdir_2 () == -1) {
    printf ("%s FAILED\n", "test_rmdir_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rm_0");
  if (test_rm_0 () == -1) {
    printf ("%s FAILED\n", "test_rm_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rm_1");
  if (test_rm_1 () == -1) {
    printf ("%s FAILED\n", "test_rm_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_rm_2");
  if (test_rm_2 () == -1) {
    printf ("%s FAILED\n", "test_rm_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvs_0");
  if (test_lvs_0 () == -1) {
    printf ("%s FAILED\n", "test_lvs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_lvs_1");
  if (test_lvs_1 () == -1) {
    printf ("%s FAILED\n", "test_lvs_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgs_0");
  if (test_vgs_0 () == -1) {
    printf ("%s FAILED\n", "test_vgs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_vgs_1");
  if (test_vgs_1 () == -1) {
    printf ("%s FAILED\n", "test_vgs_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvs_0");
  if (test_pvs_0 () == -1) {
    printf ("%s FAILED\n", "test_pvs_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_pvs_1");
  if (test_pvs_1 () == -1) {
    printf ("%s FAILED\n", "test_pvs_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_list_partitions_0");
  if (test_list_partitions_0 () == -1) {
    printf ("%s FAILED\n", "test_list_partitions_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_list_partitions_1");
  if (test_list_partitions_1 () == -1) {
    printf ("%s FAILED\n", "test_list_partitions_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_list_devices_0");
  if (test_list_devices_0 () == -1) {
    printf ("%s FAILED\n", "test_list_devices_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_touch_0");
  if (test_touch_0 () == -1) {
    printf ("%s FAILED\n", "test_touch_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_sync_0");
  if (test_sync_0 () == -1) {
    printf ("%s FAILED\n", "test_sync_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_mount_0");
  if (test_mount_0 () == -1) {
    printf ("%s FAILED\n", "test_mount_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_has_backing_file_0");
  if (test_disk_has_backing_file_0 () == -1) {
    printf ("%s FAILED\n", "test_disk_has_backing_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_has_backing_file_1");
  if (test_disk_has_backing_file_1 () == -1) {
    printf ("%s FAILED\n", "test_disk_has_backing_file_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_has_backing_file_2");
  if (test_disk_has_backing_file_2 () == -1) {
    printf ("%s FAILED\n", "test_disk_has_backing_file_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_virtual_size_0");
  if (test_disk_virtual_size_0 () == -1) {
    printf ("%s FAILED\n", "test_disk_virtual_size_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_virtual_size_1");
  if (test_disk_virtual_size_1 () == -1) {
    printf ("%s FAILED\n", "test_disk_virtual_size_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_virtual_size_2");
  if (test_disk_virtual_size_2 () == -1) {
    printf ("%s FAILED\n", "test_disk_virtual_size_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_format_0");
  if (test_disk_format_0 () == -1) {
    printf ("%s FAILED\n", "test_disk_format_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_format_1");
  if (test_disk_format_1 () == -1) {
    printf ("%s FAILED\n", "test_disk_format_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_disk_format_2");
  if (test_disk_format_2 () == -1) {
    printf ("%s FAILED\n", "test_disk_format_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_ls_0");
  if (test_ls_0 () == -1) {
    printf ("%s FAILED\n", "test_ls_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_append_0");
  if (test_write_append_0 () == -1) {
    printf ("%s FAILED\n", "test_write_append_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_0");
  if (test_write_0 () == -1) {
    printf ("%s FAILED\n", "test_write_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_1");
  if (test_write_1 () == -1) {
    printf ("%s FAILED\n", "test_write_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_2");
  if (test_write_2 () == -1) {
    printf ("%s FAILED\n", "test_write_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_3");
  if (test_write_3 () == -1) {
    printf ("%s FAILED\n", "test_write_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_4");
  if (test_write_4 () == -1) {
    printf ("%s FAILED\n", "test_write_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_write_5");
  if (test_write_5 () == -1) {
    printf ("%s FAILED\n", "test_write_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_0");
  if (test_read_lines_0 () == -1) {
    printf ("%s FAILED\n", "test_read_lines_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_1");
  if (test_read_lines_1 () == -1) {
    printf ("%s FAILED\n", "test_read_lines_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_2");
  if (test_read_lines_2 () == -1) {
    printf ("%s FAILED\n", "test_read_lines_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_3");
  if (test_read_lines_3 () == -1) {
    printf ("%s FAILED\n", "test_read_lines_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_4");
  if (test_read_lines_4 () == -1) {
    printf ("%s FAILED\n", "test_read_lines_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_5");
  if (test_read_lines_5 () == -1) {
    printf ("%s FAILED\n", "test_read_lines_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_6");
  if (test_read_lines_6 () == -1) {
    printf ("%s FAILED\n", "test_read_lines_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_7");
  if (test_read_lines_7 () == -1) {
    printf ("%s FAILED\n", "test_read_lines_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_8");
  if (test_read_lines_8 () == -1) {
    printf ("%s FAILED\n", "test_read_lines_8");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_lines_9");
  if (test_read_lines_9 () == -1) {
    printf ("%s FAILED\n", "test_read_lines_9");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_read_file_0");
  if (test_read_file_0 () == -1) {
    printf ("%s FAILED\n", "test_read_file_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_find_0");
  if (test_find_0 () == -1) {
    printf ("%s FAILED\n", "test_find_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_find_1");
  if (test_find_1 () == -1) {
    printf ("%s FAILED\n", "test_find_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_find_2");
  if (test_find_2 () == -1) {
    printf ("%s FAILED\n", "test_find_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_cat_0");
  if (test_cat_0 () == -1) {
    printf ("%s FAILED\n", "test_cat_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_attach_method_0");
  if (test_get_attach_method_0 () == -1) {
    printf ("%s FAILED\n", "test_get_attach_method_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_0");
  if (test_file_architecture_0 () == -1) {
    printf ("%s FAILED\n", "test_file_architecture_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_1");
  if (test_file_architecture_1 () == -1) {
    printf ("%s FAILED\n", "test_file_architecture_1");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_2");
  if (test_file_architecture_2 () == -1) {
    printf ("%s FAILED\n", "test_file_architecture_2");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_3");
  if (test_file_architecture_3 () == -1) {
    printf ("%s FAILED\n", "test_file_architecture_3");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_4");
  if (test_file_architecture_4 () == -1) {
    printf ("%s FAILED\n", "test_file_architecture_4");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_5");
  if (test_file_architecture_5 () == -1) {
    printf ("%s FAILED\n", "test_file_architecture_5");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_6");
  if (test_file_architecture_6 () == -1) {
    printf ("%s FAILED\n", "test_file_architecture_6");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_7");
  if (test_file_architecture_7 () == -1) {
    printf ("%s FAILED\n", "test_file_architecture_7");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_8");
  if (test_file_architecture_8 () == -1) {
    printf ("%s FAILED\n", "test_file_architecture_8");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_9");
  if (test_file_architecture_9 () == -1) {
    printf ("%s FAILED\n", "test_file_architecture_9");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_10");
  if (test_file_architecture_10 () == -1) {
    printf ("%s FAILED\n", "test_file_architecture_10");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_file_architecture_11");
  if (test_file_architecture_11 () == -1) {
    printf ("%s FAILED\n", "test_file_architecture_11");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_set_trace_0");
  if (test_set_trace_0 () == -1) {
    printf ("%s FAILED\n", "test_set_trace_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_version_0");
  if (test_version_0 () == -1) {
    printf ("%s FAILED\n", "test_version_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_memsize_0");
  if (test_get_memsize_0 () == -1) {
    printf ("%s FAILED\n", "test_get_memsize_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_busy_0");
  if (test_is_busy_0 () == -1) {
    printf ("%s FAILED\n", "test_is_busy_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_launching_0");
  if (test_is_launching_0 () == -1) {
    printf ("%s FAILED\n", "test_is_launching_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_config_0");
  if (test_is_config_0 () == -1) {
    printf ("%s FAILED\n", "test_is_config_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_is_ready_0");
  if (test_is_ready_0 () == -1) {
    printf ("%s FAILED\n", "test_is_ready_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_autosync_0");
  if (test_get_autosync_0 () == -1) {
    printf ("%s FAILED\n", "test_get_autosync_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_path_0");
  if (test_get_path_0 () == -1) {
    printf ("%s FAILED\n", "test_get_path_0");
    nr_failed++;
  }
  test_num++;
  next_test (g, test_num, nr_tests, "test_get_qemu_0");
  if (test_get_qemu_0 () == -1) {
    printf ("%s FAILED\n", "test_get_qemu_0");
    nr_failed++;
  }

  /* Check close callback is called. */
  int close_sentinel = 1;
  guestfs_set_close_callback (g, incr, &close_sentinel);

  guestfs_close (g);

  if (close_sentinel != 2) {
    fprintf (stderr, "close callback was not called\n");
    exit (EXIT_FAILURE);
  }

  unlink ("test1.img");
  unlink ("test2.img");
  unlink ("test3.img");

  if (nr_failed > 0) {
    printf ("***** %zu / %zu tests FAILED *****\n", nr_failed, nr_tests);
    exit (EXIT_FAILURE);
  }

  exit (EXIT_SUCCESS);
}
