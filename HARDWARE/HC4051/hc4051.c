#include <stm32f10x_lib.h>	   
#include "hc4051.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//Mini STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2010/5/27
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ����ԭ�� 2009-2019
//All rights reserved											  
////////////////////////////////////////////////////////////////////////////////// 	   

//��ʼ��PB3Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��

void hc4051_Init(void)
{
	RCC->APB2ENR|=1<<2;    //ʹ��PORTBʱ��	   	 	

	GPIOA->CRL&=0XFFFFFFF0; 
	GPIOA->CRL|=0X00000003;//PA0 �������   	 
    GPIOA->ODR|=1<<0;      //PA0 �����

	GPIOA->CRL&=0XFFFFFF0F; 
	GPIOA->CRL|=0X00000030;//PA1 �������   	 
    GPIOA->ODR|=1<<1;      //PA1 �����

	GPIOA->CRL&=0XFFFFF0FF; 
	GPIOA->CRL|=0X00000300;//PA2 �������   	 
    GPIOA->ODR|=1<<2;      //PA2 �����
		   	 
	GPIOA->CRL&=0XFFFF0FFF; 
	GPIOA->CRL|=0X00003000;//PA3 �������   	 
    GPIOA->ODR|=1<<3;      //PA3 ����� 

	GPIOA->CRL&=0XFFF0FFFF; 
	GPIOA->CRL|=0X00030000;//PA4 �������   	 
    GPIOA->ODR|=1<<4;      //PA4 ����� 

	GPIOA->CRL&=0XFF0FFFFF; 
	GPIOA->CRL|=0X00300000;//PA5 �������   	 
    GPIOA->ODR|=1<<5;      //PA5 ����� 

	GPIOA->CRL&=0XF0FFFFFF; 
	GPIOA->CRL|=0X03000000;//PA6 �������   	 
    GPIOA->ODR|=1<<6;      //PA6 ����� 

	GPIOA->CRL&=0X0FFFFFFF; 
	GPIOA->CRL|=0X30000000;//PA7 �������   	 
    GPIOA->ODR|=1<<7;      //PA7 �����
	 
}

void hc4051_chose(int x)
{
	//int i;
	switch (x)//ѡȡHC4051
	{
		case 0:
			HC4051_PA4=1;
			HC4051_PA5=1;
			HC4051_PA6=1;
			HC4051_PA7=1;
			HC4051_PA3=0;
			break;
		case 1:
			HC4051_PA3=1;
			HC4051_PA4=0;
			HC4051_PA5=1;
			HC4051_PA6=1;
			HC4051_PA7=1;
			break;	
		case 2:
			HC4051_PA3=1;
			HC4051_PA4=1;
			HC4051_PA6=1;
			HC4051_PA7=1;
			HC4051_PA5=0;
			break;
		case 3:
			HC4051_PA3=1;
			HC4051_PA4=1;
			HC4051_PA5=1;
			HC4051_PA7=1;
			HC4051_PA6=0;
			break;		
		case 4:
			HC4051_PA3=1;
			HC4051_PA4=1;
			HC4051_PA5=1;
			HC4051_PA6=1;
			HC4051_PA7=0;
			break;
				
	}
 			HC4051_A_PA0=0;
			HC4051_B_PA1=0;
			HC4051_C_PA2=0;
	  		//delay_ms(500);

/*	for(i=0;i<8;i++)//ѭ��HC4051����ֵ
	{
		if(0==i)
		{
			HC4051_A_PA0=0;
			HC4051_B_PA1=0;
			HC4051_C_PA2=0;
		}
		else if(1==i)
		{
			HC4051_A_PA0=1;
			HC4051_B_PA1=0;
			HC4051_C_PA2=0;
		}
		else if(2==i)
		{
			HC4051_A_PA0=0;
			HC4051_B_PA1=1;
			HC4051_C_PA2=0;
		}
		else if(3==i)
		{
			HC4051_A_PA0=1;
			HC4051_B_PA1=1;
			HC4051_C_PA2=0;
		}
		else if(4==i)
		{
			HC4051_A_PA0=0;
			HC4051_B_PA1=0;
			HC4051_C_PA2=1;
		}
		else if(5==i)
		{
			HC4051_A_PA0=1;
			HC4051_B_PA1=0;
			HC4051_C_PA2=1;
		}
		else if(6==i)
		{
			HC4051_A_PA0=0;
			HC4051_B_PA1=1;
			HC4051_C_PA2=1;
		}
		else
		{
			HC4051_A_PA0=1;
			HC4051_B_PA1=1;
			HC4051_C_PA2=1;
		}
		delay_ms(500);
	} */
}	  



