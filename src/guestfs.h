/* libguestfs
 * Copyright (C) 2009 Red Hat Inc. 
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

#ifndef GUESTFS_H_
#define GUESTFS_H_

/* IMPORTANT NOTE!
 * All API documentation is in the manual page --> guestfs(3) <--
 * Go and read it now, I'll wait.
 */

#include <rpc/xdr.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct guestfs_h guestfs_h;
typedef struct guestfs_main_loop guestfs_main_loop;

/* Connection management. */
extern guestfs_h *guestfs_create (void);
extern void guestfs_close (guestfs_h *g);

/* Error handling. */
extern const char *guestfs_last_error (guestfs_h *g);

typedef void (*guestfs_error_handler_cb) (guestfs_h *g, void *data, const char *msg);
typedef void (*guestfs_abort_cb) (void);

extern void guestfs_set_error_handler (guestfs_h *g, guestfs_error_handler_cb cb, void *data);
extern guestfs_error_handler_cb guestfs_get_error_handler (guestfs_h *g, void **data_rtn);

extern void guestfs_set_out_of_memory_handler (guestfs_h *g, guestfs_abort_cb);
extern guestfs_abort_cb guestfs_get_out_of_memory_handler (guestfs_h *g);

#include <guestfs-structs.h>
#include <guestfs-actions.h>

/* Free up return values. */
extern void guestfs_free_int_bool (struct guestfs_int_bool *);
extern void guestfs_free_lvm_pv_list (struct guestfs_lvm_pv_list *);
extern void guestfs_free_lvm_vg_list (struct guestfs_lvm_vg_list *);
extern void guestfs_free_lvm_lv_list (struct guestfs_lvm_lv_list *);

/* Low-level event API. */
typedef void (*guestfs_send_cb) (guestfs_h *g, void *data);
typedef void (*guestfs_reply_cb) (guestfs_h *g, void *data, XDR *xdr);
typedef void (*guestfs_log_message_cb) (guestfs_h *g, void *data, char *buf, int len);
typedef void (*guestfs_subprocess_quit_cb) (guestfs_h *g, void *data);
typedef void (*guestfs_launch_done_cb) (guestfs_h *g, void *data);

extern void guestfs_set_send_callback (guestfs_h *g, guestfs_send_cb cb, void *opaque);
extern void guestfs_set_reply_callback (guestfs_h *g, guestfs_reply_cb cb, void *opaque);
extern void guestfs_set_log_message_callback (guestfs_h *g, guestfs_log_message_cb cb, void *opaque);
extern void guestfs_set_subprocess_quit_callback (guestfs_h *g, guestfs_subprocess_quit_cb cb, void *opaque);
extern void guestfs_set_launch_done_callback (guestfs_h *g, guestfs_launch_done_cb cb, void *opaque);

extern void guestfs_error (guestfs_h *g, const char *fs, ...)
  __attribute__((format (printf,2,3)));
extern void guestfs_perrorf (guestfs_h *g, const char *fs, ...)
  __attribute__((format (printf,2,3)));
extern void *guestfs_safe_malloc (guestfs_h *g, size_t nbytes);
extern void *guestfs_safe_realloc (guestfs_h *g, void *ptr, int nbytes);
extern char *guestfs_safe_strdup (guestfs_h *g, const char *str);
extern void *guestfs_safe_memdup (guestfs_h *g, void *ptr, size_t size);

extern int guestfs__switch_to_sending (guestfs_h *g);
extern int guestfs__switch_to_receiving (guestfs_h *g);

/* These *_sync calls wait until the action is performed, using the
 * main loop.  We should implement asynchronous versions too.
 */
extern int guestfs__send_sync (guestfs_h *g, int proc_nr, xdrproc_t xdrp, char *args);
extern int guestfs__send_file_sync (guestfs_h *g, const char *filename);
extern int guestfs__receive_file_sync (guestfs_h *g, const char *filename);

/* Main loop. */
#define GUESTFS_HANDLE_READABLE 0x1
#define GUESTFS_HANDLE_WRITABLE 0x2
#define GUESTFS_HANDLE_HANGUP   0x4
#define GUESTFS_HANDLE_ERROR    0x8

typedef void (*guestfs_handle_event_cb) (guestfs_main_loop *ml, guestfs_h *g, void *data, int watch, int fd, int events);
typedef int (*guestfs_add_handle_cb) (guestfs_main_loop *ml, guestfs_h *g, int fd, int events, guestfs_handle_event_cb cb, void *data);
typedef int (*guestfs_remove_handle_cb) (guestfs_main_loop *ml, guestfs_h *g, int watch);
typedef void (*guestfs_handle_timeout_cb) (guestfs_main_loop *ml, guestfs_h *g, void *data, int timer);
typedef int (*guestfs_add_timeout_cb) (guestfs_main_loop *ml, guestfs_h *g, int interval, guestfs_handle_timeout_cb cb, void *data);
typedef int (*guestfs_remove_timeout_cb) (guestfs_main_loop *ml, guestfs_h *g, int timer);
typedef int (*guestfs_main_loop_run_cb) (guestfs_main_loop *ml, guestfs_h *g);
typedef int (*guestfs_main_loop_quit_cb) (guestfs_main_loop *ml, guestfs_h *g);

/* This is the head of the main loop structure.  Concrete implementations
 * use additional private data after this struct.
 */
struct guestfs_main_loop {
  guestfs_add_handle_cb add_handle;
  guestfs_remove_handle_cb remove_handle;
  guestfs_add_timeout_cb add_timeout;
  guestfs_remove_timeout_cb remove_timeout;
  guestfs_main_loop_run_cb main_loop_run;
  guestfs_main_loop_quit_cb main_loop_quit;
};

extern void guestfs_set_main_loop (guestfs_h *handle, guestfs_main_loop *main_loop);
extern guestfs_main_loop *guestfs_get_main_loop (guestfs_h *handle);
extern guestfs_main_loop *guestfs_get_default_main_loop (void);

extern guestfs_main_loop *guestfs_create_main_loop (void);
extern void guestfs_free_main_loop (guestfs_main_loop *);

#ifdef __cplusplus
}
#endif

#endif /* GUESTFS_H_ */
