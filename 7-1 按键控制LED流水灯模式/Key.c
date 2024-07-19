#include <at89c51RC2.h>
#include <Delay.h>

/**
  * @brief 获取独立按键键码
  * @param 无
  * @retval 按下按键的键码，范围0~4，无按键按下时返回值为0
  */

unsigned char Key()
{
	unsigned int KeyNum=0;
	
	if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);KeyNum=1;}
	if(P3_0==0){Delay(20);while(P3_0==0);Delay(20);KeyNum=2;}
	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);KeyNum=3;}
	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);KeyNum=4;}
	
	return KeyNum;
}
