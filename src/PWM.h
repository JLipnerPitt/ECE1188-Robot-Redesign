#ifndef PWM_H_
#define PWM_H_

void PWM_Init(uint16_t period);

void PWM_Init2(uint16_t p);

void PWM_Duty(uint16_t Duty1, uint16_t Duty2, uint16_t duty3, uint16_t duty4);

void PWM_Signal(uint16_t duty);

uint16_t period;

#endif /* PWM_H_ */