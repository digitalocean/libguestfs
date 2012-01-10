/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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

#ifndef PREPOPTS_H

struct prep {
  const char *name;             /* eg. "fs" */

  size_t nr_params;             /* optional parameters */
  struct prep_param *params;

  const char *shortdesc;        /* short description */
  const char *longdesc;         /* long description */

                                /* functions to implement it */
  void (*prelaunch) (const char *filename, prep_data *);
  void (*postlaunch) (const char *filename, prep_data *, const char *device);
};

struct prep_param {
  const char *pname;            /* parameter name */
  const char *pdefault;         /* parameter default */
  const char *pdesc;            /* parameter description */
};

extern const struct prep preps[];
#define NR_PREPS 7

extern void prep_prelaunch_disk (const char *filename, prep_data *data);
extern void prep_postlaunch_disk (const char *filename, prep_data *data, const char *device);

extern void prep_prelaunch_part (const char *filename, prep_data *data);
extern void prep_postlaunch_part (const char *filename, prep_data *data, const char *device);

extern void prep_prelaunch_fs (const char *filename, prep_data *data);
extern void prep_postlaunch_fs (const char *filename, prep_data *data, const char *device);

extern void prep_prelaunch_lv (const char *filename, prep_data *data);
extern void prep_postlaunch_lv (const char *filename, prep_data *data, const char *device);

extern void prep_prelaunch_lvfs (const char *filename, prep_data *data);
extern void prep_postlaunch_lvfs (const char *filename, prep_data *data, const char *device);

extern void prep_prelaunch_bootroot (const char *filename, prep_data *data);
extern void prep_postlaunch_bootroot (const char *filename, prep_data *data, const char *device);

extern void prep_prelaunch_bootrootlv (const char *filename, prep_data *data);
extern void prep_postlaunch_bootrootlv (const char *filename, prep_data *data, const char *device);


#endif /* PREPOPTS_H */
