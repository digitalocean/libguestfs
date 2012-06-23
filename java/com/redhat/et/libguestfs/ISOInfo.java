/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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
 * Libguestfs ISOInfo structure.
 *
 * @author rjones
 * @see GuestFS
 */
public class ISOInfo {
  public String iso_system_id;
  public String iso_volume_id;
  public int iso_volume_space_size;
  public int iso_volume_set_size;
  public int iso_volume_sequence_number;
  public int iso_logical_block_size;
  public String iso_volume_set_id;
  public String iso_publisher_id;
  public String iso_data_preparer_id;
  public String iso_application_id;
  public String iso_copyright_file_id;
  public String iso_abstract_file_id;
  public String iso_bibliographic_file_id;
  public long iso_volume_creation_t;
  public long iso_volume_modification_t;
  public long iso_volume_expiration_t;
  public long iso_volume_effective_t;
}
