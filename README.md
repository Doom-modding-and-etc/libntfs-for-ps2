## INTRODUCTION

The NTFS-3G driver is an open source, freely available read/write NTFS driver
for Linux, FreeBSD, macOS, NetBSD, OpenIndiana, QNX and Haiku. It provides
safe and fast handling of the Windows XP, Windows Server 2003, Windows 2000,
Windows Vista, Windows Server 2008, Windows 7, Windows 8, Windows Server 2012,
Windows Server 2016, Windows 10 and Windows Server 2019 NTFS file systems.

The purpose of the project is to develop, quality assurance and support a
trustable, featureful and high performance solution for hardware platforms
and operating systems whose users need to reliably interoperate with NTFS.
Besides this practical goal, the project also aims to explore the limits
of the hybrid, kernel/user space filesystem driver approach, performance,
reliability and feature richness per invested effort wise.

Besides the common file system features, NTFS-3G has support for file
ownership and permissions, POSIX ACLs, junction points, extended attributes
and creating internally compressed files (parameter files in the directory
.NTFS-3G may be required to enable them). The new compressed file formats
available in Windows 10 can also be read through a plugin.

News, support answers, problem submission instructions, support and discussion
forums, and other information are available on the project web site at

```
https://github.com/tuxera/ntfs-3g/wiki
```

The project has been funded, supported and maintained since 2008 by Tuxera:

```
https://tuxera.com
```
## LICENSES

All the NTFS related components: the file system drivers, the ntfsprogs
utilities and the shared library libntfs-3g are distributed under the terms
of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version. See the included file COPYING.

The fuse-lite library is distributed under the terms of the GNU LGPLv2.
See the included file COPYING.LIB.

## Compiling and Installing

Make sure you have [PS2DEV ENVIROMENT](https://github.com/ps2dev/ps2dev).
Then type:

````bash
 make install   
````

## Usage

NTFS related routines can be accessed by adding the following line to your
source file(s).

````c
 #include <ntfs.h>
````

When compiling you must also link against the libntfs. To do this add `-lntfs`
to the `LIBS` section of your application Makefile. For example:

````makefile
 IOP_LIBS = -lntfs -lcdvd
````

For a more practical example of using NTFS in your application,
see the included `example` directory.

## TO DO:
add examples for how to do and continue porting the library itself
