#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.msp430.MSP430{1,0,3.3,2
#
ifneq (clean,$(MAKECMDGOALS))
-include package/cfg/main_p430.o430.dep
endif

package/cfg/main_p430.o430: | .interfaces
package/cfg/main_p430.o430: package/cfg/main_p430.c package/cfg/main_p430.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl430 $< ...
	$(ti.targets.msp430.MSP430.rootDir)/bin/cl430 -c  -qq -pdsw225  -vmsp -eo.o430 -ea.s430  --embed_inline_assembly -D_DEBUG_=1  -Dxdc_cfg__header__='configPkg/package/cfg/main_p430.h'  -Dxdc_target_name__=MSP430 -Dxdc_target_types__=ti/targets/msp430/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_3_3_2 -g  $(XDCINCS) -I$(ti.targets.msp430.MSP430.rootDir)/include  -fs=./package/cfg -fr=./package/cfg -fc $<
	$(MKDEP) -a $@.dep -p package/cfg -s o430 $< -C   -qq -pdsw225  -vmsp -eo.o430 -ea.s430  --embed_inline_assembly -D_DEBUG_=1  -Dxdc_cfg__header__='configPkg/package/cfg/main_p430.h'  -Dxdc_target_name__=MSP430 -Dxdc_target_types__=ti/targets/msp430/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_3_3_2 -g  $(XDCINCS) -I$(ti.targets.msp430.MSP430.rootDir)/include  -fs=./package/cfg -fr=./package/cfg
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/main_p430.o430:C_DIR=
package/cfg/main_p430.o430: PATH:=$(ti.targets.msp430.MSP430.rootDir)/bin/;$(PATH)
package/cfg/main_p430.o430: Path:=$(ti.targets.msp430.MSP430.rootDir)/bin/;$(PATH)

package/cfg/main_p430.s430: | .interfaces
package/cfg/main_p430.s430: package/cfg/main_p430.c package/cfg/main_p430.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl430 -n $< ...
	$(ti.targets.msp430.MSP430.rootDir)/bin/cl430 -c -n -s --symdebug:none -qq -pdsw225  -vmsp -eo.o430 -ea.s430  -D_DEBUG_=1  -Dxdc_cfg__header__='configPkg/package/cfg/main_p430.h'  -Dxdc_target_name__=MSP430 -Dxdc_target_types__=ti/targets/msp430/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_3_3_2 -g  $(XDCINCS) -I$(ti.targets.msp430.MSP430.rootDir)/include  -fs=./package/cfg -fr=./package/cfg -fc $<
	$(MKDEP) -a $@.dep -p package/cfg -s o430 $< -C  -n -s --symdebug:none -qq -pdsw225  -vmsp -eo.o430 -ea.s430  -D_DEBUG_=1  -Dxdc_cfg__header__='configPkg/package/cfg/main_p430.h'  -Dxdc_target_name__=MSP430 -Dxdc_target_types__=ti/targets/msp430/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_3_3_2 -g  $(XDCINCS) -I$(ti.targets.msp430.MSP430.rootDir)/include  -fs=./package/cfg -fr=./package/cfg
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/main_p430.s430:C_DIR=
package/cfg/main_p430.s430: PATH:=$(ti.targets.msp430.MSP430.rootDir)/bin/;$(PATH)
package/cfg/main_p430.s430: Path:=$(ti.targets.msp430.MSP430.rootDir)/bin/;$(PATH)

clean,430 ::
	-$(RM) package/cfg/main_p430.o430
	-$(RM) package/cfg/main_p430.s430

main.p430: package/cfg/main_p430.o430 package/cfg/main_p430.mak

clean::
	-$(RM) package/cfg/main_p430.mak