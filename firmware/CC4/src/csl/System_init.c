/*
 *  ==== DO NOT MODIFY THIS FILE - CHANGES WILL BE OVERWRITTEN ====
 *
 *  Generated from
 *      C:/Program Files (x86)/Texas Instruments/grace_1_00_01_83/packages/ti/mcu/msp430/csl/system/System_init.xdt
 */

#include <ti/mcu/msp430/include/msp430.h>

/*
 *  ======== System_init ========
 *  Initialize MSP430 Status Register
 */
void System_init(void)
{
    /* 
     * SR, Status Register
     * 
     * ~SCG1 -- Disable System clock generator 1
     * ~SCG0 -- Disable System clock generator 0
     * ~OSCOFF -- Oscillator On
     * ~CPUOFF -- CPU On
     * GIE -- General interrupt enable
     * 
     * Note: ~<BIT> indicates that <BIT> has value zero
     */
    __bis_SR_register(GIE);
    
}
