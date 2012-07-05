/** 
  @file atcmd.h
  
  @brief Custom AT commands interpreter

  @author: Rogério Bulha Siqueira
 */
#ifndef _atcmd_h
#define _atcmd_h

/**returning codes from the interpreter*/
enum eatintrrc{
  E_NONE=0,
  E_OK,
  E_ERROR,
  E_ACK,
  E_READ,
  E_WRITE,
  E_RC_LAST
};

/** Master commands table index */
enum ealookuptmti{
  E_LT_AT=0,
  E_LT_MORE,
  E_LT_CMD_1,
  E_LT_CMD_2,
  E_LT_CMD_3,
  E_LT_CMD_LAST,
  E_LT_LAST
};


/**Initialize the at interpreter
 @note call this once ate top of your code
 */
void at_init();

/**Get the last interpreted command
 @return the command acording eatintrrc
 */
int at_get_last_cmd();

/**Return the value to write
 @return a byte with the value received
 @note must be called after a E_WRITE only
 */
unsigned char at_get_write_value();

/**Interpreter interactor
 @brief call this function for each character that compose the command.
 @param tk hold the last character received to build the command.
 @return the command interpreted or E_NONE during the parsing.
 
 @note at_get_last_cmd return the last command parsed by at_inter
 */
int at_inter(unsigned char tk);

#endif /* _atcmd_h */

