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

(** Types. *)

type input =
| InputLibvirt of string option * string (* -i libvirt: -ic + guest name *)
| InputLibvirtXML of string         (* -i libvirtxml: XML file name *)
(** The input arguments as specified on the command line. *)

type output =
| OutputLibvirt of string option    (* -o libvirt: -oc *)
| OutputLocal of string             (* -o local: directory *)
| OutputRHEV of string              (* -o rhev: output storage *)
(** The output arguments as specified on the command line. *)

type source = {
  s_dom_type : string;                  (** Source domain type, eg "kvm" *)
  s_name : string;                      (** Guest name. *)
  s_memory : int64;                     (** Memory size (bytes). *)
  s_vcpu : int;                         (** Number of CPUs. *)
  s_arch : string;                      (** Architecture. *)
  s_features : string list;             (** Machine features. *)
  s_disks : source_disk list;           (** Disk images. *)
}
(** The source: metadata, disk images. *)

and source_disk = string * string option
(** A source file is a qemu URI and a format. *)

val string_of_source : source -> string
val string_of_source_disk : source_disk -> string

type overlay = {
  ov_overlay : string;       (** Local overlay file (qcow2 format). *)
  ov_target_file : string;   (** Destination file (real). *)
  ov_target_file_tmp : string;    (** Destination file (temporary). *)
  ov_target_format : string; (** Destination format (eg. -of option). *)
  ov_sd : string;            (** sdX libguestfs name of disk. *)
  ov_virtual_size : int64;   (** Virtual disk size in bytes. *)
  ov_preallocation : string option;     (** ?preallocation option. *)

  (* Note: the next two fields are for information only and must not
   * be opened/copied/etc.
   *)
  ov_source_file : string;   (** qemu URI for source file. *)
  ov_source_format : string option; (** Source file format, if known. *)
}
(** Disk overlays and destination disks. *)

val string_of_overlay : overlay -> string

type inspect = {
  i_root : string;                      (** Root device. *)
  i_apps : Guestfs.application2 list;   (** List of packages installed. *)
  i_apps_map : Guestfs.application2 list StringMap.t;
    (** This is a map from the app name to the application object.
        Since RPM allows multiple packages with the same name to be
        installed, the value is a list. *)
}
(** Inspection information.  Only the applications list is stored here
    as that is the only one which is slow/inconvenient to fetch. *)

type guestcaps = {
  gcaps_block_bus : string;    (** "virtio", "ide", possibly others *)
  gcaps_net_bus : string;      (** "virtio", "e1000", possibly others *)
  (* XXX acpi, display *)
}
(** Guest capabilities after conversion.  eg. Was virtio found or installed? *)
