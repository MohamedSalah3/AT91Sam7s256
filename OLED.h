#ifndef _OLED_H_
#define _OLED_H_
#include <atmel/pio.h>
#include <boards/at91sam7s-ek/at91sam7s256/AT91SAM7S256.h>
#include "../at91lib/include/atmel/spi.h"


unsigned char OLED_Init(void);


void OLED_Disable(void);


void OLED_Enable(void);

#endif