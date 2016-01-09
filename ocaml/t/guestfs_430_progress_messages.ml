(* libguestfs OCaml tests
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *)

let callback_invoked = ref 0

let callback _ _ _ _ = incr callback_invoked

let () =
  let g = new Guestfs.guestfs () in
  g#add_drive "/dev/null";
  g#launch ();

  let eh = g#set_event_callback callback [Guestfs.EVENT_PROGRESS] in
  assert ("ok" = g#debug "progress" [| "5" |]);
  assert (!callback_invoked > 0);

  callback_invoked := 0;
  g#delete_event_callback eh;
  assert ("ok" = g#debug "progress" [| "5" |]);
  assert (!callback_invoked = 0);

  ignore (g#set_event_callback callback [Guestfs.EVENT_PROGRESS]);
  assert ("ok" = g#debug "progress" [| "5" |]);
  assert (!callback_invoked > 0);

  g#close ()

let () = Gc.compact ()
