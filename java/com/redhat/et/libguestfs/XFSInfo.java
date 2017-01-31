/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/java.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
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
 * XFSInfo structure.
 *
 * @author rjones
 * @see GuestFS
 */
public class XFSInfo {
  public String xfs_mntpoint;
  public int xfs_inodesize;
  public int xfs_agcount;
  public int xfs_agsize;
  public int xfs_sectsize;
  public int xfs_attr;
  public int xfs_blocksize;
  public long xfs_datablocks;
  public int xfs_imaxpct;
  public int xfs_sunit;
  public int xfs_swidth;
  public int xfs_dirversion;
  public int xfs_dirblocksize;
  public int xfs_cimode;
  public String xfs_logname;
  public int xfs_logblocksize;
  public int xfs_logblocks;
  public int xfs_logversion;
  public int xfs_logsectsize;
  public int xfs_logsunit;
  public int xfs_lazycount;
  public String xfs_rtname;
  public int xfs_rtextsize;
  public long xfs_rtblocks;
  public long xfs_rtextents;
}
