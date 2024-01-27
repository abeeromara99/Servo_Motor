/*
 * TIMERS_ass4.c
 *
 *  Created on: Jan 27, 2024
 *      Author: Abir Omara
 */


/* Lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#define F_CPU   8000000UL

/* MCAL */
#include "DIO_interface.h"
#include "TIMERS_interface.h"

/* HAL */
#include "KPD_interface.h"
#include "LCD_interface.h"
#include "DC_MOTOR_interface.h"
#include "STEPPER_MOTOR_interface.h"
#include "SERVO_MOTOR_interface.h"


u8 GetPassword (void);
u8 Angle (void);

int main (void)
{
	u8 Local_u8Key;
	u8 Password_Flag;
	DIO_voidInit();
	LCD_voidInit();
	u8 Local_u8Choose_motor=0,Local_u8Choose_motor_direction=0;
	u16 Local_u8Angle;
	//TIMERS_voidTimer1Init();
	Password_Flag=GetPassword();

	while (1)
	{
		if (Password_Flag ==1)
		{
			LCD_voidClearDisplay();
			LCD_u8GoToXY(1,0);
			LCD_voidWriteString("you tried 3     times");
			_delay_ms(1000);
			LCD_voidClearDisplay();
			LCD_u8GoToXY(1,0);
			LCD_voidWriteString("wait for 5 sec  and try later");
			_delay_ms(5000);
			LCD_voidClearDisplay();
			Password_Flag=GetPassword();

		}
		else if (Password_Flag ==0)
		{
			LCD_voidClearDisplay();
			LCD_u8GoToXY(1,0);
			LCD_voidWriteString("Welcome to motor Dash Board");
			_delay_ms(3000);
			LCD_voidClearDisplay();
			LCD_u8GoToXY(1,0);
			LCD_voidWriteString("1-DC     3-Servo2-Stepper 4-Exit");
			Local_u8Choose_motor=0;
			while (Local_u8Choose_motor !=1)
			{
				KPD_u8GetKeyState(&Local_u8Key);
				if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
				{
					switch (Local_u8Key)
					{
					case '1':
						LCD_voidClearDisplay();
						LCD_u8GoToXY(1,0);
						LCD_voidWriteString("1-cw       2-ccw3-Stop    4-back");
						Local_u8Choose_motor_direction=0;
						while (Local_u8Choose_motor_direction!=1)
						{
							KPD_u8GetKeyState(&Local_u8Key);
							if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
							{
								LCD_voidClearDisplay();
								LCD_u8GoToXY(1,0);
								LCD_voidSendData(Local_u8Key);

								switch (Local_u8Key)
								{
								case '1':
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Rotate CW");
									DCMotor_Move(MOVE_CW);
									break;
								case '2':
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Rotate CCW");
									DCMotor_Move(MOVE_CCW);
									break;
								case '3':
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Stop");
									DCMotor_Move(STOP);
									break;
								default:
									Local_u8Choose_motor_direction=1;
									Local_u8Choose_motor=1;
								}
							}
						}
						break;
					case '2':
						LCD_voidClearDisplay();
						LCD_u8GoToXY(1,0);
						LCD_voidWriteString("Angle:");
						Local_u8Angle=Angle();
						LCD_voidClearDisplay();
						LCD_u8GoToXY(1,0);
						LCD_voidWriteString("1-cw       2-ccw3-back");
						Local_u8Choose_motor_direction=0;
						while (Local_u8Choose_motor_direction!=1)
						{
							KPD_u8GetKeyState(&Local_u8Key);
							if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
							{
								LCD_voidClearDisplay();
								LCD_u8GoToXY(1,0);
								LCD_voidSendData(Local_u8Key);
								switch (Local_u8Key)
								{
								case '1':
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Rotate CW");
									StepperMotor_Move_CW(Local_u8Angle);
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Rotate CW Done");
									break;
								case '2':
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Rotate CCW");
									StepperMotor_Move_CCW(Local_u8Angle);
									LCD_u8GoToXY(2,0);
									LCD_voidWriteString("Rotate CCW Done");
									break;
								default:
									Local_u8Choose_motor_direction=1;
									Local_u8Choose_motor=1;
								}
							}
						}
						break;
					case '3':
						LCD_voidClearDisplay();
						LCD_u8GoToXY(1,0);
						LCD_voidWriteString("Angle:");
						Local_u8Angle=Angle();
						LCD_voidClearDisplay();
						LCD_u8GoToXY(1,0);
						LCD_voidWriteString("Moved to your   angle");
						ServoMotor_voidInit();
						ServoMotor_Angle(Local_u8Angle);
						break;
					case '4':
						Local_u8Choose_motor=1;
						LCD_voidClearDisplay();
						Password_Flag=GetPassword();
						break;
					}
				}
			}

		}

	}
	return 0;
}


u8 GetPassword (void)
{
	u8 Correct_password [4]={'1','1','1','1'};
	u8 Input_password [4];
	u8 Local_u8Counter=0,Local_u8Key;
	u8 Local_u8NumOfAttempts=0;
	u8 Local_u8NumOfMaxAttempts=3;
	u8 Local_u8Flag=0;
	for  (Local_u8NumOfAttempts=0; Local_u8NumOfAttempts< Local_u8NumOfMaxAttempts;Local_u8NumOfAttempts++)
	{
		LCD_u8GoToXY(1,0);
		LCD_voidWriteString("Enter password");
		while (Local_u8Counter != 4)
		{
			KPD_u8GetKeyState(&Local_u8Key);
			//if there are no switch pressed
			//no displaying on LCD
			if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
			{
				LCD_u8GoToXY(2,Local_u8Counter);
				LCD_voidSendData(Local_u8Key);
				_delay_ms(200);
				LCD_u8GoToXY(2,Local_u8Counter);
				LCD_voidSendData('*');
				Input_password[Local_u8Counter]=Local_u8Key;
				Local_u8Counter++;
			}
		}
		if ((Input_password[0]==Correct_password[0]) && (Input_password[1]==Correct_password[1]) && (Input_password[2]==Correct_password[2])  &&(Input_password[3]==Correct_password[3]))
		{
			Local_u8Flag=0;
			Local_u8NumOfAttempts=4;
			break;
		}
		else
		{
			LCD_voidClearDisplay();
			LCD_u8GoToXY(1,0);
			LCD_voidWriteString("incorrect       password");
			_delay_ms(500);
			LCD_voidClearDisplay();
			//LCD_u8GoToXY(1,0);
			//LCD_voidWriteString("try again");
			//_delay_ms(1000);
			Local_u8Counter=0;
			Local_u8Flag=1;
		}

	}
	return Local_u8Flag;
}

u8 Angle (void)
{
	u8 Local_u8CounterAngle=0,Local_u8Key,Local_u8AAngle[3];
	while (Local_u8CounterAngle != 3)
	{
		KPD_u8GetKeyState(&Local_u8Key);
		if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
		{
			LCD_u8GoToXY(1,Local_u8CounterAngle+7);
			LCD_voidSendData(Local_u8Key);
			_delay_ms(200);
			Local_u8AAngle[Local_u8CounterAngle]=Local_u8Key;
			Local_u8CounterAngle++;
		}
	}
	/*we subtract 48 to convert ASCII to digit*/
	u8 a=Local_u8AAngle[0]-48,b=Local_u8AAngle[1]-48,c=Local_u8AAngle[2]-48;
	return a*100+b*10+c;
}

