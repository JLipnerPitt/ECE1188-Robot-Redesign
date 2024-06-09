#include <Arduino.h>

void PWM_Init(int d) {

}

void Motor_Init() {

  PWM_Init(14999);

  // Motor Ports
  DDRB |= 0x10; // sets PB4 as output (Sleep Pin) 
  PORTB |= 0x10; // sets PB4 low

  // Input Pins for the DRV8833
  DDRH |= 0x78; // sets as input
}

void Motor_Stop() {

}

void Motor_Forward() {

}

void Motor_Backward() {

}

void Motor_Left() {

}

void Motor_Right() {

}

int main(void) {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}