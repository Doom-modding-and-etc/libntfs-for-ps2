# LIBNTFS FOR PLAYSTATION 2
# Copyright (c) 2021 André Guilherme Mendes da luz bastos based on libsmb2 makefile

IOP_LIB = libntfs.a

EE_LIB = libntfs.a

IOP_CFLAGS += -Wall -Os -I../include -I../include/ -std=c99

EE_CFLAGS += -Wall -Os -I../include -I../include/

IOP_OBJS = source/acls.o source/atrrib.o source/attrlist.o \
source/bdmdriver.o source/bitmap.o source/bootsect.o \
source/cache.o source/collate.o source/compat.o source/compress.o \
source/debug.o source/device_io.o source/device.o \
source/ea.o source/efs.o \
source/lcnalloc.o source/logfile.o source/logging.o \
source/mft.o source/misc.o source/mst.o \
source/ntfs.o source/ntfsfile.o source/ntfsdir.o source/ntfsinternal.o \
source/object_id.o \
source/realpath.o source/reparse.o source/runlist.o \
source/unistr.o source/volume.o source/xattrs.o \

#Solve these EE side: dir.o source/cache2.o source/misc.o source/realpath.o source/reparse.o source/runlist.o source/unistr.o
EE_OBJS = source/ee/acls.o source/ee/attrlist.o \
source/ee/bitmap.o source/ee/bootsect.o \
source/ee/cache.o source/ee/collate.o source/ee/compat.o source/ee/compress.o \
source/ee/debug.o source/ee/device_io.o source/ee/device.o \
source/ee/ea.o source/ee/efs.o \
source/ee/inode.o \
source/ee/lcnalloc.o source/ee/logfile.o source/ee/logging.o \
source/ee/mft.o source/ee/misc.o \
source/ee/object_id.o \
source/ee/realpath.o source/ee/reparse.o source/ee/runlist.o \
source/ee/unistr.o \
source/ee/volume.o \
source/ee/xattrs.o

IOP: $(IOP_LIB) 
ifeq ($(PS2DEV),)
	@echo "$PS2DEV ENVIROMENT is not set. Could not install libntfs."
	@exit 1
endif
	@echo Copying...
	@cp -frv include/ntfs.h $(PS2SDK)/iop/include/
	@cp -f $(IOP_LIB) $(PS2SDK)/iop/lib
	@echo Done!

EE: $(EE_LIB)
ifeq ($(PS2DEV),)
	@echo "$PS2DEV ENVIROMENT is not set. Could not install libntfs."
	@exit 1
endif
	@echo Copying...
	@cp -frv include/ee/ntfs.h $(PS2SDK)/ee/include/
	@cp -f $(EE_LIB) $(PS2SDK)/ee/lib
	@echo Done!
	
clean:
	@rm -f -r $(IOP_LIB) $(IOP_OBJS) $(IOP_OBJS_DIR)
	@rm -f -r $(EE_LIB) $(EE_OBJS) 

install: IOP EE clean

include $(PS2SDK)/Defs.make
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.iopglobal
include $(PS2SDK)/samples/Makefile.eeglobal 