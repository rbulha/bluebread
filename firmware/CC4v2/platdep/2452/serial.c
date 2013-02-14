/* ========================================================================== */
/*                                                                            */
/*   serial.c                                                                 */
/*   (c) 2012 Rogerio Bulha Siqueira <http://www.esd-talk.com>                */
/*                                                                            */
/*   Software UART implementation for MAS430G2452                             */
/*                                                                            */
/* ========================================================================== */


/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>
#include "serial.h"

/*
 * ======== application definitions ========
 * Bit period for 9600/4 = 2400 Baud SW UART, assuming
 *    SMCLK = 1MHz,
 *    Timer_A input divider = 8 (=> timer freq = 125 KHz)
 */
#define BITIME  (13)                // 125 KHz /(13*4) = 2404 bits/sec
#define HBITIME  (7)                //half bit time


volatile unsigned char bitCnt;
volatile unsigned int  txByte; 
volatile unsigned char rxByte;
volatile unsigned char rxMask;
volatile unsigned char bBusyRX=0;
volatile unsigned char bDataAvaliable=0;

/*
 *  ======== transmit ========
 *  Transmit specified character
 */
void transmit(unsigned char ch)
{ 
    bitCnt = 0xA;                       // Load Bit counter, 8data + ST/SP
    txByte = (unsigned int)ch | 0x100;  // Add mark stop bit to txByte
    txByte = txByte << 1;               // Add space start bit

    CCR0 = TAR + BITIME;                // Some time till first bit
    CCTL0 = OUTMOD0 + CCIE;             // TXD = mark = idle
    while (CCTL0 & CCIE);               // Wait for ISR to complete TX
}

/*
 *  ======== putstr ========
 */
void putstr(char *str)
{
    char *cp;
    for (cp = str; *cp != '\0'; cp++) {
        transmit(cp[0]);
    }
}

void suart_timer_tick(void)
{
    CCR0 += BITIME;                     // Schedule next interrupt
    if(bBusyRX)
    {
    	if((P1IN & 0x04) == 0x04)
    		rxByte |= rxMask;
    	else
    		rxByte &= ~rxMask;
    	
    	if( (rxMask & 0x80) == 0x80 )
		{
			bBusyRX = 0;
			CCTL0 &= ~CCIE;  // All bits received, disable interrupt
            P1IFG &= ~0x04;  // Clear RXD (flag) before enabling interrupt
            P1IE  |= 0x04;   // Enable RXD interrupt that wait for the next start bit.    
            bDataAvaliable=1;
		}
    	else	
    		rxMask = rxMask << 1;
    }
    else
    {  
	    if (bitCnt == 0) {
	        CCTL0 &= ~CCIE;                 // All bits TXed, disable interrupt
	    }
	    else {
	        if (txByte & 0x01) {
	            CCTL0 &= ~OUTMOD2;          // TX Mark
	        }
	        else {
	            CCTL0 |= OUTMOD2;           // TX Space
	        }
	        txByte = txByte >> 1;
	        bitCnt--;
	    }
    }
}

void suart_start_rx(void)
{
    P1IFG &= ~0x04;   // Clear RXD (flag) 
    P1IE  &= ~0x04;   // stop interruption until end of reception   
	bBusyRX = 1;      // put UART busy for reception
	rxByte = 0x00;
	rxMask = 0x01;
	CCR0 = TAR + BITIME; // Schedule next interrupt half bit time.
	CCTL0 |= CCIE;        // enable reception timer	
}

void suart_init(void)
{
    P1IES |= 0x04;      // RXD Hi/lo edge interrupt on port P1.2
    P1IFG &= ~0x04;     // Clear RXD (flag) before enabling interrupt
    P1IE  |= 0x04;      // Enable RXD interrupt    
}

unsigned char suart_data_avaliable(void)
{
	return bDataAvaliable;	
}

unsigned char suart_get_last_rx(void)
{
	bDataAvaliable = 0;
	return rxByte;	
}

