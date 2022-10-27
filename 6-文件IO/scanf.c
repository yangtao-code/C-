#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = open("./a.txt", "rw");
    char str[100];
    scanf("%s", str);
    fprintf("./a.txt", "%s\n", str);
    printf("%s\n", str);

    fclose(fp);
    return 0;
}
