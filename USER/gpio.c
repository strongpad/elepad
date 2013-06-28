#include <stm32f10x_lib.h>
#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h" 
#include "adc.h"
#include "timer.h"  
#include "hc4051.h" 
int timer_start=1;	
int chose_hc4051=0;	 
int main(void)
{

	int chose_hc4051;
	int adc;
	JTAG_Set(1);//�ر�JTAG����Ϊ��PB3��		 			  
	Stm32_Clock_Init(9); //ϵͳʱ������
	delay_init(72);	     //��ʱ��ʼ��
	LED_Init();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ�
	hc4051_Init();
	PWM_Init(240,0);	 //����Ƶ��PWMƵ��=72000/900=80Khz
  	uart_init(72,9600);	 //���ڳ�ʼ��Ϊ9600
	Adc_Init();

	HC4051_A_PA0=0;//������HC4051������ѡ��
	HC4051_B_PA1=0;
	HC4051_C_PA2=0;

	HC4051_PA3=1; //�����ر�����HC4051
	HC4051_PA4=1;
	HC4051_PA5=1;
	HC4051_PA6=1;
	HC4051_PA7=1;

   	CAD=1;
	Timerx_Init(100,7199); //2um
	while(1)
	{
	   	//chose_hc4051++;	
		TIM3->CR1|=0x01;    //ʹ�ܶ�ʱ��3
		TIM3_IRQHandler();

		TIM3->CR1|=0;    //ʹ�ܶ�ʱ��3
		//if(chose_hc4051)
		//{
		//chose_hc4051=0;
		//}
		adc=Get_Adc(ADC_CH9);
		volat=(float)adc*(3.3/4096);
		printf("%5.3f\n \n",volat);
	/*	switch(0)
		{
			case 0:
					printf("%5.3f\n \n",volat);
                    break;
			case 1:
					printf("%5.3f\n \n",volat);
                    break;
			case 2:
					printf("%5.3f\n \n",volat);
                    break;
			case 3:
					printf("%5.3f\n \n",volat);
                    break;
			case 4:
					printf("%5.3f\n \n",volat);
                    break;
		}  */
		delay_ms(10);

		LED0=1;
		PWM_VAL=120;   //����PWMռ�ձȴ�С

		HC4051_PA3=1; //�����ر�����HC4051
		HC4051_PA4=1;
		HC4051_PA5=1;
		HC4051_PA6=1;
		HC4051_PA7=1;
	}	 
	
	
} 
 
 /*
int main(void)
{			
	u8 t;
	u8 len;	
	u16 times=0;  
	Stm32_Clock_Init(9); //ϵͳʱ������
	delay_init(72);	     //��ʱ��ʼ�� 
	uart_init(72,9600);	 //���ڳ�ʼ��Ϊ9600
	LED_Init();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ�    
	while(1)
	{
		if(USART_RX_STA&0x80)
		{					   
			len=USART_RX_STA&0x3f;//�õ��˴ν��յ������ݳ���
			printf("\n�����͵���ϢΪ:\n");
			for(t=0;t<len;t++)
			{
				USART1->DR=USART_RX_BUF[t];
				while((USART1->SR&0X40)==0);//�ȴ����ͽ���
			}
			printf("\n\n");//���뻻��
			USART_RX_STA=0;
		}else
		{
			times++;
			if(times%5000==0)
			{
				printf("\nMiniSTM32������ ����ʵ��\n");
				printf("����ԭ��@ALIENTEK\n\n\n");
			}
			if(times%200==0)printf("����������,�Իس�������\n");  
			//if(times%30==0)LED0=!LED0;//��˸LED,��ʾϵͳ��������.
			delay_ms(10);   
		}
	}	 
} */
	

