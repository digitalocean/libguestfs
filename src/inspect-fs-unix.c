/* libguestfs
 * Copyright (C) 2010-2012 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#ifdef HAVE_ENDIAN_H
#include <endian.h>
#endif

#include <pcre.h>

#include "c-ctype.h"
#include "ignore-value.h"
#include "xstrtol.h"
#include "hash.h"
#include "hash-pjw.h"

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"
#include "guestfs_protocol.h"

/* Compile all the regular expressions once when the shared library is
 * loaded.  PCRE is thread safe so we're supposedly OK here if
 * multiple threads call into the libguestfs API functions below
 * simultaneously.
 */
static pcre *re_fedora;
static pcre *re_rhel_old;
static pcre *re_rhel;
static pcre *re_rhel_no_minor;
static pcre *re_centos_old;
static pcre *re_centos;
static pcre *re_centos_no_minor;
static pcre *re_scientific_linux_old;
static pcre *re_scientific_linux;
static pcre *re_scientific_linux_no_minor;
static pcre *re_oracle_linux_old;
static pcre *re_oracle_linux;
static pcre *re_oracle_linux_no_minor;
static pcre *re_major_minor;
static pcre *re_xdev;
static pcre *re_cciss;
static pcre *re_mdN;
static pcre *re_freebsd_mbr;
static pcre *re_freebsd_gpt;
static pcre *re_diskbyid;
static pcre *re_netbsd;
static pcre *re_opensuse;
static pcre *re_sles;
static pcre *re_nld;
static pcre *re_opensuse_version;
static pcre *re_sles_version;
static pcre *re_sles_patchlevel;
static pcre *re_minix;
static pcre *re_hurd_dev;

static void compile_regexps (void) __attribute__((constructor));
static void free_regexps (void) __attribute__((destructor));

static void
compile_regexps (void)
{
  const char *err;
  int offset;

#define COMPILE(re,pattern,options)                                     \
  do {                                                                  \
    re = pcre_compile ((pattern), (options), &err, &offset, NULL);      \
    if (re == NULL) {                                                   \
      ignore_value (write (2, err, strlen (err)));                      \
      abort ();                                                         \
    }                                                                   \
  } while (0)

  COMPILE (re_fedora, "Fedora release (\\d+)", 0);
  COMPILE (re_rhel_old,
           "Red Hat.*release (\\d+).*Update (\\d+)", 0);
  COMPILE (re_rhel,
           "Red Hat.*release (\\d+)\\.(\\d+)", 0);
  COMPILE (re_rhel_no_minor,
           "Red Hat.*release (\\d+)", 0);
  COMPILE (re_centos_old,
           "CentOS.*release (\\d+).*Update (\\d+)", 0);
  COMPILE (re_centos,
           "CentOS.*release (\\d+)\\.(\\d+)", 0);
  COMPILE (re_centos_no_minor,
           "CentOS.*release (\\d+)", 0);
  COMPILE (re_scientific_linux_old,
           "Scientific Linux.*release (\\d+).*Update (\\d+)", 0);
  COMPILE (re_scientific_linux,
           "Scientific Linux.*release (\\d+)\\.(\\d+)", 0);
  COMPILE (re_scientific_linux_no_minor,
           "Scientific Linux.*release (\\d+)", 0);
  COMPILE (re_oracle_linux_old,
           "Oracle Linux.*release (\\d+).*Update (\\d+)", 0);
  COMPILE (re_oracle_linux,
           "Oracle Linux.*release (\\d+)\\.(\\d+)", 0);
  COMPILE (re_oracle_linux_no_minor,
           "Oracle Linux.*release (\\d+)", 0);
  COMPILE (re_major_minor, "(\\d+)\\.(\\d+)", 0);
  COMPILE (re_xdev, "^/dev/(h|s|v|xv)d([a-z]+)(\\d*)$", 0);
  COMPILE (re_cciss, "^/dev/(cciss/c\\d+d\\d+)(?:p(\\d+))?$", 0);
  COMPILE (re_mdN, "^(/dev/md\\d+)$", 0);
  COMPILE (re_freebsd_mbr, "^/dev/(ada{0,1}|vtbd)(\\d+)s(\\d+)([a-z])$", 0);
  COMPILE (re_freebsd_gpt, "^/dev/(ada{0,1}|vtbd)(\\d+)p(\\d+)$", 0);
  COMPILE (re_diskbyid, "^/dev/disk/by-id/.*-part(\\d+)$", 0);
  COMPILE (re_netbsd, "^NetBSD (\\d+)\\.(\\d+)", 0);
  COMPILE (re_opensuse, "^(openSUSE|SuSE Linux|SUSE LINUX) ", 0);
  COMPILE (re_sles, "^SUSE (Linux|LINUX) Enterprise ", 0);
  COMPILE (re_nld, "^Novell Linux Desktop ", 0);
  COMPILE (re_opensuse_version, "^VERSION = (\\d+)\\.(\\d+)", 0);
  COMPILE (re_sles_version, "^VERSION = (\\d+)", 0);
  COMPILE (re_sles_patchlevel, "^PATCHLEVEL = (\\d+)", 0);
  COMPILE (re_minix, "^(\\d+)\\.(\\d+)(\\.(\\d+))?", 0);
  COMPILE (re_hurd_dev, "^/dev/(h)d(\\d+)s(\\d+)$", 0);
}

static void
free_regexps (void)
{
  pcre_free (re_fedora);
  pcre_free (re_rhel_old);
  pcre_free (re_rhel);
  pcre_free (re_rhel_no_minor);
  pcre_free (re_centos_old);
  pcre_free (re_centos);
  pcre_free (re_centos_no_minor);
  pcre_free (re_scientific_linux_old);
  pcre_free (re_scientific_linux);
  pcre_free (re_scientific_linux_no_minor);
  pcre_free (re_oracle_linux_old);
  pcre_free (re_oracle_linux);
  pcre_free (re_oracle_linux_no_minor);
  pcre_free (re_major_minor);
  pcre_free (re_xdev);
  pcre_free (re_cciss);
  pcre_free (re_mdN);
  pcre_free (re_freebsd_mbr);
  pcre_free (re_freebsd_gpt);
  pcre_free (re_diskbyid);
  pcre_free (re_netbsd);
  pcre_free (re_opensuse);
  pcre_free (re_sles);
  pcre_free (re_nld);
  pcre_free (re_opensuse_version);
  pcre_free (re_sles_version);
  pcre_free (re_sles_patchlevel);
  pcre_free (re_minix);
  pcre_free (re_hurd_dev);
}

static void check_architecture (guestfs_h *g, struct inspect_fs *fs);
static int check_hostname_unix (guestfs_h *g, struct inspect_fs *fs);
static int check_hostname_redhat (guestfs_h *g, struct inspect_fs *fs);
static int check_hostname_freebsd (guestfs_h *g, struct inspect_fs *fs);
static int check_fstab (guestfs_h *g, struct inspect_fs *fs);
static int add_fstab_entry (guestfs_h *g, struct inspect_fs *fs,
                            const char *mountable, const char *mp);
static char *resolve_fstab_device (guestfs_h *g, const char *spec,
                                   Hash_table *md_map);
static int inspect_with_augeas (guestfs_h *g, struct inspect_fs *fs, const char **configfiles, int (*f) (guestfs_h *, struct inspect_fs *));
static int is_partition (guestfs_h *g, const char *partition);

/* Hash structure for uuid->path lookups */
typedef struct md_uuid {
  uint32_t uuid[4];
  char *path;
} md_uuid;

static size_t uuid_hash(const void *x, size_t table_size);
static bool uuid_cmp(const void *x, const void *y);
static void md_uuid_free(void *x);

static int parse_uuid(const char *str, uint32_t *uuid);

/* Hash structure for path(mdadm)->path(appliance) lookup */
typedef struct {
  char *mdadm;
  char *app;
} mdadm_app;

static size_t mdadm_app_hash(const void *x, size_t table_size);
static bool mdadm_app_cmp(const void *x, const void *y);
static void mdadm_app_free(void *x);

static ssize_t map_app_md_devices (guestfs_h *g, Hash_table **map);
static int map_md_devices(guestfs_h *g, Hash_table **map);

/* Set fs->product_name to the first line of the release file. */
static int
parse_release_file (guestfs_h *g, struct inspect_fs *fs,
                    const char *release_filename)
{
  fs->product_name = guestfs___first_line_of_file (g, release_filename);
  if (fs->product_name == NULL)
    return -1;
  if (STREQ (fs->product_name, "")) {
    free (fs->product_name);
    fs->product_name = NULL;
    error (g, _("release file %s is empty or malformed"), release_filename);
    return -1;
  }
  return 0;
}

/* Ubuntu has /etc/lsb-release containing:
 *   DISTRIB_ID=Ubuntu                                # Distro
 *   DISTRIB_RELEASE=10.04                            # Version
 *   DISTRIB_CODENAME=lucid
 *   DISTRIB_DESCRIPTION="Ubuntu 10.04.1 LTS"         # Product name
 *
 * [Ubuntu-derived ...] Linux Mint was found to have this:
 *   DISTRIB_ID=LinuxMint
 *   DISTRIB_RELEASE=10
 *   DISTRIB_CODENAME=julia
 *   DISTRIB_DESCRIPTION="Linux Mint 10 Julia"
 * Linux Mint also has /etc/linuxmint/info with more information,
 * but we can use the LSB file.
 *
 * Mandriva has:
 *   LSB_VERSION=lsb-4.0-amd64:lsb-4.0-noarch
 *   DISTRIB_ID=MandrivaLinux
 *   DISTRIB_RELEASE=2010.1
 *   DISTRIB_CODENAME=Henry_Farman
 *   DISTRIB_DESCRIPTION="Mandriva Linux 2010.1"
 * Mandriva also has a normal release file called /etc/mandriva-release.
 */
static int
parse_lsb_release (guestfs_h *g, struct inspect_fs *fs)
{
  const char *filename = "/etc/lsb-release";
  int64_t size;
  CLEANUP_FREE_STRING_LIST char **lines = NULL;
  size_t i;
  int r = 0;

  /* Don't trust guestfs_head_n not to break with very large files.
   * Check the file size is something reasonable first.
   */
  size = guestfs_filesize (g, filename);
  if (size == -1)
    /* guestfs_filesize failed and has already set error in handle */
    return -1;
  if (size > MAX_SMALL_FILE_SIZE) {
    error (g, _("size of %s is unreasonably large (%" PRIi64 " bytes)"),
           filename, size);
    return -1;
  }

  lines = guestfs_head_n (g, 10, filename);
  if (lines == NULL)
    return -1;

  for (i = 0; lines[i] != NULL; ++i) {
    if (fs->distro == 0 &&
        STREQ (lines[i], "DISTRIB_ID=Ubuntu")) {
      fs->distro = OS_DISTRO_UBUNTU;
      r = 1;
    }
    else if (fs->distro == 0 &&
             STREQ (lines[i], "DISTRIB_ID=LinuxMint")) {
      fs->distro = OS_DISTRO_LINUX_MINT;
      r = 1;
    }
    else if (fs->distro == 0 &&
             STREQ (lines[i], "DISTRIB_ID=MandrivaLinux")) {
      fs->distro = OS_DISTRO_MANDRIVA;
      r = 1;
    }
    else if (fs->distro == 0 &&
             STREQ (lines[i], "DISTRIB_ID=\"Mageia\"")) {
      fs->distro = OS_DISTRO_MAGEIA;
      r = 1;
    }
    else if (STRPREFIX (lines[i], "DISTRIB_RELEASE=")) {
      char *major, *minor;
      if (match2 (g, &lines[i][16], re_major_minor, &major, &minor)) {
        fs->major_version = guestfs___parse_unsigned_int (g, major);
        free (major);
        if (fs->major_version == -1) {
          free (minor);
          return -1;
        }
        fs->minor_version = guestfs___parse_unsigned_int (g, minor);
        free (minor);
        if (fs->minor_version == -1)
          return -1;
      }
    }
    else if (fs->product_name == NULL &&
             (STRPREFIX (lines[i], "DISTRIB_DESCRIPTION=\"") ||
              STRPREFIX (lines[i], "DISTRIB_DESCRIPTION='"))) {
      size_t len = strlen (lines[i]) - 21 - 1;
      fs->product_name = safe_strndup (g, &lines[i][21], len);
      r = 1;
    }
    else if (fs->product_name == NULL &&
             STRPREFIX (lines[i], "DISTRIB_DESCRIPTION=")) {
      size_t len = strlen (lines[i]) - 20;
      fs->product_name = safe_strndup (g, &lines[i][20], len);
      r = 1;
    }
  }

  /* The unnecessary construct in the next line is required to
   * workaround -Wstrict-overflow warning in gcc 4.5.1.
   */
  return r ? 1 : 0;
}

static int
parse_suse_release (guestfs_h *g, struct inspect_fs *fs, const char *filename)
{
  int64_t size;
  char *major, *minor;
  CLEANUP_FREE_STRING_LIST char **lines = NULL;
  int r = -1;

  /* Don't trust guestfs_head_n not to break with very large files.
   * Check the file size is something reasonable first.
   */
  size = guestfs_filesize (g, filename);
  if (size == -1)
    /* guestfs_filesize failed and has already set error in handle */
    return -1;
  if (size > MAX_SMALL_FILE_SIZE) {
    error (g, _("size of %s is unreasonably large (%" PRIi64 " bytes)"),
           filename, size);
    return -1;
  }

  lines = guestfs_head_n (g, 10, filename);
  if (lines == NULL)
    return -1;

  if (lines[0] == NULL)
    goto out;

  /* First line is dist release name */
  fs->product_name = safe_strdup (g, lines[0]);

  /* Match SLES first because openSuSE regex overlaps some SLES release strings */
  if (match (g, fs->product_name, re_sles) || match (g, fs->product_name, re_nld)) {
    fs->distro = OS_DISTRO_SLES;

    /* Second line contains version string */
    if (lines[1] == NULL)
      goto out;
    major = match1 (g, lines[1], re_sles_version);
    if (major == NULL)
      goto out;
    fs->major_version = guestfs___parse_unsigned_int (g, major);
    free (major);
    if (fs->major_version == -1)
      goto out;

    /* Third line contains service pack string */
    if (lines[2] == NULL)
      goto out;
    minor = match1 (g, lines[2], re_sles_patchlevel);
    if (minor == NULL)
      goto out;
    fs->minor_version = guestfs___parse_unsigned_int (g, minor);
    free (minor);
    if (fs->minor_version == -1)
      goto out;
  }
  else if (match (g, fs->product_name, re_opensuse)) {
    fs->distro = OS_DISTRO_OPENSUSE;

    /* Second line contains version string */
    if (lines[1] == NULL)
      goto out;
    if (match2 (g, lines[1], re_opensuse_version, &major, &minor)) {
      fs->major_version = guestfs___parse_unsigned_int (g, major);
      fs->minor_version = guestfs___parse_unsigned_int (g, minor);
      free (major);
      free (minor);
      if (fs->major_version == -1 || fs->minor_version == -1)
        goto out;
    }
  }

  r = 0;

out:
  return r;
}

/* The currently mounted device is known to be a Linux root.  Try to
 * determine from this the distro, version, etc.  Also parse
 * /etc/fstab to determine the arrangement of mountpoints and
 * associated devices.
 */
int
guestfs___check_linux_root (guestfs_h *g, struct inspect_fs *fs)
{
  int r;
  char *major, *minor;

  fs->type = OS_TYPE_LINUX;

  if (guestfs_is_file_opts (g, "/etc/lsb-release",
                            GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    r = parse_lsb_release (g, fs);
    if (r == -1)        /* error */
      return -1;
    if (r == 1)         /* ok - detected the release from this file */
      goto skip_release_checks;
  }

  /* Oracle Linux includes a "/etc/redhat-release" file, hence the Oracle check
   * needs to be performed before the Red-Hat one.
   */
  if (guestfs_is_file_opts (g, "/etc/oracle-release",
                            GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {

    fs->distro = OS_DISTRO_ORACLE_LINUX;

    if (parse_release_file (g, fs, "/etc/oracle-release") == -1)
      return -1;

    if (match2 (g, fs->product_name, re_oracle_linux_old, &major, &minor) ||
        match2 (g, fs->product_name, re_oracle_linux, &major, &minor)) {
      fs->major_version = guestfs___parse_unsigned_int (g, major);
      free (major);
      if (fs->major_version == -1) {
        free (minor);
        return -1;
      }
      fs->minor_version = guestfs___parse_unsigned_int (g, minor);
      free (minor);
      if (fs->minor_version == -1)
        return -1;
    } else if ((major = match1 (g, fs->product_name, re_oracle_linux_no_minor)) != NULL) {
      fs->major_version = guestfs___parse_unsigned_int (g, major);
      free (major);
      if (fs->major_version == -1)
        return -1;
      fs->minor_version = 0;
    }
  }
  else if (guestfs_is_file_opts (g, "/etc/redhat-release",
                                 GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    fs->distro = OS_DISTRO_REDHAT_BASED; /* Something generic Red Hat-like. */

    if (parse_release_file (g, fs, "/etc/redhat-release") == -1)
      return -1;

    if ((major = match1 (g, fs->product_name, re_fedora)) != NULL) {
      fs->distro = OS_DISTRO_FEDORA;
      fs->major_version = guestfs___parse_unsigned_int (g, major);
      free (major);
      if (fs->major_version == -1)
        return -1;
    }
    else if (match2 (g, fs->product_name, re_rhel_old, &major, &minor) ||
             match2 (g, fs->product_name, re_rhel, &major, &minor)) {
      fs->distro = OS_DISTRO_RHEL;
      fs->major_version = guestfs___parse_unsigned_int (g, major);
      free (major);
      if (fs->major_version == -1) {
        free (minor);
        return -1;
      }
      fs->minor_version = guestfs___parse_unsigned_int (g, minor);
      free (minor);
      if (fs->minor_version == -1)
        return -1;
    }
    else if ((major = match1 (g, fs->product_name, re_rhel_no_minor)) != NULL) {
      fs->distro = OS_DISTRO_RHEL;
      fs->major_version = guestfs___parse_unsigned_int (g, major);
      free (major);
      if (fs->major_version == -1)
        return -1;
      fs->minor_version = 0;
    }
    else if (match2 (g, fs->product_name, re_centos_old, &major, &minor) ||
             match2 (g, fs->product_name, re_centos, &major, &minor)) {
      fs->distro = OS_DISTRO_CENTOS;
      fs->major_version = guestfs___parse_unsigned_int (g, major);
      free (major);
      if (fs->major_version == -1) {
        free (minor);
        return -1;
      }
      fs->minor_version = guestfs___parse_unsigned_int (g, minor);
      free (minor);
      if (fs->minor_version == -1)
        return -1;
    }
    else if ((major = match1 (g, fs->product_name, re_centos_no_minor)) != NULL) {
      fs->distro = OS_DISTRO_CENTOS;
      fs->major_version = guestfs___parse_unsigned_int (g, major);
      free (major);
      if (fs->major_version == -1)
        return -1;
      fs->minor_version = 0;
    }
    else if (match2 (g, fs->product_name, re_scientific_linux_old, &major, &minor) ||
             match2 (g, fs->product_name, re_scientific_linux, &major, &minor)) {
      fs->distro = OS_DISTRO_SCIENTIFIC_LINUX;
      fs->major_version = guestfs___parse_unsigned_int (g, major);
      free (major);
      if (fs->major_version == -1) {
        free (minor);
        return -1;
      }
      fs->minor_version = guestfs___parse_unsigned_int (g, minor);
      free (minor);
      if (fs->minor_version == -1)
        return -1;
    }
    else if ((major = match1 (g, fs->product_name, re_scientific_linux_no_minor)) != NULL) {
      fs->distro = OS_DISTRO_SCIENTIFIC_LINUX;
      fs->major_version = guestfs___parse_unsigned_int (g, major);
      free (major);
      if (fs->major_version == -1)
        return -1;
      fs->minor_version = 0;
    }
  }
  else if (guestfs_is_file_opts (g, "/etc/debian_version",
                                 GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    fs->distro = OS_DISTRO_DEBIAN;

    if (parse_release_file (g, fs, "/etc/debian_version") == -1)
      return -1;

    if (guestfs___parse_major_minor (g, fs) == -1)
      return -1;
  }
  else if (guestfs_is_file_opts (g, "/etc/pardus-release",
                                 GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    fs->distro = OS_DISTRO_PARDUS;

    if (parse_release_file (g, fs, "/etc/pardus-release") == -1)
      return -1;

    if (guestfs___parse_major_minor (g, fs) == -1)
      return -1;
  }
  else if (guestfs_is_file_opts (g, "/etc/arch-release",
                                 GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    fs->distro = OS_DISTRO_ARCHLINUX;

    /* /etc/arch-release file is empty and I can't see a way to
     * determine the actual release or product string.
     */
  }
  else if (guestfs_is_file_opts (g, "/etc/gentoo-release",
                                 GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    fs->distro = OS_DISTRO_GENTOO;

    if (parse_release_file (g, fs, "/etc/gentoo-release") == -1)
      return -1;

    if (guestfs___parse_major_minor (g, fs) == -1)
      return -1;
  }
  else if (guestfs_is_file_opts (g, "/etc/meego-release",
                                 GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    fs->distro = OS_DISTRO_MEEGO;

    if (parse_release_file (g, fs, "/etc/meego-release") == -1)
      return -1;

    if (guestfs___parse_major_minor (g, fs) == -1)
      return -1;
  }
  else if (guestfs_is_file_opts (g, "/etc/slackware-version",
                                 GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    fs->distro = OS_DISTRO_SLACKWARE;

    if (parse_release_file (g, fs, "/etc/slackware-version") == -1)
      return -1;

    if (guestfs___parse_major_minor (g, fs) == -1)
      return -1;
  }
  else if (guestfs_is_file_opts (g, "/etc/ttylinux-target",
                                 GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    fs->distro = OS_DISTRO_TTYLINUX;

    if (parse_release_file (g, fs, "/etc/ttylinux-target") == -1)
      return -1;

    if (guestfs___parse_major_minor (g, fs) == -1)
      return -1;
  }
  else if (guestfs_is_file_opts (g, "/etc/SuSE-release",
                                 GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    fs->distro = OS_DISTRO_SUSE_BASED;

    if (parse_suse_release (g, fs, "/etc/SuSE-release") == -1)
      return -1;

  }
  /* CirrOS versions providing a own version file.
   */
  else if (guestfs_is_file_opts (g, "/etc/cirros/version",
                                 GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    fs->distro = OS_DISTRO_CIRROS;

    if (parse_release_file (g, fs, "/etc/cirros/version") == -1)
      return -1;

    if (guestfs___parse_major_minor (g, fs) == -1)
      return -1;
  }
  /* Buildroot (http://buildroot.net) is an embedded Linux distro
   * toolkit.  It is used by specific distros such as Cirros.
   */
  else if (guestfs_is_file_opts (g, "/etc/br-version",
                                 GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    if (guestfs_is_file_opts (g, "/usr/share/cirros/logo",
                              GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0)
      fs->distro = OS_DISTRO_CIRROS;
    else
      fs->distro = OS_DISTRO_BUILDROOT;

    /* /etc/br-version has the format YYYY.MM[-git/hg/svn release] */
    if (parse_release_file (g, fs, "/etc/br-version") == -1)
      return -1;

    if (guestfs___parse_major_minor (g, fs) == -1)
      return -1;
  }

 skip_release_checks:;

  /* Determine the architecture. */
  check_architecture (g, fs);

  /* We already know /etc/fstab exists because it's part of the test
   * for Linux root above.  We must now parse this file to determine
   * which filesystems are used by the operating system and how they
   * are mounted.
   */
  const char *configfiles[] = { "/etc/fstab", "/etc/mdadm.conf", NULL };
  if (inspect_with_augeas (g, fs, configfiles, check_fstab) == -1)
    return -1;

  /* Determine hostname. */
  if (check_hostname_unix (g, fs) == -1)
    return -1;

  return 0;
}

/* The currently mounted device is known to be a FreeBSD root. */
int
guestfs___check_freebsd_root (guestfs_h *g, struct inspect_fs *fs)
{
  fs->type = OS_TYPE_FREEBSD;

  /* FreeBSD has no authoritative version file.  The version number is
   * in /etc/motd, which the system administrator might edit, but
   * we'll use that anyway.
   */

  if (guestfs_is_file_opts (g, "/etc/motd",
                            GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    if (parse_release_file (g, fs, "/etc/motd") == -1)
      return -1;

    if (guestfs___parse_major_minor (g, fs) == -1)
      return -1;
  }

  /* Determine the architecture. */
  check_architecture (g, fs);

  /* We already know /etc/fstab exists because it's part of the test above. */
  const char *configfiles[] = { "/etc/fstab", NULL };
  if (inspect_with_augeas (g, fs, configfiles, check_fstab) == -1)
    return -1;

  /* Determine hostname. */
  if (check_hostname_unix (g, fs) == -1)
    return -1;

  return 0;
}

/* The currently mounted device is maybe to be a *BSD root. */
int
guestfs___check_netbsd_root (guestfs_h *g, struct inspect_fs *fs)
{

  if (guestfs_is_file_opts (g, "/etc/release",
                            GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    char *major, *minor;
    if (parse_release_file (g, fs, "/etc/release") == -1)
      return -1;

    if (match2 (g, fs->product_name, re_netbsd, &major, &minor)) {
      fs->type = OS_TYPE_NETBSD;
      fs->major_version = guestfs___parse_unsigned_int (g, major);
      free (major);
      if (fs->major_version == -1) {
        free (minor);
        return -1;
      }
      fs->minor_version = guestfs___parse_unsigned_int (g, minor);
      free (minor);
      if (fs->minor_version == -1)
        return -1;
    }
  } else {
    return -1;
  }

  /* Determine the architecture. */
  check_architecture (g, fs);

  /* We already know /etc/fstab exists because it's part of the test above. */
  const char *configfiles[] = { "/etc/fstab", NULL };
  if (inspect_with_augeas (g, fs, configfiles, check_fstab) == -1)
    return -1;

  /* Determine hostname. */
  if (check_hostname_unix (g, fs) == -1)
    return -1;

  return 0;
}

/* The currently mounted device may be a Hurd root.  Hurd has distros
 * just like Linux.
 */
int
guestfs___check_hurd_root (guestfs_h *g, struct inspect_fs *fs)
{
  fs->type = OS_TYPE_HURD;

  if (guestfs_is_file_opts (g, "/etc/debian_version",
                            GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    fs->distro = OS_DISTRO_DEBIAN;

    if (parse_release_file (g, fs, "/etc/debian_version") == -1)
      return -1;

    if (guestfs___parse_major_minor (g, fs) == -1)
      return -1;
  }

  /* Arch Hurd also exists, but inconveniently it doesn't have
   * the normal /etc/arch-release file.  XXX
   */

  /* Determine the architecture. */
  check_architecture (g, fs);

  if (guestfs_is_file (g, "/etc/fstab") > 0) {
    const char *configfiles[] = { "/etc/fstab", NULL };
    if (inspect_with_augeas (g, fs, configfiles, check_fstab) == -1)
      return -1;
  }

  /* Determine hostname. */
  if (check_hostname_unix (g, fs) == -1)
    return -1;

  return 0;
}

/* The currently mounted device is maybe to be a Minix root. */
int
guestfs___check_minix_root (guestfs_h *g, struct inspect_fs *fs)
{
  fs->type = OS_TYPE_MINIX;

  if (guestfs_is_file_opts (g, "/etc/version",
                            GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) > 0) {
    char *major, *minor;
    if (parse_release_file (g, fs, "/etc/version") == -1)
      return -1;

    if (match2 (g, fs->product_name, re_minix, &major, &minor)) {
      fs->major_version = guestfs___parse_unsigned_int (g, major);
      free (major);
      if (fs->major_version == -1) {
        free (minor);
        return -1;
      }
      fs->minor_version = guestfs___parse_unsigned_int (g, minor);
      free (minor);
      if (fs->minor_version == -1)
        return -1;
    }
  } else {
    return -1;
  }

  /* Determine the architecture. */
  check_architecture (g, fs);

  /* TODO: enable fstab inspection once resolve_fstab_device implements
   * the proper mapping from the Minix device names to the appliance names
   */

  /* Determine hostname. */
  if (check_hostname_unix (g, fs) == -1)
    return -1;

  return 0;
}

static void
check_architecture (guestfs_h *g, struct inspect_fs *fs)
{
  const char *binaries[] =
    { "/bin/bash", "/bin/ls", "/bin/echo", "/bin/rm", "/bin/sh" };
  size_t i;
  char *arch;

  for (i = 0; i < sizeof binaries / sizeof binaries[0]; ++i) {
    if (guestfs_is_file (g, binaries[i]) > 0) {
      /* Ignore errors from file_architecture call. */
      guestfs_push_error_handler (g, NULL, NULL);
      arch = guestfs_file_architecture (g, binaries[i]);
      guestfs_pop_error_handler (g);

      if (arch) {
        /* String will be owned by handle, freed by
         * guestfs___free_inspect_info.
         */
        fs->arch = arch;
        break;
      }
    }
  }
}

/* Try several methods to determine the hostname from a Linux or
 * FreeBSD guest.  Note that type and distro have been set, so we can
 * use that information to direct the search.
 */
static int
check_hostname_unix (guestfs_h *g, struct inspect_fs *fs)
{
  switch (fs->type) {
  case OS_TYPE_LINUX:
  case OS_TYPE_HURD:
    /* Red Hat-derived would be in /etc/sysconfig/network or
     * /etc/hostname (RHEL 7+, F18+).  Debian-derived in the file
     * /etc/hostname.  Very old Debian and SUSE use /etc/HOSTNAME.
     * It's best to just look for each of these files in turn, rather
     * than try anything clever based on distro.
     */
    if (guestfs_is_file (g, "/etc/HOSTNAME")) {
      fs->hostname = guestfs___first_line_of_file (g, "/etc/HOSTNAME");
      if (fs->hostname == NULL)
        return -1;
      if (STREQ (fs->hostname, "")) {
        free (fs->hostname);
        fs->hostname = NULL;
      }
    }

    if (!fs->hostname && guestfs_is_file (g, "/etc/hostname")) {
      fs->hostname = guestfs___first_line_of_file (g, "/etc/hostname");
      if (fs->hostname == NULL)
        return -1;
      if (STREQ (fs->hostname, "")) {
        free (fs->hostname);
        fs->hostname = NULL;
      }
    }

    if (!fs->hostname && guestfs_is_file (g, "/etc/sysconfig/network")) {
      const char *configfiles[] = { "/etc/sysconfig/network", NULL };
      if (inspect_with_augeas (g, fs, configfiles,
                               check_hostname_redhat) == -1)
        return -1;
    }
    break;

  case OS_TYPE_FREEBSD:
  case OS_TYPE_NETBSD:
    /* /etc/rc.conf contains the hostname, but there is no Augeas lens
     * for this file.
     */
    if (guestfs_is_file (g, "/etc/rc.conf")) {
      if (check_hostname_freebsd (g, fs) == -1)
        return -1;
    }
    break;

  case OS_TYPE_MINIX:
    if (guestfs_is_file (g, "/etc/hostname.file")) {
      fs->hostname = guestfs___first_line_of_file (g, "/etc/hostname.file");
      if (fs->hostname == NULL)
        return -1;
      if (STREQ (fs->hostname, "")) {
        free (fs->hostname);
        fs->hostname = NULL;
      }
    }
    break;

  case OS_TYPE_WINDOWS: /* not here, see check_windows_system_registry */
  case OS_TYPE_DOS:
  case OS_TYPE_OPENBSD:
  case OS_TYPE_UNKNOWN:
    /* nothing */;
  }

  return 0;
}

/* Parse the hostname from /etc/sysconfig/network.  This must be
 * called from the inspect_with_augeas wrapper.  Note that F18+ and
 * RHEL7+ use /etc/hostname just like Debian.
 */
static int
check_hostname_redhat (guestfs_h *g, struct inspect_fs *fs)
{
  char *hostname;

  /* Errors here are not fatal (RHBZ#726739), since it could be
   * just missing HOSTNAME field in the file.
   */
  guestfs_push_error_handler (g, NULL, NULL);
  hostname = guestfs_aug_get (g, "/files/etc/sysconfig/network/HOSTNAME");
  guestfs_pop_error_handler (g);

  /* This is freed by guestfs___free_inspect_info.  Note that hostname
   * could be NULL because we ignored errors above.
   */
  fs->hostname = hostname;
  return 0;
}

/* Parse the hostname from /etc/rc.conf.  On FreeBSD this file
 * contains comments, blank lines and:
 *   hostname="freebsd8.example.com"
 *   ifconfig_re0="DHCP"
 *   keymap="uk.iso"
 *   sshd_enable="YES"
 */
static int
check_hostname_freebsd (guestfs_h *g, struct inspect_fs *fs)
{
  const char *filename = "/etc/rc.conf";
  int64_t size;
  CLEANUP_FREE_STRING_LIST char **lines = NULL;
  size_t i;

  /* Don't trust guestfs_read_lines not to break with very large files.
   * Check the file size is something reasonable first.
   */
  size = guestfs_filesize (g, filename);
  if (size == -1)
    /* guestfs_filesize failed and has already set error in handle */
    return -1;
  if (size > MAX_SMALL_FILE_SIZE) {
    error (g, _("size of %s is unreasonably large (%" PRIi64 " bytes)"),
           filename, size);
    return -1;
  }

  lines = guestfs_read_lines (g, filename);
  if (lines == NULL)
    return -1;

  for (i = 0; lines[i] != NULL; ++i) {
    if (STRPREFIX (lines[i], "hostname=\"") ||
        STRPREFIX (lines[i], "hostname='")) {
      size_t len = strlen (lines[i]) - 10 - 1;
      fs->hostname = safe_strndup (g, &lines[i][10], len);
      break;
    } else if (STRPREFIX (lines[i], "hostname=")) {
      size_t len = strlen (lines[i]) - 9;
      fs->hostname = safe_strndup (g, &lines[i][9], len);
      break;
    }
  }

  return 0;
}

static int
check_fstab (guestfs_h *g, struct inspect_fs *fs)
{
  CLEANUP_FREE_STRING_LIST char **entries = NULL;
  char **entry;
  char augpath[256];
  CLEANUP_HASH_FREE Hash_table *md_map = NULL;

  /* Generate a map of MD device paths listed in /etc/mdadm.conf to MD device
   * paths in the guestfs appliance */
  if (map_md_devices (g, &md_map) == -1) return -1;

  entries = guestfs_aug_match (g, "/files/etc/fstab/*[label() != '#comment']");
  if (entries == NULL)
    return -1;

  for (entry = entries; *entry != NULL; entry++) {
    CLEANUP_FREE char *spec = NULL;
    CLEANUP_FREE char *mp = NULL;
    CLEANUP_FREE char *mountable = NULL;
    CLEANUP_FREE char *vfstype = NULL;

    snprintf (augpath, sizeof augpath, "%s/spec", *entry);
    spec = guestfs_aug_get (g, augpath);
    if (spec == NULL)
      return -1;

    /* Ignore /dev/fd (floppy disks) (RHBZ#642929) and CD-ROM drives.
     *
     * /dev/iso9660/FREEBSD_INSTALL can be found in FreeBSDs installation
     * discs.
     */
    if ((STRPREFIX (spec, "/dev/fd") && c_isdigit (spec[7])) ||
        STREQ (spec, "/dev/floppy") ||
        STREQ (spec, "/dev/cdrom") ||
        STRPREFIX (spec, "/dev/iso9660/"))
      continue;

    snprintf (augpath, sizeof augpath, "%s/file", *entry);
    mp = guestfs_aug_get (g, augpath);
    if (mp == NULL)
      return -1;

    /* Ignore certain mountpoints. */
    if (STRPREFIX (mp, "/dev/") ||
        STREQ (mp, "/dev") ||
        STRPREFIX (mp, "/media/") ||
        STRPREFIX (mp, "/proc/") ||
        STREQ (mp, "/proc") ||
        STRPREFIX (mp, "/selinux/") ||
        STREQ (mp, "/selinux") ||
        STRPREFIX (mp, "/sys/") ||
        STREQ (mp, "/sys"))
      continue;

    /* Resolve UUID= and LABEL= to the actual device. */
    if (STRPREFIX (spec, "UUID="))
      mountable = guestfs_findfs_uuid (g, &spec[5]);
    else if (STRPREFIX (spec, "LABEL="))
      mountable = guestfs_findfs_label (g, &spec[6]);
    /* Ignore "/.swap" (Pardus) and pseudo-devices like "tmpfs". */
    else if (STREQ (spec, "/dev/root"))
      /* Resolve /dev/root to the current device. */
      mountable = safe_strdup (g, fs->mountable);
    else if (STRPREFIX (spec, "/dev/"))
      /* Resolve guest block device names. */
      mountable = resolve_fstab_device (g, spec, md_map);

    /* If we haven't resolved the device successfully by this point,
     * we don't care, just ignore it.
     */
    if (mountable == NULL)
      continue;

    snprintf (augpath, sizeof augpath, "%s/vfstype", *entry);
    vfstype = guestfs_aug_get (g, augpath);
    if (vfstype == NULL) return -1;

    if (STREQ (vfstype, "btrfs")) {
      char **opt;

      snprintf (augpath, sizeof augpath, "%s/opt", *entry);
      CLEANUP_FREE_STRING_LIST char **opts = guestfs_aug_match (g, augpath);
      if (opts == NULL) return -1;

      for (opt = opts; *opt; opt++) {
        CLEANUP_FREE char *optname = guestfs_aug_get (g, augpath);
        if (optname == NULL) return -1;

        if (STREQ (optname, "subvol")) {
          CLEANUP_FREE char *subvol = NULL;
          char *new;

          snprintf (augpath, sizeof augpath, "%s/value", *opt);
          subvol = guestfs_aug_get (g, augpath);
          if (subvol == NULL) return -1;

          new = safe_asprintf (g, "btrfsvol:%s/%s", mountable, subvol);
          free (mountable);
          mountable = new;
        }
      }
    }

    if  (add_fstab_entry (g, fs, mountable, mp) == -1) return -1;
  }

  return 0;
}

/* Add a filesystem and possibly a mountpoint entry for
 * the root filesystem 'fs'.
 *
 * 'spec' is the fstab spec field, which might be a device name or a
 * pseudodevice or 'UUID=...' or 'LABEL=...'.
 *
 * 'mp' is the mount point, which could also be 'swap' or 'none'.
 */
static int
add_fstab_entry (guestfs_h *g, struct inspect_fs *fs,
                 const char *mountable, const char *mountpoint)
{
  /* Add this to the fstab entry in 'fs'.
   * Note these are further filtered by guestfs_inspect_get_mountpoints
   * and guestfs_inspect_get_filesystems.
   */
  size_t n = fs->nr_fstab + 1;
  struct inspect_fstab_entry *p;

  p = realloc (fs->fstab, n * sizeof (struct inspect_fstab_entry));
  if (p == NULL) {
    perrorf (g, "realloc");
    return -1;
  }

  fs->fstab = p;
  fs->nr_fstab = n;

  /* These are owned by the handle and freed by guestfs___free_inspect_info. */
  fs->fstab[n-1].mountable = safe_strdup (g, mountable);
  fs->fstab[n-1].mountpoint = safe_strdup (g, mountpoint);

  debug (g, "fstab: mountable=%s mountpoint=%s", mountable, mountpoint);

  return 0;
}

/* Compute a uuid hash as a simple xor of of its 4 32bit components */
static size_t
uuid_hash(const void *x, size_t table_size)
{
  const md_uuid *a = x;
  size_t h, i;

  h = a->uuid[0];
  for (i = 1; i < 4; i++) {
    h ^= a->uuid[i];
  }

  return h % table_size;
}

static bool
uuid_cmp(const void *x, const void *y)
{
  const md_uuid *a = x;
  const md_uuid *b = y;
  size_t i;

  for (i = 0; i < 1; i++) {
    if (a->uuid[i] != b->uuid[i]) return 0;
  }

  return 1;
}

static void
md_uuid_free(void *x)
{
  md_uuid *a = x;
  free(a->path);
  free(a);
}

/* Taken from parse_uuid in mdadm */
static int
parse_uuid (const char *str, uint32_t *uuid)
{
  size_t hit = 0; /* number of Hex digIT */
  char c;
  size_t i;
  int n;

  for (i = 0; i < 4; i++)
    uuid[i] = 0;

  while ((c = *str++)) {
    if (c >= '0' && c <= '9')
      n = c - '0';
    else if (c >= 'a' && c <= 'f')
      n = 10 + c - 'a';
    else if (c >= 'A' && c <= 'F')
      n = 10 + c - 'A';
    else if (strchr (":. -", c))
      continue;
    else
      return -1;

    if (hit < 32) {
      uuid[hit / 8] <<= 4;
      uuid[hit / 8] += n;
    }
    hit++;
  }
  if (hit == 32) return 0;

  return -1;
}

/* Create a mapping of uuids to appliance md device names */
static ssize_t
map_app_md_devices (guestfs_h *g, Hash_table **map)
{
  CLEANUP_FREE_STRING_LIST char **mds = NULL;
  size_t n = 0;
  char **md;

  /* A hash mapping uuids to md device names */
  *map = hash_initialize(16, NULL, uuid_hash, uuid_cmp, md_uuid_free);
  if (*map == NULL) g->abort_cb();

  mds = guestfs_list_md_devices(g);
  if (mds == NULL) goto error;

  for (md = mds; *md != NULL; md++) {
    char **i;
    CLEANUP_FREE_STRING_LIST char **detail = guestfs_md_detail (g, *md);
    if (detail == NULL) goto error;

    /* Iterate over keys until we find uuid */
    for (i = detail; *i != NULL; i += 2) {
      if (STREQ(*i, "uuid")) break;
    }

    /* We found it */
    if (*i) {
      md_uuid *entry;

      /* Next item is the uuid value */
      i++;

      entry = safe_malloc(g, sizeof(md_uuid));
      entry->path = safe_strdup(g, *md);

      if (parse_uuid(*i, entry->uuid) == -1) {
        /* Invalid UUID is weird, but not fatal. */
        debug(g, "inspect-os: guestfs_md_detail returned invalid "
                 "uuid for %s: %s", *md, *i);
        md_uuid_free(entry);
        continue;
      }

      const void *matched = NULL;
      switch (hash_insert_if_absent(*map, entry, &matched)) {
        case -1:
          g->abort_cb();

        case 0:
          /* Duplicate uuid in for md device is weird, but not fatal. */
          debug(g, "inspect-os: md devices %s and %s have the same uuid",
                ((md_uuid *)matched)->path, entry->path);
          md_uuid_free(entry);
          break;

        default:
          n++;
      }
    }
  }

  return n;

error:
  hash_free (*map); *map = NULL;

  return -1;
}

static size_t
mdadm_app_hash(const void *x, size_t table_size)
{
  const mdadm_app *a = x;
  return hash_pjw(a->mdadm, table_size);
}

static bool
mdadm_app_cmp(const void *x, const void *y)
{
  const mdadm_app *a = x;
  const mdadm_app *b = y;

  return STREQ (a->mdadm, b->mdadm);
}

static void
mdadm_app_free(void *x)
{
  mdadm_app *a = x;
  free(a->mdadm);
  free(a->app);
  free(a);
}

/* Get a map of md device names in mdadm.conf to their device names in the
 * appliance */
static int
map_md_devices(guestfs_h *g, Hash_table **map)
{
  CLEANUP_HASH_FREE Hash_table *app_map = NULL;
  CLEANUP_FREE_STRING_LIST char **matches = NULL;
  ssize_t n_app_md_devices;

  *map = NULL;

  /* Get a map of md device uuids to their device names in the appliance */
  n_app_md_devices = map_app_md_devices (g, &app_map);
  if (n_app_md_devices == -1) goto error;

  /* Nothing to do if there are no md devices */
  if (n_app_md_devices == 0)
    return 0;

  /* Get all arrays listed in mdadm.conf */
  matches = guestfs_aug_match(g, "/files/etc/mdadm.conf/array");
  if (!matches) goto error;

  /* Log a debug message if we've got md devices, but nothing in mdadm.conf */
  if (matches[0] == NULL) {
    debug(g, "Appliance has MD devices, but augeas returned no array matches "
             "in mdadm.conf");
    return 0;
  }

  *map = hash_initialize(16, NULL, mdadm_app_hash, mdadm_app_cmp,
                                   mdadm_app_free);
  if (!*map) g->abort_cb();

  for (char **m = matches; *m != NULL; m++) {
    /* Get device name and uuid for each array */
    CLEANUP_FREE char *dev_path = safe_asprintf (g, "%s/devicename", *m);
    char *dev = guestfs_aug_get (g, dev_path);
    if (!dev) goto error;

    CLEANUP_FREE char *uuid_path = safe_asprintf (g, "%s/uuid", *m);
    CLEANUP_FREE char *uuid = guestfs_aug_get (g, uuid_path);
    if (!uuid) {
      free (dev);
      continue;
    }

    /* Parse the uuid into an md_uuid structure so we can look it up in the
     * uuid->appliance device map */
    md_uuid mdadm;
    mdadm.path = dev;
    if (parse_uuid(uuid, mdadm.uuid) == -1) {
      /* Invalid uuid. Weird, but not fatal. */
      debug(g, "inspect-os: mdadm.conf contains invalid uuid for %s: %s",
            dev, uuid);
      free (dev);
      continue;
    }

    /* If there's a corresponding uuid in the appliance, create a new
     * entry in the transitive map */
    md_uuid *app = hash_lookup(app_map, &mdadm);
    if (app) {
      mdadm_app *entry = safe_malloc(g, sizeof(mdadm_app));
      entry->mdadm = dev;
      entry->app = safe_strdup(g, app->path);

      switch (hash_insert_if_absent(*map, entry, NULL)) {
        case -1:
          g->abort_cb();

        case 0:
          /* Duplicate uuid in for md device is weird, but not fatal. */
          debug(g, "inspect-os: mdadm.conf contains multiple entries for %s",
                app->path);
          mdadm_app_free(entry);
          continue;
      }
    } else
      free (dev);
  }

  return 0;

error:
  if (*map) hash_free (*map);

  return -1;
}

static int
resolve_fstab_device_xdev (guestfs_h *g, const char *type, const char *disk,
                           const char *part, char **device_ret)
{
  CLEANUP_FREE char *name = NULL;
  char *device;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
  size_t i, count;
  struct drive *drv;
  const char *p;

  /* type: (h|s|v|xv)
   * disk: ([a-z]+)
   * part: (\d*)
   */

  devices = guestfs_list_devices (g);
  if (devices == NULL)
    return -1;

  /* Check any hints we were passed for a non-heuristic mapping */
  name = safe_asprintf (g, "%sd%s", type, disk);
  ITER_DRIVES (g, i, drv) {
    if (drv->name && STREQ (drv->name, name)) {
      device = safe_asprintf (g, "%s%s", devices[i], part);
      if (!is_partition (g, device)) {
        free (device);
        return 0;
      }
      *device_ret = device;
      break;
    }
  }

  /* Guess the appliance device name if we didn't find a matching hint */
  if (!*device_ret) {
    /* Count how many disks the libguestfs appliance has */
    for (count = 0; devices[count] != NULL; count++)
      ;

    /* Calculate the numerical index of the disk */
    i = disk[0] - 'a';
    for (p = disk + 1; *p != '\0'; p++) {
      i += 1; i *= 26;
      i += *p - 'a';
    }

    /* Check the index makes sense wrt the number of disks the appliance has.
     * If it does, map it to an appliance disk.
     */
    if (i < count) {
      device = safe_asprintf (g, "%s%s", devices[i], part);
      if (!is_partition (g, device)) {
        free (device);
        return 0;
      }
      *device_ret = device;
    }
  }

  return 0;
}

static int
resolve_fstab_device_cciss (guestfs_h *g, const char *disk, const char *part,
                            char **device_ret)
{
  char *device;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
  size_t i;
  struct drive *drv;

  /* disk: (cciss/c\d+d\d+)
   * part: (\d+)?
   */

  devices = guestfs_list_devices (g);
  if (devices == NULL)
    return -1;

  /* Check any hints we were passed for a non-heuristic mapping */
  ITER_DRIVES (g, i, drv) {
    if (drv->name && STREQ (drv->name, disk)) {
      if (part) {
        device = safe_asprintf (g, "%s%s", devices[i], part);
        if (!is_partition (g, device)) {
          free (device);
          return 0;
        }
        *device_ret = device;
      }
      else
        *device_ret = safe_strdup (g, devices[i]);
      break;
    }
  }

  /* We don't try to guess mappings for cciss devices */
  return 0;
}

static int
resolve_fstab_device_diskbyid (guestfs_h *g, const char *part,
                               char **device_ret)
{
  int nr_devices;
  char *device;

  /* For /dev/disk/by-id there is a limit to what we can do because
   * original SCSI ID information has likely been lost.  This
   * heuristic will only work for guests that have a single block
   * device.
   *
   * So the main task here is to make sure the assumptions above are
   * true.
   *
   * XXX Use hints from virt-p2v if available.
   * See also: https://bugzilla.redhat.com/show_bug.cgi?id=836573#c3
   */

  nr_devices = guestfs_nr_devices (g);
  if (nr_devices == -1)
    return -1;

  /* If #devices isn't 1, give up trying to translate this fstab entry. */
  if (nr_devices != 1)
    return 0;

  /* Make the partition name and check it exists. */
  device = safe_asprintf (g, "/dev/sda%s", part);
  if (!is_partition (g, device)) {
    free (device);
    return 0;
  }

  *device_ret = device;
  return 0;
}

/* Resolve block device name to the libguestfs device name, eg.
 * /dev/xvdb1 => /dev/vdb1; and /dev/mapper/VG-LV => /dev/VG/LV.  This
 * assumes that disks were added in the same order as they appear to
 * the real VM, which is a reasonable assumption to make.  Return
 * anything we don't recognize unchanged.
 */
static char *
resolve_fstab_device (guestfs_h *g, const char *spec, Hash_table *md_map)
{
  char *device = NULL;
  char *type, *slice, *disk, *part;
  int r;

  if (STRPREFIX (spec, "/dev/mapper/") && guestfs_exists (g, spec) > 0) {
    /* LVM2 does some strange munging on /dev/mapper paths for VGs and
     * LVs which contain '-' character:
     *
     * ><fs> lvcreate LV--test VG--test 32
     * ><fs> debug ls /dev/mapper
     * VG----test-LV----test
     *
     * This makes it impossible to reverse those paths directly, so
     * we have implemented lvm_canonical_lv_name in the daemon.
     */
    device = guestfs_lvm_canonical_lv_name (g, spec);
  }
  else if (match3 (g, spec, re_xdev, &type, &disk, &part)) {
    r = resolve_fstab_device_xdev (g, type, disk, part, &device);
    free (type);
    free (disk);
    free (part);
    if (r == -1)
      return NULL;
  }
  else if (match2 (g, spec, re_cciss, &disk, &part)) {
    r = resolve_fstab_device_cciss (g, disk, part, &device);
    free (disk);
    free (part);
    if (r == -1)
      return NULL;
  }
  else if (md_map && (disk = match1 (g, spec, re_mdN)) != NULL) {
    mdadm_app entry;
    entry.mdadm = disk;

    mdadm_app *app = hash_lookup (md_map, &entry);
    if (app) device = safe_strdup (g, app->app);

    free (disk);
  }
  else if (match3 (g, spec, re_freebsd_gpt, &type, &disk, &part)) {
    /* If the FreeBSD disk contains GPT partitions, the translation to Linux
     * device names is straight forward. Partitions on a virtio disk are
     * prefixed with vtbd. IDE hard drives used to be prefixed with ad and now
     * are with ada.
     */
    int disk_i = guestfs___parse_unsigned_int (g, disk);
    int part_i = guestfs___parse_unsigned_int (g, part);
    free (type);
    free (disk);
    free (part);

    if (disk_i != -1 && disk_i <= 26 && part_i > 0 && part_i <= 128)
      device = safe_asprintf (g, "/dev/sd%c%d", disk_i + 'a', part_i);
  }
  else if (match4 (g, spec, re_freebsd_mbr, &type, &disk, &slice, &part)) {
    /* FreeBSD disks are organized quite differently.  See:
     * http://www.freebsd.org/doc/handbook/disk-organization.html
     * FreeBSD "partitions" are exposed as quasi-extended partitions
     * numbered from 5 in Linux.  I have no idea what happens when you
     * have multiple "slices" (the FreeBSD term for MBR partitions).
     */
    int disk_i = guestfs___parse_unsigned_int (g, disk);
    int slice_i = guestfs___parse_unsigned_int (g, slice);
    int part_i = part[0] - 'a' /* counting from 0 */;
    free (type);
    free (disk);
    free (slice);
    free (part);

    if (disk_i != -1 && disk_i <= 26 &&
        slice_i > 0 && slice_i <= 1 /* > 4 .. see comment above */ &&
        part_i >= 0 && part_i < 26) {
      device = safe_asprintf (g, "/dev/sd%c%d", disk_i + 'a', part_i + 5);
    }
  }
  else if ((part = match1 (g, spec, re_diskbyid)) != NULL) {
    r = resolve_fstab_device_diskbyid (g, part, &device);
    free (part);
    if (r == -1)
      return NULL;
  }
  else if (match3 (g, spec, re_hurd_dev, &type, &disk, &part)) {
    /* Hurd disk devices are like /dev/hdNsM, where hdN is the
     * N-th disk and M is the M-th partition on that disk.
     * Turn the disk number into a letter-based identifier, so
     * we can resolve it easily.
     */
    int disk_i = guestfs___parse_unsigned_int (g, disk);
    const char disk_as_letter[2] = { disk_i + 'a', 0 };
    r = resolve_fstab_device_xdev (g, type, disk_as_letter, part, &device);
    free (type);
    free (disk);
    free (part);
    if (r == -1)
      return NULL;
  }

  /* Didn't match device pattern, return original spec unchanged. */
  if (device == NULL)
    device = safe_strdup (g, spec);

  return device;
}

static char *make_augeas_path_expression (guestfs_h *g, const char **configfiles);

/* Call 'f' with Augeas opened and having parsed 'configfiles' (these
 * files must exist).  As a security measure, this bails if any file
 * is too large for a reasonable configuration file.  After the call
 * to 'f' the Augeas handle is closed.
 */
static int
inspect_with_augeas (guestfs_h *g, struct inspect_fs *fs,
                     const char **configfiles,
                     int (*f) (guestfs_h *, struct inspect_fs *))
{
  size_t i;
  int64_t size;
  int r;
  CLEANUP_FREE char *pathexpr = NULL;

  /* Security: Refuse to do this if a config file is too large. */
  for (i = 0; configfiles[i] != NULL; ++i) {
    if (guestfs_is_file_opts (g, configfiles[i],
                              GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS, 1, -1) == 0)
      continue;

    size = guestfs_filesize (g, configfiles[i]);
    if (size == -1)
      /* guestfs_filesize failed and has already set error in handle */
      return -1;
    if (size > MAX_AUGEAS_FILE_SIZE) {
      error (g, _("size of %s is unreasonably large (%" PRIi64 " bytes)"),
             configfiles[i], size);
      return -1;
    }
  }

  if (guestfs_aug_init (g, "/", 16|32 /* AUG_SAVE_NOOP|AUG_NO_LOAD */) == -1)
    return -1;

  r = -1;

  /* Tell Augeas to only load configfiles and no other files.  This
   * prevents a rogue guest from performing a denial of service attack
   * by having large, over-complicated configuration files which are
   * unrelated to the task at hand.  (Thanks Dominic Cleal).
   * Note this requires Augeas >= 1.0.0 because of RHBZ#975412.
   */
  pathexpr = make_augeas_path_expression (g, configfiles);
  if (guestfs_aug_rm (g, pathexpr) == -1)
    goto out;

  if (guestfs_aug_load (g) == -1)
    goto out;

  r = f (g, fs);

 out:
  guestfs_aug_close (g);

  return r;
}

/* Explained here: https://bugzilla.redhat.com/show_bug.cgi?id=975412#c0 */
static char *
make_augeas_path_expression (guestfs_h *g, const char **configfiles)
{
  size_t i;
  size_t nr_files;
  CLEANUP_FREE_STRING_LIST char **subexprs = NULL;
  CLEANUP_FREE char *subexpr = NULL;
  char *ret;

  nr_files = guestfs___count_strings ((char **) configfiles);
  subexprs = safe_malloc (g, sizeof (char *) * (nr_files + 1));

  for (i = 0; i < nr_files; ++i) {
    subexprs[i] = /*         v NB trailing '/' after filename */
      safe_asprintf (g, "\"%s/\" !~ regexp('^') + glob(incl) + regexp('/.*')",
                     configfiles[i]);
  }
  subexprs[nr_files] = NULL;

  subexpr = guestfs___join_strings (" and ", subexprs);
  if (subexpr == NULL)
    g->abort_cb ();

  ret = safe_asprintf (g, "/augeas/load/*[ %s ]", subexpr);
  debug (g, "augeas pathexpr = %s", ret);
  return ret;
}

static int
is_partition (guestfs_h *g, const char *partition)
{
  CLEANUP_FREE char *device = NULL;

  guestfs_push_error_handler (g, NULL, NULL);

  if ((device = guestfs_part_to_dev (g, partition)) == NULL) {
    guestfs_pop_error_handler (g);
    return 0;
  }

  if (guestfs_device_index (g, device) == -1) {
    guestfs_pop_error_handler (g);
    return 0;
  }

  guestfs_pop_error_handler (g);

  return 1;
}
