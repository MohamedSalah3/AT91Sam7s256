#include "OLED.h"

#define SIZE 4
       static const Pin at91board_OLED[] = 
       {
            {AT91C_BASE_PIOA, AT91C_PIO_PA10, PIO_OUTPUT_0, PIO_DEFAULT},
            {AT91C_BASE_PIOA, AT91C_PIO_PA13, PIO_OUTPUT_0, PIO_DEFAULT},
            {AT91C_BASE_PIOA, AT91C_PIO_PA14, PIO_OUTPUT_0, PIO_DEFAULT},
            {AT91C_BASE_PIOA, AT91C_PIO_PA25, PIO_OUTPUT_0, PIO_DEFAULT}
       };


void OLED_Init(void)
{
    unsigned char Error_status = PIO_Configure(at91board_OLED,SIZE);
}
