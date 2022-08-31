#include "reg52.h"

sbit led = P2 ^ 1;

void main()
{
    while (1)
    {
        led = 0;
		sleep(1000);
    }
}
