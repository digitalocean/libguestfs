/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/* ---------- IMPORTANT NOTE ----------
 *
 * All API documentation is in the manpage, 'guestfs(3)'.
 * To read it, type:           man 3 guestfs
 * Or read it online here:     http://libguestfs.org/guestfs.3.html
 *
 * Go and read it now, I'll be right here waiting for you
 * when you come back.
 *
 * ------------------------------------
 */

#ifndef GUESTFS_H_
#define GUESTFS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#ifdef __GNUC__
# define GUESTFS_GCC_VERSION \
    (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#endif

/* Define GUESTFS_WARN_DEPRECATED=1 to warn about deprecated API functions. */
#define GUESTFS_DEPRECATED_BY(s)
#if GUESTFS_WARN_DEPRECATED
#  if defined(__GNUC__) && GUESTFS_GCC_VERSION >= 40500 /* gcc >= 4.5 */
#    undef GUESTFS_DEPRECATED_BY
#    define GUESTFS_DEPRECATED_BY(s) __attribute__((__deprecated__("change the program to use guestfs_" s " instead of this deprecated function")))
#  endif
#endif /* GUESTFS_WARN_DEPRECATED */

#if defined(__GNUC__) && GUESTFS_GCC_VERSION >= 40000 /* gcc >= 4.0 */
# define GUESTFS_DLL_PUBLIC __attribute__((visibility ("default")))
#endif

/* The handle. */
#ifndef GUESTFS_TYPEDEF_H
#define GUESTFS_TYPEDEF_H 1
typedef struct guestfs_h guestfs_h;
#endif

/* Connection management. */
extern GUESTFS_DLL_PUBLIC guestfs_h *guestfs_create (void);
extern GUESTFS_DLL_PUBLIC void guestfs_close (guestfs_h *g);

/* Error handling. */
extern GUESTFS_DLL_PUBLIC const char *guestfs_last_error (guestfs_h *g);
#define LIBGUESTFS_HAVE_LAST_ERRNO 1
extern GUESTFS_DLL_PUBLIC int guestfs_last_errno (guestfs_h *g);

#ifndef GUESTFS_TYPEDEF_ERROR_HANDLER_CB
#define GUESTFS_TYPEDEF_ERROR_HANDLER_CB 1
typedef void (*guestfs_error_handler_cb) (guestfs_h *g, void *opaque, const char *msg);
#endif

#ifndef GUESTFS_TYPEDEF_ABORT_CB
#define GUESTFS_TYPEDEF_ABORT_CB 1
typedef void (*guestfs_abort_cb) (void) __attribute__((__noreturn__));
#endif

extern GUESTFS_DLL_PUBLIC void guestfs_set_error_handler (guestfs_h *g, guestfs_error_handler_cb cb, void *opaque);
extern GUESTFS_DLL_PUBLIC guestfs_error_handler_cb guestfs_get_error_handler (guestfs_h *g, void **opaque_rtn);

extern GUESTFS_DLL_PUBLIC void guestfs_set_out_of_memory_handler (guestfs_h *g, guestfs_abort_cb);
extern GUESTFS_DLL_PUBLIC guestfs_abort_cb guestfs_get_out_of_memory_handler (guestfs_h *g);

/* Events. */
#define GUESTFS_EVENT_CLOSE            0x0001
#define GUESTFS_EVENT_SUBPROCESS_QUIT  0x0002
#define GUESTFS_EVENT_LAUNCH_DONE      0x0004
#define GUESTFS_EVENT_PROGRESS         0x0008
#define GUESTFS_EVENT_APPLIANCE        0x0010
#define GUESTFS_EVENT_LIBRARY          0x0020
#define GUESTFS_EVENT_TRACE            0x0040
#define GUESTFS_EVENT_ENTER            0x0080
#define GUESTFS_EVENT_ALL              UINT64_MAX

#ifndef GUESTFS_TYPEDEF_EVENT_CALLBACK
#define GUESTFS_TYPEDEF_EVENT_CALLBACK 1
typedef void (*guestfs_event_callback) (
                        guestfs_h *g,
                        void *opaque,
                        uint64_t event,
                        int event_handle,
                        int flags,
                        const char *buf, size_t buf_len,
                        const uint64_t *array, size_t array_len);
#endif

#define LIBGUESTFS_HAVE_SET_EVENT_CALLBACK 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_event_callback (guestfs_h *g, guestfs_event_callback cb, uint64_t event_bitmask, int flags, void *opaque);
#define LIBGUESTFS_HAVE_DELETE_EVENT_CALLBACK 1
extern GUESTFS_DLL_PUBLIC void guestfs_delete_event_callback (guestfs_h *g, int event_handle);

/* Old-style event handling. */
#ifndef GUESTFS_TYPEDEF_LOG_MESSAGE_CB
#define GUESTFS_TYPEDEF_LOG_MESSAGE_CB 1
typedef void (*guestfs_log_message_cb) (guestfs_h *g, void *opaque, char *buf, int len);
#endif

#ifndef GUESTFS_TYPEDEF_SUBPROCESS_QUIT_CB
#define GUESTFS_TYPEDEF_SUBPROCESS_QUIT_CB 1
typedef void (*guestfs_subprocess_quit_cb) (guestfs_h *g, void *opaque);
#endif

#ifndef GUESTFS_TYPEDEF_LAUNCH_DONE_CB
#define GUESTFS_TYPEDEF_LAUNCH_DONE_CB 1
typedef void (*guestfs_launch_done_cb) (guestfs_h *g, void *opaque);
#endif

#ifndef GUESTFS_TYPEDEF_CLOSE_CB
#define GUESTFS_TYPEDEF_CLOSE_CB 1
typedef void (*guestfs_close_cb) (guestfs_h *g, void *opaque);
#endif

#ifndef GUESTFS_TYPEDEF_PROGRESS_CB
#define GUESTFS_TYPEDEF_PROGRESS_CB 1
typedef void (*guestfs_progress_cb) (guestfs_h *g, void *opaque, int proc_nr, int serial, uint64_t position, uint64_t total);
#endif

extern GUESTFS_DLL_PUBLIC void guestfs_set_log_message_callback (guestfs_h *g, guestfs_log_message_cb cb, void *opaque)
  GUESTFS_DEPRECATED_BY("set_event_callback");
extern GUESTFS_DLL_PUBLIC void guestfs_set_subprocess_quit_callback (guestfs_h *g, guestfs_subprocess_quit_cb cb, void *opaque)
  GUESTFS_DEPRECATED_BY("set_event_callback");
extern GUESTFS_DLL_PUBLIC void guestfs_set_launch_done_callback (guestfs_h *g, guestfs_launch_done_cb cb, void *opaque)
  GUESTFS_DEPRECATED_BY("set_event_callback");
#define LIBGUESTFS_HAVE_SET_CLOSE_CALLBACK 1
extern GUESTFS_DLL_PUBLIC void guestfs_set_close_callback (guestfs_h *g, guestfs_close_cb cb, void *opaque)
  GUESTFS_DEPRECATED_BY("set_event_callback");
#define LIBGUESTFS_HAVE_SET_PROGRESS_CALLBACK 1
extern GUESTFS_DLL_PUBLIC void guestfs_set_progress_callback (guestfs_h *g, guestfs_progress_cb cb, void *opaque)
  GUESTFS_DEPRECATED_BY("set_event_callback");

/* User cancellation. */
#define LIBGUESTFS_HAVE_USER_CANCEL 1
extern GUESTFS_DLL_PUBLIC void guestfs_user_cancel (guestfs_h *g);

/* Private data area. */
#define LIBGUESTFS_HAVE_SET_PRIVATE 1
extern GUESTFS_DLL_PUBLIC void guestfs_set_private (guestfs_h *g, const char *key, void *data);
#define LIBGUESTFS_HAVE_GET_PRIVATE 1
extern GUESTFS_DLL_PUBLIC void *guestfs_get_private (guestfs_h *g, const char *key);
#define LIBGUESTFS_HAVE_FIRST_PRIVATE 1
extern GUESTFS_DLL_PUBLIC void *guestfs_first_private (guestfs_h *g, const char **key_rtn);
#define LIBGUESTFS_HAVE_NEXT_PRIVATE 1
extern GUESTFS_DLL_PUBLIC void *guestfs_next_private (guestfs_h *g, const char **key_rtn);

/* Structures. */
struct guestfs_int_bool {
  int32_t i;
  int32_t b;
};

struct guestfs_int_bool_list {
  uint32_t len;
  struct guestfs_int_bool *val;
};

extern GUESTFS_DLL_PUBLIC void guestfs_free_int_bool (struct guestfs_int_bool *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_int_bool_list (struct guestfs_int_bool_list *);

struct guestfs_lvm_pv {
  char *pv_name;
  char pv_uuid[32]; /* this is NOT nul-terminated, be careful when printing */
  char *pv_fmt;
  uint64_t pv_size;
  uint64_t dev_size;
  uint64_t pv_free;
  uint64_t pv_used;
  char *pv_attr;
  int64_t pv_pe_count;
  int64_t pv_pe_alloc_count;
  char *pv_tags;
  uint64_t pe_start;
  int64_t pv_mda_count;
  uint64_t pv_mda_free;
};

struct guestfs_lvm_pv_list {
  uint32_t len;
  struct guestfs_lvm_pv *val;
};

extern GUESTFS_DLL_PUBLIC void guestfs_free_lvm_pv (struct guestfs_lvm_pv *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_lvm_pv_list (struct guestfs_lvm_pv_list *);

struct guestfs_lvm_vg {
  char *vg_name;
  char vg_uuid[32]; /* this is NOT nul-terminated, be careful when printing */
  char *vg_fmt;
  char *vg_attr;
  uint64_t vg_size;
  uint64_t vg_free;
  char *vg_sysid;
  uint64_t vg_extent_size;
  int64_t vg_extent_count;
  int64_t vg_free_count;
  int64_t max_lv;
  int64_t max_pv;
  int64_t pv_count;
  int64_t lv_count;
  int64_t snap_count;
  int64_t vg_seqno;
  char *vg_tags;
  int64_t vg_mda_count;
  uint64_t vg_mda_free;
};

struct guestfs_lvm_vg_list {
  uint32_t len;
  struct guestfs_lvm_vg *val;
};

extern GUESTFS_DLL_PUBLIC void guestfs_free_lvm_vg (struct guestfs_lvm_vg *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_lvm_vg_list (struct guestfs_lvm_vg_list *);

struct guestfs_lvm_lv {
  char *lv_name;
  char lv_uuid[32]; /* this is NOT nul-terminated, be careful when printing */
  char *lv_attr;
  int64_t lv_major;
  int64_t lv_minor;
  int64_t lv_kernel_major;
  int64_t lv_kernel_minor;
  uint64_t lv_size;
  int64_t seg_count;
  char *origin;
  float snap_percent; /* [0..100] or -1 */
  float copy_percent; /* [0..100] or -1 */
  char *move_pv;
  char *lv_tags;
  char *mirror_log;
  char *modules;
};

struct guestfs_lvm_lv_list {
  uint32_t len;
  struct guestfs_lvm_lv *val;
};

extern GUESTFS_DLL_PUBLIC void guestfs_free_lvm_lv (struct guestfs_lvm_lv *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_lvm_lv_list (struct guestfs_lvm_lv_list *);

struct guestfs_stat {
  int64_t dev;
  int64_t ino;
  int64_t mode;
  int64_t nlink;
  int64_t uid;
  int64_t gid;
  int64_t rdev;
  int64_t size;
  int64_t blksize;
  int64_t blocks;
  int64_t atime;
  int64_t mtime;
  int64_t ctime;
};

struct guestfs_stat_list {
  uint32_t len;
  struct guestfs_stat *val;
};

extern GUESTFS_DLL_PUBLIC void guestfs_free_stat (struct guestfs_stat *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_stat_list (struct guestfs_stat_list *);

struct guestfs_statvfs {
  int64_t bsize;
  int64_t frsize;
  int64_t blocks;
  int64_t bfree;
  int64_t bavail;
  int64_t files;
  int64_t ffree;
  int64_t favail;
  int64_t fsid;
  int64_t flag;
  int64_t namemax;
};

struct guestfs_statvfs_list {
  uint32_t len;
  struct guestfs_statvfs *val;
};

extern GUESTFS_DLL_PUBLIC void guestfs_free_statvfs (struct guestfs_statvfs *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_statvfs_list (struct guestfs_statvfs_list *);

struct guestfs_dirent {
  int64_t ino;
  char ftyp;
  char *name;
};

struct guestfs_dirent_list {
  uint32_t len;
  struct guestfs_dirent *val;
};

extern GUESTFS_DLL_PUBLIC void guestfs_free_dirent (struct guestfs_dirent *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_dirent_list (struct guestfs_dirent_list *);

struct guestfs_version {
  int64_t major;
  int64_t minor;
  int64_t release;
  char *extra;
};

struct guestfs_version_list {
  uint32_t len;
  struct guestfs_version *val;
};

extern GUESTFS_DLL_PUBLIC void guestfs_free_version (struct guestfs_version *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_version_list (struct guestfs_version_list *);

struct guestfs_xattr {
  char *attrname;
  uint32_t attrval_len;
  char *attrval;
};

struct guestfs_xattr_list {
  uint32_t len;
  struct guestfs_xattr *val;
};

extern GUESTFS_DLL_PUBLIC void guestfs_free_xattr (struct guestfs_xattr *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_xattr_list (struct guestfs_xattr_list *);

struct guestfs_inotify_event {
  int64_t in_wd;
  uint32_t in_mask;
  uint32_t in_cookie;
  char *in_name;
};

struct guestfs_inotify_event_list {
  uint32_t len;
  struct guestfs_inotify_event *val;
};

extern GUESTFS_DLL_PUBLIC void guestfs_free_inotify_event (struct guestfs_inotify_event *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_inotify_event_list (struct guestfs_inotify_event_list *);

struct guestfs_partition {
  int32_t part_num;
  uint64_t part_start;
  uint64_t part_end;
  uint64_t part_size;
};

struct guestfs_partition_list {
  uint32_t len;
  struct guestfs_partition *val;
};

extern GUESTFS_DLL_PUBLIC void guestfs_free_partition (struct guestfs_partition *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_partition_list (struct guestfs_partition_list *);

struct guestfs_application {
  char *app_name;
  char *app_display_name;
  int32_t app_epoch;
  char *app_version;
  char *app_release;
  char *app_install_path;
  char *app_trans_path;
  char *app_publisher;
  char *app_url;
  char *app_source_package;
  char *app_summary;
  char *app_description;
};

struct guestfs_application_list {
  uint32_t len;
  struct guestfs_application *val;
};

extern GUESTFS_DLL_PUBLIC void guestfs_free_application (struct guestfs_application *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_application_list (struct guestfs_application_list *);

/* Actions. */
extern GUESTFS_DLL_PUBLIC int guestfs_add_cdrom (guestfs_h *g, const char *filename)
  GUESTFS_DEPRECATED_BY ("add_drive_opts");

#define LIBGUESTFS_HAVE_ADD_DOMAIN 1
#define GUESTFS_ADD_DOMAIN_LIBVIRTURI 0
#define GUESTFS_ADD_DOMAIN_READONLY 1
#define GUESTFS_ADD_DOMAIN_IFACE 2
#define GUESTFS_ADD_DOMAIN_LIVE 3
#define GUESTFS_ADD_DOMAIN_ALLOWUUID 4
#define GUESTFS_ADD_DOMAIN_READONLYDISK 5
extern GUESTFS_DLL_PUBLIC int guestfs_add_domain (guestfs_h *g, const char *dom, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_add_domain_va (guestfs_h *g, const char *dom, va_list args);

struct guestfs_add_domain_argv {
  uint64_t bitmask;

# define GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  const char *libvirturi;

# define GUESTFS_ADD_DOMAIN_READONLY_BITMASK (UINT64_C(1)<<1)
  /* The field below is only valid in this struct if the
   * GUESTFS_ADD_DOMAIN_READONLY_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int readonly;

# define GUESTFS_ADD_DOMAIN_IFACE_BITMASK (UINT64_C(1)<<2)
  /* The field below is only valid in this struct if the
   * GUESTFS_ADD_DOMAIN_IFACE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  const char *iface;

# define GUESTFS_ADD_DOMAIN_LIVE_BITMASK (UINT64_C(1)<<3)
  /* The field below is only valid in this struct if the
   * GUESTFS_ADD_DOMAIN_LIVE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int live;

# define GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK (UINT64_C(1)<<4)
  /* The field below is only valid in this struct if the
   * GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int allowuuid;

# define GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK (UINT64_C(1)<<5)
  /* The field below is only valid in this struct if the
   * GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  const char *readonlydisk;
};

extern GUESTFS_DLL_PUBLIC int guestfs_add_domain_argv (guestfs_h *g, const char *dom, const struct guestfs_add_domain_argv *optargs);

#define LIBGUESTFS_HAVE_ADD_DRIVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_add_drive (guestfs_h *g, const char *filename);

#define LIBGUESTFS_HAVE_ADD_DRIVE_OPTS 1
#define GUESTFS_ADD_DRIVE_OPTS_READONLY 0
#define GUESTFS_ADD_DRIVE_OPTS_FORMAT 1
#define GUESTFS_ADD_DRIVE_OPTS_IFACE 2
#define GUESTFS_ADD_DRIVE_OPTS_NAME 3
extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_opts (guestfs_h *g, const char *filename, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_opts_va (guestfs_h *g, const char *filename, va_list args);

struct guestfs_add_drive_opts_argv {
  uint64_t bitmask;

# define GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int readonly;

# define GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK (UINT64_C(1)<<1)
  /* The field below is only valid in this struct if the
   * GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  const char *format;

# define GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK (UINT64_C(1)<<2)
  /* The field below is only valid in this struct if the
   * GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  const char *iface;

# define GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK (UINT64_C(1)<<3)
  /* The field below is only valid in this struct if the
   * GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  const char *name;
};

extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_opts_argv (guestfs_h *g, const char *filename, const struct guestfs_add_drive_opts_argv *optargs);

#define LIBGUESTFS_HAVE_ADD_DRIVE_RO 1
extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_ro (guestfs_h *g, const char *filename);

extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_ro_with_if (guestfs_h *g, const char *filename, const char *iface)
  GUESTFS_DEPRECATED_BY ("add_drive_opts");

extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_with_if (guestfs_h *g, const char *filename, const char *iface)
  GUESTFS_DEPRECATED_BY ("add_drive_opts");

#define LIBGUESTFS_HAVE_AUG_CLEAR 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_clear (guestfs_h *g, const char *augpath);

#define LIBGUESTFS_HAVE_AUG_CLOSE 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_close (guestfs_h *g);

#define LIBGUESTFS_HAVE_AUG_DEFNODE 1
extern GUESTFS_DLL_PUBLIC struct guestfs_int_bool *guestfs_aug_defnode (guestfs_h *g, const char *name, const char *expr, const char *val);

#define LIBGUESTFS_HAVE_AUG_DEFVAR 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_defvar (guestfs_h *g, const char *name, const char *expr);

#define LIBGUESTFS_HAVE_AUG_GET 1
extern GUESTFS_DLL_PUBLIC char *guestfs_aug_get (guestfs_h *g, const char *augpath);

#define LIBGUESTFS_HAVE_AUG_INIT 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_init (guestfs_h *g, const char *root, int flags);

#define LIBGUESTFS_HAVE_AUG_INSERT 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_insert (guestfs_h *g, const char *augpath, const char *label, int before);

#define LIBGUESTFS_HAVE_AUG_LOAD 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_load (guestfs_h *g);

#define LIBGUESTFS_HAVE_AUG_LS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_aug_ls (guestfs_h *g, const char *augpath);

#define LIBGUESTFS_HAVE_AUG_MATCH 1
extern GUESTFS_DLL_PUBLIC char **guestfs_aug_match (guestfs_h *g, const char *augpath);

#define LIBGUESTFS_HAVE_AUG_MV 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_mv (guestfs_h *g, const char *src, const char *dest);

#define LIBGUESTFS_HAVE_AUG_RM 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_rm (guestfs_h *g, const char *augpath);

#define LIBGUESTFS_HAVE_AUG_SAVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_save (guestfs_h *g);

#define LIBGUESTFS_HAVE_AUG_SET 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_set (guestfs_h *g, const char *augpath, const char *val);

#define LIBGUESTFS_HAVE_AVAILABLE 1
extern GUESTFS_DLL_PUBLIC int guestfs_available (guestfs_h *g, char *const *groups);

#define LIBGUESTFS_HAVE_AVAILABLE_ALL_GROUPS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_available_all_groups (guestfs_h *g);

#define LIBGUESTFS_HAVE_BASE64_IN 1
extern GUESTFS_DLL_PUBLIC int guestfs_base64_in (guestfs_h *g, const char *base64file, const char *filename);

#define LIBGUESTFS_HAVE_BASE64_OUT 1
extern GUESTFS_DLL_PUBLIC int guestfs_base64_out (guestfs_h *g, const char *filename, const char *base64file);

#define LIBGUESTFS_HAVE_BLKID 1
extern GUESTFS_DLL_PUBLIC char **guestfs_blkid (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_BLOCKDEV_FLUSHBUFS 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_flushbufs (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_BLOCKDEV_GETBSZ 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_getbsz (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_BLOCKDEV_GETRO 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_getro (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_BLOCKDEV_GETSIZE64 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_blockdev_getsize64 (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_BLOCKDEV_GETSS 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_getss (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_BLOCKDEV_GETSZ 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_blockdev_getsz (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_BLOCKDEV_REREADPT 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_rereadpt (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_BLOCKDEV_SETBSZ 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_setbsz (guestfs_h *g, const char *device, int blocksize);

#define LIBGUESTFS_HAVE_BLOCKDEV_SETRO 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_setro (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_BLOCKDEV_SETRW 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_setrw (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_BTRFS_FILESYSTEM_RESIZE 1
#define GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE 0
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_filesystem_resize (guestfs_h *g, const char *mountpoint, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_filesystem_resize_va (guestfs_h *g, const char *mountpoint, va_list args);

struct guestfs_btrfs_filesystem_resize_argv {
  uint64_t bitmask;

# define GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t size;
};

extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_filesystem_resize_argv (guestfs_h *g, const char *mountpoint, const struct guestfs_btrfs_filesystem_resize_argv *optargs);

#define LIBGUESTFS_HAVE_CASE_SENSITIVE_PATH 1
extern GUESTFS_DLL_PUBLIC char *guestfs_case_sensitive_path (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_CAT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_cat (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_CHECKSUM 1
extern GUESTFS_DLL_PUBLIC char *guestfs_checksum (guestfs_h *g, const char *csumtype, const char *path);

#define LIBGUESTFS_HAVE_CHECKSUM_DEVICE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_checksum_device (guestfs_h *g, const char *csumtype, const char *device);

#define LIBGUESTFS_HAVE_CHECKSUMS_OUT 1
extern GUESTFS_DLL_PUBLIC int guestfs_checksums_out (guestfs_h *g, const char *csumtype, const char *directory, const char *sumsfile);

#define LIBGUESTFS_HAVE_CHMOD 1
extern GUESTFS_DLL_PUBLIC int guestfs_chmod (guestfs_h *g, int mode, const char *path);

#define LIBGUESTFS_HAVE_CHOWN 1
extern GUESTFS_DLL_PUBLIC int guestfs_chown (guestfs_h *g, int owner, int group, const char *path);

#define LIBGUESTFS_HAVE_COMMAND 1
extern GUESTFS_DLL_PUBLIC char *guestfs_command (guestfs_h *g, char *const *arguments);

#define LIBGUESTFS_HAVE_COMMAND_LINES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_command_lines (guestfs_h *g, char *const *arguments);

#define LIBGUESTFS_HAVE_COMPRESS_DEVICE_OUT 1
#define GUESTFS_COMPRESS_DEVICE_OUT_LEVEL 0
extern GUESTFS_DLL_PUBLIC int guestfs_compress_device_out (guestfs_h *g, const char *ctype, const char *device, const char *zdevice, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_compress_device_out_va (guestfs_h *g, const char *ctype, const char *device, const char *zdevice, va_list args);

struct guestfs_compress_device_out_argv {
  uint64_t bitmask;

# define GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int level;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compress_device_out_argv (guestfs_h *g, const char *ctype, const char *device, const char *zdevice, const struct guestfs_compress_device_out_argv *optargs);

#define LIBGUESTFS_HAVE_COMPRESS_OUT 1
#define GUESTFS_COMPRESS_OUT_LEVEL 0
extern GUESTFS_DLL_PUBLIC int guestfs_compress_out (guestfs_h *g, const char *ctype, const char *file, const char *zfile, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_compress_out_va (guestfs_h *g, const char *ctype, const char *file, const char *zfile, va_list args);

struct guestfs_compress_out_argv {
  uint64_t bitmask;

# define GUESTFS_COMPRESS_OUT_LEVEL_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_COMPRESS_OUT_LEVEL_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int level;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compress_out_argv (guestfs_h *g, const char *ctype, const char *file, const char *zfile, const struct guestfs_compress_out_argv *optargs);

#define LIBGUESTFS_HAVE_CONFIG 1
extern GUESTFS_DLL_PUBLIC int guestfs_config (guestfs_h *g, const char *qemuparam, const char *qemuvalue);

#define LIBGUESTFS_HAVE_COPY_DEVICE_TO_DEVICE 1
#define GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET 0
#define GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET 1
#define GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE 2
extern GUESTFS_DLL_PUBLIC int guestfs_copy_device_to_device (guestfs_h *g, const char *src, const char *dest, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_copy_device_to_device_va (guestfs_h *g, const char *src, const char *dest, va_list args);

struct guestfs_copy_device_to_device_argv {
  uint64_t bitmask;

# define GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t srcoffset;

# define GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
  /* The field below is only valid in this struct if the
   * GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t destoffset;

# define GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK (UINT64_C(1)<<2)
  /* The field below is only valid in this struct if the
   * GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t size;
};

extern GUESTFS_DLL_PUBLIC int guestfs_copy_device_to_device_argv (guestfs_h *g, const char *src, const char *dest, const struct guestfs_copy_device_to_device_argv *optargs);

#define LIBGUESTFS_HAVE_COPY_DEVICE_TO_FILE 1
#define GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET 0
#define GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET 1
#define GUESTFS_COPY_DEVICE_TO_FILE_SIZE 2
extern GUESTFS_DLL_PUBLIC int guestfs_copy_device_to_file (guestfs_h *g, const char *src, const char *dest, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_copy_device_to_file_va (guestfs_h *g, const char *src, const char *dest, va_list args);

struct guestfs_copy_device_to_file_argv {
  uint64_t bitmask;

# define GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t srcoffset;

# define GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
  /* The field below is only valid in this struct if the
   * GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t destoffset;

# define GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK (UINT64_C(1)<<2)
  /* The field below is only valid in this struct if the
   * GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t size;
};

extern GUESTFS_DLL_PUBLIC int guestfs_copy_device_to_file_argv (guestfs_h *g, const char *src, const char *dest, const struct guestfs_copy_device_to_file_argv *optargs);

#define LIBGUESTFS_HAVE_COPY_FILE_TO_DEVICE 1
#define GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET 0
#define GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET 1
#define GUESTFS_COPY_FILE_TO_DEVICE_SIZE 2
extern GUESTFS_DLL_PUBLIC int guestfs_copy_file_to_device (guestfs_h *g, const char *src, const char *dest, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_copy_file_to_device_va (guestfs_h *g, const char *src, const char *dest, va_list args);

struct guestfs_copy_file_to_device_argv {
  uint64_t bitmask;

# define GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t srcoffset;

# define GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
  /* The field below is only valid in this struct if the
   * GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t destoffset;

# define GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK (UINT64_C(1)<<2)
  /* The field below is only valid in this struct if the
   * GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t size;
};

extern GUESTFS_DLL_PUBLIC int guestfs_copy_file_to_device_argv (guestfs_h *g, const char *src, const char *dest, const struct guestfs_copy_file_to_device_argv *optargs);

#define LIBGUESTFS_HAVE_COPY_FILE_TO_FILE 1
#define GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET 0
#define GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET 1
#define GUESTFS_COPY_FILE_TO_FILE_SIZE 2
extern GUESTFS_DLL_PUBLIC int guestfs_copy_file_to_file (guestfs_h *g, const char *src, const char *dest, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_copy_file_to_file_va (guestfs_h *g, const char *src, const char *dest, va_list args);

struct guestfs_copy_file_to_file_argv {
  uint64_t bitmask;

# define GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t srcoffset;

# define GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
  /* The field below is only valid in this struct if the
   * GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t destoffset;

# define GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK (UINT64_C(1)<<2)
  /* The field below is only valid in this struct if the
   * GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t size;
};

extern GUESTFS_DLL_PUBLIC int guestfs_copy_file_to_file_argv (guestfs_h *g, const char *src, const char *dest, const struct guestfs_copy_file_to_file_argv *optargs);

extern GUESTFS_DLL_PUBLIC int guestfs_copy_size (guestfs_h *g, const char *src, const char *dest, int64_t size)
  GUESTFS_DEPRECATED_BY ("copy_device_to_device");

#define LIBGUESTFS_HAVE_CP 1
extern GUESTFS_DLL_PUBLIC int guestfs_cp (guestfs_h *g, const char *src, const char *dest);

#define LIBGUESTFS_HAVE_CP_A 1
extern GUESTFS_DLL_PUBLIC int guestfs_cp_a (guestfs_h *g, const char *src, const char *dest);

extern GUESTFS_DLL_PUBLIC int guestfs_dd (guestfs_h *g, const char *src, const char *dest)
  GUESTFS_DEPRECATED_BY ("copy_device_to_device");

extern GUESTFS_DLL_PUBLIC char *guestfs_debug (guestfs_h *g, const char *subcmd, char *const *extraargs);

extern GUESTFS_DLL_PUBLIC char **guestfs_debug_cmdline (guestfs_h *g);

extern GUESTFS_DLL_PUBLIC char **guestfs_debug_drives (guestfs_h *g);

extern GUESTFS_DLL_PUBLIC int guestfs_debug_upload (guestfs_h *g, const char *filename, const char *tmpname, int mode);

#define LIBGUESTFS_HAVE_DF 1
extern GUESTFS_DLL_PUBLIC char *guestfs_df (guestfs_h *g);

#define LIBGUESTFS_HAVE_DF_H 1
extern GUESTFS_DLL_PUBLIC char *guestfs_df_h (guestfs_h *g);

#define LIBGUESTFS_HAVE_DMESG 1
extern GUESTFS_DLL_PUBLIC char *guestfs_dmesg (guestfs_h *g);

#define LIBGUESTFS_HAVE_DOWNLOAD 1
extern GUESTFS_DLL_PUBLIC int guestfs_download (guestfs_h *g, const char *remotefilename, const char *filename);

#define LIBGUESTFS_HAVE_DOWNLOAD_OFFSET 1
extern GUESTFS_DLL_PUBLIC int guestfs_download_offset (guestfs_h *g, const char *remotefilename, const char *filename, int64_t offset, int64_t size);

#define LIBGUESTFS_HAVE_DROP_CACHES 1
extern GUESTFS_DLL_PUBLIC int guestfs_drop_caches (guestfs_h *g, int whattodrop);

#define LIBGUESTFS_HAVE_DU 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_du (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_E2FSCK 1
#define GUESTFS_E2FSCK_CORRECT 0
#define GUESTFS_E2FSCK_FORCEALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_e2fsck (guestfs_h *g, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_e2fsck_va (guestfs_h *g, const char *device, va_list args);

struct guestfs_e2fsck_argv {
  uint64_t bitmask;

# define GUESTFS_E2FSCK_CORRECT_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_E2FSCK_CORRECT_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int correct;

# define GUESTFS_E2FSCK_FORCEALL_BITMASK (UINT64_C(1)<<1)
  /* The field below is only valid in this struct if the
   * GUESTFS_E2FSCK_FORCEALL_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int forceall;
};

extern GUESTFS_DLL_PUBLIC int guestfs_e2fsck_argv (guestfs_h *g, const char *device, const struct guestfs_e2fsck_argv *optargs);

#define LIBGUESTFS_HAVE_E2FSCK_F 1
extern GUESTFS_DLL_PUBLIC int guestfs_e2fsck_f (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_ECHO_DAEMON 1
extern GUESTFS_DLL_PUBLIC char *guestfs_echo_daemon (guestfs_h *g, char *const *words);

#define LIBGUESTFS_HAVE_EGREP 1
extern GUESTFS_DLL_PUBLIC char **guestfs_egrep (guestfs_h *g, const char *regex, const char *path);

#define LIBGUESTFS_HAVE_EGREPI 1
extern GUESTFS_DLL_PUBLIC char **guestfs_egrepi (guestfs_h *g, const char *regex, const char *path);

#define LIBGUESTFS_HAVE_EQUAL 1
extern GUESTFS_DLL_PUBLIC int guestfs_equal (guestfs_h *g, const char *file1, const char *file2);

#define LIBGUESTFS_HAVE_EXISTS 1
extern GUESTFS_DLL_PUBLIC int guestfs_exists (guestfs_h *g, const char *path);

extern GUESTFS_DLL_PUBLIC int guestfs_fallocate (guestfs_h *g, const char *path, int len)
  GUESTFS_DEPRECATED_BY ("fallocate64");

#define LIBGUESTFS_HAVE_FALLOCATE64 1
extern GUESTFS_DLL_PUBLIC int guestfs_fallocate64 (guestfs_h *g, const char *path, int64_t len);

#define LIBGUESTFS_HAVE_FGREP 1
extern GUESTFS_DLL_PUBLIC char **guestfs_fgrep (guestfs_h *g, const char *pattern, const char *path);

#define LIBGUESTFS_HAVE_FGREPI 1
extern GUESTFS_DLL_PUBLIC char **guestfs_fgrepi (guestfs_h *g, const char *pattern, const char *path);

#define LIBGUESTFS_HAVE_FILE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_file (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_FILE_ARCHITECTURE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_file_architecture (guestfs_h *g, const char *filename);

#define LIBGUESTFS_HAVE_FILESIZE 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_filesize (guestfs_h *g, const char *file);

#define LIBGUESTFS_HAVE_FILL 1
extern GUESTFS_DLL_PUBLIC int guestfs_fill (guestfs_h *g, int c, int len, const char *path);

#define LIBGUESTFS_HAVE_FILL_PATTERN 1
extern GUESTFS_DLL_PUBLIC int guestfs_fill_pattern (guestfs_h *g, const char *pattern, int len, const char *path);

#define LIBGUESTFS_HAVE_FIND 1
extern GUESTFS_DLL_PUBLIC char **guestfs_find (guestfs_h *g, const char *directory);

#define LIBGUESTFS_HAVE_FIND0 1
extern GUESTFS_DLL_PUBLIC int guestfs_find0 (guestfs_h *g, const char *directory, const char *files);

#define LIBGUESTFS_HAVE_FINDFS_LABEL 1
extern GUESTFS_DLL_PUBLIC char *guestfs_findfs_label (guestfs_h *g, const char *label);

#define LIBGUESTFS_HAVE_FINDFS_UUID 1
extern GUESTFS_DLL_PUBLIC char *guestfs_findfs_uuid (guestfs_h *g, const char *uuid);

#define LIBGUESTFS_HAVE_FSCK 1
extern GUESTFS_DLL_PUBLIC int guestfs_fsck (guestfs_h *g, const char *fstype, const char *device);

#define LIBGUESTFS_HAVE_GET_APPEND 1
extern GUESTFS_DLL_PUBLIC const char *guestfs_get_append (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_ATTACH_METHOD 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_attach_method (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_AUTOSYNC 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_autosync (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_DIRECT 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_direct (guestfs_h *g);

extern GUESTFS_DLL_PUBLIC char *guestfs_get_e2label (guestfs_h *g, const char *device)
  GUESTFS_DEPRECATED_BY ("vfs_label");

extern GUESTFS_DLL_PUBLIC char *guestfs_get_e2uuid (guestfs_h *g, const char *device)
  GUESTFS_DEPRECATED_BY ("vfs_uuid");

#define LIBGUESTFS_HAVE_GET_MEMSIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_memsize (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_NETWORK 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_network (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_PATH 1
extern GUESTFS_DLL_PUBLIC const char *guestfs_get_path (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_PGROUP 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_pgroup (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_PID 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_pid (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_QEMU 1
extern GUESTFS_DLL_PUBLIC const char *guestfs_get_qemu (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_RECOVERY_PROC 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_recovery_proc (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_SELINUX 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_selinux (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_SMP 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_smp (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_STATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_state (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_TRACE 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_trace (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_UMASK 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_umask (guestfs_h *g);

#define LIBGUESTFS_HAVE_GET_VERBOSE 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_verbose (guestfs_h *g);

#define LIBGUESTFS_HAVE_GETCON 1
extern GUESTFS_DLL_PUBLIC char *guestfs_getcon (guestfs_h *g);

#define LIBGUESTFS_HAVE_GETXATTR 1
extern GUESTFS_DLL_PUBLIC char *guestfs_getxattr (guestfs_h *g, const char *path, const char *name, size_t *size_r);

#define LIBGUESTFS_HAVE_GETXATTRS 1
extern GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *guestfs_getxattrs (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_GLOB_EXPAND 1
extern GUESTFS_DLL_PUBLIC char **guestfs_glob_expand (guestfs_h *g, const char *pattern);

#define LIBGUESTFS_HAVE_GREP 1
extern GUESTFS_DLL_PUBLIC char **guestfs_grep (guestfs_h *g, const char *regex, const char *path);

#define LIBGUESTFS_HAVE_GREPI 1
extern GUESTFS_DLL_PUBLIC char **guestfs_grepi (guestfs_h *g, const char *regex, const char *path);

#define LIBGUESTFS_HAVE_GRUB_INSTALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_grub_install (guestfs_h *g, const char *root, const char *device);

#define LIBGUESTFS_HAVE_HEAD 1
extern GUESTFS_DLL_PUBLIC char **guestfs_head (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_HEAD_N 1
extern GUESTFS_DLL_PUBLIC char **guestfs_head_n (guestfs_h *g, int nrlines, const char *path);

#define LIBGUESTFS_HAVE_HEXDUMP 1
extern GUESTFS_DLL_PUBLIC char *guestfs_hexdump (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_INITRD_CAT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_initrd_cat (guestfs_h *g, const char *initrdpath, const char *filename, size_t *size_r);

#define LIBGUESTFS_HAVE_INITRD_LIST 1
extern GUESTFS_DLL_PUBLIC char **guestfs_initrd_list (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_INOTIFY_ADD_WATCH 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_inotify_add_watch (guestfs_h *g, const char *path, int mask);

#define LIBGUESTFS_HAVE_INOTIFY_CLOSE 1
extern GUESTFS_DLL_PUBLIC int guestfs_inotify_close (guestfs_h *g);

#define LIBGUESTFS_HAVE_INOTIFY_FILES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_inotify_files (guestfs_h *g);

#define LIBGUESTFS_HAVE_INOTIFY_INIT 1
extern GUESTFS_DLL_PUBLIC int guestfs_inotify_init (guestfs_h *g, int maxevents);

#define LIBGUESTFS_HAVE_INOTIFY_READ 1
extern GUESTFS_DLL_PUBLIC struct guestfs_inotify_event_list *guestfs_inotify_read (guestfs_h *g);

#define LIBGUESTFS_HAVE_INOTIFY_RM_WATCH 1
extern GUESTFS_DLL_PUBLIC int guestfs_inotify_rm_watch (guestfs_h *g, int wd);

#define LIBGUESTFS_HAVE_INSPECT_GET_ARCH 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_arch (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_DISTRO 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_distro (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_DRIVE_MAPPINGS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_inspect_get_drive_mappings (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_FILESYSTEMS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_inspect_get_filesystems (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_FORMAT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_format (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_HOSTNAME 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_hostname (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_ICON 1
#define GUESTFS_INSPECT_GET_ICON_FAVICON 0
#define GUESTFS_INSPECT_GET_ICON_HIGHQUALITY 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_icon (guestfs_h *g, const char *root, size_t *size_r, ...);
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_icon_va (guestfs_h *g, const char *root, size_t *size_r, va_list args);

struct guestfs_inspect_get_icon_argv {
  uint64_t bitmask;

# define GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int favicon;

# define GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK (UINT64_C(1)<<1)
  /* The field below is only valid in this struct if the
   * GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int highquality;
};

extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_icon_argv (guestfs_h *g, const char *root, size_t *size_r, const struct guestfs_inspect_get_icon_argv *optargs);

#define LIBGUESTFS_HAVE_INSPECT_GET_MAJOR_VERSION 1
extern GUESTFS_DLL_PUBLIC int guestfs_inspect_get_major_version (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_MINOR_VERSION 1
extern GUESTFS_DLL_PUBLIC int guestfs_inspect_get_minor_version (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_MOUNTPOINTS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_inspect_get_mountpoints (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_PACKAGE_FORMAT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_package_format (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_PACKAGE_MANAGEMENT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_package_management (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_PRODUCT_NAME 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_product_name (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_PRODUCT_VARIANT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_product_variant (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_ROOTS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_inspect_get_roots (guestfs_h *g);

#define LIBGUESTFS_HAVE_INSPECT_GET_TYPE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_type (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_WINDOWS_CURRENT_CONTROL_SET 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_windows_current_control_set (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_GET_WINDOWS_SYSTEMROOT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_windows_systemroot (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_IS_LIVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_inspect_is_live (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_IS_MULTIPART 1
extern GUESTFS_DLL_PUBLIC int guestfs_inspect_is_multipart (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_IS_NETINST 1
extern GUESTFS_DLL_PUBLIC int guestfs_inspect_is_netinst (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_LIST_APPLICATIONS 1
extern GUESTFS_DLL_PUBLIC struct guestfs_application_list *guestfs_inspect_list_applications (guestfs_h *g, const char *root);

#define LIBGUESTFS_HAVE_INSPECT_OS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_inspect_os (guestfs_h *g);

#define LIBGUESTFS_HAVE_INTERNAL_AUTOSYNC 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_autosync (guestfs_h *g);

#define LIBGUESTFS_HAVE_IS_BLOCKDEV 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_blockdev (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_IS_BUSY 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_busy (guestfs_h *g);

#define LIBGUESTFS_HAVE_IS_CHARDEV 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_chardev (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_IS_CONFIG 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_config (guestfs_h *g);

#define LIBGUESTFS_HAVE_IS_DIR 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_dir (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_IS_FIFO 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_fifo (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_IS_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_file (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_IS_LAUNCHING 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_launching (guestfs_h *g);

#define LIBGUESTFS_HAVE_IS_LV 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_lv (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_IS_READY 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_ready (guestfs_h *g);

#define LIBGUESTFS_HAVE_IS_SOCKET 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_socket (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_IS_SYMLINK 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_symlink (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_IS_ZERO 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_zero (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_IS_ZERO_DEVICE 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_zero_device (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_KILL_SUBPROCESS 1
extern GUESTFS_DLL_PUBLIC int guestfs_kill_subprocess (guestfs_h *g);

#define LIBGUESTFS_HAVE_LAUNCH 1
extern GUESTFS_DLL_PUBLIC int guestfs_launch (guestfs_h *g);

#define LIBGUESTFS_HAVE_LCHOWN 1
extern GUESTFS_DLL_PUBLIC int guestfs_lchown (guestfs_h *g, int owner, int group, const char *path);

#define LIBGUESTFS_HAVE_LGETXATTR 1
extern GUESTFS_DLL_PUBLIC char *guestfs_lgetxattr (guestfs_h *g, const char *path, const char *name, size_t *size_r);

#define LIBGUESTFS_HAVE_LGETXATTRS 1
extern GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *guestfs_lgetxattrs (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_LIST_9P 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_9p (guestfs_h *g);

#define LIBGUESTFS_HAVE_LIST_DEVICES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_devices (guestfs_h *g);

#define LIBGUESTFS_HAVE_LIST_DM_DEVICES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_dm_devices (guestfs_h *g);

#define LIBGUESTFS_HAVE_LIST_FILESYSTEMS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_filesystems (guestfs_h *g);

#define LIBGUESTFS_HAVE_LIST_MD_DEVICES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_md_devices (guestfs_h *g);

#define LIBGUESTFS_HAVE_LIST_PARTITIONS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_partitions (guestfs_h *g);

#define LIBGUESTFS_HAVE_LL 1
extern GUESTFS_DLL_PUBLIC char *guestfs_ll (guestfs_h *g, const char *directory);

#define LIBGUESTFS_HAVE_LN 1
extern GUESTFS_DLL_PUBLIC int guestfs_ln (guestfs_h *g, const char *target, const char *linkname);

#define LIBGUESTFS_HAVE_LN_F 1
extern GUESTFS_DLL_PUBLIC int guestfs_ln_f (guestfs_h *g, const char *target, const char *linkname);

#define LIBGUESTFS_HAVE_LN_S 1
extern GUESTFS_DLL_PUBLIC int guestfs_ln_s (guestfs_h *g, const char *target, const char *linkname);

#define LIBGUESTFS_HAVE_LN_SF 1
extern GUESTFS_DLL_PUBLIC int guestfs_ln_sf (guestfs_h *g, const char *target, const char *linkname);

#define LIBGUESTFS_HAVE_LREMOVEXATTR 1
extern GUESTFS_DLL_PUBLIC int guestfs_lremovexattr (guestfs_h *g, const char *xattr, const char *path);

#define LIBGUESTFS_HAVE_LS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_ls (guestfs_h *g, const char *directory);

#define LIBGUESTFS_HAVE_LSETXATTR 1
extern GUESTFS_DLL_PUBLIC int guestfs_lsetxattr (guestfs_h *g, const char *xattr, const char *val, int vallen, const char *path);

#define LIBGUESTFS_HAVE_LSTAT 1
extern GUESTFS_DLL_PUBLIC struct guestfs_stat *guestfs_lstat (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_LSTATLIST 1
extern GUESTFS_DLL_PUBLIC struct guestfs_stat_list *guestfs_lstatlist (guestfs_h *g, const char *path, char *const *names);

#define LIBGUESTFS_HAVE_LUKS_ADD_KEY 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_add_key (guestfs_h *g, const char *device, const char *key, const char *newkey, int keyslot);

#define LIBGUESTFS_HAVE_LUKS_CLOSE 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_close (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_LUKS_FORMAT 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_format (guestfs_h *g, const char *device, const char *key, int keyslot);

#define LIBGUESTFS_HAVE_LUKS_FORMAT_CIPHER 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_format_cipher (guestfs_h *g, const char *device, const char *key, int keyslot, const char *cipher);

#define LIBGUESTFS_HAVE_LUKS_KILL_SLOT 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_kill_slot (guestfs_h *g, const char *device, const char *key, int keyslot);

#define LIBGUESTFS_HAVE_LUKS_OPEN 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_open (guestfs_h *g, const char *device, const char *key, const char *mapname);

#define LIBGUESTFS_HAVE_LUKS_OPEN_RO 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_open_ro (guestfs_h *g, const char *device, const char *key, const char *mapname);

#define LIBGUESTFS_HAVE_LVCREATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvcreate (guestfs_h *g, const char *logvol, const char *volgroup, int mbytes);

#define LIBGUESTFS_HAVE_LVM_CANONICAL_LV_NAME 1
extern GUESTFS_DLL_PUBLIC char *guestfs_lvm_canonical_lv_name (guestfs_h *g, const char *lvname);

#define LIBGUESTFS_HAVE_LVM_CLEAR_FILTER 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvm_clear_filter (guestfs_h *g);

#define LIBGUESTFS_HAVE_LVM_REMOVE_ALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvm_remove_all (guestfs_h *g);

#define LIBGUESTFS_HAVE_LVM_SET_FILTER 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvm_set_filter (guestfs_h *g, char *const *devices);

#define LIBGUESTFS_HAVE_LVREMOVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvremove (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_LVRENAME 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvrename (guestfs_h *g, const char *logvol, const char *newlogvol);

#define LIBGUESTFS_HAVE_LVRESIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvresize (guestfs_h *g, const char *device, int mbytes);

#define LIBGUESTFS_HAVE_LVRESIZE_FREE 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvresize_free (guestfs_h *g, const char *lv, int percent);

#define LIBGUESTFS_HAVE_LVS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_lvs (guestfs_h *g);

#define LIBGUESTFS_HAVE_LVS_FULL 1
extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_lv_list *guestfs_lvs_full (guestfs_h *g);

#define LIBGUESTFS_HAVE_LVUUID 1
extern GUESTFS_DLL_PUBLIC char *guestfs_lvuuid (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_LXATTRLIST 1
extern GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *guestfs_lxattrlist (guestfs_h *g, const char *path, char *const *names);

#define LIBGUESTFS_HAVE_MD_CREATE 1
#define GUESTFS_MD_CREATE_MISSINGBITMAP 0
#define GUESTFS_MD_CREATE_NRDEVICES 1
#define GUESTFS_MD_CREATE_SPARE 2
#define GUESTFS_MD_CREATE_CHUNK 3
#define GUESTFS_MD_CREATE_LEVEL 4
extern GUESTFS_DLL_PUBLIC int guestfs_md_create (guestfs_h *g, const char *name, char *const *devices, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_md_create_va (guestfs_h *g, const char *name, char *const *devices, va_list args);

struct guestfs_md_create_argv {
  uint64_t bitmask;

# define GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t missingbitmap;

# define GUESTFS_MD_CREATE_NRDEVICES_BITMASK (UINT64_C(1)<<1)
  /* The field below is only valid in this struct if the
   * GUESTFS_MD_CREATE_NRDEVICES_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int nrdevices;

# define GUESTFS_MD_CREATE_SPARE_BITMASK (UINT64_C(1)<<2)
  /* The field below is only valid in this struct if the
   * GUESTFS_MD_CREATE_SPARE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int spare;

# define GUESTFS_MD_CREATE_CHUNK_BITMASK (UINT64_C(1)<<3)
  /* The field below is only valid in this struct if the
   * GUESTFS_MD_CREATE_CHUNK_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t chunk;

# define GUESTFS_MD_CREATE_LEVEL_BITMASK (UINT64_C(1)<<4)
  /* The field below is only valid in this struct if the
   * GUESTFS_MD_CREATE_LEVEL_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  const char *level;
};

extern GUESTFS_DLL_PUBLIC int guestfs_md_create_argv (guestfs_h *g, const char *name, char *const *devices, const struct guestfs_md_create_argv *optargs);

#define LIBGUESTFS_HAVE_MD_DETAIL 1
extern GUESTFS_DLL_PUBLIC char **guestfs_md_detail (guestfs_h *g, const char *md);

#define LIBGUESTFS_HAVE_MD_STOP 1
extern GUESTFS_DLL_PUBLIC int guestfs_md_stop (guestfs_h *g, const char *md);

#define LIBGUESTFS_HAVE_MKDIR 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkdir (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_MKDIR_MODE 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkdir_mode (guestfs_h *g, const char *path, int mode);

#define LIBGUESTFS_HAVE_MKDIR_P 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkdir_p (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_MKDTEMP 1
extern GUESTFS_DLL_PUBLIC char *guestfs_mkdtemp (guestfs_h *g, const char *template);

#define LIBGUESTFS_HAVE_MKE2FS_J 1
extern GUESTFS_DLL_PUBLIC int guestfs_mke2fs_J (guestfs_h *g, const char *fstype, int blocksize, const char *device, const char *journal);

#define LIBGUESTFS_HAVE_MKE2FS_JL 1
extern GUESTFS_DLL_PUBLIC int guestfs_mke2fs_JL (guestfs_h *g, const char *fstype, int blocksize, const char *device, const char *label);

#define LIBGUESTFS_HAVE_MKE2FS_JU 1
extern GUESTFS_DLL_PUBLIC int guestfs_mke2fs_JU (guestfs_h *g, const char *fstype, int blocksize, const char *device, const char *uuid);

#define LIBGUESTFS_HAVE_MKE2JOURNAL 1
extern GUESTFS_DLL_PUBLIC int guestfs_mke2journal (guestfs_h *g, int blocksize, const char *device);

#define LIBGUESTFS_HAVE_MKE2JOURNAL_L 1
extern GUESTFS_DLL_PUBLIC int guestfs_mke2journal_L (guestfs_h *g, int blocksize, const char *label, const char *device);

#define LIBGUESTFS_HAVE_MKE2JOURNAL_U 1
extern GUESTFS_DLL_PUBLIC int guestfs_mke2journal_U (guestfs_h *g, int blocksize, const char *uuid, const char *device);

#define LIBGUESTFS_HAVE_MKFIFO 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkfifo (guestfs_h *g, int mode, const char *path);

#define LIBGUESTFS_HAVE_MKFS 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkfs (guestfs_h *g, const char *fstype, const char *device);

extern GUESTFS_DLL_PUBLIC int guestfs_mkfs_b (guestfs_h *g, const char *fstype, int blocksize, const char *device)
  GUESTFS_DEPRECATED_BY ("mkfs_opts");

#define LIBGUESTFS_HAVE_MKFS_OPTS 1
#define GUESTFS_MKFS_OPTS_BLOCKSIZE 0
#define GUESTFS_MKFS_OPTS_FEATURES 1
#define GUESTFS_MKFS_OPTS_INODE 2
#define GUESTFS_MKFS_OPTS_SECTORSIZE 3
extern GUESTFS_DLL_PUBLIC int guestfs_mkfs_opts (guestfs_h *g, const char *fstype, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_mkfs_opts_va (guestfs_h *g, const char *fstype, const char *device, va_list args);

struct guestfs_mkfs_opts_argv {
  uint64_t bitmask;

# define GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int blocksize;

# define GUESTFS_MKFS_OPTS_FEATURES_BITMASK (UINT64_C(1)<<1)
  /* The field below is only valid in this struct if the
   * GUESTFS_MKFS_OPTS_FEATURES_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  const char *features;

# define GUESTFS_MKFS_OPTS_INODE_BITMASK (UINT64_C(1)<<2)
  /* The field below is only valid in this struct if the
   * GUESTFS_MKFS_OPTS_INODE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int inode;

# define GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK (UINT64_C(1)<<3)
  /* The field below is only valid in this struct if the
   * GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int sectorsize;
};

extern GUESTFS_DLL_PUBLIC int guestfs_mkfs_opts_argv (guestfs_h *g, const char *fstype, const char *device, const struct guestfs_mkfs_opts_argv *optargs);

#define LIBGUESTFS_HAVE_MKMOUNTPOINT 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkmountpoint (guestfs_h *g, const char *exemptpath);

#define LIBGUESTFS_HAVE_MKNOD 1
extern GUESTFS_DLL_PUBLIC int guestfs_mknod (guestfs_h *g, int mode, int devmajor, int devminor, const char *path);

#define LIBGUESTFS_HAVE_MKNOD_B 1
extern GUESTFS_DLL_PUBLIC int guestfs_mknod_b (guestfs_h *g, int mode, int devmajor, int devminor, const char *path);

#define LIBGUESTFS_HAVE_MKNOD_C 1
extern GUESTFS_DLL_PUBLIC int guestfs_mknod_c (guestfs_h *g, int mode, int devmajor, int devminor, const char *path);

#define LIBGUESTFS_HAVE_MKSWAP 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkswap (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_MKSWAP_L 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkswap_L (guestfs_h *g, const char *label, const char *device);

#define LIBGUESTFS_HAVE_MKSWAP_U 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkswap_U (guestfs_h *g, const char *uuid, const char *device);

#define LIBGUESTFS_HAVE_MKSWAP_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkswap_file (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_MODPROBE 1
extern GUESTFS_DLL_PUBLIC int guestfs_modprobe (guestfs_h *g, const char *modulename);

#define LIBGUESTFS_HAVE_MOUNT 1
extern GUESTFS_DLL_PUBLIC int guestfs_mount (guestfs_h *g, const char *device, const char *mountpoint);

#define LIBGUESTFS_HAVE_MOUNT_9P 1
#define GUESTFS_MOUNT_9P_OPTIONS 0
extern GUESTFS_DLL_PUBLIC int guestfs_mount_9p (guestfs_h *g, const char *mounttag, const char *mountpoint, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_mount_9p_va (guestfs_h *g, const char *mounttag, const char *mountpoint, va_list args);

struct guestfs_mount_9p_argv {
  uint64_t bitmask;

# define GUESTFS_MOUNT_9P_OPTIONS_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_MOUNT_9P_OPTIONS_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  const char *options;
};

extern GUESTFS_DLL_PUBLIC int guestfs_mount_9p_argv (guestfs_h *g, const char *mounttag, const char *mountpoint, const struct guestfs_mount_9p_argv *optargs);

#define LIBGUESTFS_HAVE_MOUNT_LOOP 1
extern GUESTFS_DLL_PUBLIC int guestfs_mount_loop (guestfs_h *g, const char *file, const char *mountpoint);

#define LIBGUESTFS_HAVE_MOUNT_OPTIONS 1
extern GUESTFS_DLL_PUBLIC int guestfs_mount_options (guestfs_h *g, const char *options, const char *device, const char *mountpoint);

#define LIBGUESTFS_HAVE_MOUNT_RO 1
extern GUESTFS_DLL_PUBLIC int guestfs_mount_ro (guestfs_h *g, const char *device, const char *mountpoint);

#define LIBGUESTFS_HAVE_MOUNT_VFS 1
extern GUESTFS_DLL_PUBLIC int guestfs_mount_vfs (guestfs_h *g, const char *options, const char *vfstype, const char *device, const char *mountpoint);

#define LIBGUESTFS_HAVE_MOUNTPOINTS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_mountpoints (guestfs_h *g);

#define LIBGUESTFS_HAVE_MOUNTS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_mounts (guestfs_h *g);

#define LIBGUESTFS_HAVE_MV 1
extern GUESTFS_DLL_PUBLIC int guestfs_mv (guestfs_h *g, const char *src, const char *dest);

#define LIBGUESTFS_HAVE_NTFS_3G_PROBE 1
extern GUESTFS_DLL_PUBLIC int guestfs_ntfs_3g_probe (guestfs_h *g, int rw, const char *device);

extern GUESTFS_DLL_PUBLIC int guestfs_ntfsresize (guestfs_h *g, const char *device)
  GUESTFS_DEPRECATED_BY ("ntfsresize_opts");

#define LIBGUESTFS_HAVE_NTFSRESIZE_OPTS 1
#define GUESTFS_NTFSRESIZE_OPTS_SIZE 0
#define GUESTFS_NTFSRESIZE_OPTS_FORCE 1
extern GUESTFS_DLL_PUBLIC int guestfs_ntfsresize_opts (guestfs_h *g, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_ntfsresize_opts_va (guestfs_h *g, const char *device, va_list args);

struct guestfs_ntfsresize_opts_argv {
  uint64_t bitmask;

# define GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t size;

# define GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK (UINT64_C(1)<<1)
  /* The field below is only valid in this struct if the
   * GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int force;
};

extern GUESTFS_DLL_PUBLIC int guestfs_ntfsresize_opts_argv (guestfs_h *g, const char *device, const struct guestfs_ntfsresize_opts_argv *optargs);

extern GUESTFS_DLL_PUBLIC int guestfs_ntfsresize_size (guestfs_h *g, const char *device, int64_t size)
  GUESTFS_DEPRECATED_BY ("ntfsresize_opts");

#define LIBGUESTFS_HAVE_PART_ADD 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_add (guestfs_h *g, const char *device, const char *prlogex, int64_t startsect, int64_t endsect);

#define LIBGUESTFS_HAVE_PART_DEL 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_del (guestfs_h *g, const char *device, int partnum);

#define LIBGUESTFS_HAVE_PART_DISK 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_disk (guestfs_h *g, const char *device, const char *parttype);

#define LIBGUESTFS_HAVE_PART_GET_BOOTABLE 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_get_bootable (guestfs_h *g, const char *device, int partnum);

#define LIBGUESTFS_HAVE_PART_GET_MBR_ID 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_get_mbr_id (guestfs_h *g, const char *device, int partnum);

#define LIBGUESTFS_HAVE_PART_GET_PARTTYPE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_part_get_parttype (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_PART_INIT 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_init (guestfs_h *g, const char *device, const char *parttype);

#define LIBGUESTFS_HAVE_PART_LIST 1
extern GUESTFS_DLL_PUBLIC struct guestfs_partition_list *guestfs_part_list (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_PART_SET_BOOTABLE 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_set_bootable (guestfs_h *g, const char *device, int partnum, int bootable);

#define LIBGUESTFS_HAVE_PART_SET_MBR_ID 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_set_mbr_id (guestfs_h *g, const char *device, int partnum, int idbyte);

#define LIBGUESTFS_HAVE_PART_SET_NAME 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_set_name (guestfs_h *g, const char *device, int partnum, const char *name);

#define LIBGUESTFS_HAVE_PART_TO_DEV 1
extern GUESTFS_DLL_PUBLIC char *guestfs_part_to_dev (guestfs_h *g, const char *partition);

#define LIBGUESTFS_HAVE_PART_TO_PARTNUM 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_to_partnum (guestfs_h *g, const char *partition);

#define LIBGUESTFS_HAVE_PING_DAEMON 1
extern GUESTFS_DLL_PUBLIC int guestfs_ping_daemon (guestfs_h *g);

#define LIBGUESTFS_HAVE_PREAD 1
extern GUESTFS_DLL_PUBLIC char *guestfs_pread (guestfs_h *g, const char *path, int count, int64_t offset, size_t *size_r);

#define LIBGUESTFS_HAVE_PREAD_DEVICE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_pread_device (guestfs_h *g, const char *device, int count, int64_t offset, size_t *size_r);

#define LIBGUESTFS_HAVE_PVCREATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_pvcreate (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_PVREMOVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_pvremove (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_PVRESIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_pvresize (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_PVRESIZE_SIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_pvresize_size (guestfs_h *g, const char *device, int64_t size);

#define LIBGUESTFS_HAVE_PVS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_pvs (guestfs_h *g);

#define LIBGUESTFS_HAVE_PVS_FULL 1
extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv_list *guestfs_pvs_full (guestfs_h *g);

#define LIBGUESTFS_HAVE_PVUUID 1
extern GUESTFS_DLL_PUBLIC char *guestfs_pvuuid (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_PWRITE 1
extern GUESTFS_DLL_PUBLIC int guestfs_pwrite (guestfs_h *g, const char *path, const char *content, size_t content_size, int64_t offset);

#define LIBGUESTFS_HAVE_PWRITE_DEVICE 1
extern GUESTFS_DLL_PUBLIC int guestfs_pwrite_device (guestfs_h *g, const char *device, const char *content, size_t content_size, int64_t offset);

#define LIBGUESTFS_HAVE_READ_FILE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_read_file (guestfs_h *g, const char *path, size_t *size_r);

#define LIBGUESTFS_HAVE_READ_LINES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_read_lines (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_READDIR 1
extern GUESTFS_DLL_PUBLIC struct guestfs_dirent_list *guestfs_readdir (guestfs_h *g, const char *dir);

#define LIBGUESTFS_HAVE_READLINK 1
extern GUESTFS_DLL_PUBLIC char *guestfs_readlink (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_READLINKLIST 1
extern GUESTFS_DLL_PUBLIC char **guestfs_readlinklist (guestfs_h *g, const char *path, char *const *names);

#define LIBGUESTFS_HAVE_REALPATH 1
extern GUESTFS_DLL_PUBLIC char *guestfs_realpath (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_REMOVEXATTR 1
extern GUESTFS_DLL_PUBLIC int guestfs_removexattr (guestfs_h *g, const char *xattr, const char *path);

#define LIBGUESTFS_HAVE_RESIZE2FS 1
extern GUESTFS_DLL_PUBLIC int guestfs_resize2fs (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_RESIZE2FS_M 1
extern GUESTFS_DLL_PUBLIC int guestfs_resize2fs_M (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_RESIZE2FS_SIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_resize2fs_size (guestfs_h *g, const char *device, int64_t size);

#define LIBGUESTFS_HAVE_RM 1
extern GUESTFS_DLL_PUBLIC int guestfs_rm (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_RM_RF 1
extern GUESTFS_DLL_PUBLIC int guestfs_rm_rf (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_RMDIR 1
extern GUESTFS_DLL_PUBLIC int guestfs_rmdir (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_RMMOUNTPOINT 1
extern GUESTFS_DLL_PUBLIC int guestfs_rmmountpoint (guestfs_h *g, const char *exemptpath);

#define LIBGUESTFS_HAVE_SCRUB_DEVICE 1
extern GUESTFS_DLL_PUBLIC int guestfs_scrub_device (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_SCRUB_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_scrub_file (guestfs_h *g, const char *file);

#define LIBGUESTFS_HAVE_SCRUB_FREESPACE 1
extern GUESTFS_DLL_PUBLIC int guestfs_scrub_freespace (guestfs_h *g, const char *dir);

#define LIBGUESTFS_HAVE_SET_APPEND 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_append (guestfs_h *g, const char *append);

#define LIBGUESTFS_HAVE_SET_ATTACH_METHOD 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_attach_method (guestfs_h *g, const char *attachmethod);

#define LIBGUESTFS_HAVE_SET_AUTOSYNC 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_autosync (guestfs_h *g, int autosync);

#define LIBGUESTFS_HAVE_SET_DIRECT 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_direct (guestfs_h *g, int direct);

#define LIBGUESTFS_HAVE_SET_E2LABEL 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_e2label (guestfs_h *g, const char *device, const char *label);

#define LIBGUESTFS_HAVE_SET_E2UUID 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_e2uuid (guestfs_h *g, const char *device, const char *uuid);

#define LIBGUESTFS_HAVE_SET_MEMSIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_memsize (guestfs_h *g, int memsize);

#define LIBGUESTFS_HAVE_SET_NETWORK 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_network (guestfs_h *g, int network);

#define LIBGUESTFS_HAVE_SET_PATH 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_path (guestfs_h *g, const char *searchpath);

#define LIBGUESTFS_HAVE_SET_PGROUP 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_pgroup (guestfs_h *g, int pgroup);

#define LIBGUESTFS_HAVE_SET_QEMU 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_qemu (guestfs_h *g, const char *qemu);

#define LIBGUESTFS_HAVE_SET_RECOVERY_PROC 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_recovery_proc (guestfs_h *g, int recoveryproc);

#define LIBGUESTFS_HAVE_SET_SELINUX 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_selinux (guestfs_h *g, int selinux);

#define LIBGUESTFS_HAVE_SET_SMP 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_smp (guestfs_h *g, int smp);

#define LIBGUESTFS_HAVE_SET_TRACE 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_trace (guestfs_h *g, int trace);

#define LIBGUESTFS_HAVE_SET_VERBOSE 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_verbose (guestfs_h *g, int verbose);

#define LIBGUESTFS_HAVE_SETCON 1
extern GUESTFS_DLL_PUBLIC int guestfs_setcon (guestfs_h *g, const char *context);

#define LIBGUESTFS_HAVE_SETXATTR 1
extern GUESTFS_DLL_PUBLIC int guestfs_setxattr (guestfs_h *g, const char *xattr, const char *val, int vallen, const char *path);

extern GUESTFS_DLL_PUBLIC int guestfs_sfdisk (guestfs_h *g, const char *device, int cyls, int heads, int sectors, char *const *lines)
  GUESTFS_DEPRECATED_BY ("part_add");

extern GUESTFS_DLL_PUBLIC int guestfs_sfdiskM (guestfs_h *g, const char *device, char *const *lines)
  GUESTFS_DEPRECATED_BY ("part_add");

extern GUESTFS_DLL_PUBLIC int guestfs_sfdisk_N (guestfs_h *g, const char *device, int partnum, int cyls, int heads, int sectors, const char *line)
  GUESTFS_DEPRECATED_BY ("part_add");

#define LIBGUESTFS_HAVE_SFDISK_DISK_GEOMETRY 1
extern GUESTFS_DLL_PUBLIC char *guestfs_sfdisk_disk_geometry (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_SFDISK_KERNEL_GEOMETRY 1
extern GUESTFS_DLL_PUBLIC char *guestfs_sfdisk_kernel_geometry (guestfs_h *g, const char *device);

extern GUESTFS_DLL_PUBLIC char *guestfs_sfdisk_l (guestfs_h *g, const char *device)
  GUESTFS_DEPRECATED_BY ("part_list");

#define LIBGUESTFS_HAVE_SH 1
extern GUESTFS_DLL_PUBLIC char *guestfs_sh (guestfs_h *g, const char *command);

#define LIBGUESTFS_HAVE_SH_LINES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_sh_lines (guestfs_h *g, const char *command);

#define LIBGUESTFS_HAVE_SLEEP 1
extern GUESTFS_DLL_PUBLIC int guestfs_sleep (guestfs_h *g, int secs);

#define LIBGUESTFS_HAVE_STAT 1
extern GUESTFS_DLL_PUBLIC struct guestfs_stat *guestfs_stat (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_STATVFS 1
extern GUESTFS_DLL_PUBLIC struct guestfs_statvfs *guestfs_statvfs (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_STRINGS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_strings (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_STRINGS_E 1
extern GUESTFS_DLL_PUBLIC char **guestfs_strings_e (guestfs_h *g, const char *encoding, const char *path);

#define LIBGUESTFS_HAVE_SWAPOFF_DEVICE 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapoff_device (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_SWAPOFF_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapoff_file (guestfs_h *g, const char *file);

#define LIBGUESTFS_HAVE_SWAPOFF_LABEL 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapoff_label (guestfs_h *g, const char *label);

#define LIBGUESTFS_HAVE_SWAPOFF_UUID 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapoff_uuid (guestfs_h *g, const char *uuid);

#define LIBGUESTFS_HAVE_SWAPON_DEVICE 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapon_device (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_SWAPON_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapon_file (guestfs_h *g, const char *file);

#define LIBGUESTFS_HAVE_SWAPON_LABEL 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapon_label (guestfs_h *g, const char *label);

#define LIBGUESTFS_HAVE_SWAPON_UUID 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapon_uuid (guestfs_h *g, const char *uuid);

#define LIBGUESTFS_HAVE_SYNC 1
extern GUESTFS_DLL_PUBLIC int guestfs_sync (guestfs_h *g);

#define LIBGUESTFS_HAVE_TAIL 1
extern GUESTFS_DLL_PUBLIC char **guestfs_tail (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_TAIL_N 1
extern GUESTFS_DLL_PUBLIC char **guestfs_tail_n (guestfs_h *g, int nrlines, const char *path);

#define LIBGUESTFS_HAVE_TAR_IN 1
extern GUESTFS_DLL_PUBLIC int guestfs_tar_in (guestfs_h *g, const char *tarfile, const char *directory);

#define LIBGUESTFS_HAVE_TAR_OUT 1
extern GUESTFS_DLL_PUBLIC int guestfs_tar_out (guestfs_h *g, const char *directory, const char *tarfile);

#define GUESTFS_TEST0_OBOOL 0
#define GUESTFS_TEST0_OINT 1
#define GUESTFS_TEST0_OINT64 2
#define GUESTFS_TEST0_OSTRING 3
extern GUESTFS_DLL_PUBLIC int guestfs_test0 (guestfs_h *g, const char *str, const char *optstr, char *const *strlist, int b, int integer, int64_t integer64, const char *filein, const char *fileout, const char *bufferin, size_t bufferin_size, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_test0_va (guestfs_h *g, const char *str, const char *optstr, char *const *strlist, int b, int integer, int64_t integer64, const char *filein, const char *fileout, const char *bufferin, size_t bufferin_size, va_list args);

struct guestfs_test0_argv {
  uint64_t bitmask;

# define GUESTFS_TEST0_OBOOL_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_TEST0_OBOOL_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int obool;

# define GUESTFS_TEST0_OINT_BITMASK (UINT64_C(1)<<1)
  /* The field below is only valid in this struct if the
   * GUESTFS_TEST0_OINT_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int oint;

# define GUESTFS_TEST0_OINT64_BITMASK (UINT64_C(1)<<2)
  /* The field below is only valid in this struct if the
   * GUESTFS_TEST0_OINT64_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t oint64;

# define GUESTFS_TEST0_OSTRING_BITMASK (UINT64_C(1)<<3)
  /* The field below is only valid in this struct if the
   * GUESTFS_TEST0_OSTRING_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  const char *ostring;
};

extern GUESTFS_DLL_PUBLIC int guestfs_test0_argv (guestfs_h *g, const char *str, const char *optstr, char *const *strlist, int b, int integer, int64_t integer64, const char *filein, const char *fileout, const char *bufferin, size_t bufferin_size, const struct guestfs_test0_argv *optargs);

extern GUESTFS_DLL_PUBLIC int guestfs_test0rbool (guestfs_h *g, const char *val);

extern GUESTFS_DLL_PUBLIC int guestfs_test0rboolerr (guestfs_h *g);

extern GUESTFS_DLL_PUBLIC char *guestfs_test0rbufferout (guestfs_h *g, const char *val, size_t *size_r);

extern GUESTFS_DLL_PUBLIC char *guestfs_test0rbufferouterr (guestfs_h *g, size_t *size_r);

extern GUESTFS_DLL_PUBLIC const char *guestfs_test0rconstoptstring (guestfs_h *g, const char *val);

extern GUESTFS_DLL_PUBLIC const char *guestfs_test0rconstoptstringerr (guestfs_h *g);

extern GUESTFS_DLL_PUBLIC const char *guestfs_test0rconststring (guestfs_h *g, const char *val);

extern GUESTFS_DLL_PUBLIC const char *guestfs_test0rconststringerr (guestfs_h *g);

extern GUESTFS_DLL_PUBLIC char **guestfs_test0rhashtable (guestfs_h *g, const char *val);

extern GUESTFS_DLL_PUBLIC char **guestfs_test0rhashtableerr (guestfs_h *g);

extern GUESTFS_DLL_PUBLIC int guestfs_test0rint (guestfs_h *g, const char *val);

extern GUESTFS_DLL_PUBLIC int64_t guestfs_test0rint64 (guestfs_h *g, const char *val);

extern GUESTFS_DLL_PUBLIC int64_t guestfs_test0rint64err (guestfs_h *g);

extern GUESTFS_DLL_PUBLIC int guestfs_test0rinterr (guestfs_h *g);

extern GUESTFS_DLL_PUBLIC char *guestfs_test0rstring (guestfs_h *g, const char *val);

extern GUESTFS_DLL_PUBLIC char *guestfs_test0rstringerr (guestfs_h *g);

extern GUESTFS_DLL_PUBLIC char **guestfs_test0rstringlist (guestfs_h *g, const char *val);

extern GUESTFS_DLL_PUBLIC char **guestfs_test0rstringlisterr (guestfs_h *g);

extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv *guestfs_test0rstruct (guestfs_h *g, const char *val);

extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv *guestfs_test0rstructerr (guestfs_h *g);

extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv_list *guestfs_test0rstructlist (guestfs_h *g, const char *val);

extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv_list *guestfs_test0rstructlisterr (guestfs_h *g);

#define LIBGUESTFS_HAVE_TGZ_IN 1
extern GUESTFS_DLL_PUBLIC int guestfs_tgz_in (guestfs_h *g, const char *tarball, const char *directory);

#define LIBGUESTFS_HAVE_TGZ_OUT 1
extern GUESTFS_DLL_PUBLIC int guestfs_tgz_out (guestfs_h *g, const char *directory, const char *tarball);

#define LIBGUESTFS_HAVE_TOUCH 1
extern GUESTFS_DLL_PUBLIC int guestfs_touch (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_TRUNCATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_truncate (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_TRUNCATE_SIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_truncate_size (guestfs_h *g, const char *path, int64_t size);

#define LIBGUESTFS_HAVE_TUNE2FS 1
#define GUESTFS_TUNE2FS_FORCE 0
#define GUESTFS_TUNE2FS_MAXMOUNTCOUNT 1
#define GUESTFS_TUNE2FS_MOUNTCOUNT 2
#define GUESTFS_TUNE2FS_ERRORBEHAVIOR 3
#define GUESTFS_TUNE2FS_GROUP 4
#define GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS 5
#define GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE 6
#define GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY 7
#define GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT 8
#define GUESTFS_TUNE2FS_USER 9
extern GUESTFS_DLL_PUBLIC int guestfs_tune2fs (guestfs_h *g, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_tune2fs_va (guestfs_h *g, const char *device, va_list args);

struct guestfs_tune2fs_argv {
  uint64_t bitmask;

# define GUESTFS_TUNE2FS_FORCE_BITMASK (UINT64_C(1)<<0)
  /* The field below is only valid in this struct if the
   * GUESTFS_TUNE2FS_FORCE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int force;

# define GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK (UINT64_C(1)<<1)
  /* The field below is only valid in this struct if the
   * GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int maxmountcount;

# define GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK (UINT64_C(1)<<2)
  /* The field below is only valid in this struct if the
   * GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int mountcount;

# define GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK (UINT64_C(1)<<3)
  /* The field below is only valid in this struct if the
   * GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  const char *errorbehavior;

# define GUESTFS_TUNE2FS_GROUP_BITMASK (UINT64_C(1)<<4)
  /* The field below is only valid in this struct if the
   * GUESTFS_TUNE2FS_GROUP_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t group;

# define GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK (UINT64_C(1)<<5)
  /* The field below is only valid in this struct if the
   * GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int intervalbetweenchecks;

# define GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK (UINT64_C(1)<<6)
  /* The field below is only valid in this struct if the
   * GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int reservedblockspercentage;

# define GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK (UINT64_C(1)<<7)
  /* The field below is only valid in this struct if the
   * GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  const char *lastmounteddirectory;

# define GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK (UINT64_C(1)<<8)
  /* The field below is only valid in this struct if the
   * GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t reservedblockscount;

# define GUESTFS_TUNE2FS_USER_BITMASK (UINT64_C(1)<<9)
  /* The field below is only valid in this struct if the
   * GUESTFS_TUNE2FS_USER_BITMASK bit is set
   * in the bitmask above.  If not, the field is ignored.
   */
  int64_t user;
};

extern GUESTFS_DLL_PUBLIC int guestfs_tune2fs_argv (guestfs_h *g, const char *device, const struct guestfs_tune2fs_argv *optargs);

#define LIBGUESTFS_HAVE_TUNE2FS_L 1
extern GUESTFS_DLL_PUBLIC char **guestfs_tune2fs_l (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_TXZ_IN 1
extern GUESTFS_DLL_PUBLIC int guestfs_txz_in (guestfs_h *g, const char *tarball, const char *directory);

#define LIBGUESTFS_HAVE_TXZ_OUT 1
extern GUESTFS_DLL_PUBLIC int guestfs_txz_out (guestfs_h *g, const char *directory, const char *tarball);

#define LIBGUESTFS_HAVE_UMASK 1
extern GUESTFS_DLL_PUBLIC int guestfs_umask (guestfs_h *g, int mask);

#define LIBGUESTFS_HAVE_UMOUNT 1
extern GUESTFS_DLL_PUBLIC int guestfs_umount (guestfs_h *g, const char *pathordevice);

#define LIBGUESTFS_HAVE_UMOUNT_ALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_umount_all (guestfs_h *g);

#define LIBGUESTFS_HAVE_UPLOAD 1
extern GUESTFS_DLL_PUBLIC int guestfs_upload (guestfs_h *g, const char *filename, const char *remotefilename);

#define LIBGUESTFS_HAVE_UPLOAD_OFFSET 1
extern GUESTFS_DLL_PUBLIC int guestfs_upload_offset (guestfs_h *g, const char *filename, const char *remotefilename, int64_t offset);

#define LIBGUESTFS_HAVE_UTIMENS 1
extern GUESTFS_DLL_PUBLIC int guestfs_utimens (guestfs_h *g, const char *path, int64_t atsecs, int64_t atnsecs, int64_t mtsecs, int64_t mtnsecs);

#define LIBGUESTFS_HAVE_VERSION 1
extern GUESTFS_DLL_PUBLIC struct guestfs_version *guestfs_version (guestfs_h *g);

#define LIBGUESTFS_HAVE_VFS_LABEL 1
extern GUESTFS_DLL_PUBLIC char *guestfs_vfs_label (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_VFS_TYPE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_vfs_type (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_VFS_UUID 1
extern GUESTFS_DLL_PUBLIC char *guestfs_vfs_uuid (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_VG_ACTIVATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_vg_activate (guestfs_h *g, int activate, char *const *volgroups);

#define LIBGUESTFS_HAVE_VG_ACTIVATE_ALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_vg_activate_all (guestfs_h *g, int activate);

#define LIBGUESTFS_HAVE_VGCREATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_vgcreate (guestfs_h *g, const char *volgroup, char *const *physvols);

#define LIBGUESTFS_HAVE_VGLVUUIDS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_vglvuuids (guestfs_h *g, const char *vgname);

#define LIBGUESTFS_HAVE_VGPVUUIDS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_vgpvuuids (guestfs_h *g, const char *vgname);

#define LIBGUESTFS_HAVE_VGREMOVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_vgremove (guestfs_h *g, const char *vgname);

#define LIBGUESTFS_HAVE_VGRENAME 1
extern GUESTFS_DLL_PUBLIC int guestfs_vgrename (guestfs_h *g, const char *volgroup, const char *newvolgroup);

#define LIBGUESTFS_HAVE_VGS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_vgs (guestfs_h *g);

#define LIBGUESTFS_HAVE_VGS_FULL 1
extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_vg_list *guestfs_vgs_full (guestfs_h *g);

#define LIBGUESTFS_HAVE_VGSCAN 1
extern GUESTFS_DLL_PUBLIC int guestfs_vgscan (guestfs_h *g);

#define LIBGUESTFS_HAVE_VGUUID 1
extern GUESTFS_DLL_PUBLIC char *guestfs_vguuid (guestfs_h *g, const char *vgname);

extern GUESTFS_DLL_PUBLIC int guestfs_wait_ready (guestfs_h *g)
  GUESTFS_DEPRECATED_BY ("launch");

#define LIBGUESTFS_HAVE_WC_C 1
extern GUESTFS_DLL_PUBLIC int guestfs_wc_c (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_WC_L 1
extern GUESTFS_DLL_PUBLIC int guestfs_wc_l (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_WC_W 1
extern GUESTFS_DLL_PUBLIC int guestfs_wc_w (guestfs_h *g, const char *path);

#define LIBGUESTFS_HAVE_WRITE 1
extern GUESTFS_DLL_PUBLIC int guestfs_write (guestfs_h *g, const char *path, const char *content, size_t content_size);

#define LIBGUESTFS_HAVE_WRITE_APPEND 1
extern GUESTFS_DLL_PUBLIC int guestfs_write_append (guestfs_h *g, const char *path, const char *content, size_t content_size);

extern GUESTFS_DLL_PUBLIC int guestfs_write_file (guestfs_h *g, const char *path, const char *content, int size)
  GUESTFS_DEPRECATED_BY ("write");

#define LIBGUESTFS_HAVE_ZEGREP 1
extern GUESTFS_DLL_PUBLIC char **guestfs_zegrep (guestfs_h *g, const char *regex, const char *path);

#define LIBGUESTFS_HAVE_ZEGREPI 1
extern GUESTFS_DLL_PUBLIC char **guestfs_zegrepi (guestfs_h *g, const char *regex, const char *path);

#define LIBGUESTFS_HAVE_ZERO 1
extern GUESTFS_DLL_PUBLIC int guestfs_zero (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_ZERO_DEVICE 1
extern GUESTFS_DLL_PUBLIC int guestfs_zero_device (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_ZEROFREE 1
extern GUESTFS_DLL_PUBLIC int guestfs_zerofree (guestfs_h *g, const char *device);

#define LIBGUESTFS_HAVE_ZFGREP 1
extern GUESTFS_DLL_PUBLIC char **guestfs_zfgrep (guestfs_h *g, const char *pattern, const char *path);

#define LIBGUESTFS_HAVE_ZFGREPI 1
extern GUESTFS_DLL_PUBLIC char **guestfs_zfgrepi (guestfs_h *g, const char *pattern, const char *path);

extern GUESTFS_DLL_PUBLIC char *guestfs_zfile (guestfs_h *g, const char *meth, const char *path)
  GUESTFS_DEPRECATED_BY ("file");

#define LIBGUESTFS_HAVE_ZGREP 1
extern GUESTFS_DLL_PUBLIC char **guestfs_zgrep (guestfs_h *g, const char *regex, const char *path);

#define LIBGUESTFS_HAVE_ZGREPI 1
extern GUESTFS_DLL_PUBLIC char **guestfs_zgrepi (guestfs_h *g, const char *regex, const char *path);


/* Private functions.
 *
 * These are NOT part of the public, stable API, and can change at any
 * time!  We export them because they are used by some of the language
 * bindings.
 */
extern GUESTFS_DLL_PUBLIC void *guestfs_safe_malloc (guestfs_h *g, size_t nbytes);
extern GUESTFS_DLL_PUBLIC void *guestfs_safe_calloc (guestfs_h *g, size_t n, size_t s);
extern GUESTFS_DLL_PUBLIC char *guestfs_safe_strdup (guestfs_h *g, const char *str);
extern GUESTFS_DLL_PUBLIC void *guestfs_safe_memdup (guestfs_h *g, void *ptr, size_t size);
extern GUESTFS_DLL_PUBLIC const char *guestfs_tmpdir (void);
#ifdef GUESTFS_PRIVATE_FOR_EACH_DISK
extern GUESTFS_DLL_PUBLIC int guestfs___for_each_disk (guestfs_h *g, virDomainPtr dom, int (*)(guestfs_h *g, const char *filename, const char *format, int readonly, void *data), void *data);
#endif
/* End of private functions. */

#ifdef __cplusplus
}
#endif

#endif /* GUESTFS_H_ */
