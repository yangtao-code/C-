#include <stdio.h>

#define N 10

int main()
{
	unsigned a = 6;
	int b = -20;
	(a + b > 6) ? puts("> 6"):puts("<6");
	return 0;	
}

/*void arrin(int x[N])
{
	int i=0;
	while(i<N)
	{
		scanf("%d",&x[i++]);
	}
}

int main()
{
	char buf[]="abcdefg";
	char *p;
	p=buf[1];
	printf("%c %c\n",*p,*(p+3));
	
	int x[N]={0};
	arrin(x);
	for(int i=0;i<N;i++)
	{
		printf("%d ",x[i]);
	}
	printf("\n");
	return 0;
}*/

