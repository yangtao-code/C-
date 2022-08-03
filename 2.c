#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun1(char *str, int sz);

int main(int argc, char const *argv[])
{
    char *str = NULL;
    char ch;
    int sz = 1;
    while ((ch = getchar()) != '\n')
    {
        sz++;
        str = (char *)realloc(str, sizeof(char) * sz);
        str[sz - 2] = ch;
    }
    str[sz - 1] = '\0';

    fun1(str, sz);

    puts(str);

    free(str);
    str = NULL;
    return 0;
}

void fun1(char *str, int sz)
{
    char *tmp = (char *)malloc(sz * sizeof(char));
    int k = 0;
    int i = 0;
    int flag = 0; //0代表字母,1代表数字,2代表0;
    while (i < sz)
    {
        if (str[i] >= '1' && str[i] <= '9')
        {
            tmp[k] = str[i];
            k++;
            flag = 1;
        }
        else if (str[i] == '0')
        {
            if (flag == 1)
            {
                tmp[k] = str[i];
                k++;
            }
            else if (flag == 0)
            {
                flag = 2;
            }
        }
        else
        {
            if (flag < 2)
            {
                flag = 0;
                tmp[k] = str[i];
                k++;
            }
            else
            {
                flag = 0;
                tmp[k] = '0';
                k++;
                tmp[k] = str[i];
                k++;
            }
        }
        i++;
    }
    if (flag == 0 && str[sz - 1] == '0')
    {
        tmp[k++] = '0';
        tmp[k] = '\0';
    }
    strcpy(str, tmp);
    free(tmp);
    tmp = NULL;
}
