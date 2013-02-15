#ifndef PWM_H_
#define PWM_H_

/* set the duty cycle from 0 to 256 (0-100%)
 * @duty 0 to 256 (0-100%)
 * @channel PWM number (consult platform)
 */
void pwm_duty_set(unsigned char duty, unsigned char channel);

#endif /*PWM_H_*/
