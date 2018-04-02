/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED
 *          from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2018 Red Hat Inc.
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

#include <config.h>

#include <stdio.h>

#include "guestfs.h"
#include "guestfs-internal.h"

struct uefi_firmware
guestfs_int_uefi_aarch64_firmware[] = {
  { "/usr/share/AAVMF/AAVMF_CODE.fd",
    "/usr/share/AAVMF/AAVMF_CODE.verbose.fd",
    "/usr/share/AAVMF/AAVMF_VARS.fd",
    0
  },
  { "/usr/share/edk2/aarch64/QEMU_EFI-pflash.raw",
    NULL,
    "/usr/share/edk2/aarch64/vars-template-pflash.raw",
    0
  },
};

struct uefi_firmware
guestfs_int_uefi_i386_firmware[] = {
  { "/usr/share/edk2.git/ovmf-ia32/OVMF_CODE-pure-efi.fd",
    NULL,
    "/usr/share/edk2.git/ovmf-ia32/OVMF_VARS-pure-efi.fd",
    0
  },
};

struct uefi_firmware
guestfs_int_uefi_x86_64_firmware[] = {
  { "/usr/share/OVMF/OVMF_CODE.fd",
    NULL,
    "/usr/share/OVMF/OVMF_VARS.fd",
    0
  },
  { "/usr/share/OVMF/OVMF_CODE.secboot.fd",
    NULL,
    "/usr/share/OVMF/OVMF_VARS.fd",
    UEFI_FLAG_SECURE_BOOT_REQUIRED
  },
  { "/usr/share/edk2/ovmf/OVMF_CODE.fd",
    NULL,
    "/usr/share/edk2/ovmf/OVMF_VARS.fd",
    0
  },
  { "/usr/share/qemu/ovmf-x86_64-code.bin",
    NULL,
    "/usr/share/qemu/ovmf-x86_64-vars.bin",
    0
  },
};
