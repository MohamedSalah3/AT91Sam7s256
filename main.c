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
#if 0
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

#endif

uint32_t Time,Time_start,Time_end =  0 ,STatus = 0, State_Machine = 0;

#define NONE     0
#define START_COUNTING_TIME  2
#define STOP_COUNTING_TIME   3


#define OVF_HAPPENED    1
#define OVF_DID_NOT     0

int main()
{
	 Led_Init();
	
	 Button_all_init();

	 OLED_Init();
	 
	 ConfigureOLEDdisplay();
	 SetOLEDdisplayMode(TextDisplay);
	 ClearOLEDdisplay();

	 /*
	 * Display the values of the global loader variables
	 *
	 * These are pointer variables, so we need to display their address
	 * rather than the contents of the location.
	 */

		

	    Timer_Init(&PIT_Configuration0);
		Timer_Start(&PIT_Configuration0);

	

	while(1)	
	{

			led_ALL_flash();
		if(IsButtonPressed(BUTTON1))
			{	
		    	if((State_Machine==NONE) || (State_Machine ==STOP_COUNTING_TIME ))
				{
					State_Machine = START_COUNTING_TIME;
				}
				if(State_Machine==START_COUNTING_TIME)
				{
					State_Machine = STOP_COUNTING_TIME;
				}

				/*Dispalay is zeroed here*/
					 ClearOLEDdisplay();
					 	printf("%c", '0');

					
					

			}
			if(State_Machine == START_COUNTING_TIME)
			{
				
				/*Start counting time */
				Timer_GetValue(PIT_TIMER,&Time_start);
				
			
		     	led_ONE_flash(LED1);
			}
			if(State_Machine == STOP_COUNTING_TIME)
			{
				Timer_GetValue(PIT_TIMER,&Time_end);	
				Timer_GetStatus(PIT_TIMER,&STatus);
				/* STOP_COUNTING_TIME */
				Timer_Stop(PIT_TIMER);
				/*Display the time */
				if(STatus == OVF_HAPPENED){
                Time = (Time_end + (2^20)) -Time_start ;
				}else{

					Time=Time_end-Time_start;

				}
				printf("%ld\n", Time);
			  
			}	


	}
	return 0;
}


