#include <Arduino.h>
#include "PWM.h"
#include "Motor.h"

int main(void) {
  Motor_Init(16000);
  //PWM_Init(15999);
  //PWM_Init2(15999);
  while (1) {
    //PWM_Signal(8000);
    Motor_Forward(8000,8000);
  }
}