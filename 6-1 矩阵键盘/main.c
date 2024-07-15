#include <at89c51RC2.h>
#include <Delay.h>
#include <LCD1602.h>
#include <MatriKey.h>

unsigned char KeyNum;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"MatrixKey:");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum>=0 && KeyNum<=9)
		{
			LCD_ShowNum(2,1,KeyNum,1);
		}
	}
}