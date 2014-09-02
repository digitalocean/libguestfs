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

type t

type gpgkey_type =
  | No_Key
  | Fingerprint of string
  | KeyFile of string

val create : verbose:bool -> gpg:string -> gpgkey:gpgkey_type -> check_signature:bool -> t

val verify : t -> string -> unit
(** Verify the file is signed (if check_signature is true). *)

val verify_detached : t -> string -> string option -> unit
(** Verify the file is signed against the detached signature
    (if check_signature is true). *)

type csum_t = SHA512 of string

val verify_checksum : t -> csum_t -> string -> unit
(** Verify the checksum of the file.  This is always verified even if
    check_signature if false. *)
