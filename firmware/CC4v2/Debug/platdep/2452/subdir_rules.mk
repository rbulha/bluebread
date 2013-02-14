################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
platdep/2452/gpio.obj: ../platdep/2452/gpio.c $(GEN_OPTS) $(GEN_SRCS) $(CFG_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmsp -g --define=__MSP430G2452__ --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="D:/Documents and Settings/Rogerio/Meus documentos/workspace/workspace4.2/Bluebread_2452/platdep/include" --include_path="D:/Documents and Settings/Rogerio/Meus documentos/workspace/workspace4.2/Bluebread_2452/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="platdep/2452/gpio.pp" --obj_directory="platdep/2452" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

platdep/2452/serial.obj: ../platdep/2452/serial.c $(GEN_OPTS) $(GEN_SRCS) $(CFG_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmsp -g --define=__MSP430G2452__ --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="D:/Documents and Settings/Rogerio/Meus documentos/workspace/workspace4.2/Bluebread_2452/platdep/include" --include_path="D:/Documents and Settings/Rogerio/Meus documentos/workspace/workspace4.2/Bluebread_2452/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="platdep/2452/serial.pp" --obj_directory="platdep/2452" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


