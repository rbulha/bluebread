# default to compiling with debug information
CCOPTS ?= -g -qq -pdsw225 

CC = C:/PROGRA~2/TEXASI~1/ccsv4/tools/compiler/msp430/bin/cl430 -c --obj_directory=objs/ -D__MSP430G2452__  -vmsp -I C:/PROGRA~2/TEXASI~1/ccsv4/tools/compiler/msp430/include 
AR = C:/PROGRA~2/TEXASI~1/ccsv4/tools/compiler/msp430/bin/ar430 rq
RM = cmd.exe /q /c del /f
MKDIR = mkdir

# create object sub-directory, if necessary
ifeq (,$(wildcard objs/))
    $(shell $(MKDIR) objs\ )
endif

all: csl.lib

objs\CSL_init.obj: CSL_init.c
	@echo cl430 $< ...
	$(CC) $(CCOPTS) -I "C:\Program Files (x86)\Texas Instruments\grace_1_00_01_83\packages" -I "C:\Program Files (x86)\Texas Instruments\xdctools_3_21_01_57_msp430\packages" $<
	
objs\WDTplus_init.obj: WDTplus_init.c
	@echo cl430 $< ...
	$(CC) $(CCOPTS) -I "C:\Program Files (x86)\Texas Instruments\grace_1_00_01_83\packages" -I "C:\Program Files (x86)\Texas Instruments\xdctools_3_21_01_57_msp430\packages" $<
	
objs\GPIO_init.obj: GPIO_init.c
	@echo cl430 $< ...
	$(CC) $(CCOPTS) -I "C:\Program Files (x86)\Texas Instruments\grace_1_00_01_83\packages" -I "C:\Program Files (x86)\Texas Instruments\xdctools_3_21_01_57_msp430\packages" $<
	
objs\BCSplus_init.obj: BCSplus_init.c
	@echo cl430 $< ...
	$(CC) $(CCOPTS) -I "C:\Program Files (x86)\Texas Instruments\grace_1_00_01_83\packages" -I "C:\Program Files (x86)\Texas Instruments\xdctools_3_21_01_57_msp430\packages" $<
	
objs\USI_init.obj: USI_init.c
	@echo cl430 $< ...
	$(CC) $(CCOPTS) -I "C:\Program Files (x86)\Texas Instruments\grace_1_00_01_83\packages" -I "C:\Program Files (x86)\Texas Instruments\xdctools_3_21_01_57_msp430\packages" $<
	
objs\Timer0_A3_init.obj: Timer0_A3_init.c
	@echo cl430 $< ...
	$(CC) $(CCOPTS) -I "C:\Program Files (x86)\Texas Instruments\grace_1_00_01_83\packages" -I "C:\Program Files (x86)\Texas Instruments\xdctools_3_21_01_57_msp430\packages" $<
	
objs\System_init.obj: System_init.c
	@echo cl430 $< ...
	$(CC) $(CCOPTS) -I "C:\Program Files (x86)\Texas Instruments\grace_1_00_01_83\packages" -I "C:\Program Files (x86)\Texas Instruments\xdctools_3_21_01_57_msp430\packages" $<
	
csl.lib: objs\CSL_init.obj objs\WDTplus_init.obj objs\GPIO_init.obj objs\BCSplus_init.obj objs\USI_init.obj objs\Timer0_A3_init.obj objs\System_init.obj
	@ echo ar430 $@ $< ...
	$(AR) $@ $^

clean:
	-@$(RM) csl.lib
	-@$(RM) objs\CSL_init.obj
	-@$(RM) objs\WDTplus_init.obj
	-@$(RM) objs\GPIO_init.obj
	-@$(RM) objs\BCSplus_init.obj
	-@$(RM) objs\USI_init.obj
	-@$(RM) objs\Timer0_A3_init.obj
	-@$(RM) objs\System_init.obj



