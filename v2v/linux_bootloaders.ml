(* virt-v2v
 * Copyright (C) 2009-2017 Red Hat Inc.
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

module G = Guestfs

class virtual bootloader = object
  method virtual name : string
  method virtual augeas_device_patterns : string list
  method virtual list_kernels : string list
  method virtual set_default_kernel : string -> unit
  method set_augeas_configuration () = false
  method virtual configure_console : unit -> unit
  method virtual remove_console : unit -> unit
  method update () = ()
end

(* Helper type used in detect_bootloader. *)
type bootloader_type =
  | Grub1
  | Grub2

(* Helper function for SUSE: remove (hdX,X) prefix from a path. *)
let remove_hd_prefix path =
  let rex = Str.regexp "^(hd.*)\\(.*\\)" in
  Str.replace_first rex "\\1" path

(* Grub1 (AKA grub-legacy) representation. *)
class bootloader_grub1 (g : G.guestfs) inspect grub_config =
  (* Grub prefix?  Usually "/boot". *)
  let grub_prefix =
    let mounts = g#inspect_get_mountpoints inspect.i_root in
    try
      List.find (
        fun path -> List.mem_assoc path mounts
      ) [ "/boot/grub"; "/boot" ]
    with Not_found -> "" in
object
  inherit bootloader

  method name = "grub1"

  method augeas_device_patterns = [
    "/files" ^ grub_config ^ "/*/kernel/root";
    "/files" ^ grub_config ^ "/*/kernel/resume";
    "/files/boot/grub/device.map/*[label() != \"#comment\"]";
    "/files/etc/sysconfig/grub/boot";
  ]

  method list_kernels =
    let paths =
      let expr = sprintf "/files%s/title/kernel" grub_config in
      let paths = g#aug_match expr in
      let paths = Array.to_list paths in

      (* Remove duplicates. *)
      let paths = remove_duplicates paths in

      (* Get the default kernel from grub if it's set. *)
      let default =
        let expr = sprintf "/files%s/default" grub_config in
        try
          let idx = g#aug_get expr in
          let idx = int_of_string idx in
          (* Grub indices are zero-based, augeas is 1-based. *)
          let expr =
            sprintf "/files%s/title[%d]/kernel" grub_config (idx+1) in
          Some expr
        with G.Error msg
             when String.find msg "aug_get: no matching node" >= 0 ->
          None in

      (* If a default kernel was set, put it at the beginning of the paths
       * list.  If not set, assume the first kernel always boots (?)
       *)
      match default with
      | None -> paths
      | Some p -> p :: List.filter ((<>) p) paths in

    (* Resolve the Augeas paths to kernel filenames. *)
    let vmlinuzes = List.map g#aug_get paths in

    (* Make sure kernel does not begin with (hdX,X). *)
    let vmlinuzes = List.map remove_hd_prefix vmlinuzes in

    (* Prepend grub filesystem. *)
    List.map ((^) grub_prefix) vmlinuzes

  method set_default_kernel vmlinuz =
    if not (String.is_prefix vmlinuz grub_prefix) then
      error (f_"kernel %s is not under grub tree %s")
        vmlinuz grub_prefix;
    let kernel_under_grub_prefix =
      let prefix_len = String.length grub_prefix in
      let kernel_len = String.length vmlinuz in
      String.sub vmlinuz prefix_len (kernel_len - prefix_len) in

    (* Find the grub entry for the given kernel. *)
    let paths = g#aug_match (sprintf "/files%s/title/kernel[. = '%s']"
                               grub_config kernel_under_grub_prefix) in
    let paths = Array.to_list paths in
    if paths = [] then
      error (f_"didn't find grub entry for kernel %s") vmlinuz;
    let path = List.hd paths in
    let rex = Str.regexp ".*/title\\[\\([1-9][0-9]*\\)\\]/kernel" in
    if not (Str.string_match rex path 0) then
      error (f_"internal error: regular expression did not match '%s'")
        path;
    let index = int_of_string (Str.matched_group 1 path) - 1 in
    g#aug_set (sprintf "/files%s/default" grub_config) (string_of_int index);
    g#aug_save ()

  method set_augeas_configuration () =
    let incls = g#aug_match "/augeas/load/Grub/incl" in
    let incls = Array.to_list incls in
    let incls_contains_conf =
      List.exists (fun incl -> g#aug_get incl = grub_config) incls in
    if not incls_contains_conf then (
      g#aug_set "/augeas/load/Grub/incl[last()+1]" grub_config;
      true;
    ) else false

  method configure_console () =
    let rex = Str.regexp "\\(.*\\)\\b\\([xh]vc0\\)\\b\\(.*\\)" in
    let expr = sprintf "/files%s/title/kernel/console" grub_config in

    let paths = g#aug_match expr in
    let paths = Array.to_list paths in
    List.iter (
      fun path ->
        let console = g#aug_get path in
        if Str.string_match rex console 0 then (
          let console = Str.global_replace rex "\\1ttyS0\\3" console in
          g#aug_set path console
        )
    ) paths;

    g#aug_save ()

  method remove_console () =
    let rex = Str.regexp "\\(.*\\)\\b\\([xh]vc0\\)\\b\\(.*\\)" in
    let expr = sprintf "/files%s/title/kernel/console" grub_config in

    let rec loop = function
      | [] -> ()
      | path :: paths ->
        let console = g#aug_get path in
        if Str.string_match rex console 0 then (
          ignore (g#aug_rm path);
          (* All the paths are invalid, restart the loop. *)
          let paths = g#aug_match expr in
          let paths = Array.to_list paths in
          loop paths
        )
        else
          loop paths
    in
    let paths = g#aug_match expr in
    let paths = Array.to_list paths in
    loop paths;

    g#aug_save ()
end

(** The method used to get and set the default kernel in Grub2. *)
type default_kernel_method =
  | MethodGrubby  (** Use the 'grubby' tool. *)
  | MethodPerlBootloader  (** Use the 'Bootloader::Tools' Perl module. *)
  | MethodNone  (** No known way. *)

(* Grub2 representation. *)
class bootloader_grub2 (g : G.guestfs) grub_config =

  let grub2_mkconfig_cmd =
    let elems = [
       "/sbin/grub2-mkconfig";
       "/usr/sbin/grub2-mkconfig";
       "/sbin/grub-mkconfig";
       "/usr/sbin/grub-mkconfig"
      ] in
    try List.find (g#is_file ~followsymlinks:true) elems
    with Not_found ->
      error (f_"failed to find grub2-mkconfig binary (but Grub2 was detected on guest)")
  in

  let get_default_method =
    let has_perl_bootloader () =
      try
        ignore (g#command [| "/usr/bin/perl"; "-MBootloader::Tools"; "-e1" |]);
        true
      with G.Error _ -> false
    in
    if g#exists "/sbin/grubby" then MethodGrubby
    else if has_perl_bootloader () then MethodPerlBootloader
    else (
      warning (f_"could not determine a way to update the configuration of Grub2");
      MethodNone
    ) in

object (self)
  inherit bootloader

  method private grub2_update_console ~remove () =
    let rex = Str.regexp "\\(.*\\)\\bconsole=[xh]vc0\\b\\(.*\\)" in

    let paths = [
      "/files/etc/sysconfig/grub/GRUB_CMDLINE_LINUX";
      "/files/etc/default/grub/GRUB_CMDLINE_LINUX";
      "/files/etc/default/grub/GRUB_CMDLINE_LINUX_DEFAULT"
    ] in
    let paths = List.map g#aug_match paths in
    let paths = List.map Array.to_list paths in
    let paths = List.flatten paths in
    (match paths with
    | [] ->
      if not remove then
        warning (f_"could not add grub2 serial console (ignored)")
      else
        warning (f_"could not remove grub2 serial console (ignored)")
    | path :: _ ->
      let grub_cmdline = g#aug_get path in
      if Str.string_match rex grub_cmdline 0 then (
        let new_grub_cmdline =
          if not remove then
            Str.global_replace rex "\\1console=ttyS0\\2" grub_cmdline
          else
            Str.global_replace rex "\\1\\2" grub_cmdline in
        g#aug_set path new_grub_cmdline;
        g#aug_save ();

        try
          ignore (g#command [| grub2_mkconfig_cmd; "-o"; grub_config |])
        with
          G.Error msg ->
            warning (f_"could not rebuild grub2 configuration file (%s).  This may mean that grub output will not be sent to the serial port, but otherwise should be harmless.  Original error message: %s")
              grub_config msg
      )
    )

  method name = "grub2"

  method augeas_device_patterns = [
    "/files/etc/sysconfig/grub/GRUB_CMDLINE_LINUX";
    "/files/etc/default/grub/GRUB_CMDLINE_LINUX";
    "/files/etc/default/grub/GRUB_CMDLINE_LINUX_DEFAULT";
    "/files/boot/grub2/device.map/*[label() != \"#comment\"]";
    "/files/boot/grub/device.map/*[label() != \"#comment\"]";
  ]

  method list_kernels =
    let get_default_image () =
      let res =
        match get_default_method with
        | MethodGrubby ->
          Some (g#command [| "grubby"; "--default-kernel" |])
        | MethodPerlBootloader ->
          let cmd =
            [| "/usr/bin/perl"; "-MBootloader::Tools"; "-e"; "
                  InitLibrary();
                  my $default = Bootloader::Tools::GetDefaultSection();
                  print $default->{image};
               " |] in
          Some (g#command cmd)
        | MethodNone ->
          None in
      match res with
      | None -> None
      | Some k ->
        let len = String.length k in
        let k =
          if len > 0 && k.[len-1] = '\n' then
            String.sub k 0 (len-1)
          else k in
        Some (remove_hd_prefix k)
    in

    let vmlinuzes =
      (match get_default_image () with
      | None -> []
      | Some k -> [k]) @
        (* This is how the grub2 config generator enumerates kernels. *)
        Array.to_list (g#glob_expand "/boot/kernel-*") @
        Array.to_list (g#glob_expand "/boot/vmlinuz-*") @
        Array.to_list (g#glob_expand "/vmlinuz-*") in
    let rex = Str.regexp ".*\\.\\(dpkg-.*|rpmsave|rpmnew\\)$" in
    let vmlinuzes = List.filter (
      fun file -> not (Str.string_match rex file 0)
    ) vmlinuzes in
    vmlinuzes

  method set_default_kernel vmlinuz =
    match get_default_method with
    | MethodGrubby ->
      ignore (g#command [| "grubby"; "--set-default"; vmlinuz |])
    | MethodPerlBootloader ->
      let cmd =
        [| "/usr/bin/perl"; "-MBootloader::Tools"; "-e"; sprintf "
            InitLibrary();
            my @sections = GetSectionList(type=>image, image=>\"%s\");
            my $section = GetSection(@sections);
            my $newdefault = $section->{name};
            SetGlobals(default, \"$newdefault\");
          " vmlinuz |] in
      ignore (g#command cmd)
    | MethodNone -> ()

  method configure_console = self#grub2_update_console ~remove:false

  method remove_console = self#grub2_update_console ~remove:true

  method update () =
    ignore (g#command [| grub2_mkconfig_cmd; "-o"; grub_config |])
end

let detect_bootloader (g : G.guestfs) inspect =
  let config_file, typ =
    let locations = [
      "/boot/grub2/grub.cfg", Grub2;
      "/boot/grub/grub.cfg", Grub2;
      "/boot/grub/menu.lst", Grub1;
      "/boot/grub/grub.conf", Grub1;
    ] in
    let locations =
      match inspect.i_firmware with
      | I_UEFI _ ->
        [
          "/boot/efi/EFI/redhat/grub.cfg", Grub2;
          "/boot/efi/EFI/redhat/grub.conf", Grub1;
        ] @ locations
      | I_BIOS -> locations in
    try
      List.find (
        fun (config_file, _) -> g#is_file ~followsymlinks:true config_file
      ) locations
    with
      Not_found ->
        error (f_"no bootloader detected") in

  match typ with
  | Grub1 ->
    if config_file = "/boot/efi/EFI/redhat/grub.conf" then
      g#aug_transform "grub" "/boot/efi/EFI/redhat/grub.conf";

    new bootloader_grub1 g inspect config_file
  | Grub2 -> new bootloader_grub2 g config_file
