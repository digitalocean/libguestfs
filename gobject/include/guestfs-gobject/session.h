/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/gobject.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
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

#ifndef GUESTFS_GOBJECT_SESSION_H__
#define GUESTFS_GOBJECT_SESSION_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/* GuestfsSessionEvent */

/**
 * GuestfsSessionEvent:
 * @GUESTFS_SESSION_EVENT_CLOSE: The close event
 * @GUESTFS_SESSION_EVENT_SUBPROCESS_QUIT: The subprocess_quit event
 * @GUESTFS_SESSION_EVENT_LAUNCH_DONE: The launch_done event
 * @GUESTFS_SESSION_EVENT_PROGRESS: The progress event
 * @GUESTFS_SESSION_EVENT_APPLIANCE: The appliance event
 * @GUESTFS_SESSION_EVENT_LIBRARY: The library event
 * @GUESTFS_SESSION_EVENT_TRACE: The trace event
 * @GUESTFS_SESSION_EVENT_ENTER: The enter event
 * @GUESTFS_SESSION_EVENT_LIBVIRT_AUTH: The libvirt_auth event
 * @GUESTFS_SESSION_EVENT_WARNING: The warning event
 *
 * For more detail on libguestfs events, see "SETTING CALLBACKS TO HANDLE
 * EVENTS" in guestfs(3).
 */
typedef enum {
  GUESTFS_SESSION_EVENT_CLOSE,
  GUESTFS_SESSION_EVENT_SUBPROCESS_QUIT,
  GUESTFS_SESSION_EVENT_LAUNCH_DONE,
  GUESTFS_SESSION_EVENT_PROGRESS,
  GUESTFS_SESSION_EVENT_APPLIANCE,
  GUESTFS_SESSION_EVENT_LIBRARY,
  GUESTFS_SESSION_EVENT_TRACE,
  GUESTFS_SESSION_EVENT_ENTER,
  GUESTFS_SESSION_EVENT_LIBVIRT_AUTH,
  GUESTFS_SESSION_EVENT_WARNING,
} GuestfsSessionEvent;
GType guestfs_session_event_get_type (void);
#define GUESTFS_TYPE_SESSION_EVENT (guestfs_session_event_get_type ())

/* GuestfsSessionEventParams */

/**
 * GuestfsSessionEventParams:
 * @event: The event
 * @flags: Unused
 * @buf: A message buffer. This buffer can contain arbitrary 8 bit data,
 *       including NUL bytes
 * @array: An array of 64-bit unsigned integers
 * @array_len: The length of @array
 */
typedef struct _GuestfsSessionEventParams GuestfsSessionEventParams;
struct _GuestfsSessionEventParams {
  GuestfsSessionEvent event;
  guint flags;
  GByteArray *buf;
  /* The libguestfs array has no fixed length, although it is currently only
   * ever empty or length 4. We fix the length of the array here as there is
   * currently no way for an arbitrary length array to be introspected in a
   * boxed object.
   */
  guint64 array[16];
  size_t array_len;
};
GType guestfs_session_event_params_get_type (void);

/* GuestfsSession object definition */
#define GUESTFS_TYPE_SESSION             (guestfs_session_get_type ())
#define GUESTFS_SESSION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ( (obj), GUESTFS_TYPE_SESSION, GuestfsSession))
#define GUESTFS_SESSION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ( (klass), GUESTFS_TYPE_SESSION, GuestfsSessionClass))
#define GUESTFS_IS_SESSION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ( (obj), GUESTFS_TYPE_SESSION))
#define GUESTFS_IS_SESSION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ( (klass), GUESTFS_TYPE_SESSION))
#define GUESTFS_SESSION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ( (obj), GUESTFS_TYPE_SESSION, GuestfsSessionClass))

typedef struct _GuestfsSessionPrivate GuestfsSessionPrivate;

/**
 * GuestfsSession:
 *
 * A libguestfs session, encapsulating a single libguestfs handle.
 */
typedef struct _GuestfsSession GuestfsSession;
struct _GuestfsSession
{
  GObject parent;
  GuestfsSessionPrivate *priv;
};

/**
 * GuestfsSessionClass:
 * @parent_class: The superclass of GuestfsSession
 *
 * A class metadata object for GuestfsSession.
 */
typedef struct _GuestfsSessionClass GuestfsSessionClass;
struct _GuestfsSessionClass
{
  GObjectClass parent_class;
};

GType guestfs_session_get_type (void);
GuestfsSession *guestfs_session_new (void);
gboolean guestfs_session_close (GuestfsSession *session, GError **err);

gboolean guestfs_session_acl_delete_def_file (GuestfsSession *session, const gchar *dir, GError **err);
gchar *guestfs_session_acl_get_file (GuestfsSession *session, const gchar *path, const gchar *acltype, GError **err);
gboolean guestfs_session_acl_set_file (GuestfsSession *session, const gchar *path, const gchar *acltype, const gchar *acl, GError **err);
gboolean guestfs_session_add_cdrom (GuestfsSession *session, const gchar *filename, GError **err);
gint32 guestfs_session_add_domain (GuestfsSession *session, const gchar *dom, GuestfsAddDomain *optargs, GError **err);
gboolean guestfs_session_add_drive (GuestfsSession *session, const gchar *filename, GuestfsAddDrive *optargs, GError **err);
gboolean guestfs_session_add_drive_ro (GuestfsSession *session, const gchar *filename, GError **err);
gboolean guestfs_session_add_drive_ro_with_if (GuestfsSession *session, const gchar *filename, const gchar *iface, GError **err);
gboolean guestfs_session_add_drive_scratch (GuestfsSession *session, gint64 size, GuestfsAddDriveScratch *optargs, GError **err);
gboolean guestfs_session_add_drive_with_if (GuestfsSession *session, const gchar *filename, const gchar *iface, GError **err);
gint32 guestfs_session_add_libvirt_dom (GuestfsSession *session, void * /* virDomainPtr */ dom, GuestfsAddLibvirtDom *optargs, GError **err);
gboolean guestfs_session_aug_clear (GuestfsSession *session, const gchar *augpath, GError **err);
gboolean guestfs_session_aug_close (GuestfsSession *session, GError **err);
GuestfsIntBool *guestfs_session_aug_defnode (GuestfsSession *session, const gchar *name, const gchar *expr, const gchar *val, GError **err);
gint32 guestfs_session_aug_defvar (GuestfsSession *session, const gchar *name, const gchar *expr, GError **err);
gchar *guestfs_session_aug_get (GuestfsSession *session, const gchar *augpath, GError **err);
gboolean guestfs_session_aug_init (GuestfsSession *session, const gchar *root, gint32 flags, GError **err);
gboolean guestfs_session_aug_insert (GuestfsSession *session, const gchar *augpath, const gchar *label, gboolean before, GError **err);
gchar *guestfs_session_aug_label (GuestfsSession *session, const gchar *augpath, GError **err);
gboolean guestfs_session_aug_load (GuestfsSession *session, GError **err);
gchar **guestfs_session_aug_ls (GuestfsSession *session, const gchar *augpath, GError **err);
gchar **guestfs_session_aug_match (GuestfsSession *session, const gchar *augpath, GError **err);
gboolean guestfs_session_aug_mv (GuestfsSession *session, const gchar *src, const gchar *dest, GError **err);
gint32 guestfs_session_aug_rm (GuestfsSession *session, const gchar *augpath, GError **err);
gboolean guestfs_session_aug_save (GuestfsSession *session, GError **err);
gboolean guestfs_session_aug_set (GuestfsSession *session, const gchar *augpath, const gchar *val, GError **err);
gint32 guestfs_session_aug_setm (GuestfsSession *session, const gchar *base, const gchar *sub, const gchar *val, GError **err);
gboolean guestfs_session_aug_transform (GuestfsSession *session, const gchar *lens, const gchar *file, GuestfsAugTransform *optargs, GError **err);
gboolean guestfs_session_available (GuestfsSession *session, gchar *const *groups, GError **err);
gchar **guestfs_session_available_all_groups (GuestfsSession *session, GError **err);
gboolean guestfs_session_base64_in (GuestfsSession *session, const gchar *base64file, const gchar *filename, GCancellable *cancellable, GError **err);
gboolean guestfs_session_base64_out (GuestfsSession *session, const gchar *filename, const gchar *base64file, GCancellable *cancellable, GError **err);
gboolean guestfs_session_blkdiscard (GuestfsSession *session, const gchar *device, GError **err);
gint8 guestfs_session_blkdiscardzeroes (GuestfsSession *session, const gchar *device, GError **err);
GHashTable *guestfs_session_blkid (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_blockdev_flushbufs (GuestfsSession *session, const gchar *device, GError **err);
gint32 guestfs_session_blockdev_getbsz (GuestfsSession *session, const gchar *device, GError **err);
gint8 guestfs_session_blockdev_getro (GuestfsSession *session, const gchar *device, GError **err);
gint64 guestfs_session_blockdev_getsize64 (GuestfsSession *session, const gchar *device, GError **err);
gint32 guestfs_session_blockdev_getss (GuestfsSession *session, const gchar *device, GError **err);
gint64 guestfs_session_blockdev_getsz (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_blockdev_rereadpt (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_blockdev_setbsz (GuestfsSession *session, const gchar *device, gint32 blocksize, GError **err);
gboolean guestfs_session_blockdev_setra (GuestfsSession *session, const gchar *device, gint32 sectors, GError **err);
gboolean guestfs_session_blockdev_setro (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_blockdev_setrw (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_btrfs_balance_cancel (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_btrfs_balance_pause (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_btrfs_balance_resume (GuestfsSession *session, const gchar *path, GError **err);
GuestfsBTRFSBalance *guestfs_session_btrfs_balance_status (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_btrfs_device_add (GuestfsSession *session, gchar *const *devices, const gchar *fs, GError **err);
gboolean guestfs_session_btrfs_device_delete (GuestfsSession *session, gchar *const *devices, const gchar *fs, GError **err);
gboolean guestfs_session_btrfs_filesystem_balance (GuestfsSession *session, const gchar *fs, GError **err);
gboolean guestfs_session_btrfs_filesystem_defragment (GuestfsSession *session, const gchar *path, GuestfsBTRFSFilesystemDefragment *optargs, GError **err);
gboolean guestfs_session_btrfs_filesystem_resize (GuestfsSession *session, const gchar *mountpoint, GuestfsBTRFSFilesystemResize *optargs, GError **err);
gchar **guestfs_session_btrfs_filesystem_show (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_btrfs_filesystem_sync (GuestfsSession *session, const gchar *fs, GError **err);
gboolean guestfs_session_btrfs_fsck (GuestfsSession *session, const gchar *device, GuestfsBtrfsFsck *optargs, GError **err);
gboolean guestfs_session_btrfs_image (GuestfsSession *session, gchar *const *source, const gchar *image, GuestfsBTRFSImage *optargs, GError **err);
gboolean guestfs_session_btrfs_qgroup_assign (GuestfsSession *session, const gchar *src, const gchar *dst, const gchar *path, GError **err);
gboolean guestfs_session_btrfs_qgroup_create (GuestfsSession *session, const gchar *qgroupid, const gchar *subvolume, GError **err);
gboolean guestfs_session_btrfs_qgroup_destroy (GuestfsSession *session, const gchar *qgroupid, const gchar *subvolume, GError **err);
gboolean guestfs_session_btrfs_qgroup_limit (GuestfsSession *session, const gchar *subvolume, gint64 size, GError **err);
gboolean guestfs_session_btrfs_qgroup_remove (GuestfsSession *session, const gchar *src, const gchar *dst, const gchar *path, GError **err);
GuestfsBTRFSQgroup **guestfs_session_btrfs_qgroup_show (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_btrfs_quota_enable (GuestfsSession *session, const gchar *fs, gboolean enable, GError **err);
gboolean guestfs_session_btrfs_quota_rescan (GuestfsSession *session, const gchar *fs, GError **err);
gboolean guestfs_session_btrfs_replace (GuestfsSession *session, const gchar *srcdev, const gchar *targetdev, const gchar *mntpoint, GError **err);
gboolean guestfs_session_btrfs_rescue_chunk_recover (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_btrfs_rescue_super_recover (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_btrfs_scrub_cancel (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_btrfs_scrub_resume (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_btrfs_scrub_start (GuestfsSession *session, const gchar *path, GError **err);
GuestfsBTRFSScrub *guestfs_session_btrfs_scrub_status (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_btrfs_set_seeding (GuestfsSession *session, const gchar *device, gboolean seeding, GError **err);
gboolean guestfs_session_btrfs_subvolume_create (GuestfsSession *session, const gchar *dest, GuestfsBTRFSSubvolumeCreate *optargs, GError **err);
gboolean guestfs_session_btrfs_subvolume_delete (GuestfsSession *session, const gchar *subvolume, GError **err);
gint64 guestfs_session_btrfs_subvolume_get_default (GuestfsSession *session, const gchar *fs, GError **err);
GuestfsBTRFSSubvolume **guestfs_session_btrfs_subvolume_list (GuestfsSession *session, const gchar *fs, GError **err);
gboolean guestfs_session_btrfs_subvolume_set_default (GuestfsSession *session, gint64 id, const gchar *fs, GError **err);
GHashTable *guestfs_session_btrfs_subvolume_show (GuestfsSession *session, const gchar *subvolume, GError **err);
gboolean guestfs_session_btrfs_subvolume_snapshot (GuestfsSession *session, const gchar *source, const gchar *dest, GuestfsBTRFSSubvolumeSnapshot *optargs, GError **err);
gboolean guestfs_session_btrfstune_enable_extended_inode_refs (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_btrfstune_enable_skinny_metadata_extent_refs (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_btrfstune_seeding (GuestfsSession *session, const gchar *device, gboolean seeding, GError **err);
gint64 guestfs_session_c_pointer (GuestfsSession *session, GError **err);
gchar *guestfs_session_canonical_device_name (GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_cap_get_file (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_cap_set_file (GuestfsSession *session, const gchar *path, const gchar *cap, GError **err);
gchar *guestfs_session_case_sensitive_path (GuestfsSession *session, const gchar *path, GError **err);
gchar *guestfs_session_cat (GuestfsSession *session, const gchar *path, GError **err);
gchar *guestfs_session_checksum (GuestfsSession *session, const gchar *csumtype, const gchar *path, GError **err);
gchar *guestfs_session_checksum_device (GuestfsSession *session, const gchar *csumtype, const gchar *device, GError **err);
gboolean guestfs_session_checksums_out (GuestfsSession *session, const gchar *csumtype, const gchar *directory, const gchar *sumsfile, GCancellable *cancellable, GError **err);
gboolean guestfs_session_chmod (GuestfsSession *session, gint32 mode, const gchar *path, GError **err);
gboolean guestfs_session_chown (GuestfsSession *session, gint32 owner, gint32 group, const gchar *path, GError **err);
gint32 guestfs_session_clear_backend_setting (GuestfsSession *session, const gchar *name, GError **err);
gchar *guestfs_session_command (GuestfsSession *session, gchar *const *arguments, GError **err);
gchar **guestfs_session_command_lines (GuestfsSession *session, gchar *const *arguments, GError **err);
gboolean guestfs_session_compress_device_out (GuestfsSession *session, const gchar *ctype, const gchar *device, const gchar *zdevice, GuestfsCompressDeviceOut *optargs, GCancellable *cancellable, GError **err);
gboolean guestfs_session_compress_out (GuestfsSession *session, const gchar *ctype, const gchar *file, const gchar *zfile, GuestfsCompressOut *optargs, GCancellable *cancellable, GError **err);
gboolean guestfs_session_config (GuestfsSession *session, const gchar *hvparam, const gchar *hvvalue, GError **err);
gboolean guestfs_session_copy_attributes (GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyAttributes *optargs, GError **err);
gboolean guestfs_session_copy_device_to_device (GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyDeviceToDevice *optargs, GError **err);
gboolean guestfs_session_copy_device_to_file (GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyDeviceToFile *optargs, GError **err);
gboolean guestfs_session_copy_file_to_device (GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyFileToDevice *optargs, GError **err);
gboolean guestfs_session_copy_file_to_file (GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyFileToFile *optargs, GError **err);
gboolean guestfs_session_copy_in (GuestfsSession *session, const gchar *localpath, const gchar *remotedir, GError **err);
gboolean guestfs_session_copy_out (GuestfsSession *session, const gchar *remotepath, const gchar *localdir, GError **err);
gboolean guestfs_session_copy_size (GuestfsSession *session, const gchar *src, const gchar *dest, gint64 size, GError **err);
gboolean guestfs_session_cp (GuestfsSession *session, const gchar *src, const gchar *dest, GError **err);
gboolean guestfs_session_cp_a (GuestfsSession *session, const gchar *src, const gchar *dest, GError **err);
gboolean guestfs_session_cp_r (GuestfsSession *session, const gchar *src, const gchar *dest, GError **err);
gboolean guestfs_session_cpio_out (GuestfsSession *session, const gchar *directory, const gchar *cpiofile, GuestfsCpioOut *optargs, GCancellable *cancellable, GError **err);
gboolean guestfs_session_dd (GuestfsSession *session, const gchar *src, const gchar *dest, GError **err);
gchar *guestfs_session_debug (GuestfsSession *session, const gchar *subcmd, gchar *const *extraargs, GError **err);
gchar **guestfs_session_debug_drives (GuestfsSession *session, GError **err);
gboolean guestfs_session_debug_upload (GuestfsSession *session, const gchar *filename, const gchar *tmpname, gint32 mode, GCancellable *cancellable, GError **err);
gint32 guestfs_session_device_index (GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_df (GuestfsSession *session, GError **err);
gchar *guestfs_session_df_h (GuestfsSession *session, GError **err);
gboolean guestfs_session_disk_create (GuestfsSession *session, const gchar *filename, const gchar *format, gint64 size, GuestfsDiskCreate *optargs, GError **err);
gchar *guestfs_session_disk_format (GuestfsSession *session, const gchar *filename, GError **err);
gint8 guestfs_session_disk_has_backing_file (GuestfsSession *session, const gchar *filename, GError **err);
gint64 guestfs_session_disk_virtual_size (GuestfsSession *session, const gchar *filename, GError **err);
gchar *guestfs_session_dmesg (GuestfsSession *session, GError **err);
gboolean guestfs_session_download (GuestfsSession *session, const gchar *remotefilename, const gchar *filename, GCancellable *cancellable, GError **err);
gboolean guestfs_session_download_blocks (GuestfsSession *session, const gchar *device, gint64 start, gint64 stop, const gchar *filename, GuestfsDownloadBlocks *optargs, GCancellable *cancellable, GError **err);
gboolean guestfs_session_download_inode (GuestfsSession *session, const gchar *device, gint64 inode, const gchar *filename, GCancellable *cancellable, GError **err);
gboolean guestfs_session_download_offset (GuestfsSession *session, const gchar *remotefilename, const gchar *filename, gint64 offset, gint64 size, GCancellable *cancellable, GError **err);
gboolean guestfs_session_drop_caches (GuestfsSession *session, gint32 whattodrop, GError **err);
gint64 guestfs_session_du (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_e2fsck (GuestfsSession *session, const gchar *device, GuestfsE2fsck *optargs, GError **err);
gboolean guestfs_session_e2fsck_f (GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_echo_daemon (GuestfsSession *session, gchar *const *words, GError **err);
gchar **guestfs_session_egrep (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gchar **guestfs_session_egrepi (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gint8 guestfs_session_equal (GuestfsSession *session, const gchar *file1, const gchar *file2, GError **err);
gint8 guestfs_session_exists (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_extlinux (GuestfsSession *session, const gchar *directory, GError **err);
gboolean guestfs_session_fallocate (GuestfsSession *session, const gchar *path, gint32 len, GError **err);
gboolean guestfs_session_fallocate64 (GuestfsSession *session, const gchar *path, gint64 len, GError **err);
gint8 guestfs_session_feature_available (GuestfsSession *session, gchar *const *groups, GError **err);
gchar **guestfs_session_fgrep (GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err);
gchar **guestfs_session_fgrepi (GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err);
gchar *guestfs_session_file (GuestfsSession *session, const gchar *path, GError **err);
gchar *guestfs_session_file_architecture (GuestfsSession *session, const gchar *filename, GError **err);
gint64 guestfs_session_filesize (GuestfsSession *session, const gchar *file, GError **err);
gint8 guestfs_session_filesystem_available (GuestfsSession *session, const gchar *filesystem, GError **err);
GuestfsTSKDirent **guestfs_session_filesystem_walk (GuestfsSession *session, const gchar *device, GCancellable *cancellable, GError **err);
gboolean guestfs_session_fill (GuestfsSession *session, gint32 c, gint32 len, const gchar *path, GError **err);
gboolean guestfs_session_fill_dir (GuestfsSession *session, const gchar *dir, gint32 nr, GError **err);
gboolean guestfs_session_fill_pattern (GuestfsSession *session, const gchar *pattern, gint32 len, const gchar *path, GError **err);
gchar **guestfs_session_find (GuestfsSession *session, const gchar *directory, GError **err);
gboolean guestfs_session_find0 (GuestfsSession *session, const gchar *directory, const gchar *files, GCancellable *cancellable, GError **err);
GuestfsTSKDirent **guestfs_session_find_inode (GuestfsSession *session, const gchar *device, gint64 inode, GCancellable *cancellable, GError **err);
gchar *guestfs_session_findfs_label (GuestfsSession *session, const gchar *label, GError **err);
gchar *guestfs_session_findfs_uuid (GuestfsSession *session, const gchar *uuid, GError **err);
gint32 guestfs_session_fsck (GuestfsSession *session, const gchar *fstype, const gchar *device, GError **err);
gboolean guestfs_session_fstrim (GuestfsSession *session, const gchar *mountpoint, GuestfsFstrim *optargs, GError **err);
const gchar *guestfs_session_get_append (GuestfsSession *session, GError **err);
gchar *guestfs_session_get_attach_method (GuestfsSession *session, GError **err);
gint8 guestfs_session_get_autosync (GuestfsSession *session, GError **err);
gchar *guestfs_session_get_backend (GuestfsSession *session, GError **err);
gchar *guestfs_session_get_backend_setting (GuestfsSession *session, const gchar *name, GError **err);
gchar **guestfs_session_get_backend_settings (GuestfsSession *session, GError **err);
gchar *guestfs_session_get_cachedir (GuestfsSession *session, GError **err);
gint8 guestfs_session_get_direct (GuestfsSession *session, GError **err);
gchar *guestfs_session_get_e2attrs (GuestfsSession *session, const gchar *file, GError **err);
gint64 guestfs_session_get_e2generation (GuestfsSession *session, const gchar *file, GError **err);
gchar *guestfs_session_get_e2label (GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_get_e2uuid (GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_get_hv (GuestfsSession *session, GError **err);
const gchar *guestfs_session_get_identifier (GuestfsSession *session, GError **err);
gchar *guestfs_session_get_libvirt_requested_credential_challenge (GuestfsSession *session, gint32 index, GError **err);
gchar *guestfs_session_get_libvirt_requested_credential_defresult (GuestfsSession *session, gint32 index, GError **err);
gchar *guestfs_session_get_libvirt_requested_credential_prompt (GuestfsSession *session, gint32 index, GError **err);
gchar **guestfs_session_get_libvirt_requested_credentials (GuestfsSession *session, GError **err);
gint32 guestfs_session_get_memsize (GuestfsSession *session, GError **err);
gint8 guestfs_session_get_network (GuestfsSession *session, GError **err);
const gchar *guestfs_session_get_path (GuestfsSession *session, GError **err);
gint8 guestfs_session_get_pgroup (GuestfsSession *session, GError **err);
gint32 guestfs_session_get_pid (GuestfsSession *session, GError **err);
const gchar *guestfs_session_get_program (GuestfsSession *session, GError **err);
const gchar *guestfs_session_get_qemu (GuestfsSession *session, GError **err);
gint8 guestfs_session_get_recovery_proc (GuestfsSession *session, GError **err);
gint8 guestfs_session_get_selinux (GuestfsSession *session, GError **err);
gint32 guestfs_session_get_smp (GuestfsSession *session, GError **err);
gchar *guestfs_session_get_sockdir (GuestfsSession *session, GError **err);
gint32 guestfs_session_get_state (GuestfsSession *session, GError **err);
gchar *guestfs_session_get_tmpdir (GuestfsSession *session, GError **err);
gint8 guestfs_session_get_trace (GuestfsSession *session, GError **err);
gint32 guestfs_session_get_umask (GuestfsSession *session, GError **err);
gint8 guestfs_session_get_verbose (GuestfsSession *session, GError **err);
gchar *guestfs_session_getcon (GuestfsSession *session, GError **err);
guint8 *guestfs_session_getxattr (GuestfsSession *session, const gchar *path, const gchar *name, gsize *size_r, GError **err);
GuestfsXAttr **guestfs_session_getxattrs (GuestfsSession *session, const gchar *path, GError **err);
gchar **guestfs_session_glob_expand (GuestfsSession *session, const gchar *pattern, GuestfsGlobExpand *optargs, GError **err);
gchar **guestfs_session_grep (GuestfsSession *session, const gchar *regex, const gchar *path, GuestfsGrep *optargs, GError **err);
gchar **guestfs_session_grepi (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gboolean guestfs_session_grub_install (GuestfsSession *session, const gchar *root, const gchar *device, GError **err);
gchar **guestfs_session_head (GuestfsSession *session, const gchar *path, GError **err);
gchar **guestfs_session_head_n (GuestfsSession *session, gint32 nrlines, const gchar *path, GError **err);
gchar *guestfs_session_hexdump (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_hivex_close (GuestfsSession *session, GError **err);
gboolean guestfs_session_hivex_commit (GuestfsSession *session, const gchar *filename, GError **err);
gint64 guestfs_session_hivex_node_add_child (GuestfsSession *session, gint64 parent, const gchar *name, GError **err);
GuestfsHivexNode **guestfs_session_hivex_node_children (GuestfsSession *session, gint64 nodeh, GError **err);
gboolean guestfs_session_hivex_node_delete_child (GuestfsSession *session, gint64 nodeh, GError **err);
gint64 guestfs_session_hivex_node_get_child (GuestfsSession *session, gint64 nodeh, const gchar *name, GError **err);
gint64 guestfs_session_hivex_node_get_value (GuestfsSession *session, gint64 nodeh, const gchar *key, GError **err);
gchar *guestfs_session_hivex_node_name (GuestfsSession *session, gint64 nodeh, GError **err);
gint64 guestfs_session_hivex_node_parent (GuestfsSession *session, gint64 nodeh, GError **err);
gboolean guestfs_session_hivex_node_set_value (GuestfsSession *session, gint64 nodeh, const gchar *key, gint64 t, const guint8 *val, gsize val_size, GError **err);
GuestfsHivexValue **guestfs_session_hivex_node_values (GuestfsSession *session, gint64 nodeh, GError **err);
gboolean guestfs_session_hivex_open (GuestfsSession *session, const gchar *filename, GuestfsHivexOpen *optargs, GError **err);
gint64 guestfs_session_hivex_root (GuestfsSession *session, GError **err);
gchar *guestfs_session_hivex_value_key (GuestfsSession *session, gint64 valueh, GError **err);
gint64 guestfs_session_hivex_value_type (GuestfsSession *session, gint64 valueh, GError **err);
gchar *guestfs_session_hivex_value_utf8 (GuestfsSession *session, gint64 valueh, GError **err);
guint8 *guestfs_session_hivex_value_value (GuestfsSession *session, gint64 valueh, gsize *size_r, GError **err);
guint8 *guestfs_session_initrd_cat (GuestfsSession *session, const gchar *initrdpath, const gchar *filename, gsize *size_r, GError **err);
gchar **guestfs_session_initrd_list (GuestfsSession *session, const gchar *path, GError **err);
gint64 guestfs_session_inotify_add_watch (GuestfsSession *session, const gchar *path, gint32 mask, GError **err);
gboolean guestfs_session_inotify_close (GuestfsSession *session, GError **err);
gchar **guestfs_session_inotify_files (GuestfsSession *session, GError **err);
gboolean guestfs_session_inotify_init (GuestfsSession *session, gint32 maxevents, GError **err);
GuestfsINotifyEvent **guestfs_session_inotify_read (GuestfsSession *session, GError **err);
gboolean guestfs_session_inotify_rm_watch (GuestfsSession *session, gint32 wd, GError **err);
gchar *guestfs_session_inspect_get_arch (GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_distro (GuestfsSession *session, const gchar *root, GError **err);
GHashTable *guestfs_session_inspect_get_drive_mappings (GuestfsSession *session, const gchar *root, GError **err);
gchar **guestfs_session_inspect_get_filesystems (GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_format (GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_hostname (GuestfsSession *session, const gchar *root, GError **err);
guint8 *guestfs_session_inspect_get_icon (GuestfsSession *session, const gchar *root, GuestfsInspectGetIcon *optargs, gsize *size_r, GError **err);
gint32 guestfs_session_inspect_get_major_version (GuestfsSession *session, const gchar *root, GError **err);
gint32 guestfs_session_inspect_get_minor_version (GuestfsSession *session, const gchar *root, GError **err);
GHashTable *guestfs_session_inspect_get_mountpoints (GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_package_format (GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_package_management (GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_product_name (GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_product_variant (GuestfsSession *session, const gchar *root, GError **err);
gchar **guestfs_session_inspect_get_roots (GuestfsSession *session, GError **err);
gchar *guestfs_session_inspect_get_type (GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_windows_current_control_set (GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_windows_software_hive (GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_windows_system_hive (GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_windows_systemroot (GuestfsSession *session, const gchar *root, GError **err);
gint8 guestfs_session_inspect_is_live (GuestfsSession *session, const gchar *root, GError **err);
gint8 guestfs_session_inspect_is_multipart (GuestfsSession *session, const gchar *root, GError **err);
gint8 guestfs_session_inspect_is_netinst (GuestfsSession *session, const gchar *root, GError **err);
GuestfsApplication **guestfs_session_inspect_list_applications (GuestfsSession *session, const gchar *root, GError **err);
GuestfsApplication2 **guestfs_session_inspect_list_applications2 (GuestfsSession *session, const gchar *root, GError **err);
gchar **guestfs_session_inspect_os (GuestfsSession *session, GError **err);
gboolean guestfs_session_internal_exit (GuestfsSession *session, GCancellable *cancellable, GError **err);
gboolean guestfs_session_internal_test (GuestfsSession *session, const gchar *str, const gchar *optstr, gchar *const *strlist, gboolean b, gint32 integer, gint64 integer64, const gchar *filein, const gchar *fileout, const guint8 *bufferin, gsize bufferin_size, GuestfsInternalTest *optargs, GCancellable *cancellable, GError **err);
gboolean guestfs_session_internal_test_63_optargs (GuestfsSession *session, GuestfsInternalTest63Optargs *optargs, GCancellable *cancellable, GError **err);
gboolean guestfs_session_internal_test_close_output (GuestfsSession *session, GError **err);
gboolean guestfs_session_internal_test_only_optargs (GuestfsSession *session, GuestfsInternalTestOnlyOptargs *optargs, GCancellable *cancellable, GError **err);
gint8 guestfs_session_internal_test_rbool (GuestfsSession *session, const gchar *val, GError **err);
gint8 guestfs_session_internal_test_rboolerr (GuestfsSession *session, GError **err);
guint8 *guestfs_session_internal_test_rbufferout (GuestfsSession *session, const gchar *val, gsize *size_r, GError **err);
guint8 *guestfs_session_internal_test_rbufferouterr (GuestfsSession *session, gsize *size_r, GError **err);
const gchar *guestfs_session_internal_test_rconstoptstring (GuestfsSession *session, const gchar *val, GError **err);
const gchar *guestfs_session_internal_test_rconstoptstringerr (GuestfsSession *session, GError **err);
const gchar *guestfs_session_internal_test_rconststring (GuestfsSession *session, const gchar *val, GError **err);
const gchar *guestfs_session_internal_test_rconststringerr (GuestfsSession *session, GError **err);
GHashTable *guestfs_session_internal_test_rhashtable (GuestfsSession *session, const gchar *val, GError **err);
GHashTable *guestfs_session_internal_test_rhashtableerr (GuestfsSession *session, GError **err);
gint32 guestfs_session_internal_test_rint (GuestfsSession *session, const gchar *val, GError **err);
gint64 guestfs_session_internal_test_rint64 (GuestfsSession *session, const gchar *val, GError **err);
gint64 guestfs_session_internal_test_rint64err (GuestfsSession *session, GError **err);
gint32 guestfs_session_internal_test_rinterr (GuestfsSession *session, GError **err);
gchar *guestfs_session_internal_test_rstring (GuestfsSession *session, const gchar *val, GError **err);
gchar *guestfs_session_internal_test_rstringerr (GuestfsSession *session, GError **err);
gchar **guestfs_session_internal_test_rstringlist (GuestfsSession *session, const gchar *val, GError **err);
gchar **guestfs_session_internal_test_rstringlisterr (GuestfsSession *session, GError **err);
GuestfsPV *guestfs_session_internal_test_rstruct (GuestfsSession *session, const gchar *val, GError **err);
GuestfsPV *guestfs_session_internal_test_rstructerr (GuestfsSession *session, GError **err);
GuestfsPV **guestfs_session_internal_test_rstructlist (GuestfsSession *session, const gchar *val, GError **err);
GuestfsPV **guestfs_session_internal_test_rstructlisterr (GuestfsSession *session, GError **err);
gboolean guestfs_session_internal_test_set_output (GuestfsSession *session, const gchar *filename, GError **err);
gint8 guestfs_session_is_blockdev (GuestfsSession *session, const gchar *path, GuestfsIsBlockdev *optargs, GError **err);
gint8 guestfs_session_is_busy (GuestfsSession *session, GError **err);
gint8 guestfs_session_is_chardev (GuestfsSession *session, const gchar *path, GuestfsIsChardev *optargs, GError **err);
gint8 guestfs_session_is_config (GuestfsSession *session, GError **err);
gint8 guestfs_session_is_dir (GuestfsSession *session, const gchar *path, GuestfsIsDir *optargs, GError **err);
gint8 guestfs_session_is_fifo (GuestfsSession *session, const gchar *path, GuestfsIsFifo *optargs, GError **err);
gint8 guestfs_session_is_file (GuestfsSession *session, const gchar *path, GuestfsIsFile *optargs, GError **err);
gint8 guestfs_session_is_launching (GuestfsSession *session, GError **err);
gint8 guestfs_session_is_lv (GuestfsSession *session, const gchar *mountable, GError **err);
gint8 guestfs_session_is_ready (GuestfsSession *session, GError **err);
gint8 guestfs_session_is_socket (GuestfsSession *session, const gchar *path, GuestfsIsSocket *optargs, GError **err);
gint8 guestfs_session_is_symlink (GuestfsSession *session, const gchar *path, GError **err);
gint8 guestfs_session_is_whole_device (GuestfsSession *session, const gchar *device, GError **err);
gint8 guestfs_session_is_zero (GuestfsSession *session, const gchar *path, GError **err);
gint8 guestfs_session_is_zero_device (GuestfsSession *session, const gchar *device, GError **err);
GuestfsISOInfo *guestfs_session_isoinfo (GuestfsSession *session, const gchar *isofile, GError **err);
GuestfsISOInfo *guestfs_session_isoinfo_device (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_journal_close (GuestfsSession *session, GError **err);
GuestfsXAttr **guestfs_session_journal_get (GuestfsSession *session, GError **err);
gint64 guestfs_session_journal_get_data_threshold (GuestfsSession *session, GError **err);
gint64 guestfs_session_journal_get_realtime_usec (GuestfsSession *session, GError **err);
gint8 guestfs_session_journal_next (GuestfsSession *session, GError **err);
gboolean guestfs_session_journal_open (GuestfsSession *session, const gchar *directory, GError **err);
gboolean guestfs_session_journal_set_data_threshold (GuestfsSession *session, gint64 threshold, GError **err);
gint64 guestfs_session_journal_skip (GuestfsSession *session, gint64 skip, GError **err);
gboolean guestfs_session_kill_subprocess (GuestfsSession *session, GError **err);
gboolean guestfs_session_launch (GuestfsSession *session, GError **err);
gboolean guestfs_session_lchown (GuestfsSession *session, gint32 owner, gint32 group, const gchar *path, GError **err);
gboolean guestfs_session_ldmtool_create_all (GuestfsSession *session, GError **err);
gchar **guestfs_session_ldmtool_diskgroup_disks (GuestfsSession *session, const gchar *diskgroup, GError **err);
gchar *guestfs_session_ldmtool_diskgroup_name (GuestfsSession *session, const gchar *diskgroup, GError **err);
gchar **guestfs_session_ldmtool_diskgroup_volumes (GuestfsSession *session, const gchar *diskgroup, GError **err);
gboolean guestfs_session_ldmtool_remove_all (GuestfsSession *session, GError **err);
gchar **guestfs_session_ldmtool_scan (GuestfsSession *session, GError **err);
gchar **guestfs_session_ldmtool_scan_devices (GuestfsSession *session, gchar *const *devices, GError **err);
gchar *guestfs_session_ldmtool_volume_hint (GuestfsSession *session, const gchar *diskgroup, const gchar *volume, GError **err);
gchar **guestfs_session_ldmtool_volume_partitions (GuestfsSession *session, const gchar *diskgroup, const gchar *volume, GError **err);
gchar *guestfs_session_ldmtool_volume_type (GuestfsSession *session, const gchar *diskgroup, const gchar *volume, GError **err);
guint8 *guestfs_session_lgetxattr (GuestfsSession *session, const gchar *path, const gchar *name, gsize *size_r, GError **err);
GuestfsXAttr **guestfs_session_lgetxattrs (GuestfsSession *session, const gchar *path, GError **err);
gchar **guestfs_session_list_9p (GuestfsSession *session, GError **err);
gchar **guestfs_session_list_devices (GuestfsSession *session, GError **err);
GHashTable *guestfs_session_list_disk_labels (GuestfsSession *session, GError **err);
gchar **guestfs_session_list_dm_devices (GuestfsSession *session, GError **err);
GHashTable *guestfs_session_list_filesystems (GuestfsSession *session, GError **err);
gchar **guestfs_session_list_ldm_partitions (GuestfsSession *session, GError **err);
gchar **guestfs_session_list_ldm_volumes (GuestfsSession *session, GError **err);
gchar **guestfs_session_list_md_devices (GuestfsSession *session, GError **err);
gchar **guestfs_session_list_partitions (GuestfsSession *session, GError **err);
gchar *guestfs_session_ll (GuestfsSession *session, const gchar *directory, GError **err);
gchar *guestfs_session_llz (GuestfsSession *session, const gchar *directory, GError **err);
gboolean guestfs_session_ln (GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err);
gboolean guestfs_session_ln_f (GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err);
gboolean guestfs_session_ln_s (GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err);
gboolean guestfs_session_ln_sf (GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err);
gboolean guestfs_session_lremovexattr (GuestfsSession *session, const gchar *xattr, const gchar *path, GError **err);
gchar **guestfs_session_ls (GuestfsSession *session, const gchar *directory, GError **err);
gboolean guestfs_session_ls0 (GuestfsSession *session, const gchar *dir, const gchar *filenames, GError **err);
gboolean guestfs_session_lsetxattr (GuestfsSession *session, const gchar *xattr, const gchar *val, gint32 vallen, const gchar *path, GError **err);
GuestfsStat *guestfs_session_lstat (GuestfsSession *session, const gchar *path, GError **err);
GuestfsStat **guestfs_session_lstatlist (GuestfsSession *session, const gchar *path, gchar *const *names, GError **err);
GuestfsStatNS *guestfs_session_lstatns (GuestfsSession *session, const gchar *path, GError **err);
GuestfsStatNS **guestfs_session_lstatnslist (GuestfsSession *session, const gchar *path, gchar *const *names, GError **err);
gboolean guestfs_session_luks_add_key (GuestfsSession *session, const gchar *device, const gchar *key, const gchar *newkey, gint32 keyslot, GError **err);
gboolean guestfs_session_luks_close (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_luks_format (GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, GError **err);
gboolean guestfs_session_luks_format_cipher (GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, const gchar *cipher, GError **err);
gboolean guestfs_session_luks_kill_slot (GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, GError **err);
gboolean guestfs_session_luks_open (GuestfsSession *session, const gchar *device, const gchar *key, const gchar *mapname, GError **err);
gboolean guestfs_session_luks_open_ro (GuestfsSession *session, const gchar *device, const gchar *key, const gchar *mapname, GError **err);
gboolean guestfs_session_lvcreate (GuestfsSession *session, const gchar *logvol, const gchar *volgroup, gint32 mbytes, GError **err);
gboolean guestfs_session_lvcreate_free (GuestfsSession *session, const gchar *logvol, const gchar *volgroup, gint32 percent, GError **err);
gchar *guestfs_session_lvm_canonical_lv_name (GuestfsSession *session, const gchar *lvname, GError **err);
gboolean guestfs_session_lvm_clear_filter (GuestfsSession *session, GError **err);
gboolean guestfs_session_lvm_remove_all (GuestfsSession *session, GError **err);
gboolean guestfs_session_lvm_set_filter (GuestfsSession *session, gchar *const *devices, GError **err);
gboolean guestfs_session_lvremove (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_lvrename (GuestfsSession *session, const gchar *logvol, const gchar *newlogvol, GError **err);
gboolean guestfs_session_lvresize (GuestfsSession *session, const gchar *device, gint32 mbytes, GError **err);
gboolean guestfs_session_lvresize_free (GuestfsSession *session, const gchar *lv, gint32 percent, GError **err);
gchar **guestfs_session_lvs (GuestfsSession *session, GError **err);
GuestfsLV **guestfs_session_lvs_full (GuestfsSession *session, GError **err);
gchar *guestfs_session_lvuuid (GuestfsSession *session, const gchar *device, GError **err);
GuestfsXAttr **guestfs_session_lxattrlist (GuestfsSession *session, const gchar *path, gchar *const *names, GError **err);
gint32 guestfs_session_max_disks (GuestfsSession *session, GError **err);
gboolean guestfs_session_md_create (GuestfsSession *session, const gchar *name, gchar *const *devices, GuestfsMDCreate *optargs, GError **err);
GHashTable *guestfs_session_md_detail (GuestfsSession *session, const gchar *md, GError **err);
GuestfsMDStat **guestfs_session_md_stat (GuestfsSession *session, const gchar *md, GError **err);
gboolean guestfs_session_md_stop (GuestfsSession *session, const gchar *md, GError **err);
gboolean guestfs_session_mkdir (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_mkdir_mode (GuestfsSession *session, const gchar *path, gint32 mode, GError **err);
gboolean guestfs_session_mkdir_p (GuestfsSession *session, const gchar *path, GError **err);
gchar *guestfs_session_mkdtemp (GuestfsSession *session, const gchar *tmpl, GError **err);
gboolean guestfs_session_mke2fs (GuestfsSession *session, const gchar *device, GuestfsMke2fs *optargs, GError **err);
gboolean guestfs_session_mke2fs_J (GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *journal, GError **err);
gboolean guestfs_session_mke2fs_JL (GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *label, GError **err);
gboolean guestfs_session_mke2fs_JU (GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *uuid, GError **err);
gboolean guestfs_session_mke2journal (GuestfsSession *session, gint32 blocksize, const gchar *device, GError **err);
gboolean guestfs_session_mke2journal_L (GuestfsSession *session, gint32 blocksize, const gchar *label, const gchar *device, GError **err);
gboolean guestfs_session_mke2journal_U (GuestfsSession *session, gint32 blocksize, const gchar *uuid, const gchar *device, GError **err);
gboolean guestfs_session_mkfifo (GuestfsSession *session, gint32 mode, const gchar *path, GError **err);
gboolean guestfs_session_mkfs (GuestfsSession *session, const gchar *fstype, const gchar *device, GuestfsMkfs *optargs, GError **err);
gboolean guestfs_session_mkfs_b (GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, GError **err);
gboolean guestfs_session_mkfs_btrfs (GuestfsSession *session, gchar *const *devices, GuestfsMkfsBtrfs *optargs, GError **err);
gboolean guestfs_session_mklost_and_found (GuestfsSession *session, const gchar *mountpoint, GError **err);
gboolean guestfs_session_mkmountpoint (GuestfsSession *session, const gchar *exemptpath, GError **err);
gboolean guestfs_session_mknod (GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err);
gboolean guestfs_session_mknod_b (GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err);
gboolean guestfs_session_mknod_c (GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err);
gboolean guestfs_session_mksquashfs (GuestfsSession *session, const gchar *path, const gchar *filename, GuestfsMksquashfs *optargs, GCancellable *cancellable, GError **err);
gboolean guestfs_session_mkswap (GuestfsSession *session, const gchar *device, GuestfsMkswap *optargs, GError **err);
gboolean guestfs_session_mkswap_L (GuestfsSession *session, const gchar *label, const gchar *device, GError **err);
gboolean guestfs_session_mkswap_U (GuestfsSession *session, const gchar *uuid, const gchar *device, GError **err);
gboolean guestfs_session_mkswap_file (GuestfsSession *session, const gchar *path, GError **err);
gchar *guestfs_session_mktemp (GuestfsSession *session, const gchar *tmpl, GuestfsMktemp *optargs, GError **err);
gboolean guestfs_session_modprobe (GuestfsSession *session, const gchar *modulename, GError **err);
gboolean guestfs_session_mount (GuestfsSession *session, const gchar *mountable, const gchar *mountpoint, GError **err);
gboolean guestfs_session_mount_9p (GuestfsSession *session, const gchar *mounttag, const gchar *mountpoint, GuestfsMount9P *optargs, GError **err);
gboolean guestfs_session_mount_local (GuestfsSession *session, const gchar *localmountpoint, GuestfsMountLocal *optargs, GError **err);
gboolean guestfs_session_mount_local_run (GuestfsSession *session, GCancellable *cancellable, GError **err);
gboolean guestfs_session_mount_loop (GuestfsSession *session, const gchar *file, const gchar *mountpoint, GError **err);
gboolean guestfs_session_mount_options (GuestfsSession *session, const gchar *options, const gchar *mountable, const gchar *mountpoint, GError **err);
gboolean guestfs_session_mount_ro (GuestfsSession *session, const gchar *mountable, const gchar *mountpoint, GError **err);
gboolean guestfs_session_mount_vfs (GuestfsSession *session, const gchar *options, const gchar *vfstype, const gchar *mountable, const gchar *mountpoint, GError **err);
gchar *guestfs_session_mountable_device (GuestfsSession *session, const gchar *mountable, GError **err);
gchar *guestfs_session_mountable_subvolume (GuestfsSession *session, const gchar *mountable, GError **err);
GHashTable *guestfs_session_mountpoints (GuestfsSession *session, GError **err);
gchar **guestfs_session_mounts (GuestfsSession *session, GError **err);
gboolean guestfs_session_mv (GuestfsSession *session, const gchar *src, const gchar *dest, GError **err);
gint32 guestfs_session_nr_devices (GuestfsSession *session, GError **err);
gint32 guestfs_session_ntfs_3g_probe (GuestfsSession *session, gboolean rw, const gchar *device, GError **err);
gboolean guestfs_session_ntfscat_i (GuestfsSession *session, const gchar *device, gint64 inode, const gchar *filename, GCancellable *cancellable, GError **err);
gboolean guestfs_session_ntfsclone_in (GuestfsSession *session, const gchar *backupfile, const gchar *device, GCancellable *cancellable, GError **err);
gboolean guestfs_session_ntfsclone_out (GuestfsSession *session, const gchar *device, const gchar *backupfile, GuestfsNtfscloneOut *optargs, GCancellable *cancellable, GError **err);
gboolean guestfs_session_ntfsfix (GuestfsSession *session, const gchar *device, GuestfsNtfsfix *optargs, GError **err);
gboolean guestfs_session_ntfsresize (GuestfsSession *session, const gchar *device, GuestfsNTFSResizeOpts *optargs, GError **err);
gboolean guestfs_session_ntfsresize_size (GuestfsSession *session, const gchar *device, gint64 size, GError **err);
gboolean guestfs_session_parse_environment (GuestfsSession *session, GError **err);
gboolean guestfs_session_parse_environment_list (GuestfsSession *session, gchar *const *environment, GError **err);
gboolean guestfs_session_part_add (GuestfsSession *session, const gchar *device, const gchar *prlogex, gint64 startsect, gint64 endsect, GError **err);
gboolean guestfs_session_part_del (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err);
gboolean guestfs_session_part_disk (GuestfsSession *session, const gchar *device, const gchar *parttype, GError **err);
gboolean guestfs_session_part_expand_gpt (GuestfsSession *session, const gchar *device, GError **err);
gint8 guestfs_session_part_get_bootable (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err);
gchar *guestfs_session_part_get_disk_guid (GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_part_get_gpt_guid (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err);
gchar *guestfs_session_part_get_gpt_type (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err);
gint32 guestfs_session_part_get_mbr_id (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err);
gchar *guestfs_session_part_get_mbr_part_type (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err);
gchar *guestfs_session_part_get_name (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err);
gchar *guestfs_session_part_get_parttype (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_part_init (GuestfsSession *session, const gchar *device, const gchar *parttype, GError **err);
GuestfsPartition **guestfs_session_part_list (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_part_set_bootable (GuestfsSession *session, const gchar *device, gint32 partnum, gboolean bootable, GError **err);
gboolean guestfs_session_part_set_disk_guid (GuestfsSession *session, const gchar *device, const gchar *guid, GError **err);
gboolean guestfs_session_part_set_disk_guid_random (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_part_set_gpt_guid (GuestfsSession *session, const gchar *device, gint32 partnum, const gchar *guid, GError **err);
gboolean guestfs_session_part_set_gpt_type (GuestfsSession *session, const gchar *device, gint32 partnum, const gchar *guid, GError **err);
gboolean guestfs_session_part_set_mbr_id (GuestfsSession *session, const gchar *device, gint32 partnum, gint32 idbyte, GError **err);
gboolean guestfs_session_part_set_name (GuestfsSession *session, const gchar *device, gint32 partnum, const gchar *name, GError **err);
gchar *guestfs_session_part_to_dev (GuestfsSession *session, const gchar *partition, GError **err);
gint32 guestfs_session_part_to_partnum (GuestfsSession *session, const gchar *partition, GError **err);
gboolean guestfs_session_ping_daemon (GuestfsSession *session, GError **err);
guint8 *guestfs_session_pread (GuestfsSession *session, const gchar *path, gint32 count, gint64 offset, gsize *size_r, GError **err);
guint8 *guestfs_session_pread_device (GuestfsSession *session, const gchar *device, gint32 count, gint64 offset, gsize *size_r, GError **err);
gboolean guestfs_session_pvchange_uuid (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_pvchange_uuid_all (GuestfsSession *session, GError **err);
gboolean guestfs_session_pvcreate (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_pvremove (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_pvresize (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_pvresize_size (GuestfsSession *session, const gchar *device, gint64 size, GError **err);
gchar **guestfs_session_pvs (GuestfsSession *session, GError **err);
GuestfsPV **guestfs_session_pvs_full (GuestfsSession *session, GError **err);
gchar *guestfs_session_pvuuid (GuestfsSession *session, const gchar *device, GError **err);
gint32 guestfs_session_pwrite (GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, gint64 offset, GError **err);
gint32 guestfs_session_pwrite_device (GuestfsSession *session, const gchar *device, const guint8 *content, gsize content_size, gint64 offset, GError **err);
guint8 *guestfs_session_read_file (GuestfsSession *session, const gchar *path, gsize *size_r, GError **err);
gchar **guestfs_session_read_lines (GuestfsSession *session, const gchar *path, GError **err);
GuestfsDirent **guestfs_session_readdir (GuestfsSession *session, const gchar *dir, GError **err);
gchar *guestfs_session_readlink (GuestfsSession *session, const gchar *path, GError **err);
gchar **guestfs_session_readlinklist (GuestfsSession *session, const gchar *path, gchar *const *names, GError **err);
gchar *guestfs_session_realpath (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_remount (GuestfsSession *session, const gchar *mountpoint, GuestfsRemount *optargs, GError **err);
gboolean guestfs_session_remove_drive (GuestfsSession *session, const gchar *label, GError **err);
gboolean guestfs_session_removexattr (GuestfsSession *session, const gchar *xattr, const gchar *path, GError **err);
gboolean guestfs_session_rename (GuestfsSession *session, const gchar *oldpath, const gchar *newpath, GError **err);
gboolean guestfs_session_resize2fs (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_resize2fs_M (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_resize2fs_size (GuestfsSession *session, const gchar *device, gint64 size, GError **err);
gboolean guestfs_session_rm (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_rm_f (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_rm_rf (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_rmdir (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_rmmountpoint (GuestfsSession *session, const gchar *exemptpath, GError **err);
gboolean guestfs_session_rsync (GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsRsync *optargs, GError **err);
gboolean guestfs_session_rsync_in (GuestfsSession *session, const gchar *remote, const gchar *dest, GuestfsRsyncIn *optargs, GError **err);
gboolean guestfs_session_rsync_out (GuestfsSession *session, const gchar *src, const gchar *remote, GuestfsRsyncOut *optargs, GError **err);
gboolean guestfs_session_scrub_device (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_scrub_file (GuestfsSession *session, const gchar *file, GError **err);
gboolean guestfs_session_scrub_freespace (GuestfsSession *session, const gchar *dir, GError **err);
gboolean guestfs_session_selinux_relabel (GuestfsSession *session, const gchar *specfile, const gchar *path, GuestfsSelinuxRelabel *optargs, GError **err);
gboolean guestfs_session_set_append (GuestfsSession *session, const gchar *append, GError **err);
gboolean guestfs_session_set_attach_method (GuestfsSession *session, const gchar *backend, GError **err);
gboolean guestfs_session_set_autosync (GuestfsSession *session, gboolean autosync, GError **err);
gboolean guestfs_session_set_backend (GuestfsSession *session, const gchar *backend, GError **err);
gboolean guestfs_session_set_backend_setting (GuestfsSession *session, const gchar *name, const gchar *val, GError **err);
gboolean guestfs_session_set_backend_settings (GuestfsSession *session, gchar *const *settings, GError **err);
gboolean guestfs_session_set_cachedir (GuestfsSession *session, const gchar *cachedir, GError **err);
gboolean guestfs_session_set_direct (GuestfsSession *session, gboolean direct, GError **err);
gboolean guestfs_session_set_e2attrs (GuestfsSession *session, const gchar *file, const gchar *attrs, GuestfsSetE2attrs *optargs, GError **err);
gboolean guestfs_session_set_e2generation (GuestfsSession *session, const gchar *file, gint64 generation, GError **err);
gboolean guestfs_session_set_e2label (GuestfsSession *session, const gchar *device, const gchar *label, GError **err);
gboolean guestfs_session_set_e2uuid (GuestfsSession *session, const gchar *device, const gchar *uuid, GError **err);
gboolean guestfs_session_set_hv (GuestfsSession *session, const gchar *hv, GError **err);
gboolean guestfs_session_set_identifier (GuestfsSession *session, const gchar *identifier, GError **err);
gboolean guestfs_session_set_label (GuestfsSession *session, const gchar *mountable, const gchar *label, GError **err);
gboolean guestfs_session_set_libvirt_requested_credential (GuestfsSession *session, gint32 index, const guint8 *cred, gsize cred_size, GError **err);
gboolean guestfs_session_set_libvirt_supported_credentials (GuestfsSession *session, gchar *const *creds, GError **err);
gboolean guestfs_session_set_memsize (GuestfsSession *session, gint32 memsize, GError **err);
gboolean guestfs_session_set_network (GuestfsSession *session, gboolean network, GError **err);
gboolean guestfs_session_set_path (GuestfsSession *session, const gchar *searchpath, GError **err);
gboolean guestfs_session_set_pgroup (GuestfsSession *session, gboolean pgroup, GError **err);
gboolean guestfs_session_set_program (GuestfsSession *session, const gchar *program, GError **err);
gboolean guestfs_session_set_qemu (GuestfsSession *session, const gchar *hv, GError **err);
gboolean guestfs_session_set_recovery_proc (GuestfsSession *session, gboolean recoveryproc, GError **err);
gboolean guestfs_session_set_selinux (GuestfsSession *session, gboolean selinux, GError **err);
gboolean guestfs_session_set_smp (GuestfsSession *session, gint32 smp, GError **err);
gboolean guestfs_session_set_tmpdir (GuestfsSession *session, const gchar *tmpdir, GError **err);
gboolean guestfs_session_set_trace (GuestfsSession *session, gboolean trace, GError **err);
gboolean guestfs_session_set_uuid (GuestfsSession *session, const gchar *device, const gchar *uuid, GError **err);
gboolean guestfs_session_set_uuid_random (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_set_verbose (GuestfsSession *session, gboolean verbose, GError **err);
gboolean guestfs_session_setcon (GuestfsSession *session, const gchar *context, GError **err);
gboolean guestfs_session_setxattr (GuestfsSession *session, const gchar *xattr, const gchar *val, gint32 vallen, const gchar *path, GError **err);
gboolean guestfs_session_sfdisk (GuestfsSession *session, const gchar *device, gint32 cyls, gint32 heads, gint32 sectors, gchar *const *lines, GError **err);
gboolean guestfs_session_sfdiskM (GuestfsSession *session, const gchar *device, gchar *const *lines, GError **err);
gboolean guestfs_session_sfdisk_N (GuestfsSession *session, const gchar *device, gint32 partnum, gint32 cyls, gint32 heads, gint32 sectors, const gchar *line, GError **err);
gchar *guestfs_session_sfdisk_disk_geometry (GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_sfdisk_kernel_geometry (GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_sfdisk_l (GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_sh (GuestfsSession *session, const gchar *command, GError **err);
gchar **guestfs_session_sh_lines (GuestfsSession *session, const gchar *command, GError **err);
gboolean guestfs_session_shutdown (GuestfsSession *session, GError **err);
gboolean guestfs_session_sleep (GuestfsSession *session, gint32 secs, GError **err);
GuestfsStat *guestfs_session_stat (GuestfsSession *session, const gchar *path, GError **err);
GuestfsStatNS *guestfs_session_statns (GuestfsSession *session, const gchar *path, GError **err);
GuestfsStatVFS *guestfs_session_statvfs (GuestfsSession *session, const gchar *path, GError **err);
gchar **guestfs_session_strings (GuestfsSession *session, const gchar *path, GError **err);
gchar **guestfs_session_strings_e (GuestfsSession *session, const gchar *encoding, const gchar *path, GError **err);
gboolean guestfs_session_swapoff_device (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_swapoff_file (GuestfsSession *session, const gchar *file, GError **err);
gboolean guestfs_session_swapoff_label (GuestfsSession *session, const gchar *label, GError **err);
gboolean guestfs_session_swapoff_uuid (GuestfsSession *session, const gchar *uuid, GError **err);
gboolean guestfs_session_swapon_device (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_swapon_file (GuestfsSession *session, const gchar *file, GError **err);
gboolean guestfs_session_swapon_label (GuestfsSession *session, const gchar *label, GError **err);
gboolean guestfs_session_swapon_uuid (GuestfsSession *session, const gchar *uuid, GError **err);
gboolean guestfs_session_sync (GuestfsSession *session, GError **err);
gboolean guestfs_session_syslinux (GuestfsSession *session, const gchar *device, GuestfsSyslinux *optargs, GError **err);
gchar **guestfs_session_tail (GuestfsSession *session, const gchar *path, GError **err);
gchar **guestfs_session_tail_n (GuestfsSession *session, gint32 nrlines, const gchar *path, GError **err);
gboolean guestfs_session_tar_in (GuestfsSession *session, const gchar *tarfile, const gchar *directory, GuestfsTarIn *optargs, GCancellable *cancellable, GError **err);
gboolean guestfs_session_tar_out (GuestfsSession *session, const gchar *directory, const gchar *tarfile, GuestfsTarOut *optargs, GCancellable *cancellable, GError **err);
gboolean guestfs_session_tgz_in (GuestfsSession *session, const gchar *tarball, const gchar *directory, GCancellable *cancellable, GError **err);
gboolean guestfs_session_tgz_out (GuestfsSession *session, const gchar *directory, const gchar *tarball, GCancellable *cancellable, GError **err);
gboolean guestfs_session_touch (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_truncate (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_truncate_size (GuestfsSession *session, const gchar *path, gint64 size, GError **err);
gboolean guestfs_session_tune2fs (GuestfsSession *session, const gchar *device, GuestfsTune2FS *optargs, GError **err);
GHashTable *guestfs_session_tune2fs_l (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_txz_in (GuestfsSession *session, const gchar *tarball, const gchar *directory, GCancellable *cancellable, GError **err);
gboolean guestfs_session_txz_out (GuestfsSession *session, const gchar *directory, const gchar *tarball, GCancellable *cancellable, GError **err);
gint32 guestfs_session_umask (GuestfsSession *session, gint32 mask, GError **err);
gboolean guestfs_session_umount (GuestfsSession *session, const gchar *pathordevice, GuestfsUmount *optargs, GError **err);
gboolean guestfs_session_umount_all (GuestfsSession *session, GError **err);
gboolean guestfs_session_umount_local (GuestfsSession *session, GuestfsUmountLocal *optargs, GError **err);
gboolean guestfs_session_upload (GuestfsSession *session, const gchar *filename, const gchar *remotefilename, GCancellable *cancellable, GError **err);
gboolean guestfs_session_upload_offset (GuestfsSession *session, const gchar *filename, const gchar *remotefilename, gint64 offset, GCancellable *cancellable, GError **err);
gboolean guestfs_session_user_cancel (GuestfsSession *session, GError **err);
gboolean guestfs_session_utimens (GuestfsSession *session, const gchar *path, gint64 atsecs, gint64 atnsecs, gint64 mtsecs, gint64 mtnsecs, GError **err);
GuestfsUTSName *guestfs_session_utsname (GuestfsSession *session, GError **err);
GuestfsVersion *guestfs_session_version (GuestfsSession *session, GError **err);
gchar *guestfs_session_vfs_label (GuestfsSession *session, const gchar *mountable, GError **err);
gint64 guestfs_session_vfs_minimum_size (GuestfsSession *session, const gchar *mountable, GError **err);
gchar *guestfs_session_vfs_type (GuestfsSession *session, const gchar *mountable, GError **err);
gchar *guestfs_session_vfs_uuid (GuestfsSession *session, const gchar *mountable, GError **err);
gboolean guestfs_session_vg_activate (GuestfsSession *session, gboolean activate, gchar *const *volgroups, GError **err);
gboolean guestfs_session_vg_activate_all (GuestfsSession *session, gboolean activate, GError **err);
gboolean guestfs_session_vgchange_uuid (GuestfsSession *session, const gchar *vg, GError **err);
gboolean guestfs_session_vgchange_uuid_all (GuestfsSession *session, GError **err);
gboolean guestfs_session_vgcreate (GuestfsSession *session, const gchar *volgroup, gchar *const *physvols, GError **err);
gchar **guestfs_session_vglvuuids (GuestfsSession *session, const gchar *vgname, GError **err);
guint8 *guestfs_session_vgmeta (GuestfsSession *session, const gchar *vgname, gsize *size_r, GError **err);
gchar **guestfs_session_vgpvuuids (GuestfsSession *session, const gchar *vgname, GError **err);
gboolean guestfs_session_vgremove (GuestfsSession *session, const gchar *vgname, GError **err);
gboolean guestfs_session_vgrename (GuestfsSession *session, const gchar *volgroup, const gchar *newvolgroup, GError **err);
gchar **guestfs_session_vgs (GuestfsSession *session, GError **err);
GuestfsVG **guestfs_session_vgs_full (GuestfsSession *session, GError **err);
gboolean guestfs_session_vgscan (GuestfsSession *session, GError **err);
gchar *guestfs_session_vguuid (GuestfsSession *session, const gchar *vgname, GError **err);
gboolean guestfs_session_wait_ready (GuestfsSession *session, GError **err);
gint32 guestfs_session_wc_c (GuestfsSession *session, const gchar *path, GError **err);
gint32 guestfs_session_wc_l (GuestfsSession *session, const gchar *path, GError **err);
gint32 guestfs_session_wc_w (GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_wipefs (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_write (GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, GError **err);
gboolean guestfs_session_write_append (GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, GError **err);
gboolean guestfs_session_write_file (GuestfsSession *session, const gchar *path, const gchar *content, gint32 size, GError **err);
gboolean guestfs_session_xfs_admin (GuestfsSession *session, const gchar *device, GuestfsXfsAdmin *optargs, GError **err);
gboolean guestfs_session_xfs_growfs (GuestfsSession *session, const gchar *path, GuestfsXfsGrowfs *optargs, GError **err);
GuestfsXFSInfo *guestfs_session_xfs_info (GuestfsSession *session, const gchar *pathordevice, GError **err);
gint32 guestfs_session_xfs_repair (GuestfsSession *session, const gchar *device, GuestfsXfsRepair *optargs, GError **err);
gchar **guestfs_session_zegrep (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gchar **guestfs_session_zegrepi (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gboolean guestfs_session_zero (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_zero_device (GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_zero_free_space (GuestfsSession *session, const gchar *directory, GError **err);
gboolean guestfs_session_zerofree (GuestfsSession *session, const gchar *device, GError **err);
gchar **guestfs_session_zfgrep (GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err);
gchar **guestfs_session_zfgrepi (GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err);
gchar *guestfs_session_zfile (GuestfsSession *session, const gchar *meth, const gchar *path, GError **err);
gchar **guestfs_session_zgrep (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gchar **guestfs_session_zgrepi (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_SESSION_H__ */
