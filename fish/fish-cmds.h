/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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

#ifndef FISH_CMDS_H
#define FISH_CMDS_H

extern int run_alloc (const char *cmd, size_t argc, char *argv[]);
extern int run_copy_in (const char *cmd, size_t argc, char *argv[]);
extern int run_copy_out (const char *cmd, size_t argc, char *argv[]);
extern int run_delete_event (const char *cmd, size_t argc, char *argv[]);
extern int run_display (const char *cmd, size_t argc, char *argv[]);
extern int run_echo (const char *cmd, size_t argc, char *argv[]);
extern int run_edit (const char *cmd, size_t argc, char *argv[]);
extern int run_event (const char *cmd, size_t argc, char *argv[]);
extern int run_glob (const char *cmd, size_t argc, char *argv[]);
extern int run_hexedit (const char *cmd, size_t argc, char *argv[]);
extern int run_lcd (const char *cmd, size_t argc, char *argv[]);
extern int run_list_events (const char *cmd, size_t argc, char *argv[]);
extern int run_man (const char *cmd, size_t argc, char *argv[]);
extern int run_more (const char *cmd, size_t argc, char *argv[]);
extern int run_reopen (const char *cmd, size_t argc, char *argv[]);
extern int run_setenv (const char *cmd, size_t argc, char *argv[]);
extern int run_sparse (const char *cmd, size_t argc, char *argv[]);
extern int run_supported (const char *cmd, size_t argc, char *argv[]);
extern int run_time (const char *cmd, size_t argc, char *argv[]);
extern int run_unsetenv (const char *cmd, size_t argc, char *argv[]);

#endif /* FISH_CMDS_H */
