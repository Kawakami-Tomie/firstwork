
#include "main.h"//主函数头文件
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
  
  int able=0;
  int enable=0;
  uint8_t KeyNum;
 

uint8_t KeyNum1=1;


  int menu=0;
 void KeyScan()
 {
 KeyNum=Key_GetNum();
  if (KeyNum ==1)
  {  menu++;
   if(menu==5){menu=0;}
   }
   if(KeyNum==2)
	{
//    Servo_SetAngleX(0);
//	Servo_SetAngleY(AngleY_Turn(0,25));
	able++;
	enable=(able%2);//1使能，0失能	
	}
  }
  
int main(void)
{	
	
	Serial_TxPacket[0] = 0x01;
	Serial_TxPacket[1] = 0x02;
	Serial_TxPacket[2] = 0x03;
	Serial_TxPacket[3] = 0x04;
	Serial_TxPacket[4] = 0x05;
	Serial_TxPacket[5] = 0x06;
	Serial_TxPacket[6] = 0x07;
	Serial_TxPacket[7] = 0x08;

	
//	u8 key=1;
	u8 stepcount=0;
	u8 step2count=0;
	u8 step3count=0;
	SYS_Init();//系统初始化总函数
	Servo_SetAngleX(0);
//	Servo_SetAngleY(13.35571);
	Servo_SetAngleY(AngleY_Turn(0,25.2));
	delay_ms(999);
	
	while(1)//主循环
	{	
		

		
		
		KeyScan();
		DATA_Report();//MPU6050数据上报
//		if(menu==0)
//		{
//		 Servo_SetAngleX(0);
//		Servo_SetAngleY(0);
////	     AngleY_Turn(0,25);
//		
//		}
		 if(menu==0)
		{
		 Servo_SetAngleX(0);
	     Servo_SetAngleY(AngleY_Turn(0,25.2));
//		Servo_SetAngleY(0);
		}
		
		else if(menu==1&&enable==1)
		{
		  switch(stepcount)
		  {
			  case 0:
			  
			   stepcount++ ; //左中
			   Servo_SetAngleX(AngleX_Turn(-25.7));
			  delay_ms(700);
			  
			 break;
			  
			  case 1:	
			  
			   stepcount++ ; //左上
			   Servo_SetAngleY(AngleY_Turn(-25,51.5));
			 
			  delay_ms(700);
			 break;
				
			  case 2:
			  
			   stepcount++ ; //右上
			  Servo_SetAngleX(AngleX_Turn(-15));
			  Servo_SetAngleY(AngleY_Turn(-15,51));
			    delay_ms(50);
			   Servo_SetAngleX(AngleX_Turn(-5));
			  Servo_SetAngleY(AngleY_Turn(-5,50));
			  delay_ms(50);
			   Servo_SetAngleX(AngleX_Turn(16));
			   Servo_SetAngleY(AngleY_Turn(15,50));
			  delay_ms(50);
			    Servo_SetAngleX(AngleX_Turn(27.6));
			  Servo_SetAngleY(AngleY_Turn(25,46.7));
			delay_ms(999);
			
			  break;
			
			  case 3:
			  
			   stepcount++ ; //右下
			  
			   Servo_SetAngleY(AngleY_Turn(25.3,0));
			  delay_ms(999);
			 break;

			   case 4:
			  
			   stepcount++ ;//左下
			  Servo_SetAngleX(AngleX_Turn(-27.3));
			  
			   delay_ms(999);
			 break;
			   
			   case 5:
//			   key=3;
			   stepcount=2 ; //左上
			   Servo_SetAngleY(AngleY_Turn(-25,50));
			 
			   delay_ms(999);
			 break;
		  }	
		}
		else if(menu==2&&enable==1)//第三问写死，27*19
		{
			
//		  Serial_SendByte('2');
			  switch (step2count)
		  {
		  
			  case 0 :
				    step2count++;//找到A点
					Servo_SetAngleX(-13.9);
					delay_ms(500);
					Servo_SetAngleY(AngleY_Turn(-13.5,25));
					delay_ms(700);
			  
			  break;
			  
			  case 1:
				   step2count++;//找到B点
					Servo_SetAngleX(AngleX_Turn(15.5));
					delay_ms(700);
//					Servo_SetAngleY(AngleY_Turn(Xb,Yb));
//					delay_ms(700);
			  break;
			  
			   case 2 :
				    step2count++;//找到C点
//					Servo_SetAngleX(AngleX_Turn(Xc));
//					delay_ms(500);
					Servo_SetAngleY(AngleY_Turn(14,4.5));
					delay_ms(700);
			  
			  break;
			  
			  case 3:
				   step2count++;//找到D点
					Servo_SetAngleX(AngleX_Turn(-15));
//					delay_ms(500);
//					Servo_SetAngleY(AngleY_Turn(Xd,Yd));
					delay_ms(700);
			  break;
              
			  case 4:
				  step2count=1;//回到A点
			      Servo_SetAngleY(AngleY_Turn(-13.9,25));
			      delay_ms(700);
			      
			      
		  }
			
		}
		else if(menu==3&&enable==1)
		{
			
//		  Serial_SendByte('4');
		  switch (step2count)
		  {
		  
			  case 0 :
				    step2count++;//找到A点
					Servo_SetAngleX(AngleX_Turn(Xa));
					delay_ms(500);
					Servo_SetAngleY(AngleY_Turn(Xa,Ya));
					delay_ms(700);
			  
			  break;
			  
			  case 1:
				   step2count++;//找到B点
					Servo_SetAngleX(AngleX_Turn(Xb));
					delay_ms(700);
//					Servo_SetAngleY(AngleY_Turn(Xb,Yb));
//					delay_ms(700);
			  break;
			  
			   case 2 :
				    step2count++;//找到C点
//					Servo_SetAngleX(AngleX_Turn(Xc));
//					delay_ms(500);
					Servo_SetAngleY(AngleY_Turn(Xc,Yc));
					delay_ms(700);
			  
			  break;
			  
			  case 3:
				   step2count++;//找到D点
					Servo_SetAngleX(AngleX_Turn(Xd));
//					delay_ms(500);
//					Servo_SetAngleY(AngleY_Turn(Xd,Yd));
					delay_ms(700);
			  break;
              
			  case 4:
				  step2count=1;//回到A点
			      Servo_SetAngleY(AngleY_Turn(Xa,Ya));
			      delay_ms(700);
			      
			      
		  }
		  
			
		}
		else if (menu==4&&enable==1)
		{
		    Dividede();

 //           xa=69, ya=59, xb=69, yb=39, xc=98, yc=38, xd=100, yd=59;

 //          Dividede();


		    Serial_SendByte('4');
			switch(step3count)
			{
				case 0:
					step3count++;//找到A点
					Servo_SetAngleX(AngleX_Turn(Xa));
					delay_ms(500);
					Servo_SetAngleY(AngleY_Turn(Xa,Ya));
					delay_ms(700);
				break;
				case 1:
					step3count++;//微小移动到B点
					
					for(int numiatob=0;numiatob<100;numiatob++)
						{
						 Servo_SetAngleX(AngleX_Turn(Xa+numxa*numiatob));
						 Servo_SetAngleY(AngleY_Turn(Xa+numxa*numiatob,Ya+numya*numiatob));						
						}
					delay_ms(700);	
				
				break;
						
				case 2:
					step3count++;//微小移动到C点
					
					for(int numibtoc=0;numibtoc<100;numibtoc++)
						{
						 Servo_SetAngleX(AngleX_Turn(Xb+numxb*numibtoc));
						 Servo_SetAngleY(AngleY_Turn(Xb+numxb*numibtoc,Yb+numyb*numibtoc));						
						}
					delay_ms(700);	
				
				break;
				case 3:
					step3count++;//微小移动到D点
					
					for(int numictod=0;numictod<100;numictod++)
						{
						 Servo_SetAngleX(AngleX_Turn(Xc+numxc*numictod));
						 Servo_SetAngleY(AngleY_Turn(Xc+numxc*numictod,Yc+numyc*numictod));							
						}
					delay_ms(700);	
				
				break;
						
				case 4:
					step3count=1;//微小移动到A点
					
					for(int numidtoa=0;numidtoa<100;numidtoa++)
						{
						 Servo_SetAngleX(AngleX_Turn(Xd+numxd*numidtoa));
						 Servo_SetAngleY(AngleY_Turn(Xd+numxd*numidtoa,Yd+numyd*numidtoa));							
						}
					delay_ms(700);	
				
				break;
				
		
		     }
		
		}
////		if(key==2)
////		{
////		pid_y.Actualangle=-51.35-Angle_X_Final;
////		PWM_SetCompareY((128 / 180 * 2000 + 500)-pid_y.angle*14.4);
////		}
	}
}
/**
  * @brief  系统初始化总函数
  * @param  无
  * @retval 无
  */
void SYS_Init(void)
{
//	u8 i;//零时变量定义
	delay_init();  //延时函数初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断优先级分组函数
	uart_init(115200); //串口初始化为115200
	Serial_Init();//串口2初始化
	LED_Init();//初始化与LED连接的硬件接口
	OLED_Init();//OLED初始化
	OLED_ColorTurn(0);//OLED反色显示设置
	OLED_DisplayTurn(0);//OLED无反转显示设置
	OLED_ShowString(25,1,(unsigned char*)"RxBuffer1",16);//
//	for(i = 0;i<8;i++)//文字显示循环
//	OLED_ShowChinese(16*i,40,i,16);//文字显示：卡尔曼滤波解算法
	OLED_Refresh();//更新OLED显存
	delay_ms(999);delay_ms(999);//显示延迟
	OLED_Clear();//清屏
//	MPU_Init(); 
	Servo_Init();
	Key_Init();
	PID_init();	
	
	delay_ms(500);//初始化延时
	TIM4_Int_Init(199,7199);//10Khz的计数频率，计数到200为20ms  
//	for(i = 0;i<4;i++)//文字显示循环
//	OLED_ShowChinese(16*i+32,0,i+17,16);//文字显示：俯仰角
//	for(i = 0;i<3;i++)//文字显示循环
//	OLED_ShowChinese(16*i+8,16,i+8,16);//文字单次显示
//	for(i = 0;i<3;i++)//文字显示循环
//	OLED_ShowChinese(16*i+8,32,i+11,16);//文字显示：横滚角
//	for(i = 0;i<3;i++)//文字显示循环
//	OLED_ShowChinese(16*i+8,48,i+14,16);//文字显示：温度值
//	OLED_ShowChinese(96,48,21,16);//文字显示：℃
	OLED_Refresh();//更新OLED显存
}
/**
  * @brief  MPU6050数据上报
  * @param  无
  * @retval 无
  */
void DATA_Report(void)
{
//	sprintf((char *)tmp_buf,":%.2f' ",(double)xa);//字符串格式化命令
//	OLED_ShowString(56,16,(u8 *)tmp_buf,16);//OLED显示当前解算后俯仰角
//	sprintf((char *)tmp_buf,":%.2f' ",(double)ya);//字符串格式化命令
//	OLED_ShowString(56,32,(u8 *)tmp_buf,16);//OLED显示当前解算后横滚角	
//	sprintf((char *)tmp_buf,":%.1f",(double)xb);//字符串格式化命令
//	OLED_ShowString(56,48,(u8 *)tmp_buf,16);//OLED显示当前解算后温度值	
	

			

		
		if (Serial_GetRxFlag() == 1)
		{

			Serial_TxPacket[0]=Serial_RxPacket[0];
			Serial_TxPacket[1]=Serial_RxPacket[1];
			Serial_TxPacket[2]=Serial_RxPacket[2];
			Serial_TxPacket[3]=Serial_RxPacket[3];
			Serial_TxPacket[4]=Serial_RxPacket[4];
			Serial_TxPacket[5]=Serial_RxPacket[5];
			Serial_TxPacket[6]=Serial_RxPacket[6];
			Serial_TxPacket[7]=Serial_RxPacket[7];
			Serial_SendPacket();
			
		}
		OLED_Refresh();//更新OLED显存
//		OLED_ShowString(25,1,(unsigned char*)"RXdata OK!",16);
		
		OLED_ShowString(2,1,(unsigned char*)"menu=",16);
		OLED_ShowNum(50,1,menu,1,16);
		OLED_ShowNum(2,20,Serial_RxPacket[0],3,16);
		OLED_ShowNum(32,20,Serial_RxPacket[1],3,16);
		OLED_ShowNum(64,20,Serial_RxPacket[2],3,16);
		OLED_ShowNum(96,20,Serial_RxPacket[3],3,16);
		OLED_ShowNum(2,42,Serial_RxPacket[4],3,16);
		OLED_ShowNum(32,42,Serial_RxPacket[5],3,16);
		OLED_ShowNum(64,42,Serial_RxPacket[6],3,16);
		OLED_ShowNum(96,42,Serial_RxPacket[7],3,16);
		OLED_Refresh();//更新OLED显存
	
	
//	printf("Pitch:%.4f Roll:%.4f \
//	AAC_X:%5d ",\
//	(double)xa,(double)ya,xb);//串口发送实时俯仰角，横滚角，XYZ三轴角加速度原始值，XYZ三轴角速度原始值
}
