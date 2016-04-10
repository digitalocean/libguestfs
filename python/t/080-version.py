# libguestfs Python bindings
# Copyright (C) 2016 Red Hat Inc.
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
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

import unittest
import sys
import os
import guestfs

if sys.version_info >= (3, 0):
    cl = int
else:
    cl = long

class Test080Version (unittest.TestCase):
    def setUp (self):
        self.g = guestfs.GuestFS (python_return_dict=True)
        self.version = self.g.version ()

    def test_major (self):
        self.assertEqual (self.version['major'], 1)

    def test_minor (self):
        self.assertTrue (isinstance (self.version['minor'], cl))

    def test_release (self):
        self.assertTrue (isinstance (self.version['release'], cl))

    def test_extra (self):
        self.assertTrue (isinstance (self.version['extra'], str))

if __name__ == '__main__':
    unittest.main ()
