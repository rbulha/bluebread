#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/PROGRA~2/TEXASI~1/grace_1_00_01_83/packages;D:/DOCUME~1/Rogerio/MEUSDO~1/workspace/workspace4.2/Bluebread_2211/.config
override XDCROOT = C:/PROGRA~2/TEXASI~1/xdctools_3_21_01_57_msp430
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/PROGRA~2/TEXASI~1/grace_1_00_01_83/packages;D:/DOCUME~1/Rogerio/MEUSDO~1/workspace/workspace4.2/Bluebread_2211/.config;C:/PROGRA~2/TEXASI~1/xdctools_3_21_01_57_msp430/packages;..
HOSTOS = Windows
endif
