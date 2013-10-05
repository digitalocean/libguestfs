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
void aug_finalize (void) __attribute__((destructor));
void
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

/* Calls reply_with_error, but includes the Augeas error details. */
#define AUGEAS_ERROR(fs,...)                                            \
  do {                                                                  \
      int code = aug_error (aug);                                       \
      if (code == AUG_ENOMEM)                                           \
        reply_with_error (fs ": augeas out of memory", ##__VA_ARGS__);  \
      else {                                                            \
            const char *message = aug_error_message (aug);              \
            const char *minor = aug_error_minor_message (aug);          \
            const char *details = aug_error_details (aug);              \
            reply_with_error (fs ": %s%s%s%s%s", ##__VA_ARGS__,         \
                                message,                                \
                                minor ? ": " : "", minor ? minor : "",  \
                                details ? ": " : "", details ? details : ""); \
            }                                                           \
  } while (0)

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
    AUGEAS_ERROR ("aug_defvar: %s: %s", name, expr);
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
    AUGEAS_ERROR ("aug_defnode: %s: %s: %s", name, expr, val);
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
    AUGEAS_ERROR ("aug_get: %s", path);
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
    AUGEAS_ERROR ("aug_set: %s: %s", path, val);
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
    AUGEAS_ERROR ("aug_clear: %s", path);
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
    AUGEAS_ERROR ("aug_insert: %s: %s [before=%d]", path, label, before);
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
    AUGEAS_ERROR ("aug_rm: %s", path);
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
    AUGEAS_ERROR ("aug_mv: %s: %s", src, dest);
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
    AUGEAS_ERROR ("aug_match: %s", path);
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
    AUGEAS_ERROR ("aug_save");
    return -1;
  }

  return 0;
}

int
do_aug_load (void)
{
  NEED_AUG (-1);

  if (aug_load (aug) == -1) {
    AUGEAS_ERROR ("aug_load");
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
    CLEANUP_FREE char *buf = NULL;

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

int
do_aug_setm (const char *base, const char *sub, const char *val)
{
  int r;

  NEED_AUG (-1);

  r = aug_setm (aug, base, sub, val);
  if (r == -1) {
    AUGEAS_ERROR ("aug_setm: %s: %s: %s", base, sub ? sub : "(null)", val);
    return -1;
  }

  return r;
}

char *
do_aug_label (const char *augpath)
{
  int r;
  const char *label;
  char *ret;

  NEED_AUG (NULL);

  r = aug_label (aug, augpath, &label);
  if (r == -1) {
    AUGEAS_ERROR ("aug_label: %s", augpath);
    return NULL;
  }
  if (r == 0) {
    reply_with_error ("no matching nodes found");
    return NULL;
  }

  if (label == NULL) {
    reply_with_error ("internal error: expected label != NULL (r = %d)", r);
    return NULL;
  }

  /* 'label' points to an interior field in the Augeas handle, so
   * we must return a copy.
   */
  ret = strdup (label);
  if (ret == NULL) {
    reply_with_perror ("strdup");
    return NULL;
  }

  return ret;                   /* caller frees */
}
