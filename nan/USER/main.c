
#include "main.h"//������ͷ�ļ�
/**
  * @brief  ������
  * @param  ��
  * @retval ��
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
	enable=(able%2);//1ʹ�ܣ�0ʧ��	
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
	SYS_Init();//ϵͳ��ʼ���ܺ���
	Servo_SetAngleX(0);
//	Servo_SetAngleY(13.35571);
	Servo_SetAngleY(AngleY_Turn(0,25.2));
	delay_ms(999);
	
	while(1)//��ѭ��
	{	
		

		
		
		KeyScan();
		DATA_Report();//MPU6050�����ϱ�
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
			  
			   stepcount++ ; //����
			   Servo_SetAngleX(AngleX_Turn(-25.7));
			  delay_ms(700);
			  
			 break;
			  
			  case 1:	
			  
			   stepcount++ ; //����
			   Servo_SetAngleY(AngleY_Turn(-25,51.5));
			 
			  delay_ms(700);
			 break;
				
			  case 2:
			  
			   stepcount++ ; //����
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
			  
			   stepcount++ ; //����
			  
			   Servo_SetAngleY(AngleY_Turn(25.3,0));
			  delay_ms(999);
			 break;

			   case 4:
			  
			   stepcount++ ;//����
			  Servo_SetAngleX(AngleX_Turn(-27.3));
			  
			   delay_ms(999);
			 break;
			   
			   case 5:
//			   key=3;
			   stepcount=2 ; //����
			   Servo_SetAngleY(AngleY_Turn(-25,50));
			 
			   delay_ms(999);
			 break;
		  }	
		}
		else if(menu==2&&enable==1)//������д����27*19
		{
			
//		  Serial_SendByte('2');
			  switch (step2count)
		  {
		  
			  case 0 :
				    step2count++;//�ҵ�A��
					Servo_SetAngleX(-13.9);
					delay_ms(500);
					Servo_SetAngleY(AngleY_Turn(-13.5,25));
					delay_ms(700);
			  
			  break;
			  
			  case 1:
				   step2count++;//�ҵ�B��
					Servo_SetAngleX(AngleX_Turn(15.5));
					delay_ms(700);
//					Servo_SetAngleY(AngleY_Turn(Xb,Yb));
//					delay_ms(700);
			  break;
			  
			   case 2 :
				    step2count++;//�ҵ�C��
//					Servo_SetAngleX(AngleX_Turn(Xc));
//					delay_ms(500);
					Servo_SetAngleY(AngleY_Turn(14,4.5));
					delay_ms(700);
			  
			  break;
			  
			  case 3:
				   step2count++;//�ҵ�D��
					Servo_SetAngleX(AngleX_Turn(-15));
//					delay_ms(500);
//					Servo_SetAngleY(AngleY_Turn(Xd,Yd));
					delay_ms(700);
			  break;
              
			  case 4:
				  step2count=1;//�ص�A��
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
				    step2count++;//�ҵ�A��
					Servo_SetAngleX(AngleX_Turn(Xa));
					delay_ms(500);
					Servo_SetAngleY(AngleY_Turn(Xa,Ya));
					delay_ms(700);
			  
			  break;
			  
			  case 1:
				   step2count++;//�ҵ�B��
					Servo_SetAngleX(AngleX_Turn(Xb));
					delay_ms(700);
//					Servo_SetAngleY(AngleY_Turn(Xb,Yb));
//					delay_ms(700);
			  break;
			  
			   case 2 :
				    step2count++;//�ҵ�C��
//					Servo_SetAngleX(AngleX_Turn(Xc));
//					delay_ms(500);
					Servo_SetAngleY(AngleY_Turn(Xc,Yc));
					delay_ms(700);
			  
			  break;
			  
			  case 3:
				   step2count++;//�ҵ�D��
					Servo_SetAngleX(AngleX_Turn(Xd));
//					delay_ms(500);
//					Servo_SetAngleY(AngleY_Turn(Xd,Yd));
					delay_ms(700);
			  break;
              
			  case 4:
				  step2count=1;//�ص�A��
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
					step3count++;//�ҵ�A��
					Servo_SetAngleX(AngleX_Turn(Xa));
					delay_ms(500);
					Servo_SetAngleY(AngleY_Turn(Xa,Ya));
					delay_ms(700);
				break;
				case 1:
					step3count++;//΢С�ƶ���B��
					
					for(int numiatob=0;numiatob<100;numiatob++)
						{
						 Servo_SetAngleX(AngleX_Turn(Xa+numxa*numiatob));
						 Servo_SetAngleY(AngleY_Turn(Xa+numxa*numiatob,Ya+numya*numiatob));						
						}
					delay_ms(700);	
				
				break;
						
				case 2:
					step3count++;//΢С�ƶ���C��
					
					for(int numibtoc=0;numibtoc<100;numibtoc++)
						{
						 Servo_SetAngleX(AngleX_Turn(Xb+numxb*numibtoc));
						 Servo_SetAngleY(AngleY_Turn(Xb+numxb*numibtoc,Yb+numyb*numibtoc));						
						}
					delay_ms(700);	
				
				break;
				case 3:
					step3count++;//΢С�ƶ���D��
					
					for(int numictod=0;numictod<100;numictod++)
						{
						 Servo_SetAngleX(AngleX_Turn(Xc+numxc*numictod));
						 Servo_SetAngleY(AngleY_Turn(Xc+numxc*numictod,Yc+numyc*numictod));							
						}
					delay_ms(700);	
				
				break;
						
				case 4:
					step3count=1;//΢С�ƶ���A��
					
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
  * @brief  ϵͳ��ʼ���ܺ���
  * @param  ��
  * @retval ��
  */
void SYS_Init(void)
{
//	u8 i;//��ʱ��������
	delay_init();  //��ʱ������ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�ж����ȼ����麯��
	uart_init(115200); //���ڳ�ʼ��Ϊ115200
	Serial_Init();//����2��ʼ��
	LED_Init();//��ʼ����LED���ӵ�Ӳ���ӿ�
	OLED_Init();//OLED��ʼ��
	OLED_ColorTurn(0);//OLED��ɫ��ʾ����
	OLED_DisplayTurn(0);//OLED�޷�ת��ʾ����
	OLED_ShowString(25,1,(unsigned char*)"RxBuffer1",16);//
//	for(i = 0;i<8;i++)//������ʾѭ��
//	OLED_ShowChinese(16*i,40,i,16);//������ʾ���������˲����㷨
	OLED_Refresh();//����OLED�Դ�
	delay_ms(999);delay_ms(999);//��ʾ�ӳ�
	OLED_Clear();//����
//	MPU_Init(); 
	Servo_Init();
	Key_Init();
	PID_init();	
	
	delay_ms(500);//��ʼ����ʱ
	TIM4_Int_Init(199,7199);//10Khz�ļ���Ƶ�ʣ�������200Ϊ20ms  
//	for(i = 0;i<4;i++)//������ʾѭ��
//	OLED_ShowChinese(16*i+32,0,i+17,16);//������ʾ��������
//	for(i = 0;i<3;i++)//������ʾѭ��
//	OLED_ShowChinese(16*i+8,16,i+8,16);//���ֵ�����ʾ
//	for(i = 0;i<3;i++)//������ʾѭ��
//	OLED_ShowChinese(16*i+8,32,i+11,16);//������ʾ�������
//	for(i = 0;i<3;i++)//������ʾѭ��
//	OLED_ShowChinese(16*i+8,48,i+14,16);//������ʾ���¶�ֵ
//	OLED_ShowChinese(96,48,21,16);//������ʾ����
	OLED_Refresh();//����OLED�Դ�
}
/**
  * @brief  MPU6050�����ϱ�
  * @param  ��
  * @retval ��
  */
void DATA_Report(void)
{
//	sprintf((char *)tmp_buf,":%.2f' ",(double)xa);//�ַ�����ʽ������
//	OLED_ShowString(56,16,(u8 *)tmp_buf,16);//OLED��ʾ��ǰ���������
//	sprintf((char *)tmp_buf,":%.2f' ",(double)ya);//�ַ�����ʽ������
//	OLED_ShowString(56,32,(u8 *)tmp_buf,16);//OLED��ʾ��ǰ���������	
//	sprintf((char *)tmp_buf,":%.1f",(double)xb);//�ַ�����ʽ������
//	OLED_ShowString(56,48,(u8 *)tmp_buf,16);//OLED��ʾ��ǰ������¶�ֵ	
	

			

		
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
		OLED_Refresh();//����OLED�Դ�
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
		OLED_Refresh();//����OLED�Դ�
	
	
//	printf("Pitch:%.4f Roll:%.4f \
//	AAC_X:%5d ",\
//	(double)xa,(double)ya,xb);//���ڷ���ʵʱ�����ǣ�����ǣ�XYZ����Ǽ��ٶ�ԭʼֵ��XYZ������ٶ�ԭʼֵ
}
