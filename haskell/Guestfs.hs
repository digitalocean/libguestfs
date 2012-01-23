{- libguestfs generated file
   WARNING: THIS FILE IS GENERATED FROM:
     generator/generator_*.ml
   ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
  
   Copyright (C) 2009-2012 Red Hat Inc.
  
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

{-# INCLUDE <guestfs.h> #-}
{-# LANGUAGE ForeignFunctionInterface #-}

module Guestfs (
  create,
  test0rint,
  test0rinterr,
  test0rint64,
  test0rint64err,
  launch,
  wait_ready,
  kill_subprocess,
  add_drive,
  add_cdrom,
  add_drive_ro,
  config,
  set_qemu,
  set_path,
  set_append,
  set_autosync,
  set_verbose,
  get_state,
  set_memsize,
  get_memsize,
  get_pid,
  set_selinux,
  set_trace,
  set_direct,
  set_recovery_proc,
  add_drive_with_if,
  add_drive_ro_with_if,
  inspect_get_major_version,
  inspect_get_minor_version,
  set_network,
  set_attach_method,
  set_pgroup,
  set_smp,
  get_smp,
  mount,
  sync,
  touch,
  aug_init,
  aug_close,
  aug_defvar,
  aug_set,
  aug_insert,
  aug_rm,
  aug_mv,
  aug_save,
  aug_load,
  rm,
  rmdir,
  rm_rf,
  mkdir,
  mkdir_p,
  chmod,
  chown,
  pvcreate,
  vgcreate,
  lvcreate,
  mkfs,
  sfdisk,
  write_file,
  umount,
  umount_all,
  lvm_remove_all,
  blockdev_setro,
  blockdev_setrw,
  blockdev_getss,
  blockdev_getbsz,
  blockdev_setbsz,
  blockdev_getsz,
  blockdev_getsize64,
  blockdev_flushbufs,
  blockdev_rereadpt,
  upload,
  download,
  tar_in,
  tar_out,
  tgz_in,
  tgz_out,
  mount_ro,
  mount_options,
  mount_vfs,
  lvremove,
  vgremove,
  pvremove,
  set_e2label,
  set_e2uuid,
  fsck,
  zero,
  grub_install,
  cp,
  cp_a,
  mv,
  drop_caches,
  ping_daemon,
  zerofree,
  pvresize,
  sfdisk_N,
  vg_activate_all,
  vg_activate,
  lvresize,
  resize2fs,
  e2fsck_f,
  sleep,
  ntfs_3g_probe,
  scrub_device,
  scrub_file,
  scrub_freespace,
  wc_l,
  wc_w,
  wc_c,
  du,
  mount_loop,
  mkswap,
  mkswap_L,
  mkswap_U,
  mknod,
  mkfifo,
  mknod_b,
  mknod_c,
  umask,
  sfdiskM,
  setxattr,
  lsetxattr,
  removexattr,
  lremovexattr,
  mkmountpoint,
  rmmountpoint,
  ln,
  ln_f,
  ln_s,
  ln_sf,
  fallocate,
  swapon_device,
  swapoff_device,
  swapon_file,
  swapoff_file,
  swapon_label,
  swapoff_label,
  swapon_uuid,
  swapoff_uuid,
  mkswap_file,
  inotify_init,
  inotify_add_watch,
  inotify_rm_watch,
  inotify_close,
  setcon,
  mkfs_b,
  mke2journal,
  mke2journal_L,
  mke2journal_U,
  mke2fs_J,
  mke2fs_JL,
  mke2fs_JU,
  modprobe,
  find0,
  truncate,
  truncate_size,
  utimens,
  mkdir_mode,
  lchown,
  part_init,
  part_add,
  part_disk,
  part_set_bootable,
  part_set_name,
  fill,
  available,
  dd,
  filesize,
  lvrename,
  vgrename,
  copy_size,
  zero_device,
  txz_in,
  txz_out,
  ntfsresize,
  vgscan,
  part_del,
  part_get_mbr_id,
  part_set_mbr_id,
  lvresize_free,
  aug_clear,
  get_umask,
  debug_upload,
  base64_in,
  base64_out,
  checksums_out,
  fill_pattern,
  write,
  pwrite,
  resize2fs_size,
  pvresize_size,
  ntfsresize_size,
  fallocate64,
  lvm_set_filter,
  lvm_clear_filter,
  luks_open,
  luks_open_ro,
  luks_close,
  luks_format,
  luks_format_cipher,
  luks_add_key,
  luks_kill_slot,
  upload_offset,
  download_offset,
  pwrite_device,
  resize2fs_M,
  internal_autosync,
  write_append,
  part_to_partnum,
  md_stop
  ) where

-- Unfortunately some symbols duplicate ones already present
-- in Prelude.  We don't know which, so we hard-code a list
-- here.
import Prelude hiding (truncate)

import Foreign
import Foreign.C
import Foreign.C.Types
import System.IO
import Control.Exception
import Data.Typeable

data GuestfsS = GuestfsS            -- represents the opaque C struct
type GuestfsP = Ptr GuestfsS        -- guestfs_h *
type GuestfsH = ForeignPtr GuestfsS -- guestfs_h * with attached finalizer

-- XXX define properly later XXX
data PV = PV
data VG = VG
data LV = LV
data IntBool = IntBool
data Stat = Stat
data StatVFS = StatVFS
data Hashtable = Hashtable

foreign import ccall unsafe "guestfs_create" c_create
  :: IO GuestfsP
foreign import ccall unsafe "&guestfs_close" c_close
  :: FunPtr (GuestfsP -> IO ())
foreign import ccall unsafe "guestfs_set_error_handler" c_set_error_handler
  :: GuestfsP -> Ptr CInt -> Ptr CInt -> IO ()

create :: IO GuestfsH
create = do
  p <- c_create
  c_set_error_handler p nullPtr nullPtr
  h <- newForeignPtr c_close p
  return h

foreign import ccall unsafe "guestfs_last_error" c_last_error
  :: GuestfsP -> IO CString

-- last_error :: GuestfsH -> IO (Maybe String)
-- last_error h = do
--   str <- withForeignPtr h (\p -> c_last_error p)
--   maybePeek peekCString str

last_error :: GuestfsH -> IO (String)
last_error h = do
  str <- withForeignPtr h (\p -> c_last_error p)
  if (str == nullPtr)
    then return "no error"
    else peekCString str

foreign import ccall unsafe "guestfs_test0rint" c_test0rint
  :: GuestfsP -> CString -> IO (CInt)

test0rint :: GuestfsH -> String -> IO (Int)
test0rint h val = do
  r <- withCString val $ \val -> withForeignPtr h (\p -> c_test0rint p val)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_test0rinterr" c_test0rinterr
  :: GuestfsP -> IO (CInt)

test0rinterr :: GuestfsH -> IO (Int)
test0rinterr h = do
  r <- withForeignPtr h (\p -> c_test0rinterr p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_test0rint64" c_test0rint64
  :: GuestfsP -> CString -> IO (Int64)

test0rint64 :: GuestfsH -> String -> IO (Integer)
test0rint64 h val = do
  r <- withCString val $ \val -> withForeignPtr h (\p -> c_test0rint64 p val)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_test0rint64err" c_test0rint64err
  :: GuestfsP -> IO (Int64)

test0rint64err :: GuestfsH -> IO (Integer)
test0rint64err h = do
  r <- withForeignPtr h (\p -> c_test0rint64err p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_launch" c_launch
  :: GuestfsP -> IO (CInt)

launch :: GuestfsH -> IO ()
launch h = do
  r <- withForeignPtr h (\p -> c_launch p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_wait_ready" c_wait_ready
  :: GuestfsP -> IO (CInt)

wait_ready :: GuestfsH -> IO ()
wait_ready h = do
  r <- withForeignPtr h (\p -> c_wait_ready p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_kill_subprocess" c_kill_subprocess
  :: GuestfsP -> IO (CInt)

kill_subprocess :: GuestfsH -> IO ()
kill_subprocess h = do
  r <- withForeignPtr h (\p -> c_kill_subprocess p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_add_drive" c_add_drive
  :: GuestfsP -> CString -> IO (CInt)

add_drive :: GuestfsH -> String -> IO ()
add_drive h filename = do
  r <- withCString filename $ \filename -> withForeignPtr h (\p -> c_add_drive p filename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_add_cdrom" c_add_cdrom
  :: GuestfsP -> CString -> IO (CInt)

add_cdrom :: GuestfsH -> String -> IO ()
add_cdrom h filename = do
  r <- withCString filename $ \filename -> withForeignPtr h (\p -> c_add_cdrom p filename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_add_drive_ro" c_add_drive_ro
  :: GuestfsP -> CString -> IO (CInt)

add_drive_ro :: GuestfsH -> String -> IO ()
add_drive_ro h filename = do
  r <- withCString filename $ \filename -> withForeignPtr h (\p -> c_add_drive_ro p filename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_config" c_config
  :: GuestfsP -> CString -> CString -> IO (CInt)

config :: GuestfsH -> String -> Maybe String -> IO ()
config h qemuparam qemuvalue = do
  r <- withCString qemuparam $ \qemuparam -> maybeWith withCString qemuvalue $ \qemuvalue -> withForeignPtr h (\p -> c_config p qemuparam qemuvalue)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_set_qemu" c_set_qemu
  :: GuestfsP -> CString -> IO (CInt)

set_qemu :: GuestfsH -> Maybe String -> IO ()
set_qemu h qemu = do
  r <- maybeWith withCString qemu $ \qemu -> withForeignPtr h (\p -> c_set_qemu p qemu)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_set_path" c_set_path
  :: GuestfsP -> CString -> IO (CInt)

set_path :: GuestfsH -> Maybe String -> IO ()
set_path h searchpath = do
  r <- maybeWith withCString searchpath $ \searchpath -> withForeignPtr h (\p -> c_set_path p searchpath)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_set_append" c_set_append
  :: GuestfsP -> CString -> IO (CInt)

set_append :: GuestfsH -> Maybe String -> IO ()
set_append h append = do
  r <- maybeWith withCString append $ \append -> withForeignPtr h (\p -> c_set_append p append)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_set_autosync" c_set_autosync
  :: GuestfsP -> CInt -> IO (CInt)

set_autosync :: GuestfsH -> Bool -> IO ()
set_autosync h autosync = do
  r <- withForeignPtr h (\p -> c_set_autosync p (fromBool autosync))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_set_verbose" c_set_verbose
  :: GuestfsP -> CInt -> IO (CInt)

set_verbose :: GuestfsH -> Bool -> IO ()
set_verbose h verbose = do
  r <- withForeignPtr h (\p -> c_set_verbose p (fromBool verbose))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_get_state" c_get_state
  :: GuestfsP -> IO (CInt)

get_state :: GuestfsH -> IO (Int)
get_state h = do
  r <- withForeignPtr h (\p -> c_get_state p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_set_memsize" c_set_memsize
  :: GuestfsP -> CInt -> IO (CInt)

set_memsize :: GuestfsH -> Int -> IO ()
set_memsize h memsize = do
  r <- withForeignPtr h (\p -> c_set_memsize p (fromIntegral memsize))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_get_memsize" c_get_memsize
  :: GuestfsP -> IO (CInt)

get_memsize :: GuestfsH -> IO (Int)
get_memsize h = do
  r <- withForeignPtr h (\p -> c_get_memsize p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_get_pid" c_get_pid
  :: GuestfsP -> IO (CInt)

get_pid :: GuestfsH -> IO (Int)
get_pid h = do
  r <- withForeignPtr h (\p -> c_get_pid p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_set_selinux" c_set_selinux
  :: GuestfsP -> CInt -> IO (CInt)

set_selinux :: GuestfsH -> Bool -> IO ()
set_selinux h selinux = do
  r <- withForeignPtr h (\p -> c_set_selinux p (fromBool selinux))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_set_trace" c_set_trace
  :: GuestfsP -> CInt -> IO (CInt)

set_trace :: GuestfsH -> Bool -> IO ()
set_trace h trace = do
  r <- withForeignPtr h (\p -> c_set_trace p (fromBool trace))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_set_direct" c_set_direct
  :: GuestfsP -> CInt -> IO (CInt)

set_direct :: GuestfsH -> Bool -> IO ()
set_direct h direct = do
  r <- withForeignPtr h (\p -> c_set_direct p (fromBool direct))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_set_recovery_proc" c_set_recovery_proc
  :: GuestfsP -> CInt -> IO (CInt)

set_recovery_proc :: GuestfsH -> Bool -> IO ()
set_recovery_proc h recoveryproc = do
  r <- withForeignPtr h (\p -> c_set_recovery_proc p (fromBool recoveryproc))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_add_drive_with_if" c_add_drive_with_if
  :: GuestfsP -> CString -> CString -> IO (CInt)

add_drive_with_if :: GuestfsH -> String -> String -> IO ()
add_drive_with_if h filename iface = do
  r <- withCString filename $ \filename -> withCString iface $ \iface -> withForeignPtr h (\p -> c_add_drive_with_if p filename iface)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_add_drive_ro_with_if" c_add_drive_ro_with_if
  :: GuestfsP -> CString -> CString -> IO (CInt)

add_drive_ro_with_if :: GuestfsH -> String -> String -> IO ()
add_drive_ro_with_if h filename iface = do
  r <- withCString filename $ \filename -> withCString iface $ \iface -> withForeignPtr h (\p -> c_add_drive_ro_with_if p filename iface)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_inspect_get_major_version" c_inspect_get_major_version
  :: GuestfsP -> CString -> IO (CInt)

inspect_get_major_version :: GuestfsH -> String -> IO (Int)
inspect_get_major_version h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_major_version p root)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_inspect_get_minor_version" c_inspect_get_minor_version
  :: GuestfsP -> CString -> IO (CInt)

inspect_get_minor_version :: GuestfsH -> String -> IO (Int)
inspect_get_minor_version h root = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_inspect_get_minor_version p root)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_set_network" c_set_network
  :: GuestfsP -> CInt -> IO (CInt)

set_network :: GuestfsH -> Bool -> IO ()
set_network h network = do
  r <- withForeignPtr h (\p -> c_set_network p (fromBool network))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_set_attach_method" c_set_attach_method
  :: GuestfsP -> CString -> IO (CInt)

set_attach_method :: GuestfsH -> String -> IO ()
set_attach_method h attachmethod = do
  r <- withCString attachmethod $ \attachmethod -> withForeignPtr h (\p -> c_set_attach_method p attachmethod)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_set_pgroup" c_set_pgroup
  :: GuestfsP -> CInt -> IO (CInt)

set_pgroup :: GuestfsH -> Bool -> IO ()
set_pgroup h pgroup = do
  r <- withForeignPtr h (\p -> c_set_pgroup p (fromBool pgroup))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_set_smp" c_set_smp
  :: GuestfsP -> CInt -> IO (CInt)

set_smp :: GuestfsH -> Int -> IO ()
set_smp h smp = do
  r <- withForeignPtr h (\p -> c_set_smp p (fromIntegral smp))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_get_smp" c_get_smp
  :: GuestfsP -> IO (CInt)

get_smp :: GuestfsH -> IO (Int)
get_smp h = do
  r <- withForeignPtr h (\p -> c_get_smp p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_mount" c_mount
  :: GuestfsP -> CString -> CString -> IO (CInt)

mount :: GuestfsH -> String -> String -> IO ()
mount h device mountpoint = do
  r <- withCString device $ \device -> withCString mountpoint $ \mountpoint -> withForeignPtr h (\p -> c_mount p device mountpoint)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_sync" c_sync
  :: GuestfsP -> IO (CInt)

sync :: GuestfsH -> IO ()
sync h = do
  r <- withForeignPtr h (\p -> c_sync p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_touch" c_touch
  :: GuestfsP -> CString -> IO (CInt)

touch :: GuestfsH -> String -> IO ()
touch h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_touch p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_aug_init" c_aug_init
  :: GuestfsP -> CString -> CInt -> IO (CInt)

aug_init :: GuestfsH -> String -> Int -> IO ()
aug_init h root flags = do
  r <- withCString root $ \root -> withForeignPtr h (\p -> c_aug_init p root (fromIntegral flags))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_aug_close" c_aug_close
  :: GuestfsP -> IO (CInt)

aug_close :: GuestfsH -> IO ()
aug_close h = do
  r <- withForeignPtr h (\p -> c_aug_close p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_aug_defvar" c_aug_defvar
  :: GuestfsP -> CString -> CString -> IO (CInt)

aug_defvar :: GuestfsH -> String -> Maybe String -> IO (Int)
aug_defvar h name expr = do
  r <- withCString name $ \name -> maybeWith withCString expr $ \expr -> withForeignPtr h (\p -> c_aug_defvar p name expr)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_aug_set" c_aug_set
  :: GuestfsP -> CString -> CString -> IO (CInt)

aug_set :: GuestfsH -> String -> String -> IO ()
aug_set h augpath val = do
  r <- withCString augpath $ \augpath -> withCString val $ \val -> withForeignPtr h (\p -> c_aug_set p augpath val)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_aug_insert" c_aug_insert
  :: GuestfsP -> CString -> CString -> CInt -> IO (CInt)

aug_insert :: GuestfsH -> String -> String -> Bool -> IO ()
aug_insert h augpath label before = do
  r <- withCString augpath $ \augpath -> withCString label $ \label -> withForeignPtr h (\p -> c_aug_insert p augpath label (fromBool before))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_aug_rm" c_aug_rm
  :: GuestfsP -> CString -> IO (CInt)

aug_rm :: GuestfsH -> String -> IO (Int)
aug_rm h augpath = do
  r <- withCString augpath $ \augpath -> withForeignPtr h (\p -> c_aug_rm p augpath)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_aug_mv" c_aug_mv
  :: GuestfsP -> CString -> CString -> IO (CInt)

aug_mv :: GuestfsH -> String -> String -> IO ()
aug_mv h src dest = do
  r <- withCString src $ \src -> withCString dest $ \dest -> withForeignPtr h (\p -> c_aug_mv p src dest)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_aug_save" c_aug_save
  :: GuestfsP -> IO (CInt)

aug_save :: GuestfsH -> IO ()
aug_save h = do
  r <- withForeignPtr h (\p -> c_aug_save p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_aug_load" c_aug_load
  :: GuestfsP -> IO (CInt)

aug_load :: GuestfsH -> IO ()
aug_load h = do
  r <- withForeignPtr h (\p -> c_aug_load p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_rm" c_rm
  :: GuestfsP -> CString -> IO (CInt)

rm :: GuestfsH -> String -> IO ()
rm h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_rm p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_rmdir" c_rmdir
  :: GuestfsP -> CString -> IO (CInt)

rmdir :: GuestfsH -> String -> IO ()
rmdir h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_rmdir p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_rm_rf" c_rm_rf
  :: GuestfsP -> CString -> IO (CInt)

rm_rf :: GuestfsH -> String -> IO ()
rm_rf h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_rm_rf p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mkdir" c_mkdir
  :: GuestfsP -> CString -> IO (CInt)

mkdir :: GuestfsH -> String -> IO ()
mkdir h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mkdir p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mkdir_p" c_mkdir_p
  :: GuestfsP -> CString -> IO (CInt)

mkdir_p :: GuestfsH -> String -> IO ()
mkdir_p h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mkdir_p p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_chmod" c_chmod
  :: GuestfsP -> CInt -> CString -> IO (CInt)

chmod :: GuestfsH -> Int -> String -> IO ()
chmod h mode path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_chmod p (fromIntegral mode) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_chown" c_chown
  :: GuestfsP -> CInt -> CInt -> CString -> IO (CInt)

chown :: GuestfsH -> Int -> Int -> String -> IO ()
chown h owner group path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_chown p (fromIntegral owner) (fromIntegral group) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_pvcreate" c_pvcreate
  :: GuestfsP -> CString -> IO (CInt)

pvcreate :: GuestfsH -> String -> IO ()
pvcreate h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_pvcreate p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_vgcreate" c_vgcreate
  :: GuestfsP -> CString -> Ptr CString -> IO (CInt)

vgcreate :: GuestfsH -> String -> [String] -> IO ()
vgcreate h volgroup physvols = do
  r <- withCString volgroup $ \volgroup -> withMany withCString physvols $ \physvols -> withArray0 nullPtr physvols $ \physvols -> withForeignPtr h (\p -> c_vgcreate p volgroup physvols)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_lvcreate" c_lvcreate
  :: GuestfsP -> CString -> CString -> CInt -> IO (CInt)

lvcreate :: GuestfsH -> String -> String -> Int -> IO ()
lvcreate h logvol volgroup mbytes = do
  r <- withCString logvol $ \logvol -> withCString volgroup $ \volgroup -> withForeignPtr h (\p -> c_lvcreate p logvol volgroup (fromIntegral mbytes))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mkfs" c_mkfs
  :: GuestfsP -> CString -> CString -> IO (CInt)

mkfs :: GuestfsH -> String -> String -> IO ()
mkfs h fstype device = do
  r <- withCString fstype $ \fstype -> withCString device $ \device -> withForeignPtr h (\p -> c_mkfs p fstype device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_sfdisk" c_sfdisk
  :: GuestfsP -> CString -> CInt -> CInt -> CInt -> Ptr CString -> IO (CInt)

sfdisk :: GuestfsH -> String -> Int -> Int -> Int -> [String] -> IO ()
sfdisk h device cyls heads sectors lines = do
  r <- withCString device $ \device -> withMany withCString lines $ \lines -> withArray0 nullPtr lines $ \lines -> withForeignPtr h (\p -> c_sfdisk p device (fromIntegral cyls) (fromIntegral heads) (fromIntegral sectors) lines)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_write_file" c_write_file
  :: GuestfsP -> CString -> CString -> CInt -> IO (CInt)

write_file :: GuestfsH -> String -> String -> Int -> IO ()
write_file h path content size = do
  r <- withCString path $ \path -> withCString content $ \content -> withForeignPtr h (\p -> c_write_file p path content (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_umount" c_umount
  :: GuestfsP -> CString -> IO (CInt)

umount :: GuestfsH -> String -> IO ()
umount h pathordevice = do
  r <- withCString pathordevice $ \pathordevice -> withForeignPtr h (\p -> c_umount p pathordevice)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_umount_all" c_umount_all
  :: GuestfsP -> IO (CInt)

umount_all :: GuestfsH -> IO ()
umount_all h = do
  r <- withForeignPtr h (\p -> c_umount_all p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_lvm_remove_all" c_lvm_remove_all
  :: GuestfsP -> IO (CInt)

lvm_remove_all :: GuestfsH -> IO ()
lvm_remove_all h = do
  r <- withForeignPtr h (\p -> c_lvm_remove_all p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_blockdev_setro" c_blockdev_setro
  :: GuestfsP -> CString -> IO (CInt)

blockdev_setro :: GuestfsH -> String -> IO ()
blockdev_setro h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_setro p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_blockdev_setrw" c_blockdev_setrw
  :: GuestfsP -> CString -> IO (CInt)

blockdev_setrw :: GuestfsH -> String -> IO ()
blockdev_setrw h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_setrw p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_blockdev_getss" c_blockdev_getss
  :: GuestfsP -> CString -> IO (CInt)

blockdev_getss :: GuestfsH -> String -> IO (Int)
blockdev_getss h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_getss p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_blockdev_getbsz" c_blockdev_getbsz
  :: GuestfsP -> CString -> IO (CInt)

blockdev_getbsz :: GuestfsH -> String -> IO (Int)
blockdev_getbsz h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_getbsz p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_blockdev_setbsz" c_blockdev_setbsz
  :: GuestfsP -> CString -> CInt -> IO (CInt)

blockdev_setbsz :: GuestfsH -> String -> Int -> IO ()
blockdev_setbsz h device blocksize = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_setbsz p device (fromIntegral blocksize))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_blockdev_getsz" c_blockdev_getsz
  :: GuestfsP -> CString -> IO (Int64)

blockdev_getsz :: GuestfsH -> String -> IO (Integer)
blockdev_getsz h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_getsz p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_blockdev_getsize64" c_blockdev_getsize64
  :: GuestfsP -> CString -> IO (Int64)

blockdev_getsize64 :: GuestfsH -> String -> IO (Integer)
blockdev_getsize64 h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_getsize64 p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_blockdev_flushbufs" c_blockdev_flushbufs
  :: GuestfsP -> CString -> IO (CInt)

blockdev_flushbufs :: GuestfsH -> String -> IO ()
blockdev_flushbufs h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_flushbufs p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_blockdev_rereadpt" c_blockdev_rereadpt
  :: GuestfsP -> CString -> IO (CInt)

blockdev_rereadpt :: GuestfsH -> String -> IO ()
blockdev_rereadpt h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_blockdev_rereadpt p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_upload" c_upload
  :: GuestfsP -> CString -> CString -> IO (CInt)

upload :: GuestfsH -> String -> String -> IO ()
upload h filename remotefilename = do
  r <- withCString filename $ \filename -> withCString remotefilename $ \remotefilename -> withForeignPtr h (\p -> c_upload p filename remotefilename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_download" c_download
  :: GuestfsP -> CString -> CString -> IO (CInt)

download :: GuestfsH -> String -> String -> IO ()
download h remotefilename filename = do
  r <- withCString remotefilename $ \remotefilename -> withCString filename $ \filename -> withForeignPtr h (\p -> c_download p remotefilename filename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_tar_in" c_tar_in
  :: GuestfsP -> CString -> CString -> IO (CInt)

tar_in :: GuestfsH -> String -> String -> IO ()
tar_in h tarfile directory = do
  r <- withCString tarfile $ \tarfile -> withCString directory $ \directory -> withForeignPtr h (\p -> c_tar_in p tarfile directory)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_tar_out" c_tar_out
  :: GuestfsP -> CString -> CString -> IO (CInt)

tar_out :: GuestfsH -> String -> String -> IO ()
tar_out h directory tarfile = do
  r <- withCString directory $ \directory -> withCString tarfile $ \tarfile -> withForeignPtr h (\p -> c_tar_out p directory tarfile)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_tgz_in" c_tgz_in
  :: GuestfsP -> CString -> CString -> IO (CInt)

tgz_in :: GuestfsH -> String -> String -> IO ()
tgz_in h tarball directory = do
  r <- withCString tarball $ \tarball -> withCString directory $ \directory -> withForeignPtr h (\p -> c_tgz_in p tarball directory)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_tgz_out" c_tgz_out
  :: GuestfsP -> CString -> CString -> IO (CInt)

tgz_out :: GuestfsH -> String -> String -> IO ()
tgz_out h directory tarball = do
  r <- withCString directory $ \directory -> withCString tarball $ \tarball -> withForeignPtr h (\p -> c_tgz_out p directory tarball)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mount_ro" c_mount_ro
  :: GuestfsP -> CString -> CString -> IO (CInt)

mount_ro :: GuestfsH -> String -> String -> IO ()
mount_ro h device mountpoint = do
  r <- withCString device $ \device -> withCString mountpoint $ \mountpoint -> withForeignPtr h (\p -> c_mount_ro p device mountpoint)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mount_options" c_mount_options
  :: GuestfsP -> CString -> CString -> CString -> IO (CInt)

mount_options :: GuestfsH -> String -> String -> String -> IO ()
mount_options h options device mountpoint = do
  r <- withCString options $ \options -> withCString device $ \device -> withCString mountpoint $ \mountpoint -> withForeignPtr h (\p -> c_mount_options p options device mountpoint)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mount_vfs" c_mount_vfs
  :: GuestfsP -> CString -> CString -> CString -> CString -> IO (CInt)

mount_vfs :: GuestfsH -> String -> String -> String -> String -> IO ()
mount_vfs h options vfstype device mountpoint = do
  r <- withCString options $ \options -> withCString vfstype $ \vfstype -> withCString device $ \device -> withCString mountpoint $ \mountpoint -> withForeignPtr h (\p -> c_mount_vfs p options vfstype device mountpoint)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_lvremove" c_lvremove
  :: GuestfsP -> CString -> IO (CInt)

lvremove :: GuestfsH -> String -> IO ()
lvremove h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_lvremove p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_vgremove" c_vgremove
  :: GuestfsP -> CString -> IO (CInt)

vgremove :: GuestfsH -> String -> IO ()
vgremove h vgname = do
  r <- withCString vgname $ \vgname -> withForeignPtr h (\p -> c_vgremove p vgname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_pvremove" c_pvremove
  :: GuestfsP -> CString -> IO (CInt)

pvremove :: GuestfsH -> String -> IO ()
pvremove h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_pvremove p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_set_e2label" c_set_e2label
  :: GuestfsP -> CString -> CString -> IO (CInt)

set_e2label :: GuestfsH -> String -> String -> IO ()
set_e2label h device label = do
  r <- withCString device $ \device -> withCString label $ \label -> withForeignPtr h (\p -> c_set_e2label p device label)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_set_e2uuid" c_set_e2uuid
  :: GuestfsP -> CString -> CString -> IO (CInt)

set_e2uuid :: GuestfsH -> String -> String -> IO ()
set_e2uuid h device uuid = do
  r <- withCString device $ \device -> withCString uuid $ \uuid -> withForeignPtr h (\p -> c_set_e2uuid p device uuid)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_fsck" c_fsck
  :: GuestfsP -> CString -> CString -> IO (CInt)

fsck :: GuestfsH -> String -> String -> IO (Int)
fsck h fstype device = do
  r <- withCString fstype $ \fstype -> withCString device $ \device -> withForeignPtr h (\p -> c_fsck p fstype device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_zero" c_zero
  :: GuestfsP -> CString -> IO (CInt)

zero :: GuestfsH -> String -> IO ()
zero h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_zero p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_grub_install" c_grub_install
  :: GuestfsP -> CString -> CString -> IO (CInt)

grub_install :: GuestfsH -> String -> String -> IO ()
grub_install h root device = do
  r <- withCString root $ \root -> withCString device $ \device -> withForeignPtr h (\p -> c_grub_install p root device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_cp" c_cp
  :: GuestfsP -> CString -> CString -> IO (CInt)

cp :: GuestfsH -> String -> String -> IO ()
cp h src dest = do
  r <- withCString src $ \src -> withCString dest $ \dest -> withForeignPtr h (\p -> c_cp p src dest)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_cp_a" c_cp_a
  :: GuestfsP -> CString -> CString -> IO (CInt)

cp_a :: GuestfsH -> String -> String -> IO ()
cp_a h src dest = do
  r <- withCString src $ \src -> withCString dest $ \dest -> withForeignPtr h (\p -> c_cp_a p src dest)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mv" c_mv
  :: GuestfsP -> CString -> CString -> IO (CInt)

mv :: GuestfsH -> String -> String -> IO ()
mv h src dest = do
  r <- withCString src $ \src -> withCString dest $ \dest -> withForeignPtr h (\p -> c_mv p src dest)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_drop_caches" c_drop_caches
  :: GuestfsP -> CInt -> IO (CInt)

drop_caches :: GuestfsH -> Int -> IO ()
drop_caches h whattodrop = do
  r <- withForeignPtr h (\p -> c_drop_caches p (fromIntegral whattodrop))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_ping_daemon" c_ping_daemon
  :: GuestfsP -> IO (CInt)

ping_daemon :: GuestfsH -> IO ()
ping_daemon h = do
  r <- withForeignPtr h (\p -> c_ping_daemon p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_zerofree" c_zerofree
  :: GuestfsP -> CString -> IO (CInt)

zerofree :: GuestfsH -> String -> IO ()
zerofree h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_zerofree p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_pvresize" c_pvresize
  :: GuestfsP -> CString -> IO (CInt)

pvresize :: GuestfsH -> String -> IO ()
pvresize h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_pvresize p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_sfdisk_N" c_sfdisk_N
  :: GuestfsP -> CString -> CInt -> CInt -> CInt -> CInt -> CString -> IO (CInt)

sfdisk_N :: GuestfsH -> String -> Int -> Int -> Int -> Int -> String -> IO ()
sfdisk_N h device partnum cyls heads sectors line = do
  r <- withCString device $ \device -> withCString line $ \line -> withForeignPtr h (\p -> c_sfdisk_N p device (fromIntegral partnum) (fromIntegral cyls) (fromIntegral heads) (fromIntegral sectors) line)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_vg_activate_all" c_vg_activate_all
  :: GuestfsP -> CInt -> IO (CInt)

vg_activate_all :: GuestfsH -> Bool -> IO ()
vg_activate_all h activate = do
  r <- withForeignPtr h (\p -> c_vg_activate_all p (fromBool activate))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_vg_activate" c_vg_activate
  :: GuestfsP -> CInt -> Ptr CString -> IO (CInt)

vg_activate :: GuestfsH -> Bool -> [String] -> IO ()
vg_activate h activate volgroups = do
  r <- withMany withCString volgroups $ \volgroups -> withArray0 nullPtr volgroups $ \volgroups -> withForeignPtr h (\p -> c_vg_activate p (fromBool activate) volgroups)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_lvresize" c_lvresize
  :: GuestfsP -> CString -> CInt -> IO (CInt)

lvresize :: GuestfsH -> String -> Int -> IO ()
lvresize h device mbytes = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_lvresize p device (fromIntegral mbytes))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_resize2fs" c_resize2fs
  :: GuestfsP -> CString -> IO (CInt)

resize2fs :: GuestfsH -> String -> IO ()
resize2fs h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_resize2fs p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_e2fsck_f" c_e2fsck_f
  :: GuestfsP -> CString -> IO (CInt)

e2fsck_f :: GuestfsH -> String -> IO ()
e2fsck_f h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_e2fsck_f p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_sleep" c_sleep
  :: GuestfsP -> CInt -> IO (CInt)

sleep :: GuestfsH -> Int -> IO ()
sleep h secs = do
  r <- withForeignPtr h (\p -> c_sleep p (fromIntegral secs))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_ntfs_3g_probe" c_ntfs_3g_probe
  :: GuestfsP -> CInt -> CString -> IO (CInt)

ntfs_3g_probe :: GuestfsH -> Bool -> String -> IO (Int)
ntfs_3g_probe h rw device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_ntfs_3g_probe p (fromBool rw) device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_scrub_device" c_scrub_device
  :: GuestfsP -> CString -> IO (CInt)

scrub_device :: GuestfsH -> String -> IO ()
scrub_device h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_scrub_device p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_scrub_file" c_scrub_file
  :: GuestfsP -> CString -> IO (CInt)

scrub_file :: GuestfsH -> String -> IO ()
scrub_file h file = do
  r <- withCString file $ \file -> withForeignPtr h (\p -> c_scrub_file p file)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_scrub_freespace" c_scrub_freespace
  :: GuestfsP -> CString -> IO (CInt)

scrub_freespace :: GuestfsH -> String -> IO ()
scrub_freespace h dir = do
  r <- withCString dir $ \dir -> withForeignPtr h (\p -> c_scrub_freespace p dir)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_wc_l" c_wc_l
  :: GuestfsP -> CString -> IO (CInt)

wc_l :: GuestfsH -> String -> IO (Int)
wc_l h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_wc_l p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_wc_w" c_wc_w
  :: GuestfsP -> CString -> IO (CInt)

wc_w :: GuestfsH -> String -> IO (Int)
wc_w h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_wc_w p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_wc_c" c_wc_c
  :: GuestfsP -> CString -> IO (CInt)

wc_c :: GuestfsH -> String -> IO (Int)
wc_c h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_wc_c p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_du" c_du
  :: GuestfsP -> CString -> IO (Int64)

du :: GuestfsH -> String -> IO (Integer)
du h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_du p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_mount_loop" c_mount_loop
  :: GuestfsP -> CString -> CString -> IO (CInt)

mount_loop :: GuestfsH -> String -> String -> IO ()
mount_loop h file mountpoint = do
  r <- withCString file $ \file -> withCString mountpoint $ \mountpoint -> withForeignPtr h (\p -> c_mount_loop p file mountpoint)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mkswap" c_mkswap
  :: GuestfsP -> CString -> IO (CInt)

mkswap :: GuestfsH -> String -> IO ()
mkswap h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_mkswap p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mkswap_L" c_mkswap_L
  :: GuestfsP -> CString -> CString -> IO (CInt)

mkswap_L :: GuestfsH -> String -> String -> IO ()
mkswap_L h label device = do
  r <- withCString label $ \label -> withCString device $ \device -> withForeignPtr h (\p -> c_mkswap_L p label device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mkswap_U" c_mkswap_U
  :: GuestfsP -> CString -> CString -> IO (CInt)

mkswap_U :: GuestfsH -> String -> String -> IO ()
mkswap_U h uuid device = do
  r <- withCString uuid $ \uuid -> withCString device $ \device -> withForeignPtr h (\p -> c_mkswap_U p uuid device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mknod" c_mknod
  :: GuestfsP -> CInt -> CInt -> CInt -> CString -> IO (CInt)

mknod :: GuestfsH -> Int -> Int -> Int -> String -> IO ()
mknod h mode devmajor devminor path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mknod p (fromIntegral mode) (fromIntegral devmajor) (fromIntegral devminor) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mkfifo" c_mkfifo
  :: GuestfsP -> CInt -> CString -> IO (CInt)

mkfifo :: GuestfsH -> Int -> String -> IO ()
mkfifo h mode path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mkfifo p (fromIntegral mode) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mknod_b" c_mknod_b
  :: GuestfsP -> CInt -> CInt -> CInt -> CString -> IO (CInt)

mknod_b :: GuestfsH -> Int -> Int -> Int -> String -> IO ()
mknod_b h mode devmajor devminor path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mknod_b p (fromIntegral mode) (fromIntegral devmajor) (fromIntegral devminor) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mknod_c" c_mknod_c
  :: GuestfsP -> CInt -> CInt -> CInt -> CString -> IO (CInt)

mknod_c :: GuestfsH -> Int -> Int -> Int -> String -> IO ()
mknod_c h mode devmajor devminor path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mknod_c p (fromIntegral mode) (fromIntegral devmajor) (fromIntegral devminor) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_umask" c_umask
  :: GuestfsP -> CInt -> IO (CInt)

umask :: GuestfsH -> Int -> IO (Int)
umask h mask = do
  r <- withForeignPtr h (\p -> c_umask p (fromIntegral mask))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_sfdiskM" c_sfdiskM
  :: GuestfsP -> CString -> Ptr CString -> IO (CInt)

sfdiskM :: GuestfsH -> String -> [String] -> IO ()
sfdiskM h device lines = do
  r <- withCString device $ \device -> withMany withCString lines $ \lines -> withArray0 nullPtr lines $ \lines -> withForeignPtr h (\p -> c_sfdiskM p device lines)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_setxattr" c_setxattr
  :: GuestfsP -> CString -> CString -> CInt -> CString -> IO (CInt)

setxattr :: GuestfsH -> String -> String -> Int -> String -> IO ()
setxattr h xattr val vallen path = do
  r <- withCString xattr $ \xattr -> withCString val $ \val -> withCString path $ \path -> withForeignPtr h (\p -> c_setxattr p xattr val (fromIntegral vallen) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_lsetxattr" c_lsetxattr
  :: GuestfsP -> CString -> CString -> CInt -> CString -> IO (CInt)

lsetxattr :: GuestfsH -> String -> String -> Int -> String -> IO ()
lsetxattr h xattr val vallen path = do
  r <- withCString xattr $ \xattr -> withCString val $ \val -> withCString path $ \path -> withForeignPtr h (\p -> c_lsetxattr p xattr val (fromIntegral vallen) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_removexattr" c_removexattr
  :: GuestfsP -> CString -> CString -> IO (CInt)

removexattr :: GuestfsH -> String -> String -> IO ()
removexattr h xattr path = do
  r <- withCString xattr $ \xattr -> withCString path $ \path -> withForeignPtr h (\p -> c_removexattr p xattr path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_lremovexattr" c_lremovexattr
  :: GuestfsP -> CString -> CString -> IO (CInt)

lremovexattr :: GuestfsH -> String -> String -> IO ()
lremovexattr h xattr path = do
  r <- withCString xattr $ \xattr -> withCString path $ \path -> withForeignPtr h (\p -> c_lremovexattr p xattr path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mkmountpoint" c_mkmountpoint
  :: GuestfsP -> CString -> IO (CInt)

mkmountpoint :: GuestfsH -> String -> IO ()
mkmountpoint h exemptpath = do
  r <- withCString exemptpath $ \exemptpath -> withForeignPtr h (\p -> c_mkmountpoint p exemptpath)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_rmmountpoint" c_rmmountpoint
  :: GuestfsP -> CString -> IO (CInt)

rmmountpoint :: GuestfsH -> String -> IO ()
rmmountpoint h exemptpath = do
  r <- withCString exemptpath $ \exemptpath -> withForeignPtr h (\p -> c_rmmountpoint p exemptpath)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_ln" c_ln
  :: GuestfsP -> CString -> CString -> IO (CInt)

ln :: GuestfsH -> String -> String -> IO ()
ln h target linkname = do
  r <- withCString target $ \target -> withCString linkname $ \linkname -> withForeignPtr h (\p -> c_ln p target linkname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_ln_f" c_ln_f
  :: GuestfsP -> CString -> CString -> IO (CInt)

ln_f :: GuestfsH -> String -> String -> IO ()
ln_f h target linkname = do
  r <- withCString target $ \target -> withCString linkname $ \linkname -> withForeignPtr h (\p -> c_ln_f p target linkname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_ln_s" c_ln_s
  :: GuestfsP -> CString -> CString -> IO (CInt)

ln_s :: GuestfsH -> String -> String -> IO ()
ln_s h target linkname = do
  r <- withCString target $ \target -> withCString linkname $ \linkname -> withForeignPtr h (\p -> c_ln_s p target linkname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_ln_sf" c_ln_sf
  :: GuestfsP -> CString -> CString -> IO (CInt)

ln_sf :: GuestfsH -> String -> String -> IO ()
ln_sf h target linkname = do
  r <- withCString target $ \target -> withCString linkname $ \linkname -> withForeignPtr h (\p -> c_ln_sf p target linkname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_fallocate" c_fallocate
  :: GuestfsP -> CString -> CInt -> IO (CInt)

fallocate :: GuestfsH -> String -> Int -> IO ()
fallocate h path len = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_fallocate p path (fromIntegral len))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_swapon_device" c_swapon_device
  :: GuestfsP -> CString -> IO (CInt)

swapon_device :: GuestfsH -> String -> IO ()
swapon_device h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_swapon_device p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_swapoff_device" c_swapoff_device
  :: GuestfsP -> CString -> IO (CInt)

swapoff_device :: GuestfsH -> String -> IO ()
swapoff_device h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_swapoff_device p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_swapon_file" c_swapon_file
  :: GuestfsP -> CString -> IO (CInt)

swapon_file :: GuestfsH -> String -> IO ()
swapon_file h file = do
  r <- withCString file $ \file -> withForeignPtr h (\p -> c_swapon_file p file)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_swapoff_file" c_swapoff_file
  :: GuestfsP -> CString -> IO (CInt)

swapoff_file :: GuestfsH -> String -> IO ()
swapoff_file h file = do
  r <- withCString file $ \file -> withForeignPtr h (\p -> c_swapoff_file p file)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_swapon_label" c_swapon_label
  :: GuestfsP -> CString -> IO (CInt)

swapon_label :: GuestfsH -> String -> IO ()
swapon_label h label = do
  r <- withCString label $ \label -> withForeignPtr h (\p -> c_swapon_label p label)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_swapoff_label" c_swapoff_label
  :: GuestfsP -> CString -> IO (CInt)

swapoff_label :: GuestfsH -> String -> IO ()
swapoff_label h label = do
  r <- withCString label $ \label -> withForeignPtr h (\p -> c_swapoff_label p label)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_swapon_uuid" c_swapon_uuid
  :: GuestfsP -> CString -> IO (CInt)

swapon_uuid :: GuestfsH -> String -> IO ()
swapon_uuid h uuid = do
  r <- withCString uuid $ \uuid -> withForeignPtr h (\p -> c_swapon_uuid p uuid)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_swapoff_uuid" c_swapoff_uuid
  :: GuestfsP -> CString -> IO (CInt)

swapoff_uuid :: GuestfsH -> String -> IO ()
swapoff_uuid h uuid = do
  r <- withCString uuid $ \uuid -> withForeignPtr h (\p -> c_swapoff_uuid p uuid)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mkswap_file" c_mkswap_file
  :: GuestfsP -> CString -> IO (CInt)

mkswap_file :: GuestfsH -> String -> IO ()
mkswap_file h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mkswap_file p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_inotify_init" c_inotify_init
  :: GuestfsP -> CInt -> IO (CInt)

inotify_init :: GuestfsH -> Int -> IO ()
inotify_init h maxevents = do
  r <- withForeignPtr h (\p -> c_inotify_init p (fromIntegral maxevents))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_inotify_add_watch" c_inotify_add_watch
  :: GuestfsP -> CString -> CInt -> IO (Int64)

inotify_add_watch :: GuestfsH -> String -> Int -> IO (Integer)
inotify_add_watch h path mask = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_inotify_add_watch p path (fromIntegral mask))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_inotify_rm_watch" c_inotify_rm_watch
  :: GuestfsP -> CInt -> IO (CInt)

inotify_rm_watch :: GuestfsH -> Int -> IO ()
inotify_rm_watch h wd = do
  r <- withForeignPtr h (\p -> c_inotify_rm_watch p (fromIntegral wd))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_inotify_close" c_inotify_close
  :: GuestfsP -> IO (CInt)

inotify_close :: GuestfsH -> IO ()
inotify_close h = do
  r <- withForeignPtr h (\p -> c_inotify_close p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_setcon" c_setcon
  :: GuestfsP -> CString -> IO (CInt)

setcon :: GuestfsH -> String -> IO ()
setcon h context = do
  r <- withCString context $ \context -> withForeignPtr h (\p -> c_setcon p context)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mkfs_b" c_mkfs_b
  :: GuestfsP -> CString -> CInt -> CString -> IO (CInt)

mkfs_b :: GuestfsH -> String -> Int -> String -> IO ()
mkfs_b h fstype blocksize device = do
  r <- withCString fstype $ \fstype -> withCString device $ \device -> withForeignPtr h (\p -> c_mkfs_b p fstype (fromIntegral blocksize) device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mke2journal" c_mke2journal
  :: GuestfsP -> CInt -> CString -> IO (CInt)

mke2journal :: GuestfsH -> Int -> String -> IO ()
mke2journal h blocksize device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_mke2journal p (fromIntegral blocksize) device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mke2journal_L" c_mke2journal_L
  :: GuestfsP -> CInt -> CString -> CString -> IO (CInt)

mke2journal_L :: GuestfsH -> Int -> String -> String -> IO ()
mke2journal_L h blocksize label device = do
  r <- withCString label $ \label -> withCString device $ \device -> withForeignPtr h (\p -> c_mke2journal_L p (fromIntegral blocksize) label device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mke2journal_U" c_mke2journal_U
  :: GuestfsP -> CInt -> CString -> CString -> IO (CInt)

mke2journal_U :: GuestfsH -> Int -> String -> String -> IO ()
mke2journal_U h blocksize uuid device = do
  r <- withCString uuid $ \uuid -> withCString device $ \device -> withForeignPtr h (\p -> c_mke2journal_U p (fromIntegral blocksize) uuid device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mke2fs_J" c_mke2fs_J
  :: GuestfsP -> CString -> CInt -> CString -> CString -> IO (CInt)

mke2fs_J :: GuestfsH -> String -> Int -> String -> String -> IO ()
mke2fs_J h fstype blocksize device journal = do
  r <- withCString fstype $ \fstype -> withCString device $ \device -> withCString journal $ \journal -> withForeignPtr h (\p -> c_mke2fs_J p fstype (fromIntegral blocksize) device journal)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mke2fs_JL" c_mke2fs_JL
  :: GuestfsP -> CString -> CInt -> CString -> CString -> IO (CInt)

mke2fs_JL :: GuestfsH -> String -> Int -> String -> String -> IO ()
mke2fs_JL h fstype blocksize device label = do
  r <- withCString fstype $ \fstype -> withCString device $ \device -> withCString label $ \label -> withForeignPtr h (\p -> c_mke2fs_JL p fstype (fromIntegral blocksize) device label)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mke2fs_JU" c_mke2fs_JU
  :: GuestfsP -> CString -> CInt -> CString -> CString -> IO (CInt)

mke2fs_JU :: GuestfsH -> String -> Int -> String -> String -> IO ()
mke2fs_JU h fstype blocksize device uuid = do
  r <- withCString fstype $ \fstype -> withCString device $ \device -> withCString uuid $ \uuid -> withForeignPtr h (\p -> c_mke2fs_JU p fstype (fromIntegral blocksize) device uuid)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_modprobe" c_modprobe
  :: GuestfsP -> CString -> IO (CInt)

modprobe :: GuestfsH -> String -> IO ()
modprobe h modulename = do
  r <- withCString modulename $ \modulename -> withForeignPtr h (\p -> c_modprobe p modulename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_find0" c_find0
  :: GuestfsP -> CString -> CString -> IO (CInt)

find0 :: GuestfsH -> String -> String -> IO ()
find0 h directory files = do
  r <- withCString directory $ \directory -> withCString files $ \files -> withForeignPtr h (\p -> c_find0 p directory files)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_truncate" c_truncate
  :: GuestfsP -> CString -> IO (CInt)

truncate :: GuestfsH -> String -> IO ()
truncate h path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_truncate p path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_truncate_size" c_truncate_size
  :: GuestfsP -> CString -> CInt -> IO (CInt)

truncate_size :: GuestfsH -> String -> Int -> IO ()
truncate_size h path size = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_truncate_size p path (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_utimens" c_utimens
  :: GuestfsP -> CString -> CInt -> CInt -> CInt -> CInt -> IO (CInt)

utimens :: GuestfsH -> String -> Int -> Int -> Int -> Int -> IO ()
utimens h path atsecs atnsecs mtsecs mtnsecs = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_utimens p path (fromIntegral atsecs) (fromIntegral atnsecs) (fromIntegral mtsecs) (fromIntegral mtnsecs))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_mkdir_mode" c_mkdir_mode
  :: GuestfsP -> CString -> CInt -> IO (CInt)

mkdir_mode :: GuestfsH -> String -> Int -> IO ()
mkdir_mode h path mode = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_mkdir_mode p path (fromIntegral mode))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_lchown" c_lchown
  :: GuestfsP -> CInt -> CInt -> CString -> IO (CInt)

lchown :: GuestfsH -> Int -> Int -> String -> IO ()
lchown h owner group path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_lchown p (fromIntegral owner) (fromIntegral group) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_part_init" c_part_init
  :: GuestfsP -> CString -> CString -> IO (CInt)

part_init :: GuestfsH -> String -> String -> IO ()
part_init h device parttype = do
  r <- withCString device $ \device -> withCString parttype $ \parttype -> withForeignPtr h (\p -> c_part_init p device parttype)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_part_add" c_part_add
  :: GuestfsP -> CString -> CString -> CInt -> CInt -> IO (CInt)

part_add :: GuestfsH -> String -> String -> Int -> Int -> IO ()
part_add h device prlogex startsect endsect = do
  r <- withCString device $ \device -> withCString prlogex $ \prlogex -> withForeignPtr h (\p -> c_part_add p device prlogex (fromIntegral startsect) (fromIntegral endsect))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_part_disk" c_part_disk
  :: GuestfsP -> CString -> CString -> IO (CInt)

part_disk :: GuestfsH -> String -> String -> IO ()
part_disk h device parttype = do
  r <- withCString device $ \device -> withCString parttype $ \parttype -> withForeignPtr h (\p -> c_part_disk p device parttype)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_part_set_bootable" c_part_set_bootable
  :: GuestfsP -> CString -> CInt -> CInt -> IO (CInt)

part_set_bootable :: GuestfsH -> String -> Int -> Bool -> IO ()
part_set_bootable h device partnum bootable = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_set_bootable p device (fromIntegral partnum) (fromBool bootable))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_part_set_name" c_part_set_name
  :: GuestfsP -> CString -> CInt -> CString -> IO (CInt)

part_set_name :: GuestfsH -> String -> Int -> String -> IO ()
part_set_name h device partnum name = do
  r <- withCString device $ \device -> withCString name $ \name -> withForeignPtr h (\p -> c_part_set_name p device (fromIntegral partnum) name)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_fill" c_fill
  :: GuestfsP -> CInt -> CInt -> CString -> IO (CInt)

fill :: GuestfsH -> Int -> Int -> String -> IO ()
fill h c len path = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_fill p (fromIntegral c) (fromIntegral len) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_available" c_available
  :: GuestfsP -> Ptr CString -> IO (CInt)

available :: GuestfsH -> [String] -> IO ()
available h groups = do
  r <- withMany withCString groups $ \groups -> withArray0 nullPtr groups $ \groups -> withForeignPtr h (\p -> c_available p groups)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_dd" c_dd
  :: GuestfsP -> CString -> CString -> IO (CInt)

dd :: GuestfsH -> String -> String -> IO ()
dd h src dest = do
  r <- withCString src $ \src -> withCString dest $ \dest -> withForeignPtr h (\p -> c_dd p src dest)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_filesize" c_filesize
  :: GuestfsP -> CString -> IO (Int64)

filesize :: GuestfsH -> String -> IO (Integer)
filesize h file = do
  r <- withCString file $ \file -> withForeignPtr h (\p -> c_filesize p file)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_lvrename" c_lvrename
  :: GuestfsP -> CString -> CString -> IO (CInt)

lvrename :: GuestfsH -> String -> String -> IO ()
lvrename h logvol newlogvol = do
  r <- withCString logvol $ \logvol -> withCString newlogvol $ \newlogvol -> withForeignPtr h (\p -> c_lvrename p logvol newlogvol)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_vgrename" c_vgrename
  :: GuestfsP -> CString -> CString -> IO (CInt)

vgrename :: GuestfsH -> String -> String -> IO ()
vgrename h volgroup newvolgroup = do
  r <- withCString volgroup $ \volgroup -> withCString newvolgroup $ \newvolgroup -> withForeignPtr h (\p -> c_vgrename p volgroup newvolgroup)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_copy_size" c_copy_size
  :: GuestfsP -> CString -> CString -> CInt -> IO (CInt)

copy_size :: GuestfsH -> String -> String -> Int -> IO ()
copy_size h src dest size = do
  r <- withCString src $ \src -> withCString dest $ \dest -> withForeignPtr h (\p -> c_copy_size p src dest (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_zero_device" c_zero_device
  :: GuestfsP -> CString -> IO (CInt)

zero_device :: GuestfsH -> String -> IO ()
zero_device h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_zero_device p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_txz_in" c_txz_in
  :: GuestfsP -> CString -> CString -> IO (CInt)

txz_in :: GuestfsH -> String -> String -> IO ()
txz_in h tarball directory = do
  r <- withCString tarball $ \tarball -> withCString directory $ \directory -> withForeignPtr h (\p -> c_txz_in p tarball directory)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_txz_out" c_txz_out
  :: GuestfsP -> CString -> CString -> IO (CInt)

txz_out :: GuestfsH -> String -> String -> IO ()
txz_out h directory tarball = do
  r <- withCString directory $ \directory -> withCString tarball $ \tarball -> withForeignPtr h (\p -> c_txz_out p directory tarball)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_ntfsresize" c_ntfsresize
  :: GuestfsP -> CString -> IO (CInt)

ntfsresize :: GuestfsH -> String -> IO ()
ntfsresize h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_ntfsresize p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_vgscan" c_vgscan
  :: GuestfsP -> IO (CInt)

vgscan :: GuestfsH -> IO ()
vgscan h = do
  r <- withForeignPtr h (\p -> c_vgscan p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_part_del" c_part_del
  :: GuestfsP -> CString -> CInt -> IO (CInt)

part_del :: GuestfsH -> String -> Int -> IO ()
part_del h device partnum = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_del p device (fromIntegral partnum))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_part_get_mbr_id" c_part_get_mbr_id
  :: GuestfsP -> CString -> CInt -> IO (CInt)

part_get_mbr_id :: GuestfsH -> String -> Int -> IO (Int)
part_get_mbr_id h device partnum = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_get_mbr_id p device (fromIntegral partnum))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_part_set_mbr_id" c_part_set_mbr_id
  :: GuestfsP -> CString -> CInt -> CInt -> IO (CInt)

part_set_mbr_id :: GuestfsH -> String -> Int -> Int -> IO ()
part_set_mbr_id h device partnum idbyte = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_part_set_mbr_id p device (fromIntegral partnum) (fromIntegral idbyte))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_lvresize_free" c_lvresize_free
  :: GuestfsP -> CString -> CInt -> IO (CInt)

lvresize_free :: GuestfsH -> String -> Int -> IO ()
lvresize_free h lv percent = do
  r <- withCString lv $ \lv -> withForeignPtr h (\p -> c_lvresize_free p lv (fromIntegral percent))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_aug_clear" c_aug_clear
  :: GuestfsP -> CString -> IO (CInt)

aug_clear :: GuestfsH -> String -> IO ()
aug_clear h augpath = do
  r <- withCString augpath $ \augpath -> withForeignPtr h (\p -> c_aug_clear p augpath)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_get_umask" c_get_umask
  :: GuestfsP -> IO (CInt)

get_umask :: GuestfsH -> IO (Int)
get_umask h = do
  r <- withForeignPtr h (\p -> c_get_umask p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_debug_upload" c_debug_upload
  :: GuestfsP -> CString -> CString -> CInt -> IO (CInt)

debug_upload :: GuestfsH -> String -> String -> Int -> IO ()
debug_upload h filename tmpname mode = do
  r <- withCString filename $ \filename -> withCString tmpname $ \tmpname -> withForeignPtr h (\p -> c_debug_upload p filename tmpname (fromIntegral mode))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_base64_in" c_base64_in
  :: GuestfsP -> CString -> CString -> IO (CInt)

base64_in :: GuestfsH -> String -> String -> IO ()
base64_in h base64file filename = do
  r <- withCString base64file $ \base64file -> withCString filename $ \filename -> withForeignPtr h (\p -> c_base64_in p base64file filename)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_base64_out" c_base64_out
  :: GuestfsP -> CString -> CString -> IO (CInt)

base64_out :: GuestfsH -> String -> String -> IO ()
base64_out h filename base64file = do
  r <- withCString filename $ \filename -> withCString base64file $ \base64file -> withForeignPtr h (\p -> c_base64_out p filename base64file)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_checksums_out" c_checksums_out
  :: GuestfsP -> CString -> CString -> CString -> IO (CInt)

checksums_out :: GuestfsH -> String -> String -> String -> IO ()
checksums_out h csumtype directory sumsfile = do
  r <- withCString csumtype $ \csumtype -> withCString directory $ \directory -> withCString sumsfile $ \sumsfile -> withForeignPtr h (\p -> c_checksums_out p csumtype directory sumsfile)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_fill_pattern" c_fill_pattern
  :: GuestfsP -> CString -> CInt -> CString -> IO (CInt)

fill_pattern :: GuestfsH -> String -> Int -> String -> IO ()
fill_pattern h pattern len path = do
  r <- withCString pattern $ \pattern -> withCString path $ \path -> withForeignPtr h (\p -> c_fill_pattern p pattern (fromIntegral len) path)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_write" c_write
  :: GuestfsP -> CString -> CString -> CInt -> IO (CInt)

write :: GuestfsH -> String -> String -> IO ()
write h path content = do
  r <- withCString path $ \path -> withCStringLen content $ \(content, content_size) -> withForeignPtr h (\p -> c_write p path content (fromIntegral content_size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_pwrite" c_pwrite
  :: GuestfsP -> CString -> CString -> CInt -> CInt -> IO (CInt)

pwrite :: GuestfsH -> String -> String -> Int -> IO (Int)
pwrite h path content offset = do
  r <- withCString path $ \path -> withCStringLen content $ \(content, content_size) -> withForeignPtr h (\p -> c_pwrite p path content (fromIntegral content_size) (fromIntegral offset))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_resize2fs_size" c_resize2fs_size
  :: GuestfsP -> CString -> CInt -> IO (CInt)

resize2fs_size :: GuestfsH -> String -> Int -> IO ()
resize2fs_size h device size = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_resize2fs_size p device (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_pvresize_size" c_pvresize_size
  :: GuestfsP -> CString -> CInt -> IO (CInt)

pvresize_size :: GuestfsH -> String -> Int -> IO ()
pvresize_size h device size = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_pvresize_size p device (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_ntfsresize_size" c_ntfsresize_size
  :: GuestfsP -> CString -> CInt -> IO (CInt)

ntfsresize_size :: GuestfsH -> String -> Int -> IO ()
ntfsresize_size h device size = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_ntfsresize_size p device (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_fallocate64" c_fallocate64
  :: GuestfsP -> CString -> CInt -> IO (CInt)

fallocate64 :: GuestfsH -> String -> Int -> IO ()
fallocate64 h path len = do
  r <- withCString path $ \path -> withForeignPtr h (\p -> c_fallocate64 p path (fromIntegral len))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_lvm_set_filter" c_lvm_set_filter
  :: GuestfsP -> Ptr CString -> IO (CInt)

lvm_set_filter :: GuestfsH -> [String] -> IO ()
lvm_set_filter h devices = do
  r <- withMany withCString devices $ \devices -> withArray0 nullPtr devices $ \devices -> withForeignPtr h (\p -> c_lvm_set_filter p devices)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_lvm_clear_filter" c_lvm_clear_filter
  :: GuestfsP -> IO (CInt)

lvm_clear_filter :: GuestfsH -> IO ()
lvm_clear_filter h = do
  r <- withForeignPtr h (\p -> c_lvm_clear_filter p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_luks_open" c_luks_open
  :: GuestfsP -> CString -> CString -> CString -> IO (CInt)

luks_open :: GuestfsH -> String -> String -> String -> IO ()
luks_open h device key mapname = do
  r <- withCString device $ \device -> withCString key $ \key -> withCString mapname $ \mapname -> withForeignPtr h (\p -> c_luks_open p device key mapname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_luks_open_ro" c_luks_open_ro
  :: GuestfsP -> CString -> CString -> CString -> IO (CInt)

luks_open_ro :: GuestfsH -> String -> String -> String -> IO ()
luks_open_ro h device key mapname = do
  r <- withCString device $ \device -> withCString key $ \key -> withCString mapname $ \mapname -> withForeignPtr h (\p -> c_luks_open_ro p device key mapname)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_luks_close" c_luks_close
  :: GuestfsP -> CString -> IO (CInt)

luks_close :: GuestfsH -> String -> IO ()
luks_close h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_luks_close p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_luks_format" c_luks_format
  :: GuestfsP -> CString -> CString -> CInt -> IO (CInt)

luks_format :: GuestfsH -> String -> String -> Int -> IO ()
luks_format h device key keyslot = do
  r <- withCString device $ \device -> withCString key $ \key -> withForeignPtr h (\p -> c_luks_format p device key (fromIntegral keyslot))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_luks_format_cipher" c_luks_format_cipher
  :: GuestfsP -> CString -> CString -> CInt -> CString -> IO (CInt)

luks_format_cipher :: GuestfsH -> String -> String -> Int -> String -> IO ()
luks_format_cipher h device key keyslot cipher = do
  r <- withCString device $ \device -> withCString key $ \key -> withCString cipher $ \cipher -> withForeignPtr h (\p -> c_luks_format_cipher p device key (fromIntegral keyslot) cipher)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_luks_add_key" c_luks_add_key
  :: GuestfsP -> CString -> CString -> CString -> CInt -> IO (CInt)

luks_add_key :: GuestfsH -> String -> String -> String -> Int -> IO ()
luks_add_key h device key newkey keyslot = do
  r <- withCString device $ \device -> withCString key $ \key -> withCString newkey $ \newkey -> withForeignPtr h (\p -> c_luks_add_key p device key newkey (fromIntegral keyslot))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_luks_kill_slot" c_luks_kill_slot
  :: GuestfsP -> CString -> CString -> CInt -> IO (CInt)

luks_kill_slot :: GuestfsH -> String -> String -> Int -> IO ()
luks_kill_slot h device key keyslot = do
  r <- withCString device $ \device -> withCString key $ \key -> withForeignPtr h (\p -> c_luks_kill_slot p device key (fromIntegral keyslot))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_upload_offset" c_upload_offset
  :: GuestfsP -> CString -> CString -> CInt -> IO (CInt)

upload_offset :: GuestfsH -> String -> String -> Int -> IO ()
upload_offset h filename remotefilename offset = do
  r <- withCString filename $ \filename -> withCString remotefilename $ \remotefilename -> withForeignPtr h (\p -> c_upload_offset p filename remotefilename (fromIntegral offset))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_download_offset" c_download_offset
  :: GuestfsP -> CString -> CString -> CInt -> CInt -> IO (CInt)

download_offset :: GuestfsH -> String -> String -> Int -> Int -> IO ()
download_offset h remotefilename filename offset size = do
  r <- withCString remotefilename $ \remotefilename -> withCString filename $ \filename -> withForeignPtr h (\p -> c_download_offset p remotefilename filename (fromIntegral offset) (fromIntegral size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_pwrite_device" c_pwrite_device
  :: GuestfsP -> CString -> CString -> CInt -> CInt -> IO (CInt)

pwrite_device :: GuestfsH -> String -> String -> Int -> IO (Int)
pwrite_device h device content offset = do
  r <- withCString device $ \device -> withCStringLen content $ \(content, content_size) -> withForeignPtr h (\p -> c_pwrite_device p device content (fromIntegral content_size) (fromIntegral offset))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_resize2fs_M" c_resize2fs_M
  :: GuestfsP -> CString -> IO (CInt)

resize2fs_M :: GuestfsH -> String -> IO ()
resize2fs_M h device = do
  r <- withCString device $ \device -> withForeignPtr h (\p -> c_resize2fs_M p device)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_internal_autosync" c_internal_autosync
  :: GuestfsP -> IO (CInt)

internal_autosync :: GuestfsH -> IO ()
internal_autosync h = do
  r <- withForeignPtr h (\p -> c_internal_autosync p)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_write_append" c_write_append
  :: GuestfsP -> CString -> CString -> CInt -> IO (CInt)

write_append :: GuestfsH -> String -> String -> IO ()
write_append h path content = do
  r <- withCString path $ \path -> withCStringLen content $ \(content, content_size) -> withForeignPtr h (\p -> c_write_append p path content (fromIntegral content_size))
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

foreign import ccall unsafe "guestfs_part_to_partnum" c_part_to_partnum
  :: GuestfsP -> CString -> IO (CInt)

part_to_partnum :: GuestfsH -> String -> IO (Int)
part_to_partnum h partition = do
  r <- withCString partition $ \partition -> withForeignPtr h (\p -> c_part_to_partnum p partition)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return (fromIntegral r)

foreign import ccall unsafe "guestfs_md_stop" c_md_stop
  :: GuestfsP -> CString -> IO (CInt)

md_stop :: GuestfsH -> String -> IO ()
md_stop h md = do
  r <- withCString md $ \md -> withForeignPtr h (\p -> c_md_stop p md)
  if (r == -1)
    then do
      err <- last_error h
      fail err
    else return ()

