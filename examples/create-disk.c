/* Example showing how to create a disk image. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <guestfs.h>

int
main (int argc, char *argv[])
{
  guestfs_h *g;
  size_t i;

  g = guestfs_create ();
  if (g == NULL) {
    perror ("failed to create libguestfs handle");
    exit (EXIT_FAILURE);
  }

  /* Set the trace flag so that we can see each libguestfs call. */
  guestfs_set_trace (g, 1);

  /* Create a raw-format sparse disk image, 512 MB in size. */
  if (guestfs_disk_create (g, "disk.img", "raw", UINT64_C(512)*1024*1024,
                           -1) == -1)
    exit (EXIT_FAILURE);

  /* Add the disk image to libguestfs. */
  if (guestfs_add_drive_opts (g, "disk.img",
        GUESTFS_ADD_DRIVE_OPTS_FORMAT, "raw", /* raw format */
        GUESTFS_ADD_DRIVE_OPTS_READONLY, 0, /* for write */
        -1) /* this marks end of optional arguments */
      == -1)
    exit (EXIT_FAILURE);

  /* Run the libguestfs back-end. */
  if (guestfs_launch (g) == -1)
    exit (EXIT_FAILURE);

  /* Get the list of devices.  Because we only added one drive
   * above, we expect that this list should contain a single
   * element.
   */
  char **devices = guestfs_list_devices (g);
  if (devices == NULL)
    exit (EXIT_FAILURE);
  if (devices[0] == NULL || devices[1] != NULL) {
    fprintf (stderr, "error: expected a single device from list-devices\n");
    exit (EXIT_FAILURE);
  }

  /* Partition the disk as one single MBR partition. */
  if (guestfs_part_disk (g, devices[0], "mbr") == -1)
    exit (EXIT_FAILURE);

  /* Get the list of partitions.  We expect a single element, which
   * is the partition we have just created.
   */
  char **partitions = guestfs_list_partitions (g);
  if (partitions == NULL)
    exit (EXIT_FAILURE);
  if (partitions[0] == NULL || partitions[1] != NULL) {
    fprintf (stderr, "error: expected a single partition from list-partitions\n");
    exit (EXIT_FAILURE);
  }

  /* Create a filesystem on the partition. */
  if (guestfs_mkfs (g, "ext4", partitions[0]) == -1)
    exit (EXIT_FAILURE);

  /* Now mount the filesystem so that we can add files. */
  if (guestfs_mount (g, partitions[0], "/") == -1)
    exit (EXIT_FAILURE);

  /* Create some files and directories. */
  if (guestfs_touch (g, "/empty") == -1)
    exit (EXIT_FAILURE);
  const char *message = "Hello, world\n";
  if (guestfs_write (g, "/hello", message, strlen (message)) == -1)
    exit (EXIT_FAILURE);
  if (guestfs_mkdir (g, "/foo") == -1)
    exit (EXIT_FAILURE);

  /* This one uploads the local file /etc/resolv.conf into
   * the disk image.
   */
  if (guestfs_upload (g, "/etc/resolv.conf", "/foo/resolv.conf") == -1)
    exit (EXIT_FAILURE);

  /* Because we wrote to the disk and we want to detect write
   * errors, call guestfs_shutdown.  You don't need to do this:
   * guestfs_close will do it implicitly.
   */
  if (guestfs_shutdown (g) == -1)
    exit (EXIT_FAILURE);

  guestfs_close (g);

  /* Free up the lists. */
  for (i = 0; devices[i] != NULL; ++i)
    free (devices[i]);
  free (devices);
  for (i = 0; partitions[i] != NULL; ++i)
    free (partitions[i]);
  free (partitions);

  exit (EXIT_SUCCESS);
}
