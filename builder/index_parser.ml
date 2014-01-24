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

open Printf
open Unix

type index = (string * entry) list      (* string = "os-version" *)
and entry = {
  printable_name : string option;       (* the name= field *)
  osinfo : string option;
  file_uri : string;
  signature_uri : string option;        (* deprecated, will be removed in 1.26 *)
  checksum_sha512 : string option;
  revision : int;
  format : string option;
  size : int64;
  compressed_size : int64 option;
  expand : string option;
  lvexpand : string option;
  notes : (string * string) list;
  hidden : bool;

  sigchecker : Sigchecker.t;
}

let print_entry chan (name, { printable_name = printable_name;
                              file_uri = file_uri;
                              osinfo = osinfo;
                              signature_uri = signature_uri;
                              checksum_sha512 = checksum_sha512;
                              revision = revision;
                              format = format;
                              size = size;
                              compressed_size = compressed_size;
                              expand = expand;
                              lvexpand = lvexpand;
                              notes = notes;
                              hidden = hidden }) =
  let fp fs = fprintf chan fs in
  fp "[%s]\n" name;
  (match printable_name with
  | None -> ()
  | Some name -> fp "name=%s\n" name
  );
  (match osinfo with
  | None -> ()
  | Some id -> fp "osinfo=%s\n" id
  );
  fp "file=%s\n" file_uri;
  (match signature_uri with
  | None -> ()
  | Some uri -> fp "sig=%s\n" uri
  );
  (match checksum_sha512 with
  | None -> ()
  | Some uri -> fp "checksum[sha512]=%s\n" uri
  );
  fp "revision=%d\n" revision;
  (match format with
  | None -> ()
  | Some format -> fp "format=%s\n" format
  );
  fp "size=%Ld\n" size;
  (match compressed_size with
  | None -> ()
  | Some size -> fp "compressed_size=%Ld\n" size
  );
  (match expand with
  | None -> ()
  | Some expand -> fp "expand=%s\n" expand
  );
  (match lvexpand with
  | None -> ()
  | Some lvexpand -> fp "lvexpand=%s\n" lvexpand
  );
  (match notes with
  | ("", notes) :: _ -> fp "notes=%s\n" notes
  | _ :: _
  | [] -> ()
  );
  if hidden then fp "hidden=true\n"

(* Types returned by the C index parser. *)
type sections = section array
and section = string * fields           (* [name] + fields *)
and fields = field array
and field = string * string option * string    (* key + subkey + value *)

(* Calls yyparse in the C code. *)
external parse_index : string -> sections = "virt_builder_parse_index"

let get_index ~prog ~debug ~downloader ~sigchecker source =
  let corrupt_file () =
    eprintf (f_"\nThe index file downloaded from '%s' is corrupt.\nYou need to ask the supplier of this file to fix it and upload a fixed version.\n")
      source;
    exit 1
  in

  let rec get_index () =
    (* Get the index page. *)
    let tmpfile, delete_tmpfile = Downloader.download ~prog downloader source in

    (* Check index file signature (also verifies it was fully
     * downloaded and not corrupted in transit).
     *)
    Sigchecker.verify sigchecker tmpfile;

    (* Try parsing the file. *)
    let sections = parse_index tmpfile in
    if delete_tmpfile then
      (try Unix.unlink tmpfile with _ -> ());

    let sections = Array.to_list sections in
    let sections = List.map (
      fun (n, fields) ->
        n, Array.to_list fields
    ) sections in

    (* Check for repeated os-version names. *)
    let nseen = Hashtbl.create 13 in
    List.iter (
      fun (n, _) ->
        if Hashtbl.mem nseen n then (
          eprintf (f_"virt-builder: index is corrupt: os-version '%s' appears two or more times\n") n;
          corrupt_file ()
        );
        Hashtbl.add nseen n true
    ) sections;

    (* Check for repeated fields. *)
    List.iter (
      fun (n, fields) ->
        let fseen = Hashtbl.create 13 in
        List.iter (
          fun (field, subkey, _) ->
            let hashkey = (field, subkey) in
            if Hashtbl.mem fseen hashkey then (
              (match subkey with
              | Some value ->
                eprintf (f_"virt-builder: index is corrupt: %s: field '%s[%s]' appears two or more times\n") n field value
              | None ->
                eprintf (f_"virt-builder: index is corrupt: %s: field '%s' appears two or more times\n") n field);
              corrupt_file ()
            );
            Hashtbl.add fseen hashkey true
        ) fields
    ) sections;

    (* Turn the sections into the final index. *)
    let entries =
      List.map (
        fun (n, fields) ->
          let fields = List.map (fun (k, sk, v) -> (k, sk), v) fields in
          let printable_name =
            try Some (List.assoc ("name", None) fields) with Not_found -> None in
          let osinfo =
            try Some (List.assoc ("osinfo", None) fields) with Not_found -> None in
          let file_uri =
            try make_absolute_uri (List.assoc ("file", None) fields)
            with Not_found ->
              eprintf (f_"virt-builder: no 'file' (URI) entry for '%s'\n") n;
            corrupt_file () in
          let signature_uri =
            try Some (make_absolute_uri (List.assoc ("sig", None) fields))
            with Not_found -> None in
          let checksum_sha512 =
            try Some (List.assoc ("checksum", Some "sha512") fields)
            with Not_found ->
              try Some (List.assoc ("checksum", None) fields)
              with Not_found -> None in
          let revision =
            try int_of_string (List.assoc ("revision", None) fields)
            with
            | Not_found -> 1
            | Failure "int_of_string" ->
              eprintf (f_"virt-builder: cannot parse 'revision' field for '%s'\n")
                n;
              corrupt_file () in
          let format =
            try Some (List.assoc ("format", None) fields) with Not_found -> None in
          let size =
            try Int64.of_string (List.assoc ("size", None) fields)
            with
            | Not_found ->
              eprintf (f_"virt-builder: no 'size' field for '%s'\n") n;
              corrupt_file ()
            | Failure "int_of_string" ->
              eprintf (f_"virt-builder: cannot parse 'size' field for '%s'\n")
                n;
              corrupt_file () in
          let compressed_size =
            try Some (Int64.of_string (List.assoc ("compressed_size", None) fields))
            with
            | Not_found ->
              None
            | Failure "int_of_string" ->
              eprintf (f_"virt-builder: cannot parse 'compressed_size' field for '%s'\n")
                n;
              corrupt_file () in
          let expand =
            try Some (List.assoc ("expand", None) fields) with Not_found -> None in
          let lvexpand =
            try Some (List.assoc ("lvexpand", None) fields) with Not_found -> None in
          let notes =
            let rec loop = function
              | [] -> []
              | (("notes", subkey), value) :: xs ->
                let subkey = match subkey with
                | None -> ""
                | Some v -> v in
                (subkey, value) :: loop xs
              | _ :: xs -> loop xs in
            List.sort (
              fun (k1, _) (k2, _) ->
                String.compare k1 k2
            ) (loop fields) in
          let hidden =
            try bool_of_string (List.assoc ("hidden", None) fields)
            with
            | Not_found -> false
            | Failure "bool_of_string" ->
              eprintf (f_"virt-builder: cannot parse 'hidden' field for '%s'\n")
                n;
              corrupt_file () in

          let entry = { printable_name = printable_name;
                        osinfo = osinfo;
                        file_uri = file_uri;
                        signature_uri = signature_uri;
                        checksum_sha512 = checksum_sha512;
                        revision = revision;
                        format = format;
                        size = size;
                        compressed_size = compressed_size;
                        expand = expand;
                        lvexpand = lvexpand;
                        notes = notes;
                        hidden = hidden;
                        sigchecker = sigchecker } in
          n, entry
      ) sections in

    if debug then (
      eprintf "index file (%s) after parsing (C parser):\n" source;
      List.iter (print_entry Pervasives.stderr) entries
    );

    entries

  (* Verify same-origin policy for the file= and sig= fields. *)
  and make_absolute_uri path =
    if String.length path = 0 then (
      eprintf (f_"virt-builder: zero length path in the index file\n");
      corrupt_file ()
    )
    else if string_find path "://" >= 0 then (
      eprintf (f_"virt-builder: cannot use a URI ('%s') in the index file\n")
        path;
      corrupt_file ()
    )
    else if path.[0] = '/' then (
      eprintf (f_"virt-builder: you must use relative paths (not '%s') in the index file\n") path;
      corrupt_file ()
    )
    else (
      (* Construct the URI. *)
      try
        let i = String.rindex source '/' in
        String.sub source 0 (i+1) ^ path
      with
        Not_found -> source // path
    )
  in

  get_index ()
