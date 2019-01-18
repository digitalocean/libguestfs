(* virt-v2v
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

open Printf

open Std_utils
open Tools_utils
open Common_gettext.Gettext

open Types
open Utils
open Create_libvirt_xml

class output_local dir = object
  inherit output

  method as_options = sprintf "-o local -os %s" dir

  method prepare_targets source overlays _ _ _ _ =
    List.map (
      fun (_, ov) -> TargetFile (dir // source.s_name ^ "-" ^ ov.ov_sd)
    ) overlays

  method supported_firmware = [ TargetBIOS; TargetUEFI ]

  method check_target_firmware guestcaps target_firmware =
    match target_firmware with
    | TargetBIOS -> ()
    | TargetUEFI ->
       (* XXX Can remove this method when libvirt supports
        * <loader type="efi"/> since then it will be up to
        * libvirt to check this.
        *)
       error_unless_uefi_firmware guestcaps.gcaps_arch

  method create_metadata source targets
                         target_buses guestcaps inspect target_firmware =
    (* We don't know what target features the hypervisor supports, but
     * assume a common set that libvirt supports.
     *)
    let target_features =
      match guestcaps.gcaps_arch with
      | "i686" -> [ "acpi"; "apic"; "pae" ]
      | "x86_64" -> [ "acpi"; "apic" ]
      | _ -> [] in

    let doc =
      create_libvirt_xml source targets target_buses
                         guestcaps target_features target_firmware inspect in

    let name = source.s_name in
    let file = dir // name ^ ".xml" in

    with_open_out file (fun chan -> DOM.doc_to_chan chan doc);

    if verbose () then (
      eprintf "resulting local libvirt XML:\n";
      DOM.doc_to_chan stderr doc;
      eprintf "\n%!";
    )
end

let output_local = new output_local
let () = Modules_list.register_output_module "local"
