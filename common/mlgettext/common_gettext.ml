(* This file is generated automatically by ./configure. *)

module Gettext = struct
  external s_ : string -> string = "%identity"
  external f_ : ('a, 'b, 'c, 'd, 'e, 'f) format6
    -> ('a, 'b, 'c, 'd, 'e, 'f) format6
    = "%identity"
  let sn_ : string -> string -> int -> string
    = fun s p n -> if n = 1 then s else p
  let fn_ : ('a, 'b, 'c, 'd, 'e, 'f) format6
    -> ('a, 'b, 'c, 'd, 'e, 'f) format6
    -> int -> ('a, 'b, 'c, 'd, 'e, 'f) format6
    = fun s p n -> if n = 1 then s else p
end
