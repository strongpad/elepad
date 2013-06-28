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
	JTAG_Set(1);//关闭JTAG（因为用PB3）		 			  
	Stm32_Clock_Init(9); //系统时钟设置
	delay_init(72);	     //延时初始化
	LED_Init();		  	 //初始化与LED连接的硬件接口
	hc4051_Init();
	PWM_Init(240,0);	 //不分频。PWM频率=72000/900=80Khz
  	uart_init(72,9600);	 //串口初始化为9600
	Adc_Init();

	HC4051_A_PA0=0;//开机对HC4051不输入选择
	HC4051_B_PA1=0;
	HC4051_C_PA2=0;

	HC4051_PA3=1; //开机关闭所有HC4051
	HC4051_PA4=1;
	HC4051_PA5=1;
	HC4051_PA6=1;
	HC4051_PA7=1;

   	CAD=1;
	Timerx_Init(100,7199); //2um
	while(1)
	{
	   	//chose_hc4051++;	
		TIM3->CR1|=0x01;    //使能定时器3
		TIM3_IRQHandler();

		TIM3->CR1|=0;    //使能定时器3
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
		PWM_VAL=120;   //调整PWM占空比大小

		HC4051_PA3=1; //开机关闭所有HC4051
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
	Stm32_Clock_Init(9); //系统时钟设置
	delay_init(72);	     //延时初始化 
	uart_init(72,9600);	 //串口初始化为9600
	LED_Init();		  	 //初始化与LED连接的硬件接口    
	while(1)
	{
		if(USART_RX_STA&0x80)
		{					   
			len=USART_RX_STA&0x3f;//得到此次接收到的数据长度
			printf("\n您发送的消息为:\n");
			for(t=0;t<len;t++)
			{
				USART1->DR=USART_RX_BUF[t];
				while((USART1->SR&0X40)==0);//等待发送结束
			}
			printf("\n\n");//插入换行
			USART_RX_STA=0;
		}else
		{
			times++;
			if(times%5000==0)
			{
				printf("\nMiniSTM32开发板 串口实验\n");
				printf("正点原子@ALIENTEK\n\n\n");
			}
			if(times%200==0)printf("请输入数据,以回车键结束\n");  
			//if(times%30==0)LED0=!LED0;//闪烁LED,提示系统正在运行.
			delay_ms(10);   
		}
	}	 
} */
	

