#include "LDR.h"
#include "adc.h"

uint16 LDR_getLightIntensity(void)
{
	uint8 lightIntensity = 0;

	uint16 adcValue = 0;

	adcValue = ADC_readChannel(LDR_SENSOR_CHANNEL_ID );

	lightIntensity = (uint8)(((uint32)adcValue*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));

	return lightIntensity;

}
