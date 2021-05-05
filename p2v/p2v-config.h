/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/p2v_config.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2019 Red Hat Inc.
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

#ifndef GUESTFS_P2V_CONFIG_H
#define GUESTFS_P2V_CONFIG_H

#include <stdbool.h>
#include <stdint.h>

enum basis {
  BASIS_UNKNOWN,            /* RTC could not be read */
  BASIS_UTC,                /* RTC is either UTC or an offset from UTC */
  BASIS_LOCALTIME,          /* RTC is localtime */
};

enum output_allocation {
  OUTPUT_ALLOCATION_NONE,   /* output allocation not set */
  OUTPUT_ALLOCATION_SPARSE, /* sparse */
  OUTPUT_ALLOCATION_PREALLOCATED, /* preallocated */
};

struct remote_config {
  char *server;
  int port;
};

struct identity_config {
  char *url;
  char *file;
  bool file_needs_update;
};

struct auth_config {
  char *username;
  char *password;
  struct identity_config identity;
  bool sudo;
};

struct cpu_config {
  char *vendor;
  char *model;
  unsigned sockets;
  unsigned cores;
  unsigned threads;
  bool acpi;
  bool apic;
  bool pae;
};

struct rtc_config {
  enum basis basis;
  int offset;
};

struct output_config {
  char *type;
  enum output_allocation allocation;
  char *connection;
  char *format;
  char *storage;
};

struct config {
  struct remote_config remote;
  struct auth_config auth;
  char *guestname;
  int vcpus;
  uint64_t memory;
  struct cpu_config cpu;
  struct rtc_config rtc;
  char **disks;
  char **removable;
  char **interfaces;
  char **network_map;
  struct output_config output;
};

extern struct config *new_config (void);
extern struct config *copy_config (struct config *);
extern void free_config (struct config *);
extern void print_config (struct config *, FILE *);

#endif /* GUESTFS_P2V_CONFIG_H */
