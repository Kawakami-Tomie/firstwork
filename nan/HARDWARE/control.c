#include "Device/Include/stm32f10x.h"   // Device header
#include "control.h"
_pid pid_x,pid_y;

void  PID_init()
{
	pid_x.Setangle=0.0;  
	pid_x.Actualangle =83.0;
	pid_x.err=0.0;
	pid_x.err_last=0.0;
	pid_x.integral=0.0;
	pid_x .Kp=0.25;
	pid_x.Ki=0.6;
	pid_x.Kd=0.01;
	pid_x.angle=0.0;
	pid_y.Setangle=25.0;  
	pid_y.Actualangle =0.0;
	pid_y.err=0.0;
	pid_y.err_last=0.0;
	pid_y.integral=0.0;
	pid_y .Kp=0.25;
	pid_y.Ki=0.6;
	pid_y.Kd=0.01;
	pid_y.angle=0.0;

}

float PIDx_realize(float Outangle)
{
		
		pid_x.err=pid_x.Setangle-pid_x.Actualangle;
		pid_x.integral +=pid_x.err;
		pid_x.angle=pid_x.Kp*pid_x.err+pid_x.Ki*pid_x.integral+pid_x.Kd*(pid_x.err-pid_x.err_last);	//Îó²î½Ç¶È
		pid_x.err_last=pid_x.err;
		return pid_x.angle;
}
	
float PIDy_realize(float Outangle)
{
		
		pid_y.err=pid_y.Setangle-pid_y.Actualangle;
		pid_y.integral +=pid_y.err;
		pid_y.angle=pid_y.Kp*pid_y.err+pid_y.Ki*pid_y.integral+pid_y.Kd*(pid_y.err-pid_y.err_last);	//Îó²î½Ç¶È
		pid_y.err_last=pid_y.err;
		return pid_y.angle;
}	

