/******************************************************************************************/
/******************************************************************************************/
/******************************     Name   :  Abir Omara     ******************************/
/******************************     Date   :  8/1/2023       ******************************/
/******************************     SWC    :  TIMERS         ******************************/
/******************************   Version  :  1.0            ******************************/
/******************************************************************************************/
/******************************************************************************************/

#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H

#define TIMER0_u8_PRELOAD_VALUE                0
#define TIMER0_u32_NUMBER_OF_OVF               3907
#define TIMER0_u32_NUMBER_OF_CTC               10000
#define TIMER_u8_OCR0_INIT_VALUE               0

#define TIMER1_u16_PRELOAD_VALUE                64
#define TIMER1_u32_NUMBER_OF_OVF               3907
#define TIMER1_u32_NUMBER_OF_CTC               10000
#define TIMER_u16_OCR1A_INIT_VALUE             999
#define TIMER1_u16_ICR1_VALUE                  19999

#define TIMER2_u8_PRELOAD_VALUE                0
#define TIMER2_u32_NUMBER_OF_OVF               3907
#define TIMER2_u32_NUMBER_OF_CTC               10000
#define TIMER_u8_OCR2_INIT_VALUE               99

/*select mode for timer 0&2*/
#define TIMER_NORMAL_MODE                      1
#define TIMER_PHASE_CORRECT_PWM                2
#define TIMER_CTC_MODE                         3
#define TIMER_FAST_PWM                         4

/*select mode for timer 1*/
#define TIMER_NORMAL                           1
#define TIMER_PHASE_CORRECT_PWM_8bit           2
#define TIMER_PHASE_CORRECT_PWM_9bit           3
#define TIMER_PHASE_CORRECT_PWM_10bit          4
#define TIMER_CTC_OCR1A                        5
#define TIMER_FAST_PWM_8bit                    6
#define TIMER_FAST_PWM_9bit                    7
#define TIMER_FAST_PWM_10bit                   8
#define TIMER_PHASEandFREUENCY_CORRECT_ICR1    9
#define TIMER_PHASEandFREUENCY_CORRECT_OCR1A   10
#define TIMER_PHASE_CORRECT_ICR1               11
#define TIMER_PHASE_CORRECT_OCR1A              12
#define TIMER_CTC_ICR1                         13
#define TIMER_FAST_PWM_ICR1                    15
#define TIMER_FAST_PWM_OCR1A                   16

/*Select hardware action on OCx*/
#define TIMER_u8_OCX_DISCONNECTED              1
#define TIMER_u8_OCX_TOGGELE_Reserved          2
#define TIMER_u8_OCX_SET_NON_INVERTED          3
#define TIMER_u8_OCX_CLEAR_INVERTED            4


/*select interrupt enable or disable*/
#define TIMER_INTERRUPT_ENABLE                 1
#define TIMER_INTERRUPT_DISABLE                2

/*select preschaler*/
#define TIMER_CLOCK_NO_CLOCK                   1
#define TIMER_CLOCK_NO_PRESCHALER              2
#define TIMER_CLOCK_8_PRESCHALER               3
#define TIMER_CLOCK_64_PRESCHALER              4
#define TIMER_CLOCK_256_PRESCHALER             5
#define TIMER_CLOCK_1024_PRESCHALER            6
#define TIMER_CLOCK_EXTERNAL_FALLING_EDGE      7
#define TIMER_CLOCK_EXTERNAL_RISING_EDGE       8


/*select mode */
#define TIMER0_MODE                            TIMER_FAST_PWM
#define TIMER1_MODE                            TIMER_FAST_PWM_ICR1
#define TIMER2_MODE                            TIMER_PHASE_CORRECT_PWM

/*select oc pin mode */
#define TIMER_u8_OC0_PIN_MODE                  TIMER_u8_OCX_SET_NON_INVERTED
#define TIMER_u8_OC1A_PIN_MODE                 TIMER_u8_OCX_SET_NON_INVERTED
#define TIMER_u8_OC1B_PIN_MODE                 TIMER_u8_OCX_DISCONNECTED
#define TIMER_u8_OC2_PIN_MODE                  TIMER_u8_OCX_SET_NON_INVERTED

/*select OVF interrupt*/
#define TIMER0_OVF_INTERRUPT_INIT              TIMER_INTERRUPT_DISABLE
#define TIMER1_OVF_INTERRUPT_INIT              TIMER_INTERRUPT_DISABLE
#define TIMER2_OVF_INTERRUPT_INIT              TIMER_INTERRUPT_DISABLE

/*select CTC interrupt*/
#define TIMER0_CTC_INTERRUPT_INIT              TIMER_INTERRUPT_DISABLE
#define TIMER1_CTC_CHANNEL_A_INTERRUPT_INIT    TIMER_INTERRUPT_DISABLE
#define TIMER1_CTC_CHANNEL_B_INTERRUPT_INIT    TIMER_INTERRUPT_DISABLE
#define TIMER2_CTC_INTERRUPT_INIT              TIMER_INTERRUPT_DISABLE

/*select clock*/
#define TIMER0_CLOCK_SOURCE                    TIMER_CLOCK_8_PRESCHALER
#define TIMER1_CLOCK_SOURCE                    TIMER_CLOCK_8_PRESCHALER
#define TIMER2_CLOCK_SOURCE                    TIMER_CLOCK_8_PRESCHALER


#endif 
