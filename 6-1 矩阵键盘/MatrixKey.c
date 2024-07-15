#include <at89c51RC2.h>
#include <Delay.h>
/**
  * @brief 矩阵键盘读取键盘键码
  * @param 无
  * @retval  KeyNumber本人 按下按键的键码值
	如果按键按下不放，程序会停留在子函数,松手的一瞬间，返回按键的键码值，没有按键按下时，返回W
  */

unsigned char MatrixKey()
{
	unsigned char KeyNumber="W";
	
	P1=0xFF;
	P1_3=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=1;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=6;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=7;}
	
	P1=0xFF;
	P1_2=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=2;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=5;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=8;}
	if(P1_4==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=0;}
	
	P1=0xFF;
	P1_1=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=3;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=4;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=9;}
	
	return KeyNumber;
}