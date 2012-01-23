=encoding utf8

=head1 НАЗВА

virt-win-reg - Export and merge Windows Registry entries from a Windows
guest

=head1 КОРОТКИЙ ОПИС

 virt-win-reg domname 'HKLM\Path\To\Subkey'

 virt-win-reg domname 'HKLM\Path\To\Subkey' name

 virt-win-reg domname 'HKLM\Path\To\Subkey' @

 virt-win-reg --merge domname [input.reg ...]

 virt-win-reg [--options] disk.img ... # instead of domname

=head1 ПОПЕРЕДЖЕННЯ

You must I<not> use C<virt-win-reg> with the I<--merge> option on live
virtual machines.  If you do this, you I<will> get irreversible disk
corruption in the VM.  C<virt-win-reg> tries to stop you from doing this,
but doesn't catch all cases.

Modifying the Windows Registry is an inherently risky operation.  The format
is deliberately obscure and undocumented, and Registry changes can leave the
system unbootable.  Therefore when using the I<--merge> option, make sure
you have a reliable backup first.

=head1 ОПИС

This program can export and merge Windows Registry entries from a Windows
guest.

The first parameter is the libvirt guest name or the raw disk image of a
Windows guest.

If I<--merge> is I<not> specified, then the chosen registry key is
displayed/exported (recursively).  For example:

 $ virt-win-reg Windows7 'HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft'

You can also display single values from within registry keys, for example:

 $ cvkey='HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion'
 $ virt-win-reg Windows7 $cvkey ProductName
 Windows 7 Enterprise

With I<--merge>, you can merge a textual regedit file into the Windows
Registry:

 $ virt-win-reg --merge Windows7 changes.reg

=head2 ПРИМІТКА

This program is only meant for simple access to the registry.  If you want
to do complicated things with the registry, we suggest you download the
Registry hive files from the guest using L<libguestfs(3)> or L<guestfish(1)>
and access them locally, eg. using L<hivex(3)>, L<hivexsh(1)> or
L<hivexregedit(1)>.

=head1 ПАРАМЕТРИ

=over 4

=item B<--help>

Показати коротку довідку.

=item B<--version>

Показати дані щодо версії і завершити роботу.

=item B<--debug>

Enable debugging messages.

=item B<-c адреса>

=item B<--connect адреса>

If using libvirt, connect to the given I<URI>.  If omitted, then we connect
to the default libvirt hypervisor.

If you specify guest block devices directly, then libvirt is not used at
all.

=item B<--format> raw

Specify the format of disk images given on the command line.  If this is
omitted then the format is autodetected from the content of the disk image.

If disk images are requested from libvirt, then this program asks libvirt
for this information.  In this case, the value of the format parameter is
ignored.

If working with untrusted raw-format guest disk images, you should ensure
the format is always specified.

=item B<--merge>

In merge mode, this merges a textual regedit file into the Windows Registry
of the virtual machine.  If this flag is I<not> given then virt-win-reg
displays or exports Registry entries instead.

Note that I<--merge> is I<unsafe> to use on live virtual machines, and will
result in disk corruption.  However exporting (without this flag)  is always
safe.

=item B<--encoding> UTF-16LE|ASCII

When merging (only), you may need to specify the encoding for strings to be
used in the hive file.  This is explained in detail in
L<Win::Hivex::Regedit(3)/ENCODING STRINGS>.

The default is to use UTF-16LE, which should work with recent versions of
Windows.

=item B<--unsafe-printable-strings>

When exporting (only), assume strings are UTF-16LE and print them as strings
instead of hex sequences.  Remove the final zero codepoint from strings if
present.

This is unsafe and does not preserve the fidelity of strings in the original
Registry for various reasons:

=over 4

=item *

Assumes the original encoding is UTF-16LE.  ASCII strings and strings in
other encodings will be corrupted by this transformation.

=item *

Assumes that everything which has type 1 or 2 is really a string and that
everything else is not a string, but the type field in real Registries is
not reliable.

=item *

Loses information about whether a zero codepoint followed the string in the
Registry or not.

=back

This all happens because the Registry itself contains no information about
how strings are encoded (see L<Win::Hivex::Regedit(3)/ENCODING STRINGS>).

You should only use this option for quick hacking and debugging of the
Registry contents, and I<never> use it if the output is going to be passed
into another program or stored in another Registry.

=back

=head1 ПІДТРИМУВАНІ СИСТЕМИ

The program currently supports Windows NT-derived guests starting with
Windows XP through to at least Windows 7.

The following Registry keys are supported:

=over 4

=item C<HKEY_LOCAL_MACHINE\SAM>

=item C<HKEY_LOCAL_MACHINE\SECURITY>

=item C<HKEY_LOCAL_MACHINE\SOFTWARE>

=item C<HKEY_LOCAL_MACHINE\SYSTEM>

=item C<HKEY_USERS\.DEFAULT>

=item C<HKEY_USERS\I<SID>>

where I<SID> is a Windows User SID (eg. C<S-1-5-18>).

=item C<HKEY_USERS\I<користувач>>

where I<username> is a local user name (this is a libguestfs extension).

=back

You can use C<HKLM> as a shorthand for C<HKEY_LOCAL_MACHINE>, and C<HKU> for
C<HKEY_USERS>.

The literal keys C<HKEY_USERS\$SID> and C<HKEY_CURRENT_USER> are not
supported (there is no "current user").

=head1 КОДУВАННЯ

C<virt-win-reg> expects that regedit files have already been reencoded in
the local encoding.  Usually on Linux hosts, this means UTF-8 with
Unix-style line endings.  Since Windows regedit files are often in UTF-16LE
with Windows-style line endings, you may need to reencode the whole file
before or after processing.

To reencode a file from Windows format to Linux (before processing it with
the I<--merge> option), you would do something like this:

 iconv -f utf-16le -t utf-8 < win.reg | dos2unix > linux.reg

To go in the opposite direction, after exporting and before sending the file
to a Windows user, do something like this:

 unix2dos linux.reg | iconv -f utf-8 -t utf-16le > win.reg

For more information about encoding, see L<Win::Hivex::Regedit(3)>.

If you are unsure about the current encoding, use the L<file(1)> command.
Recent versions of Windows regedit.exe produce a UTF-16LE file with
Windows-style (CRLF) line endings, like this:

 $ file software.reg
 software.reg: Little-endian UTF-16 Unicode text, with very long lines,
 with CRLF line terminators

This file would need conversion before you could I<--merge> it.

=head1 CurrentControlSet etc.

Registry keys like C<CurrentControlSet> don't really exist in the Windows
Registry at the level of the hive file, and therefore you cannot modify
these.

C<CurrentControlSet> is usually an alias for C<ControlSet001>.  In some
circumstances it might refer to another control set.  The way to find out is
to look at the C<HKLM\SYSTEM\Select> key:

 # virt-win-reg WindowsGuest 'HKLM\SYSTEM\Select'
 [HKEY_LOCAL_MACHINE\SYSTEM\Select]
 "Current"=dword:00000001
 "Default"=dword:00000001
 "Failed"=dword:00000000
 "LastKnownGood"=dword:00000002

"Current" is the one which Windows will choose when it boots.

Similarly, other C<Current...> keys in the path may need to be replaced.

=head1 DELETING REGISTRY KEYS AND VALUES

To delete a whole registry key, use the syntax:

 [-HKEY_LOCAL_MACHINE\Foo]

To delete a single value within a key, use the syntax:

 [HKEY_LOCAL_MACHINE\Foo]
 "Value"=-

=head1 WINDOWS TIPS

Note that some of these tips modify the guest disk image.  The guest I<must>
be shut off, else you will get disk corruption.

=head2 RUNNING A BATCH SCRIPT WHEN A USER LOGS IN

Prepare a DOS batch script, VBScript or executable.  Upload this using
L<guestfish(1)>.  For this example the script is called C<test.bat> and it
is uploaded into C<C:\>:

 guestfish -i -d WindowsGuest upload test.bat /test.bat

Prepare a regedit file containing the registry change:

 cat > test.reg <<'EOF'
 [HKLM\Software\Microsoft\Windows\CurrentVersion\RunOnce]
 "Test"="c:\\test.bat"
 EOF

In this example we use the key C<RunOnce> which means that the script will
run precisely once when the first user logs in.  If you want it to run every
time a user logs in, replace C<RunOnce> with C<Run>.

Оновіть регістр:

 virt-win-reg --merge WindowsGuest test.reg

=head2 INSTALLING A SERVICE

This section assumes you are familiar with Windows services, and you either
have a program which handles the Windows Service Control Protocol directly
or you want to run any program using a service wrapper like SrvAny or the
free RHSrvAny.

First upload the program and optionally the service wrapper.  In this case
the test program is called C<test.exe> and we are using the RHSrvAny
wrapper:

 guestfish -i -d WindowsGuest <<EOF
   upload rhsrvany.exe /rhsrvany.exe
   upload test.exe /test.exe
 EOF

Prepare a regedit file containing the registry changes.  In this example,
the first registry change is needed for the service itself or the service
wrapper (if used).  The second registry change is only needed because I am
using the RHSrvAny service wrapper.

 cat > service.reg <<'EOF'
 [HKLM\SYSTEM\ControlSet001\services\RHSrvAny]
 "Type"=dword:00000010
 "Start"=dword:00000002
 "ErrorControl"=dword:00000001
 "ImagePath"="c:\\rhsrvany.exe"
 "DisplayName"="RHSrvAny"
 "ObjectName"="NetworkService"
 
 [HKLM\SYSTEM\ControlSet001\services\RHSrvAny\Parameters]
 "CommandLine"="c:\\test.exe"
 "PWD"="c:\\Temp"
 EOF

Нотатки:

=over 4

=item *

For use of C<ControlSet001> see the section above in this manual page.  You
may need to adjust this according to the control set that is in use by the
guest.

=item *

C<"ObjectName"> controls the privileges that the service will have.  An
alternative is C<"ObjectName"="LocalSystem"> which would be the most
privileged account.

=item *

For the meaning of the magic numbers, see this Microsoft KB article:
L<http://support.microsoft.com/kb/103000>.

=back

Оновіть регістр:

 virt-win-reg --merge WindowsGuest service.reg

=head1 SHELL QUOTING

Be careful when passing parameters containing C<\> (backslash) in the
shell.  Usually you will have to use 'single quotes' or double backslashes
(but not both) to protect them from the shell.

Paths and value names are case-insensitive.

Libvirt guest names can contain arbitrary characters, some of which have
meaning to the shell such as C<#> and space.  You may need to quote or
escape these characters on the command line.  See the shell manual page
L<sh(1)> for details.

=head1 ТАКОЖ ПЕРЕГЛЯНЬТЕ

L<hivex(3)>, L<hivexsh(1)>, L<hivexregedit(1)>, L<guestfs(3)>,
L<guestfish(1)>, L<virt-cat(1)>, L<Sys::Guestfs(3)>,
L<Sys::Guestfs::Lib(3)>, L<Win::Hivex(3)>, L<Win::Hivex::Regedit(3)>,
L<Sys::Virt(3)>, L<http://libguestfs.org/>.

=head1 ВАДИ

When reporting bugs, please enable debugging and capture the I<complete>
output:

 export LIBGUESTFS_DEBUG=1
 virt-win-reg --debug [... rest ...] > /tmp/virt-win-reg.log 2>&1

Attach /tmp/virt-win-reg.log to a new bug report at
L<https://bugzilla.redhat.com/>

=head1 АВТОР

Richard W.M. Jones L<http://people.redhat.com/~rjones/>

=head1 АВТОРСЬКІ ПРАВА

©Red Hat Inc., 2010

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your option)
any later version.

Ця програма поширюється у сподіванні, що вона буде корисною, але БЕЗ
БУДЬ-ЯКИХ ГАРАНТІЙНИХ ЗОБОВ’ЯЗАНЬ; навіть без очевидної гарантії
ПРАЦЕЗДАТНОСТІ або ПРИДАТНОСТІ ДЛЯ ВИКОРИСТАННЯ З ПЕВНОЮ МЕТОЮ. Докладніше
про це можна дізнатися з GNU General Public License.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 51
Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

