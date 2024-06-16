#include <stdint.h>
#include "Arduino.h"
#include "PWM.h"

void PWM_Init(uint16_t period){

  DDRH |= 0x18; // sets PB5-PB6 as output (OC3A, OC3B)
  DDRE |= 0x30; // sets PE4-PE5 as output (OC4B, OC4C)

  TIMSK3 &= ~(0x0); // disables interupts on timer3
  TIMSK4 &= ~(0x0); // disables interupts on timer4

  // sets top value
  ICR3 = period - 1;
  ICR4 = period - 1;

  // Timer3
  TCCR3A &= ~(0xA2); // Clears WGM bits, COM3A bits, and COM3B bits 
  TCCR3A |= 0xA2; // WGM bits(10), COM3A bits(10), and COM3B bits(10), COM3C bits(00) 
  TCCR3B &= ~(0x11); // Clears WGM bits, and CSn bits                
  TCCR3B |= 0x11; // WGM bits(10), and CSn bits(001)
                  // (makes clock 16 MHz), and divides clock by 1 (no prescaling), respectively
  
  // Timer4
  TCCR4A &= ~(0x2A); // Clears WGM bits, COM4B bits, and COM4C bits
  TCCR4A |= 0x2A;    // WGM bits(10), COM4A bits (00), COM4B bits(10), and COM4C bits(10)
  TCCR4B &= ~(0x11); // Clears WGM bits, and CSn bits                 
  TCCR4B |= 0x11; // sets WGM bits(10), and CSn bits(001)
                  // (makes clock 16 MHz), and divides clock by 1 (no prescaling), respectively
  
  OCR3A = 0;
  OCR3B = 0;
  OCR4B = 0;
  OCR4C = 0;

  /*TIMER_A0->CCTL[0] = 0x0080;      // CCI0 toggle
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