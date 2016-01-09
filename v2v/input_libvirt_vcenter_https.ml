(* virt-v2v
 * Copyright (C) 2009-2016 Red Hat Inc.
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

(** [-i libvirt] when the source is VMware vCenter *)

open Common_gettext.Gettext
open Common_utils

open Types
open Utils
open Input_libvirtxml
open Input_libvirt_other

open Printf

(* See RHBZ#1151033 and RHBZ#1153589. *)
let readahead_for_conversion = None
let readahead_for_copying = Some (64 * 1024 * 1024)

(* Subclass specialized for handling VMware vCenter over https. *)
class input_libvirt_vcenter_https
  cmdline_dcPath password libvirt_uri parsed_uri scheme server guest =
object
  inherit input_libvirt password libvirt_uri guest

  val saved_source_paths = Hashtbl.create 13
  val mutable dcPath = ""

  method source () =
    if verbose () then
      printf "input_libvirt_vcenter_https: source: scheme %s server %s\n%!"
        scheme server;

    error_if_libvirt_backend ();

    (* Get the libvirt XML.  This also checks (as a side-effect)
     * that the domain is not running.  (RHBZ#1138586)
     *)
    let xml = Domainxml.dumpxml ?password ?conn:libvirt_uri guest in
    let source, disks = parse_libvirt_xml ?conn:libvirt_uri xml in

    (* Find the <vmware:datacenterpath> element from the XML, if it
     * exists.  This was added in libvirt >= 1.2.20.
     *)
    let xml_dcPath =
      let doc = Xml.parse_memory xml in
      let xpathctx = Xml.xpath_new_context doc in
      Xml.xpath_register_ns xpathctx
        "vmware" "http://libvirt.org/schemas/domain/vmware/1.0";
      let xpath_string = xpath_string xpathctx in
      xpath_string "/domain/vmware:datacenterpath" in

    (* Calculate the dcPath we're going to use. *)
    dcPath <- (
      match cmdline_dcPath, xml_dcPath with
      (* Command line --dcpath parameter overrides everything, allowing
       * users to correct any mistakes in v2v or libvirt.
       *)
      | Some p, (None|Some _) ->
         if verbose () then
           printf "vcenter: using --dcpath from the command line: %s\n" p;
         p
      | None, Some p ->
         if verbose () then
           printf "vcenter: using <vmware:datacenterpath> from libvirt: %s\n" p;
         p
      | None, None ->
         let p = VCenter.guess_dcPath parsed_uri scheme in
         if verbose () then
           printf "vcenter: guessed dcPath from URI: %s\n" p;
         p
    );

    (* Save the original source paths, so that we can remap them again
     * in [#adjust_overlay_parameters].
     *)
    List.iter (
      function
      | { p_source = P_source_dev _ } ->
        (* Should never happen ... *)
        error (f_"source disk has <source dev=...> attribute in XML")
      | { p_source_disk = { s_disk_id = id }; p_source = P_dont_rewrite } ->
        Hashtbl.add saved_source_paths id None
      | { p_source_disk = { s_disk_id = id }; p_source = P_source_file path } ->
        Hashtbl.add saved_source_paths id (Some path)
    ) disks;

    let readahead = readahead_for_conversion in
    let disks = List.map (
      function
      | { p_source = P_source_dev _ } -> assert false
      | { p_source_disk = disk; p_source = P_dont_rewrite } -> disk
      | { p_source_disk = disk; p_source = P_source_file path } ->
        let qemu_uri =
          VCenter.map_source_to_uri readahead dcPath password
                                    parsed_uri scheme server path in

        (* The libvirt ESX driver doesn't normally specify a format, but
         * the format of the -flat file is *always* raw, so force it here.
         *)
        { disk with s_qemu_uri = qemu_uri; s_format = Some "raw" }
    ) disks in

    { source with s_disks = disks }

  (* See RHBZ#1151033 and RHBZ#1153589 for why this is necessary. *)
  method adjust_overlay_parameters overlay =
    let orig_path =
      try Hashtbl.find saved_source_paths overlay.ov_source.s_disk_id
      with Not_found -> failwith "internal error in adjust_overlay_parameters" in
    match orig_path with
    | None -> ()
    | Some orig_path ->
      let readahead = readahead_for_copying in
      let backing_qemu_uri =
        VCenter.map_source_to_uri readahead dcPath password
                                  parsed_uri scheme server orig_path in

      (* Rebase the qcow2 overlay to adjust the readahead parameter. *)
      let cmd =
        sprintf "qemu-img rebase -u -b %s %s"
          (quote backing_qemu_uri) (quote overlay.ov_overlay_file) in
      if verbose () then printf "%s\n%!" cmd;
      if Sys.command cmd <> 0 then
        warning (f_"qemu-img rebase failed (ignored)")
end

let input_libvirt_vcenter_https = new input_libvirt_vcenter_https
