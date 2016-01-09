/* libguestfs - the guestfsd daemon
 * Copyright (C) 2009-2016 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "guestfs_protocol.h"
#include "daemon.h"
#include "actions.h"

GUESTFSD_EXT_CMD(str_find, find);
GUESTFSD_EXT_CMD(str_xargs, xargs);
GUESTFSD_EXT_CMD(str_cksum, cksum);
GUESTFSD_EXT_CMD(str_md5sum, md5sum);
GUESTFSD_EXT_CMD(str_sha1sum, sha1sum);
GUESTFSD_EXT_CMD(str_sha224sum, sha224sum);
GUESTFSD_EXT_CMD(str_sha256sum, sha256sum);
GUESTFSD_EXT_CMD(str_sha384sum, sha384sum);
GUESTFSD_EXT_CMD(str_sha512sum, sha512sum);

static const char *
program_of_csum (const char *csumtype)
{
  if (STRCASEEQ (csumtype, "crc"))
    return str_cksum;
  else if (STRCASEEQ (csumtype, "md5"))
    return str_md5sum;
  else if (STRCASEEQ (csumtype, "sha1"))
    return str_sha1sum;
  else if (STRCASEEQ (csumtype, "sha224"))
    return str_sha224sum;
  else if (STRCASEEQ (csumtype, "sha256"))
    return str_sha256sum;
  else if (STRCASEEQ (csumtype, "sha384"))
    return str_sha384sum;
  else if (STRCASEEQ (csumtype, "sha512"))
    return str_sha512sum;
  else {
    reply_with_error ("unknown checksum type, expecting crc|md5|sha1|sha224|sha256|sha384|sha512");
    return NULL;
  }
}

static char *
checksum (const char *csumtype, int fd)
{
  const char *program;
  char *out;
  CLEANUP_FREE char *err = NULL;
  int flags, r;
  size_t len;

  program = program_of_csum (csumtype);
  if (program == NULL)
    return NULL;

  pulse_mode_start ();

  flags = COMMAND_FLAG_CHROOT_COPY_FILE_TO_STDIN | fd;
  r = commandf (&out, &err, flags, program, NULL);
  if (r == -1) {
    pulse_mode_cancel ();
    reply_with_error ("%s: %s", program, err);
    free (out);
    return NULL;
  }

  /* Split it at the first whitespace. */
  len = strcspn (out, " \t\n");
  out[len] = '\0';

  pulse_mode_end ();

  return out;			/* Caller frees. */
}

char *
do_checksum (const char *csumtype, const char *path)
{
  CLEANUP_CLOSE int fd = -1;

  CHROOT_IN;
  fd = open (path, O_RDONLY|O_CLOEXEC);
  CHROOT_OUT;

  if (fd == -1) {
    reply_with_perror ("%s", path);
    return NULL;
  }

  return checksum (csumtype, fd);
}

char *
do_checksum_device (const char *csumtype, const char *device)
{
  CLEANUP_CLOSE int fd = -1;

  fd = open (device, O_RDONLY|O_CLOEXEC);
  if (fd == -1) {
    reply_with_perror ("%s", device);
    return NULL;
  }

  return checksum (csumtype, fd);
}

/* Has one FileOut parameter. */
int
do_checksums_out (const char *csumtype, const char *dir)
{
  struct stat statbuf;
  int r;

  const char *program = program_of_csum (csumtype);
  if (program == NULL)
    return -1;

  CLEANUP_FREE char *sysrootdir = sysroot_path (dir);
  if (!sysrootdir) {
    reply_with_perror ("malloc");
    return -1;
  }

  r = stat (sysrootdir, &statbuf);
  if (r == -1) {
    reply_with_perror ("%s", dir);
    return -1;
  }
  if (!S_ISDIR (statbuf.st_mode)) {
    reply_with_error ("%s: not a directory", dir);
    return -1;
  }

  CLEANUP_FREE char *cmd = NULL;
  if (asprintf_nowarn (&cmd, "cd %Q && %s -type f -print0 | %s -0 %s",
                       sysrootdir, str_find, str_xargs, program) == -1) {
    reply_with_perror ("asprintf");
    return -1;
  }

  if (verbose)
    fprintf (stderr, "%s\n", cmd);

  FILE *fp = popen (cmd, "r");
  if (fp == NULL) {
    reply_with_perror ("%s", cmd);
    return -1;
  }

  /* Now we must send the reply message, before the file contents.  After
   * this there is no opportunity in the protocol to send any error
   * message back.  Instead we can only cancel the transfer.
   */
  reply (NULL, NULL);

  char str[GUESTFS_MAX_CHUNK_SIZE];

  while ((r = fread (str, 1, GUESTFS_MAX_CHUNK_SIZE, fp)) > 0) {
    if (send_file_write (str, r) < 0) {
      pclose (fp);
      return -1;
    }
  }

  if (ferror (fp)) {
    fprintf (stderr, "fread: %s: %m\n", dir);
    send_file_end (1);                /* Cancel. */
    pclose (fp);
    return -1;
  }

  if (pclose (fp) != 0) {
    fprintf (stderr, "pclose: %s: %m\n", dir);
    send_file_end (1);                /* Cancel. */
    return -1;
  }

  if (send_file_end (0))        /* Normal end of file. */
    return -1;

  return 0;
}
