//*****************************************************************************
//   Software UART using Timer_A
//
//   Description: This example illustrates how to output characters 
//   to an RS-232 serial port without a UART peripheral.
//
//                   MSP430
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.1|-->TXD
//            |             P1.2|<--RXD
//
//   Texas Instruments Inc.
//*****************************************************************************

/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>

/*
 * ======== Grace related includes ========
 */
#include <ti/mcu/msp430/csl/CSL.h>

/*
 * ======== application definitions ========
 * Bit period for 9600/4 = 2400 Baud SW UART, assuming
 *    SMCLK = 1MHz,
 *    Timer_A input divider = 8 (=> timer freq = 125 KHz)
 */
#define BITIME  (13)                // 125 KHz /(13*4) = 2404 bits/sec
#define HBITIME  (6)                //half bit time
 
unsigned char bitCnt;                   // number of bits to transmit
unsigned int  txByte;                   // transmit buffer with start/stop bits
unsigned char txPortStatus; 
unsigned int  txPortStatusDelay;
unsigned int  Portloop; 
volatile unsigned char rxByte;
volatile unsigned char rxMask;
volatile unsigned char bBusyRX=0;

void putstr(char *str);                 // transmit string 
void transmit(unsigned char ch);        // transmit a character

/*
 *  ======== main ========
 */
int main(void)
{
    CSL_init();                         // Activate Grace-generated config

	P1OUT |= 0x01; //LED
	
	P1OUT |= 0x40; //Key
	
	txPortStatusDelay = 0;
	
    while (1) 
    {
    	if(bBusyRX)
		{
    		while(bBusyRX);
			switch(rxByte)
			{
				case 0x61: putstr("ok");
				break;	
			}	
		}
		else if(txPortStatusDelay++ == 5200)
    	{
	        putstr("Port1:[ ");
	        txPortStatus = 0x08;
	        for(Portloop=0;Portloop<3;Portloop++)
	        {
	        	txPortStatus = txPortStatus << Portloop; 
		        if( (P1IN & txPortStatus) == txPortStatus )
		        	putstr(" 1 ");
		        else	
		        	putstr(" 0 ");
	        }
	        putstr(" ]\n\r");
	        txPortStatusDelay = 0;
	        P1OUT ^= 0x01;
    	}
    }
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
 *  ======== timer_A_ISR ========
 *  Timer A0 interrupt service routine
 */
void timer_A_ISR(void)
{
    CCR0 += BITIME;                     // Schedule next interrupt
    if(bBusyRX)
    {
    	if(CCTL1 & SCCI)
    		rxByte |= rxMask;
    	else
    		rxByte &= ~rxMask;
    	
    	if( (rxMask & 0x80) == 0x80 )
		{
			bBusyRX = 0;
			CCTL0 &= ~CCIE;  // All bits received, disable interrupt
			CCTL1 |= CAP;    // set to capture start bit
			CCTL1 |= CCIE;   //enable ISR to rceive next start bit.
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

/** ISR routine P1.2 on rising edge
 * @note generate by Grace
 * @author Rogerio Bulha Siqueria
 * @date 27/06/2012
 */ 
void Timer_A2_CCR1_ISR(void)
{
	CCTL1 &= ~CCIE; //receive start bit stop interruption
	CCTL1 &= ~CAP;  // set to sample input bit
	bBusyRX = 1; //put UART busy for reception
	rxByte = 0x00;
	rxMask = 0x01;
	CCR0 = TAR + HBITIME; // Schedule next interrupt half bit time.
	CCTL0 |= CCIE; //enable reception
}

