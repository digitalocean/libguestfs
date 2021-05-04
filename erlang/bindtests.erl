#!/usr/bin/env escript
%! -smp enable -sname create_disk debug verbose

% libguestfs generated file
%  WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
%           generator/bindtests.ml
%           and from the code in the generator/ subdirectory.
%  ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
% 
%  Copyright (C) 2009-2019 Red Hat Inc.
% 
%  This program is free software; you can redistribute it and/or modify
%  it under the terms of the GNU General Public License as published by
%  the Free Software Foundation; either version 2 of the License, or
%  (at your option) any later version.
% 
%  This program is distributed in the hope that it will be useful,
%  but WITHOUT ANY WARRANTY; without even the implied warranty of
%  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%  GNU General Public License for more details.
% 
%  You should have received a copy of the GNU General Public License along
%  with this program; if not, write to the Free Software Foundation, Inc.,
%  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

main(_) ->
    {ok, G} = guestfs:create(),

    % We have to set the output file here because otherwise the
    % bindtests code would print its output on stdout, and that
    % channel is also being used by the erl-guestfs communications.
    Filename = "bindtests.tmp",
    ok = guestfs:internal_test_set_output(G, Filename),

    ok = guestfs:internal_test(G, "abc", "def", [], false, 0, 0, "123", "456", "abc\0abc", [{obool, true}, {oint, 1}, {oint64, 9223372036854775807}]),
    ok = guestfs:internal_test(G, "abc", undefined, [], false, 0, 0, "123", "456", "abc\0abc", [{oint64, 1}, {ostring, "string"}]),
    ok = guestfs:internal_test(G, "", "def", [], false, 0, 0, "123", "456", "abc\0abc", [{obool, false}, {oint64, -9223372036854775808}]),
    ok = guestfs:internal_test(G, "", "", [], false, 0, 0, "123", "456", "abc\0abc", []),
    ok = guestfs:internal_test(G, "abc", "def", ["1"], false, 0, 0, "123", "456", "abc\0abc"),
    ok = guestfs:internal_test(G, "abc", "def", ["1","2"], false, 0, 0, "123", "456", "abc\0abc"),
    ok = guestfs:internal_test(G, "abc", "def", ["1"], true, 0, 0, "123", "456", "abc\0abc"),
    ok = guestfs:internal_test(G, "abc", "def", ["1"], false, -1, -1, "123", "456", "abc\0abc"),
    ok = guestfs:internal_test(G, "abc", "def", ["1"], false, -2, -2, "123", "456", "abc\0abc"),
    ok = guestfs:internal_test(G, "abc", "def", ["1"], false, 1, 1, "123", "456", "abc\0abc"),
    ok = guestfs:internal_test(G, "abc", "def", ["1"], false, 2, 2, "123", "456", "abc\0abc"),
    ok = guestfs:internal_test(G, "abc", "def", ["1"], false, 4095, 9223372036854775807, "123", "456", "abc\0abc"),
    ok = guestfs:internal_test(G, "abc", "def", ["1"], false, 0, -9223372036854775808, "", "", "abc\0abc"),
    ok = guestfs:internal_test(G, "abc", "def", [], false, 0, 0, "123", "456", "abc\0abc", [{ostringlist, []}]),
    ok = guestfs:internal_test(G, "abc", "def", [], false, 0, 0, "123", "456", "abc\0abc", [{ostringlist, ["optelem1"]}]),
    ok = guestfs:internal_test(G, "abc", "def", [], false, 0, 0, "123", "456", "abc\0abc", [{ostringlist, ["optelem1","optelem2"]}]),
    ok = guestfs:internal_test(G, "abc", "def", [], false, 0, 0, "123", "456", "abc\0abc", [{ostringlist, ["optelem1","optelem2","optelem3"]}]),

    ok = guestfs:internal_test_close_output(G),
    ok = guestfs:close(G),
    {ok, File} = file:open(Filename, [append]),
    ok = file:write(File, "EOF\n"),
    ok = file:close(File).
