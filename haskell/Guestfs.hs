{- libguestfs generated file
   WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
            generator/haskell.ml
            and from the code in the generator/ subdirectory.
   ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
  
   Copyright (C) 2009-2016 Red Hat Inc.
  
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
  
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
  
   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
-}

{-# LANGUAGE ForeignFunctionInterface #-}

module Guestfs (
  create,
  acl_delete_def_file,
  acl_get_file,
  acl_set_file,
  add_cdrom,
  add_drive_ro,
  add_drive_ro_with_if,
  add_drive_with_if,
  aug_clear,
  aug_close,
  aug_defvar,
  aug_get,
  aug_init,
  aug_insert,
  aug_label,
  aug_load,
  aug_ls,
  aug_match,
  aug_mv,
  aug_rm,
  aug_save,
  aug_set,
  aug_setm,
  available,
  available_all_groups,
  base64_in,
  base64_out,
  blkdiscard,
  blkdiscardzeroes,
  blkid,
  blockdev_flushbufs,
  blockdev_getbsz,
  blockdev_getro,
  blockdev_getsize64,
  blockdev_getss,
  blockdev_getsz,
  blockdev_rereadpt,
  blockdev_setbsz,
  blockdev_setra,
  blockdev_setro,
  blockdev_setrw,
  btrfs_balance_cancel,
  btrfs_balance_pause,
  btrfs_balance_resume,
  btrfs_device_add,
  btrfs_device_delete,
  btrfs_filesystem_balance,
  btrfs_filesystem_sync,
  btrfs_qgroup_assign,
  btrfs_qgroup_create,
  btrfs_qgroup_destroy,
  btrfs_qgroup_limit,
  btrfs_qgroup_remove,
  btrfs_quota_enable,
  btrfs_quota_rescan,
  btrfs_replace,
  btrfs_rescue_chunk_recover,
  btrfs_rescue_super_recover,
  btrfs_scrub_cancel,
  btrfs_scrub_resume,
  btrfs_scrub_start,
  btrfs_set_seeding,
  btrfs_subvolume_delete,
  btrfs_subvolume_get_default,
  btrfs_subvolume_set_default,
  btrfs_subvolume_show,
  btrfstune_enable_extended_inode_refs,
  btrfstune_enable_skinny_metadata_extent_refs,
  btrfstune_seeding,
  c_pointer,
  canonical_device_name,
  cap_get_file,
  cap_set_file,
  case_sensitive_path,
  cat,
  checksum,
  checksum_device,
  checksums_out,
  chmod,
  chown,
  clear_backend_setting,
  command,
  command_lines,
  config,
  copy_in,
  copy_out,
  copy_size,
  cp,
  cp_a,
  cp_r,
  dd,
  debug,
  debug_drives,
  debug_upload,
  device_index,
  df,
  df_h,
  disk_format,
  disk_has_backing_file,
  disk_virtual_size,
  dmesg,
  download,
  download_offset,
  drop_caches,
  du,
  e2fsck_f,
  echo_daemon,
  egrep,
  egrepi,
  equal,
  exists,
  extlinux,
  fallocate,
  fallocate64,
  feature_available,
  fgrep,
  fgrepi,
  file,
  file_architecture,
  filesize,
  filesystem_available,
  fill,
  fill_dir,
  fill_pattern,
  find,
  find0,
  findfs_label,
  findfs_uuid,
  fsck,
  get_attach_method,
  get_autosync,
  get_backend,
  get_backend_setting,
  get_backend_settings,
  get_cachedir,
  get_direct,
  get_e2attrs,
  get_e2generation,
  get_e2label,
  get_e2uuid,
  get_hv,
  get_identifier,
  get_libvirt_requested_credential_challenge,
  get_libvirt_requested_credential_defresult,
  get_libvirt_requested_credential_prompt,
  get_libvirt_requested_credentials,
  get_memsize,
  get_network,
  get_path,
  get_pgroup,
  get_pid,
  get_program,
  get_qemu,
  get_recovery_proc,
  get_selinux,
  get_smp,
  get_state,
  get_tmpdir,
  get_trace,
  get_umask,
  get_verbose,
  getcon,
  glob_expand,
  grepi,
  grub_install,
  head,
  head_n,
  hexdump,
  hivex_close,
  hivex_commit,
  hivex_node_add_child,
  hivex_node_delete_child,
  hivex_node_get_child,
  hivex_node_get_value,
  hivex_node_name,
  hivex_node_parent,
  hivex_node_set_value,
  hivex_root,
  hivex_value_key,
  hivex_value_type,
  hivex_value_utf8,
  initrd_list,
  inotify_add_watch,
  inotify_close,
  inotify_files,
  inotify_init,
  inotify_rm_watch,
  inspect_get_arch,
  inspect_get_distro,
  inspect_get_drive_mappings,
  inspect_get_filesystems,
  inspect_get_format,
  inspect_get_hostname,
  inspect_get_major_version,
  inspect_get_minor_version,
  inspect_get_mountpoints,
  inspect_get_package_format,
  inspect_get_package_management,
  inspect_get_product_name,
  inspect_get_product_variant,
  inspect_get_roots,
  inspect_get_type,
  inspect_get_windows_current_control_set,
  inspect_get_windows_systemroot,
  inspect_is_live,
  inspect_is_multipart,
  inspect_is_netinst,
  inspect_os,
  internal_exit,
  internal_test_close_output,
  internal_test_rbool,
  internal_test_rboolerr,
  internal_test_rconststring,
  internal_test_rconststringerr,
  internal_test_rhashtable,
  internal_test_rhashtableerr,
  internal_test_rint,
  internal_test_rint64,
  internal_test_rint64err,
  internal_test_rinterr,
  internal_test_rstring,
  internal_test_rstringerr,
  internal_test_rstringlist,
  internal_test_rstringlisterr,
  internal_test_set_output,
  is_busy,
  is_config,
  is_launching,
  is_lv,
  is_ready,
  is_symlink,
  is_whole_device,
  is_zero,
  is_zero_device,
  journal_close,
  journal_get_data_threshold,
  journal_get_realtime_usec,
  journal_next,
  journal_open,
  journal_set_data_threshold,
  journal_skip,
  kill_subprocess,
  launch,
  lchown,
  ldmtool_create_all,
  ldmtool_diskgroup_disks,
  ldmtool_diskgroup_name,
  ldmtool_diskgroup_volumes,
  ldmtool_remove_all,
  ldmtool_scan,
  ldmtool_scan_devices,
  ldmtool_volume_hint,
  ldmtool_volume_partitions,
  ldmtool_volume_type,
  list_9p,
  list_devices,
  list_disk_labels,
  list_dm_devices,
  list_filesystems,
  list_ldm_partitions,
  list_ldm_volumes,
  list_md_devices,
  list_partitions,
  ll,
  llz,
  ln,
  ln_f,
  ln_s,
  ln_sf,
  lremovexattr,
  ls,
  ls0,
  lsetxattr,
  luks_add_key,
  luks_close,
  luks_format,
  luks_format_cipher,
  luks_kill_slot,
  luks_open,
  luks_open_ro,
  lvcreate,
  lvcreate_free,
  lvm_canonical_lv_name,
  lvm_clear_filter,
  lvm_remove_all,
  lvm_set_filter,
  lvremove,
  lvrename,
  lvresize,
  lvresize_free,
  lvs,
  lvuuid,
  max_disks,
  md_detail,
  md_stop,
  mkdir,
  mkdir_mode,
  mkdir_p,
  mkdtemp,
  mke2fs_J,
  mke2fs_JL,
  mke2fs_JU,
  mke2journal,
  mke2journal_L,
  mke2journal_U,
  mkfifo,
  mkfs_b,
  mklost_and_found,
  mkmountpoint,
  mknod,
  mknod_b,
  mknod_c,
  mkswap_L,
  mkswap_U,
  mkswap_file,
  modprobe,
  mount,
  mount_local_run,
  mount_loop,
  mount_options,
  mount_ro,
  mount_vfs,
  mountpoints,
  mounts,
  mv,
  nr_devices,
  ntfs_3g_probe,
  ntfsclone_in,
  ntfsresize_size,
  parse_environment,
  parse_environment_list,
  part_add,
  part_del,
  part_disk,
  part_get_bootable,
  part_get_gpt_guid,
  part_get_gpt_type,
  part_get_mbr_id,
  part_get_mbr_part_type,
  part_get_name,
  part_get_parttype,
  part_init,
  part_set_bootable,
  part_set_gpt_guid,
  part_set_gpt_type,
  part_set_mbr_id,
  part_set_name,
  part_to_dev,
  part_to_partnum,
  ping_daemon,
  pvchange_uuid,
  pvchange_uuid_all,
  pvcreate,
  pvremove,
  pvresize,
  pvresize_size,
  pvs,
  pvuuid,
  pwrite,
  pwrite_device,
  read_lines,
  readlink,
  readlinklist,
  realpath,
  remove_drive,
  removexattr,
  rename,
  resize2fs,
  resize2fs_M,
  resize2fs_size,
  rm,
  rm_f,
  rm_rf,
  rmdir,
  rmmountpoint,
  scrub_device,
  scrub_file,
  scrub_freespace,
  set_append,
  set_attach_method,
  set_autosync,
  set_backend,
  set_backend_setting,
  set_backend_settings,
  set_cachedir,
  set_direct,
  set_e2generation,
  set_e2label,
  set_e2uuid,
  set_hv,
  set_identifier,
  set_label,
  set_libvirt_requested_credential,
  set_libvirt_supported_credentials,
  set_memsize,
  set_network,
  set_path,
  set_pgroup,
  set_program,
  set_qemu,
  set_recovery_proc,
  set_selinux,
  set_smp,
  set_tmpdir,
  set_trace,
  set_uuid,
  set_uuid_random,
  set_verbose,
  setcon,
  setxattr,
  sfdisk,
  sfdiskM,
  sfdisk_N,
  sfdisk_disk_geometry,
  sfdisk_kernel_geometry,
  sfdisk_l,
  sh,
  sh_lines,
  shutdown,
  sleep,
  strings,
  strings_e,
  swapoff_device,
  swapoff_file,
  swapoff_label,
  swapoff_uuid,
  swapon_device,
  swapon_file,
  swapon_label,
  swapon_uuid,
  sync,
  tail,
  tail_n,
  tgz_in,
  tgz_out,
  touch,
  truncate,
  truncate_size,
  tune2fs_l,
  txz_in,
  txz_out,
  umask,
  umount_all,
  upload,
  upload_offset,
  user_cancel,
  utimens,
  vfs_label,
  vfs_minimum_size,
  vfs_type,
  vfs_uuid,
  vg_activate,
  vg_activate_all,
  vgchange_uuid,
  vgchange_uuid_all,
  vgcreate,
  vglvuuids,
  vgpvuuids,
  vgremove,
  vgrename,
  vgs,
  vgscan,
  vguuid,
  wait_ready,
  wc_c,
  wc_l,
  wc_w,
  wipefs,
  write,
  write_append,
  write_file,
  zegrep,
  zegrepi,
  zero,
  zero_device,
  zero_free_space,
  zerofree,
  zfgrep,
  zfgrepi,
  zfile,
  zgrep,
  zgrepi
  ) where

-- Unfortunately some symbols duplicate ones already present
-- in Prelude.  We don't know which, so we hard-code a list
-- here.
import Prelude hiding (head, tail, truncate)

import Foreign
import Foreign.C
import Foreign.C.Types
import System.IO
import Control.Exception
import Data.Typeable

data GuestfsS = GuestfsS            -- represents the opaque C struct
type GuestfsP = Ptr GuestfsS        -- guestfs_h *
type GuestfsH = ForeignPtr GuestfsS -- guestfs_h * with attached finalizer

foreign import ccall unsafe "guestfs.h guestfs_create" c_create
  :: IO GuestfsP
foreign import ccall unsafe "guestfs.h &guestfs_close" c_close
  :: FunPtr (GuestfsP -> IO ())
foreign import ccall unsafe "guestfs.h guestfs_set_error_handler" c_set_error_handler
  :: GuestfsP -> Ptr CInt -> Ptr CInt -> IO ()

create :: IO GuestfsH
create = do
  p <- c_create
  c_set_error_handler p nullPtr nullPtr
  h <- newForeignPtr c_close p
  return h

foreign import ccall unsafe "guestfs.h guestfs_last_error" c_last_error
  :: GuestfsP -> IO CString

-- last_error :: GuestfsH -> IO (Maybe String)
-- last_error h = do
--   str <- withForeignPtr h (\p -> c_last_error p)
--   maybePeek peekCString str

last_error :: GuestfsH -> IO String
last_error h = do
  str <- withForeignPtr h (\p -> c_last_error p)
  if (str == nullPtr)
    then return "no error"
    else peekCString str

assocListOfHashtable :: Eq a => [a] -> [(a,a)]
assocListOfHashtable [] = []
assocListOfHashtable [a] =
  fail "RHashtable returned an odd number of elements"
assocListOfHashtable (a:b:rest) = (a,b) : assocListOfHashtable rest

foreign import ccall unsafe "guestfs.h guestfs_acl_delete_def_file" c_acl_delete_def_file
  :: GuestfsP -> CString -> IO CInt

acl_delete_def_file :: GuestfsH -> String -> IO ()
acl_delete_def_file h dir = do
  r <- withCString dir $ \dir -> withForeignPtr h (\p -> c_acl_delete_def_file p dir)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_acl_get_file" c_acl_get_file
  :: GuestfsP -> CString -> CString -> IO CString

acl_get_file :: GuestfsH -> String -> String -> IO String
acl_get_file h path acltype = do
  r <- withCString path $ \path -> withCString acltype $ \acltype -> withForeignPtr h (\p -> c_acl_get_file p path acltype)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_acl_set_file" c_acl_set_file
  :: GuestfsP -> CString -> CString -> CString -> IO CInt

acl_set_file :: GuestfsH -> String -> String -> String -> IO ()
acl_set_file h path acltype acl = do
  r <- withCString path $ \path -> withCString acltype $ \acltype -> withCString acl $ \acl -> withForeignPtr h (\p -> c_acl_set_file p path acltype acl)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_add_cdrom" c_add_cdrom
  :: GuestfsP -> CString -> IO CInt

add_cdrom :: GuestfsH -> String -> IO ()
add_cdrom h filename = do
  r <- withCString filename $ \filename -> withForeignPtr h (\p -> c_add_cdrom p filename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_add_drive_ro" c_add_drive_ro
  :: GuestfsP -> CString -> IO CInt

add_drive_ro :: GuestfsH -> String -> IO ()
add_drive_ro h filename = do
  r <- withCString filename $ \filename -> withForeignPtr h (\p -> c_add_drive_ro p filename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_add_drive_ro_with_if" c_add_drive_ro_with_if
  :: GuestfsP -> CString -> CString -> IO CInt

add_drive_ro_with_if :: GuestfsH -> String -> String -> IO ()
add_drive_ro_with_if h filename iface = do
  r <- withCString filename $ \filename -> withCString iface $ \iface -> withForeignPtr h (\p -> c_add_drive_ro_with_if p filename iface)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_add_drive_with_if" c_add_drive_with_if
  :: GuestfsP -> CString -> CString -> IO CInt

add_drive_with_if :: GuestfsH -> String -> String -> IO ()
add_drive_with_if h filename iface = do
  r <- withCString filename $ \filename -> withCString iface $ \iface -> withForeignPtr h (\p -> c_add_drive_with_if p filename iface)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_aug_clear" c_aug_clear
  :: GuestfsP -> CString -> IO CInt

aug_clear :: GuestfsH -> String -> IO ()
aug_clear h augpath = do
  r <- withCString augpath $ \augpath -> withForeignPtr h (\p -> c_aug_clear p augpath)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_aug_close" c_aug_close
  :: GuestfsP -> IO CInt

aug_close :: GuestfsH -> IO ()
aug_close h = do
  r <- withForeignPtr h (\p -> c_aug_close p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_aug_defvar" c_aug_defvar
  :: GuestfsP -> CString -> CString -> IO CInt

aug_defvar :: GuestfsH -> String -> Maybe String -> IO Int
aug_defvar h name expr = do
  r <- withCString name $ \name -> maybeWith withCString expr $ \expr -> withForeignPtr h (\p -> c_aug_defvar p name expr)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_aug_get" c_aug_get
  :: GuestfsP -> CString -> IO CString

aug_get :: GuestfsH -> String -> IO String
aug_get h augpath = do
  r <- withCString augpath $ \augpath -> withForeignPtr h (\p -> c_aug_get p augpath)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_aug_init" c_aug_init
  :: GuestfsP -> CString -> CInt -> IO CInt

aug_init :: GuestfsH -> String -> Int -> IO ()
aug_init h root flags = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_aug_init p root (fromIntegral flags))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_aug_insert" c_aug_insert
  :: GuestfsP -> CString -> CString -> CInt -> IO CInt

aug_insert :: GuestfsH -> String -> String -> Bool -> IO ()
aug_insert h augpath label before = do
  r <- withCString augpath $ \augpath -> withCString label $ \label -> withForeignPtr h (\p -> c_aug_insert p augpath label (fromBool before))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_aug_label" c_aug_label
  :: GuestfsP -> CString -> IO CString

aug_label :: GuestfsH -> String -> IO String
aug_label h augpath = do
  r <- withCString augpath $ \augpath -> withForeignPtr h (\p -> c_aug_label p augpath)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_aug_load" c_aug_load
  :: GuestfsP -> IO CInt

aug_load :: GuestfsH -> IO ()
aug_load h = do
  r <- withForeignPtr h (\p -> c_aug_load p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_aug_ls" c_aug_ls
  :: GuestfsP -> CString -> IO (Ptr CString)

aug_ls :: GuestfsH -> String -> IO [String]
aug_ls h augpath = do
  r <- withCString augpath $ \augpath -> withForeignPtr h (\p -> c_aug_ls p augpath)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_aug_match" c_aug_match
  :: GuestfsP -> CString -> IO (Ptr CString)

aug_match :: GuestfsH -> String -> IO [String]
aug_match h augpath = do
  r <- withCString augpath $ \augpath -> withForeignPtr h (\p -> c_aug_match p augpath)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_aug_mv" c_aug_mv
  :: GuestfsP -> CString -> CString -> IO CInt

aug_mv :: GuestfsH -> String -> String -> IO ()
aug_mv h src dest = do
  r <- withCString src $ \src -> withCString dest $ \dest -> withForeignPtr h (\p -> c_aug_mv p src dest)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_aug_rm" c_aug_rm
  :: GuestfsP -> CString -> IO CInt

aug_rm :: GuestfsH -> String -> IO Int
aug_rm h augpath = do
  r <- withCString augpath $ \augpath -> withForeignPtr h (\p -> c_aug_rm p augpath)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_aug_save" c_aug_save
  :: GuestfsP -> IO CInt

aug_save :: GuestfsH -> IO ()
aug_save h = do
  r <- withForeignPtr h (\p -> c_aug_save p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_aug_set" c_aug_set
  :: GuestfsP -> CString -> CString -> IO CInt

aug_set :: GuestfsH -> String -> String -> IO ()
aug_set h augpath val = do
  r <- withCString augpath $ \augpath -> withCString val $ \val -> withForeignPtr h (\p -> c_aug_set p augpath val)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_aug_setm" c_aug_setm
  :: GuestfsP -> CString -> CString -> CString -> IO CInt

aug_setm :: GuestfsH -> String -> Maybe String -> String -> IO Int
aug_setm h base sub val = do
  r <- withCString base $ \base -> maybeWith withCString sub $ \sub -> withCString val $ \val -> withForeignPtr h (\p -> c_aug_setm p base sub val)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_available" c_available
  :: GuestfsP -> Ptr CString -> IO CInt

available :: GuestfsH -> [String] -> IO ()
available h groups = do
  r <- withMany withCString groups $ \groups -> withArray0 nullPtr groups $ \groups -> withForeignPtr h (\p -> c_available p groups)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_available_all_groups" c_available_all_groups
  :: GuestfsP -> IO (Ptr CString)

available_all_groups :: GuestfsH -> IO [String]
available_all_groups h = do
  r <- withForeignPtr h (\p -> c_available_all_groups p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_base64_in" c_base64_in
  :: GuestfsP -> CString -> CString -> IO CInt

base64_in :: GuestfsH -> String -> String -> IO ()
base64_in h base64file filename = do
  r <- withCString base64file $ \base64file -> withCString filename $ \filename -> withForeignPtr h (\p -> c_base64_in p base64file filename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_base64_out" c_base64_out
  :: GuestfsP -> CString -> CString -> IO CInt

base64_out :: GuestfsH -> String -> String -> IO ()
base64_out h filename base64file = do
  r <- withCString filename $ \filename -> withCString base64file $ \base64file -> withForeignPtr h (\p -> c_base64_out p filename base64file)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_blkdiscard" c_blkdiscard
  :: GuestfsP -> CString -> IO CInt

blkdiscard :: GuestfsH -> String -> IO ()
blkdiscard h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blkdiscard p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_blkdiscardzeroes" c_blkdiscardzeroes
  :: GuestfsP -> CString -> IO CInt

blkdiscardzeroes :: GuestfsH -> String -> IO Bool
blkdiscardzeroes h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blkdiscardzeroes p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_blkid" c_blkid
  :: GuestfsP -> CString -> IO (Ptr CString)

blkid :: GuestfsH -> String -> IO [(String, String)]
blkid h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blkid p device)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else do
      arr <- peekArray0 nullPtr r
      arr <- mapM peekCString arr
      return (assocListOfHashtable arr)

foreign import ccall unsafe "guestfs.h guestfs_blockdev_flushbufs" c_blockdev_flushbufs
  :: GuestfsP -> CString -> IO CInt

blockdev_flushbufs :: GuestfsH -> String -> IO ()
blockdev_flushbufs h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_flushbufs p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_blockdev_getbsz" c_blockdev_getbsz
  :: GuestfsP -> CString -> IO CInt

blockdev_getbsz :: GuestfsH -> String -> IO Int
blockdev_getbsz h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_getbsz p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_blockdev_getro" c_blockdev_getro
  :: GuestfsP -> CString -> IO CInt

blockdev_getro :: GuestfsH -> String -> IO Bool
blockdev_getro h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_getro p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_blockdev_getsize64" c_blockdev_getsize64
  :: GuestfsP -> CString -> IO Int64

blockdev_getsize64 :: GuestfsH -> String -> IO Int64
blockdev_getsize64 h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_getsize64 p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_blockdev_getss" c_blockdev_getss
  :: GuestfsP -> CString -> IO CInt

blockdev_getss :: GuestfsH -> String -> IO Int
blockdev_getss h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_getss p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_blockdev_getsz" c_blockdev_getsz
  :: GuestfsP -> CString -> IO Int64

blockdev_getsz :: GuestfsH -> String -> IO Int64
blockdev_getsz h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_getsz p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_blockdev_rereadpt" c_blockdev_rereadpt
  :: GuestfsP -> CString -> IO CInt

blockdev_rereadpt :: GuestfsH -> String -> IO ()
blockdev_rereadpt h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_rereadpt p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_blockdev_setbsz" c_blockdev_setbsz
  :: GuestfsP -> CString -> CInt -> IO CInt

blockdev_setbsz :: GuestfsH -> String -> Int -> IO ()
blockdev_setbsz h device blocksize = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_setbsz p device (fromIntegral blocksize))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_blockdev_setra" c_blockdev_setra
  :: GuestfsP -> CString -> CInt -> IO CInt

blockdev_setra :: GuestfsH -> String -> Int -> IO ()
blockdev_setra h device sectors = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_setra p device (fromIntegral sectors))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_blockdev_setro" c_blockdev_setro
  :: GuestfsP -> CString -> IO CInt

blockdev_setro :: GuestfsH -> String -> IO ()
blockdev_setro h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_setro p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_blockdev_setrw" c_blockdev_setrw
  :: GuestfsP -> CString -> IO CInt

blockdev_setrw :: GuestfsH -> String -> IO ()
blockdev_setrw h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_setrw p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_balance_cancel" c_btrfs_balance_cancel
  :: GuestfsP -> CString -> IO CInt

btrfs_balance_cancel :: GuestfsH -> String -> IO ()
btrfs_balance_cancel h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_btrfs_balance_cancel p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_balance_pause" c_btrfs_balance_pause
  :: GuestfsP -> CString -> IO CInt

btrfs_balance_pause :: GuestfsH -> String -> IO ()
btrfs_balance_pause h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_btrfs_balance_pause p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_balance_resume" c_btrfs_balance_resume
  :: GuestfsP -> CString -> IO CInt

btrfs_balance_resume :: GuestfsH -> String -> IO ()
btrfs_balance_resume h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_btrfs_balance_resume p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_device_add" c_btrfs_device_add
  :: GuestfsP -> Ptr CString -> CString -> IO CInt

btrfs_device_add :: GuestfsH -> [String] -> String -> IO ()
btrfs_device_add h devices fs = do
  r <- withMany withCString devices $ \devices -> withArray0 nullPtr devices $ \devices -> withCString fs $ \fs -> withForeignPtr h (\p -> c_btrfs_device_add p devices fs)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_device_delete" c_btrfs_device_delete
  :: GuestfsP -> Ptr CString -> CString -> IO CInt

btrfs_device_delete :: GuestfsH -> [String] -> String -> IO ()
btrfs_device_delete h devices fs = do
  r <- withMany withCString devices $ \devices -> withArray0 nullPtr devices $ \devices -> withCString fs $ \fs -> withForeignPtr h (\p -> c_btrfs_device_delete p devices fs)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_filesystem_balance" c_btrfs_filesystem_balance
  :: GuestfsP -> CString -> IO CInt

btrfs_filesystem_balance :: GuestfsH -> String -> IO ()
btrfs_filesystem_balance h fs = do
  r <- withCString fs $ \fs -> withForeignPtr h (\p -> c_btrfs_filesystem_balance p fs)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_filesystem_sync" c_btrfs_filesystem_sync
  :: GuestfsP -> CString -> IO CInt

btrfs_filesystem_sync :: GuestfsH -> String -> IO ()
btrfs_filesystem_sync h fs = do
  r <- withCString fs $ \fs -> withForeignPtr h (\p -> c_btrfs_filesystem_sync p fs)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_qgroup_assign" c_btrfs_qgroup_assign
  :: GuestfsP -> CString -> CString -> CString -> IO CInt

btrfs_qgroup_assign :: GuestfsH -> String -> String -> String -> IO ()
btrfs_qgroup_assign h src dst path = do
  r <- withCString src $ \src -> withCString dst $ \dst -> withCString path $ \path -> withForeignPtr h (\p -> c_btrfs_qgroup_assign p src dst path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_qgroup_create" c_btrfs_qgroup_create
  :: GuestfsP -> CString -> CString -> IO CInt

btrfs_qgroup_create :: GuestfsH -> String -> String -> IO ()
btrfs_qgroup_create h qgroupid subvolume = do
  r <- withCString qgroupid $ \qgroupid -> withCString subvolume $ \subvolume -> withForeignPtr h (\p -> c_btrfs_qgroup_create p qgroupid subvolume)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_qgroup_destroy" c_btrfs_qgroup_destroy
  :: GuestfsP -> CString -> CString -> IO CInt

btrfs_qgroup_destroy :: GuestfsH -> String -> String -> IO ()
btrfs_qgroup_destroy h qgroupid subvolume = do
  r <- withCString qgroupid $ \qgroupid -> withCString subvolume $ \subvolume -> withForeignPtr h (\p -> c_btrfs_qgroup_destroy p qgroupid subvolume)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_qgroup_limit" c_btrfs_qgroup_limit
  :: GuestfsP -> CString -> Int64 -> IO CInt

btrfs_qgroup_limit :: GuestfsH -> String -> Integer -> IO ()
btrfs_qgroup_limit h subvolume size = do
  r <- withCString subvolume $ \subvolume -> withForeignPtr h (\p -> c_btrfs_qgroup_limit p subvolume (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_qgroup_remove" c_btrfs_qgroup_remove
  :: GuestfsP -> CString -> CString -> CString -> IO CInt

btrfs_qgroup_remove :: GuestfsH -> String -> String -> String -> IO ()
btrfs_qgroup_remove h src dst path = do
  r <- withCString src $ \src -> withCString dst $ \dst -> withCString path $ \path -> withForeignPtr h (\p -> c_btrfs_qgroup_remove p src dst path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_quota_enable" c_btrfs_quota_enable
  :: GuestfsP -> CString -> CInt -> IO CInt

btrfs_quota_enable :: GuestfsH -> String -> Bool -> IO ()
btrfs_quota_enable h fs enable = do
  r <- withCString fs $ \fs -> withForeignPtr h (\p -> c_btrfs_quota_enable p fs (fromBool enable))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_quota_rescan" c_btrfs_quota_rescan
  :: GuestfsP -> CString -> IO CInt

btrfs_quota_rescan :: GuestfsH -> String -> IO ()
btrfs_quota_rescan h fs = do
  r <- withCString fs $ \fs -> withForeignPtr h (\p -> c_btrfs_quota_rescan p fs)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_replace" c_btrfs_replace
  :: GuestfsP -> CString -> CString -> CString -> IO CInt

btrfs_replace :: GuestfsH -> String -> String -> String -> IO ()
btrfs_replace h srcdev targetdev mntpoint = do
  r <- withCString srcdev $ \srcdev -> withCString targetdev $ \targetdev -> withCString mntpoint $ \mntpoint -> withForeignPtr h (\p -> c_btrfs_replace p srcdev targetdev mntpoint)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_rescue_chunk_recover" c_btrfs_rescue_chunk_recover
  :: GuestfsP -> CString -> IO CInt

btrfs_rescue_chunk_recover :: GuestfsH -> String -> IO ()
btrfs_rescue_chunk_recover h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_btrfs_rescue_chunk_recover p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_rescue_super_recover" c_btrfs_rescue_super_recover
  :: GuestfsP -> CString -> IO CInt

btrfs_rescue_super_recover :: GuestfsH -> String -> IO ()
btrfs_rescue_super_recover h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_btrfs_rescue_super_recover p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_scrub_cancel" c_btrfs_scrub_cancel
  :: GuestfsP -> CString -> IO CInt

btrfs_scrub_cancel :: GuestfsH -> String -> IO ()
btrfs_scrub_cancel h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_btrfs_scrub_cancel p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_scrub_resume" c_btrfs_scrub_resume
  :: GuestfsP -> CString -> IO CInt

btrfs_scrub_resume :: GuestfsH -> String -> IO ()
btrfs_scrub_resume h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_btrfs_scrub_resume p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_scrub_start" c_btrfs_scrub_start
  :: GuestfsP -> CString -> IO CInt

btrfs_scrub_start :: GuestfsH -> String -> IO ()
btrfs_scrub_start h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_btrfs_scrub_start p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_set_seeding" c_btrfs_set_seeding
  :: GuestfsP -> CString -> CInt -> IO CInt

btrfs_set_seeding :: GuestfsH -> String -> Bool -> IO ()
btrfs_set_seeding h device seeding = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_btrfs_set_seeding p device (fromBool seeding))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_subvolume_delete" c_btrfs_subvolume_delete
  :: GuestfsP -> CString -> IO CInt

btrfs_subvolume_delete :: GuestfsH -> String -> IO ()
btrfs_subvolume_delete h subvolume = do
  r <- withCString subvolume $ \subvolume -> withForeignPtr h (\p -> c_btrfs_subvolume_delete p subvolume)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_subvolume_get_default" c_btrfs_subvolume_get_default
  :: GuestfsP -> CString -> IO Int64

btrfs_subvolume_get_default :: GuestfsH -> String -> IO Int64
btrfs_subvolume_get_default h fs = do
  r <- withCString fs $ \fs -> withForeignPtr h (\p -> c_btrfs_subvolume_get_default p fs)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_btrfs_subvolume_set_default" c_btrfs_subvolume_set_default
  :: GuestfsP -> Int64 -> CString -> IO CInt

btrfs_subvolume_set_default :: GuestfsH -> Integer -> String -> IO ()
btrfs_subvolume_set_default h id fs = do
  r <- withCString fs $ \fs -> withForeignPtr h (\p -> c_btrfs_subvolume_set_default p (fromIntegral id) fs)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfs_subvolume_show" c_btrfs_subvolume_show
  :: GuestfsP -> CString -> IO (Ptr CString)

btrfs_subvolume_show :: GuestfsH -> String -> IO [(String, String)]
btrfs_subvolume_show h subvolume = do
  r <- withCString subvolume $ \subvolume -> withForeignPtr h (\p -> c_btrfs_subvolume_show p subvolume)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else do
      arr <- peekArray0 nullPtr r
      arr <- mapM peekCString arr
      return (assocListOfHashtable arr)

foreign import ccall unsafe "guestfs.h guestfs_btrfstune_enable_extended_inode_refs" c_btrfstune_enable_extended_inode_refs
  :: GuestfsP -> CString -> IO CInt

btrfstune_enable_extended_inode_refs :: GuestfsH -> String -> IO ()
btrfstune_enable_extended_inode_refs h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_btrfstune_enable_extended_inode_refs p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfstune_enable_skinny_metadata_extent_refs" c_btrfstune_enable_skinny_metadata_extent_refs
  :: GuestfsP -> CString -> IO CInt

btrfstune_enable_skinny_metadata_extent_refs :: GuestfsH -> String -> IO ()
btrfstune_enable_skinny_metadata_extent_refs h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_btrfstune_enable_skinny_metadata_extent_refs p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_btrfstune_seeding" c_btrfstune_seeding
  :: GuestfsP -> CString -> CInt -> IO CInt

btrfstune_seeding :: GuestfsH -> String -> Bool -> IO ()
btrfstune_seeding h device seeding = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_btrfstune_seeding p device (fromBool seeding))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_c_pointer" c_c_pointer
  :: GuestfsP -> IO Int64

c_pointer :: GuestfsH -> IO Int64
c_pointer h = do
  r <- withForeignPtr h (\p -> c_c_pointer p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_canonical_device_name" c_canonical_device_name
  :: GuestfsP -> CString -> IO CString

canonical_device_name :: GuestfsH -> String -> IO String
canonical_device_name h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_canonical_device_name p device)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_cap_get_file" c_cap_get_file
  :: GuestfsP -> CString -> IO CString

cap_get_file :: GuestfsH -> String -> IO String
cap_get_file h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_cap_get_file p path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_cap_set_file" c_cap_set_file
  :: GuestfsP -> CString -> CString -> IO CInt

cap_set_file :: GuestfsH -> String -> String -> IO ()
cap_set_file h path cap = do
  r <- withCString path $ \path -> withCString cap $ \cap -> withForeignPtr h (\p -> c_cap_set_file p path cap)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_case_sensitive_path" c_case_sensitive_path
  :: GuestfsP -> CString -> IO CString

case_sensitive_path :: GuestfsH -> String -> IO String
case_sensitive_path h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_case_sensitive_path p path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_cat" c_cat
  :: GuestfsP -> CString -> IO CString

cat :: GuestfsH -> String -> IO String
cat h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_cat p path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_checksum" c_checksum
  :: GuestfsP -> CString -> CString -> IO CString

checksum :: GuestfsH -> String -> String -> IO String
checksum h csumtype path = do
  r <- withCString csumtype $ \csumtype -> withCString path $ \path -> withForeignPtr h (\p -> c_checksum p csumtype path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_checksum_device" c_checksum_device
  :: GuestfsP -> CString -> CString -> IO CString

checksum_device :: GuestfsH -> String -> String -> IO String
checksum_device h csumtype device = do
  r <- withCString csumtype $ \csumtype -> withCString device $ \device -> withForeignPtr h (\p -> c_checksum_device p csumtype device)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_checksums_out" c_checksums_out
  :: GuestfsP -> CString -> CString -> CString -> IO CInt

checksums_out :: GuestfsH -> String -> String -> String -> IO ()
checksums_out h csumtype directory sumsfile = do
  r <- withCString csumtype $ \csumtype -> withCString directory $ \directory -> withCString sumsfile $ \sumsfile -> withForeignPtr h (\p -> c_checksums_out p csumtype directory sumsfile)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_chmod" c_chmod
  :: GuestfsP -> CInt -> CString -> IO CInt

chmod :: GuestfsH -> Int -> String -> IO ()
chmod h mode path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_chmod p (fromIntegral mode) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_chown" c_chown
  :: GuestfsP -> CInt -> CInt -> CString -> IO CInt

chown :: GuestfsH -> Int -> Int -> String -> IO ()
chown h owner group path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_chown p (fromIntegral owner) (fromIntegral group) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_clear_backend_setting" c_clear_backend_setting
  :: GuestfsP -> CString -> IO CInt

clear_backend_setting :: GuestfsH -> String -> IO Int
clear_backend_setting h name = do
  r <- withCString name $ \name -> withForeignPtr h (\p -> c_clear_backend_setting p name)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_command" c_command
  :: GuestfsP -> Ptr CString -> IO CString

command :: GuestfsH -> [String] -> IO String
command h arguments = do
  r <- withMany withCString arguments $ \arguments -> withArray0 nullPtr arguments $ \arguments -> withForeignPtr h (\p -> c_command p arguments)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_command_lines" c_command_lines
  :: GuestfsP -> Ptr CString -> IO (Ptr CString)

command_lines :: GuestfsH -> [String] -> IO [String]
command_lines h arguments = do
  r <- withMany withCString arguments $ \arguments -> withArray0 nullPtr arguments $ \arguments -> withForeignPtr h (\p -> c_command_lines p arguments)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_config" c_config
  :: GuestfsP -> CString -> CString -> IO CInt

config :: GuestfsH -> String -> Maybe String -> IO ()
config h hvparam hvvalue = do
  r <- withCString hvparam $ \hvparam -> maybeWith withCString hvvalue $ \hvvalue -> withForeignPtr h (\p -> c_config p hvparam hvvalue)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_copy_in" c_copy_in
  :: GuestfsP -> CString -> CString -> IO CInt

copy_in :: GuestfsH -> String -> String -> IO ()
copy_in h localpath remotedir = do
  r <- withCString localpath $ \localpath -> withCString remotedir $ \remotedir -> withForeignPtr h (\p -> c_copy_in p localpath remotedir)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_copy_out" c_copy_out
  :: GuestfsP -> CString -> CString -> IO CInt

copy_out :: GuestfsH -> String -> String -> IO ()
copy_out h remotepath localdir = do
  r <- withCString remotepath $ \remotepath -> withCString localdir $ \localdir -> withForeignPtr h (\p -> c_copy_out p remotepath localdir)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_copy_size" c_copy_size
  :: GuestfsP -> CString -> CString -> Int64 -> IO CInt

copy_size :: GuestfsH -> String -> String -> Integer -> IO ()
copy_size h src dest size = do
  r <- withCString src $ \src -> withCString dest $ \dest -> withForeignPtr h (\p -> c_copy_size p src dest (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_cp" c_cp
  :: GuestfsP -> CString -> CString -> IO CInt

cp :: GuestfsH -> String -> String -> IO ()
cp h src dest = do
  r <- withCString src $ \src -> withCString dest $ \dest -> withForeignPtr h (\p -> c_cp p src dest)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_cp_a" c_cp_a
  :: GuestfsP -> CString -> CString -> IO CInt

cp_a :: GuestfsH -> String -> String -> IO ()
cp_a h src dest = do
  r <- withCString src $ \src -> withCString dest $ \dest -> withForeignPtr h (\p -> c_cp_a p src dest)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_cp_r" c_cp_r
  :: GuestfsP -> CString -> CString -> IO CInt

cp_r :: GuestfsH -> String -> String -> IO ()
cp_r h src dest = do
  r <- withCString src $ \src -> withCString dest $ \dest -> withForeignPtr h (\p -> c_cp_r p src dest)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_dd" c_dd
  :: GuestfsP -> CString -> CString -> IO CInt

dd :: GuestfsH -> String -> String -> IO ()
dd h src dest = do
  r <- withCString src $ \src -> withCString dest $ \dest -> withForeignPtr h (\p -> c_dd p src dest)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_debug" c_debug
  :: GuestfsP -> CString -> Ptr CString -> IO CString

debug :: GuestfsH -> String -> [String] -> IO String
debug h subcmd extraargs = do
  r <- withCString subcmd $ \subcmd -> withMany withCString extraargs $ \extraargs -> withArray0 nullPtr extraargs $ \extraargs -> withForeignPtr h (\p -> c_debug p subcmd extraargs)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_debug_drives" c_debug_drives
  :: GuestfsP -> IO (Ptr CString)

debug_drives :: GuestfsH -> IO [String]
debug_drives h = do
  r <- withForeignPtr h (\p -> c_debug_drives p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_debug_upload" c_debug_upload
  :: GuestfsP -> CString -> CString -> CInt -> IO CInt

debug_upload :: GuestfsH -> String -> String -> Int -> IO ()
debug_upload h filename tmpname mode = do
  r <- withCString filename $ \filename -> withCString tmpname $ \tmpname -> withForeignPtr h (\p -> c_debug_upload p filename tmpname (fromIntegral mode))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_device_index" c_device_index
  :: GuestfsP -> CString -> IO CInt

device_index :: GuestfsH -> String -> IO Int
device_index h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_device_index p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_df" c_df
  :: GuestfsP -> IO CString

df :: GuestfsH -> IO String
df h = do
  r <- withForeignPtr h (\p -> c_df p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_df_h" c_df_h
  :: GuestfsP -> IO CString

df_h :: GuestfsH -> IO String
df_h h = do
  r <- withForeignPtr h (\p -> c_df_h p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_disk_format" c_disk_format
  :: GuestfsP -> CString -> IO CString

disk_format :: GuestfsH -> String -> IO String
disk_format h filename = do
  r <- withCString filename $ \filename -> withForeignPtr h (\p -> c_disk_format p filename)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_disk_has_backing_file" c_disk_has_backing_file
  :: GuestfsP -> CString -> IO CInt

disk_has_backing_file :: GuestfsH -> String -> IO Bool
disk_has_backing_file h filename = do
  r <- withCString filename $ \filename -> withForeignPtr h (\p -> c_disk_has_backing_file p filename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_disk_virtual_size" c_disk_virtual_size
  :: GuestfsP -> CString -> IO Int64

disk_virtual_size :: GuestfsH -> String -> IO Int64
disk_virtual_size h filename = do
  r <- withCString filename $ \filename -> withForeignPtr h (\p -> c_disk_virtual_size p filename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_dmesg" c_dmesg
  :: GuestfsP -> IO CString

dmesg :: GuestfsH -> IO String
dmesg h = do
  r <- withForeignPtr h (\p -> c_dmesg p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_download" c_download
  :: GuestfsP -> CString -> CString -> IO CInt

download :: GuestfsH -> String -> String -> IO ()
download h remotefilename filename = do
  r <- withCString remotefilename $ \remotefilename -> withCString filename $ \filename -> withForeignPtr h (\p -> c_download p remotefilename filename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_download_offset" c_download_offset
  :: GuestfsP -> CString -> CString -> Int64 -> Int64 -> IO CInt

download_offset :: GuestfsH -> String -> String -> Integer -> Integer -> IO ()
download_offset h remotefilename filename offset size = do
  r <- withCString remotefilename $ \remotefilename -> withCString filename $ \filename -> withForeignPtr h (\p -> c_download_offset p remotefilename filename (fromIntegral offset) (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_drop_caches" c_drop_caches
  :: GuestfsP -> CInt -> IO CInt

drop_caches :: GuestfsH -> Int -> IO ()
drop_caches h whattodrop = do
  r <- withForeignPtr h (\p -> c_drop_caches p (fromIntegral whattodrop))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_du" c_du
  :: GuestfsP -> CString -> IO Int64

du :: GuestfsH -> String -> IO Int64
du h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_du p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_e2fsck_f" c_e2fsck_f
  :: GuestfsP -> CString -> IO CInt

e2fsck_f :: GuestfsH -> String -> IO ()
e2fsck_f h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_e2fsck_f p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_echo_daemon" c_echo_daemon
  :: GuestfsP -> Ptr CString -> IO CString

echo_daemon :: GuestfsH -> [String] -> IO String
echo_daemon h words = do
  r <- withMany withCString words $ \words -> withArray0 nullPtr words $ \words -> withForeignPtr h (\p -> c_echo_daemon p words)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_egrep" c_egrep
  :: GuestfsP -> CString -> CString -> IO (Ptr CString)

egrep :: GuestfsH -> String -> String -> IO [String]
egrep h regex path = do
  r <- withCString regex $ \regex -> withCString path $ \path -> withForeignPtr h (\p -> c_egrep p regex path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_egrepi" c_egrepi
  :: GuestfsP -> CString -> CString -> IO (Ptr CString)

egrepi :: GuestfsH -> String -> String -> IO [String]
egrepi h regex path = do
  r <- withCString regex $ \regex -> withCString path $ \path -> withForeignPtr h (\p -> c_egrepi p regex path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_equal" c_equal
  :: GuestfsP -> CString -> CString -> IO CInt

equal :: GuestfsH -> String -> String -> IO Bool
equal h file1 file2 = do
  r <- withCString file1 $ \file1 -> withCString file2 $ \file2 -> withForeignPtr h (\p -> c_equal p file1 file2)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_exists" c_exists
  :: GuestfsP -> CString -> IO CInt

exists :: GuestfsH -> String -> IO Bool
exists h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_exists p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_extlinux" c_extlinux
  :: GuestfsP -> CString -> IO CInt

extlinux :: GuestfsH -> String -> IO ()
extlinux h directory = do
  r <- withCString directory $ \directory -> withForeignPtr h (\p -> c_extlinux p directory)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_fallocate" c_fallocate
  :: GuestfsP -> CString -> CInt -> IO CInt

fallocate :: GuestfsH -> String -> Int -> IO ()
fallocate h path len = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_fallocate p path (fromIntegral len))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_fallocate64" c_fallocate64
  :: GuestfsP -> CString -> Int64 -> IO CInt

fallocate64 :: GuestfsH -> String -> Integer -> IO ()
fallocate64 h path len = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_fallocate64 p path (fromIntegral len))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_feature_available" c_feature_available
  :: GuestfsP -> Ptr CString -> IO CInt

feature_available :: GuestfsH -> [String] -> IO Bool
feature_available h groups = do
  r <- withMany withCString groups $ \groups -> withArray0 nullPtr groups $ \groups -> withForeignPtr h (\p -> c_feature_available p groups)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_fgrep" c_fgrep
  :: GuestfsP -> CString -> CString -> IO (Ptr CString)

fgrep :: GuestfsH -> String -> String -> IO [String]
fgrep h pattern path = do
  r <- withCString pattern $ \pattern -> withCString path $ \path -> withForeignPtr h (\p -> c_fgrep p pattern path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_fgrepi" c_fgrepi
  :: GuestfsP -> CString -> CString -> IO (Ptr CString)

fgrepi :: GuestfsH -> String -> String -> IO [String]
fgrepi h pattern path = do
  r <- withCString pattern $ \pattern -> withCString path $ \path -> withForeignPtr h (\p -> c_fgrepi p pattern path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_file" c_file
  :: GuestfsP -> CString -> IO CString

file :: GuestfsH -> String -> IO String
file h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_file p path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_file_architecture" c_file_architecture
  :: GuestfsP -> CString -> IO CString

file_architecture :: GuestfsH -> String -> IO String
file_architecture h filename = do
  r <- withCString filename $ \filename -> withForeignPtr h (\p -> c_file_architecture p filename)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_filesize" c_filesize
  :: GuestfsP -> CString -> IO Int64

filesize :: GuestfsH -> String -> IO Int64
filesize h file = do
  r <- withCString file $ \file -> withForeignPtr h (\p -> c_filesize p file)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_filesystem_available" c_filesystem_available
  :: GuestfsP -> CString -> IO CInt

filesystem_available :: GuestfsH -> String -> IO Bool
filesystem_available h filesystem = do
  r <- withCString filesystem $ \filesystem -> withForeignPtr h (\p -> c_filesystem_available p filesystem)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_fill" c_fill
  :: GuestfsP -> CInt -> CInt -> CString -> IO CInt

fill :: GuestfsH -> Int -> Int -> String -> IO ()
fill h c len path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_fill p (fromIntegral c) (fromIntegral len) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_fill_dir" c_fill_dir
  :: GuestfsP -> CString -> CInt -> IO CInt

fill_dir :: GuestfsH -> String -> Int -> IO ()
fill_dir h dir nr = do
  r <- withCString dir $ \dir -> withForeignPtr h (\p -> c_fill_dir p dir (fromIntegral nr))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_fill_pattern" c_fill_pattern
  :: GuestfsP -> CString -> CInt -> CString -> IO CInt

fill_pattern :: GuestfsH -> String -> Int -> String -> IO ()
fill_pattern h pattern len path = do
  r <- withCString pattern $ \pattern -> withCString path $ \path -> withForeignPtr h (\p -> c_fill_pattern p pattern (fromIntegral len) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_find" c_find
  :: GuestfsP -> CString -> IO (Ptr CString)

find :: GuestfsH -> String -> IO [String]
find h directory = do
  r <- withCString directory $ \directory -> withForeignPtr h (\p -> c_find p directory)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_find0" c_find0
  :: GuestfsP -> CString -> CString -> IO CInt

find0 :: GuestfsH -> String -> String -> IO ()
find0 h directory files = do
  r <- withCString directory $ \directory -> withCString files $ \files -> withForeignPtr h (\p -> c_find0 p directory files)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_findfs_label" c_findfs_label
  :: GuestfsP -> CString -> IO CString

findfs_label :: GuestfsH -> String -> IO String
findfs_label h label = do
  r <- withCString label $ \label -> withForeignPtr h (\p -> c_findfs_label p label)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_findfs_uuid" c_findfs_uuid
  :: GuestfsP -> CString -> IO CString

findfs_uuid :: GuestfsH -> String -> IO String
findfs_uuid h uuid = do
  r <- withCString uuid $ \uuid -> withForeignPtr h (\p -> c_findfs_uuid p uuid)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_fsck" c_fsck
  :: GuestfsP -> CString -> CString -> IO CInt

fsck :: GuestfsH -> String -> String -> IO Int
fsck h fstype device = do
  r <- withCString fstype $ \fstype -> withCString device $ \device -> withForeignPtr h (\p -> c_fsck p fstype device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_get_attach_method" c_get_attach_method
  :: GuestfsP -> IO CString

get_attach_method :: GuestfsH -> IO String
get_attach_method h = do
  r <- withForeignPtr h (\p -> c_get_attach_method p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_autosync" c_get_autosync
  :: GuestfsP -> IO CInt

get_autosync :: GuestfsH -> IO Bool
get_autosync h = do
  r <- withForeignPtr h (\p -> c_get_autosync p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_get_backend" c_get_backend
  :: GuestfsP -> IO CString

get_backend :: GuestfsH -> IO String
get_backend h = do
  r <- withForeignPtr h (\p -> c_get_backend p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_backend_setting" c_get_backend_setting
  :: GuestfsP -> CString -> IO CString

get_backend_setting :: GuestfsH -> String -> IO String
get_backend_setting h name = do
  r <- withCString name $ \name -> withForeignPtr h (\p -> c_get_backend_setting p name)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_backend_settings" c_get_backend_settings
  :: GuestfsP -> IO (Ptr CString)

get_backend_settings :: GuestfsH -> IO [String]
get_backend_settings h = do
  r <- withForeignPtr h (\p -> c_get_backend_settings p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_get_cachedir" c_get_cachedir
  :: GuestfsP -> IO CString

get_cachedir :: GuestfsH -> IO String
get_cachedir h = do
  r <- withForeignPtr h (\p -> c_get_cachedir p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_direct" c_get_direct
  :: GuestfsP -> IO CInt

get_direct :: GuestfsH -> IO Bool
get_direct h = do
  r <- withForeignPtr h (\p -> c_get_direct p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_get_e2attrs" c_get_e2attrs
  :: GuestfsP -> CString -> IO CString

get_e2attrs :: GuestfsH -> String -> IO String
get_e2attrs h file = do
  r <- withCString file $ \file -> withForeignPtr h (\p -> c_get_e2attrs p file)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_e2generation" c_get_e2generation
  :: GuestfsP -> CString -> IO Int64

get_e2generation :: GuestfsH -> String -> IO Int64
get_e2generation h file = do
  r <- withCString file $ \file -> withForeignPtr h (\p -> c_get_e2generation p file)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_get_e2label" c_get_e2label
  :: GuestfsP -> CString -> IO CString

get_e2label :: GuestfsH -> String -> IO String
get_e2label h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_get_e2label p device)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_e2uuid" c_get_e2uuid
  :: GuestfsP -> CString -> IO CString

get_e2uuid :: GuestfsH -> String -> IO String
get_e2uuid h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_get_e2uuid p device)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_hv" c_get_hv
  :: GuestfsP -> IO CString

get_hv :: GuestfsH -> IO String
get_hv h = do
  r <- withForeignPtr h (\p -> c_get_hv p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_identifier" c_get_identifier
  :: GuestfsP -> IO CString

get_identifier :: GuestfsH -> IO String
get_identifier h = do
  r <- withForeignPtr h (\p -> c_get_identifier p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_libvirt_requested_credential_challenge" c_get_libvirt_requested_credential_challenge
  :: GuestfsP -> CInt -> IO CString

get_libvirt_requested_credential_challenge :: GuestfsH -> Int -> IO String
get_libvirt_requested_credential_challenge h index = do
  r <- withForeignPtr h (\p -> c_get_libvirt_requested_credential_challenge p (fromIntegral index))
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_libvirt_requested_credential_defresult" c_get_libvirt_requested_credential_defresult
  :: GuestfsP -> CInt -> IO CString

get_libvirt_requested_credential_defresult :: GuestfsH -> Int -> IO String
get_libvirt_requested_credential_defresult h index = do
  r <- withForeignPtr h (\p -> c_get_libvirt_requested_credential_defresult p (fromIntegral index))
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_libvirt_requested_credential_prompt" c_get_libvirt_requested_credential_prompt
  :: GuestfsP -> CInt -> IO CString

get_libvirt_requested_credential_prompt :: GuestfsH -> Int -> IO String
get_libvirt_requested_credential_prompt h index = do
  r <- withForeignPtr h (\p -> c_get_libvirt_requested_credential_prompt p (fromIntegral index))
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_libvirt_requested_credentials" c_get_libvirt_requested_credentials
  :: GuestfsP -> IO (Ptr CString)

get_libvirt_requested_credentials :: GuestfsH -> IO [String]
get_libvirt_requested_credentials h = do
  r <- withForeignPtr h (\p -> c_get_libvirt_requested_credentials p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_get_memsize" c_get_memsize
  :: GuestfsP -> IO CInt

get_memsize :: GuestfsH -> IO Int
get_memsize h = do
  r <- withForeignPtr h (\p -> c_get_memsize p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_get_network" c_get_network
  :: GuestfsP -> IO CInt

get_network :: GuestfsH -> IO Bool
get_network h = do
  r <- withForeignPtr h (\p -> c_get_network p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_get_path" c_get_path
  :: GuestfsP -> IO CString

get_path :: GuestfsH -> IO String
get_path h = do
  r <- withForeignPtr h (\p -> c_get_path p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_pgroup" c_get_pgroup
  :: GuestfsP -> IO CInt

get_pgroup :: GuestfsH -> IO Bool
get_pgroup h = do
  r <- withForeignPtr h (\p -> c_get_pgroup p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_get_pid" c_get_pid
  :: GuestfsP -> IO CInt

get_pid :: GuestfsH -> IO Int
get_pid h = do
  r <- withForeignPtr h (\p -> c_get_pid p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_get_program" c_get_program
  :: GuestfsP -> IO CString

get_program :: GuestfsH -> IO String
get_program h = do
  r <- withForeignPtr h (\p -> c_get_program p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_qemu" c_get_qemu
  :: GuestfsP -> IO CString

get_qemu :: GuestfsH -> IO String
get_qemu h = do
  r <- withForeignPtr h (\p -> c_get_qemu p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_recovery_proc" c_get_recovery_proc
  :: GuestfsP -> IO CInt

get_recovery_proc :: GuestfsH -> IO Bool
get_recovery_proc h = do
  r <- withForeignPtr h (\p -> c_get_recovery_proc p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_get_selinux" c_get_selinux
  :: GuestfsP -> IO CInt

get_selinux :: GuestfsH -> IO Bool
get_selinux h = do
  r <- withForeignPtr h (\p -> c_get_selinux p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_get_smp" c_get_smp
  :: GuestfsP -> IO CInt

get_smp :: GuestfsH -> IO Int
get_smp h = do
  r <- withForeignPtr h (\p -> c_get_smp p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_get_state" c_get_state
  :: GuestfsP -> IO CInt

get_state :: GuestfsH -> IO Int
get_state h = do
  r <- withForeignPtr h (\p -> c_get_state p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_get_tmpdir" c_get_tmpdir
  :: GuestfsP -> IO CString

get_tmpdir :: GuestfsH -> IO String
get_tmpdir h = do
  r <- withForeignPtr h (\p -> c_get_tmpdir p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_get_trace" c_get_trace
  :: GuestfsP -> IO CInt

get_trace :: GuestfsH -> IO Bool
get_trace h = do
  r <- withForeignPtr h (\p -> c_get_trace p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_get_umask" c_get_umask
  :: GuestfsP -> IO CInt

get_umask :: GuestfsH -> IO Int
get_umask h = do
  r <- withForeignPtr h (\p -> c_get_umask p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_get_verbose" c_get_verbose
  :: GuestfsP -> IO CInt

get_verbose :: GuestfsH -> IO Bool
get_verbose h = do
  r <- withForeignPtr h (\p -> c_get_verbose p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_getcon" c_getcon
  :: GuestfsP -> IO CString

getcon :: GuestfsH -> IO String
getcon h = do
  r <- withForeignPtr h (\p -> c_getcon p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_glob_expand" c_glob_expand
  :: GuestfsP -> CString -> IO (Ptr CString)

glob_expand :: GuestfsH -> String -> IO [String]
glob_expand h pattern = do
  r <- withCString pattern $ \pattern -> withForeignPtr h (\p -> c_glob_expand p pattern)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_grepi" c_grepi
  :: GuestfsP -> CString -> CString -> IO (Ptr CString)

grepi :: GuestfsH -> String -> String -> IO [String]
grepi h regex path = do
  r <- withCString regex $ \regex -> withCString path $ \path -> withForeignPtr h (\p -> c_grepi p regex path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_grub_install" c_grub_install
  :: GuestfsP -> CString -> CString -> IO CInt

grub_install :: GuestfsH -> String -> String -> IO ()
grub_install h root device = do
  r <- withCString root $ \root -> withCString device $ \device -> withForeignPtr h (\p -> c_grub_install p root device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_head" c_head
  :: GuestfsP -> CString -> IO (Ptr CString)

head :: GuestfsH -> String -> IO [String]
head h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_head p path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_head_n" c_head_n
  :: GuestfsP -> CInt -> CString -> IO (Ptr CString)

head_n :: GuestfsH -> Int -> String -> IO [String]
head_n h nrlines path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_head_n p (fromIntegral nrlines) path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_hexdump" c_hexdump
  :: GuestfsP -> CString -> IO CString

hexdump :: GuestfsH -> String -> IO String
hexdump h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_hexdump p path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_hivex_close" c_hivex_close
  :: GuestfsP -> IO CInt

hivex_close :: GuestfsH -> IO ()
hivex_close h = do
  r <- withForeignPtr h (\p -> c_hivex_close p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_hivex_commit" c_hivex_commit
  :: GuestfsP -> CString -> IO CInt

hivex_commit :: GuestfsH -> Maybe String -> IO ()
hivex_commit h filename = do
  r <- maybeWith withCString filename $ \filename -> withForeignPtr h (\p -> c_hivex_commit p filename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_hivex_node_add_child" c_hivex_node_add_child
  :: GuestfsP -> Int64 -> CString -> IO Int64

hivex_node_add_child :: GuestfsH -> Integer -> String -> IO Int64
hivex_node_add_child h parent name = do
  r <- withCString name $ \name -> withForeignPtr h (\p -> c_hivex_node_add_child p (fromIntegral parent) name)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_hivex_node_delete_child" c_hivex_node_delete_child
  :: GuestfsP -> Int64 -> IO CInt

hivex_node_delete_child :: GuestfsH -> Integer -> IO ()
hivex_node_delete_child h nodeh = do
  r <- withForeignPtr h (\p -> c_hivex_node_delete_child p (fromIntegral nodeh))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_hivex_node_get_child" c_hivex_node_get_child
  :: GuestfsP -> Int64 -> CString -> IO Int64

hivex_node_get_child :: GuestfsH -> Integer -> String -> IO Int64
hivex_node_get_child h nodeh name = do
  r <- withCString name $ \name -> withForeignPtr h (\p -> c_hivex_node_get_child p (fromIntegral nodeh) name)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_hivex_node_get_value" c_hivex_node_get_value
  :: GuestfsP -> Int64 -> CString -> IO Int64

hivex_node_get_value :: GuestfsH -> Integer -> String -> IO Int64
hivex_node_get_value h nodeh key = do
  r <- withCString key $ \key -> withForeignPtr h (\p -> c_hivex_node_get_value p (fromIntegral nodeh) key)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_hivex_node_name" c_hivex_node_name
  :: GuestfsP -> Int64 -> IO CString

hivex_node_name :: GuestfsH -> Integer -> IO String
hivex_node_name h nodeh = do
  r <- withForeignPtr h (\p -> c_hivex_node_name p (fromIntegral nodeh))
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_hivex_node_parent" c_hivex_node_parent
  :: GuestfsP -> Int64 -> IO Int64

hivex_node_parent :: GuestfsH -> Integer -> IO Int64
hivex_node_parent h nodeh = do
  r <- withForeignPtr h (\p -> c_hivex_node_parent p (fromIntegral nodeh))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_hivex_node_set_value" c_hivex_node_set_value
  :: GuestfsP -> Int64 -> CString -> Int64 -> CString -> CInt -> IO CInt

hivex_node_set_value :: GuestfsH -> Integer -> String -> Integer -> String -> IO ()
hivex_node_set_value h nodeh key t val = do
  r <- withCString key $ \key -> withCStringLen val $ \(val, val_size) -> withForeignPtr h (\p -> c_hivex_node_set_value p (fromIntegral nodeh) key (fromIntegral t) val (fromIntegral val_size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_hivex_root" c_hivex_root
  :: GuestfsP -> IO Int64

hivex_root :: GuestfsH -> IO Int64
hivex_root h = do
  r <- withForeignPtr h (\p -> c_hivex_root p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_hivex_value_key" c_hivex_value_key
  :: GuestfsP -> Int64 -> IO CString

hivex_value_key :: GuestfsH -> Integer -> IO String
hivex_value_key h valueh = do
  r <- withForeignPtr h (\p -> c_hivex_value_key p (fromIntegral valueh))
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_hivex_value_type" c_hivex_value_type
  :: GuestfsP -> Int64 -> IO Int64

hivex_value_type :: GuestfsH -> Integer -> IO Int64
hivex_value_type h valueh = do
  r <- withForeignPtr h (\p -> c_hivex_value_type p (fromIntegral valueh))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_hivex_value_utf8" c_hivex_value_utf8
  :: GuestfsP -> Int64 -> IO CString

hivex_value_utf8 :: GuestfsH -> Integer -> IO String
hivex_value_utf8 h valueh = do
  r <- withForeignPtr h (\p -> c_hivex_value_utf8 p (fromIntegral valueh))
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_initrd_list" c_initrd_list
  :: GuestfsP -> CString -> IO (Ptr CString)

initrd_list :: GuestfsH -> String -> IO [String]
initrd_list h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_initrd_list p path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_inotify_add_watch" c_inotify_add_watch
  :: GuestfsP -> CString -> CInt -> IO Int64

inotify_add_watch :: GuestfsH -> String -> Int -> IO Int64
inotify_add_watch h path mask = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_inotify_add_watch p path (fromIntegral mask))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_inotify_close" c_inotify_close
  :: GuestfsP -> IO CInt

inotify_close :: GuestfsH -> IO ()
inotify_close h = do
  r <- withForeignPtr h (\p -> c_inotify_close p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_inotify_files" c_inotify_files
  :: GuestfsP -> IO (Ptr CString)

inotify_files :: GuestfsH -> IO [String]
inotify_files h = do
  r <- withForeignPtr h (\p -> c_inotify_files p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_inotify_init" c_inotify_init
  :: GuestfsP -> CInt -> IO CInt

inotify_init :: GuestfsH -> Int -> IO ()
inotify_init h maxevents = do
  r <- withForeignPtr h (\p -> c_inotify_init p (fromIntegral maxevents))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_inotify_rm_watch" c_inotify_rm_watch
  :: GuestfsP -> CInt -> IO CInt

inotify_rm_watch :: GuestfsH -> Int -> IO ()
inotify_rm_watch h wd = do
  r <- withForeignPtr h (\p -> c_inotify_rm_watch p (fromIntegral wd))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_arch" c_inspect_get_arch
  :: GuestfsP -> CString -> IO CString

inspect_get_arch :: GuestfsH -> String -> IO String
inspect_get_arch h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_arch p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_distro" c_inspect_get_distro
  :: GuestfsP -> CString -> IO CString

inspect_get_distro :: GuestfsH -> String -> IO String
inspect_get_distro h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_distro p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_drive_mappings" c_inspect_get_drive_mappings
  :: GuestfsP -> CString -> IO (Ptr CString)

inspect_get_drive_mappings :: GuestfsH -> String -> IO [(String, String)]
inspect_get_drive_mappings h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_drive_mappings p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else do
      arr <- peekArray0 nullPtr r
      arr <- mapM peekCString arr
      return (assocListOfHashtable arr)

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_filesystems" c_inspect_get_filesystems
  :: GuestfsP -> CString -> IO (Ptr CString)

inspect_get_filesystems :: GuestfsH -> String -> IO [String]
inspect_get_filesystems h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_filesystems p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_format" c_inspect_get_format
  :: GuestfsP -> CString -> IO CString

inspect_get_format :: GuestfsH -> String -> IO String
inspect_get_format h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_format p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_hostname" c_inspect_get_hostname
  :: GuestfsP -> CString -> IO CString

inspect_get_hostname :: GuestfsH -> String -> IO String
inspect_get_hostname h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_hostname p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_major_version" c_inspect_get_major_version
  :: GuestfsP -> CString -> IO CInt

inspect_get_major_version :: GuestfsH -> String -> IO Int
inspect_get_major_version h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_major_version p root)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_minor_version" c_inspect_get_minor_version
  :: GuestfsP -> CString -> IO CInt

inspect_get_minor_version :: GuestfsH -> String -> IO Int
inspect_get_minor_version h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_minor_version p root)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_mountpoints" c_inspect_get_mountpoints
  :: GuestfsP -> CString -> IO (Ptr CString)

inspect_get_mountpoints :: GuestfsH -> String -> IO [(String, String)]
inspect_get_mountpoints h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_mountpoints p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else do
      arr <- peekArray0 nullPtr r
      arr <- mapM peekCString arr
      return (assocListOfHashtable arr)

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_package_format" c_inspect_get_package_format
  :: GuestfsP -> CString -> IO CString

inspect_get_package_format :: GuestfsH -> String -> IO String
inspect_get_package_format h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_package_format p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_package_management" c_inspect_get_package_management
  :: GuestfsP -> CString -> IO CString

inspect_get_package_management :: GuestfsH -> String -> IO String
inspect_get_package_management h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_package_management p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_product_name" c_inspect_get_product_name
  :: GuestfsP -> CString -> IO CString

inspect_get_product_name :: GuestfsH -> String -> IO String
inspect_get_product_name h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_product_name p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_product_variant" c_inspect_get_product_variant
  :: GuestfsP -> CString -> IO CString

inspect_get_product_variant :: GuestfsH -> String -> IO String
inspect_get_product_variant h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_product_variant p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_roots" c_inspect_get_roots
  :: GuestfsP -> IO (Ptr CString)

inspect_get_roots :: GuestfsH -> IO [String]
inspect_get_roots h = do
  r <- withForeignPtr h (\p -> c_inspect_get_roots p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_type" c_inspect_get_type
  :: GuestfsP -> CString -> IO CString

inspect_get_type :: GuestfsH -> String -> IO String
inspect_get_type h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_type p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_windows_current_control_set" c_inspect_get_windows_current_control_set
  :: GuestfsP -> CString -> IO CString

inspect_get_windows_current_control_set :: GuestfsH -> String -> IO String
inspect_get_windows_current_control_set h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_windows_current_control_set p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_inspect_get_windows_systemroot" c_inspect_get_windows_systemroot
  :: GuestfsP -> CString -> IO CString

inspect_get_windows_systemroot :: GuestfsH -> String -> IO String
inspect_get_windows_systemroot h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_windows_systemroot p root)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_inspect_is_live" c_inspect_is_live
  :: GuestfsP -> CString -> IO CInt

inspect_is_live :: GuestfsH -> String -> IO Bool
inspect_is_live h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_is_live p root)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_inspect_is_multipart" c_inspect_is_multipart
  :: GuestfsP -> CString -> IO CInt

inspect_is_multipart :: GuestfsH -> String -> IO Bool
inspect_is_multipart h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_is_multipart p root)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_inspect_is_netinst" c_inspect_is_netinst
  :: GuestfsP -> CString -> IO CInt

inspect_is_netinst :: GuestfsH -> String -> IO Bool
inspect_is_netinst h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_is_netinst p root)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_inspect_os" c_inspect_os
  :: GuestfsP -> IO (Ptr CString)

inspect_os :: GuestfsH -> IO [String]
inspect_os h = do
  r <- withForeignPtr h (\p -> c_inspect_os p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_internal_exit" c_internal_exit
  :: GuestfsP -> IO CInt

internal_exit :: GuestfsH -> IO ()
internal_exit h = do
  r <- withForeignPtr h (\p -> c_internal_exit p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_internal_test_close_output" c_internal_test_close_output
  :: GuestfsP -> IO CInt

internal_test_close_output :: GuestfsH -> IO ()
internal_test_close_output h = do
  r <- withForeignPtr h (\p -> c_internal_test_close_output p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rbool" c_internal_test_rbool
  :: GuestfsP -> CString -> IO CInt

internal_test_rbool :: GuestfsH -> String -> IO Bool
internal_test_rbool h val = do
  r <- withCString val $ \val -> withForeignPtr h (\p -> c_internal_test_rbool p val)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rboolerr" c_internal_test_rboolerr
  :: GuestfsP -> IO CInt

internal_test_rboolerr :: GuestfsH -> IO Bool
internal_test_rboolerr h = do
  r <- withForeignPtr h (\p -> c_internal_test_rboolerr p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rconststring" c_internal_test_rconststring
  :: GuestfsP -> CString -> IO CString

internal_test_rconststring :: GuestfsH -> String -> IO String
internal_test_rconststring h val = do
  r <- withCString val $ \val -> withForeignPtr h (\p -> c_internal_test_rconststring p val)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rconststringerr" c_internal_test_rconststringerr
  :: GuestfsP -> IO CString

internal_test_rconststringerr :: GuestfsH -> IO String
internal_test_rconststringerr h = do
  r <- withForeignPtr h (\p -> c_internal_test_rconststringerr p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rhashtable" c_internal_test_rhashtable
  :: GuestfsP -> CString -> IO (Ptr CString)

internal_test_rhashtable :: GuestfsH -> String -> IO [(String, String)]
internal_test_rhashtable h val = do
  r <- withCString val $ \val -> withForeignPtr h (\p -> c_internal_test_rhashtable p val)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else do
      arr <- peekArray0 nullPtr r
      arr <- mapM peekCString arr
      return (assocListOfHashtable arr)

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rhashtableerr" c_internal_test_rhashtableerr
  :: GuestfsP -> IO (Ptr CString)

internal_test_rhashtableerr :: GuestfsH -> IO [(String, String)]
internal_test_rhashtableerr h = do
  r <- withForeignPtr h (\p -> c_internal_test_rhashtableerr p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else do
      arr <- peekArray0 nullPtr r
      arr <- mapM peekCString arr
      return (assocListOfHashtable arr)

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rint" c_internal_test_rint
  :: GuestfsP -> CString -> IO CInt

internal_test_rint :: GuestfsH -> String -> IO Int
internal_test_rint h val = do
  r <- withCString val $ \val -> withForeignPtr h (\p -> c_internal_test_rint p val)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rint64" c_internal_test_rint64
  :: GuestfsP -> CString -> IO Int64

internal_test_rint64 :: GuestfsH -> String -> IO Int64
internal_test_rint64 h val = do
  r <- withCString val $ \val -> withForeignPtr h (\p -> c_internal_test_rint64 p val)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rint64err" c_internal_test_rint64err
  :: GuestfsP -> IO Int64

internal_test_rint64err :: GuestfsH -> IO Int64
internal_test_rint64err h = do
  r <- withForeignPtr h (\p -> c_internal_test_rint64err p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rinterr" c_internal_test_rinterr
  :: GuestfsP -> IO CInt

internal_test_rinterr :: GuestfsH -> IO Int
internal_test_rinterr h = do
  r <- withForeignPtr h (\p -> c_internal_test_rinterr p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rstring" c_internal_test_rstring
  :: GuestfsP -> CString -> IO CString

internal_test_rstring :: GuestfsH -> String -> IO String
internal_test_rstring h val = do
  r <- withCString val $ \val -> withForeignPtr h (\p -> c_internal_test_rstring p val)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rstringerr" c_internal_test_rstringerr
  :: GuestfsP -> IO CString

internal_test_rstringerr :: GuestfsH -> IO String
internal_test_rstringerr h = do
  r <- withForeignPtr h (\p -> c_internal_test_rstringerr p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rstringlist" c_internal_test_rstringlist
  :: GuestfsP -> CString -> IO (Ptr CString)

internal_test_rstringlist :: GuestfsH -> String -> IO [String]
internal_test_rstringlist h val = do
  r <- withCString val $ \val -> withForeignPtr h (\p -> c_internal_test_rstringlist p val)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_internal_test_rstringlisterr" c_internal_test_rstringlisterr
  :: GuestfsP -> IO (Ptr CString)

internal_test_rstringlisterr :: GuestfsH -> IO [String]
internal_test_rstringlisterr h = do
  r <- withForeignPtr h (\p -> c_internal_test_rstringlisterr p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_internal_test_set_output" c_internal_test_set_output
  :: GuestfsP -> CString -> IO CInt

internal_test_set_output :: GuestfsH -> String -> IO ()
internal_test_set_output h filename = do
  r <- withCString filename $ \filename -> withForeignPtr h (\p -> c_internal_test_set_output p filename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_is_busy" c_is_busy
  :: GuestfsP -> IO CInt

is_busy :: GuestfsH -> IO Bool
is_busy h = do
  r <- withForeignPtr h (\p -> c_is_busy p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_is_config" c_is_config
  :: GuestfsP -> IO CInt

is_config :: GuestfsH -> IO Bool
is_config h = do
  r <- withForeignPtr h (\p -> c_is_config p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_is_launching" c_is_launching
  :: GuestfsP -> IO CInt

is_launching :: GuestfsH -> IO Bool
is_launching h = do
  r <- withForeignPtr h (\p -> c_is_launching p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_is_lv" c_is_lv
  :: GuestfsP -> CString -> IO CInt

is_lv :: GuestfsH -> String -> IO Bool
is_lv h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_is_lv p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_is_ready" c_is_ready
  :: GuestfsP -> IO CInt

is_ready :: GuestfsH -> IO Bool
is_ready h = do
  r <- withForeignPtr h (\p -> c_is_ready p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_is_symlink" c_is_symlink
  :: GuestfsP -> CString -> IO CInt

is_symlink :: GuestfsH -> String -> IO Bool
is_symlink h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_is_symlink p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_is_whole_device" c_is_whole_device
  :: GuestfsP -> CString -> IO CInt

is_whole_device :: GuestfsH -> String -> IO Bool
is_whole_device h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_is_whole_device p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_is_zero" c_is_zero
  :: GuestfsP -> CString -> IO CInt

is_zero :: GuestfsH -> String -> IO Bool
is_zero h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_is_zero p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_is_zero_device" c_is_zero_device
  :: GuestfsP -> CString -> IO CInt

is_zero_device :: GuestfsH -> String -> IO Bool
is_zero_device h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_is_zero_device p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_journal_close" c_journal_close
  :: GuestfsP -> IO CInt

journal_close :: GuestfsH -> IO ()
journal_close h = do
  r <- withForeignPtr h (\p -> c_journal_close p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_journal_get_data_threshold" c_journal_get_data_threshold
  :: GuestfsP -> IO Int64

journal_get_data_threshold :: GuestfsH -> IO Int64
journal_get_data_threshold h = do
  r <- withForeignPtr h (\p -> c_journal_get_data_threshold p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_journal_get_realtime_usec" c_journal_get_realtime_usec
  :: GuestfsP -> IO Int64

journal_get_realtime_usec :: GuestfsH -> IO Int64
journal_get_realtime_usec h = do
  r <- withForeignPtr h (\p -> c_journal_get_realtime_usec p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_journal_next" c_journal_next
  :: GuestfsP -> IO CInt

journal_next :: GuestfsH -> IO Bool
journal_next h = do
  r <- withForeignPtr h (\p -> c_journal_next p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_journal_open" c_journal_open
  :: GuestfsP -> CString -> IO CInt

journal_open :: GuestfsH -> String -> IO ()
journal_open h directory = do
  r <- withCString directory $ \directory -> withForeignPtr h (\p -> c_journal_open p directory)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_journal_set_data_threshold" c_journal_set_data_threshold
  :: GuestfsP -> Int64 -> IO CInt

journal_set_data_threshold :: GuestfsH -> Integer -> IO ()
journal_set_data_threshold h threshold = do
  r <- withForeignPtr h (\p -> c_journal_set_data_threshold p (fromIntegral threshold))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_journal_skip" c_journal_skip
  :: GuestfsP -> Int64 -> IO Int64

journal_skip :: GuestfsH -> Integer -> IO Int64
journal_skip h skip = do
  r <- withForeignPtr h (\p -> c_journal_skip p (fromIntegral skip))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_kill_subprocess" c_kill_subprocess
  :: GuestfsP -> IO CInt

kill_subprocess :: GuestfsH -> IO ()
kill_subprocess h = do
  r <- withForeignPtr h (\p -> c_kill_subprocess p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_launch" c_launch
  :: GuestfsP -> IO CInt

launch :: GuestfsH -> IO ()
launch h = do
  r <- withForeignPtr h (\p -> c_launch p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_lchown" c_lchown
  :: GuestfsP -> CInt -> CInt -> CString -> IO CInt

lchown :: GuestfsH -> Int -> Int -> String -> IO ()
lchown h owner group path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_lchown p (fromIntegral owner) (fromIntegral group) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_ldmtool_create_all" c_ldmtool_create_all
  :: GuestfsP -> IO CInt

ldmtool_create_all :: GuestfsH -> IO ()
ldmtool_create_all h = do
  r <- withForeignPtr h (\p -> c_ldmtool_create_all p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_ldmtool_diskgroup_disks" c_ldmtool_diskgroup_disks
  :: GuestfsP -> CString -> IO (Ptr CString)

ldmtool_diskgroup_disks :: GuestfsH -> String -> IO [String]
ldmtool_diskgroup_disks h diskgroup = do
  r <- withCString diskgroup $ \diskgroup -> withForeignPtr h (\p -> c_ldmtool_diskgroup_disks p diskgroup)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_ldmtool_diskgroup_name" c_ldmtool_diskgroup_name
  :: GuestfsP -> CString -> IO CString

ldmtool_diskgroup_name :: GuestfsH -> String -> IO String
ldmtool_diskgroup_name h diskgroup = do
  r <- withCString diskgroup $ \diskgroup -> withForeignPtr h (\p -> c_ldmtool_diskgroup_name p diskgroup)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_ldmtool_diskgroup_volumes" c_ldmtool_diskgroup_volumes
  :: GuestfsP -> CString -> IO (Ptr CString)

ldmtool_diskgroup_volumes :: GuestfsH -> String -> IO [String]
ldmtool_diskgroup_volumes h diskgroup = do
  r <- withCString diskgroup $ \diskgroup -> withForeignPtr h (\p -> c_ldmtool_diskgroup_volumes p diskgroup)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_ldmtool_remove_all" c_ldmtool_remove_all
  :: GuestfsP -> IO CInt

ldmtool_remove_all :: GuestfsH -> IO ()
ldmtool_remove_all h = do
  r <- withForeignPtr h (\p -> c_ldmtool_remove_all p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_ldmtool_scan" c_ldmtool_scan
  :: GuestfsP -> IO (Ptr CString)

ldmtool_scan :: GuestfsH -> IO [String]
ldmtool_scan h = do
  r <- withForeignPtr h (\p -> c_ldmtool_scan p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_ldmtool_scan_devices" c_ldmtool_scan_devices
  :: GuestfsP -> Ptr CString -> IO (Ptr CString)

ldmtool_scan_devices :: GuestfsH -> [String] -> IO [String]
ldmtool_scan_devices h devices = do
  r <- withMany withCString devices $ \devices -> withArray0 nullPtr devices $ \devices -> withForeignPtr h (\p -> c_ldmtool_scan_devices p devices)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_ldmtool_volume_hint" c_ldmtool_volume_hint
  :: GuestfsP -> CString -> CString -> IO CString

ldmtool_volume_hint :: GuestfsH -> String -> String -> IO String
ldmtool_volume_hint h diskgroup volume = do
  r <- withCString diskgroup $ \diskgroup -> withCString volume $ \volume -> withForeignPtr h (\p -> c_ldmtool_volume_hint p diskgroup volume)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_ldmtool_volume_partitions" c_ldmtool_volume_partitions
  :: GuestfsP -> CString -> CString -> IO (Ptr CString)

ldmtool_volume_partitions :: GuestfsH -> String -> String -> IO [String]
ldmtool_volume_partitions h diskgroup volume = do
  r <- withCString diskgroup $ \diskgroup -> withCString volume $ \volume -> withForeignPtr h (\p -> c_ldmtool_volume_partitions p diskgroup volume)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_ldmtool_volume_type" c_ldmtool_volume_type
  :: GuestfsP -> CString -> CString -> IO CString

ldmtool_volume_type :: GuestfsH -> String -> String -> IO String
ldmtool_volume_type h diskgroup volume = do
  r <- withCString diskgroup $ \diskgroup -> withCString volume $ \volume -> withForeignPtr h (\p -> c_ldmtool_volume_type p diskgroup volume)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_list_9p" c_list_9p
  :: GuestfsP -> IO (Ptr CString)

list_9p :: GuestfsH -> IO [String]
list_9p h = do
  r <- withForeignPtr h (\p -> c_list_9p p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_list_devices" c_list_devices
  :: GuestfsP -> IO (Ptr CString)

list_devices :: GuestfsH -> IO [String]
list_devices h = do
  r <- withForeignPtr h (\p -> c_list_devices p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_list_disk_labels" c_list_disk_labels
  :: GuestfsP -> IO (Ptr CString)

list_disk_labels :: GuestfsH -> IO [(String, String)]
list_disk_labels h = do
  r <- withForeignPtr h (\p -> c_list_disk_labels p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else do
      arr <- peekArray0 nullPtr r
      arr <- mapM peekCString arr
      return (assocListOfHashtable arr)

foreign import ccall unsafe "guestfs.h guestfs_list_dm_devices" c_list_dm_devices
  :: GuestfsP -> IO (Ptr CString)

list_dm_devices :: GuestfsH -> IO [String]
list_dm_devices h = do
  r <- withForeignPtr h (\p -> c_list_dm_devices p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_list_filesystems" c_list_filesystems
  :: GuestfsP -> IO (Ptr CString)

list_filesystems :: GuestfsH -> IO [(String, String)]
list_filesystems h = do
  r <- withForeignPtr h (\p -> c_list_filesystems p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else do
      arr <- peekArray0 nullPtr r
      arr <- mapM peekCString arr
      return (assocListOfHashtable arr)

foreign import ccall unsafe "guestfs.h guestfs_list_ldm_partitions" c_list_ldm_partitions
  :: GuestfsP -> IO (Ptr CString)

list_ldm_partitions :: GuestfsH -> IO [String]
list_ldm_partitions h = do
  r <- withForeignPtr h (\p -> c_list_ldm_partitions p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_list_ldm_volumes" c_list_ldm_volumes
  :: GuestfsP -> IO (Ptr CString)

list_ldm_volumes :: GuestfsH -> IO [String]
list_ldm_volumes h = do
  r <- withForeignPtr h (\p -> c_list_ldm_volumes p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_list_md_devices" c_list_md_devices
  :: GuestfsP -> IO (Ptr CString)

list_md_devices :: GuestfsH -> IO [String]
list_md_devices h = do
  r <- withForeignPtr h (\p -> c_list_md_devices p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_list_partitions" c_list_partitions
  :: GuestfsP -> IO (Ptr CString)

list_partitions :: GuestfsH -> IO [String]
list_partitions h = do
  r <- withForeignPtr h (\p -> c_list_partitions p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_ll" c_ll
  :: GuestfsP -> CString -> IO CString

ll :: GuestfsH -> String -> IO String
ll h directory = do
  r <- withCString directory $ \directory -> withForeignPtr h (\p -> c_ll p directory)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_llz" c_llz
  :: GuestfsP -> CString -> IO CString

llz :: GuestfsH -> String -> IO String
llz h directory = do
  r <- withCString directory $ \directory -> withForeignPtr h (\p -> c_llz p directory)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_ln" c_ln
  :: GuestfsP -> CString -> CString -> IO CInt

ln :: GuestfsH -> String -> String -> IO ()
ln h target linkname = do
  r <- withCString target $ \target -> withCString linkname $ \linkname -> withForeignPtr h (\p -> c_ln p target linkname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_ln_f" c_ln_f
  :: GuestfsP -> CString -> CString -> IO CInt

ln_f :: GuestfsH -> String -> String -> IO ()
ln_f h target linkname = do
  r <- withCString target $ \target -> withCString linkname $ \linkname -> withForeignPtr h (\p -> c_ln_f p target linkname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_ln_s" c_ln_s
  :: GuestfsP -> CString -> CString -> IO CInt

ln_s :: GuestfsH -> String -> String -> IO ()
ln_s h target linkname = do
  r <- withCString target $ \target -> withCString linkname $ \linkname -> withForeignPtr h (\p -> c_ln_s p target linkname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_ln_sf" c_ln_sf
  :: GuestfsP -> CString -> CString -> IO CInt

ln_sf :: GuestfsH -> String -> String -> IO ()
ln_sf h target linkname = do
  r <- withCString target $ \target -> withCString linkname $ \linkname -> withForeignPtr h (\p -> c_ln_sf p target linkname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_lremovexattr" c_lremovexattr
  :: GuestfsP -> CString -> CString -> IO CInt

lremovexattr :: GuestfsH -> String -> String -> IO ()
lremovexattr h xattr path = do
  r <- withCString xattr $ \xattr -> withCString path $ \path -> withForeignPtr h (\p -> c_lremovexattr p xattr path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_ls" c_ls
  :: GuestfsP -> CString -> IO (Ptr CString)

ls :: GuestfsH -> String -> IO [String]
ls h directory = do
  r <- withCString directory $ \directory -> withForeignPtr h (\p -> c_ls p directory)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_ls0" c_ls0
  :: GuestfsP -> CString -> CString -> IO CInt

ls0 :: GuestfsH -> String -> String -> IO ()
ls0 h dir filenames = do
  r <- withCString dir $ \dir -> withCString filenames $ \filenames -> withForeignPtr h (\p -> c_ls0 p dir filenames)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_lsetxattr" c_lsetxattr
  :: GuestfsP -> CString -> CString -> CInt -> CString -> IO CInt

lsetxattr :: GuestfsH -> String -> String -> Int -> String -> IO ()
lsetxattr h xattr val vallen path = do
  r <- withCString xattr $ \xattr -> withCString val $ \val -> withCString path $ \path -> withForeignPtr h (\p -> c_lsetxattr p xattr val (fromIntegral vallen) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_luks_add_key" c_luks_add_key
  :: GuestfsP -> CString -> CString -> CString -> CInt -> IO CInt

luks_add_key :: GuestfsH -> String -> String -> String -> Int -> IO ()
luks_add_key h device key newkey keyslot = do
  r <- withCString device $ \device -> withCString key $ \key -> withCString newkey $ \newkey -> withForeignPtr h (\p -> c_luks_add_key p device key newkey (fromIntegral keyslot))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_luks_close" c_luks_close
  :: GuestfsP -> CString -> IO CInt

luks_close :: GuestfsH -> String -> IO ()
luks_close h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_luks_close p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_luks_format" c_luks_format
  :: GuestfsP -> CString -> CString -> CInt -> IO CInt

luks_format :: GuestfsH -> String -> String -> Int -> IO ()
luks_format h device key keyslot = do
  r <- withCString device $ \device -> withCString key $ \key -> withForeignPtr h (\p -> c_luks_format p device key (fromIntegral keyslot))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_luks_format_cipher" c_luks_format_cipher
  :: GuestfsP -> CString -> CString -> CInt -> CString -> IO CInt

luks_format_cipher :: GuestfsH -> String -> String -> Int -> String -> IO ()
luks_format_cipher h device key keyslot cipher = do
  r <- withCString device $ \device -> withCString key $ \key -> withCString cipher $ \cipher -> withForeignPtr h (\p -> c_luks_format_cipher p device key (fromIntegral keyslot) cipher)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_luks_kill_slot" c_luks_kill_slot
  :: GuestfsP -> CString -> CString -> CInt -> IO CInt

luks_kill_slot :: GuestfsH -> String -> String -> Int -> IO ()
luks_kill_slot h device key keyslot = do
  r <- withCString device $ \device -> withCString key $ \key -> withForeignPtr h (\p -> c_luks_kill_slot p device key (fromIntegral keyslot))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_luks_open" c_luks_open
  :: GuestfsP -> CString -> CString -> CString -> IO CInt

luks_open :: GuestfsH -> String -> String -> String -> IO ()
luks_open h device key mapname = do
  r <- withCString device $ \device -> withCString key $ \key -> withCString mapname $ \mapname -> withForeignPtr h (\p -> c_luks_open p device key mapname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_luks_open_ro" c_luks_open_ro
  :: GuestfsP -> CString -> CString -> CString -> IO CInt

luks_open_ro :: GuestfsH -> String -> String -> String -> IO ()
luks_open_ro h device key mapname = do
  r <- withCString device $ \device -> withCString key $ \key -> withCString mapname $ \mapname -> withForeignPtr h (\p -> c_luks_open_ro p device key mapname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_lvcreate" c_lvcreate
  :: GuestfsP -> CString -> CString -> CInt -> IO CInt

lvcreate :: GuestfsH -> String -> String -> Int -> IO ()
lvcreate h logvol volgroup mbytes = do
  r <- withCString logvol $ \logvol -> withCString volgroup $ \volgroup -> withForeignPtr h (\p -> c_lvcreate p logvol volgroup (fromIntegral mbytes))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_lvcreate_free" c_lvcreate_free
  :: GuestfsP -> CString -> CString -> CInt -> IO CInt

lvcreate_free :: GuestfsH -> String -> String -> Int -> IO ()
lvcreate_free h logvol volgroup percent = do
  r <- withCString logvol $ \logvol -> withCString volgroup $ \volgroup -> withForeignPtr h (\p -> c_lvcreate_free p logvol volgroup (fromIntegral percent))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_lvm_canonical_lv_name" c_lvm_canonical_lv_name
  :: GuestfsP -> CString -> IO CString

lvm_canonical_lv_name :: GuestfsH -> String -> IO String
lvm_canonical_lv_name h lvname = do
  r <- withCString lvname $ \lvname -> withForeignPtr h (\p -> c_lvm_canonical_lv_name p lvname)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_lvm_clear_filter" c_lvm_clear_filter
  :: GuestfsP -> IO CInt

lvm_clear_filter :: GuestfsH -> IO ()
lvm_clear_filter h = do
  r <- withForeignPtr h (\p -> c_lvm_clear_filter p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_lvm_remove_all" c_lvm_remove_all
  :: GuestfsP -> IO CInt

lvm_remove_all :: GuestfsH -> IO ()
lvm_remove_all h = do
  r <- withForeignPtr h (\p -> c_lvm_remove_all p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_lvm_set_filter" c_lvm_set_filter
  :: GuestfsP -> Ptr CString -> IO CInt

lvm_set_filter :: GuestfsH -> [String] -> IO ()
lvm_set_filter h devices = do
  r <- withMany withCString devices $ \devices -> withArray0 nullPtr devices $ \devices -> withForeignPtr h (\p -> c_lvm_set_filter p devices)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_lvremove" c_lvremove
  :: GuestfsP -> CString -> IO CInt

lvremove :: GuestfsH -> String -> IO ()
lvremove h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_lvremove p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_lvrename" c_lvrename
  :: GuestfsP -> CString -> CString -> IO CInt

lvrename :: GuestfsH -> String -> String -> IO ()
lvrename h logvol newlogvol = do
  r <- withCString logvol $ \logvol -> withCString newlogvol $ \newlogvol -> withForeignPtr h (\p -> c_lvrename p logvol newlogvol)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_lvresize" c_lvresize
  :: GuestfsP -> CString -> CInt -> IO CInt

lvresize :: GuestfsH -> String -> Int -> IO ()
lvresize h device mbytes = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_lvresize p device (fromIntegral mbytes))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_lvresize_free" c_lvresize_free
  :: GuestfsP -> CString -> CInt -> IO CInt

lvresize_free :: GuestfsH -> String -> Int -> IO ()
lvresize_free h lv percent = do
  r <- withCString lv $ \lv -> withForeignPtr h (\p -> c_lvresize_free p lv (fromIntegral percent))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_lvs" c_lvs
  :: GuestfsP -> IO (Ptr CString)

lvs :: GuestfsH -> IO [String]
lvs h = do
  r <- withForeignPtr h (\p -> c_lvs p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_lvuuid" c_lvuuid
  :: GuestfsP -> CString -> IO CString

lvuuid :: GuestfsH -> String -> IO String
lvuuid h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_lvuuid p device)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_max_disks" c_max_disks
  :: GuestfsP -> IO CInt

max_disks :: GuestfsH -> IO Int
max_disks h = do
  r <- withForeignPtr h (\p -> c_max_disks p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_md_detail" c_md_detail
  :: GuestfsP -> CString -> IO (Ptr CString)

md_detail :: GuestfsH -> String -> IO [(String, String)]
md_detail h md = do
  r <- withCString md $ \md -> withForeignPtr h (\p -> c_md_detail p md)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else do
      arr <- peekArray0 nullPtr r
      arr <- mapM peekCString arr
      return (assocListOfHashtable arr)

foreign import ccall unsafe "guestfs.h guestfs_md_stop" c_md_stop
  :: GuestfsP -> CString -> IO CInt

md_stop :: GuestfsH -> String -> IO ()
md_stop h md = do
  r <- withCString md $ \md -> withForeignPtr h (\p -> c_md_stop p md)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mkdir" c_mkdir
  :: GuestfsP -> CString -> IO CInt

mkdir :: GuestfsH -> String -> IO ()
mkdir h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mkdir p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mkdir_mode" c_mkdir_mode
  :: GuestfsP -> CString -> CInt -> IO CInt

mkdir_mode :: GuestfsH -> String -> Int -> IO ()
mkdir_mode h path mode = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mkdir_mode p path (fromIntegral mode))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mkdir_p" c_mkdir_p
  :: GuestfsP -> CString -> IO CInt

mkdir_p :: GuestfsH -> String -> IO ()
mkdir_p h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mkdir_p p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mkdtemp" c_mkdtemp
  :: GuestfsP -> CString -> IO CString

mkdtemp :: GuestfsH -> String -> IO String
mkdtemp h tmpl = do
  r <- withCString tmpl $ \tmpl -> withForeignPtr h (\p -> c_mkdtemp p tmpl)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_mke2fs_J" c_mke2fs_J
  :: GuestfsP -> CString -> CInt -> CString -> CString -> IO CInt

mke2fs_J :: GuestfsH -> String -> Int -> String -> String -> IO ()
mke2fs_J h fstype blocksize device journal = do
  r <- withCString fstype $ \fstype -> withCString device $ \device -> withCString journal $ \journal -> withForeignPtr h (\p -> c_mke2fs_J p fstype (fromIntegral blocksize) device journal)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mke2fs_JL" c_mke2fs_JL
  :: GuestfsP -> CString -> CInt -> CString -> CString -> IO CInt

mke2fs_JL :: GuestfsH -> String -> Int -> String -> String -> IO ()
mke2fs_JL h fstype blocksize device label = do
  r <- withCString fstype $ \fstype -> withCString device $ \device -> withCString label $ \label -> withForeignPtr h (\p -> c_mke2fs_JL p fstype (fromIntegral blocksize) device label)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mke2fs_JU" c_mke2fs_JU
  :: GuestfsP -> CString -> CInt -> CString -> CString -> IO CInt

mke2fs_JU :: GuestfsH -> String -> Int -> String -> String -> IO ()
mke2fs_JU h fstype blocksize device uuid = do
  r <- withCString fstype $ \fstype -> withCString device $ \device -> withCString uuid $ \uuid -> withForeignPtr h (\p -> c_mke2fs_JU p fstype (fromIntegral blocksize) device uuid)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mke2journal" c_mke2journal
  :: GuestfsP -> CInt -> CString -> IO CInt

mke2journal :: GuestfsH -> Int -> String -> IO ()
mke2journal h blocksize device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_mke2journal p (fromIntegral blocksize) device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mke2journal_L" c_mke2journal_L
  :: GuestfsP -> CInt -> CString -> CString -> IO CInt

mke2journal_L :: GuestfsH -> Int -> String -> String -> IO ()
mke2journal_L h blocksize label device = do
  r <- withCString label $ \label -> withCString device $ \device -> withForeignPtr h (\p -> c_mke2journal_L p (fromIntegral blocksize) label device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mke2journal_U" c_mke2journal_U
  :: GuestfsP -> CInt -> CString -> CString -> IO CInt

mke2journal_U :: GuestfsH -> Int -> String -> String -> IO ()
mke2journal_U h blocksize uuid device = do
  r <- withCString uuid $ \uuid -> withCString device $ \device -> withForeignPtr h (\p -> c_mke2journal_U p (fromIntegral blocksize) uuid device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mkfifo" c_mkfifo
  :: GuestfsP -> CInt -> CString -> IO CInt

mkfifo :: GuestfsH -> Int -> String -> IO ()
mkfifo h mode path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mkfifo p (fromIntegral mode) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mkfs_b" c_mkfs_b
  :: GuestfsP -> CString -> CInt -> CString -> IO CInt

mkfs_b :: GuestfsH -> String -> Int -> String -> IO ()
mkfs_b h fstype blocksize device = do
  r <- withCString fstype $ \fstype -> withCString device $ \device -> withForeignPtr h (\p -> c_mkfs_b p fstype (fromIntegral blocksize) device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mklost_and_found" c_mklost_and_found
  :: GuestfsP -> CString -> IO CInt

mklost_and_found :: GuestfsH -> String -> IO ()
mklost_and_found h mountpoint = do
  r <- withCString mountpoint $ \mountpoint -> withForeignPtr h (\p -> c_mklost_and_found p mountpoint)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mkmountpoint" c_mkmountpoint
  :: GuestfsP -> CString -> IO CInt

mkmountpoint :: GuestfsH -> String -> IO ()
mkmountpoint h exemptpath = do
  r <- withCString exemptpath $ \exemptpath -> withForeignPtr h (\p -> c_mkmountpoint p exemptpath)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mknod" c_mknod
  :: GuestfsP -> CInt -> CInt -> CInt -> CString -> IO CInt

mknod :: GuestfsH -> Int -> Int -> Int -> String -> IO ()
mknod h mode devmajor devminor path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mknod p (fromIntegral mode) (fromIntegral devmajor) (fromIntegral devminor) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mknod_b" c_mknod_b
  :: GuestfsP -> CInt -> CInt -> CInt -> CString -> IO CInt

mknod_b :: GuestfsH -> Int -> Int -> Int -> String -> IO ()
mknod_b h mode devmajor devminor path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mknod_b p (fromIntegral mode) (fromIntegral devmajor) (fromIntegral devminor) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mknod_c" c_mknod_c
  :: GuestfsP -> CInt -> CInt -> CInt -> CString -> IO CInt

mknod_c :: GuestfsH -> Int -> Int -> Int -> String -> IO ()
mknod_c h mode devmajor devminor path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mknod_c p (fromIntegral mode) (fromIntegral devmajor) (fromIntegral devminor) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mkswap_L" c_mkswap_L
  :: GuestfsP -> CString -> CString -> IO CInt

mkswap_L :: GuestfsH -> String -> String -> IO ()
mkswap_L h label device = do
  r <- withCString label $ \label -> withCString device $ \device -> withForeignPtr h (\p -> c_mkswap_L p label device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mkswap_U" c_mkswap_U
  :: GuestfsP -> CString -> CString -> IO CInt

mkswap_U :: GuestfsH -> String -> String -> IO ()
mkswap_U h uuid device = do
  r <- withCString uuid $ \uuid -> withCString device $ \device -> withForeignPtr h (\p -> c_mkswap_U p uuid device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mkswap_file" c_mkswap_file
  :: GuestfsP -> CString -> IO CInt

mkswap_file :: GuestfsH -> String -> IO ()
mkswap_file h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mkswap_file p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_modprobe" c_modprobe
  :: GuestfsP -> CString -> IO CInt

modprobe :: GuestfsH -> String -> IO ()
modprobe h modulename = do
  r <- withCString modulename $ \modulename -> withForeignPtr h (\p -> c_modprobe p modulename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mount" c_mount
  :: GuestfsP -> CString -> CString -> IO CInt

mount :: GuestfsH -> String -> String -> IO ()
mount h mountable mountpoint = do
  r <- withCString mountable $ \mountable -> withCString mountpoint $ \mountpoint -> withForeignPtr h (\p -> c_mount p mountable mountpoint)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mount_local_run" c_mount_local_run
  :: GuestfsP -> IO CInt

mount_local_run :: GuestfsH -> IO ()
mount_local_run h = do
  r <- withForeignPtr h (\p -> c_mount_local_run p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mount_loop" c_mount_loop
  :: GuestfsP -> CString -> CString -> IO CInt

mount_loop :: GuestfsH -> String -> String -> IO ()
mount_loop h file mountpoint = do
  r <- withCString file $ \file -> withCString mountpoint $ \mountpoint -> withForeignPtr h (\p -> c_mount_loop p file mountpoint)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mount_options" c_mount_options
  :: GuestfsP -> CString -> CString -> CString -> IO CInt

mount_options :: GuestfsH -> String -> String -> String -> IO ()
mount_options h options mountable mountpoint = do
  r <- withCString options $ \options -> withCString mountable $ \mountable -> withCString mountpoint $ \mountpoint -> withForeignPtr h (\p -> c_mount_options p options mountable mountpoint)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mount_ro" c_mount_ro
  :: GuestfsP -> CString -> CString -> IO CInt

mount_ro :: GuestfsH -> String -> String -> IO ()
mount_ro h mountable mountpoint = do
  r <- withCString mountable $ \mountable -> withCString mountpoint $ \mountpoint -> withForeignPtr h (\p -> c_mount_ro p mountable mountpoint)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mount_vfs" c_mount_vfs
  :: GuestfsP -> CString -> CString -> CString -> CString -> IO CInt

mount_vfs :: GuestfsH -> String -> String -> String -> String -> IO ()
mount_vfs h options vfstype mountable mountpoint = do
  r <- withCString options $ \options -> withCString vfstype $ \vfstype -> withCString mountable $ \mountable -> withCString mountpoint $ \mountpoint -> withForeignPtr h (\p -> c_mount_vfs p options vfstype mountable mountpoint)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_mountpoints" c_mountpoints
  :: GuestfsP -> IO (Ptr CString)

mountpoints :: GuestfsH -> IO [(String, String)]
mountpoints h = do
  r <- withForeignPtr h (\p -> c_mountpoints p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else do
      arr <- peekArray0 nullPtr r
      arr <- mapM peekCString arr
      return (assocListOfHashtable arr)

foreign import ccall unsafe "guestfs.h guestfs_mounts" c_mounts
  :: GuestfsP -> IO (Ptr CString)

mounts :: GuestfsH -> IO [String]
mounts h = do
  r <- withForeignPtr h (\p -> c_mounts p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_mv" c_mv
  :: GuestfsP -> CString -> CString -> IO CInt

mv :: GuestfsH -> String -> String -> IO ()
mv h src dest = do
  r <- withCString src $ \src -> withCString dest $ \dest -> withForeignPtr h (\p -> c_mv p src dest)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_nr_devices" c_nr_devices
  :: GuestfsP -> IO CInt

nr_devices :: GuestfsH -> IO Int
nr_devices h = do
  r <- withForeignPtr h (\p -> c_nr_devices p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_ntfs_3g_probe" c_ntfs_3g_probe
  :: GuestfsP -> CInt -> CString -> IO CInt

ntfs_3g_probe :: GuestfsH -> Bool -> String -> IO Int
ntfs_3g_probe h rw device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_ntfs_3g_probe p (fromBool rw) device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_ntfsclone_in" c_ntfsclone_in
  :: GuestfsP -> CString -> CString -> IO CInt

ntfsclone_in :: GuestfsH -> String -> String -> IO ()
ntfsclone_in h backupfile device = do
  r <- withCString backupfile $ \backupfile -> withCString device $ \device -> withForeignPtr h (\p -> c_ntfsclone_in p backupfile device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_ntfsresize_size" c_ntfsresize_size
  :: GuestfsP -> CString -> Int64 -> IO CInt

ntfsresize_size :: GuestfsH -> String -> Integer -> IO ()
ntfsresize_size h device size = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_ntfsresize_size p device (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_parse_environment" c_parse_environment
  :: GuestfsP -> IO CInt

parse_environment :: GuestfsH -> IO ()
parse_environment h = do
  r <- withForeignPtr h (\p -> c_parse_environment p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_parse_environment_list" c_parse_environment_list
  :: GuestfsP -> Ptr CString -> IO CInt

parse_environment_list :: GuestfsH -> [String] -> IO ()
parse_environment_list h environment = do
  r <- withMany withCString environment $ \environment -> withArray0 nullPtr environment $ \environment -> withForeignPtr h (\p -> c_parse_environment_list p environment)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_part_add" c_part_add
  :: GuestfsP -> CString -> CString -> Int64 -> Int64 -> IO CInt

part_add :: GuestfsH -> String -> String -> Integer -> Integer -> IO ()
part_add h device prlogex startsect endsect = do
  r <- withCString device $ \device -> withCString prlogex $ \prlogex -> withForeignPtr h (\p -> c_part_add p device prlogex (fromIntegral startsect) (fromIntegral endsect))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_part_del" c_part_del
  :: GuestfsP -> CString -> CInt -> IO CInt

part_del :: GuestfsH -> String -> Int -> IO ()
part_del h device partnum = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_del p device (fromIntegral partnum))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_part_disk" c_part_disk
  :: GuestfsP -> CString -> CString -> IO CInt

part_disk :: GuestfsH -> String -> String -> IO ()
part_disk h device parttype = do
  r <- withCString device $ \device -> withCString parttype $ \parttype -> withForeignPtr h (\p -> c_part_disk p device parttype)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_part_get_bootable" c_part_get_bootable
  :: GuestfsP -> CString -> CInt -> IO CInt

part_get_bootable :: GuestfsH -> String -> Int -> IO Bool
part_get_bootable h device partnum = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_get_bootable p device (fromIntegral partnum))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (toBool r)

foreign import ccall unsafe "guestfs.h guestfs_part_get_gpt_guid" c_part_get_gpt_guid
  :: GuestfsP -> CString -> CInt -> IO CString

part_get_gpt_guid :: GuestfsH -> String -> Int -> IO String
part_get_gpt_guid h device partnum = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_get_gpt_guid p device (fromIntegral partnum))
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_part_get_gpt_type" c_part_get_gpt_type
  :: GuestfsP -> CString -> CInt -> IO CString

part_get_gpt_type :: GuestfsH -> String -> Int -> IO String
part_get_gpt_type h device partnum = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_get_gpt_type p device (fromIntegral partnum))
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_part_get_mbr_id" c_part_get_mbr_id
  :: GuestfsP -> CString -> CInt -> IO CInt

part_get_mbr_id :: GuestfsH -> String -> Int -> IO Int
part_get_mbr_id h device partnum = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_get_mbr_id p device (fromIntegral partnum))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_part_get_mbr_part_type" c_part_get_mbr_part_type
  :: GuestfsP -> CString -> CInt -> IO CString

part_get_mbr_part_type :: GuestfsH -> String -> Int -> IO String
part_get_mbr_part_type h device partnum = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_get_mbr_part_type p device (fromIntegral partnum))
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_part_get_name" c_part_get_name
  :: GuestfsP -> CString -> CInt -> IO CString

part_get_name :: GuestfsH -> String -> Int -> IO String
part_get_name h device partnum = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_get_name p device (fromIntegral partnum))
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_part_get_parttype" c_part_get_parttype
  :: GuestfsP -> CString -> IO CString

part_get_parttype :: GuestfsH -> String -> IO String
part_get_parttype h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_get_parttype p device)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_part_init" c_part_init
  :: GuestfsP -> CString -> CString -> IO CInt

part_init :: GuestfsH -> String -> String -> IO ()
part_init h device parttype = do
  r <- withCString device $ \device -> withCString parttype $ \parttype -> withForeignPtr h (\p -> c_part_init p device parttype)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_part_set_bootable" c_part_set_bootable
  :: GuestfsP -> CString -> CInt -> CInt -> IO CInt

part_set_bootable :: GuestfsH -> String -> Int -> Bool -> IO ()
part_set_bootable h device partnum bootable = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_set_bootable p device (fromIntegral partnum) (fromBool bootable))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_part_set_gpt_guid" c_part_set_gpt_guid
  :: GuestfsP -> CString -> CInt -> CString -> IO CInt

part_set_gpt_guid :: GuestfsH -> String -> Int -> String -> IO ()
part_set_gpt_guid h device partnum guid = do
  r <- withCString device $ \device -> withCString guid $ \guid -> withForeignPtr h (\p -> c_part_set_gpt_guid p device (fromIntegral partnum) guid)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_part_set_gpt_type" c_part_set_gpt_type
  :: GuestfsP -> CString -> CInt -> CString -> IO CInt

part_set_gpt_type :: GuestfsH -> String -> Int -> String -> IO ()
part_set_gpt_type h device partnum guid = do
  r <- withCString device $ \device -> withCString guid $ \guid -> withForeignPtr h (\p -> c_part_set_gpt_type p device (fromIntegral partnum) guid)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_part_set_mbr_id" c_part_set_mbr_id
  :: GuestfsP -> CString -> CInt -> CInt -> IO CInt

part_set_mbr_id :: GuestfsH -> String -> Int -> Int -> IO ()
part_set_mbr_id h device partnum idbyte = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_set_mbr_id p device (fromIntegral partnum) (fromIntegral idbyte))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_part_set_name" c_part_set_name
  :: GuestfsP -> CString -> CInt -> CString -> IO CInt

part_set_name :: GuestfsH -> String -> Int -> String -> IO ()
part_set_name h device partnum name = do
  r <- withCString device $ \device -> withCString name $ \name -> withForeignPtr h (\p -> c_part_set_name p device (fromIntegral partnum) name)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_part_to_dev" c_part_to_dev
  :: GuestfsP -> CString -> IO CString

part_to_dev :: GuestfsH -> String -> IO String
part_to_dev h partition = do
  r <- withCString partition $ \partition -> withForeignPtr h (\p -> c_part_to_dev p partition)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_part_to_partnum" c_part_to_partnum
  :: GuestfsP -> CString -> IO CInt

part_to_partnum :: GuestfsH -> String -> IO Int
part_to_partnum h partition = do
  r <- withCString partition $ \partition -> withForeignPtr h (\p -> c_part_to_partnum p partition)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_ping_daemon" c_ping_daemon
  :: GuestfsP -> IO CInt

ping_daemon :: GuestfsH -> IO ()
ping_daemon h = do
  r <- withForeignPtr h (\p -> c_ping_daemon p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_pvchange_uuid" c_pvchange_uuid
  :: GuestfsP -> CString -> IO CInt

pvchange_uuid :: GuestfsH -> String -> IO ()
pvchange_uuid h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_pvchange_uuid p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_pvchange_uuid_all" c_pvchange_uuid_all
  :: GuestfsP -> IO CInt

pvchange_uuid_all :: GuestfsH -> IO ()
pvchange_uuid_all h = do
  r <- withForeignPtr h (\p -> c_pvchange_uuid_all p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_pvcreate" c_pvcreate
  :: GuestfsP -> CString -> IO CInt

pvcreate :: GuestfsH -> String -> IO ()
pvcreate h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_pvcreate p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_pvremove" c_pvremove
  :: GuestfsP -> CString -> IO CInt

pvremove :: GuestfsH -> String -> IO ()
pvremove h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_pvremove p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_pvresize" c_pvresize
  :: GuestfsP -> CString -> IO CInt

pvresize :: GuestfsH -> String -> IO ()
pvresize h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_pvresize p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_pvresize_size" c_pvresize_size
  :: GuestfsP -> CString -> Int64 -> IO CInt

pvresize_size :: GuestfsH -> String -> Integer -> IO ()
pvresize_size h device size = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_pvresize_size p device (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_pvs" c_pvs
  :: GuestfsP -> IO (Ptr CString)

pvs :: GuestfsH -> IO [String]
pvs h = do
  r <- withForeignPtr h (\p -> c_pvs p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_pvuuid" c_pvuuid
  :: GuestfsP -> CString -> IO CString

pvuuid :: GuestfsH -> String -> IO String
pvuuid h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_pvuuid p device)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_pwrite" c_pwrite
  :: GuestfsP -> CString -> CString -> CInt -> Int64 -> IO CInt

pwrite :: GuestfsH -> String -> String -> Integer -> IO Int
pwrite h path content offset = do
  r <- withCString path $ \path -> withCStringLen content $ \(content, content_size) -> withForeignPtr h (\p -> c_pwrite p path content (fromIntegral content_size) (fromIntegral offset))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_pwrite_device" c_pwrite_device
  :: GuestfsP -> CString -> CString -> CInt -> Int64 -> IO CInt

pwrite_device :: GuestfsH -> String -> String -> Integer -> IO Int
pwrite_device h device content offset = do
  r <- withCString device $ \device -> withCStringLen content $ \(content, content_size) -> withForeignPtr h (\p -> c_pwrite_device p device content (fromIntegral content_size) (fromIntegral offset))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_read_lines" c_read_lines
  :: GuestfsP -> CString -> IO (Ptr CString)

read_lines :: GuestfsH -> String -> IO [String]
read_lines h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_read_lines p path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_readlink" c_readlink
  :: GuestfsP -> CString -> IO CString

readlink :: GuestfsH -> String -> IO String
readlink h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_readlink p path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_readlinklist" c_readlinklist
  :: GuestfsP -> CString -> Ptr CString -> IO (Ptr CString)

readlinklist :: GuestfsH -> String -> [String] -> IO [String]
readlinklist h path names = do
  r <- withCString path $ \path -> withMany withCString names $ \names -> withArray0 nullPtr names $ \names -> withForeignPtr h (\p -> c_readlinklist p path names)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_realpath" c_realpath
  :: GuestfsP -> CString -> IO CString

realpath :: GuestfsH -> String -> IO String
realpath h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_realpath p path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_remove_drive" c_remove_drive
  :: GuestfsP -> CString -> IO CInt

remove_drive :: GuestfsH -> String -> IO ()
remove_drive h label = do
  r <- withCString label $ \label -> withForeignPtr h (\p -> c_remove_drive p label)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_removexattr" c_removexattr
  :: GuestfsP -> CString -> CString -> IO CInt

removexattr :: GuestfsH -> String -> String -> IO ()
removexattr h xattr path = do
  r <- withCString xattr $ \xattr -> withCString path $ \path -> withForeignPtr h (\p -> c_removexattr p xattr path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_rename" c_rename
  :: GuestfsP -> CString -> CString -> IO CInt

rename :: GuestfsH -> String -> String -> IO ()
rename h oldpath newpath = do
  r <- withCString oldpath $ \oldpath -> withCString newpath $ \newpath -> withForeignPtr h (\p -> c_rename p oldpath newpath)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_resize2fs" c_resize2fs
  :: GuestfsP -> CString -> IO CInt

resize2fs :: GuestfsH -> String -> IO ()
resize2fs h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_resize2fs p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_resize2fs_M" c_resize2fs_M
  :: GuestfsP -> CString -> IO CInt

resize2fs_M :: GuestfsH -> String -> IO ()
resize2fs_M h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_resize2fs_M p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_resize2fs_size" c_resize2fs_size
  :: GuestfsP -> CString -> Int64 -> IO CInt

resize2fs_size :: GuestfsH -> String -> Integer -> IO ()
resize2fs_size h device size = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_resize2fs_size p device (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_rm" c_rm
  :: GuestfsP -> CString -> IO CInt

rm :: GuestfsH -> String -> IO ()
rm h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_rm p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_rm_f" c_rm_f
  :: GuestfsP -> CString -> IO CInt

rm_f :: GuestfsH -> String -> IO ()
rm_f h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_rm_f p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_rm_rf" c_rm_rf
  :: GuestfsP -> CString -> IO CInt

rm_rf :: GuestfsH -> String -> IO ()
rm_rf h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_rm_rf p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_rmdir" c_rmdir
  :: GuestfsP -> CString -> IO CInt

rmdir :: GuestfsH -> String -> IO ()
rmdir h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_rmdir p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_rmmountpoint" c_rmmountpoint
  :: GuestfsP -> CString -> IO CInt

rmmountpoint :: GuestfsH -> String -> IO ()
rmmountpoint h exemptpath = do
  r <- withCString exemptpath $ \exemptpath -> withForeignPtr h (\p -> c_rmmountpoint p exemptpath)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_scrub_device" c_scrub_device
  :: GuestfsP -> CString -> IO CInt

scrub_device :: GuestfsH -> String -> IO ()
scrub_device h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_scrub_device p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_scrub_file" c_scrub_file
  :: GuestfsP -> CString -> IO CInt

scrub_file :: GuestfsH -> String -> IO ()
scrub_file h file = do
  r <- withCString file $ \file -> withForeignPtr h (\p -> c_scrub_file p file)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_scrub_freespace" c_scrub_freespace
  :: GuestfsP -> CString -> IO CInt

scrub_freespace :: GuestfsH -> String -> IO ()
scrub_freespace h dir = do
  r <- withCString dir $ \dir -> withForeignPtr h (\p -> c_scrub_freespace p dir)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_append" c_set_append
  :: GuestfsP -> CString -> IO CInt

set_append :: GuestfsH -> Maybe String -> IO ()
set_append h append = do
  r <- maybeWith withCString append $ \append -> withForeignPtr h (\p -> c_set_append p append)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_attach_method" c_set_attach_method
  :: GuestfsP -> CString -> IO CInt

set_attach_method :: GuestfsH -> String -> IO ()
set_attach_method h backend = do
  r <- withCString backend $ \backend -> withForeignPtr h (\p -> c_set_attach_method p backend)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_autosync" c_set_autosync
  :: GuestfsP -> CInt -> IO CInt

set_autosync :: GuestfsH -> Bool -> IO ()
set_autosync h autosync = do
  r <- withForeignPtr h (\p -> c_set_autosync p (fromBool autosync))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_backend" c_set_backend
  :: GuestfsP -> CString -> IO CInt

set_backend :: GuestfsH -> String -> IO ()
set_backend h backend = do
  r <- withCString backend $ \backend -> withForeignPtr h (\p -> c_set_backend p backend)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_backend_setting" c_set_backend_setting
  :: GuestfsP -> CString -> CString -> IO CInt

set_backend_setting :: GuestfsH -> String -> String -> IO ()
set_backend_setting h name val = do
  r <- withCString name $ \name -> withCString val $ \val -> withForeignPtr h (\p -> c_set_backend_setting p name val)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_backend_settings" c_set_backend_settings
  :: GuestfsP -> Ptr CString -> IO CInt

set_backend_settings :: GuestfsH -> [String] -> IO ()
set_backend_settings h settings = do
  r <- withMany withCString settings $ \settings -> withArray0 nullPtr settings $ \settings -> withForeignPtr h (\p -> c_set_backend_settings p settings)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_cachedir" c_set_cachedir
  :: GuestfsP -> CString -> IO CInt

set_cachedir :: GuestfsH -> Maybe String -> IO ()
set_cachedir h cachedir = do
  r <- maybeWith withCString cachedir $ \cachedir -> withForeignPtr h (\p -> c_set_cachedir p cachedir)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_direct" c_set_direct
  :: GuestfsP -> CInt -> IO CInt

set_direct :: GuestfsH -> Bool -> IO ()
set_direct h direct = do
  r <- withForeignPtr h (\p -> c_set_direct p (fromBool direct))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_e2generation" c_set_e2generation
  :: GuestfsP -> CString -> Int64 -> IO CInt

set_e2generation :: GuestfsH -> String -> Integer -> IO ()
set_e2generation h file generation = do
  r <- withCString file $ \file -> withForeignPtr h (\p -> c_set_e2generation p file (fromIntegral generation))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_e2label" c_set_e2label
  :: GuestfsP -> CString -> CString -> IO CInt

set_e2label :: GuestfsH -> String -> String -> IO ()
set_e2label h device label = do
  r <- withCString device $ \device -> withCString label $ \label -> withForeignPtr h (\p -> c_set_e2label p device label)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_e2uuid" c_set_e2uuid
  :: GuestfsP -> CString -> CString -> IO CInt

set_e2uuid :: GuestfsH -> String -> String -> IO ()
set_e2uuid h device uuid = do
  r <- withCString device $ \device -> withCString uuid $ \uuid -> withForeignPtr h (\p -> c_set_e2uuid p device uuid)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_hv" c_set_hv
  :: GuestfsP -> CString -> IO CInt

set_hv :: GuestfsH -> String -> IO ()
set_hv h hv = do
  r <- withCString hv $ \hv -> withForeignPtr h (\p -> c_set_hv p hv)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_identifier" c_set_identifier
  :: GuestfsP -> CString -> IO CInt

set_identifier :: GuestfsH -> String -> IO ()
set_identifier h identifier = do
  r <- withCString identifier $ \identifier -> withForeignPtr h (\p -> c_set_identifier p identifier)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_label" c_set_label
  :: GuestfsP -> CString -> CString -> IO CInt

set_label :: GuestfsH -> String -> String -> IO ()
set_label h mountable label = do
  r <- withCString mountable $ \mountable -> withCString label $ \label -> withForeignPtr h (\p -> c_set_label p mountable label)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_libvirt_requested_credential" c_set_libvirt_requested_credential
  :: GuestfsP -> CInt -> CString -> CInt -> IO CInt

set_libvirt_requested_credential :: GuestfsH -> Int -> String -> IO ()
set_libvirt_requested_credential h index cred = do
  r <- withCStringLen cred $ \(cred, cred_size) -> withForeignPtr h (\p -> c_set_libvirt_requested_credential p (fromIntegral index) cred (fromIntegral cred_size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_libvirt_supported_credentials" c_set_libvirt_supported_credentials
  :: GuestfsP -> Ptr CString -> IO CInt

set_libvirt_supported_credentials :: GuestfsH -> [String] -> IO ()
set_libvirt_supported_credentials h creds = do
  r <- withMany withCString creds $ \creds -> withArray0 nullPtr creds $ \creds -> withForeignPtr h (\p -> c_set_libvirt_supported_credentials p creds)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_memsize" c_set_memsize
  :: GuestfsP -> CInt -> IO CInt

set_memsize :: GuestfsH -> Int -> IO ()
set_memsize h memsize = do
  r <- withForeignPtr h (\p -> c_set_memsize p (fromIntegral memsize))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_network" c_set_network
  :: GuestfsP -> CInt -> IO CInt

set_network :: GuestfsH -> Bool -> IO ()
set_network h network = do
  r <- withForeignPtr h (\p -> c_set_network p (fromBool network))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_path" c_set_path
  :: GuestfsP -> CString -> IO CInt

set_path :: GuestfsH -> Maybe String -> IO ()
set_path h searchpath = do
  r <- maybeWith withCString searchpath $ \searchpath -> withForeignPtr h (\p -> c_set_path p searchpath)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_pgroup" c_set_pgroup
  :: GuestfsP -> CInt -> IO CInt

set_pgroup :: GuestfsH -> Bool -> IO ()
set_pgroup h pgroup = do
  r <- withForeignPtr h (\p -> c_set_pgroup p (fromBool pgroup))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_program" c_set_program
  :: GuestfsP -> CString -> IO CInt

set_program :: GuestfsH -> String -> IO ()
set_program h program = do
  r <- withCString program $ \program -> withForeignPtr h (\p -> c_set_program p program)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_qemu" c_set_qemu
  :: GuestfsP -> CString -> IO CInt

set_qemu :: GuestfsH -> Maybe String -> IO ()
set_qemu h hv = do
  r <- maybeWith withCString hv $ \hv -> withForeignPtr h (\p -> c_set_qemu p hv)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_recovery_proc" c_set_recovery_proc
  :: GuestfsP -> CInt -> IO CInt

set_recovery_proc :: GuestfsH -> Bool -> IO ()
set_recovery_proc h recoveryproc = do
  r <- withForeignPtr h (\p -> c_set_recovery_proc p (fromBool recoveryproc))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_selinux" c_set_selinux
  :: GuestfsP -> CInt -> IO CInt

set_selinux :: GuestfsH -> Bool -> IO ()
set_selinux h selinux = do
  r <- withForeignPtr h (\p -> c_set_selinux p (fromBool selinux))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_smp" c_set_smp
  :: GuestfsP -> CInt -> IO CInt

set_smp :: GuestfsH -> Int -> IO ()
set_smp h smp = do
  r <- withForeignPtr h (\p -> c_set_smp p (fromIntegral smp))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_tmpdir" c_set_tmpdir
  :: GuestfsP -> CString -> IO CInt

set_tmpdir :: GuestfsH -> Maybe String -> IO ()
set_tmpdir h tmpdir = do
  r <- maybeWith withCString tmpdir $ \tmpdir -> withForeignPtr h (\p -> c_set_tmpdir p tmpdir)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_trace" c_set_trace
  :: GuestfsP -> CInt -> IO CInt

set_trace :: GuestfsH -> Bool -> IO ()
set_trace h trace = do
  r <- withForeignPtr h (\p -> c_set_trace p (fromBool trace))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_uuid" c_set_uuid
  :: GuestfsP -> CString -> CString -> IO CInt

set_uuid :: GuestfsH -> String -> String -> IO ()
set_uuid h device uuid = do
  r <- withCString device $ \device -> withCString uuid $ \uuid -> withForeignPtr h (\p -> c_set_uuid p device uuid)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_uuid_random" c_set_uuid_random
  :: GuestfsP -> CString -> IO CInt

set_uuid_random :: GuestfsH -> String -> IO ()
set_uuid_random h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_set_uuid_random p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_set_verbose" c_set_verbose
  :: GuestfsP -> CInt -> IO CInt

set_verbose :: GuestfsH -> Bool -> IO ()
set_verbose h verbose = do
  r <- withForeignPtr h (\p -> c_set_verbose p (fromBool verbose))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_setcon" c_setcon
  :: GuestfsP -> CString -> IO CInt

setcon :: GuestfsH -> String -> IO ()
setcon h context = do
  r <- withCString context $ \context -> withForeignPtr h (\p -> c_setcon p context)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_setxattr" c_setxattr
  :: GuestfsP -> CString -> CString -> CInt -> CString -> IO CInt

setxattr :: GuestfsH -> String -> String -> Int -> String -> IO ()
setxattr h xattr val vallen path = do
  r <- withCString xattr $ \xattr -> withCString val $ \val -> withCString path $ \path -> withForeignPtr h (\p -> c_setxattr p xattr val (fromIntegral vallen) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_sfdisk" c_sfdisk
  :: GuestfsP -> CString -> CInt -> CInt -> CInt -> Ptr CString -> IO CInt

sfdisk :: GuestfsH -> String -> Int -> Int -> Int -> [String] -> IO ()
sfdisk h device cyls heads sectors lines = do
  r <- withCString device $ \device -> withMany withCString lines $ \lines -> withArray0 nullPtr lines $ \lines -> withForeignPtr h (\p -> c_sfdisk p device (fromIntegral cyls) (fromIntegral heads) (fromIntegral sectors) lines)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_sfdiskM" c_sfdiskM
  :: GuestfsP -> CString -> Ptr CString -> IO CInt

sfdiskM :: GuestfsH -> String -> [String] -> IO ()
sfdiskM h device lines = do
  r <- withCString device $ \device -> withMany withCString lines $ \lines -> withArray0 nullPtr lines $ \lines -> withForeignPtr h (\p -> c_sfdiskM p device lines)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_sfdisk_N" c_sfdisk_N
  :: GuestfsP -> CString -> CInt -> CInt -> CInt -> CInt -> CString -> IO CInt

sfdisk_N :: GuestfsH -> String -> Int -> Int -> Int -> Int -> String -> IO ()
sfdisk_N h device partnum cyls heads sectors line = do
  r <- withCString device $ \device -> withCString line $ \line -> withForeignPtr h (\p -> c_sfdisk_N p device (fromIntegral partnum) (fromIntegral cyls) (fromIntegral heads) (fromIntegral sectors) line)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_sfdisk_disk_geometry" c_sfdisk_disk_geometry
  :: GuestfsP -> CString -> IO CString

sfdisk_disk_geometry :: GuestfsH -> String -> IO String
sfdisk_disk_geometry h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_sfdisk_disk_geometry p device)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_sfdisk_kernel_geometry" c_sfdisk_kernel_geometry
  :: GuestfsP -> CString -> IO CString

sfdisk_kernel_geometry :: GuestfsH -> String -> IO String
sfdisk_kernel_geometry h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_sfdisk_kernel_geometry p device)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_sfdisk_l" c_sfdisk_l
  :: GuestfsP -> CString -> IO CString

sfdisk_l :: GuestfsH -> String -> IO String
sfdisk_l h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_sfdisk_l p device)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_sh" c_sh
  :: GuestfsP -> CString -> IO CString

sh :: GuestfsH -> String -> IO String
sh h command = do
  r <- withCString command $ \command -> withForeignPtr h (\p -> c_sh p command)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_sh_lines" c_sh_lines
  :: GuestfsP -> CString -> IO (Ptr CString)

sh_lines :: GuestfsH -> String -> IO [String]
sh_lines h command = do
  r <- withCString command $ \command -> withForeignPtr h (\p -> c_sh_lines p command)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_shutdown" c_shutdown
  :: GuestfsP -> IO CInt

shutdown :: GuestfsH -> IO ()
shutdown h = do
  r <- withForeignPtr h (\p -> c_shutdown p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_sleep" c_sleep
  :: GuestfsP -> CInt -> IO CInt

sleep :: GuestfsH -> Int -> IO ()
sleep h secs = do
  r <- withForeignPtr h (\p -> c_sleep p (fromIntegral secs))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_strings" c_strings
  :: GuestfsP -> CString -> IO (Ptr CString)

strings :: GuestfsH -> String -> IO [String]
strings h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_strings p path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_strings_e" c_strings_e
  :: GuestfsP -> CString -> CString -> IO (Ptr CString)

strings_e :: GuestfsH -> String -> String -> IO [String]
strings_e h encoding path = do
  r <- withCString encoding $ \encoding -> withCString path $ \path -> withForeignPtr h (\p -> c_strings_e p encoding path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_swapoff_device" c_swapoff_device
  :: GuestfsP -> CString -> IO CInt

swapoff_device :: GuestfsH -> String -> IO ()
swapoff_device h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_swapoff_device p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_swapoff_file" c_swapoff_file
  :: GuestfsP -> CString -> IO CInt

swapoff_file :: GuestfsH -> String -> IO ()
swapoff_file h file = do
  r <- withCString file $ \file -> withForeignPtr h (\p -> c_swapoff_file p file)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_swapoff_label" c_swapoff_label
  :: GuestfsP -> CString -> IO CInt

swapoff_label :: GuestfsH -> String -> IO ()
swapoff_label h label = do
  r <- withCString label $ \label -> withForeignPtr h (\p -> c_swapoff_label p label)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_swapoff_uuid" c_swapoff_uuid
  :: GuestfsP -> CString -> IO CInt

swapoff_uuid :: GuestfsH -> String -> IO ()
swapoff_uuid h uuid = do
  r <- withCString uuid $ \uuid -> withForeignPtr h (\p -> c_swapoff_uuid p uuid)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_swapon_device" c_swapon_device
  :: GuestfsP -> CString -> IO CInt

swapon_device :: GuestfsH -> String -> IO ()
swapon_device h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_swapon_device p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_swapon_file" c_swapon_file
  :: GuestfsP -> CString -> IO CInt

swapon_file :: GuestfsH -> String -> IO ()
swapon_file h file = do
  r <- withCString file $ \file -> withForeignPtr h (\p -> c_swapon_file p file)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_swapon_label" c_swapon_label
  :: GuestfsP -> CString -> IO CInt

swapon_label :: GuestfsH -> String -> IO ()
swapon_label h label = do
  r <- withCString label $ \label -> withForeignPtr h (\p -> c_swapon_label p label)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_swapon_uuid" c_swapon_uuid
  :: GuestfsP -> CString -> IO CInt

swapon_uuid :: GuestfsH -> String -> IO ()
swapon_uuid h uuid = do
  r <- withCString uuid $ \uuid -> withForeignPtr h (\p -> c_swapon_uuid p uuid)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_sync" c_sync
  :: GuestfsP -> IO CInt

sync :: GuestfsH -> IO ()
sync h = do
  r <- withForeignPtr h (\p -> c_sync p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_tail" c_tail
  :: GuestfsP -> CString -> IO (Ptr CString)

tail :: GuestfsH -> String -> IO [String]
tail h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_tail p path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_tail_n" c_tail_n
  :: GuestfsP -> CInt -> CString -> IO (Ptr CString)

tail_n :: GuestfsH -> Int -> String -> IO [String]
tail_n h nrlines path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_tail_n p (fromIntegral nrlines) path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_tgz_in" c_tgz_in
  :: GuestfsP -> CString -> CString -> IO CInt

tgz_in :: GuestfsH -> String -> String -> IO ()
tgz_in h tarball directory = do
  r <- withCString tarball $ \tarball -> withCString directory $ \directory -> withForeignPtr h (\p -> c_tgz_in p tarball directory)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_tgz_out" c_tgz_out
  :: GuestfsP -> CString -> CString -> IO CInt

tgz_out :: GuestfsH -> String -> String -> IO ()
tgz_out h directory tarball = do
  r <- withCString directory $ \directory -> withCString tarball $ \tarball -> withForeignPtr h (\p -> c_tgz_out p directory tarball)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_touch" c_touch
  :: GuestfsP -> CString -> IO CInt

touch :: GuestfsH -> String -> IO ()
touch h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_touch p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_truncate" c_truncate
  :: GuestfsP -> CString -> IO CInt

truncate :: GuestfsH -> String -> IO ()
truncate h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_truncate p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_truncate_size" c_truncate_size
  :: GuestfsP -> CString -> Int64 -> IO CInt

truncate_size :: GuestfsH -> String -> Integer -> IO ()
truncate_size h path size = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_truncate_size p path (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_tune2fs_l" c_tune2fs_l
  :: GuestfsP -> CString -> IO (Ptr CString)

tune2fs_l :: GuestfsH -> String -> IO [(String, String)]
tune2fs_l h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_tune2fs_l p device)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else do
      arr <- peekArray0 nullPtr r
      arr <- mapM peekCString arr
      return (assocListOfHashtable arr)

foreign import ccall unsafe "guestfs.h guestfs_txz_in" c_txz_in
  :: GuestfsP -> CString -> CString -> IO CInt

txz_in :: GuestfsH -> String -> String -> IO ()
txz_in h tarball directory = do
  r <- withCString tarball $ \tarball -> withCString directory $ \directory -> withForeignPtr h (\p -> c_txz_in p tarball directory)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_txz_out" c_txz_out
  :: GuestfsP -> CString -> CString -> IO CInt

txz_out :: GuestfsH -> String -> String -> IO ()
txz_out h directory tarball = do
  r <- withCString directory $ \directory -> withCString tarball $ \tarball -> withForeignPtr h (\p -> c_txz_out p directory tarball)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_umask" c_umask
  :: GuestfsP -> CInt -> IO CInt

umask :: GuestfsH -> Int -> IO Int
umask h mask = do
  r <- withForeignPtr h (\p -> c_umask p (fromIntegral mask))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_umount_all" c_umount_all
  :: GuestfsP -> IO CInt

umount_all :: GuestfsH -> IO ()
umount_all h = do
  r <- withForeignPtr h (\p -> c_umount_all p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_upload" c_upload
  :: GuestfsP -> CString -> CString -> IO CInt

upload :: GuestfsH -> String -> String -> IO ()
upload h filename remotefilename = do
  r <- withCString filename $ \filename -> withCString remotefilename $ \remotefilename -> withForeignPtr h (\p -> c_upload p filename remotefilename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_upload_offset" c_upload_offset
  :: GuestfsP -> CString -> CString -> Int64 -> IO CInt

upload_offset :: GuestfsH -> String -> String -> Integer -> IO ()
upload_offset h filename remotefilename offset = do
  r <- withCString filename $ \filename -> withCString remotefilename $ \remotefilename -> withForeignPtr h (\p -> c_upload_offset p filename remotefilename (fromIntegral offset))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_user_cancel" c_user_cancel
  :: GuestfsP -> IO CInt

user_cancel :: GuestfsH -> IO ()
user_cancel h = do
  r <- withForeignPtr h (\p -> c_user_cancel p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_utimens" c_utimens
  :: GuestfsP -> CString -> Int64 -> Int64 -> Int64 -> Int64 -> IO CInt

utimens :: GuestfsH -> String -> Integer -> Integer -> Integer -> Integer -> IO ()
utimens h path atsecs atnsecs mtsecs mtnsecs = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_utimens p path (fromIntegral atsecs) (fromIntegral atnsecs) (fromIntegral mtsecs) (fromIntegral mtnsecs))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_vfs_label" c_vfs_label
  :: GuestfsP -> CString -> IO CString

vfs_label :: GuestfsH -> String -> IO String
vfs_label h mountable = do
  r <- withCString mountable $ \mountable -> withForeignPtr h (\p -> c_vfs_label p mountable)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_vfs_minimum_size" c_vfs_minimum_size
  :: GuestfsP -> CString -> IO Int64

vfs_minimum_size :: GuestfsH -> String -> IO Int64
vfs_minimum_size h mountable = do
  r <- withCString mountable $ \mountable -> withForeignPtr h (\p -> c_vfs_minimum_size p mountable)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_vfs_type" c_vfs_type
  :: GuestfsP -> CString -> IO CString

vfs_type :: GuestfsH -> String -> IO String
vfs_type h mountable = do
  r <- withCString mountable $ \mountable -> withForeignPtr h (\p -> c_vfs_type p mountable)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_vfs_uuid" c_vfs_uuid
  :: GuestfsP -> CString -> IO CString

vfs_uuid :: GuestfsH -> String -> IO String
vfs_uuid h mountable = do
  r <- withCString mountable $ \mountable -> withForeignPtr h (\p -> c_vfs_uuid p mountable)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_vg_activate" c_vg_activate
  :: GuestfsP -> CInt -> Ptr CString -> IO CInt

vg_activate :: GuestfsH -> Bool -> [String] -> IO ()
vg_activate h activate volgroups = do
  r <- withMany withCString volgroups $ \volgroups -> withArray0 nullPtr volgroups $ \volgroups -> withForeignPtr h (\p -> c_vg_activate p (fromBool activate) volgroups)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_vg_activate_all" c_vg_activate_all
  :: GuestfsP -> CInt -> IO CInt

vg_activate_all :: GuestfsH -> Bool -> IO ()
vg_activate_all h activate = do
  r <- withForeignPtr h (\p -> c_vg_activate_all p (fromBool activate))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_vgchange_uuid" c_vgchange_uuid
  :: GuestfsP -> CString -> IO CInt

vgchange_uuid :: GuestfsH -> String -> IO ()
vgchange_uuid h vg = do
  r <- withCString vg $ \vg -> withForeignPtr h (\p -> c_vgchange_uuid p vg)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_vgchange_uuid_all" c_vgchange_uuid_all
  :: GuestfsP -> IO CInt

vgchange_uuid_all :: GuestfsH -> IO ()
vgchange_uuid_all h = do
  r <- withForeignPtr h (\p -> c_vgchange_uuid_all p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_vgcreate" c_vgcreate
  :: GuestfsP -> CString -> Ptr CString -> IO CInt

vgcreate :: GuestfsH -> String -> [String] -> IO ()
vgcreate h volgroup physvols = do
  r <- withCString volgroup $ \volgroup -> withMany withCString physvols $ \physvols -> withArray0 nullPtr physvols $ \physvols -> withForeignPtr h (\p -> c_vgcreate p volgroup physvols)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_vglvuuids" c_vglvuuids
  :: GuestfsP -> CString -> IO (Ptr CString)

vglvuuids :: GuestfsH -> String -> IO [String]
vglvuuids h vgname = do
  r <- withCString vgname $ \vgname -> withForeignPtr h (\p -> c_vglvuuids p vgname)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_vgpvuuids" c_vgpvuuids
  :: GuestfsP -> CString -> IO (Ptr CString)

vgpvuuids :: GuestfsH -> String -> IO [String]
vgpvuuids h vgname = do
  r <- withCString vgname $ \vgname -> withForeignPtr h (\p -> c_vgpvuuids p vgname)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_vgremove" c_vgremove
  :: GuestfsP -> CString -> IO CInt

vgremove :: GuestfsH -> String -> IO ()
vgremove h vgname = do
  r <- withCString vgname $ \vgname -> withForeignPtr h (\p -> c_vgremove p vgname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_vgrename" c_vgrename
  :: GuestfsP -> CString -> CString -> IO CInt

vgrename :: GuestfsH -> String -> String -> IO ()
vgrename h volgroup newvolgroup = do
  r <- withCString volgroup $ \volgroup -> withCString newvolgroup $ \newvolgroup -> withForeignPtr h (\p -> c_vgrename p volgroup newvolgroup)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_vgs" c_vgs
  :: GuestfsP -> IO (Ptr CString)

vgs :: GuestfsH -> IO [String]
vgs h = do
  r <- withForeignPtr h (\p -> c_vgs p)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_vgscan" c_vgscan
  :: GuestfsP -> IO CInt

vgscan :: GuestfsH -> IO ()
vgscan h = do
  r <- withForeignPtr h (\p -> c_vgscan p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_vguuid" c_vguuid
  :: GuestfsP -> CString -> IO CString

vguuid :: GuestfsH -> String -> IO String
vguuid h vgname = do
  r <- withCString vgname $ \vgname -> withForeignPtr h (\p -> c_vguuid p vgname)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_wait_ready" c_wait_ready
  :: GuestfsP -> IO CInt

wait_ready :: GuestfsH -> IO ()
wait_ready h = do
  r <- withForeignPtr h (\p -> c_wait_ready p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_wc_c" c_wc_c
  :: GuestfsP -> CString -> IO CInt

wc_c :: GuestfsH -> String -> IO Int
wc_c h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_wc_c p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_wc_l" c_wc_l
  :: GuestfsP -> CString -> IO CInt

wc_l :: GuestfsH -> String -> IO Int
wc_l h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_wc_l p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_wc_w" c_wc_w
  :: GuestfsP -> CString -> IO CInt

wc_w :: GuestfsH -> String -> IO Int
wc_w h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_wc_w p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs.h guestfs_wipefs" c_wipefs
  :: GuestfsP -> CString -> IO CInt

wipefs :: GuestfsH -> String -> IO ()
wipefs h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_wipefs p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_write" c_write
  :: GuestfsP -> CString -> CString -> CInt -> IO CInt

write :: GuestfsH -> String -> String -> IO ()
write h path content = do
  r <- withCString path $ \path -> withCStringLen content $ \(content, content_size) -> withForeignPtr h (\p -> c_write p path content (fromIntegral content_size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_write_append" c_write_append
  :: GuestfsP -> CString -> CString -> CInt -> IO CInt

write_append :: GuestfsH -> String -> String -> IO ()
write_append h path content = do
  r <- withCString path $ \path -> withCStringLen content $ \(content, content_size) -> withForeignPtr h (\p -> c_write_append p path content (fromIntegral content_size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_write_file" c_write_file
  :: GuestfsP -> CString -> CString -> CInt -> IO CInt

write_file :: GuestfsH -> String -> String -> Int -> IO ()
write_file h path content size = do
  r <- withCString path $ \path -> withCString content $ \content -> withForeignPtr h (\p -> c_write_file p path content (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_zegrep" c_zegrep
  :: GuestfsP -> CString -> CString -> IO (Ptr CString)

zegrep :: GuestfsH -> String -> String -> IO [String]
zegrep h regex path = do
  r <- withCString regex $ \regex -> withCString path $ \path -> withForeignPtr h (\p -> c_zegrep p regex path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_zegrepi" c_zegrepi
  :: GuestfsP -> CString -> CString -> IO (Ptr CString)

zegrepi :: GuestfsH -> String -> String -> IO [String]
zegrepi h regex path = do
  r <- withCString regex $ \regex -> withCString path $ \path -> withForeignPtr h (\p -> c_zegrepi p regex path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_zero" c_zero
  :: GuestfsP -> CString -> IO CInt

zero :: GuestfsH -> String -> IO ()
zero h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_zero p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_zero_device" c_zero_device
  :: GuestfsP -> CString -> IO CInt

zero_device :: GuestfsH -> String -> IO ()
zero_device h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_zero_device p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_zero_free_space" c_zero_free_space
  :: GuestfsP -> CString -> IO CInt

zero_free_space :: GuestfsH -> String -> IO ()
zero_free_space h directory = do
  r <- withCString directory $ \directory -> withForeignPtr h (\p -> c_zero_free_space p directory)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_zerofree" c_zerofree
  :: GuestfsP -> CString -> IO CInt

zerofree :: GuestfsH -> String -> IO ()
zerofree h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_zerofree p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs.h guestfs_zfgrep" c_zfgrep
  :: GuestfsP -> CString -> CString -> IO (Ptr CString)

zfgrep :: GuestfsH -> String -> String -> IO [String]
zfgrep h pattern path = do
  r <- withCString pattern $ \pattern -> withCString path $ \path -> withForeignPtr h (\p -> c_zfgrep p pattern path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_zfgrepi" c_zfgrepi
  :: GuestfsP -> CString -> CString -> IO (Ptr CString)

zfgrepi :: GuestfsH -> String -> String -> IO [String]
zfgrepi h pattern path = do
  r <- withCString pattern $ \pattern -> withCString path $ \path -> withForeignPtr h (\p -> c_zfgrepi p pattern path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_zfile" c_zfile
  :: GuestfsP -> CString -> CString -> IO CString

zfile :: GuestfsH -> String -> String -> IO String
zfile h meth path = do
  r <- withCString meth $ \meth -> withCString path $ \path -> withForeignPtr h (\p -> c_zfile p meth path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekCString r

foreign import ccall unsafe "guestfs.h guestfs_zgrep" c_zgrep
  :: GuestfsP -> CString -> CString -> IO (Ptr CString)

zgrep :: GuestfsH -> String -> String -> IO [String]
zgrep h regex path = do
  r <- withCString regex $ \regex -> withCString path $ \path -> withForeignPtr h (\p -> c_zgrep p regex path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

foreign import ccall unsafe "guestfs.h guestfs_zgrepi" c_zgrepi
  :: GuestfsP -> CString -> CString -> IO (Ptr CString)

zgrepi :: GuestfsH -> String -> String -> IO [String]
zgrepi h regex path = do
  r <- withCString regex $ \regex -> withCString path $ \path -> withForeignPtr h (\p -> c_zgrepi p regex path)
  if (r == nullPtr)
    then do
      err <- last_error h
      fail err
    else peekArray0 nullPtr r >>= mapM peekCString

