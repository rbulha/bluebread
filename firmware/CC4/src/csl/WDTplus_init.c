/*
 *  ==== DO NOT MODIFY THIS FILE - CHANGES WILL BE OVERWRITTEN ====
 *
 *  Generated from
 *      C:/Program Files (x86)/Texas Instruments/grace_1_00_01_83/packages/ti/mcu/msp430/csl/watchdog/WDTplus_init.xdt
 */

#include <ti/mcu/msp430/include/msp430.h>

/*
 *  ======== WDTplus_init ========
 *  Initialize MSP430 Watchdog Timer+
 */
void WDTplus_init(void)
{
    /* 
     * WDTCTL, Watchdog Timer+ Register
     * 
     * WDTHOLD -- Watchdog timer+ is stopped
     * ~WDTNMIES -- NMI on rising edge
     * ~WDTNMI -- Reset function
     * ~WDTTMSEL -- Watchdog mode
     * ~WDTCNTCL -- No action
     * ~WDTSSEL -- SMCLK
     * ~WDTIS0 -- Watchdog clock source bit0 disabled
     * ~WDTIS1 -- Watchdog clock source bit1 disabled
     * 
     * Note: ~<BIT> indicates that <BIT> has value zero
     */
    WDTCTL = WDTPW + WDTHOLD;
    
}
