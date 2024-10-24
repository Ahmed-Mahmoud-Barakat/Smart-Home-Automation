#include "LED.h"
#include "gpio.h"


typedef struct {
	uint8 port;
	uint8 pin;
	LED_LogicType logic;
} LED_ConfigType;

LED_ConfigType ledConfig[3];


void LEDS_init(void) {
	ledConfig[LED_RED].port = LED_PORT;
	ledConfig[LED_RED].pin = RED_LED_PIN;
	ledConfig[LED_RED].logic = LOGIC;

	ledConfig[LED_GREEN].port = LED_PORT;
	ledConfig[LED_GREEN].pin = GREEN_LED_PIN;
	ledConfig[LED_GREEN].logic = LOGIC;

	ledConfig[LED_BLUE].port = LED_PORT;
	ledConfig[LED_BLUE].pin = BLUE_LED_PIN;
	ledConfig[LED_BLUE].logic = LOGIC;

	for (int i = 0; i < 3; i++)
	{
		GPIO_setupPinDirection(ledConfig[i].port, ledConfig[i].pin, PIN_OUTPUT);
		LED_off(i);
	}
}

void LED_on(LED_ID id)
{
	if (ledConfig[id].logic == LOGIC)
	{
		GPIO_writePin(ledConfig[id].port, ledConfig[id].pin, 1);
	}
	else
	{
		GPIO_writePin(ledConfig[id].port, ledConfig[id].pin, 0);
	}
}

void LED_off(LED_ID id)
{
	if (ledConfig[id].logic == LOGIC)
	{
		GPIO_writePin(ledConfig[id].port, ledConfig[id].pin, LOGIC_LOW);
	}
	else
	{
		GPIO_writePin(ledConfig[id].port, ledConfig[id].pin, LOGIC_HIGH);
	}
}
