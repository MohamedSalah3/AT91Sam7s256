#ifndef _LED_H_
#define _LED_H_

#include <atmel/pio.h>
#include <boards/at91sam7s-ek/at91sam7s256/AT91SAM7S256.h>
#include <board/LED-lib.h>


#define LED_DATA_LINE AT91C_PIO_PA25		// Data line (Output)
#define LED_CLOCK_LINE AT91C_PIO_PA24		// Clock line (Output)

/// LED #0 pin definition.
#define LED_DATA   {LED_DATA_LINE, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_1, PIO_DEFAULT}
/// LED #1 pin definition.
#define LED_CLOCK   {LED_CLOCK_LINE, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_1, PIO_DEFAULT}

#define LED_PINS LED_DATA , LED_CLOCK

/*Use this with */
#define DATA_LINE_CLEAR     0
#define DATA_LINE_SET       1
#define CLOCK_LINE_CLEAR    2
#define CLOCK_LINE_SET      3

/// LED DS1 index.
#define LED_INDEX_DATA      0
/// LED DS2 index.
#define LED_INDEX_CLOCK      1

void Led_Init(void);


void led_flash(void);






#endif