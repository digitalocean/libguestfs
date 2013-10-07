(* virt-builder
 * Copyright (C) 2013 Red Hat Inc.
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

open Common_gettext.Gettext
open Common_utils

module G = Guestfs

open Printf

let rex_numbers = Str.regexp "^\\([0-9]+\\)\\(.*\\)$"
let rex_letters = Str.regexp_case_fold "^\\([a-z]+\\)\\(.*\\)$"

(* Originally:
 * http://rwmj.wordpress.com/2013/09/13/get-kernel-and-initramfs-from-a-disk-image/
 *)
let rec get_kernel ~debug ?format ?output disk =
  let g = new G.guestfs () in
  if debug then g#set_trace true;
  g#add_drive_opts ?format ~readonly:true disk;
  g#launch ();

  let roots = g#inspect_os () in
  if Array.length roots = 0 then (
    eprintf (f_"virt-builder: get-kernel: no operating system found\n");
    exit 1
  );
  if Array.length roots > 1 then (
    eprintf (f_"virt-builder: get-kernel: daual/mult-boot images are not supported by this tool\n");
    exit 1
  );
  let root = roots.(0) in

  (* Mount up the disks. *)
  let mps = g#inspect_get_mountpoints root in
  let cmp (a,_) (b,_) = compare (String.length a) (String.length b) in
  let mps = List.sort cmp mps in
  List.iter (
    fun (mp, dev) ->
      try g#mount_ro dev mp
      with Guestfs.Error msg -> eprintf "%s (ignored)\n" msg
  ) mps;

  (* Get all kernels and initramfses. *)
  let glob w = Array.to_list (g#glob_expand w) in
  let kernels = glob "/boot/vmlinuz-*" in
  let initrds = glob "/boot/initramfs-*" in

  (* Old RHEL: *)
  let initrds = if initrds <> [] then initrds else glob "/boot/initrd-*" in

  (* Debian/Ubuntu: *)
  let initrds = if initrds <> [] then initrds else glob "/boot/initrd.img-*" in

  (* Sort by version to get the latest version as first element. *)
  let kernels = List.rev (List.sort compare_version kernels) in
  let initrds = List.rev (List.sort compare_version initrds) in

  if kernels = [] then (
    eprintf (f_"virt-builder: no kernel found\n");
    exit 1
  );

  (* Download the latest. *)
  let outputdir =
    match output with
    | None -> Filename.current_dir_name
    | Some dir -> dir in
  let kernel_in = List.hd kernels in
  let kernel_out = outputdir // Filename.basename kernel_in in
  printf "download: %s -> %s\n%!" kernel_in kernel_out;
  g#download kernel_in kernel_out;

  if initrds <> [] then (
    let initrd_in = List.hd initrds in
    let initrd_out = outputdir // Filename.basename initrd_in in
    printf "download: %s -> %s\n%!" initrd_in initrd_out;
    g#download initrd_in initrd_out
  );

  (* Shutdown. *)
  g#shutdown ();
  g#close ()

and compare_version v1 v2 =
  compare (split_version v1) (split_version v2)

and split_version = function
  | "" -> []
  | str ->
    let first, rest =
      if Str.string_match rex_numbers str 0 then (
        let n = Str.matched_group 1 str in
        let rest = Str.matched_group 2 str in
        let n =
          try `Number (int_of_string n)
          with Failure "int_of_string" -> `String n in
        n, rest
      )
      else if Str.string_match rex_letters str 0 then
        `String (Str.matched_group 1 str), Str.matched_group 2 str
      else (
        let len = String.length str in
        `Char str.[0], String.sub str 1 (len-1)
      ) in
    first :: split_version rest
