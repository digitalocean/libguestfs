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

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>

#include "xstrtol.h"

#include "p2v.h"
#include "p2v-config.h"

/**
 * Read the kernel command line and parse out any C<p2v.*> fields that
 * we understand into the config struct.
 */
void
update_config_from_kernel_cmdline (struct config *c, char **cmdline)
{
  const char *p;
  strtol_error xerr;
  unsigned long long ull;

  if ((p = get_cmdline_key (cmdline, "p2v.remote.server")) != NULL ||
      (p = get_cmdline_key (cmdline, "p2v.server")) != NULL) {
    free (c->remote.server);
    c->remote.server = strdup (p);
    if (c->remote.server == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.remote.port")) != NULL ||
      (p = get_cmdline_key (cmdline, "p2v.port")) != NULL) {
    if (sscanf (p, "%d", &c->remote.port) != 1)
      error (EXIT_FAILURE, errno,
             "cannot parse %s=%s from the kernel command line",
             "p2v.remote.port", p);
  }

  if ((p = get_cmdline_key (cmdline, "p2v.auth.username")) != NULL ||
      (p = get_cmdline_key (cmdline, "p2v.username")) != NULL) {
    free (c->auth.username);
    c->auth.username = strdup (p);
    if (c->auth.username == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.auth.password")) != NULL ||
      (p = get_cmdline_key (cmdline, "p2v.password")) != NULL) {
    free (c->auth.password);
    c->auth.password = strdup (p);
    if (c->auth.password == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.auth.identity.url")) != NULL ||
      (p = get_cmdline_key (cmdline, "p2v.identity")) != NULL) {
    free (c->auth.identity.url);
    c->auth.identity.url = strdup (p);
    if (c->auth.identity.url == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.auth.sudo")) != NULL ||
      (p = get_cmdline_key (cmdline, "p2v.sudo")) != NULL) {
    c->auth.sudo = guestfs_int_is_true (p) || STREQ (p, "");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.guestname")) != NULL ||
      (p = get_cmdline_key (cmdline, "p2v.name")) != NULL) {
    free (c->guestname);
    c->guestname = strdup (p);
    if (c->guestname == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.vcpus")) != NULL) {
    if (sscanf (p, "%d", &c->vcpus) != 1)
      error (EXIT_FAILURE, errno,
             "cannot parse %s=%s from the kernel command line",
             "p2v.vcpus", p);
  }

  if ((p = get_cmdline_key (cmdline, "p2v.memory")) != NULL) {
    xerr = xstrtoull (p, NULL, 0, &ull, "0kKMGTPEZY");
    if (xerr != LONGINT_OK)
      error (EXIT_FAILURE, 0,
             "cannot parse %s=%s from the kernel command line",
             "p2v.memory", p);
    c->memory = ull;
  }

  if ((p = get_cmdline_key (cmdline, "p2v.cpu.vendor")) != NULL) {
    free (c->cpu.vendor);
    c->cpu.vendor = strdup (p);
    if (c->cpu.vendor == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.cpu.model")) != NULL) {
    free (c->cpu.model);
    c->cpu.model = strdup (p);
    if (c->cpu.model == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.cpu.sockets")) != NULL) {
    if (sscanf (p, "%u", &c->cpu.sockets) != 1)
      error (EXIT_FAILURE, errno,
             "cannot parse %s=%s from the kernel command line",
             "p2v.cpu.sockets", p);
  }

  if ((p = get_cmdline_key (cmdline, "p2v.cpu.cores")) != NULL) {
    if (sscanf (p, "%u", &c->cpu.cores) != 1)
      error (EXIT_FAILURE, errno,
             "cannot parse %s=%s from the kernel command line",
             "p2v.cpu.cores", p);
  }

  if ((p = get_cmdline_key (cmdline, "p2v.cpu.threads")) != NULL) {
    if (sscanf (p, "%u", &c->cpu.threads) != 1)
      error (EXIT_FAILURE, errno,
             "cannot parse %s=%s from the kernel command line",
             "p2v.cpu.threads", p);
  }

  if ((p = get_cmdline_key (cmdline, "p2v.cpu.acpi")) != NULL) {
    c->cpu.acpi = guestfs_int_is_true (p) || STREQ (p, "");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.cpu.apic")) != NULL) {
    c->cpu.apic = guestfs_int_is_true (p) || STREQ (p, "");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.cpu.pae")) != NULL) {
    c->cpu.pae = guestfs_int_is_true (p) || STREQ (p, "");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.rtc.basis")) != NULL) {
    if (STREQ (p, "unknown"))
      c->rtc.basis = BASIS_UNKNOWN;
    else if (STREQ (p, "utc"))
      c->rtc.basis = BASIS_UTC;
    else if (STREQ (p, "localtime"))
      c->rtc.basis = BASIS_LOCALTIME;
    else {
      error (EXIT_FAILURE, 0,
             "invalid value %s=%s from the kernel command line",
             "p2v.rtc.basis", p);
    }
  }

  if ((p = get_cmdline_key (cmdline, "p2v.rtc.offset")) != NULL) {
    if (sscanf (p, "%d", &c->rtc.offset) != 1)
      error (EXIT_FAILURE, errno,
             "cannot parse %s=%s from the kernel command line",
             "p2v.rtc.offset", p);
  }

  if ((p = get_cmdline_key (cmdline, "p2v.disks")) != NULL) {
    guestfs_int_free_string_list (c->disks);
    c->disks = guestfs_int_split_string (',', p);
    if (c->disks == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.removable")) != NULL) {
    guestfs_int_free_string_list (c->removable);
    c->removable = guestfs_int_split_string (',', p);
    if (c->removable == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.interfaces")) != NULL) {
    guestfs_int_free_string_list (c->interfaces);
    c->interfaces = guestfs_int_split_string (',', p);
    if (c->interfaces == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.network_map")) != NULL ||
      (p = get_cmdline_key (cmdline, "p2v.network")) != NULL) {
    guestfs_int_free_string_list (c->network_map);
    c->network_map = guestfs_int_split_string (',', p);
    if (c->network_map == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.output.type")) != NULL ||
      (p = get_cmdline_key (cmdline, "p2v.o")) != NULL) {
    free (c->output.type);
    c->output.type = strdup (p);
    if (c->output.type == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.output.allocation")) != NULL ||
      (p = get_cmdline_key (cmdline, "p2v.oa")) != NULL) {
    if (STREQ (p, "none"))
      c->output.allocation = OUTPUT_ALLOCATION_NONE;
    else if (STREQ (p, "sparse"))
      c->output.allocation = OUTPUT_ALLOCATION_SPARSE;
    else if (STREQ (p, "preallocated"))
      c->output.allocation = OUTPUT_ALLOCATION_PREALLOCATED;
    else {
      error (EXIT_FAILURE, 0,
             "invalid value %s=%s from the kernel command line",
             "p2v.output.allocation", p);
    }
  }

  if ((p = get_cmdline_key (cmdline, "p2v.output.connection")) != NULL ||
      (p = get_cmdline_key (cmdline, "p2v.oc")) != NULL) {
    free (c->output.connection);
    c->output.connection = strdup (p);
    if (c->output.connection == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.output.format")) != NULL ||
      (p = get_cmdline_key (cmdline, "p2v.of")) != NULL) {
    free (c->output.format);
    c->output.format = strdup (p);
    if (c->output.format == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if ((p = get_cmdline_key (cmdline, "p2v.output.storage")) != NULL ||
      (p = get_cmdline_key (cmdline, "p2v.os")) != NULL) {
    free (c->output.storage);
    c->output.storage = strdup (p);
    if (c->output.storage == NULL)
      error (EXIT_FAILURE, errno, "strdup");
  }

  if (c->auth.identity.url != NULL)
    c->auth.identity.file_needs_update = 1;

  /* Undocumented command line parameter used for testing command line
   * parsing.
   */
  p = get_cmdline_key (cmdline, "p2v.dump_config_and_exit");
  if (p) {
    print_config (c, stdout);
    exit (EXIT_SUCCESS);
  }
}
