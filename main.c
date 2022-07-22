#include "linkqueue.h"
#include "linkstack.h"
#include <string.h>
#include <stdlib.h>

void mid_to_post(const char *expr, LinkStack *stack, LinkQueue *queue);

bool is_digit(char op);

void push_operator(char op, LinkStack *stack, LinkQueue *queue);

int get_priority(char op);

int calc_post(LinkStack *stack, LinkQueue *queue);

int basic_calculate(int left, int right, int op);

int main(int argc, char const *argv[])
{
    LinkStack *stack = Create_Stack();
    LinkQueue *queue = Create_Queue();

    const char *expr = "100-100-100";

    mid_to_post(expr, stack, queue);
    Print_Queue(queue);

    int ret = calc_post(stack, queue);

    printf("%s = %d\n", expr, ret);
    return 0;
}

int calc_post(LinkStack *stack, LinkQueue *queue)
{
    while (!Queue_Empty(queue))
    {
        int c = Get_Queue_Top(queue);
        DeQueue(queue);
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            int right = Get_Stack_Top(stack);
            DeStack(stack);
            int left = Get_Stack_Top(stack);
            DeStack(stack);
            int ret = basic_calculate(left, right, c);
            EnStack(stack, ret);
        }
        else
        {
            EnStack(stack, c);
        }
    }
    int ret = Get_Stack_Top(stack);
    DeStack(stack);
    return ret;
}

int basic_calculate(int left, int right, int op)
{
    int ret=0;
    switch (op)
    {
    case '*':
        ret = left * right;
        printf("%d\n",ret);
        break;
    case '/':
        ret = left / right;
        break;
    case '+':
        ret = left + right;
        break;
    case '-':
        ret = left - right;
        break;
    default:
        break;
    }
    return ret;
}

void mid_to_post(const char *expr, LinkStack *stack, LinkQueue *queue)
{
    int tmp = 0;
    for (int i = 0; i < strlen(expr); i++)
    {
        char c = expr[i];

        if (is_digit(c))
        {
            tmp = tmp * 10 + c - 48;
        }
        else
        {
            if (Stack_Empty(stack))
            {
                EnStack(stack, c);
                EnQueue(queue, tmp);
                tmp = 0;
            }
            else
            {
                EnQueue(queue, tmp);
                tmp = 0;
                push_operator(c, stack, queue);
            }
        }
    }
    EnQueue(queue, tmp);
    while (!Stack_Empty(stack))
    {
        EnQueue(queue, Get_Stack_Top(stack));
        DeStack(stack);
    }
}

void push_operator(char op, LinkStack *stack, LinkQueue *queue)
{
    while (!Stack_Empty(stack))
    {
        char top_op = Get_Stack_Top(stack);
        if (get_priority(op) > get_priority(top_op))
        {
            EnStack(stack, op);
            return;
        }
        else
        {
            EnQueue(queue, top_op);
            DeStack(stack);
        }
    }
    EnStack(stack, op);
}

int get_priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
}

bool is_digit(char op)
{
    if (op >= '0' && op <= '9')
        return true;
    return false;
}