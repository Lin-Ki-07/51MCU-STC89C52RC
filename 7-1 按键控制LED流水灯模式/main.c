#include <REGX52.h>
#include <Timer0.h>
#include <Key.h>
#include <INTRINS.h>


unsigned char KeyNum,LEDMod;

void main()
{
	P2=0xFE;
	Timer0_Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			LEDMod++;
			if(LEDMod>=2) LEDMod=0;
		}
		
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
		if(LEDMod==1) P2=_crol_(P2,1);  //循环左移一位
		if(LEDMod==0) P2=_cror_(P2,1);  //循环右移一位
	}		
}