#include <stdint.h>
#include "PWM.h"
#include "Motor.h"
#include <Arduino.h>

void Motor_Init(uint16_t period) {
  PWM_Init(period);

  // Motor Ports
  DDRL &= ~(0x40);
  DDRL |= 0x40; // sets PL6 as output (Sleep Pin) 
  PORTL &= ~(0x40); // sets PL6 high initially

  // Input Pins for the DRV8833
  // sets all pins high initially (stop state)
}

void Motor_Stop(uint16_t leftDuty, uint16_t rightDuty) {
  PORTL &= ~(0x40);
  PWM_Duty(0,0,0,0);
}

void Motor_Forward(uint16_t leftDuty, uint16_t rightDuty) {
  PORTL |= 0x40;
  PWM_Duty(rightDuty,0,leftDuty,0);
}

void Motor_Backwards(uint16_t leftDuty, uint16_t rightDuty) {
  PORTL |= 0x40;
  PWM_Duty(0,rightDuty,0,leftDuty);
}

void Motor_Left(uint16_t leftDuty, uint16_t rightDuty) {
  PORTL |= 0x40;
  PWM_Duty(0,rightDuty,leftDuty,0);
}

void Motor_Right(uint16_t leftDuty, uint16_t rightDuty) {
  PORTL |= 0x40;
  PWM_Duty(rightDuty,0,0,leftDuty);
}

