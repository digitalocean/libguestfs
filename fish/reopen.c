/* guestfish - guest filesystem shell
 * Copyright (C) 2009-2016 Red Hat Inc.
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

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libintl.h>

#include "fish.h"

int
run_reopen (const char *cmd, size_t argc, char *argv[])
{
  guestfs_h *g2;
  int r;
  const char *p;
  guestfs_error_handler_cb cb;
  void *cb_data;

  if (argc > 0) {
    fprintf (stderr, _("'reopen' command takes no parameters\n"));
    return -1;
  }

  if (guestfs_shutdown (g) == -1)
    return -1;

  /* Open the new handle first, so we can copy the settings from the
   * old one to the new one, and also so if it fails we still have an
   * open handle.
   */
  g2 = guestfs_create ();
  if (g2 == NULL) {
    fprintf (stderr, _("reopen: guestfs_create: failed to create handle\n"));
    return -1;
  }

  /* Now copy some of the settings from the old handle.  The settings
   * we copy are those which are set by guestfish itself.
   */
  cb = guestfs_get_error_handler (g, &cb_data);
  guestfs_set_error_handler (g2, cb, cb_data);

  r = guestfs_get_verbose (g);
  if (r >= 0)
    guestfs_set_verbose (g2, r);

  r = guestfs_get_trace (g);
  if (r >= 0)
    guestfs_set_trace (g2, r);

  r = guestfs_get_autosync (g);
  if (r >= 0)
    guestfs_set_autosync (g2, r);

  p = guestfs_get_path (g);
  if (p)
    guestfs_set_path (g2, p);

  r = guestfs_get_pgroup (g);
  if (r >= 0)
    guestfs_set_pgroup (g2, r);

  if (progress_bars)
    guestfs_set_event_callback (g2, progress_callback,
                                GUESTFS_EVENT_PROGRESS, 0, NULL);

  /* Close the original handle. */
  guestfs_close (g);
  g = g2;

  /* We don't bother copying event handlers over to the new handle,
   * but we have to reset the list because they were registered
   * against the old handle.
   */
  free_event_handlers ();
  init_event_handlers ();

  return 0;
}
