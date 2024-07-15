#include <at89c51RC2.h>
#include <Delay.h>
#include <LCD1602.h>
#include <MatriKey.h>

unsigned char KeyNum;
unsigned int True_Password=2470,Password=0,Count=0;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum>=0 && KeyNum<=9 && Count<4)
		{
			Password*=10;                 //密码左移一位
			Password+=KeyNum%10;			//获取一位密码
			Count++;
			LCD_ShowNum(2,1,Password,4);  //设置四位密码
		}
		if(KeyNum==10)
		{
			if(Password==True_Password) LCD_ShowString(1,11,"RIGHT");
			else 
			{
				LCD_ShowString(1,11,"ERROR");
				Delay(1000);
				Password=0;                     //密码清零
				Count=0;                        //计次清零
				LCD_ShowNum(2,1,Password,4);
				LCD_ShowString(1,11,"AGAIN");   //清空显示ERROR
			}
		}
		if(KeyNum==11)
		{
				Password=0;                     //密码清零
				Count=0;                        //计次清零
				LCD_ShowNum(2,1,Password,4);
		}
	}
}