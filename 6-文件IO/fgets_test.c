#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buf[1024];
    fgets(buf,1024,stdin);
    printf("%s",buf);
    return 0;
}
