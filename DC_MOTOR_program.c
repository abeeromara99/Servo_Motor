/******************************************************************************************/
/******************************************************************************************/
/******************************     Name   :  Abir Omara     ******************************/
/******************************     Date   :  12/12/2023     ******************************/
/******************************     SWC    :  DC_MOTOR       ******************************/
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
#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_config.h"

void DCMotor_Move (u8 Copy_u8Direction)
{
	if (Copy_u8Direction == MOVE_CW)
	{
		DIO_u8SetPinValue(DC_MOTOR_u8_PORT,DIO_u8_PIN0,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue(DC_MOTOR_u8_PORT,DIO_u8_PIN1,DIO_u8_PIN_LOW);
	}
	else if (Copy_u8Direction == MOVE_CCW)
	{
		DIO_u8SetPinValue(DC_MOTOR_u8_PORT,DIO_u8_PIN0,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue(DC_MOTOR_u8_PORT,DIO_u8_PIN1,DIO_u8_PIN_HIGH);
    }
    else if (Copy_u8Direction == STOP)
	{
		DIO_u8SetPinValue(DC_MOTOR_u8_PORT,DIO_u8_PIN0,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue(DC_MOTOR_u8_PORT,DIO_u8_PIN1,DIO_u8_PIN_LOW);
    }
}
