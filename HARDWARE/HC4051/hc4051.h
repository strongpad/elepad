#ifndef __HC4051_H
#define __HC4051_H	 
#include "sys.h"
//Mini STM32开发板
//LED驱动代码			 
//正点原子@ALIENTEK
//2010/5/27
#define HC4051_A_PA0 PAout(0)// PB3	
#define HC4051_B_PA1 PAout(1)// PB3
#define HC4051_C_PA2 PAout(2)// PB3
#define HC4051_PA3 PAout(3)// PB3	
#define HC4051_PA4 PAout(4)// PB3
#define HC4051_PA5 PAout(5)// PB3	
#define HC4051_PA6 PAout(6)// PB3	
#define HC4051_PA7 PAout(7)// PB3	
	
void hc4051_Init(void);
void hc4051_chose(int x);
#endif

















