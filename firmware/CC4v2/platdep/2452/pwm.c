/* ========================================================================== */
/*                                                                            */
/*   pwm.c                                                                   */
/*   (c) 2013 Rogerio Bulha Siqueira <http://www.esd-talk.com>                */
/*                                                                            */
/*   general PWM implementation for MAS430G2452                               */
/*                                                                            */
/* ========================================================================== */

/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>
#include "pwm.h"

void pwm_duty_set(unsigned char duty, unsigned char channel)
{
	switch(channel)
	{
		case 1:
			//in this case duty is from 0 to 6292
			TA0CCR2 = duty * 24;
			break;
		default: break;
	}	
}
