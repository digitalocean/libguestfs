/* libguestfs
 * Copyright (C) 2010-2016 Red Hat Inc.
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
#include <string.h>

#include <pcre.h>

#include "guestfs.h"
#include "guestfs-internal.h"

/* Match a regular expression which contains no captures.  Returns
 * true if it matches or false if it doesn't.
 */
int
guestfs_int_match (guestfs_h *g, const char *str, const pcre *re)
{
  size_t len = strlen (str);
  int vec[30], r;

  r = pcre_exec (re, NULL, str, len, 0, 0, vec, sizeof vec / sizeof vec[0]);
  if (r == PCRE_ERROR_NOMATCH)
    return 0;

  return 1;
}

/* Match a regular expression which contains exactly one capture.  If
 * the string matches, return the capture, otherwise return NULL.  The
 * caller must free the result.
 */
char *
guestfs_int_match1 (guestfs_h *g, const char *str, const pcre *re)
{
  size_t len = strlen (str);
  int vec[30], r;

  r = pcre_exec (re, NULL, str, len, 0, 0, vec, sizeof vec / sizeof vec[0]);
  if (r == PCRE_ERROR_NOMATCH)
    return NULL;

  return r == 2 ? safe_strndup (g, &str[vec[2]], vec[3]-vec[2]) : NULL;
}

/* Match a regular expression which contains exactly two captures. */
int
guestfs_int_match2 (guestfs_h *g, const char *str, const pcre *re,
		    char **ret1, char **ret2)
{
  size_t len = strlen (str);
  int vec[30], r;

  r = pcre_exec (re, NULL, str, len, 0, 0, vec, 30);
  if (r == PCRE_ERROR_NOMATCH)
    return 0;

  *ret1 = NULL;
  *ret2 = NULL;

  if (r > 1) *ret1 = safe_strndup (g, &str[vec[2]], vec[3]-vec[2]);
  if (r > 2) *ret2 = safe_strndup (g, &str[vec[4]], vec[5]-vec[4]);

  return 1;
}

/* Match a regular expression which contains exactly three captures. */
int
guestfs_int_match3 (guestfs_h *g, const char *str, const pcre *re,
		    char **ret1, char **ret2, char **ret3)
{
  size_t len = strlen (str);
  int vec[30], r;

  r = pcre_exec (re, NULL, str, len, 0, 0, vec, 30);
  if (r == PCRE_ERROR_NOMATCH)
    return 0;

  *ret1 = NULL;
  *ret2 = NULL;
  *ret3 = NULL;

  if (r > 1) *ret1 = safe_strndup (g, &str[vec[2]], vec[3]-vec[2]);
  if (r > 2) *ret2 = safe_strndup (g, &str[vec[4]], vec[5]-vec[4]);
  if (r > 3) *ret3 = safe_strndup (g, &str[vec[6]], vec[7]-vec[6]);

  return 1;
}

/* Match a regular expression which contains exactly four captures. */
int
guestfs_int_match4 (guestfs_h *g, const char *str, const pcre *re,
		    char **ret1, char **ret2, char **ret3, char **ret4)
{
  size_t len = strlen (str);
  int vec[30], r;

  r = pcre_exec (re, NULL, str, len, 0, 0, vec, 30);
  if (r == PCRE_ERROR_NOMATCH)
    return 0;

  *ret1 = NULL;
  *ret2 = NULL;
  *ret3 = NULL;
  *ret4 = NULL;

  if (r > 1) *ret1 = safe_strndup (g, &str[vec[2]], vec[3]-vec[2]);
  if (r > 2) *ret2 = safe_strndup (g, &str[vec[4]], vec[5]-vec[4]);
  if (r > 3) *ret3 = safe_strndup (g, &str[vec[6]], vec[7]-vec[6]);
  if (r > 4) *ret4 = safe_strndup (g, &str[vec[8]], vec[9]-vec[8]);

  return 1;
}

/* Match a regular expression which contains exactly six captures. */
int
guestfs_int_match6 (guestfs_h *g, const char *str, const pcre *re,
		    char **ret1, char **ret2, char **ret3, char **ret4,
		    char **ret5, char **ret6)
{
  size_t len = strlen (str);
  int vec[30], r;

  r = pcre_exec (re, NULL, str, len, 0, 0, vec, 30);
  if (r == PCRE_ERROR_NOMATCH)
    return 0;

  *ret1 = NULL;
  *ret2 = NULL;
  *ret3 = NULL;
  *ret4 = NULL;
  *ret5 = NULL;
  *ret6 = NULL;

  if (r > 1) *ret1 = safe_strndup (g, &str[vec[2]], vec[3]-vec[2]);
  if (r > 2) *ret2 = safe_strndup (g, &str[vec[4]], vec[5]-vec[4]);
  if (r > 3) *ret3 = safe_strndup (g, &str[vec[6]], vec[7]-vec[6]);
  if (r > 4) *ret4 = safe_strndup (g, &str[vec[8]], vec[9]-vec[8]);
  if (r > 5) *ret5 = safe_strndup (g, &str[vec[10]], vec[11]-vec[10]);
  if (r > 6) *ret6 = safe_strndup (g, &str[vec[12]], vec[13]-vec[12]);

  return 1;
}
