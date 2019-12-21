#!/bin/sh

rm -f \
	common/mlstdutils/guestfs_config.ml \
	daemon/daemon_config.ml \
	v2v/config.ml
autoreconf -f -i
