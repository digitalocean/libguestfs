(* virt-sysprep
 * Copyright (C) 2012 Fujitsu Limited
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

open Common_utils
open Sysprep_operation
open Common_gettext.Gettext

module G = Guestfs

let net_hostname_perform g root =
  let typ = g#inspect_get_type root in
  let distro = g#inspect_get_distro root in
  match typ, distro with
  | "linux", ("fedora"|"rhel"|"centos"|"scientificlinux"|"redhat-based") ->
    let filenames = g#glob_expand "/etc/sysconfig/network-scripts/ifcfg-*" in
    Array.iter (
      fun filename ->
        (* Replace HOSTNAME=... entry. *)
        let lines = Array.to_list (g#read_lines filename) in
        let lines = List.filter (
          fun line -> not (string_prefix line "HOSTNAME=")
        ) lines in
        let file = String.concat "\n" lines ^ "\n" in
        g#write filename file
    ) filenames;

    if filenames <> [||] then [ `Created_files ] else []

  | _ -> []

let net_hostname_op = {
  name = "net-hostname";
  enabled_by_default = true;
  heading = s_"Remove HOSTNAME in network interface configuration";
  pod_description = Some (s_"\
For Fedora and Red Hat Enterprise Linux,
this is removed from C<ifcfg-*> files.");
  extra_args = [];
  perform_on_filesystems = Some net_hostname_perform;
  perform_on_devices = None;
}

let () = register_operation net_hostname_op
