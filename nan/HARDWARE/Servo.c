#include "stm32f10x.h"                  // Device header
#include "pwm.h"

void Servo_Init(void)
{
	PWM_Init();
}

void Servo_SetAngleX(float anglex)
{
	if (anglex>40)anglex=40;
	if (anglex<-40)anglex=40;

	PWM_SetCompareX((132-anglex) / 270 * 2000 + 500);
}

void Servo_SetAngleY(float angley)
{
	if (angley>40)angley=40;
	if (angley<-40)angley=40;
	PWM_SetCompareY((187.5-angley)/ 270 * 2000 + 500);
}






