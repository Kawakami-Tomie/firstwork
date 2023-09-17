#ifndef __CONTROL_H
#define __CONTROL_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float Setangle;    //目表角度
	float Actualangle; //实际角度
	float  err;
	float  err_last;
	float Kp,Ki,Kd;
	float pwm;				//控制器空中pwm
	float integral;   //积分项
	float angle;     //误差角度
}_pid;

extern _pid pid_x,pid_y;
float PIDx_realize(float Outangle);
float PIDy_realize(float Outangle);
void  PID_init(void);

#endif
