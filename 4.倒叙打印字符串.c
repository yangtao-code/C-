#include <stdio.h>

void fun1(char *str);

void fun2();

int main(int argc, char const *argv[])
{
    // char str[20];
    // gets(str);

    // fun1(str);
    // printf("\n");
    fun2();
    printf("\n");
    return 0;
}

void fun1(char *str)
{
    //当遇到‘\0’字符时，回溯
    if (*str == '\0')
        return;
    fun1(++str);
    printf("%c", *(--str));
}

void fun2()
{
    char ch;
    if ((ch = getchar()) != '\n')
        fun2();
    putchar(ch);
}
