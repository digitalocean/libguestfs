#!/usr/bin/env ocaml
(* libguestfs
 * Copyright (C) 2016 Red Hat Inc.
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *)

(* This script is used to create the virt-builder templates hosted
 * http://libguestfs.org/download/builder/
 *
 * Prior to November 2016, the templates were generated using
 * shell scripts located in libguestfs.git/builder/website.
 *)

open Printf

let prog = "make-template"

let () =
  (* Check we are being run from the correct directory. *)
  if not (Sys.file_exists "debian.preseed") then (
    eprintf "%s: run this script from the builder/templates subdirectory\n"
            prog;
    exit 1
  );

  (* Check that the ./run script was used. *)
  (try ignore (Sys.getenv "CAML_LD_LIBRARY_PATH")
   with Not_found ->
     eprintf "%s: you must use `../../run ./make-template.ml ...' to run this script\n"
             prog;
     exit 1
  )
  ;;

#load "str.cma";;
#load "unix.cma";;
#directory "../../ocaml";;
#load "mlguestfs.cma";;

type os =
  | CentOS of int * int         (* major, minor *)
  | RHEL of int * int
  | Debian of int * string      (* version, dist name like "wheezy" *)
  | Ubuntu of string * string
  | Fedora of int               (* version number *)
type arch = X86_64 | Aarch64 | Armv7 | I686 | PPC64 | PPC64le | S390X

let quote = Filename.quote
let (//) = Filename.concat

let rec main () =
  assert (Sys.word_size = 64);
  Random.self_init ();

  (* Parse the command line. *)
  let os, arch = parse_cmdline () in

  (* Choose a disk size for this OS. *)
  let virtual_size_gb = get_virtual_size_gb os arch in

  (* For OSes which require a kickstart, this generates one.
   * For OSes which require a preseed file, this returns one (we
   * don't generate preseed files at the moment).
   *)
  let ks = make_kickstart_or_preseed os arch in

  (* Find the virt-install --location for this OS. *)
  let location = make_location os arch in

  (* RHEL guests require alternate yum configuration pointing to
   * Red Hat's internal servers.
   *)
  let yum_conf =
    match os with
    | RHEL (major, minor) when major >= 5 ->
       Some (make_rhel_yum_conf major minor arch)
    | _ -> None in

  (* Choose a random temporary name for the libvirt domain.  We will
   * also have to clean this up after running virt-install.
   *)
  let tmpname = sprintf "tmp-%s" (random8 ()) in

  (* Choose a random temporary disk name. *)
  let tmpout = sprintf "%s.img" tmpname in

  (* Some architectures need EFI boot. *)
  let tmpefivars =
    match os, arch with
    | (Fedora _|RHEL _), Aarch64 ->
       let vars = sprintf "%s.vars" tmpname in
       let cmd =
         sprintf "cp /usr/share/edk2/aarch64/vars-template-pflash.raw %s"
                 (quote vars) in
       if Sys.command cmd <> 0 then exit 1;
       Some ("/usr/share/edk2/aarch64/QEMU_EFI-pflash.raw", vars)
    | _ -> None in

  (* Now construct the virt-install command. *)
  let vi = make_virt_install_command os arch ks tmpname tmpout tmpefivars
                                     location virtual_size_gb in
  (* Make sure that temporary guest and temporary files are removed
   * if we exit for any reason.
   *)
  let cleanup_libvirt_guest () =
    let cmd =
      sprintf "virsh undefine%s %s >&/dev/null"
              (if tmpefivars = None then "" else " --nvram")
              (quote tmpname) in
    ignore (Sys.command cmd)
  in
  at_exit (
    fun () ->
      cleanup_libvirt_guest ();
      (try Unix.unlink tmpout with _ -> ());
      (match tmpefivars with
       | Some (_, vars) -> (try Unix.unlink vars with _ -> ())
       | None -> ());
  );

  (* Print the virt-install command just before we run it, because
   * this is expected to be long-running.
   *)
  Array.iter (
    fun arg ->
      if arg.[0] = '-' then printf "\\\n    %s " arg
      else printf "%s " arg
  ) vi;
  printf "\n%!";

  (* Run the virt-install command. *)
  let pid = Unix.fork () in
  if pid = 0 then Unix.execvp "virt-install" vi;
  let _, pstat = Unix.waitpid [] pid in
  check_process_status_for_errors pstat;
  cleanup_libvirt_guest ();
  ignore (Sys.command "sync");

  (* Run virt-filesystems, simply to display the filesystems in the image. *)
  let cmd = sprintf "virt-filesystems -a %s --all --long -h" (quote tmpout) in
  if Sys.command cmd <> 0 then exit 1;

  (* Get the root filesystem.  If the root filesystem is LVM then
   * get the partition containing it.
   *)
  let g = open_guest tmpout in
  let roots = g#inspect_get_roots () in
  let expandfs, lvexpandfs =
    let rootfs = g#canonical_device_name roots.(0) in
    if String.length rootfs >= 7 && String.sub rootfs 0 7 = "/dev/sd" then
      rootfs, None (* non-LVM case *)
    else (
      (* The LVM case, find the containing partition to expand. *)
      let pvs = Array.to_list (g#pvs ()) in
      match pvs with
      | [pv] ->
         let pv = g#canonical_device_name pv in
         assert (String.length pv >= 7 && String.sub pv 0 7 = "/dev/sd");
         pv, Some rootfs
      | [] | _::_::_ -> assert false
    ) in

  (* Some guests are special flowers. *)
  (match os with
   | Debian _ ->
      (* Remove apt proxy configuration (thanks: Daniel Miranda). *)
      g#rm_f "/etc/apt/apt.conf";
      g#touch "/etc/apt/apt.conf";
   | _ -> ()
  );
  (match yum_conf with
   | Some yum_conf ->
      g#write "/etc/yum.repos.d/download.devel.redhat.com.repo" yum_conf;
   | None -> ()
  );

  g#shutdown ();
  g#close ();

  (match os with
   | Ubuntu (ver, _) when ver >= "14.04" ->
      (* In Ubuntu >= 14.04 you can't complete the install without creating
       * a user account.  We create one called 'builder', but we also
       * disable it.  XXX Combine with virt-sysprep step.
       *)
      let cmd =
        sprintf "virt-customize -a %s --password builder:disabled"
                (quote tmpout) in
      if Sys.command cmd <> 0 then exit 1
   | _ -> ()
  );

  (* Sysprep.  Relabel SELinux-using guests. *)
  printf "Sysprepping ...\n%!";
  let cmd =
    sprintf "virt-sysprep --quiet -a %s%s"
            (quote tmpout)
            (if is_selinux_os os then " --selinux-relabel" else "") in
  if Sys.command cmd <> 0 then exit 1;

  (* Create the final output name (actually not quite final because
   * we will xz-compress it).
   *)
  let output = filename_of_os os arch "" in

  (* Sparsify and copy to output name. *)
  printf "Sparsifying ...\n%!";
  let cmd =
    sprintf "virt-sparsify --quiet %s %s" (quote tmpout) (quote output) in
  if Sys.command cmd <> 0 then exit 1;
  Unix.unlink tmpout;

  (* Compress the output. *)
  printf "Compressing ...\n%!";
  let cmd =
    sprintf "xz -f --best --block-size=16777216 %s" (quote output) in
  if Sys.command cmd <> 0 then exit 1;
  let output = output ^ ".xz" in

  (* If there were NVRAM variables, move them to the final name and
   * compress them too.
   *)
  let nvram =
    match tmpefivars with
    | Some (_, vars) ->
       let f = sprintf "%s-nvram" output in
       let cmd = sprintf "mv %s %s-nvram" (quote vars) (quote f) in
       if Sys.command cmd <> 0 then exit 1;
       let cmd = sprintf "xz -f --best %s-nvram" (quote f) in
       if Sys.command cmd <> 0 then exit 1;
       Unix.unlink vars;
       Some (f ^ ".xz")
    | None -> None in
  printf "Template completed: %s\n%!" output;

  (* Construct the index fragment, but don't create this for the private
   * RHEL images.
   *)
  (match os with
   | RHEL _ -> ()
   | _ ->
      let index_fragment = filename_of_os os arch ".index-fragment" in
      (* If there is an existing file, read the revision and increment it. *)
      let revision = read_revision index_fragment in
      let revision = match revision with None -> None | Some i -> Some (i+1) in
      make_index_fragment os arch index_fragment output nvram revision
                          expandfs lvexpandfs virtual_size_gb;

      (* Validate the fragment we have just created. *)
      let cmd = sprintf "virt-index-validate %s" (quote index_fragment) in
      if Sys.command cmd <> 0 then exit 1;
      printf "Index fragment created: %s\n" index_fragment
  );

  printf "Finished successfully.\n%!"

and parse_cmdline () =
  let anon = ref [] in

  let usage = "\
../../run ./make-template.ml [--options] os version [arch]

Usage:
  ../../run ./make-template.ml [--options] os version [arch]

Examples:
  ../../run ./make-template.ml fedora 25
  ../../run ./make-template.ml rhel 7.3 ppc64le

The arch defaults to x86_64.  Note that i686 is treated as a
separate arch.

Options:
" in
  let spec = Arg.align [
  ] in

  Arg.parse spec (fun s -> anon := s :: !anon) usage;

  let os, ver, arch =
    match List.rev !anon with
    | [os; ver] -> os, ver, "x86_64"
    | [os; ver; arch] -> os, ver, arch
    | _ ->
       eprintf "%s [--options] os version [arch]\n" prog;
       exit 1 in
  let os = os_of_string os ver
  and arch = arch_of_string arch in

  os, arch

and os_of_string os ver =
  match os, ver with
  | "centos", ver -> let maj, min = parse_major_minor ver in CentOS (maj, min)
  | "rhel", ver -> let maj, min = parse_major_minor ver in RHEL (maj, min)
  | "debian", "6" -> Debian (6, "squeeze")
  | "debian", "7" -> Debian (7, "wheezy")
  | "debian", "8" -> Debian (8, "jessie")
  | "ubuntu", "10.04" -> Ubuntu (ver, "lucid")
  | "ubuntu", "12.04" -> Ubuntu (ver, "precise")
  | "ubuntu", "14.04" -> Ubuntu (ver, "trusty")
  | "ubuntu", "16.04" -> Ubuntu (ver, "xenial")
  | "fedora", ver -> Fedora (int_of_string ver)
  | _ ->
     eprintf "%s: unknown or unsupported OS (%s, %s)\n" prog os ver; exit 1

and parse_major_minor ver =
  let rex = Str.regexp "^\\([0-9]+\\)\\.\\([0-9]+\\)$" in
  if Str.string_match rex ver 0 then (
    int_of_string (Str.matched_group 1 ver),
    int_of_string (Str.matched_group 2 ver)
  )
  else (
    eprintf "%s: cannot parse major.minor (%s)\n" prog ver;
    exit 1
  )

and arch_of_string = function
  | "x86_64" -> X86_64
  | "aarch64" -> Aarch64
  | "armv7l" -> Armv7
  | "i686" -> I686
  | "ppc64" -> PPC64
  | "ppc64le" -> PPC64le
  | "s390x" -> S390X
  | s ->
     eprintf "%s: unknown or unsupported arch (%s)\n" prog s; exit 1

and string_of_arch = function
  | X86_64 -> "x86_64"
  | Aarch64 -> "aarch64"
  | Armv7 -> "armv7l"
  | I686 -> "i686"
  | PPC64 -> "ppc64"
  | PPC64le -> "ppc64le"
  | S390X -> "s390x"

and filename_of_os os arch ext =
  match os with
  | Fedora ver ->
     if arch = X86_64 then sprintf "fedora-%d%s" ver ext
     else sprintf "fedora-%d-%s%s" ver (string_of_arch arch) ext
  | CentOS (major, minor) ->
     if arch = X86_64 then sprintf "centos-%d.%d%s" major minor ext
     else sprintf "centos-%d.%d-%s%s" major minor (string_of_arch arch) ext
  | RHEL (major, minor) ->
     if arch = X86_64 then sprintf "rhel-%d.%d%s" major minor ext
     else sprintf "rhel-%d.%d-%s%s" major minor (string_of_arch arch) ext
  | Debian (ver, _) ->
     if arch = X86_64 then sprintf "debian-%d%s" ver ext
     else sprintf "debian-%d-%s%s" ver (string_of_arch arch) ext
  | Ubuntu (ver, _) ->
     if arch = X86_64 then sprintf "ubuntu-%s%s" ver ext
     else sprintf "ubuntu-%s-%s%s" ver (string_of_arch arch) ext

and string_of_os os arch = filename_of_os os arch ""

(* This is what virt-builder called "os-version". *)
and string_of_os_noarch = function
  | Fedora ver -> sprintf "fedora-%d" ver
  | CentOS (major, minor) -> sprintf "centos-%d.%d" major minor
  | RHEL (major, minor) -> sprintf "rhel-%d.%d" major minor
  | Debian (ver, _) -> sprintf "debian-%d" ver
  | Ubuntu (ver, _) -> sprintf "ubuntu-%s" ver

and is_selinux_os = function
  | RHEL _ | CentOS _ | Fedora _ -> true
  | Debian _ | Ubuntu _ -> false

and get_virtual_size_gb os arch = 6

and make_kickstart_or_preseed os arch =
  match os with
  (* Kickstart. *)
  | Fedora _ | CentOS _ | RHEL _ ->
     let ks_filename = filename_of_os os arch ".ks" in
     make_kickstart_common ks_filename os arch

  (* Preseed. *)
  | Debian _ -> copy_preseed_to_temporary "debian.preseed"
  | Ubuntu _ -> copy_preseed_to_temporary "ubuntu.preseed"

and make_kickstart_common ks_filename os arch =
  let buf = Buffer.create 4096 in
  let bpf fs = bprintf buf fs in

  bpf "\
# Kickstart file for %s
# Generated by libguestfs.git/builder/templates/make-template.ml

install
text
reboot
lang en_US.UTF-8
keyboard us
network --bootproto dhcp
rootpw builder
firewall --enabled --ssh
timezone --utc America/New_York
" (string_of_os os arch);

  (match os with
   | RHEL (ver, _) when ver <= 4 ->
      bpf "\
langsupport en_US
mouse generic
";
   | _ -> ()
  );

  (match os with
   | RHEL (3, _) -> ()
   | _ ->
      bpf "selinux --enforcing\n"
  );

  (match os with
   | RHEL (5, _) -> bpf "key --skip\n"
   | _ -> ()
  );
  bpf "\n";

  bpf "bootloader --location=mbr --append=\"%s\"\n"
      (kernel_cmdline_of_os os arch);
  bpf "\n";

  (match os with
   | CentOS ((3|4|5|6) as major, _) | RHEL ((3|4|5|6) as major, _) ->
      let bootfs = if major <= 5 then "ext2" else "ext4" in
      let rootfs = if major <= 4 then "ext3" else "ext4" in
      bpf "\
zerombr
clearpart --all --initlabel
part /boot --fstype=%s   --size=512         --asprimary
part swap                --size=1024        --asprimary
part /     --fstype=%s   --size=1024 --grow --asprimary
" bootfs rootfs;
   | CentOS _ | RHEL _ | Fedora _ ->
      bpf "\
zerombr
clearpart --all --initlabel
autopart --type=lvm
";
   | _ -> assert false (* cannot happen, see caller *)
  );
  bpf "\n";

  (match os with
   | RHEL (3, _) -> ()
   | _ ->
      bpf "\
# Halt the system once configuration has finished.
poweroff
";
  );
  bpf "\n";

  bpf "\
%%packages
@core
";

  (match os with
   | RHEL ((3|4|5), _) -> ()
   | _ ->
      bpf "%%end\n"
  );
  bpf "\n";

  (* Generate the %post script section.  The previous scripts did
   * many different things here.  The current script tries to update
   * the packages and enable Xen drivers only.
   *)
  let regenerate_dracut () =
    bpf "\
# To make dracut config changes permanent, we need to rerun dracut.
# Rerun dracut for the installed kernel (not the running kernel).
# See commit 0fa52e4e45d80874bc5ea5f112f74be1d3f3472f and
# https://www.redhat.com/archives/libguestfs/2014-June/thread.html#00045
KERNEL_VERSION=\"$(rpm -q kernel --qf '%%{version}-%%{release}.%%{arch}\\n' | sort -V | tail -1)\"
dracut -f /boot/initramfs-$KERNEL_VERSION.img $KERNEL_VERSION
"
  in

  (match os with
   | Fedora _ ->
      bpf "%%post\n";
      bpf "\
# Ensure the installation is up-to-date.
dnf -y --best upgrade
";

      let needs_regenerate_dracut = ref false in
      if arch = X86_64 then (
        bpf "\
# Enable Xen domU support.
pushd /etc/dracut.conf.d
echo 'add_drivers+=\" xen:vbd xen:vif \"' > virt-builder-xen-drivers.conf
popd
";
        needs_regenerate_dracut := true
      );

      if arch = PPC64 || arch = PPC64le then (
        bpf "\
# Enable virtio-scsi support.
pushd /etc/dracut.conf.d
echo 'add_drivers+=\" virtio-blk virtio-scsi \"' > virt-builder-virtio-scsi.conf
popd
";
        needs_regenerate_dracut := true
      );

      if !needs_regenerate_dracut then regenerate_dracut ();
      bpf "%%end\n\n"

   | RHEL (7,_) ->
      bpf "%%post\n";

      let needs_regenerate_dracut = ref false in

      if arch = PPC64 || arch = PPC64le then (
        bpf "\
# Enable virtio-scsi support.
pushd /etc/dracut.conf.d
echo 'add_drivers+=\" virtio-blk virtio-scsi \"' > virt-builder-virtio-scsi.conf
popd
";
        needs_regenerate_dracut := true
      );

      if !needs_regenerate_dracut then regenerate_dracut ();
      bpf "%%end\n\n"

   | _ -> ()
  );

  bpf "# EOF\n";

  (* Write out the kickstart file. *)
  let chan = open_out (ks_filename ^ ".new") in
  Buffer.output_buffer chan buf;
  close_out chan;
  let cmd =
    sprintf "mv %s %s" (quote (ks_filename ^ ".new")) (quote ks_filename) in
  if Sys.command cmd <> 0 then exit 1;

  (* Return the kickstart filename. *)
  ks_filename

and copy_preseed_to_temporary source =
  (* d-i only works if the file is literally called "/preseed.cfg" *)
  let d = Filename.get_temp_dir_name () // random8 () ^ ".tmp" in
  let f = d // "preseed.cfg" in
  Unix.mkdir d 0o700;
  let cmd = sprintf "cp %s %s" (quote source) (quote f) in
  if Sys.command cmd <> 0 then exit 1;
  f

and make_location os arch =
  match os, arch with
  | CentOS (major, _), Aarch64 ->
     (* XXX This always points to the latest CentOS, so
      * effectively the minor number is always ignored.
      *)
     sprintf "http://mirror.centos.org/altarch/%d/os/aarch64/" major

  | CentOS (major, _), X86_64 ->
     (* For 6.x we rebuild this every time there is a new 6.x release, and bump
      * the revision in the index.
      * For 7.x this always points to the latest CentOS, so
      * effectively the minor number is always ignored.
      *)
     sprintf "http://mirror.centos.org/centos-7/%d/os/x86_64/" major

  | Debian (_, dist), X86_64 ->
     sprintf "http://deb.debian.org/debian/dists/%s/main/installer-amd64"
             dist

  | Fedora ver, Aarch64 ->
     sprintf "https://download.fedoraproject.org/pub/fedora-secondary/releases/%d/Server/aarch64/os/" ver

  | Fedora ver, Armv7 ->
     sprintf "http://mirror.bytemark.co.uk/fedora/linux/releases/%d/Server/armhfp/os/" ver

  | Fedora ver, X86_64 when ver < 21 ->
     sprintf "http://mirror.bytemark.co.uk/fedora/linux/releases/%d/Fedora/x86_64/os/" ver

  | Fedora ver, X86_64 ->
     sprintf "http://mirror.bytemark.co.uk/fedora/linux/releases/%d/Server/x86_64/os/" ver

  | Fedora ver, I686 when ver < 21 ->
     sprintf "http://mirror.bytemark.co.uk/fedora/linux/releases/%d/Fedora/i386/os/" ver

  | Fedora ver, I686 ->
     sprintf "http://mirror.bytemark.co.uk/fedora/linux/releases/%d/Server/i386/os/" ver

  | Fedora ver, PPC64 ->
     sprintf "https://download.fedoraproject.org/pub/fedora-secondary/releases/%d/Server/ppc64/os/" ver

  | Fedora ver, PPC64le ->
     sprintf "https://download.fedoraproject.org/pub/fedora-secondary/releases/%d/Server/ppc64le/os/" ver

  | Fedora ver, S390X ->
     sprintf "https://download.fedoraproject.org/pub/fedora-secondary/releases/%d/Server/s390x/os/" ver

  | RHEL (3, minor), X86_64 ->
     sprintf "http://download.devel.redhat.com/released/RHEL-3/U%d/AS/x86_64/tree" minor

  | RHEL (4, minor), X86_64 ->
     sprintf "http://download.devel.redhat.com/released/RHEL-4/U%d/AS/x86_64/tree" minor

  | RHEL (5, minor), I686 ->
     sprintf "http://download.devel.redhat.com/released/RHEL-5-Server/U%d/i386/os" minor

  | RHEL (5, minor), X86_64 ->
     sprintf "http://download.devel.redhat.com/released/RHEL-5-Server/U%d/x86_64/os" minor

  | RHEL (6, minor), I686 ->
     sprintf "http://download.devel.redhat.com/released/RHEL-6/6.%d/Server/i386/os" minor

  | RHEL (6, minor), X86_64 ->
     sprintf "http://download.devel.redhat.com/released/RHEL-6/6.%d/Server/x86_64/os" minor

  | RHEL (7, minor), X86_64 ->
     sprintf "http://download.devel.redhat.com/released/RHEL-7/7.%d/Server/x86_64/os" minor

  | RHEL (7, minor), Aarch64 ->
     sprintf "http://download.eng.bos.redhat.com/released/RHEL-7/7.%d/Server/aarch64/os" minor

  | RHEL (7, minor), PPC64 ->
     sprintf "http://download.devel.redhat.com/released/RHEL-7/7.%d/Server/ppc64/os" minor

  | RHEL (7, minor), PPC64le ->
     sprintf "http://download.devel.redhat.com/released/RHEL-7/7.%d/Server/ppc64le/os" minor

  | Ubuntu (_, dist), X86_64 ->
     sprintf "http://archive.ubuntu.com/ubuntu/dists/%s/main/installer-amd64"
             dist

  | Ubuntu (_, dist), PPC64le ->
     sprintf "http://ports.ubuntu.com/ubuntu-ports/dists/%s/main/installer-ppc64el" dist

  | _ ->
     eprintf "%s: don't know how to calculate the --location for this OS and architecture\n" prog;
     exit 1

(* NB: Arguments do not need to be quoted, because we pass them
 * directly to exec(2).
 *)
and make_virt_install_command os arch ks tmpname tmpout tmpefivars location
                              virtual_size_gb =
  let args = ref [] in
  let add arg = args := arg :: !args in

  add "virt-install";
  add (sprintf "--name=%s" tmpname);

  (*add "--print-xml";*)

  (match arch with
   | PPC64 | PPC64le -> add "--ram=4096"
   | _ -> add "--ram=2048"
  );

  (match arch with
   | X86_64 ->
      (* XXX This assumes the host is always x86_64. *)
      add "--cpu=host";
      add "--vcpus=4"
   | PPC64 ->
      add "--arch=ppc64";
      add "--machine=pseries";
      add "--cpu=POWER7";
      add "--vcpus=1"
   | PPC64le ->
      add "--arch=ppc64le";
      add "--machine=pseries";
      add "--cpu=POWER8";
      add "--vcpus=1"
   | arch ->
      add (sprintf "--arch=%s" (string_of_arch arch));
      add "--vcpus=1"
  );

  add "--os-type=linux";
  add (sprintf "--os-variant=%s" (os_variant_of_os os arch));

  (match tmpefivars with
   | Some (code, vars) ->
      add "--boot";
      add (sprintf "loader=%s,loader_ro=yes,loader_type=pflash,nvram=%s"
                   code vars)
   | _ -> ()
  );

  add (sprintf "--initrd-inject=%s" ks);
  let os_extra =
    match os with
    | Debian _ | Ubuntu _ -> "auto"
    | Fedora _ | RHEL _ | CentOS _ ->
       sprintf "ks=file:/%s" (Filename.basename ks) in
  let proxy =
    let p = try Some (Sys.getenv "http_proxy") with Not_found -> None in
    match p with
    | None -> ""
    | Some p ->
       match os with
       | Fedora _ | RHEL _ | CentOS _ -> "proxy=" ^ p
       | Debian _ | Ubuntu _ -> "mirror/http/proxy=" ^ p in

  add (sprintf "--extra-args=%s %s %s" (* sic: does NOT need to be quoted *)
               os_extra proxy (kernel_cmdline_of_os os arch));

  add (sprintf "--disk=%s,size=%d,format=raw"
               (Sys.getcwd () // tmpout) virtual_size_gb);

  add "--serial=pty";
  add (sprintf "--location=%s" location);
  add "--nographics";
  add "--noreboot";

  (* Return the command line (list of arguments). *)
  Array.of_list (List.rev !args)

and os_variant_of_os os arch =
  match os, arch with
  (* This case is needed to workaround a bug in virt-install:
   * https://bugzilla.redhat.com/show_bug.cgi?id=1399083
   *)
  | Fedora _, (PPC64|PPC64le) -> "fedora22"
  | Fedora ver, _ when ver <= 23 ->
     sprintf "fedora%d" ver
  | Fedora _, _ -> "fedora23" (* max version known in Fedora 24 *)
  | CentOS (major, minor), _ when (major, minor) <= (7,0) ->
     sprintf "centos%d.%d" major minor
  | CentOS _, _ -> "centos7.0" (* max version known in Fedora 24 *)
  | RHEL (major, minor), _ when (major, minor) <= (7,2) ->
     sprintf "rhel%d.%d" major minor
  | RHEL _, _ -> "rhel7.2" (* max version known in Fedora 24 *)
  | Debian (ver, _), _ -> sprintf "debian%d" ver
  | Ubuntu (ver, _), _ -> sprintf "ubuntu%s" ver

(* Same as the above, but we print the "true" os-variant, even
 * if osinfo itself might not support it yet.
 *)
and true_os_variant_of_os = function
  | Fedora ver -> sprintf "fedora%d" ver
  | CentOS (major, minor) -> sprintf "centos%d.%d" major minor
  | RHEL (major, minor) -> sprintf "rhel%d.%d" major minor
  | Debian (ver, _) -> sprintf "debian%d" ver
  | Ubuntu (ver, _) -> sprintf "ubuntu%s" ver

and kernel_cmdline_of_os os arch =
  match os, arch with
  | _, X86_64
  | _, I686
  | _, S390X ->
     "console=tty0 console=ttyS0,115200 rd_NO_PLYMOUTH"
  | _, Aarch64 ->
     "console=ttyAMA0 earlyprintk=pl011,0x9000000 ignore_loglevel no_timer_check printk.time=1 rd_NO_PLYMOUTH"
  | _, Armv7 ->
     "console=tty0 console=ttyAMA0,115200 rd_NO_PLYMOUTH"
  | (Debian _|Fedora _|Ubuntu _), (PPC64|PPC64le) ->
     "console=tty0 console=hvc0 rd_NO_PLYMOUTH"
  | (RHEL _|CentOS _), PPC64
  | (RHEL _|CentOS _), PPC64le ->
     "console=tty0 console=ttyS0,115200 rd_NO_PLYMOUTH"

and make_rhel_yum_conf major minor arch =
  let buf = Buffer.create 4096 in
  let bpf fs = bprintf buf fs in

  let baseurl, srpms, optional =
    match major, arch with
    | 5, (I686|X86_64) ->
       let arch = match arch with I686 -> "i386" | _ -> string_of_arch arch in
       let topurl =
         sprintf "http://download.devel.redhat.com/released/RHEL-5-Server/U%d"
                 minor in
       sprintf "%s/%s/os/Server" topurl arch,
       sprintf "%s/source/SRPMS" topurl,
       None
    | 6, (I686|X86_64) ->
       let arch = match arch with I686 -> "i386" | _ -> string_of_arch arch in
       let topurl =
         sprintf "http://download.devel.redhat.com/released/RHEL-%d/%d.%d"
                 major major minor in
       sprintf "%s/Server/%s/os" topurl arch,
       sprintf "%s/source/SRPMS" topurl,
       Some (sprintf "%s/Server/optional/%s/os" arch topurl,
             sprintf "%s/Server/optional/source/SRPMS" topurl)
    | 7, (X86_64|Aarch64|PPC64|PPC64le) ->
       let topurl =
         sprintf "http://download.devel.redhat.com/released/RHEL-%d/%d.%d"
                 major major minor in
       sprintf "%s/Server/%s/os" topurl (string_of_arch arch),
       sprintf "%s/source/SRPMS" topurl,
       Some (sprintf "%s/Server-optional/%s/os" topurl (string_of_arch arch),
             sprintf "%s/Server-optional/source/tree" topurl)
    | _ -> assert false in

  bpf "\
# Yum configuration pointing to Red Hat servers.

[rhel%d]
name=RHEL %d Server
baseurl=%s
enabled=1
gpgcheck=0
keepcache=0

[rhel%d-source]
name=RHEL %d Server Source
baseurl=%s
enabled=0
gpgcheck=0
keepcache=0
" major major baseurl major major srpms;

  (match optional with
   | None -> ()
   | Some (optionalbaseurl, optionalsrpms) ->
      bpf "\

[rhel%d-optional]
name=RHEL %d Server Optional
baseurl=%s
enabled=1
gpgcheck=0
keepcache=0

[rhel%d-optional-source]
name=RHEL %d Server Optional
baseurl=%s
enabled=0
gpgcheck=0
keepcache=0
" major major optionalbaseurl major major optionalsrpms
  );

  Buffer.contents buf

and make_index_fragment os arch index_fragment output nvram revision
                        expandfs lvexpandfs virtual_size_gb =
  let virtual_size = Int64.of_int virtual_size_gb in
  let virtual_size = Int64.mul virtual_size 1024_L in
  let virtual_size = Int64.mul virtual_size 1024_L in
  let virtual_size = Int64.mul virtual_size 1024_L in

  let chan = open_out (index_fragment ^ ".new") in
  let fpf fs = fprintf chan fs in

  fpf "[%s]\n" (string_of_os_noarch os);
  fpf "name=%s\n" (long_name_of_os os arch);
  fpf "osinfo=%s\n" (true_os_variant_of_os os);
  fpf "arch=%s\n" (string_of_arch arch);
  fpf "file=%s\n" output;
  (match revision with
   | None -> ()
   | Some i -> fpf "revision=%d\n" i
  );
  fpf "checksum[sha512]=%s\n" (sha512sum_of_file output);
  fpf "format=raw\n";
  fpf "size=%Ld\n" virtual_size;
  fpf "compressed_size=%d\n" (size_of_file output);
  fpf "expand=%s\n" expandfs;
  (match lvexpandfs with
   | None -> ()
   | Some fs -> fpf "lvexpand=%s\n" fs
  );

  let notes = notes_of_os os arch nvram in
  (match notes with
   | first :: notes ->
      fpf "notes=%s\n" first;
      List.iter (fpf " %s\n") notes
   | [] -> assert false
  );
  fpf "\n";

  close_out chan;
  let cmd =
    sprintf "mv %s %s"
            (quote (index_fragment ^ ".new")) (quote index_fragment) in
  if Sys.command cmd <> 0 then exit 1

and long_name_of_os os arch =
  match os, arch with
  | CentOS (major, minor), X86_64 ->
     sprintf "CentOS %d.%d" major minor
  | CentOS (major, minor), arch ->
     sprintf "CentOS %d.%d (%s)" major minor (string_of_arch arch)
  | Debian (ver, dist), X86_64 ->
     sprintf "Debian %d (%s)" ver dist
  | Debian (ver, dist), arch ->
     sprintf "Debian %d (%s) (%s)" ver dist (string_of_arch arch)
  | Fedora ver, X86_64 ->
     sprintf "Fedora® %d Server" ver
  | Fedora ver, arch ->
     sprintf "Fedora® %d Server (%s)" ver (string_of_arch arch)
  | RHEL (major, minor), X86_64 ->
     sprintf "Red Hat Enterprise Linux® %d.%d" major minor
  | RHEL (major, minor), arch ->
     sprintf "Red Hat Enterprise Linux® %d.%d (%s)"
             major minor (string_of_arch arch)
  | Ubuntu (ver, dist), X86_64 ->
     sprintf "Ubuntu %s (%s)" ver dist
  | Ubuntu (ver, dist), arch ->
     sprintf "Ubuntu %s (%s) (%s)" ver dist (string_of_arch arch)

and notes_of_os os arch nvram =
  let args = ref [] in
  let add arg = args := arg :: !args in

  add (long_name_of_os os arch);
  add "";

  (match os with
   | CentOS _ ->
      add "This CentOS image contains only unmodified @Core group packages."
   | Debian _ ->
      add "This is a minimal Debian install."
   | Fedora _ ->
      add "This Fedora image contains only unmodified @Core group packages.";
      add "";
      add "Fedora and the Infinity design logo are trademarks of Red Hat, Inc.";
      add "Source and further information is available from http://fedoraproject.org/"
   | RHEL _ -> assert false (* cannot happen, see caller *)
   | Ubuntu _ ->
      add "This is a minimal Ubuntu install."
  );
  add "";

  (* Specific notes for particular versions. *)
  let reconfigure_ssh_host_keys_debian () =
    add "This image does not contain SSH host keys.  To regenerate them use:";
    add "";
    add "    --firstboot-command \"dpkg-reconfigure openssh-server\"";
    add "";
  in
  let fix_serial_console_debian () =
    add "The serial console is not working in this image.  To enable it, do:";
    add "";
    add "    --edit '/etc/default/grub:";
    add "    s/^GRUB_CMDLINE_LINUX_DEFAULT=.*/GRUB_CMDLINE_LINUX_DEFAULT=\"console=tty0 console=ttyS0,115200n8\"/' \\";
    add "    --run-command update-grub";
    add ""
  in
  let builder_account_warning () =
    add "IMPORTANT WARNING:";
    add "It seems to be impossible to create an Ubuntu >= 14.04 image using";
    add "preseed without creating a user account.  Therefore this image";
    add "contains a user account 'builder'.  I have disabled it, so that";
    add "people who don't read release notes don't get caught out, but you";
    add "might still wish to delete it completely.";
    add ""
  in
  (match os with
   | CentOS (6, _) ->
      add "‘virt-builder centos-6’ will always install the latest 6.x release.";
      add ""
   | Debian (8, _) ->
      reconfigure_ssh_host_keys_debian ();
      fix_serial_console_debian ();
   | Debian _ ->
      add "This image is so very minimal that it only includes an ssh server";
      add "and no virtual consoles.  To enable virtual consoles use this";
      add "virt-builder option:";
      add "";
      add "    --edit '/etc/inittab: s,^#([1-9].*respawn.*/sbin/getty.*),$1,'\n";
      add "";
      reconfigure_ssh_host_keys_debian ();
   | Ubuntu ("16.04", _) ->
      builder_account_warning ();
      fix_serial_console_debian ();
      reconfigure_ssh_host_keys_debian ();
   | Ubuntu (ver, _) when ver >= "14.04" ->
      builder_account_warning ();
      reconfigure_ssh_host_keys_debian ();
   | Ubuntu _ ->
      reconfigure_ssh_host_keys_debian ();
   | _ -> ()
  );

  (match nvram with
   | Some vars ->
      add "You will need to use the associated UEFI NVRAM variables file:";
      add (sprintf "    http://libguestfs.org/download/builder/%s" vars);
      add "";
   | None -> ()
  );

  add "This template was generated by a script in the libguestfs source tree:";
  add "    builder/templates/make-template.ml";
  add "Associated files used to prepare this template can be found in the";
  add "same directory.";

  List.rev !args

and read_revision filename =
  match (try Some (open_in filename) with Sys_error _ -> None) with
  | None -> None
  | Some chan ->
     let r = ref None in
     let rex = Str.regexp "^revision=\\([0-9]+\\)$" in
     (try
       let rec loop () =
         let line = input_line chan in
         if Str.string_match rex line 0 then (
           r := Some (int_of_string (Str.matched_group 1 line));
           raise End_of_file
         );
         loop ()
       in
       loop ()
     with End_of_file -> ()
     );
     close_in chan;
     !r

and sha512sum_of_file filename =
  let cmd = sprintf "sha512sum %s | awk '{print $1}'" (quote filename) in
  let chan = Unix.open_process_in cmd in
  let line = input_line chan in
  let pstat = Unix.close_process_in chan in
  check_process_status_for_errors pstat;
  line

and size_of_file filename = (Unix.stat filename).Unix.st_size

and open_guest filename =
  let g = new Guestfs.guestfs () in
  g#add_drive_opts ~format:"raw" filename;
  g#launch ();

  let roots = g#inspect_os () in
  if Array.length roots = 0 then (
    eprintf "%s: cannot inspect this guest - this may mean guest installation failed\n" prog;
    exit 1
  );
  let root = roots.(0) in

  let mps = g#inspect_get_mountpoints root in
  let cmp (a,_) (b,_) = compare (String.length a) (String.length b) in
  let mps = List.sort cmp mps in
  List.iter (fun (mp, dev) -> g#mount dev mp) mps;

  g

and check_process_status_for_errors = function
  | Unix.WEXITED 0 -> ()
  | Unix.WEXITED i ->
     eprintf "command exited with %d\n%!" i;
     exit 1
  | Unix.WSIGNALED i ->
     eprintf "command killed by signal %d\n%!" i;
     exit 1
  | Unix.WSTOPPED i ->
     eprintf "command stopped by signal %d\n%!" i;
     exit 1

and random8 =
  let chars = "abcdefghijklmnopqrstuvwxyz0123456789" in
  fun () ->
  String.concat "" (
    List.map (
      fun _ ->
        let c = Random.int 36 in
        let c = chars.[c] in
        String.make 1 c
      ) [1;2;3;4;5;6;7;8]
    )

let () = main ()
