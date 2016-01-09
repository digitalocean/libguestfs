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

open Types
open Utils
open Actions

(* Check function names etc. for consistency. *)
let () =
  let contains_uppercase str =
    let len = String.length str in
    let rec loop i =
      if i >= len then false
      else (
        let c = str.[i] in
        if c >= 'A' && c <= 'Z' then true
        else loop (i+1)
      )
    in
    loop 0
  in

  (* Check function names. *)
  List.iter (
    fun { name = name } ->
      let len = String.length name in

      if len >= 7 && String.sub name 0 7 = "guestfs" then
        failwithf "function name %s does not need 'guestfs' prefix" name;
      if name = "" then
        failwithf "function name is empty";
      if name.[0] < 'a' || name.[0] > 'z' then
        failwithf "function name %s must start with lowercase a-z" name;
      if String.contains name '-' then
        failwithf "function name %s should not contain '-', use '_' instead."
          name;
(*
      (* Functions mustn't be named '_opts' since that is reserved for
       * backwards compatibility functions.
       *)
      if len >= 5 && String.sub name (len-5) 5 = "_opts" then
        failwithf "function name %s cannot end with _opts" name
*)
  ) (all_functions @ fish_commands);

  (* Check added field was set to something. *)
  List.iter (
    function
    | { name = name; visibility = VPublic|VPublicNoFish|VDebug;
        added = (-1, _, _) } ->
       failwithf "function %s has no 'added' (version when added) field" name
    | _ -> ()
  ) all_functions;

  (* Check function parameter/return names. *)
  List.iter (
    fun { name = name; style = style } ->
      let check_arg_ret_name n =
        if contains_uppercase n then
          failwithf "%s param/ret %s should not contain uppercase chars"
            name n;
        if String.contains n '-' || String.contains n '_' then
          failwithf "%s param/ret %s should not contain '-' or '_'"
            name n;
        if n = "value" then
          failwithf "%s has a param/ret called 'value', which causes conflicts in the OCaml bindings, use something like 'val' or a more descriptive name" name;
        if n = "int" || n = "char" || n = "short" || n = "long" then
          failwithf "%s has a param/ret which conflicts with a C type (eg. 'int', 'char' etc.)" name;
        if n = "i" || n = "n" then
          failwithf "%s has a param/ret called 'i' or 'n', which will cause some conflicts in the generated code" name;
        if n = "argv" || n = "args" then
          failwithf "%s has a param/ret called 'argv' or 'args', which will cause some conflicts in the generated code" name;

        (* List Haskell, OCaml, C++ and C keywords here.
         * http://www.haskell.org/haskellwiki/Keywords
         * http://caml.inria.fr/pub/docs/manual-ocaml/lex.html#operator-char
         * http://en.wikipedia.org/wiki/C_syntax#Reserved_keywords
         * Formatted via: cat c haskell ocaml|sort -u|grep -vE '_|^val$' \
         *   |perl -pe 's/(.+)/"$1";/'|fmt -70
         * Omitting _-containing words, since they're handled above.
         * Omitting the OCaml reserved word, "val", is ok,
         * and saves us from renaming several parameters.
         *)
        let reserved = [
          "and"; "as"; "asr"; "assert"; "auto"; "begin"; "break"; "case";
          "char"; "class"; "const"; "constraint"; "continue"; "data";
          "default"; "delete"; "deriving"; "do"; "done"; "double"; "downto";
          "else"; "end"; "enum"; "exception"; "extern"; "external"; "false";
          "float"; "for"; "forall"; "foreign"; "fun"; "function"; "functor";
          "goto"; "hiding"; "if"; "import"; "in"; "include"; "infix"; "infixl";
          "infixr"; "inherit"; "initializer"; "inline"; "instance"; "int";
          "interface";
          "land"; "lazy"; "let"; "long"; "lor"; "lsl"; "lsr"; "lxor";
          "match"; "mdo"; "method"; "mod"; "module"; "mutable"; "new";
          "newtype"; "object"; "of"; "open"; "or"; "private"; "qualified";
          "rec"; "register"; "restrict"; "return"; "short"; "sig"; "signed";
          "sizeof"; "static"; "struct"; "switch"; "then"; "to"; "true"; "try";
          "template"; "type"; "typedef"; "union"; "unsigned"; "virtual"; "void";
          "volatile"; "when"; "where"; "while";
          ] in
        if List.mem n reserved then
          failwithf "%s has param/ret using reserved word %s" name n;
      in

      let ret, args, optargs = style in

      (match ret with
       | RErr -> ()
       | RInt n | RInt64 n | RBool n
       | RConstString n | RConstOptString n | RString n
       | RStringList n | RStruct (n, _) | RStructList (n, _)
       | RHashtable n | RBufferOut n ->
           check_arg_ret_name n
      );
      List.iter (fun arg -> check_arg_ret_name (name_of_argt arg)) args;
      List.iter (fun arg -> check_arg_ret_name (name_of_optargt arg)) optargs;
  ) all_functions;

  (* Maximum of 63 optargs permitted. *)
  List.iter (
    fun { name = name; style = _, _, optargs } ->
      if List.length optargs > 63 then
        failwithf "maximum of 63 optional args allowed for %s" name;
  ) all_functions;

  (* Some parameter types not supported for daemon functions. *)
  List.iter (
    fun { name = name; style = _, args, _ } ->
      let check_arg_type = function
        | Pointer _ ->
            failwithf "Pointer is not supported for daemon function %s."
              name
        | _ -> ()
      in
      List.iter check_arg_type args;
  ) daemon_functions;

  (* Check short descriptions. *)
  List.iter (
    fun { name = name; shortdesc = shortdesc } ->
      if shortdesc.[0] <> Char.lowercase shortdesc.[0] then
        failwithf "short description of %s should begin with lowercase." name;
      let c = shortdesc.[String.length shortdesc-1] in
      if c = '\n' || c = '.' then
        failwithf "short description of %s should not end with . or \\n." name
  ) (all_functions @ fish_commands);

  (* Check long descriptions. *)
  List.iter (
    fun { name = name; longdesc = longdesc } ->
      if longdesc.[String.length longdesc-1] = '\n' then
        failwithf "long description of %s should not end with \\n." name;
      if longdesc.[0] <> Char.uppercase longdesc.[0] then
        failwithf "long description of %s should begin with uppercase." name
  ) (all_functions @ fish_commands);

  (* Check proc_nrs. *)
  List.iter (
    function
    | { name = name; proc_nr = None } ->
      failwithf "daemon function %s should have proc_nr = Some n > 0" name
    | { name = name; proc_nr = Some n } when n <= 0 ->
      failwithf "daemon function %s should have proc_nr = Some n > 0" name
    | { proc_nr = Some _ } -> ()
  ) daemon_functions;

  List.iter (
    function
    | { name = name; proc_nr = Some _ } ->
      failwithf "non-daemon function %s should have proc_nr = None" name
    | { proc_nr = None } -> ()
  ) non_daemon_functions;

  let proc_nrs =
    List.map (
      function
      | { name = name; proc_nr = Some proc_nr } -> (name, proc_nr)
      | _ -> assert false
    ) daemon_functions in
  let proc_nrs =
    List.sort (fun (_,nr1) (_,nr2) -> compare nr1 nr2) proc_nrs in
  let rec loop = function
    | [] -> ()
    | [_] -> ()
    | (name1,nr1) :: ((name2,nr2) :: _ as rest) when nr1 < nr2 ->
        loop rest
    | (name1,nr1) :: (name2,nr2) :: _ ->
        failwithf "%s and %s have conflicting procedure numbers (%d, %d)"
          name1 name2 nr1 nr2
  in
  loop proc_nrs;

  (* Check flags. *)
  List.iter (
    fun ({ name = name; style = ret, _, _ } as f) ->
      List.iter (
        fun n ->
          if contains_uppercase n then
            failwithf "%s: guestfish alias %s should not contain uppercase chars" name n;
          if String.contains n '_' then
            failwithf "%s: guestfish alias %s should not contain '_'" name n
      ) f.fish_alias;
      (match f.deprecated_by with
      | Some n ->
        (* 'n' must be a cross-ref to the name of another action. *)
        if not (List.exists (
          function
          | { name = n' } when n = n' -> true
          | _ -> false
        ) all_functions) then
          failwithf "%s: deprecated_by flag must be cross-reference to another action" name
      | None -> ()
      );
      (match f.optional with
      | Some n ->
        if contains_uppercase n then
          failwithf "%s: optional group name %s should not contain uppercase chars" name n;
        if String.contains n '-' || String.contains n '_' then
          failwithf "%s: optional group name %s should not contain '-' or '_'" name n
      | None -> ()
      );
      if f.cancellable then (
        match ret with
        | RConstOptString n ->
          failwithf "%s: Cancellable function cannot return RConstOptString"
            name
        | _ -> ()
      )
  ) (all_functions @ fish_commands);

  (* Check blocking flag is set on all daemon functions. *)
  List.iter (
    function
    | { name = name; blocking = false } ->
      failwithf "%s: blocking flag should be 'true' on this daemon function"
        name
    | { blocking = true } -> ()
  ) daemon_functions;

  (* Check wrapper flag is set on all daemon functions. *)
  List.iter (
    function
    | { name = name; wrapper = false } ->
      failwithf "%s: wrapper flag should be 'true' on this daemon function"
        name
    | { wrapper = true } -> ()
  ) daemon_functions;

  (* Non-fish functions must have correct camel_name. *)
  List.iter (
    fun { name = name; camel_name = camel_name } ->
      if not (contains_uppercase camel_name) then
        failwithf "%s: camel case name must contain uppercase characters"
          name;
      if String.contains camel_name '_' then
        failwithf "%s: camel case name must not contain '_'" name;
  ) all_functions;

  (* ConfigOnly should only be specified on non_daemon_functions. *)
  List.iter (
    function
    | { name = name; config_only = true } ->
      failwithf "%s cannot have ConfigOnly flag" name
    | { config_only = false } -> ()
  ) (daemon_functions @ fish_commands);

  (* once_had_no_optargs can only apply if the function now has optargs. *)
  List.iter (
    function
    | { name = name; once_had_no_optargs = true; style = _, _, [] } ->
      failwithf "%s cannot have once_had_no_optargs flag and no optargs" name
    | { once_had_no_optargs = false } | { style = _, _, (_::_) } -> ()
  ) all_functions;

  (* Check tests. *)
  List.iter (
    function
      (* Ignore functions that have no tests.  We generate a
       * warning when the user does 'make check' instead.
       *)
    | { tests = [] } -> ()
    | { name = name; tests = tests } ->
      let funcs =
        List.map (
          fun (_, _, test, _) ->
            match seq_of_test test with
            | [] ->
              failwithf "%s has a test containing an empty sequence" name
            | cmds -> List.map List.hd cmds
        ) tests in
      let funcs = List.flatten funcs in

      let tested = List.mem name funcs in

      if not tested then
        failwithf "function %s has tests but does not test itself" name
  ) all_functions;

  List.iter (
    function
    | { tests = [] }
    | { optional = None } -> ()
    | { name = name; tests = tests; optional = Some optgroup } ->
      List.iter (
        function
        | _, IfAvailable o, _, _ when o = optgroup ->
          failwithf "%s test is marked 'IfAvailable %S', but since this function is in the %S optgroup, this is unnecessary; use 'Always' instead" name o optgroup
        | _ -> ()
      ) tests
  ) all_functions
