/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
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
 */

import java.util.Map;
import java.util.HashMap;
import com.redhat.et.libguestfs.*;

@SuppressWarnings("serial")
public class Bindtests {
    public static void main (String[] argv)
    {
        try {
            GuestFS g = new GuestFS ();
            Map<String, Object> o;

            o = new HashMap<String, Object>() {{
              put("obool", Boolean.TRUE);
              put("oint", 1);
              put("oint64", 9223372036854775807L);
            }};

            g.internal_test ("abc", "def", new String[]{}, false, 0, 0L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = new HashMap<String, Object>() {{
              put("oint64", 1L);
              put("ostring", "string");
            }};

            g.internal_test ("abc", null, new String[]{}, false, 0, 0L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = new HashMap<String, Object>() {{
              put("obool", Boolean.FALSE);
              put("oint64", -9223372036854775808L);
            }};

            g.internal_test ("", "def", new String[]{}, false, 0, 0L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = new HashMap<String, Object>() {{
            }};

            g.internal_test ("", "", new String[]{}, false, 0, 0L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = null;
            g.internal_test ("abc", "def", new String[]{"1"}, false, 0, 0L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = null;
            g.internal_test ("abc", "def", new String[]{"1","2"}, false, 0, 0L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = null;
            g.internal_test ("abc", "def", new String[]{"1"}, true, 0, 0L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = null;
            g.internal_test ("abc", "def", new String[]{"1"}, false, -1, -1L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = null;
            g.internal_test ("abc", "def", new String[]{"1"}, false, -2, -2L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = null;
            g.internal_test ("abc", "def", new String[]{"1"}, false, 1, 1L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = null;
            g.internal_test ("abc", "def", new String[]{"1"}, false, 2, 2L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = null;
            g.internal_test ("abc", "def", new String[]{"1"}, false, 4095, 9223372036854775807L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = null;
            g.internal_test ("abc", "def", new String[]{"1"}, false, 0, -9223372036854775808L, "", "", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = new HashMap<String, Object>() {{
              put("ostringlist", new String[]{});
            }};

            g.internal_test ("abc", "def", new String[]{}, false, 0, 0L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = new HashMap<String, Object>() {{
              put("ostringlist", new String[]{"optelem1"});
            }};

            g.internal_test ("abc", "def", new String[]{}, false, 0, 0L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = new HashMap<String, Object>() {{
              put("ostringlist", new String[]{"optelem1","optelem2"});
            }};

            g.internal_test ("abc", "def", new String[]{}, false, 0, 0L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);
            o = new HashMap<String, Object>() {{
              put("ostringlist", new String[]{"optelem1","optelem2","optelem3"});
            }};

            g.internal_test ("abc", "def", new String[]{}, false, 0, 0L, "123", "456", new byte[] { 97,98,99,0,97,98,99 }, o);

            System.out.println ("EOF");
        }
        catch (Exception exn) {
            System.err.println (exn);
            System.exit (1);
        }
    }
}
