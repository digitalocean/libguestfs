(* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/bindtests.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2019 Red Hat Inc.
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

let () =
  let g = Guestfs.create () in
  Guestfs.internal_test g "abc" (Some "def") [||] false 0 0L "123" "456" "abc\000abc" ~obool:true ~oint:(1) ~oint64:(9223372036854775807L);
  Guestfs.internal_test g "abc" None [||] false 0 0L "123" "456" "abc\000abc" ~oint64:(1L) ~ostring:"string";
  Guestfs.internal_test g "" (Some "def") [||] false 0 0L "123" "456" "abc\000abc" ~obool:false ~oint64:(-9223372036854775808L);
  Guestfs.internal_test g "" (Some "") [||] false 0 0L "123" "456" "abc\000abc";
  Guestfs.internal_test g "abc" (Some "def") [|"1"|] false 0 0L "123" "456" "abc\000abc";
  Guestfs.internal_test g "abc" (Some "def") [|"1";"2"|] false 0 0L "123" "456" "abc\000abc";
  Guestfs.internal_test g "abc" (Some "def") [|"1"|] true 0 0L "123" "456" "abc\000abc";
  Guestfs.internal_test g "abc" (Some "def") [|"1"|] false (-1) (-1L) "123" "456" "abc\000abc";
  Guestfs.internal_test g "abc" (Some "def") [|"1"|] false (-2) (-2L) "123" "456" "abc\000abc";
  Guestfs.internal_test g "abc" (Some "def") [|"1"|] false 1 1L "123" "456" "abc\000abc";
  Guestfs.internal_test g "abc" (Some "def") [|"1"|] false 2 2L "123" "456" "abc\000abc";
  Guestfs.internal_test g "abc" (Some "def") [|"1"|] false 4095 9223372036854775807L "123" "456" "abc\000abc";
  Guestfs.internal_test g "abc" (Some "def") [|"1"|] false 0 (-9223372036854775808L) "" "" "abc\000abc";
  Guestfs.internal_test g "abc" (Some "def") [||] false 0 0L "123" "456" "abc\000abc" ~ostringlist:[||];
  Guestfs.internal_test g "abc" (Some "def") [||] false 0 0L "123" "456" "abc\000abc" ~ostringlist:[|"optelem1"|];
  Guestfs.internal_test g "abc" (Some "def") [||] false 0 0L "123" "456" "abc\000abc" ~ostringlist:[|"optelem1";"optelem2"|];
  Guestfs.internal_test g "abc" (Some "def") [||] false 0 0L "123" "456" "abc\000abc" ~ostringlist:[|"optelem1";"optelem2";"optelem3"|];
print_endline "EOF"
