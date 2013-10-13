(* libguestfs
 * Copyright (C) 2011 Red Hat Inc.
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *)

(* Please read generator/README first. *)

open Utils

(* NB: DO NOT REORDER THESE, as doing so will change the ABI.  Only
 * add new event types at the end of the list.
 *)
let events = [
  "close";                              (* close handle *)
  "subprocess_quit";                    (* subprocess quit *)
  "launch_done";                        (* launched *)

  "progress";                           (* progress message *)

  (* log messages from various sources *)
  "appliance";                          (* log messages from
                                           qemu / kernel / guestfsd / tools *)
  "library";                            (* log messages from library *)
  "trace";                              (* call trace messages *)

  "enter";                              (* enter a function *)

  "libvirt_auth";                       (* libvirt authentication request *)

  "warning";                            (* warnings from the library *)
]

let events = mapi (fun i name -> name, 1 lsl i) events

let all_events_bitmask = (1 lsl List.length events) - 1
