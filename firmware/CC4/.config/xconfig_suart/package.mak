#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
override PKGDIR = xconfig_suart
XDCINCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(XPKGPATH))))
XDCCFGDIR = package/cfg/

#
# The following dependencies ensure package.mak is rebuilt
# in the event that some included BOM script changes.
#
ifneq (clean,$(MAKECMDGOALS))
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/include/utils.tci:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/include/utils.tci
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/xdc.tci:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/xdc.tci
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/template.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/template.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/om2.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/om2.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/xmlgen.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/xmlgen.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/xmlgen2.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/xmlgen2.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/IPackage.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/IPackage.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/package.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/package.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/services/global/Clock.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/services/global/Clock.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/services/global/Trace.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/services/global/Trace.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/bld.js:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/bld.js
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/BuildEnvironment.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/BuildEnvironment.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/PackageContents.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/PackageContents.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/_gen.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/_gen.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Library.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Library.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Executable.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Executable.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Repository.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Repository.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Configuration.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Configuration.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Script.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Script.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Manifest.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Manifest.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Utils.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/Utils.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/ITarget.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/ITarget.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/ITargetFilter.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/ITargetFilter.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/package.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/bld/package.xs
package.mak: config.bld
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/ti/targets/ITarget.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/ti/targets/ITarget.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/ti/targets/package.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/ti/targets/package.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/ti/targets/msp430/MSP430.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/ti/targets/msp430/MSP430.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/ti/targets/msp430/MSP430X.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/ti/targets/msp430/MSP430X.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/ti/targets/msp430/MSP430X_small.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/ti/targets/msp430/MSP430X_small.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/ti/targets/msp430/package.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/ti/targets/msp430/package.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/services/io/File.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/services/io/File.xs
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/services/io/package.xs:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/services/io/package.xs
package.mak: package.bld
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/tools/configuro/template/compiler.opt.xdt:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/tools/configuro/template/compiler.opt.xdt
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/tools/configuro/template/custom.mak.exe.xdt:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/tools/configuro/template/custom.mak.exe.xdt
C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/tools/configuro/template/package.xs.xdt:
package.mak: C:/Program\ Files\ (x86)/Texas\ Instruments/xdctools_3_21_01_57_msp430/packages/xdc/tools/configuro/template/package.xs.xdt
endif

ti.targets.msp430.MSP430.rootDir ?= C:/PROGRA~2/TEXASI~1/ccsv4/tools/compiler/msp430
ti.targets.msp430.packageBase ?= C:/Program Files (x86)/Texas Instruments/xdctools_3_21_01_57_msp430/packages/ti/targets/msp430/
.PRECIOUS: $(XDCCFGDIR)/%.o430
.PHONY: all,430 .dlls,430 .executables,430 test,430
all,430: .executables,430
.executables,430: .libraries,430
.executables,430: .dlls,430
.dlls,430: .libraries,430
.libraries,430: .interfaces
	@$(RM) $@
	@$(TOUCH) "$@"

.help::
	@$(ECHO) xdc test,430
	@$(ECHO) xdc .executables,430
	@$(ECHO) xdc .libraries,430
	@$(ECHO) xdc .dlls,430


all: .executables 
.executables: .libraries .dlls
.libraries: .interfaces

PKGCFGS := $(wildcard package.xs) package/build.cfg
.interfaces: package/package.xdc.inc package/package.defs.h package.xdc $(PKGCFGS)

-include package/package.xdc.dep
package/%.xdc.inc package/%_xconfig_suart.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package xconfig_suart" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs $(MK_IDLOPTS) -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

.dlls,430 .dlls: suart.p430

-include package/cfg/suart_p430.mak
ifneq (clean,$(MAKECMDGOALS))
-include package/cfg/suart_p430.dep
endif
suart.p430: package/cfg/suart_p430.xdl
	@


ifeq (,$(wildcard .libraries,430))
suart.p430 package/cfg/suart_p430.c: .libraries,430
endif

package/cfg/suart_p430.c package/cfg/suart_p430.h package/cfg/suart_p430.xdl: override _PROG_NAME := suart.p430
package/cfg/suart_p430.c: package/cfg/suart_p430.cfg

clean:: clean,430
	-$(RM) package/cfg/suart_p430.cfg
	-$(RM) package/cfg/suart_p430.dep
	-$(RM) package/cfg/suart_p430.c
	-$(RM) package/cfg/suart_p430.xdc.inc

clean,430::
	-$(RM) suart.p430
.executables,430 .executables: suart.x430

-include package/cfg/suart.x430.mak
suart.x430: package/cfg/suart_p430.o430 
	$(RM) $@
	@$(MSG) lnk430 $@ ...
	$(RM) $(XDCCFGDIR)/$@.map
	$(ti.targets.msp430.MSP430.rootDir)/bin/lnk430 -w -q -u _c_int00 -fs $(XDCCFGDIR)$(dir $@).  -q -o $@ package/cfg/suart_p430.o430   package/cfg/suart_p430.xdl  -c -m $(XDCCFGDIR)/$@.map  -l $(ti.targets.msp430.MSP430.rootDir)/lib/rts430.lib
	
suart.x430:C_DIR=
suart.x430: PATH:=$(ti.targets.msp430.MSP430.rootDir)/bin/;$(PATH)
suart.x430: Path:=$(ti.targets.msp430.MSP430.rootDir)/bin/;$(PATH)

suart.test test,430 test: suart.x430.test

suart.x430.test:: suart.x430
ifeq (,$(_TESTLEVEL))
	@$(MAKE) -R -r --no-print-directory -f $(XDCROOT)/packages/xdc/bld/xdc.mak _TESTLEVEL=1 suart.x430.test
else
	@$(MSG) running $<  ...
	$(call EXEC.suart.x430, ) 
endif

clean,430::
	-$(RM) .tmp,suart.x430,0,*


clean:: clean,430

clean,430::
	-$(RM) suart.x430
clean:: 
	-$(RM) package/cfg/suart_p430.pjt
%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@
suart_p430.o430,copy : package/cfg/suart_p430.o430
suart_p430.s430,copy : package/cfg/suart_p430.s430

$(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg .interfaces $(XDCROOT)/packages/xdc/cfg/Main.xs
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_XSOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,xconfig_suart
xconfig_suart.tar: package/package.bld.xml
xconfig_suart.tar: package/package.ext.xml
xconfig_suart.tar: package/package.rel.dot
xconfig_suart.tar: package/build.cfg
xconfig_suart.tar: package/package.xdc.inc
ifneq (clean,$(MAKECMDGOALS))
-include package/rel/xconfig_suart.tar.dep
endif
package/rel/xconfig_suart/xconfig_suart/package/package.rel.xml:

xconfig_suart.tar: package/rel/xconfig_suart.xdc.inc package/rel/xconfig_suart/xconfig_suart/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKRELTAR,package/rel/xconfig_suart.xdc.inc,package/rel/xconfig_suart.tar.dep)


release release,xconfig_suart: all xconfig_suart.tar
clean:: .clean
	-$(RM) xconfig_suart.tar
	-$(RM) package/rel/xconfig_suart.xdc.inc
	-$(RM) package/rel/xconfig_suart.tar.dep

clean:: .clean
	-$(RM) .libraries .libraries,*
clean:: 
	-$(RM) .dlls .dlls,*
#
# The following clean rule removes user specified
# generated files or directories.
#

ifneq (clean,$(MAKECMDGOALS))
ifeq (,$(wildcard package))
    $(shell $(MKDIR) package)
endif
ifeq (,$(wildcard package/cfg))
    $(shell $(MKDIR) package/cfg)
endif
ifeq (,$(wildcard package/lib))
    $(shell $(MKDIR) package/lib)
endif
ifeq (,$(wildcard package/rel))
    $(shell $(MKDIR) package/rel)
endif
ifeq (,$(wildcard package/internal))
    $(shell $(MKDIR) package/internal)
endif
ifeq (,$(wildcard package/external))
    $(shell $(MKDIR) package/external)
endif
endif
clean::
	-$(RMDIR) package

include custom.mak
clean:: 
	-$(RM) package/xconfig_suart.pjt