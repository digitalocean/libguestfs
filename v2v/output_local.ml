(* virt-v2v
 * Copyright (C) 2009-2014 Red Hat Inc.
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

open Common_gettext.Gettext
open Common_utils

open Types
open Utils

class output_local verbose dir = object
  inherit output verbose

  method as_options = sprintf "-o local -os %s" dir

  method prepare_targets source targets =
    List.map (
      fun t ->
        let target_file = dir // source.s_name ^ "-" ^ t.target_overlay.ov_sd in
        { t with target_file = target_file }
    ) targets

  method create_metadata source targets guestcaps _ =
    let doc = Output_libvirt.create_libvirt_xml source targets guestcaps in

    let name = source.s_name in
    let file = dir // name ^ ".xml" in

    let chan = open_out file in
    DOM.doc_to_chan chan doc;
    close_out chan
end

let output_local = new output_local
let () = Modules_list.register_output_module "local"
