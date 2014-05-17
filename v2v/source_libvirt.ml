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

let create_xml xml =
  let doc = Xml.parse_memory xml in
  let xpathctx = Xml.xpath_new_context doc in

  let xpath_to_string expr default =
    let obj = Xml.xpath_eval_expression xpathctx expr in
    if Xml.xpathobj_nr_nodes obj < 1 then default
    else (
      let node = Xml.xpathobj_node doc obj 0 in
      Xml.node_as_string node
    ) in
  let xpath_to_int expr default =
    let obj = Xml.xpath_eval_expression xpathctx expr in
    if Xml.xpathobj_nr_nodes obj < 1 then default
    else (
      let node = Xml.xpathobj_node doc obj 0 in
      let str = Xml.node_as_string node in
      try int_of_string str
      with Failure "int_of_string" ->
        error (f_"expecting XML expression to return an integer (expression: %s)")
          expr
    ) in

  let dom_type = xpath_to_string "/domain/@type" "" in
  let name = xpath_to_string "/domain/name/text()" "" in
  let memory = xpath_to_int "/domain/memory/text()" 0 in
  let memory = Int64.of_int memory *^ 1024L in
  let vcpu = xpath_to_int "/domain/vcpu/text()" 0 in
  let arch = xpath_to_string "/domain/os/type/@arch" "" in

  let features =
    let features = ref [] in
    let obj = Xml.xpath_eval_expression xpathctx "/domain/features/*" in
    let nr_nodes = Xml.xpathobj_nr_nodes obj in
    for i = 0 to nr_nodes-1 do
      let node = Xml.xpathobj_node doc obj i in
      features := Xml.node_name node :: !features
    done;
    !features in

  (* Non-removable disk devices. *)
  let disks =
    let disks = ref [] in
    let obj =
      Xml.xpath_eval_expression xpathctx
        "/domain/devices/disk[@device='disk']" in
    let nr_nodes = Xml.xpathobj_nr_nodes obj in
    if nr_nodes < 1 then
      error (f_"this guest has no non-removable disks");
    for i = 0 to nr_nodes-1 do
      let node = Xml.xpathobj_node doc obj i in
      Xml.xpathctx_set_current_context xpathctx node;

      let format =
        let format = xpath_to_string "driver/@type" "" in
        if format <> "" then Some format else None in

      (* The <disk type='...'> attribute may be 'block', 'file' or
       * 'network'.  We ignore any other types.
       *)
      match xpath_to_string "@type" "" with
      | "block" ->
        let path = xpath_to_string "source/@dev" "" in
        if path <> "" then disks := (path, format) :: !disks
      | "file" ->
        let path = xpath_to_string "source/@file" "" in
        if path <> "" then disks := (path, format) :: !disks
      | "network" ->
        (* We only handle <source protocol="nbd"> here, and that is
         * intended only for virt-p2v.  Any other network disk is
         * currently ignored.
         *)
        (match xpath_to_string "source/@protocol" "" with
        | "nbd" ->
          let host = xpath_to_string "source/host/@name" "" in
          let port = xpath_to_int "source/host/@port" 0 in
          if host <> "" && port > 0 then (
            (* Generate a qemu nbd URL.
             * XXX Quoting, although it's not needed for virt-p2v.
             *)
            let path = sprintf "nbd:%s:%d" host port in
            disks := (path, format) :: !disks
          )
        | "" -> ()
        | protocol ->
          eprintf (f_"%s: warning: network <disk> with <source protocol='%s'> was ignored")
            prog protocol
        )
      | disk_type ->
        eprintf (f_"%s: warning: <disk type='%s'> was ignored") prog disk_type
    done;
    List.rev !disks in

  (* XXX Much more metadata needs to be collected here:
   * - graphics
   * - cdroms
   * - floppies
   * - network interfaces
   * See: lib/Sys/VirtConvert/Connection/LibVirt.pm
   *)

  {
    s_dom_type = dom_type;
    s_name = name;
    s_memory = memory;
    s_vcpu = vcpu;
    s_arch = arch;
    s_features = features;
    s_disks = disks;
  }

let create_from_xml file =
  let xml = read_whole_file file in
  create_xml xml

let create libvirt_uri guest =
  let cmd =
    match libvirt_uri with
    | None -> sprintf "virsh dumpxml %s" (quote guest)
    | Some uri -> sprintf "virsh -c %s dumpxml %s" (quote uri) (quote guest) in
  let lines = external_command ~prog cmd in
  let xml = String.concat "\n" lines in
  create_xml xml
