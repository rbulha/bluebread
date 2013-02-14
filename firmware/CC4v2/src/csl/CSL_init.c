/*
 *  ======== CSL_init.c ========
 *  DO NOT MODIFY THIS FILE - CHANGES WILL BE OVERWRITTEN
 */
 
/* external peripheral initialization functions */
extern void WDTplus_init(void);
extern void GPIO_init(void);
extern void BCSplus_init(void);
extern void USI_init(void);
extern void Timer0_A3_init(void);
extern void System_init(void);

/*
 *  ======== CSL_init =========
 *  Initialize all configured CSL peripherals
 */
void CSL_init(void)
{
    /* initialize Config for the MSP430 WDT+ */
    WDTplus_init();

    /* initialize Config for the MSP430 GPIO */
    GPIO_init();

    /* initialize Config for the MSP430 2xx family clock systems (BCS) */
    BCSplus_init();

    /* initialize Config for the MSP430 USI */
    USI_init();

    /* initialize Config for the MSP430 A3 Timer0 */
    Timer0_A3_init();

    /* initialize Config for the MSP430 System Registers */
    System_init();

}

/*
 *  ======== Interrupt Function Definitions ========
 */

#include <ti/mcu/msp430/include/msp430.h>

/* Interrupt Function Prototypes */
extern void Port_1_ISR(void);
extern void Timer_A3_CCR0_ISR(void);


/*
 *  ======== PORT1 Interrupt Service Routine ========
 */
#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR_HOOK(void)
{


	/* Port 1 Interrupt Handler */
	Port_1_ISR();

	/* No change in operating mode on exit */
}
/*
 *  ======== Timer0_A3 Interrupt Service Routine ======== 
 */
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR_HOOK(void)
{
	/* Capture Compare Register 0 ISR Hook Function Name */
	Timer_A3_CCR0_ISR();

	/* No change in operating mode on exit */
}


