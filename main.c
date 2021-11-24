/*
 * ARM Project Template - main file
 */
#include <atmel/pio.h>
#include <board/LED-lib.h> /* Provide access to LEDs */
#include <board/Button-lib.h> /* Provide access to buttons */
#include <board/OLED-lib.h>
#include "LED.h"
#include "OLED.h"
#include "Button.h"
#include "delay.h"
#include "PIT.h"
/*
 * Define the direction codes for the movement of the LEDs.
 */
#define LEFT  0
#define RIGHT 1

/*
 * Main function - Program execution begins here!
 */

int main()
{
	/*
	 * Declare a variable to store the number of an LED.
	 */
	LEDnumber LEDpos, LeftEnd, RightEnd;

	short LeftRight;
	Led_Init();
	/*Timer Intialization */
	uint32_t clock_count = 2000;
	unsigned char error = Timer_Init(&PIT_Configuration0);
	error =Timer_Start(PIT_TIMER,&clock_count);
	
	
	OLED_Init();
	unsigned char error_status = Button_all_init();
	
	/*
	 * First set the LED position variable to the first LED.
	 */
	LEDpos = LED1;

	/*
	 * Now set the end markers. This is the point at which the lit LED changes
	 * direction.
	 */
	LeftEnd = LED1;
	RightEnd = LED8;

	/*
	 * Now set the direction of LED movement.
	 */
	LeftRight = RIGHT;

	/*
	 * This loop moves the lit LED along the row of LEDs until it hits the end.
	 * It then bounces back towards the other end.
	 *
	 * This loops continues until the right hand most button is pressed.
	 */
	while(IsButtonReleased(BUTTON8))
	{
		/*
		 * Display the lit LED for a short period of time
		 */
		SetLEDcolor(LEDpos, RED);
		delay_ms(100);
		SetLEDcolor(LEDpos, OFF);

		/*
		 * Has it reached the end yet? If so, change the direction of travel indicator.
		 */
		if (LEDpos == LeftEnd) LeftRight = RIGHT;
		if (LEDpos == RightEnd) LeftRight = LEFT;

		/*
		 * Now move the LED to its new position.
		 */
		if (LeftRight == RIGHT)
			LEDpos++;
		else
			LEDpos--;
	}

	/*
	 * Flash the LEDs before exiting
	 */
	SetAllLEDs(LEDsAllRed);
	delay_ms(500);
	SetAllLEDs(LEDsAllGreen);
	delay_ms(500);
	SetAllLEDs(LEDsAllOrange);
	delay_ms(500);
	SetAllLEDs(LEDsAllOff);
	delay_ms(500);

	return 0;
}


/*
int main()
{
	Led_Init();
	unsigned char error_status = Button_all_init();

	OLED_Init();

	while(1)	
	{
	led_flash();
	}
	return 0;
}

*/