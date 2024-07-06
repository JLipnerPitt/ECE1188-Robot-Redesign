#include <Arduino.h>
#include "PWM.h"
#include "Motor.h"

int main(void) {
  Motor_Init(16000);
  while (1) {
    Motor_Forward(3500,3500);
    //delay(500);
  }
}