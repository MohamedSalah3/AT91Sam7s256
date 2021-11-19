#include "LED.h"

#define SIZE 2

       static const Pin at91board_led[] = 
       {
            {AT91C_BASE_PIOA, LED_CLOCK_LINE, PIO_OUTPUT_1, PIO_DEFAULT},
            {AT91C_BASE_PIOA, LED_DATA_LINE, PIO_OUTPUT_1, PIO_DEFAULT}
       };

void Led_Init(void)
{
  
unsigned char Error_status = PIO_Configure(at91board_led,SIZE);

}


void led_flash()
{
	SetLEDcolor(LED1,RED);
	delay_ms(100);
	SetLEDcolor(LED1,OFF);
	delay_ms(100);

}
