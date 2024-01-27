/******************************************************************************************/
/******************************************************************************************/
/******************************     Name   :  Abir Omara     ******************************/
/******************************     Date   :  8/1/2023       ******************************/
/******************************     SWC    :  TIMERS         ******************************/
/******************************   Version  :  1.0            ******************************/
/******************************************************************************************/
/******************************************************************************************/

#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

#define TIMERS_u8_TIMSK    *((volatile u8 *)0x59)
#define TIMERS_u8_TIMSK_OCIE2     7
#define TIMERS_u8_TIMSK_TOIE2     6
#define TIMERS_u8_TIMSK_TICIE1    5
#define TIMERS_u8_TIMSK_OCIE1A    4
#define TIMERS_u8_TIMSK_OCIE1B    3
#define TIMERS_u8_TIMSK_TOIE1     2
#define TIMERS_u8_TIMSK_OCIE0     1
#define TIMERS_u8_TIMSK_TOIE0     0
#define TIMERS_u8_TIFR     *((volatile u8 *)0x58)
/*Timer0 registers*/
#define TIMERS_u8_TCCR0    *((volatile u8 *)0x53)
#define TIMERS_u8_TCCR0_WGM00    6
#define TIMERS_u8_TCCR0_COM01    5
#define TIMERS_u8_TCCR0_COM00    4
#define TIMERS_u8_TCCR0_WGM01    3
#define TIMERS_u8_TCCR0_CS02     2
#define TIMERS_u8_TCCR0_CS01     1
#define TIMERS_u8_TCCR0_CS00     0
#define TIMERS_u8_TCNT0    *((volatile u8 *)0x52)
#define TIMERS_u8_OCR0     *((volatile u8 *)0x5C)

/*Timer1 registers*/
#define TIMERS_u8_TCCR1A     *((volatile u8 *)0x4F)
#define TIMERS_u8_TCCR1A_COM1A1     7
#define TIMERS_u8_TCCR1A_COM1A0     6
#define TIMERS_u8_TCCR1A_COM1B1     5
#define TIMERS_u8_TCCR1A_COM1B0     4
#define TIMERS_u8_TCCR1A_WGM11      1
#define TIMERS_u8_TCCR1A_WGM10      0
#define TIMERS_u8_TCCR1B     *((volatile u8 *)0x4E)
#define TIMERS_u8_TCCR1B_WGM13     4
#define TIMERS_u8_TCCR1B_WGM12     3
#define TIMERS_u8_TCCR1B_CS12      2
#define TIMERS_u8_TCCR1B_CS11      1
#define TIMERS_u8_TCCR1B_CS10      0

#define TIMERS_u8_TCNT1H     *((volatile u8 *)0x4D)
#define TIMERS_u8_TCNT1L     *((volatile u8 *)0x4C)
#define TIMERS_u16_TCNT1     *((volatile u16 *)0x4C)

#define TIMERS_u8_OCR1AH     *((volatile u8 *)0x4B)
#define TIMERS_u8_OCR1AL     *((volatile u8 *)0x4A)
#define TIMERS_u16_OCR1A     *((volatile u16 *)0x4A)

#define TIMERS_u8_OCR1BH     *((volatile u8 *)0x49)
#define TIMERS_u8_OCR1BL     *((volatile u8 *)0x48)
#define TIMERS_u16_OCR1B     *((volatile u16 *)0x48)

#define TIMERS_u8_ICR1H     *((volatile u8 *)0x47)
#define TIMERS_u8_ICR1L     *((volatile u8 *)0x46)
#define TIMERS_u16_ICR1     *((volatile u16 *)0x46)

/*Timer2 registers*/
#define TIMERS_u8_TCCR2    *((volatile u8 *)0x45)
#define TIMERS_u8_TCCR2_WGM20    6
#define TIMERS_u8_TCCR2_COM21    5
#define TIMERS_u8_TCCR2_COM20    4
#define TIMERS_u8_TCCR2_WGM21    3
#define TIMERS_u8_TCCR2_CS22     2
#define TIMERS_u8_TCCR2_CS21     1
#define TIMERS_u8_TCCR2_CS20     0
#define TIMERS_u8_TCNT2    *((volatile u8 *)0x44)
#define TIMERS_u8_OCR2     *((volatile u8 *)0x43)

#endif
