/** 
  @file atmachine.h
  
  @brief Custom AT commands machine

  @author: Rogério Bulha Siqueira
 */
#ifndef _atmachine_h
#define _atmachine_h

/**Initialize the at command machine
 @note call this once ate top of your code
 */
void at_machine_init();

/**@return the last result from the state machine
 */ 
unsigned char at_machine_get_last_result();


/**Machine interactor
 @brief call this function for each character that compose the command.
 @param tk hold the last character received to build the command.
 @return the command machine result code.
 */
int at_machine(unsigned char tk);

#endif /* _atmachine_h */

