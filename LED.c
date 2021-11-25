#include "LED.h"
//------------------------------------------------------------------------------
//         Internal variables
//------------------------------------------------------------------------------

#ifdef LED_PINS
static const Pin Leds[] = {LED_PINS};
static const unsigned int numLeds = PIO_LISTSIZE(Leds);
#endif

void Led_Init(void)
{
/*Configure leds as output */  
unsigned char Error_status = PIO_Configure(Leds,numLeds);
data_clock_clear_set(DATA_LINE_CLEAR);
data_clock_clear_set(CLOCK_LINE_CLEAR);

}


void led_ALL_flash()
{
	//SetLEDcolor(LED1,RED);
    SetAllLEDs(LEDsAllRed);
    delay_ms(100);
	SetAllLEDs(LEDsAllOff);
	delay_ms(100);

}

void led_ONE_flash(unsigned char led_num)
{
	SetLEDcolor(led_num,RED);
    delay_ms(100);
	SetLEDcolor(led_num,OFF);
	delay_ms(100);

}

void small_fun(void)
{static int i=0;
    for(i=0 ;i<8 ; i++){
        SetLEDcolor(i,OFF);
        delay_ms(1000);
    }

}

void turn_0ff_rate_1Sec(void)
{
SetAllLEDs(LEDsAllRed);
delay_ms(1000);
small_fun();
SetLEDcolor(LED4,GREEN);
}

void data_clock_clear_set( unsigned char command )
{
switch (command)
{
case DATA_LINE_CLEAR:
    /* code */
     PIO_Clear(&Leds[LED_INDEX_DATA]);
    break;
case DATA_LINE_SET:
    PIO_Set(&Leds[LED_INDEX_DATA]);
    /* code */
    break;
case CLOCK_LINE_CLEAR:
    /* code */
        PIO_Clear(&Leds[LED_INDEX_CLOCK]);
    break;
case CLOCK_LINE_SET:
    /* code */
        PIO_Set(&Leds[LED_INDEX_CLOCK]);
    break;
}

}


