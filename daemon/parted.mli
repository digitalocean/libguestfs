(* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/daemon.ml
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
 *)

val part_list : string -> Structs.partition list
val part_get_parttype : string -> string
val part_get_mbr_id : string -> int -> int
val part_get_gpt_type : string -> int -> string
val part_set_gpt_attributes : string -> int -> int64 -> unit
val part_get_gpt_attributes : string -> int -> int64
val part_get_gpt_guid : string -> int -> string
val part_get_mbr_part_type : string -> int -> string
