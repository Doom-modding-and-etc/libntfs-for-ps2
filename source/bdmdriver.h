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
#include <stdbool.h>


#define MX4SIO
#define ILink
#define USB
u8 read;	
u32 write;
float flush;
bool stop;



const bool bdmntfsread(struct bdmdevice *MX4SIO, struct bdmdevice *ILink, struct bdmdevice *USB, u32 sectors_read, u32 sectors);
unsigned int bdmntfswrite(struct bdmdevice *MX4SIO, struct bdmdevice *ILink, struct bdmdevice *USB);
const void bdmntfsflush(struct bdmdevice *MX4SIO, struct bdmdevice *ILink, struct bdmdevice *USB);
unsigned int bdmntfs(struct bdmedvice *MX4SIO, struct bdmdevice *ILink, struct bdmdevice *USB);
unsigned boolean();
