#include <at89c51RC2.h>
#include <INTRINS.H>
void Delay(xms)		//@11.0592MHz
{
	unsigned char i, j;
	_nop_();
	while(xms)
	{
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}
void main()
{
	while(1)
	{
		if(P3_0==0) 
		{
			Delay(20);
			while(P3_0==0); 
			Delay(20);
			P2_0=~P2_0;
		}
	}
}