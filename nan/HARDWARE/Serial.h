#ifndef __SERIAL_H
#define __SERIAL_H

#include <stdio.h>
#include <stdlib.h>

//extern uint8_t RxBuffer1[8];
//extern uint8_t RxFlag1;
extern int xa,ya,xb,yb,xc,yc,xd,yd;
extern int GetOpenmvDataCount;
void XY_Turn(void);
extern float distance;//50cm的距离被切割成n份
extern float xo,yo;//假设原点坐标，最主要测量的点！！！
void Dividede(void);
extern float Xa,Ya,Xb,Yb,Xc,Yc,Xd,Yd;
extern float middlexa,middleya,middlexb,middleyb,middlexc,middleyc,middlexd,middleyd;
//extern float Num_xatoxb[],Num_xbtoxc[],Num_xctoxd[],Num_xdtoxa[];
//extern float Num_yatoyb[],Num_ybtoyc[],Num_yctoyd[],Num_ydtoya[];
 extern float numxa, numya, numxb, numyb,numxc, numyc,numxd,numyd;
extern uint8_t Serial_TxPacket[];
extern uint8_t Serial_RxPacket[];

void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array, uint16_t Length);
void Serial_SendString(char *String);
void Serial_SendNumber(uint32_t Number, uint8_t Length);
void Serial_Printf(char *format, ...);

void Serial_SendPacket(void);
uint8_t Serial_GetRxFlag(void);

#endif
