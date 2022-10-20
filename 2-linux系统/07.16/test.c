#include <stdio.h>

int main()
{
	char a = 0x01;
	char b = 0x02;
	short val = ((short)a << 8) + b;
	printf("0x%x\n",val);
	return 0;
}
