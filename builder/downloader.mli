(* virt-builder
 * Copyright (C) 2013 Red Hat Inc.
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

(** This module is a wrapper around curl, plus local caching. *)

val cache_of_name : string -> string -> int -> string
(** [cache_of_name cachedir name revision] returns the filename
    of the cached file.  (Note: It doesn't check if the filename
    exists, this is just a simple string transformation). *)

type uri = string
type filename = string

type t
(** The abstract data type. *)

val create : debug:bool -> curl:string -> cache:string option -> t
(** Create the abstract type. *)

val download : prog:string -> t -> ?template:(string*int) -> ?progress_bar:bool -> uri -> (filename * bool)
(** Download the URI, returning the downloaded filename and a
    temporary file flag.  The temporary file flag is [true] iff
    the downloaded file is temporary and should be deleted by the
    caller (otherwise it's in the cache and you shouldn't delete it).

    For templates, you must supply [~template:(name, revision)].  This
    causes the cache to be used (if possible).  Name and revision are
    used for cache control (see the man page for details).

    If [~progress_bar:true] then display a progress bar if the file
    doesn't come from the cache.  In debug mode, progress messages
    are always displayed. *)
