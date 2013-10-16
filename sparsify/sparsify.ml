(* virt-sparsify
 * Copyright (C) 2011-2013 Red Hat Inc.
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

open Unix
open Scanf
open Printf

open Common_gettext.Gettext

module G = Guestfs

open Common_utils

external statvfs_free_space : string -> int64 =
  "virt_sparsify_statvfs_free_space"

let () = Random.self_init ()

(* Command line argument parsing. *)
let prog = Filename.basename Sys.executable_name
let error fs = error ~prog fs

let indisk, outdisk, check_tmpdir, compress, convert, debug_gc,
  format, ignores, machine_readable,
  option, quiet, verbose, trace, zeroes =
  let display_version () =
    let g = new G.guestfs () in
    let version = g#version () in
    printf "virt-sparsify %Ld.%Ld.%Ld%s\n"
      version.G.major version.G.minor version.G.release version.G.extra;
    exit 0
  in

  let add xs s = xs := s :: !xs in

  let check_tmpdir = ref `Warn in
  let set_check_tmpdir = function
    | "ignore" | "i" -> check_tmpdir := `Ignore
    | "continue" | "cont" | "c" -> check_tmpdir := `Continue
    | "warn" | "warning" | "w" -> check_tmpdir := `Warn
    | "fail" | "f" | "error" -> check_tmpdir := `Fail
    | str ->
      eprintf (f_"--check-tmpdir: unknown argument `%s'\n") str;
      exit 1
  in

  let compress = ref false in
  let convert = ref "" in
  let debug_gc = ref false in
  let format = ref "" in
  let ignores = ref [] in
  let machine_readable = ref false in
  let option = ref "" in
  let quiet = ref false in
  let verbose = ref false in
  let trace = ref false in
  let zeroes = ref [] in

  let ditto = " -\"-" in
  let argspec = Arg.align [
    "--check-tmpdir", Arg.String set_check_tmpdir,  "ignore|..." ^ " " ^ s_"Check there is enough space in $TMPDIR";
    "--compress", Arg.Set compress,         " " ^ s_"Compressed output format";
    "--convert", Arg.Set_string convert,    s_"format" ^ " " ^ s_"Format of output disk (default: same as input)";
    "--debug-gc", Arg.Set debug_gc,         " " ^ s_"Debug GC and memory allocations";
    "--format",  Arg.Set_string format,     s_"format" ^ " " ^ s_"Format of input disk";
    "--ignore",  Arg.String (add ignores),  s_"fs" ^ " " ^ s_"Ignore filesystem";
    "--long-options", Arg.Unit display_long_options, " " ^ s_"List long options";
    "--machine-readable", Arg.Set machine_readable, " " ^ s_"Make output machine readable";
    "-o",        Arg.Set_string option,     s_"option" ^ " " ^ s_"Add qemu-img options";
    "-q",        Arg.Set quiet,             " " ^ s_"Quiet output";
    "--quiet",   Arg.Set quiet,             ditto;
    "-v",        Arg.Set verbose,           " " ^ s_"Enable debugging messages";
    "--verbose", Arg.Set verbose,           ditto;
    "-V",        Arg.Unit display_version,  " " ^ s_"Display version and exit";
    "--version", Arg.Unit display_version,  ditto;
    "-x",        Arg.Set trace,             " " ^ s_"Enable tracing of libguestfs calls";
    "--zero",    Arg.String (add zeroes),   s_"fs" ^ " " ^ s_"Zero filesystem";
  ] in
  long_options := argspec;
  let disks = ref [] in
  let anon_fun s = disks := s :: !disks in
  let usage_msg =
    sprintf (f_"\
%s: sparsify a virtual machine disk

 virt-sparsify [--options] indisk outdisk

A short summary of the options is given below.  For detailed help please
read the man page virt-sparsify(1).
")
      prog in
  Arg.parse argspec anon_fun usage_msg;

  (* Dereference the rest of the args. *)
  let check_tmpdir = !check_tmpdir in
  let compress = !compress in
  let convert = match !convert with "" -> None | str -> Some str in
  let debug_gc = !debug_gc in
  let format = match !format with "" -> None | str -> Some str in
  let ignores = List.rev !ignores in
  let machine_readable = !machine_readable in
  let option = match !option with "" -> None | str -> Some str in
  let quiet = !quiet in
  let verbose = !verbose in
  let trace = !trace in
  let zeroes = List.rev !zeroes in

  (* No arguments and machine-readable mode?  Print out some facts
   * about what this binary supports.
   *)
  if !disks = [] && machine_readable then (
    printf "virt-sparsify\n";
    printf "linux-swap\n";
    printf "zero\n";
    printf "check-tmpdir\n";
    let g = new G.guestfs () in
    g#add_drive "/dev/null";
    g#launch ();
    if g#feature_available [| "ntfsprogs"; "ntfs3g" |] then
      printf "ntfs\n";
    if g#feature_available [| "btrfs" |] then
      printf "btrfs\n";
    exit 0
  );

  (* Verify we got exactly 2 disks. *)
  let indisk, outdisk =
    match List.rev !disks with
    | [indisk; outdisk] -> indisk, outdisk
    | _ ->
        error "usage is: %s [--options] indisk outdisk" prog in

  (* Simple-minded check that the user isn't trying to use the
   * same disk for input and output.
   *)
  if indisk = outdisk then
    error (f_"you cannot use the same disk image for input and output");

  (* The input disk must be an absolute path, so we can store the name
   * in the overlay disk.
   *)
  let indisk =
    if not (Filename.is_relative indisk) then
      indisk
    else
      Sys.getcwd () // indisk in

  let contains_colon filename =
    try ignore (String.index filename ':'); true with Not_found -> false in

  (* Check filenames don't contain a colon (limitation of qemu-img). *)
  if contains_colon indisk then
    error (f_"input filename '%s' contains a colon (':'); qemu-img command line syntax prevents us from using such an image") indisk;

  if contains_colon outdisk then
    error (f_"output filename '%s' contains a colon (':'); qemu-img command line syntax prevents us from using such an image") outdisk;

  indisk, outdisk, check_tmpdir, compress, convert,
    debug_gc, format, ignores, machine_readable,
    option, quiet, verbose, trace, zeroes

(* Once we have got past argument parsing and start to create
 * temporary files (including the potentially massive overlay file), we
 * need to catch SIGINT (^C) and exit cleanly so the temporary file
 * goes away.  Note that we don't delete temporaries in the signal
 * handler.
 *)
let () =
  let do_sigint _ = exit 1 in
  Sys.set_signal Sys.sigint (Sys.Signal_handle do_sigint)

(* Try to determine which flag options qemu-img supports for qcow2.
 * We do this by creating and disposing of a few test images.  This
 * also detects if qemu-img is completely broken.
 *)
let qemu_img_supports_compat11, qemu_img_supports_lazy_refcounts =
  let test options =
    let tmp = Filename.temp_file "test" ".qcow2" in
    unlink_on_exit tmp;
    let cmd = "qemu-img create -f qcow2" ^
      (match options with None -> "" | Some opts -> " -o " ^ opts) ^
      " " ^ tmp ^ " 128K > /dev/null" in
    if verbose then printf "testing if '%s' works ... %!" cmd;
    let r = Sys.command cmd = 0 in
    if verbose then printf "%b\n" r;
    r
  in
  if not (test None) then (
    eprintf (f_"\
'qemu-img create' cannot create qcow2 files.  Check the 'qemu-img'
program is installed and working, and that it matches the version\
of qemu installed.\n");
    exit 1
  );
  let supports_compat11 = test (Some "compat=1.1") in
  let supports_lazy_refcounts =
    test (Some "compat=1.1,lazy_refcounts") in
  supports_compat11, supports_lazy_refcounts

(* What should the output format be?  If the user specified an
 * input format, use that, else detect it from the source image.
 *)
let output_format =
  match convert with
  | Some fmt -> fmt             (* user specified output conversion *)
  | None ->
    match format with
    | Some fmt -> fmt           (* user specified input format, use that *)
    | None ->
      (* Don't know, so we must autodetect. *)
      match (new G.guestfs ())#disk_format indisk  with
      | "unknown" ->
        error (f_"cannot detect input disk format; use the --format parameter")
      | fmt -> fmt

(* Compression is not supported by raw output (RHBZ#852194). *)
let () =
  if output_format = "raw" && compress then
    error (f_"--compress cannot be used for raw output.  Remove this option or use --convert qcow2.")

(* Get virtual size of the input disk. *)
let virtual_size = (new G.guestfs ())#disk_virtual_size indisk
let () =
  if not quiet then
    printf (f_"Input disk virtual size = %Ld bytes (%s)\n%!")
      virtual_size (human_size virtual_size)

(* Check there is enough space in $TMPDIR. *)
let tmpdir = Filename.temp_dir_name

let () =
  let print_warning () =
    let free_space = statvfs_free_space tmpdir in
    let extra_needed = virtual_size -^ free_space in
    if extra_needed > 0L then (
      eprintf (f_"\

WARNING: There may not be enough free space on %s.
You may need to set TMPDIR to point to a directory with more free space.

Max needed: %s.  Free: %s.  May need another %s.

Note this is an overestimate.  If the guest disk is full of data
then not as much free space would be required.

You can ignore this warning or change it to a hard failure using the
--check-tmpdir=(ignore|continue|warn|fail) option.  See virt-sparsify(1).

%!")
        tmpdir (human_size virtual_size)
        (human_size free_space) (human_size extra_needed);
      true
    ) else false
  in

  match check_tmpdir with
  | `Ignore -> ()
  | `Continue -> ignore (print_warning ())
  | `Warn ->
    if print_warning () then (
      eprintf "Press RETURN to continue or ^C to quit.\n%!";
      ignore (read_line ())
    );
  | `Fail ->
    if print_warning () then (
      eprintf "Exiting because --check-tmpdir=fail was set.\n%!";
      exit 2
    )

let () =
  if not quiet then
    printf (f_"Create overlay file in %s to protect source disk ...\n%!") tmpdir

(* Create the temporary overlay file. *)
let overlaydisk =
  let tmp = Filename.temp_file "sparsify" ".qcow2" in
  unlink_on_exit tmp;

  (* Create it with the indisk as the backing file. *)
  let cmd =
    let options =
      let backing_file_option =
        [sprintf "backing_file=%s" (replace_str indisk "," ",,")] in
      let backing_fmt_option =
        match format with
        | None -> []
        | Some fmt -> [sprintf "backing_fmt=%s" fmt] in
      let compat11 =
        if qemu_img_supports_compat11 then ["compat=1.1"] else [] in
      let lazy_refcounts =
        if qemu_img_supports_lazy_refcounts then
          ["lazy_refcounts"]
        else [] in
      String.concat "," (
        backing_file_option @
        backing_fmt_option @
        compat11 @
        lazy_refcounts
      ) in
    sprintf "qemu-img create -f qcow2 -o %s %s > /dev/null"
      (Filename.quote options) (Filename.quote tmp) in
  if verbose then
    printf "%s\n%!" cmd;
  if Sys.command cmd <> 0 then
    error (f_"external command failed: %s") cmd;

  tmp

let () =
  if not quiet then
    printf (f_"Examine source disk ...\n%!")

(* Connect to libguestfs. *)
let g =
  let g = new G.guestfs () in
  if trace then g#set_trace true;
  if verbose then g#set_verbose true;

  (* Note that the temporary overlay disk is always qcow2 format. *)
  g#add_drive ~format:"qcow2" ~readonly:false ~cachemode:"unsafe" overlaydisk;

  if not quiet then Progress.set_up_progress_bar ~machine_readable g;
  g#launch ();

  g

(* Modify SIGINT handler (set first above) to cancel the handle. *)
let () =
  let do_sigint _ =
    g#user_cancel ();
    exit 1
  in
  Sys.set_signal Sys.sigint (Sys.Signal_handle do_sigint)

(* Get the size in bytes of the input disk. *)
let insize = g#blockdev_getsize64 "/dev/sda"

(* Write zeroes for non-ignored filesystems that we are able to mount,
 * and selected swap partitions.
 *)
let () =
  let filesystems = g#list_filesystems () in
  let filesystems = List.map fst filesystems in
  let filesystems = List.sort compare filesystems in

  let is_ignored fs =
    let fs = g#canonical_device_name fs in
    List.exists (fun fs' -> fs = g#canonical_device_name fs') ignores
  in

  List.iter (
    fun fs ->
      if not (is_ignored fs) then (
        if List.mem fs zeroes then (
          if not quiet then
            printf (f_"Zeroing %s ...\n%!") fs;

          g#zero_device fs
        ) else (
          let mounted =
            try g#mount fs "/"; true
            with _ -> false in

          if mounted then (
            if not quiet then
              printf (f_"Fill free space in %s with zero ...\n%!") fs;

            g#zero_free_space "/"
          ) else (
            let is_linux_x86_swap =
              (* Look for the signature for Linux swap on i386.
               * Location depends on page size, so it definitely won't
               * work on non-x86 architectures (eg. on PPC, page size is
               * 64K).  Also this avoids hibernated swap space: in those,
               * the signature is moved to a different location.
               *)
              try g#pread_device fs 10 4086L = "SWAPSPACE2"
              with _ -> false in

            if is_linux_x86_swap then (
              if not quiet then
                printf (f_"Clearing Linux swap on %s ...\n%!") fs;

              (* Don't use mkswap.  Just preserve the header containing
               * the label, UUID and swap format version (libguestfs
               * mkswap may differ from guest's own).
               *)
              let header = g#pread_device fs 4096 0L in
              g#zero_device fs;
              if g#pwrite_device fs header 0L <> 4096 then
                error (f_"pwrite: short write restoring swap partition header")
            )
          )
        );

        g#umount_all ()
      )
  ) filesystems

(* Fill unused space in volume groups. *)
let () =
  let vgs = g#vgs () in
  let vgs = Array.to_list vgs in
  let vgs = List.sort compare vgs in
  List.iter (
    fun vg ->
      if not (List.mem vg ignores) then (
        let lvname = string_random8 () in
        let lvdev = "/dev/" ^ vg ^ "/" ^ lvname in

        let created =
          try g#lvcreate_free lvname vg 100; true
          with _ -> false in

        if created then (
          if not quiet then
            printf (f_"Fill free space in volgroup %s with zero ...\n%!") vg;

          g#zero_device lvdev;
          g#sync ();
          g#lvremove lvdev
        )
      )
  ) vgs

(* Don't need libguestfs now. *)
let () =
  g#shutdown ();
  g#close ()

(* Modify SIGINT handler (set first above) to just exit. *)
let () =
  let do_sigint _ = exit 1 in
  Sys.set_signal Sys.sigint (Sys.Signal_handle do_sigint)

(* Now run qemu-img convert which copies the overlay to the
 * destination and automatically does sparsification.
 *)
let () =
  if not quiet then
    printf (f_"Copy to destination and make sparse ...\n%!");

  let cmd =
    sprintf "qemu-img convert -f qcow2 -O %s%s%s %s %s"
      (Filename.quote output_format)
      (if compress then " -c" else "")
      (match option with
      | None -> ""
      | Some option -> " -o " ^ Filename.quote option)
      (Filename.quote overlaydisk) (Filename.quote outdisk) in
  if verbose then
    printf "%s\n%!" cmd;
  if Sys.command cmd <> 0 then
    error (f_"external command failed: %s") cmd

(* Finished. *)
let () =
  if not quiet then (
    print_newline ();
    wrap (s_"Sparsify operation completed with no errors.  Before deleting the old disk, carefully check that the target disk boots and works correctly.\n");
  );

  if debug_gc then
    Gc.compact ();

  exit 0
