/*
 *  ==== DO NOT MODIFY THIS FILE - CHANGES WILL BE OVERWRITTEN ====
 *
 *  Generated from
 *      C:/Program Files (x86)/Texas Instruments/grace_1_00_01_83/packages/ti/mcu/msp430/csl/gpio/GPIO_init.xdt
 */

#include <ti/mcu/msp430/include/msp430.h>

/*
 *  ======== GPIO_init ========
 *  Initialize MSP430 General Purpose Input Output Ports
 */
void GPIO_init(void)
{
    /* Port 1 Output Register */
    P1OUT = 0;

    /* Port 1 Port Select Register */
    P1SEL = BIT1;

    /* Port 1 Direction Register */
    P1DIR = BIT0 + BIT1 + BIT6 + BIT7;

    /* Port 1 Interrupt Edge Select Register */
    P1IES = BIT2;

    /* Port 1 Interrupt Flag Register */
    P1IFG = 0;

    /* Port 1 Interrupt Enable Register */
    P1IE = BIT2;

    /* Port 2 Output Register */
    P2OUT = 0;

    /* Port 2 Interrupt Edge Select Register */
    P2IES = 0;

    /* Port 2 Interrupt Flag Register */
    P2IFG = 0;

}
