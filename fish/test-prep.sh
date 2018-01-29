#!/bin/bash -
# libguestfs generated file
# WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
#          generator/fish.ml
#          and from the code in the generator/ subdirectory.
# ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
#
# Copyright (C) 2009-2018 Red Hat Inc.
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

set -e

$TEST_FUNCTIONS
skip_if_skipped

rm -f prep{1..7}.img

$VG guestfish \
    -N prep1.img=disk \
    -N prep2.img=part \
    -N prep3.img=fs \
    -N prep4.img=lv:/dev/VG1/LV \
    -N prep5.img=lvfs:/dev/VG2/LV \
    -N prep6.img=bootroot \
    -N prep7.img=bootrootlv:/dev/VG3/LV \
    exit

rm prep{1..7}.img
