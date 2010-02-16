/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   src/generator.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2010 Red Hat Inc.
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

import com.redhat.et.libguestfs.*;

public class Bindtests {
    public static void main (String[] argv)
    {
        try {
            GuestFS g = new GuestFS ();
            g.test0 ("abc", "def", new String[]{}, false, 0, 0, "123", "456");
            g.test0 ("abc", null, new String[]{}, false, 0, 0, "123", "456");
            g.test0 ("", "def", new String[]{}, false, 0, 0, "123", "456");
            g.test0 ("", "", new String[]{}, false, 0, 0, "123", "456");
            g.test0 ("abc", "def", new String[]{"1"}, false, 0, 0, "123", "456");
            g.test0 ("abc", "def", new String[]{"1","2"}, false, 0, 0, "123", "456");
            g.test0 ("abc", "def", new String[]{"1"}, true, 0, 0, "123", "456");
            g.test0 ("abc", "def", new String[]{"1"}, false, -1, -1, "123", "456");
            g.test0 ("abc", "def", new String[]{"1"}, false, -2, -2, "123", "456");
            g.test0 ("abc", "def", new String[]{"1"}, false, 1, 1, "123", "456");
            g.test0 ("abc", "def", new String[]{"1"}, false, 2, 2, "123", "456");
            g.test0 ("abc", "def", new String[]{"1"}, false, 4095, 4095, "123", "456");
            g.test0 ("abc", "def", new String[]{"1"}, false, 0, 0, "", "");

            System.out.println ("EOF");
        }
        catch (Exception exn) {
            System.err.println (exn);
            System.exit (1);
        }
    }
}
