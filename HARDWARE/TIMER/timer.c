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
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//Mini STM32开发板
//通用定时器 驱动代码			   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2010/12/03
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 正点原子 2009-2019
//All rights reserved
////////////////////////////////////////////////////////////////////////////////// 	  

//定时器3中断服务程序	 
void TIM3_IRQHandler(void)
{ 		
	if(TIM3->SR&0X0001)//溢出中断
	{
		CAD=1;//读取线圈值之前做次电压改变，先高后低
		delay_us(5);
		CAD=0;//读取线圈值之前做次电压改变，先高后低
		hc4051_chose(chose_hc4051);
		delay_us(100);			   
	}
	TIM3->SR&=~(1<<0);//清除中断标志位
}
//通用定时器中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器3!
void Timerx_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<1;//TIM3时钟使能    
 	TIM3->ARR=arr;  //设定计数器自动重装值//刚好1ms    
	TIM3->PSC=psc;  //预分频器7200,得到10Khz的计数时钟
	//这两个东东要同时设置才可以使用中断
	TIM3->DIER|=1<<0;   //允许更新中断				
	TIM3->DIER|=1<<6;   //允许触发中断
		  							    
	TIM3->CR1|=0x01;    //使能定时器3
  	MY_NVIC_Init(1,3,TIM3_IRQChannel,2);//抢占1，子优先级3，组2									 
}

//TIM3 PWM部分
//正点原子@ALIENTEK
//2010/6/2	 

//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void PWM_Init(u16 arr,u16 psc)

{                                               

       RCC->APB1ENR|=1<<2;           //TIM4时钟使能   

       RCC->APB2ENR|=1<<3;         //使能PORTB时钟      

       GPIOB->CRL&=0X00FFFFFF;   //PB6输出

       GPIOB->CRL|=0X4B000000;      //复用功能输出

       TIM4->ARR=arr;                        //设定计数器自动重装值

       TIM4->PSC=psc;                        //预分频器分频设置

       TIM4->CCMR1|=7<<4;              //CH1 PWM2模式       

       TIM4->CCMR1|=1<<3;             //CH1 预装载使能             

		TIM4->CCER|=1<<1;               //OC1 低电平有效

       TIM4->CCER|=1<<0;               //OC1输出使能      

       TIM4->CR1=0x0080;                //ARPE使能

       TIM4->CR1|=0x01;                  //使能定时器3                                                 

}
















