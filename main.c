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

int main()
{
	Led_Init();
	unsigned char error_status = Button_all_init(4);
	
	OLED_Init();
while(1)
{
	led_flash();


}
	return 0;
}

