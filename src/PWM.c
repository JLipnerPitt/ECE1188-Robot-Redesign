#include <stdint.h>
#include "Arduino.h"
#include "PWM.h"

void PWM_Init(uint16_t period){

  DDRB |= 0x60; // sets PB5-PB6 as output (OC1A, OC1B)
  DDRE |= 0x30; // sets PE4-PE5 as output (OC3B, OC3C)

  TIMSK3 &= ~(0x0); // disables interupts on timer1
  TIMSK4 &= ~(0x0); // disables interupts on timer3
  OCR3A = period-1;
  OCR3B = period-1;
  OCR4B = period-1;
  OCR4C = period-1;

  // Timer3
  TCCR3A &= ~(0xF3); // Clears WGM bits, COM1A bits, and COM1B bits 
  TCCR3A |= 0xF3; // sets WGM bits(11), COM1A bits(11), and COM1B bits(11) 
                  // makes pins OC1A and OC1B able to generate PWM signals
  TCCR3B &= ~(0x41); // Clears WGM bits, and CSn bits                
  TCCR3B |= 0x41; // sets WGM bits(10), and CSn bits(001)
                  // (makes clock 16 MHz), and divides clock by 1 (no prescaling), respectively
  
  // Timer4
  TCCR4A &= ~(0x3F); // Clears WGM bits, COM3B bits, and COM3C bits
  TCCR4A |= 0x3F;    // sets WGM bits(11), COM1A bits(11), and COM1B bits(11)
                     // makes pins OC3B and OC3C able to generate PWM signals
  TCCR4B &= ~(0x41); // Clears WGM bits, and CSn bits                 
  TCCR4B |= 0x41; // sets WGM bits(10), and CSn bits(001)
                  // (makes clock 16 MHz), and divides clock by 1 (no prescaling), respectively
  

  
  

  
  /*TIMER_A0->CCTL[0] = 0x0080;      // CCI0 toggle ( disables interrupts)
  TIMER_A0->CCR[0] = period-1;       // Period is 2*period*8*83.33ns is 1.333*period
  TIMER_A0->EX0 = 0x0000;          // divide by 1
  TIMER_A0->CCTL[3] = 0x0040;      // CCR3 toggle/reset
  TIMER_A0->CCR[3] = 0;        // CCR3 duty cycle is duty3/period
  TIMER_A0->CCTL[4] = 0x0040;      // CCR4 toggle/reset
  TIMER_A0->CCR[4] = 0;        // CCR4 duty cycle is duty4/period
  TIMER_A0->CTL = 0x02F0;          // SMCLK=12MHz, divide by 8, up-down mode*/
}

void PWM_Duty(uint16_t Duty3, uint16_t Duty4){

  /*TIMER_A0->CCR[3] = Duty3;        // CCR3 duty cycle is duty3/period
  TIMER_A0->CCR[4] = Duty4;       // CCR4 duty cycle is duty4/period*/
}