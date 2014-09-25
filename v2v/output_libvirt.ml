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
open DOM

let append_child child = function
  | PCData _ | Comment _  -> assert false
  | Element e -> e.e_children <- e.e_children @ [child]

let append_attr attr = function
  | PCData _ | Comment _ -> assert false
  | Element e -> e.e_attrs <- e.e_attrs @ [attr]

let create_libvirt_xml ?pool source targets guestcaps =
  let memory_k = source.s_memory /^ 1024L in

  let features =
    List.filter (
      fun feature ->
        (* drop acpi if the guest doesn't support it *)
        feature <> "acpi" || guestcaps.gcaps_acpi
    ) source.s_features in

  let disks =
    let block_prefix =
      match guestcaps.gcaps_block_bus with
      | Virtio_blk -> "vd" | IDE -> "hd" in
    let block_bus =
      match guestcaps.gcaps_block_bus with
      | Virtio_blk -> "virtio" | IDE -> "ide" in
    List.mapi (
      fun i t ->
        e "disk" [
          "type", if pool = None then "file" else "volume";
          "device", "disk"
        ] [
          e "driver" [
            "name", "qemu";
            "type", t.target_format;
            "cache", "none"
          ] [];
          (match pool with
          | None ->
            e "source" [
              "file", absolute_path t.target_file;
            ] []
          | Some pool ->
            e "source" [
              "pool", pool;
              "volume", Filename.basename t.target_file;
            ] []
          );
          e "target" [
            "dev", block_prefix ^ (drive_name i);
            "bus", block_bus;
          ] [];
        ]
    ) targets in

  let removables =
    (* CDs will be added as IDE devices if we're using virtio, else
     * they will be added as the same as the disk bus.  The original
     * s_removable_target_dev is ignored (same as old virt-v2v).
     *)
    let cdrom_bus, cdrom_block_prefix, cdrom_index =
      match guestcaps.gcaps_block_bus with
      | Virtio_blk | IDE -> "ide", "hd", ref 0
      (* | bus -> bus, "sd", ref (List.length targets) *) in

    (* Floppy disks always occupy their own virtual bus. *)
    let fd_bus = "fdc" and fd_index = ref 0 in

    List.map (
      function
      | { s_removable_type = `CDROM } ->
        let i = !cdrom_index in
        incr cdrom_index;
        let name = cdrom_block_prefix ^ drive_name i in
        e "disk" [ "device", "cdrom"; "type", "file" ] [
          e "driver" [ "name", "qemu"; "type", "raw" ] [];
          e "target" [ "dev", name; "bus", cdrom_bus ] []
        ]

      | { s_removable_type = `Floppy } ->
        let i = !fd_index in
        incr fd_index;
        let name = "fd" ^ drive_name i in
        e "disk" [ "device", "floppy"; "type", "file" ] [
          e "driver" [ "name", "qemu"; "type", "raw" ] [];
          e "target" [ "dev", name; "bus", fd_bus ] []
        ]
    ) source.s_removables in

  let nics =
    let net_model =
      match guestcaps.gcaps_net_bus with
      | Virtio_net -> "virtio" | E1000 -> "e1000" | RTL8139 -> "rtl8139" in
    List.map (
      fun { s_mac = mac; s_vnet_type = vnet_type;
            s_vnet = vnet; s_vnet_orig = vnet_orig } ->
        let vnet_type_str =
          match vnet_type with
          | Bridge -> "bridge" | Network -> "network" in

        let nic =
          let children = [
            e "source" [ vnet_type_str, vnet ] [];
            e "model" [ "type", net_model ] [];
          ] in
          let children =
            if vnet_orig <> vnet then
              Comment (sprintf "%s mapped from \"%s\" to \"%s\""
                         vnet_type_str vnet_orig vnet) :: children
            else
              children in
          e "interface" [ "type", vnet_type_str ] children in

        (match mac with
        | None -> ()
        | Some mac ->
          append_child (e "mac" [ "address", mac ] []) nic);

        nic
    ) source.s_nics in

  (* Same as old virt-v2v, we always add a display here even if it was
   * missing from the old metadata.
   *)
  let video, graphics =
    let video, graphics =
      match guestcaps.gcaps_video with
      | QXL ->
        e "video" [ "type", "qxl"; "ram", "65536" ] [],
        e "graphics" [ "type", "vnc" ] []
      | Cirrus ->
        e "video" [ "type", "cirrus"; "vram", "9216" ] [],
        e "graphics" [ "type", "spice" ] [] in

    append_attr ("heads", "1") video;

    append_attr ("autoport", "yes") graphics;
    (match source.s_display with
    | Some { s_keymap = Some km } -> append_attr ("keymap", km) graphics
    | _ -> ());
    (match source.s_display with
    | Some { s_password = Some pw } -> append_attr ("password", pw) graphics
    | _ -> ());

    video, graphics in

  let devices = disks @ removables @ nics @ [video] @ [graphics] @
  (* Standard devices added to every guest. *) [
    e "input" ["type", "tablet"; "bus", "usb"] [];
    e "input" ["type", "mouse"; "bus", "ps2"] [];
    e "console" ["type", "pty"] [];
  ] in

  let doc : doc =
    doc "domain" [
      "type", "kvm";                (* Always assume target is kvm? *)
    ] [
      e "name" [] [PCData source.s_name];
      e "memory" ["unit", "KiB"] [PCData (Int64.to_string memory_k)];
      e "currentMemory" ["unit", "KiB"] [PCData (Int64.to_string memory_k)];
      e "vcpu" [] [PCData (string_of_int source.s_vcpu)];
      e "os" [] [
        e "type" ["arch", guestcaps.gcaps_arch] [PCData "hvm"];
      ];
      e "features" [] (List.map (fun s -> e s [] []) features);

      e "on_poweroff" [] [PCData "destroy"];
      e "on_reboot" [] [PCData "restart"];
      e "on_crash" [] [PCData "restart"];

      e "devices" [] devices;
    ] (* /doc *) in

  doc

class output_libvirt verbose oc output_pool = object
  inherit output verbose

  method as_options =
    match oc with
    | None -> sprintf "-o libvirt -os %s" output_pool
    | Some uri -> sprintf "-o libvirt -oc %s -os %s" uri output_pool

  method prepare_targets source targets =
    (* Connect to output libvirt instance and check that the pool exists
     * and dump out its XML.
     *)
    let xml = Domainxml.pool_dumpxml ?conn:oc output_pool in
    let doc = Xml.parse_memory xml in
    let xpathctx = Xml.xpath_new_context doc in

    let xpath_to_string expr default =
      let obj = Xml.xpath_eval_expression xpathctx expr in
      if Xml.xpathobj_nr_nodes obj < 1 then default
      else (
        let node = Xml.xpathobj_node doc obj 0 in
        Xml.node_as_string node
      )
    in

    (* We can only output to a pool of type 'dir' (directory). *)
    let pool_type = xpath_to_string "/pool/@type" "" in
    if pool_type <> "dir" then
      error (f_"-o libvirt: output pool '%s' is not a directory (type='dir').  See virt-v2v(1) section \"OUTPUT TO LIBVIRT\"") output_pool;
    let target_path = xpath_to_string "/pool/target/path/text()" "" in
    if target_path = "" || not (is_directory target_path) then
      error (f_"-o libvirt: output pool '%s' has type='dir' but the /pool/target/path element either does not exist or is not a local directory.  See virt-v2v(1) section \"OUTPUT TO LIBVIRT\"") output_pool;

    (* Set up the targets. *)
    List.map (
      fun t ->
        let target_file =
          target_path // source.s_name ^ "-" ^ t.target_overlay.ov_sd in
        { t with target_file = target_file }
    ) targets

  method create_metadata source targets guestcaps _ =
    (* We copied directly into the final pool directory.  However we
     * have to tell libvirt.
     *)
    let cmd =
      match oc with
      | None -> sprintf "virsh pool-refresh %s" (quote output_pool)
      | Some uri ->
        sprintf "virsh -c %s pool-refresh %s"
          (quote uri) (quote output_pool) in
    if Sys.command cmd <> 0 then
      warning ~prog (f_"could not refresh libvirt pool %s") output_pool;

    (* Create the metadata. *)
    let doc = create_libvirt_xml ~pool:output_pool source targets guestcaps in

    let tmpfile, chan = Filename.open_temp_file "v2vlibvirt" ".xml" in
    DOM.doc_to_chan chan doc;
    close_out chan;

    (* Define the domain in libvirt. *)
    let cmd =
      match oc with
      | None -> sprintf "virsh define %s" (quote tmpfile)
      | Some uri ->
        sprintf "virsh -c %s define %s" (quote uri) (quote tmpfile) in
    if Sys.command cmd = 0 then (
      try Unix.unlink tmpfile with _ -> ()
    ) else (
      warning ~prog (f_"could not define libvirt domain.  The libvirt XML is still available in '%s'.  Try running 'virsh define %s' yourself instead.")
        tmpfile tmpfile
    );
end

let output_libvirt = new output_libvirt
let () = Modules_list.register_output_module "libvirt"
