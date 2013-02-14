/* ========================================================================== */
/*                                                                            */
/*   atmachine.c                                                              */
/*   (c) 2012 Rogerio Bulha Siqueira <http://www.esd-talk.com>                */
/*                                                                            */
/*   Custom AT commands machine                                               */
/*                                                                            */
/*   @historic last change in 14 fev 2013                                     */
/* ========================================================================== */

/** AT commands interpreter include*/
#include "atcmd.h"
#include "atmachine.h"

/** Platform depended includes*/
#include "gpio.h"
#include "serial.h"

enum eatintr{
  E_IDLE=0,
  E_RECVING_AT,
  E_RECVING_MORE,
  E_RECVING_RW,
  E_RECVING_CMD,
  E_RECVING_WV, /**Write value must be a byte only*/
  E_LAST
};

typedef struct satmachine{
  unsigned char state;
  unsigned char result; 
  unsigned char bPublishFrame;
  unsigned int  uiPublishFrameCnt;  
}tsatmachine;

volatile tsatmachine s_at_machine;
unsigned char txPortStatus; 
unsigned char Portloop; 


void at_machine_init()
{
    s_at_machine.state = E_IDLE;
    s_at_machine.result=0;
    s_at_machine.bPublishFrame=0;
    s_at_machine.uiPublishFrameCnt=0;
}

unsigned char at_machine_get_last_result()
{
    return s_at_machine.result;
}

int at_machine(unsigned char tk)
{
    switch(at_inter(tk))
    {
        case E_ACK: 
            s_at_machine.bPublishFrame=0;
            putstr("ok\r\n"); 
            break;
        case E_ERROR:
            putstr("err\r\n");
            at_machine_init();
            break;    
        case E_READ: 
        switch(at_get_last_cmd())
        {
            case E_LT_CMD_1: /**NAME*/ 
                putstr("bluebread\r\n"); 
                break;
            case E_LT_CMD_2: /**PORT*/
                putstr("P1.b3|b4|b5= ");
                txPortStatus = 0x08;
                for(Portloop=0;Portloop<3;Portloop++)
                {
                    txPortStatus = txPortStatus << Portloop; 
                    if( (port_in(1) & txPortStatus) == txPortStatus )
                        putstr("1|");
                    else	
                        putstr("0|");
                }
                putstr("\n\r");
                break;
            case E_LT_CMD_3: /**VERSION*/ 
                putstr("Bluebread version 1.0.1\r\n"); 
                break;
            case E_LT_CMD_4: /**PUBLICATION*/ 
                if(s_at_machine.bPublishFrame)
                    putstr("Publication frame=ON\r\n");
                else
                    putstr("Publication frame=OFF\r\n");	 
                break;
            default: 
                putstr("read cmd unknown\r\n"); 
                break;
        }
        //read state are solved in one turn
        at_machine_init();
        break;
        case E_WRITE:
        switch(at_get_last_cmd())
        {
            case E_LT_CMD_1: /**NAME*/ 
                putstr("NAME is read only\r\n"); 
                break;
            case E_LT_CMD_2: /**PORT*/
                switch(at_get_write_value())
                {
                    case '1': 
                        port_out_set(1,0x01);
                        putstr("LED1=ON\r\n");
                        break;
                    case '0': 
                        port_out_reset(1,0x01);
                        putstr("LED1=OFF\r\n");
                        break;
                    default: 
                        putstr("invalid LED state\r\n");
                        break;
                }
                break;
            case E_LT_CMD_3: /**VERSION*/ 
                putstr("VERSION is read only\r\n"); 
                break;
            case E_LT_CMD_4: /**PUBLICATION*/ 
                s_at_machine.bPublishFrame = at_get_write_value();
                break;
            default: putstr("write cmd unknown\r\n");	
        }
        //write state are solved in one turn
        at_machine_init();
        break;
        default: break;
    }
    return E_NONE;
}

