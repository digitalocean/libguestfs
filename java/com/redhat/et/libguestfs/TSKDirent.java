/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/java.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2016 Red Hat Inc.
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
 * TSKDirent structure.
 *
 * @author rjones
 * @see GuestFS
 */
public class TSKDirent {
  public long tsk_inode;
  public char tsk_type;
  public long tsk_size;
  public String tsk_name;
  public int tsk_flags;
  public long tsk_atime_sec;
  public long tsk_atime_nsec;
  public long tsk_mtime_sec;
  public long tsk_mtime_nsec;
  public long tsk_ctime_sec;
  public long tsk_ctime_nsec;
  public long tsk_crtime_sec;
  public long tsk_crtime_nsec;
  public long tsk_nlink;
  public String tsk_link;
  public long tsk_spare1;
}
