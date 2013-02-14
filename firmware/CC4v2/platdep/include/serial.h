#ifndef _serial_h
#define _serial_h

void putstr(char *str);

/**Must be placed into a timer ISR callback
 * this callback must execute once per baud clycle
 */ 
void suart_timer_tick(void);

/**Must be called at falling edge interruption routine
 */ 
void suart_start_rx(void);

/** Init soft uart port and timer
    
    @note it uses a call back to improve low power, the main code don't 
    need to wait the end of transmition

    @param callback point to a function like: void func(unsigned char rxch)
    put 0 if you don't want to use a callback function
*/
void suart_init(void);

/**Inform if data is avaliable to read
 * @return True if data is avaliable, otherwise false 
 */
unsigned char suart_data_avaliable(void);

/**Get the last byte received
 * @note clear the data_avaliable flag
 * @return the las rx byte
 */ 
unsigned char suart_get_last_rx(void);

#endif /* _serial_h */

