(* libguestfs
 * Copyright (C) 2009-2014 Red Hat Inc.
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

open Printf

open Types
open Utils
open Pr
open Docstrings
open Optgroups
open Actions
open Structs
open C
open Events

(* Generate the OCaml bindings interface. *)
let rec generate_ocaml_mli () =
  generate_header OCamlStyle LGPLv2plus;

  pr "\
(** libguestfs bindings for OCaml.

    For API documentation, the canonical reference is the
    {{:http://libguestfs.org/guestfs.3.html}guestfs(3)} man page.
    The OCaml API uses almost exactly the same calls.

    For examples written in OCaml see the
    {{:http://libguestfs.org/guestfs-ocaml.3.html}guestfs-ocaml(3)} man page.
    *)

(** {2 Module style API}

    This is the module-style API.  There is also an object-oriented API
    (see the end of this file and {!guestfs})
    which is functionally completely equivalent, but is more compact. *)

type t
(** A [guestfs_h] handle. *)

exception Error of string
(** This exception is raised when there is an error. *)

exception Handle_closed of string
(** This exception is raised if you use a {!t} handle
    after calling {!close} on it.  The string is the name of
    the function. *)

val create : ?environment:bool -> ?close_on_exit:bool -> unit -> t
(** Create a {!t} handle.

    [?environment] defaults to [true].  If set to false, it sets
    the [GUESTFS_CREATE_NO_ENVIRONMENT] flag.

    [?close_on_exit] defaults to [true].  If set to false, it sets
    the [GUESTFS_CREATE_NO_CLOSE_ON_EXIT] flag. *)

val close : t -> unit
(** Close the {!t} handle and free up all resources used
    by it immediately.

    Handles are closed by the garbage collector when they become
    unreferenced, but callers can call this in order to provide
    predictable cleanup. *)

type event =
";
  List.iter (
    fun (name, _) ->
      pr "  | EVENT_%s\n" (String.uppercase name)
  ) events;
  pr "\n";

  pr "\
val event_all : event list
(** A list containing all event types. *)

type event_handle
(** The opaque event handle which can be used to delete event callbacks. *)

type event_callback =
  t -> event -> event_handle -> string -> int64 array -> unit
(** The event callback. *)

val set_event_callback : t -> event_callback -> event list -> event_handle
(** [set_event_callback g f es] sets [f] as the event callback function
    for all events in the set [es].

    Note that if the closure captures a reference to the handle,
    this reference will prevent the handle from being
    automatically closed by the garbage collector.  Since the
    handle is passed to the event callback, with careful programming
    it should be possible to avoid capturing the handle in the closure. *)

val delete_event_callback : t -> event_handle -> unit
(** [delete_event_callback g eh] removes a previously registered
    event callback.  See {!set_event_callback}. *)

val event_to_string : event list -> string
(** [event_to_string events] returns the event(s) as a printable string
    for debugging etc. *)

val last_errno : t -> int
(** [last_errno g] returns the last errno that happened on the handle [g]
    (or [0] if there was no errno).  Note that the returned integer is the
    raw errno number, and it is {i not} related to the {!Unix.error} type.

    Some raw errno numbers are exposed by the {!Guestfs.Errno} submodule,
    and we can add more as required.

    [last_errno] can be overwritten by subsequent operations on a handle,
    so if you want to capture the errno correctly, you must call this
    in the {!Error} exception handler, before any other operation on [g]. *)

(** The [Guestfs.Errno] submodule exposes some raw errno numbers,
    which you can use to test the return value of {!Guestfs.last_errno}. *)

module Errno : sig
  val errno_ENOTSUP : int
  val errno_ESRCH : int
end

";
  generate_ocaml_structure_decls ();

  (* The actions. *)
  List.iter (
    fun ({ name = name; style = style; deprecated_by = deprecated_by;
          non_c_aliases = non_c_aliases;
          shortdesc = shortdesc } as f) ->
      generate_ocaml_prototype name style;

      if is_documented f then (
        pr "(** %s" shortdesc;
        (match deprecated_by with
         | None -> ()
         | Some replacement ->
             pr "\n\n    @deprecated Use {!%s} instead\n" replacement
        );
        pr " *)\n";
      );
      pr "\n";

      (* Aliases. *)
      List.iter (
        fun alias ->
          generate_ocaml_prototype alias style;
          pr "\n";
      ) non_c_aliases;
  ) external_functions_sorted;

  pr "\
(** {2 Object-oriented API}

    This is an alternate way of calling the API using an object-oriented
    style, so you can use
    [g#]{{!guestfs.add_drive_opts}add_drive_opts} [filename]
    instead of [Guestfs.add_drive_opts g filename].
    Apart from the different style, it offers exactly the same functionality.

    Calling [new guestfs ()] creates both the object and the handle.
    The object and handle are closed either implicitly when the
    object is garbage collected, or explicitly by calling the
    [g#]{{!guestfs.close}close} [()] method.

    You can get the {!t} handle by calling
    [g#]{{!guestfs.ocaml_handle}ocaml_handle}.

    Note that methods that take no required parameters
    (except the implicit handle) get an extra unit [()] parameter.
    This is so you can create a closure from the method easily.
    For example [g#]{{!guestfs.get_verbose}get_verbose} [()]
    calls the method, whereas [g#get_verbose] is a function. *)

class guestfs : ?environment:bool -> ?close_on_exit:bool -> unit -> object
  method close : unit -> unit
  method set_event_callback : event_callback -> event list -> event_handle
  method delete_event_callback : event_handle -> unit
  method last_errno : unit -> int
  method ocaml_handle : t
";

  List.iter (
    fun { name = name; style = style; non_c_aliases = non_c_aliases } ->
      (match style with
      | _, [], _ ->
        pr "  method %s : " name;
        generate_ocaml_function_type ~extra_unit:true style;
        pr "\n"
      | _, (_::_), _ ->
        pr "  method %s : " name;
        generate_ocaml_function_type style;
        pr "\n"
      );
      List.iter (fun alias ->
        pr "  method %s : " alias;
        generate_ocaml_function_type style;
        pr "\n"
      ) non_c_aliases
  ) external_functions_sorted;

  pr "end\n"

(* Generate the OCaml bindings implementation. *)
and generate_ocaml_ml () =
  generate_header OCamlStyle LGPLv2plus;

  pr "\
type t

exception Error of string
exception Handle_closed of string

external create : ?environment:bool -> ?close_on_exit:bool -> unit -> t =
  \"ocaml_guestfs_create\"
external close : t -> unit = \"ocaml_guestfs_close\"

type event =
";
  List.iter (
    fun (name, _) ->
      pr "  | EVENT_%s\n" (String.uppercase name)
  ) events;
  pr "\n";

  pr "\
let event_all = [
";
  List.iter (
    fun (name, _) ->
      pr "  EVENT_%s;\n" (String.uppercase name)
  ) events;

  pr "\
]

type event_handle = int

type event_callback =
  t -> event -> event_handle -> string -> int64 array -> unit

external set_event_callback : t -> event_callback -> event list -> event_handle
  = \"ocaml_guestfs_set_event_callback\"
external delete_event_callback : t -> event_handle -> unit
  = \"ocaml_guestfs_delete_event_callback\"
external event_to_string : event list -> string
  = \"ocaml_guestfs_event_to_string\"

external last_errno : t -> int = \"ocaml_guestfs_last_errno\"

module Errno = struct
  external enotsup : unit -> int = \"ocaml_guestfs_get_ENOTSUP\" \"noalloc\"
  let errno_ENOTSUP = enotsup ()
  external esrch : unit -> int = \"ocaml_guestfs_get_ESRCH\" \"noalloc\"
  let errno_ESRCH = esrch ()
end

(* Give the exceptions names, so they can be raised from the C code. *)
let () =
  Callback.register_exception \"ocaml_guestfs_error\" (Error \"\");
  Callback.register_exception \"ocaml_guestfs_closed\" (Handle_closed \"\")

";

  generate_ocaml_structure_decls ();

  (* The actions. *)
  List.iter (
    fun { name = name; style = style; non_c_aliases = non_c_aliases } ->
      generate_ocaml_prototype ~is_external:true name style;
      List.iter (fun alias -> pr "let %s = %s\n" alias name) non_c_aliases
  ) external_functions_sorted;

  (* OO API. *)
  pr "
class guestfs ?environment ?close_on_exit () =
  let g = create ?environment ?close_on_exit () in
  object (self)
    method close () = close g
    method set_event_callback = set_event_callback g
    method delete_event_callback = delete_event_callback g
    method last_errno () = last_errno g
    method ocaml_handle = g
";

  List.iter (
    fun { name = name; style = style; non_c_aliases = non_c_aliases } ->
      (match style with
      | _, [], optargs ->
        (* No required params?  Add explicit unit. *)
        let optargs =
          String.concat ""
            (List.map (fun arg -> " ?" ^ name_of_optargt arg) optargs) in
        pr "    method %s%s () = %s g%s\n" name optargs name optargs
      | _, (_::_), _ ->
        pr "    method %s = %s g\n" name name
      );
      List.iter
        (fun alias -> pr "    method %s = self#%s\n" alias name) non_c_aliases
  ) external_functions_sorted;

  pr "  end\n"

(* Generate the OCaml bindings C implementation. *)
and generate_ocaml_c () =
  generate_header CStyle LGPLv2plus;

  pr "\
#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <caml/config.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/mlvalues.h>
#include <caml/signals.h>

#include \"guestfs.h\"

#include \"guestfs-c.h\"

/* Copy a hashtable of string pairs into an assoc-list.  We return
 * the list in reverse order, but hashtables aren't supposed to be
 * ordered anyway.
 */
static value
copy_table (char * const * argv)
{
  CAMLparam0 ();
  CAMLlocal5 (rv, pairv, kv, vv, cons);
  size_t i;

  rv = Val_int (0);
  for (i = 0; argv[i] != NULL; i += 2) {
    kv = caml_copy_string (argv[i]);
    vv = caml_copy_string (argv[i+1]);
    pairv = caml_alloc (2, 0);
    Store_field (pairv, 0, kv);
    Store_field (pairv, 1, vv);
    cons = caml_alloc (2, 0);
    Store_field (cons, 1, rv);
    rv = cons;
    Store_field (cons, 0, pairv);
  }

  CAMLreturn (rv);
}

";

  (* Struct copy functions. *)

  let emit_ocaml_copy_list_function typ =
    pr "static value\n";
    pr "copy_%s_list (const struct guestfs_%s_list *%ss)\n" typ typ typ;
    pr "{\n";
    pr "  CAMLparam0 ();\n";
    pr "  CAMLlocal2 (rv, v);\n";
    pr "  unsigned int i;\n";
    pr "\n";
    pr "  if (%ss->len == 0)\n" typ;
    pr "    CAMLreturn (Atom (0));\n";
    pr "  else {\n";
    pr "    rv = caml_alloc (%ss->len, 0);\n" typ;
    pr "    for (i = 0; i < %ss->len; ++i) {\n" typ;
    pr "      v = copy_%s (&%ss->val[i]);\n" typ typ;
    pr "      Store_field (rv, i, v);\n";
    pr "    }\n";
    pr "    CAMLreturn (rv);\n";
    pr "  }\n";
    pr "}\n";
    pr "\n";
  in

  List.iter (
    fun { s_name = typ; s_cols = cols } ->
      let has_optpercent_col =
        List.exists (function (_, FOptPercent) -> true | _ -> false) cols in

      pr "static value\n";
      pr "copy_%s (const struct guestfs_%s *%s)\n" typ typ typ;
      pr "{\n";
      pr "  CAMLparam0 ();\n";
      if has_optpercent_col then
        pr "  CAMLlocal3 (rv, v, v2);\n"
      else
        pr "  CAMLlocal2 (rv, v);\n";
      pr "\n";
      pr "  rv = caml_alloc (%d, 0);\n" (List.length cols);
      iteri (
        fun i col ->
          (match col with
           | name, FString ->
               pr "  v = caml_copy_string (%s->%s);\n" typ name
           | name, FBuffer ->
               pr "  v = caml_alloc_string (%s->%s_len);\n" typ name;
               pr "  memcpy (String_val (v), %s->%s, %s->%s_len);\n"
                 typ name typ name
           | name, FUUID ->
               pr "  v = caml_alloc_string (32);\n";
               pr "  memcpy (String_val (v), %s->%s, 32);\n" typ name
           | name, (FBytes|FInt64|FUInt64) ->
               pr "  v = caml_copy_int64 (%s->%s);\n" typ name
           | name, (FInt32|FUInt32) ->
               pr "  v = caml_copy_int32 (%s->%s);\n" typ name
           | name, FOptPercent ->
               pr "  if (%s->%s >= 0) { /* Some %s */\n" typ name name;
               pr "    v2 = caml_copy_double (%s->%s);\n" typ name;
               pr "    v = caml_alloc (1, 0);\n";
               pr "    Store_field (v, 0, v2);\n";
               pr "  } else /* None */\n";
               pr "    v = Val_int (0);\n";
           | name, FChar ->
               pr "  v = Val_int (%s->%s);\n" typ name
          );
          pr "  Store_field (rv, %d, v);\n" i
      ) cols;
      pr "  CAMLreturn (rv);\n";
      pr "}\n";
      pr "\n";
  ) external_structs;

  (* Emit a copy_TYPE_list function definition only if that function is used. *)
  List.iter (
    function
    | typ, (RStructListOnly | RStructAndList) ->
        (* generate the function for typ *)
        emit_ocaml_copy_list_function typ
    | typ, _ -> () (* empty *)
  ) (rstructs_used_by external_functions);

  (* The wrappers. *)
  List.iter (
    fun { name = name; style = (ret, args, optargs as style);
          blocking = blocking;
          c_function = c_function; c_optarg_prefix = c_optarg_prefix } ->
      pr "/* Automatically generated wrapper for function\n";
      pr " * ";
      generate_ocaml_prototype name style;
      pr " */\n";
      pr "\n";

      let params =
        "gv" ::
          List.map (fun arg -> name_of_argt arg ^ "v")
            (args_of_optargs optargs @ args) in

      let needs_extra_vs =
        match ret with RConstOptString _ -> true | _ -> false in

      pr "/* Emit prototype to appease gcc's -Wmissing-prototypes. */\n";
      pr "value ocaml_guestfs_%s (value %s" name (List.hd params);
      List.iter (pr ", value %s") (List.tl params); pr ");\n";
      pr "\n";

      pr "value\n";
      pr "ocaml_guestfs_%s (value %s" name (List.hd params);
      List.iter (pr ", value %s") (List.tl params);
      pr ")\n";
      pr "{\n";

      (* CAMLparam<N> can only take up to 5 parameters.  Further parameters
       * have to be passed in groups of 5 to CAMLxparam<N> calls.
       *)
      (match params with
       | p1 :: p2 :: p3 :: p4 :: p5 :: rest ->
           pr "  CAMLparam5 (%s);\n" (String.concat ", " [p1; p2; p3; p4; p5]);
           let rec loop = function
             | [] -> ()
             | p1 :: p2 :: p3 :: p4 :: p5 :: rest ->
               pr "  CAMLxparam5 (%s);\n"
                 (String.concat ", " [p1; p2; p3; p4; p5]);
               loop rest
             | rest ->
               pr "  CAMLxparam%d (%s);\n"
                 (List.length rest) (String.concat ", " rest)
           in
           loop rest
       | ps ->
           pr "  CAMLparam%d (%s);\n" (List.length ps) (String.concat ", " ps)
      );
      if not needs_extra_vs then
        pr "  CAMLlocal1 (rv);\n"
      else
        pr "  CAMLlocal3 (rv, v, v2);\n";
      pr "\n";

      pr "  guestfs_h *g = Guestfs_val (gv);\n";
      pr "  if (g == NULL)\n";
      pr "    ocaml_guestfs_raise_closed (\"%s\");\n" name;
      pr "\n";

      List.iter (
        function
        | Pathname n
        | Device n | Mountable n | Dev_or_Path n | Mountable_or_Path n
        | String n
        | FileIn n
        | FileOut n
        | Key n
        | GUID n ->
            (* Copy strings in case the GC moves them: RHBZ#604691 *)
            pr "  char *%s = guestfs___safe_strdup (g, String_val (%sv));\n" n n
        | OptString n ->
            pr "  char *%s =\n" n;
            pr "    %sv != Val_int (0) ?\n" n;
            pr "      guestfs___safe_strdup (g, String_val (Field (%sv, 0))) : NULL;\n" n
        | BufferIn n ->
            pr "  size_t %s_size = caml_string_length (%sv);\n" n n;
            pr "  char *%s = guestfs___safe_memdup (g, String_val (%sv), %s_size);\n" n n n
        | StringList n | DeviceList n ->
            pr "  char **%s = ocaml_guestfs_strings_val (g, %sv);\n" n n
        | Bool n ->
            pr "  int %s = Bool_val (%sv);\n" n n
        | Int n ->
            pr "  int %s = Int_val (%sv);\n" n n
        | Int64 n ->
            pr "  int64_t %s = Int64_val (%sv);\n" n n
        | Pointer (t, n) ->
            pr "  %s %s = (%s) (intptr_t) Int64_val (%sv);\n" t n t n
      ) args;

      (* Optional arguments. *)
      if optargs <> [] then (
        pr "  struct %s optargs_s = { .bitmask = 0 };\n" c_function;
        pr "  struct %s *optargs = &optargs_s;\n" c_function;
        List.iter (
          fun argt ->
            let n = name_of_optargt argt in
            let uc_n = String.uppercase n in
            pr "  if (%sv != Val_int (0)) {\n" n;
            pr "    optargs_s.bitmask |= %s_%s_BITMASK;\n" c_optarg_prefix uc_n;
            pr "    optargs_s.%s = " n;
            (match argt with
             | OBool _ -> pr "Bool_val (Field (%sv, 0))" n
             | OInt _ -> pr "Int_val (Field (%sv, 0))" n
             | OInt64 _ -> pr "Int64_val (Field (%sv, 0))" n
             | OString _ ->
                 pr "guestfs___safe_strdup (g, String_val (Field (%sv, 0)))" n
             | OStringList n ->
                 pr "ocaml_guestfs_strings_val (g, Field (%sv, 0))\n" n
            );
            pr ";\n";
            pr "  }\n";
        ) optargs
      );

      (match ret with
       | RErr -> pr "  int r;\n"
       | RInt _ -> pr "  int r;\n"
       | RInt64 _ -> pr "  int64_t r;\n"
       | RBool _ -> pr "  int r;\n"
       | RConstString _ | RConstOptString _ ->
           pr "  const char *r;\n"
       | RString _ -> pr "  char *r;\n"
       | RStringList _ ->
           pr "  size_t i;\n";
           pr "  char **r;\n"
       | RStruct (_, typ) ->
           pr "  struct guestfs_%s *r;\n" typ
       | RStructList (_, typ) ->
           pr "  struct guestfs_%s_list *r;\n" typ
       | RHashtable _ ->
           pr "  size_t i;\n";
           pr "  char **r;\n"
       | RBufferOut _ ->
           pr "  char *r;\n";
           pr "  size_t size;\n"
      );
      pr "\n";

      if blocking then
        pr "  caml_enter_blocking_section ();\n";
      pr "  r = %s " c_function;
      generate_c_call_args ~handle:"g" style;
      pr ";\n";
      if blocking then
        pr "  caml_leave_blocking_section ();\n";

      (* Free strings if we copied them above. *)
      List.iter (
        function
        | Pathname n | Device n | Mountable n
        | Dev_or_Path n | Mountable_or_Path n | String n
        | OptString n | FileIn n | FileOut n | BufferIn n
        | Key n | GUID n ->
            pr "  free (%s);\n" n
        | StringList n | DeviceList n ->
            pr "  guestfs___free_string_list (%s);\n" n;
        | Bool _ | Int _ | Int64 _ | Pointer _ -> ()
      ) args;
      List.iter (
        function
        | OBool _ | OInt _ | OInt64 _ -> ()
        | OString n ->
            pr "  if (%sv != Val_int (0))\n" n;
            pr "    free ((char *) optargs_s.%s);\n" n
        | OStringList n ->
            pr "  if (%sv != Val_int (0))\n" n;
            pr "    guestfs___free_string_list ((char **) optargs_s.%s);\n" n;
      ) optargs;

      (match errcode_of_ret ret with
       | `CannotReturnError -> ()
       | `ErrorIsMinusOne ->
           pr "  if (r == -1)\n";
           pr "    ocaml_guestfs_raise_error (g, \"%s\");\n" name;
       | `ErrorIsNULL ->
           pr "  if (r == NULL)\n";
           pr "    ocaml_guestfs_raise_error (g, \"%s\");\n" name;
      );
      pr "\n";

      (match ret with
       | RErr -> pr "  rv = Val_unit;\n"
       | RInt _ -> pr "  rv = Val_int (r);\n"
       | RInt64 _ ->
           pr "  rv = caml_copy_int64 (r);\n"
       | RBool _ -> pr "  rv = Val_bool (r);\n"
       | RConstString _ ->
           pr "  rv = caml_copy_string (r);\n"
       | RConstOptString _ ->
           pr "  if (r) { /* Some string */\n";
           pr "    v = caml_alloc (1, 0);\n";
           pr "    v2 = caml_copy_string (r);\n";
           pr "    Store_field (v, 0, v2);\n";
           pr "  } else /* None */\n";
           pr "    v = Val_int (0);\n";
       | RString _ ->
           pr "  rv = caml_copy_string (r);\n";
           pr "  free (r);\n"
       | RStringList _ ->
           pr "  rv = caml_copy_string_array ((const char **) r);\n";
           pr "  for (i = 0; r[i] != NULL; ++i) free (r[i]);\n";
           pr "  free (r);\n"
       | RStruct (_, typ) ->
           pr "  rv = copy_%s (r);\n" typ;
           pr "  guestfs_free_%s (r);\n" typ;
       | RStructList (_, typ) ->
           pr "  rv = copy_%s_list (r);\n" typ;
           pr "  guestfs_free_%s_list (r);\n" typ;
       | RHashtable _ ->
           pr "  rv = copy_table (r);\n";
           pr "  for (i = 0; r[i] != NULL; ++i) free (r[i]);\n";
           pr "  free (r);\n";
       | RBufferOut _ ->
           pr "  rv = caml_alloc_string (size);\n";
           pr "  memcpy (String_val (rv), r, size);\n";
           pr "  free (r);\n"
      );

      pr "  CAMLreturn (rv);\n";
      pr "}\n";
      pr "\n";

      if List.length params > 5 then (
        pr "/* Emit prototype to appease gcc's -Wmissing-prototypes. */\n";
        pr "value ocaml_guestfs_%s_byte (value *argv, int argn);\n" name;
        pr "\n";
        pr "value\n";
        pr "ocaml_guestfs_%s_byte (value *argv, int argn ATTRIBUTE_UNUSED)\n"
          name;
        pr "{\n";
        pr "  return ocaml_guestfs_%s (argv[0]" name;
        iteri (fun i _ -> pr ", argv[%d]" (i+1)) (List.tl params);
        pr ");\n";
        pr "}\n";
        pr "\n"
      )
  ) external_functions_sorted

and generate_ocaml_structure_decls () =
  List.iter (
    fun { s_name = typ; s_cols = cols } ->
      pr "type %s = {\n" typ;
      List.iter (
        function
        | name, FString -> pr "  %s : string;\n" name
        | name, FBuffer -> pr "  %s : string;\n" name
        | name, FUUID -> pr "  %s : string;\n" name
        | name, (FBytes|FInt64|FUInt64) -> pr "  %s : int64;\n" name
        | name, (FInt32|FUInt32) -> pr "  %s : int32;\n" name
        | name, FChar -> pr "  %s : char;\n" name
        | name, FOptPercent -> pr "  %s : float option;\n" name
      ) cols;
      pr "}\n";
      pr "\n"
  ) external_structs

and generate_ocaml_prototype ?(is_external = false) name style =
  if is_external then pr "external " else pr "val ";
  pr "%s : t -> " name;
  generate_ocaml_function_type style;
  if is_external then (
    pr " = ";
    let _, args, optargs = style in
    if List.length args + List.length optargs + 1 > 5 then
      pr "\"ocaml_guestfs_%s_byte\" " name;
    pr "\"ocaml_guestfs_%s\"" name
  );
  pr "\n"

and generate_ocaml_function_type ?(extra_unit = false) (ret, args, optargs) =
  List.iter (
    function
    | OBool n -> pr "?%s:bool -> " n
    | OInt n -> pr "?%s:int -> " n
    | OInt64 n -> pr "?%s:int64 -> " n
    | OString n -> pr "?%s:string -> " n
    | OStringList n -> pr "?%s:string array -> " n
  ) optargs;
  List.iter (
    function
    | Pathname _ | Device _ | Mountable _
    | Dev_or_Path _ | Mountable_or_Path _ | String _
    | FileIn _ | FileOut _ | BufferIn _ | Key _
    | GUID _ -> pr "string -> "
    | OptString _ -> pr "string option -> "
    | StringList _ | DeviceList _ -> pr "string array -> "
    | Bool _ -> pr "bool -> "
    | Int _ -> pr "int -> "
    | Int64 _ | Pointer _ -> pr "int64 -> "
  ) args;
  if extra_unit then pr "unit -> ";
  (match ret with
   | RErr -> pr "unit" (* all errors are turned into exceptions *)
   | RInt _ -> pr "int"
   | RInt64 _ -> pr "int64"
   | RBool _ -> pr "bool"
   | RConstString _ -> pr "string"
   | RConstOptString _ -> pr "string option"
   | RString _ | RBufferOut _ -> pr "string"
   | RStringList _ -> pr "string array"
   | RStruct (_, typ) -> pr "%s" typ
   | RStructList (_, typ) -> pr "%s array" typ
   | RHashtable _ -> pr "(string * string) list"
  )
