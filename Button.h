#ifndef _BUTTON_H_
#define _BUTTON_H_



#include <atmel/pio.h>
#include <boards/at91sam7s-ek/at91sam7s256/AT91SAM7S256.h>
#include <board/Button-lib.h>


#define SIZE 4
#define SWITCH_SELECT_LINE AT91C_PIO_PA25	// Select line (Output)
#define SWITCH_BUTTON_4_8 AT91C_PIO_PA26	// Button 4 or 8 (Input)
#define SWITCH_BUTTON_3_7 AT91C_PIO_PA27	// Button 3 or 7 (Input)
#define SWITCH_BUTTON_2_6 AT91C_PIO_PA28	// Button 2 or 6 (Input)
#define SWITCH_BUTTON_1_5 AT91C_PIO_PA29	// Button 1 or 5 (Input)


void Button_init(void);











#endif