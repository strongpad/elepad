#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//Mini STM32������
//LED��������			 
//����ԭ��@ALIENTEK
//2010/5/27

//LED�˿ڶ���
#define CAD PBout(0)// PB0
#define ADC_test PBin(1)// PB1		
#define LED0 PBout(3)// PB3	
//#define PWM_OUT PBout(6)// PB6	

void LED_Init(void);//��ʼ��		 				    
#endif

















