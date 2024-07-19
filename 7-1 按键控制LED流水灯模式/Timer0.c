#include <REGX52.h>

/**
  * @brief 定时器0初始化，1毫秒@11.0592HZ
  * @param 无
  * @retval 无
  */
void Timer0_Init()
{
	
	//TMOD=0x01;      //0000 0001,选中定时器1，置为计时器状态
	TMOD=TMOD&0xF0;   //把TMOD的低四位清零，高四位保持不变
	TMOD=TMOD|0x01;   //把TMOD最低位置1，高四位保持不变
	TF0=0;            //将溢出中断标志清0
	TR0=1;            //开始计时
	TL0 = 0x66;		    //设置定时初值
	TH0 = 0xFC;		    //设置定时初值   
	ET0=1;
	EA=1;             //闭合两个总开关
	PT0=0;            //设置优先级为最低
}

/*定时器中断函数模板
void Timer0_Routine() interrupt 1  //溢出时中断
{
	static int T0Count;
	TL0 = 0x66;		 
	TH0 = 0xFC;
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		
	}		
}
*/