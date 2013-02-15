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
 * LV structure.
 *
 * @author rjones
 * @see GuestFS
 */
public class LV {
  public String lv_name;
  public String lv_uuid;
  public String lv_attr;
  public long lv_major;
  public long lv_minor;
  public long lv_kernel_major;
  public long lv_kernel_minor;
  public long lv_size;
  public long seg_count;
  public String origin;
  /* The next field is [0..100] or -1 meaning 'not present': */
  public float snap_percent;
  /* The next field is [0..100] or -1 meaning 'not present': */
  public float copy_percent;
  public String move_pv;
  public String lv_tags;
  public String mirror_log;
  public String modules;
}
