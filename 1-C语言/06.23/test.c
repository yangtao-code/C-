#include <stdio.h>

void main()
{
    int cows, legs, intefer;
	printf("How many cow legs did you count?\n");
	scanf("%d", &legs);
	cows = legs / 4;
	printf("That implies there are %d cows.\n", cows);
}
// int main()
// {
//     char c;
//     short a;
//     int i;
//     long b;
//     char* p;
//     printf("sizeof(short)=%ld,sizeof(a)=%ld\n",sizeof(short),sizeof(a));   // 2 2
//     printf("sizeof(int)=%ld,sizeof(i)=%ld\n",sizeof(int),sizeof(i));       // 4 4 
//     printf("sizeof(long)=%ld,sizeof(b)=%ld\n",sizeof(long),sizeof(b));     // 8 8
//     printf("sizeof(char*)=%ld,sizeof(p)=%ld\n",sizeof(char*),sizeof(p));   // 8 8
//     return 0;
// }