/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   src/generator.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2010 Red Hat Inc.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include "guestfs.h"
#include "guestfs-internal.h"

static guestfs_h *g;
static int suppress_error = 0;

static void print_error (guestfs_h *g, void *data, const char *msg)
{
  if (!suppress_error)
    fprintf (stderr, "%s\n", msg);
}

/* FIXME: nearly identical code appears in fish.c */
static void print_strings (char *const *argv)
{
  int argc;

  for (argc = 0; argv[argc] != NULL; ++argc)
    printf ("\t%s\n", argv[argc]);
}

/*
static void print_table (char const *const *argv)
{
  int i;

  for (i = 0; argv[i] != NULL; i += 2)
    printf ("%s: %s\n", argv[i], argv[i+1]);
}
*/

static void no_test_warnings (void)
{
  fprintf (stderr, "warning: \"guestfs_test0\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rint\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rinterr\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rint64\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rint64err\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rbool\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rboolerr\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rconststring\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rconststringerr\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rconstoptstring\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rconstoptstringerr\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rstring\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rstringerr\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rstringlist\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rstringlisterr\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rstruct\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rstructerr\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rstructlist\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rstructlisterr\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rhashtable\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_test0rhashtableerr\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_launch\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_wait_ready\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_kill_subprocess\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_add_drive\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_add_cdrom\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_add_drive_ro\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_config\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_set_qemu\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_set_path\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_set_append\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_get_append\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_set_autosync\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_set_verbose\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_get_verbose\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_get_state\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_add_drive_with_if\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_add_drive_ro_with_if\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_ll\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_pvs_full\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_vgs_full\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_lvs_full\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_aug_init\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_aug_close\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_aug_defvar\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_aug_defnode\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_aug_get\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_aug_set\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_aug_insert\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_aug_rm\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_aug_mv\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_aug_match\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_aug_save\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_aug_load\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_aug_ls\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_chown\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_sfdisk\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_lvm_remove_all\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_tune2fs_l\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_blockdev_setbsz\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_tar_out\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_tgz_out\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_mount_vfs\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_debug\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_grub_install\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_pvresize\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_sfdisk_N\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_sfdisk_l\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_sfdisk_kernel_geometry\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_sfdisk_disk_geometry\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_vg_activate_all\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_sh\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_sh_lines\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_scrub_freespace\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_df\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_df_h\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_mount_loop\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_umask\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_readdir\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_zfile\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_getxattrs\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_lgetxattrs\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_setxattr\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_lsetxattr\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_removexattr\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_lremovexattr\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_mountpoints\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_mkmountpoint\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_rmmountpoint\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_inotify_rm_watch\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_inotify_read\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_inotify_close\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_setcon\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_getcon\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_find0\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_lchown\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_lstatlist\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_lxattrlist\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_readlinklist\" has no tests\n");
  fprintf (stderr, "warning: \"guestfs_part_list\" has no tests\n");
}

static int test_initrd_cat_0_skip (void)
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

static int test_initrd_cat_0 (void)
{
  if (test_initrd_cat_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_initrd_cat_0");
    return 0;
  }

  /* InitISOFS for test_initrd_cat_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_initrd_cat (g, initrdpath, filename, &size);
    if (r == NULL)
      return -1;
    if (size != 11) {
      fprintf (stderr, "test_initrd_cat_0: returned size of buffer wrong, expected 11 but got %zu\n", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "test_initrd_cat_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_vgrename_0_skip (void)
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

static int test_vgrename_0 (void)
{
  if (test_vgrename_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgrename_0");
    return 0;
  }

  /* InitBasicFSonLVM for test_vgrename_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for vgrename (0) */
  {
    const char *pathordevice = "/";
    int r;
    suppress_error = 0;
    r = guestfs_umount (g, pathordevice);
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
    suppress_error = 0;
    r = guestfs_vg_activate (g, 0, (char **) volgroups);
    if (r == -1)
      return -1;
  }
  {
    const char *volgroup = "VG";
    const char *newvolgroup = "VG2";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vg_activate (g, 1, (char **) volgroups);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/VG2/LV";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_vgrename_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG2";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_vgrename_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_vgrename_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_lvrename_0_skip (void)
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

static int test_lvrename_0 (void)
{
  if (test_lvrename_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvrename_0");
    return 0;
  }

  /* InitBasicFSonLVM for test_lvrename_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvrename (0) */
  {
    const char *logvol = "/dev/VG/LV";
    const char *newlogvol = "/dev/VG/LV2";
    int r;
    suppress_error = 0;
    r = guestfs_lvrename (g, logvol, newlogvol);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_lvrename_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG/LV2";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_lvrename_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_lvrename_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_filesize_0_skip (void)
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

static int test_filesize_0 (void)
{
  if (test_filesize_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_filesize_0");
    return 0;
  }

  /* InitBasicFS for test_filesize_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for filesize (0) */
  {
    const char *path = "/file";
    const char *content = "hello, world";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/file";
    int64_t r;
    suppress_error = 0;
    r = guestfs_filesize (g, file);
    if (r == -1)
      return -1;
    if (r != 12) {
      fprintf (stderr, "test_filesize_0: expected 12 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_dd_0_skip (void)
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

static int test_dd_0 (void)
{
  if (test_dd_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_dd_0");
    return 0;
  }

  /* InitBasicFS for test_dd_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputBuffer for dd (0) */
  const char *expected = "hello, world";
  {
    const char *path = "/src";
    const char *content = "hello, world";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/src";
    const char *dest = "/dest";
    int r;
    suppress_error = 0;
    r = guestfs_dd (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/dest";
    char *r;
    size_t size;
    suppress_error = 0;
    r = guestfs_read_file (g, path, &size);
    if (r == NULL)
      return -1;
    if (size != 12) {
      fprintf (stderr, "test_dd_0: returned size of buffer wrong, expected 12 but got %zu\n", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "test_dd_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_available_0_skip (void)
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

static int test_available_0 (void)
{
  if (test_available_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_available_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_available_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for available (0) */
  {
    const char *const groups[1] = { NULL };
    int r;
    suppress_error = 0;
    r = guestfs_available (g, (char **) groups);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_fill_0_skip (void)
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

static int test_fill_0 (void)
{
  if (test_fill_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_fill_0");
    return 0;
  }

  /* InitBasicFS for test_fill_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputBuffer for fill (0) */
  const char *expected = "cccccccccc";
  {
    const char *path = "/test";
    int r;
    suppress_error = 0;
    r = guestfs_fill (g, 99, 10, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test";
    char *r;
    size_t size;
    suppress_error = 0;
    r = guestfs_read_file (g, path, &size);
    if (r == NULL)
      return -1;
    if (size != 10) {
      fprintf (stderr, "test_fill_0: returned size of buffer wrong, expected 10 but got %zu\n", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "test_fill_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_part_get_parttype_0_skip (void)
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

static int test_part_get_parttype_0 (void)
{
  if (test_part_get_parttype_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_get_parttype_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_get_parttype_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    char *r;
    suppress_error = 0;
    r = guestfs_part_get_parttype (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_part_get_parttype_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_part_set_name_0_skip (void)
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

static int test_part_set_name_0 (void)
{
  if (test_part_set_name_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_set_name_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_set_name_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_set_name (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "gpt";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *name = "thepartname";
    int r;
    suppress_error = 0;
    r = guestfs_part_set_name (g, device, 1, name);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_part_set_bootable_0_skip (void)
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

static int test_part_set_bootable_0 (void)
{
  if (test_part_set_bootable_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_set_bootable_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_set_bootable_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_set_bootable (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_part_set_bootable (g, device, 1, 1);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_part_disk_0_skip (void)
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

static int test_part_disk_0 (void)
{
  if (test_part_disk_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_disk_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_disk_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_disk (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_part_disk_1_skip (void)
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

static int test_part_disk_1 (void)
{
  if (test_part_disk_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_disk_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_disk_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_disk (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "gpt";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_part_add_0_skip (void)
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

static int test_part_add_0 (void)
{
  if (test_part_add_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_add_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_add_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_add (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    suppress_error = 0;
    r = guestfs_part_add (g, device, prlogex, 1, -1);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_part_add_1_skip (void)
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

static int test_part_add_1 (void)
{
  if (test_part_add_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_add_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_add_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_add (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "gpt";
    int r;
    suppress_error = 0;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    suppress_error = 0;
    r = guestfs_part_add (g, device, prlogex, 34, 127);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    suppress_error = 0;
    r = guestfs_part_add (g, device, prlogex, 128, -34);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_part_add_2_skip (void)
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

static int test_part_add_2 (void)
{
  if (test_part_add_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_add_2");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_add_2 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_add (2) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    suppress_error = 0;
    r = guestfs_part_add (g, device, prlogex, 32, 127);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    suppress_error = 0;
    r = guestfs_part_add (g, device, prlogex, 128, 255);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    suppress_error = 0;
    r = guestfs_part_add (g, device, prlogex, 256, 511);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *prlogex = "primary";
    int r;
    suppress_error = 0;
    r = guestfs_part_add (g, device, prlogex, 512, -1);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_part_init_0_skip (void)
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

static int test_part_init_0 (void)
{
  if (test_part_init_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_part_init_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_part_init_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for part_init (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "gpt";
    int r;
    suppress_error = 0;
    r = guestfs_part_init (g, device, parttype);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_pread_0_skip (void)
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

static int test_pread_0 (void)
{
  if (test_pread_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_pread_0");
    return 0;
  }

  /* InitISOFS for test_pread_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_pread (g, path, 1, 3, &size);
    if (r == NULL)
      return -1;
    if (size != 1) {
      fprintf (stderr, "test_pread_0: returned size of buffer wrong, expected 1 but got %zu\n", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "test_pread_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_pread_1_skip (void)
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

static int test_pread_1 (void)
{
  if (test_pread_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_pread_1");
    return 0;
  }

  /* InitISOFS for test_pread_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_pread (g, path, 0, 100, &size);
    if (r == NULL)
      return -1;
    if (size != 0) {
      fprintf (stderr, "test_pread_1: returned size of buffer wrong, expected 0 but got %zu\n", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "test_pread_1: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_mkdir_mode_0_skip (void)
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

static int test_mkdir_mode_0 (void)
{
  if (test_mkdir_mode_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_mode_0");
    return 0;
  }

  /* InitBasicFS for test_mkdir_mode_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for mkdir_mode (0) */
  {
    const char *path = "/test";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir_mode (g, path, 73);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 16457) {
      fprintf (stderr, "test_mkdir_mode_0: mode was %d, expected 16457\n",
               (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_utimens_0_skip (void)
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

static int test_utimens_0 (void)
{
  if (test_utimens_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_utimens_0");
    return 0;
  }

  /* InitBasicFS for test_utimens_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for utimens (0) */
  {
    const char *path = "/test";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test";
    int r;
    suppress_error = 0;
    r = guestfs_utimens (g, path, 12345, 67890, 9876, 5432);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mtime != 9876) {
      fprintf (stderr, "test_utimens_0: mtime was %d, expected 9876\n",
               (int) r->mtime);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_truncate_size_0_skip (void)
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

static int test_truncate_size_0 (void)
{
  if (test_truncate_size_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_truncate_size_0");
    return 0;
  }

  /* InitBasicFS for test_truncate_size_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for truncate_size (0) */
  {
    const char *path = "/test";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test";
    int r;
    suppress_error = 0;
    r = guestfs_truncate_size (g, path, 1000);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->size != 1000) {
      fprintf (stderr, "test_truncate_size_0: size was %d, expected 1000\n",
               (int) r->size);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_truncate_0_skip (void)
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

static int test_truncate_0 (void)
{
  if (test_truncate_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_truncate_0");
    return 0;
  }

  /* InitBasicFS for test_truncate_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for truncate (0) */
  {
    const char *path = "/test";
    const char *content = "some stuff so size is not zero";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test";
    int r;
    suppress_error = 0;
    r = guestfs_truncate (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->size != 0) {
      fprintf (stderr, "test_truncate_0: size was %d, expected 0\n",
               (int) r->size);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_vfs_type_0_skip (void)
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

static int test_vfs_type_0 (void)
{
  if (test_vfs_type_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_vfs_type_0");
    return 0;
  }

  /* InitBasicFS for test_vfs_type_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for vfs_type (0) */
  const char *expected = "ext2";
  {
    const char *device = "/dev/sda1";
    char *r;
    suppress_error = 0;
    r = guestfs_vfs_type (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_vfs_type_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_case_sensitive_path_0_skip (void)
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

static int test_case_sensitive_path_0 (void)
{
  if (test_case_sensitive_path_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_0");
    return 0;
  }

  /* InitISOFS for test_case_sensitive_path_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for case_sensitive_path (0) */
  const char *expected = "/directory";
  {
    const char *path = "/DIRECTORY";
    char *r;
    suppress_error = 0;
    r = guestfs_case_sensitive_path (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_case_sensitive_path_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_case_sensitive_path_1_skip (void)
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

static int test_case_sensitive_path_1 (void)
{
  if (test_case_sensitive_path_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_1");
    return 0;
  }

  /* InitISOFS for test_case_sensitive_path_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for case_sensitive_path (1) */
  const char *expected = "/directory";
  {
    const char *path = "/DIRECTORY/";
    char *r;
    suppress_error = 0;
    r = guestfs_case_sensitive_path (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_case_sensitive_path_1: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_case_sensitive_path_2_skip (void)
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

static int test_case_sensitive_path_2 (void)
{
  if (test_case_sensitive_path_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_2");
    return 0;
  }

  /* InitISOFS for test_case_sensitive_path_2 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for case_sensitive_path (2) */
  const char *expected = "/known-1";
  {
    const char *path = "/Known-1";
    char *r;
    suppress_error = 0;
    r = guestfs_case_sensitive_path (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_case_sensitive_path_2: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_case_sensitive_path_3_skip (void)
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

static int test_case_sensitive_path_3 (void)
{
  if (test_case_sensitive_path_3_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_3");
    return 0;
  }

  /* InitISOFS for test_case_sensitive_path_3 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for case_sensitive_path (3) */
  {
    const char *path = "/Known-1/";
    char *r;
    suppress_error = 1;
    r = guestfs_case_sensitive_path (g, path);
    if (r != NULL)
      return -1;
    free (r);
  }
  return 0;
}

static int test_case_sensitive_path_4_skip (void)
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

static int test_case_sensitive_path_4 (void)
{
  if (test_case_sensitive_path_4_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_4");
    return 0;
  }

  /* InitBasicFS for test_case_sensitive_path_4: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for case_sensitive_path (4) */
  const char *expected = "/a/bbb/c";
  {
    const char *path = "/a";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/bbb";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/bbb/c";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/A/bbB/C";
    char *r;
    suppress_error = 0;
    r = guestfs_case_sensitive_path (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_case_sensitive_path_4: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_case_sensitive_path_5_skip (void)
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

static int test_case_sensitive_path_5 (void)
{
  if (test_case_sensitive_path_5_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_5");
    return 0;
  }

  /* InitBasicFS for test_case_sensitive_path_5: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for case_sensitive_path (5) */
  const char *expected = "/a/bbb/c";
  {
    const char *path = "/a";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/bbb";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/bbb/c";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/A////bbB/C";
    char *r;
    suppress_error = 0;
    r = guestfs_case_sensitive_path (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_case_sensitive_path_5: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_case_sensitive_path_6_skip (void)
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

static int test_case_sensitive_path_6 (void)
{
  if (test_case_sensitive_path_6_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_case_sensitive_path_6");
    return 0;
  }

  /* InitBasicFS for test_case_sensitive_path_6: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for case_sensitive_path (6) */
  {
    const char *path = "/a";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/bbb";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/bbb/c";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/A/bbb/../bbb/C";
    char *r;
    suppress_error = 1;
    r = guestfs_case_sensitive_path (g, path);
    if (r != NULL)
      return -1;
    free (r);
  }
  return 0;
}

static int test_echo_daemon_0_skip (void)
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

static int test_echo_daemon_0 (void)
{
  if (test_echo_daemon_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_echo_daemon_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_echo_daemon_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_echo_daemon (g, (char **) words);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_echo_daemon_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_modprobe_0_skip (void)
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

static int test_modprobe_0 (void)
{
  if (test_modprobe_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_modprobe_0");
    return 0;
  }

  {
    const char *groups[] = { "linuxmodules", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_modprobe_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_modprobe_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for modprobe (0) */
  {
    const char *modulename = "fat";
    int r;
    suppress_error = 0;
    r = guestfs_modprobe (g, modulename);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_mke2journal_U_0_skip (void)
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

static int test_mke2journal_U_0 (void)
{
  if (test_mke2journal_U_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mke2journal_U_0");
    return 0;
  }

  {
    const char *groups[] = { "linuxfsuuid", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mke2journal_U_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_mke2journal_U_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mke2journal_U (0) */
  const char *expected = "new file contents";
  {
    const char *device = "/dev/sda";
    const char *lines_0 = ",100";
    const char *lines_1 = ",";
    const char *const lines[] = {
      lines_0,
      lines_1,
      NULL
    };
    int r;
    suppress_error = 0;
    r = guestfs_sfdiskM (g, device, (char **) lines);
    if (r == -1)
      return -1;
  }
  {
    const char *uuid = "7745de3f-b9f6-4b1d-9362-6510fd834c84";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mke2journal_U (g, 4096, uuid, device);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda2";
    const char *uuid = "7745de3f-b9f6-4b1d-9362-6510fd834c84";
    int r;
    suppress_error = 0;
    r = guestfs_mke2fs_JU (g, fstype, 4096, device, uuid);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda2";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_mke2journal_U_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_mke2journal_L_0_skip (void)
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

static int test_mke2journal_L_0 (void)
{
  if (test_mke2journal_L_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mke2journal_L_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mke2journal_L_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mke2journal_L (0) */
  const char *expected = "new file contents";
  {
    const char *device = "/dev/sda";
    const char *lines_0 = ",100";
    const char *lines_1 = ",";
    const char *const lines[] = {
      lines_0,
      lines_1,
      NULL
    };
    int r;
    suppress_error = 0;
    r = guestfs_sfdiskM (g, device, (char **) lines);
    if (r == -1)
      return -1;
  }
  {
    const char *label = "JOURNAL";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mke2journal_L (g, 4096, label, device);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda2";
    const char *label = "JOURNAL";
    int r;
    suppress_error = 0;
    r = guestfs_mke2fs_JL (g, fstype, 4096, device, label);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda2";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_mke2journal_L_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_mke2journal_0_skip (void)
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

static int test_mke2journal_0 (void)
{
  if (test_mke2journal_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mke2journal_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mke2journal_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mke2journal (0) */
  const char *expected = "new file contents";
  {
    const char *device = "/dev/sda";
    const char *lines_0 = ",100";
    const char *lines_1 = ",";
    const char *const lines[] = {
      lines_0,
      lines_1,
      NULL
    };
    int r;
    suppress_error = 0;
    r = guestfs_sfdiskM (g, device, (char **) lines);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mke2journal (g, 4096, device);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda2";
    const char *journal = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mke2fs_J (g, fstype, 4096, device, journal);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda2";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_mke2journal_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_mkfs_b_0_skip (void)
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

static int test_mkfs_b_0 (void)
{
  if (test_mkfs_b_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkfs_b_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_b_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs_b (g, fstype, 4096, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_mkfs_b_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_inotify_add_watch_0_skip (void)
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

static int test_inotify_add_watch_0 (void)
{
  if (test_inotify_add_watch_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_inotify_add_watch_0");
    return 0;
  }

  {
    const char *groups[] = { "inotify", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_inotify_add_watch_0", groups[0]);
      return 0;
    }
  }
  /* InitBasicFS for test_inotify_add_watch_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for inotify_add_watch (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_inotify_init (g, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/";
    int64_t r;
    suppress_error = 0;
    r = guestfs_inotify_add_watch (g, path, 1073741823);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/b";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_inotify_files (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_inotify_add_watch_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "a";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_inotify_add_watch_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_inotify_add_watch_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "b";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_inotify_add_watch_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_inotify_add_watch_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_inotify_init_0_skip (void)
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

static int test_inotify_init_0 (void)
{
  if (test_inotify_init_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_inotify_init_0");
    return 0;
  }

  {
    const char *groups[] = { "inotify", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_inotify_init_0", groups[0]);
      return 0;
    }
  }
  /* InitISOFS for test_inotify_init_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for inotify_init (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_inotify_init (g, 0);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_mkswap_file_0_skip (void)
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

static int test_mkswap_file_0 (void)
{
  if (test_mkswap_file_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkswap_file_0");
    return 0;
  }

  /* InitBasicFS for test_mkswap_file_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkswap_file (0) */
  {
    const char *path = "/swap";
    int r;
    suppress_error = 0;
    r = guestfs_fallocate (g, path, 8388608);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/swap";
    int r;
    suppress_error = 0;
    r = guestfs_mkswap_file (g, path);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_swapon_uuid_0_skip (void)
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

static int test_swapon_uuid_0 (void)
{
  if (test_swapon_uuid_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_swapon_uuid_0");
    return 0;
  }

  {
    const char *groups[] = { "linuxfsuuid", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_swapon_uuid_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_swapon_uuid_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for swapon_uuid (0) */
  {
    const char *uuid = "8111429b-ac33-4c0c-9ceb-9e0954005fda";
    const char *device = "/dev/sdb";
    int r;
    suppress_error = 0;
    r = guestfs_mkswap_U (g, uuid, device);
    if (r == -1)
      return -1;
  }
  {
    const char *uuid = "8111429b-ac33-4c0c-9ceb-9e0954005fda";
    int r;
    suppress_error = 0;
    r = guestfs_swapon_uuid (g, uuid);
    if (r == -1)
      return -1;
  }
  {
    const char *uuid = "8111429b-ac33-4c0c-9ceb-9e0954005fda";
    int r;
    suppress_error = 0;
    r = guestfs_swapoff_uuid (g, uuid);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_swapon_label_0_skip (void)
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

static int test_swapon_label_0 (void)
{
  if (test_swapon_label_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_swapon_label_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_swapon_label_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for swapon_label (0) */
  {
    const char *device = "/dev/sdb";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *label = "swapit";
    const char *device = "/dev/sdb1";
    int r;
    suppress_error = 0;
    r = guestfs_mkswap_L (g, label, device);
    if (r == -1)
      return -1;
  }
  {
    const char *label = "swapit";
    int r;
    suppress_error = 0;
    r = guestfs_swapon_label (g, label);
    if (r == -1)
      return -1;
  }
  {
    const char *label = "swapit";
    int r;
    suppress_error = 0;
    r = guestfs_swapoff_label (g, label);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb";
    int r;
    suppress_error = 0;
    r = guestfs_zero (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdb";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_rereadpt (g, device);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_swapon_file_0_skip (void)
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

static int test_swapon_file_0 (void)
{
  if (test_swapon_file_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_swapon_file_0");
    return 0;
  }

  /* InitBasicFS for test_swapon_file_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for swapon_file (0) */
  {
    const char *path = "/swap";
    int r;
    suppress_error = 0;
    r = guestfs_fallocate (g, path, 8388608);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/swap";
    int r;
    suppress_error = 0;
    r = guestfs_mkswap_file (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/swap";
    int r;
    suppress_error = 0;
    r = guestfs_swapon_file (g, file);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/swap";
    int r;
    suppress_error = 0;
    r = guestfs_swapoff_file (g, file);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_swapon_device_0_skip (void)
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

static int test_swapon_device_0 (void)
{
  if (test_swapon_device_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_swapon_device_0");
    return 0;
  }

  /* InitPartition for test_swapon_device_0: create /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  /* TestRun for swapon_device (0) */
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkswap (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_swapon_device (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_swapoff_device (g, device);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_fallocate_0_skip (void)
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

static int test_fallocate_0 (void)
{
  if (test_fallocate_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_fallocate_0");
    return 0;
  }

  /* InitBasicFS for test_fallocate_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for fallocate (0) */
  {
    const char *path = "/a";
    int r;
    suppress_error = 0;
    r = guestfs_fallocate (g, path, 1000000);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->size != 1000000) {
      fprintf (stderr, "test_fallocate_0: size was %d, expected 1000000\n",
               (int) r->size);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_ln_sf_0_skip (void)
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

static int test_ln_sf_0 (void)
{
  if (test_ln_sf_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_ln_sf_0");
    return 0;
  }

  /* InitBasicFS for test_ln_sf_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for ln_sf (0) */
  const char *expected = "../d";
  {
    const char *path = "/a/b";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/b/c";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *target = "../d";
    const char *linkname = "/a/b/c";
    int r;
    suppress_error = 0;
    r = guestfs_ln_sf (g, target, linkname);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/b/c";
    char *r;
    suppress_error = 0;
    r = guestfs_readlink (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_ln_sf_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_ln_s_0_skip (void)
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

static int test_ln_s_0 (void)
{
  if (test_ln_s_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_ln_s_0");
    return 0;
  }

  /* InitBasicFS for test_ln_s_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for ln_s (0) */
  {
    const char *path = "/a";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *target = "a";
    const char *linkname = "/b";
    int r;
    suppress_error = 0;
    r = guestfs_ln_s (g, target, linkname);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/b";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_lstat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 41471) {
      fprintf (stderr, "test_ln_s_0: mode was %d, expected 41471\n",
               (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_ln_f_0_skip (void)
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

static int test_ln_f_0 (void)
{
  if (test_ln_f_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_ln_f_0");
    return 0;
  }

  /* InitBasicFS for test_ln_f_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for ln_f (0) */
  {
    const char *path = "/a";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/b";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *target = "/a";
    const char *linkname = "/b";
    int r;
    suppress_error = 0;
    r = guestfs_ln_f (g, target, linkname);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/b";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->nlink != 2) {
      fprintf (stderr, "test_ln_f_0: nlink was %d, expected 2\n",
               (int) r->nlink);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_ln_0_skip (void)
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

static int test_ln_0 (void)
{
  if (test_ln_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_ln_0");
    return 0;
  }

  /* InitBasicFS for test_ln_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for ln (0) */
  {
    const char *path = "/a";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *target = "/a";
    const char *linkname = "/b";
    int r;
    suppress_error = 0;
    r = guestfs_ln (g, target, linkname);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/b";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->nlink != 2) {
      fprintf (stderr, "test_ln_0: nlink was %d, expected 2\n",
               (int) r->nlink);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_realpath_0_skip (void)
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

static int test_realpath_0 (void)
{
  if (test_realpath_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_realpath_0");
    return 0;
  }

  {
    const char *groups[] = { "realpath", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_realpath_0", groups[0]);
      return 0;
    }
  }
  /* InitISOFS for test_realpath_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for realpath (0) */
  const char *expected = "/directory";
  {
    const char *path = "/../directory";
    char *r;
    suppress_error = 0;
    r = guestfs_realpath (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_realpath_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_zfgrepi_0_skip (void)
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

static int test_zfgrepi_0 (void)
{
  if (test_zfgrepi_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_zfgrepi_0");
    return 0;
  }

  /* InitISOFS for test_zfgrepi_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for zfgrepi (0) */
  {
    const char *pattern = "abc";
    const char *path = "/test-grep.txt.gz";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_zfgrepi (g, pattern, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_zfgrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_zfgrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_zfgrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_zfgrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_zfgrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_zfgrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_zfgrepi_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_zegrepi_0_skip (void)
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

static int test_zegrepi_0 (void)
{
  if (test_zegrepi_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_zegrepi_0");
    return 0;
  }

  /* InitISOFS for test_zegrepi_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for zegrepi (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_zegrepi (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_zegrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_zegrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_zegrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_zegrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_zegrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_zegrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_zegrepi_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_zgrepi_0_skip (void)
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

static int test_zgrepi_0 (void)
{
  if (test_zgrepi_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_zgrepi_0");
    return 0;
  }

  /* InitISOFS for test_zgrepi_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for zgrepi (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_zgrepi (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_zgrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_zgrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_zgrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_zgrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_zgrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_zgrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_zgrepi_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_zfgrep_0_skip (void)
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

static int test_zfgrep_0 (void)
{
  if (test_zfgrep_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_zfgrep_0");
    return 0;
  }

  /* InitISOFS for test_zfgrep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for zfgrep (0) */
  {
    const char *pattern = "abc";
    const char *path = "/test-grep.txt.gz";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_zfgrep (g, pattern, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_zfgrep_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_zfgrep_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_zfgrep_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_zfgrep_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_zfgrep_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_zegrep_0_skip (void)
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

static int test_zegrep_0 (void)
{
  if (test_zegrep_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_zegrep_0");
    return 0;
  }

  /* InitISOFS for test_zegrep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for zegrep (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_zegrep (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_zegrep_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_zegrep_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_zegrep_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_zegrep_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_zegrep_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_zgrep_0_skip (void)
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

static int test_zgrep_0 (void)
{
  if (test_zgrep_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_zgrep_0");
    return 0;
  }

  /* InitISOFS for test_zgrep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for zgrep (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt.gz";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_zgrep (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_zgrep_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_zgrep_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_zgrep_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_zgrep_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_zgrep_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_fgrepi_0_skip (void)
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

static int test_fgrepi_0 (void)
{
  if (test_fgrepi_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_fgrepi_0");
    return 0;
  }

  /* InitISOFS for test_fgrepi_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for fgrepi (0) */
  {
    const char *pattern = "abc";
    const char *path = "/test-grep.txt";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_fgrepi (g, pattern, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_fgrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_fgrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_fgrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_fgrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_fgrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_fgrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_fgrepi_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_egrepi_0_skip (void)
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

static int test_egrepi_0 (void)
{
  if (test_egrepi_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_egrepi_0");
    return 0;
  }

  /* InitISOFS for test_egrepi_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for egrepi (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_egrepi (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_egrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_egrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_egrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_egrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_egrepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_egrepi_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_egrepi_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_grepi_0_skip (void)
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

static int test_grepi_0 (void)
{
  if (test_grepi_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_grepi_0");
    return 0;
  }

  /* InitISOFS for test_grepi_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grepi (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_grepi (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_grepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_grepi_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_grepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_grepi_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_grepi_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ABC";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_grepi_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_grepi_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_fgrep_0_skip (void)
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

static int test_fgrep_0 (void)
{
  if (test_fgrep_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_fgrep_0");
    return 0;
  }

  /* InitISOFS for test_fgrep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for fgrep (0) */
  {
    const char *pattern = "abc";
    const char *path = "/test-grep.txt";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_fgrep (g, pattern, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_fgrep_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_fgrep_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_fgrep_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_fgrep_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_fgrep_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_egrep_0_skip (void)
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

static int test_egrep_0 (void)
{
  if (test_egrep_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_egrep_0");
    return 0;
  }

  /* InitISOFS for test_egrep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for egrep (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_egrep (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_egrep_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_egrep_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_egrep_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_egrep_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_egrep_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_grep_0_skip (void)
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

static int test_grep_0 (void)
{
  if (test_grep_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_0");
    return 0;
  }

  /* InitISOFS for test_grep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (0) */
  {
    const char *regex = "abc";
    const char *path = "/test-grep.txt";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_grep (g, regex, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_grep_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_grep_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_grep_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc123";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_grep_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_grep_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_grep_1_skip (void)
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

static int test_grep_1 (void)
{
  if (test_grep_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_grep_1");
    return 0;
  }

  /* InitISOFS for test_grep_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for grep (1) */
  {
    const char *regex = "nomatch";
    const char *path = "/test-grep.txt";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_grep (g, regex, path);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_grep_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_read_file_0_skip (void)
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

static int test_read_file_0 (void)
{
  if (test_read_file_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_file_0");
    return 0;
  }

  /* InitISOFS for test_read_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_read_file (g, path, &size);
    if (r == NULL)
      return -1;
    if (size != 11) {
      fprintf (stderr, "test_read_file_0: returned size of buffer wrong, expected 11 but got %zu\n", size);
      return -1;
    }
    if (STRNEQLEN (r, expected, size)) {
      fprintf (stderr, "test_read_file_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_mknod_c_0_skip (void)
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

static int test_mknod_c_0 (void)
{
  if (test_mknod_c_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mknod_c_0");
    return 0;
  }

  {
    const char *groups[] = { "mknod", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mknod_c_0", groups[0]);
      return 0;
    }
  }
  /* InitBasicFS for test_mknod_c_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for mknod_c (0) */
  {
    const char *path = "/node";
    int r;
    suppress_error = 0;
    r = guestfs_mknod_c (g, 511, 99, 66, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/node";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 8685) {
      fprintf (stderr, "test_mknod_c_0: mode was %d, expected 8685\n",
               (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_mknod_b_0_skip (void)
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

static int test_mknod_b_0 (void)
{
  if (test_mknod_b_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mknod_b_0");
    return 0;
  }

  {
    const char *groups[] = { "mknod", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mknod_b_0", groups[0]);
      return 0;
    }
  }
  /* InitBasicFS for test_mknod_b_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for mknod_b (0) */
  {
    const char *path = "/node";
    int r;
    suppress_error = 0;
    r = guestfs_mknod_b (g, 511, 99, 66, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/node";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 25069) {
      fprintf (stderr, "test_mknod_b_0: mode was %d, expected 25069\n",
               (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_mkfifo_0_skip (void)
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

static int test_mkfifo_0 (void)
{
  if (test_mkfifo_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkfifo_0");
    return 0;
  }

  {
    const char *groups[] = { "mknod", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mkfifo_0", groups[0]);
      return 0;
    }
  }
  /* InitBasicFS for test_mkfifo_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for mkfifo (0) */
  {
    const char *path = "/node";
    int r;
    suppress_error = 0;
    r = guestfs_mkfifo (g, 511, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/node";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 4589) {
      fprintf (stderr, "test_mkfifo_0: mode was %d, expected 4589\n",
               (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_mknod_0_skip (void)
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

static int test_mknod_0 (void)
{
  if (test_mknod_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mknod_0");
    return 0;
  }

  {
    const char *groups[] = { "mknod", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mknod_0", groups[0]);
      return 0;
    }
  }
  /* InitBasicFS for test_mknod_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for mknod (0) */
  {
    const char *path = "/node";
    int r;
    suppress_error = 0;
    r = guestfs_mknod (g, 4607, 0, 0, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/node";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 4589) {
      fprintf (stderr, "test_mknod_0: mode was %d, expected 4589\n",
               (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_mknod_1_skip (void)
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

static int test_mknod_1 (void)
{
  if (test_mknod_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mknod_1");
    return 0;
  }

  {
    const char *groups[] = { "mknod", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mknod_1", groups[0]);
      return 0;
    }
  }
  /* InitBasicFS for test_mknod_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for mknod (1) */
  {
    const char *path = "/node";
    int r;
    suppress_error = 0;
    r = guestfs_mknod (g, 25087, 66, 99, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/node";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->mode != 25069) {
      fprintf (stderr, "test_mknod_1: mode was %d, expected 25069\n",
               (int) r->mode);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_mkswap_U_0_skip (void)
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

static int test_mkswap_U_0 (void)
{
  if (test_mkswap_U_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkswap_U_0");
    return 0;
  }

  {
    const char *groups[] = { "linuxfsuuid", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_mkswap_U_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_mkswap_U_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkswap_U (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *uuid = "0e99673a-04f9-4d08-b10c-9ca1b114818a";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkswap_U (g, uuid, device);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_mkswap_L_0_skip (void)
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

static int test_mkswap_L_0 (void)
{
  if (test_mkswap_L_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkswap_L_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkswap_L_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkswap_L (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *label = "hello";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkswap_L (g, label, device);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_mkswap_0_skip (void)
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

static int test_mkswap_0 (void)
{
  if (test_mkswap_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkswap_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkswap_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkswap (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkswap (g, device);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_initrd_list_0_skip (void)
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

static int test_initrd_list_0 (void)
{
  if (test_initrd_list_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_initrd_list_0");
    return 0;
  }

  /* InitISOFS for test_initrd_list_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for initrd_list (0) */
  {
    const char *path = "/initrd";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_initrd_list (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_initrd_list_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "empty";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_initrd_list_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_initrd_list_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "known-1";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_initrd_list_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_initrd_list_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "known-2";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_initrd_list_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "test_initrd_list_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "known-3";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "test_initrd_list_0: expected \"%s\" but got \"%s\"\n", expected, r[3]);
        return -1;
      }
    }
    if (!r[4]) {
      fprintf (stderr, "test_initrd_list_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "known-4";
      if (STRNEQ (r[4], expected)) {
        fprintf (stderr, "test_initrd_list_0: expected \"%s\" but got \"%s\"\n", expected, r[4]);
        return -1;
      }
    }
    if (!r[5]) {
      fprintf (stderr, "test_initrd_list_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "known-5";
      if (STRNEQ (r[5], expected)) {
        fprintf (stderr, "test_initrd_list_0: expected \"%s\" but got \"%s\"\n", expected, r[5]);
        return -1;
      }
    }
    if (r[6] != NULL) {
      fprintf (stderr, "test_initrd_list_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_du_0_skip (void)
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

static int test_du_0 (void)
{
  if (test_du_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_du_0");
    return 0;
  }

  /* InitISOFS for test_du_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for du (0) */
  {
    const char *path = "/directory";
    int64_t r;
    suppress_error = 0;
    r = guestfs_du (g, path);
    if (r == -1)
      return -1;
    if (r != 2) {
      fprintf (stderr, "test_du_0: expected 2 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_tail_n_0_skip (void)
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

static int test_tail_n_0 (void)
{
  if (test_tail_n_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_tail_n_0");
    return 0;
  }

  /* InitISOFS for test_tail_n_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for tail_n (0) */
  {
    const char *path = "/10klines";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_tail_n (g, 3, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_tail_n_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9997abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_tail_n_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_tail_n_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9998abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_tail_n_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_tail_n_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9999abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_tail_n_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_tail_n_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_tail_n_1_skip (void)
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

static int test_tail_n_1 (void)
{
  if (test_tail_n_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_tail_n_1");
    return 0;
  }

  /* InitISOFS for test_tail_n_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for tail_n (1) */
  {
    const char *path = "/10klines";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_tail_n (g, -9998, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_tail_n_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9997abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_tail_n_1: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_tail_n_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9998abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_tail_n_1: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_tail_n_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9999abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_tail_n_1: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_tail_n_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_tail_n_2_skip (void)
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

static int test_tail_n_2 (void)
{
  if (test_tail_n_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_tail_n_2");
    return 0;
  }

  /* InitISOFS for test_tail_n_2 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for tail_n (2) */
  {
    const char *path = "/10klines";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_tail_n (g, 0, path);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_tail_n_2: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_tail_0_skip (void)
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

static int test_tail_0 (void)
{
  if (test_tail_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_tail_0");
    return 0;
  }

  /* InitISOFS for test_tail_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for tail (0) */
  {
    const char *path = "/10klines";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_tail (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_tail_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9990abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_tail_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_tail_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9991abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_tail_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_tail_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9992abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_tail_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "test_tail_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9993abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "test_tail_0: expected \"%s\" but got \"%s\"\n", expected, r[3]);
        return -1;
      }
    }
    if (!r[4]) {
      fprintf (stderr, "test_tail_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9994abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[4], expected)) {
        fprintf (stderr, "test_tail_0: expected \"%s\" but got \"%s\"\n", expected, r[4]);
        return -1;
      }
    }
    if (!r[5]) {
      fprintf (stderr, "test_tail_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9995abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[5], expected)) {
        fprintf (stderr, "test_tail_0: expected \"%s\" but got \"%s\"\n", expected, r[5]);
        return -1;
      }
    }
    if (!r[6]) {
      fprintf (stderr, "test_tail_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9996abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[6], expected)) {
        fprintf (stderr, "test_tail_0: expected \"%s\" but got \"%s\"\n", expected, r[6]);
        return -1;
      }
    }
    if (!r[7]) {
      fprintf (stderr, "test_tail_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9997abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[7], expected)) {
        fprintf (stderr, "test_tail_0: expected \"%s\" but got \"%s\"\n", expected, r[7]);
        return -1;
      }
    }
    if (!r[8]) {
      fprintf (stderr, "test_tail_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9998abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[8], expected)) {
        fprintf (stderr, "test_tail_0: expected \"%s\" but got \"%s\"\n", expected, r[8]);
        return -1;
      }
    }
    if (!r[9]) {
      fprintf (stderr, "test_tail_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9999abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[9], expected)) {
        fprintf (stderr, "test_tail_0: expected \"%s\" but got \"%s\"\n", expected, r[9]);
        return -1;
      }
    }
    if (r[10] != NULL) {
      fprintf (stderr, "test_tail_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_head_n_0_skip (void)
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

static int test_head_n_0 (void)
{
  if (test_head_n_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_head_n_0");
    return 0;
  }

  /* InitISOFS for test_head_n_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for head_n (0) */
  {
    const char *path = "/10klines";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_head_n (g, 3, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_head_n_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "0abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_head_n_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_head_n_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "1abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_head_n_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_head_n_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "2abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_head_n_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_head_n_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_head_n_1_skip (void)
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

static int test_head_n_1 (void)
{
  if (test_head_n_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_head_n_1");
    return 0;
  }

  /* InitISOFS for test_head_n_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for head_n (1) */
  {
    const char *path = "/10klines";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_head_n (g, -9997, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_head_n_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "0abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_head_n_1: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_head_n_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "1abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_head_n_1: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_head_n_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "2abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_head_n_1: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_head_n_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_head_n_2_skip (void)
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

static int test_head_n_2 (void)
{
  if (test_head_n_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_head_n_2");
    return 0;
  }

  /* InitISOFS for test_head_n_2 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for head_n (2) */
  {
    const char *path = "/10klines";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_head_n (g, 0, path);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_head_n_2: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_head_0_skip (void)
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

static int test_head_0 (void)
{
  if (test_head_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_head_0");
    return 0;
  }

  /* InitISOFS for test_head_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for head (0) */
  {
    const char *path = "/10klines";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_head (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_head_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "0abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_head_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_head_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "1abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_head_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_head_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "2abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_head_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "test_head_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "3abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "test_head_0: expected \"%s\" but got \"%s\"\n", expected, r[3]);
        return -1;
      }
    }
    if (!r[4]) {
      fprintf (stderr, "test_head_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "4abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[4], expected)) {
        fprintf (stderr, "test_head_0: expected \"%s\" but got \"%s\"\n", expected, r[4]);
        return -1;
      }
    }
    if (!r[5]) {
      fprintf (stderr, "test_head_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "5abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[5], expected)) {
        fprintf (stderr, "test_head_0: expected \"%s\" but got \"%s\"\n", expected, r[5]);
        return -1;
      }
    }
    if (!r[6]) {
      fprintf (stderr, "test_head_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "6abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[6], expected)) {
        fprintf (stderr, "test_head_0: expected \"%s\" but got \"%s\"\n", expected, r[6]);
        return -1;
      }
    }
    if (!r[7]) {
      fprintf (stderr, "test_head_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "7abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[7], expected)) {
        fprintf (stderr, "test_head_0: expected \"%s\" but got \"%s\"\n", expected, r[7]);
        return -1;
      }
    }
    if (!r[8]) {
      fprintf (stderr, "test_head_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "8abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[8], expected)) {
        fprintf (stderr, "test_head_0: expected \"%s\" but got \"%s\"\n", expected, r[8]);
        return -1;
      }
    }
    if (!r[9]) {
      fprintf (stderr, "test_head_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "9abcdefghijklmnopqrstuvwxyz";
      if (STRNEQ (r[9], expected)) {
        fprintf (stderr, "test_head_0: expected \"%s\" but got \"%s\"\n", expected, r[9]);
        return -1;
      }
    }
    if (r[10] != NULL) {
      fprintf (stderr, "test_head_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_wc_c_0_skip (void)
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

static int test_wc_c_0 (void)
{
  if (test_wc_c_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_wc_c_0");
    return 0;
  }

  /* InitISOFS for test_wc_c_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for wc_c (0) */
  {
    const char *path = "/100kallspaces";
    int r;
    suppress_error = 0;
    r = guestfs_wc_c (g, path);
    if (r == -1)
      return -1;
    if (r != 102400) {
      fprintf (stderr, "test_wc_c_0: expected 102400 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_wc_w_0_skip (void)
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

static int test_wc_w_0 (void)
{
  if (test_wc_w_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_wc_w_0");
    return 0;
  }

  /* InitISOFS for test_wc_w_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for wc_w (0) */
  {
    const char *path = "/10klines";
    int r;
    suppress_error = 0;
    r = guestfs_wc_w (g, path);
    if (r == -1)
      return -1;
    if (r != 10000) {
      fprintf (stderr, "test_wc_w_0: expected 10000 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_wc_l_0_skip (void)
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

static int test_wc_l_0 (void)
{
  if (test_wc_l_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_wc_l_0");
    return 0;
  }

  /* InitISOFS for test_wc_l_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for wc_l (0) */
  {
    const char *path = "/10klines";
    int r;
    suppress_error = 0;
    r = guestfs_wc_l (g, path);
    if (r == -1)
      return -1;
    if (r != 10000) {
      fprintf (stderr, "test_wc_l_0: expected 10000 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_mkdtemp_0_skip (void)
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

static int test_mkdtemp_0 (void)
{
  if (test_mkdtemp_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdtemp_0");
    return 0;
  }

  /* InitBasicFS for test_mkdtemp_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkdtemp (0) */
  {
    const char *path = "/tmp";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *template = "/tmp/tmpXXXXXX";
    char *r;
    suppress_error = 0;
    r = guestfs_mkdtemp (g, template);
    if (r == NULL)
      return -1;
    free (r);
  }
  return 0;
}

static int test_scrub_file_0_skip (void)
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

static int test_scrub_file_0 (void)
{
  if (test_scrub_file_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_scrub_file_0");
    return 0;
  }

  {
    const char *groups[] = { "scrub", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_scrub_file_0", groups[0]);
      return 0;
    }
  }
  /* InitBasicFS for test_scrub_file_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for scrub_file (0) */
  {
    const char *path = "/file";
    const char *content = "content";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *file = "/file";
    int r;
    suppress_error = 0;
    r = guestfs_scrub_file (g, file);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_scrub_device_0_skip (void)
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

static int test_scrub_device_0 (void)
{
  if (test_scrub_device_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_scrub_device_0");
    return 0;
  }

  {
    const char *groups[] = { "scrub", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_scrub_device_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_scrub_device_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for scrub_device (0) */
  {
    const char *device = "/dev/sdc";
    int r;
    suppress_error = 0;
    r = guestfs_scrub_device (g, device);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_glob_expand_0_skip (void)
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

static int test_glob_expand_0 (void)
{
  if (test_glob_expand_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_glob_expand_0");
    return 0;
  }

  /* InitBasicFS for test_glob_expand_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for glob_expand (0) */
  {
    const char *path = "/a/b/c";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/b/c/d";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/b/c/e";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *pattern = "/a/b/c/*";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_glob_expand (g, pattern);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_glob_expand_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/a/b/c/d";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_glob_expand_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_glob_expand_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/a/b/c/e";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_glob_expand_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_glob_expand_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_glob_expand_1_skip (void)
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

static int test_glob_expand_1 (void)
{
  if (test_glob_expand_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_glob_expand_1");
    return 0;
  }

  /* InitBasicFS for test_glob_expand_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for glob_expand (1) */
  {
    const char *path = "/a/b/c";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/b/c/d";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/b/c/e";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *pattern = "/a/*/c/*";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_glob_expand (g, pattern);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_glob_expand_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/a/b/c/d";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_glob_expand_1: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_glob_expand_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/a/b/c/e";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_glob_expand_1: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_glob_expand_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_glob_expand_2_skip (void)
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

static int test_glob_expand_2 (void)
{
  if (test_glob_expand_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_glob_expand_2");
    return 0;
  }

  /* InitBasicFS for test_glob_expand_2: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for glob_expand (2) */
  {
    const char *path = "/a/b/c";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/b/c/d";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/b/c/e";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *pattern = "/a/*/x/*";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_glob_expand (g, pattern);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_glob_expand_2: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_ntfs_3g_probe_0_skip (void)
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

static int test_ntfs_3g_probe_0 (void)
{
  if (test_ntfs_3g_probe_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_ntfs_3g_probe_0");
    return 0;
  }

  {
    const char *groups[] = { "ntfs3g", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_ntfs_3g_probe_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_ntfs_3g_probe_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for ntfs_3g_probe (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ntfs";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_ntfs_3g_probe (g, 1, device);
    if (r == -1)
      return -1;
    if (r != 0) {
      fprintf (stderr, "test_ntfs_3g_probe_0: expected 0 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_ntfs_3g_probe_1_skip (void)
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

static int test_ntfs_3g_probe_1 (void)
{
  if (test_ntfs_3g_probe_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_ntfs_3g_probe_1");
    return 0;
  }

  {
    const char *groups[] = { "ntfs3g", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_ntfs_3g_probe_1", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_ntfs_3g_probe_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for ntfs_3g_probe (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_ntfs_3g_probe (g, 1, device);
    if (r == -1)
      return -1;
    if (r != 12) {
      fprintf (stderr, "test_ntfs_3g_probe_1: expected 12 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_sleep_0_skip (void)
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

static int test_sleep_0 (void)
{
  if (test_sleep_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_sleep_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_sleep_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for sleep (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_sleep (g, 1);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_find_0_skip (void)
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

static int test_find_0 (void)
{
  if (test_find_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_find_0");
    return 0;
  }

  /* InitBasicFS for test_find_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for find (0) */
  {
    const char *directory = "/";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_find (g, directory);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_find_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "lost+found";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_find_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_find_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_find_1_skip (void)
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

static int test_find_1 (void)
{
  if (test_find_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_find_1");
    return 0;
  }

  /* InitBasicFS for test_find_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for find (1) */
  {
    const char *path = "/a";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/b";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/b/c";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *directory = "/";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_find (g, directory);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_find_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "a";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_find_1: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_find_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "b";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_find_1: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_find_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "b/c";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_find_1: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "test_find_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "lost+found";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "test_find_1: expected \"%s\" but got \"%s\"\n", expected, r[3]);
        return -1;
      }
    }
    if (r[4] != NULL) {
      fprintf (stderr, "test_find_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_find_2_skip (void)
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

static int test_find_2 (void)
{
  if (test_find_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_find_2");
    return 0;
  }

  /* InitBasicFS for test_find_2: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for find (2) */
  {
    const char *path = "/a/b/c";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/a/b/c/d";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *directory = "/a/b/";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_find (g, directory);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_find_2: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "c";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_find_2: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_find_2: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "c/d";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_find_2: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_find_2: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_lvresize_0_skip (void)
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

static int test_lvresize_0 (void)
{
  if (test_lvresize_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvresize_0");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvresize_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_lvresize_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 10);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "test content";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *pathordevice = "/";
    int r;
    suppress_error = 0;
    r = guestfs_umount (g, pathordevice);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    int r;
    suppress_error = 0;
    r = guestfs_lvresize (g, device, 20);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    int r;
    suppress_error = 0;
    r = guestfs_e2fsck_f (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV";
    int r;
    suppress_error = 0;
    r = guestfs_resize2fs (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_lvresize_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_zerofree_0_skip (void)
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

static int test_zerofree_0 (void)
{
  if (test_zerofree_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_zerofree_0");
    return 0;
  }

  {
    const char *groups[] = { "zerofree", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_zerofree_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_zerofree_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext3";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "test file";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *pathordevice = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_umount (g, pathordevice);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_zerofree (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_zerofree_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_hexdump_0_skip (void)
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

static int test_hexdump_0 (void)
{
  if (test_hexdump_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_hexdump_0");
    return 0;
  }

  /* InitISOFS for test_hexdump_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for hexdump (0) */
  const char *expected = "00000000  61 62 63 0a 64 65 66 0a  67 68 69                 |abc.def.ghi|\n0000000b\n";
  {
    const char *path = "/known-4";
    char *r;
    suppress_error = 0;
    r = guestfs_hexdump (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_hexdump_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_hexdump_1_skip (void)
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

static int test_hexdump_1 (void)
{
  if (test_hexdump_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_hexdump_1");
    return 0;
  }

  /* InitISOFS for test_hexdump_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for hexdump (1) */
  {
    const char *path = "/100krandom";
    char *r;
    suppress_error = 0;
    r = guestfs_hexdump (g, path);
    if (r == NULL)
      return -1;
    free (r);
  }
  return 0;
}

static int test_strings_e_0_skip (void)
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

static int test_strings_e_0 (void)
{
  if (test_strings_e_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_strings_e_0");
    return 0;
  }

  /* InitISOFS for test_strings_e_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for strings_e (0) */
  {
    const char *encoding = "b";
    const char *path = "/known-5";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_strings_e (g, encoding, path);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_strings_e_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_strings_e_1_skip (void)
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

static int test_strings_e_1 (void)
{
  if (test_strings_e_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_strings_e_1");
    return 0;
  }

  printf ("        %s skipped (reason: test disabled in generator)\n", "test_strings_e_1");
  return 0;
}

static int test_strings_0_skip (void)
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

static int test_strings_0 (void)
{
  if (test_strings_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_strings_0");
    return 0;
  }

  /* InitISOFS for test_strings_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for strings (0) */
  {
    const char *path = "/known-5";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_strings (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_strings_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abcdefghi";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_strings_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_strings_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "jklmnopqr";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_strings_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_strings_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_strings_1_skip (void)
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

static int test_strings_1 (void)
{
  if (test_strings_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_strings_1");
    return 0;
  }

  /* InitISOFS for test_strings_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for strings (1) */
  {
    const char *path = "/empty";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_strings (g, path);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_strings_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_equal_0_skip (void)
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

static int test_equal_0 (void)
{
  if (test_equal_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_equal_0");
    return 0;
  }

  /* InitBasicFS for test_equal_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for equal (0) */
  {
    const char *path = "/file1";
    const char *content = "contents of a file";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/file1";
    const char *dest = "/file2";
    int r;
    suppress_error = 0;
    r = guestfs_cp (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *file1 = "/file1";
    const char *file2 = "/file2";
    int r;
    suppress_error = 0;
    r = guestfs_equal (g, file1, file2);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_equal_0: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_equal_1_skip (void)
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

static int test_equal_1 (void)
{
  if (test_equal_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_equal_1");
    return 0;
  }

  /* InitBasicFS for test_equal_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for equal (1) */
  {
    const char *path = "/file1";
    const char *content = "contents of a file";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/file2";
    const char *content = "contents of another file";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *file1 = "/file1";
    const char *file2 = "/file2";
    int r;
    suppress_error = 0;
    r = guestfs_equal (g, file1, file2);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "test_equal_1: expected false, got true\n");
      return -1;
    }
  }
  return 0;
}

static int test_equal_2_skip (void)
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

static int test_equal_2 (void)
{
  if (test_equal_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_equal_2");
    return 0;
  }

  /* InitBasicFS for test_equal_2: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for equal (2) */
  {
    const char *file1 = "/file1";
    const char *file2 = "/file2";
    int r;
    suppress_error = 1;
    r = guestfs_equal (g, file1, file2);
    if (r != -1)
      return -1;
  }
  return 0;
}

static int test_ping_daemon_0_skip (void)
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

static int test_ping_daemon_0 (void)
{
  if (test_ping_daemon_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_ping_daemon_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_ping_daemon_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for ping_daemon (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_ping_daemon (g);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_dmesg_0_skip (void)
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

static int test_dmesg_0 (void)
{
  if (test_dmesg_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_dmesg_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_dmesg_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for dmesg (0) */
  {
    char *r;
    suppress_error = 0;
    r = guestfs_dmesg (g);
    if (r == NULL)
      return -1;
    free (r);
  }
  return 0;
}

static int test_drop_caches_0_skip (void)
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

static int test_drop_caches_0 (void)
{
  if (test_drop_caches_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_drop_caches_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_drop_caches_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for drop_caches (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_drop_caches (g, 3);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_mv_0_skip (void)
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

static int test_mv_0 (void)
{
  if (test_mv_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mv_0");
    return 0;
  }

  /* InitBasicFS for test_mv_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mv (0) */
  const char *expected = "file content";
  {
    const char *path = "/old";
    const char *content = "file content";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/old";
    const char *dest = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_mv (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_mv_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_mv_1_skip (void)
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

static int test_mv_1 (void)
{
  if (test_mv_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mv_1");
    return 0;
  }

  /* InitBasicFS for test_mv_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for mv (1) */
  {
    const char *path = "/old";
    const char *content = "file content";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/old";
    const char *dest = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_mv (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/old";
    int r;
    suppress_error = 0;
    r = guestfs_is_file (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "test_mv_1: expected false, got true\n");
      return -1;
    }
  }
  return 0;
}

static int test_cp_a_0_skip (void)
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

static int test_cp_a_0 (void)
{
  if (test_cp_a_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_cp_a_0");
    return 0;
  }

  /* InitBasicFS for test_cp_a_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for cp_a (0) */
  const char *expected = "file content";
  {
    const char *path = "/olddir";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/newdir";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/olddir/file";
    const char *content = "file content";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/olddir";
    const char *dest = "/newdir";
    int r;
    suppress_error = 0;
    r = guestfs_cp_a (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/newdir/olddir/file";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_cp_a_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_cp_0_skip (void)
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

static int test_cp_0 (void)
{
  if (test_cp_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_cp_0");
    return 0;
  }

  /* InitBasicFS for test_cp_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for cp (0) */
  const char *expected = "file content";
  {
    const char *path = "/old";
    const char *content = "file content";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/old";
    const char *dest = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_cp (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_cp_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_cp_1_skip (void)
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

static int test_cp_1 (void)
{
  if (test_cp_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_cp_1");
    return 0;
  }

  /* InitBasicFS for test_cp_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for cp (1) */
  {
    const char *path = "/old";
    const char *content = "file content";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/old";
    const char *dest = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_cp (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/old";
    int r;
    suppress_error = 0;
    r = guestfs_is_file (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_cp_1: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_cp_2_skip (void)
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

static int test_cp_2 (void)
{
  if (test_cp_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_cp_2");
    return 0;
  }

  /* InitBasicFS for test_cp_2: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for cp (2) */
  const char *expected = "file content";
  {
    const char *path = "/old";
    const char *content = "file content";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/dir";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *src = "/old";
    const char *dest = "/dir/new";
    int r;
    suppress_error = 0;
    r = guestfs_cp (g, src, dest);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/dir/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_cp_2: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_grub_install_0_skip (void)
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

static int test_grub_install_0 (void)
{
  if (test_grub_install_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_grub_install_0");
    return 0;
  }

  printf ("        %s skipped (reason: test disabled in generator)\n", "test_grub_install_0");
  return 0;
}

static int test_zero_0_skip (void)
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

static int test_zero_0 (void)
{
  if (test_zero_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_zero_0");
    return 0;
  }

  /* InitBasicFS for test_zero_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for zero (0) */
  const char *expected = "data";
  {
    const char *pathordevice = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_umount (g, pathordevice);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_zero (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/dev/sda1";
    char *r;
    suppress_error = 0;
    r = guestfs_file (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_zero_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_fsck_0_skip (void)
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

static int test_fsck_0 (void)
{
  if (test_fsck_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_fsck_0");
    return 0;
  }

  /* InitBasicFS for test_fsck_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for fsck (0) */
  {
    const char *pathordevice = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_umount (g, pathordevice);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_fsck (g, fstype, device);
    if (r == -1)
      return -1;
    if (r != 0) {
      fprintf (stderr, "test_fsck_0: expected 0 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_fsck_1_skip (void)
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

static int test_fsck_1 (void)
{
  if (test_fsck_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_fsck_1");
    return 0;
  }

  /* InitBasicFS for test_fsck_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for fsck (1) */
  {
    const char *pathordevice = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_umount (g, pathordevice);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_zero (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_fsck (g, fstype, device);
    if (r == -1)
      return -1;
    if (r != 8) {
      fprintf (stderr, "test_fsck_1: expected 8 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_set_e2uuid_0_skip (void)
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

static int test_set_e2uuid_0 (void)
{
  if (test_set_e2uuid_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_e2uuid_0");
    return 0;
  }

  /* InitBasicFS for test_set_e2uuid_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for set_e2uuid (0) */
  const char *expected = "f11ff6f8-78d9-4865-a099-e82ec8172bc3";
  {
    const char *device = "/dev/sda1";
    const char *uuid = "f11ff6f8-78d9-4865-a099-e82ec8172bc3";
    int r;
    suppress_error = 0;
    r = guestfs_set_e2uuid (g, device, uuid);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    char *r;
    suppress_error = 0;
    r = guestfs_get_e2uuid (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_set_e2uuid_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_set_e2uuid_1_skip (void)
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

static int test_set_e2uuid_1 (void)
{
  if (test_set_e2uuid_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_e2uuid_1");
    return 0;
  }

  /* InitBasicFS for test_set_e2uuid_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for set_e2uuid (1) */
  const char *expected = "";
  {
    const char *device = "/dev/sda1";
    const char *uuid = "clear";
    int r;
    suppress_error = 0;
    r = guestfs_set_e2uuid (g, device, uuid);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    char *r;
    suppress_error = 0;
    r = guestfs_get_e2uuid (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_set_e2uuid_1: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_set_e2uuid_2_skip (void)
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

static int test_set_e2uuid_2 (void)
{
  if (test_set_e2uuid_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_e2uuid_2");
    return 0;
  }

  /* InitBasicFS for test_set_e2uuid_2: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for set_e2uuid (2) */
  {
    const char *device = "/dev/sda1";
    const char *uuid = "random";
    int r;
    suppress_error = 0;
    r = guestfs_set_e2uuid (g, device, uuid);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_set_e2uuid_3_skip (void)
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

static int test_set_e2uuid_3 (void)
{
  if (test_set_e2uuid_3_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_e2uuid_3");
    return 0;
  }

  /* InitBasicFS for test_set_e2uuid_3: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for set_e2uuid (3) */
  {
    const char *device = "/dev/sda1";
    const char *uuid = "time";
    int r;
    suppress_error = 0;
    r = guestfs_set_e2uuid (g, device, uuid);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_set_e2label_0_skip (void)
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

static int test_set_e2label_0 (void)
{
  if (test_set_e2label_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_e2label_0");
    return 0;
  }

  /* InitBasicFS for test_set_e2label_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for set_e2label (0) */
  const char *expected = "testlabel";
  {
    const char *device = "/dev/sda1";
    const char *label = "testlabel";
    int r;
    suppress_error = 0;
    r = guestfs_set_e2label (g, device, label);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    char *r;
    suppress_error = 0;
    r = guestfs_get_e2label (g, device);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_set_e2label_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_pvremove_0_skip (void)
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

static int test_pvremove_0 (void)
{
  if (test_pvremove_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvremove_0");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvremove_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_pvremove_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for pvremove (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *vgname = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_vgremove (g, vgname);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_pvremove (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_pvremove_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_pvremove_1_skip (void)
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

static int test_pvremove_1 (void)
{
  if (test_pvremove_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvremove_1");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvremove_1", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_pvremove_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for pvremove (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *vgname = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_vgremove (g, vgname);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_pvremove (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_pvremove_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_pvremove_2_skip (void)
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

static int test_pvremove_2 (void)
{
  if (test_pvremove_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvremove_2");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvremove_2", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_pvremove_2 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for pvremove (2) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *vgname = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_vgremove (g, vgname);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_pvremove (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_pvs (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_pvremove_2: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_vgremove_0_skip (void)
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

static int test_vgremove_0 (void)
{
  if (test_vgremove_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgremove_0");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_vgremove_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_vgremove_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for vgremove (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *vgname = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_vgremove (g, vgname);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_vgremove_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_vgremove_1_skip (void)
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

static int test_vgremove_1 (void)
{
  if (test_vgremove_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgremove_1");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_vgremove_1", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_vgremove_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for vgremove (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *vgname = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_vgremove (g, vgname);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_vgremove_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_lvremove_0_skip (void)
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

static int test_lvremove_0 (void)
{
  if (test_lvremove_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvremove_0");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvremove_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_lvremove_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvremove (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG/LV1";
    int r;
    suppress_error = 0;
    r = guestfs_lvremove (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_lvremove_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG/LV2";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_lvremove_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_lvremove_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_lvremove_1_skip (void)
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

static int test_lvremove_1 (void)
{
  if (test_lvremove_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvremove_1");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvremove_1", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_lvremove_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvremove (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvremove (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_lvremove_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_lvremove_2_skip (void)
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

static int test_lvremove_2 (void)
{
  if (test_lvremove_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvremove_2");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvremove_2", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_lvremove_2 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvremove (2) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvremove (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_lvremove_2: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_lvremove_2: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_lvremove_2: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_mount_ro_0_skip (void)
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

static int test_mount_ro_0 (void)
{
  if (test_mount_ro_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mount_ro_0");
    return 0;
  }

  /* InitBasicFS for test_mount_ro_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for mount_ro (0) */
  {
    const char *pathordevice = "/";
    int r;
    suppress_error = 0;
    r = guestfs_umount (g, pathordevice);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    int r;
    suppress_error = 1;
    r = guestfs_touch (g, path);
    if (r != -1)
      return -1;
  }
  return 0;
}

static int test_mount_ro_1_skip (void)
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

static int test_mount_ro_1 (void)
{
  if (test_mount_ro_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mount_ro_1");
    return 0;
  }

  /* InitBasicFS for test_mount_ro_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for mount_ro (1) */
  const char *expected = "data";
  {
    const char *path = "/new";
    const char *content = "data";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *pathordevice = "/";
    int r;
    suppress_error = 0;
    r = guestfs_umount (g, pathordevice);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_mount_ro_1: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_tgz_in_0_skip (void)
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

static int test_tgz_in_0 (void)
{
  if (test_tgz_in_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_tgz_in_0");
    return 0;
  }

  /* InitBasicFS for test_tgz_in_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for tgz_in (0) */
  const char *expected = "hello\n";
  {
    const char *directory = "/";
    int r;
    suppress_error = 0;
    r = guestfs_tgz_in (g, "../images/helloworld.tar.gz", directory);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/hello";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_tgz_in_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_tar_in_0_skip (void)
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

static int test_tar_in_0 (void)
{
  if (test_tar_in_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_tar_in_0");
    return 0;
  }

  /* InitBasicFS for test_tar_in_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for tar_in (0) */
  const char *expected = "hello\n";
  {
    const char *directory = "/";
    int r;
    suppress_error = 0;
    r = guestfs_tar_in (g, "../images/helloworld.tar", directory);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/hello";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_tar_in_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_checksum_0_skip (void)
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

static int test_checksum_0 (void)
{
  if (test_checksum_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_0");
    return 0;
  }

  /* InitISOFS for test_checksum_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_checksum_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_checksum_1_skip (void)
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

static int test_checksum_1 (void)
{
  if (test_checksum_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_1");
    return 0;
  }

  /* InitISOFS for test_checksum_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for checksum (1) */
  {
    const char *csumtype = "crc";
    const char *path = "/notexists";
    char *r;
    suppress_error = 1;
    r = guestfs_checksum (g, csumtype, path);
    if (r != NULL)
      return -1;
    free (r);
  }
  return 0;
}

static int test_checksum_2_skip (void)
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

static int test_checksum_2 (void)
{
  if (test_checksum_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_2");
    return 0;
  }

  /* InitISOFS for test_checksum_2 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_checksum_2: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_checksum_3_skip (void)
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

static int test_checksum_3 (void)
{
  if (test_checksum_3_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_3");
    return 0;
  }

  /* InitISOFS for test_checksum_3 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_checksum_3: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_checksum_4_skip (void)
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

static int test_checksum_4 (void)
{
  if (test_checksum_4_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_4");
    return 0;
  }

  /* InitISOFS for test_checksum_4 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_checksum_4: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_checksum_5_skip (void)
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

static int test_checksum_5 (void)
{
  if (test_checksum_5_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_5");
    return 0;
  }

  /* InitISOFS for test_checksum_5 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_checksum_5: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_checksum_6_skip (void)
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

static int test_checksum_6 (void)
{
  if (test_checksum_6_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_6");
    return 0;
  }

  /* InitISOFS for test_checksum_6 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_checksum_6: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_checksum_7_skip (void)
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

static int test_checksum_7 (void)
{
  if (test_checksum_7_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_checksum_7");
    return 0;
  }

  /* InitISOFS for test_checksum_7 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_checksum_7: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_download_0_skip (void)
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

static int test_download_0 (void)
{
  if (test_download_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_download_0");
    return 0;
  }

  /* InitBasicFS for test_download_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for download (0) */
  const char *expected = "603274a0c34714ef3c2d6cf741995301";
  {
    const char *remotefilename = "/COPYING.LIB";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "../COPYING.LIB", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/COPYING.LIB";
    int r;
    suppress_error = 0;
    r = guestfs_download (g, remotefilename, "testdownload.tmp");
    if (r == -1)
      return -1;
  }
  {
    const char *remotefilename = "/upload";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "testdownload.tmp", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *csumtype = "md5";
    const char *path = "/upload";
    char *r;
    suppress_error = 0;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_download_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_upload_0_skip (void)
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

static int test_upload_0 (void)
{
  if (test_upload_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_upload_0");
    return 0;
  }

  /* InitBasicFS for test_upload_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for upload (0) */
  const char *expected = "603274a0c34714ef3c2d6cf741995301";
  {
    const char *remotefilename = "/COPYING.LIB";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "../COPYING.LIB", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *csumtype = "md5";
    const char *path = "/COPYING.LIB";
    char *r;
    suppress_error = 0;
    r = guestfs_checksum (g, csumtype, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_upload_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_blockdev_rereadpt_0_skip (void)
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

static int test_blockdev_rereadpt_0 (void)
{
  if (test_blockdev_rereadpt_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_rereadpt_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_rereadpt_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for blockdev_rereadpt (0) */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_rereadpt (g, device);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_blockdev_flushbufs_0_skip (void)
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

static int test_blockdev_flushbufs_0 (void)
{
  if (test_blockdev_flushbufs_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_flushbufs_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_flushbufs_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for blockdev_flushbufs (0) */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_flushbufs (g, device);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_blockdev_getsize64_0_skip (void)
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

static int test_blockdev_getsize64_0 (void)
{
  if (test_blockdev_getsize64_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_getsize64_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_getsize64_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for blockdev_getsize64 (0) */
  {
    const char *device = "/dev/sda";
    int64_t r;
    suppress_error = 0;
    r = guestfs_blockdev_getsize64 (g, device);
    if (r == -1)
      return -1;
    if (r != 524288000) {
      fprintf (stderr, "test_blockdev_getsize64_0: expected 524288000 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_blockdev_getsz_0_skip (void)
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

static int test_blockdev_getsz_0 (void)
{
  if (test_blockdev_getsz_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_getsz_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_getsz_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for blockdev_getsz (0) */
  {
    const char *device = "/dev/sda";
    int64_t r;
    suppress_error = 0;
    r = guestfs_blockdev_getsz (g, device);
    if (r == -1)
      return -1;
    if (r != 1024000) {
      fprintf (stderr, "test_blockdev_getsz_0: expected 1024000 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_blockdev_getbsz_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "blockdev_getbsz") == NULL;
  str = getenv ("SKIP_TEST_BLOCKDEV_GETBSZ_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_BLOCKDEV_GETBSZ");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int test_blockdev_getbsz_0 (void)
{
  if (test_blockdev_getbsz_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_getbsz_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_getbsz_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for blockdev_getbsz (0) */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_getbsz (g, device);
    if (r == -1)
      return -1;
    if (r != 4096) {
      fprintf (stderr, "test_blockdev_getbsz_0: expected 4096 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_blockdev_getss_0_skip (void)
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

static int test_blockdev_getss_0 (void)
{
  if (test_blockdev_getss_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_getss_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_getss_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for blockdev_getss (0) */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_getss (g, device);
    if (r == -1)
      return -1;
    if (r != 512) {
      fprintf (stderr, "test_blockdev_getss_0: expected 512 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_blockdev_getro_0_skip (void)
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

static int test_blockdev_getro_0 (void)
{
  if (test_blockdev_getro_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_getro_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_getro_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for blockdev_getro (0) */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setro (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_getro (g, device);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_blockdev_getro_0: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_blockdev_setrw_0_skip (void)
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

static int test_blockdev_setrw_0 (void)
{
  if (test_blockdev_setrw_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_setrw_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_setrw_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for blockdev_setrw (0) */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_getro (g, device);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "test_blockdev_setrw_0: expected false, got true\n");
      return -1;
    }
  }
  return 0;
}

static int test_blockdev_setro_0_skip (void)
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

static int test_blockdev_setro_0 (void)
{
  if (test_blockdev_setro_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_blockdev_setro_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_blockdev_setro_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for blockdev_setro (0) */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setro (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_getro (g, device);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_blockdev_setro_0: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_statvfs_0_skip (void)
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

static int test_statvfs_0 (void)
{
  if (test_statvfs_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_statvfs_0");
    return 0;
  }

  /* InitISOFS for test_statvfs_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for statvfs (0) */
  {
    const char *path = "/";
    struct guestfs_statvfs *r;
    suppress_error = 0;
    r = guestfs_statvfs (g, path);
    if (r == NULL)
      return -1;
    if (r->namemax != 255) {
      fprintf (stderr, "test_statvfs_0: namemax was %d, expected 255\n",
               (int) r->namemax);
      return -1;
    }
    guestfs_free_statvfs (r);
  }
  return 0;
}

static int test_lstat_0_skip (void)
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

static int test_lstat_0 (void)
{
  if (test_lstat_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_lstat_0");
    return 0;
  }

  /* InitISOFS for test_lstat_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for lstat (0) */
  {
    const char *path = "/empty";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_lstat (g, path);
    if (r == NULL)
      return -1;
    if (r->size != 0) {
      fprintf (stderr, "test_lstat_0: size was %d, expected 0\n",
               (int) r->size);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_stat_0_skip (void)
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

static int test_stat_0 (void)
{
  if (test_stat_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_stat_0");
    return 0;
  }

  /* InitISOFS for test_stat_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for stat (0) */
  {
    const char *path = "/empty";
    struct guestfs_stat *r;
    suppress_error = 0;
    r = guestfs_stat (g, path);
    if (r == NULL)
      return -1;
    if (r->size != 0) {
      fprintf (stderr, "test_stat_0: size was %d, expected 0\n",
               (int) r->size);
      return -1;
    }
    guestfs_free_stat (r);
  }
  return 0;
}

static int test_command_lines_0_skip (void)
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

static int test_command_lines_0 (void)
{
  if (test_command_lines_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_0");
    return 0;
  }

  /* InitBasicFS for test_command_lines_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (0) */
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "1";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_command_lines_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_command_lines_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_command_lines_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_command_lines_1_skip (void)
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

static int test_command_lines_1 (void)
{
  if (test_command_lines_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_1");
    return 0;
  }

  /* InitBasicFS for test_command_lines_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (1) */
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "2";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_command_lines_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result2";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_command_lines_1: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_command_lines_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_command_lines_2_skip (void)
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

static int test_command_lines_2 (void)
{
  if (test_command_lines_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_2");
    return 0;
  }

  /* InitBasicFS for test_command_lines_2: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (2) */
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "3";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_command_lines_2: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_command_lines_2: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_command_lines_2: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result3";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_command_lines_2: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_command_lines_2: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_command_lines_3_skip (void)
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

static int test_command_lines_3 (void)
{
  if (test_command_lines_3_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_3");
    return 0;
  }

  /* InitBasicFS for test_command_lines_3: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (3) */
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "4";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_command_lines_3: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_command_lines_3: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_command_lines_3: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result4";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_command_lines_3: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_command_lines_3: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_command_lines_4_skip (void)
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

static int test_command_lines_4 (void)
{
  if (test_command_lines_4_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_4");
    return 0;
  }

  /* InitBasicFS for test_command_lines_4: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (4) */
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "5";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_command_lines_4: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_command_lines_4: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_command_lines_4: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result5";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_command_lines_4: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_command_lines_4: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_command_lines_4: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_command_lines_4: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_command_lines_5_skip (void)
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

static int test_command_lines_5 (void)
{
  if (test_command_lines_5_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_5");
    return 0;
  }

  /* InitBasicFS for test_command_lines_5: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (5) */
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "6";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_command_lines_5: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_command_lines_5: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_command_lines_5: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_command_lines_5: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_command_lines_5: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result6";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_command_lines_5: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "test_command_lines_5: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "test_command_lines_5: expected \"%s\" but got \"%s\"\n", expected, r[3]);
        return -1;
      }
    }
    if (r[4] != NULL) {
      fprintf (stderr, "test_command_lines_5: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_command_lines_6_skip (void)
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

static int test_command_lines_6 (void)
{
  if (test_command_lines_6_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_6");
    return 0;
  }

  /* InitBasicFS for test_command_lines_6: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (6) */
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "7";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_command_lines_6: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_command_lines_7_skip (void)
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

static int test_command_lines_7 (void)
{
  if (test_command_lines_7_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_7");
    return 0;
  }

  /* InitBasicFS for test_command_lines_7: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (7) */
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "8";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_command_lines_7: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_command_lines_7: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_command_lines_7: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_command_lines_8_skip (void)
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

static int test_command_lines_8 (void)
{
  if (test_command_lines_8_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_8");
    return 0;
  }

  /* InitBasicFS for test_command_lines_8: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (8) */
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "9";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_command_lines_8: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_command_lines_8: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_command_lines_8: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_command_lines_8: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_command_lines_8: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_command_lines_9_skip (void)
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

static int test_command_lines_9 (void)
{
  if (test_command_lines_9_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_9");
    return 0;
  }

  /* InitBasicFS for test_command_lines_9: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (9) */
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "10";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_command_lines_9: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result10-1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_command_lines_9: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_command_lines_9: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result10-2";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_command_lines_9: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_command_lines_9: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_command_lines_10_skip (void)
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

static int test_command_lines_10 (void)
{
  if (test_command_lines_10_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_lines_10");
    return 0;
  }

  /* InitBasicFS for test_command_lines_10: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for command_lines (10) */
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "11";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_command_lines (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_command_lines_10: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result11-1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_command_lines_10: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_command_lines_10: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "Result11-2";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_command_lines_10: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_command_lines_10: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_command_0_skip (void)
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

static int test_command_0 (void)
{
  if (test_command_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_0");
    return 0;
  }

  /* InitBasicFS for test_command_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (0) */
  const char *expected = "Result1";
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "1";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    suppress_error = 0;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_command_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_command_1_skip (void)
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

static int test_command_1 (void)
{
  if (test_command_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_1");
    return 0;
  }

  /* InitBasicFS for test_command_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (1) */
  const char *expected = "Result2\n";
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "2";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    suppress_error = 0;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_command_1: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_command_2_skip (void)
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

static int test_command_2 (void)
{
  if (test_command_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_2");
    return 0;
  }

  /* InitBasicFS for test_command_2: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (2) */
  const char *expected = "\nResult3";
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "3";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    suppress_error = 0;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_command_2: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_command_3_skip (void)
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

static int test_command_3 (void)
{
  if (test_command_3_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_3");
    return 0;
  }

  /* InitBasicFS for test_command_3: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (3) */
  const char *expected = "\nResult4\n";
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "4";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    suppress_error = 0;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_command_3: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_command_4_skip (void)
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

static int test_command_4 (void)
{
  if (test_command_4_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_4");
    return 0;
  }

  /* InitBasicFS for test_command_4: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (4) */
  const char *expected = "\nResult5\n\n";
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "5";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    suppress_error = 0;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_command_4: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_command_5_skip (void)
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

static int test_command_5 (void)
{
  if (test_command_5_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_5");
    return 0;
  }

  /* InitBasicFS for test_command_5: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (5) */
  const char *expected = "\n\nResult6\n\n";
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "6";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    suppress_error = 0;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_command_5: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_command_6_skip (void)
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

static int test_command_6 (void)
{
  if (test_command_6_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_6");
    return 0;
  }

  /* InitBasicFS for test_command_6: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (6) */
  const char *expected = "";
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "7";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    suppress_error = 0;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_command_6: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_command_7_skip (void)
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

static int test_command_7 (void)
{
  if (test_command_7_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_7");
    return 0;
  }

  /* InitBasicFS for test_command_7: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (7) */
  const char *expected = "\n";
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "8";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    suppress_error = 0;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_command_7: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_command_8_skip (void)
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

static int test_command_8 (void)
{
  if (test_command_8_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_8");
    return 0;
  }

  /* InitBasicFS for test_command_8: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (8) */
  const char *expected = "\n\n";
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "9";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    suppress_error = 0;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_command_8: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_command_9_skip (void)
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

static int test_command_9 (void)
{
  if (test_command_9_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_9");
    return 0;
  }

  /* InitBasicFS for test_command_9: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (9) */
  const char *expected = "Result10-1\nResult10-2\n";
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "10";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    suppress_error = 0;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_command_9: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_command_10_skip (void)
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

static int test_command_10 (void)
{
  if (test_command_10_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_10");
    return 0;
  }

  /* InitBasicFS for test_command_10: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for command (10) */
  const char *expected = "Result11-1\nResult11-2";
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *arguments_1 = "11";
    const char *const arguments[] = {
      arguments_0,
      arguments_1,
      NULL
    };
    char *r;
    suppress_error = 0;
    r = guestfs_command (g, (char **) arguments);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_command_10: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_command_11_skip (void)
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

static int test_command_11 (void)
{
  if (test_command_11_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_command_11");
    return 0;
  }

  /* InitBasicFS for test_command_11: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for command (11) */
  {
    const char *remotefilename = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_upload (g, "test-command", remotefilename);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/test-command";
    int r;
    suppress_error = 0;
    r = guestfs_chmod (g, 493, path);
    if (r == -1)
      return -1;
  }
  {
    const char *arguments_0 = "/test-command";
    const char *const arguments[] = {
      arguments_0,
      NULL
    };
    char *r;
    suppress_error = 1;
    r = guestfs_command (g, (char **) arguments);
    if (r != NULL)
      return -1;
    free (r);
  }
  return 0;
}

static int test_file_0_skip (void)
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

static int test_file_0 (void)
{
  if (test_file_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_0");
    return 0;
  }

  /* InitISOFS for test_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file (0) */
  const char *expected = "empty";
  {
    const char *path = "/empty";
    char *r;
    suppress_error = 0;
    r = guestfs_file (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_file_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_file_1_skip (void)
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

static int test_file_1 (void)
{
  if (test_file_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_1");
    return 0;
  }

  /* InitISOFS for test_file_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for file (1) */
  const char *expected = "ASCII text";
  {
    const char *path = "/known-1";
    char *r;
    suppress_error = 0;
    r = guestfs_file (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_file_1: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_file_2_skip (void)
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

static int test_file_2 (void)
{
  if (test_file_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_file_2");
    return 0;
  }

  /* InitISOFS for test_file_2 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for file (2) */
  {
    const char *path = "/notexists";
    char *r;
    suppress_error = 1;
    r = guestfs_file (g, path);
    if (r != NULL)
      return -1;
    free (r);
  }
  return 0;
}

static int test_umount_all_0_skip (void)
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

static int test_umount_all_0 (void)
{
  if (test_umount_all_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_umount_all_0");
    return 0;
  }

  /* InitBasicFS for test_umount_all_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for umount_all (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_mounts (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_umount_all_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_umount_all_1_skip (void)
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

static int test_umount_all_1 (void)
{
  if (test_umount_all_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_umount_all_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_umount_all_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for umount_all (1) */
  {
    const char *device = "/dev/sda";
    const char *lines_0 = ",100";
    const char *lines_1 = ",200";
    const char *lines_2 = ",";
    const char *const lines[] = {
      lines_0,
      lines_1,
      lines_2,
      NULL
    };
    int r;
    suppress_error = 0;
    r = guestfs_sfdiskM (g, device, (char **) lines);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda2";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda3";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mp1";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda2";
    const char *mountpoint = "/mp1";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mp1/mp2";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda3";
    const char *mountpoint = "/mp1/mp2";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/mp1/mp2/mp3";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_mounts (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_umount_all_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_mounts_0_skip (void)
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

static int test_mounts_0 (void)
{
  if (test_mounts_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mounts_0");
    return 0;
  }

  /* InitBasicFS for test_mounts_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for mounts (0) */
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_mounts (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_mounts_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_mounts_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_mounts_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_umount_0_skip (void)
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

static int test_umount_0 (void)
{
  if (test_umount_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_umount_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_umount_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for umount (0) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_mounts (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_umount_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_umount_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_umount_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_umount_1_skip (void)
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

static int test_umount_1 (void)
{
  if (test_umount_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_umount_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_umount_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for umount (1) */
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *pathordevice = "/";
    int r;
    suppress_error = 0;
    r = guestfs_umount (g, pathordevice);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_mounts (g);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_umount_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_write_file_0_skip (void)
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

static int test_write_file_0 (void)
{
  if (test_write_file_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_file_0");
    return 0;
  }

  /* InitBasicFS for test_write_file_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for write_file (0) */
  const char *expected = "new file contents";
  {
    const char *path = "/new";
    const char *content = "new file contents";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_write_file_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_write_file_1_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "write_file") == NULL;
  str = getenv ("SKIP_TEST_WRITE_FILE_1");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WRITE_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int test_write_file_1 (void)
{
  if (test_write_file_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_file_1");
    return 0;
  }

  /* InitBasicFS for test_write_file_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for write_file (1) */
  const char *expected = "\nnew file contents\n";
  {
    const char *path = "/new";
    const char *content = "\nnew file contents\n";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_write_file_1: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_write_file_2_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "write_file") == NULL;
  str = getenv ("SKIP_TEST_WRITE_FILE_2");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WRITE_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int test_write_file_2 (void)
{
  if (test_write_file_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_file_2");
    return 0;
  }

  /* InitBasicFS for test_write_file_2: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for write_file (2) */
  const char *expected = "\n\n";
  {
    const char *path = "/new";
    const char *content = "\n\n";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_write_file_2: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_write_file_3_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "write_file") == NULL;
  str = getenv ("SKIP_TEST_WRITE_FILE_3");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WRITE_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int test_write_file_3 (void)
{
  if (test_write_file_3_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_file_3");
    return 0;
  }

  /* InitBasicFS for test_write_file_3: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for write_file (3) */
  const char *expected = "";
  {
    const char *path = "/new";
    const char *content = "";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_write_file_3: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_write_file_4_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "write_file") == NULL;
  str = getenv ("SKIP_TEST_WRITE_FILE_4");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WRITE_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int test_write_file_4 (void)
{
  if (test_write_file_4_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_file_4");
    return 0;
  }

  /* InitBasicFS for test_write_file_4: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for write_file (4) */
  const char *expected = "\n\n\n";
  {
    const char *path = "/new";
    const char *content = "\n\n\n";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_write_file_4: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_write_file_5_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "write_file") == NULL;
  str = getenv ("SKIP_TEST_WRITE_FILE_5");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_WRITE_FILE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int test_write_file_5 (void)
{
  if (test_write_file_5_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_write_file_5");
    return 0;
  }

  /* InitBasicFS for test_write_file_5: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for write_file (5) */
  const char *expected = "\n";
  {
    const char *path = "/new";
    const char *content = "\n";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_write_file_5: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_mkfs_0_skip (void)
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

static int test_mkfs_0 (void)
{
  if (test_mkfs_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkfs_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mkfs_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_mkfs_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_lvcreate_0_skip (void)
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

static int test_lvcreate_0 (void)
{
  if (test_lvcreate_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvcreate_0");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvcreate_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_lvcreate_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvcreate (0) */
  {
    const char *device = "/dev/sda";
    const char *lines_0 = ",100";
    const char *lines_1 = ",200";
    const char *lines_2 = ",";
    const char *const lines[] = {
      lines_0,
      lines_1,
      lines_2,
      NULL
    };
    int r;
    suppress_error = 0;
    r = guestfs_sfdiskM (g, device, (char **) lines);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda3";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG1";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG1";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV3";
    const char *volgroup = "VG2";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV4";
    const char *volgroup = "VG2";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV5";
    const char *volgroup = "VG2";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_lvcreate_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG1/LV1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_lvcreate_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_lvcreate_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG1/LV2";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_lvcreate_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_lvcreate_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG2/LV3";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_lvcreate_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "test_lvcreate_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG2/LV4";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "test_lvcreate_0: expected \"%s\" but got \"%s\"\n", expected, r[3]);
        return -1;
      }
    }
    if (!r[4]) {
      fprintf (stderr, "test_lvcreate_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG2/LV5";
      if (STRNEQ (r[4], expected)) {
        fprintf (stderr, "test_lvcreate_0: expected \"%s\" but got \"%s\"\n", expected, r[4]);
        return -1;
      }
    }
    if (r[5] != NULL) {
      fprintf (stderr, "test_lvcreate_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_vgcreate_0_skip (void)
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

static int test_vgcreate_0 (void)
{
  if (test_vgcreate_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgcreate_0");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_vgcreate_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_vgcreate_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for vgcreate (0) */
  {
    const char *device = "/dev/sda";
    const char *lines_0 = ",100";
    const char *lines_1 = ",200";
    const char *lines_2 = ",";
    const char *const lines[] = {
      lines_0,
      lines_1,
      lines_2,
      NULL
    };
    int r;
    suppress_error = 0;
    r = guestfs_sfdiskM (g, device, (char **) lines);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda3";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_vgcreate_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_vgcreate_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_vgcreate_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG2";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_vgcreate_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_vgcreate_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_pvcreate_0_skip (void)
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

static int test_pvcreate_0 (void)
{
  if (test_pvcreate_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvcreate_0");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvcreate_0", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_pvcreate_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for pvcreate (0) */
  {
    const char *device = "/dev/sda";
    const char *lines_0 = ",100";
    const char *lines_1 = ",200";
    const char *lines_2 = ",";
    const char *const lines[] = {
      lines_0,
      lines_1,
      lines_2,
      NULL
    };
    int r;
    suppress_error = 0;
    r = guestfs_sfdiskM (g, device, (char **) lines);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda3";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_pvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_pvcreate_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_pvcreate_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_pvcreate_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda2";
      r[1][5] = 's';
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_pvcreate_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_pvcreate_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda3";
      r[2][5] = 's';
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_pvcreate_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_pvcreate_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_is_dir_0_skip (void)
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

static int test_is_dir_0 (void)
{
  if (test_is_dir_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_dir_0");
    return 0;
  }

  /* InitISOFS for test_is_dir_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_dir (0) */
  {
    const char *path = "/known-3";
    int r;
    suppress_error = 0;
    r = guestfs_is_dir (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "test_is_dir_0: expected false, got true\n");
      return -1;
    }
  }
  return 0;
}

static int test_is_dir_1_skip (void)
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

static int test_is_dir_1 (void)
{
  if (test_is_dir_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_dir_1");
    return 0;
  }

  /* InitISOFS for test_is_dir_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for is_dir (1) */
  {
    const char *path = "/directory";
    int r;
    suppress_error = 0;
    r = guestfs_is_dir (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_is_dir_1: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_is_file_0_skip (void)
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

static int test_is_file_0 (void)
{
  if (test_is_file_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_file_0");
    return 0;
  }

  /* InitISOFS for test_is_file_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for is_file (0) */
  {
    const char *path = "/known-1";
    int r;
    suppress_error = 0;
    r = guestfs_is_file (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_is_file_0: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_is_file_1_skip (void)
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

static int test_is_file_1 (void)
{
  if (test_is_file_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_file_1");
    return 0;
  }

  /* InitISOFS for test_is_file_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_file (1) */
  {
    const char *path = "/directory";
    int r;
    suppress_error = 0;
    r = guestfs_is_file (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "test_is_file_1: expected false, got true\n");
      return -1;
    }
  }
  return 0;
}

static int test_exists_0_skip (void)
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

static int test_exists_0 (void)
{
  if (test_exists_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_exists_0");
    return 0;
  }

  /* InitISOFS for test_exists_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for exists (0) */
  {
    const char *path = "/empty";
    int r;
    suppress_error = 0;
    r = guestfs_exists (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_exists_0: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_exists_1_skip (void)
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

static int test_exists_1 (void)
{
  if (test_exists_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_exists_1");
    return 0;
  }

  /* InitISOFS for test_exists_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for exists (1) */
  {
    const char *path = "/directory";
    int r;
    suppress_error = 0;
    r = guestfs_exists (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_exists_1: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_mkdir_p_0_skip (void)
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

static int test_mkdir_p_0 (void)
{
  if (test_mkdir_p_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_p_0");
    return 0;
  }

  /* InitBasicFS for test_mkdir_p_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for mkdir_p (0) */
  {
    const char *path = "/new/foo/bar";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new/foo/bar";
    int r;
    suppress_error = 0;
    r = guestfs_is_dir (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_mkdir_p_0: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_mkdir_p_1_skip (void)
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

static int test_mkdir_p_1 (void)
{
  if (test_mkdir_p_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_p_1");
    return 0;
  }

  /* InitBasicFS for test_mkdir_p_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for mkdir_p (1) */
  {
    const char *path = "/new/foo/bar";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new/foo";
    int r;
    suppress_error = 0;
    r = guestfs_is_dir (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_mkdir_p_1: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_mkdir_p_2_skip (void)
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

static int test_mkdir_p_2 (void)
{
  if (test_mkdir_p_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_p_2");
    return 0;
  }

  /* InitBasicFS for test_mkdir_p_2: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for mkdir_p (2) */
  {
    const char *path = "/new/foo/bar";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_is_dir (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_mkdir_p_2: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_mkdir_p_3_skip (void)
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

static int test_mkdir_p_3 (void)
{
  if (test_mkdir_p_3_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_p_3");
    return 0;
  }

  /* InitBasicFS for test_mkdir_p_3: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for mkdir_p (3) */
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir_p (g, path);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_mkdir_p_4_skip (void)
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

static int test_mkdir_p_4 (void)
{
  if (test_mkdir_p_4_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_p_4");
    return 0;
  }

  /* InitBasicFS for test_mkdir_p_4: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for mkdir_p (4) */
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    int r;
    suppress_error = 1;
    r = guestfs_mkdir_p (g, path);
    if (r != -1)
      return -1;
  }
  return 0;
}

static int test_mkdir_0_skip (void)
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

static int test_mkdir_0 (void)
{
  if (test_mkdir_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_0");
    return 0;
  }

  /* InitBasicFS for test_mkdir_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for mkdir (0) */
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_is_dir (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_mkdir_0: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_mkdir_1_skip (void)
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

static int test_mkdir_1 (void)
{
  if (test_mkdir_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mkdir_1");
    return 0;
  }

  /* InitBasicFS for test_mkdir_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for mkdir (1) */
  {
    const char *path = "/new/foo/bar";
    int r;
    suppress_error = 1;
    r = guestfs_mkdir (g, path);
    if (r != -1)
      return -1;
  }
  return 0;
}

static int test_rm_rf_0_skip (void)
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

static int test_rm_rf_0 (void)
{
  if (test_rm_rf_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_rm_rf_0");
    return 0;
  }

  /* InitBasicFS for test_rm_rf_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for rm_rf (0) */
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new/foo";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new/foo/bar";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_rm_rf (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_exists (g, path);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "test_rm_rf_0: expected false, got true\n");
      return -1;
    }
  }
  return 0;
}

static int test_rmdir_0_skip (void)
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

static int test_rmdir_0 (void)
{
  if (test_rmdir_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_rmdir_0");
    return 0;
  }

  /* InitBasicFS for test_rmdir_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for rmdir (0) */
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_rmdir (g, path);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_rmdir_1_skip (void)
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

static int test_rmdir_1 (void)
{
  if (test_rmdir_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_rmdir_1");
    return 0;
  }

  /* InitBasicFS for test_rmdir_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for rmdir (1) */
  {
    const char *path = "/new";
    int r;
    suppress_error = 1;
    r = guestfs_rmdir (g, path);
    if (r != -1)
      return -1;
  }
  return 0;
}

static int test_rmdir_2_skip (void)
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

static int test_rmdir_2 (void)
{
  if (test_rmdir_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_rmdir_2");
    return 0;
  }

  /* InitBasicFS for test_rmdir_2: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for rmdir (2) */
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    int r;
    suppress_error = 1;
    r = guestfs_rmdir (g, path);
    if (r != -1)
      return -1;
  }
  return 0;
}

static int test_rm_0_skip (void)
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

static int test_rm_0 (void)
{
  if (test_rm_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_rm_0");
    return 0;
  }

  /* InitBasicFS for test_rm_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestRun for rm (0) */
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_rm (g, path);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_rm_1_skip (void)
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

static int test_rm_1 (void)
{
  if (test_rm_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_rm_1");
    return 0;
  }

  /* InitBasicFS for test_rm_1: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for rm (1) */
  {
    const char *path = "/new";
    int r;
    suppress_error = 1;
    r = guestfs_rm (g, path);
    if (r != -1)
      return -1;
  }
  return 0;
}

static int test_rm_2_skip (void)
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

static int test_rm_2 (void)
{
  if (test_rm_2_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_rm_2");
    return 0;
  }

  /* InitBasicFS for test_rm_2: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestLastFail for rm (2) */
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_mkdir (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    int r;
    suppress_error = 1;
    r = guestfs_rm (g, path);
    if (r != -1)
      return -1;
  }
  return 0;
}

static int test_read_lines_0_skip (void)
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

static int test_read_lines_0 (void)
{
  if (test_read_lines_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_lines_0");
    return 0;
  }

  /* InitISOFS for test_read_lines_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for read_lines (0) */
  {
    const char *path = "/known-4";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_read_lines (g, path);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_read_lines_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "abc";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_read_lines_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_read_lines_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "def";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_read_lines_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_read_lines_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "ghi";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_read_lines_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_read_lines_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_read_lines_1_skip (void)
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

static int test_read_lines_1 (void)
{
  if (test_read_lines_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_read_lines_1");
    return 0;
  }

  /* InitISOFS for test_read_lines_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for read_lines (1) */
  {
    const char *path = "/empty";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_read_lines (g, path);
    if (r == NULL)
      return -1;
    if (r[0] != NULL) {
      fprintf (stderr, "test_read_lines_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_lvs_0_skip (void)
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

static int test_lvs_0 (void)
{
  if (test_lvs_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvs_0");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvs_0", groups[0]);
      return 0;
    }
  }
  /* InitBasicFSonLVM for test_lvs_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvs (0) */
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_lvs_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG/LV";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_lvs_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_lvs_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_lvs_1_skip (void)
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

static int test_lvs_1 (void)
{
  if (test_lvs_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_lvs_1");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_lvs_1", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_lvs_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for lvs (1) */
  {
    const char *device = "/dev/sda";
    const char *lines_0 = ",100";
    const char *lines_1 = ",200";
    const char *lines_2 = ",";
    const char *const lines[] = {
      lines_0,
      lines_1,
      lines_2,
      NULL
    };
    int r;
    suppress_error = 0;
    r = guestfs_sfdiskM (g, device, (char **) lines);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda3";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV1";
    const char *volgroup = "VG1";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV2";
    const char *volgroup = "VG1";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV3";
    const char *volgroup = "VG2";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 50);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_lvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_lvs_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG1/LV1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_lvs_1: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_lvs_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG1/LV2";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_lvs_1: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_lvs_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/VG2/LV3";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_lvs_1: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_lvs_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_vgs_0_skip (void)
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

static int test_vgs_0 (void)
{
  if (test_vgs_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgs_0");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_vgs_0", groups[0]);
      return 0;
    }
  }
  /* InitBasicFSonLVM for test_vgs_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for vgs (0) */
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_vgs_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_vgs_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_vgs_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_vgs_1_skip (void)
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

static int test_vgs_1 (void)
{
  if (test_vgs_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_vgs_1");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_vgs_1", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_vgs_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for vgs (1) */
  {
    const char *device = "/dev/sda";
    const char *lines_0 = ",100";
    const char *lines_1 = ",200";
    const char *lines_2 = ",";
    const char *const lines[] = {
      lines_0,
      lines_1,
      lines_2,
      NULL
    };
    int r;
    suppress_error = 0;
    r = guestfs_sfdiskM (g, device, (char **) lines);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda3";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_vgs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_vgs_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG1";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_vgs_1: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_vgs_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "VG2";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_vgs_1: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (r[2] != NULL) {
      fprintf (stderr, "test_vgs_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_pvs_0_skip (void)
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

static int test_pvs_0 (void)
{
  if (test_pvs_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvs_0");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvs_0", groups[0]);
      return 0;
    }
  }
  /* InitBasicFSonLVM for test_pvs_0: create ext2 on /dev/VG/LV */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_vgcreate (g, volgroup, (char **) physvols);
    if (r == -1)
      return -1;
  }
  {
    const char *logvol = "LV";
    const char *volgroup = "VG";
    int r;
    suppress_error = 0;
    r = guestfs_lvcreate (g, logvol, volgroup, 8);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/VG/LV";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/VG/LV";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for pvs (0) */
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_pvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_pvs_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_pvs_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_pvs_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_pvs_1_skip (void)
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

static int test_pvs_1 (void)
{
  if (test_pvs_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_pvs_1");
    return 0;
  }

  {
    const char *groups[] = { "lvm2", NULL };
    int r;
    suppress_error = 1;
    r = guestfs_available (g, (char **) groups);
    suppress_error = 0;
    if (r == -1) {
      printf ("        %s skipped (reason: group %s not available in daemon)\n", "test_pvs_1", groups[0]);
      return 0;
    }
  }
  /* InitNone|InitEmpty for test_pvs_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for pvs (1) */
  {
    const char *device = "/dev/sda";
    const char *lines_0 = ",100";
    const char *lines_1 = ",200";
    const char *lines_2 = ",";
    const char *const lines[] = {
      lines_0,
      lines_1,
      lines_2,
      NULL
    };
    int r;
    suppress_error = 0;
    r = guestfs_sfdiskM (g, device, (char **) lines);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda2";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda3";
    int r;
    suppress_error = 0;
    r = guestfs_pvcreate (g, device);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_pvs (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_pvs_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_pvs_1: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_pvs_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda2";
      r[1][5] = 's';
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_pvs_1: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_pvs_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda3";
      r[2][5] = 's';
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_pvs_1: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_pvs_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_list_partitions_0_skip (void)
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

static int test_list_partitions_0 (void)
{
  if (test_list_partitions_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_list_partitions_0");
    return 0;
  }

  /* InitBasicFS for test_list_partitions_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for list_partitions (0) */
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_list_partitions (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_list_partitions_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_list_partitions_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (r[1] != NULL) {
      fprintf (stderr, "test_list_partitions_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_list_partitions_1_skip (void)
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

static int test_list_partitions_1 (void)
{
  if (test_list_partitions_1_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_list_partitions_1");
    return 0;
  }

  /* InitNone|InitEmpty for test_list_partitions_1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for list_partitions (1) */
  {
    const char *device = "/dev/sda";
    const char *lines_0 = ",100";
    const char *lines_1 = ",200";
    const char *lines_2 = ",";
    const char *const lines[] = {
      lines_0,
      lines_1,
      lines_2,
      NULL
    };
    int r;
    suppress_error = 0;
    r = guestfs_sfdiskM (g, device, (char **) lines);
    if (r == -1)
      return -1;
  }
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_list_partitions (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_list_partitions_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda1";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_list_partitions_1: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_list_partitions_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda2";
      r[1][5] = 's';
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_list_partitions_1: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_list_partitions_1: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda3";
      r[2][5] = 's';
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_list_partitions_1: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (r[3] != NULL) {
      fprintf (stderr, "test_list_partitions_1: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_list_devices_0_skip (void)
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

static int test_list_devices_0 (void)
{
  if (test_list_devices_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_list_devices_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_list_devices_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputListOfDevices for list_devices (0) */
  {
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_list_devices (g);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_list_devices_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sda";
      r[0][5] = 's';
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_list_devices_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_list_devices_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sdb";
      r[1][5] = 's';
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_list_devices_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_list_devices_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sdc";
      r[2][5] = 's';
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_list_devices_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "test_list_devices_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "/dev/sdd";
      r[3][5] = 's';
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "test_list_devices_0: expected \"%s\" but got \"%s\"\n", expected, r[3]);
        return -1;
      }
    }
    if (r[4] != NULL) {
      fprintf (stderr, "test_list_devices_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_ls_0_skip (void)
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

static int test_ls_0 (void)
{
  if (test_ls_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_ls_0");
    return 0;
  }

  /* InitBasicFS for test_ls_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputList for ls (0) */
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/newer";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/newest";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *directory = "/";
    char **r;
    int i;
    suppress_error = 0;
    r = guestfs_ls (g, directory);
    if (r == NULL)
      return -1;
    if (!r[0]) {
      fprintf (stderr, "test_ls_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "lost+found";
      if (STRNEQ (r[0], expected)) {
        fprintf (stderr, "test_ls_0: expected \"%s\" but got \"%s\"\n", expected, r[0]);
        return -1;
      }
    }
    if (!r[1]) {
      fprintf (stderr, "test_ls_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "new";
      if (STRNEQ (r[1], expected)) {
        fprintf (stderr, "test_ls_0: expected \"%s\" but got \"%s\"\n", expected, r[1]);
        return -1;
      }
    }
    if (!r[2]) {
      fprintf (stderr, "test_ls_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "newer";
      if (STRNEQ (r[2], expected)) {
        fprintf (stderr, "test_ls_0: expected \"%s\" but got \"%s\"\n", expected, r[2]);
        return -1;
      }
    }
    if (!r[3]) {
      fprintf (stderr, "test_ls_0: short list returned from command\n");
      print_strings (r);
      return -1;
    }
    {
      const char *expected = "newest";
      if (STRNEQ (r[3], expected)) {
        fprintf (stderr, "test_ls_0: expected \"%s\" but got \"%s\"\n", expected, r[3]);
        return -1;
      }
    }
    if (r[4] != NULL) {
      fprintf (stderr, "test_ls_0: extra elements returned from command\n");
      print_strings (r);
      return -1;
    }
    for (i = 0; r[i] != NULL; ++i)
      free (r[i]);
    free (r);
  }
  return 0;
}

static int test_cat_0_skip (void)
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

static int test_cat_0 (void)
{
  if (test_cat_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_cat_0");
    return 0;
  }

  /* InitISOFS for test_cat_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sdd";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_ro (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutput for cat (0) */
  const char *expected = "abcdef\n";
  {
    const char *path = "/known-2";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_cat_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_touch_0_skip (void)
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

static int test_touch_0 (void)
{
  if (test_touch_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_touch_0");
    return 0;
  }

  /* InitBasicFS for test_touch_0: create ext2 on /dev/sda1 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda";
    const char *parttype = "mbr";
    int r;
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *options = "";
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount_options (g, options, device, mountpoint);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for touch (0) */
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_touch (g, path);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    int r;
    suppress_error = 0;
    r = guestfs_exists (g, path);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_touch_0: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_sync_0_skip (void)
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

static int test_sync_0 (void)
{
  if (test_sync_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_sync_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_sync_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for sync (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_sync (g);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_mount_0_skip (void)
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

static int test_mount_0 (void)
{
  if (test_mount_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_mount_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_mount_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
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
    suppress_error = 0;
    r = guestfs_part_disk (g, device, parttype);
    if (r == -1)
      return -1;
  }
  {
    const char *fstype = "ext2";
    const char *device = "/dev/sda1";
    int r;
    suppress_error = 0;
    r = guestfs_mkfs (g, fstype, device);
    if (r == -1)
      return -1;
  }
  {
    const char *device = "/dev/sda1";
    const char *mountpoint = "/";
    int r;
    suppress_error = 0;
    r = guestfs_mount (g, device, mountpoint);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    const char *content = "new file contents";
    int r;
    suppress_error = 0;
    r = guestfs_write_file (g, path, content, 0);
    if (r == -1)
      return -1;
  }
  {
    const char *path = "/new";
    char *r;
    suppress_error = 0;
    r = guestfs_cat (g, path);
    if (r == NULL)
      return -1;
    if (STRNEQ (r, expected)) {
      fprintf (stderr, "test_mount_0: expected \"%s\" but got \"%s\"\n", expected, r);
      return -1;
    }
    free (r);
  }
  return 0;
}

static int test_set_recovery_proc_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_recovery_proc") == NULL;
  str = getenv ("SKIP_TEST_SET_RECOVERY_PROC_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_RECOVERY_PROC");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int test_set_recovery_proc_0 (void)
{
  if (test_set_recovery_proc_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_recovery_proc_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_set_recovery_proc_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for set_recovery_proc (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_set_recovery_proc (g, 1);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_get_recovery_proc (g);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_set_recovery_proc_0: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_set_direct_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_direct") == NULL;
  str = getenv ("SKIP_TEST_SET_DIRECT_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_DIRECT");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int test_set_direct_0 (void)
{
  if (test_set_direct_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_direct_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_set_direct_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for set_direct (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_set_direct (g, 0);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_get_direct (g);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "test_set_direct_0: expected false, got true\n");
      return -1;
    }
  }
  return 0;
}

static int test_set_trace_0_skip (void)
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

static int test_set_trace_0 (void)
{
  if (test_set_trace_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_trace_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_set_trace_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for set_trace (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_set_trace (g, 0);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_get_trace (g);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "test_set_trace_0: expected false, got true\n");
      return -1;
    }
  }
  return 0;
}

static int test_set_selinux_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_selinux") == NULL;
  str = getenv ("SKIP_TEST_SET_SELINUX_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_SELINUX");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int test_set_selinux_0 (void)
{
  if (test_set_selinux_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_selinux_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_set_selinux_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for set_selinux (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_set_selinux (g, 1);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_get_selinux (g);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_set_selinux_0: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_version_0_skip (void)
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

static int test_version_0 (void)
{
  if (test_version_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_version_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_version_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputStruct for version (0) */
  {
    struct guestfs_version *r;
    suppress_error = 0;
    r = guestfs_version (g);
    if (r == NULL)
      return -1;
    if (r->major != 1) {
      fprintf (stderr, "test_version_0: major was %d, expected 1\n",
               (int) r->major);
      return -1;
    }
    guestfs_free_version (r);
  }
  return 0;
}

static int test_get_pid_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "get_pid") == NULL;
  str = getenv ("SKIP_TEST_GET_PID_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_GET_PID");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int test_get_pid_0 (void)
{
  if (test_get_pid_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_pid_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_pid_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputIntOp for get_pid (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_get_pid (g);
    if (r == -1)
      return -1;
    if (! (r >= 1)) {
      fprintf (stderr, "test_get_pid_0: expected >= 1 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_get_memsize_0_skip (void)
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

static int test_get_memsize_0 (void)
{
  if (test_get_memsize_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_memsize_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_memsize_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputIntOp for get_memsize (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_get_memsize (g);
    if (r == -1)
      return -1;
    if (! (r >= 256)) {
      fprintf (stderr, "test_get_memsize_0: expected >= 256 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_set_memsize_0_skip (void)
{
  const char *str;

  str = getenv ("TEST_ONLY");
  if (str)
    return strstr (str, "set_memsize") == NULL;
  str = getenv ("SKIP_TEST_SET_MEMSIZE_0");
  if (str && STREQ (str, "1")) return 1;
  str = getenv ("SKIP_TEST_SET_MEMSIZE");
  if (str && STREQ (str, "1")) return 1;
  return 0;
}

static int test_set_memsize_0 (void)
{
  if (test_set_memsize_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_set_memsize_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_set_memsize_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputInt for set_memsize (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_set_memsize (g, 500);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_get_memsize (g);
    if (r == -1)
      return -1;
    if (r != 500) {
      fprintf (stderr, "test_set_memsize_0: expected 500 but got %d\n",               (int) r);
      return -1;
    }
  }
  return 0;
}

static int test_is_busy_0_skip (void)
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

static int test_is_busy_0 (void)
{
  if (test_is_busy_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_busy_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_is_busy_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_busy (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_is_busy (g);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "test_is_busy_0: expected false, got true\n");
      return -1;
    }
  }
  return 0;
}

static int test_is_launching_0_skip (void)
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

static int test_is_launching_0 (void)
{
  if (test_is_launching_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_launching_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_is_launching_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_launching (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_is_launching (g);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "test_is_launching_0: expected false, got true\n");
      return -1;
    }
  }
  return 0;
}

static int test_is_config_0_skip (void)
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

static int test_is_config_0 (void)
{
  if (test_is_config_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_config_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_is_config_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputFalse for is_config (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_is_config (g);
    if (r == -1)
      return -1;
    if (r) {
      fprintf (stderr, "test_is_config_0: expected false, got true\n");
      return -1;
    }
  }
  return 0;
}

static int test_is_ready_0_skip (void)
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

static int test_is_ready_0 (void)
{
  if (test_is_ready_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_is_ready_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_is_ready_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestOutputTrue for is_ready (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_is_ready (g);
    if (r == -1)
      return -1;
    if (!r) {
      fprintf (stderr, "test_is_ready_0: expected true, got false\n");
      return -1;
    }
  }
  return 0;
}

static int test_get_autosync_0_skip (void)
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

static int test_get_autosync_0 (void)
{
  if (test_get_autosync_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_autosync_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_autosync_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for get_autosync (0) */
  {
    int r;
    suppress_error = 0;
    r = guestfs_get_autosync (g);
    if (r == -1)
      return -1;
  }
  return 0;
}

static int test_get_path_0_skip (void)
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

static int test_get_path_0 (void)
{
  if (test_get_path_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_path_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_path_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for get_path (0) */
  {
    const char *r;
    suppress_error = 0;
    r = guestfs_get_path (g);
    if (r == NULL)
      return -1;
  }
  return 0;
}

static int test_get_qemu_0_skip (void)
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

static int test_get_qemu_0 (void)
{
  if (test_get_qemu_0_skip ()) {
    printf ("        %s skipped (reason: environment variable set)\n", "test_get_qemu_0");
    return 0;
  }

  /* InitNone|InitEmpty for test_get_qemu_0 */
  {
    const char *device = "/dev/sda";
    int r;
    suppress_error = 0;
    r = guestfs_blockdev_setrw (g, device);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_umount_all (g);
    if (r == -1)
      return -1;
  }
  {
    int r;
    suppress_error = 0;
    r = guestfs_lvm_remove_all (g);
    if (r == -1)
      return -1;
  }
  /* TestRun for get_qemu (0) */
  {
    const char *r;
    suppress_error = 0;
    r = guestfs_get_qemu (g);
    if (r == NULL)
      return -1;
  }
  return 0;
}

int main (int argc, char *argv[])
{
  char c = 0;
  unsigned long int n_failed = 0;
  const char *filename;
  int fd;
  int nr_tests, test_num = 0;

  setbuf (stdout, NULL);

  no_test_warnings ();

  g = guestfs_create ();
  if (g == NULL) {
    printf ("guestfs_create FAILED\n");
    exit (EXIT_FAILURE);
  }

  guestfs_set_error_handler (g, print_error, NULL);

  guestfs_set_path (g, "../appliance");

  filename = "test1.img";
  fd = open (filename, O_WRONLY|O_CREAT|O_NOCTTY|O_NONBLOCK|O_TRUNC, 0666);
  if (fd == -1) {
    perror (filename);
    exit (EXIT_FAILURE);
  }
  if (lseek (fd, 524288000, SEEK_SET) == -1) {
    perror ("lseek");
    close (fd);
    unlink (filename);
    exit (EXIT_FAILURE);
  }
  if (write (fd, &c, 1) == -1) {
    perror ("write");
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
  fd = open (filename, O_WRONLY|O_CREAT|O_NOCTTY|O_NONBLOCK|O_TRUNC, 0666);
  if (fd == -1) {
    perror (filename);
    exit (EXIT_FAILURE);
  }
  if (lseek (fd, 52428800, SEEK_SET) == -1) {
    perror ("lseek");
    close (fd);
    unlink (filename);
    exit (EXIT_FAILURE);
  }
  if (write (fd, &c, 1) == -1) {
    perror ("write");
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
  fd = open (filename, O_WRONLY|O_CREAT|O_NOCTTY|O_NONBLOCK|O_TRUNC, 0666);
  if (fd == -1) {
    perror (filename);
    exit (EXIT_FAILURE);
  }
  if (lseek (fd, 10485760, SEEK_SET) == -1) {
    perror ("lseek");
    close (fd);
    unlink (filename);
    exit (EXIT_FAILURE);
  }
  if (write (fd, &c, 1) == -1) {
    perror ("write");
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

  if (guestfs_add_drive_ro (g, "../images/test.iso") == -1) {
    printf ("guestfs_add_drive_ro ../images/test.iso FAILED\n");
    exit (EXIT_FAILURE);
  }

  if (guestfs_launch (g) == -1) {
    printf ("guestfs_launch FAILED\n");
    exit (EXIT_FAILURE);
  }

  /* Set a timeout in case qemu hangs during launch (RHBZ#505329). */
  alarm (600);

  /* Cancel previous alarm. */
  alarm (0);

  nr_tests = 251;

  test_num++;
  printf ("%3d/%3d test_initrd_cat_0\n", test_num, nr_tests);
  if (test_initrd_cat_0 () == -1) {
    printf ("test_initrd_cat_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_vgrename_0\n", test_num, nr_tests);
  if (test_vgrename_0 () == -1) {
    printf ("test_vgrename_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_lvrename_0\n", test_num, nr_tests);
  if (test_lvrename_0 () == -1) {
    printf ("test_lvrename_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_filesize_0\n", test_num, nr_tests);
  if (test_filesize_0 () == -1) {
    printf ("test_filesize_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_dd_0\n", test_num, nr_tests);
  if (test_dd_0 () == -1) {
    printf ("test_dd_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_available_0\n", test_num, nr_tests);
  if (test_available_0 () == -1) {
    printf ("test_available_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_fill_0\n", test_num, nr_tests);
  if (test_fill_0 () == -1) {
    printf ("test_fill_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_part_get_parttype_0\n", test_num, nr_tests);
  if (test_part_get_parttype_0 () == -1) {
    printf ("test_part_get_parttype_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_part_set_name_0\n", test_num, nr_tests);
  if (test_part_set_name_0 () == -1) {
    printf ("test_part_set_name_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_part_set_bootable_0\n", test_num, nr_tests);
  if (test_part_set_bootable_0 () == -1) {
    printf ("test_part_set_bootable_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_part_disk_0\n", test_num, nr_tests);
  if (test_part_disk_0 () == -1) {
    printf ("test_part_disk_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_part_disk_1\n", test_num, nr_tests);
  if (test_part_disk_1 () == -1) {
    printf ("test_part_disk_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_part_add_0\n", test_num, nr_tests);
  if (test_part_add_0 () == -1) {
    printf ("test_part_add_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_part_add_1\n", test_num, nr_tests);
  if (test_part_add_1 () == -1) {
    printf ("test_part_add_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_part_add_2\n", test_num, nr_tests);
  if (test_part_add_2 () == -1) {
    printf ("test_part_add_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_part_init_0\n", test_num, nr_tests);
  if (test_part_init_0 () == -1) {
    printf ("test_part_init_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_pread_0\n", test_num, nr_tests);
  if (test_pread_0 () == -1) {
    printf ("test_pread_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_pread_1\n", test_num, nr_tests);
  if (test_pread_1 () == -1) {
    printf ("test_pread_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkdir_mode_0\n", test_num, nr_tests);
  if (test_mkdir_mode_0 () == -1) {
    printf ("test_mkdir_mode_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_utimens_0\n", test_num, nr_tests);
  if (test_utimens_0 () == -1) {
    printf ("test_utimens_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_truncate_size_0\n", test_num, nr_tests);
  if (test_truncate_size_0 () == -1) {
    printf ("test_truncate_size_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_truncate_0\n", test_num, nr_tests);
  if (test_truncate_0 () == -1) {
    printf ("test_truncate_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_vfs_type_0\n", test_num, nr_tests);
  if (test_vfs_type_0 () == -1) {
    printf ("test_vfs_type_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_case_sensitive_path_0\n", test_num, nr_tests);
  if (test_case_sensitive_path_0 () == -1) {
    printf ("test_case_sensitive_path_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_case_sensitive_path_1\n", test_num, nr_tests);
  if (test_case_sensitive_path_1 () == -1) {
    printf ("test_case_sensitive_path_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_case_sensitive_path_2\n", test_num, nr_tests);
  if (test_case_sensitive_path_2 () == -1) {
    printf ("test_case_sensitive_path_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_case_sensitive_path_3\n", test_num, nr_tests);
  if (test_case_sensitive_path_3 () == -1) {
    printf ("test_case_sensitive_path_3 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_case_sensitive_path_4\n", test_num, nr_tests);
  if (test_case_sensitive_path_4 () == -1) {
    printf ("test_case_sensitive_path_4 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_case_sensitive_path_5\n", test_num, nr_tests);
  if (test_case_sensitive_path_5 () == -1) {
    printf ("test_case_sensitive_path_5 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_case_sensitive_path_6\n", test_num, nr_tests);
  if (test_case_sensitive_path_6 () == -1) {
    printf ("test_case_sensitive_path_6 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_echo_daemon_0\n", test_num, nr_tests);
  if (test_echo_daemon_0 () == -1) {
    printf ("test_echo_daemon_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_modprobe_0\n", test_num, nr_tests);
  if (test_modprobe_0 () == -1) {
    printf ("test_modprobe_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mke2journal_U_0\n", test_num, nr_tests);
  if (test_mke2journal_U_0 () == -1) {
    printf ("test_mke2journal_U_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mke2journal_L_0\n", test_num, nr_tests);
  if (test_mke2journal_L_0 () == -1) {
    printf ("test_mke2journal_L_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mke2journal_0\n", test_num, nr_tests);
  if (test_mke2journal_0 () == -1) {
    printf ("test_mke2journal_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkfs_b_0\n", test_num, nr_tests);
  if (test_mkfs_b_0 () == -1) {
    printf ("test_mkfs_b_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_inotify_add_watch_0\n", test_num, nr_tests);
  if (test_inotify_add_watch_0 () == -1) {
    printf ("test_inotify_add_watch_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_inotify_init_0\n", test_num, nr_tests);
  if (test_inotify_init_0 () == -1) {
    printf ("test_inotify_init_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkswap_file_0\n", test_num, nr_tests);
  if (test_mkswap_file_0 () == -1) {
    printf ("test_mkswap_file_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_swapon_uuid_0\n", test_num, nr_tests);
  if (test_swapon_uuid_0 () == -1) {
    printf ("test_swapon_uuid_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_swapon_label_0\n", test_num, nr_tests);
  if (test_swapon_label_0 () == -1) {
    printf ("test_swapon_label_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_swapon_file_0\n", test_num, nr_tests);
  if (test_swapon_file_0 () == -1) {
    printf ("test_swapon_file_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_swapon_device_0\n", test_num, nr_tests);
  if (test_swapon_device_0 () == -1) {
    printf ("test_swapon_device_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_fallocate_0\n", test_num, nr_tests);
  if (test_fallocate_0 () == -1) {
    printf ("test_fallocate_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_ln_sf_0\n", test_num, nr_tests);
  if (test_ln_sf_0 () == -1) {
    printf ("test_ln_sf_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_ln_s_0\n", test_num, nr_tests);
  if (test_ln_s_0 () == -1) {
    printf ("test_ln_s_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_ln_f_0\n", test_num, nr_tests);
  if (test_ln_f_0 () == -1) {
    printf ("test_ln_f_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_ln_0\n", test_num, nr_tests);
  if (test_ln_0 () == -1) {
    printf ("test_ln_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_realpath_0\n", test_num, nr_tests);
  if (test_realpath_0 () == -1) {
    printf ("test_realpath_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_zfgrepi_0\n", test_num, nr_tests);
  if (test_zfgrepi_0 () == -1) {
    printf ("test_zfgrepi_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_zegrepi_0\n", test_num, nr_tests);
  if (test_zegrepi_0 () == -1) {
    printf ("test_zegrepi_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_zgrepi_0\n", test_num, nr_tests);
  if (test_zgrepi_0 () == -1) {
    printf ("test_zgrepi_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_zfgrep_0\n", test_num, nr_tests);
  if (test_zfgrep_0 () == -1) {
    printf ("test_zfgrep_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_zegrep_0\n", test_num, nr_tests);
  if (test_zegrep_0 () == -1) {
    printf ("test_zegrep_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_zgrep_0\n", test_num, nr_tests);
  if (test_zgrep_0 () == -1) {
    printf ("test_zgrep_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_fgrepi_0\n", test_num, nr_tests);
  if (test_fgrepi_0 () == -1) {
    printf ("test_fgrepi_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_egrepi_0\n", test_num, nr_tests);
  if (test_egrepi_0 () == -1) {
    printf ("test_egrepi_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_grepi_0\n", test_num, nr_tests);
  if (test_grepi_0 () == -1) {
    printf ("test_grepi_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_fgrep_0\n", test_num, nr_tests);
  if (test_fgrep_0 () == -1) {
    printf ("test_fgrep_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_egrep_0\n", test_num, nr_tests);
  if (test_egrep_0 () == -1) {
    printf ("test_egrep_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_grep_0\n", test_num, nr_tests);
  if (test_grep_0 () == -1) {
    printf ("test_grep_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_grep_1\n", test_num, nr_tests);
  if (test_grep_1 () == -1) {
    printf ("test_grep_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_read_file_0\n", test_num, nr_tests);
  if (test_read_file_0 () == -1) {
    printf ("test_read_file_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mknod_c_0\n", test_num, nr_tests);
  if (test_mknod_c_0 () == -1) {
    printf ("test_mknod_c_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mknod_b_0\n", test_num, nr_tests);
  if (test_mknod_b_0 () == -1) {
    printf ("test_mknod_b_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkfifo_0\n", test_num, nr_tests);
  if (test_mkfifo_0 () == -1) {
    printf ("test_mkfifo_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mknod_0\n", test_num, nr_tests);
  if (test_mknod_0 () == -1) {
    printf ("test_mknod_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mknod_1\n", test_num, nr_tests);
  if (test_mknod_1 () == -1) {
    printf ("test_mknod_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkswap_U_0\n", test_num, nr_tests);
  if (test_mkswap_U_0 () == -1) {
    printf ("test_mkswap_U_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkswap_L_0\n", test_num, nr_tests);
  if (test_mkswap_L_0 () == -1) {
    printf ("test_mkswap_L_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkswap_0\n", test_num, nr_tests);
  if (test_mkswap_0 () == -1) {
    printf ("test_mkswap_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_initrd_list_0\n", test_num, nr_tests);
  if (test_initrd_list_0 () == -1) {
    printf ("test_initrd_list_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_du_0\n", test_num, nr_tests);
  if (test_du_0 () == -1) {
    printf ("test_du_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_tail_n_0\n", test_num, nr_tests);
  if (test_tail_n_0 () == -1) {
    printf ("test_tail_n_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_tail_n_1\n", test_num, nr_tests);
  if (test_tail_n_1 () == -1) {
    printf ("test_tail_n_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_tail_n_2\n", test_num, nr_tests);
  if (test_tail_n_2 () == -1) {
    printf ("test_tail_n_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_tail_0\n", test_num, nr_tests);
  if (test_tail_0 () == -1) {
    printf ("test_tail_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_head_n_0\n", test_num, nr_tests);
  if (test_head_n_0 () == -1) {
    printf ("test_head_n_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_head_n_1\n", test_num, nr_tests);
  if (test_head_n_1 () == -1) {
    printf ("test_head_n_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_head_n_2\n", test_num, nr_tests);
  if (test_head_n_2 () == -1) {
    printf ("test_head_n_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_head_0\n", test_num, nr_tests);
  if (test_head_0 () == -1) {
    printf ("test_head_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_wc_c_0\n", test_num, nr_tests);
  if (test_wc_c_0 () == -1) {
    printf ("test_wc_c_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_wc_w_0\n", test_num, nr_tests);
  if (test_wc_w_0 () == -1) {
    printf ("test_wc_w_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_wc_l_0\n", test_num, nr_tests);
  if (test_wc_l_0 () == -1) {
    printf ("test_wc_l_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkdtemp_0\n", test_num, nr_tests);
  if (test_mkdtemp_0 () == -1) {
    printf ("test_mkdtemp_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_scrub_file_0\n", test_num, nr_tests);
  if (test_scrub_file_0 () == -1) {
    printf ("test_scrub_file_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_scrub_device_0\n", test_num, nr_tests);
  if (test_scrub_device_0 () == -1) {
    printf ("test_scrub_device_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_glob_expand_0\n", test_num, nr_tests);
  if (test_glob_expand_0 () == -1) {
    printf ("test_glob_expand_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_glob_expand_1\n", test_num, nr_tests);
  if (test_glob_expand_1 () == -1) {
    printf ("test_glob_expand_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_glob_expand_2\n", test_num, nr_tests);
  if (test_glob_expand_2 () == -1) {
    printf ("test_glob_expand_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_ntfs_3g_probe_0\n", test_num, nr_tests);
  if (test_ntfs_3g_probe_0 () == -1) {
    printf ("test_ntfs_3g_probe_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_ntfs_3g_probe_1\n", test_num, nr_tests);
  if (test_ntfs_3g_probe_1 () == -1) {
    printf ("test_ntfs_3g_probe_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_sleep_0\n", test_num, nr_tests);
  if (test_sleep_0 () == -1) {
    printf ("test_sleep_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_find_0\n", test_num, nr_tests);
  if (test_find_0 () == -1) {
    printf ("test_find_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_find_1\n", test_num, nr_tests);
  if (test_find_1 () == -1) {
    printf ("test_find_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_find_2\n", test_num, nr_tests);
  if (test_find_2 () == -1) {
    printf ("test_find_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_lvresize_0\n", test_num, nr_tests);
  if (test_lvresize_0 () == -1) {
    printf ("test_lvresize_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_zerofree_0\n", test_num, nr_tests);
  if (test_zerofree_0 () == -1) {
    printf ("test_zerofree_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_hexdump_0\n", test_num, nr_tests);
  if (test_hexdump_0 () == -1) {
    printf ("test_hexdump_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_hexdump_1\n", test_num, nr_tests);
  if (test_hexdump_1 () == -1) {
    printf ("test_hexdump_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_strings_e_0\n", test_num, nr_tests);
  if (test_strings_e_0 () == -1) {
    printf ("test_strings_e_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_strings_e_1\n", test_num, nr_tests);
  if (test_strings_e_1 () == -1) {
    printf ("test_strings_e_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_strings_0\n", test_num, nr_tests);
  if (test_strings_0 () == -1) {
    printf ("test_strings_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_strings_1\n", test_num, nr_tests);
  if (test_strings_1 () == -1) {
    printf ("test_strings_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_equal_0\n", test_num, nr_tests);
  if (test_equal_0 () == -1) {
    printf ("test_equal_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_equal_1\n", test_num, nr_tests);
  if (test_equal_1 () == -1) {
    printf ("test_equal_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_equal_2\n", test_num, nr_tests);
  if (test_equal_2 () == -1) {
    printf ("test_equal_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_ping_daemon_0\n", test_num, nr_tests);
  if (test_ping_daemon_0 () == -1) {
    printf ("test_ping_daemon_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_dmesg_0\n", test_num, nr_tests);
  if (test_dmesg_0 () == -1) {
    printf ("test_dmesg_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_drop_caches_0\n", test_num, nr_tests);
  if (test_drop_caches_0 () == -1) {
    printf ("test_drop_caches_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mv_0\n", test_num, nr_tests);
  if (test_mv_0 () == -1) {
    printf ("test_mv_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mv_1\n", test_num, nr_tests);
  if (test_mv_1 () == -1) {
    printf ("test_mv_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_cp_a_0\n", test_num, nr_tests);
  if (test_cp_a_0 () == -1) {
    printf ("test_cp_a_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_cp_0\n", test_num, nr_tests);
  if (test_cp_0 () == -1) {
    printf ("test_cp_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_cp_1\n", test_num, nr_tests);
  if (test_cp_1 () == -1) {
    printf ("test_cp_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_cp_2\n", test_num, nr_tests);
  if (test_cp_2 () == -1) {
    printf ("test_cp_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_grub_install_0\n", test_num, nr_tests);
  if (test_grub_install_0 () == -1) {
    printf ("test_grub_install_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_zero_0\n", test_num, nr_tests);
  if (test_zero_0 () == -1) {
    printf ("test_zero_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_fsck_0\n", test_num, nr_tests);
  if (test_fsck_0 () == -1) {
    printf ("test_fsck_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_fsck_1\n", test_num, nr_tests);
  if (test_fsck_1 () == -1) {
    printf ("test_fsck_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_set_e2uuid_0\n", test_num, nr_tests);
  if (test_set_e2uuid_0 () == -1) {
    printf ("test_set_e2uuid_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_set_e2uuid_1\n", test_num, nr_tests);
  if (test_set_e2uuid_1 () == -1) {
    printf ("test_set_e2uuid_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_set_e2uuid_2\n", test_num, nr_tests);
  if (test_set_e2uuid_2 () == -1) {
    printf ("test_set_e2uuid_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_set_e2uuid_3\n", test_num, nr_tests);
  if (test_set_e2uuid_3 () == -1) {
    printf ("test_set_e2uuid_3 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_set_e2label_0\n", test_num, nr_tests);
  if (test_set_e2label_0 () == -1) {
    printf ("test_set_e2label_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_pvremove_0\n", test_num, nr_tests);
  if (test_pvremove_0 () == -1) {
    printf ("test_pvremove_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_pvremove_1\n", test_num, nr_tests);
  if (test_pvremove_1 () == -1) {
    printf ("test_pvremove_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_pvremove_2\n", test_num, nr_tests);
  if (test_pvremove_2 () == -1) {
    printf ("test_pvremove_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_vgremove_0\n", test_num, nr_tests);
  if (test_vgremove_0 () == -1) {
    printf ("test_vgremove_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_vgremove_1\n", test_num, nr_tests);
  if (test_vgremove_1 () == -1) {
    printf ("test_vgremove_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_lvremove_0\n", test_num, nr_tests);
  if (test_lvremove_0 () == -1) {
    printf ("test_lvremove_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_lvremove_1\n", test_num, nr_tests);
  if (test_lvremove_1 () == -1) {
    printf ("test_lvremove_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_lvremove_2\n", test_num, nr_tests);
  if (test_lvremove_2 () == -1) {
    printf ("test_lvremove_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mount_ro_0\n", test_num, nr_tests);
  if (test_mount_ro_0 () == -1) {
    printf ("test_mount_ro_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mount_ro_1\n", test_num, nr_tests);
  if (test_mount_ro_1 () == -1) {
    printf ("test_mount_ro_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_tgz_in_0\n", test_num, nr_tests);
  if (test_tgz_in_0 () == -1) {
    printf ("test_tgz_in_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_tar_in_0\n", test_num, nr_tests);
  if (test_tar_in_0 () == -1) {
    printf ("test_tar_in_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_checksum_0\n", test_num, nr_tests);
  if (test_checksum_0 () == -1) {
    printf ("test_checksum_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_checksum_1\n", test_num, nr_tests);
  if (test_checksum_1 () == -1) {
    printf ("test_checksum_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_checksum_2\n", test_num, nr_tests);
  if (test_checksum_2 () == -1) {
    printf ("test_checksum_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_checksum_3\n", test_num, nr_tests);
  if (test_checksum_3 () == -1) {
    printf ("test_checksum_3 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_checksum_4\n", test_num, nr_tests);
  if (test_checksum_4 () == -1) {
    printf ("test_checksum_4 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_checksum_5\n", test_num, nr_tests);
  if (test_checksum_5 () == -1) {
    printf ("test_checksum_5 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_checksum_6\n", test_num, nr_tests);
  if (test_checksum_6 () == -1) {
    printf ("test_checksum_6 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_checksum_7\n", test_num, nr_tests);
  if (test_checksum_7 () == -1) {
    printf ("test_checksum_7 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_download_0\n", test_num, nr_tests);
  if (test_download_0 () == -1) {
    printf ("test_download_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_upload_0\n", test_num, nr_tests);
  if (test_upload_0 () == -1) {
    printf ("test_upload_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_blockdev_rereadpt_0\n", test_num, nr_tests);
  if (test_blockdev_rereadpt_0 () == -1) {
    printf ("test_blockdev_rereadpt_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_blockdev_flushbufs_0\n", test_num, nr_tests);
  if (test_blockdev_flushbufs_0 () == -1) {
    printf ("test_blockdev_flushbufs_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_blockdev_getsize64_0\n", test_num, nr_tests);
  if (test_blockdev_getsize64_0 () == -1) {
    printf ("test_blockdev_getsize64_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_blockdev_getsz_0\n", test_num, nr_tests);
  if (test_blockdev_getsz_0 () == -1) {
    printf ("test_blockdev_getsz_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_blockdev_getbsz_0\n", test_num, nr_tests);
  if (test_blockdev_getbsz_0 () == -1) {
    printf ("test_blockdev_getbsz_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_blockdev_getss_0\n", test_num, nr_tests);
  if (test_blockdev_getss_0 () == -1) {
    printf ("test_blockdev_getss_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_blockdev_getro_0\n", test_num, nr_tests);
  if (test_blockdev_getro_0 () == -1) {
    printf ("test_blockdev_getro_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_blockdev_setrw_0\n", test_num, nr_tests);
  if (test_blockdev_setrw_0 () == -1) {
    printf ("test_blockdev_setrw_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_blockdev_setro_0\n", test_num, nr_tests);
  if (test_blockdev_setro_0 () == -1) {
    printf ("test_blockdev_setro_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_statvfs_0\n", test_num, nr_tests);
  if (test_statvfs_0 () == -1) {
    printf ("test_statvfs_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_lstat_0\n", test_num, nr_tests);
  if (test_lstat_0 () == -1) {
    printf ("test_lstat_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_stat_0\n", test_num, nr_tests);
  if (test_stat_0 () == -1) {
    printf ("test_stat_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_lines_0\n", test_num, nr_tests);
  if (test_command_lines_0 () == -1) {
    printf ("test_command_lines_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_lines_1\n", test_num, nr_tests);
  if (test_command_lines_1 () == -1) {
    printf ("test_command_lines_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_lines_2\n", test_num, nr_tests);
  if (test_command_lines_2 () == -1) {
    printf ("test_command_lines_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_lines_3\n", test_num, nr_tests);
  if (test_command_lines_3 () == -1) {
    printf ("test_command_lines_3 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_lines_4\n", test_num, nr_tests);
  if (test_command_lines_4 () == -1) {
    printf ("test_command_lines_4 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_lines_5\n", test_num, nr_tests);
  if (test_command_lines_5 () == -1) {
    printf ("test_command_lines_5 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_lines_6\n", test_num, nr_tests);
  if (test_command_lines_6 () == -1) {
    printf ("test_command_lines_6 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_lines_7\n", test_num, nr_tests);
  if (test_command_lines_7 () == -1) {
    printf ("test_command_lines_7 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_lines_8\n", test_num, nr_tests);
  if (test_command_lines_8 () == -1) {
    printf ("test_command_lines_8 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_lines_9\n", test_num, nr_tests);
  if (test_command_lines_9 () == -1) {
    printf ("test_command_lines_9 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_lines_10\n", test_num, nr_tests);
  if (test_command_lines_10 () == -1) {
    printf ("test_command_lines_10 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_0\n", test_num, nr_tests);
  if (test_command_0 () == -1) {
    printf ("test_command_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_1\n", test_num, nr_tests);
  if (test_command_1 () == -1) {
    printf ("test_command_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_2\n", test_num, nr_tests);
  if (test_command_2 () == -1) {
    printf ("test_command_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_3\n", test_num, nr_tests);
  if (test_command_3 () == -1) {
    printf ("test_command_3 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_4\n", test_num, nr_tests);
  if (test_command_4 () == -1) {
    printf ("test_command_4 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_5\n", test_num, nr_tests);
  if (test_command_5 () == -1) {
    printf ("test_command_5 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_6\n", test_num, nr_tests);
  if (test_command_6 () == -1) {
    printf ("test_command_6 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_7\n", test_num, nr_tests);
  if (test_command_7 () == -1) {
    printf ("test_command_7 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_8\n", test_num, nr_tests);
  if (test_command_8 () == -1) {
    printf ("test_command_8 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_9\n", test_num, nr_tests);
  if (test_command_9 () == -1) {
    printf ("test_command_9 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_10\n", test_num, nr_tests);
  if (test_command_10 () == -1) {
    printf ("test_command_10 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_command_11\n", test_num, nr_tests);
  if (test_command_11 () == -1) {
    printf ("test_command_11 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_file_0\n", test_num, nr_tests);
  if (test_file_0 () == -1) {
    printf ("test_file_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_file_1\n", test_num, nr_tests);
  if (test_file_1 () == -1) {
    printf ("test_file_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_file_2\n", test_num, nr_tests);
  if (test_file_2 () == -1) {
    printf ("test_file_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_umount_all_0\n", test_num, nr_tests);
  if (test_umount_all_0 () == -1) {
    printf ("test_umount_all_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_umount_all_1\n", test_num, nr_tests);
  if (test_umount_all_1 () == -1) {
    printf ("test_umount_all_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mounts_0\n", test_num, nr_tests);
  if (test_mounts_0 () == -1) {
    printf ("test_mounts_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_umount_0\n", test_num, nr_tests);
  if (test_umount_0 () == -1) {
    printf ("test_umount_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_umount_1\n", test_num, nr_tests);
  if (test_umount_1 () == -1) {
    printf ("test_umount_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_write_file_0\n", test_num, nr_tests);
  if (test_write_file_0 () == -1) {
    printf ("test_write_file_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_write_file_1\n", test_num, nr_tests);
  if (test_write_file_1 () == -1) {
    printf ("test_write_file_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_write_file_2\n", test_num, nr_tests);
  if (test_write_file_2 () == -1) {
    printf ("test_write_file_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_write_file_3\n", test_num, nr_tests);
  if (test_write_file_3 () == -1) {
    printf ("test_write_file_3 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_write_file_4\n", test_num, nr_tests);
  if (test_write_file_4 () == -1) {
    printf ("test_write_file_4 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_write_file_5\n", test_num, nr_tests);
  if (test_write_file_5 () == -1) {
    printf ("test_write_file_5 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkfs_0\n", test_num, nr_tests);
  if (test_mkfs_0 () == -1) {
    printf ("test_mkfs_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_lvcreate_0\n", test_num, nr_tests);
  if (test_lvcreate_0 () == -1) {
    printf ("test_lvcreate_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_vgcreate_0\n", test_num, nr_tests);
  if (test_vgcreate_0 () == -1) {
    printf ("test_vgcreate_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_pvcreate_0\n", test_num, nr_tests);
  if (test_pvcreate_0 () == -1) {
    printf ("test_pvcreate_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_is_dir_0\n", test_num, nr_tests);
  if (test_is_dir_0 () == -1) {
    printf ("test_is_dir_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_is_dir_1\n", test_num, nr_tests);
  if (test_is_dir_1 () == -1) {
    printf ("test_is_dir_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_is_file_0\n", test_num, nr_tests);
  if (test_is_file_0 () == -1) {
    printf ("test_is_file_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_is_file_1\n", test_num, nr_tests);
  if (test_is_file_1 () == -1) {
    printf ("test_is_file_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_exists_0\n", test_num, nr_tests);
  if (test_exists_0 () == -1) {
    printf ("test_exists_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_exists_1\n", test_num, nr_tests);
  if (test_exists_1 () == -1) {
    printf ("test_exists_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkdir_p_0\n", test_num, nr_tests);
  if (test_mkdir_p_0 () == -1) {
    printf ("test_mkdir_p_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkdir_p_1\n", test_num, nr_tests);
  if (test_mkdir_p_1 () == -1) {
    printf ("test_mkdir_p_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkdir_p_2\n", test_num, nr_tests);
  if (test_mkdir_p_2 () == -1) {
    printf ("test_mkdir_p_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkdir_p_3\n", test_num, nr_tests);
  if (test_mkdir_p_3 () == -1) {
    printf ("test_mkdir_p_3 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkdir_p_4\n", test_num, nr_tests);
  if (test_mkdir_p_4 () == -1) {
    printf ("test_mkdir_p_4 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkdir_0\n", test_num, nr_tests);
  if (test_mkdir_0 () == -1) {
    printf ("test_mkdir_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mkdir_1\n", test_num, nr_tests);
  if (test_mkdir_1 () == -1) {
    printf ("test_mkdir_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_rm_rf_0\n", test_num, nr_tests);
  if (test_rm_rf_0 () == -1) {
    printf ("test_rm_rf_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_rmdir_0\n", test_num, nr_tests);
  if (test_rmdir_0 () == -1) {
    printf ("test_rmdir_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_rmdir_1\n", test_num, nr_tests);
  if (test_rmdir_1 () == -1) {
    printf ("test_rmdir_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_rmdir_2\n", test_num, nr_tests);
  if (test_rmdir_2 () == -1) {
    printf ("test_rmdir_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_rm_0\n", test_num, nr_tests);
  if (test_rm_0 () == -1) {
    printf ("test_rm_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_rm_1\n", test_num, nr_tests);
  if (test_rm_1 () == -1) {
    printf ("test_rm_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_rm_2\n", test_num, nr_tests);
  if (test_rm_2 () == -1) {
    printf ("test_rm_2 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_read_lines_0\n", test_num, nr_tests);
  if (test_read_lines_0 () == -1) {
    printf ("test_read_lines_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_read_lines_1\n", test_num, nr_tests);
  if (test_read_lines_1 () == -1) {
    printf ("test_read_lines_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_lvs_0\n", test_num, nr_tests);
  if (test_lvs_0 () == -1) {
    printf ("test_lvs_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_lvs_1\n", test_num, nr_tests);
  if (test_lvs_1 () == -1) {
    printf ("test_lvs_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_vgs_0\n", test_num, nr_tests);
  if (test_vgs_0 () == -1) {
    printf ("test_vgs_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_vgs_1\n", test_num, nr_tests);
  if (test_vgs_1 () == -1) {
    printf ("test_vgs_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_pvs_0\n", test_num, nr_tests);
  if (test_pvs_0 () == -1) {
    printf ("test_pvs_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_pvs_1\n", test_num, nr_tests);
  if (test_pvs_1 () == -1) {
    printf ("test_pvs_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_list_partitions_0\n", test_num, nr_tests);
  if (test_list_partitions_0 () == -1) {
    printf ("test_list_partitions_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_list_partitions_1\n", test_num, nr_tests);
  if (test_list_partitions_1 () == -1) {
    printf ("test_list_partitions_1 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_list_devices_0\n", test_num, nr_tests);
  if (test_list_devices_0 () == -1) {
    printf ("test_list_devices_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_ls_0\n", test_num, nr_tests);
  if (test_ls_0 () == -1) {
    printf ("test_ls_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_cat_0\n", test_num, nr_tests);
  if (test_cat_0 () == -1) {
    printf ("test_cat_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_touch_0\n", test_num, nr_tests);
  if (test_touch_0 () == -1) {
    printf ("test_touch_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_sync_0\n", test_num, nr_tests);
  if (test_sync_0 () == -1) {
    printf ("test_sync_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_mount_0\n", test_num, nr_tests);
  if (test_mount_0 () == -1) {
    printf ("test_mount_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_set_recovery_proc_0\n", test_num, nr_tests);
  if (test_set_recovery_proc_0 () == -1) {
    printf ("test_set_recovery_proc_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_set_direct_0\n", test_num, nr_tests);
  if (test_set_direct_0 () == -1) {
    printf ("test_set_direct_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_set_trace_0\n", test_num, nr_tests);
  if (test_set_trace_0 () == -1) {
    printf ("test_set_trace_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_set_selinux_0\n", test_num, nr_tests);
  if (test_set_selinux_0 () == -1) {
    printf ("test_set_selinux_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_version_0\n", test_num, nr_tests);
  if (test_version_0 () == -1) {
    printf ("test_version_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_get_pid_0\n", test_num, nr_tests);
  if (test_get_pid_0 () == -1) {
    printf ("test_get_pid_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_get_memsize_0\n", test_num, nr_tests);
  if (test_get_memsize_0 () == -1) {
    printf ("test_get_memsize_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_set_memsize_0\n", test_num, nr_tests);
  if (test_set_memsize_0 () == -1) {
    printf ("test_set_memsize_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_is_busy_0\n", test_num, nr_tests);
  if (test_is_busy_0 () == -1) {
    printf ("test_is_busy_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_is_launching_0\n", test_num, nr_tests);
  if (test_is_launching_0 () == -1) {
    printf ("test_is_launching_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_is_config_0\n", test_num, nr_tests);
  if (test_is_config_0 () == -1) {
    printf ("test_is_config_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_is_ready_0\n", test_num, nr_tests);
  if (test_is_ready_0 () == -1) {
    printf ("test_is_ready_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_get_autosync_0\n", test_num, nr_tests);
  if (test_get_autosync_0 () == -1) {
    printf ("test_get_autosync_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_get_path_0\n", test_num, nr_tests);
  if (test_get_path_0 () == -1) {
    printf ("test_get_path_0 FAILED\n");
    n_failed++;
  }
  test_num++;
  printf ("%3d/%3d test_get_qemu_0\n", test_num, nr_tests);
  if (test_get_qemu_0 () == -1) {
    printf ("test_get_qemu_0 FAILED\n");
    n_failed++;
  }

  guestfs_close (g);
  unlink ("test1.img");
  unlink ("test2.img");
  unlink ("test3.img");

  if (n_failed > 0) {
    printf ("***** %lu / %d tests FAILED *****\n", n_failed, nr_tests);
    exit (EXIT_FAILURE);
  }

  exit (EXIT_SUCCESS);
}
