# LIBNTFS FOR PLAYSTATION 2
# Copyright (c) 2021 André Guilherme Mendes da luz bastos based on libsmb2 makefile

IOP_LIB = libntfs.a

EE_LIB = libntfs.a

IOP_CFLAGS += -Wall -Os -I../include -I../include/

EE_CFLAGS += -Wall -Os -I../include -I../include/

IOP_OBJS = source/acls.o source/atrrib.o source/attrlist.o \
source/bdmdriver.o source/bitmap.o source/bootsect.o \
source/cache.o source/cache2.o source/collate.o source/compat.o source/compress.o \
source/debug.o source/device_io.o source/device.o\
source/ea.o source/efs.o source/inode.o source/lcnalloc.o \
source/logfile.o source/logfile.o \
source/mft.o source/misc.o source/mst.o \
source/object_id.o source/realpath.o source/reparse.o source/runlist.o \
source/unistr.o source/volume.o source/xattrs.o \

#Solve these EE side: source/bdmdriver.o source/cache2.o source/misc.o source/realpath.o source/reparse.o source/runlist.o source/unistr.o
EE_OBJS = source/compat.o source/device_io.o source/mst.o 

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