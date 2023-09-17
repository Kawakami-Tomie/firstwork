#include "Device/Include/stm32f10x.h"   // Device header
//#include "Serial.h"
#include <math.h>
float left_high,right_high,right_low,left_low;
float point_x=0,point_y=0;
float hypotenuse=0;
float AngleX=0,AngleY=0,PI=3.14159625;

//float Xa,Ya,Xb,Yb,Xc,Yc,Xd,Yd;
//float Num_xatoxb[40]={0},Num_xbtoxc[40]={0},Num_xctoxd[40]={0},Num_xdtoxa[40]={0};
//float Num_yatoyb[40]={0},Num_ybtoyc[40]={0},Num_yctoyd[40]={0},Num_ydtoya[40]={0};

float AngleX_Turn(float x)
{
  
  AngleX=atan2(x,112.5)*180/PI;
  return AngleX;

}
float AngleY_Turn(float x,float y)
{
  double  hypotenuse2=x*x+112.5*112.5;
  hypotenuse =  sqrt(hypotenuse2);
  AngleY=atan2(y,hypotenuse)*180/PI;
  return AngleY;

}

