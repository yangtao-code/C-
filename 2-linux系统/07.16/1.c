#include <stdio.h>

int main(int argc, const char* argv[])
{
	if(argc != 2)
	{
		printf("usr:please a value");
		return 1;
	}
	int value = argv[0];
	return value;
}
