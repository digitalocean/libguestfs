(* libguestfs
 * Copyright (C) 2017 Red Hat Inc.
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

type role = Development | Quality_assurance | Documentation | V2V_and_P2V
(** Not exclusive, you can be in multiple roles :-) *)

val authors : (string * string list * role list) list
(** List of authors, their aliases, and their roles. *)

val generate_authors : unit -> unit
val generate_p2v_about_authors_c : unit -> unit
