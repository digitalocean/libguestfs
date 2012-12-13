--TEST--
Check function with optional arguments.
--FILE--
<?php

// See comment in php/run-php-tests.sh.
//putenv ('LIBGUESTFS_DEBUG=1');

$g = guestfs_create ();
if ($g == false) {
  echo ("Failed to create guestfs_php handle.\n");
  exit;
}
if (guestfs_add_drive ($g, "/dev/null") == false) {
  echo ("Failed add_drive, no optional arguments.\n");
  exit;
}
if (guestfs_add_drive ($g, "/dev/null", 0) == false) {
  echo ("Failed add_drive, one optional argument.\n");
  exit;
}
if (guestfs_add_drive ($g, "/dev/null", 1) == false) {
  echo ("Failed add_drive, one optional argument.\n");
  exit;
}
if (guestfs_add_drive ($g, "/dev/null", 1, "qcow2") == false) {
  echo ("Failed add_drive, two optional arguments.\n");
  exit;
}
echo ("Completed tests OK.\n");
?>
--EXPECT--
Completed tests OK.
