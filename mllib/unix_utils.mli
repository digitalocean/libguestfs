(* mllib
 * Copyright (C) 2009-2017 Red Hat Inc.
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

(** Binding for various Unix/POSIX library functions which are not
    provided by the OCaml stdlib. *)

module Dev_t : sig
  (** Bindings for [dev_t] related functions [makedev], [major] and [minor]. *)

  val makedev : int -> int -> int
  (** makedev(3) *)

  val major : int -> int
  (** major(3) *)

  val minor : int -> int
  (** minor(3) *)
end

module Env : sig
  val unsetenv : string -> unit
  (** Unset named environment variable, see unsetenv(3). *)
end

module Exit : sig
  val _exit : int -> 'a
  (** Call _exit directly, ie. do not run OCaml atexit handlers. *)
end

module Fnmatch : sig
  (** Binding for the fnmatch(3) function in glibc or gnulib. *)

  type flag =
    | FNM_NOESCAPE
    | FNM_PATHNAME
    | FNM_PERIOD
    | FNM_FILE_NAME
    | FNM_LEADING_DIR
    | FNM_CASEFOLD
  (** Flags passed to the fnmatch function. *)

  val fnmatch : string -> string -> flag list -> bool
  (** The [fnmatch pattern filename flags] function checks whether
      the [filename] argument matches the wildcard in the [pattern]
      argument.  The [flags] is a list of flags.  Consult the
      fnmatch(3) man page for details of the flags.

      The [filename] might be a filename element or a full path
      (depending on the pattern and flags). *)
end

module Fsync : sig
  (** Bindings for sync, fsync. *)

  val sync : unit -> unit
  (** sync(2) syscall. *)

  val file : string -> unit
  (** fsync a single file by name. *)
end

module Mkdtemp : sig
  (** Functions to create temporary directories. *)

  val mkdtemp : string -> string
  (** [mkdtemp pattern] Tiny wrapper to the C [mkdtemp]. *)

  val temp_dir : ?base_dir:string -> string -> string -> string
  (** [temp_dir prefix suffix] creates a new unique temporary directory.

      The optional [~base_dir:string] changes the base directory where
      to create the new temporary directory; if not specified, the default
      [Filename.temp_dir_name] is used. *)
end

module StatVFS : sig
  val free_space : string -> int64
  (** [free_space path] returns the free space available on the
      filesystem that contains [path], in bytes. *)
end
