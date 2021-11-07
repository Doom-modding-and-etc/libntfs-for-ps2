## Introduction

The NTFS-3G driver is an open source, freely available read/write NTFS driver
for Linux, FreeBSD, Mac OS X, NetBSD, Solaris and Haiku. It provides safe and
fast handling of the Windows XP, Windows Server 2003, Windows 2000, Windows
Vista, and Windows Server 2008 file systems.

The purpose of the project is to develop, continuously quality test and
support a trustable, featureful and high performance solution for hardware
platforms and operating systems whose users need to reliably interoperate
with NTFS. Besides this practical goal, the project also aims to explore
the limits of the hybrid, kernel/user space filesystem driver approach,
performance, reliability and feature richness per invested effort wise.

The driver is in STABLE status. The test methods, the test suites used
can be found at

```
http://ntfs-3g.org/quality.html
```

News, support answers, problem submission instructions, support and discussion
forums, performance numbers and other information are available on the project
web site at

```
http://ntfs-3g.org
```

For more details on the NTFS-3G project see the 'original' folder included
with this package.

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
 LIBS := -lntfs -lcdvd
````

For a more practical example of using NTFS in your application,
see the included `example` directory.

## TO DO:

add examples how to do and continue porting the library itself
