#ifndef _BUTTON_H_
#define _BUTTON_H_



#include <atmel/pio.h>
#include <boards/at91sam7s-ek/at91sam7s256/AT91SAM7S256.h>
#include <board/Button-lib.h>


/// Push button #0 definition.
#define SWITCH_BUTTON_4_8    {AT91C_PIO_PA26, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// Push button #1 definition.
#define SWITCH_BUTTON_3_7    {AT91C_PIO_PA27, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// Push button #2 definition
#define SWITCH_BUTTON_2_6    {AT91C_PIO_PA28, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// Push button #3 definition.
#define SWITCH_BUTTON_1_5    {AT91C_PIO_PA29, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}

#define PINS_SWITCHES    SWITCH_BUTTON_4_8, SWITCH_BUTTON_3_7, SWITCH_BUTTON_2_6, SWITCH_BUTTON_1_5

/*use this with unsigned char Button_init(unsigned int Swtich)*/
 /// Push button #1 index.
#define PUSHBUTTON_4_8   0
/// Push button #2 index.
#define PUSHBUTTON_3_7   1
/// Push button #3 index.
#define PUSHBUTTON_2_6   2
/// Push button #4 index.
#define PUSHBUTTON_1_5   3

/**
 * @brief 
 * 
 * @return unsigned char 
 */

unsigned char Button_init(unsigned int Swtich);
/**
 * @brief 
 * 
 * @return unsigned char 
 */

unsigned char Button_all_init(void);








#endif