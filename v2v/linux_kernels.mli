(* virt-v2v
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
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *)

(** Detect which kernels are installed and offered by the bootloader. *)

type kernel_info = {
  ki_app : Guestfs.application2;   (** The RPM package data. *)
  ki_name : string;                (** eg. "kernel-PAE" *)
  ki_version : string;             (** version-release *)
  ki_arch : string;                (** Kernel architecture. *)
  ki_vmlinuz : string;             (** The path of the vmlinuz file. *)
  ki_vmlinuz_stat : Guestfs.statns;(** stat(2) of vmlinuz *)
  ki_initrd : string option;       (** Path of initramfs, if found. *)
  ki_modpath : string;             (** The module path. *)
  ki_modules : string list;        (** The list of module names. *)
  ki_supports_virtio : bool;       (** Kernel has virtio drivers? *)
  ki_is_xen_kernel : bool;         (** Is a Xen paravirt kernel? *)
  ki_is_debug : bool;              (** Is debug kernel? *)
}
(** Kernel information. *)

val detect_kernels : Guestfs.guestfs -> Types.inspect ->
                     [> `Debian_family ] -> Linux_bootloaders.bootloader ->
                     kernel_info list
(** This function detects the kernels offered by the Linux
    bootloader (eg. grub).

    It will only return the intersection of kernels that are
    installed and kernels that the bootloader knows about.  The
    first kernel in the returned list is the default boot option,
    ie. what the guest would boot without interaction or overrides. *)
