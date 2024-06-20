#ifndef MOTOR_H_
#define MOTOR_H_

void Motor_Init(uint16_t period);
void Motor_Forward(uint16_t leftDuty, uint16_t rightDuty);
void Motor_Backwards(uint16_t leftDuty, uint16_t rightDuty);
void Motor_Right(uint16_t leftDuty, uint16_t rightDuty);
void Motor_Left(uint16_t leftDuty, uint16_t rightDuty);
void Motor_Stop(uint16_t leftDuty, uint16_t rightDuty);

#endif