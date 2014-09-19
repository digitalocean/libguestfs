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

module G = Guestfs

let flag_reconfiguration ~verbose ~quiet g root side_effects =
  let typ = g#inspect_get_type root in
  if typ <> "windows" then (
    g#touch "/.unconfigured";
    side_effects#created_file ()
  )

let op = {
  defaults with
    name = "flag-reconfiguration";
    enabled_by_default = false;
    heading = s_"Flag the system for reconfiguration";
    pod_description = Some (s_"\
For Linux guests, this touches C</.unconfigured>, which causes
the first boot to interactively query the user for settings such
as the root password and timezone.");
    perform_on_filesystems = Some flag_reconfiguration;
}

let () = register_operation op;
