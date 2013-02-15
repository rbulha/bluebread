/* ========================================================================== */
/*                                                                            */
/*   pwm.c                                                                    */
/*   (c) 2013 Rogerio Bulha Siqueira <http://www.esd-talk.com>                */
/*                                                                            */
/*   general PWM implementation for MAS430G2452                               */
/*                                                                            */
/*                                                                            */
/*   PWM use Timer_A CCR1 and CCR2 in toggle mode.                            */
/*   when CCRx interrupt happens in 0 it programs the CCRx to the duty        */
/*   Note: Timer_A must be in continue mode                                   */
/*                                                                            */
/*                                                                            */
/* TimerA  |-------------------------|-------------------------|...           */
/*                                                                            */
/* CCR1    |------------_____________|------------_____________|...           */
/*         CCR1=duty1   CCR1=0       CCR1=duty1   CCR1=0                      */
/*                                                                            */
/* CCR2    |----------------_________|----------------_________|...           */
/*         CCR2=duty2       CCR2=0   CCR2=duty2       CCR2=0                  */
/*                                                                            */
/* ========================================================================== */

/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>
#include "pwm.h"

volatile unsigned int pwm_duty[2];

void pwm_duty_set(unsigned int duty, unsigned char channel)
{
    pwm_duty[channel] = duty;
}

/*CCR1 ISR handle */
void PWM_1_ISR(void)
{
    if(TA0CCR1==0)
        TA0CCR1 = pwm_duty[0];
    else    
        TA0CCR1 = 0;
}

/*CCR2 ISR handle */
void PWM_2_ISR(void)
{
    if(TA0CCR2==0)
        TA0CCR2 = pwm_duty[1];
    else    
        TA0CCR2 = 0;
}

