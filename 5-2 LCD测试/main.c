#include <at89c51RC2.h>
#include <LCD1602.h>
int result;
void main()
{
	LCD_Init();
	result=1+1;
	LCD_ShowNum(1,2,result,4);
	while(1)
	{
		
	}
}