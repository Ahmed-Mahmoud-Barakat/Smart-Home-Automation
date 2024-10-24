#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "LDR.h"
#include "LED.h"
#include"buzzer.h"
#include "flameSensor.h"
#include"FAN.h"
#include"PWM.h"

int main(void)
{
	uint16 light_Intensity;
	uint8 temp;
	uint8 speed;
	LCD_init(); /* initialize LCD driver */
	ADC_init(); /* initialize ADC driver */
	LEDS_init();
	FlameSensor_init();
	Buzzer_init();
	DcMotor_Init();
	PWM_Timer0_Start(0);
	LCD_moveCursor(1,8);
	LCD_displayString("LDR=    ");
	LCD_moveCursor(1,15);
	LCD_displayString("%");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp=  ");
	while(1)
	{
		light_Intensity = LDR_getLightIntensity();
		LCD_moveCursor(1,12);
		if(light_Intensity<15)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
			LCD_intgerToString(light_Intensity);
			LCD_displayCharacter(' ');
		}
		else if(light_Intensity >= 16 && light_Intensity <= 50)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_off(LED_BLUE);
			LCD_intgerToString(light_Intensity);

		}
		else if(light_Intensity >= 51 && light_Intensity <= 70)
		{
			LED_on(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
			LCD_intgerToString(light_Intensity);

		}
		else if(light_Intensity > 70)
		{
			LED_off(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
			LCD_intgerToString(light_Intensity);
			if(light_Intensity < 100)
			{
				LCD_moveCursor(1,14);
				LCD_displayCharacter(' ');
			}
		}

		if(FlameSensor_getValue())
		{
			Buzzer_on();
			LCD_clearScreen();
			while(FlameSensor_getValue())
			{
				LCD_moveCursor(0,1);
				LCD_displayString("Critical Alert!");
			}
			LCD_clearScreen();
			LCD_moveCursor(1,8);
			LCD_displayString("LDR=    ");
			LCD_moveCursor(1,15);
			LCD_displayString("%");
			LCD_moveCursor(1,0);
			LCD_displayString("Temp=  ");
		}
		else
		{
			Buzzer_off();
		}

		temp= LM35_getTemperature();
		LCD_moveCursor(1,5);
		if(temp >= 100)
		{
			temp=99;
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		if(temp<25)
		{
			LCD_moveCursor(0,3);
			LCD_displayString("FAN IS OFF");
			if(speed==0)
			{
				continue;
			}
			else
			{
				speed=0;
			}
			DcMotor_Rotate(ST,speed);

		}
		else if(temp>=25 && temp<30)
		{
			LCD_moveCursor(0,3);
			LCD_displayString("FAN IS ON");
			LCD_displayCharacter(' ');
			if(speed==25)
			{
				continue;
			}
			else
			{
				speed=25;
			}
			DcMotor_Rotate(CW,speed);

		}
		else if(temp>=30 && temp<35)
		{
			LCD_moveCursor(0,3);
			LCD_displayString("FAN IS ON");
			if(speed==50)
			{
				continue;

			}
			else
			{
				speed=50;
			}
			DcMotor_Rotate(CW,speed);
		}
		else if(temp>=35 && temp<40)
		{
			LCD_moveCursor(0,3);
			LCD_displayString("FAN IS ON");
			if(speed==75)
			{
				continue;
			}
			else
			{
				speed=75;
			}
			DcMotor_Rotate(CW,speed);
		}
		else if(temp>=40)
		{
			LCD_moveCursor(0,3);
			LCD_displayString("FAN IS ON");
			if(speed==100)
			{
				continue;
			}
			else
			{
				speed=100;
			}
			DcMotor_Rotate(CW,speed);
		}
	}
}
