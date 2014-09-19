#!/bin/bash -
# libguestfs
# Copyright (C) 2011 Red Hat Inc.
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

# Test guestfish string escapes.

set -e

rm -f test.output test.error test.error.old

$VG guestfish <<'EOF' 2>test.error | od -b > test.output
echo ""
echo " "
echo "  "
echo "\n"
echo "\r"
echo "\n\n"
echo "\x01"
echo "\001"
echo "\100"

# These are invalid:
-echo "\x00"
-echo "\000"
-echo "\x"
-echo "\x0"
-echo "\7"
-echo "\77"
-echo "\777"
-echo "\"
-echo "\\\"
-echo "
-echo """
EOF

# Since trace and debug output also goes to stderr, we must
# remove it before testing.
mv test.error test.error.old
< test.error.old \
    grep -v '^libguestfs: ' | \
    grep -vF "$HOME/.guestfish:" | \
    sed 's/.*guestfish: //' \
    > test.error

if [ "$(cat test.error)" != "\
invalid escape sequence in string (starting at offset 0)
invalid escape sequence in string (starting at offset 0)
invalid escape sequence in string (starting at offset 0)
invalid escape sequence in string (starting at offset 0)
invalid escape sequence in string (starting at offset 0)
invalid escape sequence in string (starting at offset 0)
invalid escape sequence in string (starting at offset 0)
unterminated double quote
unterminated double quote
unterminated double quote
command arguments not separated by whitespace" ]; then
    echo "unexpected stderr from guestfish:"
    cat test.error
    echo "[end of stderr]"
    exit 1
fi

if [ "$(cat test.output)" != "\
0000000 012 040 012 040 040 012 012 012 015 012 012 012 012 001 012 001
0000020 012 100 012
0000023" ]; then
    echo "unexpected stdout from guestfish:"
    cat test.output
    echo "[end of stdout]"
    exit 1
fi

rm -f test.output test.error test.error.old
