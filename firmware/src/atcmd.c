/* ========================================================================== */
/*                                                                            */
/*   atcmd.c                                                                  */
/*   (c) 2012 Rogerio Bulha Siqueira <http://www.esd-talk.com>                */
/*                                                                            */
/*   Custom AT commands interpreter                                           */
/*                                                                            */
/* ========================================================================== */

#define CMD_SIZE 4

static unsigned char aucatlookupt1[] = {'A','T'};
static unsigned char aucatlookupt2[] = {'+'};
static unsigned char aucatlookupt3[] = {'N','A','M','E'};
static unsigned char aucatlookupt4[] = {'P','O','R','T'};
static unsigned char aucatlookupt5[] = {'V','E','R','S'};
/** Master table */
static unsigned char *aucatlookuptM[] = {aucatlookupt1,aucatlookupt2,aucatlookupt3,aucatlookupt4,aucatlookupt5};

/** Master table index */
enum ealookuptmti{
  E_LT_AT=0,
  E_LT_MORE,
  E_LT_CMD_1,
  E_LT_CMD_2,
  E_LT_CMD_3,
  E_LT_CMD_LAST,
  E_LT_LAST
};

enum eatintr{
  E_IDLE=0,
  E_RECVING_AT,
  E_RECVING_MORE,
  E_RECVING_RW,
  E_RECVING_CMD,
  E_LAST
};

enum eatintrrc{
  E_NONE=0,
  E_OK,
  E_ERROR,
  E_ACK,
  E_READ,
  E_WRITE,
  E_BUFFER,
  E_RC_LAST
};

typedef struct satinterm{
  int state;
  unsigned char rx_idx;
  unsigned char rx_cmd_idx;
  unsigned char cmd[CMD_SIZE]; 
}tsatinterm;


volatile static tsatinterm s_at_inter;

void at_init()
{
  s_at_inter.state = E_IDLE;
  s_at_inter.rx_idx = 0;
  s_at_inter.rx_cmd_idx = 0;
}

int at_get_last_cmd()
{
    return s_at_inter.rx_cmd_idx;
}

int at_inter(unsigned char tk)
{
  unsigned char i;
  
  if(tk == '\n') return E_NONE; //ignore LF, all cmds must end with "\r\n"
  
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
        s_at_inter.state = E_IDLE;
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
        s_at_inter.state = E_IDLE;
        return E_ACK; //AT acknowledge  
      }
    break;
    case E_RECVING_CMD:
      while(tk != aucatlookuptM[s_at_inter.rx_cmd_idx][s_at_inter.rx_idx])
      {
        if(++s_at_inter.rx_cmd_idx >= E_LT_CMD_LAST)
        {
          s_at_inter.state = E_IDLE;
          return E_ERROR;
        }

        for(i=0; i<s_at_inter.rx_idx; i++)
        {
          if(s_at_inter.cmd[s_at_inter.rx_idx] != aucatlookuptM[s_at_inter.rx_cmd_idx][i])        
            if(++s_at_inter.rx_cmd_idx >= E_LT_CMD_LAST)
            {
              s_at_inter.state = E_IDLE;
              return E_ERROR;
            }
            else
              break;  
        }
      }
      s_at_inter.cmd[s_at_inter.rx_idx] = tk;
      if(++s_at_inter.rx_idx == CMD_SIZE)
        s_at_inter.state = E_RECVING_RW;
    break;
    case E_RECVING_RW:
      switch(tk)
      {
        case '?' : /**Inquire command*/
        s_at_inter.state = E_IDLE;
        return E_READ;
        case '=' : /**Assignment command*/
        s_at_inter.state = E_IDLE;
        return E_WRITE;
        default: 
        s_at_inter.state = E_IDLE;
        return E_NONE;
      }
    break;
    default: 
    s_at_inter.state = E_IDLE;
    return E_NONE;
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

