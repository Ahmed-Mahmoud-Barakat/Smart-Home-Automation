#ifndef FAN_H_
#define FAN_H_

#include "std_types.h"

#define FAN_PORT		PORTB_ID
#define FAN_PIN_1		PIN0_ID
#define FAN_PIN_2		PIN1_ID
#define FAN_PIN_EN		PIN3_ID

typedef enum {
	CW,
	ACW,
	ST
} DcMotor_State;
void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif
