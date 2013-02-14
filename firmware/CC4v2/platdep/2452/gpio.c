/* ========================================================================== */
/*                                                                            */
/*   gpio.c                                                                   */
/*   (c) 2012 Rogerio Bulha Siqueira <http://www.esd-talk.com>                */
/*                                                                            */
/*   general I/O implementation for MAS430G2452                               */
/*                                                                            */
/* ========================================================================== */

/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>
#include "gpio.h"

unsigned char port_in(unsigned char port_number)
{
	switch(port_number)
	{
		case 1:  return P1IN;
		default: return 0x00;	
	}	
}

void port_out_set(unsigned char port_number, unsigned char mask)
{
	switch(port_number)
	{
		case 1:  P1OUT |= mask;
	}	
}

void port_out_reset(unsigned char port_number, unsigned char mask)
{
	switch(port_number)
	{
		case 1:  P1OUT &= ~mask;
	}	
}
