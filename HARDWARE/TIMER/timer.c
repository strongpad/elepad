#include "timer.h"
#include "led.h"
#include "delay.h"
#include "hc4051.h"
#include "usart.h"
#include "adc.h"
float volat; 
extern int timer_start;
extern int chose_hc4051;  		  			    
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//Mini STM32������
//ͨ�ö�ʱ�� ��������			   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2010/12/03
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ����ԭ�� 2009-2019
//All rights reserved
////////////////////////////////////////////////////////////////////////////////// 	  

//��ʱ��3�жϷ������	 
void TIM3_IRQHandler(void)
{ 		
	if(TIM3->SR&0X0001)//����ж�
	{
		CAD=1;//��ȡ��Ȧֵ֮ǰ���ε�ѹ�ı䣬�ȸߺ��
		delay_us(5);
		CAD=0;//��ȡ��Ȧֵ֮ǰ���ε�ѹ�ı䣬�ȸߺ��
		hc4051_chose(chose_hc4051);
		delay_us(100);			   
	}
	TIM3->SR&=~(1<<0);//����жϱ�־λ
}
//ͨ�ö�ʱ���жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!
void Timerx_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<1;//TIM3ʱ��ʹ��    
 	TIM3->ARR=arr;  //�趨�������Զ���װֵ//�պ�1ms    
	TIM3->PSC=psc;  //Ԥ��Ƶ��7200,�õ�10Khz�ļ���ʱ��
	//����������Ҫͬʱ���òſ���ʹ���ж�
	TIM3->DIER|=1<<0;   //��������ж�				
	TIM3->DIER|=1<<6;   //�������ж�
		  							    
	TIM3->CR1|=0x01;    //ʹ�ܶ�ʱ��3
  	MY_NVIC_Init(1,3,TIM3_IRQChannel,2);//��ռ1�������ȼ�3����2									 
}

//TIM3 PWM����
//����ԭ��@ALIENTEK
//2010/6/2	 

//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void PWM_Init(u16 arr,u16 psc)

{                                               

       RCC->APB1ENR|=1<<2;           //TIM4ʱ��ʹ��   

       RCC->APB2ENR|=1<<3;         //ʹ��PORTBʱ��      

       GPIOB->CRL&=0X00FFFFFF;   //PB6���

       GPIOB->CRL|=0X4B000000;      //���ù������

       TIM4->ARR=arr;                        //�趨�������Զ���װֵ

       TIM4->PSC=psc;                        //Ԥ��Ƶ����Ƶ����

       TIM4->CCMR1|=7<<4;              //CH1 PWM2ģʽ       

       TIM4->CCMR1|=1<<3;             //CH1 Ԥװ��ʹ��             

		TIM4->CCER|=1<<1;               //OC1 �͵�ƽ��Ч

       TIM4->CCER|=1<<0;               //OC1���ʹ��      

       TIM4->CR1=0x0080;                //ARPEʹ��

       TIM4->CR1|=0x01;                  //ʹ�ܶ�ʱ��3                                                 

}
















