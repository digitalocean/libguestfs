/* libguestfs - the guestfsd daemon
 * Copyright (C) 2009 Red Hat Inc.
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

#include <augeas.h>

#include "daemon.h"
#include "actions.h"
#include "optgroups.h"

int
optgroup_augeas_available (void)
{
  return 1;
}

/* The Augeas handle.  We maintain a single handle per daemon, which
 * is all that is necessary and reduces the complexity of the API
 * considerably.
 */
static augeas *aug = NULL;

/* Clean up the augeas handle on daemon exit. */
static void aug_finalize (void) __attribute__((destructor));
static void
aug_finalize (void)
{
  if (aug) {
    aug_close (aug);
    aug = NULL;
  }
}

#define NEED_AUG(errcode)						\
  do {									\
    if (!aug) {								\
      reply_with_error ("%s: you must call 'aug-init' first to initialize Augeas", __func__); \
      return (errcode);							\
    }									\
  }									\
  while (0)

/* We need to rewrite the root path so it is based at /sysroot. */
int
do_aug_init (const char *root, int flags)
{
  CLEANUP_FREE char *buf = NULL;

  if (aug) {
    aug_close (aug);
    aug = NULL;
  }

  buf = sysroot_path (root);
  if (!buf) {
    reply_with_perror ("malloc");
    return -1;
  }

  aug = aug_init (buf, NULL, flags);

  if (!aug) {
    reply_with_error ("Augeas initialization failed");
    return -1;
  }

  return 0;
}

int
do_aug_close (void)
{
  NEED_AUG(-1);

  aug_close (aug);
  aug = NULL;

  return 0;
}

int
do_aug_defvar (const char *name, const char *expr)
{
  int r;

  NEED_AUG (-1);

  r = aug_defvar (aug, name, expr);
  if (r == -1) {
    reply_with_error ("Augeas defvar failed");
    return -1;
  }
  return r;
}

guestfs_int_int_bool *
do_aug_defnode (const char *name, const char *expr, const char *val)
{
  guestfs_int_int_bool *r;
  int i, created;

  NEED_AUG (NULL);

  i = aug_defnode (aug, name, expr, val, &created);
  if (i == -1) {
    reply_with_error ("Augeas defnode failed");
    return NULL;
  }

  r = malloc (sizeof *r);
  if (r == NULL) {
    reply_with_perror ("malloc");
    return NULL;
  }

  r->i = i;
  r->b = created;

  return r;
}

char *
do_aug_get (const char *path)
{
  const char *value = NULL;
  char *v;
  int r;

  NEED_AUG (NULL);

  r = aug_get (aug, path, &value);
  if (r == 0) {
    reply_with_error ("no matching node");
    return NULL;
  }
  if (r != 1) {
    reply_with_error ("Augeas get failed");
    return NULL;
  }

  /* value can still be NULL here, eg. try with path == "/augeas".
   * I don't understand this case, and it seems to contradict the
   * documentation.
   */
  if (value == NULL) {
    reply_with_error ("Augeas returned NULL match");
    return NULL;
  }

  /* The value is an internal Augeas string, so we must copy it. GC FTW. */
  v = strdup (value);
  if (v == NULL) {
    reply_with_perror ("strdup");
    return NULL;
  }

  return v;			/* Caller frees. */
}

int
do_aug_set (const char *path, const char *val)
{
  int r;

  NEED_AUG (-1);

  r = aug_set (aug, path, val);
  if (r == -1) {
    reply_with_error ("Augeas set failed");
    return -1;
  }

  return 0;
}

int
do_aug_clear (const char *path)
{
  int r;

  NEED_AUG (-1);

  r = aug_set (aug, path, NULL);
  if (r == -1) {
    reply_with_error ("Augeas clear failed");
    return -1;
  }

  return 0;
}

int
do_aug_insert (const char *path, const char *label, int before)
{
  int r;

  NEED_AUG (-1);

  r = aug_insert (aug, path, label, before);
  if (r == -1) {
    reply_with_error ("Augeas insert failed");
    return -1;
  }

  return 0;
}

int
do_aug_rm (const char *path)
{
  int r;

  NEED_AUG (-1);

  r = aug_rm (aug, path);
  if (r == -1) {
    reply_with_error ("Augeas rm failed");
    return -1;
  }

  return r;
}

int
do_aug_mv (const char *src, const char *dest)
{
  int r;

  NEED_AUG (-1);

  r = aug_mv (aug, src, dest);
  if (r == -1) {
    reply_with_error ("Augeas mv failed");
    return -1;
  }

  return 0;
}

char **
do_aug_match (const char *path)
{
  char **matches = NULL;
  void *vp;
  int r;

  NEED_AUG (NULL);

  r = aug_match (aug, path, &matches);
  if (r == -1) {
    reply_with_error ("Augeas match failed");
    return NULL;
  }

  /* This returns an array of length r, which we must extend
   * and add a terminating NULL.
   */
  vp = realloc (matches, sizeof (char *) * (r+1));
  if (vp == NULL) {
    reply_with_perror ("realloc");
    free (vp);
    return NULL;
  }
  matches = vp;
  matches[r] = NULL;

  return matches;		/* Caller frees. */
}

int
do_aug_save (void)
{
  NEED_AUG (-1);

  if (aug_save (aug) == -1) {
    reply_with_error ("Augeas save failed");
    return -1;
  }

  return 0;
}

int
do_aug_load (void)
{
  NEED_AUG (-1);

  if (aug_load (aug) == -1) {
    reply_with_error ("Augeas load failed");
    return -1;
  }

  return 0;
}

/* Simpler version of aug-match, which also sorts the output. */
char **
do_aug_ls (const char *path)
{
  char **matches;
  size_t len;

  NEED_AUG (NULL);

  /* Note that path might also be a previously defined variable
   * (defined with aug_defvar).  See RHBZ#580016.
   */

  len = strlen (path);

  if (len > 1 &&
      (path[len-1] == '/' || path[len-1] == ']' || path[len-1] == '*')) {
    reply_with_error ("don't use aug-ls with a path that ends with / ] *");
    return NULL;
  }

  if (STREQ (path, "/"))
    matches = do_aug_match ("/*");
  else {
    CLEANUP_FREE char *buf;

    len += 3;			/* / * + terminating \0 */
    buf = malloc (len);
    if (buf == NULL) {
      reply_with_perror ("malloc");
      return NULL;
    }

    snprintf (buf, len, "%s/*", path);
    matches = do_aug_match (buf);
  }

  if (matches == NULL)
    return NULL;		/* do_aug_match has already sent the error */

  sort_strings (matches, count_strings ((void *) matches));
  return matches;		/* Caller frees. */
}
