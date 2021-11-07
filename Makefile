# LIBNTFS FOR PLAYSTATION 2
# Copyright (c) 2021 André Guilherme Mendes da luz bastos based on libsmb2 makefile

IOP_CFLAGS += -Wall -Os -I. -I../include -I../include/ntfs

IOP_LIB = libntfs.a
IOP_OBJS = source/bdmdriver.o


install: $(IOP_LIB)
ifeq ($(PS2SDK),)
	@echo "$PS2SDK is not set. Can not install libntfs."
	@exit 1
endif
	@echo Copying...
	@cp -frv include/ntfs.h $(PS2SDK)/iop/include/
	@cp -f $(IOP_LIB) $(PS2SDK)/iop/lib
	@rm -f -r $(IOP_LIB) $(IOP_OBJS)
	@echo Done!

include $(PS2SDK)/Defs.make
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.iopglobal
