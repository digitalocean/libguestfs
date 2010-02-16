(* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   src/generator.ml
 *   inspector/virt-inspector.rng
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2010 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *)

open Unix

type mountpoint = string * string (* dev -> data *)
type mountpoints = mountpoint list (* 1 or more *)
type filesystem = {
  filesystem_dev : string;
  filesystem_type : string;
  filesystem_content : string option;
  filesystem_label : string option;
  filesystem_uuid : string option;
  filesystem_spec : string option;
}
type filesystems = filesystem list (* 1 or more *)
type application = {
  application_name : string;
  application_epoch : string option;
  application_version : string;
  application_release : string;
  application_arch : string;
}
type applications = application list (* 0 or more *)
type alias = {
  alias_device : string;
  alias_modulename : string;
  alias_augeas : string option;
  alias_file : string;
}
type modprobealiases = alias list (* 0 or more *)
type initrd = string * string list (* 0 or more *) (* version -> module *)
type initrds = initrd list (* 0 or more *)
type kernel = {
  kernel_version : string;
  kernel_arch : string;
  kernel_modules : string list (* 0 or more *);
  kernel_path : string option;
  kernel_package : string option;
}
type kernels = kernel list (* 0 or more *)
type config = {
  config_default : bool;
  config_title : string;
  config_kernel : string;
  config_cmdline : string;
}
type boot = config list (* 0 or more *)
type operatingsystem = {
  operatingsystem_name : [`linux|`windows];
  operatingsystem_arch : string;
  operatingsystem_root : string;
  operatingsystem_distro : string option;
  operatingsystem_major_version : string option;
  operatingsystem_minor_version : string option;
  operatingsystem_package_format : string option;
  operatingsystem_package_management : string option;
  operatingsystem_mountpoints : mountpoints;
  operatingsystem_filesystems : filesystems;
  operatingsystem_applications : applications option;
  operatingsystem_modprobealiases : modprobealiases option;
  operatingsystem_initrds : initrds option;
  operatingsystem_kernels : kernels option;
  operatingsystem_boot : boot option;
}
type operatingsystems = operatingsystem list (* 1 or more *)

(* Misc functions which are used by the parser code below. *)
let first_child = function
  | Xml.Element (_, _, c::_) -> c
  | Xml.Element (name, _, []) ->
      failwith ("expected <" ^ name ^ "/> to have a child node")
  | Xml.PCData str ->
      failwith ("expected XML tag, but read PCDATA '" ^ str ^ "' instead")

let string_child_or_empty = function
  | Xml.Element (_, _, [Xml.PCData s]) -> s
  | Xml.Element (_, _, []) -> ""
  | Xml.Element (x, _, _) ->
      failwith ("expected XML tag with a single PCDATA child, but got " ^
                x ^ " instead")
  | Xml.PCData str ->
      failwith ("expected XML tag, but read PCDATA '" ^ str ^ "' instead")

let optional_child name xml =
  let children = Xml.children xml in
  try
    Some (List.find (function
                     | Xml.Element (n, _, _) when n = name -> true
                     | _ -> false) children)
  with
    Not_found -> None

let child name xml =
  match optional_child name xml with
  | Some c -> c
  | None ->
      failwith ("mandatory field <" ^ name ^ "/> missing in XML output")

let attribute name xml =
  try Xml.attrib xml name
  with Xml.No_attribute _ ->
    failwith ("mandatory attribute " ^ name ^ " missing in XML output")

let parse_name_1 =
  (fun x -> match Xml.pcdata (first_child x) with "linux" -> `linux|"windows" -> `windows | str -> failwith ("unexpected field value: " ^ str))
let parse_name = parse_name_1
let parse_arch_2 =
  string_child_or_empty
let parse_arch = parse_arch_2
let parse_root_3 =
  string_child_or_empty
let parse_root = parse_root_3
let parse_distro_4 =
  string_child_or_empty
let parse_distro = parse_distro_4
let parse_major_version_5 =
  string_child_or_empty
let parse_major_version = parse_major_version_5
let parse_minor_version_6 =
  string_child_or_empty
let parse_minor_version = parse_minor_version_6
let parse_package_format_7 =
  string_child_or_empty
let parse_package_format = parse_package_format_7
let parse_package_management_8 =
  string_child_or_empty
let parse_package_management = parse_package_management_8
let parse_dev_9 =
  string_child_or_empty
let parse_dev = parse_dev_9
let parse_mountpoint x =
  let t = (
    attribute "dev" x,
    string_child_or_empty x
  ) in
  t
let parse_mountpoints_10 =
  (fun x -> List.map parse_mountpoint (Xml.children x))
let parse_mountpoints = parse_mountpoints_10
let parse_dev_11 =
  string_child_or_empty
let parse_dev = parse_dev_11
let parse_type_12 =
  string_child_or_empty
let parse_type = parse_type_12
let parse_content_13 =
  string_child_or_empty
let parse_content = parse_content_13
let parse_label_14 =
  string_child_or_empty
let parse_label = parse_label_14
let parse_uuid_15 =
  string_child_or_empty
let parse_uuid = parse_uuid_15
let parse_spec_16 =
  string_child_or_empty
let parse_spec = parse_spec_16
let parse_filesystem x =
  let t = (
    attribute "dev" x,
    parse_type_12 (child "type" x),
    (function None -> None | Some x -> Some (parse_content_13 x)) (optional_child "content" x),
    (function None -> None | Some x -> Some (parse_label_14 x)) (optional_child "label" x),
    (function None -> None | Some x -> Some (parse_uuid_15 x)) (optional_child "uuid" x),
    (function None -> None | Some x -> Some (parse_spec_16 x)) (optional_child "spec" x)
  ) in
  (Obj.magic t : filesystem)
let parse_filesystems_17 =
  (fun x -> List.map parse_filesystem (Xml.children x))
let parse_filesystems = parse_filesystems_17
let parse_name_18 =
  string_child_or_empty
let parse_name = parse_name_18
let parse_epoch_19 =
  string_child_or_empty
let parse_epoch = parse_epoch_19
let parse_version_20 =
  string_child_or_empty
let parse_version = parse_version_20
let parse_release_21 =
  string_child_or_empty
let parse_release = parse_release_21
let parse_arch_22 =
  string_child_or_empty
let parse_arch = parse_arch_22
let parse_application x =
  let t = (
    parse_name_18 (child "name" x),
    (function None -> None | Some x -> Some (parse_epoch_19 x)) (optional_child "epoch" x),
    parse_version_20 (child "version" x),
    parse_release_21 (child "release" x),
    parse_arch_22 (child "arch" x)
  ) in
  (Obj.magic t : application)
let parse_applications_23 =
  (fun x -> List.map parse_application (Xml.children x))
let parse_applications = parse_applications_23
let parse_device_24 =
  string_child_or_empty
let parse_device = parse_device_24
let parse_modulename_25 =
  string_child_or_empty
let parse_modulename = parse_modulename_25
let parse_augeas_26 =
  string_child_or_empty
let parse_augeas = parse_augeas_26
let parse_file_27 =
  string_child_or_empty
let parse_file = parse_file_27
let parse_alias x =
  let t = (
    attribute "device" x,
    parse_modulename_25 (child "modulename" x),
    (function None -> None | Some x -> Some (parse_augeas_26 x)) (optional_child "augeas" x),
    parse_file_27 (child "file" x)
  ) in
  (Obj.magic t : alias)
let parse_modprobealiases_28 =
  (fun x -> List.map parse_alias (Xml.children x))
let parse_modprobealiases = parse_modprobealiases_28
let parse_version_29 =
  string_child_or_empty
let parse_version = parse_version_29
let parse_module_30 =
  string_child_or_empty
let parse_module = parse_module_30
let parse_initrd x =
  let t = (
    attribute "version" x,
    (fun x -> List.map parse_module_30 (Xml.children x)) x
  ) in
  t
let parse_initrds_31 =
  (fun x -> List.map parse_initrd (Xml.children x))
let parse_initrds = parse_initrds_31
let parse_version_32 =
  string_child_or_empty
let parse_version = parse_version_32
let parse_arch_33 =
  string_child_or_empty
let parse_arch = parse_arch_33
let parse_module_34 =
  string_child_or_empty
let parse_module = parse_module_34
let parse_modules_35 =
  (fun x -> List.map parse_module_34 (Xml.children x))
let parse_modules = parse_modules_35
let parse_path_36 =
  string_child_or_empty
let parse_path = parse_path_36
let parse_package_37 =
  string_child_or_empty
let parse_package = parse_package_37
let parse_kernel x =
  let t = (
    attribute "version" x,
    attribute "arch" x,
    parse_modules_35 (child "modules" x),
    (function None -> None | Some x -> Some (parse_path_36 x)) (optional_child "path" x),
    (function None -> None | Some x -> Some (parse_package_37 x)) (optional_child "package" x)
  ) in
  (Obj.magic t : kernel)
let parse_kernels_38 =
  (fun x -> List.map parse_kernel (Xml.children x))
let parse_kernels = parse_kernels_38
let parse_title_39 =
  string_child_or_empty
let parse_title = parse_title_39
let parse_kernel_40 =
  string_child_or_empty
let parse_kernel = parse_kernel_40
let parse_cmdline_41 =
  string_child_or_empty
let parse_cmdline = parse_cmdline_41
let parse_config x =
  let t = (
    (fun x -> try ignore (Xml.attrib x "default"); true with Xml.No_attribute _ -> false) x,
    parse_title_39 (child "title" x),
    parse_kernel_40 (child "kernel" x),
    parse_cmdline_41 (child "cmdline" x)
  ) in
  (Obj.magic t : config)
let parse_boot_42 =
  (fun x -> List.map parse_config (Xml.children x))
let parse_boot = parse_boot_42
let parse_operatingsystem x =
  let t = (
    parse_name_1 (child "name" x),
    parse_arch_2 (child "arch" x),
    parse_root_3 (child "root" x),
    (function None -> None | Some x -> Some (parse_distro_4 x)) (optional_child "distro" x),
    (function None -> None | Some x -> Some (parse_major_version_5 x)) (optional_child "major_version" x),
    (function None -> None | Some x -> Some (parse_minor_version_6 x)) (optional_child "minor_version" x),
    (function None -> None | Some x -> Some (parse_package_format_7 x)) (optional_child "package_format" x),
    (function None -> None | Some x -> Some (parse_package_management_8 x)) (optional_child "package_management" x),
    parse_mountpoints_10 (child "mountpoints" x),
    parse_filesystems_17 (child "filesystems" x),
    (function None -> None | Some x -> Some (parse_applications_23 x)) (optional_child "applications" x),
    (function None -> None | Some x -> Some (parse_modprobealiases_28 x)) (optional_child "modprobealiases" x),
    (function None -> None | Some x -> Some (parse_initrds_31 x)) (optional_child "initrds" x),
    (function None -> None | Some x -> Some (parse_kernels_38 x)) (optional_child "kernels" x),
    (function None -> None | Some x -> Some (parse_boot_42 x)) (optional_child "boot" x)
  ) in
  (Obj.magic t : operatingsystem)
let parse_operatingsystems_43 =
  (fun x -> List.map parse_operatingsystem (Xml.children x))
let parse_operatingsystems = parse_operatingsystems_43

(* Run external virt-inspector, then use parser to parse the XML. *)
let inspect ?connect ?xml names =
  let xml =
    match xml with
    | None ->
        if names = [] then invalid_arg "inspect: no names given";
        let cmd = [ "virt-inspector"; "--xml" ] @
          (match connect with None -> [] | Some uri -> [ "--connect"; uri ]) @
          names in
        let cmd = List.map Filename.quote cmd in
        let cmd = String.concat " " cmd in
        let chan = open_process_in cmd in
        let xml = Xml.parse_in chan in
        (match close_process_in chan with
         | WEXITED 0 -> ()
         | WEXITED _ -> failwith "external virt-inspector command failed"
         | WSIGNALED i | WSTOPPED i ->
             failwith ("external virt-inspector command died or stopped on sig " ^
                       string_of_int i)
        );
        xml
    | Some doc ->
        Xml.parse_string doc in
  parse_operatingsystems xml
