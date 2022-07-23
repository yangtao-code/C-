#include "calc.h"

int main(int argc, char const *argv[])
{
    LinkStack *stack = Create_Stack();

    LinkQueue *queue = Create_Queue();

    char expr[100];
    printf("请输入表达式：");
    scanf("%s", expr);

    mid_to_post(expr, stack, queue);

    int ret = calc_post(stack, queue);

    printf("%s = %d\n", expr, ret);
    return 0;
}
