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
 * PV structure.
 *
 * @author rjones
 * @see GuestFS
 */
public class PV {
  public String pv_name;
  public String pv_uuid;
  public String pv_fmt;
  public long pv_size;
  public long dev_size;
  public long pv_free;
  public long pv_used;
  public String pv_attr;
  public long pv_pe_count;
  public long pv_pe_alloc_count;
  public String pv_tags;
  public long pe_start;
  public long pv_mda_count;
  public long pv_mda_free;
}
