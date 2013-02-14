################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS) $(CFG_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmsp -g --define=__MSP430G2452__ --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="D:/Documents and Settings/Rogerio/Meus documentos/workspace/workspace4.2/Bluebread_2452/platdep/include" --include_path="D:/Documents and Settings/Rogerio/Meus documentos/workspace/workspace4.2/Bluebread_2452/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

configPkg/compiler.opt: ../main.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"C:/Program Files (x86)/Texas Instruments/xdctools_3_21_01_57_msp430/xs" --xdcpath="C:/Program Files (x86)/Texas Instruments/grace_1_00_01_83/packages;" xdc.tools.configuro -o configPkg -t ti.targets.msp430.MSP430 -p ti.platforms.msp430:MSP430G2452 -r debug -c "C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt


