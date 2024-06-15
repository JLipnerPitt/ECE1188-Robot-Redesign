#include <stdint.h>
#include "PWM.h"
#include "Motor.h"
#include <Arduino.h>

void Motor_Init() {
  PWM_Init(14999);

  // Motor Ports
  DDRL |= 0x40; // sets PL6 as output (Sleep Pin) 
  PORTL &= ~(0x40); // sets PL6 low initially

  // Input Pins for the DRV8833
  // sets all pins high initially (stop state)
  PORTH |= 0x18;
  PORTE |= 0x30;
}

void Motor_Stop(uint16_t leftDuty, uint16_t rightDuty) {
  PORTL &= ~(0x40); // clears sleep bit
  PORTH |= 0x18; // clears OC4A and OC4B pins
  PORTE |= 0x30; // clears OC3B and OC3C pins
}

void Motor_Forward(uint16_t leftDuty, uint16_t rightDuty) {
  PORTL |= 0x40; // sets sleep bit
  PORTH |= 0x08; //
  PORTE |= 0x10; //
  PWM_Duty(leftDuty,rightDuty);
}

void Motor_Backward(uint16_t leftDuty, uint16_t rightDuty) {
  PORTL |= 0x40; // sets sleep bit
  PORTH |= 0x10; // 
  PORTE |= 0x20; //
  PWM_Duty(leftDuty,rightDuty);
}

void Motor_Left(uint16_t leftDuty, uint16_t rightDuty) {
  PORTL |= 0x40; // sets sleep bit
  PORTH |= 0x08; //
  PORTE |= 0x20; //
  PWM_Duty(leftDuty,rightDuty);
}

void Motor_Right(uint16_t leftDuty, uint16_t rightDuty) {
  PORTL |= 0x40; // sets sleep bit
  PORTH |= 0x10; // 
  PORTE |= 0x10; //
  PWM_Duty(leftDuty,rightDuty);
}

