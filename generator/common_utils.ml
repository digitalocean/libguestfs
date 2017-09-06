(* This file is generated from mllib/common_utils.ml *)
(*<stdlib>*)
open Printf
(*</stdlib>*)
(*<stdlib>*)

module Char = struct
    include Char

    let lowercase_ascii c =
      if (c >= 'A' && c <= 'Z')
      then unsafe_chr (code c + 32)
      else c

    let uppercase_ascii c =
      if (c >= 'a' && c <= 'z')
      then unsafe_chr (code c - 32)
      else c

    let isspace c =
      c = ' '
      (* || c = '\f' *) || c = '\n' || c = '\r' || c = '\t' (* || c = '\v' *)

    let isdigit = function
      | '0'..'9' -> true
      | _ -> false

    let isxdigit = function
      | '0'..'9' -> true
      | 'a'..'f' -> true
      | 'A'..'F' -> true
      | _ -> false

    let isalpha = function
      | 'a'..'z' -> true
      | 'A'..'Z' -> true
      | _ -> false

    let isalnum = function
      | '0'..'9' -> true
      | 'a'..'z' -> true
      | 'A'..'Z' -> true
      | _ -> false

    let hexdigit = function
      | '0' -> 0
      | '1' -> 1
      | '2' -> 2
      | '3' -> 3
      | '4' -> 4
      | '5' -> 5
      | '6' -> 6
      | '7' -> 7
      | '8' -> 8
      | '9' -> 9
      | 'a' | 'A' -> 10
      | 'b' | 'B' -> 11
      | 'c' | 'C' -> 12
      | 'd' | 'D' -> 13
      | 'e' | 'E' -> 14
      | 'f' | 'F' -> 15
      | _ -> -1
end

module String = struct
    include String

    let map f s =
      let len = String.length s in
      let b = Bytes.create len in
      for i = 0 to len-1 do
        Bytes.unsafe_set b i (f (unsafe_get s i))
      done;
      Bytes.to_string b

    let lowercase_ascii s = map Char.lowercase_ascii s
    let uppercase_ascii s = map Char.uppercase_ascii s

    let capitalize_ascii s =
      let b = Bytes.of_string s in
      Bytes.unsafe_set b 0 (Char.uppercase_ascii (Bytes.unsafe_get b 0));
      Bytes.to_string b

    let is_prefix str prefix =
      let n = length prefix in
      length str >= n && sub str 0 n = prefix

    let is_suffix str suffix =
      let sufflen = length suffix
      and len = length str in
      len >= sufflen && sub str (len - sufflen) sufflen = suffix

    let rec find s sub =
      let len = length s in
      let sublen = length sub in
      let rec loop i =
        if i <= len-sublen then (
          let rec loop2 j =
            if j < sublen then (
              if s.[i+j] = sub.[j] then loop2 (j+1)
              else -1
            ) else
              i (* found *)
          in
          let r = loop2 0 in
          if r = -1 then loop (i+1) else r
        ) else
          -1 (* not found *)
      in
      loop 0

    let rec replace s s1 s2 =
      let len = length s in
      let sublen = length s1 in
      let i = find s s1 in
      if i = -1 then s
      else (
        let s' = sub s 0 i in
        let s'' = sub s (i+sublen) (len-i-sublen) in
        s' ^ s2 ^ replace s'' s1 s2
      )

    let replace_char s c1 c2 =
      let b2 = Bytes.of_string s in
      let r = ref false in
      for i = 0 to Bytes.length b2 - 1 do
        if Bytes.unsafe_get b2 i = c1 then (
          Bytes.unsafe_set b2 i c2;
          r := true
        )
      done;
      if not !r then s else Bytes.to_string b2

    let rec nsplit sep str =
      let len = length str in
      let seplen = length sep in
      let i = find str sep in
      if i = -1 then [str]
      else (
        let s' = sub str 0 i in
        let s'' = sub str (i+seplen) (len-i-seplen) in
        s' :: nsplit sep s''
      )

    let split sep str =
      let len = length sep in
      let seplen = length str in
      let i = find str sep in
      if i = -1 then str, ""
      else (
        sub str 0 i, sub str (i + len) (seplen - i - len)
      )

    let rec lines_split str =
      let buf = Buffer.create 16 in
      let len = length str in
      let rec loop start len =
        try
          let i = index_from str start '\n' in
          if i > 0 && str.[i-1] = '\\' then (
            Buffer.add_substring buf str start (i-start-1);
            Buffer.add_char buf '\n';
            loop (i+1) len
          ) else (
            Buffer.add_substring buf str start (i-start);
            i+1
          )
        with Not_found ->
          if len > 0 && str.[len-1] = '\\' then (
            Buffer.add_substring buf str start (len-start-1);
            Buffer.add_char buf '\n'
          ) else
            Buffer.add_substring buf str start (len-start);
          len+1
      in
      let endi = loop 0 len in
      let line = Buffer.contents buf in
      if endi > len then
        [line]
      else
        line :: lines_split (sub str endi (len-endi))

    let random8 =
      let chars = "abcdefghijklmnopqrstuvwxyz0123456789" in
      fun () ->
      concat "" (
        List.map (
          fun _ ->
            let c = Random.int 36 in
            let c = chars.[c] in
            make 1 c
        ) [1;2;3;4;5;6;7;8]
      )

    let triml ?(test = Char.isspace) str =
      let i = ref 0 in
      let n = ref (String.length str) in
      while !n > 0 && test str.[!i]; do
        decr n;
        incr i
      done;
      if !i = 0 then str
      else String.sub str !i !n

    let trimr ?(test = Char.isspace) str =
      let n = ref (String.length str) in
      while !n > 0 && test str.[!n-1]; do
        decr n
      done;
      if !n = String.length str then str
      else String.sub str 0 !n

    let trim ?(test = Char.isspace) str =
      trimr ~test (triml ~test str)

    let count_chars c str =
      let count = ref 0 in
      for i = 0 to String.length str - 1 do
        if c = String.unsafe_get str i then incr count
      done;
      !count

    let explode str =
      let r = ref [] in
      for i = 0 to String.length str - 1 do
        let c = String.unsafe_get str i in
        r := c :: !r;
      done;
      List.rev !r

    let map_chars f str =
      List.map f (explode str)

    let spaces n = String.make n ' '
end

let (//) = Filename.concat
let quote = Filename.quote

let subdirectory parent path =
  if path = parent then
    ""
  else if String.is_prefix path (parent // "") then (
    let len = String.length parent in
    String.sub path (len+1) (String.length path - len-1)
  ) else
    invalid_arg (sprintf "%S is not a path prefix of %S" parent path)

let ( +^ ) = Int64.add
let ( -^ ) = Int64.sub
let ( *^ ) = Int64.mul
let ( /^ ) = Int64.div
let ( &^ ) = Int64.logand
let ( ~^ ) = Int64.lognot

external identity : 'a -> 'a = "%identity"

let roundup64 i a = let a = a -^ 1L in (i +^ a) &^ (~^ a)
let div_roundup64 i a = (i +^ a -^ 1L) /^ a

let int_of_le32 str =
  assert (String.length str = 4);
  let c0 = Char.code (String.unsafe_get str 0) in
  let c1 = Char.code (String.unsafe_get str 1) in
  let c2 = Char.code (String.unsafe_get str 2) in
  let c3 = Char.code (String.unsafe_get str 3) in
  Int64.of_int c0 +^
    (Int64.shift_left (Int64.of_int c1) 8) +^
    (Int64.shift_left (Int64.of_int c2) 16) +^
    (Int64.shift_left (Int64.of_int c3) 24)

let le32_of_int i =
  let c0 = i &^ 0xffL in
  let c1 = Int64.shift_right (i &^ 0xff00L) 8 in
  let c2 = Int64.shift_right (i &^ 0xff0000L) 16 in
  let c3 = Int64.shift_right (i &^ 0xff000000L) 24 in
  let b = Bytes.create 4 in
  Bytes.unsafe_set b 0 (Char.unsafe_chr (Int64.to_int c0));
  Bytes.unsafe_set b 1 (Char.unsafe_chr (Int64.to_int c1));
  Bytes.unsafe_set b 2 (Char.unsafe_chr (Int64.to_int c2));
  Bytes.unsafe_set b 3 (Char.unsafe_chr (Int64.to_int c3));
  Bytes.to_string b

type wrap_break_t = WrapEOS | WrapSpace | WrapNL

let rec wrap ?(chan = stdout) ?(indent = 0) str =
  let len = String.length str in
  _wrap chan indent 0 0 len str

and _wrap chan indent column i len str =
  if i < len then (
    let (j, break) = _wrap_find_next_break i len str in
    let next_column =
      if column + (j-i) >= 76 then (
        output_char chan '\n';
        output_spaces chan indent;
        indent + (j-i) + 1
      )
      else column + (j-i) + 1 in
    output chan (Bytes.of_string str) i (j-i);
    match break with
    | WrapEOS -> ()
    | WrapSpace ->
      output_char chan ' ';
      _wrap chan indent next_column (j+1) len str
    | WrapNL ->
      output_char chan '\n';
      output_spaces chan indent;
      _wrap chan indent indent (j+1) len str
  )

and _wrap_find_next_break i len str =
  if i >= len then (len, WrapEOS)
  else if String.unsafe_get str i = ' ' then (i, WrapSpace)
  else if String.unsafe_get str i = '\n' then (i, WrapNL)
  else _wrap_find_next_break (i+1) len str

and output_spaces chan n = for i = 0 to n-1 do output_char chan ' ' done

let (|>) x f = f x

(* Drop elements from a list while a predicate is true. *)
let rec dropwhile f = function
  | [] -> []
  | x :: xs when f x -> dropwhile f xs
  | xs -> xs

(* Take elements from a list while a predicate is true. *)
let rec takewhile f = function
  | x :: xs when f x -> x :: takewhile f xs
  | _ -> []

let rec filter_map f = function
  | [] -> []
  | x :: xs ->
      match f x with
      | Some y -> y :: filter_map f xs
      | None -> filter_map f xs

let rec find_map f = function
  | [] -> raise Not_found
  | x :: xs ->
      match f x with
      | Some y -> y
      | None -> find_map f xs

let iteri f xs =
  let rec loop i = function
    | [] -> ()
    | x :: xs -> f i x; loop (i+1) xs
  in
  loop 0 xs

let rec mapi i f =
  function
  | [] -> []
  | a::l ->
    let r = f i a in
    r :: mapi (i + 1) f l
let mapi f l = mapi 0 f l

let rec combine3 xs ys zs =
  match xs, ys, zs with
  | [], [], [] -> []
  | x::xs, y::ys, z::zs -> (x, y, z) :: combine3 xs ys zs
  | _ -> invalid_arg "combine3"

let rec assoc ?(cmp = compare) ~default x = function
  | [] -> default
  | (y, y') :: _ when cmp x y = 0 -> y'
  | _ :: ys -> assoc ~cmp ~default x ys

let uniq ?(cmp = Pervasives.compare) xs =
  let rec loop acc = function
    | [] -> acc
    | [x] -> x :: acc
    | x :: (y :: _ as xs) when cmp x y = 0 ->
       loop acc xs
    | x :: (y :: _ as xs) ->
       loop (x :: acc) xs
  in
  List.rev (loop [] xs)

let sort_uniq ?(cmp = Pervasives.compare) xs =
  let xs = List.sort cmp xs in
  let xs = uniq ~cmp xs in
  xs

let remove_duplicates xs =
  let h = Hashtbl.create (List.length xs) in
  let rec loop = function
    | [] -> []
    | x :: xs when Hashtbl.mem h x -> xs
    | x :: xs -> Hashtbl.add h x true; x :: loop xs
  in
  loop xs

let push_back xsp x = xsp := !xsp @ [x]
let push_front x xsp = xsp := x :: !xsp
let pop_back xsp =
  let x, xs =
    match List.rev !xsp with
    | x :: xs -> x, xs
    | [] -> failwith "pop" in
  xsp := List.rev xs;
  x
let pop_front xsp =
  let x, xs =
    match !xsp with
    | x :: xs -> x, xs
    | [] -> failwith "shift" in
  xsp := xs;
  x

let append xsp xs = xsp := !xsp @ xs
let prepend xs xsp = xsp := xs @ !xsp

let unique = let i = ref 0 in fun () -> incr i; !i

let may f = function
  | None -> ()
  | Some x -> f x

type ('a, 'b) maybe = Either of 'a | Or of 'b

let protect ~f ~finally =
  let r =
    try Either (f ())
    with exn -> Or exn in
  finally ();
  match r with Either ret -> ret | Or exn -> raise exn

let failwithf fs = ksprintf failwith fs

exception Executable_not_found of string (* executable *)

let which executable =
  let paths =
    try String.nsplit ":" (Sys.getenv "PATH")
    with Not_found -> [] in
  let paths = filter_map (
    fun p ->
      let path = p // executable in
      try Unix.access path [Unix.X_OK]; Some path
      with Unix.Unix_error _ -> None
  ) paths in
  match paths with
  | [] -> raise (Executable_not_found executable)
  | x :: _ -> x

(* Program name. *)
let prog = Filename.basename Sys.executable_name

(* Stores the colours (--colours), quiet (--quiet), trace (-x) and
 * verbose (-v) flags in a global variable.
 *)
let colours = ref false
let set_colours () = colours := true
let colours () = !colours

let quiet = ref false
let set_quiet () = quiet := true
let quiet () = !quiet

let trace = ref false
let set_trace () = trace := true
let trace () = !trace

let verbose = ref false
let set_verbose () = verbose := true
let verbose () = !verbose

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

(*</stdlib>*)
(*<stdlib>*)

let read_whole_file path =
  let buf = Buffer.create 16384 in
  let chan = open_in path in
  let maxlen = 16384 in
  let b = Bytes.create maxlen in
  let rec loop () =
    let r = input chan b 0 maxlen in
    if r > 0 then (
      Buffer.add_substring buf (Bytes.to_string b) 0 r;
      loop ()
    )
  in
  loop ();
  close_in chan;
  Buffer.contents buf

(*</stdlib>*)
(*<stdlib>*)

(* Compare two version strings intelligently. *)
let rex_numbers = Str.regexp "^\\([0-9]+\\)\\(.*\\)$"
let rex_letters = Str.regexp_case_fold "^\\([a-z]+\\)\\(.*\\)$"

let compare_version v1 v2 =
  let rec split_version = function
    | "" -> []
    | str ->
      let first, rest =
        if Str.string_match rex_numbers str 0 then (
          let n = Str.matched_group 1 str in
          let rest = Str.matched_group 2 str in
          let n =
            try `Number (int_of_string n)
            with Failure _ -> `String n in
          n, rest
        )
        else if Str.string_match rex_letters str 0 then
          `String (Str.matched_group 1 str), Str.matched_group 2 str
        else (
          let len = String.length str in
          `Char str.[0], String.sub str 1 (len-1)
        ) in
      first :: split_version rest
  in
  compare (split_version v1) (split_version v2)

(* Annoying LVM2 returns a differing UUID strings for different
 * function calls (sometimes containing or not containing '-'
 * characters), so we have to normalize each string before
 * comparison.  c.f. 'compare_pvuuids' in virt-filesystem.
 *)
let compare_lvm2_uuids uuid1 uuid2 =
  let n1 = String.length uuid1 and n2 = String.length uuid2 in
  let rec loop i1 i2 =
    if i1 = n1 && i2 = n2 then 0            (* matching *)
    else if i1 >= n1 then 1                 (* different lengths *)
    else if i2 >= n2 then -1
    else if uuid1.[i1] = '-' then loop (i1+1) i2 (* ignore '-' characters *)
    else if uuid2.[i2] = '-' then loop i1 (i2+1)
    else (
      let c = compare uuid1.[i1] uuid2.[i2] in
      if c <> 0 then c                          (* not matching *)
      else loop (i1+1) (i2+1)
    )
  in
  loop 0 0

let stringify_args args =
  let rec quote_args = function
    | [] -> ""
    | x :: xs -> " " ^ Filename.quote x ^ quote_args xs
  in
  match args with
  | [] -> ""
  | app :: xs -> app ^ quote_args xs

(*</stdlib>*)
(*<stdlib>*)

(* Unlink a temporary file on exit. *)
let unlink_on_exit =
  let files = ref [] in
  let registered_handlers = ref false in

  let rec unlink_files () =
    List.iter (
      fun file -> try Unix.unlink file with _ -> ()
    ) !files
  and register_handlers () =
    (* Unlink on exit. *)
    at_exit unlink_files
  in

  fun file ->
    files := file :: !files;
    if not !registered_handlers then (
      register_handlers ();
      registered_handlers := true
    )

(*</stdlib>*)
(*<stdlib>*)

let is_block_device file =
  try (Unix.stat file).Unix.st_kind = Unix.S_BLK
  with Unix.Unix_error _ -> false

let is_char_device file =
  try (Unix.stat file).Unix.st_kind = Unix.S_CHR
  with Unix.Unix_error _ -> false

(*</stdlib>*)
(*<stdlib>*)

(* Annoyingly Sys.is_directory throws an exception on failure
 * (RHBZ#1022431).
 *)
let is_directory path =
  try Sys.is_directory path
  with Sys_error _ -> false

let absolute_path path =
  if not (Filename.is_relative path) then path
  else Sys.getcwd () // path

let qemu_input_filename filename =
  (* If the filename is something like "file:foo" then qemu-img will
   * try to interpret that as "foo" in the file:/// protocol.  To
   * avoid that, if the path is relative prefix it with "./" since
   * qemu-img won't try to interpret such a path.
   *)
  if String.length filename > 0 && filename.[0] <> '/' then
    "./" ^ filename
  else
    filename

let rec mkdir_p path permissions =
  try Unix.mkdir path permissions
  with
  | Unix.Unix_error (Unix.EEXIST, _, _) -> ()
  | Unix.Unix_error (Unix.ENOENT, _, _) ->
    (* A component in the path does not exist, so first try
     * creating the parent directory, and then again the requested
     * directory. *)
    mkdir_p (Filename.dirname path) permissions;
    Unix.mkdir path permissions

let normalize_arch = function
  | "i486" | "i586" | "i686" -> "i386"
  | "amd64" -> "x86_64"
  | "powerpc" -> "ppc"
  | "powerpc64" -> "ppc64"
  | "powerpc64le" -> "ppc64le"
  | arch -> arch

(* Are guest arch and host_cpu compatible, in terms of being able
 * to run commands in the libguestfs appliance?
 *)
let guest_arch_compatible guest_arch =
  let own = normalize_arch Guestfs_config.host_cpu in
  let guest_arch = normalize_arch guest_arch in
  match own, guest_arch with
  | x, y when x = y -> true
  | "x86_64", "i386" -> true
  | _ -> false

(* Is the guest OS "Unix-like"? *)
let unix_like = function
  | "hurd"
  | "linux"
  | "minix" -> true
  | typ when String.is_suffix typ "bsd" -> true
  | _ -> false

(** Return the last part of a string, after the specified separator. *)
let last_part_of str sep =
  try
    let i = String.rindex str sep in
    Some (String.sub str (i+1) (String.length str - (i+1)))
  with Not_found -> None

let read_first_line_from_file filename =
  let chan = open_in filename in
  let line = try input_line chan with End_of_file -> "" in
  close_in chan;
  line

let is_regular_file path = (* NB: follows symlinks. *)
  try (Unix.stat path).Unix.st_kind = Unix.S_REG
  with Unix.Unix_error _ -> false

(*</stdlib>*)
