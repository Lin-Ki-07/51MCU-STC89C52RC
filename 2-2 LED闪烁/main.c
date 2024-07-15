#include <at89c51RC2.h>
#include <INTRINS.H>
void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;
	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
	while(1)
	{
		P2 = 0xAA;  //1010 1010
		Delay500ms();
		P2 = 0x55;  //0101 0101
		Delay500ms();
	}
}