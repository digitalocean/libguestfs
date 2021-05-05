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
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <errno.h>
#include <error.h>

#include "p2v.h"
#include "p2v-config.h"

/**
 * Allocate a new config struct.
 */
struct config *
new_config (void)
{
  struct config *c;

  c = calloc (1, sizeof *c);
  if (c == NULL)
    error (EXIT_FAILURE, errno, "calloc");

  c->remote.port = 22;

  return c;
}

/**
 * Copy a config struct.
 */
struct config *
copy_config (struct config *old)
{
  struct config *c = new_config ();

  memcpy (c, old, sizeof *c);

  /* Need to deep copy strings and string lists. */
  if (c->remote.server) {
    c->remote.server = strdup (c->remote.server);
    if (c->remote.server == NULL)
      error (EXIT_FAILURE, errno, "strdup: %s", "server");
  }
  if (c->auth.username) {
    c->auth.username = strdup (c->auth.username);
    if (c->auth.username == NULL)
      error (EXIT_FAILURE, errno, "strdup: %s", "username");
  }
  if (c->auth.password) {
    c->auth.password = strdup (c->auth.password);
    if (c->auth.password == NULL)
      error (EXIT_FAILURE, errno, "strdup: %s", "password");
  }
  if (c->auth.identity.url) {
    c->auth.identity.url = strdup (c->auth.identity.url);
    if (c->auth.identity.url == NULL)
      error (EXIT_FAILURE, errno, "strdup: %s", "url");
  }
  if (c->auth.identity.file) {
    c->auth.identity.file = strdup (c->auth.identity.file);
    if (c->auth.identity.file == NULL)
      error (EXIT_FAILURE, errno, "strdup: %s", "file");
  }
  if (c->guestname) {
    c->guestname = strdup (c->guestname);
    if (c->guestname == NULL)
      error (EXIT_FAILURE, errno, "strdup: %s", "guestname");
  }
  if (c->cpu.vendor) {
    c->cpu.vendor = strdup (c->cpu.vendor);
    if (c->cpu.vendor == NULL)
      error (EXIT_FAILURE, errno, "strdup: %s", "vendor");
  }
  if (c->cpu.model) {
    c->cpu.model = strdup (c->cpu.model);
    if (c->cpu.model == NULL)
      error (EXIT_FAILURE, errno, "strdup: %s", "model");
  }
  if (c->disks) {
    c->disks = guestfs_int_copy_string_list (c->disks);
    if (c->disks == NULL)
      error (EXIT_FAILURE, errno, "copy string list: %s", "disks");
  }
  if (c->removable) {
    c->removable = guestfs_int_copy_string_list (c->removable);
    if (c->removable == NULL)
      error (EXIT_FAILURE, errno, "copy string list: %s", "removable");
  }
  if (c->interfaces) {
    c->interfaces = guestfs_int_copy_string_list (c->interfaces);
    if (c->interfaces == NULL)
      error (EXIT_FAILURE, errno, "copy string list: %s", "interfaces");
  }
  if (c->network_map) {
    c->network_map = guestfs_int_copy_string_list (c->network_map);
    if (c->network_map == NULL)
      error (EXIT_FAILURE, errno, "copy string list: %s", "network_map");
  }
  if (c->output.type) {
    c->output.type = strdup (c->output.type);
    if (c->output.type == NULL)
      error (EXIT_FAILURE, errno, "strdup: %s", "type");
  }
  if (c->output.connection) {
    c->output.connection = strdup (c->output.connection);
    if (c->output.connection == NULL)
      error (EXIT_FAILURE, errno, "strdup: %s", "connection");
  }
  if (c->output.format) {
    c->output.format = strdup (c->output.format);
    if (c->output.format == NULL)
      error (EXIT_FAILURE, errno, "strdup: %s", "format");
  }
  if (c->output.storage) {
    c->output.storage = strdup (c->output.storage);
    if (c->output.storage == NULL)
      error (EXIT_FAILURE, errno, "strdup: %s", "storage");
  }

  return c;
}

/**
 * Free a config struct.
 */
void
free_config (struct config *c)
{
  if (c == NULL)
    return;

  free (c->remote.server);
  free (c->auth.username);
  free (c->auth.password);
  free (c->auth.identity.url);
  free (c->auth.identity.file);
  free (c->guestname);
  free (c->cpu.vendor);
  free (c->cpu.model);
  guestfs_int_free_string_list (c->disks);
  guestfs_int_free_string_list (c->removable);
  guestfs_int_free_string_list (c->interfaces);
  guestfs_int_free_string_list (c->network_map);
  free (c->output.type);
  free (c->output.connection);
  free (c->output.format);
  free (c->output.storage);
}

static void
print_basis (enum basis v, FILE *fp)
{
  switch (v) {
  case BASIS_UNKNOWN:
    fprintf (fp, "unknown");
    break;
  case BASIS_UTC:
    fprintf (fp, "utc");
    break;
  case BASIS_LOCALTIME:
    fprintf (fp, "localtime");
    break;
  }
}

static void
print_output_allocation (enum output_allocation v, FILE *fp)
{
  switch (v) {
  case OUTPUT_ALLOCATION_NONE:
    fprintf (fp, "none");
    break;
  case OUTPUT_ALLOCATION_SPARSE:
    fprintf (fp, "sparse");
    break;
  case OUTPUT_ALLOCATION_PREALLOCATED:
    fprintf (fp, "preallocated");
    break;
  }
}

/**
 * Print the conversion parameters and other important information.
 */
void
print_config (struct config *c, FILE *fp)
{
  size_t i;

  fprintf (fp, "%-20s %s\n", "local version", PACKAGE_VERSION_FULL);
  fprintf (fp, "%-20s %s\n", "remote version",
           v2v_version ? v2v_version : "unknown");
  fprintf (fp, "%-20s %s\n",
           "remote.server", c->remote.server ? c->remote.server : "(none)");
  fprintf (fp, "%-20s %d\n",
           "remote.port", c->remote.port);
  fprintf (fp, "%-20s %s\n",
           "auth.username", c->auth.username ? c->auth.username : "(none)");
  fprintf (fp, "%-20s %s\n",
           "auth.password", c->auth.password ? c->auth.password : "(none)");
  fprintf (fp, "%-20s %s\n",
           "auth.identity.url", c->auth.identity.url ? c->auth.identity.url : "(none)");
  fprintf (fp, "%-20s %s\n",
           "auth.identity.file", c->auth.identity.file ? c->auth.identity.file : "(none)");
  fprintf (fp, "%-20s %s\n",
           "auth.identity.file_needs_update", c->auth.identity.file_needs_update ? "true" : "false");
  fprintf (fp, "%-20s %s\n",
           "auth.sudo", c->auth.sudo ? "true" : "false");
  fprintf (fp, "%-20s %s\n",
           "guestname", c->guestname ? c->guestname : "(none)");
  fprintf (fp, "%-20s %d\n",
           "vcpus", c->vcpus);
  fprintf (fp, "%-20s %" PRIu64 "\n",
           "memory", c->memory);
  fprintf (fp, "%-20s %s\n",
           "cpu.vendor", c->cpu.vendor ? c->cpu.vendor : "(none)");
  fprintf (fp, "%-20s %s\n",
           "cpu.model", c->cpu.model ? c->cpu.model : "(none)");
  fprintf (fp, "%-20s %u\n",
           "cpu.sockets", c->cpu.sockets);
  fprintf (fp, "%-20s %u\n",
           "cpu.cores", c->cpu.cores);
  fprintf (fp, "%-20s %u\n",
           "cpu.threads", c->cpu.threads);
  fprintf (fp, "%-20s %s\n",
           "cpu.acpi", c->cpu.acpi ? "true" : "false");
  fprintf (fp, "%-20s %s\n",
           "cpu.apic", c->cpu.apic ? "true" : "false");
  fprintf (fp, "%-20s %s\n",
           "cpu.pae", c->cpu.pae ? "true" : "false");
  fprintf (fp, "%-20s ", "rtc.basis");
  print_basis (c->rtc.basis, fp);
  fprintf (fp, "\n");
  fprintf (fp, "%-20s %d\n",
           "rtc.offset", c->rtc.offset);
  fprintf (fp, "%-20s", "disks");
  if (c->disks) {
    for (i = 0; c->disks[i] != NULL; ++i)
      fprintf (fp, " %s", c->disks[i]);
  }
  else
    fprintf (fp, " (none)\n");
  fprintf (fp, "\n");
  fprintf (fp, "%-20s", "removable");
  if (c->removable) {
    for (i = 0; c->removable[i] != NULL; ++i)
      fprintf (fp, " %s", c->removable[i]);
  }
  else
    fprintf (fp, " (none)\n");
  fprintf (fp, "\n");
  fprintf (fp, "%-20s", "interfaces");
  if (c->interfaces) {
    for (i = 0; c->interfaces[i] != NULL; ++i)
      fprintf (fp, " %s", c->interfaces[i]);
  }
  else
    fprintf (fp, " (none)\n");
  fprintf (fp, "\n");
  fprintf (fp, "%-20s", "network_map");
  if (c->network_map) {
    for (i = 0; c->network_map[i] != NULL; ++i)
      fprintf (fp, " %s", c->network_map[i]);
  }
  else
    fprintf (fp, " (none)\n");
  fprintf (fp, "\n");
  fprintf (fp, "%-20s %s\n",
           "output.type", c->output.type ? c->output.type : "(none)");
  fprintf (fp, "%-20s ", "output.allocation");
  print_output_allocation (c->output.allocation, fp);
  fprintf (fp, "\n");
  fprintf (fp, "%-20s %s\n",
           "output.connection", c->output.connection ? c->output.connection : "(none)");
  fprintf (fp, "%-20s %s\n",
           "output.format", c->output.format ? c->output.format : "(none)");
  fprintf (fp, "%-20s %s\n",
           "output.storage", c->output.storage ? c->output.storage : "(none)");
}
