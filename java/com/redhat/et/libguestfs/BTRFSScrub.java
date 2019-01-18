/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/java.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2019 Red Hat Inc.
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
 * BTRFSScrub structure.
 *
 * @author rjones
 * @see GuestFS
 */
public class BTRFSScrub {
  public long btrfsscrub_data_extents_scrubbed;
  public long btrfsscrub_tree_extents_scrubbed;
  public long btrfsscrub_data_bytes_scrubbed;
  public long btrfsscrub_tree_bytes_scrubbed;
  public long btrfsscrub_read_errors;
  public long btrfsscrub_csum_errors;
  public long btrfsscrub_verify_errors;
  public long btrfsscrub_no_csum;
  public long btrfsscrub_csum_discards;
  public long btrfsscrub_super_errors;
  public long btrfsscrub_malloc_errors;
  public long btrfsscrub_uncorrectable_errors;
  public long btrfsscrub_unverified_errors;
  public long btrfsscrub_corrected_errors;
  public long btrfsscrub_last_physical;
}
