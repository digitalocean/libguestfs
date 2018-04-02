/* virt-p2v
 * Copyright (C) 2009-2018 Red Hat Inc.
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef P2V_H
#define P2V_H

#include <stdio.h>
#include <stdbool.h>

/* Send various debug information to stderr.  Harmless and useful, so
 * can be left enabled in production builds.
 */
#define DEBUG_STDERR 1

#include "miniexpect.h"

/* We don't use libguestfs directly here, and we don't link to it
 * either (in fact, we don't want libguestfs on the ISO).  However
 * we include this just so that we can use the convenience macros in
 * utils.h.
 */
#include "guestfs.h"
#include "guestfs-utils.h"

/* Ensure we don't use libguestfs. */
#define guestfs_h DO_NOT_USE

/* All disks / removable media / network interfaces discovered
 * when the program started.  Do not change these.
 */
extern char **all_disks;
extern char **all_removable;
extern char **all_interfaces;

/* True if running inside the virt-p2v ISO environment.  Various
 * dangerous functions such as the "Reboot" button are disabled if
 * this is false.
 */
extern int is_iso_environment;

/* True if virt-v2v supports the --colours option. */
extern int feature_colours_option;

/* virt-p2v --colours option (used by ansi_* macros). */
extern int force_colour;

/* config.c */
struct cpu_config {
  char *vendor;                 /* eg. "Intel" */
  char *model;                  /* eg. "Broadwell" */
  unsigned sockets;             /* number of sockets */
  unsigned cores;               /* number of cores per socket */
  unsigned threads;             /* number of hyperthreads per core */
  bool acpi;
  bool apic;
  bool pae;
};

struct rtc_config {
  enum {
    BASIS_UNKNOWN,              /* RTC could not be read. */
    BASIS_UTC,                  /* RTC is either UTC or an offset from UTC. */
    BASIS_LOCALTIME,            /* RTC is localtime. */
  } basis;
  int offset;                   /* RTC seconds offset from basis. */
};

struct config {
  char *server;
  int port;
  char *username;
  char *password;
  char *identity_url;
  char *identity_file; /* Used to cache the downloaded identity_url. */
  int identity_file_needs_update;
  int sudo;
  char *guestname;
  int vcpus;
  uint64_t memory;
  struct cpu_config cpu;
  struct rtc_config rtc;
  char **disks;
  char **removable;
  char **interfaces;
  char **network_map;
  char *output;
  int output_allocation;
  char *output_connection;
  char *output_format;
  char *output_storage;
};

#define OUTPUT_ALLOCATION_NONE         0
#define OUTPUT_ALLOCATION_SPARSE       1
#define OUTPUT_ALLOCATION_PREALLOCATED 2

extern struct config *new_config (void);
extern struct config *copy_config (struct config *);
extern void free_config (struct config *);
extern void print_config (struct config *, FILE *);

/* cpuid.c */
extern void get_cpu_config (struct cpu_config *);

/* rtc.c */
extern void get_rtc_config (struct rtc_config *);

/* kernel-cmdline.c */
extern char **parse_cmdline_string (const char *cmdline);
extern char **parse_proc_cmdline (void);
extern const char *get_cmdline_key (char **cmdline, const char *key);

#define CMDLINE_SOURCE_COMMAND_LINE 1 /* --cmdline */
#define CMDLINE_SOURCE_PROC_CMDLINE 2 /* /proc/cmdline */

/* kernel.c */
extern void update_config_from_kernel_cmdline (struct config *config, char **cmdline);
extern void kernel_conversion (struct config *, char **cmdline, int cmdline_source);

/* gui.c */
extern void gui_conversion (struct config *);

/* conversion.c */
struct data_conn {          /* Data per NBD connection / physical disk. */
  mexp_h *h;                /* miniexpect handle to ssh */
  pid_t nbd_pid;            /* NBD server PID */
  int nbd_remote_port;      /* remote NBD port on conversion server */
};

extern int start_conversion (struct config *, void (*notify_ui) (int type, const char *data));
#define NOTIFY_LOG_DIR        1  /* location of remote log directory */
#define NOTIFY_REMOTE_MESSAGE 2  /* log message from remote virt-v2v */
#define NOTIFY_STATUS         3  /* stage in conversion process */
extern const char *get_conversion_error (void);
extern void cancel_conversion (void);
extern int conversion_is_running (void);

/* physical-xml.c */
extern void generate_physical_xml (struct config *, struct data_conn *, const char *filename);

/* inhibit.c */
extern int inhibit_power_saving (void);

/* ssh.c */
extern int test_connection (struct config *);
extern mexp_h *open_data_connection (struct config *, const char *local_ipaddr, int local_port, int *remote_port);
extern mexp_h *start_remote_connection (struct config *, const char *remote_dir);
extern const char *get_ssh_error (void);
extern int scp_file (struct config *config, const char *target, const char *local, ...) __attribute__((sentinel));

/* nbd.c */
extern void set_nbd_option (const char *opt);
extern void test_nbd_servers (void);
extern pid_t start_nbd_server (const char **ipaddr, int *port, const char *device);
extern int wait_for_nbd_server_to_start (const char *ipaddr, int port);
const char *get_nbd_error (void);

/* utils.c */
extern uint64_t get_blockdev_size (const char *dev);
extern char *get_blockdev_model (const char *dev);
extern char *get_blockdev_serial (const char *dev);
extern char *get_if_addr (const char *if_name);
extern char *get_if_vendor (const char *if_name, int truncate);
extern void wait_network_online (const struct config *);

/* whole-file.c */
extern int read_whole_file (const char *filename, char **data_r, size_t *size_r);

/* virt-v2v version and features (read from remote). */
extern char *v2v_version;

/* input and output drivers (read from remote). */
extern char **input_drivers;
extern char **output_drivers;

/* about-authors.c */
extern const char *authors[];
extern const char *qa[];
extern const char *documenters[];
extern const char *others[];

#endif /* P2V_H */
