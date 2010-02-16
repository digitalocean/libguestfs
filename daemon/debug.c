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
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#include "../src/guestfs_protocol.h"
#include "daemon.h"
#include "actions.h"

/* This command exposes debugging information, internals and
 * status.  There is no comprehensive documentation for this
 * command.  You have to look at the source code in this file
 * to find out what you can do.
 *
 * Commands always output a freeform string.
 */

#if ENABLE_DEBUG_COMMAND
struct cmd {
  const char *cmd;
  char * (*f) (const char *subcmd, int argc, char *const *const argv);
};

static char *debug_help (const char *subcmd, int argc, char *const *const argv);
static char *debug_env (const char *subcmd, int argc, char *const *const argv);
static char *debug_fds (const char *subcmd, int argc, char *const *const argv);
static char *debug_ls (const char *subcmd, int argc, char *const *const argv);
static char *debug_ll (const char *subcmd, int argc, char *const *const argv);
static char *debug_segv (const char *subcmd, int argc, char *const *const argv);
static char *debug_sh (const char *subcmd, int argc, char *const *const argv);

static struct cmd cmds[] = {
  { "help", debug_help },
  { "env", debug_env },
  { "fds", debug_fds },
  { "ls", debug_ls },
  { "ll", debug_ll },
  { "segv", debug_segv },
  { "sh", debug_sh },
  { NULL, NULL }
};
#endif

#if ! ENABLE_DEBUG_COMMAND
# define MAYBE_UNUSED ATTRIBUTE_UNUSED
#else
# define MAYBE_UNUSED /* empty */
#endif

char *
do_debug (const char *subcmd MAYBE_UNUSED, char *const *argv MAYBE_UNUSED)
{
#if ENABLE_DEBUG_COMMAND
  int argc, i;

  for (i = argc = 0; argv[i] != NULL; ++i)
    argc++;

  for (i = 0; cmds[i].cmd != NULL; ++i) {
    if (STRCASEEQ (subcmd, cmds[i].cmd))
      return cmds[i].f (subcmd, argc, argv);
  }

  reply_with_error ("use 'debug help' to list the supported commands");
  return NULL;
#else
  reply_with_error ("guestfsd was not configured with --enable-debug-command");
  return NULL;
#endif
}

#if ENABLE_DEBUG_COMMAND
static char *
debug_help (const char *subcmd, int argc, char *const *const argv)
{
  int len, i;
  char *r, *p;

  r = strdup ("Commands supported:");
  if (!r) {
    reply_with_perror ("strdup");
    return NULL;
  }

  len = strlen (r);
  for (i = 0; cmds[i].cmd != NULL; ++i) {
    len += strlen (cmds[i].cmd) + 1; /* space + new command */
    p = realloc (r, len + 1);	     /* +1 for the final NUL */
    if (p == NULL) {
      reply_with_perror ("realloc");
      free (r);
      return NULL;
    }
    r = p;

    strcat (r, " ");
    strcat (r, cmds[i].cmd);
  }

  return r;
}

/* Show open FDs. */
static char *
debug_fds (const char *subcmd, int argc, char *const *const argv)
{
  int r;
  char *out;
  size_t size;
  FILE *fp;
  DIR *dir;
  struct dirent *d;
  char fname[256], link[256];
  struct stat statbuf;

  fp = open_memstream (&out, &size);
  if (!fp) {
    reply_with_perror ("open_memstream");
    return NULL;
  }

  dir = opendir ("/proc/self/fd");
  if (!dir) {
    reply_with_perror ("opendir: /proc/self/fd");
    fclose (fp);
    return NULL;
  }

  while ((d = readdir (dir)) != NULL) {
    if (STREQ (d->d_name, ".") || STREQ (d->d_name, ".."))
      continue;

    snprintf (fname, sizeof fname, "/proc/self/fd/%s", d->d_name);

    r = lstat (fname, &statbuf);
    if (r == -1) {
      reply_with_perror ("stat: %s", fname);
      fclose (fp);
      free (out);
      closedir (dir);
      return NULL;
    }

    if (S_ISLNK (statbuf.st_mode)) {
      r = readlink (fname, link, sizeof link - 1);
      if (r == -1) {
        reply_with_perror ("readline: %s", fname);
        fclose (fp);
        free (out);
        closedir (dir);
        return NULL;
      }
      link[r] = '\0';

      fprintf (fp, "%2s %s\n", d->d_name, link);
    } else
      fprintf (fp, "%2s 0%o\n", d->d_name, statbuf.st_mode);
  }

  fclose (fp);

  if (closedir (dir) == -1) {
    reply_with_perror ("closedir");
    free (out);
    return NULL;
  }

  return out;
}

/* Force a segfault in the daemon. */
static char *
debug_segv (const char *subcmd, int argc, char *const *const argv)
{
  *(int*)0 = 0;
  return NULL;
}

/* Run an arbitrary shell command using /bin/sh from the appliance.
 *
 * Note this is somewhat different from the ordinary guestfs_sh command
 * because it's not using the guest shell, and is not chrooted.
 *
 * Also we ignore any errors and you can see the full output if you
 * add 2>&1 to the end of the command string.
 */
static char *
debug_sh (const char *subcmd, int argc, char *const *const argv)
{
  char *cmd;
  int len, i, j;
  char *out;

  if (argc < 1) {
    reply_with_error ("sh: expecting a command to run");
    return NULL;
  }

  /* guestfish splits the parameter(s) into a list of strings,
   * and we have to reassemble them here.  Not ideal. XXX
   */
  for (i = len = 0; i < argc; ++i)
    len += strlen (argv[i]) + 1;
  cmd = malloc (len);
  if (!cmd) {
    reply_with_perror ("malloc");
    return NULL;
  }
  for (i = j = 0; i < argc; ++i) {
    len = strlen (argv[i]);
    memcpy (&cmd[j], argv[i], len);
    j += len;
    cmd[j] = ' ';
    j++;
  }
  cmd[j-1] = '\0';

  command (&out, NULL, "/bin/sh", "-c", cmd, NULL);
  free (cmd);
  return out;
}

/* Print the environment that commands get (by running external printenv). */
static char *
debug_env (const char *subcmd, int argc, char *const *const argv)
{
  int r;
  char *out, *err;

  r = command (&out, &err, "printenv", NULL);
  if (r == -1) {
    reply_with_error ("printenv: %s", err);
    free (out);
    free (err);
    return NULL;
  }

  free (err);

  return out;
}

/* List files in the appliance. */
static char *
debug_ls (const char *subcmd, int argc, char *const *const argv)
{
  int len = count_strings (argv);
  const char *cargv[len+3];
  int i;

  cargv[0] = "ls";
  cargv[1] = "-a";
  for (i = 0; i < len; ++i)
    cargv[2+i] = argv[i];
  cargv[2+len] = NULL;

  int r;
  char *out, *err;

  r = commandv (&out, &err, (void *) cargv);
  if (r == -1) {
    reply_with_error ("ls: %s", err);
    free (out);
    free (err);
    return NULL;
  }

  free (err);

  return out;
}

/* List files in the appliance. */
static char *
debug_ll (const char *subcmd, int argc, char *const *const argv)
{
  int len = count_strings (argv);
  const char *cargv[len+3];
  int i;

  cargv[0] = "ls";
  cargv[1] = "-la";
  for (i = 0; i < len; ++i)
    cargv[2+i] = argv[i];
  cargv[2+len] = NULL;

  int r;
  char *out, *err;

  r = commandv (&out, &err, (void *) cargv);
  if (r == -1) {
    reply_with_error ("ll: %s", err);
    free (out);
    free (err);
    return NULL;
  }

  free (err);

  return out;
}

#endif /* ENABLE_DEBUG_COMMAND */
