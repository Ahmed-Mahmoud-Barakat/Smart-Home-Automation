#include "flameSensor.h"
#include "gpio.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_PORT,FLAME_PIN,PIN_INPUT);
}

uint8 FlameSensor_getValue(void)
{
	return (GPIO_readPin(FLAME_PORT,FLAME_PIN)) ? 1 : 0 ;
}
