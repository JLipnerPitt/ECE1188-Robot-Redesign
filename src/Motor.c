#include <stdint.h>
#include "PWM.h"
#include "Motor.h"
#include <Arduino.h>

void Motor_Init() {
  PWM_Init(14999);

  // Motor Ports
  DDRL |= 0x40; // sets PL6 as output (Sleep Pin) 
  PORTL |= 0x40; // sets PL6 high initially

  // Input Pins for the DRV8833
  // sets all pins high initially (stop state)
  PORTH |= 0x18;
  PORTE |= 0x30;
}

void Motor_Stop(uint16_t leftDuty, uint16_t rightDuty) {
  PORTH |= 0x18; // sets OC4A and OC4B pins
  PORTE |= 0x30; // sets OC3B and OC3C pins
}

void Motor_Forward(uint16_t leftDuty, uint16_t rightDuty) {
  PWM_Duty(rightDuty,0,leftDuty,0);
}

void Motor_Backward(uint16_t leftDuty, uint16_t rightDuty) {
  PWM_Duty(0,rightDuty,0,leftDuty);
}

void Motor_Left(uint16_t leftDuty, uint16_t rightDuty) {
  PWM_Duty(0,rightDuty,leftDuty,0);
}

void Motor_Right(uint16_t leftDuty, uint16_t rightDuty) {
  PWM_Duty(rightDuty,0,0,leftDuty);
}

