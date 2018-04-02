/* libguestfs - the guestfsd daemon
 * Copyright (C) 2012 Red Hat Inc.
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
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include <yajl/yajl_tree.h>

#include "daemon.h"
#include "actions.h"
#include "optgroups.h"

/* GCC can't work out that the YAJL_IS_<foo> test is sufficient to
 * ensure that YAJL_GET_<foo> later doesn't return NULL.
 */
#if defined(__GNUC__) && GUESTFS_GCC_VERSION >= 60000 /* gcc >= 6 */
#pragma GCC diagnostic ignored "-Wnull-dereference"
#endif

int
optgroup_ldm_available (void)
{
  return prog_exists ("ldmtool");
}

int
do_ldmtool_create_all (void)
{
  int r;
  CLEANUP_FREE char *err = NULL;

  r = command (NULL, &err, "ldmtool", "create", "all", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }
  return 0;
}

int
do_ldmtool_remove_all (void)
{
  int r;
  CLEANUP_FREE char *err = NULL;

  r = command (NULL, &err, "ldmtool", "remove", "all", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }
  return 0;
}

static yajl_val
parse_json (const char *json, const char *func)
{
  yajl_val tree;
  char parse_error[1024];

  if (verbose)
    fprintf (stderr, "%s: parsing json: %s\n", func, json);

  tree = yajl_tree_parse (json, parse_error, sizeof parse_error);
  if (tree == NULL) {
    reply_with_error ("parse error: %s",
                      strlen (parse_error) ? parse_error : "unknown error");
    return NULL;
  }

  /* Caller should free this by doing 'yajl_tree_free (tree);'. */
  return tree;
}

#define TYPE_ERROR ((char **) -1)

static char **
json_value_to_string_list (yajl_val node)
{
  CLEANUP_FREE_STRINGSBUF DECLARE_STRINGSBUF (strs);
  yajl_val n;
  size_t i, len;

  if (! YAJL_IS_ARRAY (node))
    return TYPE_ERROR;

  len = YAJL_GET_ARRAY (node)->len;
  for (i = 0; i < len; ++i) {
    n = YAJL_GET_ARRAY (node)->values[i];
    if (! YAJL_IS_STRING (n))
      return TYPE_ERROR;
    if (add_string (&strs, YAJL_GET_STRING (n)) == -1)
      return NULL;
  }
  if (end_stringsbuf (&strs) == -1)
    return NULL;

  return take_stringsbuf (&strs);
}

static char **
parse_json_get_string_list (const char *json,
                            const char *func, const char *cmd)
{
  char **ret;
  yajl_val tree = NULL;

  tree = parse_json (json, func);
  if (tree == NULL)
    return NULL;

  ret = json_value_to_string_list (tree);
  yajl_tree_free (tree);
  if (ret == TYPE_ERROR) {
    reply_with_error ("output of '%s' was not a JSON array of strings", cmd);
    return NULL;
  }
  return ret;
}

#define GET_STRING_NULL_TO_EMPTY 1

static char *
parse_json_get_object_string (const char *json, const char *key, int flags,
                              const char *func, const char *cmd)
{
  char *str, *ret;
  yajl_val tree = NULL, node;
  size_t i, len;

  tree = parse_json (json, func);
  if (tree == NULL)
    return NULL;

  if (! YAJL_IS_OBJECT (tree))
    goto bad_type;

  len = YAJL_GET_OBJECT (tree)->len;
  for (i = 0; i < len; ++i) {
    if (STREQ (YAJL_GET_OBJECT (tree)->keys[i], key)) {
      node = YAJL_GET_OBJECT (tree)->values[i];

      if ((flags & GET_STRING_NULL_TO_EMPTY) && YAJL_IS_NULL (node))
        ret = strdup ("");
      else {
        str = YAJL_GET_STRING (node);
        if (str == NULL)
          goto bad_type;
        ret = strdup (str);
      }
      if (ret == NULL)
        reply_with_perror ("strdup");

      yajl_tree_free (tree);

      return ret;
    }
  }

 bad_type:
  reply_with_error ("output of '%s' was not a JSON object "
                    "containing a key '%s' of type string", cmd, key);
  yajl_tree_free (tree);
  return NULL;
}

static char **
parse_json_get_object_string_list (const char *json, const char *key,
                                   const char *func, const char *cmd)
{
  char **ret;
  yajl_val tree, node;
  size_t i, len;

  tree = parse_json (json, func);
  if (tree == NULL)
    return NULL;

  if (! YAJL_IS_OBJECT (tree))
    goto bad_type;

  len = YAJL_GET_OBJECT (tree)->len;
  for (i = 0; i < len; ++i) {
    if (STREQ (YAJL_GET_OBJECT (tree)->keys[i], key)) {
      node = YAJL_GET_OBJECT (tree)->values[i];
      ret = json_value_to_string_list (node);
      if (ret == TYPE_ERROR)
        goto bad_type;
      yajl_tree_free (tree);
      return ret;
    }
  }

 bad_type:
  reply_with_error ("output of '%s' was not a JSON object "
                    "containing a key '%s' of type array of strings",
                    cmd, key);
  yajl_tree_free (tree);
  return NULL;
}

char **
do_ldmtool_scan (void)
{
  const char *empty_list[] = { NULL };

  return do_ldmtool_scan_devices ((char * const *) empty_list);
}

char **
do_ldmtool_scan_devices (char * const * devices)
{
  char **ret;
  size_t i, nr_devices;
  CLEANUP_FREE const char **argv = NULL;
  int r;
  CLEANUP_FREE char *out = NULL, *err = NULL;

  nr_devices = guestfs_int_count_strings (devices);
  argv = malloc ((3 + nr_devices) * sizeof (char *));
  if (argv == NULL) {
    reply_with_perror ("malloc");
    return NULL;
  }

  argv[0] = "ldmtool";
  argv[1] = "scan";
  for (i = 0; i < nr_devices; ++i)
    argv[2+i] = devices[i];
  argv[2+i] = NULL;

  r = commandv (&out, &err, argv);
  if (r == -1) {
    reply_with_error ("%s", err);
    return NULL;
  }

  ret = parse_json_get_string_list (out, __func__, "ldmtool scan");
  return ret;
}

char *
do_ldmtool_diskgroup_name (const char *diskgroup)
{
  int r;
  CLEANUP_FREE char *out = NULL, *err = NULL;

  r = command (&out, &err, "ldmtool", "show", "diskgroup", diskgroup, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return NULL;
  }

  return parse_json_get_object_string (out, "name", 0,
                                       __func__, "ldmtool show diskgroup");
}

char **
do_ldmtool_diskgroup_volumes (const char *diskgroup)
{
  int r;
  CLEANUP_FREE char *out = NULL, *err = NULL;

  r = command (&out, &err, "ldmtool", "show", "diskgroup", diskgroup, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return NULL;
  }

  return parse_json_get_object_string_list (out, "volumes",
                                            __func__, "ldmtool show diskgroup");
}

char **
do_ldmtool_diskgroup_disks (const char *diskgroup)
{
  int r;
  CLEANUP_FREE char *out = NULL, *err = NULL;

  r = command (&out, &err, "ldmtool", "show", "diskgroup", diskgroup, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return NULL;
  }

  return parse_json_get_object_string_list (out, "disks",
                                            __func__, "ldmtool show diskgroup");
}

char *
do_ldmtool_volume_type (const char *diskgroup, const char *volume)
{
  int r;
  CLEANUP_FREE char *out = NULL, *err = NULL;

  r = command (&out, &err,
               "ldmtool", "show", "volume", diskgroup, volume, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return NULL;
  }

  return parse_json_get_object_string (out, "type", 0,
                                       __func__, "ldmtool show volume");
}

char *
do_ldmtool_volume_hint (const char *diskgroup, const char *volume)
{
  int r;
  CLEANUP_FREE char *out = NULL, *err = NULL;

  r = command (&out, &err,
               "ldmtool", "show", "volume", diskgroup, volume, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return NULL;
  }

  return parse_json_get_object_string (out, "hint", GET_STRING_NULL_TO_EMPTY,
                                       __func__, "ldmtool show volume");
}

char **
do_ldmtool_volume_partitions (const char *diskgroup, const char *volume)
{
  int r;
  CLEANUP_FREE char *out = NULL, *err = NULL;

  r = command (&out, &err,
               "ldmtool", "show", "volume", diskgroup, volume, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return NULL;
  }

  return parse_json_get_object_string_list (out, "partitions",
                                            __func__, "ldmtool show volume");
}
