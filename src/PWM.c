#include <stdint.h>
#include "Arduino.h"
#include "PWM.h"

void PWM_Init(uint16_t period){

  P2->DIR |= 0xC0;          // P2.6, P2.7 output
  P2->SEL0 |= 0xC0;         // P2.6, P2.7 Timer0A functions
  P2->SEL1 &= ~0xC0;        // P2.6, P2.7 Timer0A functions
  TIMER_A0->CCTL[0] = 0x0080;      // CCI0 toggle
  TIMER_A0->CCR[0] = period-1;       // Period is 2*period*8*83.33ns is 1.333*period
  TIMER_A0->EX0 = 0x0000;          // divide by 1
  TIMER_A0->CCTL[3] = 0x0040;      // CCR3 toggle/reset
  TIMER_A0->CCR[3] = 0;        // CCR3 duty cycle is duty3/period
  TIMER_A0->CCTL[4] = 0x0040;      // CCR4 toggle/reset
  TIMER_A0->CCR[4] = 0;        // CCR4 duty cycle is duty4/period
  TIMER_A0->CTL = 0x02F0;          // SMCLK=12MHz, divide by 8, up-down mode
}

void PWM_Duty(uint16_t Duty3, uint16_t Duty4){

  TIMER_A0->CCR[3] = Duty4;        // CCR4 duty cycle is duty4/period
  TIMER_A0->CCR[4] = Duty3;       // CCR3 duty cycle is duty3/period
}