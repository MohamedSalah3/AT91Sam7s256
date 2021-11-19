#include "OLED.h"


/// OLED #0 pin definition.
#define OLED_pin0  {AT91C_PIO_PA10, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_1, PIO_DEFAULT}
/// OLED #1 pin definition.
#define OLED_pin1  {AT91C_PIO_PA13, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_1, PIO_DEFAULT}

/// OLED #2 pin definition.
#define OLED_pin2  {AT91C_PIO_PA14 , AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_1, PIO_DEFAULT}

/// OLED #3 pin definition.
#define OLED_pin3  {AT91C_PIO_PA25 , AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_1, PIO_DEFAULT}


#define OLED_PINS OLED_pin0 , OLED_pin1, OLED_pin2 ,OLED_pin3


#define SIZE 4
       static const Pin at91board_OLED[] ={OLED_PINS};


unsigned char OLED_Init(void)
{
    unsigned char Error_status = PIO_Configure(at91board_OLED,SIZE);
return Error_status;
}
