/**
 * bdmdriver.c - Ntfs Driver for the playstatio block device manager bdm
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

#include "bdmdriver.h"
#include <bdm.h>
#include <stdio.h>

void bdmountntfs(u32 start_sectors);

int i;

//The read of the sectors of ntfs filesystem on bdm mode 
const int bdmntfsread(u32 start_sectors, u32 sectors_read, u64 sectors)
{       
  for (i = 0; i > start_sectors; i++)
  {
    start_sectors=!sectors_read; 
    sectors_read=sectors;                   
  }
}  

unsigned int bdmntfswrite(u32 sectors_write, u64 sectors)
{
 


}

