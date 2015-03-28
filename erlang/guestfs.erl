% libguestfs generated file
%  WARNING: THIS FILE IS GENERATED FROM:
%    generator/ *.ml
%  ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
% 
%  Copyright (C) 2009-2015 Red Hat Inc.
% 
%  This library is free software; you can redistribute it and/or
%  modify it under the terms of the GNU Lesser General Public
%  License as published by the Free Software Foundation; either
%  version 2 of the License, or (at your option) any later version.
% 
%  This library is distributed in the hope that it will be useful,
%  but WITHOUT ANY WARRANTY; without even the implied warranty of
%  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
%  Lesser General Public License for more details.
% 
%  You should have received a copy of the GNU Lesser General Public
%  License along with this library; if not, write to the Free Software
%  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

-module(guestfs).

-export([create/0, create/1, close/1, init/1]).

-export([acl_delete_def_file/2]).
-export([acl_get_file/3]).
-export([acl_set_file/4]).
-export([add_cdrom/2]).
-export([add_domain/2, add_domain/3]).
-export([add_drive/2, add_drive/3]).
-export([add_drive_opts/2, add_drive_opts/3]).
-export([add_drive_ro/2]).
-export([add_drive_ro_with_if/3]).
-export([add_drive_scratch/2, add_drive_scratch/3]).
-export([add_drive_with_if/3]).
-export([add_libvirt_dom/2, add_libvirt_dom/3]).
-export([aug_clear/2]).
-export([aug_close/1]).
-export([aug_defnode/4]).
-export([aug_defvar/3]).
-export([aug_get/2]).
-export([aug_init/3]).
-export([aug_insert/4]).
-export([aug_label/2]).
-export([aug_load/1]).
-export([aug_ls/2]).
-export([aug_match/2]).
-export([aug_mv/3]).
-export([aug_rm/2]).
-export([aug_save/1]).
-export([aug_set/3]).
-export([aug_setm/4]).
-export([available/2]).
-export([available_all_groups/1]).
-export([base64_in/3]).
-export([base64_out/3]).
-export([blkdiscard/2]).
-export([blkdiscardzeroes/2]).
-export([blkid/2]).
-export([blockdev_flushbufs/2]).
-export([blockdev_getbsz/2]).
-export([blockdev_getro/2]).
-export([blockdev_getsize64/2]).
-export([blockdev_getss/2]).
-export([blockdev_getsz/2]).
-export([blockdev_rereadpt/2]).
-export([blockdev_setbsz/3]).
-export([blockdev_setra/3]).
-export([blockdev_setro/2]).
-export([blockdev_setrw/2]).
-export([btrfs_balance_cancel/2]).
-export([btrfs_balance_pause/2]).
-export([btrfs_balance_resume/2]).
-export([btrfs_balance_status/2]).
-export([btrfs_device_add/3]).
-export([btrfs_device_delete/3]).
-export([btrfs_filesystem_balance/2]).
-export([btrfs_filesystem_defragment/2, btrfs_filesystem_defragment/3]).
-export([btrfs_filesystem_resize/2, btrfs_filesystem_resize/3]).
-export([btrfs_filesystem_sync/2]).
-export([btrfs_fsck/2, btrfs_fsck/3]).
-export([btrfs_image/3, btrfs_image/4]).
-export([btrfs_qgroup_assign/4]).
-export([btrfs_qgroup_create/3]).
-export([btrfs_qgroup_destroy/3]).
-export([btrfs_qgroup_limit/3]).
-export([btrfs_qgroup_remove/4]).
-export([btrfs_qgroup_show/2]).
-export([btrfs_quota_enable/3]).
-export([btrfs_quota_rescan/2]).
-export([btrfs_rescue_chunk_recover/2]).
-export([btrfs_rescue_super_recover/2]).
-export([btrfs_scrub_cancel/2]).
-export([btrfs_scrub_resume/2]).
-export([btrfs_scrub_start/2]).
-export([btrfs_scrub_status/2]).
-export([btrfs_set_seeding/3]).
-export([btrfs_subvolume_create/2, btrfs_subvolume_create/3]).
-export([btrfs_subvolume_create_opts/2, btrfs_subvolume_create_opts/3]).
-export([btrfs_subvolume_delete/2]).
-export([btrfs_subvolume_get_default/2]).
-export([btrfs_subvolume_list/2]).
-export([btrfs_subvolume_set_default/3]).
-export([btrfs_subvolume_show/2]).
-export([btrfs_subvolume_snapshot/3, btrfs_subvolume_snapshot/4]).
-export([btrfs_subvolume_snapshot_opts/3, btrfs_subvolume_snapshot_opts/4]).
-export([btrfstune_enable_extended_inode_refs/2]).
-export([btrfstune_enable_skinny_metadata_extent_refs/2]).
-export([btrfstune_seeding/3]).
-export([c_pointer/1]).
-export([canonical_device_name/2]).
-export([cap_get_file/2]).
-export([cap_set_file/3]).
-export([case_sensitive_path/2]).
-export([cat/2]).
-export([checksum/3]).
-export([checksum_device/3]).
-export([checksums_out/4]).
-export([chmod/3]).
-export([chown/4]).
-export([clear_backend_setting/2]).
-export([command/2]).
-export([command_lines/2]).
-export([compress_device_out/4, compress_device_out/5]).
-export([compress_out/4, compress_out/5]).
-export([config/3]).
-export([copy_attributes/3, copy_attributes/4]).
-export([copy_device_to_device/3, copy_device_to_device/4]).
-export([copy_device_to_file/3, copy_device_to_file/4]).
-export([copy_file_to_device/3, copy_file_to_device/4]).
-export([copy_file_to_file/3, copy_file_to_file/4]).
-export([copy_in/3]).
-export([copy_out/3]).
-export([copy_size/4]).
-export([cp/3]).
-export([cp_a/3]).
-export([cp_r/3]).
-export([cpio_out/3, cpio_out/4]).
-export([dd/3]).
-export([debug/3]).
-export([debug_drives/1]).
-export([debug_upload/4]).
-export([device_index/2]).
-export([df/1]).
-export([df_h/1]).
-export([disk_create/4, disk_create/5]).
-export([disk_format/2]).
-export([disk_has_backing_file/2]).
-export([disk_virtual_size/2]).
-export([dmesg/1]).
-export([download/3]).
-export([download_offset/5]).
-export([drop_caches/2]).
-export([du/2]).
-export([e2fsck/2, e2fsck/3]).
-export([e2fsck_f/2]).
-export([echo_daemon/2]).
-export([egrep/3]).
-export([egrepi/3]).
-export([equal/3]).
-export([exists/2]).
-export([extlinux/2]).
-export([fallocate/3]).
-export([fallocate64/3]).
-export([feature_available/2]).
-export([fgrep/3]).
-export([fgrepi/3]).
-export([file/2]).
-export([file_architecture/2]).
-export([filesize/2]).
-export([filesystem_available/2]).
-export([fill/4]).
-export([fill_dir/3]).
-export([fill_pattern/4]).
-export([find/2]).
-export([find0/3]).
-export([findfs_label/2]).
-export([findfs_uuid/2]).
-export([fsck/3]).
-export([fstrim/2, fstrim/3]).
-export([get_append/1]).
-export([get_attach_method/1]).
-export([get_autosync/1]).
-export([get_backend/1]).
-export([get_backend_setting/2]).
-export([get_backend_settings/1]).
-export([get_cachedir/1]).
-export([get_direct/1]).
-export([get_e2attrs/2]).
-export([get_e2generation/2]).
-export([get_e2label/2]).
-export([get_e2uuid/2]).
-export([get_hv/1]).
-export([get_libvirt_requested_credential_challenge/2]).
-export([get_libvirt_requested_credential_defresult/2]).
-export([get_libvirt_requested_credential_prompt/2]).
-export([get_libvirt_requested_credentials/1]).
-export([get_memsize/1]).
-export([get_network/1]).
-export([get_path/1]).
-export([get_pgroup/1]).
-export([get_pid/1]).
-export([get_program/1]).
-export([get_qemu/1]).
-export([get_recovery_proc/1]).
-export([get_selinux/1]).
-export([get_smp/1]).
-export([get_state/1]).
-export([get_tmpdir/1]).
-export([get_trace/1]).
-export([get_umask/1]).
-export([get_verbose/1]).
-export([getcon/1]).
-export([getxattr/3]).
-export([getxattrs/2]).
-export([glob_expand/2]).
-export([grep/3, grep/4]).
-export([grep_opts/3, grep_opts/4]).
-export([grepi/3]).
-export([grub_install/3]).
-export([head/2]).
-export([head_n/3]).
-export([hexdump/2]).
-export([hivex_close/1]).
-export([hivex_commit/2]).
-export([hivex_node_add_child/3]).
-export([hivex_node_children/2]).
-export([hivex_node_delete_child/2]).
-export([hivex_node_get_child/3]).
-export([hivex_node_get_value/3]).
-export([hivex_node_name/2]).
-export([hivex_node_parent/2]).
-export([hivex_node_set_value/5]).
-export([hivex_node_values/2]).
-export([hivex_open/2, hivex_open/3]).
-export([hivex_root/1]).
-export([hivex_value_key/2]).
-export([hivex_value_type/2]).
-export([hivex_value_utf8/2]).
-export([hivex_value_value/2]).
-export([initrd_cat/3]).
-export([initrd_list/2]).
-export([inotify_add_watch/3]).
-export([inotify_close/1]).
-export([inotify_files/1]).
-export([inotify_init/2]).
-export([inotify_read/1]).
-export([inotify_rm_watch/2]).
-export([inspect_get_arch/2]).
-export([inspect_get_distro/2]).
-export([inspect_get_drive_mappings/2]).
-export([inspect_get_filesystems/2]).
-export([inspect_get_format/2]).
-export([inspect_get_hostname/2]).
-export([inspect_get_icon/2, inspect_get_icon/3]).
-export([inspect_get_major_version/2]).
-export([inspect_get_minor_version/2]).
-export([inspect_get_mountpoints/2]).
-export([inspect_get_package_format/2]).
-export([inspect_get_package_management/2]).
-export([inspect_get_product_name/2]).
-export([inspect_get_product_variant/2]).
-export([inspect_get_roots/1]).
-export([inspect_get_type/2]).
-export([inspect_get_windows_current_control_set/2]).
-export([inspect_get_windows_systemroot/2]).
-export([inspect_is_live/2]).
-export([inspect_is_multipart/2]).
-export([inspect_is_netinst/2]).
-export([inspect_list_applications/2]).
-export([inspect_list_applications2/2]).
-export([inspect_os/1]).
-export([internal_test/10, internal_test/11]).
-export([internal_test_63_optargs/1, internal_test_63_optargs/2]).
-export([internal_test_close_output/1]).
-export([internal_test_only_optargs/1, internal_test_only_optargs/2]).
-export([internal_test_rbool/2]).
-export([internal_test_rboolerr/1]).
-export([internal_test_rbufferout/2]).
-export([internal_test_rbufferouterr/1]).
-export([internal_test_rconstoptstring/2]).
-export([internal_test_rconstoptstringerr/1]).
-export([internal_test_rconststring/2]).
-export([internal_test_rconststringerr/1]).
-export([internal_test_rhashtable/2]).
-export([internal_test_rhashtableerr/1]).
-export([internal_test_rint/2]).
-export([internal_test_rint64/2]).
-export([internal_test_rint64err/1]).
-export([internal_test_rinterr/1]).
-export([internal_test_rstring/2]).
-export([internal_test_rstringerr/1]).
-export([internal_test_rstringlist/2]).
-export([internal_test_rstringlisterr/1]).
-export([internal_test_rstruct/2]).
-export([internal_test_rstructerr/1]).
-export([internal_test_rstructlist/2]).
-export([internal_test_rstructlisterr/1]).
-export([internal_test_set_output/2]).
-export([is_blockdev/2, is_blockdev/3]).
-export([is_blockdev_opts/2, is_blockdev_opts/3]).
-export([is_busy/1]).
-export([is_chardev/2, is_chardev/3]).
-export([is_chardev_opts/2, is_chardev_opts/3]).
-export([is_config/1]).
-export([is_dir/2, is_dir/3]).
-export([is_dir_opts/2, is_dir_opts/3]).
-export([is_fifo/2, is_fifo/3]).
-export([is_fifo_opts/2, is_fifo_opts/3]).
-export([is_file/2, is_file/3]).
-export([is_file_opts/2, is_file_opts/3]).
-export([is_launching/1]).
-export([is_lv/2]).
-export([is_ready/1]).
-export([is_socket/2, is_socket/3]).
-export([is_socket_opts/2, is_socket_opts/3]).
-export([is_symlink/2]).
-export([is_whole_device/2]).
-export([is_zero/2]).
-export([is_zero_device/2]).
-export([isoinfo/2]).
-export([isoinfo_device/2]).
-export([journal_close/1]).
-export([journal_get/1]).
-export([journal_get_data_threshold/1]).
-export([journal_get_realtime_usec/1]).
-export([journal_next/1]).
-export([journal_open/2]).
-export([journal_set_data_threshold/2]).
-export([journal_skip/2]).
-export([kill_subprocess/1]).
-export([launch/1]).
-export([lchown/4]).
-export([ldmtool_create_all/1]).
-export([ldmtool_diskgroup_disks/2]).
-export([ldmtool_diskgroup_name/2]).
-export([ldmtool_diskgroup_volumes/2]).
-export([ldmtool_remove_all/1]).
-export([ldmtool_scan/1]).
-export([ldmtool_scan_devices/2]).
-export([ldmtool_volume_hint/3]).
-export([ldmtool_volume_partitions/3]).
-export([ldmtool_volume_type/3]).
-export([lgetxattr/3]).
-export([lgetxattrs/2]).
-export([list_9p/1]).
-export([list_devices/1]).
-export([list_disk_labels/1]).
-export([list_dm_devices/1]).
-export([list_filesystems/1]).
-export([list_ldm_partitions/1]).
-export([list_ldm_volumes/1]).
-export([list_md_devices/1]).
-export([list_partitions/1]).
-export([ll/2]).
-export([llz/2]).
-export([ln/3]).
-export([ln_f/3]).
-export([ln_s/3]).
-export([ln_sf/3]).
-export([lremovexattr/3]).
-export([ls/2]).
-export([ls0/3]).
-export([lsetxattr/5]).
-export([lstat/2]).
-export([lstatlist/3]).
-export([lstatns/2]).
-export([lstatnslist/3]).
-export([luks_add_key/5]).
-export([luks_close/2]).
-export([luks_format/4]).
-export([luks_format_cipher/5]).
-export([luks_kill_slot/4]).
-export([luks_open/4]).
-export([luks_open_ro/4]).
-export([lvcreate/4]).
-export([lvcreate_free/4]).
-export([lvm_canonical_lv_name/2]).
-export([lvm_clear_filter/1]).
-export([lvm_remove_all/1]).
-export([lvm_set_filter/2]).
-export([lvremove/2]).
-export([lvrename/3]).
-export([lvresize/3]).
-export([lvresize_free/3]).
-export([lvs/1]).
-export([lvs_full/1]).
-export([lvuuid/2]).
-export([lxattrlist/3]).
-export([max_disks/1]).
-export([md_create/3, md_create/4]).
-export([md_detail/2]).
-export([md_stat/2]).
-export([md_stop/2]).
-export([mkdir/2]).
-export([mkdir_mode/3]).
-export([mkdir_p/2]).
-export([mkdtemp/2]).
-export([mke2fs/2, mke2fs/3]).
-export([mke2fs_J/5]).
-export([mke2fs_JL/5]).
-export([mke2fs_JU/5]).
-export([mke2journal/3]).
-export([mke2journal_L/4]).
-export([mke2journal_U/4]).
-export([mkfifo/3]).
-export([mkfs/3, mkfs/4]).
-export([mkfs_opts/3, mkfs_opts/4]).
-export([mkfs_b/4]).
-export([mkfs_btrfs/2, mkfs_btrfs/3]).
-export([mklost_and_found/2]).
-export([mkmountpoint/2]).
-export([mknod/5]).
-export([mknod_b/5]).
-export([mknod_c/5]).
-export([mkswap/2, mkswap/3]).
-export([mkswap_opts/2, mkswap_opts/3]).
-export([mkswap_L/3]).
-export([mkswap_U/3]).
-export([mkswap_file/2]).
-export([mktemp/2, mktemp/3]).
-export([modprobe/2]).
-export([mount/3]).
-export([mount_9p/3, mount_9p/4]).
-export([mount_local/2, mount_local/3]).
-export([mount_local_run/1]).
-export([mount_loop/3]).
-export([mount_options/4]).
-export([mount_ro/3]).
-export([mount_vfs/5]).
-export([mountpoints/1]).
-export([mounts/1]).
-export([mv/3]).
-export([nr_devices/1]).
-export([ntfs_3g_probe/3]).
-export([ntfsclone_in/3]).
-export([ntfsclone_out/3, ntfsclone_out/4]).
-export([ntfsfix/2, ntfsfix/3]).
-export([ntfsresize/2, ntfsresize/3]).
-export([ntfsresize_opts/2, ntfsresize_opts/3]).
-export([ntfsresize_size/3]).
-export([parse_environment/1]).
-export([parse_environment_list/2]).
-export([part_add/5]).
-export([part_del/3]).
-export([part_disk/3]).
-export([part_get_bootable/3]).
-export([part_get_gpt_guid/3]).
-export([part_get_gpt_type/3]).
-export([part_get_mbr_id/3]).
-export([part_get_mbr_part_type/3]).
-export([part_get_name/3]).
-export([part_get_parttype/2]).
-export([part_init/3]).
-export([part_list/2]).
-export([part_set_bootable/4]).
-export([part_set_gpt_guid/4]).
-export([part_set_gpt_type/4]).
-export([part_set_mbr_id/4]).
-export([part_set_name/4]).
-export([part_to_dev/2]).
-export([part_to_partnum/2]).
-export([ping_daemon/1]).
-export([pread/4]).
-export([pread_device/4]).
-export([pvchange_uuid/2]).
-export([pvchange_uuid_all/1]).
-export([pvcreate/2]).
-export([pvremove/2]).
-export([pvresize/2]).
-export([pvresize_size/3]).
-export([pvs/1]).
-export([pvs_full/1]).
-export([pvuuid/2]).
-export([pwrite/4]).
-export([pwrite_device/4]).
-export([read_file/2]).
-export([read_lines/2]).
-export([readdir/2]).
-export([readlink/2]).
-export([readlinklist/3]).
-export([realpath/2]).
-export([remount/2, remount/3]).
-export([remove_drive/2]).
-export([removexattr/3]).
-export([rename/3]).
-export([resize2fs/2]).
-export([resize2fs_M/2]).
-export([resize2fs_size/3]).
-export([rm/2]).
-export([rm_f/2]).
-export([rm_rf/2]).
-export([rmdir/2]).
-export([rmmountpoint/2]).
-export([rsync/3, rsync/4]).
-export([rsync_in/3, rsync_in/4]).
-export([rsync_out/3, rsync_out/4]).
-export([scrub_device/2]).
-export([scrub_file/2]).
-export([scrub_freespace/2]).
-export([set_append/2]).
-export([set_attach_method/2]).
-export([set_autosync/2]).
-export([set_backend/2]).
-export([set_backend_setting/3]).
-export([set_backend_settings/2]).
-export([set_cachedir/2]).
-export([set_direct/2]).
-export([set_e2attrs/3, set_e2attrs/4]).
-export([set_e2generation/3]).
-export([set_e2label/3]).
-export([set_e2uuid/3]).
-export([set_hv/2]).
-export([set_label/3]).
-export([set_libvirt_requested_credential/3]).
-export([set_libvirt_supported_credentials/2]).
-export([set_memsize/2]).
-export([set_network/2]).
-export([set_path/2]).
-export([set_pgroup/2]).
-export([set_program/2]).
-export([set_qemu/2]).
-export([set_recovery_proc/2]).
-export([set_selinux/2]).
-export([set_smp/2]).
-export([set_tmpdir/2]).
-export([set_trace/2]).
-export([set_uuid/3]).
-export([set_verbose/2]).
-export([setcon/2]).
-export([setxattr/5]).
-export([sfdisk/6]).
-export([sfdiskM/3]).
-export([sfdisk_N/7]).
-export([sfdisk_disk_geometry/2]).
-export([sfdisk_kernel_geometry/2]).
-export([sfdisk_l/2]).
-export([sh/2]).
-export([sh_lines/2]).
-export([shutdown/1]).
-export([sleep/2]).
-export([stat/2]).
-export([statns/2]).
-export([statvfs/2]).
-export([strings/2]).
-export([strings_e/3]).
-export([swapoff_device/2]).
-export([swapoff_file/2]).
-export([swapoff_label/2]).
-export([swapoff_uuid/2]).
-export([swapon_device/2]).
-export([swapon_file/2]).
-export([swapon_label/2]).
-export([swapon_uuid/2]).
-export([sync/1]).
-export([syslinux/2, syslinux/3]).
-export([tail/2]).
-export([tail_n/3]).
-export([tar_in/3, tar_in/4]).
-export([tar_in_opts/3, tar_in_opts/4]).
-export([tar_out/3, tar_out/4]).
-export([tar_out_opts/3, tar_out_opts/4]).
-export([tgz_in/3]).
-export([tgz_out/3]).
-export([touch/2]).
-export([truncate/2]).
-export([truncate_size/3]).
-export([tune2fs/2, tune2fs/3]).
-export([tune2fs_l/2]).
-export([txz_in/3]).
-export([txz_out/3]).
-export([umask/2]).
-export([umount/2, umount/3]).
-export([umount_opts/2, umount_opts/3]).
-export([umount_all/1]).
-export([umount_local/1, umount_local/2]).
-export([upload/3]).
-export([upload_offset/4]).
-export([user_cancel/1]).
-export([utimens/6]).
-export([utsname/1]).
-export([version/1]).
-export([vfs_label/2]).
-export([vfs_type/2]).
-export([vfs_uuid/2]).
-export([vg_activate/3]).
-export([vg_activate_all/2]).
-export([vgchange_uuid/2]).
-export([vgchange_uuid_all/1]).
-export([vgcreate/3]).
-export([vglvuuids/2]).
-export([vgmeta/2]).
-export([vgpvuuids/2]).
-export([vgremove/2]).
-export([vgrename/3]).
-export([vgs/1]).
-export([vgs_full/1]).
-export([vgscan/1]).
-export([vguuid/2]).
-export([wait_ready/1]).
-export([wc_c/2]).
-export([wc_l/2]).
-export([wc_w/2]).
-export([wipefs/2]).
-export([write/3]).
-export([write_append/3]).
-export([write_file/4]).
-export([xfs_admin/2, xfs_admin/3]).
-export([xfs_growfs/2, xfs_growfs/3]).
-export([xfs_info/2]).
-export([xfs_repair/2, xfs_repair/3]).
-export([zegrep/3]).
-export([zegrepi/3]).
-export([zero/2]).
-export([zero_device/2]).
-export([zero_free_space/2]).
-export([zerofree/2]).
-export([zfgrep/3]).
-export([zfgrepi/3]).
-export([zfile/3]).
-export([zgrep/3]).
-export([zgrepi/3]).

create() ->
  create("erl-guestfs").

create(ExtProg) ->
  G = spawn(?MODULE, init, [ExtProg]),
  {ok, G}.

close(G) ->
  G ! close,
  ok.

call_port(G, Args) ->
  G ! {call, self(), Args},
  receive
    {guestfs, Result} ->
      Result
  end.

init(ExtProg) ->
  process_flag(trap_exit, true),
  Port = open_port({spawn, ExtProg}, [{packet, 4}, binary]),
  loop(Port).
loop(Port) ->
  receive
    {call, Caller, Args} ->
      Port ! { self(), {command, term_to_binary(Args)}},
      receive
        {Port, {data, Result}} ->
          Caller ! { guestfs, binary_to_term(Result)}
      end,
      loop(Port);
    close ->
      port_close(Port),
      exit(normal);
    { 'EXIT', Port, _ } ->
      exit(port_terminated)
  end.

acl_delete_def_file(G, Dir) ->
  call_port(G, {acl_delete_def_file, Dir}).

acl_get_file(G, Path, Acltype) ->
  call_port(G, {acl_get_file, Path, Acltype}).

acl_set_file(G, Path, Acltype, Acl) ->
  call_port(G, {acl_set_file, Path, Acltype, Acl}).

add_cdrom(G, Filename) ->
  call_port(G, {add_cdrom, Filename}).

add_domain(G, Dom, Optargs) ->
  call_port(G, {add_domain, Dom, Optargs}).
add_domain(G, Dom) ->
  add_domain(G, Dom, []).

add_drive(G, Filename, Optargs) ->
  call_port(G, {add_drive, Filename, Optargs}).
add_drive(G, Filename) ->
  add_drive(G, Filename, []).
add_drive_opts(G, Filename, Optargs) ->
  add_drive(G, Filename, Optargs).
add_drive_opts(G, Filename) ->
  add_drive(G, Filename).

add_drive_ro(G, Filename) ->
  call_port(G, {add_drive_ro, Filename}).

add_drive_ro_with_if(G, Filename, Iface) ->
  call_port(G, {add_drive_ro_with_if, Filename, Iface}).

add_drive_scratch(G, Size, Optargs) ->
  call_port(G, {add_drive_scratch, Size, Optargs}).
add_drive_scratch(G, Size) ->
  add_drive_scratch(G, Size, []).

add_drive_with_if(G, Filename, Iface) ->
  call_port(G, {add_drive_with_if, Filename, Iface}).

add_libvirt_dom(G, Dom, Optargs) ->
  call_port(G, {add_libvirt_dom, Dom, Optargs}).
add_libvirt_dom(G, Dom) ->
  add_libvirt_dom(G, Dom, []).

aug_clear(G, Augpath) ->
  call_port(G, {aug_clear, Augpath}).

aug_close(G) ->
  call_port(G, {aug_close}).

aug_defnode(G, Name, Expr, Val) ->
  call_port(G, {aug_defnode, Name, Expr, Val}).

aug_defvar(G, Name, Expr) ->
  call_port(G, {aug_defvar, Name, Expr}).

aug_get(G, Augpath) ->
  call_port(G, {aug_get, Augpath}).

aug_init(G, Root, Flags) ->
  call_port(G, {aug_init, Root, Flags}).

aug_insert(G, Augpath, Label, Before) ->
  call_port(G, {aug_insert, Augpath, Label, Before}).

aug_label(G, Augpath) ->
  call_port(G, {aug_label, Augpath}).

aug_load(G) ->
  call_port(G, {aug_load}).

aug_ls(G, Augpath) ->
  call_port(G, {aug_ls, Augpath}).

aug_match(G, Augpath) ->
  call_port(G, {aug_match, Augpath}).

aug_mv(G, Src, Dest) ->
  call_port(G, {aug_mv, Src, Dest}).

aug_rm(G, Augpath) ->
  call_port(G, {aug_rm, Augpath}).

aug_save(G) ->
  call_port(G, {aug_save}).

aug_set(G, Augpath, Val) ->
  call_port(G, {aug_set, Augpath, Val}).

aug_setm(G, Base, Sub, Val) ->
  call_port(G, {aug_setm, Base, Sub, Val}).

available(G, Groups) ->
  call_port(G, {available, Groups}).

available_all_groups(G) ->
  call_port(G, {available_all_groups}).

base64_in(G, Base64file, Filename) ->
  call_port(G, {base64_in, Base64file, Filename}).

base64_out(G, Filename, Base64file) ->
  call_port(G, {base64_out, Filename, Base64file}).

blkdiscard(G, Device) ->
  call_port(G, {blkdiscard, Device}).

blkdiscardzeroes(G, Device) ->
  call_port(G, {blkdiscardzeroes, Device}).

blkid(G, Device) ->
  call_port(G, {blkid, Device}).

blockdev_flushbufs(G, Device) ->
  call_port(G, {blockdev_flushbufs, Device}).

blockdev_getbsz(G, Device) ->
  call_port(G, {blockdev_getbsz, Device}).

blockdev_getro(G, Device) ->
  call_port(G, {blockdev_getro, Device}).

blockdev_getsize64(G, Device) ->
  call_port(G, {blockdev_getsize64, Device}).

blockdev_getss(G, Device) ->
  call_port(G, {blockdev_getss, Device}).

blockdev_getsz(G, Device) ->
  call_port(G, {blockdev_getsz, Device}).

blockdev_rereadpt(G, Device) ->
  call_port(G, {blockdev_rereadpt, Device}).

blockdev_setbsz(G, Device, Blocksize) ->
  call_port(G, {blockdev_setbsz, Device, Blocksize}).

blockdev_setra(G, Device, Sectors) ->
  call_port(G, {blockdev_setra, Device, Sectors}).

blockdev_setro(G, Device) ->
  call_port(G, {blockdev_setro, Device}).

blockdev_setrw(G, Device) ->
  call_port(G, {blockdev_setrw, Device}).

btrfs_balance_cancel(G, Path) ->
  call_port(G, {btrfs_balance_cancel, Path}).

btrfs_balance_pause(G, Path) ->
  call_port(G, {btrfs_balance_pause, Path}).

btrfs_balance_resume(G, Path) ->
  call_port(G, {btrfs_balance_resume, Path}).

btrfs_balance_status(G, Path) ->
  call_port(G, {btrfs_balance_status, Path}).

btrfs_device_add(G, Devices, Fs) ->
  call_port(G, {btrfs_device_add, Devices, Fs}).

btrfs_device_delete(G, Devices, Fs) ->
  call_port(G, {btrfs_device_delete, Devices, Fs}).

btrfs_filesystem_balance(G, Fs) ->
  call_port(G, {btrfs_filesystem_balance, Fs}).

btrfs_filesystem_defragment(G, Path, Optargs) ->
  call_port(G, {btrfs_filesystem_defragment, Path, Optargs}).
btrfs_filesystem_defragment(G, Path) ->
  btrfs_filesystem_defragment(G, Path, []).

btrfs_filesystem_resize(G, Mountpoint, Optargs) ->
  call_port(G, {btrfs_filesystem_resize, Mountpoint, Optargs}).
btrfs_filesystem_resize(G, Mountpoint) ->
  btrfs_filesystem_resize(G, Mountpoint, []).

btrfs_filesystem_sync(G, Fs) ->
  call_port(G, {btrfs_filesystem_sync, Fs}).

btrfs_fsck(G, Device, Optargs) ->
  call_port(G, {btrfs_fsck, Device, Optargs}).
btrfs_fsck(G, Device) ->
  btrfs_fsck(G, Device, []).

btrfs_image(G, Source, Image, Optargs) ->
  call_port(G, {btrfs_image, Source, Image, Optargs}).
btrfs_image(G, Source, Image) ->
  btrfs_image(G, Source, Image, []).

btrfs_qgroup_assign(G, Src, Dst, Path) ->
  call_port(G, {btrfs_qgroup_assign, Src, Dst, Path}).

btrfs_qgroup_create(G, Qgroupid, Subvolume) ->
  call_port(G, {btrfs_qgroup_create, Qgroupid, Subvolume}).

btrfs_qgroup_destroy(G, Qgroupid, Subvolume) ->
  call_port(G, {btrfs_qgroup_destroy, Qgroupid, Subvolume}).

btrfs_qgroup_limit(G, Subvolume, Size) ->
  call_port(G, {btrfs_qgroup_limit, Subvolume, Size}).

btrfs_qgroup_remove(G, Src, Dst, Path) ->
  call_port(G, {btrfs_qgroup_remove, Src, Dst, Path}).

btrfs_qgroup_show(G, Path) ->
  call_port(G, {btrfs_qgroup_show, Path}).

btrfs_quota_enable(G, Fs, Enable) ->
  call_port(G, {btrfs_quota_enable, Fs, Enable}).

btrfs_quota_rescan(G, Fs) ->
  call_port(G, {btrfs_quota_rescan, Fs}).

btrfs_rescue_chunk_recover(G, Device) ->
  call_port(G, {btrfs_rescue_chunk_recover, Device}).

btrfs_rescue_super_recover(G, Device) ->
  call_port(G, {btrfs_rescue_super_recover, Device}).

btrfs_scrub_cancel(G, Path) ->
  call_port(G, {btrfs_scrub_cancel, Path}).

btrfs_scrub_resume(G, Path) ->
  call_port(G, {btrfs_scrub_resume, Path}).

btrfs_scrub_start(G, Path) ->
  call_port(G, {btrfs_scrub_start, Path}).

btrfs_scrub_status(G, Path) ->
  call_port(G, {btrfs_scrub_status, Path}).

btrfs_set_seeding(G, Device, Seeding) ->
  call_port(G, {btrfs_set_seeding, Device, Seeding}).

btrfs_subvolume_create(G, Dest, Optargs) ->
  call_port(G, {btrfs_subvolume_create, Dest, Optargs}).
btrfs_subvolume_create(G, Dest) ->
  btrfs_subvolume_create(G, Dest, []).
btrfs_subvolume_create_opts(G, Dest, Optargs) ->
  btrfs_subvolume_create(G, Dest, Optargs).
btrfs_subvolume_create_opts(G, Dest) ->
  btrfs_subvolume_create(G, Dest).

btrfs_subvolume_delete(G, Subvolume) ->
  call_port(G, {btrfs_subvolume_delete, Subvolume}).

btrfs_subvolume_get_default(G, Fs) ->
  call_port(G, {btrfs_subvolume_get_default, Fs}).

btrfs_subvolume_list(G, Fs) ->
  call_port(G, {btrfs_subvolume_list, Fs}).

btrfs_subvolume_set_default(G, Id, Fs) ->
  call_port(G, {btrfs_subvolume_set_default, Id, Fs}).

btrfs_subvolume_show(G, Subvolume) ->
  call_port(G, {btrfs_subvolume_show, Subvolume}).

btrfs_subvolume_snapshot(G, Source, Dest, Optargs) ->
  call_port(G, {btrfs_subvolume_snapshot, Source, Dest, Optargs}).
btrfs_subvolume_snapshot(G, Source, Dest) ->
  btrfs_subvolume_snapshot(G, Source, Dest, []).
btrfs_subvolume_snapshot_opts(G, Source, Dest, Optargs) ->
  btrfs_subvolume_snapshot(G, Source, Dest, Optargs).
btrfs_subvolume_snapshot_opts(G, Source, Dest) ->
  btrfs_subvolume_snapshot(G, Source, Dest).

btrfstune_enable_extended_inode_refs(G, Device) ->
  call_port(G, {btrfstune_enable_extended_inode_refs, Device}).

btrfstune_enable_skinny_metadata_extent_refs(G, Device) ->
  call_port(G, {btrfstune_enable_skinny_metadata_extent_refs, Device}).

btrfstune_seeding(G, Device, Seeding) ->
  call_port(G, {btrfstune_seeding, Device, Seeding}).

c_pointer(G) ->
  call_port(G, {c_pointer}).

canonical_device_name(G, Device) ->
  call_port(G, {canonical_device_name, Device}).

cap_get_file(G, Path) ->
  call_port(G, {cap_get_file, Path}).

cap_set_file(G, Path, Cap) ->
  call_port(G, {cap_set_file, Path, Cap}).

case_sensitive_path(G, Path) ->
  call_port(G, {case_sensitive_path, Path}).

cat(G, Path) ->
  call_port(G, {cat, Path}).

checksum(G, Csumtype, Path) ->
  call_port(G, {checksum, Csumtype, Path}).

checksum_device(G, Csumtype, Device) ->
  call_port(G, {checksum_device, Csumtype, Device}).

checksums_out(G, Csumtype, Directory, Sumsfile) ->
  call_port(G, {checksums_out, Csumtype, Directory, Sumsfile}).

chmod(G, Mode, Path) ->
  call_port(G, {chmod, Mode, Path}).

chown(G, Owner, Group, Path) ->
  call_port(G, {chown, Owner, Group, Path}).

clear_backend_setting(G, Name) ->
  call_port(G, {clear_backend_setting, Name}).

command(G, Arguments) ->
  call_port(G, {command, Arguments}).

command_lines(G, Arguments) ->
  call_port(G, {command_lines, Arguments}).

compress_device_out(G, Ctype, Device, Zdevice, Optargs) ->
  call_port(G, {compress_device_out, Ctype, Device, Zdevice, Optargs}).
compress_device_out(G, Ctype, Device, Zdevice) ->
  compress_device_out(G, Ctype, Device, Zdevice, []).

compress_out(G, Ctype, File, Zfile, Optargs) ->
  call_port(G, {compress_out, Ctype, File, Zfile, Optargs}).
compress_out(G, Ctype, File, Zfile) ->
  compress_out(G, Ctype, File, Zfile, []).

config(G, Hvparam, Hvvalue) ->
  call_port(G, {config, Hvparam, Hvvalue}).

copy_attributes(G, Src, Dest, Optargs) ->
  call_port(G, {copy_attributes, Src, Dest, Optargs}).
copy_attributes(G, Src, Dest) ->
  copy_attributes(G, Src, Dest, []).

copy_device_to_device(G, Src, Dest, Optargs) ->
  call_port(G, {copy_device_to_device, Src, Dest, Optargs}).
copy_device_to_device(G, Src, Dest) ->
  copy_device_to_device(G, Src, Dest, []).

copy_device_to_file(G, Src, Dest, Optargs) ->
  call_port(G, {copy_device_to_file, Src, Dest, Optargs}).
copy_device_to_file(G, Src, Dest) ->
  copy_device_to_file(G, Src, Dest, []).

copy_file_to_device(G, Src, Dest, Optargs) ->
  call_port(G, {copy_file_to_device, Src, Dest, Optargs}).
copy_file_to_device(G, Src, Dest) ->
  copy_file_to_device(G, Src, Dest, []).

copy_file_to_file(G, Src, Dest, Optargs) ->
  call_port(G, {copy_file_to_file, Src, Dest, Optargs}).
copy_file_to_file(G, Src, Dest) ->
  copy_file_to_file(G, Src, Dest, []).

copy_in(G, Localpath, Remotedir) ->
  call_port(G, {copy_in, Localpath, Remotedir}).

copy_out(G, Remotepath, Localdir) ->
  call_port(G, {copy_out, Remotepath, Localdir}).

copy_size(G, Src, Dest, Size) ->
  call_port(G, {copy_size, Src, Dest, Size}).

cp(G, Src, Dest) ->
  call_port(G, {cp, Src, Dest}).

cp_a(G, Src, Dest) ->
  call_port(G, {cp_a, Src, Dest}).

cp_r(G, Src, Dest) ->
  call_port(G, {cp_r, Src, Dest}).

cpio_out(G, Directory, Cpiofile, Optargs) ->
  call_port(G, {cpio_out, Directory, Cpiofile, Optargs}).
cpio_out(G, Directory, Cpiofile) ->
  cpio_out(G, Directory, Cpiofile, []).

dd(G, Src, Dest) ->
  call_port(G, {dd, Src, Dest}).

debug(G, Subcmd, Extraargs) ->
  call_port(G, {debug, Subcmd, Extraargs}).

debug_drives(G) ->
  call_port(G, {debug_drives}).

debug_upload(G, Filename, Tmpname, Mode) ->
  call_port(G, {debug_upload, Filename, Tmpname, Mode}).

device_index(G, Device) ->
  call_port(G, {device_index, Device}).

df(G) ->
  call_port(G, {df}).

df_h(G) ->
  call_port(G, {df_h}).

disk_create(G, Filename, Format, Size, Optargs) ->
  call_port(G, {disk_create, Filename, Format, Size, Optargs}).
disk_create(G, Filename, Format, Size) ->
  disk_create(G, Filename, Format, Size, []).

disk_format(G, Filename) ->
  call_port(G, {disk_format, Filename}).

disk_has_backing_file(G, Filename) ->
  call_port(G, {disk_has_backing_file, Filename}).

disk_virtual_size(G, Filename) ->
  call_port(G, {disk_virtual_size, Filename}).

dmesg(G) ->
  call_port(G, {dmesg}).

download(G, Remotefilename, Filename) ->
  call_port(G, {download, Remotefilename, Filename}).

download_offset(G, Remotefilename, Filename, Offset, Size) ->
  call_port(G, {download_offset, Remotefilename, Filename, Offset, Size}).

drop_caches(G, Whattodrop) ->
  call_port(G, {drop_caches, Whattodrop}).

du(G, Path) ->
  call_port(G, {du, Path}).

e2fsck(G, Device, Optargs) ->
  call_port(G, {e2fsck, Device, Optargs}).
e2fsck(G, Device) ->
  e2fsck(G, Device, []).

e2fsck_f(G, Device) ->
  call_port(G, {e2fsck_f, Device}).

echo_daemon(G, Words) ->
  call_port(G, {echo_daemon, Words}).

egrep(G, Regex, Path) ->
  call_port(G, {egrep, Regex, Path}).

egrepi(G, Regex, Path) ->
  call_port(G, {egrepi, Regex, Path}).

equal(G, File1, File2) ->
  call_port(G, {equal, File1, File2}).

exists(G, Path) ->
  call_port(G, {exists, Path}).

extlinux(G, Directory) ->
  call_port(G, {extlinux, Directory}).

fallocate(G, Path, Len) ->
  call_port(G, {fallocate, Path, Len}).

fallocate64(G, Path, Len) ->
  call_port(G, {fallocate64, Path, Len}).

feature_available(G, Groups) ->
  call_port(G, {feature_available, Groups}).

fgrep(G, Pattern, Path) ->
  call_port(G, {fgrep, Pattern, Path}).

fgrepi(G, Pattern, Path) ->
  call_port(G, {fgrepi, Pattern, Path}).

file(G, Path) ->
  call_port(G, {file, Path}).

file_architecture(G, Filename) ->
  call_port(G, {file_architecture, Filename}).

filesize(G, File) ->
  call_port(G, {filesize, File}).

filesystem_available(G, Filesystem) ->
  call_port(G, {filesystem_available, Filesystem}).

fill(G, C, Len, Path) ->
  call_port(G, {fill, C, Len, Path}).

fill_dir(G, Dir, Nr) ->
  call_port(G, {fill_dir, Dir, Nr}).

fill_pattern(G, Pattern, Len, Path) ->
  call_port(G, {fill_pattern, Pattern, Len, Path}).

find(G, Directory) ->
  call_port(G, {find, Directory}).

find0(G, Directory, Files) ->
  call_port(G, {find0, Directory, Files}).

findfs_label(G, Label) ->
  call_port(G, {findfs_label, Label}).

findfs_uuid(G, Uuid) ->
  call_port(G, {findfs_uuid, Uuid}).

fsck(G, Fstype, Device) ->
  call_port(G, {fsck, Fstype, Device}).

fstrim(G, Mountpoint, Optargs) ->
  call_port(G, {fstrim, Mountpoint, Optargs}).
fstrim(G, Mountpoint) ->
  fstrim(G, Mountpoint, []).

get_append(G) ->
  call_port(G, {get_append}).

get_attach_method(G) ->
  call_port(G, {get_attach_method}).

get_autosync(G) ->
  call_port(G, {get_autosync}).

get_backend(G) ->
  call_port(G, {get_backend}).

get_backend_setting(G, Name) ->
  call_port(G, {get_backend_setting, Name}).

get_backend_settings(G) ->
  call_port(G, {get_backend_settings}).

get_cachedir(G) ->
  call_port(G, {get_cachedir}).

get_direct(G) ->
  call_port(G, {get_direct}).

get_e2attrs(G, File) ->
  call_port(G, {get_e2attrs, File}).

get_e2generation(G, File) ->
  call_port(G, {get_e2generation, File}).

get_e2label(G, Device) ->
  call_port(G, {get_e2label, Device}).

get_e2uuid(G, Device) ->
  call_port(G, {get_e2uuid, Device}).

get_hv(G) ->
  call_port(G, {get_hv}).

get_libvirt_requested_credential_challenge(G, Index) ->
  call_port(G, {get_libvirt_requested_credential_challenge, Index}).

get_libvirt_requested_credential_defresult(G, Index) ->
  call_port(G, {get_libvirt_requested_credential_defresult, Index}).

get_libvirt_requested_credential_prompt(G, Index) ->
  call_port(G, {get_libvirt_requested_credential_prompt, Index}).

get_libvirt_requested_credentials(G) ->
  call_port(G, {get_libvirt_requested_credentials}).

get_memsize(G) ->
  call_port(G, {get_memsize}).

get_network(G) ->
  call_port(G, {get_network}).

get_path(G) ->
  call_port(G, {get_path}).

get_pgroup(G) ->
  call_port(G, {get_pgroup}).

get_pid(G) ->
  call_port(G, {get_pid}).

get_program(G) ->
  call_port(G, {get_program}).

get_qemu(G) ->
  call_port(G, {get_qemu}).

get_recovery_proc(G) ->
  call_port(G, {get_recovery_proc}).

get_selinux(G) ->
  call_port(G, {get_selinux}).

get_smp(G) ->
  call_port(G, {get_smp}).

get_state(G) ->
  call_port(G, {get_state}).

get_tmpdir(G) ->
  call_port(G, {get_tmpdir}).

get_trace(G) ->
  call_port(G, {get_trace}).

get_umask(G) ->
  call_port(G, {get_umask}).

get_verbose(G) ->
  call_port(G, {get_verbose}).

getcon(G) ->
  call_port(G, {getcon}).

getxattr(G, Path, Name) ->
  call_port(G, {getxattr, Path, Name}).

getxattrs(G, Path) ->
  call_port(G, {getxattrs, Path}).

glob_expand(G, Pattern) ->
  call_port(G, {glob_expand, Pattern}).

grep(G, Regex, Path, Optargs) ->
  call_port(G, {grep, Regex, Path, Optargs}).
grep(G, Regex, Path) ->
  grep(G, Regex, Path, []).
grep_opts(G, Regex, Path, Optargs) ->
  grep(G, Regex, Path, Optargs).
grep_opts(G, Regex, Path) ->
  grep(G, Regex, Path).

grepi(G, Regex, Path) ->
  call_port(G, {grepi, Regex, Path}).

grub_install(G, Root, Device) ->
  call_port(G, {grub_install, Root, Device}).

head(G, Path) ->
  call_port(G, {head, Path}).

head_n(G, Nrlines, Path) ->
  call_port(G, {head_n, Nrlines, Path}).

hexdump(G, Path) ->
  call_port(G, {hexdump, Path}).

hivex_close(G) ->
  call_port(G, {hivex_close}).

hivex_commit(G, Filename) ->
  call_port(G, {hivex_commit, Filename}).

hivex_node_add_child(G, Parent, Name) ->
  call_port(G, {hivex_node_add_child, Parent, Name}).

hivex_node_children(G, Nodeh) ->
  call_port(G, {hivex_node_children, Nodeh}).

hivex_node_delete_child(G, Nodeh) ->
  call_port(G, {hivex_node_delete_child, Nodeh}).

hivex_node_get_child(G, Nodeh, Name) ->
  call_port(G, {hivex_node_get_child, Nodeh, Name}).

hivex_node_get_value(G, Nodeh, Key) ->
  call_port(G, {hivex_node_get_value, Nodeh, Key}).

hivex_node_name(G, Nodeh) ->
  call_port(G, {hivex_node_name, Nodeh}).

hivex_node_parent(G, Nodeh) ->
  call_port(G, {hivex_node_parent, Nodeh}).

hivex_node_set_value(G, Nodeh, Key, T, Val) ->
  call_port(G, {hivex_node_set_value, Nodeh, Key, T, Val}).

hivex_node_values(G, Nodeh) ->
  call_port(G, {hivex_node_values, Nodeh}).

hivex_open(G, Filename, Optargs) ->
  call_port(G, {hivex_open, Filename, Optargs}).
hivex_open(G, Filename) ->
  hivex_open(G, Filename, []).

hivex_root(G) ->
  call_port(G, {hivex_root}).

hivex_value_key(G, Valueh) ->
  call_port(G, {hivex_value_key, Valueh}).

hivex_value_type(G, Valueh) ->
  call_port(G, {hivex_value_type, Valueh}).

hivex_value_utf8(G, Valueh) ->
  call_port(G, {hivex_value_utf8, Valueh}).

hivex_value_value(G, Valueh) ->
  call_port(G, {hivex_value_value, Valueh}).

initrd_cat(G, Initrdpath, Filename) ->
  call_port(G, {initrd_cat, Initrdpath, Filename}).

initrd_list(G, Path) ->
  call_port(G, {initrd_list, Path}).

inotify_add_watch(G, Path, Mask) ->
  call_port(G, {inotify_add_watch, Path, Mask}).

inotify_close(G) ->
  call_port(G, {inotify_close}).

inotify_files(G) ->
  call_port(G, {inotify_files}).

inotify_init(G, Maxevents) ->
  call_port(G, {inotify_init, Maxevents}).

inotify_read(G) ->
  call_port(G, {inotify_read}).

inotify_rm_watch(G, Wd) ->
  call_port(G, {inotify_rm_watch, Wd}).

inspect_get_arch(G, Root) ->
  call_port(G, {inspect_get_arch, Root}).

inspect_get_distro(G, Root) ->
  call_port(G, {inspect_get_distro, Root}).

inspect_get_drive_mappings(G, Root) ->
  call_port(G, {inspect_get_drive_mappings, Root}).

inspect_get_filesystems(G, Root) ->
  call_port(G, {inspect_get_filesystems, Root}).

inspect_get_format(G, Root) ->
  call_port(G, {inspect_get_format, Root}).

inspect_get_hostname(G, Root) ->
  call_port(G, {inspect_get_hostname, Root}).

inspect_get_icon(G, Root, Optargs) ->
  call_port(G, {inspect_get_icon, Root, Optargs}).
inspect_get_icon(G, Root) ->
  inspect_get_icon(G, Root, []).

inspect_get_major_version(G, Root) ->
  call_port(G, {inspect_get_major_version, Root}).

inspect_get_minor_version(G, Root) ->
  call_port(G, {inspect_get_minor_version, Root}).

inspect_get_mountpoints(G, Root) ->
  call_port(G, {inspect_get_mountpoints, Root}).

inspect_get_package_format(G, Root) ->
  call_port(G, {inspect_get_package_format, Root}).

inspect_get_package_management(G, Root) ->
  call_port(G, {inspect_get_package_management, Root}).

inspect_get_product_name(G, Root) ->
  call_port(G, {inspect_get_product_name, Root}).

inspect_get_product_variant(G, Root) ->
  call_port(G, {inspect_get_product_variant, Root}).

inspect_get_roots(G) ->
  call_port(G, {inspect_get_roots}).

inspect_get_type(G, Root) ->
  call_port(G, {inspect_get_type, Root}).

inspect_get_windows_current_control_set(G, Root) ->
  call_port(G, {inspect_get_windows_current_control_set, Root}).

inspect_get_windows_systemroot(G, Root) ->
  call_port(G, {inspect_get_windows_systemroot, Root}).

inspect_is_live(G, Root) ->
  call_port(G, {inspect_is_live, Root}).

inspect_is_multipart(G, Root) ->
  call_port(G, {inspect_is_multipart, Root}).

inspect_is_netinst(G, Root) ->
  call_port(G, {inspect_is_netinst, Root}).

inspect_list_applications(G, Root) ->
  call_port(G, {inspect_list_applications, Root}).

inspect_list_applications2(G, Root) ->
  call_port(G, {inspect_list_applications2, Root}).

inspect_os(G) ->
  call_port(G, {inspect_os}).

internal_test(G, Str, Optstr, Strlist, B, Integer, Integer64, Filein, Fileout, Bufferin, Optargs) ->
  call_port(G, {internal_test, Str, Optstr, Strlist, B, Integer, Integer64, Filein, Fileout, Bufferin, Optargs}).
internal_test(G, Str, Optstr, Strlist, B, Integer, Integer64, Filein, Fileout, Bufferin) ->
  internal_test(G, Str, Optstr, Strlist, B, Integer, Integer64, Filein, Fileout, Bufferin, []).

internal_test_63_optargs(G, Optargs) ->
  call_port(G, {internal_test_63_optargs, Optargs}).
internal_test_63_optargs(G) ->
  internal_test_63_optargs(G, []).

internal_test_close_output(G) ->
  call_port(G, {internal_test_close_output}).

internal_test_only_optargs(G, Optargs) ->
  call_port(G, {internal_test_only_optargs, Optargs}).
internal_test_only_optargs(G) ->
  internal_test_only_optargs(G, []).

internal_test_rbool(G, Val) ->
  call_port(G, {internal_test_rbool, Val}).

internal_test_rboolerr(G) ->
  call_port(G, {internal_test_rboolerr}).

internal_test_rbufferout(G, Val) ->
  call_port(G, {internal_test_rbufferout, Val}).

internal_test_rbufferouterr(G) ->
  call_port(G, {internal_test_rbufferouterr}).

internal_test_rconstoptstring(G, Val) ->
  call_port(G, {internal_test_rconstoptstring, Val}).

internal_test_rconstoptstringerr(G) ->
  call_port(G, {internal_test_rconstoptstringerr}).

internal_test_rconststring(G, Val) ->
  call_port(G, {internal_test_rconststring, Val}).

internal_test_rconststringerr(G) ->
  call_port(G, {internal_test_rconststringerr}).

internal_test_rhashtable(G, Val) ->
  call_port(G, {internal_test_rhashtable, Val}).

internal_test_rhashtableerr(G) ->
  call_port(G, {internal_test_rhashtableerr}).

internal_test_rint(G, Val) ->
  call_port(G, {internal_test_rint, Val}).

internal_test_rint64(G, Val) ->
  call_port(G, {internal_test_rint64, Val}).

internal_test_rint64err(G) ->
  call_port(G, {internal_test_rint64err}).

internal_test_rinterr(G) ->
  call_port(G, {internal_test_rinterr}).

internal_test_rstring(G, Val) ->
  call_port(G, {internal_test_rstring, Val}).

internal_test_rstringerr(G) ->
  call_port(G, {internal_test_rstringerr}).

internal_test_rstringlist(G, Val) ->
  call_port(G, {internal_test_rstringlist, Val}).

internal_test_rstringlisterr(G) ->
  call_port(G, {internal_test_rstringlisterr}).

internal_test_rstruct(G, Val) ->
  call_port(G, {internal_test_rstruct, Val}).

internal_test_rstructerr(G) ->
  call_port(G, {internal_test_rstructerr}).

internal_test_rstructlist(G, Val) ->
  call_port(G, {internal_test_rstructlist, Val}).

internal_test_rstructlisterr(G) ->
  call_port(G, {internal_test_rstructlisterr}).

internal_test_set_output(G, Filename) ->
  call_port(G, {internal_test_set_output, Filename}).

is_blockdev(G, Path, Optargs) ->
  call_port(G, {is_blockdev, Path, Optargs}).
is_blockdev(G, Path) ->
  is_blockdev(G, Path, []).
is_blockdev_opts(G, Path, Optargs) ->
  is_blockdev(G, Path, Optargs).
is_blockdev_opts(G, Path) ->
  is_blockdev(G, Path).

is_busy(G) ->
  call_port(G, {is_busy}).

is_chardev(G, Path, Optargs) ->
  call_port(G, {is_chardev, Path, Optargs}).
is_chardev(G, Path) ->
  is_chardev(G, Path, []).
is_chardev_opts(G, Path, Optargs) ->
  is_chardev(G, Path, Optargs).
is_chardev_opts(G, Path) ->
  is_chardev(G, Path).

is_config(G) ->
  call_port(G, {is_config}).

is_dir(G, Path, Optargs) ->
  call_port(G, {is_dir, Path, Optargs}).
is_dir(G, Path) ->
  is_dir(G, Path, []).
is_dir_opts(G, Path, Optargs) ->
  is_dir(G, Path, Optargs).
is_dir_opts(G, Path) ->
  is_dir(G, Path).

is_fifo(G, Path, Optargs) ->
  call_port(G, {is_fifo, Path, Optargs}).
is_fifo(G, Path) ->
  is_fifo(G, Path, []).
is_fifo_opts(G, Path, Optargs) ->
  is_fifo(G, Path, Optargs).
is_fifo_opts(G, Path) ->
  is_fifo(G, Path).

is_file(G, Path, Optargs) ->
  call_port(G, {is_file, Path, Optargs}).
is_file(G, Path) ->
  is_file(G, Path, []).
is_file_opts(G, Path, Optargs) ->
  is_file(G, Path, Optargs).
is_file_opts(G, Path) ->
  is_file(G, Path).

is_launching(G) ->
  call_port(G, {is_launching}).

is_lv(G, Device) ->
  call_port(G, {is_lv, Device}).

is_ready(G) ->
  call_port(G, {is_ready}).

is_socket(G, Path, Optargs) ->
  call_port(G, {is_socket, Path, Optargs}).
is_socket(G, Path) ->
  is_socket(G, Path, []).
is_socket_opts(G, Path, Optargs) ->
  is_socket(G, Path, Optargs).
is_socket_opts(G, Path) ->
  is_socket(G, Path).

is_symlink(G, Path) ->
  call_port(G, {is_symlink, Path}).

is_whole_device(G, Device) ->
  call_port(G, {is_whole_device, Device}).

is_zero(G, Path) ->
  call_port(G, {is_zero, Path}).

is_zero_device(G, Device) ->
  call_port(G, {is_zero_device, Device}).

isoinfo(G, Isofile) ->
  call_port(G, {isoinfo, Isofile}).

isoinfo_device(G, Device) ->
  call_port(G, {isoinfo_device, Device}).

journal_close(G) ->
  call_port(G, {journal_close}).

journal_get(G) ->
  call_port(G, {journal_get}).

journal_get_data_threshold(G) ->
  call_port(G, {journal_get_data_threshold}).

journal_get_realtime_usec(G) ->
  call_port(G, {journal_get_realtime_usec}).

journal_next(G) ->
  call_port(G, {journal_next}).

journal_open(G, Directory) ->
  call_port(G, {journal_open, Directory}).

journal_set_data_threshold(G, Threshold) ->
  call_port(G, {journal_set_data_threshold, Threshold}).

journal_skip(G, Skip) ->
  call_port(G, {journal_skip, Skip}).

kill_subprocess(G) ->
  call_port(G, {kill_subprocess}).

launch(G) ->
  call_port(G, {launch}).

lchown(G, Owner, Group, Path) ->
  call_port(G, {lchown, Owner, Group, Path}).

ldmtool_create_all(G) ->
  call_port(G, {ldmtool_create_all}).

ldmtool_diskgroup_disks(G, Diskgroup) ->
  call_port(G, {ldmtool_diskgroup_disks, Diskgroup}).

ldmtool_diskgroup_name(G, Diskgroup) ->
  call_port(G, {ldmtool_diskgroup_name, Diskgroup}).

ldmtool_diskgroup_volumes(G, Diskgroup) ->
  call_port(G, {ldmtool_diskgroup_volumes, Diskgroup}).

ldmtool_remove_all(G) ->
  call_port(G, {ldmtool_remove_all}).

ldmtool_scan(G) ->
  call_port(G, {ldmtool_scan}).

ldmtool_scan_devices(G, Devices) ->
  call_port(G, {ldmtool_scan_devices, Devices}).

ldmtool_volume_hint(G, Diskgroup, Volume) ->
  call_port(G, {ldmtool_volume_hint, Diskgroup, Volume}).

ldmtool_volume_partitions(G, Diskgroup, Volume) ->
  call_port(G, {ldmtool_volume_partitions, Diskgroup, Volume}).

ldmtool_volume_type(G, Diskgroup, Volume) ->
  call_port(G, {ldmtool_volume_type, Diskgroup, Volume}).

lgetxattr(G, Path, Name) ->
  call_port(G, {lgetxattr, Path, Name}).

lgetxattrs(G, Path) ->
  call_port(G, {lgetxattrs, Path}).

list_9p(G) ->
  call_port(G, {list_9p}).

list_devices(G) ->
  call_port(G, {list_devices}).

list_disk_labels(G) ->
  call_port(G, {list_disk_labels}).

list_dm_devices(G) ->
  call_port(G, {list_dm_devices}).

list_filesystems(G) ->
  call_port(G, {list_filesystems}).

list_ldm_partitions(G) ->
  call_port(G, {list_ldm_partitions}).

list_ldm_volumes(G) ->
  call_port(G, {list_ldm_volumes}).

list_md_devices(G) ->
  call_port(G, {list_md_devices}).

list_partitions(G) ->
  call_port(G, {list_partitions}).

ll(G, Directory) ->
  call_port(G, {ll, Directory}).

llz(G, Directory) ->
  call_port(G, {llz, Directory}).

ln(G, Target, Linkname) ->
  call_port(G, {ln, Target, Linkname}).

ln_f(G, Target, Linkname) ->
  call_port(G, {ln_f, Target, Linkname}).

ln_s(G, Target, Linkname) ->
  call_port(G, {ln_s, Target, Linkname}).

ln_sf(G, Target, Linkname) ->
  call_port(G, {ln_sf, Target, Linkname}).

lremovexattr(G, Xattr, Path) ->
  call_port(G, {lremovexattr, Xattr, Path}).

ls(G, Directory) ->
  call_port(G, {ls, Directory}).

ls0(G, Dir, Filenames) ->
  call_port(G, {ls0, Dir, Filenames}).

lsetxattr(G, Xattr, Val, Vallen, Path) ->
  call_port(G, {lsetxattr, Xattr, Val, Vallen, Path}).

lstat(G, Path) ->
  call_port(G, {lstat, Path}).

lstatlist(G, Path, Names) ->
  call_port(G, {lstatlist, Path, Names}).

lstatns(G, Path) ->
  call_port(G, {lstatns, Path}).

lstatnslist(G, Path, Names) ->
  call_port(G, {lstatnslist, Path, Names}).

luks_add_key(G, Device, Key, Newkey, Keyslot) ->
  call_port(G, {luks_add_key, Device, Key, Newkey, Keyslot}).

luks_close(G, Device) ->
  call_port(G, {luks_close, Device}).

luks_format(G, Device, Key, Keyslot) ->
  call_port(G, {luks_format, Device, Key, Keyslot}).

luks_format_cipher(G, Device, Key, Keyslot, Cipher) ->
  call_port(G, {luks_format_cipher, Device, Key, Keyslot, Cipher}).

luks_kill_slot(G, Device, Key, Keyslot) ->
  call_port(G, {luks_kill_slot, Device, Key, Keyslot}).

luks_open(G, Device, Key, Mapname) ->
  call_port(G, {luks_open, Device, Key, Mapname}).

luks_open_ro(G, Device, Key, Mapname) ->
  call_port(G, {luks_open_ro, Device, Key, Mapname}).

lvcreate(G, Logvol, Volgroup, Mbytes) ->
  call_port(G, {lvcreate, Logvol, Volgroup, Mbytes}).

lvcreate_free(G, Logvol, Volgroup, Percent) ->
  call_port(G, {lvcreate_free, Logvol, Volgroup, Percent}).

lvm_canonical_lv_name(G, Lvname) ->
  call_port(G, {lvm_canonical_lv_name, Lvname}).

lvm_clear_filter(G) ->
  call_port(G, {lvm_clear_filter}).

lvm_remove_all(G) ->
  call_port(G, {lvm_remove_all}).

lvm_set_filter(G, Devices) ->
  call_port(G, {lvm_set_filter, Devices}).

lvremove(G, Device) ->
  call_port(G, {lvremove, Device}).

lvrename(G, Logvol, Newlogvol) ->
  call_port(G, {lvrename, Logvol, Newlogvol}).

lvresize(G, Device, Mbytes) ->
  call_port(G, {lvresize, Device, Mbytes}).

lvresize_free(G, Lv, Percent) ->
  call_port(G, {lvresize_free, Lv, Percent}).

lvs(G) ->
  call_port(G, {lvs}).

lvs_full(G) ->
  call_port(G, {lvs_full}).

lvuuid(G, Device) ->
  call_port(G, {lvuuid, Device}).

lxattrlist(G, Path, Names) ->
  call_port(G, {lxattrlist, Path, Names}).

max_disks(G) ->
  call_port(G, {max_disks}).

md_create(G, Name, Devices, Optargs) ->
  call_port(G, {md_create, Name, Devices, Optargs}).
md_create(G, Name, Devices) ->
  md_create(G, Name, Devices, []).

md_detail(G, Md) ->
  call_port(G, {md_detail, Md}).

md_stat(G, Md) ->
  call_port(G, {md_stat, Md}).

md_stop(G, Md) ->
  call_port(G, {md_stop, Md}).

mkdir(G, Path) ->
  call_port(G, {mkdir, Path}).

mkdir_mode(G, Path, Mode) ->
  call_port(G, {mkdir_mode, Path, Mode}).

mkdir_p(G, Path) ->
  call_port(G, {mkdir_p, Path}).

mkdtemp(G, Tmpl) ->
  call_port(G, {mkdtemp, Tmpl}).

mke2fs(G, Device, Optargs) ->
  call_port(G, {mke2fs, Device, Optargs}).
mke2fs(G, Device) ->
  mke2fs(G, Device, []).

mke2fs_J(G, Fstype, Blocksize, Device, Journal) ->
  call_port(G, {mke2fs_J, Fstype, Blocksize, Device, Journal}).

mke2fs_JL(G, Fstype, Blocksize, Device, Label) ->
  call_port(G, {mke2fs_JL, Fstype, Blocksize, Device, Label}).

mke2fs_JU(G, Fstype, Blocksize, Device, Uuid) ->
  call_port(G, {mke2fs_JU, Fstype, Blocksize, Device, Uuid}).

mke2journal(G, Blocksize, Device) ->
  call_port(G, {mke2journal, Blocksize, Device}).

mke2journal_L(G, Blocksize, Label, Device) ->
  call_port(G, {mke2journal_L, Blocksize, Label, Device}).

mke2journal_U(G, Blocksize, Uuid, Device) ->
  call_port(G, {mke2journal_U, Blocksize, Uuid, Device}).

mkfifo(G, Mode, Path) ->
  call_port(G, {mkfifo, Mode, Path}).

mkfs(G, Fstype, Device, Optargs) ->
  call_port(G, {mkfs, Fstype, Device, Optargs}).
mkfs(G, Fstype, Device) ->
  mkfs(G, Fstype, Device, []).
mkfs_opts(G, Fstype, Device, Optargs) ->
  mkfs(G, Fstype, Device, Optargs).
mkfs_opts(G, Fstype, Device) ->
  mkfs(G, Fstype, Device).

mkfs_b(G, Fstype, Blocksize, Device) ->
  call_port(G, {mkfs_b, Fstype, Blocksize, Device}).

mkfs_btrfs(G, Devices, Optargs) ->
  call_port(G, {mkfs_btrfs, Devices, Optargs}).
mkfs_btrfs(G, Devices) ->
  mkfs_btrfs(G, Devices, []).

mklost_and_found(G, Mountpoint) ->
  call_port(G, {mklost_and_found, Mountpoint}).

mkmountpoint(G, Exemptpath) ->
  call_port(G, {mkmountpoint, Exemptpath}).

mknod(G, Mode, Devmajor, Devminor, Path) ->
  call_port(G, {mknod, Mode, Devmajor, Devminor, Path}).

mknod_b(G, Mode, Devmajor, Devminor, Path) ->
  call_port(G, {mknod_b, Mode, Devmajor, Devminor, Path}).

mknod_c(G, Mode, Devmajor, Devminor, Path) ->
  call_port(G, {mknod_c, Mode, Devmajor, Devminor, Path}).

mkswap(G, Device, Optargs) ->
  call_port(G, {mkswap, Device, Optargs}).
mkswap(G, Device) ->
  mkswap(G, Device, []).
mkswap_opts(G, Device, Optargs) ->
  mkswap(G, Device, Optargs).
mkswap_opts(G, Device) ->
  mkswap(G, Device).

mkswap_L(G, Label, Device) ->
  call_port(G, {mkswap_L, Label, Device}).

mkswap_U(G, Uuid, Device) ->
  call_port(G, {mkswap_U, Uuid, Device}).

mkswap_file(G, Path) ->
  call_port(G, {mkswap_file, Path}).

mktemp(G, Tmpl, Optargs) ->
  call_port(G, {mktemp, Tmpl, Optargs}).
mktemp(G, Tmpl) ->
  mktemp(G, Tmpl, []).

modprobe(G, Modulename) ->
  call_port(G, {modprobe, Modulename}).

mount(G, Mountable, Mountpoint) ->
  call_port(G, {mount, Mountable, Mountpoint}).

mount_9p(G, Mounttag, Mountpoint, Optargs) ->
  call_port(G, {mount_9p, Mounttag, Mountpoint, Optargs}).
mount_9p(G, Mounttag, Mountpoint) ->
  mount_9p(G, Mounttag, Mountpoint, []).

mount_local(G, Localmountpoint, Optargs) ->
  call_port(G, {mount_local, Localmountpoint, Optargs}).
mount_local(G, Localmountpoint) ->
  mount_local(G, Localmountpoint, []).

mount_local_run(G) ->
  call_port(G, {mount_local_run}).

mount_loop(G, File, Mountpoint) ->
  call_port(G, {mount_loop, File, Mountpoint}).

mount_options(G, Options, Mountable, Mountpoint) ->
  call_port(G, {mount_options, Options, Mountable, Mountpoint}).

mount_ro(G, Mountable, Mountpoint) ->
  call_port(G, {mount_ro, Mountable, Mountpoint}).

mount_vfs(G, Options, Vfstype, Mountable, Mountpoint) ->
  call_port(G, {mount_vfs, Options, Vfstype, Mountable, Mountpoint}).

mountpoints(G) ->
  call_port(G, {mountpoints}).

mounts(G) ->
  call_port(G, {mounts}).

mv(G, Src, Dest) ->
  call_port(G, {mv, Src, Dest}).

nr_devices(G) ->
  call_port(G, {nr_devices}).

ntfs_3g_probe(G, Rw, Device) ->
  call_port(G, {ntfs_3g_probe, Rw, Device}).

ntfsclone_in(G, Backupfile, Device) ->
  call_port(G, {ntfsclone_in, Backupfile, Device}).

ntfsclone_out(G, Device, Backupfile, Optargs) ->
  call_port(G, {ntfsclone_out, Device, Backupfile, Optargs}).
ntfsclone_out(G, Device, Backupfile) ->
  ntfsclone_out(G, Device, Backupfile, []).

ntfsfix(G, Device, Optargs) ->
  call_port(G, {ntfsfix, Device, Optargs}).
ntfsfix(G, Device) ->
  ntfsfix(G, Device, []).

ntfsresize(G, Device, Optargs) ->
  call_port(G, {ntfsresize, Device, Optargs}).
ntfsresize(G, Device) ->
  ntfsresize(G, Device, []).
ntfsresize_opts(G, Device, Optargs) ->
  ntfsresize(G, Device, Optargs).
ntfsresize_opts(G, Device) ->
  ntfsresize(G, Device).

ntfsresize_size(G, Device, Size) ->
  call_port(G, {ntfsresize_size, Device, Size}).

parse_environment(G) ->
  call_port(G, {parse_environment}).

parse_environment_list(G, Environment) ->
  call_port(G, {parse_environment_list, Environment}).

part_add(G, Device, Prlogex, Startsect, Endsect) ->
  call_port(G, {part_add, Device, Prlogex, Startsect, Endsect}).

part_del(G, Device, Partnum) ->
  call_port(G, {part_del, Device, Partnum}).

part_disk(G, Device, Parttype) ->
  call_port(G, {part_disk, Device, Parttype}).

part_get_bootable(G, Device, Partnum) ->
  call_port(G, {part_get_bootable, Device, Partnum}).

part_get_gpt_guid(G, Device, Partnum) ->
  call_port(G, {part_get_gpt_guid, Device, Partnum}).

part_get_gpt_type(G, Device, Partnum) ->
  call_port(G, {part_get_gpt_type, Device, Partnum}).

part_get_mbr_id(G, Device, Partnum) ->
  call_port(G, {part_get_mbr_id, Device, Partnum}).

part_get_mbr_part_type(G, Device, Partnum) ->
  call_port(G, {part_get_mbr_part_type, Device, Partnum}).

part_get_name(G, Device, Partnum) ->
  call_port(G, {part_get_name, Device, Partnum}).

part_get_parttype(G, Device) ->
  call_port(G, {part_get_parttype, Device}).

part_init(G, Device, Parttype) ->
  call_port(G, {part_init, Device, Parttype}).

part_list(G, Device) ->
  call_port(G, {part_list, Device}).

part_set_bootable(G, Device, Partnum, Bootable) ->
  call_port(G, {part_set_bootable, Device, Partnum, Bootable}).

part_set_gpt_guid(G, Device, Partnum, Guid) ->
  call_port(G, {part_set_gpt_guid, Device, Partnum, Guid}).

part_set_gpt_type(G, Device, Partnum, Guid) ->
  call_port(G, {part_set_gpt_type, Device, Partnum, Guid}).

part_set_mbr_id(G, Device, Partnum, Idbyte) ->
  call_port(G, {part_set_mbr_id, Device, Partnum, Idbyte}).

part_set_name(G, Device, Partnum, Name) ->
  call_port(G, {part_set_name, Device, Partnum, Name}).

part_to_dev(G, Partition) ->
  call_port(G, {part_to_dev, Partition}).

part_to_partnum(G, Partition) ->
  call_port(G, {part_to_partnum, Partition}).

ping_daemon(G) ->
  call_port(G, {ping_daemon}).

pread(G, Path, Count, Offset) ->
  call_port(G, {pread, Path, Count, Offset}).

pread_device(G, Device, Count, Offset) ->
  call_port(G, {pread_device, Device, Count, Offset}).

pvchange_uuid(G, Device) ->
  call_port(G, {pvchange_uuid, Device}).

pvchange_uuid_all(G) ->
  call_port(G, {pvchange_uuid_all}).

pvcreate(G, Device) ->
  call_port(G, {pvcreate, Device}).

pvremove(G, Device) ->
  call_port(G, {pvremove, Device}).

pvresize(G, Device) ->
  call_port(G, {pvresize, Device}).

pvresize_size(G, Device, Size) ->
  call_port(G, {pvresize_size, Device, Size}).

pvs(G) ->
  call_port(G, {pvs}).

pvs_full(G) ->
  call_port(G, {pvs_full}).

pvuuid(G, Device) ->
  call_port(G, {pvuuid, Device}).

pwrite(G, Path, Content, Offset) ->
  call_port(G, {pwrite, Path, Content, Offset}).

pwrite_device(G, Device, Content, Offset) ->
  call_port(G, {pwrite_device, Device, Content, Offset}).

read_file(G, Path) ->
  call_port(G, {read_file, Path}).

read_lines(G, Path) ->
  call_port(G, {read_lines, Path}).

readdir(G, Dir) ->
  call_port(G, {readdir, Dir}).

readlink(G, Path) ->
  call_port(G, {readlink, Path}).

readlinklist(G, Path, Names) ->
  call_port(G, {readlinklist, Path, Names}).

realpath(G, Path) ->
  call_port(G, {realpath, Path}).

remount(G, Mountpoint, Optargs) ->
  call_port(G, {remount, Mountpoint, Optargs}).
remount(G, Mountpoint) ->
  remount(G, Mountpoint, []).

remove_drive(G, Label) ->
  call_port(G, {remove_drive, Label}).

removexattr(G, Xattr, Path) ->
  call_port(G, {removexattr, Xattr, Path}).

rename(G, Oldpath, Newpath) ->
  call_port(G, {rename, Oldpath, Newpath}).

resize2fs(G, Device) ->
  call_port(G, {resize2fs, Device}).

resize2fs_M(G, Device) ->
  call_port(G, {resize2fs_M, Device}).

resize2fs_size(G, Device, Size) ->
  call_port(G, {resize2fs_size, Device, Size}).

rm(G, Path) ->
  call_port(G, {rm, Path}).

rm_f(G, Path) ->
  call_port(G, {rm_f, Path}).

rm_rf(G, Path) ->
  call_port(G, {rm_rf, Path}).

rmdir(G, Path) ->
  call_port(G, {rmdir, Path}).

rmmountpoint(G, Exemptpath) ->
  call_port(G, {rmmountpoint, Exemptpath}).

rsync(G, Src, Dest, Optargs) ->
  call_port(G, {rsync, Src, Dest, Optargs}).
rsync(G, Src, Dest) ->
  rsync(G, Src, Dest, []).

rsync_in(G, Remote, Dest, Optargs) ->
  call_port(G, {rsync_in, Remote, Dest, Optargs}).
rsync_in(G, Remote, Dest) ->
  rsync_in(G, Remote, Dest, []).

rsync_out(G, Src, Remote, Optargs) ->
  call_port(G, {rsync_out, Src, Remote, Optargs}).
rsync_out(G, Src, Remote) ->
  rsync_out(G, Src, Remote, []).

scrub_device(G, Device) ->
  call_port(G, {scrub_device, Device}).

scrub_file(G, File) ->
  call_port(G, {scrub_file, File}).

scrub_freespace(G, Dir) ->
  call_port(G, {scrub_freespace, Dir}).

set_append(G, Append) ->
  call_port(G, {set_append, Append}).

set_attach_method(G, Backend) ->
  call_port(G, {set_attach_method, Backend}).

set_autosync(G, Autosync) ->
  call_port(G, {set_autosync, Autosync}).

set_backend(G, Backend) ->
  call_port(G, {set_backend, Backend}).

set_backend_setting(G, Name, Val) ->
  call_port(G, {set_backend_setting, Name, Val}).

set_backend_settings(G, Settings) ->
  call_port(G, {set_backend_settings, Settings}).

set_cachedir(G, Cachedir) ->
  call_port(G, {set_cachedir, Cachedir}).

set_direct(G, Direct) ->
  call_port(G, {set_direct, Direct}).

set_e2attrs(G, File, Attrs, Optargs) ->
  call_port(G, {set_e2attrs, File, Attrs, Optargs}).
set_e2attrs(G, File, Attrs) ->
  set_e2attrs(G, File, Attrs, []).

set_e2generation(G, File, Generation) ->
  call_port(G, {set_e2generation, File, Generation}).

set_e2label(G, Device, Label) ->
  call_port(G, {set_e2label, Device, Label}).

set_e2uuid(G, Device, Uuid) ->
  call_port(G, {set_e2uuid, Device, Uuid}).

set_hv(G, Hv) ->
  call_port(G, {set_hv, Hv}).

set_label(G, Mountable, Label) ->
  call_port(G, {set_label, Mountable, Label}).

set_libvirt_requested_credential(G, Index, Cred) ->
  call_port(G, {set_libvirt_requested_credential, Index, Cred}).

set_libvirt_supported_credentials(G, Creds) ->
  call_port(G, {set_libvirt_supported_credentials, Creds}).

set_memsize(G, Memsize) ->
  call_port(G, {set_memsize, Memsize}).

set_network(G, Network) ->
  call_port(G, {set_network, Network}).

set_path(G, Searchpath) ->
  call_port(G, {set_path, Searchpath}).

set_pgroup(G, Pgroup) ->
  call_port(G, {set_pgroup, Pgroup}).

set_program(G, Program) ->
  call_port(G, {set_program, Program}).

set_qemu(G, Hv) ->
  call_port(G, {set_qemu, Hv}).

set_recovery_proc(G, Recoveryproc) ->
  call_port(G, {set_recovery_proc, Recoveryproc}).

set_selinux(G, Selinux) ->
  call_port(G, {set_selinux, Selinux}).

set_smp(G, Smp) ->
  call_port(G, {set_smp, Smp}).

set_tmpdir(G, Tmpdir) ->
  call_port(G, {set_tmpdir, Tmpdir}).

set_trace(G, Trace) ->
  call_port(G, {set_trace, Trace}).

set_uuid(G, Device, Uuid) ->
  call_port(G, {set_uuid, Device, Uuid}).

set_verbose(G, Verbose) ->
  call_port(G, {set_verbose, Verbose}).

setcon(G, Context) ->
  call_port(G, {setcon, Context}).

setxattr(G, Xattr, Val, Vallen, Path) ->
  call_port(G, {setxattr, Xattr, Val, Vallen, Path}).

sfdisk(G, Device, Cyls, Heads, Sectors, Lines) ->
  call_port(G, {sfdisk, Device, Cyls, Heads, Sectors, Lines}).

sfdiskM(G, Device, Lines) ->
  call_port(G, {sfdiskM, Device, Lines}).

sfdisk_N(G, Device, Partnum, Cyls, Heads, Sectors, Line) ->
  call_port(G, {sfdisk_N, Device, Partnum, Cyls, Heads, Sectors, Line}).

sfdisk_disk_geometry(G, Device) ->
  call_port(G, {sfdisk_disk_geometry, Device}).

sfdisk_kernel_geometry(G, Device) ->
  call_port(G, {sfdisk_kernel_geometry, Device}).

sfdisk_l(G, Device) ->
  call_port(G, {sfdisk_l, Device}).

sh(G, Command) ->
  call_port(G, {sh, Command}).

sh_lines(G, Command) ->
  call_port(G, {sh_lines, Command}).

shutdown(G) ->
  call_port(G, {shutdown}).

sleep(G, Secs) ->
  call_port(G, {sleep, Secs}).

stat(G, Path) ->
  call_port(G, {stat, Path}).

statns(G, Path) ->
  call_port(G, {statns, Path}).

statvfs(G, Path) ->
  call_port(G, {statvfs, Path}).

strings(G, Path) ->
  call_port(G, {strings, Path}).

strings_e(G, Encoding, Path) ->
  call_port(G, {strings_e, Encoding, Path}).

swapoff_device(G, Device) ->
  call_port(G, {swapoff_device, Device}).

swapoff_file(G, File) ->
  call_port(G, {swapoff_file, File}).

swapoff_label(G, Label) ->
  call_port(G, {swapoff_label, Label}).

swapoff_uuid(G, Uuid) ->
  call_port(G, {swapoff_uuid, Uuid}).

swapon_device(G, Device) ->
  call_port(G, {swapon_device, Device}).

swapon_file(G, File) ->
  call_port(G, {swapon_file, File}).

swapon_label(G, Label) ->
  call_port(G, {swapon_label, Label}).

swapon_uuid(G, Uuid) ->
  call_port(G, {swapon_uuid, Uuid}).

sync(G) ->
  call_port(G, {sync}).

syslinux(G, Device, Optargs) ->
  call_port(G, {syslinux, Device, Optargs}).
syslinux(G, Device) ->
  syslinux(G, Device, []).

tail(G, Path) ->
  call_port(G, {tail, Path}).

tail_n(G, Nrlines, Path) ->
  call_port(G, {tail_n, Nrlines, Path}).

tar_in(G, Tarfile, Directory, Optargs) ->
  call_port(G, {tar_in, Tarfile, Directory, Optargs}).
tar_in(G, Tarfile, Directory) ->
  tar_in(G, Tarfile, Directory, []).
tar_in_opts(G, Tarfile, Directory, Optargs) ->
  tar_in(G, Tarfile, Directory, Optargs).
tar_in_opts(G, Tarfile, Directory) ->
  tar_in(G, Tarfile, Directory).

tar_out(G, Directory, Tarfile, Optargs) ->
  call_port(G, {tar_out, Directory, Tarfile, Optargs}).
tar_out(G, Directory, Tarfile) ->
  tar_out(G, Directory, Tarfile, []).
tar_out_opts(G, Directory, Tarfile, Optargs) ->
  tar_out(G, Directory, Tarfile, Optargs).
tar_out_opts(G, Directory, Tarfile) ->
  tar_out(G, Directory, Tarfile).

tgz_in(G, Tarball, Directory) ->
  call_port(G, {tgz_in, Tarball, Directory}).

tgz_out(G, Directory, Tarball) ->
  call_port(G, {tgz_out, Directory, Tarball}).

touch(G, Path) ->
  call_port(G, {touch, Path}).

truncate(G, Path) ->
  call_port(G, {truncate, Path}).

truncate_size(G, Path, Size) ->
  call_port(G, {truncate_size, Path, Size}).

tune2fs(G, Device, Optargs) ->
  call_port(G, {tune2fs, Device, Optargs}).
tune2fs(G, Device) ->
  tune2fs(G, Device, []).

tune2fs_l(G, Device) ->
  call_port(G, {tune2fs_l, Device}).

txz_in(G, Tarball, Directory) ->
  call_port(G, {txz_in, Tarball, Directory}).

txz_out(G, Directory, Tarball) ->
  call_port(G, {txz_out, Directory, Tarball}).

umask(G, Mask) ->
  call_port(G, {umask, Mask}).

umount(G, Pathordevice, Optargs) ->
  call_port(G, {umount, Pathordevice, Optargs}).
umount(G, Pathordevice) ->
  umount(G, Pathordevice, []).
umount_opts(G, Pathordevice, Optargs) ->
  umount(G, Pathordevice, Optargs).
umount_opts(G, Pathordevice) ->
  umount(G, Pathordevice).

umount_all(G) ->
  call_port(G, {umount_all}).

umount_local(G, Optargs) ->
  call_port(G, {umount_local, Optargs}).
umount_local(G) ->
  umount_local(G, []).

upload(G, Filename, Remotefilename) ->
  call_port(G, {upload, Filename, Remotefilename}).

upload_offset(G, Filename, Remotefilename, Offset) ->
  call_port(G, {upload_offset, Filename, Remotefilename, Offset}).

user_cancel(G) ->
  call_port(G, {user_cancel}).

utimens(G, Path, Atsecs, Atnsecs, Mtsecs, Mtnsecs) ->
  call_port(G, {utimens, Path, Atsecs, Atnsecs, Mtsecs, Mtnsecs}).

utsname(G) ->
  call_port(G, {utsname}).

version(G) ->
  call_port(G, {version}).

vfs_label(G, Mountable) ->
  call_port(G, {vfs_label, Mountable}).

vfs_type(G, Mountable) ->
  call_port(G, {vfs_type, Mountable}).

vfs_uuid(G, Mountable) ->
  call_port(G, {vfs_uuid, Mountable}).

vg_activate(G, Activate, Volgroups) ->
  call_port(G, {vg_activate, Activate, Volgroups}).

vg_activate_all(G, Activate) ->
  call_port(G, {vg_activate_all, Activate}).

vgchange_uuid(G, Vg) ->
  call_port(G, {vgchange_uuid, Vg}).

vgchange_uuid_all(G) ->
  call_port(G, {vgchange_uuid_all}).

vgcreate(G, Volgroup, Physvols) ->
  call_port(G, {vgcreate, Volgroup, Physvols}).

vglvuuids(G, Vgname) ->
  call_port(G, {vglvuuids, Vgname}).

vgmeta(G, Vgname) ->
  call_port(G, {vgmeta, Vgname}).

vgpvuuids(G, Vgname) ->
  call_port(G, {vgpvuuids, Vgname}).

vgremove(G, Vgname) ->
  call_port(G, {vgremove, Vgname}).

vgrename(G, Volgroup, Newvolgroup) ->
  call_port(G, {vgrename, Volgroup, Newvolgroup}).

vgs(G) ->
  call_port(G, {vgs}).

vgs_full(G) ->
  call_port(G, {vgs_full}).

vgscan(G) ->
  call_port(G, {vgscan}).

vguuid(G, Vgname) ->
  call_port(G, {vguuid, Vgname}).

wait_ready(G) ->
  call_port(G, {wait_ready}).

wc_c(G, Path) ->
  call_port(G, {wc_c, Path}).

wc_l(G, Path) ->
  call_port(G, {wc_l, Path}).

wc_w(G, Path) ->
  call_port(G, {wc_w, Path}).

wipefs(G, Device) ->
  call_port(G, {wipefs, Device}).

write(G, Path, Content) ->
  call_port(G, {write, Path, Content}).

write_append(G, Path, Content) ->
  call_port(G, {write_append, Path, Content}).

write_file(G, Path, Content, Size) ->
  call_port(G, {write_file, Path, Content, Size}).

xfs_admin(G, Device, Optargs) ->
  call_port(G, {xfs_admin, Device, Optargs}).
xfs_admin(G, Device) ->
  xfs_admin(G, Device, []).

xfs_growfs(G, Path, Optargs) ->
  call_port(G, {xfs_growfs, Path, Optargs}).
xfs_growfs(G, Path) ->
  xfs_growfs(G, Path, []).

xfs_info(G, Pathordevice) ->
  call_port(G, {xfs_info, Pathordevice}).

xfs_repair(G, Device, Optargs) ->
  call_port(G, {xfs_repair, Device, Optargs}).
xfs_repair(G, Device) ->
  xfs_repair(G, Device, []).

zegrep(G, Regex, Path) ->
  call_port(G, {zegrep, Regex, Path}).

zegrepi(G, Regex, Path) ->
  call_port(G, {zegrepi, Regex, Path}).

zero(G, Device) ->
  call_port(G, {zero, Device}).

zero_device(G, Device) ->
  call_port(G, {zero_device, Device}).

zero_free_space(G, Directory) ->
  call_port(G, {zero_free_space, Directory}).

zerofree(G, Device) ->
  call_port(G, {zerofree, Device}).

zfgrep(G, Pattern, Path) ->
  call_port(G, {zfgrep, Pattern, Path}).

zfgrepi(G, Pattern, Path) ->
  call_port(G, {zfgrepi, Pattern, Path}).

zfile(G, Meth, Path) ->
  call_port(G, {zfile, Meth, Path}).

zgrep(G, Regex, Path) ->
  call_port(G, {zgrep, Regex, Path}).

zgrepi(G, Regex, Path) ->
  call_port(G, {zgrepi, Regex, Path}).

