/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2013 Red Hat Inc.
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
 */

package main

import (
    "fmt"
    "libguestfs.org/guestfs"
)

func main() {
    g, errno := guestfs.Create ()
    if errno != nil {
        panic (fmt.Sprintf ("could not create handle: %s", errno))
    }
    defer g.Close ()

    if err := g.Internal_test ("abc", string_addr ("def"), []string{}, false, 0, 0, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, &guestfs.OptargsInternal_test{Obool_is_set: true, Obool: true, Oint_is_set: true, Oint: 1, Oint64_is_set: true, Oint64: 9223372036854775807}); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", nil, []string{}, false, 0, 0, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, &guestfs.OptargsInternal_test{Oint64_is_set: true, Oint64: 1, Ostring_is_set: true, Ostring: "string"}); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("", string_addr ("def"), []string{}, false, 0, 0, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, &guestfs.OptargsInternal_test{Obool_is_set: true, Obool: false, Oint64_is_set: true, Oint64: -9223372036854775808}); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("", string_addr (""), []string{}, false, 0, 0, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, &guestfs.OptargsInternal_test{}); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", string_addr ("def"), []string{"1"}, false, 0, 0, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, nil); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", string_addr ("def"), []string{"1", "2"}, false, 0, 0, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, nil); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", string_addr ("def"), []string{"1"}, true, 0, 0, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, nil); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", string_addr ("def"), []string{"1"}, false, -1, -1, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, nil); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", string_addr ("def"), []string{"1"}, false, -2, -2, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, nil); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", string_addr ("def"), []string{"1"}, false, 1, 1, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, nil); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", string_addr ("def"), []string{"1"}, false, 2, 2, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, nil); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", string_addr ("def"), []string{"1"}, false, 4095, 9223372036854775807, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, nil); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", string_addr ("def"), []string{"1"}, false, 0, -9223372036854775808, "", "", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, nil); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", string_addr ("def"), []string{}, false, 0, 0, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, &guestfs.OptargsInternal_test{Ostringlist_is_set: true, Ostringlist: []string{}}); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", string_addr ("def"), []string{}, false, 0, 0, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, &guestfs.OptargsInternal_test{Ostringlist_is_set: true, Ostringlist: []string{"optelem1"}}); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", string_addr ("def"), []string{}, false, 0, 0, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, &guestfs.OptargsInternal_test{Ostringlist_is_set: true, Ostringlist: []string{"optelem1", "optelem2"}}); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }
    if err := g.Internal_test ("abc", string_addr ("def"), []string{}, false, 0, 0, "123", "456", []byte{'a', 'b', 'c', '\000', 'a', 'b', 'c'}, &guestfs.OptargsInternal_test{Ostringlist_is_set: true, Ostringlist: []string{"optelem1", "optelem2", "optelem3"}}); err != nil {
        panic (fmt.Sprintf ("error: %s", err))
    }

    fmt.Printf ("EOF\n")
}

/* Work around golang lameness */
func string_addr (s string) *string {
    return &s;
}
