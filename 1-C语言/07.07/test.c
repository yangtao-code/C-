#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("USage: %s <num1><num2>\n", argv[0]);
        return 1;
    }
    char *ret = malloc(strlen(argv[1]) + strlen(argv[2]) + 1);
    strcat(ret, argv[1]);
    strcat(ret, argv[2]);
    printf("%s\n", ret);
    free(ret);
    return 0;
}

// void arrin(int x[N])
// {
//     int i = 0;
//     while (i < N)
//         scanf("%d", x + (i++));
// }

// int main()
// {
//     int a[10];
//     arrin(a);
//     for (int i = 0; i < 10; i++)
//     {
//         printf("%d ", a[i]);
//     }
//     printf("\n");
//     return 0;
// }

// int main()
// {
//     char *s[] = {"one", "two", "three"},*p;
//     p = s[1];
//     printf("%c,%s\n", *(p + 1), s[0]);
//     return 0;
// }

// int main()
// {
//     char b1[8] = "abcdefg", b2[8], *pb = b1 + 3;
//     while (--pb >= b1)
//         strcpy(b2, pb);
//     int l = strlen(b2);
//     printf("%ld\n", strlen(b2));
//     return 0;
// }

// int main()
// {

//     char* s="abcde";
//     s=s+2;
//     printf("%ld\n",s);
//     printf("%p",s);
//     return 0;
// }

// int main()
// {
//     char *p = "abcdefgh", *r;
//     long *q;
//     q = (long *)p;
//     q++;
//     r = (char *)q;
//     printf("%s\n", r);
//     return 0;
// }

// int main()
// {
//     char s[] = "hello\0world";
//     char *p = s + 2;
//     printf("%s ", p);
//     printf("%s\n", p + 4);
//     return 0;
// }

// int main()
// {
//     printf("sgsgsgsg");
//     while(1)
//     {
//         ;
//     }
//     // char* p="hafhaifhi";
//     // printf("%c ",*(p+1));
//     // *p='a';
//     // printf("%c\n",*p);
//     return 0;
// }

// int main()
// {
//     char* str1="urfgf";
//     printf(str1);
//     return 0;
// }

// char *foo(const char *files, const char *pth)
// {
//     char *pch = malloc(strlen(files)+strlen(pth)+2);
//     char *ret = pch;
//     strcat(pch, files);
//     strcat(pch, pth);

//     // while (*files)
//     // {
//     //     *pch = *files;
//     //     pch++;
//     //     files++;
//     // }
//     // while (*pth)
//     // {
//     //     *pch = *pth;
//     //     pch++;
//     //     pth++;
//     // }
//     // *pch='\0';
//     return ret;
// }

// int main()
// {
//     const char *files = "mnt/hgfs/share/study/07.07/";
//     const char *pth = "test.c";
//     char *pch = foo(files, pth);
//     printf("%s\n", pch);
//     free(pch);
//     return 0;
// }

// int main()
// {
//     int a = 1;
//     char c = *(char *)&a;
//     if (c == 1)
//     {
//         printf("小端!\n");
//     }
//     else
//     {
//         printf("大端!\n");
//     }
//     return 0;
// }

// void *foo(char **p2)
// {
//     char *p1 = (char *)malloc(100);
//     *p1 = 'a';
//     *p2 = p1;
//     return *p2;
// }
// int main()
// {
//     char *p1 = NULL;
//     p1 = foo(&p1);
//     printf("p1 = %c\n", *p1);
//     free(p1);
//     return 0;
// }

// void foo(int *p)
// {
//     for (int i = 0; i < 5; i++)
//     {
//         scanf("%d", p + i);
//     }
// }

// int main()
// {
//     int *p = NULL;
//     p = (int *)malloc(100);
//     foo(p);
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", *(p + i));
//     }
//     printf("\n");
//     free(p);
//     return 0;
// }

// void *my_memmove(void *des, const void *src, size_t count);
// // int main()
// // {
// //     char arr1[10] = "123456789";
// //     my_memmove(arr1, arr1 + 2, 5);
// //     for (int i = 0; i < 9; i++)
// //     {
// //         printf("%c ", arr1[i]);
// //     }
// //     printf("\n");
// //     return 0;
// // }
// void *my_memmove(void *des, const void *src, size_t count)
// {
//     assert(des != NULL);
//     assert(des != NULL);
//     void *ret = des;

//     while (count--)
//     {
//         if ((char *)des - (char *)src >= 0)
//         {
//             *(count + (char *)des) = *(count + (char *)src);
//         }
//         else
//         {
//             *(char *)des = *(char *)src;
//             des = (char *)des + 1;
//             src = (char *)src + 1;
//         }
//     }
//     return ret;
// }