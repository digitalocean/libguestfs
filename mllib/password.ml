(* virt-sysprep
 * Copyright (C) 2012-2014 Red Hat Inc.
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

type password_crypto = [`MD5 | `SHA256 | `SHA512 ]

type password_selector = {
  pw_password : password;
  pw_locked : bool;
}
and password =
| Password of string
| Random_password
| Disabled_password

type password_map = (string, password_selector) Hashtbl.t

let make_random_password =
  (* Get random characters from the set [A-Za-z0-9] with some
   * homoglyphs removed.
   *)
  let chars = "ABCDEFGHIJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz0123456789" in
  fun () -> Urandom.urandom_uniform 16 chars

let password_crypto_of_string ~prog = function
  | "md5" -> `MD5
  | "sha256" -> `SHA256
  | "sha512" -> `SHA512
  | arg ->
    eprintf (f_"%s: password-crypto: unknown algorithm %s, use \"md5\", \"sha256\" or \"sha512\".\n")
      prog arg;
    exit 1

let rec parse_selector ~prog arg =
  parse_selector_list ~prog arg (string_nsplit ":" arg)

and parse_selector_list ~prog orig_arg = function
  | [ "lock"|"locked" ] ->
    { pw_locked = true; pw_password = Disabled_password }
  | ("lock"|"locked") :: rest ->
    let pw = parse_selector_list ~prog orig_arg rest in
    { pw with pw_locked = true }
  | [ "file"; filename ] ->
    { pw_password = Password (read_password_from_file filename);
      pw_locked = false }
  | "password" :: password ->
    { pw_password = Password (String.concat ":" password); pw_locked = false }
  | [ "random" ] ->
    { pw_password = Random_password; pw_locked = false }
  | [ "disable"|"disabled" ] ->
    { pw_password = Disabled_password; pw_locked = false }
  | _ ->
    eprintf (f_"%s: invalid password selector '%s'; see the man page.\n")
      prog orig_arg;
    exit 1

and read_password_from_file filename =
  let chan = open_in filename in
  let password = input_line chan in
  close_in chan;
  password

(* Permissible characters in a salt. *)
let chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./"

let rec set_linux_passwords ~prog ?password_crypto g root passwords =
  let crypto =
    match password_crypto with
    | None -> default_crypto g root
    | Some c -> c in

  (* XXX Would like to use Augeas here, but Augeas doesn't support
   * /etc/shadow (as of 1.1.0).
   *)

  let shadow = Array.to_list (g#read_lines "/etc/shadow") in
  let shadow =
    List.map (
      fun line ->
        try
          (* Each line is: "user:[!!]password:..."
           * !! at the front of the password field means the account is locked.
           * 'i' points to the first colon, 'j' to the second colon.
           *)
          let i = String.index line ':' in
          let user = String.sub line 0 i in
          let selector = Hashtbl.find passwords user in
          let j = String.index_from line (i+1) ':' in
          let rest = String.sub line j (String.length line - j) in
          let pwfield =
            match selector with
            | { pw_locked = locked;
                pw_password = Password password } ->
              if locked then "!!" else "" ^ encrypt password crypto
            | { pw_locked = locked;
                pw_password = Random_password } ->
              let password = make_random_password () in
              printf (f_"Setting random password of %s to %s\n%!")
                user password;
              if locked then "!!" else "" ^ encrypt password crypto
            | { pw_locked = true; pw_password = Disabled_password } -> "!!*"
            | { pw_locked = false; pw_password = Disabled_password } -> "*" in
          user ^ ":" ^ pwfield ^ rest
        with Not_found -> line
    ) shadow in

  g#write "/etc/shadow" (String.concat "\n" shadow ^ "\n");
  (* In virt-sysprep /.autorelabel will label it correctly. *)
  g#chmod 0 "/etc/shadow"

(* Encrypt each password.  Use glibc (on the host).  See:
 * https://rwmj.wordpress.com/2013/07/09/setting-the-root-or-other-passwords-in-a-linux-guest/
 *)
and encrypt password crypto =
  (* Get random characters from the set [A-Za-z0-9./] *)
  let salt = Urandom.urandom_uniform 16 chars in
  let salt =
    (match crypto with
    | `MD5 -> "$1$"
    | `SHA256 -> "$5$"
    | `SHA512 -> "$6$") ^ salt ^ "$" in
  let r = Crypt.crypt password salt in
  (*printf "password: encrypt %s with salt %s -> %s\n" password salt r;*)
  r

(* glibc 2.7 was released in Oct 2007.  Approximately, all guests that
 * precede this date only support md5, whereas all guests after this
 * date can support sha512.
 *)
and default_crypto g root =
  let distro = g#inspect_get_distro root in
  let major = g#inspect_get_major_version root in
  match distro, major with
  | ("rhel"|"centos"|"scientificlinux"|"redhat-based"), v when v >= 6 ->
    `SHA512
  | ("rhel"|"centos"|"scientificlinux"|"redhat-based"), _ ->
    `MD5 (* RHEL 5 does not appear to support SHA512, according to crypt(3) *)

  | "fedora", v when v >= 9 -> `SHA512
  | "fedora", _ -> `MD5

  | "debian", v when v >= 5 -> `SHA512
  | "debian", _ -> `MD5

  (* Very likely earlier versions of Ubuntu than 10.04 had new crypt,
   * but Ubuntu 10.04 is the earliest version I have checked.
   *)
  | "ubuntu", v when v >= 10 -> `SHA512
  | "ubuntu", _ -> `MD5

  | _, _ ->
    eprintf (f_"\
virt-sysprep: password: warning: using insecure md5 password encryption for
guest of type %s version %d.
If this is incorrect, use --password-crypto option and file a bug.\n%!")
      distro major;
    `MD5
