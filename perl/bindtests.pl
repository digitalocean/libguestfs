#!/usr/bin/perl -w
# libguestfs generated file
# WARNING: THIS FILE IS GENERATED FROM:
#   generator/generator_*.ml
# ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
#
# Copyright (C) 2009-2012 Red Hat Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

use strict;

use Sys::Guestfs;

my $g = Sys::Guestfs->new ();
$g->test0 ("abc", "def", [], 0, 0, 0, "123", "456", "abc\0abc", 'obool' => 1, 'oint' => 1);
$g->test0 ("abc", undef, [], 0, 0, 0, "123", "456", "abc\0abc", 'oint64' => 1, 'ostring' => 'string');
$g->test0 ("", "def", [], 0, 0, 0, "123", "456", "abc\0abc", 'obool' => 0);
$g->test0 ("", "", [], 0, 0, 0, "123", "456", "abc\0abc");
$g->test0 ("abc", "def", ["1"], 0, 0, 0, "123", "456", "abc\0abc");
$g->test0 ("abc", "def", ["1","2"], 0, 0, 0, "123", "456", "abc\0abc");
$g->test0 ("abc", "def", ["1"], 1, 0, 0, "123", "456", "abc\0abc");
$g->test0 ("abc", "def", ["1"], 0, -1, -1, "123", "456", "abc\0abc");
$g->test0 ("abc", "def", ["1"], 0, -2, -2, "123", "456", "abc\0abc");
$g->test0 ("abc", "def", ["1"], 0, 1, 1, "123", "456", "abc\0abc");
$g->test0 ("abc", "def", ["1"], 0, 2, 2, "123", "456", "abc\0abc");
$g->test0 ("abc", "def", ["1"], 0, 4095, 4095, "123", "456", "abc\0abc");
$g->test0 ("abc", "def", ["1"], 0, 0, 0, "", "", "abc\0abc");
print "EOF\n"
