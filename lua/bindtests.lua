-- libguestfs generated file
-- WARNING: THIS FILE IS GENERATED FROM:
--   generator/ *.ml
-- ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
--
-- Copyright (C) 2009-2012 Red Hat Inc.
--
-- This program is free software; you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation; either version 2 of the License, or
-- (at your option) any later version.
--
-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License along
-- with this program; if not, write to the Free Software Foundation, Inc.,
-- 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

local G = require "guestfs"

local g = G.create ()

g:internal_test ("abc", "def", {}, false, 0, "0", "123", "456", "abc\0abc", {obool = true, oint = 1, oint64 = "9223372036854775807"})
g:internal_test ("abc", nil, {}, false, 0, "0", "123", "456", "abc\0abc", {oint64 = "1", ostring = "string"})
g:internal_test ("", "def", {}, false, 0, "0", "123", "456", "abc\0abc", {obool = false, oint64 = "-9223372036854775808"})
g:internal_test ("", "", {}, false, 0, "0", "123", "456", "abc\0abc", {})
g:internal_test ("abc", "def", {"1"}, false, 0, "0", "123", "456", "abc\0abc")
g:internal_test ("abc", "def", {"1","2"}, false, 0, "0", "123", "456", "abc\0abc")
g:internal_test ("abc", "def", {"1"}, true, 0, "0", "123", "456", "abc\0abc")
g:internal_test ("abc", "def", {"1"}, false, -1, "-1", "123", "456", "abc\0abc")
g:internal_test ("abc", "def", {"1"}, false, -2, "-2", "123", "456", "abc\0abc")
g:internal_test ("abc", "def", {"1"}, false, 1, "1", "123", "456", "abc\0abc")
g:internal_test ("abc", "def", {"1"}, false, 2, "2", "123", "456", "abc\0abc")
g:internal_test ("abc", "def", {"1"}, false, 4095, "9223372036854775807", "123", "456", "abc\0abc")
g:internal_test ("abc", "def", {"1"}, false, 0, "-9223372036854775808", "", "", "abc\0abc")
g:internal_test ("abc", "def", {}, false, 0, "0", "123", "456", "abc\0abc", {ostringlist = {}})
g:internal_test ("abc", "def", {}, false, 0, "0", "123", "456", "abc\0abc", {ostringlist = {"optelem1"}})
g:internal_test ("abc", "def", {}, false, 0, "0", "123", "456", "abc\0abc", {ostringlist = {"optelem1","optelem2"}})
g:internal_test ("abc", "def", {}, false, 0, "0", "123", "456", "abc\0abc", {ostringlist = {"optelem1","optelem2","optelem3"}})

print ("EOF")
