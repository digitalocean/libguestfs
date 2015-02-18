--TEST--
General PHP binding test.
--SKIPIF--
<?php
if (PHP_INT_SIZE < 8)
  print 'skip 32bit platforms due to limited int in PHP';
?>
--FILE--
<?php
$g = guestfs_create ();
if (guestfs_internal_test ($g, "abc", "def", array(), 0, 0, 0, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", NULL, array(), 0, 0, 0, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "", "def", array(), 0, 0, 0, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "", "", array(), 0, 0, 0, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", "def", array("1"), 0, 0, 0, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", "def", array("1","2"), 0, 0, 0, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", "def", array("1"), 1, 0, 0, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", "def", array("1"), 0, -1, -1, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", "def", array("1"), 0, -2, -2, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", "def", array("1"), 0, 1, 1, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", "def", array("1"), 0, 2, 2, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", "def", array("1"), 0, 4095, 9223372036854775807, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", "def", array("1"), 0, 0, -9223372036854775808, "", "", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", "def", array(), 0, 0, 0, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", "def", array(), 0, 0, 0, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", "def", array(), 0, 0, 0, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
if (guestfs_internal_test ($g, "abc", "def", array(), 0, 0, 0, "123", "456", "abc\0abc") == false) {
  echo ("Call failed: " . guestfs_last_error ($g) . "\n");
  exit;
}
echo ("EOF\n");
?>
--EXPECT--
abc
def
[]
false
0
0
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
null
[]
false
0
0
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset

def
[]
false
0
0
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset


[]
false
0
0
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
def
["1"]
false
0
0
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
def
["1", "2"]
false
0
0
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
def
["1"]
true
0
0
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
def
["1"]
false
-1
-1
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
def
["1"]
false
-2
-2
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
def
["1"]
false
1
1
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
def
["1"]
false
2
2
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
def
["1"]
false
4095
9223372036854775807
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
def
["1"]
false
0
-9223372036854775808


<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
def
[]
false
0
0
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
def
[]
false
0
0
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
def
[]
false
0
0
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
abc
def
[]
false
0
0
123
456
<61><62><63><00><61><62><63>
obool: unset
oint: unset
oint64: unset
ostring: unset
ostringlist: unset
EOF
