/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/daemon.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2018 Red Hat Inc.
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
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>
#include <rpc/types.h>
#include <rpc/xdr.h>

#include "daemon.h"
#include "c-ctype.h"
#include "guestfs_protocol.h"
#include "actions.h"
#include "optgroups.h"

static const char lvm_pv_cols[] = "pv_name,pv_uuid,pv_fmt,pv_size,dev_size,pv_free,pv_used,pv_attr,pv_pe_count,pv_pe_alloc_count,pv_tags,pe_start,pv_mda_count,pv_mda_free";

static int lvm_tokenize_pv (char *str, guestfs_int_lvm_pv *r)
{
  char *tok, *p, *next;
  size_t i, j;

  if (!str) {
    fprintf (stderr, "%s: failed: passed a NULL string\n", __func__);
    return -1;
  }
  if (!*str || c_isspace (*str)) {
    fprintf (stderr, "%s: failed: passed a empty string or one beginning with whitespace\n", __func__);
    return -1;
  }
  tok = str;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_name");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_name = strdup (tok);
  if (r->pv_name == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_uuid");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  for (i = j = 0; i < 32; ++j) {
    if (tok[j] == '\0') {
      fprintf (stderr, "%s: failed to parse UUID from '%s'\n", __func__, tok);
      return -1;
    } else if (tok[j] != '-')
      r->pv_uuid[i++] = tok[j];
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_fmt");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_fmt = strdup (tok);
  if (r->pv_fmt == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_size");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "dev_size");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->dev_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "dev_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_free");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_free");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_used");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_used) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_used");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_attr");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_attr = strdup (tok);
  if (r->pv_attr == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_pe_count");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_pe_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_pe_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_pe_alloc_count");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_pe_alloc_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_pe_alloc_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_tags");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_tags = strdup (tok);
  if (r->pv_tags == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pe_start");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pe_start) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pe_start");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_mda_count");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_mda_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_mda_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_mda_free");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_mda_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_mda_free");
    return -1;
  }
  tok = next;
  if (tok != NULL) {
    fprintf (stderr, "%s: failed: extra tokens at end of string\n", __func__);
    return -1;
  }
  return 0;
}

guestfs_int_lvm_pv_list *
parse_command_line_pvs (void)
{
  char *out, *err;
  char *p, *pend;
  int r, i;
  guestfs_int_lvm_pv_list *ret;
  void *newp;

  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->guestfs_int_lvm_pv_list_len = 0;
  ret->guestfs_int_lvm_pv_list_val = NULL;

  r = command (&out, &err,
	       "lvm", "pvs",
	       "-o", lvm_pv_cols, "--unbuffered", "--noheadings",
	       "--nosuffix", "--separator", "\r", "--units", "b", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    free (err);
    free (ret);
    return NULL;
  }

  free (err);

  /* Tokenize each line of the output. */
  p = out;
  i = 0;
  while (p) {
    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    if (!*p) {			/* Empty line?  Skip it. */
      p = pend;
      continue;
    }

    /* Allocate some space to store this next entry. */
    newp = realloc (ret->guestfs_int_lvm_pv_list_val,
		    sizeof (guestfs_int_lvm_pv) * (i+1));
    if (newp == NULL) {
      reply_with_perror ("realloc");
      free (ret->guestfs_int_lvm_pv_list_val);
      free (ret);
      free (out);
      return NULL;
    }
    ret->guestfs_int_lvm_pv_list_val = newp;

    /* Tokenize the next entry. */
    r = lvm_tokenize_pv (p, &ret->guestfs_int_lvm_pv_list_val[i]);
    if (r == -1) {
      reply_with_error ("failed to parse output of 'pvs' command");
      free (ret->guestfs_int_lvm_pv_list_val);
      free (ret);
      free (out);
      return NULL;
    }

    ++i;
    p = pend;
  }

  ret->guestfs_int_lvm_pv_list_len = i;

  free (out);
  return ret;
}
static const char lvm_vg_cols[] = "vg_name,vg_uuid,vg_fmt,vg_attr,vg_size,vg_free,vg_sysid,vg_extent_size,vg_extent_count,vg_free_count,max_lv,max_pv,pv_count,lv_count,snap_count,vg_seqno,vg_tags,vg_mda_count,vg_mda_free";

static int lvm_tokenize_vg (char *str, guestfs_int_lvm_vg *r)
{
  char *tok, *p, *next;
  size_t i, j;

  if (!str) {
    fprintf (stderr, "%s: failed: passed a NULL string\n", __func__);
    return -1;
  }
  if (!*str || c_isspace (*str)) {
    fprintf (stderr, "%s: failed: passed a empty string or one beginning with whitespace\n", __func__);
    return -1;
  }
  tok = str;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_name");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_name = strdup (tok);
  if (r->vg_name == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_uuid");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  for (i = j = 0; i < 32; ++j) {
    if (tok[j] == '\0') {
      fprintf (stderr, "%s: failed to parse UUID from '%s'\n", __func__, tok);
      return -1;
    } else if (tok[j] != '-')
      r->vg_uuid[i++] = tok[j];
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_fmt");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_fmt = strdup (tok);
  if (r->vg_fmt == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_attr");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_attr = strdup (tok);
  if (r->vg_attr == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_size");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_free");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_free");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_sysid");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_sysid = strdup (tok);
  if (r->vg_sysid == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_extent_size");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_extent_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_extent_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_extent_count");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_extent_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_extent_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_free_count");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_free_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_free_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "max_lv");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->max_lv) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "max_lv");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "max_pv");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->max_pv) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "max_pv");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_count");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_count");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->lv_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "snap_count");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->snap_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "snap_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_seqno");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_seqno) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_seqno");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_tags");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_tags = strdup (tok);
  if (r->vg_tags == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_mda_count");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_mda_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_mda_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_mda_free");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_mda_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_mda_free");
    return -1;
  }
  tok = next;
  if (tok != NULL) {
    fprintf (stderr, "%s: failed: extra tokens at end of string\n", __func__);
    return -1;
  }
  return 0;
}

guestfs_int_lvm_vg_list *
parse_command_line_vgs (void)
{
  char *out, *err;
  char *p, *pend;
  int r, i;
  guestfs_int_lvm_vg_list *ret;
  void *newp;

  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->guestfs_int_lvm_vg_list_len = 0;
  ret->guestfs_int_lvm_vg_list_val = NULL;

  r = command (&out, &err,
	       "lvm", "vgs",
	       "-o", lvm_vg_cols, "--unbuffered", "--noheadings",
	       "--nosuffix", "--separator", "\r", "--units", "b", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    free (err);
    free (ret);
    return NULL;
  }

  free (err);

  /* Tokenize each line of the output. */
  p = out;
  i = 0;
  while (p) {
    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    if (!*p) {			/* Empty line?  Skip it. */
      p = pend;
      continue;
    }

    /* Allocate some space to store this next entry. */
    newp = realloc (ret->guestfs_int_lvm_vg_list_val,
		    sizeof (guestfs_int_lvm_vg) * (i+1));
    if (newp == NULL) {
      reply_with_perror ("realloc");
      free (ret->guestfs_int_lvm_vg_list_val);
      free (ret);
      free (out);
      return NULL;
    }
    ret->guestfs_int_lvm_vg_list_val = newp;

    /* Tokenize the next entry. */
    r = lvm_tokenize_vg (p, &ret->guestfs_int_lvm_vg_list_val[i]);
    if (r == -1) {
      reply_with_error ("failed to parse output of 'vgs' command");
      free (ret->guestfs_int_lvm_vg_list_val);
      free (ret);
      free (out);
      return NULL;
    }

    ++i;
    p = pend;
  }

  ret->guestfs_int_lvm_vg_list_len = i;

  free (out);
  return ret;
}
static const char lvm_lv_cols[] = "lv_name,lv_uuid,lv_attr,lv_major,lv_minor,lv_kernel_major,lv_kernel_minor,lv_size,seg_count,origin,snap_percent,copy_percent,move_pv,lv_tags,mirror_log,modules";

static int lvm_tokenize_lv (char *str, guestfs_int_lvm_lv *r)
{
  char *tok, *p, *next;
  size_t i, j;

  if (!str) {
    fprintf (stderr, "%s: failed: passed a NULL string\n", __func__);
    return -1;
  }
  if (!*str || c_isspace (*str)) {
    fprintf (stderr, "%s: failed: passed a empty string or one beginning with whitespace\n", __func__);
    return -1;
  }
  tok = str;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_name");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->lv_name = strdup (tok);
  if (r->lv_name == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_uuid");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  for (i = j = 0; i < 32; ++j) {
    if (tok[j] == '\0') {
      fprintf (stderr, "%s: failed to parse UUID from '%s'\n", __func__, tok);
      return -1;
    } else if (tok[j] != '-')
      r->lv_uuid[i++] = tok[j];
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_attr");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->lv_attr = strdup (tok);
  if (r->lv_attr == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_major");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->lv_major) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_major");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_minor");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->lv_minor) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_minor");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_kernel_major");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->lv_kernel_major) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_kernel_major");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_kernel_minor");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->lv_kernel_minor) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_kernel_minor");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_size");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->lv_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "lv_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "seg_count");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->seg_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "seg_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "origin");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->origin = strdup (tok);
  if (r->origin == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "snap_percent");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (tok[0] == '\0')
    r->snap_percent = -1;
  else if (sscanf (tok, "%f", &r->snap_percent) != 1) {
    fprintf (stderr, "%s: failed to parse float '%s' from token %s\n", __func__, tok, "snap_percent");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "copy_percent");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (tok[0] == '\0')
    r->copy_percent = -1;
  else if (sscanf (tok, "%f", &r->copy_percent) != 1) {
    fprintf (stderr, "%s: failed to parse float '%s' from token %s\n", __func__, tok, "copy_percent");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "move_pv");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->move_pv = strdup (tok);
  if (r->move_pv == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_tags");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->lv_tags = strdup (tok);
  if (r->lv_tags == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "mirror_log");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->mirror_log = strdup (tok);
  if (r->mirror_log == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "modules");
    return -1;
  }
  p = strchrnul (tok, '\r');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->modules = strdup (tok);
  if (r->modules == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (tok != NULL) {
    fprintf (stderr, "%s: failed: extra tokens at end of string\n", __func__);
    return -1;
  }
  return 0;
}

guestfs_int_lvm_lv_list *
parse_command_line_lvs (void)
{
  char *out, *err;
  char *p, *pend;
  int r, i;
  guestfs_int_lvm_lv_list *ret;
  void *newp;

  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->guestfs_int_lvm_lv_list_len = 0;
  ret->guestfs_int_lvm_lv_list_val = NULL;

  r = command (&out, &err,
	       "lvm", "lvs",
	       "-o", lvm_lv_cols, "--unbuffered", "--noheadings",
	       "--nosuffix", "--separator", "\r", "--units", "b", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    free (err);
    free (ret);
    return NULL;
  }

  free (err);

  /* Tokenize each line of the output. */
  p = out;
  i = 0;
  while (p) {
    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    if (!*p) {			/* Empty line?  Skip it. */
      p = pend;
      continue;
    }

    /* Allocate some space to store this next entry. */
    newp = realloc (ret->guestfs_int_lvm_lv_list_val,
		    sizeof (guestfs_int_lvm_lv) * (i+1));
    if (newp == NULL) {
      reply_with_perror ("realloc");
      free (ret->guestfs_int_lvm_lv_list_val);
      free (ret);
      free (out);
      return NULL;
    }
    ret->guestfs_int_lvm_lv_list_val = newp;

    /* Tokenize the next entry. */
    r = lvm_tokenize_lv (p, &ret->guestfs_int_lvm_lv_list_val[i]);
    if (r == -1) {
      reply_with_error ("failed to parse output of 'lvs' command");
      free (ret->guestfs_int_lvm_lv_list_val);
      free (ret);
      free (out);
      return NULL;
    }

    ++i;
    p = pend;
  }

  ret->guestfs_int_lvm_lv_list_len = i;

  free (out);
  return ret;
}
