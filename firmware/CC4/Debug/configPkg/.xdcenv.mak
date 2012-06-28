#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/PROGRA~2/TEXASI~1/grace_1_00_01_83/packages
override XDCROOT = C:/PROGRA~2/TEXASI~1/xdctools_3_21_01_57_msp430
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/PROGRA~2/TEXASI~1/grace_1_00_01_83/packages;C:/PROGRA~2/TEXASI~1/xdctools_3_21_01_57_msp430/packages;..
HOSTOS = Windows
endif
