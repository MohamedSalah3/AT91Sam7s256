#ifndef _LED_H_
#define _LED_H_

#include <atmel/pio.h>
#include <boards/at91sam7s-ek/at91sam7s256/AT91SAM7S256.h>
#include <board/LED-lib.h>


#define LED_DATA_LINE AT91C_PIO_PA25		// Data line (Output)
#define LED_CLOCK_LINE AT91C_PIO_PA24		// Clock line (Output)


void Led_Init(void);


void led_flash(void);






#endif