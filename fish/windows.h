/* libguestfs - shared Windows path for tools
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

#ifndef FISH_WINDOWS_H
#define FISH_WINDOWS_H

#include <guestfs.h>

/**
 * Checks whether 'root' is a Windows installation.
 *
 * This relies on an already being done introspection.
 */
extern int is_windows (guestfs_h *g, const char *root);

/**
 * Resolves 'path' as possible Windows path according to 'root',
 * giving a new path that can be used in libguestfs API calls.
 *
 * Notes:
 *  - 'root' must be a Windows installation
 *  - relies on an already being done introspection
 *  - will unmount all the existing mount points and mount the Windows root
 *    (according to 'readonly')
 *  - will exit() on memory allocation failures
 */
extern char *windows_path (guestfs_h *g, const char *root, const char *path,
                           int readonly);

#endif
