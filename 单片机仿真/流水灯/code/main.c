#include "reg52.h"

#define led P2

typedef unsigned char u8;
typedef unsigned int u16;

void delay(u16 i)
{
	int n = 0;
	while (i--)
	{
		for (n = 0; n <= 124; n++)
			;
	}
}

void main()
{
	u16 i;
	int k = 0;
	int flag = 0;
	while (1)
	{
		if (flag == 0)
		{
			k++;
			for (i = 0; i <= 7; i++)
			{
				led = ~(1 << i);
				delay(200);
			}
			if (k == 4)
			{
				k = 0;
				flag = 1;
			}
		}
		else
		{
			k++;
			for (i = 0; i <= 7; i++)
			{
				led = ~(0x80 >> i);
				delay(200);
			}
			if (k == 4)
			{
				k = 0;
				flag = 0;
			}
		}
	}
}
