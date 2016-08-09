# libguestfs
# Copyright (C) 2015 Red Hat Inc.
# tests/daemon/captive-daemon.pm.  Generated from captive-daemon.pm.in by configure.
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

# Small library to help testing the daemon directly.

package CaptiveDaemon;

use strict;
use warnings;

use Sys::Guestfs;

$| = 1;

# Filled in by autoconf.
my %var;
$var{top_builddir} = "../..";
$var{abs_top_srcdir} = "/tmp/goaljobstmp87b23681ca026df5074d0df96e909e5a/libguestfs";
$var{abs_top_builddir} = "/tmp/goaljobstmp87b23681ca026df5074d0df96e909e5a/libguestfs";
$var{VALGRIND} = "valgrind";

# Now we have to substitute the above variables into this one:
my $VG = '$(VALGRIND) --vgdb=no --log-file=$(abs_top_builddir)/tmp/valgrind-%q{T}-%p.log --leak-check=full --error-exitcode=119 --suppressions=$(abs_top_srcdir)/valgrind-suppressions --trace-children=no --child-silent-after-fork=yes --run-libc-freeres=no';
$VG =~ s/\$\(([A-Za-z_]+)\)/ $var{"$1"} /ge;

# Refuse to run if the user is trying to run tests as root.  There's
# too much risk that things will go badly wrong.
if ($> == 0) {
    print "$0: don't run the libguestfs tests as root!\n";
    exit 77
}

sub run_tests {
    my $g = Sys::Guestfs->new();
    my $tmpdir = $g->get_tmpdir;
    my $verbose = $g->get_verbose;
    $g->close;

    # Choose a random name for the socket.  The daemon will create the
    # socket so we don't need to do that.
    my @chars = ("A".."Z", "a".."z", "0".."9");
    my $sockname = $tmpdir;
    $sockname .= "/";
    $sockname .= $chars[rand @chars] for 1..8;

    # Assemble the command we will run in the subprocess.
    my $cmd =
        "$var{top_builddir}/daemon/guestfsd --channel $sockname -r -t -l";
    if ($verbose) {
        $cmd = $cmd . " -v"
    }
    if ($ENV{TEST_WITH_VALGRIND}) {
        $cmd = $VG . " " . $cmd
    }

    if ($verbose) {
        print "$0: running: $cmd\n";
    }

    # Fork to run the daemon in the background.
    my $pid = fork ();
    die "fork: $!" unless defined $pid;
    if ($pid == 0) {
        # Child process: the daemon.
        exec $cmd or die "guestfsd: $!";
    }

    # Wait for the daemon to create the socket, but if it doesn't
    # appear after a short timeout, assume there has been a failure.
    for (my $i = 0; $i < 10; ++$i) {
        last if -S $sockname;
        sleep 1;
    }
    die "subprocess did not create the socket, check earlier messages\n"
        unless -S $sockname;

    # Create the libguestfs handle and connect to the daemon using
    # libguestfs live.
    $g = Sys::Guestfs->new ();
    $g->set_backend ("unix:" . $sockname);
    $g->set_autosync (0);
    $g->launch;

    # Run the user tests.
    my $r = ::tests ($g);

    # Tell the daemon to exit cleanly, and remove the socket.
    $g->internal_exit;
    $g->close;
    unlink $sockname;

    waitpid ($pid, 0) or die "waitpid: $!";
    if ($? != 0) {
        my $signal = $? & 127;
        die "ERROR: guestfsd died on signal $signal\n" if $signal;
        my $crash = $? & 128;
        die "ERROR: guestfsd core dumped\n" if $crash;
        my $status = $? >> 8;
        die "ERROR: guestfsd died with exit code 119 (valgrind failure)\n"
            if $status == 119;
        die "ERROR: guestfsd died with exit code $status\n";
    }

    # Exit with failure if the user test failed.
    exit 1 unless $r
}

1;
