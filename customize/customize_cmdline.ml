(* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2015 Red Hat Inc.
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

(* Command line argument parsing, both for the virt-customize binary
 * and for the other tools that share the same code.
 *)

open Printf

open Common_utils
open Common_gettext.Gettext

open Customize_utils

type ops = {
  ops : op list;
  flags : flags;
}
and op = [
  | `Chmod of string * string
      (* --chmod PERMISSIONS:FILE *)
  | `Delete of string
      (* --delete PATH *)
  | `Edit of string * string
      (* --edit FILE:EXPR *)
  | `FirstbootScript of string
      (* --firstboot SCRIPT *)
  | `FirstbootCommand of string
      (* --firstboot-command 'CMD+ARGS' *)
  | `FirstbootPackages of string list
      (* --firstboot-install PKG,PKG.. *)
  | `Hostname of string
      (* --hostname HOSTNAME *)
  | `InstallPackages of string list
      (* --install PKG,PKG.. *)
  | `Link of string * string list
      (* --link TARGET:LINK[:LINK..] *)
  | `Mkdir of string
      (* --mkdir DIR *)
  | `Password of string * Password.password_selector
      (* --password USER:SELECTOR *)
  | `RootPassword of Password.password_selector
      (* --root-password SELECTOR *)
  | `Script of string
      (* --run SCRIPT *)
  | `Command of string
      (* --run-command 'CMD+ARGS' *)
  | `Scrub of string
      (* --scrub FILE *)
  | `SSHInject of string * Ssh_key.ssh_key_selector
      (* --ssh-inject USER[:SELECTOR] *)
  | `Timezone of string
      (* --timezone TIMEZONE *)
  | `Update
      (* --update *)
  | `Upload of string * string
      (* --upload FILE:DEST *)
  | `Write of string * string
      (* --write FILE:CONTENT *)
]
and flags = {
  scrub_logfile : bool;
      (* --no-logfile *)
  password_crypto : Password.password_crypto option;
      (* --password-crypto md5|sha256|sha512 *)
  selinux_relabel : bool;
      (* --selinux-relabel *)
}

type argspec = Arg.key * Arg.spec * Arg.doc

let rec argspec () =
  let ops = ref [] in
  let scrub_logfile = ref false in
  let password_crypto = ref None in
  let selinux_relabel = ref false in

  let rec get_ops () = {
    ops = List.rev !ops;
    flags = get_flags ();
  }
  and get_flags () = {
    scrub_logfile = !scrub_logfile;
    password_crypto = !password_crypto;
    selinux_relabel = !selinux_relabel;
  }
  in

  let split_string_pair option_name arg =
    let i =
      try String.index arg ':'
      with Not_found ->
        error (f_"invalid format for '--%s' parameter, see the man page")
          option_name in
    let len = String.length arg in
    String.sub arg 0 i, String.sub arg (i+1) (len-(i+1))
  in
  let split_string_list arg =
    string_nsplit "," arg
  in
  let split_links_list option_name arg =
    match string_nsplit ":" arg with
    | [] | [_] ->
      error (f_"invalid format for '--%s' parameter, see the man page")
        option_name
    | target :: lns -> target, lns
  in

  let argspec = [
    (
      "--chmod",
      Arg.String (
        fun s ->
          let p = split_string_pair "chmod" s in
          ops := `Chmod p :: !ops
      ),
      s_"PERMISSIONS:FILE" ^ " " ^ s_"Change the permissions of a file"
    ),
    Some "PERMISSIONS:FILE", "Change the permissions of C<FILE> to C<PERMISSIONS>.\n\nI<Note>: C<PERMISSIONS> by default would be decimal, unless you prefix\nit with C<0> to get octal, ie. use C<0700> not C<700>.";
    (
      "--delete",
      Arg.String (fun s -> ops := `Delete s :: !ops),
      s_"PATH" ^ " " ^ s_"Delete a file or directory"
    ),
    Some "PATH", "Delete a file from the guest.  Or delete a directory (and all its\ncontents, recursively).\n\nSee also: I<--upload>, I<--scrub>.";
    (
      "--edit",
      Arg.String (
        fun s ->
          let p = split_string_pair "edit" s in
          ops := `Edit p :: !ops
      ),
      s_"FILE:EXPR" ^ " " ^ s_"Edit file using Perl expression"
    ),
    Some "FILE:EXPR", "Edit C<FILE> using the Perl expression C<EXPR>.\n\nBe careful to properly quote the expression to prevent it from\nbeing altered by the shell.\n\nNote that this option is only available when Perl 5 is installed.\n\nSee L<virt-edit(1)/NON-INTERACTIVE EDITING>.";
    (
      "--firstboot",
      Arg.String (fun s -> ops := `FirstbootScript s :: !ops),
      s_"SCRIPT" ^ " " ^ s_"Run script at first guest boot"
    ),
    Some "SCRIPT", "Install C<SCRIPT> inside the guest, so that when the guest first boots\nup, the script runs (as root, late in the boot process).\n\nThe script is automatically chmod +x after installation in the guest.\n\nThe alternative version I<--firstboot-command> is the same, but it\nconveniently wraps the command up in a single line script for you.\n\nYou can have multiple I<--firstboot> options.  They run in the same\norder that they appear on the command line.\n\nSee also I<--run>.";
    (
      "--firstboot-command",
      Arg.String (fun s -> ops := `FirstbootCommand s :: !ops),
      s_"'CMD+ARGS'" ^ " " ^ s_"Run command at first guest boot"
    ),
    Some "'CMD+ARGS'", "Run command (and arguments) inside the guest when the guest first\nboots up (as root, late in the boot process).\n\nYou can have multiple I<--firstboot> options.  They run in the same\norder that they appear on the command line.\n\nSee also I<--run>.";
    (
      "--firstboot-install",
      Arg.String (
        fun s ->
          let ss = split_string_list s in
          ops := `FirstbootPackages ss :: !ops
      ),
      s_"PKG,PKG.." ^ " " ^ s_"Add package(s) to install at first boot"
    ),
    Some "PKG,PKG..", "Install the named packages (a comma-separated list).  These are\ninstalled when the guest first boots using the guest's package manager\n(eg. apt, yum, etc.) and the guest's network connection.\n\nFor an overview on the different ways to install packages, see\nL<virt-builder(1)/INSTALLING PACKAGES>.";
    (
      "--hostname",
      Arg.String (fun s -> ops := `Hostname s :: !ops),
      s_"HOSTNAME" ^ " " ^ s_"Set the hostname"
    ),
    Some "HOSTNAME", "Set the hostname of the guest to C<HOSTNAME>.  You can use a\ndotted hostname.domainname (FQDN) if you want.";
    (
      "--install",
      Arg.String (
        fun s ->
          let ss = split_string_list s in
          ops := `InstallPackages ss :: !ops
      ),
      s_"PKG,PKG.." ^ " " ^ s_"Add package(s) to install"
    ),
    Some "PKG,PKG..", "Install the named packages (a comma-separated list).  These are\ninstalled during the image build using the guest's package manager\n(eg. apt, yum, etc.) and the host's network connection.\n\nFor an overview on the different ways to install packages, see\nL<virt-builder(1)/INSTALLING PACKAGES>.\n\nSee also I<--update>.";
    (
      "--link",
      Arg.String (
        fun s ->
          let ss = split_links_list "link" s in
          ops := `Link ss :: !ops
      ),
      s_"TARGET:LINK[:LINK..]" ^ " " ^ s_"Create symbolic links"
    ),
    Some "TARGET:LINK[:LINK..]", "Create symbolic link(s) in the guest, starting at C<LINK> and\npointing at C<TARGET>.";
    (
      "--mkdir",
      Arg.String (fun s -> ops := `Mkdir s :: !ops),
      s_"DIR" ^ " " ^ s_"Create a directory"
    ),
    Some "DIR", "Create a directory in the guest.\n\nThis uses S<C<mkdir -p>> so any intermediate directories are created,\nand it also works if the directory already exists.";
    (
      "--password",
      Arg.String (
        fun s ->
          let user, sel = split_string_pair "password" s in
          let sel = Password.parse_selector sel in
          ops := `Password (user, sel) :: !ops
      ),
      s_"USER:SELECTOR" ^ " " ^ s_"Set user password"
    ),
    Some "USER:SELECTOR", "Set the password for C<USER>.  (Note this option does I<not>\ncreate the user account).\n\nSee L<virt-builder(1)/USERS AND PASSWORDS> for the format of\nthe C<SELECTOR> field, and also how to set up user accounts.";
    (
      "--root-password",
      Arg.String (
        fun s ->
          let sel = Password.parse_selector s in
          ops := `RootPassword sel :: !ops
      ),
      s_"SELECTOR" ^ " " ^ s_"Set root password"
    ),
    Some "SELECTOR", "Set the root password.\n\nSee L<virt-builder(1)/USERS AND PASSWORDS> for the format of\nthe C<SELECTOR> field, and also how to set up user accounts.\n\nNote: In virt-builder, if you I<don't> set I<--root-password>\nthen the guest is given a I<random> root password.";
    (
      "--run",
      Arg.String (fun s -> ops := `Script s :: !ops),
      s_"SCRIPT" ^ " " ^ s_"Run script in disk image"
    ),
    Some "SCRIPT", "Run the shell script (or any program) called C<SCRIPT> on the disk\nimage.  The script runs virtualized inside a small appliance, chrooted\ninto the guest filesystem.\n\nThe script is automatically chmod +x.\n\nIf libguestfs supports it then a limited network connection is\navailable but it only allows outgoing network connections.  You can\nalso attach data disks (eg. ISO files) as another way to provide data\n(eg. software packages) to the script without needing a network\nconnection (I<--attach>).  You can also upload data files (I<--upload>).\n\nYou can have multiple I<--run> options.  They run\nin the same order that they appear on the command line.\n\nSee also: I<--firstboot>, I<--attach>, I<--upload>.";
    (
      "--run-command",
      Arg.String (fun s -> ops := `Command s :: !ops),
      s_"'CMD+ARGS'" ^ " " ^ s_"Run command in disk image"
    ),
    Some "'CMD+ARGS'", "Run the command and arguments on the disk image.  The command runs\nvirtualized inside a small appliance, chrooted into the guest filesystem.\n\nIf libguestfs supports it then a limited network connection is\navailable but it only allows outgoing network connections.  You can\nalso attach data disks (eg. ISO files) as another way to provide data\n(eg. software packages) to the script without needing a network\nconnection (I<--attach>).  You can also upload data files (I<--upload>).\n\nYou can have multiple I<--run-command> options.  They run\nin the same order that they appear on the command line.\n\nSee also: I<--firstboot>, I<--attach>, I<--upload>.";
    (
      "--scrub",
      Arg.String (fun s -> ops := `Scrub s :: !ops),
      s_"FILE" ^ " " ^ s_"Scrub a file"
    ),
    Some "FILE", "Scrub a file from the guest.  This is like I<--delete> except that:\n\n=over 4\n\n=item *\n\nIt scrubs the data so a guest could not recover it.\n\n=item *\n\nIt cannot delete directories, only regular files.\n\n=back";
    (
      "--ssh-inject",
      Arg.String (
        fun s ->
          let user, selstr = string_split ":" s in
          let sel = Ssh_key.parse_selector selstr in
          ops := `SSHInject (user, sel) :: !ops
      ),
      s_"USER[:SELECTOR]" ^ " " ^ s_"Inject a public key into the guest"
    ),
    Some "USER[:SELECTOR]", "Inject an ssh key so the given C<USER> will be able to log in over\nssh without supplying a password.  The C<USER> must exist already\nin the guest.\n\nSee L<virt-builder(1)/SSH KEYS> for the format of\nthe C<SELECTOR> field.\n\nYou can have multiple I<--ssh-inject> options, for different users\nand also for more keys for each user.";
    (
      "--timezone",
      Arg.String (fun s -> ops := `Timezone s :: !ops),
      s_"TIMEZONE" ^ " " ^ s_"Set the default timezone"
    ),
    Some "TIMEZONE", "Set the default timezone of the guest to C<TIMEZONE>.  Use a location\nstring like C<Europe/London>";
    (
      "--update",
      Arg.Unit (fun () -> ops := `Update :: !ops),
      " " ^ s_"Update core packages"
    ),
    None, "Do the equivalent of C<yum update>, C<apt-get upgrade>, or whatever\ncommand is required to update the packages already installed in the\ntemplate to their latest versions.\n\nSee also I<--install>.";
    (
      "--upload",
      Arg.String (
        fun s ->
          let p = split_string_pair "upload" s in
          ops := `Upload p :: !ops
      ),
      s_"FILE:DEST" ^ " " ^ s_"Upload local file to destination"
    ),
    Some "FILE:DEST", "Upload local file C<FILE> to destination C<DEST> in the disk image.\nFile owner and permissions from the original are preserved, so you\nshould set them to what you want them to be in the disk image.\n\nC<DEST> could be the final filename.  This can be used to rename\nthe file on upload.\n\nIf C<DEST> is a directory name (which must already exist in the guest)\nthen the file is uploaded into that directory, and it keeps the same\nname as on the local filesystem.\n\nSee also: I<--mkdir>, I<--delete>, I<--scrub>.";
    (
      "--write",
      Arg.String (
        fun s ->
          let p = split_string_pair "write" s in
          ops := `Write p :: !ops
      ),
      s_"FILE:CONTENT" ^ " " ^ s_"Write file"
    ),
    Some "FILE:CONTENT", "Write C<CONTENT> to C<FILE>.";
    (
      "--no-logfile",
      Arg.Set scrub_logfile,
      " " ^ s_"Scrub build log file"
    ),
    None, "Scrub C<builder.log> (log file from build commands) from the image\nafter building is complete.  If you don't want to reveal precisely how\nthe image was built, use this option.\n\nSee also: L</LOG FILE>.";
    (
      "--password-crypto",
      Arg.String (
        fun s ->
          password_crypto := Some (Password.password_crypto_of_string s)
      ),
      "md5|sha256|sha512" ^ " " ^ s_"Set password crypto"
    ),
    Some "md5|sha256|sha512", "When the virt tools change or set a password in the guest, this\noption sets the password encryption of that password to\nC<md5>, C<sha256> or C<sha512>.\n\nC<sha256> and C<sha512> require glibc E<ge> 2.7 (check crypt(3) inside\nthe guest).\n\nC<md5> will work with relatively old Linux guests (eg. RHEL 3), but\nis not secure against modern attacks.\n\nThe default is C<sha512> unless libguestfs detects an old guest that\ndidn't have support for SHA-512, in which case it will use C<md5>.\nYou can override libguestfs by specifying this option.\n\nNote this does not change the default password encryption used\nby the guest when you create new user accounts inside the guest.\nIf you want to do that, then you should use the I<--edit> option\nto modify C</etc/sysconfig/authconfig> (Fedora, RHEL) or\nC</etc/pam.d/common-password> (Debian, Ubuntu).";
    (
      "--selinux-relabel",
      Arg.Set selinux_relabel,
      " " ^ s_"Relabel files with correct SELinux labels"
    ),
    None, "Relabel files in the guest so that they have the correct SELinux label.\n\nYou should only use this option for guests which support SELinux.";
  ] in

  argspec, get_ops
