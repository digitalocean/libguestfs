# libguestfs translations of man pages and POD files
# Copyright (C) 2010-2012 Red Hat Inc.
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

# Common logic for generating translated documentation.

include $(top_srcdir)/subdir-rules.mk

LINGUA = $(shell basename -- `pwd`)

CLEANFILES = *.1 *.3 *.5

# Before 1.23.23, the old Perl tools were called *.pl.
CLEANFILES += *.pl

MANPAGES = \
	guestfish.1 \
	guestfs.3 \
	guestfs-erlang.3 \
	guestfs-examples.3 \
	guestfs-faq.1 \
	guestfs-hacking.1 \
	guestfs-internals.1 \
	guestfs-golang.3 \
	guestfs-java.3 \
	guestfs-lua.3 \
	guestfs-ocaml.3 \
	guestfs-performance.1 \
	guestfs-perl.3 \
	guestfs-python.3 \
	guestfs-recipes.1 \
	guestfs-release-notes.1 \
	guestfs-ruby.3 \
	guestfs-security.1 \
	guestfs-testing.1 \
	guestfsd.8 \
	guestmount.1 \
	guestunmount.1 \
	libguestfs-make-fixed-appliance.1 \
	libguestfs-test-tool.1 \
	libguestfs-tools.conf.5 \
	virt-alignment-scan.1 \
	virt-builder.1 \
	virt-cat.1 \
	virt-copy-in.1 \
	virt-copy-out.1 \
	virt-customize.1 \
	virt-df.1 \
	virt-dib.1 \
	virt-diff.1 \
	virt-edit.1 \
	virt-filesystems.1 \
	virt-format.1 \
	virt-get-kernel.1 \
	virt-index-validate.1 \
	virt-inspector.1 \
	virt-list-filesystems.1 \
	virt-list-partitions.1 \
	virt-log.1 \
	virt-ls.1 \
	virt-make-fs.1 \
	virt-p2v.1 \
	virt-p2v-make-disk.1 \
	virt-p2v-make-kickstart.1 \
	virt-rescue.1 \
	virt-resize.1 \
	virt-sparsify.1 \
	virt-sysprep.1 \
	virt-tar.1 \
	virt-tar-in.1 \
	virt-tar-out.1 \
	virt-v2v.1 \
	virt-v2v-test-harness.1 \
	virt-win-reg.1

podfiles := $(shell for f in `cat $(top_srcdir)/po-docs/podfiles`; do echo `basename $$f .pod`.pod; done)

# Ship the POD files and the translated manpages in the tarball.  This
# just simplifies building from the tarball, at a small cost in extra
# size.
EXTRA_DIST = \
	$(MANPAGES) \
	$(podfiles)

all-local: $(MANPAGES)

guestfs.3: guestfs.pod guestfs-actions.pod guestfs-availability.pod guestfs-structs.pod
	$(PODWRAPPER) \
	  --no-strict-checks \
	  --man $@ \
	  --section 3 \
	  --license LGPLv2+ \
	  --insert $(srcdir)/guestfs-actions.pod:__ACTIONS__ \
	  --insert $(srcdir)/guestfs-availability.pod:__AVAILABILITY__ \
	  --insert $(srcdir)/guestfs-structs.pod:__STRUCTS__ \
	  $<

# XXX --warning parameter is not passed, so no WARNING section is
# generated in any translated manual.  To fix this we need to expand
# out all the %.1 pattern rules below.

guestfish.1: guestfish.pod guestfish-actions.pod guestfish-commands.pod guestfish-prepopts.pod
	$(PODWRAPPER) \
	  --no-strict-checks \
	  --man $@ \
	  --license GPLv2+ \
	  --insert $(srcdir)/guestfish-actions.pod:__ACTIONS__ \
	  --insert $(srcdir)/guestfish-commands.pod:__FISH_COMMANDS__ \
	  --insert $(srcdir)/guestfish-prepopts.pod:__PREPOPTS__ \
	  $<

virt-builder.1: virt-builder.pod customize-synopsis.pod customize-options.pod
	$(PODWRAPPER) \
	  --no-strict-checks \
	  --man $@ \
	  --license GPLv2+ \
	  --insert $(srcdir)/customize-synopsis.pod:__CUSTOMIZE_SYNOPSIS__ \
	  --insert $(srcdir)/customize-options.pod:__CUSTOMIZE_OPTIONS__ \
	  $<

virt-customize.1: virt-customize.pod customize-synopsis.pod customize-options.pod
	$(PODWRAPPER) \
	  --no-strict-checks \
	  --man $@ \
	  --license GPLv2+ \
	  --insert $(srcdir)/customize-synopsis.pod:__CUSTOMIZE_SYNOPSIS__ \
	  --insert $(srcdir)/customize-options.pod:__CUSTOMIZE_OPTIONS__ \
	  $<

virt-sysprep.1: virt-sysprep.pod sysprep-extra-options.pod sysprep-operations.pod
	$(PODWRAPPER) \
	  --no-strict-checks \
	  --man $@ \
	  --license GPLv2+ \
          --insert $(srcdir)/sysprep-extra-options.pod:__EXTRA_OPTIONS__ \
          --insert $(srcdir)/sysprep-operations.pod:__OPERATIONS__ \
	  $<

%.1: %.pod
	$(PODWRAPPER) \
	  --no-strict-checks \
	  --man $@ \
	  $<

%.3: %.pod
	$(PODWRAPPER) \
	  --no-strict-checks \
	  --man $@ \
	  --section 3 \
	  $<

%.5: %.pod
	$(PODWRAPPER) \
	  --no-strict-checks \
	  --man $@ \
	  --section 5 \
	  $<

%.8: %.pod
	$(PODWRAPPER) \
	  --no-strict-checks \
	  --man $@ \
	  --section 8 \
	  $<

# If a POD file is missing, the user needs to run make update-po.
# This cannot be done automatically by make because it would be unsafe
# to run po4a or update podfiles potentially in parallel.  Therefore
# tell the user what to do and stop.
$(podfiles):
	@if ! test -f $@; then \
	  echo "***"; \
	  echo "*** You need to run the following commands:"; \
	  echo "***     rm po-docs/podfiles; make -C po-docs update-po"; \
	  echo "*** After that, rerun make."; \
	  echo "***"; \
	  exit 1; \
	fi

# XXX Can automake do this properly?
install-data-hook:
	$(MKDIR_P) $(DESTDIR)$(mandir)/$(LINGUA)/man1
	$(INSTALL) -m 0644 $(srcdir)/*.1 $(DESTDIR)$(mandir)/$(LINGUA)/man1
	$(MKDIR_P) $(DESTDIR)$(mandir)/$(LINGUA)/man3
	$(INSTALL) -m 0644 $(srcdir)/*.3 $(DESTDIR)$(mandir)/$(LINGUA)/man3
	$(MKDIR_P) $(DESTDIR)$(mandir)/$(LINGUA)/man5
	$(INSTALL) -m 0644 $(srcdir)/*.5 $(DESTDIR)$(mandir)/$(LINGUA)/man5
