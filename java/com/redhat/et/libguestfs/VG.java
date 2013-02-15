/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2013 Red Hat Inc.
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

package com.redhat.et.libguestfs;

/**
 * VG structure.
 *
 * @author rjones
 * @see GuestFS
 */
public class VG {
  public String vg_name;
  public String vg_uuid;
  public String vg_fmt;
  public String vg_attr;
  public long vg_size;
  public long vg_free;
  public String vg_sysid;
  public long vg_extent_size;
  public long vg_extent_count;
  public long vg_free_count;
  public long max_lv;
  public long max_pv;
  public long pv_count;
  public long lv_count;
  public long snap_count;
  public long vg_seqno;
  public String vg_tags;
  public long vg_mda_count;
  public long vg_mda_free;
}
