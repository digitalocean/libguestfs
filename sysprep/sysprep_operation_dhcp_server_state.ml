(* virt-sysprep
 * Copyright (C) 2012 Red Hat Inc.
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

open Sysprep_operation
open Common_gettext.Gettext

module G = Guestfs

let dhcp_server_state_perform (g : Guestfs.guestfs) root side_effects =
  Array.iter g#rm_rf (g#glob_expand "/var/lib/dhcpd/*")

let op = {
  defaults with
    name = "dhcp-server-state";
    enabled_by_default = true;
    heading = s_"Remove DHCP server leases";
    perform_on_filesystems = Some dhcp_server_state_perform;
}

let () = register_operation op
