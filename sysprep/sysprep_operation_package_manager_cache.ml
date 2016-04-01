(* virt-sysprep
 * Copyright (C) 2012 FUJITSU LIMITED
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

open Sysprep_operation
open Common_gettext.Gettext
open Common_utils

module G = Guestfs

let package_manager_cache_perform (g : Guestfs.guestfs) root side_effects =
  let packager = g#inspect_get_package_management root in
  let cache_dirs =
    match packager with
    | "apt" ->
      Some [ "/var/cache/apt/archives/" ]
    | "dnf" ->
      Some [ "/var/cache/dnf/" ]
    | "yum" ->
      Some [ "/var/cache/yum/" ]
    | "zypper" ->
      Some (Array.to_list (g#glob_expand "/var/cache/zypp*"))
    | _ -> None in
  match cache_dirs with
  | Some dirs -> List.iter (rm_rf_only_files g) dirs
  | _ -> ()

let op = {
  defaults with
    name = "package-manager-cache";
    enabled_by_default = true;
    heading = s_"Remove package manager cache";
    perform_on_filesystems = Some package_manager_cache_perform;
}

let () = register_operation op
