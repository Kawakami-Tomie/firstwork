#ifndef __CONTROL_H
#define __CONTROL_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float Setangle;    //Ŀ��Ƕ�
	float Actualangle; //ʵ�ʽǶ�
	float  err;
	float  err_last;
	float Kp,Ki,Kd;
	float pwm;				//����������pwm
	float integral;   //������
	float angle;     //���Ƕ�
}_pid;

extern _pid pid_x,pid_y;
float PIDx_realize(float Outangle);
float PIDy_realize(float Outangle);
void  PID_init(void);

#endif
