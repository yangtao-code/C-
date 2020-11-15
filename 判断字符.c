#include<stdio.h>

int main()

{

	char c;

	int n1 = 0, n2 = 0, n3 = 0, n4 = 0;

	printf("请输入一行字符：");

	while ((c = getchar()) != '\n')

	{

		if (c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z')

			n1++;

		else if (c == ' ')

			n2++;

		else if (c >= '0'&&c <= '9')

			n3++;

		else

			n4++;

	}

	printf("英文字母个数%d,空格个数%d,数字个数%d,其他字符个数%d", n1, n2, n3, n4);
	return 0;
}