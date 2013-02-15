/* ========================================================================== */
/*                                                                            */
/*   atcmd.c                                                                  */
/*   (c) 2012 Rogerio Bulha Siqueira <http://www.esd-talk.com>                */
/*                                                                            */
/*   Custom AT commands interpreter                                           */
/*                                                                            */
/* ========================================================================== */

#include "atcmd.h"

#define CMD_SIZE 4

static const unsigned char aucatlookupt1[] = {'A','T'};
static const unsigned char aucatlookupt2[] = {'+'};
static const unsigned char aucatlookupt3[] = {'N','A','M','E'};
static const unsigned char aucatlookupt4[] = {'P','O','R','T'};
static const unsigned char aucatlookupt5[] = {'V','E','R','S'};
static const unsigned char aucatlookupt6[] = {'P','U','B','L'};
static const unsigned char aucatlookupt7[] = {'P','W','M','1'};
/** Master table */
static const unsigned char *aucatlookuptM[] = {aucatlookupt1,
                                               aucatlookupt2,
                                               aucatlookupt3,
                                               aucatlookupt4,
                                               aucatlookupt5,
                                               aucatlookupt6,
                                               aucatlookupt7};

enum eatintr{
  E_IDLE=0,
  E_RECVING_AT,
  E_RECVING_MORE,
  E_RECVING_RW,
  E_RECVING_CMD,
  E_RECVING_WV, /**Write value must be a byte only*/
  E_LAST
};

typedef struct satinterm{
  unsigned char state;
  unsigned char rx_idx;
  unsigned char rx_cmd_idx;
  unsigned char cmd[CMD_SIZE];
  unsigned char w_value; 
}tsatinterm;

volatile tsatinterm s_at_inter;

void at_init()
{
  s_at_inter.state = E_IDLE;
  s_at_inter.rx_idx = 0;
  s_at_inter.rx_cmd_idx = 0;
}

unsigned char at_get_write_value()
{
    return s_at_inter.w_value;
}

int at_get_last_cmd()
{
    return s_at_inter.rx_cmd_idx;
}

int at_inter(unsigned char tk)
{
  unsigned char i;
  
  if(tk == '\n') 
  {
  	//LF reset interpreter, all cmds must end with "\r\n"
  	at_init();
  	return E_NONE; 
  }
  
  switch(s_at_inter.state)
  {
    case E_IDLE:
      if(tk == aucatlookuptM[E_LT_AT][0])
      {
        s_at_inter.state = E_RECVING_AT;
        s_at_inter.rx_idx = 1;
      } 
    break;
    case E_RECVING_AT:
      if(tk == aucatlookuptM[E_LT_AT][s_at_inter.rx_idx++])
      {
        s_at_inter.state = E_RECVING_MORE;
      }
      else
      {
        at_init();
        return E_ERROR;
      }    
    break;
    case E_RECVING_MORE:
      if(tk == aucatlookuptM[E_LT_MORE][0])
      {
        s_at_inter.state = E_RECVING_CMD;
        s_at_inter.rx_idx = 0;
        s_at_inter.rx_cmd_idx = E_LT_CMD_1;
      }
      else if(tk == '\r')
      {
        at_init();
        return E_ACK; //AT acknowledge  
      }
      else
      {
        at_init();
        return E_ERROR;
      }    
    break;
    case E_RECVING_CMD:
      while(tk != aucatlookuptM[s_at_inter.rx_cmd_idx][s_at_inter.rx_idx])
      {
        if(++s_at_inter.rx_cmd_idx >= E_LT_CMD_LAST)
        {
          //reach the end of the command table without a match.
          at_init();
          return E_ERROR;
        }

        for(i=0; i<s_at_inter.rx_idx; i++)
        {
          if(s_at_inter.cmd[i] != aucatlookuptM[s_at_inter.rx_cmd_idx][i])        
            if(++s_at_inter.rx_cmd_idx >= E_LT_CMD_LAST)
            {
              //reach the end of the command table without a match.
              at_init();
              return E_ERROR;
            }
            else
              break;  
        }
        //if the code reach this point s_at_inter.rx_idx hold the position of the next command character.
      }
      s_at_inter.cmd[s_at_inter.rx_idx] = tk;
      if(++s_at_inter.rx_idx == CMD_SIZE)  //if s_at_inter.rx_idx is less then CMD_SIZE stay in this state for the next command character.
        s_at_inter.state = E_RECVING_RW;
    break;
    case E_RECVING_RW:
      switch(tk)
      {
        case '?' : /**Inquire command*/
        s_at_inter.state = E_IDLE;
        s_at_inter.rx_idx = 0;
        return E_READ;
        case '=' : /**Assignment command*/
        s_at_inter.state = E_RECVING_WV;
        break;
        default: 
        at_init();
        return E_ERROR; //command should be write(=) or read(?)
      }
    break;
    case E_RECVING_WV:
    	s_at_inter.w_value = tk;
    	s_at_inter.state = E_IDLE;
	    return E_WRITE;
    default: 
        at_init();
        return E_ERROR; //running machine with a invalid state.
  }
  return E_NONE;
}

#ifdef TESTING
#include <stdio.h>

int main()
{
    unsigned char teststream[]={'A','T','\r','\n','d','\n','A','T','+','N','A','M','E','?','\r'};
    int resp;
    int i;

    at_init();

    for(i=0;i<sizeof(teststream);i++)
    {
         resp = at_inter(teststream[i]);
         printf("interation(%d)=%d ",i,resp);
         switch(resp)
         {
            case E_ACK: printf(":: receive ACK\n"); 
            break;
            case E_READ: printf(":: receive E_READ cmd=%d\n",at_get_last_cmd());
            break;
            case E_WRITE: printf(":: receive E_WRITE cmd=%d\n",at_get_last_cmd());
            break;
            default: printf("\n"); break;
         }
    }

    return 1;
}
#endif

