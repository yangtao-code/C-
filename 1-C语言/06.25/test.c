#include <stdio.h>
#include <string.h>

int main()
{
    int arr[5]={1,2,3,4,5};
    arr[10]=100;
    printf("%d,%d\n",arr[0],arr[10]);
    return 0;
}
// int main()
// {
//     char ch[100] = {0};
//     printf("%ld\n", sizeof(ch));
//     scanf("%s", ch);
//     int sz = strlen(ch);
//     printf("%d\n", sz);
//     int n = sz % 4 == 0 ? 0 : 4 - sz % 4;
//     for (int i = sz; i < sz + n - 1; i++)
//     {
//         ch[i] = '0';
//     }
//     printf("%d\n", n);
//     return 0;
// }

// int main()
// {
//     int a;
//     int b;
//     scanf("%d%d",&a,&b);
//     int max=a>b? a : b;
//     printf("max=%d\n",max);
//     return 0;
// }

// int main()
// {
//     int i=1;
//     //int j=i++;
//     //int j= ++i;
//     //printf("i=%d,j=%d\n",i,j);
//     printf("%f\n",1/0.0);
//     return 0;
// }

// int main()
// {
//     int i=1;
//     int n= (++i)+ (++i)+ (++i);
//     printf("%d\n",n);
//     return 0;
// }