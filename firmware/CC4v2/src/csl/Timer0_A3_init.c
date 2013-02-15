/*
 *  ==== DO NOT MODIFY THIS FILE - CHANGES WILL BE OVERWRITTEN ====
 *
 *  Generated from
 *      C:/Program Files (x86)/Texas Instruments/grace_1_00_01_83/packages/ti/mcu/msp430/csl/timer/ITimerx_A_init.xdt
 */

#include <ti/mcu/msp430/include/msp430.h>

/*
 *  ======== Timer0_A3_init ========
 *  Initialize MSP430 Timer0_A3 timer
 */
void Timer0_A3_init(void)
{
    /* 
     * TA0CCTL0, Capture/Compare Control Register 0
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
    TA0CCTL0 = CM_0 + CCIS_0 + OUTMOD_0 + CCIE + OUT;

    /* 
     * TA0CCTL1, Capture/Compare Control Register 1
     * 
     * CM_0 -- No Capture
     * CCIS_0 -- CCIxA
     * ~SCS -- Asynchronous Capture
     * ~SCCI -- Latched capture signal (read)
     * ~CAP -- Compare mode
     * OUTMOD_1 -- PWM output mode: 1 - Set
     * 
     * Note: ~<BIT> indicates that <BIT> has value zero
     */
    TA0CCTL1 = CM_0 + CCIS_0 + OUTMOD_1;

    /* 
     * TA0CCTL2, Capture/Compare Control Register 2
     * 
     * CM_0 -- No Capture
     * CCIS_0 -- CCIxA
     * ~SCS -- Asynchronous Capture
     * ~SCCI -- Latched capture signal (read)
     * ~CAP -- Compare mode
     * OUTMOD_5 -- PWM output mode: 5 - Reset
     * 
     * Note: ~<BIT> indicates that <BIT> has value zero
     */
    TA0CCTL2 = CM_0 + CCIS_0 + OUTMOD_5;

    /* TA0CCR0, Timer_A Capture/Compare Register 0 */
    TA0CCR0 = 6292;

    /* TA0CCR1, Timer_A Capture/Compare Register 1 */
    TA0CCR1 = 3149;

    /* TA0CCR2, Timer_A Capture/Compare Register 2 */
    TA0CCR2 = 4000;

    /* 
     * TA0CTL, Timer_A3 Control Register
     * 
     * TASSEL_2 -- SMCLK
     * ID_3 -- Divider - /8
     * MC_2 -- Continuous Mode
     */
    TA0CTL = TASSEL_2 + ID_3 + MC_2;
}
