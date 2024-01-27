/******************************************************************************************/
/******************************************************************************************/
/******************************     Name   :  Abir Omara     ******************************/
/******************************     Date   :  8/1/2023       ******************************/
/******************************     SWC    :  TIMERS         ******************************/
/******************************   Version  :  1.0            ******************************/
/******************************************************************************************/
/******************************************************************************************/

#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

void TIMERS_voidTimer0Init (void);
void TIMERS_voidTimer1Init (void);
void TIMERS_voidTimer2Init (void);

u8 TIMERS_u8Timer0OVFSetCallBack (void (*Copy_pf)(void));
u8 TIMERS_u8Timer0CTCSetCallBack (void (*Copy_pf)(void));
u8 TIMERS_u8Timer1OVFSetCallBack (void (*Copy_pf)(void));
u8 TIMERS_u8Timer1CTCSetCallBack (void (*Copy_pf)(void));
u8 TIMERS_u8Timer2OVFSetCallBack (void (*Copy_pf)(void));
u8 TIMERS_u8Timer2CTCSetCallBack (void (*Copy_pf)(void));



void TIMERS_voidTimer0SetCompareMatchValue (u8 Copy_u8OCR0Value);
void TIMERS_voidTimer1SetCompareMatchValueA (u16 Copy_u16OCR1AValue);
void TIMERS_voidTimer2SetCompareMatchValueA (u8 Copy_u8OCR0Value);

#endif
