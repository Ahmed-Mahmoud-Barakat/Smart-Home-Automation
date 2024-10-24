#ifndef FLAME_H_
#define FLAME_H_

#include "std_types.h"

#define FLAME_PORT		PORTD_ID
#define FLAME_PIN		PIN2_ID

void FlameSensor_init(void);

uint8 FlameSensor_getValue(void);

#endif
