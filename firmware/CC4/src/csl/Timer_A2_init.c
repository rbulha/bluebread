/*
 *  ==== DO NOT MODIFY THIS FILE - CHANGES WILL BE OVERWRITTEN ====
 *
 *  Generated from
 *      C:/Program Files (x86)/Texas Instruments/grace_1_00_01_83/packages/ti/mcu/msp430/csl/timer/ITimerx_A_init.xdt
 */

#include <ti/mcu/msp430/include/msp430.h>

/*
 *  ======== Timer_A2_init ========
 *  Initialize MSP430 Timer_A2 timer
 */
void Timer_A2_init(void)
{
    /* 
     * TACCTL0, Capture/Compare Control Register 0
     * 
     * CM_0 -- No Capture
     * CCIS_0 -- CCIxA
     * ~SCS -- Asynchronous Capture
     * ~SCCI -- Latched capture signal (read)
     * ~CAP -- Compare mode
     * OUTMOD_0 -- PWM output mode: 0 - OUT bit value
     * 
     * Note: ~<BIT> indicates that <BIT> has value zero
     */
    TACCTL0 = CM_0 + CCIS_0 + OUTMOD_0 + CCIE + OUT;

    /* 
     * TACCTL1, Capture/Compare Control Register 1
     * 
     * CM_2 -- Falling Edge
     * CCIS_0 -- CCIxA
     * SCS -- Sychronous Capture
     * ~SCCI -- Latched capture signal (read)
     * CAP -- Capture mode
     * OUTMOD_5 -- PWM output mode: 5 - Reset
     * 
     * Note: ~SCCI indicates that SCCI has value zero
     */
    TACCTL1 = CM_2 + CCIS_0 + SCS + CAP + OUTMOD_5 + CCIE;

    /* TACCR0, Timer_A Capture/Compare Register 0 */
    TACCR0 = 1200;

    /* 
     * TACTL, Timer_A2 Control Register
     * 
     * TASSEL_2 -- SMCLK
     * ID_3 -- Divider - /8
     * MC_2 -- Continuous Mode
     */
    TACTL = TASSEL_2 + ID_3 + MC_2;
}
