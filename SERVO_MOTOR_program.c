/******************************************************************************************/
/******************************************************************************************/
/******************************     Name   :  Abir Omara     ******************************/
/******************************     Date   :  26/1/2023      ******************************/
/******************************     SWC    :  SERVO_MOTOR    ******************************/
/******************************   Version  :  1.0            ******************************/
/******************************************************************************************/
/******************************************************************************************/

/* Lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#define F_CPU   8000000UL

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "SERVO_MOTOR_interface.h"
#include "SERVO_MOTOR_config.h"
#include "TIMERS_interface.h"

void ServoMotor_voidInit ()
{
	TIMERS_voidTimer1Init();
}

void ServoMotor_Angle (u8 Copy_u8Degree)
{
	u32 Local_OCR1A_Value =((Copy_u8Degree*1000UL)/180)+999;
    TIMERS_voidTimer1SetCompareMatchValueA(Local_OCR1A_Value);
	
}
