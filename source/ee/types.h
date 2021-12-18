/*
 * types.h - Misc type definitions not related to on-disk structure.  
 *           Originated from the Linux-NTFS project.
 *
 * Copyright (c) 2000-2004 Anton Altaparmakov
 * Copyright (c) 2021 André Guilherme
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
 * along with this program (in the main directory of the NTFS-3G
 * distribution in the file COPYING); if not, write to the Free Software
 * Foundation,Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _NTFS_TYPES_H
#define _NTFS_TYPES_H
#define S_IRWXO 00007
#define S_IROTH 00004
#define S_IWOTH 00002
#define S_IXOTH 00001
#define S_IRWXG 00070
#define S_IRGRP 00040
#define S_IWGRP 00020
#define S_IXGRP 00010
#define S_IRWXU 00700
#define S_IRUSR 00400
#define S_IWUSR 00200
#define S_IXUSR 00100
#define S_IFMT  00170000
#define S_IFSOCK 0140000
#define S_IFLNK	 0120000
#define S_IFREG  0100000
#define S_IFBLK  0060000
#define S_IFDIR  0040000
#define S_IFCHR  0020000
#define S_IFIFO  0010000
#define S_ISUID  0004000
#define S_ISGID  0002000
#define S_ISVTX  0001000
# define SEEK_SET	0	/* Seek from beginning of file.  */
# define SEEK_CUR	1	/* Seek from current position.  */
# define SEEK_END	2	/* Seek from end of file.  */
#define O_WRONLY	00000001
#define O_RDONLY 00
#define STATUS_OK				(0)
#define STATUS_ERROR				(-1)
#define STATUS_RESIDENT_ATTRIBUTE_FILLED_MFT	(-2)
#define STATUS_KEEP_SEARCHING			(-3)
#define STATUS_NOT_FOUND			(-4)
#define	EPERM		 1	/* Operation not permitted */
#define	ENOENT		 2	/* No such file or directory */
#define	ESRCH		 3	/* No such process */
#define	EINTR		 4	/* Interrupted system call */
#define	EIO		 5	/* I/O error */
#define	ENXIO		 6	/* No such device or address */
#define	E2BIG		 7	/* Argument list too long */
#define	ENOEXEC		 8	/* Exec format error */
#define	EBADF		 9	/* Bad file number */
#define	ECHILD		10	/* No child processes */
#define	EAGAIN		11	/* Try again */
#define	ENOMEM		12	/* Out of memory */
#define	EACCES		13	/* Permission denied */
#define	EFAULT		14	/* Bad address */
#define	ENOTBLK		15	/* Block device required */
#define	EBUSY		16	/* Device or resource busy */
#define	EEXIST		17	/* File exists */
#define	EXDEV		18	/* Cross-device link */
#define	ENODEV		19	/* No such device */
#define	ENOTDIR		20	/* Not a directory */
#define	EISDIR		21	/* Is a directory */
#define	EINVAL		22	/* Invalid argument */
#define	ENFILE		23	/* File table overflow */
#define	EMFILE		24	/* Too many open files */
#define	ENOTTY		25	/* Not a typewriter */
#define	ETXTBSY		26	/* Text file busy */
#define	EFBIG		27	/* File too large */
#define	ENOSPC		28	/* No space left on device */
#define	ESPIPE		29	/* Illegal seek */
#define	EROFS		30	/* Read-only file system */
#define	EMLINK		31	/* Too many links */
#define	EPIPE		32	/* Broken pipe */
#define	EDOM		33	/* Math argument out of domain of func */
#define	ERANGE		34	/* Math result not representable */
#define O_TRUNC        0x0400
#define O_CREAT        0x0200
#define O_APPEND       0x0100
#define ST_RDONLY

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#if HAVE_STDINT_H || !HAVE_CONFIG_H
#include <stdint.h>
#endif

#include <sys/types.h>
#include <sys/reent.h>
#include <stdio.h>
#include <limits.h>
#define	LC_ALL		  __LC_ALL
#define __LC_ALL		6
#include <tamtypes.h>
typedef struct mode_t *mode;
typedef unsigned int size_t;
typedef unsigned long __fsfilcnt_t;
typedef uint64_t u64;
typedef __ssize_t ssize_t;
typedef u16 le16;
typedef u32 le32;
typedef u64 le64;
typedef u16 be16;
typedef u32 be32;
typedef u64 be64;

/*
 * Declare s{l,b}e{16,32,64} to be unsigned because we do not want sign
 * extension on BE architectures.
 */
typedef u16 sle16;
typedef u32 sle32;
typedef u64 sle64;
typedef u16 sbe16;
typedef u32 sbe32;
typedef u64 sbe64;
typedef le16 ntfschar;			/* 2-byte Unicode character type. */
#define UCHAR_T_SIZE_BITS 1

/*
 * Clusters are signed 64-bit values on NTFS volumes.  We define two types, LCN
 * and VCN, to allow for type checking and better code readability.
 */
typedef s64 VCN;
typedef sle64 leVCN;
typedef s64 LCN;
typedef sle64 leLCN;

/*
 * The NTFS journal $LogFile uses log sequence numbers which are signed 64-bit
 * values.  We define our own type LSN, to allow for type checking and better
 * code readability.
 */
typedef s64 LSN;
typedef sle64 leLSN;

/*
 * Cygwin has a collision between our BOOL and <windef.h>'s
 * As long as this file will be included after <windows.h> were fine.
 */
#ifndef _WINDEF_H
/**
 * enum BOOL - These are just to make the code more readable...
 */
typedef enum {
#ifndef FALSE
	FALSE = 0,
#endif
#ifndef NO
	NO = 0,
#endif
#ifndef ZERO
	ZERO = 0,
#endif
#ifndef TRUE
	TRUE = 1,
#endif
#ifndef YES
	YES = 1,
#endif
#ifndef ONE
	ONE = 1,
#endif
} BOOL;
#endif /* defined _WINDEF_H */

/**
 * enum IGNORE_CASE_BOOL -
 */
typedef enum {
	CASE_SENSITIVE = 0,
	IGNORE_CASE = 1,
} IGNORE_CASE_BOOL;

/*
 *	Force alignment in a struct if required by processor
 */
union ALIGNMENT {
	u64 u64align;
	void *ptralign;
} ;

struct passwd
{

  char *pw_name;		/* Username.  */
  char *pw_passwd;		/* Hashed passphrase, if shadow database
                                   not in use (see shadow.h).  */
  __uid_t pw_uid;		/* User ID.  */
  __gid_t pw_gid;		/* Group ID.  */
  char *pw_gecos;		/* Real name.  */
  char *pw_dir;			/* Home directory.  */
  char *pw_shell;		/* Shell program.  */
};
struct group
{
 char *gr_name;		/* Group name.	*/
 char *gr_passwd;		/* Password.	*/
 __gid_t gr_gid;		/* Group ID.	*/
 char **gr_mem;		/* Member list.	*/
};
struct statvfs
  {
    unsigned long int f_bsize;
    unsigned long int f_frsize;
#ifndef __USE_FILE_OFFSET64
    __fsblkcnt_t f_blocks;
    __fsblkcnt_t f_bfree;
    __fsblkcnt_t f_bavail;
    __fsfilcnt_t f_files;
    __fsfilcnt_t f_ffree;
    __fsfilcnt_t f_favail;
#else
    __fsblkcnt64_t f_blocks;
    __fsblkcnt64_t f_bfree;
    __fsblkcnt64_t f_bavail;
    __fsfilcnt64_t f_files;
    __fsfilcnt64_t f_ffree;
    __fsfilcnt64_t f_favail;
#endif
    unsigned long int f_fsid;
#ifdef _STATVFSBUF_F_UNUSED
    int __f_unused;
#endif
    unsigned long int f_flag;
    unsigned long int f_namemax;
    int __f_spare[6];
  };

#ifdef __USE_LARGEFILE64
struct statvfs64
  {
    unsigned long int f_bsize;
    unsigned long int f_frsize;
    __fsblkcnt64_t f_blocks;
    __fsblkcnt64_t f_bfree;
    __fsblkcnt64_t f_bavail;
    __fsfilcnt64_t f_files;
    __fsfilcnt64_t f_ffree;
    __fsfilcnt64_t f_favail;
    unsigned long int f_fsid;
#ifdef _STATVFSBUF_F_UNUSED
    int __f_unused;
#endif
    unsigned long int f_flag;
    unsigned long int f_namemax;
    int __f_spare[6];
  };
#endif
/* The opaque type of streams.  This is the definition used elsewhere.  */
/* Standard streams.  */


#endif /*_NTFS_TYPES_H */
