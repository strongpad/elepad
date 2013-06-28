#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//Mini STM32开发板
//LED驱动代码			 
//正点原子@ALIENTEK
//2010/5/27

//LED端口定义
#define CAD PBout(0)// PB0
#define ADC_test PBin(1)// PB1		
#define LED0 PBout(3)// PB3	
//#define PWM_OUT PBout(6)// PB6	

void LED_Init(void);//初始化		 				    
#endif

















