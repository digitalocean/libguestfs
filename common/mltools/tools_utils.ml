(* Common utilities for OCaml tools in libguestfs.
 * Copyright (C) 2010-2019 Red Hat Inc.
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

open Std_utils
open Common_gettext.Gettext
open Getopt.OptionName

type key_store = {
  keys : (string, key_store_key) Hashtbl.t;
}
and key_store_key =
  | KeyString of string
  | KeyFileName of string

external c_inspect_decrypt : Guestfs.t -> int64 -> (string * key_store_key) list -> unit = "guestfs_int_mllib_inspect_decrypt"
external c_set_echo_keys : unit -> unit = "guestfs_int_mllib_set_echo_keys" "noalloc"
external c_set_keys_from_stdin : unit -> unit = "guestfs_int_mllib_set_keys_from_stdin" "noalloc"

(* ANSI terminal colours. *)
let istty chan =
  Unix.isatty (Unix.descr_of_out_channel chan)

let ansi_green ?(chan = stdout) () =
  if colours () || istty chan then output_string chan "\x1b[0;32m"
let ansi_red ?(chan = stdout) () =
  if colours () || istty chan then output_string chan "\x1b[1;31m"
let ansi_blue ?(chan = stdout) () =
  if colours () || istty chan then output_string chan "\x1b[1;34m"
let ansi_magenta ?(chan = stdout) () =
  if colours () || istty chan then output_string chan "\x1b[1;35m"
let ansi_restore ?(chan = stdout) () =
  if colours () || istty chan then output_string chan "\x1b[0m"

(* Timestamped progress messages, used for ordinary messages when not
 * --quiet.
 *)
let start_t = Unix.gettimeofday ()
let message fs =
  let display str =
    if not (quiet ()) then (
      let t = sprintf "%.1f" (Unix.gettimeofday () -. start_t) in
      printf "[%6s] " t;
      ansi_green ();
      printf "%s" str;
      ansi_restore ();
      print_newline ()
    )
  in
  ksprintf display fs

(* Error messages etc. *)
let error ?(exit_code = 1) fs =
  let display str =
    let chan = stderr in
    ansi_red ~chan ();
    wrap ~chan (sprintf (f_"%s: error: %s") prog str);
    if not (verbose () && trace ()) then (
      prerr_newline ();
      prerr_newline ();
      wrap ~chan
           (sprintf (f_"If reporting bugs, run %s with debugging enabled and include the complete output:\n\n  %s -v -x [...]")
                    prog prog);
    );
    ansi_restore ~chan ();
    prerr_newline ();
    exit exit_code
  in
  ksprintf display fs

let warning fs =
  let display str =
    let chan = stdout in
    ansi_blue ~chan ();
    wrap ~chan (sprintf (f_"%s: warning: %s") prog str);
    ansi_restore ~chan ();
    print_newline ();
  in
  ksprintf display fs

let info fs =
  let display str =
    let chan = stdout in
    ansi_magenta ~chan ();
    wrap ~chan (sprintf (f_"%s: %s") prog str);
    ansi_restore ~chan ();
    print_newline ();
  in
  ksprintf display fs

(* Print a debug message. *)
let debug fs =
  let display str = if verbose () then prerr_endline str in
  ksprintf display fs

(* Common function to create a new Guestfs handle, with common options
 * (e.g. debug, tracing) already set.
 *)
let open_guestfs ?identifier () =
  let g = new Guestfs.guestfs () in
  if trace () then g#set_trace true;
  if verbose () then g#set_verbose true;
  Option.may g#set_identifier identifier;
  g

(* All the OCaml virt-* programs use this wrapper to catch exceptions
 * and print them nicely.
 *)
let run_main_and_handle_errors main =
  try main ()
  with
  | Unix.Unix_error (code, fname, "") -> (* from a syscall *)
    error (f_"%s: %s") fname (Unix.error_message code)
  | Unix.Unix_error (code, fname, param) -> (* from a syscall *)
    error (f_"%s: %s: %s") fname (Unix.error_message code) param
  | Sys_error msg ->                    (* from a syscall *)
    error (f_"%s") msg
  | Guestfs.Error msg ->                (* from libguestfs *)
    error (f_"libguestfs error: %s") msg
  | Failure msg ->                      (* from failwith/failwithf *)
    error (f_"failure: %s") msg
  | Invalid_argument msg ->             (* probably should never happen *)
    error (f_"internal error: invalid argument: %s") msg
  | Assert_failure (file, line, char) -> (* should never happen *)
    error (f_"internal error: assertion failed at %s, line %d, char %d")
      file line char
  | Not_found ->                        (* should never happen *)
    error (f_"internal error: Not_found exception was thrown")
  | exn ->                              (* something not matched above *)
    error (f_"exception: %s") (Printexc.to_string exn)

(* Print the version number and exit.  Used to implement --version in
 * the OCaml tools.
 *)
let print_version_and_exit () =
  printf "%s %s\n%!" prog Guestfs_config.package_version_full;
  exit 0

let generated_by =
  sprintf (f_"generated by %s %s") prog Guestfs_config.package_version_full

let virt_tools_data_dir =
  let dir = lazy (
    try Sys.getenv "VIRT_TOOLS_DATA_DIR"
    with Not_found -> Guestfs_config.datadir // "virt-tools"
  ) in
  fun () -> Lazy.force dir

(* Used by parse_size and parse_resize below. *)
let const_re = PCRE.compile "^([.0-9]+)([bKMG])$"
let plus_const_re = PCRE.compile "^\\+([.0-9]+)([bKMG])$"
let minus_const_re = PCRE.compile "^-([.0-9]+)([bKMG])$"
let percent_re = PCRE.compile "^([.0-9]+)%$"
let plus_percent_re = PCRE.compile "^\\+([.0-9]+)%$"
let minus_percent_re = PCRE.compile "^-([.0-9]+)%$"
let size_scaled f = function
  | "b" -> Int64.of_float f
  | "K" -> Int64.of_float (f *. 1024.)
  | "M" -> Int64.of_float (f *. 1024. *. 1024.)
  | "G" -> Int64.of_float (f *. 1024. *. 1024. *. 1024.)
  | _ -> assert false

(* Parse a size field, eg. "10G". *)
let parse_size field =
  if PCRE.matches const_re field then
    size_scaled (float_of_string (PCRE.sub 1)) (PCRE.sub 2)
  else
    error "%s: cannot parse size field" field

(* Parse a size field, eg. "10G", "+20%" etc.  Used particularly by
 * virt-resize --resize and --resize-force options.
 *)
let parse_resize oldsize field =
  if PCRE.matches const_re field then (
    size_scaled (float_of_string (PCRE.sub 1)) (PCRE.sub 2)
  )
  else if PCRE.matches plus_const_re field then (
    let incr = size_scaled (float_of_string (PCRE.sub 1)) (PCRE.sub 2) in
    oldsize +^ incr
  )
  else if PCRE.matches minus_const_re field then (
    let incr = size_scaled (float_of_string (PCRE.sub 1)) (PCRE.sub 2) in
    oldsize -^ incr
  )
  else if PCRE.matches percent_re field then (
    let percent = Int64.of_float (10. *. float_of_string (PCRE.sub 1)) in
    oldsize *^ percent /^ 1000L
  )
  else if PCRE.matches plus_percent_re field then (
    let percent = Int64.of_float (10. *. float_of_string (PCRE.sub 1)) in
    oldsize +^ oldsize *^ percent /^ 1000L
  )
  else if PCRE.matches minus_percent_re field then (
    let percent = Int64.of_float (10. *. float_of_string (PCRE.sub 1)) in
    oldsize -^ oldsize *^ percent /^ 1000L
  )
  else
    error "%s: cannot parse resize field" field

let human_size i =
  let sign, i = if i < 0L then "-", Int64.neg i else "", i in

  if i < 1024L then
    sprintf "%s%Ld" sign i
  else (
    let f = Int64.to_float i /. 1024. in
    let i = i /^ 1024L in
    if i < 1024L then
      sprintf "%s%.1fK" sign f
    else (
      let f = Int64.to_float i /. 1024. in
      let i = i /^ 1024L in
      if i < 1024L then
        sprintf "%s%.1fM" sign f
      else (
        let f = Int64.to_float i /. 1024. in
        (*let i = i /^ 1024L in*)
        sprintf "%s%.1fG" sign f
      )
    )
  )

type machine_readable_fn = {
  pr : 'a. ('a, unit, string, unit) format4 -> 'a;
} (* [@@unboxed] *)

type machine_readable_output_type =
  | NoOutput
  | Channel of out_channel
  | File of string
let machine_readable_output = ref NoOutput
let machine_readable_channel = ref None
let machine_readable () =
  let chan =
    if !machine_readable_channel = None then (
      let chan =
        match !machine_readable_output with
        | NoOutput -> None
        | Channel chan -> Some chan
        | File f -> Some (open_out f) in
      machine_readable_channel := chan
    );
    !machine_readable_channel
  in
  match chan with
  | None -> None
  | Some chan ->
    let pr fs =
      ksprintf (output_string chan) fs
    in
    Some { pr }

type cmdline_options = {
  getopt : Getopt.t;
  ks : key_store;
}

let create_standard_options argspec ?anon_fun ?(key_opts = false) ?(machine_readable = false) usage_msg =
  (** Install an exit hook to check gc consistency for --debug-gc *)
  let set_debug_gc () =
    at_exit (fun () -> Gc.compact()) in
  let parse_machine_readable = function
    | None ->
      machine_readable_output := Channel stdout
    | Some fmt ->
      let outtype, outname = String.split ":" fmt in
      if outname = "" then
        error (f_"invalid format string for --machine-readable: %s") fmt;
      (match outtype with
      | "file" -> machine_readable_output := File outname
      | "stream" ->
        let chan =
          match outname with
          | "stdout" -> stdout
          | "stderr" -> stderr
          | n ->
            error (f_"invalid output stream for --machine-readable: %s") fmt in
        machine_readable_output := Channel chan
      | n ->
        error (f_"invalid output for --machine-readable: %s") fmt
      )
  in
  let ks = {
    keys = Hashtbl.create 13;
  } in
  let argspec = [
    [ S 'V'; L"version" ], Getopt.Unit print_version_and_exit, s_"Display version and exit";
    [ S 'v'; L"verbose" ], Getopt.Unit set_verbose,  s_"Enable libguestfs debugging messages";
    [ S 'x' ],             Getopt.Unit set_trace,    s_"Enable tracing of libguestfs calls";
    [ L"debug-gc" ],       Getopt.Unit set_debug_gc, Getopt.hidden_option_description;
    [ S 'q'; L"quiet" ],   Getopt.Unit set_quiet,    s_"Don’t print progress messages";
    [ L"color"; L"colors";
      L"colour"; L"colours" ], Getopt.Unit set_colours, s_"Use ANSI colour sequences even if not tty";
  ] @ argspec in
  let argspec =
    argspec @
      (if key_opts then
      let parse_key_selector arg =
        let parts = String.nsplit ~max:3 ":" arg in
        match parts with
        | [ device; "key"; key ] ->
          Hashtbl.replace ks.keys device (KeyString key)
        | [ device; "file"; file ] ->
          Hashtbl.replace ks.keys device (KeyFileName file)
        | _ ->
          error (f_"invalid selector string for --key: %s") arg
      in
      [
        [ L"echo-keys" ],       Getopt.Unit c_set_echo_keys,       s_"Don’t turn off echo for passphrases";
        [ L"keys-from-stdin" ], Getopt.Unit c_set_keys_from_stdin, s_"Read passphrases from stdin";
        [ L"key" ], Getopt.String (s_"SELECTOR", parse_key_selector), s_"Specify a LUKS key";
      ]
      else []) @
      (if machine_readable then
      [
        [ L"machine-readable" ], Getopt.OptString ("format", parse_machine_readable), s_"Make output machine readable";
      ]
      else []) in
  let getopt = Getopt.create argspec ?anon_fun usage_msg in
  {
    getopt; ks;
  }

(* Run an external command, slurp up the output as a list of lines. *)
let external_command ?(echo_cmd = true) cmd =
  if echo_cmd then
    debug "%s" cmd;
  let chan = Unix.open_process_in cmd in
  let lines = ref [] in
  (try while true do lines := input_line chan :: !lines done
   with End_of_file -> ());
  let lines = List.rev !lines in
  let stat = Unix.close_process_in chan in
  (match stat with
  | Unix.WEXITED 0 -> ()
  | Unix.WEXITED i ->
    error (f_"external command ‘%s’ exited with error %d") cmd i
  | Unix.WSIGNALED i ->
    error (f_"external command ‘%s’ killed by signal %d") cmd i
  | Unix.WSTOPPED i ->
    error (f_"external command ‘%s’ stopped by signal %d") cmd i
  );
  lines

let rec run_commands ?(echo_cmd = true) cmds =
  let res = Array.make (List.length cmds) 0 in
  let pids =
    List.mapi (
      fun i (args, stdout_fd, stderr_fd) ->
        let run_res = do_run args ?stdout_fd ?stderr_fd in
        match run_res with
        | Either (pid, app, outfd, errfd) ->
          Some (i, pid, app, outfd, errfd)
        | Or code ->
          res.(i) <- code;
          None
    ) cmds in
  let pids = List.filter_map identity pids in
  let pids = ref pids in
  while !pids <> [] do
    let pid, stat = Unix.waitpid [] 0 in
    let matching_pair, new_pids =
      List.partition (
        fun (_, p, _, _, _) ->
          pid = p
      ) !pids in
    if matching_pair <> [] then (
      let matching_pair = List.hd matching_pair in
      let idx, _, app, outfd, errfd = matching_pair in
      pids := new_pids;
      res.(idx) <- do_teardown app outfd errfd stat
    );
  done;
  Array.to_list res

and run_command ?(echo_cmd = true) ?stdout_fd ?stderr_fd args =
  let run_res = do_run args ~echo_cmd ?stdout_fd ?stderr_fd in
  match run_res with
  | Either (pid, app, outfd, errfd) ->
    let _, stat = Unix.waitpid [] pid in
    do_teardown app outfd errfd stat
  | Or code ->
    code

and do_run ?(echo_cmd = true) ?stdout_fd ?stderr_fd args =
  let app = List.hd args in
  let get_fd default = function
    | None ->
      default
    | Some fd ->
      Unix.set_close_on_exec fd;
      fd
  in
  try
    let app = which app in
    let outfd = get_fd Unix.stdout stdout_fd in
    let errfd = get_fd Unix.stderr stderr_fd in
    if echo_cmd then
      debug "%s" (stringify_args args);
    let pid = Unix.create_process app (Array.of_list args) Unix.stdin
                outfd errfd in
    Either (pid, app, stdout_fd, stderr_fd)
  with
  | Executable_not_found _ ->
     debug "%s: executable not found" app;
     Or 127
  | Unix.Unix_error (errcode, fn, _) when errcode = Unix.ENOENT ->
     debug "%s: %s: executable not found" app fn;
     Or 127

and do_teardown app outfd errfd exitstat =
  Option.may Unix.close outfd;
  Option.may Unix.close errfd;
  match exitstat with
  | Unix.WEXITED i ->
    i
  | Unix.WSIGNALED i ->
    error (f_"external command ‘%s’ killed by signal %d") app i
  | Unix.WSTOPPED i ->
    error (f_"external command ‘%s’ stopped by signal %d") app i

let shell_command ?(echo_cmd = true) cmd =
  if echo_cmd then
    debug "%s" cmd;
  Sys.command cmd

(* Run uuidgen to return a random UUID. *)
let uuidgen () =
  let lines = external_command "uuidgen -r" in
  assert (List.length lines >= 1);
  let uuid = String.chomp (List.hd lines) in
  if String.length uuid < 10 then assert false; (* sanity check on uuidgen *)
  uuid

(* Remove a temporary directory on exit. *)
let rmdir_on_exit =
  let dirs = ref [] in
  let registered_handlers = ref false in

  let rec rmdirs () =
    List.iter (
      fun dir ->
        let cmd = sprintf "rm -rf %s" (Filename.quote dir) in
        ignore (shell_command cmd)
    ) !dirs
  and register_handlers () =
    (* Remove on exit. *)
    at_exit rmdirs
  in

  fun dir ->
    dirs := dir :: !dirs;
    if not !registered_handlers then (
      register_handlers ();
      registered_handlers := true
    )

(* Using the libguestfs API, recursively remove only files from the
 * given directory.  Useful for cleaning /var/cache etc in sysprep
 * without removing the actual directory structure.  Also if 'dir' is
 * not a directory or doesn't exist, ignore it.
 *
 * The optional filter is used to filter out files which will be
 * removed: files returning true are not removed.
 *
 * XXX Could be faster with a specific API for doing this.
 *)
let rm_rf_only_files (g : Guestfs.guestfs) ?filter dir =
  if g#is_dir dir then (
    let files = Array.map (Filename.concat dir) (g#find dir) in
    let files = Array.to_list files in
    let files = List.filter g#is_file files in
    let files = match filter with
    | None -> files
    | Some f -> List.filter (fun x -> not (f x)) files in
    List.iter g#rm files
  )

let truncate_recursive (g : Guestfs.guestfs) dir =
  let files = Array.map (Filename.concat dir) (g#find dir) in
  let files = Array.to_list files in
  let files = List.filter g#is_file files in
  List.iter g#truncate files

let debug_augeas_errors g =
  if verbose () then (
    try
      let errors = g#aug_match "/augeas/files//error" in
      let errors = Array.to_list errors in
      let map =
        List.fold_left (
          fun map error ->
            let detail_paths = g#aug_match (error ^ "//*") in
            let detail_paths = Array.to_list detail_paths in
            List.fold_left (
              fun map path ->
                (* path is "/augeas/files/<filename>/error/<field>".  Put
                 * <filename>, <field> and the value of this Augeas field
                 * into a map.
                 *)
                let i = String.find path "/error/" in
                assert (i >= 0);
                let filename = String.sub path 13 (i-13) in
                let field =
                  String.sub path (i+7) (String.length path - (i+7)) in

                let detail = g#aug_get path in

                let fmap : string StringMap.t =
                  try StringMap.find filename map
                  with Not_found -> StringMap.empty in
                let fmap = StringMap.add field detail fmap in
                StringMap.add filename fmap map
            ) map detail_paths
        ) StringMap.empty errors in

      let filenames = StringMap.keys map in
      let filenames = List.sort compare filenames in

      List.iter (
        fun filename ->
          eprintf "augeas failed to parse %s:\n" filename;
          let fmap = StringMap.find filename map in
          (try
            let msg = StringMap.find "message" fmap in
            eprintf " error \"%s\"" msg
          with Not_found -> ()
          );
          (try
            let line = StringMap.find "line" fmap
            and char = StringMap.find "char" fmap in
            eprintf " at line %s char %s" line char
          with Not_found -> ()
          );
          (try
            let lens = StringMap.find "lens" fmap in
            eprintf " in lens %s" lens
          with Not_found -> ()
          );
          eprintf "\n"
      ) filenames;

      flush stderr
    with
      Guestfs.Error msg -> eprintf "%s: augeas: %s (ignored)\n" prog msg
  )

(* Detect type of a file. *)
let detect_file_type filename =
  with_open_in filename (
    fun chan ->
      let get start size =
        try
          seek_in chan start;
          let b = Bytes.create size in
          really_input chan b 0 size;
          Some (Bytes.to_string b)
        with End_of_file | Invalid_argument _ -> None
      in
      if get 0 6 = Some "\2537zXZ\000" then `XZ
      else if get 0 4 = Some "PK\003\004" then `Zip
      else if get 0 4 = Some "PK\005\006" then `Zip
      else if get 0 4 = Some "PK\007\008" then `Zip
      else if get 257 6 = Some "ustar\000" then `Tar
      else if get 257 8 = Some "ustar\x20\x20\000" then `Tar
      else if get 0 2 = Some "\x1f\x8b" then `GZip
      else `Unknown
  )

let is_partition dev =
  try
    if not (is_block_device dev) then false
    else (
      let rdev = (Unix.stat dev).Unix.st_rdev in
      let major = Unix_utils.Dev_t.major rdev in
      let minor = Unix_utils.Dev_t.minor rdev in
      let path = sprintf "/sys/dev/block/%d:%d/partition" major minor in
      Unix.access path [Unix.F_OK];
      true
    )
  with Unix.Unix_error _ -> false

let inspect_mount_root g ?mount_opts_fn root =
  let mps = g#inspect_get_mountpoints root in
  let cmp (a,_) (b,_) =
    compare (String.length a) (String.length b) in
  let mps = List.sort cmp mps in
  List.iter (
    fun (mp, dev) ->
      let mountfn =
        match mount_opts_fn with
        | Some fn -> g#mount_options (fn mp)
        | None -> g#mount in
      try mountfn dev mp
      with Guestfs.Error msg -> warning (f_"%s (ignored)") msg
  ) mps

let inspect_mount_root_ro =
  inspect_mount_root ~mount_opts_fn:(fun _ -> "ro")

let is_btrfs_subvolume g fs =
  try
    ignore (g#mountable_subvolume fs); true
  with Guestfs.Error msg as exn ->
    if g#last_errno () = Guestfs.Errno.errno_EINVAL then false
    else raise exn

let inspect_decrypt g ks =
  (* Turn the keys in the key_store into a simpler struct, so it is possible
   * to read it using the C API.
   *)
  let keys_as_list = Hashtbl.fold (
    fun k v acc ->
      (k, v) :: acc
  ) ks.keys [] in
  (* Note we pass original 'g' even though it is not used by the
   * callee.  This is so that 'g' is kept as a root on the stack, and
   * so cannot be garbage collected while we are in the c_inspect_decrypt
   * function.
   *)
  c_inspect_decrypt g#ocaml_handle (Guestfs.c_pointer g#ocaml_handle)
    keys_as_list

let with_timeout op timeout ?(sleep = 2) fn =
  let start_t = Unix.gettimeofday () in
  let rec loop () =
    if Unix.gettimeofday () -. start_t > float_of_int timeout then
      error (f_"%s: operation timed out") op;

    match fn () with
    | Some r -> r
    | None ->
       Unix.sleep sleep;
       loop ()
  in
  loop ()
