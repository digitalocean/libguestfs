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

(* Utilities used in virt-v2v only. *)

open Printf

open Common_gettext.Gettext
open Common_utils

external drive_name : int -> string = "v2v_utils_drive_name"
external drive_index : string -> int = "v2v_utils_drive_index"

external shell_unquote : string -> string = "v2v_utils_shell_unquote"

(* Map guest architecture found by inspection to the architecture
 * that KVM must emulate.  Note for x86 we assume a 64 bit hypervisor.
 *)
let kvm_arch = function
  | "i386" | "i486" | "i586" | "i686"
  | "x86_64" -> "x86_64"
  | "unknown" -> "x86_64" (* most likely *)
  | arch -> arch

(* Does qemu support the given sound card? *)
let qemu_supports_sound_card = function
  | Types.AC97
  | Types.ES1370
  | Types.ICH6
  | Types.ICH9
  | Types.PCSpeaker
  | Types.SB16
  | Types.USBAudio
    -> true

(* Find the UEFI firmware. *)
let find_uefi_firmware guest_arch =
  let files =
    (* The lists of firmware are actually defined in common/utils/uefi.c. *)
    match guest_arch with
    | "i386" | "i486" | "i586" | "i686" -> Uefi.uefi_i386_firmware
    | "x86_64" -> Uefi.uefi_x86_64_firmware
    | "aarch64" -> Uefi.uefi_aarch64_firmware
    | arch ->
       error (f_"don't know how to convert UEFI guests for architecture %s")
             guest_arch in
  let rec loop = function
    | [] ->
       error (f_"cannot find firmware for UEFI guests.\n\nYou probably need to install OVMF (x86-64), or AAVMF (aarch64)")
    | ({ Uefi.code = code; vars = vars_template } as ret) :: rest ->
       if Sys.file_exists code && Sys.file_exists vars_template then ret
       else loop rest
  in
  loop files

let compare_app2_versions app1 app2 =
  let i = compare app1.Guestfs.app2_epoch app2.Guestfs.app2_epoch in
  if i <> 0 then i
  else (
    let i =
      compare_version app1.Guestfs.app2_version app2.Guestfs.app2_version in
    if i <> 0 then i
    else
      compare_version app1.Guestfs.app2_release app2.Guestfs.app2_release
  )

let du filename =
  (* There's no OCaml binding for st_blocks, so run coreutils 'du'. *)
  let cmd =
    sprintf "du --block-size=1 %s | awk '{print $1}'" (quote filename) in
  (* XXX This can call error and so exit, but it would be preferable
   * to raise an exception here.
   *)
  let lines = external_command cmd in
  match lines with
  | line::_ -> Int64.of_string line
  | [] -> invalid_arg filename

let qemu_img_supports_offset_and_size () =
  (* We actually attempt to create a qcow2 file with a raw backing
   * file that has an offset and size.
   *)
  let tmp = Filename.temp_file "v2vqemuimgtst" ".img" in
  Unix.truncate tmp 1024;

  let json = [
      "file", JSON.Dict [
        "driver", JSON.String "raw";
        "offset", JSON.Int 512;
        "size", JSON.Int 512;
        "file", JSON.Dict [
          "filename", JSON.String tmp
        ]
      ]
  ] in

  let cmd =
    sprintf "qemu-img info json:%s >/dev/null%s"
            (quote (JSON.string_of_doc ~fmt:JSON.Compact json))
            (if verbose () then "" else " 2>&1") in
  debug "%s" cmd;
  let r = 0 = Sys.command cmd in
  Unix.unlink tmp;
  debug "qemu-img supports \"offset\" and \"size\" in json URLs: %b" r;
  r

let backend_is_libvirt () =
  let backend = (open_guestfs ())#get_backend () in
  let backend = fst (String.split ":" backend) in
  backend = "libvirt"

let find_file_in_tar tar filename =
  let lines = external_command (sprintf "tar tRvf %s" (Filename.quote tar)) in
  let rec loop lines =
    match lines with
    | [] -> raise Not_found
    | line :: lines -> (
      (* Lines have the form:
       * block <offset>: <perms> <owner>/<group> <size> <mdate> <mtime> <file>
       *)
      let elems = Str.bounded_split (Str.regexp " +") line 8 in
      if List.length elems = 8 && List.hd elems = "block" then (
        let elems = Array.of_list elems in
        let offset = elems.(1) in
        let size = elems.(4) in
        let fname = elems.(7) in

        if fname <> filename then
          loop lines
        else (
          let offset =
            try
              (* There should be a colon at the end *)
              let i = String.rindex offset ':' in
              if i == (String.length offset)-1 then
                Int64.of_string (String.sub offset 0 i)
              else
                failwith "colon at wrong position"
            with Failure _ | Not_found ->
              failwithf (f_"invalid offset returned by tar: %S") offset in

          let size =
            try Int64.of_string size
            with Failure _ ->
              failwithf (f_"invalid size returned by tar: %S") size in

          (* Note: Offset is actualy block number and there is a single
           * block with tar header at the beginning of the file. So skip
           * the header and convert the block number to bytes before
           * returning.
           *)
          (offset +^ 1L) *^ 512L, size
        )
      ) else
        failwithf (f_"failed to parse line returned by tar: %S") line
    )
  in
  loop lines
