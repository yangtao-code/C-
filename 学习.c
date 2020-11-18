#include<stdio.h>

void main()
{
	int i,sum=0;
	i=1;
pet:  if(i<=100)
	  {
		  sum=sum+i;
		  i++;
			  goto pet;
	  }
	  printf("%d\n",sum);
}
