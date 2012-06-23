(* This file is generated automatically by ./configure. *)

(** Gettext functions for virt-sparsify.

    The sparsify_gettext module provides gettext functions for
    sparsify, or dummy functions if ocaml-gettext was not available
    at configure time.

    {b Note}: Don't translate debug strings, or strings which are
    meant to be read/written only by machine.

    There are two ways to translate constant strings in OCaml programs.

    For ordinary strings, replace ["string"] with [s_"string"].  Since
    this is a function call to a function called [s_], you may have
    to put parentheses around the expression.

    For format strings, use:

{v
  printf (f_"zeroing filesystem %s") filename;
v}

    Note for format strings, the parentheses are almost always required,
    and they just go around the [(f_"string")], {i not} around the other
    arguments of the printf function.

    At build time, a program parses the OCaml code into an abstract
    syntax tree and statically determines all calls to the special
    [s_] and [f_] functions, which means: (a) You can be very loose
    with syntax, unlike ordinary xgettext, but (b) you cannot rename
    these functions.
*)

module Gettext = Gettext.Program (
  struct
    let textdomain = "libguestfs"
    let codeset = None
    let dir = None
    let dependencies = []
  end
) (GettextStub.Native)
