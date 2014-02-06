/* ANSI-C code produced by gperf version 3.0.4 */
/* Command-line: gperf -t cmds-gperf.gperf  */
/* Computed positions: -k'1-12,14,17,$' */

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

#line 29 "cmds-gperf.gperf"


#include <config.h>

#include <stdlib.h>
#include <string.h>

#include "cmds-gperf.h"

extern struct command_entry acl_delete_def_file_cmd_entry;
extern struct command_entry acl_get_file_cmd_entry;
extern struct command_entry acl_set_file_cmd_entry;
extern struct command_entry add_cdrom_cmd_entry;
extern struct command_entry add_domain_cmd_entry;
extern struct command_entry add_drive_cmd_entry;
extern struct command_entry add_drive_ro_cmd_entry;
extern struct command_entry add_drive_ro_with_if_cmd_entry;
extern struct command_entry add_drive_scratch_cmd_entry;
extern struct command_entry add_drive_with_if_cmd_entry;
extern struct command_entry alloc_cmd_entry;
extern struct command_entry aug_clear_cmd_entry;
extern struct command_entry aug_close_cmd_entry;
extern struct command_entry aug_defnode_cmd_entry;
extern struct command_entry aug_defvar_cmd_entry;
extern struct command_entry aug_get_cmd_entry;
extern struct command_entry aug_init_cmd_entry;
extern struct command_entry aug_insert_cmd_entry;
extern struct command_entry aug_label_cmd_entry;
extern struct command_entry aug_load_cmd_entry;
extern struct command_entry aug_ls_cmd_entry;
extern struct command_entry aug_match_cmd_entry;
extern struct command_entry aug_mv_cmd_entry;
extern struct command_entry aug_rm_cmd_entry;
extern struct command_entry aug_save_cmd_entry;
extern struct command_entry aug_set_cmd_entry;
extern struct command_entry aug_setm_cmd_entry;
extern struct command_entry available_cmd_entry;
extern struct command_entry available_all_groups_cmd_entry;
extern struct command_entry base64_in_cmd_entry;
extern struct command_entry base64_out_cmd_entry;
extern struct command_entry blkid_cmd_entry;
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
extern struct command_entry btrfs_device_add_cmd_entry;
extern struct command_entry btrfs_device_delete_cmd_entry;
extern struct command_entry btrfs_filesystem_balance_cmd_entry;
extern struct command_entry btrfs_filesystem_resize_cmd_entry;
extern struct command_entry btrfs_filesystem_sync_cmd_entry;
extern struct command_entry btrfs_fsck_cmd_entry;
extern struct command_entry btrfs_set_seeding_cmd_entry;
extern struct command_entry btrfs_subvolume_create_cmd_entry;
extern struct command_entry btrfs_subvolume_delete_cmd_entry;
extern struct command_entry btrfs_subvolume_list_cmd_entry;
extern struct command_entry btrfs_subvolume_set_default_cmd_entry;
extern struct command_entry btrfs_subvolume_snapshot_cmd_entry;
extern struct command_entry canonical_device_name_cmd_entry;
extern struct command_entry cap_get_file_cmd_entry;
extern struct command_entry cap_set_file_cmd_entry;
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
extern struct command_entry copy_attributes_cmd_entry;
extern struct command_entry copy_device_to_device_cmd_entry;
extern struct command_entry copy_device_to_file_cmd_entry;
extern struct command_entry copy_file_to_device_cmd_entry;
extern struct command_entry copy_file_to_file_cmd_entry;
extern struct command_entry copy_in_cmd_entry;
extern struct command_entry copy_out_cmd_entry;
extern struct command_entry copy_size_cmd_entry;
extern struct command_entry cp_cmd_entry;
extern struct command_entry cp_a_cmd_entry;
extern struct command_entry cp_r_cmd_entry;
extern struct command_entry dd_cmd_entry;
extern struct command_entry debug_cmd_entry;
extern struct command_entry debug_drives_cmd_entry;
extern struct command_entry debug_upload_cmd_entry;
extern struct command_entry delete_event_cmd_entry;
extern struct command_entry device_index_cmd_entry;
extern struct command_entry df_cmd_entry;
extern struct command_entry df_h_cmd_entry;
extern struct command_entry disk_create_cmd_entry;
extern struct command_entry disk_format_cmd_entry;
extern struct command_entry disk_has_backing_file_cmd_entry;
extern struct command_entry disk_virtual_size_cmd_entry;
extern struct command_entry display_cmd_entry;
extern struct command_entry dmesg_cmd_entry;
extern struct command_entry download_cmd_entry;
extern struct command_entry download_offset_cmd_entry;
extern struct command_entry drop_caches_cmd_entry;
extern struct command_entry du_cmd_entry;
extern struct command_entry e2fsck_cmd_entry;
extern struct command_entry e2fsck_f_cmd_entry;
extern struct command_entry echo_cmd_entry;
extern struct command_entry echo_daemon_cmd_entry;
extern struct command_entry edit_cmd_entry;
extern struct command_entry egrep_cmd_entry;
extern struct command_entry egrepi_cmd_entry;
extern struct command_entry equal_cmd_entry;
extern struct command_entry event_cmd_entry;
extern struct command_entry exists_cmd_entry;
extern struct command_entry extlinux_cmd_entry;
extern struct command_entry fallocate_cmd_entry;
extern struct command_entry fallocate64_cmd_entry;
extern struct command_entry feature_available_cmd_entry;
extern struct command_entry fgrep_cmd_entry;
extern struct command_entry fgrepi_cmd_entry;
extern struct command_entry file_cmd_entry;
extern struct command_entry file_architecture_cmd_entry;
extern struct command_entry filesize_cmd_entry;
extern struct command_entry filesystem_available_cmd_entry;
extern struct command_entry fill_cmd_entry;
extern struct command_entry fill_dir_cmd_entry;
extern struct command_entry fill_pattern_cmd_entry;
extern struct command_entry find_cmd_entry;
extern struct command_entry find0_cmd_entry;
extern struct command_entry findfs_label_cmd_entry;
extern struct command_entry findfs_uuid_cmd_entry;
extern struct command_entry fsck_cmd_entry;
extern struct command_entry fstrim_cmd_entry;
extern struct command_entry get_append_cmd_entry;
extern struct command_entry get_attach_method_cmd_entry;
extern struct command_entry get_autosync_cmd_entry;
extern struct command_entry get_backend_cmd_entry;
extern struct command_entry get_backend_settings_cmd_entry;
extern struct command_entry get_cachedir_cmd_entry;
extern struct command_entry get_direct_cmd_entry;
extern struct command_entry get_e2attrs_cmd_entry;
extern struct command_entry get_e2generation_cmd_entry;
extern struct command_entry get_e2label_cmd_entry;
extern struct command_entry get_e2uuid_cmd_entry;
extern struct command_entry get_hv_cmd_entry;
extern struct command_entry get_libvirt_requested_credential_challenge_cmd_entry;
extern struct command_entry get_libvirt_requested_credential_defresult_cmd_entry;
extern struct command_entry get_libvirt_requested_credential_prompt_cmd_entry;
extern struct command_entry get_libvirt_requested_credentials_cmd_entry;
extern struct command_entry get_memsize_cmd_entry;
extern struct command_entry get_network_cmd_entry;
extern struct command_entry get_path_cmd_entry;
extern struct command_entry get_pgroup_cmd_entry;
extern struct command_entry get_pid_cmd_entry;
extern struct command_entry get_program_cmd_entry;
extern struct command_entry get_qemu_cmd_entry;
extern struct command_entry get_recovery_proc_cmd_entry;
extern struct command_entry get_selinux_cmd_entry;
extern struct command_entry get_smp_cmd_entry;
extern struct command_entry get_tmpdir_cmd_entry;
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
extern struct command_entry hivex_close_cmd_entry;
extern struct command_entry hivex_commit_cmd_entry;
extern struct command_entry hivex_node_add_child_cmd_entry;
extern struct command_entry hivex_node_children_cmd_entry;
extern struct command_entry hivex_node_delete_child_cmd_entry;
extern struct command_entry hivex_node_get_child_cmd_entry;
extern struct command_entry hivex_node_get_value_cmd_entry;
extern struct command_entry hivex_node_name_cmd_entry;
extern struct command_entry hivex_node_parent_cmd_entry;
extern struct command_entry hivex_node_set_value_cmd_entry;
extern struct command_entry hivex_node_values_cmd_entry;
extern struct command_entry hivex_open_cmd_entry;
extern struct command_entry hivex_root_cmd_entry;
extern struct command_entry hivex_value_key_cmd_entry;
extern struct command_entry hivex_value_type_cmd_entry;
extern struct command_entry hivex_value_utf8_cmd_entry;
extern struct command_entry hivex_value_value_cmd_entry;
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
extern struct command_entry inspect_list_applications2_cmd_entry;
extern struct command_entry inspect_os_cmd_entry;
extern struct command_entry is_blockdev_cmd_entry;
extern struct command_entry is_chardev_cmd_entry;
extern struct command_entry is_config_cmd_entry;
extern struct command_entry is_dir_cmd_entry;
extern struct command_entry is_fifo_cmd_entry;
extern struct command_entry is_file_cmd_entry;
extern struct command_entry is_lv_cmd_entry;
extern struct command_entry is_socket_cmd_entry;
extern struct command_entry is_symlink_cmd_entry;
extern struct command_entry is_whole_device_cmd_entry;
extern struct command_entry is_zero_cmd_entry;
extern struct command_entry is_zero_device_cmd_entry;
extern struct command_entry isoinfo_cmd_entry;
extern struct command_entry isoinfo_device_cmd_entry;
extern struct command_entry journal_close_cmd_entry;
extern struct command_entry journal_get_cmd_entry;
extern struct command_entry journal_get_data_threshold_cmd_entry;
extern struct command_entry journal_next_cmd_entry;
extern struct command_entry journal_open_cmd_entry;
extern struct command_entry journal_set_data_threshold_cmd_entry;
extern struct command_entry journal_skip_cmd_entry;
extern struct command_entry kill_subprocess_cmd_entry;
extern struct command_entry launch_cmd_entry;
extern struct command_entry lcd_cmd_entry;
extern struct command_entry lchown_cmd_entry;
extern struct command_entry ldmtool_create_all_cmd_entry;
extern struct command_entry ldmtool_diskgroup_disks_cmd_entry;
extern struct command_entry ldmtool_diskgroup_name_cmd_entry;
extern struct command_entry ldmtool_diskgroup_volumes_cmd_entry;
extern struct command_entry ldmtool_remove_all_cmd_entry;
extern struct command_entry ldmtool_scan_cmd_entry;
extern struct command_entry ldmtool_scan_devices_cmd_entry;
extern struct command_entry ldmtool_volume_hint_cmd_entry;
extern struct command_entry ldmtool_volume_partitions_cmd_entry;
extern struct command_entry ldmtool_volume_type_cmd_entry;
extern struct command_entry lgetxattr_cmd_entry;
extern struct command_entry lgetxattrs_cmd_entry;
extern struct command_entry list_9p_cmd_entry;
extern struct command_entry list_devices_cmd_entry;
extern struct command_entry list_disk_labels_cmd_entry;
extern struct command_entry list_dm_devices_cmd_entry;
extern struct command_entry list_events_cmd_entry;
extern struct command_entry list_filesystems_cmd_entry;
extern struct command_entry list_ldm_partitions_cmd_entry;
extern struct command_entry list_ldm_volumes_cmd_entry;
extern struct command_entry list_md_devices_cmd_entry;
extern struct command_entry list_partitions_cmd_entry;
extern struct command_entry ll_cmd_entry;
extern struct command_entry llz_cmd_entry;
extern struct command_entry ln_cmd_entry;
extern struct command_entry ln_f_cmd_entry;
extern struct command_entry ln_s_cmd_entry;
extern struct command_entry ln_sf_cmd_entry;
extern struct command_entry lremovexattr_cmd_entry;
extern struct command_entry ls_cmd_entry;
extern struct command_entry ls0_cmd_entry;
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
extern struct command_entry lvcreate_free_cmd_entry;
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
extern struct command_entry max_disks_cmd_entry;
extern struct command_entry md_create_cmd_entry;
extern struct command_entry md_detail_cmd_entry;
extern struct command_entry md_stat_cmd_entry;
extern struct command_entry md_stop_cmd_entry;
extern struct command_entry mkdir_cmd_entry;
extern struct command_entry mkdir_mode_cmd_entry;
extern struct command_entry mkdir_p_cmd_entry;
extern struct command_entry mkdtemp_cmd_entry;
extern struct command_entry mke2fs_cmd_entry;
extern struct command_entry mke2fs_J_cmd_entry;
extern struct command_entry mke2fs_JL_cmd_entry;
extern struct command_entry mke2fs_JU_cmd_entry;
extern struct command_entry mke2journal_cmd_entry;
extern struct command_entry mke2journal_L_cmd_entry;
extern struct command_entry mke2journal_U_cmd_entry;
extern struct command_entry mkfifo_cmd_entry;
extern struct command_entry mkfs_cmd_entry;
extern struct command_entry mkfs_b_cmd_entry;
extern struct command_entry mkfs_btrfs_cmd_entry;
extern struct command_entry mklost_and_found_cmd_entry;
extern struct command_entry mkmountpoint_cmd_entry;
extern struct command_entry mknod_cmd_entry;
extern struct command_entry mknod_b_cmd_entry;
extern struct command_entry mknod_c_cmd_entry;
extern struct command_entry mkswap_cmd_entry;
extern struct command_entry mkswap_L_cmd_entry;
extern struct command_entry mkswap_U_cmd_entry;
extern struct command_entry mkswap_file_cmd_entry;
extern struct command_entry mktemp_cmd_entry;
extern struct command_entry modprobe_cmd_entry;
extern struct command_entry more_cmd_entry;
extern struct command_entry mount_cmd_entry;
extern struct command_entry mount_9p_cmd_entry;
extern struct command_entry mount_local_cmd_entry;
extern struct command_entry mount_local_run_cmd_entry;
extern struct command_entry mount_loop_cmd_entry;
extern struct command_entry mount_options_cmd_entry;
extern struct command_entry mount_ro_cmd_entry;
extern struct command_entry mount_vfs_cmd_entry;
extern struct command_entry mountpoints_cmd_entry;
extern struct command_entry mounts_cmd_entry;
extern struct command_entry mv_cmd_entry;
extern struct command_entry nr_devices_cmd_entry;
extern struct command_entry ntfs_3g_probe_cmd_entry;
extern struct command_entry ntfsclone_in_cmd_entry;
extern struct command_entry ntfsclone_out_cmd_entry;
extern struct command_entry ntfsfix_cmd_entry;
extern struct command_entry ntfsresize_cmd_entry;
extern struct command_entry ntfsresize_size_cmd_entry;
extern struct command_entry parse_environment_cmd_entry;
extern struct command_entry parse_environment_list_cmd_entry;
extern struct command_entry part_add_cmd_entry;
extern struct command_entry part_del_cmd_entry;
extern struct command_entry part_disk_cmd_entry;
extern struct command_entry part_get_bootable_cmd_entry;
extern struct command_entry part_get_gpt_type_cmd_entry;
extern struct command_entry part_get_mbr_id_cmd_entry;
extern struct command_entry part_get_name_cmd_entry;
extern struct command_entry part_get_parttype_cmd_entry;
extern struct command_entry part_init_cmd_entry;
extern struct command_entry part_list_cmd_entry;
extern struct command_entry part_set_bootable_cmd_entry;
extern struct command_entry part_set_gpt_type_cmd_entry;
extern struct command_entry part_set_mbr_id_cmd_entry;
extern struct command_entry part_set_name_cmd_entry;
extern struct command_entry part_to_dev_cmd_entry;
extern struct command_entry part_to_partnum_cmd_entry;
extern struct command_entry ping_daemon_cmd_entry;
extern struct command_entry pread_cmd_entry;
extern struct command_entry pread_device_cmd_entry;
extern struct command_entry pvchange_uuid_cmd_entry;
extern struct command_entry pvchange_uuid_all_cmd_entry;
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
extern struct command_entry remount_cmd_entry;
extern struct command_entry remove_drive_cmd_entry;
extern struct command_entry removexattr_cmd_entry;
extern struct command_entry rename_cmd_entry;
extern struct command_entry reopen_cmd_entry;
extern struct command_entry resize2fs_cmd_entry;
extern struct command_entry resize2fs_M_cmd_entry;
extern struct command_entry resize2fs_size_cmd_entry;
extern struct command_entry rm_cmd_entry;
extern struct command_entry rm_f_cmd_entry;
extern struct command_entry rm_rf_cmd_entry;
extern struct command_entry rmdir_cmd_entry;
extern struct command_entry rmmountpoint_cmd_entry;
extern struct command_entry rsync_cmd_entry;
extern struct command_entry rsync_in_cmd_entry;
extern struct command_entry rsync_out_cmd_entry;
extern struct command_entry scrub_device_cmd_entry;
extern struct command_entry scrub_file_cmd_entry;
extern struct command_entry scrub_freespace_cmd_entry;
extern struct command_entry set_append_cmd_entry;
extern struct command_entry set_attach_method_cmd_entry;
extern struct command_entry set_autosync_cmd_entry;
extern struct command_entry set_backend_cmd_entry;
extern struct command_entry set_backend_settings_cmd_entry;
extern struct command_entry set_cachedir_cmd_entry;
extern struct command_entry set_direct_cmd_entry;
extern struct command_entry set_e2attrs_cmd_entry;
extern struct command_entry set_e2generation_cmd_entry;
extern struct command_entry set_e2label_cmd_entry;
extern struct command_entry set_e2uuid_cmd_entry;
extern struct command_entry set_hv_cmd_entry;
extern struct command_entry set_label_cmd_entry;
extern struct command_entry set_libvirt_requested_credential_cmd_entry;
extern struct command_entry set_libvirt_supported_credentials_cmd_entry;
extern struct command_entry set_memsize_cmd_entry;
extern struct command_entry set_network_cmd_entry;
extern struct command_entry set_path_cmd_entry;
extern struct command_entry set_pgroup_cmd_entry;
extern struct command_entry set_program_cmd_entry;
extern struct command_entry set_qemu_cmd_entry;
extern struct command_entry set_recovery_proc_cmd_entry;
extern struct command_entry set_selinux_cmd_entry;
extern struct command_entry set_smp_cmd_entry;
extern struct command_entry set_tmpdir_cmd_entry;
extern struct command_entry set_trace_cmd_entry;
extern struct command_entry set_uuid_cmd_entry;
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
extern struct command_entry shutdown_cmd_entry;
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
extern struct command_entry syslinux_cmd_entry;
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
extern struct command_entry tune2fs_cmd_entry;
extern struct command_entry tune2fs_l_cmd_entry;
extern struct command_entry txz_in_cmd_entry;
extern struct command_entry txz_out_cmd_entry;
extern struct command_entry umask_cmd_entry;
extern struct command_entry umount_cmd_entry;
extern struct command_entry umount_all_cmd_entry;
extern struct command_entry umount_local_cmd_entry;
extern struct command_entry unsetenv_cmd_entry;
extern struct command_entry upload_cmd_entry;
extern struct command_entry upload_offset_cmd_entry;
extern struct command_entry user_cancel_cmd_entry;
extern struct command_entry utimens_cmd_entry;
extern struct command_entry utsname_cmd_entry;
extern struct command_entry version_cmd_entry;
extern struct command_entry vfs_label_cmd_entry;
extern struct command_entry vfs_type_cmd_entry;
extern struct command_entry vfs_uuid_cmd_entry;
extern struct command_entry vg_activate_cmd_entry;
extern struct command_entry vg_activate_all_cmd_entry;
extern struct command_entry vgchange_uuid_cmd_entry;
extern struct command_entry vgchange_uuid_all_cmd_entry;
extern struct command_entry vgcreate_cmd_entry;
extern struct command_entry vglvuuids_cmd_entry;
extern struct command_entry vgmeta_cmd_entry;
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
extern struct command_entry wipefs_cmd_entry;
extern struct command_entry write_cmd_entry;
extern struct command_entry write_append_cmd_entry;
extern struct command_entry write_file_cmd_entry;
extern struct command_entry xfs_admin_cmd_entry;
extern struct command_entry xfs_growfs_cmd_entry;
extern struct command_entry xfs_info_cmd_entry;
extern struct command_entry xfs_repair_cmd_entry;
extern struct command_entry zegrep_cmd_entry;
extern struct command_entry zegrepi_cmd_entry;
extern struct command_entry zero_cmd_entry;
extern struct command_entry zero_device_cmd_entry;
extern struct command_entry zero_free_space_cmd_entry;
extern struct command_entry zerofree_cmd_entry;
extern struct command_entry zfgrep_cmd_entry;
extern struct command_entry zfgrepi_cmd_entry;
extern struct command_entry zfile_cmd_entry;
extern struct command_entry zgrep_cmd_entry;
extern struct command_entry zgrepi_cmd_entry;
#line 567 "cmds-gperf.gperf"
struct command_table;

#define TOTAL_KEYWORDS 946
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 42
#define MIN_HASH_VALUE 19
#define MAX_HASH_VALUE 7670
/* maximum key range = 7652, duplicates = 0 */

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
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671,   10,  835, 7671,    0, 7671,
       550,    0,    0, 7671,   30, 7671,    0,    5,    0, 7671,
      7671, 7671, 7671, 7671, 7671,    0,  495,  140,  425,    0,
       986,    5,  518,    5, 1619,  865,  370,  290,   50,   10,
        55,  360,   35,    0,    5,    5,  790, 1419,  483,  700,
      1629,   40, 7671, 7671, 7671,    0,  155,    0,  495,  140,
       425,    0,  986,    5,  518,    5, 1619,  865,  370,  290,
        50,   10,   55,  360,   35,    0,    5,    5,  790, 1419,
       483,  700, 1629,   40, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671, 7671,
      7671, 7671, 7671, 7671, 7671, 7671, 7671
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[16]];
      /*FALLTHROUGH*/
      case 16:
      case 15:
      case 14:
        hval += asso_values[(unsigned char)str[13]];
      /*FALLTHROUGH*/
      case 13:
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
        hval += asso_values[(unsigned char)str[6]+1];
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
  return hval + asso_values[(unsigned char)str[len - 1]];
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
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1391 "cmds-gperf.gperf"
      {"stat", &stat_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 625 "cmds-gperf.gperf"
      {"aug_set", &aug_set_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 605 "cmds-gperf.gperf"
      {"aug_get", &aug_get_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 626 "cmds-gperf.gperf"
      {"aug-set", &aug_set_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 606 "cmds-gperf.gperf"
      {"aug-get", &aug_get_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1421 "cmds-gperf.gperf"
      {"tar_out", &tar_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1422 "cmds-gperf.gperf"
      {"tar-out", &tar_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1390 "cmds-gperf.gperf"
      {"sparse", &sparse_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 864 "cmds-gperf.gperf"
      {"grepi", &grepi_cmd_entry},
#line 765 "cmds-gperf.gperf"
      {"egrepi", &egrepi_cmd_entry},
#line 1393 "cmds-gperf.gperf"
      {"strings", &strings_cmd_entry},
      {(char*)0},
#line 1394 "cmds-gperf.gperf"
      {"strings_e", &strings_e_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1395 "cmds-gperf.gperf"
      {"strings-e", &strings_e_cmd_entry},
#line 609 "cmds-gperf.gperf"
      {"aug_insert", &aug_insert_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1223 "cmds-gperf.gperf"
      {"part_init", &part_init_cmd_entry},
#line 610 "cmds-gperf.gperf"
      {"aug-insert", &aug_insert_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1020 "cmds-gperf.gperf"
      {"run", &launch_cmd_entry},
#line 1224 "cmds-gperf.gperf"
      {"part-init", &part_init_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1418 "cmds-gperf.gperf"
      {"tar_in", &tar_in_cmd_entry},
      {(char*)0},
#line 689 "cmds-gperf.gperf"
      {"cat", &cat_cmd_entry},
#line 862 "cmds-gperf.gperf"
      {"grep", &grep_cmd_entry},
#line 764 "cmds-gperf.gperf"
      {"egrep", &egrep_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1419 "cmds-gperf.gperf"
      {"tar-in", &tar_in_cmd_entry},
#line 1423 "cmds-gperf.gperf"
      {"tar-out-opts", &tar_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1366 "cmds-gperf.gperf"
      {"trace", &set_trace_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 722 "cmds-gperf.gperf"
      {"cp_a", &cp_a_cmd_entry},
#line 1343 "cmds-gperf.gperf"
      {"set_pgroup", &set_pgroup_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 833 "cmds-gperf.gperf"
      {"get_pgroup", &get_pgroup_cmd_entry},
#line 1273 "cmds-gperf.gperf"
      {"reopen", &reopen_cmd_entry},
      {(char*)0}, {(char*)0},
#line 723 "cmds-gperf.gperf"
      {"cp-a", &cp_a_cmd_entry},
#line 1344 "cmds-gperf.gperf"
      {"set-pgroup", &set_pgroup_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 834 "cmds-gperf.gperf"
      {"get-pgroup", &get_pgroup_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1345 "cmds-gperf.gperf"
      {"pgroup", &set_pgroup_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 976 "cmds-gperf.gperf"
      {"is_config", &is_config_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 977 "cmds-gperf.gperf"
      {"is-config", &is_config_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1430 "cmds-gperf.gperf"
      {"truncate", &truncate_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 721 "cmds-gperf.gperf"
      {"cp", &cp_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1372 "cmds-gperf.gperf"
      {"setcon", &setcon_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 856 "cmds-gperf.gperf"
      {"getcon", &getcon_cmd_entry},
      {(char*)0}, {(char*)0},
#line 724 "cmds-gperf.gperf"
      {"cp_r", &cp_r_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 968 "cmds-gperf.gperf"
      {"inspect_os", &inspect_os_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 725 "cmds-gperf.gperf"
      {"cp-r", &cp_r_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 969 "cmds-gperf.gperf"
      {"inspect-os", &inspect_os_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 950 "cmds-gperf.gperf"
      {"inspect_get_roots", &inspect_get_roots_cmd_entry},
#line 928 "cmds-gperf.gperf"
      {"inspect_get_filesystems", &inspect_get_filesystems_cmd_entry},
      {(char*)0}, {(char*)0},
#line 942 "cmds-gperf.gperf"
      {"inspect_get_package_format", &inspect_get_package_format_cmd_entry},
      {(char*)0},
#line 930 "cmds-gperf.gperf"
      {"inspect_get_format", &inspect_get_format_cmd_entry},
      {(char*)0},
#line 944 "cmds-gperf.gperf"
      {"inspect_get_package_management", &inspect_get_package_management_cmd_entry},
      {(char*)0}, {(char*)0},
#line 940 "cmds-gperf.gperf"
      {"inspect_get_mountpoints", &inspect_get_mountpoints_cmd_entry},
#line 1428 "cmds-gperf.gperf"
      {"time", &time_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 951 "cmds-gperf.gperf"
      {"inspect-get-roots", &inspect_get_roots_cmd_entry},
#line 929 "cmds-gperf.gperf"
      {"inspect-get-filesystems", &inspect_get_filesystems_cmd_entry},
      {(char*)0},
#line 956 "cmds-gperf.gperf"
      {"inspect_get_windows_systemroot", &inspect_get_windows_systemroot_cmd_entry},
#line 943 "cmds-gperf.gperf"
      {"inspect-get-package-format", &inspect_get_package_format_cmd_entry},
      {(char*)0},
#line 931 "cmds-gperf.gperf"
      {"inspect-get-format", &inspect_get_format_cmd_entry},
      {(char*)0},
#line 945 "cmds-gperf.gperf"
      {"inspect-get-package-management", &inspect_get_package_management_cmd_entry},
      {(char*)0}, {(char*)0},
#line 941 "cmds-gperf.gperf"
      {"inspect-get-mountpoints", &inspect_get_mountpoints_cmd_entry},
#line 954 "cmds-gperf.gperf"
      {"inspect_get_windows_current_control_set", &inspect_get_windows_current_control_set_cmd_entry},
      {(char*)0},
#line 926 "cmds-gperf.gperf"
      {"inspect_get_drive_mappings", &inspect_get_drive_mappings_cmd_entry},
      {(char*)0}, {(char*)0},
#line 946 "cmds-gperf.gperf"
      {"inspect_get_product_name", &inspect_get_product_name_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 924 "cmds-gperf.gperf"
      {"inspect_get_distro", &inspect_get_distro_cmd_entry},
      {(char*)0},
#line 957 "cmds-gperf.gperf"
      {"inspect-get-windows-systemroot", &inspect_get_windows_systemroot_cmd_entry},
      {(char*)0},
#line 948 "cmds-gperf.gperf"
      {"inspect_get_product_variant", &inspect_get_product_variant_cmd_entry},
#line 962 "cmds-gperf.gperf"
      {"inspect_is_netinst", &inspect_is_netinst_cmd_entry},
#line 1170 "cmds-gperf.gperf"
      {"more", &more_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 955 "cmds-gperf.gperf"
      {"inspect-get-windows-current-control-set", &inspect_get_windows_current_control_set_cmd_entry},
#line 932 "cmds-gperf.gperf"
      {"inspect_get_hostname", &inspect_get_hostname_cmd_entry},
#line 927 "cmds-gperf.gperf"
      {"inspect-get-drive-mappings", &inspect_get_drive_mappings_cmd_entry},
      {(char*)0}, {(char*)0},
#line 947 "cmds-gperf.gperf"
      {"inspect-get-product-name", &inspect_get_product_name_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 925 "cmds-gperf.gperf"
      {"inspect-get-distro", &inspect_get_distro_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 949 "cmds-gperf.gperf"
      {"inspect-get-product-variant", &inspect_get_product_variant_cmd_entry},
#line 963 "cmds-gperf.gperf"
      {"inspect-is-netinst", &inspect_is_netinst_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 933 "cmds-gperf.gperf"
      {"inspect-get-hostname", &inspect_get_hostname_cmd_entry},
#line 1188 "cmds-gperf.gperf"
      {"mounts", &mounts_cmd_entry},
#line 1455 "cmds-gperf.gperf"
      {"utimens", &utimens_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1172 "cmds-gperf.gperf"
      {"mount", &mount_cmd_entry},
      {(char*)0},
#line 1075 "cmds-gperf.gperf"
      {"ls", &ls_cmd_entry},
#line 1076 "cmds-gperf.gperf"
      {"ls0", &ls0_cmd_entry},
#line 1171 "cmds-gperf.gperf"
      {"less", &more_cmd_entry},
#line 936 "cmds-gperf.gperf"
      {"inspect_get_major_version", &inspect_get_major_version_cmd_entry},
#line 1441 "cmds-gperf.gperf"
      {"umount", &umount_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 938 "cmds-gperf.gperf"
      {"inspect_get_minor_version", &inspect_get_minor_version_cmd_entry},
#line 1272 "cmds-gperf.gperf"
      {"rename", &rename_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 615 "cmds-gperf.gperf"
      {"aug_ls", &aug_ls_cmd_entry},
      {(char*)0},
#line 1183 "cmds-gperf.gperf"
      {"mount_ro", &mount_ro_cmd_entry},
      {(char*)0},
#line 1078 "cmds-gperf.gperf"
      {"lstat", &lstat_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1115 "cmds-gperf.gperf"
      {"man", &man_cmd_entry},
      {(char*)0},
#line 937 "cmds-gperf.gperf"
      {"inspect-get-major-version", &inspect_get_major_version_cmd_entry},
#line 616 "cmds-gperf.gperf"
      {"aug-ls", &aug_ls_cmd_entry},
      {(char*)0},
#line 1184 "cmds-gperf.gperf"
      {"mount-ro", &mount_ro_cmd_entry},
      {(char*)0},
#line 939 "cmds-gperf.gperf"
      {"inspect-get-minor-version", &inspect_get_minor_version_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1360 "cmds-gperf.gperf"
      {"smp", &set_smp_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1268 "cmds-gperf.gperf"
      {"remount", &remount_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1070 "cmds-gperf.gperf"
      {"ln_s", &ln_s_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1442 "cmds-gperf.gperf"
      {"unmount", &umount_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1349 "cmds-gperf.gperf"
      {"set_qemu", &set_qemu_cmd_entry},
#line 1071 "cmds-gperf.gperf"
      {"ln-s", &ln_s_cmd_entry},
#line 763 "cmds-gperf.gperf"
      {"emacs", &edit_cmd_entry},
      {(char*)0},
#line 754 "cmds-gperf.gperf"
      {"du", &du_cmd_entry},
#line 840 "cmds-gperf.gperf"
      {"get_qemu", &get_qemu_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1350 "cmds-gperf.gperf"
      {"set-qemu", &set_qemu_cmd_entry},
#line 761 "cmds-gperf.gperf"
      {"edit", &edit_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 841 "cmds-gperf.gperf"
      {"get-qemu", &get_qemu_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 934 "cmds-gperf.gperf"
      {"inspect_get_icon", &inspect_get_icon_cmd_entry},
#line 1067 "cmds-gperf.gperf"
      {"ln", &ln_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1173 "cmds-gperf.gperf"
      {"mount_9p", &mount_9p_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1389 "cmds-gperf.gperf"
      {"sleep", &sleep_cmd_entry},
#line 1416 "cmds-gperf.gperf"
      {"tail_n", &tail_n_cmd_entry},
#line 1348 "cmds-gperf.gperf"
      {"program", &set_program_cmd_entry},
#line 1174 "cmds-gperf.gperf"
      {"mount-9p", &mount_9p_cmd_entry},
#line 863 "cmds-gperf.gperf"
      {"grep-opts", &grep_cmd_entry},
      {(char*)0},
#line 935 "cmds-gperf.gperf"
      {"inspect-get-icon", &inspect_get_icon_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1417 "cmds-gperf.gperf"
      {"tail-n", &tail_n_cmd_entry},
      {(char*)0}, {(char*)0},
#line 768 "cmds-gperf.gperf"
      {"exists", &exists_cmd_entry},
      {(char*)0}, {(char*)0},
#line 835 "cmds-gperf.gperf"
      {"get_pid", &get_pid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 978 "cmds-gperf.gperf"
      {"is_dir", &is_dir_cmd_entry},
#line 836 "cmds-gperf.gperf"
      {"get-pid", &get_pid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 979 "cmds-gperf.gperf"
      {"is-dir", &is_dir_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1187 "cmds-gperf.gperf"
      {"mountpoints", &mountpoints_cmd_entry},
      {(char*)0}, {(char*)0},
#line 989 "cmds-gperf.gperf"
      {"is_socket", &is_socket_cmd_entry},
      {(char*)0}, {(char*)0},
#line 858 "cmds-gperf.gperf"
      {"getxattrs", &getxattrs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1181 "cmds-gperf.gperf"
      {"mount_options", &mount_options_cmd_entry},
#line 990 "cmds-gperf.gperf"
      {"is-socket", &is_socket_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1237 "cmds-gperf.gperf"
      {"part_to_partnum", &part_to_partnum_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1182 "cmds-gperf.gperf"
      {"mount-options", &mount_options_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 702 "cmds-gperf.gperf"
      {"compress_out", &compress_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1374 "cmds-gperf.gperf"
      {"setxattr", &setxattr_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1238 "cmds-gperf.gperf"
      {"part-to-partnum", &part_to_partnum_cmd_entry},
#line 857 "cmds-gperf.gperf"
      {"getxattr", &getxattr_cmd_entry},
#line 703 "cmds-gperf.gperf"
      {"compress-out", &compress_out_cmd_entry},
      {(char*)0},
#line 599 "cmds-gperf.gperf"
      {"aug_close", &aug_close_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 600 "cmds-gperf.gperf"
      {"aug-close", &aug_close_cmd_entry},
#line 1314 "cmds-gperf.gperf"
      {"set_direct", &set_direct_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 807 "cmds-gperf.gperf"
      {"get_direct", &get_direct_cmd_entry},
      {(char*)0}, {(char*)0},
#line 627 "cmds-gperf.gperf"
      {"aug_setm", &aug_setm_cmd_entry},
      {(char*)0},
#line 1315 "cmds-gperf.gperf"
      {"set-direct", &set_direct_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 808 "cmds-gperf.gperf"
      {"get-direct", &get_direct_cmd_entry},
      {(char*)0}, {(char*)0},
#line 628 "cmds-gperf.gperf"
      {"aug-setm", &aug_setm_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1279 "cmds-gperf.gperf"
      {"rm", &rm_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1316 "cmds-gperf.gperf"
      {"direct", &set_direct_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 991 "cmds-gperf.gperf"
      {"is-socket-opts", &is_socket_cmd_entry},
      {(char*)0},
#line 621 "cmds-gperf.gperf"
      {"aug_rm", &aug_rm_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 622 "cmds-gperf.gperf"
      {"aug-rm", &aug_rm_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1351 "cmds-gperf.gperf"
      {"qemu", &set_qemu_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 758 "cmds-gperf.gperf"
      {"echo", &echo_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1364 "cmds-gperf.gperf"
      {"set_trace", &set_trace_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 850 "cmds-gperf.gperf"
      {"get_trace", &get_trace_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1365 "cmds-gperf.gperf"
      {"set-trace", &set_trace_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 851 "cmds-gperf.gperf"
      {"get-trace", &get_trace_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 634 "cmds-gperf.gperf"
      {"base64_out", &base64_out_cmd_entry},
      {(char*)0},
#line 1358 "cmds-gperf.gperf"
      {"set_smp", &set_smp_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 846 "cmds-gperf.gperf"
      {"get_smp", &get_smp_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1359 "cmds-gperf.gperf"
      {"set-smp", &set_smp_cmd_entry},
      {(char*)0}, {(char*)0},
#line 748 "cmds-gperf.gperf"
      {"dmesg", &dmesg_cmd_entry},
      {(char*)0},
#line 847 "cmds-gperf.gperf"
      {"get-smp", &get_smp_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1123 "cmds-gperf.gperf"
      {"md_stat", &md_stat_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1124 "cmds-gperf.gperf"
      {"md-stat", &md_stat_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1415 "cmds-gperf.gperf"
      {"tail", &tail_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1346 "cmds-gperf.gperf"
      {"set_program", &set_program_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 838 "cmds-gperf.gperf"
      {"get_program", &get_program_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1179 "cmds-gperf.gperf"
      {"mount_loop", &mount_loop_cmd_entry},
#line 1347 "cmds-gperf.gperf"
      {"set-program", &set_program_cmd_entry},
      {(char*)0}, {(char*)0},
#line 632 "cmds-gperf.gperf"
      {"base64_in", &base64_in_cmd_entry},
      {(char*)0},
#line 839 "cmds-gperf.gperf"
      {"get-program", &get_program_cmd_entry},
      {(char*)0},
#line 1478 "cmds-gperf.gperf"
      {"vgs", &vgs_cmd_entry},
      {(char*)0},
#line 1180 "cmds-gperf.gperf"
      {"mount-loop", &mount_loop_cmd_entry},
      {(char*)0},
#line 762 "cmds-gperf.gperf"
      {"vi", &edit_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1045 "cmds-gperf.gperf"
      {"list_9p", &list_9p_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1046 "cmds-gperf.gperf"
      {"list-9p", &list_9p_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1285 "cmds-gperf.gperf"
      {"rmmountpoint", &rmmountpoint_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1284 "cmds-gperf.gperf"
      {"rmdir", &rmdir_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 922 "cmds-gperf.gperf"
      {"inspect_get_arch", &inspect_get_arch_cmd_entry},
      {(char*)0},
#line 580 "cmds-gperf.gperf"
      {"domain", &add_domain_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 906 "cmds-gperf.gperf"
      {"initrd_cat", &initrd_cat_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1253 "cmds-gperf.gperf"
      {"pvs", &pvs_cmd_entry},
      {(char*)0},
#line 592 "cmds-gperf.gperf"
      {"scratch", &add_drive_scratch_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 923 "cmds-gperf.gperf"
      {"inspect-get-arch", &inspect_get_arch_cmd_entry},
#line 767 "cmds-gperf.gperf"
      {"event", &event_cmd_entry},
#line 1363 "cmds-gperf.gperf"
      {"tmpdir", &set_tmpdir_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 596 "cmds-gperf.gperf"
      {"allocate", &alloc_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1457 "cmds-gperf.gperf"
      {"version", &version_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 837 "cmds-gperf.gperf"
      {"pid", &get_pid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1044 "cmds-gperf.gperf"
      {"lgetxattrs", &lgetxattrs_cmd_entry},
      {(char*)0}, {(char*)0},
#line 587 "cmds-gperf.gperf"
      {"add-ro", &add_drive_ro_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1295 "cmds-gperf.gperf"
      {"scrub_freespace", &scrub_freespace_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1264 "cmds-gperf.gperf"
      {"readdir", &readdir_cmd_entry},
#line 1250 "cmds-gperf.gperf"
      {"pvresize", &pvresize_cmd_entry},
      {(char*)0},
#line 1296 "cmds-gperf.gperf"
      {"scrub-freespace", &scrub_freespace_cmd_entry},
#line 601 "cmds-gperf.gperf"
      {"aug_defnode", &aug_defnode_cmd_entry},
      {(char*)0},
#line 1477 "cmds-gperf.gperf"
      {"vgrename", &vgrename_cmd_entry},
      {(char*)0},
#line 727 "cmds-gperf.gperf"
      {"debug", &debug_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1241 "cmds-gperf.gperf"
      {"pread", &pread_cmd_entry},
#line 602 "cmds-gperf.gperf"
      {"aug-defnode", &aug_defnode_cmd_entry},
#line 1077 "cmds-gperf.gperf"
      {"lsetxattr", &lsetxattr_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1043 "cmds-gperf.gperf"
      {"lgetxattr", &lgetxattr_cmd_entry},
#line 1207 "cmds-gperf.gperf"
      {"part_add", &part_add_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1208 "cmds-gperf.gperf"
      {"part-add", &part_add_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1169 "cmds-gperf.gperf"
      {"modprobe", &modprobe_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 715 "cmds-gperf.gperf"
      {"copy_in", &copy_in_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 952 "cmds-gperf.gperf"
      {"inspect_get_type", &inspect_get_type_cmd_entry},
      {(char*)0},
#line 1472 "cmds-gperf.gperf"
      {"vgcreate", &vgcreate_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 716 "cmds-gperf.gperf"
      {"copy-in", &copy_in_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 960 "cmds-gperf.gperf"
      {"inspect_is_multipart", &inspect_is_multipart_cmd_entry},
#line 953 "cmds-gperf.gperf"
      {"inspect-get-type", &inspect_get_type_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1289 "cmds-gperf.gperf"
      {"rsync_out", &rsync_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1290 "cmds-gperf.gperf"
      {"rsync-out", &rsync_out_cmd_entry},
      {(char*)0},
#line 1299 "cmds-gperf.gperf"
      {"append", &set_append_cmd_entry},
      {(char*)0},
#line 1305 "cmds-gperf.gperf"
      {"autosync", &set_autosync_cmd_entry},
      {(char*)0},
#line 961 "cmds-gperf.gperf"
      {"inspect-is-multipart", &inspect_is_multipart_cmd_entry},
#line 1420 "cmds-gperf.gperf"
      {"tar-in-opts", &tar_in_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1396 "cmds-gperf.gperf"
      {"supported", &supported_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 964 "cmds-gperf.gperf"
      {"inspect_list_applications", &inspect_list_applications_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1248 "cmds-gperf.gperf"
      {"pvcreate", &pvcreate_cmd_entry},
#line 1413 "cmds-gperf.gperf"
      {"sync", &sync_cmd_entry},
#line 595 "cmds-gperf.gperf"
      {"alloc", &alloc_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1385 "cmds-gperf.gperf"
      {"sh", &sh_cmd_entry},
      {(char*)0},
#line 965 "cmds-gperf.gperf"
      {"inspect-list-applications", &inspect_list_applications_cmd_entry},
#line 1481 "cmds-gperf.gperf"
      {"vgscan", &vgscan_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 868 "cmds-gperf.gperf"
      {"head_n", &head_n_cmd_entry},
#line 1063 "cmds-gperf.gperf"
      {"list_partitions", &list_partitions_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 869 "cmds-gperf.gperf"
      {"head-n", &head_n_cmd_entry},
#line 1064 "cmds-gperf.gperf"
      {"list-partitions", &list_partitions_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1293 "cmds-gperf.gperf"
      {"scrub_file", &scrub_file_cmd_entry},
      {(char*)0},
#line 1303 "cmds-gperf.gperf"
      {"set_autosync", &set_autosync_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1286 "cmds-gperf.gperf"
      {"rsync", &rsync_cmd_entry},
      {(char*)0},
#line 799 "cmds-gperf.gperf"
      {"get_autosync", &get_autosync_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1294 "cmds-gperf.gperf"
      {"scrub-file", &scrub_file_cmd_entry},
#line 908 "cmds-gperf.gperf"
      {"initrd_list", &initrd_list_cmd_entry},
#line 1304 "cmds-gperf.gperf"
      {"set-autosync", &set_autosync_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 800 "cmds-gperf.gperf"
      {"get-autosync", &get_autosync_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1116 "cmds-gperf.gperf"
      {"manual", &man_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1474 "cmds-gperf.gperf"
      {"vgmeta", &vgmeta_cmd_entry},
#line 775 "cmds-gperf.gperf"
      {"fgrepi", &fgrepi_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1342 "cmds-gperf.gperf"
      {"path", &set_path_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1317 "cmds-gperf.gperf"
      {"set_e2attrs", &set_e2attrs_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1340 "cmds-gperf.gperf"
      {"set_path", &set_path_cmd_entry},
#line 766 "cmds-gperf.gperf"
      {"equal", &equal_cmd_entry},
#line 809 "cmds-gperf.gperf"
      {"get_e2attrs", &get_e2attrs_cmd_entry},
#line 1065 "cmds-gperf.gperf"
      {"ll", &ll_cmd_entry},
      {(char*)0},
#line 831 "cmds-gperf.gperf"
      {"get_path", &get_path_cmd_entry},
      {(char*)0},
#line 1318 "cmds-gperf.gperf"
      {"set-e2attrs", &set_e2attrs_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1341 "cmds-gperf.gperf"
      {"set-path", &set_path_cmd_entry},
      {(char*)0},
#line 810 "cmds-gperf.gperf"
      {"get-e2attrs", &get_e2attrs_cmd_entry},
      {(char*)0}, {(char*)0},
#line 832 "cmds-gperf.gperf"
      {"get-path", &get_path_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1000 "cmds-gperf.gperf"
      {"isoinfo", &isoinfo_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 774 "cmds-gperf.gperf"
      {"fgrep", &fgrep_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1125 "cmds-gperf.gperf"
      {"md_stop", &md_stop_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1126 "cmds-gperf.gperf"
      {"md-stop", &md_stop_cmd_entry},
#line 1110 "cmds-gperf.gperf"
      {"lvs", &lvs_cmd_entry},
#line 1057 "cmds-gperf.gperf"
      {"list_ldm_partitions", &list_ldm_partitions_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1361 "cmds-gperf.gperf"
      {"set_tmpdir", &set_tmpdir_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1229 "cmds-gperf.gperf"
      {"part_set_gpt_type", &part_set_gpt_type_cmd_entry},
      {(char*)0},
#line 848 "cmds-gperf.gperf"
      {"get_tmpdir", &get_tmpdir_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1215 "cmds-gperf.gperf"
      {"part_get_gpt_type", &part_get_gpt_type_cmd_entry},
      {(char*)0},
#line 1362 "cmds-gperf.gperf"
      {"set-tmpdir", &set_tmpdir_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1058 "cmds-gperf.gperf"
      {"list-ldm-partitions", &list_ldm_partitions_cmd_entry},
#line 849 "cmds-gperf.gperf"
      {"get-tmpdir", &get_tmpdir_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1230 "cmds-gperf.gperf"
      {"part-set-gpt-type", &part_set_gpt_type_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1216 "cmds-gperf.gperf"
      {"part-get-gpt-type", &part_get_gpt_type_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1429 "cmds-gperf.gperf"
      {"touch", &touch_cmd_entry},
      {(char*)0},
#line 1221 "cmds-gperf.gperf"
      {"part_get_parttype", &part_get_parttype_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 704 "cmds-gperf.gperf"
      {"config", &config_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 697 "cmds-gperf.gperf"
      {"command", &command_cmd_entry},
#line 1114 "cmds-gperf.gperf"
      {"lxattrlist", &lxattrlist_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 698 "cmds-gperf.gperf"
      {"command_lines", &command_lines_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1222 "cmds-gperf.gperf"
      {"part-get-parttype", &part_get_parttype_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 699 "cmds-gperf.gperf"
      {"command-lines", &command_lines_cmd_entry},
#line 1319 "cmds-gperf.gperf"
      {"set_e2generation", &set_e2generation_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 811 "cmds-gperf.gperf"
      {"get_e2generation", &get_e2generation_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1320 "cmds-gperf.gperf"
      {"set-e2generation", &set_e2generation_cmd_entry},
#line 1177 "cmds-gperf.gperf"
      {"mount_local_run", &mount_local_run_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 812 "cmds-gperf.gperf"
      {"get-e2generation", &get_e2generation_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1107 "cmds-gperf.gperf"
      {"lvresize", &lvresize_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1178 "cmds-gperf.gperf"
      {"mount-local-run", &mount_local_run_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1328 "cmds-gperf.gperf"
      {"set_label", &set_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 611 "cmds-gperf.gperf"
      {"aug_label", &aug_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1329 "cmds-gperf.gperf"
      {"set-label", &set_label_cmd_entry},
      {(char*)0}, {(char*)0},
#line 726 "cmds-gperf.gperf"
      {"dd", &dd_cmd_entry},
#line 583 "cmds-gperf.gperf"
      {"add", &add_drive_cmd_entry},
#line 612 "cmds-gperf.gperf"
      {"aug-label", &aug_label_cmd_entry},
      {(char*)0},
#line 1443 "cmds-gperf.gperf"
      {"umount-opts", &umount_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1450 "cmds-gperf.gperf"
      {"upload", &upload_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1106 "cmds-gperf.gperf"
      {"lvrename", &lvrename_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 603 "cmds-gperf.gperf"
      {"aug_defvar", &aug_defvar_cmd_entry},
#line 1369 "cmds-gperf.gperf"
      {"set_verbose", &set_verbose_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 854 "cmds-gperf.gperf"
      {"get_verbose", &get_verbose_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 604 "cmds-gperf.gperf"
      {"aug-defvar", &aug_defvar_cmd_entry},
#line 1370 "cmds-gperf.gperf"
      {"set-verbose", &set_verbose_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 855 "cmds-gperf.gperf"
      {"get-verbose", &get_verbose_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1297 "cmds-gperf.gperf"
      {"set_append", &set_append_cmd_entry},
      {(char*)0},
#line 1355 "cmds-gperf.gperf"
      {"set_selinux", &set_selinux_cmd_entry},
      {(char*)0}, {(char*)0},
#line 795 "cmds-gperf.gperf"
      {"get_append", &get_append_cmd_entry},
      {(char*)0},
#line 844 "cmds-gperf.gperf"
      {"get_selinux", &get_selinux_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1298 "cmds-gperf.gperf"
      {"set-append", &set_append_cmd_entry},
      {(char*)0},
#line 1356 "cmds-gperf.gperf"
      {"set-selinux", &set_selinux_cmd_entry},
#line 1456 "cmds-gperf.gperf"
      {"utsname", &utsname_cmd_entry},
      {(char*)0},
#line 796 "cmds-gperf.gperf"
      {"get-append", &get_append_cmd_entry},
      {(char*)0},
#line 845 "cmds-gperf.gperf"
      {"get-selinux", &get_selinux_cmd_entry},
#line 1094 "cmds-gperf.gperf"
      {"lvcreate", &lvcreate_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1021 "cmds-gperf.gperf"
      {"lcd", &lcd_cmd_entry},
      {(char*)0},
#line 776 "cmds-gperf.gperf"
      {"file", &file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 867 "cmds-gperf.gperf"
      {"head", &head_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 859 "cmds-gperf.gperf"
      {"glob", &glob_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 825 "cmds-gperf.gperf"
      {"get_libvirt_requested_credentials", &get_libvirt_requested_credentials_cmd_entry},
      {(char*)0},
#line 635 "cmds-gperf.gperf"
      {"base64-out", &base64_out_cmd_entry},
#line 980 "cmds-gperf.gperf"
      {"is-dir-opts", &is_dir_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1119 "cmds-gperf.gperf"
      {"md_create", &md_create_cmd_entry},
      {(char*)0}, {(char*)0},
#line 819 "cmds-gperf.gperf"
      {"get_libvirt_requested_credential_challenge", &get_libvirt_requested_credential_challenge_cmd_entry},
#line 1332 "cmds-gperf.gperf"
      {"set_libvirt_supported_credentials", &set_libvirt_supported_credentials_cmd_entry},
#line 823 "cmds-gperf.gperf"
      {"get_libvirt_requested_credential_prompt", &get_libvirt_requested_credential_prompt_cmd_entry},
      {(char*)0}, {(char*)0},
#line 821 "cmds-gperf.gperf"
      {"get_libvirt_requested_credential_defresult", &get_libvirt_requested_credential_defresult_cmd_entry},
      {(char*)0},
#line 1120 "cmds-gperf.gperf"
      {"md-create", &md_create_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 826 "cmds-gperf.gperf"
      {"get-libvirt-requested-credentials", &get_libvirt_requested_credentials_cmd_entry},
#line 779 "cmds-gperf.gperf"
      {"filesize", &filesize_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 820 "cmds-gperf.gperf"
      {"get-libvirt-requested-credential-challenge", &get_libvirt_requested_credential_challenge_cmd_entry},
#line 1333 "cmds-gperf.gperf"
      {"set-libvirt-supported-credentials", &set_libvirt_supported_credentials_cmd_entry},
#line 824 "cmds-gperf.gperf"
      {"get-libvirt-requested-credential-prompt", &get_libvirt_requested_credential_prompt_cmd_entry},
      {(char*)0}, {(char*)0},
#line 822 "cmds-gperf.gperf"
      {"get-libvirt-requested-credential-defresult", &get_libvirt_requested_credential_defresult_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 958 "cmds-gperf.gperf"
      {"inspect_is_live", &inspect_is_live_cmd_entry},
      {(char*)0},
#line 623 "cmds-gperf.gperf"
      {"aug_save", &aug_save_cmd_entry},
      {(char*)0},
#line 1233 "cmds-gperf.gperf"
      {"part_set_name", &part_set_name_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1219 "cmds-gperf.gperf"
      {"part_get_name", &part_get_name_cmd_entry},
      {(char*)0},
#line 1239 "cmds-gperf.gperf"
      {"ping_daemon", &ping_daemon_cmd_entry},
#line 624 "cmds-gperf.gperf"
      {"aug-save", &aug_save_cmd_entry},
#line 871 "cmds-gperf.gperf"
      {"hexedit", &hexedit_cmd_entry},
      {(char*)0},
#line 578 "cmds-gperf.gperf"
      {"add_domain", &add_domain_cmd_entry},
#line 739 "cmds-gperf.gperf"
      {"disk_create", &disk_create_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 959 "cmds-gperf.gperf"
      {"inspect-is-live", &inspect_is_live_cmd_entry},
#line 1240 "cmds-gperf.gperf"
      {"ping-daemon", &ping_daemon_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1234 "cmds-gperf.gperf"
      {"part-set-name", &part_set_name_cmd_entry},
#line 579 "cmds-gperf.gperf"
      {"add-domain", &add_domain_cmd_entry},
#line 740 "cmds-gperf.gperf"
      {"disk-create", &disk_create_cmd_entry},
#line 1242 "cmds-gperf.gperf"
      {"pread_device", &pread_device_cmd_entry},
      {(char*)0},
#line 1220 "cmds-gperf.gperf"
      {"part-get-name", &part_get_name_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1490 "cmds-gperf.gperf"
      {"write", &write_cmd_entry},
#line 705 "cmds-gperf.gperf"
      {"copy_attributes", &copy_attributes_cmd_entry},
#line 788 "cmds-gperf.gperf"
      {"find0", &find0_cmd_entry},
#line 1243 "cmds-gperf.gperf"
      {"pread-device", &pread_device_cmd_entry},
      {(char*)0},
#line 633 "cmds-gperf.gperf"
      {"base64-in", &base64_in_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 706 "cmds-gperf.gperf"
      {"copy-attributes", &copy_attributes_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 617 "cmds-gperf.gperf"
      {"aug_match", &aug_match_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 618 "cmds-gperf.gperf"
      {"aug-match", &aug_match_cmd_entry},
#line 681 "cmds-gperf.gperf"
      {"canonical_device_name", &canonical_device_name_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1267 "cmds-gperf.gperf"
      {"realpath", &realpath_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 907 "cmds-gperf.gperf"
      {"initrd-cat", &initrd_cat_cmd_entry},
#line 682 "cmds-gperf.gperf"
      {"canonical-device-name", &canonical_device_name_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1257 "cmds-gperf.gperf"
      {"pwrite", &pwrite_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1446 "cmds-gperf.gperf"
      {"unmount-all", &umount_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1175 "cmds-gperf.gperf"
      {"mount_local", &mount_local_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1388 "cmds-gperf.gperf"
      {"shutdown", &shutdown_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1499 "cmds-gperf.gperf"
      {"xfs_info", &xfs_info_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1176 "cmds-gperf.gperf"
      {"mount-local", &mount_local_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1168 "cmds-gperf.gperf"
      {"mktemp", &mktemp_cmd_entry},
#line 1500 "cmds-gperf.gperf"
      {"xfs-info", &xfs_info_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 685 "cmds-gperf.gperf"
      {"cap_set_file", &cap_set_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 683 "cmds-gperf.gperf"
      {"cap_get_file", &cap_get_file_cmd_entry},
      {(char*)0}, {(char*)0},
#line 966 "cmds-gperf.gperf"
      {"inspect_list_applications2", &inspect_list_applications2_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 597 "cmds-gperf.gperf"
      {"aug_clear", &aug_clear_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 967 "cmds-gperf.gperf"
      {"inspect-list-applications2", &inspect_list_applications2_cmd_entry},
      {(char*)0},
#line 686 "cmds-gperf.gperf"
      {"cap-set-file", &cap_set_file_cmd_entry},
      {(char*)0},
#line 598 "cmds-gperf.gperf"
      {"aug-clear", &aug_clear_cmd_entry},
      {(char*)0}, {(char*)0},
#line 684 "cmds-gperf.gperf"
      {"cap-get-file", &cap_get_file_cmd_entry},
      {(char*)0},
#line 1311 "cmds-gperf.gperf"
      {"set_cachedir", &set_cachedir_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 805 "cmds-gperf.gperf"
      {"get_cachedir", &get_cachedir_cmd_entry},
      {(char*)0},
#line 1019 "cmds-gperf.gperf"
      {"launch", &launch_cmd_entry},
#line 1433 "cmds-gperf.gperf"
      {"tune2fs", &tune2fs_cmd_entry},
      {(char*)0},
#line 1312 "cmds-gperf.gperf"
      {"set-cachedir", &set_cachedir_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 806 "cmds-gperf.gperf"
      {"get-cachedir", &get_cachedir_cmd_entry},
#line 1453 "cmds-gperf.gperf"
      {"user_cancel", &user_cancel_cmd_entry},
#line 794 "cmds-gperf.gperf"
      {"fstrim", &fstrim_cmd_entry},
#line 1227 "cmds-gperf.gperf"
      {"part_set_bootable", &part_set_bootable_cmd_entry},
      {(char*)0},
#line 1357 "cmds-gperf.gperf"
      {"selinux", &set_selinux_cmd_entry},
      {(char*)0},
#line 1291 "cmds-gperf.gperf"
      {"scrub_device", &scrub_device_cmd_entry},
#line 1213 "cmds-gperf.gperf"
      {"part_get_bootable", &part_get_bootable_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1454 "cmds-gperf.gperf"
      {"user-cancel", &user_cancel_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1292 "cmds-gperf.gperf"
      {"scrub-device", &scrub_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1228 "cmds-gperf.gperf"
      {"part-set-bootable", &part_set_bootable_cmd_entry},
      {(char*)0},
#line 1444 "cmds-gperf.gperf"
      {"umount_all", &umount_all_cmd_entry},
#line 1373 "cmds-gperf.gperf"
      {"setenv", &setenv_cmd_entry},
      {(char*)0},
#line 1214 "cmds-gperf.gperf"
      {"part-get-bootable", &part_get_bootable_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1033 "cmds-gperf.gperf"
      {"ldmtool_scan", &ldmtool_scan_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1154 "cmds-gperf.gperf"
      {"mkmountpoint", &mkmountpoint_cmd_entry},
#line 1449 "cmds-gperf.gperf"
      {"unsetenv", &unsetenv_cmd_entry},
      {(char*)0},
#line 1127 "cmds-gperf.gperf"
      {"mkdir", &mkdir_cmd_entry},
      {(char*)0},
#line 1034 "cmds-gperf.gperf"
      {"ldmtool-scan", &ldmtool_scan_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1482 "cmds-gperf.gperf"
      {"vguuid", &vguuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1426 "cmds-gperf.gperf"
      {"tgz_out", &tgz_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1427 "cmds-gperf.gperf"
      {"tgz-out", &tgz_out_cmd_entry},
#line 865 "cmds-gperf.gperf"
      {"grub_install", &grub_install_cmd_entry},
      {(char*)0},
#line 629 "cmds-gperf.gperf"
      {"available", &available_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1505 "cmds-gperf.gperf"
      {"zero", &zero_cmd_entry},
#line 1196 "cmds-gperf.gperf"
      {"ntfsclone_out", &ntfsclone_out_cmd_entry},
#line 1082 "cmds-gperf.gperf"
      {"luks_close", &luks_close_cmd_entry},
      {(char*)0},
#line 866 "cmds-gperf.gperf"
      {"grub-install", &grub_install_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1197 "cmds-gperf.gperf"
      {"ntfsclone-out", &ntfsclone_out_cmd_entry},
#line 1083 "cmds-gperf.gperf"
      {"luks-close", &luks_close_cmd_entry},
      {(char*)0},
#line 607 "cmds-gperf.gperf"
      {"aug_init", &aug_init_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 608 "cmds-gperf.gperf"
      {"aug-init", &aug_init_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1256 "cmds-gperf.gperf"
      {"pvuuid", &pvuuid_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1090 "cmds-gperf.gperf"
      {"luks_open", &luks_open_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 717 "cmds-gperf.gperf"
      {"copy_out", &copy_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1092 "cmds-gperf.gperf"
      {"luks_open_ro", &luks_open_ro_cmd_entry},
#line 687 "cmds-gperf.gperf"
      {"case_sensitive_path", &case_sensitive_path_cmd_entry},
#line 1091 "cmds-gperf.gperf"
      {"luks-open", &luks_open_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 718 "cmds-gperf.gperf"
      {"copy-out", &copy_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 688 "cmds-gperf.gperf"
      {"case-sensitive-path", &case_sensitive_path_cmd_entry},
      {(char*)0},
#line 1515 "cmds-gperf.gperf"
      {"zgrepi", &zgrepi_cmd_entry},
#line 996 "cmds-gperf.gperf"
      {"is_zero", &is_zero_cmd_entry},
      {(char*)0},
#line 613 "cmds-gperf.gperf"
      {"aug_load", &aug_load_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1093 "cmds-gperf.gperf"
      {"luks-open-ro", &luks_open_ro_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1424 "cmds-gperf.gperf"
      {"tgz_in", &tgz_in_cmd_entry},
#line 997 "cmds-gperf.gperf"
      {"is-zero", &is_zero_cmd_entry},
      {(char*)0},
#line 614 "cmds-gperf.gperf"
      {"aug-load", &aug_load_cmd_entry},
      {(char*)0}, {(char*)0},
#line 909 "cmds-gperf.gperf"
      {"initrd-list", &initrd_list_cmd_entry},
#line 1330 "cmds-gperf.gperf"
      {"set_libvirt_requested_credential", &set_libvirt_requested_credential_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1425 "cmds-gperf.gperf"
      {"tgz-in", &tgz_in_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 728 "cmds-gperf.gperf"
      {"debug_drives", &debug_drives_cmd_entry},
#line 1194 "cmds-gperf.gperf"
      {"ntfsclone_in", &ntfsclone_in_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1331 "cmds-gperf.gperf"
      {"set-libvirt-requested-credential", &set_libvirt_requested_credential_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 729 "cmds-gperf.gperf"
      {"debug-drives", &debug_drives_cmd_entry},
#line 1195 "cmds-gperf.gperf"
      {"ntfsclone-in", &ntfsclone_in_cmd_entry},
#line 1514 "cmds-gperf.gperf"
      {"zgrep", &zgrep_cmd_entry},
#line 1503 "cmds-gperf.gperf"
      {"zegrep", &zegrep_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1447 "cmds-gperf.gperf"
      {"umount_local", &umount_local_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1392 "cmds-gperf.gperf"
      {"statvfs", &statvfs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 695 "cmds-gperf.gperf"
      {"chmod", &chmod_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 732 "cmds-gperf.gperf"
      {"delete_event", &delete_event_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1097 "cmds-gperf.gperf"
      {"lvm_canonical_lv_name", &lvm_canonical_lv_name_cmd_entry},
      {(char*)0}, {(char*)0},
#line 752 "cmds-gperf.gperf"
      {"drop_caches", &drop_caches_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1300 "cmds-gperf.gperf"
      {"set_attach_method", &set_attach_method_cmd_entry},
#line 896 "cmds-gperf.gperf"
      {"hivex_root", &hivex_root_cmd_entry},
      {(char*)0}, {(char*)0},
#line 753 "cmds-gperf.gperf"
      {"drop-caches", &drop_caches_cmd_entry},
#line 797 "cmds-gperf.gperf"
      {"get_attach_method", &get_attach_method_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1483 "cmds-gperf.gperf"
      {"wc_c", &wc_c_cmd_entry},
      {(char*)0}, {(char*)0},
#line 897 "cmds-gperf.gperf"
      {"hivex-root", &hivex_root_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1484 "cmds-gperf.gperf"
      {"wc-c", &wc_c_cmd_entry},
#line 1493 "cmds-gperf.gperf"
      {"write_file", &write_file_cmd_entry},
#line 1301 "cmds-gperf.gperf"
      {"set-attach-method", &set_attach_method_cmd_entry},
#line 1098 "cmds-gperf.gperf"
      {"lvm-canonical-lv-name", &lvm_canonical_lv_name_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 798 "cmds-gperf.gperf"
      {"get-attach-method", &get_attach_method_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1494 "cmds-gperf.gperf"
      {"write-file", &write_file_cmd_entry},
#line 1053 "cmds-gperf.gperf"
      {"list_events", &list_events_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1189 "cmds-gperf.gperf"
      {"mv", &mv_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1054 "cmds-gperf.gperf"
      {"list-events", &list_events_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 619 "cmds-gperf.gperf"
      {"aug_mv", &aug_mv_cmd_entry},
#line 1431 "cmds-gperf.gperf"
      {"truncate_size", &truncate_size_cmd_entry},
#line 574 "cmds-gperf.gperf"
      {"acl_set_file", &acl_set_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 572 "cmds-gperf.gperf"
      {"acl_get_file", &acl_get_file_cmd_entry},
      {(char*)0},
#line 787 "cmds-gperf.gperf"
      {"find", &find_cmd_entry},
#line 620 "cmds-gperf.gperf"
      {"aug-mv", &aug_mv_cmd_entry},
#line 1432 "cmds-gperf.gperf"
      {"truncate-size", &truncate_size_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1061 "cmds-gperf.gperf"
      {"list_md_devices", &list_md_devices_cmd_entry},
      {(char*)0}, {(char*)0},
#line 575 "cmds-gperf.gperf"
      {"acl-set-file", &acl_set_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 573 "cmds-gperf.gperf"
      {"acl-get-file", &acl_get_file_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1271 "cmds-gperf.gperf"
      {"removexattr", &removexattr_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 700 "cmds-gperf.gperf"
      {"compress_device_out", &compress_device_out_cmd_entry},
#line 1062 "cmds-gperf.gperf"
      {"list-md-devices", &list_md_devices_cmd_entry},
      {(char*)0}, {(char*)0},
#line 975 "cmds-gperf.gperf"
      {"is-chardev-opts", &is_chardev_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 701 "cmds-gperf.gperf"
      {"compress-device-out", &compress_device_out_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1386 "cmds-gperf.gperf"
      {"sh_lines", &sh_lines_cmd_entry},
#line 1354 "cmds-gperf.gperf"
      {"recovery-proc", &set_recovery_proc_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1387 "cmds-gperf.gperf"
      {"sh-lines", &sh_lines_cmd_entry},
      {(char*)0},
#line 1501 "cmds-gperf.gperf"
      {"xfs_repair", &xfs_repair_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1502 "cmds-gperf.gperf"
      {"xfs-repair", &xfs_repair_cmd_entry},
#line 987 "cmds-gperf.gperf"
      {"is_lv", &is_lv_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 988 "cmds-gperf.gperf"
      {"is-lv", &is_lv_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1308 "cmds-gperf.gperf"
      {"backend", &set_backend_cmd_entry},
#line 669 "cmds-gperf.gperf"
      {"btrfs_set_seeding", &btrfs_set_seeding_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1334 "cmds-gperf.gperf"
      {"set_memsize", &set_memsize_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 827 "cmds-gperf.gperf"
      {"get_memsize", &get_memsize_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 759 "cmds-gperf.gperf"
      {"echo_daemon", &echo_daemon_cmd_entry},
#line 1335 "cmds-gperf.gperf"
      {"set-memsize", &set_memsize_cmd_entry},
      {(char*)0}, {(char*)0},
#line 670 "cmds-gperf.gperf"
      {"btrfs-set-seeding", &btrfs_set_seeding_cmd_entry},
      {(char*)0},
#line 828 "cmds-gperf.gperf"
      {"get-memsize", &get_memsize_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 760 "cmds-gperf.gperf"
      {"echo-daemon", &echo_daemon_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 576 "cmds-gperf.gperf"
      {"add_cdrom", &add_cdrom_cmd_entry},
      {(char*)0},
#line 894 "cmds-gperf.gperf"
      {"hivex_open", &hivex_open_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 577 "cmds-gperf.gperf"
      {"add-cdrom", &add_cdrom_cmd_entry},
      {(char*)0},
#line 895 "cmds-gperf.gperf"
      {"hivex-open", &hivex_open_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1440 "cmds-gperf.gperf"
      {"umask", &umask_cmd_entry},
#line 1113 "cmds-gperf.gperf"
      {"lvuuid", &lvuuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1005 "cmds-gperf.gperf"
      {"journal_get", &journal_get_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1035 "cmds-gperf.gperf"
      {"ldmtool_scan_devices", &ldmtool_scan_devices_cmd_entry},
      {(char*)0},
#line 1130 "cmds-gperf.gperf"
      {"mkdir_p", &mkdir_p_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1006 "cmds-gperf.gperf"
      {"journal-get", &journal_get_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1036 "cmds-gperf.gperf"
      {"ldmtool-scan-devices", &ldmtool_scan_devices_cmd_entry},
#line 777 "cmds-gperf.gperf"
      {"file_architecture", &file_architecture_cmd_entry},
#line 1131 "cmds-gperf.gperf"
      {"mkdir-p", &mkdir_p_cmd_entry},
      {(char*)0},
#line 981 "cmds-gperf.gperf"
      {"is_fifo", &is_fifo_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1495 "cmds-gperf.gperf"
      {"xfs_admin", &xfs_admin_cmd_entry},
      {(char*)0}, {(char*)0},
#line 778 "cmds-gperf.gperf"
      {"file-architecture", &file_architecture_cmd_entry},
      {(char*)0}, {(char*)0},
#line 982 "cmds-gperf.gperf"
      {"is-fifo", &is_fifo_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1496 "cmds-gperf.gperf"
      {"xfs-admin", &xfs_admin_cmd_entry},
      {(char*)0},
#line 1155 "cmds-gperf.gperf"
      {"mknod", &mknod_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 630 "cmds-gperf.gperf"
      {"available_all_groups", &available_all_groups_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1117 "cmds-gperf.gperf"
      {"max_disks", &max_disks_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1051 "cmds-gperf.gperf"
      {"list_dm_devices", &list_dm_devices_cmd_entry},
#line 1321 "cmds-gperf.gperf"
      {"set_e2label", &set_e2label_cmd_entry},
#line 1118 "cmds-gperf.gperf"
      {"max-disks", &max_disks_cmd_entry},
      {(char*)0}, {(char*)0},
#line 631 "cmds-gperf.gperf"
      {"available-all-groups", &available_all_groups_cmd_entry},
#line 813 "cmds-gperf.gperf"
      {"get_e2label", &get_e2label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1327 "cmds-gperf.gperf"
      {"hv", &set_hv_cmd_entry},
#line 1322 "cmds-gperf.gperf"
      {"set-e2label", &set_e2label_cmd_entry},
      {(char*)0},
#line 1225 "cmds-gperf.gperf"
      {"part_list", &part_list_cmd_entry},
      {(char*)0},
#line 782 "cmds-gperf.gperf"
      {"fill", &fill_cmd_entry},
#line 814 "cmds-gperf.gperf"
      {"get-e2label", &get_e2label_cmd_entry},
#line 1266 "cmds-gperf.gperf"
      {"readlinklist", &readlinklist_cmd_entry},
      {(char*)0},
#line 1325 "cmds-gperf.gperf"
      {"set_hv", &set_hv_cmd_entry},
#line 1052 "cmds-gperf.gperf"
      {"list-dm-devices", &list_dm_devices_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1226 "cmds-gperf.gperf"
      {"part-list", &part_list_cmd_entry},
#line 817 "cmds-gperf.gperf"
      {"get_hv", &get_hv_cmd_entry},
#line 1128 "cmds-gperf.gperf"
      {"mkdir_mode", &mkdir_mode_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1326 "cmds-gperf.gperf"
      {"set-hv", &set_hv_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 818 "cmds-gperf.gperf"
      {"get-hv", &get_hv_cmd_entry},
#line 1129 "cmds-gperf.gperf"
      {"mkdir-mode", &mkdir_mode_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 983 "cmds-gperf.gperf"
      {"is-fifo-opts", &is_fifo_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 870 "cmds-gperf.gperf"
      {"hexdump", &hexdump_cmd_entry},
      {(char*)0},
#line 1146 "cmds-gperf.gperf"
      {"mkfs", &mkfs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1438 "cmds-gperf.gperf"
      {"txz_out", &txz_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1439 "cmds-gperf.gperf"
      {"txz-out", &txz_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1192 "cmds-gperf.gperf"
      {"ntfs_3g_probe", &ntfs_3g_probe_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1235 "cmds-gperf.gperf"
      {"part_to_dev", &part_to_dev_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1011 "cmds-gperf.gperf"
      {"journal_open", &journal_open_cmd_entry},
#line 1193 "cmds-gperf.gperf"
      {"ntfs-3g-probe", &ntfs_3g_probe_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1236 "cmds-gperf.gperf"
      {"part-to-dev", &part_to_dev_cmd_entry},
#line 696 "cmds-gperf.gperf"
      {"chown", &chown_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1012 "cmds-gperf.gperf"
      {"journal-open", &journal_open_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1158 "cmds-gperf.gperf"
      {"mknod_c", &mknod_c_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1323 "cmds-gperf.gperf"
      {"set_e2uuid", &set_e2uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 815 "cmds-gperf.gperf"
      {"get_e2uuid", &get_e2uuid_cmd_entry},
      {(char*)0},
#line 1159 "cmds-gperf.gperf"
      {"mknod-c", &mknod_c_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1324 "cmds-gperf.gperf"
      {"set-e2uuid", &set_e2uuid_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1436 "cmds-gperf.gperf"
      {"txz_in", &txz_in_cmd_entry},
      {(char*)0},
#line 816 "cmds-gperf.gperf"
      {"get-e2uuid", &get_e2uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1437 "cmds-gperf.gperf"
      {"txz-in", &txz_in_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1209 "cmds-gperf.gperf"
      {"part_del", &part_del_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1210 "cmds-gperf.gperf"
      {"part-del", &part_del_cmd_entry},
      {(char*)0},
#line 890 "cmds-gperf.gperf"
      {"hivex_node_set_value", &hivex_node_set_value_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 884 "cmds-gperf.gperf"
      {"hivex_node_get_value", &hivex_node_get_value_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1108 "cmds-gperf.gperf"
      {"lvresize_free", &lvresize_free_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1156 "cmds-gperf.gperf"
      {"mknod_b", &mknod_b_cmd_entry},
#line 1203 "cmds-gperf.gperf"
      {"parse_environment", &parse_environment_cmd_entry},
#line 1109 "cmds-gperf.gperf"
      {"lvresize-free", &lvresize_free_cmd_entry},
      {(char*)0},
#line 891 "cmds-gperf.gperf"
      {"hivex-node-set-value", &hivex_node_set_value_cmd_entry},
      {(char*)0},
#line 1205 "cmds-gperf.gperf"
      {"parse_environment_list", &parse_environment_list_cmd_entry},
      {(char*)0},
#line 1309 "cmds-gperf.gperf"
      {"set_backend_settings", &set_backend_settings_cmd_entry},
#line 885 "cmds-gperf.gperf"
      {"hivex-node-get-value", &hivex_node_get_value_cmd_entry},
#line 1157 "cmds-gperf.gperf"
      {"mknod-b", &mknod_b_cmd_entry},
#line 1204 "cmds-gperf.gperf"
      {"parse-environment", &parse_environment_cmd_entry},
      {(char*)0},
#line 803 "cmds-gperf.gperf"
      {"get_backend_settings", &get_backend_settings_cmd_entry},
      {(char*)0},
#line 1132 "cmds-gperf.gperf"
      {"mkdtemp", &mkdtemp_cmd_entry},
#line 1206 "cmds-gperf.gperf"
      {"parse-environment-list", &parse_environment_list_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1280 "cmds-gperf.gperf"
      {"rm_f", &rm_f_cmd_entry},
      {(char*)0},
#line 1485 "cmds-gperf.gperf"
      {"wc_l", &wc_l_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1310 "cmds-gperf.gperf"
      {"set-backend-settings", &set_backend_settings_cmd_entry},
#line 1281 "cmds-gperf.gperf"
      {"rm-f", &rm_f_cmd_entry},
      {(char*)0},
#line 1486 "cmds-gperf.gperf"
      {"wc-l", &wc_l_cmd_entry},
      {(char*)0},
#line 804 "cmds-gperf.gperf"
      {"get-backend-settings", &get_backend_settings_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1445 "cmds-gperf.gperf"
      {"umount-all", &umount_all_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1371 "cmds-gperf.gperf"
      {"verbose", &set_verbose_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1023 "cmds-gperf.gperf"
      {"ldmtool_create_all", &ldmtool_create_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1282 "cmds-gperf.gperf"
      {"rm_rf", &rm_rf_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1024 "cmds-gperf.gperf"
      {"ldmtool-create-all", &ldmtool_create_all_cmd_entry},
      {(char*)0},
#line 1001 "cmds-gperf.gperf"
      {"isoinfo_device", &isoinfo_device_cmd_entry},
      {(char*)0},
#line 1283 "cmds-gperf.gperf"
      {"rm-rf", &rm_rf_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1434 "cmds-gperf.gperf"
      {"tune2fs_l", &tune2fs_l_cmd_entry},
#line 1231 "cmds-gperf.gperf"
      {"part_set_mbr_id", &part_set_mbr_id_cmd_entry},
#line 1352 "cmds-gperf.gperf"
      {"set_recovery_proc", &set_recovery_proc_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1002 "cmds-gperf.gperf"
      {"isoinfo-device", &isoinfo_device_cmd_entry},
#line 1217 "cmds-gperf.gperf"
      {"part_get_mbr_id", &part_get_mbr_id_cmd_entry},
#line 842 "cmds-gperf.gperf"
      {"get_recovery_proc", &get_recovery_proc_cmd_entry},
#line 888 "cmds-gperf.gperf"
      {"hivex_node_parent", &hivex_node_parent_cmd_entry},
#line 984 "cmds-gperf.gperf"
      {"is_file", &is_file_cmd_entry},
#line 1435 "cmds-gperf.gperf"
      {"tune2fs-l", &tune2fs_l_cmd_entry},
      {(char*)0},
#line 1353 "cmds-gperf.gperf"
      {"set-recovery-proc", &set_recovery_proc_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 843 "cmds-gperf.gperf"
      {"get-recovery-proc", &get_recovery_proc_cmd_entry},
      {(char*)0},
#line 985 "cmds-gperf.gperf"
      {"is-file", &is_file_cmd_entry},
      {(char*)0},
#line 1232 "cmds-gperf.gperf"
      {"part-set-mbr-id", &part_set_mbr_id_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1095 "cmds-gperf.gperf"
      {"lvcreate_free", &lvcreate_free_cmd_entry},
      {(char*)0},
#line 1218 "cmds-gperf.gperf"
      {"part-get-mbr-id", &part_get_mbr_id_cmd_entry},
      {(char*)0},
#line 889 "cmds-gperf.gperf"
      {"hivex-node-parent", &hivex_node_parent_cmd_entry},
      {(char*)0}, {(char*)0},
#line 780 "cmds-gperf.gperf"
      {"filesystem_available", &filesystem_available_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1096 "cmds-gperf.gperf"
      {"lvcreate-free", &lvcreate_free_cmd_entry},
#line 770 "cmds-gperf.gperf"
      {"fallocate", &fallocate_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1079 "cmds-gperf.gperf"
      {"lstatlist", &lstatlist_cmd_entry},
      {(char*)0}, {(char*)0},
#line 781 "cmds-gperf.gperf"
      {"filesystem-available", &filesystem_available_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1121 "cmds-gperf.gperf"
      {"md_detail", &md_detail_cmd_entry},
      {(char*)0},
#line 1068 "cmds-gperf.gperf"
      {"ln_f", &ln_f_cmd_entry},
#line 1072 "cmds-gperf.gperf"
      {"ln_sf", &ln_sf_cmd_entry},
      {(char*)0},
#line 736 "cmds-gperf.gperf"
      {"df", &df_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1122 "cmds-gperf.gperf"
      {"md-detail", &md_detail_cmd_entry},
      {(char*)0},
#line 1069 "cmds-gperf.gperf"
      {"ln-f", &ln_f_cmd_entry},
#line 1073 "cmds-gperf.gperf"
      {"ln-sf", &ln_sf_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 771 "cmds-gperf.gperf"
      {"fallocate64", &fallocate64_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 785 "cmds-gperf.gperf"
      {"fill_pattern", &fill_pattern_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 786 "cmds-gperf.gperf"
      {"fill-pattern", &fill_pattern_cmd_entry},
      {(char*)0}, {(char*)0},
#line 737 "cmds-gperf.gperf"
      {"df_h", &df_h_cmd_entry},
      {(char*)0}, {(char*)0},
#line 986 "cmds-gperf.gperf"
      {"is-file-opts", &is_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 738 "cmds-gperf.gperf"
      {"df-h", &df_h_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1013 "cmds-gperf.gperf"
      {"journal_set_data_threshold", &journal_set_data_threshold_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1007 "cmds-gperf.gperf"
      {"journal_get_data_threshold", &journal_get_data_threshold_cmd_entry},
#line 1489 "cmds-gperf.gperf"
      {"wipefs", &wipefs_cmd_entry},
#line 1448 "cmds-gperf.gperf"
      {"umount-local", &umount_local_cmd_entry},
      {(char*)0},
#line 1468 "cmds-gperf.gperf"
      {"vgchange_uuid", &vgchange_uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1469 "cmds-gperf.gperf"
      {"vgchange-uuid", &vgchange_uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 878 "cmds-gperf.gperf"
      {"hivex_node_children", &hivex_node_children_cmd_entry},
      {(char*)0},
#line 1367 "cmds-gperf.gperf"
      {"set_uuid", &set_uuid_cmd_entry},
#line 1031 "cmds-gperf.gperf"
      {"ldmtool_remove_all", &ldmtool_remove_all_cmd_entry},
      {(char*)0},
#line 1014 "cmds-gperf.gperf"
      {"journal-set-data-threshold", &journal_set_data_threshold_cmd_entry},
      {(char*)0},
#line 733 "cmds-gperf.gperf"
      {"delete-event", &delete_event_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1008 "cmds-gperf.gperf"
      {"journal-get-data-threshold", &journal_get_data_threshold_cmd_entry},
      {(char*)0},
#line 1368 "cmds-gperf.gperf"
      {"set-uuid", &set_uuid_cmd_entry},
#line 1032 "cmds-gperf.gperf"
      {"ldmtool-remove-all", &ldmtool_remove_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1262 "cmds-gperf.gperf"
      {"read_lines", &read_lines_cmd_entry},
#line 879 "cmds-gperf.gperf"
      {"hivex-node-children", &hivex_node_children_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1059 "cmds-gperf.gperf"
      {"list_ldm_volumes", &list_ldm_volumes_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1263 "cmds-gperf.gperf"
      {"read-lines", &read_lines_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1244 "cmds-gperf.gperf"
      {"pvchange_uuid", &pvchange_uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1245 "cmds-gperf.gperf"
      {"pvchange-uuid", &pvchange_uuid_cmd_entry},
#line 1147 "cmds-gperf.gperf"
      {"mkfs-opts", &mkfs_cmd_entry},
#line 1060 "cmds-gperf.gperf"
      {"list-ldm-volumes", &list_ldm_volumes_cmd_entry},
      {(char*)0}, {(char*)0},
#line 852 "cmds-gperf.gperf"
      {"get_umask", &get_umask_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1003 "cmds-gperf.gperf"
      {"journal_close", &journal_close_cmd_entry},
      {(char*)0},
#line 1377 "cmds-gperf.gperf"
      {"sfdisk_N", &sfdisk_N_cmd_entry},
      {(char*)0},
#line 860 "cmds-gperf.gperf"
      {"glob_expand", &glob_expand_cmd_entry},
#line 1269 "cmds-gperf.gperf"
      {"remove_drive", &remove_drive_cmd_entry},
      {(char*)0},
#line 853 "cmds-gperf.gperf"
      {"get-umask", &get_umask_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1004 "cmds-gperf.gperf"
      {"journal-close", &journal_close_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 861 "cmds-gperf.gperf"
      {"glob-expand", &glob_expand_cmd_entry},
#line 1476 "cmds-gperf.gperf"
      {"vgremove", &vgremove_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1022 "cmds-gperf.gperf"
      {"lchown", &lchown_cmd_entry},
#line 1009 "cmds-gperf.gperf"
      {"journal_next", &journal_next_cmd_entry},
#line 1411 "cmds-gperf.gperf"
      {"swapon_uuid", &swapon_uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1251 "cmds-gperf.gperf"
      {"pvresize_size", &pvresize_size_cmd_entry},
      {(char*)0},
#line 1010 "cmds-gperf.gperf"
      {"journal-next", &journal_next_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1252 "cmds-gperf.gperf"
      {"pvresize-size", &pvresize_size_cmd_entry},
#line 1265 "cmds-gperf.gperf"
      {"readlink", &readlink_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 636 "cmds-gperf.gperf"
      {"blkid", &blkid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 886 "cmds-gperf.gperf"
      {"hivex_node_name", &hivex_node_name_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1039 "cmds-gperf.gperf"
      {"ldmtool_volume_partitions", &ldmtool_volume_partitions_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1037 "cmds-gperf.gperf"
      {"ldmtool_volume_hint", &ldmtool_volume_hint_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1249 "cmds-gperf.gperf"
      {"pvremove", &pvremove_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1040 "cmds-gperf.gperf"
      {"ldmtool-volume-partitions", &ldmtool_volume_partitions_cmd_entry},
      {(char*)0},
#line 872 "cmds-gperf.gperf"
      {"hivex_close", &hivex_close_cmd_entry},
      {(char*)0},
#line 1038 "cmds-gperf.gperf"
      {"ldmtool-volume-hint", &ldmtool_volume_hint_cmd_entry},
      {(char*)0},
#line 887 "cmds-gperf.gperf"
      {"hivex-node-name", &hivex_node_name_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 873 "cmds-gperf.gperf"
      {"hivex-close", &hivex_close_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1084 "cmds-gperf.gperf"
      {"luks_format", &luks_format_cmd_entry},
#line 1376 "cmds-gperf.gperf"
      {"sfdiskM", &sfdiskM_cmd_entry},
#line 663 "cmds-gperf.gperf"
      {"btrfs_filesystem_resize", &btrfs_filesystem_resize_cmd_entry},
#line 661 "cmds-gperf.gperf"
      {"btrfs_filesystem_balance", &btrfs_filesystem_balance_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1085 "cmds-gperf.gperf"
      {"luks-format", &luks_format_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 664 "cmds-gperf.gperf"
      {"btrfs-filesystem-resize", &btrfs_filesystem_resize_cmd_entry},
#line 662 "cmds-gperf.gperf"
      {"btrfs-filesystem-balance", &btrfs_filesystem_balance_cmd_entry},
      {(char*)0},
#line 1287 "cmds-gperf.gperf"
      {"rsync_in", &rsync_in_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1288 "cmds-gperf.gperf"
      {"rsync-in", &rsync_in_cmd_entry},
      {(char*)0},
#line 1274 "cmds-gperf.gperf"
      {"resize2fs", &resize2fs_cmd_entry},
#line 570 "cmds-gperf.gperf"
      {"acl_delete_def_file", &acl_delete_def_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1086 "cmds-gperf.gperf"
      {"luks_format_cipher", &luks_format_cipher_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1277 "cmds-gperf.gperf"
      {"resize2fs_size", &resize2fs_size_cmd_entry},
      {(char*)0}, {(char*)0},
#line 769 "cmds-gperf.gperf"
      {"extlinux", &extlinux_cmd_entry},
#line 973 "cmds-gperf.gperf"
      {"is_chardev", &is_chardev_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 741 "cmds-gperf.gperf"
      {"disk_format", &disk_format_cmd_entry},
      {(char*)0},
#line 1278 "cmds-gperf.gperf"
      {"resize2fs-size", &resize2fs_size_cmd_entry},
#line 571 "cmds-gperf.gperf"
      {"acl-delete-def-file", &acl_delete_def_file_cmd_entry},
      {(char*)0}, {(char*)0},
#line 974 "cmds-gperf.gperf"
      {"is-chardev", &is_chardev_cmd_entry},
#line 1087 "cmds-gperf.gperf"
      {"luks-format-cipher", &luks_format_cipher_cmd_entry},
#line 1160 "cmds-gperf.gperf"
      {"mkswap", &mkswap_cmd_entry},
      {(char*)0},
#line 742 "cmds-gperf.gperf"
      {"disk-format", &disk_format_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1133 "cmds-gperf.gperf"
      {"mke2fs", &mke2fs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1306 "cmds-gperf.gperf"
      {"set_backend", &set_backend_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 801 "cmds-gperf.gperf"
      {"get_backend", &get_backend_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1307 "cmds-gperf.gperf"
      {"set-backend", &set_backend_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 802 "cmds-gperf.gperf"
      {"get-backend", &get_backend_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1199 "cmds-gperf.gperf"
      {"ntfsresize", &ntfsresize_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1047 "cmds-gperf.gperf"
      {"list_devices", &list_devices_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1048 "cmds-gperf.gperf"
      {"list-devices", &list_devices_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1200 "cmds-gperf.gperf"
      {"ntfsresize-opts", &ntfsresize_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1339 "cmds-gperf.gperf"
      {"network", &set_network_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1302 "cmds-gperf.gperf"
      {"attach-method", &set_attach_method_cmd_entry},
      {(char*)0}, {(char*)0},
#line 665 "cmds-gperf.gperf"
      {"btrfs_filesystem_sync", &btrfs_filesystem_sync_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1511 "cmds-gperf.gperf"
      {"zfgrep", &zfgrep_cmd_entry},
#line 916 "cmds-gperf.gperf"
      {"inotify_init", &inotify_init_cmd_entry},
      {(char*)0},
#line 1185 "cmds-gperf.gperf"
      {"mount_vfs", &mount_vfs_cmd_entry},
      {(char*)0},
#line 693 "cmds-gperf.gperf"
      {"checksums_out", &checksums_out_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 917 "cmds-gperf.gperf"
      {"inotify-init", &inotify_init_cmd_entry},
      {(char*)0},
#line 1186 "cmds-gperf.gperf"
      {"mount-vfs", &mount_vfs_cmd_entry},
      {(char*)0},
#line 694 "cmds-gperf.gperf"
      {"checksums-out", &checksums_out_cmd_entry},
#line 666 "cmds-gperf.gperf"
      {"btrfs-filesystem-sync", &btrfs_filesystem_sync_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1470 "cmds-gperf.gperf"
      {"vgchange_uuid_all", &vgchange_uuid_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1164 "cmds-gperf.gperf"
      {"mkswap_U", &mkswap_U_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1027 "cmds-gperf.gperf"
      {"ldmtool_diskgroup_name", &ldmtool_diskgroup_name_cmd_entry},
#line 1025 "cmds-gperf.gperf"
      {"ldmtool_diskgroup_disks", &ldmtool_diskgroup_disks_cmd_entry},
      {(char*)0},
#line 1029 "cmds-gperf.gperf"
      {"ldmtool_diskgroup_volumes", &ldmtool_diskgroup_volumes_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1471 "cmds-gperf.gperf"
      {"vgchange-uuid-all", &vgchange_uuid_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1028 "cmds-gperf.gperf"
      {"ldmtool-diskgroup-name", &ldmtool_diskgroup_name_cmd_entry},
#line 1026 "cmds-gperf.gperf"
      {"ldmtool-diskgroup-disks", &ldmtool_diskgroup_disks_cmd_entry},
      {(char*)0},
#line 1030 "cmds-gperf.gperf"
      {"ldmtool-diskgroup-volumes", &ldmtool_diskgroup_volumes_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1479 "cmds-gperf.gperf"
      {"vgs_full", &vgs_full_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 772 "cmds-gperf.gperf"
      {"feature_available", &feature_available_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1480 "cmds-gperf.gperf"
      {"vgs-full", &vgs_full_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 874 "cmds-gperf.gperf"
      {"hivex_commit", &hivex_commit_cmd_entry},
#line 773 "cmds-gperf.gperf"
      {"feature-available", &feature_available_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1246 "cmds-gperf.gperf"
      {"pvchange_uuid_all", &pvchange_uuid_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 875 "cmds-gperf.gperf"
      {"hivex-commit", &hivex_commit_cmd_entry},
#line 1460 "cmds-gperf.gperf"
      {"vfs_type", &vfs_type_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1461 "cmds-gperf.gperf"
      {"vfs-type", &vfs_type_cmd_entry},
#line 793 "cmds-gperf.gperf"
      {"fsck", &fsck_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1247 "cmds-gperf.gperf"
      {"pvchange-uuid-all", &pvchange_uuid_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1508 "cmds-gperf.gperf"
      {"zero_free_space", &zero_free_space_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1254 "cmds-gperf.gperf"
      {"pvs_full", &pvs_full_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1255 "cmds-gperf.gperf"
      {"pvs-full", &pvs_full_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1414 "cmds-gperf.gperf"
      {"syslinux", &syslinux_cmd_entry},
#line 1509 "cmds-gperf.gperf"
      {"zero-free-space", &zero_free_space_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 657 "cmds-gperf.gperf"
      {"btrfs_device_add", &btrfs_device_add_cmd_entry},
      {(char*)0}, {(char*)0},
#line 659 "cmds-gperf.gperf"
      {"btrfs_device_delete", &btrfs_device_delete_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1103 "cmds-gperf.gperf"
      {"lvm_set_filter", &lvm_set_filter_cmd_entry},
      {(char*)0},
#line 658 "cmds-gperf.gperf"
      {"btrfs-device-add", &btrfs_device_add_cmd_entry},
      {(char*)0}, {(char*)0},
#line 660 "cmds-gperf.gperf"
      {"btrfs-device-delete", &btrfs_device_delete_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1313 "cmds-gperf.gperf"
      {"cachedir", &set_cachedir_cmd_entry},
      {(char*)0},
#line 1105 "cmds-gperf.gperf"
      {"lvremove", &lvremove_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1104 "cmds-gperf.gperf"
      {"lvm-set-filter", &lvm_set_filter_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 998 "cmds-gperf.gperf"
      {"is_zero_device", &is_zero_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 743 "cmds-gperf.gperf"
      {"disk_has_backing_file", &disk_has_backing_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 734 "cmds-gperf.gperf"
      {"device_index", &device_index_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 999 "cmds-gperf.gperf"
      {"is-zero-device", &is_zero_device_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1491 "cmds-gperf.gperf"
      {"write_append", &write_append_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1492 "cmds-gperf.gperf"
      {"write-append", &write_append_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1513 "cmds-gperf.gperf"
      {"zfile", &zfile_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 744 "cmds-gperf.gperf"
      {"disk-has-backing-file", &disk_has_backing_file_cmd_entry},
      {(char*)0},
#line 1015 "cmds-gperf.gperf"
      {"journal_skip", &journal_skip_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1016 "cmds-gperf.gperf"
      {"journal-skip", &journal_skip_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 730 "cmds-gperf.gperf"
      {"debug_upload", &debug_upload_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1451 "cmds-gperf.gperf"
      {"upload_offset", &upload_offset_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 731 "cmds-gperf.gperf"
      {"debug-upload", &debug_upload_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1458 "cmds-gperf.gperf"
      {"vfs_label", &vfs_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 690 "cmds-gperf.gperf"
      {"checksum", &checksum_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1459 "cmds-gperf.gperf"
      {"vfs-label", &vfs_label_cmd_entry},
      {(char*)0},
#line 1258 "cmds-gperf.gperf"
      {"pwrite_device", &pwrite_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1074 "cmds-gperf.gperf"
      {"lremovexattr", &lremovexattr_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1407 "cmds-gperf.gperf"
      {"swapon_file", &swapon_file_cmd_entry},
#line 1405 "cmds-gperf.gperf"
      {"swapon_device", &swapon_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1190 "cmds-gperf.gperf"
      {"nr_devices", &nr_devices_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1191 "cmds-gperf.gperf"
      {"nr-devices", &nr_devices_cmd_entry},
#line 992 "cmds-gperf.gperf"
      {"is_symlink", &is_symlink_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1101 "cmds-gperf.gperf"
      {"lvm_remove_all", &lvm_remove_all_cmd_entry},
#line 993 "cmds-gperf.gperf"
      {"is-symlink", &is_symlink_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1102 "cmds-gperf.gperf"
      {"lvm-remove-all", &lvm_remove_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1148 "cmds-gperf.gperf"
      {"mkfs_b", &mkfs_b_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1149 "cmds-gperf.gperf"
      {"mkfs-b", &mkfs_b_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1017 "cmds-gperf.gperf"
      {"kill_subprocess", &kill_subprocess_cmd_entry},
      {(char*)0},
#line 1375 "cmds-gperf.gperf"
      {"sfdisk", &sfdisk_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1145 "cmds-gperf.gperf"
      {"mkfifo", &mkfifo_cmd_entry},
      {(char*)0},
#line 1018 "cmds-gperf.gperf"
      {"kill-subprocess", &kill_subprocess_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1383 "cmds-gperf.gperf"
      {"sfdisk_l", &sfdisk_l_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1111 "cmds-gperf.gperf"
      {"lvs_full", &lvs_full_cmd_entry},
      {(char*)0},
#line 747 "cmds-gperf.gperf"
      {"display", &display_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1112 "cmds-gperf.gperf"
      {"lvs-full", &lvs_full_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1336 "cmds-gperf.gperf"
      {"memsize", &set_memsize_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 882 "cmds-gperf.gperf"
      {"hivex_node_get_child", &hivex_node_get_child_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1198 "cmds-gperf.gperf"
      {"ntfsfix", &ntfsfix_cmd_entry},
#line 912 "cmds-gperf.gperf"
      {"inotify_close", &inotify_close_cmd_entry},
#line 1378 "cmds-gperf.gperf"
      {"sfdisk-N", &sfdisk_N_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1270 "cmds-gperf.gperf"
      {"remove-drive", &remove_drive_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 913 "cmds-gperf.gperf"
      {"inotify-close", &inotify_close_cmd_entry},
#line 883 "cmds-gperf.gperf"
      {"hivex-node-get-child", &hivex_node_get_child_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1412 "cmds-gperf.gperf"
      {"swapon-uuid", &swapon_uuid_cmd_entry},
#line 1275 "cmds-gperf.gperf"
      {"resize2fs_M", &resize2fs_M_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1276 "cmds-gperf.gperf"
      {"resize2fs-M", &resize2fs_M_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1337 "cmds-gperf.gperf"
      {"set_network", &set_network_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 829 "cmds-gperf.gperf"
      {"get_network", &get_network_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1338 "cmds-gperf.gperf"
      {"set-network", &set_network_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 830 "cmds-gperf.gperf"
      {"get-network", &get_network_cmd_entry},
      {(char*)0},
#line 707 "cmds-gperf.gperf"
      {"copy_device_to_device", &copy_device_to_device_cmd_entry},
      {(char*)0}, {(char*)0},
#line 709 "cmds-gperf.gperf"
      {"copy_device_to_file", &copy_device_to_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1041 "cmds-gperf.gperf"
      {"ldmtool_volume_type", &ldmtool_volume_type_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 708 "cmds-gperf.gperf"
      {"copy-device-to-device", &copy_device_to_device_cmd_entry},
      {(char*)0},
#line 1042 "cmds-gperf.gperf"
      {"ldmtool-volume-type", &ldmtool_volume_type_cmd_entry},
#line 710 "cmds-gperf.gperf"
      {"copy-device-to-file", &copy_device_to_file_cmd_entry},
#line 1409 "cmds-gperf.gperf"
      {"swapon_label", &swapon_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 1403 "cmds-gperf.gperf"
      {"swapoff_uuid", &swapoff_uuid_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1504 "cmds-gperf.gperf"
      {"zegrepi", &zegrepi_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1404 "cmds-gperf.gperf"
      {"swapoff-uuid", &swapoff_uuid_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1464 "cmds-gperf.gperf"
      {"vg_activate", &vg_activate_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1465 "cmds-gperf.gperf"
      {"vg-activate", &vg_activate_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 667 "cmds-gperf.gperf"
      {"btrfs_fsck", &btrfs_fsck_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 755 "cmds-gperf.gperf"
      {"e2fsck", &e2fsck_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 668 "cmds-gperf.gperf"
      {"btrfs-fsck", &btrfs_fsck_cmd_entry},
      {(char*)0},
#line 892 "cmds-gperf.gperf"
      {"hivex_node_values", &hivex_node_values_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 893 "cmds-gperf.gperf"
      {"hivex-node-values", &hivex_node_values_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1260 "cmds-gperf.gperf"
      {"read_file", &read_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1261 "cmds-gperf.gperf"
      {"read-file", &read_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 972 "cmds-gperf.gperf"
      {"is-blockdev-opts", &is_blockdev_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1165 "cmds-gperf.gperf"
      {"mkswap-U", &mkswap_U_cmd_entry},
#line 791 "cmds-gperf.gperf"
      {"findfs_uuid", &findfs_uuid_cmd_entry},
#line 880 "cmds-gperf.gperf"
      {"hivex_node_delete_child", &hivex_node_delete_child_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 881 "cmds-gperf.gperf"
      {"hivex-node-delete-child", &hivex_node_delete_child_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 679 "cmds-gperf.gperf"
      {"btrfs_subvolume_snapshot", &btrfs_subvolume_snapshot_cmd_entry},
      {(char*)0}, {(char*)0},
#line 677 "cmds-gperf.gperf"
      {"btrfs_subvolume_set_default", &btrfs_subvolume_set_default_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 680 "cmds-gperf.gperf"
      {"btrfs-subvolume-snapshot", &btrfs_subvolume_snapshot_cmd_entry},
      {(char*)0}, {(char*)0},
#line 678 "cmds-gperf.gperf"
      {"btrfs-subvolume-set-default", &btrfs_subvolume_set_default_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1162 "cmds-gperf.gperf"
      {"mkswap_L", &mkswap_L_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1161 "cmds-gperf.gperf"
      {"mkswap-opts", &mkswap_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 918 "cmds-gperf.gperf"
      {"inotify_read", &inotify_read_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 919 "cmds-gperf.gperf"
      {"inotify-read", &inotify_read_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1152 "cmds-gperf.gperf"
      {"mklost_and_found", &mklost_and_found_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 904 "cmds-gperf.gperf"
      {"hivex_value_value", &hivex_value_value_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 902 "cmds-gperf.gperf"
      {"hivex_value_utf8", &hivex_value_utf8_cmd_entry},
#line 994 "cmds-gperf.gperf"
      {"is_whole_device", &is_whole_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 905 "cmds-gperf.gperf"
      {"hivex-value-value", &hivex_value_value_cmd_entry},
      {(char*)0},
#line 876 "cmds-gperf.gperf"
      {"hivex_node_add_child", &hivex_node_add_child_cmd_entry},
      {(char*)0},
#line 903 "cmds-gperf.gperf"
      {"hivex-value-utf8", &hivex_value_utf8_cmd_entry},
#line 995 "cmds-gperf.gperf"
      {"is-whole-device", &is_whole_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 749 "cmds-gperf.gperf"
      {"download", &download_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 671 "cmds-gperf.gperf"
      {"btrfs_subvolume_create", &btrfs_subvolume_create_cmd_entry},
#line 877 "cmds-gperf.gperf"
      {"hivex-node-add-child", &hivex_node_add_child_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 735 "cmds-gperf.gperf"
      {"device-index", &device_index_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 672 "cmds-gperf.gperf"
      {"btrfs-subvolume-create", &btrfs_subvolume_create_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1150 "cmds-gperf.gperf"
      {"mkfs_btrfs", &mkfs_btrfs_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1049 "cmds-gperf.gperf"
      {"list_disk_labels", &list_disk_labels_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1151 "cmds-gperf.gperf"
      {"mkfs-btrfs", &mkfs_btrfs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1510 "cmds-gperf.gperf"
      {"zerofree", &zerofree_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1050 "cmds-gperf.gperf"
      {"list-disk-labels", &list_disk_labels_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1452 "cmds-gperf.gperf"
      {"upload-offset", &upload_offset_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1475 "cmds-gperf.gperf"
      {"vgpvuuids", &vgpvuuids_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1397 "cmds-gperf.gperf"
      {"swapoff_device", &swapoff_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1398 "cmds-gperf.gperf"
      {"swapoff-device", &swapoff_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1401 "cmds-gperf.gperf"
      {"swapoff_label", &swapoff_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1259 "cmds-gperf.gperf"
      {"pwrite-device", &pwrite_device_cmd_entry},
#line 581 "cmds-gperf.gperf"
      {"add_drive", &add_drive_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1402 "cmds-gperf.gperf"
      {"swapoff-label", &swapoff_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 582 "cmds-gperf.gperf"
      {"add-drive", &add_drive_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1408 "cmds-gperf.gperf"
      {"swapon-file", &swapon_file_cmd_entry},
#line 1406 "cmds-gperf.gperf"
      {"swapon-device", &swapon_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 585 "cmds-gperf.gperf"
      {"add_drive_ro", &add_drive_ro_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 586 "cmds-gperf.gperf"
      {"add-drive-ro", &add_drive_ro_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 584 "cmds-gperf.gperf"
      {"add-drive-opts", &add_drive_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1399 "cmds-gperf.gperf"
      {"swapoff_file", &swapoff_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 783 "cmds-gperf.gperf"
      {"fill_dir", &fill_dir_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1400 "cmds-gperf.gperf"
      {"swapoff-file", &swapoff_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 784 "cmds-gperf.gperf"
      {"fill-dir", &fill_dir_cmd_entry},
#line 1384 "cmds-gperf.gperf"
      {"sfdisk-l", &sfdisk_l_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1211 "cmds-gperf.gperf"
      {"part_disk", &part_disk_cmd_entry},
      {(char*)0}, {(char*)0},
#line 675 "cmds-gperf.gperf"
      {"btrfs_subvolume_list", &btrfs_subvolume_list_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1212 "cmds-gperf.gperf"
      {"part-disk", &part_disk_cmd_entry},
      {(char*)0}, {(char*)0},
#line 676 "cmds-gperf.gperf"
      {"btrfs-subvolume-list", &btrfs_subvolume_list_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 673 "cmds-gperf.gperf"
      {"btrfs_subvolume_delete", &btrfs_subvolume_delete_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1080 "cmds-gperf.gperf"
      {"luks_add_key", &luks_add_key_cmd_entry},
#line 674 "cmds-gperf.gperf"
      {"btrfs-subvolume-delete", &btrfs_subvolume_delete_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1081 "cmds-gperf.gperf"
      {"luks-add-key", &luks_add_key_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1497 "cmds-gperf.gperf"
      {"xfs_growfs", &xfs_growfs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1410 "cmds-gperf.gperf"
      {"swapon-label", &swapon_label_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1498 "cmds-gperf.gperf"
      {"xfs-growfs", &xfs_growfs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1066 "cmds-gperf.gperf"
      {"llz", &llz_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1473 "cmds-gperf.gperf"
      {"vglvuuids", &vglvuuids_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1099 "cmds-gperf.gperf"
      {"lvm_clear_filter", &lvm_clear_filter_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1506 "cmds-gperf.gperf"
      {"zero_device", &zero_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1507 "cmds-gperf.gperf"
      {"zero-device", &zero_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1100 "cmds-gperf.gperf"
      {"lvm-clear-filter", &lvm_clear_filter_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 914 "cmds-gperf.gperf"
      {"inotify_files", &inotify_files_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1055 "cmds-gperf.gperf"
      {"list_filesystems", &list_filesystems_cmd_entry},
      {(char*)0}, {(char*)0},
#line 915 "cmds-gperf.gperf"
      {"inotify-files", &inotify_files_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1056 "cmds-gperf.gperf"
      {"list-filesystems", &list_filesystems_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 645 "cmds-gperf.gperf"
      {"blockdev_getss", &blockdev_getss_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1466 "cmds-gperf.gperf"
      {"vg_activate_all", &vg_activate_all_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 691 "cmds-gperf.gperf"
      {"checksum_device", &checksum_device_cmd_entry},
      {(char*)0},
#line 646 "cmds-gperf.gperf"
      {"blockdev-getss", &blockdev_getss_cmd_entry},
      {(char*)0}, {(char*)0},
#line 1381 "cmds-gperf.gperf"
      {"sfdisk_kernel_geometry", &sfdisk_kernel_geometry_cmd_entry},
      {(char*)0},
#line 653 "cmds-gperf.gperf"
      {"blockdev_setro", &blockdev_setro_cmd_entry},
      {(char*)0}, {(char*)0},
#line 692 "cmds-gperf.gperf"
      {"checksum-device", &checksum_device_cmd_entry},
      {(char*)0},
#line 641 "cmds-gperf.gperf"
      {"blockdev_getro", &blockdev_getro_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1467 "cmds-gperf.gperf"
      {"vg-activate-all", &vg_activate_all_cmd_entry},
#line 654 "cmds-gperf.gperf"
      {"blockdev-setro", &blockdev_setro_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 642 "cmds-gperf.gperf"
      {"blockdev-getro", &blockdev_getro_cmd_entry},
#line 745 "cmds-gperf.gperf"
      {"disk_virtual_size", &disk_virtual_size_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 643 "cmds-gperf.gperf"
      {"blockdev_getsize64", &blockdev_getsize64_cmd_entry},
      {(char*)0},
#line 746 "cmds-gperf.gperf"
      {"disk-virtual-size", &disk_virtual_size_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 644 "cmds-gperf.gperf"
      {"blockdev-getsize64", &blockdev_getsize64_cmd_entry},
      {(char*)0},
#line 1166 "cmds-gperf.gperf"
      {"mkswap_file", &mkswap_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 719 "cmds-gperf.gperf"
      {"copy_size", &copy_size_cmd_entry},
#line 792 "cmds-gperf.gperf"
      {"findfs-uuid", &findfs_uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 720 "cmds-gperf.gperf"
      {"copy-size", &copy_size_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 649 "cmds-gperf.gperf"
      {"blockdev_rereadpt", &blockdev_rereadpt_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 970 "cmds-gperf.gperf"
      {"is_blockdev", &is_blockdev_cmd_entry},
      {(char*)0},
#line 650 "cmds-gperf.gperf"
      {"blockdev-rereadpt", &blockdev_rereadpt_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 971 "cmds-gperf.gperf"
      {"is-blockdev", &is_blockdev_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1163 "cmds-gperf.gperf"
      {"mkswap-L", &mkswap_L_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 789 "cmds-gperf.gperf"
      {"findfs_label", &findfs_label_cmd_entry},
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
#line 1462 "cmds-gperf.gperf"
      {"vfs_uuid", &vfs_uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1463 "cmds-gperf.gperf"
      {"vfs-uuid", &vfs_uuid_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1153 "cmds-gperf.gperf"
      {"mklost-and-found", &mklost_and_found_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 898 "cmds-gperf.gperf"
      {"hivex_value_key", &hivex_value_key_cmd_entry},
#line 900 "cmds-gperf.gperf"
      {"hivex_value_type", &hivex_value_type_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 899 "cmds-gperf.gperf"
      {"hivex-value-key", &hivex_value_key_cmd_entry},
#line 901 "cmds-gperf.gperf"
      {"hivex-value-type", &hivex_value_type_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1512 "cmds-gperf.gperf"
      {"zfgrepi", &zfgrepi_cmd_entry},
      {(char*)0}, {(char*)0},
#line 711 "cmds-gperf.gperf"
      {"copy_file_to_device", &copy_file_to_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1201 "cmds-gperf.gperf"
      {"ntfsresize_size", &ntfsresize_size_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 712 "cmds-gperf.gperf"
      {"copy-file-to-device", &copy_file_to_device_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1202 "cmds-gperf.gperf"
      {"ntfsresize-size", &ntfsresize_size_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1487 "cmds-gperf.gperf"
      {"wc_w", &wc_w_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1488 "cmds-gperf.gperf"
      {"wc-w", &wc_w_cmd_entry},
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
#line 1379 "cmds-gperf.gperf"
      {"sfdisk_disk_geometry", &sfdisk_disk_geometry_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1138 "cmds-gperf.gperf"
      {"mke2fs_JU", &mke2fs_JU_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 910 "cmds-gperf.gperf"
      {"inotify_add_watch", &inotify_add_watch_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1143 "cmds-gperf.gperf"
      {"mke2journal_U", &mke2journal_U_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1144 "cmds-gperf.gperf"
      {"mke2journal-U", &mke2journal_U_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 911 "cmds-gperf.gperf"
      {"inotify-add-watch", &inotify_add_watch_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 756 "cmds-gperf.gperf"
      {"e2fsck_f", &e2fsck_f_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 1382 "cmds-gperf.gperf"
      {"sfdisk-kernel-geometry", &sfdisk_kernel_geometry_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1167 "cmds-gperf.gperf"
      {"mkswap-file", &mkswap_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1088 "cmds-gperf.gperf"
      {"luks_kill_slot", &luks_kill_slot_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1089 "cmds-gperf.gperf"
      {"luks-kill-slot", &luks_kill_slot_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 713 "cmds-gperf.gperf"
      {"copy_file_to_file", &copy_file_to_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 790 "cmds-gperf.gperf"
      {"findfs-label", &findfs_label_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 590 "cmds-gperf.gperf"
      {"add_drive_scratch", &add_drive_scratch_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 714 "cmds-gperf.gperf"
      {"copy-file-to-file", &copy_file_to_file_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 591 "cmds-gperf.gperf"
      {"add-drive-scratch", &add_drive_scratch_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1140 "cmds-gperf.gperf"
      {"mke2journal", &mke2journal_cmd_entry},
      {(char*)0},
#line 1141 "cmds-gperf.gperf"
      {"mke2journal_L", &mke2journal_L_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 1142 "cmds-gperf.gperf"
      {"mke2journal-L", &mke2journal_L_cmd_entry},
#line 920 "cmds-gperf.gperf"
      {"inotify_rm_watch", &inotify_rm_watch_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 921 "cmds-gperf.gperf"
      {"inotify-rm-watch", &inotify_rm_watch_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 1380 "cmds-gperf.gperf"
      {"sfdisk-disk-geometry", &sfdisk_disk_geometry_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 1139 "cmds-gperf.gperf"
      {"mke2fs-JU", &mke2fs_JU_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 750 "cmds-gperf.gperf"
      {"download_offset", &download_offset_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 1136 "cmds-gperf.gperf"
      {"mke2fs_JL", &mke2fs_JL_cmd_entry},
      {(char*)0},
#line 751 "cmds-gperf.gperf"
      {"download-offset", &download_offset_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 757 "cmds-gperf.gperf"
      {"e2fsck-f", &e2fsck_f_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 651 "cmds-gperf.gperf"
      {"blockdev_setbsz", &blockdev_setbsz_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 639 "cmds-gperf.gperf"
      {"blockdev_getbsz", &blockdev_getbsz_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 652 "cmds-gperf.gperf"
      {"blockdev-setbsz", &blockdev_setbsz_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 640 "cmds-gperf.gperf"
      {"blockdev-getbsz", &blockdev_getbsz_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1137 "cmds-gperf.gperf"
      {"mke2fs-JL", &mke2fs_JL_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 1134 "cmds-gperf.gperf"
      {"mke2fs_J", &mke2fs_J_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 588 "cmds-gperf.gperf"
      {"add_drive_ro_with_if", &add_drive_ro_with_if_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 589 "cmds-gperf.gperf"
      {"add-drive-ro-with-if", &add_drive_ro_with_if_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 1135 "cmds-gperf.gperf"
      {"mke2fs-J", &mke2fs_J_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
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
#line 655 "cmds-gperf.gperf"
      {"blockdev_setrw", &blockdev_setrw_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 656 "cmds-gperf.gperf"
      {"blockdev-setrw", &blockdev_setrw_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 637 "cmds-gperf.gperf"
      {"blockdev_flushbufs", &blockdev_flushbufs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 638 "cmds-gperf.gperf"
      {"blockdev-flushbufs", &blockdev_flushbufs_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 647 "cmds-gperf.gperf"
      {"blockdev_getsz", &blockdev_getsz_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 648 "cmds-gperf.gperf"
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
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 593 "cmds-gperf.gperf"
      {"add_drive_with_if", &add_drive_with_if_cmd_entry},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 594 "cmds-gperf.gperf"
      {"add-drive-with-if", &add_drive_with_if_cmd_entry}
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
