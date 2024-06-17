#include <stdint.h>
#include "Arduino.h"
#include "PWM.h"

void PWM_Init(uint16_t period){

  DDRH |= 0x18; // sets PB5-PB6 as output (OC3A, OC3B)
  DDRE |= 0x30; // sets PE4-PE5 as output (OC4B, OC4C)

  TIMSK3 &= 0; // disables interupts on timer3
  TIMSK4 &= 0; // disables interupts on timer4

  // sets top value for each timer
  ICR3 = period - 1;
  ICR4 = period - 1;

  // Timer3
  TCCR3A &= ~(0x16); // Clears WGM bits, COM3B bits, and COM3C bits 
  TCCR3A |= 0x16; // COM3A bits(00), COM3B bits(01), COM3C bits(01), and WGM bits(01) 
  TCCR3B &= ~(0x12); // Clears WGM bits, and CSn bits                
  TCCR3B |= 0x12; // WGM bits(10), and CSn bits(010) (divides clock by 8)  
  // Timer4
  TCCR4A &= ~(0x52); // Clears WGM bits, COM4A bits, and COM4B bits
  TCCR4A |= 0x52;    // WGM bits(10), COM4A bits (10), COM4B bits(10), and COM4C bits(00)
  TCCR4B &= ~(0x12); // Clears WGM bits, and CSn bits                 
  TCCR4B |= 0x12; // sets WGM bits(10), and CSn bits(010) (divides clock by 8)
  
  OCR4A = 0;
  OCR4B = 0;
  OCR3B = 0;
  OCR3C = 0;
}

/*Left Motor:
  OCR4A = Duty3 (IN3)
  OCR4B = Duty4 (IN4)
  
  Right Motor:
  OCR3B = Duty1 (IN1)
  OCR3C = Duty2 (IN2)
*/
void PWM_Duty(uint16_t Duty1, uint16_t Duty2, uint16_t Duty3, uint16_t Duty4){

  OCR4A = Duty3;
  OCR4B = Duty4;
  OCR3B = Duty1;
  OCR3C = Duty2;
}