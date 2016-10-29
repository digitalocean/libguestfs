(* libguestfs
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *)

(* Please read generator/README first. *)

(** The libguestfs API. *)

val actions : Types.action list
(** The list of functions in the libguestfs API. *)

val daemon_functions : Types.action list -> Types.action list
val non_daemon_functions : Types.action list -> Types.action list
(** Filter {!actions}, returning only daemon function /
    non-daemon function respectively.

    The difference is that a daemon function is handled directly by
    the daemon.  A non-daemon function is implemented in the library side. *)

val external_functions : Types.action list -> Types.action list
(** Filter {!actions}, returning only external functions. *)

val internal_functions : Types.action list -> Types.action list
(** Filter {!actions}, returning only internal functions. *)

val fish_functions : Types.action list -> Types.action list
(** Filter {!actions}, returning only functions in guestfish. *)

val documented_functions : Types.action list -> Types.action list
(** Filter {!actions}, returning only functions requiring documentation. *)

val sort : Types.action list -> Types.action list
(** Sort the functions alphabetically by name
    (see also {!Utils.action_compare}). *)

val is_documented : Types.action -> bool
(** Returns true if function should be documented, false otherwise. *)

val test_functions : Types.action list
(** Internal test functions used to test the language bindings. *)

val fish_commands : Types.action list
(** Non-API meta-commands available only in guestfish. *)

val max_proc_nr : int
(** The largest procedure number used (also saved in [src/MAX_PROC_NR] and
    used as the minor version number of the shared library). *)
