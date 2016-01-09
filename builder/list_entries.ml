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

let rec list_entries ~list_format ~sources index =
  match list_format with
  | `Short -> list_entries_short index
  | `Long -> list_entries_long ~sources index
  | `Json -> list_entries_json ~sources index

and list_entries_short index =
  List.iter (
    fun (name, { Index.printable_name = printable_name;
                 arch = arch;
                 hidden = hidden }) ->
      if not hidden then (
        printf "%-24s" name;
        printf " %-10s" arch;
        may (printf " %s") printable_name;
        printf "\n"
      )
  ) index

and list_entries_long ~sources index =
  let langs = Languages.languages () in

  List.iter (
    fun { Sources.uri = uri; gpgkey = gpgkey } ->
      printf (f_"Source URI: %s\n") uri;
      (match gpgkey with
      | Utils.No_Key -> ()
      | Utils.Fingerprint fp ->
        printf (f_"Fingerprint: %s\n") fp;
      | Utils.KeyFile kf ->
        printf (f_"Key: %s\n") kf;
      );
      printf "\n"
  ) sources;

  List.iter (
    fun (name, { Index.printable_name = printable_name;
                 arch = arch;
                 size = size;
                 compressed_size = compressed_size;
                 notes = notes;
                 aliases = aliases;
                 hidden = hidden }) ->
      if not hidden then (
        printf "%-24s %s\n" "os-version:" name;
        may (printf "%-24s %s\n" (s_"Full name:")) printable_name;
        printf "%-24s %s\n" (s_"Architecture:") arch;
        printf "%-24s %s\n" (s_"Minimum/default size:") (human_size size);
        (match compressed_size with
        | None -> ()
        | Some size ->
          printf "%-24s %s\n" (s_"Download size:") (human_size size);
        );
        (match aliases with
        | None -> ()
        | Some l -> printf "%-24s %s\n" (s_"Aliases:")
                      (String.concat " " l);
        );
        let notes = Languages.find_notes langs notes in
        (match notes with
        | notes :: _ ->
          printf "\n";
          printf (f_"Notes:\n\n%s\n") notes
        | [] -> ()
        );
        printf "\n"
      )
  ) index

and list_entries_json ~sources index =
  let json_sources =
    List.map (
      fun { Sources.uri = uri; gpgkey = gpgkey } ->
        let item = [ "uri", JSON.String uri ] in
        let item =
          match gpgkey with
          | Utils.No_Key -> item
          | Utils.Fingerprint fp ->
            ("fingerprint", JSON.String fp) :: item
          | Utils.KeyFile kf ->
            ("key", JSON.String kf) :: item in
        JSON.Dict item
    ) sources in
  let json_templates =
    List.map (
      fun (name, { Index.printable_name = printable_name;
                   arch = arch;
                   size = size;
                   compressed_size = compressed_size;
                   notes = notes;
                   aliases = aliases;
                   osinfo = osinfo;
                   hidden = hidden }) ->
        let item = [ "os-version", JSON.String name ] in
        let item =
          match printable_name with
          | None -> item
          | Some str -> ("full-name", JSON.String str) :: item in
        let item = ("arch", JSON.String arch) :: item in
        let item = ("size", JSON.Int64 size) :: item in
        let item =
          match compressed_size with
          | None -> item
          | Some n -> ("compressed-size", JSON.String (Int64.to_string n)) :: item in
        let item =
          let json_notes =
            List.fold_right (
              fun (lang, langnotes) acc ->
                let lang =
                  match lang with
                  | "" -> "C"
                  | x -> x in
                (lang, JSON.String langnotes) :: acc
            ) notes [] in
          if List.length json_notes = 0 then item
          else ("notes", JSON.Dict json_notes) :: item in
        let item =
          match aliases with
          | None -> item
          | Some l ->
            let l = List.map (fun x -> JSON.String x) l in
            ("aliases", JSON.List l) :: item in
        let item =
          match osinfo with
          | None -> item
          | Some str -> ("osinfo", JSON.String str) :: item in
        let item = ("hidden", JSON.Bool hidden) :: item in
        JSON.Dict (List.rev item)
    ) index in
  let doc = [
    "version", JSON.Int 1;
    "sources", JSON.List json_sources;
    "templates", JSON.List json_templates;
  ] in
  print_string (JSON.string_of_doc ~fmt:JSON.Indented doc);
  print_newline ()
