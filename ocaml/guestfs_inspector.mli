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

(** This is an OCaml language binding to the external [virt-inspector]
    program.

    For more information, please read the man page [virt-inspector(1)].
*)

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
(** The nested information returned from the {!inspect} function. *)

val inspect : ?connect:string -> ?xml:string -> string list -> operatingsystems
(** To inspect a libvirt domain called [name], pass a singleton
    list: [inspect [name]].  When using libvirt only, you may
    optionally pass a libvirt URI using [inspect ~connect:uri ...].

    To inspect a disk image or images, pass a list of the filenames
    of the disk images: [inspect filenames]

    This function inspects the given guest or disk images and
    returns a list of operating system(s) found and a large amount
    of information about them.  In the vast majority of cases,
    a virtual machine only contains a single operating system.

    If the optional [~xml] parameter is given, then this function
    skips running the external virt-inspector program and just
    parses the given XML directly (which is expected to be XML
    produced from a previous run of virt-inspector).  The list of
    names and connect URI are ignored in this case.

    This function can throw a wide variety of exceptions, for example
    if the external virt-inspector program cannot be found, or if
    it doesn't generate valid XML.
*)
