#ifndef __GCTYPES_H__
#define __GCTYPES_H__

/*! \file gctypes.h 
\brief Data type definitions
*/ 

#include <stdbool.h>
#include <stdint.h>
#include <tamtypes.h>
#include "types.h"
#ifdef __cplusplus
   extern "C" {
#endif /* __cplusplus */

/*+----------------------------------------------------------------------------------------------+*/
typedef unsigned char u8;									///< 8bit unsigned integer
typedef unsigned short u16;								///< 16bit unsigned integer									///< 32bit unsigned integer
typedef unsigned long long u64;						///< 64bit unsigned integer
/*+----------------------------------------------------------------------------------------------+*/
typedef signed char s8;										///< 8bit signed integer
typedef signed short s16;									///< 16bit signed integer									///< 32bit signed integer
typedef signed long long s64;							///< 64bit signed integer
/*+----------------------------------------------------------------------------------------------+*/
typedef volatile unsigned char vu8;				///< 8bit unsigned volatile integer
typedef volatile unsigned short vu16;			///< 16bit unsigned volatile integer
typedef volatile unsigned long long vu64;	///< 64bit unsigned volatile integer
/*+----------------------------------------------------------------------------------------------+*/
typedef volatile signed char vs8;					///< 8bit signed volatile integer
typedef volatile signed short vs16;				///< 16bit signed volatile integer
typedef volatile signed long long vs64;		///< 64bit signed volatile integer
/*+----------------------------------------------------------------------------------------------+*/
// fixed point math typedefs
typedef s16 sfp16;                              ///< signed 8:8 fixed point
typedef s32 sfp32;                              ///< signed 20:8 fixed point
typedef u16 ufp16;                              ///< unsigned 8:8 fixed point
typedef u32 ufp32;                              ///< unsigned 24:8 fixed point
/*+----------------------------------------------------------------------------------------------+*/
typedef float f32;
typedef double f64;
typedef volatile float vf32;
typedef volatile double vf64;
typedef uint32_t *sec_t;
typedef bool (* FN_MEDIUM_STARTUP)(void) ;
typedef bool (* FN_MEDIUM_ISINSERTED)(void) ;
typedef bool (* FN_MEDIUM_READSECTORS)(sec_t sector, sec_t numSectors, void* buffer) ;
typedef bool (* FN_MEDIUM_WRITESECTORS)(sec_t sector, sec_t numSectors, const void* buffer) ;
typedef bool (* FN_MEDIUM_CLEARSTATUS)(void) ;
typedef bool (* FN_MEDIUM_SHUTDOWN)(void) ;
//important types
typedef unsigned long __ino_t;
typedef __ino_t *ino_t;
typedef u32 mutex_t;
typedef mode_t *__mode_t;
typedef dev_t *__dev_t;
typedef long __off64_t;
typedef unsigned long __syscall_ulong_t;
typedef long __blkcnt64_t;
typedef long __blkcnt_t;
typedef unsigned long __nlink_t;
typedef long __blksize_t;
struct _reent;

typedef long __time_t;
typedef unsigned long __ino64_t;
/*+----------------------------------------------------------------------------------------------+*/
// alias type typedefs
#define FIXED s32                               ///< Alias type for sfp32
/*+----------------------------------------------------------------------------------------------+*/
// boolean defines
#ifndef boolean
#define boolean  u8
#endif
/*+----------------------------------------------------------------------------------------------+*/
#ifndef TRUE
#define TRUE 1                                  ///< True
#endif
/*+----------------------------------------------------------------------------------------------+*/
#ifndef FALSE
#define FALSE 0                                 ///< False
#endif
/*+----------------------------------------------------------------------------------------------+*/
#ifndef NULL
#define NULL			0                        ///< Pointer to 0
#endif
/*+----------------------------------------------------------------------------------------------+*/
#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN  3412
#endif /* LITTLE_ENDIAN */
/*+----------------------------------------------------------------------------------------------+*/
#ifndef BIG_ENDIAN
#define BIG_ENDIAN     1234
#endif /* BIGE_ENDIAN */
/*+----------------------------------------------------------------------------------------------+*/
#ifndef BYTE_ORDER
#define BYTE_ORDER     BIG_ENDIAN
#endif /* BYTE_ORDER */
/*+----------------------------------------------------------------------------------------------+*/
#define ARGV_MAGIC 0x5f617267
#define FEATURE_MEDIUM_CANREAD      0x00000001
#define FEATURE_MEDIUM_CANWRITE     0x00000002
#define FEATURE_GAMECUBE_SLOTA      0x00000010
#define FEATURE_GAMECUBE_SLOTB      0x00000020
#define FEATURE_GAMECUBE_DVD        0x00000040
#define FEATURE_GAMECUBE_PORT2      0x00000080
#define FEATURE_WII_USB             0x00000200
#define FEATURE_WII_DVD             0x00000400


//!	argv structure
/*!	\struct __argv
	structure used to set up argc/argv
*/
struct __argv {
	int argvMagic;		//!< argv magic number, set to 0x5f617267 ('_arg') if valid 
	char *commandLine;	//!< base address of command line, set of null terminated strings
	int length;//!< total length of command line
	int argc;
	char **argv;
	char **endARGV;
};

//!	Default location for the system argv structure.
extern struct __argv *__system_argv;

struct DISC_INTERFACE_STRUCT {
	unsigned long			ioType ;
	unsigned long			features ;
	FN_MEDIUM_STARTUP		startup ;
	FN_MEDIUM_ISINSERTED	isInserted ;
	FN_MEDIUM_READSECTORS	readSectors ;
	FN_MEDIUM_WRITESECTORS	writeSectors ;
	FN_MEDIUM_CLEARSTATUS	clearStatus ;
	FN_MEDIUM_SHUTDOWN		shutdown ;
} ;

struct stat
  {
    __dev_t st_dev;		/* Device.  */
# ifdef __x86_64__
    __ino64_t st_ino;		/* File serial number.  */
    __nlink_t st_nlink;		/* Link count.  */
    __mode_t st_mode;		/* File mode.  */
# else
    unsigned int __pad1;
    __ino_t __st_ino;			/* 32bit file serial number.	*/
    __mode_t st_mode;			/* File mode.  */
    __nlink_t st_nlink;			/* Link count.  */
# endif
    __uid_t st_uid;		/* User ID of the file's owner.	*/
    __gid_t st_gid;		/* Group ID of the file's group.*/
# ifdef __x86_64__
    int __pad0;
    __dev_t st_rdev;		/* Device number, if device.  */
    __off_t st_size;		/* Size of file, in bytes.  */
# else
    __dev_t st_rdev;			/* Device number, if device.  */
    unsigned int __pad2;
    __off64_t st_size;			/* Size of file, in bytes.  */
# endif
    __blksize_t st_blksize;	/* Optimal block size for I/O.  */
    __blkcnt64_t st_blocks;	/* Nr. 512-byte blocks allocated.  */
# ifdef __USE_XOPEN2K8
    /* Nanosecond resolution timestamps are stored in a format
       equivalent to 'struct timespec'.  This is the type used
       whenever possible but the Unix namespace rules do not allow the
       identifier 'timespec' to appear in the <sys/stat.h> header.
       Therefore we have to handle the use of this header in strictly
       standard-compliant sources special.  */
    struct timespec st_atim;		/* Time of last access.  */
    struct timespec st_mtim;		/* Time of last modification.  */
    struct timespec st_ctim;		/* Time of last status change.  */
# else
    __time_t st_atime;			/* Time of last access.  */
    __syscall_ulong_t st_atimensec;	/* Nscecs of last access.  */
    __time_t st_mtime;			/* Time of last modification.  */
    __syscall_ulong_t st_mtimensec;	/* Nsecs of last modification.  */
    __time_t st_ctime;			/* Time of last status change.  */
    __syscall_ulong_t st_ctimensec;	/* Nsecs of last status change.  */
# endif
# ifdef __x86_64__
    __syscall_slong_t __glibc_reserved[3];
# else
    __ino64_t st_ino;			/* File serial number.		*/
# endif
  };
#endif


typedef struct DISC_INTERFACE_STRUCT DISC_INTERFACE;

#ifdef __cplusplus
   }
#endif /* __cplusplus */

/* END OF FILE */
