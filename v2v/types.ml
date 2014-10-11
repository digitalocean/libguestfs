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

(* Types.  See types.mli for documentation. *)

type source = {
  s_dom_type : string;
  s_name : string;
  s_orig_name : string;
  s_memory : int64;
  s_vcpu : int;
  s_features : string list;
  s_display : source_display option;
  s_disks : source_disk list;
  s_removables : source_removable list;
  s_nics : source_nic list;
}
and source_disk = {
  s_qemu_uri : string;
  s_format : string option;
  s_target_dev : string option;
}
and source_removable = {
  s_removable_type : [`CDROM|`Floppy];
  s_removable_target_dev : string option;
}
and source_nic = {
  s_mac : string option;
  s_vnet : string;
  s_vnet_orig : string;
  s_vnet_type : vnet_type;
}
and vnet_type = Bridge | Network
and source_display = {
  s_display_type : [`Window|`VNC|`Spice];
  s_keymap : string option;
  s_password : string option;
}

let rec string_of_source s =
  sprintf "    source name: %s
hypervisor type: %s
         memory: %Ld (bytes)
       nr vCPUs: %d
   CPU features: %s
        display: %s
disks:
%s
removable media:
%s
NICs:
%s
"
    s.s_name
    s.s_dom_type
    s.s_memory
    s.s_vcpu
    (String.concat "," s.s_features)
    (match s.s_display with
    | None -> ""
    | Some display -> string_of_source_display display)
    (String.concat "\n" (List.map string_of_source_disk s.s_disks))
    (String.concat "\n" (List.map string_of_source_removable s.s_removables))
    (String.concat "\n" (List.map string_of_source_nic s.s_nics))

and string_of_source_disk { s_qemu_uri = qemu_uri; s_format = format;
                            s_target_dev = target_dev } =
  sprintf "\t%s%s%s"
    qemu_uri
    (match format with
    | None -> ""
    | Some format -> " (" ^ format ^ ")")
    (match target_dev with
    | None -> ""
    | Some target_dev -> " [" ^ target_dev ^ "]")

and string_of_source_removable { s_removable_type = typ;
                                 s_removable_target_dev = target_dev } =
  sprintf "\t%s%s"
    (match typ with `CDROM -> "CD-ROM" | `Floppy -> "Floppy")
    (match target_dev with
    | None -> ""
    | Some target_dev -> " [" ^ target_dev ^ "]")

and string_of_source_nic { s_mac = mac; s_vnet = vnet; s_vnet_type = typ } =
  sprintf "\t%s \"%s\"%s"
    (match typ with Bridge -> "Bridge" | Network -> "Network")
    vnet
    (match mac with
    | None -> ""
    | Some mac -> " mac: " ^ mac)

and string_of_source_display { s_display_type = typ;
                               s_keymap = keymap; s_password = password } =
  sprintf "%s%s%s"
    (match typ with `Window -> "window" | `VNC -> "vnc" | `Spice -> "spice")
    (match keymap with None -> "" | Some km -> " " ^ km)
    (match password with None -> "" | Some _ -> " with password")

type overlay = {
  ov_overlay_file : string;
  ov_sd : string;
  ov_virtual_size : int64;
  ov_source : source_disk;
}

let string_of_overlay ov =
  sprintf "\
ov_overlay_file = %s
ov_sd = %s
ov_virtual_size = %Ld
ov_source = %s
"
    ov.ov_overlay_file
    ov.ov_sd
    ov.ov_virtual_size
    ov.ov_source.s_qemu_uri

type target = {
  target_file : string;
  target_format : string;
  target_estimated_size : int64 option;
  target_actual_size : int64 option;
  target_overlay : overlay;
}

let string_of_target t =
  sprintf "\
target_file = %s
target_format = %s
target_estimated_size = %s
target_overlay = %s
target_overlay.ov_source = %s
"
    t.target_file
    t.target_format
    (match t.target_estimated_size with
    | None -> "None" | Some i -> Int64.to_string i)
    t.target_overlay.ov_overlay_file
    t.target_overlay.ov_source.s_qemu_uri

type inspect = {
  i_root : string;
  i_type : string;
  i_distro : string;
  i_arch : string;
  i_major_version : int;
  i_minor_version : int;
  i_package_format : string;
  i_package_management : string;
  i_product_name : string;
  i_product_variant : string;
  i_mountpoints : (string * string) list;
  i_apps : Guestfs.application2 list;
  i_apps_map : Guestfs.application2 list StringMap.t;
}

type mpstat = {
  mp_dev : string;
  mp_path : string;
  mp_statvfs : Guestfs.statvfs;
  mp_vfs : string;
}

type guestcaps = {
  gcaps_block_bus : guestcaps_block_type;
  gcaps_net_bus : guestcaps_net_type;
  gcaps_video : guestcaps_video_type;
  gcaps_arch : string;
  gcaps_acpi : bool;
}
and guestcaps_block_type = Virtio_blk | IDE
and guestcaps_net_type = Virtio_net | E1000 | RTL8139
and guestcaps_video_type = QXL | Cirrus

class virtual input verbose = object
  method virtual as_options : string
  method virtual source : unit -> source
end

class virtual output verbose = object
  method virtual as_options : string
  method virtual prepare_targets : source -> target list -> target list
  method check_target_free_space (_ : source) (_ : target list) = ()
  method disk_create = (new Guestfs.guestfs ())#disk_create
  method virtual create_metadata : source -> target list -> guestcaps -> inspect -> unit
  method keep_serial_console = true
end
