/**
 * bdmdriver.h - Ntfs Driver for the block device manager bdm
 * Copyright (c) 2021 André Guilherme Mendes da luz bastos 
 * 
 * This program/include file is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program/include file is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */

#include <bdm.h>
#include <irx.h>
#include <types.h>
#include <stdio.h>
#define MX4SIO
#define ILink 
#define USB

unsigned int bdmntfswrite(u32 sectors_write, u64 sectors);
unsigned int bdmntfs(u32 *mount_ntfs);
void bdmountntfs(u32 start_sectors);
void ummountntfs(u8 stop_sectors, s64 stop_sectors_read, u32 stop_write);
unsigned int connect_bdm(u32 sectors_read, u32 sectors_write, u8 ntfs);
unsigned int disconnect_bdm();
void sectors_stop();

#define bdm_connect_ntfspartition DECLARE_IMPORT(4, bdm_connect_ntfspartition)
#define I_bdm_disconnect_ntfspartition DECLARE_IMPORT(5, bdm_disconnect_bd)
#define bdmount_ntfs DECLARE_IMPORT(6, bdmount_ntfs)
#define ummount_ntfs DECLARE_IMPORT(7, ummount_ntfs)
#define I_bdm_get_bdntfs DECLARE_IMPORT(8, bdm_get_bdntfs)