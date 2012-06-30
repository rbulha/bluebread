/** Bluebread software uart implementation
 
    @based on Software UART using Timer_A from Texas Instruments Inc.


               MSP430
         -----------------
     /|\|              XIN|-
      | |                 |
      --|RST          XOUT|-
        |                 |
        |             P1.1|-->TXD
        |             P1.2|<--RXD


    @author Rogerio Bulha Siqueira
    @date   29/06/2012
 */

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
#define HBITIME  (7)                //half bit time

typedef void (*rx_routine_type)(unsigned char);

rx_routine_type *pf_rx_callback;
 
unsigned char bitCnt;                   // number of bits to transmit
unsigned int  txByte;                   // transmit buffer with start/stop bits
unsigned char txPortStatus; 
unsigned int  Portloop; 
volatile unsigned char rxByte;
volatile unsigned char rxMask;
volatile unsigned char bBusyRX=0;
volatile unsigned char txNow=0;

void putstr(char *str);                 // transmit string 
void transmit(unsigned char ch);        // transmit a character
void init_uart(void *callback);
void rx_uart_cb(unsigned char rxch);

/*
 *  ======== main ========
    (testing routine by now)
 */
int main(void)
{
    CSL_init();                         // Activate Grace-generated config

    init_uart(rx_uart_cb);

	P1OUT |= 0x01; //LED
	
	P1OUT |= 0x40; //Key
	
	putstr("Blue bread terminal - ON\r\n");
	
    while (1) 
    {
    	if(txNow)
    	{
    		switch(rxByte)
    		{
    			case 'a':
    				putstr("P1|b3 |b4 |b5 |\r\n");
			        putstr("  |");
			        txPortStatus = 0x08;
			        for(Portloop=0;Portloop<3;Portloop++)
			        {
			        	txPortStatus = txPortStatus << Portloop; 
				        if( (P1IN & txPortStatus) == txPortStatus )
				        	putstr(" 1 |");
				        else	
				        	putstr(" 0 |");
			        }
			        putstr("\n\r");
	        		break;
	        	case 't':
	        	    P1OUT ^= 0x01;
	        	    putstr("Toggle LED\r\n");
	        		break;	
	        	case 'v':
	        	    putstr("Bluebread version 1.0.0\r\n");
	        		break;	
    			default:	
    				putstr("ok\r\n");
    				break;
    		}
    		txNow = 0;
    	}
		 //__bis_SR_register(CPUOFF + GIE);  // Enter LPM3
    }
}

/**end of reception callback function.
   passed to init_uart
   @param rxch is the received UART byte
*/
void rx_uart_cb(unsigned char rxch)
{
	txNow = 1;
}

/** Init soft uart port and timer
    
    @note it uses a call back to improve low power, the main code don't 
    need to wait the end of transmition

    @param callback point to a function like: void func(unsigned char rxch)
    put 0 if you don't want to use a callback function
*/
void init_uart(void *callback)
{
    P1IES |= 0x04;      // RXD Hi/lo edge interrupt on port P1.2
    P1IFG &= ~0x04;     // Clear RXD (flag) before enabling interrupt
    P1IE  |= 0x04;      // Enable RXD interrupt    
    pf_rx_callback = (rx_routine_type*)callback;
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

/** Timer A0 interrupt service routine
 */
unsigned short timer_A_ISR(void)
{
 	// Initialize return status to not change state
    unsigned short status = 0;	
    
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
            if(pf_rx_callback)
            {
               rx_uart_cb(rxByte);
               //status = LPM3_bits; // Exit LPM0 on return
            }
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
    
    return status;
}

/** ISR routine P1.2 on falling edge
 * @note generate by Grace
 * @author Rogerio Bulha Siqueria
 * @date 27/06/2012
 */ 
void Timer_A2_CCR1_ISR(void)
{
    P1IFG &= ~0x04;   // Clear RXD (flag) 
    P1IE  &= ~0x04;   // stop interruption until end of reception   
	bBusyRX = 1;      // put UART busy for reception
	rxByte = 0x00;
	rxMask = 0x01;
	CCR0 = TAR + BITIME; // Schedule next interrupt half bit time.
	CCTL0 |= CCIE;        // enable reception timer
}

