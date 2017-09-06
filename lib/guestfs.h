/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/c.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
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
 * Go and read it now!  This header file won't make much sense.
 *
 * For example code using the C API, see 'guestfs-examples(3)'
 * available online at: http://libguestfs.org/guestfs-examples.3.html
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

#if defined(__GNUC__) && !defined(GUESTFS_GCC_VERSION)
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
#else
# define GUESTFS_DLL_PUBLIC
#endif

#if defined(__GNUC__) && GUESTFS_GCC_VERSION >= 30100 /* gcc >= 3.1 */
# define GUESTFS_NORETURN __attribute__((noreturn))
#else
# define GUESTFS_NORETURN
#endif

/* The handle. */
#ifndef GUESTFS_TYPEDEF_H
#define GUESTFS_TYPEDEF_H 1
typedef struct guestfs_h guestfs_h;
#endif

/* Connection management. */
extern GUESTFS_DLL_PUBLIC guestfs_h *guestfs_create (void);
#define GUESTFS_HAVE_CREATE_FLAGS 1
extern GUESTFS_DLL_PUBLIC guestfs_h *guestfs_create_flags (unsigned flags, ...);
#define GUESTFS_CREATE_NO_ENVIRONMENT   (1 << 0)
#define GUESTFS_CREATE_NO_CLOSE_ON_EXIT (1 << 1)
extern GUESTFS_DLL_PUBLIC void guestfs_close (guestfs_h *g);

/* Error handling. */
extern GUESTFS_DLL_PUBLIC const char *guestfs_last_error (guestfs_h *g);
#define GUESTFS_HAVE_LAST_ERRNO 1
extern GUESTFS_DLL_PUBLIC int guestfs_last_errno (guestfs_h *g);

#ifndef GUESTFS_TYPEDEF_ERROR_HANDLER_CB
#define GUESTFS_TYPEDEF_ERROR_HANDLER_CB 1
typedef void (*guestfs_error_handler_cb) (guestfs_h *g, void *opaque, const char *msg);
#endif

#ifndef GUESTFS_TYPEDEF_ABORT_CB
#define GUESTFS_TYPEDEF_ABORT_CB 1
typedef void (*guestfs_abort_cb) (void) GUESTFS_NORETURN;
#endif

extern GUESTFS_DLL_PUBLIC void guestfs_set_error_handler (guestfs_h *g, guestfs_error_handler_cb cb, void *opaque);
extern GUESTFS_DLL_PUBLIC guestfs_error_handler_cb guestfs_get_error_handler (guestfs_h *g, void **opaque_rtn);
#define GUESTFS_HAVE_PUSH_ERROR_HANDLER 1
extern GUESTFS_DLL_PUBLIC void guestfs_push_error_handler (guestfs_h *g, guestfs_error_handler_cb cb, void *opaque);
#define GUESTFS_HAVE_POP_ERROR_HANDLER 1
extern GUESTFS_DLL_PUBLIC void guestfs_pop_error_handler (guestfs_h *g);

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
#define GUESTFS_EVENT_LIBVIRT_AUTH     0x0100
#define GUESTFS_EVENT_WARNING          0x0200
#define GUESTFS_EVENT_ALL              0x03ff

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

#define GUESTFS_HAVE_SET_EVENT_CALLBACK 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_event_callback (guestfs_h *g, guestfs_event_callback cb, uint64_t event_bitmask, int flags, void *opaque);
#define GUESTFS_HAVE_DELETE_EVENT_CALLBACK 1
extern GUESTFS_DLL_PUBLIC void guestfs_delete_event_callback (guestfs_h *g, int event_handle);
#define GUESTFS_HAVE_EVENT_TO_STRING 1
extern GUESTFS_DLL_PUBLIC char *guestfs_event_to_string (uint64_t event);

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
#define GUESTFS_HAVE_SET_CLOSE_CALLBACK 1
extern GUESTFS_DLL_PUBLIC void guestfs_set_close_callback (guestfs_h *g, guestfs_close_cb cb, void *opaque)
  GUESTFS_DEPRECATED_BY("set_event_callback");
#define GUESTFS_HAVE_SET_PROGRESS_CALLBACK 1
extern GUESTFS_DLL_PUBLIC void guestfs_set_progress_callback (guestfs_h *g, guestfs_progress_cb cb, void *opaque)
  GUESTFS_DEPRECATED_BY("set_event_callback");

/* Private data area. */
#define GUESTFS_HAVE_SET_PRIVATE 1
extern GUESTFS_DLL_PUBLIC void guestfs_set_private (guestfs_h *g, const char *key, void *data);
#define GUESTFS_HAVE_GET_PRIVATE 1
extern GUESTFS_DLL_PUBLIC void *guestfs_get_private (guestfs_h *g, const char *key);
#define GUESTFS_HAVE_FIRST_PRIVATE 1
extern GUESTFS_DLL_PUBLIC void *guestfs_first_private (guestfs_h *g, const char **key_rtn);
#define GUESTFS_HAVE_NEXT_PRIVATE 1
extern GUESTFS_DLL_PUBLIC void *guestfs_next_private (guestfs_h *g, const char **key_rtn);

/* Structures. */
#define GUESTFS_HAVE_STRUCT_APPLICATION 1

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

extern GUESTFS_DLL_PUBLIC int guestfs_compare_application (const struct guestfs_application *, const struct guestfs_application *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_application_list (const struct guestfs_application_list *, const struct guestfs_application_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_application *guestfs_copy_application (const struct guestfs_application *);
extern GUESTFS_DLL_PUBLIC struct guestfs_application_list *guestfs_copy_application_list (const struct guestfs_application_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_application (struct guestfs_application *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_application_list (struct guestfs_application_list *);

#define GUESTFS_HAVE_STRUCT_APPLICATION2 1

struct guestfs_application2 {
  char *app2_name;
  char *app2_display_name;
  int32_t app2_epoch;
  char *app2_version;
  char *app2_release;
  char *app2_arch;
  char *app2_install_path;
  char *app2_trans_path;
  char *app2_publisher;
  char *app2_url;
  char *app2_source_package;
  char *app2_summary;
  char *app2_description;
  char *app2_spare1;
  char *app2_spare2;
  char *app2_spare3;
  char *app2_spare4;
};

struct guestfs_application2_list {
  uint32_t len;
  struct guestfs_application2 *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_application2 (const struct guestfs_application2 *, const struct guestfs_application2 *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_application2_list (const struct guestfs_application2_list *, const struct guestfs_application2_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_application2 *guestfs_copy_application2 (const struct guestfs_application2 *);
extern GUESTFS_DLL_PUBLIC struct guestfs_application2_list *guestfs_copy_application2_list (const struct guestfs_application2_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_application2 (struct guestfs_application2 *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_application2_list (struct guestfs_application2_list *);

#define GUESTFS_HAVE_STRUCT_BTRFSBALANCE 1

struct guestfs_btrfsbalance {
  char *btrfsbalance_status;
  uint64_t btrfsbalance_total;
  uint64_t btrfsbalance_balanced;
  uint64_t btrfsbalance_considered;
  uint64_t btrfsbalance_left;
};

struct guestfs_btrfsbalance_list {
  uint32_t len;
  struct guestfs_btrfsbalance *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_btrfsbalance (const struct guestfs_btrfsbalance *, const struct guestfs_btrfsbalance *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_btrfsbalance_list (const struct guestfs_btrfsbalance_list *, const struct guestfs_btrfsbalance_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_btrfsbalance *guestfs_copy_btrfsbalance (const struct guestfs_btrfsbalance *);
extern GUESTFS_DLL_PUBLIC struct guestfs_btrfsbalance_list *guestfs_copy_btrfsbalance_list (const struct guestfs_btrfsbalance_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_btrfsbalance (struct guestfs_btrfsbalance *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_btrfsbalance_list (struct guestfs_btrfsbalance_list *);

#define GUESTFS_HAVE_STRUCT_BTRFSQGROUP 1

struct guestfs_btrfsqgroup {
  char *btrfsqgroup_id;
  uint64_t btrfsqgroup_rfer;
  uint64_t btrfsqgroup_excl;
};

struct guestfs_btrfsqgroup_list {
  uint32_t len;
  struct guestfs_btrfsqgroup *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_btrfsqgroup (const struct guestfs_btrfsqgroup *, const struct guestfs_btrfsqgroup *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_btrfsqgroup_list (const struct guestfs_btrfsqgroup_list *, const struct guestfs_btrfsqgroup_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_btrfsqgroup *guestfs_copy_btrfsqgroup (const struct guestfs_btrfsqgroup *);
extern GUESTFS_DLL_PUBLIC struct guestfs_btrfsqgroup_list *guestfs_copy_btrfsqgroup_list (const struct guestfs_btrfsqgroup_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_btrfsqgroup (struct guestfs_btrfsqgroup *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_btrfsqgroup_list (struct guestfs_btrfsqgroup_list *);

#define GUESTFS_HAVE_STRUCT_BTRFSSCRUB 1

struct guestfs_btrfsscrub {
  uint64_t btrfsscrub_data_extents_scrubbed;
  uint64_t btrfsscrub_tree_extents_scrubbed;
  uint64_t btrfsscrub_data_bytes_scrubbed;
  uint64_t btrfsscrub_tree_bytes_scrubbed;
  uint64_t btrfsscrub_read_errors;
  uint64_t btrfsscrub_csum_errors;
  uint64_t btrfsscrub_verify_errors;
  uint64_t btrfsscrub_no_csum;
  uint64_t btrfsscrub_csum_discards;
  uint64_t btrfsscrub_super_errors;
  uint64_t btrfsscrub_malloc_errors;
  uint64_t btrfsscrub_uncorrectable_errors;
  uint64_t btrfsscrub_unverified_errors;
  uint64_t btrfsscrub_corrected_errors;
  uint64_t btrfsscrub_last_physical;
};

struct guestfs_btrfsscrub_list {
  uint32_t len;
  struct guestfs_btrfsscrub *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_btrfsscrub (const struct guestfs_btrfsscrub *, const struct guestfs_btrfsscrub *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_btrfsscrub_list (const struct guestfs_btrfsscrub_list *, const struct guestfs_btrfsscrub_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_btrfsscrub *guestfs_copy_btrfsscrub (const struct guestfs_btrfsscrub *);
extern GUESTFS_DLL_PUBLIC struct guestfs_btrfsscrub_list *guestfs_copy_btrfsscrub_list (const struct guestfs_btrfsscrub_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_btrfsscrub (struct guestfs_btrfsscrub *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_btrfsscrub_list (struct guestfs_btrfsscrub_list *);

#define GUESTFS_HAVE_STRUCT_BTRFSSUBVOLUME 1

struct guestfs_btrfssubvolume {
  uint64_t btrfssubvolume_id;
  uint64_t btrfssubvolume_top_level_id;
  char *btrfssubvolume_path;
};

struct guestfs_btrfssubvolume_list {
  uint32_t len;
  struct guestfs_btrfssubvolume *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_btrfssubvolume (const struct guestfs_btrfssubvolume *, const struct guestfs_btrfssubvolume *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_btrfssubvolume_list (const struct guestfs_btrfssubvolume_list *, const struct guestfs_btrfssubvolume_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_btrfssubvolume *guestfs_copy_btrfssubvolume (const struct guestfs_btrfssubvolume *);
extern GUESTFS_DLL_PUBLIC struct guestfs_btrfssubvolume_list *guestfs_copy_btrfssubvolume_list (const struct guestfs_btrfssubvolume_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_btrfssubvolume (struct guestfs_btrfssubvolume *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_btrfssubvolume_list (struct guestfs_btrfssubvolume_list *);

#define GUESTFS_HAVE_STRUCT_DIRENT 1

struct guestfs_dirent {
  int64_t ino;
  char ftyp;
  char *name;
};

struct guestfs_dirent_list {
  uint32_t len;
  struct guestfs_dirent *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_dirent (const struct guestfs_dirent *, const struct guestfs_dirent *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_dirent_list (const struct guestfs_dirent_list *, const struct guestfs_dirent_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_dirent *guestfs_copy_dirent (const struct guestfs_dirent *);
extern GUESTFS_DLL_PUBLIC struct guestfs_dirent_list *guestfs_copy_dirent_list (const struct guestfs_dirent_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_dirent (struct guestfs_dirent *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_dirent_list (struct guestfs_dirent_list *);

#define GUESTFS_HAVE_STRUCT_HIVEX_NODE 1

struct guestfs_hivex_node {
  int64_t hivex_node_h;
};

struct guestfs_hivex_node_list {
  uint32_t len;
  struct guestfs_hivex_node *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_hivex_node (const struct guestfs_hivex_node *, const struct guestfs_hivex_node *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_hivex_node_list (const struct guestfs_hivex_node_list *, const struct guestfs_hivex_node_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_hivex_node *guestfs_copy_hivex_node (const struct guestfs_hivex_node *);
extern GUESTFS_DLL_PUBLIC struct guestfs_hivex_node_list *guestfs_copy_hivex_node_list (const struct guestfs_hivex_node_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_hivex_node (struct guestfs_hivex_node *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_hivex_node_list (struct guestfs_hivex_node_list *);

#define GUESTFS_HAVE_STRUCT_HIVEX_VALUE 1

struct guestfs_hivex_value {
  int64_t hivex_value_h;
};

struct guestfs_hivex_value_list {
  uint32_t len;
  struct guestfs_hivex_value *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_hivex_value (const struct guestfs_hivex_value *, const struct guestfs_hivex_value *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_hivex_value_list (const struct guestfs_hivex_value_list *, const struct guestfs_hivex_value_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_hivex_value *guestfs_copy_hivex_value (const struct guestfs_hivex_value *);
extern GUESTFS_DLL_PUBLIC struct guestfs_hivex_value_list *guestfs_copy_hivex_value_list (const struct guestfs_hivex_value_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_hivex_value (struct guestfs_hivex_value *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_hivex_value_list (struct guestfs_hivex_value_list *);

#define GUESTFS_HAVE_STRUCT_INOTIFY_EVENT 1

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

extern GUESTFS_DLL_PUBLIC int guestfs_compare_inotify_event (const struct guestfs_inotify_event *, const struct guestfs_inotify_event *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_inotify_event_list (const struct guestfs_inotify_event_list *, const struct guestfs_inotify_event_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_inotify_event *guestfs_copy_inotify_event (const struct guestfs_inotify_event *);
extern GUESTFS_DLL_PUBLIC struct guestfs_inotify_event_list *guestfs_copy_inotify_event_list (const struct guestfs_inotify_event_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_inotify_event (struct guestfs_inotify_event *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_inotify_event_list (struct guestfs_inotify_event_list *);

#define GUESTFS_HAVE_STRUCT_INT_BOOL 1

struct guestfs_int_bool {
  int32_t i;
  int32_t b;
};

struct guestfs_int_bool_list {
  uint32_t len;
  struct guestfs_int_bool *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_int_bool (const struct guestfs_int_bool *, const struct guestfs_int_bool *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_int_bool_list (const struct guestfs_int_bool_list *, const struct guestfs_int_bool_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_int_bool *guestfs_copy_int_bool (const struct guestfs_int_bool *);
extern GUESTFS_DLL_PUBLIC struct guestfs_int_bool_list *guestfs_copy_int_bool_list (const struct guestfs_int_bool_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_int_bool (struct guestfs_int_bool *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_int_bool_list (struct guestfs_int_bool_list *);

#define GUESTFS_HAVE_STRUCT_ISOINFO 1

struct guestfs_isoinfo {
  char *iso_system_id;
  char *iso_volume_id;
  uint32_t iso_volume_space_size;
  uint32_t iso_volume_set_size;
  uint32_t iso_volume_sequence_number;
  uint32_t iso_logical_block_size;
  char *iso_volume_set_id;
  char *iso_publisher_id;
  char *iso_data_preparer_id;
  char *iso_application_id;
  char *iso_copyright_file_id;
  char *iso_abstract_file_id;
  char *iso_bibliographic_file_id;
  int64_t iso_volume_creation_t;
  int64_t iso_volume_modification_t;
  int64_t iso_volume_expiration_t;
  int64_t iso_volume_effective_t;
};

struct guestfs_isoinfo_list {
  uint32_t len;
  struct guestfs_isoinfo *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_isoinfo (const struct guestfs_isoinfo *, const struct guestfs_isoinfo *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_isoinfo_list (const struct guestfs_isoinfo_list *, const struct guestfs_isoinfo_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_isoinfo *guestfs_copy_isoinfo (const struct guestfs_isoinfo *);
extern GUESTFS_DLL_PUBLIC struct guestfs_isoinfo_list *guestfs_copy_isoinfo_list (const struct guestfs_isoinfo_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_isoinfo (struct guestfs_isoinfo *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_isoinfo_list (struct guestfs_isoinfo_list *);

#define GUESTFS_HAVE_STRUCT_LVM_LV 1

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

extern GUESTFS_DLL_PUBLIC int guestfs_compare_lvm_lv (const struct guestfs_lvm_lv *, const struct guestfs_lvm_lv *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_lvm_lv_list (const struct guestfs_lvm_lv_list *, const struct guestfs_lvm_lv_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_lv *guestfs_copy_lvm_lv (const struct guestfs_lvm_lv *);
extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_lv_list *guestfs_copy_lvm_lv_list (const struct guestfs_lvm_lv_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_lvm_lv (struct guestfs_lvm_lv *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_lvm_lv_list (struct guestfs_lvm_lv_list *);

#define GUESTFS_HAVE_STRUCT_LVM_PV 1

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

extern GUESTFS_DLL_PUBLIC int guestfs_compare_lvm_pv (const struct guestfs_lvm_pv *, const struct guestfs_lvm_pv *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_lvm_pv_list (const struct guestfs_lvm_pv_list *, const struct guestfs_lvm_pv_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv *guestfs_copy_lvm_pv (const struct guestfs_lvm_pv *);
extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv_list *guestfs_copy_lvm_pv_list (const struct guestfs_lvm_pv_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_lvm_pv (struct guestfs_lvm_pv *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_lvm_pv_list (struct guestfs_lvm_pv_list *);

#define GUESTFS_HAVE_STRUCT_LVM_VG 1

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

extern GUESTFS_DLL_PUBLIC int guestfs_compare_lvm_vg (const struct guestfs_lvm_vg *, const struct guestfs_lvm_vg *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_lvm_vg_list (const struct guestfs_lvm_vg_list *, const struct guestfs_lvm_vg_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_vg *guestfs_copy_lvm_vg (const struct guestfs_lvm_vg *);
extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_vg_list *guestfs_copy_lvm_vg_list (const struct guestfs_lvm_vg_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_lvm_vg (struct guestfs_lvm_vg *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_lvm_vg_list (struct guestfs_lvm_vg_list *);

#define GUESTFS_HAVE_STRUCT_MDSTAT 1

struct guestfs_mdstat {
  char *mdstat_device;
  int32_t mdstat_index;
  char *mdstat_flags;
};

struct guestfs_mdstat_list {
  uint32_t len;
  struct guestfs_mdstat *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_mdstat (const struct guestfs_mdstat *, const struct guestfs_mdstat *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_mdstat_list (const struct guestfs_mdstat_list *, const struct guestfs_mdstat_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_mdstat *guestfs_copy_mdstat (const struct guestfs_mdstat *);
extern GUESTFS_DLL_PUBLIC struct guestfs_mdstat_list *guestfs_copy_mdstat_list (const struct guestfs_mdstat_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_mdstat (struct guestfs_mdstat *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_mdstat_list (struct guestfs_mdstat_list *);

#define GUESTFS_HAVE_STRUCT_PARTITION 1

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

extern GUESTFS_DLL_PUBLIC int guestfs_compare_partition (const struct guestfs_partition *, const struct guestfs_partition *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_partition_list (const struct guestfs_partition_list *, const struct guestfs_partition_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_partition *guestfs_copy_partition (const struct guestfs_partition *);
extern GUESTFS_DLL_PUBLIC struct guestfs_partition_list *guestfs_copy_partition_list (const struct guestfs_partition_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_partition (struct guestfs_partition *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_partition_list (struct guestfs_partition_list *);

#define GUESTFS_HAVE_STRUCT_STAT 1

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

extern GUESTFS_DLL_PUBLIC int guestfs_compare_stat (const struct guestfs_stat *, const struct guestfs_stat *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_stat_list (const struct guestfs_stat_list *, const struct guestfs_stat_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_stat *guestfs_copy_stat (const struct guestfs_stat *);
extern GUESTFS_DLL_PUBLIC struct guestfs_stat_list *guestfs_copy_stat_list (const struct guestfs_stat_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_stat (struct guestfs_stat *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_stat_list (struct guestfs_stat_list *);

#define GUESTFS_HAVE_STRUCT_STATNS 1

struct guestfs_statns {
  int64_t st_dev;
  int64_t st_ino;
  int64_t st_mode;
  int64_t st_nlink;
  int64_t st_uid;
  int64_t st_gid;
  int64_t st_rdev;
  int64_t st_size;
  int64_t st_blksize;
  int64_t st_blocks;
  int64_t st_atime_sec;
  int64_t st_atime_nsec;
  int64_t st_mtime_sec;
  int64_t st_mtime_nsec;
  int64_t st_ctime_sec;
  int64_t st_ctime_nsec;
  int64_t st_spare1;
  int64_t st_spare2;
  int64_t st_spare3;
  int64_t st_spare4;
  int64_t st_spare5;
  int64_t st_spare6;
};

struct guestfs_statns_list {
  uint32_t len;
  struct guestfs_statns *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_statns (const struct guestfs_statns *, const struct guestfs_statns *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_statns_list (const struct guestfs_statns_list *, const struct guestfs_statns_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_statns *guestfs_copy_statns (const struct guestfs_statns *);
extern GUESTFS_DLL_PUBLIC struct guestfs_statns_list *guestfs_copy_statns_list (const struct guestfs_statns_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_statns (struct guestfs_statns *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_statns_list (struct guestfs_statns_list *);

#define GUESTFS_HAVE_STRUCT_STATVFS 1

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

extern GUESTFS_DLL_PUBLIC int guestfs_compare_statvfs (const struct guestfs_statvfs *, const struct guestfs_statvfs *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_statvfs_list (const struct guestfs_statvfs_list *, const struct guestfs_statvfs_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_statvfs *guestfs_copy_statvfs (const struct guestfs_statvfs *);
extern GUESTFS_DLL_PUBLIC struct guestfs_statvfs_list *guestfs_copy_statvfs_list (const struct guestfs_statvfs_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_statvfs (struct guestfs_statvfs *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_statvfs_list (struct guestfs_statvfs_list *);

#define GUESTFS_HAVE_STRUCT_TSK_DIRENT 1

struct guestfs_tsk_dirent {
  uint64_t tsk_inode;
  char tsk_type;
  int64_t tsk_size;
  char *tsk_name;
  uint32_t tsk_flags;
  int64_t tsk_atime_sec;
  int64_t tsk_atime_nsec;
  int64_t tsk_mtime_sec;
  int64_t tsk_mtime_nsec;
  int64_t tsk_ctime_sec;
  int64_t tsk_ctime_nsec;
  int64_t tsk_crtime_sec;
  int64_t tsk_crtime_nsec;
  int64_t tsk_nlink;
  char *tsk_link;
  int64_t tsk_spare1;
};

struct guestfs_tsk_dirent_list {
  uint32_t len;
  struct guestfs_tsk_dirent *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_tsk_dirent (const struct guestfs_tsk_dirent *, const struct guestfs_tsk_dirent *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_tsk_dirent_list (const struct guestfs_tsk_dirent_list *, const struct guestfs_tsk_dirent_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_tsk_dirent *guestfs_copy_tsk_dirent (const struct guestfs_tsk_dirent *);
extern GUESTFS_DLL_PUBLIC struct guestfs_tsk_dirent_list *guestfs_copy_tsk_dirent_list (const struct guestfs_tsk_dirent_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_tsk_dirent (struct guestfs_tsk_dirent *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_tsk_dirent_list (struct guestfs_tsk_dirent_list *);

#define GUESTFS_HAVE_STRUCT_UTSNAME 1

struct guestfs_utsname {
  char *uts_sysname;
  char *uts_release;
  char *uts_version;
  char *uts_machine;
};

struct guestfs_utsname_list {
  uint32_t len;
  struct guestfs_utsname *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_utsname (const struct guestfs_utsname *, const struct guestfs_utsname *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_utsname_list (const struct guestfs_utsname_list *, const struct guestfs_utsname_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_utsname *guestfs_copy_utsname (const struct guestfs_utsname *);
extern GUESTFS_DLL_PUBLIC struct guestfs_utsname_list *guestfs_copy_utsname_list (const struct guestfs_utsname_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_utsname (struct guestfs_utsname *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_utsname_list (struct guestfs_utsname_list *);

#define GUESTFS_HAVE_STRUCT_VERSION 1

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

extern GUESTFS_DLL_PUBLIC int guestfs_compare_version (const struct guestfs_version *, const struct guestfs_version *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_version_list (const struct guestfs_version_list *, const struct guestfs_version_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_version *guestfs_copy_version (const struct guestfs_version *);
extern GUESTFS_DLL_PUBLIC struct guestfs_version_list *guestfs_copy_version_list (const struct guestfs_version_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_version (struct guestfs_version *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_version_list (struct guestfs_version_list *);

#define GUESTFS_HAVE_STRUCT_XATTR 1

struct guestfs_xattr {
  char *attrname;
  uint32_t attrval_len;
  char *attrval;
};

struct guestfs_xattr_list {
  uint32_t len;
  struct guestfs_xattr *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_xattr (const struct guestfs_xattr *, const struct guestfs_xattr *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_xattr_list (const struct guestfs_xattr_list *, const struct guestfs_xattr_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_xattr *guestfs_copy_xattr (const struct guestfs_xattr *);
extern GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *guestfs_copy_xattr_list (const struct guestfs_xattr_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_xattr (struct guestfs_xattr *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_xattr_list (struct guestfs_xattr_list *);

#define GUESTFS_HAVE_STRUCT_XFSINFO 1

struct guestfs_xfsinfo {
  char *xfs_mntpoint;
  uint32_t xfs_inodesize;
  uint32_t xfs_agcount;
  uint32_t xfs_agsize;
  uint32_t xfs_sectsize;
  uint32_t xfs_attr;
  uint32_t xfs_blocksize;
  uint64_t xfs_datablocks;
  uint32_t xfs_imaxpct;
  uint32_t xfs_sunit;
  uint32_t xfs_swidth;
  uint32_t xfs_dirversion;
  uint32_t xfs_dirblocksize;
  uint32_t xfs_cimode;
  char *xfs_logname;
  uint32_t xfs_logblocksize;
  uint32_t xfs_logblocks;
  uint32_t xfs_logversion;
  uint32_t xfs_logsectsize;
  uint32_t xfs_logsunit;
  uint32_t xfs_lazycount;
  char *xfs_rtname;
  uint32_t xfs_rtextsize;
  uint64_t xfs_rtblocks;
  uint64_t xfs_rtextents;
};

struct guestfs_xfsinfo_list {
  uint32_t len;
  struct guestfs_xfsinfo *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_xfsinfo (const struct guestfs_xfsinfo *, const struct guestfs_xfsinfo *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_xfsinfo_list (const struct guestfs_xfsinfo_list *, const struct guestfs_xfsinfo_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_xfsinfo *guestfs_copy_xfsinfo (const struct guestfs_xfsinfo *);
extern GUESTFS_DLL_PUBLIC struct guestfs_xfsinfo_list *guestfs_copy_xfsinfo_list (const struct guestfs_xfsinfo_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_xfsinfo (struct guestfs_xfsinfo *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_xfsinfo_list (struct guestfs_xfsinfo_list *);

/* Actions. */
#define GUESTFS_HAVE_ACL_DELETE_DEF_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_acl_delete_def_file (guestfs_h *g, const char *dir);

#define GUESTFS_HAVE_ACL_GET_FILE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_acl_get_file (guestfs_h *g, const char *path, const char *acltype);

#define GUESTFS_HAVE_ACL_SET_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_acl_set_file (guestfs_h *g, const char *path, const char *acltype, const char *acl);

#define GUESTFS_HAVE_ADD_CDROM 1
extern GUESTFS_DLL_PUBLIC int guestfs_add_cdrom (guestfs_h *g, const char *filename)
  GUESTFS_DEPRECATED_BY ("add_drive_ro");

#define GUESTFS_HAVE_ADD_DOMAIN 1
#define GUESTFS_ADD_DOMAIN_LIBVIRTURI 0
#define GUESTFS_ADD_DOMAIN_READONLY 1
#define GUESTFS_ADD_DOMAIN_IFACE 2
#define GUESTFS_ADD_DOMAIN_LIVE 3
#define GUESTFS_ADD_DOMAIN_ALLOWUUID 4
#define GUESTFS_ADD_DOMAIN_READONLYDISK 5
#define GUESTFS_ADD_DOMAIN_CACHEMODE 6
#define GUESTFS_ADD_DOMAIN_DISCARD 7
#define GUESTFS_ADD_DOMAIN_COPYONREAD 8
extern GUESTFS_DLL_PUBLIC int guestfs_add_domain (guestfs_h *g, const char *dom, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_add_domain_va (guestfs_h *g, const char *dom, va_list args);

struct guestfs_add_domain_argv {
  uint64_t bitmask;
# define GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK (UINT64_C(1)<<0)
  const char *libvirturi;
# define GUESTFS_ADD_DOMAIN_READONLY_BITMASK (UINT64_C(1)<<1)
  int readonly;
# define GUESTFS_ADD_DOMAIN_IFACE_BITMASK (UINT64_C(1)<<2)
  const char *iface;
# define GUESTFS_ADD_DOMAIN_LIVE_BITMASK (UINT64_C(1)<<3)
  int live;
# define GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK (UINT64_C(1)<<4)
  int allowuuid;
# define GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK (UINT64_C(1)<<5)
  const char *readonlydisk;
# define GUESTFS_ADD_DOMAIN_CACHEMODE_BITMASK (UINT64_C(1)<<6)
  const char *cachemode;
# define GUESTFS_ADD_DOMAIN_DISCARD_BITMASK (UINT64_C(1)<<7)
  const char *discard;
# define GUESTFS_ADD_DOMAIN_COPYONREAD_BITMASK (UINT64_C(1)<<8)
  int copyonread;
};

extern GUESTFS_DLL_PUBLIC int guestfs_add_domain_argv (guestfs_h *g, const char *dom, const struct guestfs_add_domain_argv *optargs);

#define GUESTFS_HAVE_ADD_DRIVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_add_drive (guestfs_h *g, const char *filename);

#define GUESTFS_HAVE_ADD_DRIVE_OPTS 1
#define GUESTFS_ADD_DRIVE_OPTS_READONLY 0
#define GUESTFS_ADD_DRIVE_OPTS_FORMAT 1
#define GUESTFS_ADD_DRIVE_OPTS_IFACE 2
#define GUESTFS_ADD_DRIVE_OPTS_NAME 3
#define GUESTFS_ADD_DRIVE_OPTS_LABEL 4
#define GUESTFS_ADD_DRIVE_OPTS_PROTOCOL 5
#define GUESTFS_ADD_DRIVE_OPTS_SERVER 6
#define GUESTFS_ADD_DRIVE_OPTS_USERNAME 7
#define GUESTFS_ADD_DRIVE_OPTS_SECRET 8
#define GUESTFS_ADD_DRIVE_OPTS_CACHEMODE 9
#define GUESTFS_ADD_DRIVE_OPTS_DISCARD 10
#define GUESTFS_ADD_DRIVE_OPTS_COPYONREAD 11
extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_opts (guestfs_h *g, const char *filename, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_opts_va (guestfs_h *g, const char *filename, va_list args);

struct guestfs_add_drive_opts_argv {
  uint64_t bitmask;
# define GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK (UINT64_C(1)<<0)
  int readonly;
# define GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK (UINT64_C(1)<<1)
  const char *format;
# define GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK (UINT64_C(1)<<2)
  const char *iface;
# define GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK (UINT64_C(1)<<3)
  const char *name;
# define GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK (UINT64_C(1)<<4)
  const char *label;
# define GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK (UINT64_C(1)<<5)
  const char *protocol;
# define GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK (UINT64_C(1)<<6)
  char *const *server;
# define GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK (UINT64_C(1)<<7)
  const char *username;
# define GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK (UINT64_C(1)<<8)
  const char *secret;
# define GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK (UINT64_C(1)<<9)
  const char *cachemode;
# define GUESTFS_ADD_DRIVE_OPTS_DISCARD_BITMASK (UINT64_C(1)<<10)
  const char *discard;
# define GUESTFS_ADD_DRIVE_OPTS_COPYONREAD_BITMASK (UINT64_C(1)<<11)
  int copyonread;
};

extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_opts_argv (guestfs_h *g, const char *filename, const struct guestfs_add_drive_opts_argv *optargs);

#define GUESTFS_HAVE_ADD_DRIVE_RO 1
extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_ro (guestfs_h *g, const char *filename);

#define GUESTFS_HAVE_ADD_DRIVE_RO_WITH_IF 1
extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_ro_with_if (guestfs_h *g, const char *filename, const char *iface)
  GUESTFS_DEPRECATED_BY ("add_drive");

#define GUESTFS_HAVE_ADD_DRIVE_SCRATCH 1
#define GUESTFS_ADD_DRIVE_SCRATCH_NAME 0
#define GUESTFS_ADD_DRIVE_SCRATCH_LABEL 1
extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_scratch (guestfs_h *g, int64_t size, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_scratch_va (guestfs_h *g, int64_t size, va_list args);

struct guestfs_add_drive_scratch_argv {
  uint64_t bitmask;
# define GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK (UINT64_C(1)<<0)
  const char *name;
# define GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK (UINT64_C(1)<<1)
  const char *label;
};

extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_scratch_argv (guestfs_h *g, int64_t size, const struct guestfs_add_drive_scratch_argv *optargs);

#define GUESTFS_HAVE_ADD_DRIVE_WITH_IF 1
extern GUESTFS_DLL_PUBLIC int guestfs_add_drive_with_if (guestfs_h *g, const char *filename, const char *iface)
  GUESTFS_DEPRECATED_BY ("add_drive");

#define GUESTFS_HAVE_ADD_LIBVIRT_DOM 1
#define GUESTFS_ADD_LIBVIRT_DOM_READONLY 0
#define GUESTFS_ADD_LIBVIRT_DOM_IFACE 1
#define GUESTFS_ADD_LIBVIRT_DOM_LIVE 2
#define GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK 3
#define GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE 4
#define GUESTFS_ADD_LIBVIRT_DOM_DISCARD 5
#define GUESTFS_ADD_LIBVIRT_DOM_COPYONREAD 6
extern GUESTFS_DLL_PUBLIC int guestfs_add_libvirt_dom (guestfs_h *g, void * /* really virDomainPtr */ dom, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_add_libvirt_dom_va (guestfs_h *g, void * /* really virDomainPtr */ dom, va_list args);

struct guestfs_add_libvirt_dom_argv {
  uint64_t bitmask;
# define GUESTFS_ADD_LIBVIRT_DOM_READONLY_BITMASK (UINT64_C(1)<<0)
  int readonly;
# define GUESTFS_ADD_LIBVIRT_DOM_IFACE_BITMASK (UINT64_C(1)<<1)
  const char *iface;
# define GUESTFS_ADD_LIBVIRT_DOM_LIVE_BITMASK (UINT64_C(1)<<2)
  int live;
# define GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK_BITMASK (UINT64_C(1)<<3)
  const char *readonlydisk;
# define GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE_BITMASK (UINT64_C(1)<<4)
  const char *cachemode;
# define GUESTFS_ADD_LIBVIRT_DOM_DISCARD_BITMASK (UINT64_C(1)<<5)
  const char *discard;
# define GUESTFS_ADD_LIBVIRT_DOM_COPYONREAD_BITMASK (UINT64_C(1)<<6)
  int copyonread;
};

extern GUESTFS_DLL_PUBLIC int guestfs_add_libvirt_dom_argv (guestfs_h *g, void * /* really virDomainPtr */ dom, const struct guestfs_add_libvirt_dom_argv *optargs);

#define GUESTFS_HAVE_AUG_CLEAR 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_clear (guestfs_h *g, const char *augpath);

#define GUESTFS_HAVE_AUG_CLOSE 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_close (guestfs_h *g);

#define GUESTFS_HAVE_AUG_DEFNODE 1
extern GUESTFS_DLL_PUBLIC struct guestfs_int_bool *guestfs_aug_defnode (guestfs_h *g, const char *name, const char *expr, const char *val);

#define GUESTFS_HAVE_AUG_DEFVAR 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_defvar (guestfs_h *g, const char *name, const char *expr);

#define GUESTFS_HAVE_AUG_GET 1
extern GUESTFS_DLL_PUBLIC char *guestfs_aug_get (guestfs_h *g, const char *augpath);

#define GUESTFS_HAVE_AUG_INIT 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_init (guestfs_h *g, const char *root, int flags);

#define GUESTFS_HAVE_AUG_INSERT 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_insert (guestfs_h *g, const char *augpath, const char *label, int before);

#define GUESTFS_HAVE_AUG_LABEL 1
extern GUESTFS_DLL_PUBLIC char *guestfs_aug_label (guestfs_h *g, const char *augpath);

#define GUESTFS_HAVE_AUG_LOAD 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_load (guestfs_h *g);

#define GUESTFS_HAVE_AUG_LS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_aug_ls (guestfs_h *g, const char *augpath);

#define GUESTFS_HAVE_AUG_MATCH 1
extern GUESTFS_DLL_PUBLIC char **guestfs_aug_match (guestfs_h *g, const char *augpath);

#define GUESTFS_HAVE_AUG_MV 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_mv (guestfs_h *g, const char *src, const char *dest);

#define GUESTFS_HAVE_AUG_RM 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_rm (guestfs_h *g, const char *augpath);

#define GUESTFS_HAVE_AUG_SAVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_save (guestfs_h *g);

#define GUESTFS_HAVE_AUG_SET 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_set (guestfs_h *g, const char *augpath, const char *val);

#define GUESTFS_HAVE_AUG_SETM 1
extern GUESTFS_DLL_PUBLIC int guestfs_aug_setm (guestfs_h *g, const char *base, const char *sub, const char *val);

#define GUESTFS_HAVE_AUG_TRANSFORM 1
#define GUESTFS_AUG_TRANSFORM_REMOVE 0
extern GUESTFS_DLL_PUBLIC int guestfs_aug_transform (guestfs_h *g, const char *lens, const char *file, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_aug_transform_va (guestfs_h *g, const char *lens, const char *file, va_list args);

struct guestfs_aug_transform_argv {
  uint64_t bitmask;
# define GUESTFS_AUG_TRANSFORM_REMOVE_BITMASK (UINT64_C(1)<<0)
  int remove;
};

extern GUESTFS_DLL_PUBLIC int guestfs_aug_transform_argv (guestfs_h *g, const char *lens, const char *file, const struct guestfs_aug_transform_argv *optargs);

#define GUESTFS_HAVE_AVAILABLE 1
extern GUESTFS_DLL_PUBLIC int guestfs_available (guestfs_h *g, char *const *groups);

#define GUESTFS_HAVE_AVAILABLE_ALL_GROUPS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_available_all_groups (guestfs_h *g);

#define GUESTFS_HAVE_BASE64_IN 1
extern GUESTFS_DLL_PUBLIC int guestfs_base64_in (guestfs_h *g, const char *base64file, const char *filename);

#define GUESTFS_HAVE_BASE64_OUT 1
extern GUESTFS_DLL_PUBLIC int guestfs_base64_out (guestfs_h *g, const char *filename, const char *base64file);

#define GUESTFS_HAVE_BLKDISCARD 1
extern GUESTFS_DLL_PUBLIC int guestfs_blkdiscard (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BLKDISCARDZEROES 1
extern GUESTFS_DLL_PUBLIC int guestfs_blkdiscardzeroes (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BLKID 1
extern GUESTFS_DLL_PUBLIC char **guestfs_blkid (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BLOCKDEV_FLUSHBUFS 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_flushbufs (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BLOCKDEV_GETBSZ 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_getbsz (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BLOCKDEV_GETRO 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_getro (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BLOCKDEV_GETSIZE64 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_blockdev_getsize64 (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BLOCKDEV_GETSS 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_getss (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BLOCKDEV_GETSZ 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_blockdev_getsz (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BLOCKDEV_REREADPT 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_rereadpt (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BLOCKDEV_SETBSZ 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_setbsz (guestfs_h *g, const char *device, int blocksize)
  GUESTFS_DEPRECATED_BY ("mkfs");

#define GUESTFS_HAVE_BLOCKDEV_SETRA 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_setra (guestfs_h *g, const char *device, int sectors);

#define GUESTFS_HAVE_BLOCKDEV_SETRO 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_setro (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BLOCKDEV_SETRW 1
extern GUESTFS_DLL_PUBLIC int guestfs_blockdev_setrw (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BTRFS_BALANCE_CANCEL 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_balance_cancel (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_BTRFS_BALANCE_PAUSE 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_balance_pause (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_BTRFS_BALANCE_RESUME 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_balance_resume (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_BTRFS_BALANCE_STATUS 1
extern GUESTFS_DLL_PUBLIC struct guestfs_btrfsbalance *guestfs_btrfs_balance_status (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_BTRFS_DEVICE_ADD 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_device_add (guestfs_h *g, char *const *devices, const char *fs);

#define GUESTFS_HAVE_BTRFS_DEVICE_DELETE 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_device_delete (guestfs_h *g, char *const *devices, const char *fs);

#define GUESTFS_HAVE_BTRFS_FILESYSTEM_BALANCE 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_filesystem_balance (guestfs_h *g, const char *fs);

#define GUESTFS_HAVE_BTRFS_FILESYSTEM_DEFRAGMENT 1
#define GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH 0
#define GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_filesystem_defragment (guestfs_h *g, const char *path, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_filesystem_defragment_va (guestfs_h *g, const char *path, va_list args);

struct guestfs_btrfs_filesystem_defragment_argv {
  uint64_t bitmask;
# define GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH_BITMASK (UINT64_C(1)<<0)
  int flush;
# define GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS_BITMASK (UINT64_C(1)<<1)
  const char *compress;
};

extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_filesystem_defragment_argv (guestfs_h *g, const char *path, const struct guestfs_btrfs_filesystem_defragment_argv *optargs);

#define GUESTFS_HAVE_BTRFS_FILESYSTEM_RESIZE 1
#define GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE 0
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_filesystem_resize (guestfs_h *g, const char *mountpoint, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_filesystem_resize_va (guestfs_h *g, const char *mountpoint, va_list args);

struct guestfs_btrfs_filesystem_resize_argv {
  uint64_t bitmask;
# define GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK (UINT64_C(1)<<0)
  int64_t size;
};

extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_filesystem_resize_argv (guestfs_h *g, const char *mountpoint, const struct guestfs_btrfs_filesystem_resize_argv *optargs);

#define GUESTFS_HAVE_BTRFS_FILESYSTEM_SHOW 1
extern GUESTFS_DLL_PUBLIC char **guestfs_btrfs_filesystem_show (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BTRFS_FILESYSTEM_SYNC 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_filesystem_sync (guestfs_h *g, const char *fs);

#define GUESTFS_HAVE_BTRFS_FSCK 1
#define GUESTFS_BTRFS_FSCK_SUPERBLOCK 0
#define GUESTFS_BTRFS_FSCK_REPAIR 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_fsck (guestfs_h *g, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_fsck_va (guestfs_h *g, const char *device, va_list args);

struct guestfs_btrfs_fsck_argv {
  uint64_t bitmask;
# define GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK (UINT64_C(1)<<0)
  int64_t superblock;
# define GUESTFS_BTRFS_FSCK_REPAIR_BITMASK (UINT64_C(1)<<1)
  int repair;
};

extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_fsck_argv (guestfs_h *g, const char *device, const struct guestfs_btrfs_fsck_argv *optargs);

#define GUESTFS_HAVE_BTRFS_IMAGE 1
#define GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL 0
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_image (guestfs_h *g, char *const *source, const char *image, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_image_va (guestfs_h *g, char *const *source, const char *image, va_list args);

struct guestfs_btrfs_image_argv {
  uint64_t bitmask;
# define GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL_BITMASK (UINT64_C(1)<<0)
  int compresslevel;
};

extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_image_argv (guestfs_h *g, char *const *source, const char *image, const struct guestfs_btrfs_image_argv *optargs);

#define GUESTFS_HAVE_BTRFS_QGROUP_ASSIGN 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_qgroup_assign (guestfs_h *g, const char *src, const char *dst, const char *path);

#define GUESTFS_HAVE_BTRFS_QGROUP_CREATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_qgroup_create (guestfs_h *g, const char *qgroupid, const char *subvolume);

#define GUESTFS_HAVE_BTRFS_QGROUP_DESTROY 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_qgroup_destroy (guestfs_h *g, const char *qgroupid, const char *subvolume);

#define GUESTFS_HAVE_BTRFS_QGROUP_LIMIT 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_qgroup_limit (guestfs_h *g, const char *subvolume, int64_t size);

#define GUESTFS_HAVE_BTRFS_QGROUP_REMOVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_qgroup_remove (guestfs_h *g, const char *src, const char *dst, const char *path);

#define GUESTFS_HAVE_BTRFS_QGROUP_SHOW 1
extern GUESTFS_DLL_PUBLIC struct guestfs_btrfsqgroup_list *guestfs_btrfs_qgroup_show (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_BTRFS_QUOTA_ENABLE 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_quota_enable (guestfs_h *g, const char *fs, int enable);

#define GUESTFS_HAVE_BTRFS_QUOTA_RESCAN 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_quota_rescan (guestfs_h *g, const char *fs);

#define GUESTFS_HAVE_BTRFS_REPLACE 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_replace (guestfs_h *g, const char *srcdev, const char *targetdev, const char *mntpoint);

#define GUESTFS_HAVE_BTRFS_RESCUE_CHUNK_RECOVER 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_rescue_chunk_recover (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BTRFS_RESCUE_SUPER_RECOVER 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_rescue_super_recover (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BTRFS_SCRUB_CANCEL 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_scrub_cancel (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_BTRFS_SCRUB_RESUME 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_scrub_resume (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_BTRFS_SCRUB_START 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_scrub_start (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_BTRFS_SCRUB_STATUS 1
extern GUESTFS_DLL_PUBLIC struct guestfs_btrfsscrub *guestfs_btrfs_scrub_status (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_BTRFS_SET_SEEDING 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_set_seeding (guestfs_h *g, const char *device, int seeding);

#define GUESTFS_HAVE_BTRFS_SUBVOLUME_CREATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_subvolume_create (guestfs_h *g, const char *dest);

#define GUESTFS_HAVE_BTRFS_SUBVOLUME_CREATE_OPTS 1
#define GUESTFS_BTRFS_SUBVOLUME_CREATE_OPTS_QGROUPID 0
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_subvolume_create_opts (guestfs_h *g, const char *dest, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_subvolume_create_opts_va (guestfs_h *g, const char *dest, va_list args);

struct guestfs_btrfs_subvolume_create_opts_argv {
  uint64_t bitmask;
# define GUESTFS_BTRFS_SUBVOLUME_CREATE_OPTS_QGROUPID_BITMASK (UINT64_C(1)<<0)
  const char *qgroupid;
};

extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_subvolume_create_opts_argv (guestfs_h *g, const char *dest, const struct guestfs_btrfs_subvolume_create_opts_argv *optargs);

#define GUESTFS_HAVE_BTRFS_SUBVOLUME_DELETE 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_subvolume_delete (guestfs_h *g, const char *subvolume);

#define GUESTFS_HAVE_BTRFS_SUBVOLUME_GET_DEFAULT 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_btrfs_subvolume_get_default (guestfs_h *g, const char *fs);

#define GUESTFS_HAVE_BTRFS_SUBVOLUME_LIST 1
extern GUESTFS_DLL_PUBLIC struct guestfs_btrfssubvolume_list *guestfs_btrfs_subvolume_list (guestfs_h *g, const char *fs);

#define GUESTFS_HAVE_BTRFS_SUBVOLUME_SET_DEFAULT 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_subvolume_set_default (guestfs_h *g, int64_t id, const char *fs);

#define GUESTFS_HAVE_BTRFS_SUBVOLUME_SHOW 1
extern GUESTFS_DLL_PUBLIC char **guestfs_btrfs_subvolume_show (guestfs_h *g, const char *subvolume);

#define GUESTFS_HAVE_BTRFS_SUBVOLUME_SNAPSHOT 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_subvolume_snapshot (guestfs_h *g, const char *source, const char *dest);

#define GUESTFS_HAVE_BTRFS_SUBVOLUME_SNAPSHOT_OPTS 1
#define GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_RO 0
#define GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_QGROUPID 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_subvolume_snapshot_opts (guestfs_h *g, const char *source, const char *dest, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_subvolume_snapshot_opts_va (guestfs_h *g, const char *source, const char *dest, va_list args);

struct guestfs_btrfs_subvolume_snapshot_opts_argv {
  uint64_t bitmask;
# define GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_RO_BITMASK (UINT64_C(1)<<0)
  int ro;
# define GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_QGROUPID_BITMASK (UINT64_C(1)<<1)
  const char *qgroupid;
};

extern GUESTFS_DLL_PUBLIC int guestfs_btrfs_subvolume_snapshot_opts_argv (guestfs_h *g, const char *source, const char *dest, const struct guestfs_btrfs_subvolume_snapshot_opts_argv *optargs);

#define GUESTFS_HAVE_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfstune_enable_extended_inode_refs (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfstune_enable_skinny_metadata_extent_refs (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_BTRFSTUNE_SEEDING 1
extern GUESTFS_DLL_PUBLIC int guestfs_btrfstune_seeding (guestfs_h *g, const char *device, int seeding);

#define GUESTFS_HAVE_C_POINTER 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_c_pointer (guestfs_h *g);

#define GUESTFS_HAVE_CANONICAL_DEVICE_NAME 1
extern GUESTFS_DLL_PUBLIC char *guestfs_canonical_device_name (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_CAP_GET_FILE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_cap_get_file (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_CAP_SET_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_cap_set_file (guestfs_h *g, const char *path, const char *cap);

#define GUESTFS_HAVE_CASE_SENSITIVE_PATH 1
extern GUESTFS_DLL_PUBLIC char *guestfs_case_sensitive_path (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_CAT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_cat (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_CHECKSUM 1
extern GUESTFS_DLL_PUBLIC char *guestfs_checksum (guestfs_h *g, const char *csumtype, const char *path);

#define GUESTFS_HAVE_CHECKSUM_DEVICE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_checksum_device (guestfs_h *g, const char *csumtype, const char *device);

#define GUESTFS_HAVE_CHECKSUMS_OUT 1
extern GUESTFS_DLL_PUBLIC int guestfs_checksums_out (guestfs_h *g, const char *csumtype, const char *directory, const char *sumsfile);

#define GUESTFS_HAVE_CHMOD 1
extern GUESTFS_DLL_PUBLIC int guestfs_chmod (guestfs_h *g, int mode, const char *path);

#define GUESTFS_HAVE_CHOWN 1
extern GUESTFS_DLL_PUBLIC int guestfs_chown (guestfs_h *g, int owner, int group, const char *path);

#define GUESTFS_HAVE_CLEAR_BACKEND_SETTING 1
extern GUESTFS_DLL_PUBLIC int guestfs_clear_backend_setting (guestfs_h *g, const char *name);

#define GUESTFS_HAVE_COMMAND 1
extern GUESTFS_DLL_PUBLIC char *guestfs_command (guestfs_h *g, char *const *arguments);

#define GUESTFS_HAVE_COMMAND_LINES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_command_lines (guestfs_h *g, char *const *arguments);

#define GUESTFS_HAVE_COMPRESS_DEVICE_OUT 1
#define GUESTFS_COMPRESS_DEVICE_OUT_LEVEL 0
extern GUESTFS_DLL_PUBLIC int guestfs_compress_device_out (guestfs_h *g, const char *ctype, const char *device, const char *zdevice, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_compress_device_out_va (guestfs_h *g, const char *ctype, const char *device, const char *zdevice, va_list args);

struct guestfs_compress_device_out_argv {
  uint64_t bitmask;
# define GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK (UINT64_C(1)<<0)
  int level;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compress_device_out_argv (guestfs_h *g, const char *ctype, const char *device, const char *zdevice, const struct guestfs_compress_device_out_argv *optargs);

#define GUESTFS_HAVE_COMPRESS_OUT 1
#define GUESTFS_COMPRESS_OUT_LEVEL 0
extern GUESTFS_DLL_PUBLIC int guestfs_compress_out (guestfs_h *g, const char *ctype, const char *file, const char *zfile, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_compress_out_va (guestfs_h *g, const char *ctype, const char *file, const char *zfile, va_list args);

struct guestfs_compress_out_argv {
  uint64_t bitmask;
# define GUESTFS_COMPRESS_OUT_LEVEL_BITMASK (UINT64_C(1)<<0)
  int level;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compress_out_argv (guestfs_h *g, const char *ctype, const char *file, const char *zfile, const struct guestfs_compress_out_argv *optargs);

#define GUESTFS_HAVE_CONFIG 1
extern GUESTFS_DLL_PUBLIC int guestfs_config (guestfs_h *g, const char *hvparam, const char *hvvalue);

#define GUESTFS_HAVE_COPY_ATTRIBUTES 1
#define GUESTFS_COPY_ATTRIBUTES_ALL 0
#define GUESTFS_COPY_ATTRIBUTES_MODE 1
#define GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES 2
#define GUESTFS_COPY_ATTRIBUTES_OWNERSHIP 3
extern GUESTFS_DLL_PUBLIC int guestfs_copy_attributes (guestfs_h *g, const char *src, const char *dest, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_copy_attributes_va (guestfs_h *g, const char *src, const char *dest, va_list args);

struct guestfs_copy_attributes_argv {
  uint64_t bitmask;
# define GUESTFS_COPY_ATTRIBUTES_ALL_BITMASK (UINT64_C(1)<<0)
  int all;
# define GUESTFS_COPY_ATTRIBUTES_MODE_BITMASK (UINT64_C(1)<<1)
  int mode;
# define GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES_BITMASK (UINT64_C(1)<<2)
  int xattributes;
# define GUESTFS_COPY_ATTRIBUTES_OWNERSHIP_BITMASK (UINT64_C(1)<<3)
  int ownership;
};

extern GUESTFS_DLL_PUBLIC int guestfs_copy_attributes_argv (guestfs_h *g, const char *src, const char *dest, const struct guestfs_copy_attributes_argv *optargs);

#define GUESTFS_HAVE_COPY_DEVICE_TO_DEVICE 1
#define GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET 0
#define GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET 1
#define GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE 2
#define GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE 3
#define GUESTFS_COPY_DEVICE_TO_DEVICE_APPEND 4
extern GUESTFS_DLL_PUBLIC int guestfs_copy_device_to_device (guestfs_h *g, const char *src, const char *dest, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_copy_device_to_device_va (guestfs_h *g, const char *src, const char *dest, va_list args);

struct guestfs_copy_device_to_device_argv {
  uint64_t bitmask;
# define GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
  int64_t srcoffset;
# define GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
  int64_t destoffset;
# define GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK (UINT64_C(1)<<2)
  int64_t size;
# define GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK (UINT64_C(1)<<3)
  int sparse;
# define GUESTFS_COPY_DEVICE_TO_DEVICE_APPEND_BITMASK (UINT64_C(1)<<4)
  int append;
};

extern GUESTFS_DLL_PUBLIC int guestfs_copy_device_to_device_argv (guestfs_h *g, const char *src, const char *dest, const struct guestfs_copy_device_to_device_argv *optargs);

#define GUESTFS_HAVE_COPY_DEVICE_TO_FILE 1
#define GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET 0
#define GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET 1
#define GUESTFS_COPY_DEVICE_TO_FILE_SIZE 2
#define GUESTFS_COPY_DEVICE_TO_FILE_SPARSE 3
#define GUESTFS_COPY_DEVICE_TO_FILE_APPEND 4
extern GUESTFS_DLL_PUBLIC int guestfs_copy_device_to_file (guestfs_h *g, const char *src, const char *dest, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_copy_device_to_file_va (guestfs_h *g, const char *src, const char *dest, va_list args);

struct guestfs_copy_device_to_file_argv {
  uint64_t bitmask;
# define GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
  int64_t srcoffset;
# define GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
  int64_t destoffset;
# define GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK (UINT64_C(1)<<2)
  int64_t size;
# define GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK (UINT64_C(1)<<3)
  int sparse;
# define GUESTFS_COPY_DEVICE_TO_FILE_APPEND_BITMASK (UINT64_C(1)<<4)
  int append;
};

extern GUESTFS_DLL_PUBLIC int guestfs_copy_device_to_file_argv (guestfs_h *g, const char *src, const char *dest, const struct guestfs_copy_device_to_file_argv *optargs);

#define GUESTFS_HAVE_COPY_FILE_TO_DEVICE 1
#define GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET 0
#define GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET 1
#define GUESTFS_COPY_FILE_TO_DEVICE_SIZE 2
#define GUESTFS_COPY_FILE_TO_DEVICE_SPARSE 3
#define GUESTFS_COPY_FILE_TO_DEVICE_APPEND 4
extern GUESTFS_DLL_PUBLIC int guestfs_copy_file_to_device (guestfs_h *g, const char *src, const char *dest, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_copy_file_to_device_va (guestfs_h *g, const char *src, const char *dest, va_list args);

struct guestfs_copy_file_to_device_argv {
  uint64_t bitmask;
# define GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
  int64_t srcoffset;
# define GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
  int64_t destoffset;
# define GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK (UINT64_C(1)<<2)
  int64_t size;
# define GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK (UINT64_C(1)<<3)
  int sparse;
# define GUESTFS_COPY_FILE_TO_DEVICE_APPEND_BITMASK (UINT64_C(1)<<4)
  int append;
};

extern GUESTFS_DLL_PUBLIC int guestfs_copy_file_to_device_argv (guestfs_h *g, const char *src, const char *dest, const struct guestfs_copy_file_to_device_argv *optargs);

#define GUESTFS_HAVE_COPY_FILE_TO_FILE 1
#define GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET 0
#define GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET 1
#define GUESTFS_COPY_FILE_TO_FILE_SIZE 2
#define GUESTFS_COPY_FILE_TO_FILE_SPARSE 3
#define GUESTFS_COPY_FILE_TO_FILE_APPEND 4
extern GUESTFS_DLL_PUBLIC int guestfs_copy_file_to_file (guestfs_h *g, const char *src, const char *dest, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_copy_file_to_file_va (guestfs_h *g, const char *src, const char *dest, va_list args);

struct guestfs_copy_file_to_file_argv {
  uint64_t bitmask;
# define GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
  int64_t srcoffset;
# define GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
  int64_t destoffset;
# define GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK (UINT64_C(1)<<2)
  int64_t size;
# define GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK (UINT64_C(1)<<3)
  int sparse;
# define GUESTFS_COPY_FILE_TO_FILE_APPEND_BITMASK (UINT64_C(1)<<4)
  int append;
};

extern GUESTFS_DLL_PUBLIC int guestfs_copy_file_to_file_argv (guestfs_h *g, const char *src, const char *dest, const struct guestfs_copy_file_to_file_argv *optargs);

#define GUESTFS_HAVE_COPY_IN 1
extern GUESTFS_DLL_PUBLIC int guestfs_copy_in (guestfs_h *g, const char *localpath, const char *remotedir);

#define GUESTFS_HAVE_COPY_OUT 1
extern GUESTFS_DLL_PUBLIC int guestfs_copy_out (guestfs_h *g, const char *remotepath, const char *localdir);

#define GUESTFS_HAVE_COPY_SIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_copy_size (guestfs_h *g, const char *src, const char *dest, int64_t size)
  GUESTFS_DEPRECATED_BY ("copy_device_to_device");

#define GUESTFS_HAVE_CP 1
extern GUESTFS_DLL_PUBLIC int guestfs_cp (guestfs_h *g, const char *src, const char *dest);

#define GUESTFS_HAVE_CP_A 1
extern GUESTFS_DLL_PUBLIC int guestfs_cp_a (guestfs_h *g, const char *src, const char *dest);

#define GUESTFS_HAVE_CP_R 1
extern GUESTFS_DLL_PUBLIC int guestfs_cp_r (guestfs_h *g, const char *src, const char *dest);

#define GUESTFS_HAVE_CPIO_OUT 1
#define GUESTFS_CPIO_OUT_FORMAT 0
extern GUESTFS_DLL_PUBLIC int guestfs_cpio_out (guestfs_h *g, const char *directory, const char *cpiofile, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_cpio_out_va (guestfs_h *g, const char *directory, const char *cpiofile, va_list args);

struct guestfs_cpio_out_argv {
  uint64_t bitmask;
# define GUESTFS_CPIO_OUT_FORMAT_BITMASK (UINT64_C(1)<<0)
  const char *format;
};

extern GUESTFS_DLL_PUBLIC int guestfs_cpio_out_argv (guestfs_h *g, const char *directory, const char *cpiofile, const struct guestfs_cpio_out_argv *optargs);

#define GUESTFS_HAVE_DD 1
extern GUESTFS_DLL_PUBLIC int guestfs_dd (guestfs_h *g, const char *src, const char *dest)
  GUESTFS_DEPRECATED_BY ("copy_device_to_device");

#define GUESTFS_HAVE_DEBUG 1
extern GUESTFS_DLL_PUBLIC char *guestfs_debug (guestfs_h *g, const char *subcmd, char *const *extraargs);

#define GUESTFS_HAVE_DEBUG_DRIVES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_debug_drives (guestfs_h *g);

#define GUESTFS_HAVE_DEBUG_UPLOAD 1
extern GUESTFS_DLL_PUBLIC int guestfs_debug_upload (guestfs_h *g, const char *filename, const char *tmpname, int mode);

#define GUESTFS_HAVE_DEVICE_INDEX 1
extern GUESTFS_DLL_PUBLIC int guestfs_device_index (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_DF 1
extern GUESTFS_DLL_PUBLIC char *guestfs_df (guestfs_h *g);

#define GUESTFS_HAVE_DF_H 1
extern GUESTFS_DLL_PUBLIC char *guestfs_df_h (guestfs_h *g);

#define GUESTFS_HAVE_DISK_CREATE 1
#define GUESTFS_DISK_CREATE_BACKINGFILE 0
#define GUESTFS_DISK_CREATE_BACKINGFORMAT 1
#define GUESTFS_DISK_CREATE_PREALLOCATION 2
#define GUESTFS_DISK_CREATE_COMPAT 3
#define GUESTFS_DISK_CREATE_CLUSTERSIZE 4
extern GUESTFS_DLL_PUBLIC int guestfs_disk_create (guestfs_h *g, const char *filename, const char *format, int64_t size, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_disk_create_va (guestfs_h *g, const char *filename, const char *format, int64_t size, va_list args);

struct guestfs_disk_create_argv {
  uint64_t bitmask;
# define GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK (UINT64_C(1)<<0)
  const char *backingfile;
# define GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK (UINT64_C(1)<<1)
  const char *backingformat;
# define GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK (UINT64_C(1)<<2)
  const char *preallocation;
# define GUESTFS_DISK_CREATE_COMPAT_BITMASK (UINT64_C(1)<<3)
  const char *compat;
# define GUESTFS_DISK_CREATE_CLUSTERSIZE_BITMASK (UINT64_C(1)<<4)
  int clustersize;
};

extern GUESTFS_DLL_PUBLIC int guestfs_disk_create_argv (guestfs_h *g, const char *filename, const char *format, int64_t size, const struct guestfs_disk_create_argv *optargs);

#define GUESTFS_HAVE_DISK_FORMAT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_disk_format (guestfs_h *g, const char *filename);

#define GUESTFS_HAVE_DISK_HAS_BACKING_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_disk_has_backing_file (guestfs_h *g, const char *filename);

#define GUESTFS_HAVE_DISK_VIRTUAL_SIZE 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_disk_virtual_size (guestfs_h *g, const char *filename);

#define GUESTFS_HAVE_DMESG 1
extern GUESTFS_DLL_PUBLIC char *guestfs_dmesg (guestfs_h *g);

#define GUESTFS_HAVE_DOWNLOAD 1
extern GUESTFS_DLL_PUBLIC int guestfs_download (guestfs_h *g, const char *remotefilename, const char *filename);

#define GUESTFS_HAVE_DOWNLOAD_BLOCKS 1
#define GUESTFS_DOWNLOAD_BLOCKS_UNALLOCATED 0
extern GUESTFS_DLL_PUBLIC int guestfs_download_blocks (guestfs_h *g, const char *device, int64_t start, int64_t stop, const char *filename, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_download_blocks_va (guestfs_h *g, const char *device, int64_t start, int64_t stop, const char *filename, va_list args);

struct guestfs_download_blocks_argv {
  uint64_t bitmask;
# define GUESTFS_DOWNLOAD_BLOCKS_UNALLOCATED_BITMASK (UINT64_C(1)<<0)
  int unallocated;
};

extern GUESTFS_DLL_PUBLIC int guestfs_download_blocks_argv (guestfs_h *g, const char *device, int64_t start, int64_t stop, const char *filename, const struct guestfs_download_blocks_argv *optargs);

#define GUESTFS_HAVE_DOWNLOAD_INODE 1
extern GUESTFS_DLL_PUBLIC int guestfs_download_inode (guestfs_h *g, const char *device, int64_t inode, const char *filename);

#define GUESTFS_HAVE_DOWNLOAD_OFFSET 1
extern GUESTFS_DLL_PUBLIC int guestfs_download_offset (guestfs_h *g, const char *remotefilename, const char *filename, int64_t offset, int64_t size);

#define GUESTFS_HAVE_DROP_CACHES 1
extern GUESTFS_DLL_PUBLIC int guestfs_drop_caches (guestfs_h *g, int whattodrop);

#define GUESTFS_HAVE_DU 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_du (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_E2FSCK 1
#define GUESTFS_E2FSCK_CORRECT 0
#define GUESTFS_E2FSCK_FORCEALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_e2fsck (guestfs_h *g, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_e2fsck_va (guestfs_h *g, const char *device, va_list args);

struct guestfs_e2fsck_argv {
  uint64_t bitmask;
# define GUESTFS_E2FSCK_CORRECT_BITMASK (UINT64_C(1)<<0)
  int correct;
# define GUESTFS_E2FSCK_FORCEALL_BITMASK (UINT64_C(1)<<1)
  int forceall;
};

extern GUESTFS_DLL_PUBLIC int guestfs_e2fsck_argv (guestfs_h *g, const char *device, const struct guestfs_e2fsck_argv *optargs);

#define GUESTFS_HAVE_E2FSCK_F 1
extern GUESTFS_DLL_PUBLIC int guestfs_e2fsck_f (guestfs_h *g, const char *device)
  GUESTFS_DEPRECATED_BY ("e2fsck");

#define GUESTFS_HAVE_ECHO_DAEMON 1
extern GUESTFS_DLL_PUBLIC char *guestfs_echo_daemon (guestfs_h *g, char *const *words);

#define GUESTFS_HAVE_EGREP 1
extern GUESTFS_DLL_PUBLIC char **guestfs_egrep (guestfs_h *g, const char *regex, const char *path)
  GUESTFS_DEPRECATED_BY ("grep");

#define GUESTFS_HAVE_EGREPI 1
extern GUESTFS_DLL_PUBLIC char **guestfs_egrepi (guestfs_h *g, const char *regex, const char *path)
  GUESTFS_DEPRECATED_BY ("grep");

#define GUESTFS_HAVE_EQUAL 1
extern GUESTFS_DLL_PUBLIC int guestfs_equal (guestfs_h *g, const char *file1, const char *file2);

#define GUESTFS_HAVE_EXISTS 1
extern GUESTFS_DLL_PUBLIC int guestfs_exists (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_EXTLINUX 1
extern GUESTFS_DLL_PUBLIC int guestfs_extlinux (guestfs_h *g, const char *directory);

#define GUESTFS_HAVE_FALLOCATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_fallocate (guestfs_h *g, const char *path, int len)
  GUESTFS_DEPRECATED_BY ("fallocate64");

#define GUESTFS_HAVE_FALLOCATE64 1
extern GUESTFS_DLL_PUBLIC int guestfs_fallocate64 (guestfs_h *g, const char *path, int64_t len);

#define GUESTFS_HAVE_FEATURE_AVAILABLE 1
extern GUESTFS_DLL_PUBLIC int guestfs_feature_available (guestfs_h *g, char *const *groups);

#define GUESTFS_HAVE_FGREP 1
extern GUESTFS_DLL_PUBLIC char **guestfs_fgrep (guestfs_h *g, const char *pattern, const char *path)
  GUESTFS_DEPRECATED_BY ("grep");

#define GUESTFS_HAVE_FGREPI 1
extern GUESTFS_DLL_PUBLIC char **guestfs_fgrepi (guestfs_h *g, const char *pattern, const char *path)
  GUESTFS_DEPRECATED_BY ("grep");

#define GUESTFS_HAVE_FILE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_file (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_FILE_ARCHITECTURE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_file_architecture (guestfs_h *g, const char *filename);

#define GUESTFS_HAVE_FILESIZE 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_filesize (guestfs_h *g, const char *file);

#define GUESTFS_HAVE_FILESYSTEM_AVAILABLE 1
extern GUESTFS_DLL_PUBLIC int guestfs_filesystem_available (guestfs_h *g, const char *filesystem);

#define GUESTFS_HAVE_FILESYSTEM_WALK 1
extern GUESTFS_DLL_PUBLIC struct guestfs_tsk_dirent_list *guestfs_filesystem_walk (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_FILL 1
extern GUESTFS_DLL_PUBLIC int guestfs_fill (guestfs_h *g, int c, int len, const char *path);

#define GUESTFS_HAVE_FILL_DIR 1
extern GUESTFS_DLL_PUBLIC int guestfs_fill_dir (guestfs_h *g, const char *dir, int nr);

#define GUESTFS_HAVE_FILL_PATTERN 1
extern GUESTFS_DLL_PUBLIC int guestfs_fill_pattern (guestfs_h *g, const char *pattern, int len, const char *path);

#define GUESTFS_HAVE_FIND 1
extern GUESTFS_DLL_PUBLIC char **guestfs_find (guestfs_h *g, const char *directory);

#define GUESTFS_HAVE_FIND0 1
extern GUESTFS_DLL_PUBLIC int guestfs_find0 (guestfs_h *g, const char *directory, const char *files);

#define GUESTFS_HAVE_FIND_INODE 1
extern GUESTFS_DLL_PUBLIC struct guestfs_tsk_dirent_list *guestfs_find_inode (guestfs_h *g, const char *device, int64_t inode);

#define GUESTFS_HAVE_FINDFS_LABEL 1
extern GUESTFS_DLL_PUBLIC char *guestfs_findfs_label (guestfs_h *g, const char *label);

#define GUESTFS_HAVE_FINDFS_UUID 1
extern GUESTFS_DLL_PUBLIC char *guestfs_findfs_uuid (guestfs_h *g, const char *uuid);

#define GUESTFS_HAVE_FSCK 1
extern GUESTFS_DLL_PUBLIC int guestfs_fsck (guestfs_h *g, const char *fstype, const char *device);

#define GUESTFS_HAVE_FSTRIM 1
#define GUESTFS_FSTRIM_OFFSET 0
#define GUESTFS_FSTRIM_LENGTH 1
#define GUESTFS_FSTRIM_MINIMUMFREEEXTENT 2
extern GUESTFS_DLL_PUBLIC int guestfs_fstrim (guestfs_h *g, const char *mountpoint, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_fstrim_va (guestfs_h *g, const char *mountpoint, va_list args);

struct guestfs_fstrim_argv {
  uint64_t bitmask;
# define GUESTFS_FSTRIM_OFFSET_BITMASK (UINT64_C(1)<<0)
  int64_t offset;
# define GUESTFS_FSTRIM_LENGTH_BITMASK (UINT64_C(1)<<1)
  int64_t length;
# define GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK (UINT64_C(1)<<2)
  int64_t minimumfreeextent;
};

extern GUESTFS_DLL_PUBLIC int guestfs_fstrim_argv (guestfs_h *g, const char *mountpoint, const struct guestfs_fstrim_argv *optargs);

#define GUESTFS_HAVE_GET_APPEND 1
extern GUESTFS_DLL_PUBLIC const char *guestfs_get_append (guestfs_h *g);

#define GUESTFS_HAVE_GET_ATTACH_METHOD 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_attach_method (guestfs_h *g)
  GUESTFS_DEPRECATED_BY ("get_backend");

#define GUESTFS_HAVE_GET_AUTOSYNC 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_autosync (guestfs_h *g);

#define GUESTFS_HAVE_GET_BACKEND 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_backend (guestfs_h *g);

#define GUESTFS_HAVE_GET_BACKEND_SETTING 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_backend_setting (guestfs_h *g, const char *name);

#define GUESTFS_HAVE_GET_BACKEND_SETTINGS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_get_backend_settings (guestfs_h *g);

#define GUESTFS_HAVE_GET_CACHEDIR 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_cachedir (guestfs_h *g);

#define GUESTFS_HAVE_GET_DIRECT 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_direct (guestfs_h *g);

#define GUESTFS_HAVE_GET_E2ATTRS 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_e2attrs (guestfs_h *g, const char *file);

#define GUESTFS_HAVE_GET_E2GENERATION 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_get_e2generation (guestfs_h *g, const char *file);

#define GUESTFS_HAVE_GET_E2LABEL 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_e2label (guestfs_h *g, const char *device)
  GUESTFS_DEPRECATED_BY ("vfs_label");

#define GUESTFS_HAVE_GET_E2UUID 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_e2uuid (guestfs_h *g, const char *device)
  GUESTFS_DEPRECATED_BY ("vfs_uuid");

#define GUESTFS_HAVE_GET_HV 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_hv (guestfs_h *g);

#define GUESTFS_HAVE_GET_IDENTIFIER 1
extern GUESTFS_DLL_PUBLIC const char *guestfs_get_identifier (guestfs_h *g);

#define GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_CHALLENGE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_libvirt_requested_credential_challenge (guestfs_h *g, int index);

#define GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_DEFRESULT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_libvirt_requested_credential_defresult (guestfs_h *g, int index);

#define GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_PROMPT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_libvirt_requested_credential_prompt (guestfs_h *g, int index);

#define GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIALS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_get_libvirt_requested_credentials (guestfs_h *g);

#define GUESTFS_HAVE_GET_MEMSIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_memsize (guestfs_h *g);

#define GUESTFS_HAVE_GET_NETWORK 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_network (guestfs_h *g);

#define GUESTFS_HAVE_GET_PATH 1
extern GUESTFS_DLL_PUBLIC const char *guestfs_get_path (guestfs_h *g);

#define GUESTFS_HAVE_GET_PGROUP 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_pgroup (guestfs_h *g);

#define GUESTFS_HAVE_GET_PID 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_pid (guestfs_h *g);

#define GUESTFS_HAVE_GET_PROGRAM 1
extern GUESTFS_DLL_PUBLIC const char *guestfs_get_program (guestfs_h *g);

#define GUESTFS_HAVE_GET_QEMU 1
extern GUESTFS_DLL_PUBLIC const char *guestfs_get_qemu (guestfs_h *g)
  GUESTFS_DEPRECATED_BY ("get_hv");

#define GUESTFS_HAVE_GET_RECOVERY_PROC 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_recovery_proc (guestfs_h *g);

#define GUESTFS_HAVE_GET_SELINUX 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_selinux (guestfs_h *g)
  GUESTFS_DEPRECATED_BY ("selinux_relabel");

#define GUESTFS_HAVE_GET_SMP 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_smp (guestfs_h *g);

#define GUESTFS_HAVE_GET_SOCKDIR 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_sockdir (guestfs_h *g);

#define GUESTFS_HAVE_GET_STATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_state (guestfs_h *g);

#define GUESTFS_HAVE_GET_TMPDIR 1
extern GUESTFS_DLL_PUBLIC char *guestfs_get_tmpdir (guestfs_h *g);

#define GUESTFS_HAVE_GET_TRACE 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_trace (guestfs_h *g);

#define GUESTFS_HAVE_GET_UMASK 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_umask (guestfs_h *g);

#define GUESTFS_HAVE_GET_VERBOSE 1
extern GUESTFS_DLL_PUBLIC int guestfs_get_verbose (guestfs_h *g);

#define GUESTFS_HAVE_GETCON 1
extern GUESTFS_DLL_PUBLIC char *guestfs_getcon (guestfs_h *g)
  GUESTFS_DEPRECATED_BY ("selinux_relabel");

#define GUESTFS_HAVE_GETXATTR 1
extern GUESTFS_DLL_PUBLIC char *guestfs_getxattr (guestfs_h *g, const char *path, const char *name, size_t *size_r);

#define GUESTFS_HAVE_GETXATTRS 1
extern GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *guestfs_getxattrs (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_GLOB_EXPAND 1
extern GUESTFS_DLL_PUBLIC char **guestfs_glob_expand (guestfs_h *g, const char *pattern);

#define GUESTFS_HAVE_GLOB_EXPAND_OPTS 1
#define GUESTFS_GLOB_EXPAND_OPTS_DIRECTORYSLASH 0
extern GUESTFS_DLL_PUBLIC char **guestfs_glob_expand_opts (guestfs_h *g, const char *pattern, ...);
extern GUESTFS_DLL_PUBLIC char **guestfs_glob_expand_opts_va (guestfs_h *g, const char *pattern, va_list args);

struct guestfs_glob_expand_opts_argv {
  uint64_t bitmask;
# define GUESTFS_GLOB_EXPAND_OPTS_DIRECTORYSLASH_BITMASK (UINT64_C(1)<<0)
  int directoryslash;
};

extern GUESTFS_DLL_PUBLIC char **guestfs_glob_expand_opts_argv (guestfs_h *g, const char *pattern, const struct guestfs_glob_expand_opts_argv *optargs);

#define GUESTFS_HAVE_GREP 1
extern GUESTFS_DLL_PUBLIC char **guestfs_grep (guestfs_h *g, const char *regex, const char *path);

#define GUESTFS_HAVE_GREP_OPTS 1
#define GUESTFS_GREP_OPTS_EXTENDED 0
#define GUESTFS_GREP_OPTS_FIXED 1
#define GUESTFS_GREP_OPTS_INSENSITIVE 2
#define GUESTFS_GREP_OPTS_COMPRESSED 3
extern GUESTFS_DLL_PUBLIC char **guestfs_grep_opts (guestfs_h *g, const char *regex, const char *path, ...);
extern GUESTFS_DLL_PUBLIC char **guestfs_grep_opts_va (guestfs_h *g, const char *regex, const char *path, va_list args);

struct guestfs_grep_opts_argv {
  uint64_t bitmask;
# define GUESTFS_GREP_OPTS_EXTENDED_BITMASK (UINT64_C(1)<<0)
  int extended;
# define GUESTFS_GREP_OPTS_FIXED_BITMASK (UINT64_C(1)<<1)
  int fixed;
# define GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK (UINT64_C(1)<<2)
  int insensitive;
# define GUESTFS_GREP_OPTS_COMPRESSED_BITMASK (UINT64_C(1)<<3)
  int compressed;
};

extern GUESTFS_DLL_PUBLIC char **guestfs_grep_opts_argv (guestfs_h *g, const char *regex, const char *path, const struct guestfs_grep_opts_argv *optargs);

#define GUESTFS_HAVE_GREPI 1
extern GUESTFS_DLL_PUBLIC char **guestfs_grepi (guestfs_h *g, const char *regex, const char *path)
  GUESTFS_DEPRECATED_BY ("grep");

#define GUESTFS_HAVE_GRUB_INSTALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_grub_install (guestfs_h *g, const char *root, const char *device);

#define GUESTFS_HAVE_HEAD 1
extern GUESTFS_DLL_PUBLIC char **guestfs_head (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_HEAD_N 1
extern GUESTFS_DLL_PUBLIC char **guestfs_head_n (guestfs_h *g, int nrlines, const char *path);

#define GUESTFS_HAVE_HEXDUMP 1
extern GUESTFS_DLL_PUBLIC char *guestfs_hexdump (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_HIVEX_CLOSE 1
extern GUESTFS_DLL_PUBLIC int guestfs_hivex_close (guestfs_h *g);

#define GUESTFS_HAVE_HIVEX_COMMIT 1
extern GUESTFS_DLL_PUBLIC int guestfs_hivex_commit (guestfs_h *g, const char *filename);

#define GUESTFS_HAVE_HIVEX_NODE_ADD_CHILD 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_hivex_node_add_child (guestfs_h *g, int64_t parent, const char *name);

#define GUESTFS_HAVE_HIVEX_NODE_CHILDREN 1
extern GUESTFS_DLL_PUBLIC struct guestfs_hivex_node_list *guestfs_hivex_node_children (guestfs_h *g, int64_t nodeh);

#define GUESTFS_HAVE_HIVEX_NODE_DELETE_CHILD 1
extern GUESTFS_DLL_PUBLIC int guestfs_hivex_node_delete_child (guestfs_h *g, int64_t nodeh);

#define GUESTFS_HAVE_HIVEX_NODE_GET_CHILD 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_hivex_node_get_child (guestfs_h *g, int64_t nodeh, const char *name);

#define GUESTFS_HAVE_HIVEX_NODE_GET_VALUE 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_hivex_node_get_value (guestfs_h *g, int64_t nodeh, const char *key);

#define GUESTFS_HAVE_HIVEX_NODE_NAME 1
extern GUESTFS_DLL_PUBLIC char *guestfs_hivex_node_name (guestfs_h *g, int64_t nodeh);

#define GUESTFS_HAVE_HIVEX_NODE_PARENT 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_hivex_node_parent (guestfs_h *g, int64_t nodeh);

#define GUESTFS_HAVE_HIVEX_NODE_SET_VALUE 1
extern GUESTFS_DLL_PUBLIC int guestfs_hivex_node_set_value (guestfs_h *g, int64_t nodeh, const char *key, int64_t t, const char *val, size_t val_size);

#define GUESTFS_HAVE_HIVEX_NODE_VALUES 1
extern GUESTFS_DLL_PUBLIC struct guestfs_hivex_value_list *guestfs_hivex_node_values (guestfs_h *g, int64_t nodeh);

#define GUESTFS_HAVE_HIVEX_OPEN 1
#define GUESTFS_HIVEX_OPEN_VERBOSE 0
#define GUESTFS_HIVEX_OPEN_DEBUG 1
#define GUESTFS_HIVEX_OPEN_WRITE 2
#define GUESTFS_HIVEX_OPEN_UNSAFE 3
extern GUESTFS_DLL_PUBLIC int guestfs_hivex_open (guestfs_h *g, const char *filename, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_hivex_open_va (guestfs_h *g, const char *filename, va_list args);

struct guestfs_hivex_open_argv {
  uint64_t bitmask;
# define GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK (UINT64_C(1)<<0)
  int verbose;
# define GUESTFS_HIVEX_OPEN_DEBUG_BITMASK (UINT64_C(1)<<1)
  int debug;
# define GUESTFS_HIVEX_OPEN_WRITE_BITMASK (UINT64_C(1)<<2)
  int write;
# define GUESTFS_HIVEX_OPEN_UNSAFE_BITMASK (UINT64_C(1)<<3)
  int unsafe;
};

extern GUESTFS_DLL_PUBLIC int guestfs_hivex_open_argv (guestfs_h *g, const char *filename, const struct guestfs_hivex_open_argv *optargs);

#define GUESTFS_HAVE_HIVEX_ROOT 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_hivex_root (guestfs_h *g);

#define GUESTFS_HAVE_HIVEX_VALUE_KEY 1
extern GUESTFS_DLL_PUBLIC char *guestfs_hivex_value_key (guestfs_h *g, int64_t valueh);

#define GUESTFS_HAVE_HIVEX_VALUE_TYPE 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_hivex_value_type (guestfs_h *g, int64_t valueh);

#define GUESTFS_HAVE_HIVEX_VALUE_UTF8 1
extern GUESTFS_DLL_PUBLIC char *guestfs_hivex_value_utf8 (guestfs_h *g, int64_t valueh);

#define GUESTFS_HAVE_HIVEX_VALUE_VALUE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_hivex_value_value (guestfs_h *g, int64_t valueh, size_t *size_r);

#define GUESTFS_HAVE_INITRD_CAT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_initrd_cat (guestfs_h *g, const char *initrdpath, const char *filename, size_t *size_r);

#define GUESTFS_HAVE_INITRD_LIST 1
extern GUESTFS_DLL_PUBLIC char **guestfs_initrd_list (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_INOTIFY_ADD_WATCH 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_inotify_add_watch (guestfs_h *g, const char *path, int mask);

#define GUESTFS_HAVE_INOTIFY_CLOSE 1
extern GUESTFS_DLL_PUBLIC int guestfs_inotify_close (guestfs_h *g);

#define GUESTFS_HAVE_INOTIFY_FILES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_inotify_files (guestfs_h *g);

#define GUESTFS_HAVE_INOTIFY_INIT 1
extern GUESTFS_DLL_PUBLIC int guestfs_inotify_init (guestfs_h *g, int maxevents);

#define GUESTFS_HAVE_INOTIFY_READ 1
extern GUESTFS_DLL_PUBLIC struct guestfs_inotify_event_list *guestfs_inotify_read (guestfs_h *g);

#define GUESTFS_HAVE_INOTIFY_RM_WATCH 1
extern GUESTFS_DLL_PUBLIC int guestfs_inotify_rm_watch (guestfs_h *g, int wd);

#define GUESTFS_HAVE_INSPECT_GET_ARCH 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_arch (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_DISTRO 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_distro (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_DRIVE_MAPPINGS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_inspect_get_drive_mappings (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_FILESYSTEMS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_inspect_get_filesystems (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_FORMAT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_format (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_HOSTNAME 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_hostname (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_ICON 1
#define GUESTFS_INSPECT_GET_ICON_FAVICON 0
#define GUESTFS_INSPECT_GET_ICON_HIGHQUALITY 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_icon (guestfs_h *g, const char *root, size_t *size_r, ...);
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_icon_va (guestfs_h *g, const char *root, size_t *size_r, va_list args);

struct guestfs_inspect_get_icon_argv {
  uint64_t bitmask;
# define GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK (UINT64_C(1)<<0)
  int favicon;
# define GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK (UINT64_C(1)<<1)
  int highquality;
};

extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_icon_argv (guestfs_h *g, const char *root, size_t *size_r, const struct guestfs_inspect_get_icon_argv *optargs);

#define GUESTFS_HAVE_INSPECT_GET_MAJOR_VERSION 1
extern GUESTFS_DLL_PUBLIC int guestfs_inspect_get_major_version (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_MINOR_VERSION 1
extern GUESTFS_DLL_PUBLIC int guestfs_inspect_get_minor_version (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_MOUNTPOINTS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_inspect_get_mountpoints (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_PACKAGE_FORMAT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_package_format (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_PACKAGE_MANAGEMENT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_package_management (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_PRODUCT_NAME 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_product_name (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_PRODUCT_VARIANT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_product_variant (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_ROOTS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_inspect_get_roots (guestfs_h *g);

#define GUESTFS_HAVE_INSPECT_GET_TYPE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_type (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_WINDOWS_CURRENT_CONTROL_SET 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_windows_current_control_set (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_WINDOWS_SOFTWARE_HIVE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_windows_software_hive (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_WINDOWS_SYSTEM_HIVE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_windows_system_hive (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_GET_WINDOWS_SYSTEMROOT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_inspect_get_windows_systemroot (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_IS_LIVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_inspect_is_live (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_IS_MULTIPART 1
extern GUESTFS_DLL_PUBLIC int guestfs_inspect_is_multipart (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_IS_NETINST 1
extern GUESTFS_DLL_PUBLIC int guestfs_inspect_is_netinst (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_LIST_APPLICATIONS 1
extern GUESTFS_DLL_PUBLIC struct guestfs_application_list *guestfs_inspect_list_applications (guestfs_h *g, const char *root)
  GUESTFS_DEPRECATED_BY ("inspect_list_applications2");

#define GUESTFS_HAVE_INSPECT_LIST_APPLICATIONS2 1
extern GUESTFS_DLL_PUBLIC struct guestfs_application2_list *guestfs_inspect_list_applications2 (guestfs_h *g, const char *root);

#define GUESTFS_HAVE_INSPECT_OS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_inspect_os (guestfs_h *g);

#define GUESTFS_HAVE_INTERNAL_EXIT 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_exit (guestfs_h *g);

#define GUESTFS_HAVE_IS_BLOCKDEV 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_blockdev (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_IS_BLOCKDEV_OPTS 1
#define GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS 0
extern GUESTFS_DLL_PUBLIC int guestfs_is_blockdev_opts (guestfs_h *g, const char *path, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_is_blockdev_opts_va (guestfs_h *g, const char *path, va_list args);

struct guestfs_is_blockdev_opts_argv {
  uint64_t bitmask;
# define GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS_BITMASK (UINT64_C(1)<<0)
  int followsymlinks;
};

extern GUESTFS_DLL_PUBLIC int guestfs_is_blockdev_opts_argv (guestfs_h *g, const char *path, const struct guestfs_is_blockdev_opts_argv *optargs);

#define GUESTFS_HAVE_IS_BUSY 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_busy (guestfs_h *g);

#define GUESTFS_HAVE_IS_CHARDEV 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_chardev (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_IS_CHARDEV_OPTS 1
#define GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS 0
extern GUESTFS_DLL_PUBLIC int guestfs_is_chardev_opts (guestfs_h *g, const char *path, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_is_chardev_opts_va (guestfs_h *g, const char *path, va_list args);

struct guestfs_is_chardev_opts_argv {
  uint64_t bitmask;
# define GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS_BITMASK (UINT64_C(1)<<0)
  int followsymlinks;
};

extern GUESTFS_DLL_PUBLIC int guestfs_is_chardev_opts_argv (guestfs_h *g, const char *path, const struct guestfs_is_chardev_opts_argv *optargs);

#define GUESTFS_HAVE_IS_CONFIG 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_config (guestfs_h *g);

#define GUESTFS_HAVE_IS_DIR 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_dir (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_IS_DIR_OPTS 1
#define GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS 0
extern GUESTFS_DLL_PUBLIC int guestfs_is_dir_opts (guestfs_h *g, const char *path, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_is_dir_opts_va (guestfs_h *g, const char *path, va_list args);

struct guestfs_is_dir_opts_argv {
  uint64_t bitmask;
# define GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS_BITMASK (UINT64_C(1)<<0)
  int followsymlinks;
};

extern GUESTFS_DLL_PUBLIC int guestfs_is_dir_opts_argv (guestfs_h *g, const char *path, const struct guestfs_is_dir_opts_argv *optargs);

#define GUESTFS_HAVE_IS_FIFO 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_fifo (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_IS_FIFO_OPTS 1
#define GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS 0
extern GUESTFS_DLL_PUBLIC int guestfs_is_fifo_opts (guestfs_h *g, const char *path, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_is_fifo_opts_va (guestfs_h *g, const char *path, va_list args);

struct guestfs_is_fifo_opts_argv {
  uint64_t bitmask;
# define GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS_BITMASK (UINT64_C(1)<<0)
  int followsymlinks;
};

extern GUESTFS_DLL_PUBLIC int guestfs_is_fifo_opts_argv (guestfs_h *g, const char *path, const struct guestfs_is_fifo_opts_argv *optargs);

#define GUESTFS_HAVE_IS_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_file (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_IS_FILE_OPTS 1
#define GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS 0
extern GUESTFS_DLL_PUBLIC int guestfs_is_file_opts (guestfs_h *g, const char *path, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_is_file_opts_va (guestfs_h *g, const char *path, va_list args);

struct guestfs_is_file_opts_argv {
  uint64_t bitmask;
# define GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS_BITMASK (UINT64_C(1)<<0)
  int followsymlinks;
};

extern GUESTFS_DLL_PUBLIC int guestfs_is_file_opts_argv (guestfs_h *g, const char *path, const struct guestfs_is_file_opts_argv *optargs);

#define GUESTFS_HAVE_IS_LAUNCHING 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_launching (guestfs_h *g);

#define GUESTFS_HAVE_IS_LV 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_lv (guestfs_h *g, const char *mountable);

#define GUESTFS_HAVE_IS_READY 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_ready (guestfs_h *g);

#define GUESTFS_HAVE_IS_SOCKET 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_socket (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_IS_SOCKET_OPTS 1
#define GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS 0
extern GUESTFS_DLL_PUBLIC int guestfs_is_socket_opts (guestfs_h *g, const char *path, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_is_socket_opts_va (guestfs_h *g, const char *path, va_list args);

struct guestfs_is_socket_opts_argv {
  uint64_t bitmask;
# define GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS_BITMASK (UINT64_C(1)<<0)
  int followsymlinks;
};

extern GUESTFS_DLL_PUBLIC int guestfs_is_socket_opts_argv (guestfs_h *g, const char *path, const struct guestfs_is_socket_opts_argv *optargs);

#define GUESTFS_HAVE_IS_SYMLINK 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_symlink (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_IS_WHOLE_DEVICE 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_whole_device (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_IS_ZERO 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_zero (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_IS_ZERO_DEVICE 1
extern GUESTFS_DLL_PUBLIC int guestfs_is_zero_device (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_ISOINFO 1
extern GUESTFS_DLL_PUBLIC struct guestfs_isoinfo *guestfs_isoinfo (guestfs_h *g, const char *isofile);

#define GUESTFS_HAVE_ISOINFO_DEVICE 1
extern GUESTFS_DLL_PUBLIC struct guestfs_isoinfo *guestfs_isoinfo_device (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_JOURNAL_CLOSE 1
extern GUESTFS_DLL_PUBLIC int guestfs_journal_close (guestfs_h *g);

#define GUESTFS_HAVE_JOURNAL_GET 1
extern GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *guestfs_journal_get (guestfs_h *g);

#define GUESTFS_HAVE_JOURNAL_GET_DATA_THRESHOLD 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_journal_get_data_threshold (guestfs_h *g);

#define GUESTFS_HAVE_JOURNAL_GET_REALTIME_USEC 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_journal_get_realtime_usec (guestfs_h *g);

#define GUESTFS_HAVE_JOURNAL_NEXT 1
extern GUESTFS_DLL_PUBLIC int guestfs_journal_next (guestfs_h *g);

#define GUESTFS_HAVE_JOURNAL_OPEN 1
extern GUESTFS_DLL_PUBLIC int guestfs_journal_open (guestfs_h *g, const char *directory);

#define GUESTFS_HAVE_JOURNAL_SET_DATA_THRESHOLD 1
extern GUESTFS_DLL_PUBLIC int guestfs_journal_set_data_threshold (guestfs_h *g, int64_t threshold);

#define GUESTFS_HAVE_JOURNAL_SKIP 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_journal_skip (guestfs_h *g, int64_t skip);

#define GUESTFS_HAVE_KILL_SUBPROCESS 1
extern GUESTFS_DLL_PUBLIC int guestfs_kill_subprocess (guestfs_h *g)
  GUESTFS_DEPRECATED_BY ("shutdown");

#define GUESTFS_HAVE_LAUNCH 1
extern GUESTFS_DLL_PUBLIC int guestfs_launch (guestfs_h *g);

#define GUESTFS_HAVE_LCHOWN 1
extern GUESTFS_DLL_PUBLIC int guestfs_lchown (guestfs_h *g, int owner, int group, const char *path);

#define GUESTFS_HAVE_LDMTOOL_CREATE_ALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_ldmtool_create_all (guestfs_h *g);

#define GUESTFS_HAVE_LDMTOOL_DISKGROUP_DISKS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_ldmtool_diskgroup_disks (guestfs_h *g, const char *diskgroup);

#define GUESTFS_HAVE_LDMTOOL_DISKGROUP_NAME 1
extern GUESTFS_DLL_PUBLIC char *guestfs_ldmtool_diskgroup_name (guestfs_h *g, const char *diskgroup);

#define GUESTFS_HAVE_LDMTOOL_DISKGROUP_VOLUMES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_ldmtool_diskgroup_volumes (guestfs_h *g, const char *diskgroup);

#define GUESTFS_HAVE_LDMTOOL_REMOVE_ALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_ldmtool_remove_all (guestfs_h *g);

#define GUESTFS_HAVE_LDMTOOL_SCAN 1
extern GUESTFS_DLL_PUBLIC char **guestfs_ldmtool_scan (guestfs_h *g);

#define GUESTFS_HAVE_LDMTOOL_SCAN_DEVICES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_ldmtool_scan_devices (guestfs_h *g, char *const *devices);

#define GUESTFS_HAVE_LDMTOOL_VOLUME_HINT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_ldmtool_volume_hint (guestfs_h *g, const char *diskgroup, const char *volume);

#define GUESTFS_HAVE_LDMTOOL_VOLUME_PARTITIONS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_ldmtool_volume_partitions (guestfs_h *g, const char *diskgroup, const char *volume);

#define GUESTFS_HAVE_LDMTOOL_VOLUME_TYPE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_ldmtool_volume_type (guestfs_h *g, const char *diskgroup, const char *volume);

#define GUESTFS_HAVE_LGETXATTR 1
extern GUESTFS_DLL_PUBLIC char *guestfs_lgetxattr (guestfs_h *g, const char *path, const char *name, size_t *size_r);

#define GUESTFS_HAVE_LGETXATTRS 1
extern GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *guestfs_lgetxattrs (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_LIST_9P 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_9p (guestfs_h *g);

#define GUESTFS_HAVE_LIST_DEVICES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_devices (guestfs_h *g);

#define GUESTFS_HAVE_LIST_DISK_LABELS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_disk_labels (guestfs_h *g);

#define GUESTFS_HAVE_LIST_DM_DEVICES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_dm_devices (guestfs_h *g);

#define GUESTFS_HAVE_LIST_FILESYSTEMS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_filesystems (guestfs_h *g);

#define GUESTFS_HAVE_LIST_LDM_PARTITIONS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_ldm_partitions (guestfs_h *g);

#define GUESTFS_HAVE_LIST_LDM_VOLUMES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_ldm_volumes (guestfs_h *g);

#define GUESTFS_HAVE_LIST_MD_DEVICES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_md_devices (guestfs_h *g);

#define GUESTFS_HAVE_LIST_PARTITIONS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_list_partitions (guestfs_h *g);

#define GUESTFS_HAVE_LL 1
extern GUESTFS_DLL_PUBLIC char *guestfs_ll (guestfs_h *g, const char *directory);

#define GUESTFS_HAVE_LLZ 1
extern GUESTFS_DLL_PUBLIC char *guestfs_llz (guestfs_h *g, const char *directory)
  GUESTFS_DEPRECATED_BY ("lgetxattrs");

#define GUESTFS_HAVE_LN 1
extern GUESTFS_DLL_PUBLIC int guestfs_ln (guestfs_h *g, const char *target, const char *linkname);

#define GUESTFS_HAVE_LN_F 1
extern GUESTFS_DLL_PUBLIC int guestfs_ln_f (guestfs_h *g, const char *target, const char *linkname);

#define GUESTFS_HAVE_LN_S 1
extern GUESTFS_DLL_PUBLIC int guestfs_ln_s (guestfs_h *g, const char *target, const char *linkname);

#define GUESTFS_HAVE_LN_SF 1
extern GUESTFS_DLL_PUBLIC int guestfs_ln_sf (guestfs_h *g, const char *target, const char *linkname);

#define GUESTFS_HAVE_LREMOVEXATTR 1
extern GUESTFS_DLL_PUBLIC int guestfs_lremovexattr (guestfs_h *g, const char *xattr, const char *path);

#define GUESTFS_HAVE_LS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_ls (guestfs_h *g, const char *directory);

#define GUESTFS_HAVE_LS0 1
extern GUESTFS_DLL_PUBLIC int guestfs_ls0 (guestfs_h *g, const char *dir, const char *filenames);

#define GUESTFS_HAVE_LSETXATTR 1
extern GUESTFS_DLL_PUBLIC int guestfs_lsetxattr (guestfs_h *g, const char *xattr, const char *val, int vallen, const char *path);

#define GUESTFS_HAVE_LSTAT 1
extern GUESTFS_DLL_PUBLIC struct guestfs_stat *guestfs_lstat (guestfs_h *g, const char *path)
  GUESTFS_DEPRECATED_BY ("lstatns");

#define GUESTFS_HAVE_LSTATLIST 1
extern GUESTFS_DLL_PUBLIC struct guestfs_stat_list *guestfs_lstatlist (guestfs_h *g, const char *path, char *const *names)
  GUESTFS_DEPRECATED_BY ("lstatnslist");

#define GUESTFS_HAVE_LSTATNS 1
extern GUESTFS_DLL_PUBLIC struct guestfs_statns *guestfs_lstatns (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_LSTATNSLIST 1
extern GUESTFS_DLL_PUBLIC struct guestfs_statns_list *guestfs_lstatnslist (guestfs_h *g, const char *path, char *const *names);

#define GUESTFS_HAVE_LUKS_ADD_KEY 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_add_key (guestfs_h *g, const char *device, const char *key, const char *newkey, int keyslot);

#define GUESTFS_HAVE_LUKS_CLOSE 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_close (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_LUKS_FORMAT 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_format (guestfs_h *g, const char *device, const char *key, int keyslot);

#define GUESTFS_HAVE_LUKS_FORMAT_CIPHER 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_format_cipher (guestfs_h *g, const char *device, const char *key, int keyslot, const char *cipher);

#define GUESTFS_HAVE_LUKS_KILL_SLOT 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_kill_slot (guestfs_h *g, const char *device, const char *key, int keyslot);

#define GUESTFS_HAVE_LUKS_OPEN 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_open (guestfs_h *g, const char *device, const char *key, const char *mapname);

#define GUESTFS_HAVE_LUKS_OPEN_RO 1
extern GUESTFS_DLL_PUBLIC int guestfs_luks_open_ro (guestfs_h *g, const char *device, const char *key, const char *mapname);

#define GUESTFS_HAVE_LVCREATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvcreate (guestfs_h *g, const char *logvol, const char *volgroup, int mbytes);

#define GUESTFS_HAVE_LVCREATE_FREE 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvcreate_free (guestfs_h *g, const char *logvol, const char *volgroup, int percent);

#define GUESTFS_HAVE_LVM_CANONICAL_LV_NAME 1
extern GUESTFS_DLL_PUBLIC char *guestfs_lvm_canonical_lv_name (guestfs_h *g, const char *lvname);

#define GUESTFS_HAVE_LVM_CLEAR_FILTER 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvm_clear_filter (guestfs_h *g);

#define GUESTFS_HAVE_LVM_REMOVE_ALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvm_remove_all (guestfs_h *g);

#define GUESTFS_HAVE_LVM_SET_FILTER 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvm_set_filter (guestfs_h *g, char *const *devices);

#define GUESTFS_HAVE_LVREMOVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvremove (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_LVRENAME 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvrename (guestfs_h *g, const char *logvol, const char *newlogvol);

#define GUESTFS_HAVE_LVRESIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvresize (guestfs_h *g, const char *device, int mbytes);

#define GUESTFS_HAVE_LVRESIZE_FREE 1
extern GUESTFS_DLL_PUBLIC int guestfs_lvresize_free (guestfs_h *g, const char *lv, int percent);

#define GUESTFS_HAVE_LVS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_lvs (guestfs_h *g);

#define GUESTFS_HAVE_LVS_FULL 1
extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_lv_list *guestfs_lvs_full (guestfs_h *g);

#define GUESTFS_HAVE_LVUUID 1
extern GUESTFS_DLL_PUBLIC char *guestfs_lvuuid (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_LXATTRLIST 1
extern GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *guestfs_lxattrlist (guestfs_h *g, const char *path, char *const *names);

#define GUESTFS_HAVE_MAX_DISKS 1
extern GUESTFS_DLL_PUBLIC int guestfs_max_disks (guestfs_h *g);

#define GUESTFS_HAVE_MD_CREATE 1
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
  int64_t missingbitmap;
# define GUESTFS_MD_CREATE_NRDEVICES_BITMASK (UINT64_C(1)<<1)
  int nrdevices;
# define GUESTFS_MD_CREATE_SPARE_BITMASK (UINT64_C(1)<<2)
  int spare;
# define GUESTFS_MD_CREATE_CHUNK_BITMASK (UINT64_C(1)<<3)
  int64_t chunk;
# define GUESTFS_MD_CREATE_LEVEL_BITMASK (UINT64_C(1)<<4)
  const char *level;
};

extern GUESTFS_DLL_PUBLIC int guestfs_md_create_argv (guestfs_h *g, const char *name, char *const *devices, const struct guestfs_md_create_argv *optargs);

#define GUESTFS_HAVE_MD_DETAIL 1
extern GUESTFS_DLL_PUBLIC char **guestfs_md_detail (guestfs_h *g, const char *md);

#define GUESTFS_HAVE_MD_STAT 1
extern GUESTFS_DLL_PUBLIC struct guestfs_mdstat_list *guestfs_md_stat (guestfs_h *g, const char *md);

#define GUESTFS_HAVE_MD_STOP 1
extern GUESTFS_DLL_PUBLIC int guestfs_md_stop (guestfs_h *g, const char *md);

#define GUESTFS_HAVE_MKDIR 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkdir (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_MKDIR_MODE 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkdir_mode (guestfs_h *g, const char *path, int mode);

#define GUESTFS_HAVE_MKDIR_P 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkdir_p (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_MKDTEMP 1
extern GUESTFS_DLL_PUBLIC char *guestfs_mkdtemp (guestfs_h *g, const char *tmpl);

#define GUESTFS_HAVE_MKE2FS 1
#define GUESTFS_MKE2FS_BLOCKSCOUNT 0
#define GUESTFS_MKE2FS_BLOCKSIZE 1
#define GUESTFS_MKE2FS_FRAGSIZE 2
#define GUESTFS_MKE2FS_BLOCKSPERGROUP 3
#define GUESTFS_MKE2FS_NUMBEROFGROUPS 4
#define GUESTFS_MKE2FS_BYTESPERINODE 5
#define GUESTFS_MKE2FS_INODESIZE 6
#define GUESTFS_MKE2FS_JOURNALSIZE 7
#define GUESTFS_MKE2FS_NUMBEROFINODES 8
#define GUESTFS_MKE2FS_STRIDESIZE 9
#define GUESTFS_MKE2FS_STRIPEWIDTH 10
#define GUESTFS_MKE2FS_MAXONLINERESIZE 11
#define GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE 12
#define GUESTFS_MKE2FS_MMPUPDATEINTERVAL 13
#define GUESTFS_MKE2FS_JOURNALDEVICE 14
#define GUESTFS_MKE2FS_LABEL 15
#define GUESTFS_MKE2FS_LASTMOUNTEDDIR 16
#define GUESTFS_MKE2FS_CREATOROS 17
#define GUESTFS_MKE2FS_FSTYPE 18
#define GUESTFS_MKE2FS_USAGETYPE 19
#define GUESTFS_MKE2FS_UUID 20
#define GUESTFS_MKE2FS_FORCECREATE 21
#define GUESTFS_MKE2FS_WRITESBANDGROUPONLY 22
#define GUESTFS_MKE2FS_LAZYITABLEINIT 23
#define GUESTFS_MKE2FS_LAZYJOURNALINIT 24
#define GUESTFS_MKE2FS_TESTFS 25
#define GUESTFS_MKE2FS_DISCARD 26
#define GUESTFS_MKE2FS_QUOTATYPE 27
#define GUESTFS_MKE2FS_EXTENT 28
#define GUESTFS_MKE2FS_FILETYPE 29
#define GUESTFS_MKE2FS_FLEXBG 30
#define GUESTFS_MKE2FS_HASJOURNAL 31
#define GUESTFS_MKE2FS_JOURNALDEV 32
#define GUESTFS_MKE2FS_LARGEFILE 33
#define GUESTFS_MKE2FS_QUOTA 34
#define GUESTFS_MKE2FS_RESIZEINODE 35
#define GUESTFS_MKE2FS_SPARSESUPER 36
#define GUESTFS_MKE2FS_UNINITBG 37
extern GUESTFS_DLL_PUBLIC int guestfs_mke2fs (guestfs_h *g, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_mke2fs_va (guestfs_h *g, const char *device, va_list args);

struct guestfs_mke2fs_argv {
  uint64_t bitmask;
# define GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK (UINT64_C(1)<<0)
  int64_t blockscount;
# define GUESTFS_MKE2FS_BLOCKSIZE_BITMASK (UINT64_C(1)<<1)
  int64_t blocksize;
# define GUESTFS_MKE2FS_FRAGSIZE_BITMASK (UINT64_C(1)<<2)
  int64_t fragsize;
# define GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK (UINT64_C(1)<<3)
  int64_t blockspergroup;
# define GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK (UINT64_C(1)<<4)
  int64_t numberofgroups;
# define GUESTFS_MKE2FS_BYTESPERINODE_BITMASK (UINT64_C(1)<<5)
  int64_t bytesperinode;
# define GUESTFS_MKE2FS_INODESIZE_BITMASK (UINT64_C(1)<<6)
  int64_t inodesize;
# define GUESTFS_MKE2FS_JOURNALSIZE_BITMASK (UINT64_C(1)<<7)
  int64_t journalsize;
# define GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK (UINT64_C(1)<<8)
  int64_t numberofinodes;
# define GUESTFS_MKE2FS_STRIDESIZE_BITMASK (UINT64_C(1)<<9)
  int64_t stridesize;
# define GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK (UINT64_C(1)<<10)
  int64_t stripewidth;
# define GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK (UINT64_C(1)<<11)
  int64_t maxonlineresize;
# define GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK (UINT64_C(1)<<12)
  int reservedblockspercentage;
# define GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK (UINT64_C(1)<<13)
  int mmpupdateinterval;
# define GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK (UINT64_C(1)<<14)
  const char *journaldevice;
# define GUESTFS_MKE2FS_LABEL_BITMASK (UINT64_C(1)<<15)
  const char *label;
# define GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK (UINT64_C(1)<<16)
  const char *lastmounteddir;
# define GUESTFS_MKE2FS_CREATOROS_BITMASK (UINT64_C(1)<<17)
  const char *creatoros;
# define GUESTFS_MKE2FS_FSTYPE_BITMASK (UINT64_C(1)<<18)
  const char *fstype;
# define GUESTFS_MKE2FS_USAGETYPE_BITMASK (UINT64_C(1)<<19)
  const char *usagetype;
# define GUESTFS_MKE2FS_UUID_BITMASK (UINT64_C(1)<<20)
  const char *uuid;
# define GUESTFS_MKE2FS_FORCECREATE_BITMASK (UINT64_C(1)<<21)
  int forcecreate;
# define GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK (UINT64_C(1)<<22)
  int writesbandgrouponly;
# define GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK (UINT64_C(1)<<23)
  int lazyitableinit;
# define GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK (UINT64_C(1)<<24)
  int lazyjournalinit;
# define GUESTFS_MKE2FS_TESTFS_BITMASK (UINT64_C(1)<<25)
  int testfs;
# define GUESTFS_MKE2FS_DISCARD_BITMASK (UINT64_C(1)<<26)
  int discard;
# define GUESTFS_MKE2FS_QUOTATYPE_BITMASK (UINT64_C(1)<<27)
  int quotatype;
# define GUESTFS_MKE2FS_EXTENT_BITMASK (UINT64_C(1)<<28)
  int extent;
# define GUESTFS_MKE2FS_FILETYPE_BITMASK (UINT64_C(1)<<29)
  int filetype;
# define GUESTFS_MKE2FS_FLEXBG_BITMASK (UINT64_C(1)<<30)
  int flexbg;
# define GUESTFS_MKE2FS_HASJOURNAL_BITMASK (UINT64_C(1)<<31)
  int hasjournal;
# define GUESTFS_MKE2FS_JOURNALDEV_BITMASK (UINT64_C(1)<<32)
  int journaldev;
# define GUESTFS_MKE2FS_LARGEFILE_BITMASK (UINT64_C(1)<<33)
  int largefile;
# define GUESTFS_MKE2FS_QUOTA_BITMASK (UINT64_C(1)<<34)
  int quota;
# define GUESTFS_MKE2FS_RESIZEINODE_BITMASK (UINT64_C(1)<<35)
  int resizeinode;
# define GUESTFS_MKE2FS_SPARSESUPER_BITMASK (UINT64_C(1)<<36)
  int sparsesuper;
# define GUESTFS_MKE2FS_UNINITBG_BITMASK (UINT64_C(1)<<37)
  int uninitbg;
};

extern GUESTFS_DLL_PUBLIC int guestfs_mke2fs_argv (guestfs_h *g, const char *device, const struct guestfs_mke2fs_argv *optargs);

#define GUESTFS_HAVE_MKE2FS_J 1
extern GUESTFS_DLL_PUBLIC int guestfs_mke2fs_J (guestfs_h *g, const char *fstype, int blocksize, const char *device, const char *journal)
  GUESTFS_DEPRECATED_BY ("mke2fs");

#define GUESTFS_HAVE_MKE2FS_JL 1
extern GUESTFS_DLL_PUBLIC int guestfs_mke2fs_JL (guestfs_h *g, const char *fstype, int blocksize, const char *device, const char *label)
  GUESTFS_DEPRECATED_BY ("mke2fs");

#define GUESTFS_HAVE_MKE2FS_JU 1
extern GUESTFS_DLL_PUBLIC int guestfs_mke2fs_JU (guestfs_h *g, const char *fstype, int blocksize, const char *device, const char *uuid)
  GUESTFS_DEPRECATED_BY ("mke2fs");

#define GUESTFS_HAVE_MKE2JOURNAL 1
extern GUESTFS_DLL_PUBLIC int guestfs_mke2journal (guestfs_h *g, int blocksize, const char *device)
  GUESTFS_DEPRECATED_BY ("mke2fs");

#define GUESTFS_HAVE_MKE2JOURNAL_L 1
extern GUESTFS_DLL_PUBLIC int guestfs_mke2journal_L (guestfs_h *g, int blocksize, const char *label, const char *device)
  GUESTFS_DEPRECATED_BY ("mke2fs");

#define GUESTFS_HAVE_MKE2JOURNAL_U 1
extern GUESTFS_DLL_PUBLIC int guestfs_mke2journal_U (guestfs_h *g, int blocksize, const char *uuid, const char *device)
  GUESTFS_DEPRECATED_BY ("mke2fs");

#define GUESTFS_HAVE_MKFIFO 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkfifo (guestfs_h *g, int mode, const char *path);

#define GUESTFS_HAVE_MKFS 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkfs (guestfs_h *g, const char *fstype, const char *device);

#define GUESTFS_HAVE_MKFS_OPTS 1
#define GUESTFS_MKFS_OPTS_BLOCKSIZE 0
#define GUESTFS_MKFS_OPTS_FEATURES 1
#define GUESTFS_MKFS_OPTS_INODE 2
#define GUESTFS_MKFS_OPTS_SECTORSIZE 3
#define GUESTFS_MKFS_OPTS_LABEL 4
extern GUESTFS_DLL_PUBLIC int guestfs_mkfs_opts (guestfs_h *g, const char *fstype, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_mkfs_opts_va (guestfs_h *g, const char *fstype, const char *device, va_list args);

struct guestfs_mkfs_opts_argv {
  uint64_t bitmask;
# define GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK (UINT64_C(1)<<0)
  int blocksize;
# define GUESTFS_MKFS_OPTS_FEATURES_BITMASK (UINT64_C(1)<<1)
  const char *features;
# define GUESTFS_MKFS_OPTS_INODE_BITMASK (UINT64_C(1)<<2)
  int inode;
# define GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK (UINT64_C(1)<<3)
  int sectorsize;
# define GUESTFS_MKFS_OPTS_LABEL_BITMASK (UINT64_C(1)<<4)
  const char *label;
};

extern GUESTFS_DLL_PUBLIC int guestfs_mkfs_opts_argv (guestfs_h *g, const char *fstype, const char *device, const struct guestfs_mkfs_opts_argv *optargs);

#define GUESTFS_HAVE_MKFS_B 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkfs_b (guestfs_h *g, const char *fstype, int blocksize, const char *device)
  GUESTFS_DEPRECATED_BY ("mkfs");

#define GUESTFS_HAVE_MKFS_BTRFS 1
#define GUESTFS_MKFS_BTRFS_ALLOCSTART 0
#define GUESTFS_MKFS_BTRFS_BYTECOUNT 1
#define GUESTFS_MKFS_BTRFS_DATATYPE 2
#define GUESTFS_MKFS_BTRFS_LEAFSIZE 3
#define GUESTFS_MKFS_BTRFS_LABEL 4
#define GUESTFS_MKFS_BTRFS_METADATA 5
#define GUESTFS_MKFS_BTRFS_NODESIZE 6
#define GUESTFS_MKFS_BTRFS_SECTORSIZE 7
extern GUESTFS_DLL_PUBLIC int guestfs_mkfs_btrfs (guestfs_h *g, char *const *devices, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_mkfs_btrfs_va (guestfs_h *g, char *const *devices, va_list args);

struct guestfs_mkfs_btrfs_argv {
  uint64_t bitmask;
# define GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK (UINT64_C(1)<<0)
  int64_t allocstart;
# define GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK (UINT64_C(1)<<1)
  int64_t bytecount;
# define GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK (UINT64_C(1)<<2)
  const char *datatype;
# define GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK (UINT64_C(1)<<3)
  int leafsize;
# define GUESTFS_MKFS_BTRFS_LABEL_BITMASK (UINT64_C(1)<<4)
  const char *label;
# define GUESTFS_MKFS_BTRFS_METADATA_BITMASK (UINT64_C(1)<<5)
  const char *metadata;
# define GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK (UINT64_C(1)<<6)
  int nodesize;
# define GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK (UINT64_C(1)<<7)
  int sectorsize;
};

extern GUESTFS_DLL_PUBLIC int guestfs_mkfs_btrfs_argv (guestfs_h *g, char *const *devices, const struct guestfs_mkfs_btrfs_argv *optargs);

#define GUESTFS_HAVE_MKLOST_AND_FOUND 1
extern GUESTFS_DLL_PUBLIC int guestfs_mklost_and_found (guestfs_h *g, const char *mountpoint);

#define GUESTFS_HAVE_MKMOUNTPOINT 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkmountpoint (guestfs_h *g, const char *exemptpath);

#define GUESTFS_HAVE_MKNOD 1
extern GUESTFS_DLL_PUBLIC int guestfs_mknod (guestfs_h *g, int mode, int devmajor, int devminor, const char *path);

#define GUESTFS_HAVE_MKNOD_B 1
extern GUESTFS_DLL_PUBLIC int guestfs_mknod_b (guestfs_h *g, int mode, int devmajor, int devminor, const char *path);

#define GUESTFS_HAVE_MKNOD_C 1
extern GUESTFS_DLL_PUBLIC int guestfs_mknod_c (guestfs_h *g, int mode, int devmajor, int devminor, const char *path);

#define GUESTFS_HAVE_MKSQUASHFS 1
#define GUESTFS_MKSQUASHFS_COMPRESS 0
#define GUESTFS_MKSQUASHFS_EXCLUDES 1
extern GUESTFS_DLL_PUBLIC int guestfs_mksquashfs (guestfs_h *g, const char *path, const char *filename, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_mksquashfs_va (guestfs_h *g, const char *path, const char *filename, va_list args);

struct guestfs_mksquashfs_argv {
  uint64_t bitmask;
# define GUESTFS_MKSQUASHFS_COMPRESS_BITMASK (UINT64_C(1)<<0)
  const char *compress;
# define GUESTFS_MKSQUASHFS_EXCLUDES_BITMASK (UINT64_C(1)<<1)
  char *const *excludes;
};

extern GUESTFS_DLL_PUBLIC int guestfs_mksquashfs_argv (guestfs_h *g, const char *path, const char *filename, const struct guestfs_mksquashfs_argv *optargs);

#define GUESTFS_HAVE_MKSWAP 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkswap (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_MKSWAP_OPTS 1
#define GUESTFS_MKSWAP_OPTS_LABEL 0
#define GUESTFS_MKSWAP_OPTS_UUID 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkswap_opts (guestfs_h *g, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_mkswap_opts_va (guestfs_h *g, const char *device, va_list args);

struct guestfs_mkswap_opts_argv {
  uint64_t bitmask;
# define GUESTFS_MKSWAP_OPTS_LABEL_BITMASK (UINT64_C(1)<<0)
  const char *label;
# define GUESTFS_MKSWAP_OPTS_UUID_BITMASK (UINT64_C(1)<<1)
  const char *uuid;
};

extern GUESTFS_DLL_PUBLIC int guestfs_mkswap_opts_argv (guestfs_h *g, const char *device, const struct guestfs_mkswap_opts_argv *optargs);

#define GUESTFS_HAVE_MKSWAP_L 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkswap_L (guestfs_h *g, const char *label, const char *device)
  GUESTFS_DEPRECATED_BY ("mkswap");

#define GUESTFS_HAVE_MKSWAP_U 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkswap_U (guestfs_h *g, const char *uuid, const char *device)
  GUESTFS_DEPRECATED_BY ("mkswap");

#define GUESTFS_HAVE_MKSWAP_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_mkswap_file (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_MKTEMP 1
#define GUESTFS_MKTEMP_SUFFIX 0
extern GUESTFS_DLL_PUBLIC char *guestfs_mktemp (guestfs_h *g, const char *tmpl, ...);
extern GUESTFS_DLL_PUBLIC char *guestfs_mktemp_va (guestfs_h *g, const char *tmpl, va_list args);

struct guestfs_mktemp_argv {
  uint64_t bitmask;
# define GUESTFS_MKTEMP_SUFFIX_BITMASK (UINT64_C(1)<<0)
  const char *suffix;
};

extern GUESTFS_DLL_PUBLIC char *guestfs_mktemp_argv (guestfs_h *g, const char *tmpl, const struct guestfs_mktemp_argv *optargs);

#define GUESTFS_HAVE_MODPROBE 1
extern GUESTFS_DLL_PUBLIC int guestfs_modprobe (guestfs_h *g, const char *modulename);

#define GUESTFS_HAVE_MOUNT 1
extern GUESTFS_DLL_PUBLIC int guestfs_mount (guestfs_h *g, const char *mountable, const char *mountpoint);

#define GUESTFS_HAVE_MOUNT_9P 1
#define GUESTFS_MOUNT_9P_OPTIONS 0
extern GUESTFS_DLL_PUBLIC int guestfs_mount_9p (guestfs_h *g, const char *mounttag, const char *mountpoint, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_mount_9p_va (guestfs_h *g, const char *mounttag, const char *mountpoint, va_list args);

struct guestfs_mount_9p_argv {
  uint64_t bitmask;
# define GUESTFS_MOUNT_9P_OPTIONS_BITMASK (UINT64_C(1)<<0)
  const char *options;
};

extern GUESTFS_DLL_PUBLIC int guestfs_mount_9p_argv (guestfs_h *g, const char *mounttag, const char *mountpoint, const struct guestfs_mount_9p_argv *optargs);

#define GUESTFS_HAVE_MOUNT_LOCAL 1
#define GUESTFS_MOUNT_LOCAL_READONLY 0
#define GUESTFS_MOUNT_LOCAL_OPTIONS 1
#define GUESTFS_MOUNT_LOCAL_CACHETIMEOUT 2
#define GUESTFS_MOUNT_LOCAL_DEBUGCALLS 3
extern GUESTFS_DLL_PUBLIC int guestfs_mount_local (guestfs_h *g, const char *localmountpoint, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_mount_local_va (guestfs_h *g, const char *localmountpoint, va_list args);

struct guestfs_mount_local_argv {
  uint64_t bitmask;
# define GUESTFS_MOUNT_LOCAL_READONLY_BITMASK (UINT64_C(1)<<0)
  int readonly;
# define GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK (UINT64_C(1)<<1)
  const char *options;
# define GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK (UINT64_C(1)<<2)
  int cachetimeout;
# define GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK (UINT64_C(1)<<3)
  int debugcalls;
};

extern GUESTFS_DLL_PUBLIC int guestfs_mount_local_argv (guestfs_h *g, const char *localmountpoint, const struct guestfs_mount_local_argv *optargs);

#define GUESTFS_HAVE_MOUNT_LOCAL_RUN 1
extern GUESTFS_DLL_PUBLIC int guestfs_mount_local_run (guestfs_h *g);

#define GUESTFS_HAVE_MOUNT_LOOP 1
extern GUESTFS_DLL_PUBLIC int guestfs_mount_loop (guestfs_h *g, const char *file, const char *mountpoint);

#define GUESTFS_HAVE_MOUNT_OPTIONS 1
extern GUESTFS_DLL_PUBLIC int guestfs_mount_options (guestfs_h *g, const char *options, const char *mountable, const char *mountpoint);

#define GUESTFS_HAVE_MOUNT_RO 1
extern GUESTFS_DLL_PUBLIC int guestfs_mount_ro (guestfs_h *g, const char *mountable, const char *mountpoint);

#define GUESTFS_HAVE_MOUNT_VFS 1
extern GUESTFS_DLL_PUBLIC int guestfs_mount_vfs (guestfs_h *g, const char *options, const char *vfstype, const char *mountable, const char *mountpoint);

#define GUESTFS_HAVE_MOUNTABLE_DEVICE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_mountable_device (guestfs_h *g, const char *mountable);

#define GUESTFS_HAVE_MOUNTABLE_SUBVOLUME 1
extern GUESTFS_DLL_PUBLIC char *guestfs_mountable_subvolume (guestfs_h *g, const char *mountable);

#define GUESTFS_HAVE_MOUNTPOINTS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_mountpoints (guestfs_h *g);

#define GUESTFS_HAVE_MOUNTS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_mounts (guestfs_h *g);

#define GUESTFS_HAVE_MV 1
extern GUESTFS_DLL_PUBLIC int guestfs_mv (guestfs_h *g, const char *src, const char *dest);

#define GUESTFS_HAVE_NR_DEVICES 1
extern GUESTFS_DLL_PUBLIC int guestfs_nr_devices (guestfs_h *g);

#define GUESTFS_HAVE_NTFS_3G_PROBE 1
extern GUESTFS_DLL_PUBLIC int guestfs_ntfs_3g_probe (guestfs_h *g, int rw, const char *device);

#define GUESTFS_HAVE_NTFSCAT_I 1
extern GUESTFS_DLL_PUBLIC int guestfs_ntfscat_i (guestfs_h *g, const char *device, int64_t inode, const char *filename);

#define GUESTFS_HAVE_NTFSCLONE_IN 1
extern GUESTFS_DLL_PUBLIC int guestfs_ntfsclone_in (guestfs_h *g, const char *backupfile, const char *device);

#define GUESTFS_HAVE_NTFSCLONE_OUT 1
#define GUESTFS_NTFSCLONE_OUT_METADATAONLY 0
#define GUESTFS_NTFSCLONE_OUT_RESCUE 1
#define GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK 2
#define GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS 3
#define GUESTFS_NTFSCLONE_OUT_FORCE 4
extern GUESTFS_DLL_PUBLIC int guestfs_ntfsclone_out (guestfs_h *g, const char *device, const char *backupfile, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_ntfsclone_out_va (guestfs_h *g, const char *device, const char *backupfile, va_list args);

struct guestfs_ntfsclone_out_argv {
  uint64_t bitmask;
# define GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK (UINT64_C(1)<<0)
  int metadataonly;
# define GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK (UINT64_C(1)<<1)
  int rescue;
# define GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK (UINT64_C(1)<<2)
  int ignorefscheck;
# define GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK (UINT64_C(1)<<3)
  int preservetimestamps;
# define GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK (UINT64_C(1)<<4)
  int force;
};

extern GUESTFS_DLL_PUBLIC int guestfs_ntfsclone_out_argv (guestfs_h *g, const char *device, const char *backupfile, const struct guestfs_ntfsclone_out_argv *optargs);

#define GUESTFS_HAVE_NTFSFIX 1
#define GUESTFS_NTFSFIX_CLEARBADSECTORS 0
extern GUESTFS_DLL_PUBLIC int guestfs_ntfsfix (guestfs_h *g, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_ntfsfix_va (guestfs_h *g, const char *device, va_list args);

struct guestfs_ntfsfix_argv {
  uint64_t bitmask;
# define GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK (UINT64_C(1)<<0)
  int clearbadsectors;
};

extern GUESTFS_DLL_PUBLIC int guestfs_ntfsfix_argv (guestfs_h *g, const char *device, const struct guestfs_ntfsfix_argv *optargs);

#define GUESTFS_HAVE_NTFSRESIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_ntfsresize (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_NTFSRESIZE_OPTS 1
#define GUESTFS_NTFSRESIZE_OPTS_SIZE 0
#define GUESTFS_NTFSRESIZE_OPTS_FORCE 1
extern GUESTFS_DLL_PUBLIC int guestfs_ntfsresize_opts (guestfs_h *g, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_ntfsresize_opts_va (guestfs_h *g, const char *device, va_list args);

struct guestfs_ntfsresize_opts_argv {
  uint64_t bitmask;
# define GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK (UINT64_C(1)<<0)
  int64_t size;
# define GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK (UINT64_C(1)<<1)
  int force;
};

extern GUESTFS_DLL_PUBLIC int guestfs_ntfsresize_opts_argv (guestfs_h *g, const char *device, const struct guestfs_ntfsresize_opts_argv *optargs);

#define GUESTFS_HAVE_NTFSRESIZE_SIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_ntfsresize_size (guestfs_h *g, const char *device, int64_t size)
  GUESTFS_DEPRECATED_BY ("ntfsresize");

#define GUESTFS_HAVE_PARSE_ENVIRONMENT 1
extern GUESTFS_DLL_PUBLIC int guestfs_parse_environment (guestfs_h *g);

#define GUESTFS_HAVE_PARSE_ENVIRONMENT_LIST 1
extern GUESTFS_DLL_PUBLIC int guestfs_parse_environment_list (guestfs_h *g, char *const *environment);

#define GUESTFS_HAVE_PART_ADD 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_add (guestfs_h *g, const char *device, const char *prlogex, int64_t startsect, int64_t endsect);

#define GUESTFS_HAVE_PART_DEL 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_del (guestfs_h *g, const char *device, int partnum);

#define GUESTFS_HAVE_PART_DISK 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_disk (guestfs_h *g, const char *device, const char *parttype);

#define GUESTFS_HAVE_PART_EXPAND_GPT 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_expand_gpt (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_PART_GET_BOOTABLE 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_get_bootable (guestfs_h *g, const char *device, int partnum);

#define GUESTFS_HAVE_PART_GET_DISK_GUID 1
extern GUESTFS_DLL_PUBLIC char *guestfs_part_get_disk_guid (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_PART_GET_GPT_GUID 1
extern GUESTFS_DLL_PUBLIC char *guestfs_part_get_gpt_guid (guestfs_h *g, const char *device, int partnum);

#define GUESTFS_HAVE_PART_GET_GPT_TYPE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_part_get_gpt_type (guestfs_h *g, const char *device, int partnum);

#define GUESTFS_HAVE_PART_GET_MBR_ID 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_get_mbr_id (guestfs_h *g, const char *device, int partnum);

#define GUESTFS_HAVE_PART_GET_MBR_PART_TYPE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_part_get_mbr_part_type (guestfs_h *g, const char *device, int partnum);

#define GUESTFS_HAVE_PART_GET_NAME 1
extern GUESTFS_DLL_PUBLIC char *guestfs_part_get_name (guestfs_h *g, const char *device, int partnum);

#define GUESTFS_HAVE_PART_GET_PARTTYPE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_part_get_parttype (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_PART_INIT 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_init (guestfs_h *g, const char *device, const char *parttype);

#define GUESTFS_HAVE_PART_LIST 1
extern GUESTFS_DLL_PUBLIC struct guestfs_partition_list *guestfs_part_list (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_PART_SET_BOOTABLE 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_set_bootable (guestfs_h *g, const char *device, int partnum, int bootable);

#define GUESTFS_HAVE_PART_SET_DISK_GUID 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_set_disk_guid (guestfs_h *g, const char *device, const char *guid);

#define GUESTFS_HAVE_PART_SET_DISK_GUID_RANDOM 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_set_disk_guid_random (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_PART_SET_GPT_GUID 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_set_gpt_guid (guestfs_h *g, const char *device, int partnum, const char *guid);

#define GUESTFS_HAVE_PART_SET_GPT_TYPE 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_set_gpt_type (guestfs_h *g, const char *device, int partnum, const char *guid);

#define GUESTFS_HAVE_PART_SET_MBR_ID 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_set_mbr_id (guestfs_h *g, const char *device, int partnum, int idbyte);

#define GUESTFS_HAVE_PART_SET_NAME 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_set_name (guestfs_h *g, const char *device, int partnum, const char *name);

#define GUESTFS_HAVE_PART_TO_DEV 1
extern GUESTFS_DLL_PUBLIC char *guestfs_part_to_dev (guestfs_h *g, const char *partition);

#define GUESTFS_HAVE_PART_TO_PARTNUM 1
extern GUESTFS_DLL_PUBLIC int guestfs_part_to_partnum (guestfs_h *g, const char *partition);

#define GUESTFS_HAVE_PING_DAEMON 1
extern GUESTFS_DLL_PUBLIC int guestfs_ping_daemon (guestfs_h *g);

#define GUESTFS_HAVE_PREAD 1
extern GUESTFS_DLL_PUBLIC char *guestfs_pread (guestfs_h *g, const char *path, int count, int64_t offset, size_t *size_r);

#define GUESTFS_HAVE_PREAD_DEVICE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_pread_device (guestfs_h *g, const char *device, int count, int64_t offset, size_t *size_r);

#define GUESTFS_HAVE_PVCHANGE_UUID 1
extern GUESTFS_DLL_PUBLIC int guestfs_pvchange_uuid (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_PVCHANGE_UUID_ALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_pvchange_uuid_all (guestfs_h *g);

#define GUESTFS_HAVE_PVCREATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_pvcreate (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_PVREMOVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_pvremove (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_PVRESIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_pvresize (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_PVRESIZE_SIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_pvresize_size (guestfs_h *g, const char *device, int64_t size);

#define GUESTFS_HAVE_PVS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_pvs (guestfs_h *g);

#define GUESTFS_HAVE_PVS_FULL 1
extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv_list *guestfs_pvs_full (guestfs_h *g);

#define GUESTFS_HAVE_PVUUID 1
extern GUESTFS_DLL_PUBLIC char *guestfs_pvuuid (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_PWRITE 1
extern GUESTFS_DLL_PUBLIC int guestfs_pwrite (guestfs_h *g, const char *path, const char *content, size_t content_size, int64_t offset);

#define GUESTFS_HAVE_PWRITE_DEVICE 1
extern GUESTFS_DLL_PUBLIC int guestfs_pwrite_device (guestfs_h *g, const char *device, const char *content, size_t content_size, int64_t offset);

#define GUESTFS_HAVE_READ_FILE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_read_file (guestfs_h *g, const char *path, size_t *size_r);

#define GUESTFS_HAVE_READ_LINES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_read_lines (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_READDIR 1
extern GUESTFS_DLL_PUBLIC struct guestfs_dirent_list *guestfs_readdir (guestfs_h *g, const char *dir);

#define GUESTFS_HAVE_READLINK 1
extern GUESTFS_DLL_PUBLIC char *guestfs_readlink (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_READLINKLIST 1
extern GUESTFS_DLL_PUBLIC char **guestfs_readlinklist (guestfs_h *g, const char *path, char *const *names);

#define GUESTFS_HAVE_REALPATH 1
extern GUESTFS_DLL_PUBLIC char *guestfs_realpath (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_REMOUNT 1
#define GUESTFS_REMOUNT_RW 0
extern GUESTFS_DLL_PUBLIC int guestfs_remount (guestfs_h *g, const char *mountpoint, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_remount_va (guestfs_h *g, const char *mountpoint, va_list args);

struct guestfs_remount_argv {
  uint64_t bitmask;
# define GUESTFS_REMOUNT_RW_BITMASK (UINT64_C(1)<<0)
  int rw;
};

extern GUESTFS_DLL_PUBLIC int guestfs_remount_argv (guestfs_h *g, const char *mountpoint, const struct guestfs_remount_argv *optargs);

#define GUESTFS_HAVE_REMOVE_DRIVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_remove_drive (guestfs_h *g, const char *label);

#define GUESTFS_HAVE_REMOVEXATTR 1
extern GUESTFS_DLL_PUBLIC int guestfs_removexattr (guestfs_h *g, const char *xattr, const char *path);

#define GUESTFS_HAVE_RENAME 1
extern GUESTFS_DLL_PUBLIC int guestfs_rename (guestfs_h *g, const char *oldpath, const char *newpath);

#define GUESTFS_HAVE_RESIZE2FS 1
extern GUESTFS_DLL_PUBLIC int guestfs_resize2fs (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_RESIZE2FS_M 1
extern GUESTFS_DLL_PUBLIC int guestfs_resize2fs_M (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_RESIZE2FS_SIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_resize2fs_size (guestfs_h *g, const char *device, int64_t size);

#define GUESTFS_HAVE_RM 1
extern GUESTFS_DLL_PUBLIC int guestfs_rm (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_RM_F 1
extern GUESTFS_DLL_PUBLIC int guestfs_rm_f (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_RM_RF 1
extern GUESTFS_DLL_PUBLIC int guestfs_rm_rf (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_RMDIR 1
extern GUESTFS_DLL_PUBLIC int guestfs_rmdir (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_RMMOUNTPOINT 1
extern GUESTFS_DLL_PUBLIC int guestfs_rmmountpoint (guestfs_h *g, const char *exemptpath);

#define GUESTFS_HAVE_RSYNC 1
#define GUESTFS_RSYNC_ARCHIVE 0
#define GUESTFS_RSYNC_DELETEDEST 1
extern GUESTFS_DLL_PUBLIC int guestfs_rsync (guestfs_h *g, const char *src, const char *dest, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_rsync_va (guestfs_h *g, const char *src, const char *dest, va_list args);

struct guestfs_rsync_argv {
  uint64_t bitmask;
# define GUESTFS_RSYNC_ARCHIVE_BITMASK (UINT64_C(1)<<0)
  int archive;
# define GUESTFS_RSYNC_DELETEDEST_BITMASK (UINT64_C(1)<<1)
  int deletedest;
};

extern GUESTFS_DLL_PUBLIC int guestfs_rsync_argv (guestfs_h *g, const char *src, const char *dest, const struct guestfs_rsync_argv *optargs);

#define GUESTFS_HAVE_RSYNC_IN 1
#define GUESTFS_RSYNC_IN_ARCHIVE 0
#define GUESTFS_RSYNC_IN_DELETEDEST 1
extern GUESTFS_DLL_PUBLIC int guestfs_rsync_in (guestfs_h *g, const char *remote, const char *dest, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_rsync_in_va (guestfs_h *g, const char *remote, const char *dest, va_list args);

struct guestfs_rsync_in_argv {
  uint64_t bitmask;
# define GUESTFS_RSYNC_IN_ARCHIVE_BITMASK (UINT64_C(1)<<0)
  int archive;
# define GUESTFS_RSYNC_IN_DELETEDEST_BITMASK (UINT64_C(1)<<1)
  int deletedest;
};

extern GUESTFS_DLL_PUBLIC int guestfs_rsync_in_argv (guestfs_h *g, const char *remote, const char *dest, const struct guestfs_rsync_in_argv *optargs);

#define GUESTFS_HAVE_RSYNC_OUT 1
#define GUESTFS_RSYNC_OUT_ARCHIVE 0
#define GUESTFS_RSYNC_OUT_DELETEDEST 1
extern GUESTFS_DLL_PUBLIC int guestfs_rsync_out (guestfs_h *g, const char *src, const char *remote, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_rsync_out_va (guestfs_h *g, const char *src, const char *remote, va_list args);

struct guestfs_rsync_out_argv {
  uint64_t bitmask;
# define GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK (UINT64_C(1)<<0)
  int archive;
# define GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK (UINT64_C(1)<<1)
  int deletedest;
};

extern GUESTFS_DLL_PUBLIC int guestfs_rsync_out_argv (guestfs_h *g, const char *src, const char *remote, const struct guestfs_rsync_out_argv *optargs);

#define GUESTFS_HAVE_SCRUB_DEVICE 1
extern GUESTFS_DLL_PUBLIC int guestfs_scrub_device (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_SCRUB_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_scrub_file (guestfs_h *g, const char *file);

#define GUESTFS_HAVE_SCRUB_FREESPACE 1
extern GUESTFS_DLL_PUBLIC int guestfs_scrub_freespace (guestfs_h *g, const char *dir);

#define GUESTFS_HAVE_SELINUX_RELABEL 1
#define GUESTFS_SELINUX_RELABEL_FORCE 0
extern GUESTFS_DLL_PUBLIC int guestfs_selinux_relabel (guestfs_h *g, const char *specfile, const char *path, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_selinux_relabel_va (guestfs_h *g, const char *specfile, const char *path, va_list args);

struct guestfs_selinux_relabel_argv {
  uint64_t bitmask;
# define GUESTFS_SELINUX_RELABEL_FORCE_BITMASK (UINT64_C(1)<<0)
  int force;
};

extern GUESTFS_DLL_PUBLIC int guestfs_selinux_relabel_argv (guestfs_h *g, const char *specfile, const char *path, const struct guestfs_selinux_relabel_argv *optargs);

#define GUESTFS_HAVE_SET_APPEND 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_append (guestfs_h *g, const char *append);

#define GUESTFS_HAVE_SET_ATTACH_METHOD 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_attach_method (guestfs_h *g, const char *backend)
  GUESTFS_DEPRECATED_BY ("set_backend");

#define GUESTFS_HAVE_SET_AUTOSYNC 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_autosync (guestfs_h *g, int autosync);

#define GUESTFS_HAVE_SET_BACKEND 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_backend (guestfs_h *g, const char *backend);

#define GUESTFS_HAVE_SET_BACKEND_SETTING 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_backend_setting (guestfs_h *g, const char *name, const char *val);

#define GUESTFS_HAVE_SET_BACKEND_SETTINGS 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_backend_settings (guestfs_h *g, char *const *settings);

#define GUESTFS_HAVE_SET_CACHEDIR 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_cachedir (guestfs_h *g, const char *cachedir);

#define GUESTFS_HAVE_SET_DIRECT 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_direct (guestfs_h *g, int direct);

#define GUESTFS_HAVE_SET_E2ATTRS 1
#define GUESTFS_SET_E2ATTRS_CLEAR 0
extern GUESTFS_DLL_PUBLIC int guestfs_set_e2attrs (guestfs_h *g, const char *file, const char *attrs, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_set_e2attrs_va (guestfs_h *g, const char *file, const char *attrs, va_list args);

struct guestfs_set_e2attrs_argv {
  uint64_t bitmask;
# define GUESTFS_SET_E2ATTRS_CLEAR_BITMASK (UINT64_C(1)<<0)
  int clear;
};

extern GUESTFS_DLL_PUBLIC int guestfs_set_e2attrs_argv (guestfs_h *g, const char *file, const char *attrs, const struct guestfs_set_e2attrs_argv *optargs);

#define GUESTFS_HAVE_SET_E2GENERATION 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_e2generation (guestfs_h *g, const char *file, int64_t generation);

#define GUESTFS_HAVE_SET_E2LABEL 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_e2label (guestfs_h *g, const char *device, const char *label)
  GUESTFS_DEPRECATED_BY ("set_label");

#define GUESTFS_HAVE_SET_E2UUID 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_e2uuid (guestfs_h *g, const char *device, const char *uuid)
  GUESTFS_DEPRECATED_BY ("set_uuid");

#define GUESTFS_HAVE_SET_HV 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_hv (guestfs_h *g, const char *hv);

#define GUESTFS_HAVE_SET_IDENTIFIER 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_identifier (guestfs_h *g, const char *identifier);

#define GUESTFS_HAVE_SET_LABEL 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_label (guestfs_h *g, const char *mountable, const char *label);

#define GUESTFS_HAVE_SET_LIBVIRT_REQUESTED_CREDENTIAL 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_libvirt_requested_credential (guestfs_h *g, int index, const char *cred, size_t cred_size);

#define GUESTFS_HAVE_SET_LIBVIRT_SUPPORTED_CREDENTIALS 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_libvirt_supported_credentials (guestfs_h *g, char *const *creds);

#define GUESTFS_HAVE_SET_MEMSIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_memsize (guestfs_h *g, int memsize);

#define GUESTFS_HAVE_SET_NETWORK 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_network (guestfs_h *g, int network);

#define GUESTFS_HAVE_SET_PATH 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_path (guestfs_h *g, const char *searchpath);

#define GUESTFS_HAVE_SET_PGROUP 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_pgroup (guestfs_h *g, int pgroup);

#define GUESTFS_HAVE_SET_PROGRAM 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_program (guestfs_h *g, const char *program);

#define GUESTFS_HAVE_SET_QEMU 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_qemu (guestfs_h *g, const char *hv)
  GUESTFS_DEPRECATED_BY ("set_hv");

#define GUESTFS_HAVE_SET_RECOVERY_PROC 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_recovery_proc (guestfs_h *g, int recoveryproc);

#define GUESTFS_HAVE_SET_SELINUX 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_selinux (guestfs_h *g, int selinux)
  GUESTFS_DEPRECATED_BY ("selinux_relabel");

#define GUESTFS_HAVE_SET_SMP 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_smp (guestfs_h *g, int smp);

#define GUESTFS_HAVE_SET_TMPDIR 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_tmpdir (guestfs_h *g, const char *tmpdir);

#define GUESTFS_HAVE_SET_TRACE 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_trace (guestfs_h *g, int trace);

#define GUESTFS_HAVE_SET_UUID 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_uuid (guestfs_h *g, const char *device, const char *uuid);

#define GUESTFS_HAVE_SET_UUID_RANDOM 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_uuid_random (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_SET_VERBOSE 1
extern GUESTFS_DLL_PUBLIC int guestfs_set_verbose (guestfs_h *g, int verbose);

#define GUESTFS_HAVE_SETCON 1
extern GUESTFS_DLL_PUBLIC int guestfs_setcon (guestfs_h *g, const char *context)
  GUESTFS_DEPRECATED_BY ("selinux_relabel");

#define GUESTFS_HAVE_SETXATTR 1
extern GUESTFS_DLL_PUBLIC int guestfs_setxattr (guestfs_h *g, const char *xattr, const char *val, int vallen, const char *path);

#define GUESTFS_HAVE_SFDISK 1
extern GUESTFS_DLL_PUBLIC int guestfs_sfdisk (guestfs_h *g, const char *device, int cyls, int heads, int sectors, char *const *lines)
  GUESTFS_DEPRECATED_BY ("part_add");

#define GUESTFS_HAVE_SFDISKM 1
extern GUESTFS_DLL_PUBLIC int guestfs_sfdiskM (guestfs_h *g, const char *device, char *const *lines)
  GUESTFS_DEPRECATED_BY ("part_add");

#define GUESTFS_HAVE_SFDISK_N 1
extern GUESTFS_DLL_PUBLIC int guestfs_sfdisk_N (guestfs_h *g, const char *device, int partnum, int cyls, int heads, int sectors, const char *line)
  GUESTFS_DEPRECATED_BY ("part_add");

#define GUESTFS_HAVE_SFDISK_DISK_GEOMETRY 1
extern GUESTFS_DLL_PUBLIC char *guestfs_sfdisk_disk_geometry (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_SFDISK_KERNEL_GEOMETRY 1
extern GUESTFS_DLL_PUBLIC char *guestfs_sfdisk_kernel_geometry (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_SFDISK_L 1
extern GUESTFS_DLL_PUBLIC char *guestfs_sfdisk_l (guestfs_h *g, const char *device)
  GUESTFS_DEPRECATED_BY ("part_list");

#define GUESTFS_HAVE_SH 1
extern GUESTFS_DLL_PUBLIC char *guestfs_sh (guestfs_h *g, const char *command);

#define GUESTFS_HAVE_SH_LINES 1
extern GUESTFS_DLL_PUBLIC char **guestfs_sh_lines (guestfs_h *g, const char *command);

#define GUESTFS_HAVE_SHUTDOWN 1
extern GUESTFS_DLL_PUBLIC int guestfs_shutdown (guestfs_h *g);

#define GUESTFS_HAVE_SLEEP 1
extern GUESTFS_DLL_PUBLIC int guestfs_sleep (guestfs_h *g, int secs);

#define GUESTFS_HAVE_STAT 1
extern GUESTFS_DLL_PUBLIC struct guestfs_stat *guestfs_stat (guestfs_h *g, const char *path)
  GUESTFS_DEPRECATED_BY ("statns");

#define GUESTFS_HAVE_STATNS 1
extern GUESTFS_DLL_PUBLIC struct guestfs_statns *guestfs_statns (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_STATVFS 1
extern GUESTFS_DLL_PUBLIC struct guestfs_statvfs *guestfs_statvfs (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_STRINGS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_strings (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_STRINGS_E 1
extern GUESTFS_DLL_PUBLIC char **guestfs_strings_e (guestfs_h *g, const char *encoding, const char *path);

#define GUESTFS_HAVE_SWAPOFF_DEVICE 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapoff_device (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_SWAPOFF_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapoff_file (guestfs_h *g, const char *file);

#define GUESTFS_HAVE_SWAPOFF_LABEL 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapoff_label (guestfs_h *g, const char *label);

#define GUESTFS_HAVE_SWAPOFF_UUID 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapoff_uuid (guestfs_h *g, const char *uuid);

#define GUESTFS_HAVE_SWAPON_DEVICE 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapon_device (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_SWAPON_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapon_file (guestfs_h *g, const char *file);

#define GUESTFS_HAVE_SWAPON_LABEL 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapon_label (guestfs_h *g, const char *label);

#define GUESTFS_HAVE_SWAPON_UUID 1
extern GUESTFS_DLL_PUBLIC int guestfs_swapon_uuid (guestfs_h *g, const char *uuid);

#define GUESTFS_HAVE_SYNC 1
extern GUESTFS_DLL_PUBLIC int guestfs_sync (guestfs_h *g);

#define GUESTFS_HAVE_SYSLINUX 1
#define GUESTFS_SYSLINUX_DIRECTORY 0
extern GUESTFS_DLL_PUBLIC int guestfs_syslinux (guestfs_h *g, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_syslinux_va (guestfs_h *g, const char *device, va_list args);

struct guestfs_syslinux_argv {
  uint64_t bitmask;
# define GUESTFS_SYSLINUX_DIRECTORY_BITMASK (UINT64_C(1)<<0)
  const char *directory;
};

extern GUESTFS_DLL_PUBLIC int guestfs_syslinux_argv (guestfs_h *g, const char *device, const struct guestfs_syslinux_argv *optargs);

#define GUESTFS_HAVE_TAIL 1
extern GUESTFS_DLL_PUBLIC char **guestfs_tail (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_TAIL_N 1
extern GUESTFS_DLL_PUBLIC char **guestfs_tail_n (guestfs_h *g, int nrlines, const char *path);

#define GUESTFS_HAVE_TAR_IN 1
extern GUESTFS_DLL_PUBLIC int guestfs_tar_in (guestfs_h *g, const char *tarfile, const char *directory);

#define GUESTFS_HAVE_TAR_IN_OPTS 1
#define GUESTFS_TAR_IN_OPTS_COMPRESS 0
#define GUESTFS_TAR_IN_OPTS_XATTRS 1
#define GUESTFS_TAR_IN_OPTS_SELINUX 2
#define GUESTFS_TAR_IN_OPTS_ACLS 3
extern GUESTFS_DLL_PUBLIC int guestfs_tar_in_opts (guestfs_h *g, const char *tarfile, const char *directory, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_tar_in_opts_va (guestfs_h *g, const char *tarfile, const char *directory, va_list args);

struct guestfs_tar_in_opts_argv {
  uint64_t bitmask;
# define GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK (UINT64_C(1)<<0)
  const char *compress;
# define GUESTFS_TAR_IN_OPTS_XATTRS_BITMASK (UINT64_C(1)<<1)
  int xattrs;
# define GUESTFS_TAR_IN_OPTS_SELINUX_BITMASK (UINT64_C(1)<<2)
  int selinux;
# define GUESTFS_TAR_IN_OPTS_ACLS_BITMASK (UINT64_C(1)<<3)
  int acls;
};

extern GUESTFS_DLL_PUBLIC int guestfs_tar_in_opts_argv (guestfs_h *g, const char *tarfile, const char *directory, const struct guestfs_tar_in_opts_argv *optargs);

#define GUESTFS_HAVE_TAR_OUT 1
extern GUESTFS_DLL_PUBLIC int guestfs_tar_out (guestfs_h *g, const char *directory, const char *tarfile);

#define GUESTFS_HAVE_TAR_OUT_OPTS 1
#define GUESTFS_TAR_OUT_OPTS_COMPRESS 0
#define GUESTFS_TAR_OUT_OPTS_NUMERICOWNER 1
#define GUESTFS_TAR_OUT_OPTS_EXCLUDES 2
#define GUESTFS_TAR_OUT_OPTS_XATTRS 3
#define GUESTFS_TAR_OUT_OPTS_SELINUX 4
#define GUESTFS_TAR_OUT_OPTS_ACLS 5
extern GUESTFS_DLL_PUBLIC int guestfs_tar_out_opts (guestfs_h *g, const char *directory, const char *tarfile, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_tar_out_opts_va (guestfs_h *g, const char *directory, const char *tarfile, va_list args);

struct guestfs_tar_out_opts_argv {
  uint64_t bitmask;
# define GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK (UINT64_C(1)<<0)
  const char *compress;
# define GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK (UINT64_C(1)<<1)
  int numericowner;
# define GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK (UINT64_C(1)<<2)
  char *const *excludes;
# define GUESTFS_TAR_OUT_OPTS_XATTRS_BITMASK (UINT64_C(1)<<3)
  int xattrs;
# define GUESTFS_TAR_OUT_OPTS_SELINUX_BITMASK (UINT64_C(1)<<4)
  int selinux;
# define GUESTFS_TAR_OUT_OPTS_ACLS_BITMASK (UINT64_C(1)<<5)
  int acls;
};

extern GUESTFS_DLL_PUBLIC int guestfs_tar_out_opts_argv (guestfs_h *g, const char *directory, const char *tarfile, const struct guestfs_tar_out_opts_argv *optargs);

#define GUESTFS_HAVE_TGZ_IN 1
extern GUESTFS_DLL_PUBLIC int guestfs_tgz_in (guestfs_h *g, const char *tarball, const char *directory)
  GUESTFS_DEPRECATED_BY ("tar_in");

#define GUESTFS_HAVE_TGZ_OUT 1
extern GUESTFS_DLL_PUBLIC int guestfs_tgz_out (guestfs_h *g, const char *directory, const char *tarball)
  GUESTFS_DEPRECATED_BY ("tar_out");

#define GUESTFS_HAVE_TOUCH 1
extern GUESTFS_DLL_PUBLIC int guestfs_touch (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_TRUNCATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_truncate (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_TRUNCATE_SIZE 1
extern GUESTFS_DLL_PUBLIC int guestfs_truncate_size (guestfs_h *g, const char *path, int64_t size);

#define GUESTFS_HAVE_TUNE2FS 1
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
  int force;
# define GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK (UINT64_C(1)<<1)
  int maxmountcount;
# define GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK (UINT64_C(1)<<2)
  int mountcount;
# define GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK (UINT64_C(1)<<3)
  const char *errorbehavior;
# define GUESTFS_TUNE2FS_GROUP_BITMASK (UINT64_C(1)<<4)
  int64_t group;
# define GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK (UINT64_C(1)<<5)
  int intervalbetweenchecks;
# define GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK (UINT64_C(1)<<6)
  int reservedblockspercentage;
# define GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK (UINT64_C(1)<<7)
  const char *lastmounteddirectory;
# define GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK (UINT64_C(1)<<8)
  int64_t reservedblockscount;
# define GUESTFS_TUNE2FS_USER_BITMASK (UINT64_C(1)<<9)
  int64_t user;
};

extern GUESTFS_DLL_PUBLIC int guestfs_tune2fs_argv (guestfs_h *g, const char *device, const struct guestfs_tune2fs_argv *optargs);

#define GUESTFS_HAVE_TUNE2FS_L 1
extern GUESTFS_DLL_PUBLIC char **guestfs_tune2fs_l (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_TXZ_IN 1
extern GUESTFS_DLL_PUBLIC int guestfs_txz_in (guestfs_h *g, const char *tarball, const char *directory)
  GUESTFS_DEPRECATED_BY ("tar_in");

#define GUESTFS_HAVE_TXZ_OUT 1
extern GUESTFS_DLL_PUBLIC int guestfs_txz_out (guestfs_h *g, const char *directory, const char *tarball)
  GUESTFS_DEPRECATED_BY ("tar_out");

#define GUESTFS_HAVE_UMASK 1
extern GUESTFS_DLL_PUBLIC int guestfs_umask (guestfs_h *g, int mask);

#define GUESTFS_HAVE_UMOUNT 1
extern GUESTFS_DLL_PUBLIC int guestfs_umount (guestfs_h *g, const char *pathordevice);

#define GUESTFS_HAVE_UMOUNT_OPTS 1
#define GUESTFS_UMOUNT_OPTS_FORCE 0
#define GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT 1
extern GUESTFS_DLL_PUBLIC int guestfs_umount_opts (guestfs_h *g, const char *pathordevice, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_umount_opts_va (guestfs_h *g, const char *pathordevice, va_list args);

struct guestfs_umount_opts_argv {
  uint64_t bitmask;
# define GUESTFS_UMOUNT_OPTS_FORCE_BITMASK (UINT64_C(1)<<0)
  int force;
# define GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK (UINT64_C(1)<<1)
  int lazyunmount;
};

extern GUESTFS_DLL_PUBLIC int guestfs_umount_opts_argv (guestfs_h *g, const char *pathordevice, const struct guestfs_umount_opts_argv *optargs);

#define GUESTFS_HAVE_UMOUNT_ALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_umount_all (guestfs_h *g);

#define GUESTFS_HAVE_UMOUNT_LOCAL 1
#define GUESTFS_UMOUNT_LOCAL_RETRY 0
extern GUESTFS_DLL_PUBLIC int guestfs_umount_local (guestfs_h *g, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_umount_local_va (guestfs_h *g, va_list args);

struct guestfs_umount_local_argv {
  uint64_t bitmask;
# define GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK (UINT64_C(1)<<0)
  int retry;
};

extern GUESTFS_DLL_PUBLIC int guestfs_umount_local_argv (guestfs_h *g, const struct guestfs_umount_local_argv *optargs);

#define GUESTFS_HAVE_UPLOAD 1
extern GUESTFS_DLL_PUBLIC int guestfs_upload (guestfs_h *g, const char *filename, const char *remotefilename);

#define GUESTFS_HAVE_UPLOAD_OFFSET 1
extern GUESTFS_DLL_PUBLIC int guestfs_upload_offset (guestfs_h *g, const char *filename, const char *remotefilename, int64_t offset);

#define GUESTFS_HAVE_USER_CANCEL 1
extern GUESTFS_DLL_PUBLIC int guestfs_user_cancel (guestfs_h *g);

#define GUESTFS_HAVE_UTIMENS 1
extern GUESTFS_DLL_PUBLIC int guestfs_utimens (guestfs_h *g, const char *path, int64_t atsecs, int64_t atnsecs, int64_t mtsecs, int64_t mtnsecs);

#define GUESTFS_HAVE_UTSNAME 1
extern GUESTFS_DLL_PUBLIC struct guestfs_utsname *guestfs_utsname (guestfs_h *g);

#define GUESTFS_HAVE_VERSION 1
extern GUESTFS_DLL_PUBLIC struct guestfs_version *guestfs_version (guestfs_h *g);

#define GUESTFS_HAVE_VFS_LABEL 1
extern GUESTFS_DLL_PUBLIC char *guestfs_vfs_label (guestfs_h *g, const char *mountable);

#define GUESTFS_HAVE_VFS_MINIMUM_SIZE 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_vfs_minimum_size (guestfs_h *g, const char *mountable);

#define GUESTFS_HAVE_VFS_TYPE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_vfs_type (guestfs_h *g, const char *mountable);

#define GUESTFS_HAVE_VFS_UUID 1
extern GUESTFS_DLL_PUBLIC char *guestfs_vfs_uuid (guestfs_h *g, const char *mountable);

#define GUESTFS_HAVE_VG_ACTIVATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_vg_activate (guestfs_h *g, int activate, char *const *volgroups);

#define GUESTFS_HAVE_VG_ACTIVATE_ALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_vg_activate_all (guestfs_h *g, int activate);

#define GUESTFS_HAVE_VGCHANGE_UUID 1
extern GUESTFS_DLL_PUBLIC int guestfs_vgchange_uuid (guestfs_h *g, const char *vg);

#define GUESTFS_HAVE_VGCHANGE_UUID_ALL 1
extern GUESTFS_DLL_PUBLIC int guestfs_vgchange_uuid_all (guestfs_h *g);

#define GUESTFS_HAVE_VGCREATE 1
extern GUESTFS_DLL_PUBLIC int guestfs_vgcreate (guestfs_h *g, const char *volgroup, char *const *physvols);

#define GUESTFS_HAVE_VGLVUUIDS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_vglvuuids (guestfs_h *g, const char *vgname);

#define GUESTFS_HAVE_VGMETA 1
extern GUESTFS_DLL_PUBLIC char *guestfs_vgmeta (guestfs_h *g, const char *vgname, size_t *size_r);

#define GUESTFS_HAVE_VGPVUUIDS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_vgpvuuids (guestfs_h *g, const char *vgname);

#define GUESTFS_HAVE_VGREMOVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_vgremove (guestfs_h *g, const char *vgname);

#define GUESTFS_HAVE_VGRENAME 1
extern GUESTFS_DLL_PUBLIC int guestfs_vgrename (guestfs_h *g, const char *volgroup, const char *newvolgroup);

#define GUESTFS_HAVE_VGS 1
extern GUESTFS_DLL_PUBLIC char **guestfs_vgs (guestfs_h *g);

#define GUESTFS_HAVE_VGS_FULL 1
extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_vg_list *guestfs_vgs_full (guestfs_h *g);

#define GUESTFS_HAVE_VGSCAN 1
extern GUESTFS_DLL_PUBLIC int guestfs_vgscan (guestfs_h *g);

#define GUESTFS_HAVE_VGUUID 1
extern GUESTFS_DLL_PUBLIC char *guestfs_vguuid (guestfs_h *g, const char *vgname);

#define GUESTFS_HAVE_WAIT_READY 1
extern GUESTFS_DLL_PUBLIC int guestfs_wait_ready (guestfs_h *g)
  GUESTFS_DEPRECATED_BY ("launch");

#define GUESTFS_HAVE_WC_C 1
extern GUESTFS_DLL_PUBLIC int guestfs_wc_c (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_WC_L 1
extern GUESTFS_DLL_PUBLIC int guestfs_wc_l (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_WC_W 1
extern GUESTFS_DLL_PUBLIC int guestfs_wc_w (guestfs_h *g, const char *path);

#define GUESTFS_HAVE_WIPEFS 1
extern GUESTFS_DLL_PUBLIC int guestfs_wipefs (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_WRITE 1
extern GUESTFS_DLL_PUBLIC int guestfs_write (guestfs_h *g, const char *path, const char *content, size_t content_size);

#define GUESTFS_HAVE_WRITE_APPEND 1
extern GUESTFS_DLL_PUBLIC int guestfs_write_append (guestfs_h *g, const char *path, const char *content, size_t content_size);

#define GUESTFS_HAVE_WRITE_FILE 1
extern GUESTFS_DLL_PUBLIC int guestfs_write_file (guestfs_h *g, const char *path, const char *content, int size)
  GUESTFS_DEPRECATED_BY ("write");

#define GUESTFS_HAVE_XFS_ADMIN 1
#define GUESTFS_XFS_ADMIN_EXTUNWRITTEN 0
#define GUESTFS_XFS_ADMIN_IMGFILE 1
#define GUESTFS_XFS_ADMIN_V2LOG 2
#define GUESTFS_XFS_ADMIN_PROJID32BIT 3
#define GUESTFS_XFS_ADMIN_LAZYCOUNTER 4
#define GUESTFS_XFS_ADMIN_LABEL 5
#define GUESTFS_XFS_ADMIN_UUID 6
extern GUESTFS_DLL_PUBLIC int guestfs_xfs_admin (guestfs_h *g, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_xfs_admin_va (guestfs_h *g, const char *device, va_list args);

struct guestfs_xfs_admin_argv {
  uint64_t bitmask;
# define GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK (UINT64_C(1)<<0)
  int extunwritten;
# define GUESTFS_XFS_ADMIN_IMGFILE_BITMASK (UINT64_C(1)<<1)
  int imgfile;
# define GUESTFS_XFS_ADMIN_V2LOG_BITMASK (UINT64_C(1)<<2)
  int v2log;
# define GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK (UINT64_C(1)<<3)
  int projid32bit;
# define GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK (UINT64_C(1)<<4)
  int lazycounter;
# define GUESTFS_XFS_ADMIN_LABEL_BITMASK (UINT64_C(1)<<5)
  const char *label;
# define GUESTFS_XFS_ADMIN_UUID_BITMASK (UINT64_C(1)<<6)
  const char *uuid;
};

extern GUESTFS_DLL_PUBLIC int guestfs_xfs_admin_argv (guestfs_h *g, const char *device, const struct guestfs_xfs_admin_argv *optargs);

#define GUESTFS_HAVE_XFS_GROWFS 1
#define GUESTFS_XFS_GROWFS_DATASEC 0
#define GUESTFS_XFS_GROWFS_LOGSEC 1
#define GUESTFS_XFS_GROWFS_RTSEC 2
#define GUESTFS_XFS_GROWFS_DATASIZE 3
#define GUESTFS_XFS_GROWFS_LOGSIZE 4
#define GUESTFS_XFS_GROWFS_RTSIZE 5
#define GUESTFS_XFS_GROWFS_RTEXTSIZE 6
#define GUESTFS_XFS_GROWFS_MAXPCT 7
extern GUESTFS_DLL_PUBLIC int guestfs_xfs_growfs (guestfs_h *g, const char *path, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_xfs_growfs_va (guestfs_h *g, const char *path, va_list args);

struct guestfs_xfs_growfs_argv {
  uint64_t bitmask;
# define GUESTFS_XFS_GROWFS_DATASEC_BITMASK (UINT64_C(1)<<0)
  int datasec;
# define GUESTFS_XFS_GROWFS_LOGSEC_BITMASK (UINT64_C(1)<<1)
  int logsec;
# define GUESTFS_XFS_GROWFS_RTSEC_BITMASK (UINT64_C(1)<<2)
  int rtsec;
# define GUESTFS_XFS_GROWFS_DATASIZE_BITMASK (UINT64_C(1)<<3)
  int64_t datasize;
# define GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK (UINT64_C(1)<<4)
  int64_t logsize;
# define GUESTFS_XFS_GROWFS_RTSIZE_BITMASK (UINT64_C(1)<<5)
  int64_t rtsize;
# define GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK (UINT64_C(1)<<6)
  int64_t rtextsize;
# define GUESTFS_XFS_GROWFS_MAXPCT_BITMASK (UINT64_C(1)<<7)
  int maxpct;
};

extern GUESTFS_DLL_PUBLIC int guestfs_xfs_growfs_argv (guestfs_h *g, const char *path, const struct guestfs_xfs_growfs_argv *optargs);

#define GUESTFS_HAVE_XFS_INFO 1
extern GUESTFS_DLL_PUBLIC struct guestfs_xfsinfo *guestfs_xfs_info (guestfs_h *g, const char *pathordevice);

#define GUESTFS_HAVE_XFS_REPAIR 1
#define GUESTFS_XFS_REPAIR_FORCELOGZERO 0
#define GUESTFS_XFS_REPAIR_NOMODIFY 1
#define GUESTFS_XFS_REPAIR_NOPREFETCH 2
#define GUESTFS_XFS_REPAIR_FORCEGEOMETRY 3
#define GUESTFS_XFS_REPAIR_MAXMEM 4
#define GUESTFS_XFS_REPAIR_IHASHSIZE 5
#define GUESTFS_XFS_REPAIR_BHASHSIZE 6
#define GUESTFS_XFS_REPAIR_AGSTRIDE 7
#define GUESTFS_XFS_REPAIR_LOGDEV 8
#define GUESTFS_XFS_REPAIR_RTDEV 9
extern GUESTFS_DLL_PUBLIC int guestfs_xfs_repair (guestfs_h *g, const char *device, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_xfs_repair_va (guestfs_h *g, const char *device, va_list args);

struct guestfs_xfs_repair_argv {
  uint64_t bitmask;
# define GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK (UINT64_C(1)<<0)
  int forcelogzero;
# define GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK (UINT64_C(1)<<1)
  int nomodify;
# define GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK (UINT64_C(1)<<2)
  int noprefetch;
# define GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK (UINT64_C(1)<<3)
  int forcegeometry;
# define GUESTFS_XFS_REPAIR_MAXMEM_BITMASK (UINT64_C(1)<<4)
  int64_t maxmem;
# define GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK (UINT64_C(1)<<5)
  int64_t ihashsize;
# define GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK (UINT64_C(1)<<6)
  int64_t bhashsize;
# define GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK (UINT64_C(1)<<7)
  int64_t agstride;
# define GUESTFS_XFS_REPAIR_LOGDEV_BITMASK (UINT64_C(1)<<8)
  const char *logdev;
# define GUESTFS_XFS_REPAIR_RTDEV_BITMASK (UINT64_C(1)<<9)
  const char *rtdev;
};

extern GUESTFS_DLL_PUBLIC int guestfs_xfs_repair_argv (guestfs_h *g, const char *device, const struct guestfs_xfs_repair_argv *optargs);

#define GUESTFS_HAVE_ZEGREP 1
extern GUESTFS_DLL_PUBLIC char **guestfs_zegrep (guestfs_h *g, const char *regex, const char *path)
  GUESTFS_DEPRECATED_BY ("grep");

#define GUESTFS_HAVE_ZEGREPI 1
extern GUESTFS_DLL_PUBLIC char **guestfs_zegrepi (guestfs_h *g, const char *regex, const char *path)
  GUESTFS_DEPRECATED_BY ("grep");

#define GUESTFS_HAVE_ZERO 1
extern GUESTFS_DLL_PUBLIC int guestfs_zero (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_ZERO_DEVICE 1
extern GUESTFS_DLL_PUBLIC int guestfs_zero_device (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_ZERO_FREE_SPACE 1
extern GUESTFS_DLL_PUBLIC int guestfs_zero_free_space (guestfs_h *g, const char *directory);

#define GUESTFS_HAVE_ZEROFREE 1
extern GUESTFS_DLL_PUBLIC int guestfs_zerofree (guestfs_h *g, const char *device);

#define GUESTFS_HAVE_ZFGREP 1
extern GUESTFS_DLL_PUBLIC char **guestfs_zfgrep (guestfs_h *g, const char *pattern, const char *path)
  GUESTFS_DEPRECATED_BY ("grep");

#define GUESTFS_HAVE_ZFGREPI 1
extern GUESTFS_DLL_PUBLIC char **guestfs_zfgrepi (guestfs_h *g, const char *pattern, const char *path)
  GUESTFS_DEPRECATED_BY ("grep");

#define GUESTFS_HAVE_ZFILE 1
extern GUESTFS_DLL_PUBLIC char *guestfs_zfile (guestfs_h *g, const char *meth, const char *path)
  GUESTFS_DEPRECATED_BY ("file");

#define GUESTFS_HAVE_ZGREP 1
extern GUESTFS_DLL_PUBLIC char **guestfs_zgrep (guestfs_h *g, const char *regex, const char *path)
  GUESTFS_DEPRECATED_BY ("grep");

#define GUESTFS_HAVE_ZGREPI 1
extern GUESTFS_DLL_PUBLIC char **guestfs_zgrepi (guestfs_h *g, const char *regex, const char *path)
  GUESTFS_DEPRECATED_BY ("grep");

#if GUESTFS_PRIVATE
/* Symbols protected by GUESTFS_PRIVATE are NOT part of the public,
 * stable API, and can change at any time!  We export them because
 * they are used by some of the language bindings.
 */

/* Private functions. */

#define GUESTFS_HAVE_INTERNAL_AUTOSYNC 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_autosync (guestfs_h *g);

#define GUESTFS_HAVE_INTERNAL_FEATURE_AVAILABLE 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_feature_available (guestfs_h *g, const char *group);

#define GUESTFS_HAVE_INTERNAL_FILESYSTEM_WALK 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_filesystem_walk (guestfs_h *g, const char *device, const char *filename);

#define GUESTFS_HAVE_INTERNAL_FIND_INODE 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_find_inode (guestfs_h *g, const char *device, int64_t inode, const char *filename);

#define GUESTFS_HAVE_INTERNAL_HOT_ADD_DRIVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_hot_add_drive (guestfs_h *g, const char *label);

#define GUESTFS_HAVE_INTERNAL_HOT_REMOVE_DRIVE 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_hot_remove_drive (guestfs_h *g, const char *label);

#define GUESTFS_HAVE_INTERNAL_HOT_REMOVE_DRIVE_PRECHECK 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_hot_remove_drive_precheck (guestfs_h *g, const char *label);

#define GUESTFS_HAVE_INTERNAL_JOURNAL_GET 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_journal_get (guestfs_h *g, const char *filename);

#define GUESTFS_HAVE_INTERNAL_LSTATNSLIST 1
extern GUESTFS_DLL_PUBLIC struct guestfs_statns_list *guestfs_internal_lstatnslist (guestfs_h *g, const char *path, char *const *names);

#define GUESTFS_HAVE_INTERNAL_LXATTRLIST 1
extern GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *guestfs_internal_lxattrlist (guestfs_h *g, const char *path, char *const *names);

#define GUESTFS_HAVE_INTERNAL_PARSE_MOUNTABLE 1
extern GUESTFS_DLL_PUBLIC struct guestfs_internal_mountable *guestfs_internal_parse_mountable (guestfs_h *g, const char *mountable);

#define GUESTFS_HAVE_INTERNAL_READLINKLIST 1
extern GUESTFS_DLL_PUBLIC char **guestfs_internal_readlinklist (guestfs_h *g, const char *path, char *const *names);

#define GUESTFS_HAVE_INTERNAL_RHBZ914931 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_rhbz914931 (guestfs_h *g, const char *filename, int count);

#define GUESTFS_HAVE_INTERNAL_TEST 1
#define GUESTFS_INTERNAL_TEST_OBOOL 0
#define GUESTFS_INTERNAL_TEST_OINT 1
#define GUESTFS_INTERNAL_TEST_OINT64 2
#define GUESTFS_INTERNAL_TEST_OSTRING 3
#define GUESTFS_INTERNAL_TEST_OSTRINGLIST 4
extern GUESTFS_DLL_PUBLIC int guestfs_internal_test (guestfs_h *g, const char *str, const char *optstr, char *const *strlist, int b, int integer, int64_t integer64, const char *filein, const char *fileout, const char *bufferin, size_t bufferin_size, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_va (guestfs_h *g, const char *str, const char *optstr, char *const *strlist, int b, int integer, int64_t integer64, const char *filein, const char *fileout, const char *bufferin, size_t bufferin_size, va_list args);

struct guestfs_internal_test_argv {
  uint64_t bitmask;
# define GUESTFS_INTERNAL_TEST_OBOOL_BITMASK (UINT64_C(1)<<0)
  int obool;
# define GUESTFS_INTERNAL_TEST_OINT_BITMASK (UINT64_C(1)<<1)
  int oint;
# define GUESTFS_INTERNAL_TEST_OINT64_BITMASK (UINT64_C(1)<<2)
  int64_t oint64;
# define GUESTFS_INTERNAL_TEST_OSTRING_BITMASK (UINT64_C(1)<<3)
  const char *ostring;
# define GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK (UINT64_C(1)<<4)
  char *const *ostringlist;
};

extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_argv (guestfs_h *g, const char *str, const char *optstr, char *const *strlist, int b, int integer, int64_t integer64, const char *filein, const char *fileout, const char *bufferin, size_t bufferin_size, const struct guestfs_internal_test_argv *optargs);

#define GUESTFS_HAVE_INTERNAL_TEST_63_OPTARGS 1
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1 0
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2 1
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3 2
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4 3
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5 4
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6 5
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7 6
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8 7
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9 8
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10 9
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11 10
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12 11
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13 12
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14 13
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15 14
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16 15
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17 16
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18 17
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19 18
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20 19
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21 20
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22 21
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23 22
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24 23
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25 24
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26 25
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27 26
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28 27
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29 28
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30 29
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31 30
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32 31
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33 32
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34 33
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35 34
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36 35
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37 36
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38 37
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39 38
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40 39
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41 40
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42 41
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43 42
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44 43
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45 44
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46 45
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47 46
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48 47
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49 48
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50 49
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51 50
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52 51
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53 52
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54 53
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55 54
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56 55
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57 56
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58 57
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59 58
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60 59
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61 60
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62 61
#define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63 62
extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_63_optargs (guestfs_h *g, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_63_optargs_va (guestfs_h *g, va_list args);

struct guestfs_internal_test_63_optargs_argv {
  uint64_t bitmask;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1_BITMASK (UINT64_C(1)<<0)
  int opt1;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2_BITMASK (UINT64_C(1)<<1)
  int opt2;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3_BITMASK (UINT64_C(1)<<2)
  int opt3;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4_BITMASK (UINT64_C(1)<<3)
  int opt4;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5_BITMASK (UINT64_C(1)<<4)
  int opt5;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6_BITMASK (UINT64_C(1)<<5)
  int opt6;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7_BITMASK (UINT64_C(1)<<6)
  int opt7;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8_BITMASK (UINT64_C(1)<<7)
  int opt8;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9_BITMASK (UINT64_C(1)<<8)
  int opt9;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10_BITMASK (UINT64_C(1)<<9)
  int opt10;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11_BITMASK (UINT64_C(1)<<10)
  int opt11;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12_BITMASK (UINT64_C(1)<<11)
  int opt12;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13_BITMASK (UINT64_C(1)<<12)
  int opt13;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14_BITMASK (UINT64_C(1)<<13)
  int opt14;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15_BITMASK (UINT64_C(1)<<14)
  int opt15;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16_BITMASK (UINT64_C(1)<<15)
  int opt16;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17_BITMASK (UINT64_C(1)<<16)
  int opt17;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18_BITMASK (UINT64_C(1)<<17)
  int opt18;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19_BITMASK (UINT64_C(1)<<18)
  int opt19;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20_BITMASK (UINT64_C(1)<<19)
  int opt20;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21_BITMASK (UINT64_C(1)<<20)
  int opt21;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22_BITMASK (UINT64_C(1)<<21)
  int opt22;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23_BITMASK (UINT64_C(1)<<22)
  int opt23;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24_BITMASK (UINT64_C(1)<<23)
  int opt24;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25_BITMASK (UINT64_C(1)<<24)
  int opt25;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26_BITMASK (UINT64_C(1)<<25)
  int opt26;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27_BITMASK (UINT64_C(1)<<26)
  int opt27;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28_BITMASK (UINT64_C(1)<<27)
  int opt28;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29_BITMASK (UINT64_C(1)<<28)
  int opt29;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30_BITMASK (UINT64_C(1)<<29)
  int opt30;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31_BITMASK (UINT64_C(1)<<30)
  int opt31;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32_BITMASK (UINT64_C(1)<<31)
  int opt32;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33_BITMASK (UINT64_C(1)<<32)
  int opt33;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34_BITMASK (UINT64_C(1)<<33)
  int opt34;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35_BITMASK (UINT64_C(1)<<34)
  int opt35;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36_BITMASK (UINT64_C(1)<<35)
  int opt36;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37_BITMASK (UINT64_C(1)<<36)
  int opt37;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38_BITMASK (UINT64_C(1)<<37)
  int opt38;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39_BITMASK (UINT64_C(1)<<38)
  int opt39;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40_BITMASK (UINT64_C(1)<<39)
  int opt40;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41_BITMASK (UINT64_C(1)<<40)
  int opt41;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42_BITMASK (UINT64_C(1)<<41)
  int opt42;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43_BITMASK (UINT64_C(1)<<42)
  int opt43;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44_BITMASK (UINT64_C(1)<<43)
  int opt44;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45_BITMASK (UINT64_C(1)<<44)
  int opt45;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46_BITMASK (UINT64_C(1)<<45)
  int opt46;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47_BITMASK (UINT64_C(1)<<46)
  int opt47;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48_BITMASK (UINT64_C(1)<<47)
  int opt48;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49_BITMASK (UINT64_C(1)<<48)
  int opt49;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50_BITMASK (UINT64_C(1)<<49)
  int opt50;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51_BITMASK (UINT64_C(1)<<50)
  int opt51;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52_BITMASK (UINT64_C(1)<<51)
  int opt52;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53_BITMASK (UINT64_C(1)<<52)
  int opt53;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54_BITMASK (UINT64_C(1)<<53)
  int opt54;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55_BITMASK (UINT64_C(1)<<54)
  int opt55;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56_BITMASK (UINT64_C(1)<<55)
  int opt56;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57_BITMASK (UINT64_C(1)<<56)
  int opt57;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58_BITMASK (UINT64_C(1)<<57)
  int opt58;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59_BITMASK (UINT64_C(1)<<58)
  int opt59;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60_BITMASK (UINT64_C(1)<<59)
  int opt60;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61_BITMASK (UINT64_C(1)<<60)
  int opt61;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62_BITMASK (UINT64_C(1)<<61)
  int opt62;
# define GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63_BITMASK (UINT64_C(1)<<62)
  int opt63;
};

extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_63_optargs_argv (guestfs_h *g, const struct guestfs_internal_test_63_optargs_argv *optargs);

#define GUESTFS_HAVE_INTERNAL_TEST_CLOSE_OUTPUT 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_close_output (guestfs_h *g);

#define GUESTFS_HAVE_INTERNAL_TEST_ONLY_OPTARGS 1
#define GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST 0
extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_only_optargs (guestfs_h *g, ...);
extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_only_optargs_va (guestfs_h *g, va_list args);

struct guestfs_internal_test_only_optargs_argv {
  uint64_t bitmask;
# define GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST_BITMASK (UINT64_C(1)<<0)
  int test;
};

extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_only_optargs_argv (guestfs_h *g, const struct guestfs_internal_test_only_optargs_argv *optargs);

#define GUESTFS_HAVE_INTERNAL_TEST_RBOOL 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_rbool (guestfs_h *g, const char *val);

#define GUESTFS_HAVE_INTERNAL_TEST_RBOOLERR 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_rboolerr (guestfs_h *g);

#define GUESTFS_HAVE_INTERNAL_TEST_RBUFFEROUT 1
extern GUESTFS_DLL_PUBLIC char *guestfs_internal_test_rbufferout (guestfs_h *g, const char *val, size_t *size_r);

#define GUESTFS_HAVE_INTERNAL_TEST_RBUFFEROUTERR 1
extern GUESTFS_DLL_PUBLIC char *guestfs_internal_test_rbufferouterr (guestfs_h *g, size_t *size_r);

#define GUESTFS_HAVE_INTERNAL_TEST_RCONSTOPTSTRING 1
extern GUESTFS_DLL_PUBLIC const char *guestfs_internal_test_rconstoptstring (guestfs_h *g, const char *val);

#define GUESTFS_HAVE_INTERNAL_TEST_RCONSTOPTSTRINGERR 1
extern GUESTFS_DLL_PUBLIC const char *guestfs_internal_test_rconstoptstringerr (guestfs_h *g);

#define GUESTFS_HAVE_INTERNAL_TEST_RCONSTSTRING 1
extern GUESTFS_DLL_PUBLIC const char *guestfs_internal_test_rconststring (guestfs_h *g, const char *val);

#define GUESTFS_HAVE_INTERNAL_TEST_RCONSTSTRINGERR 1
extern GUESTFS_DLL_PUBLIC const char *guestfs_internal_test_rconststringerr (guestfs_h *g);

#define GUESTFS_HAVE_INTERNAL_TEST_RHASHTABLE 1
extern GUESTFS_DLL_PUBLIC char **guestfs_internal_test_rhashtable (guestfs_h *g, const char *val);

#define GUESTFS_HAVE_INTERNAL_TEST_RHASHTABLEERR 1
extern GUESTFS_DLL_PUBLIC char **guestfs_internal_test_rhashtableerr (guestfs_h *g);

#define GUESTFS_HAVE_INTERNAL_TEST_RINT 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_rint (guestfs_h *g, const char *val);

#define GUESTFS_HAVE_INTERNAL_TEST_RINT64 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_internal_test_rint64 (guestfs_h *g, const char *val);

#define GUESTFS_HAVE_INTERNAL_TEST_RINT64ERR 1
extern GUESTFS_DLL_PUBLIC int64_t guestfs_internal_test_rint64err (guestfs_h *g);

#define GUESTFS_HAVE_INTERNAL_TEST_RINTERR 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_rinterr (guestfs_h *g);

#define GUESTFS_HAVE_INTERNAL_TEST_RSTRING 1
extern GUESTFS_DLL_PUBLIC char *guestfs_internal_test_rstring (guestfs_h *g, const char *val);

#define GUESTFS_HAVE_INTERNAL_TEST_RSTRINGERR 1
extern GUESTFS_DLL_PUBLIC char *guestfs_internal_test_rstringerr (guestfs_h *g);

#define GUESTFS_HAVE_INTERNAL_TEST_RSTRINGLIST 1
extern GUESTFS_DLL_PUBLIC char **guestfs_internal_test_rstringlist (guestfs_h *g, const char *val);

#define GUESTFS_HAVE_INTERNAL_TEST_RSTRINGLISTERR 1
extern GUESTFS_DLL_PUBLIC char **guestfs_internal_test_rstringlisterr (guestfs_h *g);

#define GUESTFS_HAVE_INTERNAL_TEST_RSTRUCT 1
extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv *guestfs_internal_test_rstruct (guestfs_h *g, const char *val);

#define GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTERR 1
extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv *guestfs_internal_test_rstructerr (guestfs_h *g);

#define GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTLIST 1
extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv_list *guestfs_internal_test_rstructlist (guestfs_h *g, const char *val);

#define GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTLISTERR 1
extern GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv_list *guestfs_internal_test_rstructlisterr (guestfs_h *g);

#define GUESTFS_HAVE_INTERNAL_TEST_SET_OUTPUT 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_test_set_output (guestfs_h *g, const char *filename);

#define GUESTFS_HAVE_INTERNAL_UPLOAD 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_upload (guestfs_h *g, const char *filename, const char *tmpname, int mode);

#define GUESTFS_HAVE_INTERNAL_WRITE 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_write (guestfs_h *g, const char *path, const char *content, size_t content_size);

#define GUESTFS_HAVE_INTERNAL_WRITE_APPEND 1
extern GUESTFS_DLL_PUBLIC int guestfs_internal_write_append (guestfs_h *g, const char *path, const char *content, size_t content_size);

/* Private structures. */

#define GUESTFS_HAVE_STRUCT_INTERNAL_MOUNTABLE 1

struct guestfs_internal_mountable {
  int32_t im_type;
  char *im_device;
  char *im_volume;
};

struct guestfs_internal_mountable_list {
  uint32_t len;
  struct guestfs_internal_mountable *val;
};

extern GUESTFS_DLL_PUBLIC int guestfs_compare_internal_mountable (const struct guestfs_internal_mountable *, const struct guestfs_internal_mountable *);
extern GUESTFS_DLL_PUBLIC int guestfs_compare_internal_mountable_list (const struct guestfs_internal_mountable_list *, const struct guestfs_internal_mountable_list *);

extern GUESTFS_DLL_PUBLIC struct guestfs_internal_mountable *guestfs_copy_internal_mountable (const struct guestfs_internal_mountable *);
extern GUESTFS_DLL_PUBLIC struct guestfs_internal_mountable_list *guestfs_copy_internal_mountable_list (const struct guestfs_internal_mountable_list *);

extern GUESTFS_DLL_PUBLIC void guestfs_free_internal_mountable (struct guestfs_internal_mountable *);
extern GUESTFS_DLL_PUBLIC void guestfs_free_internal_mountable_list (struct guestfs_internal_mountable_list *);


#endif /* End of GUESTFS_PRIVATE. */

/* Deprecated macros.  Use GUESTFS_HAVE_* instead. */

#define LIBGUESTFS_HAVE_CREATE_FLAGS 1
#define LIBGUESTFS_HAVE_LAST_ERRNO 1
#define LIBGUESTFS_HAVE_PUSH_ERROR_HANDLER 1
#define LIBGUESTFS_HAVE_POP_ERROR_HANDLER 1
#define LIBGUESTFS_HAVE_SET_EVENT_CALLBACK 1
#define LIBGUESTFS_HAVE_DELETE_EVENT_CALLBACK 1
#define LIBGUESTFS_HAVE_SET_CLOSE_CALLBACK 1
#define LIBGUESTFS_HAVE_SET_PROGRESS_CALLBACK 1
#define LIBGUESTFS_HAVE_SET_PRIVATE 1
#define LIBGUESTFS_HAVE_GET_PRIVATE 1
#define LIBGUESTFS_HAVE_FIRST_PRIVATE 1
#define LIBGUESTFS_HAVE_NEXT_PRIVATE 1

#define LIBGUESTFS_HAVE_ACL_DELETE_DEF_FILE 1
#define LIBGUESTFS_HAVE_ACL_GET_FILE 1
#define LIBGUESTFS_HAVE_ACL_SET_FILE 1
#define LIBGUESTFS_HAVE_ADD_CDROM 1
#define LIBGUESTFS_HAVE_ADD_DOMAIN 1
#define LIBGUESTFS_HAVE_ADD_DRIVE 1
#define LIBGUESTFS_HAVE_ADD_DRIVE_RO 1
#define LIBGUESTFS_HAVE_ADD_DRIVE_RO_WITH_IF 1
#define LIBGUESTFS_HAVE_ADD_DRIVE_SCRATCH 1
#define LIBGUESTFS_HAVE_ADD_DRIVE_WITH_IF 1
#define LIBGUESTFS_HAVE_ADD_LIBVIRT_DOM 1
#define LIBGUESTFS_HAVE_AUG_CLEAR 1
#define LIBGUESTFS_HAVE_AUG_CLOSE 1
#define LIBGUESTFS_HAVE_AUG_DEFNODE 1
#define LIBGUESTFS_HAVE_AUG_DEFVAR 1
#define LIBGUESTFS_HAVE_AUG_GET 1
#define LIBGUESTFS_HAVE_AUG_INIT 1
#define LIBGUESTFS_HAVE_AUG_INSERT 1
#define LIBGUESTFS_HAVE_AUG_LABEL 1
#define LIBGUESTFS_HAVE_AUG_LOAD 1
#define LIBGUESTFS_HAVE_AUG_LS 1
#define LIBGUESTFS_HAVE_AUG_MATCH 1
#define LIBGUESTFS_HAVE_AUG_MV 1
#define LIBGUESTFS_HAVE_AUG_RM 1
#define LIBGUESTFS_HAVE_AUG_SAVE 1
#define LIBGUESTFS_HAVE_AUG_SET 1
#define LIBGUESTFS_HAVE_AUG_SETM 1
#define LIBGUESTFS_HAVE_AUG_TRANSFORM 1
#define LIBGUESTFS_HAVE_AVAILABLE 1
#define LIBGUESTFS_HAVE_AVAILABLE_ALL_GROUPS 1
#define LIBGUESTFS_HAVE_BASE64_IN 1
#define LIBGUESTFS_HAVE_BASE64_OUT 1
#define LIBGUESTFS_HAVE_BLKDISCARD 1
#define LIBGUESTFS_HAVE_BLKDISCARDZEROES 1
#define LIBGUESTFS_HAVE_BLKID 1
#define LIBGUESTFS_HAVE_BLOCKDEV_FLUSHBUFS 1
#define LIBGUESTFS_HAVE_BLOCKDEV_GETBSZ 1
#define LIBGUESTFS_HAVE_BLOCKDEV_GETRO 1
#define LIBGUESTFS_HAVE_BLOCKDEV_GETSIZE64 1
#define LIBGUESTFS_HAVE_BLOCKDEV_GETSS 1
#define LIBGUESTFS_HAVE_BLOCKDEV_GETSZ 1
#define LIBGUESTFS_HAVE_BLOCKDEV_REREADPT 1
#define LIBGUESTFS_HAVE_BLOCKDEV_SETBSZ 1
#define LIBGUESTFS_HAVE_BLOCKDEV_SETRA 1
#define LIBGUESTFS_HAVE_BLOCKDEV_SETRO 1
#define LIBGUESTFS_HAVE_BLOCKDEV_SETRW 1
#define LIBGUESTFS_HAVE_BTRFS_BALANCE_CANCEL 1
#define LIBGUESTFS_HAVE_BTRFS_BALANCE_PAUSE 1
#define LIBGUESTFS_HAVE_BTRFS_BALANCE_RESUME 1
#define LIBGUESTFS_HAVE_BTRFS_BALANCE_STATUS 1
#define LIBGUESTFS_HAVE_BTRFS_DEVICE_ADD 1
#define LIBGUESTFS_HAVE_BTRFS_DEVICE_DELETE 1
#define LIBGUESTFS_HAVE_BTRFS_FILESYSTEM_BALANCE 1
#define LIBGUESTFS_HAVE_BTRFS_FILESYSTEM_DEFRAGMENT 1
#define LIBGUESTFS_HAVE_BTRFS_FILESYSTEM_RESIZE 1
#define LIBGUESTFS_HAVE_BTRFS_FILESYSTEM_SHOW 1
#define LIBGUESTFS_HAVE_BTRFS_FILESYSTEM_SYNC 1
#define LIBGUESTFS_HAVE_BTRFS_FSCK 1
#define LIBGUESTFS_HAVE_BTRFS_IMAGE 1
#define LIBGUESTFS_HAVE_BTRFS_QGROUP_ASSIGN 1
#define LIBGUESTFS_HAVE_BTRFS_QGROUP_CREATE 1
#define LIBGUESTFS_HAVE_BTRFS_QGROUP_DESTROY 1
#define LIBGUESTFS_HAVE_BTRFS_QGROUP_LIMIT 1
#define LIBGUESTFS_HAVE_BTRFS_QGROUP_REMOVE 1
#define LIBGUESTFS_HAVE_BTRFS_QGROUP_SHOW 1
#define LIBGUESTFS_HAVE_BTRFS_QUOTA_ENABLE 1
#define LIBGUESTFS_HAVE_BTRFS_QUOTA_RESCAN 1
#define LIBGUESTFS_HAVE_BTRFS_REPLACE 1
#define LIBGUESTFS_HAVE_BTRFS_RESCUE_CHUNK_RECOVER 1
#define LIBGUESTFS_HAVE_BTRFS_RESCUE_SUPER_RECOVER 1
#define LIBGUESTFS_HAVE_BTRFS_SCRUB_CANCEL 1
#define LIBGUESTFS_HAVE_BTRFS_SCRUB_RESUME 1
#define LIBGUESTFS_HAVE_BTRFS_SCRUB_START 1
#define LIBGUESTFS_HAVE_BTRFS_SCRUB_STATUS 1
#define LIBGUESTFS_HAVE_BTRFS_SET_SEEDING 1
#define LIBGUESTFS_HAVE_BTRFS_SUBVOLUME_CREATE 1
#define LIBGUESTFS_HAVE_BTRFS_SUBVOLUME_DELETE 1
#define LIBGUESTFS_HAVE_BTRFS_SUBVOLUME_GET_DEFAULT 1
#define LIBGUESTFS_HAVE_BTRFS_SUBVOLUME_LIST 1
#define LIBGUESTFS_HAVE_BTRFS_SUBVOLUME_SET_DEFAULT 1
#define LIBGUESTFS_HAVE_BTRFS_SUBVOLUME_SHOW 1
#define LIBGUESTFS_HAVE_BTRFS_SUBVOLUME_SNAPSHOT 1
#define LIBGUESTFS_HAVE_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS 1
#define LIBGUESTFS_HAVE_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS 1
#define LIBGUESTFS_HAVE_BTRFSTUNE_SEEDING 1
#define LIBGUESTFS_HAVE_C_POINTER 1
#define LIBGUESTFS_HAVE_CANONICAL_DEVICE_NAME 1
#define LIBGUESTFS_HAVE_CAP_GET_FILE 1
#define LIBGUESTFS_HAVE_CAP_SET_FILE 1
#define LIBGUESTFS_HAVE_CASE_SENSITIVE_PATH 1
#define LIBGUESTFS_HAVE_CAT 1
#define LIBGUESTFS_HAVE_CHECKSUM 1
#define LIBGUESTFS_HAVE_CHECKSUM_DEVICE 1
#define LIBGUESTFS_HAVE_CHECKSUMS_OUT 1
#define LIBGUESTFS_HAVE_CHMOD 1
#define LIBGUESTFS_HAVE_CHOWN 1
#define LIBGUESTFS_HAVE_CLEAR_BACKEND_SETTING 1
#define LIBGUESTFS_HAVE_COMMAND 1
#define LIBGUESTFS_HAVE_COMMAND_LINES 1
#define LIBGUESTFS_HAVE_COMPRESS_DEVICE_OUT 1
#define LIBGUESTFS_HAVE_COMPRESS_OUT 1
#define LIBGUESTFS_HAVE_CONFIG 1
#define LIBGUESTFS_HAVE_COPY_ATTRIBUTES 1
#define LIBGUESTFS_HAVE_COPY_DEVICE_TO_DEVICE 1
#define LIBGUESTFS_HAVE_COPY_DEVICE_TO_FILE 1
#define LIBGUESTFS_HAVE_COPY_FILE_TO_DEVICE 1
#define LIBGUESTFS_HAVE_COPY_FILE_TO_FILE 1
#define LIBGUESTFS_HAVE_COPY_IN 1
#define LIBGUESTFS_HAVE_COPY_OUT 1
#define LIBGUESTFS_HAVE_COPY_SIZE 1
#define LIBGUESTFS_HAVE_CP 1
#define LIBGUESTFS_HAVE_CP_A 1
#define LIBGUESTFS_HAVE_CP_R 1
#define LIBGUESTFS_HAVE_CPIO_OUT 1
#define LIBGUESTFS_HAVE_DD 1
#define LIBGUESTFS_HAVE_DEBUG 1
#define LIBGUESTFS_HAVE_DEBUG_DRIVES 1
#define LIBGUESTFS_HAVE_DEBUG_UPLOAD 1
#define LIBGUESTFS_HAVE_DEVICE_INDEX 1
#define LIBGUESTFS_HAVE_DF 1
#define LIBGUESTFS_HAVE_DF_H 1
#define LIBGUESTFS_HAVE_DISK_CREATE 1
#define LIBGUESTFS_HAVE_DISK_FORMAT 1
#define LIBGUESTFS_HAVE_DISK_HAS_BACKING_FILE 1
#define LIBGUESTFS_HAVE_DISK_VIRTUAL_SIZE 1
#define LIBGUESTFS_HAVE_DMESG 1
#define LIBGUESTFS_HAVE_DOWNLOAD 1
#define LIBGUESTFS_HAVE_DOWNLOAD_BLOCKS 1
#define LIBGUESTFS_HAVE_DOWNLOAD_INODE 1
#define LIBGUESTFS_HAVE_DOWNLOAD_OFFSET 1
#define LIBGUESTFS_HAVE_DROP_CACHES 1
#define LIBGUESTFS_HAVE_DU 1
#define LIBGUESTFS_HAVE_E2FSCK 1
#define LIBGUESTFS_HAVE_E2FSCK_F 1
#define LIBGUESTFS_HAVE_ECHO_DAEMON 1
#define LIBGUESTFS_HAVE_EGREP 1
#define LIBGUESTFS_HAVE_EGREPI 1
#define LIBGUESTFS_HAVE_EQUAL 1
#define LIBGUESTFS_HAVE_EXISTS 1
#define LIBGUESTFS_HAVE_EXTLINUX 1
#define LIBGUESTFS_HAVE_FALLOCATE 1
#define LIBGUESTFS_HAVE_FALLOCATE64 1
#define LIBGUESTFS_HAVE_FEATURE_AVAILABLE 1
#define LIBGUESTFS_HAVE_FGREP 1
#define LIBGUESTFS_HAVE_FGREPI 1
#define LIBGUESTFS_HAVE_FILE 1
#define LIBGUESTFS_HAVE_FILE_ARCHITECTURE 1
#define LIBGUESTFS_HAVE_FILESIZE 1
#define LIBGUESTFS_HAVE_FILESYSTEM_AVAILABLE 1
#define LIBGUESTFS_HAVE_FILESYSTEM_WALK 1
#define LIBGUESTFS_HAVE_FILL 1
#define LIBGUESTFS_HAVE_FILL_DIR 1
#define LIBGUESTFS_HAVE_FILL_PATTERN 1
#define LIBGUESTFS_HAVE_FIND 1
#define LIBGUESTFS_HAVE_FIND0 1
#define LIBGUESTFS_HAVE_FIND_INODE 1
#define LIBGUESTFS_HAVE_FINDFS_LABEL 1
#define LIBGUESTFS_HAVE_FINDFS_UUID 1
#define LIBGUESTFS_HAVE_FSCK 1
#define LIBGUESTFS_HAVE_FSTRIM 1
#define LIBGUESTFS_HAVE_GET_APPEND 1
#define LIBGUESTFS_HAVE_GET_ATTACH_METHOD 1
#define LIBGUESTFS_HAVE_GET_AUTOSYNC 1
#define LIBGUESTFS_HAVE_GET_BACKEND 1
#define LIBGUESTFS_HAVE_GET_BACKEND_SETTING 1
#define LIBGUESTFS_HAVE_GET_BACKEND_SETTINGS 1
#define LIBGUESTFS_HAVE_GET_CACHEDIR 1
#define LIBGUESTFS_HAVE_GET_DIRECT 1
#define LIBGUESTFS_HAVE_GET_E2ATTRS 1
#define LIBGUESTFS_HAVE_GET_E2GENERATION 1
#define LIBGUESTFS_HAVE_GET_E2LABEL 1
#define LIBGUESTFS_HAVE_GET_E2UUID 1
#define LIBGUESTFS_HAVE_GET_HV 1
#define LIBGUESTFS_HAVE_GET_IDENTIFIER 1
#define LIBGUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_CHALLENGE 1
#define LIBGUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_DEFRESULT 1
#define LIBGUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_PROMPT 1
#define LIBGUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIALS 1
#define LIBGUESTFS_HAVE_GET_MEMSIZE 1
#define LIBGUESTFS_HAVE_GET_NETWORK 1
#define LIBGUESTFS_HAVE_GET_PATH 1
#define LIBGUESTFS_HAVE_GET_PGROUP 1
#define LIBGUESTFS_HAVE_GET_PID 1
#define LIBGUESTFS_HAVE_GET_PROGRAM 1
#define LIBGUESTFS_HAVE_GET_QEMU 1
#define LIBGUESTFS_HAVE_GET_RECOVERY_PROC 1
#define LIBGUESTFS_HAVE_GET_SELINUX 1
#define LIBGUESTFS_HAVE_GET_SMP 1
#define LIBGUESTFS_HAVE_GET_SOCKDIR 1
#define LIBGUESTFS_HAVE_GET_STATE 1
#define LIBGUESTFS_HAVE_GET_TMPDIR 1
#define LIBGUESTFS_HAVE_GET_TRACE 1
#define LIBGUESTFS_HAVE_GET_UMASK 1
#define LIBGUESTFS_HAVE_GET_VERBOSE 1
#define LIBGUESTFS_HAVE_GETCON 1
#define LIBGUESTFS_HAVE_GETXATTR 1
#define LIBGUESTFS_HAVE_GETXATTRS 1
#define LIBGUESTFS_HAVE_GLOB_EXPAND 1
#define LIBGUESTFS_HAVE_GREP 1
#define LIBGUESTFS_HAVE_GREPI 1
#define LIBGUESTFS_HAVE_GRUB_INSTALL 1
#define LIBGUESTFS_HAVE_HEAD 1
#define LIBGUESTFS_HAVE_HEAD_N 1
#define LIBGUESTFS_HAVE_HEXDUMP 1
#define LIBGUESTFS_HAVE_HIVEX_CLOSE 1
#define LIBGUESTFS_HAVE_HIVEX_COMMIT 1
#define LIBGUESTFS_HAVE_HIVEX_NODE_ADD_CHILD 1
#define LIBGUESTFS_HAVE_HIVEX_NODE_CHILDREN 1
#define LIBGUESTFS_HAVE_HIVEX_NODE_DELETE_CHILD 1
#define LIBGUESTFS_HAVE_HIVEX_NODE_GET_CHILD 1
#define LIBGUESTFS_HAVE_HIVEX_NODE_GET_VALUE 1
#define LIBGUESTFS_HAVE_HIVEX_NODE_NAME 1
#define LIBGUESTFS_HAVE_HIVEX_NODE_PARENT 1
#define LIBGUESTFS_HAVE_HIVEX_NODE_SET_VALUE 1
#define LIBGUESTFS_HAVE_HIVEX_NODE_VALUES 1
#define LIBGUESTFS_HAVE_HIVEX_OPEN 1
#define LIBGUESTFS_HAVE_HIVEX_ROOT 1
#define LIBGUESTFS_HAVE_HIVEX_VALUE_KEY 1
#define LIBGUESTFS_HAVE_HIVEX_VALUE_TYPE 1
#define LIBGUESTFS_HAVE_HIVEX_VALUE_UTF8 1
#define LIBGUESTFS_HAVE_HIVEX_VALUE_VALUE 1
#define LIBGUESTFS_HAVE_INITRD_CAT 1
#define LIBGUESTFS_HAVE_INITRD_LIST 1
#define LIBGUESTFS_HAVE_INOTIFY_ADD_WATCH 1
#define LIBGUESTFS_HAVE_INOTIFY_CLOSE 1
#define LIBGUESTFS_HAVE_INOTIFY_FILES 1
#define LIBGUESTFS_HAVE_INOTIFY_INIT 1
#define LIBGUESTFS_HAVE_INOTIFY_READ 1
#define LIBGUESTFS_HAVE_INOTIFY_RM_WATCH 1
#define LIBGUESTFS_HAVE_INSPECT_GET_ARCH 1
#define LIBGUESTFS_HAVE_INSPECT_GET_DISTRO 1
#define LIBGUESTFS_HAVE_INSPECT_GET_DRIVE_MAPPINGS 1
#define LIBGUESTFS_HAVE_INSPECT_GET_FILESYSTEMS 1
#define LIBGUESTFS_HAVE_INSPECT_GET_FORMAT 1
#define LIBGUESTFS_HAVE_INSPECT_GET_HOSTNAME 1
#define LIBGUESTFS_HAVE_INSPECT_GET_ICON 1
#define LIBGUESTFS_HAVE_INSPECT_GET_MAJOR_VERSION 1
#define LIBGUESTFS_HAVE_INSPECT_GET_MINOR_VERSION 1
#define LIBGUESTFS_HAVE_INSPECT_GET_MOUNTPOINTS 1
#define LIBGUESTFS_HAVE_INSPECT_GET_PACKAGE_FORMAT 1
#define LIBGUESTFS_HAVE_INSPECT_GET_PACKAGE_MANAGEMENT 1
#define LIBGUESTFS_HAVE_INSPECT_GET_PRODUCT_NAME 1
#define LIBGUESTFS_HAVE_INSPECT_GET_PRODUCT_VARIANT 1
#define LIBGUESTFS_HAVE_INSPECT_GET_ROOTS 1
#define LIBGUESTFS_HAVE_INSPECT_GET_TYPE 1
#define LIBGUESTFS_HAVE_INSPECT_GET_WINDOWS_CURRENT_CONTROL_SET 1
#define LIBGUESTFS_HAVE_INSPECT_GET_WINDOWS_SOFTWARE_HIVE 1
#define LIBGUESTFS_HAVE_INSPECT_GET_WINDOWS_SYSTEM_HIVE 1
#define LIBGUESTFS_HAVE_INSPECT_GET_WINDOWS_SYSTEMROOT 1
#define LIBGUESTFS_HAVE_INSPECT_IS_LIVE 1
#define LIBGUESTFS_HAVE_INSPECT_IS_MULTIPART 1
#define LIBGUESTFS_HAVE_INSPECT_IS_NETINST 1
#define LIBGUESTFS_HAVE_INSPECT_LIST_APPLICATIONS 1
#define LIBGUESTFS_HAVE_INSPECT_LIST_APPLICATIONS2 1
#define LIBGUESTFS_HAVE_INSPECT_OS 1
#define LIBGUESTFS_HAVE_INTERNAL_EXIT 1
#define LIBGUESTFS_HAVE_IS_BLOCKDEV 1
#define LIBGUESTFS_HAVE_IS_BUSY 1
#define LIBGUESTFS_HAVE_IS_CHARDEV 1
#define LIBGUESTFS_HAVE_IS_CONFIG 1
#define LIBGUESTFS_HAVE_IS_DIR 1
#define LIBGUESTFS_HAVE_IS_FIFO 1
#define LIBGUESTFS_HAVE_IS_FILE 1
#define LIBGUESTFS_HAVE_IS_LAUNCHING 1
#define LIBGUESTFS_HAVE_IS_LV 1
#define LIBGUESTFS_HAVE_IS_READY 1
#define LIBGUESTFS_HAVE_IS_SOCKET 1
#define LIBGUESTFS_HAVE_IS_SYMLINK 1
#define LIBGUESTFS_HAVE_IS_WHOLE_DEVICE 1
#define LIBGUESTFS_HAVE_IS_ZERO 1
#define LIBGUESTFS_HAVE_IS_ZERO_DEVICE 1
#define LIBGUESTFS_HAVE_ISOINFO 1
#define LIBGUESTFS_HAVE_ISOINFO_DEVICE 1
#define LIBGUESTFS_HAVE_JOURNAL_CLOSE 1
#define LIBGUESTFS_HAVE_JOURNAL_GET 1
#define LIBGUESTFS_HAVE_JOURNAL_GET_DATA_THRESHOLD 1
#define LIBGUESTFS_HAVE_JOURNAL_GET_REALTIME_USEC 1
#define LIBGUESTFS_HAVE_JOURNAL_NEXT 1
#define LIBGUESTFS_HAVE_JOURNAL_OPEN 1
#define LIBGUESTFS_HAVE_JOURNAL_SET_DATA_THRESHOLD 1
#define LIBGUESTFS_HAVE_JOURNAL_SKIP 1
#define LIBGUESTFS_HAVE_KILL_SUBPROCESS 1
#define LIBGUESTFS_HAVE_LAUNCH 1
#define LIBGUESTFS_HAVE_LCHOWN 1
#define LIBGUESTFS_HAVE_LDMTOOL_CREATE_ALL 1
#define LIBGUESTFS_HAVE_LDMTOOL_DISKGROUP_DISKS 1
#define LIBGUESTFS_HAVE_LDMTOOL_DISKGROUP_NAME 1
#define LIBGUESTFS_HAVE_LDMTOOL_DISKGROUP_VOLUMES 1
#define LIBGUESTFS_HAVE_LDMTOOL_REMOVE_ALL 1
#define LIBGUESTFS_HAVE_LDMTOOL_SCAN 1
#define LIBGUESTFS_HAVE_LDMTOOL_SCAN_DEVICES 1
#define LIBGUESTFS_HAVE_LDMTOOL_VOLUME_HINT 1
#define LIBGUESTFS_HAVE_LDMTOOL_VOLUME_PARTITIONS 1
#define LIBGUESTFS_HAVE_LDMTOOL_VOLUME_TYPE 1
#define LIBGUESTFS_HAVE_LGETXATTR 1
#define LIBGUESTFS_HAVE_LGETXATTRS 1
#define LIBGUESTFS_HAVE_LIST_9P 1
#define LIBGUESTFS_HAVE_LIST_DEVICES 1
#define LIBGUESTFS_HAVE_LIST_DISK_LABELS 1
#define LIBGUESTFS_HAVE_LIST_DM_DEVICES 1
#define LIBGUESTFS_HAVE_LIST_FILESYSTEMS 1
#define LIBGUESTFS_HAVE_LIST_LDM_PARTITIONS 1
#define LIBGUESTFS_HAVE_LIST_LDM_VOLUMES 1
#define LIBGUESTFS_HAVE_LIST_MD_DEVICES 1
#define LIBGUESTFS_HAVE_LIST_PARTITIONS 1
#define LIBGUESTFS_HAVE_LL 1
#define LIBGUESTFS_HAVE_LLZ 1
#define LIBGUESTFS_HAVE_LN 1
#define LIBGUESTFS_HAVE_LN_F 1
#define LIBGUESTFS_HAVE_LN_S 1
#define LIBGUESTFS_HAVE_LN_SF 1
#define LIBGUESTFS_HAVE_LREMOVEXATTR 1
#define LIBGUESTFS_HAVE_LS 1
#define LIBGUESTFS_HAVE_LS0 1
#define LIBGUESTFS_HAVE_LSETXATTR 1
#define LIBGUESTFS_HAVE_LSTAT 1
#define LIBGUESTFS_HAVE_LSTATLIST 1
#define LIBGUESTFS_HAVE_LSTATNS 1
#define LIBGUESTFS_HAVE_LSTATNSLIST 1
#define LIBGUESTFS_HAVE_LUKS_ADD_KEY 1
#define LIBGUESTFS_HAVE_LUKS_CLOSE 1
#define LIBGUESTFS_HAVE_LUKS_FORMAT 1
#define LIBGUESTFS_HAVE_LUKS_FORMAT_CIPHER 1
#define LIBGUESTFS_HAVE_LUKS_KILL_SLOT 1
#define LIBGUESTFS_HAVE_LUKS_OPEN 1
#define LIBGUESTFS_HAVE_LUKS_OPEN_RO 1
#define LIBGUESTFS_HAVE_LVCREATE 1
#define LIBGUESTFS_HAVE_LVCREATE_FREE 1
#define LIBGUESTFS_HAVE_LVM_CANONICAL_LV_NAME 1
#define LIBGUESTFS_HAVE_LVM_CLEAR_FILTER 1
#define LIBGUESTFS_HAVE_LVM_REMOVE_ALL 1
#define LIBGUESTFS_HAVE_LVM_SET_FILTER 1
#define LIBGUESTFS_HAVE_LVREMOVE 1
#define LIBGUESTFS_HAVE_LVRENAME 1
#define LIBGUESTFS_HAVE_LVRESIZE 1
#define LIBGUESTFS_HAVE_LVRESIZE_FREE 1
#define LIBGUESTFS_HAVE_LVS 1
#define LIBGUESTFS_HAVE_LVS_FULL 1
#define LIBGUESTFS_HAVE_LVUUID 1
#define LIBGUESTFS_HAVE_LXATTRLIST 1
#define LIBGUESTFS_HAVE_MAX_DISKS 1
#define LIBGUESTFS_HAVE_MD_CREATE 1
#define LIBGUESTFS_HAVE_MD_DETAIL 1
#define LIBGUESTFS_HAVE_MD_STAT 1
#define LIBGUESTFS_HAVE_MD_STOP 1
#define LIBGUESTFS_HAVE_MKDIR 1
#define LIBGUESTFS_HAVE_MKDIR_MODE 1
#define LIBGUESTFS_HAVE_MKDIR_P 1
#define LIBGUESTFS_HAVE_MKDTEMP 1
#define LIBGUESTFS_HAVE_MKE2FS 1
#define LIBGUESTFS_HAVE_MKE2FS_J 1
#define LIBGUESTFS_HAVE_MKE2FS_JL 1
#define LIBGUESTFS_HAVE_MKE2FS_JU 1
#define LIBGUESTFS_HAVE_MKE2JOURNAL 1
#define LIBGUESTFS_HAVE_MKE2JOURNAL_L 1
#define LIBGUESTFS_HAVE_MKE2JOURNAL_U 1
#define LIBGUESTFS_HAVE_MKFIFO 1
#define LIBGUESTFS_HAVE_MKFS 1
#define LIBGUESTFS_HAVE_MKFS_B 1
#define LIBGUESTFS_HAVE_MKFS_BTRFS 1
#define LIBGUESTFS_HAVE_MKLOST_AND_FOUND 1
#define LIBGUESTFS_HAVE_MKMOUNTPOINT 1
#define LIBGUESTFS_HAVE_MKNOD 1
#define LIBGUESTFS_HAVE_MKNOD_B 1
#define LIBGUESTFS_HAVE_MKNOD_C 1
#define LIBGUESTFS_HAVE_MKSQUASHFS 1
#define LIBGUESTFS_HAVE_MKSWAP 1
#define LIBGUESTFS_HAVE_MKSWAP_L 1
#define LIBGUESTFS_HAVE_MKSWAP_U 1
#define LIBGUESTFS_HAVE_MKSWAP_FILE 1
#define LIBGUESTFS_HAVE_MKTEMP 1
#define LIBGUESTFS_HAVE_MODPROBE 1
#define LIBGUESTFS_HAVE_MOUNT 1
#define LIBGUESTFS_HAVE_MOUNT_9P 1
#define LIBGUESTFS_HAVE_MOUNT_LOCAL 1
#define LIBGUESTFS_HAVE_MOUNT_LOCAL_RUN 1
#define LIBGUESTFS_HAVE_MOUNT_LOOP 1
#define LIBGUESTFS_HAVE_MOUNT_OPTIONS 1
#define LIBGUESTFS_HAVE_MOUNT_RO 1
#define LIBGUESTFS_HAVE_MOUNT_VFS 1
#define LIBGUESTFS_HAVE_MOUNTABLE_DEVICE 1
#define LIBGUESTFS_HAVE_MOUNTABLE_SUBVOLUME 1
#define LIBGUESTFS_HAVE_MOUNTPOINTS 1
#define LIBGUESTFS_HAVE_MOUNTS 1
#define LIBGUESTFS_HAVE_MV 1
#define LIBGUESTFS_HAVE_NR_DEVICES 1
#define LIBGUESTFS_HAVE_NTFS_3G_PROBE 1
#define LIBGUESTFS_HAVE_NTFSCAT_I 1
#define LIBGUESTFS_HAVE_NTFSCLONE_IN 1
#define LIBGUESTFS_HAVE_NTFSCLONE_OUT 1
#define LIBGUESTFS_HAVE_NTFSFIX 1
#define LIBGUESTFS_HAVE_NTFSRESIZE 1
#define LIBGUESTFS_HAVE_NTFSRESIZE_SIZE 1
#define LIBGUESTFS_HAVE_PARSE_ENVIRONMENT 1
#define LIBGUESTFS_HAVE_PARSE_ENVIRONMENT_LIST 1
#define LIBGUESTFS_HAVE_PART_ADD 1
#define LIBGUESTFS_HAVE_PART_DEL 1
#define LIBGUESTFS_HAVE_PART_DISK 1
#define LIBGUESTFS_HAVE_PART_EXPAND_GPT 1
#define LIBGUESTFS_HAVE_PART_GET_BOOTABLE 1
#define LIBGUESTFS_HAVE_PART_GET_DISK_GUID 1
#define LIBGUESTFS_HAVE_PART_GET_GPT_GUID 1
#define LIBGUESTFS_HAVE_PART_GET_GPT_TYPE 1
#define LIBGUESTFS_HAVE_PART_GET_MBR_ID 1
#define LIBGUESTFS_HAVE_PART_GET_MBR_PART_TYPE 1
#define LIBGUESTFS_HAVE_PART_GET_NAME 1
#define LIBGUESTFS_HAVE_PART_GET_PARTTYPE 1
#define LIBGUESTFS_HAVE_PART_INIT 1
#define LIBGUESTFS_HAVE_PART_LIST 1
#define LIBGUESTFS_HAVE_PART_SET_BOOTABLE 1
#define LIBGUESTFS_HAVE_PART_SET_DISK_GUID 1
#define LIBGUESTFS_HAVE_PART_SET_DISK_GUID_RANDOM 1
#define LIBGUESTFS_HAVE_PART_SET_GPT_GUID 1
#define LIBGUESTFS_HAVE_PART_SET_GPT_TYPE 1
#define LIBGUESTFS_HAVE_PART_SET_MBR_ID 1
#define LIBGUESTFS_HAVE_PART_SET_NAME 1
#define LIBGUESTFS_HAVE_PART_TO_DEV 1
#define LIBGUESTFS_HAVE_PART_TO_PARTNUM 1
#define LIBGUESTFS_HAVE_PING_DAEMON 1
#define LIBGUESTFS_HAVE_PREAD 1
#define LIBGUESTFS_HAVE_PREAD_DEVICE 1
#define LIBGUESTFS_HAVE_PVCHANGE_UUID 1
#define LIBGUESTFS_HAVE_PVCHANGE_UUID_ALL 1
#define LIBGUESTFS_HAVE_PVCREATE 1
#define LIBGUESTFS_HAVE_PVREMOVE 1
#define LIBGUESTFS_HAVE_PVRESIZE 1
#define LIBGUESTFS_HAVE_PVRESIZE_SIZE 1
#define LIBGUESTFS_HAVE_PVS 1
#define LIBGUESTFS_HAVE_PVS_FULL 1
#define LIBGUESTFS_HAVE_PVUUID 1
#define LIBGUESTFS_HAVE_PWRITE 1
#define LIBGUESTFS_HAVE_PWRITE_DEVICE 1
#define LIBGUESTFS_HAVE_READ_FILE 1
#define LIBGUESTFS_HAVE_READ_LINES 1
#define LIBGUESTFS_HAVE_READDIR 1
#define LIBGUESTFS_HAVE_READLINK 1
#define LIBGUESTFS_HAVE_READLINKLIST 1
#define LIBGUESTFS_HAVE_REALPATH 1
#define LIBGUESTFS_HAVE_REMOUNT 1
#define LIBGUESTFS_HAVE_REMOVE_DRIVE 1
#define LIBGUESTFS_HAVE_REMOVEXATTR 1
#define LIBGUESTFS_HAVE_RENAME 1
#define LIBGUESTFS_HAVE_RESIZE2FS 1
#define LIBGUESTFS_HAVE_RESIZE2FS_M 1
#define LIBGUESTFS_HAVE_RESIZE2FS_SIZE 1
#define LIBGUESTFS_HAVE_RM 1
#define LIBGUESTFS_HAVE_RM_F 1
#define LIBGUESTFS_HAVE_RM_RF 1
#define LIBGUESTFS_HAVE_RMDIR 1
#define LIBGUESTFS_HAVE_RMMOUNTPOINT 1
#define LIBGUESTFS_HAVE_RSYNC 1
#define LIBGUESTFS_HAVE_RSYNC_IN 1
#define LIBGUESTFS_HAVE_RSYNC_OUT 1
#define LIBGUESTFS_HAVE_SCRUB_DEVICE 1
#define LIBGUESTFS_HAVE_SCRUB_FILE 1
#define LIBGUESTFS_HAVE_SCRUB_FREESPACE 1
#define LIBGUESTFS_HAVE_SELINUX_RELABEL 1
#define LIBGUESTFS_HAVE_SET_APPEND 1
#define LIBGUESTFS_HAVE_SET_ATTACH_METHOD 1
#define LIBGUESTFS_HAVE_SET_AUTOSYNC 1
#define LIBGUESTFS_HAVE_SET_BACKEND 1
#define LIBGUESTFS_HAVE_SET_BACKEND_SETTING 1
#define LIBGUESTFS_HAVE_SET_BACKEND_SETTINGS 1
#define LIBGUESTFS_HAVE_SET_CACHEDIR 1
#define LIBGUESTFS_HAVE_SET_DIRECT 1
#define LIBGUESTFS_HAVE_SET_E2ATTRS 1
#define LIBGUESTFS_HAVE_SET_E2GENERATION 1
#define LIBGUESTFS_HAVE_SET_E2LABEL 1
#define LIBGUESTFS_HAVE_SET_E2UUID 1
#define LIBGUESTFS_HAVE_SET_HV 1
#define LIBGUESTFS_HAVE_SET_IDENTIFIER 1
#define LIBGUESTFS_HAVE_SET_LABEL 1
#define LIBGUESTFS_HAVE_SET_LIBVIRT_REQUESTED_CREDENTIAL 1
#define LIBGUESTFS_HAVE_SET_LIBVIRT_SUPPORTED_CREDENTIALS 1
#define LIBGUESTFS_HAVE_SET_MEMSIZE 1
#define LIBGUESTFS_HAVE_SET_NETWORK 1
#define LIBGUESTFS_HAVE_SET_PATH 1
#define LIBGUESTFS_HAVE_SET_PGROUP 1
#define LIBGUESTFS_HAVE_SET_PROGRAM 1
#define LIBGUESTFS_HAVE_SET_QEMU 1
#define LIBGUESTFS_HAVE_SET_RECOVERY_PROC 1
#define LIBGUESTFS_HAVE_SET_SELINUX 1
#define LIBGUESTFS_HAVE_SET_SMP 1
#define LIBGUESTFS_HAVE_SET_TMPDIR 1
#define LIBGUESTFS_HAVE_SET_TRACE 1
#define LIBGUESTFS_HAVE_SET_UUID 1
#define LIBGUESTFS_HAVE_SET_UUID_RANDOM 1
#define LIBGUESTFS_HAVE_SET_VERBOSE 1
#define LIBGUESTFS_HAVE_SETCON 1
#define LIBGUESTFS_HAVE_SETXATTR 1
#define LIBGUESTFS_HAVE_SFDISK 1
#define LIBGUESTFS_HAVE_SFDISKM 1
#define LIBGUESTFS_HAVE_SFDISK_N 1
#define LIBGUESTFS_HAVE_SFDISK_DISK_GEOMETRY 1
#define LIBGUESTFS_HAVE_SFDISK_KERNEL_GEOMETRY 1
#define LIBGUESTFS_HAVE_SFDISK_L 1
#define LIBGUESTFS_HAVE_SH 1
#define LIBGUESTFS_HAVE_SH_LINES 1
#define LIBGUESTFS_HAVE_SHUTDOWN 1
#define LIBGUESTFS_HAVE_SLEEP 1
#define LIBGUESTFS_HAVE_STAT 1
#define LIBGUESTFS_HAVE_STATNS 1
#define LIBGUESTFS_HAVE_STATVFS 1
#define LIBGUESTFS_HAVE_STRINGS 1
#define LIBGUESTFS_HAVE_STRINGS_E 1
#define LIBGUESTFS_HAVE_SWAPOFF_DEVICE 1
#define LIBGUESTFS_HAVE_SWAPOFF_FILE 1
#define LIBGUESTFS_HAVE_SWAPOFF_LABEL 1
#define LIBGUESTFS_HAVE_SWAPOFF_UUID 1
#define LIBGUESTFS_HAVE_SWAPON_DEVICE 1
#define LIBGUESTFS_HAVE_SWAPON_FILE 1
#define LIBGUESTFS_HAVE_SWAPON_LABEL 1
#define LIBGUESTFS_HAVE_SWAPON_UUID 1
#define LIBGUESTFS_HAVE_SYNC 1
#define LIBGUESTFS_HAVE_SYSLINUX 1
#define LIBGUESTFS_HAVE_TAIL 1
#define LIBGUESTFS_HAVE_TAIL_N 1
#define LIBGUESTFS_HAVE_TAR_IN 1
#define LIBGUESTFS_HAVE_TAR_OUT 1
#define LIBGUESTFS_HAVE_TGZ_IN 1
#define LIBGUESTFS_HAVE_TGZ_OUT 1
#define LIBGUESTFS_HAVE_TOUCH 1
#define LIBGUESTFS_HAVE_TRUNCATE 1
#define LIBGUESTFS_HAVE_TRUNCATE_SIZE 1
#define LIBGUESTFS_HAVE_TUNE2FS 1
#define LIBGUESTFS_HAVE_TUNE2FS_L 1
#define LIBGUESTFS_HAVE_TXZ_IN 1
#define LIBGUESTFS_HAVE_TXZ_OUT 1
#define LIBGUESTFS_HAVE_UMASK 1
#define LIBGUESTFS_HAVE_UMOUNT 1
#define LIBGUESTFS_HAVE_UMOUNT_ALL 1
#define LIBGUESTFS_HAVE_UMOUNT_LOCAL 1
#define LIBGUESTFS_HAVE_UPLOAD 1
#define LIBGUESTFS_HAVE_UPLOAD_OFFSET 1
#define LIBGUESTFS_HAVE_USER_CANCEL 1
#define LIBGUESTFS_HAVE_UTIMENS 1
#define LIBGUESTFS_HAVE_UTSNAME 1
#define LIBGUESTFS_HAVE_VERSION 1
#define LIBGUESTFS_HAVE_VFS_LABEL 1
#define LIBGUESTFS_HAVE_VFS_MINIMUM_SIZE 1
#define LIBGUESTFS_HAVE_VFS_TYPE 1
#define LIBGUESTFS_HAVE_VFS_UUID 1
#define LIBGUESTFS_HAVE_VG_ACTIVATE 1
#define LIBGUESTFS_HAVE_VG_ACTIVATE_ALL 1
#define LIBGUESTFS_HAVE_VGCHANGE_UUID 1
#define LIBGUESTFS_HAVE_VGCHANGE_UUID_ALL 1
#define LIBGUESTFS_HAVE_VGCREATE 1
#define LIBGUESTFS_HAVE_VGLVUUIDS 1
#define LIBGUESTFS_HAVE_VGMETA 1
#define LIBGUESTFS_HAVE_VGPVUUIDS 1
#define LIBGUESTFS_HAVE_VGREMOVE 1
#define LIBGUESTFS_HAVE_VGRENAME 1
#define LIBGUESTFS_HAVE_VGS 1
#define LIBGUESTFS_HAVE_VGS_FULL 1
#define LIBGUESTFS_HAVE_VGSCAN 1
#define LIBGUESTFS_HAVE_VGUUID 1
#define LIBGUESTFS_HAVE_WAIT_READY 1
#define LIBGUESTFS_HAVE_WC_C 1
#define LIBGUESTFS_HAVE_WC_L 1
#define LIBGUESTFS_HAVE_WC_W 1
#define LIBGUESTFS_HAVE_WIPEFS 1
#define LIBGUESTFS_HAVE_WRITE 1
#define LIBGUESTFS_HAVE_WRITE_APPEND 1
#define LIBGUESTFS_HAVE_WRITE_FILE 1
#define LIBGUESTFS_HAVE_XFS_ADMIN 1
#define LIBGUESTFS_HAVE_XFS_GROWFS 1
#define LIBGUESTFS_HAVE_XFS_INFO 1
#define LIBGUESTFS_HAVE_XFS_REPAIR 1
#define LIBGUESTFS_HAVE_ZEGREP 1
#define LIBGUESTFS_HAVE_ZEGREPI 1
#define LIBGUESTFS_HAVE_ZERO 1
#define LIBGUESTFS_HAVE_ZERO_DEVICE 1
#define LIBGUESTFS_HAVE_ZERO_FREE_SPACE 1
#define LIBGUESTFS_HAVE_ZEROFREE 1
#define LIBGUESTFS_HAVE_ZFGREP 1
#define LIBGUESTFS_HAVE_ZFGREPI 1
#define LIBGUESTFS_HAVE_ZFILE 1
#define LIBGUESTFS_HAVE_ZGREP 1
#define LIBGUESTFS_HAVE_ZGREPI 1

/* End of deprecated macros. */

#ifdef __cplusplus
}
#endif

#endif /* GUESTFS_H_ */
