#include "IO.h"
#include "delay.h"
#include "TIM.h"
#include "math.h"
#include "stdlib.h"


void IO_Init(void)
{
	LED_4_OUT;
	LED_4_RESET;
	KEY_IN;
}
