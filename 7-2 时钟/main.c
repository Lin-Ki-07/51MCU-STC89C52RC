#include <at89c51RC2.h>
#include <LCD1602.h>
#include <Timer0.h>

unsigned char sec=23,min=59,hour=23;

void main()
{
	LCD_Init();
	Timer0_Init();
	
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(2,1,"  :  :");
	
	while(1)
	{
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowNum(2,4,min,2);
		LCD_ShowNum(2,7,sec,2);
		
	}
}


void Timer0_Routine() interrupt 1  //溢出时中断
{
	static int T0Count;
	TL0 = 0x66;		 
	TH0 = 0xFC;
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		sec++;             //秒数加1
		if(sec>=60)
		{
			sec=0;
			min++;
			if(min>=60)
			{
				min=0;
				hour++;
				if(hour>=24)
				{
					hour=0;
				}
			}
		}
	}		
}
