#include <stdint.h>
#include "PWM.h"
#include "Motor.h"

void Motor_Init() {

  PWM_Init(14999);

  // Motor Ports
  DDRB |= 0x10; // sets PB4 as output (Sleep Pin) 
  PORTB |= 0x10; // sets PB4 low initially

  // Input Pins for the DRV8833
  DDRH |= 0x78; // sets as input
  PORTH &= ~0x78; // sets all pins low initially
  
}

