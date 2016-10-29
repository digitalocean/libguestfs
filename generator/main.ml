(* libguestfs
 * Copyright (C) 2009-2016 Red Hat Inc.
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *)

(* Please read generator/README first. *)

open Unix
open Printf

open Pr
open Actions
open Structs
open Types

open C
open Xdr
open Daemon
open Tests_c_api
open Fish
open Ocaml
open Perl
open Python
open Ruby
open Java
open Haskell
open Csharp
open Php
open Erlang
open Lua
open Gobject
open Golang
open Bindtests
open Errnostring
open Uefi
open Customize

let perror msg = function
  | Unix_error (err, _, _) ->
      eprintf "%s: %s\n" msg (error_message err)
  | exn ->
      eprintf "%s: %s\n" msg (Printexc.to_string exn)

(* In some directories the actions are split across this many C
 * files.  You can increase this number in order to reduce the number
 * of lines in each file (hence making compilation faster), but you
 * also have to modify .../Makefile.am.
 *)
let nr_actions_files = 7
let actions_subsets =
  let h i { name = name } = i = Hashtbl.hash name mod nr_actions_files in
  Array.init nr_actions_files (fun i -> List.filter (h i) actions)
let output_to_subset fs f =
  for i = 0 to nr_actions_files-1 do
    ksprintf (fun filename -> output_to filename (f actions_subsets.(i))) fs i
  done

(* Main program. *)
let () =
  let lock_fd =
    try openfile "BUGS" [O_RDWR] 0
    with
    | Unix_error (ENOENT, _, _) ->
        eprintf "\
You are probably running this from the wrong directory.
Run it from the top source directory using the command
  make -C generator stamp-generator
";
        exit 1
    | exn ->
        perror "open: BUGS" exn;
        exit 1 in

  (* Acquire a lock so parallel builds won't try to run the generator
   * twice at the same time.  Subsequent builds will wait for the first
   * one to finish.  Note the lock is released implicitly when the
   * program exits.
   *)
  (try lockf lock_fd F_LOCK 1
   with exn ->
     perror "lock: BUGS" exn;
     exit 1);

  output_to "src/guestfs_protocol.x" generate_xdr;
  output_to "src/guestfs.h" generate_guestfs_h;
  output_to "src/guestfs-internal-actions.h" generate_internal_actions_h;
  output_to "src/guestfs-internal-frontend-cleanups.h"
    generate_internal_frontend_cleanups_h;
  output_to "src/bindtests.c" generate_bindtests;
  output_to "src/guestfs-structs.pod" generate_structs_pod;
  output_to "src/guestfs-actions.pod" generate_actions_pod;
  output_to "src/guestfs-availability.pod" generate_availability_pod;
  output_to "src/errnostring-gperf.gperf" generate_errnostring_gperf;
  output_to "src/errnostring.c" generate_errnostring_c;
  output_to "src/errnostring.h" generate_errnostring_h;
  output_to "src/event-string.c" generate_event_string_c;
  output_to "src/MAX_PROC_NR" generate_max_proc_nr;
  output_to "src/libguestfs.syms" generate_linker_script;

  output_to "src/structs-compare.c" generate_client_structs_compare;
  output_to "src/structs-copy.c" generate_client_structs_copy;
  output_to "src/structs-free.c" generate_client_structs_free;
  output_to "src/structs-cleanup.c" generate_client_structs_cleanup;
  output_to "src/structs-print.c" generate_client_structs_print_c;
  output_to "src/structs-print.h" generate_client_structs_print_h;
  output_to "src/actions-variants.c" generate_client_actions_variants;
  output_to_subset "src/actions-%d.c" generate_client_actions;
  output_to "daemon/actions.h" generate_daemon_actions_h;
  output_to "daemon/stubs.h" generate_daemon_stubs_h;
  output_to_subset "daemon/stubs-%d.c" generate_daemon_stubs;
  output_to "daemon/dispatch.c" generate_daemon_dispatch;
  output_to "daemon/names.c" generate_daemon_names;
  output_to "daemon/optgroups.c" generate_daemon_optgroups_c;
  output_to "daemon/optgroups.h" generate_daemon_optgroups_h;
  output_to "daemon/lvm-tokenization.c" generate_daemon_lvm_tokenization;
  output_to "tests/c-api/tests.c" generate_c_api_tests;
  output_to "fish/cmds-gperf.gperf" generate_fish_cmds_gperf;
  output_to "fish/cmds.c" generate_fish_cmds;
  output_to_subset "fish/entries-%d.c" generate_fish_cmd_entries;
  output_to_subset "fish/run-%d.c" generate_fish_run_cmds;
  output_to "fish/run.h" generate_fish_run_header;
  output_to "fish/completion.c" generate_fish_completion;
  output_to "fish/event-names.c" generate_fish_event_names;
  output_to "fish/fish-cmds.h" generate_fish_cmds_h;
  output_to "fish/guestfish-commands.pod" generate_fish_commands_pod;
  output_to "fish/guestfish-actions.pod" generate_fish_actions_pod;
  output_to "fish/prepopts.c" generate_fish_prep_options_c;
  output_to "fish/prepopts.h" generate_fish_prep_options_h;
  output_to "fish/guestfish-prepopts.pod" generate_fish_prep_options_pod;
  output_to ~perm:0o555 "fish/test-prep.sh" generate_fish_test_prep_sh;
  output_to "ocaml/guestfs.mli" generate_ocaml_mli;
  output_to "ocaml/guestfs.ml" generate_ocaml_ml;
  output_to "ocaml/guestfs-c-actions.c" generate_ocaml_c;
  output_to "ocaml/guestfs-c-errnos.c" generate_ocaml_c_errnos;
  output_to "ocaml/bindtests.ml" generate_ocaml_bindtests;
  output_to "perl/lib/Sys/Guestfs.xs" generate_perl_xs;
  output_to "perl/lib/Sys/Guestfs.pm" generate_perl_pm;
  output_to "perl/bindtests.pl" generate_perl_bindtests;
  output_to "python/actions.h" generate_python_actions_h;
  output_to_subset "python/actions-%d.c" generate_python_actions;
  output_to "python/module.c" generate_python_module;
  output_to "python/structs.c" generate_python_structs;
  output_to "python/guestfs.py" generate_python_py;
  output_to "python/bindtests.py" generate_python_bindtests;
  output_to "ruby/ext/guestfs/actions.h" generate_ruby_h;
  output_to_subset "ruby/ext/guestfs/actions-%d.c" generate_ruby_c;
  output_to "ruby/ext/guestfs/module.c" generate_ruby_module;
  output_to "ruby/bindtests.rb" generate_ruby_bindtests;
  output_to "java/com/redhat/et/libguestfs/GuestFS.java" generate_java_java;

  List.iter (
    fun { s_name = typ; s_camel_name = jtyp } ->
      let cols = cols_of_struct typ in
      let filename = sprintf "java/com/redhat/et/libguestfs/%s.java" jtyp in
      output_to filename (generate_java_struct jtyp cols)
  ) external_structs;
  delete_except_generated
    ~skip:["java/com/redhat/et/libguestfs/LibGuestFSException.java";
           "java/com/redhat/et/libguestfs/LibGuestFSOutOfMemory.java";
           "java/com/redhat/et/libguestfs/EventCallback.java"]
    "java/com/redhat/et/libguestfs/*.java";

  output_to "java/Makefile.inc" generate_java_makefile_inc;
  output_to_subset "java/actions-%d.c" generate_java_c;
  output_to "java/com/redhat/et/libguestfs/.gitignore" generate_java_gitignore;
  output_to "java/Bindtests.java" generate_java_bindtests;
  output_to "haskell/Guestfs.hs" generate_haskell_hs;
  output_to "haskell/Bindtests.hs" generate_haskell_bindtests;
  output_to "csharp/Libguestfs.cs" generate_csharp;
  output_to "php/extension/php_guestfs_php.h" generate_php_h;
  output_to "php/extension/guestfs_php.c" generate_php_c;
  output_to "php/extension/tests/guestfs_090_bindtests.phpt" generate_php_bindtests;
  output_to "erlang/guestfs.erl" generate_erlang_erl;
  output_to "erlang/actions.h" generate_erlang_actions_h;
  output_to_subset "erlang/actions-%d.c" generate_erlang_actions;
  output_to "erlang/dispatch.c" generate_erlang_dispatch;
  output_to "erlang/structs.c" generate_erlang_structs;
  output_to ~perm:0o555 "erlang/bindtests.erl" generate_erlang_bindtests;
  output_to "lua/lua-guestfs.c" generate_lua_c;
  output_to "lua/bindtests.lua" generate_lua_bindtests;
  output_to "golang/src/libguestfs.org/guestfs/guestfs.go" generate_golang_go;
  output_to "golang/bindtests.go" generate_golang_bindtests;

  output_to "gobject/bindtests.js" generate_gobject_js_bindtests;
  output_to "gobject/Makefile.inc" generate_gobject_makefile;
  output_to "gobject/include/guestfs-gobject.h" generate_gobject_header;
  output_to "gobject/docs/guestfs-title.sgml" generate_gobject_doc_title;

  List.iter (
    fun { s_name = typ; s_cols = cols } ->
      let short = sprintf "struct-%s" typ in
      let filename =
        sprintf "gobject/include/guestfs-gobject/%s.h" short in
      output_to filename (generate_gobject_struct_header short typ cols);
      let filename = sprintf "gobject/src/%s.c" short in
      output_to filename (generate_gobject_struct_source short typ)
  ) external_structs;
  delete_except_generated "gobject/include/guestfs-gobject/struct-*.h";
  delete_except_generated "gobject/src/struct-*.c";

  List.iter (
    function
    | ({ name = name; style = (_, _, (_::_ as optargs)) } as f) ->
      let short = sprintf "optargs-%s" name in
      let filename =
        sprintf "gobject/include/guestfs-gobject/%s.h" short in
      output_to filename
        (generate_gobject_optargs_header short name f);
      let filename = sprintf "gobject/src/%s.c" short in
      output_to filename
        (generate_gobject_optargs_source short name optargs f)
    | { style = _, _, [] } -> ()
  ) (actions |> external_functions |> sort);
  delete_except_generated "gobject/include/guestfs-gobject/optargs-*.h";
  delete_except_generated "gobject/src/optargs-*.c";

  output_to "gobject/include/guestfs-gobject/tristate.h"
    generate_gobject_tristate_header;
  output_to "gobject/src/tristate.c" generate_gobject_tristate_source;

  output_to "gobject/include/guestfs-gobject/session.h"
    generate_gobject_session_header;
  output_to "gobject/src/session.c" generate_gobject_session_source;

  output_to "src/uefi.c" generate_uefi_c;
  output_to "v2v/uefi.ml" generate_uefi_ml;
  output_to "v2v/uefi.mli" generate_uefi_mli;

  output_to "customize/customize_cmdline.mli" generate_customize_cmdline_mli;
  output_to "customize/customize_cmdline.ml" generate_customize_cmdline_ml;
  output_to "customize/customize-synopsis.pod" generate_customize_synopsis_pod;
  output_to "customize/customize-options.pod" generate_customize_options_pod;

  (* Generate the list of files generated -- last. *)
  printf "generated %d lines of code\n" (get_lines_generated ());
  let files = List.sort compare (get_files_generated ()) in
  output_to "generator/files-generated.txt"
    (fun () -> List.iter (pr "%s\n") files)
