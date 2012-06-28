################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CFG_SRCS += \
../suart.cfg 

C_SRCS += \
../suart.c 

CMD_SRCS += \
../lnk_msp430g2211.cmd 

GEN_SRCS += \
./configPkg/compiler.opt \
./configPkg/linker.cmd 

GEN_CMDS += \
./configPkg/linker.cmd 

OBJS += \
./suart.obj 

C_DEPS += \
./suart.pp 

GEN_MISC_DIRS += \
./configPkg/ 

GEN_OPTS += \
./configPkg/compiler.opt 

OBJS__QTD += \
".\suart.obj" 

GEN_SRCS__QTD += \
".\configPkg\compiler.opt" \
".\configPkg\linker.cmd" 

C_DEPS__QTD += \
".\suart.pp" 

GEN_MISC_DIRS__QTD += \
".\configPkg\" 

C_SRCS_QUOTED += \
"../suart.c" 

CFG_SRCS_QUOTED += \
"../suart.cfg" 

GEN_OPTS_QUOTED += \
--cmd_file="./configPkg/compiler.opt" 

GEN_CMDS_QUOTED += \
-l"./configPkg/linker.cmd" 


