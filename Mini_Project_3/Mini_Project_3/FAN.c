#include"FAN.h"
#include "gpio.h"
#include"PWM.h"
#include <avr/io.h>


void DcMotor_Init(void)
{
	GPIO_setupPinDirection(FAN_PORT,FAN_PIN_1 ,PIN_OUTPUT);
	GPIO_setupPinDirection(FAN_PORT,FAN_PIN_2 ,PIN_OUTPUT);
	GPIO_setupPinDirection(FAN_PORT,FAN_PIN_EN ,PIN_OUTPUT);

	GPIO_writePin(FAN_PORT, FAN_PIN_1, LOGIC_LOW);
	GPIO_writePin(FAN_PORT, FAN_PIN_2, LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	PWM_Timer0_Start(speed);
	switch (state)
	{
	case 0:
		GPIO_writePin(FAN_PORT, FAN_PIN_1, LOGIC_LOW);
		GPIO_writePin(FAN_PORT, FAN_PIN_2, LOGIC_HIGH);
		break;

	case 1:
		GPIO_writePin(FAN_PORT, FAN_PIN_1, LOGIC_HIGH);
		GPIO_writePin(FAN_PORT, FAN_PIN_2, LOGIC_LOW);
		break;

	case 2:
		GPIO_writePin(FAN_PORT, FAN_PIN_1, LOGIC_LOW);
		GPIO_writePin(FAN_PORT, FAN_PIN_2, LOGIC_LOW);
		speed = 0;  // Set speed to 0 to stop PWM
		break;
	default:
		break;

	}
}
