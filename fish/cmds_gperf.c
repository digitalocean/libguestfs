/* ANSI-C code produced by gperf version 3.0.4 */
/* Command-line: gperf -t cmds_gperf.gperf  */
/* Computed positions: -k'1-14' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 29 "cmds_gperf.gperf"


#include <config.h>

#include <stdlib.h>
#include <string.h>

#include "cmds_gperf.h"

extern struct command_entry add_cdrom_cmd_entry;
extern struct command_entry add_domain_cmd_entry;
extern struct command_entry add_drive_cmd_entry;
extern struct command_entry add_drive_opts_cmd_entry;
extern struct command_entry add_drive_ro_cmd_entry;
extern struct command_entry add_drive_ro_with_if_cmd_entry;
extern struct command_entry add_drive_with_if_cmd_entry;
extern struct command_entry alloc_cmd_entry;
extern struct command_entry aug_clear_cmd_entry;
extern struct command_entry aug_close_cmd_entry;
extern struct command_entry aug_defnode_cmd_entry;
extern struct command_entry aug_defvar_cmd_entry;
extern struct command_entry aug_get_cmd_entry;
extern struct command_entry aug_init_cmd_entry;
extern struct command_entry aug_insert_cmd_entry;
extern struct command_entry aug_load_cmd_entry;
extern struct command_entry aug_ls_cmd_entry;
extern struct command_entry aug_match_cmd_entry;
extern struct command_entry aug_mv_cmd_entry;
extern struct command_entry aug_rm_cmd_entry;
extern struct command_entry aug_save_cmd_entry;
extern struct command_entry aug_set_cmd_entry;
extern struct command_entry available_cmd_entry;
extern struct command_entry available_all_groups_cmd_entry;
extern struct command_entry base64_in_cmd_entry;
extern struct command_entry base64_out_cmd_entry;
extern struct command_entry blockdev_flushbufs_cmd_entry;
extern struct command_entry blockdev_getbsz_cmd_entry;
extern struct command_entry blockdev_getro_cmd_entry;
extern struct command_entry blockdev_getsize64_cmd_entry;
extern struct command_entry blockdev_getss_cmd_entry;
extern struct command_entry blockdev_getsz_cmd_entry;
extern struct command_entry blockdev_rereadpt_cmd_entry;
extern struct command_entry blockdev_setbsz_cmd_entry;
extern struct command_entry blockdev_setro_cmd_entry;
extern struct command_entry blockdev_setrw_cmd_entry;
extern struct command_entry btrfs_filesystem_resize_cmd_entry;
extern struct command_entry case_sensitive_path_cmd_entry;
extern struct command_entry cat_cmd_entry;
extern struct command_entry checksum_cmd_entry;
extern struct command_entry checksum_device_cmd_entry;
extern struct command_entry checksums_out_cmd_entry;
extern struct command_entry chmod_cmd_entry;
extern struct command_entry chown_cmd_entry;
extern struct command_entry command_cmd_entry;
extern struct command_entry command_lines_cmd_entry;
extern struct command_entry compress_device_out_cmd_entry;
extern struct command_entry compress_out_cmd_entry;
extern struct command_entry config_cmd_entry;
extern struct command_entry copy_device_to_device_cmd_entry;
extern struct command_entry copy_device_to_file_cmd_entry;
extern struct command_entry copy_file_to_device_cmd_entry;
extern struct command_entry copy_file_to_file_cmd_entry;
extern struct command_entry copy_in_cmd_entry;
extern struct command_entry copy_out_cmd_entry;
extern struct command_entry copy_size_cmd_entry;
extern struct command_entry cp_cmd_entry;
extern struct command_entry cp_a_cmd_entry;
extern struct command_entry dd_cmd_entry;
extern struct command_entry debug_cmd_entry;
extern struct command_entry debug_cmdline_cmd_entry;
extern struct command_entry debug_drives_cmd_entry;
extern struct command_entry debug_upload_cmd_entry;
extern struct command_entry df_cmd_entry;
extern struct command_entry df_h_cmd_entry;
extern struct command_entry display_cmd_entry;
extern struct command_entry dmesg_cmd_entry;
extern struct command_entry download_cmd_entry;
extern struct command_entry download_offset_cmd_entry;
extern struct command_entry drop_caches_cmd_entry;
extern struct command_entry du_cmd_entry;
extern struct command_entry e2fsck_f_cmd_entry;
extern struct command_entry echo_cmd_entry;
extern struct command_entry echo_daemon_cmd_entry;
extern struct command_entry edit_cmd_entry;
extern struct command_entry egrep_cmd_entry;
extern struct command_entry egrepi_cmd_entry;
extern struct command_entry equal_cmd_entry;
extern struct command_entry exists_cmd_entry;
extern struct command_entry fallocate_cmd_entry;
extern struct command_entry fallocate64_cmd_entry;
extern struct command_entry fgrep_cmd_entry;
extern struct command_entry fgrepi_cmd_entry;
extern struct command_entry file_cmd_entry;
extern struct command_entry file_architecture_cmd_entry;
extern struct command_entry filesize_cmd_entry;
extern struct command_entry fill_cmd_entry;
extern struct command_entry fill_pattern_cmd_entry;
extern struct command_entry find_cmd_entry;
extern struct command_entry find0_cmd_entry;
extern struct command_entry findfs_label_cmd_entry;
extern struct command_entry findfs_uuid_cmd_entry;
extern struct command_entry fsck_cmd_entry;
extern struct command_entry get_append_cmd_entry;
extern struct command_entry get_attach_method_cmd_entry;
extern struct command_entry get_autosync_cmd_entry;
extern struct command_entry get_direct_cmd_entry;
extern struct command_entry get_e2label_cmd_entry;
extern struct command_entry get_e2uuid_cmd_entry;
extern struct command_entry get_memsize_cmd_entry;
extern struct command_entry get_network_cmd_entry;
extern struct command_entry get_path_cmd_entry;
extern struct command_entry get_pgroup_cmd_entry;
extern struct command_entry get_pid_cmd_entry;
extern struct command_entry get_qemu_cmd_entry;
extern struct command_entry get_recovery_proc_cmd_entry;
extern struct command_entry get_selinux_cmd_entry;
extern struct command_entry get_smp_cmd_entry;
extern struct command_entry get_state_cmd_entry;
extern struct command_entry get_trace_cmd_entry;
extern struct command_entry get_umask_cmd_entry;
extern struct command_entry get_verbose_cmd_entry;
extern struct command_entry getcon_cmd_entry;
extern struct command_entry getxattr_cmd_entry;
extern struct command_entry getxattrs_cmd_entry;
extern struct command_entry glob_cmd_entry;
extern struct command_entry glob_expand_cmd_entry;
extern struct command_entry grep_cmd_entry;
extern struct command_entry grepi_cmd_entry;
extern struct command_entry grub_install_cmd_entry;
extern struct command_entry head_cmd_entry;
extern struct command_entry head_n_cmd_entry;
extern struct command_entry hexdump_cmd_entry;
extern struct command_entry hexedit_cmd_entry;
extern struct command_entry initrd_cat_cmd_entry;
extern struct command_entry initrd_list_cmd_entry;
extern struct command_entry inotify_add_watch_cmd_entry;
extern struct command_entry inotify_close_cmd_entry;
extern struct command_entry inotify_files_cmd_entry;
extern struct command_entry inotify_init_cmd_entry;
extern struct command_entry inotify_read_cmd_entry;
extern struct command_entry inotify_rm_watch_cmd_entry;
extern struct command_entry inspect_get_arch_cmd_entry;
extern struct command_entry inspect_get_distro_cmd_entry;
extern struct command_entry inspect_get_drive_mappings_cmd_entry;
extern struct command_entry inspect_get_filesystems_cmd_entry;
extern struct command_entry inspect_get_format_cmd_entry;
extern struct command_entry inspect_get_hostname_cmd_entry;
extern struct command_entry inspect_get_icon_cmd_entry;
extern struct command_entry inspect_get_major_version_cmd_entry;
extern struct command_entry inspect_get_minor_version_cmd_entry;
extern struct command_entry inspect_get_mountpoints_cmd_entry;
extern struct command_entry inspect_get_package_format_cmd_entry;
extern struct command_entry inspect_get_package_management_cmd_entry;
extern struct command_entry inspect_get_product_name_cmd_entry;
extern struct command_entry inspect_get_product_variant_cmd_entry;
extern struct command_entry inspect_get_roots_cmd_entry;
extern struct command_entry inspect_get_type_cmd_entry;
extern struct command_entry inspect_get_windows_current_control_set_cmd_entry;
extern struct command_entry inspect_get_windows_systemroot_cmd_entry;
extern struct command_entry inspect_is_live_cmd_entry;
extern struct command_entry inspect_is_multipart_cmd_entry;
extern struct command_entry inspect_is_netinst_cmd_entry;
extern struct command_entry inspect_list_applications_cmd_entry;
extern struct command_entry inspect_os_cmd_entry;
extern struct command_entry is_blockdev_cmd_entry;
extern struct command_entry is_busy_cmd_entry;
extern struct command_entry is_chardev_cmd_entry;
extern struct command_entry is_config_cmd_entry;
extern struct command_entry is_dir_cmd_entry;
extern struct command_entry is_fifo_cmd_entry;
extern struct command_entry is_file_cmd_entry;
extern struct command_entry is_launching_cmd_entry;
extern struct command_entry is_lv_cmd_entry;
extern struct command_entry is_ready_cmd_entry;
extern struct command_entry is_socket_cmd_entry;
extern struct command_entry is_symlink_cmd_entry;
extern struct command_entry is_zero_cmd_entry;
extern struct command_entry is_zero_device_cmd_entry;
extern struct command_entry kill_subprocess_cmd_entry;
extern struct command_entry launch_cmd_entry;
extern struct command_entry lcd_cmd_entry;
extern struct command_entry lchown_cmd_entry;
extern struct command_entry lgetxattr_cmd_entry;
extern struct command_entry lgetxattrs_cmd_entry;
extern struct command_entry list_9p_cmd_entry;
extern struct command_entry list_devices_cmd_entry;
extern struct command_entry list_dm_devices_cmd_entry;
extern struct command_entry list_filesystems_cmd_entry;
extern struct command_entry list_partitions_cmd_entry;
extern struct command_entry ll_cmd_entry;
extern struct command_entry ln_cmd_entry;
extern struct command_entry ln_f_cmd_entry;
extern struct command_entry ln_s_cmd_entry;
extern struct command_entry ln_sf_cmd_entry;
extern struct command_entry lremovexattr_cmd_entry;
extern struct command_entry ls_cmd_entry;
extern struct command_entry lsetxattr_cmd_entry;
extern struct command_entry lstat_cmd_entry;
extern struct command_entry lstatlist_cmd_entry;
extern struct command_entry luks_add_key_cmd_entry;
extern struct command_entry luks_close_cmd_entry;
extern struct command_entry luks_format_cmd_entry;
extern struct command_entry luks_format_cipher_cmd_entry;
extern struct command_entry luks_kill_slot_cmd_entry;
extern struct command_entry luks_open_cmd_entry;
extern struct command_entry luks_open_ro_cmd_entry;
extern struct command_entry lvcreate_cmd_entry;
extern struct command_entry lvm_canonical_lv_name_cmd_entry;
extern struct command_entry lvm_clear_filter_cmd_entry;
extern struct command_entry lvm_remove_all_cmd_entry;
extern struct command_entry lvm_set_filter_cmd_entry;
extern struct command_entry lvremove_cmd_entry;
extern struct command_entry lvrename_cmd_entry;
extern struct command_entry lvresize_cmd_entry;
extern struct command_entry lvresize_free_cmd_entry;
extern struct command_entry lvs_cmd_entry;
extern struct command_entry lvs_full_cmd_entry;
extern struct command_entry lvuuid_cmd_entry;
extern struct command_entry lxattrlist_cmd_entry;
extern struct command_entry man_cmd_entry;
extern struct command_entry mkdir_cmd_entry;
extern struct command_entry mkdir_mode_cmd_entry;
extern struct command_entry mkdir_p_cmd_entry;
extern struct command_entry mkdtemp_cmd_entry;
extern struct command_entry mke2fs_J_cmd_entry;
extern struct command_entry mke2fs_JL_cmd_entry;
extern struct command_entry mke2fs_JU_cmd_entry;
extern struct command_entry mke2journal_cmd_entry;
extern struct command_entry mke2journal_L_cmd_entry;
extern struct command_entry mke2journal_U_cmd_entry;
extern struct command_entry mkfifo_cmd_entry;
extern struct command_entry mkfs_cmd_entry;
extern struct command_entry mkfs_b_cmd_entry;
extern struct command_entry mkfs_opts_cmd_entry;
extern struct command_entry mkmountpoint_cmd_entry;
extern struct command_entry mknod_cmd_entry;
extern struct command_entry mknod_b_cmd_entry;
extern struct command_entry mknod_c_cmd_entry;
extern struct command_entry mkswap_cmd_entry;
extern struct command_entry mkswap_L_cmd_entry;
extern struct command_entry mkswap_U_cmd_entry;
extern struct command_entry mkswap_file_cmd_entry;
extern struct command_entry modprobe_cmd_entry;
extern struct command_entry more_cmd_entry;
extern struct command_entry mount_cmd_entry;
extern struct command_entry mount_9p_cmd_entry;
extern struct command_entry mount_loop_cmd_entry;
extern struct command_entry mount_options_cmd_entry;
extern struct command_entry mount_ro_cmd_entry;
extern struct command_entry mount_vfs_cmd_entry;
extern struct command_entry mountpoints_cmd_entry;
extern struct command_entry mounts_cmd_entry;
extern struct command_entry mv_cmd_entry;
extern struct command_entry ntfs_3g_probe_cmd_entry;
extern struct command_entry ntfsresize_cmd_entry;
extern struct command_entry ntfsresize_opts_cmd_entry;
extern struct command_entry ntfsresize_size_cmd_entry;
extern struct command_entry part_add_cmd_entry;
extern struct command_entry part_del_cmd_entry;
extern struct command_entry part_disk_cmd_entry;
extern struct command_entry part_get_bootable_cmd_entry;
extern struct command_entry part_get_mbr_id_cmd_entry;
extern struct command_entry part_get_parttype_cmd_entry;
extern struct command_entry part_init_cmd_entry;
extern struct command_entry part_list_cmd_entry;
extern struct command_entry part_set_bootable_cmd_entry;
extern struct command_entry part_set_mbr_id_cmd_entry;
extern struct command_entry part_set_name_cmd_entry;
extern struct command_entry part_to_dev_cmd_entry;
extern struct command_entry part_to_partnum_cmd_entry;
extern struct command_entry ping_daemon_cmd_entry;
extern struct command_entry pread_cmd_entry;
extern struct command_entry pread_device_cmd_entry;
extern struct command_entry pvcreate_cmd_entry;
extern struct command_entry pvremove_cmd_entry;
extern struct command_entry pvresize_cmd_entry;
extern struct command_entry pvresize_size_cmd_entry;
extern struct command_entry pvs_cmd_entry;
extern struct command_entry pvs_full_cmd_entry;
extern struct command_entry pvuuid_cmd_entry;
extern struct command_entry pwrite_cmd_entry;
extern struct command_entry pwrite_device_cmd_entry;
extern struct command_entry read_file_cmd_entry;
extern struct command_entry read_lines_cmd_entry;
extern struct command_entry readdir_cmd_entry;
extern struct command_entry readlink_cmd_entry;
extern struct command_entry readlinklist_cmd_entry;
extern struct command_entry realpath_cmd_entry;
extern struct command_entry removexattr_cmd_entry;
extern struct command_entry reopen_cmd_entry;
extern struct command_entry resize2fs_cmd_entry;
extern struct command_entry resize2fs_M_cmd_entry;
extern struct command_entry resize2fs_size_cmd_entry;
extern struct command_entry rm_cmd_entry;
extern struct command_entry rm_rf_cmd_entry;
extern struct command_entry rmdir_cmd_entry;
extern struct command_entry rmmountpoint_cmd_entry;
extern struct command_entry scrub_device_cmd_entry;
extern struct command_entry scrub_file_cmd_entry;
extern struct command_entry scrub_freespace_cmd_entry;
extern struct command_entry set_append_cmd_entry;
extern struct command_entry set_attach_method_cmd_entry;
extern struct command_entry set_autosync_cmd_entry;
extern struct command_entry set_direct_cmd_entry;
extern struct command_entry set_e2label_cmd_entry;
extern struct command_entry set_e2uuid_cmd_entry;
extern struct command_entry set_memsize_cmd_entry;
extern struct command_entry set_network_cmd_entry;
extern struct command_entry set_path_cmd_entry;
extern struct command_entry set_pgroup_cmd_entry;
extern struct command_entry set_qemu_cmd_entry;
extern struct command_entry set_recovery_proc_cmd_entry;
extern struct command_entry set_selinux_cmd_entry;
extern struct command_entry set_smp_cmd_entry;
extern struct command_entry set_trace_cmd_entry;
extern struct command_entry set_verbose_cmd_entry;
extern struct command_entry setcon_cmd_entry;
extern struct command_entry setenv_cmd_entry;
extern struct command_entry setxattr_cmd_entry;
extern struct command_entry sfdisk_cmd_entry;
extern struct command_entry sfdiskM_cmd_entry;
extern struct command_entry sfdisk_N_cmd_entry;
extern struct command_entry sfdisk_disk_geometry_cmd_entry;
extern struct command_entry sfdisk_kernel_geometry_cmd_entry;
extern struct command_entry sfdisk_l_cmd_entry;
extern struct command_entry sh_cmd_entry;
extern struct command_entry sh_lines_cmd_entry;
extern struct command_entry sleep_cmd_entry;
extern struct command_entry sparse_cmd_entry;
extern struct command_entry stat_cmd_entry;
extern struct command_entry statvfs_cmd_entry;
extern struct command_entry strings_cmd_entry;
extern struct command_entry strings_e_cmd_entry;
extern struct command_entry supported_cmd_entry;
extern struct command_entry swapoff_device_cmd_entry;
extern struct command_entry swapoff_file_cmd_entry;
extern struct command_entry swapoff_label_cmd_entry;
extern struct command_entry swapoff_uuid_cmd_entry;
extern struct command_entry swapon_device_cmd_entry;
extern struct command_entry swapon_file_cmd_entry;
extern struct command_entry swapon_label_cmd_entry;
extern struct command_entry swapon_uuid_cmd_entry;
extern struct command_entry sync_cmd_entry;
extern struct command_entry tail_cmd_entry;
extern struct command_entry tail_n_cmd_entry;
extern struct command_entry tar_in_cmd_entry;
extern struct command_entry tar_out_cmd_entry;
extern struct command_entry tgz_in_cmd_entry;
extern struct command_entry tgz_out_cmd_entry;
extern struct command_entry time_cmd_entry;
extern struct command_entry touch_cmd_entry;
extern struct command_entry truncate_cmd_entry;
extern struct command_entry truncate_size_cmd_entry;
extern struct command_entry tune2fs_l_cmd_entry;
extern struct command_entry txz_in_cmd_entry;
extern struct command_entry txz_out_cmd_entry;
extern struct command_entry umask_cmd_entry;
extern struct command_entry umount_cmd_entry;
extern struct command_entry umount_all_cmd_entry;
extern struct command_entry unsetenv_cmd_entry;
extern struct command_entry upload_cmd_entry;
extern struct command_entry upload_offset_cmd_entry;
extern struct command_entry utimens_cmd_entry;
extern struct command_entry version_cmd_entry;
extern struct command_entry vfs_label_cmd_entry;
extern struct command_entry vfs_type_cmd_entry;
extern struct command_entry vfs_uuid_cmd_entry;
extern struct command_entry vg_activate_cmd_entry;
extern struct command_entry vg_activate_all_cmd_entry;
extern struct command_entry vgcreate_cmd_entry;
extern struct command_entry vglvuuids_cmd_entry;
extern struct command_entry vgpvuuids_cmd_entry;
extern struct command_entry vgremove_cmd_entry;
extern struct command_entry vgrename_cmd_entry;
extern struct command_entry vgs_cmd_entry;
extern struct command_entry vgs_full_cmd_entry;
extern struct command_entry vgscan_cmd_entry;
extern struct command_entry vguuid_cmd_entry;
extern struct command_entry wc_c_cmd_entry;
extern struct command_entry wc_l_cmd_entry;
extern struct command_entry wc_w_cmd_entry;
extern struct command_entry write_cmd_entry;
extern struct command_entry write_append_cmd_entry;
extern struct command_entry write_file_cmd_entry;
extern struct command_entry zegrep_cmd_entry;
extern struct command_entry zegrepi_cmd_entry;
extern struct command_entry zero_cmd_entry;
extern struct command_entry zero_device_cmd_entry;
extern struct command_entry zerofree_cmd_entry;
extern struct command_entry zfgrep_cmd_entry;
extern struct command_entry zfgrepi_cmd_entry;
extern struct command_entry zfile_cmd_entry;
extern struct command_entry zgrep_cmd_entry;
extern struct command_entry zgrepi_cmd_entry;
#line 425 "cmds_gperf.gperf"
struct command_table;

#define TOTAL_KEYWORDS 662
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 39
#define MIN_HASH_VALUE 11
#define MAX_HASH_VALUE 6002
/* maximum key range = 5992, duplicates = 0 */

#ifndef GPERF_DOWNCASE
#define GPERF_DOWNCASE 1
static unsigned char gperf_downcase[256] =
  {
      0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,
     15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
     30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,
     45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
     60,  61,  62,  63,  64,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106,
    107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121,
    122,  91,  92,  93,  94,  95,  96,  97,  98,  99, 100, 101, 102, 103, 104,
    105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
    120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134,
    135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149,
    150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164,
    165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
    180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194,
    195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
    210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224,
    225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254,
    255
  };
#endif

#ifndef GPERF_CASE_STRCMP
#define GPERF_CASE_STRCMP 1
static int
gperf_case_strcmp (register const char *s1, register const char *s2)
{
  for (;;)
    {
      unsigned char c1 = gperf_downcase[(unsigned char)*s1++];
      unsigned char c2 = gperf_downcase[(unsigned char)*s2++];
      if (c1 != 0 && c1 == c2)
        continue;
      return (int)c1 - (int)c2;
    }
}
#endif

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003,    5, 6003, 6003,    0, 6003,
        40,    0,    5, 6003,    0, 6003, 6003,    5, 6003, 6003,
      6003, 6003, 6003, 6003, 6003,    0,  860,  100,   10,    0,
       330,   50, 1929,   15,    0,  660,  545,  170,   55,  125,
         5,    0,    0,    0,   10,  285,  590,  950,  705,  887,
       930, 6003, 6003, 6003, 6003,    0, 6003,    0,  860,  100,
        10,    0,  330,   50, 1929,   15,    0,  660,  545,  170,
        55,  125,    5,    0,    0,    0,   10,  285,  590,  950,
       705,  887,  930, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003,
      6003, 6003, 6003, 6003, 6003, 6003
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[13]];
      /*FALLTHROUGH*/
      case 13:
        hval += asso_values[(unsigned char)str[12]];
      /*FALLTHROUGH*/
      case 12:
        hval += asso_values[(unsigned char)str[11]];
      /*FALLTHROUGH*/
      case 11:
        hval += asso_values[(unsigned char)str[10]];
      /*FALLTHROUGH*/
      case 10:
        hval += asso_values[(unsigned char)str[9]];
      /*FALLTHROUGH*/
      case 9:
        hval += asso_values[(unsigned char)str[8]];
      /*FALLTHROUGH*/
      case 8:
        hval += asso_values[(unsigned char)str[7]];
      /*FALLTHROUGH*/
      case 7:
        hval += asso_values[(unsigned char)str[6]];
      /*FALLTHROUGH*/
      case 6:
        hval += asso_values[(unsigned char)str[5]];
      /*FALLTHROUGH*/
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      /*FALLTHROUGH*/
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

#ifdef __GNUC__
__inline
#if defined __GNUC_STDC_INLINE__ || defined __GNUC_GNU_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
const struct command_table *
lookup_fish_command (register const char *str, register unsigned int len)
{
  static const struct command_table wordlist[] =
    {
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 990 "cmds_gperf.gperf"
      {"sparse", &sparse_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 886 "cmds_gperf.gperf"
      {"pread", &pread_cmd_entry},
      {(char*)0},
#line 539 "cmds_gperf.gperf"
      {"dd", &dd_cmd_entry},
#line 437 "cmds_gperf.gperf"
      {"add", &add_drive_opts_cmd_entry},
#line 991 "cmds_gperf.gperf"
      {"stat", &stat_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 610 "cmds_gperf.gperf"
      {"pid", &get_pid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 563 "cmds_gperf.gperf"
      {"edit", &edit_cmd_entry},
      {(char*)0}, {(char*)0},
#line 905 "cmds_gperf.gperf"
      {"readdir", &readdir_cmd_entry},
#line 858 "cmds_gperf.gperf"
      {"part_add", &part_add_cmd_entry},
      {(char*)0}, {(char*)0},
#line 712 "cmds_gperf.gperf"
      {"is_dir", &is_dir_cmd_entry},
      {(char*)0},
#line 859 "cmds_gperf.gperf"
      {"part-add", &part_add_cmd_entry},
      {(char*)0}, {(char*)0},
#line 713 "cmds_gperf.gperf"
      {"is-dir", &is_dir_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 633 "cmds_gperf.gperf"
      {"grep", &grep_cmd_entry},
#line 566 "cmds_gperf.gperf"
      {"egrep", &egrep_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 634 "cmds_gperf.gperf"
      {"grepi", &grepi_cmd_entry},
#line 567 "cmds_gperf.gperf"
      {"egrepi", &egrepi_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 929 "cmds_gperf.gperf"
      {"append", &set_append_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1017 "cmds_gperf.gperf"
      {"tar_in", &tar_in_cmd_entry},
      {(char*)0}, {(char*)0},
#line 619 "cmds_gperf.gperf"
      {"get_state", &get_state_cmd_entry},
      {(char*)0},
#line 1018 "cmds_gperf.gperf"
      {"tar-in", &tar_in_cmd_entry},
      {(char*)0}, {(char*)0},
#line 620 "cmds_gperf.gperf"
      {"get-state", &get_state_cmd_entry},
#line 927 "cmds_gperf.gperf"
      {"set_append", &set_append_cmd_entry},
      {(char*)0},
#line 608 "cmds_gperf.gperf"
      {"get_pid", &get_pid_cmd_entry},
      {(char*)0}, {(char*)0},
#line 928 "cmds_gperf.gperf"
      {"set-append", &set_append_cmd_entry},
      {(char*)0},
#line 609 "cmds_gperf.gperf"
      {"get-pid", &get_pid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 536 "cmds_gperf.gperf"
      {"cp", &cp_cmd_entry},
      {(char*)0},
#line 537 "cmds_gperf.gperf"
      {"cp_a", &cp_a_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 506 "cmds_gperf.gperf"
      {"cat", &cat_cmd_entry},
#line 538 "cmds_gperf.gperf"
      {"cp-a", &cp_a_cmd_entry},
#line 969 "cmds_gperf.gperf"
      {"trace", &set_trace_cmd_entry},
      {(char*)0},
#line 868 "cmds_gperf.gperf"
      {"part_get_parttype", &part_get_parttype_cmd_entry},
      {(char*)0},
#line 870 "cmds_gperf.gperf"
      {"part_init", &part_init_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 871 "cmds_gperf.gperf"
      {"part-init", &part_init_cmd_entry},
      {(char*)0}, {(char*)0},
#line 869 "cmds_gperf.gperf"
      {"part-get-parttype", &part_get_parttype_cmd_entry},
      {(char*)0},
#line 967 "cmds_gperf.gperf"
      {"set_trace", &set_trace_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 968 "cmds_gperf.gperf"
      {"set-trace", &set_trace_cmd_entry},
      {(char*)0}, {(char*)0},
#line 993 "cmds_gperf.gperf"
      {"strings", &strings_cmd_entry},
      {(char*)0},
#line 994 "cmds_gperf.gperf"
      {"strings_e", &strings_e_cmd_entry},
      {(char*)0},
#line 938 "cmds_gperf.gperf"
      {"direct", &set_direct_cmd_entry},
      {(char*)0}, {(char*)0},
#line 995 "cmds_gperf.gperf"
      {"strings-e", &strings_e_cmd_entry},
#line 588 "cmds_gperf.gperf"
      {"get_append", &get_append_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 589 "cmds_gperf.gperf"
      {"get-append", &get_append_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 936 "cmds_gperf.gperf"
      {"set_direct", &set_direct_cmd_entry},
#line 440 "cmds_gperf.gperf"
      {"add-ro", &add_drive_ro_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 937 "cmds_gperf.gperf"
      {"set-direct", &set_direct_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 916 "cmds_gperf.gperf"
      {"rm", &rm_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 966 "cmds_gperf.gperf"
      {"smp", &set_smp_cmd_entry},
#line 621 "cmds_gperf.gperf"
      {"get_trace", &get_trace_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 622 "cmds_gperf.gperf"
      {"get-trace", &get_trace_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 910 "cmds_gperf.gperf"
      {"reopen", &reopen_cmd_entry},
#line 964 "cmds_gperf.gperf"
      {"set_smp", &set_smp_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 965 "cmds_gperf.gperf"
      {"set-smp", &set_smp_cmd_entry},
      {(char*)0},
#line 1025 "cmds_gperf.gperf"
      {"time", &time_cmd_entry},
#line 919 "cmds_gperf.gperf"
      {"rmdir", &rmdir_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 594 "cmds_gperf.gperf"
      {"get_direct", &get_direct_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 595 "cmds_gperf.gperf"
      {"get-direct", &get_direct_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 642 "cmds_gperf.gperf"
      {"initrd_cat", &initrd_cat_cmd_entry},
      {(char*)0}, {(char*)0},
#line 796 "cmds_gperf.gperf"
      {"man", &man_cmd_entry},
      {(char*)0},
#line 643 "cmds_gperf.gperf"
      {"initrd-cat", &initrd_cat_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 551 "cmds_gperf.gperf"
      {"dmesg", &dmesg_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 617 "cmds_gperf.gperf"
      {"get_smp", &get_smp_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 618 "cmds_gperf.gperf"
      {"get-smp", &get_smp_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 658 "cmds_gperf.gperf"
      {"inspect_get_arch", &inspect_get_arch_cmd_entry},
      {(char*)0},
#line 878 "cmds_gperf.gperf"
      {"part_set_name", &part_set_name_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 659 "cmds_gperf.gperf"
      {"inspect-get-arch", &inspect_get_arch_cmd_entry},
      {(char*)0},
#line 879 "cmds_gperf.gperf"
      {"part-set-name", &part_set_name_cmd_entry},
#line 682 "cmds_gperf.gperf"
      {"inspect_get_product_name", &inspect_get_product_name_cmd_entry},
#line 565 "cmds_gperf.gperf"
      {"emacs", &edit_cmd_entry},
#line 678 "cmds_gperf.gperf"
      {"inspect_get_package_format", &inspect_get_package_format_cmd_entry},
#line 684 "cmds_gperf.gperf"
      {"inspect_get_product_variant", &inspect_get_product_variant_cmd_entry},
      {(char*)0}, {(char*)0},
#line 680 "cmds_gperf.gperf"
      {"inspect_get_package_management", &inspect_get_package_management_cmd_entry},
#line 662 "cmds_gperf.gperf"
      {"inspect_get_drive_mappings", &inspect_get_drive_mappings_cmd_entry},
      {(char*)0},
#line 698 "cmds_gperf.gperf"
      {"inspect_is_netinst", &inspect_is_netinst_cmd_entry},
#line 683 "cmds_gperf.gperf"
      {"inspect-get-product-name", &inspect_get_product_name_cmd_entry},
      {(char*)0},
#line 679 "cmds_gperf.gperf"
      {"inspect-get-package-format", &inspect_get_package_format_cmd_entry},
#line 685 "cmds_gperf.gperf"
      {"inspect-get-product-variant", &inspect_get_product_variant_cmd_entry},
#line 660 "cmds_gperf.gperf"
      {"inspect_get_distro", &inspect_get_distro_cmd_entry},
      {(char*)0},
#line 681 "cmds_gperf.gperf"
      {"inspect-get-package-management", &inspect_get_package_management_cmd_entry},
#line 663 "cmds_gperf.gperf"
      {"inspect-get-drive-mappings", &inspect_get_drive_mappings_cmd_entry},
      {(char*)0},
#line 699 "cmds_gperf.gperf"
      {"inspect-is-netinst", &inspect_is_netinst_cmd_entry},
      {(char*)0}, {(char*)0},
#line 973 "cmds_gperf.gperf"
      {"setcon", &setcon_cmd_entry},
#line 557 "cmds_gperf.gperf"
      {"du", &du_cmd_entry},
#line 661 "cmds_gperf.gperf"
      {"inspect-get-distro", &inspect_get_distro_cmd_entry},
#line 835 "cmds_gperf.gperf"
      {"more", &more_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 702 "cmds_gperf.gperf"
      {"inspect_os", &inspect_os_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 703 "cmds_gperf.gperf"
      {"inspect-os", &inspect_os_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 547 "cmds_gperf.gperf"
      {"df", &df_cmd_entry},
#line 735 "cmds_gperf.gperf"
      {"run", &launch_cmd_entry},
      {(char*)0}, {(char*)0},
#line 627 "cmds_gperf.gperf"
      {"getcon", &getcon_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 473 "cmds_gperf.gperf"
      {"aug_set", &aug_set_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 474 "cmds_gperf.gperf"
      {"aug-set", &aug_set_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 670 "cmds_gperf.gperf"
      {"inspect_get_icon", &inspect_get_icon_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 432 "cmds_gperf.gperf"
      {"domain", &add_domain_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 671 "cmds_gperf.gperf"
      {"inspect-get-icon", &inspect_get_icon_cmd_entry},
#line 686 "cmds_gperf.gperf"
      {"inspect_get_roots", &inspect_get_roots_cmd_entry},
      {(char*)0}, {(char*)0},
#line 572 "cmds_gperf.gperf"
      {"fgrep", &fgrep_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 687 "cmds_gperf.gperf"
      {"inspect-get-roots", &inspect_get_roots_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 455 "cmds_gperf.gperf"
      {"aug_get", &aug_get_cmd_entry},
      {(char*)0}, {(char*)0},
#line 430 "cmds_gperf.gperf"
      {"add_domain", &add_domain_cmd_entry},
#line 573 "cmds_gperf.gperf"
      {"fgrepi", &fgrepi_cmd_entry},
#line 456 "cmds_gperf.gperf"
      {"aug-get", &aug_get_cmd_entry},
      {(char*)0}, {(char*)0},
#line 431 "cmds_gperf.gperf"
      {"add-domain", &add_domain_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 581 "cmds_gperf.gperf"
      {"find", &find_cmd_entry},
#line 582 "cmds_gperf.gperf"
      {"find0", &find0_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 459 "cmds_gperf.gperf"
      {"aug_insert", &aug_insert_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 460 "cmds_gperf.gperf"
      {"aug-insert", &aug_insert_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 428 "cmds_gperf.gperf"
      {"add_cdrom", &add_cdrom_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1019 "cmds_gperf.gperf"
      {"tar_out", &tar_out_cmd_entry},
#line 457 "cmds_gperf.gperf"
      {"aug_init", &aug_init_cmd_entry},
#line 429 "cmds_gperf.gperf"
      {"add-cdrom", &add_cdrom_cmd_entry},
#line 672 "cmds_gperf.gperf"
      {"inspect_get_major_version", &inspect_get_major_version_cmd_entry},
      {(char*)0},
#line 1020 "cmds_gperf.gperf"
      {"tar-out", &tar_out_cmd_entry},
#line 458 "cmds_gperf.gperf"
      {"aug-init", &aug_init_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 996 "cmds_gperf.gperf"
      {"supported", &supported_cmd_entry},
#line 673 "cmds_gperf.gperf"
      {"inspect-get-major-version", &inspect_get_major_version_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 674 "cmds_gperf.gperf"
      {"inspect_get_minor_version", &inspect_get_minor_version_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 957 "cmds_gperf.gperf"
      {"qemu", &set_qemu_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 675 "cmds_gperf.gperf"
      {"inspect-get-minor-version", &inspect_get_minor_version_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1027 "cmds_gperf.gperf"
      {"truncate", &truncate_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 955 "cmds_gperf.gperf"
      {"set_qemu", &set_qemu_cmd_entry},
      {(char*)0}, {(char*)0},
#line 954 "cmds_gperf.gperf"
      {"pgroup", &set_pgroup_cmd_entry},
      {(char*)0},
#line 956 "cmds_gperf.gperf"
      {"set-qemu", &set_qemu_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 952 "cmds_gperf.gperf"
      {"set_pgroup", &set_pgroup_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 953 "cmds_gperf.gperf"
      {"set-pgroup", &set_pgroup_cmd_entry},
#line 884 "cmds_gperf.gperf"
      {"ping_daemon", &ping_daemon_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 885 "cmds_gperf.gperf"
      {"ping-daemon", &ping_daemon_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 917 "cmds_gperf.gperf"
      {"rm_rf", &rm_rf_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 918 "cmds_gperf.gperf"
      {"rm-rf", &rm_rf_cmd_entry},
#line 469 "cmds_gperf.gperf"
      {"aug_rm", &aug_rm_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 470 "cmds_gperf.gperf"
      {"aug-rm", &aug_rm_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 882 "cmds_gperf.gperf"
      {"part_to_partnum", &part_to_partnum_cmd_entry},
      {(char*)0}, {(char*)0},
#line 611 "cmds_gperf.gperf"
      {"get_qemu", &get_qemu_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 612 "cmds_gperf.gperf"
      {"get-qemu", &get_qemu_cmd_entry},
      {(char*)0},
#line 883 "cmds_gperf.gperf"
      {"part-to-partnum", &part_to_partnum_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 606 "cmds_gperf.gperf"
      {"get_pgroup", &get_pgroup_cmd_entry},
      {(char*)0},
#line 1046 "cmds_gperf.gperf"
      {"utimens", &utimens_cmd_entry},
      {(char*)0}, {(char*)0},
#line 607 "cmds_gperf.gperf"
      {"get-pgroup", &get_pgroup_cmd_entry},
      {(char*)0},
#line 759 "cmds_gperf.gperf"
      {"ls", &ls_cmd_entry},
      {(char*)0},
#line 836 "cmds_gperf.gperf"
      {"less", &more_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 989 "cmds_gperf.gperf"
      {"sleep", &sleep_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 676 "cmds_gperf.gperf"
      {"inspect_get_mountpoints", &inspect_get_mountpoints_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 761 "cmds_gperf.gperf"
      {"lstat", &lstat_cmd_entry},
      {(char*)0}, {(char*)0},
#line 677 "cmds_gperf.gperf"
      {"inspect-get-mountpoints", &inspect_get_mountpoints_cmd_entry},
#line 1014 "cmds_gperf.gperf"
      {"tail", &tail_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 860 "cmds_gperf.gperf"
      {"part_del", &part_del_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 861 "cmds_gperf.gperf"
      {"part-del", &part_del_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 740 "cmds_gperf.gperf"
      {"list_9p", &list_9p_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 741 "cmds_gperf.gperf"
      {"list-9p", &list_9p_cmd_entry},
      {(char*)0},
#line 872 "cmds_gperf.gperf"
      {"part_list", &part_list_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 894 "cmds_gperf.gperf"
      {"pvs", &pvs_cmd_entry},
#line 873 "cmds_gperf.gperf"
      {"part-list", &part_list_cmd_entry},
      {(char*)0}, {(char*)0},
#line 751 "cmds_gperf.gperf"
      {"ln", &ln_cmd_entry},
      {(char*)0},
#line 754 "cmds_gperf.gperf"
      {"ln_s", &ln_s_cmd_entry},
      {(char*)0}, {(char*)0},
#line 564 "cmds_gperf.gperf"
      {"vi", &edit_cmd_entry},
      {(char*)0},
#line 755 "cmds_gperf.gperf"
      {"ln-s", &ln_s_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 664 "cmds_gperf.gperf"
      {"inspect_get_filesystems", &inspect_get_filesystems_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 665 "cmds_gperf.gperf"
      {"inspect-get-filesystems", &inspect_get_filesystems_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1015 "cmds_gperf.gperf"
      {"tail_n", &tail_n_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 903 "cmds_gperf.gperf"
      {"read_lines", &read_lines_cmd_entry},
#line 1016 "cmds_gperf.gperf"
      {"tail-n", &tail_n_cmd_entry},
#line 514 "cmds_gperf.gperf"
      {"command", &command_cmd_entry},
      {(char*)0}, {(char*)0},
#line 904 "cmds_gperf.gperf"
      {"read-lines", &read_lines_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1063 "cmds_gperf.gperf"
      {"vgs", &vgs_cmd_entry},
#line 433 "cmds_gperf.gperf"
      {"add_drive", &add_drive_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 434 "cmds_gperf.gperf"
      {"add-drive", &add_drive_cmd_entry},
#line 837 "cmds_gperf.gperf"
      {"mount", &mount_cmd_entry},
#line 849 "cmds_gperf.gperf"
      {"mounts", &mounts_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 941 "cmds_gperf.gperf"
      {"set_e2uuid", &set_e2uuid_cmd_entry},
      {(char*)0}, {(char*)0},
#line 736 "cmds_gperf.gperf"
      {"lcd", &lcd_cmd_entry},
      {(char*)0},
#line 942 "cmds_gperf.gperf"
      {"set-e2uuid", &set_e2uuid_cmd_entry},
#line 974 "cmds_gperf.gperf"
      {"setenv", &setenv_cmd_entry},
      {(char*)0},
#line 838 "cmds_gperf.gperf"
      {"mount_9p", &mount_9p_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 839 "cmds_gperf.gperf"
      {"mount-9p", &mount_9p_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 521 "cmds_gperf.gperf"
      {"config", &config_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 644 "cmds_gperf.gperf"
      {"initrd_list", &initrd_list_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 645 "cmds_gperf.gperf"
      {"initrd-list", &initrd_list_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 710 "cmds_gperf.gperf"
      {"is_config", &is_config_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 711 "cmds_gperf.gperf"
      {"is-config", &is_config_cmd_entry},
#line 598 "cmds_gperf.gperf"
      {"get_e2uuid", &get_e2uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 862 "cmds_gperf.gperf"
      {"part_disk", &part_disk_cmd_entry},
#line 599 "cmds_gperf.gperf"
      {"get-e2uuid", &get_e2uuid_cmd_entry},
      {(char*)0}, {(char*)0},
#line 889 "cmds_gperf.gperf"
      {"pvcreate", &pvcreate_cmd_entry},
#line 863 "cmds_gperf.gperf"
      {"part-disk", &part_disk_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 666 "cmds_gperf.gperf"
      {"inspect_get_format", &inspect_get_format_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 667 "cmds_gperf.gperf"
      {"inspect-get-format", &inspect_get_format_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 569 "cmds_gperf.gperf"
      {"exists", &exists_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 887 "cmds_gperf.gperf"
      {"pread_device", &pread_device_cmd_entry},
#line 975 "cmds_gperf.gperf"
      {"setxattr", &setxattr_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 888 "cmds_gperf.gperf"
      {"pread-device", &pread_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1058 "cmds_gperf.gperf"
      {"vgcreate", &vgcreate_cmd_entry},
      {(char*)0}, {(char*)0},
#line 880 "cmds_gperf.gperf"
      {"part_to_dev", &part_to_dev_cmd_entry},
#line 850 "cmds_gperf.gperf"
      {"mv", &mv_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 881 "cmds_gperf.gperf"
      {"part-to-dev", &part_to_dev_cmd_entry},
#line 438 "cmds_gperf.gperf"
      {"add_drive_ro", &add_drive_ro_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 844 "cmds_gperf.gperf"
      {"mount_ro", &mount_ro_cmd_entry},
      {(char*)0},
#line 700 "cmds_gperf.gperf"
      {"inspect_list_applications", &inspect_list_applications_cmd_entry},
      {(char*)0},
#line 439 "cmds_gperf.gperf"
      {"add-drive-ro", &add_drive_ro_cmd_entry},
#line 845 "cmds_gperf.gperf"
      {"mount-ro", &mount_ro_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 435 "cmds_gperf.gperf"
      {"add_drive_opts", &add_drive_opts_cmd_entry},
#line 701 "cmds_gperf.gperf"
      {"inspect-list-applications", &inspect_list_applications_cmd_entry},
      {(char*)0},
#line 1047 "cmds_gperf.gperf"
      {"version", &version_cmd_entry},
#line 628 "cmds_gperf.gperf"
      {"getxattr", &getxattr_cmd_entry},
#line 629 "cmds_gperf.gperf"
      {"getxattrs", &getxattrs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 436 "cmds_gperf.gperf"
      {"add-drive-opts", &add_drive_opts_cmd_entry},
      {(char*)0},
#line 1066 "cmds_gperf.gperf"
      {"vgscan", &vgscan_cmd_entry},
      {(char*)0}, {(char*)0},
#line 504 "cmds_gperf.gperf"
      {"case_sensitive_path", &case_sensitive_path_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 505 "cmds_gperf.gperf"
      {"case-sensitive-path", &case_sensitive_path_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 748 "cmds_gperf.gperf"
      {"list_partitions", &list_partitions_cmd_entry},
      {(char*)0},
#line 714 "cmds_gperf.gperf"
      {"is_fifo", &is_fifo_cmd_entry},
      {(char*)0}, {(char*)0},
#line 749 "cmds_gperf.gperf"
      {"list-partitions", &list_partitions_cmd_entry},
      {(char*)0},
#line 715 "cmds_gperf.gperf"
      {"is-fifo", &is_fifo_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 519 "cmds_gperf.gperf"
      {"compress_out", &compress_out_cmd_entry},
      {(char*)0}, {(char*)0},
#line 568 "cmds_gperf.gperf"
      {"equal", &equal_cmd_entry},
      {(char*)0},
#line 520 "cmds_gperf.gperf"
      {"compress-out", &compress_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 798 "cmds_gperf.gperf"
      {"mkdir", &mkdir_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 848 "cmds_gperf.gperf"
      {"mountpoints", &mountpoints_cmd_entry},
#line 801 "cmds_gperf.gperf"
      {"mkdir_p", &mkdir_p_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 802 "cmds_gperf.gperf"
      {"mkdir-p", &mkdir_p_cmd_entry},
#line 1062 "cmds_gperf.gperf"
      {"vgrename", &vgrename_cmd_entry},
      {(char*)0}, {(char*)0},
#line 451 "cmds_gperf.gperf"
      {"aug_defnode", &aug_defnode_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 452 "cmds_gperf.gperf"
      {"aug-defnode", &aug_defnode_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 463 "cmds_gperf.gperf"
      {"aug_ls", &aug_ls_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 464 "cmds_gperf.gperf"
      {"aug-ls", &aug_ls_cmd_entry},
      {(char*)0}, {(char*)0},
#line 574 "cmds_gperf.gperf"
      {"file", &file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 901 "cmds_gperf.gperf"
      {"read_file", &read_file_cmd_entry},
      {(char*)0}, {(char*)0},
#line 716 "cmds_gperf.gperf"
      {"is_file", &is_file_cmd_entry},
      {(char*)0},
#line 902 "cmds_gperf.gperf"
      {"read-file", &read_file_cmd_entry},
      {(char*)0}, {(char*)0},
#line 717 "cmds_gperf.gperf"
      {"is-file", &is_file_cmd_entry},
      {(char*)0},
#line 724 "cmds_gperf.gperf"
      {"is_socket", &is_socket_cmd_entry},
#line 722 "cmds_gperf.gperf"
      {"is_ready", &is_ready_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 725 "cmds_gperf.gperf"
      {"is-socket", &is_socket_cmd_entry},
#line 723 "cmds_gperf.gperf"
      {"is-ready", &is_ready_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 471 "cmds_gperf.gperf"
      {"aug_save", &aug_save_cmd_entry},
#line 752 "cmds_gperf.gperf"
      {"ln_f", &ln_f_cmd_entry},
#line 756 "cmds_gperf.gperf"
      {"ln_sf", &ln_sf_cmd_entry},
#line 1037 "cmds_gperf.gperf"
      {"umount", &umount_cmd_entry},
      {(char*)0},
#line 472 "cmds_gperf.gperf"
      {"aug-save", &aug_save_cmd_entry},
#line 753 "cmds_gperf.gperf"
      {"ln-f", &ln_f_cmd_entry},
#line 757 "cmds_gperf.gperf"
      {"ln-sf", &ln_sf_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 478 "cmds_gperf.gperf"
      {"base64_in", &base64_in_cmd_entry},
      {(char*)0}, {(char*)0},
#line 992 "cmds_gperf.gperf"
      {"statvfs", &statvfs_cmd_entry},
      {(char*)0},
#line 479 "cmds_gperf.gperf"
      {"base64-in", &base64_in_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1043 "cmds_gperf.gperf"
      {"upload", &upload_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1074 "cmds_gperf.gperf"
      {"write", &write_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 898 "cmds_gperf.gperf"
      {"pwrite", &pwrite_cmd_entry},
      {(char*)0}, {(char*)0},
#line 447 "cmds_gperf.gperf"
      {"aug_clear", &aug_clear_cmd_entry},
#line 1088 "cmds_gperf.gperf"
      {"zgrep", &zgrep_cmd_entry},
#line 1079 "cmds_gperf.gperf"
      {"zegrep", &zegrep_cmd_entry},
#line 1038 "cmds_gperf.gperf"
      {"unmount", &umount_cmd_entry},
#line 842 "cmds_gperf.gperf"
      {"mount_options", &mount_options_cmd_entry},
#line 448 "cmds_gperf.gperf"
      {"aug-clear", &aug_clear_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 843 "cmds_gperf.gperf"
      {"mount-options", &mount_options_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1042 "cmds_gperf.gperf"
      {"unsetenv", &unsetenv_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1089 "cmds_gperf.gperf"
      {"zgrepi", &zgrepi_cmd_entry},
#line 1080 "cmds_gperf.gperf"
      {"zegrepi", &zegrepi_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 976 "cmds_gperf.gperf"
      {"sfdisk", &sfdisk_cmd_entry},
      {(char*)0},
#line 461 "cmds_gperf.gperf"
      {"aug_load", &aug_load_cmd_entry},
      {(char*)0},
#line 822 "cmds_gperf.gperf"
      {"mknod", &mknod_cmd_entry},
      {(char*)0}, {(char*)0},
#line 462 "cmds_gperf.gperf"
      {"aug-load", &aug_load_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 803 "cmds_gperf.gperf"
      {"mkdtemp", &mkdtemp_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 920 "cmds_gperf.gperf"
      {"rmmountpoint", &rmmountpoint_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1013 "cmds_gperf.gperf"
      {"sync", &sync_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1081 "cmds_gperf.gperf"
      {"zero", &zero_cmd_entry},
      {(char*)0},
#line 797 "cmds_gperf.gperf"
      {"manual", &man_cmd_entry},
#line 1075 "cmds_gperf.gperf"
      {"write_append", &write_append_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1021 "cmds_gperf.gperf"
      {"tgz_in", &tgz_in_cmd_entry},
#line 1076 "cmds_gperf.gperf"
      {"write-append", &write_append_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1022 "cmds_gperf.gperf"
      {"tgz-in", &tgz_in_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 728 "cmds_gperf.gperf"
      {"is_zero", &is_zero_cmd_entry},
#line 978 "cmds_gperf.gperf"
      {"sfdisk_N", &sfdisk_N_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 729 "cmds_gperf.gperf"
      {"is-zero", &is_zero_cmd_entry},
#line 979 "cmds_gperf.gperf"
      {"sfdisk-N", &sfdisk_N_cmd_entry},
      {(char*)0},
#line 876 "cmds_gperf.gperf"
      {"part_set_mbr_id", &part_set_mbr_id_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 750 "cmds_gperf.gperf"
      {"ll", &ll_cmd_entry},
      {(char*)0},
#line 587 "cmds_gperf.gperf"
      {"fsck", &fsck_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 877 "cmds_gperf.gperf"
      {"part-set-mbr-id", &part_set_mbr_id_cmd_entry},
#line 467 "cmds_gperf.gperf"
      {"aug_mv", &aug_mv_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 468 "cmds_gperf.gperf"
      {"aug-mv", &aug_mv_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 449 "cmds_gperf.gperf"
      {"aug_close", &aug_close_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 450 "cmds_gperf.gperf"
      {"aug-close", &aug_close_cmd_entry},
#line 1036 "cmds_gperf.gperf"
      {"umask", &umask_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 825 "cmds_gperf.gperf"
      {"mknod_c", &mknod_c_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 826 "cmds_gperf.gperf"
      {"mknod-c", &mknod_c_cmd_entry},
      {(char*)0},
#line 517 "cmds_gperf.gperf"
      {"compress_device_out", &compress_device_out_cmd_entry},
#line 866 "cmds_gperf.gperf"
      {"part_get_mbr_id", &part_get_mbr_id_cmd_entry},
      {(char*)0}, {(char*)0},
#line 791 "cmds_gperf.gperf"
      {"lvs", &lvs_cmd_entry},
#line 518 "cmds_gperf.gperf"
      {"compress-device-out", &compress_device_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 762 "cmds_gperf.gperf"
      {"lstatlist", &lstatlist_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 867 "cmds_gperf.gperf"
      {"part-get-mbr-id", &part_get_mbr_id_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1068 "cmds_gperf.gperf"
      {"wc_c", &wc_c_cmd_entry},
#line 720 "cmds_gperf.gperf"
      {"is_lv", &is_lv_cmd_entry},
      {(char*)0}, {(char*)0},
#line 688 "cmds_gperf.gperf"
      {"inspect_get_type", &inspect_get_type_cmd_entry},
#line 1069 "cmds_gperf.gperf"
      {"wc-c", &wc_c_cmd_entry},
#line 721 "cmds_gperf.gperf"
      {"is-lv", &is_lv_cmd_entry},
      {(char*)0},
#line 874 "cmds_gperf.gperf"
      {"part_set_bootable", &part_set_bootable_cmd_entry},
      {(char*)0},
#line 816 "cmds_gperf.gperf"
      {"mkfs", &mkfs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 689 "cmds_gperf.gperf"
      {"inspect-get-type", &inspect_get_type_cmd_entry},
      {(char*)0},
#line 799 "cmds_gperf.gperf"
      {"mkdir_mode", &mkdir_mode_cmd_entry},
      {(char*)0},
#line 875 "cmds_gperf.gperf"
      {"part-set-bootable", &part_set_bootable_cmd_entry},
      {(char*)0}, {(char*)0},
#line 800 "cmds_gperf.gperf"
      {"mkdir-mode", &mkdir_mode_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 623 "cmds_gperf.gperf"
      {"get_umask", &get_umask_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 624 "cmds_gperf.gperf"
      {"get-umask", &get_umask_cmd_entry},
      {(char*)0}, {(char*)0},
#line 977 "cmds_gperf.gperf"
      {"sfdiskM", &sfdiskM_cmd_entry},
      {(char*)0},
#line 530 "cmds_gperf.gperf"
      {"copy_in", &copy_in_cmd_entry},
      {(char*)0},
#line 897 "cmds_gperf.gperf"
      {"pvuuid", &pvuuid_cmd_entry},
      {(char*)0}, {(char*)0},
#line 531 "cmds_gperf.gperf"
      {"copy-in", &copy_in_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 804 "cmds_gperf.gperf"
      {"mke2fs_J", &mke2fs_J_cmd_entry},
      {(char*)0},
#line 540 "cmds_gperf.gperf"
      {"debug", &debug_cmd_entry},
      {(char*)0},
#line 864 "cmds_gperf.gperf"
      {"part_get_bootable", &part_get_bootable_cmd_entry},
#line 805 "cmds_gperf.gperf"
      {"mke2fs-J", &mke2fs_J_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 696 "cmds_gperf.gperf"
      {"inspect_is_multipart", &inspect_is_multipart_cmd_entry},
      {(char*)0},
#line 865 "cmds_gperf.gperf"
      {"part-get-bootable", &part_get_bootable_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 697 "cmds_gperf.gperf"
      {"inspect-is-multipart", &inspect_is_multipart_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 692 "cmds_gperf.gperf"
      {"inspect_get_windows_systemroot", &inspect_get_windows_systemroot_cmd_entry},
#line 1067 "cmds_gperf.gperf"
      {"vguuid", &vguuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 690 "cmds_gperf.gperf"
      {"inspect_get_windows_current_control_set", &inspect_get_windows_current_control_set_cmd_entry},
#line 693 "cmds_gperf.gperf"
      {"inspect-get-windows-systemroot", &inspect_get_windows_systemroot_cmd_entry},
      {(char*)0}, {(char*)0},
#line 777 "cmds_gperf.gperf"
      {"lvcreate", &lvcreate_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 515 "cmds_gperf.gperf"
      {"command_lines", &command_lines_cmd_entry},
#line 691 "cmds_gperf.gperf"
      {"inspect-get-windows-current-control-set", &inspect_get_windows_current_control_set_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 516 "cmds_gperf.gperf"
      {"command-lines", &command_lines_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1030 "cmds_gperf.gperf"
      {"tune2fs_l", &tune2fs_l_cmd_entry},
#line 453 "cmds_gperf.gperf"
      {"aug_defvar", &aug_defvar_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1031 "cmds_gperf.gperf"
      {"tune2fs-l", &tune2fs_l_cmd_entry},
#line 454 "cmds_gperf.gperf"
      {"aug-defvar", &aug_defvar_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 760 "cmds_gperf.gperf"
      {"lsetxattr", &lsetxattr_cmd_entry},
      {(char*)0}, {(char*)0},
#line 945 "cmds_gperf.gperf"
      {"memsize", &set_memsize_cmd_entry},
#line 906 "cmds_gperf.gperf"
      {"readlink", &readlink_cmd_entry},
      {(char*)0},
#line 480 "cmds_gperf.gperf"
      {"base64_out", &base64_out_cmd_entry},
      {(char*)0},
#line 742 "cmds_gperf.gperf"
      {"list_devices", &list_devices_cmd_entry},
      {(char*)0}, {(char*)0},
#line 481 "cmds_gperf.gperf"
      {"base64-out", &base64_out_cmd_entry},
      {(char*)0},
#line 743 "cmds_gperf.gperf"
      {"list-devices", &list_devices_cmd_entry},
#line 834 "cmds_gperf.gperf"
      {"modprobe", &modprobe_cmd_entry},
      {(char*)0}, {(char*)0},
#line 943 "cmds_gperf.gperf"
      {"set_memsize", &set_memsize_cmd_entry},
      {(char*)0}, {(char*)0},
#line 819 "cmds_gperf.gperf"
      {"mkfs_opts", &mkfs_opts_cmd_entry},
      {(char*)0},
#line 944 "cmds_gperf.gperf"
      {"set-memsize", &set_memsize_cmd_entry},
      {(char*)0}, {(char*)0},
#line 820 "cmds_gperf.gperf"
      {"mkfs-opts", &mkfs_opts_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 445 "cmds_gperf.gperf"
      {"alloc", &alloc_cmd_entry},
#line 1085 "cmds_gperf.gperf"
      {"zfgrep", &zfgrep_cmd_entry},
      {(char*)0}, {(char*)0},
#line 911 "cmds_gperf.gperf"
      {"resize2fs", &resize2fs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 446 "cmds_gperf.gperf"
      {"allocate", &alloc_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1086 "cmds_gperf.gperf"
      {"zfgrepi", &zfgrepi_cmd_entry},
      {(char*)0},
#line 738 "cmds_gperf.gperf"
      {"lgetxattr", &lgetxattr_cmd_entry},
#line 739 "cmds_gperf.gperf"
      {"lgetxattrs", &lgetxattrs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 585 "cmds_gperf.gperf"
      {"findfs_uuid", &findfs_uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 853 "cmds_gperf.gperf"
      {"ntfsresize", &ntfsresize_cmd_entry},
#line 586 "cmds_gperf.gperf"
      {"findfs-uuid", &findfs_uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 600 "cmds_gperf.gperf"
      {"get_memsize", &get_memsize_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 601 "cmds_gperf.gperf"
      {"get-memsize", &get_memsize_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 694 "cmds_gperf.gperf"
      {"inspect_is_live", &inspect_is_live_cmd_entry},
      {(char*)0}, {(char*)0},
#line 787 "cmds_gperf.gperf"
      {"lvrename", &lvrename_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 695 "cmds_gperf.gperf"
      {"inspect-is-live", &inspect_is_live_cmd_entry},
#line 1054 "cmds_gperf.gperf"
      {"vg_activate", &vg_activate_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1055 "cmds_gperf.gperf"
      {"vg-activate", &vg_activate_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1084 "cmds_gperf.gperf"
      {"zerofree", &zerofree_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1023 "cmds_gperf.gperf"
      {"tgz_out", &tgz_out_cmd_entry},
#line 1028 "cmds_gperf.gperf"
      {"truncate_size", &truncate_size_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1024 "cmds_gperf.gperf"
      {"tgz-out", &tgz_out_cmd_entry},
#line 1029 "cmds_gperf.gperf"
      {"truncate-size", &truncate_size_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 578 "cmds_gperf.gperf"
      {"fill", &fill_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 851 "cmds_gperf.gperf"
      {"ntfs_3g_probe", &ntfs_3g_probe_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 840 "cmds_gperf.gperf"
      {"mount_loop", &mount_loop_cmd_entry},
      {(char*)0}, {(char*)0},
#line 852 "cmds_gperf.gperf"
      {"ntfs-3g-probe", &ntfs_3g_probe_cmd_entry},
#line 654 "cmds_gperf.gperf"
      {"inotify_read", &inotify_read_cmd_entry},
#line 841 "cmds_gperf.gperf"
      {"mount-loop", &mount_loop_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 655 "cmds_gperf.gperf"
      {"inotify-read", &inotify_read_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 558 "cmds_gperf.gperf"
      {"e2fsck_f", &e2fsck_f_cmd_entry},
#line 550 "cmds_gperf.gperf"
      {"display", &display_cmd_entry},
#line 935 "cmds_gperf.gperf"
      {"autosync", &set_autosync_cmd_entry},
      {(char*)0}, {(char*)0},
#line 559 "cmds_gperf.gperf"
      {"e2fsck-f", &e2fsck_f_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 744 "cmds_gperf.gperf"
      {"list_dm_devices", &list_dm_devices_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 933 "cmds_gperf.gperf"
      {"set_autosync", &set_autosync_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 890 "cmds_gperf.gperf"
      {"pvremove", &pvremove_cmd_entry},
#line 934 "cmds_gperf.gperf"
      {"set-autosync", &set_autosync_cmd_entry},
#line 745 "cmds_gperf.gperf"
      {"list-dm-devices", &list_dm_devices_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 808 "cmds_gperf.gperf"
      {"mke2fs_JU", &mke2fs_JU_cmd_entry},
#line 854 "cmds_gperf.gperf"
      {"ntfsresize_opts", &ntfsresize_opts_cmd_entry},
#line 912 "cmds_gperf.gperf"
      {"resize2fs_M", &resize2fs_M_cmd_entry},
      {(char*)0}, {(char*)0},
#line 809 "cmds_gperf.gperf"
      {"mke2fs-JU", &mke2fs_JU_cmd_entry},
#line 855 "cmds_gperf.gperf"
      {"ntfsresize-opts", &ntfsresize_opts_cmd_entry},
#line 913 "cmds_gperf.gperf"
      {"resize2fs-M", &resize2fs_M_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1052 "cmds_gperf.gperf"
      {"vfs_uuid", &vfs_uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 579 "cmds_gperf.gperf"
      {"fill_pattern", &fill_pattern_cmd_entry},
#line 1053 "cmds_gperf.gperf"
      {"vfs-uuid", &vfs_uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 580 "cmds_gperf.gperf"
      {"fill-pattern", &fill_pattern_cmd_entry},
#line 1061 "cmds_gperf.gperf"
      {"vgremove", &vgremove_cmd_entry},
#line 592 "cmds_gperf.gperf"
      {"get_autosync", &get_autosync_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 593 "cmds_gperf.gperf"
      {"get-autosync", &get_autosync_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 652 "cmds_gperf.gperf"
      {"inotify_init", &inotify_init_cmd_entry},
#line 532 "cmds_gperf.gperf"
      {"copy_out", &copy_out_cmd_entry},
      {(char*)0}, {(char*)0},
#line 891 "cmds_gperf.gperf"
      {"pvresize", &pvresize_cmd_entry},
#line 653 "cmds_gperf.gperf"
      {"inotify-init", &inotify_init_cmd_entry},
#line 533 "cmds_gperf.gperf"
      {"copy-out", &copy_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 984 "cmds_gperf.gperf"
      {"sfdisk_l", &sfdisk_l_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 985 "cmds_gperf.gperf"
      {"sfdisk-l", &sfdisk_l_cmd_entry},
#line 846 "cmds_gperf.gperf"
      {"mount_vfs", &mount_vfs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 847 "cmds_gperf.gperf"
      {"mount-vfs", &mount_vfs_cmd_entry},
      {(char*)0}, {(char*)0},
#line 972 "cmds_gperf.gperf"
      {"verbose", &set_verbose_cmd_entry},
      {(char*)0},
#line 630 "cmds_gperf.gperf"
      {"glob", &glob_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 970 "cmds_gperf.gperf"
      {"set_verbose", &set_verbose_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1070 "cmds_gperf.gperf"
      {"wc_l", &wc_l_cmd_entry},
      {(char*)0},
#line 971 "cmds_gperf.gperf"
      {"set-verbose", &set_verbose_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1071 "cmds_gperf.gperf"
      {"wc-l", &wc_l_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 963 "cmds_gperf.gperf"
      {"selinux", &set_selinux_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 909 "cmds_gperf.gperf"
      {"removexattr", &removexattr_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 961 "cmds_gperf.gperf"
      {"set_selinux", &set_selinux_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 962 "cmds_gperf.gperf"
      {"set-selinux", &set_selinux_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 815 "cmds_gperf.gperf"
      {"mkfifo", &mkfifo_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 625 "cmds_gperf.gperf"
      {"get_verbose", &get_verbose_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 626 "cmds_gperf.gperf"
      {"get-verbose", &get_verbose_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 570 "cmds_gperf.gperf"
      {"fallocate", &fallocate_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 571 "cmds_gperf.gperf"
      {"fallocate64", &fallocate64_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 615 "cmds_gperf.gperf"
      {"get_selinux", &get_selinux_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 616 "cmds_gperf.gperf"
      {"get-selinux", &get_selinux_cmd_entry},
      {(char*)0}, {(char*)0},
#line 773 "cmds_gperf.gperf"
      {"luks_open", &luks_open_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 774 "cmds_gperf.gperf"
      {"luks-open", &luks_open_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 925 "cmds_gperf.gperf"
      {"scrub_freespace", &scrub_freespace_cmd_entry},
      {(char*)0},
#line 821 "cmds_gperf.gperf"
      {"mkmountpoint", &mkmountpoint_cmd_entry},
      {(char*)0}, {(char*)0},
#line 926 "cmds_gperf.gperf"
      {"scrub-freespace", &scrub_freespace_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 899 "cmds_gperf.gperf"
      {"pwrite_device", &pwrite_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 900 "cmds_gperf.gperf"
      {"pwrite-device", &pwrite_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1032 "cmds_gperf.gperf"
      {"txz_in", &txz_in_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1033 "cmds_gperf.gperf"
      {"txz-in", &txz_in_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 441 "cmds_gperf.gperf"
      {"add_drive_ro_with_if", &add_drive_ro_with_if_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 958 "cmds_gperf.gperf"
      {"set_recovery_proc", &set_recovery_proc_cmd_entry},
      {(char*)0},
#line 794 "cmds_gperf.gperf"
      {"lvuuid", &lvuuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1011 "cmds_gperf.gperf"
      {"swapon_uuid", &swapon_uuid_cmd_entry},
      {(char*)0}, {(char*)0},
#line 959 "cmds_gperf.gperf"
      {"set-recovery-proc", &set_recovery_proc_cmd_entry},
#line 442 "cmds_gperf.gperf"
      {"add-drive-ro-with-if", &add_drive_ro_with_if_cmd_entry},
#line 1012 "cmds_gperf.gperf"
      {"swapon-uuid", &swapon_uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 806 "cmds_gperf.gperf"
      {"mke2fs_JL", &mke2fs_JL_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 807 "cmds_gperf.gperf"
      {"mke2fs-JL", &mke2fs_JL_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 980 "cmds_gperf.gperf"
      {"sfdisk_disk_geometry", &sfdisk_disk_geometry_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1044 "cmds_gperf.gperf"
      {"upload_offset", &upload_offset_cmd_entry},
      {(char*)0},
#line 981 "cmds_gperf.gperf"
      {"sfdisk-disk-geometry", &sfdisk_disk_geometry_cmd_entry},
#line 1082 "cmds_gperf.gperf"
      {"zero_device", &zero_device_cmd_entry},
      {(char*)0},
#line 1045 "cmds_gperf.gperf"
      {"upload-offset", &upload_offset_cmd_entry},
#line 613 "cmds_gperf.gperf"
      {"get_recovery_proc", &get_recovery_proc_cmd_entry},
      {(char*)0},
#line 1083 "cmds_gperf.gperf"
      {"zero-device", &zero_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 827 "cmds_gperf.gperf"
      {"mkswap", &mkswap_cmd_entry},
      {(char*)0}, {(char*)0},
#line 614 "cmds_gperf.gperf"
      {"get-recovery-proc", &get_recovery_proc_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 730 "cmds_gperf.gperf"
      {"is_zero_device", &is_zero_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 948 "cmds_gperf.gperf"
      {"network", &set_network_cmd_entry},
      {(char*)0},
#line 731 "cmds_gperf.gperf"
      {"is-zero-device", &is_zero_device_cmd_entry},
      {(char*)0}, {(char*)0},
#line 775 "cmds_gperf.gperf"
      {"luks_open_ro", &luks_open_ro_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 946 "cmds_gperf.gperf"
      {"set_network", &set_network_cmd_entry},
#line 776 "cmds_gperf.gperf"
      {"luks-open-ro", &luks_open_ro_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1087 "cmds_gperf.gperf"
      {"zfile", &zfile_cmd_entry},
#line 947 "cmds_gperf.gperf"
      {"set-network", &set_network_cmd_entry},
      {(char*)0},
#line 552 "cmds_gperf.gperf"
      {"download", &download_cmd_entry},
      {(char*)0},
#line 1050 "cmds_gperf.gperf"
      {"vfs_type", &vfs_type_cmd_entry},
      {(char*)0},
#line 543 "cmds_gperf.gperf"
      {"debug_drives", &debug_drives_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1051 "cmds_gperf.gperf"
      {"vfs-type", &vfs_type_cmd_entry},
      {(char*)0},
#line 544 "cmds_gperf.gperf"
      {"debug-drives", &debug_drives_cmd_entry},
      {(char*)0},
#line 1060 "cmds_gperf.gperf"
      {"vgpvuuids", &vgpvuuids_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 577 "cmds_gperf.gperf"
      {"filesize", &filesize_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 795 "cmds_gperf.gperf"
      {"lxattrlist", &lxattrlist_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1005 "cmds_gperf.gperf"
      {"swapon_device", &swapon_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 907 "cmds_gperf.gperf"
      {"readlinklist", &readlinklist_cmd_entry},
#line 1006 "cmds_gperf.gperf"
      {"swapon-device", &swapon_device_cmd_entry},
      {(char*)0}, {(char*)0},
#line 602 "cmds_gperf.gperf"
      {"get_network", &get_network_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1077 "cmds_gperf.gperf"
      {"write_file", &write_file_cmd_entry},
#line 603 "cmds_gperf.gperf"
      {"get-network", &get_network_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1078 "cmds_gperf.gperf"
      {"write-file", &write_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 823 "cmds_gperf.gperf"
      {"mknod_b", &mknod_b_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 810 "cmds_gperf.gperf"
      {"mke2journal", &mke2journal_cmd_entry},
#line 824 "cmds_gperf.gperf"
      {"mknod-b", &mknod_b_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1056 "cmds_gperf.gperf"
      {"vg_activate_all", &vg_activate_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 986 "cmds_gperf.gperf"
      {"sh", &sh_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1057 "cmds_gperf.gperf"
      {"vg-activate-all", &vg_activate_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 637 "cmds_gperf.gperf"
      {"head", &head_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 951 "cmds_gperf.gperf"
      {"path", &set_path_cmd_entry},
      {(char*)0},
#line 960 "cmds_gperf.gperf"
      {"recovery-proc", &set_recovery_proc_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 949 "cmds_gperf.gperf"
      {"set_path", &set_path_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 950 "cmds_gperf.gperf"
      {"set-path", &set_path_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 921 "cmds_gperf.gperf"
      {"scrub_device", &scrub_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 922 "cmds_gperf.gperf"
      {"scrub-device", &scrub_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 524 "cmds_gperf.gperf"
      {"copy_device_to_file", &copy_device_to_file_cmd_entry},
      {(char*)0},
#line 522 "cmds_gperf.gperf"
      {"copy_device_to_device", &copy_device_to_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 525 "cmds_gperf.gperf"
      {"copy-device-to-file", &copy_device_to_file_cmd_entry},
      {(char*)0},
#line 523 "cmds_gperf.gperf"
      {"copy-device-to-device", &copy_device_to_device_cmd_entry},
      {(char*)0},
#line 638 "cmds_gperf.gperf"
      {"head_n", &head_n_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1072 "cmds_gperf.gperf"
      {"wc_w", &wc_w_cmd_entry},
#line 639 "cmds_gperf.gperf"
      {"head-n", &head_n_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1073 "cmds_gperf.gperf"
      {"wc-w", &wc_w_cmd_entry},
      {(char*)0},
#line 939 "cmds_gperf.gperf"
      {"set_e2label", &set_e2label_cmd_entry},
#line 604 "cmds_gperf.gperf"
      {"get_path", &get_path_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 940 "cmds_gperf.gperf"
      {"set-e2label", &set_e2label_cmd_entry},
#line 605 "cmds_gperf.gperf"
      {"get-path", &get_path_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 817 "cmds_gperf.gperf"
      {"mkfs_b", &mkfs_b_cmd_entry},
      {(char*)0},
#line 786 "cmds_gperf.gperf"
      {"lvremove", &lvremove_cmd_entry},
      {(char*)0},
#line 1039 "cmds_gperf.gperf"
      {"umount_all", &umount_all_cmd_entry},
#line 818 "cmds_gperf.gperf"
      {"mkfs-b", &mkfs_b_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1040 "cmds_gperf.gperf"
      {"umount-all", &umount_all_cmd_entry},
#line 1007 "cmds_gperf.gperf"
      {"swapon_file", &swapon_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1008 "cmds_gperf.gperf"
      {"swapon-file", &swapon_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 706 "cmds_gperf.gperf"
      {"is_busy", &is_busy_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 707 "cmds_gperf.gperf"
      {"is-busy", &is_busy_cmd_entry},
      {(char*)0},
#line 596 "cmds_gperf.gperf"
      {"get_e2label", &get_e2label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 597 "cmds_gperf.gperf"
      {"get-e2label", &get_e2label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 534 "cmds_gperf.gperf"
      {"copy_size", &copy_size_cmd_entry},
#line 1034 "cmds_gperf.gperf"
      {"txz_out", &txz_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 535 "cmds_gperf.gperf"
      {"copy-size", &copy_size_cmd_entry},
#line 1035 "cmds_gperf.gperf"
      {"txz-out", &txz_out_cmd_entry},
#line 830 "cmds_gperf.gperf"
      {"mkswap_U", &mkswap_U_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 831 "cmds_gperf.gperf"
      {"mkswap-U", &mkswap_U_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 788 "cmds_gperf.gperf"
      {"lvresize", &lvresize_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1041 "cmds_gperf.gperf"
      {"unmount-all", &umount_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 541 "cmds_gperf.gperf"
      {"debug_cmdline", &debug_cmdline_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 542 "cmds_gperf.gperf"
      {"debug-cmdline", &debug_cmdline_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 767 "cmds_gperf.gperf"
      {"luks_format", &luks_format_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 768 "cmds_gperf.gperf"
      {"luks-format", &luks_format_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 923 "cmds_gperf.gperf"
      {"scrub_file", &scrub_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 924 "cmds_gperf.gperf"
      {"scrub-file", &scrub_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 560 "cmds_gperf.gperf"
      {"echo", &echo_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 758 "cmds_gperf.gperf"
      {"lremovexattr", &lremovexattr_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 526 "cmds_gperf.gperf"
      {"copy_file_to_device", &copy_file_to_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 813 "cmds_gperf.gperf"
      {"mke2journal_U", &mke2journal_U_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 814 "cmds_gperf.gperf"
      {"mke2journal-U", &mke2journal_U_cmd_entry},
      {(char*)0}, {(char*)0},
#line 527 "cmds_gperf.gperf"
      {"copy-file-to-device", &copy_file_to_device_cmd_entry},
#line 545 "cmds_gperf.gperf"
      {"debug_upload", &debug_upload_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 546 "cmds_gperf.gperf"
      {"debug-upload", &debug_upload_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 648 "cmds_gperf.gperf"
      {"inotify_close", &inotify_close_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 649 "cmds_gperf.gperf"
      {"inotify-close", &inotify_close_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 784 "cmds_gperf.gperf"
      {"lvm_set_filter", &lvm_set_filter_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 785 "cmds_gperf.gperf"
      {"lvm-set-filter", &lvm_set_filter_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 930 "cmds_gperf.gperf"
      {"set_attach_method", &set_attach_method_cmd_entry},
      {(char*)0},
#line 769 "cmds_gperf.gperf"
      {"luks_format_cipher", &luks_format_cipher_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 931 "cmds_gperf.gperf"
      {"set-attach-method", &set_attach_method_cmd_entry},
      {(char*)0},
#line 770 "cmds_gperf.gperf"
      {"luks-format-cipher", &luks_format_cipher_cmd_entry},
      {(char*)0},
#line 765 "cmds_gperf.gperf"
      {"luks_close", &luks_close_cmd_entry},
      {(char*)0}, {(char*)0},
#line 548 "cmds_gperf.gperf"
      {"df_h", &df_h_cmd_entry},
#line 914 "cmds_gperf.gperf"
      {"resize2fs_size", &resize2fs_size_cmd_entry},
#line 766 "cmds_gperf.gperf"
      {"luks-close", &luks_close_cmd_entry},
      {(char*)0}, {(char*)0},
#line 549 "cmds_gperf.gperf"
      {"df-h", &df_h_cmd_entry},
#line 915 "cmds_gperf.gperf"
      {"resize2fs-size", &resize2fs_size_cmd_entry},
#line 555 "cmds_gperf.gperf"
      {"drop_caches", &drop_caches_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 556 "cmds_gperf.gperf"
      {"drop-caches", &drop_caches_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 982 "cmds_gperf.gperf"
      {"sfdisk_kernel_geometry", &sfdisk_kernel_geometry_cmd_entry},
      {(char*)0}, {(char*)0},
#line 856 "cmds_gperf.gperf"
      {"ntfsresize_size", &ntfsresize_size_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 857 "cmds_gperf.gperf"
      {"ntfsresize-size", &ntfsresize_size_cmd_entry},
#line 590 "cmds_gperf.gperf"
      {"get_attach_method", &get_attach_method_cmd_entry},
#line 983 "cmds_gperf.gperf"
      {"sfdisk-kernel-geometry", &sfdisk_kernel_geometry_cmd_entry},
#line 895 "cmds_gperf.gperf"
      {"pvs_full", &pvs_full_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 896 "cmds_gperf.gperf"
      {"pvs-full", &pvs_full_cmd_entry},
      {(char*)0}, {(char*)0},
#line 591 "cmds_gperf.gperf"
      {"get-attach-method", &get_attach_method_cmd_entry},
      {(char*)0}, {(char*)0},
#line 668 "cmds_gperf.gperf"
      {"inspect_get_hostname", &inspect_get_hostname_cmd_entry},
      {(char*)0},
#line 778 "cmds_gperf.gperf"
      {"lvm_canonical_lv_name", &lvm_canonical_lv_name_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 669 "cmds_gperf.gperf"
      {"inspect-get-hostname", &inspect_get_hostname_cmd_entry},
      {(char*)0},
#line 779 "cmds_gperf.gperf"
      {"lvm-canonical-lv-name", &lvm_canonical_lv_name_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 828 "cmds_gperf.gperf"
      {"mkswap_L", &mkswap_L_cmd_entry},
#line 512 "cmds_gperf.gperf"
      {"chmod", &chmod_cmd_entry},
#line 650 "cmds_gperf.gperf"
      {"inotify_files", &inotify_files_cmd_entry},
      {(char*)0}, {(char*)0},
#line 829 "cmds_gperf.gperf"
      {"mkswap-L", &mkswap_L_cmd_entry},
      {(char*)0},
#line 651 "cmds_gperf.gperf"
      {"inotify-files", &inotify_files_cmd_entry},
      {(char*)0},
#line 1003 "cmds_gperf.gperf"
      {"swapoff_uuid", &swapoff_uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1004 "cmds_gperf.gperf"
      {"swapoff-uuid", &swapoff_uuid_cmd_entry},
#line 1064 "cmds_gperf.gperf"
      {"vgs_full", &vgs_full_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 726 "cmds_gperf.gperf"
      {"is_symlink", &is_symlink_cmd_entry},
#line 1065 "cmds_gperf.gperf"
      {"vgs-full", &vgs_full_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 727 "cmds_gperf.gperf"
      {"is-symlink", &is_symlink_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 631 "cmds_gperf.gperf"
      {"glob_expand", &glob_expand_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 632 "cmds_gperf.gperf"
      {"glob-expand", &glob_expand_cmd_entry},
      {(char*)0},
#line 746 "cmds_gperf.gperf"
      {"list_filesystems", &list_filesystems_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 635 "cmds_gperf.gperf"
      {"grub_install", &grub_install_cmd_entry},
#line 747 "cmds_gperf.gperf"
      {"list-filesystems", &list_filesystems_cmd_entry},
#line 1059 "cmds_gperf.gperf"
      {"vglvuuids", &vglvuuids_cmd_entry},
      {(char*)0}, {(char*)0},
#line 636 "cmds_gperf.gperf"
      {"grub-install", &grub_install_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 789 "cmds_gperf.gperf"
      {"lvresize_free", &lvresize_free_cmd_entry},
#line 646 "cmds_gperf.gperf"
      {"inotify_add_watch", &inotify_add_watch_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 790 "cmds_gperf.gperf"
      {"lvresize-free", &lvresize_free_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 647 "cmds_gperf.gperf"
      {"inotify-add-watch", &inotify_add_watch_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 811 "cmds_gperf.gperf"
      {"mke2journal_L", &mke2journal_L_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 812 "cmds_gperf.gperf"
      {"mke2journal-L", &mke2journal_L_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1026 "cmds_gperf.gperf"
      {"touch", &touch_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 997 "cmds_gperf.gperf"
      {"swapoff_device", &swapoff_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 998 "cmds_gperf.gperf"
      {"swapoff-device", &swapoff_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 528 "cmds_gperf.gperf"
      {"copy_file_to_file", &copy_file_to_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 908 "cmds_gperf.gperf"
      {"realpath", &realpath_cmd_entry},
#line 892 "cmds_gperf.gperf"
      {"pvresize_size", &pvresize_size_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 893 "cmds_gperf.gperf"
      {"pvresize-size", &pvresize_size_cmd_entry},
#line 529 "cmds_gperf.gperf"
      {"copy-file-to-file", &copy_file_to_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 561 "cmds_gperf.gperf"
      {"echo_daemon", &echo_daemon_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 562 "cmds_gperf.gperf"
      {"echo-daemon", &echo_daemon_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 987 "cmds_gperf.gperf"
      {"sh_lines", &sh_lines_cmd_entry},
#line 465 "cmds_gperf.gperf"
      {"aug_match", &aug_match_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 988 "cmds_gperf.gperf"
      {"sh-lines", &sh_lines_cmd_entry},
#line 466 "cmds_gperf.gperf"
      {"aug-match", &aug_match_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 475 "cmds_gperf.gperf"
      {"available", &available_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 656 "cmds_gperf.gperf"
      {"inotify_rm_watch", &inotify_rm_watch_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 657 "cmds_gperf.gperf"
      {"inotify-rm-watch", &inotify_rm_watch_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 553 "cmds_gperf.gperf"
      {"download_offset", &download_offset_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 554 "cmds_gperf.gperf"
      {"download-offset", &download_offset_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 999 "cmds_gperf.gperf"
      {"swapoff_file", &swapoff_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1000 "cmds_gperf.gperf"
      {"swapoff-file", &swapoff_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 708 "cmds_gperf.gperf"
      {"is_chardev", &is_chardev_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 709 "cmds_gperf.gperf"
      {"is-chardev", &is_chardev_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 641 "cmds_gperf.gperf"
      {"hexedit", &hexedit_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 832 "cmds_gperf.gperf"
      {"mkswap_file", &mkswap_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 833 "cmds_gperf.gperf"
      {"mkswap-file", &mkswap_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 583 "cmds_gperf.gperf"
      {"findfs_label", &findfs_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 584 "cmds_gperf.gperf"
      {"findfs-label", &findfs_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 792 "cmds_gperf.gperf"
      {"lvs_full", &lvs_full_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 793 "cmds_gperf.gperf"
      {"lvs-full", &lvs_full_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 780 "cmds_gperf.gperf"
      {"lvm_clear_filter", &lvm_clear_filter_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 781 "cmds_gperf.gperf"
      {"lvm-clear-filter", &lvm_clear_filter_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1048 "cmds_gperf.gperf"
      {"vfs_label", &vfs_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1049 "cmds_gperf.gperf"
      {"vfs-label", &vfs_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 494 "cmds_gperf.gperf"
      {"blockdev_rereadpt", &blockdev_rereadpt_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 495 "cmds_gperf.gperf"
      {"blockdev-rereadpt", &blockdev_rereadpt_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 704 "cmds_gperf.gperf"
      {"is_blockdev", &is_blockdev_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 734 "cmds_gperf.gperf"
      {"launch", &launch_cmd_entry},
#line 705 "cmds_gperf.gperf"
      {"is-blockdev", &is_blockdev_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 490 "cmds_gperf.gperf"
      {"blockdev_getss", &blockdev_getss_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 491 "cmds_gperf.gperf"
      {"blockdev-getss", &blockdev_getss_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 488 "cmds_gperf.gperf"
      {"blockdev_getsize64", &blockdev_getsize64_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 489 "cmds_gperf.gperf"
      {"blockdev-getsize64", &blockdev_getsize64_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 502 "cmds_gperf.gperf"
      {"btrfs_filesystem_resize", &btrfs_filesystem_resize_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 503 "cmds_gperf.gperf"
      {"btrfs-filesystem-resize", &btrfs_filesystem_resize_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 498 "cmds_gperf.gperf"
      {"blockdev_setro", &blockdev_setro_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 499 "cmds_gperf.gperf"
      {"blockdev-setro", &blockdev_setro_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 718 "cmds_gperf.gperf"
      {"is_launching", &is_launching_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 719 "cmds_gperf.gperf"
      {"is-launching", &is_launching_cmd_entry},
      {(char*)0}, {(char*)0},
#line 763 "cmds_gperf.gperf"
      {"luks_add_key", &luks_add_key_cmd_entry},
      {(char*)0},
#line 575 "cmds_gperf.gperf"
      {"file_architecture", &file_architecture_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 576 "cmds_gperf.gperf"
      {"file-architecture", &file_architecture_cmd_entry},
      {(char*)0}, {(char*)0},
#line 764 "cmds_gperf.gperf"
      {"luks-add-key", &luks_add_key_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 486 "cmds_gperf.gperf"
      {"blockdev_getro", &blockdev_getro_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 487 "cmds_gperf.gperf"
      {"blockdev-getro", &blockdev_getro_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1009 "cmds_gperf.gperf"
      {"swapon_label", &swapon_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1010 "cmds_gperf.gperf"
      {"swapon-label", &swapon_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 640 "cmds_gperf.gperf"
      {"hexdump", &hexdump_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 732 "cmds_gperf.gperf"
      {"kill_subprocess", &kill_subprocess_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 733 "cmds_gperf.gperf"
      {"kill-subprocess", &kill_subprocess_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 513 "cmds_gperf.gperf"
      {"chown", &chown_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 507 "cmds_gperf.gperf"
      {"checksum", &checksum_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 782 "cmds_gperf.gperf"
      {"lvm_remove_all", &lvm_remove_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 783 "cmds_gperf.gperf"
      {"lvm-remove-all", &lvm_remove_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 443 "cmds_gperf.gperf"
      {"add_drive_with_if", &add_drive_with_if_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 444 "cmds_gperf.gperf"
      {"add-drive-with-if", &add_drive_with_if_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 476 "cmds_gperf.gperf"
      {"available_all_groups", &available_all_groups_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 477 "cmds_gperf.gperf"
      {"available-all-groups", &available_all_groups_cmd_entry},
      {(char*)0},
#line 510 "cmds_gperf.gperf"
      {"checksums_out", &checksums_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 511 "cmds_gperf.gperf"
      {"checksums-out", &checksums_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1001 "cmds_gperf.gperf"
      {"swapoff_label", &swapoff_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1002 "cmds_gperf.gperf"
      {"swapoff-label", &swapoff_label_cmd_entry},
      {(char*)0},
#line 737 "cmds_gperf.gperf"
      {"lchown", &lchown_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 496 "cmds_gperf.gperf"
      {"blockdev_setbsz", &blockdev_setbsz_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 497 "cmds_gperf.gperf"
      {"blockdev-setbsz", &blockdev_setbsz_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 484 "cmds_gperf.gperf"
      {"blockdev_getbsz", &blockdev_getbsz_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 485 "cmds_gperf.gperf"
      {"blockdev-getbsz", &blockdev_getbsz_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 500 "cmds_gperf.gperf"
      {"blockdev_setrw", &blockdev_setrw_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 501 "cmds_gperf.gperf"
      {"blockdev-setrw", &blockdev_setrw_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 492 "cmds_gperf.gperf"
      {"blockdev_getsz", &blockdev_getsz_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 493 "cmds_gperf.gperf"
      {"blockdev-getsz", &blockdev_getsz_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 771 "cmds_gperf.gperf"
      {"luks_kill_slot", &luks_kill_slot_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 772 "cmds_gperf.gperf"
      {"luks-kill-slot", &luks_kill_slot_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 508 "cmds_gperf.gperf"
      {"checksum_device", &checksum_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 509 "cmds_gperf.gperf"
      {"checksum-device", &checksum_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 932 "cmds_gperf.gperf"
      {"attach-method", &set_attach_method_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 482 "cmds_gperf.gperf"
      {"blockdev_flushbufs", &blockdev_flushbufs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 483 "cmds_gperf.gperf"
      {"blockdev-flushbufs", &blockdev_flushbufs_cmd_entry}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].name;

          if (s && (((unsigned char)*str ^ (unsigned char)*s) & ~32) == 0 && !gperf_case_strcmp (str, s))
            return &wordlist[key];
        }
    }
  return 0;
}
