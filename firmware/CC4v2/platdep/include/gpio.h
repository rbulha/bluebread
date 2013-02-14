#ifndef _gpio_h
#define _gpio_h

unsigned char port_in(unsigned char port_number);
void port_out_set(unsigned char port_number, unsigned char mask);
void port_out_reset(unsigned char port_number, unsigned char mask);

#endif /* _gpio_h */
