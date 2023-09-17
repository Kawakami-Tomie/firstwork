#include "Device/Include/stm32f10x.h"   // Device header
#include "stm32f10x.h"                  // Device header
#include <stdio.h>
#include <stdarg.h>
#include "OLED.h"
//#include "point.h"
uint8_t Serial_TxPacket[8];				//FF 01 02 03 04 FE
uint8_t Serial_RxPacket[8];
uint8_t Serial_RxFlag;
float distance=1.036269;//50cm�ľ��뱻�и��n��
float xo=83,yo=85;//����ԭ�����꣬����Ҫ�����ĵ㣡����
float Xa,Ya,Xb,Yb,Xc,Yc,Xd,Yd;
float numxa, numya, numxb, numyb,numxc, numyc,numxd,numyd;
//float Num_xatoxb[40]={0},Num_xbtoxc[40]={0},Num_xctoxd[40]={0},Num_xdtoxa[40]={0};
//float Num_yatoyb[40]={0},Num_ybtoyc[40]={0},Num_yctoyd[40]={0},Num_ydtoya[40]={0};

//uint8_t RxBuffer1[8];
//uint8_t RxFlag1;
int xa,ya,xb,yb,xc,yc,xd,yd;

int GetOpenmvDataCount  = 0;

void XY_Turn(void)
{
  xa=Serial_RxPacket[0];
  ya=Serial_RxPacket[1];
  xb=Serial_RxPacket[2];
  yb=Serial_RxPacket[3];
  xc=Serial_RxPacket[4];
  yc=Serial_RxPacket[5];
  xd=Serial_RxPacket[6];
  yd=Serial_RxPacket[7];

}

void Dividede(void)//���ڼ����ǽ����ı�Ե������Ŀ��ֵҲ�Ǳ�Ե��Ҫ��Ŀ��ֵ��������������������������궼��С0.9cm����
{
	Xa=((float)xa-xo)*1.036269+4.1;
	Ya=(yo-(float)ya)*1.036269-3.5;
	Xb=((float)xb-xo)*1.036269+4.1;
	Yb=(yo-(float)yb)*1.036269-5.5;
	Xc=((float)xc-xo)*1.036269+4.5;
	Yc=(yo-(float)yc)*1.036269-5.5;
	Xd=((float)xd-xo)*1.036269+4.5;
	Yd=(yo-(float)yd)*1.036269-3.5;
	
     numxa=(Xb-Xa)/100;
	 numya=(Yb-Ya)/100;
	 numxb=(Xc-Xb)/100;
	 numyb=(Yc-Yb)/100;
	 numxc=(Xd-Xc)/100;
	 numyc=(Yd-Yc)/100;
	 numxd=(Xa-Xd)/100;
     numyd=(Ya-Yd)/100;
	
//	for(int d_numi=0;d_numi<40;d_numi++)
//	{
//	 Num_xatoxb[d_numi]=Xa+numxa*d_numi;
//	 Num_yatoyb[d_numi]=Ya+numya*d_numi;
//	 Num_xbtoxc[d_numi]=Xb+numxb*d_numi;
//	 Num_ybtoyc[d_numi]=Yb+numyb*d_numi;
//	 Num_xctoxd[d_numi]=Xc+numxc*d_numi;
//	 Num_yctoyd[d_numi]=Yc+numyc*d_numi;
//	 Num_xdtoxa[d_numi]=Xd+numxd*d_numi;
//	 Num_ydtoya[d_numi]=Yd+numyd*d_numi;		
//	}
		

}


void Serial_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;

	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitTypeDef USART_InitStructure;

	
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART2, &USART_InitStructure);
	

	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;

	
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART2, ENABLE);
}


void Serial_SendByte(uint8_t Byte)
{
	USART_SendData(USART2, Byte);
	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
}

void Serial_SendArray(uint8_t *Array, uint16_t Length)
{
	uint16_t i;
	for (i = 0; i < Length; i ++)
	{
		Serial_SendByte(Array[i]);
	}
}

void Serial_SendString(char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i ++)
	{
		Serial_SendByte(String[i]);
	}
}

uint32_t Serial_Pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y --)
	{
		Result *= X;
	}
	return Result;
}

void Serial_SendNumber(uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i ++)
	{
		Serial_SendByte(Number / Serial_Pow(10, Length - i - 1) % 10 + '0');
	}
}

int fputc(int ch, FILE *f)
{
	Serial_SendByte(ch);
	return ch;
}

void Serial_Printf(char *format, ...)
{
	char String[100];
	va_list arg;
	va_start(arg, format);
	vsprintf(String, format, arg);
	va_end(arg);
	Serial_SendString(String);
}


void Serial_SendPacket(void)//�������ݰ�
{
	Serial_SendByte(0xFF);//��Ӱ�ͷ
	Serial_SendArray(Serial_TxPacket, 8);//����
	Serial_SendByte(0xFE);//��Ӱ�β
}

uint8_t Serial_GetRxFlag(void)
{
	if (Serial_RxFlag == 1)
	{
		Serial_RxFlag = 0;
		return 1;
	}
	return 0;
}

void USART2_IRQHandler(void)
{
	static uint8_t RxState = 0;//����״̬
	static uint8_t pRxPacket = 0;//���յڼ�������
	if (USART_GetITStatus(USART2, USART_IT_RXNE) == SET)
	{
		uint8_t RxData = USART_ReceiveData(USART2);
		
		if (RxState == 0)//�ȴ���ͷ
		{
			if (RxData == 0x2C)//�����ͷΪ0xFF
			{
				RxState = 1;//����״̬��Ϊ1��������
				pRxPacket = 0;
//				Serial_SendByte(0xFF);
			}
		}
		else if (RxState == 1)//�ȴ���ͷ
		{
			if (RxData == 0x12||RxData == 0x26)//�����ͷΪ0xFF
			{
				RxState = 2;//����״̬��Ϊ2��������
				pRxPacket = 0;
//				Serial_SendByte(0xFF);
			}
		}
		
		else if (RxState == 2)//����״̬Ϊ1��������
		{
			Serial_RxPacket[pRxPacket] = RxData;//��������
			pRxPacket ++;//�������ݸ���+1
			if (pRxPacket >= 8)//����������ݹ��ĸ�
			{
				RxState = 3;//�ý���״̬Ϊ2�ȴ���β
			}
		}
		else if (RxState == 3)//����״̬Ϊ2
		{
			if (RxData == 0x5B)//��βΪ0xFE
			{
				RxState = 0;//�ý���״̬Ϊ�ȴ���ͷ
				Serial_RxFlag = 1;//���ձ�־λ��1���Խ���
				GetOpenmvDataCount++;//�����ݽ������Ǵ�������
				XY_Turn();
				Dividede();
				if(GetOpenmvDataCount>=10)
				{
				RxState=4;//���ٽ���
				}
			}
		}
		
		USART_ClearITPendingBit(USART2, USART_IT_RXNE);//��־λ�������ȡ��DR�ͻ��Զ����㣬���û��ȡDR������Ҫ�ֶ����㡣
	}
}







//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//  uint8_t tem;// ��������޷��ŵ�
//	
//	//RedSignal_Toggle;   //�������Ƿ�������ݵ�, ����Ҫ��ʱ��ûЧ���Ļ��ʹ���������3���ж϶�û����
//  if(huart->Instance== USART3)     //����ֻ��������дUSART3
//  {
//		   
//		//RedSignal_Toggle;   //�������Ƿ�������ݵ�, ����Ҫ��ʱ��ûЧ���Ļ��ʹ���������3���ж϶�û����
//		
//    tem=uart3_rxbuff;
//    Openmv_Receive_Data(tem);
//		
//  }	
//   HAL_UART_Receive_IT(&huart3,&uart3_rxbuff,1); 
//}




//void USART2_IRQHandler(void)
//{
////	static uint8_t RxState = 0;
////	static uint8_t pRxPacket = 0;
//	    uint8_t i;
//		static uint8_t RxCounter1=0;//����
//		
//		static uint8_t RxState = 0;	
////		static uint8_t RxFlag1 = 0;

//	if (USART_GetITStatus(USART2, USART_IT_RXNE) == SET)
//	{
//		uint8_t com_data = USART_ReceiveData(USART2);
//		
////		if (RxState == 0)
////		{
////			if (RxData == 0xFF)
////			{
////				RxState = 1;
////				pRxPacket = 0;
////			}
////		}
////		else if (RxState == 1)
////		{
////			Serial_RxPacket[pRxPacket] = RxData;
////			pRxPacket ++;
////			if (pRxPacket >= 4)
////			{
////				RxState = 2;
////			}
////		}
////		else if (RxState == 2)
////		{
////			if (RxData == 0xFE)
////			{
////				RxState = 0;
////				Serial_RxFlag = 1;
////			}
////		}
//		if(RxState==0&&com_data==0x2C)  //0x2c/0x26֡ͷ
//		{
//			
//			RxState=1;
////			RxBuffer1[RxCounter1++]=com_data; 
//			RxCounter1=0;
//			OLED_ShowString(25,1,(unsigned char*)"A OK!",16);
//		}

//		else if(RxState==1&&(com_data==0x12||com_data==0x26))  //0x12֡ͷ
//		{
//			RxState=2;
////			RxBuffer1[RxCounter1++]=com_data;
//			RxCounter1=0;
//		}
//		
//		else if(RxState==2)
//		{
////			 Serial_RxPacket[pRxPacket] = RxData;
////			pRxPacket ++;
////			if (pRxPacket >= 4)
////			{
////				RxState = 2;
////			}
//			RxBuffer1[RxCounter1]=com_data;
//			RxCounter1++;
//			if(RxCounter1>=8)       //RxBuffer1��������,�������ݽ���
//			{
//				RxState=3;
//				RxFlag1=1;

//				GetOpenmvDataCount++;      
//				
//				
//			}
//		}

//		else if(RxState==3)		//����Ƿ���ܵ�������־
//		{
//				if(com_data== 0x5B)
//				{
//							
//							RxFlag1 = 0;
//							RxCounter1 = 0;
//							RxState = 0;
//						    XY_Turn();
//				}
//				else   //���մ���
//				{
//							RxState = 0;
//							RxCounter1=0;
//							for(i=0;i<10;i++)
//							{
//									RxBuffer1[i]=0x00;      //�����������������
//							}
//				}
//		} 

//		else   
//		{
//				RxState = 0;
//				RxCounter1=0;
//				for(i=0;i<10;i++)
//				{
//						RxBuffer1[i]=0x00;      //�����������������
//				}
//		}
//		
//		USART_ClearITPendingBit(USART2, USART_IT_RXNE);
//	}
//}


