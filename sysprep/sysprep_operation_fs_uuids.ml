(* virt-sysprep
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

open Printf

open Sysprep_operation
open Common_gettext.Gettext

module G = Guestfs

let rec fs_uuids_perform g root =
  let fses = g#list_filesystems () in
  List.iter (function
  | _, "unknown" -> ()
  | _, "swap" ->
    (* XXX Not implemented *) ()
  | dev, typ ->
    let new_uuid = Common_utils.uuidgen () in
    try
      g#set_uuid dev new_uuid
    with
      G.Error msg ->
        eprintf (f_"warning: cannot set random UUID on filesystem %s type %s: %s\n")
          dev typ msg
  ) fses;
  []

let fs_uuids_op = {
  name = "fs-uuids";
  enabled_by_default = true;
  heading = s_"Change filesystem UUIDs";
  pod_description = Some (s_"\
On guests and filesystem types where this is supported,
new random UUIDs are generated and assigned to filesystems.");
  extra_args = [];
  perform_on_filesystems = None;
  perform_on_devices = Some fs_uuids_perform;
}

let () = register_operation fs_uuids_op
