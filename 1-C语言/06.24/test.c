#include <stdio.h>
#include <string.h>

#define FORMAT "%s! C is cool!\n"
#define TEN 7
#define MESG "COMPUTER BYTES DOG"

int main()
{
    int n=0;
    while(n<5)
        printf("%s\n",MESG);
        n++;
    printf("That's all.\n");
    return 0;
}
// int main()
// {
//     int n=0;
//     char c='a';
//     while(n++ < TEN)
//         {
//             printf("%5c",c);
//             c=c+1;
//         }
//     printf("\n");
    
//     return 0;
// }

// int main()
// {
//     char c1,c2;
//     int diff;
//     float num;

//     c1='S';
//     c2='O';
//     diff=c1-c2;
//     num=diff;
//     printf("%c%c%c:%d %3.2f\n",c1,c2,c1,diff,num);
//     return 0;
// }

// int main()
// {
//     int num = 10;

//     printf(FORMAT,FORMAT);
//     printf("%d\n",++num);
//     printf("%d\n",num++);
//     printf("%d\n",num--);
//     printf("%d\n",num);
//     return 0;
// }
// int main(void)
// {
//     int i=1;
//     float n;
//     printf("Watch out ! Here a bunch of fractions!\n");
//     while(i<30)
//     {
//         n=1.0/i;
//         printf(" %f",n);
//         i++;
//     }
//     printf("\n");
//     printf("This's all, folks !\n");
//     return 0;
// }
// int main()
// {
//     int x,y;
//     x=22.0*3/5;
//     x=(2+3) * 10.5;
//     x=(int)3.8+3.3;
//     printf("%f\n",30/4*5.0);
//     y=3+2*(x=7/2);
//     y=x=(2+3)/4;
//     printf("%d,%d\n",y,x);
//     int x=(2+3)*6;
//     printf("%d\n",x);
//     return 0;
// }
// int main()
// {
//     printf("%d\n",-1);          //-1
//     printf("%u\n",-1);          //4294967295
//     printf("%d\n",(char) -1);   //-1
//     printf("%u\n",(char) -1);   //4294967295
//     printf("%d\n",255);         //255
//     printf("%d\n",(char) 255);  //-1
//     printf("%u\n",(char) 255);  //4294967295
// }
// int main()
// {
//     int i=0;
//     int a=0;        //小写字母个数
//     int b=0;        //大写字母个数
//     int c=0;        //数字字符个数
//     int d=0;        //其他字符个数
//     char ch[50]={0};
//     printf("请输入一串字符：");
//     scanf("%s",ch);
//     int sz=strlen(ch);
//     for(i=0;i<sz;i++)
//     {
//         if(ch[i]>='a'&&ch[i]<='z')
//         {
//             a++;
//         }
//         else if(ch[i]>='A'&&ch[i]<='Z')
//         {
//             b++;
//         }
//         else if(ch[i]>='0'&&ch[i]<='9')
//         {
//             c++;
//         }
//         else
//         {
//             d++;
//         }
//     }
//     printf("小写字母有%d个。\n",a);
//     printf("大写字母有%d个。\n",b);
//     printf("数字字符有%d个。\n",c);
//     printf("其他字符有%d个。\n",d);
//     return 0;
// }
// int main()
// {
//     int i=0;
//     char ch[20]={0};
//     scanf("%s",ch);
//     int sz=strlen(ch);
//     printf("%d\n",sz);
//     for(i=0;i<sz;i++)
//     {
//         if(ch[i]>='a'&&ch[i]<='z')
//         {
//             ch[i]=ch[i]-32;
//         }
//         else if(ch[i]>='0'&&ch[i]<='9')
//         {
//             ch[i]=ch[i]-48;
//         }
//     }
//     for(i=0;i<sz;i++)
//     {
//         if(ch[i]>='A'&&ch[i]<='Z')
//         {
//             printf("%c ",ch[i]);
//         } 
//         else
//         {
//             printf("%d ",ch[i]);
//         }
//     }
//     printf("\n");
//     return 0;
// }