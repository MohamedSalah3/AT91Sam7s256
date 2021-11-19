#include "Button.h"


       static const Pin at91board_Buttons[] = 
       {
            {AT91C_BASE_PIOA, AT91C_PIO_PA26, PIO_INPUT, PIO_PULLUP},
            {AT91C_BASE_PIOA, AT91C_PIO_PA27, PIO_INPUT, PIO_PULLUP},
            {AT91C_BASE_PIOA, AT91C_PIO_PA28, PIO_INPUT, PIO_PULLUP},
            {AT91C_BASE_PIOA, AT91C_PIO_PA29, PIO_INPUT, PIO_PULLUP}
       };


void Button_init(void){
unsigned char Error_status = PIO_Configure(at91board_Buttons,SIZE);
}

