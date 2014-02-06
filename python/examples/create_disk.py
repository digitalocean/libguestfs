# Example showing how to create a disk image.

import guestfs

output = "disk.img"

# All new Python code should pass python_return_dict=True
# to the constructor.  It indicates that your program wants
# to receive Python dicts for methods in the API that return
# hashtables.
g = guestfs.GuestFS (python_return_dict=True)

# Create a raw-format sparse disk image, 512 MB in size.
g.disk_create (output, "raw", 512 * 1024 * 1024);

# Set the trace flag so that we can see each libguestfs call.
g.set_trace (1)

# Attach the disk image to libguestfs.
g.add_drive_opts (output, format = "raw", readonly = 0)

# Run the libguestfs back-end.
g.launch ()

# Get the list of devices.  Because we only added one drive
# above, we expect that this list should contain a single
# element.
devices = g.list_devices ()
assert (len (devices) == 1)

# Partition the disk as one single MBR partition.
g.part_disk (devices[0], "mbr")

# Get the list of partitions.  We expect a single element, which
# is the partition we have just created.
partitions = g.list_partitions ()
assert (len (partitions) == 1)

# Create a filesystem on the partition.
g.mkfs ("ext4", partitions[0])

# Now mount the filesystem so that we can add files.
g.mount (partitions[0], "/")

# Create some files and directories.
g.touch ("/empty")
message = "Hello, world\n"
g.write ("/hello", message)
g.mkdir ("/foo")

# This one uploads the local file /etc/resolv.conf into
# the disk image.
g.upload ("/etc/resolv.conf", "/foo/resolv.conf")

# Because we wrote to the disk and we want to detect write
# errors, call g.shutdown.  You don't need to do this:
# g.close will do it implicitly.
g.shutdown ()

# Note also that handles are automatically closed if they are
# reaped by reference counting.  You only need to call close
# if you want to close the handle right away.
g.close ()
