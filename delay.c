#include "delay.h"

void delay_ms(short ms)
{
	volatile short loop;

	while (ms-- > 0)
		for (loop = 0; loop < 2100; loop++);
}
