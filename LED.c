#include "LED.h"

#define SIZE 2

       static const Pin at91board_led[] = 
       { /*Led Configurations */
            {AT91C_BASE_PIOA, LED_CLOCK_LINE, PIO_OUTPUT_1, PIO_DEFAULT},
            {AT91C_BASE_PIOA, LED_DATA_LINE, PIO_OUTPUT_1, PIO_DEFAULT}
       };

void Led_Init(void)
{
/*Configure leds as output */  
unsigned char Error_status = PIO_Configure(at91board_led,SIZE);
clear_leds(); 

}


void led_flash()
{
	SetLEDcolor(LED1,RED);
	delay_ms(100);
	SetLEDcolor(LED1,OFF);
	delay_ms(100);

}



static void clear_leds(void)
{	/*
	 * Clear all the LEDs
	 */
	AT91C_BASE_PIOA->PIO_CODR = LED_CLOCK_LINE;
	AT91C_BASE_PIOA->PIO_SODR = LED_DATA_LINE;    
}