/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>

/*
 * ======== Grace related includes ========
 */
#include <ti/mcu/msp430/csl/CSL.h>

/** AT commands interpreter include*/
#include "atcmd.h"
#include "atmachine.h"
#include "serial.h"
/*
 *  ======== main ========
 */
int main(int argc, char *argv[])
{
	int i=0;
    CSL_init();                     // Activate Grace-generated configuration
    suart_init();
    __enable_interrupt();           // Set global interrupt enable
    
    // >>>>> Fill-in user code here <<<<<
    at_machine_init();
    
    at_init(); /**init AT command interpreter */

	P1OUT |= 0x01; //LED
	
	for(i=0; i<100; i++)
		__no_operation();
	
	putstr("Blue bread terminal - ON\r\n");
	
	while(1)
	{
		if(suart_data_avaliable())
		{
			at_machine(suart_get_last_rx());
		}	
	}
    
    return (0);
}

void Port_1_ISR(void)
{
	suart_start_rx();	 		
}

void Timer_A3_CCR0_ISR(void)
{
	suart_timer_tick();	
}

void I2C_COUNT_ISR(void)
{
	
}
